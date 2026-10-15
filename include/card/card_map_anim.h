#ifndef GUARD_CARD_MAP_ANIM_H
#define GUARD_CARD_MAP_ANIM_H

#include "card_types.h"
#include "types.h"

#define CARD_NOT_ADDED (-1)

Deck* CreateLinkSendDeck();
void FreeLinkSendDeck();
Deck* CreateLinkPartnerDeck();
void FreeLinkPartnerDeck();
u16 CountLinkPartnerDeckCards(u8 listIndex);
u16 CountCardsById(u16 cardId);
s16 AddCardToCollection(u16 a);
u8 IsCardCollectionFull();
u16 CountCollectionCards();
u16 CountCardsInDecks();

#endif
