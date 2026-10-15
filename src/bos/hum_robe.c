/**
 * hum_robe.c
 * Robed Figure Tutorial Opponent
 */

#include "hum.h"
#include "sprites_evt.h"
#include "sprites_hum.h"
#include "hum_common.h"
#include "hum_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "hum_types.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sHumRobeAnimDefs[2] = {
    { gRobeFl00Frames, gRobeFl00Anims, gRobeFl00Tiles, 5 },
    { gHumRobeGuardFrames, gHumRobeGuardAnims, gHumRobeGuardTiles, 0 },
};

static const HumDef sHumRobeDef = { 128, gRobePalette, 0, { ENEMY_MARLUXIA, 99, 64, 14, 32, 99, 0 } };

void task_hum_robe_0(RobeWork* work) {
    HumInit(&work->base, &sHumRobeDef);
    work->idleAnim = TRUE;
    AnimChangeWithDef(sHumRobeAnimDefs, &work->base.anim, 0, ANIM_FLAG_LOOP, work->base.tiles);
}

u8 task_hum_robe_1(RobeWork* work) {
    BtlObj* act = &work->base.actor;
    s32 x;
    s32 y;
    s32 z;
    u8 alive;

    if (HumUpdateReaction(&work->base) == BTL_REACTION_HURT) {
        work->base.stateTimer = 1;
    }

    if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
        if (work->idleAnim == TRUE) {
            AnimChangeWithDef(sHumRobeAnimDefs, &work->base.anim, 1, 0, work->base.tiles);
            work->idleAnim = FALSE;
        }
    } else if (AnimIsFinished(&work->base.anim)) {
        AnimChangeWithDef(sHumRobeAnimDefs, &work->base.anim, 0, ANIM_FLAG_LOOP, work->base.tiles);
        work->idleAnim = TRUE;
    }

    HumFaceTarget(&work->base, 1);
    x = act->x;
    y = act->y;
    z = act->z;
    alive = HumUpdate(&work->base);
    act->x = x;
    act->y = y;
    act->z = z;
    return alive;
}

void task_hum_robe_2(HumWork* work) {
    HumDraw(work);
}

void task_hum_robe_3(HumWork* work) {
    HumReleaseResources(work);
}

TaskDesc gTaskDescHumRobe = {
    "task_hum_robe",
    (TaskInitFunc)task_hum_robe_0,
    (TaskUpdateFunc)task_hum_robe_1,
    (TaskDrawFunc)task_hum_robe_2,
    (TaskDestroyFunc)task_hum_robe_3,
    sizeof(RobeWork),
};
