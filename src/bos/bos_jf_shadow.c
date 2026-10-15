/**
 * bos_jf_shadow.c
 * Jafar Boss Shadow
 */

#include "macros.h"
#include "bos_jf_shadow.h"
#include "sprites_btl.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "game.h"
#include "obj.h"
#include "obj_api.h"
#include "save_types.h"
#include <stddef.h>
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "engine_math.h"

u16 gUnk_0203C3BC EWRAM_COMMON(4);
u16 gUnk_0203C3C0 EWRAM_COMMON(4);

void task_bos_jf_shadow_0(JfShadowWork* work, BtlObj* obj) {
    work->actor = obj;
    work->tiles = LoadObjTiles(gBtlShadowLargeTiles, sizeof(gBtlShadowLargeTiles));
    work->gfx = gBtlShadowLargeFrame0;
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
}

s32 task_bos_jf_shadow_1() {
    return 1;
}

void task_bos_jf_shadow_2(JfShadowWork* work) {
    BtlObj* obj;
    s16 x;
    s16 y;
    s32 scale;
    s32 doubleSize;
    u16 flags;
    ObjAffine* affine;

    obj = work->actor;

    if (obj->shadowPriority == 0) {
        return;
    }

    if (obj->flags & 0x402000000) {
        return;
    }

    flags = GetBattleSpritePriorityFlags(obj->y);

    if (obj->z >= 0 && gBtlWork->scale == Q_8_8(1)) {
        affine = NULL;
    } else {
        scale = Q_8_8(2) - ((obj->groundZ - obj->z) / 128);

        if (scale <= 127) {
            scale = Q_8_8(0.5);
        }

        doubleSize = FALSE;

        if (scale > Q_8_8(1)) {
            doubleSize = TRUE;
        }

        affine = AllocObjAffine(0, scale, scale, doubleSize);
    }

    WorldToScreen(&x, &y, obj->x, obj->y, obj->groundZ);
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, affine, flags, obj->shadowPriority);
}

void task_bos_jf_shadow_3(JfShadowWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void ResetSaveSliceE6C() {
    gUnk_0203C3C0 = 0;
    gUnk_0203C3BC = 0;
}

void WriteSaveSliceE6C(SaveSliceE6C* out) {
    out->unk_00 = gUnk_0203C3C0;
    out->unk_02 = gUnk_0203C3BC;
}

void ReadSaveSliceE6C(SaveSliceE6C* in) {
    gUnk_0203C3C0 = in->unk_00;
    gUnk_0203C3BC = in->unk_02;
}

TaskDesc gTaskDescBosJfShadow = {
    "task_bos_jf_shadow",
    (TaskInitFunc)task_bos_jf_shadow_0,
    (TaskUpdateFunc)task_bos_jf_shadow_1,
    (TaskDrawFunc)task_bos_jf_shadow_2,
    (TaskDestroyFunc)task_bos_jf_shadow_3,
    sizeof(JfShadowWork),
};
