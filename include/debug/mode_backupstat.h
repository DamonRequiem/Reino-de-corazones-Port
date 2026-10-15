#ifndef GUARD_MODE_BACKUPSTAT_H
#define GUARD_MODE_BACKUPSTAT_H

#include "types.h"

typedef struct BackupStatEntry {
    const char* name;
    s32 unk_04;
} BackupStatEntry;

void mode_backupstat_0();
void mode_backupstat_1();
void mode_backupstat_2();
void BackupStatApplyState();

#endif /* GUARD_MODE_BACKUPSTAT_H */
