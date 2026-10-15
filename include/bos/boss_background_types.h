#ifndef GUARD_BOSS_BACKGROUND_TYPES_H
#define GUARD_BOSS_BACKGROUND_TYPES_H

#include "types.h"

typedef struct BosMapConfig {
    void* tiles;
    u16 tilesSize;
    void* palette;
    u16 paletteSize;
    void* maps[4];
} BosMapConfig;

#endif
