/**
 * emy_26.c
 * Gargoyle Enemy
 */

#include "task_descriptors.h"
#include "sprites_emy.h"
#include "enemy_common.h"
#include "songs.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_effect.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy26CommonAnimDefs[3] = {
    { gEmy2600Frames, gEmy2600Anims, gEmy2600Tiles, 0 },
    { gEmy2602Frames, gEmy2602Anims, gEmy2602Tiles, 0 },
    { gEmy2601Frames, gEmy2601Anims, gEmy2601Tiles, 0 },
};

static const AnimDef sEmy26AnimDefs[2] = {
    { gEmy2610Frames, gEmy2610Anims, gEmy2610Tiles, 0 },
    { gEmy2611Frames, gEmy2611Anims, gEmy2611Tiles, 0 },
};

static const EmyDef sEmy26Def = { gEmy26Palette, sEmy26CommonAnimDefs, 192, 130, 20, 20, 64, 32, 32, 10, 0, { ENEMY_GARGOYLE, 89, 36, 20, 16, 100, EMY_KIND_FLAG_LARGE_BODY } };

TaskDesc gTaskDescEmy26 = {
    "task_emy_26",
    (TaskInitFunc)task_emy_26_0,
    (TaskUpdateFunc)task_emy_26_1,
    (TaskDrawFunc)task_emy_26_2,
    (TaskDestroyFunc)task_emy_26_3,
    sizeof(EmyWork),
};

void task_emy_26_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy26Def, obj);
    work->actor.z = (GetRandom() % 0x1001) - 0x3000;
    work->idleState = EMY_STATE_HOVER;
}

enum Emy26State {
    EMY26_STATE_DIVE_LUNGE = 18,
    EMY26_STATE_FIRE
};

u8 task_emy_26_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 roll;
    s32 y;
    s32 targetX;
    s32 z;
    s32* targetZ;

    w = work;
    act = &work->actor;

    if (EmyUpdateReaction(work)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->state = EMY26_STATE_DIVE_LUNGE;
            break;
        case 1:
            work->state = EMY26_STATE_FIRE;
            break;
        }
    }

    switch (work->state) {
    case EMY26_STATE_DIVE_LUNGE:
        AnimChangeWithDef(sEmy26AnimDefs, &w->anim, 0, 0, w->tiles);

        switch (AnimGetFrame(&work->anim)) {
        case 3:
            if (work->anim.timer == 0) {
                work->vz = 0x300;
            }

            break;
        case 0:
        case 1:
        case 2:
            work->vz = 0;
            targetZ = &gBtlWork->targetZ;
            z = act->z + 0x3C00;
            act->z += (*targetZ - z) >> 3;
            break;
        }

        EmyLungeAttack(work, 0x20, 0x0C, 0x14, 0xC5, 0x28, SONG_BTL_HANE_HIT, 0x14, 0x0A, 0x0A);
        break;
    case EMY26_STATE_FIRE:
        work->vz = 0;

        switch (work->stateTimer) {
        case 0:
            AnimChangeWithDef(sEmy26AnimDefs, &w->anim, 1, 0, w->tiles);
            work->stateTimer++;
            break;
        case 1:
            if (AnimIsFinished(&work->anim)) {
                y = act->y;

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    targetX = act->x - 0x6400;
                    BgFxStartFire(SPELL_TIER_RA, act->x - 0x2600, y, act->z - 0x2000, targetX, y, 0, TRUE,
                        0xC6);
                } else {
                    targetX = act->x + 0x6400;
                    BgFxStartFire(SPELL_TIER_RA, act->x + 0x2600, y, act->z - 0x2000, targetX, y, 0, FALSE,
                        0xC6);
                }

                work->stateTimer++;
            }

            break;
        case 2:
            AnimChange(&work->anim, 1, 0);

            if (AnimIsFinished(&work->anim)) {
                work->stateTimer++;
            }

            break;
        case 3:
            AnimChange(&work->anim, 1, 0);

            if (AnimIsFinished(&work->anim)) {
                EmyReturnToIdle(work);
            }

            break;
        }

        break;
    }

    return EmyUpdateCommonStates(work);
}

void task_emy_26_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_26_3(EmyWork* work) {
    EmyReleaseResources(work);
}
