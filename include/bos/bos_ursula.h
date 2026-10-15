#ifndef GUARD_BOS_URSULA_H
#define GUARD_BOS_URSULA_H

#include "battle_actor_types.h"
#include "battle_bg_types.h"
#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "bos4_api.h"
#include "obj.h"

enum BosUrsulaHpPhase {
    BOS_URSULA_HP_PHASE_HIGH,
    BOS_URSULA_HP_PHASE_MID,
    BOS_URSULA_HP_PHASE_LOW
};

typedef struct UrsulaWork {
    u32 state;
    s16 timer;
    TaskPool tasks;
    Task* tako;
    Task* tako2;
    BtlObj obj;
    const u16** mapBlocks;
    s32 bobZ;
    s32 bobTarget;
    u16 bobTimer;
    u16 gimmickTimer;
    u8 unk_144[0x4];
    u32 gimmickCameraX;
    u32 gimmickViewY;
    u32 sinkZ;
    u32 gimmickCameraY;
    u16 sinkSteps;
    u16 riseSteps;
    u16 unk_15C;
    u16 gimmickDelay;
    u8 takoRecoverPending;
} UrsulaWork;

void BosUrsulaStartAttack(s32 attack);
u8 BosUrsulaIsAttacking();
u8 BosUrsulaIsCharging();
u16 BosUrsulaGetCardInterval();
void task_bos_ursula_3(UrsulaWork* work);

typedef struct UrsulaTakoWork {
    void* tiles;
    void* palette;
    void* palette2;
    AnimState anim;
    u16 animBase;
    BtlObj obj;
    u32 state;
    u16 timer;
    u8 isLeft;
    Collider collider;
    Collider collider2;
    s32 collider2OffsetX;
    s32 offsetX;
    s32 offsetZ;
} UrsulaTakoWork;

void BosUrsulaUpdateMapBlocks(UrsulaWork* work);
void task_bos_ursula_2(UrsulaWork* work);
u8 BosUrsulaIsGuarded(UrsulaWork* work);
u8 BosUrsulaMoveForward(UrsulaWork* work);
void BosUrsulaUpdateBob(UrsulaWork* work);
s32 BosUrsulaChooseAttackPhase0(UrsulaWork* work);
s32 BosUrsulaChooseAttackPhase1(UrsulaWork* work);
s32 BosUrsulaChooseAttack(UrsulaWork* work);
void BosUrsulaRecoverPendingTakos(UrsulaWork* work);
void BosUrsulaUpdateTakoRecovery(UrsulaWork* work);
void task_bos_ursula_tako_3(UrsulaTakoWork* work);
u8 BosUrsulaTakoIsBusy(UrsulaTakoWork* work);
void BosUrsulaTakoEndDown(UrsulaTakoWork* work);
u8 BosUrsulaTakoIsStoodOn(UrsulaTakoWork* work);

typedef struct UrsulaMapanimeWork {
    BosMapanimeState anim;
    u32 attack;
    TaskPool tasks;
    Task* task;
    u8 attackSpawned;
} UrsulaMapanimeWork;

typedef struct UrsulaMapWork {
    s32 viewYMax;
    s32 viewYMaxTarget;
    u16 viewYMaxSteps;
} UrsulaMapWork;

typedef struct UrsulaBorderWork {
    ObjTiles* tiles;
    ObjPalette* palette;
} UrsulaBorderWork;

void task_bos_ursula_map_0(UrsulaMapWork* work, BattleBackgroundDef* arg);
u8 task_bos_ursula_map_1(UrsulaMapWork* work);

typedef struct UrsulaBacktakoWork {
    ObjTiles* tiles;
    ObjPalette* palette;
    AnimState anim;
    u16 animBase;
    u8 isLeft;
    u32 offsetX;
    u32 offsetZ;
    u32 x;
    u32 y;
    u32 z;
    u32 x2;
    u32 y2;
    u32 z2;
} UrsulaBacktakoWork;

u8 BosUrsulaIsFacingLeft();
u8 BosUrsulaIsGimmickActive();
u8 BosUrsulaObjectsGone();
u8 BosUrsulaIsGimmickStarting();
u8 BosUrsulaIsGimmickInProgress();
u32 BosUrsulaGetHpPhase();
u8 BosUrsulaIsDefeated();
s32 BosUrsulaGetTakoPlatformRadius(u8 isLeft);
void task_bos_ursula_border_0(UrsulaBorderWork* work);
void task_bos_ursula_border_3(UrsulaBorderWork* work);
u8 task_bos_ursula_backtako_1(UrsulaBacktakoWork* work);
void task_bos_ursula_backtako_3(UrsulaBacktakoWork* work);
void task_bos_ursula_map_3();
s32 task_bos_ursula_border_1();
void task_bos_ursula_mapanime_0(UrsulaMapanimeWork* work);
u8 task_bos_ursula_mapanime_1(UrsulaMapanimeWork* work);
void task_bos_ursula_mapanime_2(UrsulaMapanimeWork* work);
void task_bos_ursula_mapanime_3(UrsulaMapanimeWork* work);
void task_bos_ursula_tako_2(UrsulaTakoWork* work);
void task_bos_ursula_tako_0(UrsulaTakoWork* work, u8* arg);
u8 task_bos_ursula_tako_1(UrsulaTakoWork* work);
void task_bos_ursula_0(UrsulaWork* work);
void task_bos_ursula_backtako_0(UrsulaBacktakoWork* work, u8* arg);
void task_bos_ursula_border_2(UrsulaBorderWork* work);
void task_bos_ursula_backtako_2(UrsulaBacktakoWork* work);
void BosUrsulaTakoGetPosition(s32* x, s32* y, s32* z, UrsulaTakoWork* work);
void BosUrsulaBacktakoGetPosition(s32* x, s32* y, s32* z, UrsulaBacktakoWork* work);
s32 BosUrsulaChooseAttackPhase2(UrsulaWork* work);
u8 task_bos_ursula_1(UrsulaWork* work);

#endif /* GUARD_BOS_URSULA_H */
