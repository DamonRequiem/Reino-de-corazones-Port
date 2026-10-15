/**
 * emy_83.c
 * Creeper Plant Enemy
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
#include "battle_work.h"
#include "btl_collision.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "sprites_btl.h"
#include "enemy_ids.h"

static const AnimDef sEmy83CommonAnimDefs[3] = {
    { gEmy8300Frames, gEmy8300Anims, gEmy8300Tiles, 0 },
    { gEmy8302Frames, gEmy8302Anims, gEmy8302Tiles, 0 },
    { gEmy8300Frames, gEmy8300Anims, gEmy8300Tiles, 0 },
};

static const AnimDef sEmy83AnimDefs[4] = {
    { gEmy8310Frames, gEmy8310Anims, gEmy8310Tiles, 0 },
    { gEmy8311Frames, gEmy8311Anims, gEmy8311Tiles, 0 },
    { gEmy8311Frames, gEmy8311Anims, gEmy8311Tiles, 1 },
    { gEmy8311Frames, gEmy8311Anims, gEmy8311Tiles, 2 },
};

static const EmyDef sEmy83Def = { gEmy83Palette, sEmy83CommonAnimDefs, 192, 130, 20, 20, 50, 50, 50, 10, 0, { ENEMY_CREEPER_PLANT, 66, 35, 12, 24, 100, 0 } };

TaskDesc gTaskDescEmy83 = {
    "task_emy_83",
    (TaskInitFunc)task_emy_83_0,
    (TaskUpdateFunc)task_emy_83_1,
    (TaskDrawFunc)task_emy_83_2,
    (TaskDestroyFunc)task_emy_83_3,
    sizeof(Emy83Work),
};

static TaskDesc sTaskDescEmy83B = {
    "task_emy_83_b",
    (TaskInitFunc)task_emy_83_b_0,
    (TaskUpdateFunc)task_emy_83_b_1,
    (TaskDrawFunc)task_emy_83_b_2,
    (TaskDestroyFunc)task_emy_83_b_3,
    sizeof(Emy83bWork),
};

static TaskDesc sTaskDescEmy83S = {
    "task_emy_83_s",
    (TaskInitFunc)task_emy_83_s_0,
    (TaskUpdateFunc)task_emy_83_s_1,
    (TaskDrawFunc)task_emy_83_s_2,
    (TaskDestroyFunc)task_emy_83_s_3,
    sizeof(Emy83sWork),
};

enum Emy83State {
    EMY83_STATE_GROUND_STRIKE = 18,
    EMY83_STATE_SHOOT_WINDUP,
    EMY83_STATE_SHOOT,
    EMY83_STATE_SHOOT_END,
    EMY83_STATE_IDLE
};

void task_emy_83_0(Emy83Work* work, void* obj) {
    EmyInit(&work->base, &sEmy83Def, obj);
    work->task = NULL;
    work->base.idleState = EMY83_STATE_IDLE;
    TaskPoolInit(&work->tasks, 4);
}

u8 task_emy_83_1(Emy83Work* work) {
    Emy83Work* w;
    BtlObj* act;
    u16 roll;
    u16 animTimer;
    EmySpawn spawn;
    s32 targetX;
    s32 x;
    s32 y;
    s32 z;
    u8 alive;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->base.state = EMY83_STATE_GROUND_STRIKE;
            w->task = NULL;
            break;
        case 1:
            work->base.state = EMY83_STATE_SHOOT_WINDUP;
            w->shotCount = 0;
            break;
        }
    }

    switch (work->base.state) {
    case EMY83_STATE_IDLE:
        AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, ANIM_FLAG_LOOP | ANIM_FLAG_RANDOM_START, w->base.tiles);
        TryEnemyCardUse(act);
        GetEnemyTargetPosition(act, &targetX, NULL, NULL);

        if (act->x < targetX) {
            act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
        } else {
            act->flags |= BTLOBJ_FLAG_FACING_LEFT;
        }

        break;
    case EMY83_STATE_GROUND_STRIKE:
        AnimChangeWithDef(sEmy83AnimDefs, &w->base.anim, 0, 0, w->base.tiles);
        animTimer = work->base.anim.timer;

        if (animTimer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 3:
                GetEnemyTargetPosition(act, &w->targetX, &w->targetY, NULL);
                break;
            case 5:
                spawn.x = w->targetX;
                spawn.y = w->targetY;
                spawn.z = animTimer;
                w->task = TaskCreate(&w->tasks, &sTaskDescEmy83B, &spawn);
                break;
            }
        }

        if (AnimIsFinished(&work->base.anim) && !IsTaskActiveNamed(w->task, sTaskDescEmy83B.name)) {
            EmyReturnToIdle(&work->base);
        }

        break;
    case EMY83_STATE_SHOOT_WINDUP:
        AnimChangeWithDef(sEmy83AnimDefs, &w->base.anim, 1, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.state = EMY83_STATE_SHOOT;
        }

        break;
    case EMY83_STATE_SHOOT:
        AnimChangeWithDef(sEmy83AnimDefs, &w->base.anim, 2, ANIM_FLAG_LOOP, w->base.tiles);

        if (AnimGetGfxIndex(&work->base.anim) == 6 && work->base.anim.timer == 0) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                spawn.x = act->x - 0x1000;
                spawn.facingLeft = TRUE;
            } else {
                spawn.x = act->x + 0x1000;
                spawn.facingLeft = FALSE;
            }

            spawn.y = act->y;
            spawn.z = act->z - 0x1200;
            spawn.hitPhase = 0;
            TaskCreate(&w->tasks, &sTaskDescEmy83S, &spawn);
            spawn.hitPhase = 1;
            TaskCreate(&w->tasks, &sTaskDescEmy83S, &spawn);
            spawn.hitPhase = 2;
            TaskCreate(&w->tasks, &sTaskDescEmy83S, &spawn);
            w->shotCount++;
        }

        if (w->shotCount > 2 && AnimIsFinished(&work->base.anim)) {
            work->base.state = EMY83_STATE_SHOOT_END;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY83_STATE_SHOOT_END:
        AnimChangeWithDef(sEmy83AnimDefs, &w->base.anim, 3, 0, w->base.tiles);

        if (work->base.stateTimer > 0x28) {
            EmyReturnToIdle(&work->base);
        } else {
            work->base.stateTimer++;
        }

        break;
    }

    TaskPoolUpdate(&w->tasks);
    x = act->x;
    y = act->y;
    z = act->z;
    alive = EmyUpdateCommonStates(&work->base);

    if (work->base.state != EMY_STATE_SPAWN) {
        act->x = x;
        act->y = y;
        act->z = z;
    }

    return alive;
}

void task_emy_83_2(Emy83Work* work) {
    EmyDraw(&work->base);
    TaskPoolDraw(&work->tasks);
}

void task_emy_83_3(Emy83Work* work) {
    TaskPoolDestroy(&work->tasks);
    EmyReleaseResources(&work->base);
}

enum Emy83bState {
    EMY83B_STATE_EMERGE,
    EMY83B_STATE_STRIKE,
    EMY83B_STATE_RETRACT
};

void task_emy_83_b_0(Emy83bWork* work, EmySpawn* spawn) {
    work->state = EMY83B_STATE_EMERGE;
    work->palette = LoadObjPalette(gEmy83Palette, sizeof(gEmy83Palette));
    work->tiles = AllocObjTiles(0x80, gEmy8310bTiles);
    AnimInit(&work->anim, gEmy8310bAnims, gEmy8310bFrames);
    AnimStart(&work->anim, 0, 0);
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
    work->timer = 0;
    ColliderInit(&work->collider, COLLIDER_TYPE_SLIPPERY, 4, 0x10);
}

u8 task_emy_83_b_1(Emy83bWork* work) {
    if ((gBtlWork->flags & BTL_FLAG_OPPONENT_CARD_ACTION) == 0) {
        return 0;
    }

    switch (work->state) {
    case EMY83B_STATE_EMERGE:
        if (work->timer > 0x0F) {
            work->state = EMY83B_STATE_STRIKE;
            work->timer = 0;
        } else {
            work->timer++;
        }

        break;
    case EMY83B_STATE_STRIKE:
        if (work->timer == 0) {
            AnimStart(&work->anim, 1, 0);
        }

        if (AnimGetFrame(&work->anim) == 1 && work->anim.timer == 0) {
            if (ApplyAttackBox(0xE0, work->x, work->y, work->z, 4, 4, 0x10)) {
                m4aSongNumStart(SONG_BTL_HANE_HIT);
            }
        }

        if (work->timer > 0x1D) {
            work->state = EMY83B_STATE_RETRACT;
            work->timer = 0;
        } else {
            work->timer++;
        }

        break;
    case EMY83B_STATE_RETRACT:
    default:
        if (work->timer == 0) {
            AnimStart(&work->anim, 2, 0);
        }

        if (AnimIsFinished(&work->anim)) {
            return 0;
        }

        work->timer++;
        break;
    }

    ColliderSetPosition(&work->collider, work->x, work->y, work->z);
    AnimUpdate(&work->anim);
    return 1;
}

void task_emy_83_b_2(Emy83bWork* work) {
    void* gfx;
    u16 flags;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(&work->anim);
    flags = GetBattleSpritePriorityFlags(work->y);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, NULL, flags,
        -0x1004 - ((work->y + 0x400) >> 8) * 4);
}

void task_emy_83_b_3(Emy83bWork* work) {
    ColliderUnregister(&work->collider);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_emy_83_s_0(Emy83sWork* work, EmySpawn* spawn) {
    work->palette = LoadObjPalette(gEmy83Palette, sizeof(gEmy83Palette));
    work->tiles = LoadObjTiles(gEmy8311bTiles, sizeof(gEmy8311bTiles));
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
    work->vz = 0;
    work->frameCount = 0;

    if (spawn->facingLeft) {
        work->vx = -(GetRandom() % 0x4CE + 0x133);
    } else {
        work->vx = GetRandom() % 0x4CE + 0x133;
    }

    work->vy = GetRandom() % 0x201 - 0x100;
    work->hitPhase = spawn->hitPhase;
}

u8 task_emy_83_s_1(Emy83sWork* work) {
    s32 x;
    s32 y;

    if (gBtlWork->flags & BTL_FLAG_OPPONENT_CARD_ACTION) {
        x = work->x + work->vx;
        work->x = x;
        y = work->y + work->vy;
        work->y = y;

        if (work->frameCount % 3 == work->hitPhase) {
            if (ApplyAttackBox(0xE1, x, y, work->z, 2, 2, 2) != ATTACK_RESULT_NONE) {
                m4aSongNumStart(SONG_BTL_KAMITUKI);
            }
        }

        work->z += work->vz;
        work->vz += 0x14;

        if (work->z < 0) {
            work->frameCount++;
            return 1;
        }
    }

    return 0;
}

void task_emy_83_s_2(Emy83sWork* work) {
    u16 flags;
    s16 x;
    s16 y;

    flags = GetBattleSpritePriorityFlags(work->y);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gEmy8311bFrame0, work->tiles, work->palette, NULL, flags,
        -0x1004 - ((work->y + 0x400) >> 8) * 4);
    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, gEmy8311bFrame1, work->tiles, work->palette, NULL, flags, -2);
}

void task_emy_83_s_3(Emy83sWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}
