#ifndef GUARD_BATTLE_ACTOR_H
#define GUARD_BATTLE_ACTOR_H

#include "battle_actor_types.h"
#include "types.h"

#define STEP_STATE(work) \
    do { \
        (work)->stateTimer++; \
        (work)->steps--; \
    } while (0)

struct EmyKind;
struct AnimDef;

void SetBattleZoom(u16 steps, s32 scale, s32 x, s32 y);
void AnimChangeWithDef(const struct AnimDef* defs, void* anim, u16 index, u16 flags, void* tiles);
void WorldToScreen(s16* outX, s16* outY, s32 px, s32 py, s32 pz);
enum BtlPopKind {
    BTL_POP_GUARD,
    BTL_POP_COUNTER,
    BTL_POP_MISS,
    BTL_POP_OVERWRITE,
    BTL_POP_TIME_BREAK,
    BTL_POP_25_PERCENT_UP,
    BTL_POP_50_PERCENT_UP,
    BTL_POP_25_PERCENT_DOWN,
    BTL_POP_50_PERCENT_DOWN,
    BTL_POP_CARD_BREAK,
    BTL_POP_RECOVER
};

void CreateBtlPopTask(BtlObj* obj, s16 kind);
void MakeOpponentsHittable();
void UpdateBattleState();
enum BattleEdge {
    BATTLE_EDGE_NONE,
    BATTLE_EDGE_LEFT,
    BATTLE_EDGE_RIGHT,
    BATTLE_EDGE_TOP,
    BATTLE_EDGE_BOTTOM
};

u32 ClampBattlePosition(s32* px, s32* py, s32 radiusX, s32 radiusY);
void SetBattleBounds(s32 xMin, s32 xMax, s32 yMin, s32 yMax);
s32 UpdateBtlObjReaction(BtlObj* obj);
void ClearBtlObjActionFlags(BtlObj* obj);
u16 GetBattleSpritePriorityFlags(s32 y);
void BeginBossDefeat(BtlObj* actor);
void EndBossDefeat();
void InitEnemyBtlObj(BtlObj* obj, const struct EmyKind* kind, s32 x, s32 y, s32 z);
void ReleaseEnemyBtlObj(BtlObj* obj);
void DropBossPrizes(BtlObj* obj);
void DropEnemyPrizes(BtlObj* obj);
void TryDropPremireCard(BtlObj* obj);
void RequestEnemyCardUse(BtlObj* obj);
void TryEnemyCardUse(BtlObj* obj);
void SetBtlObjParent(BtlObj* obj, BtlObj* parent);
u8 ConsumeGimmickFlag(u8 index);
void SetBtlPaletteFadeExcluded(u8 index, u8 on);
void SetBtlObjUnhittable(BtlObj* obj, u8 on);
void ExitBattle();
u8 ApplyBattleBounds(s32* x, s32* y, s32* z, s32* floor);
void GetEnemyTargetPosition(BtlObj* obj, s32* x, s32* y, s32* z);
u8 StepHitFlash(BtlObj* obj);

struct HumWork;
struct HumSub;

void BtlWorkInit();
u8 IsPlayerOnPlatform(Collider* platform);
void SetBattleActorPosition(s32 x, s32 y, s32 z);
u8 SpawnEnemy(s32 id, s32 x, s32 y, s32 z);
void AllocBattleTiles();
void ReleaseBattleTiles();
void SetGimmickFlag(u8 index);
void DropGimmickCard(u8 index, s32 x, s32 y, s32 z);
void SetGimmickTarget(s32 x, s32 y, s32 z);
void SetEnemyHpFromStats(BtlObj* obj, s32 id, s32 hpScale);
void SetEnemyJiminyFlag(BtlObj* obj);

#endif
