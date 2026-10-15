/**
 * btl_premire.c
 * Premium Bonus Drop
 */

#include "m4a_song.h"
#include "btl2.h"
#include "sprites_btl.h"
#include "songs.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "engine_math.h"
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "card_label_data.h"

void task_btl_premire_0(BtlPremireWork* work, BtlPremireSrc* src) {
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
    AnimInit(&work->anim, gBPuraizuAnims, gBPuraizuFrames);
    AnimStart(&work->anim, 10, ANIM_FLAG_LOOP);
    work->gfx = AnimGetGfx(&work->anim);
    work->timer = 0;
    work->gfx2 = gBPuraizuFrame0;
    work->flags = (BTL_PRIZE_FLAG_SPRITE_VISIBLE | BTL_PRIZE_FLAG_DRAW_SHADOW);

    if (src->noTimeout) {
        work->flags = (BTL_PRIZE_FLAG_SPRITE_VISIBLE | BTL_PRIZE_FLAG_DRAW_SHADOW | BTL_PRIZE_FLAG_NO_TIMEOUT);
    }

    work->bounceSpeed = 0x400;
    speed = 384;
    work->collected = FALSE;
    work->orbitRadius = 0x100;
    gBtlWork->prizeCount++;
    work->vx = (gSineTable[angle] * speed) >> 8;
    work->vy = (-gSineTable[angle + 64] * speed) >> 8;
    work->actor = gBtlWork->actor;
}

#define DIST(a, b) ((a) - (b) >= 0 ? (a) - (b) : (b) - (a))
s32 task_btl_premire_1(BtlPremireWork* work) {
    s32 hit;
    s32 range;
    s32 vz;
    s32 tx;
    s32 ty;
    s32 tz;
    u64 flags;

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
                if (flags & BTL_FLAG_VS_LINK_PARENT) {
                    if (gRikuBtlWork->hcEffect == HC_EFFECT_DRAW) {
                        range = 0x10000;
                    } else {
                        range = 0x2000;
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
                            range = 0x2000;
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
                        range = 0x2000;
                    }

                    if (DIST(gBtlWork->actor->x, work->x) < range &&
                        DIST(gBtlWork->actor->y, work->y) < (range >> 1) &&
                        DIST(gBtlWork->actor->z, work->z) < 12800) {
                        hit = TRUE;
                    } else {
                        if (gRikuBtlWork->hcEffect == HC_EFFECT_DRAW) {
                            range = 0x10000;
                        } else {
                            range = 0x2000;
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
                    range = 0x2000;
                }

                if (DIST(gBtlWork->actor->x, work->x) < range &&
                    DIST(gBtlWork->actor->y, work->y) < (range >> 1) &&
                    DIST(gBtlWork->actor->z, work->z) < 12800) {
                    hit = TRUE;
                }
            }

            if (hit) {
                m4aSongNumStart(SONG_SYS_POWER_GET);
                gBtlWork->flags |= BTL_FLAG_PREMIRE_COLLECTED;
                work->timer = 0;
                work->collected = TRUE;
                work->timer = 0;
                work->angle = GetAngle(work->actor->x, work->actor->y, work->x, work->y);
                work->flags &= ~BTL_PRIZE_FLAG_DRAW_SHADOW;
                work->flags |= BTL_PRIZE_FLAG_SPRITE_VISIBLE;
                work->spinSpeed = GetRandom() % 6 + 5;
                work->gfx = AnimUpdate(&work->anim);
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

    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_btl_premire_2(BtlPremireWork* work) {
    s16 x;
    s16 y;
    ObjAffine* affine;

    if (work->flags & BTL_PRIZE_FLAG_SPRITE_VISIBLE) {
        u16 flags = GetBattleSpritePriorityFlags(work->y);

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

void task_btl_premire_3(BtlPremireWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    gBtlWork->prizeCount--;
}

TaskDesc gTaskDescBtlPremire = {
    "task_btl_premire",
    (TaskInitFunc)task_btl_premire_0,
    (TaskUpdateFunc)task_btl_premire_1,
    (TaskDrawFunc)task_btl_premire_2,
    (TaskDestroyFunc)task_btl_premire_3,
    sizeof(BtlPremireWork),
};
