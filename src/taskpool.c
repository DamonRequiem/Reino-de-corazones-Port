/**
 * taskpool.c
 * Task Pool Management
 */

#include "listpool.h"
#include "taskpool.h"
#include "malloc.h"
#include "main.h"
#include <stddef.h>
#include "types.h"

Task* TaskDestroy(TaskPool* pool, Task* task) {
    if (task->desc->destroy != NULL) {
        task->desc->destroy(task->work);
    }

    EwramFree(task->work);

    return ListPoolRelease(&task->node, pool);
}

void TaskKill(TaskPool* pool, Task* task) {
    if (task->desc->destroy != NULL) {
        task->desc->destroy(task->work);
    }

    EwramFree(task->work);

    ListPoolRelease(&task->node, pool);
}

Task* TaskCreate(TaskPool* pool, TaskDesc* desc, const void* arg) {
    Task* task;

    task = ListPoolFirstFree(pool);

    if (task == NULL) {
        return NULL;
    }

    if (desc->workSize > 0) {
        task->work = EwramAlloc(desc->workSize);

        if (task->work == NULL) {
            return NULL;
        }
    } else {
        task->work = NULL;
    }

    task->desc = desc;
    task->update = desc->update;
    ListPoolActivate(&task->node, pool);

    if (desc->init != NULL) {
        desc->init(task->work, arg);
    }

    return task;
}

void TaskPoolInit(TaskPool* pool, s32 count) {
    Task* task;
    s32 i;

    pool->tasks = EwramAlloc(count * sizeof(Task));

    if (pool->tasks == NULL) {
        return;
    }

    ListPoolInit(pool);

    for (i = 0; i < count; i++) {
        task = &((Task*)pool->tasks)[i];
        ListPoolAddFree(&task->node, pool, task);
    }
}

void TaskPoolUpdate(TaskPool* pool) {
    Task* task;

    task = ListPoolFirst(&pool->head);

    while (task != NULL) {
        if (task->update != NULL && task->update(task->work, task) == 0) {
            task = TaskDestroy(pool, task);
        } else {
            task = ListPoolNext(&task->node);
        }
    }
}

void TaskPoolDraw(TaskPool* pool) {
    Task* task;

    task = ListPoolFirst(&pool->head);

    while (task != NULL) {
        if (task->desc->draw != NULL) {
            task->desc->draw(task->work);
        }

        task = ListPoolNext(&task->node);
    }
}

void TaskPoolDestroy(TaskPool* pool) {
    Task* task;

    task = ListPoolFirst(&pool->head);

    while (task != NULL) {
        task = TaskDestroy(pool, task);
    }

    EwramFree(pool->tasks);
}

void func_08000F30(TaskPool* pool) {
    Task* task;

    task = ListPoolFirst(&pool->head);

    if (task != NULL) {
        do {
            task = ListPoolNext(&task->node);
        } while (task != NULL);
    }
}

u8 IsTaskActive(Task* task) {
    if (task == NULL || (task->node.flags & LIST_NODE_FLAG_ACTIVE) == 0) {
        return FALSE;
    }

    return TRUE;
}

u8 IsTaskActiveNamed(Task* task, const char* name) {
    if (task == NULL || name == NULL || task->desc->name != name || (task->node.flags & LIST_NODE_FLAG_ACTIVE) == 0) {
        return FALSE;
    }

    return TRUE;
}

const char* GetTaskName(Task* task) {
    return task->desc->name;
}

void SetTaskUpdate(Task* task, TaskUpdateFunc update) {
    task->update = update;
}

s32 func_08000F90() {
    return 0;
}
