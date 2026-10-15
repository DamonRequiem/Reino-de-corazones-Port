/**
 * emy_39.c
 * Fat Bandit Enemy
 */

#include "task_descriptors.h"
#include "display.h"
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
#include "btl_effect.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy39CommonAnimDefs[3] = {
    { gEmy3900Frames, gEmy3900Anims, gEmy3900Tiles, 0 },
    { gEmy3902Frames, gEmy3902Anims, gEmy3902Tiles, 0 },
    { gEmy3901Frames, gEmy3901Anims, gEmy3901Tiles, 0 },
};

static const AnimDef sEmy39AnimDefs[2] = {
    { gEmy3910Frames, gEmy3910Anims, gEmy3910Tiles, 0 },
    { gEmy3911Frames, gEmy3911Anims, gEmy3911Tiles, 0 },
};

static const EmyDef sEmy39Def = { gEmy39Palette, sEmy39CommonAnimDefs, 102, 130, 100, 22, 64, 32, 32, 10, 0, { ENEMY_FAT_BANDIT, 134, 56, 25, 32, 100, EMY_KIND_FLAG_LARGE_BODY } };

TaskDesc gTaskDescEmy39 = {
    "task_emy_39",
    (TaskInitFunc)task_emy_39_0,
    (TaskUpdateFunc)task_emy_39_1,
    (TaskDrawFunc)task_emy_39_2,
    (TaskDestroyFunc)task_emy_39_3,
    sizeof(Emy39Work),
};

void task_emy_39_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy39Def, obj);
}

enum Emy39State {
    EMY39_STATE_FIRE = 18,
    EMY39_STATE_BUMP
};

u8 task_emy_39_1(Emy39Work* work) {
    Emy39Work* w;
    BtlObj* act;
    u16 roll;
    s16 timer;
    s32 y;
    s32 targetX;
    s32 halfX;
    s32 halfY;
    u8 alive;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->base.state = EMY39_STATE_FIRE;
            break;
        case 1:
            work->base.state = EMY39_STATE_BUMP;
            break;
        }
    }

    switch (work->base.state) {
    case EMY39_STATE_FIRE:
        AnimChangeWithDef(sEmy39AnimDefs, &w->base.anim, 0, 0, w->base.tiles);

        if (work->base.stateTimer == 0x30) {
            y = act->y;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                targetX = act->x - 0x6400;
                BgFxStartFire(SPELL_TIER_BASE, act->x - 0x4000, y, act->z - 0x2000, targetX, y, 0, TRUE,
                    0xD6);
            } else {
                targetX = act->x + 0x6400;
                BgFxStartFire(SPELL_TIER_BASE, act->x + 0x4000, y, act->z - 0x2000, targetX, y, 0, FALSE,
                    0xD6);
            }
        }

        if (work->base.stateTimer > 0x30 && BgAnimIsStopped()) {
            EmyReturnToIdle(&work->base);
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY39_STATE_BUMP:
        timer = work->base.stateTimer;

        if (timer == 0) {
            AnimChangeWithDef(sEmy39AnimDefs, &w->base.anim, 1, 0, w->base.tiles);
            w->dashSpeed = 0;
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 0:
            halfX = 24;
            halfY = 20;
            break;
        case 1:
            halfX = 30;
            halfY = 16;
            break;
        case 2:
            halfX = 24;
            halfY = 20;

            if (work->base.anim.timer == 0) {
                w->dashSpeed = 0x200;
            }

            break;
        case 3:
            halfX = 24;
            halfY = 16;
            break;
        case 4:
            halfX = 48;
            halfY = 20;
            break;
        case 5:
            halfX = 30;
            halfY = 16;

            if (work->base.anim.timer == 0) {
                w->dashSpeed = 0x200;
            }

            break;
        case 6:
            halfX = 48;
            halfY = 20;
            break;
        case 7:
        default:
            halfX = 24;
            halfY = 20;
            break;
        }

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            act->x -= w->dashSpeed;
        } else {
            act->x += w->dashSpeed;
        }

        w->dashSpeed -= 0x19;

        if (w->dashSpeed < 0) {
            w->dashSpeed = 0;
        }

        if (ApplyAttackBox(0xD7, act->x, act->y, act->z, halfX, halfY, 0x28)) {
            m4aSongNumStart(SONG_BTL_MON_HIT02);
        }

        if (AnimIsFinished(&work->base.anim)) {
            EmyReturnToIdle(&work->base);
        } else {
            work->base.stateTimer++;
        }

        break;
    }

    alive = EmyUpdateCommonStates(&work->base);

    if ((gBtlWork->actor->x < work->base.actor.x
                && (work->base.actor.flags & BTLOBJ_FLAG_FACING_LEFT))
            || (gBtlWork->actor->x > work->base.actor.x
                && !(work->base.actor.flags & BTLOBJ_FLAG_FACING_LEFT))) {
        work->base.actor.flags |= BTLOBJ_FLAG_GUARD_PHYSICAL;
    } else {
        work->base.actor.flags &= ~BTLOBJ_FLAG_GUARD_PHYSICAL;
    }

    return alive;
}

void task_emy_39_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_39_3(EmyWork* work) {
    EmyReleaseResources(work);
}
