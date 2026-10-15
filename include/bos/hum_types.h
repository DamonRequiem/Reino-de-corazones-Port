#ifndef GUARD_HUM_TYPES_H
#define GUARD_HUM_TYPES_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "obj.h"
#include "battle_actor_types.h"

enum HumSubFlag {
    HUM_SUB_FLAG_IN_FRONT = 0x1,
    HUM_SUB_FLAG_HIDDEN = 0x2,
    HUM_SUB_FLAG_OWN_DEPTH = 0x4
};

typedef struct HumSub {
    void* unk_00;
    void* tiles;
    void* palette;
    void* palette2;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u16 flags;
    void* gfx;
} HumSub;

typedef struct HumDef {
    u16 tileCount;
    void* palette;
    u32 unk_08;
    EmyKind kind;
} HumDef;

typedef struct HumSubDef {
    void* palette;
    u16 tileCount;
} HumSubDef;

enum HumFlag {
    HUM_FLAG_AT_FIELD_EDGE = 0x1,
    HUM_FLAG_FLASH_PALETTE = 0x2,
    HUM_FLAG_PASS_THROUGH = 0x4,
    HUM_FLAG_IGNORE_BOUNDS = 0x8,
    HUM_FLAG_ENEMY_CARDS_SPENT = 0x10,
    HUM_FLAG_BEHIND_BG_FX = 0x20,
    HUM_FLAG_BOSS_DEATH = 0x40
};

enum HumState {
    HUM_STATE_IDLE,
    HUM_STATE_HURT,
    HUM_STATE_HURT_RECOVER,
    HUM_STATE_DEFEATED,
    HUM_STATE_DEFEAT_EFFECT,
    HUM_STATE_DROP_PRIZES,
    HUM_STATE_BOSS_DEATH,
    HUM_STATE_BOSS_DEATH_FLASH,
    HUM_STATE_MOVE,
    HUM_STATE_CARD_BROKEN,
    HUM_STATE_HEALED,
    HUM_STATE_STUNNED,
    HUM_STATE_ENTER,
    HUM_STATE_STOPPED,
    HUM_STATE_GRAVITY,
    HUM_STATE_GRAVITY_FLAT,
    HUM_STATE_GRAVITY_RECOVER,
    HUM_STATE_RELOAD,
    HUM_STATE_USE_ITEM
};

typedef struct HumWork {
    const void* def;
    ObjTiles* tiles;
    ObjPalette* palette;
    HumSub* sub;
    HumSub* sub2;
    AnimState anim;
    TaskPool tasks;
    BtlObj actor;
    s16 stateTimer;
    s16 steps;
    u32 flags;
    s32 vz;
    s32 targetX;
    s32 targetY;
    s32 targetZ;
    s32 scaleX;
    s32 scaleY;
    u32 state;
    s16 boundsMargin;
    void* paletteData;
    u16 unk_17C;
    u16 itemIndex;
    void* gfx;
    const u32* stockMoves;
} HumWork;

#endif
