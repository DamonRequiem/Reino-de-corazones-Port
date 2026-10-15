#ifndef GUARD_PC_ACDDMG_H
#define GUARD_PC_ACDDMG_H

#include "types.h"
#include "battle_actor_types.h"

typedef struct PcAcdDmgWork {
    s16 timer;
    s16 groundFrames;
    BtlObj* actor;
    u8 grounded;
} PcAcdDmgWork;

#endif /* GUARD_PC_ACDDMG_H */
