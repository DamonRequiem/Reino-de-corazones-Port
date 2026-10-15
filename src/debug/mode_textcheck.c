/**
 * mode_textcheck.c
 * Debug Text Check
 */

#include "registration_data.h"
#include "display.h"
#include "taskpool.h"
#include "card_api.h"
#include "mode.h"
#include "types.h"

#ifdef VERSION_EU

static TaskPool sTextCheckTasks;

static u32 sTextCheckMessageId;

void Mode_textcheck_0() {
    sTextCheckMessageId = 0;
    SetBgMode0();
    SetupBg(0, 0, 28, 14);
    TaskPoolInit(&sTextCheckTasks, 1);
    CreateCardMessageTask(&sTextCheckTasks, 0, sTextCheckMessageId);
}

void Mode_textcheck_1() {
    if (!IsMessageWindowOpen()) {
        sTextCheckMessageId++;

        if (sTextCheckMessageId == 179) {
            sTextCheckMessageId = 0;
        }

        CreateCardMessageTask(&sTextCheckTasks, 0, sTextCheckMessageId);
    }

    TaskPoolUpdate(&sTextCheckTasks);
    TaskPoolDraw(&sTextCheckTasks);
}

void Mode_textcheck_2() {
    TaskPoolDestroy(&sTextCheckTasks);
}

Mode gModeTextCheck = {
    "Mode_textcheck",
    (ModeInitFunc)Mode_textcheck_0,
    Mode_textcheck_1,
    Mode_textcheck_2,
};

#endif
