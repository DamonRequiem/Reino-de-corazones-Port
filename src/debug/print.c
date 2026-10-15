/**
 * print.c
 * Debug Print Layer Task
 */

#include "registration_data.h"
#include "taskpool.h"
#include "card.h"
#include "types.h"

void task_print_0() {
    InitPrintLayer(0);
}

s32 task_print_1() {
    return 1;
}

void task_print_2() {
    ResetPrintLines();
}

void task_print_3() {
    FreePrintLayer();
}

TaskDesc gTaskDescPrint = {
    "task_print",
    (TaskInitFunc)task_print_0,
    (TaskUpdateFunc)task_print_1,
    (TaskDrawFunc)task_print_2,
    (TaskDestroyFunc)task_print_3,
    sizeof(PrintWork),
};
