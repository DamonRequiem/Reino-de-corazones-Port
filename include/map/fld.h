#ifndef GUARD_FLD_H
#define GUARD_FLD_H

#include "types.h"
#include "anim.h"
#include "fld_types.h"
#include "macros.h"

typedef struct FldShadowWork {
    s32 x;
    s32 y;
    void* tiles;
    void* palette;
    FldObj* actor;
    AnimState anim;
} FldShadowWork;

STATIC_ASSERT(sizeof(FldShadowWork) == 0x2C, FldShadowWorkSize);

void FldRikuSetAnim(FldWork* work, s32 index, u16 flags);

void CreateWorldSelBeforeTask(void* pool, s32 x, s32 y, s32 z);

u8 FldRikuCheckBlocked(FldPos* pos);
s32 FldRikuProbeGround(FldPos* pos);
u8 FldRikuCheckClimb(FldPos* pos, FldWork* work);
u8 FldRikuCheckDoorAhead(FldActor* act);
s32 FldRikuGetGround(FldWork* work);
void FldRikuSetAngleFromDpad(FldActor* act);
void FldRikuTurn(FldActor* act);
u8 FldSoraWaitRoomCreate(FldWork* work, void* task);
u8 FldSoraGmkJump(FldWork* work, void* task);
u8 FldSoraJump(FldWork* work, void* task);
u8 FldSoraClimb(FldWork* work, void* task);
u8 FldSoraLedgeInput(FldWork* work, void* task);
u8 FldSoraHangLedge(FldWork* work, void* task);
u8 FldSoraWalkOut(FldWork* work, void* task);
u8 FldSoraAttack(FldWork* work, void* task);
u8 FldRikuGmkJump(FldWork* work, void* task);
u8 FldRikuJump(FldWork* work, void* task);
u8 FldRikuClimb(FldWork* work, void* task);
u8 FldRikuLedgeInput(FldWork* work, void* task);
u8 FldRikuHangLedge(FldWork* work, void* task);
u8 FldRikuWalkOut(FldWork* work, void* task);
u8 FldRikuAttack(FldWork* work, void* task);
u8 FldRikuWaitRoomCreate(FldWork* work, void* task);

#endif /* GUARD_FLD_H */
