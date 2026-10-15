#ifndef GUARD_EVENTSELECT_API_H
#define GUARD_EVENTSELECT_API_H

#include "types.h"

struct EventCharaWork;
struct EventSoundMix;

extern struct EventSoundMix* gEventSoundMix;

void SetEventSoundPosition(u16 song, s16 x, s16 y);
void CreateTinkerbellTask(struct EventCharaWork* work);
void CreateDownTask(struct EventCharaWork* work);
void CreateSmokeTask(struct EventCharaWork* work);
void CreateExclamationTask(struct EventCharaWork* work);
void CreateBalloonTask(struct EventCharaWork* work);
void CreateQuestionTask(struct EventCharaWork* work);
void CreateGlowNoseTask(struct EventCharaWork* work);
void CreateHanabiraTask(struct EventCharaWork* work);

#endif
