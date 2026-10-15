/**
 * bos_pc_event.c
 * Parasite Cage Boss Event Animation
 */

#include "bos6.h"
#include "taskpool.h"
#include "types.h"

static s32 Square(s32 x) {
    return x * x;
}

s32 BosPcStartEventAnim(Task* task) {
    PcWork* work;

    work = task->work;
    BosPcSetAnim(work, 13);
    BosPcUpdateAnim(work);
}
