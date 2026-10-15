#ifndef GUARD_EMY_H
#define GUARD_EMY_H

#include "enemy_types.h"
#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "battle_actor_types.h"

typedef struct EmySpawn {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 facingLeft;
    u16 hitPhase;
    u8 unk_16[0x0A];
} EmySpawn;

typedef struct Emy03Work {
    EmyWork base;
    u32 targetX;
    u32 targetY;
    u32 targetZ;
} Emy03Work;

typedef struct Emy04Work {
    EmyWork base;
    u8 unk_184;
    s16 healCount;
} Emy04Work;

typedef struct Emy06Work {
    EmyWork base;
    s32 speed;
} Emy06Work;

typedef struct Emy07Work {
    EmyWork base;
    s16 successCount;
    u8 thunderRequested;
    u8 rewarded;
} Emy07Work;

enum Emy08Flag {
    EMY08_FLAG_ATTACK_HIT = 0x1,
    EMY08_FLAG_HARDENED = 0x2
};

typedef struct Emy08Work {
    EmyWork base;
    void* palette;
    void* basePalette;
    u16 flags;
} Emy08Work;

typedef struct Emy16Work {
    EmyWork base;
    void* pTask;
    void* bTask;
    TaskPool tasks;
    u8 pTaskStarted;
} Emy16Work;

typedef struct Emy16bWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 facingLeft;
    s32 vz;
    s32 vx;
    u32 state;
    s16 timer;
    Collider collider;
    u8 visible;
    u8 bounced;
} Emy16bWork;

typedef struct Emy16pWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 facingLeft;
    s32 vz;
} Emy16pWork;

typedef struct Emy18Work {
    EmyWork base;
    u16 hitFrame;
} Emy18Work;

typedef struct Emy19Work {
    EmyWork base;
    s32 dashSpeed;
} Emy19Work;

typedef struct Emy21Work {
    EmyWork base;
    s32 dashSpeed;
} Emy21Work;

typedef struct Emy22Work {
    EmyWork base;
    u8 counterPending;
} Emy22Work;

typedef struct Emy23Work {
    EmyWork base;
    s32 targetX;
} Emy23Work;

typedef struct Emy28Work {
    EmyWork base;
    u16 hitFrame;
} Emy28Work;

typedef struct Emy29Work {
    EmyWork base;
    s16 state;
    s16 steps;
} Emy29Work;

typedef struct Emy31Work {
    EmyWork base;
    u32 state;
    u32 targetX;
    u32 targetY;
    u32 targetZ;
} Emy31Work;

typedef struct Emy37Work {
    EmyWork base;
    u8 rotation;
    u32 speed;
    u16 angle;
} Emy37Work;

typedef struct Emy39Work {
    EmyWork base;
    s32 dashSpeed;
} Emy39Work;

typedef struct Emy41Work {
    EmyWork base;
    u32 targetX;
    u32 targetY;
    u32 targetZ;
} Emy41Work;

typedef struct Emy81Work {
    EmyWork base;
    s32 speedX;
    s32 speedY;
    s32 targetX;
    s32 targetY;
} Emy81Work;

typedef struct Emy82Work {
    EmyWork base;
    u16 spawnCount;
} Emy82Work;

typedef struct Emy83Work {
    EmyWork base;
    void* task;
    TaskPool tasks;
    s32 targetX;
    s32 targetY;
    s16 shotCount;
} Emy83Work;

typedef struct Emy83bWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u32 state;
    s16 timer;
    Collider collider;
} Emy83bWork;

typedef struct Emy83sWork {
    void* tiles;
    void* palette;
    s32 x;
    s32 y;
    s32 z;
    s32 vz;
    s32 vx;
    s32 vy;
    u16 hitPhase;
    s16 frameCount;
} Emy83sWork;

void Emy29MoveToPose(Emy29Work* work, s16 anim, s16 dx, s16 dy, s16 dz);
u8 GetEmyApproachAngle(EmyWork* work);

#endif /* GUARD_EMY_H */
