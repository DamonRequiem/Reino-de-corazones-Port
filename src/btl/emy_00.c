/**
 * emy_00.c
 * Shadow Enemy
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
#include "enemy_types.h"
#include "engine_math.h"
#include "game_state.h"
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy00CommonAnimDefs[3] = {
    { gEmy00L00Frames, gEmy00L00Anims, gEmy00L00Tiles, 0 },
    { gEmy00L09Frames, gEmy00L09Anims, gEmy00L09Tiles, 0 },
    { gEmy00L02Frames, gEmy00L02Anims, gEmy00L02Tiles, 0 },
};

static const AnimDef sEmy00AnimDefs[7] = {
    { gEmy00L07Frames, gEmy00L07Anims, gEmy00L07Tiles, 1 },
    { gEmy00L12Frames, gEmy00L12Anims, gEmy00L12Tiles, 0 },
    { gEmy00L06Frames, gEmy00L06Anims, gEmy00L06Tiles, 1 },
    { gEmy00L06Frames, gEmy00L06Anims, gEmy00L06Tiles, 0 },
    { gEmy00L04Frames, gEmy00L04Anims, gEmy00L04Tiles, 0 },
    { gEmy00L10Frames, gEmy00L10Anims, gEmy00L10Tiles, 0 },
    { gEmy00L11Frames, gEmy00L11Anims, gEmy00L11Tiles, 0 },
};

static const EmyDef sEmy00Def = { gEmy00Palette, sEmy00CommonAnimDefs, 384, 130, 10, 20, 64, 32, 16, 10, EMY_DEF_FLAG_NO_SHADOW | EMY_DEF_FLAG_NO_SCALE_IN, { ENEMY_SHADOW, 12, 32, 12, 16, 100, 0 } };

TaskDesc gTaskDescEmy00 = {
    "task_emy_00",
    (TaskInitFunc)task_emy_00_0,
    (TaskUpdateFunc)task_emy_00_1,
    (TaskDrawFunc)task_emy_00_2,
    (TaskDestroyFunc)task_emy_00_3,
    sizeof(EmyWork),
};

enum Emy00State {
    EMY00_STATE_IDLE = 18,
    EMY00_STATE_SINK,
    EMY00_STATE_SUNK_MOVE,
    EMY00_STATE_RISE,
    EMY00_STATE_SPAWN,
    EMY00_STATE_LUNGE = 24,
    EMY00_STATE_JUMP_LUNGE
};

void task_emy_00_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy00Def, obj);
    work->flags |= EMY_FLAG_DARK_DEATH;
    work->idleState = EMY00_STATE_IDLE;
    work->state = EMY00_STATE_SPAWN;
}

u8 task_emy_00_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 roll;
    s32 sunkTargetX;
    s32 idleTargetX;
    u8 alive;

    w = work;
    act = &work->actor;

    if (EmyUpdateReaction(work)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->state = EMY00_STATE_LUNGE;
            break;
        case 1:
            work->state = EMY00_STATE_JUMP_LUNGE;
            break;
        }
    }

    switch (w->state) {
    case EMY00_STATE_LUNGE:
        AnimChangeWithDef(sEmy00AnimDefs, &work->anim, 5, 0, work->tiles);
        EmyLungeAttack(w, 31, 18, 11, 165, 40, SONG_BTL_MON_HIT00, 0, 0, 24);
        break;
    case EMY00_STATE_JUMP_LUNGE:
        AnimChangeWithDef(sEmy00AnimDefs, &work->anim, 6, 0, work->tiles);

        if (w->stateTimer == 10) {
            w->vz = -0x400;
        }

        EmyLungeAttack(w, 14, 35, 10, 166, 96, SONG_BTL_MON_HIT00, 0, 0, 24);
        break;
    case EMY00_STATE_SINK:
        AnimChangeWithDef(sEmy00AnimDefs, &work->anim, 0, 0, work->tiles);

        if (AnimIsFinished(&w->anim)) {
            w->state = EMY00_STATE_SUNK_MOVE;
            ColliderSetDisabled(&act->collider, TRUE);
            act->flags |= BTLOBJ_FLAG_INTANGIBLE;
            act->centerHeight = 0;
        }

        break;
    case EMY00_STATE_SUNK_MOVE:
        if (gBtlWork->flags & BTL_FLAG_ENEMY_MOVE_ENABLED) {
            GetEnemyTargetPosition(act, &sunkTargetX, NULL, NULL);
            AnimChangeWithDef(sEmy00AnimDefs, &work->anim, 1, ANIM_FLAG_LOOP, work->tiles);
            act->x += gSineTable[w->angle] * w->speed >> 8;
            act->y += -gSineTable[w->angle + 64] * w->speed >> 8;

            if (w->stateTimer > 100) {
                w->state = EMY00_STATE_RISE;
                ColliderSetDisabled(&act->collider, FALSE);
                act->flags &= ~BTLOBJ_FLAG_INTANGIBLE;
                act->centerHeight = 16;
                w->stateTimer = 0;
            } else {
                w->stateTimer++;
            }

            if (act->x > sunkTargetX) {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }
        }

        break;
    case EMY00_STATE_SPAWN:
        AnimChangeWithDef(sEmy00AnimDefs, &work->anim, 3, 0, work->tiles);

        if (w->stateTimer == 20) {
            act->flags &= ~BTLOBJ_FLAG_INTANGIBLE;

            if (gGameState.flags & GAME_FLAG_FIRST_STRIKE) {
                EmyFinishSpawn(w);
                break;
            }
        }

        if (AnimIsFinished(&w->anim)) {
            EmyFinishSpawn(w);
            break;
        }

        w->stateTimer++;
        break;
    case EMY00_STATE_RISE:
        AnimChangeWithDef(sEmy00AnimDefs, &work->anim, 2, 0, work->tiles);

        if (w->stateTimer == 30) {
            act->flags &= ~BTLOBJ_FLAG_INTANGIBLE;
        }

        if (AnimIsFinished(&w->anim)) {
            act->flags &= ~(BTLOBJ_FLAG_INTANGIBLE | BTLOBJ_FLAG_CARD_USE_BLOCKED);
            w->state = EMY00_STATE_IDLE;
#ifdef VERSION_EU
            w->stateTimer = 0;
#endif
        } else {
            w->stateTimer++;
        }

        break;
    case EMY00_STATE_IDLE:
        if (w->stateTimer == 0) {
            ColliderSetDisabled(&act->collider, FALSE);
            act->flags &= ~(BTLOBJ_FLAG_INTANGIBLE | BTLOBJ_FLAG_CARD_USE_BLOCKED);
            AnimChangeWithDef(work->def->animDef, &work->anim, 0, ANIM_FLAG_LOOP | ANIM_FLAG_RANDOM_START,
                work->tiles);
        }

        TryEnemyCardUse(act);

        if (GetRandom() % 120 == 0) {
            w->state = EMY_STATE_WALK;

            if (GetRandom() % 2 == 0) {
                w->x = -((act->attackOffset
                    + (-act->attackRangeX
                        + GetRandom() % (act->attackRangeX - -act->attackRangeX + 1)))
                    << 8);
            } else {
                w->x = (act->attackOffset
                    + (-act->attackRangeX
                        + GetRandom() % (act->attackRangeX - -act->attackRangeX + 1)))
                    << 8;
            }
        } else if (GetRandom() % 200 == 0) {
            w->state = EMY00_STATE_SINK;
            act->flags |= BTLOBJ_FLAG_CARD_USE_BLOCKED;
            w->angle = GetRandom();
            w->stateTimer = 0;
            break;
        }

        if (GetRandom() % w->def->turnInterval == 0) {
            GetEnemyTargetPosition(act, &idleTargetX, NULL, NULL);

            if (act->x > idleTargetX) {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }
        }

        w->stateTimer++;
        break;
    }

    alive = EmyUpdateCommonStates(w);

    if (w->state == EMY_STATE_FLEE) {
        AnimChangeWithDef(sEmy00AnimDefs, &work->anim, 4, ANIM_FLAG_LOOP, work->tiles);
    }

    return alive;
}

void task_emy_00_2(EmyWork* work) {
    BtlObj* act;
    u16 flags;
    ObjAffine* affine;
    s32 sx;
    s32 sy;
    s32 scaleY;
    s16 x;
    s16 y;

    if (work->visible) {
        act = &work->actor;
        flags = GetBattleSpritePriorityFlags(act->y) | work->spriteFlags;
        WorldToScreen(&x, &y, act->x, act->y, act->z);
        scaleY = work->scaleY;

        if (scaleY == Q_8_8(1)) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                sy = gBtlWork->scale;
                sx = sy;
            } else if (gBtlWork->scale == scaleY) {
                sy = scaleY;
                sx = sy;
                flags |= SPRITE_FLAG_HFLIP;
            } else {
                sx = -gBtlWork->scale;
                sy = gBtlWork->scale;
            }
        } else {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                sx = gBtlWork->scale * work->scaleX >> 8;
                sy = gBtlWork->scale;
            } else {
                sx = -(gBtlWork->scale * work->scaleX >> 8);
                sy = gBtlWork->scale;
            }

            sy = sy * scaleY >> 8;
        }

        if (sy == Q_8_8(1) && sx == sy) {
            affine = NULL;
        } else if (sy <= 0xFF) {
            affine = AllocObjAffine(0, sx, sy, FALSE);
        } else {
            affine = AllocObjAffine(0, sx, sy, TRUE);
        }

        if (StepHitFlash(act)) {
            DrawSprite(x, y, work->gfx, work->tiles, work->palette2, affine, flags,
                -0x1004 - (act->y >> 8) * 4);
        } else if (work->state == EMY00_STATE_SUNK_MOVE) {
            DrawSprite(x, y, work->gfx, work->tiles, work->palette, affine, flags, 0xFFFF);
        } else {
            DrawSprite(x, y, work->gfx, work->tiles, work->palette, affine, flags,
                -0x1004 - (act->y >> 8) * 4);
        }

        TaskPoolDraw(&work->tasks);
    }
}

void task_emy_00_3(EmyWork* work) {
    EmyReleaseResources(work);
}
