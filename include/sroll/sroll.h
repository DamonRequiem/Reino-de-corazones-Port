#ifndef GUARD_SROLL_H
#define GUARD_SROLL_H

#include "evt_object_types.h"
#include "obj.h"
#include "anim.h"
#include "types.h"
#include "taskpool.h"

struct EvtObjParam;

typedef struct DmaStream {
    u8 enabled;
    u8 swapPending;
    void (*update)();
    vu16* dst;
    s32 srcIdx;
    u8* src[2];
    u8* dmaSrc;
    u32 cnt;
} DmaStream;

typedef struct SrollShift {
    u32 shift;
    u32 spillShift;
} SrollShift;

typedef struct SrollMask {
    u32 keepLeft;
    u32 keepNext;
    u32 keepRight;
} SrollMask;

typedef struct SrollBlit {
    s32 x;
    s32 width;
    u8* src;
    u32* dst;
    u32* colors;
    u32 buf[32];
} SrollBlit;

typedef void (*SrollBlitFunc)(u32* dst, u8* src, u32* pal, s32 x);

typedef struct SrollANameWork {
    u16 unk_00;
    s16 kind;
    s16 timer;
    s32 x;
    s32 y;
    s32 targetX;
    s32 targetY;
    void* tiles;
    ObjPalette* palette;
    AnimState anim;
} SrollANameWork;

typedef struct SrollANameArg {
    s16 kind;
    u16 animId;
    u16 nameIndex;
    s32 x;
    s32 y;
    s32 targetX;
    s32 targetY;
} SrollANameArg;

typedef struct SrollBCharWork {
    s32 motion;
    s32 motionTimer;
    EvtObj* obj;
    void* tiles;
    ObjPalette* palette;
    AnimState anim;
    TaskPool tasks;
} SrollBCharWork;

typedef struct SrollBLogoWork {
    s32 x;
    s32 y;
    s32* scrollY;
    s32 scrollSpeed;
    void* tiles;
    ObjPalette* palette;
    AnimState anim;
} SrollBLogoWork;

typedef struct SrollBLogoArg {
    s32 x;
    s32 y;
    s32* scrollY;
    s32 scrollSpeed;
    u16 animId;
} SrollBLogoArg;

typedef struct SrollBSecnWork {
    s32 timer;
    s32 x;
    s32 y;
    s32* scrollY;
    s32 scrollSpeed;
    void* tiles;
    ObjPalette* palette;
    AnimState anim;
    AnimState anim2;
} SrollBSecnWork;

typedef struct SrollBSecnArg {
    s32 index;
    s32 x;
    s32 y;
    s32* scrollY;
    s32 scrollSpeed;
} SrollBSecnArg;

typedef struct SrollBCrtnWork {
    s32 timer;
    u16 kind;
    s32 x;
    s32 y;
    void* tiles;
    ObjPalette* palette;
    AnimState anim;
} SrollBCrtnWork;

typedef struct SrollCCharWork {
    s32 unk_00;
    u8 unk_04[0x14];
    void* tiles;
    ObjPalette* palette;
    AnimState anim[5];
} SrollCCharWork;

typedef struct SrollBCrtnArg {
    u16 kind;
    s32 x;
    s32 y;
} SrollBCrtnArg;

typedef struct SrollTmrWork {
    u8 visible;
    s32 frameCount;
    void* tiles;
    ObjPalette* palette;
} SrollTmrWork;

typedef struct SrollInit {
    u32 unk_00;
    u32 font;
    u16 clearTile;
    u16 frameTileBase;
    u16 textTileBase;
    u8* unk_10;
    u8* tilemapBuffer;
    u8* tileData;
    u8* tilemap;
    u16 fgColor;
    u16 shadowColor;
    u16 bgColor;
    u16 edgeColor;
    u32 frameStyle;
    u16 windowX;
    u16 windowY;
    u16 windowWidth;
    u16 windowHeight;
    u16 textX;
    u16 textY;
    u16 textWidth;
    u16 textHeight;
} SrollInit;

typedef struct SrollFont {
    u16 bpp;
    u16 height;
    u8* pages;
    u8* glyphs;
    u8* widths;
    u32 glyphCount;
    u8 unk_14;
} SrollFont;

enum SrollFlag {
    SROLL_FLAG_TILEMAP_DIRTY = 0x1
};

typedef struct SrollWork {
    u16 flags;
    u16 fgColor;
    u16 shadowColor;
    u16 bgColor;
    u16 edgeColor;
    u16 mapWidth;
    u32 frameStyle;
    u16 windowX;
    u16 windowY;
    u16 windowWidth;
    u16 windowHeight;
    u16 textX;
    u16 textY;
    u16 textWidth;
    u16 textHeight;
    u16 x;
    u16 y;
    u16 glyphHeight;
    u16 glyphBpp;
    u16 writeIdx;
    u16 readIdx;
    u16 clearTile;
    u16 frameTileBase;
    u16 textTileBase;
    u8* fontPages;
    u8* fontGlyphs;
    u8* fontWidths;
    u32 fontGlyphCount;
    u8 unk_44;
    u8* unk_48;
    u8* tilemapBuffer;
    u8* tileData;
    u8* tilemap;
    u16 charQueue[0x100];
} SrollWork;

typedef struct StaffRollTileBlock {
    void* tiles;
    u32 size;
} StaffRollTileBlock;

typedef struct SrollSecnSprite {
    void* tiles;
    u32 tileSize;
    void* anims;
    void* gfxTable;
} SrollSecnSprite;

extern const SrollSecnSprite gSrollSecnSprites[];
extern const s32 gSrollBCharSwayOffsets[16];
extern const s32 gSrollBCharHopOffsets[16];

void task_sroll_a_name_0(SrollANameWork* work, SrollANameArg* arg);
void task_sroll_a_name_2(SrollANameWork* work);
void task_sroll_a_name_3(SrollANameWork* work);
void task_sroll_b_char_3(SrollBCharWork* work);
void task_sroll_b_crtn_3(SrollBCrtnWork* work);
void task_sroll_c_char_3(SrollCCharWork* work);
u8 task_sroll_a_name_1(SrollANameWork* work);
void task_sroll_b_crtn_0(SrollBCrtnWork* work, SrollBCrtnArg* arg);
u8 task_sroll_b_crtn_1(SrollBCrtnWork* work);
void task_sroll_b_crtn_2(SrollBCrtnWork* work);
void task_sroll_b_logo_3(SrollBLogoWork* work);
void task_sroll_b_char_0(SrollBCharWork* work, struct EvtObjParam* arg);
s32 task_sroll_b_char_1(SrollBCharWork* work);
void task_sroll_b_char_2(SrollBCharWork* work);
void task_sroll_b_logo_0(SrollBLogoWork* work, SrollBLogoArg* arg);
void SrollBCharChangeAnim(SrollBCharWork* work);
void task_sroll_c_char_0(SrollCCharWork* work, s32 kind);
void SrollTextClearWindowImmediate(SrollWork* work);
void SrollTextClearWindow(SrollWork* work, u8 flush);
void SrollTextResetWindow(SrollWork* work, u8 flush);
u8* SrollTextEnqueueString(SrollWork* work, u8* str);
u8 SrollTextProcessNextChar(SrollWork* work);
void SrollTextDrawQueued(SrollWork* work, u8 flush);
void SrollTextFlushTilemap(SrollWork* work);
void SrollTextDrawString(SrollWork* work, u8* str, u8 flush);
void SrollTextDrawStringAtTile(SrollWork* work, u16 x, u16 y, u8* str, u8 flush);
u8* SrollTextGetTilemap(SrollWork* work);
u8 task_sroll_b_logo_1(SrollBLogoWork* work);
void task_sroll_b_logo_2(SrollBLogoWork* work);
void task_sroll_b_secn_0(SrollBSecnWork* work, SrollBSecnArg* arg);
u8 task_sroll_b_secn_1(SrollBSecnWork* work);
void task_sroll_b_secn_2(SrollBSecnWork* work);
void task_sroll_b_secn_3(SrollBSecnWork* work);
u8 task_sroll_c_char_1(SrollCCharWork* work);
void task_sroll_c_char_2(SrollCCharWork* work);
void task_sroll_tmr_0(SrollTmrWork* work, void* arg);
u8 task_sroll_tmr_1(SrollTmrWork* work);
void VBlankIntrBlockAudio();
void SrollBlit1bppWidth1(u32* dst, u8* src, u32* pal, s32 x);
void SrollBlit1bppWidth2(u32* dst, u8* src, u32* pal, s32 x);
void SrollBlit1bppWidth3(u32* dst, u8* src, u32* pal, s32 x);
void SrollBlit1bppWidth4(u32* dst, u8* src, u32* pal, s32 x);
void SrollBlit1bppWidth5(u32* dst, u8* src, u32* pal, s32 x);
void SrollBlit1bppWidth6(u32* dst, u8* src, u32* pal, s32 x);
void SrollBlit1bppWidth7(u32* dst, u8* src, u32* pal, s32 x);
void SrollBlit2bppWidth1(u32* dst, u16* src, u32* pal, s32 x);
void SrollBlit2bppWidth2(u32* dst, u16* src, u32* pal, s32 x);
void SrollBlit2bppWidth3(u32* dst, u16* src, u32* pal, s32 x);
u32 SrollTextBlit1bpp(SrollBlit* blit);
u32 SrollTextBlit2bpp(SrollBlit* blit);
void task_sroll_tmr_2(SrollTmrWork* work);
void task_sroll_tmr_3(SrollTmrWork* work);
u16 ParseLowercaseHexDigit(u16 ch);
void SrollTextDrawNextGlyph(SrollWork* work, u8 flush);
void SrollTextClearTextArea(SrollWork* work);
u32 SrollTextBlitGlyph(SrollWork* work, u32* dst, u8* src, s32 width);
void SrollTextDrawFrame(SrollWork* work);
void SrollTextDrawFrameTailLeft(SrollWork* work);
void SrollTextDrawFrameTailRight(SrollWork* work);
u16 SrollTextGetGlyphIndex(u16 ch, u8* font);
u8 SrollTextGetGlyphWidth(u16 ch, u8* font, u8* widths, u32 count);
u8* SrollTextGetGlyphAddress(u16 ch, u8* font, u8* base, u16 bpp, u16 height);
void SrollTextClearQueue(SrollWork* work);
u8 SrollTextQueueIsEmpty(SrollWork* work);
void SrollTextEnqueueChar(SrollWork* work, u16 ch);
u16 SrollTextDequeueChar(SrollWork* work);
void SrollTextSetCursorTile(SrollWork* work, u16 x, u16 y);
void SrollTextSetCursorPixelX(SrollWork* work, u16 x);
u16 SrollTextMapSingleByteChar(u8 ch);
void ScanlineDmaUpdate();
void ScanlineDmaPrime32Bit();
void ScanlineDmaPrime16Bit();
void BlockAudioVBlank();
u16 GetBlockAudioSampleRate();
u32* GetBlockAudioData();
u8* ReadNextAudioBlock(u32** next);
s32 AudioBlockStreamInit(u32* src);
s32 AudioBlockStreamUpdate();

#endif /* GUARD_SROLL_H */
