/*
 * pc_android_main.c  ->  libmain.so
 * Entry point of the Android app (SDLActivity calls SDL_main here).
 *
 * The game itself is libgame_usa.so or libgame_eur.so (one per version). Quick-save states hold pointers into the
 * game's memory, so they only load back into a game sitting at the same
 * address. Android picks a random address for every library, so this loader
 * reserves a fixed spot first and asks the system linker to put libgame.so
 * there (android_dlopen_ext + ANDROID_DLEXT_RESERVED_ADDRESS, Android 5.0+).
 * If none of the spots is free, the game still runs from wherever it lands;
 * only states saved in another session will not load.
 */
#include <dlfcn.h>
#include <elf.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <android/dlext.h>
#include <android/log.h>

#define TAG "ReinoDeCorazones"

int SDL_main(int argc, char** argv);

#if !defined(__LP64__)
/* Bytes of address space the library needs (its PT_LOAD span). */
static size_t LoadSpan(const char* path) {
    Elf32_Ehdr eh;
    Elf32_Phdr ph;
    size_t end = 0;
    int i, fd = open(path, O_RDONLY | O_CLOEXEC);
    if (fd < 0)
        return 0;
    if (pread(fd, &eh, sizeof(eh), 0) != (ssize_t)sizeof(eh) || memcmp(eh.e_ident, ELFMAG, SELFMAG)) {
        close(fd);
        return 0;
    }
    for (i = 0; i < eh.e_phnum; i++) {
        if (pread(fd, &ph, sizeof(ph), eh.e_phoff + i * eh.e_phentsize) != (ssize_t)sizeof(ph))
            break;
        if (ph.p_type == PT_LOAD && ph.p_vaddr + ph.p_memsz > end)
            end = ph.p_vaddr + ph.p_memsz;
    }
    close(fd);
    return (end + 0xFFFFF) & ~(size_t)0xFFFFF; /* whole megabytes */
}
#endif

static void* LoadGame(const char* path) {
#if defined(__LP64__)
    /* 64-bit phones run the game as a 32-bit core inside libgame (port/wasm/):
     * its memory addresses never change, wherever the library lands. */
    void* h = dlopen(path, RTLD_NOW);
    if (!h)
        __android_log_print(ANDROID_LOG_ERROR, TAG, "cannot load %s: %s", path, dlerror());
    return h;
#else
    /* Low in the 32-bit address space, clear of the Java heap (0x12C00000+)
     * and of where the system maps libraries (from the top down). */
    static const uintptr_t kSpots[] = {0x60000000, 0x58000000, 0x68000000, 0x50000000, 0x70000000, 0x48000000};
    size_t span = LoadSpan(path);
    unsigned i;
    void* h;
    for (i = 0; span && i < sizeof(kSpots) / sizeof(kSpots[0]); i++) {
        void* want = (void*)kSpots[i];
        void* got = mmap(want, span, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0);
        android_dlextinfo ext;
        if (got == MAP_FAILED)
            continue;
        if (got != want) {
            munmap(got, span);
            continue;
        }
        memset(&ext, 0, sizeof(ext));
        ext.flags = ANDROID_DLEXT_RESERVED_ADDRESS;
        ext.reserved_addr = got;
        ext.reserved_size = span;
        h = android_dlopen_ext(path, RTLD_NOW, &ext);
        if (h) {
            __android_log_print(ANDROID_LOG_INFO, TAG, "libgame.so at %p (%zu MB)", got, span >> 20);
            return h;
        }
        __android_log_print(ANDROID_LOG_WARN, TAG, "fixed load at %p failed: %s", got, dlerror());
        munmap(got, span);
    }
    h = dlopen(path, RTLD_NOW);
    if (!h)
        __android_log_print(ANDROID_LOG_ERROR, TAG, "cannot load %s: %s", path, dlerror());
    return h;
#endif
}

int SDL_main(int argc, char** argv) {
    char path[1024];
    Dl_info self;
    char* slash;
    void* game;
    int (*gameMain)(int, char**);

    /* libgame.so sits next to this library. */
    if (!dladdr((void*)&SDL_main, &self) || !self.dli_fname)
        return 1;
    snprintf(path, sizeof(path), "%s", self.dli_fname);
    slash = strrchr(path, '/');
    if (!slash)
        return 1;
    {
        /* One game library per version of the game (they differ in code). */
        const char* region = "usa";
        int i;
        for (i = 1; i + 1 < argc; i++)
            if (!strcmp(argv[i], "--region"))
                region = argv[i + 1];
        snprintf(slash + 1, sizeof(path) - (size_t)(slash + 1 - path), "libgame_%s.so",
                 !strcmp(region, "eur") ? "eur" : "usa");
    }
    game = LoadGame(path);
    if (!game)
        return 1;
    gameMain = (int (*)(int, char**))dlsym(game, "SDL_main");
    if (!gameMain || gameMain == SDL_main) {
        __android_log_print(ANDROID_LOG_ERROR, TAG, "libgame.so has no entry point");
        return 1;
    }
    return gameMain(argc, argv);
}
