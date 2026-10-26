/*
 * core_headless.c
 * Test runner for the 32-bit core turned into native code (port/wasm/):
 * the same options and output as khcom_headless, so the two can be compared
 * frame by frame and sample by sample.
 *
 *   core_headless --rom ROM --map MAP [--frames N] [--dump-every N] [--out DIR]
 *                 [--press F:KEYS]... [--wav FILE] [--sav FILE]
 */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pc_platform.h"

const char* RdcHostLoad(const char* romPath, const char* mapPath);
int RdcHostDumpImage(const char* path, uint32_t lo, uint32_t len);
static const char* sDumpImage;
void RdcHostTestBattle(uint32_t id);
static uint32_t sBattleAt, sBattleId;
static uint32_t sDumpLo, sDumpLen;
void RdcHostRun(void (*frameHook)(void));

static uint32_t sMaxFrames = 600, sDumpEvery;
static const char* sOutDir = ".";
static FILE* sWav;
static uint32_t sWavFrames;
#define MAX_PRESSES 8192
static struct { uint32_t frame; uint16_t keys; } sPresses[MAX_PRESSES];
static int sNumPresses;
static uint32_t sStateSaveAt, sStateLoadAt;
static const char* sStatePath = "core_test.state";

void PcLog(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
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

static void WavHeader(void) {
    uint32_t data = sWavFrames * 4, v;
    fseek(sWav, 0, SEEK_SET);
    fwrite("RIFF", 1, 4, sWav); v = 36 + data; fwrite(&v, 4, 1, sWav);
    fwrite("WAVEfmt ", 1, 8, sWav); v = 16; fwrite(&v, 4, 1, sWav);
    { uint16_t f[2] = {1, 2}; fwrite(f, 2, 2, sWav); }
    v = PC_AUDIO_RATE; fwrite(&v, 4, 1, sWav); v = PC_AUDIO_RATE * 4; fwrite(&v, 4, 1, sWav);
    { uint16_t f[2] = {4, 16}; fwrite(f, 2, 2, sWav); }
    fwrite("data", 1, 4, sWav); fwrite(&data, 4, 1, sWav);
}

static void FrameHook(void) {
    uint16_t held = 0;
    int16_t buf[1024 * 2];
    unsigned n;
    int i;
    char path[512];

    for (i = 0; i < sNumPresses; i++)
        if (gPcFrameCount >= sPresses[i].frame && gPcFrameCount < sPresses[i].frame + 4)
            held |= sPresses[i].keys;
    PC_IO16(PC_REG_KEYINPUT) = (uint16_t)(0x03FF & ~held);
    if (sBattleAt && gPcFrameCount == sBattleAt)
        RdcHostTestBattle(sBattleId);
    if (sDumpEvery && gPcFrameCount % sDumpEvery == 0) {
        snprintf(path, sizeof(path), "%s/frame_%05u.bmp", sOutDir, gPcFrameCount);
        PcSaveScreenshot(path);
        PcLog("[pc] frame %5u  DISPCNT=%04X  BG0CNT=%04X BG1CNT=%04X BG2CNT=%04X BG3CNT=%04X\n", gPcFrameCount,
              PC_IO16(0x00), PC_IO16(0x08), PC_IO16(0x0A), PC_IO16(0x0C), PC_IO16(0x0E));
    }
    if (sStateSaveAt && gPcFrameCount == sStateSaveAt)
        PcStateRequestQuickSave(sStatePath);
    if (sStateLoadAt && gPcFrameCount == sStateLoadAt)
        PcStateRequestQuickLoad(sStatePath);
    {
        int r = PcStateTakeQuickResult();
        if (r)
            PcLog("[pc] quick state result %d at frame %u\n", r, gPcFrameCount);
    }
    PcSaveTick();
    while ((n = PcApuReadSamples(buf, 1024)) > 0)
        if (sWav) {
            fwrite(buf, 4, n, sWav);
            sWavFrames += n;
        }
    if (gPcFrameCount >= sMaxFrames) {
        PcLog("[pc] reached %u frames without crashing\n", gPcFrameCount);
        if (sWav) {
            WavHeader();
            fclose(sWav);
        }
        PcSaveFlush();
        exit(0);
    }
}

int main(int argc, char** argv) {
    const char *rom = NULL, *map = NULL, *sav = NULL;
    const char* err;
    int i;
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--frames") && i + 1 < argc) sMaxFrames = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--dump-every") && i + 1 < argc) sDumpEvery = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--out") && i + 1 < argc) sOutDir = argv[++i];
        else if (!strcmp(argv[i], "--rom") && i + 1 < argc) rom = argv[++i];
        else if (!strcmp(argv[i], "--map") && i + 1 < argc) map = argv[++i];
        else if (!strcmp(argv[i], "--battle") && i + 1 < argc) {
            char* colon = strchr(argv[++i], ':');
            sBattleAt = (uint32_t)strtoul(argv[i], NULL, 0);
            sBattleId = colon ? (uint32_t)strtoul(colon + 1, NULL, 0) : 148;
        }
        else if (!strcmp(argv[i], "--dump-image") && i + 3 < argc) {
            sDumpImage = argv[++i];
            sDumpLo = (uint32_t)strtoul(argv[++i], NULL, 0);
            sDumpLen = (uint32_t)strtoul(argv[++i], NULL, 0);
        }
        else if (!strcmp(argv[i], "--sav") && i + 1 < argc) sav = argv[++i];
        else if (!strcmp(argv[i], "--state-save") && i + 1 < argc) sStateSaveAt = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--state-load") && i + 1 < argc) sStateLoadAt = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--state-file") && i + 1 < argc) sStatePath = argv[++i];
        else if (!strcmp(argv[i], "--wav") && i + 1 < argc) {
            sWav = fopen(argv[++i], "wb");
            if (sWav) fseek(sWav, 44, SEEK_SET);
        } else if (!strcmp(argv[i], "--press") && i + 1 < argc && sNumPresses < MAX_PRESSES) {
            char* colon = strchr(argv[++i], ':');
            if (colon) {
                sPresses[sNumPresses].frame = (uint32_t)strtoul(argv[i], NULL, 0);
                sPresses[sNumPresses].keys = ParseKeys(colon + 1);
                sNumPresses++;
            }
        }
    }
    if (!rom || !map) {
        fprintf(stderr, "usage: core_headless --rom ROM --map MAP [options]\n");
        return 2;
    }
    err = RdcHostLoad(rom, map);
    if (err) {
        fprintf(stderr, "%s\n", err);
        return 1;
    }
    if (sDumpImage) {
        RdcHostDumpImage(sDumpImage, sDumpLo, sDumpLen);
        return 0;
    }
    if (sav)
        PcSaveLoad(sav);
    PcApuReset();
    RdcHostRun(FrameHook);
    return 3;
}
