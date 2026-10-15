#ifndef GUARD_ROOM_DATA_H
#define GUARD_ROOM_DATA_H

#include "types.h"
#include "anim.h"

typedef struct GaEntryDef {
    s32 hpScale;
    s32 offsetX;
    s32 offsetY;
    s32 offsetZ;
    u16 x2;
    u16 y2;
    void* owner;
    AnimHeader** anims;
    void** gfxTable;
    u16 spriteCount;
} GaEntryDef;

#endif
