#ifndef GUARD_CARD_DECKMENU2_H
#define GUARD_CARD_DECKMENU2_H

#include "card.h"
#include "types.h"

void ClearCardCollectionSlot(u16* slot);
u8 HasNonPremiumCardsInActiveDeck();
u8 IsActiveDeckAllPremium();
void BuildRikuDeck(u8 deck);
u8 GetActiveDeckIndex();
u8 UpdateDeckMenuLoadBgs(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuLoadDeckInfo(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuDeckGrid(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuDeckFilter(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuDeleteValueSelect(DeckMenuWork* work, void* task);
void RemoveEmptyCollectionEntry(DeckMenuWork* work, u8 excludeBossCards);
u8 UpdateDeckMenuCollectionFilter(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuDeckSelect(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuCommands(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuCloseCommands(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuOpenAddMode(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuBuildAddList(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuAddGrid(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuCloseAddMode(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuOpenRemoveMode(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuBuildRemoveGrid(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuRemoveGrid(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuCloseRemoveMode(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuBuildDeleteList(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuDeleteGrid(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuCloseDeleteMode(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuFadeOut(DeckMenuWork* work);
u8 UpdateDeckMenuStartSlideOut(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuSlideOut(DeckMenuWork* work, void* task);
void CreateDeckGridCards(DeckMenuWork* work, u8 categoryFilter);
s32 CreateCollectionGridCards(DeckMenuWork* work, u8 categoryFilter, u8 excludeBossCards);
s32 GetCardIdForKindEntry(s32 kind);
void ClearCardGrid(DeckMenuWork* work);
void SetGridRowCount(DeckMenuWork* work, s16 cardCount);
void UpdateGridScrollBar(DeckMenuWork* work);
void ScrollGridDown(DeckMenuWork* work);
DeckCard2Work* GetCardAtCursor(DeckMenuWork* work);
void HighlightDeckTab(DeckMenuWork* work, u8 deckIndex);
void DrawDeckEquipMarker(u8 deck);
void DrawDeckCpCost(u8 deck);
void DrawCardTotals();
void LoadDeckNameTexts(DeckMenuWork* work);
s32 ShowCollectionCardPreview(DeckMenuWork* work);
void ReleaseCardPreview(DeckMenuWork* work);
void ShowDeckCardPreview(DeckMenuWork* work);
void DrawSelectedValueCpCost(DeckMenuWork* work);
void DrawCpCost(u8 cpCost);
s32 MoveValueCursor(DeckMenuWork* work, u16 keys);
s32 AddSelectedValueCardToDeck(DeckMenuWork* work);
void FreeCollectionEntries(DeckMenuWork* work);
void ReleaseCommandMenuGfx(DeckMenuWork* work);
u8 DeleteSelectedValueCard(DeckMenuWork* work);
s32 CheckDeckCpCost(DeckMenuWork* work);
s32 CheckDeckHasAttackCard(DeckMenuWork* work);
s32 IsCardAtCursor(DeckMenuWork* work);
u8 IsCardAt(DeckMenuWork* work, s16 col, s16 row);
u8 SwapHeldDeckCard(DeckMenuWork* work);
u8 UpdateDeckMenuOpenKeyboard(DeckMenuWork* work, void* task);
u8 UpdateDeckMenuKeyboard(DeckMenuWork* work, void* task);
void BuildCollectionEntries(DeckMenuWork* work);

#endif
