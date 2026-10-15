#ifndef GUARD_MODE_CHKSND_H
#define GUARD_MODE_CHKSND_H

#include "types.h"
typedef struct ChkSndEntry {
    const char* name;
    u16 songNum;
} ChkSndEntry;

void mode_chksnd_0();
void mode_chksnd_1();
void mode_chksnd_2();

#endif /* GUARD_MODE_CHKSND_H */
