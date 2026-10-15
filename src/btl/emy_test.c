/**
 * emy_test.c
 * Debug Test Enemy
 */

#include "task_descriptors.h"
#include "sprites_emy.h"
#include "enemy_common.h"
#include "emy_tasks.h"
#include "anim.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "enemy_types.h"
#include "taskpool.h"
#include "types.h"
#include "enemy_ids.h"

static const AnimDef sEmyTestCommonAnimDefs[3] = {
    { gEmyTestFrames, gEmyTestAnims, gEmyTestTiles, 0 },
    { gEmyTestFrames, gEmyTestAnims, gEmyTestTiles, 0 },
    { gEmyTestFrames, gEmyTestAnims, gEmyTestTiles, 0 },
};

static const EmyDef sEmyTestDef = { gEmyTestPalette, sEmyTestCommonAnimDefs, 0, 130, 20, 60, 64, 32, 32, 10, 0, { ENEMY_DEFENDER, 260, 16, 8, 16, 100, 0 } };

void task_emy_test_0(EmyWork* work, void* obj) {
    EmyInit(work, &sEmyTestDef, obj);
    work->actor.maxHp = 0xBB8;
    work->actor.hp = 0xBB8;
    work->actor.flags |= BTLOBJ_FLAG_NEVER_USES_CARDS;
}

u8 task_emy_test_1(EmyWork* work) {
    EmyUpdateReaction(work);
    return EmyUpdateCommonStates(work);
}

void task_emy_test_2(EmyWork* work) {
    EmyDraw(work);
}

void task_emy_test_3(EmyWork* work) {
    EmyReleaseResources(work);
}

TaskDesc gTaskDescEmyTest = {
    "task_emy_test",
    (TaskInitFunc)task_emy_test_0,
    (TaskUpdateFunc)task_emy_test_1,
    (TaskDrawFunc)task_emy_test_2,
    (TaskDestroyFunc)task_emy_test_3,
    sizeof(EmyWork),
};
