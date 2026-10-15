/**
 * btl_form.c
 * Enemy Formation Spawner
 */

#include "btl3.h"
#include "btl3_tasks.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "engine_math.h"
#include "formation_types.h"
#include "game_state.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "enemy_tile_counts.h"
#include "map_types.h"

TaskDesc gTaskDescBtlForm = {
    "task_btl_form",
    (TaskInitFunc)task_btl_form_0,
    (TaskUpdateFunc)task_btl_form_1,
    NULL,
    (TaskDestroyFunc)task_btl_form_3,
    sizeof(BtlFormWork),
};

u16 GetBtlFormEntryTileCount(const BtlFormEntry* list) {
    u16 total;
    s32 i;

    total = 0;

    for (i = 0; i < list->count; i++) {
        total += gEnemyTileCounts[list->steps[i].id];
    }

    return total;
}

void task_btl_form_0(BtlFormWork* work, const BtlFormList* list) {
    s32 i;

    gBtlWork->flags |= BTL_FLAG_FORMATION_ACTIVE;
    work->flags = 0;
    work->list = list;
    work->entry = list->entries[0];
    work->timer = work->entry->delay;
    work->entryIndex = 1;
    work->stepTimer = 0;
    work->stepIndex = 0;
    work->nextTileCount = 0;
    work->waitTimer = 100;
    gBtlWork->pendingEnemies = 0;

    for (i = 0; i < list->count; i++) {
        gBtlWork->pendingEnemies += list->entries[i]->count;
    }
}

u8 task_btl_form_1(BtlFormWork* work) {
    const BtlFormList* list;
    const BtlFormStep* step;
    BtlObj* obj;
    s32 x;
    s32 y;
    s32 z;

    if (gBtlWork->flags & BTL_FLAG_STOP_SPAWNING) {
        return 0;
    }

    if (work->flags & BTL_FORM_FLAG_WAIT_NEXT_ENTRY) {
        list = work->list;

        if (list->threshold >= work->nextTileCount + gBtlWork->enemyTileCount) {
            if (work->nextTileCount == 0) {
                return 0;
            }

            work->entry = list->entries[work->entryIndex];
            work->timer = work->entry->delay;
            work->stepTimer = 0;
            work->stepIndex = 0;
            work->flags &= ~BTL_FORM_FLAG_WAIT_NEXT_ENTRY;
            work->entryIndex++;
            work->waitTimer = 100;
        }
    } else if (work->entry->count <= work->stepIndex) {
        if (work->waitTimer-- <= 0) {
            work->flags |= BTL_FORM_FLAG_WAIT_NEXT_ENTRY;

            if (gGameState.roomEffect != ROOM_EFFECT_LASTING_DAZE) {
                gGameState.flags &= ~GAME_FLAG_FIRST_STRIKE;
            }

            if (work->entryIndex >= work->list->count) {
                work->nextTileCount = 0;
                return 0;
            }

            work->nextTileCount = GetBtlFormEntryTileCount(work->list->entries[work->entryIndex]);
        }
    } else {
        if (work->timer > 0) {
            work->timer--;
        } else {
            if (work->timer == 0) {
                obj = gBtlWork->actor;
                work->x = (obj->x + 0x10000) >> 1;
                work->y = obj->y;
                work->z = 0;

                if (obj->flags & BTLOBJ_FLAG_FACING_LEFT) {
                    if (GetRandom() % 5 != 0) {
                        work->flags |= BTL_FORM_FLAG_MIRROR_X;
                    } else {
                        work->flags &= ~BTL_FORM_FLAG_MIRROR_X;
                    }
                } else {
                    if (GetRandom() % 5 == 0) {
                        work->flags |= BTL_FORM_FLAG_MIRROR_X;
                    } else {
                        work->flags &= ~BTL_FORM_FLAG_MIRROR_X;
                    }
                }

                work->timer = 0xFFFF;
            }

            step = &work->entry->steps[work->stepIndex];

            if (work->stepTimer >= step->delay) {
                if (work->flags & BTL_FORM_FLAG_MIRROR_X) {
                    x = work->x - (step->x << 8);
                } else {
                    x = work->x + (step->x << 8);
                }

                y = work->y + (step->y << 8);
                z = work->z + (step->z << 8);
                SpawnEnemy(step->id, x, y, z);
                work->stepIndex++;
            } else {
                work->stepTimer++;
            }
        }
    }

    return 1;
}

void task_btl_form_3() {
    gBtlWork->flags &= ~BTL_FLAG_FORMATION_ACTIVE;
}
