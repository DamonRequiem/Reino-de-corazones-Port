#ifndef GUARD_BOS_GA_H
#define GUARD_BOS_GA_H

#include "ga_types.h"
#include "types.h"

void task_bos_ga_2(GaWork* work);
void task_bos_ga_3(GaWork* work);
void task_bos_ga_0(GaWork* work, s32 arg);
u8 task_bos_ga_1(GaWork* work);
u16 BosGaAtan(s32 ratio);
s32 BosGaGetAngle(s32 x0, s32 y0, s32 x1, s32 y1);
void BosGaEntryUpdateFall(GaEntryWork* work);
void BosGaRequestState(GaWork* work, s32 state);
s32 BosGaEntryOffsetX(GaWork* work, s16 index);
s32 BosGaEntryOffsetY(GaWork* work, s16 index);
s32 BosGaEntryHomeX(GaWork* work, s16 index);
s32 BosGaEntryHomeY(GaWork* work, s16 index);
s32 BosGaEntryHomeZ(GaWork* work, s16 index);
void BosGaEntryResetHome(GaWork* work, s32 index);
void BosGaUpdateFacing(GaWork* work);
void BosGaEntryInit(GaWork* work, u32 index, s32 assemble);
void BosGaEntryRelease(GaEntryWork* work);
void BosGaReleaseBody();
void BosGaEntryDraw(GaWork* work, GaEntryWork* entry);
u8 BosGaUpdateAssemble(GaWork* work);
u8 BosGaUpdateIdle(GaWork* work);
u8 BosGaUpdateWalk(GaWork* work);
u8 BosGaUpdateStomp(GaWork* work);
u8 BosGaUpdateThrust(GaWork* work);
u8 BosGaUpdateOrbit(GaWork* work);
u8 BosGaUpdateJump(GaWork* work);
u8 BosGaUpdateBodyChase(GaWork* work);
u8 BosGaUpdateBodyDash(GaWork* work);
u8 BosGaUpdateBodyJump(GaWork* work);
u8 BosGaUpdateGimmick(GaWork* work);
u8 BosGaUpdateDefeat(GaWork* work);
void BosGaEntryUpdate(GaWork* work, GaEntryWork* entry);

#endif /* GUARD_BOS_GA_H */
