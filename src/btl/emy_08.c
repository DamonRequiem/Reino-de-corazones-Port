/**
 * emy_08.c
 * Black Fungus Enemy
 */

#include "task_descriptors.h"
#include "emy.h"
#include "sprites_emy.h"
#include "enemy_common.h"
#include "songs.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "btl_collision.h"
#include "btl_effect.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy08CommonAnimDefs[3] = {
    { gEmy07Fl00Frames, gEmy07Fl00Anims, gEmy07Fl00Tiles, 0 },
    { gEmy07Fl03Frames, gEmy07Fl03Anims, gEmy07Fl03Tiles, 0 },
    { gEmy07Fl09Frames, gEmy07Fl09Anims, gEmy07Fl09Tiles, 0 },
};

static const AnimDef sEmy08AnimDefs[6] = {
    { gEmy07Fl10Frames, gEmy07Fl10Anims, gEmy07Fl10Tiles, 0 },
    { gEmy08GasFrames, gEmy08GasAnims, gEmy08GasTiles, 0 },
    { gEmy07Fl10tFrames, gEmy07Fl10tAnims, gEmy07Fl10tTiles, 0 },
    { gEmy07Fl10fFrames, gEmy07Fl10fAnims, gEmy07Fl10fTiles, 0 },
    { gEmy07Fl11tFrames, gEmy07Fl11tAnims, gEmy07Fl11tTiles, 0 },
    { gEmy07Fl11fFrames, gEmy07Fl11fAnims, gEmy07Fl11fTiles, 0 },
};

static const EmyDef sEmy08Def = { gEmy07bPalette, sEmy08CommonAnimDefs, 179, 130, 20, 20, 24, 24, 16, 5, 0, { ENEMY_BLACK_FUNGUS, 999, 32, 12, 16, 100, 0 } };

TaskDesc gTaskDescEmy08 = {
    "task_emy_08",
    (TaskInitFunc)task_emy_08_0,
    (TaskUpdateFunc)task_emy_08_1,
    (TaskDrawFunc)task_emy_08_2,
    (TaskDestroyFunc)task_emy_08_3,
    sizeof(Emy08Work),
};

void task_emy_08_0(Emy08Work* work, void* obj) {
    EmyInit(&work->base, &sEmy08Def, obj);
    work->palette = LoadObjPalette(gEmy07mPalette, sizeof(gEmy07mPalette));
    work->basePalette = work->base.palette;
    work->flags = 0;
}

enum Emy08State {
    EMY08_STATE_LUNGE = 18,
    EMY08_STATE_GAS,
    EMY08_STATE_LUNGE_HIT,
    EMY08_STATE_LUNGE_MISS,
    EMY08_STATE_HARDEN,
    EMY08_STATE_SOFTEN
};

u8 task_emy_08_1(Emy08Work* work) {
    Emy08Work* w;
    BtlObj* act;
    u16 roll;
    s32 dx;
    s32 dy;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        roll = GetRandom();

        switch (roll & 1) {
        case 0:
            work->base.state = EMY08_STATE_LUNGE;
            break;
        case 1:
            work->base.state = EMY08_STATE_GAS;
            break;
        }
    }

    switch (work->base.state) {
    case EMY_STATE_IDLE:
        if (GetRandom() % 100 == 0) {
            if (w->flags & EMY08_FLAG_HARDENED) {
                work->base.state = EMY08_STATE_SOFTEN;
            } else {
                work->base.state = EMY08_STATE_HARDEN;
            }

            work->base.stateTimer = 0;
        }

        break;
    case EMY08_STATE_HARDEN:
        AnimChangeWithDef(sEmy08AnimDefs, &w->base.anim, 4, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 6) {
            act->flags |= (BTLOBJ_FLAG_IMMUNE_STOP | BTLOBJ_FLAG_INVULNERABLE);
            w->flags |= EMY08_FLAG_HARDENED;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = work->base.idleState;
        }

        break;
    case EMY08_STATE_SOFTEN:
        AnimChangeWithDef(sEmy08AnimDefs, &w->base.anim, 5, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 4) {
            act->flags &= ~(BTLOBJ_FLAG_IMMUNE_STOP | BTLOBJ_FLAG_INVULNERABLE);
            w->flags &= ~EMY08_FLAG_HARDENED;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = work->base.idleState;
        }

        break;
    case EMY08_STATE_LUNGE:
        AnimChangeWithDef(sEmy08AnimDefs, &w->base.anim, 0, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            EmyReturnToIdle(&work->base);
            act->flags |= BTLOBJ_FLAG_CARD_USE_BLOCKED;

            if (w->flags & EMY08_FLAG_ATTACK_HIT) {
                work->base.state = EMY08_STATE_LUNGE_HIT;
            } else {
                work->base.state = EMY08_STATE_LUNGE_MISS;
            }
        } else if (work->base.anim.timer == 0) {
            dx = 0;
            dy = 0;

            switch (work->base.anim.frame) {
            case 1:
                dx = 2;
                break;
            case 2:
                dx = 2;
                dy = 1;
                break;
            case 3:
                dx = 2;
                dy = 1;
                break;
            case 4:
                dx = 2;
                dy = 1;
                break;
            case 5:
                dx = 3;
                dy = 1;
                break;
            case 6:
                dx = 3;
                break;
            case 7:
                dx = 2;

                if ((act->flags & BTLOBJ_FLAG_FACING_LEFT)
                        ? ApplyAttackBox(0xB1, act->x - 0x1400, act->y, act->z,
                            4, 4, 0x20)
                        : ApplyAttackBox(0xB1, act->x + 0x1400, act->y, act->z,
                            4, 4, 0x20)) {
                    m4aSongNumStart(SONG_BTL_HANE_HIT);
                    w->flags |= EMY08_FLAG_ATTACK_HIT;
                } else {
                    w->flags &= ~EMY08_FLAG_ATTACK_HIT;
                }

                break;
            }

            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                act->x -= dx << 8;
            } else {
                act->x += dx << 8;
            }

            act->y -= dy << 8;
        }

        break;
    case EMY08_STATE_LUNGE_HIT:
        AnimChangeWithDef(sEmy08AnimDefs, &w->base.anim, 2, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = work->base.idleState;
            act->flags &= ~BTLOBJ_FLAG_CARD_USE_BLOCKED;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY08_STATE_LUNGE_MISS:
        AnimChangeWithDef(sEmy08AnimDefs, &w->base.anim, 3, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.stateTimer = 0;
            work->base.state = work->base.idleState;
            act->flags &= ~BTLOBJ_FLAG_CARD_USE_BLOCKED;
        } else {
            work->base.stateTimer++;
        }

        break;
    case EMY08_STATE_GAS:
        AnimChangeWithDef(sEmy08AnimDefs, &w->base.anim, 1, 0, w->base.tiles);

        if (work->base.anim.timer == 0
                && AnimGetFrame(&work->base.anim) == 7) {
            if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                BgFxStartGas(act->x, act->y, act->z - 0xA00, TRUE);
            } else {
                BgFxStartGas(act->x, act->y, act->z - 0xA00, FALSE);
            }
        }

        if (work->base.stateTimer == 60) {
            (act->flags & BTLOBJ_FLAG_FACING_LEFT)
                ? ApplyAttackBox(0xB2, act->x, act->y, act->z, 0x20, 0x20, 0x20)
                : ApplyAttackBox(0xB2, act->x, act->y, act->z, 0x20, 0x20, 0x20);
        }

        if (AnimIsFinished(&work->base.anim) && !BgFxIsActive()) {
            EmyReturnToIdle(&work->base);
        } else {
            work->base.stateTimer++;
        }

        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_08_2(Emy08Work* work) {
    work->base.palette = (work->flags & EMY08_FLAG_HARDENED) ? work->palette : work->basePalette;
    EmyDraw(&work->base);
    work->base.palette = work->basePalette;
}

void task_emy_08_3(Emy08Work* work) {
    EmyReleaseResources(&work->base);
    ReleaseObjPalette(work->palette);
}
