#ifndef GUARD_FRD_H
#define GUARD_FRD_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "battle_actor_types.h"

typedef struct FrdArgs {
    u16 variant;
    u8 mainSide;
} FrdArgs;

typedef struct FrdDonaldWork {
    TaskPool tasks;
    BtlObj* actor;
    void* tiles;
    void* palette;
    BtlObj body;
    AnimState anim;
    s32 state;
    u8 mainSide;
    u8 variant;
    s16 stateTimer;
    s16 steps;
    s32 vz;
    s32 unk_158;
    s32 vy;
    s16 repeatsLeft;
} FrdDonaldWork;

typedef struct FrdGoofyWork {
    TaskPool tasks;
    BtlObj* actor;
    void* tiles;
    void* palette;
    BtlObj body;
    AnimState anim;
    u32 state;
    u8 mainSide;
    u8 variant;
    s16 stateTimer;
    s16 steps;
    s32 vz;
    s32 targetX;
    s32 targetY;
    u8 angle;
} FrdGoofyWork;

typedef struct FrdArielWork {
    TaskPool tasks;
    BtlObj* actor;
    void* tiles;
    void* palette;
    BtlObj body;
    AnimState anim;
    u32 state;
    u8 mainSide;
    u8 variant;
    s16 stateTimer;
    s16 steps;
    s32 hoverZ;
    s16 passesLeft;
    s32 passSpeed;
    s32 speed;
} FrdArielWork;

typedef struct FrdJackWork {
    TaskPool tasks;
    BtlObj* actor;
    void* tiles;
    void* palette;
    BtlObj body;
    AnimState anim;
    s32 state;
    u8 mainSide;
    u8 variant;
    s16 stateTimer;
    s16 steps;
    s32 vz;
    s32 targetX;
    s32 targetY;
    s32 rotation;
    s32 rotationTarget;
    s16 repeatsLeft;
} FrdJackWork;

typedef struct FrdPanWork {
    TaskPool tasks;
    BtlObj* actor;
    void* tiles;
    void* palette;
    BtlObj body;
    AnimState anim;
    u32 state;
    u8 mainSide;
    u8 variant;
    s16 stateTimer;
    s16 steps;
    s16 duration;
    s16 unk_154;
    s32 vz;
    s32 targetX;
    s32 unk_160;
    s32 hoverZ;
    s32 vx;
    u8 flyLeft;
} FrdPanWork;

typedef struct FrdAladdinWork {
    TaskPool tasks;
    BtlObj* actor;
    void* tiles;
    void* palette;
    BtlObj body;
    AnimState anim;
    u32 state;
    u8 mainSide;
    u8 variant;
    s16 stateTimer;
    s16 steps;
    s16 duration;
    s32 vz;
    s32 targetX;
    u8 unk_15C[0x04];
} FrdAladdinWork;

typedef struct FrdBeastWork {
    TaskPool tasks;
    BtlObj* actor;
    void* tiles;
    void* palette;
    BtlObj body;
    AnimState anim;
    s32 state;
    u8 mainSide;
    u8 variant;
    s16 stateTimer;
    s32 targetX;
    s32 targetY;
    s32 vz;
    s32 attack;
} FrdBeastWork;

u8 FrdJackApplyGravity(FrdJackWork* work);
void FrdPanHover(FrdPanWork* work);
void FrdPanSpawnSparkle(FrdPanWork* work);
u8 FrdGoofyApplyGravity(FrdGoofyWork* work);
u8 FrdAladdinApplyGravity(FrdAladdinWork* work);

#endif /* GUARD_FRD_H */
