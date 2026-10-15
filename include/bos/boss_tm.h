#ifndef GUARD_BOSS_TM_H
#define GUARD_BOSS_TM_H

#include "types.h"
#include "battle_actor_types.h"
#include "anim.h"
#include "taskpool.h"
#include "obj.h"
#include "macros.h"

typedef struct TmArmSrc {
    s32 x;
    s32 y;
    s32 z;
    s32 x2;
    s32 y2;
    s32 z2;
    struct TmWork* tm;
} TmArmSrc;

enum TmFlag {
    TM_FLAG_HURT = 0x1,
    TM_FLAG_ATTACK_DONE = 0x2,
    TM_FLAG_HURT_NO_RECOIL = 0x4,
    TM_FLAG_IN_EVENT = 0x8,
    TM_FLAG_TABLE_JUST_RAISED = 0x10,
    TM_FLAG_FACING_LEFT = 0x20,
    TM_FLAG_SWITCHING_SIDES = 0x40,
    TM_FLAG_GIMMICK_DROP_ROLLED = 0x80
};

enum BosTmState {
    BOS_TM_STATE_IDLE,
    BOS_TM_STATE_FIRE,
    BOS_TM_STATE_SLAM_TABLE,
    BOS_TM_STATE_SLAM_GROUND,
    BOS_TM_STATE_WALK_LEFT,
    BOS_TM_STATE_WALK_LEFT_SETTLE,
    BOS_TM_STATE_WALK_RIGHT,
    BOS_TM_STATE_WALK_RIGHT_SETTLE,
    BOS_TM_STATE_RESUME_WALK,
    BOS_TM_STATE_SPIN,
    BOS_TM_STATE_FIRE_TWICE,
    BOS_TM_STATE_SLAM_GROUND_SLOW,
    BOS_TM_STATE_RECOIL,
    BOS_TM_STATE_DEFEATED,
    BOS_TM_STATE_CARD_BROKEN,
    BOS_TM_STATE_EVENT_IDLE,
    BOS_TM_STATE_NONE,
    BOS_TM_STATE_FROZEN
};

enum BosTmTableState {
    BOS_TM_TABLE_STATE_DOWN,
    BOS_TM_TABLE_STATE_MOVING,
    BOS_TM_TABLE_STATE_UP
};

typedef struct TmWork {
    u16 x;
    u16 y;
    u16 z;
    s32 baseX;
    s32 baseY;
    s32 baseZ;
    s32 x2;
    s32 y2;
    s32 z2;
    s32 vx;
    s32 vy;
    u16 flags;
    u32 state;
    s16 hitCount;
    s16 hurtTimer;
    s16 step;
    s16 stepTimer;
    s16 stateTimer;
    s8 tableState;
    u8 unk_3B;
    s32 resumeState;
    u16 tileIndex;
    u16 tileCount;
    u16 paletteIndex;
    TmArmSrc arm;
} TmWork;

typedef struct TmBodyWork {
    TmWork* tm;
    ObjTiles* tiles;
    ObjPalette* palette;
    ObjPalette* palette2;
    BtlObj body;
    u8 unk_120[0x4];
    void* gfx;
    u8 angle;
    BtlObj body2;
    u8 unk_23C[0x4];
    void* gfx2;
    u8 angle2;
    BtlObj body3;
    u8 unk_358[0x4];
    void* gfx3;
    u8 angle3;
    BtlObj body4;
    u8 unk_474[0x4];
    void* gfx4;
    u8 angle4;
    u8 unk_47D[0x3];
    s16 unk_480;
    s16 angleStep;
    s16 angleTimer;
    s16 unk_486;
    u8 unk_488;
    s16 hp;
    s16 prevHp;
    s16 unk_48E;
    u8 unk_490;
    s16 unk_492;
} TmBodyWork;

typedef struct TmTblWork {
    TmWork* tm;
    Collider collider;
    u16 height;
    u8 unk_062;
    u16 unk_064;
    s8 frame;
    u8 gimmickPlayed;
    u32 state;
} TmTblWork;

typedef struct TmArmPos {
    s32 x;
    s32 y;
    s32 z;
    u16 angle;
} TmArmPos;

typedef struct TmClbArg {
    u32 moveMode;
    u32 spinMode;
    TmArmPos* src;
    s32 vz;
    ObjTiles* tiles;
    void* gfx;
} TmClbArg;

typedef struct TmClbWork {
    TmClbArg* arg;
    ObjTiles* tiles;
    ObjPalette* palette;
    u16 angle;
    s32 x;
    s32 y;
    s32 z;
} TmClbWork;

typedef struct TmAnimFrame {
    s16 duration;
    u8 unk_02[0x2];
    u8 angles[0x10];
} TmAnimFrame;

typedef struct TmAnim {
    s16 timer;
    s16 frame;
    s16 frameCount;
    const TmAnimFrame* frames;
} TmAnim;

typedef struct TmArmJoint {
    s32 curX;
    s32 curY;
    u8 angle;
    s32 x;
    s32 y;
    u16 targetAngle;
    AnimState anim;
    void* gfx;
} TmArmJoint;

typedef struct TmArmWork {
    ObjTiles* tiles;
    ObjPalette* palette;
    ObjPalette* palette2;
    TmArmSrc* src;
    union {
        TmArmJoint all[8];
        TmArmJoint arms[2][4];
    } joints;
    u16 timer;
    u16 timer2;
    TaskPool tasks;
    TmClbArg clb;
    TmClbArg clb2;
    TmArmPos tips[2];
    TmAnim jointAnim;
    TmAnim jointAnim2;
    u8 clbSwapped;
    u32 prevState;
    ObjTiles* tiles2;
    AnimState anim;
    u8 paletteStep;
} TmArmWork;

typedef struct TmFootWork {
    u16 unk_000;
    u8 unk_002;
    u8 footFrame;
    u8 footFrame2;
    ObjTiles* tiles;
    ObjTiles* tiles2;
    ObjTiles* tiles3;
    ObjPalette* palette;
    ObjPalette* palette2;
    BtlObj body;
    void* gfx;
    u8 angle;
    BtlObj body2;
    void* gfx2;
    u8 angle2;
    BtlObj body3;
    void* gfx3;
    u8 angle3;
    BtlObj body4;
    void* gfx4;
    u8 angle4;
    TmWork* tm;
    u32 unk_480;
} TmFootWork;

STATIC_ASSERT(sizeof(TmArmWork) == 0x258, TmArmWorkSize);

STATIC_ASSERT(sizeof(TmFootWork) == 0x484, TmFootWorkSize);

typedef struct TmBodyStep {
    s16 dx;
    s16 dz;
    u8 dAngle;
    u8 unk_05[0x3];
    s16 dx2;
    s16 dz2;
    u8 dAngle2;
    u8 unk_0D[0x3];
    s16 dx3;
    s16 dz3;
    u8 unk_14[0x2];
    s16 gfx3Index;
    s16 dx4;
    s16 dz4;
    u8 unk_1C[0x2];
    s16 gfx4Index;
} TmBodyStep;

typedef struct TmFootStep {
    s16 unk_00;
    s16 dz;
    s16 unk_04;
    s16 gfxIndex;
    s16 unk_08;
    s16 dz2;
    s16 unk_0C;
    s16 gfx2Index;
    s16 x3;
    s16 z3;
    u8 unk_14[0x4];
    s16 x4;
    s16 z4;
    u8 unk_1C[0x4];
} TmFootStep;

STATIC_ASSERT(sizeof(TmWork) == 0x64, TmWorkSize);
STATIC_ASSERT(sizeof(TmBodyWork) == 0x494, TmBodyWorkSize);

void BosTmBodyResetTimers(TmBodyWork* work);
void BosTmBodyInitEnemy(BtlObj* obj, s16 x, s16 y, s16 z);
void BosTmBodySetObjPos(BtlObj* obj, s16 x, s16 y, s16 z);
void BosTmBodyReleaseEnemy(BtlObj* obj);
void BosTmBodyUpdateAngle(TmBodyWork* work);
void BosTmBodyPlaceParts(TmBodyWork* work);
void BosTmBodyResetPose(TmBodyWork* work);
void BosTmBodySetDefeatPose(TmBodyWork* work);
void BosTmBodySetBreakPose(TmBodyWork* work);
void BosTmBodyApplyThrowStep(TmBodyWork* work, s16 step);
void BosTmBodySetWalkPose(TmBodyWork* work);
void BosTmBodyWalk(TmBodyWork* work);
void BosTmBodyUpdateRecoil(TmBodyWork* work);
void BosTmBodyApplySpinStep(TmBodyWork* work, s16 step);
void BosTmBodyChooseAction(TmBodyWork* work);
void BosTmBodyUpdateReaction(BtlObj* obj, TmBodyWork* work);
void BosTmBodyRollBossCard(TmBodyWork* work);

s32 GetAbsoluteDifference(s32 x0, s32 x1);
void BosTmSetArmPositions(TmWork* work);
void task_bos_tm_0(TmWork* work, BtlObj* arg);
u8 task_bos_tm_1(TmWork* work);
void task_bos_tm_2(TmWork* work);
void task_bos_tm_3(TmWork* work);
void BosTmDestroyParts();
void BosTmArmUpdateArm1(TmArmWork* work);
void BosTmArmUpdateArm0(TmArmWork* work);
u8 task_bos_tm_clb_1(TmClbWork* work);
u8 task_bos_tm_arm_1(TmArmWork* work);
void task_bos_tm_arm_3(TmArmWork* work);
void task_bos_tm_foot_3(TmFootWork* work);
void task_bos_tm_clb_0(TmClbWork* work, TmClbArg* arg);
void task_bos_tm_clb_2(TmClbWork* work);
void task_bos_tm_tbl_0(TmTblWork* work, TmWork* arg);
void task_bos_tm_tbl_3(TmTblWork* work);
void task_bos_tm_clb_3(TmClbWork* work);
void BosTmFootSetPartPos(BtlObj* obj, s32 x, s32 y, s32 z);
void BosTmFootReleasePart(BtlObj* work);
void task_bos_tm_body_3(TmBodyWork* work);
void CreateBosTmClbTask(TaskPool* pool, TmClbArg* clb, TmArmPos* tip);
void BosTmClbThrow(TmClbArg* clb, TmArmPos* tip, s32 vz);
void BosTmClbHoldSpinning(TmClbArg* clb, TmArmPos* tip);
void BosTmClbHold(TmClbArg* clb, TmArmPos* tip, u8 mode);
void BosTmArmSetTargetAngles(TmArmJoint* joints, const u8* src);
void BosTmArmStartJointAnim(TmAnim* anim, const TmAnimFrame* src, u16 frameCount, TmArmJoint* joints);
void BosTmArmUpdateArm1Tip(TmArmWork* work);
void BosTmArmUpdateArm0Tip(TmArmWork* work);
void BosTmFootSyncCollider(BtlObj* sub, TmFootWork* work);
void BosTmFootApplyThrowStep(TmFootWork* work, s16 step);
void BosTmFootWalk(TmFootWork* work);
void BosTmFootApplySpinStep(TmFootWork* work, s16 step);
void BosTmArmUpdateJoints(TmArmJoint* joints, u16 shift);
void BosTmArmStepJointAnim(TmArmJoint* joints, TmAnim* anim);

extern s16 gBosTmActorZ;
extern s16 gBosTmActorOriginZ;
extern s16 gBosTmActorY;
extern s16 gBosTmBossY;
extern BtlObj gBosTmBodyObjCopy;
extern s16 gBosTmArmImpactViewX;
extern s32 gBosTmArmImpactViewFixedX;
extern s16 gUnk_0203AC68;
extern s16 gBosTmArmImpactViewY;
extern s32 gUnk_0203AC70;
extern u16 gBosTmArmSpinTimer;
extern s32 gBosTmArmImpactViewFixedY;

void task_bos_tm_body_0(TmBodyWork* work, TmWork* arg);
u8 task_bos_tm_body_1(TmBodyWork* work);
void task_bos_tm_body_2(TmBodyWork* work);
void task_bos_tm_foot_0(TmFootWork* work, TmWork* arg);
u8 task_bos_tm_foot_1(TmFootWork* work);
void task_bos_tm_foot_2(TmFootWork* work);

#endif
