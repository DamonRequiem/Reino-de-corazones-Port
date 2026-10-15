/**
 * boss_card_data.c
 * Enemy Card Deck Tables
 */

#include "card_ids.h"
#include "types.h"

static const s32 sShadowCardIds[3] = {
    450, 451, 452,
};

static const s32 sSoldierCardIds[3] = {
    CARD_SOLDIER_1, 454, 455,
};

static const s32 sRedNocturneCardIds[3] = {
    CARD_RED_NOCTURNE_1, CARD_RED_NOCTURNE_2, CARD_RED_NOCTURNE_4,
};

static const s32 sBlueRhapsodyCardIds[3] = {
    CARD_BLUE_RHAPSODY_1, CARD_BLUE_RHAPSODY_2, CARD_BLUE_RHAPSODY_4,
};

static const s32 sYellowOperaCardIds[3] = {
    CARD_YELLOW_OPERA_1, CARD_YELLOW_OPERA_2, CARD_YELLOW_OPERA_4,
};

static const s32 sGreenRequiemCardIds[3] = {
    CARD_GREEN_REQUIEM_1, CARD_GREEN_REQUIEM_2, CARD_GREEN_REQUIEM_4,
};

static const s32 sLargeBodyCardIds[3] = {
    CARD_LARGE_BODY_1, CARD_LARGE_BODY_3, CARD_LARGE_BODY_4,
};

static const s32 sBarrelSpiderCardIds[3] = {
    486, 487, 488,
};

static const s32 sWizardCardIds[3] = {
    CARD_WIZARD_3, CARD_WIZARD_1, CARD_WIZARD_7,
};

const s32 gRedNocturneCardId = CARD_RED_NOCTURNE_1;

static const s32 sDarksideCardIds[10] = {
    565, 566, 567, 568, 569, 570, 571, 572, 573, 574,
};

static const s32 sSeaNeonCardIds[3] = {
    492, 493, 494,
};

static const s32 sPowerwildCardIds[3] = {
    471, 472, 473,
};

static const s32 sBouncywildCardIds[3] = {
    474, 475, 476,
};

static const s32 sBanditCardIds[3] = {
    CARD_BANDIT_1, 481, 482,
};

static const s32 sSearchGhostCardIds[3] = {
    CARD_SEARCH_GHOST_1, 490, 491,
};

static const s32 sScrewdiverCardIds[3] = {
    CARD_SCREWDIVER_1, 496, 497,
};

static const s32 sWightKnightCardIds[3] = {
    CARD_WIGHT_KNIGHT_2, 502, 503,
};

static const s32 sGargoyleCardIds[3] = {
    CARD_GARGOYLE_3, 505, 506,
};

static const s32 sPirateCardIds[3] = {
    CARD_PIRATE_1, 508, 509,
};

static const s32 sDarkballCardIds[3] = {
    CARD_DARKBALL_2, CARD_DARKBALL_4, CARD_DARKBALL_6,
};

static const s32 sFatBanditCardIds[3] = {
    CARD_FAT_BANDIT_3, CARD_FAT_BANDIT_1, CARD_FAT_BANDIT_6,
};

static const s32 sAquatankCardIds[3] = {
    CARD_AQUATANK_2, CARD_AQUATANK_1, CARD_AQUATANK_7,
};

static const s32 sDefenderCardIds[3] = {
    CARD_DEFENDER_5, CARD_DEFENDER_1, CARD_DEFENDER_9,
};

static const s32 sGuardArmorCardIds[10] = {
    575, 576, 577, 578, 579, 580, 581, 582, 583, 584,
};

static const s32 sTrickmasterCardIds[10] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603, 604,
};

static const s32 sNeoshadowCardIds[3] = {
    CARD_NEOSHADOW_7, CARD_NEOSHADOW_2, CARD_NEOSHADOW_8,
};

static const s32 sCardSoldierSpadeCardIds[3] = {
    CARD_CARD_SOLDIER_1, 549, 550,
};

static const s32 sCardSoldierHeartCardIds[3] = {
    CARD_CARD_SOLDIER_2, 546, 547,
};

static const s32 sWhiteMushroomCardIds = CARD_WHITE_MUSHROOM_2;

static const s32 sBlackFungusCardIds[3] = {
    529, 530, 531,
};

static const s32 sBlackFungusCardIds2[3] = {
    529, 530, 531,
};

static const s32 sAirPirateCardIds[3] = {
    CARD_AIR_PIRATE_3, 511, 512,
};

static const s32 sAirSoldierCardIds[3] = {
    CARD_AIR_SOLDIER_3, 478, 479,
};

static const s32 sWyvernCardIds[3] = {
    CARD_WYVERN_4, 520, 521,
};

static const s32 sTornadoStepCardIds[3] = {
    CARD_TORNADO_STEP_2, CARD_TORNADO_STEP_4, CARD_TORNADO_STEP_6,
};

static const s32 sCrescendoCardIds[3] = {
    CARD_CRESCENDO_2, CARD_CRESCENDO_4, CARD_CRESCENDO_6,
};

static const s32 sCreeperPlantCardIds[3] = {
    CARD_CREEPER_PLANT_2, CARD_CREEPER_PLANT_4, CARD_CREEPER_PLANT_6,
};

static const s32 sJafarCardIds[10] = {
    615, 616, 617, 618, 619, 620, 621, 622, 623, 624,
};

static const s32 sUrsulaCardIds[10] = {
    625, 626, 627, 628, 629, 630, 631, 632, 633, 634,
};

static const s32 sParasiteCageCardIds[10] = {
    605, 606, 607, 608, 609, 610, 611, 612, 613, 614,
};

static const s32 sDragonMaleficentCardIds[10] = {
    635, 636, 637, 638, 639, 640, 641, 642, 643, 644,
};

static const s32 sOogieBoogieCardIds[10] = {
    585, 586, 587, 588, 589, 590, 591, 592, 593, 594,
};

static const s32 sMarluxia2CardIds[10] = {
    645, 646, 647, 648, 649, 650, 651, 652, 653, 654,
};

static const s32 sLeonCardIds[10] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603, 604,
};

static const s32 sHookCardIds[9] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603,
};

static const s32 sCloudCardIds[9] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603,
};

static const s32 sHadesCardIds[9] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603,
};

static const s32 sRikuReplicaCardIds[9] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603,
};

static const s32 sAxelCardIds[9] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603,
};

static const s32 sLarxeneCardIds[9] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603,
};

static const s32 sVexenCardIds[9] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603,
};

static const s32 sMarluxiaCardIds[9] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603,
};

static const s32 sAnsemCardIds[9] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603,
};

static const s32 sLexaeusCardIds[9] = {
    595, 596, 597, 598, 599, 600, 601, 602, 603,
};

const s32* gEnemyCardIds[54] = {
    sShadowCardIds,
    sRedNocturneCardIds,
    sBlueRhapsodyCardIds,
    sYellowOperaCardIds,
    sGreenRequiemCardIds,
    sSeaNeonCardIds,
    &sWhiteMushroomCardIds,
    sBlackFungusCardIds,
    sBlackFungusCardIds2,
    sSoldierCardIds,
    sPowerwildCardIds,
    sBouncywildCardIds,
    sAirSoldierCardIds,
    sBanditCardIds,
    sBarrelSpiderCardIds,
    sSearchGhostCardIds,
    sScrewdiverCardIds,
    sWightKnightCardIds,
    sGargoyleCardIds,
    sPirateCardIds,
    sAirPirateCardIds,
    sDarkballCardIds,
    sWyvernCardIds,
    sWizardCardIds,
    sNeoshadowCardIds,
    sLargeBodyCardIds,
    sFatBanditCardIds,
    sAquatankCardIds,
    sDefenderCardIds,
    sTornadoStepCardIds,
    sCrescendoCardIds,
    sCreeperPlantCardIds,
    sGuardArmorCardIds,
    sJafarCardIds,
    sTrickmasterCardIds,
    sUrsulaCardIds,
    sParasiteCageCardIds,
    sDragonMaleficentCardIds,
    sDarksideCardIds,
    sOogieBoogieCardIds,
    sMarluxia2CardIds,
    sLeonCardIds,
    sHookCardIds,
    sCloudCardIds,
    sHadesCardIds,
    sRikuReplicaCardIds,
    sCardSoldierSpadeCardIds,
    sCardSoldierHeartCardIds,
    sAxelCardIds,
    sLarxeneCardIds,
    sVexenCardIds,
    sMarluxiaCardIds,
    sAnsemCardIds,
    sLexaeusCardIds,
};

const u8 gEnemyCardCounts[54] = {
    3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 3, 3, 9, 9, 9, 9, 9, 0,
};
