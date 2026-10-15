/**
 * hum_leon.c
 * Leon Tutorial Opponent
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
#include "game_state.h"
#include "hum_types.h"
#include "player_progression_types.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sHumLeonAnimDefs[5] = {
    { gReonFl00Frames, gReonFl00Anims, gReonFl00Tiles, 0 },
    { gHumLeonGunbladeFrames, gHumLeonGunbladeAnims, gHumLeonGunbladeTiles, 0 },
    { gHumLeonGunbladeFrames, gHumLeonGunbladeAnims, gHumLeonGunbladeTiles, 3 },
    { gHumLeonGunbladeFrames, gHumLeonGunbladeAnims, gHumLeonGunbladeTiles, 1 },
    { gHumLeonGunbladeFrames, gHumLeonGunbladeAnims, gHumLeonGunbladeTiles, 2 },
};

static const HumDef sHumLeonDef = { 128, gReonPalette, 0, { ENEMY_LEON, 99, 64, 14, 40, 99, 0 } };

TaskDesc gTaskDescHumLeon = {
    "task_hum_leon",
    (TaskInitFunc)task_hum_leon_0,
    (TaskUpdateFunc)task_hum_leon_1,
    (TaskDrawFunc)task_hum_leon_2,
    (TaskDestroyFunc)task_hum_leon_3,
    sizeof(LeonWork),
};

void task_hum_leon_0(LeonWork* work) {
    HumInit(&work->base, &sHumLeonDef);
    work->flashTimer = 0;
    work->gunbladeRaised = FALSE;
    AnimChangeWithDef(sHumLeonAnimDefs, &work->base.anim, 0, ANIM_FLAG_LOOP, work->base.tiles);
    work->savedLearnedStocks = gGameState.progression.learnedStocks;
    work->savedLearnedStocks2 = gGameState.progression.learnedStocks2;
    gGameState.progression.learnedStocks = 0;
    gGameState.progression.learnedStocks2 = 0;
}

enum HumLeonState {
    HUM_LEON_STATE_CARD_ACTION = 19,
    HUM_LEON_STATE_COUNTER
};

u8 task_hum_leon_1(LeonWork* work) {
    LeonWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 z;
    s32 targetX;
    s32 targetY;
    s32 targetZ;
    u8 alive;

    w = work;
    act = &work->base.actor;
    GetEnemyTargetPosition(act, &targetX, &targetY, &targetZ);

    switch (HumUpdateReaction(&work->base)) {
    case BTL_REACTION_CARD_BROKEN:
        break;
    case BTL_REACTION_CARD_ACTION:
        work->base.state = HUM_LEON_STATE_CARD_ACTION;
        work->base.stateTimer = 0;
        break;
    }

    HumFaceTarget(&work->base, 1);

    switch (work->base.state) {
    case HUM_STATE_ENTER:
        AnimChangeWithDef(sHumLeonAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        break;
    case HUM_STATE_IDLE:
        if (gBtlWork->flags & 0x20000000000) {
            if (!w->gunbladeRaised) {
                AnimChangeWithDef(sHumLeonAnimDefs, &w->base.anim, 1, 0, w->base.tiles);
                w->gunbladeRaised = TRUE;
            } else if (AnimIsFinished(&work->base.anim)) {
                AnimChangeWithDef(sHumLeonAnimDefs, &w->base.anim, 3, 0, w->base.tiles);
            }
        } else {
            if (w->gunbladeRaised) {
                AnimChangeWithDef(sHumLeonAnimDefs, &w->base.anim, 2, 0, w->base.tiles);
                w->gunbladeRaised = FALSE;
            } else if (AnimIsFinished(&work->base.anim)) {
                AnimChangeWithDef(sHumLeonAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
            }
        }

        if (gBtlWork->flags & 0x100000) {
            if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
                work->base.state = HUM_LEON_STATE_COUNTER;
                work->base.stateTimer = 0;
            }
        }

        break;
    case HUM_STATE_HURT:
        if (work->base.stateTimer == 0) {
            ClearBtlObjActionFlags(act);
            AnimChangeWithDef(sHumLeonAnimDefs, &w->base.anim, 4, 0, w->base.tiles);
            work->base.stateTimer = 8;
        }

        break;
    case HUM_STATE_HURT_RECOVER:
        if (gBtlWork->flags & 0x100000) {
            if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
                work->base.state = HUM_LEON_STATE_COUNTER;
                work->base.stateTimer = 0;
            }
        }

        break;
    case HUM_LEON_STATE_COUNTER:
        if (work->base.stateTimer > 10) {
            gBtlWork->rikuKeys |= RIKU_KEY_USE_CARD;
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LEON_STATE_CARD_ACTION:
        if (work->base.stateTimer > 80) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    default:
        AnimChangeWithDef(sHumLeonAnimDefs, &w->base.anim, 3, 0, w->base.tiles);
        HumFaceTarget(&work->base, 1);
        break;
    }

    if ((s16)w->flashTimer > 0) {
        w->flashTimer--;
        act->flags |= BTLOBJ_FLAG_HURT;
    } else {
        act->flags &= ~BTLOBJ_FLAG_HURT;
    }

    x = act->x;
    y = act->y;
    z = act->z;
    alive = HumUpdate(&work->base);
    act->x = x;
    act->y = y;
    act->z = z;
    return alive;
}

void task_hum_leon_2(HumWork* work) {
    HumDraw(work);
}

void task_hum_leon_3(LeonWork* work) {
    gGameState.progression.learnedStocks = work->savedLearnedStocks;
    gGameState.progression.learnedStocks2 = work->savedLearnedStocks2;
    HumReleaseResources(&work->base);
}
