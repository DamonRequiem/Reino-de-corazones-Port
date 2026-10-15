#ifndef GUARD_EVT_OBJ_H
#define GUARD_EVT_OBJ_H

#include "evt_object_types.h"
#include "obj.h"
#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "evt_types.h"

typedef struct EvtObjParam {
    const EvtObjRes* res;
    EvtObj* obj;
} EvtObjParam;

typedef struct EvtObjWork {
    EvtObj* obj;
    void* tiles;
    ObjPalette* palette;
    AnimState anim;
    TaskPool tasks;
} EvtObjWork;

typedef struct EvtShadowWork {
    void* palette;
    EvtObj* obj;
    void* tiles;
    void* tiles2;
    void* tiles3;
} EvtShadowWork;

extern EventState* gEventState;

void EvtObjSetGroundZ(EvtObj* obj, s32 groundZ);
void EvtObjChangeAnim(EvtObjWork* work);

#endif /* GUARD_EVT_OBJ_H */
