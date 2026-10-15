#ifndef GUARD_CARD_DECK_DATA_H
#define GUARD_CARD_DECK_DATA_H

#include "types.h"
#include "card_types.h"

extern const u16 gRikuDeckCards0[21];
extern const u16 gRikuDeckCards1[20];
extern const u16 gRikuDeckCards2[21];
extern const u16 gRikuDeckCards3[12];
extern const u16 gRikuDeckCards4[20];
extern const u16 gRikuDeckCards5[18];
extern const u16 gRikuDeckCards6[17];
extern const u16 gRikuDeckCards7[16];
extern const u16 gRikuDeckCards8[19];
extern const u16 gRikuDeckCards9[5];
extern const u16 gRikuDeckCards10[25];
extern const u16 gRikuDeckCards11[30];
extern const u16 gRikuDeckEnemyCard0;
extern const u16 gRikuDeckEnemyCard1;
extern const u16 gRikuDeckEnemyCard2;
extern const u16 gRikuDeckEnemyCard3;
extern const u16 gRikuDeckEnemyCard4;
extern const u16 gRikuDeckEnemyCard5;
extern const u16 gRikuDeckEnemyCard6;
extern const u16 gRikuDeckEnemyCard7;
extern const u16 gRikuDeckEnemyCard9;
extern const u16 gRikuDeckCardCounts[12];
extern const u16 gRikuDeckEnemyCardCounts[12];

Deck* GetLinkPartnerDeck();
void InitCardCollection();

#endif
