/**
 * mode_continue.c
 * Continue Screen
 */

#include "continue_ui.h"
#include "map_api.h"
#include "mode.h"
#include "continue_types.h"
#include "game_state.h"
#include "gba/syscall.h"
#include <stddef.h>
#include "taskpool.h"

static TaskPool sContinueTaskPool;
static Task* sContinueTask;

static void Continue_0() {
    TaskPoolInit(&sContinueTaskPool, 2);

    if ((gGameState.flags & GAME_FLAG_RIKU) == 0) {
        sContinueTask = TaskCreate(&sContinueTaskPool, &gTaskDescContinueSora, NULL);
    } else {
        sContinueTask = TaskCreate(&sContinueTaskPool, &gTaskDescContinueRiku, NULL);
    }
}

void ContinueModeUpdate() {
    ContinueWork* work;

    TaskPoolUpdate(&sContinueTaskPool);
    TaskPoolDraw(&sContinueTaskPool);
    work = sContinueTask->work;

    if (work->state == CONTINUE_STATE_DONE) {
        switch (work->cursor) {
        case CONTINUE_OPTION_CONTINUE:
            RequestMapMode();
            break;
        case CONTINUE_OPTION_RETURN_TO_TITLE:
#ifdef VERSION_EU
            DoSoftReset();
#else
            SoftReset(RESET_ALL);
#endif
            break;
        }
    }
}

static void Continue_2() {
    TaskPoolDestroy(&sContinueTaskPool);
}

Mode gModeContinue = {
    "Continue",
    (ModeInitFunc)Continue_0,
    ContinueModeUpdate,
    Continue_2,
};
