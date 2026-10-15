/**
 * btl_pop_cb.c
 * Riku Card Break Popup
 */

#include "system_state.h"
#include "btl4.h"
#include "sprites_btl.h"
#include "sprites_btl_hud.h"
#include "battle_actor.h"
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"

void task_btl_pop_cb_0(BtlPopCbWork* work, BtlPopSrc* src) {
#ifdef VERSION_EU
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));

    switch (gLanguage) {
    case LANGUAGE_ENGLISH:
    case LANGUAGE_FRENCH:
        work->tiles = AllocObjTiles(0x200, gBtlPopCbTiles);

        switch (src->number) {
        case 0:
            work->gfx = gBtlPopCbFrame1;
            break;
        case 1:
            work->gfx = gBtlPopCbFrame2;
            break;
        case 2:
            work->gfx = gBtlPopCbFrame3;
            break;
        case 3:
            work->gfx = gBtlPopCbFrame4;
            break;
        case 4:
            work->gfx = gBtlPopCbFrame5;
            break;
        case 5:
            work->gfx = gBtlPopCbFrame6;
            break;
        case 6:
            work->gfx = gBtlPopCbFrame7;
            break;
        case 7:
            work->gfx = gBtlPopCbFrame8;
            break;
        case 8:
            work->gfx = gBtlPopCbFrame9;
            break;
        case 9:
        default:
            work->gfx = gBtlPopCbFrame10;
            break;
        }

        break;
    case LANGUAGE_SPANISH:
        work->tiles = AllocObjTiles(0x200, gBtlPopCbSpanishTiles);

        switch (src->number) {
        case 0:
            work->gfx = gBtlPopCbSpanishFrame1;
            break;
        case 1:
            work->gfx = gBtlPopCbSpanishFrame2;
            break;
        case 2:
            work->gfx = gBtlPopCbSpanishFrame3;
            break;
        case 3:
            work->gfx = gBtlPopCbSpanishFrame4;
            break;
        case 4:
            work->gfx = gBtlPopCbSpanishFrame5;
            break;
        case 5:
            work->gfx = gBtlPopCbSpanishFrame6;
            break;
        case 6:
            work->gfx = gBtlPopCbSpanishFrame7;
            break;
        case 7:
            work->gfx = gBtlPopCbSpanishFrame8;
            break;
        case 8:
            work->gfx = gBtlPopCbSpanishFrame9;
            break;
        case 9:
        default:
            work->gfx = gBtlPopCbSpanishFrame10;
            break;
        }

        break;
    case LANGUAGE_ITALIAN:
        work->tiles = AllocObjTiles(0x200, gBtlPopCbItalianTiles);

        switch (src->number) {
        case 0:
            work->gfx = gBtlPopCbItalianFrame1;
            break;
        case 1:
            work->gfx = gBtlPopCbItalianFrame2;
            break;
        case 2:
            work->gfx = gBtlPopCbItalianFrame3;
            break;
        case 3:
            work->gfx = gBtlPopCbItalianFrame4;
            break;
        case 4:
            work->gfx = gBtlPopCbItalianFrame5;
            break;
        case 5:
            work->gfx = gBtlPopCbItalianFrame6;
            break;
        case 6:
            work->gfx = gBtlPopCbItalianFrame7;
            break;
        case 7:
            work->gfx = gBtlPopCbItalianFrame8;
            break;
        case 8:
            work->gfx = gBtlPopCbItalianFrame9;
            break;
        case 9:
        default:
            work->gfx = gBtlPopCbItalianFrame10;
            break;
        }

        break;
    case LANGUAGE_GERMAN:
    default:
        work->tiles = AllocObjTiles(0x200, gBtlPopCbGermanTiles);

        switch (src->number) {
        case 0:
            work->gfx = gBtlPopCbGermanFrame1;
            break;
        case 1:
            work->gfx = gBtlPopCbGermanFrame2;
            break;
        case 2:
            work->gfx = gBtlPopCbGermanFrame3;
            break;
        case 3:
            work->gfx = gBtlPopCbGermanFrame4;
            break;
        case 4:
            work->gfx = gBtlPopCbGermanFrame5;
            break;
        case 5:
            work->gfx = gBtlPopCbGermanFrame6;
            break;
        case 6:
            work->gfx = gBtlPopCbGermanFrame7;
            break;
        case 7:
            work->gfx = gBtlPopCbGermanFrame8;
            break;
        case 8:
            work->gfx = gBtlPopCbGermanFrame9;
            break;
        case 9:
        default:
            work->gfx = gBtlPopCbGermanFrame10;
            break;
        }

        break;
    }
#else
    work->tiles = AllocObjTiles(0x200, gBtlPopCbTiles);
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));

    switch (src->number) {
    case 0:
        work->gfx = gBtlPopCbFrame1;
        break;
    case 1:
        work->gfx = gBtlPopCbFrame2;
        break;
    case 2:
        work->gfx = gBtlPopCbFrame3;
        break;
    case 3:
        work->gfx = gBtlPopCbFrame4;
        break;
    case 4:
        work->gfx = gBtlPopCbFrame5;
        break;
    case 5:
        work->gfx = gBtlPopCbFrame6;
        break;
    case 6:
        work->gfx = gBtlPopCbFrame7;
        break;
    case 7:
        work->gfx = gBtlPopCbFrame8;
        break;
    case 8:
        work->gfx = gBtlPopCbFrame9;
        break;
    case 9:
    default:
        work->gfx = gBtlPopCbFrame10;
        break;
    }
#endif

    work->x = src->x;
    work->y = src->y;
    work->z = src->z;
    work->timer = 0;
}

s32 task_btl_pop_cb_1(BtlPopCbWork* work) {
    work->z -= 192;

    if (work->timer > 49) {
        return 0;
    }

    work->timer++;
    return 1;
}

void task_btl_pop_cb_2(BtlPopCbWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, NULL, SPRITE_FLAG_NO_MOSAIC, 5);
}

void task_btl_pop_cb_3(BtlPopCbWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescBtlPopCb = {
    "task_btl_pop_cb",
    (TaskInitFunc)task_btl_pop_cb_0,
    (TaskUpdateFunc)task_btl_pop_cb_1,
    (TaskDrawFunc)task_btl_pop_cb_2,
    (TaskDestroyFunc)task_btl_pop_cb_3,
    sizeof(BtlPopCbWork),
};
