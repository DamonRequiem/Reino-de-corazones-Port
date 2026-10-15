/**
 * hum_ansem.c
 * Ansem Boss
 */

#include "system_state.h"
#include "fade.h"
#include "hum.h"
#include "sprites_hum.h"
#include "hum_common.h"
#include "songs.h"
#include "hum_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_collision.h"
#include "btl_effect.h"
#include "card_api.h"
#include "engine_math.h"
#include "hum_types.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "battle_ids.h"
#include "enemy_ids.h"
#include "card_ids.h"

static const u32 sHumAnsemStockMovesA[3] = {
    MOVE_BOSS_A, MOVE_BOSS_B, MOVE_BOSS_B,
};

static const u32 sHumAnsemStockMovesB[3] = {
    MOVE_BOSS_A, MOVE_BOSS_B, MOVE_BOSS_A,
};

static const AnimDef sHumAnsemAnimDefs[7] = {
    { gAnsemBt00Frames, gAnsemBt00Anims, gAnsemBt00Tiles, 0 },
    { gAnsemBt01Frames, gAnsemBt01Anims, gAnsemBt01Tiles, 0 },
    { gAnsemBt03Frames, gAnsemBt03Anims, gAnsemBt03Tiles, 0 },
    { gAnsemBt04Frames, gAnsemBt04Anims, gAnsemBt04Tiles, 0 },
    { gAnsemBt05Frames, gAnsemBt05Anims, gAnsemBt05Tiles, 0 },
    { gAnsemBt05Frames, gAnsemBt05Anims, gAnsemBt05Tiles, 1 },
    { gAnsemBt05Frames, gAnsemBt05Anims, gAnsemBt05Tiles, 2 },
};

static const AnimDef sHumAnsemBackAnimDefs[10] = {
    { gAnsembackBt00Frames, gAnsembackBt00Anims, gAnsembackBt00Tiles, 0 },
    { gAnsembackBt01Frames, gAnsembackBt01Anims, gAnsembackBt01Tiles, 0 },
    { gAnsembackBt02Frames, gAnsembackBt02Anims, gAnsembackBt02Tiles, 0 },
    { gAnsembackBt03Frames, gAnsembackBt03Anims, gAnsembackBt03Tiles, 0 },
    { gAnsembackBt03bFrames, gAnsembackBt03bAnims, gAnsembackBt03bTiles, 1 },
    { gAnsembackBt03bFrames, gAnsembackBt03bAnims, gAnsembackBt03bTiles, 0 },
    { gAnsembackBt04Frames, gAnsembackBt04Anims, gAnsembackBt04Tiles, 0 },
    { gAnsembackBt05Frames, gAnsembackBt05Anims, gAnsembackBt05Tiles, 0 },
    { gAnsembackBt05Frames, gAnsembackBt05Anims, gAnsembackBt05Tiles, 1 },
    { gAnsembackBt05Frames, gAnsembackBt05Anims, gAnsembackBt05Tiles, 2 },
};

static const HumSubDef sHumAnsemSubDef = { gAnsembackPalette, 128 };

static const HumDef sHumAnsemDef = { 80, gAnsemPalette, 0, { ENEMY_ANSEM, 99, 65, 14, 42, 99, 0 } };

TaskDesc gTaskDescHumAnsem = {
    "task_hum_ansem",
    (TaskInitFunc)task_hum_ansem_0,
    (TaskUpdateFunc)task_hum_ansem_1,
    (TaskDrawFunc)task_hum_ansem_2,
    (TaskDestroyFunc)task_hum_ansem_3,
    sizeof(AnsemWork),
};

void AnsemHover(HumWork* work, s32 hoverZ) {
    BtlObj* act = &work->actor;
    s32 bobZ;

    if (hoverZ != 0) {
        bobZ = hoverZ + gSineTable[gFrameCounter * 4 % 256] * 8;
        work->vz = 0;
        act->z += (bobZ - act->z) >> 4;
    }
}

void AnsemPlaceSub(AnsemWork* work) {
    BtlObj* act = &work->base.actor;

    if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
        work->subOffsetX += (0x1800 - work->subOffsetX) >> 3;
    } else {
        work->subOffsetX += (-0x1800 - work->subOffsetX) >> 3;
    }

    work->subOffsetZ += (-0x1200 - work->subOffsetZ) >> 3;
    work->sub.x = act->x + work->subOffsetX;
    work->sub.y = act->y;
    work->sub.z = act->z + work->subOffsetZ;
}

void task_hum_ansem_0(AnsemWork* work) {
    HumInit(&work->base, &sHumAnsemDef);
    HumSubInit(&work->base, &work->sub, &sHumAnsemSubDef);
    work->hoverZ = -0xC00;
    work->subOffsetX = 0;
    work->base.boundsMargin = -50;
    work->base.stockMoves = sHumAnsemStockMovesA;
}

enum HumAnsemState {
    HUM_ANSEM_STATE_GUARDIAN_STRIKE = 20,
    HUM_ANSEM_STATE_GUARDIAN_SUMMON,
    HUM_ANSEM_STATE_GUARDIAN_ASCEND,
    HUM_ANSEM_STATE_GUARDIAN_ERUPT,
    HUM_ANSEM_STATE_GUARDIAN_RETURN,
    HUM_ANSEM_STATE_WAVE,
    HUM_ANSEM_STATE_RUSH_START,
    HUM_ANSEM_STATE_RUSH,
    HUM_ANSEM_STATE_RUSH_END,
    HUM_ANSEM_STATE_GUARD
};

u8 task_hum_ansem_1(AnsemWork* work) {
    AnsemWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 prevX;
    s32 prevY;
    s32 prevZ;
    s32 offset;

    w = work;
    act = &work->base.actor;
    GetEnemyTargetPosition(act, &x, &y, NULL);

    switch (HumUpdateReaction(&work->base)) {
    case BTL_REACTION_CARD_ACTION:
        work->base.stateTimer = 0;
        act->flags &= ~(BTLOBJ_FLAG_GUARD_PHYSICAL | BTLOBJ_FLAG_INVULNERABLE);
        MakeOpponentsHittable();

        switch ((u32)HumResolveCardMove(&work->base)) {
        case MOVE_BOSS_A:
        case MOVE_BOSS_C:
            work->base.state = HUM_ANSEM_STATE_GUARDIAN_STRIKE;
            break;
        case MOVE_BOSS_B:
        case MOVE_BOSS_D:
            work->base.state = HUM_ANSEM_STATE_WAVE;
            break;
        case MOVE_ROCKSHATTER:
            work->base.state = HUM_ANSEM_STATE_RUSH_START;
            work->repeatCount = 0;
            break;
        case MOVE_DARK_SHADOW:
            work->base.state = HUM_ANSEM_STATE_GUARDIAN_SUMMON;
            work->repeatCount = 0;
            break;
        }

        break;
    case BTL_REACTION_CARD_BROKEN:
        act->flags &= ~(BTLOBJ_FLAG_GUARD_PHYSICAL | BTLOBJ_FLAG_INVULNERABLE);
        work->sub.flags &= ~(HUM_SUB_FLAG_IN_FRONT | HUM_SUB_FLAG_OWN_DEPTH);
        break;
    }

    if (gBtlWork->battleId == BATTLE_ANSEM_1) {
        HumChooseCardAction(&work->base, 30, 80, 80, 24);
    } else if (HumChooseCardAction(&work->base, 2, 80, 80, 24)) {
        if (GetRandom() % 2) {
            work->base.stockMoves = sHumAnsemStockMovesA;
        } else {
            work->base.stockMoves = sHumAnsemStockMovesB;
        }
    }

    switch (work->base.state) {
    case HUM_STATE_ENTER:
    case HUM_STATE_USE_ITEM:
        AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 0, ANIM_FLAG_LOOP, w->base.sub->tiles);
        break;
    case HUM_STATE_RELOAD:
        AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 0, ANIM_FLAG_LOOP, w->base.sub->tiles);
        w->hoverZ = -0x5000;
        break;
    case HUM_STATE_IDLE:
        AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 0, ANIM_FLAG_LOOP, w->base.sub->tiles);
        w->hoverZ = -0xC00;

        if (func_08081828()) {
            break;
        }

        if (gBtlWork->battleId == BATTLE_ANSEM_2) {
            if ((u16)(GetRandom() % 15) == 0) {
                if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
                    work->base.state = HUM_ANSEM_STATE_GUARD;
                    work->base.stateTimer = 0;
                    break;
                }
            }
        }

        if ((u16)(GetRandom() % 80) == 0) {
            work->base.state = HUM_STATE_MOVE;
            work->base.stateTimer = 0;
            break;
        }

        HumFaceTarget(&work->base, 3);
        work->base.stateTimer++;
        break;
    case HUM_STATE_MOVE:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
            AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 0, ANIM_FLAG_LOOP, w->base.sub->tiles);
            w->hoverZ = -0xC00;
            work->base.targetY = y;

            if (act->x < x) {
                work->base.targetX = x - 0x7800;
            } else {
                work->base.targetX = x + 0x7800;
            }
        }

        if (gBtlWork->battleId == BATTLE_ANSEM_2) {
            if ((u16)(GetRandom() % 30) == 0) {
                if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
                    work->base.state = HUM_ANSEM_STATE_GUARD;
                    work->base.stateTimer = 0;
                    break;
                }
            }
        }

        if (HumMoveToward(&work->base, work->base.targetX, work->base.targetY, 0x300)) {
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
            break;
        }

        HumFaceTarget(&work->base, 1);
        work->base.stateTimer++;
        break;
    case HUM_STATE_HURT:
    case HUM_STATE_DEFEATED:
    case HUM_STATE_CARD_BROKEN:
    case HUM_STATE_STUNNED:
    case HUM_STATE_GRAVITY:
        w->hoverZ = 0;
        AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 1, 0, w->base.tiles);
        AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 1, 0, w->base.sub->tiles);
        break;
    case HUM_STATE_HURT_RECOVER:
        if (gBtlWork->battleId != BATTLE_ANSEM_2) {
            break;
        }

        if (!(gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION)) {
            break;
        }

        if (!(GetRandom() % 2)) {
            break;
        }

        work->base.state = HUM_ANSEM_STATE_GUARD;
        work->base.stateTimer = 0;
        break;
    case HUM_ANSEM_STATE_GUARDIAN_STRIKE:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
            AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 2, 0, w->base.sub->tiles);
            w->hoverZ = -0x800;
            m4aSongNumStart(SONG_VO_AN_ATTACK00);
        }

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            s32 frontX = act->x - 0x2800;
            act->x = act->x + ((x - frontX) >> 4);
        } else {
            s32 frontX = act->x + 0x2800;
            act->x = act->x + ((x - frontX) >> 4);
        }

        act->y += (y - act->y) >> 4;

        switch (AnimGetFrame(&w->sub.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x -= 0x100;
            } else {
                act->x += 0x100;
            }

            break;
        case 4:
            w->sub.flags |= HUM_SUB_FLAG_IN_FRONT;

            if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                ? ApplyAttackBox(0x140, act->x - 0x2000, act->y, act->z, 20, 12, 24)
                : ApplyAttackBox(0x140, act->x + 0x2000, act->y, act->z, 20, 12, 24)) {
                m4aSongNumStart(SONG_BTL_MON_HIT06);
            }

            break;
        }

        if (AnimIsFinished(&w->sub.anim)) {
            w->sub.flags &= ~HUM_SUB_FLAG_IN_FRONT;
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_ANSEM_STATE_GUARDIAN_SUMMON:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 2, 0, w->base.tiles);
            AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 3, 0, w->base.sub->tiles);
            w->subRiseSpeed = 0;
            FadeStartOut(FADE_MODE_DARK_MAGENTA, 90);
            m4aSongNumStart(SONG_BTL_AN_STANDENTRY);
            w->hoverZ = -0xC00;
        }

        switch (AnimGetFrame(&w->sub.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            AnsemPlaceSub(w);
            break;
        default:
            w->subRiseSpeed += 25;
            w->sub.z -= w->subRiseSpeed;
            break;
        }

        if (AnimIsFinished(&w->sub.anim)) {
            work->base.state = HUM_ANSEM_STATE_GUARDIAN_ASCEND;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_ANSEM_STATE_GUARDIAN_ASCEND:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
            AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 5, 0, w->base.sub->tiles);
        }

        w->subRiseSpeed += 25;
        w->sub.z -= w->subRiseSpeed;

        if (w->sub.z < -0x12C00) {
            work->base.state = HUM_ANSEM_STATE_GUARDIAN_ERUPT;
            work->base.stateTimer = 0;
            break;
        }

        work->base.stateTimer++;
        break;
    case HUM_ANSEM_STATE_GUARDIAN_ERUPT:
        if (work->base.stateTimer == 0) {
            AnimReset(&w->sub.anim);
            AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
            AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 4, 0, w->base.sub->tiles);
            w->subRiseSpeed = 0x800;
            w->sub.x = x + (offset = ((u16)(GetRandom() % 65) << 8) - 0x2000);
            w->sub.y = y;
            w->sub.z = 0;
            w->sub.flags |= HUM_SUB_FLAG_OWN_DEPTH;
            m4aSongNumStart(SONG_EF_AN_STANDUP);
        }

        switch (AnimGetFrame(&w->sub.anim)) {
        case 5:
            if (w->sub.anim.timer == 4) {
                m4aSongNumStart(SONG_EF_BOSS_DEADL);
            }

            break;
        case 6:
            w->subRiseSpeed += 25;
            w->sub.z -= w->subRiseSpeed;
            break;
        }

        if ((s16)(work->base.stateTimer % 10) == 0) {
            MakeOpponentsHittable();
        }

        switch (AnimGetFrame(&w->sub.anim)) {
        case 2:
        case 3:
            if (ApplyAttackBox(0x141, w->sub.x, w->sub.y,
                    w->sub.z - 0x800, 20, 16, 8)) {
                m4aSongNumStart(SONG_BTL_MON_HIT06);
            }

            break;
        case 4:
            if (ApplyAttackBox(0x141, w->sub.x, w->sub.y,
                    w->sub.z - 0x1000, 20, 16, 16)) {
                m4aSongNumStart(SONG_BTL_MON_HIT00);
            }

            break;
        case 5:
            if (ApplyAttackBox(0x141, w->sub.x, w->sub.y,
                    w->sub.z - 0x2000, 20, 16, 32)) {
                m4aSongNumStart(SONG_BTL_MON_HIT00);
            }

            break;
        case 6:
            if (ApplyAttackBox(0x141, w->sub.x, w->sub.y,
                    w->sub.z - 0x3000, 20, 16, 48)) {
                m4aSongNumStart(SONG_BTL_MON_HIT00);
            }

            break;
        }

        if (w->sub.z < -0x12C00) {
            w->sub.flags &= ~HUM_SUB_FLAG_OWN_DEPTH;
            work->base.stateTimer = 0;

            if (w->repeatCount > 6) {
                work->base.state = HUM_ANSEM_STATE_GUARDIAN_RETURN;
                break;
            }

            work->base.state = HUM_ANSEM_STATE_GUARDIAN_ERUPT;
            w->repeatCount++;
            break;
        }

        work->base.stateTimer++;
        break;
    case HUM_ANSEM_STATE_GUARDIAN_RETURN:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 0, ANIM_FLAG_LOOP, w->base.sub->tiles);
            w->steps = 30;
        }

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            ApproachValueHalfSteps(&w->sub.x, act->x + 0x1800, w->steps);
        } else {
            ApproachValueHalfSteps(&w->sub.x, act->x - 0x1800, w->steps);
        }

        ApproachValueHalfSteps(&w->sub.y, act->y, w->steps);
        ApproachValueHalfSteps(&w->sub.z, act->z, w->steps);
        w->steps--;

        if (w->steps <= 0) {
            FadeStartIn(FADE_MODE_BLACK, 30);
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_ANSEM_STATE_GUARD:
        if (work->base.stateTimer == 0) {
            AnimReset(&w->sub.anim);
            AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 7, 0, w->base.sub->tiles);
            w->sub.flags |= HUM_SUB_FLAG_IN_FRONT;
            act->originX = act->x;
            act->flags |= BTLOBJ_FLAG_CARD_USE_BLOCKED;
        }

        HumFaceTarget(&work->base, 1);

        if (AnimGetFrame(&w->sub.anim) != 0) {
            act->flags |= (BTLOBJ_FLAG_GUARD_PHYSICAL | BTLOBJ_FLAG_INVULNERABLE);

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                s32 frontX = act->x - 0x1000;
                act->x = act->x + ((act->originX - frontX) >> 2);
            } else {
                s32 frontX = act->x + 0x1000;
                act->x = act->x + ((act->originX - frontX) >> 2);
            }

            w->subOffsetX += (0 - w->subOffsetX) >> 2;
            w->subOffsetZ += (0 - w->subOffsetZ) >> 2;
            w->sub.x = act->x + w->subOffsetX;
            w->sub.y = act->y;
            w->sub.z = act->z + w->subOffsetZ;
        }

        if (work->base.stateTimer == 25) {
            act->flags &= ~BTLOBJ_FLAG_CARD_USE_BLOCKED;
        }

        if (work->base.stateTimer > 50) {
            w->sub.flags &= ~HUM_SUB_FLAG_IN_FRONT;
            act->flags &= ~(BTLOBJ_FLAG_GUARD_PHYSICAL | BTLOBJ_FLAG_INVULNERABLE);
            work->base.stateTimer = 0;
            work->base.state = HUM_STATE_IDLE;
            break;
        }

        work->base.stateTimer++;
        break;
    case HUM_ANSEM_STATE_RUSH_START:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 4, 0, w->base.tiles);
            AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 7, 0, w->base.sub->tiles);
            w->hoverZ = -0xC00;
            m4aSongNumStart(SONG_VO_AN_ATTACK01);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = HUM_ANSEM_STATE_RUSH;
            break;
        }

        work->base.stateTimer++;
        break;
    case HUM_ANSEM_STATE_RUSH:
        if (work->base.stateTimer == 0) {
            if (act->x <= 0xFFFF) {
                work->base.targetX = (gBtlWork->xMax - 48) << 8;
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            } else {
                work->base.targetX = (gBtlWork->xMin + 48) << 8;
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            }

            work->base.targetY = y;
            AnimReset(&work->base.anim);
            AnimReset(&w->sub.anim);
            AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 5, ANIM_FLAG_LOOP, w->base.tiles);
            AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 8, ANIM_FLAG_LOOP, w->base.sub->tiles);
            w->hoverZ = -0xC00;
            w->steps = 40;
            BgFxStartAnsemRush(w->sub.x, w->sub.y,
                w->sub.z - 0x2100, act->flags & BTLOBJ_FLAG_FACING_LEFT);
        }

        prevX = w->sub.x;
        prevY = w->sub.y;
        prevZ = w->sub.z;

        if (w->steps > 0) {
            ApproachValue(&act->x, work->base.targetX, w->steps);
            ApproachValueHalfSteps(&act->y, work->base.targetY, w->steps);
        }

        w->steps--;

        if (work->base.stateTimer > 5) {
            w->sub.flags |= HUM_SUB_FLAG_IN_FRONT;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                w->subOffsetX += (-0x2200 - w->subOffsetX) >> 3;
            } else {
                w->subOffsetX += (0x2200 - w->subOffsetX) >> 3;
            }

            w->subOffsetZ += (0 - w->subOffsetZ) >> 3;
            w->sub.x = act->x + w->subOffsetX;
            w->sub.y = act->y;
            w->sub.z = act->z + w->subOffsetZ;
        } else {
            AnsemPlaceSub(w);
        }

        if (ApplyAttackBox(0x143, w->sub.x, w->sub.y,
                w->sub.z, 32, 16, 32)) {
            m4aSongNumStart(SONG_BTL_MON_HIT02);
        }

        BgFxAddPosition(w->sub.x - prevX, w->sub.y - prevY, w->sub.z - prevZ);

        if (w->steps <= 0) {
            w->sub.flags &= ~HUM_SUB_FLAG_IN_FRONT;
            work->base.stateTimer = 0;

            if (w->repeatCount > 3) {
                work->base.state = HUM_ANSEM_STATE_RUSH_END;
                break;
            }

            work->base.state = HUM_ANSEM_STATE_RUSH;
            w->repeatCount++;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_ANSEM_STATE_RUSH_END:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 6, 0, w->base.tiles);
            AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 9, 0, w->base.sub->tiles);
            w->hoverZ = -0xC00;
        }

        if (!AnimIsFinished(&work->base.anim)) {
            break;
        }

        ClearBtlObjActionFlags(act);
        work->base.state = HUM_STATE_IDLE;
        work->base.stateTimer = 0;
        break;
    case HUM_ANSEM_STATE_WAVE:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAnsemAnimDefs, &w->base.anim, 3, 0, w->base.tiles);
            AnimChangeWithDef(sHumAnsemBackAnimDefs, &w->base.sub->anim, 6, 0, w->base.sub->tiles);
            FadeToAmount(FADE_MODE_BLACK, gBtlWork->fadeAmount, 8);
            w->hoverZ = -0xC00;
        }

        if (work->base.stateTimer == 20) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                BgFxStartAnsemWave(act->x, act->y, 0, TRUE, 0x142);
            } else {
                BgFxStartAnsemWave(act->x, act->y, 0, FALSE, 0x142);
            }
        }

        switch (AnimGetFrame(&w->sub.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            AnsemPlaceSub(w);
            break;
        case 5:
            if (w->sub.anim.timer == 0) {
                w->steps = 8;
            }

            if (w->steps > 0) {
                ApproachValueHalfSteps(&w->sub.z, act->z - 0x3000, w->steps);
                w->steps--;
            }

            break;
        case 6:
            if (w->sub.anim.timer == 0) {
                w->steps = 8;
            }

            if (w->steps > 0) {
                ApproachValueHalfSteps(&w->sub.z, act->z - 0x1000, w->steps);
                w->steps--;
            }

            break;
        }

        if (AnimIsFinished(&w->sub.anim)) {
            if (!BgFxIsActive()) {
                ClearBtlObjActionFlags(act);
                FadeToOriginal(FADE_MODE_BLACK, 8);
                work->base.state = HUM_STATE_IDLE;
                work->base.stateTimer = 0;
                break;
            }
        }

        work->base.stateTimer++;
        break;
    }

    if (!(act->flags & BTLOBJ_FLAG_HURT) && act->badStatus != BAD_STATUS_STOP) {
        AnsemHover(&work->base, w->hoverZ);
    }

    switch (work->base.state) {
    case HUM_ANSEM_STATE_GUARDIAN_SUMMON:
    case HUM_ANSEM_STATE_GUARDIAN_ASCEND:
    case HUM_ANSEM_STATE_GUARDIAN_ERUPT:
    case HUM_ANSEM_STATE_WAVE:
    case HUM_ANSEM_STATE_RUSH:
    case HUM_ANSEM_STATE_GUARD:
        break;
    default:
        AnsemPlaceSub(w);
        break;
    }

    return HumUpdate(&work->base);
}

void task_hum_ansem_2(HumWork* work) {
    HumDraw(work);
}

void task_hum_ansem_3(HumWork* work) {
    HumReleaseResources(work);
}
