/**
 * room_name.c
 * Room Name Display
 */

#include "text.h"
#include "monsgage.h"
#include "room_name.h"
#include "sprites_map.h"
#include "sprites_map_tasks.h"
#include "map_text_data.h"
#include "jiminy_data.h"
#include "common_text.h"
#include "field_state.h"
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "text_types.h"
#include "engine_math.h"
#include "macros.h"

const MapNameText* gRoomNames[28] = {
    LOCALIZED(gRoomNameTeemingDarkness),
    LOCALIZED(gRoomNameTranquilDarkness),
    LOCALIZED(gRoomNameGuardedTrove),
    LOCALIZED(gRoomNameLoomingDarkness),
    LOCALIZED(gRoomNameSleepingDarkness),
    LOCALIZED(gRoomNameMomentsReprieve),
    LOCALIZED(gRoomNameFeebleDarkness),
    LOCALIZED(gRoomNameAlmightyDarkness),
    LOCALIZED(gRoomNameCalmBounty),
    LOCALIZED(gRoomNameFalseBounty),
    LOCALIZED(gRoomNameMoogleRoom),
    LOCALIZED(gRoomNameSorcerousWaking),
    LOCALIZED(gRoomNameMartialWaking),
    LOCALIZED(gRoomNameAlchemicWaking),
    LOCALIZED(gRoomNameMeetingGround),
    LOCALIZED(gRoomNameMinglingWorlds),
    LOCALIZED(gRoomNameStrongInitiative),
    LOCALIZED(gRoomNameLastingDaze),
    LOCALIZED(gRoomNameStagnantSpace),
    LOCALIZED(gRoomNamePremiumRoom),
    LOCALIZED(gRoomNameWhiteRoom),
    LOCALIZED(gRoomNameBlackRoom),
    LOCALIZED(gRoomNameKeyOfBeginnings),
    LOCALIZED(gRoomNameKeyOfGuidance),
    LOCALIZED(gRoomNameKeyToTruth),
    LOCALIZED(gRoomNameKeyToRewards),
    LOCALIZED(gRoomNameUnknownPlace),
    LOCALIZED(gRoomNameHiddenChamber),
};

enum RoomNameState {
    ROOM_NAME_STATE_DELAY,
    ROOM_NAME_STATE_OPEN,
    ROOM_NAME_STATE_HOLD,
    ROOM_NAME_STATE_CLOSE
};

void task_room_name_0(RoomNameWork* work, s32 nameId) {
    work->tiles = LoadObjTiles(gMapNameBarTiles, sizeof(gMapNameBarTiles));
    work->palette = LoadObjPalette(gMapFloorNamePalette, sizeof(gMapFloorNamePalette));
    work->gfx = gMapNameBarFrames[0];
    work->nameId = nameId;
    work->x2 = 0x5C00;
    work->y2 = 0x8A00;
    work->x = 0x7800;
    work->y = 0x8A00;
    work->unk_20 = 0x400;
    work->unk_24 = 0x19;
    work->timer = 0;
    work->unk_2C = 0;
    work->state = ROOM_NAME_STATE_DELAY;
    work->scaleY = Q_8_8(0.1);
    InitTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    work->palette2 = LoadTextPalette(1);
#ifdef VERSION_EU
    work->textSlotCount = LoadTextSlots(GetLocalizedString(gRoomNames[work->nameId]), work->textSlots);
#else
    work->textSlotCount = LoadTextSlots(gRoomNames[work->nameId], work->textSlots);
#endif
}

u8 task_room_name_1(RoomNameWork* work) {
    if (gFieldState->flags & (FIELD_FLAG_MENU_OPEN | FIELD_FLAG_ROOM_CREATE)) {
        return 0;
    }

    switch (work->state) {
    case ROOM_NAME_STATE_DELAY:
        work->timer++;

        if (work->timer > 0x27) {
            work->timer = 0;
            work->state++;
        }

        break;
    case ROOM_NAME_STATE_OPEN:
        work->timer++;

        if (work->timer > 1) {
            work->timer = 0;
            work->y2 -= 0x99;
            work->scaleY += Q_8_8(0.1);

            if (work->scaleY > 0xFF) {
                work->scaleY = Q_8_8(1);
                work->state++;
            }
        }

        break;
    case ROOM_NAME_STATE_HOLD:
        work->timer++;

        if (work->timer > 0xB3) {
            work->timer = 0;
            work->state++;
        }

        break;
    case ROOM_NAME_STATE_CLOSE:
        work->timer++;

        if (work->timer > 1) {
            work->timer = 0;
            work->y2 += 0x99;
            work->scaleY -= Q_8_8(0.1);

            if (work->scaleY <= Q_8_8(0.1)) {
                work->scaleY = Q_8_8(0.1);
                return 0;
            }
        }

        break;
    }

    return 1;
}

void task_room_name_2(RoomNameWork* work) {
    ObjAffine* affine;

    if (work->state != ROOM_NAME_STATE_DELAY) {
        affine = AllocObjAffine(0, Q_8_8(1), work->scaleY, FALSE);
        DrawSprite(work->x >> 8, work->y >> 8, work->gfx, work->tiles, work->palette, affine, 0, 0x3C);
        DrawTextSlots(work->x2 >> 8, work->y2 >> 8, work->textSlots, work->palette2, 0x32, work->textSlotCount);
    }
}

void task_room_name_3(RoomNameWork* work) {
    ReleaseObjTiles(work->tiles);
    FreeTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
}

TaskDesc gTaskDescRoomName = {
    "task_room_name",
    (TaskInitFunc)task_room_name_0,
    (TaskUpdateFunc)task_room_name_1,
    (TaskDrawFunc)task_room_name_2,
    (TaskDestroyFunc)task_room_name_3,
    sizeof(RoomNameWork),
};
