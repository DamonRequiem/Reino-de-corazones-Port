#ifndef GUARD_GBA_SYSCALL_H
#define GUARD_GBA_SYSCALL_H

#include "types.h"

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_32BIT     0x04000000

#define CPU_FAST_SET_SRC_FIXED 0x01000000

#define RESET_EWRAM      0x01
#define RESET_IWRAM      0x02
#define RESET_PALETTE    0x04
#define RESET_VRAM       0x08
#define RESET_OAM        0x10
#define RESET_SIO_REGS   0x20
#define RESET_SOUND_REGS 0x40
#define RESET_REGS       0x80
#define RESET_ALL        0xFF

typedef struct BgAffineSrcData {
    s32 texX;
    s32 texY;
    s16 scrX;
    s16 scrY;
    s16 sx;
    s16 sy;
    u16 alpha;
} BgAffineSrcData;

typedef struct BgAffineDstData {
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
    s32 dx;
    s32 dy;
} BgAffineDstData;

void BgAffineSet(BgAffineSrcData* src, BgAffineDstData* dst, s32 count);
void SoftReset(s32 flags);
void CpuSet(const void* src, void* dst, u32 ctrl);
void CpuFastSet(void* src, void* dst, s32 ctrl);
void RegisterRamReset(u32 flags);
void VBlankIntrWait();
u32 Sqrt(u32 value);

#ifdef VERSION_EU
void LZ77UnCompVram(const void* src, void* dst);
void LZ77UnCompWram(void* src, void* dst);
#endif

#endif
