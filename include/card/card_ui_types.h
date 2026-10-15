#ifndef GUARD_CARD_UI_TYPES_H
#define GUARD_CARD_UI_TYPES_H

#include "types.h"
#include "anim.h"
#include "macros.h"

struct ObjTiles;
struct ObjPalette;

typedef struct CardUiSpriteState {
    struct ObjTiles* tiles;
    struct ObjPalette* palette;
    AnimState anim;
    void* gfx;
} CardUiSpriteState;

typedef struct MapCardUiResources {
    struct ObjTiles* tiles;
    struct ObjTiles* extraTiles;
    u8 unk_08[4];
    struct ObjPalette* palette;
    void* gfx;
    void** sprites;
    AnimState anim;
} MapCardUiResources;

STATIC_ASSERT(sizeof(CardUiSpriteState) == 0x24, CardUiSpriteStateSize);
STATIC_ASSERT(sizeof(MapCardUiResources) == 0x30, MapCardUiResourcesSize);

typedef struct LayeredCardSprite {
    struct ObjTiles* tiles;
    struct ObjTiles* tiles2;
    struct ObjTiles* tiles3;
    struct ObjPalette* palette;
    struct ObjPalette* palette2;
    struct ObjPalette* palette3;
    void* gfx;
    void* gfx2;
    void* gfx3;
    s32 x;
    s32 y;
} LayeredCardSprite;

typedef struct EventKeyCard {
    LayeredCardSprite sprite;
    u16 unk_2C;
    u16 total;
    u16 drawnTotal;
    u8 color;
} EventKeyCard;

STATIC_ASSERT(sizeof(EventKeyCard) == 0x34, EventKeyCardSize);

typedef struct SpriteFrameResourceDef {
#ifdef VERSION_EU
    void** tiles;
    void*** sprites;
#else
    void* tiles;
    void** sprites;
#endif
    u16 tilesSize;
    u16 spriteIndex;
} SpriteFrameResourceDef;

enum MapCardColor {
    MAP_CARD_COLOR_NONE,
    MAP_CARD_COLOR_GREEN,
    MAP_CARD_COLOR_RED,
    MAP_CARD_COLOR_BLUE,
    MAP_CARD_COLOR_GOLD
};

typedef struct MapCardDef {
    void* tiles;
    void* palette;
    void** sprites;
    void* tiles2;
    void* palette2;
    void** sprites2;
    u16 tilesSize;
    u16 paletteSize;
    u16 tilesSize2;
    u8 backIndex;
    u16 kind;
    u16 value;
    u16 color;
} MapCardDef;

typedef struct MapCardBackDef {
    void* tiles;
    void* palette;
    void** sprites;
    void* tiles2;
    void** sprites2;
    u16 tilesSize;
    u16 paletteSize;
    u16 tilesSize2;
} MapCardBackDef;

#endif
