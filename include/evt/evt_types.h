#ifndef GUARD_EVT_TYPES_H
#define GUARD_EVT_TYPES_H

#include "types.h"
#include "macros.h"

typedef struct EvtObjRes {
    u16 tileCount;
    u8 unk_02[0x06];
    void* palette;
} EvtObjRes;

typedef struct EvtAnimDef {
    void* gfxTable;
    void* anims;
    void* tiles;
} EvtAnimDef;

typedef struct EvtObjAnim {
    const EvtAnimDef* animDef;
    u8 unk_04[0x08];
    u16 animId;
    u16 flags;
} EvtObjAnim;

typedef struct EvtObjResTable {
    EvtObjRes res;
    u8 unk_0C[0x04];
} EvtObjResTable;

STATIC_ASSERT(sizeof(EvtAnimDef) == 12, EvtAnimDefSize);
STATIC_ASSERT(sizeof(EvtObjAnim) == 16, EvtObjAnimSize);
STATIC_ASSERT(sizeof(EvtObjResTable) == 16, EvtObjResTableSize);

struct EvtObj;
struct Task;

enum EventFlag {
    EVENT_FLAG_PAUSED = 0x1,
    EVENT_FLAG_STARTED = 0x2,
    EVENT_FLAG_PLAYER_CONTROL = 0x4
};

typedef struct EventState {
    struct EvtObj* charaObjs[16];
    struct Task* bossTask;
    s32 mapAnim;
    s32 cameraX;
    s32 cameraY;
    s32 centerX;
    s32 centerY;
    s32 x;
    s32 y;
    s32 bossChara;
    u32 flags;
    s16 shakeX;
    s16 shakeY;
    u16 frame;
    u16 bldCnt;
    u16 bldAlpha;
    s32 eventId;
    u8 hasBg2Map;
    u8 hasBg1Map;
    u8 running;
    u8 talking;
    u8 focusSpeaker;
    u8 msgWaitActive;
    u8 unk_7E;
    u8 fadedOut;
    u8 bgEffectActive;
    u8 msgWinOpen;
    u8 ending;
    u8 endRequest;
    u8 answerYes;
    u8 askedYesNo;
    u8 particleCount;
    u8 msgWinPosition;
    u8 speaker;
    u8 focusSteps;
    u8 skipHoldTime;
    u8 msgWinCentered;
} EventState;

#endif
