#ifndef GUARD_BATTLE_BG_TYPES_H
#define GUARD_BATTLE_BG_TYPES_H

#include "types.h"

typedef struct BattleBackgroundDef {
    void* tiles;
    u16 tilesSize;
    void* palette;
    u16 paletteSize;
    const void* map[4];
} BattleBackgroundDef;

typedef struct PcBattleBackgroundDef {
    void* tiles;
    u16 tilesSize;
    void* palette;
    u16 paletteSize;
    void* map[6];
} PcBattleBackgroundDef;

#endif
