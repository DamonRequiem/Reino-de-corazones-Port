#ifndef GUARD_BTL_API_H
#define GUARD_BTL_API_H

#include "types.h"

void SelectLockonTarget();
void BtlMapResetShake();
void BtlMapStartShake();
void BtlMapUpdateShake();
s32 BtlMapGetShake();
void BtlMapSetCameraTarget(s32 x, s32 y);
void BtlMapFollowPosition(s32 px, s32 py, s32 pz);

#endif
