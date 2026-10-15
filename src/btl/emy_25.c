/**
 * emy_25.c
 * Wight Knight Enemy
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
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy25CommonAnimDefs[3] = {
    { gEmy2500Frames, gEmy2500Anims, gEmy2500Tiles, 0 },
    { gEmy2502Frames, gEmy2502Anims, gEmy2502Tiles, 0 },
    { gEmy2501Frames, gEmy2501Anims, gEmy2501Tiles, 0 },
};

static const AnimDef sEmy25AnimDefs[2] = {
    { gEmy2510Frames, gEmy2510Anims, gEmy2510Tiles, 0 },
    { gEmy2511Frames, gEmy2511Anims, gEmy2511Tiles, 0 },
};

static const EmyDef sEmy25Def = { gEmy25Palette, sEmy25CommonAnimDefs, 253, 130, 20, 20, 24, 16, 16, 3, 0, { ENEMY_WIGHT_KNIGHT, 79, 40, 12, 32, 100, 0 } };

TaskDesc gTaskDescEmy25 = {
    "task_emy_25",
    (TaskInitFunc)task_emy_25_0,
    (TaskUpdateFunc)task_emy_25_1,
    (TaskDrawFunc)task_emy_25_2,
    (TaskDestroyFunc)task_emy_25_3,
    sizeof(EmyWork),
};

void task_emy_25_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy25Def, obj);
}

enum Emy25State {
    EMY25_STATE_SWIPE = 18,
    EMY25_STATE_SPIN_ATTACK
};

u8 task_emy_25_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 roll;
    s32 dx;
    u16 dy;
    s16 spinDx;
    u16 spinDy;

    w = work;
    act = &work->actor;

    if (EmyUpdateReaction(work)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->state = EMY25_STATE_SWIPE;
            break;
        case 1:
            work->state = EMY25_STATE_SPIN_ATTACK;
            break;
        }
    }

    switch (work->state) {
    case EMY25_STATE_SWIPE:
        AnimChangeWithDef(sEmy25AnimDefs, &w->anim, 0, 0, w->tiles);

        if (AnimIsFinished(&work->anim)) {
            EmyReturnToIdle(work);
        } else if (work->anim.timer == 0) {
            dx = 0;
            dy = 0;

            switch (work->anim.frame) {
            case 2:
                dx = 5;
                dy = -1;
                break;
            case 3:
                dx = 5;
                dy = -2;

                if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0xC3, act->x - 0x2800, act->y, act->z,
                            0x10, 0x10, 0x20)
                        : ApplyAttackBox(0xC3, act->x + 0x2800, act->y, act->z,
                            0x10, 0x10, 0x20)) {
                    m4aSongNumStart(SONG_BTL_HANE_HIT);
                }

                break;
            case 4:
                dx = 5;
                dy = -1;
                break;
            case 5:
                dx = 6;
                dy = -2;
                break;
            case 6:
                dx = 6;
                dy = -1;
                break;
            case 7:
                dx = 1;
                dy = -1;
                break;
            }

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x -= dx << 8;
            } else {
                act->x += dx << 8;
            }

            act->y -= (s16)dy << 8;
        }

        break;
    case EMY25_STATE_SPIN_ATTACK:
        AnimChangeWithDef(sEmy25AnimDefs, &w->anim, 1, 0, w->tiles);

        if (AnimIsFinished(&work->anim)) {
            EmyReturnToIdle(work);
        } else if (work->anim.timer == 0) {
            spinDx = 0;
            spinDy = 0;

            switch (work->anim.frame) {
            case 8:
                spinDx = 4;
                break;
            case 9:
                spinDx = 2;
                break;
            case 10:
                spinDx = 2;
                spinDy = -1;
                break;
            case 11:
                spinDx = 4;
                break;
            case 12:
                spinDx = 7;
                spinDy = -2;
                break;
            case 13:
                spinDx = 1;
                spinDy = -2;
                break;
            case 26:
                spinDx = -5;
                spinDy = 1;
                break;
            case 27:
                spinDx = -15;
                spinDy = 4;
                break;
            }

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x -= spinDx << 8;
            } else {
                act->x += spinDx << 8;
            }

            act->y -= (s16)spinDy << 8;

            if (work->anim.frame >= 8 && work->anim.frame <= 22) {
                if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0xC4, act->x, act->y, act->z, 0x30, 0x30,
                            0x20)
                        : ApplyAttackBox(0xC4, act->x, act->y, act->z, 0x30, 0x30,
                            0x20)) {
                    m4aSongNumStart(SONG_BTL_MON_HIT00);
                }
            }
        }

        break;
    }

    return EmyUpdateCommonStates(work);
}

void task_emy_25_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_25_3(EmyWork* work) {
    EmyReleaseResources(work);
}
