/**
 * emy_03.c
 * Yellow Opera Enemy
 */

#include "task_descriptors.h"
#include "display.h"
#include "emy.h"
#include "sprites_emy.h"
#include "enemy_common.h"
#include "songs.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "btl_effect.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy03CommonAnimDefs[3] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 0 },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 3 },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 2 },
};

static const AnimDef sEmy03AnimDefs[2] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 7 },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 5 },
};

static const EmyDef sEmy03Def = { gEmy03Palette, sEmy03CommonAnimDefs, 512, 130, 20, 20, 64, 32, 32, 10, 0, { ENEMY_YELLOW_OPERA, 36, 24, 12, 4, 100, EMY_KIND_FLAG_NO_ENEMY_COLLISION } };

TaskDesc gTaskDescEmy03 = {
    "task_emy_03",
    (TaskInitFunc)task_emy_03_0,
    (TaskUpdateFunc)task_emy_03_1,
    (TaskDrawFunc)task_emy_03_2,
    (TaskDestroyFunc)task_emy_03_3,
    sizeof(Emy03Work),
};

void task_emy_03_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy03Def, obj);
    work->idleState = EMY_STATE_HOVER;
}

enum Emy03State {
    EMY03_STATE_THUNDER_LUNGE = 18,
    EMY03_STATE_THUNDER
};

u8 task_emy_03_1(Emy03Work* work) {
    Emy03Work* w;
    BtlObj* act;
    u16 roll;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->base.state = EMY03_STATE_THUNDER_LUNGE;
            break;
        case 1:
            work->base.state = EMY03_STATE_THUNDER;
            break;
        }
    }

    switch (work->base.state) {
    case EMY03_STATE_THUNDER_LUNGE:
        if (work->base.stateTimer == 0) {
            work->base.vz = -0x480;
            AnimChangeWithDef(sEmy03AnimDefs, &w->base.anim, 0, 0, w->base.tiles);
        } else if (work->base.stateTimer == 1) {
            BgFxStartActorThunder(act);
            m4aSongNumStart(SONG_BTL_YELLOW_MOV);
        }

        if (EmyLungeAttack(&work->base, 0x11, 0x17, 0x0A, 0xAB, 0x50, SONG_BTL_YELLOW_HIT, 0, 0, 0x0A) == EMY_LUNGE_FINISHED) {
            BgAnimStop();
        }

        break;
    case EMY03_STATE_THUNDER:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sEmy03AnimDefs, &w->base.anim, 1, 0, w->base.tiles);
        } else if (work->base.stateTimer == 1) {
            GetEnemyTargetPosition(act, &w->targetX, &w->targetY, NULL);
            w->targetZ = 0;
            BgFxStartThunder(SPELL_TIER_BASE, act->x, act->y, act->z - 0x1000, w->targetX,
                w->targetY, 0, 0xAC);
        }

        work->base.vz = 0;

        if (AnimIsFinished(&work->base.anim) && !BgFxIsActive()) {
            EmyReturnToIdle(&work->base);
        } else {
            work->base.stateTimer++;
        }

        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_03_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_03_3(EmyWork* work) {
    EmyReleaseResources(work);
}
