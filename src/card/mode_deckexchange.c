/**
 * mode_deckexchange.c
 * Deck Exchange Mode and Deck Setup
 */

#include "msg_localized_data.h"
#include "registration_data.h"
#include "system_state.h"
#include "msg_api.h"
#include "mode_sio_api.h"
#include "card_battle.h"
#include "game_state.h"
#include "obj_api.h"
#include "engine_math.h"
#include "taskpool.h"
#include "card.h"
#include "sprites_card.h"
#include "card_ids.h"
#include "card_description_text.h"
#include "battle_work.h"
#include "card_api.h"
#include "card_description_data.h"
#include "mode.h"
#include <stddef.h>
#include "types.h"
#include "card_deckmenu2.h"
#include "card_types.h"

#ifndef VERSION_EU
static TaskPool sModeDeckExchangeTasks;

static u8 sModeDeckExchangeResult;

#endif

#ifndef VERSION_EU
void Mode_DeckExchange_0() {
    sModeDeckExchangeResult = DECK_MENU_RESULT_NONE;
    gSioTradeCardId = SIO_TRADE_CARD_NONE;
    TaskPoolInit(&sModeDeckExchangeTasks, 1);
    TaskCreate(&sModeDeckExchangeTasks, &gTaskDescDeckexchange, &sModeDeckExchangeResult);
}

void Mode_DeckExchange_1() {
    if (gSystemFlags & SYSTEM_FLAG_LINK_ACTIVE) {
        SioChgCardRecvSlotIds();
    } else {
        UpdatePlayTime();
    }

    TaskPoolUpdate(&sModeDeckExchangeTasks);
    TaskPoolDraw(&sModeDeckExchangeTasks);

    if (sModeDeckExchangeResult == DECK_MENU_RESULT_CLOSED) {
        ModeRequest(&gModeSioChgCard, gSioTradeCardId);
    }
}

void Mode_DeckExchange_2() {
    TaskPoolDestroy(&sModeDeckExchangeTasks);
}
#endif

void DarkPoint_0(DarkPointWork* work) {
    work->tiles = LoadObjTiles(gDarkPointTiles, sizeof(gDarkPointTiles));
    work->slideTimer = 8;
    work->x = -0x2000;
    SplitFourDigits(gBtlWork->darkPoints, &work->thousands);
}

s32 DarkPoint_1(DarkPointWork* work) {
    SplitFourDigits(gBtlWork->darkPoints, &work->thousands);

    if (work->slideTimer > 0) {
        ApproachValue(&work->x, 0, work->slideTimer);
        work->slideTimer--;
    }

    return 1;
}

void DarkPoint_2(DarkPointWork* work) {
    DrawSprite(work->x >> 8, 27, gDarkPointFrames[0], work->tiles, gCardBattleState->palette, NULL, 0, 30);

    if (work->hundreds != 0) {
        DrawSprite((work->x >> 8) + 11, 30, gDarkPointFrames[work->hundreds + 1], work->tiles, gCardBattleState->palette, NULL, 0, 29);
        DrawSprite((work->x >> 8) + 17, 30, gDarkPointFrames[work->tens + 1], work->tiles, gCardBattleState->palette, NULL, 0, 29);
        DrawSprite((work->x >> 8) + 23, 30, gDarkPointFrames[work->ones + 1], work->tiles, gCardBattleState->palette, NULL, 0, 29);
    } else if (work->tens != 0) {
        DrawSprite((work->x >> 8) + 15, 30, gDarkPointFrames[work->tens + 1], work->tiles, gCardBattleState->palette, NULL, 0, 29);
        DrawSprite((work->x >> 8) + 21, 30, gDarkPointFrames[work->ones + 1], work->tiles, gCardBattleState->palette, NULL, 0, 29);
    } else {
        DrawSprite((work->x >> 8) + 17, 30, gDarkPointFrames[work->ones + 1], work->tiles, gCardBattleState->palette, NULL, 0, 29);
    }
}

void DarkPoint_3(DarkPointWork* work) {
    ReleaseObjTiles(work->tiles);
}

void AddCardToDeckViaActive(u8 deck, u16 card) {
    u8 saved;

    saved = GetActiveDeckIndex();
    SetActiveDeckIndex(deck);
    AddCardToActiveDeck(card);
    SetActiveDeckIndex(saved);
}

void FillDebugCardCollection() {
#ifdef VERSION_EU
    u16 i;
    u16 n;

    n = 0;
    gCardCount = 999;

    for (i = 0; i < 170; i++) {
        gCardCollection[n++] = i;
    }

    for (i = 170; i < 380; i++) {
        gCardCollection[n++] = i;
    }

    for (i = 380; i < 450; i++) {
        gCardCollection[n++] = i;
    }

    for (i = 380; i < 450; i++) {
        gCardCollection[n++] = i;
    }

    for (i = 450; i < 526; i += 3) {
        gCardCollection[n++] = i;
    }

    gCardCollection[n++] = CARD_WHITE_MUSHROOM_2;
    gCardCollection[n++] = 529;
    gCardCollection[n++] = CARD_CREEPER_PLANT_2;
    gCardCollection[n++] = CARD_TORNADO_STEP_2;
    gCardCollection[n++] = CARD_CRESCENDO_2;
    gCardCollection[n++] = CARD_GUARD_ARMOR_1;
    gCardCollection[n++] = CARD_TRICKMASTER_1;
    gCardCollection[n++] = CARD_PARASITE_CAGE_1;
    gCardCollection[n++] = CARD_DARKSIDE_1;
    gCardCollection[n++] = CARD_CARD_SOLDIER_2;
    gCardCollection[n++] = CARD_HADES_9;
    gCardCollection[n++] = CARD_JAFAR_1;
    gCardCollection[n++] = CARD_OOGIE_BOOGIE_1;
    gCardCollection[n++] = CARD_URSULA_1;
    gCardCollection[n++] = CARD_HOOK_9;
    gCardCollection[n++] = CARD_DRAGON_MALEFICENT_1;
    gCardCollection[n++] = CARD_RIKU_9;
    gCardCollection[n++] = CARD_AXEL_9;
    gCardCollection[n++] = CARD_LARXENE_9;
    gCardCollection[n++] = CARD_VEXEN_9;
    gCardCollection[n++] = CARD_MARLUXIA_9;
    gCardCollection[n++] = CARD_LEXAEUS_9;
    gCardCollection[n++] = CARD_ANSEM_9;

    for (i = 0; i < 170; i++) {
        if (n < 999) {
            gCardCollection[n++] = i | CARD_FLAG_PREMIUM;
        }
    }

    for (i = 170; i < 240; i++) {
        if (n < 999) {
            gCardCollection[n++] = i | CARD_FLAG_PREMIUM;
        }
    }

    for (i = 0; i < 95; i++) {
        gCardCollection[n++] = CARD_ID(CARD_KINGDOM_KEY, 6);
    }
#endif
}

void BuildDebugKeybladeDeck(u8 deck) {
    AddCardToDeckViaActive(deck, 0);
    AddCardToDeckViaActive(deck, 1);
    AddCardToDeckViaActive(deck, 2);
    AddCardToDeckViaActive(deck, 3);
    AddCardToDeckViaActive(deck, 4);
    AddCardToDeckViaActive(deck, 5);
    AddCardToDeckViaActive(deck, 6);
    AddCardToDeckViaActive(deck, 7);
    AddCardToDeckViaActive(deck, 8);
    AddCardToDeckViaActive(deck, 9);
    AddCardToDeckViaActive(deck, 73);
    AddCardToDeckViaActive(deck, 74);
    AddCardToDeckViaActive(deck, 75);
    AddCardToDeckViaActive(deck, 76);
    AddCardToDeckViaActive(deck, 77);
    AddCardToDeckViaActive(deck, 78);
    AddCardToDeckViaActive(deck, 79);
    AddCardToDeckViaActive(deck, 80);
    AddCardToDeckViaActive(deck, 81);
    AddCardToDeckViaActive(deck, 82);
    AddCardToDeckViaActive(deck, 83);
    AddCardToDeckViaActive(deck, 84);
    AddCardToDeckViaActive(deck, 85);
    AddCardToDeckViaActive(deck, 86);
    AddCardToDeckViaActive(deck, 87);
    AddCardToDeckViaActive(deck, 88);
    AddCardToDeckViaActive(deck, 89);
    AddCardToDeckViaActive(deck, 90);
    AddCardToDeckViaActive(deck, 91);
    AddCardToDeckViaActive(deck, 92);
    AddCardToDeckViaActive(deck, 93);
}

void BuildDebugKingdomKeyDeck(u8 deck) {
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 5)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 7)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 4)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 5)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 4)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 3)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 4)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 5)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 6)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 7)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 6)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 5)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 4)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 3)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 4)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 5)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_BLIZZARD, 6)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_BLIZZARD, 5)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_CURE, 7)));
    AddCardToDeckViaActive(deck, ObtainCard(CARD_ID(CARD_CURE, 5)));
}

void BuildDebugMixedDeck(u8 deck) {
    AddCardToDeckViaActive(deck, 0);
    AddCardToDeckViaActive(deck, 1);
    AddCardToDeckViaActive(deck, 2);
    AddCardToDeckViaActive(deck, 3);
    AddCardToDeckViaActive(deck, 4);
    AddCardToDeckViaActive(deck, 5);
    AddCardToDeckViaActive(deck, 6);
    AddCardToDeckViaActive(deck, 7);
    AddCardToDeckViaActive(deck, 8);
    AddCardToDeckViaActive(deck, 9);
    AddCardToDeckViaActive(deck, 173);
    AddCardToDeckViaActive(deck, 176);
    AddCardToDeckViaActive(deck, 178);
    AddCardToDeckViaActive(deck, 181);
    AddCardToDeckViaActive(deck, 184);
    AddCardToDeckViaActive(deck, 189);
    AddCardToDeckViaActive(deck, 192);
    AddCardToDeckViaActive(deck, 195);
    AddCardToDeckViaActive(deck, 197);
    AddCardToDeckViaActive(deck, 202);
    AddCardToDeckViaActive(deck, 204);
    AddCardToDeckViaActive(deck, 207);
    AddCardToDeckViaActive(deck, 213);
    AddCardToDeckViaActive(deck, 216);
    AddCardToDeckViaActive(deck, 219);
    AddCardToDeckViaActive(deck, 224);
    AddCardToDeckViaActive(deck, 225);
    AddCardToDeckViaActive(deck, 228);
    AddCardToDeckViaActive(deck, 234);
    AddCardToDeckViaActive(deck, 235);
    AddCardToDeckViaActive(deck, 238);
    AddCardToDeckViaActive(deck, 255);
    AddCardToDeckViaActive(deck, 257);
    AddCardToDeckViaActive(deck, 258);
    AddCardToDeckViaActive(deck, 245);
    AddCardToDeckViaActive(deck, 247);
    AddCardToDeckViaActive(deck, 248);
    AddCardToDeckViaActive(deck, 265);
    AddCardToDeckViaActive(deck, 267);
    AddCardToDeckViaActive(deck, 268);
    AddCardToDeckViaActive(deck, 275);
    AddCardToDeckViaActive(deck, 277);
    AddCardToDeckViaActive(deck, 278);
    AddCardToDeckViaActive(deck, 285);
    AddCardToDeckViaActive(deck, 287);
    AddCardToDeckViaActive(deck, 288);
    AddCardToDeckViaActive(deck, 295);
    AddCardToDeckViaActive(deck, 297);
    AddCardToDeckViaActive(deck, 298);
    AddCardToDeckViaActive(deck, 305);
    AddCardToDeckViaActive(deck, 307);
    AddCardToDeckViaActive(deck, 308);
    AddCardToDeckViaActive(deck, 315);
    AddCardToDeckViaActive(deck, 317);
    AddCardToDeckViaActive(deck, 318);
    AddCardToDeckViaActive(deck, 325);
    AddCardToDeckViaActive(deck, 327);
    AddCardToDeckViaActive(deck, 328);
    AddCardToDeckViaActive(deck, 335);
    AddCardToDeckViaActive(deck, 337);
    AddCardToDeckViaActive(deck, 338);
    AddCardToDeckViaActive(deck, 345);
    AddCardToDeckViaActive(deck, 347);
    AddCardToDeckViaActive(deck, 348);
    AddCardToDeckViaActive(deck, 355);
    AddCardToDeckViaActive(deck, 357);
    AddCardToDeckViaActive(deck, 358);
    AddCardToDeckViaActive(deck, 365);
    AddCardToDeckViaActive(deck, 367);
    AddCardToDeckViaActive(deck, 368);
    AddCardToDeckViaActive(deck, 375);
    AddCardToDeckViaActive(deck, 377);
    AddCardToDeckViaActive(deck, 378);
    AddCardToDeckViaActive(deck, 450);
    AddCardToDeckViaActive(deck, 459);
    AddCardToDeckViaActive(deck, 462);
    AddCardToDeckViaActive(deck, 465);
    AddCardToDeckViaActive(deck, 468);
    AddCardToDeckViaActive(deck, 492);
    AddCardToDeckViaActive(deck, 528);
    AddCardToDeckViaActive(deck, 529);
    AddCardToDeckViaActive(deck, 453);
    AddCardToDeckViaActive(deck, 471);
    AddCardToDeckViaActive(deck, 474);
    AddCardToDeckViaActive(deck, 477);
    AddCardToDeckViaActive(deck, 480);
    AddCardToDeckViaActive(deck, 486);
    AddCardToDeckViaActive(deck, 489);
    AddCardToDeckViaActive(deck, 495);
    AddCardToDeckViaActive(deck, 501);
    AddCardToDeckViaActive(deck, 504);
    AddCardToDeckViaActive(deck, 507);
    AddCardToDeckViaActive(deck, 510);
    AddCardToDeckViaActive(deck, 513);
    AddCardToDeckViaActive(deck, 519);
    AddCardToDeckViaActive(deck, 522);
}

void ObtainStarterCards() {
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 7));
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 6));
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 5));
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 5));
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 4));
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 3));
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 4));
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 3));
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 2));
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 2));
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 1));
    ObtainCard(CARD_ID(CARD_KINGDOM_KEY, 0));
    ObtainCard(CARD_ID(CARD_BLIZZARD, 5));
    ObtainCard(CARD_ID(CARD_POTION, 6));
    ObtainCard(CARD_ID(CARD_CURE, 7));
}

void FillStarterDeck() {
    AddCardToDeckViaActive(0, 0);
    AddCardToDeckViaActive(0, 1);
    AddCardToDeckViaActive(0, 2);
    AddCardToDeckViaActive(0, 3);
    AddCardToDeckViaActive(0, 4);
    AddCardToDeckViaActive(0, 5);
    AddCardToDeckViaActive(0, 6);
    AddCardToDeckViaActive(0, 7);
    AddCardToDeckViaActive(0, 8);
    AddCardToDeckViaActive(0, 9);
    AddCardToDeckViaActive(0, 10);
    AddCardToDeckViaActive(0, 11);
    AddCardToDeckViaActive(0, 12);
    AddCardToDeckViaActive(0, 13);
    AddCardToDeckViaActive(0, 14);
}

void func_080AB964() {
}

void func_080AB968() {
}

#ifndef VERSION_EU
Mode gModeDeckExchange = {
    "Mode_Deck",
    (ModeInitFunc)Mode_DeckExchange_0,
    Mode_DeckExchange_1,
    Mode_DeckExchange_2,
};
#endif

TaskDesc gTaskDescDarkPoint = {
    "DarkPoint",
    (TaskInitFunc)DarkPoint_0,
    (TaskUpdateFunc)DarkPoint_1,
    (TaskDrawFunc)DarkPoint_2,
    (TaskDestroyFunc)DarkPoint_3,
    sizeof(DarkPointWork),
};

CardDescriptionText* gCardKindDescriptions[98] = {
#if defined(VERSION_EU)
    &gCardKindDescription00ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090106C0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042080,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription01ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090106F4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090420FC,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription02ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010728,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042176,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription03ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010760,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090421EE,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription04ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010794,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904226A,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription05ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090107CC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090422E4,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription06ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010800,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904235E,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription07ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010834,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090423D6,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription08ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010868,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042452,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription09ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901089C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090424CC,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription10ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090108D0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904254E,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription11ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010904,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090425CA,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription12ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010938,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042646,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription13ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901096C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090426C0,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription14ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090109A0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904273C,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription15ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090109D8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090427BC,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription16ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010A0C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042840,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription17ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010A40,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904434A,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription18ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010A6C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042F40,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription19ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010A8C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042F6A,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription20ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010AAC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042F92,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription21ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010ACC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042FC6,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription22ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010AE0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042FDE,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription23ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010B10,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090428BC,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription24ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010B2C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043042,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription25ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010B60,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042912,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription26ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010B84,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904309C,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription27ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010BB4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042984,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription28ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010BE4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090429E6,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription29ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010C0C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042A40,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription30ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010C38,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090430F0,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription31ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010C58,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042AA0,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription32ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010C6C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904315A,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription33ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010CA8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042AFC,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription34ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010CE4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090431C6,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription35ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010D20,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043230,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription36ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010D5C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904329A,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription37ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010D98,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042B5C,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription38ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010DD4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043302,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription39ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010E10,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904336A,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription40ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010E4C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090433DA,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription41ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010E6C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043426,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription42ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010E88,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043474,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription43ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010EBC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090434E0,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription44ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010EF4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043540,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription45ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010F08,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043586,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription46ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010F30,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09045146,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription47ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010F68,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090435E4,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription48ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010F94,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043632,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription49ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011018,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043746,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription50ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901111C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090438CA,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription51ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011144,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904391C,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription52ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901116C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043976,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription53ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011194,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090439CE,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription54ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010FB4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043678,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription55ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010FE4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090436E0,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription56ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090111F8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043A80,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription57ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090110BC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043814,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription58ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011050,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090437B0,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription59ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011224,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042C02,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription60ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090112D8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043B7C,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription61ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901108C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042BB4,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription62ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011344,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043BDE,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription63ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011314,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042C88,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription64ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011248,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042C32,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription65ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090112B0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043B0E,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription66ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090110F0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043880,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription67ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011278,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043AB0,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription68ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011370,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043C2C,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription69ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090113D0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043CE2,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription70ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901139C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043C82,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription71ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090111BC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043A1E,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription72ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011500,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043F00,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription73ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090113F8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043D42,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription74ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011428,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043DA6,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription75ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011460,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043DF0,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription76ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011488,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043E56,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription77ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090114C4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043E9E,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription78ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901152C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043F4A,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription79ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011654,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904408C,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription80ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901159C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090442E0,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription81ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090116F8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042D38,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription82ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011810,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042CE4,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription82ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011810,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042CE4,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription84ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011564,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043FA0,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription85ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090115D8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042D90,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription86ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011638,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044060,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription87ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901160C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044000,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription88ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011684,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090440E6,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription89ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090116BC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044160,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription90ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011770,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090441C2,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription91ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011724,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042DF2,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription92ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011754,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042E4C,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription93ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090117AC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904422C,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription94ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090117D4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044282,
#endif
    NULL,
#if defined(VERSION_EU)
    &gCardKindDescription96ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011844,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042E7C,
#endif
#if defined(VERSION_EU)
    &gCardKindDescription97ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011870,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042EEA,
#endif
};

CardDescriptionText* gMapCardDescriptions[26] = {
#if defined(VERSION_EU)
    &gMapCardDescription00ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011B30,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044886,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription01ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011B5C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090448CE,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription02ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011B84,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044922,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription03ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011BB0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044980,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription04ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011BE0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090449D8,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription05ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011C18,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044A44,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription06ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011C44,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044A96,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription07ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011C74,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044AF4,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription08ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011CA4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044B56,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription09ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011CB8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044B8E,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription10ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011CE0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044BEA,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription11ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011D08,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044C48,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription12ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011D3C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044CA2,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription13ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011D70,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044CFE,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription14ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011DA4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044D56,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription15ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011DE0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044DBE,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription16ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011E04,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044E06,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription17ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011E40,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044E6E,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription18ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011E78,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044EC6,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription19ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011EB4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044F16,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription20ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011EEC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044F80,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription21ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011F1C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044FD4,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription22ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011F48,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09045026,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription23ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011F78,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904506E,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription24ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011FA8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090450B6,
#endif
#if defined(VERSION_EU)
    &gMapCardDescription25ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011FD8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090450FE,
#endif
};

CardDescriptionText* gWorldDescriptions[14] = {
#if defined(VERSION_EU)
    &gWorldDescription00ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901192C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904446C,
#endif
#if defined(VERSION_EU)
    &gWorldDescription01ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090119EC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090445B4,
#endif
#if defined(VERSION_EU)
    &gWorldDescription02ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090119B4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904455E,
#endif
#if defined(VERSION_EU)
    &gWorldDescription03ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011984,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044514,
#endif
#if defined(VERSION_EU)
    &gWorldDescription04ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090118D0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090443B2,
#endif
#if defined(VERSION_EU)
    &gWorldDescription05ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011960,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090444C4,
#endif
#if defined(VERSION_EU)
    &gWorldDescription06ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090118FC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904440A,
#endif
#if defined(VERSION_EU)
    &gWorldDescription07ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011A04,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090445FA,
#endif
#if defined(VERSION_EU)
    &gWorldDescription08ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011AA0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090446FC,
#endif
#if defined(VERSION_EU)
    &gWorldDescription09ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090118A0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090447B6,
#endif
#if defined(VERSION_EU)
    &gWorldDescription10ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011A74,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090446A8,
#endif
#if defined(VERSION_EU)
    &gWorldDescription11ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011AD4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044758,
#endif
#if defined(VERSION_EU)
    &gWorldDescription12ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011A3C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044654,
#endif
#if defined(VERSION_EU)
    &gWorldDescription13ByLanguage,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011B04,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044816,
#endif
};
