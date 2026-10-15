#ifndef GUARD_BTL2_H
#define GUARD_BTL2_H

#include "types.h"
#include "anim.h"
#include "battle_actor_types.h"

typedef struct BtlShadowWork {
    void* tiles;
    void* palette;
    BtlObj* actor;
    void* gfx;
} BtlShadowWork;

typedef struct BtlHpplyWork {
    s32 hpRatio;
    u8 firstUpdate;
    void* palette2;
    void* palette;
    void* tiles;
    void* tiles2;
    void* tiles3;
    void* tiles4;
    void* gfx;
    void* gfx2;
    void* gfx3;
    AnimState anim2;
    AnimState anim;
    u8 unk_5C;
    u8 alarmPlaying;
    s16 timer;
    s16 prevHp;
    s16 displayHp;
    s16 gaugeSize;
    u32 gaugeMode;
} BtlHpplyWork;

typedef struct BtlHpenmWork {
    void* tiles;
    void* tiles2;
    void* palette;
    void* tiles3;
    s32 hpRatio;
    u8 visible;
    BtlObj* actor;
    s16 gaugeSize;
    s16 displayHp;
    u32 gaugeLayer;
} BtlHpenmWork;

typedef struct BtlPauseWork {
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    u8 visible;
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;
    s16 steps;
    s16 unk_26;
} BtlPauseWork;

typedef struct BtlPopWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s16 timer;
} BtlPopWork;

typedef struct BtlEscapeWork {
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    void* gfx3;
    s32 progressRatio;
    s32 progressMax;
    s32 progress;
    s16 timer;
    u8 visible;
} BtlEscapeWork;

enum BtlPrizeFlag {
    BTL_PRIZE_FLAG_SPRITE_VISIBLE = 0x1,
    BTL_PRIZE_FLAG_DRAW_SHADOW = 0x2,
    BTL_PRIZE_FLAG_NO_MOVE = 0x4,
    BTL_PRIZE_FLAG_NO_TIMEOUT = 0x8,
    BTL_PRIZE_FLAG_CAN_COLLECT = 0x10
};

typedef struct BtlPrizeWork {
    s32 x;
    s32 y;
    s32 z;
    s32 groundZ;
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    s32 vz;
    s32 bounceSpeed;
    s16 timer;
    u8 spinSpeed;
    u16 flags;
    s32 collected;
    s32 orbitRadius;
    u16 exp;
    s16 healAmount;
    s32 vx;
    s32 vy;
    u8 angle;
    BtlObj* actor;
} BtlPrizeWork;

typedef struct BtlPremireWork {
    s32 x;
    s32 y;
    s32 z;
    s32 groundZ;
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    s32 vz;
    s32 bounceSpeed;
    s16 timer;
    u8 spinSpeed;
    u16 flags;
    s32 collected;
    s32 orbitRadius;
    s32 vx;
    s32 vy;
    u8 angle;
    BtlObj* actor;
    AnimState anim;
} BtlPremireWork;

typedef struct BtlPremireSrc {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 kind;
    s16 noTimeout;
} BtlPremireSrc;

typedef struct BtlStartWork {
    s16 timer;
    s16 unk_02;
} BtlStartWork;

#endif /* GUARD_BTL2_H */
