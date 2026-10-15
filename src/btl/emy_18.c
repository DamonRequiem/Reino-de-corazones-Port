/**
 * emy_18.c
 * Air Soldier Enemy
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
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy18CommonAnimDefs[3] = {
    { gEmy1800Frames, gEmy1800Anims, gEmy1800Tiles, 0 },
    { gEmy1802Frames, gEmy1802Anims, gEmy1802Tiles, 0 },
    { gEmy1801Frames, gEmy1801Anims, gEmy1801Tiles, 1 },
};

static const AnimDef sEmy18AnimDefs[4] = {
    { gEmy1810Frames, gEmy1810Anims, gEmy1810Tiles, 0 },
    { gEmy1811Frames, gEmy1811Anims, gEmy1811Tiles, 0 },
    { gEmy1801Frames, gEmy1801Anims, gEmy1801Tiles, 0 },
    { gEmy1801Frames, gEmy1801Anims, gEmy1801Tiles, 2 },
};

static const EmyDef sEmy18Def = { gEmy18Palette, sEmy18CommonAnimDefs, 768, 150, 4, 20, 40, 24, 16, 10, 0, { ENEMY_AIR_SOLDIER, 45, 40, 8, 16, 100, 0 } };

TaskDesc gTaskDescEmy18 = {
    "task_emy_18",
    (TaskInitFunc)task_emy_18_0,
    (TaskUpdateFunc)task_emy_18_1,
    (TaskDrawFunc)task_emy_18_2,
    (TaskDestroyFunc)task_emy_18_3,
    sizeof(Emy18Work),
};

void task_emy_18_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy18Def, obj);
    work->actor.z = (GetRandom() % 0x1001) - 0x3000;
    work->idleState = EMY_STATE_HOVER;
}

enum Emy18State {
    EMY18_STATE_DIVE_LUNGE = 18,
    EMY18_STATE_RISING_LUNGE,
    EMY18_STATE_FLY_START,
    EMY18_STATE_FLY_STOP,
    EMY18_STATE_FLY
};

u8 task_emy_18_1(Emy18Work* work) {
    Emy18Work* w;
    BtlObj* act;
    u16 roll;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->base.state = EMY18_STATE_DIVE_LUNGE;
            break;
        case 1:
            work->base.state = EMY18_STATE_RISING_LUNGE;
            break;
        }

        w->hitFrame = 0xEFFF;
    }

    if (work->base.state == EMY_STATE_HOVER_MOVE) {
        work->base.state = EMY18_STATE_FLY_START;
        work->base.stateTimer = 0;
    }

    switch (work->base.state) {
    case EMY18_STATE_FLY_START:
        AnimChangeWithDef(sEmy18AnimDefs, &w->base.anim, 2, 0, w->base.tiles);
        work->base.vz = 0;

        if (AnimGetFrame(&work->base.anim) == 5) {
            work->base.angle = GetAngle(act->x, act->y, work->base.x,
                work->base.y);
            work->base.speed = work->base.def->speed;
            act->x += gSineTable[work->base.angle] * work->base.speed >> 8;
            act->y += -gSineTable[work->base.angle + 64] * work->base.speed
                >> 8;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = EMY18_STATE_FLY;
        }

        break;
    case EMY18_STATE_FLY:
        work->base.vz = 0;
        AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 2, ANIM_FLAG_LOOP | ANIM_FLAG_RANDOM_START,
            w->base.tiles);

        if (gBtlWork->flags & BTL_FLAG_ENEMY_MOVE_ENABLED) {
            if (act->x > work->base.x) {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }

            work->base.angle = GetAngle(act->x, act->y, work->base.x,
                work->base.y);
            work->base.speed = work->base.def->speed;
            act->x += gSineTable[work->base.angle] * work->base.speed >> 8;
            act->y += -gSineTable[work->base.angle + 64] * work->base.speed
                >> 8;
            act->z += (work->base.hoverZ - act->z) >> 3;

            if ((work->base.flags & EMY_FLAG_AT_FIELD_EDGE) ||
                    ((act->x - work->base.x >= 0
                    ? act->x - work->base.x <= 0xFFF
                    : work->base.x - act->x <= 0xFFF) &&
                    (act->y - work->base.y >= 0
                        ? act->y - work->base.y <= 0xFFF
                        : work->base.y - act->y <= 0xFFF))) {
                work->base.state = EMY18_STATE_FLY_STOP;
                work->base.stateTimer = 0;
                break;
            }

            work->base.stateTimer++;
        }

        break;
    case EMY18_STATE_FLY_STOP:
        AnimChangeWithDef(sEmy18AnimDefs, &w->base.anim, 3, 0, w->base.tiles);
        work->base.vz = 0;
        act->x += gSineTable[work->base.angle] * work->base.speed >> 8;
        act->y += -gSineTable[work->base.angle + 64] * work->base.speed >> 8;
        work->base.speed -= 25;

        if (work->base.speed < 0) {
            work->base.speed = 0;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = EMY_STATE_HOVER;
        }

        break;
    case EMY18_STATE_DIVE_LUNGE:
        AnimChangeWithDef(sEmy18AnimDefs, &w->base.anim, 0, 0, w->base.tiles);

        if (work->base.stateTimer <= 29) {
            work->base.vz = 0;
            act->z += (-0x3500 - act->z) >> 3;
        } else if (work->base.stateTimer == 30) {
            work->base.vz = 0x300;
        }

        if (EmyLungeAttack(&work->base, 30, 10, 6, 185, 32, SONG_BTL_MON_HIT02, 24, -10, 16)
                == EMY_LUNGE_HIT) {
            w->hitFrame = work->base.stateTimer;
        }

        break;
    case EMY18_STATE_RISING_LUNGE:
        AnimChangeWithDef(sEmy18AnimDefs, &w->base.anim, 1, 0, w->base.tiles);

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 0:
                work->base.vz = 0x300;
                break;
            case 3:
                work->base.vz = -0x600;
                break;
            }
        }

        if (EmyLungeAttack(&work->base, 21, 8, 7, 186, 32, SONG_BTL_MON_HIT00, 16, -30, 16)
                == EMY_LUNGE_HIT) {
            w->hitFrame = work->base.stateTimer;
        }

        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_18_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_18_3(EmyWork* work) {
    EmyReleaseResources(work);
}
