/*
 * pc_main_headless.c
 * Phase 1 entry point: runs the game with no window, sound or input.
 *
 * It boots AgbMain on the emulated hardware, advances a fixed number of
 * frames and writes screenshots, so the port can be tested on any machine
 * (including automated checks).
 *
 *   khcom_headless [--frames N] [--dump-every N] [--out DIR] [--sav FILE] [--press F:KEYS]...
 *
 * --press F:KEYS holds keys on frame F for 4 frames. KEYS is any of
 * A B S(elect) T (sTart) R L U D r(ight-shoulder) l(eft-shoulder).
 */
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pc_platform.h"

#ifdef _WIN32
/* No signal masks on Windows: plain setjmp/longjmp do the same job. */
#define sigjmp_buf jmp_buf
#define sigsetjmp(env, save) setjmp(env)
#define siglongjmp longjmp
#endif

static sigjmp_buf sResetJump;
static uint32_t sMaxFrames = 1200;
static uint32_t sDumpEvery = 60;
static const char* sOutDir = ".";
static const char* sSavPath;
static FILE* sWav;          /* --wav: record the audio output */
static FILE* sPcmDump;      /* --dump-pcm: m4a PCM buffer every frame */
const void* PcTestPcmBuffer(int* size, int* dmaCounter, int* samplesPerVBlank);
static uint32_t sWavFrames;
static uint32_t sCallSaveFrame; /* test: save game file 1 at this frame */
static uint32_t sCrashAtFrame;  /* test: crash once at this frame */
void SaveWriteFileLarge(uint16_t file);

#define MAX_PRESSES 8192
static struct { uint32_t frame; uint16_t keys; } sPresses[MAX_PRESSES];
static int sNumPresses;

void PcLog(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

void PcLongjmpToMain(int code) {
    siglongjmp(sResetJump, code);
}

void PcRequestSoftReset(void) {
    PcLog("[pc] soft reset at frame %u\n", gPcFrameCount);
    PcLongjmpToMain(1);
}

static uint16_t ParseKeys(const char* s) {
    uint16_t k = 0;
    for (; *s; s++) {
        switch (*s) {
            case 'A': k |= 1 << 0; break;
            case 'B': k |= 1 << 1; break;
            case 'S': k |= 1 << 2; break;
            case 'T': k |= 1 << 3; break;
            case 'R': k |= 1 << 4; break;
            case 'L': k |= 1 << 5; break;
            case 'U': k |= 1 << 6; break;
            case 'D': k |= 1 << 7; break;
            case 'r': k |= 1 << 8; break;
            case 'l': k |= 1 << 9; break;
        }
    }
    return k;
}

static void WavWriteHeader(void) {
    uint8_t h[44] = {'R', 'I', 'F', 'F', 0, 0, 0, 0, 'W', 'A', 'V', 'E', 'f', 'm', 't', ' ', 16, 0, 0, 0, 1, 0, 2, 0};
    uint32_t rate = PC_AUDIO_RATE, byteRate = PC_AUDIO_RATE * 4, data = sWavFrames * 4, riff = 36 + data;
    memcpy(h + 4, &riff, 4);
    memcpy(h + 24, &rate, 4);
    memcpy(h + 28, &byteRate, 4);
    h[32] = 4;
    h[34] = 16;
    memcpy(h + 36, "data", 4);
    memcpy(h + 40, &data, 4);
    fseek(sWav, 0, SEEK_SET);
    fwrite(h, 1, 44, sWav);
    fseek(sWav, 0, SEEK_END);
}

static void DrainAudio(void) {
    int16_t buf[1024 * 2];
    unsigned n;
    while ((n = PcApuReadSamples(buf, 1024)) > 0) {
        if (sWav) {
            fwrite(buf, 4, n, sWav);
            sWavFrames += n;
        }
    }
}

static void FrameHook(void) {
    uint16_t held = 0;
    int i;
    char path[512];

    for (i = 0; i < sNumPresses; i++)
        if (gPcFrameCount >= sPresses[i].frame && gPcFrameCount < sPresses[i].frame + 4)
            held |= sPresses[i].keys;
    /* KEYINPUT is active-low. */
    PC_IO16(PC_REG_KEYINPUT) = (uint16_t)(0x03FF & ~held);

    if (sDumpEvery && gPcFrameCount % sDumpEvery == 0) {
        snprintf(path, sizeof(path), "%s/frame_%05u.bmp", sOutDir, gPcFrameCount);
        PcSaveScreenshot(path);
        PcLog("[pc] frame %5u  DISPCNT=%04X  BG0CNT=%04X BG1CNT=%04X BG2CNT=%04X BG3CNT=%04X\n", gPcFrameCount,
              PC_IO16(0x00), PC_IO16(0x08), PC_IO16(0x0A), PC_IO16(0x0C), PC_IO16(0x0E));
    }
    if (sCrashAtFrame && gPcFrameCount == sCrashAtFrame) {
        volatile int* volatile bad = (int*)(uintptr_t)0x12345678; /* not a GBA-style address */
        sCrashAtFrame = 0;
        *bad = 1;
    }
    if (sCallSaveFrame && gPcFrameCount == sCallSaveFrame) {
        /* What a save point does when the player confirms (src/map/map.c). */
        SaveWriteFileLarge(0);
        PcLog("[pc] test: saved file 1 at frame %u\n", gPcFrameCount);
    }
    PcSaveTick();
    DrainAudio();
    if (sPcmDump) {
        int size = 0, counter = 0, spv = 0;
        const void* pcm = PcTestPcmBuffer(&size, &counter, &spv);
        uint8_t hdr[4] = {(uint8_t)counter, (uint8_t)spv, (uint8_t)(spv >> 8), 0};
        static uint8_t zero[3168];
        fwrite(hdr, 1, 4, sPcmDump);
        fwrite(pcm ? pcm : zero, 1, 3168, sPcmDump);
    }
    if (gPcFrameCount >= sMaxFrames) {
        PcLog("[pc] reached %u frames without crashing\n", gPcFrameCount);
        if (sWav) {
            WavWriteHeader();
            fclose(sWav);
        }
        PcSaveFlush();
        exit(0);
    }
}

static int sResumeOnCrash; /* --resume-on-crash: test the snapshot recovery */

static void CrashHandler(int sig) {
    fprintf(stderr, "[pc] CRASH: signal %d at frame %u\n", sig, gPcFrameCount);
    if (sResumeOnCrash && PcStateCanResume()) {
        signal(sig, CrashHandler);
        PcStateResumeAfterCrash(); /* siglongjmps back into main() */
    }
    _Exit(3);
}

static const char* sRomPath;
static const char* sMapPath;

int main(int argc, char** argv) {
    int i;

    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--frames") && i + 1 < argc)
            sMaxFrames = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--dump-every") && i + 1 < argc)
            sDumpEvery = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--selftest")) {
            /* Checks the GBA-compatible division by zero. */
            volatile int a = 1234, z = 0, m = -1, mn = (int)0x80000000;
            PcInstallDivZeroHandler();
            printf("1234/0=%d 1234%%0=%d INT_MIN/-1=%d\n", a / z, a % z, mn / m);
            return 0;
        } else if (!strcmp(argv[i], "--selftest-game")) {
            extern int PcSelfTestClearStockedSlots(void);
            int cleared;
            PcResetNullPage();
            signal(SIGSEGV, CrashHandler);
            PcInstallFaultRecovery();
            cleared = PcSelfTestClearStockedSlots();
            printf("sleight slot clear: %d main slot(s) cleared (GBA: 1), recoveries=%lu\n", cleared,
                   PcFaultRecoveries());
            return 0;
        } else if (!strcmp(argv[i], "--faulttest")) {
            /* Checks the fault recovery: a read and a write through NULL+offset
             * and through a BIOS-latch pointer must behave like the GBA. */
            struct { int pad[3]; int field; } * volatile p = NULL;
            int* volatile q = (int*)(uintptr_t)0xE3A02004u;
            int v1, v2;
            PcResetNullPage();
            signal(SIGSEGV, CrashHandler);
            PcInstallFaultRecovery();
            v1 = p->field;
            p->field = 5;
            v2 = *q;
            printf("NULL->field=0x%08X latch=0x%08X recoveries=%lu\n", (unsigned)v1, (unsigned)v2, PcFaultRecoveries());
            return 0;
        } else if (!strcmp(argv[i], "--resume-on-crash"))
            sResumeOnCrash = 1;
        else if (!strcmp(argv[i], "--crash-at") && i + 1 < argc)
            sCrashAtFrame = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--call-save") && i + 1 < argc)
            sCallSaveFrame = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--mute") && i + 1 < argc) {
            extern int gPcApuMute;
            gPcApuMute = atoi(argv[++i]);
        } else if (!strcmp(argv[i], "--dump-pcm") && i + 1 < argc)
            sPcmDump = fopen(argv[++i], "wb");
        else if (!strcmp(argv[i], "--wav") && i + 1 < argc) {
            sWav = fopen(argv[++i], "wb");
            if (sWav)
                fwrite("\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 1, 44, sWav);
        } else if (!strcmp(argv[i], "--sav") && i + 1 < argc)
            sSavPath = argv[++i];
        else if (!strcmp(argv[i], "--rom") && i + 1 < argc)
            sRomPath = argv[++i];
        else if (!strcmp(argv[i], "--map") && i + 1 < argc)
            sMapPath = argv[++i];
        else if (!strcmp(argv[i], "--out") && i + 1 < argc)
            sOutDir = argv[++i];
        else if (!strcmp(argv[i], "--press") && i + 1 < argc && sNumPresses < MAX_PRESSES) {
            char* colon;
            ++i;
            colon = strchr(argv[i], ':');
            if (colon) {
                sPresses[sNumPresses].frame = (uint32_t)strtoul(argv[i], NULL, 0);
                sPresses[sNumPresses].keys = ParseKeys(colon + 1);
                sNumPresses++;
            }
        } else {
            fprintf(stderr, "usage: %s [--frames N] [--dump-every N] [--out DIR] [--press FRAME:KEYS]\n", argv[0]);
            return 2;
        }
    }

    PcInstallDivZeroHandler();
    signal(SIGSEGV, CrashHandler);
    signal(SIGILL, CrashHandler);
    signal(SIGABRT, CrashHandler);
    PcInstallFaultRecovery(); /* after the crash handler: it chains to it */

    PC_IO16(PC_REG_KEYINPUT) = 0x03FF;
    if (sRomPath || PcRomDataNeeded()) {
        const char* err;
        if (!sRomPath || !sMapPath) {
            fprintf(stderr, "this engine has no game data: pass --rom your.gba --map engine.map\n");
            return 1;
        }
        err = PcRomDataLoad(sRomPath, sMapPath);
        if (err) {
            fprintf(stderr, "%s\n", err);
            return 1;
        }
    }
    PcApuReset();
    PcResetNullPage();
    gPcFrameHook = FrameHook;
    gPcScanlineHook = PcRenderScanline;

    if (sSavPath)
        PcSaveLoad(sSavPath);
    else
        memset(gPcSram, 0xFF, PC_SRAM_SIZE);
    PcSaveGameState();
    PcStateInit();
    if (sigsetjmp(sResetJump, 1) == 1)
        PcRestoreGameState();
    AgbMain();
    PcLog("[pc] AgbMain returned unexpectedly\n");
    return 1;
}
