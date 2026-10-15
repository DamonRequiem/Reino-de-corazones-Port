/**
 * map_mickey.c
 * King Mickey Field NPC
 */

#include "map_tasks.h"
#include "sprites_map_tasks.h"
#include "sprite_palettes.h"
#include "gba/keys.h"
#include "anim.h"
#include "btl_collision.h"
#include "card_api.h"
#include "field_state.h"
#include "fld_types.h"
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

void MapMickeyCheckTalk(MapMickeyWork* work) {
    if (work->targeted && (GetKeysPressed() & A_BUTTON)) {
        gFieldState->flags |= FIELD_FLAG_FREEZE_PLAYER;

        switch (gMapFloorState.progress) {
        case 20:
            CreateCardMessageTask(&work->tasks, 0, CARD_MSG_MICKEY_TALK_2);
            break;
        case 22:
            CreateCardMessageTask(&work->tasks, 0, CARD_MSG_MICKEY_TALK_0);
            break;
        case 23:
        default:
            CreateCardMessageTask(&work->tasks, 0, CARD_MSG_MICKEY_TALK_1);
            break;
        }

        work->update = MapMickeyWaitMessage;
    }
}

void MapMickeyWaitMessage(MapMickeyWork* work) {
    if (!IsMessageWindowOpen()) {
        gFieldState->flags &= ~FIELD_FLAG_FREEZE_PLAYER;
        work->update = MapMickeyCheckTalk;
    }
}

void Task_MapMickey_0(MapMickeyWork* work) {
    FldObj* obj = &work->obj;

    obj->fieldPosition.x = 0x1C800;
    obj->fieldPosition.y = 0xE000;
    work->spriteFlags = SPRITE_PRIORITY(2) | SPRITE_FLAG_HFLIP;
    obj->fieldPosition.z = 0;
    obj->fieldPosition.ground = GetFldPosFloor(&obj->fieldPosition);
    obj->fieldPosition.z = obj->fieldPosition.ground;
    obj->fieldPosition.y -= obj->fieldPosition.ground;
    obj->angle = FLD_ANGLE_DOWN_LEFT;
    obj->height = 0x30;
    obj->kind = FLD_OBJ_KIND_NPC;
    work->visible = TRUE;
    work->update = MapMickeyCheckTalk;
    work->tiles = AllocObjTiles(0x300, gMickeyFl00Tiles);
    work->palette = LoadObjPalette(gMickeyPalette, sizeof(gMickeyPalette));
    AnimInit(&work->anim, gMickeyFl00Anims, gMickeyFl00Frames);
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

s32 Task_MapMickey_1(MapMickeyWork* work) {
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

void Task_MapMickey_2(MapMickeyWork* work) {
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
        DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, work->palette, NULL, work->spriteFlags, priority);
        work->obj.shadowZ = pos->ground;
        work->obj.shadowPriority = priority + 1;
        TaskPoolDraw(&work->tasks);

        if (work->targeted) {
            TaskPoolDraw(&work->tasks2);
        }
    }
}

void Task_MapMickey_3(MapMickeyWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ColliderUnregister(&work->collider);
    FldObjUnregister(&work->obj);
    TaskPoolDestroy(&work->tasks);
    TaskPoolDestroy(&work->tasks2);
}

TaskDesc gTaskDescMapMickey = {
    "Task_MapMickey",
    (TaskInitFunc)Task_MapMickey_0,
    (TaskUpdateFunc)Task_MapMickey_1,
    (TaskDrawFunc)Task_MapMickey_2,
    (TaskDestroyFunc)Task_MapMickey_3,
    sizeof(MapMickeyWork),
};
