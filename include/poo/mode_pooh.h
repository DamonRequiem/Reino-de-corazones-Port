#ifndef GUARD_MODE_POOH_H
#define GUARD_MODE_POOH_H

#include "types.h"
#include "pooh_actor_types.h"

void BackdropFadeToOriginal(u32 mode, u16 frames);
void BackdropFadeToAmount(u32 mode, u16 amount, u16 frames);
u8 BackdropFadeIsActive();
void BackdropFadeFromAmount(u32 mode, u16 amount, u16 frames);
void SetPooStartPositions();
void SetPooReentryPositions();
void mode_pooh_0(s32 arg);
void mode_pooh_1();
void mode_pooh_2();
u16 CountPooPrizes();
void SetPoohDir5Left(PoohWork* work);
void SetPoohDir8(PoohWork* work);
void SetPoohDir2(PoohWork* work);
void SetPoohDir3(PoohWork* work);
u8 IsAngleFacingRight(u8 angle);
u8 GetPoohLookColumn(PoohWork* work);

#endif /* GUARD_MODE_POOH_H */
