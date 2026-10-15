/*
 * pc_memory.c
 * Host-side storage for the GBA memory map.
 *
 * On the GBA these regions sit at fixed addresses (EWRAM 0x02000000,
 * IWRAM 0x03000000, palette 0x05000000, VRAM 0x06000000, OAM 0x07000000,
 * IO 0x04000000, SRAM 0x0E000000). The PLATFORM_PC branches in include/gba/
 * point those addresses at the arrays below instead.
 */
#include "pc_platform.h"

/* Alignment matches the strictest GBA access width the game uses (32-bit DMA). */
#define PC_ALIGN __attribute__((aligned(32)))

/* EWRAM/IWRAM scratch: the game's globals are ordinary host variables, so these
 * only receive the boot-time clears (InitSystem fills EWRAM_START/IWRAM_START). */
PC_ALIGN uint8_t gPcEwram[PC_EWRAM_SIZE];
PC_ALIGN uint8_t gPcIwram[PC_IWRAM_SIZE];

PC_ALIGN uint8_t gPcPltt[PC_PLTT_SIZE];
PC_ALIGN uint8_t gPcVram[PC_VRAM_SIZE];
PC_ALIGN uint8_t gPcOam[PC_OAM_SIZE];
PC_ALIGN uint8_t gPcIoRegs[PC_IO_SIZE];
PC_ALIGN uint8_t gPcSram[PC_SRAM_SIZE];

/* Heaps the GBA linker script carves out of EWRAM and IWRAM (include/malloc.h). */
PC_ALIGN uint8_t gEwramHeapStart[0x34000];
PC_ALIGN uint8_t gIwramHeapStart[0x6800];

/* Variables the GBA BIOS keeps at fixed IWRAM addresses (configure.py BIOS_SYMBOLS). */
void* gSoundInfoPtr;    /* 0x03007FF0 */
volatile uint16_t gIntrCheck; /* 0x03007FF8 */

/* Interrupt vector (0x03007FFC) and the ARM IRQ stub the game copies into IWRAM.
 * On PC interrupts are dispatched in C (pc_intr.c), so the stub is never run. */
void* gPcIntrVector;
PC_ALIGN uint8_t IrqHandler[0x800];

/* Stand-in for the GBA BIOS region (address 0) read by original-game NULL
 * pointer bugs. The BIOS returns its last fetched opcode for any such read;
 * after a SWI returns that is 0xE3A02004. Refreshed every frame. */
PC_ALIGN uint8_t gPcNullPage[0x2000]; /* 8 KiB: accesses at offset < 4 KiB never run off its end */

void PcResetNullPage(void) {
    size_t i;
#ifdef __wasm__
    {
        /* The 32-bit core (pc_core.c): NULL really is address 0, and the first
         * 64 KiB of its memory are kept free (--global-base) to stand in for
         * the BIOS, like gPcNullPage does through the fault handler on PC. */
        static volatile uintptr_t zero; /* keeps the compiler from treating this as a NULL write */
        volatile uint32_t* p = (volatile uint32_t*)zero;
        for (i = 0; i < 0x10000 / 4; i++)
            p[i] = 0xE3A02004u;
    }
#endif
    for (i = 0; i < sizeof(gPcNullPage); i += 4) {
        gPcNullPage[i + 0] = 0x04;
        gPcNullPage[i + 1] = 0x20;
        gPcNullPage[i + 2] = 0xA0;
        gPcNullPage[i + 3] = 0xE3;
    }
}
