/**
 * emy_23.c
 * Screwdiver Enemy
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
#include "btl_collision.h"
#include "enemy_types.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy23CommonAnimDefs[3] = {
    { gEmy2300Frames, gEmy2300Anims, gEmy2300Tiles, 0 },
    { gEmy2302Frames, gEmy2302Anims, gEmy2302Tiles, 0 },
    { gEmy2301Frames, gEmy2301Anims, gEmy2301Tiles, 0 },
};

static const AnimDef sEmy23AnimDefs[2] = {
    { gEmy2310Frames, gEmy2310Anims, gEmy2310Tiles, 0 },
    { gEmy2311Frames, gEmy2311Anims, gEmy2311Tiles, 0 },
};

static const EmyDef sEmy23Def = { gEmy23Palette, sEmy23CommonAnimDefs, 192, 30, 2, 20, 64, 40, 32, 25, 0, { ENEMY_SCREWDIVER, 66, 36, 10, 16, 100, 0 } };

TaskDesc gTaskDescEmy23 = {
    "task_emy_23",
    (TaskInitFunc)task_emy_23_0,
    (TaskUpdateFunc)task_emy_23_1,
    (TaskDrawFunc)task_emy_23_2,
    (TaskDestroyFunc)task_emy_23_3,
    sizeof(Emy23Work),
};

void task_emy_23_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy23Def, obj);
    work->idleState = EMY_STATE_HOVER;
}

enum Emy23State {
    EMY23_STATE_DIVE = 18,
    EMY23_STATE_STAB
};

u8 task_emy_23_1(Emy23Work* work) {
    Emy23Work* w;
    BtlObj* act;
    s32 targetX;
    s32 dx;
    s32 diveTargetX;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        GetEnemyTargetPosition(act, &targetX, NULL, NULL);
        dx = act->x - targetX;

        if (dx >= 0 ? dx <= 0x31FF : targetX - act->x <= 0x31FF) {
            work->base.state = EMY23_STATE_STAB;
        } else {
            work->base.state = EMY23_STATE_DIVE;
        }
    }

    switch (work->base.state) {
    case EMY23_STATE_DIVE:
        AnimChangeWithDef(sEmy23AnimDefs, &w->base.anim, 0, 0, w->base.tiles);

        switch (AnimGetFrame(&work->base.anim)) {
        case 0:
        case 1:
        case 2:
            work->base.vz = 0;
            act->z += (-0x4000 - act->z) >> 3;
            break;
        case 3:
            if (work->base.anim.timer == 0) {
                GetEnemyTargetPosition(act, &diveTargetX, NULL, NULL);
                work->base.vz = 0x200;
                w->targetX = diveTargetX;
            }
        case 4:
        case 5:
            if (act->z >= act->groundZ) {
                work->base.vz = -0x466;
            }

            act->x += (w->targetX - act->x) >> 4;

            if (ApplyAttackBox(0xC1, act->x, act->y, act->z - 0x1000, 12, 16, 16)) {
                m4aSongNumStart(SONG_BTL_MON_SWORD00);
                work->base.vz = -0x466;
            }

            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            EmyReturnToIdle(&work->base);
        }

        break;
    case EMY23_STATE_STAB:
        AnimChangeWithDef(sEmy23AnimDefs, &w->base.anim, 1, 0, w->base.tiles);
        act->z += -act->z >> 2;

        if (AnimGetFrame(&work->base.anim) == 3) {
            if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                    ? ApplyAttackBox(0xC2, act->x - 0x1E00, act->y, act->z,
                        0x10, 0x10, 4)
                    : ApplyAttackBox(0xC2, act->x + 0x1E00, act->y, act->z,
                        0x10, 0x10, 4)) {
                m4aSongNumStart(SONG_BTL_MON_SWORD00);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            EmyReturnToIdle(&work->base);
        }

        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_23_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_23_3(EmyWork* work) {
    EmyReleaseResources(work);
}
