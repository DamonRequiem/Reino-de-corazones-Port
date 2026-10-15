#ifndef GUARD_FRD_DONALD_API_H
#define GUARD_FRD_DONALD_API_H

#include "battle_actor_types.h"
#include "types.h"

struct FrdDonaldWork;

u8 FrdDonaldApplyGravity(struct FrdDonaldWork* work);
void UpdateDonaldFlame(BtlObj* body, u8 attacking, s16 dx, s16 dz);

#endif
