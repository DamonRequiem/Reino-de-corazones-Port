#ifndef GUARD_CONTINUE_UI_H
#define GUARD_CONTINUE_UI_H

#include "continue_types.h"
#include "taskpool.h"
#include "types.h"

extern TaskDesc gTaskDescContinueSora;
extern TaskDesc gTaskDescContinueRiku;

void LoadContinueCursorPalette(s32 cursor);
void ContinueSora_0(ContinueWork* work);
void ContinueRiku_0(ContinueWork* work);

#endif
