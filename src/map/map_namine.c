/**
 * map_namine.c
 * Namine Field NPC
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

void MapNamineCheckTalk(MapNamineWork* work) {
    if (work->targeted && (GetKeysPressed() & A_BUTTON)) {
        gFieldState->flags |= FIELD_FLAG_FREEZE_PLAYER;

        if (gMapFloorState.progress == 27) {
            CreateCardMessageTask(&work->tasks, 0, CARD_MSG_NAMINE_TALK_1);
        } else {
            CreateCardMessageTask(&work->tasks, 0, CARD_MSG_NAMINE_TALK_0);
        }

        work->update = MapNamineWaitMessage;
    }
}

void MapNamineWaitMessage(MapNamineWork* work) {
    if (!IsMessageWindowOpen()) {
        gFieldState->flags &= ~FIELD_FLAG_FREEZE_PLAYER;
        work->update = MapNamineCheckTalk;
    }
}

void Task_MapNamine_0(MapNamineWork* work) {
    FldObj* obj = &work->obj;

    switch (gMapFloorState.progress) {
    case 27:
        work->obj.fieldPosition.x = 0x20D00;
        work->obj.fieldPosition.y = 0xD500;
        work->spriteFlags = SPRITE_PRIORITY(2);
        break;
    case 23:
        work->obj.fieldPosition.x = 0x27C00;
        work->obj.fieldPosition.y = 0xD400;
        work->spriteFlags = SPRITE_PRIORITY(2);
        break;
    case 24:
    case 25:
    case 26:
    default:
        obj->fieldPosition.x = 0x15200;
        obj->fieldPosition.y = 0xF800;
        work->spriteFlags = SPRITE_PRIORITY(2) | SPRITE_FLAG_HFLIP;
        break;
    }

    obj->fieldPosition.z = 0;
    obj->fieldPosition.z = obj->fieldPosition.ground = GetFldPosFloor(&obj->fieldPosition);
    obj->fieldPosition.y -= obj->fieldPosition.ground;
    obj->angle = FLD_ANGLE_DOWN_LEFT;
    obj->height = 48;
    obj->kind = FLD_OBJ_KIND_NPC;
    work->registered = gMapFloorState.progress != 23;
    work->visible = TRUE;
    work->update = MapNamineCheckTalk;
    work->tiles = AllocObjTiles(0x300, gNamiF00Tiles);
    work->palette = LoadObjPalette(gNaminePalette, sizeof(gNaminePalette));
    AnimInit(&work->anim, gNamiF00Anims, gNamiF00Frames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
    ColliderInit(&work->collider, COLLIDER_TYPE_NPC, 16, 48);
    ColliderSetPosition(&work->collider, obj->fieldPosition.x, obj->fieldPosition.y, obj->fieldPosition.z);

    if (work->registered) {
        FldObjRegister(obj);
    }

    TaskPoolInit(&work->tasks, 2);
    TaskCreate(&work->tasks, &gTaskDescFldShadow, &work->obj);
    work->targeted = FALSE;
    TaskPoolInit(&work->tasks2, 1);
    TaskCreate(&work->tasks2, &gTaskDescMapTalk, &work->obj);
}

s32 Task_MapNamine_1(MapNamineWork* work) {
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

void Task_MapNamine_2(MapNamineWork* work) {
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

void Task_MapNamine_3(MapNamineWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ColliderUnregister(&work->collider);

    if (work->registered) {
        FldObjUnregister(&work->obj);
    }

    TaskPoolDestroy(&work->tasks);
    TaskPoolDestroy(&work->tasks2);
}

TaskDesc gTaskDescMapNamine = {
    "Task_MapNamine",
    (TaskInitFunc)Task_MapNamine_0,
    (TaskUpdateFunc)Task_MapNamine_1,
    (TaskDrawFunc)Task_MapNamine_2,
    (TaskDestroyFunc)Task_MapNamine_3,
    sizeof(MapNamineWork),
};
