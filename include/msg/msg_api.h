#ifndef GUARD_MSG_API_H
#define GUARD_MSG_API_H

#include "types.h"
#include "text_types.h"
#include "msg_types.h"

extern const void* gMsgwinMapBlocks[4];

void RequestEventMode(u16 eventId);
u16 InitMsgGlyphSprites(s32 mode);
u16 InitMsgGlyphSpritesAltPalette5(s32 mode);
u16 InitMsgGlyphSpritesAltPalette3(s32 mode);
#ifndef VERSION_EU
u8 LayoutMsgGlyphsSjis(s32 x, s32 y, const u8* text);
#endif
s32 GetMsgTextWidth(const TextChar* text);
u8 LayoutMsgGlyphs(s32 x, s32 y, const MsgLatinChar* text);
void DrawMsgGlyphs(u8 n);
void FreeMsgGlyphSprites();
#ifdef VERSION_EU
s16 GetTextSlotsMaxLineWidth(TextSlot* slots, u8 n);
#endif
s32 LoadTextTileArray(TextChar* text, void** tiles);
void FreeSmallFontResources(void* tiles, void* palette);
u16 EncodeSmallFontString(const u8* str, u16* out);
u16 FormatSmallFontDecimal(s32 value, u16* out);
u16 FormatSmallFontHex(s32 value, u16* out);
s32 DrawSmallFontString(s16 x, s16 y, u16* str, void* tiles, void* palette, u16 priority, u8 n);
void SplitFourDigits(s16 value, u8* out);
u16 InitCardMsgGlyphSprites(s32 mode, s32 flag);
u8 LayoutCardMsgGlyphsPage(s32 x, s32 y, MsgLatinChar* text, MsgLatinChar** nextText);
#ifndef VERSION_EU
u8 LayoutCardMsgGlyphsPageSjis(s32 x, s32 y, u8* text, u8** nextText);
s32 CopySjisGlyphsToVram(const TextChar* str);
s32 CopySjisGlyphsToVramAt(const TextChar* str, u16 tile);
#endif
u8 CopyLatinGlyphsToVram(const TextChar* str, u16* widths, u16 tile);
void DrawCardMsgGlyphs(u8 n);
void FreeCardMsgGlyphSprites();

extern const u16 gMsgwinClosedScrollX[4];
extern const u16 gMsgwinOpenScrollX[4];
extern const s32 gMsgwinTextX[4];
extern const s32 gMsgwinTextY[4];
extern const s32 gMsgfaceHiddenX[4];
extern const s32 gMsgfaceShownX[4];
extern const s32 gMsgfaceY[4];
extern const s32 gMsgwaitIconPos[4][2];
extern const s32 gMsgwaitYesnoCursorY[2];

#endif
