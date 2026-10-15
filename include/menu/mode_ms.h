#ifndef GUARD_MODE_MS_H
#define GUARD_MODE_MS_H

#include "types.h"
#include "fld_types.h"
#include "anim.h"

typedef struct MooglePackCardDef {
    u16 cardId;
    s32 unlockFlag;
    u16 weights[4];
} MooglePackCardDef;

typedef struct MooglePackCardTable {
    const MooglePackCardDef* cards;
    s16 count;
} MooglePackCardTable;

typedef struct MooglePackSpriteDef {
    void* palette;
    u16 paletteSize;
    void* tiles;
    u16 tilesSize;
    void* sprite;
    u16 xOffset;
    u16 yOffset;
} MooglePackSpriteDef;

typedef struct MooglePackTilemapDef {
#ifdef VERSION_EU
    u16** tilemap;
#else
    u16* tilemap;
#endif
    s16 srcX;
    s16 srcY;
} MooglePackTilemapDef;

#define MOOGLE_PACK_ENTRY_NONE (-1)
#define MOOGLE_PACK_ENTRY_ROW_LIST 5

typedef struct MooglePackMenuEntry {
    s16 upEntry;
    s16 downEntry;
    s16 leftEntry;
    s16 rightEntry;
    s16 cursorX;
    s16 cursorY;
    void* selectionTilemap;
    u16 selectionTilemapSize;
    s16 tilemapX;
    s16 tilemapY;
    u16 spriteX;
    u16 spriteY;
    MooglePackTilemapDef packTilemaps[4];
} MooglePackMenuEntry;

typedef struct MooglePackCardWork {
    FldRes* palette;
    void* tiles;
    void* gfx;
    FldRes* palette2;
    void* tiles2;
    void* backSprite;
    AnimState anim;
    u16 flipAngle;
    s32 scale;
    u16 state;
    s32 x;
    s32 y;
    u16 timer;
    u8 premium;
    u8 revealed;
} MooglePackCardWork;

void ClearMooglePackBought(u16 room, u16 category, u16 pack);
u8 IsMooglePackBought(u16 room, u16 category, u16 pack);
void SetMoogleFreePackFlag(u16 room);
void ClearMoogleFreePackFlag(u16 room);
u8 GetMoogleFreePackFlag(u16 room);
void ClearMoogleRoomFlags();
u8 BuildMooglePackList(s16 floor);
s32 MoogleShopReadMenuKeys();
u16 RollMoogleCardValue();
void DrawMoogleShopPacks(s16 row);
void DrawMoogleShopCategoryLabels(s16 row);
void ReleaseMooglePackOpening();
void mode_ms_shop_1();
void MoogleShopDraw();
void mode_ms_shop_0();
void MoogleShopHandlePackInput();
void mode_ms_shop_2();
void LoadMooglePackSelectionTilemap(s16 pack);
void MoogleShopHandleSoldOutInput();
void MoogleShopHandleRowInput();

void SetMooglePackBought(u16 room, u16 category, u16 pack);
u8 UpdateMooglePackOpening(u16 freePack);
void InitMooglePackOpening(s16 x, s16 y);
void RollMooglePackCards(s16 category, s16 tier);
void MoogleShopCopyTilemapRect(u16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy);

#endif /* GUARD_MODE_MS_H */
