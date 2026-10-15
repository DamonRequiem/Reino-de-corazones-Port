/*
 * pc_core.c
 * The game as a 32-bit "core" for 64-bit-only phones.
 *
 * The decompiled game assumes 32-bit pointers everywhere, its data tables
 * included. Phones from 2024 on can only run 64-bit code, so there the game
 * (src/ + its data + the emulated GBA hardware in port/) is compiled to
 * wasm32 — a 32-bit memory model — and wasm2c turns that into C, which the
 * phone's compiler builds into ordinary arm64 machine code (port/wasm/).
 * Nothing is interpreted: it is the same C code, compiled with 32-bit
 * addresses into one block of memory.
 *
 * This file is the core's side of the boundary: what the frontend
 * (pc_main_sdl.c, linked natively) may call, and the three things the core
 * asks of the frontend (rdc.log, rdc.frame, rdc.jump).
 */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "pc_platform.h"

#define EXPORT(name) __attribute__((export_name(#name)))
#define IMPORT(name) __attribute__((import_module("rdc"), import_name(#name)))

IMPORT(log) void HostLog(const char* text);
IMPORT(frame) void HostFrame(void);
IMPORT(jump) void HostJump(int code); /* leaves the core; does not return */

void PcLog(const char* fmt, ...) {
    char buf[1024];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    HostLog(buf);
}

void PcLongjmpToMain(int code) {
    HostJump(code);
    __builtin_unreachable();
}

void PcRequestSoftReset(void) {
    PcLog("[pc] soft reset at frame %u\n", gPcFrameCount);
    PcLongjmpToMain(1);
}

/* No separate ROM sections in the core: its whole data image is rebuilt by
 * the frontend before the core starts (port/wasm/pc_core_host.c). */
int PcRomDataSection(const char* name, uint8_t** start, size_t* size) {
    (void)name;
    (void)start;
    (void)size;
    return 0;
}

static void FrameHook(void) {
    HostFrame();
}

/* code 0: first start; 1: soft reset; 2: resume (after a crash or a loaded
 * state, PcStateResumeAfterCrash). Never returns: the frontend leaves through
 * rdc.jump or by quitting. */
EXPORT(rdc_enter) void RdcEnter(int code) {
    if (code == 0) {
        gPcFrameHook = FrameHook;
        gPcScanlineHook = PcRenderScanline;
        PC_IO16(PC_REG_KEYINPUT) = 0x03FF;
        PcResetNullPage();
        PcSaveGameState();
        PcStateInit();
    } else if (code == 1) {
        PcRestoreGameState();
    }
    AgbMain();
    PcLog("[pc] AgbMain returned unexpectedly\n");
    HostJump(-1);
}

/* Shared buffer for strings (paths) and sound passed across the boundary. */
static char sScratch[1 << 16] __attribute__((aligned(16)));
EXPORT(rdc_scratch) char* RdcScratch(void) { return sScratch; }
EXPORT(rdc_scratch_size) unsigned RdcScratchSize(void) { return sizeof(sScratch); }

EXPORT(rdc_framebuffer) uint32_t* RdcFramebuffer(void) { return gPcFramebuffer; }
EXPORT(rdc_frame_count) uint32_t* RdcFrameCount(void) { return &gPcFrameCount; }
EXPORT(rdc_io) uint8_t* RdcIo(void) { return gPcIoRegs; }
EXPORT(rdc_skip_movies) int* RdcSkipMovies(void) { return &gPcSkipMovies; }

EXPORT(rdc_apu_reset) void RdcApuReset(void) { PcApuReset(); }
EXPORT(rdc_apu_read) unsigned RdcApuRead(int16_t* out, unsigned maxFrames) { return PcApuReadSamples(out, maxFrames); }

EXPORT(rdc_save_load) int RdcSaveLoad(const char* path) { return PcSaveLoad(path); }
EXPORT(rdc_save_tick) void RdcSaveTick(void) { PcSaveTick(); }
EXPORT(rdc_save_flush) void RdcSaveFlush(void) { PcSaveFlush(); }
EXPORT(rdc_screenshot) int RdcScreenshot(const char* path) { return PcSaveScreenshot(path); }
EXPORT(rdc_null_page) void RdcNullPage(void) { PcResetNullPage(); }

EXPORT(rdc_state_quick_save) void RdcStateQuickSave(const char* path) { PcStateRequestQuickSave(path); }
EXPORT(rdc_state_quick_load) void RdcStateQuickLoad(const char* path) { PcStateRequestQuickLoad(path); }
EXPORT(rdc_state_result) int RdcStateResult(void) { return PcStateTakeQuickResult(); }
int PcTakeRecoveredNotice(void);
EXPORT(rdc_recovered_notice) int RdcRecoveredNotice(void) { return PcTakeRecoveredNotice(); }
EXPORT(rdc_can_resume) int RdcCanResume(void) { return PcStateCanResume(); }
EXPORT(rdc_resume_after_crash) void RdcResumeAfterCrash(void) { PcStateResumeAfterCrash(); }

/* The core's initialised data: the frontend fills it from the player's ROM. */
extern char __global_base[], __data_end[];
EXPORT(rdc_data_start) char* RdcDataStart(void) { return __global_base; }
EXPORT(rdc_data_end) char* RdcDataEnd(void) { return __data_end; }
