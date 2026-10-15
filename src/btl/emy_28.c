/**
 * emy_28.c
 * Air Pirate Enemy
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
#include "btl_effect.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy28CommonAnimDefs[3] = {
    { gEmy2800Frames, gEmy2800Anims, gEmy2800Tiles, 0 },
    { gEmy2802Frames, gEmy2802Anims, gEmy2802Tiles, 0 },
    { gEmy2801Frames, gEmy2801Anims, gEmy2801Tiles, 1 },
};

static const AnimDef sEmy28AnimDefs[4] = {
    { gEmy2810Frames, gEmy2810Anims, gEmy2810Tiles, 0 },
    { gEmy2811Frames, gEmy2811Anims, gEmy2811Tiles, 0 },
    { gEmy2801Frames, gEmy2801Anims, gEmy2801Tiles, 0 },
    { gEmy2801Frames, gEmy2801Anims, gEmy2801Tiles, 2 },
};

static const EmyDef sEmy28Def = { gEmy28Palette, sEmy28CommonAnimDefs, 1024, 150, 4, 20, 40, 24, 16, 25, 0, { ENEMY_AIR_PIRATE, 45, 48, 8, 16, 100, EMY_KIND_FLAG_LARGE_BODY } };

TaskDesc gTaskDescEmy28 = {
    "task_emy_28",
    (TaskInitFunc)task_emy_28_0,
    (TaskUpdateFunc)task_emy_28_1,
    (TaskDrawFunc)task_emy_28_2,
    (TaskDestroyFunc)task_emy_28_3,
    sizeof(Emy28Work),
};

void task_emy_28_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy28Def, obj);
    work->actor.z = (GetRandom() % 0x1001) - 0x3000;
    work->idleState = EMY_STATE_HOVER;
}

enum Emy28State {
    EMY28_STATE_RISING_LUNGE = 18,
    EMY28_STATE_DIVE_LUNGE,
    EMY28_STATE_FLY_START,
    EMY28_STATE_FLY_STOP,
    EMY28_STATE_FLY
};

u8 task_emy_28_1(Emy28Work* work) {
    Emy28Work* w;
    BtlObj* act;
    u16 roll;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->base.state = EMY28_STATE_RISING_LUNGE;
            break;
        case 1:
            work->base.state = EMY28_STATE_DIVE_LUNGE;
            break;
        }

        w->hitFrame = 0xEFFF;
    }

    if (work->base.state == EMY_STATE_HOVER_MOVE) {
        work->base.state = EMY28_STATE_FLY_START;
        work->base.stateTimer = 0;
    }

    switch (work->base.state) {
    case EMY28_STATE_FLY_START:
        AnimChangeWithDef(sEmy28AnimDefs, &w->base.anim, 2, 0, w->base.tiles);
        work->base.vz = 0;

        if (AnimGetFrame(&work->base.anim) == 1) {
            work->base.angle = GetAngle(act->x, act->y, work->base.x,
                work->base.y);
            work->base.speed = work->base.def->speed;
            act->x += gSineTable[work->base.angle] * work->base.speed >> 8;
            act->y += -gSineTable[work->base.angle + 64] * work->base.speed
                >> 8;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = EMY28_STATE_FLY;
        }

        break;
    case EMY28_STATE_FLY:
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
                work->base.state = EMY28_STATE_FLY_STOP;
                work->base.stateTimer = 0;
                break;
            }

            work->base.stateTimer++;
        }

        break;
    case EMY28_STATE_FLY_STOP:
        AnimChangeWithDef(sEmy28AnimDefs, &w->base.anim, 3, 0, w->base.tiles);
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
    case EMY28_STATE_RISING_LUNGE:
        AnimChangeWithDef(sEmy28AnimDefs, &w->base.anim, 0, 0, w->base.tiles);

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

        if (EmyLungeAttack(&work->base, 22, 10, 20, 201, 32, SONG_BTL_MON_HIT00, 16, -40, 32)
                == EMY_LUNGE_HIT) {
            w->hitFrame = work->base.stateTimer;
        }

        break;
    case EMY28_STATE_DIVE_LUNGE:
        AnimChangeWithDef(sEmy28AnimDefs, &w->base.anim, 1, 0, w->base.tiles);

        if (work->base.stateTimer <= 34) {
            work->base.vz = 0;
            act->z += (-0x4000 - act->z) >> 3;
        } else if (work->base.stateTimer == 35) {
            work->base.vz = 0x300;
        }

        if (work->base.anim.timer == 0 && AnimGetFrame(&work->base.anim) == 1) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                BgFxStartFlash(act->x + 0x1000, act->y, act->z - 0x3200);
            } else {
                BgFxStartFlash(act->x - 0x1000, act->y, act->z - 0x3200);
            }

            m4aSongNumStart(SONG_BTL_SWORDFLASH);
        }

        if (EmyLungeAttack(&work->base, 35, 10, 14, 202, 32, SONG_BTL_MON_HIT04, 24, 32, 16)
                == EMY_LUNGE_HIT) {
            w->hitFrame = work->base.stateTimer;
        }

        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_28_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_28_3(EmyWork* work) {
    EmyReleaseResources(work);
}
