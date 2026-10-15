#ifndef GUARD_MODE_EVENT_H
#define GUARD_MODE_EVENT_H

#include "mode.h"
#include "taskpool.h"
#include "types.h"

typedef struct EvtArg {
    u32 eventId : 8;
    u32 fromGame : 8;
    u32 unk_10 : 16;
} EvtArg;

extern Mode gModeEventDebug;
extern Mode gModeEvent;

void ShowEventEndMessage();
void SetFriendsAfterEvent();
void GrantRewardsAfterEvent();
void HandleYesAnswerAfterEvent();
u8 HandleNoAnswerAfterEvent();
void UnlockCardKindsAfterEvent();
void SaveAfterEvent();
void EnterExitHallAfterEvent();
void SetJiminyFlagsAfterEvent();

#endif
