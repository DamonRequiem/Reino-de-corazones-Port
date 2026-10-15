#ifndef GUARD_PC_SPRITE_TYPES_H
#define GUARD_PC_SPRITE_TYPES_H

#include "types.h"
#include "macros.h"

typedef struct PcSpriteDef {
    u16 count;
    u16 attr0;
    u16 attr1;
    u16 attr2;
} PcSpriteDef;

STATIC_ASSERT(sizeof(PcSpriteDef) == 8, PcSpriteDefSize);

#endif
