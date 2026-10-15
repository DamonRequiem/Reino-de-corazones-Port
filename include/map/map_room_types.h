#ifndef GUARD_MAP_ROOM_TYPES_H
#define GUARD_MAP_ROOM_TYPES_H

#include "types.h"

#define MAP_FIXED_GMK_END 0xFF

typedef struct MapFixedGmk {
    u8 defIndex;
    s32 x;
    s32 y;
} MapFixedGmk;

typedef struct MapFixedCollider {
    u16 radius;
    s32 x;
    s32 y;
} MapFixedCollider;

typedef struct MapDecorRule {
    const u8* pattern;
    u8 width;
    u8 height;
    u8 chance;
    const u8* pieces;
    u16* tilemap;
} MapDecorRule;

#define MAP_ROOM_EVENT_END 0xFF

typedef struct MapRoomDef {
    void* palette;
    u16 paletteSize;
    void* tiles;
    u16 tilesSize;
    void* tiles2;
    u16 tilesSize2;
    u16* map3;
    u16* map2;
    u16* map;
    MapDecorRule* layer1DecorRules;
    MapDecorRule* layer2DecorRules;
    void* tileAnims;
    s32* soraEvents;
    s32* rikuEvents;
    u16 song;
} MapRoomDef;

typedef struct MapFixedDef {
    void* palette;
    u16 paletteSize;
    void* tiles;
    u16 tilesSize;
    void* tiles2;
    u16 tilesSize2;
    void* map3;
    void* map2;
    void* map;
    u8 mapWidth;
    u8 mapHeight;
    const u8* cellTypes;
    struct MapFixedGmk* gimmicks;
    struct MapFixedCollider* colliders;
    u16 song;
    s32 stairX;
    s32 stairY;
    s32 stair2X;
    s32 stair2Y;
    s32 spawnX;
    s32 spawnY;
#ifdef VERSION_EU
    u8 rawTiles;
#endif
} MapFixedDef;

#endif
