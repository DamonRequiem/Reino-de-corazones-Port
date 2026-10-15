#ifndef GUARD_MODE_CHKBTL_H
#define GUARD_MODE_CHKBTL_H

#include "types.h"
#include "taskpool.h"
#include "battle_debug_types.h"

typedef struct ChkBtlEntry {
    u8 world;
    s32 kind;
    s32 battleId;
    TaskDesc* taskDesc;
    const char* name;
} ChkBtlEntry;

typedef struct ChkBtlPos {
    s32 x;
    s32 y;
    s32 z;
} ChkBtlPos;

typedef struct ChkBtlWorld {
    u8 world;
    const char* name;
} ChkBtlWorld;

extern u16 gVsBattleMinY;
extern u16 gVsBattleMaxY;
extern u16 gVsBattleHalfWidth;
extern ChkBtlWork* gChkBtlWork;
extern const char gWhitePalette[32];

#endif /* GUARD_MODE_CHKBTL_H */
