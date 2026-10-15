/**
 * emy_14.c
 * Soldier Enemy
 */

#include "task_descriptors.h"
#include "sprites_emy.h"
#include "enemy_common.h"
#include "songs.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "enemy_types.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy14CommonAnimDefs[3] = {
    { gEmy14Ll00Frames, gEmy14Ll00Anims, gEmy14Ll00Tiles, 0 },
    { gEmy14Ll03Frames, gEmy14Ll03Anims, gEmy14Ll03Tiles, 0 },
    { gEmy14Ll01Frames, gEmy14Ll01Anims, gEmy14Ll01Tiles, 0 },
};

static const AnimDef sEmy14AnimDefs[2] = {
    { gEmy14Ll02Frames, gEmy14Ll02Anims, gEmy14Ll02Tiles, 0 },
    { gEmy14Ll04Frames, gEmy14Ll04Anims, gEmy14Ll04Tiles, 0 },
};

static const EmyDef sEmy14Def = { gEmy14Palette, sEmy14CommonAnimDefs, 307, 130, 10, 20, 64, 32, 16, 10, 0, { ENEMY_SOLDIER, 32, 35, 12, 16, 100, 0 } };

TaskDesc gTaskDescEmy14 = {
    "task_emy_14",
    (TaskInitFunc)task_emy_14_0,
    (TaskUpdateFunc)task_emy_14_1,
    (TaskDrawFunc)task_emy_14_2,
    (TaskDestroyFunc)task_emy_14_3,
    sizeof(EmyWork),
};

void task_emy_14_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy14Def, obj);
}

enum Emy14State {
    EMY14_STATE_SHORT_LUNGE = 18,
    EMY14_STATE_LONG_LUNGE
};

u8 task_emy_14_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    s32 targetX;
    s32 dx;

    w = work;
    act = &work->actor;

    if (EmyUpdateReaction(work)) {
        GetEnemyTargetPosition(act, &targetX, NULL, NULL);
        dx = act->x - targetX;

        if (dx >= 0 ? dx <= 0x31FF : targetX - act->x <= 0x31FF) {
            work->state = EMY14_STATE_SHORT_LUNGE;
        } else {
            work->state = EMY14_STATE_LONG_LUNGE;
        }
    }

    switch (work->state) {
    case EMY14_STATE_SHORT_LUNGE:
        AnimChangeWithDef(sEmy14AnimDefs, &w->anim, 0, 0, w->tiles);
        EmyLungeAttack(work, 0x0F, 0x0E, 0x14, 0xB3, 0x18, SONG_BTL_HANE_HIT, 0, 0, 0x16);
        break;
    case EMY14_STATE_LONG_LUNGE:
        AnimChangeWithDef(sEmy14AnimDefs, &w->anim, 1, 0, w->tiles);
        EmyLungeAttack(work, 0x14, 0x25, 0x06, 0xB4, 0x64, SONG_BTL_MON_HIT02, 0, 0, 0x14);
        break;
    }

    return EmyUpdateCommonStates(work);
}

void task_emy_14_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_14_3(EmyWork* work) {
    EmyReleaseResources(work);
}
