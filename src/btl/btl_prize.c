/**
 * btl_prize.c
 * Battle Prize Drops
 */

#include "m4a_song.h"
#include "btl2.h"
#include "sprites_btl.h"
#include "songs.h"
#include <stdlib.h>
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "engine_math.h"
#include "game_state.h"
#include "obj.h"
#include "obj_api.h"
#include "player_progression_types.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "card_label_data.h"
#include "battle.h"

void task_btl_prize_0(BtlPrizeWork* work, BtlPremireSrc* src) {
    u8 angle;
    s32 speed;

    work->x = src->x;
    work->y = src->y;
    work->z = src->z;
    work->groundZ = 0;

    if (gBtlWork->boundsCallback != NULL) {
        gBtlWork->boundsCallback(&work->x, &work->y, &work->z, &work->groundZ);
    }

    work->vz = -(GetRandom() % 897 + 768);
    angle = GetRandom();

    work->tiles = LoadObjTiles(gBPuraizuTiles, sizeof(gBPuraizuTiles));
    work->palette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
    work->timer = 0;
    work->gfx2 = gBPuraizuFrame0;
    work->flags = (BTL_PRIZE_FLAG_SPRITE_VISIBLE | BTL_PRIZE_FLAG_DRAW_SHADOW);

    if (src->noTimeout) {
        work->flags = (BTL_PRIZE_FLAG_SPRITE_VISIBLE | BTL_PRIZE_FLAG_DRAW_SHADOW | BTL_PRIZE_FLAG_NO_TIMEOUT);
    }

    switch (src->kind) {
    case BTL_PRIZE_EXP_1400:
        work->gfx = gBPuraizuFrame1;
        work->healAmount = 0;
        work->exp = 1400;
        work->bounceSpeed = 1280;
        speed = 384;
        break;
    case BTL_PRIZE_HP_3:
        work->gfx = gBPuraizuFrame2;
        work->healAmount = 3;
        work->exp = 0;
        work->bounceSpeed = 0x300;
        speed = 76;
        break;
    case BTL_PRIZE_HP_10:
        work->gfx = gBPuraizuFrame3;
        work->healAmount = 10;
        work->exp = 0;
        work->bounceSpeed = 0x300;
        speed = 76;
        break;
    case BTL_PRIZE_EXP_1:
        work->gfx = gBPuraizuFrame4;
        work->healAmount = 0;
        work->exp = 1;
        work->bounceSpeed = 0x400;
        speed = 128;
        break;
    case BTL_PRIZE_EXP_10:
        work->gfx = gBPuraizuFrame5;
        work->healAmount = 0;
        work->exp = 10;
        work->bounceSpeed = 0x400;
        speed = 128;
        break;
    case BTL_PRIZE_EXP_60:
        work->gfx = gBPuraizuFrame6;
        work->healAmount = 0;
        work->exp = 60;
        work->bounceSpeed = 0x400;
        speed = 128;
        break;
    case BTL_PRIZE_EXP_5:
        work->gfx = gBPuraizuFrame7;
        work->healAmount = 0;
        work->exp = 5;
        work->bounceSpeed = 0x400;
        speed = 179;
        break;
    case BTL_PRIZE_EXP_30:
        work->gfx = gBPuraizuFrame8;
        work->healAmount = 0;
        work->exp = 30;
        work->bounceSpeed = 0x400;
        speed = 179;
        break;
    case BTL_PRIZE_EXP_199:
    default:
        work->gfx = gBPuraizuFrame9;
        work->healAmount = 0;
        work->exp = 199;
        work->bounceSpeed = 0x400;
        speed = 179;
        break;
    }

    work->collected = FALSE;
    work->orbitRadius = 0x100;
    gBtlWork->prizeCount++;
    work->vx = (gSineTable[angle] * speed) >> 8;
    work->vy = (-gSineTable[angle + 64] * speed) >> 8;

    if (abs(work->vx) <= 50) {
        if (work->vx < 0) {
            work->vx = -(GetRandom() % 78 + 51);
        } else {
            work->vx = GetRandom() % 78 + 51;
        }
    }

    work->actor = gBtlWork->actor;
}

#define DIST(a, b) ((a) - (b) >= 0 ? (a) - (b) : (b) - (a))
s32 task_btl_prize_1(BtlPrizeWork* work) {
    s32 hit;
    s32 rikuNearer;
    s32 range;
    s32 mainDist;
    s32 rikuDist;
    s32 vz;
    s32 tx;
    s32 ty;
    s32 tz;
    u64 flags;
    u64 linkParent;

    if (gBtlWork->flags & BTL_FLAG_FIELD_HIDDEN) {
        return 0;
    }

    if (!work->collected) {
        if (!(work->flags & BTL_PRIZE_FLAG_NO_MOVE)) {
            if (gBtlWork->boundsCallback != NULL) {
                gBtlWork->boundsCallback(&work->x, &work->y, &work->z, &work->groundZ);
            }

            work->z += work->vz;
            vz = work->vz - 15;
            work->vz = vz + gBtlWork->gravity;

            switch (ClampBattlePosition(&work->x, &work->y, 0, 0)) {
            case BATTLE_EDGE_LEFT:
            case BATTLE_EDGE_RIGHT:
                work->vx = -work->vx;
                break;
            case BATTLE_EDGE_TOP:
            case BATTLE_EDGE_BOTTOM:
                work->vy = -work->vy;
                break;
            }

            work->x += work->vx;
            work->y += work->vy;

            if (work->z > work->groundZ) {
                work->flags &= ~BTL_PRIZE_FLAG_DRAW_SHADOW;
                work->z = work->groundZ;
                work->vz = -((work->bounceSpeed >> 1) + GetRandom() % (work->bounceSpeed - (work->bounceSpeed >> 1) + 1));
            } else {
                work->flags |= BTL_PRIZE_FLAG_DRAW_SHADOW;
            }
        }

        if (work->flags & BTL_PRIZE_FLAG_CAN_COLLECT) {
            hit = FALSE;
            flags = gBtlWork->flags;

            if (flags & BTL_FLAG_VS_BATTLE) {
                mainDist = DIST(work->x, gBtlWork->actor->x);
                rikuDist = DIST(work->x, gRikuBtlWork->actor->x);

                if (mainDist == rikuDist) {
                    linkParent = flags & BTL_FLAG_VS_LINK_PARENT;
                    rikuNearer = linkParent != 0;
                } else {
                    rikuNearer = TRUE;

                    if (mainDist < rikuDist) {
                        rikuNearer = FALSE;
                    }
                }

                if (rikuNearer) {
                    if (gRikuBtlWork->hcEffect == HC_EFFECT_DRAW) {
                        range = 0x10000;
                    } else {
                        range = 0x2800;
                    }

                    if (DIST(gRikuBtlWork->actor->x, work->x) < range &&
                        DIST(gRikuBtlWork->actor->y, work->y) < (range >> 1) &&
                        DIST(gRikuBtlWork->actor->z, work->z) < 12800) {
                        work->actor = gRikuBtlWork->actor;
                        hit = TRUE;
                    } else {
                        if (gBtlWork->hcEffect == HC_EFFECT_DRAW) {
                            range = 0x10000;
                        } else {
                            range = 0x2800;
                        }

                        if (DIST(gBtlWork->actor->x, work->x) < range &&
                            DIST(gBtlWork->actor->y, work->y) < (range >> 1) &&
                            DIST(gBtlWork->actor->z, work->z) < 12800) {
                            hit = TRUE;
                        }
                    }
                } else {
                    if (gBtlWork->hcEffect == HC_EFFECT_DRAW) {
                        range = 0x10000;
                    } else {
                        range = 0x2800;
                    }

                    if (DIST(gBtlWork->actor->x, work->x) < range &&
                        DIST(gBtlWork->actor->y, work->y) < (range >> 1) &&
                        DIST(gBtlWork->actor->z, work->z) < 12800) {
                        hit = TRUE;
                    } else {
                        if (gRikuBtlWork->hcEffect == HC_EFFECT_DRAW) {
                            range = 0x10000;
                        } else {
                            range = 0x2800;
                        }

                        if (DIST(gRikuBtlWork->actor->x, work->x) < range &&
                            DIST(gRikuBtlWork->actor->y, work->y) < (range >> 1) &&
                            DIST(gRikuBtlWork->actor->z, work->z) < 12800) {
                            work->actor = gRikuBtlWork->actor;
                            hit = TRUE;
                        }
                    }
                }
            } else {
                if (gBtlWork->hcEffect == HC_EFFECT_DRAW) {
                    range = 0x10000;
                } else {
                    range = 0x2800;
                }

                if (DIST(gBtlWork->actor->x, work->x) < range &&
                    DIST(gBtlWork->actor->y, work->y) < (range >> 1) &&
                    DIST(gBtlWork->actor->z, work->z) < 12800) {
                    hit = TRUE;
                }
            }

            if (hit) {
                m4aSongNumStart(SONG_SYS_POWER_GET);

                if (gBtlWork->flags & BTL_FLAG_VS_BATTLE) {
                    work->actor->hp += work->healAmount;

                    if (work->actor->hp > work->actor->maxHp) {
                        work->actor->hp = work->actor->maxHp;
                    }
                } else {
                    work->actor->hp += work->healAmount;

                    if (work->actor->hp > work->actor->maxHp) {
                        work->actor->hp = work->actor->maxHp;
                    }

                    gGameState.progression.exp += work->exp;
                }

                work->collected = TRUE;
                work->timer = 0;
                work->angle = GetAngle(work->actor->x, work->actor->y, work->x, work->y);
                work->flags &= ~BTL_PRIZE_FLAG_DRAW_SHADOW;
                work->flags |= BTL_PRIZE_FLAG_SPRITE_VISIBLE;
                work->spinSpeed = GetRandom() % 6 + 5;
                return 1;
            }

            if (!(work->flags & BTL_PRIZE_FLAG_NO_TIMEOUT)) {
                if (work->timer > 360 && (work->timer & 3) == 0) {
                    work->flags ^= BTL_PRIZE_FLAG_SPRITE_VISIBLE;
                }

                if (work->timer > 420) {
                    return 0;
                }
            }
        } else {
            if (work->timer > 10) {
                work->flags |= BTL_PRIZE_FLAG_CAN_COLLECT;
            }
        }

        work->timer++;
    } else {
        tx = work->actor->x + ((gSineTable[work->angle] * (work->orbitRadius << 5)) >> 8);
        ty = work->actor->y + ((-gSineTable[work->angle + 64] * (work->orbitRadius << 4)) >> 8);
        tz = work->actor->z - ((work->timer >> 1) << 8);
        work->angle += work->spinSpeed;
        work->x += (tx - work->x) >> 2;
        work->y += (ty - work->y) >> 2;
        work->z += (tz - work->z) >> 2;
        work->orbitRadius -= 2;

        if (work->timer > 60) {
            return 0;
        }

        work->timer++;
    }

    return 1;
}

void task_btl_prize_2(BtlPrizeWork* work) {
    s16 x;
    s16 y;
    ObjAffine* affine;

    if (work->flags & BTL_PRIZE_FLAG_SPRITE_VISIBLE) {
        s32 flags = SPRITE_PRIORITY(2);

        WorldToScreen(&x, &y, work->x, work->y, work->z);
        affine = AllocObjAffine(0, gBtlWork->scale, gBtlWork->scale, TRUE);
        DrawSprite(x, y, work->gfx, work->tiles, work->palette, affine, flags,
                   -4100 - (work->y >> 8) * 4);

        if (work->flags & BTL_PRIZE_FLAG_DRAW_SHADOW) {
            WorldToScreen(&x, &y, work->x, work->y, work->groundZ);
            DrawSprite(x, y, work->gfx2, work->tiles, work->palette, affine, flags, 0xFFFF);
        }
    }
}

void task_btl_prize_3(BtlPrizeWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    gBtlWork->prizeCount--;
}

TaskDesc gTaskDescBtlPrize = {
    "task_btl_prize",
    (TaskInitFunc)task_btl_prize_0,
    (TaskUpdateFunc)task_btl_prize_1,
    (TaskDrawFunc)task_btl_prize_2,
    (TaskDestroyFunc)task_btl_prize_3,
    sizeof(BtlPrizeWork),
};
