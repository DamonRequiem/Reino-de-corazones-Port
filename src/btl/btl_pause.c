/**
 * btl_pause.c
 * Battle Pause Control
 */

#include "system_state.h"
#include "m4a_song.h"
#include "btl2.h"
#include "gba/keys.h"
#include "sprites_btl.h"
#include "sprites_btl_hud.h"
#include "fade.h"
#include "battle_work.h"
#include "engine_math.h"
#include "key.h"
#include "m4a_catalog_data.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"

void task_btl_pause_0(BtlPauseWork* work) {
#ifdef VERSION_EU
    void** frames;

    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));

    if (gLanguage <= LANGUAGE_GERMAN) {
        work->tiles = LoadObjTiles(gBtlPauseTiles, sizeof(gBtlPauseTiles));
        frames = gBtlPauseFrames;
    } else {
        work->tiles = LoadObjTiles(gBtlPauseItalianSpanishTiles, sizeof(gBtlPauseItalianSpanishTiles));
        frames = gBtlPauseItalianSpanishFrames;
    }

    work->gfx = frames[0];
    work->gfx2 = frames[1];
#else
    work->tiles = LoadObjTiles(gBtlPauseTiles, sizeof(gBtlPauseTiles));
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
    work->gfx = gBtlPauseFrames[0];
    work->gfx2 = gBtlPauseFrames[1];
#endif
    work->visible = FALSE;
    work->steps = 0;
    work->unk_26 = 0;
    gBtlWork->flags |= BTL_FLAG_PAUSE_DISABLED;
}

s32 task_btl_pause_1(BtlPauseWork* work) {
    s32 paused;

    if (GetKeysPressed() & START_BUTTON) {
        if (!(gBtlWork->flags & BTL_FLAG_PAUSE_DISABLED)) {
            gBtlWork->paused = !gBtlWork->paused ? TRUE : FALSE;
        }
    }

    paused = gBtlWork->paused;

    if (paused) {
        if (!work->visible) {
            FadeSetPaused(TRUE);
            work->visible = TRUE;
            work->x = -0x4000;
            work->y = 0x5000;
            work->x2 = 0x13000;
            work->y2 = 0x5000;
            work->steps = 14;
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x80);
        m4aMPlayVolumeControl(&gMPlayInfo1, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo2, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo3, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo4, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo5, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo6, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo7, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo8, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo9, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo10, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo11, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo12, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo16, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo17, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo18, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo19, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo20, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo21, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo22, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo23, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo24, 0xFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo25, 0xFF, 0);
        } else {
            ApproachValue(&work->x, 0x7800, work->steps);
            ApproachValue(&work->x2, 0x7800, work->steps);

            if (work->steps > 1) {
                work->steps--;
            }
        }
    } else if (work->visible) {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo1, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo2, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo3, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo4, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo5, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo6, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo7, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo8, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo9, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo10, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo11, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo12, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo16, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo17, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo18, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo19, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo20, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo21, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo22, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo23, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo24, 0xFF, 0x100);
        m4aMPlayVolumeControl(&gMPlayInfo25, 0xFF, 0x100);
        work->visible = paused;
        FadeSetPaused(FALSE);
    }

    return 1;
}

void task_btl_pause_2(BtlPauseWork* work) {
    if (work->visible) {
        DrawSprite(work->x >> 8, work->y >> 8, work->gfx, work->tiles, work->palette, NULL, 0, 0);
        DrawSprite(work->x2 >> 8, work->y2 >> 8, work->gfx2, work->tiles, work->palette, NULL, 0, 0);
    }
}

void task_btl_pause_3(BtlPauseWork* work) {
    FadeSetPaused(FALSE);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescBtlPause = {
    "task_btl_pause",
    (TaskInitFunc)task_btl_pause_0,
    (TaskUpdateFunc)task_btl_pause_1,
    (TaskDrawFunc)task_btl_pause_2,
    (TaskDestroyFunc)task_btl_pause_3,
    sizeof(BtlPauseWork),
};
