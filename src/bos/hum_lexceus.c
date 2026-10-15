/**
 * hum_lexceus.c
 * Lexaeus Boss
 */

#include "system_state.h"
#include "obj_api.h"
#include "hum.h"
#include "sprites_btl.h"
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
#include "obj.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "card_label_data.h"
#include "enemy_ids.h"
#include "card_ids.h"

static const u32 sHumLexceusStockMoves[3] = {
    MOVE_BOSS_A, MOVE_BOSS_B, MOVE_BOSS_A,
};

static const AnimDef sHumLexceusAnimDefs[10] = {
    { gRexeusIdlFrames, gRexeusIdlAnims, gRexeusIdlTiles, 0 },
    { gRexeusMovFrames, gRexeusMovAnims, gRexeusMovTiles, 0 },
    { gRexeusDmgFrames, gRexeusDmgAnims, gRexeusDmgTiles, 0 },
    { gRexeusCmb1Frames, gRexeusCmb1Anims, gRexeusCmb1Tiles, 0 },
    { gRexeusCmb2Frames, gRexeusCmb2Anims, gRexeusCmb2Tiles, 1 },
    { gRexeusTmhFrames, gRexeusTmhAnims, gRexeusTmhTiles, 0 },
    { gRexeusTmhFrames, gRexeusTmhAnims, gRexeusTmhTiles, 1 },
    { gRexeusRckFrames, gRexeusRckAnims, gRexeusRckTiles, 0 },
    { gRexeusRckFrames, gRexeusRckAnims, gRexeusRckTiles, 1 },
    { gRexeusImpFrames, gRexeusImpAnims, gRexeusImpTiles, 0 },
};

static const HumDef sHumLexceusDef = { 128, gRexeusPalette, 0, { ENEMY_LEXAEUS, 99, 70, 24, 52, 99, EMY_KIND_FLAG_LARGE_BODY } };

TaskDesc gTaskDescHumLexceus = {
    "task_hum_lexceus",
    (TaskInitFunc)task_hum_lexceus_0,
    (TaskUpdateFunc)task_hum_lexceus_1,
    (TaskDrawFunc)task_hum_lexceus_2,
    (TaskDestroyFunc)task_hum_lexceus_3,
    sizeof(LexceusWork),
};

static TaskDesc sTaskDescHumLexTmh = {
    "task_hum_lex_tmh",
    (TaskInitFunc)task_hum_lex_tmh_0,
    (TaskUpdateFunc)task_hum_lex_tmh_1,
    (TaskDrawFunc)task_hum_lex_tmh_2,
    (TaskDestroyFunc)task_hum_lex_tmh_3,
    sizeof(LexTmhWork),
};

static TaskDesc sTaskDescHumLexTmh0 = {
    "task_hum_lex_tmh0",
    (TaskInitFunc)task_hum_lex_tmh0_0,
    (TaskUpdateFunc)task_hum_lex_tmh0_1,
    (TaskDrawFunc)task_hum_lex_tmh0_2,
    (TaskDestroyFunc)task_hum_lex_tmh0_3,
    sizeof(LexTmh0Work),
};

static TaskDesc sTaskDescHumLexRock = {
    "task_hum_lex_rock",
    (TaskInitFunc)task_hum_lex_rock_0,
    (TaskUpdateFunc)task_hum_lex_rock_1,
    (TaskDrawFunc)task_hum_lex_rock_2,
    (TaskDestroyFunc)task_hum_lex_rock_3,
    sizeof(LexRockWork),
};

void LexceusHover(HumWork* work, s32 hoverZ) {
    BtlObj* act;
    s32 bobZ;

    if (hoverZ != 0) {
        act = &work->actor;
        bobZ = hoverZ + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->vz = 0;
        act->z += (bobZ - act->z) >> 4;
    }
}

void task_hum_lexceus_0(LexceusWork* work) {
    HumInit(&work->base, &sHumLexceusDef);
    work->flags = 0;
    work->hoverZ = 0;
    work->scaleSteps = 0;
    work->tiltSteps = 0;
    work->tilt = 0;
    work->targetTilt = 0;
    work->tiltSlide = 0;
    work->base.stockMoves = sHumLexceusStockMoves;
    TaskPoolInit(&work->tasks, 3);
}

enum HumLexceusState {
    HUM_LEXCEUS_STATE_COMBO = 21,
    HUM_LEXCEUS_STATE_COMBO_FINISH,
    HUM_LEXCEUS_STATE_AXE_THROW,
    HUM_LEXCEUS_STATE_AXE_RECALL,
    HUM_LEXCEUS_STATE_ROCK_RAISE,
    HUM_LEXCEUS_STATE_ROCK_SMASH,
    HUM_LEXCEUS_STATE_QUAKE
};

u8 task_hum_lexceus_1(LexceusWork* work) {
    LexceusWork* w;
    BtlObj* act;
    BtlObj* player;
    VixenNdlArgs args;
    VixenNdlArgs recallArgs;
    s32 x;
    s32 y;
    s32 z;
    s16 dx;
    s16 dy;

    w = work;
    act = &work->base.actor;
    player = gBtlWork->actor;
    GetEnemyTargetPosition(act, &x, &y, &z);

    switch (HumUpdateReaction(&work->base)) {
    case BTL_REACTION_CARD_ACTION:
        work->base.stateTimer = 0;
        work->base.steps = 0;

        switch ((u32)HumResolveCardMove(&work->base)) {
        case MOVE_BOSS_A:
            work->base.state = HUM_LEXCEUS_STATE_COMBO;
            break;
        case MOVE_BOSS_B:
            work->base.state = HUM_LEXCEUS_STATE_AXE_THROW;
            break;
        case MOVE_BOSS_C:
        case MOVE_BOSS_D:
            work->base.state = HUM_LEXCEUS_STATE_QUAKE;
            break;
        case MOVE_ROCKSHATTER_2:
            work->base.state = HUM_LEXCEUS_STATE_ROCK_RAISE;
            break;
        }

        break;
    case BTL_REACTION_CARD_BROKEN:
        work->base.scaleX = work->targetScaleX = Q_8_8(1);
        work->base.scaleY = work->targetScaleY = Q_8_8(1);
        work->scaleSteps = 0;

        if (work->targetTilt != 0) {
            work->targetTilt = 0;
            work->tiltSteps = 420;
        }

        break;
    }

    HumChooseCardAction(&work->base, 3, 40, 40, 20);
    w->hoverZ = 0;

    switch (work->base.state) {
    case HUM_STATE_ENTER:
        AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        break;
    case HUM_STATE_RELOAD:
    case HUM_STATE_USE_ITEM:
        AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        break;
    case HUM_STATE_IDLE:
        AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);

        if (func_08081828()) {
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            if (GetRandom() % 80 == 0) {
                work->base.state = HUM_STATE_MOVE;
                work->base.stateTimer = 0;
                break;
            }
        }

        HumFaceTarget(&work->base, 10);
        work->base.stateTimer++;
        break;
    case HUM_STATE_MOVE:
        AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 1, ANIM_FLAG_LOOP, w->base.tiles);
        w->hoverZ = -0x1000;
        work->base.targetX = x;
        work->base.targetY = y;

        if (AnimIsFinished(&work->base.anim)) {
            if (HumMoveToward(&work->base, work->base.targetX, work->base.targetY, 0x100)) {
                work->base.state = HUM_STATE_IDLE;
                work->base.stateTimer = 0;
                break;
            }
        }

        HumFaceTarget(&work->base, 10);
        work->base.stateTimer++;
        break;
    case HUM_STATE_HURT:
        act->vx = act->vy = 0;
        work->base.vz = 0;

        if (work->base.stateTimer > 5) {
            break;
        }

        work->base.stateTimer = 6;
        act->invincibleTimer = 30;
        break;
    case HUM_STATE_DEFEATED:
    case HUM_STATE_CARD_BROKEN:
    case HUM_STATE_STUNNED:
    case HUM_STATE_GRAVITY:
        AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case HUM_LEXCEUS_STATE_ROCK_RAISE:
        if (work->base.stateTimer == 0) {
            m4aSongNumStart(SONG_SND_286);
            AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 7, 0, w->base.tiles);
            gBtlWork->flags &= ~0x100000;
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 2:
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(SONG_BTL_LEC_ROCKB2);
            }

            break;
        case 3:
            if (work->base.anim.timer == 0) {
                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    args.x = act->x - 0x2000;
                    args.facingLeft = 1;
                } else {
                    args.x = act->x + 0x2000;
                    args.facingLeft = 0;
                }

                args.y = act->y;
                args.z = 0;
                w->task = TaskCreate(&w->tasks, &sTaskDescHumLexRock, &args);
            }

            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = HUM_LEXCEUS_STATE_ROCK_SMASH;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LEXCEUS_STATE_ROCK_SMASH:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 8, 0, w->base.tiles);
            gBtlWork->flags |= 0x100000;
        }

        if (IsTaskActiveNamed(w->task, sTaskDescHumLexRock.name)) {
            break;
        }

        if (!AnimIsFinished(&work->base.anim)) {
            break;
        }

        work->base.stateTimer = 0;
        work->base.state = HUM_STATE_IDLE;
        ClearBtlObjActionFlags(act);
        break;
    case HUM_LEXCEUS_STATE_AXE_THROW:
        if (work->base.stateTimer == 0) {
            w->hoverZ = 0;
            AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 5, 0, w->base.tiles);
            w->flags &= ~LEXCEUS_FLAG_WEAPON_THROWN;
            w->task = NULL;
            m4aSongNumStart(SONG_SND_287);
        }

        if (AnimGetFrame(&work->base.anim) == 3) {
            if (work->base.anim.timer == 2) {
                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    args.x = act->x - 0x1800;
                    args.facingLeft = 1;
                } else {
                    args.x = act->x + 0x1800;
                    args.facingLeft = 0;
                }

                args.y = act->y;
                args.z = act->z - 0x6000;
                w->flags |= LEXCEUS_FLAG_WEAPON_THROWN;
                w->task = TaskCreate(&w->tasks, &sTaskDescHumLexTmh, &args);
            }
        }

        if (w->flags & LEXCEUS_FLAG_WEAPON_THROWN) {
            if (!IsTaskActiveNamed(w->task, sTaskDescHumLexTmh.name)) {
                work->base.stateTimer = 0;
                work->base.state = HUM_LEXCEUS_STATE_AXE_RECALL;
                break;
            }
        }

        work->base.stateTimer++;
        break;
    case HUM_LEXCEUS_STATE_AXE_RECALL:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 6, 0, w->base.tiles);
        }

        if (AnimGetFrame(&work->base.anim) == 2) {
            if (work->base.anim.timer == 10) {
                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    recallArgs.x = act->x - 0x700;
                    recallArgs.facingLeft = 1;
                } else {
                    recallArgs.x = act->x + 0x700;
                    recallArgs.facingLeft = 0;
                }

                recallArgs.y = act->y;
                recallArgs.z = act->z;
                TaskCreate(&w->tasks, &sTaskDescHumLexTmh0, &recallArgs);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
            break;
        }

        work->base.stateTimer++;
        break;
    case HUM_LEXCEUS_STATE_COMBO:
        if (work->base.stateTimer == 0) {
            w->hoverZ = 0;
            AnimReset(&work->base.anim);
            AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 3, 0, w->base.tiles);
            w->flags &= ~(LEXCEUS_FLAG_ATTACK_HIT | LEXCEUS_FLAG_COMBO_FOLLOWUP);

#ifdef VERSION_EU
            if (act->btl->hcEffect == HC_EFFECT_WARP_BREAK) {
                act->btl->hcEffectCount--;
            }
#endif
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 3:
                dx = 9;
                dy = 0;
                break;
            case 4:
                dx = 13;
                dy = 0;
                break;
            case 5:
                dx = 6;
                dy = 6;
                break;
            case 7:
                dx = -21;
                dy = -6;
                break;
            default:
                dx = 0;
                dy = 0;
                break;
            }

            if (!AnimIsFinished(&work->base.anim)) {
                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    act->x = act->x - (dx << 8);
                } else {
                    act->x = act->x + (dx << 8);
                }

                act->y = act->y + (dy << 8);
            }

            if (work->base.anim.timer == 0) {
                if (AnimGetGfxIndex(&work->base.anim) == 5) {
                    MakeOpponentsHittable();

                    if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0x144, act->x - 0x3C00, act->y, act->z, 24, 20, 30)
                        : ApplyAttackBox(0x144, act->x + 0x3C00, act->y, act->z, 24, 20, 30)) {
                        m4aSongNumStart(SONG_BTL_LEC_HIT);
                        w->flags |= LEXCEUS_FLAG_ATTACK_HIT;
                    }
                }
            }
        }

        if (w->flags & LEXCEUS_FLAG_ATTACK_HIT) {
            if (AnimGetFrame(&work->base.anim) == 6) {
                if (work->base.anim.timer == 19) {
                    w->flags |= LEXCEUS_FLAG_COMBO_FOLLOWUP;
                }
            }
        }

        if (w->flags & LEXCEUS_FLAG_COMBO_FOLLOWUP) {
            work->base.stateTimer = 0;
            work->base.state = HUM_LEXCEUS_STATE_COMBO_FINISH;
            work->base.steps++;
        } else if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LEXCEUS_STATE_COMBO_FINISH:
        if (work->base.stateTimer == 0) {
            w->hoverZ = 0;
            AnimReset(&work->base.anim);
            AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 4, 0, w->base.tiles);
            w->flags &= ~LEXCEUS_FLAG_ATTACK_HIT;

#ifdef VERSION_EU
            if (act->btl->hcEffect == HC_EFFECT_WARP_BREAK) {
                act->btl->hcEffectCount--;
            }
#endif
        }

        if (work->base.anim.timer == 0) {
            if (AnimGetGfxIndex(&work->base.anim) == 1) {
                MakeOpponentsHittable();

                if (act->btl->hcEffect == HC_EFFECT_WARP_BREAK) {
                    if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0x149, act->x - 0x2800, act->y, act->z, 24, 20, 55)
                        : ApplyAttackBox(0x149, act->x + 0x2800, act->y, act->z, 24, 20, 55)) {
                        m4aSongNumStart(SONG_BTL_LEC_HIT);
                        w->flags |= LEXCEUS_FLAG_ATTACK_HIT;
                    }
                } else {
                    if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0x145, act->x - 0x2800, act->y, act->z, 24, 20, 55)
                        : ApplyAttackBox(0x145, act->x + 0x2800, act->y, act->z, 24, 20, 55)) {
                        m4aSongNumStart(SONG_BTL_LEC_HIT);
                        w->flags |= LEXCEUS_FLAG_ATTACK_HIT;
                    }
                }
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x = act->x - 0x1900;
            } else {
                act->x = act->x + 0x1900;
            }

            AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
            work->base.stateTimer = 0;
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_LEXCEUS_STATE_QUAKE:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumLexceusAnimDefs, &w->base.anim, 9, 0, w->base.tiles);
            w->hoverZ = 0;
            w->cameraBaseY = gBtlWork->y;
        }

        if (AnimGetFrame(&work->base.anim) == 3) {
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(SONG_SND_288);
            }
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            HumFaceTarget(&work->base, 1);
            break;
        case 5:
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(SONG_EF_AIRO);

                if ((act->flags & BTLOBJ_FLAG_FACING_LEFT) == 0) {
                    w->targetTilt = -0x800;
                } else {
                    w->targetTilt = 0x800;
                }

                w->tiltSteps = 10;

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    BgFxStartLexceusGround(act->x - 0x3000, act->y + 0xE00, 0, 0x147);
                } else {
                    BgFxStartLexceusGround(act->x + 0x3000, act->y + 0xE00, 0, 0x147);
                }
            }

            if (work->base.stateTimer % 6 <= 2) {
                gBtlWork->y2 = w->cameraBaseY - 0x4000;
            } else {
                gBtlWork->y2 = w->cameraBaseY + 0x4000;
            }

            break;
        case 6:
            if (work->base.stateTimer % 6 <= 2) {
                gBtlWork->y2 = w->cameraBaseY - 0x3000;
            } else {
                gBtlWork->y2 = w->cameraBaseY + 0x3000;
            }

            break;
        case 7:
            if (work->base.stateTimer % 6 <= 2) {
                gBtlWork->y2 = w->cameraBaseY - 0x2000;
            } else {
                gBtlWork->y2 = w->cameraBaseY + 0x2000;
            }

            break;
        case 8:
            if (work->base.stateTimer % 6 <= 2) {
                gBtlWork->y2 = w->cameraBaseY - 0x1000;
            } else {
                gBtlWork->y2 = w->cameraBaseY + 0x1000;
            }

            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
            w->targetTilt = 0;
            w->tiltSteps = 420;
        } else {
            work->base.stateTimer++;
        }

        break;
    }

    if (!(act->flags & BTLOBJ_FLAG_HURT)) {
        if (act->badStatus != BAD_STATUS_STOP) {
            LexceusHover(&work->base, w->hoverZ);
        }
    }

    if ((s16)w->tiltSteps > 0) {
        ApproachValue(&w->tilt, w->targetTilt, w->tiltSteps);
        w->tiltSteps--;
    }

    gBtlWork->rotation = w->tilt >> 8;

    if (player->z >= player->groundZ && player->hp > 0 && player->badStatus != BAD_STATUS_STOP && !(player->flags & BTLOBJ_FLAG_IN_CARD_ACTION)) {
        w->tiltSlide += (GetAngleDiff(0, gBtlWork->rotation) * 64 - w->tiltSlide) >> 4;
        player->x -= w->tiltSlide;
    } else {
        w->tiltSlide = 0;
    }

    TaskPoolUpdate(&w->tasks);
    return HumUpdate(&work->base);
}

void task_hum_lexceus_2(LexceusWork* work) {
    HumDraw(&work->base);

    if (work->scaleSteps > 0) {
        ApproachValue(&work->base.scaleX, work->targetScaleX, work->scaleSteps);
        ApproachValue(&work->base.scaleY, work->targetScaleY, work->scaleSteps);
        work->scaleSteps--;
    }

    TaskPoolDraw(&work->tasks);
}

void task_hum_lexceus_3(LexceusWork* work) {
    HumReleaseResources(&work->base);
    TaskPoolDestroy(&work->tasks);
}

enum HumLexTmhState {
    HUM_LEX_TMH_STATE_FLY,
    HUM_LEX_TMH_STATE_BOUNCE
};

void task_hum_lex_tmh_0(LexTmhWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gRexeusPalette, sizeof(gRexeusPalette));
    work->tiles = AllocObjTiles(0x400, gRexeusTmhAxTiles);
    AnimInit(&work->anim, gRexeusTmhAxAnims, gRexeusTmhAxFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);

    if (args->facingLeft != 0) {
        work->facingLeft = TRUE;
    } else {
        work->facingLeft = FALSE;
    }

    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->targetX = gBtlWork->targetX + (GetRandom() % 65 - 32) * 256;
    work->targetY = gBtlWork->targetY + (GetRandom() % 33 - 16) * 256;
    work->state = HUM_LEX_TMH_STATE_FLY;
    work->timer = 0;
    work->done = FALSE;
    work->vz = -0x980;
    work->tiles2 = LoadObjTiles(gBtlShadowTiles, sizeof(gBtlShadowTiles));
    work->palette2 = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
    m4aSongNumStart(SONG_BTL_LEC_THRSW);
}

u8 task_hum_lex_tmh_1(LexTmhWork* work) {
    if ((gBtlWork->flags & BTL_FLAG_OPPONENT_CARD_ACTION) == 0) {
        return 0;
    }

    if (work->done) {
        return 0;
    }

    switch (work->state) {
    case HUM_LEX_TMH_STATE_FLY:
        work->x += (work->targetX - work->x) >> 4;
        work->y += (work->targetY - work->y) >> 4;
        work->z += work->vz;
        work->vz += 64;

        if (ApplyAttackBox(0x146, work->x, work->y, work->z, 16, 12, 16)) {
            m4aSongNumStart(SONG_BTL_LEC_THRHIT);
            work->timer = 0;
            work->state = HUM_LEX_TMH_STATE_BOUNCE;
        } else if (work->z >= 0) {
            m4aSongNumStart(SONG_BTL_LEC_THR);
            work->timer = 0;
            work->state = HUM_LEX_TMH_STATE_BOUNCE;
        } else {
            work->timer++;
        }

        break;
    case HUM_LEX_TMH_STATE_BOUNCE:
        if (work->timer == 0) {
            work->vz = -work->vz >> 1;

            if (gBtlWork->targetX < work->x) {
                work->flyLeft = TRUE;
            } else {
                work->flyLeft = FALSE;
            }
        }

        if (work->x < (gBtlWork->xMin - 32) << 8 ||
            work->x > (gBtlWork->xMax + 32) << 8) {
            work->done = TRUE;
        }

        if (work->flyLeft) {
            work->x += -0x400;
        } else {
            work->x += 0x400;
        }

        work->y += (gBtlWork->targetY - work->y) >> 4;
        work->z += work->vz;
        work->vz += 64;

        if (ApplyAttackBox(0x146, work->x, work->y, work->z, 16, 12, 16)) {
            m4aSongNumStart(SONG_BTL_LEC_THRHIT);
        }

        if (work->z >= 0) {
            m4aSongNumStart(SONG_BTL_LEC_THR);
            work->vz = -work->vz >> 1;
            work->z = 0;
        }

        work->timer++;
        break;
    }

    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_lex_tmh_2(LexTmhWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;
    ObjAffine* affine;
    s32 scale;

    gfx = AnimGetGfx(&work->anim);

    if (work->facingLeft) {
        attr = GetBattleSpritePriorityFlags(work->y);
    } else {
        attr = GetBattleSpritePriorityFlags(work->y) | SPRITE_FLAG_HFLIP;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, NULL, attr,
        -0x1004 - (work->y >> 8) * 4);

    if (work->z >= 0) {
        affine = NULL;
    } else {
        scale = Q_8_8(1) - (-work->z) / 256;

        if (scale <= 75) {
            scale = Q_8_8(0.3);
        }

        affine = AllocObjAffine(0, scale, scale, FALSE);
    }

    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, gBtlShadowFrame0, work->tiles2, work->palette2, affine, attr, 0xFFF0);
}

void task_hum_lex_tmh_3(LexTmhWork* work) {
    ReleaseObjTiles(work->tiles2);
    ReleaseObjPalette(work->palette2);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_hum_lex_tmh0_0(LexTmh0Work* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gRexeusPalette, sizeof(gRexeusPalette));
    work->tiles = AllocObjTiles(0x400, gRexeusTmhTiles);
    AnimInit(&work->anim, gRexeusTmhAnims, gRexeusTmhFrames);
    AnimStart(&work->anim, 2, ANIM_FLAG_LOOP);

    if (args->facingLeft != 0) {
        work->facingLeft = TRUE;
    } else {
        work->facingLeft = FALSE;
    }

    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->scale = 10;
    work->steps = 21;
    m4aSongNumStart(SONG_BTL_LEC_WEPUP);
}

u8 task_hum_lex_tmh0_1(LexTmh0Work* work) {
    if (gBtlWork->flags & BTL_FLAG_OPPONENT_CARD_ACTION) {
        ApproachValue(&work->scale, Q_8_8(1), work->steps--);

        if (work->steps > 0) {
            AnimUpdate(&work->anim);
            return 1;
        }
    }

    return 0;
}

void task_hum_lex_tmh0_2(LexTmh0Work* work) {
    void* gfx;
    u16 attr;
    s32 sx;
    s32 scale;
    ObjAffine* affine;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(&work->anim);
    attr = GetBattleSpritePriorityFlags(work->y);
    scale = work->scale;

    if (scale == Q_8_8(1)) {
        if (!work->facingLeft) {
            attr |= SPRITE_FLAG_HFLIP;
        }

        sx = scale;
    } else {
        if (work->facingLeft) {
            sx = scale;
        } else {
            sx = -scale;
        }
    }

    affine = AllocObjAffine(0, sx, Q_8_8(1), FALSE);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, affine, attr,
        -0x100C - (work->y >> 8) * 4);
}

void task_hum_lex_tmh0_3(LexTmh0Work* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

enum HumLexRockState {
    HUM_LEX_ROCK_STATE_EMERGE,
    HUM_LEX_ROCK_STATE_EMERGE_WAIT,
    HUM_LEX_ROCK_STATE_LIFT,
    HUM_LEX_ROCK_STATE_HOLD,
    HUM_LEX_ROCK_STATE_SMASH_WAIT,
    HUM_LEX_ROCK_STATE_SHATTER,
    HUM_LEX_ROCK_STATE_SCATTER
};

void task_hum_lex_rock_0(LexRockWork* work, VixenNdlArgs* args) {
    if (args->facingLeft != 0) {
        work->facingLeft = TRUE;
    } else {
        work->facingLeft = FALSE;
    }

    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->state = HUM_LEX_ROCK_STATE_EMERGE;
    work->rockCount = 0;
    work->tiles = LoadObjTiles(gBtlShadowSmallTiles, sizeof(gBtlShadowSmallTiles));
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
    work->blinking = FALSE;
}

u8 task_hum_lex_rock_1(LexRockWork* work) {
    s32 i;
    s32 range;
    LexRockSub* piece;
    u32 edge;

    if ((gBtlWork->flags & BTL_FLAG_OPPONENT_CARD_ACTION) == 0) {
        return 0;
    }

    switch (work->state) {
    case HUM_LEX_ROCK_STATE_EMERGE:
        work->rockCount = 1;
        work->palette2 = LoadObjPalette(gRexeusRock01Palette, sizeof(gRexeusRock01Palette));
        work->tiles2[0] = AllocObjTiles(0xDC0, gRexeusRock01Tiles);
        AnimInit(&work->anim[0], gRexeusRock01Anims, gRexeusRock01Frames);
        AnimStart(&work->anim[0], 0, 0);
        work->state++;
        break;
    case HUM_LEX_ROCK_STATE_EMERGE_WAIT:
        if (!AnimIsFinished(&work->anim[0])) {
            break;
        }

        work->state++;
        break;
    case HUM_LEX_ROCK_STATE_LIFT:
        ReleaseObjTiles(work->tiles2[0]);
        ReleaseObjPalette(work->palette2);
        work->rockCount = 1;
        work->palette2 = LoadObjPalette(gRexeusRock02Palette, sizeof(gRexeusRock02Palette));
        work->tiles2[0] = AllocObjTiles(0xDC0, gRexeusRock02Tiles);
        AnimInit(&work->anim[0], gRexeusRock02Anims, gRexeusRock02Frames);
        AnimStart(&work->anim[0], 0, 0);
        work->z -= 0x4000;
        work->state++;
        break;
    case HUM_LEX_ROCK_STATE_HOLD:
        if (gBtlWork->flags & 0x100000) {
            m4aSongNumStart(SONG_BTL_LEC_JMPKUEIKU);
            work->state += 2;
        }

        break;
    case HUM_LEX_ROCK_STATE_SMASH_WAIT:
        if (!AnimIsFinished(&work->anim[0])) {
            break;
        }

        work->state++;
        break;
    case HUM_LEX_ROCK_STATE_SHATTER:
        work->rockCount = 12;
        ReleaseObjTiles(work->tiles2[0]);

        for (i = 0; i < 12; i++) {
            piece = &work->sub[i];
            work->tiles2[i] = AllocObjTiles(0xC0, gRexeusRock02Tiles);
            AnimInit(&work->anim[i], gRexeusRock02Anims, gRexeusRock02Frames);
            AnimStart(&work->anim[i], GetRandom() % 5 + 2, ANIM_FLAG_LOOP | ANIM_FLAG_RANDOM_START);

            if (work->facingLeft) {
                piece->vx = -(GetRandom() % 0x501 + 0x300);
            } else {
                piece->vx = GetRandom() % 0x501 + 0x300;
            }

            piece->vy = GetRandom() % 0x801 - 0x400;
            piece->x = work->x + ((GetRandom() % 17 - 8) << 8);
            piece->y = work->y + ((GetRandom() % 17 - 8) << 8);
            piece->z = work->z + ((GetRandom() % 17 - 8) << 8);
            piece->hasHit = FALSE;

            if (GetRandom() % 2) {
                piece->vz = -(GetRandom() % 0x701 + 0x100);
            } else {
                piece->vz = GetRandom() % 1 + 0x300;
            }
        }

        work->state++;
        work->timer = 0;
        break;
    case HUM_LEX_ROCK_STATE_SCATTER:
        if (!work->blinking) {
            MakeOpponentsHittable();

            for (i = 0; i < 12; i++) {
                piece = &work->sub[i];
                piece->x += piece->vx;
                piece->y += piece->vy;
                piece->z += piece->vz;
                piece->vz += 64;

                if (piece->z > 0) {
                    piece->z = 0;
                    piece->vz = -(piece->vz >> 1);
                }

                edge = ClampBattlePosition(&piece->x, &piece->y, 0, 0);

                switch (edge) {
                case BATTLE_EDGE_TOP:
                case BATTLE_EDGE_BOTTOM:
                    piece->vy = -piece->vy;
                    break;
                case BATTLE_EDGE_LEFT:
                case BATTLE_EDGE_RIGHT:
                    piece->vx = -piece->vx;
                    break;
                }

                if (!piece->hasHit) {
                    if (ApplyAttackBox(0x148, piece->x, piece->y, piece->z, 4, 4, 4)) {
                        m4aSongNumStart(SONG_BTL_MON_HIT02);
                        piece->hasHit = TRUE;
                    }
                }
            }
        }

        if (work->timer == 80) {
            work->blinking = TRUE;
        }

        if (work->timer > 100) {
            return 0;
        }

        work->timer++;
        break;
    }

    for (i = 0; i < work->rockCount; i++) {
        AnimUpdate(&work->anim[i]);
    }

    return 1;
}

void task_hum_lex_rock_2(LexRockWork* work) {
    void* gfx;
    u16 attr;
    s16 x;
    s16 y;
    s32 i;
    LexRockSub* piece;

    if (work->blinking && (work->timer & 1)) {
        return;
    }

    if (work->rockCount == 1) {
        gfx = AnimGetGfx(&work->anim[0]);

        if (work->facingLeft) {
            attr = GetBattleSpritePriorityFlags(work->y);
        } else {
            attr = GetBattleSpritePriorityFlags(work->y) | SPRITE_FLAG_HFLIP;
        }

        WorldToScreen(&x, &y, work->x, work->y, work->z);
        DrawSprite(x, y, gfx, work->tiles2[0], work->palette2, NULL, attr,
            -0x1006 - (work->y >> 8) * 4);
    } else if (work->rockCount == 12) {
        for (i = 0; i < work->rockCount; i++) {
            piece = &work->sub[i];
            gfx = AnimGetGfx(&work->anim[i]);

            if (work->facingLeft) {
                attr = GetBattleSpritePriorityFlags(piece->y);
            } else {
                attr = GetBattleSpritePriorityFlags(piece->y) | SPRITE_FLAG_HFLIP;
            }

            WorldToScreen(&x, &y, piece->x, piece->y,
                piece->z);
            DrawSprite(x, y, gfx, work->tiles2[i], work->palette2, NULL, attr,
                -0x1006 - (piece->y >> 8) * 4);
            WorldToScreen(&x, &y, piece->x, piece->y, 0);
            DrawSprite(x, y, gBtlShadowSmallFrame0, work->tiles, work->palette, NULL, attr, 0xFFFE);
        }
    }
}

void task_hum_lex_rock_3(LexRockWork* work) {
    s32 i;

    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);

    if (work->rockCount != 0) {
        ReleaseObjPalette(work->palette2);

        for (i = 0; i < work->rockCount; i++) {
            ReleaseObjTiles(work->tiles2[i]);
        }
    }
}
