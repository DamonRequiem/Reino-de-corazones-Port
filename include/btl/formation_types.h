#ifndef GUARD_FORMATION_TYPES_H
#define GUARD_FORMATION_TYPES_H

#include "types.h"
#include "macros.h"

typedef struct BtlFormStep {
    u32 id;
    s16 x;
    s16 y;
    s16 z;
    s16 delay;
} BtlFormStep;

typedef struct BtlFormEntry {
    s16 count;
    const BtlFormStep* steps;
    u16 delay;
} BtlFormEntry;

typedef struct BtlFormList {
    s16 count;
    const BtlFormEntry* const* entries;
    s16 threshold;
} BtlFormList;

STATIC_ASSERT(sizeof(BtlFormStep) == 12, BtlFormStepSize);
STATIC_ASSERT(sizeof(BtlFormEntry) == 12, BtlFormEntrySize);
STATIC_ASSERT(sizeof(BtlFormList) == 12, BtlFormListSize);

#endif
