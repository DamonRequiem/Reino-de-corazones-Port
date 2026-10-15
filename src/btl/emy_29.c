/**
 * emy_29.c
 * Darkball Enemy
 */

#include "task_descriptors.h"
#include "emy.h"
#include "sprites_emy.h"
#include "enemy_common.h"
#include "songs.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "btl_collision.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy29CommonAnimDefs[3] = {
    { gEmy2900Frames, gEmy2900Anims, gEmy2900Tiles, 0 },
    { gEmy2902Frames, gEmy2902Anims, gEmy2902Tiles, 0 },
    { gEmy2900Frames, gEmy2900Anims, gEmy2900Tiles, 0 },
};

static const AnimDef sEmy29AnimDefs[2] = {
    { gEmy2910Frames, gEmy2910Anims, gEmy2910Tiles, 0 },
    { gEmy2911Frames, gEmy2911Anims, gEmy2911Tiles, 0 },
};

static const EmyDef sEmy29Def = { gEmy29Palette, sEmy29CommonAnimDefs, 192, 300, 20, 20, 64, 64, 32, 30, 0, { ENEMY_DARKBALL, 80, 56, 22, 32, 100, EMY_KIND_FLAG_LARGE_BODY } };

TaskDesc gTaskDescEmy29 = {
    "task_emy_29",
    (TaskInitFunc)task_emy_29_0,
    (TaskUpdateFunc)task_emy_29_1,
    (TaskDrawFunc)task_emy_29_2,
    (TaskDestroyFunc)task_emy_29_3,
    sizeof(Emy29Work),
};

void task_emy_29_0(Emy29Work* work, void* obj) {
    EmyInit(&work->base, &sEmy29Def, obj);
    work->base.fxScale = Q_8_8(1.5);
    work->base.idleState = EMY_STATE_HOVER;
    work->base.flags |= EMY_FLAG_DARK_DEATH;
    work->state = 0;
    work->steps = 0;
}

void Emy29MoveToPose(Emy29Work* work, s16 anim, s16 dx, s16 dy, s16 dz) {
    if (work->steps > 0) {
        AnimChange(&work->base.anim, anim, 0);
        ApproachValue(&work->base.actor.x, work->base.actor.originX + (dx << 8), work->steps);
        ApproachValue(&work->base.actor.y, work->base.actor.originY + (dy << 8), work->steps);
        ApproachValue(&work->base.actor.z, dz << 8, work->steps);
        work->steps--;
    } else {
        work->steps = 8;
        work->state++;
    }
}

enum Emy29State {
    EMY29_STATE_BITE = 18,
    EMY29_STATE_BOUNCE
};

u8 task_emy_29_1(Emy29Work* work) {
    Emy29Work* w;
    BtlObj* act;
    s32 targetX;
    s32 dx;
    s32 sample;
    s32 z;
    s16 timer;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        GetEnemyTargetPosition(act, &targetX, NULL, NULL);
        dx = act->x - targetX;

        if (dx >= 0 ? dx <= 0x27FF : targetX - act->x <= 0x27FF) {
            work->base.state = EMY29_STATE_BOUNCE;
        } else {
            work->base.state = EMY29_STATE_BITE;
        }
    }

    switch (work->base.state) {
    case EMY29_STATE_BITE:
        AnimChangeWithDef(sEmy29AnimDefs, &w->base.anim, 0, 0, w->base.tiles);
        work->base.vz = 0;
        sample = -COS((u16)work->base.stateTimer * 2) << 4;
        z = act->z + 0x1000;
        act->z += (sample - z) >> 2;

        if (EmyLungeAttack(&work->base, 0x16, 0x64, 0x18, 0xCB, 0xB4, SONG_BTL_KAMITUKI, 0, 0, 0x0C) == EMY_LUNGE_HIT) {
            EmyReturnToIdle(&work->base);
        }

        break;
    case EMY29_STATE_BOUNCE:
        timer = work->base.stateTimer;

        if (timer == 0) {
            AnimChangeWithDef(sEmy29AnimDefs, &w->base.anim, 1, 0, w->base.tiles);
            w->state = 0;
            w->steps = 8;
            work->base.stateTimer++;
            m4aSongNumStart(SONG_BTL_BOYOYON);
        }

        switch (w->state) {
        case 0:
            Emy29MoveToPose(w, 0, -25, 5, -10);
            break;
        case 1:
            Emy29MoveToPose(w, 1, 25, 0, 0);
            break;
        case 2:
            Emy29MoveToPose(w, 2, -20, -5, -22);
            break;
        case 3:
            Emy29MoveToPose(w, 3, 5, -17, -8);
            break;
        case 4:
            Emy29MoveToPose(w, 4, -5, 17, -16);
            break;
        case 5:
            Emy29MoveToPose(w, 5, 0, -17, 0);
            break;
        case 6:
            Emy29MoveToPose(w, 6, 25, 0, -11);
            break;
        case 7:
            Emy29MoveToPose(w, 7, -25, 0, -4);
            break;
        case 8:
            Emy29MoveToPose(w, 8, 0, 0, 0);
            break;
        case 9:
            EmyReturnToIdle(&work->base);
            break;
        }

        if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                ? ApplyAttackBox(0xCC, act->x, act->y, act->z, 0x0C, 0x0C, 0x0C)
                : ApplyAttackBox(0xCC, act->x, act->y, act->z, 0x0C, 0x0C, 0x0C)) {
            m4aSongNumStart(SONG_BTL_MON_HIT01);
        }

        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_29_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_29_3(EmyWork* work) {
    EmyReleaseResources(work);
}
