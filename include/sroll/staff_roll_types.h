#ifndef GUARD_STAFF_ROLL_TYPES_H
#define GUARD_STAFF_ROLL_TYPES_H

#include "types.h"

typedef struct StaffRollScene {
    u8 color256;
    u8 fadeInBg;
    u8 fadeOutBg;
    s32 duration;
    s32 x;
    s32 y;
    void* tiles;
    u16 tilesSize;
    void* map;
    u16 mapSize;
    void* palette;
    u16 paletteSize;
    s32 targetX;
    s32 targetY;
    u16 animId;
    u16 nameIndex;
} StaffRollScene;

#endif
