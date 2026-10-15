/**
 * bos_boogie_dice.c
 * Oogie Boogie Boss Dice and Gimmicks
 */

#include "macros.h"
#include "bos4.h"
#include "sprites_bos4.h"
#include "system_state.h"
#include "btl_api.h"
#include "songs.h"
#include <string.h>
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_bg_types.h"
#include "battle_work.h"
#include "bos4_api.h"
#include "bos_boogie.h"
#include "btl_collision.h"
#include "btl_effect.h"
#include "card_api.h"
#include "display.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "map_types.h"
#include "obj.h"
#include "obj_api.h"
#include "registration_data.h"
#include "task_descriptors.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "bos_boogie_dice.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"
#include "gba/defines.h"

#define BOS_BOOGIE_VIEW_Y_MIN 396
#define BOS_BOOGIE_VIEW_Y_MAX 632

u16 gBosBoogieSakuOpenTime EWRAM_COMMON(4);
u8 gBosBoogieDiceFace EWRAM_COMMON(4);
struct BtlObj* gBosBoogieActor EWRAM_COMMON(4);
u16 gBosBoogieDiceBreakCount EWRAM_COMMON(4);
u8 gBosBoogieDiceFaceReady EWRAM_COMMON(4);
u8 gBosBoogieGimmickCardDropped EWRAM_COMMON(4);
u8 gBosBoogieAttackHit EWRAM_COMMON(4);
u8 gBosBoogieTaskKnockedDown EWRAM_COMMON(4);
u8 gBosBoogieKnivesRetract EWRAM_COMMON(4);
u8 gBosBoogieKnivesMoveRight EWRAM_COMMON(4);
u8 gBosUrsulaActive EWRAM_COMMON(4);
s32 gBosUrsulaBaseZ EWRAM_COMMON(4);
u8 gMapChkUseParams EWRAM_COMMON(4);
MapFloorState gMapFloorState EWRAM_COMMON(16);

static const EmyKind sBosBoogieDiceEmyKind = { ENEMY_OOGIE_BOOGIE, 0, 16, 16, 0, 0, EMY_KIND_FLAG_NO_COLLIDER };

TaskDesc gTaskDescBosBoogieDice = {
    "task_bos_boogie_dice",
    (TaskInitFunc)task_bos_boogie_dice_0,
    (TaskUpdateFunc)task_bos_boogie_dice_1,
    (TaskDrawFunc)task_bos_boogie_dice_2,
    (TaskDestroyFunc)task_bos_boogie_dice_3,
    sizeof(BoogieDiceWork),
};

static void* const sBoogieDiceFaces[6][3] = {
    { gBosBoogieDiceFace0Anims, gBosBoogieDiceFace0Frames, gBosBoogieDiceFace0Tiles },
    { gBosBoogieDiceFace1Anims, gBosBoogieDiceFace1Frames, gBosBoogieDiceFace1Tiles },
    { gBosBoogieDiceFace2Anims, gBosBoogieDiceFace2Frames, gBosBoogieDiceFace2Tiles },
    { gBosBoogieDiceFace3Anims, gBosBoogieDiceFace3Frames, gBosBoogieDiceFace3Tiles },
    { gBosBoogieDiceFace4Anims, gBosBoogieDiceFace4Frames, gBosBoogieDiceFace4Tiles },
    { gBosBoogieDiceFace5Anims, gBosBoogieDiceFace5Frames, gBosBoogieDiceFace5Tiles },
};

static const EmyKind sBosBoogieExplosiondiceEmyKind = { ENEMY_OOGIE_BOOGIE, 0, 16, 16, 0, 0, 0 };

static TaskDesc sTaskDescBosBoogieExplosiondice = {
    "task_bos_boogie_explosiondice",
    (TaskInitFunc)task_bos_boogie_explosiondice_0,
    (TaskUpdateFunc)task_bos_boogie_explosiondice_1,
    (TaskDrawFunc)task_bos_boogie_explosiondice_2,
    (TaskDestroyFunc)task_bos_boogie_explosiondice_3,
    sizeof(BoogieExplosiondiceWork),
};

TaskDesc gTaskDescBosBoogieSaku = {
    "task_bos_boogie_saku",
    (TaskInitFunc)task_bos_boogie_saku_0,
    (TaskUpdateFunc)task_bos_boogie_saku_1,
    (TaskDrawFunc)task_bos_boogie_saku_2,
    (TaskDestroyFunc)task_bos_boogie_saku_3,
    sizeof(BoogieSakuWork),
};

TaskDesc gTaskDescBosBoogieMap = {
    "task_bos_boogie_map",
    (TaskInitFunc)task_bos_boogie_map_0,
    (TaskUpdateFunc)task_bos_boogie_map_1,
    NULL,
    NULL,
    sizeof(BoogieMapWork),
};

static const BosMapanimeFrame sBosBoogieMapanimeFrames[5] = { { 5, 0 }, { 5, 1 }, { 5, 2 }, { 5, 3 }, { 5, 4 } };

static const BosMapanimeDef sBosBoogieMapanimeDef0 = { sBosBoogieMapanimeFrames, ARRAY_COUNT(sBosBoogieMapanimeFrames), gBosBoogieMapanime0Tiles, 0x7C00, 0x0100, 0x0300, 0 };

static const BosMapanimeDef sBosBoogieMapanimeDef1 = { sBosBoogieMapanimeFrames, ARRAY_COUNT(sBosBoogieMapanimeFrames), gBosBoogieMapanime1Tiles, 0x7D00, 0x0100, 0x0300, 0 };

static const BosMapanimeDef sBosBoogieMapanimeDef2 = { sBosBoogieMapanimeFrames, ARRAY_COUNT(sBosBoogieMapanimeFrames), gBosBoogieMapanime2Tiles, 0x7E00, 0x0100, 0x0300, 0 };

TaskDesc gTaskDescBosBoogieMapanime = {
    "task_bos_boogie_mapanime",
    (TaskInitFunc)task_bos_boogie_mapanime_0,
    (TaskUpdateFunc)task_bos_boogie_mapanime_1,
    (TaskDrawFunc)task_bos_boogie_mapanime_2,
    (TaskDestroyFunc)task_bos_boogie_mapanime_3,
    sizeof(BoogieMapanimeWork),
};

static const EmyKind sBosBoogieDiskEmyKind = { ENEMY_OOGIE_BOOGIE, 0, 16, 16, 0, 0, EMY_KIND_FLAG_LARGE_BODY };

TaskDesc gTaskDescBosBoogieDisk = {
    "task_bos_boogie_disk",
    (TaskInitFunc)task_bos_boogie_disk_0,
    (TaskUpdateFunc)task_bos_boogie_disk_1,
    (TaskDrawFunc)task_bos_boogie_disk_2,
    (TaskDestroyFunc)task_bos_boogie_disk_3,
    sizeof(BoogieDiskWork),
};

static const EmyKind sBosBoogieKnifeEmyKind = { ENEMY_OOGIE_BOOGIE, 0, 192, 16, 0, 0, 0 };

static TaskDesc sTaskDescBosBoogieKnife = {
    "task_bos_boogie_knife",
    (TaskInitFunc)task_bos_boogie_knife_0,
    (TaskUpdateFunc)task_bos_boogie_knife_1,
    (TaskDrawFunc)task_bos_boogie_knife_2,
    (TaskDestroyFunc)task_bos_boogie_knife_3,
    sizeof(BoogieKnifeWork),
};

static const EmyKind sBosBoogieKnifereaderEmyKind = { ENEMY_OOGIE_BOOGIE, 0, 0, 0, 0, 0, 0 };

TaskDesc gTaskDescBosBoogieKnifereader = {
    "task_bos_boogie_knifereader",
    (TaskInitFunc)task_bos_boogie_knifereader_0,
    (TaskUpdateFunc)task_bos_boogie_knifereader_1,
    (TaskDrawFunc)task_bos_boogie_knifereader_2,
    (TaskDestroyFunc)task_bos_boogie_knifereader_3,
    sizeof(BoogieKnifereaderWork),
};

static const EmyKind sBosBoogieKaihukuEmyKind = { ENEMY_OOGIE_BOOGIE, 0, 16, 16, 0, 0, 0 };

TaskDesc gTaskDescBosBoogieKaihuku = {
    "task_bos_boogie_kaihuku",
    (TaskInitFunc)task_bos_boogie_kaihuku_0,
    (TaskUpdateFunc)task_bos_boogie_kaihuku_1,
    (TaskDrawFunc)task_bos_boogie_kaihuku_2,
    (TaskDestroyFunc)task_bos_boogie_kaihuku_3,
    sizeof(BoogieKaihukuWork),
};

u8 ClampBoogieDicePosition(s32* x, s32* y, s16 marginX, u16 marginY) {
    u8 clamped;

    clamped = FALSE;

    if (*x < (128 - marginX) << 8) {
        *x = (128 - marginX) << 8;
        clamped = TRUE;
    }

    if (*x > (marginX + 368) << 8) {
        *x = (marginX + 368) << 8;
        clamped = TRUE;
    }

    if (*y < (576 - (s16)marginY) << 8) {
        *y = (576 - (s16)marginY) << 8;
        clamped = TRUE;
    }

    if (*y > ((s16)marginY + 632) << 8) {
        *y = ((s16)marginY + 632) << 8;
        clamped = TRUE;
    }

    return clamped;
}

u8 BosBoogieDiceIsHeld(BoogieDiceWork* work) {
    if (work->state == BOS_BOOGIE_DICE_STATE_THROWN) {
        if (work->parent->state == BOS_BOOGIE_STATE_DICE_THROW) {
            if (AnimGetFrame(&work->parent->anim) <= 2) {
                if (!AnimIsFinished(&work->parent->anim)) {
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

void BosBoogieDiceGrow(BoogieDiceWork* work) {
    if (work->scaleY <= 255) {
        work->scaleY += 8;
    }

    if (work->scaleX <= 255) {
        work->scaleX += 8;
    }
}

void task_bos_boogie_dice_0(BoogieDiceWork* work, BoogieWork* arg) {
    BtlObj* boogieActor = &arg->actor;
    s32 x;
    s32 y;
    s32 z;
    u16 roll;

    work->follower = arg->diceFollower;
    work->parent = arg;
    work->state = BOS_BOOGIE_DICE_STATE_WAIT_CARD;
    work->timer = 0;
    work->vz = -0x4CC;
    work->speed = GetRandom() % 437 + 0x4C;
    work->angle = GetRandom() % 0x78 + 0x44;
    work->scaleY = Q_8_8(0.2);
    work->scaleX = Q_8_8(0.2);
    work->y = 0;
    work->counted = FALSE;
    gBosBoogieDiceFaceReady = FALSE;
    x = boogieActor->x;
    y = 0x24000;
    z = boogieActor->z - 0x3800;
    InitEnemyBtlObj(&work->obj, &sBosBoogieDiceEmyKind, x, y, z);
    ColliderInit(&work->obj.collider, COLLIDER_TYPE_ENEMY, sBosBoogieDiceEmyKind.radius, sBosBoogieDiceEmyKind.height);
    work->obj.flags |= 0x400;
#ifdef VERSION_EU
    work->obj.flags |= BTLOBJ_FLAG_INTANGIBLE;
#else
    work->obj.flags |= BTLOBJ_FLAG_HIT_LOCKED;
#endif
    work->tiles = AllocObjTiles(GetMaxSpriteTileBytes(gBosBoogieDiceFrames, ARRAY_COUNT(gBosBoogieDiceFrames)), gBosBoogieDiceTiles);
    work->palette = LoadObjPalette(gBosBoogieDicePalette, sizeof(gBosBoogieDicePalette));
    work->palette2 = LoadObjPalette(gHitFlashPalette, sizeof(gHitFlashPalette));
    AnimInit(&work->anim, gBosBoogieDiceAnims, gBosBoogieDiceFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
    roll = GetRandom();
    AnimSetFrame(&work->anim, roll & 3);
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBosShadow, &work->obj);

    if (!work->follower) {
        RequestEnemyCardUse(&work->obj);
    }
}

u8 task_bos_boogie_dice_1(BoogieDiceWork* work) {
    BtlObj* obj = &work->obj;

    if (!work->follower) {
        switch (UpdateBtlObjReaction(obj)) {
        case BTL_REACTION_CARD_ACTION:
            work->state = BOS_BOOGIE_DICE_STATE_THROWN;
            work->timer = 0;
            break;
        case BTL_REACTION_CARD_BROKEN:
            work->state = BOS_BOOGIE_DICE_STATE_BROKEN;
            work->timer = 0;
            gBosBoogieSakuOpenTime += 180;
            break;
        case BTL_REACTION_HEALED:
        default:
            if (ConsumeGimmickFlag(0)) {
                BosBoogieApplyGimmick();

                if (work->state == BOS_BOOGIE_DICE_STATE_THROWN) {
                    work->state = BOS_BOOGIE_DICE_STATE_BROKEN;
                    work->timer = 0;
                }
            }

            break;
        case BTL_REACTION_HURT:
        case BTL_REACTION_DEFEATED:
        case BTL_REACTION_STUNNED:
        case BTL_REACTION_GRAVITY:
        case BTL_REACTION_GRAVITY_DEFEATED:
            work->state = BOS_BOOGIE_DICE_STATE_DESTROYED;
            work->timer = 0;
            break;
        }
    } else {
        switch (GetBoogieDiceState()) {
        case BOS_BOOGIE_DICE_STATE_THROWN:
            if (work->state != BOS_BOOGIE_DICE_STATE_THROWN) {
                work->state = BOS_BOOGIE_DICE_STATE_THROWN;
                work->timer = 0;
            }

            break;
        case BOS_BOOGIE_DICE_STATE_BROKEN:
            if (work->state != BOS_BOOGIE_DICE_STATE_BROKEN) {
                work->state = BOS_BOOGIE_DICE_STATE_BROKEN;
                work->timer = 0;
            }

            break;
        case BOS_BOOGIE_DICE_STATE_TUMBLE:
            if (work->state == BOS_BOOGIE_DICE_STATE_THROWN) {
                work->state = BOS_BOOGIE_DICE_STATE_BROKEN;
                work->timer = 0;
            }

            break;
        }

        switch ((u32)UpdateBtlObjReaction(obj)) {
        case BTL_REACTION_HURT:
        case BTL_REACTION_DEFEATED:
        case BTL_REACTION_STUNNED:
        case BTL_REACTION_GRAVITY:
        case BTL_REACTION_GRAVITY_DEFEATED:
            work->state = BOS_BOOGIE_DICE_STATE_DESTROYED;
            work->timer = 0;
            break;
        }
    }

    switch (work->state) {
    case BOS_BOOGIE_DICE_STATE_THROWN:
        if (BosBoogieDiceIsHeld(work)) {
            return 1;
        }

#ifdef VERSION_EU
        obj->flags &= ~BTLOBJ_FLAG_INTANGIBLE;
#else
        obj->flags &= ~BTLOBJ_FLAG_HIT_LOCKED;
#endif
        BosBoogieDiceGrow(work);
        work->vz += 51;
        obj->z += work->vz;
        obj->x += gSineTable[work->angle] * work->speed >> 8;
        obj->y += -gSineTable[work->angle + 0x40] * work->speed >> 8;

        if (obj->collider.colliding && work->scaleY > 255 && work->scaleX > 255) {
            work->speed = work->speed * 230 >> 8;
            obj->x += obj->collider.pushX;
            obj->y += obj->collider.pushY;
            work->angle = work->angle + (100 + GetRandom() % 57);
        }

        if (ClampBoogieDicePosition(&obj->x, &obj->y, 0, 0)) {
            work->angle = work->angle + (100 + GetRandom() % 57);
        }

        if (obj->z > 0) {
            obj->z = 0;
            work->vz = -(work->vz * 179 >> 8);
            work->speed = work->speed * 212 >> 8;

            if (work->vz >= -25) {
                RollBoogieDice(work);
                work->state = BOS_BOOGIE_DICE_STATE_SHOW_FACE;
                obj->flags |= BTLOBJ_FLAG_INTANGIBLE;

                if (!work->follower) {
                    ClearBtlObjActionFlags(obj);
                }
            }
        }

        break;
    case BOS_BOOGIE_DICE_STATE_BROKEN:
#ifdef VERSION_EU
        obj->flags &= ~BTLOBJ_FLAG_INTANGIBLE;
#else
        obj->flags &= ~BTLOBJ_FLAG_HIT_LOCKED;
#endif

        if (work->timer == 0 && !work->follower) {
            ClearBtlObjActionFlags(obj);
            gBosBoogieDiceBreakCount++;
            work->counted = TRUE;
        }

        work->timer++;
        BosBoogieDiceGrow(work);

        if (obj->collider.colliding && work->scaleY > 255 && work->scaleX > 255) {
            work->speed = work->speed * 230 >> 8;
            obj->x += obj->collider.pushX;
            obj->y += obj->collider.pushY;
            work->angle = work->angle + (100 + GetRandom() % 57);
        }

        work->vz += 51;
        obj->z += work->vz;

        if (obj->z > 0) {
            obj->z = 0;
            work->vz = -(work->vz * 128 >> 8);
            work->timer = 0;
            work->state = BOS_BOOGIE_DICE_STATE_TUMBLE;
        }

        break;
    case BOS_BOOGIE_DICE_STATE_TUMBLE:
        if (work->timer > 59) {
            work->state = BOS_BOOGIE_DICE_STATE_SQUASH;
            break;
        }

        work->timer++;
        work->vz += 51;
        obj->x += gSineTable[work->angle] * work->speed >> 8;
        obj->y += -gSineTable[work->angle + 0x40] * work->speed >> 8;

        if (obj->collider.colliding && work->scaleY > 255 && work->scaleX > 255) {
            work->speed = work->speed * 230 >> 8;
            obj->x += obj->collider.pushX;
            obj->y += obj->collider.pushY;
            work->angle = work->angle + (100 + GetRandom() % 57);
        }

        if (ClampBoogieDicePosition(&obj->x, &obj->y, 0, 0)) {
            work->angle = work->angle + (100 + GetRandom() % 57);
        }

        if (obj->z > 0) {
            obj->z = 0;
            work->vz = -(work->vz * 179 >> 8);
        }

        break;
    case BOS_BOOGIE_DICE_STATE_DESTROYED:
        if (!work->follower && !gBosBoogieGimmickCardDropped && GetRandom() % 16 <= 7) {
            gBosBoogieGimmickCardDropped = TRUE;
            DropGimmickCard(0, obj->x, obj->y, obj->z);
        }

        SetBtlObjUnhittable(obj, TRUE);

        return 0;
    case BOS_BOOGIE_DICE_STATE_SHOW_FACE:
        if (AnimIsFinished(&work->anim)) {
            work->state = BOS_BOOGIE_DICE_STATE_FACE_WAIT;
            work->timer = 0;
        }

        break;
    case BOS_BOOGIE_DICE_STATE_FACE_WAIT:
        if (work->timer > 20) {
            work->state = BOS_BOOGIE_DICE_STATE_SQUASH;
            break;
        }

        work->timer++;
        break;
    case BOS_BOOGIE_DICE_STATE_SQUASH:
        SetBtlObjUnhittable(obj, TRUE);
        work->scaleY -= Q_8_8(0.05);
        work->y += 96;

        if (work->scaleY <= 127) {
            work->state = BOS_BOOGIE_DICE_STATE_SQUASH_WAIT;
            work->vz = -0x4CC;
            work->timer = 0;
        }

        break;
    case BOS_BOOGIE_DICE_STATE_SQUASH_WAIT:
        if (work->timer > 10) {
            work->state = BOS_BOOGIE_DICE_STATE_JUMP;
            work->timer = 0;
            break;
        }

        work->timer++;
        break;
    case BOS_BOOGIE_DICE_STATE_JUMP:
        work->vz += 51;
        obj->z += work->vz;
        work->scaleY += Q_8_8(0.1);
        work->y -= 200;

        if (work->scaleY > 255) {
            work->state = BOS_BOOGIE_DICE_STATE_VANISH;
            work->timer = 0;
        } else if (work->scaleY <= 178) {
            break;
        }
    case BOS_BOOGIE_DICE_STATE_VANISH:
        work->scaleX -= Q_8_8(0.15);

        if (work->scaleX <= 24) {
            BgFxStartDarkDeathBlend(obj->x, obj->y + obj->z, Q_8_8(1), 8, 16);

            return 0;
        }

        break;
    case BOS_BOOGIE_DICE_STATE_WAIT_CARD:
        if (work->timer > 30) {
            return 0;
        }

        work->timer++;
        break;
    }

    AnimUpdate(&work->anim);

    if (work->state == BOS_BOOGIE_DICE_STATE_TUMBLE) {
        AnimUpdate(&work->anim);
    }

    ColliderSetPosition(&obj->collider, obj->x, obj->y, obj->z);
    TaskPoolUpdate(&work->tasks);

    return 1;
}

void task_bos_boogie_dice_2(BoogieDiceWork* work) {
    BtlObj* obj = &work->obj;
    s16 x;
    s16 y;
    u16 flags;
    void* pal;
    ObjAffine* affine;
    s32 scaleX;
    s32 scaleY;

    if (BosBoogieDiceIsHeld(work)) {
        return;
    }

    flags = GetBattleSpritePriorityFlags(obj->y);

    if (StepHitFlash(obj)) {
        pal = work->palette2;
    } else {
        pal = work->palette;
    }

    scaleX = work->scaleX;

    if (scaleX > Q_8_8(1)) {
        scaleX = Q_8_8(1);
    }

    scaleY = work->scaleY;

    if (scaleY > Q_8_8(1)) {
        scaleY = Q_8_8(1);
    }

    affine = AllocObjAffine(0, scaleX, scaleY, FALSE);
    WorldToScreen(&x, &y, obj->x, obj->y, obj->z);
    DrawSprite(x, (work->y >> 8) + y, AnimGetGfx(&work->anim), work->tiles, pal,
        affine, flags, -0x1004 - (obj->y >> 8) * 4);
    TaskPoolDraw(&work->tasks);
}

void task_bos_boogie_dice_3(BoogieDiceWork* work) {
    if (!work->counted && gBosBoogieDiceBreakCount != 3 && !work->follower && work->state != BOS_BOOGIE_DICE_STATE_WAIT_CARD) {
        gBosBoogieDiceFaceReady = TRUE;
    }

    ColliderUnregister(&work->obj.collider);
    ReleaseEnemyBtlObj(&work->obj);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
    TaskPoolDestroy(&work->tasks);
}

void RollBoogieDice(BoogieDiceWork* work) {
    void* faces[6][3];
    u8 face;

    memcpy(faces, sBoogieDiceFaces, sizeof(faces));

    switch (GetRandom() % 4) {
    case 0:
        face = BOS_BOOGIE_DICE_FACE_HEAL;
        break;
    case 1:
        face = BOS_BOOGIE_DICE_FACE_KNIVES;
        break;
    case 2:
        face = BOS_BOOGIE_DICE_FACE_DISK;
        break;
    default:
        switch (GetRandom() % 3) {
        case 0:
            face = BOS_BOOGIE_DICE_FACE_GARGOYLES;
            break;
        case 1:
            face = BOS_BOOGIE_DICE_FACE_WIGHT_KNIGHTS;
            break;
        default:
            face = BOS_BOOGIE_DICE_FACE_SEARCH_GHOSTS;
            break;
        }

        break;
    }

    if (!work->follower) {
        gBosBoogieDiceFace = face;
    }

    AnimChangeWithTables(&work->anim, 0, 0, faces[face][0], faces[face][1]);
    SetObjTileSource(work->tiles, faces[face][2]);
}

u8 BosBoogieExplosiondiceIsHeld(BoogieExplosiondiceWork* work) {
    BoogieWork* boogie = work->boogie;

    if (boogie->animationIndex == 3 && AnimGetFrame(&boogie->anim) <= 2) {
        return TRUE;
    }

    return FALSE;
}

enum BosBoogieExplosiondiceState {
    BOS_BOOGIE_EXPLOSIONDICE_STATE_FALL,
    BOS_BOOGIE_EXPLOSIONDICE_STATE_HIDDEN,
    BOS_BOOGIE_EXPLOSIONDICE_STATE_EXPLODE
};

void task_bos_boogie_explosiondice_0(BoogieExplosiondiceWork* work, BoogieWork* arg) {
    BtlObj* player;

    work->boogie = arg;
    work->state = BOS_BOOGIE_EXPLOSIONDICE_STATE_FALL;
    work->timer = 0;
    work->vz = 0;
    work->speed = GetRandom() % 437 + 76;
    work->angle = GetRandom() % 128 + 0x40;
    player = gBtlWork->actor;
    work->obj.x = player->x;
    work->obj.y = player->y;
    work->obj.z = -0xA000;
    ColliderInit(&work->obj.collider, COLLIDER_TYPE_BOSS, sBosBoogieExplosiondiceEmyKind.radius, sBosBoogieExplosiondiceEmyKind.height);
    work->tiles = AllocObjTiles(GetMaxSpriteTileBytes(gBosBoogieExplosiondiceFrames, ARRAY_COUNT(gBosBoogieExplosiondiceFrames)), gBosBoogieExplosiondiceTiles);
    work->palette = LoadObjPalette(gBosBoogieDicePalette, sizeof(gBosBoogieDicePalette));
    work->palette2 = LoadObjPalette(gHitFlashPalette, sizeof(gHitFlashPalette));
    AnimInit(&work->anim, gBosBoogieExplosiondiceAnims, gBosBoogieExplosiondiceFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBosShadow, &work->obj);
}

u8 task_bos_boogie_explosiondice_1(BoogieExplosiondiceWork* work) {
    BtlObj* obj = &work->obj;

    if (BosBoogieExplosiondiceIsHeld(work)) {
        return 1;
    }

    switch (work->state) {
    case BOS_BOOGIE_EXPLOSIONDICE_STATE_FALL:
        work->vz += 51;
        obj->z += work->vz;

        if (obj->z > -0x2000) {
            BgFxStartExplosion(obj->x, obj->y + obj->z, 0);
            return 0;
        }

        break;
    case BOS_BOOGIE_EXPLOSIONDICE_STATE_EXPLODE:
        if (!BgFxIsActive()) {
            return 0;
        }

        break;
    }

    AnimUpdate(&work->anim);
    ColliderSetPosition(&obj->collider, obj->x, obj->y, obj->z);
    TaskPoolUpdate(&work->tasks);

    return 1;
}

void task_bos_boogie_explosiondice_2(BoogieExplosiondiceWork* work) {
    BtlObj* obj = &work->obj;
    u8 held = BosBoogieExplosiondiceIsHeld(work);
    s16 x;
    s16 y;
    u16 flags;
    void* pal;

    if (held || work->state == BOS_BOOGIE_EXPLOSIONDICE_STATE_HIDDEN) {
        return;
    }

    flags = GetBattleSpritePriorityFlags(obj->y);
    pal = work->palette;
    WorldToScreen(&x, &y, obj->x, obj->y, obj->z);
    DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, pal, NULL, flags,
        -0x1004 - (obj->y >> 8) * 4);
    TaskPoolDraw(&work->tasks);
}

void task_bos_boogie_explosiondice_3(BoogieExplosiondiceWork* work) {
    ColliderUnregister(&work->obj.collider);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
    TaskPoolDestroy(&work->tasks);
}

u8 BosBoogieIsActorPastSaku() {
    if (gBtlWork->actor->y <= 0x23EFF) {
        return TRUE;
    }

    return FALSE;
}

void task_bos_boogie_saku_0(BoogieSakuWork* work, BoogieWork* arg) {
    work->boogie = arg;
    work->tiles = LoadObjTiles(gSakuTiles, sizeof(gSakuTiles));
    work->palette = LoadObjPalette(gBoss02objPalette, sizeof(gBoss02objPalette));
    AnimInit(&work->anim, gSakuAnims, gSakuFrames);
    AnimStart(&work->anim, 0, 0);
    work->openTimer = 0;
    TaskPoolInit(&work->tasks, 1);
    work->task = NULL;
    work->closePending = FALSE;
}

u8 task_bos_boogie_saku_1(BoogieSakuWork* work) {
    u8 wasFinished;

    if (gBosBoogieDiceBreakCount > 2 && AnimIsFinished(&work->anim)) {
        if (work->openTimer < gBosBoogieSakuOpenTime) {
            if (work->openTimer == 0) {
                BtlMapStartShake();
            }

            work->openTimer++;
            SetBattleBounds(0x80, 0x170, 0x228, 0x278);

            if (BosBoogieIsActorPastSaku()) {
                SetBtlObjUnhittable(&work->boogie->actor, FALSE);
            } else {
                SetBtlObjUnhittable(&work->boogie->actor, TRUE);
            }
        } else if (work->boogie->state != BOS_BOOGIE_STATE_DEFEATED) {
            work->closePending = TRUE;
            gBosBoogieDiceBreakCount = 0;
            work->openTimer = 0;
            gBosBoogieSakuOpenTime = 0;
            SetBtlObjUnhittable(&work->boogie->actor, TRUE);

            if (BosBoogieIsActorPastSaku()) {
                work->task = TaskCreate(&work->tasks, &sTaskDescBosBoogieExplosiondice, work->boogie);
            }
        }
    }

    if (gBosBoogieDiceBreakCount <= 2 && !IsTaskActive(work->task)) {
        SetBattleBounds(0x80, 0x170, 0x240, 0x278);

        if (gBosBoogieDiceBreakCount != 0) {
            AnimChange(&work->anim, gBosBoogieDiceBreakCount, 0);
        } else if (work->closePending) {
            AnimChange(&work->anim, 3, 0);
            work->closePending = FALSE;
        }
    }

    wasFinished = AnimIsFinished(&work->anim);

    if (gBosBoogieDiceBreakCount > 2
            || (gBosBoogieDiceBreakCount == 0 && AnimGetId(&work->anim) == 3
                && !IsTaskActive(work->task))) {
        AnimUpdate(&work->anim);
    }

    if (!wasFinished && AnimIsFinished(&work->anim)) {
        m4aSongNumStart(SONG_BTL_BU_SAKU);

        if (AnimGetId(&work->anim) == 3) {
            AnimChange(&work->anim, 0, 0);
        }
    }

    TaskPoolUpdate(&work->tasks);

    return 1;
}

void BosBoogieSakuDrawAt(BoogieSakuWork* work, s32 px, u16 flags) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, px, 0x23F00, -0x2000);
    DrawSprite(x, y + 1, AnimGetGfx(&work->anim), work->tiles, work->palette, NULL, flags, 0xE700);
    TaskPoolDraw(&work->tasks);
}

void task_bos_boogie_saku_2(BoogieSakuWork* work) {
    u16 flags = GetBattleSpritePriorityFlags(0x23F00);

    BosBoogieSakuDrawAt(work, 0xA800, flags);
    BosBoogieSakuDrawAt(work, 0xF800, flags);
    BosBoogieSakuDrawAt(work, 0x14800, flags);
}

void task_bos_boogie_saku_3(BoogieSakuWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->tasks);
}

void task_bos_boogie_map_0(BoogieMapWork* work, BattleBackgroundDef* arg) {
    LoadBgTiles(0, arg->tiles, arg->tilesSize);
    LoadBgPalette(0, arg->palette, arg->paletteSize);
    SetBgMapBlocks(0, &arg->map, 2, 2);
    gBtlWork->scale = Q_8_8(1);
    gBtlWork->zoomScale = Q_8_8(1);
    gBtlWork->x = 0xF800;
    gBtlWork->y = 0x21000;
    gBtlWork->viewX = 0xF800;
    gBtlWork->viewY = 0x21000;
    gBtlWork->x2 = 0xF800;
    gBtlWork->y2 = 0x21000;
    gBtlWork->zoomX = 0xF800;
    gBtlWork->zoomY = 0x21000;
    gBtlWork->zoomSteps = 15;
    gBtlWork->rotation = 0;
    BtlMapResetShake();
    ScrollBgMapTo(0, gBtlWork->viewX >> 8, gBtlWork->viewY >> 8);
}

u8 task_bos_boogie_map_1() {
    s32 dx;
    s32 dy;

    BtlMapUpdateShake();
    dx = (gBtlWork->x2 - gBtlWork->x) >> 3;
    dy = (gBtlWork->y2 - gBtlWork->y) >> 3;

    if (dx > 0x500) {
        dx = 0x500;
    } else if (dx < -0x500) {
        dx = -0x500;
    }

    gBtlWork->x += dx;
    gBtlWork->y += dy;
    gBtlWork->viewX = gBtlWork->x;
    gBtlWork->viewY = gBtlWork->y;

    if (gBtlWork->viewX - ((DISPLAY_WIDTH / 2) << 8) < gBtlWork->xMin * 256) {
        gBtlWork->viewX = (gBtlWork->xMin + DISPLAY_WIDTH / 2) << 8;
    } else if (gBtlWork->viewX + ((DISPLAY_WIDTH / 2) << 8) > gBtlWork->xMax * 256) {
        gBtlWork->viewX = (gBtlWork->xMax - DISPLAY_WIDTH / 2) << 8;
    }

    if (gBtlWork->viewY - ((DISPLAY_HEIGHT / 2) << 8) < (BOS_BOOGIE_VIEW_Y_MIN << 8)) {
        gBtlWork->viewY = (BOS_BOOGIE_VIEW_Y_MIN + DISPLAY_HEIGHT / 2) << 8;
    } else if (gBtlWork->viewY + ((DISPLAY_HEIGHT / 2) << 8) > (BOS_BOOGIE_VIEW_Y_MAX << 8)) {
        gBtlWork->viewY = (BOS_BOOGIE_VIEW_Y_MAX - DISPLAY_HEIGHT / 2) << 8;
    }

    gBtlWork->viewY += BtlMapGetShake();
    ScrollBgMapTo(0, (gBtlWork->viewX >> 8) + 8, (gBtlWork->viewY >> 8) - 0x108);

    return 1;
}

void task_bos_boogie_mapanime_0(BoogieMapanimeWork* work) {
    BosMapanimeInit(&work->anims[0], &sBosBoogieMapanimeDef0);
    BosMapanimeInit(&work->anims[1], &sBosBoogieMapanimeDef1);
    BosMapanimeInit(&work->anims[2], &sBosBoogieMapanimeDef2);
}

u8 task_bos_boogie_mapanime_1(BoogieMapanimeWork* work) {
    u32 i;
    u8 defer = FALSE;

    for (i = gBosBoogieDiceBreakCount; i < ARRAY_COUNT(work->anims); i++) {
        defer = BosMapanimeUpdate(&work->anims[i], work->anims[i].def, defer);
    }

    return 1;
}

void task_bos_boogie_mapanime_2() {
}

void task_bos_boogie_mapanime_3() {
}

u8 ClampBoogieDiskPosition(s32* x, s32* y, s16 marginX, s16 offsetY, s32 z) {
    u8 clamped = FALSE;

    if (*x < (0x80 - marginX) << 8) {
        *x = (0x80 - marginX) << 8;
        clamped = TRUE;
    }

    if (*x > (marginX + 0x170) << 8) {
        *x = (marginX + 0x170) << 8;
        clamped = TRUE;
    }

    if (*y < (0x240 - offsetY) << 8) {
        *y = (0x240 - offsetY) << 8;
        clamped = TRUE;
    }

    if (*y > (0x278 - offsetY) << 8) {
        *y = (0x278 - offsetY) << 8;
        clamped = TRUE;
    }

    return clamped;
}

enum BosBoogieDiskState {
    BOS_BOOGIE_DISK_STATE_ATTACK,
    BOS_BOOGIE_DISK_STATE_KNOCKED_DOWN,
    BOS_BOOGIE_DISK_STATE_WAIT_CARD
};

void task_bos_boogie_disk_0(BoogieDiskWork* work, BtlObj* arg) {
    s32 x;
    s32 maxHp;
    s32 y;
    s32 z;

    work->state = BOS_BOOGIE_DISK_STATE_WAIT_CARD;
    work->timer = 0;
    work->angle = 0;
    work->vz = -0x200;

    if (gBtlWork->actor->x < 0xF800) {
        x = gBtlWork->actor->x + 0xF000;
        work->vx = -0x266;
    } else {
        x = gBtlWork->actor->x - 0xF000;
        work->vx = 0x266;
    }

    work->vy = 0x133;
    maxHp = arg->maxHp;

    if (arg->hp < (s16)(maxHp / 3)) {
        work->vx *= 3;
        work->vy *= 3;
    } else if (arg->hp < maxHp * 2 / 3) {
        work->vx *= 2;
        work->vy *= 2;
    }

    y = gBtlWork->actor->y;
    z = -0x1000;
    InitEnemyBtlObj(&work->obj, &sBosBoogieDiskEmyKind, x, y, z);
    work->obj.flags |= 0x400;
    work->tiles = AllocObjTiles(GetMaxSpriteTileBytes(gNokogiriFrames, ARRAY_COUNT(gNokogiriFrames)), gNokogiriTiles);
    work->palette = LoadObjPalette(gKaifukuPalette, sizeof(gKaifukuPalette));
    work->palette2 = LoadObjPalette(gHitFlashPalette, sizeof(gHitFlashPalette));
    AnimInit(&work->anim, gNokogiriAnims, gNokogiriFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBosShadow, &work->obj);
    RequestEnemyCardUse(&work->obj);
    m4aSongNumStart(SONG_BTL_BU_KAITEN);
}

u8 task_bos_boogie_disk_1(BoogieDiskWork* work) {
    BtlObj* obj = &work->obj;

    switch (UpdateBtlObjReaction(obj)) {
    case BTL_REACTION_CARD_ACTION:
        work->state = BOS_BOOGIE_DISK_STATE_ATTACK;
        work->timer = 0;
        break;
    case BTL_REACTION_HEALED:
    default:
        if (!ConsumeGimmickFlag(0)) {
            break;
        }

        BosBoogieApplyGimmick();
    case BTL_REACTION_HURT:
    case BTL_REACTION_DEFEATED:
    case BTL_REACTION_CARD_BROKEN:
    case BTL_REACTION_STUNNED:
    case BTL_REACTION_GRAVITY:
    case BTL_REACTION_GRAVITY_DEFEATED:
        if (work->state != BOS_BOOGIE_DISK_STATE_KNOCKED_DOWN) {
            work->state = BOS_BOOGIE_DISK_STATE_KNOCKED_DOWN;
            work->timer = 0;
        }

        break;
    }

    switch (work->state) {
    case BOS_BOOGIE_DISK_STATE_ATTACK:
        obj->y += work->vy;

        if (ClampBoogieDiskPosition(&obj->x, &obj->y, 0x20, -0x10, obj->z)) {
            work->vy = -work->vy;
        }

        obj->x += work->vx;

        if ((work->vx > 0 && obj->x > 0x19000)
                || (work->vx <= 0 && obj->x < 0x6000)) {
            ClearBtlObjActionFlags(obj);

            return 0;
        }

        if (ApplyAttackBox(0x105, obj->x, obj->y, obj->z, 0x20, 0x10, 1) == ATTACK_RESULT_HIT) {
            gBosBoogieAttackHit = TRUE;
            m4aSongNumStart(SONG_BTL_MON_SWORD01);
        }

        break;
    case BOS_BOOGIE_DISK_STATE_KNOCKED_DOWN:
        if (obj->z >= 0) {
            gBosBoogieTaskKnockedDown = TRUE;
            ClearBtlObjActionFlags(obj);

            return 0;
        }

        work->timer++;
        obj->x -= work->vx;
        work->angle += 0x19;
        obj->z += work->vz;
        work->vz += 0x42;

        if (obj->z > 0) {
            obj->z = 0;
        }

        break;
    case BOS_BOOGIE_DISK_STATE_WAIT_CARD:
        if ((s16)work->timer > 30) {
            return 0;
        }

        work->timer++;
        break;
    }

    AnimUpdate(&work->anim);
    ColliderSetPosition(&obj->collider, obj->x, obj->y, obj->z);
    TaskPoolUpdate(&work->tasks);

    return 1;
}

void task_bos_boogie_disk_2(BoogieDiskWork* work) {
    BtlObj* obj = &work->obj;
    s16 x;
    s16 y;
    u16 flags = GetBattleSpritePriorityFlags(obj->y);
    void* pal = work->palette;
    ObjAffine* affine = AllocObjAffineAngle(work->angle, TRUE);

    WorldToScreen(&x, &y, obj->x, obj->y, obj->z);
    DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, pal, affine, flags,
        -0x1004 - (obj->y >> 8) * 4);
    TaskPoolDraw(&work->tasks);
}

void task_bos_boogie_disk_3(BoogieDiskWork* work) {
    ReleaseEnemyBtlObj(&work->obj);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
    TaskPoolDestroy(&work->tasks);
}

void BosBoogieKnifeAttack(BoogieKnifeWork* work) {
    BtlObj* obj = &work->obj;
    s32 offsetX;

    if (gBosBoogieKnivesMoveRight) {
        work->scaleX = Q_8_8(1);
        work->drawOffsetX = 0;
        offsetX = 0x2000;
    } else {
        work->scaleX = Q_8_8(-1);
        work->drawOffsetX = 0;
        offsetX = -0x2000;
    }

    if (ApplyAttackBox(0x106, obj->x - offsetX, obj->y, obj->z - 0x1000, 4, 0x1C, 0x10) == ATTACK_RESULT_HIT) {
        gBosBoogieAttackHit = TRUE;
        m4aSongNumStart(SONG_EF_KU_ATT04);
    }
}

enum BosBoogieKnifeState {
    BOS_BOOGIE_KNIFE_STATE_DROP,
    BOS_BOOGIE_KNIFE_STATE_HOP,
    BOS_BOOGIE_KNIFE_STATE_RETRACT
};

void task_bos_boogie_knife_0(BoogieKnifeWork* work, s32* arg) {
    BtlObj* boogieActor;
    s32 maxHp;

    work->state = BOS_BOOGIE_KNIFE_STATE_DROP;
    work->timer = 0;

    if (gBosBoogieKnivesMoveRight) {
        work->vx = 0x133;
    } else {
        work->vx = -0x133;
    }

    work->vz = 0;
    work->gravity = 0x42;
    work->bounceVz = -0x500;
    boogieActor = gBosBoogieActor;
    maxHp = boogieActor->maxHp;

    if (boogieActor->hp < (s16)(maxHp / 3)) {
        work->gravity = (work->gravity * 0x300) >> 8;
        work->bounceVz = -0xA00;
    } else if (boogieActor->hp < maxHp * 2 / 3) {
        work->gravity = (work->gravity * 0x200) >> 8;
        work->bounceVz = -0x780;
    }

    work->obj.y = 0x25C00;
    work->obj.z = -0xC000;
    work->obj.x = *arg;
    ColliderInit(&work->obj.collider, COLLIDER_TYPE_BOSS, sBosBoogieKnifeEmyKind.radius, sBosBoogieKnifeEmyKind.height);
    work->tiles = LoadObjTiles(gKnifeTiles, sizeof(gKnifeTiles));
    work->palette = LoadObjPalette(gKnifePalette, sizeof(gKnifePalette));
    work->palette2 = LoadObjPalette(gHitFlashPalette, sizeof(gHitFlashPalette));
    AnimInit(&work->anim, gKnifeAnims, gKnifeFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
}

u8 task_bos_boogie_knife_1(BoogieKnifeWork* work) {
    BtlObj* obj = &work->obj;

    if (gBosBoogieKnivesRetract) {
        work->state = BOS_BOOGIE_KNIFE_STATE_RETRACT;
    }

    switch (work->state) {
    case BOS_BOOGIE_KNIFE_STATE_DROP:
        obj->z += work->vz;
        work->vz += work->gravity;

        if (obj->z < 0) {
            BosBoogieKnifeAttack(work);
        } else {
            obj->z = 0;
            work->state = BOS_BOOGIE_KNIFE_STATE_HOP;
            work->vz = work->bounceVz;
        }

        break;
    case BOS_BOOGIE_KNIFE_STATE_HOP:
        obj->x += work->vx;
        obj->z += work->vz;
        work->vz += work->gravity;
        work->timer++;

        if (obj->z < 0) {
            BosBoogieKnifeAttack(work);
        } else {
            obj->z = 0;
            work->vz = work->bounceVz;

            if ((s16)work->timer > 199.99999f) {
                work->state = BOS_BOOGIE_KNIFE_STATE_RETRACT;
            } else {
                BosBoogieKnifeAttack(work);
            }
        }

        break;
    case BOS_BOOGIE_KNIFE_STATE_RETRACT:
        obj->z -= 0x800;

        if (obj->z < -0xC000) {
            return 0;
        }

        break;
    }

    AnimUpdate(&work->anim);
    ColliderSetPosition(&obj->collider, obj->x, obj->y, obj->z);

    return 1;
}

void task_bos_boogie_knife_2(BoogieKnifeWork* work) {
    BtlObj* obj = &work->obj;
    s16 x;
    s16 y;
    u16 flags;
    void* pal;
    ObjAffine* affine;

    WorldToScreen(&x, &y, obj->x + work->drawOffsetX, obj->y - 0x2400, obj->z);

    if ((u16)(x + 0x20) > 0x130) {
        return;
    }

    flags = GetBattleSpritePriorityFlags(obj->y);

    if (gBosBoogieKnivesRetract && (gFrameCounter & 1) != 0 && !gBtlWork->paused) {
        pal = work->palette2;
    } else {
        pal = work->palette;
    }

    affine = AllocObjAffine(0, work->scaleX, Q_8_8(1), FALSE);
    DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, pal, affine, flags,
        -0x1004 - (obj->y >> 8) * 4);
}

void task_bos_boogie_knife_3(BoogieKnifeWork* work) {
    ColliderUnregister(&work->obj.collider);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
}

u8 BosBoogieKnifeIsLanded(BoogieKnifeWork* work) {
    if (work->obj.z >= 0) {
        return TRUE;
    }

    return FALSE;
}

u8 BosBoogieAnyKnifeActive(BoogieKnifereaderWork* work) {
    s32 i;

    for (i = 0; i <= 4; i++) {
        if (IsTaskActive(work->knives[i])) {
            return TRUE;
        }
    }

    return FALSE;
}

void BosBoogieSpawnKnives(BoogieKnifereaderWork* work) {
    s32 i;
    s32 x;

    if (GetRandom() % 16 > 7) {
        gBosBoogieKnivesMoveRight = TRUE;
        x = -0x4000;

        for (i = 0; i <= 4; i++) {
            work->knives[i] = TaskCreate(&work->tasks, &sTaskDescBosBoogieKnife, &x);
            x += 0x6800;
        }
    } else {
        gBosBoogieKnivesMoveRight = FALSE;
        x = 0x23000;

        for (i = 0; i <= 4; i++) {
            work->knives[i] = TaskCreate(&work->tasks, &sTaskDescBosBoogieKnife, &x);
            x += -0x6800;
        }
    }
}

enum BosBoogieKnifereaderState {
    BOS_BOOGIE_KNIFEREADER_STATE_ATTACK,
    BOS_BOOGIE_KNIFEREADER_STATE_RETRACT,
    BOS_BOOGIE_KNIFEREADER_STATE_WAIT_CARD
};

void task_bos_boogie_knifereader_0(BoogieKnifereaderWork* work) {
    s32 i;

    work->state = BOS_BOOGIE_KNIFEREADER_STATE_WAIT_CARD;
    work->timer = 0;
    gBosBoogieKnivesRetract = FALSE;
    TaskPoolInit(&work->tasks, 5);

    for (i = 0; i < 5; i++) {
        work->knives[i] = NULL;
    }

    InitEnemyBtlObj(&work->obj, &sBosBoogieKnifereaderEmyKind, 0xF800, 0x24000, 0);
    SetBtlObjUnhittable(&work->obj, TRUE);
    RequestEnemyCardUse(&work->obj);
}

u8 task_bos_boogie_knifereader_1(BoogieKnifereaderWork* work) {
    s32 i;
    BtlObj* obj = &work->obj;
    void* pool;
    s32 checkKnives;

    switch (UpdateBtlObjReaction(obj)) {
    case BTL_REACTION_CARD_ACTION:
        work->state = BOS_BOOGIE_KNIFEREADER_STATE_ATTACK;
        work->timer = 0;
        break;
    case BTL_REACTION_HEALED:
    default:
        if (!ConsumeGimmickFlag(0)) {
            break;
        }

        BosBoogieApplyGimmick();
    case BTL_REACTION_HURT:
    case BTL_REACTION_DEFEATED:
    case BTL_REACTION_CARD_BROKEN:
    case BTL_REACTION_STUNNED:
    case BTL_REACTION_GRAVITY:
    case BTL_REACTION_GRAVITY_DEFEATED:
        if (work->state != BOS_BOOGIE_KNIFEREADER_STATE_RETRACT) {
            work->state = BOS_BOOGIE_KNIFEREADER_STATE_RETRACT;
            work->timer = 0;
        }

        break;
    }

    switch (work->state) {
    case BOS_BOOGIE_KNIFEREADER_STATE_WAIT_CARD:
        if ((s16)work->timer > 30) {
            return 0;
        }

        work->timer++;
        checkKnives = FALSE;
        break;
    case BOS_BOOGIE_KNIFEREADER_STATE_RETRACT:
        gBosBoogieKnivesRetract = TRUE;
        checkKnives = TRUE;
        break;
    case BOS_BOOGIE_KNIFEREADER_STATE_ATTACK:
        if ((s16)work->timer == 0) {
            work->timer++;
            BosBoogieSpawnKnives(work);
            checkKnives = FALSE;
            break;
        }
    default:
        checkKnives = TRUE;
        break;
    }

    if (!checkKnives) {
        pool = &work->tasks;
        TaskPoolUpdate(pool);
        return 1;
    }

    if (!BosBoogieAnyKnifeActive(work)) {
        ClearBtlObjActionFlags(obj);

        return 0;
    }

    for (i = 0; i <= 4; i++) {
        pool = &work->tasks;

        if (IsTaskActive(work->knives[i])) {
            if (BosBoogieKnifeIsLanded(work->knives[i]->work)) {
                m4aSongNumStart(SONG_BTL_BU_TRAP);
            }

            break;
        }
    }

    TaskPoolUpdate(pool);

    return 1;
}

void task_bos_boogie_knifereader_2(BoogieKnifereaderWork* work) {
    TaskPoolDraw(&work->tasks);
}

void task_bos_boogie_knifereader_3(BoogieKnifereaderWork* work) {
    ReleaseEnemyBtlObj(&work->obj);
    TaskPoolDestroy(&work->tasks);
}

enum BosBoogieKaihukuState {
    BOS_BOOGIE_KAIHUKU_STATE_HEAL,
    BOS_BOOGIE_KAIHUKU_STATE_KNOCKED_DOWN,
    BOS_BOOGIE_KAIHUKU_STATE_WAIT_CARD
};

void task_bos_boogie_kaihuku_0(BoogieKaihukuWork* work, BoogieWork* arg) {
    s32 x;
    s32 y;
    s32 z;

    work->state = BOS_BOOGIE_KAIHUKU_STATE_WAIT_CARD;
    work->timer = 0;
    work->boogie = arg;
    work->vz = 0;
    x = arg->actor.x;
    y = arg->actor.y + 0x100;
    z = arg->actor.z - 0x7C00;
    InitEnemyBtlObj(&work->obj, &sBosBoogieKaihukuEmyKind, x, y, z);
    work->obj.flags |= 0x400;
    work->tiles = LoadObjTiles(gKaifukuTiles, sizeof(gKaifukuTiles));
    work->palette = LoadObjPalette(gKaifukuPalette, sizeof(gKaifukuPalette));
    work->palette2 = LoadObjPalette(gHitFlashPalette, sizeof(gHitFlashPalette));
    AnimInit(&work->anim, gKaifukuAnims, gKaifukuFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
    RequestEnemyCardUse(&work->obj);
}

u8 task_bos_boogie_kaihuku_1(BoogieKaihukuWork* work) {
    BtlObj* obj = &work->obj;
    BoogieWork* boogie = work->boogie;
    BtlObj* boogieActor = &boogie->actor;

    switch (UpdateBtlObjReaction(obj)) {
    case BTL_REACTION_CARD_ACTION:
        work->state = BOS_BOOGIE_KAIHUKU_STATE_HEAL;
        work->timer = 0;
        break;
    case BTL_REACTION_HEALED:
    default:
        if (!ConsumeGimmickFlag(0)) {
            break;
        }

        BosBoogieApplyGimmick();
    case BTL_REACTION_HURT:
    case BTL_REACTION_DEFEATED:
    case BTL_REACTION_CARD_BROKEN:
    case BTL_REACTION_STUNNED:
    case BTL_REACTION_GRAVITY:
    case BTL_REACTION_GRAVITY_DEFEATED:
        if (work->state != BOS_BOOGIE_KAIHUKU_STATE_KNOCKED_DOWN) {
            work->state = BOS_BOOGIE_KAIHUKU_STATE_KNOCKED_DOWN;
            work->timer = 0;
        }

        break;
    }

    switch (work->state) {
    case BOS_BOOGIE_KAIHUKU_STATE_HEAL:
        BtlMapSetCameraTarget(obj->x, obj->y + obj->z);

        if ((s16)work->timer == 0) {
            BgFxStartBoogieKaihuku(obj->x, obj->y, obj->z + 0x2800, Q_8_8(1.6));
            m4aSongNumStart(SONG_BTL_BU_KAIFUKU);
            work->timer++;
            break;
        }

        if (BgFxIsActive()) {
            break;
        }

        CreateBtlPopTask(boogieActor, BTL_POP_RECOVER);
        boogie = work->boogie;
        boogie->actor.hp += boogie->actor.maxHp / 16;
        boogie = work->boogie;

        if (boogie->actor.hp > boogie->actor.maxHp) {
            boogie->actor.hp = boogie->actor.maxHp;
        }

        return 0;
    case BOS_BOOGIE_KAIHUKU_STATE_KNOCKED_DOWN:
        if (obj->z >= 0) {
            gBosBoogieTaskKnockedDown = TRUE;
            ClearBtlObjActionFlags(obj);

            return 0;
        }

        work->timer++;
        obj->z += work->vz;
        work->vz += 0x42;

        if (obj->z < -0x2000) {
            obj->z = 0;
        }

        break;
    case BOS_BOOGIE_KAIHUKU_STATE_WAIT_CARD:
        if ((s16)work->timer > 30) {
            return 0;
        }

        work->timer++;
        break;
    }

    AnimUpdate(&work->anim);
    ColliderSetPosition(&obj->collider, obj->x, obj->y, obj->z);

    return 1;
}

void task_bos_boogie_kaihuku_2(BoogieKaihukuWork* work) {
    BtlObj* obj = &work->obj;
    void* pal;
    u16 flags;
    s16 x;
    s16 y;

    if (work->state != BOS_BOOGIE_KAIHUKU_STATE_WAIT_CARD) {
        flags = GetBattleSpritePriorityFlags(obj->y);
        pal = work->palette;
        WorldToScreen(&x, &y, obj->x, obj->y, obj->z);
        DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, pal, NULL, flags, -0x1004 - (obj->y >> 8) * 4);
    }
}

void task_bos_boogie_kaihuku_3(BoogieKaihukuWork* work) {
    ReleaseEnemyBtlObj(&work->obj);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
}
