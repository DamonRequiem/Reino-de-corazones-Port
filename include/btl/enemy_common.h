#ifndef GUARD_ENEMY_COMMON_H
#define GUARD_ENEMY_COMMON_H

#include "types.h"

struct EmyDef;
struct EmyObj;
struct EmyWork;

void EmyInit(struct EmyWork* work, const struct EmyDef* def, struct EmyObj* obj);
enum EmyLungeResult {
    EMY_LUNGE_ACTIVE,
    EMY_LUNGE_HIT,
    EMY_LUNGE_FINISHED
};

s16 EmyLungeAttack(struct EmyWork* work, s16 delay, s16 duration, s16 recovery, s32 attack, s16 distance, u16 song, s16 dx, s16 dz, u16 halfSize);
void EmyReturnToIdle(struct EmyWork* work);
void EmyStartKnockback(struct EmyWork* work);
u8 EmyUpdateReaction(struct EmyWork* work);
void EmyFinishSpawn(struct EmyWork* work);
s32 EmyUpdateCommonStates(struct EmyWork* work);
void EmyDraw(struct EmyWork* work);
void EmyReleaseResources(struct EmyWork* work);

#endif
