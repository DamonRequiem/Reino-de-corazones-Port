#ifndef GUARD_BOS2_H
#define GUARD_BOS2_H

#include "battle_actor_types.h"
#include "boss_jafar_types.h"
#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "obj.h"
#include "macros.h"

extern void* gBosJfMajinFrameMaps[49];
extern void* gBosJfMajinFrameTiles[49];
extern u32 gBosJfMajinBeamScales[27];
extern u32 gUnk_09EF2A00;
extern u32 gUnk_09EF2A04;
extern u32 gUnk_09EF2A08;
extern u32 gUnk_09EF2A0C;
extern u32 gUnk_09EF2A10;
extern u32 gUnk_09EF2A14;
extern u32 gUnk_09EF2A18;
extern u32 gUnk_09EF2A1C;
extern s8 gBosJfRockAnims[9];
extern s8 gUnk_09EF2A41;
extern s16 gBosJfRockGfx2Frames[12];

extern void* gBosJfPillarMaps[2][15];

enum DsdFlag {
    DSD_FLAG_HURT = 0x1,
    DSD_FLAG_DEFEAT_DONE = 0x2,
    DSD_FLAG_PLATFORM_ACTIVE = 0x8,
    DSD_FLAG_IN_EVENT = 0x10,
    DSD_FLAG_PLAYER_ON_PLATFORM = 0x20,
    DSD_FLAG_DRIFT_CHANGED = 0x40
};

enum BosDsdState {
    BOS_DSD_STATE_RETURN,
    BOS_DSD_STATE_IDLE,
    BOS_DSD_STATE_ATTACK_START,
    BOS_DSD_STATE_APPROACH,
    BOS_DSD_STATE_SHOCKWAVE,
    BOS_DSD_STATE_SUMMON,
    BOS_DSD_STATE_ENERGY_HOMING,
    BOS_DSD_STATE_ENERGY_RAIN,
    BOS_DSD_STATE_CARD_BROKEN,
    BOS_DSD_STATE_EVENT_IDLE,
    BOS_DSD_STATE_UNUSED,
    BOS_DSD_STATE_DEFEATED
};

enum BosDsdSummonStep {
    BOS_DSD_SUMMON_STEP_PLUNGE,
    BOS_DSD_SUMMON_STEP_OPEN,
    BOS_DSD_SUMMON_STEP_START_SPAWN,
    BOS_DSD_SUMMON_STEP_SPAWN_SHADOWS,
    BOS_DSD_SUMMON_STEP_STOP_SPAWN,
    BOS_DSD_SUMMON_STEP_CLOSE,
    BOS_DSD_SUMMON_STEP_WARP_SHADOWS,
    BOS_DSD_SUMMON_STEP_END
};

enum BosDsdHpPhase {
    BOS_DSD_HP_PHASE_HIGH,
    BOS_DSD_HP_PHASE_MID,
    BOS_DSD_HP_PHASE_LOW
};

typedef struct DsdWork {
    BtlObj body[3];
    u32 lastState;
    u32 state;
    u32 attackState;
    s16 attackCycle;
    u32 bodyX;
    u32 bodyY;
    u32 bodyZ;
    u16 hitCount;
    u16 timer;
    s16 stateStep;
    s16 stepTimer;
    s16 bgFrame;
    s16 bgFrameTimer;
    s16 flags;
    s8 hpPhase;
    s32 driftX;
    ObjTiles* tiles;
    ObjPalette* palette;
    ObjTiles* tiles2;
    ObjPalette* palette2;
    ObjPalette* palette3;
    ObjTiles* tiles3;
    ObjPalette* palette4;
    TaskPool tasks;
    u16 unk_390;
    u16 unk_392;
} DsdWork;

typedef struct DsdEnergy1Work {
    DsdWork* dsd;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 vx;
    s32 vy;
    s32 vz;
    u8 angle;
    u8 targetAngle;
    s32 speed;
    s32 unk_30;
    s16 state;
    u16 unk_36;
    s16 timer;
    u16 unk_3A;
    s16 chargeTime;
    u8 unk_3E[0x2];
    s16 retargetTimer;
    void* gfx;
    s8 visible;
} DsdEnergy1Work;

typedef struct DsdEnergy2Work {
    DsdWork* dsd;
    s32 x;
    s32 y;
    s32 z;
    s32 scaleX;
    s32 scaleY;
    s32 unk_18;
    s32 unk_1C;
    s32 vx;
    s32 vy;
    s32 vz;
    s16 state;
    u16 unk_2E;
    s16 timer;
    s16 chargeTime;
    s8 dropCount;
    u8 dropTotal;
    void* gfx;
    s8 visible;
} DsdEnergy2Work;

typedef struct DsdRockWork {
    DsdWork* dsd;
    s32 x;
    s32 y;
    s32 z;
    s32 vx;
    s32 unk_14;
    s32 vz;
    void* gfx;
    u8 front;
} DsdRockWork;

typedef struct DsdCircleWork {
    DsdWork* dsd;
    void* gfx;
    s32 x;
    s32 y;
    s32 z;
    s16 paletteTimer;
    s16 paletteFrame;
    s16 endTimer;
    s8 frame;
    s16 summonTimer;
} DsdCircleWork;

typedef struct DsdMainWork {
    DsdWork* dsd;
    u16 moveSteps;
    s16 stepTimer;
    u8 step;
    s16 baseFrame;
    void* tiles;
    void* tiles2;
    void* gfx;
    void* gfx2;
    AnimState anim;
    AnimState anim2;
    void* palette;
    void* palette2;
    s8 spriteVisible;
    TaskPool tasks;
    Task* energy2Task;
    s8 lastBreakDifference;
    BtlObj body;
    Task* energy1Task;
    Task* energy1Task2;
    Task* energy1Task3;
} DsdMainWork;

enum DsdItaFlag {
    DSD_ITA_FLAG_SINKING = 0x1,
    DSD_ITA_FLAG_RISING = 0x2
};

typedef struct DsdItaWork {
    DsdWork* dsd;
    Collider collider;
    s32 x;
    s32 y;
    s32 z;
    s32 vz;
    s32 gravity;
    s16 moveSteps;
    u16 lifeTimer;
    s16 offTimer;
    u8 state;
    u16 flags;
    s16 dipStep;
    s32 dipOffset;
    u8 unk_084[0x4];
    void* gfx;
    void* gfx2;
} DsdItaWork;

enum JfFlag {
    JF_FLAG_HURT = 0x1,
    JF_FLAG_DEFEAT_DONE = 0x2,
    JF_FLAG_GIMMICK_PENDING = 0x4,
    JF_FLAG_IN_EVENT = 0x8,
    JF_FLAG_NEEDS_BG_CLIP = 0x10
};

enum BosJfState {
    BOS_JF_STATE_IDLE,
    BOS_JF_STATE_SWITCH_SIDE,
    BOS_JF_STATE_ROCK_THROW,
    BOS_JF_STATE_SLAM,
    BOS_JF_STATE_BEAM,
    BOS_JF_STATE_SWEEP_BEAM,
    BOS_JF_STATE_SHIFT_PILLARS,
    BOS_JF_STATE_CARD_BROKEN,
    BOS_JF_STATE_UNUSED,
    BOS_JF_STATE_DEFEATED,
    BOS_JF_STATE_EVENT_IDLE,
    BOS_JF_STATE_GIMMICK
};

enum BosJfPillarPhase {
    BOS_JF_PILLAR_PHASE_START,
    BOS_JF_PILLAR_PHASE_STAIRS,
    BOS_JF_PILLAR_PHASE_GIMMICK,
    BOS_JF_PILLAR_PHASE_FLAT
};

typedef struct JfWork {
    BtlObj body;
    BtlObj sub;
    s32 subX;
    s32 subY;
    s32 subZ;
    s32 bodyX;
    s32 bodyY;
    s32 bodyZ;
    u32 state;
    u32 attackState;
    u16 hitCount;
    s16 hurtTimer;
    s16 stateStep;
    s16 stepTimer;
    s16 bgFrame;
    s16 bgFrameTimer;
    s16 flags;
    s16 pillarPhase;
    s16 gimmickTimer;
    TaskPool tasks;
    u16 unk_268;
    u16 unk_26A;
} JfWork;

typedef struct JfMapWork {
    s16 paletteTimer;
    s16 paletteFrame;
} JfMapWork;

typedef struct DsdMapWork {
    u32 unk_00;
} DsdMapWork;

typedef struct JfLampWork {
    JfWork* jf;
    ObjTiles* tiles;
    void* gfx;
    ObjTiles* tiles2;
    void* gfx2;
    ObjPalette* palette;
    ObjPalette* palette2;
    s16 tiles2Frame;
    s16 tiles2Timer;
    s16 voiceInterval;
    s16 voiceTimer;
    u8 unk_24;
    s32 vx;
    u8 unk_2C[0x1];
    u8 onFlatGround;
    s16 moveSteps;
    u8 unk_30[0x2];
    u8 state;
    s16 stateTimer;
    s32 targetX;
    u8 unk_3C[0x6];
    u16 angle;
    TaskPool tasks;
} JfLampWork;

typedef struct JfRockWork {
    JfWork* jf;
    ObjTiles* tiles;
    ObjPalette* palette;
    void* gfx;
    AnimState anim;
    s16 paletteFrame;
    s16 paletteTimer;
    BtlObj body;
    s32 targetX;
    s32 targetY;
    s32 targetZ;
    s32 vx;
    s32 vy;
    s32 vz;
    s32 accelZ;
    s16 animIndex;
    u8 visible;
    s16 riseSteps;
    s16 throwTimer;
    u8 state;
    ObjTiles* tiles2;
    ObjPalette* palette2;
    void* gfx2;
    s32 x2;
    s32 y2;
    s32 z2;
    u8 visible2;
    s16 gfx2Index;
    TaskPool tasks;
    u8 shadowVisible;
} JfRockWork;

typedef struct JfMajinWork {
    JfWork* jf;
    void* tiles;
    void* palette;
    void* palette2;
    void* gfx;
    AnimState anim;
    u8 spriteVisible;
    u32 unk_30;
    u32 unk_34;
    u8 unk_38[0x4];
    s16 idleStep;
    u8 unk_3E[0x2];
    s16 y;
    u8 unk_42[0x2];
    s16 moveSteps;
    s16 stepTimer;
    u8 step;
    u8 beamAngle;
    s16 beamLength;
    u32 beamScale;
    u32 x;
    u32 y2;
    u32 z;
    s16 baseFrame;
    s16 leftLevel;
    u16 middleLevel;
    u16 rightLevel;
    u16 leftTarget;
    u16 middleTarget;
    u16 rightTarget;
    s8 extraClipRows;
    TaskPool tasks;
    Task* task;
} JfMajinWork;

typedef struct JfBorderlineWork {
    JfWork* jf;
    ObjTiles* tiles;
    ObjPalette* palette;
    void* gfx;
    void* gfx2;
    void* gfx3;
    void* gfx4;
    AnimState anim;
    AnimState anim2;
    AnimState anim3;
    AnimState anim4;
    void* gfx5;
    AnimState anim5;
    s32 x;
    s32 y;
    u32 z;
    s32 offsetX;
    s32 offsetY;
    u32 offsetZ;
    u16 unk_0B0;
    u16 unk_0B2;
    u8 unk_0B4;
    u8 wide;
} JfBorderlineWork;

STATIC_ASSERT(sizeof(JfWork) == 0x26C, JfWorkSize);

extern const EmyKind gBosDsdEmyKind;
extern const s16 gBosDsdCircleOffsetsX[9];
extern const s16 gBosDsdCircleOffsetsY[10];
extern const s16 gBosDsdFrameDurations[47];
extern const s8 gBosDsdIdleBob[10];

extern const s8 gBosDsdCirclePaletteDurations[10];
extern const EmyKind gBosJfEmyKind;

extern const s16 gBosDsdItaDipSteps[6];
extern const s16 gBosJfMajinFrameDurations[49];
extern const s8 gBosJfMajinIdleOffsets[6];
extern const u16 gBosJfPillarPatterns[16][3];

void BosJfBorderlineUpdateLayout(JfBorderlineWork* work);
s32 __divsi3(s32 a, s32 b);
void BosJfMajinCopyBgMap(u8 frame, JfMajinWork* work);
void BosJfMajinUpdateBgClip(u8 frame, JfMajinWork* work);
void BosJfMajinSetBgFrame(u8 frame, u16 tileCount, JfMajinWork* work);

u8 task_bos_jf_borderline_1(JfBorderlineWork* work);
void task_bos_jf_borderline_3(JfBorderlineWork* work);

u8 task_bos_dsd_rock_1(DsdRockWork* work);
void task_bos_dsd_rock_3();
void task_bos_dsd_circle_0(DsdCircleWork* work, void* arg);
void task_bos_dsd_circle_2(DsdCircleWork* work);
void task_bos_dsd_circle_3();
void task_bos_dsd_energy2_3();
void BosDsdMainUpdateDrift(DsdMainWork* work);
void BosDsdMainUpdateIdleFrames(DsdMainWork* work);
void BosDsdMainResetPose(DsdMainWork* work);
void BosDsdMainBeginTransition(DsdMainWork* work, s32 x, s32 y, s32 z);
void task_bos_dsd_main_3(DsdMainWork* work);
void task_bos_dsd_energy1_0(DsdEnergy1Work* work, void* arg);
void task_bos_dsd_energy2_0(DsdEnergy2Work* work, void* arg);
s32 BosJfUpdateShake();
void BosJfDrawPillars();
void BosJfStartShake(s16 duration);
void task_bos_jf_map_0(JfMapWork* work, JfMapArg* arg);
u8 task_bos_jf_map_1(JfMapWork* work);
u8 BosJfGetGroundZ(s32* px, s32* py, s32* pz, s32* out);
void task_bos_dsd_energy1_2(DsdEnergy1Work* work);
void task_bos_dsd_energy2_2(DsdEnergy2Work* work);
void task_bos_dsd_map_0();
void task_bos_dsd_ita_0(DsdItaWork* work, void* arg);
void task_bos_dsd_rock_2(DsdRockWork* work);
void task_bos_dsd_ita_3(DsdItaWork* work);
void task_bos_jf_2(JfWork* work);
void task_bos_jf_3(JfWork* work);
u8 task_bos_dsd_map_1();
void task_bos_dsd_2(DsdWork* work);
void task_bos_dsd_3(DsdWork* work);
void BosDsdSetBgMap(u8 index);
void BosDsdSetBgFrame(u8 index, u16 tileCount);
void BosDsdItaMoveToward(s32* value, s32 target);

void BosDsdMainUpdateState10(DsdMainWork* work);
void BosDsdMainUpdateEventIdle(DsdMainWork* work);
void task_bos_dsd_energy1_3();
void task_bos_jf_lamp_3(JfLampWork* work);
void task_bos_jf_majin_3(JfMajinWork* work);
s32 BosJfGetActorPillar();
void task_bos_jf_rock_0(JfRockWork* work, JfWork* arg);
void task_bos_jf_rock_3(JfRockWork* work);
void BosDsdMainEndTransition(DsdMainWork* work);
void BosDsdMainUpdateIdle(DsdMainWork* work);
void BosDsdItaUpdateLifetime(DsdItaWork* work);
u8 BosJfStepPillarLevel(u16* level, s16 target, u8 actorPillar, u8 pillar);
s32 BosJfMajinGetActorPillarDistance(JfMajinWork* work);
void BosDsdMainLoopFrames(DsdMainWork* work);
void BosDsdMainLoopMapFrames(DsdMainWork* work);
void BosDsdEnergy1UpdateArc(DsdEnergy1Work* work);
void BosDsdMainUpdateBreak(DsdMainWork* work);
u8 BosJfRockTestPillars(s32 x, s32 y, s32 z);
s32 BosJfLampChooseTargetX(JfLampWork* work);
void BosDsdEnergy1UpdateHoming(DsdEnergy1Work* work);
void BosJfMajinUpdateEventIdle(JfMajinWork* work);
void BosJfMajinUpdateGimmick(JfMajinWork* work);
void BosJfMajinChooseAttack(JfMajinWork* work);
void BosJfMajinUpdateIdle(JfMajinWork* work);
void BosJfMajinUpdateState8(JfMajinWork* work);
void BosJfMajinUpdateBreak(JfMajinWork* work);
void BosJfMajinUpdateSwitchSide(JfMajinWork* work);
void BosJfMajinUpdateRockAttack(JfMajinWork* work);
void BosJfMajinUpdateSlam(JfMajinWork* work);
void BosJfMajinUpdateBeam(JfMajinWork* work);
void BosJfMajinUpdateSweepBeam(JfMajinWork* work);
void BosJfMajinUpdateDefeat(JfMajinWork* work);
void BosJfMajinUpdatePillars(JfMajinWork* work);
u8 task_bos_jf_majin_1(JfMajinWork* work);
u8 task_bos_dsd_energy2_1(DsdEnergy2Work* work);
void BosDsdMainUpdateEnergy2Attack(DsdMainWork* work);
void BosDsdMainUpdateReturn(DsdMainWork* work);
void BosDsdMainUpdateAttackStart(DsdMainWork* work);
void BosDsdMainUpdateApproach(DsdMainWork* work);
void BosDsdMainUpdateShockwave(DsdMainWork* work);
void BosDsdMainUpdateEnergy1Attack(DsdMainWork* work);
void BosDsdMainUpdateDefeat(DsdMainWork* work);
void BosDsdMainUpdateCircleAttack(DsdMainWork* work);
void BosDsdItaUpdateRider(DsdItaWork* work);
void task_bos_jf_majin_2(JfMajinWork* work);
void task_bos_jf_rock_2(JfRockWork* work);
void task_bos_dsd_ita_2(DsdItaWork* work);
u8 task_bos_dsd_energy1_1(DsdEnergy1Work* work);
u8 task_bos_dsd_main_1(DsdMainWork* work);
void task_bos_dsd_main_2(DsdMainWork* work);
u8 task_bos_dsd_ita_1(DsdItaWork* work);
void task_bos_dsd_rock_0(DsdRockWork* work, DsdWork* arg);
void task_bos_jf_lamp_0(JfLampWork* work, JfWork* arg);
u8 task_bos_dsd_circle_1(DsdCircleWork* work);
void task_bos_dsd_0(DsdWork* work, void* arg);
void task_bos_jf_borderline_0(JfBorderlineWork* work, JfWork* arg);
void task_bos_jf_lamp_2(JfLampWork* work);
void task_bos_dsd_main_0(DsdMainWork* work, DsdWork* arg);
u8 task_bos_dsd_1(DsdWork* work);

void BosDsdMainChooseAttack(DsdMainWork* work);

extern s16 gBosJfActorX;
extern JfMapArg gJfMapArg;
extern s16 gBosJfActorY;
extern s16 gBosJfActorZ;
extern s16 gBosJfRightPillarLevel;
extern s16 gBosJfLeftPillarLevel;
extern s16 gBosJfMiddlePillarLevel;

#endif /* GUARD_BOS2_H */
