#ifndef GUARD_CARD_SYSMSGWIN_H
#define GUARD_CARD_SYSMSGWIN_H

#include "card.h"
#include "types.h"

u8 UpdateSysmsgwinWaitInput(SysMsgWinWork* work, void* task);
s32 UpdateSysmsgwinClose(SysMsgWinWork* work);
u8 UpdateSysmsgwinChoice(SysMsgWinWork* work, void* task);
u8 UpdateSysmsgwinPersistent(SysMsgWinWork* work, void* task);

#endif
