#ifndef GUARD_TASKPOOL_H
#define GUARD_TASKPOOL_H

#include "types.h"
#include "listpool.h"
#include "macros.h"

typedef struct TaskPool {
    ListPool head;
    void* tasks;
} TaskPool;

struct Task;

typedef void (*TaskInitFunc)(void* work, const void* arg);
typedef u8 (*TaskUpdateFunc)(void* work, struct Task* task);
typedef void (*TaskDrawFunc)(void* work);
typedef void (*TaskDestroyFunc)(void* work);

typedef struct TaskDesc {
    const char* name;
    TaskInitFunc init;
    TaskUpdateFunc update;
    TaskDrawFunc draw;
    TaskDestroyFunc destroy;
    s32 workSize;
} TaskDesc;

typedef struct Task {
    TaskDesc* desc;
    void* work;
    u8 unk_08[0x04];
    ListNode node;
    TaskUpdateFunc update;
} Task;

STATIC_ASSERT(sizeof(TaskPool) == 0x14, TaskPoolSize);
STATIC_ASSERT(sizeof(Task) == 0x24, TaskSize);

Task* TaskCreate(TaskPool* pool, TaskDesc* desc, const void* arg);
Task* TaskDestroy(TaskPool* pool, Task* task);
void TaskKill(TaskPool* pool, Task* task);
void func_08000F30(TaskPool* pool);
u8 IsTaskActive(Task* task);
u8 IsTaskActiveNamed(Task* task, const char* name);
const char* GetTaskName(Task* task);
void SetTaskUpdate(Task* task, TaskUpdateFunc update);
void TaskPoolInit(TaskPool* pool, s32 count);
void TaskPoolUpdate(TaskPool* pool);
void TaskPoolDraw(TaskPool* pool);
void TaskPoolDestroy(TaskPool* pool);
s32 func_08000F90();

#define TASK_CREATE_IF_INACTIVE(task, pool, desc, arg) \
    do { \
        if (!IsTaskActive(task)) { \
            (task) = TaskCreate(pool, desc, arg); \
        } \
    } while (0)

#endif
