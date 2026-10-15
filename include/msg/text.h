#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H

#include "text_types.h"
#include "types.h"

void InitTextSlots(TextSlot* slots, s32 count);
void FreeTextSlots(TextSlot* slots, s32 count);
s16 GetTextSlotsWidth(TextSlot* slots, u8 count);
s32 GetTextLength(const void* text);
u16 LoadTextSlots(const void* text, TextSlot* slots);
void* LoadTextPalette(s32 palette);
void DrawTextSlots(s16 x, s16 y, TextSlot* slots, void* palette, u16 priority, u8 count);
void DrawTextSlotsUnsorted(s16 x, s16 y, TextSlot* slots, void* palette, s32 priority, u8 count);
void* LoadSmallFontTiles();
void* LoadSmallFontPalette();

#endif
