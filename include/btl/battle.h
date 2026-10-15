#ifndef GUARD_BATTLE_H
#define GUARD_BATTLE_H

#include "anim.h"
#include "battle_actor.h"
#include "types.h"
#include "listpool.h"
#include "taskpool.h"
#include "mode.h"
#include "battle_actor_types.h"
struct BtlObj;

enum BgFxFlag {
    BGFX_FLAG_FLIP_X = 0x1,
    BGFX_FLAG_ACTIVE = 0x2,
    BGFX_FLAG_IGNORE_ZOOM = 0x4,
    BGFX_FLAG_SCREEN_DIMMED = 0x8,
    BGFX_FLAG_ABOVE_SPRITES = 0x10,
    BGFX_FLAG_BELOW_SPRITES = 0x20
};

typedef struct BgFx {
    s32 bg;
    void (*update)();
    s16 timer;
    s16 steps;
    s16 unk_0C;
    s16 scaleYSteps;
    s32 x;
    s32 y;
    s32 z;
    s32 scaleX;
    s32 scaleY;
    u8 angle;
    u16 state;
    s32 targetX;
    s32 targetY;
    s32 targetZ;
    u16 flags;
    u16 endSignals;
    u8 priority;
    s32 unk_3C;
    s32 angleFixed;
    struct BtlObj* actor;
    s32 attack;
    s16 releaseFrames;
} BgFx;

typedef struct EnemySpawnRequest {
    TaskDesc* desc;
    s32 x;
    s32 y;
    s32 z;
    u16 flags;
    u16 tileCount;
} EnemySpawnRequest;

typedef struct BtlPrizeSrc {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    u16 kind;
    u16 noTimeout;
    u8 unk_16[0x0A];
} BtlPrizeSrc;

enum BtlPrizeKind {
    BTL_PRIZE_EXP_1400,
    BTL_PRIZE_HP_3,
    BTL_PRIZE_HP_10,
    BTL_PRIZE_EXP_1,
    BTL_PRIZE_EXP_10,
    BTL_PRIZE_EXP_60,
    BTL_PRIZE_EXP_5,
    BTL_PRIZE_EXP_30,
    BTL_PRIZE_EXP_199
};

typedef struct FieldTransitionWork {
    void* tiles;
    void* palette;
    AnimState anim;
    u16 initialized;
    u8 flipped;
} FieldTransitionWork;

typedef struct EnemyBaseStats {
    s16 hp;
    s16 attack;
    s16 exp;
    s16 unk_06;
} EnemyBaseStats;

typedef struct BattleAttackDef {
    s32 power;
    s32 knockbackSpeed;
    s32 knockbackLift;
    s32 hitStop;
    void (*hitEffect)(s32, s32, s32);
    u32 flags;
} BattleAttackDef;

extern s32 gUnk_02039DC0;


void* ColliderGetPool(u32 type);
void HandleSoraCardInput();
void HandleTutorialCardInput();
void SetEnemyKindFlags(BtlObj* obj);
void CreateHeartlessCardTask(void* pool, s16 x, s16 y, s16 z, u16 kind);
void BgFxReset();
void BgFxUpdateBase();
void FieldTransitionInit();
s32 ApplyAttackAt(s32 attack, s32 x, s32 y, s32 z);
void BgFxUpdateFlash();
void BgFxUpdateStop();
void BgFxUpdateAnsemWave();
void BgFxUpdateGravityStrike();
void BgFxUpdateShockwave();
void BgFxUpdateGround();
BtlObj* BgFxGetSyncTarget();
void UpdateEnemyCardUse();
void BgFxUpdateEnemyDeath();
void BgFxUpdateZantetsuken();
void BgFxUpdateFadeOut();
void BgFxUpdateExplosion();
void BgFxUpdateGravity();
void BgFxUpdateFadeInOut();
void BgFxUpdateRagnarokCharge();
void BgFxUpdateBossDeathFlash();
void UseEnemyCard(u16 a);
void BgFxUpdateGas();
void BgFxUpdateRikuLimit();
void BgFxUpdateLaxeneBeam();
void BgFxUpdateAero();
void ColliderCheckPoolPairs(ListPool* poolA, ListPool* poolB);
s64 __ashldi3(s64 v, s32 n);
u8 GetStockMoveCount();

const EnemyBaseStats* GetEnemyBaseStats(u16 i);
s32 ResolveAttackHit(BtlObj* hit, s32 index);

u8 GetRikuSelectedCardValue();
s32 GetRikuSelectedMove();
u8 GetRikuCardsLeft();
u8 GetActiveCardValue();
void RequestBossCardOpen();
void RequestBossCardClose();
extern Mode gModeChkbtl;

u8 TryStartCardAction(BtlObj* obj);
void VsBtlWorkInit();
void VsEndCardPlay();
void VsBattleUpdate();
void AbsorbAttack(BtlObj* target, BtlObj* source, const BattleAttackDef* attack);

void func_080135EC(s32 x, s32 y, s32 z);
void BgFxStartFlashHit(s32 x, s32 y, s32 z);
void BgFxUpdateFlashHit();
void BgFxUpdateBlizzard();
void func_080146A8(s32 x, s32 y, s32 z);
void func_08014654();
void BgFxUpdateUrsulaBeam();
void BgFxUpdateFire();
void BgFxStartAxcelFireWall(s32 x, u8 facingLeft, s32 attack);
void BgFxUpdateBind();
void BgFxUpdateAxcelFireWall();
void BgFxUpdateFireBurst();
void BgFxUpdateDsdEnergy();
void BgFxTornadoLiftBtlObj(BtlObj* source, BtlObj* target, u8 spin, u8 init);
void BgFxUpdateTornado();
void BgFxUpdatePcShot();
void BgFxUpdateRikuLimitFinish();
void BgFxUpdateHanabira();
void BgFxUpdateKama();
void BgFxUpdateTrinityLimitBlast();
void BgFxUpdateRagnarokShot();
void BgFxUpdateThunder();
void BgFxUpdateDumboSplash();
void BgFxUpdateWideThunder();
void BgFxUpdateHoly();
void BgFxUpdateSync();
void BgFxUpdateRikuDarkMode();
void BgFxStartFireHit(s32 x, s32 y, s32 z);
void BgFxStartBlizzardHit(s32 x, s32 y, s32 z);
void BgFxStartEnemyHit(s32 x, s32 y, s32 z);
void BgFxStartRikuHit(s32 x, s32 y, s32 z);
void BgFxStartSoraHit(s32 x, s32 y, s32 z);
void BgFxUpdateFullscreen();
void BgFxUpdateVixenIceFall();
u8 CreateBtlPrizeTasksCapped(BtlPrizeSrc* src, u16 kind, s16 value, s16* remaining, s16* cnt);
void CreateBtlPrizeTasks(BtlPrizeSrc* src, u16 kind, s16 value, s16* remaining);

s32 LevelUpMaxHp();
s32 LevelUpCp();
s32 LevelUpDp();
s32 LevelUpAp();
void AddExp(u16 exp);
void BgFxUpdateTrinityLimit();
s32 ApplyAttackInFront(BtlObj* obj, s16 distance, s32 attack);
void RequestSwitchRikuCardList();
u8 GetRikuStockCount();
u8 IsRikuSelectionEmpty();
u8 GetRikuCardListIndex();
u8 StepHitFlashSolid(BtlObj* obj);

void BgFxReleaseEarly(s16 frames);
void BgFxStartGuard(s32 x, s32 y, s32 z);
void BgFxStartLimit(s32 x, s32 y, s32 z, u8 flip);
void BgFxUpdateFollowActor();
void EndCardPlay();

void func_08012214();
void ColliderClearPoolContacts(ListPool* pool);
u8 BgFxIsBlocked(u8 priority);

u8 ColliderIsColliding(Collider* collider);
s32 ApplyBtlObjHit(BtlObj* obj);
void CreateGimmickCardTask(void* pool, s16 x, s16 y, s16 z, u16 cardId);

typedef struct BtlPrizeArgs {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x14];
} BtlPrizeArgs;

#endif /* GUARD_BATTLE_H */
