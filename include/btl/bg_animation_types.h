#ifndef GUARD_BG_ANIMATION_TYPES_H
#define GUARD_BG_ANIMATION_TYPES_H

#include "types.h"
#include "macros.h"

typedef struct BgAnimationChunk {
    void* data;
    u16 size;
} BgAnimationChunk;

typedef struct BgAnimationDef {
    const BgAnimationChunk* chunks;
    void* tilemap;
    void* palette;
    u16 paletteSize;
    u16 tilesPerFrame;
    u16 originX;
    u16 originY;
    u16 frameCount;
    u16 frameDuration;
} BgAnimationDef;

STATIC_ASSERT(sizeof(BgAnimationDef) == 0x18, BgAnimationDefSize);
STATIC_ASSERT(sizeof(BgAnimationChunk) == 0x08, BgAnimationChunkSize);

#endif
