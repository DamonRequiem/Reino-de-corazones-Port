/**
 * card_catalog.c
 * Card Definition Catalog
 */

#include <stddef.h>
#include "sprites_card_pictures.h"
#include "sprite_palettes.h"
#include "card_label_data.h"
#include "card_label_language_data.h"
#include "common_text.h"
#include "card_types.h"
#include "card_ui_types.h"
#include "jiminy_data.h"
#include "types.h"
#include "text_types.h"
#include "card_ids.h"

const CardBack gCardBacks[5] = {
    {
        gCardBorderRedFrame0, gCardOutlineRedFrame0, gCardBackRedFrame0, gCardBorderRedTiles, gCardOutlineRedTiles, gCardBackRedTiles,
    },
    {
        gCardBorderBlueFrame0, gCardOutlineBlueFrame0, gCardBackBlueFrame0, gCardBorderBlueTiles, gCardOutlineBlueTiles, gCardBackBlueTiles,
    },
    {
        gCardBorderGreenFrame0, gCardOutlineGreenFrame0, gCardBackGreenFrame0, gCardBorderGreenTiles, gCardOutlineGreenTiles, gCardBackGreenTiles,
    },
    {
        gCardBorderBlackFrame0, gCardOutlineBlackFrame0, gCardBackBlackFrame0, gCardBorderBlackTiles, gCardOutlineBlackTiles, gCardBackBlackTiles,
    },
    {
        gCardBorderWhiteFrame0, gCardOutlineWhiteFrame0, gCardBackWhiteFrame0, gCardBorderWhiteTiles, gCardOutlineWhiteTiles, gCardBackWhiteTiles,
    },
};

const CardBack gEnemyCardBacks[5] = {
    {
        gCardBorderBlackFrame0, gCardOutlineBlackFrame0, gEnemyCardBackFrame0, gCardBorderBlackTiles, gCardOutlineBlackTiles, gEnemyCardBackTiles,
    },
    {
        gCardBorderBlackFrame0, gCardOutlineBlackFrame0, gEnemyCardBackFrame0, gCardBorderBlackTiles, gCardOutlineBlackTiles, gEnemyCardBackTiles,
    },
    {
        gCardBorderBlackFrame0, gCardOutlineBlackFrame0, gEnemyCardBackFrame0, gCardBorderBlackTiles, gCardOutlineBlackTiles, gEnemyCardBackTiles,
    },
    {
        gCardBorderBlackFrame0, gCardOutlineBlackFrame0, gEnemyCardBackFrame0, gCardBorderBlackTiles, gCardOutlineBlackTiles, gEnemyCardBackTiles,
    },
    {
        gCardBorderBlackFrame0, gCardOutlineBlackFrame0, gEnemyCardBackFrame0, gCardBorderBlackTiles, gCardOutlineBlackTiles, gEnemyCardBackTiles,
    },
};

const u8 gBlackCircleText[3] = "\x81\x9C";

const u8 gWhiteCircleText[3] = "\x81\x9B";

const u8 gBlackStarText[3] = "\x81\x9A";

const u8 gWhiteStarText[3] = "\x81\x99";

const u8* gWhiteStarTextPtr = gWhiteStarText;
const u8* gBlackStarTextPtr = gBlackStarText;
const u8* gWhiteCircleTextPtr = gWhiteCircleText;
const u8* gBlackCircleTextPtr = gBlackCircleText;

const CardDef gCardDefs[950] = {
    {
        gCardWep01Frame0, gCardWep01Tiles, gCardWep01Palette, LOCALIZED(gCardNameKingdomKey), gKingdomKeySmallCardFrame0, gKingdomKeySmallCardTiles, gKingdomKeySmallCardPalette,
        CARD_KIND_KINGDOM_KEY, 0x0, 0, MOVE_KINGDOM_KEY, 1, CARD_CATEGORY_ATTACK, 10, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep01Frame0, gCardWep01Tiles, gCardWep01Palette, LOCALIZED(gCardNameKingdomKey), gKingdomKeySmallCardFrame0, gKingdomKeySmallCardTiles, gKingdomKeySmallCardPalette,
        CARD_KIND_KINGDOM_KEY, 0x0, 1, MOVE_KINGDOM_KEY, 1, CARD_CATEGORY_ATTACK, 10, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep01Frame0, gCardWep01Tiles, gCardWep01Palette, LOCALIZED(gCardNameKingdomKey), gKingdomKeySmallCardFrame0, gKingdomKeySmallCardTiles, gKingdomKeySmallCardPalette,
        CARD_KIND_KINGDOM_KEY, 0x0, 2, MOVE_KINGDOM_KEY, 1, CARD_CATEGORY_ATTACK, 10, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep01Frame0, gCardWep01Tiles, gCardWep01Palette, LOCALIZED(gCardNameKingdomKey), gKingdomKeySmallCardFrame0, gKingdomKeySmallCardTiles, gKingdomKeySmallCardPalette,
        CARD_KIND_KINGDOM_KEY, 0x0, 3, MOVE_KINGDOM_KEY, 1, CARD_CATEGORY_ATTACK, 10, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep01Frame0, gCardWep01Tiles, gCardWep01Palette, LOCALIZED(gCardNameKingdomKey), gKingdomKeySmallCardFrame0, gKingdomKeySmallCardTiles, gKingdomKeySmallCardPalette,
        CARD_KIND_KINGDOM_KEY, 0x0, 4, MOVE_KINGDOM_KEY, 1, CARD_CATEGORY_ATTACK, 10, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep01Frame0, gCardWep01Tiles, gCardWep01Palette, LOCALIZED(gCardNameKingdomKey), gKingdomKeySmallCardFrame0, gKingdomKeySmallCardTiles, gKingdomKeySmallCardPalette,
        CARD_KIND_KINGDOM_KEY, 0x0, 5, MOVE_KINGDOM_KEY, 1, CARD_CATEGORY_ATTACK, 10, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep01Frame0, gCardWep01Tiles, gCardWep01Palette, LOCALIZED(gCardNameKingdomKey), gKingdomKeySmallCardFrame0, gKingdomKeySmallCardTiles, gKingdomKeySmallCardPalette,
        CARD_KIND_KINGDOM_KEY, 0x0, 6, MOVE_KINGDOM_KEY, 1, CARD_CATEGORY_ATTACK, 10, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep01Frame0, gCardWep01Tiles, gCardWep01Palette, LOCALIZED(gCardNameKingdomKey), gKingdomKeySmallCardFrame0, gKingdomKeySmallCardTiles, gKingdomKeySmallCardPalette,
        CARD_KIND_KINGDOM_KEY, 0x0, 7, MOVE_KINGDOM_KEY, 1, CARD_CATEGORY_ATTACK, 10, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep01Frame0, gCardWep01Tiles, gCardWep01Palette, LOCALIZED(gCardNameKingdomKey), gKingdomKeySmallCardFrame0, gKingdomKeySmallCardTiles, gKingdomKeySmallCardPalette,
        CARD_KIND_KINGDOM_KEY, 0x0, 8, MOVE_KINGDOM_KEY, 1, CARD_CATEGORY_ATTACK, 10, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep01Frame0, gCardWep01Tiles, gCardWep01Palette, LOCALIZED(gCardNameKingdomKey), gKingdomKeySmallCardFrame0, gKingdomKeySmallCardTiles, gKingdomKeySmallCardPalette,
        CARD_KIND_KINGDOM_KEY, 0x0, 9, MOVE_KINGDOM_KEY, 1, CARD_CATEGORY_ATTACK, 10, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep04Frame0, gCardWep04Tiles, gCardWep04Palette, LOCALIZED(gCardNameThreeWishes), gThreeWishesSmallCardFrame0, gThreeWishesSmallCardTiles, gThreeWishesSmallCardPalette,
        CARD_KIND_THREE_WISHES, 0x0, 0, MOVE_THREE_WISHES, 11, CARD_CATEGORY_ATTACK, 15, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep04Frame0, gCardWep04Tiles, gCardWep04Palette, LOCALIZED(gCardNameThreeWishes), gThreeWishesSmallCardFrame0, gThreeWishesSmallCardTiles, gThreeWishesSmallCardPalette,
        CARD_KIND_THREE_WISHES, 0x0, 1, MOVE_THREE_WISHES, 11, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep04Frame0, gCardWep04Tiles, gCardWep04Palette, LOCALIZED(gCardNameThreeWishes), gThreeWishesSmallCardFrame0, gThreeWishesSmallCardTiles, gThreeWishesSmallCardPalette,
        CARD_KIND_THREE_WISHES, 0x0, 2, MOVE_THREE_WISHES, 11, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep04Frame0, gCardWep04Tiles, gCardWep04Palette, LOCALIZED(gCardNameThreeWishes), gThreeWishesSmallCardFrame0, gThreeWishesSmallCardTiles, gThreeWishesSmallCardPalette,
        CARD_KIND_THREE_WISHES, 0x0, 3, MOVE_THREE_WISHES, 11, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep04Frame0, gCardWep04Tiles, gCardWep04Palette, LOCALIZED(gCardNameThreeWishes), gThreeWishesSmallCardFrame0, gThreeWishesSmallCardTiles, gThreeWishesSmallCardPalette,
        CARD_KIND_THREE_WISHES, 0x0, 4, MOVE_THREE_WISHES, 11, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep04Frame0, gCardWep04Tiles, gCardWep04Palette, LOCALIZED(gCardNameThreeWishes), gThreeWishesSmallCardFrame0, gThreeWishesSmallCardTiles, gThreeWishesSmallCardPalette,
        CARD_KIND_THREE_WISHES, 0x0, 5, MOVE_THREE_WISHES, 11, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep04Frame0, gCardWep04Tiles, gCardWep04Palette, LOCALIZED(gCardNameThreeWishes), gThreeWishesSmallCardFrame0, gThreeWishesSmallCardTiles, gThreeWishesSmallCardPalette,
        CARD_KIND_THREE_WISHES, 0x0, 6, MOVE_THREE_WISHES, 11, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep04Frame0, gCardWep04Tiles, gCardWep04Palette, LOCALIZED(gCardNameThreeWishes), gThreeWishesSmallCardFrame0, gThreeWishesSmallCardTiles, gThreeWishesSmallCardPalette,
        CARD_KIND_THREE_WISHES, 0x0, 7, MOVE_THREE_WISHES, 11, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep04Frame0, gCardWep04Tiles, gCardWep04Palette, LOCALIZED(gCardNameThreeWishes), gThreeWishesSmallCardFrame0, gThreeWishesSmallCardTiles, gThreeWishesSmallCardPalette,
        CARD_KIND_THREE_WISHES, 0x0, 8, MOVE_THREE_WISHES, 11, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep04Frame0, gCardWep04Tiles, gCardWep04Palette, LOCALIZED(gCardNameThreeWishes), gThreeWishesSmallCardFrame0, gThreeWishesSmallCardTiles, gThreeWishesSmallCardPalette,
        CARD_KIND_THREE_WISHES, 0x0, 9, MOVE_THREE_WISHES, 11, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep05Frame0, gCardWep05Tiles, gCardWep05Palette, LOCALIZED(gCardNameCrabclaw), gCrabclawSmallCardFrame0, gCrabclawSmallCardTiles, gCrabclawSmallCardPalette,
        CARD_KIND_CRABCLAW, 0x0, 0, MOVE_CRABCLAW, 21, CARD_CATEGORY_ATTACK, 20, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep05Frame0, gCardWep05Tiles, gCardWep05Palette, LOCALIZED(gCardNameCrabclaw), gCrabclawSmallCardFrame0, gCrabclawSmallCardTiles, gCrabclawSmallCardPalette,
        CARD_KIND_CRABCLAW, 0x0, 1, MOVE_CRABCLAW, 21, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep05Frame0, gCardWep05Tiles, gCardWep05Palette, LOCALIZED(gCardNameCrabclaw), gCrabclawSmallCardFrame0, gCrabclawSmallCardTiles, gCrabclawSmallCardPalette,
        CARD_KIND_CRABCLAW, 0x0, 2, MOVE_CRABCLAW, 21, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep05Frame0, gCardWep05Tiles, gCardWep05Palette, LOCALIZED(gCardNameCrabclaw), gCrabclawSmallCardFrame0, gCrabclawSmallCardTiles, gCrabclawSmallCardPalette,
        CARD_KIND_CRABCLAW, 0x0, 3, MOVE_CRABCLAW, 21, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep05Frame0, gCardWep05Tiles, gCardWep05Palette, LOCALIZED(gCardNameCrabclaw), gCrabclawSmallCardFrame0, gCrabclawSmallCardTiles, gCrabclawSmallCardPalette,
        CARD_KIND_CRABCLAW, 0x0, 4, MOVE_CRABCLAW, 21, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep05Frame0, gCardWep05Tiles, gCardWep05Palette, LOCALIZED(gCardNameCrabclaw), gCrabclawSmallCardFrame0, gCrabclawSmallCardTiles, gCrabclawSmallCardPalette,
        CARD_KIND_CRABCLAW, 0x0, 5, MOVE_CRABCLAW, 21, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep05Frame0, gCardWep05Tiles, gCardWep05Palette, LOCALIZED(gCardNameCrabclaw), gCrabclawSmallCardFrame0, gCrabclawSmallCardTiles, gCrabclawSmallCardPalette,
        CARD_KIND_CRABCLAW, 0x0, 6, MOVE_CRABCLAW, 21, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep05Frame0, gCardWep05Tiles, gCardWep05Palette, LOCALIZED(gCardNameCrabclaw), gCrabclawSmallCardFrame0, gCrabclawSmallCardTiles, gCrabclawSmallCardPalette,
        CARD_KIND_CRABCLAW, 0x0, 7, MOVE_CRABCLAW, 21, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep05Frame0, gCardWep05Tiles, gCardWep05Palette, LOCALIZED(gCardNameCrabclaw), gCrabclawSmallCardFrame0, gCrabclawSmallCardTiles, gCrabclawSmallCardPalette,
        CARD_KIND_CRABCLAW, 0x0, 8, MOVE_CRABCLAW, 21, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep05Frame0, gCardWep05Tiles, gCardWep05Palette, LOCALIZED(gCardNameCrabclaw), gCrabclawSmallCardFrame0, gCrabclawSmallCardTiles, gCrabclawSmallCardPalette,
        CARD_KIND_CRABCLAW, 0x0, 9, MOVE_CRABCLAW, 21, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep06Frame0, gCardWep06Tiles, gCardWep06Palette, LOCALIZED(gCardNamePumpkinhead), gPumpkinheadSmallCardFrame0, gPumpkinheadSmallCardTiles, gPumpkinheadSmallCardPalette,
        CARD_KIND_PUMPKINHEAD, 0x0, 0, MOVE_PUMPKINHEAD, 31, CARD_CATEGORY_ATTACK, 15, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep06Frame0, gCardWep06Tiles, gCardWep06Palette, LOCALIZED(gCardNamePumpkinhead), gPumpkinheadSmallCardFrame0, gPumpkinheadSmallCardTiles, gPumpkinheadSmallCardPalette,
        CARD_KIND_PUMPKINHEAD, 0x0, 1, MOVE_PUMPKINHEAD, 31, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep06Frame0, gCardWep06Tiles, gCardWep06Palette, LOCALIZED(gCardNamePumpkinhead), gPumpkinheadSmallCardFrame0, gPumpkinheadSmallCardTiles, gPumpkinheadSmallCardPalette,
        CARD_KIND_PUMPKINHEAD, 0x0, 2, MOVE_PUMPKINHEAD, 31, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep06Frame0, gCardWep06Tiles, gCardWep06Palette, LOCALIZED(gCardNamePumpkinhead), gPumpkinheadSmallCardFrame0, gPumpkinheadSmallCardTiles, gPumpkinheadSmallCardPalette,
        CARD_KIND_PUMPKINHEAD, 0x0, 3, MOVE_PUMPKINHEAD, 31, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep06Frame0, gCardWep06Tiles, gCardWep06Palette, LOCALIZED(gCardNamePumpkinhead), gPumpkinheadSmallCardFrame0, gPumpkinheadSmallCardTiles, gPumpkinheadSmallCardPalette,
        CARD_KIND_PUMPKINHEAD, 0x0, 4, MOVE_PUMPKINHEAD, 31, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep06Frame0, gCardWep06Tiles, gCardWep06Palette, LOCALIZED(gCardNamePumpkinhead), gPumpkinheadSmallCardFrame0, gPumpkinheadSmallCardTiles, gPumpkinheadSmallCardPalette,
        CARD_KIND_PUMPKINHEAD, 0x0, 5, MOVE_PUMPKINHEAD, 31, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep06Frame0, gCardWep06Tiles, gCardWep06Palette, LOCALIZED(gCardNamePumpkinhead), gPumpkinheadSmallCardFrame0, gPumpkinheadSmallCardTiles, gPumpkinheadSmallCardPalette,
        CARD_KIND_PUMPKINHEAD, 0x0, 6, MOVE_PUMPKINHEAD, 31, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep06Frame0, gCardWep06Tiles, gCardWep06Palette, LOCALIZED(gCardNamePumpkinhead), gPumpkinheadSmallCardFrame0, gPumpkinheadSmallCardTiles, gPumpkinheadSmallCardPalette,
        CARD_KIND_PUMPKINHEAD, 0x0, 7, MOVE_PUMPKINHEAD, 31, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep06Frame0, gCardWep06Tiles, gCardWep06Palette, LOCALIZED(gCardNamePumpkinhead), gPumpkinheadSmallCardFrame0, gPumpkinheadSmallCardTiles, gPumpkinheadSmallCardPalette,
        CARD_KIND_PUMPKINHEAD, 0x0, 8, MOVE_PUMPKINHEAD, 31, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep06Frame0, gCardWep06Tiles, gCardWep06Palette, LOCALIZED(gCardNamePumpkinhead), gPumpkinheadSmallCardFrame0, gPumpkinheadSmallCardTiles, gPumpkinheadSmallCardPalette,
        CARD_KIND_PUMPKINHEAD, 0x0, 9, MOVE_PUMPKINHEAD, 31, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep07Frame0, gCardWep07Tiles, gCardWep07Palette, LOCALIZED(gCardNameFairyHarp), gFairyHarpSmallCardFrame0, gFairyHarpSmallCardTiles, gFairyHarpSmallCardPalette,
        CARD_KIND_FAIRY_HARP, 0x0, 0, MOVE_FAIRY_HARP, 41, CARD_CATEGORY_ATTACK, 20, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep07Frame0, gCardWep07Tiles, gCardWep07Palette, LOCALIZED(gCardNameFairyHarp), gFairyHarpSmallCardFrame0, gFairyHarpSmallCardTiles, gFairyHarpSmallCardPalette,
        CARD_KIND_FAIRY_HARP, 0x0, 1, MOVE_FAIRY_HARP, 41, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep07Frame0, gCardWep07Tiles, gCardWep07Palette, LOCALIZED(gCardNameFairyHarp), gFairyHarpSmallCardFrame0, gFairyHarpSmallCardTiles, gFairyHarpSmallCardPalette,
        CARD_KIND_FAIRY_HARP, 0x0, 2, MOVE_FAIRY_HARP, 41, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep07Frame0, gCardWep07Tiles, gCardWep07Palette, LOCALIZED(gCardNameFairyHarp), gFairyHarpSmallCardFrame0, gFairyHarpSmallCardTiles, gFairyHarpSmallCardPalette,
        CARD_KIND_FAIRY_HARP, 0x0, 3, MOVE_FAIRY_HARP, 41, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep07Frame0, gCardWep07Tiles, gCardWep07Palette, LOCALIZED(gCardNameFairyHarp), gFairyHarpSmallCardFrame0, gFairyHarpSmallCardTiles, gFairyHarpSmallCardPalette,
        CARD_KIND_FAIRY_HARP, 0x0, 4, MOVE_FAIRY_HARP, 41, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep07Frame0, gCardWep07Tiles, gCardWep07Palette, LOCALIZED(gCardNameFairyHarp), gFairyHarpSmallCardFrame0, gFairyHarpSmallCardTiles, gFairyHarpSmallCardPalette,
        CARD_KIND_FAIRY_HARP, 0x0, 5, MOVE_FAIRY_HARP, 41, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep07Frame0, gCardWep07Tiles, gCardWep07Palette, LOCALIZED(gCardNameFairyHarp), gFairyHarpSmallCardFrame0, gFairyHarpSmallCardTiles, gFairyHarpSmallCardPalette,
        CARD_KIND_FAIRY_HARP, 0x0, 6, MOVE_FAIRY_HARP, 41, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep07Frame0, gCardWep07Tiles, gCardWep07Palette, LOCALIZED(gCardNameFairyHarp), gFairyHarpSmallCardFrame0, gFairyHarpSmallCardTiles, gFairyHarpSmallCardPalette,
        CARD_KIND_FAIRY_HARP, 0x0, 7, MOVE_FAIRY_HARP, 41, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep07Frame0, gCardWep07Tiles, gCardWep07Palette, LOCALIZED(gCardNameFairyHarp), gFairyHarpSmallCardFrame0, gFairyHarpSmallCardTiles, gFairyHarpSmallCardPalette,
        CARD_KIND_FAIRY_HARP, 0x0, 8, MOVE_FAIRY_HARP, 41, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep07Frame0, gCardWep07Tiles, gCardWep07Palette, LOCALIZED(gCardNameFairyHarp), gFairyHarpSmallCardFrame0, gFairyHarpSmallCardTiles, gFairyHarpSmallCardPalette,
        CARD_KIND_FAIRY_HARP, 0x0, 9, MOVE_FAIRY_HARP, 41, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep08Frame0, gCardWep08Tiles, gCardWep08Palette, LOCALIZED(gCardNameWishingStar), gWishingStarSmallCardFrame0, gWishingStarSmallCardTiles, gWishingStarSmallCardPalette,
        CARD_KIND_WISHING_STAR, 0x0, 0, MOVE_WISHING_STAR, 51, CARD_CATEGORY_ATTACK, 15, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep08Frame0, gCardWep08Tiles, gCardWep08Palette, LOCALIZED(gCardNameWishingStar), gWishingStarSmallCardFrame0, gWishingStarSmallCardTiles, gWishingStarSmallCardPalette,
        CARD_KIND_WISHING_STAR, 0x0, 1, MOVE_WISHING_STAR, 51, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep08Frame0, gCardWep08Tiles, gCardWep08Palette, LOCALIZED(gCardNameWishingStar), gWishingStarSmallCardFrame0, gWishingStarSmallCardTiles, gWishingStarSmallCardPalette,
        CARD_KIND_WISHING_STAR, 0x0, 2, MOVE_WISHING_STAR, 51, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep08Frame0, gCardWep08Tiles, gCardWep08Palette, LOCALIZED(gCardNameWishingStar), gWishingStarSmallCardFrame0, gWishingStarSmallCardTiles, gWishingStarSmallCardPalette,
        CARD_KIND_WISHING_STAR, 0x0, 3, MOVE_WISHING_STAR, 51, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep08Frame0, gCardWep08Tiles, gCardWep08Palette, LOCALIZED(gCardNameWishingStar), gWishingStarSmallCardFrame0, gWishingStarSmallCardTiles, gWishingStarSmallCardPalette,
        CARD_KIND_WISHING_STAR, 0x0, 4, MOVE_WISHING_STAR, 51, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep08Frame0, gCardWep08Tiles, gCardWep08Palette, LOCALIZED(gCardNameWishingStar), gWishingStarSmallCardFrame0, gWishingStarSmallCardTiles, gWishingStarSmallCardPalette,
        CARD_KIND_WISHING_STAR, 0x0, 5, MOVE_WISHING_STAR, 51, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep08Frame0, gCardWep08Tiles, gCardWep08Palette, LOCALIZED(gCardNameWishingStar), gWishingStarSmallCardFrame0, gWishingStarSmallCardTiles, gWishingStarSmallCardPalette,
        CARD_KIND_WISHING_STAR, 0x0, 6, MOVE_WISHING_STAR, 51, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep08Frame0, gCardWep08Tiles, gCardWep08Palette, LOCALIZED(gCardNameWishingStar), gWishingStarSmallCardFrame0, gWishingStarSmallCardTiles, gWishingStarSmallCardPalette,
        CARD_KIND_WISHING_STAR, 0x0, 7, MOVE_WISHING_STAR, 51, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep08Frame0, gCardWep08Tiles, gCardWep08Palette, LOCALIZED(gCardNameWishingStar), gWishingStarSmallCardFrame0, gWishingStarSmallCardTiles, gWishingStarSmallCardPalette,
        CARD_KIND_WISHING_STAR, 0x0, 8, MOVE_WISHING_STAR, 51, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep08Frame0, gCardWep08Tiles, gCardWep08Palette, LOCALIZED(gCardNameWishingStar), gWishingStarSmallCardFrame0, gWishingStarSmallCardTiles, gWishingStarSmallCardPalette,
        CARD_KIND_WISHING_STAR, 0x0, 9, MOVE_WISHING_STAR, 51, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep09Frame0, gCardWep09Tiles, gCardWep09Palette, LOCALIZED(gCardNameSpellbinder), gSpellbinderSmallCardFrame0, gSpellbinderSmallCardTiles, gSpellbinderSmallCardPalette,
        CARD_KIND_SPELLBINDER, 0x0, 0, MOVE_SPELLBINDER, 61, CARD_CATEGORY_ATTACK, 20, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep09Frame0, gCardWep09Tiles, gCardWep09Palette, LOCALIZED(gCardNameSpellbinder), gSpellbinderSmallCardFrame0, gSpellbinderSmallCardTiles, gSpellbinderSmallCardPalette,
        CARD_KIND_SPELLBINDER, 0x0, 1, MOVE_SPELLBINDER, 61, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep09Frame0, gCardWep09Tiles, gCardWep09Palette, LOCALIZED(gCardNameSpellbinder), gSpellbinderSmallCardFrame0, gSpellbinderSmallCardTiles, gSpellbinderSmallCardPalette,
        CARD_KIND_SPELLBINDER, 0x0, 2, MOVE_SPELLBINDER, 61, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep09Frame0, gCardWep09Tiles, gCardWep09Palette, LOCALIZED(gCardNameSpellbinder), gSpellbinderSmallCardFrame0, gSpellbinderSmallCardTiles, gSpellbinderSmallCardPalette,
        CARD_KIND_SPELLBINDER, 0x0, 3, MOVE_SPELLBINDER, 61, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep09Frame0, gCardWep09Tiles, gCardWep09Palette, LOCALIZED(gCardNameSpellbinder), gSpellbinderSmallCardFrame0, gSpellbinderSmallCardTiles, gSpellbinderSmallCardPalette,
        CARD_KIND_SPELLBINDER, 0x0, 4, MOVE_SPELLBINDER, 61, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep09Frame0, gCardWep09Tiles, gCardWep09Palette, LOCALIZED(gCardNameSpellbinder), gSpellbinderSmallCardFrame0, gSpellbinderSmallCardTiles, gSpellbinderSmallCardPalette,
        CARD_KIND_SPELLBINDER, 0x0, 5, MOVE_SPELLBINDER, 61, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep09Frame0, gCardWep09Tiles, gCardWep09Palette, LOCALIZED(gCardNameSpellbinder), gSpellbinderSmallCardFrame0, gSpellbinderSmallCardTiles, gSpellbinderSmallCardPalette,
        CARD_KIND_SPELLBINDER, 0x0, 6, MOVE_SPELLBINDER, 61, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep09Frame0, gCardWep09Tiles, gCardWep09Palette, LOCALIZED(gCardNameSpellbinder), gSpellbinderSmallCardFrame0, gSpellbinderSmallCardTiles, gSpellbinderSmallCardPalette,
        CARD_KIND_SPELLBINDER, 0x0, 7, MOVE_SPELLBINDER, 61, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep09Frame0, gCardWep09Tiles, gCardWep09Palette, LOCALIZED(gCardNameSpellbinder), gSpellbinderSmallCardFrame0, gSpellbinderSmallCardTiles, gSpellbinderSmallCardPalette,
        CARD_KIND_SPELLBINDER, 0x0, 8, MOVE_SPELLBINDER, 61, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep09Frame0, gCardWep09Tiles, gCardWep09Palette, LOCALIZED(gCardNameSpellbinder), gSpellbinderSmallCardFrame0, gSpellbinderSmallCardTiles, gSpellbinderSmallCardPalette,
        CARD_KIND_SPELLBINDER, 0x0, 9, MOVE_SPELLBINDER, 61, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep10Frame0, gCardWep10Tiles, gCardWep10Palette, LOCALIZED(gCardNameMetalChocobo), gMetalChocoboSmallCardFrame0, gMetalChocoboSmallCardTiles, gMetalChocoboSmallCardPalette,
        CARD_KIND_METAL_CHOCOBO, 0x0, 0, MOVE_METAL_CHOCOBO, 71, CARD_CATEGORY_ATTACK, 20, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep10Frame0, gCardWep10Tiles, gCardWep10Palette, LOCALIZED(gCardNameMetalChocobo), gMetalChocoboSmallCardFrame0, gMetalChocoboSmallCardTiles, gMetalChocoboSmallCardPalette,
        CARD_KIND_METAL_CHOCOBO, 0x0, 1, MOVE_METAL_CHOCOBO, 71, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep10Frame0, gCardWep10Tiles, gCardWep10Palette, LOCALIZED(gCardNameMetalChocobo), gMetalChocoboSmallCardFrame0, gMetalChocoboSmallCardTiles, gMetalChocoboSmallCardPalette,
        CARD_KIND_METAL_CHOCOBO, 0x0, 2, MOVE_METAL_CHOCOBO, 71, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep10Frame0, gCardWep10Tiles, gCardWep10Palette, LOCALIZED(gCardNameMetalChocobo), gMetalChocoboSmallCardFrame0, gMetalChocoboSmallCardTiles, gMetalChocoboSmallCardPalette,
        CARD_KIND_METAL_CHOCOBO, 0x0, 3, MOVE_METAL_CHOCOBO, 71, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep10Frame0, gCardWep10Tiles, gCardWep10Palette, LOCALIZED(gCardNameMetalChocobo), gMetalChocoboSmallCardFrame0, gMetalChocoboSmallCardTiles, gMetalChocoboSmallCardPalette,
        CARD_KIND_METAL_CHOCOBO, 0x0, 4, MOVE_METAL_CHOCOBO, 71, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep10Frame0, gCardWep10Tiles, gCardWep10Palette, LOCALIZED(gCardNameMetalChocobo), gMetalChocoboSmallCardFrame0, gMetalChocoboSmallCardTiles, gMetalChocoboSmallCardPalette,
        CARD_KIND_METAL_CHOCOBO, 0x0, 5, MOVE_METAL_CHOCOBO, 71, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep10Frame0, gCardWep10Tiles, gCardWep10Palette, LOCALIZED(gCardNameMetalChocobo), gMetalChocoboSmallCardFrame0, gMetalChocoboSmallCardTiles, gMetalChocoboSmallCardPalette,
        CARD_KIND_METAL_CHOCOBO, 0x0, 6, MOVE_METAL_CHOCOBO, 71, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep10Frame0, gCardWep10Tiles, gCardWep10Palette, LOCALIZED(gCardNameMetalChocobo), gMetalChocoboSmallCardFrame0, gMetalChocoboSmallCardTiles, gMetalChocoboSmallCardPalette,
        CARD_KIND_METAL_CHOCOBO, 0x0, 7, MOVE_METAL_CHOCOBO, 71, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep10Frame0, gCardWep10Tiles, gCardWep10Palette, LOCALIZED(gCardNameMetalChocobo), gMetalChocoboSmallCardFrame0, gMetalChocoboSmallCardTiles, gMetalChocoboSmallCardPalette,
        CARD_KIND_METAL_CHOCOBO, 0x0, 8, MOVE_METAL_CHOCOBO, 71, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep10Frame0, gCardWep10Tiles, gCardWep10Palette, LOCALIZED(gCardNameMetalChocobo), gMetalChocoboSmallCardFrame0, gMetalChocoboSmallCardTiles, gMetalChocoboSmallCardPalette,
        CARD_KIND_METAL_CHOCOBO, 0x0, 9, MOVE_METAL_CHOCOBO, 71, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep03Frame0, gCardWep03Tiles, gCardWep03Palette, LOCALIZED(gCardNameOlympia), gOlympiaSmallCardFrame0, gOlympiaSmallCardTiles, gOlympiaSmallCardPalette,
        CARD_KIND_OLYMPIA, 0x0, 0, MOVE_OLYMPIA, 81, CARD_CATEGORY_ATTACK, 15, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep03Frame0, gCardWep03Tiles, gCardWep03Palette, LOCALIZED(gCardNameOlympia), gOlympiaSmallCardFrame0, gOlympiaSmallCardTiles, gOlympiaSmallCardPalette,
        CARD_KIND_OLYMPIA, 0x0, 1, MOVE_OLYMPIA, 81, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep03Frame0, gCardWep03Tiles, gCardWep03Palette, LOCALIZED(gCardNameOlympia), gOlympiaSmallCardFrame0, gOlympiaSmallCardTiles, gOlympiaSmallCardPalette,
        CARD_KIND_OLYMPIA, 0x0, 2, MOVE_OLYMPIA, 81, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep03Frame0, gCardWep03Tiles, gCardWep03Palette, LOCALIZED(gCardNameOlympia), gOlympiaSmallCardFrame0, gOlympiaSmallCardTiles, gOlympiaSmallCardPalette,
        CARD_KIND_OLYMPIA, 0x0, 3, MOVE_OLYMPIA, 81, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep03Frame0, gCardWep03Tiles, gCardWep03Palette, LOCALIZED(gCardNameOlympia), gOlympiaSmallCardFrame0, gOlympiaSmallCardTiles, gOlympiaSmallCardPalette,
        CARD_KIND_OLYMPIA, 0x0, 4, MOVE_OLYMPIA, 81, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep03Frame0, gCardWep03Tiles, gCardWep03Palette, LOCALIZED(gCardNameOlympia), gOlympiaSmallCardFrame0, gOlympiaSmallCardTiles, gOlympiaSmallCardPalette,
        CARD_KIND_OLYMPIA, 0x0, 5, MOVE_OLYMPIA, 81, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep03Frame0, gCardWep03Tiles, gCardWep03Palette, LOCALIZED(gCardNameOlympia), gOlympiaSmallCardFrame0, gOlympiaSmallCardTiles, gOlympiaSmallCardPalette,
        CARD_KIND_OLYMPIA, 0x0, 6, MOVE_OLYMPIA, 81, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep03Frame0, gCardWep03Tiles, gCardWep03Palette, LOCALIZED(gCardNameOlympia), gOlympiaSmallCardFrame0, gOlympiaSmallCardTiles, gOlympiaSmallCardPalette,
        CARD_KIND_OLYMPIA, 0x0, 7, MOVE_OLYMPIA, 81, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep03Frame0, gCardWep03Tiles, gCardWep03Palette, LOCALIZED(gCardNameOlympia), gOlympiaSmallCardFrame0, gOlympiaSmallCardTiles, gOlympiaSmallCardPalette,
        CARD_KIND_OLYMPIA, 0x0, 8, MOVE_OLYMPIA, 81, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep03Frame0, gCardWep03Tiles, gCardWep03Palette, LOCALIZED(gCardNameOlympia), gOlympiaSmallCardFrame0, gOlympiaSmallCardTiles, gOlympiaSmallCardPalette,
        CARD_KIND_OLYMPIA, 0x0, 9, MOVE_OLYMPIA, 81, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep11Frame0, gCardWep11Tiles, gCardWep11Palette, LOCALIZED(gCardNameLionheart), gLionheartSmallCardFrame0, gLionheartSmallCardTiles, gLionheartSmallCardPalette,
        CARD_KIND_LIONHEART, 0x0, 0, MOVE_LIONHEART, 91, CARD_CATEGORY_ATTACK, 20, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep11Frame0, gCardWep11Tiles, gCardWep11Palette, LOCALIZED(gCardNameLionheart), gLionheartSmallCardFrame0, gLionheartSmallCardTiles, gLionheartSmallCardPalette,
        CARD_KIND_LIONHEART, 0x0, 1, MOVE_LIONHEART, 91, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep11Frame0, gCardWep11Tiles, gCardWep11Palette, LOCALIZED(gCardNameLionheart), gLionheartSmallCardFrame0, gLionheartSmallCardTiles, gLionheartSmallCardPalette,
        CARD_KIND_LIONHEART, 0x0, 2, MOVE_LIONHEART, 91, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep11Frame0, gCardWep11Tiles, gCardWep11Palette, LOCALIZED(gCardNameLionheart), gLionheartSmallCardFrame0, gLionheartSmallCardTiles, gLionheartSmallCardPalette,
        CARD_KIND_LIONHEART, 0x0, 3, MOVE_LIONHEART, 91, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep11Frame0, gCardWep11Tiles, gCardWep11Palette, LOCALIZED(gCardNameLionheart), gLionheartSmallCardFrame0, gLionheartSmallCardTiles, gLionheartSmallCardPalette,
        CARD_KIND_LIONHEART, 0x0, 4, MOVE_LIONHEART, 91, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep11Frame0, gCardWep11Tiles, gCardWep11Palette, LOCALIZED(gCardNameLionheart), gLionheartSmallCardFrame0, gLionheartSmallCardTiles, gLionheartSmallCardPalette,
        CARD_KIND_LIONHEART, 0x0, 5, MOVE_LIONHEART, 91, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep11Frame0, gCardWep11Tiles, gCardWep11Palette, LOCALIZED(gCardNameLionheart), gLionheartSmallCardFrame0, gLionheartSmallCardTiles, gLionheartSmallCardPalette,
        CARD_KIND_LIONHEART, 0x0, 6, MOVE_LIONHEART, 91, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep11Frame0, gCardWep11Tiles, gCardWep11Palette, LOCALIZED(gCardNameLionheart), gLionheartSmallCardFrame0, gLionheartSmallCardTiles, gLionheartSmallCardPalette,
        CARD_KIND_LIONHEART, 0x0, 7, MOVE_LIONHEART, 91, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep11Frame0, gCardWep11Tiles, gCardWep11Palette, LOCALIZED(gCardNameLionheart), gLionheartSmallCardFrame0, gLionheartSmallCardTiles, gLionheartSmallCardPalette,
        CARD_KIND_LIONHEART, 0x0, 8, MOVE_LIONHEART, 91, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep11Frame0, gCardWep11Tiles, gCardWep11Palette, LOCALIZED(gCardNameLionheart), gLionheartSmallCardFrame0, gLionheartSmallCardTiles, gLionheartSmallCardPalette,
        CARD_KIND_LIONHEART, 0x0, 9, MOVE_LIONHEART, 91, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep12Frame0, gCardWep12Tiles, gCardWep12Palette, LOCALIZED(gCardNameLadyLuck), gLadyLuckSmallCardFrame0, gLadyLuckSmallCardTiles, gLadyLuckSmallCardPalette,
        CARD_KIND_LADY_LUCK, 0x0, 0, MOVE_LADY_LUCK, 101, CARD_CATEGORY_ATTACK, 15, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep12Frame0, gCardWep12Tiles, gCardWep12Palette, LOCALIZED(gCardNameLadyLuck), gLadyLuckSmallCardFrame0, gLadyLuckSmallCardTiles, gLadyLuckSmallCardPalette,
        CARD_KIND_LADY_LUCK, 0x0, 1, MOVE_LADY_LUCK, 101, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep12Frame0, gCardWep12Tiles, gCardWep12Palette, LOCALIZED(gCardNameLadyLuck), gLadyLuckSmallCardFrame0, gLadyLuckSmallCardTiles, gLadyLuckSmallCardPalette,
        CARD_KIND_LADY_LUCK, 0x0, 2, MOVE_LADY_LUCK, 101, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep12Frame0, gCardWep12Tiles, gCardWep12Palette, LOCALIZED(gCardNameLadyLuck), gLadyLuckSmallCardFrame0, gLadyLuckSmallCardTiles, gLadyLuckSmallCardPalette,
        CARD_KIND_LADY_LUCK, 0x0, 3, MOVE_LADY_LUCK, 101, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep12Frame0, gCardWep12Tiles, gCardWep12Palette, LOCALIZED(gCardNameLadyLuck), gLadyLuckSmallCardFrame0, gLadyLuckSmallCardTiles, gLadyLuckSmallCardPalette,
        CARD_KIND_LADY_LUCK, 0x0, 4, MOVE_LADY_LUCK, 101, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep12Frame0, gCardWep12Tiles, gCardWep12Palette, LOCALIZED(gCardNameLadyLuck), gLadyLuckSmallCardFrame0, gLadyLuckSmallCardTiles, gLadyLuckSmallCardPalette,
        CARD_KIND_LADY_LUCK, 0x0, 5, MOVE_LADY_LUCK, 101, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep12Frame0, gCardWep12Tiles, gCardWep12Palette, LOCALIZED(gCardNameLadyLuck), gLadyLuckSmallCardFrame0, gLadyLuckSmallCardTiles, gLadyLuckSmallCardPalette,
        CARD_KIND_LADY_LUCK, 0x0, 6, MOVE_LADY_LUCK, 101, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep12Frame0, gCardWep12Tiles, gCardWep12Palette, LOCALIZED(gCardNameLadyLuck), gLadyLuckSmallCardFrame0, gLadyLuckSmallCardTiles, gLadyLuckSmallCardPalette,
        CARD_KIND_LADY_LUCK, 0x0, 7, MOVE_LADY_LUCK, 101, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep12Frame0, gCardWep12Tiles, gCardWep12Palette, LOCALIZED(gCardNameLadyLuck), gLadyLuckSmallCardFrame0, gLadyLuckSmallCardTiles, gLadyLuckSmallCardPalette,
        CARD_KIND_LADY_LUCK, 0x0, 8, MOVE_LADY_LUCK, 101, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep12Frame0, gCardWep12Tiles, gCardWep12Palette, LOCALIZED(gCardNameLadyLuck), gLadyLuckSmallCardFrame0, gLadyLuckSmallCardTiles, gLadyLuckSmallCardPalette,
        CARD_KIND_LADY_LUCK, 0x0, 9, MOVE_LADY_LUCK, 101, CARD_CATEGORY_ATTACK, 15, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep13Frame0, gCardWep13Tiles, gCardWep13Palette, LOCALIZED(gCardNameDivineRose), gDivineRoseSmallCardFrame0, gDivineRoseSmallCardTiles, gDivineRoseSmallCardPalette,
        CARD_KIND_DIVINE_ROSE, 0x0, 0, MOVE_DIVINE_ROSE, 111, CARD_CATEGORY_ATTACK, 20, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep13Frame0, gCardWep13Tiles, gCardWep13Palette, LOCALIZED(gCardNameDivineRose), gDivineRoseSmallCardFrame0, gDivineRoseSmallCardTiles, gDivineRoseSmallCardPalette,
        CARD_KIND_DIVINE_ROSE, 0x0, 1, MOVE_DIVINE_ROSE, 111, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep13Frame0, gCardWep13Tiles, gCardWep13Palette, LOCALIZED(gCardNameDivineRose), gDivineRoseSmallCardFrame0, gDivineRoseSmallCardTiles, gDivineRoseSmallCardPalette,
        CARD_KIND_DIVINE_ROSE, 0x0, 2, MOVE_DIVINE_ROSE, 111, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep13Frame0, gCardWep13Tiles, gCardWep13Palette, LOCALIZED(gCardNameDivineRose), gDivineRoseSmallCardFrame0, gDivineRoseSmallCardTiles, gDivineRoseSmallCardPalette,
        CARD_KIND_DIVINE_ROSE, 0x0, 3, MOVE_DIVINE_ROSE, 111, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep13Frame0, gCardWep13Tiles, gCardWep13Palette, LOCALIZED(gCardNameDivineRose), gDivineRoseSmallCardFrame0, gDivineRoseSmallCardTiles, gDivineRoseSmallCardPalette,
        CARD_KIND_DIVINE_ROSE, 0x0, 4, MOVE_DIVINE_ROSE, 111, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep13Frame0, gCardWep13Tiles, gCardWep13Palette, LOCALIZED(gCardNameDivineRose), gDivineRoseSmallCardFrame0, gDivineRoseSmallCardTiles, gDivineRoseSmallCardPalette,
        CARD_KIND_DIVINE_ROSE, 0x0, 5, MOVE_DIVINE_ROSE, 111, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep13Frame0, gCardWep13Tiles, gCardWep13Palette, LOCALIZED(gCardNameDivineRose), gDivineRoseSmallCardFrame0, gDivineRoseSmallCardTiles, gDivineRoseSmallCardPalette,
        CARD_KIND_DIVINE_ROSE, 0x0, 6, MOVE_DIVINE_ROSE, 111, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep13Frame0, gCardWep13Tiles, gCardWep13Palette, LOCALIZED(gCardNameDivineRose), gDivineRoseSmallCardFrame0, gDivineRoseSmallCardTiles, gDivineRoseSmallCardPalette,
        CARD_KIND_DIVINE_ROSE, 0x0, 7, MOVE_DIVINE_ROSE, 111, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep13Frame0, gCardWep13Tiles, gCardWep13Palette, LOCALIZED(gCardNameDivineRose), gDivineRoseSmallCardFrame0, gDivineRoseSmallCardTiles, gDivineRoseSmallCardPalette,
        CARD_KIND_DIVINE_ROSE, 0x0, 8, MOVE_DIVINE_ROSE, 111, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep13Frame0, gCardWep13Tiles, gCardWep13Palette, LOCALIZED(gCardNameDivineRose), gDivineRoseSmallCardFrame0, gDivineRoseSmallCardTiles, gDivineRoseSmallCardPalette,
        CARD_KIND_DIVINE_ROSE, 0x0, 9, MOVE_DIVINE_ROSE, 111, CARD_CATEGORY_ATTACK, 20, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep14Frame0, gCardWep14Tiles, gCardWep14Palette, LOCALIZED(gCardNameOathkeeper), gOathkeeperSmallCardFrame0, gOathkeeperSmallCardTiles, gOathkeeperSmallCardPalette,
        CARD_KIND_OATHKEEPER, 0x0, 0, MOVE_OATHKEEPER, 121, CARD_CATEGORY_ATTACK, 25, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep14Frame0, gCardWep14Tiles, gCardWep14Palette, LOCALIZED(gCardNameOathkeeper), gOathkeeperSmallCardFrame0, gOathkeeperSmallCardTiles, gOathkeeperSmallCardPalette,
        CARD_KIND_OATHKEEPER, 0x0, 1, MOVE_OATHKEEPER, 121, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep14Frame0, gCardWep14Tiles, gCardWep14Palette, LOCALIZED(gCardNameOathkeeper), gOathkeeperSmallCardFrame0, gOathkeeperSmallCardTiles, gOathkeeperSmallCardPalette,
        CARD_KIND_OATHKEEPER, 0x0, 2, MOVE_OATHKEEPER, 121, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep14Frame0, gCardWep14Tiles, gCardWep14Palette, LOCALIZED(gCardNameOathkeeper), gOathkeeperSmallCardFrame0, gOathkeeperSmallCardTiles, gOathkeeperSmallCardPalette,
        CARD_KIND_OATHKEEPER, 0x0, 3, MOVE_OATHKEEPER, 121, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep14Frame0, gCardWep14Tiles, gCardWep14Palette, LOCALIZED(gCardNameOathkeeper), gOathkeeperSmallCardFrame0, gOathkeeperSmallCardTiles, gOathkeeperSmallCardPalette,
        CARD_KIND_OATHKEEPER, 0x0, 4, MOVE_OATHKEEPER, 121, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep14Frame0, gCardWep14Tiles, gCardWep14Palette, LOCALIZED(gCardNameOathkeeper), gOathkeeperSmallCardFrame0, gOathkeeperSmallCardTiles, gOathkeeperSmallCardPalette,
        CARD_KIND_OATHKEEPER, 0x0, 5, MOVE_OATHKEEPER, 121, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep14Frame0, gCardWep14Tiles, gCardWep14Palette, LOCALIZED(gCardNameOathkeeper), gOathkeeperSmallCardFrame0, gOathkeeperSmallCardTiles, gOathkeeperSmallCardPalette,
        CARD_KIND_OATHKEEPER, 0x0, 6, MOVE_OATHKEEPER, 121, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep14Frame0, gCardWep14Tiles, gCardWep14Palette, LOCALIZED(gCardNameOathkeeper), gOathkeeperSmallCardFrame0, gOathkeeperSmallCardTiles, gOathkeeperSmallCardPalette,
        CARD_KIND_OATHKEEPER, 0x0, 7, MOVE_OATHKEEPER, 121, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep14Frame0, gCardWep14Tiles, gCardWep14Palette, LOCALIZED(gCardNameOathkeeper), gOathkeeperSmallCardFrame0, gOathkeeperSmallCardTiles, gOathkeeperSmallCardPalette,
        CARD_KIND_OATHKEEPER, 0x0, 8, MOVE_OATHKEEPER, 121, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep14Frame0, gCardWep14Tiles, gCardWep14Palette, LOCALIZED(gCardNameOathkeeper), gOathkeeperSmallCardFrame0, gOathkeeperSmallCardTiles, gOathkeeperSmallCardPalette,
        CARD_KIND_OATHKEEPER, 0x0, 9, MOVE_OATHKEEPER, 121, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep15Frame0, gCardWep15Tiles, gCardWep15Palette, LOCALIZED(gCardNameOblivion), gOblivionSmallCardFrame0, gOblivionSmallCardTiles, gOblivionSmallCardPalette,
        CARD_KIND_OBLIVION, 0x0, 0, MOVE_OBLIVION, 131, CARD_CATEGORY_ATTACK, 25, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep15Frame0, gCardWep15Tiles, gCardWep15Palette, LOCALIZED(gCardNameOblivion), gOblivionSmallCardFrame0, gOblivionSmallCardTiles, gOblivionSmallCardPalette,
        CARD_KIND_OBLIVION, 0x0, 1, MOVE_OBLIVION, 131, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep15Frame0, gCardWep15Tiles, gCardWep15Palette, LOCALIZED(gCardNameOblivion), gOblivionSmallCardFrame0, gOblivionSmallCardTiles, gOblivionSmallCardPalette,
        CARD_KIND_OBLIVION, 0x0, 2, MOVE_OBLIVION, 131, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep15Frame0, gCardWep15Tiles, gCardWep15Palette, LOCALIZED(gCardNameOblivion), gOblivionSmallCardFrame0, gOblivionSmallCardTiles, gOblivionSmallCardPalette,
        CARD_KIND_OBLIVION, 0x0, 3, MOVE_OBLIVION, 131, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep15Frame0, gCardWep15Tiles, gCardWep15Palette, LOCALIZED(gCardNameOblivion), gOblivionSmallCardFrame0, gOblivionSmallCardTiles, gOblivionSmallCardPalette,
        CARD_KIND_OBLIVION, 0x0, 4, MOVE_OBLIVION, 131, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep15Frame0, gCardWep15Tiles, gCardWep15Palette, LOCALIZED(gCardNameOblivion), gOblivionSmallCardFrame0, gOblivionSmallCardTiles, gOblivionSmallCardPalette,
        CARD_KIND_OBLIVION, 0x0, 5, MOVE_OBLIVION, 131, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep15Frame0, gCardWep15Tiles, gCardWep15Palette, LOCALIZED(gCardNameOblivion), gOblivionSmallCardFrame0, gOblivionSmallCardTiles, gOblivionSmallCardPalette,
        CARD_KIND_OBLIVION, 0x0, 6, MOVE_OBLIVION, 131, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep15Frame0, gCardWep15Tiles, gCardWep15Palette, LOCALIZED(gCardNameOblivion), gOblivionSmallCardFrame0, gOblivionSmallCardTiles, gOblivionSmallCardPalette,
        CARD_KIND_OBLIVION, 0x0, 7, MOVE_OBLIVION, 131, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep15Frame0, gCardWep15Tiles, gCardWep15Palette, LOCALIZED(gCardNameOblivion), gOblivionSmallCardFrame0, gOblivionSmallCardTiles, gOblivionSmallCardPalette,
        CARD_KIND_OBLIVION, 0x0, 8, MOVE_OBLIVION, 131, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep15Frame0, gCardWep15Tiles, gCardWep15Palette, LOCALIZED(gCardNameOblivion), gOblivionSmallCardFrame0, gOblivionSmallCardTiles, gOblivionSmallCardPalette,
        CARD_KIND_OBLIVION, 0x0, 9, MOVE_OBLIVION, 131, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep18Frame0, gCardWep18Tiles, gCardWep18Palette, LOCALIZED(gCardNameDiamondDust), gDiamondDustSmallCardFrame0, gDiamondDustSmallCardTiles, gDiamondDustSmallCardPalette,
        CARD_KIND_DIAMOND_DUST, 0x0, 0, MOVE_DIAMOND_DUST, 141, CARD_CATEGORY_ATTACK, 25, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep18Frame0, gCardWep18Tiles, gCardWep18Palette, LOCALIZED(gCardNameDiamondDust), gDiamondDustSmallCardFrame0, gDiamondDustSmallCardTiles, gDiamondDustSmallCardPalette,
        CARD_KIND_DIAMOND_DUST, 0x0, 1, MOVE_DIAMOND_DUST, 141, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep18Frame0, gCardWep18Tiles, gCardWep18Palette, LOCALIZED(gCardNameDiamondDust), gDiamondDustSmallCardFrame0, gDiamondDustSmallCardTiles, gDiamondDustSmallCardPalette,
        CARD_KIND_DIAMOND_DUST, 0x0, 2, MOVE_DIAMOND_DUST, 141, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep18Frame0, gCardWep18Tiles, gCardWep18Palette, LOCALIZED(gCardNameDiamondDust), gDiamondDustSmallCardFrame0, gDiamondDustSmallCardTiles, gDiamondDustSmallCardPalette,
        CARD_KIND_DIAMOND_DUST, 0x0, 3, MOVE_DIAMOND_DUST, 141, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep18Frame0, gCardWep18Tiles, gCardWep18Palette, LOCALIZED(gCardNameDiamondDust), gDiamondDustSmallCardFrame0, gDiamondDustSmallCardTiles, gDiamondDustSmallCardPalette,
        CARD_KIND_DIAMOND_DUST, 0x0, 4, MOVE_DIAMOND_DUST, 141, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep18Frame0, gCardWep18Tiles, gCardWep18Palette, LOCALIZED(gCardNameDiamondDust), gDiamondDustSmallCardFrame0, gDiamondDustSmallCardTiles, gDiamondDustSmallCardPalette,
        CARD_KIND_DIAMOND_DUST, 0x0, 5, MOVE_DIAMOND_DUST, 141, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep18Frame0, gCardWep18Tiles, gCardWep18Palette, LOCALIZED(gCardNameDiamondDust), gDiamondDustSmallCardFrame0, gDiamondDustSmallCardTiles, gDiamondDustSmallCardPalette,
        CARD_KIND_DIAMOND_DUST, 0x0, 6, MOVE_DIAMOND_DUST, 141, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep18Frame0, gCardWep18Tiles, gCardWep18Palette, LOCALIZED(gCardNameDiamondDust), gDiamondDustSmallCardFrame0, gDiamondDustSmallCardTiles, gDiamondDustSmallCardPalette,
        CARD_KIND_DIAMOND_DUST, 0x0, 7, MOVE_DIAMOND_DUST, 141, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep18Frame0, gCardWep18Tiles, gCardWep18Palette, LOCALIZED(gCardNameDiamondDust), gDiamondDustSmallCardFrame0, gDiamondDustSmallCardTiles, gDiamondDustSmallCardPalette,
        CARD_KIND_DIAMOND_DUST, 0x0, 8, MOVE_DIAMOND_DUST, 141, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep18Frame0, gCardWep18Tiles, gCardWep18Palette, LOCALIZED(gCardNameDiamondDust), gDiamondDustSmallCardFrame0, gDiamondDustSmallCardTiles, gDiamondDustSmallCardPalette,
        CARD_KIND_DIAMOND_DUST, 0x0, 9, MOVE_DIAMOND_DUST, 141, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep19Frame0, gCardWep19Tiles, gCardWep19Palette, LOCALIZED(gCardNameOneWingedAngel), gOneWingedAngelSmallCardFrame0, gOneWingedAngelSmallCardTiles, gOneWingedAngelSmallCardPalette,
        CARD_KIND_ONE_WINGED_ANGEL, 0x0, 0, MOVE_ONE_WINGED_ANGEL, 151, CARD_CATEGORY_ATTACK, 25, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep19Frame0, gCardWep19Tiles, gCardWep19Palette, LOCALIZED(gCardNameOneWingedAngel), gOneWingedAngelSmallCardFrame0, gOneWingedAngelSmallCardTiles, gOneWingedAngelSmallCardPalette,
        CARD_KIND_ONE_WINGED_ANGEL, 0x0, 1, MOVE_ONE_WINGED_ANGEL, 151, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep19Frame0, gCardWep19Tiles, gCardWep19Palette, LOCALIZED(gCardNameOneWingedAngel), gOneWingedAngelSmallCardFrame0, gOneWingedAngelSmallCardTiles, gOneWingedAngelSmallCardPalette,
        CARD_KIND_ONE_WINGED_ANGEL, 0x0, 2, MOVE_ONE_WINGED_ANGEL, 151, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep19Frame0, gCardWep19Tiles, gCardWep19Palette, LOCALIZED(gCardNameOneWingedAngel), gOneWingedAngelSmallCardFrame0, gOneWingedAngelSmallCardTiles, gOneWingedAngelSmallCardPalette,
        CARD_KIND_ONE_WINGED_ANGEL, 0x0, 3, MOVE_ONE_WINGED_ANGEL, 151, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep19Frame0, gCardWep19Tiles, gCardWep19Palette, LOCALIZED(gCardNameOneWingedAngel), gOneWingedAngelSmallCardFrame0, gOneWingedAngelSmallCardTiles, gOneWingedAngelSmallCardPalette,
        CARD_KIND_ONE_WINGED_ANGEL, 0x0, 4, MOVE_ONE_WINGED_ANGEL, 151, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep19Frame0, gCardWep19Tiles, gCardWep19Palette, LOCALIZED(gCardNameOneWingedAngel), gOneWingedAngelSmallCardFrame0, gOneWingedAngelSmallCardTiles, gOneWingedAngelSmallCardPalette,
        CARD_KIND_ONE_WINGED_ANGEL, 0x0, 5, MOVE_ONE_WINGED_ANGEL, 151, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep19Frame0, gCardWep19Tiles, gCardWep19Palette, LOCALIZED(gCardNameOneWingedAngel), gOneWingedAngelSmallCardFrame0, gOneWingedAngelSmallCardTiles, gOneWingedAngelSmallCardPalette,
        CARD_KIND_ONE_WINGED_ANGEL, 0x0, 6, MOVE_ONE_WINGED_ANGEL, 151, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep19Frame0, gCardWep19Tiles, gCardWep19Palette, LOCALIZED(gCardNameOneWingedAngel), gOneWingedAngelSmallCardFrame0, gOneWingedAngelSmallCardTiles, gOneWingedAngelSmallCardPalette,
        CARD_KIND_ONE_WINGED_ANGEL, 0x0, 7, MOVE_ONE_WINGED_ANGEL, 151, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep19Frame0, gCardWep19Tiles, gCardWep19Palette, LOCALIZED(gCardNameOneWingedAngel), gOneWingedAngelSmallCardFrame0, gOneWingedAngelSmallCardTiles, gOneWingedAngelSmallCardPalette,
        CARD_KIND_ONE_WINGED_ANGEL, 0x0, 8, MOVE_ONE_WINGED_ANGEL, 151, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep19Frame0, gCardWep19Tiles, gCardWep19Palette, LOCALIZED(gCardNameOneWingedAngel), gOneWingedAngelSmallCardFrame0, gOneWingedAngelSmallCardTiles, gOneWingedAngelSmallCardPalette,
        CARD_KIND_ONE_WINGED_ANGEL, 0x0, 9, MOVE_ONE_WINGED_ANGEL, 151, CARD_CATEGORY_ATTACK, 25, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep16Frame0, gCardWep16Tiles, gCardWep16Palette, LOCALIZED(gCardNameUltimaWeapon), gUltimaWeaponSmallCardFrame0, gUltimaWeaponSmallCardTiles, gUltimaWeaponSmallCardPalette,
        CARD_KIND_ULTIMA_WEAPON, 0x0, 0, MOVE_ULTIMA_WEAPON, 161, CARD_CATEGORY_ATTACK, 30, {10, 0, 0, 0, 0, 0},
    },
    {
        gCardWep16Frame0, gCardWep16Tiles, gCardWep16Palette, LOCALIZED(gCardNameUltimaWeapon), gUltimaWeaponSmallCardFrame0, gUltimaWeaponSmallCardTiles, gUltimaWeaponSmallCardPalette,
        CARD_KIND_ULTIMA_WEAPON, 0x0, 1, MOVE_ULTIMA_WEAPON, 161, CARD_CATEGORY_ATTACK, 30, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep16Frame0, gCardWep16Tiles, gCardWep16Palette, LOCALIZED(gCardNameUltimaWeapon), gUltimaWeaponSmallCardFrame0, gUltimaWeaponSmallCardTiles, gUltimaWeaponSmallCardPalette,
        CARD_KIND_ULTIMA_WEAPON, 0x0, 2, MOVE_ULTIMA_WEAPON, 161, CARD_CATEGORY_ATTACK, 30, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep16Frame0, gCardWep16Tiles, gCardWep16Palette, LOCALIZED(gCardNameUltimaWeapon), gUltimaWeaponSmallCardFrame0, gUltimaWeaponSmallCardTiles, gUltimaWeaponSmallCardPalette,
        CARD_KIND_ULTIMA_WEAPON, 0x0, 3, MOVE_ULTIMA_WEAPON, 161, CARD_CATEGORY_ATTACK, 30, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep16Frame0, gCardWep16Tiles, gCardWep16Palette, LOCALIZED(gCardNameUltimaWeapon), gUltimaWeaponSmallCardFrame0, gUltimaWeaponSmallCardTiles, gUltimaWeaponSmallCardPalette,
        CARD_KIND_ULTIMA_WEAPON, 0x0, 4, MOVE_ULTIMA_WEAPON, 161, CARD_CATEGORY_ATTACK, 30, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep16Frame0, gCardWep16Tiles, gCardWep16Palette, LOCALIZED(gCardNameUltimaWeapon), gUltimaWeaponSmallCardFrame0, gUltimaWeaponSmallCardTiles, gUltimaWeaponSmallCardPalette,
        CARD_KIND_ULTIMA_WEAPON, 0x0, 5, MOVE_ULTIMA_WEAPON, 161, CARD_CATEGORY_ATTACK, 30, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep16Frame0, gCardWep16Tiles, gCardWep16Palette, LOCALIZED(gCardNameUltimaWeapon), gUltimaWeaponSmallCardFrame0, gUltimaWeaponSmallCardTiles, gUltimaWeaponSmallCardPalette,
        CARD_KIND_ULTIMA_WEAPON, 0x0, 6, MOVE_ULTIMA_WEAPON, 161, CARD_CATEGORY_ATTACK, 30, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep16Frame0, gCardWep16Tiles, gCardWep16Palette, LOCALIZED(gCardNameUltimaWeapon), gUltimaWeaponSmallCardFrame0, gUltimaWeaponSmallCardTiles, gUltimaWeaponSmallCardPalette,
        CARD_KIND_ULTIMA_WEAPON, 0x0, 7, MOVE_ULTIMA_WEAPON, 161, CARD_CATEGORY_ATTACK, 30, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep16Frame0, gCardWep16Tiles, gCardWep16Palette, LOCALIZED(gCardNameUltimaWeapon), gUltimaWeaponSmallCardFrame0, gUltimaWeaponSmallCardTiles, gUltimaWeaponSmallCardPalette,
        CARD_KIND_ULTIMA_WEAPON, 0x0, 8, MOVE_ULTIMA_WEAPON, 161, CARD_CATEGORY_ATTACK, 30, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardWep16Frame0, gCardWep16Tiles, gCardWep16Palette, LOCALIZED(gCardNameUltimaWeapon), gUltimaWeaponSmallCardFrame0, gUltimaWeaponSmallCardTiles, gUltimaWeaponSmallCardPalette,
        CARD_KIND_ULTIMA_WEAPON, 0x0, 9, MOVE_ULTIMA_WEAPON, 161, CARD_CATEGORY_ATTACK, 30, {2, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc01Frame0, gCardMgc01Tiles, gCardMgc01Palette, LOCALIZED(gCardNameFire), gFireSmallCardFrame0, gFireSmallCardTiles, gFireSmallCardPalette,
        CARD_KIND_FIRE, 0x0, 0, MOVE_FIRE, 171, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc01Frame0, gCardMgc01Tiles, gCardMgc01Palette, LOCALIZED(gCardNameFire), gFireSmallCardFrame0, gFireSmallCardTiles, gFireSmallCardPalette,
        CARD_KIND_FIRE, 0x0, 1, MOVE_FIRE, 171, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc01Frame0, gCardMgc01Tiles, gCardMgc01Palette, LOCALIZED(gCardNameFire), gFireSmallCardFrame0, gFireSmallCardTiles, gFireSmallCardPalette,
        CARD_KIND_FIRE, 0x0, 2, MOVE_FIRE, 171, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc01Frame0, gCardMgc01Tiles, gCardMgc01Palette, LOCALIZED(gCardNameFire), gFireSmallCardFrame0, gFireSmallCardTiles, gFireSmallCardPalette,
        CARD_KIND_FIRE, 0x0, 3, MOVE_FIRE, 171, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc01Frame0, gCardMgc01Tiles, gCardMgc01Palette, LOCALIZED(gCardNameFire), gFireSmallCardFrame0, gFireSmallCardTiles, gFireSmallCardPalette,
        CARD_KIND_FIRE, 0x0, 4, MOVE_FIRE, 171, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc01Frame0, gCardMgc01Tiles, gCardMgc01Palette, LOCALIZED(gCardNameFire), gFireSmallCardFrame0, gFireSmallCardTiles, gFireSmallCardPalette,
        CARD_KIND_FIRE, 0x0, 5, MOVE_FIRE, 171, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc01Frame0, gCardMgc01Tiles, gCardMgc01Palette, LOCALIZED(gCardNameFire), gFireSmallCardFrame0, gFireSmallCardTiles, gFireSmallCardPalette,
        CARD_KIND_FIRE, 0x0, 6, MOVE_FIRE, 171, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc01Frame0, gCardMgc01Tiles, gCardMgc01Palette, LOCALIZED(gCardNameFire), gFireSmallCardFrame0, gFireSmallCardTiles, gFireSmallCardPalette,
        CARD_KIND_FIRE, 0x0, 7, MOVE_FIRE, 171, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc01Frame0, gCardMgc01Tiles, gCardMgc01Palette, LOCALIZED(gCardNameFire), gFireSmallCardFrame0, gFireSmallCardTiles, gFireSmallCardPalette,
        CARD_KIND_FIRE, 0x0, 8, MOVE_FIRE, 171, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc01Frame0, gCardMgc01Tiles, gCardMgc01Palette, LOCALIZED(gCardNameFire), gFireSmallCardFrame0, gFireSmallCardTiles, gFireSmallCardPalette,
        CARD_KIND_FIRE, 0x0, 9, MOVE_FIRE, 171, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc02Frame0, gCardMgc02Tiles, gCardMgc02Palette, LOCALIZED(gCardNameBlizzard), gBlizzardSmallCardFrame0, gBlizzardSmallCardTiles, gBlizzardSmallCardPalette,
        CARD_KIND_BLIZZARD, 0x0, 0, MOVE_BLIZZARD, 181, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc02Frame0, gCardMgc02Tiles, gCardMgc02Palette, LOCALIZED(gCardNameBlizzard), gBlizzardSmallCardFrame0, gBlizzardSmallCardTiles, gBlizzardSmallCardPalette,
        CARD_KIND_BLIZZARD, 0x0, 1, MOVE_BLIZZARD, 181, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc02Frame0, gCardMgc02Tiles, gCardMgc02Palette, LOCALIZED(gCardNameBlizzard), gBlizzardSmallCardFrame0, gBlizzardSmallCardTiles, gBlizzardSmallCardPalette,
        CARD_KIND_BLIZZARD, 0x0, 2, MOVE_BLIZZARD, 181, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc02Frame0, gCardMgc02Tiles, gCardMgc02Palette, LOCALIZED(gCardNameBlizzard), gBlizzardSmallCardFrame0, gBlizzardSmallCardTiles, gBlizzardSmallCardPalette,
        CARD_KIND_BLIZZARD, 0x0, 3, MOVE_BLIZZARD, 181, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc02Frame0, gCardMgc02Tiles, gCardMgc02Palette, LOCALIZED(gCardNameBlizzard), gBlizzardSmallCardFrame0, gBlizzardSmallCardTiles, gBlizzardSmallCardPalette,
        CARD_KIND_BLIZZARD, 0x0, 4, MOVE_BLIZZARD, 181, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc02Frame0, gCardMgc02Tiles, gCardMgc02Palette, LOCALIZED(gCardNameBlizzard), gBlizzardSmallCardFrame0, gBlizzardSmallCardTiles, gBlizzardSmallCardPalette,
        CARD_KIND_BLIZZARD, 0x0, 5, MOVE_BLIZZARD, 181, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc02Frame0, gCardMgc02Tiles, gCardMgc02Palette, LOCALIZED(gCardNameBlizzard), gBlizzardSmallCardFrame0, gBlizzardSmallCardTiles, gBlizzardSmallCardPalette,
        CARD_KIND_BLIZZARD, 0x0, 6, MOVE_BLIZZARD, 181, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc02Frame0, gCardMgc02Tiles, gCardMgc02Palette, LOCALIZED(gCardNameBlizzard), gBlizzardSmallCardFrame0, gBlizzardSmallCardTiles, gBlizzardSmallCardPalette,
        CARD_KIND_BLIZZARD, 0x0, 7, MOVE_BLIZZARD, 181, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc02Frame0, gCardMgc02Tiles, gCardMgc02Palette, LOCALIZED(gCardNameBlizzard), gBlizzardSmallCardFrame0, gBlizzardSmallCardTiles, gBlizzardSmallCardPalette,
        CARD_KIND_BLIZZARD, 0x0, 8, MOVE_BLIZZARD, 181, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc02Frame0, gCardMgc02Tiles, gCardMgc02Palette, LOCALIZED(gCardNameBlizzard), gBlizzardSmallCardFrame0, gBlizzardSmallCardTiles, gBlizzardSmallCardPalette,
        CARD_KIND_BLIZZARD, 0x0, 9, MOVE_BLIZZARD, 181, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc03Frame0, gCardMgc03Tiles, gCardMgc03Palette, LOCALIZED(gCardNameThunder), gThunderSmallCardFrame0, gThunderSmallCardTiles, gThunderSmallCardPalette,
        CARD_KIND_THUNDER, 0x0, 0, MOVE_THUNDER, 191, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc03Frame0, gCardMgc03Tiles, gCardMgc03Palette, LOCALIZED(gCardNameThunder), gThunderSmallCardFrame0, gThunderSmallCardTiles, gThunderSmallCardPalette,
        CARD_KIND_THUNDER, 0x0, 1, MOVE_THUNDER, 191, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc03Frame0, gCardMgc03Tiles, gCardMgc03Palette, LOCALIZED(gCardNameThunder), gThunderSmallCardFrame0, gThunderSmallCardTiles, gThunderSmallCardPalette,
        CARD_KIND_THUNDER, 0x0, 2, MOVE_THUNDER, 191, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc03Frame0, gCardMgc03Tiles, gCardMgc03Palette, LOCALIZED(gCardNameThunder), gThunderSmallCardFrame0, gThunderSmallCardTiles, gThunderSmallCardPalette,
        CARD_KIND_THUNDER, 0x0, 3, MOVE_THUNDER, 191, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc03Frame0, gCardMgc03Tiles, gCardMgc03Palette, LOCALIZED(gCardNameThunder), gThunderSmallCardFrame0, gThunderSmallCardTiles, gThunderSmallCardPalette,
        CARD_KIND_THUNDER, 0x0, 4, MOVE_THUNDER, 191, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc03Frame0, gCardMgc03Tiles, gCardMgc03Palette, LOCALIZED(gCardNameThunder), gThunderSmallCardFrame0, gThunderSmallCardTiles, gThunderSmallCardPalette,
        CARD_KIND_THUNDER, 0x0, 5, MOVE_THUNDER, 191, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc03Frame0, gCardMgc03Tiles, gCardMgc03Palette, LOCALIZED(gCardNameThunder), gThunderSmallCardFrame0, gThunderSmallCardTiles, gThunderSmallCardPalette,
        CARD_KIND_THUNDER, 0x0, 6, MOVE_THUNDER, 191, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc03Frame0, gCardMgc03Tiles, gCardMgc03Palette, LOCALIZED(gCardNameThunder), gThunderSmallCardFrame0, gThunderSmallCardTiles, gThunderSmallCardPalette,
        CARD_KIND_THUNDER, 0x0, 7, MOVE_THUNDER, 191, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc03Frame0, gCardMgc03Tiles, gCardMgc03Palette, LOCALIZED(gCardNameThunder), gThunderSmallCardFrame0, gThunderSmallCardTiles, gThunderSmallCardPalette,
        CARD_KIND_THUNDER, 0x0, 8, MOVE_THUNDER, 191, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc03Frame0, gCardMgc03Tiles, gCardMgc03Palette, LOCALIZED(gCardNameThunder), gThunderSmallCardFrame0, gThunderSmallCardTiles, gThunderSmallCardPalette,
        CARD_KIND_THUNDER, 0x0, 9, MOVE_THUNDER, 191, CARD_CATEGORY_MAGIC, 15, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc04Frame0, gCardMgc04Tiles, gCardMgc04Palette, LOCALIZED(gCardNameCure), gCureSmallCardFrame0, gCureSmallCardTiles, gCureSmallCardPalette,
        CARD_KIND_CURE, 0x0, 0, MOVE_CURE, 201, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc04Frame0, gCardMgc04Tiles, gCardMgc04Palette, LOCALIZED(gCardNameCure), gCureSmallCardFrame0, gCureSmallCardTiles, gCureSmallCardPalette,
        CARD_KIND_CURE, 0x0, 1, MOVE_CURE, 201, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc04Frame0, gCardMgc04Tiles, gCardMgc04Palette, LOCALIZED(gCardNameCure), gCureSmallCardFrame0, gCureSmallCardTiles, gCureSmallCardPalette,
        CARD_KIND_CURE, 0x0, 2, MOVE_CURE, 201, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc04Frame0, gCardMgc04Tiles, gCardMgc04Palette, LOCALIZED(gCardNameCure), gCureSmallCardFrame0, gCureSmallCardTiles, gCureSmallCardPalette,
        CARD_KIND_CURE, 0x0, 3, MOVE_CURE, 201, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc04Frame0, gCardMgc04Tiles, gCardMgc04Palette, LOCALIZED(gCardNameCure), gCureSmallCardFrame0, gCureSmallCardTiles, gCureSmallCardPalette,
        CARD_KIND_CURE, 0x0, 4, MOVE_CURE, 201, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc04Frame0, gCardMgc04Tiles, gCardMgc04Palette, LOCALIZED(gCardNameCure), gCureSmallCardFrame0, gCureSmallCardTiles, gCureSmallCardPalette,
        CARD_KIND_CURE, 0x0, 5, MOVE_CURE, 201, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc04Frame0, gCardMgc04Tiles, gCardMgc04Palette, LOCALIZED(gCardNameCure), gCureSmallCardFrame0, gCureSmallCardTiles, gCureSmallCardPalette,
        CARD_KIND_CURE, 0x0, 6, MOVE_CURE, 201, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc04Frame0, gCardMgc04Tiles, gCardMgc04Palette, LOCALIZED(gCardNameCure), gCureSmallCardFrame0, gCureSmallCardTiles, gCureSmallCardPalette,
        CARD_KIND_CURE, 0x0, 7, MOVE_CURE, 201, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc04Frame0, gCardMgc04Tiles, gCardMgc04Palette, LOCALIZED(gCardNameCure), gCureSmallCardFrame0, gCureSmallCardTiles, gCureSmallCardPalette,
        CARD_KIND_CURE, 0x0, 8, MOVE_CURE, 201, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc04Frame0, gCardMgc04Tiles, gCardMgc04Palette, LOCALIZED(gCardNameCure), gCureSmallCardFrame0, gCureSmallCardTiles, gCureSmallCardPalette,
        CARD_KIND_CURE, 0x0, 9, MOVE_CURE, 201, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc05Frame0, gCardMgc05Tiles, gCardMgc05Palette, LOCALIZED(gCardNameGravity), gGravitySmallCardFrame0, gGravitySmallCardTiles, gGravitySmallCardPalette,
        CARD_KIND_GRAVITY, 0x0, 0, MOVE_GRAVITY, 211, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc05Frame0, gCardMgc05Tiles, gCardMgc05Palette, LOCALIZED(gCardNameGravity), gGravitySmallCardFrame0, gGravitySmallCardTiles, gGravitySmallCardPalette,
        CARD_KIND_GRAVITY, 0x0, 1, MOVE_GRAVITY, 211, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc05Frame0, gCardMgc05Tiles, gCardMgc05Palette, LOCALIZED(gCardNameGravity), gGravitySmallCardFrame0, gGravitySmallCardTiles, gGravitySmallCardPalette,
        CARD_KIND_GRAVITY, 0x0, 2, MOVE_GRAVITY, 211, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc05Frame0, gCardMgc05Tiles, gCardMgc05Palette, LOCALIZED(gCardNameGravity), gGravitySmallCardFrame0, gGravitySmallCardTiles, gGravitySmallCardPalette,
        CARD_KIND_GRAVITY, 0x0, 3, MOVE_GRAVITY, 211, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc05Frame0, gCardMgc05Tiles, gCardMgc05Palette, LOCALIZED(gCardNameGravity), gGravitySmallCardFrame0, gGravitySmallCardTiles, gGravitySmallCardPalette,
        CARD_KIND_GRAVITY, 0x0, 4, MOVE_GRAVITY, 211, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc05Frame0, gCardMgc05Tiles, gCardMgc05Palette, LOCALIZED(gCardNameGravity), gGravitySmallCardFrame0, gGravitySmallCardTiles, gGravitySmallCardPalette,
        CARD_KIND_GRAVITY, 0x0, 5, MOVE_GRAVITY, 211, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc05Frame0, gCardMgc05Tiles, gCardMgc05Palette, LOCALIZED(gCardNameGravity), gGravitySmallCardFrame0, gGravitySmallCardTiles, gGravitySmallCardPalette,
        CARD_KIND_GRAVITY, 0x0, 6, MOVE_GRAVITY, 211, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc05Frame0, gCardMgc05Tiles, gCardMgc05Palette, LOCALIZED(gCardNameGravity), gGravitySmallCardFrame0, gGravitySmallCardTiles, gGravitySmallCardPalette,
        CARD_KIND_GRAVITY, 0x0, 7, MOVE_GRAVITY, 211, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc05Frame0, gCardMgc05Tiles, gCardMgc05Palette, LOCALIZED(gCardNameGravity), gGravitySmallCardFrame0, gGravitySmallCardTiles, gGravitySmallCardPalette,
        CARD_KIND_GRAVITY, 0x0, 8, MOVE_GRAVITY, 211, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc05Frame0, gCardMgc05Tiles, gCardMgc05Palette, LOCALIZED(gCardNameGravity), gGravitySmallCardFrame0, gGravitySmallCardTiles, gGravitySmallCardPalette,
        CARD_KIND_GRAVITY, 0x0, 9, MOVE_GRAVITY, 211, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc06Frame0, gCardMgc06Tiles, gCardMgc06Palette, LOCALIZED(gCardNameStop), gStopSmallCardFrame0, gStopSmallCardTiles, gStopSmallCardPalette,
        CARD_KIND_STOP, 0x0, 0, MOVE_STOP, 221, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc06Frame0, gCardMgc06Tiles, gCardMgc06Palette, LOCALIZED(gCardNameStop), gStopSmallCardFrame0, gStopSmallCardTiles, gStopSmallCardPalette,
        CARD_KIND_STOP, 0x0, 1, MOVE_STOP, 221, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc06Frame0, gCardMgc06Tiles, gCardMgc06Palette, LOCALIZED(gCardNameStop), gStopSmallCardFrame0, gStopSmallCardTiles, gStopSmallCardPalette,
        CARD_KIND_STOP, 0x0, 2, MOVE_STOP, 221, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc06Frame0, gCardMgc06Tiles, gCardMgc06Palette, LOCALIZED(gCardNameStop), gStopSmallCardFrame0, gStopSmallCardTiles, gStopSmallCardPalette,
        CARD_KIND_STOP, 0x0, 3, MOVE_STOP, 221, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc06Frame0, gCardMgc06Tiles, gCardMgc06Palette, LOCALIZED(gCardNameStop), gStopSmallCardFrame0, gStopSmallCardTiles, gStopSmallCardPalette,
        CARD_KIND_STOP, 0x0, 4, MOVE_STOP, 221, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc06Frame0, gCardMgc06Tiles, gCardMgc06Palette, LOCALIZED(gCardNameStop), gStopSmallCardFrame0, gStopSmallCardTiles, gStopSmallCardPalette,
        CARD_KIND_STOP, 0x0, 5, MOVE_STOP, 221, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc06Frame0, gCardMgc06Tiles, gCardMgc06Palette, LOCALIZED(gCardNameStop), gStopSmallCardFrame0, gStopSmallCardTiles, gStopSmallCardPalette,
        CARD_KIND_STOP, 0x0, 6, MOVE_STOP, 221, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc06Frame0, gCardMgc06Tiles, gCardMgc06Palette, LOCALIZED(gCardNameStop), gStopSmallCardFrame0, gStopSmallCardTiles, gStopSmallCardPalette,
        CARD_KIND_STOP, 0x0, 7, MOVE_STOP, 221, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc06Frame0, gCardMgc06Tiles, gCardMgc06Palette, LOCALIZED(gCardNameStop), gStopSmallCardFrame0, gStopSmallCardTiles, gStopSmallCardPalette,
        CARD_KIND_STOP, 0x0, 8, MOVE_STOP, 221, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc06Frame0, gCardMgc06Tiles, gCardMgc06Palette, LOCALIZED(gCardNameStop), gStopSmallCardFrame0, gStopSmallCardTiles, gStopSmallCardPalette,
        CARD_KIND_STOP, 0x0, 9, MOVE_STOP, 221, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc07Frame0, gCardMgc07Tiles, gCardMgc07Palette, LOCALIZED(gCardNameAero), gAeroSmallCardFrame0, gAeroSmallCardTiles, gAeroSmallCardPalette,
        CARD_KIND_AERO, 0x0, 0, MOVE_AERO, 231, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc07Frame0, gCardMgc07Tiles, gCardMgc07Palette, LOCALIZED(gCardNameAero), gAeroSmallCardFrame0, gAeroSmallCardTiles, gAeroSmallCardPalette,
        CARD_KIND_AERO, 0x0, 1, MOVE_AERO, 231, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc07Frame0, gCardMgc07Tiles, gCardMgc07Palette, LOCALIZED(gCardNameAero), gAeroSmallCardFrame0, gAeroSmallCardTiles, gAeroSmallCardPalette,
        CARD_KIND_AERO, 0x0, 2, MOVE_AERO, 231, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc07Frame0, gCardMgc07Tiles, gCardMgc07Palette, LOCALIZED(gCardNameAero), gAeroSmallCardFrame0, gAeroSmallCardTiles, gAeroSmallCardPalette,
        CARD_KIND_AERO, 0x0, 3, MOVE_AERO, 231, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc07Frame0, gCardMgc07Tiles, gCardMgc07Palette, LOCALIZED(gCardNameAero), gAeroSmallCardFrame0, gAeroSmallCardTiles, gAeroSmallCardPalette,
        CARD_KIND_AERO, 0x0, 4, MOVE_AERO, 231, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc07Frame0, gCardMgc07Tiles, gCardMgc07Palette, LOCALIZED(gCardNameAero), gAeroSmallCardFrame0, gAeroSmallCardTiles, gAeroSmallCardPalette,
        CARD_KIND_AERO, 0x0, 5, MOVE_AERO, 231, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc07Frame0, gCardMgc07Tiles, gCardMgc07Palette, LOCALIZED(gCardNameAero), gAeroSmallCardFrame0, gAeroSmallCardTiles, gAeroSmallCardPalette,
        CARD_KIND_AERO, 0x0, 6, MOVE_AERO, 231, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc07Frame0, gCardMgc07Tiles, gCardMgc07Palette, LOCALIZED(gCardNameAero), gAeroSmallCardFrame0, gAeroSmallCardTiles, gAeroSmallCardPalette,
        CARD_KIND_AERO, 0x0, 7, MOVE_AERO, 231, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc07Frame0, gCardMgc07Tiles, gCardMgc07Palette, LOCALIZED(gCardNameAero), gAeroSmallCardFrame0, gAeroSmallCardTiles, gAeroSmallCardPalette,
        CARD_KIND_AERO, 0x0, 8, MOVE_AERO, 231, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardMgc07Frame0, gCardMgc07Tiles, gCardMgc07Palette, LOCALIZED(gCardNameAero), gAeroSmallCardFrame0, gAeroSmallCardTiles, gAeroSmallCardPalette,
        CARD_KIND_AERO, 0x0, 9, MOVE_AERO, 231, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn02Frame0, gCardSmn02Tiles, gDonaldPalette, LOCALIZED(gCardNameDonaldDuck), gDonaldDuckSmallCardFrame0, gDonaldDuckSmallCardTiles, gDonaldDuckSmallCardPalette,
        CARD_KIND_DONALD_DUCK, CARD_DEF_FLAG_FRIEND, 0, MOVE_DONALD_DUCK, 241, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn02Frame0, gCardSmn02Tiles, gDonaldPalette, LOCALIZED(gCardNameDonaldDuck), gDonaldDuckSmallCardFrame0, gDonaldDuckSmallCardTiles, gDonaldDuckSmallCardPalette,
        CARD_KIND_DONALD_DUCK, CARD_DEF_FLAG_FRIEND, 1, MOVE_DONALD_DUCK, 241, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn02Frame0, gCardSmn02Tiles, gDonaldPalette, LOCALIZED(gCardNameDonaldDuck), gDonaldDuckSmallCardFrame0, gDonaldDuckSmallCardTiles, gDonaldDuckSmallCardPalette,
        CARD_KIND_DONALD_DUCK, CARD_DEF_FLAG_FRIEND, 2, MOVE_DONALD_DUCK, 241, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn02Frame0, gCardSmn02Tiles, gDonaldPalette, LOCALIZED(gCardNameDonaldDuck), gDonaldDuckSmallCardFrame0, gDonaldDuckSmallCardTiles, gDonaldDuckSmallCardPalette,
        CARD_KIND_DONALD_DUCK, CARD_DEF_FLAG_FRIEND, 3, MOVE_DONALD_DUCK, 241, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn02Frame0, gCardSmn02Tiles, gDonaldPalette, LOCALIZED(gCardNameDonaldDuck), gDonaldDuckSmallCardFrame0, gDonaldDuckSmallCardTiles, gDonaldDuckSmallCardPalette,
        CARD_KIND_DONALD_DUCK, CARD_DEF_FLAG_FRIEND, 4, MOVE_DONALD_DUCK, 241, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn02Frame0, gCardSmn02Tiles, gDonaldPalette, LOCALIZED(gCardNameDonaldDuck), gDonaldDuckSmallCardFrame0, gDonaldDuckSmallCardTiles, gDonaldDuckSmallCardPalette,
        CARD_KIND_DONALD_DUCK, CARD_DEF_FLAG_FRIEND, 5, MOVE_DONALD_DUCK, 241, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn02Frame0, gCardSmn02Tiles, gDonaldPalette, LOCALIZED(gCardNameDonaldDuck), gDonaldDuckSmallCardFrame0, gDonaldDuckSmallCardTiles, gDonaldDuckSmallCardPalette,
        CARD_KIND_DONALD_DUCK, CARD_DEF_FLAG_FRIEND, 6, MOVE_DONALD_DUCK, 241, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn02Frame0, gCardSmn02Tiles, gDonaldPalette, LOCALIZED(gCardNameDonaldDuck), gDonaldDuckSmallCardFrame0, gDonaldDuckSmallCardTiles, gDonaldDuckSmallCardPalette,
        CARD_KIND_DONALD_DUCK, CARD_DEF_FLAG_FRIEND, 7, MOVE_DONALD_DUCK, 241, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn02Frame0, gCardSmn02Tiles, gDonaldPalette, LOCALIZED(gCardNameDonaldDuck), gDonaldDuckSmallCardFrame0, gDonaldDuckSmallCardTiles, gDonaldDuckSmallCardPalette,
        CARD_KIND_DONALD_DUCK, CARD_DEF_FLAG_FRIEND, 8, MOVE_DONALD_DUCK, 241, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn02Frame0, gCardSmn02Tiles, gDonaldPalette, LOCALIZED(gCardNameDonaldDuck), gDonaldDuckSmallCardFrame0, gDonaldDuckSmallCardTiles, gDonaldDuckSmallCardPalette,
        CARD_KIND_DONALD_DUCK, CARD_DEF_FLAG_FRIEND, 9, MOVE_DONALD_DUCK, 241, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn01Frame0, gCardSmn01Tiles, gGoofyPalette, LOCALIZED(gCardNameGoofy), gGoofySmallCardFrame0, gGoofySmallCardTiles, gGoofySmallCardPalette,
        CARD_KIND_GOOFY, CARD_DEF_FLAG_FRIEND, 0, MOVE_GOOFY, 251, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn01Frame0, gCardSmn01Tiles, gGoofyPalette, LOCALIZED(gCardNameGoofy), gGoofySmallCardFrame0, gGoofySmallCardTiles, gGoofySmallCardPalette,
        CARD_KIND_GOOFY, CARD_DEF_FLAG_FRIEND, 1, MOVE_GOOFY, 251, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn01Frame0, gCardSmn01Tiles, gGoofyPalette, LOCALIZED(gCardNameGoofy), gGoofySmallCardFrame0, gGoofySmallCardTiles, gGoofySmallCardPalette,
        CARD_KIND_GOOFY, CARD_DEF_FLAG_FRIEND, 2, MOVE_GOOFY, 251, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn01Frame0, gCardSmn01Tiles, gGoofyPalette, LOCALIZED(gCardNameGoofy), gGoofySmallCardFrame0, gGoofySmallCardTiles, gGoofySmallCardPalette,
        CARD_KIND_GOOFY, CARD_DEF_FLAG_FRIEND, 3, MOVE_GOOFY, 251, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn01Frame0, gCardSmn01Tiles, gGoofyPalette, LOCALIZED(gCardNameGoofy), gGoofySmallCardFrame0, gGoofySmallCardTiles, gGoofySmallCardPalette,
        CARD_KIND_GOOFY, CARD_DEF_FLAG_FRIEND, 4, MOVE_GOOFY, 251, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn01Frame0, gCardSmn01Tiles, gGoofyPalette, LOCALIZED(gCardNameGoofy), gGoofySmallCardFrame0, gGoofySmallCardTiles, gGoofySmallCardPalette,
        CARD_KIND_GOOFY, CARD_DEF_FLAG_FRIEND, 5, MOVE_GOOFY, 251, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn01Frame0, gCardSmn01Tiles, gGoofyPalette, LOCALIZED(gCardNameGoofy), gGoofySmallCardFrame0, gGoofySmallCardTiles, gGoofySmallCardPalette,
        CARD_KIND_GOOFY, CARD_DEF_FLAG_FRIEND, 6, MOVE_GOOFY, 251, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn01Frame0, gCardSmn01Tiles, gGoofyPalette, LOCALIZED(gCardNameGoofy), gGoofySmallCardFrame0, gGoofySmallCardTiles, gGoofySmallCardPalette,
        CARD_KIND_GOOFY, CARD_DEF_FLAG_FRIEND, 7, MOVE_GOOFY, 251, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn01Frame0, gCardSmn01Tiles, gGoofyPalette, LOCALIZED(gCardNameGoofy), gGoofySmallCardFrame0, gGoofySmallCardTiles, gGoofySmallCardPalette,
        CARD_KIND_GOOFY, CARD_DEF_FLAG_FRIEND, 8, MOVE_GOOFY, 251, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn01Frame0, gCardSmn01Tiles, gGoofyPalette, LOCALIZED(gCardNameGoofy), gGoofySmallCardFrame0, gGoofySmallCardTiles, gGoofySmallCardPalette,
        CARD_KIND_GOOFY, CARD_DEF_FLAG_FRIEND, 9, MOVE_GOOFY, 251, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn03Frame0, gCardSmn03Tiles, gCardSmn03Palette, LOCALIZED(gCardNameSimba), gSimbaSmallCardFrame0, gSimbaSmallCardTiles, gSimbaSmallCardPalette,
        CARD_KIND_SIMBA, CARD_DEF_FLAG_SUMMON, 0, MOVE_SIMBA, 261, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn03Frame0, gCardSmn03Tiles, gCardSmn03Palette, LOCALIZED(gCardNameSimba), gSimbaSmallCardFrame0, gSimbaSmallCardTiles, gSimbaSmallCardPalette,
        CARD_KIND_SIMBA, CARD_DEF_FLAG_SUMMON, 1, MOVE_SIMBA, 261, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn03Frame0, gCardSmn03Tiles, gCardSmn03Palette, LOCALIZED(gCardNameSimba), gSimbaSmallCardFrame0, gSimbaSmallCardTiles, gSimbaSmallCardPalette,
        CARD_KIND_SIMBA, CARD_DEF_FLAG_SUMMON, 2, MOVE_SIMBA, 261, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn03Frame0, gCardSmn03Tiles, gCardSmn03Palette, LOCALIZED(gCardNameSimba), gSimbaSmallCardFrame0, gSimbaSmallCardTiles, gSimbaSmallCardPalette,
        CARD_KIND_SIMBA, CARD_DEF_FLAG_SUMMON, 3, MOVE_SIMBA, 261, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn03Frame0, gCardSmn03Tiles, gCardSmn03Palette, LOCALIZED(gCardNameSimba), gSimbaSmallCardFrame0, gSimbaSmallCardTiles, gSimbaSmallCardPalette,
        CARD_KIND_SIMBA, CARD_DEF_FLAG_SUMMON, 4, MOVE_SIMBA, 261, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn03Frame0, gCardSmn03Tiles, gCardSmn03Palette, LOCALIZED(gCardNameSimba), gSimbaSmallCardFrame0, gSimbaSmallCardTiles, gSimbaSmallCardPalette,
        CARD_KIND_SIMBA, CARD_DEF_FLAG_SUMMON, 5, MOVE_SIMBA, 261, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn03Frame0, gCardSmn03Tiles, gCardSmn03Palette, LOCALIZED(gCardNameSimba), gSimbaSmallCardFrame0, gSimbaSmallCardTiles, gSimbaSmallCardPalette,
        CARD_KIND_SIMBA, CARD_DEF_FLAG_SUMMON, 6, MOVE_SIMBA, 261, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn03Frame0, gCardSmn03Tiles, gCardSmn03Palette, LOCALIZED(gCardNameSimba), gSimbaSmallCardFrame0, gSimbaSmallCardTiles, gSimbaSmallCardPalette,
        CARD_KIND_SIMBA, CARD_DEF_FLAG_SUMMON, 7, MOVE_SIMBA, 261, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn03Frame0, gCardSmn03Tiles, gCardSmn03Palette, LOCALIZED(gCardNameSimba), gSimbaSmallCardFrame0, gSimbaSmallCardTiles, gSimbaSmallCardPalette,
        CARD_KIND_SIMBA, CARD_DEF_FLAG_SUMMON, 8, MOVE_SIMBA, 261, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn03Frame0, gCardSmn03Tiles, gCardSmn03Palette, LOCALIZED(gCardNameSimba), gSimbaSmallCardFrame0, gSimbaSmallCardTiles, gSimbaSmallCardPalette,
        CARD_KIND_SIMBA, CARD_DEF_FLAG_SUMMON, 9, MOVE_SIMBA, 261, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn04Frame0, gCardSmn04Tiles, gCardSmn04Palette, LOCALIZED(gCardNameGenie), gGenieSmallCardFrame0, gGenieSmallCardTiles, gGenieSmallCardPalette,
        CARD_KIND_GENIE, CARD_DEF_FLAG_SUMMON, 0, MOVE_GENIE, 271, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn04Frame0, gCardSmn04Tiles, gCardSmn04Palette, LOCALIZED(gCardNameGenie), gGenieSmallCardFrame0, gGenieSmallCardTiles, gGenieSmallCardPalette,
        CARD_KIND_GENIE, CARD_DEF_FLAG_SUMMON, 1, MOVE_GENIE, 271, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn04Frame0, gCardSmn04Tiles, gCardSmn04Palette, LOCALIZED(gCardNameGenie), gGenieSmallCardFrame0, gGenieSmallCardTiles, gGenieSmallCardPalette,
        CARD_KIND_GENIE, CARD_DEF_FLAG_SUMMON, 2, MOVE_GENIE, 271, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn04Frame0, gCardSmn04Tiles, gCardSmn04Palette, LOCALIZED(gCardNameGenie), gGenieSmallCardFrame0, gGenieSmallCardTiles, gGenieSmallCardPalette,
        CARD_KIND_GENIE, CARD_DEF_FLAG_SUMMON, 3, MOVE_GENIE, 271, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn04Frame0, gCardSmn04Tiles, gCardSmn04Palette, LOCALIZED(gCardNameGenie), gGenieSmallCardFrame0, gGenieSmallCardTiles, gGenieSmallCardPalette,
        CARD_KIND_GENIE, CARD_DEF_FLAG_SUMMON, 4, MOVE_GENIE, 271, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn04Frame0, gCardSmn04Tiles, gCardSmn04Palette, LOCALIZED(gCardNameGenie), gGenieSmallCardFrame0, gGenieSmallCardTiles, gGenieSmallCardPalette,
        CARD_KIND_GENIE, CARD_DEF_FLAG_SUMMON, 5, MOVE_GENIE, 271, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn04Frame0, gCardSmn04Tiles, gCardSmn04Palette, LOCALIZED(gCardNameGenie), gGenieSmallCardFrame0, gGenieSmallCardTiles, gGenieSmallCardPalette,
        CARD_KIND_GENIE, CARD_DEF_FLAG_SUMMON, 6, MOVE_GENIE, 271, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn04Frame0, gCardSmn04Tiles, gCardSmn04Palette, LOCALIZED(gCardNameGenie), gGenieSmallCardFrame0, gGenieSmallCardTiles, gGenieSmallCardPalette,
        CARD_KIND_GENIE, CARD_DEF_FLAG_SUMMON, 7, MOVE_GENIE, 271, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn04Frame0, gCardSmn04Tiles, gCardSmn04Palette, LOCALIZED(gCardNameGenie), gGenieSmallCardFrame0, gGenieSmallCardTiles, gGenieSmallCardPalette,
        CARD_KIND_GENIE, CARD_DEF_FLAG_SUMMON, 8, MOVE_GENIE, 271, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn04Frame0, gCardSmn04Tiles, gCardSmn04Palette, LOCALIZED(gCardNameGenie), gGenieSmallCardFrame0, gGenieSmallCardTiles, gGenieSmallCardPalette,
        CARD_KIND_GENIE, CARD_DEF_FLAG_SUMMON, 9, MOVE_GENIE, 271, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn05Frame0, gCardSmn05Tiles, gBanbPalette, LOCALIZED(gCardNameBambi), gBambiSmallCardFrame0, gBambiSmallCardTiles, gBambiSmallCardPalette,
        CARD_KIND_BAMBI, CARD_DEF_FLAG_SUMMON, 0, MOVE_BAMBI, 281, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn05Frame0, gCardSmn05Tiles, gBanbPalette, LOCALIZED(gCardNameBambi), gBambiSmallCardFrame0, gBambiSmallCardTiles, gBambiSmallCardPalette,
        CARD_KIND_BAMBI, CARD_DEF_FLAG_SUMMON, 1, MOVE_BAMBI, 281, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn05Frame0, gCardSmn05Tiles, gBanbPalette, LOCALIZED(gCardNameBambi), gBambiSmallCardFrame0, gBambiSmallCardTiles, gBambiSmallCardPalette,
        CARD_KIND_BAMBI, CARD_DEF_FLAG_SUMMON, 2, MOVE_BAMBI, 281, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn05Frame0, gCardSmn05Tiles, gBanbPalette, LOCALIZED(gCardNameBambi), gBambiSmallCardFrame0, gBambiSmallCardTiles, gBambiSmallCardPalette,
        CARD_KIND_BAMBI, CARD_DEF_FLAG_SUMMON, 3, MOVE_BAMBI, 281, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn05Frame0, gCardSmn05Tiles, gBanbPalette, LOCALIZED(gCardNameBambi), gBambiSmallCardFrame0, gBambiSmallCardTiles, gBambiSmallCardPalette,
        CARD_KIND_BAMBI, CARD_DEF_FLAG_SUMMON, 4, MOVE_BAMBI, 281, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn05Frame0, gCardSmn05Tiles, gBanbPalette, LOCALIZED(gCardNameBambi), gBambiSmallCardFrame0, gBambiSmallCardTiles, gBambiSmallCardPalette,
        CARD_KIND_BAMBI, CARD_DEF_FLAG_SUMMON, 5, MOVE_BAMBI, 281, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn05Frame0, gCardSmn05Tiles, gBanbPalette, LOCALIZED(gCardNameBambi), gBambiSmallCardFrame0, gBambiSmallCardTiles, gBambiSmallCardPalette,
        CARD_KIND_BAMBI, CARD_DEF_FLAG_SUMMON, 6, MOVE_BAMBI, 281, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn05Frame0, gCardSmn05Tiles, gBanbPalette, LOCALIZED(gCardNameBambi), gBambiSmallCardFrame0, gBambiSmallCardTiles, gBambiSmallCardPalette,
        CARD_KIND_BAMBI, CARD_DEF_FLAG_SUMMON, 7, MOVE_BAMBI, 281, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn05Frame0, gCardSmn05Tiles, gBanbPalette, LOCALIZED(gCardNameBambi), gBambiSmallCardFrame0, gBambiSmallCardTiles, gBambiSmallCardPalette,
        CARD_KIND_BAMBI, CARD_DEF_FLAG_SUMMON, 8, MOVE_BAMBI, 281, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn05Frame0, gCardSmn05Tiles, gBanbPalette, LOCALIZED(gCardNameBambi), gBambiSmallCardFrame0, gBambiSmallCardTiles, gBambiSmallCardPalette,
        CARD_KIND_BAMBI, CARD_DEF_FLAG_SUMMON, 9, MOVE_BAMBI, 281, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn06Frame0, gCardSmn06Tiles, gCardSmn06Palette, LOCALIZED(gCardNameDumbo), gDumboSmallCardFrame0, gDumboSmallCardTiles, gDumboSmallCardPalette,
        CARD_KIND_DUMBO, CARD_DEF_FLAG_SUMMON, 0, MOVE_DUMBO, 291, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn06Frame0, gCardSmn06Tiles, gCardSmn06Palette, LOCALIZED(gCardNameDumbo), gDumboSmallCardFrame0, gDumboSmallCardTiles, gDumboSmallCardPalette,
        CARD_KIND_DUMBO, CARD_DEF_FLAG_SUMMON, 1, MOVE_DUMBO, 291, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn06Frame0, gCardSmn06Tiles, gCardSmn06Palette, LOCALIZED(gCardNameDumbo), gDumboSmallCardFrame0, gDumboSmallCardTiles, gDumboSmallCardPalette,
        CARD_KIND_DUMBO, CARD_DEF_FLAG_SUMMON, 2, MOVE_DUMBO, 291, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn06Frame0, gCardSmn06Tiles, gCardSmn06Palette, LOCALIZED(gCardNameDumbo), gDumboSmallCardFrame0, gDumboSmallCardTiles, gDumboSmallCardPalette,
        CARD_KIND_DUMBO, CARD_DEF_FLAG_SUMMON, 3, MOVE_DUMBO, 291, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn06Frame0, gCardSmn06Tiles, gCardSmn06Palette, LOCALIZED(gCardNameDumbo), gDumboSmallCardFrame0, gDumboSmallCardTiles, gDumboSmallCardPalette,
        CARD_KIND_DUMBO, CARD_DEF_FLAG_SUMMON, 4, MOVE_DUMBO, 291, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn06Frame0, gCardSmn06Tiles, gCardSmn06Palette, LOCALIZED(gCardNameDumbo), gDumboSmallCardFrame0, gDumboSmallCardTiles, gDumboSmallCardPalette,
        CARD_KIND_DUMBO, CARD_DEF_FLAG_SUMMON, 5, MOVE_DUMBO, 291, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn06Frame0, gCardSmn06Tiles, gCardSmn06Palette, LOCALIZED(gCardNameDumbo), gDumboSmallCardFrame0, gDumboSmallCardTiles, gDumboSmallCardPalette,
        CARD_KIND_DUMBO, CARD_DEF_FLAG_SUMMON, 6, MOVE_DUMBO, 291, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn06Frame0, gCardSmn06Tiles, gCardSmn06Palette, LOCALIZED(gCardNameDumbo), gDumboSmallCardFrame0, gDumboSmallCardTiles, gDumboSmallCardPalette,
        CARD_KIND_DUMBO, CARD_DEF_FLAG_SUMMON, 7, MOVE_DUMBO, 291, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn06Frame0, gCardSmn06Tiles, gCardSmn06Palette, LOCALIZED(gCardNameDumbo), gDumboSmallCardFrame0, gDumboSmallCardTiles, gDumboSmallCardPalette,
        CARD_KIND_DUMBO, CARD_DEF_FLAG_SUMMON, 8, MOVE_DUMBO, 291, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn06Frame0, gCardSmn06Tiles, gCardSmn06Palette, LOCALIZED(gCardNameDumbo), gDumboSmallCardFrame0, gDumboSmallCardTiles, gDumboSmallCardPalette,
        CARD_KIND_DUMBO, CARD_DEF_FLAG_SUMMON, 9, MOVE_DUMBO, 291, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn07Frame0, gCardSmn07Tiles, gTinkPalette, LOCALIZED(gCardNameTinkerBell), gTinkerBellSmallCardFrame0, gTinkerBellSmallCardTiles, gTinkerBellSmallCardPalette,
        CARD_KIND_TINKER_BELL, CARD_DEF_FLAG_SUMMON, 0, MOVE_TINKER_BELL, 301, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn07Frame0, gCardSmn07Tiles, gTinkPalette, LOCALIZED(gCardNameTinkerBell), gTinkerBellSmallCardFrame0, gTinkerBellSmallCardTiles, gTinkerBellSmallCardPalette,
        CARD_KIND_TINKER_BELL, CARD_DEF_FLAG_SUMMON, 1, MOVE_TINKER_BELL, 301, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn07Frame0, gCardSmn07Tiles, gTinkPalette, LOCALIZED(gCardNameTinkerBell), gTinkerBellSmallCardFrame0, gTinkerBellSmallCardTiles, gTinkerBellSmallCardPalette,
        CARD_KIND_TINKER_BELL, CARD_DEF_FLAG_SUMMON, 2, MOVE_TINKER_BELL, 301, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn07Frame0, gCardSmn07Tiles, gTinkPalette, LOCALIZED(gCardNameTinkerBell), gTinkerBellSmallCardFrame0, gTinkerBellSmallCardTiles, gTinkerBellSmallCardPalette,
        CARD_KIND_TINKER_BELL, CARD_DEF_FLAG_SUMMON, 3, MOVE_TINKER_BELL, 301, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn07Frame0, gCardSmn07Tiles, gTinkPalette, LOCALIZED(gCardNameTinkerBell), gTinkerBellSmallCardFrame0, gTinkerBellSmallCardTiles, gTinkerBellSmallCardPalette,
        CARD_KIND_TINKER_BELL, CARD_DEF_FLAG_SUMMON, 4, MOVE_TINKER_BELL, 301, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn07Frame0, gCardSmn07Tiles, gTinkPalette, LOCALIZED(gCardNameTinkerBell), gTinkerBellSmallCardFrame0, gTinkerBellSmallCardTiles, gTinkerBellSmallCardPalette,
        CARD_KIND_TINKER_BELL, CARD_DEF_FLAG_SUMMON, 5, MOVE_TINKER_BELL, 301, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn07Frame0, gCardSmn07Tiles, gTinkPalette, LOCALIZED(gCardNameTinkerBell), gTinkerBellSmallCardFrame0, gTinkerBellSmallCardTiles, gTinkerBellSmallCardPalette,
        CARD_KIND_TINKER_BELL, CARD_DEF_FLAG_SUMMON, 6, MOVE_TINKER_BELL, 301, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn07Frame0, gCardSmn07Tiles, gTinkPalette, LOCALIZED(gCardNameTinkerBell), gTinkerBellSmallCardFrame0, gTinkerBellSmallCardTiles, gTinkerBellSmallCardPalette,
        CARD_KIND_TINKER_BELL, CARD_DEF_FLAG_SUMMON, 7, MOVE_TINKER_BELL, 301, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn07Frame0, gCardSmn07Tiles, gTinkPalette, LOCALIZED(gCardNameTinkerBell), gTinkerBellSmallCardFrame0, gTinkerBellSmallCardTiles, gTinkerBellSmallCardPalette,
        CARD_KIND_TINKER_BELL, CARD_DEF_FLAG_SUMMON, 8, MOVE_TINKER_BELL, 301, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn07Frame0, gCardSmn07Tiles, gTinkPalette, LOCALIZED(gCardNameTinkerBell), gTinkerBellSmallCardFrame0, gTinkerBellSmallCardTiles, gTinkerBellSmallCardPalette,
        CARD_KIND_TINKER_BELL, CARD_DEF_FLAG_SUMMON, 9, MOVE_TINKER_BELL, 301, CARD_CATEGORY_MAGIC, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn08Frame0, gCardSmn08Tiles, gMushuPalette, LOCALIZED(gCardNameMushu), gMushuSmallCardFrame0, gMushuSmallCardTiles, gMushuSmallCardPalette,
        CARD_KIND_MUSHU, CARD_DEF_FLAG_SUMMON, 0, MOVE_MUSHU, 311, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn08Frame0, gCardSmn08Tiles, gMushuPalette, LOCALIZED(gCardNameMushu), gMushuSmallCardFrame0, gMushuSmallCardTiles, gMushuSmallCardPalette,
        CARD_KIND_MUSHU, CARD_DEF_FLAG_SUMMON, 1, MOVE_MUSHU, 311, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn08Frame0, gCardSmn08Tiles, gMushuPalette, LOCALIZED(gCardNameMushu), gMushuSmallCardFrame0, gMushuSmallCardTiles, gMushuSmallCardPalette,
        CARD_KIND_MUSHU, CARD_DEF_FLAG_SUMMON, 2, MOVE_MUSHU, 311, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn08Frame0, gCardSmn08Tiles, gMushuPalette, LOCALIZED(gCardNameMushu), gMushuSmallCardFrame0, gMushuSmallCardTiles, gMushuSmallCardPalette,
        CARD_KIND_MUSHU, CARD_DEF_FLAG_SUMMON, 3, MOVE_MUSHU, 311, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn08Frame0, gCardSmn08Tiles, gMushuPalette, LOCALIZED(gCardNameMushu), gMushuSmallCardFrame0, gMushuSmallCardTiles, gMushuSmallCardPalette,
        CARD_KIND_MUSHU, CARD_DEF_FLAG_SUMMON, 4, MOVE_MUSHU, 311, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn08Frame0, gCardSmn08Tiles, gMushuPalette, LOCALIZED(gCardNameMushu), gMushuSmallCardFrame0, gMushuSmallCardTiles, gMushuSmallCardPalette,
        CARD_KIND_MUSHU, CARD_DEF_FLAG_SUMMON, 5, MOVE_MUSHU, 311, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn08Frame0, gCardSmn08Tiles, gMushuPalette, LOCALIZED(gCardNameMushu), gMushuSmallCardFrame0, gMushuSmallCardTiles, gMushuSmallCardPalette,
        CARD_KIND_MUSHU, CARD_DEF_FLAG_SUMMON, 6, MOVE_MUSHU, 311, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn08Frame0, gCardSmn08Tiles, gMushuPalette, LOCALIZED(gCardNameMushu), gMushuSmallCardFrame0, gMushuSmallCardTiles, gMushuSmallCardPalette,
        CARD_KIND_MUSHU, CARD_DEF_FLAG_SUMMON, 7, MOVE_MUSHU, 311, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn08Frame0, gCardSmn08Tiles, gMushuPalette, LOCALIZED(gCardNameMushu), gMushuSmallCardFrame0, gMushuSmallCardTiles, gMushuSmallCardPalette,
        CARD_KIND_MUSHU, CARD_DEF_FLAG_SUMMON, 8, MOVE_MUSHU, 311, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn08Frame0, gCardSmn08Tiles, gMushuPalette, LOCALIZED(gCardNameMushu), gMushuSmallCardFrame0, gMushuSmallCardTiles, gMushuSmallCardPalette,
        CARD_KIND_MUSHU, CARD_DEF_FLAG_SUMMON, 9, MOVE_MUSHU, 311, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09Palette, LOCALIZED(gCardNameCloud), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudSmallCardPalette,
        CARD_KIND_CLOUD, CARD_DEF_FLAG_SUMMON, 0, MOVE_CLOUD, 321, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09Palette, LOCALIZED(gCardNameCloud), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudSmallCardPalette,
        CARD_KIND_CLOUD, CARD_DEF_FLAG_SUMMON, 1, MOVE_CLOUD, 321, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09Palette, LOCALIZED(gCardNameCloud), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudSmallCardPalette,
        CARD_KIND_CLOUD, CARD_DEF_FLAG_SUMMON, 2, MOVE_CLOUD, 321, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09Palette, LOCALIZED(gCardNameCloud), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudSmallCardPalette,
        CARD_KIND_CLOUD, CARD_DEF_FLAG_SUMMON, 3, MOVE_CLOUD, 321, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09Palette, LOCALIZED(gCardNameCloud), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudSmallCardPalette,
        CARD_KIND_CLOUD, CARD_DEF_FLAG_SUMMON, 4, MOVE_CLOUD, 321, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09Palette, LOCALIZED(gCardNameCloud), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudSmallCardPalette,
        CARD_KIND_CLOUD, CARD_DEF_FLAG_SUMMON, 5, MOVE_CLOUD, 321, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09Palette, LOCALIZED(gCardNameCloud), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudSmallCardPalette,
        CARD_KIND_CLOUD, CARD_DEF_FLAG_SUMMON, 6, MOVE_CLOUD, 321, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09Palette, LOCALIZED(gCardNameCloud), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudSmallCardPalette,
        CARD_KIND_CLOUD, CARD_DEF_FLAG_SUMMON, 7, MOVE_CLOUD, 321, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09Palette, LOCALIZED(gCardNameCloud), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudSmallCardPalette,
        CARD_KIND_CLOUD, CARD_DEF_FLAG_SUMMON, 8, MOVE_CLOUD, 321, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09Palette, LOCALIZED(gCardNameCloud), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudSmallCardPalette,
        CARD_KIND_CLOUD, CARD_DEF_FLAG_SUMMON, 9, MOVE_CLOUD, 321, CARD_CATEGORY_MAGIC, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn10Frame0, gCardSmn10Tiles, gAladdinPalette, LOCALIZED(gCardNameAladdin), gAladdinSmallCardFrame0, gAladdinSmallCardTiles, gAladdinSmallCardPalette,
        CARD_KIND_ALADDIN, CARD_DEF_FLAG_FRIEND, 0, MOVE_ALADDIN, 331, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn10Frame0, gCardSmn10Tiles, gAladdinPalette, LOCALIZED(gCardNameAladdin), gAladdinSmallCardFrame0, gAladdinSmallCardTiles, gAladdinSmallCardPalette,
        CARD_KIND_ALADDIN, CARD_DEF_FLAG_FRIEND, 1, MOVE_ALADDIN, 331, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn10Frame0, gCardSmn10Tiles, gAladdinPalette, LOCALIZED(gCardNameAladdin), gAladdinSmallCardFrame0, gAladdinSmallCardTiles, gAladdinSmallCardPalette,
        CARD_KIND_ALADDIN, CARD_DEF_FLAG_FRIEND, 2, MOVE_ALADDIN, 331, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn10Frame0, gCardSmn10Tiles, gAladdinPalette, LOCALIZED(gCardNameAladdin), gAladdinSmallCardFrame0, gAladdinSmallCardTiles, gAladdinSmallCardPalette,
        CARD_KIND_ALADDIN, CARD_DEF_FLAG_FRIEND, 3, MOVE_ALADDIN, 331, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn10Frame0, gCardSmn10Tiles, gAladdinPalette, LOCALIZED(gCardNameAladdin), gAladdinSmallCardFrame0, gAladdinSmallCardTiles, gAladdinSmallCardPalette,
        CARD_KIND_ALADDIN, CARD_DEF_FLAG_FRIEND, 4, MOVE_ALADDIN, 331, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn10Frame0, gCardSmn10Tiles, gAladdinPalette, LOCALIZED(gCardNameAladdin), gAladdinSmallCardFrame0, gAladdinSmallCardTiles, gAladdinSmallCardPalette,
        CARD_KIND_ALADDIN, CARD_DEF_FLAG_FRIEND, 5, MOVE_ALADDIN, 331, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn10Frame0, gCardSmn10Tiles, gAladdinPalette, LOCALIZED(gCardNameAladdin), gAladdinSmallCardFrame0, gAladdinSmallCardTiles, gAladdinSmallCardPalette,
        CARD_KIND_ALADDIN, CARD_DEF_FLAG_FRIEND, 6, MOVE_ALADDIN, 331, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn10Frame0, gCardSmn10Tiles, gAladdinPalette, LOCALIZED(gCardNameAladdin), gAladdinSmallCardFrame0, gAladdinSmallCardTiles, gAladdinSmallCardPalette,
        CARD_KIND_ALADDIN, CARD_DEF_FLAG_FRIEND, 7, MOVE_ALADDIN, 331, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn10Frame0, gCardSmn10Tiles, gAladdinPalette, LOCALIZED(gCardNameAladdin), gAladdinSmallCardFrame0, gAladdinSmallCardTiles, gAladdinSmallCardPalette,
        CARD_KIND_ALADDIN, CARD_DEF_FLAG_FRIEND, 8, MOVE_ALADDIN, 331, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn10Frame0, gCardSmn10Tiles, gAladdinPalette, LOCALIZED(gCardNameAladdin), gAladdinSmallCardFrame0, gAladdinSmallCardTiles, gAladdinSmallCardPalette,
        CARD_KIND_ALADDIN, CARD_DEF_FLAG_FRIEND, 9, MOVE_ALADDIN, 331, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn11Frame0, gCardSmn11Tiles, gArielPalette, LOCALIZED(gCardNameAriel), gArielSmallCardFrame0, gArielSmallCardTiles, gArielSmallCardPalette,
        CARD_KIND_ARIEL, CARD_DEF_FLAG_FRIEND, 0, MOVE_ARIEL, 341, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn11Frame0, gCardSmn11Tiles, gArielPalette, LOCALIZED(gCardNameAriel), gArielSmallCardFrame0, gArielSmallCardTiles, gArielSmallCardPalette,
        CARD_KIND_ARIEL, CARD_DEF_FLAG_FRIEND, 1, MOVE_ARIEL, 341, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn11Frame0, gCardSmn11Tiles, gArielPalette, LOCALIZED(gCardNameAriel), gArielSmallCardFrame0, gArielSmallCardTiles, gArielSmallCardPalette,
        CARD_KIND_ARIEL, CARD_DEF_FLAG_FRIEND, 2, MOVE_ARIEL, 341, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn11Frame0, gCardSmn11Tiles, gArielPalette, LOCALIZED(gCardNameAriel), gArielSmallCardFrame0, gArielSmallCardTiles, gArielSmallCardPalette,
        CARD_KIND_ARIEL, CARD_DEF_FLAG_FRIEND, 3, MOVE_ARIEL, 341, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn11Frame0, gCardSmn11Tiles, gArielPalette, LOCALIZED(gCardNameAriel), gArielSmallCardFrame0, gArielSmallCardTiles, gArielSmallCardPalette,
        CARD_KIND_ARIEL, CARD_DEF_FLAG_FRIEND, 4, MOVE_ARIEL, 341, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn11Frame0, gCardSmn11Tiles, gArielPalette, LOCALIZED(gCardNameAriel), gArielSmallCardFrame0, gArielSmallCardTiles, gArielSmallCardPalette,
        CARD_KIND_ARIEL, CARD_DEF_FLAG_FRIEND, 5, MOVE_ARIEL, 341, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn11Frame0, gCardSmn11Tiles, gArielPalette, LOCALIZED(gCardNameAriel), gArielSmallCardFrame0, gArielSmallCardTiles, gArielSmallCardPalette,
        CARD_KIND_ARIEL, CARD_DEF_FLAG_FRIEND, 6, MOVE_ARIEL, 341, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn11Frame0, gCardSmn11Tiles, gArielPalette, LOCALIZED(gCardNameAriel), gArielSmallCardFrame0, gArielSmallCardTiles, gArielSmallCardPalette,
        CARD_KIND_ARIEL, CARD_DEF_FLAG_FRIEND, 7, MOVE_ARIEL, 341, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn11Frame0, gCardSmn11Tiles, gArielPalette, LOCALIZED(gCardNameAriel), gArielSmallCardFrame0, gArielSmallCardTiles, gArielSmallCardPalette,
        CARD_KIND_ARIEL, CARD_DEF_FLAG_FRIEND, 8, MOVE_ARIEL, 341, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn11Frame0, gCardSmn11Tiles, gArielPalette, LOCALIZED(gCardNameAriel), gArielSmallCardFrame0, gArielSmallCardTiles, gArielSmallCardPalette,
        CARD_KIND_ARIEL, CARD_DEF_FLAG_FRIEND, 9, MOVE_ARIEL, 341, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn12Frame0, gCardSmn12Tiles, gJackPalette, LOCALIZED(gCardNameJack), gJackSmallCardFrame0, gJackSmallCardTiles, gJackSmallCardPalette,
        CARD_KIND_JACK, CARD_DEF_FLAG_FRIEND, 0, MOVE_JACK, 351, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn12Frame0, gCardSmn12Tiles, gJackPalette, LOCALIZED(gCardNameJack), gJackSmallCardFrame0, gJackSmallCardTiles, gJackSmallCardPalette,
        CARD_KIND_JACK, CARD_DEF_FLAG_FRIEND, 1, MOVE_JACK, 351, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn12Frame0, gCardSmn12Tiles, gJackPalette, LOCALIZED(gCardNameJack), gJackSmallCardFrame0, gJackSmallCardTiles, gJackSmallCardPalette,
        CARD_KIND_JACK, CARD_DEF_FLAG_FRIEND, 2, MOVE_JACK, 351, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn12Frame0, gCardSmn12Tiles, gJackPalette, LOCALIZED(gCardNameJack), gJackSmallCardFrame0, gJackSmallCardTiles, gJackSmallCardPalette,
        CARD_KIND_JACK, CARD_DEF_FLAG_FRIEND, 3, MOVE_JACK, 351, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn12Frame0, gCardSmn12Tiles, gJackPalette, LOCALIZED(gCardNameJack), gJackSmallCardFrame0, gJackSmallCardTiles, gJackSmallCardPalette,
        CARD_KIND_JACK, CARD_DEF_FLAG_FRIEND, 4, MOVE_JACK, 351, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn12Frame0, gCardSmn12Tiles, gJackPalette, LOCALIZED(gCardNameJack), gJackSmallCardFrame0, gJackSmallCardTiles, gJackSmallCardPalette,
        CARD_KIND_JACK, CARD_DEF_FLAG_FRIEND, 5, MOVE_JACK, 351, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn12Frame0, gCardSmn12Tiles, gJackPalette, LOCALIZED(gCardNameJack), gJackSmallCardFrame0, gJackSmallCardTiles, gJackSmallCardPalette,
        CARD_KIND_JACK, CARD_DEF_FLAG_FRIEND, 6, MOVE_JACK, 351, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn12Frame0, gCardSmn12Tiles, gJackPalette, LOCALIZED(gCardNameJack), gJackSmallCardFrame0, gJackSmallCardTiles, gJackSmallCardPalette,
        CARD_KIND_JACK, CARD_DEF_FLAG_FRIEND, 7, MOVE_JACK, 351, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn12Frame0, gCardSmn12Tiles, gJackPalette, LOCALIZED(gCardNameJack), gJackSmallCardFrame0, gJackSmallCardTiles, gJackSmallCardPalette,
        CARD_KIND_JACK, CARD_DEF_FLAG_FRIEND, 8, MOVE_JACK, 351, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn12Frame0, gCardSmn12Tiles, gJackPalette, LOCALIZED(gCardNameJack), gJackSmallCardFrame0, gJackSmallCardTiles, gJackSmallCardPalette,
        CARD_KIND_JACK, CARD_DEF_FLAG_FRIEND, 9, MOVE_JACK, 351, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn13Frame0, gCardSmn13Tiles, gPeterPalette, LOCALIZED(gCardNamePeterPan), gPeterPanSmallCardFrame0, gPeterPanSmallCardTiles, gPeterPanSmallCardPalette,
        CARD_KIND_PETER_PAN, CARD_DEF_FLAG_FRIEND, 0, MOVE_PETER_PAN, 361, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn13Frame0, gCardSmn13Tiles, gPeterPalette, LOCALIZED(gCardNamePeterPan), gPeterPanSmallCardFrame0, gPeterPanSmallCardTiles, gPeterPanSmallCardPalette,
        CARD_KIND_PETER_PAN, CARD_DEF_FLAG_FRIEND, 1, MOVE_PETER_PAN, 361, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn13Frame0, gCardSmn13Tiles, gPeterPalette, LOCALIZED(gCardNamePeterPan), gPeterPanSmallCardFrame0, gPeterPanSmallCardTiles, gPeterPanSmallCardPalette,
        CARD_KIND_PETER_PAN, CARD_DEF_FLAG_FRIEND, 2, MOVE_PETER_PAN, 361, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn13Frame0, gCardSmn13Tiles, gPeterPalette, LOCALIZED(gCardNamePeterPan), gPeterPanSmallCardFrame0, gPeterPanSmallCardTiles, gPeterPanSmallCardPalette,
        CARD_KIND_PETER_PAN, CARD_DEF_FLAG_FRIEND, 3, MOVE_PETER_PAN, 361, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn13Frame0, gCardSmn13Tiles, gPeterPalette, LOCALIZED(gCardNamePeterPan), gPeterPanSmallCardFrame0, gPeterPanSmallCardTiles, gPeterPanSmallCardPalette,
        CARD_KIND_PETER_PAN, CARD_DEF_FLAG_FRIEND, 4, MOVE_PETER_PAN, 361, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn13Frame0, gCardSmn13Tiles, gPeterPalette, LOCALIZED(gCardNamePeterPan), gPeterPanSmallCardFrame0, gPeterPanSmallCardTiles, gPeterPanSmallCardPalette,
        CARD_KIND_PETER_PAN, CARD_DEF_FLAG_FRIEND, 5, MOVE_PETER_PAN, 361, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn13Frame0, gCardSmn13Tiles, gPeterPalette, LOCALIZED(gCardNamePeterPan), gPeterPanSmallCardFrame0, gPeterPanSmallCardTiles, gPeterPanSmallCardPalette,
        CARD_KIND_PETER_PAN, CARD_DEF_FLAG_FRIEND, 6, MOVE_PETER_PAN, 361, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn13Frame0, gCardSmn13Tiles, gPeterPalette, LOCALIZED(gCardNamePeterPan), gPeterPanSmallCardFrame0, gPeterPanSmallCardTiles, gPeterPanSmallCardPalette,
        CARD_KIND_PETER_PAN, CARD_DEF_FLAG_FRIEND, 7, MOVE_PETER_PAN, 361, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn13Frame0, gCardSmn13Tiles, gPeterPalette, LOCALIZED(gCardNamePeterPan), gPeterPanSmallCardFrame0, gPeterPanSmallCardTiles, gPeterPanSmallCardPalette,
        CARD_KIND_PETER_PAN, CARD_DEF_FLAG_FRIEND, 8, MOVE_PETER_PAN, 361, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn13Frame0, gCardSmn13Tiles, gPeterPalette, LOCALIZED(gCardNamePeterPan), gPeterPanSmallCardFrame0, gPeterPanSmallCardTiles, gPeterPanSmallCardPalette,
        CARD_KIND_PETER_PAN, CARD_DEF_FLAG_FRIEND, 9, MOVE_PETER_PAN, 361, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn14Frame0, gCardSmn14Tiles, gBeastPalette, LOCALIZED(gCardNameBeast), gTheBeastSmallCardFrame0, gTheBeastSmallCardTiles, gTheBeastSmallCardPalette,
        CARD_KIND_THE_BEAST, CARD_DEF_FLAG_FRIEND, 0, MOVE_THE_BEAST, 371, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn14Frame0, gCardSmn14Tiles, gBeastPalette, LOCALIZED(gCardNameBeast), gTheBeastSmallCardFrame0, gTheBeastSmallCardTiles, gTheBeastSmallCardPalette,
        CARD_KIND_THE_BEAST, CARD_DEF_FLAG_FRIEND, 1, MOVE_THE_BEAST, 371, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn14Frame0, gCardSmn14Tiles, gBeastPalette, LOCALIZED(gCardNameBeast), gTheBeastSmallCardFrame0, gTheBeastSmallCardTiles, gTheBeastSmallCardPalette,
        CARD_KIND_THE_BEAST, CARD_DEF_FLAG_FRIEND, 2, MOVE_THE_BEAST, 371, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn14Frame0, gCardSmn14Tiles, gBeastPalette, LOCALIZED(gCardNameBeast), gTheBeastSmallCardFrame0, gTheBeastSmallCardTiles, gTheBeastSmallCardPalette,
        CARD_KIND_THE_BEAST, CARD_DEF_FLAG_FRIEND, 3, MOVE_THE_BEAST, 371, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn14Frame0, gCardSmn14Tiles, gBeastPalette, LOCALIZED(gCardNameBeast), gTheBeastSmallCardFrame0, gTheBeastSmallCardTiles, gTheBeastSmallCardPalette,
        CARD_KIND_THE_BEAST, CARD_DEF_FLAG_FRIEND, 4, MOVE_THE_BEAST, 371, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn14Frame0, gCardSmn14Tiles, gBeastPalette, LOCALIZED(gCardNameBeast), gTheBeastSmallCardFrame0, gTheBeastSmallCardTiles, gTheBeastSmallCardPalette,
        CARD_KIND_THE_BEAST, CARD_DEF_FLAG_FRIEND, 5, MOVE_THE_BEAST, 371, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn14Frame0, gCardSmn14Tiles, gBeastPalette, LOCALIZED(gCardNameBeast), gTheBeastSmallCardFrame0, gTheBeastSmallCardTiles, gTheBeastSmallCardPalette,
        CARD_KIND_THE_BEAST, CARD_DEF_FLAG_FRIEND, 6, MOVE_THE_BEAST, 371, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn14Frame0, gCardSmn14Tiles, gBeastPalette, LOCALIZED(gCardNameBeast), gTheBeastSmallCardFrame0, gTheBeastSmallCardTiles, gTheBeastSmallCardPalette,
        CARD_KIND_THE_BEAST, CARD_DEF_FLAG_FRIEND, 7, MOVE_THE_BEAST, 371, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn14Frame0, gCardSmn14Tiles, gBeastPalette, LOCALIZED(gCardNameBeast), gTheBeastSmallCardFrame0, gTheBeastSmallCardTiles, gTheBeastSmallCardPalette,
        CARD_KIND_THE_BEAST, CARD_DEF_FLAG_FRIEND, 8, MOVE_THE_BEAST, 371, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn14Frame0, gCardSmn14Tiles, gBeastPalette, LOCALIZED(gCardNameBeast), gTheBeastSmallCardFrame0, gTheBeastSmallCardTiles, gTheBeastSmallCardPalette,
        CARD_KIND_THE_BEAST, CARD_DEF_FLAG_FRIEND, 9, MOVE_THE_BEAST, 371, CARD_CATEGORY_ITEM, 25, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm01Frame0, gCardItm01Tiles, gCardItm01Palette, LOCALIZED(gCardNamePotion), gPotionSmallCardFrame0, gPotionSmallCardTiles, gPotionSmallCardPalette,
        CARD_KIND_POTION, CARD_DEF_FLAG_ITEM, 0, MOVE_POTION, 381, CARD_CATEGORY_ITEM, 30, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm01Frame0, gCardItm01Tiles, gCardItm01Palette, LOCALIZED(gCardNamePotion), gPotionSmallCardFrame0, gPotionSmallCardTiles, gPotionSmallCardPalette,
        CARD_KIND_POTION, CARD_DEF_FLAG_ITEM, 1, MOVE_POTION, 381, CARD_CATEGORY_ITEM, 30, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm01Frame0, gCardItm01Tiles, gCardItm01Palette, LOCALIZED(gCardNamePotion), gPotionSmallCardFrame0, gPotionSmallCardTiles, gPotionSmallCardPalette,
        CARD_KIND_POTION, CARD_DEF_FLAG_ITEM, 2, MOVE_POTION, 381, CARD_CATEGORY_ITEM, 30, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm01Frame0, gCardItm01Tiles, gCardItm01Palette, LOCALIZED(gCardNamePotion), gPotionSmallCardFrame0, gPotionSmallCardTiles, gPotionSmallCardPalette,
        CARD_KIND_POTION, CARD_DEF_FLAG_ITEM, 3, MOVE_POTION, 381, CARD_CATEGORY_ITEM, 30, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm01Frame0, gCardItm01Tiles, gCardItm01Palette, LOCALIZED(gCardNamePotion), gPotionSmallCardFrame0, gPotionSmallCardTiles, gPotionSmallCardPalette,
        CARD_KIND_POTION, CARD_DEF_FLAG_ITEM, 4, MOVE_POTION, 381, CARD_CATEGORY_ITEM, 30, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm01Frame0, gCardItm01Tiles, gCardItm01Palette, LOCALIZED(gCardNamePotion), gPotionSmallCardFrame0, gPotionSmallCardTiles, gPotionSmallCardPalette,
        CARD_KIND_POTION, CARD_DEF_FLAG_ITEM, 5, MOVE_POTION, 381, CARD_CATEGORY_ITEM, 30, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm01Frame0, gCardItm01Tiles, gCardItm01Palette, LOCALIZED(gCardNamePotion), gPotionSmallCardFrame0, gPotionSmallCardTiles, gPotionSmallCardPalette,
        CARD_KIND_POTION, CARD_DEF_FLAG_ITEM, 6, MOVE_POTION, 381, CARD_CATEGORY_ITEM, 30, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm01Frame0, gCardItm01Tiles, gCardItm01Palette, LOCALIZED(gCardNamePotion), gPotionSmallCardFrame0, gPotionSmallCardTiles, gPotionSmallCardPalette,
        CARD_KIND_POTION, CARD_DEF_FLAG_ITEM, 7, MOVE_POTION, 381, CARD_CATEGORY_ITEM, 30, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm01Frame0, gCardItm01Tiles, gCardItm01Palette, LOCALIZED(gCardNamePotion), gPotionSmallCardFrame0, gPotionSmallCardTiles, gPotionSmallCardPalette,
        CARD_KIND_POTION, CARD_DEF_FLAG_ITEM, 8, MOVE_POTION, 381, CARD_CATEGORY_ITEM, 30, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm01Frame0, gCardItm01Tiles, gCardItm01Palette, LOCALIZED(gCardNamePotion), gPotionSmallCardFrame0, gPotionSmallCardTiles, gPotionSmallCardPalette,
        CARD_KIND_POTION, CARD_DEF_FLAG_ITEM, 9, MOVE_POTION, 381, CARD_CATEGORY_ITEM, 30, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm02Frame0, gCardItm02Tiles, gCardItm02Palette, LOCALIZED(gCardNameHiPotion), gHiPotionSmallCardFrame0, gHiPotionSmallCardTiles, gHiPotionSmallCardPalette,
        CARD_KIND_HI_POTION, CARD_DEF_FLAG_ITEM, 0, MOVE_HI_POTION, 391, CARD_CATEGORY_ITEM, 40, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm02Frame0, gCardItm02Tiles, gCardItm02Palette, LOCALIZED(gCardNameHiPotion), gHiPotionSmallCardFrame0, gHiPotionSmallCardTiles, gHiPotionSmallCardPalette,
        CARD_KIND_HI_POTION, CARD_DEF_FLAG_ITEM, 1, MOVE_HI_POTION, 391, CARD_CATEGORY_ITEM, 40, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm02Frame0, gCardItm02Tiles, gCardItm02Palette, LOCALIZED(gCardNameHiPotion), gHiPotionSmallCardFrame0, gHiPotionSmallCardTiles, gHiPotionSmallCardPalette,
        CARD_KIND_HI_POTION, CARD_DEF_FLAG_ITEM, 2, MOVE_HI_POTION, 391, CARD_CATEGORY_ITEM, 40, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm02Frame0, gCardItm02Tiles, gCardItm02Palette, LOCALIZED(gCardNameHiPotion), gHiPotionSmallCardFrame0, gHiPotionSmallCardTiles, gHiPotionSmallCardPalette,
        CARD_KIND_HI_POTION, CARD_DEF_FLAG_ITEM, 3, MOVE_HI_POTION, 391, CARD_CATEGORY_ITEM, 40, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm02Frame0, gCardItm02Tiles, gCardItm02Palette, LOCALIZED(gCardNameHiPotion), gHiPotionSmallCardFrame0, gHiPotionSmallCardTiles, gHiPotionSmallCardPalette,
        CARD_KIND_HI_POTION, CARD_DEF_FLAG_ITEM, 4, MOVE_HI_POTION, 391, CARD_CATEGORY_ITEM, 40, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm02Frame0, gCardItm02Tiles, gCardItm02Palette, LOCALIZED(gCardNameHiPotion), gHiPotionSmallCardFrame0, gHiPotionSmallCardTiles, gHiPotionSmallCardPalette,
        CARD_KIND_HI_POTION, CARD_DEF_FLAG_ITEM, 5, MOVE_HI_POTION, 391, CARD_CATEGORY_ITEM, 40, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm02Frame0, gCardItm02Tiles, gCardItm02Palette, LOCALIZED(gCardNameHiPotion), gHiPotionSmallCardFrame0, gHiPotionSmallCardTiles, gHiPotionSmallCardPalette,
        CARD_KIND_HI_POTION, CARD_DEF_FLAG_ITEM, 6, MOVE_HI_POTION, 391, CARD_CATEGORY_ITEM, 40, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm02Frame0, gCardItm02Tiles, gCardItm02Palette, LOCALIZED(gCardNameHiPotion), gHiPotionSmallCardFrame0, gHiPotionSmallCardTiles, gHiPotionSmallCardPalette,
        CARD_KIND_HI_POTION, CARD_DEF_FLAG_ITEM, 7, MOVE_HI_POTION, 391, CARD_CATEGORY_ITEM, 40, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm02Frame0, gCardItm02Tiles, gCardItm02Palette, LOCALIZED(gCardNameHiPotion), gHiPotionSmallCardFrame0, gHiPotionSmallCardTiles, gHiPotionSmallCardPalette,
        CARD_KIND_HI_POTION, CARD_DEF_FLAG_ITEM, 8, MOVE_HI_POTION, 391, CARD_CATEGORY_ITEM, 40, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm02Frame0, gCardItm02Tiles, gCardItm02Palette, LOCALIZED(gCardNameHiPotion), gHiPotionSmallCardFrame0, gHiPotionSmallCardTiles, gHiPotionSmallCardPalette,
        CARD_KIND_HI_POTION, CARD_DEF_FLAG_ITEM, 9, MOVE_HI_POTION, 391, CARD_CATEGORY_ITEM, 40, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm03Frame0, gCardItm03Tiles, gCardItm03Palette, LOCALIZED(gCardNameMegaPotion), gMegaPotionSmallCardFrame0, gMegaPotionSmallCardTiles, gMegaPotionSmallCardPalette,
        CARD_KIND_MEGA_POTION, CARD_DEF_FLAG_ITEM, 0, MOVE_MEGA_POTION, 401, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm03Frame0, gCardItm03Tiles, gCardItm03Palette, LOCALIZED(gCardNameMegaPotion), gMegaPotionSmallCardFrame0, gMegaPotionSmallCardTiles, gMegaPotionSmallCardPalette,
        CARD_KIND_MEGA_POTION, CARD_DEF_FLAG_ITEM, 1, MOVE_MEGA_POTION, 401, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm03Frame0, gCardItm03Tiles, gCardItm03Palette, LOCALIZED(gCardNameMegaPotion), gMegaPotionSmallCardFrame0, gMegaPotionSmallCardTiles, gMegaPotionSmallCardPalette,
        CARD_KIND_MEGA_POTION, CARD_DEF_FLAG_ITEM, 2, MOVE_MEGA_POTION, 401, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm03Frame0, gCardItm03Tiles, gCardItm03Palette, LOCALIZED(gCardNameMegaPotion), gMegaPotionSmallCardFrame0, gMegaPotionSmallCardTiles, gMegaPotionSmallCardPalette,
        CARD_KIND_MEGA_POTION, CARD_DEF_FLAG_ITEM, 3, MOVE_MEGA_POTION, 401, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm03Frame0, gCardItm03Tiles, gCardItm03Palette, LOCALIZED(gCardNameMegaPotion), gMegaPotionSmallCardFrame0, gMegaPotionSmallCardTiles, gMegaPotionSmallCardPalette,
        CARD_KIND_MEGA_POTION, CARD_DEF_FLAG_ITEM, 4, MOVE_MEGA_POTION, 401, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm03Frame0, gCardItm03Tiles, gCardItm03Palette, LOCALIZED(gCardNameMegaPotion), gMegaPotionSmallCardFrame0, gMegaPotionSmallCardTiles, gMegaPotionSmallCardPalette,
        CARD_KIND_MEGA_POTION, CARD_DEF_FLAG_ITEM, 5, MOVE_MEGA_POTION, 401, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm03Frame0, gCardItm03Tiles, gCardItm03Palette, LOCALIZED(gCardNameMegaPotion), gMegaPotionSmallCardFrame0, gMegaPotionSmallCardTiles, gMegaPotionSmallCardPalette,
        CARD_KIND_MEGA_POTION, CARD_DEF_FLAG_ITEM, 6, MOVE_MEGA_POTION, 401, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm03Frame0, gCardItm03Tiles, gCardItm03Palette, LOCALIZED(gCardNameMegaPotion), gMegaPotionSmallCardFrame0, gMegaPotionSmallCardTiles, gMegaPotionSmallCardPalette,
        CARD_KIND_MEGA_POTION, CARD_DEF_FLAG_ITEM, 7, MOVE_MEGA_POTION, 401, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm03Frame0, gCardItm03Tiles, gCardItm03Palette, LOCALIZED(gCardNameMegaPotion), gMegaPotionSmallCardFrame0, gMegaPotionSmallCardTiles, gMegaPotionSmallCardPalette,
        CARD_KIND_MEGA_POTION, CARD_DEF_FLAG_ITEM, 8, MOVE_MEGA_POTION, 401, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm03Frame0, gCardItm03Tiles, gCardItm03Palette, LOCALIZED(gCardNameMegaPotion), gMegaPotionSmallCardFrame0, gMegaPotionSmallCardTiles, gMegaPotionSmallCardPalette,
        CARD_KIND_MEGA_POTION, CARD_DEF_FLAG_ITEM, 9, MOVE_MEGA_POTION, 401, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm04Frame0, gCardItm04Tiles, gCardItm04Palette, LOCALIZED(gCardNameEther), gEtherSmallCardFrame0, gEtherSmallCardTiles, gEtherSmallCardPalette,
        CARD_KIND_ETHER, CARD_DEF_FLAG_ITEM, 0, MOVE_ETHER, 411, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm04Frame0, gCardItm04Tiles, gCardItm04Palette, LOCALIZED(gCardNameEther), gEtherSmallCardFrame0, gEtherSmallCardTiles, gEtherSmallCardPalette,
        CARD_KIND_ETHER, CARD_DEF_FLAG_ITEM, 1, MOVE_ETHER, 411, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm04Frame0, gCardItm04Tiles, gCardItm04Palette, LOCALIZED(gCardNameEther), gEtherSmallCardFrame0, gEtherSmallCardTiles, gEtherSmallCardPalette,
        CARD_KIND_ETHER, CARD_DEF_FLAG_ITEM, 2, MOVE_ETHER, 411, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm04Frame0, gCardItm04Tiles, gCardItm04Palette, LOCALIZED(gCardNameEther), gEtherSmallCardFrame0, gEtherSmallCardTiles, gEtherSmallCardPalette,
        CARD_KIND_ETHER, CARD_DEF_FLAG_ITEM, 3, MOVE_ETHER, 411, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm04Frame0, gCardItm04Tiles, gCardItm04Palette, LOCALIZED(gCardNameEther), gEtherSmallCardFrame0, gEtherSmallCardTiles, gEtherSmallCardPalette,
        CARD_KIND_ETHER, CARD_DEF_FLAG_ITEM, 4, MOVE_ETHER, 411, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm04Frame0, gCardItm04Tiles, gCardItm04Palette, LOCALIZED(gCardNameEther), gEtherSmallCardFrame0, gEtherSmallCardTiles, gEtherSmallCardPalette,
        CARD_KIND_ETHER, CARD_DEF_FLAG_ITEM, 5, MOVE_ETHER, 411, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm04Frame0, gCardItm04Tiles, gCardItm04Palette, LOCALIZED(gCardNameEther), gEtherSmallCardFrame0, gEtherSmallCardTiles, gEtherSmallCardPalette,
        CARD_KIND_ETHER, CARD_DEF_FLAG_ITEM, 6, MOVE_ETHER, 411, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm04Frame0, gCardItm04Tiles, gCardItm04Palette, LOCALIZED(gCardNameEther), gEtherSmallCardFrame0, gEtherSmallCardTiles, gEtherSmallCardPalette,
        CARD_KIND_ETHER, CARD_DEF_FLAG_ITEM, 7, MOVE_ETHER, 411, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm04Frame0, gCardItm04Tiles, gCardItm04Palette, LOCALIZED(gCardNameEther), gEtherSmallCardFrame0, gEtherSmallCardTiles, gEtherSmallCardPalette,
        CARD_KIND_ETHER, CARD_DEF_FLAG_ITEM, 8, MOVE_ETHER, 411, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm04Frame0, gCardItm04Tiles, gCardItm04Palette, LOCALIZED(gCardNameEther), gEtherSmallCardFrame0, gEtherSmallCardTiles, gEtherSmallCardPalette,
        CARD_KIND_ETHER, CARD_DEF_FLAG_ITEM, 9, MOVE_ETHER, 411, CARD_CATEGORY_ITEM, 20, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm05Frame0, gCardItm05Tiles, gCardItm05Palette, LOCALIZED(gCardNameMegaEther), gMegaEtherSmallCardFrame0, gMegaEtherSmallCardTiles, gMegaEtherSmallCardPalette,
        CARD_KIND_MEGA_ETHER, CARD_DEF_FLAG_ITEM, 0, MOVE_MEGA_ETHER, 421, CARD_CATEGORY_ITEM, 35, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm05Frame0, gCardItm05Tiles, gCardItm05Palette, LOCALIZED(gCardNameMegaEther), gMegaEtherSmallCardFrame0, gMegaEtherSmallCardTiles, gMegaEtherSmallCardPalette,
        CARD_KIND_MEGA_ETHER, CARD_DEF_FLAG_ITEM, 1, MOVE_MEGA_ETHER, 421, CARD_CATEGORY_ITEM, 35, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm05Frame0, gCardItm05Tiles, gCardItm05Palette, LOCALIZED(gCardNameMegaEther), gMegaEtherSmallCardFrame0, gMegaEtherSmallCardTiles, gMegaEtherSmallCardPalette,
        CARD_KIND_MEGA_ETHER, CARD_DEF_FLAG_ITEM, 2, MOVE_MEGA_ETHER, 421, CARD_CATEGORY_ITEM, 35, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm05Frame0, gCardItm05Tiles, gCardItm05Palette, LOCALIZED(gCardNameMegaEther), gMegaEtherSmallCardFrame0, gMegaEtherSmallCardTiles, gMegaEtherSmallCardPalette,
        CARD_KIND_MEGA_ETHER, CARD_DEF_FLAG_ITEM, 3, MOVE_MEGA_ETHER, 421, CARD_CATEGORY_ITEM, 35, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm05Frame0, gCardItm05Tiles, gCardItm05Palette, LOCALIZED(gCardNameMegaEther), gMegaEtherSmallCardFrame0, gMegaEtherSmallCardTiles, gMegaEtherSmallCardPalette,
        CARD_KIND_MEGA_ETHER, CARD_DEF_FLAG_ITEM, 4, MOVE_MEGA_ETHER, 421, CARD_CATEGORY_ITEM, 35, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm05Frame0, gCardItm05Tiles, gCardItm05Palette, LOCALIZED(gCardNameMegaEther), gMegaEtherSmallCardFrame0, gMegaEtherSmallCardTiles, gMegaEtherSmallCardPalette,
        CARD_KIND_MEGA_ETHER, CARD_DEF_FLAG_ITEM, 5, MOVE_MEGA_ETHER, 421, CARD_CATEGORY_ITEM, 35, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm05Frame0, gCardItm05Tiles, gCardItm05Palette, LOCALIZED(gCardNameMegaEther), gMegaEtherSmallCardFrame0, gMegaEtherSmallCardTiles, gMegaEtherSmallCardPalette,
        CARD_KIND_MEGA_ETHER, CARD_DEF_FLAG_ITEM, 6, MOVE_MEGA_ETHER, 421, CARD_CATEGORY_ITEM, 35, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm05Frame0, gCardItm05Tiles, gCardItm05Palette, LOCALIZED(gCardNameMegaEther), gMegaEtherSmallCardFrame0, gMegaEtherSmallCardTiles, gMegaEtherSmallCardPalette,
        CARD_KIND_MEGA_ETHER, CARD_DEF_FLAG_ITEM, 7, MOVE_MEGA_ETHER, 421, CARD_CATEGORY_ITEM, 35, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm05Frame0, gCardItm05Tiles, gCardItm05Palette, LOCALIZED(gCardNameMegaEther), gMegaEtherSmallCardFrame0, gMegaEtherSmallCardTiles, gMegaEtherSmallCardPalette,
        CARD_KIND_MEGA_ETHER, CARD_DEF_FLAG_ITEM, 8, MOVE_MEGA_ETHER, 421, CARD_CATEGORY_ITEM, 35, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm05Frame0, gCardItm05Tiles, gCardItm05Palette, LOCALIZED(gCardNameMegaEther), gMegaEtherSmallCardFrame0, gMegaEtherSmallCardTiles, gMegaEtherSmallCardPalette,
        CARD_KIND_MEGA_ETHER, CARD_DEF_FLAG_ITEM, 9, MOVE_MEGA_ETHER, 421, CARD_CATEGORY_ITEM, 35, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm06Frame0, gCardItm06Tiles, gCardItm06Palette, LOCALIZED(gCardNameElixir), gElixirSmallCardFrame0, gElixirSmallCardTiles, gElixirSmallCardPalette,
        CARD_KIND_ELIXIR, CARD_DEF_FLAG_ITEM, 0, MOVE_ELIXIR, 431, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm06Frame0, gCardItm06Tiles, gCardItm06Palette, LOCALIZED(gCardNameElixir), gElixirSmallCardFrame0, gElixirSmallCardTiles, gElixirSmallCardPalette,
        CARD_KIND_ELIXIR, CARD_DEF_FLAG_ITEM, 1, MOVE_ELIXIR, 431, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm06Frame0, gCardItm06Tiles, gCardItm06Palette, LOCALIZED(gCardNameElixir), gElixirSmallCardFrame0, gElixirSmallCardTiles, gElixirSmallCardPalette,
        CARD_KIND_ELIXIR, CARD_DEF_FLAG_ITEM, 2, MOVE_ELIXIR, 431, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm06Frame0, gCardItm06Tiles, gCardItm06Palette, LOCALIZED(gCardNameElixir), gElixirSmallCardFrame0, gElixirSmallCardTiles, gElixirSmallCardPalette,
        CARD_KIND_ELIXIR, CARD_DEF_FLAG_ITEM, 3, MOVE_ELIXIR, 431, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm06Frame0, gCardItm06Tiles, gCardItm06Palette, LOCALIZED(gCardNameElixir), gElixirSmallCardFrame0, gElixirSmallCardTiles, gElixirSmallCardPalette,
        CARD_KIND_ELIXIR, CARD_DEF_FLAG_ITEM, 4, MOVE_ELIXIR, 431, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm06Frame0, gCardItm06Tiles, gCardItm06Palette, LOCALIZED(gCardNameElixir), gElixirSmallCardFrame0, gElixirSmallCardTiles, gElixirSmallCardPalette,
        CARD_KIND_ELIXIR, CARD_DEF_FLAG_ITEM, 5, MOVE_ELIXIR, 431, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm06Frame0, gCardItm06Tiles, gCardItm06Palette, LOCALIZED(gCardNameElixir), gElixirSmallCardFrame0, gElixirSmallCardTiles, gElixirSmallCardPalette,
        CARD_KIND_ELIXIR, CARD_DEF_FLAG_ITEM, 6, MOVE_ELIXIR, 431, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm06Frame0, gCardItm06Tiles, gCardItm06Palette, LOCALIZED(gCardNameElixir), gElixirSmallCardFrame0, gElixirSmallCardTiles, gElixirSmallCardPalette,
        CARD_KIND_ELIXIR, CARD_DEF_FLAG_ITEM, 7, MOVE_ELIXIR, 431, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm06Frame0, gCardItm06Tiles, gCardItm06Palette, LOCALIZED(gCardNameElixir), gElixirSmallCardFrame0, gElixirSmallCardTiles, gElixirSmallCardPalette,
        CARD_KIND_ELIXIR, CARD_DEF_FLAG_ITEM, 8, MOVE_ELIXIR, 431, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm06Frame0, gCardItm06Tiles, gCardItm06Palette, LOCALIZED(gCardNameElixir), gElixirSmallCardFrame0, gElixirSmallCardTiles, gElixirSmallCardPalette,
        CARD_KIND_ELIXIR, CARD_DEF_FLAG_ITEM, 9, MOVE_ELIXIR, 431, CARD_CATEGORY_ITEM, 45, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm07Frame0, gCardItm07Tiles, gCardItm07Palette, LOCALIZED(gCardNameMegalixir), gMegalixirSmallCardFrame0, gMegalixirSmallCardTiles, gMegalixirSmallCardPalette,
        CARD_KIND_MEGALIXIR, CARD_DEF_FLAG_ITEM, 0, MOVE_MEGALIXIR, 441, CARD_CATEGORY_ITEM, 50, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm07Frame0, gCardItm07Tiles, gCardItm07Palette, LOCALIZED(gCardNameMegalixir), gMegalixirSmallCardFrame0, gMegalixirSmallCardTiles, gMegalixirSmallCardPalette,
        CARD_KIND_MEGALIXIR, CARD_DEF_FLAG_ITEM, 1, MOVE_MEGALIXIR, 441, CARD_CATEGORY_ITEM, 50, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm07Frame0, gCardItm07Tiles, gCardItm07Palette, LOCALIZED(gCardNameMegalixir), gMegalixirSmallCardFrame0, gMegalixirSmallCardTiles, gMegalixirSmallCardPalette,
        CARD_KIND_MEGALIXIR, CARD_DEF_FLAG_ITEM, 2, MOVE_MEGALIXIR, 441, CARD_CATEGORY_ITEM, 50, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm07Frame0, gCardItm07Tiles, gCardItm07Palette, LOCALIZED(gCardNameMegalixir), gMegalixirSmallCardFrame0, gMegalixirSmallCardTiles, gMegalixirSmallCardPalette,
        CARD_KIND_MEGALIXIR, CARD_DEF_FLAG_ITEM, 3, MOVE_MEGALIXIR, 441, CARD_CATEGORY_ITEM, 50, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm07Frame0, gCardItm07Tiles, gCardItm07Palette, LOCALIZED(gCardNameMegalixir), gMegalixirSmallCardFrame0, gMegalixirSmallCardTiles, gMegalixirSmallCardPalette,
        CARD_KIND_MEGALIXIR, CARD_DEF_FLAG_ITEM, 4, MOVE_MEGALIXIR, 441, CARD_CATEGORY_ITEM, 50, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm07Frame0, gCardItm07Tiles, gCardItm07Palette, LOCALIZED(gCardNameMegalixir), gMegalixirSmallCardFrame0, gMegalixirSmallCardTiles, gMegalixirSmallCardPalette,
        CARD_KIND_MEGALIXIR, CARD_DEF_FLAG_ITEM, 5, MOVE_MEGALIXIR, 441, CARD_CATEGORY_ITEM, 50, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm07Frame0, gCardItm07Tiles, gCardItm07Palette, LOCALIZED(gCardNameMegalixir), gMegalixirSmallCardFrame0, gMegalixirSmallCardTiles, gMegalixirSmallCardPalette,
        CARD_KIND_MEGALIXIR, CARD_DEF_FLAG_ITEM, 6, MOVE_MEGALIXIR, 441, CARD_CATEGORY_ITEM, 50, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm07Frame0, gCardItm07Tiles, gCardItm07Palette, LOCALIZED(gCardNameMegalixir), gMegalixirSmallCardFrame0, gMegalixirSmallCardTiles, gMegalixirSmallCardPalette,
        CARD_KIND_MEGALIXIR, CARD_DEF_FLAG_ITEM, 7, MOVE_MEGALIXIR, 441, CARD_CATEGORY_ITEM, 50, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm07Frame0, gCardItm07Tiles, gCardItm07Palette, LOCALIZED(gCardNameMegalixir), gMegalixirSmallCardFrame0, gMegalixirSmallCardTiles, gMegalixirSmallCardPalette,
        CARD_KIND_MEGALIXIR, CARD_DEF_FLAG_ITEM, 8, MOVE_MEGALIXIR, 441, CARD_CATEGORY_ITEM, 50, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardItm07Frame0, gCardItm07Tiles, gCardItm07Palette, LOCALIZED(gCardNameMegalixir), gMegalixirSmallCardFrame0, gMegalixirSmallCardTiles, gMegalixirSmallCardPalette,
        CARD_KIND_MEGALIXIR, CARD_DEF_FLAG_ITEM, 9, MOVE_MEGALIXIR, 441, CARD_CATEGORY_ITEM, 50, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy00Frame0, gCardEmy00Tiles, gEmy00Palette, LOCALIZED(gEnemyNameShadow), gShadowSmallCardFrame0, gShadowSmallCardTiles, gShadowSmallCardPalette,
        CARD_KIND_SHADOW, 0x0, 1, HC_EFFECT_INCREMENTOR, 450, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy00Frame0, gCardEmy00Tiles, gEmy00Palette, LOCALIZED(gEnemyNameShadow), gShadowSmallCardFrame0, gShadowSmallCardTiles, gShadowSmallCardPalette,
        CARD_KIND_SHADOW, 0x0, 1, HC_EFFECT_INCREMENTOR, 450, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy00Frame0, gCardEmy00Tiles, gEmy00Palette, LOCALIZED(gEnemyNameShadow), gShadowSmallCardFrame0, gShadowSmallCardTiles, gShadowSmallCardPalette,
        CARD_KIND_SHADOW, 0x0, 1, HC_EFFECT_INCREMENTOR, 450, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy14Frame0, gCardEmy14Tiles, gEmy14Palette, LOCALIZED(gEnemyNameSoldier), gSoldierSmallCardFrame0, gSoldierSmallCardTiles, gSoldierSmallCardPalette,
        CARD_KIND_SOLDIER, 0x0, 1, HC_EFFECT_COMBO_PLUS, 453, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy14Frame0, gCardEmy14Tiles, gEmy14Palette, LOCALIZED(gEnemyNameSoldier), gSoldierSmallCardFrame0, gSoldierSmallCardTiles, gSoldierSmallCardPalette,
        CARD_KIND_SOLDIER, 0x0, 2, HC_EFFECT_COMBO_PLUS, 453, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy14Frame0, gCardEmy14Tiles, gEmy14Palette, LOCALIZED(gEnemyNameSoldier), gSoldierSmallCardFrame0, gSoldierSmallCardTiles, gSoldierSmallCardPalette,
        CARD_KIND_SOLDIER, 0x0, 2, HC_EFFECT_COMBO_PLUS, 453, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy38Frame0, gCardEmy38Tiles, gEmy38Palette, LOCALIZED(gEnemyNameLargeBody), gLargeBodySmallCardFrame0, gLargeBodySmallCardTiles, gLargeBodySmallCardPalette,
        CARD_KIND_LARGE_BODY, 0x0, 1, HC_EFFECT_GUARD, 456, CARD_CATEGORY_ENEMY, 40, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy38Frame0, gCardEmy38Tiles, gEmy38Palette, LOCALIZED(gEnemyNameLargeBody), gLargeBodySmallCardFrame0, gLargeBodySmallCardTiles, gLargeBodySmallCardPalette,
        CARD_KIND_LARGE_BODY, 0x0, 3, HC_EFFECT_GUARD, 456, CARD_CATEGORY_ENEMY, 40, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy38Frame0, gCardEmy38Tiles, gEmy38Palette, LOCALIZED(gEnemyNameLargeBody), gLargeBodySmallCardFrame0, gLargeBodySmallCardTiles, gLargeBodySmallCardPalette,
        CARD_KIND_LARGE_BODY, 0x0, 4, HC_EFFECT_GUARD, 456, CARD_CATEGORY_ENEMY, 40, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy01Frame0, gCardEmy01Tiles, gEmy01Palette, LOCALIZED(gEnemyNameRedNocturne), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gRedNocturneSmallCardPalette,
        CARD_KIND_RED_NOCTURNE, 0x0, 1, HC_EFFECT_FIRE_BOOST, 459, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy01Frame0, gCardEmy01Tiles, gEmy01Palette, LOCALIZED(gEnemyNameRedNocturne), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gRedNocturneSmallCardPalette,
        CARD_KIND_RED_NOCTURNE, 0x0, 2, HC_EFFECT_FIRE_BOOST, 459, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy01Frame0, gCardEmy01Tiles, gEmy01Palette, LOCALIZED(gEnemyNameRedNocturne), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gRedNocturneSmallCardPalette,
        CARD_KIND_RED_NOCTURNE, 0x0, 4, HC_EFFECT_FIRE_BOOST, 459, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gBlueRhapsodyCardFrame0, gBlueRhapsodyCardTiles, gEmy02Palette, LOCALIZED(gEnemyNameBlueRhapsody), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gBlueRhapsodySmallCardPalette,
        CARD_KIND_BLUE_RHAPSODY, 0x0, 1, HC_EFFECT_BLIZZARD_BOOST, 463, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gBlueRhapsodyCardFrame0, gBlueRhapsodyCardTiles, gEmy02Palette, LOCALIZED(gEnemyNameBlueRhapsody), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gBlueRhapsodySmallCardPalette,
        CARD_KIND_BLUE_RHAPSODY, 0x0, 2, HC_EFFECT_BLIZZARD_BOOST, 463, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gBlueRhapsodyCardFrame0, gBlueRhapsodyCardTiles, gEmy02Palette, LOCALIZED(gEnemyNameBlueRhapsody), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gBlueRhapsodySmallCardPalette,
        CARD_KIND_BLUE_RHAPSODY, 0x0, 4, HC_EFFECT_BLIZZARD_BOOST, 463, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gYellowOperaCardFrame0, gYellowOperaCardTiles, gEmy03Palette, LOCALIZED(gEnemyNameYellowOpera), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gYellowOperaSmallCardPalette,
        CARD_KIND_YELLOW_OPERA, 0x0, 1, HC_EFFECT_THUNDER_BOOST, 466, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gYellowOperaCardFrame0, gYellowOperaCardTiles, gEmy03Palette, LOCALIZED(gEnemyNameYellowOpera), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gYellowOperaSmallCardPalette,
        CARD_KIND_YELLOW_OPERA, 0x0, 2, HC_EFFECT_THUNDER_BOOST, 466, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gYellowOperaCardFrame0, gYellowOperaCardTiles, gEmy03Palette, LOCALIZED(gEnemyNameYellowOpera), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gYellowOperaSmallCardPalette,
        CARD_KIND_YELLOW_OPERA, 0x0, 4, HC_EFFECT_THUNDER_BOOST, 466, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gGreenRequiemCardFrame0, gGreenRequiemCardTiles, gEmy04Palette, LOCALIZED(gEnemyNameGreenRequiem), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gGreenRequiemSmallCardPalette,
        CARD_KIND_GREEN_REQUIEM, 0x0, 1, HC_EFFECT_CURE_BOOST, 469, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gGreenRequiemCardFrame0, gGreenRequiemCardTiles, gEmy04Palette, LOCALIZED(gEnemyNameGreenRequiem), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gGreenRequiemSmallCardPalette,
        CARD_KIND_GREEN_REQUIEM, 0x0, 2, HC_EFFECT_CURE_BOOST, 469, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gGreenRequiemCardFrame0, gGreenRequiemCardTiles, gEmy04Palette, LOCALIZED(gEnemyNameGreenRequiem), gRedNocturneSmallCardFrame0, gRedNocturneSmallCardTiles, gGreenRequiemSmallCardPalette,
        CARD_KIND_GREEN_REQUIEM, 0x0, 4, HC_EFFECT_CURE_BOOST, 469, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy15Frame0, gCardEmy15Tiles, gEmy15Palette, LOCALIZED(gEnemyNamePowerwild), gPowerwildSmallCardFrame0, gPowerwildSmallCardTiles, gPowerwildSmallCardPalette,
        CARD_KIND_POWERWILD, 0x0, 3, HC_EFFECT_RETROGRADE, 471, CARD_CATEGORY_ENEMY, 40, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy15Frame0, gCardEmy15Tiles, gEmy15Palette, LOCALIZED(gEnemyNamePowerwild), gPowerwildSmallCardFrame0, gPowerwildSmallCardTiles, gPowerwildSmallCardPalette,
        CARD_KIND_POWERWILD, 0x0, 3, HC_EFFECT_RETROGRADE, 471, CARD_CATEGORY_ENEMY, 40, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy15Frame0, gCardEmy15Tiles, gEmy15Palette, LOCALIZED(gEnemyNamePowerwild), gPowerwildSmallCardFrame0, gPowerwildSmallCardTiles, gPowerwildSmallCardPalette,
        CARD_KIND_POWERWILD, 0x0, 3, HC_EFFECT_RETROGRADE, 471, CARD_CATEGORY_ENEMY, 40, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy16Frame0, gCardEmy16Tiles, gEmy16Palette, LOCALIZED(gEnemyNameBouncywild), gBouncywildSmallCardFrame0, gBouncywildSmallCardTiles, gBouncywildSmallCardPalette,
        CARD_KIND_BOUNCYWILD, 0x0, 2, HC_EFFECT_DRAW, 474, CARD_CATEGORY_ENEMY, 10, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy16Frame0, gCardEmy16Tiles, gEmy16Palette, LOCALIZED(gEnemyNameBouncywild), gBouncywildSmallCardFrame0, gBouncywildSmallCardTiles, gBouncywildSmallCardPalette,
        CARD_KIND_BOUNCYWILD, 0x0, 2, HC_EFFECT_DRAW, 474, CARD_CATEGORY_ENEMY, 10, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy16Frame0, gCardEmy16Tiles, gEmy16Palette, LOCALIZED(gEnemyNameBouncywild), gBouncywildSmallCardFrame0, gBouncywildSmallCardTiles, gBouncywildSmallCardPalette,
        CARD_KIND_BOUNCYWILD, 0x0, 2, HC_EFFECT_DRAW, 474, CARD_CATEGORY_ENEMY, 10, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy18Frame0, gCardEmy18Tiles, gEmy18Palette, LOCALIZED(gEnemyNameAirSoldier), gAirSoldierSmallCardFrame0, gAirSoldierSmallCardTiles, gAirSoldierSmallCardPalette,
        CARD_KIND_AIR_SOLDIER, 0x0, 3, HC_EFFECT_RELOAD_KINESIS, 477, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy18Frame0, gCardEmy18Tiles, gEmy18Palette, LOCALIZED(gEnemyNameAirSoldier), gAirSoldierSmallCardFrame0, gAirSoldierSmallCardTiles, gAirSoldierSmallCardPalette,
        CARD_KIND_AIR_SOLDIER, 0x0, 4, HC_EFFECT_RELOAD_KINESIS, 477, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy18Frame0, gCardEmy18Tiles, gEmy18Palette, LOCALIZED(gEnemyNameAirSoldier), gAirSoldierSmallCardFrame0, gAirSoldierSmallCardTiles, gAirSoldierSmallCardPalette,
        CARD_KIND_AIR_SOLDIER, 0x0, 4, HC_EFFECT_RELOAD_KINESIS, 477, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy19Frame0, gCardEmy19Tiles, gEmy19Palette, LOCALIZED(gEnemyNameBandit), gBanditSmallCardFrame0, gBanditSmallCardTiles, gBanditSmallCardPalette,
        CARD_KIND_BANDIT, 0x0, 1, HC_EFFECT_COMBO_FINISH, 480, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy19Frame0, gCardEmy19Tiles, gEmy19Palette, LOCALIZED(gEnemyNameBandit), gBanditSmallCardFrame0, gBanditSmallCardTiles, gBanditSmallCardPalette,
        CARD_KIND_BANDIT, 0x0, 2, HC_EFFECT_COMBO_FINISH, 480, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy19Frame0, gCardEmy19Tiles, gEmy19Palette, LOCALIZED(gEnemyNameBandit), gBanditSmallCardFrame0, gBanditSmallCardTiles, gBanditSmallCardPalette,
        CARD_KIND_BANDIT, 0x0, 2, HC_EFFECT_COMBO_FINISH, 480, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy39Frame0, gCardEmy39Tiles, gEmy39Palette, LOCALIZED(gEnemyNameFatBandit), gFatBanditSmallCardFrame0, gFatBanditSmallCardTiles, gFatBanditSmallCardPalette,
        CARD_KIND_FAT_BANDIT, 0x0, 3, HC_EFFECT_BACK_ATTACK, 483, CARD_CATEGORY_ENEMY, 40, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy39Frame0, gCardEmy39Tiles, gEmy39Palette, LOCALIZED(gEnemyNameFatBandit), gFatBanditSmallCardFrame0, gFatBanditSmallCardTiles, gFatBanditSmallCardPalette,
        CARD_KIND_FAT_BANDIT, 0x0, 1, HC_EFFECT_BACK_ATTACK, 483, CARD_CATEGORY_ENEMY, 40, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy39Frame0, gCardEmy39Tiles, gEmy39Palette, LOCALIZED(gEnemyNameFatBandit), gFatBanditSmallCardFrame0, gFatBanditSmallCardTiles, gFatBanditSmallCardPalette,
        CARD_KIND_FAT_BANDIT, 0x0, 6, HC_EFFECT_BACK_ATTACK, 483, CARD_CATEGORY_ENEMY, 40, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy21Frame0, gCardEmy21Tiles, gEmy21Palette, LOCALIZED(gEnemyNameBarrelSpider), gBarrelSpiderSmallCardFrame0, gBarrelSpiderSmallCardTiles, gBarrelSpiderSmallCardPalette,
        CARD_KIND_BARREL_SPIDER, 0x0, 4, HC_EFFECT_QUICKLOAD, 486, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy21Frame0, gCardEmy21Tiles, gEmy21Palette, LOCALIZED(gEnemyNameBarrelSpider), gBarrelSpiderSmallCardFrame0, gBarrelSpiderSmallCardTiles, gBarrelSpiderSmallCardPalette,
        CARD_KIND_BARREL_SPIDER, 0x0, 4, HC_EFFECT_QUICKLOAD, 486, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy21Frame0, gCardEmy21Tiles, gEmy21Palette, LOCALIZED(gEnemyNameBarrelSpider), gBarrelSpiderSmallCardFrame0, gBarrelSpiderSmallCardTiles, gBarrelSpiderSmallCardPalette,
        CARD_KIND_BARREL_SPIDER, 0x0, 4, HC_EFFECT_QUICKLOAD, 486, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy22Frame0, gCardEmy22Tiles, gEmy22Palette, LOCALIZED(gEnemyNameSearchGhost), gSearchGhostSmallCardFrame0, gSearchGhostSmallCardTiles, gSearchGhostSmallCardPalette,
        CARD_KIND_SEARCH_GHOST, 0x0, 1, HC_EFFECT_DRAIN, 489, CARD_CATEGORY_ENEMY, 35, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy22Frame0, gCardEmy22Tiles, gEmy22Palette, LOCALIZED(gEnemyNameSearchGhost), gSearchGhostSmallCardFrame0, gSearchGhostSmallCardTiles, gSearchGhostSmallCardPalette,
        CARD_KIND_SEARCH_GHOST, 0x0, 2, HC_EFFECT_DRAIN, 489, CARD_CATEGORY_ENEMY, 35, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy22Frame0, gCardEmy22Tiles, gEmy22Palette, LOCALIZED(gEnemyNameSearchGhost), gSearchGhostSmallCardFrame0, gSearchGhostSmallCardTiles, gSearchGhostSmallCardPalette,
        CARD_KIND_SEARCH_GHOST, 0x0, 2, HC_EFFECT_DRAIN, 489, CARD_CATEGORY_ENEMY, 35, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy06Frame0, gCardEmy06Tiles, gEmy06Palette, LOCALIZED(gEnemyNameSeaNeon), gSeaNeonSmallCardFrame0, gSeaNeonSmallCardTiles, gSeaNeonSmallCardPalette,
        CARD_KIND_SEA_NEON, 0x0, 1, HC_EFFECT_RANDOM_VALUES, 492, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy06Frame0, gCardEmy06Tiles, gEmy06Palette, LOCALIZED(gEnemyNameSeaNeon), gSeaNeonSmallCardFrame0, gSeaNeonSmallCardTiles, gSeaNeonSmallCardPalette,
        CARD_KIND_SEA_NEON, 0x0, 1, HC_EFFECT_RANDOM_VALUES, 492, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy06Frame0, gCardEmy06Tiles, gEmy06Palette, LOCALIZED(gEnemyNameSeaNeon), gSeaNeonSmallCardFrame0, gSeaNeonSmallCardTiles, gSeaNeonSmallCardPalette,
        CARD_KIND_SEA_NEON, 0x0, 1, HC_EFFECT_RANDOM_VALUES, 492, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy23Frame0, gCardEmy23Tiles, gEmy23Palette, LOCALIZED(gEnemyNameScrewdiver), gScrewdiverSmallCardFrame0, gScrewdiverSmallCardTiles, gScrewdiverSmallCardPalette,
        CARD_KIND_SCREWDIVER, 0x0, 1, HC_EFFECT_DECREMENTOR, 495, CARD_CATEGORY_ENEMY, 15, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy23Frame0, gCardEmy23Tiles, gEmy23Palette, LOCALIZED(gEnemyNameScrewdiver), gScrewdiverSmallCardFrame0, gScrewdiverSmallCardTiles, gScrewdiverSmallCardPalette,
        CARD_KIND_SCREWDIVER, 0x0, 2, HC_EFFECT_DECREMENTOR, 495, CARD_CATEGORY_ENEMY, 15, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy23Frame0, gCardEmy23Tiles, gEmy23Palette, LOCALIZED(gEnemyNameScrewdiver), gScrewdiverSmallCardFrame0, gScrewdiverSmallCardTiles, gScrewdiverSmallCardPalette,
        CARD_KIND_SCREWDIVER, 0x0, 2, HC_EFFECT_DECREMENTOR, 495, CARD_CATEGORY_ENEMY, 15, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy41Frame0, gCardEmy41Tiles, gEmy41Palette, LOCALIZED(gEnemyNameAquatank), gAquatankSmallCardFrame0, gAquatankSmallCardTiles, gAquatankSmallCardPalette,
        CARD_KIND_AQUATANK, 0x0, 2, HC_EFFECT_AUTO_RELOAD, 498, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy41Frame0, gCardEmy41Tiles, gEmy41Palette, LOCALIZED(gEnemyNameAquatank), gAquatankSmallCardFrame0, gAquatankSmallCardTiles, gAquatankSmallCardPalette,
        CARD_KIND_AQUATANK, 0x0, 1, HC_EFFECT_AUTO_RELOAD, 498, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy41Frame0, gCardEmy41Tiles, gEmy41Palette, LOCALIZED(gEnemyNameAquatank), gAquatankSmallCardFrame0, gAquatankSmallCardTiles, gAquatankSmallCardPalette,
        CARD_KIND_AQUATANK, 0x0, 7, HC_EFFECT_AUTO_RELOAD, 498, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy25Frame0, gCardEmy25Tiles, gEmy25Palette, LOCALIZED(gEnemyNameWightKnight), gWightKnightSmallCardFrame0, gWightKnightSmallCardTiles, gWightKnightSmallCardPalette,
        CARD_KIND_WIGHT_KNIGHT, 0x0, 2, HC_EFFECT_FLOAT, 501, CARD_CATEGORY_ENEMY, 15, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy25Frame0, gCardEmy25Tiles, gEmy25Palette, LOCALIZED(gEnemyNameWightKnight), gWightKnightSmallCardFrame0, gWightKnightSmallCardTiles, gWightKnightSmallCardPalette,
        CARD_KIND_WIGHT_KNIGHT, 0x0, 3, HC_EFFECT_FLOAT, 501, CARD_CATEGORY_ENEMY, 15, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy25Frame0, gCardEmy25Tiles, gEmy25Palette, LOCALIZED(gEnemyNameWightKnight), gWightKnightSmallCardFrame0, gWightKnightSmallCardTiles, gWightKnightSmallCardPalette,
        CARD_KIND_WIGHT_KNIGHT, 0x0, 3, HC_EFFECT_FLOAT, 501, CARD_CATEGORY_ENEMY, 15, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy26Frame0, gCardEmy26Tiles, gEmy26Palette, LOCALIZED(gEnemyNameGargoyle), gGargoyleSmallCardFrame0, gGargoyleSmallCardTiles, gGargoyleSmallCardPalette,
        CARD_KIND_GARGOYLE, 0x0, 3, HC_EFFECT_VANISH, 504, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy26Frame0, gCardEmy26Tiles, gEmy26Palette, LOCALIZED(gEnemyNameGargoyle), gGargoyleSmallCardFrame0, gGargoyleSmallCardTiles, gGargoyleSmallCardPalette,
        CARD_KIND_GARGOYLE, 0x0, 4, HC_EFFECT_VANISH, 504, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy26Frame0, gCardEmy26Tiles, gEmy26Palette, LOCALIZED(gEnemyNameGargoyle), gGargoyleSmallCardFrame0, gGargoyleSmallCardTiles, gGargoyleSmallCardPalette,
        CARD_KIND_GARGOYLE, 0x0, 4, HC_EFFECT_VANISH, 504, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy27Frame0, gCardEmy27Tiles, gEmy27Palette, LOCALIZED(gEnemyNamePirate), gPirateSmallCardFrame0, gPirateSmallCardTiles, gPirateSmallCardPalette,
        CARD_KIND_PIRATE, 0x0, 1, HC_EFFECT_ALL_ZEROS, 507, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy27Frame0, gCardEmy27Tiles, gEmy27Palette, LOCALIZED(gEnemyNamePirate), gPirateSmallCardFrame0, gPirateSmallCardTiles, gPirateSmallCardPalette,
        CARD_KIND_PIRATE, 0x0, 2, HC_EFFECT_ALL_ZEROS, 507, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy27Frame0, gCardEmy27Tiles, gEmy27Palette, LOCALIZED(gEnemyNamePirate), gPirateSmallCardFrame0, gPirateSmallCardTiles, gPirateSmallCardPalette,
        CARD_KIND_PIRATE, 0x0, 2, HC_EFFECT_ALL_ZEROS, 507, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy28Frame0, gCardEmy28Tiles, gEmy28Palette, LOCALIZED(gEnemyNameAirPirate), gAirPirateSmallCardFrame0, gAirPirateSmallCardTiles, gAirPirateSmallCardPalette,
        CARD_KIND_AIR_PIRATE, 0x0, 3, HC_EFFECT_ITEM_BRACER, 510, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy28Frame0, gCardEmy28Tiles, gEmy28Palette, LOCALIZED(gEnemyNameAirPirate), gAirPirateSmallCardFrame0, gAirPirateSmallCardTiles, gAirPirateSmallCardPalette,
        CARD_KIND_AIR_PIRATE, 0x0, 4, HC_EFFECT_ITEM_BRACER, 510, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy28Frame0, gCardEmy28Tiles, gEmy28Palette, LOCALIZED(gEnemyNameAirPirate), gAirPirateSmallCardFrame0, gAirPirateSmallCardTiles, gAirPirateSmallCardPalette,
        CARD_KIND_AIR_PIRATE, 0x0, 4, HC_EFFECT_ITEM_BRACER, 510, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy29Frame0, gCardEmy29Tiles, gEmy29Palette, LOCALIZED(gEnemyNameDarkball), gDarkballSmallCardFrame0, gDarkballSmallCardTiles, gDarkballSmallCardPalette,
        CARD_KIND_DARKBALL, 0x0, 2, HC_EFFECT_CARDBLIND, 513, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy29Frame0, gCardEmy29Tiles, gEmy29Palette, LOCALIZED(gEnemyNameDarkball), gDarkballSmallCardFrame0, gDarkballSmallCardTiles, gDarkballSmallCardPalette,
        CARD_KIND_DARKBALL, 0x0, 4, HC_EFFECT_CARDBLIND, 513, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy29Frame0, gCardEmy29Tiles, gEmy29Palette, LOCALIZED(gEnemyNameDarkball), gDarkballSmallCardFrame0, gDarkballSmallCardTiles, gDarkballSmallCardPalette,
        CARD_KIND_DARKBALL, 0x0, 6, HC_EFFECT_CARDBLIND, 513, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy44Frame0, gCardEmy44Tiles, gEmy44Palette, LOCALIZED(gEnemyNameDefender), gDefenderSmallCardFrame0, gDefenderSmallCardTiles, gDefenderSmallCardPalette,
        CARD_KIND_DEFENDER, 0x0, 5, HC_EFFECT_PROTECT, 516, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy44Frame0, gCardEmy44Tiles, gEmy44Palette, LOCALIZED(gEnemyNameDefender), gDefenderSmallCardFrame0, gDefenderSmallCardTiles, gDefenderSmallCardPalette,
        CARD_KIND_DEFENDER, 0x0, 1, HC_EFFECT_PROTECT, 516, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy44Frame0, gCardEmy44Tiles, gEmy44Palette, LOCALIZED(gEnemyNameDefender), gDefenderSmallCardFrame0, gDefenderSmallCardTiles, gDefenderSmallCardPalette,
        CARD_KIND_DEFENDER, 0x0, 9, HC_EFFECT_PROTECT, 516, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy30Frame0, gCardEmy30Tiles, gEmy30Palette, LOCALIZED(gEnemyNameWyvern), gWyvernSmallCardFrame0, gWyvernSmallCardTiles, gWyvernSmallCardPalette,
        CARD_KIND_WYVERN, 0x0, 4, HC_EFFECT_DRAW_2, 519, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy30Frame0, gCardEmy30Tiles, gEmy30Palette, LOCALIZED(gEnemyNameWyvern), gWyvernSmallCardFrame0, gWyvernSmallCardTiles, gWyvernSmallCardPalette,
        CARD_KIND_WYVERN, 0x0, 5, HC_EFFECT_DRAW_2, 519, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy30Frame0, gCardEmy30Tiles, gEmy30Palette, LOCALIZED(gEnemyNameWyvern), gWyvernSmallCardFrame0, gWyvernSmallCardTiles, gWyvernSmallCardPalette,
        CARD_KIND_WYVERN, 0x0, 5, HC_EFFECT_DRAW_2, 519, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy31Frame0, gCardEmy31Tiles, gEmy31Palette, LOCALIZED(gEnemyNameWizard), gWizardSmallCardFrame0, gWizardSmallCardTiles, gWizardSmallCardPalette,
        CARD_KIND_WIZARD, 0x0, 3, HC_EFFECT_MAGIC_BOOST, 522, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy31Frame0, gCardEmy31Tiles, gEmy31Palette, LOCALIZED(gEnemyNameWizard), gWizardSmallCardFrame0, gWizardSmallCardTiles, gWizardSmallCardPalette,
        CARD_KIND_WIZARD, 0x0, 1, HC_EFFECT_MAGIC_BOOST, 522, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy31Frame0, gCardEmy31Tiles, gEmy31Palette, LOCALIZED(gEnemyNameWizard), gWizardSmallCardFrame0, gWizardSmallCardTiles, gWizardSmallCardPalette,
        CARD_KIND_WIZARD, 0x0, 7, HC_EFFECT_MAGIC_BOOST, 522, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy37Frame0, gCardEmy37Tiles, gEmy37Palette, LOCALIZED(gEnemyNameNeoshadow), gNeoshadowSmallCardFrame0, gNeoshadowSmallCardTiles, gNeoshadowSmallCardPalette,
        CARD_KIND_NEOSHADOW, 0x0, 7, HC_EFFECT_BIO, 525, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy37Frame0, gCardEmy37Tiles, gEmy37Palette, LOCALIZED(gEnemyNameNeoshadow), gNeoshadowSmallCardFrame0, gNeoshadowSmallCardTiles, gNeoshadowSmallCardPalette,
        CARD_KIND_NEOSHADOW, 0x0, 2, HC_EFFECT_BIO, 525, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy37Frame0, gCardEmy37Tiles, gEmy37Palette, LOCALIZED(gEnemyNameNeoshadow), gNeoshadowSmallCardFrame0, gNeoshadowSmallCardTiles, gNeoshadowSmallCardPalette,
        CARD_KIND_NEOSHADOW, 0x0, 8, HC_EFFECT_BIO, 525, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy07Frame0, gCardEmy07Tiles, gEmy07Palette, LOCALIZED(gEnemyNameWhiteMushroom), gWhiteMushroomSmallCardFrame0, gWhiteMushroomSmallCardTiles, gWhiteMushroomSmallCardPalette,
        CARD_KIND_WHITE_MUSHROOM, 0x0, 2, HC_EFFECT_HYPER_HEALING, 528, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy08Frame0, gCardEmy08Tiles, gEmy07bPalette, LOCALIZED(gEnemyNameBlackFungus), gBlackFungusSmallCardFrame0, gBlackFungusSmallCardTiles, gBlackFungusSmallCardPalette,
        CARD_KIND_BLACK_FUNGUS, 0x0, 7, HC_EFFECT_RANDOM_FLUSH, 529, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy08Frame0, gCardEmy08Tiles, gEmy07bPalette, LOCALIZED(gEnemyNameBlackFungus), gBlackFungusSmallCardFrame0, gBlackFungusSmallCardTiles, gBlackFungusSmallCardPalette,
        CARD_KIND_BLACK_FUNGUS, 0x0, 7, HC_EFFECT_RANDOM_FLUSH, 529, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy08Frame0, gCardEmy08Tiles, gEmy07bPalette, LOCALIZED(gEnemyNameBlackFungus), gBlackFungusSmallCardFrame0, gBlackFungusSmallCardTiles, gBlackFungusSmallCardPalette,
        CARD_KIND_BLACK_FUNGUS, 0x0, 7, HC_EFFECT_RANDOM_FLUSH, 529, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy83Frame0, gCardEmy83Tiles, gEmy83Palette, LOCALIZED(gEnemyNameCreeperPlant), gCreeperPlantSmallCardFrame0, gCreeperPlantSmallCardTiles, gCreeperPlantSmallCardPalette,
        CARD_KIND_CREEPER_PLANT, 0x0, 2, HC_EFFECT_LEAF_BRACER, 532, CARD_CATEGORY_ENEMY, 35, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy83Frame0, gCardEmy83Tiles, gEmy83Palette, LOCALIZED(gEnemyNameCreeperPlant), gCreeperPlantSmallCardFrame0, gCreeperPlantSmallCardTiles, gCreeperPlantSmallCardPalette,
        CARD_KIND_CREEPER_PLANT, 0x0, 4, HC_EFFECT_LEAF_BRACER, 532, CARD_CATEGORY_ENEMY, 35, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy83Frame0, gCardEmy83Tiles, gEmy83Palette, LOCALIZED(gEnemyNameCreeperPlant), gCreeperPlantSmallCardFrame0, gCreeperPlantSmallCardTiles, gCreeperPlantSmallCardPalette,
        CARD_KIND_CREEPER_PLANT, 0x0, 6, HC_EFFECT_LEAF_BRACER, 532, CARD_CATEGORY_ENEMY, 35, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy81Frame0, gCardEmy81Tiles, gEmy81Palette, LOCALIZED(gEnemyNameTornadoStep), gTornadoStepSmallCardFrame0, gTornadoStepSmallCardTiles, gTornadoStepSmallCardPalette,
        CARD_KIND_TORNADO_STEP, 0x0, 2, HC_EFFECT_COMBO_PLUS_2, 535, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy81Frame0, gCardEmy81Tiles, gEmy81Palette, LOCALIZED(gEnemyNameTornadoStep), gTornadoStepSmallCardFrame0, gTornadoStepSmallCardTiles, gTornadoStepSmallCardPalette,
        CARD_KIND_TORNADO_STEP, 0x0, 4, HC_EFFECT_COMBO_PLUS_2, 535, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy81Frame0, gCardEmy81Tiles, gEmy81Palette, LOCALIZED(gEnemyNameTornadoStep), gTornadoStepSmallCardFrame0, gTornadoStepSmallCardTiles, gTornadoStepSmallCardPalette,
        CARD_KIND_TORNADO_STEP, 0x0, 6, HC_EFFECT_COMBO_PLUS_2, 535, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy82Frame0, gCardEmy82Tiles, gEmy82Palette, LOCALIZED(gEnemyNameCrescendo), gCrescendoSmallCardFrame0, gCrescendoSmallCardTiles, gCrescendoSmallCardPalette,
        CARD_KIND_CRESCENDO, 0x0, 2, HC_EFFECT_SUMMON_BOOST, 538, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy82Frame0, gCardEmy82Tiles, gEmy82Palette, LOCALIZED(gEnemyNameCrescendo), gCrescendoSmallCardFrame0, gCrescendoSmallCardTiles, gCrescendoSmallCardPalette,
        CARD_KIND_CRESCENDO, 0x0, 4, HC_EFFECT_SUMMON_BOOST, 538, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardEmy82Frame0, gCardEmy82Tiles, gEmy82Palette, LOCALIZED(gEnemyNameCrescendo), gCrescendoSmallCardFrame0, gCrescendoSmallCardTiles, gCrescendoSmallCardPalette,
        CARD_KIND_CRESCENDO, 0x0, 6, HC_EFFECT_SUMMON_BOOST, 538, CARD_CATEGORY_ENEMY, 20, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos01Frame0, gCardBos01Tiles, gBoss01objPalette, LOCALIZED(gEnemyNameGuardArmor), gGuardArmorSmallCardFrame0, gGuardArmorSmallCardTiles, gGuardArmorSmallCardPalette,
        CARD_KIND_GUARD_ARMOR, 0x0, 1, HC_EFFECT_WIDE_ATTACK_2, 575, CARD_CATEGORY_ENEMY, 30, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos04Frame0, gCardBos04Tiles, gBosPcBgPalettes, LOCALIZED(gEnemyNameParasiteCage), gParasiteCageSmallCardFrame0, gParasiteCageSmallCardTiles, gParasiteCageSmallCardPalette,
        CARD_KIND_PARASITE_CAGE, 0x0, 1, HC_EFFECT_DISPEL, 605, CARD_CATEGORY_ENEMY, 60, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos03Frame0, gCardBos03Tiles, gBoss03objPalettes, LOCALIZED(gEnemyNameTrickmaster), gTrickmasterSmallCardFrame0, gTrickmasterSmallCardTiles, gTrickmasterSmallCardPalette,
        CARD_KIND_TRICKMASTER, 0x0, 1, HC_EFFECT_VALUE_BREAK, 595, CARD_CATEGORY_ENEMY, 25, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos00Frame0, gCardBos00Tiles, gBoss00ObjPalette, LOCALIZED(gEnemyNameDarkside), gDarksideSmallCardFrame0, gDarksideSmallCardTiles, gDarksideSmallCardPalette,
        CARD_KIND_DARKSIDE, 0x0, 1, HC_EFFECT_MIMIC, 565, CARD_CATEGORY_ENEMY, 99, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardNpcAw04Frame0, gCardNpcAw04Tiles, gTrumpHPalette, LOCALIZED(gEnemyNameCardSoldier), gCardSoldierHeartSmallCardFrame0, gCardSoldierHeartSmallCardTiles, gCardSoldierHeartSmallCardPalette,
        CARD_KIND_CARD_SOLDIER_HEART, 0x0, 2, HC_EFFECT_ATTACK_HASTE, 545, CARD_CATEGORY_ENEMY, 55, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardNpcAw04Frame0, gCardNpcAw04Tiles, gTrumpHPalette, LOCALIZED(gEnemyNameCardSoldier), gCardSoldierHeartSmallCardFrame0, gCardSoldierHeartSmallCardTiles, gCardSoldierHeartSmallCardPalette,
        CARD_KIND_CARD_SOLDIER_HEART, 0x0, 3, HC_EFFECT_ATTACK_HASTE, 545, CARD_CATEGORY_ENEMY, 55, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardNpcAw04Frame0, gCardNpcAw04Tiles, gTrumpHPalette, LOCALIZED(gEnemyNameCardSoldier), gCardSoldierHeartSmallCardFrame0, gCardSoldierHeartSmallCardTiles, gCardSoldierHeartSmallCardPalette,
        CARD_KIND_CARD_SOLDIER_HEART, 0x0, 3, HC_EFFECT_ATTACK_HASTE, 545, CARD_CATEGORY_ENEMY, 55, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardNpcAw03Frame0, gCardNpcAw03Tiles, gTrumpSPalette, LOCALIZED(gEnemyNameCardSoldier), gCardSoldierSpadeSmallCardFrame0, gCardSoldierSpadeSmallCardTiles, gCardSoldierSpadeSmallCardPalette,
        CARD_KIND_CARD_SOLDIER_SPADE, 0x0, 1, HC_EFFECT_ATTACK_HASTE, 548, CARD_CATEGORY_ENEMY, 55, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardNpcAw03Frame0, gCardNpcAw03Tiles, gTrumpSPalette, LOCALIZED(gEnemyNameCardSoldier), gCardSoldierSpadeSmallCardFrame0, gCardSoldierSpadeSmallCardTiles, gCardSoldierSpadeSmallCardPalette,
        CARD_KIND_CARD_SOLDIER_SPADE, 0x0, 4, HC_EFFECT_ATTACK_HASTE, 548, CARD_CATEGORY_ENEMY, 55, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardNpcAw03Frame0, gCardNpcAw03Tiles, gTrumpSPalette, LOCALIZED(gEnemyNameCardSoldier), gCardSoldierSpadeSmallCardFrame0, gCardSoldierSpadeSmallCardTiles, gCardSoldierSpadeSmallCardPalette,
        CARD_KIND_CARD_SOLDIER_SPADE, 0x0, 4, HC_EFFECT_ATTACK_HASTE, 548, CARD_CATEGORY_ENEMY, 55, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11Palette, LOCALIZED(gEnemyNameHades), gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesSmallCardPalette,
        CARD_KIND_HADES, 0x0, 9, HC_EFFECT_BERSERK, 551, CARD_CATEGORY_ENEMY, 40, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos05Frame0, gCardBos05Tiles, gCardBos05Palette, LOCALIZED(gEnemyNameJafar), gJafarSmallCardFrame0, gJafarSmallCardTiles, gJafarSmallCardPalette,
        CARD_KIND_JAFAR, 0x0, 1, HC_EFFECT_ATTACK_BRACER, 615, CARD_CATEGORY_ENEMY, 65, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos02Frame0, gCardBos02Tiles, gBoss02objPalette, LOCALIZED(gEnemyNameOogieBoogie), gOogieBoogieSmallCardFrame0, gOogieBoogieSmallCardTiles, gOogieBoogieSmallCardPalette,
        CARD_KIND_OOGIE_BOOGIE, 0x0, 1, HC_EFFECT_REGEN, 585, CARD_CATEGORY_ENEMY, 40, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos06Frame0, gCardBos06Tiles, gCardBos06Palette, LOCALIZED(gEnemyNameUrsula), gUrsulaSmallCardFrame0, gUrsulaSmallCardTiles, gUrsulaSmallCardPalette,
        CARD_KIND_URSULA, 0x0, 1, HC_EFFECT_SHELL, 625, CARD_CATEGORY_ENEMY, 50, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10Palette, LOCALIZED(gEnemyNameHook), gHookSmallCardFrame0, gHookSmallCardTiles, gHookSmallCardPalette,
        CARD_KIND_HOOK, 0x0, 9, HC_EFFECT_SECOND_CHANCE, 555, CARD_CATEGORY_ENEMY, 35, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos07Frame0, gCardBos07Tiles, gCardBos07Palette, LOCALIZED(gEnemyNameDragonMaleficent), gDragonMaleficentSmallCardFrame0, gDragonMaleficentSmallCardTiles, gDragonMaleficentSmallCardPalette,
        CARD_KIND_DRAGON_MALEFICENT, 0x0, 1, HC_EFFECT_OVERDRIVE, 635, CARD_CATEGORY_ENEMY, 70, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12Palette, LOCALIZED(gEnemyNameRiku), gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuSmallCardPalette,
        CARD_KIND_RIKU, 0x0, 9, HC_EFFECT_SLEIGHT_LOCK, 557, CARD_CATEGORY_ENEMY, 80, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13Palette, LOCALIZED(gEnemyNameAxel), gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelSmallCardPalette,
        CARD_KIND_AXEL, 0x0, 9, HC_EFFECT_QUICK_RECOVERY, 558, CARD_CATEGORY_ENEMY, 75, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14Palette, LOCALIZED(gEnemyNameLarxene), gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneSmallCardPalette,
        CARD_KIND_LARXENE, 0x0, 9, HC_EFFECT_DASH, 559, CARD_CATEGORY_ENEMY, 60, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15Palette, LOCALIZED(gEnemyNameVexen), gVexenSmallCardFrame0, gVexenSmallCardTiles, gVexenSmallCardPalette,
        CARD_KIND_VEXEN, 0x0, 9, HC_EFFECT_AUTO_LIFE, 560, CARD_CATEGORY_ENEMY, 60, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16Palette, LOCALIZED(gEnemyNameMarluxia), gMarluxiaSmallCardFrame0, gMarluxiaSmallCardTiles, gMarluxiaSmallCardPalette,
        CARD_KIND_MARLUXIA, 0x0, 9, HC_EFFECT_DOUBLE_SLEIGHT, 561, CARD_CATEGORY_ENEMY, 99, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos08Frame0, gCardBos08Tiles, gCardBos08Palette, LOCALIZED(gEnemyNameMarluxia), gMarluxia2SmallCardFrame0, gMarluxia2SmallCardTiles, gMarluxia2SmallCardPalette,
        CARD_KIND_MARLUXIA_2, 0x0, 1, HC_EFFECT_OVERDRIVE, 645, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17Palette, LOCALIZED(gEnemyNameLexaeus), gLexaeusSmallCardFrame0, gLexaeusSmallCardTiles, gLexaeusSmallCardPalette,
        CARD_KIND_LEXAEUS, 0x0, 9, HC_EFFECT_WARP_BREAK, 563, CARD_CATEGORY_ENEMY, 99, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18Palette, LOCALIZED(gEnemyNameAnsem), gAnsemSmallCardFrame0, gAnsemSmallCardTiles, gAnsemSmallCardPalette,
        CARD_KIND_ANSEM, 0x0, 9, HC_EFFECT_SLEIGHTBLIND, 564, CARD_CATEGORY_ENEMY, 60, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos00Frame0, gCardBos00Tiles, gBoss00ObjPalette, LOCALIZED(gCharacterNameCardOfSpades), gDarksideSmallCardFrame0, gDarksideSmallCardTiles, gDarksideSmallCardPalette,
        CARD_KIND_DARKSIDE, 0x0, 0, HC_EFFECT_NONE, 565, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos00Frame0, gCardBos00Tiles, gBoss00ObjPalette, LOCALIZED(gCharacterNameCardOfSpades), gDarksideSmallCardFrame0, gDarksideSmallCardTiles, gDarksideSmallCardPalette,
        CARD_KIND_DARKSIDE, 0x0, 1, HC_EFFECT_NONE, 565, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos00Frame0, gCardBos00Tiles, gBoss00ObjPalette, LOCALIZED(gCharacterNameCardOfSpades), gDarksideSmallCardFrame0, gDarksideSmallCardTiles, gDarksideSmallCardPalette,
        CARD_KIND_DARKSIDE, 0x0, 2, HC_EFFECT_NONE, 565, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos00Frame0, gCardBos00Tiles, gBoss00ObjPalette, LOCALIZED(gCharacterNameCardOfSpades), gDarksideSmallCardFrame0, gDarksideSmallCardTiles, gDarksideSmallCardPalette,
        CARD_KIND_DARKSIDE, 0x0, 3, HC_EFFECT_NONE, 565, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos00Frame0, gCardBos00Tiles, gBoss00ObjPalette, LOCALIZED(gCharacterNameCardOfSpades), gDarksideSmallCardFrame0, gDarksideSmallCardTiles, gDarksideSmallCardPalette,
        CARD_KIND_DARKSIDE, 0x0, 4, HC_EFFECT_NONE, 565, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos00Frame0, gCardBos00Tiles, gBoss00ObjPalette, LOCALIZED(gCharacterNameCardOfSpades), gDarksideSmallCardFrame0, gDarksideSmallCardTiles, gDarksideSmallCardPalette,
        CARD_KIND_DARKSIDE, 0x0, 5, HC_EFFECT_NONE, 565, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos00Frame0, gCardBos00Tiles, gBoss00ObjPalette, LOCALIZED(gCharacterNameCardOfSpades), gDarksideSmallCardFrame0, gDarksideSmallCardTiles, gDarksideSmallCardPalette,
        CARD_KIND_DARKSIDE, 0x0, 6, HC_EFFECT_NONE, 565, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos00Frame0, gCardBos00Tiles, gBoss00ObjPalette, LOCALIZED(gCharacterNameCardOfSpades), gDarksideSmallCardFrame0, gDarksideSmallCardTiles, gDarksideSmallCardPalette,
        CARD_KIND_DARKSIDE, 0x0, 7, HC_EFFECT_NONE, 565, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos00Frame0, gCardBos00Tiles, gBoss00ObjPalette, LOCALIZED(gCharacterNameCardOfSpades), gDarksideSmallCardFrame0, gDarksideSmallCardTiles, gDarksideSmallCardPalette,
        CARD_KIND_DARKSIDE, 0x0, 8, HC_EFFECT_NONE, 565, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos00Frame0, gCardBos00Tiles, gBoss00ObjPalette, LOCALIZED(gCharacterNameCardOfSpades), gDarksideSmallCardFrame0, gDarksideSmallCardTiles, gDarksideSmallCardPalette,
        CARD_KIND_DARKSIDE, 0x0, 9, HC_EFFECT_NONE, 565, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos01Frame0, gCardBos01Tiles, gBoss01objPalette, LOCALIZED(gCharacterNameCardOfSpades), gGuardArmorSmallCardFrame0, gGuardArmorSmallCardTiles, gGuardArmorSmallCardPalette,
        CARD_KIND_GUARD_ARMOR, 0x0, 0, HC_EFFECT_NONE, 575, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos01Frame0, gCardBos01Tiles, gBoss01objPalette, LOCALIZED(gCharacterNameCardOfSpades), gGuardArmorSmallCardFrame0, gGuardArmorSmallCardTiles, gGuardArmorSmallCardPalette,
        CARD_KIND_GUARD_ARMOR, 0x0, 1, HC_EFFECT_NONE, 575, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos01Frame0, gCardBos01Tiles, gBoss01objPalette, LOCALIZED(gCharacterNameCardOfSpades), gGuardArmorSmallCardFrame0, gGuardArmorSmallCardTiles, gGuardArmorSmallCardPalette,
        CARD_KIND_GUARD_ARMOR, 0x0, 2, HC_EFFECT_NONE, 575, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos01Frame0, gCardBos01Tiles, gBoss01objPalette, LOCALIZED(gCharacterNameCardOfSpades), gGuardArmorSmallCardFrame0, gGuardArmorSmallCardTiles, gGuardArmorSmallCardPalette,
        CARD_KIND_GUARD_ARMOR, 0x0, 3, HC_EFFECT_NONE, 575, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos01Frame0, gCardBos01Tiles, gBoss01objPalette, LOCALIZED(gCharacterNameCardOfSpades), gGuardArmorSmallCardFrame0, gGuardArmorSmallCardTiles, gGuardArmorSmallCardPalette,
        CARD_KIND_GUARD_ARMOR, 0x0, 4, HC_EFFECT_NONE, 575, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos01Frame0, gCardBos01Tiles, gBoss01objPalette, LOCALIZED(gCharacterNameCardOfSpades), gGuardArmorSmallCardFrame0, gGuardArmorSmallCardTiles, gGuardArmorSmallCardPalette,
        CARD_KIND_GUARD_ARMOR, 0x0, 5, HC_EFFECT_NONE, 575, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos01Frame0, gCardBos01Tiles, gBoss01objPalette, LOCALIZED(gCharacterNameCardOfSpades), gGuardArmorSmallCardFrame0, gGuardArmorSmallCardTiles, gGuardArmorSmallCardPalette,
        CARD_KIND_GUARD_ARMOR, 0x0, 6, HC_EFFECT_NONE, 575, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos01Frame0, gCardBos01Tiles, gBoss01objPalette, LOCALIZED(gCharacterNameCardOfSpades), gGuardArmorSmallCardFrame0, gGuardArmorSmallCardTiles, gGuardArmorSmallCardPalette,
        CARD_KIND_GUARD_ARMOR, 0x0, 7, HC_EFFECT_NONE, 575, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos01Frame0, gCardBos01Tiles, gBoss01objPalette, LOCALIZED(gCharacterNameCardOfSpades), gGuardArmorSmallCardFrame0, gGuardArmorSmallCardTiles, gGuardArmorSmallCardPalette,
        CARD_KIND_GUARD_ARMOR, 0x0, 8, HC_EFFECT_NONE, 575, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos01Frame0, gCardBos01Tiles, gBoss01objPalette, LOCALIZED(gCharacterNameCardOfSpades), gGuardArmorSmallCardFrame0, gGuardArmorSmallCardTiles, gGuardArmorSmallCardPalette,
        CARD_KIND_GUARD_ARMOR, 0x0, 9, HC_EFFECT_NONE, 575, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos02Frame0, gCardBos02Tiles, gBoss02objPalette, LOCALIZED(gCharacterNameCardOfSpades), gOogieBoogieSmallCardFrame0, gOogieBoogieSmallCardTiles, gOogieBoogieSmallCardPalette,
        CARD_KIND_OOGIE_BOOGIE, 0x0, 0, HC_EFFECT_NONE, 585, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos02Frame0, gCardBos02Tiles, gBoss02objPalette, LOCALIZED(gCharacterNameCardOfSpades), gOogieBoogieSmallCardFrame0, gOogieBoogieSmallCardTiles, gOogieBoogieSmallCardPalette,
        CARD_KIND_OOGIE_BOOGIE, 0x0, 1, HC_EFFECT_NONE, 585, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos02Frame0, gCardBos02Tiles, gBoss02objPalette, LOCALIZED(gCharacterNameCardOfSpades), gOogieBoogieSmallCardFrame0, gOogieBoogieSmallCardTiles, gOogieBoogieSmallCardPalette,
        CARD_KIND_OOGIE_BOOGIE, 0x0, 2, HC_EFFECT_NONE, 585, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos02Frame0, gCardBos02Tiles, gBoss02objPalette, LOCALIZED(gCharacterNameCardOfSpades), gOogieBoogieSmallCardFrame0, gOogieBoogieSmallCardTiles, gOogieBoogieSmallCardPalette,
        CARD_KIND_OOGIE_BOOGIE, 0x0, 3, HC_EFFECT_NONE, 585, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos02Frame0, gCardBos02Tiles, gBoss02objPalette, LOCALIZED(gCharacterNameCardOfSpades), gOogieBoogieSmallCardFrame0, gOogieBoogieSmallCardTiles, gOogieBoogieSmallCardPalette,
        CARD_KIND_OOGIE_BOOGIE, 0x0, 4, HC_EFFECT_NONE, 585, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos02Frame0, gCardBos02Tiles, gBoss02objPalette, LOCALIZED(gCharacterNameCardOfSpades), gOogieBoogieSmallCardFrame0, gOogieBoogieSmallCardTiles, gOogieBoogieSmallCardPalette,
        CARD_KIND_OOGIE_BOOGIE, 0x0, 5, HC_EFFECT_NONE, 585, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos02Frame0, gCardBos02Tiles, gBoss02objPalette, LOCALIZED(gCharacterNameCardOfSpades), gOogieBoogieSmallCardFrame0, gOogieBoogieSmallCardTiles, gOogieBoogieSmallCardPalette,
        CARD_KIND_OOGIE_BOOGIE, 0x0, 6, HC_EFFECT_NONE, 585, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos02Frame0, gCardBos02Tiles, gBoss02objPalette, LOCALIZED(gCharacterNameCardOfSpades), gOogieBoogieSmallCardFrame0, gOogieBoogieSmallCardTiles, gOogieBoogieSmallCardPalette,
        CARD_KIND_OOGIE_BOOGIE, 0x0, 7, HC_EFFECT_NONE, 585, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos02Frame0, gCardBos02Tiles, gBoss02objPalette, LOCALIZED(gCharacterNameCardOfSpades), gOogieBoogieSmallCardFrame0, gOogieBoogieSmallCardTiles, gOogieBoogieSmallCardPalette,
        CARD_KIND_OOGIE_BOOGIE, 0x0, 8, HC_EFFECT_NONE, 585, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos02Frame0, gCardBos02Tiles, gBoss02objPalette, LOCALIZED(gCharacterNameCardOfSpades), gOogieBoogieSmallCardFrame0, gOogieBoogieSmallCardTiles, gOogieBoogieSmallCardPalette,
        CARD_KIND_OOGIE_BOOGIE, 0x0, 9, HC_EFFECT_NONE, 585, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos03Frame0, gCardBos03Tiles, gBoss03objPalettes, LOCALIZED(gCharacterNameCardOfSpades), gTrickmasterSmallCardFrame0, gTrickmasterSmallCardTiles, gTrickmasterSmallCardPalette,
        CARD_KIND_TRICKMASTER, 0x0, 0, HC_EFFECT_NONE, 595, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos03Frame0, gCardBos03Tiles, gBoss03objPalettes, LOCALIZED(gCharacterNameCardOfSpades), gTrickmasterSmallCardFrame0, gTrickmasterSmallCardTiles, gTrickmasterSmallCardPalette,
        CARD_KIND_TRICKMASTER, 0x0, 1, HC_EFFECT_NONE, 595, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos03Frame0, gCardBos03Tiles, gBoss03objPalettes, LOCALIZED(gCharacterNameCardOfSpades), gTrickmasterSmallCardFrame0, gTrickmasterSmallCardTiles, gTrickmasterSmallCardPalette,
        CARD_KIND_TRICKMASTER, 0x0, 2, HC_EFFECT_NONE, 595, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos03Frame0, gCardBos03Tiles, gBoss03objPalettes, LOCALIZED(gCharacterNameCardOfSpades), gTrickmasterSmallCardFrame0, gTrickmasterSmallCardTiles, gTrickmasterSmallCardPalette,
        CARD_KIND_TRICKMASTER, 0x0, 3, HC_EFFECT_NONE, 595, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos03Frame0, gCardBos03Tiles, gBoss03objPalettes, LOCALIZED(gCharacterNameCardOfSpades), gTrickmasterSmallCardFrame0, gTrickmasterSmallCardTiles, gTrickmasterSmallCardPalette,
        CARD_KIND_TRICKMASTER, 0x0, 4, HC_EFFECT_NONE, 595, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos03Frame0, gCardBos03Tiles, gBoss03objPalettes, LOCALIZED(gCharacterNameCardOfSpades), gTrickmasterSmallCardFrame0, gTrickmasterSmallCardTiles, gTrickmasterSmallCardPalette,
        CARD_KIND_TRICKMASTER, 0x0, 5, HC_EFFECT_NONE, 595, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos03Frame0, gCardBos03Tiles, gBoss03objPalettes, LOCALIZED(gCharacterNameCardOfSpades), gTrickmasterSmallCardFrame0, gTrickmasterSmallCardTiles, gTrickmasterSmallCardPalette,
        CARD_KIND_TRICKMASTER, 0x0, 6, HC_EFFECT_NONE, 595, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos03Frame0, gCardBos03Tiles, gBoss03objPalettes, LOCALIZED(gCharacterNameCardOfSpades), gTrickmasterSmallCardFrame0, gTrickmasterSmallCardTiles, gTrickmasterSmallCardPalette,
        CARD_KIND_TRICKMASTER, 0x0, 7, HC_EFFECT_NONE, 595, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos03Frame0, gCardBos03Tiles, gBoss03objPalettes, LOCALIZED(gCharacterNameCardOfSpades), gTrickmasterSmallCardFrame0, gTrickmasterSmallCardTiles, gTrickmasterSmallCardPalette,
        CARD_KIND_TRICKMASTER, 0x0, 8, HC_EFFECT_NONE, 595, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos03Frame0, gCardBos03Tiles, gBoss03objPalettes, LOCALIZED(gCharacterNameCardOfSpades), gTrickmasterSmallCardFrame0, gTrickmasterSmallCardTiles, gTrickmasterSmallCardPalette,
        CARD_KIND_TRICKMASTER, 0x0, 9, HC_EFFECT_NONE, 595, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos04Frame0, gCardBos04Tiles, gBosPcBgPalettes, LOCALIZED(gCharacterNameCardOfSpades), gParasiteCageSmallCardFrame0, gParasiteCageSmallCardTiles, gParasiteCageSmallCardPalette,
        CARD_KIND_PARASITE_CAGE, 0x0, 0, HC_EFFECT_NONE, 605, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos04Frame0, gCardBos04Tiles, gBosPcBgPalettes, LOCALIZED(gCharacterNameCardOfSpades), gParasiteCageSmallCardFrame0, gParasiteCageSmallCardTiles, gParasiteCageSmallCardPalette,
        CARD_KIND_PARASITE_CAGE, 0x0, 1, HC_EFFECT_NONE, 605, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos04Frame0, gCardBos04Tiles, gBosPcBgPalettes, LOCALIZED(gCharacterNameCardOfSpades), gParasiteCageSmallCardFrame0, gParasiteCageSmallCardTiles, gParasiteCageSmallCardPalette,
        CARD_KIND_PARASITE_CAGE, 0x0, 2, HC_EFFECT_NONE, 605, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos04Frame0, gCardBos04Tiles, gBosPcBgPalettes, LOCALIZED(gCharacterNameCardOfSpades), gParasiteCageSmallCardFrame0, gParasiteCageSmallCardTiles, gParasiteCageSmallCardPalette,
        CARD_KIND_PARASITE_CAGE, 0x0, 3, HC_EFFECT_NONE, 605, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos04Frame0, gCardBos04Tiles, gBosPcBgPalettes, LOCALIZED(gCharacterNameCardOfSpades), gParasiteCageSmallCardFrame0, gParasiteCageSmallCardTiles, gParasiteCageSmallCardPalette,
        CARD_KIND_PARASITE_CAGE, 0x0, 4, HC_EFFECT_NONE, 605, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos04Frame0, gCardBos04Tiles, gBosPcBgPalettes, LOCALIZED(gCharacterNameCardOfSpades), gParasiteCageSmallCardFrame0, gParasiteCageSmallCardTiles, gParasiteCageSmallCardPalette,
        CARD_KIND_PARASITE_CAGE, 0x0, 5, HC_EFFECT_NONE, 605, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos04Frame0, gCardBos04Tiles, gBosPcBgPalettes, LOCALIZED(gCharacterNameCardOfSpades), gParasiteCageSmallCardFrame0, gParasiteCageSmallCardTiles, gParasiteCageSmallCardPalette,
        CARD_KIND_PARASITE_CAGE, 0x0, 6, HC_EFFECT_NONE, 605, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos04Frame0, gCardBos04Tiles, gBosPcBgPalettes, LOCALIZED(gCharacterNameCardOfSpades), gParasiteCageSmallCardFrame0, gParasiteCageSmallCardTiles, gParasiteCageSmallCardPalette,
        CARD_KIND_PARASITE_CAGE, 0x0, 7, HC_EFFECT_NONE, 605, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos04Frame0, gCardBos04Tiles, gBosPcBgPalettes, LOCALIZED(gCharacterNameCardOfSpades), gParasiteCageSmallCardFrame0, gParasiteCageSmallCardTiles, gParasiteCageSmallCardPalette,
        CARD_KIND_PARASITE_CAGE, 0x0, 8, HC_EFFECT_NONE, 605, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos04Frame0, gCardBos04Tiles, gBosPcBgPalettes, LOCALIZED(gCharacterNameCardOfSpades), gParasiteCageSmallCardFrame0, gParasiteCageSmallCardTiles, gParasiteCageSmallCardPalette,
        CARD_KIND_PARASITE_CAGE, 0x0, 9, HC_EFFECT_NONE, 605, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos05Frame0, gCardBos05Tiles, gCardBos05Palette, LOCALIZED(gCharacterNameCardOfSpades), gJafarSmallCardFrame0, gJafarSmallCardTiles, gJafarSmallCardPalette,
        CARD_KIND_JAFAR, 0x0, 0, HC_EFFECT_NONE, 615, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos05Frame0, gCardBos05Tiles, gCardBos05Palette, LOCALIZED(gCharacterNameCardOfSpades), gJafarSmallCardFrame0, gJafarSmallCardTiles, gJafarSmallCardPalette,
        CARD_KIND_JAFAR, 0x0, 1, HC_EFFECT_NONE, 615, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos05Frame0, gCardBos05Tiles, gCardBos05Palette, LOCALIZED(gCharacterNameCardOfSpades), gJafarSmallCardFrame0, gJafarSmallCardTiles, gJafarSmallCardPalette,
        CARD_KIND_JAFAR, 0x0, 2, HC_EFFECT_NONE, 615, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos05Frame0, gCardBos05Tiles, gCardBos05Palette, LOCALIZED(gCharacterNameCardOfSpades), gJafarSmallCardFrame0, gJafarSmallCardTiles, gJafarSmallCardPalette,
        CARD_KIND_JAFAR, 0x0, 3, HC_EFFECT_NONE, 615, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos05Frame0, gCardBos05Tiles, gCardBos05Palette, LOCALIZED(gCharacterNameCardOfSpades), gJafarSmallCardFrame0, gJafarSmallCardTiles, gJafarSmallCardPalette,
        CARD_KIND_JAFAR, 0x0, 4, HC_EFFECT_NONE, 615, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos05Frame0, gCardBos05Tiles, gCardBos05Palette, LOCALIZED(gCharacterNameCardOfSpades), gJafarSmallCardFrame0, gJafarSmallCardTiles, gJafarSmallCardPalette,
        CARD_KIND_JAFAR, 0x0, 5, HC_EFFECT_NONE, 615, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos05Frame0, gCardBos05Tiles, gCardBos05Palette, LOCALIZED(gCharacterNameCardOfSpades), gJafarSmallCardFrame0, gJafarSmallCardTiles, gJafarSmallCardPalette,
        CARD_KIND_JAFAR, 0x0, 6, HC_EFFECT_NONE, 615, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos05Frame0, gCardBos05Tiles, gCardBos05Palette, LOCALIZED(gCharacterNameCardOfSpades), gJafarSmallCardFrame0, gJafarSmallCardTiles, gJafarSmallCardPalette,
        CARD_KIND_JAFAR, 0x0, 7, HC_EFFECT_NONE, 615, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos05Frame0, gCardBos05Tiles, gCardBos05Palette, LOCALIZED(gCharacterNameCardOfSpades), gJafarSmallCardFrame0, gJafarSmallCardTiles, gJafarSmallCardPalette,
        CARD_KIND_JAFAR, 0x0, 8, HC_EFFECT_NONE, 615, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos05Frame0, gCardBos05Tiles, gCardBos05Palette, LOCALIZED(gCharacterNameCardOfSpades), gJafarSmallCardFrame0, gJafarSmallCardTiles, gJafarSmallCardPalette,
        CARD_KIND_JAFAR, 0x0, 9, HC_EFFECT_NONE, 615, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos06Frame0, gCardBos06Tiles, gCardBos06Palette, LOCALIZED(gCharacterNameCardOfSpades), gUrsulaSmallCardFrame0, gUrsulaSmallCardTiles, gUrsulaSmallCardPalette,
        CARD_KIND_URSULA, 0x0, 0, HC_EFFECT_NONE, 625, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos06Frame0, gCardBos06Tiles, gCardBos06Palette, LOCALIZED(gCharacterNameCardOfSpades), gUrsulaSmallCardFrame0, gUrsulaSmallCardTiles, gUrsulaSmallCardPalette,
        CARD_KIND_URSULA, 0x0, 1, HC_EFFECT_NONE, 625, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos06Frame0, gCardBos06Tiles, gCardBos06Palette, LOCALIZED(gCharacterNameCardOfSpades), gUrsulaSmallCardFrame0, gUrsulaSmallCardTiles, gUrsulaSmallCardPalette,
        CARD_KIND_URSULA, 0x0, 2, HC_EFFECT_NONE, 625, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos06Frame0, gCardBos06Tiles, gCardBos06Palette, LOCALIZED(gCharacterNameCardOfSpades), gUrsulaSmallCardFrame0, gUrsulaSmallCardTiles, gUrsulaSmallCardPalette,
        CARD_KIND_URSULA, 0x0, 3, HC_EFFECT_NONE, 625, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos06Frame0, gCardBos06Tiles, gCardBos06Palette, LOCALIZED(gCharacterNameCardOfSpades), gUrsulaSmallCardFrame0, gUrsulaSmallCardTiles, gUrsulaSmallCardPalette,
        CARD_KIND_URSULA, 0x0, 4, HC_EFFECT_NONE, 625, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos06Frame0, gCardBos06Tiles, gCardBos06Palette, LOCALIZED(gCharacterNameCardOfSpades), gUrsulaSmallCardFrame0, gUrsulaSmallCardTiles, gUrsulaSmallCardPalette,
        CARD_KIND_URSULA, 0x0, 5, HC_EFFECT_NONE, 625, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos06Frame0, gCardBos06Tiles, gCardBos06Palette, LOCALIZED(gCharacterNameCardOfSpades), gUrsulaSmallCardFrame0, gUrsulaSmallCardTiles, gUrsulaSmallCardPalette,
        CARD_KIND_URSULA, 0x0, 6, HC_EFFECT_NONE, 625, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos06Frame0, gCardBos06Tiles, gCardBos06Palette, LOCALIZED(gCharacterNameCardOfSpades), gUrsulaSmallCardFrame0, gUrsulaSmallCardTiles, gUrsulaSmallCardPalette,
        CARD_KIND_URSULA, 0x0, 7, HC_EFFECT_NONE, 625, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos06Frame0, gCardBos06Tiles, gCardBos06Palette, LOCALIZED(gCharacterNameCardOfSpades), gUrsulaSmallCardFrame0, gUrsulaSmallCardTiles, gUrsulaSmallCardPalette,
        CARD_KIND_URSULA, 0x0, 8, HC_EFFECT_NONE, 625, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos06Frame0, gCardBos06Tiles, gCardBos06Palette, LOCALIZED(gCharacterNameCardOfSpades), gUrsulaSmallCardFrame0, gUrsulaSmallCardTiles, gUrsulaSmallCardPalette,
        CARD_KIND_URSULA, 0x0, 9, HC_EFFECT_NONE, 625, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos07Frame0, gCardBos07Tiles, gCardBos07Palette, LOCALIZED(gCharacterNameCardOfSpades), gDragonMaleficentSmallCardFrame0, gDragonMaleficentSmallCardTiles, gDragonMaleficentSmallCardPalette,
        CARD_KIND_DRAGON_MALEFICENT, 0x0, 0, HC_EFFECT_NONE, 635, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos07Frame0, gCardBos07Tiles, gCardBos07Palette, LOCALIZED(gCharacterNameCardOfSpades), gDragonMaleficentSmallCardFrame0, gDragonMaleficentSmallCardTiles, gDragonMaleficentSmallCardPalette,
        CARD_KIND_DRAGON_MALEFICENT, 0x0, 1, HC_EFFECT_NONE, 635, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos07Frame0, gCardBos07Tiles, gCardBos07Palette, LOCALIZED(gCharacterNameCardOfSpades), gDragonMaleficentSmallCardFrame0, gDragonMaleficentSmallCardTiles, gDragonMaleficentSmallCardPalette,
        CARD_KIND_DRAGON_MALEFICENT, 0x0, 2, HC_EFFECT_NONE, 635, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos07Frame0, gCardBos07Tiles, gCardBos07Palette, LOCALIZED(gCharacterNameCardOfSpades), gDragonMaleficentSmallCardFrame0, gDragonMaleficentSmallCardTiles, gDragonMaleficentSmallCardPalette,
        CARD_KIND_DRAGON_MALEFICENT, 0x0, 3, HC_EFFECT_NONE, 635, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos07Frame0, gCardBos07Tiles, gCardBos07Palette, LOCALIZED(gCharacterNameCardOfSpades), gDragonMaleficentSmallCardFrame0, gDragonMaleficentSmallCardTiles, gDragonMaleficentSmallCardPalette,
        CARD_KIND_DRAGON_MALEFICENT, 0x0, 4, HC_EFFECT_NONE, 635, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos07Frame0, gCardBos07Tiles, gCardBos07Palette, LOCALIZED(gCharacterNameCardOfSpades), gDragonMaleficentSmallCardFrame0, gDragonMaleficentSmallCardTiles, gDragonMaleficentSmallCardPalette,
        CARD_KIND_DRAGON_MALEFICENT, 0x0, 5, HC_EFFECT_NONE, 635, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos07Frame0, gCardBos07Tiles, gCardBos07Palette, LOCALIZED(gCharacterNameCardOfSpades), gDragonMaleficentSmallCardFrame0, gDragonMaleficentSmallCardTiles, gDragonMaleficentSmallCardPalette,
        CARD_KIND_DRAGON_MALEFICENT, 0x0, 6, HC_EFFECT_NONE, 635, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos07Frame0, gCardBos07Tiles, gCardBos07Palette, LOCALIZED(gCharacterNameCardOfSpades), gDragonMaleficentSmallCardFrame0, gDragonMaleficentSmallCardTiles, gDragonMaleficentSmallCardPalette,
        CARD_KIND_DRAGON_MALEFICENT, 0x0, 7, HC_EFFECT_NONE, 635, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos07Frame0, gCardBos07Tiles, gCardBos07Palette, LOCALIZED(gCharacterNameCardOfSpades), gDragonMaleficentSmallCardFrame0, gDragonMaleficentSmallCardTiles, gDragonMaleficentSmallCardPalette,
        CARD_KIND_DRAGON_MALEFICENT, 0x0, 8, HC_EFFECT_NONE, 635, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos07Frame0, gCardBos07Tiles, gCardBos07Palette, LOCALIZED(gCharacterNameCardOfSpades), gDragonMaleficentSmallCardFrame0, gDragonMaleficentSmallCardTiles, gDragonMaleficentSmallCardPalette,
        CARD_KIND_DRAGON_MALEFICENT, 0x0, 9, HC_EFFECT_NONE, 635, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos08Frame0, gCardBos08Tiles, gCardBos08Palette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxia2SmallCardFrame0, gMarluxia2SmallCardTiles, gMarluxia2SmallCardPalette,
        CARD_KIND_MARLUXIA_2, 0x0, 0, HC_EFFECT_NONE, 645, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos08Frame0, gCardBos08Tiles, gCardBos08Palette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxia2SmallCardFrame0, gMarluxia2SmallCardTiles, gMarluxia2SmallCardPalette,
        CARD_KIND_MARLUXIA_2, 0x0, 1, HC_EFFECT_NONE, 645, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos08Frame0, gCardBos08Tiles, gCardBos08Palette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxia2SmallCardFrame0, gMarluxia2SmallCardTiles, gMarluxia2SmallCardPalette,
        CARD_KIND_MARLUXIA_2, 0x0, 2, HC_EFFECT_NONE, 645, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos08Frame0, gCardBos08Tiles, gCardBos08Palette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxia2SmallCardFrame0, gMarluxia2SmallCardTiles, gMarluxia2SmallCardPalette,
        CARD_KIND_MARLUXIA_2, 0x0, 3, HC_EFFECT_NONE, 645, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos08Frame0, gCardBos08Tiles, gCardBos08Palette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxia2SmallCardFrame0, gMarluxia2SmallCardTiles, gMarluxia2SmallCardPalette,
        CARD_KIND_MARLUXIA_2, 0x0, 4, HC_EFFECT_NONE, 645, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos08Frame0, gCardBos08Tiles, gCardBos08Palette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxia2SmallCardFrame0, gMarluxia2SmallCardTiles, gMarluxia2SmallCardPalette,
        CARD_KIND_MARLUXIA_2, 0x0, 5, HC_EFFECT_NONE, 645, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos08Frame0, gCardBos08Tiles, gCardBos08Palette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxia2SmallCardFrame0, gMarluxia2SmallCardTiles, gMarluxia2SmallCardPalette,
        CARD_KIND_MARLUXIA_2, 0x0, 6, HC_EFFECT_NONE, 645, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos08Frame0, gCardBos08Tiles, gCardBos08Palette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxia2SmallCardFrame0, gMarluxia2SmallCardTiles, gMarluxia2SmallCardPalette,
        CARD_KIND_MARLUXIA_2, 0x0, 7, HC_EFFECT_NONE, 645, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos08Frame0, gCardBos08Tiles, gCardBos08Palette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxia2SmallCardFrame0, gMarluxia2SmallCardTiles, gMarluxia2SmallCardPalette,
        CARD_KIND_MARLUXIA_2, 0x0, 8, HC_EFFECT_NONE, 645, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardBos08Frame0, gCardBos08Tiles, gCardBos08Palette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxia2SmallCardFrame0, gMarluxia2SmallCardTiles, gMarluxia2SmallCardPalette,
        CARD_KIND_MARLUXIA_2, 0x0, 9, HC_EFFECT_NONE, 645, CARD_CATEGORY_ENEMY, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gGimmickCardFrame0, gGimmickCardTiles, gGimmickCardPalette, LOCALIZED(gCharacterNameCardOfSpades), NULL, NULL, NULL,
        CARD_KIND_GIMMICK_0, CARD_DEF_FLAG_GIMMICK, 0, MOVE_GIMMICK_0, 655, CARD_CATEGORY_ITEM, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gGimmickCardFrame0, gGimmickCardTiles, gGimmickCardPalette, LOCALIZED(gCharacterNameCardOfSpades), NULL, NULL, NULL,
        CARD_KIND_GIMMICK_1, CARD_DEF_FLAG_GIMMICK, 0, MOVE_GIMMICK_1, 656, CARD_CATEGORY_ITEM, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gGimmickCardFrame0, gGimmickCardTiles, gGimmickCardPalette, LOCALIZED(gCharacterNameCardOfSpades), NULL, NULL, NULL,
        CARD_KIND_GIMMICK_2, CARD_DEF_FLAG_GIMMICK, 0, MOVE_GIMMICK_2, 657, CARD_CATEGORY_ITEM, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gGimmickCardFrame0, gGimmickCardTiles, gGimmickCardPalette, LOCALIZED(gCharacterNameCardOfSpades), NULL, NULL, NULL,
        CARD_KIND_GIMMICK_3, CARD_DEF_FLAG_GIMMICK, 0, MOVE_GIMMICK_3, 658, CARD_CATEGORY_ITEM, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gGimmickCardFrame0, gGimmickCardTiles, gGimmickCardPalette, LOCALIZED(gCharacterNameCardOfSpades), NULL, NULL, NULL,
        CARD_KIND_GIMMICK_4, CARD_DEF_FLAG_GIMMICK, 0, MOVE_GIMMICK_4, 659, CARD_CATEGORY_ITEM, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardWep20Frame0, gCardWep20Tiles, gCardWep20Palette, LOCALIZED(gCardNameSoulEater), gSoulEaterSmallCardFrame0, gSoulEaterSmallCardTiles, gSoulEaterSmallCardPalette,
        CARD_KIND_SOUL_EATER, 0x0, 0, MOVE_SOUL_EATER, 661, CARD_CATEGORY_ATTACK, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardWep20Frame0, gCardWep20Tiles, gCardWep20Palette, LOCALIZED(gCardNameSoulEater), gSoulEaterSmallCardFrame0, gSoulEaterSmallCardTiles, gSoulEaterSmallCardPalette,
        CARD_KIND_SOUL_EATER, 0x0, 1, MOVE_SOUL_EATER, 661, CARD_CATEGORY_ATTACK, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardWep20Frame0, gCardWep20Tiles, gCardWep20Palette, LOCALIZED(gCardNameSoulEater), gSoulEaterSmallCardFrame0, gSoulEaterSmallCardTiles, gSoulEaterSmallCardPalette,
        CARD_KIND_SOUL_EATER, 0x0, 2, MOVE_SOUL_EATER, 661, CARD_CATEGORY_ATTACK, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardWep20Frame0, gCardWep20Tiles, gCardWep20Palette, LOCALIZED(gCardNameSoulEater), gSoulEaterSmallCardFrame0, gSoulEaterSmallCardTiles, gSoulEaterSmallCardPalette,
        CARD_KIND_SOUL_EATER, 0x0, 3, MOVE_SOUL_EATER, 661, CARD_CATEGORY_ATTACK, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardWep20Frame0, gCardWep20Tiles, gCardWep20Palette, LOCALIZED(gCardNameSoulEater), gSoulEaterSmallCardFrame0, gSoulEaterSmallCardTiles, gSoulEaterSmallCardPalette,
        CARD_KIND_SOUL_EATER, 0x0, 4, MOVE_SOUL_EATER, 661, CARD_CATEGORY_ATTACK, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardWep20Frame0, gCardWep20Tiles, gCardWep20Palette, LOCALIZED(gCardNameSoulEater), gSoulEaterSmallCardFrame0, gSoulEaterSmallCardTiles, gSoulEaterSmallCardPalette,
        CARD_KIND_SOUL_EATER, 0x0, 5, MOVE_SOUL_EATER, 661, CARD_CATEGORY_ATTACK, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardWep20Frame0, gCardWep20Tiles, gCardWep20Palette, LOCALIZED(gCardNameSoulEater), gSoulEaterSmallCardFrame0, gSoulEaterSmallCardTiles, gSoulEaterSmallCardPalette,
        CARD_KIND_SOUL_EATER, 0x0, 6, MOVE_SOUL_EATER, 661, CARD_CATEGORY_ATTACK, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardWep20Frame0, gCardWep20Tiles, gCardWep20Palette, LOCALIZED(gCardNameSoulEater), gSoulEaterSmallCardFrame0, gSoulEaterSmallCardTiles, gSoulEaterSmallCardPalette,
        CARD_KIND_SOUL_EATER, 0x0, 7, MOVE_SOUL_EATER, 661, CARD_CATEGORY_ATTACK, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardWep20Frame0, gCardWep20Tiles, gCardWep20Palette, LOCALIZED(gCardNameSoulEater), gSoulEaterSmallCardFrame0, gSoulEaterSmallCardTiles, gSoulEaterSmallCardPalette,
        CARD_KIND_SOUL_EATER, 0x0, 8, MOVE_SOUL_EATER, 661, CARD_CATEGORY_ATTACK, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardWep20Frame0, gCardWep20Tiles, gCardWep20Palette, LOCALIZED(gCardNameSoulEater), gSoulEaterSmallCardFrame0, gSoulEaterSmallCardTiles, gSoulEaterSmallCardPalette,
        CARD_KIND_SOUL_EATER, 0x0, 9, MOVE_SOUL_EATER, 661, CARD_CATEGORY_ATTACK, 0, {5, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn15Frame0, gCardSmn15Tiles, gMickeyPalette, LOCALIZED(gCardNameKing), gTheKingSmallCardFrame0, gTheKingSmallCardTiles, gTheKingSmallCardPalette,
        CARD_KIND_THE_KING, CARD_DEF_FLAG_FRIEND, 0, MOVE_THE_KING, 671, CARD_CATEGORY_ITEM, 0, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn15Frame0, gCardSmn15Tiles, gMickeyPalette, LOCALIZED(gCardNameKing), gTheKingSmallCardFrame0, gTheKingSmallCardTiles, gTheKingSmallCardPalette,
        CARD_KIND_THE_KING, CARD_DEF_FLAG_FRIEND, 1, MOVE_THE_KING, 671, CARD_CATEGORY_ITEM, 0, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn15Frame0, gCardSmn15Tiles, gMickeyPalette, LOCALIZED(gCardNameKing), gTheKingSmallCardFrame0, gTheKingSmallCardTiles, gTheKingSmallCardPalette,
        CARD_KIND_THE_KING, CARD_DEF_FLAG_FRIEND, 2, MOVE_THE_KING, 671, CARD_CATEGORY_ITEM, 0, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn15Frame0, gCardSmn15Tiles, gMickeyPalette, LOCALIZED(gCardNameKing), gTheKingSmallCardFrame0, gTheKingSmallCardTiles, gTheKingSmallCardPalette,
        CARD_KIND_THE_KING, CARD_DEF_FLAG_FRIEND, 3, MOVE_THE_KING, 671, CARD_CATEGORY_ITEM, 0, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn15Frame0, gCardSmn15Tiles, gMickeyPalette, LOCALIZED(gCardNameKing), gTheKingSmallCardFrame0, gTheKingSmallCardTiles, gTheKingSmallCardPalette,
        CARD_KIND_THE_KING, CARD_DEF_FLAG_FRIEND, 4, MOVE_THE_KING, 671, CARD_CATEGORY_ITEM, 0, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn15Frame0, gCardSmn15Tiles, gMickeyPalette, LOCALIZED(gCardNameKing), gTheKingSmallCardFrame0, gTheKingSmallCardTiles, gTheKingSmallCardPalette,
        CARD_KIND_THE_KING, CARD_DEF_FLAG_FRIEND, 5, MOVE_THE_KING, 671, CARD_CATEGORY_ITEM, 0, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn15Frame0, gCardSmn15Tiles, gMickeyPalette, LOCALIZED(gCardNameKing), gTheKingSmallCardFrame0, gTheKingSmallCardTiles, gTheKingSmallCardPalette,
        CARD_KIND_THE_KING, CARD_DEF_FLAG_FRIEND, 6, MOVE_THE_KING, 671, CARD_CATEGORY_ITEM, 0, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn15Frame0, gCardSmn15Tiles, gMickeyPalette, LOCALIZED(gCardNameKing), gTheKingSmallCardFrame0, gTheKingSmallCardTiles, gTheKingSmallCardPalette,
        CARD_KIND_THE_KING, CARD_DEF_FLAG_FRIEND, 7, MOVE_THE_KING, 671, CARD_CATEGORY_ITEM, 0, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn15Frame0, gCardSmn15Tiles, gMickeyPalette, LOCALIZED(gCardNameKing), gTheKingSmallCardFrame0, gTheKingSmallCardTiles, gTheKingSmallCardPalette,
        CARD_KIND_THE_KING, CARD_DEF_FLAG_FRIEND, 8, MOVE_THE_KING, 671, CARD_CATEGORY_ITEM, 0, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn15Frame0, gCardSmn15Tiles, gMickeyPalette, LOCALIZED(gCardNameKing), gTheKingSmallCardFrame0, gTheKingSmallCardTiles, gTheKingSmallCardPalette,
        CARD_KIND_THE_KING, CARD_DEF_FLAG_FRIEND, 9, MOVE_THE_KING, 671, CARD_CATEGORY_ITEM, 0, {3, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09aPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudASmallCardPalette,
        CARD_KIND_CLOUD_A, 0x0, 0, MOVE_BOSS_A, 681, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09aPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudASmallCardPalette,
        CARD_KIND_CLOUD_A, 0x0, 1, MOVE_BOSS_A, 681, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09aPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudASmallCardPalette,
        CARD_KIND_CLOUD_A, 0x0, 2, MOVE_BOSS_A, 681, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09aPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudASmallCardPalette,
        CARD_KIND_CLOUD_A, 0x0, 3, MOVE_BOSS_A, 681, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09aPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudASmallCardPalette,
        CARD_KIND_CLOUD_A, 0x0, 4, MOVE_BOSS_A, 681, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09aPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudASmallCardPalette,
        CARD_KIND_CLOUD_A, 0x0, 5, MOVE_BOSS_A, 681, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09aPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudASmallCardPalette,
        CARD_KIND_CLOUD_A, 0x0, 6, MOVE_BOSS_A, 681, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09aPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudASmallCardPalette,
        CARD_KIND_CLOUD_A, 0x0, 7, MOVE_BOSS_A, 681, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09aPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudASmallCardPalette,
        CARD_KIND_CLOUD_A, 0x0, 8, MOVE_BOSS_A, 681, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09aPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudASmallCardPalette,
        CARD_KIND_CLOUD_A, 0x0, 9, MOVE_BOSS_A, 681, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09bPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudBSmallCardPalette,
        CARD_KIND_CLOUD_B, 0x0, 0, MOVE_BOSS_B, 691, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09bPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudBSmallCardPalette,
        CARD_KIND_CLOUD_B, 0x0, 1, MOVE_BOSS_B, 691, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09bPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudBSmallCardPalette,
        CARD_KIND_CLOUD_B, 0x0, 2, MOVE_BOSS_B, 691, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09bPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudBSmallCardPalette,
        CARD_KIND_CLOUD_B, 0x0, 3, MOVE_BOSS_B, 691, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09bPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudBSmallCardPalette,
        CARD_KIND_CLOUD_B, 0x0, 4, MOVE_BOSS_B, 691, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09bPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudBSmallCardPalette,
        CARD_KIND_CLOUD_B, 0x0, 5, MOVE_BOSS_B, 691, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09bPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudBSmallCardPalette,
        CARD_KIND_CLOUD_B, 0x0, 6, MOVE_BOSS_B, 691, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09bPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudBSmallCardPalette,
        CARD_KIND_CLOUD_B, 0x0, 7, MOVE_BOSS_B, 691, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09bPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudBSmallCardPalette,
        CARD_KIND_CLOUD_B, 0x0, 8, MOVE_BOSS_B, 691, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardSmn09Frame0, gCardSmn09Tiles, gCardSmn09bPalette, LOCALIZED(gCharacterNameCardOfSpades), gCloudSmallCardFrame0, gCloudSmallCardTiles, gCloudBSmallCardPalette,
        CARD_KIND_CLOUD_B, 0x0, 9, MOVE_BOSS_B, 691, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10aPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookASmallCardFrame0, gHookASmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_A, 0x0, 0, MOVE_BOSS_A, 701, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10aPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookASmallCardFrame0, gHookASmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_A, 0x0, 1, MOVE_BOSS_A, 701, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10aPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookASmallCardFrame0, gHookASmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_A, 0x0, 2, MOVE_BOSS_A, 701, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10aPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookASmallCardFrame0, gHookASmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_A, 0x0, 3, MOVE_BOSS_A, 701, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10aPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookASmallCardFrame0, gHookASmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_A, 0x0, 4, MOVE_BOSS_A, 701, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10aPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookASmallCardFrame0, gHookASmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_A, 0x0, 5, MOVE_BOSS_A, 701, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10aPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookASmallCardFrame0, gHookASmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_A, 0x0, 6, MOVE_BOSS_A, 701, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10aPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookASmallCardFrame0, gHookASmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_A, 0x0, 7, MOVE_BOSS_A, 701, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10aPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookASmallCardFrame0, gHookASmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_A, 0x0, 8, MOVE_BOSS_A, 701, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10aPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookASmallCardFrame0, gHookASmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_A, 0x0, 9, MOVE_BOSS_A, 701, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10bPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookBSmallCardFrame0, gHookBSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_B, 0x0, 0, MOVE_BOSS_B, 711, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10bPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookBSmallCardFrame0, gHookBSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_B, 0x0, 1, MOVE_BOSS_B, 711, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10bPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookBSmallCardFrame0, gHookBSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_B, 0x0, 2, MOVE_BOSS_B, 711, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10bPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookBSmallCardFrame0, gHookBSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_B, 0x0, 3, MOVE_BOSS_B, 711, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10bPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookBSmallCardFrame0, gHookBSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_B, 0x0, 4, MOVE_BOSS_B, 711, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10bPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookBSmallCardFrame0, gHookBSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_B, 0x0, 5, MOVE_BOSS_B, 711, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10bPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookBSmallCardFrame0, gHookBSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_B, 0x0, 6, MOVE_BOSS_B, 711, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10bPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookBSmallCardFrame0, gHookBSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_B, 0x0, 7, MOVE_BOSS_B, 711, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10bPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookBSmallCardFrame0, gHookBSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_B, 0x0, 8, MOVE_BOSS_B, 711, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10bPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookBSmallCardFrame0, gHookBSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_B, 0x0, 9, MOVE_BOSS_B, 711, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10cPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookCSmallCardFrame0, gHookCSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_C, 0x0, 0, MOVE_BOSS_C, 721, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10cPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookCSmallCardFrame0, gHookCSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_C, 0x0, 1, MOVE_BOSS_C, 721, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10cPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookCSmallCardFrame0, gHookCSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_C, 0x0, 2, MOVE_BOSS_C, 721, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10cPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookCSmallCardFrame0, gHookCSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_C, 0x0, 3, MOVE_BOSS_C, 721, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10cPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookCSmallCardFrame0, gHookCSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_C, 0x0, 4, MOVE_BOSS_C, 721, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10cPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookCSmallCardFrame0, gHookCSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_C, 0x0, 5, MOVE_BOSS_C, 721, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10cPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookCSmallCardFrame0, gHookCSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_C, 0x0, 6, MOVE_BOSS_C, 721, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10cPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookCSmallCardFrame0, gHookCSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_C, 0x0, 7, MOVE_BOSS_C, 721, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10cPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookCSmallCardFrame0, gHookCSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_C, 0x0, 8, MOVE_BOSS_C, 721, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10cPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookCSmallCardFrame0, gHookCSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_C, 0x0, 9, MOVE_BOSS_C, 721, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10dPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookSmallCardFrame0, gHookSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_D, 0x0, 0, MOVE_BOSS_D, 731, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10dPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookSmallCardFrame0, gHookSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_D, 0x0, 1, MOVE_BOSS_D, 731, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10dPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookSmallCardFrame0, gHookSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_D, 0x0, 2, MOVE_BOSS_D, 731, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10dPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookSmallCardFrame0, gHookSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_D, 0x0, 3, MOVE_BOSS_D, 731, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10dPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookSmallCardFrame0, gHookSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_D, 0x0, 4, MOVE_BOSS_D, 731, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10dPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookSmallCardFrame0, gHookSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_D, 0x0, 5, MOVE_BOSS_D, 731, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10dPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookSmallCardFrame0, gHookSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_D, 0x0, 6, MOVE_BOSS_D, 731, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10dPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookSmallCardFrame0, gHookSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_D, 0x0, 7, MOVE_BOSS_D, 731, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10dPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookSmallCardFrame0, gHookSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_D, 0x0, 8, MOVE_BOSS_D, 731, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos10Frame0, gCardBos10Tiles, gCardBos10dPalette, LOCALIZED(gCharacterNameCardOfSpades), gHookSmallCardFrame0, gHookSmallCardTiles, gHookVariantSmallCardPalette,
        CARD_KIND_HOOK_D, 0x0, 9, MOVE_BOSS_D, 731, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesASmallCardFrame0, gHadesASmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesASmallCardPalette,
#endif
        CARD_KIND_HADES_A, 0x0, 0, MOVE_BOSS_A, 741, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesASmallCardFrame0, gHadesASmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesASmallCardPalette,
#endif
        CARD_KIND_HADES_A, 0x0, 1, MOVE_BOSS_A, 741, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesASmallCardFrame0, gHadesASmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesASmallCardPalette,
#endif
        CARD_KIND_HADES_A, 0x0, 2, MOVE_BOSS_A, 741, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesASmallCardFrame0, gHadesASmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesASmallCardPalette,
#endif
        CARD_KIND_HADES_A, 0x0, 3, MOVE_BOSS_A, 741, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesASmallCardFrame0, gHadesASmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesASmallCardPalette,
#endif
        CARD_KIND_HADES_A, 0x0, 4, MOVE_BOSS_A, 741, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesASmallCardFrame0, gHadesASmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesASmallCardPalette,
#endif
        CARD_KIND_HADES_A, 0x0, 5, MOVE_BOSS_A, 741, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesASmallCardFrame0, gHadesASmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesASmallCardPalette,
#endif
        CARD_KIND_HADES_A, 0x0, 6, MOVE_BOSS_A, 741, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesASmallCardFrame0, gHadesASmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesASmallCardPalette,
#endif
        CARD_KIND_HADES_A, 0x0, 7, MOVE_BOSS_A, 741, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesASmallCardFrame0, gHadesASmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesASmallCardPalette,
#endif
        CARD_KIND_HADES_A, 0x0, 8, MOVE_BOSS_A, 741, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesASmallCardFrame0, gHadesASmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11aPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesASmallCardPalette,
#endif
        CARD_KIND_HADES_A, 0x0, 9, MOVE_BOSS_A, 741, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesBSmallCardFrame0, gHadesBSmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesBSmallCardPalette,
#endif
        CARD_KIND_HADES_B, 0x0, 0, MOVE_BOSS_B, 751, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesBSmallCardFrame0, gHadesBSmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesBSmallCardPalette,
#endif
        CARD_KIND_HADES_B, 0x0, 1, MOVE_BOSS_B, 751, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesBSmallCardFrame0, gHadesBSmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesBSmallCardPalette,
#endif
        CARD_KIND_HADES_B, 0x0, 2, MOVE_BOSS_B, 751, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesBSmallCardFrame0, gHadesBSmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesBSmallCardPalette,
#endif
        CARD_KIND_HADES_B, 0x0, 3, MOVE_BOSS_B, 751, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesBSmallCardFrame0, gHadesBSmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesBSmallCardPalette,
#endif
        CARD_KIND_HADES_B, 0x0, 4, MOVE_BOSS_B, 751, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesBSmallCardFrame0, gHadesBSmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesBSmallCardPalette,
#endif
        CARD_KIND_HADES_B, 0x0, 5, MOVE_BOSS_B, 751, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesBSmallCardFrame0, gHadesBSmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesBSmallCardPalette,
#endif
        CARD_KIND_HADES_B, 0x0, 6, MOVE_BOSS_B, 751, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesBSmallCardFrame0, gHadesBSmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesBSmallCardPalette,
#endif
        CARD_KIND_HADES_B, 0x0, 7, MOVE_BOSS_B, 751, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesBSmallCardFrame0, gHadesBSmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesBSmallCardPalette,
#endif
        CARD_KIND_HADES_B, 0x0, 8, MOVE_BOSS_B, 751, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, &gCharacterNameCardOfSpadesByLanguage, gHadesBSmallCardFrame0, gHadesBSmallCardTiles, gHadesASmallCardPalette,
#else
        gCardBos11Frame0, gCardBos11Tiles, gCardBos11bPalette, gCharacterNameCardOfSpades, gHadesSmallCardFrame0, gHadesSmallCardTiles, gHadesBSmallCardPalette,
#endif
        CARD_KIND_HADES_B, 0x0, 9, MOVE_BOSS_B, 751, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuASmallCardFrame0, gRikuASmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuASmallCardPalette,
#endif
        CARD_KIND_RIKU_A, 0x0, 0, MOVE_BOSS_A, 761, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuASmallCardFrame0, gRikuASmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuASmallCardPalette,
#endif
        CARD_KIND_RIKU_A, 0x0, 1, MOVE_BOSS_A, 761, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuASmallCardFrame0, gRikuASmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuASmallCardPalette,
#endif
        CARD_KIND_RIKU_A, 0x0, 2, MOVE_BOSS_A, 761, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuASmallCardFrame0, gRikuASmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuASmallCardPalette,
#endif
        CARD_KIND_RIKU_A, 0x0, 3, MOVE_BOSS_A, 761, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuASmallCardFrame0, gRikuASmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuASmallCardPalette,
#endif
        CARD_KIND_RIKU_A, 0x0, 4, MOVE_BOSS_A, 761, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuASmallCardFrame0, gRikuASmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuASmallCardPalette,
#endif
        CARD_KIND_RIKU_A, 0x0, 5, MOVE_BOSS_A, 761, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuASmallCardFrame0, gRikuASmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuASmallCardPalette,
#endif
        CARD_KIND_RIKU_A, 0x0, 6, MOVE_BOSS_A, 761, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuASmallCardFrame0, gRikuASmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuASmallCardPalette,
#endif
        CARD_KIND_RIKU_A, 0x0, 7, MOVE_BOSS_A, 761, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuASmallCardFrame0, gRikuASmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuASmallCardPalette,
#endif
        CARD_KIND_RIKU_A, 0x0, 8, MOVE_BOSS_A, 761, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuASmallCardFrame0, gRikuASmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12aPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuASmallCardPalette,
#endif
        CARD_KIND_RIKU_A, 0x0, 9, MOVE_BOSS_A, 761, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuBSmallCardFrame0, gRikuBSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuBSmallCardPalette,
#endif
        CARD_KIND_RIKU_B, 0x0, 0, MOVE_BOSS_B, 771, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuBSmallCardFrame0, gRikuBSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuBSmallCardPalette,
#endif
        CARD_KIND_RIKU_B, 0x0, 1, MOVE_BOSS_B, 771, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuBSmallCardFrame0, gRikuBSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuBSmallCardPalette,
#endif
        CARD_KIND_RIKU_B, 0x0, 2, MOVE_BOSS_B, 771, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuBSmallCardFrame0, gRikuBSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuBSmallCardPalette,
#endif
        CARD_KIND_RIKU_B, 0x0, 3, MOVE_BOSS_B, 771, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuBSmallCardFrame0, gRikuBSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuBSmallCardPalette,
#endif
        CARD_KIND_RIKU_B, 0x0, 4, MOVE_BOSS_B, 771, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuBSmallCardFrame0, gRikuBSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuBSmallCardPalette,
#endif
        CARD_KIND_RIKU_B, 0x0, 5, MOVE_BOSS_B, 771, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuBSmallCardFrame0, gRikuBSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuBSmallCardPalette,
#endif
        CARD_KIND_RIKU_B, 0x0, 6, MOVE_BOSS_B, 771, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuBSmallCardFrame0, gRikuBSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuBSmallCardPalette,
#endif
        CARD_KIND_RIKU_B, 0x0, 7, MOVE_BOSS_B, 771, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuBSmallCardFrame0, gRikuBSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuBSmallCardPalette,
#endif
        CARD_KIND_RIKU_B, 0x0, 8, MOVE_BOSS_B, 771, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuBSmallCardFrame0, gRikuBSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12bPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuBSmallCardPalette,
#endif
        CARD_KIND_RIKU_B, 0x0, 9, MOVE_BOSS_B, 771, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuCSmallCardFrame0, gRikuCSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuCSmallCardPalette,
#endif
        CARD_KIND_RIKU_C, 0x0, 0, MOVE_BOSS_C, 781, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuCSmallCardFrame0, gRikuCSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuCSmallCardPalette,
#endif
        CARD_KIND_RIKU_C, 0x0, 1, MOVE_BOSS_C, 781, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuCSmallCardFrame0, gRikuCSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuCSmallCardPalette,
#endif
        CARD_KIND_RIKU_C, 0x0, 2, MOVE_BOSS_C, 781, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuCSmallCardFrame0, gRikuCSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuCSmallCardPalette,
#endif
        CARD_KIND_RIKU_C, 0x0, 3, MOVE_BOSS_C, 781, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuCSmallCardFrame0, gRikuCSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuCSmallCardPalette,
#endif
        CARD_KIND_RIKU_C, 0x0, 4, MOVE_BOSS_C, 781, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuCSmallCardFrame0, gRikuCSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuCSmallCardPalette,
#endif
        CARD_KIND_RIKU_C, 0x0, 5, MOVE_BOSS_C, 781, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuCSmallCardFrame0, gRikuCSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuCSmallCardPalette,
#endif
        CARD_KIND_RIKU_C, 0x0, 6, MOVE_BOSS_C, 781, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuCSmallCardFrame0, gRikuCSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuCSmallCardPalette,
#endif
        CARD_KIND_RIKU_C, 0x0, 7, MOVE_BOSS_C, 781, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuCSmallCardFrame0, gRikuCSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuCSmallCardPalette,
#endif
        CARD_KIND_RIKU_C, 0x0, 8, MOVE_BOSS_C, 781, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuCSmallCardFrame0, gRikuCSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12cPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuCSmallCardPalette,
#endif
        CARD_KIND_RIKU_C, 0x0, 9, MOVE_BOSS_C, 781, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuDSmallCardFrame0, gRikuDSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuDSmallCardPalette,
#endif
        CARD_KIND_RIKU_D, 0x0, 0, MOVE_BOSS_D, 791, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuDSmallCardFrame0, gRikuDSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuDSmallCardPalette,
#endif
        CARD_KIND_RIKU_D, 0x0, 1, MOVE_BOSS_D, 791, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuDSmallCardFrame0, gRikuDSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuDSmallCardPalette,
#endif
        CARD_KIND_RIKU_D, 0x0, 2, MOVE_BOSS_D, 791, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuDSmallCardFrame0, gRikuDSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuDSmallCardPalette,
#endif
        CARD_KIND_RIKU_D, 0x0, 3, MOVE_BOSS_D, 791, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuDSmallCardFrame0, gRikuDSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuDSmallCardPalette,
#endif
        CARD_KIND_RIKU_D, 0x0, 4, MOVE_BOSS_D, 791, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuDSmallCardFrame0, gRikuDSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuDSmallCardPalette,
#endif
        CARD_KIND_RIKU_D, 0x0, 5, MOVE_BOSS_D, 791, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuDSmallCardFrame0, gRikuDSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuDSmallCardPalette,
#endif
        CARD_KIND_RIKU_D, 0x0, 6, MOVE_BOSS_D, 791, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuDSmallCardFrame0, gRikuDSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuDSmallCardPalette,
#endif
        CARD_KIND_RIKU_D, 0x0, 7, MOVE_BOSS_D, 791, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuDSmallCardFrame0, gRikuDSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuDSmallCardPalette,
#endif
        CARD_KIND_RIKU_D, 0x0, 8, MOVE_BOSS_D, 791, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, &gCharacterNameCardOfSpadesByLanguage, gRikuDSmallCardFrame0, gRikuDSmallCardTiles, gRikuASmallCardPalette,
#else
        gCardBos12Frame0, gCardBos12Tiles, gCardBos12dPalette, gCharacterNameCardOfSpades, gRikuSmallCardFrame0, gRikuSmallCardTiles, gRikuDSmallCardPalette,
#endif
        CARD_KIND_RIKU_D, 0x0, 9, MOVE_BOSS_D, 791, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelASmallCardFrame0, gAxelASmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelASmallCardPalette,
#endif
        CARD_KIND_AXEL_A, 0x0, 0, MOVE_BOSS_A, 801, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelASmallCardFrame0, gAxelASmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelASmallCardPalette,
#endif
        CARD_KIND_AXEL_A, 0x0, 1, MOVE_BOSS_A, 801, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelASmallCardFrame0, gAxelASmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelASmallCardPalette,
#endif
        CARD_KIND_AXEL_A, 0x0, 2, MOVE_BOSS_A, 801, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelASmallCardFrame0, gAxelASmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelASmallCardPalette,
#endif
        CARD_KIND_AXEL_A, 0x0, 3, MOVE_BOSS_A, 801, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelASmallCardFrame0, gAxelASmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelASmallCardPalette,
#endif
        CARD_KIND_AXEL_A, 0x0, 4, MOVE_BOSS_A, 801, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelASmallCardFrame0, gAxelASmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelASmallCardPalette,
#endif
        CARD_KIND_AXEL_A, 0x0, 5, MOVE_BOSS_A, 801, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelASmallCardFrame0, gAxelASmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelASmallCardPalette,
#endif
        CARD_KIND_AXEL_A, 0x0, 6, MOVE_BOSS_A, 801, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelASmallCardFrame0, gAxelASmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelASmallCardPalette,
#endif
        CARD_KIND_AXEL_A, 0x0, 7, MOVE_BOSS_A, 801, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelASmallCardFrame0, gAxelASmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelASmallCardPalette,
#endif
        CARD_KIND_AXEL_A, 0x0, 8, MOVE_BOSS_A, 801, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelASmallCardFrame0, gAxelASmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13aPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelASmallCardPalette,
#endif
        CARD_KIND_AXEL_A, 0x0, 9, MOVE_BOSS_A, 801, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelBSmallCardFrame0, gAxelBSmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelBSmallCardPalette,
#endif
        CARD_KIND_AXEL_B, 0x0, 0, MOVE_BOSS_B, 811, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelBSmallCardFrame0, gAxelBSmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelBSmallCardPalette,
#endif
        CARD_KIND_AXEL_B, 0x0, 1, MOVE_BOSS_B, 811, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelBSmallCardFrame0, gAxelBSmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelBSmallCardPalette,
#endif
        CARD_KIND_AXEL_B, 0x0, 2, MOVE_BOSS_B, 811, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelBSmallCardFrame0, gAxelBSmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelBSmallCardPalette,
#endif
        CARD_KIND_AXEL_B, 0x0, 3, MOVE_BOSS_B, 811, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelBSmallCardFrame0, gAxelBSmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelBSmallCardPalette,
#endif
        CARD_KIND_AXEL_B, 0x0, 4, MOVE_BOSS_B, 811, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelBSmallCardFrame0, gAxelBSmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelBSmallCardPalette,
#endif
        CARD_KIND_AXEL_B, 0x0, 5, MOVE_BOSS_B, 811, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelBSmallCardFrame0, gAxelBSmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelBSmallCardPalette,
#endif
        CARD_KIND_AXEL_B, 0x0, 6, MOVE_BOSS_B, 811, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelBSmallCardFrame0, gAxelBSmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelBSmallCardPalette,
#endif
        CARD_KIND_AXEL_B, 0x0, 7, MOVE_BOSS_B, 811, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelBSmallCardFrame0, gAxelBSmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelBSmallCardPalette,
#endif
        CARD_KIND_AXEL_B, 0x0, 8, MOVE_BOSS_B, 811, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, &gCharacterNameCardOfSpadesByLanguage, gAxelBSmallCardFrame0, gAxelBSmallCardTiles, gAxelASmallCardPalette,
#else
        gCardBos13Frame0, gCardBos13Tiles, gCardBos13bPalette, gCharacterNameCardOfSpades, gAxelSmallCardFrame0, gAxelSmallCardTiles, gAxelBSmallCardPalette,
#endif
        CARD_KIND_AXEL_B, 0x0, 9, MOVE_BOSS_B, 811, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneASmallCardFrame0, gLarxeneASmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneASmallCardPalette,
#endif
        CARD_KIND_LARXENE_A, 0x0, 0, MOVE_BOSS_A, 821, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneASmallCardFrame0, gLarxeneASmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneASmallCardPalette,
#endif
        CARD_KIND_LARXENE_A, 0x0, 1, MOVE_BOSS_A, 821, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneASmallCardFrame0, gLarxeneASmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneASmallCardPalette,
#endif
        CARD_KIND_LARXENE_A, 0x0, 2, MOVE_BOSS_A, 821, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneASmallCardFrame0, gLarxeneASmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneASmallCardPalette,
#endif
        CARD_KIND_LARXENE_A, 0x0, 3, MOVE_BOSS_A, 821, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneASmallCardFrame0, gLarxeneASmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneASmallCardPalette,
#endif
        CARD_KIND_LARXENE_A, 0x0, 4, MOVE_BOSS_A, 821, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneASmallCardFrame0, gLarxeneASmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneASmallCardPalette,
#endif
        CARD_KIND_LARXENE_A, 0x0, 5, MOVE_BOSS_A, 821, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneASmallCardFrame0, gLarxeneASmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneASmallCardPalette,
#endif
        CARD_KIND_LARXENE_A, 0x0, 6, MOVE_BOSS_A, 821, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneASmallCardFrame0, gLarxeneASmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneASmallCardPalette,
#endif
        CARD_KIND_LARXENE_A, 0x0, 7, MOVE_BOSS_A, 821, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneASmallCardFrame0, gLarxeneASmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneASmallCardPalette,
#endif
        CARD_KIND_LARXENE_A, 0x0, 8, MOVE_BOSS_A, 821, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneASmallCardFrame0, gLarxeneASmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14aPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneASmallCardPalette,
#endif
        CARD_KIND_LARXENE_A, 0x0, 9, MOVE_BOSS_A, 821, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneBSmallCardFrame0, gLarxeneBSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneBSmallCardPalette,
#endif
        CARD_KIND_LARXENE_B, 0x0, 0, MOVE_BOSS_B, 831, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneBSmallCardFrame0, gLarxeneBSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneBSmallCardPalette,
#endif
        CARD_KIND_LARXENE_B, 0x0, 1, MOVE_BOSS_B, 831, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneBSmallCardFrame0, gLarxeneBSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneBSmallCardPalette,
#endif
        CARD_KIND_LARXENE_B, 0x0, 2, MOVE_BOSS_B, 831, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneBSmallCardFrame0, gLarxeneBSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneBSmallCardPalette,
#endif
        CARD_KIND_LARXENE_B, 0x0, 3, MOVE_BOSS_B, 831, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneBSmallCardFrame0, gLarxeneBSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneBSmallCardPalette,
#endif
        CARD_KIND_LARXENE_B, 0x0, 4, MOVE_BOSS_B, 831, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneBSmallCardFrame0, gLarxeneBSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneBSmallCardPalette,
#endif
        CARD_KIND_LARXENE_B, 0x0, 5, MOVE_BOSS_B, 831, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneBSmallCardFrame0, gLarxeneBSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneBSmallCardPalette,
#endif
        CARD_KIND_LARXENE_B, 0x0, 6, MOVE_BOSS_B, 831, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneBSmallCardFrame0, gLarxeneBSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneBSmallCardPalette,
#endif
        CARD_KIND_LARXENE_B, 0x0, 7, MOVE_BOSS_B, 831, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneBSmallCardFrame0, gLarxeneBSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneBSmallCardPalette,
#endif
        CARD_KIND_LARXENE_B, 0x0, 8, MOVE_BOSS_B, 831, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneBSmallCardFrame0, gLarxeneBSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14bPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneBSmallCardPalette,
#endif
        CARD_KIND_LARXENE_B, 0x0, 9, MOVE_BOSS_B, 831, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneCSmallCardFrame0, gLarxeneCSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneCSmallCardPalette,
#endif
        CARD_KIND_LARXENE_C, 0x0, 0, MOVE_BOSS_C, 841, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneCSmallCardFrame0, gLarxeneCSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneCSmallCardPalette,
#endif
        CARD_KIND_LARXENE_C, 0x0, 1, MOVE_BOSS_C, 841, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneCSmallCardFrame0, gLarxeneCSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneCSmallCardPalette,
#endif
        CARD_KIND_LARXENE_C, 0x0, 2, MOVE_BOSS_C, 841, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneCSmallCardFrame0, gLarxeneCSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneCSmallCardPalette,
#endif
        CARD_KIND_LARXENE_C, 0x0, 3, MOVE_BOSS_C, 841, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneCSmallCardFrame0, gLarxeneCSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneCSmallCardPalette,
#endif
        CARD_KIND_LARXENE_C, 0x0, 4, MOVE_BOSS_C, 841, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneCSmallCardFrame0, gLarxeneCSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneCSmallCardPalette,
#endif
        CARD_KIND_LARXENE_C, 0x0, 5, MOVE_BOSS_C, 841, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneCSmallCardFrame0, gLarxeneCSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneCSmallCardPalette,
#endif
        CARD_KIND_LARXENE_C, 0x0, 6, MOVE_BOSS_C, 841, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneCSmallCardFrame0, gLarxeneCSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneCSmallCardPalette,
#endif
        CARD_KIND_LARXENE_C, 0x0, 7, MOVE_BOSS_C, 841, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneCSmallCardFrame0, gLarxeneCSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneCSmallCardPalette,
#endif
        CARD_KIND_LARXENE_C, 0x0, 8, MOVE_BOSS_C, 841, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#ifdef VERSION_EU
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, &gCharacterNameCardOfSpadesByLanguage, gLarxeneCSmallCardFrame0, gLarxeneCSmallCardTiles, gLarxeneASmallCardPalette,
#else
        gCardBos14Frame0, gCardBos14Tiles, gCardBos14cPalette, gCharacterNameCardOfSpades, gLarxeneSmallCardFrame0, gLarxeneSmallCardTiles, gLarxeneCSmallCardPalette,
#endif
        CARD_KIND_LARXENE_C, 0x0, 9, MOVE_BOSS_C, 841, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15aPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenASmallCardFrame0, gVexenASmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_A, 0x0, 0, MOVE_BOSS_A, 851, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15aPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenASmallCardFrame0, gVexenASmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_A, 0x0, 1, MOVE_BOSS_A, 851, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15aPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenASmallCardFrame0, gVexenASmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_A, 0x0, 2, MOVE_BOSS_A, 851, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15aPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenASmallCardFrame0, gVexenASmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_A, 0x0, 3, MOVE_BOSS_A, 851, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15aPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenASmallCardFrame0, gVexenASmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_A, 0x0, 4, MOVE_BOSS_A, 851, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15aPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenASmallCardFrame0, gVexenASmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_A, 0x0, 5, MOVE_BOSS_A, 851, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15aPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenASmallCardFrame0, gVexenASmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_A, 0x0, 6, MOVE_BOSS_A, 851, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15aPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenASmallCardFrame0, gVexenASmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_A, 0x0, 7, MOVE_BOSS_A, 851, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15aPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenASmallCardFrame0, gVexenASmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_A, 0x0, 8, MOVE_BOSS_A, 851, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15aPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenASmallCardFrame0, gVexenASmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_A, 0x0, 9, MOVE_BOSS_A, 851, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15bPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenBSmallCardFrame0, gVexenBSmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_B, 0x0, 0, MOVE_BOSS_B, 861, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15bPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenBSmallCardFrame0, gVexenBSmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_B, 0x0, 1, MOVE_BOSS_B, 861, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15bPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenBSmallCardFrame0, gVexenBSmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_B, 0x0, 2, MOVE_BOSS_B, 861, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15bPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenBSmallCardFrame0, gVexenBSmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_B, 0x0, 3, MOVE_BOSS_B, 861, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15bPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenBSmallCardFrame0, gVexenBSmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_B, 0x0, 4, MOVE_BOSS_B, 861, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15bPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenBSmallCardFrame0, gVexenBSmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_B, 0x0, 5, MOVE_BOSS_B, 861, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15bPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenBSmallCardFrame0, gVexenBSmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_B, 0x0, 6, MOVE_BOSS_B, 861, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15bPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenBSmallCardFrame0, gVexenBSmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_B, 0x0, 7, MOVE_BOSS_B, 861, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15bPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenBSmallCardFrame0, gVexenBSmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_B, 0x0, 8, MOVE_BOSS_B, 861, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos15Frame0, gCardBos15Tiles, gCardBos15bPalette, LOCALIZED(gCharacterNameCardOfSpades), gVexenBSmallCardFrame0, gVexenBSmallCardTiles, gVexenVariantSmallCardPalette,
        CARD_KIND_VEXEN_B, 0x0, 9, MOVE_BOSS_B, 861, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16aPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaASmallCardFrame0, gMarluxiaASmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_A, 0x0, 0, MOVE_BOSS_A, 871, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16aPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaASmallCardFrame0, gMarluxiaASmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_A, 0x0, 1, MOVE_BOSS_A, 871, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16aPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaASmallCardFrame0, gMarluxiaASmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_A, 0x0, 2, MOVE_BOSS_A, 871, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16aPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaASmallCardFrame0, gMarluxiaASmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_A, 0x0, 3, MOVE_BOSS_A, 871, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16aPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaASmallCardFrame0, gMarluxiaASmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_A, 0x0, 4, MOVE_BOSS_A, 871, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16aPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaASmallCardFrame0, gMarluxiaASmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_A, 0x0, 5, MOVE_BOSS_A, 871, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16aPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaASmallCardFrame0, gMarluxiaASmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_A, 0x0, 6, MOVE_BOSS_A, 871, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16aPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaASmallCardFrame0, gMarluxiaASmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_A, 0x0, 7, MOVE_BOSS_A, 871, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16aPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaASmallCardFrame0, gMarluxiaASmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_A, 0x0, 8, MOVE_BOSS_A, 871, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16aPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaASmallCardFrame0, gMarluxiaASmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_A, 0x0, 9, MOVE_BOSS_A, 871, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16bPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaBSmallCardFrame0, gMarluxiaBSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_B, 0x0, 0, MOVE_BOSS_B, 881, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16bPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaBSmallCardFrame0, gMarluxiaBSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_B, 0x0, 1, MOVE_BOSS_B, 881, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16bPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaBSmallCardFrame0, gMarluxiaBSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_B, 0x0, 2, MOVE_BOSS_B, 881, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16bPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaBSmallCardFrame0, gMarluxiaBSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_B, 0x0, 3, MOVE_BOSS_B, 881, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16bPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaBSmallCardFrame0, gMarluxiaBSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_B, 0x0, 4, MOVE_BOSS_B, 881, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16bPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaBSmallCardFrame0, gMarluxiaBSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_B, 0x0, 5, MOVE_BOSS_B, 881, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16bPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaBSmallCardFrame0, gMarluxiaBSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_B, 0x0, 6, MOVE_BOSS_B, 881, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16bPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaBSmallCardFrame0, gMarluxiaBSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_B, 0x0, 7, MOVE_BOSS_B, 881, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16bPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaBSmallCardFrame0, gMarluxiaBSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_B, 0x0, 8, MOVE_BOSS_B, 881, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16bPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaBSmallCardFrame0, gMarluxiaBSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_B, 0x0, 9, MOVE_BOSS_B, 881, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16cPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaCSmallCardFrame0, gMarluxiaCSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_C, 0x0, 0, MOVE_BOSS_C, 891, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16cPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaCSmallCardFrame0, gMarluxiaCSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_C, 0x0, 1, MOVE_BOSS_C, 891, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16cPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaCSmallCardFrame0, gMarluxiaCSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_C, 0x0, 2, MOVE_BOSS_C, 891, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16cPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaCSmallCardFrame0, gMarluxiaCSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_C, 0x0, 3, MOVE_BOSS_C, 891, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16cPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaCSmallCardFrame0, gMarluxiaCSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_C, 0x0, 4, MOVE_BOSS_C, 891, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16cPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaCSmallCardFrame0, gMarluxiaCSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_C, 0x0, 5, MOVE_BOSS_C, 891, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16cPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaCSmallCardFrame0, gMarluxiaCSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_C, 0x0, 6, MOVE_BOSS_C, 891, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16cPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaCSmallCardFrame0, gMarluxiaCSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_C, 0x0, 7, MOVE_BOSS_C, 891, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16cPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaCSmallCardFrame0, gMarluxiaCSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_C, 0x0, 8, MOVE_BOSS_C, 891, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos16Frame0, gCardBos16Tiles, gCardBos16cPalette, LOCALIZED(gCharacterNameCardOfSpades), gMarluxiaCSmallCardFrame0, gMarluxiaCSmallCardTiles, gMarluxiaVariantSmallCardPalette,
        CARD_KIND_MARLUXIA_C, 0x0, 9, MOVE_BOSS_C, 891, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17aPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusASmallCardFrame0, gLexaeusASmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_A, 0x0, 0, MOVE_BOSS_A, 901, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17aPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusASmallCardFrame0, gLexaeusASmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_A, 0x0, 1, MOVE_BOSS_A, 901, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17aPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusASmallCardFrame0, gLexaeusASmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_A, 0x0, 2, MOVE_BOSS_A, 901, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17aPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusASmallCardFrame0, gLexaeusASmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_A, 0x0, 3, MOVE_BOSS_A, 901, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17aPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusASmallCardFrame0, gLexaeusASmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_A, 0x0, 4, MOVE_BOSS_A, 901, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17aPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusASmallCardFrame0, gLexaeusASmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_A, 0x0, 5, MOVE_BOSS_A, 901, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17aPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusASmallCardFrame0, gLexaeusASmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_A, 0x0, 6, MOVE_BOSS_A, 901, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17aPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusASmallCardFrame0, gLexaeusASmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_A, 0x0, 7, MOVE_BOSS_A, 901, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17aPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusASmallCardFrame0, gLexaeusASmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_A, 0x0, 8, MOVE_BOSS_A, 901, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17aPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusASmallCardFrame0, gLexaeusASmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_A, 0x0, 9, MOVE_BOSS_A, 901, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17bPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusBSmallCardFrame0, gLexaeusBSmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_B, 0x0, 0, MOVE_BOSS_B, 911, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17bPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusBSmallCardFrame0, gLexaeusBSmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_B, 0x0, 1, MOVE_BOSS_B, 911, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17bPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusBSmallCardFrame0, gLexaeusBSmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_B, 0x0, 2, MOVE_BOSS_B, 911, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17bPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusBSmallCardFrame0, gLexaeusBSmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_B, 0x0, 3, MOVE_BOSS_B, 911, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17bPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusBSmallCardFrame0, gLexaeusBSmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_B, 0x0, 4, MOVE_BOSS_B, 911, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17bPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusBSmallCardFrame0, gLexaeusBSmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_B, 0x0, 5, MOVE_BOSS_B, 911, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17bPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusBSmallCardFrame0, gLexaeusBSmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_B, 0x0, 6, MOVE_BOSS_B, 911, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17bPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusBSmallCardFrame0, gLexaeusBSmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_B, 0x0, 7, MOVE_BOSS_B, 911, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17bPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusBSmallCardFrame0, gLexaeusBSmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_B, 0x0, 8, MOVE_BOSS_B, 911, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17bPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusBSmallCardFrame0, gLexaeusBSmallCardTiles, gLexaeusVariantSmallCardPalette,
        CARD_KIND_LEXAEUS_B, 0x0, 9, MOVE_BOSS_B, 911, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17cPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusSmallCardFrame0, gLexaeusSmallCardTiles, gLexaeusCSmallCardPalette,
        CARD_KIND_LEXAEUS_C, 0x0, 0, MOVE_BOSS_C, 921, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17cPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusSmallCardFrame0, gLexaeusSmallCardTiles, gLexaeusCSmallCardPalette,
        CARD_KIND_LEXAEUS_C, 0x0, 1, MOVE_BOSS_C, 921, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17cPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusSmallCardFrame0, gLexaeusSmallCardTiles, gLexaeusCSmallCardPalette,
        CARD_KIND_LEXAEUS_C, 0x0, 2, MOVE_BOSS_C, 921, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17cPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusSmallCardFrame0, gLexaeusSmallCardTiles, gLexaeusCSmallCardPalette,
        CARD_KIND_LEXAEUS_C, 0x0, 3, MOVE_BOSS_C, 921, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17cPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusSmallCardFrame0, gLexaeusSmallCardTiles, gLexaeusCSmallCardPalette,
        CARD_KIND_LEXAEUS_C, 0x0, 4, MOVE_BOSS_C, 921, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17cPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusSmallCardFrame0, gLexaeusSmallCardTiles, gLexaeusCSmallCardPalette,
        CARD_KIND_LEXAEUS_C, 0x0, 5, MOVE_BOSS_C, 921, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17cPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusSmallCardFrame0, gLexaeusSmallCardTiles, gLexaeusCSmallCardPalette,
        CARD_KIND_LEXAEUS_C, 0x0, 6, MOVE_BOSS_C, 921, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17cPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusSmallCardFrame0, gLexaeusSmallCardTiles, gLexaeusCSmallCardPalette,
        CARD_KIND_LEXAEUS_C, 0x0, 7, MOVE_BOSS_C, 921, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17cPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusSmallCardFrame0, gLexaeusSmallCardTiles, gLexaeusCSmallCardPalette,
        CARD_KIND_LEXAEUS_C, 0x0, 8, MOVE_BOSS_C, 921, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos17Frame0, gCardBos17Tiles, gCardBos17cPalette, LOCALIZED(gCharacterNameCardOfSpades), gLexaeusSmallCardFrame0, gLexaeusSmallCardTiles, gLexaeusCSmallCardPalette,
        CARD_KIND_LEXAEUS_C, 0x0, 9, MOVE_BOSS_C, 921, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18aPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemASmallCardFrame0, gAnsemASmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_A, 0x0, 0, MOVE_BOSS_A, 931, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18aPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemASmallCardFrame0, gAnsemASmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_A, 0x0, 1, MOVE_BOSS_A, 931, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18aPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemASmallCardFrame0, gAnsemASmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_A, 0x0, 2, MOVE_BOSS_A, 931, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18aPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemASmallCardFrame0, gAnsemASmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_A, 0x0, 3, MOVE_BOSS_A, 931, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18aPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemASmallCardFrame0, gAnsemASmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_A, 0x0, 4, MOVE_BOSS_A, 931, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18aPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemASmallCardFrame0, gAnsemASmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_A, 0x0, 5, MOVE_BOSS_A, 931, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18aPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemASmallCardFrame0, gAnsemASmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_A, 0x0, 6, MOVE_BOSS_A, 931, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18aPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemASmallCardFrame0, gAnsemASmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_A, 0x0, 7, MOVE_BOSS_A, 931, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18aPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemASmallCardFrame0, gAnsemASmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_A, 0x0, 8, MOVE_BOSS_A, 931, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18aPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemASmallCardFrame0, gAnsemASmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_A, 0x0, 9, MOVE_BOSS_A, 931, CARD_CATEGORY_MAGIC, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18bPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemBSmallCardFrame0, gAnsemBSmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_B, 0x0, 0, MOVE_BOSS_B, 941, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18bPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemBSmallCardFrame0, gAnsemBSmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_B, 0x0, 1, MOVE_BOSS_B, 941, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18bPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemBSmallCardFrame0, gAnsemBSmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_B, 0x0, 2, MOVE_BOSS_B, 941, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18bPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemBSmallCardFrame0, gAnsemBSmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_B, 0x0, 3, MOVE_BOSS_B, 941, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18bPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemBSmallCardFrame0, gAnsemBSmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_B, 0x0, 4, MOVE_BOSS_B, 941, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18bPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemBSmallCardFrame0, gAnsemBSmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_B, 0x0, 5, MOVE_BOSS_B, 941, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18bPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemBSmallCardFrame0, gAnsemBSmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_B, 0x0, 6, MOVE_BOSS_B, 941, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18bPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemBSmallCardFrame0, gAnsemBSmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_B, 0x0, 7, MOVE_BOSS_B, 941, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18bPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemBSmallCardFrame0, gAnsemBSmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_B, 0x0, 8, MOVE_BOSS_B, 941, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
    {
        gCardBos18Frame0, gCardBos18Tiles, gCardBos18bPalette, LOCALIZED(gCharacterNameCardOfSpades), gAnsemBSmallCardFrame0, gAnsemBSmallCardTiles, gAnsemVariantSmallCardPalette,
        CARD_KIND_ANSEM_B, 0x0, 9, MOVE_BOSS_B, 941, CARD_CATEGORY_ATTACK, 0, {0, 0, 0, 0, 0, 0},
    },
};

const HcEffectDef gHcEffectDefs[55] = {
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
        0,
        0,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
        0,
        2,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        1,
#else
        33,
#endif
        20,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        2,
#else
        1,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        3,
#else
        9,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        4,
#else
        7,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        5,
#else
        3,
#endif
        5,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        6,
#else
        22,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        7,
#else
        32,
#endif
        30,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        8,
#else
        30,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        9,
#else
        28,
#endif
#ifdef VERSION_EU
        1,
#else
        2,
#endif
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
        10,
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
        11,
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
        12,
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        13,
#else
        24,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        14,
#else
        43,
#endif
        5,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        15,
#else
        6,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        16,
#else
        8,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        17,
#else
        41,
#endif
        10,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        18,
#else
        16,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        19,
#else
        20,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        20,
#else
        21,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
        21,
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        22,
#else
        36,
#endif
        10,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        23,
#else
        15,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        24,
#else
        23,
#endif
#ifdef VERSION_EU
        3,
#else
        1,
#endif
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        25,
#else
        38,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        26,
#else
        44,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        27,
#else
        42,
#endif
        10,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        28,
#else
        17,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        29,
#else
        27,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        30,
#else
        2,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
        31,
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
        32,
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        33,
#else
        31,
#endif
        30,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        34,
#else
        19,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        35,
#else
        4,
#endif
        2,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        36,
#else
        26,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        37,
#else
        14,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        38,
#else
        13,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        39,
#else
        29,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        40,
#else
        37,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        41,
#else
        25,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        42,
#else
        39,
#endif
        30,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        43,
#else
        40,
#endif
        30,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        44,
#else
        34,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        45,
#else
        35,
#endif
        5,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        46,
#else
        45,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        47,
#else
        46,
#endif
        10,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
        48,
        50,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        49,
#else
        47,
#endif
        15,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        50,
#else
        5,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        51,
#else
        34,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
#ifdef VERSION_JP
        52,
#else
        18,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gHcEffectNameTilesByLanguage,
#else
        gHcEffectNameTiles,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        sizeof(gHcEffectNameTiles),
#elif defined(VERSION_US)
        sizeof(gHcEffectNameTiles),
#endif
#endif
#ifdef VERSION_EU
        gHcEffectNameSpritesByLanguage,
#else
        gHcEffectNameFrames,
#endif
        0,
        1,
    },
};

const SpriteFrameResourceDef gStockNameSprites[106] = {
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_EU
        640,
#else
        384,
#endif
        0,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        512,
#endif
        2,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        576,
#endif
        4,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_EU
        640,
#else
        384,
#endif
#ifdef VERSION_JP
        10,
#else
        6,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        448,
#endif
#ifdef VERSION_JP
        6,
#else
        10,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
#ifdef VERSION_JP
        0,
#else
        1,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
#ifdef VERSION_JP
        576,
#else
        640,
#endif
#ifdef VERSION_JP
        1,
#else
        3,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        448,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        512,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        576,
#endif
        5,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        512,
#endif
#ifdef VERSION_JP
        11,
#else
        7,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        512,
#endif
        8,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        512,
#endif
        9,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        448,
#endif
#ifdef VERSION_JP
        7,
#else
        11,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
        2,
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
        1,
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
#ifdef VERSION_JP
        384,
#else
        640,
#endif
        0,
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
#ifdef VERSION_JP
        384,
#else
        640,
#endif
        0,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_JP
        512,
#else
        640,
#endif
#ifdef VERSION_JP
        12,
#else
        14,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_JP
        512,
#else
        640,
#endif
#ifdef VERSION_JP
        12,
#else
        14,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        704,
#elif defined(VERSION_US)
        512,
#endif
#ifdef VERSION_JP
        17,
#else
        15,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        704,
#elif defined(VERSION_US)
        512,
#endif
#ifdef VERSION_JP
        17,
#else
        15,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
#ifdef VERSION_JP
        19,
#else
        20,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
#ifdef VERSION_JP
        19,
#else
        20,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        448,
#else
        640,
#endif
#ifdef VERSION_JP
        20,
#else
        21,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        448,
#else
        640,
#endif
#ifdef VERSION_JP
        20,
#else
        21,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
#ifdef VERSION_JP
        42,
#else
        16,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
#ifdef VERSION_JP
        42,
#else
        16,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
#ifdef VERSION_JP
        18,
#else
        17,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
#ifdef VERSION_JP
        18,
#else
        17,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        576,
#else
        640,
#endif
#ifdef VERSION_JP
        16,
#else
        19,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
#ifdef VERSION_JP
        15,
#else
        18,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
#ifdef VERSION_JP
        6,
#else
        3,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
#ifdef VERSION_JP
        6,
#else
        3,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
#ifdef VERSION_JP
        3,
#else
        5,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
#ifdef VERSION_JP
        3,
#else
        5,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
#ifdef VERSION_JP
        7,
#else
        4,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
#ifdef VERSION_JP
        7,
#else
        4,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
#ifdef VERSION_JP
        5,
#else
        6,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
#ifdef VERSION_JP
        5,
#else
        6,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
#ifdef VERSION_JP
        4,
#else
        7,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameFriendTilesByLanguage,
#else
        gStockNameFriendTiles,
#endif
#ifdef VERSION_EU
        gStockNameFriendSpritesByLanguage,
#else
        gStockNameFriendFrames,
#endif
        640,
#ifdef VERSION_JP
        4,
#else
        7,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMmMiracleTilesByLanguage,
#else
        gStockNameMmMiracleTiles,
#endif
#ifdef VERSION_EU
        gStockNameMmMiracleSpritesByLanguage,
#else
        gStockNameMmMiracleFrames,
#endif
        640,
        0,
    },
    {
#ifdef VERSION_EU
        gStockNameMmMiracleTilesByLanguage,
#else
        gStockNameMmMiracleTiles,
#endif
#ifdef VERSION_EU
        gStockNameMmMiracleSpritesByLanguage,
#else
        gStockNameMmMiracleFrames,
#endif
        640,
        0,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        512,
#elif defined(VERSION_US)
        448,
#endif
#ifdef VERSION_JP
        13,
#else
        12,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        512,
#elif defined(VERSION_US)
        448,
#endif
#ifdef VERSION_JP
        14,
#else
        13,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
#ifdef VERSION_JP
        8,
#else
        0,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
#ifdef VERSION_JP
        5,
#else
        2,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
#ifdef VERSION_JP
        576,
#else
        640,
#endif
#ifdef VERSION_JP
        2,
#else
        4,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
#ifdef VERSION_JP
        7,
#else
        5,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
#ifdef VERSION_JP
        4,
#else
        6,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
#ifdef VERSION_JP
        6,
#else
        7,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
#ifdef VERSION_JP
        3,
#else
        8,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        384,
#else
        640,
#endif
#ifdef VERSION_JP
        21,
#else
        22,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
#ifdef VERSION_JP
        22,
#else
        23,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        448,
#else
        640,
#endif
#ifdef VERSION_JP
        23,
#else
        24,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        512,
#else
        640,
#endif
#ifdef VERSION_JP
        24,
#else
        25,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
        25,
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
        9,
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
        10,
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
        11,
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
        12,
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
        13,
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
        14,
    },
    {
#ifdef VERSION_EU
        gStockNameAttackTilesByLanguage,
#else
        gStockNameAttackTiles,
#endif
#ifdef VERSION_EU
        gStockNameAttackSpritesByLanguage,
#else
        gStockNameAttackFrames,
#endif
        640,
        15,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
        26,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        448,
#else
        640,
#endif
        27,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
        28,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
        0,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
        29,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
        30,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
        31,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
        32,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
        33,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
        34,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        640,
        35,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
        704,
        36,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        512,
#else
        640,
#endif
        37,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        320,
#else
        640,
#endif
        38,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        512,
#else
        640,
#endif
        39,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        448,
#else
        640,
#endif
        40,
    },
    {
#ifdef VERSION_EU
        gStockNameMagicTilesByLanguage,
#else
        gStockNameMagicTiles,
#endif
#ifdef VERSION_EU
        gStockNameMagicSpritesByLanguage,
#else
        gStockNameMagicFrames,
#endif
#ifdef VERSION_US
        512,
#else
        640,
#endif
        41,
    },
    {
#ifdef VERSION_EU
        gStockNameRikuTilesByLanguage,
#else
        gStockNameRikuTiles,
#endif
#ifdef VERSION_EU
        gStockNameRikuSpritesByLanguage,
#else
        gStockNameRikuFrames,
#endif
        640,
#ifdef VERSION_JP
        0,
#else
        2,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameRikuTilesByLanguage,
#else
        gStockNameRikuTiles,
#endif
#ifdef VERSION_EU
        gStockNameRikuSpritesByLanguage,
#else
        gStockNameRikuFrames,
#endif
        640,
#ifdef VERSION_JP
        1,
#else
        0,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameRikuTilesByLanguage,
#else
        gStockNameRikuTiles,
#endif
#ifdef VERSION_EU
        gStockNameRikuSpritesByLanguage,
#else
        gStockNameRikuFrames,
#endif
        640,
#ifdef VERSION_JP
        2,
#else
        1,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
        0,
    },
    {
#ifdef VERSION_EU
        gStockNameWorldBossTilesByLanguage,
#else
        gStockNameWorldBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameWorldBossSpritesByLanguage,
#else
        gStockNameWorldBossFrames,
#endif
        640,
        0,
    },
    {
#ifdef VERSION_EU
        gStockNameWorldBossTilesByLanguage,
#else
        gStockNameWorldBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameWorldBossSpritesByLanguage,
#else
        gStockNameWorldBossFrames,
#endif
        640,
        1,
    },
    {
#ifdef VERSION_EU
        gStockNameWorldBossTilesByLanguage,
#else
        gStockNameWorldBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameWorldBossSpritesByLanguage,
#else
        gStockNameWorldBossFrames,
#endif
        640,
        2,
    },
    {
#ifdef VERSION_EU
        gStockNameWorldBossTilesByLanguage,
#else
        gStockNameWorldBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameWorldBossSpritesByLanguage,
#else
        gStockNameWorldBossFrames,
#endif
        640,
        3,
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        1,
#else
        2,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameWorldBossTilesByLanguage,
#else
        gStockNameWorldBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameWorldBossSpritesByLanguage,
#else
        gStockNameWorldBossFrames,
#endif
        640,
        4,
    },
    {
#ifdef VERSION_EU
        gStockNameWorldBossTilesByLanguage,
#else
        gStockNameWorldBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameWorldBossSpritesByLanguage,
#else
        gStockNameWorldBossFrames,
#endif
        640,
        5,
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        2,
#else
        10,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        3,
#else
        4,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        4,
#else
        7,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
        5,
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        6,
#else
        11,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        7,
#else
        3,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        8,
#else
        1,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        9,
#else
        8,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        10,
#else
        9,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_EU
        13,
#else
        12,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        13,
#else
        14,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        11,
#else
        12,
#endif
    },
    {
#ifdef VERSION_EU
        gStockNameBossTilesByLanguage,
#else
        gStockNameBossTiles,
#endif
#ifdef VERSION_EU
        gStockNameBossSpritesByLanguage,
#else
        gStockNameBossFrames,
#endif
        640,
#ifdef VERSION_JP
        14,
#else
        6,
#endif
    },
};

#ifdef VERSION_EU
void* gHcEffectNameTilesByLanguage[5] = { gHcEffectNameTiles, gHcEffectNameFrenchTiles, gHcEffectNameGermanTiles, gHcEffectNameItalianTiles, gHcEffectNameSpanishTiles };
void** gHcEffectNameSpritesByLanguage[5] = { gHcEffectNameFrames, gHcEffectNameFrenchFrames, gHcEffectNameGermanFrames, gHcEffectNameItalianFrames, gHcEffectNameSpanishFrames };
void* gStockNameAttackTilesByLanguage[5] = { gStockNameAttackTiles, gStockNameAttackFrenchTiles, gStockNameAttackGermanTiles, gStockNameAttackItalianTiles, gStockNameAttackSpanishTiles };
void** gStockNameAttackSpritesByLanguage[5] = { gStockNameAttackFrames, gStockNameAttackFrenchFrames, gStockNameAttackGermanFrames, gStockNameAttackItalianFrames, gStockNameAttackSpanishFrames };
void* gStockNameMagicTilesByLanguage[5] = { gStockNameMagicTiles, gStockNameMagicFrenchTiles, gStockNameMagicGermanTiles, gStockNameMagicItalianTiles, gStockNameMagicSpanishTiles };
void** gStockNameMagicSpritesByLanguage[5] = { gStockNameMagicFrames, gStockNameMagicFrenchFrames, gStockNameMagicGermanFrames, gStockNameMagicItalianFrames, gStockNameMagicSpanishFrames };
void* gStockNameFriendTilesByLanguage[5] = { gStockNameFriendTiles, gStockNameFriendFrenchTiles, gStockNameFriendGermanTiles, gStockNameFriendItalianTiles, gStockNameFriendSpanishTiles };
void** gStockNameFriendSpritesByLanguage[5] = { gStockNameFriendFrames, gStockNameFriendFrenchFrames, gStockNameFriendGermanFrames, gStockNameFriendItalianFrames, gStockNameFriendSpanishFrames };
void* gStockNameMmMiracleTilesByLanguage[5] = { gStockNameMmMiracleTiles, gStockNameMmMiracleFrenchTiles, gStockNameMmMiracleGermanTiles, gStockNameMmMiracleItalianTiles, gStockNameMmMiracleSpanishTiles };
void** gStockNameMmMiracleSpritesByLanguage[5] = { gStockNameMmMiracleFrames, gStockNameMmMiracleFrenchFrames, gStockNameMmMiracleGermanFrames, gStockNameMmMiracleItalianFrames, gStockNameMmMiracleSpanishFrames };
void* gStockNameRikuTilesByLanguage[5] = { gStockNameRikuTiles, gStockNameRikuFrenchTiles, gStockNameRikuGermanTiles, gStockNameRikuItalianTiles, gStockNameRikuSpanishTiles };
void** gStockNameRikuSpritesByLanguage[5] = { gStockNameRikuFrames, gStockNameRikuFrenchFrames, gStockNameRikuGermanFrames, gStockNameRikuItalianFrames, gStockNameRikuSpanishFrames };
void* gStockNameBossTilesByLanguage[5] = { gStockNameBossTiles, gStockNameBossFrenchTiles, gStockNameBossGermanTiles, gStockNameBossItalianTiles, gStockNameBossSpanishTiles };
void** gStockNameBossSpritesByLanguage[5] = { gStockNameBossFrames, gStockNameBossFrenchFrames, gStockNameBossGermanFrames, gStockNameBossItalianFrames, gStockNameBossSpanishFrames };
void* gStockNameWorldBossTilesByLanguage[5] = { gStockNameWorldBossTiles, gStockNameWorldBossFrenchTiles, gStockNameWorldBossGermanTiles, gStockNameWorldBossItalianTiles, gStockNameWorldBossSpanishTiles };
void** gStockNameWorldBossSpritesByLanguage[5] = { gStockNameWorldBossFrames, gStockNameWorldBossFrenchFrames, gStockNameWorldBossGermanFrames, gStockNameWorldBossItalianFrames, gStockNameWorldBossSpanishFrames };
#endif

u16 GetCardCpCost(u16 cardId) {
    s32 n;
    u16 cpCost;
    CardStat* stat;

    if (cardId & CARD_FLAG_PREMIUM) {
        return gCardDefs[cardId & CARD_ID_MASK].cpCost;
    }

    if ((cardId & CARD_ID_MASK) <= CARD_ID_LAST_VALUED) {
        stat = (CardStat*)&gCardDefs[cardId & CARD_ID_MASK].kind;
        n = stat->value;

        if (n == 0) {
            n = 10;
        }

        n--;
        cpCost = stat->cpCost;
        cpCost += (cpCost / 10) * n;
        return cpCost;
    }

    return gCardDefs[cardId & CARD_ID_MASK].cpCost;
}

u16 GetCardMooglePointValue(u16 cardId) {
    u16 points;

    if ((cardId & CARD_FLAG_PREMIUM) == 0) {
        points = GetCardCpCost(cardId) / 5 * 2;
    } else {
        points = GetCardCpCost(cardId & CARD_ID_MASK) / 5 * 2 + 10;
    }

    return points;
}
