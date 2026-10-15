/**
 * emy_16.c
 * Bouncywild Enemy
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
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy16CommonAnimDefs[3] = {
    { gEmy1600Frames, gEmy1600Anims, gEmy1600Tiles, 0 },
    { gEmy1602Frames, gEmy1602Anims, gEmy1602Tiles, 0 },
    { gEmy1601Frames, gEmy1601Anims, gEmy1601Tiles, 0 },
};

static const AnimDef sEmy16AnimDefs[2] = {
    { gEmy1610Frames, gEmy1610Anims, gEmy1610Tiles, 0 },
    { gEmy1611Frames, gEmy1611Anims, gEmy1611Tiles, 0 },
};

static const EmyDef sEmy16Def = { gEmy16Palette, sEmy16CommonAnimDefs, 307, 130, 20, 20, 99, 32, 32, 10, 0, { ENEMY_BOUNCYWILD, 29, 16, 8, 16, 100, 0 } };

TaskDesc gTaskDescEmy16 = {
    "task_emy_16",
    (TaskInitFunc)task_emy_16_0,
    (TaskUpdateFunc)task_emy_16_1,
    (TaskDrawFunc)task_emy_16_2,
    (TaskDestroyFunc)task_emy_16_3,
    sizeof(Emy16Work),
};

static TaskDesc sTaskDescEmy16B = {
    "task_emy_16_b",
    (TaskInitFunc)task_emy_16_b_0,
    (TaskUpdateFunc)task_emy_16_b_1,
    (TaskDrawFunc)task_emy_16_b_2,
    (TaskDestroyFunc)task_emy_16_b_3,
    sizeof(Emy16bWork),
};

static TaskDesc sTaskDescEmy16P = {
    "task_emy_16_p",
    (TaskInitFunc)task_emy_16_p_0,
    (TaskUpdateFunc)task_emy_16_p_1,
    (TaskDrawFunc)task_emy_16_p_2,
    (TaskDestroyFunc)task_emy_16_p_3,
    sizeof(Emy16pWork),
};

void task_emy_16_0(Emy16Work* work, void* obj) {
    EmyInit(&work->base, &sEmy16Def, obj);
    work->pTask = NULL;
    work->bTask = NULL;
    TaskPoolInit(&work->tasks, 2);
}

enum Emy16State {
    EMY16_STATE_SHOOT = 18,
    EMY16_STATE_THROW_TRAP
};

u8 task_emy_16_1(Emy16Work* work) {
    Emy16Work* w;
    BtlObj* act;
    EmySpawn spawn;
    u16 roll;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        if (IsTaskActiveNamed(work->bTask, sTaskDescEmy16B.name)) {
            work->base.state = EMY16_STATE_SHOOT;
        } else {
            roll = GetRandom();

            switch (roll & 1) {
            case 0:
                work->base.state = EMY16_STATE_SHOOT;
                break;
            case 1:
                work->base.state = EMY16_STATE_THROW_TRAP;
                break;
            }
        }

        w->pTaskStarted = FALSE;
    }

    switch (work->base.state) {
    case EMY16_STATE_SHOOT:
        AnimChangeWithDef(sEmy16AnimDefs, &w->base.anim, 0, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 3 && work->base.anim.timer == 0) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                spawn.x = act->x - 0x1000;
                spawn.y = act->y;
                spawn.z = act->z - 0x1000;
                spawn.facingLeft = TRUE;
            } else {
                spawn.x = act->x + 0x1000;
                spawn.y = act->y;
                spawn.z = act->z - 0x1000;
                spawn.facingLeft = FALSE;
            }

            w->pTask = TaskCreate(&w->tasks, &sTaskDescEmy16P, &spawn);
            w->pTaskStarted = TRUE;
        }

        if (w->pTaskStarted) {
            if (!IsTaskActiveNamed(w->pTask, sTaskDescEmy16P.name)) {
                EmyReturnToIdle(&work->base);
            }
        }

        break;
    case EMY16_STATE_THROW_TRAP:
        AnimChangeWithDef(sEmy16AnimDefs, &w->base.anim, 1, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 0x0A && work->base.anim.timer == 0) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                spawn.x = act->x - 0xC00;
                spawn.y = act->y;
                spawn.z = act->z - 0x200;
                spawn.facingLeft = TRUE;
            } else {
                spawn.x = act->x + 0xC00;
                spawn.y = act->y;
                spawn.z = act->z - 0x200;
                spawn.facingLeft = FALSE;
            }

            w->bTask = TaskCreate(&w->tasks, &sTaskDescEmy16B, &spawn);
        }

        if (AnimIsFinished(&work->base.anim)) {
            EmyReturnToIdle(&work->base);
        }

        break;
    }

    TaskPoolUpdate(&w->tasks);
    return EmyUpdateCommonStates(&work->base);
}

void task_emy_16_2(Emy16Work* work) {
    EmyDraw(&work->base);
    TaskPoolDraw(&work->tasks);
}

void task_emy_16_3(Emy16Work* work) {
    EmyReleaseResources(&work->base);
    TaskPoolDestroy(&work->tasks);
}

enum Emy16bState {
    EMY16B_STATE_THROWN,
    EMY16B_STATE_LANDED,
    EMY16B_STATE_TRIGGERED,
    EMY16B_STATE_FADE_OUT
};

void task_emy_16_b_0(Emy16bWork* work, EmySpawn* spawn) {
    if (spawn->facingLeft) {
        work->facingLeft = TRUE;
    } else {
        work->facingLeft = FALSE;
    }

    work->palette = LoadObjPalette(gEmy16Palette, sizeof(gEmy16Palette));
    work->tiles = AllocObjTiles(0x80, gEmy1611bTiles);
    AnimInit(&work->anim, gEmy1611bAnims, gEmy1611bFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
    work->state = EMY16B_STATE_THROWN;
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
    work->vx = 0x200;
    work->vz = -0x34C;
    work->timer = 0;
    work->visible = TRUE;
    work->bounced = FALSE;
    ColliderInit(&work->collider, COLLIDER_TYPE_SLIPPERY, 4, 3);
    ColliderSetDisabled(&work->collider, TRUE);
}

u8 task_emy_16_b_1(Emy16bWork* work) {
    switch (work->state) {
    case EMY16B_STATE_THROWN:
        if (work->facingLeft) {
            work->x -= work->vx;
        } else {
            work->x += work->vx;
        }

        if (ClampBattlePosition(&work->x, &work->y, -0x10, 0) != BATTLE_EDGE_NONE) {
            work->vx = -work->vx;
        }

        if (!work->bounced
                && TestAttackBox(work->x, work->y, work->z, 4, 4, 4)) {
            work->vx = -(work->vx >> 1);
            work->bounced = TRUE;
        }

        if (work->z >= 0) {
            work->state = EMY16B_STATE_LANDED;
            work->timer = 0;
        }

        break;
    case EMY16B_STATE_LANDED:
        if (work->timer == 0) {
            ColliderSetDisabled(&work->collider, FALSE);
            AnimStart(&work->anim, 1, ANIM_FLAG_LOOP);
        }

        if (work->collider.colliding) {
            work->timer = 0;
            work->state = EMY16B_STATE_TRIGGERED;
            ColliderSetDisabled(&work->collider, TRUE);
        } else if (work->timer > 0x64) {
            work->timer = 0;
            work->state = EMY16B_STATE_FADE_OUT;
        } else {
            work->timer++;
        }

        break;
    case EMY16B_STATE_TRIGGERED:
        if (work->timer != 0) {
            if (work->z >= 0) {
                work->timer = 0;
                work->state = EMY16B_STATE_FADE_OUT;
                break;
            }
        } else {
            AnimStart(&work->anim, 2, ANIM_FLAG_LOOP);
            work->vz = -0x3CC;
        }

        work->timer++;
        break;
    case EMY16B_STATE_FADE_OUT:
        if ((work->timer & 3) == 0) {
            work->visible = work->visible == FALSE;
        }

        if (work->collider.colliding) {
            work->timer = 0;
            work->state = EMY16B_STATE_TRIGGERED;
            ColliderSetDisabled(&work->collider, TRUE);
            work->visible = TRUE;
        } else if (work->timer > 0x3C) {
            return 0;
        } else {
            work->timer++;
        }

        break;
    }

    work->z += work->vz;
    work->vz += 0x33;

    if (work->z >= 0) {
        work->vz = 0;
        work->z = 0;
    }

    ColliderSetPosition(&work->collider, work->x, work->y, work->z);
    AnimUpdate(&work->anim);
    return 1;
}

void task_emy_16_b_2(Emy16bWork* work) {
    void* gfx;
    u16 flags;
    ObjAffine* affine;
    s32 scale;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(&work->anim);

    if (work->visible) {
        flags = GetBattleSpritePriorityFlags(work->y);
        WorldToScreen(&x, &y, work->x, work->y, work->z);
        scale = gBtlWork->scale;

        if (scale == Q_8_8(1)) {
            affine = NULL;

            if (!work->facingLeft) {
                flags |= SPRITE_FLAG_HFLIP;
            }
        } else if (!work->facingLeft) {
            affine = AllocObjAffine(0, -scale, scale, TRUE);
        } else {
            affine = AllocObjAffine(0, scale, scale, TRUE);
        }

        DrawSprite(x, y, gfx, work->tiles, work->palette, affine, flags,
            -0x1004 - (work->y >> 8) * 4);
    }
}

void task_emy_16_b_3(Emy16bWork* work) {
    ColliderUnregister(&work->collider);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_emy_16_p_0(Emy16pWork* work, EmySpawn* spawn) {
    if (spawn->facingLeft) {
        work->facingLeft = TRUE;
    } else {
        work->facingLeft = FALSE;
    }

    work->palette = LoadObjPalette(gEmy16Palette, sizeof(gEmy16Palette));
    work->tiles = AllocObjTiles(0x80, gEmy1610bTiles);
    AnimInit(&work->anim, gEmy1610bAnims, gEmy1610bFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
    work->vz = 0;
}

u8 task_emy_16_p_1(Emy16pWork* work) {
    if ((gBtlWork->flags & BTL_FLAG_OPPONENT_CARD_ACTION) == 0) {
        return 0;
    }

    if (work->facingLeft) {
        work->x -= 0x400;
    } else {
        work->x += 0x400;
    }

    if (ApplyAttackBox(0xB7, work->x, work->y, work->z, 4, 4, 4) != ATTACK_RESULT_NONE) {
        m4aSongNumStart(SONG_BTL_BW_PACHIN);
    }

    if (ClampBattlePosition(&work->x, &work->y, 0x10, 0) != BATTLE_EDGE_NONE) {
        return 0;
    }

    work->z += work->vz;
    work->vz += 0x2E;

    if (work->z >= 0) {
        work->vz = -0x400;
        work->z = 0;
    }

    AnimUpdate(&work->anim);
    return 1;
}

void task_emy_16_p_2(Emy16pWork* work) {
    void* gfx;
    u16 flags;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(&work->anim);
    flags = GetBattleSpritePriorityFlags(work->y);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, NULL, flags,
        -0x1004 - ((work->y + 0x1000) >> 8) * 4);
}

void task_emy_16_p_3(Emy16pWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}
