#ifndef GUARD_MS_CHARGE_H
#define GUARD_MS_CHARGE_H

#include "ms_charge_api.h"
#include "types.h"

s16 GetMsChargeTabStart(s16 tab);
s16 GetMsChargeTabCount(s16 tab);
s16 GetMsChargeSelectedIndex();
void MsChargeSelectFirstValue();
s16 GetMsChargeValueIndex(s16 col, s16 row);
s16 GetMsChargeSelectedValue();
u16 GetMsChargeCardPoints(u16 index);
void MsChargeSellCard();
u8 MsCardIsEmpty(MsCard* card);
u8 MsCardSelectedValueIsEmpty(MsCard* card);
void MsChargeSelectNextValue(MsCard* card);
void MsChargeRemoveCard(MsCard* card);
s32 FindMsCard(u16 kind, u8 premium, s16 count);
s32 MsChargeReadMenuKeys();
s32 MsChargeSelectValueInColumn(MsCard* card, u16 col);

void mode_ms_charge_1();
void mode_ms_charge_2();
void mode_ms_charge_0();

#endif
