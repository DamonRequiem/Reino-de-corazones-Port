#ifndef GUARD_INTR_H
#define GUARD_INTR_H

#include "types.h"

typedef void (*IntrFunc)();

#define INTR_COUNT 14

extern vu16 gIntrCheck;

void EnableVBlankIntr();
void DisableVBlankIntr();
void EnableHBlankIntr();
void SetVBlankCallback(IntrFunc fn);
void ResetVBlankCallback();
void SetHBlankCallback(IntrFunc fn);
void SetVCountCallback(IntrFunc fn);
void ResetVCountCallback();
void SetSerialCallback(IntrFunc fn);
void ResetSerialCallback();
void SetTimer3Callback(IntrFunc fn);
void ResetTimer3Callback();
void ApplyIntrCallbacks();

void ResetHBlankCallback();

void DisableHBlankIntr();

#endif
