/**
 * emy_30.c
 * Wyvern Enemy
 */

#include "task_descriptors.h"
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

static const AnimDef sEmy30CommonAnimDefs[3] = {
    { gEmy3000Frames, gEmy3000Anims, gEmy3000Tiles, 0 },
    { gEmy3002Frames, gEmy3002Anims, gEmy3002Tiles, 0 },
    { gEmy3001Frames, gEmy3001Anims, gEmy3001Tiles, 1 },
};

static const AnimDef sEmy30AnimDefs[8] = {
    { gEmy3001Frames, gEmy3001Anims, gEmy3001Tiles, 0 },
    { gEmy3001Frames, gEmy3001Anims, gEmy3001Tiles, 2 },
    { gEmy3010Frames, gEmy3010Anims, gEmy3010Tiles, 0 },
    { gEmy3010Frames, gEmy3010Anims, gEmy3010Tiles, 1 },
    { gEmy3010Frames, gEmy3010Anims, gEmy3010Tiles, 2 },
    { gEmy3011Frames, gEmy3011Anims, gEmy3011Tiles, 0 },
    { gEmy3011Frames, gEmy3011Anims, gEmy3011Tiles, 1 },
    { gEmy3011Frames, gEmy3011Anims, gEmy3011Tiles, 2 },
};

static const EmyDef sEmy30Def = { gEmy30Palette, sEmy30CommonAnimDefs, 1024, 150, 4, 20, 60, 32, 32, 30, 0, { ENEMY_WYVERN, 45, 34, 30, 16, 100, EMY_KIND_FLAG_LARGE_BODY } };

TaskDesc gTaskDescEmy30 = {
    "task_emy_30",
    (TaskInitFunc)task_emy_30_0,
    (TaskUpdateFunc)task_emy_30_1,
    (TaskDrawFunc)task_emy_30_2,
    (TaskDestroyFunc)task_emy_30_3,
    sizeof(EmyWork),
};

void task_emy_30_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy30Def, obj);
    work->actor.z = (GetRandom() % 0x1001) - 0x3000;
    work->idleState = EMY_STATE_HOVER;
}

enum Emy30State {
    EMY30_STATE_BITE_APPROACH = 18,
    EMY30_STATE_BITE,
    EMY30_STATE_BITE_END,
    EMY30_STATE_CHARGE_WINDUP,
    EMY30_STATE_CHARGE,
    EMY30_STATE_CHARGE_END,
    EMY30_STATE_FLY_START,
    EMY30_STATE_FLY_STOP,
    EMY30_STATE_FLY
};

u8 task_emy_30_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 frontX;
    u16 roll;

    w = work;
    act = &work->actor;
    GetEnemyTargetPosition(act, &x, &y, NULL);

    if (EmyUpdateReaction(work)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->state = EMY30_STATE_BITE_APPROACH;
            break;
        case 1:
            work->state = EMY30_STATE_CHARGE_WINDUP;
            break;
        }
    }

    if (work->state == EMY_STATE_HOVER_MOVE) {
        work->state = EMY30_STATE_FLY_START;
        work->stateTimer = 0;
    }

    switch (work->state) {
    case EMY30_STATE_FLY_START:
        AnimChangeWithDef(sEmy30AnimDefs, &w->anim, 0, 0, w->tiles);
        work->vz = 0;

        if (AnimGetFrame(&work->anim) == 1) {
            work->angle = GetAngle(act->x, act->y, work->x, work->y);
            work->speed = work->def->speed;
            act->x += gSineTable[work->angle] * work->speed >> 8;
            act->y += -gSineTable[work->angle + 64] * work->speed >> 8;
        }

        if (AnimIsFinished(&work->anim)) {
            work->stateTimer = 0;
            work->state = EMY30_STATE_FLY;
        }

        break;
    case EMY30_STATE_FLY:
        work->vz = 0;
        AnimChangeWithDef(w->def->animDef, &w->anim, 2, ANIM_FLAG_LOOP | ANIM_FLAG_RANDOM_START, w->tiles);

        if (gBtlWork->flags & BTL_FLAG_ENEMY_MOVE_ENABLED) {
            if (act->x > work->x) {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }

            work->angle = GetAngle(act->x, act->y, work->x, work->y);
            work->speed = work->def->speed;
            act->x += gSineTable[work->angle] * work->speed >> 8;
            act->y += -gSineTable[work->angle + 64] * work->speed >> 8;
            act->z += (work->hoverZ - act->z) >> 3;

            if ((work->flags & EMY_FLAG_AT_FIELD_EDGE)
                || ((act->x - work->x >= 0
                        ? act->x - work->x
                        : work->x - act->x) <= 0xFFF
                    && (act->y - work->y >= 0
                        ? act->y - work->y
                        : work->y - act->y) <= 0xFFF)) {
                work->state = EMY30_STATE_FLY_STOP;
                work->stateTimer = 0;
            } else {
                work->stateTimer++;
            }
        }

        break;
    case EMY30_STATE_FLY_STOP:
        AnimChangeWithDef(sEmy30AnimDefs, &w->anim, 1, 0, w->tiles);
        work->vz = 0;
        act->x += gSineTable[work->angle] * work->speed >> 8;
        act->y += -gSineTable[work->angle + 64] * work->speed >> 8;
        work->speed -= 25;

        if (work->speed < 0) {
            work->speed = 0;
        }

        if (AnimIsFinished(&work->anim)) {
            work->stateTimer = 0;
            work->state = EMY_STATE_HOVER;
        }

        break;
    case EMY30_STATE_BITE_APPROACH: {
    s32 currentX;
    s32 targetX;
        AnimChangeWithDef(sEmy30AnimDefs, &w->anim, 2, 0, w->tiles);
        work->vz = 0;
        act->z += (-0x4000 - act->z) >> 3;
        act->y += (y - act->y) >> 3;

        currentX = act->x;
        targetX = x;

        if (currentX < targetX) {
            act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            frontX = currentX + 0x1400;
        } else {
            act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            frontX = currentX - 0x1400;
        }

        act->x = currentX + ((targetX - frontX) >> 3);

        if (AnimIsFinished(&work->anim)) {
            work->state = EMY30_STATE_BITE;
            work->stateTimer = 0;
        }

        break;
    }
    case EMY30_STATE_BITE: {
    s32 currentX;
    s32 targetX;
        AnimChangeWithDef(sEmy30AnimDefs, &w->anim, 3, ANIM_FLAG_LOOP, w->tiles);
        work->vz = 0;
        act->z += (-0x2000 - act->z) >> 3;
        act->y += (y - act->y) >> 4;

        currentX = act->x;
        targetX = x;

        if (currentX < targetX) {
            act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            frontX = currentX + 0x1400;
        } else {
            act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            frontX = currentX - 0x1400;
        }

        act->x = currentX + ((targetX - frontX) >> 3);

        if (work->anim.timer == 0) {
            switch (AnimGetFrame(&work->anim)) {
            case 1:
            case 3:
                MakeOpponentsHittable();

                if (ApplyAttackBox(0xCD, act->x, act->y, act->z, 12, 12, 12)) {
                    m4aSongNumStart(SONG_BTL_KAMITUKI);
                }

                break;
            }
        }

        if (work->stateTimer > 100) {
            work->stateTimer = 0;
            work->state = EMY30_STATE_BITE_END;
        } else {
            work->stateTimer++;
        }

        break;
    }
    case EMY30_STATE_BITE_END:
        AnimChangeWithDef(sEmy30AnimDefs, &w->anim, 4, 0, w->tiles);
        work->vz = 0;

        if (AnimIsFinished(&work->anim)) {
            EmyReturnToIdle(work);
        }

        break;
    case EMY30_STATE_CHARGE_WINDUP:
        work->vz = 0;

        if (work->stateTimer == 0) {
            AnimChangeWithDef(sEmy30AnimDefs, &w->anim, 5, 0, w->tiles);

            if (act->x > 0x10000) {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
                work->x = gBtlWork->xMax * 256;
            } else {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
                work->x = gBtlWork->xMin * 256;
            }
        }

        act->x += (work->x - act->x) >> 4;
        act->y += (y - act->y) >> 4;
        act->z += (-0x800 - act->z) >> 4;

        if (AnimIsFinished(&work->anim) && (work->flags & EMY_FLAG_AT_FIELD_EDGE)) {
            work->stateTimer = 0;
            work->state = EMY30_STATE_CHARGE;
            work->speed = 0;
        } else {
            work->stateTimer++;
        }

        break;
    case EMY30_STATE_CHARGE:
        AnimChangeWithDef(sEmy30AnimDefs, &w->anim, 6, ANIM_FLAG_LOOP, w->tiles);
        work->vz = 0;
        work->speed += 38;
        act->y += (y - act->y) >> 4;
        act->z += (-0x800 - act->z) >> 4;

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            if (ApplyAttackBox(0xCE, act->x - 0x1400, act->y, act->z, 12, 12, 12)) {
                m4aSongNumStart(SONG_BTL_MON_HIT03);
            }

            act->x -= work->speed;

            if (act->x < (gBtlWork->xMin + 32) * 256) {
                work->state = EMY30_STATE_CHARGE_END;
                work->stateTimer = 0;
            }
        } else {
            if (ApplyAttackBox(0xCE, act->x + 0x1400, act->y, act->z, 12, 12, 12)) {
                m4aSongNumStart(SONG_BTL_MON_HIT03);
            }

            act->x += work->speed;

            if (act->x > (gBtlWork->xMax - 32) * 256) {
                work->state = EMY30_STATE_CHARGE_END;
                work->stateTimer = 0;
            }
        }

        break;
    case EMY30_STATE_CHARGE_END:
        AnimChangeWithDef(sEmy30AnimDefs, &w->anim, 7, 0, w->tiles);
        work->vz = 0;
        work->speed -= 128;

        if (work->speed < 0) {
            work->speed = 0;
        }

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            act->x -= work->speed;
        } else {
            act->x += work->speed;
        }

        if (AnimIsFinished(&work->anim)) {
            EmyReturnToIdle(work);
        }

        break;
    }

    return EmyUpdateCommonStates(work);
}

void task_emy_30_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_30_3(EmyWork* work) {
    EmyReleaseResources(work);
}
