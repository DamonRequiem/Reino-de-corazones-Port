#ifndef GUARD_FLD_TYPES_H
#define GUARD_FLD_TYPES_H

#include "types.h"
#include "anim.h"
#include "listpool.h"
#include "taskpool.h"
#include "obj.h"
#include "battle_actor_types.h"
#include "macros.h"

typedef struct FldPos {
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
} FldPos;

typedef AnimDef FldAnimDef;

typedef ObjPalette FldRes;

enum FldAngle {
    FLD_ANGLE_UP = 0x00,
    FLD_ANGLE_UP_RIGHT = 0x2D,
    FLD_ANGLE_RIGHT = 0x40,
    FLD_ANGLE_DOWN_RIGHT = 0x53,
    FLD_ANGLE_DOWN = 0x80,
    FLD_ANGLE_DOWN_LEFT = 0xAD,
    FLD_ANGLE_LEFT = 0xC0,
    FLD_ANGLE_UP_LEFT = 0xD3
};

enum FldClimbDir {
    FLD_CLIMB_DIR_NONE,
    FLD_CLIMB_DIR_UP_RIGHT,
    FLD_CLIMB_DIR_UP_LEFT
};

enum FldObjKind {
    FLD_OBJ_KIND_PLAYER,
    FLD_OBJ_KIND_ENEMY,
    FLD_OBJ_KIND_NPC,
    FLD_OBJ_KIND_FIXTURE
};

typedef struct FldActor {
    FldPos fieldPosition;
    s32 speed;
    u8 angle;
    u8 unk_15[0x05];
    u16 height;
    ListNode node;
    u16 kind;
    u16 unk_32;
    u8 unk_34[0x06];
    u16 shadowPriority;
    s32 shadowZ;
    ListPool pool;
} FldActor;

typedef struct FldObj {
    FldPos fieldPosition;
    s32 speed;
    u8 angle;
    u8 unk_15[0x05];
    s16 height;
    ListNode node;
    u16 kind;
    u16 unk_32;
    u16 unk_34;
    u8 unk_36[0x04];
    u16 shadowPriority;
    s32 shadowZ;
} FldObj;

STATIC_ASSERT(sizeof(FldActor) == 0x50, FldActorSize);
STATIC_ASSERT(sizeof(FldObj) == 0x40, FldObjSize);

enum FldFlag {
    FLD_FLAG_HFLIP = 0x2,
    FLD_FLAG_NO_AIR_TURN = 0x4,
    FLD_FLAG_RESTORE_STATE = 0x8,
    FLD_FLAG_WALK_OUT = 0x10,
    FLD_FLAG_TO_WORLD_SELECT = 0x20
};

enum FldState {
    FLD_STATE_GROUND,
    FLD_STATE_GROUND_UNUSED,
    FLD_STATE_JUMP_START,
    FLD_STATE_JUMP_RISE,
    FLD_STATE_FALL,
    FLD_STATE_LAND,
    FLD_STATE_CLIMB,
    FLD_STATE_CLIMB_OVER,
    FLD_STATE_LEDGE_CATCH,
    FLD_STATE_LEDGE_HANG,
    FLD_STATE_LEDGE_CLIMB,
    FLD_STATE_ATTACK,
    FLD_STATE_AIR_ATTACK,
    FLD_STATE_GMK_JUMP_START,
    FLD_STATE_GMK_JUMP,
    FLD_STATE_WALK_OUT,
    FLD_STATE_WALK_OUT_TO_WORLD_SELECT,
    FLD_STATE_WALK_OUT_TO_EXIT,
    FLD_STATE_WORLD_SELECT_POSE,
    FLD_STATE_WALK_OUT_END
};

typedef struct FldWork {
    void* tiles;
    FldRes* palette;
    AnimState anim;
    void* gfx;
    TaskPool tasks;
    Collider collider;
    u32 state;
    s16 timer;
    s16 steps;
    u8 unk_9C;
    u8 unk_9D;
    u16 unk_9E;
    s32 vz;
    u16 flags;
    s32 animAction;
    const u16* sounds;
    s32 targetX;
    s32 targetY;
    s32 targetZ;
    u8 onCollider;
} FldWork;

STATIC_ASSERT(sizeof(FldWork) == 0xC0, FldWorkSize);

#endif
