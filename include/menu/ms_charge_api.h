#ifndef GUARD_MS_CHARGE_API_H
#define GUARD_MS_CHARGE_API_H

#include "types.h"

typedef struct MsCard {
    u16 kind;
    u16 cardId;
    u16 category;
    s16 values[10][2];
    u8 premium;
    u32 sortKey;
} MsCard;

MsCard* GetMsChargeSelectedCard();
void MsChargeLoadGrid();
void MsChargeLoadSelectedCard();
void MsChargeDrawPoints();
void MsChargeDrawCardCounts();
void MsChargeDrawCategoryCounts();
void MsChargeDrawValueCounts();
void MsChargeDrawTab(s16 tab);
void MsChargeBuildCardList();
void MsChargeHandleGridInput();
void MsChargeHandleTabInput();
void MsChargeHandleValueInput();
void MsChargeHandleConfirmInput();
void MsChargeHandleNoticeInput();
void MsChargeDraw();

#endif
