/**
 * mode_chkmov.c
 * Debug Movie Check
 */

#include "card_api.h"
#include "display.h"
#include "gba/keys.h"
#include "key.h"
#include "malloc.h"
#include "mode_chkmov.h"
#include "registration_data.h"
#include "taskpool.h"
#include "mode.h"
#include <stddef.h>
#include "types.h"
#include "mode_movie.h"

#ifdef VERSION_EU

static MovieDebugWork* sMovieDebugWorkEu;

extern const char gMovieDebugTextEu_0812F6D4[];
extern const char gMovieDebugTextEu_0812F6F4[];

extern const MovieDebugEntry gMovieDebugEntriesEu[5];

void mode_chkmov_0(s32 arg) {
    sMovieDebugWorkEu = EwramAlloc(sizeof(MovieDebugWork));
    SetBgMode0();
    sMovieDebugWorkEu->index = 0;
    TaskPoolInit(&sMovieDebugWorkEu->pool, 10);
    TaskCreate(&sMovieDebugWorkEu->pool, &gTaskDescPrint, NULL);
}

void mode_chkmov_1() {
    u16 cancel = GetKeysPressed() & B_BUTTON;

    if (cancel) {
        ModeRequest(&gModeDebug, 0);
        return;
    }

    if (GetKeysRepeat() & DPAD_LEFT) {
        sMovieDebugWorkEu->index--;
    }

    if (GetKeysRepeat() & DPAD_RIGHT) {
        sMovieDebugWorkEu->index++;
    }

    if (sMovieDebugWorkEu->index < 0) {
        sMovieDebugWorkEu->index = 4;
    }

    if (sMovieDebugWorkEu->index > 4) {
        sMovieDebugWorkEu->index = 0;
    }

    if (GetKeysPressed() & A_BUTTON) {
        ModeRequestHeapReset(&gModeMovie, gMovieDebugEntriesEu[sMovieDebugWorkEu->index].movie);
        return;
    }

    PrintString(0, 0, 0, gMovieDebugTextEu_0812F6D4);
    PrintNumber(0, 0, 0, sMovieDebugWorkEu->index);
    PrintString(5, 0, 0, gMovieDebugTextEu_0812F6F4);
    PrintString(7, 0, 0, gMovieDebugEntriesEu[sMovieDebugWorkEu->index].label);
    TaskPoolUpdate(&sMovieDebugWorkEu->pool);
    TaskPoolDraw(&sMovieDebugWorkEu->pool);
}

void mode_chkmov_2() {
    TaskPoolDestroy(&sMovieDebugWorkEu->pool);
    EwramFree(sMovieDebugWorkEu);
}

const MovieDebugEntry gMovieDebugEntriesEu[5] = {
    {MOVIE_OPENING, "OPENING"},
    {MOVIE_6F_GOAL, "6F_GOAL"},
    {MOVIE_12F_E2, "12F_E2"},
    {MOVIE_ENDING, "ENDING"},
    {MOVIE_RIKU_ENDING, "RIKU_ENDING"},
};

const char gMovieDebugTextEu_0812F6D4[] = "                              ";

const char gMovieDebugTextEu_0812F6F4[] = ": ";

Mode gModeMovieDebugEu = {
    "mode_chkmov",
    mode_chkmov_0,
    mode_chkmov_1,
    mode_chkmov_2,
};

#endif
