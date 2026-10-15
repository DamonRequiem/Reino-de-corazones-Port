#ifndef GUARD_MODE_STAFFROLL_H
#define GUARD_MODE_STAFFROLL_H

#include "types.h"
#include "staff_roll_types.h"
#include "evt_object_types.h"
#include "obj.h"
#include "sroll.h"
#include "taskpool.h"

typedef struct StaffRollLabelArg {
    u16 kind;
    s32 x;
    s32 y;
} StaffRollLabelArg;

typedef struct StaffRollTaskArg {
    u16 kind;
    u16 animId;
    u16 nameIndex;
    s32 x;
    s32 y;
    s32 targetX;
    s32 targetY;
} StaffRollTaskArg;

typedef struct StaffRollLogoArg {
    s32 x;
    s32 y;
    s32* scrollY;
    s32* scrollSpeed;
    u16 animId;
} StaffRollLogoArg;

typedef struct StaffRollSecnArg {
    s32 index;
    s32 x;
    s32 y;
    s32* scrollY;
    s32* scrollSpeed;
} StaffRollSecnArg;

typedef struct StaffRollWork {
    u8 unk_000;
    u8 unk_001;
    u16 flags;
    u16 unk_004;
    s32 phase;
    s32 phaseTimer;
    s32 musicFrames;
    s32 secnCount;
    u8 unk_018[0x60];
    s32 blendMode;
    s32 blendDuration;
    s32 blendTimer;
    s32 sceneState;
    s32 sceneTimer;
    s32 sceneStep;
    s32 sceneIndex;
    s32 nextScene;
    s32 sceneScroll;
    const StaffRollScene* scene;
    u8 creditsEnded;
    s32 creditsState;
    s32 creditsTimer;
    s32 unk_0AC;
    s32 lastRow;
    s32 scrollSpeed;
    s32 scrollY;
    s32 imageState;
    s32 imageTimer;
    s32 endState;
    s32 endTimer;
    const s32* script;
    s32 scriptPos;
    s32 scriptFrame;
    s32 activeOp;
    s32 moveObj;
    s32 opTimer;
    s32 moveStartX;
    s32 moveStartY;
    s32 moveEndX;
    s32 moveEndY;
    s32 opDuration;
    ObjPalette* palette;
    TaskPool tasks;
    TaskPool tasks2;
    Task* subTasks[6];
    EvtObj objs[3];
    SrollWork text;
} StaffRollWork;

#endif
