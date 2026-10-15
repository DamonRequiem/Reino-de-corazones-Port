/**
 * bos_lst_bit.c
 * Marluxia Final Form Laser Bits
 */

#include "bos7.h"
#include "sprites_bos7.h"
#include "sprites_bos6.h"
#include "boss_lst_data.h"
#include "songs.h"
#include <stdlib.h>
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "bos7_api.h"
#include "btl_collision.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "obj.h"
#include "obj_api.h"
#include "registration_data.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const EmyKind sBosLstBitEmyKind = { ENEMY_SHADOW, 1, 8, 8, 0, 128, 0 };

static const s32 sBosLstBitTanTable[32] = {
    6, 12, 18, 25, 31, 37, 44, 50, 57, 64, 70, 77, 84, 91, 98, 106,
    113, 121, 128, 136, 145, 153, 162, 171, 180, 189, 199, 210, 220, 232, 243, 256,
};

static const s32 sBosLstBitHoverY[3] = { 0, -8, 8 };

static const s32 sBosLstBitBobZ[16] = { -1, -2, -3, -4, -5, -6, -7, -8, -7, -6, -5, -4, -3, -2, -1, 0 };

static LstAnimSet sLstAnimSets[4] = {
    { 5, 0, 4, 5 },
    { 5, 0, 4, 12 },
    { 5, 0, 4, 13 },
    { 5, 0, 4, 14 },
};

TaskDesc gTaskDescBosLstBit = {
    "task_bos_lst_bit",
    (TaskInitFunc)task_bos_lst_bit_0,
    (TaskUpdateFunc)task_bos_lst_bit_1,
    (TaskDrawFunc)task_bos_lst_bit_2,
    (TaskDestroyFunc)task_bos_lst_bit_3,
    sizeof(LstState),
};

s32 BosLstBitSquare(s32 x) {
    return x * x;
}

s32 BosLstBitSquare2(s32 x) {
    return x * x;
}

u8 BosLstBitSpawnFal(LstState* work, s32 atTarget) {
    LstFalArg arg;
    u8 spawned;

    spawned = FALSE;

    if (work->kind != BOS_LST_BIT_KIND_BITS) {
        return FALSE;
    }

    if ((s16)*work->falCount <= 31) {
        arg.kind = BOS_LST_FAL_DRIFT;

        if (atTarget == TRUE) {
            arg.x = work->targetX;
            arg.y = work->targetY;
            arg.z = work->targetZ;
        } else {
            arg.x = work->x;
            arg.y = work->y;
            arg.z = work->z;
        }

        arg.facing = *work->facing;
        arg.falCount = work->falCount;
        TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosLstFal, &arg);
        spawned = TRUE;
    }

    return spawned;
}

enum BosLstBitState {
    BOS_LST_BIT_STATE_ENTER,
    BOS_LST_BIT_STATE_HOVER,
    BOS_LST_BIT_STATE_CHARGE,
    BOS_LST_BIT_STATE_FIRE,
    BOS_LST_BIT_STATE_IMPACT,
    BOS_LST_BIT_STATE_RETURN,
    BOS_LST_BIT_STATE_HIDDEN,
    BOS_LST_BIT_STATE_INTERRUPTED
};

u8 BosLstBitIsAlive(Task* task) {
    LstState* work;
    u8 alive;

    work = task->work;
    alive = TRUE;

    if (work->obj.hp <= 0 || work->state == BOS_LST_BIT_STATE_HIDDEN) {
        alive = FALSE;
    }

    return alive;
}

u8 BosLstBitHasShots(Task* task) {
    LstState* work;
    u8 hasShots;

    work = task->work;
    hasShots = BosLstBitIsAlive(task);

    if (hasShots == TRUE && work->shots <= 0) {
        hasShots = FALSE;
    }

    return hasShots;
}

#ifdef VERSION_EU
u8 BosLstBitIsScaling(Task* task) {
    LstState* work;
    u8 scaling;
    work = task->work;
    scaling = BosLstBitIsAlive(task);

    if (scaling == TRUE && (work->scaleX == Q_8_8(1) || work->scaleY == Q_8_8(1))) {
        scaling = FALSE;
    }

    return scaling;
}
#endif

s16 BosLstBitMarkFirstAlive(Task* task, s16 found) {
    LstState* work;

    work = task->work;

    if (BosLstBitIsAlive(task) == TRUE && found == 0) {
        work->index = found;
        found = 1;
    }

    return found;
}

void BosLstBitStartHover(Task* task) {
    LstState* work;
    u16 zero;

    work = task->work;
    zero = 0;
    work->state = BOS_LST_BIT_STATE_HOVER;
    work->step = zero;
    work->timer = zero;
    work->delay = zero;
}

void BosLstBitStartFiring(Task* task, s16 shots) {
    LstState* work;
    u16 zero;

    work = task->work;
    zero = 0;
    work->state = BOS_LST_BIT_STATE_CHARGE;
    work->step = zero;
    work->timer = zero;
    work->delay = zero;
    work->shots = shots;
}

void BosLstBitStartReturn(Task* task) {
    LstState* work;
    u16 zero;

    work = task->work;

#ifdef VERSION_EU
    if ((u16)(work->state - BOS_LST_BIT_STATE_RETURN) > 1) {
#endif
        zero = 0;
        work->state = BOS_LST_BIT_STATE_RETURN;
        work->step = zero;
        work->timer = zero;
        work->delay = zero;
#ifdef VERSION_EU
    }
#endif
}

u8 BosLstBitInterrupt(Task* task, u8 destroy) {
    LstState* work;
    u8 destroyed;

    work = task->work;
    destroyed = FALSE;
    BosLstLsrStop(work->lsrTask);
    BosLstLsrStop(work->lsrTask2);
    BosLstLsrStop(work->lsrTask3);
    work->shots = 0;

    if (work->state >= BOS_LST_BIT_STATE_RETURN && work->state <= BOS_LST_BIT_STATE_HIDDEN) {
        return FALSE;
    }

    if (destroy == TRUE && work->index == 0) {
        work->obj.hp = 0;
        SetBtlObjUnhittable(&work->obj, TRUE);
        BosLstBitSpawnFal(work, FALSE);
        BosLstBitSpawnFal(work, FALSE);
        destroyed = TRUE;
    }

#ifdef VERSION_EU
    AnimReset(&work->anim);
    AnimChange(&work->anim, sLstAnimSets[work->animSet].idleAnim, ANIM_FLAG_LOOP);

    if (work->state != BOS_LST_BIT_STATE_ENTER && work->state != BOS_LST_BIT_STATE_RETURN) {
        work->state = BOS_LST_BIT_STATE_INTERRUPTED;
        work->step = 0;
        work->timer = 0;
        work->delay = 0;

        if (gBtlWork->actor->z > -0xC000) {
            work->targetZ = -0x6000;
        } else {
            work->targetZ = gBtlWork->bossZ - 0x5000;
        }
    }
#else
    work->state = BOS_LST_BIT_STATE_INTERRUPTED;
    work->step = 0;
    work->timer = 0;
    work->delay = 0;
#endif

    return destroyed;
}

s32 BosLstBitAtanLookup(s32 x, s32 y) {
    s32 ratio;
    s32 step;
    s32 i;

    if (x == 0 || y == 0) {
        return 0;
    }

    ratio = (y << 8) / x;

    if (ratio <= sBosLstBitTanTable[0]) {
        return 0;
    }

    step = 8;
    i = 16;

    while (step != 0 && ratio != sBosLstBitTanTable[i]) {
        if (ratio < sBosLstBitTanTable[i]) {
            i -= step;
        } else {
            i += step;
        }

        step /= 2;
    }

    return i;
}

s32 BosLstBitAngleBetween(s32 x0, s32 y0, s32 x1, s32 y1) {
    s32 dx;
    s32 dy;
    s32 angle;

    dx = x0 - x1;
    dy = y0 - y1;

    if (abs(dx) >= abs(dy)) {
        angle = BosLstBitAtanLookup(abs(dx), abs(dy));
    } else {
        angle = 63 - BosLstBitAtanLookup(abs(dy), abs(dx));
    }

    if (dx >= 0) {
        if (dy >= 0) {
            angle = 63 - angle;
            angle = angle + 192;
        }
    } else if (dy >= 0) {
        angle = angle + 128;
    } else {
        angle = 63 - angle;
        angle = angle + 64;
    }

    angle = 255 - angle;
    angle = angle + 65;

    return angle & 255;
}

s32 BosLstBitAngleDiff(u8 from, u8 to) {
    s32 diff;

    if (from > to) {
        diff = from - to;

        if (diff > 128) {
            diff = diff - 256;
        }

        return -diff;
    }

    diff = to - from;

    if (diff > 128) {
        diff = diff - 256;
    }

    return diff;
}

void task_bos_lst_bit_0(LstState* work, LstBitArg* arg) {
    LstLsrArg laserArg;
    BtlObj* actor;
    TaskPool* pool;

    work->animSet = 0;
    work->state = BOS_LST_BIT_STATE_ENTER;
    work->step = 0;
    work->timer = 0;
    work->delay = 0;
    work->hurtTimer = 0;
    work->bobFrame = 0;
    work->kind = arg->kind;
    work->index = arg->index;
    work->shots = 0;
    work->falTimer = GetRandom() % 32;
    work->facing = arg->facing;
    work->falCount = arg->falCount;
    work->unk_024 = arg->unk_10;
    work->x = arg->x;
    work->y = arg->y;
    work->z = arg->z;
    work->startX = arg->x;
    work->startY = arg->y;
    work->startZ = arg->z;
    work->bobZ = 0;
    work->targetX = arg->x2;
    work->targetY = arg->y2;
    work->targetZ = arg->z2;
    actor = gBtlWork->actor;
    work->actorX = actor->x;
    work->actorY = actor->y;
    work->actorZ = actor->z;
    work->angle = arg->index << 7;
    work->scaleX = 2;
    work->scaleY = 2;
    work->tiles = LoadObjTiles(gBosLstBitTiles, sizeof(gBosLstBitTiles));
    work->palette = LoadObjPalette(gBosLstObjPalette, sizeof(gBosLstObjPalette));
    work->palette2 = LoadObjPalette(gHitFlashPalette, sizeof(gHitFlashPalette));
    AnimInit(&work->anim, gBosLstBitAnims, gBosLstBitFrames);
    AnimStart(&work->anim, sLstAnimSets[work->animSet].idleAnim, ANIM_FLAG_LOOP);
    InitEnemyBtlObj(&work->obj, &sBosLstBitEmyKind, work->x, work->y, work->z);
    pool = &work->tasks;
    TaskPoolInit(pool, 4);
    laserArg.kind = work->kind;
    laserArg.facing = work->facing;
    laserArg.falCount = work->falCount;
    work->lsrTask = TaskCreate(pool, &gTaskDescBosLstLsr, &laserArg);
    work->lsrTask2 = TaskCreate(pool, &gTaskDescBosLstLsr, &laserArg);
    work->lsrTask3 = TaskCreate(pool, &gTaskDescBosLstLsr, &laserArg);
}

void BosLstBitHandleHit(LstState* work) {
    BtlObj* obj;

    obj = &work->obj;

    switch (UpdateBtlObjReaction(obj)) {
    case BTL_REACTION_HURT:
    case BTL_REACTION_STUNNED:
    case BTL_REACTION_GRAVITY:
        work->hurtTimer = 20;
        BosLstBitSpawnFal(work, FALSE);
        ClearBtlObjActionFlags(obj);
        break;
    case BTL_REACTION_DEFEATED:
        SetBtlObjUnhittable(&work->obj, TRUE);
        BosLstBitSpawnFal(work, FALSE);
        BosLstBitSpawnFal(work, FALSE);
        ClearBtlObjActionFlags(obj);
        break;
    case BTL_REACTION_CARD_ACTION:
        ClearBtlObjActionFlags(obj);
        break;
    case BTL_REACTION_CARD_BROKEN:
        ClearBtlObjActionFlags(obj);
        break;
    case BTL_REACTION_HEALED:
        break;
    }
}

u8 task_bos_lst_bit_1(LstState* work) {
    Vec3 origin;
    Vec3 target;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    BtlObj* p;
    s32 diff;
    u8 dir;
    BtlObj* obj;

    obj = &work->obj;

    if (obj->hp <= 0) {
        SetBtlObjUnhittable(obj, TRUE);
        return 1;
    }

    BosLstBitHandleHit(work);

    switch (work->state) {
    case BOS_LST_BIT_STATE_ENTER:
        ApproachValueHalfSteps(&work->x, work->targetX, 20);
        ApproachValueHalfSteps(&work->y, work->targetY, 20);
        ApproachValueHalfSteps(&work->z, work->targetZ, 20);
        ApproachValueHalfSteps(&work->scaleX, Q_8_8(1), 32);
        ApproachValueHalfSteps(&work->scaleY, Q_8_8(1), 32);
        work->timer++;

        if (work->timer > 29) {
            work->state = BOS_LST_BIT_STATE_HOVER;
            work->step = 0;
            work->timer = 0;
            work->delay = 0;
            work->scaleX = Q_8_8(1);
            work->scaleY = Q_8_8(1);
        }

        break;
    case BOS_LST_BIT_STATE_HOVER:
        if (work->timer == 0) {
            if (gBtlWork->flags & BTL_FLAG_PLAYER_OFFSCREEN) {
                work->targetX = (GetRandom() % 113 << 8) + 0xC000;
#ifndef VERSION_EU
                work->targetY = gBtlWork->actor->y;
#endif
            } else if (work->kind == BOS_LST_BIT_KIND_BITS) {
                work->targetX = (GetRandom() % 113 << 8) + 0xC000;
                work->targetY = gBtlWork->actor->y + (sBosLstBitHoverY[work->index] << 8);
            } else {
                work->targetX = gBtlWork->actor->x;
                work->targetY = gBtlWork->actor->y;
            }

            AnimReset(&work->anim);
            AnimChange(&work->anim, sLstAnimSets[work->animSet].idleAnim, ANIM_FLAG_LOOP);
        }

        if (!(gBtlWork->flags & BTL_FLAG_PLAYER_OFFSCREEN)) {
            if (gBtlWork->actor->z > -0xC000) {
                work->targetZ = -0x6000;
            } else {
                work->targetZ = gBtlWork->bossZ - 0x5000;
            }
        }

        work->timer++;

        if ((work->falTimer & 31) == 0) {
            BosLstBitSpawnFal(work, FALSE);
        }

        ApproachValueHalfSteps(&work->x, work->targetX, 20);
        ApproachValueHalfSteps(&work->y, work->targetY, 20);
        ApproachValueHalfSteps(&work->z, work->targetZ, 20);
        break;
    case BOS_LST_BIT_STATE_CHARGE:
        if (work->timer == 0) {
            work->targetX = gBtlWork->actor->x;
            work->targetY = gBtlWork->actor->y;

            if (gBtlWork->actor->z > -0xC000) {
                work->targetZ = 0;
            } else {
                work->targetZ = gBtlWork->bossZ;
            }

            AnimReset(&work->anim);
            AnimChange(&work->anim, sLstAnimSets[work->animSet].chargeAnim, 0);
        }

        work->timer++;

        if (AnimGetId(&work->anim) == (s16)sLstAnimSets[work->animSet].chargeAnim && AnimIsFinished(&work->anim) == TRUE) {
            work->state = BOS_LST_BIT_STATE_FIRE;
            work->timer = 0;
            work->unk_018 = 1;
            work->fireAngle = work->aimAngle;
            work->fireX = work->x + work->orbitX;
            work->fireY = work->y + work->orbitY;
            work->fireZ = work->z + work->orbitZ;
            m4aSongNumStart(SONG_SND_708);
            AnimReset(&work->anim);
            AnimChange(&work->anim, sLstAnimSets[work->animSet].idleAnim, ANIM_FLAG_LOOP);
        }

        break;
    case BOS_LST_BIT_STATE_FIRE:
        if (work->timer == 0) {
            if (!BosLstLsrIsFiring(work->lsrTask)) {
                origin.x = work->fireX;
                origin.y = work->fireY;
                origin.z = work->fireZ;
                target.x = work->targetX;
                target.y = work->targetY;
                target.z = work->targetZ;
                BosLstLsrFire(work->lsrTask, &origin, &target, work->fireAngle, 0);
            }

            work->timer++;
        } else {
            work->targetX = gBtlWork->actor->x;
            work->targetY = gBtlWork->actor->y;

            if (gBtlWork->actor->z > -0xC000) {
                work->targetZ = 0;
            } else {
                work->targetZ = gBtlWork->bossZ;
            }

            if (!BosLstLsrIsFiring(work->lsrTask)) {
                if (work->shots > 1) {
                    work->state = BOS_LST_BIT_STATE_CHARGE;
                    work->timer = 0;
                    work->shots--;
                } else {
                    work->shots = 0;
                }
            }
        }

        break;
    case BOS_LST_BIT_STATE_IMPACT:
        if (work->timer > 14) {
            break;
        }

        ApplyAttackBox(0x10D, work->targetX, work->targetY, work->targetZ, 8, 8, 8);

        if ((work->timer & 3) == 0) {
            BosLstBitSpawnFal(work, TRUE);
        }

        if (abs(work->targetX - gBtlWork->actor->x) < 0x180) {
            work->targetX = gBtlWork->actor->x;
        } else if (work->targetX > gBtlWork->actor->x) {
            work->targetX = work->targetX - 0x180;
        } else if (work->targetX < gBtlWork->actor->x) {
            work->targetX = work->targetX + 0x180;
        }

        if (abs(work->targetY - gBtlWork->actor->y) < 0x180) {
            work->targetY = gBtlWork->actor->y;
        } else if (work->targetY > gBtlWork->actor->y) {
            work->targetY = work->targetY - 0x180;
        } else if (work->targetY < gBtlWork->actor->y) {
            work->targetY = work->targetY + 0x180;
        }

        work->timer++;
        break;
    case BOS_LST_BIT_STATE_RETURN:
        work->targetX = gBtlWork->bossX;
        work->targetY = gBtlWork->bossY - 0x1400;
        work->targetZ = gBtlWork->bossZ;
        ApproachValueHalfSteps(&work->x, work->targetX, 16);
        ApproachValueHalfSteps(&work->y, work->targetY, 16);
        ApproachValueHalfSteps(&work->z, work->targetZ, 16);
        ApproachValueHalfSteps(&work->scaleX, Q_8_8(2), 16);
        ApproachValueHalfSteps(&work->scaleY, 2, 16);
        work->timer++;

        if (work->timer > 59) {
            work->state = BOS_LST_BIT_STATE_HIDDEN;
            work->step = 0;
            work->timer = 0;
            work->delay = 0;
        }

        break;
    case BOS_LST_BIT_STATE_HIDDEN:
        work->scaleX = Q_8_8(1);
        work->scaleY = Q_8_8(1);
        AnimReset(&work->anim);
        AnimChange(&work->anim, 4, ANIM_FLAG_LOOP);
        break;
    case BOS_LST_BIT_STATE_INTERRUPTED:
        AnimChange(&work->anim, sLstAnimSets[work->animSet].idleAnim, ANIM_FLAG_LOOP);
        break;
    }

    WorldToScreen(&x1, &y1, work->x + work->orbitX, work->y + work->orbitY,
                  work->z + work->orbitZ);

    if (gBtlWork->flags & BTL_FLAG_PLAYER_OFFSCREEN) {
        WorldToScreen(&x2, &y2, work->actorX, work->actorY, work->actorZ);
        work->angle += 2;
    } else {
        if (work->kind == BOS_LST_BIT_KIND_BITS) {
            switch (work->state) {
            case BOS_LST_BIT_STATE_CHARGE:
            case BOS_LST_BIT_STATE_FIRE:
                work->angle += 2;
                WorldToScreen(&x2, &y2, work->targetX, work->targetY, work->targetZ);
                break;
            default:
                work->angle += 2;
                WorldToScreen(&x2, &y2, gBtlWork->actor->x, gBtlWork->actor->y,
                              gBtlWork->actor->z);
                break;
            }
        } else {
            switch (work->state) {
            case BOS_LST_BIT_STATE_CHARGE:
            case BOS_LST_BIT_STATE_FIRE:
            case BOS_LST_BIT_STATE_IMPACT:
                work->angle += 6;
                WorldToScreen(&x2, &y2, work->targetX, work->targetY, work->targetZ);
                break;
            default:
                work->angle += 2;
                WorldToScreen(&x2, &y2, gBtlWork->actor->x, gBtlWork->actor->y,
                              gBtlWork->actor->z);
                break;
            }
        }

        work->actorX = gBtlWork->actor->x;
        work->actorY = gBtlWork->actor->y;
        work->actorZ = gBtlWork->actor->z;
    }

    work->angle &= 0xFF;

    if (work->kind == BOS_LST_BIT_KIND_BITS) {
        work->orbitX = (-COS(work->angle) * 3 >> 6) << 8;
        work->orbitY = (SIN(work->angle) * 3 >> 6) << 8;
        work->orbitZ = work->orbitZ / 2;
    } else if (work->index == 0) {
        work->orbitX = work->orbitX / 2;
        work->orbitY = work->orbitY / 2;
        work->orbitZ = work->orbitZ / 2;
    } else {
        work->orbitX = (-COS(work->angle) >> 3) << 8;
        work->orbitY = (SIN(work->angle) * 3 >> 6) << 8;
        work->orbitZ = 0x800;
    }

    work->bobZ = sBosLstBitBobZ[(work->bobFrame >> 2) & 15] << 8;
    dir = BosLstBitAngleBetween(x2, y2, x1, y1);
    diff = BosLstBitAngleDiff(work->aimAngle, dir);

    if (abs(diff) <= 1) {
        work->aimAngle = dir;
    } else {
        work->aimAngle += diff / 2;
    }

    obj->x = work->x + work->orbitX;
    obj->y = work->y + work->orbitY;
    obj->z = work->z + work->orbitZ + work->bobZ;
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    work->falTimer++;
    work->bobFrame++;

    return 1;
}

void task_bos_lst_bit_2(LstState* work) {
    s16 x;
    s16 y;
    void* pal;
    ObjAffine* affine;
    u16 prio;
    u16 depth;
    void* gfx;

    if (work->obj.hp <= 0) {
        return;
    }

    pal = work->palette;

    if ((work->hurtTimer & 1) != 0) {
        pal = work->palette2;
    }

    if (work->hurtTimer > 0) {
        work->hurtTimer = work->hurtTimer - 1;
    }

    WorldToScreen(&x, &y, work->x + work->orbitX, work->y + work->orbitY,
                  work->z + work->orbitZ + work->bobZ);
    prio = GetBattleSpritePriorityFlags(work->y);
    depth = -0x1004 - (work->y >> 8) * 4;
    affine = AllocObjAffine(work->aimAngle, work->scaleX, work->scaleY, FALSE);
    gfx = AnimGetGfx(&work->anim);
    DrawSprite(x, y, gfx, work->tiles, pal, affine, prio, depth);
    TaskPoolDraw(&work->tasks);
}

void task_bos_lst_bit_3(LstBitWork* work) {
    ReleaseEnemyBtlObj(&work->obj);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
    TaskPoolDestroy(&work->tasks);
}
