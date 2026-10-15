/**
 * emy_07.c
 * White Mushroom Enemy
 */

#include "task_descriptors.h"
#include "emy.h"
#include "sprites_emy.h"
#include "system_state.h"
#include "enemy_common.h"
#include "songs.h"
#include "player_progression.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_collision.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"
#include "jiminy_records_index_data.h"

static const AnimDef sEmy07CommonAnimDefs[3] = {
    { gEmy07Fl00Frames, gEmy07Fl00Anims, gEmy07Fl00Tiles, 0 },
    { gEmy07Fl03Frames, gEmy07Fl03Anims, gEmy07Fl03Tiles, 0 },
    { gEmy07Fl00Frames, gEmy07Fl00Anims, gEmy07Fl00Tiles, 0 },
};

static const AnimDef sEmy07AnimDefs[7] = {
    { gEmy07Fl05Frames, gEmy07Fl05Anims, gEmy07Fl05Tiles, 0 },
    { gEmy07Fl04Frames, gEmy07Fl04Anims, gEmy07Fl04Tiles, 0 },
    { gEmy07Fl04tFrames, gEmy07Fl04tAnims, gEmy07Fl04tTiles, 0 },
    { gEmy07Fl07Frames, gEmy07Fl07Anims, gEmy07Fl07Tiles, 0 },
    { gEmy07Fl06Frames, gEmy07Fl06Anims, gEmy07Fl06Tiles, 0 },
    { gEmy07Fl08Frames, gEmy07Fl08Anims, gEmy07Fl08Tiles, 0 },
    { gEmy07Fl02Frames, gEmy07Fl02Anims, gEmy07Fl02Tiles, 0 },
};

static const EmyDef sEmy07Def = { gEmy07Palette, sEmy07CommonAnimDefs, 0, 130, 20, 20, 0, 0, 0, 1, 0, { ENEMY_WHITE_MUSHROOM, 40, 32, 12, 16, 100, 0 } };

TaskDesc gTaskDescEmy07 = {
    "task_emy_07",
    (TaskInitFunc)task_emy_07_0,
    (TaskUpdateFunc)task_emy_07_1,
    (TaskDrawFunc)task_emy_07_2,
    (TaskDestroyFunc)task_emy_07_3,
    sizeof(Emy07Work),
};

enum Emy07State {
    EMY07_STATE_IDLE = 18,
    EMY07_STATE_FAILED,
    EMY07_STATE_SATISFIED,
    EMY07_STATE_REQUEST_FIRE,
    EMY07_STATE_REQUEST_BLIZZARD,
    EMY07_STATE_REQUEST_THUNDER,
    EMY07_STATE_VANISH = 25,
    EMY07_STATE_WRONG_HIT
};

void task_emy_07_0(Emy07Work* work, void* obj) {
    EmyInit(&work->base, &sEmy07Def, obj);
    work->successCount = 0;
    work->thunderRequested = FALSE;
    work->base.idleState = EMY07_STATE_IDLE;
    work->base.actor.flags |= BTLOBJ_FLAG_NEVER_USES_CARDS;
    work->rewarded = FALSE;
}

u8 task_emy_07_1(Emy07Work* work) {
    Emy07Work* w;
    BtlObj* act;
    EmySpawn spawn;
    u32 prevState;
    s32 idleTargetX;
    s32 wrongHitTargetX;

    w = work;
    act = &work->base.actor;
    prevState = work->base.state;

#ifdef VERSION_EU
    act->hp = 0x7FFF;
#endif

    EmyUpdateReaction(&work->base);

#ifdef VERSION_EU
    act->hp = act->maxHp;
#endif

    switch (work->base.state) {
    case EMY_STATE_HURT:
    case EMY_STATE_DEFEATED:
    case EMY_STATE_GRAVITY_SQUASH:
        work->base.state = EMY07_STATE_WRONG_HIT;

        switch (prevState) {
        case EMY07_STATE_REQUEST_FIRE:
            w->thunderRequested = FALSE;

            if (act->hitFlags & ATTACK_FLAG_ELEMENT_FIRE) {
                ClearBtlObjActionFlags(act);
                work->base.state = EMY07_STATE_SATISFIED;
                work->base.stateTimer = 0;
            }

            break;
        case EMY07_STATE_REQUEST_BLIZZARD:
            w->thunderRequested = FALSE;

            if (act->hitFlags & ATTACK_FLAG_ELEMENT_BLIZZARD) {
                ClearBtlObjActionFlags(act);
                work->base.state = EMY07_STATE_SATISFIED;
                work->base.stateTimer = 0;
            }

            break;
        case EMY07_STATE_REQUEST_THUNDER:
            w->thunderRequested = TRUE;

            if (act->hitFlags & ATTACK_FLAG_ELEMENT_THUNDER) {
                ClearBtlObjActionFlags(act);
                work->base.state = EMY07_STATE_SATISFIED;
                work->base.stateTimer = 0;
            }

            break;
        }

        act->hp = act->maxHp;
        ColliderSetDisabled(&act->collider, FALSE);
        break;
    }

    switch (work->base.state) {
    case EMY07_STATE_IDLE:
        AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, ANIM_FLAG_LOOP | ANIM_FLAG_RANDOM_START,
            w->base.tiles);
        GetEnemyTargetPosition(act, &idleTargetX, NULL, NULL);

        if (act->x < idleTargetX) {
            act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
        } else {
            act->flags |= BTLOBJ_FLAG_FACING_LEFT;
        }

        if (GetRandom() % 60 == 0) {
            work->base.stateTimer = 0;

            switch (GetRandom() % 3) {
            case 1:
                work->base.state = EMY07_STATE_REQUEST_BLIZZARD;
                break;
            case 2:
                work->base.state = EMY07_STATE_REQUEST_THUNDER;
                break;
            case 0:
            default:
                work->base.state = EMY07_STATE_REQUEST_FIRE;
                break;
            }
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY07_STATE_REQUEST_FIRE:
        AnimChangeWithDef(sEmy07AnimDefs, &w->base.anim, 3, ANIM_FLAG_LOOP, w->base.tiles);

        if (work->base.stateTimer > 300) {
            work->base.stateTimer = 0;
            work->base.state = EMY07_STATE_IDLE;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY07_STATE_REQUEST_BLIZZARD:
        AnimChangeWithDef(sEmy07AnimDefs, &w->base.anim, 4, ANIM_FLAG_LOOP, w->base.tiles);

        if (work->base.stateTimer > 300) {
            work->base.stateTimer = 0;
            work->base.state = EMY07_STATE_IDLE;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY07_STATE_REQUEST_THUNDER:
        AnimChangeWithDef(sEmy07AnimDefs, &w->base.anim, 5, ANIM_FLAG_LOOP, w->base.tiles);

        if (work->base.stateTimer > 300) {
            work->base.stateTimer = 0;
            work->base.state = EMY07_STATE_IDLE;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY07_STATE_SATISFIED:
        if (w->thunderRequested) {
            AnimChangeWithDef(sEmy07AnimDefs, &w->base.anim, 2, 0, w->base.tiles);
        } else {
            AnimChangeWithDef(sEmy07AnimDefs, &w->base.anim, 1, 0, w->base.tiles);
        }

        if (work->base.stateTimer == 0) {
            m4aSongNumStart(SONG_BTL_WM_OK);
            work->base.stateTimer = 1;
            act->flags |= BTLOBJ_FLAG_INTANGIBLE;
        }

        if (w->successCount == 2 && gFrameCounter % 10 == 0) {
            spawn.facingLeft = TRUE;
            spawn.hitPhase = 0;
            spawn.x = act->x;
            spawn.y = act->y;
            spawn.z = act->z - (act->height << 8);
            TaskCreate(&gBtlWork->taskPools[0], &gTaskDescBtlPrize,
                &spawn);
        }

        if (AnimIsFinished(&work->base.anim)) {
            w->successCount++;

            if (w->successCount > 2) {
                work->base.stateTimer = 0;
                work->base.state = EMY07_STATE_VANISH;
                w->rewarded = TRUE;
                SetJiminyFlag(JIMINY_RECORD_HEARTLESS_WHITE_MUSHROOM);
            } else {
                work->base.stateTimer = 0;
                work->base.state = EMY07_STATE_IDLE;
                act->flags &= ~BTLOBJ_FLAG_INTANGIBLE;
            }
        }

        break;
    case EMY07_STATE_WRONG_HIT:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 1, 0,
                w->base.tiles);
        }

        GetEnemyTargetPosition(act, &wrongHitTargetX, NULL, NULL);

        if (act->x < wrongHitTargetX) {
            act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
        } else {
            act->flags |= BTLOBJ_FLAG_FACING_LEFT;
        }

        if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            act->flags |= BTLOBJ_FLAG_INTANGIBLE;
            work->base.stateTimer = 0;
            work->base.state = EMY07_STATE_FAILED;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY07_STATE_FAILED:
        AnimChangeWithDef(sEmy07AnimDefs, &w->base.anim, 0, 0, w->base.tiles);

        if (work->base.stateTimer == 0) {
            act->flags |= BTLOBJ_FLAG_INTANGIBLE;
            work->base.stateTimer = 1;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = EMY07_STATE_VANISH;
        }

        break;
    case EMY07_STATE_VANISH:
        AnimChangeWithDef(sEmy07AnimDefs, &w->base.anim, 6, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            if (w->rewarded) {
                DropEnemyPrizes(act);
                TryDropPremireCard(act);
            }

            return 0;
        }

        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_07_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_07_3(EmyWork* work) {
    EmyReleaseResources(work);
}
