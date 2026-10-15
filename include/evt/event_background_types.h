#ifndef GUARD_EVENT_BACKGROUND_TYPES_H
#define GUARD_EVENT_BACKGROUND_TYPES_H

#include "types.h"

struct EventMapObjectDef;

enum EventBackgroundFlag {
    EVENT_BG_FLAG_POOH_MAP = 0x1,
    EVENT_BG_FLAG_ALPHA_BLEND = 0x2
};

enum EventBgCompression {
    EVENT_BG_COMPRESSION_NONE,
    EVENT_BG_COMPRESSION_TILES,
    EVENT_BG_COMPRESSION_MAPS,
    EVENT_BG_COMPRESSION_TILES_AND_MAPS
};

typedef struct EventBackgroundDef {
    void* tiles;
    void* tiles2;
    void* palette;
    const void** maps;
    const void** maps2;
    const void** maps3;
    u16 tilesSize;
    u16 tilesSize2;
    u16 paletteSize;
    u8 mapWidth;
    u8 mapHeight;
    s32 mapAnim;
    u8 isAffine;
    struct EventMapObjectDef* mapObjects;
    u8 groundType;
    u8 flags;
    u8 compression[2];
} EventBackgroundDef;

#endif
