#ifndef GUARD_MODE_RIKU_TUTORIAL_H
#define GUARD_MODE_RIKU_TUTORIAL_H

#include "card.h"
#include "types.h"

enum LinkSide {
    LINK_SIDE_SELF,
    LINK_SIDE_PARTNER
};

u8 FindStockPairsInCombo(s32* keys, u8* found);
s32 GetStockMove(s32 stock);
s32 IsThreeDistinctAttackCards(CardDisplayWork** cards, u8 count);
s32 IsThreeAttackCardsNoSoulEater(CardDisplayWork** cards, u8 count);
s32 IsAttackDonaldGoofyAnyOrder(CardDisplayWork** cards, u8 count);
s32 IsKindPairThenNonSummonOfCategory(CardDisplayWork** cards, u8 count, u16 firstKind, u16 secondKind, u8 category);
s32 IsKindPairThenSummon(CardDisplayWork** cards, u8 count, u16 firstKind, u16 secondKind);
s32 IsKindThenTwoAttackCards(CardDisplayWork** cards, u16 kind, u8 count);
s32 IsKindThenTwoOfCategory(CardDisplayWork** cards, u16 kind, u8 category, u8 count);
s32 IsFireMushuAttack(CardDisplayWork** cards, u8 count);
s32 IsTwoSummonsThenKind(CardDisplayWork** cards, u8 count, u16 kind);
s32 IsSimbaMushuItem(CardDisplayWork** cards, u8 count);
s32 IsSummonMagicJackOrBambiBlizzardItem(CardDisplayWork** cards, u8 count);
s32 IsGenieTinkerBellSummon(CardDisplayWork** cards, u8 count);
s32 IsMegaEtherMegalixirItem(CardDisplayWork** cards, u8 count);
s32 IsFireDonaldMagic(CardDisplayWork** cards, u8 count);
s32 IsCloudStopAttack(CardDisplayWork** cards, u8 count);
s32 IsAeroFireMagic(CardDisplayWork** cards, u8 count);
s32 IsAeroBlizzardMagic(CardDisplayWork** cards, u8 count);
s32 IsTwoMagicThenPeterPan(CardDisplayWork** cards, u8 count);
u8 IsLinkSideStockLearned(s32 stock, s32 side);

#endif
