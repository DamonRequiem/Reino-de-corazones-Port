/**
 * fld_shadow.c
 * Field Actor Shadow
 */

#include "task_descriptors.h"
#include "fld.h"
#include "sprites_btl.h"
#include "fld_tasks.h"
#include "anim.h"
#include "field_state.h"
#include "fld_types.h"
#include "obj.h"
#include "obj_api.h"
#include <stddef.h>
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "engine_math.h"

void task_fld_shadow_0(FldShadowWork* work, FldObj* obj) {
    work->actor = obj;
    work->x = obj->fieldPosition.x;
    work->y = obj->fieldPosition.y;
    work->tiles = LoadObjTiles(gBtlShadowTiles, sizeof(gBtlShadowTiles));
    work->palette = LoadObjPalette(gCommonObjPalette, sizeof(gCommonObjPalette));
    AnimInit(&work->anim, gBtlShadowAnims, gBtlShadowFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
}

s32 task_fld_shadow_1(FldShadowWork* work) {
    work->x = work->actor->fieldPosition.x;
    work->y = work->actor->fieldPosition.y;
    return 1;
}

void task_fld_shadow_2(FldShadowWork* work) {
    FldObj* obj;
    void* spr;
    s32 z;
    s32 size;
    ObjAffine* sprite;
    s32 x;
    s32 y;

    obj = work->actor;

    if (obj->shadowPriority == 0) {
        return;
    }

    spr = AnimUpdate(&work->anim);
    z = obj->shadowZ;

    if (obj->fieldPosition.z >= z) {
        sprite = NULL;
    } else {
        size = Q_8_8(1) - (z - obj->fieldPosition.z) / 128;

        if (size <= 0x18) {
            size = Q_8_8(0.1);
        }

        sprite = AllocObjAffine(0, size, size, FALSE);
    }

    x = (work->x >> 8) - (gFieldState->x >> 8);
    y = (work->y >> 8) + (z >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, spr, work->tiles, work->palette, sprite, SPRITE_PRIORITY(2), obj->shadowPriority);
}

void task_fld_shadow_3(FldShadowWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescFldShadow = {
    "task_fld_shadow",
    (TaskInitFunc)task_fld_shadow_0,
    (TaskUpdateFunc)task_fld_shadow_1,
    (TaskDrawFunc)task_fld_shadow_2,
    (TaskDestroyFunc)task_fld_shadow_3,
    sizeof(FldShadowWork),
};
