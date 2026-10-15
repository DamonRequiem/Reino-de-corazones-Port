/**
 * roomcreate.c
 * Room Creation Sequence
 */

#include "task_descriptors.h"
#include "map_api.h"
#include "m4a_song.h"
#include "roomcreate.h"
#include "fade.h"
#include "songs.h"
#include "card_api.h"
#include "display.h"
#include "engine_math.h"
#include "field_state.h"
#include "fld_types.h"
#include "m4a_catalog_data.h"
#include "map_runtime.h"
#include "registration_data.h"
#include "taskpool.h"
#include "types.h"
#include "card_worldselect.h"
#include "map.h"

enum RoomCreateState {
    ROOM_CREATE_STATE_APPROACH,
    ROOM_CREATE_STATE_SELECT_CARD,
    ROOM_CREATE_STATE_WALK_BACK,
    ROOM_CREATE_STATE_CARD_POSE,
    ROOM_CREATE_STATE_OPEN_DOOR,
    ROOM_CREATE_STATE_WAIT,
    ROOM_CREATE_STATE_ENTER,
    ROOM_CREATE_STATE_IDLE
};

void task_roomcreate_0(RoomCreateWork* work) {
    FldObj* obj;

    ResetSelectedMapCard();
    gFieldState->flags |= FIELD_FLAG_ROOM_CREATE;
    gFieldState->flags |= FIELD_FLAG_HOLD_LOCKON;
    work->mapSelectStatus = MAP_SELECT_STATUS_OPEN;
    work->spotLightEnd = 0;
    work->timer = 0;
    work->state = ROOM_CREATE_STATE_APPROACH;
    SetBgPriority(0, 2);
    SetBgPriority(1, 2);
    TaskPoolInit(&work->tasks, 3);
    work->x = gFieldState->actor.fieldPosition.x;
    work->y = gFieldState->actor.fieldPosition.y;
    work->z = gFieldState->actor.fieldPosition.z;
    obj = gFieldState->lockonTarget;
    work->x2 = obj->fieldPosition.x;
    work->y2 = obj->fieldPosition.y;
    work->z2 = obj->fieldPosition.z;
    work->angle = obj->angle;
    work->frontX = work->x2 + gSineTable[work->angle] * 50;
    work->frontY = work->y2 + -gSineTable[work->angle + 0x40] * 50;
    work->frontZ = work->z2;
    work->playerAngle = gFieldState->actor.angle;
}

u8 task_roomcreate_1(RoomCreateWork* work) {
    s16 steps;
    s32 i;

    switch (work->state) {
    case ROOM_CREATE_STATE_APPROACH:
        if (work->timer == 0) {
            gFieldState->actor.angle = work->angle + 0x80;
            TaskCreate(&work->tasks, &gTaskDescSpotLight, &work->spotLightEnd);
            gFieldState->flags |= FIELD_FLAG_AUTO_WALK;
        }

        steps = 30 - work->timer;
        ApproachValue(&gFieldState->actor.fieldPosition.x, work->frontX, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.y, work->frontY, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.z, work->frontZ, steps);

        if (steps <= 1) {
            MapFreezeBg1();
            work->state = ROOM_CREATE_STATE_SELECT_CARD;
            gFieldState->flags &= ~FIELD_FLAG_AUTO_WALK;
            work->timer = 8;
        } else {
            MapSetCameraTarget((gFieldState->actor.fieldPosition.x + work->x2) / 2,
                          (gFieldState->actor.fieldPosition.y + gFieldState->actor.fieldPosition.z + work->y2 + work->z2) / 2);
            work->timer++;
        }

        break;
    case ROOM_CREATE_STATE_SELECT_CARD:
        if (work->timer > 0) {
            ApproachValue(&gFieldState->x, gFieldState->x2 - 0x7800, work->timer);
            ApproachValue(&gFieldState->y, gFieldState->y2 - 0x6000, work->timer);
            work->timer--;
        } else if (work->timer == 0) {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x80);
            CreateMapCardSelection(&work->tasks, &work->mapSelectStatus);
            SetBgPriority(1, 1);
            work->timer--;
        }

        switch (work->mapSelectStatus) {
        case MAP_SELECT_STATUS_CLOSED:
            work->state = ROOM_CREATE_STATE_WALK_BACK;
            work->timer = 0;
            MapRestoreBg1();
            SetBgPriority(1, 2);
            break;
        case MAP_SELECT_STATUS_CARD_CHOSEN:
            work->state = ROOM_CREATE_STATE_CARD_POSE;
            work->timer = 0;
            break;
        }

        break;
    case ROOM_CREATE_STATE_CARD_POSE:
        if (work->timer == 0) {
            gFieldState->flags |= FIELD_FLAG_CARD_POSE;
            DisableBg(2);
            DisableBg(3);
            FadeStartIn(FADE_MODE_BLACK, 1);
            work->timer++;
        } else if (work->timer == 1) {
            for (i = 0; i <= 31; i++) {
                FadeSetPaletteExcluded(i, FALSE);
            }

            work->timer++;
        } else if (work->timer <= 19) {
            work->timer++;
        } else if (work->timer == 20) {
            m4aSongNumStart(SONG_SYS_DOOR0);
            TaskCreate(&work->tasks, &gTaskDescRomcriEff2, (void*)(u32)work->angle);
            work->timer++;
        }

        if (work->mapSelectStatus == MAP_SELECT_STATUS_CLOSED) {
            work->timer = 0;
            work->state = ROOM_CREATE_STATE_OPEN_DOOR;
        }

        break;
    case ROOM_CREATE_STATE_OPEN_DOOR:
        if (work->timer == 16) {
            TaskCreate(&work->tasks, &gTaskDescRomcriEff, (void*)(u32)work->angle);
        }

        if (work->timer == 40) {
            gFieldState->flags |= FIELD_FLAG_DOOR_OPENED;
        }

        if (work->timer > 60) {
            work->timer = 0;
            work->state = ROOM_CREATE_STATE_ENTER;
            gFieldState->flags &= ~FIELD_FLAG_CARD_POSE;
        } else {
            work->timer++;
        }

        break;
    case ROOM_CREATE_STATE_WAIT:
        if (work->timer > 60) {
            work->timer = 0;
            work->state = ROOM_CREATE_STATE_ENTER;
        } else {
            work->timer++;
        }

        break;
    case ROOM_CREATE_STATE_WALK_BACK:
        if (work->timer == 0) {
            work->spotLightEnd = 1;
            gFieldState->flags |= FIELD_FLAG_AUTO_WALK;
        }

        steps = 30 - work->timer;
        ApproachValue(&gFieldState->actor.fieldPosition.x, work->x, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.y, work->y, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.z, work->z, steps);

        if (steps <= 1) {
            gFieldState->actor.angle = work->playerAngle;
            gFieldState->flags &= ~FIELD_FLAG_ROOM_CREATE;
            gFieldState->flags &= ~FIELD_FLAG_HOLD_LOCKON;
            DisableBg(0);
            SetBgPriority(1, 1);
            return 0;
        }

        work->timer++;
        MapSetCameraTarget((gFieldState->actor.fieldPosition.x + work->x2) / 2,
                      (gFieldState->actor.fieldPosition.y + gFieldState->actor.fieldPosition.z + work->y2 + work->z2) / 2);
        break;
    case ROOM_CREATE_STATE_ENTER:
        if (work->timer == 0) {
            gFieldState->flags |= FIELD_FLAG_AUTO_WALK;
        }

        steps = 40 - work->timer;
        ApproachValue(&gFieldState->actor.fieldPosition.x, work->x2, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.y, work->y2, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.z, work->z2, steps);

        if (IsAtTargetDoor(&gFieldState->actor.fieldPosition)) {
            gFieldState->flags |= FIELD_FLAG_EXIT_ROOM;
        }

        break;
    case ROOM_CREATE_STATE_IDLE:
        break;
    }

    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_roomcreate_2(RoomCreateWork* work) {
    TaskPoolDraw(&work->tasks);
}

void task_roomcreate_3(RoomCreateWork* work) {
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x100);
    TaskPoolDestroy(&work->tasks);
}

TaskDesc gTaskDescRoomcreate = {
    "task_roomcreate",
    (TaskInitFunc)task_roomcreate_0,
    (TaskUpdateFunc)task_roomcreate_1,
    (TaskDrawFunc)task_roomcreate_2,
    (TaskDestroyFunc)task_roomcreate_3,
    sizeof(RoomCreateWork),
};
