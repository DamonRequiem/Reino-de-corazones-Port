#ifndef GUARD_CARD_DEF_DATA_H
#define GUARD_CARD_DEF_DATA_H

#include "card_types.h"
#include "types.h"

extern const CardDef gCardDefs[];
extern const CardBack gCardBacks[];
extern const CardBack gEnemyCardBacks[];
extern const u8 gBlackCircleText[3];
extern const u8 gWhiteCircleText[3];
extern const u8 gBlackStarText[3];
extern const u8 gWhiteStarText[3];

extern const u8* gWhiteStarTextPtr;
extern const u8* gBlackStarTextPtr;
extern const u8* gWhiteCircleTextPtr;
extern const u8* gBlackCircleTextPtr;

u16 GetCardCpCost(u16 cardId);
u16 GetCardMooglePointValue(u16 cardId);

#endif
