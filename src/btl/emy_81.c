/**
 * emy_81.c
 * Tornado Step Enemy
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
#include "engine_math.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy81CommonAnimDefs[3] = {
    { gEmy8100Frames, gEmy8100Anims, gEmy8100Tiles, 0 },
    { gEmy8102Frames, gEmy8102Anims, gEmy8102Tiles, 0 },
    { gEmy8100Frames, gEmy8100Anims, gEmy8100Tiles, 0 },
};

static const AnimDef sEmy81AnimDefs[5] = {
    { gEmy8110Frames, gEmy8110Anims, gEmy8110Tiles, 0 },
    { gEmy8111Frames, gEmy8111Anims, gEmy8111Tiles, 0 },
    { gEmy8105Frames, gEmy8105Anims, gEmy8105Tiles, 0 },
    { gEmy8105Frames, gEmy8105Anims, gEmy8105Tiles, 1 },
    { gEmy8105Frames, gEmy8105Anims, gEmy8105Tiles, 2 },
};

static const EmyDef sEmy81Def = { gEmy81Palette, sEmy81CommonAnimDefs, 128, 130, 20, 15, 64, 32, 32, 10, 0, { ENEMY_TORNADO_STEP, 66, 27, 13, 16, 100, 0 } };

TaskDesc gTaskDescEmy81 = {
    "task_emy_81",
    (TaskInitFunc)task_emy_81_0,
    (TaskUpdateFunc)task_emy_81_1,
    (TaskDrawFunc)task_emy_81_2,
    (TaskDestroyFunc)task_emy_81_3,
    sizeof(Emy81Work),
};

void task_emy_81_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy81Def, obj);
}

static inline s32 EmyFacingX(BtlObj* actor, s32 offset) {
    return actor->flags & BTLOBJ_FLAG_FACING_LEFT ? actor->x - offset : actor->x + offset;
}

enum Emy81State {
    EMY81_STATE_LEAP_ATTACK = 18,
    EMY81_STATE_DASH_ATTACK,
    EMY81_STATE_TAKEOFF,
    EMY81_STATE_FLY_OVER,
    EMY81_STATE_LAND
};

u8 task_emy_81_1(Emy81Work* work) {
    Emy81Work* w;
    BtlObj* act;
    u16 roll;
    u16 frame;
    u16 idleFrame;
    s32 step;
    s32 hitX;
    s32 pivotX;
    s32 z;
    s32 pivotY;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->base.state = EMY81_STATE_LEAP_ATTACK;
            break;
        case 1:
            work->base.state = EMY81_STATE_DASH_ATTACK;
            break;
        }
    }

    switch (work->base.state) {
    case EMY_STATE_IDLE:
    case EMY_STATE_WALK:
        idleFrame = AnimGetGfxIndex(&work->base.anim);

        if ((idleFrame == 2 || idleFrame == 6) && work->base.anim.timer == 0) {
            work->base.vz = -0x133;
        }

        if (GetRandom() % 200 == 0) {
            work->base.state = EMY81_STATE_TAKEOFF;
            work->base.stateTimer = 0;
            w->speedX = 0;
        }

        break;
    case EMY81_STATE_TAKEOFF:
        AnimChangeWithDef(sEmy81AnimDefs, &w->base.anim, 2, 0, w->base.tiles);

        step = (-0x2800 - act->z) >> 4;

        if (step < -w->speedX) {
            w->speedX += 25;
        } else {
            w->speedX = -step;
        }

        work->base.vz = 0;

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = EMY81_STATE_FLY_OVER;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY81_STATE_FLY_OVER:
        if (work->base.stateTimer == 0) {
            GetEnemyTargetPosition(act, &pivotX, &pivotY, NULL);
            AnimChangeWithDef(sEmy81AnimDefs, &w->base.anim, 3, ANIM_FLAG_LOOP, w->base.tiles);
            w->targetX = (pivotX * 2) - act->x;
            w->targetY = (pivotY * 2) - act->y;
            w->speedX = 0;
            w->speedY = 0;
        }

        work->base.vz = 0;

        {
            s32 sample = SIN((u16)work->base.stateTimer * 4) * 10;
            s32 current = act->z;

            z = current + 0x2800;
            act->z = current + ((sample - z) >> 3);
        }

        step = (w->targetX - act->x) >> 4;

        if (step > w->speedX) {
            step = w->speedX;
            w->speedX += 51;
        } else if (step < -w->speedX) {
            step = -w->speedX;
            w->speedX += 51;
        } else {
            w->speedX = step < 0 ? -step : step;
        }

        act->x += step;
        step = (w->targetY - act->y) >> 4;

        if (step > w->speedY) {
            step = w->speedY;
            w->speedY = step + 2;
        } else if (step < -w->speedY) {
            step = -w->speedY;
            w->speedY += 2;
        } else {
            w->speedY = step < 0 ? -step : step;
        }

        act->y += step;

        if ((work->base.flags & EMY_FLAG_AT_FIELD_EDGE)
                || ((w->targetX - act->x < 0
                        ? act->x - w->targetX
                        : w->targetX - act->x) <= 0x7FF
                    && (w->targetY - act->y < 0
                        ? act->y - w->targetY
                        : w->targetY - act->y) <= 0x7FF)) {
            work->base.state = EMY81_STATE_LAND;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY81_STATE_LAND:
        AnimChangeWithDef(sEmy81AnimDefs, &w->base.anim, 4, 0, w->base.tiles);
        work->base.vz -= 25;

        if (act->z >= act->groundZ) {
            work->base.state = work->base.idleState;
            work->base.stateTimer = 0;
        }

        break;
    case EMY81_STATE_LEAP_ATTACK:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sEmy81AnimDefs, &w->base.anim, 0, 0, w->base.tiles);
        }

        {
            s32 currentX;
            s32 targetX;
            s32 adjustedX;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                targetX = 0x3000;
                currentX = act->x;
                adjustedX = currentX + targetX;
            } else {
                targetX = -0x3000;
                currentX = act->x;
                adjustedX = currentX + targetX;
            }

            targetX = act->originX;
            targetX -= adjustedX;
            targetX >>= 4;
            currentX += targetX;
            act->x = currentX;
        }

        frame = AnimGetFrame(&work->base.anim);

        if (frame >= 3 && frame <= 6) {
            work->base.vz = 0;
        }

        switch (frame) {
        case 1:
            if (work->base.anim.timer == 0) {
                work->base.vz = -0x400;
            }

            break;
        case 3:
            hitX = EmyFacingX(act, 0x1600);

            if (ApplyAttackBox(0xDC, hitX, act->y, act->z + 0x800, 10, 10, 10)) {
                m4aSongNumStart(SONG_BTL_MON_HIT04);
            }

            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            EmyReturnToIdle(&work->base);
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY81_STATE_DASH_ATTACK:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sEmy81AnimDefs, &w->base.anim, 1, 0, w->base.tiles);
        }

        {
            s32 currentX;
            s32 targetX;
            s32 adjustedX;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                targetX = 0x4600;
                currentX = act->x;
                adjustedX = currentX + targetX;
            } else {
                targetX = -0x4600;
                currentX = act->x;
                adjustedX = currentX + targetX;
            }

            targetX = act->originX;
            targetX -= adjustedX;
            targetX >>= 4;
            currentX += targetX;
            act->x = currentX;
        }

        frame = AnimGetFrame(&work->base.anim);

        if (frame == 4) {
            s32 centerX = EmyFacingX(act, 0);

            if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                    ? ApplyAttackBox(0xDD, centerX - 0x1800, act->y, act->z,
                        0x10, 0x10, 10)
                    : ApplyAttackBox(0xDD, centerX + 0x1800, act->y, act->z,
                        0x10, 0x10, 10)) {
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

void task_emy_81_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_81_3(EmyWork* work) {
    EmyReleaseResources(work);
}
