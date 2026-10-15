/*
 * pc_platform.h
 * Internal interface of the PC port's emulated GBA hardware.
 *
 * The game code (src/) talks to the GBA through memory-mapped registers and
 * memory regions. On PC those regions are plain arrays (pc_memory.c), and this
 * header describes the services the rest of the port layer shares.
 */
#ifndef PC_PLATFORM_H
#define PC_PLATFORM_H

#include <stdint.h>
#include <stddef.h>

/* ---- Emulated GBA memory regions (pc_memory.c) ---- */
#define PC_EWRAM_SIZE 0x40000
#define PC_IWRAM_SIZE 0x8000
#define PC_PLTT_SIZE  0x400
#define PC_VRAM_SIZE  0x18000
#define PC_OAM_SIZE   0x400
#define PC_IO_SIZE    0x400
#define PC_SRAM_SIZE  0x8000

extern uint8_t gPcEwram[PC_EWRAM_SIZE];
extern uint8_t gPcIwram[PC_IWRAM_SIZE];
extern uint8_t gPcPltt[PC_PLTT_SIZE];
extern uint8_t gPcVram[PC_VRAM_SIZE];
extern uint8_t gPcOam[PC_OAM_SIZE];
extern uint8_t gPcIoRegs[PC_IO_SIZE];
extern uint8_t gPcSram[PC_SRAM_SIZE];
extern uint8_t gPcNullPage[0x2000];
void PcResetNullPage(void);

/* 16/32-bit register access helpers (registers are little-endian, like x86). */
#define PC_IO16(off) (*(volatile uint16_t*)(gPcIoRegs + (off)))
#define PC_IO32(off) (*(volatile uint32_t*)(gPcIoRegs + (off)))

/* Register offsets used by the port layer. */
#define PC_REG_DISPCNT  0x000
#define PC_REG_DISPSTAT 0x004
#define PC_REG_VCOUNT   0x006
#define PC_REG_BG0CNT   0x008
#define PC_REG_DMA0SAD  0x0B0
#define PC_REG_KEYINPUT 0x130
#define PC_REG_IE       0x200
#define PC_REG_IF       0x202
#define PC_REG_IME      0x208

/* ---- Interrupts (pc_intr.c) ---- */
enum {
    PC_IRQ_VBLANK = 1 << 0,
    PC_IRQ_HBLANK = 1 << 1,
    PC_IRQ_VCOUNT = 1 << 2,
};
void PcRaiseIrq(uint16_t flag);
void PcDispatchPendingIrqs(void);
void PcClearPendingIrqs(void);

/* ---- DMA controller (pc_dma.c) ---- */
enum {
    PC_DMA_TIMING_IMMEDIATE = 0,
    PC_DMA_TIMING_VBLANK = 1,
    PC_DMA_TIMING_HBLANK = 2,
    PC_DMA_TIMING_SPECIAL = 3,
};
void PcDmaReset(void);
void PcDmaRunTiming(int timing);

/* ---- Frame scheduler (pc_frame.c) ---- */
/* Advances the beam to the next VBlank, firing per-line interrupts on the way. */
void PcRunFrame(void);
/* Lets one scanline pass; for code that busy-waits on the display beam. */
void PcYieldScanline(void);
extern uint32_t gPcFrameCount;

/* Called once per visible scanline before its HBlank (the renderer). */
typedef void (*PcScanlineHook)(int line);
extern PcScanlineHook gPcScanlineHook;
/* Called once per frame when line 159 is done, before the VBlank interrupt
 * (present / pacing / input). */
typedef void (*PcFrameHook)(void);
extern PcFrameHook gPcFrameHook;
extern int gPcSkipMovies;

/* ---- Video (pc_render.c, pc_screenshot.c) ---- */
#define PC_SCREEN_W 240
#define PC_SCREEN_H 160
/* Final picture, XRGB8888, written line by line as the beam advances. */
extern uint32_t gPcFramebuffer[PC_SCREEN_W * PC_SCREEN_H];
void PcRenderScanline(int line);
int PcSaveScreenshot(const char* path);

/* ---- Sound hardware (pc_apu.c) ---- */
#define PC_AUDIO_RATE 32768                 /* the GBA's output sample rate */
void PcApuReset(void);
void PcApuStep(uint32_t cycles);            /* advance by CPU cycles */
unsigned PcApuReadSamples(int16_t* out, unsigned maxFrames); /* stereo frames */

/* Sound card output (pc_audio_out.c, windowed builds only). */
int PcAudioOpen(int volumePercent);
void PcAudioUpdate(int mute);
void PcAudioClose(void);

/* Game data from the player's ROM (pc_romdata.c). */
int PcRomDataNeeded(void);
int PcRomDataSection(const char* name, uint8_t** start, size_t* size);
const char* PcRomDataLoad(const char* romPath, const char* mapPath);
void PcAudioSetSpeed(double speed);
void PcAudioPause(int paused);
void PcAudioSetVolume(int volumePercent);
void* PcApuState(size_t* size);             /* for snapshots */

/* ---- CPU compatibility (pc_divzero.c) ---- */
/* Makes integer division by zero return 0, like the GBA's libgcc. */
void PcInstallDivZeroHandler(void);

/* ---- Fault recovery (pc_fault.c) ---- */
/* Turns accesses through NULL/BIOS-latch pointers into GBA behaviour. */
void PcInstallFaultRecovery(void);
unsigned long PcFaultRecoveries(void);

/* ---- Save file (pc_save.c) ---- */
int PcSaveLoad(const char* path);  /* call before AgbMain; 0 if no file yet */
void PcSaveMarkDirty(void);        /* the game wrote to SRAM */
void PcSaveTick(void);             /* once per frame: writes when idle */
void PcSaveFlush(void);            /* write now (on exit) */

/* ---- Soft reset (pc_softreset.c) ---- */
/* Snapshot of the game's globals at boot, restored before AgbMain restarts. */
void PcSaveGameState(void);
void PcRestoreGameState(void);

/* ---- Snapshots (pc_state.c) ---- */
extern int gPcMainLoopWait;            /* set by AgbMain around its VBlankIntrWait */
void PcStateInit(void);                /* after PcSaveGameState */
void PcStateMainLoopPoint(void);
int PcStateCanResume(void);
void PcStateResumeAfterCrash(void);    /* does not return */
void PcStateRequestQuickSave(const char* path);
void PcStateRequestQuickLoad(const char* path);
int PcStateTakeQuickResult(void);

/* ---- Lifecycle (pc_main_*.c) ---- */
/* Jumps back into main() and restarts AgbMain: 1 = soft reset, 2 = resume. */
void PcLongjmpToMain(int code);
void PcRequestSoftReset(void);
void PcLog(const char* fmt, ...);

/* Entry point of the game (src/main.c). */
void AgbMain(void);

#ifdef PC_SPLIT_CORE
/* The frontend of the 64-bit phone build: the game itself runs in the 32-bit
 * core (port/pc_core.c), and these reach into its memory
 * (port/wasm/pc_core_host.c). */
uint32_t* RdcHostFrameCount(void);
uint32_t* RdcHostFramebuffer(void);
uint8_t* RdcHostIo(void);
int* RdcHostSkipMovies(void);
const char* RdcHostLoad(const char* romPath, const char* mapPath);
void RdcHostRun(void (*frameHook)(void));
#undef PC_IO16
#undef PC_IO32
#define PC_IO16(off) (*(volatile uint16_t*)(RdcHostIo() + (off)))
#define PC_IO32(off) (*(volatile uint32_t*)(RdcHostIo() + (off)))
#define gPcFrameCount (*RdcHostFrameCount())
#define gPcFramebuffer (RdcHostFramebuffer())
#define gPcSkipMovies (*RdcHostSkipMovies())
#endif

#endif /* PC_PLATFORM_H */
