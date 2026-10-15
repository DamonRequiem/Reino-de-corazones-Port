/*
 * pc_bios.c
 * C replacements for the GBA BIOS calls in asm/libagbsyscall.s.
 */
#include <math.h>
#include <string.h>
#include "pc_platform.h"

typedef int16_t s16;
typedef int32_t s32;
typedef uint16_t u16;
typedef uint32_t u32;

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_32BIT     0x04000000

/* swi 11 */
void CpuSet(const void* src, void* dst, u32 ctrl) {
    u32 count = ctrl & 0x1FFFFF;
    int fixed = (ctrl & CPU_SET_SRC_FIXED) != 0;
    u32 i;

    if (ctrl & CPU_SET_32BIT) {
        const uint8_t* s = (const uint8_t*)((uintptr_t)src & ~(uintptr_t)3);
        uint8_t* d = (uint8_t*)((uintptr_t)dst & ~(uintptr_t)3);
        u32 v;
        if (fixed) {
            memcpy(&v, s, 4);
            for (i = 0; i < count; i++)
                memcpy(d + i * 4, &v, 4);
        } else {
            memmove(d, s, (size_t)count * 4);
        }
    } else {
        const uint8_t* s = (const uint8_t*)((uintptr_t)src & ~(uintptr_t)1);
        uint8_t* d = (uint8_t*)((uintptr_t)dst & ~(uintptr_t)1);
        u16 v;
        if (fixed) {
            memcpy(&v, s, 2);
            for (i = 0; i < count; i++)
                memcpy(d + i * 2, &v, 2);
        } else {
            memmove(d, s, (size_t)count * 2);
        }
    }
}

/* swi 12: always 32-bit, length rounded up to a multiple of 8 words. */
void CpuFastSet(void* src, void* dst, s32 ctrl) {
    u32 count = ((u32)ctrl & 0x1FFFFF);
    count = (count + 7) & ~7u;
    CpuSet(src, dst, CPU_SET_32BIT | ((u32)ctrl & CPU_SET_SRC_FIXED) | count);
}

/* swi 1 */
void RegisterRamReset(u32 flags) {
    if (flags & 0x01)
        memset(gPcEwram, 0, PC_EWRAM_SIZE);
    if (flags & 0x02)
        memset(gPcIwram, 0, PC_IWRAM_SIZE - 0x200);
    if (flags & 0x04)
        memset(gPcPltt, 0, PC_PLTT_SIZE);
    if (flags & 0x08)
        memset(gPcVram, 0, PC_VRAM_SIZE);
    if (flags & 0x10)
        memset(gPcOam, 0, PC_OAM_SIZE);
    if (flags & 0x20) {
        memset(gPcIoRegs + 0x120, 0, 0x10); /* SIO */
        memset(gPcIoRegs + 0x134, 0, 0x0C);
    }
    if (flags & 0x40) {
        memset(gPcIoRegs + 0x060, 0, 0x50); /* sound */
        PcApuReset();
    }
    if (flags & 0x80) {
        memset(gPcIoRegs, 0, 0x60);         /* display */
        memset(gPcIoRegs + 0x0B0, 0, 0x50); /* DMA + timers */
        memset(gPcIoRegs + 0x200, 0, 0x0C);
        PC_IO16(0x000) = 0x0080;            /* DISPCNT: forced blank */
        PcDmaReset();
    }
    PC_IO16(PC_REG_KEYINPUT) = 0x03FF;     /* no keys pressed */
}

/* swi 0 (after swi 1 in the GBA's SoftReset wrapper) */
void SoftReset(s32 flags) {
    RegisterRamReset((u32)flags);
    PcRequestSoftReset();
}

/* swi 8 */
u32 Sqrt(u32 value) {
    u32 res = 0;
    u32 bit = 1u << 30;

    while (bit > value)
        bit >>= 2;
    while (bit != 0) {
        if (value >= res + bit) {
            value -= res + bit;
            res = (res >> 1) + bit;
        } else {
            res >>= 1;
        }
        bit >>= 2;
    }
    return res;
}

typedef struct {
    s32 texX;
    s32 texY;
    s16 scrX;
    s16 scrY;
    s16 sx;
    s16 sy;
    u16 alpha;
} PcBgAffineSrc;

typedef struct {
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
    s32 dx;
    s32 dy;
} PcBgAffineDst;

/* swi 14. The BIOS uses a 256-entry sine table indexed by alpha >> 8;
 * this follows the same math (as reproduced by accurate HLE emulators). */
void BgAffineSet(PcBgAffineSrc* src, PcBgAffineDst* dst, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        double ox = src[i].texX / 256.0;
        double oy = src[i].texY / 256.0;
        double cx = src[i].scrX;
        double cy = src[i].scrY;
        double sx = src[i].sx / 256.0;
        double sy = src[i].sy / 256.0;
        double theta = (src[i].alpha >> 8) / 128.0 * M_PI;
        double a = cos(theta), b = sin(theta), c = sin(theta), d = cos(theta);
        double rx, ry;

        a *= sx;
        b *= -sx;
        c *= sy;
        d *= sy;
        rx = ox - (a * cx + b * cy);
        ry = oy - (c * cx + d * cy);
        dst[i].pa = (s16)(a * 256);
        dst[i].pb = (s16)(b * 256);
        dst[i].pc = (s16)(c * 256);
        dst[i].pd = (s16)(d * 256);
        dst[i].dx = (s32)(rx * 256);
        dst[i].dy = (s32)(ry * 256);
    }
}

/* swi 17 / 18. VRAM needs 16-bit writes on hardware; on PC bytes are fine. */
static void LZ77UnComp(const void* src, void* dst) {
    const uint8_t* s = (const uint8_t*)src;
    uint8_t* d = (uint8_t*)dst;
    u32 size = (u32)s[1] | ((u32)s[2] << 8) | ((u32)s[3] << 16);
    u32 out = 0;

    s += 4;
    while (out < size) {
        uint8_t flags = *s++;
        int bit;
        for (bit = 0; bit < 8 && out < size; bit++, flags <<= 1) {
            if (flags & 0x80) {
                u32 len = (u32)(s[0] >> 4) + 3;
                u32 disp = (((u32)(s[0] & 0xF) << 8) | s[1]) + 1;
                s += 2;
                while (len-- && out < size) {
                    d[out] = d[out - disp];
                    out++;
                }
            } else {
                d[out++] = *s++;
            }
        }
    }
}

void LZ77UnCompVram(const void* src, void* dst) {
    LZ77UnComp(src, dst);
}

void LZ77UnCompWram(void* src, void* dst) {
    LZ77UnComp(src, dst);
}

/* swi 5: wait for the next VBlank. On PC this runs one whole emulated frame. */
void VBlankIntrWait(void) {
    PcRunFrame();
    /* AgbMain's own wait: the one place where snapshots are consistent. */
    if (gPcMainLoopWait)
        PcStateMainLoopPoint();
}
