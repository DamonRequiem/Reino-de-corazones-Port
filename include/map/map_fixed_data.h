#ifndef GUARD_MAP_FIXED_DATA_H
#define GUARD_MAP_FIXED_DATA_H

#include "types.h"

extern u8 gMapFixed0CellTypes[1536];
extern u8 gMapFixed1CellTypes[768];
extern u8 gMapFixed2CellTypes[768];
extern u8 gMapFixed3CellTypes[768];
extern u8 gMapFixed4CellTypes[512];

struct MapFixedDef;
struct PrzCardChance;
struct PrizeEntry;

extern const void* gMapFixed0Bg3Blocks[12];
extern const void* gMapFixed0Bg2Blocks[12];
extern const void* gMapFixed0Bg1Blocks[12];
extern const void* gMapFixed1Bg3Blocks[6];
extern const void* gMapFixed1Bg2Blocks[6];
extern const void* gMapFixed2Bg3Blocks[6];
extern const void* gMapFixed2Bg2Blocks[6];
extern const void* gMapFixed3Bg3Blocks[6];
extern const void* gMapFixed3Bg2Blocks[6];
extern const void* gMapFixed4Bg3Blocks[4];
extern const void* gMapFixed4Bg2Blocks[4];
extern const void* gMapFixed4Bg1Blocks[4];
extern const void* gMapFixed5Bg2Blocks[6];
extern struct MapFixedDef* gMapFixedDefs[6];
extern struct PrzCardChance* gWorldPrzCardChances[14];
extern struct PrizeEntry* gWorldPrizeLists[14];

#endif
