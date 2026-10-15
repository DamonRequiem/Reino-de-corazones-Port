/**
 * emy_02.c
 * Blue Rhapsody Enemy
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

static const AnimDef sEmy02CommonAnimDefs[3] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 0 },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 3 },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 2 },
};

static const AnimDef sEmy02AnimDefs[2] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 6 },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 8 },
};

static const EmyDef sEmy02Def = { gEmy02Palette, sEmy02CommonAnimDefs, 460, 130, 20, 20, 64, 32, 32, 10, 0, { ENEMY_BLUE_RHAPSODY, 34, 24, 12, 4, 100, EMY_KIND_FLAG_NO_ENEMY_COLLISION } };

TaskDesc gTaskDescEmy02 = {
    "task_emy_02",
    (TaskInitFunc)task_emy_02_0,
    (TaskUpdateFunc)task_emy_02_1,
    (TaskDrawFunc)task_emy_02_2,
    (TaskDestroyFunc)task_emy_02_3,
    sizeof(EmyWork),
};

void task_emy_02_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy02Def, obj);
    work->idleState = EMY_STATE_HOVER;
}

enum Emy02State {
    EMY02_STATE_BLIZZARD = 18,
    EMY02_STATE_BLIZZARA
};

u8 task_emy_02_1(EmyWork* work) {
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
            work->state = EMY02_STATE_BLIZZARD;
            break;
        case 1:
            work->state = EMY02_STATE_BLIZZARA;
            break;
        }
    }

    switch (work->state) {
    case EMY02_STATE_BLIZZARD: {
        s32 y;

        AnimChangeWithDef(sEmy02AnimDefs, &w->anim, 0, 0, w->tiles);
        work->vz = 0;

        if (work->stateTimer == 0) {
        } else if (work->stateTimer == 22) {
            y = act->y;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                targetX = act->x - 0x3C00;
                BgFxStartBlizzard(SPELL_TIER_BASE, act->x - 0x2800, y, act->z - 0x800, targetX, y, 0, TRUE,
                    0xA9);
            } else {
                targetX = act->x + 0x3C00;
                BgFxStartBlizzard(SPELL_TIER_BASE, act->x + 0x2800, y, act->z - 0x800, targetX, y, 0, FALSE,
                    0xA9);
            }
        }

        if (work->stateTimer > 21 && !BgFxIsActive()) {
            EmyReturnToIdle(work);
        } else {
            work->stateTimer++;
        }

        break;
    }
    case EMY02_STATE_BLIZZARA: {
        s32 y;

        AnimChangeWithDef(sEmy02AnimDefs, &w->anim, 1, 0, w->tiles);
        work->vz = 0;

        if (work->stateTimer == 0) {
        } else if (work->stateTimer == 3) {
            y = act->y;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                targetX = act->x - 0x3C00;
                BgFxStartBlizzard(SPELL_TIER_RA, act->x - 0x2800, y, act->z - 0x800, targetX, y, 0, TRUE,
                    0xAA);
            } else {
                targetX = act->x + 0x3C00;
                BgFxStartBlizzard(SPELL_TIER_RA, act->x + 0x2800, y, act->z - 0x800, targetX, y, 0, FALSE,
                    0xAA);
            }
        }

        if (work->stateTimer > 2 && !BgFxIsActive()) {
            EmyReturnToIdle(work);
        } else {
            work->stateTimer++;
        }

        break;
    }
    }

    return EmyUpdateCommonStates(work);
}

void task_emy_02_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_02_3(EmyWork* work) {
    EmyReleaseResources(work);
}
