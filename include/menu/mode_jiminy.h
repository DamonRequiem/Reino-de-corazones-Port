#ifndef GUARD_MODE_JIMINY_H
#define GUARD_MODE_JIMINY_H

#include "types.h"
#include "text_types.h"
#include "jiminy_types.h"

extern TextChar gJiminyChooseEntryText[];

void JiminyFreeRows();
u8 JiminyHandleListInput();
void JiminyReloadPlainRows();
void JiminyOpenList(s16 visibleRows, s16 itemCount, const u16* const* itemTexts, const u16* itemFlags, const u16* itemChildren, s16 listX, s16 listY, s16 rowHeight);

void JiminyDetailUpdate();
void JiminyOpenPlainList(s16 visibleRows, s16 itemCount, const u16* const* itemTexts, s16 listX, s16 listY, s16 rowHeight);
void SplitThreeDecimalDigits(s16 value, u8* out);

void mode_jiminy_1();

#endif
