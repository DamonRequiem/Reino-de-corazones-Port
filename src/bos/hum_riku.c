/**
 * hum_riku.c
 * Riku Replica Boss
 */

#include "fade.h"
#include "obj_api.h"
#include "hum.h"
#include "sprites_hum.h"
#include "gba/io_reg.h"
#include "btl_api.h"
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
#include "display.h"
#include "engine_math.h"
#include "hum_types.h"
#include "m4a_song.h"
#include "obj.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "battle_ids.h"
#include "enemy_ids.h"
#include "card_ids.h"

static const u32 sHumRikuStockMoves[2][3] = {
    { MOVE_BOSS_A, MOVE_BOSS_A, MOVE_BOSS_C },
    { MOVE_BOSS_B, MOVE_BOSS_B, MOVE_BOSS_D },
};

static const AnimDef sHumRikuAnimDefs[21] = {
    { gNiserikuIdolFrames, gNiserikuIdolAnims, gNiserikuIdolTiles, 0 },
    { gNiserikuRunFrames, gNiserikuRunAnims, gNiserikuRunTiles, 0 },
    { gNiserikuDamageFrames, gNiserikuDamageAnims, gNiserikuDamageTiles, 0 },
    { gNiserikuJumpFrames, gNiserikuJumpAnims, gNiserikuJumpTiles, 0 },
    { gNiserikuJumpFrames, gNiserikuJumpAnims, gNiserikuJumpTiles, 1 },
    { gNiserikuJumpFrames, gNiserikuJumpAnims, gNiserikuJumpTiles, 2 },
    { gNiserikuJumpFrames, gNiserikuJumpAnims, gNiserikuJumpTiles, 3 },
    { gNiserikuJumpFrames, gNiserikuJumpAnims, gNiserikuJumpTiles, 4 },
    { gNiserikuDashFrames, gNiserikuDashAnims, gNiserikuDashTiles, 0 },
    { gNiserikuFuriharaiFrames, gNiserikuFuriharaiAnims, gNiserikuFuriharaiTiles, 0 },
    { gNiserikuTategiriFrames, gNiserikuTategiriAnims, gNiserikuTategiriTiles, 0 },
    { gNiserikuKabutoFrames, gNiserikuKabutoAnims, gNiserikuKabutoTiles, 0 },
    { gNiserikuKabutoFrames, gNiserikuKabutoAnims, gNiserikuKabutoTiles, 2 },
    { gNiserikuDarkfigaFrames, gNiserikuDarkfigaAnims, gNiserikuDarkfigaTiles, 0 },
    { gNiserikuYamiStartFrames, gNiserikuYamiStartAnims, gNiserikuYamiStartTiles, 0 },
    { gNiserikuYamiStartFrames, gNiserikuYamiStartAnims, gNiserikuYamiStartTiles, 1 },
    { gNiserikuYamiStartFrames, gNiserikuYamiStartAnims, gNiserikuYamiStartTiles, 2 },
    { gNiserikuYamiIngFrames, gNiserikuYamiIngAnims, gNiserikuYamiIngTiles, 0 },
    { gNiserikuYamiIngFrames, gNiserikuYamiIngAnims, gNiserikuYamiIngTiles, 1 },
    { gNiserikuYamiIngFrames, gNiserikuYamiIngAnims, gNiserikuYamiIngTiles, 2 },
    { gNiserikuYamiEndFrames, gNiserikuYamiEndAnims, gNiserikuYamiEndTiles, 0 },
};

static const HumDef sHumRikuDef = { 64, gNiserikuPalette, 0, { ENEMY_RIKU_REPLICA, 99, 38, 14, 24, 99, 0 } };

static const HumSubDef sHumRikuSubDef = { gNiserikuPalette, 64 };

TaskDesc gTaskDescHumRiku = {
    "task_hum_riku",
    (TaskInitFunc)task_hum_riku_0,
    (TaskUpdateFunc)task_hum_riku_1,
    (TaskDrawFunc)task_hum_riku_2,
    (TaskDestroyFunc)task_hum_riku_3,
    sizeof(RikuWork),
};

enum HumRikuState {
    HUM_RIKU_STATE_JUMP_CROUCH = 19,
    HUM_RIKU_STATE_JUMP_AIR,
    HUM_RIKU_STATE_JUMP_LAND,
    HUM_RIKU_STATE_DASH_SLASH,
    HUM_RIKU_STATE_SWEEP,
    HUM_RIKU_STATE_VERTICAL_SLASH,
    HUM_RIKU_STATE_DIVE_CROUCH,
    HUM_RIKU_STATE_DIVE_RISE,
    HUM_RIKU_STATE_DIVE,
    HUM_RIKU_STATE_DIVE_RECOIL,
    HUM_RIKU_STATE_DARK_FIRAGA,
    HUM_RIKU_STATE_DARK_AURA_START,
    HUM_RIKU_STATE_DARK_AURA_LEAP,
    HUM_RIKU_STATE_DARK_AURA_EXIT,
    HUM_RIKU_STATE_DARK_AURA_AIM,
    HUM_RIKU_STATE_DARK_AURA_DASH,
    HUM_RIKU_STATE_DARK_AURA_END
};

void RikuJumpOffset(RikuWork* work, s16 distance, s32 speed) {
    HumWork* base = &work->base;
    BtlObj* act = &base->actor;

    if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
        work->base.targetX = act->x - (distance << 8);
    } else {
        work->base.targetX = act->x + (distance << 8);
    }

    base->targetY = act->y;
    base->state = HUM_RIKU_STATE_JUMP_CROUCH;
    base->stateTimer = 0;
    work->unk_1C4 = -speed;
    work->state = 0;
}

void RikuJumpTo(RikuWork* work, s32 x, s32 y) {
    work->base.targetX = x;
    work->base.targetY = y;
    work->base.state = HUM_RIKU_STATE_JUMP_CROUCH;
    work->base.stateTimer = 0;
    work->unk_1C4 = -0x500;
}

u8 RikuTryJumpAway(RikuWork* work) {
    s32 x;
    s32 y;
    BtlObj* player;

    player = gBtlWork->actor;

    if (GetRandom() % 30 == 0) {
        GetEnemyTargetPosition(&work->base.actor, &x, &y, NULL);
        HumFaceTarget(&work->base, 1);

        if (HumIsInPlayerReach(&work->base, 0x100, 0x100, 0x100)) {
            if (gBtlWork->flags & BTL_FLAG_PLAYER_AIRBORNE) {
                RikuJumpOffset(work, -99, 0x280);
            } else if (GetRandom() & 1) {
                if (player->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    RikuJumpTo(work, x + 0x2800, y);
                } else {
                    RikuJumpTo(work, x - 0x2800, y);
                }
            } else {
                RikuJumpOffset(work, -80, 0x500);
            }

            return TRUE;
        }
    }

    return FALSE;
}

void RikuSaveAfterimage(RikuWork* work, RikuSpawn* dst) {
    BtlObj* act = &work->base.actor;

    dst->x = act->x;
    dst->y = act->y;
    dst->z = act->z;

    if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
        dst->flags |= RIKU_SPAWN_FLAG_FACING_LEFT;
    } else {
        dst->flags &= ~RIKU_SPAWN_FLAG_FACING_LEFT;
    }

    dst->anim = work->base.anim;
    dst->tileSrc = work->base.tiles->src;
    dst->scale = gBtlWork->scale;
}

void RikuDrawAfterimage(RikuWork* work, RikuSpawn* spawn) {
    BtlObj* act;
    HumSub* sub;
    void* gfx;
    u16 attr;
    s32 sx;
    s32 sy;
    ObjAffine* affine;
    s16 x;
    s16 y;
    u16 pri;

    sub = work->base.sub;
    gfx = AnimGetGfx(&spawn->anim);
    act = &work->base.actor;

    if (!BgFxIsActive()) {
        gBldCnt = (BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
        SetBlendAlpha(6, 12);
        attr = SPRITE_PRIORITY(2) | SPRITE_FLAG_BLEND;
    } else {
        attr = GetBattleSpritePriorityFlags(act->y);
    }

    if (spawn->flags & RIKU_SPAWN_FLAG_FACING_LEFT) {
        sy = spawn->scale;
        sx = sy;
    } else if (spawn->scale == Q_8_8(1)) {
        sy = spawn->scale;
        sx = sy;
        attr |= SPRITE_FLAG_HFLIP;
    } else {
        sx = -gBtlWork->scale;
        sy = gBtlWork->scale;
    }

    if (sy == Q_8_8(1) && sx == sy) {
        affine = NULL;
    } else if (sy <= 255) {
        affine = AllocObjAffine(0, sx, sy, FALSE);
    } else {
        affine = AllocObjAffine(0, sx, sy, TRUE);
    }

    pri = 0xFFF0;
    WorldToScreen(&x, &y, spawn->x, spawn->y, spawn->z);
    SetObjTileSource(sub->tiles, spawn->tileSrc);
    DrawSprite(x, y, gfx, sub->tiles, work->base.palette, affine, attr, pri);
}

void task_hum_riku_0(RikuWork* work) {
    HumInit(&work->base, &sHumRikuDef);
    HumSubInit(&work->base, &work->sub, &sHumRikuSubDef);
    work->unk_1C4 = 0;
    work->flags = 0;
    work->sub.flags |= (HUM_SUB_FLAG_IN_FRONT | HUM_SUB_FLAG_HIDDEN);
    work->afterimageTimer = 0;

    if (gBtlWork->battleId != BATTLE_RIKU_1) {
        work->base.stockMoves = sHumRikuStockMoves[0];
    }

    RikuSaveAfterimage(work, &work->spawns[0]);
    work->spawns[1] = work->spawns[0];
    work->spawns[2] = work->spawns[0];
    work->spawns[3] = work->spawns[0];
    work->spawns[4] = work->spawns[0];
    work->spawns[5] = work->spawns[0];
    work->spawns[6] = work->spawns[0];
    work->spawns[7] = work->spawns[0];
    work->spawns[8] = work->spawns[0];
}

u8 task_hum_riku_1(RikuWork* work) {
    RikuWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 z;

    w = work;
    act = &work->base.actor;
    GetEnemyTargetPosition(act, &x, &y, &z);
    work->flags &= ~RIKU_FLAG_AFTERIMAGE;

    switch (HumUpdateReaction(&work->base)) {
    case BTL_REACTION_CARD_ACTION:
        work->base.stateTimer = 0;

        switch ((u32)HumResolveCardMove(&work->base)) {
        case MOVE_BOSS_A:
            work->base.state = HUM_RIKU_STATE_VERTICAL_SLASH;
            break;
        case MOVE_BOSS_B:
            work->base.state = HUM_RIKU_STATE_DASH_SLASH;
            break;
        case MOVE_BOSS_C:
            work->base.state = HUM_RIKU_STATE_SWEEP;
            break;
        case MOVE_BOSS_D:
            work->base.state = HUM_RIKU_STATE_DIVE_CROUCH;
            break;
        case MOVE_DARK_FIRAGA_2:
            work->base.state = HUM_RIKU_STATE_DARK_FIRAGA;
            break;
        case MOVE_DARK_AURA_2:
            work->base.state = HUM_RIKU_STATE_DARK_AURA_START;
            break;
        }

        break;
    case BTL_REACTION_CARD_BROKEN:
        work->base.flags &= ~HUM_FLAG_IGNORE_BOUNDS;
        work->base.scaleX = Q_8_8(1);
        break;
    }

    switch (gBtlWork->battleId) {
    case BATTLE_RIKU_1:
        HumChooseCardAction(&work->base, 20, 40, 40, 20);
        break;
    case BATTLE_RIKU_2:
    case BATTLE_RIKU_5:
        if (HumChooseCardAction(&work->base, 15, 40, 40, 20)) {
            work->base.stockMoves = sHumRikuStockMoves[0];
        }

        break;
    case BATTLE_RIKU_3:
        if (HumChooseCardAction(&work->base, 10, 40, 40, 20)) {
            work->base.stockMoves = sHumRikuStockMoves[0];
        }

        break;
    case BATTLE_RIKU_4:
    case BATTLE_RIKU_6:
        if (HumChooseCardAction(&work->base, 3, 40, 40, 20)) {
            if (GetRandom() % 2) {
                work->base.stockMoves = sHumRikuStockMoves[0];
            } else {
                work->base.stockMoves = sHumRikuStockMoves[1];
            }
        }

        break;
    }

    switch (work->base.state) {
    case HUM_STATE_ENTER:
    case HUM_STATE_USE_ITEM:
        AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        break;
    case HUM_STATE_RELOAD:
        AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP | ANIM_FLAG_RANDOM_START, w->base.tiles);

        if ((gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) && RikuTryJumpAway(w)) {
            break;
        }

        if ((act->x - x >= 0 ? act->x - x : x - act->x) <= 0x4FFF) {
            if (x < 0x10000) {
                RikuJumpTo(w, (gBtlWork->xMax - 40) << 8, (gBtlWork->yMin + gBtlWork->yMax) << 7);
            } else {
                RikuJumpTo(w, (gBtlWork->xMin + 40) << 8, (gBtlWork->yMin + gBtlWork->yMax) << 7);
            }
        }

        break;
    case HUM_STATE_IDLE:
        AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);

        if (func_08081828()) {
            break;
        }

        if (AnimIsFinished(&work->base.anim) && (u16)(GetRandom() % 60) == 0) {
            work->base.state = HUM_STATE_MOVE;
            work->base.stateTimer = 0;
            break;
        }

        if (HumIsNearAreaEdge(&work->base, 40)) {
            RikuJumpTo(w, 0x10000, (gBtlWork->yMin + gBtlWork->yMax) << 7);
            break;
        }

        if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
            if (RikuTryJumpAway(w)) {
                break;
            }
        } else {
            HumFaceTarget(&work->base, 60);
        }

        work->base.stateTimer++;
        break;
    case HUM_STATE_MOVE:
        AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 1, ANIM_FLAG_LOOP, w->base.tiles);
        work->base.targetX = x;
        work->base.targetY = y;

        if (HumMoveToward(&work->base, work->base.targetX, work->base.targetY, 512) && AnimIsFinished(&work->base.anim)) {
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
            break;
        }

        if ((u16)(GetRandom() % 500) == 0 && (act->x - x >= 0 ? act->x - x : x - act->x) > 70) {
            RikuJumpTo(w, x, y);
            break;
        }

        if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
            if (RikuTryJumpAway(w)) {
                break;
            }
        } else {
            HumFaceTarget(&work->base, 1);
        }

        work->base.stateTimer++;
        break;
    case HUM_STATE_DEFEATED:
    case HUM_STATE_CARD_BROKEN:
    case HUM_STATE_STUNNED:
    case HUM_STATE_GRAVITY:
        AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case HUM_STATE_HURT:
        AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 2, 0, w->base.tiles);

        if (work->base.stateTimer == 3) {
            switch ((s32)(u16)(GetRandom() % 3)) {
            case 0:
                m4aSongNumStart(SONG_VO_RK_DAMAGE00);
                break;
            case 1:
                m4aSongNumStart(SONG_VO_RK_DAMAGE01);
                break;
            case 2:
            default:
                m4aSongNumStart(SONG_VO_RK_DAMAGE02);
                break;
            }
        }

        break;
    case HUM_RIKU_STATE_DARK_AURA_START:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 14, 0, w->base.tiles);
            m4aSongNumStart(SONG_VO_RK_ATTACK08);
            m4aSongNumStart(SONG_BTL_AN_STANDENTRY);
            FadeStartOut(FADE_MODE_DARK_MAGENTA, 80);
        }

        work->base.vz = 0;
        act->z += (-0x2800 - act->z) >> 5;

        if (AnimIsFinished(&work->base.anim)) {
            work->base.state = HUM_RIKU_STATE_DARK_AURA_LEAP;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_DARK_AURA_LEAP: {
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 15, 0, w->base.tiles);
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 1:
        case 2:
            work->base.vz -= 179;
            break;
        }

        w->flags |= RIKU_FLAG_AFTERIMAGE;

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            s32 frontX = act->x - 0x3000;
            act->x += (act->originX - frontX) >> 3;
        } else {
            s32 frontX = act->x + 0x3000;
            act->x += (act->originX - frontX) >> 3;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.state = HUM_RIKU_STATE_DARK_AURA_EXIT;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    }
    case HUM_RIKU_STATE_DARK_AURA_EXIT:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 16, 0, w->base.tiles);
            work->base.flags |= HUM_FLAG_IGNORE_BOUNDS;
        }

        work->base.vz = 0;
        w->flags |= RIKU_FLAG_AFTERIMAGE;

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            act->x -= 0xC00;
        } else {
            act->x += 0xC00;
        }

        if (act->x < ((gBtlWork->xMin - 48) << 8) ||
            act->x > ((gBtlWork->xMax + 48) << 8)) {
            work->base.state = HUM_RIKU_STATE_DARK_AURA_AIM;
            work->base.stateTimer = 0;
            w->dashCount = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_DARK_AURA_AIM:
        if (work->base.stateTimer == 0) {
            act->flags ^= BTLOBJ_FLAG_FACING_LEFT;

            switch ((u16)(GetRandom() % 3)) {
            case 0:
                AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 17, ANIM_FLAG_LOOP, w->base.tiles);

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    w->unk_1C4 = (u16)(GetRandom() % 17) + 184;
                } else {
                    w->unk_1C4 = (u16)(GetRandom() % 17) + 56;
                }

                act->y = y + (((u16)(GetRandom() % 33) - 16) << 8);
                break;
            case 1:
                AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 18, ANIM_FLAG_LOOP, w->base.tiles);

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    w->unk_1C4 = (u16)(GetRandom() % 17) + 203;
                } else {
                    w->unk_1C4 = (u16)(GetRandom() % 17) + 37;
                }

                act->y = y + (((u16)(GetRandom() % 17) + 16) << 8);
                break;
            case 2:
                AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 19, ANIM_FLAG_LOOP, w->base.tiles);

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    w->unk_1C4 = (u16)(GetRandom() % 17) + 165;
                } else {
                    w->unk_1C4 = (u16)(GetRandom() % 17) + 75;
                }

                act->y = y - (((u16)(GetRandom() % 17) + 16) << 8);
                break;
            }

            act->z = -0x1000;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x = x + 0x6300;
                BgFxStartRikuLimit(act->x, act->y, act->z, 192);
            } else {
                act->x = x - 0x6300;
                BgFxStartRikuLimit(act->x, act->y, act->z, 64);
            }

            m4aSongNumStart(SONG_BTL_RK_LIMITENTRY);
            work->base.steps = 10;
            work->base.scaleX = 10;
        }

        work->base.vz = 0;
        BtlMapFollowPosition(gBtlWork->actor->x, gBtlWork->actor->y, gBtlWork->actor->z);
        ApproachValue(&work->base.scaleX, Q_8_8(1), work->base.steps);
        work->base.steps--;

        if (work->base.steps <= 0) {
            work->base.state = HUM_RIKU_STATE_DARK_AURA_DASH;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_DARK_AURA_DASH:
        if (work->base.stateTimer == 0) {
            m4aSongNumStart(SONG_EF_RK_LIMITMOV);
            MakeOpponentsHittable();
        }

        w->flags |= RIKU_FLAG_AFTERIMAGE;
        act->x += gSineTable[(u8)w->unk_1C4] * 12;
        act->y += -gSineTable[(u8)w->unk_1C4 + 64] * 12;

        if (ApplyAttackBox(295, act->x, act->y, act->z, 24, 16, 24)) {
            m4aSongNumStart(SONG_BTL_RK_HIT03);
        }

        work->base.vz = 0;
        BtlMapFollowPosition(gBtlWork->actor->x, gBtlWork->actor->y, gBtlWork->actor->z);

        if (work->base.stateTimer == 15 && (s16)w->dashCount > 4) {
            work->base.state = HUM_RIKU_STATE_DARK_AURA_END;
            work->base.stateTimer = 0;
        } else if (work->base.stateTimer > 30) {
            work->base.state = HUM_RIKU_STATE_DARK_AURA_AIM;
            work->base.stateTimer = 0;
            w->dashCount++;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_DARK_AURA_END:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 20, 0, w->base.tiles);
            work->base.steps = 40;
        }

        if (work->base.steps > 0) {
            ApproachValue(&act->x, act->originX, work->base.steps);
            ApproachValue(&act->y, act->originY, work->base.steps);
            ApproachValue(&act->z, act->originZ, work->base.steps);
            work->base.steps--;

            if (work->base.steps <= 0) {
                BgFxStartRikuLimitFinish(act->x, act->y - 0x2000, 0);
            }
        }

        if (!BgFxIsActive() && work->base.steps <= 0 && AnimIsFinished(&work->base.anim)) {
            work->base.flags &= ~HUM_FLAG_IGNORE_BOUNDS;
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            FadeStartIn(FADE_MODE_DARK_MAGENTA, 30);
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_VERTICAL_SLASH:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 10, 0, w->base.tiles);
            m4aSongNumStart(SONG_VO_RK_ATTACK02);
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 1:
                work->base.vz = -972;
                break;
            case 4:
                work->base.vz = 0x1000;

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT ?
                    ApplyAttackBox(293, act->x - 0x2000, act->y, act->z, 28, 16, 16) :
                    ApplyAttackBox(293, act->x + 0x2000, act->y, act->z, 28, 16, 16)) {
                    m4aSongNumStart(SONG_BTL_RK_HIT00);
                }

                break;
            }
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 1:
        case 2:
        case 3: {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                s32 backX = act->x + 0x3200;
                act->x += (act->originX - backX) >> 3;
            } else {
                s32 backX = act->x - 0x3200;
                act->x += (act->originX - backX) >> 3;
            }

            break;
        }
        }

        if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_DARK_FIRAGA:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 13, 0, w->base.tiles);
            m4aSongNumStart(SONG_VO_RK_ATTACK08);
            w->flags &= ~RIKU_FLAG_FIRE_LAUNCHED;
            HumFaceTarget(&work->base, 1);
        }

        if (w->flags & RIKU_FLAG_FIRE_LAUNCHED) {
            BtlObj* player = gBtlWork->actor;

            if (player != NULL) {
                s32 follow = FALSE;

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    if (player->x < act->x - 0x2000) {
                        follow = TRUE;
                    }
                } else {
                    if (player->x > act->x + 0x2000) {
                        follow = TRUE;
                    }
                }

                if (follow) {
                    BgFxSetTarget(player->x, player->y, player->z - (player->centerHeight << 8));
                }
            }
        }

        if (!(w->flags & RIKU_FLAG_FIRE_LAUNCHED) && work->base.anim.timer == 0) {
            s16 step = 0;
            s32 spawn = FALSE;

            switch (AnimGetFrame(&work->base.anim)) {
            case 0:
                step = -10;
                break;
            case 1:
                step = -24;
                break;
            case 4:
                step = 12;
                break;
            case 5:
                step = 15;
                break;
            case 6:
                step = 7;
                spawn = TRUE;
                break;
            }

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x -= step << 8;
            } else {
                act->x += step << 8;
            }

            if (spawn) {
                w->flags |= RIKU_FLAG_FIRE_LAUNCHED;

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    BgFxStartFire(SPELL_TIER_DARK, act->x - 0x4A00, act->y, act->z - 0x1800,
                        act->originX - 0xC800, act->originY, act->z - 0x1800, TRUE, 296);
                } else {
                    BgFxStartFire(SPELL_TIER_DARK, act->x + 0x4A00, act->y, act->z - 0x1800,
                        act->originX + 0xC800, act->originY, act->z - 0x1800, FALSE, 296);
                }
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim) && !BgFxIsActive()) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_SWEEP:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 9, 0, w->base.tiles);
            m4aSongNumStart(GetRandom() % 2 + SONG_VO_RK_ATTACK04);
        }

        if (work->base.anim.timer == 0) {
            s32 step = 0;
            s32 hit = FALSE;

            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                step = 4;
                break;
            case 3:
                step = 16;
                hit = TRUE;
                break;
            case 4:
                step = 5;
                break;
            case 6:
                step = 1;
                break;
            case 7:
                step = 4;
                hit = TRUE;
                break;
            case 8:
                step = 6;
                break;
            case 9:
            case 10:
                step = 2;
                break;
            }

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x -= step << 8;
            } else {
                act->x += step << 8;
            }

            if (hit) {
                MakeOpponentsHittable();

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT ?
                    ApplyAttackBox(292, act->x - 0x1400, act->y, act->z, 30, 16, 16) :
                    ApplyAttackBox(292, act->x + 0x1400, act->y, act->z, 30, 16, 16)) {
                    m4aSongNumStart(SONG_BTL_RK_HIT01);
                }
            }
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x -= 256;
            } else {
                act->x += 256;
            }

            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_DASH_SLASH:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 8, 0, w->base.tiles);
            m4aSongNumStart(GetRandom() % 2 + SONG_VO_RK_ATTACK04);
        }

        if (AnimGetGfxIndex(&work->base.anim) == 6) {
            w->flags |= RIKU_FLAG_AFTERIMAGE;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                s32 backX = act->x + 0x5800;
                act->x += (act->originX - backX) >> 2;
            } else {
                s32 backX = act->x - 0x5800;
                act->x += (act->originX - backX) >> 2;
            }
        }

        if (work->base.anim.timer == 0) {
            s16 step = 0;
            s32 hit = FALSE;
            s32 attack = 290;

            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 1:
                step = 15;
                break;
            case 2:
                step = 5;
                hit = TRUE;
                attack = 290;
                break;
            case 4:
                step = -5;
                break;
            case 5:
                step = 10;
                break;
            case 6:
                step = 20;
                hit = TRUE;
                attack = 291;
                break;
            case 7:
                step = -9;
                break;
            case 8:
                step = 6;
                break;
            case 9:
                step = 1;
                break;
            }

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x -= step << 8;
            } else {
                act->x += step << 8;
            }

            if (hit) {
                MakeOpponentsHittable();

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT ?
                    ApplyAttackBox(attack, act->x - 0x1400, act->y, act->z, 20, 8, 16) :
                    ApplyAttackBox(attack, act->x + 0x1400, act->y, act->z, 20, 8, 16)) {
                    m4aSongNumStart(SONG_BTL_RK_HIT01);

                    if (attack == 291) {
                        FadeStartIn(FADE_MODE_ADD_WHITE, 45);

                        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                            SetBattleZoom(6, Q_8_8(1.3), act->x - 0x2000, (act->y - 0x1800) + act->z);
                        } else {
                            SetBattleZoom(6, Q_8_8(1.3), act->x + 0x2000, (act->y - 0x1800) + act->z);
                        }
                    }
                }
            }
        }

        if (work->base.anim.timer == 2 && AnimGetGfxIndex(&work->base.anim) == 6) {
            SetBattleZoom(8, Q_8_8(1), gBtlWork->x2, gBtlWork->y2);
        }

        if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_DIVE_CROUCH:
        if (act->z < act->groundZ) {
            break;
        }

        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 3, 0, w->base.tiles);
            m4aSongNumStart(SONG_VO_RK_ATTACK02);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = HUM_RIKU_STATE_DIVE_RISE;
            work->base.vz = -0x600;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_DIVE_RISE:
        act->x += (x - act->x) >> 4;
        act->y += (y - act->y) >> 4;

        if (work->base.vz < 0) {
            if (work->base.vz > -0x200) {
                AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 5, 0, w->base.tiles);
            } else {
                AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 4, 0, w->base.tiles);
            }
        } else {
            work->base.stateTimer = 0;
            work->base.state = HUM_RIKU_STATE_DIVE;
            break;
        }

        work->base.stateTimer++;
        break;
    case HUM_RIKU_STATE_DIVE:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 11, 0, w->base.tiles);
            w->flags &= ~RIKU_FLAG_DIVE_HIT;
        }

        act->x += (x - act->x) >> 4;
        act->y += (y - act->y) >> 4;

        if (AnimGetFrame(&work->base.anim) > 1) {
            if (ApplyAttackBox(294, act->x, act->y, act->z, 10, 10, 4)) {
                m4aSongNumStart(SONG_BTL_RK_HIT02);
                w->flags |= RIKU_FLAG_DIVE_HIT;
            }
        }

        if ((w->flags & RIKU_FLAG_DIVE_HIT) || act->z >= act->groundZ) {
            work->base.stateTimer = 0;
            work->base.state = HUM_RIKU_STATE_DIVE_RECOIL;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_DIVE_RECOIL:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 12, 0, w->base.tiles);
            work->base.vz = -0x400;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                work->base.targetX = act->x + 0x3000;
            } else {
                work->base.targetX = act->x - 0x3000;
            }
        }

        act->x += (work->base.targetX - act->x) >> 3;

        if (AnimIsFinished(&work->base.anim) && act->z >= act->groundZ) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_JUMP_CROUCH:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 3, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = HUM_RIKU_STATE_JUMP_AIR;
            work->base.vz = w->unk_1C4;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_RIKU_STATE_JUMP_AIR:
        act->x += (work->base.targetX - act->x) >> 4;
        act->y += (work->base.targetY - act->y) >> 4;

        if (work->base.vz < 0) {
            if (work->base.vz <= -0x200) {
                AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 4, 0, w->base.tiles);
            } else {
                AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 5, 0, w->base.tiles);
            }
        } else if (work->base.vz <= 0x1FF) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 5, 0, w->base.tiles);
        } else {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 6, 0, w->base.tiles);
        }

        if (act->z >= 0) {
            work->base.stateTimer = 0;
            work->base.state = HUM_RIKU_STATE_JUMP_LAND;
            break;
        }

        HumFaceTarget(&work->base, 1);
        work->base.stateTimer++;
        break;
    case HUM_RIKU_STATE_JUMP_LAND:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumRikuAnimDefs, &w->base.anim, 7, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = HUM_STATE_IDLE;
        } else {
            work->base.stateTimer++;
        }

        break;
    }

    return HumUpdate(&work->base);
}

void task_hum_riku_2(RikuWork* work) {
    HumDraw(&work->base);

    if ((work->flags & RIKU_FLAG_AFTERIMAGE) && (work->sub.flags & HUM_SUB_FLAG_HIDDEN)) {
        switch (work->afterimageTimer % 2) {
        case 0:
            RikuDrawAfterimage(work, &work->spawns[2]);
            break;
        case 1:
            RikuDrawAfterimage(work, &work->spawns[4]);
            break;
        }

        work->afterimageTimer++;
    }

    work->spawns[4] = work->spawns[3];
    work->spawns[3] = work->spawns[2];
    work->spawns[2] = work->spawns[1];
    work->spawns[1] = work->spawns[0];
    RikuSaveAfterimage(work, &work->spawns[0]);
}

void task_hum_riku_3(HumWork* work) {
    HumReleaseResources(work);
}
