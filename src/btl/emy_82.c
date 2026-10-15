/**
 * emy_82.c
 * Crescendo Enemy
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
#include "listpool.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy82CommonAnimDefs[3] = {
    { gEmy8200Frames, gEmy8200Anims, gEmy8200Tiles, 0 },
    { gEmy8202Frames, gEmy8202Anims, gEmy8202Tiles, 0 },
    { gEmy8201Frames, gEmy8201Anims, gEmy8201Tiles, 0 },
};

static const AnimDef sEmy82AnimDefs[6] = {
    { gEmy8210jFrames, gEmy8210jAnims, gEmy8210jTiles, 0 },
    { gEmy8210jFrames, gEmy8210jAnims, gEmy8210jTiles, 1 },
    { gEmy8210jFrames, gEmy8210jAnims, gEmy8210jTiles, 2 },
    { gEmy8210Frames, gEmy8210Anims, gEmy8210Tiles, 0 },
    { gEmy8211Frames, gEmy8211Anims, gEmy8211Tiles, 0 },
    { gEmy8212Frames, gEmy8212Anims, gEmy8212Tiles, 0 },
};

static const EmyDef sEmy82Def = { gEmy82Palette, sEmy82CommonAnimDefs, 204, 3, 20, 20, 48, 32, 32, 1, 0, { ENEMY_CRESCENDO, 66, 32, 10, 16, 100, 0 } };

TaskDesc gTaskDescEmy82 = {
    "task_emy_82",
    (TaskInitFunc)task_emy_82_0,
    (TaskUpdateFunc)task_emy_82_1,
    (TaskDrawFunc)task_emy_82_2,
    (TaskDestroyFunc)task_emy_82_3,
    sizeof(Emy82Work),
};

enum Emy82State {
    EMY82_STATE_JUMP_ATTACK = 18,
    EMY82_STATE_HEAL,
    EMY82_STATE_SUMMON,
    EMY82_STATE_IDLE,
    EMY82_STATE_HOP,
    EMY82_STATE_FALL_START,
    EMY82_STATE_FALL,
    EMY82_STATE_LAND
};

void task_emy_82_0(Emy82Work* work, void* obj) {
    EmyInit(&work->base, &sEmy82Def, obj);
    work->base.idleState = EMY82_STATE_IDLE;
    work->spawnCount = 0;
}

u8 GetEmyApproachAngle(EmyWork* work) {
    BtlObj* act;
    s32 x;
    s32 y;
    s32 targetX;
    s32 offset;
    s32 lo;
    s32 actorX;
    s32 actorY;
    s32 targetY;

    act = &work->actor;
    GetEnemyTargetPosition(act, &x, &y, NULL);

    if (x < (gBtlWork->xMin + 0x30) << 8) {
        targetX = x + 0x28;
    } else if (x > (gBtlWork->xMax - 0x30) << 8) {
        targetX = x - 0x28;
    } else {
        offset = (work->actor.attackOffset + ((lo = -work->actor.attackRangeX) +
            GetRandom() % (work->actor.attackRangeX - lo + 1))) << 8;

        if (act->x < x) {
            targetX = x - offset;
        } else {
            targetX = x + offset;
        }
    }

    targetY = y;
    actorX = act->x;
    actorY = act->y;
    return GetAngle(actorX, actorY, targetX, targetY);
}

u8 task_emy_82_1(Emy82Work* work) {
    Emy82Work* w;
    BtlObj* act;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        switch ((u16)(GetRandom() % 3U)) {
        case 0:
            work->base.state = EMY82_STATE_JUMP_ATTACK;
            break;
        case 1:
            if (gBtlWork->enemyCount > 1) {
                work->base.state = EMY82_STATE_HEAL;
            } else {
                work->base.state = EMY82_STATE_JUMP_ATTACK;
            }

            break;
        case 2:
            work->base.state = EMY82_STATE_SUMMON;
            break;
        }
    }

    switch (work->base.state) {
    case EMY_STATE_CARD_BROKEN:
        if (work->base.stateTimer == 0) {
            m4aSongNumStop(SONG_EF_RAPPA_CALL);
        }

        break;
    case EMY82_STATE_HOP:
        AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 2, ANIM_FLAG_LOOP, w->base.tiles);

        if (act->z < act->groundZ && (gBtlWork->flags & BTL_FLAG_ENEMY_MOVE_ENABLED)) {
            act->x += gSineTable[work->base.angle] * work->base.speed >> 8;
            act->y += -gSineTable[work->base.angle + 64] * work->base.speed >> 8;

            if ((u16)((u32)GetRandom() % work->base.def->turnInterval) == 0) {
                s32 x;
                GetEnemyTargetPosition(act, &x, NULL, NULL);

                if (act->x > x) {
                    act->flags |= BTLOBJ_FLAG_FACING_LEFT;
                } else {
                    act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
                }
            }
        } else {
            switch (AnimGetFrame(&work->base.anim)) {
            case 6:
                if (work->base.anim.timer > 2 && (u16)(GetRandom() % 15U) == 0) {
                    work->base.state = work->base.idleState;
                }

                break;
            case 1:
                if (work->base.anim.timer == 0) {
                    work->base.angle = GetEmyApproachAngle(&work->base);
                    TryEnemyCardUse(act);
                    work->base.vz = -0x3CC;
                }

                break;
            }
        }

        break;
    case EMY82_STATE_IDLE:
        AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);

        if ((u16)((u32)GetRandom() % work->base.def->turnInterval) == 0) {
            s32 x;
            GetEnemyTargetPosition(act, &x, NULL, NULL);

            if (act->x > x) {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            } else {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            }
        }

        switch (AnimGetGfxIndex(&work->base.anim)) {
        case 0:
            if (work->base.anim.timer == 5 && (u16)((u32)GetRandom() % work->base.def->moveInterval) == 0) {
                work->base.state = EMY82_STATE_HOP;
                work->base.angle = GetEmyApproachAngle(&work->base);
            }

            break;
        case 2:
            if (work->base.anim.timer == 0 && act->z >= act->groundZ) {
                work->base.vz = -0x4C0;
                TryEnemyCardUse(act);
            }

            break;
        }

        break;
    case EMY82_STATE_JUMP_ATTACK:
        {
            s32 adjustedX;
            s32 currentX;
            s32 targetX;
            u32 frame;
            s32 hitX;

            if (work->base.stateTimer == 0) {
                AnimChangeWithDef(sEmy82AnimDefs, &w->base.anim, 3, 0, w->base.tiles);
                work->base.vz = -0x400;
            }

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                targetX = 0x3000;
                currentX = act->x;
                adjustedX = currentX + targetX;
            } else {
                targetX = -0x3000;
                currentX = act->x;
                adjustedX = currentX + targetX;
            }

            targetX = act->originX;
            targetX -= adjustedX;
            targetX >>= 4;
            currentX += targetX;
            act->x = currentX;
            frame = AnimGetFrame(&work->base.anim);

            if (frame > 3) {
                work->base.vz = 0;
            }

            if (frame == 4) {
                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    hitX = act->x - 0x1400;
                } else {
                    hitX = act->x + 0x1400;
                }

                if (ApplyAttackBox(0xDE, hitX, act->y, act->z + 0x800, 10, 10, 20)) {
                    m4aSongNumStart(SONG_BTL_MON_HIT00);
                }
            } else if (frame == 5) {
                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    hitX = act->x - 0x1800;
                } else {
                    hitX = act->x + 0x1800;
                }

                if (ApplyAttackBox(0xDE, hitX, act->y, act->z - 0x2300, 10, 10, 10)) {
                    m4aSongNumStart(SONG_BTL_MON_HIT00);
                }
            }

            if (AnimIsFinished(&work->base.anim)) {
                work->base.state = EMY82_STATE_FALL_START;
            } else {
                work->base.stateTimer++;
            }
        }

        break;
    case EMY82_STATE_HEAL:
        {
            u32 frame;

            if (work->base.stateTimer == 0) {
                AnimChangeWithDef(sEmy82AnimDefs, &w->base.anim, 4, 0, w->base.tiles);
            }

            frame = AnimGetFrame(&work->base.anim);

            if (frame > 1) {
                work->base.vz = 0;
            }

            if (work->base.anim.timer == 0) {
                switch (frame) {
                case 1:
                    work->base.vz = -0x100;
                    m4aSongNumStart(SONG_EF_RAPPA_CALL);
                    break;
                case 4:
                    {
                        BtlObj* best = NULL;
                        BtlObj* actor;
                        s16 missing = 0;

                        for (actor = ListPoolFirst(&gBtlWork->pool); actor;
                             actor = ListPoolNext(&actor->node)) {
                            if (actor != act && !(actor->flags & BTLOBJ_FLAG_INTANGIBLE)) {
                                if (missing <= actor->maxHp - actor->hp) {
                                    missing = actor->maxHp - actor->hp;
                                    best = actor;
                                }
                            }
                        }

                        if (best) {
                            m4aSongNumStart(SONG_EF_CAREL00);
                            best->flags |= BTLOBJ_FLAG_HEAL_PENDING;
                            best->damage = 0xFFEC;
                        } else {
                            CreateBtlPopTask(act, BTL_POP_MISS);
                        }
                    }

                    break;
                }
            }

            if (AnimIsFinished(&work->base.anim)) {
                work->base.state = EMY82_STATE_FALL_START;
            } else {
                work->base.stateTimer++;
            }
        }

        break;
    case EMY82_STATE_SUMMON:
        {
            u32 frame;

            if (work->base.stateTimer == 0) {
                AnimChangeWithDef(sEmy82AnimDefs, &w->base.anim, 5, 0, w->base.tiles);
            }

            frame = AnimGetFrame(&work->base.anim);

            if ((u16)(frame - 2) <= 21) {
                work->base.vz = 0;
            }

            if (work->base.anim.timer == 0) {
                switch (frame) {
                case 1:
                    work->base.vz = -0x100;
                    m4aSongNumStart(SONG_EF_RAPPA_CALL);
                    break;
                case 24:
                    work->base.vz = -0x380;

                    if (gBtlWork->enemyCount <= 3 && (s16)w->spawnCount <= 2) {
                        u32 spawnFailure = 0;
                        s32 x;
                        s32 offset;

                        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                            x = act->x;
                            offset = 0x2000;
                        } else {
                            x = act->x;
                            offset = -0x2000;
                        }

                        x += offset;
                        offset = act->y;

                        if (SpawnEnemy(ENEMY_SOLDIER, x, offset, act->z - 0xC00) != spawnFailure) {
                            gBtlWork->pendingEnemies++;
                            w->spawnCount++;
                        } else {
                            CreateBtlPopTask(act, BTL_POP_MISS);
                        }
                    } else {
                        CreateBtlPopTask(act, BTL_POP_MISS);
                    }

                    break;
                }
            }

            if (AnimIsFinished(&work->base.anim)) {
                work->base.state = EMY82_STATE_FALL_START;
            } else {
                work->base.stateTimer++;
            }
        }

        break;
    case EMY82_STATE_FALL_START:
        AnimChangeWithDef(sEmy82AnimDefs, &w->base.anim, 0, 0, w->base.tiles);
        work->base.vz = 0;

        if (AnimIsFinished(&work->base.anim)) {
            work->base.state = EMY82_STATE_FALL;
        }

        break;
    case EMY82_STATE_FALL:
        AnimChangeWithDef(sEmy82AnimDefs, &w->base.anim, 1, 0, w->base.tiles);

        if (act->z >= act->groundZ) {
            work->base.state = EMY82_STATE_LAND;
        }

        break;
    case EMY82_STATE_LAND:
        AnimChangeWithDef(sEmy82AnimDefs, &w->base.anim, 2, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 1 && work->base.anim.timer == 0) {
            work->base.vz = -0x333;
        }

        if (AnimIsFinished(&work->base.anim)) {
            EmyReturnToIdle(&work->base);
        }

        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_82_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_82_3(EmyWork* work) {
    EmyReleaseResources(work);
}
