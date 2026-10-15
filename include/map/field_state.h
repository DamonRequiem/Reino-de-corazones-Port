#ifndef GUARD_FIELD_STATE_H
#define GUARD_FIELD_STATE_H

#include "types.h"
#include "fld_types.h"
#include "taskpool.h"
#include "macros.h"

enum FieldFlag {
    FIELD_FLAG_NO_LOCKON = 0x1,
    FIELD_FLAG_HOLD_LOCKON = 0x2,
    FIELD_FLAG_EXIT_ROOM = 0x10,
    FIELD_FLAG_FREEZE_ENEMIES = 0x80,
    FIELD_FLAG_HIDE_ENEMIES = 0x100,
    FIELD_FLAG_NO_ENEMY_SPAWN = 0x200,
    FIELD_FLAG_FREEZE_PLAYER = 0x1000,
    FIELD_FLAG_MENU_OPEN = 0x2000,
    FIELD_FLAG_ENEMY_FRAME_CHANGED = 0x10000,
    FIELD_FLAG_ROOM_CREATE = 0x40000,
    FIELD_FLAG_AUTO_WALK = 0x80000,
    FIELD_FLAG_CARD_POSE = 0x100000,
    FIELD_FLAG_DOOR_OPENED = 0x200000,
    FIELD_FLAG_PLAYER_JUMPING = 0x800000
};

typedef struct FieldState {
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;
    u16 tileCols;
    u16 tileRows;
    u8 unk_14[0x04];
    FldActor actor;
    void* lockonTarget;
    s16 lockonDelay;
    u32 flags;
    u16 unk_74;
    TaskPool tasks;
    TaskPool tasks2;
    TaskPool tasks3;
    TaskPool tasks4;
    TaskPool tasks5;
    s32 spawnX;
    s32 spawnY;
    u8 spawnAngle;
} FieldState;

STATIC_ASSERT(sizeof(FieldState) == 0xE8, FieldStateSize);

extern FieldState* gFieldState;

#endif
