#ifndef GUARD_CHKOBJ_H
#define GUARD_CHKOBJ_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"

typedef struct ObjDef {
    void* gfxTable;
    void* anims;
    void* tiles;
    u16 animCount;
    void* palette;
    const char* aobName;
    const char* aclName;
    u16 paletteSize;
} ObjDef;

typedef struct ChkObjWork {
    TaskPool pool;
    s16 defIndex;
    s16 animId;
    s16 category;
    void* tiles;
    void* palette;
    AnimState anim;
    void* gfx;
    u8 paused;
    u16 angle;
    s16 maxTiles;
    s16 y;
} ChkObjWork;

#endif
