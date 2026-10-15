/**
 * bos_dsd.c
 * Darkside Boss
 */

#include "bos2.h"
#include "sprites_bos2.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_collision.h"
#include "card_api.h"
#include "gba/defines.h"
#include "pallet.h"
#include "registration_data.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "enemy_ids.h"

void task_bos_dsd_0(DsdWork* work, void* arg) {
    s32 inEvent;
    DsdWork* w;
    BtlObj* head;
    BtlObj* hand;
    BtlWork* btl;

    work->flags = 0;

    if (arg != NULL) {
        work->flags = DSD_FLAG_IN_EVENT;
    }

    TaskPoolInit(&work->tasks, 4);

    if (work->flags & DSD_FLAG_IN_EVENT) {
        TaskCreate(&work->tasks, &gTaskDescBosDsdMap, NULL);
    } else {
        TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosDsdMap, work);
    }

    work->unk_390 = 0;
    work->unk_392 = 0;

    if (work->flags & DSD_FLAG_IN_EVENT) {
        work->state = BOS_DSD_STATE_EVENT_IDLE;
    } else {
        work->state = BOS_DSD_STATE_IDLE;
    }

    work->attackState = BOS_DSD_STATE_IDLE;
    work->lastState = BOS_DSD_STATE_IDLE;
    work->attackCycle = 0;
    work->hitCount = 0;
    work->timer = 0;
    work->stateStep = 0;
    work->stepTimer = 0;
    work->bgFrame = 0;
    work->bgFrameTimer = 0;
    work->hpPhase = BOS_DSD_HP_PHASE_HIGH;
    work->driftX = -51;
    inEvent = (s16)(work->flags & DSD_FLAG_IN_EVENT);

    if (inEvent != 0) {
        work->bodyX = 0xDC00;
        work->bodyY = 0x16800;
        work->bodyZ = -0x6400;
        w = work;
        InitEnemyBtlObj(&w->body[0], &gBosDsdEmyKind, work->bodyX, work->bodyY, work->bodyZ);
        head = &w->body[1];
        InitEnemyBtlObj(head, &gBosDsdEmyKind, 0xDC00, 0x16800, -0x8C00);
        hand = &w->body[2];
        InitEnemyBtlObj(hand, &gBosDsdEmyKind, 0x9000, 0x16800, 0);
        TaskCreate(&w->tasks, &gTaskDescBosDsdMain, w);
    } else {
        work->bodyX = 0xDC00;
        work->bodyY = 0x16800;
        work->bodyZ = -0x6400;
        w = work;
        InitEnemyBtlObj(&w->body[0], &gBosDsdEmyKind, work->bodyX, work->bodyY, work->bodyZ);
        w->body[0].flags |= BTLOBJ_FLAG_UNHITTABLE;
        w->body[0].flags |= BTLOBJ_FLAG_FACING_LEFT;
        head = &w->body[1];
        InitEnemyBtlObj(head, &gBosDsdEmyKind, 0xDC00, 0x16800, -0x8C00);
        head->flags |= BTLOBJ_FLAG_FACING_LEFT;
        head->flags |= 0x400;
        head->centerHeight = inEvent;
        head->radiusX = 16;
        head->radiusY = 16;
        head->height = 16;
        hand = &w->body[2];
        InitEnemyBtlObj(hand, &gBosDsdEmyKind, 0x9000, 0x16800, inEvent);
        hand->flags |= (BTLOBJ_FLAG_FACING_LEFT | BTLOBJ_FLAG_UNHITTABLE | BTLOBJ_FLAG_RESIST_FIRE | BTLOBJ_FLAG_RESIST_BLIZZARD | BTLOBJ_FLAG_RESIST_THUNDER | BTLOBJ_FLAG_RESIST_PHYSICAL);
        hand->centerHeight = inEvent;
        hand->radiusX = 16;
        hand->radiusY = 16;
        hand->height = 32;
        ColliderInit(&hand->collider, COLLIDER_TYPE_PLATFORM, 16, 32);
        ColliderSetPosition(&hand->collider, hand->x, hand->y, hand->z);
        ColliderSetDisabled(&hand->collider, TRUE);
        SetBtlObjParent(hand, head);
        gBtlWork->bossPriorityOffset = inEvent;
        SetBtlPaletteFadeExcluded(0, TRUE);
        SetBattleActorPosition(0x6400, 0x16800, 0);
        SetGimmickTarget(0x2800, 0x16800, 0);
        TaskCreate(&w->tasks, &gTaskDescBosDsdMain, w);
        btl = gBtlWork;
        btl->bossX = w->body[0].x;
        btl->bossY = w->body[0].y;
        btl->bossZ = w->body[0].z;
    }
}

u8 task_bos_dsd_1(DsdWork* work) {
    BtlWork* btl;
    BtlObj* body = work->body;
    BtlObj* head = &work->body[1];

    if (work->flags & DSD_FLAG_IN_EVENT) {
        TaskPoolUpdate(&work->tasks);
        return 1;
    }

    switch (UpdateBtlObjReaction(head)) {
    case BTL_REACTION_CARD_ACTION:
        work->state = BOS_DSD_STATE_ATTACK_START;
        head->flags |= BTLOBJ_FLAG_UNHITTABLE;
        work->stateStep = 0;
        break;
    case BTL_REACTION_HURT:
    case BTL_REACTION_STUNNED:
    case BTL_REACTION_GRAVITY:
        work->flags |= DSD_FLAG_HURT;
        work->timer = 20;
        break;
    case BTL_REACTION_DEFEATED:
    case BTL_REACTION_GRAVITY_DEFEATED:
        work->state = BOS_DSD_STATE_DEFEATED;
        work->stateStep = 0;
        break;
    case BTL_REACTION_CARD_BROKEN:
        work->state = BOS_DSD_STATE_CARD_BROKEN;
        work->stateStep = 0;
        break;
    }

    if (work->flags & DSD_FLAG_HURT) {
        work->timer--;

        if ((s16)work->timer <= 0) {
            work->hitCount = 0;
            work->flags &= ~DSD_FLAG_HURT;
            LoadPaletteWithEffect(gBosDsdBgPalette, (void*)PLTT, 32);
            ClearBtlObjActionFlags(head);

            if (head->hp > 0) {
                switch (work->state) {
                case BOS_DSD_STATE_RETURN:
                case BOS_DSD_STATE_IDLE:
                case BOS_DSD_STATE_SHOCKWAVE:
                case BOS_DSD_STATE_SUMMON:
                case BOS_DSD_STATE_CARD_BROKEN:
                    break;
                default:
                    work->state = BOS_DSD_STATE_RETURN;
                    work->stateStep = 0;
                    break;
                }
            }
        }
    }

    if (ConsumeGimmickFlag(0)) {
        work->flags |= DSD_FLAG_PLATFORM_ACTIVE;
        TaskCreate(&work->tasks, &gTaskDescBosDsdIta, work);
    }

    if (work->state == BOS_DSD_STATE_SHOCKWAVE) {
        if (gBtlWork->actor->z <= -0x1000) {
            gBtlWork->bossPriorityOffset = -30;
        } else {
            gBtlWork->bossPriorityOffset = 0;
        }
    } else {
        gBtlWork->bossPriorityOffset = 0;
    }

    TaskPoolUpdate(&work->tasks);
    btl = gBtlWork;
    btl->bossX = body->x;
    btl->bossY = body->y;
    btl->bossZ = body->z;

    if (work->flags & DSD_FLAG_DEFEAT_DONE) {
        return 0;
    }

    return 1;
}

void task_bos_dsd_2(DsdWork* work) {
    TaskPoolDraw(&work->tasks);
}

void task_bos_dsd_3(DsdWork* work) {
    BtlObj* head;
    BtlObj* hand;

    head = &work->body[1];
    hand = &work->body[2];
    TaskPoolDestroy(&work->tasks);
    ColliderUnregister(&work->body[2].collider);
    ReleaseEnemyBtlObj(&work->body[0]);
    ReleaseEnemyBtlObj(head);
    ReleaseEnemyBtlObj(hand);
}

const EmyKind gBosDsdEmyKind = { ENEMY_DARKSIDE, 1000, 16, 16, 40, 60, 0 };

TaskDesc gTaskDescBosDsd = {
    "task_bos_dsd",
    (TaskInitFunc)task_bos_dsd_0,
    (TaskUpdateFunc)task_bos_dsd_1,
    (TaskDrawFunc)task_bos_dsd_2,
    (TaskDestroyFunc)task_bos_dsd_3,
    sizeof(DsdWork),
};
