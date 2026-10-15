#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

#include "types.h"
#include "engine.h"
#include "listpool.h"
#include "obj.h"
#include "macros.h"

typedef struct ObjListPool {
    ListPool head;
    u16 rangeStart;
    u16 rangeEnd;
} ObjListPool;

typedef struct SpriteEntry {
    void* tiles;
    void* palette;
    ObjAffine* affine;
    void* sprite;
    u16 x;
    u16 y;
    u16 priority;
    u16 flags;
} SpriteEntry;

struct SpriteWork {
    ObjTiles tiles[128];
    ObjListPool tilePool;
    ObjPalette palettes[16];
    ObjListPool palettePool;
    SpriteEntry entries[128];
    SpriteEntry* sortPtrs[128];
    u16 entryCount;
    u16 sortLo;
    ObjAffine affine[32];
    u16 affineCount;
    u8 oamUpdatesPaused;
    u8 mosaicEnabled;
};

STATIC_ASSERT(sizeof(SpriteWork) == 0x2BB0, SpriteWorkSize);
STATIC_ASSERT(sizeof(ObjTiles) == 0x30, ObjTilesSize);
STATIC_ASSERT(sizeof(ObjPalette) == 0x28, ObjPaletteSize);
STATIC_ASSERT(sizeof(ObjListPool) == 0x14, ObjListPoolSize);
STATIC_ASSERT(sizeof(SpriteEntry) == 0x18, SpriteEntrySize);
STATIC_ASSERT(sizeof(ObjAffine) == 0x18, ObjAffineSize);

void SpriteInit();
void SpriteFree();
void SortSpriteEntries(SpriteEntry** arr, s32 lo, s32 hi);
u8 DrawSpriteSharedTiles(s16 x, s16 y, void* sprite, void* obj, void* palette, ObjAffine* affine, u16 flags, u16 priority);

#endif
