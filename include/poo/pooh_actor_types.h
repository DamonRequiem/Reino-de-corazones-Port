#ifndef GUARD_POOH_ACTOR_TYPES_H
#define GUARD_POOH_ACTOR_TYPES_H

#include "types.h"
#include "anim.h"
#include "battle_actor_types.h"
#include "obj.h"
#include "taskpool.h"
#include "listpool.h"

struct PooNode;

typedef struct PooPos {
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
} PooPos;

typedef struct PooActor {
    PooPos pos;
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
} PooActor;

enum PooEventId {
    POO_EVENT_PIGLET,
    POO_EVENT_TIGGER,
    POO_EVENT_EEYORE,
    POO_EVENT_OWL,
    POO_EVENT_RABBIT,
    POO_EVENT_ROO,
    POO_EVENT_WAGON
};

typedef struct PooState {
    PooPos pos;
    PooPos pos2;
    s32 poohAction;
    u32 flags;
    u16 eventsDone;
    u32 droppedPrizes[4];
    u16 gauge;
    u16 gaugeTimer;
    u16 wheelX;
    u16 wheelY;
} PooState;

typedef struct PooShadowInfo {
    u16 priority;
    s32 z;
} PooShadowInfo;

typedef struct PooHitBox {
    void* palette;
    u16 tileCount;
    s16 height;
    s16 radius;
} PooHitBox;

enum PoohAction {
    POOH_ACTION_IDLE,
    POOH_ACTION_FALL,
    POOH_ACTION_WAGON_DROP,
    POOH_ACTION_WALK,
    POOH_ACTION_WALK_AWAY,
    POOH_ACTION_FLEE_BEES_1,
    POOH_ACTION_FLEE_BEES_2,
    POOH_ACTION_STUMP_WALK,
    POOH_ACTION_STUMP_WAIT,
    POOH_ACTION_LOOK,
    POOH_ACTION_BLOCKED,
    POOH_ACTION_LOOK_AT_HONEYCOMB_DONE,
    POOH_ACTION_LOOK_AT_HONEYCOMB,
    POOH_ACTION_WAGON_WAIT,
    POOH_ACTION_BEE_CHASE_OVER,
    POOH_ACTION_JUMP_SCARED,
    POOH_ACTION_TRAP_FALL,
    POOH_ACTION_TRIP,
    POOH_ACTION_GET_UP,
    POOH_ACTION_STUMP_JUMP,
    POOH_ACTION_STUMP_CLIMB,
    POOH_ACTION_WAGON_CLIMB,
    POOH_ACTION_OWL_DESCENT,
    POOH_ACTION_SIT_DOWN,
    POOH_ACTION_SIT,
    POOH_ACTION_LIE_DOWN,
    POOH_ACTION_SLEEP,
    POOH_ACTION_WAKE_UP,
    POOH_ACTION_STAND_UP,
    POOH_ACTION_THINK_START,
    POOH_ACTION_THINK,
    POOH_ACTION_THINK_END,
    POOH_ACTION_SIT_FOR_HONEY,
    POOH_ACTION_EAT_HONEY_1,
    POOH_ACTION_EAT_HONEY_2,
    POOH_ACTION_EAT_HONEY_3,
    POOH_ACTION_TRAPPED,
    POOH_ACTION_TRAPPED_WITH_ROO,
    POOH_ACTION_BALLOON,
    POOH_ACTION_OWL_BALLOON
};

typedef struct PoohWork {
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    AnimState anim;
    u8 flipped;
    u16 animAction;
    PooPos pos;
    u8 angle;
    u8 lookTarget;
    u8 lookAngle;
    u8 lookColumn;
    s32 speed;
    s32 targetX;
    s32 targetY;
    s32 vz;
    Collider collider;
    s32 dirIndex;
    u16 balloonTimer;
    TaskPool tasks;
    Task* task;
    Task* zzzTask;
    u8 unk_CC;
    struct PooNode* targetNode;
    u16 lookTimer;
    u8 unk_D6;
    u16 sleepTimer;
    s16 actionTimer;
    u16 callTimer;
    PooShadowInfo shadowInfo;
    u8 onCollider;
    s32 groundZ;
    s32 stumpIndex;
    u16 stumpCount;
    u8 leavingWagon;
    u16 callCount;
    u8 hideShadow;
    u8 hopAngle;
} PoohWork;

#endif
