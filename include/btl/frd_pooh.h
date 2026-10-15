#ifndef GUARD_FRD_POOH_H
#define GUARD_FRD_POOH_H

#include "anim.h"
#include "battle_actor_types.h"
#include "taskpool.h"
#include "types.h"

#ifdef VERSION_EU
typedef struct FrdPoohBody {
    s32 kind;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    u8 unk_14[0x20];
    u64 flags;
    u8 unk_3C[4];
    Collider collider;
    u8 unk_9C[0x30];
    u16 depth;
    u8 unk_CE[0x42];
} FrdPoohBody;

typedef struct FrdPoohWork {
    TaskPool tasks;
    BtlObj* actor;
    void* tiles;
    void* palette;
    FrdPoohBody body;
    AnimState anim;
    s32 state;
    u8 side;
    u8 card;
    s16 counter;
    s32 targetX;
    s32 targetY;
    s32 velocity;
    s32 speed;
    u8 bounce;
    s32 bob;
    s32 animcounter;
    s32 scale;
} FrdPoohWork;

typedef struct FrdPoohArgs {
    u16 card;
    u8 side;
} FrdPoohArgs;

#endif

#endif /* GUARD_FRD_POOH_H */
