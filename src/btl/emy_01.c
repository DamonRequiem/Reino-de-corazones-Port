/**
 * emy_01.c
 * Red Nocturne Enemy
 */

#include "task_descriptors.h"
#include "sprites_emy.h"
#include "enemy_common.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "btl_effect.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy01CommonAnimDefs[3] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 0 },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 3 },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 2 },
};

static const AnimDef sEmy01AnimDefs[2] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 1 },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 1 },
};

static const EmyDef sEmy01Def = { gEmy01Palette, sEmy01CommonAnimDefs, 384, 130, 20, 20, 64, 32, 32, 10, 0, { ENEMY_RED_NOCTURNE, 33, 24, 12, 4, 100, EMY_KIND_FLAG_NO_ENEMY_COLLISION } };

TaskDesc gTaskDescEmy01 = {
    "task_emy_01",
    (TaskInitFunc)task_emy_01_0,
    (TaskUpdateFunc)task_emy_01_1,
    (TaskDrawFunc)task_emy_01_2,
    (TaskDestroyFunc)task_emy_01_3,
    sizeof(EmyWork),
};

void task_emy_01_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy01Def, obj);
    work->idleState = EMY_STATE_HOVER;
}

enum Emy01State {
    EMY01_STATE_FIRE = 18,
    EMY01_STATE_FIRA
};

u8 task_emy_01_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 roll;
    s32 targetX;

    w = work;
    act = &work->actor;

    if (EmyUpdateReaction(work)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->state = EMY01_STATE_FIRE;
            break;
        case 1:
            work->state = EMY01_STATE_FIRA;
            break;
        }
    }

    switch (work->state) {
    case EMY01_STATE_FIRE: {
        s32 y;
        AnimChangeWithDef(sEmy01AnimDefs, &w->anim, 0, 0, w->tiles);
        work->vz = 0;

        if (work->stateTimer != 0) {
            if (work->stateTimer == 0x16) {
                y = act->y;

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    targetX = act->x - 0x6400;
                    BgFxStartFire(SPELL_TIER_BASE, act->x - 0x2600, y, act->z - 0xC00, targetX, y, 0, TRUE,
                        0xA7);
                } else {
                    targetX = act->x + 0x6400;
                    BgFxStartFire(SPELL_TIER_BASE, act->x + 0x2600, y, act->z - 0xC00, targetX, y, 0, FALSE,
                        0xA7);
                }
            }
        }

        if (work->stateTimer > 0x15 && !BgFxIsActive()) {
            EmyReturnToIdle(work);
        } else {
            work->stateTimer++;
        }

        break;
    }
    case EMY01_STATE_FIRA: {
        s32 y;
        AnimChangeWithDef(sEmy01AnimDefs, &w->anim, 1, 0, w->tiles);
        work->vz = 0;

        if (work->stateTimer != 0) {
            if (work->stateTimer == 0x16) {
                y = act->y;

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    targetX = act->x - 0x6400;
                    BgFxStartFire(SPELL_TIER_RA, act->x - 0x2600, y, act->z - 0xC00, targetX, y, 0, TRUE,
                        0xA8);
                } else {
                    targetX = act->x + 0x6400;
                    BgFxStartFire(SPELL_TIER_RA, act->x + 0x2600, y, act->z - 0xC00, targetX, y, 0, FALSE,
                        0xA8);
                }
            }
        }

        if (work->stateTimer > 0x15 && !BgFxIsActive()) {
            EmyReturnToIdle(work);
        } else {
            work->stateTimer++;
        }

        break;
    }
    }

    return EmyUpdateCommonStates(work);
}

void task_emy_01_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_01_3(EmyWork* work) {
    EmyReleaseResources(work);
}
