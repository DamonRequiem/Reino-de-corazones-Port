/**
 * card_deck_equip.c
 * Deck Equip Dialogs
 */

#include "system_state.h"
#include "msg_api.h"
#include <string.h>
#include "text.h"
#include "monsgage.h"
#include "obj_api.h"
#include "taskpool.h"
#include "key.h"
#include "card.h"
#include "sprites_card.h"
#include "gba/keys.h"
#include "jiminy_data.h"
#include "common_text.h"
#include "card_api.h"
#include "card_types.h"
#include "save_types.h"
#include "types.h"
#include "deck_equip_suffix.inc"
#include <stddef.h>
#include "card_deckmenu2.h"
#include "ui_text.h"
#include "sprite_palettes.h"
#include "text_types.h"
#include "gba/defines.h"
#include "macros.h"

void Deck_Equip_0(DeckConfirmWork* work, u8* active) {
    work->textSlotCount = 0;
    work->textSlotCount2 = 0;
    work->textSlotCount3 = 0;
    InitTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    InitTextSlots(work->textSlots2, ARRAY_COUNT(work->textSlots2));
    InitTextSlots(work->textSlots3, ARRAY_COUNT(work->textSlots3));
    work->textSlotCount = LoadTextSlots(GetDeckName(GetActiveDeckIndex()), work->textSlots);
    work->textSlotCount2 = LoadTextSlots(LOCALIZED_STRING(gDeckEquipText), work->textSlots2);
    work->palette = LoadObjPalette(gDialogBoxPalette, sizeof(gDialogBoxPalette));
    work->tiles = LoadObjTiles(gDialogBoxTiles, sizeof(gDialogBoxTiles));
    work->palette2 = LoadObjPalette(gCard00Palette, sizeof(gCard00Palette));
#ifdef VERSION_JP
    work->textSlotCount3 = LoadTextSlots((u16*)gDeckEquipSuffixText, work->textSlots3);
    work->x = (233 - GetTextSlotsWidth(work->textSlots, work->textSlotCount) - GetTextSlotsWidth(work->textSlots3, work->textSlotCount3)) / 2;
    work->x3 = work->x + GetTextSlotsWidth(work->textSlots, work->textSlotCount);
    work->y3 = 66;
    work->y = 66;
    work->x2 = (243 - GetTextSlotsWidth(work->textSlots2, work->textSlotCount2)) / 2;
    work->y2 = 82;
#else
    work->x = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots, work->textSlotCount)) / 2;
#ifdef VERSION_EU
    work->x2 = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots2, work->textSlotCount2)) / 2;

    if (gLanguage - 1 <= 1) {
        work->y = 66;
        work->y2 = 82;
    } else {
        work->y = 82;
        work->y2 = 66;
    }
#else
    work->y = 82;
    work->x2 = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots2, work->textSlotCount2)) / 2;
    work->y2 = 66;
#endif
#endif
    work->unk_790 = 0;
    work->unk_7A4 = 0;
    work->active = active;
    *active = 1;
}

void DeckErrorCpInit(DeckConfirmWork* work, u8* active) {
    work->textSlotCount = 0;
    work->textSlotCount2 = 0;
    work->textSlotCount3 = 0;
    InitTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    InitTextSlots(work->textSlots2, ARRAY_COUNT(work->textSlots2));
    InitTextSlots(work->textSlots3, ARRAY_COUNT(work->textSlots3));
#ifdef VERSION_JP
    work->textSlotCount = 0;
    work->textSlotCount2 = LoadTextSlots(gDeckErrorCpText, work->textSlots2);
#elif defined(VERSION_EU)
    work->textSlotCount2 = LoadTextSlots(GetLocalizedString(&gDeckErrorCpTextByLanguage), work->textSlots2);
#else
    work->textSlotCount2 = LoadTextSlots(gDeckErrorCpText, work->textSlots2);
#endif
    work->palette = LoadObjPalette(gDialogBoxPalette, sizeof(gDialogBoxPalette));
    work->tiles = LoadObjTiles(gDialogBoxTiles, sizeof(gDialogBoxTiles));
    work->palette2 = LoadObjPalette(gCard00Palette, sizeof(gCard00Palette));
#ifdef VERSION_JP
    work->x2 = (207 - GetTextSlotsWidth(work->textSlots2, work->textSlotCount2)) / 2;
    work->y2 = 62;
#elif defined(VERSION_EU)
    work->x2 = (DISPLAY_WIDTH - GetTextSlotsMaxLineWidth(work->textSlots2, work->textSlotCount2)) / 2;
    work->y2 = 68;
#else
    work->x2 = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots2, work->textSlotCount2)) / 2;
    work->y2 = 68;
#endif
    work->unk_790 = 0;
    work->unk_7A4 = 0;
    work->active = active;
    active[0] = 1;
}

void DeckErrorNoAttackCardInit(DeckConfirmWork* work, u8* active) {
    work->textSlotCount = 0;
    work->textSlotCount2 = 0;
    InitTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    InitTextSlots(work->textSlots2, ARRAY_COUNT(work->textSlots2));
    InitTextSlots(work->textSlots3, ARRAY_COUNT(work->textSlots3));
#ifdef VERSION_JP
    work->textSlotCount = 0;
    work->textSlotCount2 = LoadTextSlots(gDeckErrorNoAttackCardText, work->textSlots2);
#elif defined(VERSION_EU)
    work->textSlotCount2 = LoadTextSlots(GetLocalizedString(&gDeckErrorNoAttackCardTextByLanguage), work->textSlots2);
#else
    work->textSlotCount2 = LoadTextSlots(gDeckErrorNoAttackCardText, work->textSlots2);
#endif
    work->palette = LoadObjPalette(gDialogBoxPalette, sizeof(gDialogBoxPalette));
    work->tiles = LoadObjTiles(gDialogBoxTiles, sizeof(gDialogBoxTiles));
    work->palette2 = LoadObjPalette(gCard00Palette, sizeof(gCard00Palette));
    work->x = (250 - GetTextSlotsWidth(work->textSlots, work->textSlotCount)) / 2;
    work->y = 64;
#ifdef VERSION_JP
    work->x2 = (219 - GetTextSlotsWidth(work->textSlots2, work->textSlotCount2)) / 2;
#elif defined(VERSION_EU)
    work->x2 = (DISPLAY_WIDTH - GetTextSlotsMaxLineWidth(work->textSlots2, work->textSlotCount2)) / 2;
#else
    work->x2 = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots2, work->textSlotCount2)) / 2;
#endif
    work->y2 = 62;
    work->unk_790 = 0;
    work->unk_7A4 = 0;
    work->active = active;
    active[0] = 1;
}

void DeckErrorLastAttackCardInit(DeckConfirmWork* work, u8* active) {
    work->textSlotCount = 0;
    work->textSlotCount2 = 0;
    InitTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    InitTextSlots(work->textSlots2, ARRAY_COUNT(work->textSlots2));
    InitTextSlots(work->textSlots3, ARRAY_COUNT(work->textSlots3));
#ifdef VERSION_JP
    work->textSlotCount = LoadTextSlots(gDeckErrorAnyMoreText, work->textSlots);
    work->textSlotCount2 = LoadTextSlots(gDeckErrorLastAttackCardText, work->textSlots2);
#elif defined(VERSION_EU)
    work->textSlotCount2 = LoadTextSlots(GetLocalizedString(&gDeckErrorLastAttackCardTextByLanguage), work->textSlots2);
#else
    work->textSlotCount2 = LoadTextSlots(gDeckErrorLastAttackCardText, work->textSlots2);
#endif
    work->palette = LoadObjPalette(gDialogBoxPalette, sizeof(gDialogBoxPalette));
    work->tiles = LoadObjTiles(gDialogBoxTiles, sizeof(gDialogBoxTiles));
    work->palette2 = LoadObjPalette(gCard00Palette, sizeof(gCard00Palette));
    work->x = (242 - GetTextSlotsWidth(work->textSlots, work->textSlotCount)) / 2;
    work->y = 66;
    work->x2 = (242 - GetTextSlotsWidth(work->textSlots2, work->textSlotCount2)) / 2;
#ifdef VERSION_JP
    work->y2 = 82;
#else
    work->y2 = 68;
#endif
    work->unk_790 = 0;
    work->unk_7A4 = 0;
    work->active = active;
    active[0] = 1;
}

void DeckErrorDeckFullInit(DeckConfirmWork* work, u8* active) {
    work->textSlotCount = 0;
    work->textSlotCount2 = 0;
    InitTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    InitTextSlots(work->textSlots2, ARRAY_COUNT(work->textSlots2));
    InitTextSlots(work->textSlots3, ARRAY_COUNT(work->textSlots3));
#ifdef VERSION_JP
    work->textSlotCount = LoadTextSlots(gDeckErrorAnyMoreText, work->textSlots);
    work->textSlotCount2 = LoadTextSlots(gDeckErrorDeckFullText, work->textSlots2);
#elif defined(VERSION_EU)
    work->textSlotCount2 = LoadTextSlots(GetLocalizedString(&gDeckErrorDeckFullTextByLanguage), work->textSlots2);
#else
    work->textSlotCount2 = LoadTextSlots(gDeckErrorDeckFullText, work->textSlots2);
#endif
    work->palette = LoadObjPalette(gDialogBoxPalette, sizeof(gDialogBoxPalette));
    work->tiles = LoadObjTiles(gDialogBoxTiles, sizeof(gDialogBoxTiles));
    work->palette2 = LoadObjPalette(gCard00Palette, sizeof(gCard00Palette));
    work->x = (243 - GetTextSlotsWidth(work->textSlots, work->textSlotCount)) / 2;
    work->y = 66;
    work->x2 = (243 - GetTextSlotsWidth(work->textSlots2, work->textSlotCount2)) / 2;
#ifdef VERSION_JP
    work->y2 = 82;
#else
    work->y2 = 68;
#endif
    work->unk_7A4 = 0;
    work->unk_790 = 0;
    work->active = active;
    active[0] = 1;
}

s32 DeckConfirmUpdate() {
    if ((GetKeysPressed() & A_BUTTON) || (GetKeysPressed() & START_BUTTON) ||
        (GetKeysPressed() & B_BUTTON)) {
        return 0;
    }

    return 1;
}

void DeckConfirmDraw(DeckConfirmWork* work) {
    DrawTextSlots(work->x, work->y, work->textSlots, work->palette, 1, work->textSlotCount);
    DrawTextSlots(work->x2, work->y2, work->textSlots2, work->palette, 1, work->textSlotCount2);
    DrawTextSlots(work->x3, work->y3, work->textSlots3, work->palette, 1, work->textSlotCount3);
    DrawSprite(120, 80, gDialogBoxFrames[0], work->tiles, work->palette2, NULL, 0, 2);
}

void DeckConfirmDestroy(DeckConfirmWork* work) {
    FreeTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    FreeTextSlots(work->textSlots2, ARRAY_COUNT(work->textSlots2));
    FreeTextSlots(work->textSlots3, ARRAY_COUNT(work->textSlots3));
    ReleaseObjPalette(work->palette);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette2);
    work->active[0] = 0;
}
#ifdef VERSION_JP
#define DECK_PROMPT_LEFT_DX 30
#define DECK_PROMPT_RIGHT_DX 35
#define DECK_CLEAR_TEXT_Y 66
#else
#define DECK_PROMPT_LEFT_DX 20
#define DECK_PROMPT_RIGHT_DX 20
#define DECK_CLEAR_TEXT_Y 61
#endif
void Deck_Yes_No_0(DeckConfirmWork* work, u8* active) {
    work->textSlotCount = 0;
    work->textSlotCount2 = 0;
    InitTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    InitTextSlots(work->textSlots2, ARRAY_COUNT(work->textSlots2));
    InitTextSlots(work->textSlots3, ARRAY_COUNT(work->textSlots3));
    work->textSlotCount = LoadTextSlots(LOCALIZED_STRING(gDeleteCardConfirmText), work->textSlots);
    work->textSlotCount2 = LoadTextSlots(LOCALIZED_STRING(gYesChoiceText), work->textSlots2);
    work->textSlotCount3 = LoadTextSlots(LOCALIZED_STRING(gNoChoiceText), work->textSlots3);
    work->palette = LoadObjPalette(gDialogBoxPalette, sizeof(gDialogBoxPalette));
    work->tiles = LoadObjTiles(gDialogBoxTiles, sizeof(gDialogBoxTiles));
    work->palette2 = LoadObjPalette(gCard00Palette, sizeof(gCard00Palette));
    work->x = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots, work->textSlotCount)) / 2;
    work->y = 66;
    work->x2 = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots2, work->textSlotCount2)) / 2 - DECK_PROMPT_LEFT_DX;
    work->y2 = 88;
    work->x3 = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots3, work->textSlotCount3)) / 2 + DECK_PROMPT_RIGHT_DX;
    work->y3 = 88;
    work->unk_790 = 0;
    work->unk_7A4 = 0;
    work->active = active;
    active[0] = 1;
}

s32 DeckConfirmYesNoUpdate() {
    if ((GetKeysPressed() & A_BUTTON) || (GetKeysPressed() & B_BUTTON)) {
        return 0;
    }

    return 1;
}

void Deck_Clear_0(DeckConfirmWork* work, u8* active) {
    work->textSlotCount = 0;
    work->textSlotCount2 = 0;
    InitTextSlots(work->textSlots, ARRAY_COUNT(work->textSlots));
    InitTextSlots(work->textSlots2, ARRAY_COUNT(work->textSlots2));
    InitTextSlots(work->textSlots3, ARRAY_COUNT(work->textSlots3));
    work->textSlotCount = LoadTextSlots(LOCALIZED_STRING(gDeckClearConfirmText), work->textSlots);
    work->textSlotCount2 = LoadTextSlots(LOCALIZED_STRING(gYesChoiceText), work->textSlots2);
    work->textSlotCount3 = LoadTextSlots(LOCALIZED_STRING(gNoChoiceText), work->textSlots3);
    work->palette = LoadObjPalette(gDialogBoxPalette, sizeof(gDialogBoxPalette));
    work->tiles = LoadObjTiles(gDialogBoxTiles, sizeof(gDialogBoxTiles));
    work->palette2 = LoadObjPalette(gCard00Palette, sizeof(gCard00Palette));
    work->x = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots, work->textSlotCount)) / 2;
    work->x2 = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots2, work->textSlotCount2)) / 2 - DECK_PROMPT_LEFT_DX;
    work->y2 = 88;
    work->x3 = (DISPLAY_WIDTH - GetTextSlotsWidth(work->textSlots2, work->textSlotCount3)) / 2 + DECK_PROMPT_RIGHT_DX;
    work->y3 = 88;
    work->y = DECK_CLEAR_TEXT_Y;
    work->unk_790 = 0;
    work->unk_7A4 = 0;
    work->active = active;
    active[0] = 1;
}

void WriteCardSaveSlice(SaveLargeSlice* out) {
    s32 i;

    for (i = 0; i < 270; i++) {
        out->mapCardCounts[i] = gMapCardCounts[i];
    }

    for (i = 0; i < 999; i++) {
        out->cards[i] = gCardCollection[i];
    }

    for (i = 0; i < 3; i++) {
        memcpy(&out->decks[i], &gDecks[i], sizeof(Deck));
    }

    out->cardCount = gCardCount;
    out->activeDeck = GetActiveDeckIndex();
}

void ReadCardSaveSlice(SaveLargeSlice* in) {
    u16 i;

    for (i = 0; i < ARRAY_COUNT(gMapCardCounts); i++) {
        gMapCardCounts[i] = in->mapCardCounts[i];
    }

    for (i = 0; i < ARRAY_COUNT(gCardCollection); i++) {
        gCardCollection[i] = in->cards[i];
    }

    for (i = 0; i < ARRAY_COUNT(gDecks); i++) {
        gDecks[i] = in->decks[i];
    }

    gCardCount = in->cardCount;
    SetActiveDeckIndex(in->activeDeck);
}

void CopyMapCardInventory(SaveSmallSlice* out) {
    s32 i;

    for (i = 0; i <= 0x10D; i++) {
        out->mapCardCounts[i] = gMapCardCounts[i];
    }
}

void RestoreMapCardInventory(SaveSmallSlice* in) {
    u16 i;

    for (i = 0; i < ARRAY_COUNT(gMapCardCounts); i++) {
        gMapCardCounts[i] = in->mapCardCounts[i];
    }
}

TaskDesc gTaskDescDeckEquip = {
    "Deck Equip",
    (TaskInitFunc)Deck_Equip_0,
    (TaskUpdateFunc)DeckConfirmUpdate,
    (TaskDrawFunc)DeckConfirmDraw,
    (TaskDestroyFunc)DeckConfirmDestroy,
    sizeof(DeckConfirmWork),
};

TaskDesc gTaskDescDeckYesNo = {
    "Deck_Yes_No",
    (TaskInitFunc)Deck_Yes_No_0,
    (TaskUpdateFunc)DeckConfirmYesNoUpdate,
    (TaskDrawFunc)DeckConfirmDraw,
    (TaskDestroyFunc)DeckConfirmDestroy,
    sizeof(DeckConfirmWork),
};

TaskDesc gTaskDescDeckClear = {
    "Deck_Clear",
    (TaskInitFunc)Deck_Clear_0,
    (TaskUpdateFunc)DeckConfirmYesNoUpdate,
    (TaskDrawFunc)DeckConfirmDraw,
    (TaskDestroyFunc)DeckConfirmDestroy,
    sizeof(DeckConfirmWork),
};

TaskDesc gTaskDescDeckErrorCp = {
    "Deck Error",
    (TaskInitFunc)DeckErrorCpInit,
    (TaskUpdateFunc)DeckConfirmUpdate,
    (TaskDrawFunc)DeckConfirmDraw,
    (TaskDestroyFunc)DeckConfirmDestroy,
    sizeof(DeckConfirmWork),
};

TaskDesc gTaskDescDeckErrorNoAttackCard = {
    "Deck Error",
    (TaskInitFunc)DeckErrorNoAttackCardInit,
    (TaskUpdateFunc)DeckConfirmUpdate,
    (TaskDrawFunc)DeckConfirmDraw,
    (TaskDestroyFunc)DeckConfirmDestroy,
    sizeof(DeckConfirmWork),
};

TaskDesc gTaskDescDeckErrorLastAttackCard = {
    "Deck Error",
    (TaskInitFunc)DeckErrorLastAttackCardInit,
    (TaskUpdateFunc)DeckConfirmUpdate,
    (TaskDrawFunc)DeckConfirmDraw,
    (TaskDestroyFunc)DeckConfirmDestroy,
    sizeof(DeckConfirmWork),
};

TaskDesc gTaskDescDeckErrorDeckFull = {
    "Deck Error",
    (TaskInitFunc)DeckErrorDeckFullInit,
    (TaskUpdateFunc)DeckConfirmUpdate,
    (TaskDrawFunc)DeckConfirmDraw,
    (TaskDestroyFunc)DeckConfirmDestroy,
    sizeof(DeckConfirmWork),
};

#ifdef VERSION_EU
u8* gLeaveWorldTextByLanguage[5] = { gLeaveWorldText, gLeaveWorldText, gLeaveWorldText, gLeaveWorldText, gLeaveWorldText };
#endif
