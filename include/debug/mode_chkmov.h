#ifndef GUARD_MODE_CHKMOV_H
#define GUARD_MODE_CHKMOV_H

#include "mode.h"
#include "taskpool.h"
#include "types.h"

#ifdef VERSION_EU

typedef struct MovieDebugWork {
    TaskPool pool;
    s16 index;
} MovieDebugWork;

typedef struct MovieDebugEntry {
    s32 movie;
    const char* label;
} MovieDebugEntry;

extern Mode gModeMovieDebugEu;
#endif

#endif
