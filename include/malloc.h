#ifndef GUARD_MALLOC_H
#define GUARD_MALLOC_H

#include "types.h"

typedef struct HeapBlock {
    s32 size;
    struct HeapBlock* prevFree;
    struct HeapBlock* nextFree;
    struct HeapBlock* prev;
    struct HeapBlock* next;
    u32 allocFlag;
    const void* name;
    struct HeapBlock* self;
} HeapBlock;

typedef struct Heap {
    HeapBlock* start;
    HeapBlock* end;
    u8 allocFlag;
    const void* name;
} Heap;

void HeapInit(void* addr, u32 size, Heap* heap);
void* HeapAlloc(u32 size, Heap* heap);
void HeapFree(const void* ptr, Heap* heap);
s32 HeapGetBlockSize(void* ptr, Heap* heap);
void HeapUnlinkFreeBlock(HeapBlock* block);
u8 HeapContains(const void* ptr, Heap* heap);
HeapBlock* HeapFindFreeBlock(s32 size, Heap* heap);
void EwramHeapInit(void* addr, u32 size);
void IwramHeapInit(void* addr, u32 size);
void* EwramAlloc(u32 size);
void* IwramAlloc(u32 size);
void EwramFree(const void* ptr);
void IwramFree(const void* ptr);
void SetEwramHeapName(const void* name);
void SetIwramHeapName(const void* name);



#define EWRAM_HEAP_SIZE 0x34000
#define IWRAM_HEAP_SIZE 0x6800

extern u8 gEwramHeapStart[];
extern u8 gIwramHeapStart[];

#endif
