/**
 * emy_44.c
 * Defender Enemy
 */

#include "task_descriptors.h"
#include "sprites_emy.h"
#include "enemy_common.h"
#include "songs.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_collision.h"
#include "btl_effect.h"
#include "enemy_types.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy44CommonAnimDefs[3] = {
    { gEmy4400Frames, gEmy4400Anims, gEmy4400Tiles, 0 },
    { gEmy4402Frames, gEmy4402Anims, gEmy4402Tiles, 0 },
    { gEmy4401Frames, gEmy4401Anims, gEmy4401Tiles, 0 },
};

static const AnimDef sEmy44AnimDefs[2] = {
    { gEmy4410Frames, gEmy4410Anims, gEmy4410Tiles, 0 },
    { gEmy4412Frames, gEmy4412Anims, gEmy4412Tiles, 0 },
};

static const EmyDef sEmy44Def = { gEmy44Palette, sEmy44CommonAnimDefs, 192, 130, 90, 20, 60, 60, 16, 10, 0, { ENEMY_DEFENDER, 260, 48, 25, 32, 100, EMY_KIND_FLAG_LARGE_BODY } };

TaskDesc gTaskDescEmy44 = {
    "task_emy_44",
    (TaskInitFunc)task_emy_44_0,
    (TaskUpdateFunc)task_emy_44_1,
    (TaskDrawFunc)task_emy_44_2,
    (TaskDestroyFunc)task_emy_44_3,
    sizeof(EmyWork),
};

void task_emy_44_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy44Def, obj);
}

enum Emy44State {
    EMY44_STATE_BASH = 18,
    EMY44_STATE_FIRE
};

u8 task_emy_44_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    s32 targetX;
    s32 dx;
    u8 alive;

    w = work;
    act = &work->actor;

    if (EmyUpdateReaction(work)) {
        GetEnemyTargetPosition(act, &targetX, NULL, NULL);
        dx = act->x - targetX;

        if (dx >= 0 ? dx <= 0x4FFF : targetX - act->x <= 0x4FFF) {
            work->state = EMY44_STATE_BASH;
        } else {
            work->state = EMY44_STATE_FIRE;
        }
    }

    switch (work->state) {
    case EMY44_STATE_BASH:
        AnimChangeWithDef(sEmy44AnimDefs, &w->anim, 0, 0, w->tiles);

        switch (AnimGetFrame(&work->anim)) {
        case 1:
        case 2:
        case 3:
        case 4:
            if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                    ? ApplyAttackBox(0xDA, act->x - 0x2000, act->y, act->z, 0x20,
                        0x10, 0x28)
                    : ApplyAttackBox(0xDA, act->x + 0x2000, act->y, act->z, 0x20,
                        0x10, 0x28)) {
                m4aSongNumStart(SONG_BTL_DF_HIT);
            }

            break;
        }

        if (AnimIsFinished(&work->anim)) {
            EmyReturnToIdle(work);
        }

        break;
    case EMY44_STATE_FIRE:
        AnimChangeWithDef(sEmy44AnimDefs, &w->anim, 1, 0, w->tiles);

        if (AnimGetFrame(&work->anim) == 7 && work->anim.timer == 0) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                BgFxStartFire(SPELL_TIER_RA, act->x - 0x4000, act->y, act->z - 0x400,
                    act->x - 0xB400, act->y, act->z - 0x400, TRUE, 0xDB);
            } else {
                BgFxStartFire(SPELL_TIER_RA, act->x + 0x4000, act->y, act->z - 0x400,
                    act->x + 0xB400, act->y, act->z - 0x400, FALSE, 0xDB);
            }
        }

        if (AnimIsFinished(&work->anim)) {
            EmyReturnToIdle(work);
        }

        break;
    }

    alive = EmyUpdateCommonStates(work);

    if ((gBtlWork->actor->x < work->actor.x && (work->actor.flags & BTLOBJ_FLAG_FACING_LEFT)) ||
            (gBtlWork->actor->x > work->actor.x &&
                !(work->actor.flags & BTLOBJ_FLAG_FACING_LEFT))) {
        work->actor.flags |= (BTLOBJ_FLAG_GUARD_PHYSICAL | BTLOBJ_FLAG_IMMUNE_FIRE | BTLOBJ_FLAG_IMMUNE_BLIZZARD);
    } else {
        work->actor.flags &= ~(BTLOBJ_FLAG_GUARD_PHYSICAL | BTLOBJ_FLAG_IMMUNE_FIRE | BTLOBJ_FLAG_IMMUNE_BLIZZARD);
    }

    return alive;
}

void task_emy_44_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_44_3(EmyWork* work) {
    EmyReleaseResources(work);
}
