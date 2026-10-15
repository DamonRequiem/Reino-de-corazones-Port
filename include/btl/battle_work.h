#ifndef GUARD_BATTLE_WORK_H
#define GUARD_BATTLE_WORK_H

#include "types.h"
#include "taskpool.h"
#include "battle_bounds.h"
#include "battle_actor_types.h"
#include "listpool.h"
#include "macros.h"

enum BtlFlag {
    BTL_FLAG_ENEMY_FRAME_CHANGED = 0x1,
    BTL_FLAG_STOCK_SEQUENCE = 0x2,
    BTL_FLAG_BOSS_BATTLE = 0x4,
    BTL_FLAG_PUSHING_EDGE = 0x8,
    BTL_FLAG_ESCAPED = 0x10,
    BTL_FLAG_CARD_PLAY_ENDED = 0x20,
    BTL_FLAG_OPPONENT_CARD_ACTION = 0x40,
    BTL_FLAG_CARD_ACTIVE = 0x80,
    BTL_FLAG_CARD_PLAY_START = 0x400,
    BTL_FLAG_HUM_BATTLE = 0x800,
    BTL_FLAG_VS_LINK_PARENT = 0x1000,
    BTL_FLAG_FIELD_HIDDEN = 0x2000,
    BTL_FLAG_VS_BATTLE = 0x4000,
    BTL_FLAG_PLAYER_AIRBORNE = 0x8000,
    BTL_FLAG_ENEMY_DEFEATED = 0x10000,
    BTL_FLAG_LEVEL_UP_EFFECT = 0x20000,
    BTL_FLAG_ENEMY_MOVE_ENABLED = 0x40000,
    BTL_FLAG_BOSS_DEFEATING = 0x80000,
    BTL_FLAG_SUMMON_ACTIVE = 0x200000,
    BTL_FLAG_STOP_BGFX = 0x400000,
    BTL_FLAG_CARD_BREAK = 0x800000,
    BTL_FLAG_RELOAD_CHARGING = 0x1000000,
    BTL_FLAG_FORMATION_ACTIVE = 0x2000000,
    BTL_FLAG_PAUSE_DISABLED = 0x4000000,
    BTL_FLAG_PLAYER_CARD_BUSY = 0x8000000,
    BTL_FLAG_OPPONENT_CARD_BUSY = 0x10000000,
    BTL_FLAG_PLAYER_CARD_ACTION = 0x20000000,
    BTL_FLAG_DISMISS_SUMMONS = 0x40000000
};

#define BTL_FLAG_RELOADING               0x80000000LL
#define BTL_FLAG_PREMIRE_DROPPED         0x100000000
#define BTL_FLAG_BATTLE_OVER             0x200000000
#define BTL_FLAG_NO_ENEMY_DROPS          0x400000000
#define BTL_FLAG_TUTORIAL                0x800000000
#define BTL_FLAG_TUTORIAL_NO_CONTROL     0x1000000000
#define BTL_FLAG_TUTORIAL_NO_CARD_USE    0x2000000000
#define BTL_FLAG_TUTORIAL_NO_CARD_SELECT 0x4000000000
#define BTL_FLAG_TUTORIAL_NO_STOCK       0x8000000000
#define BTL_FLAG_TUTORIAL_NO_LIST_SWITCH 0x10000000000
#define BTL_FLAG_DODGE_ROLL_DONE         0x40000000000
#define BTL_FLAG_JUMP_LANDED             0x80000000000
#define BTL_FLAG_TUTORIAL_NO_JUMP        0x100000000000
#define BTL_FLAG_TUTORIAL_NO_DODGE       0x200000000000
#define BTL_FLAG_PLAYER_DEFEATED         0x400000000000
#define BTL_FLAG_DARK_MODE               0x800000000000
#define BTL_FLAG_TILES_ALLOCATED         0x1000000000000
#define BTL_FLAG_PLAYER_OFFSCREEN        0x2000000000000
#define BTL_FLAG_TUTORIAL_NO_STOCK_USE   0x4000000000000
#define BTL_FLAG_PREMIRE_COLLECTED       0x8000000000000
#define BTL_FLAG_CAN_CHARGE_RELOAD       0x10000000000000
#define BTL_FLAG_GIMMICK_CARD_ACTIVE     0x20000000000000
#define BTL_FLAG_DARK_MODE_CHANGED       0x80000000000000
#define BTL_FLAG_STOP_SPAWNING           0x100000000000000
#define BTL_FLAG_BGFX_PAUSED             0x200000000000000
enum RikuKey {
    RIKU_KEY_NEXT_CARD = 0x1,
    RIKU_KEY_PREV_CARD = 0x2,
    RIKU_KEY_SWITCH_LIST = 0x4,
    RIKU_KEY_STOCK = 0x10,
    RIKU_KEY_USE_CARD = 0x20
};

enum BtlPhase {
    BTL_PHASE_START,
    BTL_PHASE_IDLE,
    BTL_PHASE_CARD_PLAY,
    BTL_PHASE_GAME_OVER,
    BTL_PHASE_END
};

enum BtlStartStep {
    BTL_START_STEP_INTRO,
    BTL_START_STEP_EXCLUDE_PALETTES,
    BTL_START_STEP_CREATE_TASKS,
    BTL_START_STEP_FINISH
};

typedef struct BtlWork {
    s32 viewX;
    s32 viewY;
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;
    u8 rotation;
    s16 zoomSteps;
    s32 zoomX;
    s32 zoomY;
    s32 scale;
    s32 zoomScale;
    TaskPool taskPools[3];
    u64 flags;
    u8 paused;
    s16 hitStop;
    s16 freezeTimer;
    u16 pendingHitStop;
    BtlObj* actor2;
    BtlObj* actor;
    ListPool pool;
    ListPool pool2;
    s32 phase;
    u8 soraOwnsPlay;
    BtlObj* actor3;
    BtlObj* actor4;
    s16 prizeCount;
    s8 stockMove;
    u8 fadeAmount;
    u8 areaUpdated;
    s32 x3;
    s32 y3;
    s32 z3;
    s16 areaHalfX;
    s16 areaHalfY;
    s16 areaHalfZ;
    s32 bossX;
    s32 bossY;
    s32 bossZ;
    s16 bossPriorityOffset;
    s16 xMin;
    s16 xMax;
    s16 yMin;
    s16 yMax;
    u8 lHeldFrames;
    u8 rHeldFrames;
    s16 phaseStep;
    Task* task;
    s16 enemyTileCount;
    u8 enemyCount;
    u8 rikuKeys;
    Collider* platform;
    s32 hcEffect;
    u16 hcEffectCount;
    u8 pendingLevelUps;
    u8 gimmickFlags;
    s32 fadeExcludedPalettes;
    s32 gimmickX;
    s32 gimmickY;
    s32 gimmickZ;
    u32 battleId;
    void* tiles;
    void* tiles2;
    void* tiles3;
    u8 unk_11C[0x04];
    s16 pendingEnemies;
    s32 damageScale;
    BtlBoundsCallback boundsCallback;
    s32 gravity;
    s32 targetX;
    s32 targetY;
    s32 targetZ;
    u8 savedProgression[0x88];
    u16 bg;
    u16 mapBg;
    s16 darkPoints;
    s8 breakDifference;
    u16 listSwitchTimer;
} BtlWork;

STATIC_ASSERT(sizeof(BtlWork) == 0x1D0, BtlWorkSize);

extern BtlWork* gBtlWork;
extern BtlWork* gRikuBtlWork;

#endif
