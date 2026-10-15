/**
 * bos_lst_lsr.c
 * Marluxia Final Form Lasers
 */

#include "bos7.h"
#include "sprites_bos7.h"
#include "sprites_bos6.h"
#include <stdlib.h>
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "bos7_api.h"
#include "btl_collision.h"
#include "obj.h"
#include "obj_api.h"
#include "registration_data.h"
#include "taskpool.h"
#include "types.h"
#include "engine_math.h"

TaskDesc gTaskDescBosLstLsr = {
    "task_bos_lst_lsr",
    (TaskInitFunc)task_bos_lst_lsr_0,
    (TaskUpdateFunc)task_bos_lst_lsr_1,
    (TaskDrawFunc)task_bos_lst_lsr_2,
    (TaskDestroyFunc)task_bos_lst_lsr_3,
    sizeof(LstLsrWork),
};

s32 BosLstLsrSquare(s32 x) {
    return x * x;
}

s32 BosLstLsrSquare2(s32 x) {
    return x * x;
}

s32 BosLstLsrSqrt(s32 n) {
    s32 x;
    s32 root;

    if (n <= 0) {
        return 0;
    }

    x = 1;
    root = n;

    while (x < root) {
        x <<= 1;
        root >>= 1;
    }

    do {
        root = x;
        x = (n / root + root) >> 1;
    } while (x < root);

    return root;
}

enum BosLstLsrState {
    BOS_LST_LSR_STATE_IDLE,
    BOS_LST_LSR_STATE_DELAY,
    BOS_LST_LSR_STATE_TRAVEL,
    BOS_LST_LSR_STATE_IMPACT
};

u8 BosLstLsrIsFiring(Task* task) {
    LstLsrWork* work;
    u8 firing;

    work = task->work;
    firing = FALSE;

    switch (work->state) {
    case BOS_LST_LSR_STATE_TRAVEL:
    case BOS_LST_LSR_STATE_IMPACT:
        firing = TRUE;
        break;
    }

    return firing;
}

void BosLstLsrFire(Task* task, Vec3* origin, Vec3* target, s32 angle, u16 delay) {
    LstLsrWork* work;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;

    work = task->work;
    work->state = BOS_LST_LSR_STATE_DELAY;
    work->angle = angle;
    work->delay = delay;
    work->pos = *origin;
    work->pos2 = *target;
    WorldToScreen(&x1, &y1, work->pos.x, work->pos.y, work->pos.z);
    WorldToScreen(&x2, &y2, work->pos2.x, work->pos2.y, work->pos2.z);
    work->duration = (s16)BosLstLsrSqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 16;

    if (work->duration <= 1) {
        work->duration = 2;
    }

    work->timer = 0;
}

void BosLstLsrStop(Task* task) {
    LstLsrWork* work;

    work = task->work;
    work->state = BOS_LST_LSR_STATE_IDLE;
    work->timer = 0;
    AnimStart(&work->anim, 4, 0);
}

u8 BosLstLsrSpawnFal(LstLsrWork* work) {
    LstFalArg arg;
    u8 spawned;

    spawned = FALSE;

    if (work->kind != BOS_LST_BIT_KIND_BITS) {
        return FALSE;
    }

    if ((s16)*work->falCount <= 31) {
        arg.kind = BOS_LST_FAL_DRIFT;
        arg.x = work->pos2.x;
        arg.y = work->pos2.y;
        arg.z = work->pos2.z;
        arg.facing = *work->facing;
        arg.falCount = work->falCount;
        TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosLstFal, &arg);
        spawned = TRUE;
    }

    return spawned;
}

void task_bos_lst_lsr_0(LstLsrWork* work, LstLsrArg* arg) {
    work->kind = arg->kind;
    work->facing = arg->facing;
    work->falCount = arg->falCount;
    work->state = BOS_LST_LSR_STATE_IDLE;
    work->tiles = LoadObjTiles(gBosLstBitTiles, sizeof(gBosLstBitTiles));
    work->palette = LoadObjPalette(gBosLstObjPalette, sizeof(gBosLstObjPalette));
    AnimInit(&work->anim, gBosLstBitAnims, gBosLstBitFrames);
    AnimStart(&work->anim, 4, 0);
}

u8 task_bos_lst_lsr_1(LstLsrWork* work) {
    switch (work->state) {
    case BOS_LST_LSR_STATE_IDLE:
        break;
    case BOS_LST_LSR_STATE_DELAY:
        work->delay--;

        if (work->delay > 0) {
            break;
        }

        work->state = BOS_LST_LSR_STATE_TRAVEL;
        work->delay = 0;
    case BOS_LST_LSR_STATE_TRAVEL:
        work->timer++;

        if (work->timer >= work->duration) {
            work->state = BOS_LST_LSR_STATE_IMPACT;
            work->timer = 0;
            AnimReset(&work->anim);
            AnimChange(&work->anim, 6, ANIM_FLAG_LOOP);
        }

        break;
    case BOS_LST_LSR_STATE_IMPACT:
        if (work->timer > 15) {
            work->state = BOS_LST_LSR_STATE_IDLE;
            work->timer = 0;
            AnimChange(&work->anim, 4, 0);
        } else {
            ApplyAttackBox(0x10D, work->pos2.x, work->pos2.y, work->pos2.z, 8, 8, 8);

            if ((work->timer & 3) == 0) {
                BosLstLsrSpawnFal(work);
            }

            if (abs(work->pos2.x - gBtlWork->actor->x) < 384) {
                work->pos2.x = gBtlWork->actor->x;
            } else if (work->pos2.x > gBtlWork->actor->x) {
                work->pos2.x = work->pos2.x - 384;
            } else if (work->pos2.x < gBtlWork->actor->x) {
                work->pos2.x = work->pos2.x + 384;
            }

            if (abs(work->pos2.y - gBtlWork->actor->y) < 384) {
                work->pos2.y = gBtlWork->actor->y;
            } else if (work->pos2.y > gBtlWork->actor->y) {
                work->pos2.y = work->pos2.y - 384;
            } else if (work->pos2.y < gBtlWork->actor->y) {
                work->pos2.y = work->pos2.y + 384;
            }

            work->timer++;
        }

        break;
    }

    AnimUpdate(&work->anim);

    return 1;
}

void task_bos_lst_lsr_2(LstLsrWork* work) {
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    u16 depth;
    u16 x;
    u16 y;
    u16 prio;
    void* gfx;
    ObjAffine* affine;

    switch (work->state) {
    case BOS_LST_LSR_STATE_TRAVEL:
        WorldToScreen(&x1, &y1, work->pos2.x, work->pos2.y, work->pos2.z);
        prio = GetBattleSpritePriorityFlags(work->pos2.y);
        depth = -0x1004 - (work->pos2.y >> 8) * 4;
        WorldToScreen(&x2, &y2, work->pos.x, work->pos.y, work->pos.z);
        affine = AllocObjAffineAngle(work->angle, TRUE);
        x = x2 + (x1 - x2) * work->timer / work->duration;
        y = y2 + (y1 - y2) * work->timer / work->duration;
        DrawSprite(x, y, gBosLstBitFrames[13], work->tiles, work->palette,
                   affine, prio, depth);
        break;
    case BOS_LST_LSR_STATE_IMPACT:
        WorldToScreen(&x1, &y1, work->pos2.x, work->pos2.y, work->pos2.z);
        prio = GetBattleSpritePriorityFlags(work->pos2.y);
        depth = -0x1004 - (work->pos2.y >> 8) * 4;
        affine = AllocObjAffine(0, Q_8_8(1) - work->timer * 8, work->timer * 16 + Q_8_8(1), TRUE);
        gfx = AnimGetGfx(&work->anim);
        DrawSprite(x1, y1, gfx, work->tiles, work->palette,
                   affine, prio | SPRITE_FLAG_BLEND, depth);
        break;
    }
}

void task_bos_lst_lsr_3(LstLsrWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}
