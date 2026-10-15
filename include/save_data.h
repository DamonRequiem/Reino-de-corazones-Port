#ifndef GUARD_SAVE_DATA_H
#define GUARD_SAVE_DATA_H

#include "save_types.h"
#include "types.h"

void MakeSaveHeaderData(SaveHeaderData* data, s16 file);
void MakeSaveSystem(SaveFileLarge* data);
void MakeSaveFileLarge(SaveFileLarge* data);
void MakeSaveFileSmall(SaveFileSmall* data);
void ApplySaveHeaderData(SaveHeaderData* data);
void ApplySaveSystem(SaveFileLarge* data);
void ApplySaveFileLarge(SaveFileLarge* data);
void ApplySaveFileSmall(SaveFileSmall* data);

#endif
