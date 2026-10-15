#ifndef GUARD_ALLMAP_TYPES_H
#define GUARD_ALLMAP_TYPES_H

#include "types.h"
#include "anim.h"

typedef struct AllmapRoomWork {
    void* tiles;
    void* palette;
    void* gfx2;
    void* tiles2[4];
    void* gfx[4];
    AnimState anim[4];
    s16 x;
    s16 y;
    s32 dropY;
    s32 dropTargetY;
    u8 room;
    u16 shape;
    u16 asSprite;
} AllmapRoomWork;

#endif
