/**
 * map_goofy.c
 * Goofy Field NPC
 */

#include "map_tasks.h"
#include "sprites_evt.h"
#include "sprite_palettes.h"
#include "gba/keys.h"
#include "anim.h"
#include "btl_collision.h"
#include "card_api.h"
#include "field_state.h"
#include "fld_types.h"
#include "game_state.h"
#include "key.h"
#include "map.h"
#include "map_api.h"
#include "map_types.h"
#include "obj.h"
#include "obj_api.h"
#include "registration_data.h"
#include "task_descriptors.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "card_message_data.h"
#include "battle_actor_types.h"

void MapGoofyCheckTalk(MapGoofyWork* work) {
    if (work->targeted && (GetKeysPressed() & A_BUTTON)) {
        gFieldState->flags |= FIELD_FLAG_FREEZE_PLAYER;

        if (gGameState.floor == 12 && gMapFloorState.room == MAP_ROOM_EXIT_HALL) {
            CreateCardMessageTask(&work->tasks, 0, CARD_MSG_GOOFY_EXIT_HALL_TALK);
        } else {
            CreateCardMessageTask(&work->tasks, 0, gGoofyTalkMessages[gMapFloorState.progress]);
        }

        work->update = MapGoofyWaitMessage;
    }
}

void MapGoofyWaitMessage(MapGoofyWork* work) {
    if (!IsMessageWindowOpen()) {
        gFieldState->flags &= ~FIELD_FLAG_FREEZE_PLAYER;
        work->update = MapGoofyCheckTalk;
    }
}

void Task_MapGoofy_0(MapGoofyWork* work) {
    FldObj* obj = &work->obj;

    if (gMapFloorState.room != MAP_ROOM_ENTRANCE_HALL) {
        if (gGameState.floor == 12) {
            work->obj.fieldPosition.x = 0x25000;
            work->obj.fieldPosition.y = 0x10A00;
        } else {
            work->obj.fieldPosition.x = 0x20000;
            work->obj.fieldPosition.y = 0xB000;
        }
    } else {
        if (gGameState.floor != 0) {
            work->obj.fieldPosition.x = 0x1E800;
            work->obj.fieldPosition.y = 0xD000;
        } else {
            work->obj.fieldPosition.x = 0x2C000;
            work->obj.fieldPosition.y = 0xE000;
        }
    }

    obj->fieldPosition.z = 0;
    obj->fieldPosition.ground = GetFldPosFloor(&obj->fieldPosition);
    obj->fieldPosition.z = obj->fieldPosition.ground;
    obj->fieldPosition.y -= obj->fieldPosition.ground;
    obj->angle = FLD_ANGLE_DOWN;
    obj->height = 0x30;
    obj->kind = FLD_OBJ_KIND_NPC;
    work->visible = TRUE;
    work->update = MapGoofyCheckTalk;
    work->tiles = AllocObjTiles(0x400, gGoofyFl00Tiles);
    work->palette = LoadObjPalette(gGoofyPalette, sizeof(gGoofyPalette));
    AnimInit(&work->anim, gGoofyFl00Anims, gGoofyFl00Frames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
    ColliderInit(&work->collider, COLLIDER_TYPE_NPC, 16, 48);
    ColliderSetPosition(&work->collider, obj->fieldPosition.x, obj->fieldPosition.y, obj->fieldPosition.z);
    FldObjRegister(obj);
    TaskPoolInit(&work->tasks, 2);
    TaskCreate(&work->tasks, &gTaskDescFldShadow, &work->obj);
    work->targeted = FALSE;
    TaskPoolInit(&work->tasks2, 1);
    TaskCreate(&work->tasks2, &gTaskDescMapTalk, &work->obj);
}

s32 Task_MapGoofy_1(MapGoofyWork* work) {
    if ((u8)IsMapInterrupted()) {
        work->visible = FALSE;
    } else {
        work->visible = TRUE;
        work->targeted = IsFldObjTalkTarget(&work->obj);
        TaskPoolUpdate(&work->tasks);
        TaskPoolUpdate(&work->tasks2);
        AnimUpdate(&work->anim);

        if (work->update != NULL) {
            work->update(work);
        }
    }

    return 1;
}

void Task_MapGoofy_2(MapGoofyWork* work) {
    FldPos* pos = &work->obj.fieldPosition;
    u16 priority;
    s32 pixelY;
    s16 x;
    s16 y;

    if (work->visible) {
        x = (pos->x >> 8) - (gFieldState->x >> 8);
        pixelY = pos->y >> 8;
        y = pixelY + (pos->z >> 8) - (gFieldState->y >> 8);
        priority = -0x1004 - pixelY * 4;
        DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, work->palette, NULL, SPRITE_PRIORITY(2), priority);
        work->obj.shadowZ = pos->ground;
        work->obj.shadowPriority = priority + 1;
        TaskPoolDraw(&work->tasks);

        if (work->targeted) {
            TaskPoolDraw(&work->tasks2);
        }
    }
}

void Task_MapGoofy_3(MapGoofyWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ColliderUnregister(&work->collider);
    FldObjUnregister(&work->obj);
    TaskPoolDestroy(&work->tasks);
    TaskPoolDestroy(&work->tasks2);
}

const u8 gGoofyTalkMessages[28] = {
    CARD_MSG_GOOFY_TALK_00,
    CARD_MSG_GOOFY_TALK_01,
    CARD_MSG_GOOFY_TALK_02,
    CARD_MSG_GOOFY_TALK_03,
    CARD_MSG_GOOFY_TALK_04,
    CARD_MSG_GOOFY_TALK_05,
    CARD_MSG_GOOFY_TALK_06,
    CARD_MSG_GOOFY_TALK_07,
    CARD_MSG_GOOFY_TALK_08,
    CARD_MSG_GOOFY_TALK_09,
    CARD_MSG_GOOFY_TALK_10,
    CARD_MSG_GOOFY_TALK_11,
    CARD_MSG_GOOFY_TALK_12,
    CARD_MSG_GOOFY_TALK_13,
    CARD_MSG_GOOFY_TALK_14,
    CARD_MSG_GOOFY_TALK_15,
    CARD_MSG_GOOFY_TALK_16,
    CARD_MSG_GOOFY_TALK_17,
    CARD_MSG_GOOFY_TALK_18,
    CARD_MSG_GOOFY_TALK_19,
    CARD_MSG_GOOFY_TALK_20,
    CARD_MSG_GOOFY_TALK_21,
    CARD_MSG_GOOFY_TALK_21,
    CARD_MSG_GOOFY_TALK_21,
    CARD_MSG_GOOFY_TALK_22,
    CARD_MSG_GOOFY_TALK_22,
    CARD_MSG_GOOFY_TALK_23,
    CARD_MSG_GOOFY_TALK_23,
};

TaskDesc gTaskDescMapGoofy = {
    "Task_MapGoofy",
    (TaskInitFunc)Task_MapGoofy_0,
    (TaskUpdateFunc)Task_MapGoofy_1,
    (TaskDrawFunc)Task_MapGoofy_2,
    (TaskDestroyFunc)Task_MapGoofy_3,
    sizeof(MapGoofyWork),
};
