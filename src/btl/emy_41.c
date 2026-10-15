/**
 * emy_41.c
 * Aquatank Enemy
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
#include "btl_effect.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy41CommonAnimDefs[3] = {
    { gEmy4100Frames, gEmy4100Anims, gEmy4100Tiles, 0 },
    { gEmy4102Frames, gEmy4102Anims, gEmy4102Tiles, 0 },
    { gEmy4101Frames, gEmy4101Anims, gEmy4101Tiles, 0 },
};

static const AnimDef sEmy41AnimDefs[2] = {
    { gEmy4110Frames, gEmy4110Anims, gEmy4110Tiles, 0 },
    { gEmy4111Frames, gEmy4111Anims, gEmy4111Tiles, 0 },
};

static const EmyDef sEmy41Def = { gEmy41Palette, sEmy41CommonAnimDefs, 192, 400, 50, 20, 64, 32, 32, 10, 0, { ENEMY_AQUATANK, 108, 56, 32, 20, 100, EMY_KIND_FLAG_LARGE_BODY } };

TaskDesc gTaskDescEmy41 = {
    "task_emy_41",
    (TaskInitFunc)task_emy_41_0,
    (TaskUpdateFunc)task_emy_41_1,
    (TaskDrawFunc)task_emy_41_2,
    (TaskDestroyFunc)task_emy_41_3,
    sizeof(Emy41Work),
};

void task_emy_41_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy41Def, obj);
    work->idleState = EMY_STATE_HOVER;
}

enum Emy41State {
    EMY41_STATE_LUNGE = 18,
    EMY41_STATE_THUNDER
};

u8 task_emy_41_1(Emy41Work* work) {
    Emy41Work* w;
    BtlObj* act;
    u16 roll;
    s32 z;
    s32 sample;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->base.state = EMY41_STATE_LUNGE;
            break;
        case 1:
            work->base.state = EMY41_STATE_THUNDER;
            break;
        }
    }

    switch (work->base.state) {
    case EMY41_STATE_LUNGE:
        AnimChangeWithDef(sEmy41AnimDefs, &w->base.anim, 0, 0, w->base.tiles);
        work->base.vz = 0;
        sample = SIN((u16)work->base.stateTimer * 4) << 4;
        z = act->z + 0x1000;
        act->z += (sample - z) >> 2;
        EmyLungeAttack(&work->base, 0x14, 0x63, 0x1E, 0xD8, 0x40, SONG_BTL_MON_HIT02, 0, -0x10, 0x2C);
        break;
    case EMY41_STATE_THUNDER:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sEmy41AnimDefs, &w->base.anim, 1, 0, w->base.tiles);
            GetEnemyTargetPosition(act, &w->targetX, &w->targetY, NULL);
            w->targetZ = 0;
        }

        if (AnimGetFrame(&work->base.anim) == 4 && work->base.anim.timer == 0) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                BgFxStartThunder(SPELL_TIER_RA, act->x - 0x2C00, act->y, act->z, w->targetX,
                    w->targetY, w->targetZ, 0xD9);
            } else {
                BgFxStartThunder(SPELL_TIER_RA, act->x + 0x2C00, act->y, act->z, w->targetX,
                    w->targetY, w->targetZ, 0xD9);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            EmyReturnToIdle(&work->base);
        } else {
            work->base.stateTimer++;
        }

        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_41_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_41_3(EmyWork* work) {
    EmyReleaseResources(work);
}
