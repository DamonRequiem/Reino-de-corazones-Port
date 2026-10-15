#ifndef GUARD_MODE_ALLMAP_H
#define GUARD_MODE_ALLMAP_H

#include "types.h"
#include "taskpool.h"

typedef struct AllmapRoomOrder {
    s32 shapes[16];
} AllmapRoomOrder;

typedef struct AllmapRoomDirs {
    s32 animIds[4];
} AllmapRoomDirs;

extern TaskPool gAllmapTaskPool;

void AllmapVCountCallback();
void AllmapAllocBgMaps();
void AllmapDimPalette10();
void AllmapSetBlend(s16 alpha);
void AllmapCyclePalette();
void AllmapLoadWorldBg();
void AllmapLoadFloorTiles();
void mode_allmap_0(s32 lowerBgm);
void AllmapFreezePalette10();
void mode_allmap_1();
void mode_allmap_2();
u8 AllmapDoorLeadsToHall(u8 room, u8 side);

#endif /* GUARD_MODE_ALLMAP_H */
