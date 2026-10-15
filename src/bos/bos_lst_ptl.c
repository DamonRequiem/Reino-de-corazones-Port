/**
 * bos_lst_ptl.c
 * Marluxia Final Form Petal Effect
 */

#include "bos7.h"
#include "sprites_bos7.h"
#include "sprites_bos6.h"
#include "anim.h"
#include "battle_actor.h"
#include "engine_math.h"
#include "obj_api.h"
#include <stddef.h>
#include "taskpool.h"
#include "types.h"

TaskDesc gTaskDescBosLstPtl = {
    "task_bos_lst_ptl",
    (TaskInitFunc)task_bos_lst_ptl_0,
    (TaskUpdateFunc)task_bos_lst_ptl_1,
    (TaskDrawFunc)task_bos_lst_ptl_2,
    (TaskDestroyFunc)task_bos_lst_ptl_3,
    sizeof(LstPtlWork),
};

s32 BosLstPtlSquare(s32 x) {
    return x * x;
}

s32 BosLstPtlSquare2(s32 x) {
    return x * x;
}

enum BosLstPtlState {
    BOS_LST_PTL_STATE_WAIT,
    BOS_LST_PTL_STATE_FALL,
    BOS_LST_PTL_STATE_DONE
};

u8 BosLstPtlIsActive(Task* task) {
    LstPtlWork* work;

    work = task->work;
    return work->state != BOS_LST_PTL_STATE_DONE;
}

void task_bos_lst_ptl_0(LstPtlWork* work, LstPtlArg* arg) {
    work->state = BOS_LST_PTL_STATE_WAIT;
    work->step = 0;
    work->timer = 0;
    work->delay = arg->delay;
    work->x = arg->x;
    work->y = arg->y;
    work->wobbleX = 0;
    work->wobbleY = 0;
    work->tiles = LoadObjTiles(gBosLstPtlTiles, sizeof(gBosLstPtlTiles));
    work->palette = LoadObjPalette(gBosLstObjPalette, sizeof(gBosLstObjPalette));
    AnimInit(&work->anim, gBosLstPtlAnims, gBosLstPtlFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
}

u8 task_bos_lst_ptl_1(LstPtlWork* work) {
    u8 alive;

    alive = 1;

    switch (work->state) {
    case BOS_LST_PTL_STATE_WAIT:
        work->delay--;

        if (work->delay <= 0) {
            work->state = BOS_LST_PTL_STATE_FALL;
            work->step = 0;
            work->timer = 0;
            work->delay = 0;
            AnimReset(&work->anim);
            AnimChange(&work->anim, 1, ANIM_FLAG_LOOP);
        }

        break;
    case BOS_LST_PTL_STATE_FALL:
        work->x -= 0x80;
        work->y += 0x100;
        work->wobbleX = -COS(work->timer * 8);
        work->wobbleY = SIN(work->timer * 2);
        work->timer++;

        if ((work->y >> 8) > 0xA8) {
            work->state = BOS_LST_PTL_STATE_DONE;
            work->step = 0;
            work->timer = 0;
            work->delay = 0;
        }

        break;
    case BOS_LST_PTL_STATE_DONE:
        AnimReset(&work->anim);
        AnimChange(&work->anim, 0, ANIM_FLAG_LOOP);
        break;
    }

    AnimUpdate(&work->anim);

    return alive;
}

void task_bos_lst_ptl_2(LstPtlWork* work) {
    u16 x;
    u16 y;
    u16 prio;
    void* gfx;
    u16 depth;

    x = (work->x >> 8) + (work->wobbleX * 12 >> 8);
    y = (work->y >> 8) + (work->wobbleY * 6 >> 8);
    prio = GetBattleSpritePriorityFlags(0x20100);
    depth = 0xE7F8;
    gfx = AnimGetGfx(&work->anim);
    DrawSprite(x, y, gfx, work->tiles, work->palette, NULL, prio, depth);
}

void task_bos_lst_ptl_3(LstPtlWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}
