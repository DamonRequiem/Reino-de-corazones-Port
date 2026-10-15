/**
 * btl_vslockon.c
 * Link Battle Lock-On Cursor
 */

#include "btl4.h"
#include "sprites_btl.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "card_label_data.h"

void task_btl_vslockon_0(BtlVslockonWork* work) {
    work->tiles = LoadObjTiles(gBtlLockonTiles, sizeof(gBtlLockonTiles));
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
    AnimInit(&work->anim, gBtlLockonAnims, gBtlLockonFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
    work->gfx = AnimGetGfx(&work->anim);
    gBtlWork->actor2 = gRikuBtlWork->actor;
    gRikuBtlWork->actor2 = gBtlWork->actor;
}

s32 task_btl_vslockon_1(BtlVslockonWork* work) {
    if (gBtlWork->hcEffect == HC_EFFECT_VANISH) {
        gRikuBtlWork->actor2 = NULL;
    } else {
        gRikuBtlWork->actor2 = gBtlWork->actor;
    }

    if (gRikuBtlWork->hcEffect == HC_EFFECT_VANISH) {
        gBtlWork->actor2 = NULL;
    } else {
        gBtlWork->actor2 = gRikuBtlWork->actor;
    }

    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_btl_vslockon_2(BtlVslockonWork* work) {
    s16 x;
    s16 y;
    BtlObj* target;

    target = gBtlWork->actor2;

    if (target != NULL) {
        WorldToScreen(&x, &y, target->x, target->y, target->z - (target->centerHeight << 8));
        DrawSprite(x, y, work->gfx, work->tiles, work->palette, NULL, 0, 0x100);
    }
}

void task_btl_vslockon_3(BtlVslockonWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescBtlVslockon = {
    "task_btl_vslockon",
    (TaskInitFunc)task_btl_vslockon_0,
    (TaskUpdateFunc)task_btl_vslockon_1,
    (TaskDrawFunc)task_btl_vslockon_2,
    (TaskDestroyFunc)task_btl_vslockon_3,
    sizeof(BtlVslockonWork),
};
