/**
 * emy_38.c
 * Large Body Enemy
 */

#include "task_descriptors.h"
#include "sprites_emy.h"
#include "btl_api.h"
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
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy38CommonAnimDefs[3] = {
    { gEmy3800Frames, gEmy3800Anims, gEmy3800Tiles, 0 },
    { gEmy3802Frames, gEmy3802Anims, gEmy3802Tiles, 0 },
    { gEmy3801Frames, gEmy3801Anims, gEmy3801Tiles, 0 },
};

static const AnimDef sEmy38AnimDefs[2] = {
    { gEmy3811Frames, gEmy3811Anims, gEmy3811Tiles, 0 },
    { gEmy3810Frames, gEmy3810Anims, gEmy3810Tiles, 0 },
};

static const EmyDef sEmy38Def = { gEmy38Palette, sEmy38CommonAnimDefs, 76, 130, 80, 22, 64, 32, 32, 10, 0, { ENEMY_LARGE_BODY, 112, 56, 25, 32, 100, EMY_KIND_FLAG_LARGE_BODY } };

TaskDesc gTaskDescEmy38 = {
    "task_emy_38",
    (TaskInitFunc)task_emy_38_0,
    (TaskUpdateFunc)task_emy_38_1,
    (TaskDrawFunc)task_emy_38_2,
    (TaskDestroyFunc)task_emy_38_3,
    sizeof(EmyWork),
};

void task_emy_38_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy38Def, obj);
}

enum Emy38State {
    EMY38_STATE_LUNGE = 18,
    EMY38_STATE_STOMP
};

u8 task_emy_38_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 roll;
    u8 alive;

    w = work;
    act = &work->actor;

    if (EmyUpdateReaction(work)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->state = EMY38_STATE_LUNGE;
            break;
        case 1:
            work->state = EMY38_STATE_STOMP;
            break;
        }
    }

    switch (work->state) {
    case EMY38_STATE_LUNGE:
        AnimChangeWithDef(sEmy38AnimDefs, &w->anim, 0, 0, w->tiles);
        EmyLungeAttack(work, 0x1E, 0x14, 0x2D, 0xD4, 0x32, SONG_BTL_MON_HIT01, 0, 0, 0x18);

        if (work->stateTimer == 0x1E) {
            work->vz = -0x300;
        }

        break;
    case EMY38_STATE_STOMP:
        AnimChangeWithDef(sEmy38AnimDefs, &w->anim, 1, 0, w->tiles);

        if (work->stateTimer == 0x3F) {
            ApplyAttackBox(0xD5, act->x, act->y, act->z, 0x100, 0x100, 1);
            m4aSongNumStart(SONG_BTL_LB_RUMB);
            BtlMapStartShake();
        }

        if (AnimIsFinished(&work->anim)) {
            EmyReturnToIdle(work);
        } else {
            work->stateTimer++;
        }

        break;
    }

    alive = EmyUpdateCommonStates(work);

    if ((gBtlWork->actor->x < work->actor.x && (work->actor.flags & BTLOBJ_FLAG_FACING_LEFT)) ||
            (gBtlWork->actor->x > work->actor.x &&
                !(work->actor.flags & BTLOBJ_FLAG_FACING_LEFT))) {
        work->actor.flags |= BTLOBJ_FLAG_GUARD_PHYSICAL;
    } else {
        work->actor.flags &= ~BTLOBJ_FLAG_GUARD_PHYSICAL;
    }

    return alive;
}

void task_emy_38_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_38_3(EmyWork* work) {
    EmyReleaseResources(work);
}
