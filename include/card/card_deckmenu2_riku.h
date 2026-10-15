#ifndef GUARD_CARD_DECKMENU2_RIKU_H
#define GUARD_CARD_DECKMENU2_RIKU_H

#include "card.h"
#include "types.h"

u8 UpdateRikuDeckMenuLoadDeckInfo(RikuDeckMenuWork* work, void* task);
u8 UpdateRikuDeckMenuDeckGrid(RikuDeckMenuWork* work, void* task);
s32 UpdateRikuDeckMenuFadeOut(RikuDeckMenuWork* work);
void CreateRikuDeckGridCards(RikuDeckMenuWork* work, u8 categoryFilter);
void ClearRikuCardGrid(RikuDeckMenuWork* work);
DeckCard2Work* GetRikuCardAtCursor(RikuDeckMenuWork* work);
void ShowRikuDeckCardPreview(RikuDeckMenuWork* work);
void DrawRikuCpCost(u8 cpCost);
void FreeRikuCollectionEntries(RikuDeckMenuWork* work);
void ReleaseRikuCommandMenuGfx(RikuDeckMenuWork* work);
void SetRikuDeckMenuFrameCursor(RikuDeckMenuWork* work, u8 frameCursor);
u8 CheckRikuDeckCpCost(RikuDeckMenuWork* work);
u8 CheckRikuDeckHasAttackCard(RikuDeckMenuWork* work);

#endif
