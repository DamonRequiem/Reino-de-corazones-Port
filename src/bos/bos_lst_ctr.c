/**
 * bos_lst_ctr.c
 * Marluxia Final Form Projectiles
 */

#include "bos7.h"
#include "sprites_bos7.h"
#include "sprites_bos6.h"
#include "songs.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "bos7_api.h"
#include "btl_collision.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "obj.h"
#include "obj_api.h"
#include <stddef.h>
#include "taskpool.h"
#include "types.h"
#include "enemy_ids.h"

const EmyKind gBosLstCtrEmyKind = { ENEMY_SHADOW, 1, 8, 8, 0, 128, 0 };

static const u32 sBosLstCtrAngles[6][5] = {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 128, 0, 0, 0 },
    { 0, 86, 171, 0, 0 },
    { 0, 64, 128, 192, 0 },
    { 0, 51, 102, 153, 204 },
};

TaskDesc gTaskDescBosLstCtr = {
    "task_bos_lst_ctr",
    (TaskInitFunc)task_bos_lst_ctr_0,
    (TaskUpdateFunc)task_bos_lst_ctr_1,
    (TaskDrawFunc)task_bos_lst_ctr_2,
    (TaskDestroyFunc)task_bos_lst_ctr_3,
    sizeof(LstCtrWork),
};

s32 BosLstCtrSquare(s32 x) {
    return x * x;
}

s32 BosLstCtrSquare2(s32 x) {
    return x * x;
}

enum BosLstCtrState {
    BOS_LST_CTR_STATE_ORBIT,
    BOS_LST_CTR_STATE_DROP,
    BOS_LST_CTR_STATE_LAND,
    BOS_LST_CTR_STATE_SLIDE,
    BOS_LST_CTR_STATE_DONE
};

u8 BosLstCtrIsActive(Task* task) {
    LstCtrWork* work;

    work = task->work;
    return work->state != BOS_LST_CTR_STATE_DONE;
}

s32 BosLstCtrSqrt(s32 n) {
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

void task_bos_lst_ctr_0(LstCtrWork* work, LstCtrArg* arg) {
    work->unk_000 = arg->unk_00;
    work->count = arg->count;
    work->index = arg->index;
    work->state = BOS_LST_CTR_STATE_ORBIT;
    work->step = 0;
    work->timer = 0;
    work->delay = arg->delay;
    work->offsetX = 0;
    work->offsetY = 0;
    work->offsetZ = 0;
    work->curX = arg->x;
    work->curY = arg->y;
    work->curZ = arg->z;
    work->x = arg->x;
    work->y = arg->y;
    work->z = arg->z;
    work->tiles = LoadObjTiles(gBosLstCtrTiles, sizeof(gBosLstCtrTiles));
    work->palette = LoadObjPalette(gBosLstObjPalette, sizeof(gBosLstObjPalette));
    AnimInit(&work->anim, gBosLstCtrAnims, gBosLstCtrFrames);
    AnimStart(&work->anim, 3, ANIM_FLAG_LOOP);
}

u8 task_bos_lst_ctr_1(LstCtrWork* work) {
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    BtlObj* actor;
    s32 timer;

    work->offsetX /= 2;
    work->offsetY /= 2;
    work->offsetZ /= 2;

    switch (work->state) {
    case BOS_LST_CTR_STATE_ORBIT:
        timer = (u16)work->timer + 1;
        work->timer = timer;
        work->delay--;

        if (work->delay <= 0) {
            actor = gBtlWork->actor;
            work->x2 = work->curX - (work->curX - actor->x) / 4;
            work->y2 = actor->y;
            work->z2 = -0x1000;
            work->state = BOS_LST_CTR_STATE_DROP;
            work->step = 0;
            work->timer = 0;
            work->delay = 0;
            WorldToScreen(&x1, &y1, work->x, work->y, work->z);
            WorldToScreen(&x2, &y2, work->x2, work->y2, work->z2);
            work->unk_010 = 0;
            work->duration = (s16)BosLstCtrSqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 9;
        } else {
            work->offsetX =
                (-COS(sBosLstCtrAngles[work->count][work->index] + timer) * 5 >> 6) << 8;
            work->offsetZ =
                ((SIN(sBosLstCtrAngles[work->count][work->index] + timer) * 3 >> 5) - 4) << 8;
        }

        break;
    case BOS_LST_CTR_STATE_DROP:
        work->curX = work->x - (work->x - work->x2) * work->timer / work->duration;
        work->curY = work->y + (work->y2 - work->y) * work->timer / work->duration;
        work->curZ = work->z + (work->z2 - work->z) * work->timer / work->duration;
        work->timer++;

        if (work->timer >= work->duration) {
            work->state = BOS_LST_CTR_STATE_LAND;
            work->step = 0;
            work->timer = 0;
            work->delay = 0;
        }

        if (ApplyAttackBox(0x10F, work->curX, work->curY, work->curZ, 8, 1, 4) != ATTACK_RESULT_NONE) {
            m4aSongNumStart(SONG_EF_DS_ANKOKUPUNCH);
        }

        break;
    case BOS_LST_CTR_STATE_LAND:
        work->timer++;

        if (work->timer > 2) {
            work->state = BOS_LST_CTR_STATE_SLIDE;
            work->step = 0;
            work->timer = 0;
            work->delay = 0;
            work->curX = work->x2;
            work->curY = work->y2;
            work->curZ = work->z2;
            AnimStart(&work->anim, 1, 0);
            m4aSongNumStart(SONG_SND_710);
        }

        break;
    case BOS_LST_CTR_STATE_SLIDE:
        if (work->x > work->x2) {
            work->unk_010 = 0;
            work->curX = work->curX - 0x600;

            if (work->curX < 0x6000) {
                work->state = BOS_LST_CTR_STATE_DONE;
                work->step = 0;
                work->timer = 0;
                work->delay = 0;
            }
        } else {
            work->unk_010 = 0x80;
            work->curX = work->curX + 0x600;

            if (work->curX > 0x19000) {
                work->state = BOS_LST_CTR_STATE_DONE;
                work->step = 0;
                work->timer = 0;
                work->delay = 0;
            }
        }

        work->curZ = work->z2 - ((work->timer >> 2) << 8);

        if (ApplyAttackBox(0x10F, work->curX, work->curY, work->curZ, 8, 4, 4) != ATTACK_RESULT_NONE) {
            m4aSongNumStart(SONG_EF_DS_ANKOKUPUNCH);
        }

        work->timer++;
        break;
    case BOS_LST_CTR_STATE_DONE:
        AnimStart(&work->anim, 2, ANIM_FLAG_LOOP);
        break;
    }

    AnimUpdate(&work->anim);

    return 1;
}

void task_bos_lst_ctr_2(LstCtrWork* work) {
    s16 x;
    s16 y;
    ObjAffine* affine;
    u16 prio;
    u16 depth;
    void* gfx;
    s32 elapsed;

    WorldToScreen(&x, &y, work->curX + work->offsetX, work->curY + work->offsetY,
                  work->curZ + work->offsetZ);
    affine = NULL;
    prio = GetBattleSpritePriorityFlags(work->curY + work->offsetY) | SPRITE_FLAG_BLEND;
    depth = -0x1004 - ((work->curY + work->offsetY) >> 8) * 4;

    switch (work->state) {
    case BOS_LST_CTR_STATE_ORBIT:
        elapsed = work->timer - work->index * 8;

        if (elapsed <= 0) {
            return;
        }

        if (elapsed <= 15) {
            affine = AllocObjAffine(0, Q_8_8(1), elapsed * 16, FALSE);
        }

        break;
    case BOS_LST_CTR_STATE_DROP:
        affine = AllocObjAffine(0, Q_8_8(1) - work->timer * 4, Q_8_8(1) - work->timer * 4, TRUE);
        break;
    case BOS_LST_CTR_STATE_LAND:
        affine = AllocObjAffine(0, Q_8_8(1) - (work->duration - work->timer) * 4,
                                Q_8_8(1) - work->duration * 4, TRUE);
        break;
    default:
        if (work->curX + work->offsetX > work->x2) {
            prio |= SPRITE_FLAG_HFLIP;
        }

        break;
    }

    gfx = AnimGetGfx(&work->anim);
    DrawSprite(x, y, gfx, work->tiles, work->palette, affine, prio, depth);
}

void task_bos_lst_ctr_3(LstCtrWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}
