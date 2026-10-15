/**
 * map_floor.c
 * Floor Name Display
 */

#include "monsgage.h"
#include "map_tasks.h"
#include "sprites_map.h"
#include "sprites_map_tasks.h"
#include "sprite_palettes.h"
#include "common_text.h"
#include "field_state.h"
#include "game_state.h"
#include "map.h"
#include "map_text_data.h"
#include "obj_api.h"
#include "registration_data.h"
#include "taskpool.h"
#include "text.h"
#include "types.h"
#include <stddef.h>
#include "text_types.h"
#include "gba/defines.h"
#include "macros.h"

extern const MapNameText* gFloorNames[13];
extern const MapNameText* gBasementFloorNames[12];

const void* GetFloorName() {
#ifdef VERSION_EU
    if (gGameState.flags & GAME_FLAG_RIKU) {
        return GetLocalizedString(gBasementFloorNames[gGameState.floor]);
    }

    return GetLocalizedString(gFloorNames[gGameState.floor]);
#else
    if (gGameState.flags & GAME_FLAG_RIKU) {
        return gBasementFloorNames[gGameState.floor];
    }

    return gFloorNames[gGameState.floor];
#endif
}

void Task_MapFloor_0(MapFloorWork* work) {
    gFieldState->flags |= FIELD_FLAG_FREEZE_PLAYER;
    gFieldState->flags |= FIELD_FLAG_FREEZE_ENEMIES;
    work->tiles = LoadObjTiles(gMapNameBarTiles, sizeof(gMapNameBarTiles));
    work->palette = LoadObjPalette(gMapFloorNamePalette, sizeof(gMapFloorNamePalette));
    work->gfx = gMapNameBarFrames[0];
    work->timer = 120;
    InitTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    work->palette2 = LoadTextPalette(1);
    work->textSlotCount = LoadTextSlots(GetFloorName(), work->textSlots);
    work->textX = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots, work->textSlotCount)) / 2;
}

s32 Task_MapFloor_1(MapFloorWork* work) {
    u16* timer = &work->timer;

    if (*timer != 0) {
        (*timer)--;
        return 1;
    }

    return 0;
}

void Task_MapFloor_2(MapFloorWork* work) {
    DrawSprite(120, 138, work->gfx, work->tiles, work->palette, NULL, 0, 0x3C);
    DrawTextSlots(work->textX, 0x85, work->textSlots, work->palette2, 50, work->textSlotCount);
}

void Task_MapFloor_3(MapFloorWork* work) {
    ReleaseObjPalette(work->palette);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette2);
    FreeTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    gFieldState->flags &= ~FIELD_FLAG_FREEZE_ENEMIES;
    gFieldState->flags &= ~FIELD_FLAG_FREEZE_PLAYER;
}

const MapNameText* gFloorNames[13] = {
    LOCALIZED(gFloorName1),
    LOCALIZED(gFloorName2),
    LOCALIZED(gFloorName3),
    LOCALIZED(gFloorName4),
    LOCALIZED(gFloorName5),
    LOCALIZED(gFloorName6),
    LOCALIZED(gFloorName7),
    LOCALIZED(gFloorName8),
    LOCALIZED(gFloorName9),
    LOCALIZED(gFloorName10),
    LOCALIZED(gFloorName11),
    LOCALIZED(gFloorName12),
    LOCALIZED(gFloorName13),
};

const MapNameText* gBasementFloorNames[12] = {
    LOCALIZED(gBasementFloorName12),
    LOCALIZED(gBasementFloorName11),
    LOCALIZED(gBasementFloorName10),
    LOCALIZED(gBasementFloorName9),
    LOCALIZED(gBasementFloorName8),
    LOCALIZED(gBasementFloorName7),
    LOCALIZED(gBasementFloorName6),
    LOCALIZED(gBasementFloorName5),
    LOCALIZED(gBasementFloorName4),
    LOCALIZED(gBasementFloorName3),
    LOCALIZED(gBasementFloorName2),
    LOCALIZED(gBasementFloorName1),
};

TaskDesc gTaskDescMapFloor = {
    "Task_MapFloor",
    (TaskInitFunc)Task_MapFloor_0,
    (TaskUpdateFunc)Task_MapFloor_1,
    (TaskDrawFunc)Task_MapFloor_2,
    (TaskDestroyFunc)Task_MapFloor_3,
    sizeof(MapFloorWork),
};
