/**
 * game_state.c
 * Game State Setup
 */

#include "system_state.h"
#include "game_state.h"
#include "card_api.h"
#include "map_runtime.h"
#include "player_progression.h"
#include "player_progression_types.h"
#include "types.h"
#include "battle.h"
#include "engine_math.h"
#include "gba/macro.h"
#include "mode_chkbtl_api.h"
#include "world_types.h"
#include "jiminy_records_index_data.h"
#include "fld_types.h"
#include "map_types.h"

void InitGameState() {
    CpuFill32(0, &gGameState, sizeof(GameState));

    if (gDebugFlags & DEBUG_FLAG_RIKU) {
        gGameState.flags |= GAME_FLAG_RIKU;
        gGameState.flags |= GAME_FLAG_SORA_CLEAR;
    }

    gGameState.world = WORLD_WONDERLAND;
    gGameState.battleStage = BATTLE_STAGE_WONDERLAND;
    InitPlayerProgression();
    gGameState.availableWorlds = 0xFFFF;
    ResetMapFloors();
    gGameState.hp = gGameState.progression.maxHp;
    gGameState.fieldAngle = FLD_ANGLE_UP_RIGHT;
    gGameState.roomEffect = ROOM_EFFECT_NONE;
}

void ClearFieldResume() {
    gGameState.fieldResume = FALSE;
}

void RequestFieldResume() {
    gGameState.fieldResume = TRUE;
}

void SeedGameRandom() {
    if (gGameState.fieldResume) {
        SeedRandom(gGameState.randomSeed);
    } else {
        gGameState.randomSeed = GetRandom();
        SeedRandom(gGameState.randomSeed);
    }
}

void ResetGameState() {
    SeedRandom(gFrameCounter);
    InitGameState();
    ClearFieldResume();
    ChkBtlReset();
    gUnk_02039DC0 = 0;
#ifdef VERSION_EU
    gDebugFlags &= ~DEBUG_FLAG_DEBUG_MENU;
#endif
}

u8 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1) {
    s32 dx;
    s32 dy;
    u8 angle;

    dx = x1 - x0;
    dy = y1 - y0;
    angle = 0;

    if (dx == 0 && dy == 0) {
        angle = 0;
    } else if (dx > 0 && dy < 0) {
        dy = -dy;

        if (dx <= dy) {
            angle = ((0x200000 / dy) * dx) >> 16;
        } else {
            angle = 0x40 - (((0x200000 / dx) * dy) >> 16);
        }
    } else if (dx > 0 && dy > 0) {
        if (dx <= dy) {
            angle = 0x7F - (((0x200000 / dy) * dx) >> 16);
        } else {
            angle = (((0x200000 / dx) * dy) >> 16) + 0x3F;
        }
    } else if (dx < 0 && dy > 0) {
        dx = -dx;

        if (dx <= dy) {
            angle = (((0x200000 / dy) * dx) >> 16) - 0x80;
        } else {
            angle = -0x40 - (((0x200000 / dx) * dy) >> 16);
        }
    } else if (dx < 0 && dy < 0) {
        dx = -dx;
        dy = -dy;

        if (dx <= dy) {
            angle = -1 - (((0x200000 / dy) * dx) >> 16);
        } else {
            angle = (((0x200000 / dx) * dy) >> 16) - 0x41;
        }
    } else if (dx == 0 && dy < 0) {
        angle = 0;
    } else if (dx == 0 && dy > 0) {
        angle = 0x80;
    } else if (dx < 0 && dy == 0) {
        angle = 0xC0;
    } else if (dx > 0 && dy == 0) {
        angle = 0x40;
    }

    return angle;
}

void UpdatePlayTime() {
    if (gFrameCounter % 60 == 0) {
        if (gGameState.playTime <= 0x57E3E) {
            gGameState.playTime++;
        }
    }
}

void SetupRikuNewGame() {
    InitStartFloor(0, 0);
    gGameState.progression.tutorialFlags = ~(TUTORIAL_FLAG_RIKU_DECK | TUTORIAL_FLAG_RIKU_BATTLE);
    gGameState.progression.friendFlags = FRIEND_FLAG_THE_KING;
    InitRikuDeckForWorld(0);
    gGameState.flags |= GAME_FLAG_RIKU;
    gGameState.flags |= GAME_FLAG_DARK_POINTS_LOCKED;
    SetJiminyFlag(JIMINY_RECORD_STORY_TALE_1);
    SetJiminyFlag(JIMINY_RECORD_CHARACTER_RIKU);
    SetJiminyFlag(JIMINY_RECORD_RIKU_CHARACTER_KING);
    SetJiminyFlag(JIMINY_RECORD_CHARACTER_SORA);
    SetJiminyFlag(JIMINY_RECORD_CHARACTER_KAIRI);
    SetJiminyFlag(JIMINY_RECORD_RIKU_CHARACTER_ANSEM);
    SetJiminyFlag(JIMINY_RECORD_RIKU_CARD_SOUL_EATER);
}

void SetupSoraNewGame() {
    gGameState.progression.friendFlags = (FRIEND_FLAG_GOOFY | FRIEND_FLAG_DONALD_DUCK);
    InitSoraDecks();
    gGameState.flags &= ~GAME_FLAG_RIKU;
    SetJiminyFlag(JIMINY_RECORD_CHARACTER_SORA);
    SetJiminyFlag(JIMINY_RECORD_CHARACTER_DONALD_DUCK);
    SetJiminyFlag(JIMINY_RECORD_CHARACTER_GOOFY);
    SetJiminyFlag(JIMINY_RECORD_CHARACTER_JIMINY_CRICKET);
    SetJiminyFlag(JIMINY_RECORD_CHARACTER_RIKU);
    SetJiminyFlag(JIMINY_RECORD_CHARACTER_KAIRI);
    InitStartFloor(0, WORLD_TRAVERSE_TOWN);
}
