#ifndef GUARD_WLOGO_H
#define GUARD_WLOGO_H

#include "obj.h"
#include "types.h"
#include "taskpool.h"
#include "anim.h"

typedef struct WlogoWonEntry {
    s32 x;
    s32 y;
    s32 speedX;
    u16 delay;
    u16 duration;
    u16 priority;
    u16 scaleIndex;
} WlogoWonEntry;

typedef struct WlogoAgrEntry {
    s16 smokeX;
    s16 smokeY;
    s16 time;
    u8 smokeAnimId;
    u8 unk_07;
    u16 flashX;
    u16 flashY;
    u8 flashAnimId;
    u8 unk_0D[0x3];
} WlogoAgrEntry;

typedef struct WlogoTtMotion {
    s32 first[6];
    s32 second[6];
} WlogoTtMotion;

typedef struct WlogoTtWork {
    u8 state;
    u16 timer;
    u16 subStep;
    u8 blend;
    u8 paletteStep;
    void* tiles;
    void* tiles2;
    void* tiles3;
    void* tiles4;
    void* tiles5;
    ObjPalette* palette;
    void* gfx;
    void* gfx2;
    void* gfx3;
    void* gfx4;
    void* gfx5;
    void* gfx6;
    void* gfx7;
    u8 unk_03C[0x4];
    AnimState anim[6];
    u8 unk_0D0[0x1C];
    u16 unk_0EC;
    u8 unk_0EE[0x12];
    s8 visible[0x8];
    s32 scaleX;
    s32 scaleX2;
    s32 scrollSpeed;
    TaskPool tasks;
} WlogoTtWork;

typedef struct WlogoBksObjWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_00C[0x18];
    s16 holdTimer;
    s16 moveTimer;
    s8 state;
    s8 id;
    s32 x;
    s32 y;
    s32 targetX;
    s32 targetY;
    s32 scaleX;
    s32 scaleY;
    u8 unk_044;
    s16 scaleIndex;
    u16 priority;
} WlogoBksObjWork;

typedef struct WlogoBksWork {
    u8 state;
    u16 timer;
    u16 paletteStep;
    u8 tileFrame;
    u16 tileFrameTimer;
    u8 blend;
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s8 visible;
    u16 frameCount;
    u16 waveTimer;
    u8 waveAmplitude;
    u8 waveFrequency;
    u16 unk_038;
    TaskPool tasks;
} WlogoBksWork;

typedef struct WlogoTtObjArg {
    s32 x;
    s32 y;
    s32 unk_08;
    s32 unk_0C;
} WlogoTtObjArg;

typedef struct WlogoTtObjWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    u16 unk_02C;
    u16 unk_02E;
} WlogoTtObjWork;

typedef struct WlogoTtLineWork {
    s16 timer;
    s16 index;
    s8 state;
    TaskPool tasks;
} WlogoTtLineWork;

typedef struct WlogoPooWork {
    u8 state;
    u16 timer;
    u8 tileFrame;
    u16 tileFrameTimer;
    u8 blend;
    u8 unk_009[0x3];
} WlogoPooWork;

typedef struct WlogoPooObjStep {
    s16 duration;
    s32 vx;
    s32 vy;
    s32 ax;
    s32 ay;
} WlogoPooObjStep;

typedef struct WlogoPooObjWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 vx;
    s32 vy;
    s32 ax;
    s32 ay;
    u16 step;
    u16 stepTimer;
    u8 done;
    u8 id;
    u8 visible;
    u8 animId;
} WlogoPooObjWork;

typedef struct WlogoTvtWork {
    void* tiles;
    void* palette;
    s16 x;
    s16 y;
    void* gfx;
    AnimState anim;
    u8 visible;
    u8 state;
    u16 timer;
    u8 tileFrame;
    u16 tileFrameTimer;
    u8 blend;
} WlogoTvtWork;

typedef struct WlogoAgrSmokeWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 unk_02C;
    u8 animId;
    u8 unk_031;
    u16 unk_032;
    u16 unk_034;
} WlogoAgrSmokeWork;

typedef struct WlogoAgrFlashWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s16 x;
    s16 y;
    u8 animId;
} WlogoAgrFlashWork;

typedef struct WlogoAgrWork {
    void* tiles;
    void* palette;
    void* gfx;
    s16 x;
    s16 y;
    u8 visible;
    u8 state;
    s16 timer;
    s16 entryIndex;
    u8 blend;
    u8 unk_017;
} WlogoAgrWork;

typedef struct WlogoDilWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 state;
    u16 timer;
    u8 blend;
    s16 x;
    s16 y;
    u8 visible;
} WlogoDilWork;

typedef struct WlogoColWork {
    void* tiles;
    void* palette;
    s16 x;
    s16 y;
    void* gfx;
    AnimState anim;
    u8 state;
    u16 timer;
    u8 tileFrame;
    u16 tileFrameTimer;
    u8 blend;
    u8 visible;
} WlogoColWork;

typedef struct WlogoHlwWork {
    u8 state;
    u16 timer;
    u8 blend;
    u8 unk_005[0x3];
} WlogoHlwWork;

typedef struct WlogoNvlObjArg {
    s32 x;
    s32 y;
    s32 animId;
} WlogoNvlObjArg;

typedef struct WlogoNvlMovWork {
    s32 x;
    s32 y;
    s32 vx;
    s32 vy;
    s32 ax;
    s32 ay;
    u8 done;
    u16 stepTimer;
    u16 step;
    u16 frameCount;
    u8 trailAnimId;
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    u8 animId;
    u8 visible;
} WlogoNvlMovWork;

typedef struct WlogoNvlObjWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    u8 animId;
} WlogoNvlObjWork;

typedef struct WlogoNvlWork {
    u8 state;
    u16 timer;
    s8 tileFrame;
    u16 tileFrameTimer;
    u16 frameCount;
    u8 blend;
} WlogoNvlWork;

typedef struct WlogoAtlWork {
    u8 state;
    u16 timer;
    u8 tileFrame;
    u16 tileFrameTimer;
    u8 blend;
    u8 waveAmplitude;
    u16 waveTimer;
} WlogoAtlWork;

typedef struct WlogoWonWork {
    void* tiles;
    void* palette;
    u16 timer;
    u8 angle;
    s32 x[10];
    s32 y[10];
    s32 speedX[10];
    void* gfx[10];
    u16 cardTimers[10];
    u8 cardPhases[10];
    u16 scaleIndex[10];
    u16 scaleTicks[10];
    u8 state;
    u8 blend;
    u8 unk_0F4[0x14];
} WlogoWonWork;

typedef struct WlogoHwtObjA {
    s32 x;
    s32 y;
    s32 unk_08;
    u8 animId;
} WlogoHwtObjA;

typedef struct WlogoHwtObjB {
    s16 duration;
    s32 vx;
    s32 vy;
    s32 ax;
    s32 ay;
    u8 isLast;
} WlogoHwtObjB;

typedef struct WlogoHwtObjWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 vx;
    s32 vy;
    s32 ax;
    s32 ay;
    u16 step;
    u16 stepTimer;
    u8 done;
    s32 unk_044;
    u8 unk_048[0x2];
    u8 id;
} WlogoHwtObjWork;

typedef struct WlogoHwtWork {
    u16 paletteStep;
    u16 timer;
    u8 state;
    u8 blend;
    u8 unk_006[0x2];
} WlogoHwtWork;

typedef struct WlogoMonsWork {
    void* tiles;
    ObjPalette* palette;
    s16 x;
    s16 y;
    void* gfx;
    AnimState anim;
    u16 paletteStep;
    u16 timer;
    u8 state;
    u8 visible;
    u8 blend;
} WlogoMonsWork;

extern s32 gWlogoTtSkew;
extern const WlogoPooObjStep gWlogoPooObjSteps[5][5];

void task_wlogo_hwt_0(WlogoHwtWork* work);
u8 task_wlogo_hwt_1(WlogoHwtWork* work);
void task_wlogo_hwt_2(WlogoHwtWork* work);
void task_wlogo_hwt_3(WlogoHwtWork* work);
void task_wlogo_hwt_obj_0(WlogoHwtObjWork* work, s32 id);
u8 task_wlogo_hwt_obj_1(WlogoHwtObjWork* work);
void task_wlogo_hwt_obj_2(WlogoHwtObjWork* work);
void task_wlogo_hwt_obj_3(WlogoHwtObjWork* work);
void task_wlogo_tt_0(WlogoTtWork* work);
u8 task_wlogo_tt_1(WlogoTtWork* work);
void task_wlogo_tt_2(WlogoTtWork* work);
void task_wlogo_tt_3(WlogoTtWork* work);
void task_wlogo_bks_obj_0(WlogoBksObjWork* work, s32 id);
u8 task_wlogo_bks_obj_1(WlogoBksObjWork* work);
void task_wlogo_bks_obj_2(WlogoBksObjWork* work);
void task_wlogo_bks_obj_3(WlogoBksObjWork* work);
void task_wlogo_bks_0(WlogoBksWork* work);
u8 task_wlogo_bks_1(WlogoBksWork* work);
void task_wlogo_bks_2(WlogoBksWork* work);
void task_wlogo_bks_3(WlogoBksWork* work);
void WlogoBksHBlankIntr();
void task_wlogo_tt_obj_0(WlogoTtObjWork* work, WlogoTtObjArg* arg);
u8 task_wlogo_tt_obj_1(WlogoTtObjWork* work);
void task_wlogo_tt_obj_2(WlogoTtObjWork* work);
void task_wlogo_tt_obj_3(WlogoTtObjWork* work);
void task_wlogo_tt_line_0(WlogoTtLineWork* work);
u8 task_wlogo_tt_line_1(WlogoTtLineWork* work);
void task_wlogo_tt_line_2(WlogoTtLineWork* work);
void task_wlogo_tt_line_3(WlogoTtLineWork* work);
void task_wlogo_poo_0(WlogoPooWork* work);
u8 task_wlogo_poo_1(WlogoPooWork* work);
void task_wlogo_poo_2(WlogoPooWork* work);
void task_wlogo_poo_3(WlogoPooWork* work);
void task_wlogo_poo_obj_0(WlogoPooObjWork* work, s32 id);
u8 task_wlogo_poo_obj_1(WlogoPooObjWork* work);
void task_wlogo_poo_obj_2(WlogoPooObjWork* work);
void task_wlogo_poo_obj_3(WlogoPooObjWork* work);
void task_wlogo_tvt_0(WlogoTvtWork* work);
u8 task_wlogo_tvt_1(WlogoTvtWork* work);
void task_wlogo_tvt_2(WlogoTvtWork* work);
void task_wlogo_tvt_3(WlogoTvtWork* work);
void task_wlogo_agr_smoke_0(WlogoAgrSmokeWork* work, WlogoAgrEntry* arg);
u8 task_wlogo_agr_smoke_1(WlogoAgrSmokeWork* work);
void task_wlogo_agr_smoke_2(WlogoAgrSmokeWork* work);
void task_wlogo_agr_smoke_3(WlogoAgrSmokeWork* work);
void task_wlogo_agr_flash0_0(WlogoAgrFlashWork* work);
u8 task_wlogo_agr_flash0_1(WlogoAgrFlashWork* work);
void task_wlogo_agr_flash0_2(WlogoAgrFlashWork* work);
void task_wlogo_agr_flash0_3(WlogoAgrFlashWork* work);
void task_wlogo_agr_flash1_0(WlogoAgrFlashWork* work, WlogoAgrEntry* arg);
u8 task_wlogo_agr_flash1_1(WlogoAgrFlashWork* work);
void task_wlogo_agr_flash1_2(WlogoAgrFlashWork* work);
void task_wlogo_agr_flash1_3(WlogoAgrFlashWork* work);
void task_wlogo_agr_0(WlogoAgrWork* work, s32 arg);
u8 task_wlogo_agr_1(WlogoAgrWork* work);
void task_wlogo_agr_2(WlogoAgrWork* work);
void task_wlogo_agr_3(WlogoAgrWork* work);
void task_wlogo_dil_0(WlogoDilWork* work);
u8 task_wlogo_dil_1(WlogoDilWork* work);
void task_wlogo_dil_2(WlogoDilWork* work);
void task_wlogo_dil_3(WlogoDilWork* work);
void task_wlogo_col_0(WlogoColWork* work);
u8 task_wlogo_col_1(WlogoColWork* work);
void task_wlogo_col_2(WlogoColWork* work);
void task_wlogo_col_3(WlogoColWork* work);
void task_wlogo_hlw_0(WlogoHlwWork* work);
u8 task_wlogo_hlw_1(WlogoHlwWork* work);
void task_wlogo_hlw_2(WlogoHlwWork* work);
void task_wlogo_hlw_3(WlogoHlwWork* work);
void task_wlogo_nvl_mov_0(WlogoNvlMovWork* work);
u8 task_wlogo_nvl_mov_1(WlogoNvlMovWork* work);
void task_wlogo_nvl_mov_2(WlogoNvlMovWork* work);
void task_wlogo_nvl_mov_3(WlogoNvlMovWork* work);
void task_wlogo_nvl_obj_0(WlogoNvlObjWork* work, WlogoNvlObjArg* arg);
u8 task_wlogo_nvl_obj_1(WlogoNvlObjWork* work);
void task_wlogo_nvl_obj_2(WlogoNvlObjWork* work);
void task_wlogo_nvl_obj_3(WlogoNvlObjWork* work);
void task_wlogo_nvl_0(WlogoNvlWork* work);
u8 task_wlogo_nvl_1(WlogoNvlWork* work);
void task_wlogo_nvl_2(WlogoNvlWork* work);
void task_wlogo_nvl_3(WlogoNvlWork* work);
void task_wlogo_atl_0(WlogoAtlWork* work);
u8 task_wlogo_atl_1(WlogoAtlWork* work);
void task_wlogo_atl_2(WlogoAtlWork* work);
void task_wlogo_atl_3(WlogoAtlWork* work);
void WlogoAtlHBlankIntr();
void WlogoEnableHBlank();
void WlogoHBlankIntr();
void WlogoDisableHBlank();
void task_wlogo_won_0(WlogoWonWork* work);
u8 task_wlogo_won_1(WlogoWonWork* work);
void task_wlogo_won_2(WlogoWonWork* work);
void task_wlogo_won_3(WlogoWonWork* work);
void task_wlogo_mons_0(WlogoMonsWork* work);
u8 task_wlogo_mons_1(WlogoMonsWork* work);
void task_wlogo_mons_2(WlogoMonsWork* work);
void task_wlogo_mons_3(WlogoMonsWork* work);

#endif /* GUARD_WLOGO_H */
