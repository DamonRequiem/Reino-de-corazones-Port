/**
 * hum_axcel.c
 * Axel Boss
 */

#include "system_state.h"
#include "fade.h"
#include "obj_api.h"
#include "hum.h"
#include "sprites_btl.h"
#include "sprites_hum.h"
#include "btl_api.h"
#include "hum_common.h"
#include "songs.h"
#include "hum_tasks.h"
#include "anim.h"
#include "battle.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_collision.h"
#include "btl_effect.h"
#include "card_api.h"
#include "engine_math.h"
#include "hum_types.h"
#include "m4a_song.h"
#include "obj.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "battle_ids.h"
#include "card_label_data.h"
#include "enemy_ids.h"
#include "card_ids.h"

static const u32 sHumAxcelStockMoves[2][3] = {
    { MOVE_BOSS_A, MOVE_BOSS_A, MOVE_BOSS_A },
    { MOVE_BOSS_A, MOVE_BOSS_B, MOVE_BOSS_A },
};

static const AnimDef sHumAxcelAnimDefs[14] = {
    { gAcceleBt00Frames, gAcceleBt00Anims, gAcceleBt00Tiles, 0 },
    { gAcceleBt01Frames, gAcceleBt01Anims, gAcceleBt01Tiles, 0 },
    { gAcceleBt02Frames, gAcceleBt02Anims, gAcceleBt02Tiles, 0 },
    { gAcceleBt03Frames, gAcceleBt03Anims, gAcceleBt03Tiles, 1 },
    { gAcceleBt03Frames, gAcceleBt03Anims, gAcceleBt03Tiles, 2 },
    { gAcceleBt04Frames, gAcceleBt04Anims, gAcceleBt04Tiles, 0 },
    { gAcceleBt04Frames, gAcceleBt04Anims, gAcceleBt04Tiles, 1 },
    { gAcceleBt04Frames, gAcceleBt04Anims, gAcceleBt04Tiles, 2 },
    { gAcceleBt06Frames, gAcceleBt06Anims, gAcceleBt06Tiles, 0 },
    { gAcceleBt06Frames, gAcceleBt06Anims, gAcceleBt06Tiles, 1 },
    { gAcceleBt06Frames, gAcceleBt06Anims, gAcceleBt06Tiles, 2 },
    { gAcceleBt05Frames, gAcceleBt05Anims, gAcceleBt05Tiles, 0 },
    { gAcceleBt05Frames, gAcceleBt05Anims, gAcceleBt05Tiles, 1 },
    { gAcceleBt05Frames, gAcceleBt05Anims, gAcceleBt05Tiles, 2 },
};

static const AnimDef sHumAxcelWeaponAnimDefs[10] = {
    { gAcceleBtWepFrames, gAcceleBtWepAnims, gAcceleBtWepTiles, 0 },
    { gAcceleBt06WepFrames, gAcceleBt06WepAnims, gAcceleBt06WepTiles, 0 },
    { gAcceleBt06WepFrames, gAcceleBt06WepAnims, gAcceleBt06WepTiles, 1 },
    { gAcceleBt06WepFrames, gAcceleBt06WepAnims, gAcceleBt06WepTiles, 2 },
    { gAcceleBt06WepFrames, gAcceleBt06WepAnims, gAcceleBt06WepTiles, 7 },
    { gAcceleBt06WepFrames, gAcceleBt06WepAnims, gAcceleBt06WepTiles, 3 },
    { gAcceleBt06WepFrames, gAcceleBt06WepAnims, gAcceleBt06WepTiles, 4 },
    { gAcceleBt06WepFrames, gAcceleBt06WepAnims, gAcceleBt06WepTiles, 5 },
    { gAcceleBt06WepFrames, gAcceleBt06WepAnims, gAcceleBt06WepTiles, 8 },
    { gAcceleBt06WepFrames, gAcceleBt06WepAnims, gAcceleBt06WepTiles, 6 },
};

static const HumSubDef sHumAxcelSubDef = { gBStatesPalette, 64 };

static const HumDef sHumAxcelDef = {
#ifdef VERSION_EU
        102
#else
        128
#endif
    , gAccelePalette, 0, { ENEMY_AXEL, 99, 60, 14, 32, 99, 0 } };

TaskDesc gTaskDescHumAxcel = {
    "task_hum_axcel",
    (TaskInitFunc)task_hum_axcel_0,
    (TaskUpdateFunc)task_hum_axcel_1,
    (TaskDrawFunc)task_hum_axcel_2,
    (TaskDestroyFunc)task_hum_axcel_3,
    sizeof(AxcelWork),
};

static TaskDesc sTaskDescHumAxcelPtc = {
    "task_hum_axcel_ptc",
    (TaskInitFunc)task_hum_axcel_ptc_0,
    (TaskUpdateFunc)task_hum_axcel_ptc_1,
    (TaskDrawFunc)task_hum_axcel_ptc_2,
    (TaskDestroyFunc)task_hum_axcel_ptc_3,
    sizeof(AxcelPtcWork),
};

enum HumAxcelState {
    HUM_AXCEL_STATE_WARP = 19,
    HUM_AXCEL_STATE_SLASH,
    HUM_AXCEL_STATE_SLASH_FOLLOWUP,
    HUM_AXCEL_STATE_THROW_APPROACH,
    HUM_AXCEL_STATE_THROW_WINDUP,
    HUM_AXCEL_STATE_THROW,
    HUM_AXCEL_STATE_CATCH,
    HUM_AXCEL_STATE_CHAKRAM_IGNITE,
    HUM_AXCEL_STATE_CHAKRAM_SWEEP,
    HUM_AXCEL_STATE_CHAKRAM_END,
    HUM_AXCEL_STATE_CHAKRAM_ORBIT,
    HUM_AXCEL_STATE_CHAKRAM_EXIT,
    HUM_AXCEL_STATE_CHAKRAM_BOUNCE,
    HUM_AXCEL_STATE_FIRE_WALL_WINDUP,
    HUM_AXCEL_STATE_FIRE_WALL,
    HUM_AXCEL_STATE_FIRE_WALL_END
};

void AxcelMoveTo(HumWork* work, s32 x, s32 y) {
    work->targetX = x;
    work->targetY = y;
    work->state = HUM_AXCEL_STATE_WARP;
    work->stateTimer = 0;
}

void AxcelScaleTo(AxcelWork* work, s32 scaleX, s32 scaleY, u16 steps) {
    work->scaleSteps = steps;
    work->targetScaleX = scaleX;
    work->targetScaleY = scaleY;
}

void AxcelHover(HumWork* work, s32 hoverZ) {
    BtlObj* act;
    s32 bobZ;

    if (hoverZ != 0) {
        act = &work->actor;
        bobZ = hoverZ + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->vz = 0;
        act->z += (bobZ - act->z) >> 4;
    }
}

void AxcelSpawnParticle(AxcelWork* work, HumSub* sub) {
    s32 args[3];

    if (GetRandom() % 6 == 0) {
        args[0] = sub->x + (GetRandom() % 29 - 14) * 256;
        args[1] = sub->y + (GetRandom() % 15 - 7) * 256;
        args[2] = sub->z;
        TaskCreate(&work->tasks, &sTaskDescHumAxcelPtc, args);
    }
}

void task_hum_axcel_0(AxcelWork* work) {
    HumInit(&work->base, &sHumAxcelDef);
    HumSubInit(&work->base, &work->sub, &sHumAxcelSubDef);
    HumSubInit(&work->base, &work->sub2, &sHumAxcelSubDef);
    work->base.actor.flags |= BTLOBJ_FLAG_IMMUNE_FIRE;
    work->base.stockMoves = sHumAxcelStockMoves[0];
    work->flags = 0;
    work->hoverZ = -0x300;
    work->scaleSteps = 0;
    work->sub.flags |= HUM_SUB_FLAG_HIDDEN;
    work->sub2.flags |= HUM_SUB_FLAG_HIDDEN;
    work->tiles = LoadObjTiles(gBtlShadowTiles, sizeof(gBtlShadowTiles));
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
    TaskPoolInit(&work->tasks, 16);
}

u8 task_hum_axcel_1(AxcelWork* work) {
    AxcelWork* w;
    HumSub* sub;
    HumSub* sub2;
    BtlObj* act;
    s32 x;
    s32 y;

    w = work;
    sub = &work->sub;
    sub2 = &work->sub2;
    act = &work->base.actor;
    GetEnemyTargetPosition(act, &x, &y, NULL);

    switch (HumUpdateReaction(&work->base)) {
    case BTL_REACTION_CARD_ACTION:
        work->base.stateTimer = 0;

        switch ((u32)HumResolveCardMove(&work->base)) {
        case MOVE_BOSS_A:
        case MOVE_BOSS_C:
            work->base.state = HUM_AXCEL_STATE_SLASH;
            work->base.steps = 0;
            break;
        case MOVE_BOSS_B:
        case MOVE_BOSS_D:
            work->base.state = HUM_AXCEL_STATE_THROW_APPROACH;
            break;
        case MOVE_FIRE_WALL:
            work->base.state = HUM_AXCEL_STATE_FIRE_WALL_WINDUP;
            break;
        case MOVE_FIRETOOTH:
            work->base.state = HUM_AXCEL_STATE_CHAKRAM_IGNITE;
            break;
        }

        w->targetScaleX = work->base.scaleX = Q_8_8(1);
        w->targetScaleY = work->base.scaleY = Q_8_8(1);
        break;
    case BTL_REACTION_CARD_BROKEN:
        work->base.flags &= ~HUM_FLAG_BEHIND_BG_FX;
#ifdef VERSION_EU
        act->flags &= ~BTLOBJ_FLAG_HIDE_SHADOW;
#endif
        sub->flags |= HUM_SUB_FLAG_HIDDEN;
        sub2->flags |= HUM_SUB_FLAG_HIDDEN;
        work->targetScaleX = work->base.scaleX = Q_8_8(1);
        work->targetScaleY = work->base.scaleY = Q_8_8(1);
        m4aSongNumStop(SONG_EF_AKL_FIREWALL);
        break;
    }

    if (gBtlWork->battleId == BATTLE_AXEL_1) {
        if (HumChooseCardAction(&work->base, 20, 40, 40, 24)) {
            work->base.stockMoves = sHumAxcelStockMoves[0];
        }
    } else if (HumChooseCardAction(&work->base, 5, 40, 40, 24)) {
        if (GetRandom() % 2) {
            work->base.stockMoves = sHumAxcelStockMoves[0];
        } else {
            work->base.stockMoves = sHumAxcelStockMoves[1];
        }
    }

    switch (work->base.state) {
    case HUM_STATE_ENTER:
    case HUM_STATE_USE_ITEM:
        AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        break;
    case HUM_STATE_RELOAD:
        AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        break;
    case HUM_STATE_IDLE:
        AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        w->hoverZ = -0x300;

        if (func_08081828()) {
            break;
        }

        if ((u16)(GetRandom() % 80) == 0) {
            work->base.state = HUM_STATE_MOVE;
            work->base.stateTimer = 0;
            break;
        }

        if (HumIsNearAreaEdge(&work->base, 40)) {
            AxcelMoveTo(&w->base, 0x10000, act->y);
            break;
        }

        HumFaceTarget(&work->base, 8);
        work->base.stateTimer++;
        break;
    case HUM_STATE_MOVE:
        if (work->base.stateTimer == 0) {
            work->base.targetX = x + (((u16)(GetRandom() % 201) - 100) << 8);
            work->base.targetY = y + (((u16)(GetRandom() % 65) - 32) << 8);
            work->base.state = HUM_AXCEL_STATE_WARP;
        }

        break;
    case HUM_STATE_HURT:
        if (work->base.stateTimer == 0) {
            if (act->btl->hcEffect == HC_EFFECT_QUICK_RECOVERY) {
                act->btl->hcEffectCount--;
#ifdef VERSION_EU
                w->targetScaleX = work->base.scaleX = Q_8_8(1);
                w->targetScaleY = work->base.scaleY = Q_8_8(1);
#endif
                act->vx = act->vy = 0;
                work->base.vz = 0;
                act->invincibleTimer = 30;
                work->base.stateTimer = 6;
                break;
            }
        }
    case HUM_STATE_DEFEATED:
    case HUM_STATE_CARD_BROKEN:
    case HUM_STATE_STUNNED:
    case HUM_STATE_GRAVITY:
        if (work->base.stateTimer == 0) {
            w->targetScaleX = work->base.scaleX = Q_8_8(1);
            w->targetScaleY = work->base.scaleY = Q_8_8(1);
        }

        w->hoverZ = 0;
        AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case HUM_AXCEL_STATE_THROW_APPROACH:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 1, ANIM_FLAG_LOOP, w->base.tiles);
            work->base.steps = 10;
        }

        if (act->x < x) {
            work->base.targetX = x - 0x6E00;
        } else {
            work->base.targetX = x + 0x6E00;
        }

        ApproachValueHalfSteps(&act->x, work->base.targetX, work->base.steps);
        work->base.steps--;
        HumFaceTarget(&work->base, 1);

        if (work->base.steps <= 0) {
            work->base.state = HUM_AXCEL_STATE_THROW_WINDUP;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_THROW_WINDUP:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 5, 0, w->base.tiles);
            w->hoverZ = 0;
            work->base.targetX = x * 2 - act->x;
            work->base.targetY = y * 2 - act->y;
        }

        HumFaceTarget(&work->base, 1);
        BtlMapFollowPosition(act->x, act->y, act->z);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.state = HUM_AXCEL_STATE_THROW;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_THROW:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 6, 0, w->base.tiles);
            AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub->anim, 0, ANIM_FLAG_LOOP, w->base.sub->tiles);
            sub->palette2 = work->base.palette;
            sub->flags |= HUM_SUB_FLAG_OWN_DEPTH;
            sub->flags &= ~HUM_SUB_FLAG_HIDDEN;
            m4aSongNumStart(SONG_BTL_AKL_WTHR);

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                sub->x = act->x - 0x2000;
            } else {
                sub->x = act->x + 0x2000;
            }

            sub->y = act->y;
            sub->z = act->z - 0x2000;
            HumFaceTarget(&work->base, 1);
            w->steps = 30;
        }

        ApproachValue(&sub->x, work->base.targetX, w->steps);
        ApproachValue(&sub->y, work->base.targetY, w->steps);
        w->steps--;
        BtlMapFollowPosition(sub->x, sub->y, sub->z);

        if (ApplyAttackBox(302, sub->x, sub->y, sub->z, 8, 8, 2)) {
            m4aSongNumStart(SONG_BTL_MON_SWORD01);
        }

        if (w->steps == 19) {
            AxcelScaleTo(w, Q_8_8(0.05), Q_8_8(2), 8);
        }

        if (w->steps == 11) {
            act->x = work->base.targetX;
            act->y = work->base.targetY;
            act->flags ^= BTLOBJ_FLAG_FACING_LEFT;
            AxcelScaleTo(w, Q_8_8(1), Q_8_8(1), 8);
        }

        if (w->steps <= 4) {
            work->base.state = HUM_AXCEL_STATE_CATCH;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_CATCH:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 7, 0, w->base.tiles);
            sub->flags |= HUM_SUB_FLAG_HIDDEN;
            sub->flags &= ~HUM_SUB_FLAG_OWN_DEPTH;
        }

        BtlMapFollowPosition(act->x, act->y, act->z);

        if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_CHAKRAM_IGNITE:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 8, 0, w->base.tiles);
            AnimReset(&sub->anim);
            AnimReset(&sub2->anim);
            AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub->anim, 6, 0, w->base.sub->tiles);
            AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub2->anim, 2, 0, w->base.sub2->tiles);
            sub->palette2 = sub->palette;
            sub->flags &= ~(HUM_SUB_FLAG_HIDDEN | HUM_SUB_FLAG_OWN_DEPTH);
            sub2->flags &= ~(HUM_SUB_FLAG_HIDDEN | HUM_SUB_FLAG_OWN_DEPTH);
            sub->flags |= HUM_SUB_FLAG_IN_FRONT;
            sub2->flags &= ~HUM_SUB_FLAG_IN_FRONT;
            w->hoverZ = 0;
        }

        HumFaceTarget(&work->base, 1);
        work->base.vz = 0;

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 3:
                m4aSongNumStart(SONG_BTL_AKL_FIREENTRY);
                AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub->anim, 7, ANIM_FLAG_LOOP, w->base.sub->tiles);
                AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub2->anim, 3, ANIM_FLAG_LOOP, w->base.sub2->tiles);
                break;
            case 6:
                m4aSongNumStart(SONG_SND_290);
                AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub->anim, 8, ANIM_FLAG_LOOP, w->base.sub->tiles);
                AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub2->anim, 4, ANIM_FLAG_LOOP, w->base.sub2->tiles);
                break;
            case 7:
                AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub->anim, 9, 0, w->base.sub->tiles);
                AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub2->anim, 5, 0, w->base.sub2->tiles);
                m4aSongNumStart(SONG_BTL_AKL_FIRETHR);
                break;
            }
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 3:
        case 4:
        case 5:
            {
                s32 lowZ = act->z + 0x1000;
                act->z += (act->originZ - lowZ) >> 4;
            }

            break;
        case 6:
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                {
                s32 frontX = act->x - 0x800;
                act->x += (act->originX - frontX) >> 3;
            }
            } else {
                {
                s32 frontX = act->x + 0x800;
                act->x += (act->originX - frontX) >> 3;
            }
            }

            {
                s32 lowZ = act->z + 0x1400;
                act->z += (act->originZ - lowZ) >> 3;
            }

            break;
        }

        act->y += (((gBtlWork->yMin + gBtlWork->yMax + 32) << 7) - act->y) >> 3;
        sub->x = act->x;
        sub->y = act->y;
        sub->z = act->z;
        sub2->x = act->x;
        sub2->y = act->y;
        sub2->z = act->z;

        if (AnimIsFinished(&work->base.anim)) {
            if (act->hp < act->maxHp / 2) {
                work->base.state = HUM_AXCEL_STATE_CHAKRAM_BOUNCE;
            } else if ((x - act->x >= 0) ? x - act->x <= 0x4FFF : act->x - x <= 0x4FFF) {
                work->base.state = HUM_AXCEL_STATE_CHAKRAM_ORBIT;
            } else {
                work->base.state = HUM_AXCEL_STATE_CHAKRAM_SWEEP;
            }

            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_CHAKRAM_SWEEP: {
        s32 targetX;

        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 9, ANIM_FLAG_LOOP, w->base.tiles);
            AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub->anim, 1, ANIM_FLAG_LOOP, w->base.sub->tiles);
            AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub2->anim, 1, ANIM_FLAG_LOOP, w->base.sub2->tiles);
            sub->flags |= HUM_SUB_FLAG_OWN_DEPTH;
            sub2->flags |= HUM_SUB_FLAG_OWN_DEPTH;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                sub->x = act->x - 0x3700;
                sub2->x = act->x - 0x5700;
            } else {
                sub->x = act->x + 0x3700;
                sub2->x = act->x + 0x5700;
            }

            sub->y = act->y + 0xA00;
            sub->z = act->z - 0x1E00;
            sub2->y = act->y - 0xA00;
            sub2->z = act->z - 0x1400;
            w->hoverZ = act->z;
        }

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            s32 dist = (work->base.stateTimer << 9) + 0x5A00;
            targetX = act->x - dist;
        } else {
            s32 dist = (work->base.stateTimer << 9) + 0x5A00;
            targetX = act->x + dist;
        }

        sub->x += (targetX - sub->x) >> 3;
        sub2->x += (targetX - sub2->x) >> 3;
        sub->y += (act->y + SIN((u16)work->base.stateTimer * 4) * 55 - sub->y) >> 2;
        sub2->y += (act->y - SIN((u16)work->base.stateTimer * 4) * 55 - sub2->y) >> 2;

        {
            s32* ground = &gBtlWork->targetZ;

            {
                s32 lowZ = sub->z + 0x1800;
                sub->z += (*ground - lowZ) >> 2;
            }

            {
                s32 lowZ = sub2->z + 0x1800;
                sub2->z += (*ground - lowZ) >> 3;
            }
        }

        if (ApplyAttackBox(304, sub->x, sub->y, sub->z, 8, 8, 2)) {
            m4aSongNumStart(SONG_EF_FIRE01);
        }

        if (ApplyAttackBox(304, sub2->x, sub2->y, sub2->z, 8, 8, 2)) {
            m4aSongNumStart(SONG_EF_FIRE01);
        }

        AxcelSpawnParticle(w, sub);
        AxcelSpawnParticle(w, sub2);

        if (sub->x > ((gBtlWork->xMax + 32) << 8) ||
            sub->x < ((gBtlWork->xMin - 32) << 8)) {
            sub->flags |= HUM_SUB_FLAG_HIDDEN;
            sub2->flags |= HUM_SUB_FLAG_HIDDEN;
            work->base.stateTimer = 0;
            work->base.state = HUM_AXCEL_STATE_CHAKRAM_END;
        } else {
            work->base.stateTimer++;
        }

        break;
    }
    case HUM_AXCEL_STATE_CHAKRAM_ORBIT: {
        u16 angle;
        s32 dx;
        s32 dy;
        HumFaceTarget(&work->base, 1);

        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 9, ANIM_FLAG_LOOP, w->base.tiles);
            AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub->anim, 1, ANIM_FLAG_LOOP, w->base.sub->tiles);
            AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub2->anim, 1, ANIM_FLAG_LOOP, w->base.sub2->tiles);
            sub->flags |= HUM_SUB_FLAG_OWN_DEPTH;
            sub2->flags |= HUM_SUB_FLAG_OWN_DEPTH;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                sub->x = act->x - 0x3700;
                sub2->x = act->x - 0x5700;
            } else {
                sub->x = act->x + 0x3700;
                sub2->x = act->x + 0x5700;
            }

            sub->y = act->y + 0xA00;
            sub->z = act->z - 0x1E00;
            sub2->y = act->y - 0xA00;
            sub2->z = act->z - 0x1400;
            w->hoverZ = act->z;
            w->steps = 200;
            w->orbitRadius = 0x5A00;
            m4aSongNumStart(SONG_BTL_AKL_FIRETHR);
        }

        angle = (u16)work->base.stateTimer * 4;
        ApproachValue(&w->orbitRadius, 0x2800, w->steps);
        w->steps--;
        dx = gSineTable[angle % 256] * w->orbitRadius >> 8;
        dy = -gSineTable[angle % 256 + 64] * w->orbitRadius >> 8;
        sub->x += (x + dx - sub->x) >> 4;
        sub->y += (y + dy - sub->y) >> 4;
        sub2->x += (x - dx - sub2->x) >> 4;
        sub2->y += (y - dy - sub2->y) >> 4;
        sub->z += (-0x1800 - sub->z) >> 3;
        sub2->z += (-0x1800 - sub2->z) >> 3;

        if (ApplyAttackBox(304, sub->x, sub->y, sub->z, 8, 8, 2)) {
            m4aSongNumStart(SONG_EF_FIRE01);
        }

        if (ApplyAttackBox(304, sub2->x, sub2->y, sub2->z, 8, 8, 2)) {
            m4aSongNumStart(SONG_EF_FIRE01);
        }

        AxcelSpawnParticle(w, sub);
        AxcelSpawnParticle(w, sub2);

        if (w->steps <= 0) {
            work->base.stateTimer = 0;
            work->base.state = HUM_AXCEL_STATE_CHAKRAM_EXIT;
        } else {
            work->base.stateTimer++;
        }

        break;
    }
    case HUM_AXCEL_STATE_CHAKRAM_EXIT:
        if (work->base.stateTimer == 0) {
            w->steps = 20;
        }

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            ApproachValue(&sub->x, (gBtlWork->xMin - 32) << 8, w->steps);
            ApproachValue(&sub2->x, (gBtlWork->xMin - 32) << 8, w->steps);
        } else {
            ApproachValue(&sub->x, (gBtlWork->xMax + 32) << 8, w->steps);
            ApproachValue(&sub2->x, (gBtlWork->xMax + 32) << 8, w->steps);
        }

        ApproachValue(&sub->z, -0x5A00, w->steps);
        ApproachValue(&sub2->z, -0x5A00, w->steps);
        w->steps--;

        if (w->steps <= 0) {
            sub->flags |= HUM_SUB_FLAG_HIDDEN;
            sub2->flags |= HUM_SUB_FLAG_HIDDEN;
            work->base.stateTimer = 0;
            work->base.state = HUM_AXCEL_STATE_CHAKRAM_END;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_CHAKRAM_BOUNCE:
        HumFaceTarget(&work->base, 1);

        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 9, ANIM_FLAG_LOOP, w->base.tiles);
            AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub->anim, 1, ANIM_FLAG_LOOP, w->base.sub->tiles);
            AnimChangeWithDef(sHumAxcelWeaponAnimDefs, &w->base.sub2->anim, 1, ANIM_FLAG_LOOP, w->base.sub2->tiles);
            sub->flags |= HUM_SUB_FLAG_OWN_DEPTH;
            sub2->flags |= HUM_SUB_FLAG_OWN_DEPTH;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                sub->x = act->x - 0x3700;
                sub2->x = act->x - 0x5700;
            } else {
                sub->x = act->x + 0x3700;
                sub2->x = act->x + 0x5700;
            }

            sub->y = act->y + 0xA00;
            sub->z = act->z - 0x1E00;
            sub2->y = act->y - 0xA00;
            sub2->z = act->z - 0x1400;
            w->hoverZ = act->z;
            w->subAngle = GetAngle(sub->x, sub->y, x, y);
            w->sub2Angle = GetAngle(sub2->x, sub2->y, x, y);
        }

        sub->x += gSineTable[(u8)w->subAngle] * 6;
        sub->y -= gSineTable[(u8)w->subAngle + 64] * 4;
        sub2->x += gSineTable[(u8)w->sub2Angle] * 6;
        sub2->y -= gSineTable[(u8)w->sub2Angle + 64] * 4;
        sub->z += (-0x1000 - sub->z) >> 3;
        sub2->z += (-0x1000 - sub2->z) >> 3;
        w->subAngle += 2;
        w->sub2Angle -= 2;

        if (ClampBattlePosition(&sub->x, &sub->y, 0, 0)) {
            w->subAngle += 128;
        }

        if (ClampBattlePosition(&sub2->x, &sub2->y, 0, 0)) {
            w->sub2Angle += 128;
        }

        if (ApplyAttackBox(304, sub->x, sub->y, sub->z, 8, 8, 2)) {
            m4aSongNumStart(SONG_EF_FIRE01);
            w->subAngle += 128;
        }

        if (ApplyAttackBox(304, sub2->x, sub2->y, sub2->z, 8, 8, 2)) {
            m4aSongNumStart(SONG_EF_FIRE01);
            w->sub2Angle += 128;
        }

        AxcelSpawnParticle(w, sub);
        AxcelSpawnParticle(w, sub2);

        if (work->base.stateTimer > 300) {
            work->base.stateTimer = 0;
            work->base.state = HUM_AXCEL_STATE_CHAKRAM_EXIT;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_CHAKRAM_END:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 10, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.stateTimer = 0;
            work->base.state = HUM_STATE_IDLE;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_SLASH:
        if (work->base.stateTimer == 0) {
            m4aSongNumStart(SONG_SND_291);
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 3, 0, w->base.tiles);
            w->hoverZ = 0;
            w->flags &= ~AXCEL_FLAG_ATTACK_HIT;
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 1:
        case 2:
        case 3:
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                s32 backX = act->x + 0x3000;
                act->x += (act->originX - backX) >> 3;
            } else {
                s32 backX = act->x - 0x3000;
                act->x += (act->originX - backX) >> 3;
            }

            break;
        }

        if (AnimGetFrame(&work->base.anim) == 2 && work->base.anim.timer == 0) {
            MakeOpponentsHittable();

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT ?
                ApplyAttackBox(300, act->x - 0x2000, act->y, act->z, 20, 24, 50) :
                ApplyAttackBox(300, act->x + 0x2000, act->y, act->z, 20, 24, 50)) {
                m4aSongNumStart(SONG_BTL_MON_SWORD00);
                w->flags |= AXCEL_FLAG_ATTACK_HIT;
            }
        }

        if (w->flags & AXCEL_FLAG_ATTACK_HIT) {
            work->base.state = HUM_AXCEL_STATE_SLASH_FOLLOWUP;
            work->base.stateTimer = 0;
        } else if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_SLASH_FOLLOWUP:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 4, 0, w->base.tiles);
            w->hoverZ = 0;
            w->flags &= ~AXCEL_FLAG_ATTACK_HIT;
        }

        if (AnimGetFrame(&work->base.anim) == 1) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                s32 backX = act->x + 0x2800;
                act->x += (act->originX - backX) >> 3;
            } else {
                s32 backX = act->x - 0x2800;
                act->x += (act->originX - backX) >> 3;
            }
        }

        if (AnimGetFrame(&work->base.anim) == 2 && work->base.anim.timer == 0) {
            MakeOpponentsHittable();

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT ?
                ApplyAttackBox(301, act->x - 0x2000, act->y, act->z, 24, 24, 50) :
                ApplyAttackBox(301, act->x + 0x2000, act->y, act->z, 24, 24, 50)) {
                m4aSongNumStart(SONG_BTL_MON_SWORD00);
                w->flags |= AXCEL_FLAG_ATTACK_HIT;
            }
        }

        if (work->base.steps <= 1 && (w->flags & AXCEL_FLAG_ATTACK_HIT) && AnimGetFrame(&work->base.anim) > 2) {
            work->base.state = HUM_AXCEL_STATE_SLASH;
            work->base.stateTimer = 0;
            work->base.steps++;
        } else if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_FIRE_WALL_WINDUP:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 11, 0, w->base.tiles);
            w->hoverZ = 0;
            m4aSongNumStart(SONG_SND_289);
        }

        HumFaceTarget(&work->base, 1);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.state = HUM_AXCEL_STATE_FIRE_WALL;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_FIRE_WALL: {
        s32 wallX, wallY, wallZ;

        if (work->base.stateTimer == 0) {
            FadeToAmount(FADE_MODE_BLACK, gBtlWork->fadeAmount, 8);
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 12, 0, w->base.tiles);

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                BgFxStartAxcelFireWall(act->x, TRUE, 303);
            } else {
                BgFxStartAxcelFireWall(act->x, FALSE, 303);
            }

            work->base.flags |= HUM_FLAG_BEHIND_BG_FX;
#ifdef VERSION_EU
            act->flags |= BTLOBJ_FLAG_HIDE_SHADOW;
#endif
            m4aSongNumStart(SONG_EF_AKL_FIREWALL);
        }

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            BgFxAddPosition(-76, 0, 0);
        } else {
            BgFxAddPosition(76, 0, 0);
        }

        BgFxGetPosition(&wallX, &wallY, &wallZ);

        if (!BgFxIsActive() || wallX < ((gBtlWork->xMin - 64) << 8) || wallX > ((gBtlWork->xMax + 64) << 8)) {
            m4aSongNumStop(SONG_EF_AKL_FIREWALL);
            work->base.state = HUM_AXCEL_STATE_FIRE_WALL_END;
            work->base.stateTimer = 0;
            gBtlWork->flags |= BTL_FLAG_STOP_BGFX;
            FadeToOriginal(FADE_MODE_BLACK, 8);
        } else {
            work->base.stateTimer++;
        }

        break;
    }
    case HUM_AXCEL_STATE_FIRE_WALL_END:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 13, 0, w->base.tiles);
            w->hoverZ = 0;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.flags &= ~HUM_FLAG_BEHIND_BG_FX;
#ifdef VERSION_EU
            act->flags &= ~BTLOBJ_FLAG_HIDE_SHADOW;
#endif
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_AXCEL_STATE_WARP:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumAxcelAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
            AxcelScaleTo(w, Q_8_8(0.05), Q_8_8(2), 8);
        }

        if (work->base.stateTimer > 6) {
            if (work->base.stateTimer == 7) {
                act->x = work->base.targetX;
                act->y = work->base.targetY;
                AxcelScaleTo(w, Q_8_8(1), Q_8_8(1), 8);
            }

            if (AnimIsFinished(&work->base.anim)) {
                work->base.state = HUM_STATE_IDLE;
                work->base.stateTimer = 0;
                break;
            }
        }

        work->base.stateTimer++;
        break;
    }

    if (act->badStatus != BAD_STATUS_STOP) {
        AxcelHover(&work->base, w->hoverZ);
    }

    if ((s16)w->scaleSteps > 0) {
        ApproachValue(&work->base.scaleX, w->targetScaleX, w->scaleSteps);
        ApproachValue(&work->base.scaleY, w->targetScaleY, w->scaleSteps);
        w->scaleSteps--;
    }

    TaskPoolUpdate(&w->tasks);
    return HumUpdate(&work->base);
}

void AxcelDrawSubShadow(AxcelWork* work, HumSub* sub) {
    s16 x;
    s16 y;
    ObjAffine* affine;
    s32 scale;
    s32 doubleSize;

    if ((sub->flags & HUM_SUB_FLAG_HIDDEN) == 0) {
        if (sub->z >= 0) {
            affine = NULL;
        } else {
            scale = Q_8_8(1) - (-sub->z) / 128;

            if (scale <= 127) {
                scale = Q_8_8(0.5);
            }

            doubleSize = FALSE;

            if (scale > Q_8_8(1)) {
                doubleSize = TRUE;
            }

            affine = AllocObjAffine(0, scale, scale, doubleSize);
        }

        WorldToScreen(&x, &y, sub->x, sub->y, 0);
        DrawSprite(x, y, gBtlShadowFrame0, work->tiles, work->palette, affine, SPRITE_PRIORITY(2), 0xFFFE);
    }
}

void task_hum_axcel_2(AxcelWork* work) {
    HumDraw(&work->base);
    AxcelDrawSubShadow(work, &work->sub);
    AxcelDrawSubShadow(work, &work->sub2);
    TaskPoolDraw(&work->tasks);
}

void task_hum_axcel_3(AxcelWork* work) {
    m4aSongNumStop(SONG_EF_AKL_FIREWALL);
    TaskPoolDestroy(&work->tasks);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    HumReleaseResources(&work->base);
}

void task_hum_axcel_ptc_0(AxcelPtcWork* work, s32* args) {
    work->x = args[0];
    work->y = args[1];
    work->z = args[2];
    work->tiles = LoadObjTiles(gHumAxcelPtcTiles, sizeof(gHumAxcelPtcTiles));
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
    AnimInit(&work->anim, gHumAxcelPtcAnims, gHumAxcelPtcFrames);

    switch (GetRandom() % 3) {
    case 0:
        AnimStart(&work->anim, 0, 0);
        break;
    case 1:
        AnimStart(&work->anim, 1, 0);
        break;
    case 2:
        AnimStart(&work->anim, 2, 0);
        break;
    }
}

u8 task_hum_axcel_ptc_1(AxcelPtcWork* work) {
    if (AnimIsFinished(&work->anim)) {
        return 0;
    }

    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_hum_axcel_ptc_2(AxcelPtcWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, NULL,
        GetBattleSpritePriorityFlags(work->y), -0x1004 - (work->y >> 8) * 4);
}

void task_hum_axcel_ptc_3(AxcelPtcWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}
