#ifndef GUARD_ROMCRI_H
#define GUARD_ROMCRI_H

#include "types.h"

typedef struct RomcriEffWork {
    s16 timer;
    u8 angle;
} RomcriEffWork;

typedef struct RomcriEff2Work {
    s16 timer;
    u8 angle;
    u8 frame;
} RomcriEff2Work;

#endif /* GUARD_ROMCRI_H */
