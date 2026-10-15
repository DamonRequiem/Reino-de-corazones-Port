#ifndef GUARD_CARD_DECKEXCHANGE_H
#define GUARD_CARD_DECKEXCHANGE_H

#include "card.h"
#include "types.h"

u8 UpdateDeckExchangeLoadBgs(DeckExchangeWork* work, void* task);
u8 UpdateDeckExchangeOpenCollection(DeckExchangeWork* work, void* task);
u8 UpdateDeckExchangeBuildList(DeckExchangeWork* work, void* task);
u8 UpdateDeckExchangeGrid(DeckExchangeWork* work, void* task);
u8 UpdateDeckExchangeClose(DeckExchangeWork* work, void* task);
u8 UpdateDeckExchangeFadeOut(DeckExchangeWork* work);
void CreateDeckExchangeDeckGridCards(DeckExchangeWork* work, u8 categoryFilter);
s32 CreateDeckExchangeCollectionGridCards(DeckExchangeWork* work, u8 categoryFilter, u8 excludeBossCards);
s32 GetCardIdForKind(s32 kind);
void ClearDeckExchangeCardGrid(DeckExchangeWork* work);
void DrawDeckExchangeEquipMarker(u8 deck);
void DrawDeckExchangeCardTotals();
void ShowDeckExchangeCardPreview(DeckExchangeWork* work);
void ReleaseDeckExchangeCardPreview(DeckExchangeWork* work);
void DrawDeckExchangeValueCpCost(DeckExchangeWork* work);
void DrawDeckExchangeCpCost(u8 cpCost);
s32 MoveDeckExchangeValueCursor(DeckExchangeWork* work, u16 key);
void FreeDeckExchangeCollectionEntries(DeckExchangeWork* work);
s32 TakeTradeCard(DeckExchangeWork* work);
s32 CheckDeckExchangeCpCost(DeckExchangeWork* work);
u8 CheckDeckExchangeHasAttackCard(DeckExchangeWork* work);
void ResetDeckExchangeGridScroll(DeckExchangeWork* work);
u8 IsDeckExchangeCardAtCursor(DeckExchangeWork* work);
u8 IsDeckExchangeCardAt(DeckExchangeWork* work, s16 x, s16 y);
void LoadDeckExchangeCardDescriptionText(DeckExchangeWork* work, u16 index);
void SetDeckExchangeGridRowCount(DeckExchangeWork* work, s16 cardCount);
void UpdateDeckExchangeGridScrollBar(DeckExchangeWork* work);

#endif
