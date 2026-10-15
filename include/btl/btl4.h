#ifndef GUARD_BTL4_H
#define GUARD_BTL4_H

#include "types.h"
#include "anim.h"
typedef struct BtlPopSrc {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 number;
} BtlPopSrc;

typedef struct BtlPopCbWork {
    void* tiles;
    void* palette;
    void* gfx;
    s32 x;
    s32 y;
    s32 z;
    s16 timer;
} BtlPopCbWork;

typedef struct BtlExpWork {
    void* palette;
    void* tiles;
    void* tiles2[6];
    void* gfx;
    void* gfx2[6];
    s16 timer;
    u8 level;
    u16 gainedExp;
    u32 lastExp;
    u32 state;
} BtlExpWork;

typedef struct BtlVslockonWork {
    void* tiles;
    void* palette;
    AnimState anim;
    void* gfx;
} BtlVslockonWork;

typedef struct BtlHpothWork {
    s32 hpRatio;
    u8 firstUpdate;
    void* palette2;
    void* palette;
    void* tiles;
    void* tiles2;
    void* tiles3;
    void* tiles4;
    void* gfx;
    void* gfx2;
    void* gfx3;
    AnimState anim2;
    AnimState anim;
    u8 unk_5C;
    s16 timer;
    s16 prevHp;
    s16 displayHp;
    s16 gaugeSize;
    u32 gaugeMode;
} BtlHpothWork;

void CreatePersistentSysmsgwinTask(void* pool, u16 message);

void task_btl_pop_cb_0(BtlPopCbWork* work, BtlPopSrc* src);
s32 task_btl_pop_cb_1(BtlPopCbWork* work);
void task_btl_pop_cb_2(BtlPopCbWork* work);
void task_btl_pop_cb_3(BtlPopCbWork* work);
void* GetExpDigitGfx(s32 digit, u8 leading);
void BtlExpSetNumber(BtlExpWork* work, u32 value);
void task_btl_exp_0(BtlExpWork* work);
s32 task_btl_exp_1(BtlExpWork* work);
void task_btl_exp_2(BtlExpWork* work);
void task_btl_exp_3(BtlExpWork* work);
void task_btl_vslockon_0(BtlVslockonWork* work);
s32 task_btl_vslockon_1(BtlVslockonWork* work);
void task_btl_vslockon_2(BtlVslockonWork* work);
void task_btl_vslockon_3(BtlVslockonWork* work);
void task_btl_hpoth_0(BtlHpothWork* work);
s32 task_btl_hpoth_1(BtlHpothWork* work);
void task_btl_hpoth_2(BtlHpothWork* work);
void task_btl_hpoth_3(BtlHpothWork* work);

#endif /* GUARD_BTL4_H */
