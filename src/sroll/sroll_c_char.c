/**
 * sroll_c_char.c
 * Staff Roll Ending Character
 */

#include "sroll.h"
#include "sprites_staff_roll.h"
#include "anim.h"
#include "obj_api.h"
#include <stddef.h>
#include "system_state.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"

static s32 Square(s32 x) {
    return x * x;
}

void task_sroll_c_char_0(SrollCCharWork* work, s32 kind) {
    AnimState* anim;
    s32 i;

#ifdef VERSION_EU
    switch (gLanguage) {
    case LANGUAGE_ENGLISH:
#endif
    if (kind == 0) {
        work->tiles = LoadObjTiles(gSrollSoraEpilogueTiles, sizeof(gSrollSoraEpilogueTiles));
        work->palette = LoadObjPalette(gSrollSoraEpiloguePalettes, sizeof(gSrollSoraEpiloguePalettes));

        for (i = 0, anim = work->anim; i <= 4; i++) {
            AnimInit(anim, gSrollSoraEpilogueAnims, gSrollSoraEpilogueFrames);
            AnimStart(anim, i, 0);
            anim++;
        }
    } else {
        work->tiles = LoadObjTiles(gSrollRikuEpilogueTiles, sizeof(gSrollRikuEpilogueTiles));
        work->palette = LoadObjPalette(gSrollRikuEpiloguePalettes, sizeof(gSrollRikuEpiloguePalettes));

        for (i = 0, anim = work->anim; i <= 4; i++) {
            AnimInit(anim, gSrollRikuEpilogueAnims, gSrollRikuEpilogueFrames);
            AnimStart(anim, i, 0);
            anim++;
        }
    }

#ifdef VERSION_EU
        break;
    case LANGUAGE_FRENCH:
        if (kind == 0) {
            work->tiles = LoadObjTiles(gSrollSoraEpilogueFrenchTiles, sizeof(gSrollSoraEpilogueFrenchTiles));
            work->palette = LoadObjPalette(gSrollSoraEpiloguePalettes, sizeof(gSrollSoraEpiloguePalettes));

            for (i = 0, anim = work->anim; i <= 4; i++) {
                AnimInit(anim, gSrollSoraEpilogueFrenchAnims, gSrollSoraEpilogueFrenchFrames);
                AnimStart(anim, i, 0);
                anim++;
            }
        } else {
            work->tiles = LoadObjTiles(gSrollRikuEpilogueFrenchTiles, sizeof(gSrollRikuEpilogueFrenchTiles));
            work->palette = LoadObjPalette(gSrollRikuEpiloguePalettes, sizeof(gSrollRikuEpiloguePalettes));

            for (i = 0, anim = work->anim; i <= 4; i++) {
                AnimInit(anim, gSrollRikuEpilogueFrenchAnims, gSrollRikuEpilogueFrenchFrames);
                AnimStart(anim, i, 0);
                anim++;
            }
        }

        break;
    case LANGUAGE_SPANISH:
        if (kind == 0) {
            work->tiles = LoadObjTiles(gSrollSoraEpilogueSpanishTiles, sizeof(gSrollSoraEpilogueSpanishTiles));
            work->palette = LoadObjPalette(gSrollSoraEpiloguePalettes, sizeof(gSrollSoraEpiloguePalettes));

            for (i = 0, anim = work->anim; i <= 4; i++) {
                AnimInit(anim, gSrollSoraEpilogueSpanishAnims, gSrollSoraEpilogueSpanishFrames);
                AnimStart(anim, i, 0);
                anim++;
            }
        } else {
            work->tiles = LoadObjTiles(gSrollRikuEpilogueSpanishTiles, sizeof(gSrollRikuEpilogueSpanishTiles));
            work->palette = LoadObjPalette(gSrollRikuEpiloguePalettes, sizeof(gSrollRikuEpiloguePalettes));

            for (i = 0, anim = work->anim; i <= 4; i++) {
                AnimInit(anim, gSrollRikuEpilogueSpanishAnims, gSrollRikuEpilogueSpanishFrames);
                AnimStart(anim, i, 0);
                anim++;
            }
        }

        break;
    case LANGUAGE_ITALIAN:
        if (kind == 0) {
            work->tiles = LoadObjTiles(gSrollSoraEpilogueItalianTiles, sizeof(gSrollSoraEpilogueItalianTiles));
            work->palette = LoadObjPalette(gSrollSoraEpiloguePalettes, sizeof(gSrollSoraEpiloguePalettes));

            for (i = 0, anim = work->anim; i <= 4; i++) {
                AnimInit(anim, gSrollSoraEpilogueItalianAnims, gSrollSoraEpilogueItalianFrames);
                AnimStart(anim, i, 0);
                anim++;
            }
        } else {
            work->tiles = LoadObjTiles(gSrollRikuEpilogueItalianTiles, sizeof(gSrollRikuEpilogueItalianTiles));
            work->palette = LoadObjPalette(gSrollRikuEpiloguePalettes, sizeof(gSrollRikuEpiloguePalettes));

            for (i = 0, anim = work->anim; i <= 4; i++) {
                AnimInit(anim, gSrollRikuEpilogueItalianAnims, gSrollRikuEpilogueItalianFrames);
                AnimStart(anim, i, 0);
                anim++;
            }
        }

        break;
    case LANGUAGE_GERMAN:
    default:
        if (kind == 0) {
            work->tiles = LoadObjTiles(gSrollSoraEpilogueGermanTiles, sizeof(gSrollSoraEpilogueGermanTiles));
            work->palette = LoadObjPalette(gSrollSoraEpiloguePalettes, sizeof(gSrollSoraEpiloguePalettes));

            for (i = 0, anim = work->anim; i <= 4; i++) {
                AnimInit(anim, gSrollSoraEpilogueGermanAnims, gSrollSoraEpilogueGermanFrames);
                AnimStart(anim, i, 0);
                anim++;
            }
        } else {
            work->tiles = LoadObjTiles(gSrollRikuEpilogueGermanTiles, sizeof(gSrollRikuEpilogueGermanTiles));
            work->palette = LoadObjPalette(gSrollRikuEpiloguePalettes, sizeof(gSrollRikuEpiloguePalettes));

            for (i = 0, anim = work->anim; i <= 4; i++) {
                AnimInit(anim, gSrollRikuEpilogueGermanAnims, gSrollRikuEpilogueGermanFrames);
                AnimStart(anim, i, 0);
                anim++;
            }
        }

        break;
    }
#endif
}

u8 task_sroll_c_char_1(SrollCCharWork* work) {
    AnimState* anim;
    s32 i;

    anim = work->anim;

    for (i = 4; i >= 0; i--) {
        AnimUpdate(anim);
        anim++;
    }

    return 1;
}

void task_sroll_c_char_2(SrollCCharWork* work) {
    AnimState* anim;
    s32 i;
    u16 flags;

    flags = 0;
    anim = work->anim;

    for (i = 4; i >= 0; i--) {
        DrawSprite(120, 80, AnimGetGfx(anim), work->tiles, work->palette, NULL, flags, 0xFF0);
        anim++;
    }
}

void task_sroll_c_char_3(SrollCCharWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescSrollCChar = {
    "task_sroll_c_char",
    (TaskInitFunc)task_sroll_c_char_0,
    (TaskUpdateFunc)task_sroll_c_char_1,
    (TaskDrawFunc)task_sroll_c_char_2,
    (TaskDestroyFunc)task_sroll_c_char_3,
    sizeof(SrollCCharWork),
};
