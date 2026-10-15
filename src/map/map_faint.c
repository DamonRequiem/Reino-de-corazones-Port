/**
 * map_faint.c
 * Field Faint Effect
 */

#include "map_tasks.h"
#include "sprites_btl.h"
#include "sprite_palettes.h"
#include "anim.h"
#include "field_state.h"
#include "fld_types.h"
#include "map.h"
#include "obj.h"
#include "obj_api.h"
#include "registration_data.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>

void Task_MapFaint_0(MapFaintWork* work, FldObj* obj) {
    work->obj = obj;
    work->tiles = AllocObjTiles(0x80, gBtlBadstatusStunTiles);
    work->palette = LoadObjPalette(gCommonObjPalette, sizeof(gCommonObjPalette));
    AnimInit(&work->anim, gBtlBadstatusStunAnims, gBtlBadstatusStunFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
}

s32 Task_MapFaint_1(MapFaintWork* work) {
    AnimUpdate(&work->anim);
    return 1;
}

void Task_MapFaint_2(MapFaintWork* work) {
    FldObj* obj = work->obj;
    u16 x;
    u16 y;

    x = (obj->fieldPosition.x >> 8) - (gFieldState->x >> 8);
    y = (obj->fieldPosition.y >> 8) + ((obj->fieldPosition.z - (obj->height + 8) * 0x100) >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, work->palette, NULL, SPRITE_PRIORITY(2), -0x1005 - (obj->fieldPosition.y >> 8) * 4);
}

void Task_MapFaint_3(MapFaintWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescMapFaint = {
    "Task_MapFaint",
    (TaskInitFunc)Task_MapFaint_0,
    (TaskUpdateFunc)Task_MapFaint_1,
    (TaskDrawFunc)Task_MapFaint_2,
    (TaskDestroyFunc)Task_MapFaint_3,
    sizeof(MapFaintWork),
};
