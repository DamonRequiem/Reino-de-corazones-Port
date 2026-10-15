#ifndef GUARD_DEBUG_TEXT_H
#define GUARD_DEBUG_TEXT_H

#include "types.h"

typedef struct DebugTextLine {
    u16 glyphs[61];
    u8 x;
    u8 y;
    u8 unk_7C;
    u8 length;
    u32 font;
} DebugTextLine;

typedef struct CharTile {
    u32 rows[8];
} CharTile;

extern u8* gDebugFont2Banks[2];

void DebugTextClearBg();
void func_0805F7B0(s32 a);
void DebugTextClearScreen();
void func_0805F7C8(u8 block);
void DebugTextPrintFont2(u8 x, u8 y, u16* text);
u8 DebugTextGetPixelShift(u8 x);
void DebugTextClearLines();
s32 DebugTextScrollUp(u8 bg, u8 x, u8 y, u8 width, u8 height);
void DebugTextLoadPalette(s32 bg, const void* palette, s32 size, u8 bank);
void DebugTextInit(u8 bg, u16 charSize, u16 screenSize);
void DebugTextSetMergeFirstGlyph(s32 on);
void DebugTextPrintXNumber(u8 x, u8 y, u32 font, u8 value);
void DebugTextPrintNumber(u8 x, u8 y, u32 font, u16 value);
void DebugTextPrint(u8 x, u8 y, u32 font, const char* text);
void DebugTextDrawAligned(u8 bg);
void DebugTextClear();
void DebugTextDraw(u8 bg);
void DebugTextFree();
void DebugTextDestroy();

#endif
