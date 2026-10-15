/*
 * pc_dma.c
 * Emulated DMA controller.
 *
 * The game programs DMA through the DmaSet/DmaStop macros (include/gba/macro.h),
 * which on PC call PcDmaSet/PcDmaStop. Immediate transfers run right away;
 * VBlank and HBlank transfers are kept armed and executed by the frame
 * scheduler at the right moment, like the hardware does (used for scanline
 * scroll effects). Sound FIFO transfers (DMA1/2 "special" timing) are ignored
 * here; the audio mixer reads the game's sound buffers directly.
 */
#include <string.h>
#include "pc_platform.h"

#define DMA_DEST_INC     0
#define DMA_DEST_DEC     1
#define DMA_DEST_FIXED   2
#define DMA_DEST_RELOAD  3
#define DMA_SRC_INC      0
#define DMA_SRC_DEC      1
#define DMA_SRC_FIXED    2

#define CNT_H_REPEAT  (1 << 9)
#define CNT_H_32BIT   (1 << 10)
#define CNT_H_ENABLE  (1 << 15)

typedef struct {
    const uint8_t* src;     /* current source pointer */
    uint8_t* dest;          /* current destination pointer */
    uint8_t* destReload;    /* destination to restore for DEST_RELOAD repeats */
    uint32_t count;         /* units per transfer */
    uint16_t cntH;          /* control bits (upper half of DMAxCNT) */
} PcDmaChannel;

static PcDmaChannel sDma[4];

/* For snapshots (pc_state.c). The channels point into game memory, which is
 * restored at the same addresses. */
void* PcDmaState(size_t* size) {
    *size = sizeof(sDma);
    return sDma;
}

static void StoreRegs(int ch, const void* src, void* dest, uint32_t control) {
    /* Keep the IO view consistent so code that reads DMAxCNT back still works.
     * Pointers are truncated to 32 bits; that only matters for debugging. */
    PC_IO32(PC_REG_DMA0SAD + ch * 12 + 0) = (uint32_t)(uintptr_t)src;
    PC_IO32(PC_REG_DMA0SAD + ch * 12 + 4) = (uint32_t)(uintptr_t)dest;
    PC_IO32(PC_REG_DMA0SAD + ch * 12 + 8) = control;
}

static void Transfer(PcDmaChannel* d) {
    uint32_t unit = (d->cntH & CNT_H_32BIT) ? 4 : 2;
    int srcMode = (d->cntH >> 7) & 3;
    int destMode = (d->cntH >> 5) & 3;
    int32_t srcStep = srcMode == DMA_SRC_INC ? (int32_t)unit : srcMode == DMA_SRC_DEC ? -(int32_t)unit : 0;
    int32_t destStep = (destMode == DMA_DEST_INC || destMode == DMA_DEST_RELOAD) ? (int32_t)unit
                       : destMode == DMA_DEST_DEC ? -(int32_t)unit : 0;
    uint32_t i;

    /* Fast path: plain incrementing copy. */
    if (srcStep == (int32_t)unit && destStep == (int32_t)unit) {
        memmove(d->dest, d->src, (size_t)d->count * unit);
        d->src += d->count * unit;
        d->dest += d->count * unit;
        return;
    }

    for (i = 0; i < d->count; i++) {
        if (unit == 4)
            memcpy(d->dest, d->src, 4);
        else
            memcpy(d->dest, d->src, 2);
        d->src += srcStep;
        d->dest += destStep;
    }
}

void PcDmaSet(int ch, const void* src, void* dest, uint32_t control) {
    PcDmaChannel* d;
    uint16_t cntH = (uint16_t)(control >> 16);
    uint32_t count = control & 0xFFFF;
    int timing;

    if (ch < 0 || ch > 3)
        return;
    d = &sDma[ch];
    StoreRegs(ch, src, dest, control);

    if (!(cntH & CNT_H_ENABLE)) {
        d->cntH = 0;
        return;
    }
    if (count == 0)
        count = (ch == 3) ? 0x10000 : 0x4000;

    /* Low addresses are the GBA BIOS/unmapped area: writes there are ignored
     * and reads return the BIOS latch (see gPcNullPage). Original-game bugs do
     * transfer from/to NULL (+offset), so mirror that instead of crashing.
     * No host object lives below 64 KiB on Windows or Linux. */
    if ((uintptr_t)dest < 0x10000) {
        d->cntH = 0;
        return;
    }
    if ((uintptr_t)src < 0x10000) {
        src = gPcNullPage;
        cntH = (uint16_t)((cntH & ~(3 << 7)) | (DMA_SRC_FIXED << 7));
    }

    d->src = (const uint8_t*)src;
    d->dest = (uint8_t*)dest;
    d->destReload = (uint8_t*)dest;
    d->count = count;
    d->cntH = cntH;

    timing = (cntH >> 12) & 3;
    if (timing == PC_DMA_TIMING_IMMEDIATE) {
        Transfer(d);
        d->cntH &= ~CNT_H_ENABLE;
        PC_IO32(PC_REG_DMA0SAD + ch * 12 + 8) &= ~((uint32_t)CNT_H_ENABLE << 16);
    }
}

void PcDmaStop(int ch) {
    if (ch < 0 || ch > 3)
        return;
    sDma[ch].cntH = 0;
    PC_IO32(PC_REG_DMA0SAD + ch * 12 + 8) &= ~((uint32_t)(CNT_H_ENABLE | CNT_H_REPEAT | (3 << 12)) << 16);
}

void PcDmaReset(void) {
    memset(sDma, 0, sizeof(sDma));
}

void PcDmaRunTiming(int timing) {
    int ch;

    for (ch = 0; ch < 4; ch++) {
        PcDmaChannel* d = &sDma[ch];

        if (!(d->cntH & CNT_H_ENABLE) || ((d->cntH >> 12) & 3) != timing)
            continue;
        /* Sound FIFO transfers use "special" timing and are never matched here. */
        Transfer(d);
        if (d->cntH & CNT_H_REPEAT) {
            if (((d->cntH >> 5) & 3) == DMA_DEST_RELOAD)
                d->dest = d->destReload;
        } else {
            d->cntH &= ~CNT_H_ENABLE;
            PC_IO32(PC_REG_DMA0SAD + ch * 12 + 8) &= ~((uint32_t)CNT_H_ENABLE << 16);
        }
    }
}
