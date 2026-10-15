/**
 * hum_laxene.c
 * Larxene Boss
 */

#include "system_state.h"
#include "fade.h"
#include "obj_api.h"
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
#include "card_label_data.h"
#include "enemy_ids.h"
#include "obj.h"
#include "card_ids.h"

static const u32 sHumLaxeneStockMoves[2][3] = {
    { MOVE_BOSS_A, MOVE_BOSS_C, MOVE_BOSS_C },
    { MOVE_BOSS_B, MOVE_BOSS_B, MOVE_BOSS_A },
};

static const AnimDef sHumLaxeneAnimDefs[15] = {
    { gLaxineIdleFrames, gLaxineIdleAnims, gLaxineIdleTiles, 0 },
    { gLaxineMoveFrames, gLaxineMoveAnims, gLaxineMoveTiles, 0 },
    { gLaxineMoveFrames, gLaxineMoveAnims, gLaxineMoveTiles, 1 },
    { gLaxineDamageFrames, gLaxineDamageAnims, gLaxineDamageTiles, 0 },
    { gLaxineRenzokFrames, gLaxineRenzokAnims, gLaxineRenzokTiles, 1 },
    { gLaxineRenzokFrames, gLaxineRenzokAnims, gLaxineRenzokTiles, 2 },
    { gLaxineMagicFrames, gLaxineMagicAnims, gLaxineMagicTiles, 0 },
    { gLaxineMagicFrames, gLaxineMagicAnims, gLaxineMagicTiles, 1 },
    { gLaxineMagicFrames, gLaxineMagicAnims, gLaxineMagicTiles, 2 },
    { gLaxineMagicFrames, gLaxineMagicAnims, gLaxineMagicTiles, 3 },
    { gLaxineMagicFrames, gLaxineMagicAnims, gLaxineMagicTiles, 4 },
    { gLaxineMagicFrames, gLaxineMagicAnims, gLaxineMagicTiles, 5 },
    { gLaxineKnifethrowFrames, gLaxineKnifethrowAnims, gLaxineKnifethrowTiles, 0 },
    { gLaxineRenzokFrames, gLaxineRenzokAnims, gLaxineRenzokTiles, 3 },
    { gLaxineRenzokFrames, gLaxineRenzokAnims, gLaxineRenzokTiles, 4 },
};

static const HumDef sHumLaxeneDef = { 128, gLaxinePalette, 0, { ENEMY_LARXENE, 99, 60, 14, 46, 99, 0 } };

TaskDesc gTaskDescHumLaxene = {
    "task_hum_laxene",
    (TaskInitFunc)task_hum_laxene_0,
    (TaskUpdateFunc)task_hum_laxene_1,
    (TaskDrawFunc)task_hum_laxene_2,
    (TaskDestroyFunc)task_hum_laxene_3,
    sizeof(LaxeneWork),
};

static TaskDesc sTaskDescHumLaxeneKnf = {
    "task_hum_laxene_knf",
    (TaskInitFunc)task_hum_laxene_knf_0,
    (TaskUpdateFunc)task_hum_laxene_knf_1,
    (TaskDrawFunc)task_hum_laxene_knf_2,
    (TaskDestroyFunc)task_hum_laxene_knf_3,
    sizeof(LaxeneKnfWork),
};

void LaxeneHover(HumWork* work, s32 hoverZ) {
    BtlObj* act;
    s32 bobZ;

    if (hoverZ != 0) {
        act = &work->actor;
        bobZ = hoverZ + gSineTable[gFrameCounter * 4 % 256] * 6;
        work->vz = 0;
        act->z += (bobZ - act->z) >> 3;
    }
}

void CreateHumLaxeneKnfTask(LaxeneWork* work, s16 dx, s16 dz) {
    BtlObj* act = &work->base.actor;
    VixenNdlArgs args;

    if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
        args.x = act->x + (dx << 8);
        args.facingLeft = 1;
    } else {
        args.x = act->x - (dx << 8);
        args.facingLeft = 0;
    }

    args.z = act->z + (dz << 8);
    args.y = act->y;
    TaskCreate(&work->tasks, &sTaskDescHumLaxeneKnf, &args);
}

void task_hum_laxene_0(LaxeneWork* work) {
    HumInit(&work->base, &sHumLaxeneDef);
    work->flags = 0;
    work->hoverZ = -0x3000;
    work->scaleSteps = 0;
    work->base.actor.flags |= BTLOBJ_FLAG_IMMUNE_BIND;
    work->base.stockMoves = sHumLaxeneStockMoves[0];
    TaskPoolInit(&work->tasks, 12);
}

enum HumLaxeneState {
    HUM_LAXENE_STATE_COMBO = 21,
    HUM_LAXENE_STATE_THUNDER_WINDUP,
    HUM_LAXENE_STATE_THUNDER,
    HUM_LAXENE_STATE_THUNDER_END,
    HUM_LAXENE_STATE_BEAM_WINDUP,
    HUM_LAXENE_STATE_BEAM_CHARGE,
    HUM_LAXENE_STATE_BEAM_AIM,
    HUM_LAXENE_STATE_BEAM,
    HUM_LAXENE_STATE_BEAM_END,
    HUM_LAXENE_STATE_KNIFE_THROW,
    HUM_LAXENE_STATE_THUNDER_COMBO,
    HUM_LAXENE_STATE_WARP_SLASH,
    HUM_LAXENE_STATE_WARP_THROW
};

u8 task_hum_laxene_1(LaxeneWork* work) {
    LaxeneWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 z;
    s16 step;
    s32 dy;

    w = work;
    act = &work->base.actor;
    GetEnemyTargetPosition(act, &x, &y, &z);

    switch (HumUpdateReaction(&work->base)) {
    case BTL_REACTION_CARD_ACTION:
        work->base.stateTimer = 0;
        work->base.steps = 0;

        switch ((u32)HumResolveCardMove(&work->base)) {
        case MOVE_BOSS_A:
            work->base.state = HUM_LAXENE_STATE_COMBO;
            break;
        case MOVE_BOSS_B:
            work->base.state = HUM_LAXENE_STATE_KNIFE_THROW;
            break;
        case MOVE_BOSS_C:
        case MOVE_BOSS_D:
            if (act->hp < (act->maxHp >> 1)) {
                work->base.state = HUM_LAXENE_STATE_THUNDER_COMBO;
            } else {
                work->base.state = HUM_LAXENE_STATE_THUNDER_WINDUP;
            }

            break;
        case MOVE_LIGHTNING_BOLT:
            work->base.state = HUM_LAXENE_STATE_BEAM_WINDUP;
            break;
        case MOVE_TELEPORT_RUSH:
            work->base.steps = GetRandom() % 4 + 4;
            work->base.state = HUM_LAXENE_STATE_WARP_SLASH;
            m4aSongNumStart(SONG_SND_284);
            break;
        }

        break;
    case BTL_REACTION_CARD_BROKEN:
        m4aSongNumStop(SONG_EF_RAC_BEEM);
        work->base.scaleX = Q_8_8(1);
        work->base.scaleY = Q_8_8(1);
        break;
    }

    if (gBtlWork->battleId == BATTLE_LARXENE_1) {
        if (HumChooseCardAction(&work->base, 15, 80, 80, 50)) {
            work->base.stockMoves = sHumLaxeneStockMoves[0];
        }
    } else if (HumChooseCardAction(&work->base, 5, 80, 80, 50)) {
        if (GetRandom() % 2) {
            work->base.stockMoves = sHumLaxeneStockMoves[0];
        } else {
            work->base.stockMoves = sHumLaxeneStockMoves[1];
        }
    }

    switch (work->base.state) {
    case HUM_STATE_ENTER:
    case HUM_STATE_USE_ITEM:
        AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        break;
    case HUM_STATE_RELOAD:
        AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        break;
    case HUM_STATE_IDLE:
        AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        HumFaceTarget(&work->base, 5);

        if (func_08081828() == 0) {
            if (GetRandom() % 30 == 0) {
                work->base.state = HUM_STATE_MOVE;
                work->base.stateTimer = 0;
            } else {
                work->base.stateTimer++;
            }
        }

        break;
    case HUM_STATE_MOVE:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 1, 0, w->base.tiles);
            work->base.targetX = (gBtlWork->xMin + GetRandom() % (gBtlWork->xMax - gBtlWork->xMin + 1)) << 8;
            work->base.targetY = (gBtlWork->yMin + GetRandom() % (gBtlWork->yMax - gBtlWork->yMin + 1)) << 8;
            work->base.targetZ = -((GetRandom() % 71) << 8);

            if (act->btl->hcEffect == HC_EFFECT_DASH) {
                work->base.steps = 12;
            } else {
                work->base.steps = 25;
            }

            w->hoverZ = 0;
        } else if (AnimIsFinished(&work->base.anim)) {
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 2, ANIM_FLAG_LOOP, w->base.tiles);
        }

        ApproachValue(&act->x, work->base.targetX, work->base.steps);
        ApproachValue(&act->y, work->base.targetY, work->base.steps);
        ApproachValue(&act->z, work->base.targetZ, work->base.steps);
        work->base.steps--;

        if (work->base.steps <= 0) {
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
            w->hoverZ = act->z;
            break;
        }

        work->base.vz = 0;

        if (act->x < work->base.targetX) {
            act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
        } else {
            act->flags |= BTLOBJ_FLAG_FACING_LEFT;
        }

        work->base.stateTimer++;
        break;
    case HUM_STATE_HURT:
    case HUM_STATE_DEFEATED:
    case HUM_STATE_CARD_BROKEN:
    case HUM_STATE_STUNNED:
    case HUM_STATE_GRAVITY:
        w->hoverZ = 0;
        AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 3, 0, w->base.tiles);
        break;
    case HUM_LAXENE_STATE_BEAM_WINDUP:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 6, 0, w->base.tiles);
            w->hoverZ = 0;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = HUM_LAXENE_STATE_BEAM_CHARGE;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LAXENE_STATE_BEAM_CHARGE:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 7, ANIM_FLAG_LOOP, w->base.tiles);

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                BgFxStartThunder(SPELL_TIER_BASE, act->x + 0x400, act->y, act->z - 0x5000, act->x,
                    act->y, act->z - 0x5000, 0x135);
            } else {
                BgFxStartThunder(SPELL_TIER_BASE, act->x - 0x400, act->y, act->z - 0x5000, act->x,
                    act->y, act->z - 0x5000, 0x135);
            }
        }

        if (BgFxIsActive()) {
            work->base.stateTimer++;
        } else {
            work->base.stateTimer = 0;
            work->base.state = HUM_LAXENE_STATE_BEAM_AIM;
        }

        break;
    case HUM_LAXENE_STATE_BEAM_AIM:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 9, 0, w->base.tiles);
        }

        HumFaceTarget(&work->base, 1);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = HUM_LAXENE_STATE_BEAM;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LAXENE_STATE_BEAM:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 10, ANIM_FLAG_LOOP, w->base.tiles);
            m4aSongNumStart(SONG_EF_RAC_BEEM);

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                BgFxStartLaxeneBeam(act->x - 0x1000, act->y, act->z - 0x3000, TRUE, 310);
            } else {
                BgFxStartLaxeneBeam(act->x + 0x1000, act->y, act->z - 0x3000, FALSE, 310);
            }
        }

        dy = (y - act->y) >> 3;
        act->y += dy;
        BgFxAddPosition(0, dy, 0);

        if (BgFxIsActive()) {
            work->base.stateTimer++;
        } else {
            m4aSongNumStop(SONG_EF_RAC_BEEM);
            work->base.stateTimer = 0;
            work->base.state = HUM_LAXENE_STATE_BEAM_END;
        }

        break;
    case HUM_LAXENE_STATE_BEAM_END:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 11, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LAXENE_STATE_THUNDER_WINDUP:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 6, 0, w->base.tiles);
            w->hoverZ = 0;
            m4aSongNumStart(SONG_SND_283);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = HUM_LAXENE_STATE_THUNDER;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LAXENE_STATE_THUNDER:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 7, ANIM_FLAG_LOOP, w->base.tiles);

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                BgFxStartThunder(SPELL_TIER_RA, act->x + 0x400, act->y, act->z - 0x5000, x, y, 0, 0x135);
            } else {
                BgFxStartThunder(SPELL_TIER_RA, act->x - 0x400, act->y, act->z - 0x5000, x, y, 0, 0x135);
            }
        }

        if (BgFxIsActive()) {
            work->base.stateTimer++;
        } else {
            work->base.stateTimer = 0;
            work->base.state = HUM_LAXENE_STATE_THUNDER_END;
        }

        break;
    case HUM_LAXENE_STATE_THUNDER_END:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 8, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LAXENE_STATE_KNIFE_THROW:
        if (work->base.stateTimer == 0) {
            m4aSongNumStart(SONG_SND_285);
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 12, 0, w->base.tiles);
            FadeToAmount(FADE_MODE_BLACK, gBtlWork->fadeAmount, 8);
            w->hoverZ = 0;
            work->base.vz = 0x400;
        }

        MakeOpponentsHittable();

        switch (work->base.stateTimer) {
        case 28:
            CreateHumLaxeneKnfTask(w, -38, -11);
            break;
        case 32:
            CreateHumLaxeneKnfTask(w, -37, -25);
            break;
        case 36:
            CreateHumLaxeneKnfTask(w, -32, -38);
            break;
        case 44:
            CreateHumLaxeneKnfTask(w, -36, -18);
            break;
        case 48:
            CreateHumLaxeneKnfTask(w, -35, -32);
            break;
        case 52:
            CreateHumLaxeneKnfTask(w, -30, -45);
            break;
        }

        if (work->base.stateTimer > 120) {
            FadeToOriginal(FADE_MODE_BLACK, 8);
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LAXENE_STATE_COMBO:
        if (work->base.stateTimer == 0) {
            AnimReset(&work->base.anim);

            if (work->base.steps == 0) {
                AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 5, 0, w->base.tiles);
            } else {
                AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 4, 0, w->base.tiles);
            }

            w->hoverZ = 0;
            w->flags &= ~LAXENE_FLAG_ATTACK_HIT;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                step = 13;
                break;
            case 3:
                step = -1;
                break;
            case 4:
                step = -4;
                break;
            case 5:
                step = -3;
                break;
            case 9:
                step = -2;
                break;
            case 10:
                step = -3;
                break;
            default:
                step = 0;
                break;
            }

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x -= step << 8;
            } else {
                act->x += step << 8;
            }
        }

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            s32 frontX = act->x - 0x1000;
            act->x += (x - frontX) >> 4;
        } else {
            s32 frontX = act->x + 0x1000;
            act->x += (x - frontX) >> 4;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                MakeOpponentsHittable();

                if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                    ? ApplyAttackBox(0x131, act->x - 0x1800, act->y, act->z, 8, 24, 50)
                    : ApplyAttackBox(0x131, act->x + 0x1800, act->y, act->z, 8, 24, 50)) {
                    m4aSongNumStart(SONG_BTL_RAC_HIT);
                    w->flags |= LAXENE_FLAG_ATTACK_HIT;
                }

                break;
            case 8:
                MakeOpponentsHittable();

                if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                    ? ApplyAttackBox(0x132, act->x - 0x1000, act->y, act->z, 16, 24, 50)
                    : ApplyAttackBox(0x132, act->x + 0x1000, act->y, act->z, 16, 24, 50)) {
                    m4aSongNumStart(SONG_BTL_RAC_HIT);
                    w->flags |= LAXENE_FLAG_ATTACK_HIT;
                }

                break;
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;

            if (work->base.steps <= 0 && (w->flags & LAXENE_FLAG_ATTACK_HIT)) {
                work->base.state = HUM_LAXENE_STATE_COMBO;
                work->base.steps++;
            } else {
                ClearBtlObjActionFlags(act);
                work->base.state = HUM_STATE_IDLE;
            }
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LAXENE_STATE_THUNDER_COMBO:
        if (work->base.stateTimer == 0) {
            AnimReset(&work->base.anim);

            if ((work->base.steps & 1) == 0) {
                AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 13, 0, w->base.tiles);
            } else {
                AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 14, 0, w->base.tiles);
            }

            w->hoverZ = 0;
            w->flags &= ~LAXENE_FLAG_ATTACK_HIT;
            act->originX = act->x;
            work->base.vz = 0x400;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                step = 13;
                break;
            case 3:
                step = -1;
                break;
            case 4:
                step = -4;
                break;
            case 5:
                step = -3;
                break;
            case 9:
                step = -2;
                break;
            case 10:
                step = -3;
                break;
            default:
                step = 0;
                break;
            }

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x -= step << 8;
            } else {
                act->x += step << 8;
            }
        }

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            s32 frontX = act->x - 0x1000;
            act->x += (x - frontX) >> 3;
        } else {
            s32 frontX = act->x + 0x1000;
            act->x += (x - frontX) >> 3;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                MakeOpponentsHittable();

                if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                    ? ApplyAttackBox(0x131, act->x - 0x1800, act->y, act->z, 8, 24, 50)
                    : ApplyAttackBox(0x131, act->x + 0x1800, act->y, act->z, 8, 24, 50)) {
                    m4aSongNumStart(SONG_BTL_RAC_HIT);
                    w->flags |= LAXENE_FLAG_ATTACK_HIT;

                    if (work->base.steps == 4) {
                        MakeOpponentsHittable();
                        BgFxStartThunderStrike(x, y, 0, 0x137);
                    }
                }

                break;
            case 8:
                MakeOpponentsHittable();

                if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                    ? ApplyAttackBox(0x132, act->x - 0x1000, act->y, act->z, 16, 24, 50)
                    : ApplyAttackBox(0x132, act->x + 0x1000, act->y, act->z, 16, 24, 50)) {
                    m4aSongNumStart(SONG_BTL_RAC_HIT);
                    w->flags |= LAXENE_FLAG_ATTACK_HIT;

                    if (work->base.steps == 4) {
                        MakeOpponentsHittable();
                        BgFxStartThunderStrike(x, y, z, 0x137);
                    }
                }

                break;
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;

            if (w->flags & LAXENE_FLAG_ATTACK_HIT) {
                if (work->base.steps > 3) {
                    ClearBtlObjActionFlags(act);
                    work->base.state = HUM_STATE_IDLE;
                } else {
                    work->base.state = HUM_LAXENE_STATE_THUNDER_COMBO;
                    work->base.steps++;
                }
            } else {
                ClearBtlObjActionFlags(act);
                work->base.state = HUM_STATE_IDLE;
            }
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LAXENE_STATE_WARP_SLASH:
        if (work->base.stateTimer == 0) {
            act->flags ^= BTLOBJ_FLAG_FACING_LEFT;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                s32 dist = ((GetRandom() % 57) << 8) + 0x1800;
                act->x = x + dist;
            } else {
                s32 dist = ((GetRandom() % 57) << 8) + 0x1800;
                act->x = x - dist;
            }

            {
                s32 offsetY = ((GetRandom() % 27) << 8) - 0xD00;
                act->y = y + offsetY;
            }

            act->z = 0;
            AnimReset(&work->base.anim);

            if ((GetRandom() & 1) == 0) {
                AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 13, 0, w->base.tiles);
            } else {
                AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 14, 0, w->base.tiles);
            }

            w->hoverZ = 0;
            w->flags &= ~LAXENE_FLAG_ATTACK_HIT;
            w->scaleSteps = 8;
            work->base.scaleX = 5;
            work->base.scaleY = Q_8_8(1.5);
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                step = 13;
                break;
            case 3:
                step = -1;
                break;
            case 4:
                step = -4;
                break;
            case 5:
                step = -3;
                break;
            case 9:
                step = -2;
                break;
            case 10:
                step = -3;
                break;
            default:
                step = 0;
                break;
            }

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x -= step << 8;
            } else {
                act->x += step << 8;
            }
        }

        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
            s32 frontX = act->x - 0x1000;
            act->x += (x - frontX) >> 3;
        } else {
            s32 frontX = act->x + 0x1000;
            act->x += (x - frontX) >> 3;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                MakeOpponentsHittable();

                if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                    ? ApplyAttackBox(0x131, act->x - 0x1800, act->y, act->z, 8, 24, 50)
                    : ApplyAttackBox(0x131, act->x + 0x1800, act->y, act->z, 8, 24, 50)) {
                    m4aSongNumStart(SONG_BTL_RAC_HIT);
                    w->flags |= LAXENE_FLAG_ATTACK_HIT;
                }

                break;
            case 8:
                MakeOpponentsHittable();

                if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                    ? ApplyAttackBox(0x132, act->x - 0x1000, act->y, act->z, 16, 24, 50)
                    : ApplyAttackBox(0x132, act->x + 0x1000, act->y, act->z, 16, 24, 50)) {
                    m4aSongNumStart(SONG_BTL_RAC_HIT);
                    w->flags |= LAXENE_FLAG_ATTACK_HIT;
                }

                break;
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.steps--;

            if (work->base.steps > 0) {
                if (GetRandom() % 6 != 0) {
                    work->base.state = HUM_LAXENE_STATE_WARP_SLASH;
                } else {
                    work->base.state = HUM_LAXENE_STATE_WARP_THROW;
                }
            } else {
                ClearBtlObjActionFlags(act);
                work->base.state = HUM_STATE_IDLE;
            }
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LAXENE_STATE_WARP_THROW:
        if (work->base.stateTimer == 0) {
            m4aSongNumStart(SONG_SND_285);
            act->flags ^= BTLOBJ_FLAG_FACING_LEFT;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                s32 dist = ((GetRandom() % 41) << 8) + 0x5000;
                act->x = x + dist;
            } else {
                s32 dist = ((GetRandom() % 41) << 8) + 0x5000;
                act->x = x - dist;
            }

            {
                s32 offsetY = ((GetRandom() % 49) << 8) - 0x1800;
                act->y = y + offsetY;
            }

            act->z = 0;
            AnimReset(&work->base.anim);
            AnimChangeWithDef(sHumLaxeneAnimDefs, &w->base.anim, 12, 0, w->base.tiles);
            FadeToAmount(FADE_MODE_BLACK, gBtlWork->fadeAmount, 8);
            w->hoverZ = 0;
            work->base.vz = 0x400;
            w->scaleSteps = 8;
            work->base.scaleX = 5;
            work->base.scaleY = Q_8_8(1.5);
        }

        MakeOpponentsHittable();

        switch (work->base.stateTimer) {
        case 28:
            CreateHumLaxeneKnfTask(w, -38, -11);
            break;
        case 32:
            CreateHumLaxeneKnfTask(w, -37, -25);
            break;
        case 36:
            CreateHumLaxeneKnfTask(w, -32, -38);
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            FadeToOriginal(FADE_MODE_BLACK, 8);
            work->base.stateTimer = 0;
            work->base.steps--;

            if (work->base.steps <= 0) {
                ClearBtlObjActionFlags(act);
                work->base.state = HUM_STATE_IDLE;
            } else if (GetRandom() & 10) {
                work->base.state = HUM_LAXENE_STATE_WARP_SLASH;
            } else {
                work->base.state = HUM_LAXENE_STATE_WARP_THROW;
            }
        } else {
            work->base.stateTimer++;
        }

        break;
    }

    if (!(act->flags & BTLOBJ_FLAG_HURT) && act->badStatus != BAD_STATUS_STOP) {
        LaxeneHover(&work->base, w->hoverZ);
    }

    TaskPoolUpdate(&w->tasks);

    if ((s16)w->scaleSteps > 0) {
        ApproachValue(&work->base.scaleX, Q_8_8(1), w->scaleSteps);
        ApproachValue(&work->base.scaleY, Q_8_8(1), w->scaleSteps);
        w->scaleSteps--;
    }

    return HumUpdate(&work->base);
}

void task_hum_laxene_2(LaxeneWork* work) {
    HumDraw(&work->base);
    TaskPoolDraw(&work->tasks);
}

void task_hum_laxene_3(LaxeneWork* work) {
    m4aSongNumStop(SONG_EF_RAC_BEEM);
    HumReleaseResources(&work->base);
    TaskPoolDestroy(&work->tasks);
}

enum HumLaxeneKnfState {
    HUM_LAXENE_KNF_STATE_FLY,
    HUM_LAXENE_KNF_STATE_STUCK
};

void task_hum_laxene_knf_0(LaxeneKnfWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gLaxinePalette, sizeof(gLaxinePalette));
    work->tiles = LoadObjTiles(gLaxineKnifeTiles, sizeof(gLaxineKnifeTiles));
    AnimInit(&work->anim, gLaxineKnifeAnims, gLaxineKnifeFrames);
    AnimStart(&work->anim, 0, 0);

    if (args->facingLeft != 0) {
        work->facingLeft = TRUE;
    } else {
        work->facingLeft = FALSE;
    }

    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->timer = 0;
    work->onScreen = TRUE;
    work->state = HUM_LAXENE_KNF_STATE_FLY;
    work->playerPrevX = gBtlWork->actor->x;
    work->playerPrevY = gBtlWork->actor->y;
    work->playerPrevZ = gBtlWork->actor->z;
    work->vx = GetRandom() % 897 + 0x800;
    m4aSongNumStart(SONG_EF_RAC_3TR);
}

u8 task_hum_laxene_knf_1(LaxeneKnfWork* work) {
    BtlObj* player;

    if ((gBtlWork->flags & BTL_FLAG_OPPONENT_CARD_ACTION) == 0) {
        return 0;
    }

    if (!work->onScreen) {
        return 0;
    }

    switch (work->state) {
    case HUM_LAXENE_KNF_STATE_FLY:
        if (ApplyAttackBox(0x133, work->x, work->y, work->z, 1, 6, 2)) {
            m4aSongNumStart(SONG_BTL_RAC_HIT);
            work->timer = 0;
            work->state = HUM_LAXENE_KNF_STATE_STUCK;
            BgFxStartThunderHit(work->x, work->y, work->z + 0x1000);
        } else {
            if (work->facingLeft) {
                work->x = work->x - work->vx;
            } else {
                work->x = work->x + work->vx;
            }

            work->timer++;
        }

        break;
    case HUM_LAXENE_KNF_STATE_STUCK:
        if ((s16)work->timer == 0) {
            AnimStart(&work->anim, 1, 0);
        }

        player = gBtlWork->actor;
        work->x += player->x - work->playerPrevX;
        work->y += player->y - work->playerPrevY;
        work->z += player->z - work->playerPrevZ;

        if ((s16)work->timer > 30) {
            return 0;
        }

        work->timer++;
        break;
    }

    AnimUpdate(&work->anim);
    work->playerPrevX = gBtlWork->actor->x;
    work->playerPrevY = gBtlWork->actor->y;
    work->playerPrevZ = gBtlWork->actor->z;
    return 1;
}

void task_hum_laxene_knf_2(LaxeneKnfWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    gfx = AnimGetGfx(&work->anim);

    if (work->facingLeft) {
        attr = GetBattleSpritePriorityFlags(work->y);
    } else {
        attr = GetBattleSpritePriorityFlags(work->y) | SPRITE_FLAG_HFLIP;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, NULL, attr,
        -0x1004 - (work->y >> 8) * 4);

    if (IsRectOutsideScreen(x, y, 2, 2, 32, 32)) {
        work->onScreen = FALSE;
    }
}

void task_hum_laxene_knf_3(LaxeneKnfWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}
