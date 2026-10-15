/**
 * emy_27.c
 * Pirate Enemy
 */

#include "task_descriptors.h"
#include "sprites_emy.h"
#include "enemy_common.h"
#include "songs.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "btl_collision.h"
#include "btl_effect.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy27CommonAnimDefs[3] = {
    { gEmy2700Frames, gEmy2700Anims, gEmy2700Tiles, 0 },
    { gEmy2702Frames, gEmy2702Anims, gEmy2702Tiles, 0 },
    { gEmy2701Frames, gEmy2701Anims, gEmy2701Tiles, 0 },
};

static const AnimDef sEmy27AnimDefs[2] = {
    { gEmy2710Frames, gEmy2710Anims, gEmy2710Tiles, 0 },
    { gEmy2711Frames, gEmy2711Anims, gEmy2711Tiles, 0 },
};

static const EmyDef sEmy27Def = { gEmy27Palette, sEmy27CommonAnimDefs, 192, 130, 20, 20, 64, 32, 64, 10, 0, { ENEMY_PIRATE, 125, 32, 12, 16, 100, 0 } };

TaskDesc gTaskDescEmy27 = {
    "task_emy_27",
    (TaskInitFunc)task_emy_27_0,
    (TaskUpdateFunc)task_emy_27_1,
    (TaskDrawFunc)task_emy_27_2,
    (TaskDestroyFunc)task_emy_27_3,
    sizeof(EmyWork),
};

void task_emy_27_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy27Def, obj);
}

enum Emy27State {
    EMY27_STATE_LUNGE = 18,
    EMY27_STATE_CHASE_SLASH
};

u8 task_emy_27_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 frame;
    s32 dy;
    s32 y;
    s32 tx;
    s32 ty;

    w = work;
    act = &work->actor;

    if (EmyUpdateReaction(work)) {
        GetEnemyTargetPosition(act, NULL, &y, NULL);
        dy = act->y - y;

        if (dy >= 0 ? dy <= 0xFFF : y - act->y <= 0xFFF) {
            work->state = EMY27_STATE_LUNGE;
        } else {
            work->state = EMY27_STATE_CHASE_SLASH;
        }
    }

    switch (work->state) {
    case EMY27_STATE_LUNGE:
        AnimChangeWithDef(sEmy27AnimDefs, &w->anim, 0, 0, w->tiles);

        if (AnimGetFrame(&work->anim) == 1 && work->anim.timer == 0) {
            m4aSongNumStart(SONG_BTL_SWORDFLASH);

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                BgFxStartFlash(act->x - 0xC00, act->y, act->z - 0x2200);
            } else {
                BgFxStartFlash(act->x + 0xC00, act->y, act->z - 0x2200);
            }
        }

        EmyLungeAttack(work, 0x3D, 6, 0x14, 0xC8, 0x20, SONG_BTL_MON_SWORD04, 0x28, 0, 0x14);
        break;
    case EMY27_STATE_CHASE_SLASH:
        AnimChangeWithDef(sEmy27AnimDefs, &w->anim, 1, ANIM_FLAG_LOOP, w->tiles);
        GetEnemyTargetPosition(act, &tx, &ty, NULL);

        if (work->stateTimer % 6 == 0) {
            work->angle = GetAngle(act->x, act->y, tx, ty);
        }

        act->x += gSineTable[work->angle];
        act->y -= gSineTable[work->angle + 0x40];

        if (act->x > tx) {
            act->flags |= BTLOBJ_FLAG_FACING_LEFT;
        } else {
            act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
        }

        frame = AnimGetFrame(&work->anim);

        if (frame == 2 || frame == 5) {
            if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                    ? ApplyAttackBox(0xC7, act->x - 0x1000, act->y, act->z, 0x14,
                        0x14, 0x20)
                    : ApplyAttackBox(0xC7, act->x + 0x1000, act->y, act->z, 0x14,
                        0x14, 0x20)) {
                m4aSongNumStart(SONG_BTL_MON_SWORD03);
            }
        }

        if (work->stateTimer > 0x78) {
            EmyReturnToIdle(work);
        } else {
            work->stateTimer++;
        }

        break;
    }

    return EmyUpdateCommonStates(work);
}

void task_emy_27_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_27_3(EmyWork* work) {
    EmyReleaseResources(work);
}
