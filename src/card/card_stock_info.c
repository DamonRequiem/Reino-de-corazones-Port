/**
 * card_stock_info.c
 * Card Help Text and Sleight Info
 */

#include "msg_localized_data.h"
#include "system_state.h"
#include "player_progression.h"
#include "m4a_song.h"
#include "game_state.h"
#include "fade.h"
#include "obj_api.h"
#include "engine_math.h"
#include "taskpool.h"
#include "card.h"
#include "card_help_data.h"
#include "sprites_level_up.h"
#include "songs.h"
#include "card_help_text.h"
#include "player_progression_types.h"
#include "status.h"
#include <stddef.h>
#include "types.h"
#include "card_stock_info.h"
#include "sprite_palettes.h"
#include "card_label_data.h"

#if defined(VERSION_US)
static const CardHelpDef sFiraHelpDef = {
    gFiraHelpTexts,
    2,
};
#endif

#if defined(VERSION_US)
static const CardHelpDef sBlizzaraHelpDef = {
    gBlizzaraHelpTexts,
    2,
};
#endif

#if defined(VERSION_JP)
static const CardHelpDef sFiraHelpDef = {
    gFiraHelpTexts,
    2,
};
#endif

#if defined(VERSION_JP)
#include "card_help_pages_head.inc"
#endif
#if defined(VERSION_JP)
static const CardHelpDef sBlizzaraHelpDef = {
    gBlizzaraHelpTexts,
    2,
};
#endif

#if defined(VERSION_JP)
#include "card_help_pages.inc"
#endif
#if defined(VERSION_JP)
static const CardHelpDef sSecretHelpDef = {
    gSecretHelpTexts,
    2,
};
#endif

static const CardHelpDef sThundaraHelpDef = {
    gThundaraHelpTexts,
    2,
};

static const CardHelpDef sCuraHelpDef = {
    gCuraHelpTexts,
    2,
};

static const CardHelpDef sStopraHelpDef = {
    gStopraHelpTexts,
    2,
};

static const CardHelpDef sSonicBladeHelpDef = {
    gSonicBladeHelpTexts,
#if defined(VERSION_US) || defined(VERSION_EU)
    3,
#elif defined(VERSION_JP)
    2,
#endif
};

static const CardHelpDef sStrikeRaidHelpDef = {
    gStrikeRaidHelpTexts,
    2,
};

#if defined(VERSION_EU)
static const CardHelpDef sFiraHelpDef = {
    gFiraHelpTexts,
    2,
};
#endif

static const CardHelpDef sFiragaHelpDef = {
    gFiragaHelpTexts,
    2,
};

#if defined(VERSION_EU)
static const CardHelpDef sBlizzaraHelpDef = {
    gBlizzaraHelpTexts,
    2,
};
#endif

static const CardHelpDef sBlizzagaHelpDef = {
    gBlizzagaHelpTexts,
    2,
};

static const CardHelpDef sThundagaHelpDef = {
    gThundagaHelpTexts,
    2,
};

static const CardHelpDef sCuragaHelpDef = {
    gCuragaHelpTexts,
    2,
};

static const CardHelpDef sGraviraHelpDef = {
    gGraviraHelpTexts,
    2,
};

static const CardHelpDef sGravigaHelpDef = {
    gGravigaHelpTexts,
    2,
};

static const CardHelpDef sStopgaHelpDef = {
    gStopgaHelpTexts,
    2,
};

static const CardHelpDef sGoofyChargeHelpDef = {
    gGoofyChargeHelpTexts,
    2,
};

static const CardHelpDef sGoofyTornadoHelpDef = {
    gGoofyTornadoHelpTexts,
    2,
};

static const CardHelpDef sMagicHelpDef = {
    gMagicHelpTexts,
    4,
};

static const CardHelpDef sMagicPairHelpDef = {
    gMagicPairHelpTexts,
    4,
};

static const CardHelpDef sProudRoarHelpDef = {
    gProudRoarHelpTexts,
    4,
};

static const CardHelpDef sProudRoarPairHelpDef = {
    gProudRoarPairHelpTexts,
    4,
};

static const CardHelpDef sShowtimeHelpDef = {
    gShowtimeHelpTexts,
    4,
};

static const CardHelpDef sShowtimePairHelpDef = {
    gShowtimePairHelpTexts,
    4,
};

static const CardHelpDef sParadiseHelpDef = {
    gParadiseHelpTexts,
    4,
};

static const CardHelpDef sParadisePairHelpDef = {
    gParadisePairHelpTexts,
    4,
};

static const CardHelpDef sSplashHelpDef = {
    gSplashHelpTexts,
    4,
};

static const CardHelpDef sSplashPairHelpDef = {
    gSplashPairHelpTexts,
    4,
};

static const CardHelpDef sTwinkleHelpDef = {
    gTwinkleHelpTexts,
    4,
};

static const CardHelpDef sTwinklePairHelpDef = {
    gTwinklePairHelpTexts,
    4,
};

static const CardHelpDef sFlareBreathHelpDef = {
    gFlareBreathHelpTexts,
    4,
};

static const CardHelpDef sFlareBreathPairHelpDef = {
    gFlareBreathPairHelpTexts,
    4,
};

static const CardHelpDef sOmnislashHelpDef = {
    gOmnislashHelpTexts,
    2,
};

static const CardHelpDef sCrossSlashHelpDef = {
    gCrossSlashHelpTexts,
    2,
};

static const CardHelpDef sSandstormHelpDef = {
    gSandstormHelpTexts,
    4,
};

static const CardHelpDef sSandstormPairHelpDef = {
    gSandstormPairHelpTexts,
    4,
};

static const CardHelpDef sSpiralWaveHelpDef = {
    gSpiralWaveHelpTexts,
    4,
};

static const CardHelpDef sSpiralWavePairHelpDef = {
    gSpiralWavePairHelpTexts,
    4,
};

static const CardHelpDef sSurpriseHelpDef = {
    gSurpriseHelpTexts,
    4,
};

static const CardHelpDef sSurprisePairHelpDef = {
    gSurprisePairHelpTexts,
    4,
};

static const CardHelpDef sHummingbirdHelpDef = {
    gHummingbirdHelpTexts,
    4,
};

static const CardHelpDef sHummingbirdPairHelpDef = {
    gHummingbirdPairHelpTexts,
    4,
};

static const CardHelpDef sFerociousLungeHelpDef = {
    gFerociousLungeHelpTexts,
    4,
};

static const CardHelpDef sFerociousLungePairHelpDef = {
    gFerociousLungePairHelpTexts,
    4,
};

static const CardHelpDef sMmMiracleHelpDef = {
    gMmMiracleHelpTexts,
    4,
};

static const CardHelpDef sMmMiraclePairHelpDef = {
    gMmMiraclePairHelpTexts,
#if defined(VERSION_US) || defined(VERSION_EU)
    4,
#elif defined(VERSION_JP)
    2,
#endif
};

static const CardHelpDef sAeroraHelpDef = {
    gAeroraHelpTexts,
    2,
};

static const CardHelpDef sAerogaHelpDef = {
    gAerogaHelpTexts,
    2,
};

static const CardHelpDef sBlitzHelpDef = {
    gBlitzHelpTexts,
    2,
};

static const CardHelpDef sArsArcanumHelpDef = {
    gArsArcanumHelpTexts,
    2,
};

static const CardHelpDef sRagnarokHelpDef = {
    gRagnarokHelpTexts,
    2,
};

static const CardHelpDef sTrinityLimitHelpDef = {
    gTrinityLimitHelpTexts,
    2,
};

static const CardHelpDef sSlidingDashHelpDef = {
    gSlidingDashHelpTexts,
    2,
};

static const CardHelpDef sStunImpactHelpDef = {
    gStunImpactHelpTexts,
    2,
};

static const CardHelpDef sZantetsukenHelpDef = {
    gZantetsukenHelpTexts,
    2,
};

static const CardHelpDef sWarpHelpDef = {
    gWarpHelpTexts,
    2,
};

static const CardHelpDef sWarpinatorHelpDef = {
    gWarpinatorHelpTexts,
    2,
};

static const CardHelpDef sTerrorHelpDef = {
    gTerrorHelpTexts,
    3,
};

static const CardHelpDef sConfuseHelpDef = {
    gConfuseHelpTexts,
    2,
};

#if defined(VERSION_US) || defined(VERSION_JP)
static const CardHelpDef sSleight57HelpDef = {
    gSleight57HelpTexts,
    2,
};
#endif

static const CardHelpDef sStopRaidHelpDef = {
    gStopRaidHelpTexts,
    2,
};

static const CardHelpDef sJudgmentHelpDef = {
    gJudgmentHelpTexts,
    2,
};

static const CardHelpDef sReflectRaidHelpDef = {
    gReflectRaidHelpTexts,
    2,
};

static const CardHelpDef sFireRaidHelpDef = {
    gFireRaidHelpTexts,
    2,
};

static const CardHelpDef sBlizzardRaidHelpDef = {
    gBlizzardRaidHelpTexts,
    2,
};

static const CardHelpDef sThunderRaidHelpDef = {
    gThunderRaidHelpTexts,
    2,
};

static const CardHelpDef sGravityRaidHelpDef = {
    gGravityRaidHelpTexts,
    2,
};

static const CardHelpDef sAquaSplashHelpDef = {
    gAquaSplashHelpTexts,
    2,
};

static const CardHelpDef sHolyHelpDef = {
    gHolyHelpTexts,
    2,
};

static const CardHelpDef sBlazingDonaldHelpDef = {
    gBlazingDonaldHelpTexts,
    2,
};

#if defined(VERSION_US) || defined(VERSION_JP)
static const CardHelpDef sSleight68HelpDef = {
    gSleight68HelpTexts,
    2,
};
#endif

static const CardHelpDef sGiftedMiracleHelpDef = {
    gGiftedMiracleHelpTexts,
    3,
};

static const CardHelpDef sMegaFlareHelpDef = {
    gMegaFlareHelpTexts,
    2,
};

static const CardHelpDef sFiragaBreakHelpDef = {
    gFiragaBreakHelpTexts,
    2,
};

static const CardHelpDef sShockImpactHelpDef = {
    gShockImpactHelpTexts,
    2,
};

static const CardHelpDef sIdyllRompHelpDef = {
    gIdyllRompHelpTexts,
    2,
};

static const CardHelpDef sCrossSlashPlusHelpDef = {
    gCrossSlashPlusHelpTexts,
    2,
};

static const CardHelpDef sHomingFiraHelpDef = {
    gHomingFiraHelpTexts,
    2,
};

static const CardHelpDef sHomingBlizzaraHelpDef = {
    gHomingBlizzaraHelpTexts,
    2,
};

static const CardHelpDef sSynchroHelpDef = {
    gSynchroHelpTexts,
    2,
};

static const CardHelpDef sBindHelpDef = {
    gBindHelpTexts,
    2,
};

static const CardHelpDef sTornadoHelpDef = {
    gTornadoHelpTexts,
    2,
};

static const CardHelpDef sQuakeHelpDef = {
    gQuakeHelpTexts,
    2,
};

static const CardHelpDef sTeleportHelpDef = {
    gTeleportHelpTexts,
    3,
};

static const CardHelpDef sDarkBreakHelpDef = {
    gDarkBreakHelpTexts,
    2,
};

static const CardHelpDef sDarkFiragaHelpDef = {
    gDarkFiragaHelpTexts,
    2,
};

static const CardHelpDef sDarkAuraHelpDef = {
    gDarkAuraHelpTexts,
    2,
};

#if defined(VERSION_US)
static const CardHelpDef sSecretHelpDef = {
    gSecretHelpTexts,
    4,
};
#endif

#if defined(VERSION_US) || defined(VERSION_EU)
const CardHelpText* gBlitzHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090381F8,
    gCardHelpTextUs_09038260,
#elif defined(VERSION_EU)
    &gBlitzHelpText0ByLanguage,
    &gBlitzHelpText1ByLanguage,
#endif
};
#endif

const CardHelpText* gSonicBladeHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090382DC,
    gCardHelpTextUs_0903835A,
    gCardHelpTextUs_090383C4,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900B6E8,
    gCardHelpTextJp_0900B734,
#elif defined(VERSION_EU)
    &gSonicBladeHelpText0ByLanguage,
    &gSonicBladeHelpText1ByLanguage,
    &gSonicBladeHelpText2ByLanguage,
#endif
};

#if defined(VERSION_US) || defined(VERSION_EU)
const CardHelpText* gArsArcanumHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038440,
    gCardHelpTextUs_0903848E,
#elif defined(VERSION_EU)
    &gArsArcanumHelpText0ByLanguage,
    &gArsArcanumHelpText1ByLanguage,
#endif
};
#endif

const CardHelpText* gStrikeRaidHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090384DC,
    gCardHelpTextUs_0903857A,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900B7B4,
    gCardHelpTextJp_0900B7F0,
#elif defined(VERSION_EU)
    &gStrikeRaidHelpText0ByLanguage,
    &gStrikeRaidHelpText1ByLanguage,
#endif
};

#if defined(VERSION_US) || defined(VERSION_EU)
const CardHelpText* gRagnarokHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090385CC,
    gCardHelpTextUs_09038646,
#elif defined(VERSION_EU)
    &gRagnarokHelpText0ByLanguage,
    &gRagnarokHelpText1ByLanguage,
#endif
};

const CardHelpText* gTrinityLimitHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038694,
    gCardHelpTextUs_090386F0,
#elif defined(VERSION_EU)
    &gTrinityLimitHelpText0ByLanguage,
    &gTrinityLimitHelpText1ByLanguage,
#endif
};

const CardHelpText* gSlidingDashHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038736,
    gCardHelpTextUs_090387A4,
#elif defined(VERSION_EU)
    &gSlidingDashHelpText0ByLanguage,
    &gSlidingDashHelpText1ByLanguage,
#endif
};

const CardHelpText* gStunImpactHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903881C,
    gCardHelpTextUs_0903887A,
#elif defined(VERSION_EU)
    &gStunImpactHelpText0ByLanguage,
    &gStunImpactHelpText1ByLanguage,
#endif
};

const CardHelpText* gZantetsukenHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090388F2,
    gCardHelpTextUs_0903897C,
#elif defined(VERSION_EU)
    &gZantetsukenHelpText0ByLanguage,
    &gZantetsukenHelpText1ByLanguage,
#endif
};
#endif

const CardHelpText* gFiraHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090389D2,
    gCardHelpTextUs_09038A32,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900B9F0,
    gCardHelpTextJp_0900BA08,
#elif defined(VERSION_EU)
    &gFiraHelpText0ByLanguage,
    &gFiraHelpText1ByLanguage,
#endif
};

const CardHelpText* gBlizzaraHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038A4E,
    gCardHelpTextUs_09038AAA,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BA24,
    gCardHelpTextJp_0900BA3C,
#elif defined(VERSION_EU)
    &gBlizzaraHelpText0ByLanguage,
    &gBlizzaraHelpText1ByLanguage,
#endif
};

const CardHelpText* gThundaraHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038AD6,
    gCardHelpTextUs_09038B3E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BA58,
    gCardHelpTextJp_0900BA70,
#elif defined(VERSION_EU)
    &gThundaraHelpText0ByLanguage,
    &gThundaraHelpText1ByLanguage,
#endif
};

const CardHelpText* gCuraHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038B66,
    gCardHelpTextUs_09038B90,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BA84,
    gCardHelpTextJp_0900BA9C,
#elif defined(VERSION_EU)
    &gCuraHelpText0ByLanguage,
    &gCuraHelpText1ByLanguage,
#endif
};

#if defined(VERSION_US) || defined(VERSION_EU)
const CardHelpText* gGraviraHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038BAC,
    gCardHelpTextUs_09038C10,
#elif defined(VERSION_EU)
    &gGraviraHelpText0ByLanguage,
    &gGraviraHelpText1ByLanguage,
#endif
};
#endif

const CardHelpText* gStopraHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038C38,
    gCardHelpTextUs_09038C96,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BAAC,
    gCardHelpTextJp_0900BAC8,
#elif defined(VERSION_EU)
    &gStopraHelpText0ByLanguage,
    &gStopraHelpText1ByLanguage,
#endif
};

#if defined(VERSION_US) || defined(VERSION_EU)
const CardHelpText* gAeroraHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038CB2,
    gCardHelpTextUs_09038D16,
#elif defined(VERSION_EU)
    &gAeroraHelpText0ByLanguage,
    &gAeroraHelpText1ByLanguage,
#endif
};
#endif

const CardHelpText* gFiragaHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038D32,
    gCardHelpTextUs_09038D90,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BADC,
    gCardHelpTextJp_0900BAF4,
#elif defined(VERSION_EU)
    &gFiragaHelpText0ByLanguage,
    &gFiragaHelpText1ByLanguage,
#endif
};

const CardHelpText* gBlizzagaHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038DBA,
    gCardHelpTextUs_09038E16,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BB14,
    gCardHelpTextJp_0900BB2C,
#elif defined(VERSION_EU)
    &gBlizzagaHelpText0ByLanguage,
    &gBlizzagaHelpText1ByLanguage,
#endif
};

const CardHelpText* gThundagaHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038E58,
    gCardHelpTextUs_09038EBA,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BB4C,
    gCardHelpTextJp_0900BB64,
#elif defined(VERSION_EU)
    &gThundagaHelpText0ByLanguage,
    &gThundagaHelpText1ByLanguage,
#endif
};

const CardHelpText* gCuragaHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038EF6,
    gCardHelpTextUs_09038F3C,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BB84,
    gCardHelpTextJp_0900BBA0,
#elif defined(VERSION_EU)
    &gCuragaHelpText0ByLanguage,
    &gCuragaHelpText1ByLanguage,
#endif
};

#if defined(VERSION_JP)
const CardHelpText* gGraviraHelpTexts[] = {
    gCardHelpTextJp_0900BBB8,
    gCardHelpTextJp_0900BBE4,
};
#endif

const CardHelpText* gGravigaHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038F66,
    gCardHelpTextUs_09038FCA,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BBF8,
    gCardHelpTextJp_0900BC24,
#elif defined(VERSION_EU)
    &gGravigaHelpText0ByLanguage,
    &gGravigaHelpText1ByLanguage,
#endif
};

const CardHelpText* gStopgaHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039006,
    gCardHelpTextUs_0903906E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BC44,
    gCardHelpTextJp_0900BC6C,
#elif defined(VERSION_EU)
    &gStopgaHelpText0ByLanguage,
    &gStopgaHelpText1ByLanguage,
#endif
};

#if defined(VERSION_US) || defined(VERSION_EU)
const CardHelpText* gAerogaHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039098,
    gCardHelpTextUs_09039110,
#elif defined(VERSION_EU)
    &gAerogaHelpText0ByLanguage,
    &gAerogaHelpText1ByLanguage,
#endif
};
#endif

const CardHelpText* gProudRoarHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903913A,
    gCardHelpTextUs_090391BA,
    gCardHelpTextUs_090391DA,
    gCardHelpTextUs_0903926E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BD20,
    gCardHelpTextJp_0900BD4C,
    gCardHelpTextJp_0900BD5C,
    gCardHelpTextJp_0900BD90,
#elif defined(VERSION_EU)
    &gProudRoarHelpText0ByLanguage,
    &gProudRoarHelpText1ByLanguage,
    &gProudRoarHelpText2ByLanguage,
    &gProudRoarHelpText3ByLanguage,
#endif
};

const CardHelpText* gProudRoarPairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903913A,
    gCardHelpTextUs_090391BA,
    gCardHelpTextUs_090391DA,
    gCardHelpTextUs_0903926E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BD20,
    gCardHelpTextJp_0900BD4C,
    gCardHelpTextJp_0900BD5C,
    gCardHelpTextJp_0900BD90,
#elif defined(VERSION_EU)
    &gProudRoarHelpText0ByLanguage,
    &gProudRoarHelpText1ByLanguage,
    &gProudRoarHelpText2ByLanguage,
    &gProudRoarHelpText3ByLanguage,
#endif
};

const CardHelpText* gShowtimeHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903929E,
    gCardHelpTextUs_09039334,
    gCardHelpTextUs_09039354,
    gCardHelpTextUs_090393EE,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BDA8,
    gCardHelpTextJp_0900BDE0,
    gCardHelpTextJp_0900BDF4,
    gCardHelpTextJp_0900BE2C,
#elif defined(VERSION_EU)
    &gShowtimeHelpText0ByLanguage,
    &gShowtimeHelpText1ByLanguage,
    &gShowtimeHelpText2ByLanguage,
    &gShowtimeHelpText3ByLanguage,
#endif
};

const CardHelpText* gShowtimePairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903929E,
    gCardHelpTextUs_09039334,
    gCardHelpTextUs_09039354,
    gCardHelpTextUs_090393EE,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BDA8,
    gCardHelpTextJp_0900BDE0,
    gCardHelpTextJp_0900BDF4,
    gCardHelpTextJp_0900BE2C,
#elif defined(VERSION_EU)
    &gShowtimeHelpText0ByLanguage,
    &gShowtimeHelpText1ByLanguage,
    &gShowtimeHelpText2ByLanguage,
    &gShowtimeHelpText3ByLanguage,
#endif
};

const CardHelpText* gTwinkleHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903941E,
    gCardHelpTextUs_09039490,
    gCardHelpTextUs_090394C8,
    gCardHelpTextUs_09039562,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BE4C,
    gCardHelpTextJp_0900BE7C,
    gCardHelpTextJp_0900BE90,
    gCardHelpTextJp_0900BEC4,
#elif defined(VERSION_EU)
    &gTwinkleHelpText0ByLanguage,
    &gTwinkleHelpText1ByLanguage,
    &gTwinkleHelpText2ByLanguage,
    &gTwinkleHelpText3ByLanguage,
#endif
};

const CardHelpText* gTwinklePairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903941E,
    gCardHelpTextUs_09039490,
    gCardHelpTextUs_090394C8,
    gCardHelpTextUs_09039562,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BE4C,
    gCardHelpTextJp_0900BE7C,
    gCardHelpTextJp_0900BE90,
    gCardHelpTextJp_0900BEC4,
#elif defined(VERSION_EU)
    &gTwinkleHelpText0ByLanguage,
    &gTwinkleHelpText1ByLanguage,
    &gTwinkleHelpText2ByLanguage,
    &gTwinkleHelpText3ByLanguage,
#endif
};

const CardHelpText* gFlareBreathHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090395B6,
    gCardHelpTextUs_09039646,
    gCardHelpTextUs_09039666,
    gCardHelpTextUs_09039708,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BEE4,
    gCardHelpTextJp_0900BF14,
    gCardHelpTextJp_0900BF2C,
    gCardHelpTextJp_0900BF64,
#elif defined(VERSION_EU)
    &gFlareBreathHelpText0ByLanguage,
    &gFlareBreathHelpText1ByLanguage,
    &gFlareBreathHelpText2ByLanguage,
    &gFlareBreathHelpText3ByLanguage,
#endif
};

const CardHelpText* gFlareBreathPairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090395B6,
    gCardHelpTextUs_09039646,
    gCardHelpTextUs_09039666,
    gCardHelpTextUs_09039708,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BEE4,
    gCardHelpTextJp_0900BF14,
    gCardHelpTextJp_0900BF2C,
    gCardHelpTextJp_0900BF64,
#elif defined(VERSION_EU)
    &gFlareBreathHelpText0ByLanguage,
    &gFlareBreathHelpText1ByLanguage,
    &gFlareBreathHelpText2ByLanguage,
    &gFlareBreathHelpText3ByLanguage,
#endif
};

#if defined(VERSION_JP)
const CardHelpText* gCrossSlashHelpTexts[] = {
    gCardHelpTextJp_0900BF88,
    gCardHelpTextJp_0900BF9C,
};
#endif

const CardHelpText* gOmnislashHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090397BA,
    gCardHelpTextUs_09039842,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BFB0,
    gCardHelpTextJp_0900BFDC,
#elif defined(VERSION_EU)
    &gOmnislashHelpText0ByLanguage,
    &gOmnislashHelpText1ByLanguage,
#endif
};

#if defined(VERSION_US) || defined(VERSION_EU)
const CardHelpText* gCrossSlashHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039738,
    gCardHelpTextUs_0903979A,
#elif defined(VERSION_EU)
    &gCrossSlashHelpText0ByLanguage,
    &gCrossSlashHelpText1ByLanguage,
#endif
};
#endif

const CardHelpText* gParadiseHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039872,
    gCardHelpTextUs_090398D4,
    gCardHelpTextUs_090398F4,
    gCardHelpTextUs_09039988,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BFFC,
    gCardHelpTextJp_0900C02C,
    gCardHelpTextJp_0900C03C,
    gCardHelpTextJp_0900C084,
#elif defined(VERSION_EU)
    &gParadiseHelpText0ByLanguage,
    &gParadiseHelpText1ByLanguage,
    &gParadiseHelpText2ByLanguage,
    &gParadiseHelpText3ByLanguage,
#endif
};

const CardHelpText* gParadisePairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039872,
    gCardHelpTextUs_090398D4,
    gCardHelpTextUs_090398F4,
    gCardHelpTextUs_09039988,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BFFC,
    gCardHelpTextJp_0900C02C,
    gCardHelpTextJp_0900C03C,
    gCardHelpTextJp_0900C084,
#elif defined(VERSION_EU)
    &gParadiseHelpText0ByLanguage,
    &gParadiseHelpText1ByLanguage,
    &gParadiseHelpText2ByLanguage,
    &gParadiseHelpText3ByLanguage,
#endif
};

const CardHelpText* gSplashHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090399B8,
    gCardHelpTextUs_09039A3A,
    gCardHelpTextUs_09039A5A,
    gCardHelpTextUs_09039AF8,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C09C,
    gCardHelpTextJp_0900C0CC,
    gCardHelpTextJp_0900C0DC,
    gCardHelpTextJp_0900C118,
#elif defined(VERSION_EU)
    &gSplashHelpText0ByLanguage,
    &gSplashHelpText1ByLanguage,
    &gSplashHelpText2ByLanguage,
    &gSplashHelpText3ByLanguage,
#endif
};

const CardHelpText* gSplashPairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090399B8,
    gCardHelpTextUs_09039A3A,
    gCardHelpTextUs_09039A5A,
    gCardHelpTextUs_09039AF8,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C09C,
    gCardHelpTextJp_0900C0CC,
    gCardHelpTextJp_0900C0DC,
    gCardHelpTextJp_0900C118,
#elif defined(VERSION_EU)
    &gSplashHelpText0ByLanguage,
    &gSplashHelpText1ByLanguage,
    &gSplashHelpText2ByLanguage,
    &gSplashHelpText3ByLanguage,
#endif
};

const CardHelpText* gMagicHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039B28,
    gCardHelpTextUs_09039B96,
    gCardHelpTextUs_09039BBA,
    gCardHelpTextUs_09039C30,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C130,
    gCardHelpTextJp_0900C174,
    gCardHelpTextJp_0900C188,
    gCardHelpTextJp_0900C1CC,
#elif defined(VERSION_EU)
    &gMagicHelpText0ByLanguage,
    &gMagicHelpText1ByLanguage,
    &gMagicHelpText2ByLanguage,
    &gMagicHelpText3ByLanguage,
#endif
};

const CardHelpText* gMagicPairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039B28,
    gCardHelpTextUs_09039B96,
    gCardHelpTextUs_09039BBA,
    gCardHelpTextUs_09039C30,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C188,
    gCardHelpTextJp_0900C1CC,
    gCardHelpTextJp_0900C130,
    gCardHelpTextJp_0900C174,
#elif defined(VERSION_EU)
    &gMagicHelpText0ByLanguage,
    &gMagicHelpText1ByLanguage,
    &gMagicHelpText2ByLanguage,
    &gMagicHelpText3ByLanguage,
#endif
};

const CardHelpText* gGoofyChargeHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039C66,
    gCardHelpTextUs_09039CEE,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C1EC,
    gCardHelpTextJp_0900C218,
#elif defined(VERSION_EU)
    &gGoofyChargeHelpText0ByLanguage,
    &gGoofyChargeHelpText1ByLanguage,
#endif
};

const CardHelpText* gGoofyTornadoHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039D0E,
    gCardHelpTextUs_09039D8E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C230,
    gCardHelpTextJp_0900C25C,
#elif defined(VERSION_EU)
    &gGoofyTornadoHelpText0ByLanguage,
    &gGoofyTornadoHelpText1ByLanguage,
#endif
};

const CardHelpText* gSandstormHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039DBE,
    gCardHelpTextUs_09039E1A,
    gCardHelpTextUs_09039E42,
    gCardHelpTextUs_09039ED6,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C280,
    gCardHelpTextJp_0900C29C,
    gCardHelpTextJp_0900C2B0,
    gCardHelpTextJp_0900C2E0,
#elif defined(VERSION_EU)
    &gSandstormHelpText0ByLanguage,
    &gSandstormHelpText1ByLanguage,
    &gSandstormHelpText2ByLanguage,
    &gSandstormHelpText3ByLanguage,
#endif
};

const CardHelpText* gSandstormPairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039DBE,
    gCardHelpTextUs_09039E1A,
    gCardHelpTextUs_09039E42,
    gCardHelpTextUs_09039ED6,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C280,
    gCardHelpTextJp_0900C29C,
    gCardHelpTextJp_0900C2B0,
    gCardHelpTextJp_0900C2E0,
#elif defined(VERSION_EU)
    &gSandstormHelpText0ByLanguage,
    &gSandstormHelpText1ByLanguage,
    &gSandstormHelpText2ByLanguage,
    &gSandstormHelpText3ByLanguage,
#endif
};

const CardHelpText* gSurpriseHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039F12,
    gCardHelpTextUs_09039F82,
    gCardHelpTextUs_09039F9E,
    gCardHelpTextUs_0903A012,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C300,
    gCardHelpTextJp_0900C33C,
    gCardHelpTextJp_0900C350,
    gCardHelpTextJp_0900C38C,
#elif defined(VERSION_EU)
    &gSurpriseHelpText0ByLanguage,
    &gSurpriseHelpText1ByLanguage,
    &gSurpriseHelpText2ByLanguage,
    &gSurpriseHelpText3ByLanguage,
#endif
};

const CardHelpText* gSurprisePairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039F12,
    gCardHelpTextUs_09039F82,
    gCardHelpTextUs_09039F9E,
    gCardHelpTextUs_0903A012,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C300,
    gCardHelpTextJp_0900C33C,
    gCardHelpTextJp_0900C350,
    gCardHelpTextJp_0900C38C,
#elif defined(VERSION_EU)
    &gSurpriseHelpText0ByLanguage,
    &gSurpriseHelpText1ByLanguage,
    &gSurpriseHelpText2ByLanguage,
    &gSurpriseHelpText3ByLanguage,
#endif
};

const CardHelpText* gSpiralWaveHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A03C,
    gCardHelpTextUs_0903A0A4,
    gCardHelpTextUs_0903A0C4,
    gCardHelpTextUs_0903A15C,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C3AC,
    gCardHelpTextJp_0900C3DC,
    gCardHelpTextJp_0900C3F0,
    gCardHelpTextJp_0900C428,
#elif defined(VERSION_EU)
    &gSpiralWaveHelpText0ByLanguage,
    &gSpiralWaveHelpText1ByLanguage,
    &gSpiralWaveHelpText2ByLanguage,
    &gSpiralWaveHelpText3ByLanguage,
#endif
};

const CardHelpText* gSpiralWavePairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A03C,
    gCardHelpTextUs_0903A0A4,
    gCardHelpTextUs_0903A0C4,
    gCardHelpTextUs_0903A15C,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C3AC,
    gCardHelpTextJp_0900C3DC,
    gCardHelpTextJp_0900C3F0,
    gCardHelpTextJp_0900C428,
#elif defined(VERSION_EU)
    &gSpiralWaveHelpText0ByLanguage,
    &gSpiralWaveHelpText1ByLanguage,
    &gSpiralWaveHelpText2ByLanguage,
    &gSpiralWaveHelpText3ByLanguage,
#endif
};

const CardHelpText* gHummingbirdHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A18C,
    gCardHelpTextUs_0903A1FE,
    gCardHelpTextUs_0903A22E,
    gCardHelpTextUs_0903A2D0,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C448,
    gCardHelpTextJp_0900C474,
    gCardHelpTextJp_0900C490,
    gCardHelpTextJp_0900C4C0,
#elif defined(VERSION_EU)
    &gHummingbirdHelpText0ByLanguage,
    &gHummingbirdHelpText1ByLanguage,
    &gHummingbirdHelpText2ByLanguage,
    &gHummingbirdHelpText3ByLanguage,
#endif
};

const CardHelpText* gHummingbirdPairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A18C,
    gCardHelpTextUs_0903A1FE,
    gCardHelpTextUs_0903A22E,
    gCardHelpTextUs_0903A2D0,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C448,
    gCardHelpTextJp_0900C474,
    gCardHelpTextJp_0900C490,
    gCardHelpTextJp_0900C4C0,
#elif defined(VERSION_EU)
    &gHummingbirdHelpText0ByLanguage,
    &gHummingbirdHelpText1ByLanguage,
    &gHummingbirdHelpText2ByLanguage,
    &gHummingbirdHelpText3ByLanguage,
#endif
};

const CardHelpText* gFerociousLungeHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A318,
    gCardHelpTextUs_0903A39A,
    gCardHelpTextUs_0903A3CA,
    gCardHelpTextUs_0903A448,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C4EC,
    gCardHelpTextJp_0900C524,
    gCardHelpTextJp_0900C538,
    gCardHelpTextJp_0900C568,
#elif defined(VERSION_EU)
    &gFerociousLungeHelpText0ByLanguage,
    &gFerociousLungeHelpText1ByLanguage,
    &gFerociousLungeHelpText2ByLanguage,
    &gFerociousLungeHelpText3ByLanguage,
#endif
};

const CardHelpText* gFerociousLungePairHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A318,
    gCardHelpTextUs_0903A39A,
    gCardHelpTextUs_0903A3CA,
    gCardHelpTextUs_0903A448,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C4EC,
    gCardHelpTextJp_0900C524,
    gCardHelpTextJp_0900C538,
    gCardHelpTextJp_0900C568,
#elif defined(VERSION_EU)
    &gFerociousLungeHelpText0ByLanguage,
    &gFerociousLungeHelpText1ByLanguage,
    &gFerociousLungeHelpText2ByLanguage,
    &gFerociousLungeHelpText3ByLanguage,
#endif
};

#if defined(VERSION_JP)
const CardHelpText* gMmMiracleHelpTexts[] = {
    gCardHelpTextJp_0900D0D8,
    gCardHelpTextJp_0900D110,
    gCardHelpTextJp_0900D11C,
    gCardHelpTextJp_0900D158,
};

const CardHelpText* gSecretHelpTexts[] = {
    gCardHelpTextJp_0900D16C,
    gCardHelpTextJp_0900D174,
};

const CardHelpText* gMmMiraclePairHelpTexts[] = {
    gCardHelpTextJp_0900D11C,
    gCardHelpTextJp_0900D158,
};

const CardHelpText* gAeroraHelpTexts[] = {
    gCardHelpTextJp_0900BC8C,
    gCardHelpTextJp_0900BCC0,
};

const CardHelpText* gAerogaHelpTexts[] = {
    gCardHelpTextJp_0900BCD0,
    gCardHelpTextJp_0900BD08,
};

const CardHelpText* gBlitzHelpTexts[] = {
    gCardHelpTextJp_0900B684,
    gCardHelpTextJp_0900B6B0,
};

const CardHelpText* gArsArcanumHelpTexts[] = {
    gCardHelpTextJp_0900B76C,
    gCardHelpTextJp_0900B78C,
};

const CardHelpText* gRagnarokHelpTexts[] = {
    gCardHelpTextJp_0900B81C,
    gCardHelpTextJp_0900B83C,
};

const CardHelpText* gTrinityLimitHelpTexts[] = {
    gCardHelpTextJp_0900B864,
    gCardHelpTextJp_0900B8A0,
};

const CardHelpText* gSlidingDashHelpTexts[] = {
    gCardHelpTextJp_0900B8C8,
    gCardHelpTextJp_0900B8F0,
};

const CardHelpText* gStunImpactHelpTexts[] = {
    gCardHelpTextJp_0900B928,
    gCardHelpTextJp_0900B950,
};

const CardHelpText* gZantetsukenHelpTexts[] = {
    gCardHelpTextJp_0900B988,
    gCardHelpTextJp_0900B9C4,
};
#endif

const CardHelpText* gWarpHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A490,
    gCardHelpTextUs_0903A4D0,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C588,
    gCardHelpTextJp_0900C5B0,
#elif defined(VERSION_EU)
    &gWarpHelpText0ByLanguage,
    &gWarpHelpText1ByLanguage,
#endif
};

const CardHelpText* gWarpinatorHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A4FA,
    gCardHelpTextUs_0903A562,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C5CC,
    gCardHelpTextJp_0900C600,
#elif defined(VERSION_EU)
    &gWarpinatorHelpText0ByLanguage,
    &gWarpinatorHelpText1ByLanguage,
#endif
};

const CardHelpText* gTerrorHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A592,
    gCardHelpTextUs_0903A5FC,
    gCardHelpTextUs_0903A652,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C61C,
    gCardHelpTextJp_0900C644,
    gCardHelpTextJp_0900C668,
#elif defined(VERSION_EU)
    &gTerrorHelpText0ByLanguage,
    &gTerrorHelpText1ByLanguage,
    &gTerrorHelpText2ByLanguage,
#endif
};

const CardHelpText* gConfuseHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A692,
    gCardHelpTextUs_0903A700,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C68C,
    gCardHelpTextJp_0900C6C0,
#elif defined(VERSION_EU)
    &gConfuseHelpText0ByLanguage,
    &gConfuseHelpText1ByLanguage,
#endif
};

#if defined(VERSION_JP)
const CardHelpText* gSleight57HelpTexts[] = {
    gCardHelpTextJp_0900C6E0,
    gCardHelpTextJp_0900C718,
};
#endif

const CardHelpText* gStopRaidHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A750,
    gCardHelpTextUs_0903A7B0,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C728,
    gCardHelpTextJp_0900C75C,
#elif defined(VERSION_EU)
    &gStopRaidHelpText0ByLanguage,
    &gStopRaidHelpText1ByLanguage,
#endif
};

const CardHelpText* gJudgmentHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A806,
    gCardHelpTextUs_0903A878,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C788,
    gCardHelpTextJp_0900C7B8,
#elif defined(VERSION_EU)
    &gJudgmentHelpText0ByLanguage,
    &gJudgmentHelpText1ByLanguage,
#endif
};

const CardHelpText* gReflectRaidHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A8CE,
    gCardHelpTextUs_0903A95A,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C7E0,
    gCardHelpTextJp_0900C82C,
#elif defined(VERSION_EU)
    &gReflectRaidHelpText0ByLanguage,
    &gReflectRaidHelpText1ByLanguage,
#endif
};

const CardHelpText* gFireRaidHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A9B2,
    gCardHelpTextUs_0903AA08,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C858,
    gCardHelpTextJp_0900C880,
#elif defined(VERSION_EU)
    &gFireRaidHelpText0ByLanguage,
    &gFireRaidHelpText1ByLanguage,
#endif
};

const CardHelpText* gBlizzardRaidHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AA5E,
    gCardHelpTextUs_0903AAB2,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C8AC,
    gCardHelpTextJp_0900C8D4,
#elif defined(VERSION_EU)
    &gBlizzardRaidHelpText0ByLanguage,
    &gBlizzardRaidHelpText1ByLanguage,
#endif
};

const CardHelpText* gThunderRaidHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AB10,
    gCardHelpTextUs_0903AB70,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C900,
    gCardHelpTextJp_0900C928,
#elif defined(VERSION_EU)
    &gThunderRaidHelpText0ByLanguage,
    &gThunderRaidHelpText1ByLanguage,
#endif
};

const CardHelpText* gGravityRaidHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903ABCC,
    gCardHelpTextUs_0903AC32,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C954,
    gCardHelpTextJp_0900C988,
#elif defined(VERSION_EU)
    &gGravityRaidHelpText0ByLanguage,
    &gGravityRaidHelpText1ByLanguage,
#endif
};

const CardHelpText* gAquaSplashHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AC8E,
    gCardHelpTextUs_0903AD26,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C9B4,
    gCardHelpTextJp_0900C9F0,
#elif defined(VERSION_EU)
    &gAquaSplashHelpText0ByLanguage,
    &gAquaSplashHelpText1ByLanguage,
#endif
};

const CardHelpText* gHolyHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AD58,
    gCardHelpTextUs_0903ADD8,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CA0C,
    gCardHelpTextJp_0900CA48,
#elif defined(VERSION_EU)
    &gHolyHelpText0ByLanguage,
    &gHolyHelpText1ByLanguage,
#endif
};

const CardHelpText* gBlazingDonaldHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AE2A,
    gCardHelpTextUs_0903AE60,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CA78,
    gCardHelpTextJp_0900CAA4,
#elif defined(VERSION_EU)
    &gBlazingDonaldHelpText0ByLanguage,
    &gBlazingDonaldHelpText1ByLanguage,
#endif
};

#if defined(VERSION_JP)
const CardHelpText* gSleight68HelpTexts[] = {
    gCardHelpTextJp_0900CAC4,
    gCardHelpTextJp_0900CAFC,
};
#endif

const CardHelpText* gGiftedMiracleHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AEA2,
    gCardHelpTextUs_0903AF44,
    gCardHelpTextUs_0903AF98,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CB0C,
    gCardHelpTextJp_0900CB48,
    gCardHelpTextJp_0900CB6C,
#elif defined(VERSION_EU)
    &gGiftedMiracleHelpText0ByLanguage,
    &gGiftedMiracleHelpText1ByLanguage,
    &gGiftedMiracleHelpText2ByLanguage,
#endif
};

const CardHelpText* gMegaFlareHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AFDE,
    gCardHelpTextUs_0903B02C,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CB90,
    gCardHelpTextJp_0900CBAC,
#elif defined(VERSION_EU)
    &gMegaFlareHelpText0ByLanguage,
    &gMegaFlareHelpText1ByLanguage,
#endif
};

const CardHelpText* gFiragaBreakHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B058,
    gCardHelpTextUs_0903B0E6,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CBCC,
    gCardHelpTextJp_0900CBF8,
#elif defined(VERSION_EU)
    &gFiragaBreakHelpText0ByLanguage,
    &gFiragaBreakHelpText1ByLanguage,
#endif
};

const CardHelpText* gShockImpactHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B128,
    gCardHelpTextUs_0903B192,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CC20,
    gCardHelpTextJp_0900CC50,
#elif defined(VERSION_EU)
    &gShockImpactHelpText0ByLanguage,
    &gShockImpactHelpText1ByLanguage,
#endif
};

const CardHelpText* gIdyllRompHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B1EA,
    gCardHelpTextUs_0903B260,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CC78,
    gCardHelpTextJp_0900CCA4,
#elif defined(VERSION_EU)
    &gIdyllRompHelpText0ByLanguage,
    &gIdyllRompHelpText1ByLanguage,
#endif
};

const CardHelpText* gCrossSlashPlusHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B2B8,
    gCardHelpTextUs_0903B31A,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CCCC,
    gCardHelpTextJp_0900CCFC,
#elif defined(VERSION_EU)
    &gCrossSlashPlusHelpText0ByLanguage,
    &gCrossSlashPlusHelpText1ByLanguage,
#endif
};

const CardHelpText* gHomingFiraHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B35C,
    gCardHelpTextUs_0903B3C6,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CD20,
    gCardHelpTextJp_0900CD50,
#elif defined(VERSION_EU)
    &gHomingFiraHelpText0ByLanguage,
    &gHomingFiraHelpText1ByLanguage,
#endif
};

const CardHelpText* gHomingBlizzaraHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B404,
    gCardHelpTextUs_0903B476,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CD70,
    gCardHelpTextJp_0900CDA0,
#elif defined(VERSION_EU)
    &gHomingBlizzaraHelpText0ByLanguage,
    &gHomingBlizzaraHelpText1ByLanguage,
#endif
};

const CardHelpText* gSynchroHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B4BC,
    gCardHelpTextUs_0903B522,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CDC0,
    gCardHelpTextJp_0900CDFC,
#elif defined(VERSION_EU)
    &gSynchroHelpText0ByLanguage,
    &gSynchroHelpText1ByLanguage,
#endif
};

const CardHelpText* gBindHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B552,
    gCardHelpTextUs_0903B5DE,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CE18,
    gCardHelpTextJp_0900CE54,
#elif defined(VERSION_EU)
    &gBindHelpText0ByLanguage,
    &gBindHelpText1ByLanguage,
#endif
};

const CardHelpText* gTornadoHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B622,
    gCardHelpTextUs_0903B6B0,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CE74,
    gCardHelpTextJp_0900CEB0,
#elif defined(VERSION_EU)
    &gTornadoHelpText0ByLanguage,
    &gTornadoHelpText1ByLanguage,
#endif
};

const CardHelpText* gQuakeHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B6F6,
    gCardHelpTextUs_0903B76E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CED0,
    gCardHelpTextJp_0900CF0C,
#elif defined(VERSION_EU)
    &gQuakeHelpText0ByLanguage,
    &gQuakeHelpText1ByLanguage,
#endif
};

const CardHelpText* gTeleportHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B7B4,
    gCardHelpTextUs_0903B842,
    gCardHelpTextUs_0903B89E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CF2C,
    gCardHelpTextJp_0900CF68,
    gCardHelpTextJp_0900CF90,
#elif defined(VERSION_EU)
    &gTeleportHelpText0ByLanguage,
    &gTeleportHelpText1ByLanguage,
    &gTeleportHelpText2ByLanguage,
#endif
};

const CardHelpText* gDarkBreakHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B8DA,
    gCardHelpTextUs_0903B976,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CFB4,
    gCardHelpTextJp_0900CFE8,
#elif defined(VERSION_EU)
    &gDarkBreakHelpText0ByLanguage,
    &gDarkBreakHelpText1ByLanguage,
#endif
};

const CardHelpText* gDarkFiragaHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B9C4,
    gCardHelpTextUs_0903BA4A,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900D014,
    gCardHelpTextJp_0900D04C,
#elif defined(VERSION_EU)
    &gDarkFiragaHelpText0ByLanguage,
    &gDarkFiragaHelpText1ByLanguage,
#endif
};

const CardHelpText* gDarkAuraHelpTexts[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903BA9A,
    gCardHelpTextUs_0903BB2C,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900D078,
    gCardHelpTextJp_0900D0B0,
#elif defined(VERSION_EU)
    &gDarkAuraHelpText0ByLanguage,
    &gDarkAuraHelpText1ByLanguage,
#endif
};

#if defined(VERSION_US)
const CardHelpText* gSecretHelpTexts[] = {
    gCardHelpTextUs_0903BCFA,
    gCardHelpTextUs_0903BCFA,
    gCardHelpTextUs_0903BCFA,
    gCardHelpTextUs_0903BCFA,
};

const CardHelpText* gMmMiracleHelpTexts[] = {
    gCardHelpTextUs_0903BB76,
    gCardHelpTextUs_0903BBF8,
    gCardHelpTextUs_0903BC24,
    gCardHelpTextUs_0903BCB8,
};

const CardHelpText* gMmMiraclePairHelpTexts[] = {
    gCardHelpTextUs_0903BB76,
    gCardHelpTextUs_0903BBF8,
    gCardHelpTextUs_0903BC24,
    gCardHelpTextUs_0903BCB8,
};

const CardHelpText* gSleight57HelpTexts[] = {
    gCardHelpTextUs_0903BCFA,
    gCardHelpTextUs_0903BCFA,
};

const CardHelpText* gSleight68HelpTexts[] = {
    gCardHelpTextUs_0903BCFA,
    gCardHelpTextUs_0903BCFA,
};
#endif

#if defined(VERSION_EU)
const CardHelpText* gMmMiracleHelpTexts[] = {
    &gMmMiracleHelpText0ByLanguage,
    &gMmMiracleHelpText1ByLanguage,
    &gMmMiracleHelpText2ByLanguage,
    &gMmMiracleHelpText3ByLanguage,
};

const CardHelpText* gMmMiraclePairHelpTexts[] = {
    &gMmMiracleHelpText0ByLanguage,
    &gMmMiracleHelpText1ByLanguage,
    &gMmMiracleHelpText2ByLanguage,
    &gMmMiracleHelpText3ByLanguage,
};
#endif

static const u16 sLevelUpStockHelpIndices[12] = {
    STOCK_SLIDING_DASH,
    STOCK_STUN_IMPACT,
    STOCK_STRIKE_RAID,
    STOCK_BLITZ,
    STOCK_SONIC_BLADE,
    STOCK_ZANTETSUKEN,
    STOCK_TORNADO,
    STOCK_ARS_ARCANUM,
    STOCK_HOLY,
    STOCK_RAGNAROK,
    STOCK_MEGA_FLARE,
    0xFFFF,
};

static const u16 sLevelUpStockLevels[12] = {
    2, 7, 12, 17, 22, 27, 32, 37, 42, 47, 52, 999,
};

void StockInfo_0(StockInfoWork* work, u8* active) {
    u8 i;

    work->active = active;
    TaskPoolInit(&work->tasks, 1);
    work->tiles = LoadObjTiles(gStockInfoWindowTiles, sizeof(gStockInfoWindowTiles));
    work->palette = LoadObjPalette(gStockInfoWindowPalette, sizeof(gStockInfoWindowPalette));

    for (i = 16; i < 32; i++) {
        FadeSetPaletteExcluded(i, TRUE);
    }

    work->x = 0x4C00;
    work->y = 0xBC00;
    work->timer = 16;

    switch (gGameState.progression.levelMilestone) {
    case 0:
        LearnStock(LEARNED_STOCK_SLIDING_DASH);
        break;
    case 1:
        LearnStock(LEARNED_STOCK_STUN_IMPACT);
        break;
    case 2:
        LearnStock(LEARNED_STOCK_STRIKE_RAID);
        break;
    case 3:
        LearnStock(LEARNED_STOCK_BLITZ);
        break;
    case 4:
        LearnStock(LEARNED_STOCK_SONIC_BLADE);
        break;
    case 5:
        LearnStock(LEARNED_STOCK_ZANTETSUKEN);
        break;
    case 6:
        LearnStock(LEARNED_STOCK_TORNADO);
        break;
    case 7:
        LearnStock(LEARNED_STOCK_ARS_ARCANUM);
        break;
    case 8:
        LearnStock(LEARNED_STOCK_HOLY);
        break;
    case 9:
        LearnStock(LEARNED_STOCK_RAGNAROK);
        break;
    case 10:
        LearnStock(LEARNED_STOCK_MEGA_FLARE);
        break;
    }
}

u8 StockInfo_1(StockInfoWork* work, void* task) {
    if (work->timer > 0) {
        ApproachValue(&work->y, 0x6C00, work->timer);
        work->timer--;
    } else {
        m4aSongNumStart(SONG_SYS_CHAGEF2);
        CreateStockMesDispTask(&work->tasks, sLevelUpStockHelpIndices[gGameState.progression.levelMilestone], 0, 0, 0x50);
        SetTaskUpdate(task, (TaskUpdateFunc)UpdateStockInfoMessage);
    }

    return 1;
}

s32 UpdateStockInfoMessage(StockInfoWork* work) {
    if (*work->active == 0) {
        return 0;
    }

    TaskPoolUpdate(&work->tasks);
    return 1;
}

void StockInfo_2(StockInfoWork* work) {
    DrawSprite(work->x >> 8, work->y >> 8, gStockInfoWindowFrames[0], work->tiles, work->palette, NULL, 0, 50);
    TaskPoolDraw(&work->tasks);
}

void StockInfo_3(StockInfoWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    gGameState.progression.levelMilestone++;
    TaskPoolDestroy(&work->tasks);
}

void* GetCardHelpText(u16 helpIndex, u8 textIndex) {
    if (textIndex < gCardHelpDefs[helpIndex]->textCount) {
        return LANGSTR(gCardHelpDefs[helpIndex]->texts[textIndex]);
    }

    return NULL;
}

u8 GetCardHelpTextCount(u16 helpIndex) {
    return gCardHelpDefs[helpIndex]->textCount;
}

u8 IsLevelUpStockUnlocked() {
    if (gGameState.progression.level >= sLevelUpStockLevels[gGameState.progression.levelMilestone]) {
        return TRUE;
    }

    return FALSE;
}

const CardHelpDef* gCardHelpDefs[] = {
    &sFiraHelpDef,
    &sBlizzaraHelpDef,
    &sThundaraHelpDef,
    &sCuraHelpDef,
    &sStopraHelpDef,
    &sSonicBladeHelpDef,
    &sStrikeRaidHelpDef,
    &sFiragaHelpDef,
    &sBlizzagaHelpDef,
    &sThundagaHelpDef,
    &sCuragaHelpDef,
    &sGraviraHelpDef,
    &sGravigaHelpDef,
    &sStopgaHelpDef,
    &sGoofyTornadoHelpDef,
    &sGoofyChargeHelpDef,
    &sMagicHelpDef,
    &sMagicPairHelpDef,
    &sProudRoarHelpDef,
    &sProudRoarPairHelpDef,
    &sShowtimeHelpDef,
    &sShowtimePairHelpDef,
    &sParadiseHelpDef,
    &sParadisePairHelpDef,
    &sSplashHelpDef,
    &sSplashPairHelpDef,
    &sTwinkleHelpDef,
    &sTwinklePairHelpDef,
    &sFlareBreathHelpDef,
    &sFlareBreathPairHelpDef,
    &sOmnislashHelpDef,
    &sCrossSlashHelpDef,
    &sSandstormHelpDef,
    &sSandstormPairHelpDef,
    &sSpiralWaveHelpDef,
    &sSpiralWavePairHelpDef,
    &sSurpriseHelpDef,
    &sSurprisePairHelpDef,
    &sHummingbirdHelpDef,
    &sHummingbirdPairHelpDef,
    &sFerociousLungeHelpDef,
    &sFerociousLungePairHelpDef,
    &sMmMiracleHelpDef,
    &sMmMiraclePairHelpDef,
    &sAeroraHelpDef,
    &sAerogaHelpDef,
    &sBlitzHelpDef,
    &sArsArcanumHelpDef,
    &sRagnarokHelpDef,
    &sTrinityLimitHelpDef,
    &sSlidingDashHelpDef,
    &sStunImpactHelpDef,
    &sZantetsukenHelpDef,
    &sWarpHelpDef,
    &sWarpinatorHelpDef,
    &sTerrorHelpDef,
    &sConfuseHelpDef,
#if defined(VERSION_US) || defined(VERSION_JP)
    &sSleight57HelpDef,
#elif defined(VERSION_EU)
    NULL,
#endif
    &sStopRaidHelpDef,
    &sJudgmentHelpDef,
    &sReflectRaidHelpDef,
    &sFireRaidHelpDef,
    &sBlizzardRaidHelpDef,
    &sThunderRaidHelpDef,
    &sGravityRaidHelpDef,
    &sAquaSplashHelpDef,
    &sHolyHelpDef,
    &sBlazingDonaldHelpDef,
#if defined(VERSION_US) || defined(VERSION_JP)
    &sSleight68HelpDef,
#elif defined(VERSION_EU)
    NULL,
#endif
    &sGiftedMiracleHelpDef,
    &sMegaFlareHelpDef,
    &sFiragaBreakHelpDef,
    &sShockImpactHelpDef,
    &sIdyllRompHelpDef,
    &sCrossSlashPlusHelpDef,
    &sHomingFiraHelpDef,
    &sHomingBlizzaraHelpDef,
    &sSynchroHelpDef,
    &sBindHelpDef,
    &sTornadoHelpDef,
    &sQuakeHelpDef,
    &sTeleportHelpDef,
    &sDarkBreakHelpDef,
    &sDarkFiragaHelpDef,
    &sDarkAuraHelpDef,
#if defined(VERSION_US) || defined(VERSION_JP)
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
    &sSecretHelpDef,
#endif
};

TaskDesc gTaskDescStockInfo = {
    "StockInfo",
    (TaskInitFunc)StockInfo_0,
    (TaskUpdateFunc)StockInfo_1,
    (TaskDrawFunc)StockInfo_2,
    (TaskDestroyFunc)StockInfo_3,
    sizeof(StockInfoWork),
};
