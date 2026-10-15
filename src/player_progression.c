/**
 * player_progression.c
 * Player Progression
 */

#include "macros.h"
#include "ms_api.h"
#include "player_progression.h"
#include "battle.h"
#include "battle_work.h"
#include "bos_jf_shadow.h"
#include "bos4_api.h"
#include "game_state.h"
#include "player_progression_types.h"
#include "types.h"
#include <stddef.h>

static const EnemyBaseStats sEnemyBaseStats[54] = {
    { 33, 2, 3, 0 },
    { 35, 3, 3, 0 },
    { 35, 3, 3, 0 },
    { 35, 3, 3, 0 },
    { 40, 2, 3, 0 },
    { 50, 4, 4, 0 },
    { 198, 0, 3, 0 },
    { 74, 5, 1, 0 },
    { 40, 1, 3, 0 },
    { 60, 3, 5, 0 },
    { 70, 3, 5, 0 },
    { 50, 4, 5, 0 },
    { 80, 3, 5, 0 },
    { 80, 5, 5, 0 },
    { 60, 5, 5, 0 },
    { 60, 3, 5, 0 },
    { 80, 5, 8, 0 },
    { 70, 4, 8, 0 },
    { 80, 4, 5, 0 },
    { 70, 4, 8, 0 },
    { 60, 4, 8, 0 },
    { 70, 3, 10, 0 },
    { 70, 4, 10, 0 },
    { 50, 3, 10, 0 },
    { 74, 3, 10, 0 },
    { 100, 4, 10, 0 },
    { 120, 5, 10, 0 },
    { 130, 5, 10, 0 },
    { 90, 4, 13, 0 },
    { 70, 3, 8, 0 },
    { 70, 3, 8, 0 },
    { 60, 3, 8, 0 },
    { 200, 5, 48, 0 },
    { 500, 5, 93, 0 },
    { 500, 5, 93, 0 },
    { 400, 5, 173, 0 },
    { 550, 4, 93, 0 },
    { 600, 5, 173, 0 },
    { 600, 6, 195, 0 },
    { 500, 5, 93, 0 },
    { 660, 6, 313, 0 },
    { 500, 3, 133, 0 },
    { 400, 3, 173, 0 },
    { 250, 3, 77, 0 },
    { 400, 4, 93, 0 },
    { 500, 2, 75, 0 },
    { 80, 3, 5, 0 },
    { 100, 4, 7, 0 },
    { 313, 2, 75, 0 },
    { 500, 3, 75, 0 },
    { 500, 3, 75, 0 },
    { 500, 3, 113, 0 },
    { 500, 3, 133, 0 },
    { 500, 3, 133, 0 },
};

GameState gGameState EWRAM_COMMON(16);

void AdvanceLevelExpThreshold(PlayerProgression* progression) {
    s32 nextLevel = progression->level + 1;

    if (progression->level) {
        progression->nextExp = nextLevel * nextLevel * 3 + progression->nextExp;
    } else {
        progression->nextExp = nextLevel * nextLevel * 3 + progression->nextExp;
    }
}

void InitPlayerProgression() {
    PlayerProgression* progression = &gGameState.progression;

    progression->maxHp = 0x50;
    progression->cp = 0x113;
    progression->dp = 8;
    progression->ap = 10;
    progression->exp = 0;
    progression->level = 1;
    progression->learnedStocks = 0;
    progression->learnedStocks2 = 0;
    progression->newStocks = 0;
    progression->newStocks2 = 0;
    progression->obtainedCardKinds = 0;
    progression->jiminyFlags[0] = 0;
    progression->jiminyFlags[1] = 0;
    progression->jiminyFlags[2] = 0;
    progression->jiminyFlags[3] = 0;
    progression->jiminyFlags[4] = 0;
    progression->jiminyFlags[5] = 0;
    progression->jiminyFlags[6] = 0;
    progression->jiminyFlags[7] = 0;
    progression->mooglePoints = 0;
    progression->levelMilestone = 0;
    progression->tutorialFlags = 0;
    progression->friendFlags = 0;
    progression->nextExp = 0x19;
    ResetSaveSliceE6C();
    ResetPooState();
    ClearMoogleShopFlags();
}

u8 LevelUp() {
    PlayerProgression* progression = &gGameState.progression;

    if (progression->level + gBtlWork->pendingLevelUps + 1 <= 99) {
        gBtlWork->pendingLevelUps++;
        progression->level++;
        AdvanceLevelExpThreshold(progression);
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 LevelUpMaxHp() {
    gGameState.progression.maxHp += 15;

    if (gGameState.progression.maxHp > 560) {
        gGameState.progression.maxHp = 560;
    }

    return 15;
}

s32 LevelUpCp() {
    gGameState.progression.cp += 25;

    if (gGameState.progression.cp > 9999) {
        gGameState.progression.cp = 9999;
    }

    return 25;
}

s32 LevelUpDp() {
    gGameState.progression.dp += 2;

    if (gGameState.progression.dp > 999) {
        gGameState.progression.dp = 999;
    }

    return 2;
}

s32 LevelUpAp() {
    gGameState.progression.ap += 1;

    if (gGameState.progression.ap > 999) {
        gGameState.progression.ap = 999;
    }

    return 1;
}

void AddExp(u16 exp) {
    PlayerProgression* progression = &gGameState.progression;

    progression->exp += exp;
}

u8 CanLevelUp() {
    PlayerProgression* progression = &gGameState.progression;

    if (progression->exp >= progression->nextExp) {
        return TRUE;
    }

    return FALSE;
}

const EnemyBaseStats* GetEnemyBaseStats(u16 i) {
    if (i > 0x35) {
        return NULL;
    }

    return &sEnemyBaseStats[i];
}

void LearnStock(u32 stock) {
    u8* addr;
    u8* base;

    if (stock == 72) {
        base = (u8*)&gGameState;
        *(u64*)(base + offsetof(GameState, progression.learnedStocks)) = -1;
        *(u64*)(base + offsetof(GameState, progression.learnedStocks2)) = -1;
        return;
    }

    if (IsStockLearned(stock)) {
        return;
    }

    if (stock <= 0x1E) {
        addr = (u8*)&gGameState;
        *(u64*)(addr + offsetof(GameState, progression.learnedStocks)) |= 1LL << stock;
        *(u64*)(addr + offsetof(GameState, progression.newStocks)) |= 1LL << stock;
    } else {
        stock -= 0x1F;
        addr = (u8*)&gGameState;
        *(u64*)(addr + offsetof(GameState, progression.learnedStocks2)) |= 1LL << stock;
        *(u64*)(addr + offsetof(GameState, progression.newStocks2)) |= 1LL << stock;
    }
}

u8 IsStockLearned(u32 stock) {
    u64* flags;
    u8* addr;

    if (stock <= 0x1E) {
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.learnedStocks);
    } else {
        stock -= 0x1F;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.learnedStocks2);
    }

    flags = (u64*)addr;

    if (*flags & (1LL << stock)) {
        return TRUE;
    }

    return FALSE;
}

void SetCardKindObtained(s32 kind) {
    if (kind == 0x3A) {
        gGameState.progression.obtainedCardKinds = -1;
    } else {
        gGameState.progression.obtainedCardKinds |= 1LL << kind;
    }
}

u8 IsCardKindObtained(s32 kind) {
    if (gGameState.progression.obtainedCardKinds & (1LL << kind)) {
        return TRUE;
    }

    return FALSE;
}

u8 IsLinkStockLearned(u32 stock) {
    u64* flags;
    u8* addr;

    if (stock <= 0x1E) {
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, linkLearnedStocks);
    } else {
        stock -= 0x1F;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, linkLearnedStocks2);
    }

    flags = (u64*)addr;

    if (*flags & (1LL << stock)) {
        return TRUE;
    }

    return FALSE;
}

u8 IsLinkPartnerStockLearned(u32 stock) {
    u64* flags;
    u8* addr;

    if (stock <= 0x1E) {
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, linkPartnerLearnedStocks);
    } else {
        stock -= 0x1F;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, linkPartnerLearnedStocks2);
    }

    flags = (u64*)addr;

    if (*flags & (1LL << stock)) {
        return TRUE;
    }

    return FALSE;
}

u8 IsStockNew(u32 stock) {
    u64* flags;
    u8* addr;

    if (stock <= 0x1E) {
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.newStocks);
    } else {
        stock -= 0x1F;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.newStocks2);
    }

    flags = (u64*)addr;

    if (*flags & (1LL << stock)) {
        return TRUE;
    }

    return FALSE;
}

void ClearStockNew(u32 stock) {
    u64* flags;
    u8* addr;

    if (stock == 0x48) {
        GameState* state = &gGameState;
        state->progression.newStocks = 0;
        state->progression.newStocks2 = 0;
    } else {
        if (stock <= 0x1E) {
            addr = (u8*)&gGameState;
            addr += offsetof(GameState, progression.newStocks);
        } else {
            stock -= 0x1F;
            addr = (u8*)&gGameState;
            addr += offsetof(GameState, progression.newStocks2);
        }

        flags = (u64*)addr;
        *flags &= ~(1LL << stock);
    }
}

void SetJiminyFlag(u32 flag) {
    GameState* state;

    if (flag == 250) {
        GameState* state = &gGameState;
        state->progression.jiminyFlags[0] = -1;
        state->progression.jiminyFlags[1] = -1;
        state->progression.jiminyFlags[2] = -1;
        state->progression.jiminyFlags[3] = -1;
        state->progression.jiminyFlags[4] = -1;
        state->progression.jiminyFlags[5] = -1;
        state->progression.jiminyFlags[6] = -1;
        state->progression.jiminyFlags[7] = -1;
        return;
    }

    if (IsJiminyFlagSet(flag)) {
        return;
    }

    if (flag <= 0x3F) {
        state = &gGameState;
        state->progression.jiminyFlags[0] |= 1ULL << flag;
        state->progression.jiminyFlags[4] |= 1ULL << flag;
    } else if (flag <= 0x7F) {
        flag -= 0x40;
        state = &gGameState;
        state->progression.jiminyFlags[1] |= 1ULL << flag;
        state->progression.jiminyFlags[5] |= 1ULL << flag;
    } else if (flag <= 0xBF) {
        flag -= 0x80;
        state = &gGameState;
        state->progression.jiminyFlags[2] |= 1ULL << flag;
        state->progression.jiminyFlags[6] |= 1ULL << flag;
    } else {
        flag -= 0xC0;
        state = &gGameState;
        state->progression.jiminyFlags[3] |= 1ULL << flag;
        state->progression.jiminyFlags[7] |= 1ULL << flag;
    }
}

u8 IsJiminyFlagSet(u32 flag) {
    u64* flags;
    u8* addr;

    if (flag <= 0x3F) {
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[0]);
    } else if (flag <= 0x7F) {
        flag -= 0x40;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[1]);
    } else if (flag <= 0xBF) {
        flag -= 0x80;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[2]);
    } else {
        flag -= 0xC0;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[3]);
    }

    flags = (u64*)addr;

    if (*flags & (1LL << flag)) {
        return TRUE;
    }

    return FALSE;
}

u8 IsJiminyFlagNew(u32 flag) {
    u64* flags;
    u8* addr;

    if (flag <= 0x3F) {
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[4]);
    } else if (flag <= 0x7F) {
        flag -= 0x40;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[5]);
    } else if (flag <= 0xBF) {
        flag -= 0x80;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[6]);
    } else {
        flag -= 0xC0;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[7]);
    }

    flags = (u64*)addr;

    if (*flags & (1LL << flag)) {
        return TRUE;
    }

    return FALSE;
}

void ClearJiminyFlagNew(u32 flag) {
    u64* flags;
    u8* addr;
    u8* z;

    if (flag == 250) {
        z = (u8*)&gGameState;
        *(u64*)(z + offsetof(GameState, progression.jiminyFlags[4])) = 0;
        *(u64*)(z + offsetof(GameState, progression.jiminyFlags[5])) = 0;
        *(u64*)(z + offsetof(GameState, progression.jiminyFlags[6])) = 0;
        *(u64*)(z + offsetof(GameState, progression.jiminyFlags[7])) = 0;
        return;
    }

    if (flag <= 0x3F) {
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[4]);
    } else if (flag <= 0x7F) {
        flag -= 0x40;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[5]);
    } else if (flag <= 0xBF) {
        flag -= 0x80;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[6]);
    } else {
        flag -= 0xC0;
        addr = (u8*)&gGameState;
        addr += offsetof(GameState, progression.jiminyFlags[7]);
    }

    flags = (u64*)addr;
    *flags &= ~(1LL << flag);
}
