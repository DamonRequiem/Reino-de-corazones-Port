#ifndef GUARD_MODE_POOH_API_H
#define GUARD_MODE_POOH_API_H

#include "types.h"

struct Collider;
struct PoohWork;

void BackdropFadeStartOut(u32 mode, u16 frames);
void BackdropFadeReset();
void BackdropFadeSetColor(u16 r, u16 g, u16 b);
void BackdropFadeStartIn(u32 mode, u16 frames);
void BackdropFadeUpdate();
void SetPooAttackPoint(s32 x, s32 y, s32 z);
u8 PooAttackHitsCollider(struct Collider* collider);
void ExitPoohMode(u32 event);
void OpenPoohModeMessage(u16 message);
u16 SpawnPooPrizes(u8 kind, u8 count, s32 x, s32 y, s32 z);
void SetPooMapBeeVisible(u8 visible);
u8 IsPooMapBeeVisible();
void SetPoohDir5Right(struct PoohWork* work);
void SetPoohAnimation(struct PoohWork* work, u32 action);
u8 IsWithinPoohRadius(u16 x, u16 y, u16 px, u16 py);

#endif
