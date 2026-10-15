/**
 * hum_cloud.c
 * Cloud Boss
 */

#include "system_state.h"
#include "fade.h"
#include "hum.h"
#include "sprites_cloud.h"
#include "sprites_hum.h"
#include "hum_common.h"
#include "songs.h"
#include "hum_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_collision.h"
#include "card_api.h"
#include "engine_math.h"
#include "hum_types.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "enemy_ids.h"
#include "card_ids.h"

static const u32 sHumCloudStockMoves[2][3] = {
    { MOVE_BOSS_B, MOVE_BOSS_B, MOVE_BOSS_B },
    { MOVE_BOSS_B, MOVE_BOSS_A, MOVE_BOSS_B },
};

static const AnimDef sHumCloudAnimDefs[20] = {
    { gCroudBt00Frames, gCroudBt00Anims, gCroudBt00Tiles, 0 },
    { gCroudBt01Frames, gCroudBt01Anims, gCroudBt01Tiles, 0 },
    { gCroudBt02Frames, gCroudBt02Anims, gCroudBt02Tiles, 0 },
    { gCroudBt03Frames, gCroudBt03Anims, gCroudBt03Tiles, 0 },
    { gCroudBt03Frames, gCroudBt03Anims, gCroudBt03Tiles, 1 },
    { gCroudBt03Frames, gCroudBt03Anims, gCroudBt03Tiles, 2 },
    { gCroudBt03Frames, gCroudBt03Anims, gCroudBt03Tiles, 3 },
    { gCroudBt03Frames, gCroudBt03Anims, gCroudBt03Tiles, 4 },
    { gCroud01Frames, gCroud01Anims, gCroud01Tiles, 2 },
    { gCroud01Frames, gCroud01Anims, gCroud01Tiles, 2 },
    { gCroud00Frames, gCroud00Anims, gCroud00Tiles, 0 },
    { gCroud00Frames, gCroud00Anims, gCroud00Tiles, 1 },
    { gCroud00Frames, gCroud00Anims, gCroud00Tiles, 2 },
    { gCroud00Frames, gCroud00Anims, gCroud00Tiles, 3 },
    { gCroud10Frames, gCroud10Anims, gCroud10Tiles, 0 },
    { gCroud11Frames, gCroud11Anims, gCroud11Tiles, 0 },
    { gCroud12Frames, gCroud12Anims, gCroud12Tiles, 0 },
    { gCroud13Frames, gCroud13Anims, gCroud13Tiles, 0 },
    { gCroud01Frames, gCroud01Anims, gCroud01Tiles, 0 },
    { gCroud02Frames, gCroud02Anims, gCroud02Tiles, 0 },
};

static const HumDef sHumCloudDef = { 128, gCroudPalette, 0, { ENEMY_CLOUD, 99, 38, 14, 24, 99, 0 } };

TaskDesc gTaskDescHumCloud = {
    "task_hum_cloud",
    (TaskInitFunc)task_hum_cloud_0,
    (TaskUpdateFunc)task_hum_cloud_1,
    (TaskDrawFunc)task_hum_cloud_2,
    (TaskDestroyFunc)task_hum_cloud_3,
    sizeof(CloudWork),
};

enum HumCloudState {
    HUM_CLOUD_STATE_SLASH_LONG = 19,
    HUM_CLOUD_STATE_SLASH_SHORT,
    HUM_CLOUD_STATE_AIR_FOLLOW,
    HUM_CLOUD_STATE_AIR_HANG,
    HUM_CLOUD_STATE_DIVE,
    HUM_CLOUD_STATE_LANDING_SLASH,
    HUM_CLOUD_STATE_JUMP_CROUCH,
    HUM_CLOUD_STATE_JUMP_AIR,
    HUM_CLOUD_STATE_JUMP_LAND,
    HUM_CLOUD_STATE_OMNISLASH_RISE,
    HUM_CLOUD_STATE_OMNISLASH_FLY,
    HUM_CLOUD_STATE_OMNISLASH_STRIKE,
    HUM_CLOUD_STATE_CROSS_SLASH_START,
    HUM_CLOUD_STATE_CROSS_SLASH,
    HUM_CLOUD_STATE_LEAP_RISE,
    HUM_CLOUD_STATE_LEAP_FLY
};

void CloudJumpOffset(CloudWork* work, s16 distance, s32 speed) {
    CloudWork* w = work;
    BtlObj* obj = &work->base.actor;

    if (obj->flags & BTLOBJ_FLAG_FACING_LEFT) {
        work->base.targetX = obj->x - (distance << 8);
    } else {
        work->base.targetX = obj->x + (distance << 8);
    }

    w->base.targetY = obj->y;
    w->base.state = HUM_CLOUD_STATE_JUMP_CROUCH;
    w->base.stateTimer = 0;
    work->speed = -speed;
    work->state = 0;
}

void CloudJumpTo(CloudWork* work, s32 x, s32 y) {
    work->base.targetX = x;
    work->base.targetY = y;
    work->base.state = HUM_CLOUD_STATE_JUMP_CROUCH;
    work->base.stateTimer = 0;
    work->speed = -0x500;
    work->nextState = HUM_STATE_IDLE;
}

void CloudLeapTo(CloudWork* work, s32 x, s32 y) {
    work->base.targetX = x;
    work->base.targetY = y;
    work->base.state = HUM_CLOUD_STATE_LEAP_RISE;
    work->base.stateTimer = 0;
}

s32 CloudTryJumpAway(CloudWork* work) {
    s32 x;
    s32 y;
    BtlObj* player;

    player = gBtlWork->actor;

    if (GetRandom() % 60 == 0) {
        GetEnemyTargetPosition(&work->base.actor, &x, &y, NULL);
        HumFaceTarget(&work->base, 1);

        if (HumIsInPlayerReach(&work->base, 0x100, 0x100, 0x100)) {
            if (gBtlWork->flags & BTL_FLAG_PLAYER_AIRBORNE) {
                CloudJumpOffset(work, -0x63, 0x280);
            } else if (GetRandom() & 1) {
                if (player->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    CloudJumpTo(work, x + 0x2800, y);
                } else {
                    CloudJumpTo(work, x - 0x2800, y);
                }
            } else {
                CloudJumpOffset(work, -0x50, 0x500);
            }

            return TRUE;
        }
    }

    return FALSE;
}

void task_hum_cloud_0(CloudWork* work, void* obj) {
    HumInit(&work->base, &sHumCloudDef);
    work->speed = 0;
    work->base.stockMoves = sHumCloudStockMoves[0];
}

enum HumCloudAttackPhase {
    HUM_CLOUD_ATTACK_PHASE_OPENER,
    HUM_CLOUD_ATTACK_PHASE_FINISHER
};

u8 task_hum_cloud_1(CloudWork* work) {
    CloudWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 z;
    u8 arrived;

    w = work;
    act = &work->base.actor;
    GetEnemyTargetPosition(act, &x, &y, &z);

    switch (HumUpdateReaction(&work->base)) {
    case BTL_REACTION_CARD_ACTION:
        work->base.stateTimer = 0;

        switch ((u32)HumResolveCardMove(&work->base)) {
        case MOVE_BOSS_A:
        case MOVE_BOSS_C:
            if (act->z < 0) {
                work->base.state = HUM_CLOUD_STATE_AIR_FOLLOW;
            } else {
                work->base.state = HUM_CLOUD_STATE_SLASH_LONG;
            }

            break;
        case MOVE_BOSS_B:
        case MOVE_BOSS_D:
            if (act->z < 0) {
                work->base.state = HUM_CLOUD_STATE_AIR_FOLLOW;
            } else {
                work->base.state = HUM_CLOUD_STATE_SLASH_SHORT;
            }

            break;
        case MOVE_CROSS_SLASH_2:
            work->base.state = HUM_CLOUD_STATE_CROSS_SLASH_START;
            break;
        case MOVE_OMNISLASH_2:
            work->base.state = HUM_CLOUD_STATE_OMNISLASH_RISE;
            break;
        }

        break;
    case BTL_REACTION_CARD_BROKEN:
        work->nextState = HUM_STATE_IDLE;
        break;
    }

    if (HumChooseCardAction(&work->base, 8, 32, 32, 24)) {
        if (GetRandom() % 2) {
            work->base.stockMoves = sHumCloudStockMoves[0];
        } else {
            work->base.stockMoves = sHumCloudStockMoves[1];
        }
    }

    switch (work->base.state) {
    case HUM_STATE_ENTER:
    case HUM_STATE_USE_ITEM:
        AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP, w->base.tiles);
        break;
    case HUM_STATE_RELOAD: {
        AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP | ANIM_FLAG_RANDOM_START, w->base.tiles);

        if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
            if ((u8)CloudTryJumpAway(w)) {
                break;
            }
        }

        if ((act->x - x >= 0) ? act->x - x <= 0x4FFF : x - act->x <= 0x4FFF) {
            if (x <= 0xFFFF) {
                CloudLeapTo(w, (gBtlWork->xMax - 40) << 8,
                    (gBtlWork->yMin + gBtlWork->yMax) << 7);
            } else {
                CloudLeapTo(w, (gBtlWork->xMin + 40) << 8,
                    (gBtlWork->yMin + gBtlWork->yMax) << 7);
            }
        }

        break;
    }
    case HUM_STATE_IDLE:
        AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 0, ANIM_FLAG_LOOP | ANIM_FLAG_RANDOM_START, w->base.tiles);

        if (func_08081828()) {
            break;
        }

        if ((u16)(GetRandom() % 60) == 0) {
            work->base.state = HUM_STATE_MOVE;
            work->base.stateTimer = 0;
            break;
        }

        if (HumIsNearAreaEdge(&work->base, 40)) {
            CloudLeapTo(w, 0x10000,
                (gBtlWork->yMin + gBtlWork->yMax) << 7);
            break;
        }

        if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
            if ((u8)CloudTryJumpAway(w)) {
                break;
            }
        } else {
            HumFaceTarget(&work->base, 30);
        }

        work->base.stateTimer++;
        break;
    case HUM_STATE_MOVE: {
        AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 1, ANIM_FLAG_LOOP | ANIM_FLAG_RANDOM_START, w->base.tiles);
        work->base.targetX = x;
        work->base.targetY = y;

        if (HumMoveToward(&work->base, work->base.targetX, y, 0x133)) {
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
            break;
        }

        if ((u16)(GetRandom() % 150) == 0) {
            if ((act->x - x >= 0) ? act->x - x > 70 : x - act->x > 70) {
                CloudJumpTo(w, x, y);
                break;
            }
        }

        if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
            if ((u8)CloudTryJumpAway(w)) {
                break;
            }
        } else {
            HumFaceTarget(&work->base, 30);
        }

        work->base.stateTimer++;
        break;
    }
    case HUM_STATE_HURT:
    case HUM_STATE_DEFEATED:
    case HUM_STATE_CARD_BROKEN:
    case HUM_STATE_STUNNED:
    case HUM_STATE_GRAVITY:
        AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case HUM_CLOUD_STATE_SLASH_LONG:
        if (work->base.stateTimer == 0) {
            AnimReset(&work->base.anim);
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 8, 0, w->base.tiles);
            m4aSongNumStart(SONG_VO_MKU_ATTACK00);
            MakeOpponentsHittable();
        }

        if (AnimGetFrame(&work->base.anim) == 6) {
            if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                ? ApplyAttackBox(0x11A, act->x - 9216, act->y, act->z, 24, 16, 50)
                : ApplyAttackBox(0x11A, act->x + 9216, act->y, act->z, 24, 16, 50)) {
                m4aSongNumStart(SONG_EF_KU_ATT00);
            }
        } else if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
            break;
        }

        work->base.stateTimer++;
        break;
    case HUM_CLOUD_STATE_SLASH_SHORT:
        if (work->base.stateTimer == 0) {
            AnimReset(&work->base.anim);
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 9, 0, w->base.tiles);
            m4aSongNumStart(SONG_VO_MKU_ATTACK01);
            MakeOpponentsHittable();
        }

        if (AnimGetFrame(&work->base.anim) == 6) {
            if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                ? ApplyAttackBox(0x11A, act->x - 8192, act->y, act->z, 22, 16, 50)
                : ApplyAttackBox(0x11A, act->x + 8192, act->y, act->z, 22, 16, 50)) {
                m4aSongNumStart(SONG_EF_KU_ATT01);
            }
        } else if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
            break;
        }

        work->base.stateTimer++;
        break;
    case HUM_CLOUD_STATE_JUMP_CROUCH:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 3, 0, w->base.tiles);
        }

        if (work->base.stateTimer > 3) {
            work->base.stateTimer = 0;
            work->base.state = HUM_CLOUD_STATE_JUMP_AIR;
            work->base.vz = w->speed;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_CLOUD_STATE_JUMP_AIR: {
        s32 vz;

        act->x += (work->base.targetX - act->x) >> 4;
        act->y += (work->base.targetY - act->y) >> 4;
        vz = work->base.vz;

        if (vz < 0) {
            if (vz <= -0x200) {
                AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 4, 0, w->base.tiles);
            } else {
                AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 5, 0, w->base.tiles);
            }
        } else if (vz <= 0x1FF) {
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 5, 0, w->base.tiles);
        } else {
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 6, 0, w->base.tiles);
        }

        if (act->z >= 0) {
            work->base.stateTimer = 0;
            work->base.state = HUM_CLOUD_STATE_JUMP_LAND;
        } else {
            HumFaceTarget(&work->base, 1);
            work->base.stateTimer++;
        }

        break;
    }
    case HUM_CLOUD_STATE_JUMP_LAND:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 7, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = w->nextState;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_CLOUD_STATE_LEAP_RISE: {
        s32 vz;

        if (work->base.stateTimer == 0) {
            work->base.vz = -0x500;
        }

        vz = work->base.vz;

        if (vz < 0) {
            if (vz > -0x200) {
                AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 5, 0, w->base.tiles);
            } else {
                AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 4, 0, w->base.tiles);
            }
        }

        if (work->base.vz > 0) {
            work->base.stateTimer = 0;
            work->base.state = HUM_CLOUD_STATE_LEAP_FLY;
        } else {
            work->base.stateTimer++;
        }

        break;
    }
    case HUM_CLOUD_STATE_LEAP_FLY: {
        s32 dist;

        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 14, 0, w->base.tiles);
            w->speed = 0;
            work->base.targetZ = act->z;
        }

        arrived = HumMoveToward(&work->base, work->base.targetX, work->base.targetY, w->speed);

        if (arrived) {
            work->base.state = HUM_CLOUD_STATE_JUMP_AIR;
            w->nextState = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            w->speed += 76;

            if ((s32)w->speed > 0x800) {
                w->speed = 0x800;
            }

            dist = (work->base.targetX - act->x) >> 3;

            if (dist < 0) {
                dist = -dist;
            }

            if (dist < (s32)w->speed) {
                w->speed = dist;
            }

            {
                s32 bobZ = work->base.targetZ + SIN(gFrameCounter * 4) * 12;
            work->base.vz = 0;
            act->z += (bobZ - act->z) >> 3;
            }

            if (act->x < work->base.targetX) {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            } else {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            }

            work->base.stateTimer++;
        }

        break;
    }
    case HUM_CLOUD_STATE_AIR_FOLLOW: {
        s32 lowZ;

        if (work->base.stateTimer == 0) {
            AnimReset(&work->base.anim);
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 10, 0, w->base.tiles);
        }

        act->z += (gSineTable[gFrameCounter % 256] * 10 - (lowZ = act->z + 0x2C00)) >> 3;

        if (act->x < x) {
            s32 frontX = act->x + 0x2100;
            act->x += (x - frontX) >> 3;
        } else {
            s32 frontX = act->x - 0x2100;
            act->x += (x - frontX) >> 3;
        }

        act->y += (y - act->y) >> 4;
        work->base.vz = 0;

        if (work->base.stateTimer > 30) {
            work->base.state = HUM_CLOUD_STATE_AIR_HANG;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    }
    case HUM_CLOUD_STATE_AIR_HANG:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 11, 0, w->base.tiles);
        }

        work->base.vz = 0;

        if (work->base.stateTimer > 8) {
            work->base.vz = 0x500;
            work->base.state = HUM_CLOUD_STATE_DIVE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_CLOUD_STATE_DIVE:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 12, 0, w->base.tiles);
        }

        if (act->z >= 0) {
            work->base.state = HUM_CLOUD_STATE_LANDING_SLASH;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_CLOUD_STATE_LANDING_SLASH:
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 13, 0, w->base.tiles);
        }

        if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
            ? ApplyAttackBox(0x11A, act->x - 0x2000, act->y, act->z, 22, 16, 30)
            : ApplyAttackBox(0x11A, act->x + 0x2000, act->y, act->z, 22, 16, 30)) {
            m4aSongNumStart(SONG_EF_KU_ATT02);
        }

        if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    case HUM_CLOUD_STATE_CROSS_SLASH_START:
        if (act->z >= act->groundZ) {
            s32 offset;
            work->base.targetX = x + (offset = ((u16)(GetRandom() % 41) << 8) - 0x1400);
            work->base.targetY = y;
            work->base.state = HUM_CLOUD_STATE_JUMP_CROUCH;
            work->base.stateTimer = 0;
            w->speed = -0x500;
            w->nextState = HUM_CLOUD_STATE_CROSS_SLASH;
        }

        break;
    case HUM_CLOUD_STATE_CROSS_SLASH: {
        s32 focusZ;

        if (work->base.stateTimer == 0) {
            w->attackPhase = HUM_CLOUD_ATTACK_PHASE_OPENER;
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 18, 0, w->base.tiles);
        } else if ((s16)w->attackPhase == HUM_CLOUD_ATTACK_PHASE_OPENER && AnimIsFinished(&work->base.anim)) {
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 19, 0, w->base.tiles);
            w->attackPhase++;
        } else if (AnimIsFinished(&work->base.anim)) {
            ClearBtlObjActionFlags(act);
            work->base.state = HUM_STATE_IDLE;
            w->nextState = HUM_STATE_IDLE;
            work->base.stateTimer = 0;
            break;
        }

        HumFaceTarget(&work->base, 1);

        if (work->base.anim.timer == 0) {
            if ((s16)w->attackPhase == HUM_CLOUD_ATTACK_PHASE_OPENER) {
                switch (AnimGetFrame(&work->base.anim)) {
                case 2:
                    m4aSongNumStart(SONG_VO_MKU_ATTACK00);
                    break;
                case 6:
                    if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0x11B, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : ApplyAttackBox(0x11B, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(SONG_EF_KU_ATT00);
                        FadeStartIn(FADE_MODE_ADD_WHITE, 20);

                        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                            SetBattleZoom(6, Q_8_8(1.2), act->x - 0x2000, (focusZ = act->z - 0x1800, act->y + focusZ));
                        } else {
                            SetBattleZoom(6, Q_8_8(1.2), act->x + 0x2000, (focusZ = act->z - 0x1800, act->y + focusZ));
                        }
                    }

                    break;
                case 7:
                    SetBattleZoom(6, Q_8_8(1), gBtlWork->x2, gBtlWork->y2);
                    break;
                case 9:
                    m4aSongNumStart(SONG_VO_MKU_ATTACK01);
                    break;
                }
            } else {
                switch (AnimGetFrame(&work->base.anim)) {
                case 0:
                    MakeOpponentsHittable();

                    if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0x11B, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : ApplyAttackBox(0x11B, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(SONG_EF_KU_ATT01);
                        FadeStartIn(FADE_MODE_ADD_WHITE, 20);

                        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                            SetBattleZoom(6, Q_8_8(1.2), act->x - 0x2000, (focusZ = act->z - 0x1800, act->y + focusZ));
                        } else {
                            SetBattleZoom(6, Q_8_8(1.2), act->x + 0x2000, (focusZ = act->z - 0x1800, act->y + focusZ));
                        }
                    }

                    break;
                case 1:
                    SetBattleZoom(6, Q_8_8(1), gBtlWork->x2, gBtlWork->y2);
                    break;
                case 4:
                    m4aSongNumStart(SONG_VO_MKU_ATTACK02);
                    break;
                case 5:
                    MakeOpponentsHittable();

                    if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0x11C, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : ApplyAttackBox(0x11C, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(SONG_EF_KU_ATT02);
                        FadeStartIn(FADE_MODE_ADD_WHITE, 50);

                        if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                            SetBattleZoom(6, Q_8_8(2), act->x - 0x2000, (focusZ = act->z - 0x1800, act->y + focusZ));
                        } else {
                            SetBattleZoom(6, Q_8_8(2), act->x + 0x2000, (focusZ = act->z - 0x1800, act->y + focusZ));
                        }
                    }

                    break;
                case 6:
                    SetBattleZoom(6, Q_8_8(1), gBtlWork->x2, gBtlWork->y2);
                    break;
                }
            }
        }

        work->base.stateTimer++;
        break;
    }
    case HUM_CLOUD_STATE_OMNISLASH_RISE: {
        s32 vz;

        if (work->base.stateTimer == 0) {
            work->base.vz = -0x500;
        }

        vz = work->base.vz;

        if (vz < 0) {
            if (vz > -0x200) {
                AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 5, 0, w->base.tiles);
            } else {
                AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 4, 0, w->base.tiles);
            }
        }

        if (work->base.vz > 0) {
            work->base.stateTimer = 0;
            work->base.state = HUM_CLOUD_STATE_OMNISLASH_FLY;
            w->state = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    }
    case HUM_CLOUD_STATE_OMNISLASH_FLY: {
        if (work->base.stateTimer == 0) {
            AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 14, 0, w->base.tiles);
            w->speed = 0;

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                work->base.targetX = (gBtlWork->xMin + 50) << 8;
            } else {
                work->base.targetX = (gBtlWork->xMax - 50) << 8;
            }

            work->base.targetY = act->y;
            work->base.targetZ = -0xC800;
        }

        work->base.vz = 0;
        act->x += (work->base.targetX - act->x) >> 4;
        act->y += (work->base.targetY - act->y) >> 4;

        {
            s32 dz;
        dz = (work->base.targetZ - act->z) >> 3;

        if (dz > (s32)w->speed) {
            dz = w->speed;
        }

        if (dz < -(s32)w->speed) {
            dz = -w->speed;
        }

        act->z += dz;
        }

        w->speed += 0x80;

        if ((act->z - work->base.targetZ >= 0) ? act->z - work->base.targetZ <= 0xFFF : work->base.targetZ - act->z <= 0xFFF) {
            work->base.state = HUM_CLOUD_STATE_OMNISLASH_STRIKE;
            work->base.stateTimer = 0;
        } else {
            work->base.stateTimer++;
        }

        break;
    }
    case HUM_CLOUD_STATE_OMNISLASH_STRIKE:
        if (work->base.stateTimer == 0) {
            work->base.targetX = x;
            work->base.targetY = y;
            work->base.targetZ = z - 0x1000;
            MakeOpponentsHittable();

            switch ((s16)w->state) {
            case 0:
                m4aSongNumStart(SONG_VO_MKU_ATTACK00);
                AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 15, 0, w->base.tiles);
                break;
            case 1:
                m4aSongNumStart(SONG_VO_MKU_ATTACK01);
                AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 16, 0, w->base.tiles);
                break;
            case 2:
            default:
                m4aSongNumStart(SONG_VO_MKU_ATTACK02);
                AnimChangeWithDef(sHumCloudAnimDefs, &w->base.anim, 17, 0, w->base.tiles);
                break;
            }

            if (act->x < work->base.targetX) {
                act->flags &= ~BTLOBJ_FLAG_FACING_LEFT;
            } else {
                act->flags |= BTLOBJ_FLAG_FACING_LEFT;
            }
        }

        work->base.vz = 0;
        act->x += (work->base.targetX - act->x) >> 3;
        act->y += (work->base.targetY - act->y) >> 3;
        act->z += (work->base.targetZ - act->z) >> 3;

        if (work->base.anim.timer == 0) {
            switch ((s16)w->state) {
            case 0:
                if (AnimGetFrame(&work->base.anim) == 4) {
                    if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0x11D, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : ApplyAttackBox(0x11D, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(SONG_EF_KU_ATT00);
                        FadeStartIn(FADE_MODE_ADD_WHITE, 20);
                    }
                }

                break;
            case 1:
                if (AnimGetFrame(&work->base.anim) == 3) {
                    MakeOpponentsHittable();

                    if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0x11D, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : ApplyAttackBox(0x11D, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(SONG_EF_KU_ATT01);
                        FadeStartIn(FADE_MODE_ADD_WHITE, 20);
                    }
                }

                break;
            case 2:
            default:
                if (AnimGetFrame(&work->base.anim) == 3) {
                    MakeOpponentsHittable();

                    if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0x11D, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : ApplyAttackBox(0x11D, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(SONG_EF_KU_ATT02);
                        FadeStartIn(FADE_MODE_ADD_WHITE, 20);
                    }
                }

                break;
            }
        }

        if (work->base.stateTimer > 23 && AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            w->state++;

            if ((s16)w->state > 2) {
                ClearBtlObjActionFlags(act);
                work->base.state = HUM_CLOUD_STATE_JUMP_AIR;
                w->nextState = HUM_STATE_IDLE;
            } else {
                work->base.state = HUM_CLOUD_STATE_OMNISLASH_FLY;
            }
        } else {
            work->base.stateTimer++;
        }

        break;
    }

    return HumUpdate(&work->base);
}

void task_hum_cloud_2(HumWork* work) {
    HumDraw(work);
}

void task_hum_cloud_3(HumWork* work) {
    HumReleaseResources(work);
}
