/**
 * btl_raid.c
 * Raid Sleight Keyblade Throw
 */

#include "display.h"
#include "obj_api.h"
#include "btl3.h"
#include "sprites_btl.h"
#include "sprites_fld.h"
#include "btl_api.h"
#include "songs.h"
#include "btl3_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_collision.h"
#include "btl_effect.h"
#include "engine_math.h"
#include "listpool.h"
#include "m4a_song.h"
#include "obj.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"

TaskDesc gTaskDescBtlRaid = {
    "task_btl_raid",
    (TaskInitFunc)task_btl_raid_0,
    (TaskUpdateFunc)task_btl_raid_1,
    (TaskDrawFunc)task_btl_raid_2,
    (TaskDestroyFunc)task_btl_raid_3,
    sizeof(BtlRaidWork),
};

void BtlRaidGetEffectPosition(BtlRaidWork* work, s32* outX, s32* outY, s32* outZ) {
    s16 dx;
    s16 dz;

    switch (AnimGetFrame(&work->anim)) {
    case 0:
    case 1:
        dx = -15;
        dz = -6;
        break;
    case 2:
    case 3:
        dx = -15;
        dz = 6;
        break;
    case 4:
    case 5:
        dx = 0;
        dz = 8;
        break;
    case 6:
    case 7:
        dx = 15;
        dz = 6;
        break;
    case 8:
    case 9:
        dx = 15;
        dz = -6;
        break;
    case 10:
    case 11:
    default:
        dx = 0;
        dz = -8;
        break;
    }

    if (!work->facingLeft) {
        dx = -dx;
    }

    *outX = work->x + (dx << 8);
    *outY = work->y;
    *outZ = work->z + (dz << 8);
}

enum BtlRaidState {
    BTL_RAID_STATE_THROW,
    BTL_RAID_STATE_BOUNCE,
    BTL_RAID_STATE_STRIKE,
    BTL_RAID_STATE_RICOCHET,
    BTL_RAID_STATE_HOMING,
    BTL_RAID_STATE_RETURN
};

void task_btl_raid_0(BtlRaidWork* work, BtlRaidArgs* args) {
    s32 x;
    s32 y;
    s32 z;

    work->variant = args->variant;

    if (args->facingLeft) {
        work->facingLeft = TRUE;
    } else {
        work->facingLeft = FALSE;
    }

    if (args->mainSide) {
        work->mainSide = TRUE;
        work->tiles2 = gBtlWork->tiles2;
        work->actor = gBtlWork->actor;
        work->palette = LoadObjPalette(gSoraPalette, sizeof(gSoraPalette));
    } else {
        work->mainSide = FALSE;
        work->tiles2 = gBtlWork->tiles2;
        work->actor = gRikuBtlWork->actor;
        work->palette = LoadObjPalette(gBtlOtherSidePalette, sizeof(gBtlOtherSidePalette));
    }

    AnimInit(&work->anim, NULL, NULL);
    AnimChangeWithTables(&work->anim, 0, ANIM_FLAG_LOOP, gSor1ll68wAnims, gSor1ll68wFrames);
    SetObjTileSource(work->tiles2, gSor1ll68wTiles);
    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->timer = 100;
    work->state = BTL_RAID_STATE_THROW;
    work->scale = Q_8_8(1);
    work->vx = 0x800;
    work->hitHalfSize = 10;
    work->flags = BTL_RAID_FLAG_BLADE_VISIBLE;
    work->song = SONG_EF_LT2_HIT;

    switch (work->variant) {
    case BTL_RAID_STRIKE:
        work->attack = 86;
        break;
    case BTL_RAID_STOP:
        work->attack = 100;
        break;
    case BTL_RAID_FIRE:
        work->attack = 101;
        BtlRaidGetEffectPosition(work, &x, &y, &z);
        BgFxStartFlame(x, y, z, Q_8_8(1.3));
        work->hitHalfSize = 16;
        work->song = SONG_EF_FIRE01;
        break;
    case BTL_RAID_BLIZZARD:
        work->attack = 102;
        BtlRaidGetEffectPosition(work, &x, &y, &z);
        BgFxStartFrost(x, y, z, Q_8_8(1.3));
        work->hitHalfSize = 16;
        work->song = SONG_EF_BURIZA01;
        break;
    case BTL_RAID_THUNDER:
        work->attack = 103;
        work->flags |= BTL_RAID_FLAG_STRIKE_ON_CONTACT;
        work->hitHalfSize = 8;
        break;
    case BTL_RAID_GRAVITY:
        work->attack = 104;
        work->flags |= BTL_RAID_FLAG_STRIKE_ON_CONTACT;
        work->hitHalfSize = 8;
        break;
    case BTL_RAID_REFLECT:
        work->attack = 105;
        work->state = BTL_RAID_STATE_RICOCHET;

        if (work->facingLeft) {
            work->angle = 192;
        } else {
            work->angle = 64;
        }

        work->timer = 0;
        work->unk_5A = GetRandom() % 5 + 0xFFFE;
        break;
    case BTL_RAID_JUDGMENT:
        work->attack = 111;
        work->state = BTL_RAID_STATE_HOMING;

        if (work->facingLeft) {
            work->angle = 192;
        } else {
            work->angle = 64;
        }

        work->timer = 0;
        work->steps = 0;
        break;
    }

    work->tiles = LoadObjTiles(gBtlShadowSmallTiles, sizeof(gBtlShadowSmallTiles));
    work->palette2 = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
    m4aSongNumStart(SONG_BTL_LT2_SW);
}

BtlObj* BtlRaidGetTarget(BtlRaidWork* work) {
    BtlObj* obj;

    if (gBtlWork->flags & BTL_FLAG_VS_BATTLE) {
        if (work->mainSide) {
            obj = gRikuBtlWork->actor;
        } else {
            obj = gBtlWork->actor;
        }

        if (obj->hp <= 0) {
            return NULL;
        }

        return obj;
    }

    if (gBtlWork->actor2 == NULL) {
        return ListPoolFirst(&gBtlWork->pool);
    }

    return gBtlWork->actor2;
}

u8 task_btl_raid_1(BtlRaidWork* work) {
    BtlObj* obj;
    u16 edge;
    s32 x;
    s32 y;
    s32 z;

    if ((work->mainSide ? gBtlWork : gRikuBtlWork)->flags & BTL_FLAG_DISMISS_SUMMONS) {
        return 0;
    }

    BtlMapFollowPosition(work->x, work->y, work->z + 0x1800);

    switch (work->state) {
    case BTL_RAID_STATE_HOMING:
        work->x += gSineTable[(u8)work->angle] * 5;
        work->z += -gSineTable[(u8)work->angle + 64] * 5;

        if (work->z > 0) {
            work->z = 0;
        }

        obj = BtlRaidGetTarget(work);

        if (obj != NULL) {
            if (work->steps <= 0) {
                ApproachAngle(&work->angle,
                              GetAngle(work->x, work->z, obj->x,
                                            obj->z - (obj->centerHeight << 8)),
                              2);
            } else {
                work->steps--;
            }

            work->y += (obj->y - work->y) >> 3;

            if (ApplyAttackBox(work->attack, work->x, work->y, work->z, 8, 8, 8) != ATTACK_RESULT_NONE) {
                m4aSongNumStart(work->song);

                if (obj->flags & BTLOBJ_FLAG_DAMAGE_PENDING) {
                    work->steps = 20;
                }
            }
        }

        if (obj == NULL || work->timer > 180) {
            work->state = BTL_RAID_STATE_RETURN;
            work->timer = 0;
        } else {
            work->timer++;
        }

        break;
    case BTL_RAID_STATE_RICOCHET:
        work->x += gSineTable[(u8)work->angle] * 8;
        work->y -= gSineTable[(u8)work->angle + 64] * 4;
        edge = ClampBattlePosition(&work->x, &work->y, 0, 0);

        switch (edge) {
        case BATTLE_EDGE_LEFT:
            work->angle = GetRandom() % 65 + 32;
            break;
        case BATTLE_EDGE_RIGHT:
            work->angle = GetRandom() % 65 + 160;
            break;
        case BATTLE_EDGE_BOTTOM:
            work->angle = GetRandom() % 65 + 0xFFE0;
            break;
        case BATTLE_EDGE_TOP:
            work->angle = GetRandom() % 65 + 96;
            break;
        }

        if (ApplyAttackBox(work->attack, work->x, work->y, work->z, 8, 8, 32) != ATTACK_RESULT_NONE) {
            m4aSongNumStart(work->song);
        }

        if (edge != BATTLE_EDGE_NONE) {
            if (work->timer > 180) {
                work->state = BTL_RAID_STATE_RETURN;
                work->timer = 0;
                break;
            }

            work->unk_5A = GetRandom() % 5 + 0xFFFE;
        }

        work->timer++;
        break;
    case BTL_RAID_STATE_RETURN:
        if (work->timer == 0) {
            work->steps = 16;
        }

        ApproachValue(&work->x, work->actor->x, work->steps);
        ApproachValue(&work->y, work->actor->y, work->steps);
        ApproachValue(&work->z, work->actor->z - 0x1000, work->steps);
        work->steps--;

        if (work->steps <= 3) {
            return 0;
        }

        work->timer++;
        break;
    case BTL_RAID_STATE_THROW:
        ApproachValue(&work->vx, -0x800, work->timer);

        if (work->facingLeft) {
            work->x = work->x - work->vx;
        } else {
            work->x = work->x + work->vx;
        }

        if (work->flags & BTL_RAID_FLAG_STRIKE_ON_CONTACT) {
            if (TestAttackBox(work->x, work->y, work->z, work->hitHalfSize, work->hitHalfSize, 32)) {
                work->state = BTL_RAID_STATE_STRIKE;
                work->timer = 0;
                break;
            }
        } else {
            if (ApplyAttackBox(work->attack, work->x, work->y, work->z,
                              work->hitHalfSize, work->hitHalfSize, 32) != ATTACK_RESULT_NONE) {
                m4aSongNumStart(work->song);
            }
        }

        if (work->timer <= 0) {
            switch (work->variant) {
            case BTL_RAID_FIRE:
            case BTL_RAID_BLIZZARD:
                BgAnimStop();
                break;
            }

            return 0;
        }

        switch (ClampBattlePosition(&work->x, &work->y, -20, 0)) {
        case BATTLE_EDGE_LEFT:
        case BATTLE_EDGE_RIGHT:
            work->state = BTL_RAID_STATE_BOUNCE;
            work->steps = work->timer >> 2;
            work->bounceVx = work->vx;
            break;
        }

        work->timer--;
        break;
    case BTL_RAID_STATE_BOUNCE:
        ApproachValue(&work->vx, -work->bounceVx, work->steps);

        if (work->facingLeft) {
            work->x = work->x - work->vx;
        } else {
            work->x = work->x + work->vx;
        }

        if (ApplyAttackBox(work->attack, work->x, work->y, work->z,
                          work->hitHalfSize, work->hitHalfSize, 32) != ATTACK_RESULT_NONE) {
            m4aSongNumStart(work->song);
        }

        if (work->steps <= 0) {
            work->timer = 100 - work->timer;
            MakeOpponentsHittable();
            work->state = BTL_RAID_STATE_THROW;
        } else {
            work->steps--;
        }

        break;
    case BTL_RAID_STATE_STRIKE:
        if (work->timer == 0) {
            work->steps = 30;

            switch (work->variant) {
            case BTL_RAID_THUNDER:
                BgFxStartThunderStrike(work->x, work->y, 0, work->attack);
                break;
            case BTL_RAID_GRAVITY:
                BgFxStartGravityStrike(work->x, work->y, 0, work->attack);
                break;
            }
        }

        if (work->steps > 0) {
            ApproachValue(&work->scale, Q_8_8(0.1), work->steps);
            work->steps--;

            if (work->steps <= 0) {
                work->flags &= ~BTL_RAID_FLAG_BLADE_VISIBLE;
            }
        }

        if (!(work->flags & BTL_RAID_FLAG_BLADE_VISIBLE) && !BgFxIsActive()) {
            return 0;
        }

        work->timer++;
        break;
    }

    switch (work->variant) {
    case BTL_RAID_FIRE:
    case BTL_RAID_BLIZZARD:
        BtlRaidGetEffectPosition(work, &x, &y, &z);
        BgFxSetPosition(x, y, z);
        break;
    }

    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_btl_raid_2(BtlRaidWork* work) {
    s16 sx;
    s16 sy;
    u16 flags;
    ObjAffine* affine;
    s32 scale;

    if (work->flags & BTL_RAID_FLAG_BLADE_VISIBLE) {
        flags = GetBattleSpritePriorityFlags(work->y);
        WorldToScreen(&sx, &sy, work->x, work->y, work->z);
        scale = gBtlWork->scale * work->scale >> 8;

        if (scale == Q_8_8(1)) {
            affine = NULL;

            if (!work->facingLeft) {
                flags |= SPRITE_FLAG_HFLIP;
            }
        } else {
            if (!work->facingLeft) {
                affine = AllocObjAffine(0, -scale, scale, TRUE);
            } else {
                affine = AllocObjAffine(0, scale, scale, TRUE);
            }
        }

        DrawSprite(sx, sy, work->gfx, work->tiles2, work->palette, affine, flags,
                   -4100 - (((work->y + 0x1000) >> 8) * 4));
        WorldToScreen(&sx, &sy, work->x, work->y, 0);
        DrawSprite(sx, sy, gBtlShadowSmallFrame0, work->tiles, work->palette2, NULL, flags, 0xFFFE);
    }
}

void task_btl_raid_3(BtlRaidWork* work) {
    ReleaseObjPalette(work->palette);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette2);
}
