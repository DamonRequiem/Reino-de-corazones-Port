/*
 * pc_core_host.c
 * The frontend's side of the 32-bit core (port/pc_core.c), for 64-bit-only
 * phones: owns the core instance (C from wasm2c, built natively), fills its
 * data from the player's ROM, gives it the few system services it uses
 * (files, clock, log) and offers the frontend the same functions it calls on
 * PC (PcSaveLoad, PcApuReadSamples...), so pc_main_sdl.c barely changes.
 *
 * Leaving the core: it calls rdc.jump (soft reset, resume after a crash),
 * which unwinds through wasm2c's trap mechanism back into RdcHostRun().
 * A real fault inside the core (a wild pointer) arrives the same way and is
 * answered like the PC build's crash recovery: back to a recent snapshot.
 */
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#include "core.h"
#include "pc_platform.h"
#include "wasm-rt-exceptions.h"
#include "wasm-rt-impl.h"

struct w2c_rdc { int unused; };
struct w2c_wasi__snapshot__preview1 { int unused; };

static w2c_core sCore;
static struct w2c_rdc sRdc;
static struct w2c_wasi__snapshot__preview1 sWasi;
static int sReady;
static void (*sFrameHook)(void);
static int sJumpCode;          /* why the core left: see RdcHostRun */
static const int kJumpNone = -1000;
static u32 sStackTop;

#define MEM (sCore.w2c_memory.data)
#define MEMSIZE (sCore.w2c_memory.size)

static void* Ptr(uint32_t addr) {
    return MEM + addr;
}

uint8_t* RdcHostPtr(uint32_t addr) {
    return (uint8_t*)Ptr(addr);
}

/* ---- what the core asks of the frontend ---- */

void w2c_rdc_log(struct w2c_rdc* r, u32 text) {
    (void)r;
    PcLog("%s", (const char*)Ptr(text));
}

void w2c_rdc_frame(struct w2c_rdc* r) {
    (void)r;
    if (sFrameHook)
        sFrameHook();
}

void w2c_rdc_jump(struct w2c_rdc* r, u32 code) {
    (void)r;
    sJumpCode = (int)code;
    wasm_rt_trap(WASM_RT_TRAP_UNREACHABLE); /* unwinds to RdcHostRun */
}

/* ---- WASI: the handful of calls the core's C library makes ---- */

enum { WASI_ESUCCESS = 0, WASI_EACCES = 2, WASI_EBADF = 8, WASI_EINVAL = 28, WASI_EIO = 29, WASI_ENOENT = 44 };
#define MAX_FILES 32
static int sFds[MAX_FILES]; /* WASI fd -> host fd; 0-2 stdio, 3 = "/" (preopened) */

static void Put32(u32 addr, uint32_t v) { memcpy(Ptr(addr), &v, 4); }
static void Put64(u32 addr, uint64_t v) { memcpy(Ptr(addr), &v, 8); }
static uint32_t Get32(u32 addr) { uint32_t v; memcpy(&v, Ptr(addr), 4); return v; }

static int HostErr(void) {
    return errno == ENOENT ? WASI_ENOENT : errno == EACCES ? WASI_EACCES : WASI_EIO;
}

u32 w2c_wasi__snapshot__preview1_fd_prestat_get(struct w2c_wasi__snapshot__preview1* w, u32 fd, u32 buf) {
    (void)w;
    if (fd != 3)
        return WASI_EBADF;
    memset(Ptr(buf), 0, 8); /* tag 0: directory */
    Put32(buf + 4, 1);      /* name "/" */
    return WASI_ESUCCESS;
}

u32 w2c_wasi__snapshot__preview1_fd_prestat_dir_name(struct w2c_wasi__snapshot__preview1* w, u32 fd, u32 path,
                                                      u32 len) {
    (void)w;
    if (fd != 3 || len < 1)
        return WASI_EBADF;
    *(char*)Ptr(path) = '/';
    return WASI_ESUCCESS;
}

u32 w2c_wasi__snapshot__preview1_fd_fdstat_get(struct w2c_wasi__snapshot__preview1* w, u32 fd, u32 buf) {
    (void)w;
    if (fd >= MAX_FILES || (fd > 3 && sFds[fd] <= 0))
        return WASI_EBADF;
    memset(Ptr(buf), 0, 24);
    *(uint8_t*)Ptr(buf) = fd < 3 ? 2 : fd == 3 ? 3 : 4; /* char device, directory, regular file */
    Put64(buf + 8, ~0ull);
    Put64(buf + 16, ~0ull);
    return WASI_ESUCCESS;
}

u32 w2c_wasi__snapshot__preview1_fd_fdstat_set_flags(struct w2c_wasi__snapshot__preview1* w, u32 fd, u32 flags) {
    (void)w;
    (void)fd;
    (void)flags;
    return WASI_ESUCCESS;
}

u32 w2c_wasi__snapshot__preview1_path_open(struct w2c_wasi__snapshot__preview1* w, u32 dirfd, u32 dirflags,
                                            u32 path, u32 pathLen, u32 oflags, u64 rights, u64 inherit,
                                            u32 fdflags, u32 fdOut) {
    char full[2048];
    int flags = 0, fd, slot;
    int rd = (rights & (1ull << 1)) != 0, wr = (rights & (1ull << 6)) != 0;
    (void)w;
    (void)dirflags;
    (void)inherit;
    if (dirfd != 3 || pathLen + 2 > sizeof(full))
        return WASI_EBADF;
    full[0] = '/';
    memcpy(full + 1, Ptr(path), pathLen);
    full[pathLen + 1] = 0;
    flags = rd && wr ? O_RDWR : wr ? O_WRONLY : O_RDONLY;
    if (oflags & 1) flags |= O_CREAT;
    if (oflags & 4) flags |= O_EXCL;
    if (oflags & 8) flags |= O_TRUNC;
    if (fdflags & 1) flags |= O_APPEND;
    for (slot = 4; slot < MAX_FILES && sFds[slot] > 0; slot++) {
    }
    if (slot >= MAX_FILES)
        return WASI_EIO;
    fd = open(full, flags | O_CLOEXEC, 0644);
    if (fd < 0)
        return (u32)HostErr();
    sFds[slot] = fd;
    Put32(fdOut, (uint32_t)slot);
    return WASI_ESUCCESS;
}

u32 w2c_wasi__snapshot__preview1_fd_close(struct w2c_wasi__snapshot__preview1* w, u32 fd) {
    (void)w;
    if (fd < 4 || fd >= MAX_FILES || sFds[fd] <= 0)
        return WASI_EBADF;
    close(sFds[fd]);
    sFds[fd] = 0;
    return WASI_ESUCCESS;
}

u32 w2c_wasi__snapshot__preview1_fd_read(struct w2c_wasi__snapshot__preview1* w, u32 fd, u32 iovs, u32 n,
                                          u32 nread) {
    uint32_t total = 0, i;
    (void)w;
    if (fd < 4 || fd >= MAX_FILES || sFds[fd] <= 0) {
        Put32(nread, 0);
        return fd == 0 ? WASI_ESUCCESS : WASI_EBADF;
    }
    for (i = 0; i < n; i++) {
        uint32_t buf = Get32(iovs + i * 8), len = Get32(iovs + i * 8 + 4);
        ssize_t got = read(sFds[fd], Ptr(buf), len);
        if (got < 0)
            return (u32)HostErr();
        total += (uint32_t)got;
        if ((uint32_t)got < len)
            break;
    }
    Put32(nread, total);
    return WASI_ESUCCESS;
}

u32 w2c_wasi__snapshot__preview1_fd_write(struct w2c_wasi__snapshot__preview1* w, u32 fd, u32 iovs, u32 n,
                                           u32 nwritten) {
    uint32_t total = 0, i;
    (void)w;
    for (i = 0; i < n; i++) {
        uint32_t buf = Get32(iovs + i * 8), len = Get32(iovs + i * 8 + 4);
        if (fd == 1 || fd == 2) {
            PcLog("%.*s", (int)len, (const char*)Ptr(buf));
            total += len;
            continue;
        }
        if (fd < 4 || fd >= MAX_FILES || sFds[fd] <= 0)
            return WASI_EBADF;
        {
            ssize_t put = write(sFds[fd], Ptr(buf), len);
            if (put < 0)
                return (u32)HostErr();
            total += (uint32_t)put;
        }
    }
    Put32(nwritten, total);
    return WASI_ESUCCESS;
}

u32 w2c_wasi__snapshot__preview1_fd_seek(struct w2c_wasi__snapshot__preview1* w, u32 fd, u64 offset, u32 whence,
                                          u32 newOffset) {
    off_t r;
    (void)w;
    if (fd < 4 || fd >= MAX_FILES || sFds[fd] <= 0)
        return WASI_EBADF;
    r = lseek(sFds[fd], (off_t)(int64_t)offset, whence == 0 ? SEEK_SET : whence == 1 ? SEEK_CUR : SEEK_END);
    if (r < 0)
        return WASI_EINVAL;
    Put64(newOffset, (uint64_t)r);
    return WASI_ESUCCESS;
}

u32 w2c_wasi__snapshot__preview1_path_rename(struct w2c_wasi__snapshot__preview1* w, u32 fd, u32 oldPath,
                                              u32 oldLen, u32 newFd, u32 newPath, u32 newLen) {
    char a[2048], b[2048];
    (void)w;
    if (fd != 3 || newFd != 3 || oldLen + 2 > sizeof(a) || newLen + 2 > sizeof(b))
        return WASI_EBADF;
    a[0] = b[0] = '/';
    memcpy(a + 1, Ptr(oldPath), oldLen);
    a[oldLen + 1] = 0;
    memcpy(b + 1, Ptr(newPath), newLen);
    b[newLen + 1] = 0;
    return rename(a, b) == 0 ? WASI_ESUCCESS : (u32)HostErr();
}

u32 w2c_wasi__snapshot__preview1_clock_time_get(struct w2c_wasi__snapshot__preview1* w, u32 id, u64 precision,
                                                 u32 out) {
    struct timespec ts;
    (void)w;
    (void)precision;
    clock_gettime(id == 0 ? CLOCK_REALTIME : CLOCK_MONOTONIC, &ts);
    Put64(out, (uint64_t)ts.tv_sec * 1000000000ull + (uint64_t)ts.tv_nsec);
    return WASI_ESUCCESS;
}

void w2c_wasi__snapshot__preview1_proc_exit(struct w2c_wasi__snapshot__preview1* w, u32 code) {
    (void)w;
    PcLog("[pc] core exited (%u)\n", code);
    sJumpCode = -1;
    wasm_rt_trap(WASM_RT_TRAP_UNREACHABLE);
}

/* ---- the core's data ---- */

int PcRomDataSection(const char* name, uint8_t** start, size_t* size) {
    uint32_t a, b;
    if (!sReady || strcmp(name, "wasmdata"))
        return 0;
    a = w2c_core_rdc_data_start(&sCore);
    b = w2c_core_rdc_data_end(&sCore);
    *start = (uint8_t*)Ptr(a);
    *size = b - a;
    return 1;
}

int PcRomDataNeeded(void) {
    return 1; /* the core never carries its data */
}


/* Creates the core and rebuilds its memory from the player's ROM. Returns
 * NULL on success, or a message for the player. */
const char* RdcHostLoad(const char* romPath, const char* mapPath) {
    const char* err;
    wasm_rt_init();
    wasm2c_core_instantiate(&sCore, &sRdc, &sWasi);
    sReady = 1;
    sStackTop = sCore.w2c_g0; /* __stack_pointer: put back each time the core is entered */
    err = PcRomDataLoad(romPath, mapPath);
    if (err)
        return err;
    w2c_core_0x5Finitialize(&sCore); /* the C library's start-up */
    PcLog("[pc] 32-bit core ready: %u MB of memory\n", (unsigned)(MEMSIZE >> 20));
    return NULL;
}

/* ---- the functions pc_main_sdl.c uses, forwarded to the core ---- */

static u32 Scratch(const char* s) {
    u32 at = w2c_core_rdc_scratch(&sCore);
    size_t n = strlen(s);
    if (n >= w2c_core_rdc_scratch_size(&sCore))
        n = w2c_core_rdc_scratch_size(&sCore) - 1;
    memcpy(Ptr(at), s, n);
    *((char*)Ptr(at) + n) = 0;
    return at;
}

uint32_t* RdcHostFrameCount(void) { return (uint32_t*)Ptr(w2c_core_rdc_frame_count(&sCore)); }
uint32_t* RdcHostFramebuffer(void) { return (uint32_t*)Ptr(w2c_core_rdc_framebuffer(&sCore)); }
uint8_t* RdcHostIo(void) { return (uint8_t*)Ptr(w2c_core_rdc_io(&sCore)); }
int* RdcHostSkipMovies(void) { return (int*)Ptr(w2c_core_rdc_skip_movies(&sCore)); }

void PcApuReset(void) { w2c_core_rdc_apu_reset(&sCore); }

unsigned PcApuReadSamples(int16_t* out, unsigned maxFrames) {
    u32 at = w2c_core_rdc_scratch(&sCore);
    unsigned cap = w2c_core_rdc_scratch_size(&sCore) / 4, got;
    if (maxFrames > cap)
        maxFrames = cap;
    got = w2c_core_rdc_apu_read(&sCore, at, maxFrames);
    memcpy(out, Ptr(at), (size_t)got * 4);
    return got;
}

int PcSaveLoad(const char* path) { return (int)w2c_core_rdc_save_load(&sCore, Scratch(path)); }
void PcSaveTick(void) { w2c_core_rdc_save_tick(&sCore); }
void PcSaveFlush(void) { if (sReady) w2c_core_rdc_save_flush(&sCore); }
int PcSaveScreenshot(const char* path) { return (int)w2c_core_rdc_screenshot(&sCore, Scratch(path)); }
void PcResetNullPage(void) { w2c_core_rdc_null_page(&sCore); }
void PcStateRequestQuickSave(const char* path) { w2c_core_rdc_state_quick_save(&sCore, Scratch(path)); }
void PcStateRequestQuickLoad(const char* path) { w2c_core_rdc_state_quick_load(&sCore, Scratch(path)); }
int PcStateTakeQuickResult(void) { return (int)w2c_core_rdc_state_result(&sCore); }
int PcTakeRecoveredNotice(void) { return (int)w2c_core_rdc_recovered_notice(&sCore); }

/* Fault handling lives in the generated core (port/wasm/build_core.py). */
void PcInstallDivZeroHandler(void) {}
void PcInstallFaultRecovery(void) {}

/* Runs the game. Returns only when it cannot go on (the message is logged). */
void RdcHostRun(void (*frameHook)(void)) {
    int code = 0;
    sFrameHook = frameHook;
    for (;;) {
        wasm_rt_trap_t trap;
        sJumpCode = kJumpNone;
        sCore.w2c_g0 = sStackTop; /* leaving by a trap does not unwind the core's own stack */
        trap = (wasm_rt_trap_t)wasm_rt_impl_try();
        if (trap == WASM_RT_TRAP_NONE) {
            if (code == -2)
                w2c_core_rdc_resume_after_crash(&sCore); /* leaves through rdc.jump(2) */
            else
                w2c_core_rdc_enter(&sCore, (u32)code);
            code = -1; /* the game must never return */
            break;
        }
        if (sJumpCode != kJumpNone) {
            code = sJumpCode; /* 1: soft reset, 2: resume, -1: stop */
            if (code < 0)
                break;
            continue;
        }
        /* A real fault inside the core. */
        PcLog("[pc] CRASH in the game core: %s (frame %u)\n", wasm_rt_strerror(trap), *RdcHostFrameCount());
        if (!w2c_core_rdc_can_resume(&sCore))
            break;
        code = -2;
    }
    PcLog("[pc] the game core stopped\n");
}
