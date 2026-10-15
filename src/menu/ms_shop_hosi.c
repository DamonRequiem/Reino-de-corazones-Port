/**
 * ms_shop_hosi.c
 * Moogle Shop Sparkles and Flags
 */

#include "ms_shop_hosi.h"
#include "sprites_moogle_shop.h"
#include "mode_ms_api.h"
#include "engine_math.h"
#include "ms_types.h"
#include "obj_api.h"
#include <stddef.h>
#include "taskpool.h"
#include "types.h"

void task_ms_shop_hosi_0(MsShopHosiWork* work, MsShopHosiArg* arg) {
    work->x = arg->x << 8;
    work->y = arg->y << 8;
    work->velX = gSineTable[arg->angle] * arg->speed >> 8;
    work->velY = -gSineTable[arg->angle + 0x40] * arg->speed >> 8;
    work->frame = 0;
    work->timer = work->frameDuration = GetRandom() % 8 + 4;
    work->palette = arg->palette;
    work->tiles = LoadObjTiles(gMsShopHosiTiles, sizeof(gMsShopHosiTiles));
}

s32 task_ms_shop_hosi_1(MsShopHosiWork* work) {
    s32 result;

    result = 1;
    work->x += work->velX;
    work->velY += 10;
    work->y += work->velY;

    if (--work->timer <= 0) {
        work->timer = work->frameDuration;
        work->frame++;

        if (work->frame > 5) {
            result = 0;
        }
    }

    return result;
}

void task_ms_shop_hosi_2(MsShopHosiWork* work) {
    if (work->timer & 1) {
        DrawSprite(work->x >> 8, work->y >> 8, gMsShopHosiFrames[work->frame], work->tiles, work->palette, NULL, 0, 0);
    }
}

void task_ms_shop_hosi_3(MsShopHosiWork* work) {
    ReleaseObjTiles(work->tiles);
}

void ClearMoogleShopFlags() {
    MoogleShopClearFlags();
}

void SaveMoogleShopFlags(void* dst) {
    MoogleShopSaveFlags(dst);
}

void LoadMoogleShopFlags(void* src) {
    MoogleShopLoadFlags(src);
}

TaskDesc gTaskDescMsShopHosi = {
    "task_ms_shop_hosi",
    (TaskInitFunc)task_ms_shop_hosi_0,
    (TaskUpdateFunc)task_ms_shop_hosi_1,
    (TaskDrawFunc)task_ms_shop_hosi_2,
    (TaskDestroyFunc)task_ms_shop_hosi_3,
    sizeof(MsShopHosiWork),
};
