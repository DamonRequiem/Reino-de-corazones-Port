#ifndef GUARD_BOS6_API_H
#define GUARD_BOS6_API_H

#include "types.h"

struct Task;

s32 BosPcStartEventAnim(struct Task* task);
void BosLstAdvanceEventStep(struct Task* task);

#endif
