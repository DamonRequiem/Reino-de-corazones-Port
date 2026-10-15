/**
 * emy_22.c
 * Search Ghost Enemy
 */

#include "task_descriptors.h"
#include "emy.h"
#include "sprites_emy.h"
#include "enemy_common.h"
#include "songs.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy22CommonAnimDefs[3] = {
    { gEmy2200Frames, gEmy2200Anims, gEmy2200Tiles, 0 },
    { gEmy2202Frames, gEmy2202Anims, gEmy2202Tiles, 0 },
    { gEmy2200Frames, gEmy2200Anims, gEmy2200Tiles, 0 },
};

static const AnimDef sEmy22AnimDefs[2] = {
    { gEmy2210Frames, gEmy2210Anims, gEmy2210Tiles, 0 },
    { gEmy2211Frames, gEmy2211Anims, gEmy2211Tiles, 0 },
};

static const EmyDef sEmy22Def = { gEmy22Palette, sEmy22CommonAnimDefs, 192, 130, 20, 20, 64, 32, 32, 5, 0, { ENEMY_SEARCH_GHOST, 61, 40, 12, 24, 15, EMY_KIND_FLAG_NO_ENEMY_COLLISION } };

TaskDesc gTaskDescEmy22 = {
    "task_emy_22",
    (TaskInitFunc)task_emy_22_0,
    (TaskUpdateFunc)task_emy_22_1,
    (TaskDrawFunc)task_emy_22_2,
    (TaskDestroyFunc)task_emy_22_3,
    sizeof(Emy22Work),
};

void task_emy_22_0(Emy22Work* work, void* obj) {
    EmyInit(&work->base, &sEmy22Def, obj);
    work->base.idleState = EMY_STATE_HOVER;
    work->counterPending = FALSE;
}

enum Emy22State {
    EMY22_STATE_WARP_OUT = 18,
    EMY22_STATE_WARP_IN,
    EMY22_STATE_DRAIN_LUNGE,
    EMY22_STATE_LUNGE
};

u8 task_emy_22_1(Emy22Work* work) {
    Emy22Work* w;
    BtlObj* act;
    s32 warpTargetX;
    s32 drainTargetX;
    s32 lungeTargetX;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        if (act->hp < act->maxHp) {
            work->base.state = EMY22_STATE_DRAIN_LUNGE;
        } else {
            work->base.state = EMY22_STATE_LUNGE;
        }
    }

    switch (work->base.state) {
    case EMY_STATE_HURT:
        if (work->base.stateTimer == 0) {
            w->counterPending = TRUE;
        }

        break;
    case EMY_STATE_HOVER:
        if (w->counterPending && work->base.stateTimer == 0) {
            work->base.state = EMY22_STATE_WARP_OUT;
            work->base.stateTimer = 0;
            w->counterPending = FALSE;
        }

        break;
    case EMY22_STATE_WARP_OUT:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, ANIM_FLAG_LOOP,
                w->base.tiles);
            act->flags |= (BTLOBJ_FLAG_INTANGIBLE | BTLOBJ_FLAG_CARD_USE_BLOCKED);
            work->base.steps = 20;
            work->base.stateTimer = 1;
        }

        work->base.vz = 0;

        if (work->base.steps > 0) {
            ApproachValue(&work->base.scaleX, Q_8_8(0.1), work->base.steps);

            if (--work->base.steps > 0) {
                break;
            }
        }

        work->base.state = EMY22_STATE_WARP_IN;
        work->base.stateTimer = 0;
        break;
    case EMY22_STATE_WARP_IN:
        if (work->base.stateTimer == 0) {
            GetEnemyTargetPosition(act, &warpTargetX, NULL, NULL);
            AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, ANIM_FLAG_LOOP,
                w->base.tiles);

            if (act->x > warpTargetX) {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }

            act->x = (gBtlWork->xMin
                + GetRandom() % (gBtlWork->xMax - gBtlWork->xMin + 1))
                << 8;
            act->y = (gBtlWork->yMin
                + GetRandom() % (gBtlWork->yMax - gBtlWork->yMin + 1))
                << 8;
            act->z = gBtlWork->targetZ;
            work->base.scaleX = Q_8_8(0.1);
            work->base.steps = 20;
            work->base.stateTimer = 1;
            m4aSongNumStart(SONG_BTL_WARPIN);
        }

        work->base.vz = 0;

        if (work->base.steps > 0) {
            ApproachValue(&work->base.scaleX, Q_8_8(1), work->base.steps);

            if (--work->base.steps > 0) {
                break;
            }
        }

        act->flags &= ~(BTLOBJ_FLAG_INTANGIBLE | BTLOBJ_FLAG_CARD_USE_BLOCKED);
        work->base.state = work->base.idleState;
        work->base.stateTimer = 0;
        break;
    case EMY22_STATE_DRAIN_LUNGE:
        if (work->base.stateTimer == 0) {
            GetEnemyTargetPosition(act, &drainTargetX, NULL, NULL);

            if (act->x > drainTargetX) {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }
        }

        act->z += -act->z >> 4;
        AnimChangeWithDef(sEmy22AnimDefs, &w->base.anim, 0, 0, w->base.tiles);
        EmyLungeAttack(&work->base, 27, 14, 40, 191, 24, SONG_BTL_MON_HIT00, 24, 0, 24);

        if (gBtlWork->actor->flags & BTLOBJ_FLAG_DAMAGE_PENDING) {
            act->hp += act->maxHp >> 3;

            if (act->hp > act->maxHp) {
                act->hp = act->maxHp;
            }

            CreateBtlPopTask(act, BTL_POP_RECOVER);
        }

        break;
    case EMY22_STATE_LUNGE:
        if (work->base.stateTimer == 0) {
            GetEnemyTargetPosition(act, &lungeTargetX, NULL, NULL);

            if (act->x > lungeTargetX) {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }
        }

        act->z += -act->z >> 4;
        AnimChangeWithDef(sEmy22AnimDefs, &w->base.anim, 1, 0, w->base.tiles);
        EmyLungeAttack(&work->base, 50, 19, 30, 192, 16, SONG_BTL_MON_HIT00, 48, 0, 24);
        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_22_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_22_3(EmyWork* work) {
    EmyReleaseResources(work);
}
