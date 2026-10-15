#ifndef GUARD_BTL3_H
#define GUARD_BTL3_H

#include "types.h"
#include "anim.h"
#include "formation_types.h"
#include "battle_actor_types.h"

enum BtlFormFlag {
    BTL_FORM_FLAG_MIRROR_X = 0x1,
    BTL_FORM_FLAG_WAIT_NEXT_ENTRY = 0x2
};

enum BtlRaidFlag {
    BTL_RAID_FLAG_STRIKE_ON_CONTACT = 0x1,
    BTL_RAID_FLAG_BLADE_VISIBLE = 0x2
};

typedef struct BtlFormWork {
    s16 timer;
    s16 stepTimer;
    s16 stepIndex;
    const BtlFormList* list;
    const BtlFormEntry* entry;
    s16 entryIndex;
    s32 x;
    s32 y;
    s32 z;
    u16 flags;
    u16 nextTileCount;
    s16 waitTimer;
} BtlFormWork;

typedef struct BtlVec {
    s32 x;
    s32 y;
    s32 z;
} BtlVec;

typedef struct BtlBornWork {
    BtlVec pos;
    void* desc;
    u16 flags;
    u16 tileCount;
} BtlBornWork;

typedef struct BtlBornArgs {
    void* desc;
    BtlVec pos;
    u16 flags;
    u16 tileCount;
} BtlBornArgs;

typedef struct BtlRaidWork {
    void* tiles2;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 vx;
    s32 bounceVx;
    s16 timer;
    s16 steps;
    u8 facingLeft;
    u8 mainSide;
    u32 state;
    s32 scale;
    u16 variant;
    s32 attack;
    s32 unk_50;
    s16 hitHalfSize;
    u16 flags;
    u16 angle;
    u16 unk_5A;
    BtlObj* actor;
    void* tiles;
    void* palette2;
    u16 song;
} BtlRaidWork;

typedef struct BtlRaidArgs {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 facingLeft;
    s16 mainSide;
    u8 unk_16[0x06];
    u16 variant;
} BtlRaidArgs;

enum BtlRaidKind {
    BTL_RAID_STRIKE,
    BTL_RAID_STOP,
    BTL_RAID_FIRE,
    BTL_RAID_BLIZZARD,
    BTL_RAID_THUNDER,
    BTL_RAID_GRAVITY,
    BTL_RAID_REFLECT,
    BTL_RAID_JUDGMENT
};

typedef struct BtlBadStatusWork {
    void* tiles;
    void* palette;
    void* palette2;
    AnimState anim;
    BtlObj* actor;
    u32 status;
    void* palette3;
} BtlBadStatusWork;

u16 GetBtlFormEntryTileCount(const BtlFormEntry* list);
void BtlRaidGetEffectPosition(BtlRaidWork* work, s32* outX, s32* outY, s32* outZ);
BtlObj* BtlRaidGetTarget(BtlRaidWork* work);

#endif /* GUARD_BTL3_H */
