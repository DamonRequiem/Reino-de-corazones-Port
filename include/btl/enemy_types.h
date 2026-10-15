#ifndef GUARD_ENEMY_TYPES_H
#define GUARD_ENEMY_TYPES_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "battle_actor_types.h"

enum EmyDefFlag {
    EMY_DEF_FLAG_NO_SHADOW = 0x1,
    EMY_DEF_FLAG_NO_SCALE_IN = 0x2
};

enum EmyFlag {
    EMY_FLAG_DARK_DEATH = 0x1,
    EMY_FLAG_AT_FIELD_EDGE = 0x2,
    EMY_FLAG_LUNGE_HIT = 0x4
};

typedef struct EmyDef {
    void* palette;
    const AnimDef* animDef;
    s32 speed;
    u16 moveInterval;
    u16 turnInterval;
    u16 hitStunFrames;
    u16 attackOffset;
    u16 attackRangeX;
    u16 attackRangeY;
    u16 cardInterval;
    u16 flags;
    EmyKind kind;
} EmyDef;

enum EmyState {
    EMY_STATE_IDLE,
    EMY_STATE_HURT,
    EMY_STATE_HURT_RECOVER,
    EMY_STATE_DEFEATED,
    EMY_STATE_WALK,
    EMY_STATE_CARD_BROKEN,
    EMY_STATE_HEALED,
    EMY_STATE_HOVER,
    EMY_STATE_HOVER_MOVE,
    EMY_STATE_STUNNED,
    EMY_STATE_WARPED,
    EMY_STATE_SPAWN,
    EMY_STATE_STOPPED,
    EMY_STATE_TERRIFIED,
    EMY_STATE_FLEE,
    EMY_STATE_GRAVITY_SQUASH,
    EMY_STATE_GRAVITY_HOLD,
    EMY_STATE_GRAVITY_RECOVER
};

typedef struct EmyWork {
    void* tiles;
    void* palette;
    void* palette2;
    void* gfx;
    AnimState anim;
    TaskPool tasks;
    BtlObj actor;
    u32 state;
    u32 idleState;
    s16 stateTimer;
    s16 steps;
    u16 flags;
    u8 visible;
    const EmyDef* def;
    u8 angle;
    u16 spriteFlags;
    s32 speed;
    s32 vz;
    u32 fxScale;
    s32 x;
    s32 y;
    s32 hoverZ;
    s32 scaleX;
    s32 scaleY;
} EmyWork;

typedef struct EmyObj {
    s32 x;
    s32 y;
    s32 z;
} EmyObj;

#endif
