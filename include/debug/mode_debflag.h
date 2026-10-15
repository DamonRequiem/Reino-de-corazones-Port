#ifndef GUARD_MODE_DEBFLAG_H
#define GUARD_MODE_DEBFLAG_H

#include "types.h"
typedef struct DebugFlag {
    const char* name;
    u32 mask;
} DebugFlag;

extern u8 gDebflagReturnToMap;

void mode_debflag_0(s32 arg);
void mode_debflag_1();
void mode_debflag_2();

#endif /* GUARD_MODE_DEBFLAG_H */
