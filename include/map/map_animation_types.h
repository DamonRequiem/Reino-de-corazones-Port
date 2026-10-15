#ifndef GUARD_MAP_ANIMATION_TYPES_H
#define GUARD_MAP_ANIMATION_TYPES_H

#include "types.h"

typedef struct MapTileAnimationFrame {
    u16 tileOffset;
    u8 duration;
} MapTileAnimationFrame;

typedef struct MapTileAnimationTrack {
    const MapTileAnimationFrame* frames;
    u8* tiles;
    u8 frameCount;
    s16 destOffset;
    u16 copySize;
} MapTileAnimationTrack;

typedef struct MapTileAnimationDef {
    const MapTileAnimationTrack* tracks;
    u8 trackCount;
    u8 unk_05;
} MapTileAnimationDef;

#endif
