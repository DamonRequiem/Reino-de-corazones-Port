#ifndef GUARD_MODE_CHKEFF_H
#define GUARD_MODE_CHKEFF_H

#include "types.h"
#include "taskpool.h"

typedef struct ChkEffWork {
    TaskPool pool;
    s16 effectIndex;
    u8 paused;
    u16 scrollX;
    u16 scrollY;
    u8 rotation;
    s32 scale;
    u16 alphaA;
    u16 alphaB;
} ChkEffWork;

void mode_chkeff_0();
void mode_chkeff_1();
void mode_chkeff_2();

#endif /* GUARD_MODE_CHKEFF_H */
