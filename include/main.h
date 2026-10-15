#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "types.h"
#include "taskpool.h"

struct Task;

void* GetIwramHeapStart();
u32 GetIwramHeapSize();
void InitSystem();
void VBlankIntr();
void HBlankIntrDummy();
void VCountIntrDummy();
void SerialIntrDummy();
void InitIntrTable();

void* GetEwramHeapStart();
u32 GetEwramHeapSize();
void VBlankIntrSio();

#endif /* GUARD_MAIN_H */
