#ifndef GUARD_CHARA_TYPES_H
#define GUARD_CHARA_TYPES_H

#include "types.h"

struct BtlObj;

typedef struct CharaObjParam {
    u32 tilesAddr;
    u16 tileCount;
    u32 tilesAddr2;
    u16 tileCount2;
    u32 tilesAddr3;
    u16 tileCount3;
    u32 paletteAddr;
    u16 paletteSize;
    u32 tilesAddr4;
    u16 tileCount4;
    u32 paletteAddr2;
    u16 paletteSize2;
    u32 x;
    u32 y;
    u32 z;
    void (*callback)();
    struct BtlObj* prizeObj;
    u16 flags;
} CharaObjParam;

typedef struct CharaObjParam2 {
    u32 tilesAddr;
    u16 tileCount;
    u32 paletteAddr;
    u16 paletteSize;
    u32 x;
    u32 y;
    u32 z;
    void (*callback)();
    struct BtlObj* prizeObj;
} CharaObjParam2;

typedef struct CharaLinkData {
    u16 hp;
    u16 maxHp;
    u16 level;
    u16 winCount;
    u16 loseCount;
    u16 ap;
    u64 learnedStocks;
    u64 learnedStocks2;
    u16 worldFlags;
    u16 seed;
} CharaLinkData;

#endif
