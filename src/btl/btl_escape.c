/**
 * btl_escape.c
 * Battle Escape Gauge
 */

#include "system_state.h"
#include "btl2.h"
#include "sprites_btl.h"
#include "sprites_btl_hud.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "game_state.h"
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "engine_math.h"

void task_btl_escape_0(BtlEscapeWork* work) {
    void** frames;

    work->progressMax = 0x5A00;
#ifdef VERSION_EU
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));

    switch (gLanguage) {
    case LANGUAGE_ENGLISH:
        work->tiles = LoadObjTiles(gBtlEscapeTiles, sizeof(gBtlEscapeTiles));
        frames = gBtlEscapeFrames;
        break;
    case LANGUAGE_FRENCH:
        work->tiles = LoadObjTiles(gBtlEscapeFrenchTiles, sizeof(gBtlEscapeFrenchTiles));
        frames = gBtlEscapeFrenchFrames;
        break;
    case LANGUAGE_SPANISH:
        work->tiles = LoadObjTiles(gBtlEscapeSpanishTiles, sizeof(gBtlEscapeSpanishTiles));
        frames = gBtlEscapeSpanishFrames;
        break;
    case LANGUAGE_ITALIAN:
        work->tiles = LoadObjTiles(gBtlEscapeItalianTiles, sizeof(gBtlEscapeItalianTiles));
        frames = gBtlEscapeItalianFrames;
        break;
    case LANGUAGE_GERMAN:
    default:
        work->tiles = LoadObjTiles(gBtlEscapeGermanTiles, sizeof(gBtlEscapeGermanTiles));
        frames = gBtlEscapeGermanFrames;
        break;
    }
#else
    work->tiles = LoadObjTiles(gBtlEscapeTiles, sizeof(gBtlEscapeTiles));
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
    frames = gBtlEscapeFrames;
#endif
    work->gfx = frames[0];
    work->gfx2 = frames[2];
    work->gfx3 = frames[1];
    work->progressRatio = 0;
    work->progress = 0;
    work->visible = FALSE;
    work->timer = 0;
}

s32 task_btl_escape_1(BtlEscapeWork* work) {
    if (gBtlWork->flags & BTL_FLAG_STOP_SPAWNING) {
        return 0;
    }

    if (!(gBtlWork->flags & BTL_FLAG_PUSHING_EDGE)) {
        if (work->visible) {
            work->progress = 0;
            work->visible = FALSE;
            work->timer = 0;
        }
    } else {
        if (work->timer <= 15) {
            work->timer++;
            work->visible = FALSE;
        } else {
            work->visible = TRUE;
            work->progressRatio = (work->progress << 8) / work->progressMax;

            if (work->progress >= work->progressMax) {
                gGameState.flags |= GAME_FLAG_BATTLE_NOT_WON;
                gBtlWork->flags |= BTL_FLAG_ESCAPED;
                gBtlWork->flags |= BTL_FLAG_BATTLE_OVER;
                work->visible = FALSE;
            } else {
                work->progress += 256;
            }
        }
    }

    return 1;
}

void task_btl_escape_2(BtlEscapeWork* work) {
    BtlObj* actor;
    s16 x;
    s16 y;
    s32 scale;
    ObjAffine* affine;

    if (!work->visible) {
        return;
    }

    actor = gBtlWork->actor;

    if (actor->flags & BTLOBJ_FLAG_FACING_LEFT) {
        WorldToScreen(&x, &y, actor->x - 768, actor->y, actor->z - 10240);
        DrawSprite(x, y, work->gfx, work->tiles, work->palette, NULL, 0, 2);
    } else {
        WorldToScreen(&x, &y, actor->x - 3072, actor->y, actor->z - 10240);
        DrawSprite(x, y, work->gfx2, work->tiles, work->palette, NULL, 0, 2);
    }

    if (work->progressRatio > 0) {
        scale = work->progressRatio * 2;

        if (scale > Q_8_8(1)) {
            affine = AllocObjAffine(0, scale, Q_8_8(1), TRUE);
        } else {
            affine = AllocObjAffine(0, scale, Q_8_8(1), FALSE);
        }

        DrawSprite(x, y, work->gfx3, work->tiles, work->palette, affine, 0, 1);
    }
}

void task_btl_escape_3(BtlEscapeWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescBtlEscape = {
    "task_btl_escape",
    (TaskInitFunc)task_btl_escape_0,
    (TaskUpdateFunc)task_btl_escape_1,
    (TaskDrawFunc)task_btl_escape_2,
    (TaskDestroyFunc)task_btl_escape_3,
    sizeof(BtlEscapeWork),
};
