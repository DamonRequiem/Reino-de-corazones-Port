/*
 * pc_frame.c
 * Scanline-stepped display timing.
 *
 * A GBA frame is 228 scanlines: 160 visible lines followed by 68 lines of
 * VBlank. Each visible line is drawn, then the hardware enters HBlank (HBlank
 * DMA + interrupt); the line matching DISPSTAT's VCount setting raises VCount;
 * entering line 160 raises VBlank.
 *
 * On the console this beam runs in parallel with the CPU. Here it advances
 * only when the game waits for it:
 *   - VBlankIntrWait() steps lines until the next VBlank interrupt, exactly
 *     where the BIOS call would return on hardware;
 *   - code that busy-waits on the beam (e.g. the movie player reading VCOUNT)
 *     calls PcYieldScanline() to let one line pass.
 * Register changes therefore land on the same scanline as on hardware, which
 * is what raster effects depend on.
 */
#include "pc_platform.h"

#define DISPSTAT_VBLANK      0x0001
#define DISPSTAT_HBLANK      0x0002
#define DISPSTAT_VCOUNT      0x0004
#define DISPSTAT_VBLANK_INTR 0x0008
#define DISPSTAT_HBLANK_INTR 0x0010
#define DISPSTAT_VCOUNT_INTR 0x0020

#define VISIBLE_LINES 160
#define TOTAL_LINES   228

uint32_t gPcFrameCount;
PcScanlineHook gPcScanlineHook;
PcFrameHook gPcFrameHook;
int gPcSkipMovies = 1; /* Start skips cinematics (PC addition; khcom.ini [game]) */

static struct {
    int line;           /* scanline the beam is on (0..227) */
    int vblankHappened;
} sBeam;
#define sLine sBeam.line
#define sVBlankHappened sBeam.vblankHappened

/* For snapshots (pc_state.c). */
void* PcFrameState(size_t* size) {
    *size = sizeof(sBeam);
    return &sBeam;
}

static void EnterLine(int line) {
    uint16_t stat = PC_IO16(PC_REG_DISPSTAT);

    PC_IO16(PC_REG_VCOUNT) = (uint16_t)line;
    stat &= ~(DISPSTAT_VCOUNT | DISPSTAT_HBLANK | DISPSTAT_VBLANK);
    if ((stat >> 8) == line)
        stat |= DISPSTAT_VCOUNT;
    if (line >= VISIBLE_LINES && line < TOTAL_LINES - 1)
        stat |= DISPSTAT_VBLANK;
    PC_IO16(PC_REG_DISPSTAT) = stat;

    if (line == VISIBLE_LINES) {
        /* Frame complete: present it before the game starts the next one. */
        gPcFrameCount++;
        PcResetNullPage();
        if (gPcFrameHook != NULL)
            gPcFrameHook();
        PcDmaRunTiming(PC_DMA_TIMING_VBLANK);
        if (stat & DISPSTAT_VBLANK_INTR)
            PcRaiseIrq(PC_IRQ_VBLANK);
        sVBlankHappened = 1;
    }
}

/* Everything that happens on the current line after it starts. */
static void FinishLine(int line) {
    uint16_t stat;

    if (line < VISIBLE_LINES && gPcScanlineHook != NULL)
        gPcScanlineHook(line);

    PC_IO16(PC_REG_DISPSTAT) |= DISPSTAT_HBLANK;
    stat = PC_IO16(PC_REG_DISPSTAT);

    /* VCount handlers run after the line is drawn, so their changes take effect
     * from the next line, as when they wait for HBlank on hardware. */
    if ((stat & DISPSTAT_VCOUNT) && (stat & DISPSTAT_VCOUNT_INTR))
        PcRaiseIrq(PC_IRQ_VCOUNT);
    if (line < VISIBLE_LINES)
        PcDmaRunTiming(PC_DMA_TIMING_HBLANK);
    if (stat & DISPSTAT_HBLANK_INTR)
        PcRaiseIrq(PC_IRQ_HBLANK);
}

void PcYieldScanline(void) {
    PcApuStep(1232); /* one scanline of CPU time */
    PcDispatchPendingIrqs();
    FinishLine(sLine);
    sLine = (sLine + 1) % TOTAL_LINES;
    EnterLine(sLine);
}

void PcRunFrame(void) {
    sVBlankHappened = 0;
    while (!sVBlankHappened)
        PcYieldScanline();
}
