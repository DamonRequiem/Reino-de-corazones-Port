/**
 * frd_pooh.c
 * Winnie the Pooh Battle Ally
 */

#include "frd_pooh.h"
#include "sprites_pooh.h"
#include "btl_api.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_collision.h"
#include "btl_effect.h"
#include "engine_math.h"
#include "obj.h"
#include "obj_api.h"
#include <stddef.h>
#include "task_descriptors.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"

#ifdef VERSION_EU

static const AnimDef sFrdPoohAnimDefsEu[18] = {
    { gPoohFf01Frames, gPoohFf01Anims, gPoohFf01Tiles, 0 },
    { gPoohFr01Frames, gPoohFr01Anims, gPoohFr01Tiles, 0 },
    { gPoohRr01Frames, gPoohRr01Anims, gPoohRr01Tiles, 0 },
    { gPoohBr01Frames, gPoohBr01Anims, gPoohBr01Tiles, 0 },
    { gPoohBb01Frames, gPoohBb01Anims, gPoohBb01Tiles, 0 },
    { gPoohLl10Frames, gPoohLl10Anims, gPoohLl10Tiles, 0 },
    { gPoohBl07Frames, gPoohBl07Anims, gPoohBl07Tiles, 0 },
    { gPoohLl04Frames, gPoohLl04Anims, gPoohLl04Tiles, 0 },
    { gPoohLl04aFrames, gPoohLl04aAnims, gPoohLl04aTiles, 0 },
    { gPoohFl06Frames, gPoohFl06Anims, gPoohFl06Tiles, 0 },
    { gPoohFf00Frames, gPoohFf00Anims, gPoohFf00Tiles, 0 },
    { gPoohFf00FrFrames, gPoohFf00FrAnims, gPoohFf00FrTiles, 0 },
    { gPoohFf00RrFrames, gPoohFf00RrAnims, gPoohFf00RrTiles, 0 },
    { gPoohBb00BrFrames, gPoohBb00BrAnims, gPoohBb00BrTiles, 0 },
    { gPoohBb00Frames, gPoohBb00Anims, gPoohBb00Tiles, 0 },
    { gPoohBb00BlFrames, gPoohBb00BlAnims, gPoohBb00BlTiles, 0 },
    { gPoohFf00LlFrames, gPoohFf00LlAnims, gPoohFf00LlTiles, 0 },
    { gPoohFf00FlFrames, gPoohFf00FlAnims, gPoohFf00FlTiles, 0 },
};

u8 FrdPoohApplyGravity(FrdPoohWork* work) {
    FrdPoohBody* body;
    body = &work->body;
    ApplyBattleBounds(&body->x, &body->y, &body->z, &body->ground);
    body->z += work->velocity;
    work->velocity += 0x33;

    if (body->z > body->ground) {
        body->z = body->ground;
        work->velocity = 0;
        return TRUE;
    }

    return FALSE;
}

enum FrdPoohState {
    FRD_POOH_STATE_WANDER,
    FRD_POOH_STATE_APPROACH,
    FRD_POOH_STATE_RIDE,
    FRD_POOH_STATE_JUMP_OFF,
    FRD_POOH_STATE_RECOVER,
    FRD_POOH_STATE_BEAM_CHARGE,
    FRD_POOH_STATE_BEAM
};

void task_frd_pooh_0(FrdPoohWork* work, FrdPoohArgs* args) {
    FrdPoohBody* body;
    body = &work->body;

    if (args->side) {
        work->side = TRUE;
        gBtlWork->flags |= BTL_FLAG_SUMMON_ACTIVE;
        work->actor = gBtlWork->actor;
        work->tiles = gBtlWork->tiles2;
    } else {
        work->side = args->side;
        gRikuBtlWork->flags |= BTL_FLAG_SUMMON_ACTIVE;
        work->actor = gRikuBtlWork->actor;
        work->tiles = gBtlWork->tiles2;
    }

    work->card = args->card;
    work->counter = 0;
    work->velocity = 0;

    if (work->actor->flags & BTLOBJ_FLAG_FACING_LEFT) {
        body->x = (gBtlWork->xMax + 48) * 256;
        body->flags = BTLOBJ_FLAG_FACING_LEFT;
    } else {
        body->x = (gBtlWork->xMin - 48) * 256;
        body->flags = 0;
    }

    body->y = work->actor->y;
    body->z = 0;
    body->ground = 0;
    work->state = FRD_POOH_STATE_WANDER;
    work->targetX = work->actor->x;
    work->targetY = work->actor->y;
    work->palette = LoadObjPalette(gPoohPalette, sizeof(gPoohPalette));
    AnimInit(&work->anim, NULL, NULL);
    AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 0, 0, work->tiles);
    ColliderInit(&body->collider, COLLIDER_TYPE_ENEMY, 10, 32);
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBtlShadow, body);
}

u8 task_frd_pooh_1(FrdPoohWork* work) {
    FrdPoohBody* body;
    BtlWork* owner;
    body = &work->body;
    owner = work->side ? gBtlWork : gRikuBtlWork;

    if (owner->flags & BTL_FLAG_DISMISS_SUMMONS) {
        return 0;
    }

    BtlMapFollowPosition(body->x, body->y, body->z);

    switch (work->state) {
    case FRD_POOH_STATE_WANDER: {
        s32 flip = FALSE;
        u8 angle = GetAngle(body->x, body->y, work->targetX, work->targetY);

        switch (((angle + 16) & 255) >> 5) {
        case 0:
            AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 4, ANIM_FLAG_LOOP, work->tiles);
            flip = TRUE;
            break;
        case 1:
            AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 3, ANIM_FLAG_LOOP, work->tiles);
            flip = TRUE;
            break;
        case 2:
            AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 2, ANIM_FLAG_LOOP, work->tiles);
            flip = TRUE;
            break;
        case 3:
            AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 1, ANIM_FLAG_LOOP, work->tiles);
            flip = TRUE;
            break;
        case 4:
            AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 0, ANIM_FLAG_LOOP, work->tiles);
            flip = FALSE;
            break;
        case 5:
            AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 1, ANIM_FLAG_LOOP, work->tiles);
            flip = FALSE;
            break;
        case 6:
            AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 2, ANIM_FLAG_LOOP, work->tiles);
            flip = FALSE;
            break;
        case 7:
            AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 3, ANIM_FLAG_LOOP, work->tiles);
            flip = FALSE;
            break;
        }

        if (flip) body->flags |= BTLOBJ_FLAG_FACING_LEFT;
        else body->flags &= ~BTLOBJ_FLAG_FACING_LEFT;

        body->x += gSineTable[angle] * 128 >> 8;
        body->y += -gSineTable[angle + 64] * 128 >> 8;
        ApplyAttackBox(110, body->x, body->y, body->z, 20, 10, 64);

        if ((body->x - work->targetX >= 0 ? body->x - work->targetX : work->targetX - body->x) < 0x800 &&
            (body->y - work->targetY >= 0 ? body->y - work->targetY : work->targetY - body->y) < 0x800) {
            work->targetX = (gBtlWork->xMin + GetRandom() % (gBtlWork->xMax - gBtlWork->xMin + 1)) * 256;
            work->targetY = (gBtlWork->yMin + GetRandom() % (gBtlWork->yMax - gBtlWork->yMin + 1)) * 256;
        }

        if ((u16)(GetRandom() % 300u) == 0) work->state = FRD_POOH_STATE_APPROACH;

        break;
    }
    case FRD_POOH_STATE_APPROACH: {
        u8 angle;
        work->targetX = work->actor->x;
        work->targetY = work->actor->y;
        AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 5, ANIM_FLAG_LOOP, work->tiles);
        angle = GetAngle(body->x, body->y, work->targetX, work->targetY);

        if (work->targetX < body->x) body->flags |= BTLOBJ_FLAG_FACING_LEFT;
        else body->flags &= ~BTLOBJ_FLAG_FACING_LEFT;

        body->x += gSineTable[angle] * 0x133 >> 8;
        body->y += -gSineTable[angle + 64] * 0x133 >> 8;
        ApplyAttackBox(110, body->x, body->y, body->z, 20, 10, 64);

        if (ColliderIsTouchingType(&body->collider, COLLIDER_TYPE_PLAYER)) {
            work->state = FRD_POOH_STATE_RIDE;
            ColliderSetDisabled(&body->collider, TRUE);
            work->bob = 0;
        }

        break;
    }
    case FRD_POOH_STATE_RIDE:
        AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 6, 0, work->tiles);

        if (AnimIsFinished(&work->anim)) {
            if (work->actor->flags & BTLOBJ_FLAG_FACING_LEFT) body->flags |= BTLOBJ_FLAG_FACING_LEFT;
            else body->flags &= ~BTLOBJ_FLAG_FACING_LEFT;

            if ((u16)(GetRandom() % 200u) == 0) work->state = FRD_POOH_STATE_BEAM_CHARGE;
        }

        if (body->flags & BTLOBJ_FLAG_FACING_LEFT) body->x = work->actor->x + 0xA00;
        else body->x = work->actor->x - 0xA00;

        body->y = work->actor->y + 0x800;
        body->z = work->actor->z + work->bob;
        work->bob += (-0x1C00 - work->bob) >> 3;
        break;
    case FRD_POOH_STATE_BEAM_CHARGE:
        AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 9, 0, work->tiles);

        if (work->actor->flags & BTLOBJ_FLAG_FACING_LEFT) body->flags |= BTLOBJ_FLAG_FACING_LEFT;
        else body->flags &= ~BTLOBJ_FLAG_FACING_LEFT;

        body->x = work->actor->x;
        body->y = work->actor->y + 0x800;
        body->z = work->actor->z + work->bob - 0xC00;

        if (work->counter > 180) {
            work->state = FRD_POOH_STATE_BEAM;
            work->counter = 120;
            work->animcounter = 0;
            work->scale = 0;
            BgFxStartJfMajinBeam(body->x, body->y, body->z - 0x1A00, Q_8_8(1.5), 0x80, 80);
        } else work->counter++;

        break;
    case FRD_POOH_STATE_BEAM: {
        s32 frame;

        if (work->actor->flags & BTLOBJ_FLAG_FACING_LEFT) body->flags |= BTLOBJ_FLAG_FACING_LEFT;
        else body->flags &= ~BTLOBJ_FLAG_FACING_LEFT;

        body->x = work->actor->x;
        body->y = work->actor->y + 0x800;
        body->z = work->actor->z + work->bob - 0xC00;
        frame = (work->animcounter >> 8) & 7;
        AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, frame + 10, 0, work->tiles);
        ApproachValue(&work->animcounter, 0x800, work->counter);
        ApproachValue(&work->scale, 0x10000, work->counter);
        BgFxSetAngle(-(work->scale >> 8) - 128);
        BgFxSetPosition(body->x, body->y, body->z - 0x1A00);

        if (--work->counter <= 0) {
            work->state = FRD_POOH_STATE_JUMP_OFF;
            work->counter = 0;
            work->velocity = -0x380;
            work->speed = 0x500;
            work->bounce = FALSE;
        }

        break;
    }
    case FRD_POOH_STATE_JUMP_OFF:
        AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 7, 0, work->tiles);

        if (body->flags & BTLOBJ_FLAG_FACING_LEFT) body->x -= work->speed;
        else body->x += work->speed;

        work->speed -= 0x33;

        if (work->speed <= 0) {
            work->speed = 0;

            if (AnimIsFinished(&work->anim)) {
                work->state = FRD_POOH_STATE_RECOVER;
                ColliderSetDisabled(&body->collider, FALSE);
            }
        }

        if (FrdPoohApplyGravity(work) && !work->bounce) {
            work->bounce = TRUE;
            BtlMapStartShake();
        }

        ApplyAttackBox(162, body->x, body->y, body->z, 30, 25, 10);
        break;
    case FRD_POOH_STATE_RECOVER:
        AnimChangeWithDef(sFrdPoohAnimDefsEu, &work->anim, 8, 0, work->tiles);

        if (AnimIsFinished(&work->anim)) work->state = FRD_POOH_STATE_WANDER;

        break;
    }

    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    ColliderSetPosition(&body->collider, body->x, body->y, body->z);
    return 1;
}

void task_frd_pooh_2(FrdPoohWork* work) {
    FrdPoohBody* body;
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
    } else if (gBtlWork->scale == Q_8_8(1)) {
        sclY = gBtlWork->scale;
        sclX = sclY;
        flags |= SPRITE_FLAG_HFLIP;
    } else {
        sclX = -gBtlWork->scale;
        sclY = gBtlWork->scale;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->scale == Q_8_8(1)) {
        affine = NULL;
    } else if (gBtlWork->scale <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, FALSE);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, TRUE);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->depth = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->tasks);
}

void task_frd_pooh_3(FrdPoohWork* work) {
    BtlWork* owner;
    ColliderUnregister(&work->body.collider);
    owner = work->side ? gBtlWork : gRikuBtlWork;
    owner->flags &= ~BTL_FLAG_SUMMON_ACTIVE;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->tasks);
}

TaskDesc gTaskDescFrdPoohEu = {
    "task_frd_pooh",
    (TaskInitFunc)task_frd_pooh_0,
    (TaskUpdateFunc)task_frd_pooh_1,
    (TaskDrawFunc)task_frd_pooh_2,
    (TaskDestroyFunc)task_frd_pooh_3,
    sizeof(FrdPoohWork),
};

#endif
