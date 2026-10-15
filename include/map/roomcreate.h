#ifndef GUARD_ROOMCREATE_H
#define GUARD_ROOMCREATE_H

#include "types.h"
#include "taskpool.h"

typedef struct RoomCreateWork {
    s32 x;
    s32 y;
    s32 z;
    s32 x2;
    s32 y2;
    s32 z2;
    s32 frontX;
    s32 frontY;
    s32 frontZ;
    u8 angle;
    u8 playerAngle;
    s16 timer;
    u8 spotLightEnd;
    u8 mapSelectStatus;
    TaskPool tasks;
    s32 state;
} RoomCreateWork;

struct Task;

#endif /* GUARD_ROOMCREATE_H */
