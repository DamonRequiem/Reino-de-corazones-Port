/*
 * pc_state.c
 * Snapshots of the whole running game: crash recovery and quick save/load.
 *
 * A snapshot holds everything the game's behaviour depends on: its global
 * variables (between the pc_game_begin/end markers), its two heaps, video
 * memory, palette, OAM, IO registers and the emulated hardware's internal
 * state (beam position, DMA channels, affine latches, pending interrupts).
 * The cartridge save (SRAM) is deliberately left out: going back in time
 * must never undo a saved game.
 *
 * Snapshots are only taken and restored at one point: the end of the
 * VBlankIntrWait() call in AgbMain's main loop (gPcMainLoopWait). There the
 * C call stack is always the same, so the memory image is all there is.
 *
 *  - Automatic: every 2 seconds, keeping a recent and an older copy. If the
 *    game crashes or freezes, the frontend calls PcStateResumeAfterCrash(),
 *    which restores a copy and re-enters AgbMain's loop (see src/main.c).
 *  - Quick save/load: F5/F8 in the SDL frontend, stored in a file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pc_platform.h"

extern char gPcGameDataBegin[], gPcGameDataEnd[];
extern char gPcGameBssBegin[], gPcGameBssEnd[];
extern uint8_t gEwramHeapStart[0x34000];
extern uint8_t gIwramHeapStart[0x6800];
extern void* gSoundInfoPtr;
extern volatile uint16_t gIntrCheck;
extern void* gPcIntrVector;

void* PcFrameState(size_t* size);
void* PcDmaState(size_t* size);
void* PcRenderState(size_t* size);
void* PcIntrState(size_t* size);
void PcIntrResetDepth(void);

int gPcMainLoopWait;

#define AUTO_INTERVAL 120 /* frames (~2 s) */
#define OLDER_EVERY 5     /* the older copy is refreshed every 5th capture (~10 s) */
#define MAX_REGIONS 16

typedef struct {
    void* ptr;
    size_t size;
} Region;

typedef struct {
    uint8_t* data;
    int valid;
    uint32_t frame; /* gPcFrameCount when taken */
} Snapshot;

static Region sRegions[MAX_REGIONS];
static int sNumRegions;
static size_t sTotalSize;
static Snapshot sRecent, sOlder, sQuick;
static uint32_t sAutoCounter;
static int sResumePending;
static int sQuickRequest; /* 1 = save, 2 = load */
static char sQuickPath[1100];
static uint32_t sLastResumeFrame;
static int sResumeAttempts;

/* Plain byte copies: the game range includes padding that AddressSanitizer
 * test builds poison. */
#if defined(__GNUC__)
__attribute__((no_sanitize_address, noinline))
#endif
static void RawCopy(void* dst, const void* src, size_t n) {
    volatile unsigned char* d = (volatile unsigned char*)dst;
    const volatile unsigned char* s = (const volatile unsigned char*)src;
    while (n--)
        *d++ = *s++;
}

static void AddRegion(void* ptr, size_t size) {
    if (sNumRegions < MAX_REGIONS && ptr != NULL && size > 0) {
        sRegions[sNumRegions].ptr = ptr;
        sRegions[sNumRegions].size = size;
        sNumRegions++;
        sTotalSize += size;
    }
}

void PcStateInit(void) {
    size_t n;
    void* p;

    if (sNumRegions)
        return;
    if ((uintptr_t)gPcGameDataEnd > (uintptr_t)gPcGameDataBegin)
        AddRegion(gPcGameDataBegin, (size_t)(gPcGameDataEnd - gPcGameDataBegin));
    if ((uintptr_t)gPcGameBssEnd > (uintptr_t)gPcGameBssBegin)
        AddRegion(gPcGameBssBegin, (size_t)(gPcGameBssEnd - gPcGameBssBegin));
    {
        uint8_t* w;
        size_t wn;
        if (PcRomDataSection("romdatw", &w, &wn) && wn)
            AddRegion(w, wn); /* the game's initialised variables */
    }
    AddRegion(gEwramHeapStart, sizeof(gEwramHeapStart));
    AddRegion(gIwramHeapStart, sizeof(gIwramHeapStart));
    AddRegion(gPcVram, PC_VRAM_SIZE);
    AddRegion(gPcPltt, PC_PLTT_SIZE);
    AddRegion(gPcOam, PC_OAM_SIZE);
    AddRegion(gPcIoRegs, PC_IO_SIZE);
    AddRegion(&gSoundInfoPtr, sizeof(gSoundInfoPtr));
    AddRegion((void*)&gIntrCheck, sizeof(gIntrCheck));
    AddRegion(&gPcIntrVector, sizeof(gPcIntrVector));
    p = PcFrameState(&n);
    AddRegion(p, n);
    p = PcDmaState(&n);
    AddRegion(p, n);
    p = PcRenderState(&n);
    AddRegion(p, n);
    p = PcIntrState(&n);
    AddRegion(p, n);
    p = PcApuState(&n);
    AddRegion(p, n);

    sRecent.data = malloc(sTotalSize);
    sOlder.data = malloc(sTotalSize);
    sQuick.data = malloc(sTotalSize);
    PcLog("[pc] snapshots: %lu KiB each\n", (unsigned long)(sTotalSize / 1024));
}

static void Capture(Snapshot* s) {
    uint8_t* out = s->data;
    int i;
    if (!out)
        return;
    for (i = 0; i < sNumRegions; i++) {
        RawCopy(out, sRegions[i].ptr, sRegions[i].size);
        out += sRegions[i].size;
    }
    s->valid = 1;
    s->frame = gPcFrameCount;
}

static void Restore(const Snapshot* s) {
    const uint8_t* in = s->data;
    int i;
    for (i = 0; i < sNumRegions; i++) {
        RawCopy(sRegions[i].ptr, in, sRegions[i].size);
        in += sRegions[i].size;
    }
    PcIntrResetDepth();
    PcResetNullPage();
}

/* ---- Quick save / load files ---- */

typedef struct {
    char magic[8];       /* "KHCOMSS1" */
    uint32_t totalSize;  /* must match this build */
    uint32_t numRegions;
    char build[32];      /* build date/time and load address: states only load into the same
                          * exe at the same address (they hold pointers) */
} FileHeader;

static void FillHeader(FileHeader* h) {
    memset(h, 0, sizeof(*h));
    memcpy(h->magic, "KHCOMSS1", 8);
    h->totalSize = (uint32_t)sTotalSize;
    h->numRegions = (uint32_t)sNumRegions;
    snprintf(h->build, sizeof(h->build), "%s %s %08lx", __DATE__, __TIME__,
             (unsigned long)(uintptr_t)gPcGameDataBegin);
}

static int WriteQuickFile(const char* path) {
    FileHeader h;
    FILE* f = fopen(path, "wb");
    int ok;
    if (!f)
        return 0;
    FillHeader(&h);
    ok = fwrite(&h, sizeof(h), 1, f) == 1 && fwrite(sQuick.data, 1, sTotalSize, f) == sTotalSize;
    ok = (fclose(f) == 0) && ok;
    return ok;
}

static int ReadQuickFile(const char* path) {
    FileHeader h, want;
    FILE* f = fopen(path, "rb");
    int ok;
    if (!f)
        return 0;
    FillHeader(&want);
    ok = fread(&h, sizeof(h), 1, f) == 1 && memcmp(&h, &want, sizeof(h)) == 0 &&
         fread(sQuick.data, 1, sTotalSize, f) == sTotalSize;
    fclose(f);
    if (ok)
        sQuick.valid = 1;
    return ok;
}

void PcStateRequestQuickSave(const char* path) {
    snprintf(sQuickPath, sizeof(sQuickPath), "%s", path);
    sQuickRequest = 1;
}

void PcStateRequestQuickLoad(const char* path) {
    snprintf(sQuickPath, sizeof(sQuickPath), "%s", path);
    sQuickRequest = 2;
}

/* Result of the last quick save/load for the frontend to show: 0 none,
 * 1 saved, 2 loaded, -1 save failed, -2 load failed (missing/other build). */
static int sQuickResult;
int PcStateTakeQuickResult(void) {
    int r = sQuickResult;
    sQuickResult = 0;
    return r;
}

/* ---- Main-loop point (called from VBlankIntrWait) ---- */

void PcStateMainLoopPoint(void) {
    if (!sNumRegions)
        return;

    if (sQuickRequest == 1) {
        Capture(&sQuick);
        sQuickResult = WriteQuickFile(sQuickPath) ? 1 : -1;
        PcLog("[pc] quick save %s: %s\n", sQuickResult > 0 ? "written" : "FAILED", sQuickPath);
    } else if (sQuickRequest == 2) {
        if (ReadQuickFile(sQuickPath)) {
            Restore(&sQuick);
            sQuickResult = 2;
            PcLog("[pc] quick load: %s\n", sQuickPath);
        } else {
            sQuickResult = -2;
            PcLog("[pc] quick load failed (missing, or made by another build): %s\n", sQuickPath);
        }
    }
    sQuickRequest = 0;

    if (++sAutoCounter % AUTO_INTERVAL == 0) {
        if (sRecent.valid && (sAutoCounter / AUTO_INTERVAL) % OLDER_EVERY == 0) {
            Snapshot t = sOlder;
            sOlder = sRecent;
            sRecent = t;
        }
        Capture(&sRecent);
    }
}

/* ---- Crash recovery ---- */

int PcStateCanResume(void) {
    /* Three crashes in a row (within 30 s each) means the snapshots
     * themselves are bad; a crash long after the last one starts afresh. */
    return sNumRegions && (sRecent.valid || sOlder.valid) &&
           (sResumeAttempts < 3 || gPcFrameCount - sLastResumeFrame >= 1800);
}

static int sRecoveredNotice;
int PcTakeRecoveredNotice(void) {
    int r = sRecoveredNotice;
    sRecoveredNotice = 0;
    return r;
}

int PcConsumeResume(void) {
    int r = sResumePending;
    sResumePending = 0;
    return r;
}

/* Called instead of crashing (from the exception handler or the watchdog,
 * on the game thread). Restores a snapshot and re-enters AgbMain's loop
 * through the frontend's jump back into main(). Does not return. */
void PcStateResumeAfterCrash(void) {
    const Snapshot* s;

    /* A crash soon after a resume probably comes from the restored state:
     * go further back, and give up after a few tries. */
    if (sResumeAttempts > 0 && gPcFrameCount - sLastResumeFrame < 1800)
        sResumeAttempts++;
    else
        sResumeAttempts = 1;
    sLastResumeFrame = gPcFrameCount;

    s = (sResumeAttempts >= 2 && sOlder.valid) ? &sOlder : (sRecent.valid ? &sRecent : &sOlder);
    PcLog("[pc] RECOVERY: resuming from the snapshot of frame %u (attempt %d)\n", s->frame, sResumeAttempts);
    Restore(s);
    sResumePending = 1;
    sRecoveredNotice = 1;
    PcLongjmpToMain(2);
}
