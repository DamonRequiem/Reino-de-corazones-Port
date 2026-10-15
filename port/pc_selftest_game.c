/*
 * pc_selftest_game.c
 * Self-tests that need the game's own types (compiled with the game flags).
 * Run with: khcom_headless --selftest-game
 */
#include <string.h>
#include "card.h"

void ClearStockedCardSlots(CardBattleWork* work);

/* Reproduces the sleight crash seen on a player's PC (frame 106290): the
 * Magic and Item lists have no slots (NULL) but the @bug loop writes to them.
 * Returns how many slots of the main list were cleared. */
int PcSelfTestClearStockedSlots(void) {
    static CardSlot mainSlots[8];
    static CardBattleWork work;
    int i, cleared = 0;

    memset(&work, 0, sizeof(work));
    for (i = 0; i < 8; i++)
        mainSlots[i].stocked = TRUE;
    work.slots[0] = mainSlots; /* main list */
    work.slots[1] = NULL;      /* magic: unused */
    work.slots[2] = NULL;      /* item: unused */
    work.slots[3] = NULL;      /* enemy cards: none */
    work.slotCounts[0] = 8;
    ClearStockedCardSlots(&work);
    for (i = 0; i < 8; i++)
        cleared += !mainSlots[i].stocked;
    return cleared;
}

#include "m4a.h"

/* For audio tests: the m4a PCM double buffer and its position. */
const void* PcTestPcmBuffer(int* size, int* dmaCounter, int* samplesPerVBlank) {
    SoundInfo* si = gSoundInfoPtr;
    if (si == NULL)
        return NULL;
    *size = (int)sizeof(si->pcmBuffer);
    *dmaCounter = si->pcmDmaCounter;
    *samplesPerVBlank = si->pcmSamplesPerVBlank;
    return si->pcmBuffer;
}
