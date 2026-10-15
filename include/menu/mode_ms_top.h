#ifndef GUARD_MODE_MS_TOP_H
#define GUARD_MODE_MS_TOP_H

#include "types.h"
#include "anim.h"
#include "mode.h"

typedef struct WarpGfx {
    u16 x;
    s16 y;
    void* palette;
    u16 paletteSize;
    void* tiles;
    u16 tilesSize;
    AnimHeader** anims;
    void** gfxTable;
    u16 animId;
} WarpGfx;

typedef struct WarpDef {
    Mode* mode;
    void* map;
    u16 mapSize;
    u16 x;
    s16 y;
    u16 animId;
    u16 x2;
    s16 y2;
    u16 flags;
    u16 x3;
    s16 y3;
    WarpGfx gfx[2];
} WarpDef;

#endif
