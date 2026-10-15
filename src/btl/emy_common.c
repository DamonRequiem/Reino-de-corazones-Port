/**
 * emy_common.c
 * Common Enemy Routines
 */

#include "display.h"
#include "enemy_common.h"
#include "system_state.h"
#include "gba/io_reg.h"
#include "fade.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_collision.h"
#include "btl_effect.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "game_state.h"
#include "m4a_song.h"
#include "obj.h"
#include "obj_api.h"
#include <stddef.h>
#include "task_descriptors.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "map_types.h"

u16 gEnemyTileCounts[54] = {
    32, 32, 32, 32, 32, 34, 28, 24, 32,
    44, 50, 44, 52, 46, 72, 80, 88, 74,
    76, 43, 86, 86, 88, 72, 74, 106, 110,
    89, 100, 50, 50, 33, 128, 128, 128, 128,
    128, 128, 128, 128, 128, 128, 128, 128, 128,
    128, 80, 80, 128, 128, 128, 128, 128, 128,
};

void EmyInit(EmyWork* work, const EmyDef* def, EmyObj* obj) {
    BtlObj* actor = &work->actor;
    u16 tileCount;

    InitEnemyBtlObj(actor, &def->kind, obj->x, obj->y, obj->z);
    actor->attackOffset = def->attackOffset;
    actor->attackRangeX = def->attackRangeX;
    actor->attackRangeY = def->attackRangeY;
    actor->cardInterval = def->cardInterval;

    if (gBtlWork->actor->x < actor->x) {
        actor->flags |= BTLOBJ_FLAG_FACING_LEFT;
    }

    actor->flags |= (BTLOBJ_FLAG_INTANGIBLE | BTLOBJ_FLAG_CARD_USE_BLOCKED);
    tileCount = gEnemyTileCounts[actor->kind];
    work->def = def;
    work->tiles = AllocObjTiles(tileCount * 32, NULL);
    work->palette = LoadObjPalette(def->palette, 32);
    work->palette2 = LoadObjPalette(gHitFlashPalette, sizeof(gHitFlashPalette));
    work->idleState = EMY_STATE_IDLE;
    work->state = EMY_STATE_SPAWN;
    work->stateTimer = 0;
    work->steps = 0;
    work->flags = 0;
    work->visible = TRUE;
    work->angle = 0;
    work->speed = def->speed;
    work->vz = 0;
    actor->vx = 0;
    actor->vy = 0;
    work->spriteFlags = 0;

    if (actor->flags & BTLOBJ_FLAG_LARGE_SHADOW) {
        work->fxScale = Q_8_8(1.1);
    } else {
        work->fxScale = Q_8_8(1);
    }

    work->x = 0;
    work->y = 0;
    work->hoverZ = 0;
    AnimInit(&work->anim, NULL, NULL);
    AnimChangeWithDef(work->def->animDef, &work->anim, 0, ANIM_FLAG_LOOP, work->tiles);
    work->gfx = AnimGetGfx(&work->anim);
    TaskPoolInit(&work->tasks, 3);

    if (!(def->flags & EMY_DEF_FLAG_NO_SHADOW)) {
        TaskCreate(&work->tasks, &gTaskDescBtlShadow, actor);
    }

    TaskCreate(&work->tasks, &gTaskDescBtlBadstatus, actor);

    if (def->flags & EMY_DEF_FLAG_NO_SCALE_IN) {
        work->scaleX = Q_8_8(1);
        work->scaleY = Q_8_8(1);
    } else {
        work->scaleX = Q_8_8(0.5);
        work->scaleY = Q_8_8(0.5);
    }

    gBtlWork->enemyTileCount += tileCount;
    gBtlWork->pendingEnemies--;
}

s16 EmyLungeAttack(EmyWork* work, s16 delay, s16 duration, s16 recovery, s32 attack, s16 distance, u16 song, s16 dx, s16 dz, u16 halfSize) {
    BtlObj* actor = &work->actor;
    s32 hit;
    s32 targetX;
    s32 targetY;
    s16 steps;

    hit = EMY_LUNGE_ACTIVE;

    if (work->stateTimer == 0) {
        work->flags &= ~EMY_FLAG_LUNGE_HIT;
    }

    if (work->stateTimer >= delay) {
        if (work->stateTimer < delay + duration) {
            steps = (delay + duration) - work->stateTimer;
            targetY = actor->originY;

            if (work->actor.flags & BTLOBJ_FLAG_FACING_LEFT) {
                targetX = actor->originX - (distance << 8);
            } else {
                targetX = actor->originX + (distance << 8);
            }

            if (actor->badStatus != BAD_STATUS_BIND) {
                ApproachValueHalfSteps(&actor->x, targetX, steps);
                ApproachValueHalfSteps(&actor->y, targetY, steps);
            }

            if (!(work->flags & EMY_FLAG_LUNGE_HIT)) {
                if (actor->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    if (ApplyAttackBox(attack, actor->x - (dx << 8), actor->y, actor->z + (dz << 8), halfSize, halfSize / 2, halfSize) != ATTACK_RESULT_NONE) {
                        m4aSongNumStart(song);
                        work->flags |= EMY_FLAG_LUNGE_HIT;
                        hit = EMY_LUNGE_HIT;
                    }
                } else {
                    if (ApplyAttackBox(attack, actor->x + (dx << 8), actor->y, actor->z + (dz << 8), halfSize, halfSize / 2, halfSize) != ATTACK_RESULT_NONE) {
                        m4aSongNumStart(song);
                        hit = EMY_LUNGE_HIT;
                        work->flags |= EMY_FLAG_LUNGE_HIT;
                    }
                }
            }
        } else if (work->stateTimer > delay + duration + recovery) {
            EmyReturnToIdle(work);
            return EMY_LUNGE_FINISHED;
        }
    }

    work->stateTimer++;
    return hit;
}

void EmyReturnToIdle(EmyWork* work) {
    ClearBtlObjActionFlags(&work->actor);
    work->state = work->idleState;
    work->stateTimer = 0;
}

void EmyStartKnockback(EmyWork* work) {
    work->vz = -work->actor.knockbackLift * 3;
    work->actor.vx = ((gSineTable[work->actor.angle] << 1) * work->actor.knockbackSpeed) >> 8;
    work->actor.vy = ((-gSineTable[work->actor.angle + 0x40] << 1) * work->actor.knockbackSpeed) >> 8;
}

u8 EmyUpdateReaction(EmyWork* work) {
    BtlObj* actor = &work->actor;

    actor->prevX = actor->x;
    actor->prevY = actor->y;

    if (work->state == EMY_STATE_DEFEATED) {
        return FALSE;
    }

    if (work->state == EMY_STATE_WARPED) {
        return FALSE;
    }

    switch (UpdateBtlObjReaction(actor)) {
    case BTL_REACTION_STUNNED:
        EmyStartKnockback(work);
        work->state = EMY_STATE_STUNNED;
        work->stateTimer = 0;
        break;
    case BTL_REACTION_GRAVITY:
        work->state = EMY_STATE_GRAVITY_SQUASH;
        work->stateTimer = 0;
        break;
    case BTL_REACTION_GRAVITY_DEFEATED:
        SetBtlObjUnhittable(actor, TRUE);
        work->state = EMY_STATE_GRAVITY_SQUASH;
        work->stateTimer = 0;
        break;
    case BTL_REACTION_HURT:
        EmyStartKnockback(work);
        work->state = EMY_STATE_HURT;
        work->stateTimer = 0;
        break;
    case BTL_REACTION_WARPED:
        SetBtlObjUnhittable(actor, TRUE);
        work->state = EMY_STATE_WARPED;
        work->stateTimer = 0;
        break;
    case BTL_REACTION_DEFEATED:
        SetBtlObjUnhittable(actor, TRUE);
        EmyStartKnockback(work);
        work->state = EMY_STATE_DEFEATED;
        work->stateTimer = 0;
        break;
    case BTL_REACTION_TERRIFIED:
        work->state = EMY_STATE_TERRIFIED;
        work->stateTimer = 0;
        break;
    case BTL_REACTION_HEALED:
        if (work->state != EMY_STATE_STOPPED) {
            work->state = EMY_STATE_HEALED;
            work->stateTimer = 0;
        }

        break;
    case BTL_REACTION_CARD_ACTION:
        work->stateTimer = 0;
        return TRUE;
    case BTL_REACTION_CARD_BROKEN:
        work->state = EMY_STATE_CARD_BROKEN;
        work->stateTimer = 0;
        work->visible = TRUE;
        break;
    case BTL_REACTION_STOPPED:
        if (work->state != EMY_STATE_STOPPED) {
            work->state = EMY_STATE_STOPPED;
            work->stateTimer = 0;
            actor->vx = actor->vy = 0;
        }

        break;
    }

    return FALSE;
}

void EmyFinishSpawn(EmyWork* work) {
    BtlObj* actor = &work->actor;

    if (gGameState.flags & GAME_FLAG_FIRST_STRIKE) {
        actor->flags |= (BTLOBJ_FLAG_DAMAGE_PENDING | BTLOBJ_FLAG_STUN_PENDING);

        if (gGameState.roomEffect == ROOM_EFFECT_STRONG_INITIATIVE) {
            actor->damage = (actor->maxHp * 204) >> 8;
        } else {
            actor->damage = (actor->maxHp * 25) >> 8;
        }

        actor->hitFlags = ATTACK_FLAG_INFLICT_STUN;
        gBtlWork->pendingHitStop = 0;
        actor->knockbackSpeed = 0;
        actor->knockbackLift = 0;
    }

    work->state = work->idleState;
    work->stateTimer = 0;
    actor->flags &= ~(BTLOBJ_FLAG_INTANGIBLE | BTLOBJ_FLAG_CARD_USE_BLOCKED);
}

s32 EmyUpdateCommonStates(EmyWork* work) {
    BtlObj* actor = &work->actor;
    s32 x;
    s32 y;
    s32 z;

    GetEnemyTargetPosition(actor, &x, &y, &z);

    if (gBtlWork->flags & BTL_FLAG_FIELD_HIDDEN) {
        return 0;
    }

    switch (work->state) {
    case EMY_STATE_SPAWN:
        if (work->stateTimer == 0) {
            work->steps = 18;
        }

        work->vz = 0;
        ApproachValue(&work->scaleY, Q_8_8(1), work->steps--);
        work->scaleX = work->scaleY;

        if (work->steps <= 0) {
            EmyFinishSpawn(work);
        } else {
            work->stateTimer++;
        }

        break;
    case EMY_STATE_HOVER_MOVE:
        work->vz = 0;
        AnimChangeWithDef(work->def->animDef, &work->anim, 2, ANIM_FLAG_LOOP, work->tiles);
        TryEnemyCardUse(actor);
        actor->z += ((work->hoverZ + SIN(gFrameCounter) * 10) - actor->z) >> 4;

        if (GetRandom() % work->def->turnInterval == 0) {
            if (actor->x > x) {
                actor->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                actor->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }
        }

        if (gBtlWork->flags & BTL_FLAG_ENEMY_MOVE_ENABLED) {
            s32 tx;
            s32 ty;
            s32 step;

            tx = work->x;
            ty = work->y;
            work->speed += 51;
            step = (tx - actor->x) >> 5;

            if (step > work->speed) {
                step = work->speed;
            } else if (step < -work->speed) {
                step = -work->speed;
            }

            actor->x += step;
            step = (ty - actor->y) >> 5;

            if (step > work->speed) {
                step = work->speed;
            } else if (step < -work->speed) {
                step = -work->speed;
            }

            actor->y += step;

            if (work->stateTimer > 64) {
                work->state = work->idleState;
            } else {
                work->stateTimer++;
            }
        }

        break;
    case EMY_STATE_HOVER:
        work->vz = 0;
        AnimChangeWithDef(work->def->animDef, &work->anim, 0, ANIM_FLAG_LOOP, work->tiles);
        TryEnemyCardUse(actor);
        actor->z += ((work->hoverZ + SIN(gFrameCounter * 2) * 12) - actor->z) >> 4;

        if (GetRandom() % work->def->turnInterval == 0) {
            if (actor->x > x) {
                actor->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                actor->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }
        }

        if (GetRandom() % work->def->moveInterval == 0) {
            work->speed = 0;
            work->state = EMY_STATE_HOVER_MOVE;

            if (GetRandom() % 2 == 0) {
                s32 lo;

                work->x = x - ((actor->attackOffset + ((lo = -actor->attackRangeX) + GetRandom() % (actor->attackRangeX - lo + 1))) << 8);
            } else {
                s32 lo;

                work->x = x + ((actor->attackOffset + ((lo = -actor->attackRangeX) + GetRandom() % (actor->attackRangeX - lo + 1))) << 8);
            }

            work->y = y + ((GetRandom() % 121 - 60) << 8);
            work->hoverZ = -((GetRandom() % 49 + 16) << 8);
            work->stateTimer = 0;
        } else {
            work->stateTimer++;
        }

        break;
    case EMY_STATE_TERRIFIED:
        if (work->stateTimer == 0) {
            AnimReset(&work->anim);
            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);
            actor->originX = actor->x;
            actor->originY = actor->y;
        }

        switch (work->stateTimer % 4) {
        case 0:
            actor->x = actor->originX + 0x100;
            actor->y = actor->originY;
            break;
        case 1:
            actor->x = actor->originX - 0x100;
            actor->y = actor->originY;
            break;
        case 2:
            actor->x = actor->originX;
            actor->y = actor->originY + 0x100;
            break;
        case 3:
            actor->x = actor->originX;
            actor->y = actor->originY - 0x100;
            break;
        }

        if (AnimIsFinished(&work->anim)) {
            ClearBtlObjActionFlags(actor);
            work->state = EMY_STATE_FLEE;
            work->stateTimer = 0;
        } else {
            work->stateTimer++;
        }

        break;
    case EMY_STATE_FLEE:
        if (gBtlWork->flags & BTL_FLAG_ENEMY_MOVE_ENABLED) {
            s32 tx;
            s32 ty;

            if (work->stateTimer == 0) {
                AnimChangeWithDef(work->def->animDef, &work->anim, 2, ANIM_FLAG_LOOP, work->tiles);
            }

            if (x < 0x10000) {
                tx = x >> 1;
            } else {
                tx = (x + 0x20000) >> 1;
            }

            if (y < ((gBtlWork->yMin + gBtlWork->yMax) >> 1) << 8) {
                ty = (gBtlWork->yMin << 8) - 0x4000;
            } else {
                ty = (gBtlWork->yMax << 8) + 0x4000;
            }

            work->angle = GetAngle(tx, ty, actor->x, actor->y);
            actor->x += ((gSineTable[work->angle] << 1) * work->def->speed) >> 8;
            actor->y += ((-gSineTable[work->angle + 64] << 1) * work->def->speed) >> 8;

            if ((s8)work->angle >= 0) {
                actor->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            } else {
                actor->flags |= BTLOBJ_FLAG_FACING_LEFT;
            }

            if (actor->badStatus != BAD_STATUS_TERROR) {
                work->state = work->idleState;
                work->stateTimer = 0;
            } else {
                work->stateTimer++;
            }
        }

        break;
    case EMY_STATE_WALK:
        if (gBtlWork->flags & BTL_FLAG_ENEMY_MOVE_ENABLED) {
            s32 px;
            s32 tx;
            s32 ty;
            s32 step;

            AnimChangeWithDef(work->def->animDef, &work->anim, 2, ANIM_FLAG_LOOP, work->tiles);
            TryEnemyCardUse(actor);
            px = x;
            tx = px + work->x;
            ty = y;

            if (tx < (gBtlWork->xMin + 32) << 8) {
                tx = px + ((actor->attackOffset + actor->attackRangeX) << 8);
            } else if (tx > (gBtlWork->xMax - 32) << 8) {
                tx = ty - ((actor->attackOffset + actor->attackRangeX) << 8);
            }

            if (GetRandom() % 100 == 0) {
                if (GetRandom() % 2 == 0) {
                    s32 lo;

                    work->x = -((actor->attackOffset + ((lo = -actor->attackRangeX) + GetRandom() % (actor->attackRangeX - lo + 1))) << 8);
                } else {
                    s32 lo;

                    work->x = ((actor->attackOffset + ((lo = -actor->attackRangeX) + GetRandom() % (actor->attackRangeX - lo + 1))) << 8);
                }
            } else {
                if ((tx - actor->x >= 0 ? tx - actor->x : actor->x - tx) > 0x400
                    || (ty - actor->y >= 0 ? ty - actor->y : actor->y - ty) > 0x400) {
                    work->angle = GetAngle(actor->x, actor->y, tx, ty);
                    actor->x += (gSineTable[work->angle] * work->speed) >> 8;
                    actor->y += (-gSineTable[work->angle + 64] * work->speed) >> 8;
                } else if (AnimIsFinished(&work->anim)) {
                    work->state = work->idleState;
                }
            }

            if (GetRandom() % work->def->turnInterval == 0) {
                if (actor->x > x) {
                    actor->flags |= BTLOBJ_FLAG_FACING_LEFT;
                } else {
                    actor->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
                }
            }
        }

        break;
    case EMY_STATE_IDLE:
        AnimChangeWithDef(work->def->animDef, &work->anim, 0, ANIM_FLAG_LOOP, work->tiles);
        TryEnemyCardUse(actor);

        if (GetRandom() % work->def->moveInterval == 0) {
            work->state = EMY_STATE_WALK;

            if (GetRandom() % 2 == 0) {
                s32 lo;

                work->x = -((actor->attackOffset + ((lo = -actor->attackRangeX) + GetRandom() % (actor->attackRangeX - lo + 1))) << 8);
            } else {
                s32 lo;

                work->x = ((actor->attackOffset + ((lo = -actor->attackRangeX) + GetRandom() % (actor->attackRangeX - lo + 1))) << 8);
            }
        }

        if (GetRandom() % work->def->turnInterval == 0) {
            if (actor->x > x) {
                actor->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                actor->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }
        }

        break;
    case EMY_STATE_STOPPED:
        if (actor->badStatus != BAD_STATUS_STOP) {
            work->state = work->idleState;
            ClearBtlObjActionFlags(actor);
        }

        break;
    case EMY_STATE_STUNNED:
        if (work->stateTimer == 0) {
            AnimReset(&work->anim);
            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);
            work->stateTimer++;
        }

        if (AnimIsFinished(&work->anim)) {
            actor->flags &= ~BTLOBJ_FLAG_HIT_LOCKED;
            actor->flags &= ~BTLOBJ_FLAG_HURT;
        }

        if (GetRandom() % 10 == 0) {
            actor->badStatusTimer--;
        }

        if (actor->badStatus != BAD_STATUS_STUN) {
            ClearBtlObjActionFlags(actor);
            work->state = work->idleState;
            work->stateTimer = 0;
        }

        break;
    case EMY_STATE_HURT:
        if (work->stateTimer == 0) {
            AnimReset(&work->anim);
            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);
        }

        if (work->stateTimer >= work->def->hitStunFrames) {
            s32 facingTarget = FALSE;

            ClearBtlObjActionFlags(actor);
            work->state = EMY_STATE_HURT_RECOVER;
            work->stateTimer = 0;

            if (actor->x < x) {
                if (actor->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    if (GetRandom() % 5 == 0) {
                        actor->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
                        facingTarget = TRUE;
                    }
                } else {
                    facingTarget = TRUE;
                }
            } else {
                if (actor->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    facingTarget = TRUE;
                } else {
                    if (GetRandom() % 5 == 0) {
                        actor->flags |= BTLOBJ_FLAG_FACING_LEFT;
                        facingTarget = TRUE;
                    }
                }
            }

            if (!facingTarget) {
                break;
            }

            if (GetRandom() % 4 == 0) {
                RequestEnemyCardUse(actor);
            }
        } else {
            work->stateTimer++;
        }

        break;
    case EMY_STATE_HURT_RECOVER:
        if (AnimIsFinished(&work->anim)) {
            work->state = work->idleState;
            work->stateTimer = 0;
        }

        break;
    case EMY_STATE_GRAVITY_SQUASH:
        if (work->stateTimer == 0) {
            ColliderSetDisabled(&actor->collider, TRUE);
            actor->flags |= BTLOBJ_FLAG_INTANGIBLE;
            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);
            work->anim.frame = 0;
            work->anim.timer = 0;
            work->vz = 0x400;
            actor->vx = 0;
            actor->vy = 0;
            work->steps = 10;
        }

        ApproachValue(&work->scaleY, Q_8_8(0.25), work->steps--);

        if (work->steps <= 0) {
            work->stateTimer = 0;
            work->state = EMY_STATE_GRAVITY_HOLD;
        } else {
            work->stateTimer++;
        }

        break;
    case EMY_STATE_GRAVITY_HOLD:
        if (work->stateTimer > 44) {
            if (actor->hp <= 0) {
                work->state = EMY_STATE_DEFEATED;
            } else {
                work->state = EMY_STATE_GRAVITY_RECOVER;
            }

            work->stateTimer = 0;
        } else {
            work->stateTimer++;
        }

        break;
    case EMY_STATE_GRAVITY_RECOVER:
        if (work->stateTimer == 0) {
            ColliderSetDisabled(&actor->collider, FALSE);
            work->steps = 10;
        }

        ApproachValueHalfSteps(&work->scaleY, Q_8_8(1), work->steps--);

        if (work->steps <= 0) {
            actor->flags &= ~BTLOBJ_FLAG_INTANGIBLE;
            ClearBtlObjActionFlags(actor);
            work->state = work->idleState;
            work->stateTimer = 0;
        } else {
            work->stateTimer++;
        }

        break;
    case EMY_STATE_HEALED:
        if (work->stateTimer == 0) {
            AnimChangeWithDef(work->def->animDef, &work->anim, 0, ANIM_FLAG_LOOP, work->tiles);
            work->scaleX = Q_8_8(1);
            work->scaleY = Q_8_8(1);
            actor->vx = 0;
            actor->vy = 0;
        }

        work->vz = 0;

        if (work->stateTimer == 40) {
            CreateBtlPopTask(actor, BTL_POP_RECOVER);
            actor->hp -= actor->damage;

            if (actor->hp > actor->maxHp) {
                actor->hp = actor->maxHp;
            }

            ClearBtlObjActionFlags(actor);
            work->state = work->idleState;
            work->stateTimer = 0;
        } else {
            work->stateTimer++;
        }

        break;
    case EMY_STATE_WARPED:
        if (work->stateTimer == 0) {
            work->steps = 16;
        }

        actor->z -= (16 - work->steps) << 8;

        if (BgAnimIsStopped()) {
            gBldCnt = (BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
            work->spriteFlags = SPRITE_FLAG_BLEND;
            SetBlendAlpha(16 - work->steps, work->steps);
        } else {
            work->spriteFlags &= ~SPRITE_FLAG_BLEND;
        }

        ApproachValue(&work->scaleX, 10, work->steps);
        ApproachValue(&work->scaleY, Q_8_8(2), work->steps);
        work->steps--;

        if (work->steps <= 0) {
            if (gBtlWork->enemyCount == 1 && gBtlWork->pendingEnemies <= 0) {
                BgAnimStop();
                FadeStartIn(FADE_MODE_ADD_WHITE, 20);
                FadeLock();
            }

            DropEnemyPrizes(actor);
            SetEnemyJiminyFlag(actor);
            return 0;
        } else {
            work->stateTimer++;
        }

        break;
    case EMY_STATE_DEFEATED:
        if (work->stateTimer == 0) {
            s32 halfHeight;

            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);

            if (actor->flags & BTLOBJ_FLAG_NO_DEATH_FX) {
                work->stateTimer++;
                break;
            }

            if (actor->vx != 0) {
                break;
            }

            if (actor->vy != 0) {
                break;
            }

            if (actor->z != actor->groundZ) {
                break;
            }

            if (BgFxIsActive()) {
                break;
            }

            halfHeight = (actor->height / 2) * work->fxScale;

            if (work->flags & EMY_FLAG_DARK_DEATH) {
                BgFxStartDarkDeath(actor->x, actor->y, actor->z - halfHeight, work->fxScale);
            } else {
                BgFxStartEnemyDeath(actor->x, actor->y, actor->z - halfHeight, work->fxScale);
            }

            work->stateTimer++;
        } else if (work->stateTimer > 0) {
            if (gBtlWork->enemyCount == 1 && gBtlWork->pendingEnemies <= 0) {
                FadeStartIn(FADE_MODE_ADD_WHITE, 20);
                FadeLock();
            }

            DropEnemyPrizes(actor);

            if (gGameState.roomEffect == ROOM_EFFECT_PREMIUM_ROOM) {
                if (GetRandom() % 10 == 0) {
                    TryDropPremireCard(actor);
                }
            } else {
                if (GetRandom() % 1000 == 0) {
                    TryDropPremireCard(actor);
                }
            }

            gBtlWork->flags |= BTL_FLAG_ENEMY_DEFEATED;
            SetEnemyJiminyFlag(actor);
            return 0;
        }

        break;
    case EMY_STATE_CARD_BROKEN:
        if (work->stateTimer == 0) {
            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);
        }

        if (AnimIsFinished(&work->anim) && work->stateTimer > 40) {
            ClearBtlObjActionFlags(actor);
            work->state = work->idleState;
            work->stateTimer = 0;
        } else {
            work->stateTimer++;
        }

        break;
    }

    if (actor->badStatus != BAD_STATUS_STOP) {
        actor->z += work->vz;
        work->vz += gBtlWork->gravity;

        if (actor->z > 0) {
            actor->z = 0;
            work->vz = 0;
        }

        if (actor->collider.colliding && !(actor->flags & BTLOBJ_FLAG_IN_CARD_ACTION) && !(actor->collider.other->flags & COLLIDER_FLAG_PASS_THROUGH)) {
            actor->x += actor->collider.pushX >> 1;
            actor->y += actor->collider.pushY >> 1;
        }
    }

    if (actor->vx > 0) {
        actor->x += actor->vx;
        actor->vx -= 17;

        if (actor->vx < 0) {
            actor->vx = 0;
        }
    } else if (actor->vx < 0) {
        actor->x += actor->vx;
        actor->vx += 17;

        if (actor->vx > 0) {
            actor->vx = 0;
        }
    }

    if (actor->vy > 0) {
        actor->y += actor->vy;
        actor->vy -= 17;

        if (actor->vy < 0) {
            actor->vy = 0;
        }
    } else if (actor->vy < 0) {
        actor->y += actor->vy;
        actor->vy += 17;

        if (actor->vy > 0) {
            actor->vy = 0;
        }
    }

    switch (ClampBattlePosition(&actor->x, &actor->y, -20, 0)) {
    case BATTLE_EDGE_LEFT:
    case BATTLE_EDGE_RIGHT:
        work->flags |= EMY_FLAG_AT_FIELD_EDGE;
        actor->vx = -(actor->vx >> 1);
        break;
    case BATTLE_EDGE_TOP:
    case BATTLE_EDGE_BOTTOM:
        work->flags |= EMY_FLAG_AT_FIELD_EDGE;
        actor->vy = -(actor->vy >> 1);
        break;
    default:
        work->flags &= ~EMY_FLAG_AT_FIELD_EDGE;
        break;
    }

    if (actor->flags & BTLOBJ_FLAG_IN_CARD_ACTION) {
        work->gfx = AnimUpdate(&work->anim);
    } else if (actor->badStatus != BAD_STATUS_STOP) {
        if (gBtlWork->flags & BTL_FLAG_ENEMY_FRAME_CHANGED) {
            if (!AnimIsFrameEnding(&work->anim)) {
                work->gfx = AnimUpdate(&work->anim);
            }
        } else {
            if (AnimIsFrameEnding(&work->anim)) {
                gBtlWork->flags |= BTL_FLAG_ENEMY_FRAME_CHANGED;
            }

            work->gfx = AnimUpdate(&work->anim);
        }
    }

    if (actor->badStatus == BAD_STATUS_BIND) {
        actor->x = actor->prevX;
        actor->y = actor->prevY;
    }

    TaskPoolUpdate(&work->tasks);
    ColliderSetPosition(&actor->collider, actor->x, actor->y, actor->z);
    return 1;
}

void EmyDraw(EmyWork* work) {
    if (work->visible) {
        BtlObj* actor;
        u16 flags;
        ObjAffine* affine;
        s32 sx;
        s32 sy;
        s16 x;
        s16 y;

        actor = &work->actor;
        flags = GetBattleSpritePriorityFlags(actor->y) | work->spriteFlags;
        WorldToScreen(&x, &y, actor->x, actor->y, actor->z);

        if (work->scaleX == Q_8_8(1) && work->scaleY == Q_8_8(1)) {
            if (actor->flags & BTLOBJ_FLAG_FACING_LEFT) {
                sy = gBtlWork->scale;
                sx = sy;
            } else if (gBtlWork->scale == Q_8_8(1)) {
                sy = gBtlWork->scale;
                sx = sy;
                flags |= SPRITE_FLAG_HFLIP;
            } else {
                sy = gBtlWork->scale;
                sx = -sy;
            }
        } else {
            if (actor->flags & BTLOBJ_FLAG_FACING_LEFT) {
                sx = (gBtlWork->scale * work->scaleX) >> 8;
                sy = gBtlWork->scale;
                sy = (sy * work->scaleY) >> 8;
            } else {
                sx = -((gBtlWork->scale * work->scaleX) >> 8);
                sy = gBtlWork->scale;
                sy = (sy * work->scaleY) >> 8;
            }
        }

        if (sy == Q_8_8(1) && sx == sy) {
            affine = NULL;
        } else if (sy < Q_8_8(1)) {
            affine = AllocObjAffine(0, sx, sy, FALSE);
        } else {
            affine = AllocObjAffine(0, sx, sy, TRUE);
        }

        if (StepHitFlash(actor)) {
            DrawSprite(x, y, work->gfx, work->tiles, work->palette2, affine, flags, (-4100 - ((actor->y >> 8) << 2)) | 3);
        } else {
            DrawSprite(x, y, work->gfx, work->tiles, work->palette, affine, flags, (-4100 - ((actor->y >> 8) << 2)) | 3);
        }

        TaskPoolDraw(&work->tasks);
    }
}

void EmyReleaseResources(EmyWork* work) {
    gBtlWork->enemyTileCount -= gEnemyTileCounts[work->actor.kind];

    if (gBtlWork->actor2 == &work->actor) {
        gBtlWork->actor2 = NULL;
    }

    ReleaseEnemyBtlObj(&work->actor);

    if (gBtlWork->enemyCount == 0) {
        if (gBtlWork->pendingEnemies <= 0) {
            if (gBtlWork->actor->hp > 0) {
                gBtlWork->flags |= BTL_FLAG_BATTLE_OVER;
            }
        }
    }

    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
    TaskPoolDestroy(&work->tasks);
}
