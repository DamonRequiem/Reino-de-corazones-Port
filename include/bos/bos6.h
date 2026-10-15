#ifndef GUARD_BOS6_H
#define GUARD_BOS6_H

#include "battle_actor_types.h"
#include "battle_bg_types.h"
#include "evt_types.h"
#include "types.h"
#include "taskpool.h"
#include "anim.h"
#include "obj.h"

typedef struct PcAnimStep {
    u16 op;
    u8 unk_02[0x2];
    s16 body2X;
    s16 body2Y;
    s16 body2Z;
    u8 unk_0A[0x2];
    u16 anchorCmd;
    s16 hitX;
    s16 hitY;
    s16 hitZ;
    s16 hitHalfX;
    s16 hitHalfY;
    s16 hitHalfZ;
    u8 unk_1A[0x2];
    u16 event;
    s16 gfxSet;
    s16 cmdList;
    s16 duration;
} PcAnimStep;

extern const PcAnimStep gBosPcIdleAnim[];
extern const PcAnimStep gBosPcReactionShortAnim[];
extern const PcAnimStep gBosPcReactionMidAnim[];
extern const PcAnimStep gBosPcReactionLongAnim[];
extern const PcAnimStep gBosPcUnusedSlamAnim[];
extern const PcAnimStep gBosPcSlamBackAnim[];
extern const PcAnimStep gBosPcGimmickSlamAnim[];
extern const PcAnimStep gBosPcBeamAnim[];
extern const PcAnimStep gBosPcTackleAnim[];
extern const PcAnimStep gBosPcSlamMidAnim[];
extern const PcAnimStep gBosPcSlamFrontAnim[];
extern const PcAnimStep gBosPcDefeatAnim[];
extern const PcAnimStep gBosPcEventPoseAnim[];
extern const PcAnimStep gBosPcEventAnim[];

enum PcSpriteCmdFlag {
    PC_SPRITE_CMD_STANDALONE = 0x1,
    PC_SPRITE_CMD_END = 0x80
};

typedef struct PcSpriteCmd {
    u8 flags;
    u8 gfxIndex;
    s16 layer;
    s16 x;
    s16 y;
    s16 height;
    u16 unk_0A;
} PcSpriteCmd;

extern const PcSpriteCmd gBosPcIdleFrame0[];
extern const PcSpriteCmd gBosPcIdleFrame1[];
extern const PcSpriteCmd gBosPcIdleFrame2[];
extern const PcSpriteCmd gBosPcIdleFrame3[];
extern const PcSpriteCmd gBosPcIdleFrame4[];
extern const PcSpriteCmd gBosPcIdleFrame5[];
extern const PcSpriteCmd gBosPcIdleFrame6[];
extern const PcSpriteCmd gBosPcIdleFrame7[];
extern const PcSpriteCmd gBosPcIdleFrame8[];
extern const PcSpriteCmd gBosPcIdleFrame9[];
extern const PcSpriteCmd gBosPcIdleFrame10[];
extern const PcSpriteCmd gBosPcIdleFrame11[];
extern const PcSpriteCmd gBosPcIdleFrame12[];
extern const PcSpriteCmd gBosPcIdleFrame13[];
extern const PcSpriteCmd gBosPcIdleFrame14[];
extern const PcSpriteCmd gBosPcReactionFrame0[];
extern const PcSpriteCmd gBosPcReactionFrame1[];
extern const PcSpriteCmd gBosPcReactionFrame2[];
extern const PcSpriteCmd gBosPcReactionFrame3[];
extern const PcSpriteCmd gBosPcReactionFrame4[];
extern const PcSpriteCmd gBosPcReactionFrame5[];
extern const PcSpriteCmd gBosPcReactionFrame6[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame14[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame1[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame2[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame3[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame4[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame5[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame6[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame7[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame8[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame9[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame10[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame11[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame12[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame13[];
extern const PcSpriteCmd gBosPcUnusedSlamFrame0[];
extern const PcSpriteCmd gBosPcSlamBackFrame0[];
extern const PcSpriteCmd gBosPcSlamBackFrame1[];
extern const PcSpriteCmd gBosPcSlamBackFrame2[];
extern const PcSpriteCmd gBosPcSlamBackFrame3[];
extern const PcSpriteCmd gBosPcSlamBackFrame4[];
extern const PcSpriteCmd gBosPcSlamBackFrame5[];
extern const PcSpriteCmd gBosPcSlamBackFrame6[];
extern const PcSpriteCmd gBosPcGimmickSlamFrame6[];
extern const PcSpriteCmd gBosPcGimmickSlamFrame1[];
extern const PcSpriteCmd gBosPcGimmickSlamFrame2[];
extern const PcSpriteCmd gBosPcGimmickSlamFrame3[];
extern const PcSpriteCmd gBosPcGimmickSlamFrame4[];
extern const PcSpriteCmd gBosPcGimmickSlamFrame5[];
extern const PcSpriteCmd gBosPcGimmickSlamFrame0[];
extern const PcSpriteCmd gBosPcBeamFrame0[];
extern const PcSpriteCmd gBosPcBeamFrame1[];
extern const PcSpriteCmd gBosPcBeamFrame2[];
extern const PcSpriteCmd gBosPcBeamFrame3[];
extern const PcSpriteCmd gBosPcBeamFrame4[];
extern const PcSpriteCmd gBosPcBeamFrame5[];
extern const PcSpriteCmd gBosPcBeamFrame6[];
extern const PcSpriteCmd gBosPcBeamFrame7[];
extern const PcSpriteCmd gBosPcBeamFrame8[];
extern const PcSpriteCmd gBosPcBeamFrame9[];
extern const PcSpriteCmd gBosPcBeamFrame10[];
extern const PcSpriteCmd gBosPcBeamFrame11[];
extern const PcSpriteCmd gBosPcTackleFrame0[];
extern const PcSpriteCmd gBosPcTackleFrame1[];
extern const PcSpriteCmd gBosPcTackleFrame2[];
extern const PcSpriteCmd gBosPcTackleFrame3[];
extern const PcSpriteCmd gBosPcTackleFrame4[];
extern const PcSpriteCmd gBosPcTackleFrame5[];
extern const PcSpriteCmd gBosPcTackleFrame6[];
extern const PcSpriteCmd gBosPcTackleFrame7[];
extern const PcSpriteCmd gBosPcTackleFrame8[];
extern const PcSpriteCmd gBosPcTackleFrame9[];
extern const PcSpriteCmd gBosPcTackleFrame10[];
extern const PcSpriteCmd gBosPcTackleFrame11[];
extern const PcSpriteCmd gBosPcSlamMidFrame0[];
extern const PcSpriteCmd gBosPcSlamMidFrame1[];
extern const PcSpriteCmd gBosPcSlamMidFrame2[];
extern const PcSpriteCmd gBosPcSlamMidFrame3[];
extern const PcSpriteCmd gBosPcSlamMidFrame4[];
extern const PcSpriteCmd gBosPcSlamMidFrame5[];
extern const PcSpriteCmd gBosPcSlamMidFrame6[];
extern const PcSpriteCmd gBosPcSlamFrontFrame0[];
extern const PcSpriteCmd gBosPcSlamFrontFrame1[];
extern const PcSpriteCmd gBosPcSlamFrontFrame2[];
extern const PcSpriteCmd gBosPcSlamFrontFrame3[];
extern const PcSpriteCmd gBosPcSlamFrontFrame4[];
extern const PcSpriteCmd gBosPcSlamFrontFrame5[];
extern const PcSpriteCmd gBosPcSlamFrontFrame6[];
extern const PcSpriteCmd gBosPcDefeatFrame0[];
extern const PcSpriteCmd gBosPcDefeatFrame1[];
extern const PcSpriteCmd gBosPcDefeatFrame2[];
extern const PcSpriteCmd gBosPcDefeatFrame3[];
extern const PcSpriteCmd gBosPcDefeatFrame4[];
extern const PcSpriteCmd gBosPcDefeatFrame5[];
extern const PcSpriteCmd gBosPcDefeatFrame6[];

typedef struct PcGfxSet {
    void* tiles;
    u16 tilesSize;
    void* map;
    u16 mapSize;
} PcGfxSet;

typedef struct PcShot {
    s32 targetX;
    s32 targetY;
    u16 steps;
    s32 targetScale;
} PcShot;

typedef struct PcShared {
    s16 hpRatio;
    u8 fltShrunk;
    u8 unk_03;
    u8 forceRipple;
    u8 inEvent;
    s32 fltStopTimer;
    s32 gimmickTimer;
} PcShared;

typedef struct PcOam {
    u16 count;
    u16 attr[0x95];
} PcOam;

typedef struct PcWork {
    s16 state;
    s16 step;
    s16 cardDelay;
    s16 hurtTimer;
    s16 reactionAnim;
    s16 flash;
    s16 prevFlash;
    s32 hitAttack;
    s32 hitFlags;
    u8 defeated;
    s32 actorMaxX;
    s32 x;
    s32 y;
    s32 z;
    const PcAnimStep* animSteps;
    s16 animIndex;
    s16 animFrame;
    s16 animTimer;
    s16 bgFrame;
    u8 paletteCycle;
    s16 paletteIndex;
    s16 paletteTimer;
    void* tiles;
    void* tiles2[2];
    void* palette;
    void* palette2;
    BtlObj body;
    BtlObj body2;
    Collider collider;
    Task* fld;
    Task* flt[4];
    Task* acd;
    PcShared shared;
    u8 unk_2F8[0x4];
    PcOam oam[24];
} PcWork;

u16 BosPcGetSpritePriority(PcWork* work, s32 y);
u16 BosPcGetSpriteDepth(PcWork* work, s32 y, s32 order);

typedef struct PcAcdWork {
    u32 unk_000;
    ObjTiles* tiles;
    ObjPalette* palette;
    s32 x;
    s32 y;
    s32 z;
    u8 acdOff;
    PcShared* shared;
    AnimState anim;
} PcAcdWork;

typedef struct PcFltWork {
    u16 playerOnPlatform;
    s16 timer;
    u8 index;
    u8 state;
    u8 unk_006;
    u8 unk_007;
    u16 orbitAngle;
    u32 centerX;
    u32 centerY;
    u16 radiusX;
    u16 radiusY;
    s16 sinkTimer;
    u32 baseX;
    u32 baseY;
    u32 baseZ;
    s32 x;
    s32 y;
    s32 z;
    ObjTiles* tiles;
    ObjPalette* palette;
    PcShared* shared;
    Collider collider;
    AnimState anim;
} PcFltWork;

typedef struct PcFldWork {
    u8 paletteCycle;
    s16 paletteIndex;
    s16 paletteTimer;
    ObjTiles* tiles;
    ObjPalette* palette;
    Collider collider;
} PcFldWork;

typedef struct LstSub {
    u8 defeated;
    u8 unk_001;
    u8 restartAnim;
    s16 state;
    s16 timer;
    s16 hurtTimer;
    s16 animId;
    s16 curAnimId;
    ObjTiles* tiles;
    u8 unk_014[0x4];
    BtlObj body;
    AnimState anim;
} LstSub;

typedef struct BosLstWork {
    u8 inEvent;
    u8 eventStep;
    u8 hidden;
    s16 unk_004;
    s16 subsDefeated;
    s16 state;
    s16 step;
    s16 moveMode;
    s16 attackKind;
    s16 bodyCycle;
    s16 facing;
    u16 flash;
    u16 prevFlash;
    s32 hpRatio;
    u8 turned;
    s16 animId;
    u16 animFlags;
    u16 animFacing;
    u16 bgFrame;
    s16 hittableTimer;
    ObjTiles* tiles;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 offsetX;
    s32 offsetY;
    s32 offsetZ;
    s32 actorX;
    s32 actorY;
    s32 actorZ;
    s16 timer;
    s16 bobFrame;
    u16 frameCount;
    s16 platformTimer;
    u16 cardRequests;
    s16 breakCount;
    u16 falCount;
    u16 hurtTimer;
    u16 unk_078;
    s16 defeatTimer;
    s32 cardDelay;
    s16 groundStep;
    s16 groundCount;
    s32 groundVz;
    s32 groundTargetX;
    s16 kamaStep;
    s16 kamaCount;
    s32 kamaStartX;
    s32 kamaStartY;
    s32 kamaStartZ;
    s32 kamaTargetX;
    s32 kamaTargetY;
    s32 kamaTargetZ;
    s16 dashStep;
    s16 dashCount;
    s16 unk_0AC;
    s32 dashSpeed;
    s32 dashVz;
    s32 ctrCount;
    s16 bitStep;
    s16 bitRound;
    s16 bitAttackStarted;
    s32 lstTaskCount;
    u8 unk_0C8[0xC];
    u8 playerOnPlatform;
    s16 platformStep;
    u8 unk_0D8[0x4];
    s32 platformSpeed;
    ObjPalette* palette;
    BtlObj body;
    LstSub sub[2];
    Collider collider;
    Collider collider2;
    Collider colliders[8];
    Task* task;
    Task* lstTasks[0x20];
    TaskPool tasks;
    u16 bgMap[0x400];
} BosLstWork;

void BosPcDraw(PcWork* work);
void BosPcLoadPaletteCycle(PcWork* work);

s32 BosPcFldGetShake();
void BosPcFldResetPaletteCycle(PcFldWork* work);
void BosPcFldStopPaletteCycle(PcFldWork* work);
void BosPcAcdSetOff(Task* task, u8 off);
void BosLstSetMode(BosLstWork* work, u16 moveMode, u16 attackKind);
void BosLstRequestCardUse(BosLstWork* work);
void task_bos_pc_2(PcWork* work);
void task_bos_pc_acd_3(PcAcdWork* work);
void task_bos_pc_flt_3(PcFltWork* work);
void task_bos_pc_fld_3(PcFldWork* work);
void BosPcFldLoadPaletteCycle(PcFldWork* work);
s32 BosPcFltSquare(s32 x);
s32 BosPcFltSquare2(s32 x);
s32 BosPcAcdSquare(s32 x);
s32 BosPcAcdSquare2(s32 x);
s32 BosLstSquare(s32 x);
s32 BosLstSquare2(s32 x);

void BosPcFldSetPaletteCycle(Task* task, u8 on);

void BosPcSetAnim(PcWork* work, s32 anim);
void BosPcUpdateAnim(PcWork* work);
u8 BosPcFltIsSubmerged(Task* task);
u8 BosPcFltIsPlayerOn(Task* task);
void BosPcFltGetPosition(Task* task, s32* x, s32* y, s32* z);

void BosLstDestroyTasks(BosLstWork* work);
s16 BosLstFindActiveSub(BosLstWork* work);
u8 BosLstAnyBitAlive(BosLstWork* work);
void BosLstHoverBits(BosLstWork* work);
void BosLstReturnBits(BosLstWork* work);

void BosPcFldResetShake();
void BosPcFldStartShake(s16 pattern);
void BosPcFldUpdateShake();
void BosPcFldUpdatePaletteCycle(PcFldWork* work);

void BosPcFltUpdateSinkEnd(PcFltWork* work);
void BosPcFltUpdateRise(PcFltWork* work);
void BosPcFltUpdateState6(PcFltWork* work);

void BosPcFltUpdateSink(PcFltWork* work);
void BosPcFltUpdateSubmerged(PcFltWork* work);
void BosPcFltUpdateState5(PcFltWork* work);
void BosPcFltUpdateState7(PcFltWork* work);
void BosPcFltUpdateGimmick(PcFltWork* work);
void BosPcFltSyncCollider(PcFltWork* work);

typedef struct PcFltFrameDef {
    s16 drawY;
    s16 z;
    u16 radius;
    u16 nextAnim;
} PcFltFrameDef;

void BosPcStopPaletteCycle(PcWork* work);
void BosLstSetAnim(BosLstWork* work, u16 animId, u16 flags, u8 change);

void BosPcFldEnableObject(Task* task, u8 on);
u8 BosLstUpdateHurt(BosLstWork* work);
u8 BosLstUpdateState5(BosLstWork* work);
void BosLstInterruptBits(BosLstWork* work);

u8 BosPcIsAnimDone(PcWork* work);

s32 BosLstApproachValue(s32 value, s32 target, s32 speed, s32 minSpeed, s32 maxSpeed);
u8 BosPcUpdateReaction(PcWork* work, Task* task);
u8 BosLstAnyBitFiring(BosLstWork* work, s32 idx);

u8 BosPcUpdateBreak(PcWork* work, Task* task);
void BosLstTickCardDelay(BosLstWork* work);
void BosLstUpdateBob(BosLstWork* work);
void BosLstMoveMode0(BosLstWork* work);

s32 BosLstGetPlatformY(BosLstWork* work);

u8 BosLstFireBits(BosLstWork* work, s32 idx, s16 shots);
u8 task_bos_pc_flt_1(PcFltWork* work);
void BosPcFltUpdateMotion(PcFltWork* work);

void BosLstMoveMode2(BosLstWork* work);
void BosLstSetFacing(BosLstWork* work, s16 facing);

void task_bos_pc_fld_2(PcFldWork* work);

const PcAnimStep* BosPcGetAnimStep(PcWork* work);
void BosPcUpdatePaletteCycle(PcWork* work);
u8 BosPcUpdateAttack(PcWork* work, Task* task);
u8 task_bos_pc_1(PcWork* work, Task* task);
void task_bos_pc_0(PcWork* work, TaskPool* pool);
void BosPcStartPaletteCycle(PcWork* work);
void CreateBosPcFltTask(PcWork* work, u16 angle, s32 x, s32 y, s32 z, u8 index);
void CreateBosPcAcdTask(PcWork* work, TaskPool* pool);

void task_bos_lst_0(BosLstWork* work, TaskPool* pool);
u8 task_bos_lst_1(BosLstWork* work);

typedef struct LstAnimDef {
    void* bgMap;
    u16 spriteX;
    u16 spriteY;
    u8 spriteFlip;
    u8 unk_09[0x3];
    u16 subSpriteX;
    u16 subSpriteY;
    u8 subSpriteFlip;
    s16 subX;
    s16 subY;
    s16 subZ;
    u16 sub2SpriteX;
    u16 sub2SpriteY;
    u8 sub2SpriteFlip;
    s16 sub2X;
    s16 sub2Y;
    s16 sub2Z;
    s16 bgX;
    s16 bgY;
    s16 bgZ;
} LstAnimDef;

void task_bos_lst_2(BosLstWork* work);
u8 BosLstUpdateDefeat(BosLstWork* work);

extern EventState* gEventState;
void task_bos_pc_acd_2(PcAcdWork* work);

const PcSpriteCmd* BosPcGetSpriteCmds(PcWork* work);

void BosPcPlaceBodies(PcWork* work);
void task_bos_pc_acd_0(PcAcdWork* work, PcShared* arg);
u8 task_bos_pc_acd_1(PcAcdWork* work);
void task_bos_lst_3(BosLstWork* work);

typedef struct PcFltInit {
    u8 index;
    u16 angle;
    u32 x;
    u32 y;
    u32 z;
    PcShared* shared;
} PcFltInit;

void task_bos_pc_flt_0(PcFltWork* work, PcFltInit* arg);
void task_bos_pc_flt_2(PcFltWork* work);

void task_bos_pc_fld_0(PcFldWork* work, PcBattleBackgroundDef* arg);

u8 task_bos_pc_fld_1(PcFldWork* work);

u8 BosLstSetSubAnim(BosLstWork* work, u16 animId);
u8 BosLstUpdateMove(BosLstWork* work);
void BosLstMoveMode1(BosLstWork* work);
void BosLstMoveDash(BosLstWork* work);
void BosLstMoveBits(BosLstWork* work);
void BosLstMovePlatform(BosLstWork* work);

u8 BosLstUpdateEvent(BosLstWork* work);
u8 BosLstUpdateAttack(BosLstWork* work);
u8 BosLstAttackGround(BosLstWork* work);
u8 BosLstAttackKama(BosLstWork* work);
u8 BosLstAttackDash(BosLstWork* work);
u8 BosLstAttackCtr(BosLstWork* work);
u8 BosLstAttackBits(BosLstWork* work);
u8 BosLstAttackHanabira(BosLstWork* work);

u8 BosPcUpdateIdle(PcWork* work, Task* task);
void BosPcFltUpdateFloat(PcFltWork* work);

u8 BosLstSpawnFal(BosLstWork* work, s32 kind);

u8 BosPcUpdateDefeat(PcWork* work, Task* task);

u8 BosPcUpdateHurt(PcWork* work, Task* task);

typedef struct LstSpawn3 {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x6];
    s16 kind;
    u8 unk_14[0xC];
} LstSpawn3;

void BosLstUpdateSub(BosLstWork* work, LstSub* sub);

u8 BosLstUpdateBreak(BosLstWork* work);

#endif /* GUARD_BOS6_H */
