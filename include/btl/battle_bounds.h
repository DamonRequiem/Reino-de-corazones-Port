#ifndef GUARD_BATTLE_BOUNDS_H
#define GUARD_BATTLE_BOUNDS_H

#include "types.h"

typedef u8 (*BtlBoundsCallback)(s32* x, s32* y, s32* z, s32* floor);

u8 ClampBosBoogieBounds(s32* x, s32* y, s32* z, s32* floor);
u8 ClampBosJfBounds(s32* px, s32* py, s32* pz, s32* out);

#endif
