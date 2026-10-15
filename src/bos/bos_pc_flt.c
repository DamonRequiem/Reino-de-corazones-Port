/**
 * bos_pc_flt.c
 * Parasite Cage Boss Floating Platforms
 */

#include "bos6.h"
#include "sprites_bos6.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>

static const s16 sBosPcFltSine[256] = {
    0, 6, 12, 18, 25, 31, 37, 43, 49, 56, 62, 68, 74, 80, 86, 92,
    97, 103, 109, 115, 120, 126, 131, 136, 142, 147, 152, 157, 162, 167, 171, 176,
    181, 185, 189, 193, 197, 201, 205, 209, 212, 216, 219, 222, 225, 228, 231, 234,
    236, 238, 241, 243, 244, 246, 248, 249, 251, 252, 253, 254, 254, 255, 255, 255,
    256, 255, 255, 255, 254, 254, 253, 252, 251, 249, 248, 246, 244, 243, 241, 238,
    236, 234, 231, 228, 225, 222, 219, 216, 212, 209, 205, 201, 197, 193, 189, 185,
    181, 176, 171, 167, 162, 157, 152, 147, 142, 136, 131, 126, 120, 115, 109, 103,
    97, 92, 86, 80, 74, 68, 62, 56, 49, 43, 37, 31, 25, 18, 12, 6,
    0, -6, -12, -18, -25, -31, -37, -43, -49, -56, -62, -68, -74, -80, -86, -92,
    -97, -103, -109, -115, -120, -126, -131, -136, -142, -147, -152, -157, -162, -167, -171, -176,
    -181, -185, -189, -193, -197, -201, -205, -209, -212, -216, -219, -222, -225, -228, -231, -234,
    -236, -238, -241, -243, -244, -246, -248, -249, -251, -252, -253, -254, -254, -255, -255, -255,
    -256, -255, -255, -255, -254, -254, -253, -252, -251, -249, -248, -246, -244, -243, -241, -238,
    -236, -234, -231, -228, -225, -222, -219, -216, -212, -209, -205, -201, -197, -193, -189, -185,
    -181, -176, -171, -167, -162, -157, -152, -147, -142, -136, -131, -126, -120, -115, -109, -103,
    -97, -92, -86, -80, -74, -68, -62, -56, -49, -43, -37, -31, -25, -18, -12, -6,
};

static const s16 sBosPcFltCosine[256] = {
    256, 255, 255, 255, 254, 254, 253, 252, 251, 249, 248, 246, 244, 243, 241, 238,
    236, 234, 231, 228, 225, 222, 219, 216, 212, 209, 205, 201, 197, 193, 189, 185,
    181, 176, 171, 167, 162, 157, 152, 147, 142, 136, 131, 126, 120, 115, 109, 103,
    97, 92, 86, 80, 74, 68, 62, 56, 49, 43, 37, 31, 25, 18, 12, 6,
    0, -6, -12, -18, -25, -31, -37, -43, -49, -56, -62, -68, -74, -80, -86, -92,
    -97, -103, -109, -115, -120, -126, -131, -136, -142, -147, -152, -157, -162, -167, -171, -176,
    -181, -185, -189, -193, -197, -201, -205, -209, -212, -216, -219, -222, -225, -228, -231, -234,
    -236, -238, -241, -243, -244, -246, -248, -249, -251, -252, -253, -254, -254, -255, -255, -255,
    -256, -255, -255, -255, -254, -254, -253, -252, -251, -249, -248, -246, -244, -243, -241, -238,
    -236, -234, -231, -228, -225, -222, -219, -216, -212, -209, -205, -201, -197, -193, -189, -185,
    -181, -176, -171, -167, -162, -157, -152, -147, -142, -136, -131, -126, -120, -115, -109, -103,
    -97, -92, -86, -80, -74, -68, -62, -56, -49, -43, -37, -31, -25, -18, -12, -6,
    0, 6, 12, 18, 25, 31, 37, 43, 49, 56, 62, 68, 74, 80, 86, 92,
    97, 103, 109, 115, 120, 126, 131, 136, 142, 147, 152, 157, 162, 167, 171, 176,
    181, 185, 189, 193, 197, 201, 205, 209, 212, 216, 219, 222, 225, 228, 231, 234,
    236, 238, 241, 243, 244, 246, 248, 249, 251, 252, 253, 254, 254, 255, 255, 255,
};

static const PcFltFrameDef sBosPcFltFrameDefs[12] = {
    { -16, -16, 0, 0 },
    { -16, 0, 24, 11 },
    { -16, 2, 24, 13 },
    { -16, 4, 21, 14 },
    { -16, 6, 16, 15 },
    { -16, 7, 12, 0 },
    { -10, 3, 16, 17 },
    { -10, 4, 16, 18 },
    { -10, 5, 14, 19 },
    { -10, 6, 12, 20 },
    { -10, 7, 8, 0 },
    { -16, 1, 24, 12 },
};

TaskDesc gTaskDescBosPcFlt = {
    "task_bos_pc_flt",
    (TaskInitFunc)task_bos_pc_flt_0,
    (TaskUpdateFunc)task_bos_pc_flt_1,
    (TaskDrawFunc)task_bos_pc_flt_2,
    (TaskDestroyFunc)task_bos_pc_flt_3,
    sizeof(PcFltWork),
};

s32 BosPcFltSquare(s32 x) {
    return x * x;
}

s32 BosPcFltSquare2(s32 x) {
    return x * x;
}

void BosPcFltGetPosition(Task* task, s32* x, s32* y, s32* z) {
    PcFltWork* work;

    work = task->work;
    *x = work->x;
    *y = work->y;
    *z = work->z;
}

enum BosPcFltState {
    BOS_PC_FLT_STATE_FLOAT,
    BOS_PC_FLT_STATE_SINK,
    BOS_PC_FLT_STATE_SINK_END,
    BOS_PC_FLT_STATE_SUBMERGED,
    BOS_PC_FLT_STATE_RISE,
    BOS_PC_FLT_STATE_SHRINK,
    BOS_PC_FLT_STATE_SHRUNK,
    BOS_PC_FLT_STATE_REGROW,
    BOS_PC_FLT_STATE_GIMMICK
};

u8 BosPcFltIsSubmerged(Task* task) {
    PcFltWork* work;

    work = task->work;

    if (work->state == BOS_PC_FLT_STATE_GIMMICK && AnimGetGfxIndex(&work->anim) == 0) {
        return TRUE;
    }

    return FALSE;
}

u8 BosPcFltIsPlayerOn(Task* task) {
    PcFltWork* work;
    u8 playerOn;

    work = task->work;
    playerOn = FALSE;

    if (IsPlayerOnPlatform(&work->collider) == TRUE) {
        playerOn = TRUE;
    }

    return playerOn;
}

void BosPcFltUpdateFloat(PcFltWork* work) {
    AnimState* anim;

    work->z = work->baseZ;

    if (!work->shared->fltShrunk) {
        if (IsPlayerOnPlatform(&work->collider) == TRUE) {
            work->z += 0x200;

            if (work->playerOnPlatform != TRUE) {
                work->playerOnPlatform = TRUE;
                AnimChange(&work->anim, 8, 0);
            }

            work->sinkTimer -= 2;

            if (work->sinkTimer < 0) {
                work->state = BOS_PC_FLT_STATE_SINK;
                work->playerOnPlatform = FALSE;
                work->timer = 0;
                work->sinkTimer = 360;
                AnimChange(&work->anim, 7, 0);
            }
        } else {
            if (work->playerOnPlatform == TRUE) {
                work->sinkTimer -= 120;
                AnimChange(&work->anim, 1, 0);
            } else {
                work->sinkTimer += 1;

                if (work->sinkTimer > 720) {
                    work->sinkTimer = 720;
                }
            }

            work->playerOnPlatform = FALSE;
        }
    } else {
        work->state = BOS_PC_FLT_STATE_SHRINK;
        work->playerOnPlatform = FALSE;
        work->timer = 0;
        AnimChange(&work->anim, 5, 0);
    }
}

void BosPcFltUpdateSink(PcFltWork* work) {
    AnimState* anim;

    work->z = work->baseZ;
    anim = &work->anim;

    if (AnimIsFinished(anim) == TRUE) {
        work->state = BOS_PC_FLT_STATE_SINK_END;
        work->timer = 0;
        AnimReset(anim);
        AnimChange(anim, 3, 0);
    }
}

void BosPcFltUpdateSinkEnd(PcFltWork* work) {
    work->z = work->baseZ;

    if (AnimIsFinished(&work->anim) == TRUE) {
        work->state = BOS_PC_FLT_STATE_SUBMERGED;
        work->playerOnPlatform = FALSE;
        work->timer = 60;
    }
}

void BosPcFltUpdateSubmerged(PcFltWork* work) {
    work->z = work->baseZ + 0x1000;
    work->timer -= 1;

    if (work->timer < 0) {
        if (!work->shared->fltShrunk) {
            work->state = BOS_PC_FLT_STATE_RISE;
            work->timer = 0;
            AnimChange(&work->anim, 4, 0);
        } else {
            work->state = BOS_PC_FLT_STATE_SHRUNK;
            work->timer = 0;
            AnimChange(&work->anim, 9, 0);
        }
    }
}

void BosPcFltUpdateRise(PcFltWork* work) {
    AnimState* anim;

    work->z = work->baseZ;
    anim = &work->anim;

    if (AnimIsFinished(anim) == TRUE) {
        work->state = BOS_PC_FLT_STATE_FLOAT;
        AnimReset(anim);
        AnimChange(anim, 1, 0);
    }
}

void BosPcFltUpdateState5(PcFltWork* work) {
    AnimState* anim;

    work->z = work->baseZ;
    anim = &work->anim;

    if (AnimIsFinished(anim) == TRUE) {
        work->state = BOS_PC_FLT_STATE_SHRUNK;
        work->timer = 0;
        AnimReset(anim);
        AnimChange(anim, 2, 0);
    }
}

void BosPcFltUpdateState6(PcFltWork* work) {
    work->z = work->baseZ;

    if (!work->shared->fltShrunk) {
        work->state = BOS_PC_FLT_STATE_REGROW;
        work->timer = 0;
        AnimChange(&work->anim, 6, 0);
    }
}

void BosPcFltUpdateState7(PcFltWork* work) {
    AnimState* anim;

    work->z = work->baseZ;
    anim = &work->anim;

    if (AnimIsFinished(anim) == TRUE) {
        work->state = BOS_PC_FLT_STATE_FLOAT;
        work->timer = 0;
        AnimReset(anim);
        AnimChange(anim, 1, 0);
    }
}

void BosPcFltUpdateGimmick(PcFltWork* work) {
    AnimState* anim;
    u8 fin;
    u16 id;

    work->z = work->baseZ;

    if (work->timer == 0) {
        anim = &work->anim;
        fin = AnimIsFinished(anim);

        if (fin == TRUE) {
            id = AnimGetGfxIndex(anim);

            if (id != 0) {
                AnimReset(anim);
                AnimChange(anim, sBosPcFltFrameDefs[id].nextAnim, 0);
            } else {
                work->timer = 1;
            }
        }
    } else if (work->shared->gimmickTimer <= 119) {
        work->state = BOS_PC_FLT_STATE_SUBMERGED;
        work->playerOnPlatform = FALSE;
        work->timer = work->index * 30;
    }
}

void BosPcFltUpdateMotion(PcFltWork* work) {
    s32 orbit;

    if ((gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) || (gBtlWork->flags & BTL_FLAG_OPPONENT_CARD_ACTION) ||
        work->shared->fltStopTimer > 0) {
        orbit = -1;
    } else {
        orbit = work->unk_007;
    }

    if (work->state != BOS_PC_FLT_STATE_GIMMICK && work->shared->gimmickTimer > 0x257) {
        work->state = BOS_PC_FLT_STATE_GIMMICK;
        work->playerOnPlatform = FALSE;
        work->timer = 0;
        work->sinkTimer = 360;
    }

    if (!work->shared->fltShrunk) {
        if (work->centerX > 0xF400) {
            work->centerX -= 32;
        }

        if (work->centerY > 0x15400) {
            work->centerY -= 32;
        }

        if (work->radiusX <= 0x3FFF) {
            work->radiusX += 64;
        }

        if (work->radiusY <= 0x1FFF) {
            work->radiusY += 32;
        }
    } else {
        if (work->centerX <= 0x103FF) {
            work->centerX += 32;
        }

        if (work->centerY <= 0x153FF) {
            work->centerY += 32;
        }

        if (work->radiusX > 0x3400) {
            work->radiusX -= 64;
        }

        if (work->radiusY > 0x1E00) {
            work->radiusY -= 32;
        }
    }

    if (orbit >= 0) {
        work->x = (((sBosPcFltCosine[work->orbitAngle >> 8] * (work->radiusX >> 8)) >> 8) + (work->centerX >> 8)) << 8;
        work->y = (((sBosPcFltSine[work->orbitAngle >> 8] * (work->radiusY >> 8)) >> 8) + (work->centerY >> 8)) << 8;
        work->orbitAngle = work->orbitAngle - (((work->shared->hpRatio * 3) << 4) / 256 - 112);
    }

    switch (work->state) {
    case BOS_PC_FLT_STATE_FLOAT:
        BosPcFltUpdateFloat(work);
        break;
    case BOS_PC_FLT_STATE_SINK:
        BosPcFltUpdateSink(work);
        break;
    case BOS_PC_FLT_STATE_SINK_END:
        BosPcFltUpdateSinkEnd(work);
        break;
    case BOS_PC_FLT_STATE_SUBMERGED:
        BosPcFltUpdateSubmerged(work);
        break;
    case BOS_PC_FLT_STATE_RISE:
        BosPcFltUpdateRise(work);
        break;
    case BOS_PC_FLT_STATE_SHRINK:
        BosPcFltUpdateState5(work);
        break;
    case BOS_PC_FLT_STATE_SHRUNK:
        BosPcFltUpdateState6(work);
        break;
    case BOS_PC_FLT_STATE_REGROW:
        BosPcFltUpdateState7(work);
        break;
    case BOS_PC_FLT_STATE_GIMMICK:
        BosPcFltUpdateGimmick(work);
        break;
    }

    if (IsPlayerOnPlatform(&work->collider) == TRUE) {
        work->playerOnPlatform = TRUE;
    }
}

void BosPcFltSyncCollider(PcFltWork* work) {
    Collider* collider;

    collider = &work->collider;
    ColliderSetPosition(collider, work->x, work->y + 0x200, 0);
    ColliderSetHeight(collider, -work->z >> 8);

    if (work->z > 0) {
        ColliderSetDisabled(collider, TRUE);
    } else {
        ColliderSetDisabled(collider, FALSE);
    }
}

void task_bos_pc_flt_0(PcFltWork* work, PcFltInit* arg) {
    AnimState* anim;

    work->tiles = LoadObjTiles(gBosPcFltTiles, 0xDC0);
    work->palette = LoadObjPalette(gBosPcObjPalette, sizeof(gBosPcObjPalette));
    anim = &work->anim;
    AnimInit(anim, gBosPcFltAnims, gBosPcFltFrames);
    AnimStart(anim, 1, 0);
    ColliderInit(&work->collider, COLLIDER_TYPE_PLATFORM, 26, 4);
    work->playerOnPlatform = FALSE;
    work->timer = 0;
    work->index = arg->index;
    work->state = BOS_PC_FLT_STATE_FLOAT;
    work->unk_006 = 0;
    work->unk_007 = 0;
    work->orbitAngle = (arg->index << 14) + arg->angle;
    work->centerX = 0xF400;
    work->centerY = 0x15400;
    work->radiusX = 0x4000;
    work->radiusY = 0x2000;
    work->sinkTimer = 720;
    work->baseX = arg->x;
    work->baseY = arg->y;
    work->baseZ = arg->z;
    work->shared = arg->shared;
    BosPcFltUpdateMotion(work);
    BosPcFltSyncCollider(work);
}

u8 task_bos_pc_flt_1(PcFltWork* work) {
    AnimState* anim;
    u16 id;

    BosPcFltUpdateMotion(work);
    anim = &work->anim;
    AnimUpdate(anim);
    id = AnimGetGfxIndex(anim);

    if (id == 0) {
        work->z += 0x1000;
    } else {
        work->z += sBosPcFltFrameDefs[id].z << 8;
        ColliderSetRadius(&work->collider, sBosPcFltFrameDefs[id].radius);
    }

    BosPcFltSyncCollider(work);
    work->unk_007 = work->shared->hpRatio & 1;
    return 1;
}

void task_bos_pc_flt_2(PcFltWork* work) {
    s16 sx;
    s16 sy;
    u16 id;
    u16 prio;
    u16 depth;

    if (work->z <= 0) {
        id = AnimGetGfxIndex(&work->anim);
        WorldToScreen(&sx, &sy, work->x,
            work->y + (sBosPcFltFrameDefs[id].drawY << 8), work->z);

        if (gBtlWork->platform != NULL) {
            prio = GetBattleSpritePriorityFlags(work->y + (sBosPcFltFrameDefs[id].drawY << 8));
            depth = (-0x1004 - ((work->y >> 8) << 2)) | 3;
        } else {
            prio = GetBattleSpritePriorityFlags(work->y);
            depth = -0x1004 - ((work->y >> 8) << 2);
        }

        DrawSprite(sx, sy, AnimGetGfx(&work->anim), work->tiles,
                   work->palette, NULL, prio, depth);
    }
}

void task_bos_pc_flt_3(PcFltWork* work) {
    ColliderUnregister(&work->collider);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}
