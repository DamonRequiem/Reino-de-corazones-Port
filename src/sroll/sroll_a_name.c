/**
 * sroll_a_name.c
 * Staff Roll Character Names
 */

#include "sroll.h"
#include "sprites_staff_roll.h"
#include "gba/io_reg.h"
#include "anim.h"
#include "display.h"
#include "gba/defines.h"
#include "obj.h"
#include "obj_api.h"
#include <stddef.h>
#include "taskpool.h"
#include "types.h"

s32 SrollANameSquare(s32 x) {
    return x * x;
}

s32 SrollANameSquare2(s32 x) {
    return x * x;
}

void task_sroll_a_name_0(SrollANameWork* work, SrollANameArg* arg) {
    AnimState* anim;

    work->kind = arg->kind;
    work->x = arg->x;
    work->y = arg->y;
    work->targetX = arg->targetX;
    work->targetY = arg->targetY;
    work->unk_00 = 0;
    work->timer = 0;

    switch (arg->kind) {
    case 0:
        work->tiles = LoadObjTiles(gSrollNameOrnamentTiles, sizeof(gSrollNameOrnamentTiles));
        anim = &work->anim;
        AnimInit(anim, gSrollNameOrnamentAnims, gSrollNameOrnamentFrames);
        AnimStart(anim, arg->animId, 0);
        break;
    case 1:
        work->tiles = LoadObjTiles(gSrollNameTileBlocks[arg->nameIndex].tiles, gSrollNameTileBlocks[arg->nameIndex].size);
        anim = &work->anim;
        AnimInit(anim, gSrollNameDirectorAnims, gSrollNameDirectorFrames);
        AnimStart(anim, arg->animId, 0);
        break;
    case 2:
        work->tiles = LoadObjTiles(gSrollNameTileBlocks[arg->nameIndex].tiles, gSrollNameTileBlocks[arg->nameIndex].size);

        if (arg->animId == 1) {
            anim = &work->anim;
            AnimInit(anim, gSrollNameCharacterDirectorsAnims, gSrollNameCharacterDirectorsFrames);
        } else {
            anim = &work->anim;
            AnimInit(anim, gSrollNameDirectorAnims, gSrollNameDirectorFrames);
        }

        AnimStart(anim, 2, 0);
        gBldCnt = (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0);
        gBldAlpha = 0;
        break;
    }

    work->palette = LoadObjPalette(gSrollNamePalettes, 64);
}

u8 task_sroll_a_name_1(SrollANameWork* work) {
    work->timer++;

    if (work->kind == 2) {
        if (work->timer <= 47) {
            gBldAlpha = work->timer / 3;
        } else {
            if (work->timer == 48) {
                gBldCnt = 0;
                gBldAlpha = 0;
            }

            AnimUpdate(&work->anim);
        }
    } else {
        AnimUpdate(&work->anim);
    }

    return 1;
}

void task_sroll_a_name_2(SrollANameWork* work) {
    s32 x;
    s32 y;
    u16 flags;
    s32 ofs;

    if (work->timer <= 29) {
        x = work->x + (work->targetX - work->x) * work->timer / 30;
        y = work->y + (work->targetY - work->y) * work->timer / 30;
    } else {
        x = work->targetX;
        y = work->targetY;
    }

    flags = 0;

    if (work->kind == 2) {
        flags = SPRITE_FLAG_BLEND;
        ofs = AnimGetFrame(&work->anim) * 16 + 16;
        LoadPalette(&gSrollNamePalettes[ofs], (u8*)(OBJ_PLTT + PLTT_SIZE_4BPP) + ((work->palette->index & 15) * 32), 32);
    }

    DrawSprite(x >> 8, y >> 8, AnimGetGfx(&work->anim), work->tiles, work->palette, NULL, flags,
               0xFF0 - work->kind);
}

void task_sroll_a_name_3(SrollANameWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescSrollAName = {
    "task_sroll_a_name",
    (TaskInitFunc)task_sroll_a_name_0,
    (TaskUpdateFunc)task_sroll_a_name_1,
    (TaskDrawFunc)task_sroll_a_name_2,
    (TaskDestroyFunc)task_sroll_a_name_3,
    sizeof(SrollANameWork),
};
