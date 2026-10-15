/*
 * pc_save.c
 * Cartridge SRAM persisted to a .sav file.
 *
 * The game keeps its save data in 32 KiB of battery-backed SRAM (gPcSram on
 * PC). The file is a raw image of that memory, the same format GBA emulators
 * use, so saves can be moved between this port and mGBA / VisualBoyAdvance.
 *
 * Writes from the game (WriteSramFast, src/lib/agb_sram.c) mark the image
 * dirty; it is written to disk once the game has stopped writing for half a
 * second, and when the program exits. Disk writes go to a temporary file that
 * then replaces the save, so a crash or power cut cannot leave a half-written
 * file. The first write of each session also keeps the previous save as
 * <name>.bak.
 */
#include <stdio.h>
#include <string.h>
#include "pc_platform.h"

#ifdef _WIN32
#include <windows.h>
#endif

#define FLUSH_DELAY_FRAMES 30

static char sPath[1024];
static int sDirty;
static uint32_t sLastWriteFrame;
static int sBackedUp;

static int ReplaceFile_(const char* tmp, const char* dst) {
#ifdef _WIN32
    wchar_t wtmp[1024], wdst[1024];
    MultiByteToWideChar(CP_UTF8, 0, tmp, -1, wtmp, 1024);
    MultiByteToWideChar(CP_UTF8, 0, dst, -1, wdst, 1024);
    return MoveFileExW(wtmp, wdst, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != 0;
#else
    return rename(tmp, dst) == 0;
#endif
}

static FILE* OpenUtf8(const char* path, const char* mode) {
#ifdef _WIN32
    wchar_t wpath[1024], wmode[8];
    MultiByteToWideChar(CP_UTF8, 0, path, -1, wpath, 1024);
    MultiByteToWideChar(CP_UTF8, 0, mode, -1, wmode, 8);
    return _wfopen(wpath, wmode);
#else
    return fopen(path, mode);
#endif
}

static int WriteImage(const char* path, const uint8_t* data, size_t size) {
    FILE* f = OpenUtf8(path, "wb");
    int ok;
    if (!f)
        return 0;
    ok = fwrite(data, 1, size, f) == size;
    ok = (fflush(f) == 0) && ok;
    ok = (fclose(f) == 0) && ok;
    return ok;
}

int PcSaveLoad(const char* path) {
    FILE* f;
    size_t n;

    snprintf(sPath, sizeof(sPath), "%s", path);
    /* A blank cartridge reads as 0xFF (also what emulators use). */
    memset(gPcSram, 0xFF, PC_SRAM_SIZE);
    f = OpenUtf8(sPath, "rb");
    if (!f) {
        PcLog("[pc] save: no file yet (%s)\n", sPath);
        return 0;
    }
    n = fread(gPcSram, 1, PC_SRAM_SIZE, f);
    fclose(f);
    /* Emulators sometimes pad saves to 64 KiB; the first 32 KiB is the SRAM. */
    PcLog("[pc] save: loaded %lu bytes from %s\n", (unsigned long)n, sPath);
    return n > 0;
}

void PcSaveMarkDirty(void) {
    sDirty = 1;
    sLastWriteFrame = gPcFrameCount;
}

void PcSaveFlush(void) {
    char tmp[1100], bak[1100];

    if (!sDirty || sPath[0] == '\0')
        return;
    if (!sBackedUp) {
        FILE* f = OpenUtf8(sPath, "rb");
        if (f) {
            static uint8_t old[PC_SRAM_SIZE];
            size_t n = fread(old, 1, sizeof(old), f);
            fclose(f);
            snprintf(bak, sizeof(bak), "%s.bak", sPath);
            if (n > 0)
                WriteImage(bak, old, n);
        }
        sBackedUp = 1;
    }
    snprintf(tmp, sizeof(tmp), "%s.tmp", sPath);
    if (WriteImage(tmp, gPcSram, PC_SRAM_SIZE) && ReplaceFile_(tmp, sPath)) {
        sDirty = 0;
        PcLog("[pc] save: written to %s (frame %u)\n", sPath, gPcFrameCount);
    } else {
        PcLog("[pc] save: could not write %s\n", sPath);
        sLastWriteFrame = gPcFrameCount; /* retry after the delay, not every frame */
    }
}

void PcSaveTick(void) {
    if (sDirty && gPcFrameCount - sLastWriteFrame >= FLUSH_DELAY_FRAMES)
        PcSaveFlush();
}
