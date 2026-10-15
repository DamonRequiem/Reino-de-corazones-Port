#ifndef GUARD_MODE_ALLMAP_API_H
#define GUARD_MODE_ALLMAP_API_H

#include "types.h"

struct AllmapRoomWork;

enum AllmapModeState {
    ALLMAP_MODE_STATE_FADE,
    ALLMAP_MODE_STATE_BAR_SLIDE,
    ALLMAP_MODE_STATE_INTRO,
    ALLMAP_MODE_STATE_ACTIVE
};

void SetAllmapReturnToMenu(u8 returnToMenu);
u8 AllmapDoorExists(u8 room, u8 side);
u8 AllmapDoorIsOpen(u8 room, u8 side);
s32 SetupAllmapRoomDoors(struct AllmapRoomWork* work);

extern u16* gAllmapBg0MapBlocks[8];
extern u32 gAllmapModeState;
extern u16* gAllmapBg1Map;
extern u16 gAllmapCursorDropTimer;
extern u16* gAllmapBg1MapBlocks[8];
extern u16* gAllmapBg0Map;
extern u16 gAllmapScrollInTimer;

#endif
