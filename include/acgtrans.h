#ifndef GUARD_ACGTRANS_H
#define GUARD_ACGTRANS_H

#include "types.h"
#include "taskpool.h"

typedef struct AcgTransWork {
    u8* dst;
    const u8* src;
    u16 size;
    u16 chunkSize;
    u16 transferredBytes;
    u32 bg;
} AcgTransWork;

typedef struct AcgTransConfig {
    const u8* src;
    u8* dst;
    u16 size;
    u16 frames;
    u32 bg;
} AcgTransConfig;

void CreateBgTileTransferTask(TaskPool* pool, s32 bg, u16 tile, u16 count, u16 frames, const u8* src);

#endif /* GUARD_ACGTRANS_H */
