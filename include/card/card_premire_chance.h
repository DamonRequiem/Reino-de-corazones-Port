#ifndef GUARD_CARD_PREMIRE_CHANCE_H
#define GUARD_CARD_PREMIRE_CHANCE_H

#include "card.h"
#include "types.h"

void UpdatePremireChanceCardPos(PremireChanceCardWork* work);
u8 IsPremireChanceCardOnScreen(PremireChanceCardWork* work);
void LoadPremireChanceCardGfx(PremireChanceCardWork* work);
void ReleasePremireChanceCardGfx(PremireChanceCardWork* work);
u8 StartPremireChanceCardAnim(PremireChanceCardWork* work, void* task);
s32 UpdatePremireChanceCardAnim(PremireChanceCardWork* work);

#endif
