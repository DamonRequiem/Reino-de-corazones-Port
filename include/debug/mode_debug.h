#ifndef GUARD_MODE_DEBUG_H
#define GUARD_MODE_DEBUG_H

#include "types.h"
#include "anim.h"
#include "mode.h"
typedef struct DebugWork {
    s8 cursor;
    s8 page;
    void* tiles;
    void* palette;
    AnimState anim;
} DebugWork;

extern const char gVersionString[];
extern Mode gModeChkbtl;
extern Mode gModeChksnd;

#endif /* GUARD_MODE_DEBUG_H */
