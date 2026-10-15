#ifndef GUARD_GBA_DEFINES_H
#define GUARD_GBA_DEFINES_H

#ifdef PLATFORM_PC
/* PC port: the GBA memory map lives in ordinary host arrays (port/pc_memory.c). */
#include <stdint.h>
extern unsigned char gPcEwram[];
extern unsigned char gPcIwram[];
extern unsigned char gPcPltt[];
extern unsigned char gPcVram[];
extern unsigned char gPcOam[];
extern void* gPcIntrVector;
#define INTR_VECTOR gPcIntrVector
#define EWRAM_START ((uintptr_t)gPcEwram)
#define IWRAM_START ((uintptr_t)gPcIwram)
#define PLTT ((uintptr_t)gPcPltt)
#else
#define INTR_VECTOR (*(void**)0x03007FFC)
#define EWRAM_START 0x02000000
#define IWRAM_START 0x03000000
#define PLTT 0x05000000
#endif

#define EWRAM_SIZE 0x40000
#define IWRAM_SIZE 0x8000

#define PLTT_SIZE 0x400
#define BG_PLTT PLTT
#define BG_PLTT_SIZE 0x200
#define OBJ_PLTT (PLTT + 0x200)

#ifdef PLATFORM_PC
#define VRAM ((uintptr_t)gPcVram)
#else
#define VRAM 0x06000000
#endif
#define VRAM_SIZE 0x18000
#define BG_VRAM VRAM
#define BG_CHAR_SIZE 0x4000
#define BG_CHAR_ADDR(n) (BG_VRAM + BG_CHAR_SIZE * (n))
#define OBJ_VRAM0 (VRAM + 0x10000)

#ifdef PLATFORM_PC
#define OAM ((uintptr_t)gPcOam)
#else
#define OAM 0x07000000
#endif

#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 160

#define TILE_SIZE_4BPP 32
#define PLTT_SIZE_4BPP 32

#endif
