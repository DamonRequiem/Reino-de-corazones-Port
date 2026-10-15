/**
 * lockon.c
 * Field Lock-On Cursor
 */

#include "sprites_mode_test.h"
#include "malloc.h"
#include "anim.h"
#include "engine_math.h"
#include "field_state.h"
#include "fld_types.h"
#include "gba/syscall.h"
#include "listpool.h"
#include "obj.h"
#include "obj_api.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "lockon.h"
#include "sprite_palettes.h"
#include "gba/defines.h"

void task_lockon_0(LockonWork* work) {
    s32 i;

    gLockonDoorPosition = EwramAlloc(12);
    work->tiles = AllocObjTiles(0x80, NULL);
    work->palette = LoadObjPalette(gCommonObjPalette, sizeof(gCommonObjPalette));
    SetObjTileSource(work->tiles, gLockonCursorTiles);
    AnimInit(&work->anim, gLockonCursorAnims, gLockonCursorFrames);
    AnimStart(&work->anim, 0, ANIM_FLAG_LOOP);
    work->gfx = AnimGetGfx(&work->anim);

    for (i = 0; i < 8; i++) {
        work->targets[i] = NULL;
    }

    work->targetCount = 0;
    work->selected = LOCKON_TARGET_NONE;
    work->timer = 0;
    work->unk_30 = 0;
    work->unk_4C = 0;
}

u8 task_lockon_1(LockonWork* work) {
    FldObj* obj;
    s8 count;
    s8 i;
    s8 nsel;
    s8 list[8];
    s32 px;
    s32 py;
    s32 dx;
    s32 dy;
    s32 ox;
    s32 oy;

    i = 0;
    obj = ListPoolFirst(&gFieldState->actor.pool);

    if (gFieldState->flags & FIELD_FLAG_NO_LOCKON) {
        gFieldState->lockonTarget = NULL;
        return 1;
    }

    LockonClearTargets(work);

    if (work->prevSelected != work->selected) {
        work->unk_30 = 0;
    }

    px = gFieldState->actor.fieldPosition.x;
    py = gFieldState->actor.fieldPosition.y;
    count = 0;

    if ((gFieldState->flags & FIELD_FLAG_HOLD_LOCKON) == 0) {
        while (obj != NULL) {
            ox = obj->fieldPosition.x;
            oy = obj->fieldPosition.y;
            dx = px - ox;
            dy = py - oy;

            if (VectorLength2D(dx, dy) <= 0x3000 && (dx > -0x8000 && dx < 0x8000) && (dy > -0x8000 && dy < 0x8000) && obj->fieldPosition.ground == gFieldState->actor.fieldPosition.ground) {
                if (obj->kind == FLD_OBJ_KIND_FIXTURE) {
                    gLockonDoorPosition[0] = obj->fieldPosition.x;
                    gLockonDoorPosition[1] = obj->fieldPosition.y;
                    gLockonDoorPosition[2] = obj->fieldPosition.z;
                    work->targets[count++] = obj;
                    work->targetCount++;
                } else {
                    work->targets[count++] = obj;
                    work->targetCount++;
                }
            }

            if (count > 6) {
                break;
            }

            obj = ListPoolNext(&obj->node);
        }

        if (work->targetCount != 0) {
            nsel = 0;

            for (i = 0; i < work->targetCount; i++) {
                if (LockonIsInFront(gFieldState->actor.angle, px, py, work->targets[i])) {
                    work->selected = i;
                    list[nsel++] = i;
                }
            }

            if (nsel > 1) {
                work->selected = LockonPickNearest(px, py, work, nsel, list);
            }
        }
    }

    if (work->selected >= 0) {
        gFieldState->lockonTarget = work->targets[work->selected];
    } else {
        gFieldState->lockonTarget = NULL;
        work->unk_30 = 0;
    }

    work->prevSelected = work->selected;
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

#define CLAMP_LABEL(v, edge, limit, dest) \
    do { \
        if ((edge) > (limit)) { \
            (v) = (dest); \
        } \
    } while (0)
void task_lockon_2(LockonWork* work) {
    FldObj* obj;
    s32 x;
    s32 y;
    union {
        s32 coord;
        u8 counter;
    } x2, y2;

    if (gFieldState->flags & FIELD_FLAG_ROOM_CREATE) {
        return;
    }

    obj = work->targets[work->selected];

    if (obj->kind == FLD_OBJ_KIND_NPC) {
        return;
    }

    x = (obj->fieldPosition.x >> 8) - (gFieldState->x >> 8);
    x2.coord = x + 12;
    y = (obj->fieldPosition.y >> 8) + (obj->fieldPosition.z >> 8) - (gFieldState->y >> 8) - obj->height;
    y2.coord = y - 8;

    CLAMP_LABEL(x2.coord, x + 60, DISPLAY_WIDTH, 192);
    CLAMP_LABEL(y2.coord, y, DISPLAY_HEIGHT, 152);

    x2.counter = work->timer++;
    y2.counter = x2.counter;

    if (y2.counter > 10) {
        work->timer = 0;
    }

    if (gFieldState->lockonTarget == NULL) {
        return;
    }

    if (work->selected < 0) {
        return;
    }

#ifdef VERSION_EU
    {
        FldObj* obj = work->targets[work->selected];
        s32 projectedY = (obj->fieldPosition.y >> 8) + (obj->fieldPosition.z >> 8) - (gFieldState->y >> 8);

        DrawSprite((obj->fieldPosition.x >> 8) - (gFieldState->x >> 8), projectedY - obj->height + 40, work->gfx, work->tiles, work->palette, NULL, SPRITE_PRIORITY(1), -0x100E - (((s16)projectedY >> 8) << 2));
    }
#else
    obj = work->targets[work->selected];
    DrawSprite((obj->fieldPosition.x >> 8) - (gFieldState->x >> 8), (obj->fieldPosition.y >> 8) + (obj->fieldPosition.z >> 8) - (gFieldState->y >> 8) - obj->height + 40, work->gfx, work->tiles, work->palette, NULL, 0, -0x100E - ((work->targets[work->selected]->fieldPosition.y >> 8) << 2));
#endif
}

#undef CLAMP_LABEL
void task_lockon_3(LockonWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    gFieldState->lockonTarget = NULL;
    EwramFree(gLockonDoorPosition);
    gLockonDoorPosition = NULL;
}

s32 VectorLength2D(s32 x, s32 y) {
    return (u16)Sqrt(x * x + y * y);
}

s32 NormalizeVector2D8(s32* x, s32* y) {
    s32 length = VectorLength2D(*x, *y);

    if (length > 0) {
        *x = (*x << 8) / length;
        *y = (*y << 8) / length;
    }

    return length;
}

s8 LockonPickNearest(s32 px, s32 py, LockonWork* work, s8 n, s8* list) {
    s8 i;
    s8 best;
    s32 bestDist;
    FldObj* target;
    s32 dist;
    s32 dx;
    s32 dy;

    best = LOCKON_TARGET_NONE;
    bestDist = 0x10000;

    for (i = 0; i < n; i++) {
        target = work->targets[list[i]];

        if (target != NULL) {
            dx = target->fieldPosition.x;
            dy = target->fieldPosition.y;
            dist = VectorLength2D(dx - px, dy - py);

            if (bestDist > dist) {
                bestDist = dist;
                best = i;
            }
        }
    }

    if (best != LOCKON_TARGET_NONE) {
        return list[best];
    }

    return best;
}

void LockonClearTargets(LockonWork* work) {
    s8 i;

    if ((gFieldState->flags & FIELD_FLAG_HOLD_LOCKON) == 0) {
        work->selected = LOCKON_TARGET_NONE;

        for (i = 0; i < 8; i++) {
            work->targets[i] = NULL;
        }

        work->targetCount = 0;
    }
}

u8 LockonIsInFront(u16 angle, s32 px, s32 py, FldObj* target) {
    s32 x;
    s32 y;
    s32 sn;
    s32 cs;
    s32 dot;

    if (target != NULL) {
        x = target->fieldPosition.x - px;
        y = target->fieldPosition.y - py;
        sn = SIN(angle);
        cs = -COS(angle);
        NormalizeVector2D8(&x, &y);
        dot = (sn * x >> 8) + (y * cs >> 8);

        if (target->kind == FLD_OBJ_KIND_FIXTURE) {
            if (dot > 99) {
                return TRUE;
            }
        } else {
            if (dot > 19) {
                return TRUE;
            }
        }
    }

    return FALSE;
}

void LockonGetDoorScreenPos(s32* x, s32* y) {
    if (gLockonDoorPosition != NULL) {
        *x = (gLockonDoorPosition[0] >> 8) - (gFieldState->x >> 8);
        *y = (gLockonDoorPosition[1] >> 8) + (gLockonDoorPosition[2] >> 8) - (gFieldState->y >> 8) - 24;
    } else {
        *x = 0;
        *y = 0;
    }
}

TaskDesc gTaskDescLockon = {
    "task_lockon",
    (TaskInitFunc)task_lockon_0,
    (TaskUpdateFunc)task_lockon_1,
    (TaskDrawFunc)task_lockon_2,
    (TaskDestroyFunc)task_lockon_3,
    sizeof(LockonWork),
};
