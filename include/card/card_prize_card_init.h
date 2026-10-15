#ifndef GUARD_CARD_PRIZE_CARD_INIT_H
#define GUARD_CARD_PRIZE_CARD_INIT_H

#include "card.h"
#include "taskpool.h"
#include "types.h"

u16 PickPrizeMapCardKindForWorld(u16 world, s32 b);
void CreatePrizeMapCardTask(TaskPool* pool, s32* args);
s32 UpdateSpotLightFadeOut(SpotlightWork* work);
s32 UpdateSelmapEventKeyClose(SelmapEventKeyWork* work);

#endif
