#ifndef GUARD_MODE_DECK_H
#define GUARD_MODE_DECK_H

#include "mode.h"
#include "types.h"

typedef struct MenuWork {
    void* tiles;
    void* palette;
    s32 x;
    s32 y;
    u8 state;
    u8 cursor;
} MenuWork;

extern Mode gModeDeck;

#endif
