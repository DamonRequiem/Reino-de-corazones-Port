#ifndef GUARD_MODE_WLOGO_H
#define GUARD_MODE_WLOGO_H

#include "types.h"

typedef struct WLogoTaskWork {
    u8 worldId;
    s32 cameraOffsetY;
    s16 timer;
} WLogoTaskWork;

void WLogoInitWorldSelect();
void WLogoStartLogo(u8 world);

#endif
