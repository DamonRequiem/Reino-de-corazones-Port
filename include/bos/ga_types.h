#ifndef GUARD_GA_TYPES_H
#define GUARD_GA_TYPES_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "obj.h"
#include "battle_actor_types.h"

enum GaEntryFlag {
    GA_ENTRY_FLAG_NO_BOB = 0x1,
    GA_ENTRY_FLAG_HURT = 0x2,
    GA_ENTRY_FLAG_DESTROYED = 0x4,
    GA_ENTRY_FLAG_STEPPING = 0x8,
    GA_ENTRY_FLAG_RELEASED = 0x10
};

enum GaFlag {
    GA_FLAG_STATE_REQUESTED = 0x1
};

typedef struct GaEntryWork {
    BtlObj actor;
    u8 unk_110[0x02];
    u8 rotation;
    u16 landSteps;
    s32 rotationFixed;
    s32 mode;
    s32 vz;
    s32 baseX;
    s32 baseY;
    s32 baseZ;
    s32 unk_130;
    s32 unk_134;
    s32 unk_138;
    s32 bobZ;
    s32 offsetX;
    s32 offsetY;
    s32 baseVx;
    s32 baseVy;
    s32 baseVz;
    s32 baseAccelZ;
    u8 bobAngle;
    u16 flags;
    s16 counter;
    u16 x2;
    u16 y2;
    s32 vx;
    s32 vy;
    TaskPool tasks;
    AnimState anim;
    ObjTiles* tiles;
    void* gfx;
    u32 index;
    u8 orbitAngle;
    s16 flashTimer;
} GaEntryWork;

typedef struct GaWork {
    s32 state;
    s32 nextState;
    u32 statePhase;
    u16 step;
    u16 flags;
    s16 timer;
    s16 stepsLeft;
    s16 hurtTimer;
    s32 flipped;
    u8 angle;
    GaEntryWork entries[6];
    AnimState anim;
    ObjTiles* tiles;
    void* gfx;
    ObjPalette* palette;
    ObjPalette* palette2;
    s32 vx;
    s32 vy;
    s32 vz;
    s32 vzDelta;
    s32 orbitRadius;
    s32 attackToggle;
    s16 cardTimer;
    u8 cardActionSeen;
} GaWork;

#endif
