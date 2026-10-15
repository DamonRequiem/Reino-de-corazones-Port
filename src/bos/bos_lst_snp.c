/**
 * bos_lst_snp.c
 * Marluxia Final Form Broken Part
 */

#include "bos7.h"
#include "sprites_bos7.h"
#include "sprites_bos6.h"
#include "songs.h"
#include "anim.h"
#include "battle_actor.h"
#include "bos7_api.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"

TaskDesc gTaskDescBosLstSnp = {
    "task_bos_lst_snp",
    (TaskInitFunc)task_bos_lst_snp_0,
    (TaskUpdateFunc)task_bos_lst_snp_1,
    (TaskDrawFunc)task_bos_lst_snp_2,
    (TaskDestroyFunc)task_bos_lst_snp_3,
    sizeof(LstSnpWork),
};

s32 BosLstSnpSquare(s32 x) {
    return x * x;
}

s32 BosLstSnpSquare2(s32 x) {
    return x * x;
}

void task_bos_lst_snp_0(LstSnpWork* work, LstSnpArg* arg) {
    work->angle = 0;
    work->x = arg->x;
    work->y = arg->y;
    work->z = arg->z;
    work->vx = (GetRandom() % 0x181 + 0x80) * arg->facing;
    work->vz = -(GetRandom() % 0x201 + 0x400);
    work->tiles = LoadObjTiles(gBosLstSnpTiles, sizeof(gBosLstSnpTiles));
    work->palette = LoadObjPalette(gBosLstObjPalette, sizeof(gBosLstObjPalette));
    m4aSongNumStart(SONG_SND_707);
    AnimInit(&work->anim, gBosLstSnpAnims, gBosLstSnpFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
}

u8 task_bos_lst_snp_1(LstSnpWork* work) {
    s16 x;
    s16 y;
    u8 alive;

    alive = 1;
    work->angle += 8;
    work->x += work->vx;
    work->z += work->vz;
    work->vz += 64;
    WorldToScreen(&x, &y, work->x, work->y, work->z);

    if (y > 192) {
        alive = 0;
    }

    AnimUpdate(&work->anim);

    return alive;
}

void task_bos_lst_snp_2(LstSnpWork* work) {
    s16 x;
    s16 y;
    ObjAffine* affine;
    void* gfx;
    u16 prio;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    affine = AllocObjAffineAngle(work->angle, TRUE);
    gfx = AnimGetGfx(&work->anim);
    prio = GetBattleSpritePriorityFlags(work->y) | SPRITE_FLAG_BLEND;
    DrawSprite(x, y, gfx, work->tiles, work->palette, affine, prio,
               -0x1004 - (work->y >> 8) * 4);
}

void task_bos_lst_snp_3(LstSnpWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}
