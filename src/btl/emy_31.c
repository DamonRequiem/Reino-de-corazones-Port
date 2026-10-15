/**
 * emy_31.c
 * Wizard Enemy
 */

#include "task_descriptors.h"
#include "emy.h"
#include "sprites_emy.h"
#include "enemy_common.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "btl_effect.h"
#include "enemy_types.h"
#include "engine_math.h"
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "enemy_ids.h"

static const AnimDef sEmy31CommonAnimDefs[3] = {
    { gEmy3100Frames, gEmy3100Anims, gEmy3100Tiles, 0 },
    { gEmy3104Frames, gEmy3104Anims, gEmy3104Tiles, 0 },
    { gEmy3100Frames, gEmy3100Anims, gEmy3100Tiles, 0 },
};

static const AnimDef sEmy31AnimDefs[3] = {
    { gEmy3105Frames, gEmy3105Anims, gEmy3105Tiles, 0 },
    { gEmy3106Frames, gEmy3106Anims, gEmy3106Tiles, 0 },
    { gEmy3107Frames, gEmy3107Anims, gEmy3107Tiles, 0 },
};

static const EmyDef sEmy31Def = { gEmy31Palette, sEmy31CommonAnimDefs, 256, 100, 10, 20, 64, 32, 32, 10, 0, { ENEMY_WIZARD, 95, 32, 12, 24, 100, 0 } };

TaskDesc gTaskDescEmy31 = {
    "task_emy_31",
    (TaskInitFunc)task_emy_31_0,
    (TaskUpdateFunc)task_emy_31_1,
    (TaskDrawFunc)task_emy_31_2,
    (TaskDestroyFunc)task_emy_31_3,
    sizeof(Emy31Work),
};

void task_emy_31_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmy31Def, obj);
    work->idleState = EMY_STATE_HOVER;
}

enum Emy31State {
    EMY31_STATE_FIRE = 18,
    EMY31_STATE_BLIZZARD,
    EMY31_STATE_THUNDER
};

enum Emy31CastPhase {
    EMY31_CAST_PHASE_WINDUP,
    EMY31_CAST_PHASE_CAST,
    EMY31_CAST_PHASE_END,
    EMY31_CAST_PHASE_FIRE_END
};

u8 task_emy_31_1(Emy31Work* work) {
    Emy31Work* w;
    BtlObj* act;

    w = work;
    act = &work->base.actor;

    if (EmyUpdateReaction(&work->base)) {
        switch ((u16)(GetRandom() % 3)) {
        case 0:
            work->base.state = EMY31_STATE_FIRE;
            break;
        case 1:
            work->base.state = EMY31_STATE_BLIZZARD;
            break;
        case 2:
            work->base.state = EMY31_STATE_THUNDER;
            break;
        }

        w->state = EMY31_CAST_PHASE_WINDUP;
    }

    switch (work->base.state) {
    case EMY31_STATE_FIRE: {
        s32 targetX;
        s32 y;
        work->base.vz = 0;

        switch (w->state) {
        case EMY31_CAST_PHASE_WINDUP:
            if (work->base.stateTimer == 0) {
                AnimChangeWithDef(sEmy31AnimDefs, &w->base.anim, 0, 0,
                    w->base.tiles);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->state = EMY31_CAST_PHASE_CAST;
                work->base.stateTimer = 0;
            } else {
                work->base.stateTimer++;
            }

            break;
        case EMY31_CAST_PHASE_CAST:
            if (work->base.stateTimer == 0) {
                AnimStart(&work->base.anim, 1, 0);

                y = act->y;

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    targetX = act->x - 0xC800;
                    BgFxStartFire(SPELL_TIER_RA, act->x - 0x4000, y, act->z,
                        targetX, y, 0, TRUE, 0xCF);
                } else {
                    targetX = act->x + 0xC800;
                    BgFxStartFire(SPELL_TIER_RA, act->x + 0x4000, y, act->z,
                        targetX, y, 0, FALSE, 0xCF);
                }
            }

            if (work->base.stateTimer > 30) {
                w->state = EMY31_CAST_PHASE_FIRE_END;
                work->base.stateTimer = 0;
            } else {
                work->base.stateTimer++;
            }

            break;
        case EMY31_CAST_PHASE_FIRE_END:
            if (work->base.stateTimer == 0) {
                AnimStart(&work->base.anim, 2, 0);
            }

            if (AnimIsFinished(&work->base.anim)) {
                AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, ANIM_FLAG_LOOP,
                    w->base.tiles);
            }

            if (BgFxIsActive()) {
                work->base.stateTimer++;
            } else {
                w->state = EMY31_CAST_PHASE_WINDUP;
                EmyReturnToIdle(&work->base);
            }

            break;
        }

        break;
    }
    case EMY31_STATE_BLIZZARD: {
        s32 targetX;
        s32 y;
        work->base.vz = 0;

        switch (w->state) {
        case EMY31_CAST_PHASE_WINDUP:
            if (work->base.stateTimer == 0) {
                AnimChangeWithDef(sEmy31AnimDefs, &w->base.anim, 1, 0,
                    w->base.tiles);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->state = EMY31_CAST_PHASE_CAST;
                work->base.stateTimer = 0;
            } else {
                work->base.stateTimer++;
            }

            break;
        case EMY31_CAST_PHASE_CAST:
            if (work->base.stateTimer == 0) {
                AnimStart(&work->base.anim, 1, ANIM_FLAG_LOOP);

                y = act->y;

                if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    targetX = act->x - 0x6400;
                    BgFxStartBlizzard(SPELL_TIER_RA, act->x - 0x4600, y, act->z,
                        targetX, y, 0, TRUE, 0xD0);
                } else {
                    targetX = act->x + 0x6400;
                    BgFxStartBlizzard(SPELL_TIER_RA, act->x + 0x4600, y, act->z,
                        targetX, y, 0, FALSE, 0xD0);
                }
            }

            if (work->base.stateTimer > 60) {
                w->state = EMY31_CAST_PHASE_END;
                work->base.stateTimer = 0;
            } else {
                work->base.stateTimer++;
            }

            break;
        case EMY31_CAST_PHASE_END:
            if (work->base.stateTimer == 0) {
                AnimStart(&work->base.anim, 2, 0);
            }

            if (AnimIsFinished(&work->base.anim)) {
                AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, ANIM_FLAG_LOOP,
                    w->base.tiles);
            }

            if (BgFxIsActive()) {
                work->base.stateTimer++;
            } else {
                w->state = EMY31_CAST_PHASE_WINDUP;
                EmyReturnToIdle(&work->base);
            }

            break;
        }

        break;
    }
    case EMY31_STATE_THUNDER:
        work->base.vz = 0;

        switch (w->state) {
        case EMY31_CAST_PHASE_WINDUP:
            if (work->base.stateTimer == 0) {
                AnimChangeWithDef(sEmy31AnimDefs, &w->base.anim, 2, 0,
                    w->base.tiles);
                GetEnemyTargetPosition(act, &w->targetX, &w->targetY, &w->targetZ);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->state = EMY31_CAST_PHASE_CAST;
                work->base.stateTimer = 0;
            } else {
                work->base.stateTimer++;
            }

            break;
        case EMY31_CAST_PHASE_CAST:
            if (work->base.stateTimer == 0) {
                AnimStart(&work->base.anim, 1, 0);
                work->base.steps = 0;
            }

            if (AnimIsFinished(&work->base.anim)) {
                if (work->base.steps == 0) {
                    if (act->flags & BTLOBJ_FLAG_FACING_LEFT) {
                        BgFxStartThunder(SPELL_TIER_RA, act->x - 0x1600, act->y,
                            act->z - 0x3C00, w->targetX, w->targetY,
                            w->targetZ, 0xD1);
                    } else {
                        BgFxStartThunder(SPELL_TIER_RA, act->x + 0x1600, act->y,
                            act->z - 0x3C00, w->targetX, w->targetY,
                            w->targetZ, 0xD1);
                    }

                    work->base.steps++;
                }

                if (!BgFxIsActive()) {
                    w->state = EMY31_CAST_PHASE_END;
                    work->base.stateTimer = 0;
                    break;
                }
            }

            work->base.stateTimer++;
            break;
        case EMY31_CAST_PHASE_END:
            if (work->base.stateTimer == 0) {
                AnimStart(&work->base.anim, 2, 0);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->state = EMY31_CAST_PHASE_WINDUP;
                EmyReturnToIdle(&work->base);
            } else {
                work->base.stateTimer++;
            }

            break;
        }

        break;
    }

    return EmyUpdateCommonStates(&work->base);
}

void task_emy_31_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_31_3(EmyWork* work) {
    EmyReleaseResources(work);
}
