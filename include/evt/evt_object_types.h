#ifndef GUARD_EVT_OBJECT_TYPES_H
#define GUARD_EVT_OBJECT_TYPES_H

#include "types.h"

struct AnimState;
struct EvtObjAnim;

enum EvtObjFlag {
    EVTOBJ_FLAG_ANIM_CHANGED = 0x1,
    EVTOBJ_FLAG_HIDDEN = 0x2,
    EVTOBJ_FLAG_NO_SHADOW = 0x4,
    EVTOBJ_FLAG_SHADOW_WIDE = 0x8,
    EVTOBJ_FLAG_SHADOW_SMALL = 0x10
};

typedef struct EvtObj {
    const struct EvtObjAnim* animEntry;
    s32 x;
    s32 y;
    s32 z;
    s32 groundZ;
    u16 flags;
    u16 drawFlags;
    struct AnimState* anim;
    u16 paletteIndex;
    s32 scaleX;
    s32 scaleY;
    u8 angle;
} EvtObj;

#endif
