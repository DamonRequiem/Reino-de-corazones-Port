/**
 * smn_king.c
 * King Mickey Summon
 */

#include "task_descriptors.h"
#include "smn.h"
#include "anim.h"
#include "sprites_smn.h"
#include "btl_api.h"
#include "fade.h"
#include "songs.h"
#include "smn_tasks.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_collision.h"
#include "btl_effect.h"
#include "card_battle.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "sprite_palettes.h"
#include "btl.h"

static const AnimDef sSmnKingAnimDefs[3] = {
    { gMickey10Frames, gMickey10Anims, gMickey10Tiles, 0 },
    { gMickey10Frames, gMickey10Anims, gMickey10Tiles, 1 },
    { gMickey10Frames, gMickey10Anims, gMickey10Tiles, 2 },
};

enum SmnKingState {
    SMN_KING_STATE_APPEAR,
    SMN_KING_STATE_VANISH,
    SMN_KING_STATE_FALL,
    SMN_KING_STATE_FLASH = 4,
    SMN_KING_STATE_WAIT
};

void task_smn_king_0(SmnKingWork* work, SmnArgs* args) {
    BtlObj* body;
    BtlObj* actor;

    body = &work->body;

    if (args->mainSide) {
        work->mainSide = TRUE;
        gBtlWork->flags |= BTL_FLAG_SUMMON_ACTIVE;
        actor = gBtlWork->actor;
        work->tiles = gBtlWork->tiles;
    } else {
        work->mainSide = args->mainSide;
        gRikuBtlWork->flags |= BTL_FLAG_SUMMON_ACTIVE;
        actor = gRikuBtlWork->actor;
        work->tiles = gRikuBtlWork->tiles;
    }

    body->x = actor->originX;
    body->y = actor->originY;
    body->z = actor->originZ - 0x4000;
    body->groundZ = 0;
    body->flags = actor->flags & BTLOBJ_FLAG_FACING_LEFT;
    work->variant = args->variant;
    work->palette = LoadObjPalette(gMickeyPalette, sizeof(gMickeyPalette));
    work->vz = 0;
    AnimInit(&work->anim, NULL, NULL);
    AnimChangeWithDef(sSmnKingAnimDefs, &work->anim, 0, 0, work->tiles);
    work->state = SMN_KING_STATE_APPEAR;
    work->stateTimer = 0;
    work->steps = 0;
    work->unk_14C = 0;
    work->scale = 10;
    work->animating = FALSE;
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBtlShadow, body);
}

u8 SmnKingApplyGravity(SmnKingWork* work) {
    BtlObj* body;

    body = &work->body;
    ApplyBattleBounds(&body->x, &body->y, &body->z, &body->groundZ);
    body->z += work->vz;
    work->vz += 0x33;

    if (body->z > body->groundZ) {
        body->z = body->groundZ;
        work->vz = 0;
        return TRUE;
    }

    return FALSE;
}

u8 task_smn_king_1(SmnKingWork* work) {
    BtlObj* body = &work->body;
    BtlWork* owner;
    owner = work->mainSide ? gBtlWork : gRikuBtlWork;

    if (owner->flags & BTL_FLAG_DISMISS_SUMMONS) {
        return 0;
    }

    BtlMapFollowPosition(body->x, body->y, body->z);

    switch (work->state) {
    case SMN_KING_STATE_APPEAR:
        if (work->stateTimer == 0) {
            work->steps = 30;
            BgFxStartSummon(body->x, body->y, body->z);
            m4aSongNumStart(SONG_EF_SUMMON_UP);
        }

        ApproachValue(&work->scale, Q_8_8(1), work->steps);

        if (work->steps <= 0) {
            work->state = SMN_KING_STATE_FALL;
            work->stateTimer = 0;
            work->animating = TRUE;
        } else {
            STEP_STATE(work);
        }

        break;
    case SMN_KING_STATE_VANISH:
        if (work->stateTimer == 0) {
            work->steps = 30;
            BgFxStartSummon(body->x, body->y, body->z);
            m4aSongNumStart(SONG_EF_SUMMON_DOWN);
        }

        ApproachValue(&work->scale, Q_8_8(0.1), work->steps);

        if (work->steps <= 0) {
            return 0;
        }

        STEP_STATE(work);
        break;
    case SMN_KING_STATE_FALL:
        AnimChangeWithDef(sSmnKingAnimDefs, &work->anim, 1, 0, work->tiles);

        if (SmnKingApplyGravity(work)) {
            work->state = SMN_KING_STATE_FLASH;
            work->stateTimer = 0;
            FadeToAmount(FADE_MODE_BLACK, gBtlWork->fadeAmount, 8);
        }

        break;
    case SMN_KING_STATE_FLASH:
        AnimChangeWithDef(sSmnKingAnimDefs, &work->anim, 2, 0, work->tiles);

        if (AnimGetFrame(&work->anim) == 5 && work->anim.timer == 3) {
            BgFxStartFlash(body->x, body->y, body->z - 0x1300);
            ApplyAttackBox(3, body->x, body->y, body->z, 256, 256, 256);
            m4aSongNumStart(SONG_EF_TLIMIT01);

            switch (work->variant) {
            case SUMMON_LEVEL_SINGLE:
                gBtlWork->actor->hp += gBtlWork->actor->maxHp / 5;
                RequestSoraKingReload0();
                break;
            case SUMMON_LEVEL_PAIR:
                gBtlWork->actor->hp += gBtlWork->actor->maxHp / 2;
                RequestSoraKingReload1();
                break;
            case SUMMON_LEVEL_TRIPLE:
            default:
                gBtlWork->actor->hp += gBtlWork->actor->maxHp;
                RequestSoraKingReload2();
                break;
            }

            CreateBtlPopTask(gBtlWork->actor, BTL_POP_RECOVER);

            if (gBtlWork->actor->hp > gBtlWork->actor->maxHp) {
                gBtlWork->actor->hp = gBtlWork->actor->maxHp;
            }
        }

        ApplyBattleBounds(&body->x, &body->y, &body->z, &body->groundZ);

        if (AnimIsFinished(&work->anim)) {
            work->state = SMN_KING_STATE_WAIT;
            work->stateTimer = 0;
        }

        break;
    case SMN_KING_STATE_WAIT:
        ApplyBattleBounds(&body->x, &body->y, &body->z, &body->groundZ);

        if (work->stateTimer > 60) {
            FadeToOriginal(FADE_MODE_BLACK, 8);
            work->state = SMN_KING_STATE_VANISH;
            work->stateTimer = 0;
        } else {
            work->stateTimer++;
        }

        break;
    }

    if (body->z > body->groundZ) {
        body->z = body->groundZ;
    }

    if (work->animating) {
        AnimUpdate(&work->anim);
    }

    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_smn_king_2(SmnKingWork* work) {
    BtlObj* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    ObjAffine* affine;
    s32 sclX;
    s32 sclY;

    body = &work->body;
    gfx = AnimGetGfx(&work->anim);
    flags = GetBattleSpritePriorityFlags(body->y);

    if (body->flags & BTLOBJ_FLAG_FACING_LEFT) {
        sclY = gBtlWork->scale;
        sclX = sclY;
    } else if (gBtlWork->scale == Q_8_8(1) && work->scale == gBtlWork->scale) {
        sclY = work->scale;
        sclX = sclY;
        flags |= SPRITE_FLAG_HFLIP;
    } else {
        sclX = -gBtlWork->scale;
        sclY = gBtlWork->scale;
    }

    sclX = sclX * work->scale >> 8;
    sclY = sclY * work->scale >> 8;

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (sclX <= Q_8_8(1) && sclY <= Q_8_8(1)) {
        affine = AllocObjAffine(0, sclX, sclY, FALSE);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, TRUE);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->shadowPriority = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->tasks);
}

void task_smn_king_3(SmnKingWork* work) {
    BtlWork* owner;

    owner = work->mainSide ? gBtlWork : gRikuBtlWork;
    owner->flags &= ~BTL_FLAG_SUMMON_ACTIVE;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->tasks);
}

TaskDesc gTaskDescSmnKing = {
    "task_smn_king",
    (TaskInitFunc)task_smn_king_0,
    (TaskUpdateFunc)task_smn_king_1,
    (TaskDrawFunc)task_smn_king_2,
    (TaskDestroyFunc)task_smn_king_3,
    sizeof(SmnKingWork),
};
