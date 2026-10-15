/**
 * btl_pop.c
 * Battle Popup Labels
 */

#include "system_state.h"
#include "btl2.h"
#include "sprites_btl.h"
#include "sprites_btl_hud.h"
#include "anim.h"
#include "battle_actor.h"
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"

void task_btl_pop_0(BtlPopWork* work, BtlPremireSrc* src) {
#ifdef VERSION_EU
    switch (gLanguage) {
    case LANGUAGE_ENGLISH:
        switch (src->kind) {
        case BTL_POP_GUARD:
            work->tiles = LoadObjTiles(gBtlPopGuardTiles, sizeof(gBtlPopGuardTiles));
            AnimInit(&work->anim, gBtlPopGuardAnims, gBtlPopGuardFrames);
            break;
        case BTL_POP_MISS:
            work->tiles = LoadObjTiles(gBtlPopMissTiles, sizeof(gBtlPopMissTiles));
            AnimInit(&work->anim, gBtlPopMissAnims, gBtlPopMissFrames);
            break;
        case BTL_POP_CARD_BREAK:
            work->tiles = LoadObjTiles(gBtlPopCardBreakTiles, sizeof(gBtlPopCardBreakTiles));
            AnimInit(&work->anim, gBtlPopCardBreakAnims, gBtlPopCardBreakFrames);
            break;
        case BTL_POP_RECOVER:
            work->tiles = LoadObjTiles(gBtlPopRecoverTiles, sizeof(gBtlPopRecoverTiles));
            AnimInit(&work->anim, gBtlPopRecoverAnims, gBtlPopRecoverFrames);
            break;
        default:
            work->tiles = LoadObjTiles(gBtlPopMissTiles, sizeof(gBtlPopMissTiles));
            AnimInit(&work->anim, gBtlPopMissAnims, gBtlPopMissFrames);
            break;
        }

        break;
    case LANGUAGE_FRENCH:
        switch (src->kind) {
        case BTL_POP_GUARD:
            work->tiles = LoadObjTiles(gBtlPopGuardFrenchTiles, sizeof(gBtlPopGuardFrenchTiles));
            AnimInit(&work->anim, gBtlPopGuardFrenchAnims, gBtlPopGuardFrenchFrames);
            break;
        case BTL_POP_MISS:
            work->tiles = LoadObjTiles(gBtlPopMissFrenchTiles, sizeof(gBtlPopMissFrenchTiles));
            AnimInit(&work->anim, gBtlPopMissFrenchAnims, gBtlPopMissFrenchFrames);
            break;
        case BTL_POP_CARD_BREAK:
            work->tiles = LoadObjTiles(gBtlPopCardBreakTiles, sizeof(gBtlPopCardBreakTiles));
            AnimInit(&work->anim, gBtlPopCardBreakAnims, gBtlPopCardBreakFrames);
            break;
        case BTL_POP_RECOVER:
            work->tiles = LoadObjTiles(gBtlPopRecoverFrenchTiles, sizeof(gBtlPopRecoverFrenchTiles));
            AnimInit(&work->anim, gBtlPopRecoverFrenchAnims, gBtlPopRecoverFrenchFrames);
            break;
        default:
            work->tiles = LoadObjTiles(gBtlPopMissFrenchTiles, sizeof(gBtlPopMissFrenchTiles));
            AnimInit(&work->anim, gBtlPopMissFrenchAnims, gBtlPopMissFrenchFrames);
            break;
        }

        break;
    case LANGUAGE_GERMAN:
        switch (src->kind) {
        case BTL_POP_GUARD:
            work->tiles = LoadObjTiles(gBtlPopGuardGermanTiles, sizeof(gBtlPopGuardGermanTiles));
            AnimInit(&work->anim, gBtlPopGuardGermanAnims, gBtlPopGuardGermanFrames);
            break;
        case BTL_POP_MISS:
            work->tiles = LoadObjTiles(gBtlPopMissGermanTiles, sizeof(gBtlPopMissGermanTiles));
            AnimInit(&work->anim, gBtlPopMissGermanAnims, gBtlPopMissGermanFrames);
            break;
        case BTL_POP_CARD_BREAK:
            work->tiles = LoadObjTiles(gBtlPopCardBreakGermanTiles, sizeof(gBtlPopCardBreakGermanTiles));
            AnimInit(&work->anim, gBtlPopCardBreakGermanAnims, gBtlPopCardBreakGermanFrames);
            break;
        case BTL_POP_RECOVER:
            work->tiles = LoadObjTiles(gBtlPopRecoverGermanTiles, sizeof(gBtlPopRecoverGermanTiles));
            AnimInit(&work->anim, gBtlPopRecoverGermanAnims, gBtlPopRecoverGermanFrames);
            break;
        default:
            work->tiles = LoadObjTiles(gBtlPopMissGermanTiles, sizeof(gBtlPopMissGermanTiles));
            AnimInit(&work->anim, gBtlPopMissGermanAnims, gBtlPopMissGermanFrames);
            break;
        }

        break;
    case LANGUAGE_ITALIAN:
        switch (src->kind) {
        case BTL_POP_GUARD:
            work->tiles = LoadObjTiles(gBtlPopGuardItalianTiles, sizeof(gBtlPopGuardItalianTiles));
            AnimInit(&work->anim, gBtlPopGuardItalianAnims, gBtlPopGuardItalianFrames);
            break;
        case BTL_POP_MISS:
            work->tiles = LoadObjTiles(gBtlPopMissItalianTiles, sizeof(gBtlPopMissItalianTiles));
            AnimInit(&work->anim, gBtlPopMissItalianAnims, gBtlPopMissItalianFrames);
            break;
        case BTL_POP_CARD_BREAK:
            work->tiles = LoadObjTiles(gBtlPopCardBreakItalianTiles, sizeof(gBtlPopCardBreakItalianTiles));
            AnimInit(&work->anim, gBtlPopCardBreakItalianAnims, gBtlPopCardBreakItalianFrames);
            break;
        case BTL_POP_RECOVER:
            work->tiles = LoadObjTiles(gBtlPopRecoverItalianTiles, sizeof(gBtlPopRecoverItalianTiles));
            AnimInit(&work->anim, gBtlPopRecoverItalianAnims, gBtlPopRecoverItalianFrames);
            break;
        default:
            work->tiles = LoadObjTiles(gBtlPopMissItalianTiles, sizeof(gBtlPopMissItalianTiles));
            AnimInit(&work->anim, gBtlPopMissItalianAnims, gBtlPopMissItalianFrames);
            break;
        }

        break;
    case LANGUAGE_SPANISH:
    default:
        switch (src->kind) {
        case BTL_POP_GUARD:
            work->tiles = LoadObjTiles(gBtlPopGuardSpanishTiles, sizeof(gBtlPopGuardSpanishTiles));
            AnimInit(&work->anim, gBtlPopGuardSpanishAnims, gBtlPopGuardSpanishFrames);
            break;
        case BTL_POP_MISS:
            work->tiles = LoadObjTiles(gBtlPopMissSpanishTiles, sizeof(gBtlPopMissSpanishTiles));
            AnimInit(&work->anim, gBtlPopMissSpanishAnims, gBtlPopMissSpanishFrames);
            break;
        case BTL_POP_CARD_BREAK:
            work->tiles = LoadObjTiles(gBtlPopCardBreakSpanishTiles, sizeof(gBtlPopCardBreakSpanishTiles));
            AnimInit(&work->anim, gBtlPopCardBreakSpanishAnims, gBtlPopCardBreakSpanishFrames);
            break;
        case BTL_POP_RECOVER:
            work->tiles = LoadObjTiles(gBtlPopRecoverSpanishTiles, sizeof(gBtlPopRecoverSpanishTiles));
            AnimInit(&work->anim, gBtlPopRecoverSpanishAnims, gBtlPopRecoverSpanishFrames);
            break;
        default:
            work->tiles = LoadObjTiles(gBtlPopMissSpanishTiles, sizeof(gBtlPopMissSpanishTiles));
            AnimInit(&work->anim, gBtlPopMissSpanishAnims, gBtlPopMissSpanishFrames);
            break;
        }

        break;
    }

    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
#else
    switch (src->kind) {
    case BTL_POP_GUARD:
        work->tiles = LoadObjTiles(gBtlPopGuardTiles, sizeof(gBtlPopGuardTiles));
        AnimInit(&work->anim, gBtlPopGuardAnims, gBtlPopGuardFrames);
        AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
        break;
    case BTL_POP_COUNTER:
        work->tiles = LoadObjTiles(gBtlPopCounterTiles, sizeof(gBtlPopCounterTiles));
        AnimInit(&work->anim, gBtlPopCounterAnims, gBtlPopCounterFrames);
        AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
        break;
    case BTL_POP_MISS:
        work->tiles = LoadObjTiles(gBtlPopMissTiles, sizeof(gBtlPopMissTiles));
        AnimInit(&work->anim, gBtlPopMissAnims, gBtlPopMissFrames);
        AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
        break;
    case BTL_POP_OVERWRITE:
        work->tiles = LoadObjTiles(gBtlPopOverWriteTiles, sizeof(gBtlPopOverWriteTiles));
        AnimInit(&work->anim, gBtlPopOverWriteAnims, gBtlPopOverWriteFrames);
        AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
        break;
    case BTL_POP_25_PERCENT_UP:
        work->tiles = LoadObjTiles(gBtlPopPercentTiles, sizeof(gBtlPopPercentTiles));
        AnimInit(&work->anim, gBtlPopPercentAnims, gBtlPopPercentFrames);
        AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
        break;
    case BTL_POP_50_PERCENT_UP:
        work->tiles = LoadObjTiles(gBtlPopPercentTiles, sizeof(gBtlPopPercentTiles));
        AnimInit(&work->anim, gBtlPopPercentAnims, gBtlPopPercentFrames);
        AnimStart(&work->anim, 2, ANIM_FLAG_LOOP);
        break;
    case BTL_POP_25_PERCENT_DOWN:
        work->tiles = LoadObjTiles(gBtlPopPercentTiles, sizeof(gBtlPopPercentTiles));
        AnimInit(&work->anim, gBtlPopPercentAnims, gBtlPopPercentFrames);
        AnimStart(&work->anim, 1, ANIM_FLAG_LOOP);
        break;
    case BTL_POP_50_PERCENT_DOWN:
        work->tiles = LoadObjTiles(gBtlPopPercentTiles, sizeof(gBtlPopPercentTiles));
        AnimInit(&work->anim, gBtlPopPercentAnims, gBtlPopPercentFrames);
        AnimStart(&work->anim, 3, ANIM_FLAG_LOOP);
        break;
    case BTL_POP_CARD_BREAK:
        work->tiles = LoadObjTiles(gBtlPopCardBreakTiles, sizeof(gBtlPopCardBreakTiles));
        AnimInit(&work->anim, gBtlPopCardBreakAnims, gBtlPopCardBreakFrames);
        AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
        break;
    case BTL_POP_RECOVER:
        work->tiles = LoadObjTiles(gBtlPopRecoverTiles, sizeof(gBtlPopRecoverTiles));
        AnimInit(&work->anim, gBtlPopRecoverAnims, gBtlPopRecoverFrames);
        AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
        break;
    case BTL_POP_TIME_BREAK:
    default:
        work->tiles = LoadObjTiles(gBtlPopTimeBreakTiles, sizeof(gBtlPopTimeBreakTiles));
        AnimInit(&work->anim, gBtlPopTimeBreakAnims, gBtlPopTimeBreakFrames);
        AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
        break;
    }
#endif

    work->gfx = AnimGetGfx(&work->anim);
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
    work->x = src->x;
    work->y = src->y;
    work->z = src->z;
    work->timer = 0;
}

s32 task_btl_pop_1(BtlPopWork* work) {
    work->z -= 0xC0;

    if (work->timer > 49) {
        return 0;
    }

    work->timer++;
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_btl_pop_2(BtlPopWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, NULL, SPRITE_FLAG_NO_MOSAIC, 5);
}

void task_btl_pop_3(BtlPopWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescBtlPop = {
    "task_btl_pop",
    (TaskInitFunc)task_btl_pop_0,
    (TaskUpdateFunc)task_btl_pop_1,
    (TaskDrawFunc)task_btl_pop_2,
    (TaskDestroyFunc)task_btl_pop_3,
    sizeof(BtlPopWork),
};
