#ifndef GUARD_CARD_BATTLE_RIKU_H
#define GUARD_CARD_BATTLE_RIKU_H

#include "card.h"
#include "card_types.h"
#include "types.h"

void SetRikuReloadCharging();
u16 FillCardSlotsFromIds(CardSlot* out, const u16* ids, u16 idCount, u8 listIndex);
u8 UpdateRikuReloadDeal(CardBattleWork* work, void* task);
void SelectNextRikuCard(CardBattleWork* work, u8 listIndex);
void SelectPrevRikuCard(CardBattleWork* work, u8 listIndex);
void SwitchRikuCardList(CardBattleWork* work);
void CycleRikuCardList(CardBattleWork* work);
u8 UseRikuCard(CardBattleWork* work);
void BeginRikuReloadDeal(CardBattleWork* work);
u8 StockRikuCard(CardBattleWork* work);
void UseRikuStock(CardBattleWork* work);
u8 UseRikuHeartlessCard(CardBattleWork* work);
void func_08081740(CardBattleWork* work, u16 hcEffect);
void SyncRikuHcEffect(CardBattleWork* work);
void TickRikuHcEffectOnCardUse();
void ResetRikuReloadGauge(CardBattleWork* work);
u8 RikuStockMoveToSlot(CardDisplayWork* work, void* task);
u8 RikuCardShrinkAway(CardDisplayWork* work);
void UpdateRikuPlayedCardPosition(CardDisplayWork* work);
void LookupRikuCardDef(CardDisplayArgs* args, const CardDef** out, u8 index);
void LoadRikuCardDisplayGfx2(CardDisplayWork* work);
void RefreshRikuCardDisplayGfx(CardDisplayWork* work);
u8 RikuStockVanish(CardDisplayWork* work);
void UpdateRikuReloadGauge(CardDisplayWork* work);
void TickRikuHcEffectOnPlayEnd();
void TickRikuHcEffectOnAttackEnd();
s32 BosscardSlideOut(BossCardWork* work);

#endif
