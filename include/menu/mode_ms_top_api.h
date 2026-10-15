#ifndef GUARD_MODE_MS_TOP_API_H
#define GUARD_MODE_MS_TOP_API_H

#include "types.h"

u32 GetMooglePoints();
void SetMooglePoints(u32 points);
u8 SpendMooglePoints(u32 points);
u8 AddMooglePoints(u32 points);
void LoadDecimalDigitTiles(u32 value, u8* glyphs, u8* dst, u16 stride, u16 count);
void mode_ms_top_0(u32 flags);
void mode_ms_top_1();
void mode_ms_top_2();

#endif
