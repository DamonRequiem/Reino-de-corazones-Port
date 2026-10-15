/**
 * map_niseriku.c
 * Riku Replica Field NPC
 */

#include "map_tasks.h"
#include "sprites_evt.h"
#include "sprites_map_tasks.h"
#include "sprite_palettes.h"
#include "gba/keys.h"
#include "fade.h"
#include "engine_math.h"
#include "anim.h"
#include "btl_collision.h"
#include "card_api.h"
#include "field_state.h"
#include "fld_types.h"
#include "key.h"
#include "map.h"
#include "map_api.h"
#include "map_types.h"
#include "msg_api.h"
#include "obj.h"
#include "obj_api.h"
#include "registration_data.h"
#include "task_descriptors.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "card_message_data.h"
#include "event_ids.h"
#include "battle_actor_types.h"

void MapNiserikuCheckTalk(MapNiserikuWork* work) {
    if (work->targeted && (GetKeysPressed() & A_BUTTON)) {
        gFieldState->flags |= FIELD_FLAG_FREEZE_PLAYER;
        CreateCardMessageTask(&work->tasks, 0, CARD_MSG_RIKU_REPLICA_TALK);
        work->update = MapNiserikuWaitMessage;
    }
}

void MapNiserikuWaitMessage(MapNiserikuWork* work) {
    if (!IsMessageWindowOpen()) {
        gFieldState->flags &= ~FIELD_FLAG_FREEZE_PLAYER;
        work->update = MapNiserikuCheckTalk;
    }
}

void MapNiserikuWaitApproach(MapNiserikuWork* work) {
    s32 dx;
    s32 dy;

    dx = work->obj.fieldPosition.x - gFieldState->actor.fieldPosition.x;

    if (dx < 0) {
        dx = gFieldState->actor.fieldPosition.x - work->obj.fieldPosition.x;
    }

    dy = work->obj.fieldPosition.y - gFieldState->actor.fieldPosition.y;

    if (dy < 0) {
        dy = gFieldState->actor.fieldPosition.y - work->obj.fieldPosition.y;
    }

    if (dx <= 0x8000 && dy <= 0x8000) {
        if (Sqrt8((dx * dx >> 8) + (dy * dy >> 8)) < 0x3000) {
            FadeStartOut(FADE_MODE_BLACK, 16);
            gFieldState->flags |= FIELD_FLAG_FREEZE_PLAYER;
            work->update = MapNiserikuStartEvent;
        }
    }
}

void MapNiserikuStartEvent(MapNiserikuWork* work) {
    if (!FadeIsActive()) {
        RequestEventMode(EVENT_059_12F_GOAL_2);
        work->update = NULL;
    }
}

void Task_MapNiseriku_0(MapNiserikuWork* work) {
    FldObj* obj = &work->obj;
    s32 registered;

    switch (gMapFloorState.progress) {
    case 27:
        obj->fieldPosition.x = 0x27C00;
        obj->fieldPosition.y = 0x10700;
        break;
    case 23:
        obj->fieldPosition.x = 0x24900;
        obj->fieldPosition.y = 0xD500;
        break;
    case 24:
    case 25:
    case 26:
    default:
        obj->fieldPosition.x = 0x17A00;
        obj->fieldPosition.y = 0x11000;
        break;
    }

    obj->fieldPosition.z = 0;
    obj->fieldPosition.z = obj->fieldPosition.ground = GetFldPosFloor(&obj->fieldPosition);
    obj->fieldPosition.y -= obj->fieldPosition.z;
    obj->angle = FLD_ANGLE_DOWN_LEFT;
    obj->height = 48;
    obj->kind = FLD_OBJ_KIND_NPC;

    registered = FALSE;

    if (gMapFloorState.progress == 27) {
        registered = TRUE;
    }

    work->registered = registered;

    work->visible = TRUE;
    work->targeted = FALSE;
    TaskPoolInit(&work->tasks2, 1);
    TaskCreate(&work->tasks2, &gTaskDescMapTalk, &work->obj);
    TaskPoolInit(&work->tasks, 2);

    switch (gMapFloorState.progress) {
    case 27:
        work->update = MapNiserikuCheckTalk;
        work->tiles = AllocObjTiles(0x680, gNiseFl00Tiles);
        work->palette = LoadObjPalette(gNiserikuPalette, sizeof(gNiserikuPalette));
        AnimInit(&work->anim, gNiseFl00Anims, gNiseFl00Frames);
        AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
        ColliderInit(&work->collider, COLLIDER_TYPE_NPC, 16, 48);
        ColliderSetPosition(&work->collider, obj->fieldPosition.x, obj->fieldPosition.y, obj->fieldPosition.z);
        TaskCreate(&work->tasks, &gTaskDescFldShadow, &work->obj);
        break;
    case 23:
        work->update = MapNiserikuWaitApproach;
        work->tiles = AllocObjTiles(0x320, gNiserikuHizaFTiles);
        work->palette = LoadObjPalette(gNiserikuPalette, sizeof(gNiserikuPalette));
        AnimInit(&work->anim, gNiserikuHizaFAnims, gNiserikuHizaFFrames);
        AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
        ColliderInit(&work->collider, COLLIDER_TYPE_NPC, 16, 48);
        ColliderSetPosition(&work->collider, obj->fieldPosition.x, obj->fieldPosition.y, obj->fieldPosition.z);
        TaskCreate(&work->tasks, &gTaskDescFldShadow, &work->obj);
        break;
    case 24:
    case 25:
    case 26:
    default:
        work->update = NULL;
        work->tiles = AllocObjTiles(0x300, gNiserikuDownFTiles);
        work->palette = LoadObjPalette(gNiserikuPalette, sizeof(gNiserikuPalette));
        AnimInit(&work->anim, gNiserikuDownFAnims, gNiserikuDownFFrames);
        AnimStart(&work->anim, 1, ANIM_FLAG_LOOP);
        ColliderInit(&work->collider, COLLIDER_TYPE_NPC, 36, 48);
        ColliderSetPosition(&work->collider, obj->fieldPosition.x, obj->fieldPosition.y, obj->fieldPosition.z);
        break;
    }

    if (work->registered) {
        FldObjRegister(obj);
    }
}

s32 Task_MapNiseriku_1(MapNiserikuWork* work) {
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

void Task_MapNiseriku_2(MapNiserikuWork* work) {
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

void Task_MapNiseriku_3(MapNiserikuWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ColliderUnregister(&work->collider);

    if (work->registered) {
        FldObjUnregister(&work->obj);
    }

    TaskPoolDestroy(&work->tasks);
    TaskPoolDestroy(&work->tasks2);
}

TaskDesc gTaskDescMapNiseriku = {
    "Task_MapNiseriku",
    (TaskInitFunc)Task_MapNiseriku_0,
    (TaskUpdateFunc)Task_MapNiseriku_1,
    (TaskDrawFunc)Task_MapNiseriku_2,
    (TaskDestroyFunc)Task_MapNiseriku_3,
    sizeof(MapNiserikuWork),
};
