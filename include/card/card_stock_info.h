#ifndef GUARD_CARD_STOCK_INFO_H
#define GUARD_CARD_STOCK_INFO_H

#include "card.h"
#include "types.h"

s32 UpdateStockInfoMessage(StockInfoWork* work);
void* GetCardHelpText(u16 helpIndex, u8 textIndex);
u8 GetCardHelpTextCount(u16 helpIndex);

#endif
