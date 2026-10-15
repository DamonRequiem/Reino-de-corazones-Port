/**
 * emy_06.c
 * Sea Neon Enemy
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
#include "btl_collision.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy06CommonAnimDefs[3] = {
    { gEmy0600Frames, gEmy0600Anims, gEmy0600Tiles, 0 },
    { gEmy0603Frames, gEmy0603Anims, gEmy0603Tiles, 0 },
    { gEmy0600Frames, gEmy0600Anims, gEmy0600Tiles, 0 },
};

static const AnimDef sEmy06AnimDefs[2] = {
    { gEmy0610Frames, gEmy0610Anims, gEmy0610Tiles, 0 },
    { gEmy0611Frames, gEmy0611Anims, gEmy0611Tiles, 0 },
};

static const EmyDef sEmy06Def = { gEmy06Palette, sEmy06CommonAnimDefs, 230, 130, 20, 20, 70, 32, 48, 10, 0, { ENEMY_SEA_NEON, 42, 32, 8, 16, 100, 0 } };

TaskDesc gTaskDescEmy06 = {
    "task_emy_06",
    (TaskInitFunc)task_emy_06_0,
    (TaskUpdateFunc)task_emy_06_1,
    (TaskDrawFunc)task_emy_06_2,
    (TaskDestroyFunc)task_emy_06_3,
    sizeof(Emy06Work),
};

void task_emy_06_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy06Def, obj);
    work->idleState = EMY_STATE_HOVER;
}

enum Emy06State {
    EMY06_STATE_HOMING_CHARGE = 18,
    EMY06_STATE_STRAIGHT_DASH
};

u8 task_emy_06_1(Emy06Work* work) {
    Emy06Work* w;
    BtlObj* act;
    s32* targetZ;
    u16 frame;
    u16 timer;
    s32 targetY;
    s32 dy;
    s32 z;
    s32 adjustedX;
    s32 step;
    s32 tx;
    s32 ty;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        GetEnemyTargetPosition(act, NULL, &targetY, NULL);
        dy = act->y - targetY;

        if (dy >= 0 ? dy <= 0xFFF : targetY - act->y <= 0xFFF) {
            work->base.state = EMY06_STATE_STRAIGHT_DASH;
        } else {
            work->base.state = EMY06_STATE_HOMING_CHARGE;
        }

        w->speed = 0;
    }

    switch (work->base.state) {
    case EMY06_STATE_HOMING_CHARGE:
        AnimChangeWithDef(sEmy06AnimDefs, &w->base.anim, 0, 0, w->base.tiles);
        work->base.vz = 0;
        targetZ = &gBtlWork->targetZ;
        z = act->z + 0xC00;
        act->z += (*targetZ - z) >> 4;
        frame = AnimGetFrame(&work->base.anim);

        if (frame >= 5 && frame <= 20) {
            timer = work->base.stateTimer;
            timer &= 3;

            if (timer == 0) {
                GetEnemyTargetPosition(act, &tx, &ty, NULL);
                work->base.angle = GetAngle(act->x, act->y, tx, ty);
            }

            act->x += gSineTable[work->base.angle] * 2;
            act->y -= gSineTable[work->base.angle + 0x40] * 2;

            if (ApplyAttackBox(0xAF, act->x, act->y, act->z - 0x800, 0x14, 0x14,
                    8)) {
                m4aSongNumStart(SONG_BTL_MON_HIT04);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            EmyReturnToIdle(&work->base);
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY06_STATE_STRAIGHT_DASH:
        AnimChangeWithDef(sEmy06AnimDefs, &w->base.anim, 1, 0, w->base.tiles);
        work->base.vz = 0;
        targetZ = &gBtlWork->targetZ;
        z = act->z + 0xC00;
        act->z += (*targetZ - z) >> 4;
        frame = AnimGetFrame(&work->base.anim);

        if (frame >= 6 && frame <= 16) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                adjustedX = act->x;
                adjustedX += 0x7800;
            } else {
                adjustedX = act->x;
                adjustedX -= 0x7800;
            }

            step = (act->originX - adjustedX) >> 3;
            w->speed += 0x33;

            if (step > w->speed) {
                step = w->speed;
            } else if (step < -w->speed) {
                step = -w->speed;
            }

            act->x += step;

            if (ApplyAttackBox(0xB0, act->x, act->y, act->z - 0x800, 0x10, 0x10,
                    8)) {
                m4aSongNumStart(SONG_BTL_MON_HIT00);
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

void task_emy_06_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_06_3(EmyWork* work) {
    EmyReleaseResources(work);
}
