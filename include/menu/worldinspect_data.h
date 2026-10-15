#ifndef GUARD_WORLDINSPECT_DATA_H
#define GUARD_WORLDINSPECT_DATA_H

#include "types.h"

typedef struct WorldinspectNav {
    u16 up;
    u16 down;
    u16 left;
    u16 right;
    s16 x;
    s16 y;
    s16 rect;
    s16 x2;
    s16 y2;
    u8 unk_12[0x02];
} WorldinspectNav;

typedef struct WorldinspectMsg {
    u16 flags;
    u16 world;
    void* palette;
    u16 paletteSize;
    void* tiles;
    u16 tilesSize;
    void* sprite;
    void* palette2;
    u16 paletteSize2;
    void* tiles2;
    u16 tilesSize2;
    void* sprite2;
    const void* text;
    u16 descId;
    u16 descId2;
} WorldinspectMsg;

typedef WorldinspectNav MdWorldNav;
typedef WorldinspectMsg MdMsg;

#endif
