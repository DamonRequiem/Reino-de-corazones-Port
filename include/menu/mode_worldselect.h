#ifndef GUARD_MODE_WORLDSELECT_H
#define GUARD_MODE_WORLDSELECT_H

#include "types.h"

typedef struct WorldselectWorldDef {
    u16 worldBit;
    s16 world;
    s16 eventId;
    s16 rikuEventId;
    void* palette;
    void* tiles;
    void* gfx;
    void* nameTiles;
#ifdef VERSION_EU
    u16 nameTilesOffset;
#endif
} WorldselectWorldDef;

typedef struct WorldselectSlot {
    s16 listIndex;
    u8 unk_02[0x6];
    u8 angle;
    void* palette;
    void* tiles;
    void* gfx;
} WorldselectSlot;

typedef struct WorldselectTileSizes {
    u16 sizes[5];
} WorldselectTileSizes;

void WorldselectLoadSlotPalette(s16 model, s16 slot);
void WorldselectLoadSlotTiles(s16 model, s16 slot);
s16 WorldselectSetSlotGfx(s16 model, s16 slot);
void WorldselectSetBgMode0();
void mode_worldselect_1();
void WorldselectHandleInput();
void WorldselectDraw();
void mode_worldselect_0();
void WorldselectDrawName(s16 model, s16 width);
void mode_worldselect_2();
void WorldselectSetBgMode1();
void WorldselectCyclePalette();

#endif /* GUARD_MODE_WORLDSELECT_H */
