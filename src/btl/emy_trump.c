/**
 * emy_trump.c
 * Card Soldier Enemy
 */

#include "task_descriptors.h"
#include "sprites_emy.h"
#include "sprites_evt.h"
#include "enemy_common.h"
#include "songs.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmyTrumpHCommonAnimDefs[3] = {
    { gTrumpH00bFrames, gTrumpH00bAnims, gTrumpH00bTiles, 0 },
    { gTrumpH02bFrames, gTrumpH02bAnims, gTrumpH02bTiles, 0 },
    { gTrumpH03Frames, gTrumpH03Anims, gTrumpH03Tiles, 0 },
};

static const AnimDef sEmyTrumpHAnimDef = { gTrumpH10Frames, gTrumpH10Anims, gTrumpH10Tiles, 0 };

static const EmyDef sEmyTrumpHDef = { gTrumpHPalette, sEmyTrumpHCommonAnimDefs, 409, 130, 20, 20, 90, 32, 32, 10, 0, { ENEMY_CARD_SOLDIER_HEART, 200, 40, 16, 16, 100, 0 } };

TaskDesc gTaskDescEmyTrumpH = {
    "task_emy_trump_h",
    (TaskInitFunc)task_emy_trump_h_0,
    (TaskUpdateFunc)task_emy_trump_h_1,
    (TaskDrawFunc)task_emy_trump_h_2,
    (TaskDestroyFunc)task_emy_trump_h_3,
    sizeof(EmyWork),
};

static const AnimDef sEmyTrumpSCommonAnimDefs[3] = {
    { gTrumpS00bFrames, gTrumpS00bAnims, gTrumpS00bTiles, 0 },
    { gTrumpS02bFrames, gTrumpS02bAnims, gTrumpS02bTiles, 0 },
    { gTrumpS03Frames, gTrumpS03Anims, gTrumpS03Tiles, 0 },
};

static const AnimDef sEmyTrumpSAnimDef = { gTrumpS10Frames, gTrumpS10Anims, gTrumpS10Tiles, 0 };

static const EmyDef sEmyTrumpSDef = { gTrumpSPalette, sEmyTrumpSCommonAnimDefs, 307, 130, 20, 20, 64, 32, 32, 10, 0, { ENEMY_CARD_SOLDIER_SPADE, 200, 40, 16, 16, 100, 0 } };

TaskDesc gTaskDescEmyTrumpS = {
    "task_emy_trump_s",
    (TaskInitFunc)task_emy_trump_s_0,
    (TaskUpdateFunc)task_emy_trump_s_1,
    (TaskDrawFunc)task_emy_trump_s_2,
    (TaskDestroyFunc)task_emy_trump_s_3,
    sizeof(EmyWork),
};

void task_emy_trump_h_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmyTrumpHDef, obj);
}

enum EmyTrumpState {
    EMY_TRUMP_STATE_CARD_DEATH = 18,
    EMY_TRUMP_STATE_LUNGE
};

u8 task_emy_trump_h_1(EmyWork* work) {
    BtlObj* act;

    act = &work->actor;

    if (EmyUpdateReaction(work)) {
        work->state = EMY_TRUMP_STATE_LUNGE;
    }

    if (work->state == EMY_STATE_DEFEATED) {
        work->state = EMY_TRUMP_STATE_CARD_DEATH;
    }

    switch (work->state) {
    case EMY_TRUMP_STATE_LUNGE:
        AnimChangeWithDef(&sEmyTrumpHAnimDef, &work->anim, 0, 0, work->tiles);
        EmyLungeAttack(work, 0x19, 8, 0x0A, 0x12B, 0x30, SONG_BTL_MON_SWORD00, 0x50, 0, 0x18);
        break;
    case EMY_TRUMP_STATE_CARD_DEATH:
        if (work->stateTimer == 0) {
            AnimChangeWithDef(work->def->animDef, &work->anim, 0, 0, work->tiles);
            m4aSongNumStart(SONG_BTL_CARDDEATH);
        }

        work->scaleX = gSineTable[(u8)work->stateTimer + 0x40];
        work->stateTimer += 8;

        if (work->stateTimer > 0x13F) {
            DropEnemyPrizes(act);
            return 0;
        }

        work->stateTimer++;
        break;
    }

    return EmyUpdateCommonStates(work);
}

void task_emy_trump_h_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_trump_h_3(EmyWork* work) {
    EmyReleaseResources(work);
}

void task_emy_trump_s_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmyTrumpSDef, obj);
}

u8 task_emy_trump_s_1(EmyWork* work) {
    BtlObj* act;

    act = &work->actor;

    if (EmyUpdateReaction(work)) {
        work->state = EMY_TRUMP_STATE_LUNGE;
    }

    if (work->state == EMY_STATE_DEFEATED) {
        work->state = EMY_TRUMP_STATE_CARD_DEATH;
    }

    switch (work->state) {
    case EMY_TRUMP_STATE_LUNGE:
        AnimChangeWithDef(&sEmyTrumpSAnimDef, &work->anim, 0, 0, work->tiles);
        EmyLungeAttack(work, 0x14, 0x1E, 0x0A, 0x12A, 0x46, SONG_BTL_MON_SWORD01, 0x10, 0, 0x18);

        if (work->stateTimer == 0x14) {
            work->vz = -0x480;
        }

        break;
    case EMY_TRUMP_STATE_CARD_DEATH:
        if (work->stateTimer == 0) {
            AnimChangeWithDef(work->def->animDef, &work->anim, 0, 0, work->tiles);
            m4aSongNumStart(SONG_BTL_CARDDEATH);
        }

        work->scaleX = gSineTable[(u8)work->stateTimer + 0x40];
        work->stateTimer += 8;

        if (work->stateTimer > 0x13F) {
            DropEnemyPrizes(act);
            return 0;
        }

        work->stateTimer++;
        break;
    }

    return EmyUpdateCommonStates(work);
}

void task_emy_trump_s_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_trump_s_3(EmyWork* work) {
    EmyReleaseResources(work);
}
