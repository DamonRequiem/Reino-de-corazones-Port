/**
 * emy_37.c
 * Neoshadow Enemy
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

static const AnimDef sEmy37CommonAnimDefs[3] = {
    { gEmy3700Frames, gEmy3700Anims, gEmy3700Tiles, 0 },
    { gEmy3702Frames, gEmy3702Anims, gEmy3702Tiles, 0 },
    { gEmy3701Frames, gEmy3701Anims, gEmy3701Tiles, 0 },
};

static const AnimDef sEmy37AnimDefs[11] = {
    { gEmy3710Frames, gEmy3710Anims, gEmy3710Tiles, 0 },
    { gEmy3711Frames, gEmy3711Anims, gEmy3711Tiles, 0 },
    { gEmy3711Frames, gEmy3711Anims, gEmy3711Tiles, 1 },
    { gEmy3711Frames, gEmy3711Anims, gEmy3711Tiles, 2 },
    { gEmy3711Frames, gEmy3711Anims, gEmy3711Tiles, 3 },
    { gEmy3720Frames, gEmy3720Anims, gEmy3720Tiles, 0 },
    { gEmy3720Frames, gEmy3720Anims, gEmy3720Tiles, 1 },
    { gEmy3720Frames, gEmy3720Anims, gEmy3720Tiles, 2 },
    { gEmy3720Frames, gEmy3720Anims, gEmy3720Tiles, 3 },
    { gEmy3721Frames, gEmy3721Anims, gEmy3721Tiles, 0 },
    { gEmy3721Frames, gEmy3721Anims, gEmy3721Tiles, 1 },
};

static const EmyDef sEmy37Def = { gEmy37Palette, sEmy37CommonAnimDefs, 409, 130, 20, 20, 64, 32, 32, 10, EMY_DEF_FLAG_NO_SHADOW | EMY_DEF_FLAG_NO_SCALE_IN, { ENEMY_NEOSHADOW, 110, 38, 12, 20, 100, 0 } };

TaskDesc gTaskDescEmy37 = {
    "task_emy_37",
    (TaskInitFunc)task_emy_37_0,
    (TaskUpdateFunc)task_emy_37_1,
    (TaskDrawFunc)task_emy_37_2,
    (TaskDestroyFunc)task_emy_37_3,
    sizeof(Emy37Work),
};

enum Emy37State {
    EMY37_STATE_IDLE = 18,
    EMY37_STATE_SINK,
    EMY37_STATE_SUNK_MOVE,
    EMY37_STATE_RISE,
    EMY37_STATE_LUNGE = 24,
    EMY37_STATE_AMBUSH_RISE,
    EMY37_STATE_RISE_JUMP,
    EMY37_STATE_RISE_FALL,
    EMY37_STATE_SPAWN,
    EMY37_STATE_AMBUSH_LEAP,
    EMY37_STATE_AMBUSH_GLIDE
};

void task_emy_37_0(Emy37Work* work, void* obj) {
    EmyInit(&work->base, &sEmy37Def, obj);
    work->base.flags |= EMY_FLAG_DARK_DEATH;
    work->base.idleState = EMY37_STATE_IDLE;
    work->base.state = EMY37_STATE_SPAWN;
    work->rotation = 0;
}

u8 task_emy_37_1(Emy37Work* work) {
    Emy37Work* w;
    BtlObj* act;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        if (work->base.state == EMY37_STATE_SUNK_MOVE) {
            work->rotation = 0;
            act->flags &= ~BTLOBJ_FLAG_INTANGIBLE;
            work->base.state = EMY37_STATE_AMBUSH_RISE;
            work->base.actor.centerHeight = 20;
        } else {
            work->base.state = EMY37_STATE_LUNGE;
        }
    }

    switch (work->base.state) {
    case EMY37_STATE_LUNGE:
        AnimChangeWithDef(sEmy37AnimDefs, &w->base.anim, 0, 0, w->base.tiles);
        EmyLungeAttack(&work->base, 30, 14, 20, 0xD2, 70, SONG_BTL_MON_HIT00, 0, 0, 24);
        break;
    case EMY37_STATE_AMBUSH_RISE:
        AnimChangeWithDef(sEmy37AnimDefs, &w->base.anim, 4, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = EMY37_STATE_AMBUSH_LEAP;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY37_STATE_AMBUSH_LEAP:
        if (work->base.stateTimer == 0) {
            work->base.vz = -0x399;
            AnimChangeWithDef(sEmy37AnimDefs, &w->base.anim, 1, 0, w->base.tiles);
        }

        if (work->base.vz > 0) {
            work->base.vz = 0;
        }

        if (ApplyAttackBox(0xD3, act->x, act->y, act->z, 16, 8, 32)) {
            m4aSongNumStart(SONG_BTL_MON_HIT00);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = EMY37_STATE_AMBUSH_GLIDE;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY37_STATE_AMBUSH_GLIDE:
        if (work->base.stateTimer == 0) {
            s32 x;
            s32 y;

            AnimChangeWithDef(sEmy37AnimDefs, &w->base.anim, 2, ANIM_FLAG_LOOP, w->base.tiles);
            w->speed = 0;
            GetEnemyTargetPosition(act, &x, &y, NULL);
            w->angle = GetAngle(act->x, act->y, x, y);
        }

        if (((u16)work->base.stateTimer % 4) == 0) {
            u8 angle;
            s32 x;
            s32 y;

            GetEnemyTargetPosition(act, &x, &y, NULL);
            angle = GetAngle(act->x, act->y, x, y);
            ApproachAngle(&w->angle, angle, 4);
        }

        act->x += gSineTable[(u8)w->angle] * (s32)w->speed >> 8;
        act->y += -gSineTable[(u8)w->angle + 64] * (s32)w->speed >> 8;
        w->speed += 12;

        if (ApplyAttackBox(0xD3, act->x, act->y, act->z, 32, 16, 16)) {
            m4aSongNumStart(SONG_BTL_MON_HIT00);
            work->base.stateTimer = 120;
        }

        work->base.vz = 0;

        if (work->base.stateTimer > 120) {
            EmyReturnToIdle(&work->base);
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY37_STATE_SPAWN:
        AnimChangeWithDef(sEmy37AnimDefs, &w->base.anim, 10, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            act->flags &= ~BTLOBJ_FLAG_INTANGIBLE;
            EmyFinishSpawn(&work->base);
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY37_STATE_SINK:
        AnimChangeWithDef(sEmy37AnimDefs, &w->base.anim, 9, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.state = EMY37_STATE_SUNK_MOVE;
            ColliderSetDisabled(&act->collider, TRUE);
            act->flags |= BTLOBJ_FLAG_INTANGIBLE;
            act->centerHeight = 0;
        }

        break;
    case EMY37_STATE_SUNK_MOVE:
        if (gBtlWork->flags & BTL_FLAG_ENEMY_MOVE_ENABLED) {
            s32 x;
            s32 y;
            s32 dx;
            s32 dy;
            s32 sample;
            s32 offset;

            GetEnemyTargetPosition(act, &x, &y, NULL);
            AnimChangeWithDef(sEmy37AnimDefs, &w->base.anim, 5, ANIM_FLAG_LOOP, w->base.tiles);
            sample = gSineTable[work->base.angle];
            offset = 70;
            offset *= sample;
            dx = x + offset;
            dy = y + -gSineTable[work->base.angle + 64] * 35;
            dx -= act->x;
            dx >>= 4;
            dy -= act->y;
            dy >>= 4;

            if (dx > 0x300) {
                dx = 0x300;
            } else if (dx < -0x300) {
                dx = -0x300;
            }

            if (dy > 0x300) {
                dy = 0x300;
            } else if (dy < -0x300) {
                dy = -0x300;
            }

            act->x += dx;
            act->y += dy;

            if (work->base.stateTimer == 0) {
                act->flags &= ~BTLOBJ_FLAG_CARD_USE_BLOCKED;
            }

            TryEnemyCardUse(act);

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                work->base.angle -= 2;
                w->rotation = work->base.angle;
            } else {
                work->base.angle += 2;
                w->rotation = -work->base.angle;
            }

            if (work->base.stateTimer > 160) {
                w->rotation = 0;
                work->base.state = EMY37_STATE_RISE;
                ColliderSetDisabled(&act->collider, FALSE);
                act->flags &= ~BTLOBJ_FLAG_INTANGIBLE;
                act->centerHeight = 20;
                act->flags |= BTLOBJ_FLAG_CARD_USE_BLOCKED;
                work->base.stateTimer = 0;
            } else {
                work->base.stateTimer++;
            }
        }

        break;
    case EMY37_STATE_RISE:
        AnimChangeWithDef(sEmy37AnimDefs, &w->base.anim, 6, 0, w->base.tiles);

        if (work->base.stateTimer == 30) {
            act->flags &= ~BTLOBJ_FLAG_INTANGIBLE;
        }

        if (AnimIsFinished(&work->base.anim)) {
            act->flags &= ~(BTLOBJ_FLAG_INTANGIBLE | BTLOBJ_FLAG_CARD_USE_BLOCKED);
            work->base.state = EMY37_STATE_RISE_JUMP;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY37_STATE_RISE_JUMP:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sEmy37AnimDefs, &w->base.anim, 7, 0, w->base.tiles);
            work->base.vz = -0x433;
        }

        if (work->base.vz > 0) {
            work->base.state = EMY37_STATE_RISE_FALL;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY37_STATE_RISE_FALL:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sEmy37AnimDefs, &w->base.anim, 8, 0, w->base.tiles);
        }

        if (act->z >= act->groundZ) {
            work->base.state = EMY37_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY37_STATE_IDLE:
        if (work->base.stateTimer == 0) {
            act->centerHeight = 20;
            ColliderSetDisabled(&act->collider, FALSE);
            act->flags &= ~(BTLOBJ_FLAG_INTANGIBLE | BTLOBJ_FLAG_CARD_USE_BLOCKED);
            AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, ANIM_FLAG_LOOP | ANIM_FLAG_RANDOM_START, w->base.tiles);
        }

        TryEnemyCardUse(act);

        if ((u16)(GetRandom() % 200U) == 0) {
            work->base.state = EMY_STATE_WALK;

            if (GetRandom() % 2 == 0) {
                work->base.x = -((act->attackOffset
                    + (-act->attackRangeX + GetRandom() % (act->attackRangeX - -act->attackRangeX + 1))) * 256);
            } else {
                work->base.x = (act->attackOffset
                    + (-act->attackRangeX + GetRandom() % (act->attackRangeX - -act->attackRangeX + 1))) * 256;
            }

            break;
        } else if ((u16)(GetRandom() % 100U) == 0) {
            work->base.state = EMY37_STATE_SINK;
            act->flags |= BTLOBJ_FLAG_CARD_USE_BLOCKED;
            work->base.angle = GetRandom();
            work->base.stateTimer = 0;
            break;
        }

        if ((u16)((u32)GetRandom() % work->base.def->turnInterval) == 0) {
            s32 x;

            GetEnemyTargetPosition(act, &x, NULL, NULL);

            if (act->x > x) {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }
        }

        work->base.stateTimer++;
        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_37_2(Emy37Work* work) {
    Emy37Work* w;
    BtlObj* act;
    u16 flags;
    ObjAffine* affine;
    s32 sx;
    s32 sy;
    s32 scaleY;
    s16 x;
    s16 y;

    w = work;

    if (work->base.visible) {
        act = &work->base.actor;
        flags = GetBattleSpritePriorityFlags(act->y) | work->base.spriteFlags;
        WorldToScreen(&x, &y, act->x, act->y, act->z);

        scaleY = work->base.scaleY;

        if (scaleY == Q_8_8(1)) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                sy = gBtlWork->scale;
                sx = sy;
            } else if (work->rotation == 0 && gBtlWork->scale == scaleY) {
                sy = scaleY;
                sx = sy;
                flags |= SPRITE_FLAG_HFLIP;
            } else {
                sx = -gBtlWork->scale;
                sy = gBtlWork->scale;
            }
        } else {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                sx = gBtlWork->scale * work->base.scaleX >> 8;
                sy = gBtlWork->scale;
            } else {
                sx = -(gBtlWork->scale * work->base.scaleX >> 8);
                sy = gBtlWork->scale;
            }

            sy = sy * scaleY >> 8;
        }

        if (w->rotation) {
            affine = AllocObjAffine(w->rotation, sx, sy, TRUE);
        } else if (sy == Q_8_8(1) && sx == sy) {
            affine = NULL;
        } else if (sy <= 0xFF) {
            affine = AllocObjAffine(0, sx, sy, FALSE);
        } else {
            affine = AllocObjAffine(0, sx, sy, TRUE);
        }

        if (StepHitFlash(act)) {
            DrawSprite(x, y, work->base.gfx, work->base.tiles, work->base.palette2, affine,
                flags, -0x1004 - (act->y >> 8) * 4);
        } else if (work->base.state == EMY37_STATE_SUNK_MOVE) {
            DrawSprite(x, y, work->base.gfx, work->base.tiles, work->base.palette, affine,
                flags, 0xFFFF);
        } else {
            DrawSprite(x, y, work->base.gfx, work->base.tiles, work->base.palette, affine,
                flags, -0x1004 - (act->y >> 8) * 4);
        }

        TaskPoolDraw(&work->base.tasks);
    }
}

void task_emy_37_3(EmyWork* work) {
    EmyReleaseResources(work);
}
