#ifndef GUARD_GAME_STATE_H
#define GUARD_GAME_STATE_H

#include <stddef.h>
#include "types.h"
#include "save_types.h"
#include "fld_types.h"
#include "player_progression_types.h"
#include "listpool.h"
#include "macros.h"

enum GameFlag {
    GAME_FLAG_MAP_ENEMY_BATTLE = 0x2,
    GAME_FLAG_FIRST_STRIKE = 0x4,
    GAME_FLAG_RIKU = 0x8,
    GAME_FLAG_SECOND_FILE = 0x10,
    GAME_FLAG_SORA_CLEAR = 0x20,
    GAME_FLAG_BATTLE_NOT_WON = 0x40,
    GAME_FLAG_FRIENDS_SAVED = 0x80,
    GAME_FLAG_DARK_POINTS_LOCKED = 0x100,
    GAME_FLAG_RIKU_TITLE = 0x200,
    GAME_FLAG_MONSGAGE_BATTLE = 0x400,
    GAME_FLAG_RIKU_CLEAR = 0x800
};

#define GAME_FLAGS_HEADER (GAME_FLAG_SORA_CLEAR | GAME_FLAG_RIKU_TITLE | GAME_FLAG_RIKU_CLEAR)
enum BattleStage {
    BATTLE_STAGE_WONDERLAND = 1,
    BATTLE_STAGE_GARDEN = 2,
    BATTLE_STAGE_AGRABAH = 3,
    BATTLE_STAGE_ATLANTICA = 4,
    BATTLE_STAGE_MONSTRO = 5,
    BATTLE_STAGE_OLYMPUS_COLISEUM = 6,
    BATTLE_STAGE_HALLOWEEN_TOWN = 7,
    BATTLE_STAGE_NEVER_LAND = 8,
    BATTLE_STAGE_DESTINY_ISLANDS = 9,
    BATTLE_STAGE_HOLLOW_BASTION = 10,
    BATTLE_STAGE_TRAVERSE_TOWN = 11,
    BATTLE_STAGE_CASTLE_OBLIVION = 12,
    BATTLE_STAGE_TWILIGHT_TOWN = 13
};

struct MapEnmDef;
struct MapEnmWork;

typedef struct MapEnmCache {
    FldPos pos;
    u8 angle;
    s32 speed;
    u8 unk_18[0x04];
    ListNode node;
    const struct MapEnmDef* def;
    void (*update)(struct MapEnmWork*);
} MapEnmCache;

typedef struct GameState {
    u8 fieldResume;
    u32 randomSeed;
    u32 flags;
    u8 world;
    u8 battleStage;
    s8 floor;
    u8 mapMenuCursor;
    u16 battleCount;
    FldPos fieldPosition;
    u8 fieldAngle;
    s32 fieldSpeed;
    s32 fieldVz;
    u16 fieldState;
    s16 hp;
    s32 fieldTargetX;
    s32 fieldTargetY;
    s32 fieldTargetZ;
    MapEnmCache enemyCache[3];
    ListPool enemyCachePool;
    PlayerProgression progression;
    u16 availableWorlds;
    u8 unk_182[0x02];
    GameFloor floors[13];
    u32 roomEffect;
    SaveFileSummary fileSummaries[4];
    u32 playTime;
    u16 linkMaxHp;
    u16 linkAp;
    u8 linkLevel;
    u64 linkLearnedStocks;
    u64 linkLearnedStocks2;
    u16 linkPartnerMaxHp;
    u16 linkPartnerAp;
    u8 linkPartnerLevel;
    u64 linkPartnerLearnedStocks;
    u64 linkPartnerLearnedStocks2;
} GameState;

STATIC_ASSERT(sizeof(GameState) == 0x210, GameStateSize);
STATIC_ASSERT(offsetof(GameState, progression) == 0xF8, GameStateProgressionOffset);
STATIC_ASSERT(sizeof(MapEnmCache) == 0x38, MapEnmCacheSize);

extern GameState gGameState;

void InitGameState();
void ClearFieldResume();
void RequestFieldResume();
void SeedGameRandom();
void ResetGameState();
void UpdatePlayTime();
void SetupRikuNewGame();
void SetupSoraNewGame();

#endif
