#ifndef GUARD_MS_SHOP_HOSI_H
#define GUARD_MS_SHOP_HOSI_H

#include "ms_types.h"
#include "types.h"

typedef struct MsShopHosiWork {
    s32 x;
    s32 y;
    s32 velX;
    s32 velY;
    s16 frame;
    s16 timer;
    s16 frameDuration;
    void* palette;
    void* tiles;
} MsShopHosiWork;

void task_ms_shop_hosi_0(MsShopHosiWork* work, MsShopHosiArg* arg);
s32 task_ms_shop_hosi_1(MsShopHosiWork* work);
void task_ms_shop_hosi_2(MsShopHosiWork* work);
void task_ms_shop_hosi_3(MsShopHosiWork* work);

#endif /* GUARD_MS_SHOP_HOSI_H */
