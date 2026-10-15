#ifndef GUARD_POO_DATA_H
#define GUARD_POO_DATA_H

#include "types.h"

typedef struct PooPoint {
    s32 x;
    s32 y;
} PooPoint;

typedef struct PooSpot {
    s32 x;
    s32 y;
    s32 z;
} PooSpot;

typedef struct PooMapBgDesc {
    void* tiles;
    u16 tilesSize;
    void* palette;
    u16 paletteSize;
    void* tiles2;
    u16 tilesSize2;
    u8 mapWidth;
    u8 mapHeight;
} PooMapBgDesc;

extern const PooMapBgDesc gPooMapBgDesc;
extern const PooSpot gPooCabbageStackOffsets[];

#endif
