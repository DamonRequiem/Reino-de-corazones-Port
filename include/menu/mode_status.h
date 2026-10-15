#ifndef GUARD_MODE_STATUS_H
#define GUARD_MODE_STATUS_H

#include "types.h"

u8* CopyNumberTiles(u8* dst, s32 value, u16 digits);
void LoadStatusNumberTiles();
void mode_status_0();
void mode_status_1();
void mode_status_2();

#endif /* GUARD_MODE_STATUS_H */
