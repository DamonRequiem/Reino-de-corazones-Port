#ifndef GUARD_CARD_MSGWIN_H
#define GUARD_CARD_MSGWIN_H

#include "card.h"
#include "types.h"

u8 UpdateCardMsgwinLoadText(CardMsgWinWork* work, void* task);
u8 UpdateCardMsgwinWaitInput(CardMsgWinWork* work, void* task);
u8 UpdateCardMsgwinTypingPersistent(CardMsgWinWork* work, void* task);
u8 UpdateCardMsgwinPersistent(CardMsgWinWork* work, void* task);
void ShowPersistentCardMessage(void* pool, u32 bg, u16 message);

#endif
