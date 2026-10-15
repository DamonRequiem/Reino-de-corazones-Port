/**
 * btl_born.c
 * Enemy Spawn Sequence
 */

#include "obj_api.h"
#include "key_state.h"
#include "btl3.h"
#include "songs.h"
#include "btl3_tasks.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "btl_effect.h"
#include "m4a_song.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "engine_math.h"

TaskDesc gTaskDescBtlBorn = {
    "task_btl_born",
    (TaskInitFunc)task_btl_born_0,
    (TaskUpdateFunc)task_btl_born_1,
    NULL,
    NULL,
    sizeof(BtlBornWork),
};

void task_btl_born_0(BtlBornWork* work, BtlBornArgs* args) {
    work->pos = args->pos;
    work->desc = args->desc;
    work->flags = args->flags;
    work->tileCount = args->tileCount;
}

u8 task_btl_born_1(BtlBornWork* work) {
    if (!BgFxIsActive()) {
        ClampBattlePosition(&work->pos.x, &work->pos.y, -24, -12);

        if (!IsSongPlaying(SONG_EF_MON_UP)) {
            m4aSongNumStart(SONG_EF_MON_UP);
        }

        if (!CanAllocObjTiles(work->tileCount)) {
            gBtlWork->pendingEnemies--;
            return 0;
        }

        if (!CanAllocObjPalette(1)) {
            gBtlWork->pendingEnemies--;
            return 0;
        }

        if (work->flags & SPAWN_FLAG_LARGE_EFFECT) {
            BgFxStartEnemySpawn(work->pos.x, work->pos.y,
                          work->pos.z - 0x1000, Q_8_8(2));
        } else {
            BgFxStartEnemySpawn(work->pos.x, work->pos.y,
                          work->pos.z - 0x800, Q_8_8(1));
        }

        TaskCreate(&gBtlWork->taskPools[0], work->desc, work);
        return 0;
    }

    return 1;
}
