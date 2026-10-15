#ifndef GUARD_CARD_LEVEL_UP_H
#define GUARD_CARD_LEVEL_UP_H

#include "card.h"
#include "types.h"

u8 UpdateLevelUpSelect(LevelUpWork* work, void* task);
u8 UpdateLevelUpResult(struct LevelUpWork* work, void* task);
u8 UpdateLevelUpClose(LevelUpWork* work, void* task);
u8 UpdateLevelUpWaitFade();
void DrawLevelUpStatDigits(s16 x, s16 y, void* tiles, void* pal, void** gfx, u16* digits, u8 stat);
u8 UpdateLevelUpNextSlideOut(LevelUpWork* work, void* task);
s32 IsLevelUpApUnlocked();

#endif
