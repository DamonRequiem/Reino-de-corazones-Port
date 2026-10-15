/**
 * hum_mahluxia_flw.c
 * Marluxia Boss Flower Effect
 */

#include "obj_api.h"
#include "hum.h"
#include "sprites_hum.h"
#include "hum_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "engine_math.h"
#include "obj.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"

TaskDesc gTaskDescHumMahluxiaFlw = {
    "task_hum_mahluxia_flw",
    (TaskInitFunc)task_hum_mahluxia_flw_0,
    (TaskUpdateFunc)task_hum_mahluxia_flw_1,
    (TaskDrawFunc)task_hum_mahluxia_flw_2,
    (TaskDestroyFunc)task_hum_mahluxia_flw_3,
    sizeof(MahluxiaFlwWork),
};

enum HumMahluxiaFlwState {
    HUM_MAHLUXIA_FLW_STATE_TOSS,
    HUM_MAHLUXIA_FLW_STATE_FLUTTER
};

void task_hum_mahluxia_flw_0(MahluxiaFlwWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gMaruxhaBtEffPalette, sizeof(gMaruxhaBtEffPalette));
    work->tiles = LoadObjTiles(gMaruxhaBtEff2Tiles, sizeof(gMaruxhaBtEff2Tiles));
    work->state = HUM_MAHLUXIA_FLW_STATE_TOSS;
    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->vx = GetRandom() % 717 - 358;
    work->vz = -(GetRandom() % 539 + 102);
    AnimInit(&work->anim, gMaruxhaBtEff2Anims, gMaruxhaBtEff2Frames);
    AnimStart(&work->anim, GetRandom() & 1, ANIM_FLAG_LOOP);
}

u8 task_hum_mahluxia_flw_1(MahluxiaFlwWork* work) {
    switch (work->state) {
    case HUM_MAHLUXIA_FLW_STATE_TOSS:
        work->x += work->vx;
        work->z += work->vz;
        work->vz += 17;

        if (work->vz > 0x1CC) {
            work->state = HUM_MAHLUXIA_FLW_STATE_FLUTTER;
        }

        break;
    case HUM_MAHLUXIA_FLW_STATE_FLUTTER:
        work->x += work->vx;
        work->z += work->vz;
        work->vz -= 12;

        if (work->vz < 0) {
            work->vz = GetRandom() % 181 + 204;

            if (work->vx > 0) {
                work->vx = -(GetRandom() % 257 + 128);
            } else {
                work->vx = GetRandom() % 257 + 128;
            }
        }

        if (work->z >= 0) {
            return 0;
        }

        break;
    }

    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_mahluxia_flw_2(MahluxiaFlwWork* work) {
    s16 x;
    s16 y;
    void* gfx;

    gfx = AnimGetGfx(&work->anim);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, NULL, SPRITE_PRIORITY(2),
        -0x1004 - (work->y >> 8) * 4);
}

void task_hum_mahluxia_flw_3(MahluxiaFlwWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}
