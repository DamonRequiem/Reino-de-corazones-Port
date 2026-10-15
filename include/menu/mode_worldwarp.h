#ifndef GUARD_MODE_WORLDWARP_H
#define GUARD_MODE_WORLDWARP_H

#include "types.h"

void mode_worldwarp_0();
void mode_worldwarp_1();
void mode_worldwarp_2();

typedef struct WarpIcon {
    s16 up;
    s16 down;
    s16 left;
    s16 right;
    s16 x;
    s16 y;
    s16 rect;
    s16 x2;
    s16 y2;
    u8 unk_12[0x02];
} WarpIcon;

typedef struct WarpRect {
    s16 width;
    s16 height;
    s16 x;
    s16 y;
} WarpRect;

#endif /* GUARD_MODE_WORLDWARP_H */
