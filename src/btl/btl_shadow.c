/**
 * btl_shadow.c
 * Battle Actor Shadow
 */

#include "btl2.h"
#include "sprites_btl.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "engine_math.h"

void task_btl_shadow_0(BtlShadowWork* work, BtlObj* actor) {
    work->actor = actor;

    if (actor->flags & BTLOBJ_FLAG_SMALL_SHADOW) {
        work->tiles = LoadObjTiles(gBtlShadowSmallTiles, sizeof(gBtlShadowSmallTiles));
        work->gfx = gBtlShadowSmallFrame0;
    } else if (actor->flags & BTLOBJ_FLAG_LARGE_SHADOW) {
        work->tiles = LoadObjTiles(gBtlShadowLargeTiles, sizeof(gBtlShadowLargeTiles));
        work->gfx = gBtlShadowLargeFrame0;
    } else {
        work->tiles = LoadObjTiles(gBtlShadowTiles, sizeof(gBtlShadowTiles));
        work->gfx = gBtlShadowFrame0;
    }

    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
}

s32 task_btl_shadow_1() {
    return 1;
}

void task_btl_shadow_2(BtlShadowWork* work) {
    BtlObj* actor = work->actor;
    s16 x;
    s16 y;
    u16 flags;
    ObjAffine* affine;

    if (actor->shadowPriority != 0) {
        if (!(actor->flags & 0x0000000402000000)) {
            flags = GetBattleSpritePriorityFlags(actor->y);

            if (actor->z >= 0 && gBtlWork->scale == Q_8_8(1)) {
                affine = NULL;
            } else {
                s32 scale = Q_8_8(1) - (actor->groundZ - actor->z) / 128;
                scale = (gBtlWork->scale * scale) >> 8;

                if (scale <= 127) {
                    scale = Q_8_8(0.5);
                }

                affine = AllocObjAffine(0, scale, scale, scale > Q_8_8(1));
            }

            WorldToScreen(&x, &y, actor->x, actor->y, actor->groundZ);
            DrawSprite(x, y, work->gfx, work->tiles, work->palette, affine, flags, actor->shadowPriority);
        }
    }
}

void task_btl_shadow_3(BtlShadowWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescBtlShadow = {
    "task_btl_shadow",
    (TaskInitFunc)task_btl_shadow_0,
    (TaskUpdateFunc)task_btl_shadow_1,
    (TaskDrawFunc)task_btl_shadow_2,
    (TaskDestroyFunc)task_btl_shadow_3,
    sizeof(BtlShadowWork),
};
