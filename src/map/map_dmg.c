/**
 * map_dmg.c
 * Field Attack Area Marker
 */

#include "map_tasks.h"
#include "sprites_btl.h"
#include "sprite_palettes.h"
#include "field_state.h"
#include "map.h"
#include "map_api.h"
#include "map_types.h"
#include "obj.h"
#include "obj_api.h"
#include "registration_data.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>

void Task_MapDmg_0(MapDmgWork* work) {
    s32 zero = 0;

    work->visible = zero;
    work->palette = LoadObjPalette(gCommonObjPalette, sizeof(gCommonObjPalette));
    work->tiles = LoadObjTiles(gBtlAreaTiles, sizeof(gBtlAreaTiles));
    work->timer = zero;
    work->enabled = TRUE;
}

s32 Task_MapDmg_1(MapDmgWork* work) {
    if (!work->enabled) {
        work->visible = 0;
    } else {
        if (gMapRoomState->attackActive || (gMapRoomState->flags & ROOM_FLAG_ENEMY_STRUCK)) {
            work->timer = 20;
        }

        work->visible = work->timer != 0;

        if (work->timer != 0) {
            work->timer -= 1;
        }
    }

    return 1;
}

void Task_MapDmg_2(MapDmgWork* work) {
    s16 x;
    s16 y;

    if (work->visible == 0) {
        return;
    }

    x = ((gMapRoomState->attackX - 0x1400) >> 8) - (gFieldState->x >> 8);
    y = ((gMapRoomState->attackY - 0x1400) >> 8) + (gMapRoomState->attackZ >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, gBtlAreaFrame0, work->tiles, work->palette, NULL, SPRITE_PRIORITY(2), 0x101);

    x = ((gMapRoomState->attackX + 0x1400) >> 8) - (gFieldState->x >> 8);
    y = ((gMapRoomState->attackY - 0x1400) >> 8) + (gMapRoomState->attackZ >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, gBtlAreaFrame1, work->tiles, work->palette, NULL, SPRITE_PRIORITY(2), 0x101);

    x = ((gMapRoomState->attackX - 0x1400) >> 8) - (gFieldState->x >> 8);
    y = ((gMapRoomState->attackY + 0x1400) >> 8) + (gMapRoomState->attackZ >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, gBtlAreaFrame3, work->tiles, work->palette, NULL, SPRITE_PRIORITY(2), 0x101);

    x = ((gMapRoomState->attackX + 0x1400) >> 8) - (gFieldState->x >> 8);
    y = ((gMapRoomState->attackY + 0x1400) >> 8) + (gMapRoomState->attackZ >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, gBtlAreaFrame2, work->tiles, work->palette, NULL, SPRITE_PRIORITY(2), 0x101);

    x = ((gMapRoomState->attackX) >> 8) - (gFieldState->x >> 8);
    y = ((gMapRoomState->attackY) >> 8) + (gMapRoomState->attackZ >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, gBtlAreaFrame5, work->tiles, work->palette, NULL, SPRITE_PRIORITY(2), 0x101);
}

void Task_MapDmg_3(MapDmgWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescMapDmg = {
    "Task_MapDmg",
    (TaskInitFunc)Task_MapDmg_0,
    (TaskUpdateFunc)Task_MapDmg_1,
    (TaskDrawFunc)Task_MapDmg_2,
    (TaskDestroyFunc)Task_MapDmg_3,
    sizeof(MapDmgWork),
};
