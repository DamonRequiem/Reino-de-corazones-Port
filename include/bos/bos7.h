#ifndef GUARD_BOS7_H
#define GUARD_BOS7_H

#include "battle_actor_types.h"
#include "types.h"
#include "taskpool.h"
#include "anim.h"
#include "bos7_api.h"
#include "obj.h"

typedef struct LstState {
    s16 animSet;
    s16 state;
    u16 step;
    s16 timer;
    s16 delay;
    s16 hurtTimer;
    s16 bobFrame;
    s16 kind;
    s16 index;
    s16 shots;
    s16 falTimer;
    u16 angle;
    u16 unk_018;
    u8 fireAngle;
    u8 aimAngle;
    s16* facing;
    u16* falCount;
    s16* unk_024;
    s32 x;
    s32 y;
    s32 z;
    s32 orbitX;
    s32 orbitY;
    s32 orbitZ;
    s32 bobZ;
    s32 startX;
    s32 startY;
    s32 startZ;
    s32 targetX;
    s32 targetY;
    s32 targetZ;
    s32 fireX;
    s32 fireY;
    s32 fireZ;
    u32 actorX;
    u32 actorY;
    u32 actorZ;
    u32 scaleX;
    u32 scaleY;
    AnimState anim;
    ObjTiles* tiles;
    ObjPalette* palette;
    ObjPalette* palette2;
    BtlObj obj;
    TaskPool tasks;
    Task* lsrTask;
    Task* lsrTask2;
    Task* lsrTask3;
} LstState;

typedef struct LstEdgWork {
    s16 state;
    s16 step;
    s16 timer;
    s16 delay;
    s32 x;
    s32 y;
    s32 z;
    s32 homeX;
    s32 homeY;
    s32 homeZ;
    s32 targetX;
    s32 targetY;
    s32 targetZ;
    AnimState anim;
    ObjTiles* tiles;
    ObjPalette* palette;
} LstEdgWork;

typedef struct LstCtrWork {
    s16* unk_000;
    s16 count;
    s16 index;
    s16 state;
    s16 step;
    s16 timer;
    s16 delay;
    u8 unk_010;
    s16 duration;
    s32 curX;
    s32 curY;
    s32 curZ;
    s32 offsetX;
    s32 offsetY;
    s32 offsetZ;
    s32 x;
    s32 y;
    s32 z;
    s32 x2;
    s32 y2;
    s32 z2;
    AnimState anim;
    ObjTiles* tiles;
    ObjPalette* palette;
    u8 unk_064[0x124];
} LstCtrWork;

enum BosLstFldCameraMode {
    BOS_LST_FLD_CAMERA_MODE_FOLLOW_PLAYER,
    BOS_LST_FLD_CAMERA_MODE_FOLLOW_BOSS,
    BOS_LST_FLD_CAMERA_MODE_FOLLOW_PLAYER_SLOW
};

enum BosLstFldBgMode {
    BOS_LST_FLD_BG_MODE_HORIZON,
    BOS_LST_FLD_BG_MODE_TUNNEL,
    BOS_LST_FLD_BG_MODE_STAR_DRIFT,
    BOS_LST_FLD_BG_MODE_STAR_STREAM,
    BOS_LST_FLD_BG_MODE_BLANK
};

typedef struct LstFldWork {
    s32 cameraMode;
    s32 bgMode;
    s32 fadeStep;
    s32 scrollDir;
    s32 nextBgMode;
    s32 nextScrollDir;
    s32 frameCount;
    s32 scrollSpeed;
    u16 scrollX;
    u16 scrollY;
    u16 paletteBuf[0x50];
    u16 vofsTable[0x340];
    u16 hofsTable[0x4A0];
    u16 scanlineBuf[2][160];
} LstFldWork;

typedef LstState LstBitWork;

typedef struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct LstLsrWork {
    s16 state;
    u8 angle;
    s32 kind;
    s16* facing;
    u16* falCount;
    s16 timer;
    s16 delay;
    s16 duration;
    u8 unk_016[0x0E];
    Vec3 pos;
    Vec3 pos2;
    ObjTiles* tiles;
    ObjPalette* palette;
    AnimState anim;
} LstLsrWork;

typedef struct LstPtlWork {
    s16 state;
    s16 step;
    s16 timer;
    s16 delay;
    s32 x;
    s32 y;
    s32 wobbleX;
    s32 wobbleY;
    AnimState anim;
    ObjTiles* tiles;
    ObjPalette* palette;
} LstPtlWork;

typedef struct LstFalWork {
    s32 kind;
    s32 x;
    s32 y;
    s32 z;
    s32 vx;
    s32 vz;
    s32 lift;
    u16* falCount;
    ObjTiles* tiles;
    ObjPalette* palette;
    AnimState anim;
} LstFalWork;

typedef struct LstSnpWork {
    u8 angle;
    s32 x;
    s32 y;
    s32 z;
    s32 vx;
    s32 vz;
    ObjTiles* tiles;
    ObjPalette* palette;
    AnimState anim;
} LstSnpWork;

typedef struct LstFldArg {
    void* tiles;
    u16 tilesSize;
    void* palette;
    u16 paletteSize;
} LstFldArg;

typedef struct LstEdgArg {
    s32 delay;
    s32 x;
    s32 y;
    s32 z;
} LstEdgArg;

typedef struct LstLsrArg {
    s32 kind;
    s16* facing;
    u16* falCount;
} LstLsrArg;

typedef struct LstFalAnim {
    u16 anim;
    u16 unk_02;
} LstFalAnim;

typedef struct LstPtlArg {
    u16 delay;
    s32 x;
    s32 y;
} LstPtlArg;

extern const EmyKind gBosLstCtrEmyKind;

void BosLstFldUpdateShake();
void BosLstFldResetShake();
void BosLstFldSetShake(s16 pattern);
s32 BosLstFldGetShake();

void task_bos_lst_fld_0(LstFldWork* work, LstFldArg* arg);
u8 task_bos_lst_fld_1(LstFldWork* work);
void task_bos_lst_fld_3(LstFldWork* work);
void task_bos_lst_bit_3(LstBitWork* work);
void task_bos_lst_lsr_0(LstLsrWork* work, LstLsrArg* arg);
u8 task_bos_lst_lsr_1(LstLsrWork* work);
void task_bos_lst_lsr_2(LstLsrWork* work);
u8 BosLstLsrSpawnFal(LstLsrWork* work);
void task_bos_lst_lsr_3(LstLsrWork* work);
void task_bos_lst_ptl_0(LstPtlWork* work, LstPtlArg* arg);
u8 task_bos_lst_ptl_1(LstPtlWork* work);
void task_bos_lst_ptl_2(LstPtlWork* work);
void task_bos_lst_ptl_3(LstPtlWork* work);
void task_bos_lst_fal_0(LstFalWork* work, LstFalArg* arg);
u8 task_bos_lst_fal_1(LstFalWork* work);
void task_bos_lst_fal_2(LstFalWork* work);
void task_bos_lst_fal_3(LstFalWork* work);
void task_bos_lst_snp_0(LstSnpWork* work, LstSnpArg* arg);
u8 task_bos_lst_snp_1(LstSnpWork* work);
void task_bos_lst_snp_2(LstSnpWork* work);
void task_bos_lst_snp_3(LstSnpWork* work);
void task_bos_lst_fld_2();
void task_bos_lst_edg_0(LstEdgWork* work, LstEdgArg* arg);
u8 task_bos_lst_edg_1(LstEdgWork* work);
void task_bos_lst_edg_2(LstEdgWork* work);
void task_bos_lst_edg_3(LstEdgWork* work);
void task_bos_lst_ctr_0(LstCtrWork* work, LstCtrArg* arg);
u8 task_bos_lst_ctr_1(LstCtrWork* work);
void task_bos_lst_ctr_2(LstCtrWork* work);
void task_bos_lst_ctr_3(LstCtrWork* work);
s32 BosLstBitSquare(s32 x);
s32 BosLstBitSquare2(s32 x);
s32 BosLstSnpSquare(s32 x);
s32 BosLstSnpSquare2(s32 x);
s32 BosLstFldSquare(s32 x);
s32 BosLstFldSquare2(s32 x);
s32 BosLstEdgSquare(s32 x);
s32 BosLstEdgSquare2(s32 x);
s32 BosLstLsrSquare(s32 x);
s32 BosLstLsrSquare2(s32 x);
s32 BosLstPtlSquare(s32 x);
s32 BosLstPtlSquare2(s32 x);
s32 BosLstFalSquare(s32 x);
s32 BosLstFalSquare2(s32 x);
s32 BosLstCtrSquare(s32 x);
s32 BosLstCtrSquare2(s32 x);
u8 BosLstEdgIsActive(Task* task);
u8 BosLstPtlIsActive(Task* task);
u8 BosLstLsrIsFiring(Task* task);
s32 BosLstLsrSqrt(s32 n);
s32 BosLstCtrSqrt(s32 n);
u8 BosLstBitSpawnFal(LstState* work, s32 atTarget);
s32 BosLstBitAtanLookup(s32 x, s32 y);
s32 BosLstBitAngleBetween(s32 x0, s32 y0, s32 x1, s32 y1);
s32 BosLstBitAngleDiff(u8 from, u8 to);
void BosLstFldDarkenPalette(u16* dst, u16* src, s32 count, s32 level);
void task_bos_lst_bit_0(LstState* work, LstBitArg* arg);
u8 task_bos_lst_bit_1(LstState* work);
void task_bos_lst_bit_2(LstState* work);
void BosLstBitHandleHit(LstState* work);
void BosLstLsrFire(Task* task, Vec3* origin, Vec3* target, s32 angle, u16 delay);
void BosLstLsrStop(Task* task);

#ifdef VERSION_EU
u8 BosLstBitIsScaling(Task* task);
#endif

#endif /* GUARD_BOS7_H */
