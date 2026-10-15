/**
 * btl_badstatus.c
 * Status Ailment Indicator
 */

#include "obj_api.h"
#include "btl3.h"
#include "sprites_btl.h"
#include "btl3_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"

static const AnimDef sBtlBadstatusAnimDefs[5] = {
    { gBtlBadstatusStopFrames, gBtlBadstatusStopAnims, gBtlBadstatusStopTiles, 0 },
    { gBtlBadstatusStunFrames, gBtlBadstatusStunAnims, gBtlBadstatusStunTiles, 0 },
    { gBtlBadstatusBindFrames, gBtlBadstatusBindAnims, gBtlBadstatusBindTiles, 0 },
    { gBtlBadstatusConfuseFrames, gBtlBadstatusConfuseAnims, gBtlBadstatusConfuseTiles, 0 },
    { gBtlBadstatusTerrorFrames, gBtlBadstatusTerrorAnims, gBtlBadstatusTerrorTiles, 0 },
};

void task_btl_badstatus_0(BtlBadStatusWork* work, BtlObj* obj) {
    work->status = BAD_STATUS_NONE;
    work->actor = obj;
    work->tiles = AllocObjTiles(128, NULL);
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
    work->palette2 = LoadObjPalette(gCard00Palette, sizeof(gCard00Palette));
    work->palette3 = work->palette;
    AnimInit(&work->anim, NULL, NULL);
    AnimChangeWithDef(sBtlBadstatusAnimDefs, &work->anim, 0, ANIM_FLAG_LOOP, work->tiles);
}

u8 task_btl_badstatus_1(BtlBadStatusWork* work) {
    BtlObj* obj;
    u32 status;

    obj = work->actor;
    status = obj->badStatus;

    if (status == BAD_STATUS_NONE) {
        return 1;
    }

    if (status != work->status) {
        work->status = status;

        switch (status) {
        case BAD_STATUS_STOP:
            AnimChangeWithDef(sBtlBadstatusAnimDefs, &work->anim, 0, ANIM_FLAG_LOOP, work->tiles);
            work->palette3 = work->palette;
            break;
        case BAD_STATUS_BIND:
            AnimChangeWithDef(sBtlBadstatusAnimDefs, &work->anim, 2, ANIM_FLAG_LOOP, work->tiles);
            work->palette3 = work->palette2;
            break;
        case BAD_STATUS_CONFUSE:
            AnimChangeWithDef(sBtlBadstatusAnimDefs, &work->anim, 3, ANIM_FLAG_LOOP, work->tiles);
            work->palette3 = work->palette;
            break;
        case BAD_STATUS_TERROR:
            AnimChangeWithDef(sBtlBadstatusAnimDefs, &work->anim, 4, ANIM_FLAG_LOOP, work->tiles);
            work->palette3 = work->palette2;
            break;
        case BAD_STATUS_STUN:
        default:
            AnimChangeWithDef(sBtlBadstatusAnimDefs, &work->anim, 1, ANIM_FLAG_LOOP, work->tiles);
            work->palette3 = work->palette;
            break;
        }
    }

    obj->badStatusTimer--;

    if (obj->badStatusTimer <= 0) {
        obj->badStatus = BAD_STATUS_NONE;
        work->status = BAD_STATUS_NONE;
    }

    return 1;
}

void task_btl_badstatus_2(BtlBadStatusWork* work) {
    BtlObj* obj;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;

    obj = work->actor;

    if (obj->badStatus != BAD_STATUS_NONE) {
        flags = GetBattleSpritePriorityFlags(obj->y);

        if (gBtlWork->paused) {
            gfx = AnimGetGfx(&work->anim);
        } else {
            gfx = AnimUpdate(&work->anim);
        }

        WorldToScreen(&sx, &sy, obj->x, obj->y,
                      obj->z - ((obj->height + 8) << 8));
        DrawSprite(sx, sy, gfx, work->tiles, work->palette3, NULL, flags,
                   -4101 - ((obj->y >> 8) * 4));
    }
}

void task_btl_badstatus_3(BtlBadStatusWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
}

TaskDesc gTaskDescBtlBadstatus = {
    "task_btl_badstatus",
    (TaskInitFunc)task_btl_badstatus_0,
    (TaskUpdateFunc)task_btl_badstatus_1,
    (TaskDrawFunc)task_btl_badstatus_2,
    (TaskDestroyFunc)task_btl_badstatus_3,
    sizeof(BtlBadStatusWork),
};
