#ifndef GUARD_LOCKON_H
#define GUARD_LOCKON_H

#include "anim.h"
#include "fld_types.h"
#include "types.h"

#define LOCKON_TARGET_NONE (-1)

typedef struct LockonWork {
    void* tiles;
    void* palette;
    void* gfx;
    FldObj* targets[8];
    u8 targetCount;
    s8 selected;
    s8 prevSelected;
    u8 timer;
    u8 unk_30;
    AnimState anim;
    u8 unk_4C;
} LockonWork;

extern s32* gLockonDoorPosition;

void task_lockon_0(LockonWork* work);
u8 task_lockon_1(LockonWork* work);
void task_lockon_2(LockonWork* work);
void task_lockon_3(LockonWork* work);
s32 VectorLength2D(s32 x, s32 y);
s32 NormalizeVector2D8(s32* x, s32* y);
s8 LockonPickNearest(s32 px, s32 py, LockonWork* work, s8 n, s8* list);
void LockonClearTargets(LockonWork* work);
u8 LockonIsInFront(u16 angle, s32 px, s32 py, FldObj* target);
void LockonGetDoorScreenPos(s32* x, s32* y);

#endif
