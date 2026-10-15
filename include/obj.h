#ifndef GUARD_OBJ_H
#define GUARD_OBJ_H

#include "types.h"
#include "listpool.h"

enum SpriteFlag {
    SPRITE_FLAG_HFLIP = 0x1,
    SPRITE_FLAG_VFLIP = 0x2,
    SPRITE_FLAG_BLEND = 0x4,
    SPRITE_FLAG_MOSAIC = 0x8,
    SPRITE_FLAG_NO_MOSAIC = 0x10
};

#define SPRITE_PRIORITY(n) ((n) << 10)
#define SPRITE_PRIORITY_MASK SPRITE_PRIORITY(3)
typedef struct PaletteSlot {
    void* src;
    void* dst;
    u16 buffer[16];
    u8 excluded;
    u8 dirty;
} PaletteSlot;

typedef struct ObjTiles {
    const u8* src;
    u16 refCount;
    u16 index;
    u16 count;
    ListNode node;
    void* sprite;
    u8 allocated;
    u32 type;
    struct ObjTiles* self;
} ObjTiles;

typedef struct ObjAffine {
    u16 pa;
    u16 pb;
    u16 pc;
    u16 pd;
    u16 index;
    u8 doubleSize;
    s32 sx;
    s32 sy;
    u8 angle;
} ObjAffine;

typedef struct ObjPalette {
    const void* src;
    u16 refCount;
    u16 index;
    u16 count;
    ListNode node;
    u32 type;
    struct ObjPalette* self;
} ObjPalette;

#endif
