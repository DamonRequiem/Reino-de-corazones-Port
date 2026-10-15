#ifndef GUARD_GBA_OAM_H
#define GUARD_GBA_OAM_H

#include "types.h"

#define OAM_Y_MASK           0x00FF
#define OAM_AFFINE           0x0100
#define OAM_DOUBLE_SIZE      0x0200
#define OAM_DISABLE          0x0200
#define OAM_BLEND            0x0400

#define OAM_SHAPE_SQUARE     0x0000
#define OAM_SHAPE_HORIZONTAL 0x4000
#define OAM_SHAPE_VERTICAL   0x8000
#define OAM_SHAPE_MASK       0xC000
#define OAM_SIZE(n)          ((n) << 14)
#define OAM_X_MASK           0x01FF

#define OAM_TILE_MASK        0x03FF
#define OAM_PALETTE_MASK     0xF000

#define OAM_SHAPE_SIZE(shape, size) (((u32)OAM_SIZE(size) << 16) | (shape))

#endif
