/*
 * pc_softreset.c
 * Boot-time snapshot of the game's globals, restored on soft reset.
 *
 * On the GBA a soft reset (A+B+Start+Select, or SoftReset() from the game)
 * clears RAM and restarts AgbMain, so every variable starts over. On PC the
 * game's variables are ordinary globals; this keeps a copy of their initial
 * contents and puts it back before AgbMain runs again.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "pc_platform.h"

extern char gPcGameDataBegin[], gPcGameDataEnd[];
extern char gPcGameBssBegin[], gPcGameBssEnd[];

static void* sDataCopy;
static void* sWCopy;      /* the game's initialised variables ("romdatw") */
static uint8_t* sWStart;
static size_t sWSize;
static void* sBssCopy;
static size_t sDataSize, sBssSize;

/* The range includes the padding between variables, which AddressSanitizer
 * test builds mark as off-limits; copy it byte by byte without checks. */
#if defined(__GNUC__)
__attribute__((no_sanitize_address, noinline))
#endif
static void RawCopy(void* dst, const void* src, size_t n) {
    volatile unsigned char* d = (volatile unsigned char*)dst;
    const volatile unsigned char* s = (const volatile unsigned char*)src;
    while (n--)
        *d++ = *s++;
}

static int RangeOk(const char* begin, const char* end) {
    return end > begin && (size_t)(end - begin) < (64u << 20);
}

void PcSaveGameState(void) {
    if (PcRomDataSection("romdatw", &sWStart, &sWSize) && sWSize) {
        sWCopy = malloc(sWSize);
        if (sWCopy)
            RawCopy(sWCopy, sWStart, sWSize);
    }
    if (RangeOk(gPcGameDataBegin, gPcGameDataEnd)) {
        sDataSize = (size_t)(gPcGameDataEnd - gPcGameDataBegin);
        sDataCopy = malloc(sDataSize);
        if (sDataCopy)
            RawCopy(sDataCopy, gPcGameDataBegin, sDataSize);
    }
    if (RangeOk(gPcGameBssBegin, gPcGameBssEnd)) {
        sBssSize = (size_t)(gPcGameBssEnd - gPcGameBssBegin);
        sBssCopy = malloc(sBssSize);
        if (sBssCopy)
            RawCopy(sBssCopy, gPcGameBssBegin, sBssSize);
    }
    PcLog("[pc] game state: %lu bytes of data, %lu bytes of bss%s\n", (unsigned long)(sDataSize + sWSize),
          (unsigned long)sBssSize, (sDataCopy && sBssCopy) ? "" : " (snapshot unavailable)");
}

void PcRestoreGameState(void) {
    if (sWCopy)
        RawCopy(sWStart, sWCopy, sWSize);
    if (sDataCopy)
        RawCopy(gPcGameDataBegin, sDataCopy, sDataSize);
    if (sBssCopy)
        RawCopy(gPcGameBssBegin, sBssCopy, sBssSize);
    /* The hardware side: the BIOS reset already cleared memory and registers;
     * drop any interrupt or DMA left over from before the reset. */
    PcDmaReset();
    PcClearPendingIrqs();
    PcApuReset();
}
