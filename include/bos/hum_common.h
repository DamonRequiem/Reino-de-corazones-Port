#ifndef GUARD_HUM_COMMON_H
#define GUARD_HUM_COMMON_H

#include "types.h"

struct HumDef;
struct HumSub;
struct HumSubDef;
struct HumWork;

void HumInit(struct HumWork* work, const struct HumDef* def);
void HumSubInit(struct HumWork* work, struct HumSub* sub, const struct HumSubDef* def);
void HumSubReleaseGraphics(struct HumSub* sub);
void HumReleaseResources(struct HumWork* work);
void HumStartKnockback(struct HumWork* work);
s32 HumUpdateReaction(struct HumWork* work);
void HumSubUpdateAnimation(struct HumSub* sub);
s32 HumUpdate(struct HumWork* work);
void HumDrawSub(struct HumWork* work, struct HumSub* sub);
void HumDraw(struct HumWork* work);
void HandleRikuAiCardInput();
#ifdef VERSION_EU
void HandleRikuTutorialCardInput();
#endif
void HumFaceTarget(struct HumWork* work, u16 interval);
u8 HumMoveToward(struct HumWork* work, s32 x, s32 y, s32 spd);
u8 HumIsTargetInReach(struct HumWork* work, s16 offset, u16 width, u16 depth);
u8 HumIsNearAreaEdge(struct HumWork* work, u16 margin);
u8 HumIsInPlayerReach(struct HumWork* work, s16 offset, u16 width, u16 depth);
u8 HumChooseCardAction(struct HumWork* work, u16 interval, u16 offset, u16 width, u16 depth);
s32 HumResolveCardMove(struct HumWork* work);

#endif
