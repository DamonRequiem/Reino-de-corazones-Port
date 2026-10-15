/**
 * bos_map.c
 * Boss Battle Map and Shadow
 */

#include "bos_map.h"
#include "sprites_btl.h"
#include "boss_background_types.h"
#include <stddef.h>
#include "btl_api.h"
#include "bos_tasks.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "display.h"
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "engine_math.h"
#include "gba/defines.h"

void task_bos_map_0(BosMapWork* work, BosMapConfig* cfg) {
    LoadBgTiles(0, cfg->tiles, cfg->tilesSize);
    LoadBgPalette(0, cfg->palette, cfg->paletteSize);
    SetBgMapBlocks(0, cfg->maps, 2, 2);

    gBtlWork->scale = Q_8_8(1);
    gBtlWork->zoomScale = Q_8_8(1);
    gBtlWork->x = 0x10000;
    gBtlWork->y = 0x14000;
    gBtlWork->viewX = 0x10000;
    gBtlWork->viewY = 0x14000;
    gBtlWork->x2 = 0x10000;
    gBtlWork->y2 = 0x14000;
    gBtlWork->zoomX = 0x10000;
    gBtlWork->zoomY = 0x14000;
    gBtlWork->zoomSteps = 15;
    gBtlWork->rotation = 0;
    BtlMapResetShake();

    ScrollBgMapTo(0, gBtlWork->viewX >> 8, gBtlWork->viewY >> 8);
}

s32 task_bos_map_1() {
    s32 dx;
    s32 dy;
    s32 y;

    BtlMapUpdateShake();

    dx = (gBtlWork->x2 - gBtlWork->x) >> 3;
    dy = (gBtlWork->y2 - gBtlWork->y) >> 3;

    if (dx > 0x500) {
        dx = 0x500;
    } else if (dx < -0x500) {
        dx = -0x500;
    }

    gBtlWork->x += dx;
    gBtlWork->y += dy;
    gBtlWork->viewX = gBtlWork->x;
    gBtlWork->viewY = gBtlWork->y;

    if (gBtlWork->viewX - ((DISPLAY_WIDTH / 2) << 8) < (gBtlWork->xMin << 8)) {
        gBtlWork->viewX = (gBtlWork->xMin + DISPLAY_WIDTH / 2) << 8;
    } else if (gBtlWork->viewX + ((DISPLAY_WIDTH / 2) << 8) > (gBtlWork->xMax << 8)) {
        gBtlWork->viewX = (gBtlWork->xMax - DISPLAY_WIDTH / 2) << 8;
    }

    if (gBtlWork->viewY + ((DISPLAY_HEIGHT / 2) << 8) < (gBtlWork->yMin << 8)) {
        gBtlWork->viewY = (gBtlWork->yMin - DISPLAY_HEIGHT / 2) << 8;
    } else if (gBtlWork->viewY + ((DISPLAY_HEIGHT / 2) << 8) > (gBtlWork->yMax << 8)) {
        gBtlWork->viewY = (gBtlWork->yMax - DISPLAY_HEIGHT / 2) << 8;
    }

    y = gBtlWork->viewY + BtlMapGetShake();
    gBtlWork->viewY = y;
    ScrollBgMapTo(0, (gBtlWork->viewX >> 8) + 8, (y >> 8) + 0x28);

    return 1;
}

void task_bos_shadow_0(BosShadowWork* work, BtlObj* obj) {
    work->actor = obj;
    work->tiles = LoadObjTiles(gBtlShadowTiles, sizeof(gBtlShadowTiles));
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
}

s32 task_bos_shadow_1() {
    return 1;
}

void task_bos_shadow_2(BosShadowWork* work) {
    BtlObj* obj;
    s16 x;
    s16 y;
    s32 size;
    u8 doubleSize;
    u16 flags;
    ObjAffine* affine;
    void* gfx;

    obj = work->actor;
    doubleSize = FALSE;
    gfx = gBtlShadowFrame0;
    flags = GetBattleSpritePriorityFlags(obj->y);
    size = Q_8_8(1) - ((obj->groundZ - obj->z) >> 7);

    if (size <= 0xB2) {
        size = Q_8_8(0.7);
    }

    if (work->actor->flags & BTLOBJ_FLAG_LARGE_SHADOW) {
        size += Q_8_8(1);
        doubleSize = TRUE;
    }

    affine = AllocObjAffine(0, size, size, doubleSize);
    WorldToScreen(&x, &y, obj->x, obj->y, obj->groundZ);
    DrawSprite(x, y, gfx, work->tiles, work->palette, affine, flags, 0xFFF0);
}

void task_bos_shadow_3(BosShadowWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescBosMap = {
    "task_bos_map",
    (TaskInitFunc)task_bos_map_0,
    (TaskUpdateFunc)task_bos_map_1,
    NULL,
    NULL,
    sizeof(BosMapWork),
};

TaskDesc gTaskDescBosShadow = {
    "task_bos_shadow",
    (TaskInitFunc)task_bos_shadow_0,
    (TaskUpdateFunc)task_bos_shadow_1,
    (TaskDrawFunc)task_bos_shadow_2,
    (TaskDestroyFunc)task_bos_shadow_3,
    sizeof(BosShadowWork),
};
