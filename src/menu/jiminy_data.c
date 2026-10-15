/**
 * jiminy_data.c
 * Jiminy's Journal Data
 */

#include "jiminy_data.h"
#include "common_text.h"
#include "jiminy_inline_text_data.h"
#include "jiminy_text.h"
#include "jiminy_types.h"

#if defined(VERSION_US)

JiminyTextChar* gJiminyStoryTale1Lines[22] = {
    gJiminyStoryTale1Line0, gJiminyStoryTale1Line1, gJiminyStoryTale1Line2, gJiminyStoryTale1Line3,
    gJiminyStoryTale1Line4, gJiminyStoryTale1Line5, gJiminyStoryTale1Line6, gJiminyStoryTale1Line7,
    gJiminyStoryTale1Line8, gJiminyStoryTale1Line9, gJiminyStoryTale1Line10, gJiminyStoryTale1Line11,
    gJiminyStoryTale1Line12, gJiminyStoryTale1Line13, gJiminyStoryTale1Line14, gJiminyStoryTale1Line15,
    gJiminyStoryTale1Line16, gJiminyStoryTale1Line17, gJiminyStoryTale1Line18, gJiminyStoryTale1Line19,
    gJiminyStoryTale1Line20, gJiminyStoryTale1Line21,
};

JiminyTextChar* gJiminyStoryTale2Lines[19] = {
    gJiminyStoryTale2Line0, gJiminyStoryTale2Line1, gJiminyStoryTale2Line2, gJiminyStoryTale2Line3,
    gJiminyStoryTale2Line4, gJiminyStoryTale2Line5, gJiminyStoryTale2Line6, gJiminyStoryTale2Line7,
    gJiminyStoryTale2Line8, gJiminyStoryTale2Line9, gJiminyStoryTale2Line10, gJiminyStoryTale2Line11,
    gJiminyStoryTale2Line12, gJiminyStoryTale2Line13, gJiminyStoryTale2Line14, gJiminyStoryTale2Line15,
    gJiminyStoryTale2Line16, gJiminyStoryTale2Line17, gJiminyStoryTale2Line18,
};

JiminyTextChar* gJiminyStoryTale4Lines[22] = {
    gJiminyStoryTale4Line0, gJiminyStoryTale4Line1, gJiminyStoryTale4Line2, gJiminyStoryTale4Line3,
    gJiminyStoryTale4Line4, gJiminyStoryTale4Line5, gJiminyStoryTale4Line6, gJiminyStoryTale4Line7,
    gJiminyStoryTale4Line8, gJiminyStoryTale4Line9, gJiminyStoryTale4Line10, gJiminyStoryTale4Line11,
    gJiminyStoryTale4Line12, gJiminyStoryTale4Line13, gJiminyStoryTale4Line14, gJiminyStoryTale4Line15,
    gJiminyStoryTale4Line16, gJiminyStoryTale4Line17, gJiminyStoryTale4Line18, gJiminyStoryTale4Line19,
    gJiminyStoryTale4Line20, gJiminyStoryTale4Line21,
};

JiminyTextChar* gJiminyStoryOlympusColiseumLines[17] = {
    gJiminyStoryOlympusColiseumLine0, gJiminyStoryOlympusColiseumLine1, gJiminyStoryOlympusColiseumLine2, gJiminyStoryOlympusColiseumLine3,
    gJiminyStoryOlympusColiseumLine4, gJiminyStoryOlympusColiseumLine5, gJiminyStoryOlympusColiseumLine6, gJiminyStoryOlympusColiseumLine7,
    gJiminyStoryOlympusColiseumLine8, gJiminyStoryOlympusColiseumLine9, gJiminyStoryOlympusColiseumLine10, gJiminyStoryOlympusColiseumLine11,
    gJiminyStoryOlympusColiseumLine12, gJiminyStoryOlympusColiseumLine13, gJiminyStoryOlympusColiseumLine14, gJiminyStoryOlympusColiseumLine15,
    gJiminyStoryOlympusColiseumLine16,
};

JiminyTextChar* gJiminyStoryAgrabahLines[32] = {
    gJiminyStoryAgrabahLine0, gJiminyStoryAgrabahLine1, gJiminyStoryAgrabahLine2, gJiminyStoryAgrabahLine3,
    gJiminyStoryAgrabahLine4, gJiminyStoryAgrabahLine5, gJiminyStoryAgrabahLine6, gJiminyStoryAgrabahLine7,
    gJiminyStoryAgrabahLine8, gJiminyStoryAgrabahLine9, gJiminyStoryAgrabahLine10, gJiminyStoryAgrabahLine11,
    gJiminyStoryAgrabahLine12, gJiminyStoryAgrabahLine13, gJiminyStoryAgrabahLine14, gJiminyStoryAgrabahLine15,
    gJiminyStoryAgrabahLine16, gJiminyStoryAgrabahLine17, gJiminyStoryAgrabahLine18, gJiminyStoryAgrabahLine19,
    gJiminyStoryAgrabahLine20, gJiminyStoryAgrabahLine21, gJiminyStoryAgrabahLine22, gJiminyStoryAgrabahLine23,
    gJiminyStoryAgrabahLine24, gJiminyStoryAgrabahLine25, gJiminyStoryAgrabahLine26, gJiminyStoryAgrabahLine27,
    gJiminyStoryAgrabahLine28, gJiminyStoryAgrabahLine29, gJiminyStoryAgrabahLine30, gJiminyStoryAgrabahLine31,
};

JiminyTextChar* gJiminyStoryMonstroLines[25] = {
    gJiminyStoryMonstroLine0, gJiminyStoryMonstroLine1, gJiminyStoryMonstroLine2, gJiminyStoryMonstroLine3,
    gJiminyStoryMonstroLine4, gJiminyStoryMonstroLine5, gJiminyStoryMonstroLine6, gJiminyStoryMonstroLine7,
    gJiminyStoryMonstroLine8, gJiminyStoryMonstroLine9, gJiminyStoryMonstroLine10, gJiminyStoryMonstroLine11,
    gJiminyStoryMonstroLine12, gJiminyStoryMonstroLine13, gJiminyStoryMonstroLine14, gJiminyStoryMonstroLine15,
    gJiminyStoryMonstroLine16, gJiminyStoryMonstroLine17, gJiminyStoryMonstroLine18, gJiminyStoryMonstroLine19,
    gJiminyStoryMonstroLine20, gJiminyStoryMonstroLine21, gJiminyStoryMonstroLine22, gJiminyStoryMonstroLine23,
    gJiminyStoryMonstroLine24,
};

JiminyTextChar* gJiminyStoryNeverLandLines[27] = {
    gJiminyStoryNeverLandLine0, gJiminyStoryNeverLandLine1, gJiminyStoryNeverLandLine2, gJiminyStoryNeverLandLine3,
    gJiminyStoryNeverLandLine4, gJiminyStoryNeverLandLine5, gJiminyStoryNeverLandLine6, gJiminyStoryNeverLandLine7,
    gJiminyStoryNeverLandLine8, gJiminyStoryNeverLandLine9, gJiminyStoryNeverLandLine10, gJiminyStoryNeverLandLine11,
    gJiminyStoryNeverLandLine12, gJiminyStoryNeverLandLine13, gJiminyStoryNeverLandLine14, gJiminyStoryNeverLandLine15,
    gJiminyStoryNeverLandLine16, gJiminyStoryNeverLandLine17, gJiminyStoryNeverLandLine18, gJiminyStoryNeverLandLine19,
    gJiminyStoryNeverLandLine20, gJiminyStoryNeverLandLine21, gJiminyStoryNeverLandLine22, gJiminyStoryNeverLandLine23,
    gJiminyStoryNeverLandLine24, gJiminyStoryNeverLandLine25, gJiminyStoryNeverLandLine26,
};

JiminyTextChar* gJiminyStoryHollowBastionLines[25] = {
    gJiminyStoryHollowBastionLine0, gJiminyStoryHollowBastionLine1, gJiminyStoryHollowBastionLine2, gJiminyStoryHollowBastionLine3,
    gJiminyStoryHollowBastionLine4, gJiminyStoryHollowBastionLine5, gJiminyStoryHollowBastionLine6, gJiminyStoryHollowBastionLine7,
    gJiminyStoryHollowBastionLine8, gJiminyStoryHollowBastionLine9, gJiminyStoryHollowBastionLine10, gJiminyStoryHollowBastionLine11,
    gJiminyStoryHollowBastionLine12, gJiminyStoryHollowBastionLine13, gJiminyStoryHollowBastionLine14, gJiminyStoryHollowBastionLine15,
    gJiminyStoryHollowBastionLine16, gJiminyStoryHollowBastionLine17, gJiminyStoryHollowBastionLine18, gJiminyStoryHollowBastionLine19,
    gJiminyStoryHollowBastionLine20, gJiminyStoryHollowBastionLine21, gJiminyStoryHollowBastionLine22, gJiminyStoryHollowBastionLine23,
    gJiminyStoryHollowBastionLine24,
};

JiminyTextChar* gJiminyStoryTwilightTownLines[15] = {
    gJiminyStoryTwilightTownLine0, gJiminyStoryTwilightTownLine1, gJiminyStoryTwilightTownLine2, gJiminyStoryTwilightTownLine3,
    gJiminyStoryTwilightTownLine4, gJiminyStoryTwilightTownLine5, gJiminyStoryTwilightTownLine6, gJiminyStoryTwilightTownLine7,
    gJiminyStoryTwilightTownLine8, gJiminyStoryTwilightTownLine9, gJiminyStoryTwilightTownLine10, gJiminyStoryTwilightTownLine11,
    gJiminyStoryTwilightTownLine12, gJiminyStoryTwilightTownLine13, gJiminyStoryTwilightTownLine14,
};

JiminyTextChar* gJiminyRikuStoryTale2Lines[26] = {
    gJiminyRikuStoryTale2Line0, gJiminyRikuStoryTale2Line1, gJiminyRikuStoryTale2Line2, gJiminyRikuStoryTale2Line3,
    gJiminyRikuStoryTale2Line4, gJiminyRikuStoryTale2Line5, gJiminyRikuStoryTale2Line6, gJiminyRikuStoryTale2Line7,
    gJiminyRikuStoryTale2Line8, gJiminyRikuStoryTale2Line9, gJiminyRikuStoryTale2Line10, gJiminyRikuStoryTale2Line11,
    gJiminyRikuStoryTale2Line12, gJiminyRikuStoryTale2Line13, gJiminyRikuStoryTale2Line14, gJiminyRikuStoryTale2Line15,
    gJiminyRikuStoryTale2Line16, gJiminyRikuStoryTale2Line17, gJiminyRikuStoryTale2Line18, gJiminyRikuStoryTale2Line19,
    gJiminyRikuStoryTale2Line20, gJiminyRikuStoryTale2Line21, gJiminyRikuStoryTale2Line22, gJiminyRikuStoryTale2Line23,
    gJiminyRikuStoryTale2Line24, gJiminyRikuStoryTale2Line25,
};

JiminyTextChar* gJiminyRikuStoryTale3Lines[20] = {
    gJiminyRikuStoryTale3Line0, gJiminyRikuStoryTale3Line1, gJiminyRikuStoryTale3Line2, gJiminyRikuStoryTale3Line3,
    gJiminyRikuStoryTale3Line4, gJiminyRikuStoryTale3Line5, gJiminyRikuStoryTale3Line6, gJiminyRikuStoryTale3Line7,
    gJiminyRikuStoryTale3Line8, gJiminyRikuStoryTale3Line9, gJiminyRikuStoryTale3Line10, gJiminyRikuStoryTale3Line11,
    gJiminyRikuStoryTale3Line12, gJiminyRikuStoryTale3Line13, gJiminyRikuStoryTale3Line14, gJiminyRikuStoryTale3Line15,
    gJiminyRikuStoryTale3Line16, gJiminyRikuStoryTale3Line17, gJiminyRikuStoryTale3Line18, gJiminyRikuStoryTale3Line19,
};

JiminyTextChar* gJiminyRikuStoryTale5Lines[23] = {
    gJiminyRikuStoryTale5Line0, gJiminyRikuStoryTale5Line1, gJiminyRikuStoryTale5Line2, gJiminyRikuStoryTale5Line3,
    gJiminyRikuStoryTale5Line4, gJiminyRikuStoryTale5Line5, gJiminyRikuStoryTale5Line6, gJiminyRikuStoryTale5Line7,
    gJiminyRikuStoryTale5Line8, gJiminyRikuStoryTale5Line9, gJiminyRikuStoryTale5Line10, gJiminyRikuStoryTale5Line11,
    gJiminyRikuStoryTale5Line12, gJiminyRikuStoryTale5Line13, gJiminyRikuStoryTale5Line14, gJiminyRikuStoryTale5Line15,
    gJiminyRikuStoryTale5Line16, gJiminyRikuStoryTale5Line17, gJiminyRikuStoryTale5Line18, gJiminyRikuStoryTale5Line19,
    gJiminyRikuStoryTale5Line20, gJiminyRikuStoryTale5Line21, gJiminyRikuStoryTale5Line22,
};

JiminyTextChar* gJiminyRikuCardSoulEaterLines[4] = {
    gJiminyRikuCardSoulEaterLine0, gJiminyRikuCardSoulEaterLine1, gJiminyRikuCardSoulEaterLine2, gJiminyRikuCardSoulEaterLine3,
};

JiminyTextChar* gJiminyCharacterSoraLines[15] = {
    gJiminyCharacterSoraLine0, gJiminyCharacterSoraLine1, gJiminyCharacterSoraLine2, gJiminyCharacterSoraLine3,
    gJiminyCharacterSoraLine4, gJiminyCharacterSoraLine5, gJiminyCharacterSoraLine6, gJiminyCharacterSoraLine7,
    gJiminyCharacterSoraLine8, gJiminyCharacterSoraLine9, gJiminyCharacterSoraLine10, gJiminyCharacterSoraLine11,
    gJiminyCharacterSoraLine12, gJiminyCharacterSoraLine13, gJiminyCharacterSoraLine14,
};

JiminyTextChar* gJiminyCharacterDonaldDuckLines[16] = {
    gJiminyCharacterDonaldDuckLine0, gJiminyCharacterDonaldDuckLine1, gJiminyCharacterDonaldDuckLine2, gJiminyCharacterDonaldDuckLine3,
    gJiminyCharacterDonaldDuckLine4, gJiminyCharacterDonaldDuckLine5, gJiminyCharacterDonaldDuckLine6, gJiminyCharacterDonaldDuckLine7,
    gJiminyCharacterDonaldDuckLine8, gJiminyCharacterDonaldDuckLine9, gJiminyCharacterDonaldDuckLine10, gJiminyCharacterDonaldDuckLine11,
    gJiminyCharacterDonaldDuckLine12, gJiminyCharacterDonaldDuckLine13, gJiminyCharacterDonaldDuckLine14, gJiminyCharacterDonaldDuckLine15,
};

JiminyTextChar* gJiminyCharacterGoofyLines[12] = {
    gJiminyCharacterGoofyLine0, gJiminyCharacterGoofyLine1, gJiminyCharacterGoofyLine2, gJiminyCharacterGoofyLine3,
    gJiminyCharacterGoofyLine4, gJiminyCharacterGoofyLine5, gJiminyCharacterGoofyLine6, gJiminyCharacterGoofyLine7,
    gJiminyCharacterGoofyLine8, gJiminyCharacterGoofyLine9, gJiminyCharacterGoofyLine10, gJiminyCharacterGoofyLine11,
};

JiminyTextChar* gJiminyCharacterJiminyCricketLines[7] = {
    gJiminyCharacterJiminyCricketLine0, gJiminyCharacterJiminyCricketLine1, gJiminyCharacterJiminyCricketLine2, gJiminyCharacterJiminyCricketLine3,
    gJiminyCharacterJiminyCricketLine4, gJiminyCharacterJiminyCricketLine5, gJiminyCharacterJiminyCricketLine6,
};

JiminyTextChar* gJiminyCharacterRikuLines[16] = {
    gJiminyCharacterRikuLine0, gJiminyBlankLine, gJiminyCharacterRikuLine2, gJiminyCharacterRikuLine3,
    gJiminyCharacterRikuLine4, gJiminyCharacterRikuLine5, gJiminyCharacterRikuLine6, gJiminyCharacterRikuLine7,
    gJiminyCharacterRikuLine8, gJiminyCharacterRikuLine9, gJiminyCharacterRikuLine10, gJiminyCharacterRikuLine11,
    gJiminyCharacterRikuLine12, gJiminyCharacterRikuLine13, gJiminyCharacterRikuLine14, gJiminyCharacterRikuLine15,
};

JiminyTextChar* gJiminyCharacterSimbaLines[7] = {
    gJiminyCharacterSimbaLine0, gJiminyCharacterSimbaLine1, gJiminyCharacterSimbaLine2, gJiminyCharacterSimbaLine3,
    gJiminyCharacterSimbaLine4, gJiminyCharacterSimbaLine5, gJiminyCharacterSimbaLine6,
};

JiminyTextChar* gJiminyCharacterDumboLines[11] = {
    gJiminyCharacterDumboLine0, gJiminyCharacterDumboLine1, gJiminyCharacterDumboLine2, gJiminyCharacterDumboLine3,
    gJiminyCharacterDumboLine4, gJiminyCharacterDumboLine5, gJiminyCharacterDumboLine6, gJiminyCharacterDumboLine7,
    gJiminyCharacterDumboLine8, gJiminyCharacterDumboLine9, gJiminyCharacterDumboLine10,
};

JiminyTextChar* gJiminyCharacterBambiLines[6] = {
    gJiminyCharacterBambiLine0, gJiminyCharacterBambiLine1, gJiminyCharacterBambiLine2, gJiminyCharacterBambiLine3,
    gJiminyCharacterBambiLine4, gJiminyCharacterBambiLine5,
};

JiminyTextChar* gJiminyCharacterMushuLines[8] = {
    gJiminyCharacterMushuLine0, gJiminyCharacterMushuLine1, gJiminyCharacterMushuLine2, gJiminyCharacterMushuLine3,
    gJiminyCharacterMushuLine4, gJiminyCharacterMushuLine5, gJiminyCharacterMushuLine6, gJiminyCharacterMushuLine7,
};

JiminyTextChar* gJiminyCharacterMooglesLines[8] = {
    gJiminyCharacterMooglesLine0, gJiminyCharacterMooglesLine1, gJiminyCharacterMooglesLine2, gJiminyCharacterMooglesLine3,
    gJiminyCharacterMooglesLine4, gJiminyCharacterMooglesLine5, gJiminyCharacterMooglesLine6, gJiminyCharacterMooglesLine7,
};

JiminyTextChar* gJiminyCharacterLeonLines[13] = {
    gJiminyCharacterLeonLine0, gJiminyCharacterLeonLine1, gJiminyCharacterLeonLine2, gJiminyCharacterLeonLine3,
    gJiminyCharacterLeonLine4, gJiminyCharacterLeonLine5, gJiminyCharacterLeonLine6, gJiminyCharacterLeonLine7,
    gJiminyCharacterLeonLine8, gJiminyCharacterLeonLine9, gJiminyCharacterLeonLine10, gJiminyCharacterLeonLine11,
    gJiminyCharacterLeonLine12,
};

JiminyTextChar* gJiminyCharacterYuffieLines[11] = {
    gJiminyCharacterYuffieLine0, gJiminyCharacterYuffieLine1, gJiminyCharacterYuffieLine2, gJiminyCharacterYuffieLine3,
    gJiminyCharacterYuffieLine4, gJiminyCharacterYuffieLine5, gJiminyCharacterYuffieLine6, gJiminyCharacterYuffieLine7,
    gJiminyCharacterYuffieLine8, gJiminyCharacterYuffieLine9, gJiminyCharacterYuffieLine10,
};

JiminyTextChar* gJiminyCharacterAerithLines[12] = {
    gJiminyCharacterAerithLine0, gJiminyCharacterAerithLine1, gJiminyCharacterAerithLine2, gJiminyCharacterAerithLine3,
    gJiminyCharacterAerithLine4, gJiminyCharacterAerithLine5, gJiminyCharacterAerithLine6, gJiminyCharacterAerithLine7,
    gJiminyCharacterAerithLine8, gJiminyCharacterAerithLine9, gJiminyCharacterAerithLine10, gJiminyCharacterAerithLine11,
};

JiminyTextChar* gJiminyCharacterCidLines[8] = {
    gJiminyCharacterCidLine0, gJiminyCharacterCidLine1, gJiminyCharacterCidLine2, gJiminyCharacterCidLine3,
    gJiminyCharacterCidLine4, gJiminyCharacterCidLine5, gJiminyCharacterCidLine6, gJiminyCharacterCidLine7,
};

JiminyTextChar* gJiminyCharacterCloudLines[10] = {
    gJiminyCharacterCloudLine0, gJiminyCharacterCloudLine1, gJiminyCharacterCloudLine2, gJiminyCharacterCloudLine3,
    gJiminyCharacterCloudLine4, gJiminyCharacterCloudLine5, gJiminyCharacterCloudLine6, gJiminyCharacterCloudLine7,
    gJiminyCharacterCloudLine8, gJiminyCharacterCloudLine9,
};

JiminyTextChar* gJiminyCharacterNamineLines[15] = {
    gJiminyCharacterNamineLine0, gJiminyCharacterNamineLine1, gJiminyCharacterNamineLine2, gJiminyCharacterNamineLine3,
    gJiminyCharacterNamineLine4, gJiminyCharacterNamineLine5, gJiminyCharacterNamineLine6, gJiminyCharacterNamineLine7,
    gJiminyCharacterNamineLine8, gJiminyCharacterNamineLine9, gJiminyCharacterNamineLine10, gJiminyCharacterNamineLine11,
    gJiminyCharacterNamineLine12, gJiminyCharacterNamineLine13, gJiminyCharacterNamineLine14,
};

JiminyTextChar* gJiminyCharacterRikuReplicaLines[12] = {
    gJiminyCharacterRikuReplicaLine0, gJiminyCharacterRikuReplicaLine1, gJiminyCharacterRikuReplicaLine2, gJiminyCharacterRikuReplicaLine3,
    gJiminyCharacterRikuReplicaLine4, gJiminyCharacterRikuReplicaLine5, gJiminyCharacterRikuReplicaLine6, gJiminyCharacterRikuReplicaLine7,
    gJiminyCharacterRikuReplicaLine8, gJiminyCharacterRikuReplicaLine9, gJiminyCharacterRikuReplicaLine10, gJiminyCharacterRikuReplicaLine11,
};

JiminyTextChar* gJiminyCharacterAxelLines[11] = {
    gJiminyCharacterAxelLine0, gJiminyCharacterAxelLine1, gJiminyCharacterAxelLine2, gJiminyCharacterAxelLine3,
    gJiminyCharacterAxelLine4, gJiminyCharacterAxelLine5, gJiminyCharacterAxelLine6, gJiminyCharacterAxelLine7,
    gJiminyCharacterAxelLine8, gJiminyCharacterAxelLine9, gJiminyCharacterAxelLine10,
};

JiminyTextChar* gJiminyCharacterVexenLines[11] = {
    gJiminyCharacterVexenLine0, gJiminyCharacterVexenLine1, gJiminyCharacterVexenLine2, gJiminyCharacterVexenLine3,
    gJiminyCharacterVexenLine4, gJiminyCharacterVexenLine5, gJiminyCharacterVexenLine6, gJiminyCharacterVexenLine7,
    gJiminyCharacterVexenLine8, gJiminyCharacterVexenLine9, gJiminyCharacterVexenLine10,
};

JiminyTextChar* gJiminyCharacterMarluxiaLines[10] = {
    gJiminyCharacterMarluxiaLine0, gJiminyCharacterMarluxiaLine1, gJiminyCharacterMarluxiaLine2, gJiminyCharacterMarluxiaLine3,
    gJiminyCharacterMarluxiaLine4, gJiminyCharacterMarluxiaLine5, gJiminyCharacterMarluxiaLine6, gJiminyCharacterMarluxiaLine7,
    gJiminyCharacterMarluxiaLine8, gJiminyCharacterMarluxiaLine9,
};

JiminyTextChar* gJiminyCharacterAladdinLines[16] = {
    gJiminyCharacterAladdinLine0, gJiminyCharacterAladdinLine1, gJiminyCharacterAladdinLine2, gJiminyCharacterAladdinLine3,
    gJiminyCharacterAladdinLine4, gJiminyCharacterAladdinLine5, gJiminyCharacterAladdinLine6, gJiminyCharacterAladdinLine7,
    gJiminyCharacterAladdinLine8, gJiminyCharacterAladdinLine9, gJiminyCharacterAladdinLine10, gJiminyCharacterAladdinLine11,
    gJiminyCharacterAladdinLine12, gJiminyCharacterAladdinLine13, gJiminyCharacterAladdinLine14, gJiminyCharacterAladdinLine15,
};

JiminyTextChar* gJiminyCharacterGenieLines[11] = {
    gJiminyCharacterGenieLine0, gJiminyCharacterGenieLine1, gJiminyCharacterGenieLine2, gJiminyCharacterGenieLine3,
    gJiminyCharacterGenieLine4, gJiminyCharacterGenieLine5, gJiminyCharacterGenieLine6, gJiminyCharacterGenieLine7,
    gJiminyCharacterGenieLine8, gJiminyCharacterGenieLine9, gJiminyCharacterGenieLine10,
};

JiminyTextChar* gJiminyCharacterJasmineLines[6] = {
    gJiminyCharacterJasmineLine0, gJiminyCharacterJasmineLine1, gJiminyCharacterJasmineLine2, gJiminyCharacterJasmineLine3,
    gJiminyCharacterJasmineLine4, gJiminyCharacterJasmineLine5,
};

JiminyTextChar* gJiminyCharacterIagoLines[7] = {
    gJiminyCharacterIagoLine0, gJiminyCharacterIagoLine1, gJiminyCharacterIagoLine2, gJiminyCharacterIagoLine3,
    gJiminyCharacterIagoLine4, gJiminyCharacterIagoLine5, gJiminyCharacterIagoLine6,
};

JiminyTextChar* gJiminyCharacterJafarLines[8] = {
    gJiminyCharacterJafarLine0, gJiminyCharacterJafarLine1, gJiminyCharacterJafarLine2, gJiminyCharacterJafarLine3,
    gJiminyCharacterJafarLine4, gJiminyCharacterJafarLine5, gJiminyCharacterJafarLine6, gJiminyCharacterJafarLine7,
};

JiminyTextChar* gJiminyCharacterJafarGenieLines[7] = {
    gJiminyCharacterJafarGenieLine0, gJiminyCharacterJafarGenieLine1, gJiminyCharacterJafarGenieLine2, gJiminyCharacterJafarGenieLine3,
    gJiminyCharacterJafarGenieLine4, gJiminyCharacterJafarGenieLine5, gJiminyCharacterJafarGenieLine6,
};

JiminyTextChar* gJiminyCharacterJackLines[7] = {
    gJiminyCharacterJackLine0, gJiminyCharacterJackLine1, gJiminyCharacterJackLine2, gJiminyCharacterJackLine3,
    gJiminyCharacterJackLine4, gJiminyCharacterJackLine5, gJiminyCharacterJackLine6,
};

JiminyTextChar* gJiminyCharacterSallyLines[7] = {
    gJiminyCharacterSallyLine0, gJiminyCharacterSallyLine1, gJiminyCharacterSallyLine2, gJiminyCharacterSallyLine3,
    gJiminyCharacterSallyLine4, gJiminyCharacterSallyLine5, gJiminyCharacterSallyLine6,
};

JiminyTextChar* gJiminyCharacterDrFinkelsteinLines[10] = {
    gJiminyCharacterDrFinkelsteinLine0, gJiminyCharacterDrFinkelsteinLine1, gJiminyCharacterDrFinkelsteinLine2, gJiminyCharacterDrFinkelsteinLine3,
    gJiminyCharacterDrFinkelsteinLine4, gJiminyCharacterDrFinkelsteinLine5, gJiminyCharacterDrFinkelsteinLine6, gJiminyCharacterDrFinkelsteinLine7,
    gJiminyCharacterDrFinkelsteinLine8, gJiminyCharacterDrFinkelsteinLine9,
};

JiminyTextChar* gJiminyCharacterOogieBoogieLines[9] = {
    gJiminyCharacterOogieBoogieLine0, gJiminyCharacterOogieBoogieLine1, gJiminyCharacterOogieBoogieLine2, gJiminyCharacterOogieBoogieLine3,
    gJiminyCharacterOogieBoogieLine4, gJiminyCharacterOogieBoogieLine5, gJiminyCharacterOogieBoogieLine6, gJiminyCharacterOogieBoogieLine7,
    gJiminyCharacterOogieBoogieLine8,
};

JiminyTextChar* gJiminyCharacterPinocchioLines[13] = {
    gJiminyCharacterPinocchioLine0, gJiminyCharacterPinocchioLine1, gJiminyCharacterPinocchioLine2, gJiminyCharacterPinocchioLine3,
    gJiminyCharacterPinocchioLine4, gJiminyCharacterPinocchioLine5, gJiminyCharacterPinocchioLine6, gJiminyCharacterPinocchioLine7,
    gJiminyCharacterPinocchioLine8, gJiminyCharacterPinocchioLine9, gJiminyCharacterPinocchioLine10, gJiminyCharacterPinocchioLine11,
    gJiminyCharacterPinocchioLine12,
};

JiminyTextChar* gJiminyCharacterGeppettoLines[14] = {
    gJiminyCharacterGeppettoLine0, gJiminyCharacterGeppettoLine1, gJiminyCharacterGeppettoLine2, gJiminyCharacterGeppettoLine3,
    gJiminyCharacterGeppettoLine4, gJiminyCharacterGeppettoLine5, gJiminyCharacterGeppettoLine6, gJiminyCharacterGeppettoLine7,
    gJiminyCharacterGeppettoLine8, gJiminyCharacterGeppettoLine9, gJiminyCharacterGeppettoLine10, gJiminyCharacterGeppettoLine11,
    gJiminyCharacterGeppettoLine12, gJiminyCharacterGeppettoLine13,
};

JiminyTextChar* gJiminyCharacterHerculesLines[10] = {
    gJiminyCharacterHerculesLine0, gJiminyCharacterHerculesLine1, gJiminyCharacterHerculesLine2, gJiminyCharacterHerculesLine3,
    gJiminyCharacterHerculesLine4, gJiminyCharacterHerculesLine5, gJiminyCharacterHerculesLine6, gJiminyCharacterHerculesLine7,
    gJiminyCharacterHerculesLine8, gJiminyCharacterHerculesLine9,
};

JiminyTextChar* gJiminyCharacterPhiloctetesLines[7] = {
    gJiminyCharacterPhiloctetesLine0, gJiminyCharacterPhiloctetesLine1, gJiminyCharacterPhiloctetesLine2, gJiminyCharacterPhiloctetesLine3,
    gJiminyCharacterPhiloctetesLine4, gJiminyCharacterPhiloctetesLine5, gJiminyCharacterPhiloctetesLine6,
};

JiminyTextChar* gJiminyCharacterHadesLines[9] = {
    gJiminyCharacterHadesLine0, gJiminyCharacterHadesLine1, gJiminyCharacterHadesLine2, gJiminyCharacterHadesLine3,
    gJiminyCharacterHadesLine4, gJiminyCharacterHadesLine5, gJiminyCharacterHadesLine6, gJiminyCharacterHadesLine7,
    gJiminyCharacterHadesLine8,
};

JiminyTextChar* gJiminyCharacterAliceLines[11] = {
    gJiminyCharacterAliceLine0, gJiminyCharacterAliceLine1, gJiminyCharacterAliceLine2, gJiminyCharacterAliceLine3,
    gJiminyCharacterAliceLine4, gJiminyCharacterAliceLine5, gJiminyCharacterAliceLine6, gJiminyCharacterAliceLine7,
    gJiminyCharacterAliceLine8, gJiminyCharacterAliceLine9, gJiminyCharacterAliceLine10,
};

JiminyTextChar* gJiminyCharacterQueenOfHeartsLines[8] = {
    gJiminyCharacterQueenOfHeartsLine0, gJiminyCharacterQueenOfHeartsLine1, gJiminyCharacterQueenOfHeartsLine2, gJiminyCharacterQueenOfHeartsLine3,
    gJiminyCharacterQueenOfHeartsLine4, gJiminyCharacterQueenOfHeartsLine5, gJiminyCharacterQueenOfHeartsLine6, gJiminyCharacterQueenOfHeartsLine7,
};

JiminyTextChar* gJiminyCharacterWhiteRabbitLines[7] = {
    gJiminyCharacterWhiteRabbitLine0, gJiminyCharacterWhiteRabbitLine1, gJiminyCharacterWhiteRabbitLine2, gJiminyCharacterWhiteRabbitLine3,
    gJiminyCharacterWhiteRabbitLine4, gJiminyCharacterWhiteRabbitLine5, gJiminyCharacterWhiteRabbitLine6,
};

JiminyTextChar* gJiminyCharacterCardOfHeartsLines[6] = {
    gJiminyCharacterCardOfHeartsLine0, gJiminyCharacterCardOfHeartsLine1, gJiminyCharacterCardOfHeartsLine2, gJiminyCharacterCardOfHeartsLine3,
    gJiminyCharacterCardOfHeartsLine4, gJiminyCharacterCardOfHeartsLine5,
};

JiminyTextChar* gJiminyCharacterCardOfSpadesLines[6] = {
    gJiminyCharacterCardOfSpadesLine0, gJiminyCharacterCardOfSpadesLine1, gJiminyCharacterCardOfSpadesLine2, gJiminyCharacterCardOfSpadesLine3,
    gJiminyCharacterCardOfSpadesLine4, gJiminyCharacterCardOfSpadesLine5,
};

JiminyTextChar* gJiminyCharacterCheshireCatLines[8] = {
    gJiminyCharacterCheshireCatLine0, gJiminyCharacterCheshireCatLine1, gJiminyCharacterCheshireCatLine2, gJiminyCharacterCheshireCatLine3,
    gJiminyCharacterCheshireCatLine4, gJiminyCharacterCheshireCatLine5, gJiminyCharacterCheshireCatLine6, gJiminyCharacterCheshireCatLine7,
};

JiminyTextChar* gJiminyCharacterSebastianLines[8] = {
    gJiminyCharacterSebastianLine0, gJiminyCharacterSebastianLine1, gJiminyCharacterSebastianLine2, gJiminyCharacterSebastianLine3,
    gJiminyCharacterSebastianLine4, gJiminyCharacterSebastianLine5, gJiminyCharacterSebastianLine6, gJiminyCharacterSebastianLine7,
};

JiminyTextChar* gJiminyCharacterFlounderLines[10] = {
    gJiminyCharacterFlounderLine0, gJiminyCharacterFlounderLine1, gJiminyCharacterFlounderLine2, gJiminyCharacterFlounderLine3,
    gJiminyCharacterFlounderLine4, gJiminyCharacterFlounderLine5, gJiminyCharacterFlounderLine6, gJiminyCharacterFlounderLine7,
    gJiminyCharacterFlounderLine8, gJiminyCharacterFlounderLine9,
};

JiminyTextChar* gJiminyCharacterUrsulaLines[9] = {
    gJiminyCharacterUrsulaLine0, gJiminyCharacterUrsulaLine1, gJiminyCharacterUrsulaLine2, gJiminyCharacterUrsulaLine3,
    gJiminyCharacterUrsulaLine4, gJiminyCharacterUrsulaLine5, gJiminyCharacterUrsulaLine6, gJiminyCharacterUrsulaLine7,
    gJiminyCharacterUrsulaLine8,
};

JiminyTextChar* gJiminyCharacterPeterPanLines[13] = {
    gJiminyCharacterPeterPanLine0, gJiminyCharacterPeterPanLine1, gJiminyCharacterPeterPanLine2, gJiminyCharacterPeterPanLine3,
    gJiminyCharacterPeterPanLine4, gJiminyCharacterPeterPanLine5, gJiminyCharacterPeterPanLine6, gJiminyCharacterPeterPanLine7,
    gJiminyCharacterPeterPanLine8, gJiminyCharacterPeterPanLine9, gJiminyCharacterPeterPanLine10, gJiminyCharacterPeterPanLine11,
    gJiminyCharacterPeterPanLine12,
};

JiminyTextChar* gJiminyCharacterTinkerBellLines[4] = {
    gJiminyCharacterTinkerBellLine0, gJiminyCharacterTinkerBellLine1, gJiminyCharacterTinkerBellLine2, gJiminyCharacterTinkerBellLine3,
};

JiminyTextChar* gJiminyCharacterWendyLines[7] = {
    gJiminyCharacterWendyLine0, gJiminyCharacterWendyLine1, gJiminyCharacterWendyLine2, gJiminyCharacterWendyLine3,
    gJiminyCharacterWendyLine4, gJiminyCharacterWendyLine5, gJiminyCharacterWendyLine6,
};

JiminyTextChar* gJiminyCharacterHookLines[12] = {
    gJiminyCharacterHookLine0, gJiminyCharacterHookLine1, gJiminyCharacterHookLine2, gJiminyCharacterHookLine3,
    gJiminyCharacterHookLine4, gJiminyCharacterHookLine5, gJiminyCharacterHookLine6, gJiminyCharacterHookLine7,
    gJiminyCharacterHookLine8, gJiminyCharacterHookLine9, gJiminyCharacterHookLine10, gJiminyCharacterHookLine11,
};

JiminyTextChar* gJiminyCharacterBeastLines[10] = {
    gJiminyCharacterBeastLine0, gJiminyCharacterBeastLine1, gJiminyCharacterBeastLine2, gJiminyCharacterBeastLine3,
    gJiminyCharacterBeastLine4, gJiminyCharacterBeastLine5, gJiminyCharacterBeastLine6, gJiminyCharacterBeastLine7,
    gJiminyCharacterBeastLine8, gJiminyCharacterBeastLine9,
};

JiminyTextChar* gJiminyCharacterBelleLines[11] = {
    gJiminyCharacterBelleLine0, gJiminyCharacterBelleLine1, gJiminyCharacterBelleLine2, gJiminyCharacterBelleLine3,
    gJiminyCharacterBelleLine4, gJiminyCharacterBelleLine5, gJiminyCharacterBelleLine6, gJiminyCharacterBelleLine7,
    gJiminyCharacterBelleLine8, gJiminyCharacterBelleLine9, gJiminyCharacterBelleLine10,
};

JiminyTextChar* gJiminyCharacterMaleficentLines[11] = {
    gJiminyCharacterMaleficentLine0, gJiminyCharacterMaleficentLine1, gJiminyCharacterMaleficentLine2, gJiminyCharacterMaleficentLine3,
    gJiminyCharacterMaleficentLine4, gJiminyCharacterMaleficentLine5, gJiminyCharacterMaleficentLine6, gJiminyCharacterMaleficentLine7,
    gJiminyCharacterMaleficentLine8, gJiminyCharacterMaleficentLine9, gJiminyCharacterMaleficentLine10,
};

JiminyTextChar* gJiminyCharacterDragonMaleficentLines[8] = {
    gJiminyCharacterDragonMaleficentLine0, gJiminyCharacterDragonMaleficentLine1, gJiminyCharacterDragonMaleficentLine2, gJiminyCharacterDragonMaleficentLine3,
    gJiminyCharacterDragonMaleficentLine4, gJiminyCharacterDragonMaleficentLine5, gJiminyCharacterDragonMaleficentLine6, gJiminyCharacterDragonMaleficentLine7,
};

JiminyTextChar* gJiminyCharacterPigletLines[6] = {
    gJiminyCharacterPigletLine0, gJiminyCharacterPigletLine1, gJiminyCharacterPigletLine2, gJiminyCharacterPigletLine3,
    gJiminyCharacterPigletLine4, gJiminyCharacterPigletLine5,
};

JiminyTextChar* gJiminyCharacterOwlLines[6] = {
    gJiminyCharacterOwlLine0, gJiminyCharacterOwlLine1, gJiminyCharacterOwlLine2, gJiminyCharacterOwlLine3,
    gJiminyCharacterOwlLine4, gJiminyCharacterOwlLine5,
};

JiminyTextChar* gJiminyCharacterRooLines[6] = {
    gJiminyCharacterRooLine0, gJiminyCharacterRooLine1, gJiminyCharacterRooLine2, gJiminyCharacterRooLine3,
    gJiminyCharacterRooLine4, gJiminyCharacterRooLine5,
};

JiminyTextChar* gJiminyCharacterEeyoreLines[8] = {
    gJiminyCharacterEeyoreLine0, gJiminyCharacterEeyoreLine1, gJiminyCharacterEeyoreLine2, gJiminyCharacterEeyoreLine3,
    gJiminyCharacterEeyoreLine4, gJiminyCharacterEeyoreLine5, gJiminyCharacterEeyoreLine6, gJiminyCharacterEeyoreLine7,
};

JiminyTextChar* gJiminyCharacterTiggerLines[8] = {
    gJiminyCharacterTiggerLine0, gJiminyCharacterTiggerLine1, gJiminyCharacterTiggerLine2, gJiminyCharacterTiggerLine3,
    gJiminyCharacterTiggerLine4, gJiminyCharacterTiggerLine5, gJiminyCharacterTiggerLine6, gJiminyCharacterTiggerLine7,
};

JiminyTextChar* gJiminyCharacterRabbitLines[9] = {
    gJiminyCharacterRabbitLine0, gJiminyCharacterRabbitLine1, gJiminyCharacterRabbitLine2, gJiminyCharacterRabbitLine3,
    gJiminyCharacterRabbitLine4, gJiminyCharacterRabbitLine5, gJiminyCharacterRabbitLine6, gJiminyCharacterRabbitLine7,
    gJiminyCharacterRabbitLine8,
};

JiminyTextChar* gJiminyHeartlessGuardArmorLines[6] = {
    gJiminyHeartlessGuardArmorLine0, gJiminyHeartlessGuardArmorLine1, gJiminyHeartlessGuardArmorLine2, gJiminyHeartlessGuardArmorLine3,
    gJiminyHeartlessGuardArmorLine4, gJiminyHeartlessGuardArmorLine5,
};

JiminyTextChar* gJiminyHeartlessParasiteCageLines[10] = {
    gJiminyHeartlessParasiteCageLine0, gJiminyHeartlessParasiteCageLine1, gJiminyHeartlessParasiteCageLine2, gJiminyHeartlessParasiteCageLine3,
    gJiminyHeartlessParasiteCageLine4, gJiminyHeartlessParasiteCageLine5, gJiminyHeartlessParasiteCageLine6, gJiminyHeartlessParasiteCageLine7,
    gJiminyHeartlessParasiteCageLine8, gJiminyHeartlessParasiteCageLine9,
};

JiminyTextChar* gJiminyHeartlessTrickmasterLines[8] = {
    gJiminyHeartlessTrickmasterLine0, gJiminyHeartlessTrickmasterLine1, gJiminyHeartlessTrickmasterLine2, gJiminyHeartlessTrickmasterLine3,
    gJiminyHeartlessTrickmasterLine4, gJiminyHeartlessTrickmasterLine5, gJiminyHeartlessTrickmasterLine6, gJiminyHeartlessTrickmasterLine7,
};

JiminyTextChar* gJiminyHeartlessShadowLines[9] = {
    gJiminyHeartlessShadowLine0, gJiminyHeartlessShadowLine1, gJiminyHeartlessShadowLine2, gJiminyHeartlessShadowLine3,
    gJiminyHeartlessShadowLine4, gJiminyHeartlessShadowLine5, gJiminyHeartlessShadowLine6, gJiminyHeartlessShadowLine7,
    gJiminyHeartlessShadowLine8,
};

JiminyTextChar* gJiminyHeartlessSoldierLines[7] = {
    gJiminyHeartlessSoldierLine0, gJiminyHeartlessSoldierLine1, gJiminyHeartlessSoldierLine2, gJiminyHeartlessSoldierLine3,
    gJiminyHeartlessSoldierLine4, gJiminyHeartlessSoldierLine5, gJiminyHeartlessSoldierLine6,
};

JiminyTextChar* gJiminyHeartlessLargeBodyLines[10] = {
    gJiminyHeartlessLargeBodyLine0, gJiminyHeartlessLargeBodyLine1, gJiminyHeartlessLargeBodyLine2, gJiminyHeartlessLargeBodyLine3,
    gJiminyHeartlessLargeBodyLine4, gJiminyHeartlessLargeBodyLine5, gJiminyHeartlessLargeBodyLine6, gJiminyHeartlessLargeBodyLine7,
    gJiminyHeartlessLargeBodyLine8, gJiminyHeartlessLargeBodyLine9,
};

JiminyTextChar* gJiminyHeartlessRedNocturneLines[9] = {
    gJiminyHeartlessRedNocturneLine0, gJiminyHeartlessRedNocturneLine1, gJiminyHeartlessRedNocturneLine2, gJiminyHeartlessRedNocturneLine3,
    gJiminyHeartlessRedNocturneLine4, gJiminyHeartlessRedNocturneLine5, gJiminyHeartlessRedNocturneLine6, gJiminyHeartlessRedNocturneLine7,
    gJiminyHeartlessRedNocturneLine8,
};

JiminyTextChar* gJiminyHeartlessBlueRhapsodyLines[9] = {
    gJiminyHeartlessBlueRhapsodyLine0, gJiminyHeartlessBlueRhapsodyLine1, gJiminyHeartlessBlueRhapsodyLine2, gJiminyHeartlessBlueRhapsodyLine3,
    gJiminyHeartlessBlueRhapsodyLine4, gJiminyHeartlessBlueRhapsodyLine5, gJiminyHeartlessBlueRhapsodyLine6, gJiminyHeartlessBlueRhapsodyLine7,
    gJiminyHeartlessBlueRhapsodyLine8,
};

JiminyTextChar* gJiminyHeartlessYellowOperaLines[9] = {
    gJiminyHeartlessYellowOperaLine0, gJiminyHeartlessYellowOperaLine1, gJiminyHeartlessYellowOperaLine2, gJiminyHeartlessYellowOperaLine3,
    gJiminyHeartlessYellowOperaLine4, gJiminyHeartlessYellowOperaLine5, gJiminyHeartlessYellowOperaLine6, gJiminyHeartlessYellowOperaLine7,
    gJiminyHeartlessYellowOperaLine8,
};

JiminyTextChar* gJiminyHeartlessGreenRequiemLines[11] = {
    gJiminyHeartlessGreenRequiemLine0, gJiminyHeartlessGreenRequiemLine1, gJiminyHeartlessGreenRequiemLine2, gJiminyHeartlessGreenRequiemLine3,
    gJiminyHeartlessGreenRequiemLine4, gJiminyHeartlessGreenRequiemLine5, gJiminyHeartlessGreenRequiemLine6, gJiminyHeartlessGreenRequiemLine7,
    gJiminyHeartlessGreenRequiemLine8, gJiminyHeartlessGreenRequiemLine9, gJiminyHeartlessGreenRequiemLine10,
};

JiminyTextChar* gJiminyHeartlessPowerwildLines[7] = {
    gJiminyHeartlessPowerwildLine0, gJiminyHeartlessPowerwildLine1, gJiminyHeartlessPowerwildLine2, gJiminyHeartlessPowerwildLine3,
    gJiminyHeartlessPowerwildLine4, gJiminyHeartlessPowerwildLine5, gJiminyHeartlessPowerwildLine6,
};

JiminyTextChar* gJiminyHeartlessBouncywildLines[6] = {
    gJiminyHeartlessBouncywildLine0, gJiminyHeartlessBouncywildLine1, gJiminyHeartlessBouncywildLine2, gJiminyHeartlessBouncywildLine3,
    gJiminyHeartlessBouncywildLine4, gJiminyHeartlessBouncywildLine5,
};

JiminyTextChar* gJiminyHeartlessAirSoldierLines[10] = {
    gJiminyHeartlessAirSoldierLine0, gJiminyHeartlessAirSoldierLine1, gJiminyHeartlessAirSoldierLine2, gJiminyHeartlessAirSoldierLine3,
    gJiminyHeartlessAirSoldierLine4, gJiminyHeartlessAirSoldierLine5, gJiminyHeartlessAirSoldierLine6, gJiminyHeartlessAirSoldierLine7,
    gJiminyHeartlessAirSoldierLine8, gJiminyHeartlessAirSoldierLine9,
};

JiminyTextChar* gJiminyHeartlessBanditLines[7] = {
    gJiminyHeartlessBanditLine0, gJiminyHeartlessBanditLine1, gJiminyHeartlessBanditLine2, gJiminyHeartlessBanditLine3,
    gJiminyHeartlessBanditLine4, gJiminyHeartlessBanditLine5, gJiminyHeartlessBanditLine6,
};

JiminyTextChar* gJiminyHeartlessFatBanditLines[7] = {
    gJiminyHeartlessFatBanditLine0, gJiminyHeartlessFatBanditLine1, gJiminyHeartlessFatBanditLine2, gJiminyHeartlessFatBanditLine3,
    gJiminyHeartlessFatBanditLine4, gJiminyHeartlessFatBanditLine5, gJiminyHeartlessFatBanditLine6,
};

JiminyTextChar* gJiminyHeartlessBarrelSpiderLines[9] = {
    gJiminyHeartlessBarrelSpiderLine0, gJiminyHeartlessBarrelSpiderLine1, gJiminyHeartlessBarrelSpiderLine2, gJiminyHeartlessBarrelSpiderLine3,
    gJiminyHeartlessBarrelSpiderLine4, gJiminyHeartlessBarrelSpiderLine5, gJiminyHeartlessBarrelSpiderLine6, gJiminyHeartlessBarrelSpiderLine7,
    gJiminyHeartlessBarrelSpiderLine8,
};

JiminyTextChar* gJiminyHeartlessSearchGhostLines[7] = {
    gJiminyHeartlessSearchGhostLine0, gJiminyHeartlessSearchGhostLine1, gJiminyHeartlessSearchGhostLine2, gJiminyHeartlessSearchGhostLine3,
    gJiminyHeartlessSearchGhostLine4, gJiminyHeartlessSearchGhostLine5, gJiminyHeartlessSearchGhostLine6,
};

JiminyTextChar* gJiminyHeartlessScrewdiverLines[6] = {
    gJiminyHeartlessScrewdiverLine0, gJiminyHeartlessScrewdiverLine1, gJiminyHeartlessScrewdiverLine2, gJiminyHeartlessScrewdiverLine3,
    gJiminyHeartlessScrewdiverLine4, gJiminyHeartlessScrewdiverLine5,
};

JiminyTextChar* gJiminyHeartlessAquatankLines[8] = {
    gJiminyHeartlessAquatankLine0, gJiminyHeartlessAquatankLine1, gJiminyHeartlessAquatankLine2, gJiminyHeartlessAquatankLine3,
    gJiminyHeartlessAquatankLine4, gJiminyHeartlessAquatankLine5, gJiminyHeartlessAquatankLine6, gJiminyHeartlessAquatankLine7,
};

JiminyTextChar* gJiminyHeartlessWightKnightLines[7] = {
    gJiminyHeartlessWightKnightLine0, gJiminyHeartlessWightKnightLine1, gJiminyHeartlessWightKnightLine2, gJiminyHeartlessWightKnightLine3,
    gJiminyHeartlessWightKnightLine4, gJiminyHeartlessWightKnightLine5, gJiminyHeartlessWightKnightLine6,
};

JiminyTextChar* gJiminyHeartlessGargoyleLines[7] = {
    gJiminyHeartlessGargoyleLine0, gJiminyHeartlessGargoyleLine1, gJiminyHeartlessGargoyleLine2, gJiminyHeartlessGargoyleLine3,
    gJiminyHeartlessGargoyleLine4, gJiminyHeartlessGargoyleLine5, gJiminyHeartlessGargoyleLine6,
};

JiminyTextChar* gJiminyHeartlessPirateLines[10] = {
    gJiminyHeartlessPirateLine0, gJiminyHeartlessPirateLine1, gJiminyHeartlessPirateLine2, gJiminyHeartlessPirateLine3,
    gJiminyHeartlessPirateLine4, gJiminyHeartlessPirateLine5, gJiminyHeartlessPirateLine6, gJiminyHeartlessPirateLine7,
    gJiminyHeartlessPirateLine8, gJiminyHeartlessPirateLine9,
};

JiminyTextChar* gJiminyHeartlessAirPirateLines[9] = {
    gJiminyHeartlessAirPirateLine0, gJiminyHeartlessAirPirateLine1, gJiminyHeartlessAirPirateLine2, gJiminyHeartlessAirPirateLine3,
    gJiminyHeartlessAirPirateLine4, gJiminyHeartlessAirPirateLine5, gJiminyHeartlessAirPirateLine6, gJiminyHeartlessAirPirateLine7,
    gJiminyHeartlessAirPirateLine8,
};

JiminyTextChar* gJiminyHeartlessDarkballLines[9] = {
    gJiminyHeartlessDarkballLine0, gJiminyHeartlessDarkballLine1, gJiminyHeartlessDarkballLine2, gJiminyHeartlessDarkballLine3,
    gJiminyHeartlessDarkballLine4, gJiminyHeartlessDarkballLine5, gJiminyHeartlessDarkballLine6, gJiminyHeartlessDarkballLine7,
    gJiminyHeartlessDarkballLine8,
};

JiminyTextChar* gJiminyHeartlessDefenderLines[13] = {
    gJiminyHeartlessDefenderLine0, gJiminyHeartlessDefenderLine1, gJiminyHeartlessDefenderLine2, gJiminyHeartlessDefenderLine3,
    gJiminyHeartlessDefenderLine4, gJiminyHeartlessDefenderLine5, gJiminyHeartlessDefenderLine6, gJiminyHeartlessDefenderLine7,
    gJiminyHeartlessDefenderLine8, gJiminyHeartlessDefenderLine9, gJiminyHeartlessDefenderLine10, gJiminyHeartlessDefenderLine11,
    gJiminyHeartlessDefenderLine12,
};

JiminyTextChar* gJiminyHeartlessWyvernLines[10] = {
    gJiminyHeartlessWyvernLine0, gJiminyHeartlessWyvernLine1, gJiminyHeartlessWyvernLine2, gJiminyHeartlessWyvernLine3,
    gJiminyHeartlessWyvernLine4, gJiminyHeartlessWyvernLine5, gJiminyHeartlessWyvernLine6, gJiminyHeartlessWyvernLine7,
    gJiminyHeartlessWyvernLine8, gJiminyHeartlessWyvernLine9,
};

JiminyTextChar* gJiminyHeartlessWizardLines[8] = {
    gJiminyHeartlessWizardLine0, gJiminyHeartlessWizardLine1, gJiminyHeartlessWizardLine2, gJiminyHeartlessWizardLine3,
    gJiminyHeartlessWizardLine4, gJiminyHeartlessWizardLine5, gJiminyHeartlessWizardLine6, gJiminyHeartlessWizardLine7,
};

JiminyTextChar* gJiminyHeartlessWhiteMushroomLines[8] = {
    gJiminyHeartlessWhiteMushroomLine0, gJiminyHeartlessWhiteMushroomLine1, gJiminyHeartlessWhiteMushroomLine2, gJiminyHeartlessWhiteMushroomLine3,
    gJiminyHeartlessWhiteMushroomLine4, gJiminyHeartlessWhiteMushroomLine5, gJiminyHeartlessWhiteMushroomLine6, gJiminyHeartlessWhiteMushroomLine7,
};

JiminyTextChar* gJiminyHeartlessBlackFungusLines[12] = {
    gJiminyHeartlessBlackFungusLine0, gJiminyHeartlessBlackFungusLine1, gJiminyHeartlessBlackFungusLine2, gJiminyHeartlessBlackFungusLine3,
    gJiminyHeartlessBlackFungusLine4, gJiminyHeartlessBlackFungusLine5, gJiminyHeartlessBlackFungusLine6, gJiminyHeartlessBlackFungusLine7,
    gJiminyHeartlessBlackFungusLine8, gJiminyHeartlessBlackFungusLine9, gJiminyHeartlessBlackFungusLine10, gJiminyHeartlessBlackFungusLine11,
};

JiminyTextChar* gJiminyHeartlessCreeperPlantLines[8] = {
    gJiminyHeartlessCreeperPlantLine0, gJiminyHeartlessCreeperPlantLine1, gJiminyHeartlessCreeperPlantLine2, gJiminyHeartlessCreeperPlantLine3,
    gJiminyHeartlessCreeperPlantLine4, gJiminyHeartlessCreeperPlantLine5, gJiminyHeartlessCreeperPlantLine6, gJiminyHeartlessCreeperPlantLine7,
};

JiminyTextChar* gJiminyHeartlessTornadoStepLines[9] = {
    gJiminyHeartlessTornadoStepLine0, gJiminyHeartlessTornadoStepLine1, gJiminyHeartlessTornadoStepLine2, gJiminyHeartlessTornadoStepLine3,
    gJiminyHeartlessTornadoStepLine4, gJiminyHeartlessTornadoStepLine5, gJiminyHeartlessTornadoStepLine6, gJiminyHeartlessTornadoStepLine7,
    gJiminyHeartlessTornadoStepLine8,
};

JiminyTextChar* gJiminyHeartlessCrescendoLines[6] = {
    gJiminyHeartlessCrescendoLine0, gJiminyHeartlessCrescendoLine1, gJiminyHeartlessCrescendoLine2, gJiminyHeartlessCrescendoLine3,
    gJiminyHeartlessCrescendoLine4, gJiminyHeartlessCrescendoLine5,
};

JiminyTextChar* gJiminyRikuCharacterSoraLines[13] = {
    gJiminyRikuCharacterSoraLine0, gJiminyRikuCharacterSoraLine1, gJiminyRikuCharacterSoraLine2, gJiminyRikuCharacterSoraLine3,
    gJiminyRikuCharacterSoraLine4, gJiminyBlankLine, gJiminyRikuCharacterSoraLine6, gJiminyRikuCharacterSoraLine7,
    gJiminyRikuCharacterSoraLine8, gJiminyRikuCharacterSoraLine9, gJiminyRikuCharacterSoraLine10, gJiminyRikuCharacterSoraLine11,
    gJiminyRikuCharacterSoraLine12,
};

JiminyTextChar* gJiminyRikuCharacterNamineLines[16] = {
    gJiminyRikuCharacterNamineLine0, gJiminyRikuCharacterNamineLine1, gJiminyRikuCharacterNamineLine2, gJiminyRikuCharacterNamineLine3,
    gJiminyRikuCharacterNamineLine4, gJiminyRikuCharacterNamineLine5, gJiminyRikuCharacterNamineLine6, gJiminyRikuCharacterNamineLine7,
    gJiminyRikuCharacterNamineLine8, gJiminyRikuCharacterNamineLine9, gJiminyRikuCharacterNamineLine10, gJiminyRikuCharacterNamineLine11,
    gJiminyRikuCharacterNamineLine12, gJiminyRikuCharacterNamineLine13, gJiminyRikuCharacterNamineLine14, gJiminyRikuCharacterNamineLine15,
};

JiminyTextChar* gJiminyRikuCharacterRikuReplicaLines[8] = {
    gJiminyRikuCharacterRikuReplicaLine0, gJiminyRikuCharacterRikuReplicaLine1, gJiminyRikuCharacterRikuReplicaLine2, gJiminyRikuCharacterRikuReplicaLine3,
    gJiminyRikuCharacterRikuReplicaLine4, gJiminyRikuCharacterRikuReplicaLine5, gJiminyRikuCharacterRikuReplicaLine6, gJiminyRikuCharacterRikuReplicaLine7,
};

JiminyTextChar* gJiminyRikuCharacterAnsemLines[14] = {
    gJiminyRikuCharacterAnsemLine0, gJiminyRikuCharacterAnsemLine1, gJiminyRikuCharacterAnsemLine2, gJiminyRikuCharacterAnsemLine3,
    gJiminyRikuCharacterAnsemLine4, gJiminyRikuCharacterAnsemLine5, gJiminyRikuCharacterAnsemLine6, gJiminyRikuCharacterAnsemLine7,
    gJiminyRikuCharacterAnsemLine8, gJiminyRikuCharacterAnsemLine9, gJiminyRikuCharacterAnsemLine10, gJiminyRikuCharacterAnsemLine11,
    gJiminyRikuCharacterAnsemLine12, gJiminyRikuCharacterAnsemLine13,
};

JiminyTextChar* gJiminyRikuCharacterVexenLines[16] = {
    gJiminyRikuCharacterVexenLine0, gJiminyRikuCharacterVexenLine1, gJiminyRikuCharacterVexenLine2, gJiminyRikuCharacterVexenLine3,
    gJiminyRikuCharacterVexenLine4, gJiminyRikuCharacterVexenLine5, gJiminyRikuCharacterVexenLine6, gJiminyRikuCharacterVexenLine7,
    gJiminyRikuCharacterVexenLine8, gJiminyRikuCharacterVexenLine9, gJiminyRikuCharacterVexenLine10, gJiminyRikuCharacterVexenLine11,
    gJiminyRikuCharacterVexenLine12, gJiminyRikuCharacterVexenLine13, gJiminyRikuCharacterVexenLine14, gJiminyRikuCharacterVexenLine15,
};

JiminyTextChar* gJiminyRikuCharacterZexionLines[17] = {
    gJiminyRikuCharacterZexionLine0, gJiminyRikuCharacterZexionLine1, gJiminyRikuCharacterZexionLine2, gJiminyRikuCharacterZexionLine3,
    gJiminyRikuCharacterZexionLine4, gJiminyRikuCharacterZexionLine5, gJiminyRikuCharacterZexionLine6, gJiminyRikuCharacterZexionLine7,
    gJiminyRikuCharacterZexionLine8, gJiminyRikuCharacterZexionLine9, gJiminyRikuCharacterZexionLine10, gJiminyRikuCharacterZexionLine11,
    gJiminyRikuCharacterZexionLine12, gJiminyRikuCharacterZexionLine13, gJiminyRikuCharacterZexionLine14, gJiminyRikuCharacterZexionLine15,
    gJiminyRikuCharacterZexionLine16,
};

JiminyTextChar* gJiminyRikuCharacterAxelLines[19] = {
    gJiminyRikuCharacterAxelLine0, gJiminyRikuCharacterAxelLine1, gJiminyRikuCharacterAxelLine2, gJiminyRikuCharacterAxelLine3,
    gJiminyRikuCharacterAxelLine4, gJiminyRikuCharacterAxelLine5, gJiminyRikuCharacterAxelLine6, gJiminyRikuCharacterAxelLine7,
    gJiminyRikuCharacterAxelLine8, gJiminyRikuCharacterAxelLine9, gJiminyRikuCharacterAxelLine10, gJiminyRikuCharacterAxelLine11,
    gJiminyRikuCharacterAxelLine12, gJiminyRikuCharacterAxelLine13, gJiminyRikuCharacterAxelLine14, gJiminyRikuCharacterAxelLine15,
    gJiminyRikuCharacterAxelLine16, gJiminyRikuCharacterAxelLine17, gJiminyRikuCharacterAxelLine18,
};

JiminyTextChar* gJiminyRikuCharacterMarluxiaLines[19] = {
    gJiminyRikuCharacterMarluxiaLine0, gJiminyRikuCharacterMarluxiaLine1, gJiminyRikuCharacterMarluxiaLine2, gJiminyRikuCharacterMarluxiaLine3,
    gJiminyRikuCharacterMarluxiaLine4, gJiminyRikuCharacterMarluxiaLine5, gJiminyRikuCharacterMarluxiaLine6, gJiminyRikuCharacterMarluxiaLine7,
    gJiminyRikuCharacterMarluxiaLine8, gJiminyRikuCharacterMarluxiaLine9, gJiminyRikuCharacterMarluxiaLine10, gJiminyRikuCharacterMarluxiaLine11,
    gJiminyRikuCharacterMarluxiaLine12, gJiminyRikuCharacterMarluxiaLine13, gJiminyRikuCharacterMarluxiaLine14, gJiminyRikuCharacterMarluxiaLine15,
    gJiminyRikuCharacterMarluxiaLine16, gJiminyRikuCharacterMarluxiaLine17, gJiminyRikuCharacterMarluxiaLine18,
};

JiminyTextChar* gJiminyRikuCharacterLarxeneLines[13] = {
    gJiminyRikuCharacterLarxeneLine0, gJiminyRikuCharacterLarxeneLine1, gJiminyRikuCharacterLarxeneLine2, gJiminyRikuCharacterLarxeneLine3,
    gJiminyRikuCharacterLarxeneLine4, gJiminyRikuCharacterLarxeneLine5, gJiminyRikuCharacterLarxeneLine6, gJiminyRikuCharacterLarxeneLine7,
    gJiminyRikuCharacterLarxeneLine8, gJiminyRikuCharacterLarxeneLine9, gJiminyRikuCharacterLarxeneLine10, gJiminyRikuCharacterLarxeneLine11,
    gJiminyRikuCharacterLarxeneLine12,
};

JiminyTextChar* gJiminyRikuCharacterDiZLines[11] = {
    gJiminyRikuCharacterDiZLine0, gJiminyRikuCharacterDiZLine1, gJiminyRikuCharacterDiZLine2, gJiminyRikuCharacterDiZLine3,
    gJiminyRikuCharacterDiZLine4, gJiminyRikuCharacterDiZLine5, gJiminyRikuCharacterDiZLine6, gJiminyRikuCharacterDiZLine7,
    gJiminyRikuCharacterDiZLine8, gJiminyRikuCharacterDiZLine9, gJiminyRikuCharacterDiZLine10,
};

JiminyTextChar* gJiminyRikuCharacterMaleficentLines[13] = {
    gJiminyRikuCharacterMaleficentLine0, gJiminyRikuCharacterMaleficentLine1, gJiminyRikuCharacterMaleficentLine2, gJiminyRikuCharacterMaleficentLine3,
    gJiminyRikuCharacterMaleficentLine4, gJiminyRikuCharacterMaleficentLine5, gJiminyRikuCharacterMaleficentLine6, gJiminyRikuCharacterMaleficentLine7,
    gJiminyRikuCharacterMaleficentLine8, gJiminyRikuCharacterMaleficentLine9, gJiminyRikuCharacterMaleficentLine10, gJiminyRikuCharacterMaleficentLine11,
    gJiminyRikuCharacterMaleficentLine12,
};

JiminyTextChar* gJiminyRikuCharacterJafarGenieLines[8] = {
    gJiminyRikuCharacterJafarGenieLine0, gJiminyRikuCharacterJafarGenieLine1, gJiminyRikuCharacterJafarGenieLine2, gJiminyRikuCharacterJafarGenieLine3,
    gJiminyRikuCharacterJafarGenieLine4, gJiminyRikuCharacterJafarGenieLine5, gJiminyRikuCharacterJafarGenieLine6, gJiminyRikuCharacterJafarGenieLine7,
};

JiminyTextChar* gJiminyRikuCharacterUrsulaLines[9] = {
    gJiminyRikuCharacterUrsulaLine0, gJiminyRikuCharacterUrsulaLine1, gJiminyRikuCharacterUrsulaLine2, gJiminyRikuCharacterUrsulaLine3,
    gJiminyRikuCharacterUrsulaLine4, gJiminyRikuCharacterUrsulaLine5, gJiminyRikuCharacterUrsulaLine6, gJiminyRikuCharacterUrsulaLine7,
    gJiminyRikuCharacterUrsulaLine8,
};

JiminyTextChar* gJiminyRikuCharacterHadesLines[8] = {
    gJiminyRikuCharacterHadesLine0, gJiminyRikuCharacterHadesLine1, gJiminyRikuCharacterHadesLine2, gJiminyRikuCharacterHadesLine3,
    gJiminyRikuCharacterHadesLine4, gJiminyRikuCharacterHadesLine5, gJiminyRikuCharacterHadesLine6, gJiminyRikuCharacterHadesLine7,
};

JiminyTextChar* gJiminyRikuCharacterOogieBoogieLines[8] = {
    gJiminyRikuCharacterOogieBoogieLine0, gJiminyRikuCharacterOogieBoogieLine1, gJiminyRikuCharacterOogieBoogieLine2, gJiminyRikuCharacterOogieBoogieLine3,
    gJiminyRikuCharacterOogieBoogieLine4, gJiminyRikuCharacterOogieBoogieLine5, gJiminyRikuCharacterOogieBoogieLine6, gJiminyRikuCharacterOogieBoogieLine7,
};

JiminyTextChar* gJiminyRikuCharacterHookLines[6] = {
    gJiminyRikuCharacterHookLine0, gJiminyRikuCharacterHookLine1, gJiminyRikuCharacterHookLine2, gJiminyRikuCharacterHookLine3,
    gJiminyRikuCharacterHookLine4, gJiminyRikuCharacterHookLine5,
};

JiminyTextChar* gJiminyRikuHeartlessGuardArmorLines[7] = {
    gJiminyRikuHeartlessGuardArmorLine0, gJiminyRikuHeartlessGuardArmorLine1, gJiminyRikuHeartlessGuardArmorLine2, gJiminyRikuHeartlessGuardArmorLine3,
    gJiminyRikuHeartlessGuardArmorLine4, gJiminyRikuHeartlessGuardArmorLine5, gJiminyRikuHeartlessGuardArmorLine6,
};

JiminyTextChar* gJiminyRikuHeartlessParasiteCageLines[7] = {
    gJiminyRikuHeartlessParasiteCageLine0, gJiminyRikuHeartlessParasiteCageLine1, gJiminyRikuHeartlessParasiteCageLine2, gJiminyRikuHeartlessParasiteCageLine3,
    gJiminyRikuHeartlessParasiteCageLine4, gJiminyRikuHeartlessParasiteCageLine5, gJiminyRikuHeartlessParasiteCageLine6,
};

JiminyTextChar* gJiminyRikuHeartlessTrickmasterLines[8] = {
    gJiminyRikuHeartlessTrickmasterLine0, gJiminyRikuHeartlessTrickmasterLine1, gJiminyRikuHeartlessTrickmasterLine2, gJiminyRikuHeartlessTrickmasterLine3,
    gJiminyRikuHeartlessTrickmasterLine4, gJiminyRikuHeartlessTrickmasterLine5, gJiminyRikuHeartlessTrickmasterLine6, gJiminyRikuHeartlessTrickmasterLine7,
};

JiminyTextChar* gJiminyRikuHeartlessDarksideLines[8] = {
    gJiminyRikuHeartlessDarksideLine0, gJiminyRikuHeartlessDarksideLine1, gJiminyRikuHeartlessDarksideLine2, gJiminyRikuHeartlessDarksideLine3,
    gJiminyRikuHeartlessDarksideLine4, gJiminyRikuHeartlessDarksideLine5, gJiminyRikuHeartlessDarksideLine6, gJiminyRikuHeartlessDarksideLine7,
};

JiminyTextChar* gJiminyMagicCardFireLines[4] = {
    gJiminyMagicCardFireLine0, gJiminyMagicCardFireLine1, gJiminyMagicCardFireLine2, gJiminyMagicCardFireLine3,
};

JiminyTextChar* gJiminyMagicCardBlizzardLines[4] = {
    gJiminyMagicCardBlizzardLine0, gJiminyMagicCardBlizzardLine1, gJiminyMagicCardBlizzardLine2, gJiminyMagicCardBlizzardLine3,
};

JiminyTextChar* gJiminyMagicCardThunderLines[5] = {
    gJiminyMagicCardThunderLine0, gJiminyMagicCardThunderLine1, gJiminyMagicCardThunderLine2, gJiminyMagicCardThunderLine3,
    gJiminyMagicCardThunderLine4,
};

JiminyTextChar* gJiminyMagicCardCureLines[3] = {
    gJiminyMagicCardCureLine0, gJiminyMagicCardCureLine1, gJiminyMagicCardCureLine2,
};

JiminyTextChar* gJiminyMagicCardGravityLines[5] = {
    gJiminyMagicCardGravityLine0, gJiminyMagicCardGravityLine1, gJiminyMagicCardGravityLine2, gJiminyMagicCardGravityLine3,
    gJiminyMagicCardGravityLine4,
};

JiminyTextChar* gJiminyMagicCardStopLines[5] = {
    gJiminyMagicCardStopLine0, gJiminyMagicCardStopLine1, gJiminyMagicCardStopLine2, gJiminyMagicCardStopLine3,
    gJiminyMagicCardStopLine4,
};

JiminyTextChar* gJiminyMagicCardAeroLines[5] = {
    gJiminyMagicCardAeroLine0, gJiminyMagicCardAeroLine1, gJiminyMagicCardAeroLine2, gJiminyMagicCardAeroLine3,
    gJiminyMagicCardAeroLine4,
};

JiminyTextChar* gJiminyMagicCardSimbaLines[6] = {
    gJiminyMagicCardSimbaLine0, gJiminyMagicCardSimbaLine1, gJiminyMagicCardSimbaLine2, gJiminyMagicCardSimbaLine3,
    gJiminyMagicCardSimbaLine4, gJiminyMagicCardSimbaLine5,
};

JiminyTextChar* gJiminyMagicCardDumboLines[6] = {
    gJiminyMagicCardDumboLine0, gJiminyMagicCardDumboLine1, gJiminyMagicCardDumboLine2, gJiminyMagicCardDumboLine3,
    gJiminyMagicCardDumboLine4, gJiminyMagicCardDumboLine5,
};

JiminyTextChar* gJiminyMagicCardBambiLines[4] = {
    gJiminyMagicCardBambiLine0, gJiminyMagicCardBambiLine1, gJiminyMagicCardBambiLine2, gJiminyMagicCardBambiLine3,
};

JiminyTextChar* gJiminyMagicCardMushuLines[5] = {
    gJiminyMagicCardMushuLine0, gJiminyMagicCardMushuLine1, gJiminyMagicCardMushuLine2, gJiminyMagicCardMushuLine3,
    gJiminyMagicCardMushuLine4,
};

JiminyTextChar* gJiminyMagicCardGenieLines[5] = {
    gJiminyMagicCardGenieLine0, gJiminyMagicCardGenieLine1, gJiminyMagicCardGenieLine2, gJiminyMagicCardGenieLine3,
    gJiminyMagicCardGenieLine4,
};

JiminyTextChar* gJiminyMagicCardTinkerBellLines[4] = {
    gJiminyMagicCardTinkerBellLine0, gJiminyMagicCardTinkerBellLine1, gJiminyMagicCardTinkerBellLine2, gJiminyMagicCardTinkerBellLine3,
};

JiminyTextChar* gJiminyMagicCardCloudLines[4] = {
    gJiminyMagicCardCloudLine0, gJiminyMagicCardCloudLine1, gJiminyMagicCardCloudLine2, gJiminyMagicCardCloudLine3,
};

JiminyTextChar* gJiminyItemCardPotionLines[5] = {
    gJiminyItemCardPotionLine0, gJiminyItemCardPotionLine1, gJiminyItemCardPotionLine2, gJiminyItemCardPotionLine3,
    gJiminyItemCardPotionLine4,
};

JiminyTextChar* gJiminyItemCardHiPotionLines[5] = {
    gJiminyItemCardHiPotionLine0, gJiminyItemCardHiPotionLine1, gJiminyItemCardHiPotionLine2, gJiminyItemCardHiPotionLine3,
    gJiminyItemCardHiPotionLine4,
};

JiminyTextChar* gJiminyItemCardMegaPotionLines[6] = {
    gJiminyItemCardMegaPotionLine0, gJiminyItemCardMegaPotionLine1, gJiminyItemCardMegaPotionLine2, gJiminyItemCardMegaPotionLine3,
    gJiminyItemCardMegaPotionLine4, gJiminyItemCardMegaPotionLine5,
};

JiminyTextChar* gJiminyItemCardEtherLines[5] = {
    gJiminyItemCardEtherLine0, gJiminyItemCardEtherLine1, gJiminyItemCardEtherLine2, gJiminyItemCardEtherLine3,
    gJiminyItemCardEtherLine4,
};

JiminyTextChar* gJiminyItemCardMegaEtherLines[6] = {
    gJiminyItemCardMegaEtherLine0, gJiminyItemCardMegaEtherLine1, gJiminyItemCardMegaEtherLine2, gJiminyItemCardMegaEtherLine3,
    gJiminyItemCardMegaEtherLine4, gJiminyItemCardMegaEtherLine5,
};

JiminyTextChar* gJiminyItemCardElixirLines[4] = {
    gJiminyItemCardElixirLine0, gJiminyItemCardElixirLine1, gJiminyItemCardElixirLine2, gJiminyItemCardElixirLine3,
};

JiminyTextChar* gJiminyItemCardMegalixirLines[6] = {
    gJiminyItemCardMegalixirLine0, gJiminyItemCardMegalixirLine1, gJiminyItemCardMegalixirLine2, gJiminyItemCardMegalixirLine3,
    gJiminyItemCardMegalixirLine4, gJiminyItemCardMegalixirLine5,
};

JiminyTextChar* gJiminyFriendCardDonaldDuckLines[5] = {
    gJiminyFriendCardDonaldDuckLine0, gJiminyFriendCardDonaldDuckLine1, gJiminyFriendCardDonaldDuckLine2, gJiminyFriendCardDonaldDuckLine3,
    gJiminyFriendCardDonaldDuckLine4,
};

JiminyTextChar* gJiminyFriendCardGoofyLines[4] = {
    gJiminyFriendCardGoofyLine0, gJiminyFriendCardGoofyLine1, gJiminyFriendCardGoofyLine2, gJiminyFriendCardGoofyLine3,
};

JiminyTextChar* gJiminyFriendCardAladdinLines[5] = {
    gJiminyFriendCardAladdinLine0, gJiminyFriendCardAladdinLine1, gJiminyFriendCardAladdinLine2, gJiminyFriendCardAladdinLine3,
    gJiminyFriendCardAladdinLine4,
};

JiminyTextChar* gJiminyFriendCardJackLines[5] = {
    gJiminyFriendCardJackLine0, gJiminyFriendCardJackLine1, gJiminyFriendCardJackLine2, gJiminyFriendCardJackLine3,
    gJiminyFriendCardJackLine4,
};

JiminyTextChar* gJiminyFriendCardArielLines[5] = {
    gJiminyFriendCardArielLine0, gJiminyFriendCardArielLine1, gJiminyFriendCardArielLine2, gJiminyFriendCardArielLine3,
    gJiminyFriendCardArielLine4,
};

JiminyTextChar* gJiminyFriendCardPeterPanLines[4] = {
    gJiminyFriendCardPeterPanLine0, gJiminyFriendCardPeterPanLine1, gJiminyFriendCardPeterPanLine2, gJiminyFriendCardPeterPanLine3,
};

JiminyTextChar* gJiminyFriendCardBeastLines[5] = {
    gJiminyFriendCardBeastLine0, gJiminyFriendCardBeastLine1, gJiminyFriendCardBeastLine2, gJiminyFriendCardBeastLine3,
    gJiminyFriendCardBeastLine4,
};

JiminyTextChar* gJiminyEnemyCardShadowLines[5] = {
    gJiminyEnemyCardShadowLine0, gJiminyEnemyCardShadowLine1, gJiminyEnemyCardShadowLine2, gJiminyEnemyCardShadowLine3,
    gJiminyEnemyCardShadowLine4,
};

JiminyTextChar* gJiminyEnemyCardSoldierLines[5] = {
    gJiminyEnemyCardSoldierLine0, gJiminyEnemyCardSoldierLine1, gJiminyEnemyCardSoldierLine2, gJiminyEnemyCardSoldierLine3,
    gJiminyEnemyCardSoldierLine4,
};

JiminyTextChar* gJiminyEnemyCardLargeBodyLines[6] = {
    gJiminyEnemyCardLargeBodyLine0, gJiminyEnemyCardLargeBodyLine1, gJiminyEnemyCardLargeBodyLine2, gJiminyEnemyCardLargeBodyLine3,
    gJiminyEnemyCardLargeBodyLine4, gJiminyEnemyCardLargeBodyLine5,
};

JiminyTextChar* gJiminyEnemyCardRedNocturneLines[5] = {
    gJiminyEnemyCardRedNocturneLine0, gJiminyEnemyCardRedNocturneLine1, gJiminyEnemyCardRedNocturneLine2, gJiminyEnemyCardRedNocturneLine3,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardBlueRhapsodyLines[5] = {
    gJiminyEnemyCardBlueRhapsodyLine0, gJiminyEnemyCardBlueRhapsodyLine1, gJiminyEnemyCardBlueRhapsodyLine2, gJiminyEnemyCardBlueRhapsodyLine3,
    gJiminyEnemyCardBlueRhapsodyLine4,
};

JiminyTextChar* gJiminyEnemyCardYellowOperaLines[5] = {
    gJiminyEnemyCardYellowOperaLine0, gJiminyEnemyCardYellowOperaLine1, gJiminyEnemyCardYellowOperaLine2, gJiminyEnemyCardYellowOperaLine3,
    gJiminyEnemyCardYellowOperaLine4,
};

JiminyTextChar* gJiminyEnemyCardGreenRequiemLines[5] = {
    gJiminyEnemyCardGreenRequiemLine0, gJiminyEnemyCardGreenRequiemLine1, gJiminyEnemyCardGreenRequiemLine2, gJiminyEnemyCardGreenRequiemLine3,
    gJiminyEnemyCardGreenRequiemLine4,
};

JiminyTextChar* gJiminyEnemyCardPowerwildLines[8] = {
    gJiminyEnemyCardPowerwildLine0, gJiminyEnemyCardPowerwildLine1, gJiminyEnemyCardPowerwildLine2, gJiminyEnemyCardPowerwildLine3,
    gJiminyEnemyCardPowerwildLine4, gJiminyEnemyCardPowerwildLine5, gJiminyEnemyCardPowerwildLine6, gJiminyEnemyCardPowerwildLine7,
};

JiminyTextChar* gJiminyEnemyCardBouncywildLines[6] = {
    gJiminyEnemyCardBouncywildLine0, gJiminyEnemyCardBouncywildLine1, gJiminyEnemyCardBouncywildLine2, gJiminyEnemyCardBouncywildLine3,
    gJiminyEnemyCardBouncywildLine4, gJiminyEnemyCardBouncywildLine5,
};

JiminyTextChar* gJiminyEnemyCardAirSoldierLines[4] = {
    gJiminyEnemyCardAirSoldierLine0, gJiminyEnemyCardAirSoldierLine1, gJiminyEnemyCardAirSoldierLine2, gJiminyEnemyCardAirSoldierLine3,
};

JiminyTextChar* gJiminyEnemyCardBanditLines[6] = {
    gJiminyEnemyCardBanditLine0, gJiminyEnemyCardBanditLine1, gJiminyEnemyCardBanditLine2, gJiminyEnemyCardBanditLine3,
    gJiminyEnemyCardBanditLine4, gJiminyEnemyCardBanditLine5,
};

JiminyTextChar* gJiminyEnemyCardFatBanditLines[6] = {
    gJiminyEnemyCardFatBanditLine0, gJiminyEnemyCardFatBanditLine1, gJiminyEnemyCardFatBanditLine2, gJiminyEnemyCardFatBanditLine3,
    gJiminyEnemyCardFatBanditLine4, gJiminyEnemyCardFatBanditLine5,
};

JiminyTextChar* gJiminyEnemyCardBarrelSpiderLines[4] = {
    gJiminyEnemyCardBarrelSpiderLine0, gJiminyEnemyCardBarrelSpiderLine1, gJiminyEnemyCardBarrelSpiderLine2, gJiminyEnemyCardBarrelSpiderLine3,
};

JiminyTextChar* gJiminyEnemyCardSeaNeonLines[5] = {
    gJiminyEnemyCardSeaNeonLine0, gJiminyEnemyCardSeaNeonLine1, gJiminyEnemyCardSeaNeonLine2, gJiminyEnemyCardSeaNeonLine3,
    gJiminyEnemyCardSeaNeonLine4,
};

JiminyTextChar* gJiminyEnemyCardScrewdiverLines[5] = {
    gJiminyEnemyCardScrewdiverLine0, gJiminyEnemyCardScrewdiverLine1, gJiminyEnemyCardScrewdiverLine2, gJiminyEnemyCardScrewdiverLine3,
    gJiminyEnemyCardScrewdiverLine4,
};

JiminyTextChar* gJiminyEnemyCardAquatankLines[6] = {
    gJiminyEnemyCardAquatankLine0, gJiminyEnemyCardAquatankLine1, gJiminyEnemyCardAquatankLine2, gJiminyEnemyCardAquatankLine3,
    gJiminyEnemyCardAquatankLine4, gJiminyEnemyCardAquatankLine5,
};

JiminyTextChar* gJiminyEnemyCardWightKnightLines[5] = {
    gJiminyEnemyCardWightKnightLine0, gJiminyEnemyCardWightKnightLine1, gJiminyEnemyCardWightKnightLine2, gJiminyEnemyCardWightKnightLine3,
    gJiminyEnemyCardWightKnightLine4,
};

JiminyTextChar* gJiminyEnemyCardGargoyleLines[6] = {
    gJiminyEnemyCardGargoyleLine0, gJiminyEnemyCardGargoyleLine1, gJiminyEnemyCardGargoyleLine2, gJiminyEnemyCardGargoyleLine3,
    gJiminyEnemyCardGargoyleLine4, gJiminyEnemyCardGargoyleLine5,
};

JiminyTextChar* gJiminyEnemyCardPirateLines[5] = {
    gJiminyEnemyCardPirateLine0, gJiminyEnemyCardPirateLine1, gJiminyEnemyCardPirateLine2, gJiminyEnemyCardPirateLine3,
    gJiminyEnemyCardPirateLine4,
};

JiminyTextChar* gJiminyEnemyCardAirPirateLines[6] = {
    gJiminyEnemyCardAirPirateLine0, gJiminyEnemyCardAirPirateLine1, gJiminyEnemyCardAirPirateLine2, gJiminyEnemyCardAirPirateLine3,
    gJiminyEnemyCardAirPirateLine4, gJiminyEnemyCardAirPirateLine5,
};

JiminyTextChar* gJiminyEnemyCardDarkballLines[5] = {
    gJiminyEnemyCardDarkballLine0, gJiminyEnemyCardDarkballLine1, gJiminyEnemyCardDarkballLine2, gJiminyEnemyCardDarkballLine3,
    gJiminyEnemyCardDarkballLine4,
};

JiminyTextChar* gJiminyEnemyCardDefenderLines[7] = {
    gJiminyEnemyCardDefenderLine0, gJiminyEnemyCardDefenderLine1, gJiminyEnemyCardDefenderLine2, gJiminyEnemyCardDefenderLine3,
    gJiminyEnemyCardDefenderLine4, gJiminyEnemyCardDefenderLine5, gJiminyEnemyCardDefenderLine6,
};

JiminyTextChar* gJiminyEnemyCardWizardLines[6] = {
    gJiminyEnemyCardWizardLine0, gJiminyEnemyCardWizardLine1, gJiminyEnemyCardWizardLine2, gJiminyEnemyCardWizardLine3,
    gJiminyEnemyCardWizardLine4, gJiminyEnemyCardWizardLine5,
};

JiminyTextChar* gJiminyEnemyCardNeoshadowLines[5] = {
    gJiminyEnemyCardNeoshadowLine0, gJiminyEnemyCardNeoshadowLine1, gJiminyEnemyCardNeoshadowLine2, gJiminyEnemyCardNeoshadowLine3,
    gJiminyEnemyCardNeoshadowLine4,
};

JiminyTextChar* gJiminyEnemyCardWhiteMushroomLines[6] = {
    gJiminyEnemyCardWhiteMushroomLine0, gJiminyEnemyCardWhiteMushroomLine1, gJiminyEnemyCardWhiteMushroomLine2, gJiminyEnemyCardWhiteMushroomLine3,
    gJiminyEnemyCardWhiteMushroomLine4, gJiminyEnemyCardWhiteMushroomLine5,
};

JiminyTextChar* gJiminyEnemyCardBlackFungusLines[5] = {
    gJiminyEnemyCardBlackFungusLine0, gJiminyEnemyCardBlackFungusLine1, gJiminyEnemyCardBlackFungusLine2, gJiminyEnemyCardBlackFungusLine3,
    gJiminyEnemyCardBlackFungusLine4,
};

JiminyTextChar* gJiminyEnemyCardCreeperPlantLines[6] = {
    gJiminyEnemyCardCreeperPlantLine0, gJiminyEnemyCardCreeperPlantLine1, gJiminyEnemyCardCreeperPlantLine2, gJiminyEnemyCardCreeperPlantLine3,
    gJiminyEnemyCardCreeperPlantLine4, gJiminyEnemyCardCreeperPlantLine5,
};

JiminyTextChar* gJiminyEnemyCardCrescendoLines[6] = {
    gJiminyEnemyCardCrescendoLine0, gJiminyEnemyCardCrescendoLine1, gJiminyEnemyCardCrescendoLine2, gJiminyEnemyCardCrescendoLine3,
    gJiminyEnemyCardCrescendoLine4, gJiminyEnemyCardCrescendoLine5,
};

JiminyTextChar* gJiminyEnemyCardGuardArmorLines[5] = {
    gJiminyEnemyCardGuardArmorLine0, gJiminyEnemyCardGuardArmorLine1, gJiminyEnemyCardGuardArmorLine2, gJiminyEnemyCardGuardArmorLine3,
    gJiminyEnemyCardGuardArmorLine4,
};

JiminyTextChar* gJiminyEnemyCardHadesLines[9] = {
    gJiminyEnemyCardHadesLine0, gJiminyEnemyCardHadesLine1, gJiminyEnemyCardHadesLine2, gJiminyEnemyCardHadesLine3,
    gJiminyEnemyCardHadesLine4, gJiminyEnemyCardHadesLine5, gJiminyEnemyCardHadesLine6, gJiminyEnemyCardHadesLine7,
    gJiminyEnemyCardHadesLine8,
};

JiminyTextChar* gJiminyEnemyCardUrsulaLines[7] = {
    gJiminyEnemyCardUrsulaLine0, gJiminyEnemyCardUrsulaLine1, gJiminyEnemyCardUrsulaLine2, gJiminyEnemyCardUrsulaLine3,
    gJiminyEnemyCardUrsulaLine4, gJiminyEnemyCardUrsulaLine5, gJiminyEnemyCardUrsulaLine6,
};

JiminyTextChar* gJiminyEnemyCardHookLines[8] = {
    gJiminyEnemyCardHookLine0, gJiminyEnemyCardHookLine1, gJiminyEnemyCardHookLine2, gJiminyEnemyCardHookLine3,
    gJiminyEnemyCardHookLine4, gJiminyEnemyCardHookLine5, gJiminyEnemyCardHookLine6, gJiminyEnemyCardHookLine7,
};

JiminyTextChar* gJiminyEnemyCardDragonMaleficentLines[6] = {
    gJiminyEnemyCardDragonMaleficentLine0, gJiminyEnemyCardDragonMaleficentLine1, gJiminyEnemyCardDragonMaleficentLine2, gJiminyEnemyCardDragonMaleficentLine3,
    gJiminyEnemyCardDragonMaleficentLine4, gJiminyEnemyCardDragonMaleficentLine5,
};

JiminyTextChar* gJiminyEnemyCardRikuLines[8] = {
    gJiminyEnemyCardRikuLine0, gJiminyEnemyCardRikuLine1, gJiminyEnemyCardRikuLine2, gJiminyEnemyCardRikuLine3,
    gJiminyEnemyCardRikuLine4, gJiminyEnemyCardRikuLine5, gJiminyEnemyCardRikuLine6, gJiminyEnemyCardRikuLine7,
};

JiminyTextChar* gJiminyEnemyCardAxelLines[7] = {
    gJiminyEnemyCardAxelLine0, gJiminyEnemyCardAxelLine1, gJiminyEnemyCardAxelLine2, gJiminyEnemyCardAxelLine3,
    gJiminyEnemyCardAxelLine4, gJiminyEnemyCardAxelLine5, gJiminyEnemyCardAxelLine6,
};

JiminyTextChar* gJiminyEnemyCardLarxeneLines[7] = {
    gJiminyEnemyCardLarxeneLine0, gJiminyEnemyCardLarxeneLine1, gJiminyEnemyCardLarxeneLine2, gJiminyEnemyCardLarxeneLine3,
    gJiminyEnemyCardLarxeneLine4, gJiminyEnemyCardLarxeneLine5, gJiminyEnemyCardLarxeneLine6,
};

JiminyTextChar* gJiminyEnemyCardVexenLines[9] = {
    gJiminyEnemyCardVexenLine0, gJiminyEnemyCardVexenLine1, gJiminyEnemyCardVexenLine2, gJiminyEnemyCardVexenLine3,
    gJiminyEnemyCardVexenLine4, gJiminyEnemyCardVexenLine5, gJiminyEnemyCardVexenLine6, gJiminyEnemyCardVexenLine7,
    gJiminyEnemyCardVexenLine8,
};

JiminyTextChar* gJiminyEnemyCardMarluxiaLines[13] = {
    gJiminyEnemyCardMarluxiaLine0, gJiminyEnemyCardMarluxiaLine1, gJiminyEnemyCardMarluxiaLine2, gJiminyEnemyCardMarluxiaLine3,
    gJiminyEnemyCardMarluxiaLine4, gJiminyEnemyCardMarluxiaLine5, gJiminyEnemyCardMarluxiaLine6, gJiminyEnemyCardMarluxiaLine7,
    gJiminyEnemyCardMarluxiaLine8, gJiminyEnemyCardMarluxiaLine9, gJiminyEnemyCardMarluxiaLine10, gJiminyEnemyCardMarluxiaLine11,
    gJiminyEnemyCardMarluxiaLine12,
};

JiminyTextChar* gJiminyMapCardTranquilDarknessLines[2] = {
    gJiminyMapCardTranquilDarknessLine0, gJiminyMapCardTranquilDarknessLine1,
};

JiminyTextChar* gJiminyMapCardGuardedTroveLines[3] = {
    gJiminyMapCardGuardedTroveLine0, gJiminyMapCardGuardedTroveLine1, gJiminyMapCardGuardedTroveLine2,
};

JiminyTextChar* gJiminyMapCardSleepingDarknessLines[3] = {
    gJiminyMapCardSleepingDarknessLine0, gJiminyMapCardSleepingDarknessLine1, gJiminyMapCardSleepingDarknessLine2,
};

JiminyTextChar* gJiminyMapCardMomentsReprieveLines[2] = {
    gJiminyMapCardMomentsReprieveLine0, gJiminyMapCardMomentsReprieveLine1,
};

JiminyTextChar* gJiminyMapCardFeebleDarknessLines[3] = {
    gJiminyMapCardFeebleDarknessLine0, gJiminyMapCardFeebleDarknessLine1, gJiminyMapCardFeebleDarknessLine2,
};

JiminyTextChar* gJiminyMapCardCalmBountyLines[2] = {
    gJiminyMapCardCalmBountyLine0, gJiminyMapCardCalmBountyLine1,
};

JiminyTextChar* gJiminyMapCardFalseBountyLines[4] = {
    gJiminyMapCardFalseBountyLine0, gJiminyMapCardFalseBountyLine1, gJiminyMapCardFalseBountyLine2, gJiminyMapCardFalseBountyLine3,
};

JiminyTextChar* gJiminyMapCardMoogleRoomLines[3] = {
    gJiminyMapCardMoogleRoomLine0, gJiminyMapCardMoogleRoomLine1, gJiminyMapCardMoogleRoomLine2,
};

JiminyTextChar* gJiminyMapCardSorcerousWakingLines[3] = {
    gJiminyMapCardSorcerousWakingLine0, gJiminyMapCardSorcerousWakingLine1, gJiminyMapCardSorcerousWakingLine2,
};

JiminyTextChar* gJiminyMapCardMartialWakingLines[3] = {
    gJiminyMapCardMartialWakingLine0, gJiminyMapCardMartialWakingLine1, gJiminyMapCardMartialWakingLine2,
};

JiminyTextChar* gJiminyMapCardAlchemicWakingLines[3] = {
    gJiminyMapCardAlchemicWakingLine0, gJiminyMapCardAlchemicWakingLine1, gJiminyMapCardAlchemicWakingLine2,
};

JiminyTextChar* gJiminyMapCardMeetingGroundLines[5] = {
    gJiminyMapCardMeetingGroundLine0, gJiminyMapCardMeetingGroundLine1, gJiminyMapCardMeetingGroundLine2, gJiminyMapCardMeetingGroundLine3,
    gJiminyMapCardMeetingGroundLine4,
};

JiminyTextChar* gJiminyMapCardMinglingWorldsLines[2] = {
    gJiminyMapCardMinglingWorldsLine0, gJiminyMapCardMinglingWorldsLine1,
};

JiminyTextChar* gJiminyMapCardStrongInitiativeLines[4] = {
    gJiminyMapCardStrongInitiativeLine0, gJiminyMapCardStrongInitiativeLine1, gJiminyMapCardStrongInitiativeLine2, gJiminyMapCardStrongInitiativeLine3,
};

JiminyTextChar* gJiminyMapCardLastingDazeLines[4] = {
    gJiminyMapCardLastingDazeLine0, gJiminyMapCardLastingDazeLine1, gJiminyMapCardLastingDazeLine2, gJiminyMapCardLastingDazeLine3,
};

JiminyTextChar* gJiminyMapCardStagnantSpaceLines[2] = {
    gJiminyMapCardStagnantSpaceLine0, gJiminyMapCardStagnantSpaceLine1,
};

JiminyTextChar* gJiminyMapCardPremiumRoomLines[3] = {
    gJiminyMapCardPremiumRoomLine0, gJiminyMapCardPremiumRoomLine1, gJiminyMapCardPremiumRoomLine2,
};

JiminyTextChar* gJiminyMapCardWhiteRoomLines[5] = {
    gJiminyMapCardWhiteRoomLine0, gJiminyMapCardWhiteRoomLine1, gJiminyMapCardWhiteRoomLine2, gJiminyMapCardWhiteRoomLine3,
    gJiminyMapCardWhiteRoomLine4,
};

JiminyTextChar* gJiminyMapCardBlackRoomLines[4] = {
    gJiminyMapCardBlackRoomLine0, gJiminyMapCardBlackRoomLine1, gJiminyMapCardBlackRoomLine2, gJiminyMapCardBlackRoomLine3,
};

JiminyTextChar* gJiminyMapCardKeyOfBeginningsLines[2] = {
    gJiminyMapCardKeyOfBeginningsLine0, gJiminyMapCardKeyOfBeginningsLine1,
};

JiminyTextChar* gJiminyMapCardKeyOfGuidanceLines[2] = {
    gJiminyMapCardKeyOfGuidanceLine0, gJiminyMapCardKeyOfGuidanceLine1,
};

JiminyTextChar* gJiminyMapCardKeyToTruthLines[2] = {
    gJiminyMapCardKeyToTruthLine0, gJiminyMapCardKeyToTruthLine1,
};

JiminyTextChar* gJiminyMapCardKeyToRewardsLines[2] = {
    gJiminyMapCardKeyToRewardsLine0, gJiminyMapCardKeyToRewardsLine1,
};

JiminyTextChar* gJiminyEnemyCardLexaeusLines[14] = {
    gJiminyEnemyCardLexaeusLine0, gJiminyEnemyCardLexaeusLine1, gJiminyEnemyCardLexaeusLine2, gJiminyEnemyCardLexaeusLine3,
    gJiminyEnemyCardLexaeusLine4, gJiminyEnemyCardLexaeusLine5, gJiminyEnemyCardLexaeusLine6, gJiminyEnemyCardLexaeusLine7,
    gJiminyEnemyCardLexaeusLine8, gJiminyEnemyCardLexaeusLine9, gJiminyEnemyCardLexaeusLine10, gJiminyEnemyCardLexaeusLine11,
    gJiminyEnemyCardLexaeusLine12, gJiminyEnemyCardLexaeusLine13,
};

JiminyTextChar* gJiminyStoryTraverseTownLines[20] = {
    gJiminyStoryTraverseTownLine0, gJiminyStoryTraverseTownLine1, gJiminyStoryTraverseTownLine2, gJiminyStoryTraverseTownLine3,
    gJiminyStoryTraverseTownLine4, gJiminyStoryTraverseTownLine5, gJiminyStoryTraverseTownLine6, gJiminyStoryTraverseTownLine7,
    gJiminyStoryTraverseTownLine8, gJiminyStoryTraverseTownLine9, gJiminyStoryTraverseTownLine10, gJiminyStoryTraverseTownLine11,
    gJiminyStoryTraverseTownLine12, gJiminyStoryTraverseTownLine13, gJiminyStoryTraverseTownLine14, gJiminyStoryTraverseTownLine15,
    gJiminyStoryTraverseTownLine16, gJiminyStoryTraverseTownLine17, gJiminyStoryTraverseTownLine18, gJiminyStoryTraverseTownLine19,
};

JiminyTextChar* gJiminyStoryWonderlandLines[26] = {
    gJiminyStoryWonderlandLine0, gJiminyStoryWonderlandLine1, gJiminyStoryWonderlandLine2, gJiminyStoryWonderlandLine3,
    gJiminyStoryWonderlandLine4, gJiminyStoryWonderlandLine5, gJiminyStoryWonderlandLine6, gJiminyStoryWonderlandLine7,
    gJiminyStoryWonderlandLine8, gJiminyStoryWonderlandLine9, gJiminyStoryWonderlandLine10, gJiminyStoryWonderlandLine11,
    gJiminyStoryWonderlandLine12, gJiminyStoryWonderlandLine13, gJiminyStoryWonderlandLine14, gJiminyStoryWonderlandLine15,
    gJiminyStoryWonderlandLine16, gJiminyStoryWonderlandLine17, gJiminyStoryWonderlandLine18, gJiminyStoryWonderlandLine19,
    gJiminyStoryWonderlandLine20, gJiminyStoryWonderlandLine21, gJiminyStoryWonderlandLine22, gJiminyStoryWonderlandLine23,
    gJiminyStoryWonderlandLine24, gJiminyStoryWonderlandLine25,
};

JiminyTextChar* gJiminyStoryTale3Lines[18] = {
    gJiminyStoryTale3Line0, gJiminyStoryTale3Line1, gJiminyStoryTale3Line2, gJiminyStoryTale3Line3,
    gJiminyStoryTale3Line4, gJiminyStoryTale3Line5, gJiminyStoryTale3Line6, gJiminyStoryTale3Line7,
    gJiminyStoryTale3Line8, gJiminyStoryTale3Line9, gJiminyStoryTale3Line10, gJiminyStoryTale3Line11,
    gJiminyStoryTale3Line12, gJiminyStoryTale3Line13, gJiminyStoryTale3Line14, gJiminyStoryTale3Line15,
    gJiminyStoryTale3Line16, gJiminyStoryTale3Line17,
};

JiminyTextChar* gJiminyStoryHalloweenTownLines[22] = {
    gJiminyStoryHalloweenTownLine0, gJiminyStoryHalloweenTownLine1, gJiminyStoryHalloweenTownLine2, gJiminyStoryHalloweenTownLine3,
    gJiminyStoryHalloweenTownLine4, gJiminyStoryHalloweenTownLine5, gJiminyStoryHalloweenTownLine6, gJiminyStoryHalloweenTownLine7,
    gJiminyStoryHalloweenTownLine8, gJiminyStoryHalloweenTownLine9, gJiminyStoryHalloweenTownLine10, gJiminyStoryHalloweenTownLine11,
    gJiminyStoryHalloweenTownLine12, gJiminyStoryHalloweenTownLine13, gJiminyStoryHalloweenTownLine14, gJiminyStoryHalloweenTownLine15,
    gJiminyStoryHalloweenTownLine16, gJiminyStoryHalloweenTownLine17, gJiminyStoryHalloweenTownLine18, gJiminyStoryHalloweenTownLine19,
    gJiminyStoryHalloweenTownLine20, gJiminyStoryHalloweenTownLine21,
};

JiminyTextChar* gJiminyStoryDestinyIslandsLines[16] = {
    gJiminyStoryDestinyIslandsLine0, gJiminyStoryDestinyIslandsLine1, gJiminyStoryDestinyIslandsLine2, gJiminyStoryDestinyIslandsLine3,
    gJiminyStoryDestinyIslandsLine4, gJiminyStoryDestinyIslandsLine5, gJiminyStoryDestinyIslandsLine6, gJiminyStoryDestinyIslandsLine7,
    gJiminyStoryDestinyIslandsLine8, gJiminyStoryDestinyIslandsLine9, gJiminyStoryDestinyIslandsLine10, gJiminyStoryDestinyIslandsLine11,
    gJiminyStoryDestinyIslandsLine12, gJiminyStoryDestinyIslandsLine13, gJiminyStoryDestinyIslandsLine14, gJiminyStoryDestinyIslandsLine15,
};

JiminyTextChar* gJiminyCharacterKairiLines[15] = {
    gJiminyCharacterKairiLine0, gJiminyCharacterKairiLine1, gJiminyCharacterKairiLine2, gJiminyCharacterKairiLine3,
    gJiminyCharacterKairiLine4, gJiminyCharacterKairiLine5, gJiminyCharacterKairiLine6, gJiminyCharacterKairiLine7,
    gJiminyCharacterKairiLine8, gJiminyCharacterKairiLine9, gJiminyCharacterKairiLine10, gJiminyCharacterKairiLine11,
    gJiminyCharacterKairiLine12, gJiminyCharacterKairiLine13, gJiminyCharacterKairiLine14,
};

JiminyTextChar* gJiminyCharacterTidusLines[9] = {
    gJiminyCharacterTidusLine0, gJiminyCharacterTidusLine1, gJiminyCharacterTidusLine2, gJiminyCharacterTidusLine3,
    gJiminyCharacterTidusLine4, gJiminyCharacterTidusLine5, gJiminyCharacterTidusLine6, gJiminyCharacterTidusLine7,
    gJiminyCharacterTidusLine8,
};

JiminyTextChar* gJiminyCharacterWakkaLines[7] = {
    gJiminyCharacterWakkaLine0, gJiminyCharacterWakkaLine1, gJiminyCharacterWakkaLine2, gJiminyCharacterWakkaLine3,
    gJiminyCharacterWakkaLine4, gJiminyCharacterWakkaLine5, gJiminyCharacterWakkaLine6,
};

JiminyTextChar* gJiminyCharacterSelphieLines[8] = {
    gJiminyCharacterSelphieLine0, gJiminyCharacterSelphieLine1, gJiminyCharacterSelphieLine2, gJiminyCharacterSelphieLine3,
    gJiminyCharacterSelphieLine4, gJiminyCharacterSelphieLine5, gJiminyCharacterSelphieLine6, gJiminyCharacterSelphieLine7,
};

JiminyTextChar* gJiminyCharacterLarxeneLines[13] = {
    gJiminyCharacterLarxeneLine0, gJiminyCharacterLarxeneLine1, gJiminyCharacterLarxeneLine2, gJiminyCharacterLarxeneLine3,
    gJiminyCharacterLarxeneLine4, gJiminyCharacterLarxeneLine5, gJiminyCharacterLarxeneLine6, gJiminyCharacterLarxeneLine7,
    gJiminyCharacterLarxeneLine8, gJiminyCharacterLarxeneLine9, gJiminyCharacterLarxeneLine10, gJiminyCharacterLarxeneLine11,
    gJiminyCharacterLarxeneLine12,
};

JiminyTextChar* gJiminyCharacterArielLines[15] = {
    gJiminyCharacterArielLine0, gJiminyCharacterArielLine1, gJiminyCharacterArielLine2, gJiminyCharacterArielLine3,
    gJiminyCharacterArielLine4, gJiminyCharacterArielLine5, gJiminyCharacterArielLine6, gJiminyCharacterArielLine7,
    gJiminyCharacterArielLine8, gJiminyCharacterArielLine9, gJiminyCharacterArielLine10, gJiminyCharacterArielLine11,
    gJiminyCharacterArielLine12, gJiminyCharacterArielLine13, gJiminyCharacterArielLine14,
};

JiminyTextChar* gJiminyCharacterWinnieThePoohLines[9] = {
    gJiminyCharacterWinnieThePoohLine0, gJiminyCharacterWinnieThePoohLine1, gJiminyCharacterWinnieThePoohLine2, gJiminyCharacterWinnieThePoohLine3,
    gJiminyCharacterWinnieThePoohLine4, gJiminyCharacterWinnieThePoohLine5, gJiminyCharacterWinnieThePoohLine6, gJiminyCharacterWinnieThePoohLine7,
    gJiminyCharacterWinnieThePoohLine8,
};

JiminyTextChar* gJiminyHeartlessDarksideLines[7] = {
    gJiminyHeartlessDarksideLine0, gJiminyHeartlessDarksideLine1, gJiminyHeartlessDarksideLine2, gJiminyHeartlessDarksideLine3,
    gJiminyHeartlessDarksideLine4, gJiminyHeartlessDarksideLine5, gJiminyHeartlessDarksideLine6,
};

JiminyTextChar* gJiminyRikuStoryTale1Lines[41] = {
    gJiminyRikuStoryTale1Line0, gJiminyRikuStoryTale1Line1, gJiminyRikuStoryTale1Line2, gJiminyRikuStoryTale1Line3,
    gJiminyRikuStoryTale1Line4, gJiminyRikuStoryTale1Line5, gJiminyRikuStoryTale1Line6, gJiminyRikuStoryTale1Line7,
    gJiminyRikuStoryTale1Line8, gJiminyRikuStoryTale1Line9, gJiminyRikuStoryTale1Line10, gJiminyRikuStoryTale1Line11,
    gJiminyRikuStoryTale1Line12, gJiminyRikuStoryTale1Line13, gJiminyRikuStoryTale1Line14, gJiminyRikuStoryTale1Line15,
    gJiminyRikuStoryTale1Line16, gJiminyRikuStoryTale1Line17, gJiminyRikuStoryTale1Line18, gJiminyRikuStoryTale1Line19,
    gJiminyRikuStoryTale1Line20, gJiminyRikuStoryTale1Line21, gJiminyRikuStoryTale1Line22, gJiminyRikuStoryTale1Line23,
    gJiminyRikuStoryTale1Line24, gJiminyRikuStoryTale1Line25, gJiminyRikuStoryTale1Line26, gJiminyRikuStoryTale1Line27,
    gJiminyRikuStoryTale1Line28, gJiminyRikuStoryTale1Line29, gJiminyRikuStoryTale1Line30, gJiminyRikuStoryTale1Line31,
    gJiminyRikuStoryTale1Line32, gJiminyRikuStoryTale1Line33, gJiminyRikuStoryTale1Line34, gJiminyRikuStoryTale1Line35,
    gJiminyRikuStoryTale1Line36, gJiminyRikuStoryTale1Line37, gJiminyRikuStoryTale1Line38, gJiminyRikuStoryTale1Line39,
    gJiminyRikuStoryTale1Line40,
};

JiminyTextChar* gJiminyRikuStoryTale4Lines[20] = {
    gJiminyRikuStoryTale4Line0, gJiminyRikuStoryTale4Line1, gJiminyRikuStoryTale4Line2, gJiminyRikuStoryTale4Line3,
    gJiminyRikuStoryTale4Line4, gJiminyRikuStoryTale4Line5, gJiminyRikuStoryTale4Line6, gJiminyRikuStoryTale4Line7,
    gJiminyRikuStoryTale4Line8, gJiminyRikuStoryTale4Line9, gJiminyRikuStoryTale4Line10, gJiminyRikuStoryTale4Line11,
    gJiminyRikuStoryTale4Line12, gJiminyRikuStoryTale4Line13, gJiminyRikuStoryTale4Line14, gJiminyRikuStoryTale4Line15,
    gJiminyRikuStoryTale4Line16, gJiminyRikuStoryTale4Line17, gJiminyRikuStoryTale4Line18, gJiminyRikuStoryTale4Line19,
};

JiminyTextChar* gJiminyRikuStoryTale6Lines[31] = {
    gJiminyRikuStoryTale6Line0, gJiminyRikuStoryTale6Line1, gJiminyRikuStoryTale6Line2, gJiminyRikuStoryTale6Line3,
    gJiminyRikuStoryTale6Line4, gJiminyRikuStoryTale6Line5, gJiminyRikuStoryTale6Line6, gJiminyRikuStoryTale6Line7,
    gJiminyRikuStoryTale6Line8, gJiminyRikuStoryTale6Line9, gJiminyRikuStoryTale6Line10, gJiminyRikuStoryTale6Line11,
    gJiminyRikuStoryTale6Line12, gJiminyRikuStoryTale6Line13, gJiminyRikuStoryTale6Line14, gJiminyRikuStoryTale6Line15,
    gJiminyRikuStoryTale6Line16, gJiminyRikuStoryTale6Line17, gJiminyRikuStoryTale6Line18, gJiminyRikuStoryTale6Line19,
    gJiminyRikuStoryTale6Line20, gJiminyRikuStoryTale6Line21, gJiminyRikuStoryTale6Line22, gJiminyRikuStoryTale6Line23,
    gJiminyRikuStoryTale6Line24, gJiminyRikuStoryTale6Line25, gJiminyRikuStoryTale6Line26, gJiminyRikuStoryTale6Line27,
    gJiminyRikuStoryTale6Line28, gJiminyRikuStoryTale6Line29, gJiminyRikuStoryTale6Line30,
};

JiminyTextChar* gJiminyRikuCharacterRikuLines[24] = {
    gJiminyRikuCharacterRikuLine0, gJiminyRikuCharacterRikuLine1, gJiminyRikuCharacterRikuLine2, gJiminyRikuCharacterRikuLine3,
    gJiminyRikuCharacterRikuLine4, gJiminyRikuCharacterRikuLine5, gJiminyRikuCharacterRikuLine6, gJiminyRikuCharacterRikuLine7,
    gJiminyRikuCharacterRikuLine8, gJiminyRikuCharacterRikuLine9, gJiminyRikuCharacterRikuLine10, gJiminyRikuCharacterRikuLine11,
    gJiminyRikuCharacterRikuLine12, gJiminyRikuCharacterRikuLine13, gJiminyRikuCharacterRikuLine14, gJiminyRikuCharacterRikuLine15,
    gJiminyRikuCharacterRikuLine16, gJiminyRikuCharacterRikuLine17, gJiminyRikuCharacterRikuLine18, gJiminyRikuCharacterRikuLine19,
    gJiminyRikuCharacterRikuLine20, gJiminyRikuCharacterRikuLine21, gJiminyRikuCharacterRikuLine22, gJiminyRikuCharacterRikuLine23,
};

JiminyTextChar* gJiminyRikuCharacterKingLines[15] = {
    gJiminyRikuCharacterKingLine0, gJiminyRikuCharacterKingLine1, gJiminyRikuCharacterKingLine2, gJiminyRikuCharacterKingLine3,
    gJiminyRikuCharacterKingLine4, gJiminyRikuCharacterKingLine5, gJiminyRikuCharacterKingLine6, gJiminyRikuCharacterKingLine7,
    gJiminyRikuCharacterKingLine8, gJiminyRikuCharacterKingLine9, gJiminyRikuCharacterKingLine10, gJiminyRikuCharacterKingLine11,
    gJiminyRikuCharacterKingLine12, gJiminyRikuCharacterKingLine13, gJiminyRikuCharacterKingLine14,
};

JiminyTextChar* gJiminyRikuCharacterKairiLines[16] = {
    gJiminyRikuCharacterKairiLine0, gJiminyRikuCharacterKairiLine1, gJiminyRikuCharacterKairiLine2, gJiminyRikuCharacterKairiLine3,
    gJiminyRikuCharacterKairiLine4, gJiminyRikuCharacterKairiLine5, gJiminyRikuCharacterKairiLine6, gJiminyRikuCharacterKairiLine7,
    gJiminyRikuCharacterKairiLine8, gJiminyRikuCharacterKairiLine9, gJiminyRikuCharacterKairiLine10, gJiminyRikuCharacterKairiLine11,
    gJiminyRikuCharacterKairiLine12, gJiminyRikuCharacterKairiLine13, gJiminyRikuCharacterKairiLine14, gJiminyRikuCharacterKairiLine15,
};

JiminyTextChar* gJiminyRikuCharacterLexaeusLines[17] = {
    gJiminyRikuCharacterLexaeusLine0, gJiminyRikuCharacterLexaeusLine1, gJiminyRikuCharacterLexaeusLine2, gJiminyRikuCharacterLexaeusLine3,
    gJiminyRikuCharacterLexaeusLine4, gJiminyRikuCharacterLexaeusLine5, gJiminyRikuCharacterLexaeusLine6, gJiminyRikuCharacterLexaeusLine7,
    gJiminyRikuCharacterLexaeusLine8, gJiminyRikuCharacterLexaeusLine9, gJiminyRikuCharacterLexaeusLine10, gJiminyRikuCharacterLexaeusLine11,
    gJiminyRikuCharacterLexaeusLine12, gJiminyRikuCharacterLexaeusLine13, gJiminyRikuCharacterLexaeusLine14, gJiminyRikuCharacterLexaeusLine15,
    gJiminyRikuCharacterLexaeusLine16,
};

JiminyTextChar* gJiminyAttackCardKingdomKeyLines[12] = {
    gJiminyAttackCardKingdomKeyLine0, gJiminyAttackCardKingdomKeyLine1, gJiminyAttackCardKingdomKeyLine2, gJiminyAttackCardKingdomKeyLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardKingdomKeyLine5, gJiminyAttackCardKingdomKeyLine6, gJiminyAttackCardKingdomKeyLine7,
    gJiminyAttackCardKingdomKeyLine8, gJiminyAttackCardKingdomKeyLine9, gJiminyAttackCardKingdomKeyLine10, gJiminyAttackCardKingdomKeyLine11,
};

JiminyTextChar* gJiminyAttackCardThreeWishesLines[11] = {
    gJiminyAttackCardThreeWishesLine0, gJiminyAttackCardThreeWishesLine1, gJiminyAttackCardThreeWishesLine2, gJiminyAttackCardThreeWishesLine3,
    gJiminyAttackCardThreeWishesLine4, gJiminyAttackCardThreeWishesLine5, gJiminyAttackCardThreeWishesLine6, gJiminyAttackCardThreeWishesLine7,
    gJiminyAttackCardThreeWishesLine8, gJiminyAttackCardThreeWishesLine9, gJiminyAttackCardThreeWishesLine10,
};

JiminyTextChar* gJiminyAttackCardCrabclawLines[12] = {
    gJiminyAttackCardCrabclawLine0, gJiminyAttackCardCrabclawLine1, gJiminyAttackCardCrabclawLine2, gJiminyAttackCardCrabclawLine3,
    gJiminyAttackCardCrabclawLine4, gJiminyAttackCardCrabclawLine5, gJiminyAttackCardCrabclawLine6, gJiminyAttackCardCrabclawLine7,
    gJiminyAttackCardCrabclawLine8, gJiminyAttackCardCrabclawLine9, gJiminyAttackCardCrabclawLine10, gJiminyAttackCardCrabclawLine11,
};

JiminyTextChar* gJiminyAttackCardPumpkinheadLines[12] = {
    gJiminyAttackCardPumpkinheadLine0, gJiminyAttackCardPumpkinheadLine1, gJiminyAttackCardPumpkinheadLine2, gJiminyAttackCardPumpkinheadLine3,
    gJiminyAttackCardPumpkinheadLine4, gJiminyAttackCardPumpkinheadLine5, gJiminyAttackCardPumpkinheadLine6, gJiminyAttackCardPumpkinheadLine7,
    gJiminyAttackCardPumpkinheadLine8, gJiminyAttackCardPumpkinheadLine9, gJiminyAttackCardPumpkinheadLine10, gJiminyAttackCardPumpkinheadLine11,
};

JiminyTextChar* gJiminyAttackCardFairyHarpLines[11] = {
    gJiminyAttackCardFairyHarpLine0, gJiminyAttackCardFairyHarpLine1, gJiminyAttackCardFairyHarpLine2, gJiminyAttackCardFairyHarpLine3,
    gJiminyAttackCardFairyHarpLine4, gJiminyAttackCardFairyHarpLine5, gJiminyAttackCardFairyHarpLine6, gJiminyAttackCardFairyHarpLine7,
    gJiminyAttackCardFairyHarpLine8, gJiminyAttackCardFairyHarpLine9, gJiminyAttackCardFairyHarpLine10,
};

JiminyTextChar* gJiminyAttackCardWishingStarLines[11] = {
    gJiminyAttackCardWishingStarLine0, gJiminyAttackCardWishingStarLine1, gJiminyAttackCardWishingStarLine2, gJiminyAttackCardWishingStarLine3,
    gJiminyAttackCardWishingStarLine4, gJiminyAttackCardWishingStarLine5, gJiminyAttackCardWishingStarLine6, gJiminyAttackCardWishingStarLine7,
    gJiminyAttackCardWishingStarLine8, gJiminyAttackCardWishingStarLine9, gJiminyAttackCardWishingStarLine10,
};

JiminyTextChar* gJiminyAttackCardSpellbinderLines[11] = {
    gJiminyAttackCardSpellbinderLine0, gJiminyAttackCardSpellbinderLine1, gJiminyAttackCardSpellbinderLine2, gJiminyAttackCardSpellbinderLine3,
    gJiminyAttackCardSpellbinderLine4, gJiminyAttackCardSpellbinderLine5, gJiminyAttackCardSpellbinderLine6, gJiminyAttackCardSpellbinderLine7,
    gJiminyAttackCardSpellbinderLine8, gJiminyAttackCardSpellbinderLine9, gJiminyAttackCardSpellbinderLine10,
};

JiminyTextChar* gJiminyAttackCardMetalChocoboLines[12] = {
    gJiminyAttackCardMetalChocoboLine0, gJiminyAttackCardMetalChocoboLine1, gJiminyAttackCardMetalChocoboLine2, gJiminyAttackCardMetalChocoboLine3,
    gJiminyAttackCardMetalChocoboLine4, gJiminyAttackCardMetalChocoboLine5, gJiminyAttackCardMetalChocoboLine6, gJiminyAttackCardMetalChocoboLine7,
    gJiminyAttackCardMetalChocoboLine8, gJiminyAttackCardMetalChocoboLine9, gJiminyAttackCardMetalChocoboLine10, gJiminyAttackCardMetalChocoboLine11,
};

JiminyTextChar* gJiminyAttackCardOlympiaLines[12] = {
    gJiminyAttackCardOlympiaLine0, gJiminyAttackCardOlympiaLine1, gJiminyAttackCardOlympiaLine2, gJiminyAttackCardOlympiaLine3,
    gJiminyAttackCardOlympiaLine4, gJiminyAttackCardOlympiaLine5, gJiminyAttackCardOlympiaLine6, gJiminyAttackCardOlympiaLine7,
    gJiminyAttackCardOlympiaLine8, gJiminyAttackCardOlympiaLine9, gJiminyAttackCardOlympiaLine10, gJiminyAttackCardOlympiaLine11,
};

JiminyTextChar* gJiminyAttackCardLionheartLines[11] = {
    gJiminyAttackCardLionheartLine0, gJiminyAttackCardLionheartLine1, gJiminyAttackCardLionheartLine2, gJiminyAttackCardLionheartLine3,
    gJiminyAttackCardLionheartLine4, gJiminyAttackCardLionheartLine5, gJiminyAttackCardLionheartLine6, gJiminyAttackCardLionheartLine7,
    gJiminyAttackCardLionheartLine8, gJiminyAttackCardLionheartLine9, gJiminyAttackCardLionheartLine10,
};

JiminyTextChar* gJiminyAttackCardLadyLuckLines[11] = {
    gJiminyAttackCardLadyLuckLine0, gJiminyAttackCardLadyLuckLine1, gJiminyAttackCardLadyLuckLine2, gJiminyAttackCardLadyLuckLine3,
    gJiminyAttackCardLadyLuckLine4, gJiminyAttackCardLadyLuckLine5, gJiminyAttackCardLadyLuckLine6, gJiminyAttackCardLadyLuckLine7,
    gJiminyAttackCardLadyLuckLine8, gJiminyAttackCardLadyLuckLine9, gJiminyAttackCardLadyLuckLine10,
};

JiminyTextChar* gJiminyAttackCardDivineRoseLines[12] = {
    gJiminyAttackCardDivineRoseLine0, gJiminyAttackCardDivineRoseLine1, gJiminyAttackCardDivineRoseLine2, gJiminyAttackCardDivineRoseLine3,
    gJiminyAttackCardDivineRoseLine4, gJiminyAttackCardDivineRoseLine5, gJiminyAttackCardDivineRoseLine6, gJiminyAttackCardDivineRoseLine7,
    gJiminyAttackCardDivineRoseLine8, gJiminyAttackCardDivineRoseLine9, gJiminyAttackCardDivineRoseLine10, gJiminyAttackCardDivineRoseLine11,
};

JiminyTextChar* gJiminyAttackCardOathkeeperLines[11] = {
    gJiminyAttackCardOathkeeperLine0, gJiminyAttackCardOathkeeperLine1, gJiminyAttackCardOathkeeperLine2, gJiminyAttackCardOathkeeperLine3,
    gJiminyAttackCardOathkeeperLine4, gJiminyAttackCardOathkeeperLine5, gJiminyAttackCardOathkeeperLine6, gJiminyAttackCardOathkeeperLine7,
    gJiminyAttackCardOathkeeperLine8, gJiminyAttackCardOathkeeperLine9, gJiminyAttackCardOathkeeperLine10,
};

JiminyTextChar* gJiminyAttackCardOblivionLines[12] = {
    gJiminyAttackCardOblivionLine0, gJiminyAttackCardOblivionLine1, gJiminyAttackCardOblivionLine2, gJiminyAttackCardOblivionLine3,
    gJiminyAttackCardOblivionLine4, gJiminyAttackCardOblivionLine5, gJiminyAttackCardOblivionLine6, gJiminyAttackCardOblivionLine7,
    gJiminyAttackCardOblivionLine8, gJiminyAttackCardOblivionLine9, gJiminyAttackCardOblivionLine10, gJiminyAttackCardOblivionLine11,
};

JiminyTextChar* gJiminyAttackCardDiamondDustLines[12] = {
    gJiminyAttackCardDiamondDustLine0, gJiminyAttackCardDiamondDustLine1, gJiminyAttackCardDiamondDustLine2, gJiminyAttackCardDiamondDustLine3,
    gJiminyAttackCardDiamondDustLine4, gJiminyAttackCardDiamondDustLine5, gJiminyAttackCardDiamondDustLine6, gJiminyAttackCardDiamondDustLine7,
    gJiminyAttackCardDiamondDustLine8, gJiminyAttackCardDiamondDustLine9, gJiminyAttackCardDiamondDustLine10, gJiminyAttackCardDiamondDustLine11,
};

JiminyTextChar* gJiminyAttackCardOneWingedAngelLines[12] = {
    gJiminyAttackCardOneWingedAngelLine0, gJiminyAttackCardOneWingedAngelLine1, gJiminyAttackCardOneWingedAngelLine2, gJiminyAttackCardOneWingedAngelLine3,
    gJiminyAttackCardOneWingedAngelLine4, gJiminyAttackCardOneWingedAngelLine5, gJiminyAttackCardOneWingedAngelLine6, gJiminyAttackCardOneWingedAngelLine7,
    gJiminyAttackCardOneWingedAngelLine8, gJiminyAttackCardOneWingedAngelLine9, gJiminyAttackCardOneWingedAngelLine10, gJiminyAttackCardOneWingedAngelLine11,
};

JiminyTextChar* gJiminyEnemyCardDarksideLines[6] = {
    gJiminyEnemyCardDarksideLine0, gJiminyEnemyCardDarksideLine1, gJiminyEnemyCardDarksideLine2, gJiminyEnemyCardDarksideLine3,
    gJiminyEnemyCardDarksideLine4, gJiminyEnemyCardDarksideLine5,
};

JiminyTextChar* gJiminyEnemyCardOogieBoogieLines[6] = {
    gJiminyEnemyCardOogieBoogieLine0, gJiminyEnemyCardOogieBoogieLine1, gJiminyEnemyCardOogieBoogieLine2, gJiminyEnemyCardOogieBoogieLine3,
    gJiminyEnemyCardOogieBoogieLine4, gJiminyEnemyCardOogieBoogieLine5,
};

JiminyTextChar* gJiminyEnemyCardParasiteCageLines[6] = {
    gJiminyEnemyCardParasiteCageLine0, gJiminyEnemyCardParasiteCageLine1, gJiminyEnemyCardParasiteCageLine2, gJiminyEnemyCardParasiteCageLine3,
    gJiminyEnemyCardParasiteCageLine4, gJiminyEnemyCardParasiteCageLine5,
};

JiminyTextChar* gJiminyEnemyCardAnsemLines[7] = {
    gJiminyEnemyCardAnsemLine0, gJiminyEnemyCardAnsemLine1, gJiminyEnemyCardAnsemLine2, gJiminyEnemyCardAnsemLine3,
    gJiminyEnemyCardAnsemLine4, gJiminyEnemyCardAnsemLine5, gJiminyEnemyCardAnsemLine6,
};

JiminyTextChar* gJiminyEnemyCardTrickmasterLines[8] = {
    gJiminyEnemyCardTrickmasterLine0, gJiminyEnemyCardTrickmasterLine1, gJiminyEnemyCardTrickmasterLine2, gJiminyEnemyCardTrickmasterLine3,
    gJiminyEnemyCardTrickmasterLine4, gJiminyEnemyCardTrickmasterLine5, gJiminyEnemyCardTrickmasterLine6, gJiminyEnemyCardTrickmasterLine7,
};

JiminyTextChar* gJiminyEnemyCardJafarLines[6] = {
    gJiminyEnemyCardJafarLine0, gJiminyEnemyCardJafarLine1, gJiminyEnemyCardJafarLine2, gJiminyEnemyCardJafarLine3,
    gJiminyEnemyCardJafarLine4, gJiminyEnemyCardJafarLine5,
};

JiminyTextChar* gJiminyEnemyCardCardSoldierLines[5] = {
    gJiminyEnemyCardCardSoldierLine0, gJiminyEnemyCardCardSoldierLine1, gJiminyEnemyCardCardSoldierLine2, gJiminyEnemyCardCardSoldierLine3,
    gJiminyEnemyCardCardSoldierLine4,
};

JiminyTextChar* gJiminyMapCardTeemingDarknessLines[4] = {
    gJiminyMapCardTeemingDarknessLine0, gJiminyMapCardTeemingDarknessLine1, gJiminyMapCardTeemingDarknessLine2, gJiminyMapCardTeemingDarknessLine3,
};

JiminyTextChar* gJiminyMapCardLoomingDarknessLines[5] = {
    gJiminyMapCardLoomingDarknessLine0, gJiminyMapCardLoomingDarknessLine1, gJiminyMapCardLoomingDarknessLine2, gJiminyMapCardLoomingDarknessLine3,
    gJiminyMapCardLoomingDarknessLine4,
};

JiminyTextChar* gJiminyMapCardAlmightyDarknessLines[5] = {
    gJiminyMapCardAlmightyDarknessLine0, gJiminyMapCardAlmightyDarknessLine1, gJiminyMapCardAlmightyDarknessLine2, gJiminyMapCardAlmightyDarknessLine3,
    gJiminyMapCardAlmightyDarknessLine4,
};

JiminyTextChar* gJiminyPremiumCardsLines[17] = {
    gJiminyPremiumCardsLine0, gJiminyPremiumCardsLine1, gJiminyPremiumCardsLine2, gJiminyPremiumCardsLine3,
    gJiminyPremiumCardsLine4, gJiminyPremiumCardsLine5, gJiminyPremiumCardsLine6, gJiminyPremiumCardsLine7,
    gJiminyPremiumCardsLine8, gJiminyPremiumCardsLine9, gJiminyPremiumCardsLine10, gJiminyPremiumCardsLine11,
    gJiminyPremiumCardsLine12, gJiminyPremiumCardsLine13, gJiminyPremiumCardsLine14, gJiminyPremiumCardsLine15,
    gJiminyPremiumCardsLine16,
};

JiminyTextChar* gJiminyRikuCardKingLines[4] = {
    gJiminyRikuCardKingLine0, gJiminyRikuCardKingLine1, gJiminyRikuCardKingLine2, gJiminyRikuCardKingLine3,
};

JiminyTextChar* gJiminyStoryAtlanticaLines[25] = {
    gJiminyStoryAtlanticaLine0, gJiminyStoryAtlanticaLine1, gJiminyStoryAtlanticaLine2, gJiminyStoryAtlanticaLine3,
    gJiminyStoryAtlanticaLine4, gJiminyStoryAtlanticaLine5, gJiminyStoryAtlanticaLine6, gJiminyStoryAtlanticaLine7,
    gJiminyStoryAtlanticaLine8, gJiminyStoryAtlanticaLine9, gJiminyStoryAtlanticaLine10, gJiminyStoryAtlanticaLine11,
    gJiminyStoryAtlanticaLine12, gJiminyStoryAtlanticaLine13, gJiminyStoryAtlanticaLine14, gJiminyStoryAtlanticaLine15,
    gJiminyStoryAtlanticaLine16, gJiminyStoryAtlanticaLine17, gJiminyStoryAtlanticaLine18, gJiminyStoryAtlanticaLine19,
    gJiminyStoryAtlanticaLine20, gJiminyStoryAtlanticaLine21, gJiminyStoryAtlanticaLine22, gJiminyStoryAtlanticaLine23,
    gJiminyStoryAtlanticaLine24,
};

JiminyTextChar* gJiminyStory100AcreWoodLines[9] = {
    gJiminyStory100AcreWoodLine0, gJiminyStory100AcreWoodLine1, gJiminyStory100AcreWoodLine2, gJiminyStory100AcreWoodLine3,
    gJiminyStory100AcreWoodLine4, gJiminyStory100AcreWoodLine5, gJiminyStory100AcreWoodLine6, gJiminyStory100AcreWoodLine7,
    gJiminyStory100AcreWoodLine8,
};

JiminyTextChar* gJiminyEnemyCardSearchGhostLines[7] = {
    gJiminyEnemyCardSearchGhostLine0, gJiminyEnemyCardSearchGhostLine1, gJiminyEnemyCardSearchGhostLine2, gJiminyEnemyCardSearchGhostLine3,
    gJiminyEnemyCardSearchGhostLine4, gJiminyEnemyCardSearchGhostLine5, gJiminyEnemyCardSearchGhostLine6,
};

JiminyTextChar* gJiminyEnemyCardWyvernLines[6] = {
    gJiminyEnemyCardWyvernLine0, gJiminyEnemyCardWyvernLine1, gJiminyEnemyCardWyvernLine2, gJiminyEnemyCardWyvernLine3,
    gJiminyEnemyCardWyvernLine4, gJiminyEnemyCardWyvernLine5,
};

JiminyTextChar* gJiminyEnemyCardTornadoStepLines[5] = {
    gJiminyEnemyCardTornadoStepLine0, gJiminyEnemyCardTornadoStepLine1, gJiminyEnemyCardTornadoStepLine2, gJiminyEnemyCardTornadoStepLine3,
    gJiminyEnemyCardTornadoStepLine4,
};

JiminyTextChar* gJiminyHeartlessSeaNeonLines[8] = {
    gJiminyHeartlessSeaNeonLine0, gJiminyHeartlessSeaNeonLine1, gJiminyHeartlessSeaNeonLine2, gJiminyHeartlessSeaNeonLine3,
    gJiminyHeartlessSeaNeonLine4, gJiminyHeartlessSeaNeonLine5, gJiminyHeartlessSeaNeonLine6, gJiminyHeartlessSeaNeonLine7,
};

JiminyTextChar* gJiminyStoryCastleOblivionLines[24] = {
    gJiminyStoryCastleOblivionLine0, gJiminyStoryCastleOblivionLine1, gJiminyStoryCastleOblivionLine2, gJiminyStoryCastleOblivionLine3,
    gJiminyStoryCastleOblivionLine4, gJiminyStoryCastleOblivionLine5, gJiminyStoryCastleOblivionLine6, gJiminyStoryCastleOblivionLine7,
    gJiminyStoryCastleOblivionLine8, gJiminyStoryCastleOblivionLine9, gJiminyStoryCastleOblivionLine10, gJiminyStoryCastleOblivionLine11,
    gJiminyStoryCastleOblivionLine12, gJiminyStoryCastleOblivionLine13, gJiminyStoryCastleOblivionLine14, gJiminyStoryCastleOblivionLine15,
    gJiminyStoryCastleOblivionLine16, gJiminyStoryCastleOblivionLine17, gJiminyStoryCastleOblivionLine18, gJiminyStoryCastleOblivionLine19,
    gJiminyStoryCastleOblivionLine20, gJiminyStoryCastleOblivionLine21, gJiminyStoryCastleOblivionLine22, gJiminyStoryCastleOblivionLine23,
};

JiminyTextChar* gJiminyAttackCardUltimaWeaponLines[10] = {
    gJiminyAttackCardUltimaWeaponLine0, gJiminyAttackCardUltimaWeaponLine1, gJiminyAttackCardUltimaWeaponLine2, gJiminyAttackCardUltimaWeaponLine3,
    gJiminyAttackCardUltimaWeaponLine4, gJiminyAttackCardUltimaWeaponLine5, gJiminyAttackCardUltimaWeaponLine6, gJiminyAttackCardUltimaWeaponLine7,
    gJiminyAttackCardUltimaWeaponLine8, gJiminyAttackCardUltimaWeaponLine9,
};

JiminyTextChar* gJiminyHeartlessNeoshadowLines[3] = {
    gJiminyHeartlessNeoshadowLine0, gJiminyHeartlessNeoshadowLine1, gJiminyHeartlessNeoshadowLine2,
};

JiminyTextChar* gJiminyRootNames[3] = {
    gJiminyMenuStoryName, gJiminyMenuCardIndexName, gJiminyMenuCharactersName,
};

JiminyTextChar* gJiminyEntry01Names[17] = {
    gJiminyStoryTale1Name, gJiminyStoryTale2Name, gJiminyStoryTale3Name, gJiminyStoryTale4Name,
    gWorldNameTraverseTown, gWorldNameWonderland, gWorldNameOlympusColiseum, gWorldNameAgrabah,
    gWorldNameHalloweenTown, gWorldNameMonstro, gWorldNameAtlantica, gWorldNameNeverLand,
    gWorldNameHollowBastion, gWorldName100AcreWood, gWorldNameTwilightTown, gWorldNameDestinyIslands,
    gWorldNameCastleOblivion,
};

JiminyTextChar* gJiminyEntry02Names[7] = {
    gJiminyMenuAttackCardsName, gJiminyMenuMagicCardsName, gJiminyMenuItemCardsName, gJiminyMenuFriendCardsName,
    gJiminyMenuEnemyCardsName, gJiminyMenuMapCardsName, gJiminyMenuPremiumCardsName,
};

JiminyTextChar* gJiminyEntry03Names[3] = {
    gJiminyMenuCharacters1Name, gJiminyMenuCharacters2Name, gJiminyMenuHeartlessName,
};

JiminyTextChar* gJiminyEntry04Names[17] = {
    gCardNameKingdomKey, gCardNameThreeWishes, gCardNameCrabclaw, gCardNamePumpkinhead,
    gCardNameFairyHarp, gCardNameWishingStar, gCardNameSpellbinder, gCardNameMetalChocobo,
    gCardNameOlympia, gCardNameLionheart, gCardNameLadyLuck, gCardNameDivineRose,
    gCardNameOathkeeper, gCardNameOblivion, gCardNameDiamondDust, gCardNameOneWingedAngel,
    gCardNameUltimaWeapon,
};

JiminyTextChar* gJiminyEntry05Names[14] = {
    gCardNameFire, gCardNameBlizzard, gCardNameThunder, gCardNameCure,
    gCardNameGravity, gCardNameStop, gCardNameAero, gCardNameSimba,
    gCardNameDumbo, gCardNameBambi, gCardNameMushu, gCardNameGenie,
    gCardNameTinkerBell, gCardNameCloud,
};

JiminyTextChar* gJiminyEntry06Names[7] = {
    gCardNamePotion, gCardNameHiPotion, gCardNameMegaPotion, gCardNameEther,
    gCardNameMegaEther, gCardNameElixir, gCardNameMegalixir,
};

JiminyTextChar* gJiminyEntry07Names[7] = {
    gCardNameDonaldDuck, gCardNameGoofy, gCardNameAladdin, gCardNameJack,
    gCardNameAriel, gCardNamePeterPan, gCardNameBeast,
};

JiminyTextChar* gJiminyEntry08Names[49] = {
    gEnemyNameShadow, gEnemyNameSoldier, gEnemyNameLargeBody, gEnemyNameRedNocturne,
    gEnemyNameBlueRhapsody, gEnemyNameYellowOpera, gEnemyNameGreenRequiem, gEnemyNamePowerwild,
    gEnemyNameBouncywild, gEnemyNameAirSoldier, gEnemyNameBandit, gEnemyNameFatBandit,
    gEnemyNameBarrelSpider, gEnemyNameSearchGhost, gEnemyNameSeaNeon, gEnemyNameScrewdiver,
    gEnemyNameAquatank, gEnemyNameWightKnight, gEnemyNameGargoyle, gEnemyNamePirate,
    gEnemyNameAirPirate, gEnemyNameDarkball, gEnemyNameDefender, gEnemyNameWyvern,
    gEnemyNameWizard, gEnemyNameNeoshadow, gEnemyNameWhiteMushroom, gEnemyNameBlackFungus,
    gEnemyNameCreeperPlant, gEnemyNameTornadoStep, gEnemyNameCrescendo, gEnemyNameGuardArmor,
    gEnemyNameParasiteCage, gEnemyNameTrickmaster, gEnemyNameDarkside, gEnemyNameCardSoldier,
    gEnemyNameHades, gEnemyNameJafar, gEnemyNameOogieBoogie, gEnemyNameUrsula,
    gEnemyNameHook, gEnemyNameDragonMaleficent, gEnemyNameRiku, gEnemyNameAxel,
    gEnemyNameLarxene, gEnemyNameVexen, gEnemyNameMarluxia, gEnemyNameLexaeus,
    gEnemyNameAnsem,
};

JiminyTextChar* gJiminyEntry09Names[26] = {
    gRoomNameTranquilDarkness, gRoomNameTeemingDarkness, gRoomNameFeebleDarkness, gRoomNameAlmightyDarkness,
    gRoomNameSleepingDarkness, gRoomNameLoomingDarkness, gRoomNamePremiumRoom, gRoomNameWhiteRoom,
    gRoomNameBlackRoom, gRoomNameMartialWaking, gRoomNameSorcerousWaking, gRoomNameAlchemicWaking,
    gRoomNameMeetingGround, gRoomNameStagnantSpace, gRoomNameStrongInitiative, gRoomNameLastingDaze,
    gRoomNameCalmBounty, gRoomNameGuardedTrove, gRoomNameFalseBounty, gRoomNameMomentsReprieve,
    gRoomNameMinglingWorlds, gRoomNameMoogleRoom, gRoomNameKeyOfBeginnings, gRoomNameKeyOfGuidance,
    gRoomNameKeyToTruth, gRoomNameKeyToRewards,
};

JiminyTextChar* gJiminyEntry10Names[1] = {
    gJiminyPremiumCardsName,
};

JiminyTextChar* gJiminyEntry11Names[25] = {
    gCharacterNameSora, gCardNameDonaldDuck, gCardNameGoofy, gCharacterNameJiminyCricket,
    gEnemyNameRiku, gCharacterNameKairi, gCardNameSimba, gCardNameDumbo,
    gCardNameBambi, gCardNameMushu, gCharacterNameMoogles, gCharacterNameLeon,
    gCharacterNameYuffie, gCharacterNameAerith, gCharacterNameCid, gCardNameCloud,
    gCharacterNameTidus, gCharacterNameWakka, gCharacterNameSelphie, gCharacterNameNamine,
    gCharacterNameRikuReplica, gEnemyNameAxel, gEnemyNameLarxene, gEnemyNameVexen,
    gEnemyNameMarluxia,
};

JiminyTextChar* gJiminyEntry12Names[40] = {
    gCharacterNameAlice, gCharacterNameQueenOfHearts, gCharacterNameWhiteRabbit, gCharacterNameCardOfHearts,
    gCharacterNameCardOfSpades, gCharacterNameCheshireCat, gCharacterNameHercules, gCharacterNamePhiloctetes,
    gEnemyNameHades, gCardNameAladdin, gCardNameGenie, gCharacterNameJasmine,
    gCharacterNameIago, gEnemyNameJafar, gCharacterNameJafarGenie, gCardNameJack,
    gCharacterNameSally, gCharacterNameDrFinkelstein, gEnemyNameOogieBoogie, gCharacterNamePinocchio,
    gCharacterNameGeppetto, gCardNameAriel, gCharacterNameSebastian, gCharacterNameFlounder,
    gEnemyNameUrsula, gCardNamePeterPan, gCardNameTinkerBell, gCharacterNameWendy,
    gCharacterNameHook, gCardNameBeast, gCharacterNameBelle, gCharacterNameMaleficent,
    gEnemyNameDragonMaleficent, gCharacterNameWinnieThePooh, gCharacterNamePiglet, gCharacterNameOwl,
    gCharacterNameRoo, gCharacterNameEeyore, gCharacterNameTigger, gCharacterNameRabbit,
};

JiminyTextChar* gJiminyEntry13Names[35] = {
    gEnemyNameShadow, gEnemyNameSoldier, gEnemyNameLargeBody, gEnemyNameRedNocturne,
    gEnemyNameBlueRhapsody, gEnemyNameYellowOpera, gEnemyNameGreenRequiem, gEnemyNamePowerwild,
    gEnemyNameBouncywild, gEnemyNameAirSoldier, gEnemyNameBandit, gEnemyNameFatBandit,
    gEnemyNameBarrelSpider, gEnemyNameSearchGhost, gEnemyNameSeaNeon, gEnemyNameScrewdiver,
    gEnemyNameAquatank, gEnemyNameWightKnight, gEnemyNameGargoyle, gEnemyNamePirate,
    gEnemyNameAirPirate, gEnemyNameDarkball, gEnemyNameDefender, gEnemyNameWyvern,
    gEnemyNameWizard, gEnemyNameNeoshadow, gEnemyNameWhiteMushroom, gEnemyNameBlackFungus,
    gEnemyNameCreeperPlant, gEnemyNameTornadoStep, gEnemyNameCrescendo, gEnemyNameGuardArmor,
    gEnemyNameParasiteCage, gEnemyNameTrickmaster, gEnemyNameDarkside,
};

JiminyTextChar* gJiminyEntry15Names[6] = {
    gJiminyRikuStoryTale1Name, gJiminyRikuStoryTale2Name, gJiminyRikuStoryTale3Name, gJiminyRikuStoryTale4Name,
    gJiminyRikuStoryTale5Name, gJiminyRikuStoryTale6Name,
};

JiminyTextChar* gJiminyEntry18Names[14] = {
    gEnemyNameRiku, gCardNameKing, gCharacterNameSora, gCharacterNameKairi,
    gCharacterNameNamine, gCharacterNameRikuReplica, gEnemyNameAnsem, gEnemyNameVexen,
    gEnemyNameLexaeus, gCharacterNameZexion, gEnemyNameAxel, gEnemyNameMarluxia,
    gEnemyNameLarxene, gCharacterNameDiZ,
};

JiminyTextChar* gJiminyEntry19Names[6] = {
    gCharacterNameMaleficent, gCharacterNameJafarGenie, gEnemyNameUrsula, gEnemyNameHades,
    gEnemyNameOogieBoogie, gCharacterNameHook,
};

JiminyTextChar* gJiminyEntry20Names[33] = {
    gEnemyNameShadow, gEnemyNameSoldier, gEnemyNameLargeBody, gEnemyNameRedNocturne,
    gEnemyNameBlueRhapsody, gEnemyNameYellowOpera, gEnemyNameGreenRequiem, gEnemyNamePowerwild,
    gEnemyNameBouncywild, gEnemyNameAirSoldier, gEnemyNameBandit, gEnemyNameFatBandit,
    gEnemyNameBarrelSpider, gEnemyNameSearchGhost, gEnemyNameSeaNeon, gEnemyNameScrewdiver,
    gEnemyNameAquatank, gEnemyNameWightKnight, gEnemyNameGargoyle, gEnemyNamePirate,
    gEnemyNameAirPirate, gEnemyNameDarkball, gEnemyNameDefender, gEnemyNameWyvern,
    gEnemyNameWizard, gEnemyNameNeoshadow, gEnemyNameCreeperPlant, gEnemyNameTornadoStep,
    gEnemyNameCrescendo, gEnemyNameGuardArmor, gEnemyNameParasiteCage, gEnemyNameTrickmaster,
    gEnemyNameDarkside,
};

JiminyTextChar* gJiminyEntry16Names[22] = {
    gCardNameSoulEater, gCardNameKing, gEnemyNameShadow, gEnemyNameLargeBody,
    gEnemyNamePowerwild, gEnemyNameFatBandit, gEnemyNameSearchGhost, gEnemyNameSeaNeon,
    gEnemyNameWightKnight, gEnemyNamePirate, gEnemyNameDefender, gEnemyNameGuardArmor,
    gEnemyNameParasiteCage, gEnemyNameTrickmaster, gEnemyNameDarkside, gEnemyNameHades,
    gEnemyNameJafar, gEnemyNameOogieBoogie, gEnemyNameUrsula, gEnemyNameHook,
    gEnemyNameDragonMaleficent, gEnemyNameLexaeus,
};

const JiminyTextChar* gJiminyHiddenTexts[13] = {
    gJiminyHiddenText0, gJiminyHiddenText1, gJiminyHiddenText2, gJiminyHiddenText3,
    gJiminyHiddenText4, gJiminyHiddenText5, gJiminyHiddenText6, gJiminyHiddenText7,
    gJiminyHiddenText8, gJiminyHiddenText9, gJiminyHiddenText10, gJiminyHiddenText11,
    gJiminyHiddenText12,
};

#elif defined(VERSION_JP)

JiminyTextChar* gJiminyStoryTale1Lines[12] = {
    gJiminyStoryTale1Line0, gJiminyStoryTale1Line1, gJiminyStoryTale1Line2, gJiminyStoryTale1Line3,
    gJiminyStoryTale1Line4, gJiminyStoryTale1Line5, gJiminyStoryTale1Line6, gJiminyStoryTale1Line7,
    gJiminyStoryTale1Line8, gJiminyStoryTale1Line9, gJiminyStoryTale1Line10, gJiminyStoryTale1Line11,
};

JiminyTextChar* gJiminyStoryTale2Lines[14] = {
    gJiminyStoryTale2Line0, gJiminyStoryTale2Line1, gJiminyStoryTale2Line2, gJiminyStoryTale2Line3,
    gJiminyStoryTale2Line4, gJiminyStoryTale2Line5, gJiminyStoryTale2Line6, gJiminyStoryTale2Line7,
    gJiminyStoryTale2Line8, gJiminyStoryTale2Line9, gJiminyStoryTale2Line10, gJiminyStoryTale2Line11,
    gJiminyStoryTale2Line12, gJiminyStoryTale2Line13,
};

JiminyTextChar* gJiminyStoryTale3Lines[16] = {
    gJiminyStoryTale3Line0, gJiminyStoryTale3Line1, gJiminyStoryTale3Line2, gJiminyStoryTale3Line3,
    gJiminyStoryTale3Line4, gJiminyStoryTale3Line5, gJiminyStoryTale3Line6, gJiminyStoryTale3Line7,
    gJiminyStoryTale3Line8, gJiminyStoryTale3Line9, gJiminyStoryTale3Line10, gJiminyStoryTale3Line11,
    gJiminyStoryTale3Line12, gJiminyStoryTale3Line13, gJiminyStoryTale3Line14, gJiminyStoryTale3Line15,
};

JiminyTextChar* gJiminyStoryTale4Lines[18] = {
    gJiminyStoryTale4Line0, gJiminyStoryTale4Line1, gJiminyStoryTale4Line2, gJiminyStoryTale4Line3,
    gJiminyStoryTale4Line4, gJiminyStoryTale4Line5, gJiminyStoryTale4Line6, gJiminyStoryTale4Line7,
    gJiminyStoryTale4Line8, gJiminyStoryTale4Line9, gJiminyStoryTale4Line10, gJiminyStoryTale4Line11,
    gJiminyStoryTale4Line12, gJiminyStoryTale4Line13, gJiminyStoryTale4Line14, gJiminyStoryTale4Line15,
    gJiminyStoryTale4Line16, gJiminyStoryTale4Line17,
};

JiminyTextChar* gJiminyStoryTraverseTownLines[16] = {
    gJiminyStoryTale1Line5, gJiminyStoryTraverseTownLine1, gJiminyStoryTraverseTownLine2, gJiminyStoryTraverseTownLine3,
    gJiminyStoryTraverseTownLine4, gJiminyStoryTraverseTownLine5, gJiminyStoryTraverseTownLine6, gJiminyStoryTraverseTownLine7,
    gJiminyStoryTraverseTownLine8, gJiminyStoryTraverseTownLine9, gJiminyStoryTraverseTownLine10, gJiminyStoryTraverseTownLine11,
    gJiminyStoryTraverseTownLine12, gJiminyStoryTraverseTownLine13, gJiminyStoryTraverseTownLine14, gJiminyStoryTraverseTownLine15,
};

JiminyTextChar* gJiminyStoryWonderlandLines[16] = {
    gJiminyStoryWonderlandLine0, gJiminyStoryWonderlandLine1, gJiminyStoryWonderlandLine2, gJiminyStoryWonderlandLine3,
    gJiminyStoryWonderlandLine4, gJiminyStoryWonderlandLine5, gJiminyStoryWonderlandLine6, gJiminyStoryWonderlandLine7,
    gJiminyStoryWonderlandLine8, gJiminyStoryWonderlandLine9, gJiminyStoryWonderlandLine10, gJiminyStoryWonderlandLine11,
    gJiminyStoryWonderlandLine12, gJiminyStoryWonderlandLine13, gJiminyStoryWonderlandLine14, gJiminyStoryWonderlandLine15,
};

JiminyTextChar* gJiminyStoryOlympusColiseumLines[16] = {
    gJiminyStoryOlympusColiseumLine0, gJiminyStoryOlympusColiseumLine1, gJiminyStoryOlympusColiseumLine2, gJiminyStoryOlympusColiseumLine3,
    gJiminyStoryOlympusColiseumLine4, gJiminyStoryOlympusColiseumLine5, gJiminyStoryOlympusColiseumLine6, gJiminyStoryOlympusColiseumLine7,
    gJiminyStoryOlympusColiseumLine8, gJiminyStoryOlympusColiseumLine9, gJiminyStoryOlympusColiseumLine10, gJiminyStoryOlympusColiseumLine11,
    gJiminyStoryOlympusColiseumLine12, gJiminyStoryOlympusColiseumLine13, gJiminyStoryOlympusColiseumLine14, gJiminyStoryOlympusColiseumLine15,
};

JiminyTextChar* gJiminyStoryAgrabahLines[26] = {
    gJiminyStoryAgrabahLine0, gJiminyStoryAgrabahLine1, gJiminyStoryAgrabahLine2, gJiminyStoryAgrabahLine3,
    gJiminyStoryAgrabahLine4, gJiminyStoryAgrabahLine5, gJiminyStoryAgrabahLine6, gJiminyStoryAgrabahLine7,
    gJiminyStoryAgrabahLine8, gJiminyStoryAgrabahLine9, gJiminyStoryAgrabahLine10, gJiminyStoryAgrabahLine11,
    gJiminyStoryAgrabahLine12, gJiminyStoryAgrabahLine13, gJiminyStoryAgrabahLine14, gJiminyStoryAgrabahLine15,
    gJiminyStoryAgrabahLine16, gJiminyStoryAgrabahLine17, gJiminyStoryAgrabahLine18, gJiminyStoryAgrabahLine19,
    gJiminyStoryAgrabahLine20, gJiminyStoryAgrabahLine21, gJiminyStoryAgrabahLine22, gJiminyStoryAgrabahLine23,
    gJiminyStoryAgrabahLine24, gJiminyStoryAgrabahLine25,
};

JiminyTextChar* gJiminyStoryHalloweenTownLines[19] = {
    gJiminyStoryHalloweenTownLine0, gJiminyStoryHalloweenTownLine1, gJiminyStoryHalloweenTownLine2, gJiminyStoryHalloweenTownLine3,
    gJiminyStoryHalloweenTownLine4, gJiminyStoryHalloweenTownLine5, gJiminyStoryHalloweenTownLine6, gJiminyStoryHalloweenTownLine7,
    gJiminyStoryHalloweenTownLine8, gJiminyStoryHalloweenTownLine9, gJiminyStoryHalloweenTownLine10, gJiminyStoryHalloweenTownLine11,
    gJiminyStoryHalloweenTownLine12, gJiminyStoryHalloweenTownLine13, gJiminyStoryHalloweenTownLine14, gJiminyStoryHalloweenTownLine15,
    gJiminyStoryHalloweenTownLine16, gJiminyStoryHalloweenTownLine17, gJiminyStoryHalloweenTownLine18,
};

JiminyTextChar* gJiminyStoryMonstroLines[22] = {
    gJiminyStoryMonstroLine0, gJiminyStoryMonstroLine1, gJiminyStoryMonstroLine2, gJiminyStoryMonstroLine3,
    gJiminyStoryMonstroLine4, gJiminyStoryMonstroLine5, gJiminyStoryMonstroLine6, gJiminyStoryMonstroLine7,
    gJiminyStoryMonstroLine8, gJiminyStoryMonstroLine9, gJiminyStoryMonstroLine10, gJiminyStoryMonstroLine11,
    gJiminyStoryMonstroLine12, gJiminyStoryMonstroLine13, gJiminyStoryMonstroLine14, gJiminyStoryMonstroLine15,
    gJiminyStoryMonstroLine16, gJiminyStoryMonstroLine17, gJiminyStoryMonstroLine18, gJiminyStoryMonstroLine19,
    gJiminyStoryMonstroLine20, gJiminyStoryMonstroLine21,
};

JiminyTextChar* gJiminyStoryAtlanticaLines[21] = {
    gJiminyStoryAtlanticaLine0, gJiminyStoryAtlanticaLine1, gJiminyStoryAtlanticaLine2, gJiminyStoryAtlanticaLine3,
    gJiminyStoryAtlanticaLine4, gJiminyStoryAtlanticaLine5, gJiminyStoryAtlanticaLine6, gJiminyStoryAtlanticaLine7,
    gJiminyStoryAtlanticaLine8, gJiminyStoryAtlanticaLine9, gJiminyStoryAtlanticaLine10, gJiminyStoryAtlanticaLine11,
    gJiminyStoryAtlanticaLine12, gJiminyStoryAtlanticaLine13, gJiminyStoryOlympusColiseumLine10, gJiminyStoryAtlanticaLine15,
    gJiminyStoryAtlanticaLine16, gJiminyStoryAtlanticaLine17, gJiminyStoryAtlanticaLine18, gJiminyStoryAtlanticaLine19,
    gJiminyStoryAtlanticaLine20,
};

JiminyTextChar* gJiminyStoryNeverLandLines[22] = {
    gJiminyStoryNeverLandLine0, gJiminyStoryNeverLandLine1, gJiminyStoryNeverLandLine2, gJiminyStoryNeverLandLine3,
    gJiminyStoryNeverLandLine4, gJiminyStoryNeverLandLine5, gJiminyStoryNeverLandLine6, gJiminyStoryNeverLandLine7,
    gJiminyStoryNeverLandLine8, gJiminyStoryNeverLandLine9, gJiminyStoryNeverLandLine10, gJiminyStoryNeverLandLine11,
    gJiminyStoryNeverLandLine12, gJiminyStoryNeverLandLine13, gJiminyStoryNeverLandLine14, gJiminyStoryNeverLandLine15,
    gJiminyStoryNeverLandLine16, gJiminyStoryNeverLandLine17, gJiminyStoryNeverLandLine18, gJiminyStoryNeverLandLine19,
    gJiminyStoryNeverLandLine20, gJiminyStoryNeverLandLine21,
};

JiminyTextChar* gJiminyStoryHollowBastionLines[21] = {
    gJiminyStoryHollowBastionLine0, gJiminyStoryHollowBastionLine1, gJiminyStoryHollowBastionLine2, gJiminyStoryHollowBastionLine3,
    gJiminyStoryHollowBastionLine4, gJiminyStoryHollowBastionLine5, gJiminyStoryHollowBastionLine6, gJiminyStoryHollowBastionLine7,
    gJiminyStoryHollowBastionLine8, gJiminyStoryHollowBastionLine9, gJiminyStoryHollowBastionLine10, gJiminyStoryHollowBastionLine11,
    gJiminyStoryHollowBastionLine12, gJiminyStoryHollowBastionLine13, gJiminyStoryHollowBastionLine14, gJiminyStoryHollowBastionLine15,
    gJiminyStoryHollowBastionLine16, gJiminyStoryHollowBastionLine17, gJiminyStoryHollowBastionLine18, gJiminyStoryHollowBastionLine19,
    gJiminyStoryHollowBastionLine20,
};

JiminyTextChar* gJiminyStory100AcreWoodLines[10] = {
    gJiminyStory100AcreWoodLine0, gJiminyStory100AcreWoodLine1, gJiminyStory100AcreWoodLine2, gJiminyStoryAtlanticaLine20,
    gJiminyStory100AcreWoodLine4, gJiminyStory100AcreWoodLine5, gJiminyStory100AcreWoodLine6, gJiminyStory100AcreWoodLine7,
    gJiminyStory100AcreWoodLine8, gJiminyStory100AcreWoodLine9,
};

JiminyTextChar* gJiminyStoryTwilightTownLines[10] = {
    gJiminyStoryTwilightTownLine0, gJiminyStoryTwilightTownLine1, gJiminyStoryTwilightTownLine2, gJiminyStoryTwilightTownLine3,
    gJiminyStoryTwilightTownLine4, gJiminyStoryTwilightTownLine5, gJiminyStoryTwilightTownLine6, gJiminyStoryTwilightTownLine7,
    gJiminyStoryTwilightTownLine8, gJiminyStoryTwilightTownLine9,
};

JiminyTextChar* gJiminyStoryDestinyIslandsLines[11] = {
    gJiminyStoryDestinyIslandsLine0, gJiminyStoryDestinyIslandsLine1, gJiminyStoryNeverLandLine18, gJiminyStoryDestinyIslandsLine3,
    gJiminyStoryDestinyIslandsLine4, gJiminyStoryDestinyIslandsLine5, gJiminyStoryDestinyIslandsLine6, gJiminyStoryDestinyIslandsLine7,
    gJiminyStoryDestinyIslandsLine8, gJiminyStoryDestinyIslandsLine9, gJiminyStoryDestinyIslandsLine10,
};

JiminyTextChar* gJiminyStoryCastleOblivionLines[16] = {
    gJiminyStoryCastleOblivionLine0, gJiminyStoryCastleOblivionLine1, gJiminyStoryCastleOblivionLine2, gJiminyStoryCastleOblivionLine3,
    gJiminyStoryCastleOblivionLine4, gJiminyStoryCastleOblivionLine5, gJiminyStoryCastleOblivionLine6, gJiminyStoryCastleOblivionLine7,
    gJiminyStoryCastleOblivionLine8, gJiminyStoryCastleOblivionLine9, gJiminyStoryCastleOblivionLine10, gJiminyStoryCastleOblivionLine11,
    gJiminyStoryCastleOblivionLine12, gJiminyStoryCastleOblivionLine13, gJiminyStoryCastleOblivionLine14, gJiminyStoryCastleOblivionLine15,
};

JiminyTextChar* gJiminyRikuStoryTale1Lines[28] = {
    gJiminyRikuStoryTale1Line0, gJiminyRikuStoryTale1Line1, gJiminyRikuStoryTale1Line2, gJiminyRikuStoryTale1Line3,
    gJiminyRikuStoryTale1Line4, gJiminyRikuStoryTale1Line5, gJiminyRikuStoryTale1Line6, gJiminyRikuStoryTale1Line7,
    gJiminyRikuStoryTale1Line8, gJiminyRikuStoryTale1Line9, gJiminyRikuStoryTale1Line10, gJiminyRikuStoryTale1Line11,
    gJiminyRikuStoryTale1Line12, gJiminyRikuStoryTale1Line13, gJiminyRikuStoryTale1Line14, gJiminyRikuStoryTale1Line15,
    gJiminyRikuStoryTale1Line16, gJiminyRikuStoryTale1Line17, gJiminyRikuStoryTale1Line18, gJiminyRikuStoryTale1Line19,
    gJiminyRikuStoryTale1Line20, gJiminyRikuStoryTale1Line21, gJiminyRikuStoryTale1Line22, gJiminyRikuStoryTale1Line23,
    gJiminyRikuStoryTale1Line24, gJiminyRikuStoryTale1Line25, gJiminyRikuStoryTale1Line26, gJiminyRikuStoryTale1Line27,
};

JiminyTextChar* gJiminyRikuStoryTale2Lines[16] = {
    gJiminyRikuStoryTale2Line0, gJiminyRikuStoryTale2Line1, gJiminyRikuStoryTale2Line2, gJiminyRikuStoryTale2Line3,
    gJiminyRikuStoryTale2Line4, gJiminyRikuStoryTale2Line5, gJiminyRikuStoryTale2Line6, gJiminyRikuStoryTale2Line7,
    gJiminyRikuStoryTale2Line8, gJiminyRikuStoryTale2Line9, gJiminyRikuStoryTale2Line10, gJiminyRikuStoryTale2Line11,
    gJiminyRikuStoryTale2Line12, gJiminyRikuStoryTale2Line13, gJiminyRikuStoryTale2Line14, gJiminyRikuStoryTale2Line15,
};

JiminyTextChar* gJiminyRikuStoryTale3Lines[13] = {
    gJiminyRikuStoryTale3Line0, gJiminyRikuStoryTale3Line1, gJiminyRikuStoryTale3Line2, gJiminyRikuStoryTale3Line3,
    gJiminyRikuStoryTale3Line4, gJiminyRikuStoryTale3Line5, gJiminyRikuStoryTale3Line6, gJiminyRikuStoryTale3Line7,
    gJiminyRikuStoryTale3Line8, gJiminyRikuStoryTale3Line9, gJiminyRikuStoryTale3Line10, gJiminyRikuStoryTale3Line11,
    gJiminyRikuStoryTale3Line12,
};

JiminyTextChar* gJiminyRikuStoryTale4Lines[14] = {
    gJiminyRikuStoryTale4Line0, gJiminyRikuStoryTale4Line1, gJiminyRikuStoryTale4Line2, gJiminyRikuStoryTale4Line3,
    gJiminyRikuStoryTale4Line4, gJiminyRikuStoryTale4Line5, gJiminyRikuStoryTale4Line6, gJiminyRikuStoryTale4Line7,
    gJiminyRikuStoryTale4Line8, gJiminyRikuStoryTale4Line9, gJiminyRikuStoryTale4Line10, gJiminyRikuStoryTale4Line11,
    gJiminyRikuStoryTale4Line12, gJiminyStoryNeverLandLine12,
};

JiminyTextChar* gJiminyRikuStoryTale5Lines[16] = {
    gJiminyRikuStoryTale5Line0, gJiminyRikuStoryTale5Line1, gJiminyRikuStoryTale5Line2, gJiminyRikuStoryTale5Line3,
    gJiminyRikuStoryTale5Line4, gJiminyRikuStoryTale5Line5, gJiminyRikuStoryTale5Line6, gJiminyRikuStoryTale5Line7,
    gJiminyRikuStoryTale5Line8, gJiminyRikuStoryTale5Line9, gJiminyRikuStoryTale5Line10, gJiminyRikuStoryTale5Line11,
    gJiminyRikuStoryTale5Line12, gJiminyRikuStoryTale5Line13, gJiminyRikuStoryTale5Line14, gJiminyRikuStoryTale5Line15,
};

JiminyTextChar* gJiminyRikuStoryTale6Lines[23] = {
    gJiminyRikuStoryTale6Line0, gJiminyRikuStoryTale6Line1, gJiminyRikuStoryTale6Line2, gJiminyRikuStoryTale6Line3,
    gJiminyStoryCastleOblivionLine3, gJiminyRikuStoryTale6Line5, gJiminyRikuStoryTale6Line6, gJiminyRikuStoryTale6Line7,
    gJiminyRikuStoryTale6Line8, gJiminyRikuStoryTale6Line9, gJiminyRikuStoryTale6Line10, gJiminyRikuStoryTale6Line11,
    gJiminyRikuStoryTale6Line12, gJiminyRikuStoryTale6Line13, gJiminyRikuStoryTale6Line14, gJiminyRikuStoryTale6Line15,
    gJiminyRikuStoryTale6Line16, gJiminyRikuStoryTale6Line17, gJiminyRikuStoryTale6Line18, gJiminyRikuStoryTale6Line19,
    gJiminyRikuStoryTale6Line20, gJiminyRikuStoryTale6Line21, gJiminyRikuStoryTale6Line22,
};

JiminyTextChar* gJiminyAttackCardKingdomKeyLines[11] = {
    gJiminyAttackCardKingdomKeyLine0, gJiminyAttackCardKingdomKeyLine1, gJiminyAttackCardKingdomKeyLine2, gJiminyAttackCardKingdomKeyLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardKingdomKeyLine5, gJiminyAttackCardKingdomKeyLine6, gJiminyBlankLine,
    gJiminyAttackCardKingdomKeyLine8, gJiminyAttackCardKingdomKeyLine9, gJiminyAttackCardKingdomKeyLine10,
};

JiminyTextChar* gJiminyAttackCardThreeWishesLines[11] = {
    gJiminyAttackCardThreeWishesLine0, gJiminyAttackCardKingdomKeyLine1, gJiminyAttackCardThreeWishesLine2, gJiminyAttackCardThreeWishesLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardKingdomKeyLine5, gJiminyAttackCardThreeWishesLine6, gJiminyBlankLine,
    gJiminyAttackCardThreeWishesLine8, gJiminyAttackCardThreeWishesLine9, gJiminyAttackCardThreeWishesLine10,
};

JiminyTextChar* gJiminyAttackCardCrabclawLines[13] = {
    gJiminyAttackCardCrabclawLine0, gJiminyAttackCardCrabclawLine1, gJiminyAttackCardCrabclawLine2, gJiminyAttackCardKingdomKeyLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardCrabclawLine5, gJiminyAttackCardCrabclawLine6, gJiminyBlankLine,
    gJiminyAttackCardCrabclawLine8, gJiminyAttackCardCrabclawLine9, gJiminyAttackCardCrabclawLine10, gJiminyAttackCardCrabclawLine11,
    gJiminyAttackCardCrabclawLine12,
};

JiminyTextChar* gJiminyAttackCardPumpkinheadLines[12] = {
    gJiminyAttackCardThreeWishesLine0, gJiminyAttackCardPumpkinheadLine1, gJiminyAttackCardKingdomKeyLine2, gJiminyAttackCardKingdomKeyLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardPumpkinheadLine5, gJiminyAttackCardThreeWishesLine6, gJiminyBlankLine,
    gJiminyAttackCardPumpkinheadLine8, gJiminyAttackCardCrabclawLine9, gJiminyAttackCardPumpkinheadLine10, gJiminyAttackCardPumpkinheadLine11,
};

JiminyTextChar* gJiminyAttackCardFairyHarpLines[11] = {
    gJiminyAttackCardThreeWishesLine0, gJiminyAttackCardPumpkinheadLine1, gJiminyAttackCardFairyHarpLine2, gJiminyAttackCardFairyHarpLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardKingdomKeyLine5, gJiminyAttackCardCrabclawLine6, gJiminyBlankLine,
    gJiminyAttackCardFairyHarpLine8, gJiminyAttackCardFairyHarpLine9, gJiminyAttackCardFairyHarpLine10,
};

JiminyTextChar* gJiminyAttackCardWishingStarLines[11] = {
    gJiminyAttackCardCrabclawLine0, gJiminyAttackCardCrabclawLine1, gJiminyAttackCardKingdomKeyLine2, gJiminyAttackCardThreeWishesLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardPumpkinheadLine5, gJiminyAttackCardThreeWishesLine6, gJiminyBlankLine,
    gJiminyAttackCardWishingStarLine8, gJiminyAttackCardWishingStarLine9, gJiminyAttackCardWishingStarLine10,
};

JiminyTextChar* gJiminyAttackCardSpellbinderLines[10] = {
    gJiminyAttackCardKingdomKeyLine0, gJiminyAttackCardSpellbinderLine1, gJiminyAttackCardKingdomKeyLine2, gJiminyAttackCardSpellbinderLine3,
    gJiminyAttackCardSpellbinderLine4, gJiminyAttackCardPumpkinheadLine5, gJiminyAttackCardCrabclawLine6, gJiminyBlankLine,
    gJiminyAttackCardSpellbinderLine8, gJiminyAttackCardSpellbinderLine9,
};

JiminyTextChar* gJiminyAttackCardMetalChocoboLines[11] = {
    gJiminyAttackCardThreeWishesLine0, gJiminyAttackCardPumpkinheadLine1, gJiminyAttackCardCrabclawLine2, gJiminyAttackCardSpellbinderLine3,
    gJiminyAttackCardMetalChocoboLine4, gJiminyAttackCardKingdomKeyLine5, gJiminyAttackCardCrabclawLine6, gJiminyBlankLine,
    gJiminyAttackCardMetalChocoboLine8, gJiminyAttackCardMetalChocoboLine9, gJiminyAttackCardMetalChocoboLine10,
};

JiminyTextChar* gJiminyAttackCardOlympiaLines[12] = {
    gJiminyAttackCardThreeWishesLine0, gJiminyAttackCardKingdomKeyLine1, gJiminyAttackCardThreeWishesLine2, gJiminyAttackCardSpellbinderLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardPumpkinheadLine5, gJiminyAttackCardThreeWishesLine6, gJiminyBlankLine,
    gJiminyAttackCardOlympiaLine8, gJiminyAttackCardOlympiaLine9, gJiminyAttackCardOlympiaLine10, gJiminyAttackCardOlympiaLine11,
};

JiminyTextChar* gJiminyAttackCardLionheartLines[10] = {
    gJiminyAttackCardLionheartLine0, gJiminyAttackCardLionheartLine1, gJiminyAttackCardThreeWishesLine2, gJiminyAttackCardLionheartLine3,
    gJiminyAttackCardLionheartLine4, gJiminyAttackCardPumpkinheadLine5, gJiminyAttackCardCrabclawLine6, gJiminyBlankLine,
    gJiminyAttackCardLionheartLine8, gJiminyAttackCardSpellbinderLine9,
};

JiminyTextChar* gJiminyAttackCardLadyLuckLines[12] = {
    gJiminyAttackCardThreeWishesLine0, gJiminyAttackCardPumpkinheadLine1, gJiminyAttackCardLadyLuckLine2, gJiminyAttackCardThreeWishesLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardKingdomKeyLine5, gJiminyAttackCardThreeWishesLine6, gJiminyBlankLine,
    gJiminyAttackCardLadyLuckLine8, gJiminyAttackCardCrabclawLine9, gJiminyAttackCardLadyLuckLine10, gJiminyAttackCardFairyHarpLine10,
};

JiminyTextChar* gJiminyAttackCardDivineRoseLines[12] = {
    gJiminyAttackCardDivineRoseLine0, gJiminyAttackCardKingdomKeyLine1, gJiminyAttackCardFairyHarpLine2, gJiminyAttackCardThreeWishesLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardDivineRoseLine5, gJiminyAttackCardCrabclawLine6, gJiminyBlankLine,
    gJiminyAttackCardDivineRoseLine8, gJiminyAttackCardDivineRoseLine9, gJiminyAttackCardDivineRoseLine10, gJiminyAttackCardDivineRoseLine11,
};

JiminyTextChar* gJiminyAttackCardOathkeeperLines[10] = {
    gJiminyAttackCardLionheartLine0, gJiminyAttackCardOathkeeperLine1, gJiminyAttackCardCrabclawLine2, gJiminyAttackCardKingdomKeyLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardKingdomKeyLine5, gJiminyAttackCardOathkeeperLine6, gJiminyBlankLine,
    gJiminyAttackCardOathkeeperLine8, gJiminyAttackCardOathkeeperLine9,
};

JiminyTextChar* gJiminyAttackCardOblivionLines[11] = {
    gJiminyAttackCardDivineRoseLine0, gJiminyAttackCardSpellbinderLine1, gJiminyAttackCardLadyLuckLine2, gJiminyAttackCardSpellbinderLine3,
    gJiminyAttackCardMetalChocoboLine4, gJiminyAttackCardPumpkinheadLine5, gJiminyAttackCardOathkeeperLine6, gJiminyBlankLine,
    gJiminyAttackCardMetalChocoboLine8, gJiminyAttackCardMetalChocoboLine9, gJiminyAttackCardOblivionLine10,
};

JiminyTextChar* gJiminyAttackCardDiamondDustLines[12] = {
    gJiminyAttackCardDiamondDustLine0, gJiminyAttackCardDiamondDustLine1, gJiminyAttackCardThreeWishesLine2, gJiminyAttackCardFairyHarpLine3,
    gJiminyAttackCardDiamondDustLine4, gJiminyAttackCardCrabclawLine5, gJiminyAttackCardOathkeeperLine6, gJiminyBlankLine,
    gJiminyAttackCardDiamondDustLine8, gJiminyAttackCardSpellbinderLine9, gJiminyAttackCardDiamondDustLine10, gJiminyAttackCardWishingStarLine10,
};

JiminyTextChar* gJiminyAttackCardOneWingedAngelLines[12] = {
    gJiminyAttackCardCrabclawLine0, gJiminyAttackCardCrabclawLine1, gJiminyAttackCardOneWingedAngelLine2, gJiminyAttackCardThreeWishesLine3,
    gJiminyAttackCardLionheartLine4, gJiminyAttackCardDivineRoseLine5, gJiminyAttackCardOathkeeperLine6, gJiminyBlankLine,
    gJiminyAttackCardLionheartLine8, gJiminyAttackCardSpellbinderLine9, gJiminyAttackCardOneWingedAngelLine10, gJiminyAttackCardOneWingedAngelLine11,
};

JiminyTextChar* gJiminyAttackCardUltimaWeaponLines[10] = {
    gJiminyAttackCardUltimaWeaponLine0, gJiminyAttackCardOathkeeperLine1, gJiminyAttackCardUltimaWeaponLine2, gJiminyAttackCardKingdomKeyLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardKingdomKeyLine5, gJiminyAttackCardUltimaWeaponLine6, gJiminyBlankLine,
    gJiminyAttackCardUltimaWeaponLine8, gJiminyAttackCardUltimaWeaponLine9,
};

JiminyTextChar* gJiminyMagicCardFireLines[5] = {
    gJiminyMagicCardFireLine0, gJiminyMagicCardFireLine1, gJiminyMagicCardFireLine2, gJiminyMagicCardFireLine3,
    gJiminyAttackCardCrabclawLine9,
};

JiminyTextChar* gJiminyMagicCardBlizzardLines[5] = {
    gJiminyMagicCardBlizzardLine0, gJiminyMagicCardFireLine1, gJiminyMagicCardBlizzardLine2, gJiminyMagicCardBlizzardLine3,
    gJiminyAttackCardCrabclawLine9,
};

JiminyTextChar* gJiminyMagicCardThunderLines[5] = {
    gJiminyMagicCardThunderLine0, gJiminyMagicCardFireLine1, gJiminyMagicCardThunderLine2, gJiminyMagicCardThunderLine3,
    gJiminyAttackCardCrabclawLine9,
};

JiminyTextChar* gJiminyMagicCardCureLines[4] = {
    gJiminyMagicCardCureLine0, gJiminyMagicCardCureLine1, gJiminyMagicCardCureLine2, gJiminyAttackCardCrabclawLine9,
};

JiminyTextChar* gJiminyMagicCardGravityLines[5] = {
    gJiminyMagicCardGravityLine0, gJiminyMagicCardGravityLine1, gJiminyMagicCardGravityLine2, gJiminyMagicCardGravityLine3,
    gJiminyAttackCardCrabclawLine9,
};

JiminyTextChar* gJiminyMagicCardStopLines[5] = {
    gJiminyMagicCardStopLine0, gJiminyMagicCardStopLine1, gJiminyMagicCardStopLine2, gJiminyMagicCardStopLine3,
    gJiminyAttackCardCrabclawLine9,
};

JiminyTextChar* gJiminyMagicCardAeroLines[6] = {
    gJiminyMagicCardAeroLine0, gJiminyMagicCardAeroLine1, gJiminyMagicCardAeroLine2, gJiminyMagicCardAeroLine3,
    gJiminyMagicCardAeroLine4, gJiminyAttackCardCrabclawLine9,
};

JiminyTextChar* gJiminyMagicCardSimbaLines[5] = {
    gJiminyMagicCardSimbaLine0, gJiminyMagicCardSimbaLine1, gJiminyMagicCardSimbaLine2, gJiminyMagicCardSimbaLine3,
    gJiminyMagicCardSimbaLine4,
};

JiminyTextChar* gJiminyMagicCardGenieLines[4] = {
    gJiminyMagicCardGenieLine0, gJiminyMagicCardGenieLine1, gJiminyMagicCardGenieLine2, gJiminyMagicCardGenieLine3,
};

JiminyTextChar* gJiminyMagicCardBambiLines[4] = {
    gJiminyMagicCardBambiLine0, gJiminyMagicCardBambiLine1, gJiminyMagicCardBambiLine2, gJiminyMagicCardBambiLine3,
};

JiminyTextChar* gJiminyMagicCardDumboLines[4] = {
    gJiminyMagicCardDumboLine0, gJiminyMagicCardDumboLine1, gJiminyMagicCardBambiLine2, gJiminyMagicCardBambiLine3,
};

JiminyTextChar* gJiminyMagicCardTinkerBellLines[4] = {
    gJiminyMagicCardTinkerBellLine0, gJiminyMagicCardTinkerBellLine1, gJiminyMagicCardBambiLine2, gJiminyMagicCardBambiLine3,
};

JiminyTextChar* gJiminyMagicCardMushuLines[4] = {
    gJiminyMagicCardMushuLine0, gJiminyMagicCardDumboLine1, gJiminyMagicCardMushuLine2, gJiminyMagicCardMushuLine3,
};

JiminyTextChar* gJiminyMagicCardCloudLines[3] = {
    gJiminyMagicCardCloudLine0, gJiminyMagicCardCloudLine1, gJiminyMagicCardCloudLine2,
};

JiminyTextChar* gJiminyItemCardPotionLines[5] = {
    gJiminyItemCardPotionLine0, gJiminyItemCardPotionLine1, gJiminyItemCardPotionLine2, gJiminyItemCardPotionLine3,
    gJiminyItemCardPotionLine4,
};

JiminyTextChar* gJiminyItemCardHiPotionLines[5] = {
    gJiminyItemCardPotionLine0, gJiminyItemCardPotionLine1, gJiminyItemCardPotionLine2, gJiminyItemCardHiPotionLine3,
    gJiminyItemCardHiPotionLine4,
};

JiminyTextChar* gJiminyItemCardMegaPotionLines[6] = {
    gJiminyItemCardPotionLine0, gJiminyItemCardPotionLine1, gJiminyItemCardMegaPotionLine2, gJiminyItemCardMegaPotionLine3,
    gJiminyItemCardHiPotionLine3, gJiminyItemCardHiPotionLine4,
};

JiminyTextChar* gJiminyItemCardEtherLines[5] = {
    gJiminyItemCardEtherLine0, gJiminyItemCardEtherLine1, gJiminyItemCardPotionLine2, gJiminyItemCardPotionLine3,
    gJiminyItemCardPotionLine4,
};

JiminyTextChar* gJiminyItemCardMegaEtherLines[6] = {
    gJiminyItemCardEtherLine0, gJiminyItemCardEtherLine1, gJiminyItemCardMegaPotionLine2, gJiminyItemCardMegaPotionLine3,
    gJiminyItemCardHiPotionLine3, gJiminyItemCardHiPotionLine4,
};

JiminyTextChar* gJiminyItemCardElixirLines[4] = {
    gJiminyItemCardElixirLine0, gJiminyItemCardElixirLine1, gJiminyItemCardElixirLine2, gJiminyItemCardElixirLine3,
};

JiminyTextChar* gJiminyItemCardMegalixirLines[6] = {
    gJiminyItemCardElixirLine0, gJiminyItemCardElixirLine1, gJiminyItemCardElixirLine2, gJiminyItemCardElixirLine3,
    gJiminyItemCardMegalixirLine4, gJiminyItemCardMegalixirLine5,
};

JiminyTextChar* gJiminyFriendCardDonaldDuckLines[5] = {
    gJiminyFriendCardDonaldDuckLine0, gJiminyFriendCardDonaldDuckLine1, gJiminyFriendCardDonaldDuckLine2, gJiminyFriendCardDonaldDuckLine3,
    gJiminyFriendCardDonaldDuckLine4,
};

JiminyTextChar* gJiminyFriendCardGoofyLines[4] = {
    gJiminyFriendCardGoofyLine0, gJiminyAttackCardCrabclawLine9, gJiminyFriendCardGoofyLine2, gJiminyFriendCardDonaldDuckLine4,
};

JiminyTextChar* gJiminyFriendCardAladdinLines[4] = {
    gJiminyFriendCardAladdinLine0, gJiminyFriendCardAladdinLine1, gJiminyFriendCardGoofyLine2, gJiminyFriendCardDonaldDuckLine4,
};

JiminyTextChar* gJiminyFriendCardArielLines[4] = {
    gJiminyFriendCardArielLine0, gJiminyFriendCardArielLine1, gJiminyFriendCardGoofyLine2, gJiminyFriendCardDonaldDuckLine4,
};

JiminyTextChar* gJiminyFriendCardJackLines[5] = {
    gJiminyFriendCardDonaldDuckLine0, gJiminyFriendCardJackLine1, gJiminyFriendCardJackLine2, gJiminyFriendCardDonaldDuckLine3,
    gJiminyFriendCardDonaldDuckLine4,
};

JiminyTextChar* gJiminyFriendCardPeterPanLines[3] = {
    gJiminyFriendCardPeterPanLine0, gJiminyFriendCardGoofyLine2, gJiminyFriendCardDonaldDuckLine4,
};

JiminyTextChar* gJiminyFriendCardBeastLines[3] = {
    gJiminyFriendCardBeastLine0, gJiminyFriendCardGoofyLine2, gJiminyFriendCardDonaldDuckLine4,
};

JiminyTextChar* gJiminyEnemyCardShadowLines[5] = {
    gJiminyEnemyCardShadowLine0, gJiminyEnemyCardShadowLine1, gJiminyEnemyCardShadowLine2, gJiminyBlankLine,
    gJiminyEnemyCardShadowLine4,
};

JiminyTextChar* gJiminyEnemyCardRedNocturneLines[5] = {
    gJiminyEnemyCardRedNocturneLine0, gJiminyEnemyCardRedNocturneLine1, gJiminyMagicCardBambiLine3, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardBlueRhapsodyLines[5] = {
    gJiminyEnemyCardBlueRhapsodyLine0, gJiminyEnemyCardBlueRhapsodyLine1, gJiminyMagicCardBambiLine3, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardYellowOperaLines[5] = {
    gJiminyEnemyCardYellowOperaLine0, gJiminyEnemyCardYellowOperaLine1, gJiminyMagicCardBambiLine3, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardGreenRequiemLines[5] = {
    gJiminyEnemyCardGreenRequiemLine0, gJiminyEnemyCardGreenRequiemLine1, gJiminyEnemyCardGreenRequiemLine2, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardSeaNeonLines[5] = {
    gJiminyEnemyCardSeaNeonLine0, gJiminyEnemyCardShadowLine1, gJiminyEnemyCardSeaNeonLine2, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardWhiteMushroomLines[5] = {
    gJiminyEnemyCardWhiteMushroomLine0, gJiminyEnemyCardWhiteMushroomLine1, gJiminyEnemyCardWhiteMushroomLine2, gJiminyBlankLine,
    gJiminyEnemyCardWhiteMushroomLine4,
};

JiminyTextChar* gJiminyEnemyCardBlackFungusLines[5] = {
    gJiminyEnemyCardBlackFungusLine0, gJiminyEnemyCardBlackFungusLine1, gJiminyEnemyCardBlackFungusLine2, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardSoldierLines[5] = {
    gJiminyEnemyCardSoldierLine0, gJiminyEnemyCardSoldierLine1, gJiminyAttackCardCrabclawLine9, gJiminyBlankLine,
    gJiminyEnemyCardWhiteMushroomLine4,
};

JiminyTextChar* gJiminyEnemyCardPowerwildLines[8] = {
    gJiminyEnemyCardPowerwildLine0, gJiminyEnemyCardPowerwildLine1, gJiminyEnemyCardPowerwildLine2, gJiminyEnemyCardPowerwildLine3,
    gJiminyEnemyCardPowerwildLine4, gJiminyEnemyCardPowerwildLine5, gJiminyBlankLine, gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardBouncywildLines[5] = {
    gJiminyEnemyCardBouncywildLine0, gJiminyEnemyCardBouncywildLine1, gJiminyEnemyCardBouncywildLine2, gJiminyBlankLine,
    gJiminyEnemyCardBouncywildLine4,
};

JiminyTextChar* gJiminyEnemyCardAirSoldierLines[5] = {
    gJiminyEnemyCardAirSoldierLine0, gJiminyEnemyCardAirSoldierLine1, gJiminyEnemyCardAirSoldierLine2, gJiminyBlankLine,
    gJiminyEnemyCardWhiteMushroomLine4,
};

JiminyTextChar* gJiminyEnemyCardBanditLines[5] = {
    gJiminyEnemyCardBanditLine0, gJiminyEnemyCardBanditLine1, gJiminyEnemyCardBanditLine2, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardBarrelSpiderLines[5] = {
    gJiminyEnemyCardBarrelSpiderLine0, gJiminyEnemyCardBarrelSpiderLine1, gJiminyEnemyCardBarrelSpiderLine2, gJiminyBlankLine,
    gJiminyEnemyCardWhiteMushroomLine4,
};

JiminyTextChar* gJiminyEnemyCardSearchGhostLines[7] = {
    gJiminyEnemyCardSearchGhostLine0, gJiminyEnemyCardSearchGhostLine1, gJiminyEnemyCardSearchGhostLine2, gJiminyEnemyCardSearchGhostLine3,
    gJiminyEnemyCardSearchGhostLine4, gJiminyBlankLine, gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardScrewdiverLines[5] = {
    gJiminyEnemyCardScrewdiverLine0, gJiminyEnemyCardShadowLine1, gJiminyEnemyCardScrewdiverLine2, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardWightKnightLines[5] = {
    gJiminyEnemyCardWightKnightLine0, gJiminyEnemyCardWightKnightLine1, gJiminyEnemyCardWightKnightLine2, gJiminyBlankLine,
    gJiminyEnemyCardWhiteMushroomLine4,
};

JiminyTextChar* gJiminyEnemyCardGargoyleLines[5] = {
    gJiminyEnemyCardGargoyleLine0, gJiminyEnemyCardGargoyleLine1, gJiminyEnemyCardGargoyleLine2, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardPirateLines[5] = {
    gJiminyEnemyCardPirateLine0, gJiminyEnemyCardShadowLine1, gJiminyEnemyCardPirateLine2, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardAirPirateLines[5] = {
    gJiminyEnemyCardAirPirateLine0, gJiminyEnemyCardAirPirateLine1, gJiminyEnemyCardAirPirateLine2, gJiminyBlankLine,
    gJiminyEnemyCardWhiteMushroomLine4,
};

JiminyTextChar* gJiminyEnemyCardDarkballLines[5] = {
    gJiminyEnemyCardDarkballLine0, gJiminyEnemyCardDarkballLine1, gJiminyEnemyCardDarkballLine2, gJiminyBlankLine,
    gJiminyEnemyCardWhiteMushroomLine4,
};

JiminyTextChar* gJiminyEnemyCardWyvernLines[5] = {
    gJiminyEnemyCardWyvernLine0, gJiminyEnemyCardWyvernLine1, gJiminyEnemyCardWyvernLine2, gJiminyBlankLine,
    gJiminyEnemyCardWhiteMushroomLine4,
};

JiminyTextChar* gJiminyEnemyCardWizardLines[6] = {
    gJiminyEnemyCardWizardLine0, gJiminyEnemyCardWizardLine1, gJiminyEnemyCardWizardLine2, gJiminyEnemyCardWizardLine3,
    gJiminyBlankLine, gJiminyEnemyCardWizardLine5,
};

JiminyTextChar* gJiminyEnemyCardNeoshadowLines[5] = {
    gJiminyEnemyCardNeoshadowLine0, gJiminyEnemyCardNeoshadowLine1, gJiminyEnemyCardNeoshadowLine2, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardLargeBodyLines[6] = {
    gJiminyEnemyCardLargeBodyLine0, gJiminyEnemyCardLargeBodyLine1, gJiminyEnemyCardLargeBodyLine2, gJiminyEnemyCardLargeBodyLine3,
    gJiminyBlankLine, gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardFatBanditLines[6] = {
    gJiminyEnemyCardFatBanditLine0, gJiminyEnemyCardFatBanditLine1, gJiminyEnemyCardFatBanditLine2, gJiminyEnemyCardFatBanditLine3,
    gJiminyBlankLine, gJiminyEnemyCardShadowLine4,
};

JiminyTextChar* gJiminyEnemyCardAquatankLines[5] = {
    gJiminyEnemyCardAquatankLine0, gJiminyEnemyCardAquatankLine1, gJiminyEnemyCardAquatankLine2, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardDefenderLines[6] = {
    gJiminyEnemyCardDefenderLine0, gJiminyEnemyCardDefenderLine1, gJiminyEnemyCardDefenderLine2, gJiminyEnemyCardDefenderLine3,
    gJiminyBlankLine, gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardTornadoStepLines[6] = {
    gJiminyEnemyCardTornadoStepLine0, gJiminyEnemyCardTornadoStepLine1, gJiminyEnemyCardTornadoStepLine2, gJiminyEnemyCardFatBanditLine3,
    gJiminyBlankLine, gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardCrescendoLines[6] = {
    gJiminyEnemyCardCrescendoLine0, gJiminyEnemyCardCrescendoLine1, gJiminyEnemyCardCrescendoLine2, gJiminyEnemyCardWizardLine3,
    gJiminyBlankLine, gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardCreeperPlantLines[5] = {
    gJiminyEnemyCardCreeperPlantLine0, gJiminyEnemyCardCreeperPlantLine1, gJiminyEnemyCardCreeperPlantLine2, gJiminyBlankLine,
    gJiminyEnemyCardRedNocturneLine4,
};

JiminyTextChar* gJiminyEnemyCardGuardArmorLines[6] = {
    gJiminyEnemyCardGuardArmorLine0, gJiminyEnemyCardGuardArmorLine1, gJiminyEnemyCardGuardArmorLine2, gJiminyAttackCardCrabclawLine9,
    gJiminyBlankLine, gJiminyEnemyCardGuardArmorLine5,
};

JiminyTextChar* gJiminyEnemyCardCardSoldierLines[5] = {
    gJiminyEnemyCardCardSoldierLine0, gJiminyEnemyCardSearchGhostLine1, gJiminyEnemyCardCardSoldierLine2, gJiminyBlankLine,
    gJiminyEnemyCardGuardArmorLine5,
};

JiminyTextChar* gJiminyEnemyCardHadesLines[8] = {
    gJiminyEnemyCardHadesLine0, gJiminyEnemyCardHadesLine1, gJiminyEnemyCardHadesLine2, gJiminyEnemyCardHadesLine3,
    gJiminyBlankLine, gJiminyEnemyCardGuardArmorLine5, gJiminyEnemyCardHadesLine6, gJiminyEnemyCardHadesLine7,
};

JiminyTextChar* gJiminyEnemyCardTrickmasterLines[7] = {
    gJiminyEnemyCardTrickmasterLine0, gJiminyEnemyCardTrickmasterLine1, gJiminyEnemyCardTrickmasterLine2, gJiminyEnemyCardTrickmasterLine3,
    gJiminyEnemyCardTrickmasterLine4, gJiminyBlankLine, gJiminyEnemyCardTrickmasterLine6,
};

JiminyTextChar* gJiminyEnemyCardJafarLines[5] = {
    gJiminyEnemyCardJafarLine0, gJiminyEnemyCardJafarLine1, gJiminyEnemyCardJafarLine2, gJiminyBlankLine,
    gJiminyEnemyCardJafarLine4,
};

JiminyTextChar* gJiminyEnemyCardUrsulaLines[7] = {
    gJiminyEnemyCardUrsulaLine0, gJiminyEnemyCardUrsulaLine1, gJiminyEnemyCardUrsulaLine2, gJiminyEnemyCardUrsulaLine3,
    gJiminyEnemyCardUrsulaLine4, gJiminyBlankLine, gJiminyEnemyCardUrsulaLine6,
};

JiminyTextChar* gJiminyEnemyCardOogieBoogieLines[6] = {
    gJiminyEnemyCardOogieBoogieLine0, gJiminyEnemyCardOogieBoogieLine1, gJiminyEnemyCardOogieBoogieLine2, gJiminyEnemyCardOogieBoogieLine3,
    gJiminyBlankLine, gJiminyEnemyCardOogieBoogieLine5,
};

JiminyTextChar* gJiminyEnemyCardParasiteCageLines[7] = {
    gJiminyEnemyCardParasiteCageLine0, gJiminyEnemyCardParasiteCageLine1, gJiminyEnemyCardParasiteCageLine2, gJiminyEnemyCardParasiteCageLine3,
    gJiminyEnemyCardParasiteCageLine4, gJiminyBlankLine, gJiminyEnemyCardParasiteCageLine6,
};

JiminyTextChar* gJiminyEnemyCardHookLines[8] = {
    gJiminyEnemyCardHookLine0, gJiminyEnemyCardHookLine1, gJiminyEnemyCardHookLine2, gJiminyEnemyCardHookLine3,
    gJiminyBlankLine, gJiminyEnemyCardHookLine5, gJiminyEnemyCardHookLine6, gJiminyEnemyCardHookLine7,
};

JiminyTextChar* gJiminyEnemyCardDragonMaleficentLines[6] = {
    gJiminyEnemyCardDragonMaleficentLine0, gJiminyEnemyCardDragonMaleficentLine1, gJiminyEnemyCardDragonMaleficentLine2, gJiminyEnemyCardDragonMaleficentLine3,
    gJiminyBlankLine, gJiminyEnemyCardGuardArmorLine5,
};

JiminyTextChar* gJiminyEnemyCardDarksideLines[7] = {
    gJiminyEnemyCardDarksideLine0, gJiminyEnemyCardDarksideLine1, gJiminyEnemyCardDarksideLine2, gJiminyEnemyCardParasiteCageLine3,
    gJiminyEnemyCardParasiteCageLine4, gJiminyBlankLine, gJiminyEnemyCardParasiteCageLine6,
};

JiminyTextChar* gJiminyEnemyCardLarxeneLines[6] = {
    gJiminyEnemyCardLarxeneLine0, gJiminyEnemyCardLarxeneLine1, gJiminyBlankLine, gJiminyEnemyCardLarxeneLine3,
    gJiminyEnemyCardLarxeneLine4, gJiminyEnemyCardLarxeneLine5,
};

JiminyTextChar* gJiminyEnemyCardRikuLines[9] = {
    gJiminyEnemyCardRikuLine0, gJiminyEnemyCardRikuLine1, gJiminyEnemyCardRikuLine2, gJiminyEnemyCardRikuLine3,
    gJiminyBlankLine, gJiminyEnemyCardRikuLine5, gJiminyEnemyCardHadesLine6, gJiminyEnemyCardRikuLine7,
    gJiminyEnemyCardHookLine6,
};

JiminyTextChar* gJiminyEnemyCardAxelLines[7] = {
    gJiminyEnemyCardAxelLine0, gJiminyEnemyCardAxelLine1, gJiminyEnemyCardAxelLine2, gJiminyBlankLine,
    gJiminyEnemyCardAxelLine4, gJiminyEnemyCardAxelLine5, gJiminyEnemyCardHadesLine7,
};

JiminyTextChar* gJiminyEnemyCardVexenLines[8] = {
    gJiminyEnemyCardVexenLine0, gJiminyEnemyCardVexenLine1, gJiminyEnemyCardVexenLine2, gJiminyEnemyCardVexenLine3,
    gJiminyBlankLine, gJiminyEnemyCardVexenLine5, gJiminyEnemyCardVexenLine6, gJiminyEnemyCardHookLine7,
};

JiminyTextChar* gJiminyEnemyCardLexaeusLines[11] = {
    gJiminyEnemyCardLexaeusLine0, gJiminyEnemyCardLexaeusLine1, gJiminyEnemyCardLexaeusLine2, gJiminyEnemyCardLexaeusLine3,
    gJiminyEnemyCardLexaeusLine4, gJiminyAttackCardCrabclawLine9, gJiminyBlankLine, gJiminyEnemyCardLexaeusLine7,
    gJiminyEnemyCardVexenLine6, gJiminyEnemyCardLexaeusLine9, gJiminyEnemyCardLarxeneLine5,
};

JiminyTextChar* gJiminyEnemyCardAnsemLines[9] = {
    gJiminyEnemyCardAnsemLine0, gJiminyEnemyCardAnsemLine1, gJiminyEnemyCardAnsemLine2, gJiminyEnemyCardFatBanditLine3,
    gJiminyBlankLine, gJiminyEnemyCardAnsemLine5, gJiminyEnemyCardHadesLine6, gJiminyEnemyCardRikuLine7,
    gJiminyEnemyCardHookLine6,
};

JiminyTextChar* gJiminyEnemyCardMarluxiaLines[13] = {
    gJiminyEnemyCardMarluxiaLine0, gJiminyEnemyCardRikuLine1, gJiminyEnemyCardMarluxiaLine2, gJiminyEnemyCardMarluxiaLine3,
    gJiminyEnemyCardMarluxiaLine4, gJiminyEnemyCardMarluxiaLine5, gJiminyBlankLine, gJiminyEnemyCardMarluxiaLine7,
    gJiminyEnemyCardHadesLine6, gJiminyEnemyCardRikuLine7, gJiminyEnemyCardHookLine6, gJiminyEnemyCardMarluxiaLine11,
    gJiminyEnemyCardMarluxiaLine12,
};

JiminyTextChar* gJiminyRikuCardSoulEaterLines[3] = {
    gJiminyRikuCardSoulEaterLine0, gJiminyRikuCardSoulEaterLine1, gJiminyRikuCardSoulEaterLine2,
};

JiminyTextChar* gJiminyRikuCardKingLines[4] = {
    gJiminyRikuCardKingLine0, gJiminyRikuCardKingLine1, gJiminyRikuCardKingLine2, gJiminyRikuCardKingLine3,
};

JiminyTextChar* gJiminyMapCardTeemingDarknessLines[5] = {
    gJiminyMapCardTeemingDarknessLine0, gJiminyMapCardTeemingDarknessLine1, gJiminyMapCardTeemingDarknessLine2, gJiminyMapCardTeemingDarknessLine3,
    gJiminyEnemyCardFatBanditLine3,
};

JiminyTextChar* gJiminyMapCardTranquilDarknessLines[2] = {
    gJiminyMapCardTranquilDarknessLine0, gJiminyMapCardTranquilDarknessLine1,
};

JiminyTextChar* gJiminyMapCardGuardedTroveLines[2] = {
    gJiminyMapCardGuardedTroveLine0, gJiminyMapCardGuardedTroveLine1,
};

JiminyTextChar* gJiminyMapCardLoomingDarknessLines[5] = {
    gJiminyMapCardLoomingDarknessLine0, gJiminyMapCardLoomingDarknessLine1, gJiminyMapCardTeemingDarknessLine2, gJiminyMapCardTeemingDarknessLine3,
    gJiminyEnemyCardFatBanditLine3,
};

JiminyTextChar* gJiminyMapCardSleepingDarknessLines[3] = {
    gJiminyMapCardSleepingDarknessLine0, gJiminyMapCardSleepingDarknessLine1, gJiminyMapCardSleepingDarknessLine2,
};

JiminyTextChar* gJiminyMapCardMomentsReprieveLines[3] = {
    gJiminyMapCardMomentsReprieveLine0, gJiminyMapCardMomentsReprieveLine1, gJiminyMapCardMomentsReprieveLine2,
};

JiminyTextChar* gJiminyMapCardFeebleDarknessLines[2] = {
    gJiminyMapCardFeebleDarknessLine0, gJiminyMapCardFeebleDarknessLine1,
};

JiminyTextChar* gJiminyMapCardAlmightyDarknessLines[5] = {
    gJiminyMapCardAlmightyDarknessLine0, gJiminyMapCardFeebleDarknessLine1, gJiminyMapCardTeemingDarknessLine2, gJiminyMapCardTeemingDarknessLine3,
    gJiminyEnemyCardFatBanditLine3,
};

JiminyTextChar* gJiminyMapCardCalmBountyLines[1] = {
    gJiminyMapCardCalmBountyLine0,
};

JiminyTextChar* gJiminyMapCardFalseBountyLines[4] = {
    gJiminyMapCardFalseBountyLine0, gJiminyMapCardFalseBountyLine1, gJiminyMapCardFalseBountyLine2, gJiminyMapCardFalseBountyLine3,
};

JiminyTextChar* gJiminyMapCardMoogleRoomLines[2] = {
    gJiminyMapCardMoogleRoomLine0, gJiminyMapCardMoogleRoomLine1,
};

JiminyTextChar* gJiminyMapCardSorcerousWakingLines[2] = {
    gJiminyMapCardSorcerousWakingLine0, gJiminyMapCardSorcerousWakingLine1,
};

JiminyTextChar* gJiminyMapCardMartialWakingLines[2] = {
    gJiminyMapCardMartialWakingLine0, gJiminyMapCardSorcerousWakingLine1,
};

JiminyTextChar* gJiminyMapCardAlchemicWakingLines[2] = {
    gJiminyMapCardAlchemicWakingLine0, gJiminyMapCardSorcerousWakingLine1,
};

JiminyTextChar* gJiminyMapCardMeetingGroundLines[3] = {
    gJiminyMapCardMeetingGroundLine0, gJiminyMapCardMeetingGroundLine1, gJiminyMapCardMeetingGroundLine2,
};

JiminyTextChar* gJiminyMapCardMinglingWorldsLines[2] = {
    gJiminyMapCardMinglingWorldsLine0, gJiminyMapCardMinglingWorldsLine1,
};

JiminyTextChar* gJiminyMapCardStrongInitiativeLines[4] = {
    gJiminyMapCardStrongInitiativeLine0, gJiminyMapCardStrongInitiativeLine1, gJiminyMapCardStrongInitiativeLine2, gJiminyMapCardStrongInitiativeLine3,
};

JiminyTextChar* gJiminyMapCardLastingDazeLines[4] = {
    gJiminyMapCardStrongInitiativeLine0, gJiminyMapCardLastingDazeLine1, gJiminyMapCardLastingDazeLine2, gJiminyMapCardLastingDazeLine3,
};

JiminyTextChar* gJiminyMapCardStagnantSpaceLines[3] = {
    gJiminyMapCardStagnantSpaceLine0, gJiminyMapCardStagnantSpaceLine1, gJiminyMapCardStagnantSpaceLine2,
};

JiminyTextChar* gJiminyMapCardPremiumRoomLines[3] = {
    gJiminyMapCardPremiumRoomLine0, gJiminyMapCardPremiumRoomLine1, gJiminyMapCardPremiumRoomLine2,
};

JiminyTextChar* gJiminyMapCardWhiteRoomLines[4] = {
    gJiminyMapCardWhiteRoomLine0, gJiminyMapCardWhiteRoomLine1, gJiminyMapCardWhiteRoomLine2, gJiminyMapCardWhiteRoomLine3,
};

JiminyTextChar* gJiminyMapCardBlackRoomLines[4] = {
    gJiminyMapCardBlackRoomLine0, gJiminyMapCardBlackRoomLine1, gJiminyMapCardBlackRoomLine2, gJiminyMapCardBlackRoomLine3,
};

JiminyTextChar* gJiminyMapCardKeyOfBeginningsLines[2] = {
    gJiminyMapCardKeyOfBeginningsLine0, gJiminyMapCardKeyOfBeginningsLine1,
};

JiminyTextChar* gJiminyMapCardKeyOfGuidanceLines[2] = {
    gJiminyMapCardKeyOfBeginningsLine0, gJiminyMapCardKeyOfBeginningsLine1,
};

JiminyTextChar* gJiminyMapCardKeyToTruthLines[2] = {
    gJiminyMapCardKeyOfBeginningsLine0, gJiminyMapCardKeyOfBeginningsLine1,
};

JiminyTextChar* gJiminyMapCardKeyToRewardsLines[2] = {
    gJiminyMapCardKeyToRewardsLine0, gJiminyMapCardFalseBountyLine1,
};

JiminyTextChar* gJiminyPremiumCardsLines[13] = {
    gJiminyPremiumCardsLine0, gJiminyPremiumCardsLine1, gJiminyPremiumCardsLine2, gJiminyPremiumCardsLine3,
    gJiminyPremiumCardsLine4, gJiminyPremiumCardsLine5, gJiminyPremiumCardsLine6, gJiminyPremiumCardsLine7,
    gJiminyPremiumCardsLine8, gJiminyPremiumCardsLine9, gJiminyPremiumCardsLine10, gJiminyPremiumCardsLine11,
    gJiminyPremiumCardsLine12,
};

JiminyTextChar* gJiminyCharacterSoraLines[8] = {
    gJiminyCharacterSoraLine0, gJiminyCharacterSoraLine1, gJiminyCharacterSoraLine2, gJiminyCharacterSoraLine3,
    gJiminyCharacterSoraLine4, gJiminyCharacterSoraLine5, gJiminyCharacterSoraLine6, gJiminyCharacterSoraLine7,
};

JiminyTextChar* gJiminyCharacterDonaldDuckLines[10] = {
    gJiminyCharacterDonaldDuckLine0, gJiminyCharacterDonaldDuckLine1, gJiminyCharacterDonaldDuckLine2, gJiminyCharacterDonaldDuckLine3,
    gJiminyCharacterDonaldDuckLine4, gJiminyCharacterDonaldDuckLine5, gJiminyCharacterDonaldDuckLine6, gJiminyCharacterDonaldDuckLine7,
    gJiminyCharacterDonaldDuckLine8, gJiminyAttackCardCrabclawLine9,
};

JiminyTextChar* gJiminyCharacterGoofyLines[9] = {
    gJiminyCharacterDonaldDuckLine0, gJiminyCharacterDonaldDuckLine1, gJiminyCharacterGoofyLine2, gJiminyCharacterGoofyLine3,
    gJiminyCharacterGoofyLine4, gJiminyCharacterGoofyLine5, gJiminyCharacterGoofyLine6, gJiminyCharacterGoofyLine7,
    gJiminyCharacterGoofyLine8,
};

JiminyTextChar* gJiminyCharacterJiminyCricketLines[6] = {
    gJiminyCharacterJiminyCricketLine0, gJiminyCharacterJiminyCricketLine1, gJiminyCharacterJiminyCricketLine2, gJiminyCharacterJiminyCricketLine3,
    gJiminyCharacterJiminyCricketLine4, gJiminyCharacterJiminyCricketLine5,
};

JiminyTextChar* gJiminyCharacterRikuLines[10] = {
    gJiminyCharacterRikuLine0, gJiminyCharacterRikuLine1, gJiminyCharacterRikuLine2, gJiminyCharacterRikuLine3,
    gJiminyCharacterRikuLine4, gJiminyCharacterRikuLine5, gJiminyCharacterRikuLine6, gJiminyCharacterRikuLine7,
    gJiminyCharacterRikuLine8, gJiminyCharacterRikuLine9,
};

JiminyTextChar* gJiminyCharacterKairiLines[10] = {
    gJiminyCharacterRikuLine0, gJiminyCharacterKairiLine1, gJiminyCharacterKairiLine2, gJiminyCharacterKairiLine3,
    gJiminyCharacterKairiLine4, gJiminyCharacterKairiLine5, gJiminyCharacterKairiLine6, gJiminyCharacterKairiLine7,
    gJiminyCharacterKairiLine8, gJiminyCharacterKairiLine9,
};

JiminyTextChar* gJiminyCharacterSimbaLines[7] = {
    gJiminyCharacterSimbaLine0, gJiminyCharacterSimbaLine1, gJiminyCharacterSimbaLine2, gJiminyCharacterSimbaLine3,
    gJiminyCharacterSimbaLine4, gJiminyCharacterSimbaLine5, gJiminyCharacterSimbaLine6,
};

JiminyTextChar* gJiminyCharacterDumboLines[8] = {
    gJiminyCharacterDumboLine0, gJiminyCharacterDumboLine1, gJiminyCharacterDumboLine2, gJiminyCharacterDumboLine3,
    gJiminyCharacterDumboLine4, gJiminyCharacterSimbaLine4, gJiminyCharacterSimbaLine5, gJiminyCharacterSimbaLine6,
};

JiminyTextChar* gJiminyCharacterBambiLines[5] = {
    gJiminyCharacterBambiLine0, gJiminyCharacterBambiLine1, gJiminyCharacterSimbaLine4, gJiminyCharacterSimbaLine5,
    gJiminyCharacterSimbaLine6,
};

JiminyTextChar* gJiminyCharacterMushuLines[6] = {
    gJiminyCharacterMushuLine0, gJiminyCharacterMushuLine1, gJiminyCharacterMushuLine2, gJiminyCharacterSimbaLine4,
    gJiminyCharacterSimbaLine5, gJiminyCharacterSimbaLine6,
};

JiminyTextChar* gJiminyCharacterMooglesLines[5] = {
    gJiminyCharacterMooglesLine0, gJiminyCharacterMooglesLine1, gJiminyCharacterMooglesLine2, gJiminyCharacterMooglesLine3,
    gJiminyCharacterMooglesLine4,
};

JiminyTextChar* gJiminyCharacterLeonLines[9] = {
    gJiminyCharacterLeonLine0, gJiminyCharacterLeonLine1, gJiminyCharacterLeonLine2, gJiminyCharacterLeonLine3,
    gJiminyCharacterLeonLine4, gJiminyCharacterLeonLine5, gJiminyCharacterLeonLine6, gJiminyCharacterLeonLine7,
    gJiminyCharacterLeonLine8,
};

JiminyTextChar* gJiminyCharacterYuffieLines[6] = {
    gJiminyCharacterYuffieLine0, gJiminyCharacterYuffieLine1, gJiminyCharacterYuffieLine2, gJiminyCharacterYuffieLine3,
    gJiminyCharacterYuffieLine4, gJiminyCharacterYuffieLine5,
};

JiminyTextChar* gJiminyCharacterAerithLines[8] = {
    gJiminyCharacterAerithLine0, gJiminyCharacterAerithLine1, gJiminyCharacterAerithLine2, gJiminyCharacterAerithLine3,
    gJiminyCharacterAerithLine4, gJiminyCharacterAerithLine5, gJiminyCharacterAerithLine6, gJiminyCharacterAerithLine7,
};

JiminyTextChar* gJiminyCharacterCidLines[5] = {
    gJiminyCharacterCidLine0, gJiminyCharacterCidLine1, gJiminyCharacterCidLine2, gJiminyCharacterCidLine3,
    gJiminyCharacterCidLine4,
};

JiminyTextChar* gJiminyCharacterCloudLines[8] = {
    gJiminyCharacterCloudLine0, gJiminyCharacterCloudLine1, gJiminyCharacterCloudLine2, gJiminyCharacterCloudLine3,
    gJiminyCharacterCloudLine4, gJiminyCharacterCloudLine5, gJiminyCharacterCloudLine6, gJiminyCharacterCloudLine7,
};

JiminyTextChar* gJiminyCharacterTidusLines[5] = {
    gJiminyCharacterTidusLine0, gJiminyCharacterTidusLine1, gJiminyCharacterTidusLine2, gJiminyCharacterTidusLine3,
    gJiminyAttackCardCrabclawLine9,
};

JiminyTextChar* gJiminyCharacterWakkaLines[5] = {
    gJiminyCharacterTidusLine0, gJiminyCharacterWakkaLine1, gJiminyCharacterWakkaLine2, gJiminyCharacterWakkaLine3,
    gJiminyCharacterWakkaLine4,
};

JiminyTextChar* gJiminyCharacterSelphieLines[5] = {
    gJiminyCharacterTidusLine0, gJiminyCharacterSelphieLine1, gJiminyCharacterSelphieLine2, gJiminyCharacterSelphieLine3,
    gJiminyCharacterSelphieLine4,
};

JiminyTextChar* gJiminyCharacterNamineLines[11] = {
    gJiminyCharacterNamineLine0, gJiminyCharacterNamineLine1, gJiminyCharacterNamineLine2, gJiminyCharacterNamineLine3,
    gJiminyCharacterNamineLine4, gJiminyCharacterNamineLine5, gJiminyCharacterNamineLine6, gJiminyCharacterNamineLine7,
    gJiminyCharacterNamineLine8, gJiminyCharacterNamineLine9, gJiminyCharacterNamineLine10,
};

JiminyTextChar* gJiminyCharacterRikuReplicaLines[7] = {
    gJiminyCharacterRikuReplicaLine0, gJiminyCharacterRikuReplicaLine1, gJiminyCharacterRikuReplicaLine2, gJiminyCharacterRikuReplicaLine3,
    gJiminyCharacterRikuReplicaLine4, gJiminyCharacterRikuReplicaLine5, gJiminyCharacterMooglesLine4,
};

JiminyTextChar* gJiminyCharacterAxelLines[6] = {
    gJiminyCharacterAxelLine0, gJiminyCharacterAxelLine1, gJiminyCharacterAxelLine2, gJiminyCharacterAxelLine3,
    gJiminyCharacterAxelLine4, gJiminyCharacterAxelLine5,
};

JiminyTextChar* gJiminyCharacterLarxeneLines[7] = {
    gJiminyCharacterLarxeneLine0, gJiminyCharacterLarxeneLine1, gJiminyCharacterLarxeneLine2, gJiminyCharacterLarxeneLine3,
    gJiminyCharacterLarxeneLine4, gJiminyCharacterLarxeneLine5, gJiminyCharacterLarxeneLine6,
};

JiminyTextChar* gJiminyCharacterVexenLines[6] = {
    gJiminyCharacterVexenLine0, gJiminyCharacterVexenLine1, gJiminyCharacterVexenLine2, gJiminyCharacterVexenLine3,
    gJiminyCharacterVexenLine4, gJiminyCharacterVexenLine5,
};

JiminyTextChar* gJiminyCharacterMarluxiaLines[6] = {
    gJiminyCharacterMarluxiaLine0, gJiminyCharacterMarluxiaLine1, gJiminyCharacterMarluxiaLine2, gJiminyCharacterMarluxiaLine3,
    gJiminyCharacterMarluxiaLine4, gJiminyCharacterMarluxiaLine5,
};

JiminyTextChar* gJiminyCharacterAladdinLines[11] = {
    gJiminyCharacterAladdinLine0, gJiminyCharacterAladdinLine1, gJiminyCharacterAladdinLine2, gJiminyCharacterAladdinLine3,
    gJiminyCharacterAladdinLine4, gJiminyCharacterAladdinLine5, gJiminyCharacterAladdinLine6, gJiminyCharacterAladdinLine7,
    gJiminyCharacterAladdinLine8, gJiminyCharacterAladdinLine9, gJiminyCharacterAladdinLine10,
};

JiminyTextChar* gJiminyCharacterGenieLines[8] = {
    gJiminyCharacterGenieLine0, gJiminyCharacterGenieLine1, gJiminyCharacterGenieLine2, gJiminyCharacterGenieLine3,
    gJiminyCharacterGenieLine4, gJiminyCharacterGenieLine5, gJiminyCharacterGenieLine6, gJiminyCharacterGenieLine7,
};

JiminyTextChar* gJiminyCharacterJasmineLines[5] = {
    gJiminyCharacterJasmineLine0, gJiminyCharacterJasmineLine1, gJiminyCharacterJasmineLine2, gJiminyCharacterJasmineLine3,
    gJiminyCharacterJasmineLine4,
};

JiminyTextChar* gJiminyCharacterIagoLines[5] = {
    gJiminyCharacterIagoLine0, gJiminyCharacterIagoLine1, gJiminyCharacterIagoLine2, gJiminyCharacterIagoLine3,
    gJiminyCharacterIagoLine4,
};

JiminyTextChar* gJiminyCharacterJafarLines[6] = {
    gJiminyCharacterJafarLine0, gJiminyCharacterJafarLine1, gJiminyCharacterJafarLine2, gJiminyCharacterJafarLine3,
    gJiminyCharacterJafarLine4, gJiminyCharacterJafarLine5,
};

JiminyTextChar* gJiminyCharacterJafarGenieLines[6] = {
    gJiminyCharacterJafarLine2, gJiminyCharacterJafarGenieLine1, gJiminyCharacterJafarGenieLine2, gJiminyCharacterJafarGenieLine3,
    gJiminyCharacterJafarGenieLine4, gJiminyCharacterJafarGenieLine5,
};

JiminyTextChar* gJiminyCharacterJackLines[6] = {
    gJiminyCharacterJackLine0, gJiminyCharacterJackLine1, gJiminyCharacterJackLine2, gJiminyCharacterJackLine3,
    gJiminyCharacterJackLine4, gJiminyCharacterJackLine5,
};

JiminyTextChar* gJiminyCharacterSallyLines[6] = {
    gJiminyCharacterSallyLine0, gJiminyCharacterSallyLine1, gJiminyCharacterSallyLine2, gJiminyCharacterSallyLine3,
    gJiminyCharacterSallyLine4, gJiminyCharacterSallyLine5,
};

JiminyTextChar* gJiminyCharacterDrFinkelsteinLines[8] = {
    gJiminyCharacterDrFinkelsteinLine0, gJiminyCharacterDrFinkelsteinLine1, gJiminyCharacterDrFinkelsteinLine2, gJiminyCharacterDrFinkelsteinLine3,
    gJiminyCharacterDrFinkelsteinLine4, gJiminyCharacterDrFinkelsteinLine5, gJiminyCharacterDrFinkelsteinLine6, gJiminyCharacterDrFinkelsteinLine7,
};

JiminyTextChar* gJiminyCharacterOogieBoogieLines[7] = {
    gJiminyCharacterOogieBoogieLine0, gJiminyCharacterOogieBoogieLine1, gJiminyCharacterOogieBoogieLine2, gJiminyCharacterOogieBoogieLine3,
    gJiminyCharacterOogieBoogieLine4, gJiminyCharacterOogieBoogieLine5, gJiminyCharacterOogieBoogieLine6,
};

JiminyTextChar* gJiminyCharacterPinocchioLines[10] = {
    gJiminyCharacterPinocchioLine0, gJiminyCharacterPinocchioLine1, gJiminyCharacterPinocchioLine2, gJiminyCharacterPinocchioLine3,
    gJiminyCharacterPinocchioLine4, gJiminyCharacterPinocchioLine5, gJiminyCharacterPinocchioLine6, gJiminyCharacterPinocchioLine7,
    gJiminyCharacterPinocchioLine8, gJiminyCharacterPinocchioLine9,
};

JiminyTextChar* gJiminyCharacterGeppettoLines[10] = {
    gJiminyCharacterGeppettoLine0, gJiminyCharacterGeppettoLine1, gJiminyCharacterAxelLine1, gJiminyCharacterGeppettoLine3,
    gJiminyCharacterGeppettoLine4, gJiminyCharacterGeppettoLine5, gJiminyCharacterGeppettoLine6, gJiminyCharacterGeppettoLine7,
    gJiminyCharacterGeppettoLine8, gJiminyCharacterGeppettoLine9,
};

JiminyTextChar* gJiminyCharacterHerculesLines[7] = {
    gJiminyCharacterHerculesLine0, gJiminyCharacterHerculesLine1, gJiminyCharacterHerculesLine2, gJiminyCharacterHerculesLine3,
    gJiminyCharacterHerculesLine4, gJiminyCharacterHerculesLine5, gJiminyCharacterHerculesLine6,
};

JiminyTextChar* gJiminyCharacterPhiloctetesLines[6] = {
    gJiminyCharacterPhiloctetesLine0, gJiminyCharacterPhiloctetesLine1, gJiminyCharacterPhiloctetesLine2, gJiminyCharacterPhiloctetesLine3,
    gJiminyCharacterPhiloctetesLine4, gJiminyCharacterPhiloctetesLine5,
};

JiminyTextChar* gJiminyCharacterHadesLines[7] = {
    gJiminyCharacterHadesLine0, gJiminyCharacterHadesLine1, gJiminyCharacterHadesLine2, gJiminyCharacterHadesLine3,
    gJiminyCharacterHadesLine4, gJiminyCharacterHadesLine5, gJiminyCharacterHadesLine6,
};

JiminyTextChar* gJiminyCharacterAliceLines[8] = {
    gJiminyCharacterAliceLine0, gJiminyCharacterAliceLine1, gJiminyCharacterAliceLine2, gJiminyCharacterAliceLine3,
    gJiminyCharacterAliceLine4, gJiminyCharacterAliceLine5, gJiminyCharacterAliceLine6, gJiminyStoryNeverLandLine21,
};

JiminyTextChar* gJiminyCharacterQueenOfHeartsLines[6] = {
    gJiminyCharacterQueenOfHeartsLine0, gJiminyCharacterQueenOfHeartsLine1, gJiminyCharacterQueenOfHeartsLine2, gJiminyCharacterQueenOfHeartsLine3,
    gJiminyCharacterQueenOfHeartsLine4, gJiminyCharacterQueenOfHeartsLine5,
};

JiminyTextChar* gJiminyCharacterWhiteRabbitLines[4] = {
    gJiminyCharacterWhiteRabbitLine0, gJiminyCharacterWhiteRabbitLine1, gJiminyCharacterWhiteRabbitLine2, gJiminyCharacterWhiteRabbitLine3,
};

JiminyTextChar* gJiminyCharacterCardOfHeartsLines[4] = {
    gJiminyCharacterCardOfHeartsLine0, gJiminyCharacterCardOfHeartsLine1, gJiminyCharacterCardOfHeartsLine2, gJiminyCharacterCardOfHeartsLine3,
};

JiminyTextChar* gJiminyCharacterCardOfSpadesLines[4] = {
    gJiminyCharacterCardOfHeartsLine0, gJiminyCharacterCardOfHeartsLine1, gJiminyCharacterCardOfHeartsLine2, gJiminyCharacterCardOfHeartsLine3,
};

JiminyTextChar* gJiminyCharacterCheshireCatLines[6] = {
    gJiminyCharacterCheshireCatLine0, gJiminyCharacterCheshireCatLine1, gJiminyCharacterCheshireCatLine2, gJiminyCharacterCheshireCatLine3,
    gJiminyCharacterCheshireCatLine4, gJiminyCharacterCheshireCatLine5,
};

JiminyTextChar* gJiminyCharacterArielLines[12] = {
    gJiminyCharacterArielLine0, gJiminyCharacterArielLine1, gJiminyCharacterArielLine2, gJiminyCharacterArielLine3,
    gJiminyCharacterArielLine4, gJiminyCharacterArielLine5, gJiminyCharacterArielLine6, gJiminyCharacterGeppettoLine9,
    gJiminyCharacterArielLine8, gJiminyCharacterArielLine9, gJiminyCharacterArielLine10, gJiminyStoryNeverLandLine18,
};

JiminyTextChar* gJiminyCharacterSebastianLines[6] = {
    gJiminyCharacterSebastianLine0, gJiminyCharacterSebastianLine1, gJiminyCharacterSebastianLine2, gJiminyCharacterSebastianLine3,
    gJiminyCharacterSebastianLine4, gJiminyCharacterSebastianLine5,
};

JiminyTextChar* gJiminyCharacterFlounderLines[7] = {
    gJiminyCharacterFlounderLine0, gJiminyCharacterFlounderLine1, gJiminyCharacterFlounderLine2, gJiminyCharacterGoofyLine6,
    gJiminyCharacterFlounderLine4, gJiminyCharacterFlounderLine5, gJiminyCharacterFlounderLine6,
};

JiminyTextChar* gJiminyCharacterUrsulaLines[6] = {
    gJiminyCharacterUrsulaLine0, gJiminyCharacterUrsulaLine1, gJiminyCharacterUrsulaLine2, gJiminyCharacterUrsulaLine3,
    gJiminyCharacterUrsulaLine4, gJiminyCharacterUrsulaLine5,
};

JiminyTextChar* gJiminyCharacterPeterPanLines[9] = {
    gJiminyCharacterPeterPanLine0, gJiminyCharacterPeterPanLine1, gJiminyCharacterPeterPanLine2, gJiminyCharacterPeterPanLine3,
    gJiminyCharacterPeterPanLine4, gJiminyCharacterPeterPanLine5, gJiminyCharacterPeterPanLine6, gJiminyCharacterPeterPanLine7,
    gJiminyCharacterPeterPanLine8,
};

JiminyTextChar* gJiminyCharacterTinkerBellLines[4] = {
    gJiminyCharacterTinkerBellLine0, gJiminyCharacterTinkerBellLine1, gJiminyCharacterTinkerBellLine2, gJiminyCharacterTinkerBellLine3,
};

JiminyTextChar* gJiminyCharacterWendyLines[6] = {
    gJiminyCharacterWendyLine0, gJiminyCharacterWendyLine1, gJiminyCharacterWendyLine2, gJiminyCharacterWendyLine3,
    gJiminyCharacterWendyLine4, gJiminyCharacterWendyLine5,
};

JiminyTextChar* gJiminyCharacterHookLines[8] = {
    gJiminyCharacterHookLine0, gJiminyCharacterHookLine1, gJiminyCharacterHookLine2, gJiminyStoryNeverLandLine18,
    gJiminyCharacterHookLine4, gJiminyCharacterHookLine5, gJiminyCharacterHookLine6, gJiminyCharacterHookLine7,
};

JiminyTextChar* gJiminyCharacterBeastLines[10] = {
    gJiminyCharacterBeastLine0, gJiminyCharacterBeastLine1, gJiminyCharacterBeastLine2, gJiminyCharacterBeastLine3,
    gJiminyCharacterBeastLine4, gJiminyCharacterBeastLine5, gJiminyCharacterBeastLine6, gJiminyCharacterBeastLine7,
    gJiminyCharacterBeastLine8, gJiminyCharacterBeastLine9,
};

JiminyTextChar* gJiminyCharacterBelleLines[9] = {
    gJiminyCharacterBelleLine0, gJiminyCharacterBelleLine1, gJiminyCharacterBelleLine2, gJiminyCharacterBelleLine3,
    gJiminyCharacterBelleLine4, gJiminyCharacterBelleLine5, gJiminyCharacterBelleLine6, gJiminyCharacterBelleLine7,
    gJiminyCharacterBelleLine8,
};

JiminyTextChar* gJiminyCharacterMaleficentLines[9] = {
    gJiminyCharacterMaleficentLine0, gJiminyCharacterMaleficentLine1, gJiminyCharacterMaleficentLine2, gJiminyCharacterMaleficentLine3,
    gJiminyCharacterMaleficentLine4, gJiminyCharacterMaleficentLine5, gJiminyCharacterMaleficentLine6, gJiminyCharacterMaleficentLine7,
    gJiminyStoryCastleOblivionLine3,
};

JiminyTextChar* gJiminyCharacterDragonMaleficentLines[5] = {
    gJiminyCharacterDragonMaleficentLine0, gJiminyCharacterDragonMaleficentLine1, gJiminyCharacterDragonMaleficentLine2, gJiminyCharacterDragonMaleficentLine3,
    gJiminyCharacterDragonMaleficentLine4,
};

JiminyTextChar* gJiminyCharacterWinnieThePoohLines[6] = {
    gJiminyCharacterWinnieThePoohLine0, gJiminyCharacterWinnieThePoohLine1, gJiminyCharacterWinnieThePoohLine2, gJiminyCharacterWinnieThePoohLine3,
    gJiminyCharacterWinnieThePoohLine4, gJiminyCharacterWinnieThePoohLine5,
};

JiminyTextChar* gJiminyCharacterPigletLines[6] = {
    gJiminyCharacterPigletLine0, gJiminyCharacterPigletLine1, gJiminyCharacterPigletLine2, gJiminyCharacterPigletLine3,
    gJiminyCharacterPigletLine4, gJiminyCharacterPigletLine5,
};

JiminyTextChar* gJiminyCharacterOwlLines[5] = {
    gJiminyCharacterOwlLine0, gJiminyCharacterOwlLine1, gJiminyCharacterOwlLine2, gJiminyCharacterOwlLine3,
    gJiminyCharacterOwlLine4,
};

JiminyTextChar* gJiminyCharacterRooLines[5] = {
    gJiminyCharacterRooLine0, gJiminyCharacterRooLine1, gJiminyCharacterRooLine2, gJiminyCharacterRooLine3,
    gJiminyCharacterRooLine4,
};

JiminyTextChar* gJiminyCharacterEeyoreLines[5] = {
    gJiminyCharacterEeyoreLine0, gJiminyCharacterEeyoreLine1, gJiminyCharacterEeyoreLine2, gJiminyCharacterEeyoreLine3,
    gJiminyCharacterEeyoreLine4,
};

JiminyTextChar* gJiminyCharacterTiggerLines[6] = {
    gJiminyCharacterTiggerLine0, gJiminyCharacterTiggerLine1, gJiminyCharacterTiggerLine2, gJiminyCharacterTiggerLine3,
    gJiminyCharacterTiggerLine4, gJiminyCharacterTiggerLine5,
};

JiminyTextChar* gJiminyCharacterRabbitLines[6] = {
    gJiminyCharacterRabbitLine0, gJiminyCharacterRabbitLine1, gJiminyCharacterRabbitLine2, gJiminyCharacterRabbitLine3,
    gJiminyCharacterRabbitLine4, gJiminyCharacterRabbitLine5,
};

JiminyTextChar* gJiminyHeartlessGuardArmorLines[4] = {
    gJiminyHeartlessGuardArmorLine0, gJiminyHeartlessGuardArmorLine1, gJiminyHeartlessGuardArmorLine2, gJiminyHeartlessGuardArmorLine3,
};

JiminyTextChar* gJiminyHeartlessParasiteCageLines[8] = {
    gJiminyHeartlessParasiteCageLine0, gJiminyHeartlessParasiteCageLine1, gJiminyHeartlessParasiteCageLine2, gJiminyHeartlessParasiteCageLine3,
    gJiminyHeartlessParasiteCageLine4, gJiminyHeartlessParasiteCageLine5, gJiminyHeartlessParasiteCageLine6, gJiminyHeartlessParasiteCageLine7,
};

JiminyTextChar* gJiminyHeartlessTrickmasterLines[6] = {
    gJiminyHeartlessTrickmasterLine0, gJiminyHeartlessTrickmasterLine1, gJiminyHeartlessTrickmasterLine2, gJiminyHeartlessTrickmasterLine3,
    gJiminyHeartlessTrickmasterLine4, gJiminyHeartlessTrickmasterLine5,
};

JiminyTextChar* gJiminyHeartlessDarksideLines[6] = {
    gJiminyHeartlessDarksideLine0, gJiminyHeartlessDarksideLine1, gJiminyHeartlessDarksideLine2, gJiminyHeartlessDarksideLine3,
    gJiminyHeartlessDarksideLine4, gJiminyStoryNeverLandLine12,
};

JiminyTextChar* gJiminyHeartlessShadowLines[7] = {
    gJiminyHeartlessShadowLine0, gJiminyHeartlessShadowLine1, gJiminyHeartlessShadowLine2, gJiminyHeartlessShadowLine3,
    gJiminyHeartlessShadowLine4, gJiminyHeartlessShadowLine5, gJiminyHeartlessShadowLine6,
};

JiminyTextChar* gJiminyHeartlessSoldierLines[5] = {
    gJiminyHeartlessSoldierLine0, gJiminyHeartlessSoldierLine1, gJiminyHeartlessSoldierLine2, gJiminyHeartlessSoldierLine3,
    gJiminyHeartlessSoldierLine4,
};

JiminyTextChar* gJiminyHeartlessLargeBodyLines[8] = {
    gJiminyHeartlessLargeBodyLine0, gJiminyHeartlessLargeBodyLine1, gJiminyHeartlessLargeBodyLine2, gJiminyHeartlessLargeBodyLine3,
    gJiminyHeartlessLargeBodyLine4, gJiminyHeartlessLargeBodyLine5, gJiminyHeartlessLargeBodyLine6, gJiminyHeartlessLargeBodyLine7,
};

JiminyTextChar* gJiminyHeartlessRedNocturneLines[8] = {
    gJiminyHeartlessRedNocturneLine0, gJiminyHeartlessRedNocturneLine1, gJiminyHeartlessRedNocturneLine2, gJiminyHeartlessRedNocturneLine3,
    gJiminyHeartlessRedNocturneLine4, gJiminyHeartlessRedNocturneLine5, gJiminyHeartlessRedNocturneLine6, gJiminyHeartlessRedNocturneLine7,
};

JiminyTextChar* gJiminyHeartlessBlueRhapsodyLines[6] = {
    gJiminyHeartlessRedNocturneLine0, gJiminyHeartlessBlueRhapsodyLine1, gJiminyHeartlessBlueRhapsodyLine2, gJiminyHeartlessBlueRhapsodyLine3,
    gJiminyHeartlessBlueRhapsodyLine4, gJiminyHeartlessBlueRhapsodyLine5,
};

JiminyTextChar* gJiminyHeartlessYellowOperaLines[6] = {
    gJiminyHeartlessRedNocturneLine0, gJiminyHeartlessYellowOperaLine1, gJiminyHeartlessYellowOperaLine2, gJiminyHeartlessYellowOperaLine3,
    gJiminyHeartlessYellowOperaLine4, gJiminyHeartlessRedNocturneLine7,
};

JiminyTextChar* gJiminyHeartlessGreenRequiemLines[8] = {
    gJiminyHeartlessRedNocturneLine0, gJiminyHeartlessShadowLine1, gJiminyHeartlessGreenRequiemLine2, gJiminyHeartlessGreenRequiemLine3,
    gJiminyHeartlessGreenRequiemLine4, gJiminyHeartlessGreenRequiemLine5, gJiminyHeartlessGreenRequiemLine6, gJiminyHeartlessGreenRequiemLine7,
};

JiminyTextChar* gJiminyHeartlessPowerwildLines[6] = {
    gJiminyHeartlessPowerwildLine0, gJiminyHeartlessPowerwildLine1, gJiminyCharacterAladdinLine2, gJiminyHeartlessPowerwildLine3,
    gJiminyHeartlessPowerwildLine4, gJiminyHeartlessPowerwildLine5,
};

JiminyTextChar* gJiminyHeartlessBouncywildLines[6] = {
    gJiminyHeartlessPowerwildLine0, gJiminyHeartlessDarksideLine2, gJiminyHeartlessBouncywildLine2, gJiminyHeartlessBouncywildLine3,
    gJiminyHeartlessBouncywildLine4, gJiminyHeartlessBouncywildLine5,
};

JiminyTextChar* gJiminyHeartlessAirSoldierLines[7] = {
    gJiminyHeartlessAirSoldierLine0, gJiminyHeartlessAirSoldierLine1, gJiminyHeartlessAirSoldierLine2, gJiminyHeartlessAirSoldierLine3,
    gJiminyHeartlessAirSoldierLine4, gJiminyHeartlessAirSoldierLine5, gJiminyHeartlessAirSoldierLine6,
};

JiminyTextChar* gJiminyHeartlessBanditLines[5] = {
    gJiminyHeartlessBanditLine0, gJiminyHeartlessShadowLine1, gJiminyHeartlessBanditLine2, gJiminyHeartlessBanditLine3,
    gJiminyHeartlessBanditLine4,
};

JiminyTextChar* gJiminyHeartlessFatBanditLines[6] = {
    gJiminyHeartlessBanditLine0, gJiminyHeartlessShadowLine1, gJiminyHeartlessLargeBodyLine2, gJiminyHeartlessLargeBodyLine3,
    gJiminyHeartlessFatBanditLine4, gJiminyHeartlessFatBanditLine5,
};

JiminyTextChar* gJiminyHeartlessBarrelSpiderLines[6] = {
    gJiminyHeartlessBarrelSpiderLine0, gJiminyHeartlessBarrelSpiderLine1, gJiminyHeartlessBarrelSpiderLine2, gJiminyHeartlessBarrelSpiderLine3,
    gJiminyHeartlessBarrelSpiderLine4, gJiminyHeartlessBarrelSpiderLine5,
};

JiminyTextChar* gJiminyHeartlessSearchGhostLines[5] = {
    gJiminyHeartlessSearchGhostLine0, gJiminyHeartlessTrickmasterLine2, gJiminyHeartlessSearchGhostLine2, gJiminyHeartlessSearchGhostLine3,
    gJiminyHeartlessSearchGhostLine4,
};

JiminyTextChar* gJiminyHeartlessSeaNeonLines[7] = {
    gJiminyHeartlessSeaNeonLine0, gJiminyHeartlessTrickmasterLine2, gJiminyHeartlessSeaNeonLine2, gJiminyHeartlessSeaNeonLine3,
    gJiminyHeartlessSeaNeonLine4, gJiminyHeartlessSeaNeonLine5, gJiminyHeartlessSeaNeonLine6,
};

JiminyTextChar* gJiminyHeartlessScrewdiverLines[4] = {
    gJiminyHeartlessScrewdiverLine0, gJiminyHeartlessScrewdiverLine1, gJiminyHeartlessScrewdiverLine2, gJiminyHeartlessScrewdiverLine3,
};

JiminyTextChar* gJiminyHeartlessAquatankLines[5] = {
    gJiminyHeartlessAquatankLine0, gJiminyHeartlessAquatankLine1, gJiminyHeartlessAquatankLine2, gJiminyHeartlessAquatankLine3,
    gJiminyEnemyCardPowerwildLine3,
};

JiminyTextChar* gJiminyHeartlessWightKnightLines[5] = {
    gJiminyHeartlessWightKnightLine0, gJiminyHeartlessWightKnightLine1, gJiminyHeartlessWightKnightLine2, gJiminyHeartlessWightKnightLine3,
    gJiminyHeartlessWightKnightLine4,
};

JiminyTextChar* gJiminyHeartlessGargoyleLines[5] = {
    gJiminyHeartlessGargoyleLine0, gJiminyHeartlessGargoyleLine1, gJiminyHeartlessTrickmasterLine2, gJiminyHeartlessGargoyleLine3,
    gJiminyHeartlessGargoyleLine4,
};

JiminyTextChar* gJiminyHeartlessPirateLines[7] = {
    gJiminyHeartlessPirateLine0, gJiminyHeartlessShadowLine1, gJiminyHeartlessPirateLine2, gJiminyHeartlessPirateLine3,
    gJiminyHeartlessPirateLine4, gJiminyHeartlessPirateLine5, gJiminyHeartlessPirateLine6,
};

JiminyTextChar* gJiminyHeartlessAirPirateLines[6] = {
    gJiminyHeartlessPirateLine0, gJiminyHeartlessAirPirateLine1, gJiminyHeartlessAirPirateLine2, gJiminyHeartlessAirPirateLine3,
    gJiminyHeartlessAirPirateLine4, gJiminyHeartlessAirPirateLine5,
};

JiminyTextChar* gJiminyHeartlessDarkballLines[7] = {
    gJiminyHeartlessDarkballLine0, gJiminyHeartlessDarkballLine1, gJiminyHeartlessDarkballLine2, gJiminyHeartlessDarkballLine3,
    gJiminyHeartlessDarkballLine4, gJiminyHeartlessDarkballLine5, gJiminyHeartlessDarkballLine6,
};

JiminyTextChar* gJiminyHeartlessDefenderLines[9] = {
    gJiminyHeartlessDefenderLine0, gJiminyHeartlessDefenderLine1, gJiminyHeartlessDefenderLine2, gJiminyHeartlessDefenderLine3,
    gJiminyHeartlessDefenderLine4, gJiminyHeartlessDefenderLine5, gJiminyHeartlessDefenderLine6, gJiminyHeartlessDefenderLine7,
    gJiminyHeartlessDefenderLine8,
};

JiminyTextChar* gJiminyHeartlessWyvernLines[6] = {
    gJiminyHeartlessWyvernLine0, gJiminyHeartlessShadowLine1, gJiminyHeartlessWyvernLine2, gJiminyHeartlessWyvernLine3,
    gJiminyHeartlessWyvernLine4, gJiminyHeartlessWyvernLine5,
};

JiminyTextChar* gJiminyHeartlessWizardLines[4] = {
    gJiminyHeartlessWizardLine0, gJiminyFriendCardDonaldDuckLine0, gJiminyHeartlessWizardLine2, gJiminyHeartlessWizardLine3,
};

JiminyTextChar* gJiminyHeartlessNeoshadowLines[2] = {
    gJiminyHeartlessNeoshadowLine0, gJiminyHeartlessNeoshadowLine1,
};

JiminyTextChar* gJiminyHeartlessWhiteMushroomLines[7] = {
    gJiminyHeartlessWhiteMushroomLine0, gJiminyHeartlessWhiteMushroomLine1, gJiminyHeartlessWhiteMushroomLine2, gJiminyCharacterWhiteRabbitLine3,
    gJiminyHeartlessWhiteMushroomLine4, gJiminyHeartlessWhiteMushroomLine5, gJiminyHeartlessWhiteMushroomLine6,
};

JiminyTextChar* gJiminyHeartlessBlackFungusLines[8] = {
    gJiminyHeartlessBlackFungusLine0, gJiminyHeartlessBlackFungusLine1, gJiminyCharacterKairiLine9, gJiminyHeartlessBlackFungusLine3,
    gJiminyHeartlessBlackFungusLine4, gJiminyHeartlessBlackFungusLine5, gJiminyHeartlessBlackFungusLine6, gJiminyHeartlessBlackFungusLine7,
};

JiminyTextChar* gJiminyHeartlessCreeperPlantLines[7] = {
    gJiminyHeartlessCreeperPlantLine0, gJiminyHeartlessTrickmasterLine2, gJiminyHeartlessCreeperPlantLine2, gJiminyHeartlessCreeperPlantLine3,
    gJiminyHeartlessCreeperPlantLine4, gJiminyHeartlessCreeperPlantLine5, gJiminyHeartlessCreeperPlantLine6,
};

JiminyTextChar* gJiminyHeartlessTornadoStepLines[6] = {
    gJiminyHeartlessTornadoStepLine0, gJiminyHeartlessTornadoStepLine1, gJiminyHeartlessTornadoStepLine2, gJiminyHeartlessTornadoStepLine3,
    gJiminyHeartlessTornadoStepLine4, gJiminyHeartlessTornadoStepLine5,
};

JiminyTextChar* gJiminyHeartlessCrescendoLines[5] = {
    gJiminyHeartlessCrescendoLine0, gJiminyHeartlessCrescendoLine1, gJiminyHeartlessCrescendoLine2, gJiminyHeartlessCrescendoLine3,
    gJiminyHeartlessCrescendoLine4,
};

JiminyTextChar* gJiminyRikuCharacterRikuLines[11] = {
    gJiminyRikuCharacterRikuLine0, gJiminyRikuCharacterRikuLine1, gJiminyRikuCharacterRikuLine2, gJiminyRikuCharacterRikuLine3,
    gJiminyRikuCharacterRikuLine4, gJiminyRikuCharacterRikuLine5, gJiminyRikuCharacterRikuLine6, gJiminyRikuCharacterRikuLine7,
    gJiminyRikuCharacterRikuLine8, gJiminyRikuCharacterRikuLine9, gJiminyRikuCharacterRikuLine10,
};

JiminyTextChar* gJiminyRikuCharacterKingLines[7] = {
    gJiminyRikuCharacterKingLine0, gJiminyRikuCharacterKingLine1, gJiminyRikuCharacterKingLine2, gJiminyRikuCharacterKingLine3,
    gJiminyRikuCharacterKingLine4, gJiminyRikuCharacterKingLine5, gJiminyRikuCharacterKingLine6,
};

JiminyTextChar* gJiminyRikuCharacterSoraLines[7] = {
    gJiminyRikuCharacterSoraLine0, gJiminyRikuCharacterSoraLine1, gJiminyRikuCharacterSoraLine2, gJiminyRikuCharacterSoraLine3,
    gJiminyRikuCharacterSoraLine4, gJiminyRikuCharacterSoraLine5, gJiminyRikuCharacterSoraLine6,
};

JiminyTextChar* gJiminyRikuCharacterKairiLines[10] = {
    gJiminyRikuCharacterKairiLine0, gJiminyRikuCharacterKairiLine1, gJiminyRikuCharacterKairiLine2, gJiminyRikuCharacterKairiLine3,
    gJiminyRikuCharacterKairiLine4, gJiminyCharacterKairiLine5, gJiminyCharacterKairiLine6, gJiminyCharacterKairiLine7,
    gJiminyRikuCharacterKairiLine8, gJiminyCharacterKairiLine9,
};

JiminyTextChar* gJiminyRikuCharacterNamineLines[8] = {
    gJiminyCharacterNamineLine0, gJiminyRikuCharacterNamineLine1, gJiminyRikuCharacterNamineLine2, gJiminyRikuCharacterNamineLine3,
    gJiminyRikuCharacterNamineLine4, gJiminyRikuCharacterNamineLine5, gJiminyRikuCharacterNamineLine6, gJiminyRikuCharacterNamineLine7,
};

JiminyTextChar* gJiminyRikuCharacterRikuReplicaLines[7] = {
    gJiminyCharacterRikuReplicaLine0, gJiminyRikuCharacterRikuReplicaLine1, gJiminyRikuCharacterRikuReplicaLine2, gJiminyRikuCharacterRikuReplicaLine3,
    gJiminyRikuCharacterRikuReplicaLine4, gJiminyRikuCharacterRikuReplicaLine5, gJiminyRikuCharacterRikuReplicaLine6,
};

JiminyTextChar* gJiminyRikuCharacterAnsemLines[8] = {
    gJiminyRikuCharacterAnsemLine0, gJiminyRikuCharacterAnsemLine1, gJiminyRikuCharacterAnsemLine2, gJiminyRikuCharacterAnsemLine3,
    gJiminyRikuCharacterAnsemLine4, gJiminyRikuCharacterAnsemLine5, gJiminyRikuCharacterAnsemLine6, gJiminyRikuCharacterAnsemLine7,
};

JiminyTextChar* gJiminyRikuCharacterVexenLines[10] = {
    gJiminyRikuCharacterVexenLine0, gJiminyRikuCharacterVexenLine1, gJiminyRikuCharacterVexenLine2, gJiminyRikuCharacterVexenLine3,
    gJiminyRikuCharacterVexenLine4, gJiminyRikuCharacterVexenLine5, gJiminyRikuCharacterVexenLine6, gJiminyRikuCharacterVexenLine7,
    gJiminyRikuCharacterVexenLine8, gJiminyAttackCardCrabclawLine9,
};

JiminyTextChar* gJiminyRikuCharacterLexaeusLines[10] = {
    gJiminyRikuCharacterLexaeusLine0, gJiminyRikuCharacterLexaeusLine1, gJiminyRikuCharacterLexaeusLine2, gJiminyRikuCharacterLexaeusLine3,
    gJiminyRikuCharacterLexaeusLine4, gJiminyRikuCharacterLexaeusLine5, gJiminyStoryNeverLandLine21, gJiminyRikuCharacterLexaeusLine7,
    gJiminyRikuCharacterLexaeusLine8, gJiminyRikuCharacterLexaeusLine9,
};

JiminyTextChar* gJiminyRikuCharacterZexionLines[11] = {
    gJiminyRikuCharacterZexionLine0, gJiminyRikuCharacterZexionLine1, gJiminyRikuCharacterZexionLine2, gJiminyRikuCharacterZexionLine3,
    gJiminyRikuCharacterZexionLine4, gJiminyRikuCharacterZexionLine5, gJiminyRikuCharacterZexionLine6, gJiminyRikuCharacterZexionLine7,
    gJiminyRikuCharacterZexionLine8, gJiminyRikuCharacterZexionLine9, gJiminyRikuCharacterZexionLine10,
};

JiminyTextChar* gJiminyRikuCharacterAxelLines[10] = {
    gJiminyRikuCharacterAxelLine0, gJiminyRikuCharacterAxelLine1, gJiminyRikuCharacterAxelLine2, gJiminyRikuCharacterAxelLine3,
    gJiminyRikuCharacterAxelLine4, gJiminyRikuCharacterAxelLine5, gJiminyRikuCharacterAxelLine6, gJiminyRikuCharacterAxelLine7,
    gJiminyRikuCharacterAxelLine8, gJiminyRikuCharacterAxelLine9,
};

JiminyTextChar* gJiminyRikuCharacterMarluxiaLines[12] = {
    gJiminyRikuCharacterMarluxiaLine0, gJiminyRikuCharacterMarluxiaLine1, gJiminyRikuCharacterMarluxiaLine2, gJiminyRikuCharacterMarluxiaLine3,
    gJiminyRikuCharacterMarluxiaLine4, gJiminyRikuCharacterMarluxiaLine5, gJiminyRikuCharacterMarluxiaLine6, gJiminyRikuCharacterMarluxiaLine7,
    gJiminyRikuCharacterMarluxiaLine8, gJiminyRikuCharacterMarluxiaLine9, gJiminyRikuCharacterMarluxiaLine10, gJiminyStoryNeverLandLine18,
};

JiminyTextChar* gJiminyRikuCharacterLarxeneLines[9] = {
    gJiminyRikuCharacterLarxeneLine0, gJiminyRikuCharacterLarxeneLine1, gJiminyRikuCharacterLarxeneLine2, gJiminyRikuCharacterLarxeneLine3,
    gJiminyRikuCharacterLarxeneLine4, gJiminyRikuCharacterLarxeneLine5, gJiminyRikuCharacterLarxeneLine6, gJiminyRikuCharacterLarxeneLine7,
    gJiminyRikuCharacterLarxeneLine8,
};

JiminyTextChar* gJiminyRikuCharacterDiZLines[7] = {
    gJiminyRikuCharacterDiZLine0, gJiminyRikuCharacterDiZLine1, gJiminyRikuCharacterDiZLine2, gJiminyRikuCharacterDiZLine3,
    gJiminyRikuCharacterDiZLine4, gJiminyRikuCharacterDiZLine5, gJiminyRikuCharacterDiZLine6,
};

JiminyTextChar* gJiminyRikuCharacterMaleficentLines[6] = {
    gJiminyCharacterMaleficentLine0, gJiminyRikuCharacterMaleficentLine1, gJiminyRikuCharacterMaleficentLine2, gJiminyRikuCharacterMaleficentLine3,
    gJiminyRikuCharacterMaleficentLine4, gJiminyRikuCharacterMaleficentLine5,
};

JiminyTextChar* gJiminyRikuCharacterJafarGenieLines[6] = {
    gJiminyRikuCharacterJafarGenieLine0, gJiminyRikuCharacterJafarGenieLine1, gJiminyRikuCharacterJafarGenieLine2, gJiminyRikuCharacterMaleficentLine3,
    gJiminyRikuCharacterMaleficentLine4, gJiminyRikuCharacterMaleficentLine5,
};

JiminyTextChar* gJiminyRikuCharacterUrsulaLines[6] = {
    gJiminyRikuCharacterUrsulaLine0, gJiminyRikuCharacterUrsulaLine1, gJiminyRikuCharacterUrsulaLine2, gJiminyRikuCharacterMaleficentLine3,
    gJiminyRikuCharacterMaleficentLine4, gJiminyRikuCharacterMaleficentLine5,
};

JiminyTextChar* gJiminyRikuCharacterHadesLines[5] = {
    gJiminyCharacterHadesLine0, gJiminyCharacterHadesLine1, gJiminyRikuCharacterMaleficentLine3, gJiminyRikuCharacterMaleficentLine4,
    gJiminyRikuCharacterMaleficentLine5,
};

JiminyTextChar* gJiminyRikuCharacterOogieBoogieLines[5] = {
    gJiminyCharacterOogieBoogieLine0, gJiminyCharacterOogieBoogieLine1, gJiminyRikuCharacterMaleficentLine3, gJiminyRikuCharacterMaleficentLine4,
    gJiminyRikuCharacterMaleficentLine5,
};

JiminyTextChar* gJiminyRikuCharacterHookLines[4] = {
    gJiminyCharacterHookLine0, gJiminyRikuCharacterMaleficentLine3, gJiminyRikuCharacterMaleficentLine4, gJiminyRikuCharacterMaleficentLine5,
};

JiminyTextChar* gJiminyRikuHeartlessGuardArmorLines[4] = {
    gJiminyHeartlessGuardArmorLine0, gJiminyHeartlessGuardArmorLine1, gJiminyRikuHeartlessGuardArmorLine2, gJiminyRikuHeartlessGuardArmorLine3,
};

JiminyTextChar* gJiminyRikuHeartlessParasiteCageLines[4] = {
    gJiminyHeartlessParasiteCageLine0, gJiminyHeartlessParasiteCageLine1, gJiminyRikuHeartlessGuardArmorLine2, gJiminyRikuHeartlessGuardArmorLine3,
};

JiminyTextChar* gJiminyRikuHeartlessTrickmasterLines[4] = {
    gJiminyRikuHeartlessTrickmasterLine0, gJiminyHeartlessParasiteCageLine1, gJiminyRikuHeartlessGuardArmorLine2, gJiminyRikuHeartlessGuardArmorLine3,
};

JiminyTextChar* gJiminyRikuHeartlessDarksideLines[5] = {
    gJiminyRikuHeartlessDarksideLine0, gJiminyRikuHeartlessDarksideLine1, gJiminyRikuHeartlessDarksideLine2, gJiminyRikuHeartlessDarksideLine3,
    gJiminyRikuHeartlessDarksideLine4,
};

JiminyTextChar* gJiminyRootNames[3] = {
    gJiminyMenuStoryName, gJiminyMenuCardIndexName, gJiminyMenuCharactersName,
};

JiminyTextChar* gJiminyEntry01Names[17] = {
    gJiminyStoryTale1Name, gJiminyStoryTale2Name, gJiminyStoryTale3Name, gJiminyStoryTale4Name,
    gWorldNameTraverseTown, gWorldNameWonderland, gWorldNameOlympusColiseum, gWorldNameAgrabah,
    gWorldNameHalloweenTown, gWorldNameMonstro, gWorldNameAtlantica, gWorldNameNeverLand,
    gWorldNameHollowBastion, gWorldName100AcreWood, gWorldNameTwilightTown, gWorldNameDestinyIslands,
    gWorldNameCastleOblivion,
};

JiminyTextChar* gJiminyEntry02Names[7] = {
    gJiminyMenuAttackCardsName, gJiminyMenuMagicCardsName, gJiminyMenuItemCardsName, gJiminyMenuFriendCardsName,
    gJiminyMenuEnemyCardsName, gJiminyMenuMapCardsName, gJiminyMenuPremiumCardsName,
};

JiminyTextChar* gJiminyEntry03Names[3] = {
    gJiminyMenuCharacters1Name, gJiminyMenuCharacters2Name, gJiminyMenuHeartlessName,
};

JiminyTextChar* gJiminyEntry04Names[17] = {
    gCardNameKingdomKey, gCardNameThreeWishes, gCardNameCrabclaw, gCardNamePumpkinhead,
    gCardNameFairyHarp, gCardNameWishingStar, gCardNameSpellbinder, gCardNameMetalChocobo,
    gCardNameOlympia, gCardNameLionheart, gCardNameLadyLuck, gCardNameDivineRose,
    gCardNameOathkeeper, gCardNameOblivion, gCardNameDiamondDust, gCardNameOneWingedAngel,
    gCardNameUltimaWeapon,
};

JiminyTextChar* gJiminyEntry05Names[14] = {
    gCardNameFire, gCardNameBlizzard, gCardNameThunder, gCardNameCure,
    gCardNameGravity, gCardNameStop, gCardNameAero, gCardNameSimba,
    gCardNameDumbo, gCardNameBambi, gCardNameMushu, gCardNameGenie,
    gCardNameTinkerBell, gCardNameCloud,
};

JiminyTextChar* gJiminyEntry06Names[7] = {
    gCardNamePotion, gCardNameHiPotion, gCardNameMegaPotion, gCardNameEther,
    gCardNameMegaEther, gCardNameElixir, gCardNameMegalixir,
};

JiminyTextChar* gJiminyEntry07Names[7] = {
    gCardNameDonaldDuck, gCardNameGoofy, gCardNameAladdin, gCardNameJack,
    gCardNameAriel, gCardNamePeterPan, gCardNameBeast,
};

JiminyTextChar* gJiminyEntry08Names[49] = {
    gEnemyNameShadow, gEnemyNameSoldier, gEnemyNameLargeBody, gEnemyNameRedNocturne,
    gEnemyNameBlueRhapsody, gEnemyNameYellowOpera, gEnemyNameGreenRequiem, gEnemyNamePowerwild,
    gEnemyNameBouncywild, gEnemyNameAirSoldier, gEnemyNameBandit, gEnemyNameFatBandit,
    gEnemyNameBarrelSpider, gEnemyNameSearchGhost, gEnemyNameSeaNeon, gEnemyNameScrewdiver,
    gEnemyNameAquatank, gEnemyNameWightKnight, gEnemyNameGargoyle, gEnemyNamePirate,
    gEnemyNameAirPirate, gEnemyNameDarkball, gEnemyNameDefender, gEnemyNameWyvern,
    gEnemyNameWizard, gEnemyNameNeoshadow, gEnemyNameWhiteMushroom, gEnemyNameBlackFungus,
    gEnemyNameCreeperPlant, gEnemyNameTornadoStep, gEnemyNameCrescendo, gEnemyNameGuardArmor,
    gEnemyNameParasiteCage, gEnemyNameTrickmaster, gEnemyNameDarkside, gEnemyNameCardSoldier,
    gEnemyNameHades, gEnemyNameJafar, gEnemyNameOogieBoogie, gEnemyNameUrsula,
    gEnemyNameHook, gEnemyNameDragonMaleficent, gEnemyNameRiku, gEnemyNameAxel,
    gEnemyNameLarxene, gEnemyNameVexen, gEnemyNameMarluxia, gEnemyNameLexaeus,
    gEnemyNameAnsem,
};

JiminyTextChar* gJiminyEntry09Names[26] = {
    gRoomNameTranquilDarkness, gRoomNameTeemingDarkness, gRoomNameFeebleDarkness, gRoomNameAlmightyDarkness,
    gRoomNameSleepingDarkness, gRoomNameLoomingDarkness, gRoomNamePremiumRoom, gRoomNameWhiteRoom,
    gRoomNameBlackRoom, gRoomNameMartialWaking, gRoomNameSorcerousWaking, gRoomNameAlchemicWaking,
    gRoomNameMeetingGround, gRoomNameStagnantSpace, gRoomNameStrongInitiative, gRoomNameLastingDaze,
    gRoomNameCalmBounty, gRoomNameGuardedTrove, gRoomNameFalseBounty, gRoomNameMomentsReprieve,
    gRoomNameMinglingWorlds, gRoomNameMoogleRoom, gRoomNameKeyOfBeginnings, gRoomNameKeyOfGuidance,
    gRoomNameKeyToTruth, gRoomNameKeyToRewards,
};

JiminyTextChar* gJiminyEntry10Names[1] = {
    gJiminyPremiumCardsName,
};

JiminyTextChar* gJiminyEntry11Names[25] = {
    gCharacterNameSora, gCardNameDonaldDuck, gCardNameGoofy, gCharacterNameJiminyCricket,
    gEnemyNameRiku, gCharacterNameKairi, gCardNameSimba, gCardNameDumbo,
    gCardNameBambi, gCardNameMushu, gCharacterNameMoogles, gCharacterNameLeon,
    gCharacterNameYuffie, gCharacterNameAerith, gCharacterNameCid, gCardNameCloud,
    gCharacterNameTidus, gCharacterNameWakka, gCharacterNameSelphie, gCharacterNameNamine,
    gCharacterNameRikuReplica, gEnemyNameAxel, gEnemyNameLarxene, gEnemyNameVexen,
    gEnemyNameMarluxia,
};

JiminyTextChar* gJiminyEntry12Names[40] = {
    gCharacterNameAlice, gCharacterNameQueenOfHearts, gCharacterNameWhiteRabbit, gCharacterNameCardOfHearts,
    gCharacterNameCardOfSpades, gCharacterNameCheshireCat, gCharacterNameHercules, gCharacterNamePhiloctetes,
    gEnemyNameHades, gCardNameAladdin, gCardNameGenie, gCharacterNameJasmine,
    gCharacterNameIago, gEnemyNameJafar, gCharacterNameJafarGenie, gCardNameJack,
    gCharacterNameSally, gCharacterNameDrFinkelstein, gEnemyNameOogieBoogie, gCharacterNamePinocchio,
    gCharacterNameGeppetto, gCardNameAriel, gCharacterNameSebastian, gCharacterNameFlounder,
    gEnemyNameUrsula, gCardNamePeterPan, gCardNameTinkerBell, gCharacterNameWendy,
    gCharacterNameHook, gCardNameBeast, gCharacterNameBelle, gCharacterNameMaleficent,
    gEnemyNameDragonMaleficent, gCharacterNameWinnieThePooh, gCharacterNamePiglet, gCharacterNameOwl,
    gCharacterNameRoo, gCharacterNameEeyore, gCharacterNameTigger, gCharacterNameRabbit,
};

JiminyTextChar* gJiminyEntry13Names[35] = {
    gEnemyNameShadow, gEnemyNameSoldier, gEnemyNameLargeBody, gEnemyNameRedNocturne,
    gEnemyNameBlueRhapsody, gEnemyNameYellowOpera, gEnemyNameGreenRequiem, gEnemyNamePowerwild,
    gEnemyNameBouncywild, gEnemyNameAirSoldier, gEnemyNameBandit, gEnemyNameFatBandit,
    gEnemyNameBarrelSpider, gEnemyNameSearchGhost, gEnemyNameSeaNeon, gEnemyNameScrewdiver,
    gEnemyNameAquatank, gEnemyNameWightKnight, gEnemyNameGargoyle, gEnemyNamePirate,
    gEnemyNameAirPirate, gEnemyNameDarkball, gEnemyNameDefender, gEnemyNameWyvern,
    gEnemyNameWizard, gEnemyNameNeoshadow, gEnemyNameWhiteMushroom, gEnemyNameBlackFungus,
    gEnemyNameCreeperPlant, gEnemyNameTornadoStep, gEnemyNameCrescendo, gEnemyNameGuardArmor,
    gEnemyNameParasiteCage, gEnemyNameTrickmaster, gEnemyNameDarkside,
};

JiminyTextChar* gJiminyEntry15Names[6] = {
    gJiminyRikuStoryTale1Name, gJiminyRikuStoryTale2Name, gJiminyRikuStoryTale3Name, gJiminyRikuStoryTale4Name,
    gJiminyRikuStoryTale5Name, gJiminyRikuStoryTale6Name,
};

JiminyTextChar* gJiminyEntry18Names[14] = {
    gEnemyNameRiku, gCardNameKing, gCharacterNameSora, gCharacterNameKairi,
    gCharacterNameNamine, gCharacterNameRikuReplica, gEnemyNameAnsem, gEnemyNameVexen,
    gEnemyNameLexaeus, gCharacterNameZexion, gEnemyNameAxel, gEnemyNameMarluxia,
    gEnemyNameLarxene, gCharacterNameDiZ,
};

JiminyTextChar* gJiminyEntry19Names[6] = {
    gCharacterNameMaleficent, gCharacterNameJafarGenie, gEnemyNameUrsula, gEnemyNameHades,
    gEnemyNameOogieBoogie, gCharacterNameHook,
};

JiminyTextChar* gJiminyEntry20Names[33] = {
    gEnemyNameShadow, gEnemyNameSoldier, gEnemyNameLargeBody, gEnemyNameRedNocturne,
    gEnemyNameBlueRhapsody, gEnemyNameYellowOpera, gEnemyNameGreenRequiem, gEnemyNamePowerwild,
    gEnemyNameBouncywild, gEnemyNameAirSoldier, gEnemyNameBandit, gEnemyNameFatBandit,
    gEnemyNameBarrelSpider, gEnemyNameSearchGhost, gEnemyNameSeaNeon, gEnemyNameScrewdiver,
    gEnemyNameAquatank, gEnemyNameWightKnight, gEnemyNameGargoyle, gEnemyNamePirate,
    gEnemyNameAirPirate, gEnemyNameDarkball, gEnemyNameDefender, gEnemyNameWyvern,
    gEnemyNameWizard, gEnemyNameNeoshadow, gEnemyNameCreeperPlant, gEnemyNameTornadoStep,
    gEnemyNameCrescendo, gEnemyNameGuardArmor, gEnemyNameParasiteCage, gEnemyNameTrickmaster,
    gEnemyNameDarkside,
};

JiminyTextChar* gJiminyEntry16Names[22] = {
    gCardNameSoulEater, gCardNameKing, gEnemyNameShadow, gEnemyNameLargeBody,
    gEnemyNamePowerwild, gEnemyNameFatBandit, gEnemyNameSearchGhost, gEnemyNameSeaNeon,
    gEnemyNameWightKnight, gEnemyNamePirate, gEnemyNameDefender, gEnemyNameGuardArmor,
    gEnemyNameParasiteCage, gEnemyNameTrickmaster, gEnemyNameDarkside, gEnemyNameHades,
    gEnemyNameJafar, gEnemyNameOogieBoogie, gEnemyNameUrsula, gEnemyNameHook,
    gEnemyNameDragonMaleficent, gEnemyNameLexaeus,
};

const JiminyTextChar* gJiminyHiddenTexts[13] = {
    gJiminyHiddenText0, gJiminyHiddenText1, gJiminyHiddenText2, gJiminyHiddenText3,
    gJiminyHiddenText4, gJiminyHiddenText5, gJiminyHiddenText6, gJiminyHiddenText7,
    gJiminyHiddenText8, gJiminyHiddenText9, gJiminyHiddenText10, gJiminyHiddenText11,
    gJiminyHiddenText12,
};

#elif defined(VERSION_EU)

const JiminyTextChar* gJiminyStoryTale1Lines[22] = {
    gJiminyStoryTale1Line0, gJiminyStoryTale1Line1, gJiminyStoryTale1Line2, gJiminyStoryTale1Line3,
    gJiminyStoryTale1Line4, gJiminyStoryTale1Line5, gJiminyStoryTale1Line6, gJiminyStoryTale1Line7,
    gJiminyStoryTale1Line8, gJiminyStoryTale1Line9, gJiminyStoryTale1Line10, gJiminyStoryTale1Line11,
    gJiminyStoryTale1Line12, gJiminyStoryTale1Line13, gJiminyStoryTale1Line14, gJiminyStoryTale1Line15,
    gJiminyStoryTale1Line16, gJiminyStoryTale1Line17, gJiminyStoryTale1Line18, gJiminyStoryTale1Line19,
    gJiminyStoryTale1Line20, gJiminyStoryTale1Line21,
};

const JiminyTextChar* gJiminyStoryTale1LinesFrench[25] = {
    gJiminyStoryTale1Line0French, gJiminyStoryTale1Line1French, gJiminyStoryTale1Line2French, gJiminyStoryTale1Line3French,
    gJiminyStoryTale1Line4French, gJiminyStoryTale1Line5French, gJiminyStoryTale1Line6French, gJiminyStoryTale1Line7French,
    gJiminyStoryTale1Line8French, gJiminyStoryTale1Line9French, gJiminyStoryTale1Line10French, gJiminyStoryTale1Line11French,
    gJiminyStoryTale1Line12French, gJiminyStoryTale1Line13French, gJiminyStoryTale1Line14French, gJiminyStoryTale1Line15French,
    gJiminyStoryTale1Line16French, gJiminyStoryTale1Line17French, gJiminyStoryTale1Line18French, gJiminyStoryTale1Line19French,
    gJiminyStoryTale1Line20French, gJiminyStoryTale1Line21French, gJiminyStoryTale1Line22French, gJiminyStoryTale1Line23French,
    gJiminyStoryTale1Line24French,
};

const JiminyTextChar* gJiminyStoryTale1LinesGerman[27] = {
    gJiminyStoryTale1Line0German, gJiminyStoryTale1Line1German, gJiminyStoryTale1Line2German, gJiminyStoryTale1Line3German,
    gJiminyStoryTale1Line4German, gJiminyStoryTale1Line5German, gJiminyStoryTale1Line6German, gJiminyStoryTale1Line7German,
    gJiminyStoryTale1Line8German, gJiminyStoryTale1Line9German, gJiminyStoryTale1Line10German, gJiminyStoryTale1Line11German,
    gJiminyStoryTale1Line12German, gJiminyStoryTale1Line13German, gJiminyStoryTale1Line14German, gJiminyStoryTale1Line15German,
    gJiminyStoryTale1Line16German, gJiminyStoryTale1Line17German, gJiminyStoryTale1Line18German, gJiminyStoryTale1Line19German,
    gJiminyStoryTale1Line20German, gJiminyStoryTale1Line21German, gJiminyStoryTale1Line22German, gJiminyStoryTale1Line23German,
    gJiminyStoryTale1Line24German, gJiminyStoryTale1Line25German, gJiminyStoryTale1Line26German,
};

const JiminyTextChar* gJiminyStoryTale1LinesItalian[27] = {
    gJiminyStoryTale1Line0Italian, gJiminyStoryTale1Line1Italian, gJiminyStoryTale1Line2Italian, gJiminyStoryTale1Line3Italian,
    gJiminyStoryTale1Line4Italian, gJiminyStoryTale1Line5Italian, gJiminyStoryTale1Line6Italian, gJiminyStoryTale1Line7Italian,
    gJiminyStoryTale1Line8Italian, gJiminyStoryTale1Line9Italian, gJiminyStoryTale1Line10Italian, gJiminyStoryTale1Line11Italian,
    gJiminyStoryTale1Line12Italian, gJiminyStoryTale1Line13Italian, gJiminyStoryTale1Line14Italian, gJiminyStoryTale1Line15Italian,
    gJiminyStoryTale1Line16Italian, gJiminyStoryTale1Line17Italian, gJiminyStoryTale1Line18Italian, gJiminyStoryTale1Line19Italian,
    gJiminyStoryTale1Line20Italian, gJiminyStoryTale1Line21Italian, gJiminyStoryTale1Line22Italian, gJiminyStoryTale1Line23Italian,
    gJiminyStoryTale1Line24Italian, gJiminyStoryTale1Line25Italian, gJiminyStoryTale1Line26Italian,
};

const JiminyTextChar* gJiminyStoryTale1LinesSpanish[25] = {
    gJiminyStoryTale1Line0Spanish, gJiminyStoryTale1Line1Spanish, gJiminyStoryTale1Line2Spanish, gJiminyStoryTale1Line3Spanish,
    gJiminyStoryTale1Line4Spanish, gJiminyStoryTale1Line5Spanish, gJiminyStoryTale1Line6Spanish, gJiminyStoryTale1Line7Spanish,
    gJiminyStoryTale1Line8Spanish, gJiminyStoryTale1Line9Spanish, gJiminyStoryTale1Line10Spanish, gJiminyStoryTale1Line11Spanish,
    gJiminyStoryTale1Line12Spanish, gJiminyStoryTale1Line13Spanish, gJiminyStoryTale1Line14Spanish, gJiminyStoryTale1Line15Spanish,
    gJiminyStoryTale1Line16Spanish, gJiminyStoryTale1Line17Spanish, gJiminyStoryTale1Line18Spanish, gJiminyStoryTale1Line19Spanish,
    gJiminyStoryTale1Line20Spanish, gJiminyStoryTale1Line21Spanish, gJiminyStoryTale1Line22Spanish, gJiminyStoryTale1Line23Spanish,
    gJiminyStoryTale1Line24Spanish,
};

const JiminyTextChar* gJiminyStoryTale2Lines[19] = {
    gJiminyStoryTale2Line0, gJiminyStoryTale2Line1, gJiminyStoryTale2Line2, gJiminyStoryTale2Line3,
    gJiminyStoryTale2Line4, gJiminyStoryTale2Line5, gJiminyStoryTale2Line6, gJiminyStoryTale2Line7,
    gJiminyStoryTale2Line8, gJiminyStoryTale2Line9, gJiminyStoryTale2Line10, gJiminyStoryTale2Line11,
    gJiminyStoryTale2Line12, gJiminyStoryTale2Line13, gJiminyStoryTale2Line14, gJiminyStoryTale2Line15,
    gJiminyStoryTale2Line16, gJiminyStoryTale2Line17, gJiminyStoryTale2Line18,
};

const JiminyTextChar* gJiminyStoryTale2LinesFrench[20] = {
    gJiminyStoryTale2Line0French, gJiminyStoryTale2Line1French, gJiminyStoryTale2Line2French, gJiminyStoryTale2Line3French,
    gJiminyStoryTale2Line4French, gJiminyStoryTale2Line5French, gJiminyStoryTale2Line6French, gJiminyStoryTale2Line7French,
    gJiminyStoryTale2Line8French, gJiminyStoryTale2Line9French, gJiminyStoryTale2Line10French, gJiminyStoryTale2Line11French,
    gJiminyStoryTale2Line12French, gJiminyStoryTale2Line13French, gJiminyStoryTale2Line14French, gJiminyStoryTale2Line15French,
    gJiminyStoryTale2Line16French, gJiminyStoryTale2Line17French, gJiminyStoryTale2Line18French, gJiminyStoryTale2Line19French,
};

const JiminyTextChar* gJiminyStoryTale2LinesGerman[24] = {
    gJiminyStoryTale2Line0German, gJiminyStoryTale2Line1German, gJiminyStoryTale2Line2German, gJiminyStoryTale2Line3German,
    gJiminyStoryTale2Line4German, gJiminyStoryTale2Line5German, gJiminyStoryTale2Line6German, gJiminyStoryTale2Line7German,
    gJiminyStoryTale2Line8German, gJiminyStoryTale2Line9German, gJiminyStoryTale2Line10German, gJiminyStoryTale2Line11German,
    gJiminyStoryTale2Line12German, gJiminyStoryTale2Line13German, gJiminyStoryTale2Line14German, gJiminyStoryTale2Line15German,
    gJiminyStoryTale2Line16German, gJiminyStoryTale2Line17German, gJiminyStoryTale2Line18German, gJiminyStoryTale2Line19German,
    gJiminyStoryTale2Line20German, gJiminyStoryTale2Line21German, gJiminyStoryTale2Line22German, gJiminyStoryTale2Line23German,
};

const JiminyTextChar* gJiminyStoryTale2LinesItalian[24] = {
    gJiminyStoryTale2Line0Italian, gJiminyStoryTale2Line1Italian, gJiminyStoryTale2Line2Italian, gJiminyStoryTale2Line3Italian,
    gJiminyStoryTale2Line4Italian, gJiminyStoryTale2Line5Italian, gJiminyStoryTale2Line6Italian, gJiminyStoryTale2Line7Italian,
    gJiminyStoryTale2Line8Italian, gJiminyStoryTale2Line9Italian, gJiminyStoryTale2Line10Italian, gJiminyStoryTale2Line11Italian,
    gJiminyStoryTale2Line12Italian, gJiminyStoryTale2Line13Italian, gJiminyStoryTale2Line14Italian, gJiminyStoryTale2Line15Italian,
    gJiminyStoryTale2Line16Italian, gJiminyStoryTale2Line17Italian, gJiminyStoryTale2Line18Italian, gJiminyStoryTale2Line19Italian,
    gJiminyStoryTale2Line20Italian, gJiminyStoryTale2Line21Italian, gJiminyStoryTale2Line22Italian, gJiminyStoryTale2Line23Italian,
};

const JiminyTextChar* gJiminyStoryTale2LinesSpanish[20] = {
    gJiminyStoryTale2Line0Spanish, gJiminyStoryTale2Line1Spanish, gJiminyStoryTale2Line2Spanish, gJiminyStoryTale2Line3Spanish,
    gJiminyStoryTale2Line4Spanish, gJiminyStoryTale2Line5Spanish, gJiminyStoryTale2Line6Spanish, gJiminyStoryTale2Line7Spanish,
    gJiminyStoryTale2Line8Spanish, gJiminyStoryTale2Line9Spanish, gJiminyStoryTale2Line10Spanish, gJiminyStoryTale2Line11Spanish,
    gJiminyStoryTale2Line12Spanish, gJiminyStoryTale2Line13Spanish, gJiminyStoryTale2Line14Spanish, gJiminyStoryTale2Line15Spanish,
    gJiminyStoryTale2Line16Spanish, gJiminyStoryTale2Line17Spanish, gJiminyStoryTale2Line18Spanish, gJiminyStoryTale2Line19Spanish,
};

const JiminyTextChar* gJiminyStoryTale3Lines[18] = {
    gJiminyStoryTale3Line0, gJiminyStoryTale3Line1, gJiminyStoryTale3Line2, gJiminyStoryTale3Line3,
    gJiminyStoryTale3Line4, gJiminyStoryTale3Line5, gJiminyStoryTale3Line6, gJiminyStoryTale3Line7,
    gJiminyStoryTale3Line8, gJiminyStoryTale3Line9, gJiminyStoryTale3Line10, gJiminyStoryTale3Line11,
    gJiminyStoryTale3Line12, gJiminyStoryTale3Line13, gJiminyStoryTale3Line14, gJiminyStoryTale3Line15,
    gJiminyStoryTale3Line16, gJiminyStoryTale3Line17,
};

const JiminyTextChar* gJiminyStoryTale3LinesFrench[19] = {
    gJiminyStoryTale3Line0French, gJiminyStoryTale3Line1French, gJiminyStoryTale3Line2French, gJiminyStoryTale3Line3French,
    gJiminyStoryTale3Line4French, gJiminyStoryTale3Line5French, gJiminyStoryTale3Line6French, gJiminyStoryTale3Line7French,
    gJiminyStoryTale3Line8French, gJiminyStoryTale3Line9French, gJiminyStoryTale3Line10French, gJiminyStoryTale3Line11French,
    gJiminyStoryTale3Line12French, gJiminyStoryTale3Line13French, gJiminyStoryTale3Line14French, gJiminyStoryTale3Line15French,
    gJiminyStoryTale3Line16French, gJiminyStoryTale3Line17French, gJiminyStoryTale3Line18French,
};

const JiminyTextChar* gJiminyStoryTale3LinesGerman[26] = {
    gJiminyStoryTale3Line0German, gJiminyStoryTale3Line1German, gJiminyStoryTale3Line2German, gJiminyStoryTale3Line3German,
    gJiminyStoryTale3Line4German, gJiminyStoryTale3Line5German, gJiminyStoryTale3Line6German, gJiminyStoryTale3Line7German,
    gJiminyStoryTale3Line8German, gJiminyStoryTale3Line9German, gJiminyStoryTale3Line10German, gJiminyStoryTale3Line11German,
    gJiminyStoryTale3Line12German, gJiminyStoryTale3Line13German, gJiminyStoryTale3Line14German, gJiminyStoryTale3Line15German,
    gJiminyStoryTale3Line16German, gJiminyStoryTale3Line17German, gJiminyStoryTale3Line18German, gJiminyStoryTale3Line19German,
    gJiminyStoryTale3Line20German, gJiminyStoryTale3Line21German, gJiminyStoryTale3Line22German, gJiminyStoryTale3Line23German,
    gJiminyStoryTale3Line24German, gJiminyStoryTale3Line25German,
};

const JiminyTextChar* gJiminyStoryTale3LinesItalian[22] = {
    gJiminyStoryTale3Line0Italian, gJiminyStoryTale3Line1Italian, gJiminyStoryTale3Line2Italian, gJiminyStoryTale3Line3Italian,
    gJiminyStoryTale3Line4Italian, gJiminyStoryTale3Line5Italian, gJiminyStoryTale3Line6Italian, gJiminyStoryTale3Line7Italian,
    gJiminyStoryTale3Line8Italian, gJiminyStoryTale3Line9Italian, gJiminyStoryTale3Line10Italian, gJiminyStoryTale3Line11Italian,
    gJiminyStoryTale3Line12Italian, gJiminyStoryTale3Line13Italian, gJiminyStoryTale3Line14Italian, gJiminyStoryTale3Line15Italian,
    gJiminyStoryTale3Line16Italian, gJiminyStoryTale3Line17Italian, gJiminyStoryTale3Line18Italian, gJiminyStoryTale3Line19Italian,
    gJiminyStoryTale3Line20Italian, gJiminyStoryTale3Line21Italian,
};

const JiminyTextChar* gJiminyStoryTale3LinesSpanish[20] = {
    gJiminyStoryTale3Line0Spanish, gJiminyStoryTale3Line1Spanish, gJiminyStoryTale3Line2Spanish, gJiminyStoryTale3Line3Spanish,
    gJiminyStoryTale3Line4Spanish, gJiminyStoryTale3Line5Spanish, gJiminyStoryTale3Line6Spanish, gJiminyStoryTale3Line7Spanish,
    gJiminyStoryTale3Line8Spanish, gJiminyStoryTale3Line9Spanish, gJiminyStoryTale3Line10Spanish, gJiminyStoryTale3Line11Spanish,
    gJiminyStoryTale3Line12Spanish, gJiminyStoryTale3Line13Spanish, gJiminyStoryTale3Line14Spanish, gJiminyStoryTale3Line15Spanish,
    gJiminyStoryTale3Line16Spanish, gJiminyStoryTale3Line17Spanish, gJiminyStoryTale3Line18Spanish, gJiminyStoryTale3Line19Spanish,
};

const JiminyTextChar* gJiminyStoryTale4Lines[22] = {
    gJiminyStoryTale4Line0, gJiminyStoryTale4Line1, gJiminyStoryTale4Line2, gJiminyStoryTale4Line3,
    gJiminyStoryTale4Line4, gJiminyStoryTale4Line5, gJiminyStoryTale4Line6, gJiminyStoryTale4Line7,
    gJiminyStoryTale4Line8, gJiminyStoryTale4Line9, gJiminyStoryTale4Line10, gJiminyStoryTale4Line11,
    gJiminyStoryTale4Line12, gJiminyStoryTale4Line13, gJiminyStoryTale4Line14, gJiminyStoryTale4Line15,
    gJiminyStoryTale4Line16, gJiminyStoryTale4Line17, gJiminyStoryTale4Line18, gJiminyStoryTale4Line19,
    gJiminyStoryTale4Line20, gJiminyStoryTale4Line21,
};

const JiminyTextChar* gJiminyStoryTale4LinesFrench[23] = {
    gJiminyStoryTale4Line0French, gJiminyStoryTale4Line1French, gJiminyStoryTale4Line2French, gJiminyStoryTale4Line3French,
    gJiminyStoryTale4Line4French, gJiminyStoryTale4Line5French, gJiminyStoryTale4Line6French, gJiminyStoryTale4Line7French,
    gJiminyStoryTale4Line8French, gJiminyStoryTale4Line9French, gJiminyStoryTale4Line10French, gJiminyStoryTale4Line11French,
    gJiminyStoryTale4Line12French, gJiminyStoryTale4Line13French, gJiminyStoryTale4Line14French, gJiminyStoryTale4Line15French,
    gJiminyStoryTale4Line16French, gJiminyStoryTale4Line17French, gJiminyStoryTale4Line18French, gJiminyStoryTale4Line19French,
    gJiminyStoryTale4Line20French, gJiminyStoryTale4Line21French, gJiminyStoryTale4Line22French,
};

const JiminyTextChar* gJiminyStoryTale4LinesGerman[30] = {
    gJiminyStoryTale4Line0German, gJiminyStoryTale4Line1German, gJiminyStoryTale4Line2German, gJiminyStoryTale4Line3German,
    gJiminyStoryTale4Line4German, gJiminyStoryTale4Line5German, gJiminyStoryTale4Line6German, gJiminyStoryTale4Line7German,
    gJiminyStoryTale4Line8German, gJiminyStoryTale4Line9German, gJiminyStoryTale4Line10German, gJiminyStoryTale4Line11German,
    gJiminyStoryTale4Line12German, gJiminyStoryTale4Line13German, gJiminyStoryTale4Line14German, gJiminyStoryTale4Line15German,
    gJiminyStoryTale4Line16German, gJiminyStoryTale4Line17German, gJiminyStoryTale4Line18German, gJiminyStoryTale4Line19German,
    gJiminyStoryTale4Line20German, gJiminyStoryTale4Line21German, gJiminyStoryTale4Line22German, gJiminyStoryTale4Line23German,
    gJiminyStoryTale4Line24German, gJiminyStoryTale4Line25German, gJiminyStoryTale4Line26German, gJiminyStoryTale4Line27German,
    gJiminyStoryTale4Line28German, gJiminyStoryTale4Line29German,
};

const JiminyTextChar* gJiminyStoryTale4LinesItalian[30] = {
    gJiminyStoryTale4Line0Italian, gJiminyStoryTale4Line1Italian, gJiminyStoryTale4Line2Italian, gJiminyStoryTale4Line3Italian,
    gJiminyStoryTale4Line4Italian, gJiminyStoryTale4Line5Italian, gJiminyStoryTale4Line6Italian, gJiminyStoryTale4Line7Italian,
    gJiminyStoryTale4Line8Italian, gJiminyStoryTale4Line9Italian, gJiminyStoryTale4Line10Italian, gJiminyStoryTale4Line11Italian,
    gJiminyStoryTale4Line12Italian, gJiminyStoryTale4Line13Italian, gJiminyStoryTale4Line14Italian, gJiminyStoryTale4Line15Italian,
    gJiminyStoryTale4Line16Italian, gJiminyStoryTale4Line17Italian, gJiminyStoryTale4Line18Italian, gJiminyStoryTale4Line19Italian,
    gJiminyStoryTale4Line20Italian, gJiminyStoryTale4Line21Italian, gJiminyStoryTale4Line22Italian, gJiminyStoryTale4Line23Italian,
    gJiminyStoryTale4Line24Italian, gJiminyStoryTale4Line25Italian, gJiminyStoryTale4Line26Italian, gJiminyStoryTale4Line27Italian,
    gJiminyStoryTale4Line28Italian, gJiminyStoryTale4Line29Italian,
};

const JiminyTextChar* gJiminyStoryTale4LinesSpanish[26] = {
    gJiminyStoryTale4Line0Spanish, gJiminyStoryTale4Line1Spanish, gJiminyStoryTale4Line2Spanish, gJiminyStoryTale4Line3Spanish,
    gJiminyStoryTale4Line4Spanish, gJiminyStoryTale4Line5Spanish, gJiminyStoryTale4Line6Spanish, gJiminyStoryTale4Line7Spanish,
    gJiminyStoryTale4Line8Spanish, gJiminyStoryTale4Line9Spanish, gJiminyStoryTale4Line10Spanish, gJiminyStoryTale4Line11Spanish,
    gJiminyStoryTale4Line12Spanish, gJiminyStoryTale4Line13Spanish, gJiminyStoryTale4Line14Spanish, gJiminyStoryTale4Line15Spanish,
    gJiminyStoryTale4Line16Spanish, gJiminyStoryTale4Line17Spanish, gJiminyStoryTale4Line18Spanish, gJiminyStoryTale4Line19Spanish,
    gJiminyStoryTale4Line20Spanish, gJiminyStoryTale4Line21Spanish, gJiminyStoryTale4Line22Spanish, gJiminyStoryTale4Line23Spanish,
    gJiminyStoryTale4Line24Spanish, gJiminyStoryTale4Line25Spanish,
};

const JiminyTextChar* gJiminyStoryTraverseTownLines[20] = {
    gJiminyStoryTraverseTownLine0, gJiminyStoryTraverseTownLine1, gJiminyStoryTraverseTownLine2, gJiminyStoryTraverseTownLine3,
    gJiminyStoryTraverseTownLine4, gJiminyStoryTraverseTownLine5, gJiminyStoryTraverseTownLine6, gJiminyStoryTraverseTownLine7,
    gJiminyStoryTraverseTownLine8, gJiminyStoryTraverseTownLine9, gJiminyStoryTraverseTownLine10, gJiminyStoryTraverseTownLine11,
    gJiminyStoryTraverseTownLine12, gJiminyStoryTraverseTownLine13, gJiminyStoryTraverseTownLine14, gJiminyStoryTraverseTownLine15,
    gJiminyStoryTraverseTownLine16, gJiminyStoryTraverseTownLine17, gJiminyStoryTraverseTownLine18, gJiminyStoryTraverseTownLine19,
};

const JiminyTextChar* gJiminyStoryTraverseTownLinesFrench[21] = {
    gJiminyStoryTraverseTownLine0French, gJiminyStoryTraverseTownLine1French, gJiminyStoryTraverseTownLine2French, gJiminyStoryTraverseTownLine3French,
    gJiminyStoryTraverseTownLine4French, gJiminyStoryTraverseTownLine5French, gJiminyStoryTraverseTownLine6French, gJiminyStoryTraverseTownLine7French,
    gJiminyStoryTraverseTownLine8French, gJiminyStoryTraverseTownLine9French, gJiminyStoryTraverseTownLine10French, gJiminyStoryTraverseTownLine11French,
    gJiminyStoryTraverseTownLine12French, gJiminyStoryTraverseTownLine13French, gJiminyStoryTraverseTownLine14French, gJiminyStoryTraverseTownLine15French,
    gJiminyStoryTraverseTownLine16French, gJiminyStoryTraverseTownLine17French, gJiminyStoryTraverseTownLine18French, gJiminyStoryTraverseTownLine19French,
    gJiminyStoryTraverseTownLine20French,
};

const JiminyTextChar* gJiminyStoryTraverseTownLinesGerman[25] = {
    gJiminyStoryTraverseTownLine0German, gJiminyStoryTraverseTownLine1German, gJiminyStoryTraverseTownLine2German, gJiminyStoryTraverseTownLine3German,
    gJiminyStoryTraverseTownLine4German, gJiminyStoryTraverseTownLine5German, gJiminyStoryTraverseTownLine6German, gJiminyStoryTraverseTownLine7German,
    gJiminyStoryTraverseTownLine8German, gJiminyStoryTraverseTownLine9German, gJiminyStoryTraverseTownLine10German, gJiminyStoryTraverseTownLine11German,
    gJiminyStoryTraverseTownLine12German, gJiminyStoryTraverseTownLine13German, gJiminyStoryTraverseTownLine14German, gJiminyStoryTraverseTownLine15German,
    gJiminyStoryTraverseTownLine16German, gJiminyStoryTraverseTownLine17German, gJiminyStoryTraverseTownLine18German, gJiminyStoryTraverseTownLine19German,
    gJiminyStoryTraverseTownLine20German, gJiminyStoryTraverseTownLine21German, gJiminyStoryTraverseTownLine22German, gJiminyStoryTraverseTownLine23German,
    gJiminyStoryTraverseTownLine24German,
};

const JiminyTextChar* gJiminyStoryTraverseTownLinesItalian[25] = {
    gJiminyStoryTraverseTownLine0Italian, gJiminyStoryTraverseTownLine1Italian, gJiminyStoryTraverseTownLine2Italian, gJiminyStoryTraverseTownLine3Italian,
    gJiminyStoryTraverseTownLine4Italian, gJiminyStoryTraverseTownLine5Italian, gJiminyStoryTraverseTownLine6Italian, gJiminyStoryTraverseTownLine7Italian,
    gJiminyStoryTraverseTownLine8Italian, gJiminyStoryTraverseTownLine9Italian, gJiminyStoryTraverseTownLine10Italian, gJiminyStoryTraverseTownLine11Italian,
    gJiminyStoryTraverseTownLine12Italian, gJiminyStoryTraverseTownLine13Italian, gJiminyStoryTraverseTownLine14Italian, gJiminyStoryTraverseTownLine15Italian,
    gJiminyStoryTraverseTownLine16Italian, gJiminyStoryTraverseTownLine17Italian, gJiminyStoryTraverseTownLine18Italian, gJiminyStoryTraverseTownLine19Italian,
    gJiminyStoryTraverseTownLine20Italian, gJiminyStoryTraverseTownLine21Italian, gJiminyStoryTraverseTownLine22Italian, gJiminyStoryTraverseTownLine23Italian,
    gJiminyStoryTraverseTownLine24Italian,
};

const JiminyTextChar* gJiminyStoryTraverseTownLinesSpanish[23] = {
    gJiminyStoryTraverseTownLine0Spanish, gJiminyStoryTraverseTownLine1Spanish, gJiminyStoryTraverseTownLine2Spanish, gJiminyStoryTraverseTownLine3Spanish,
    gJiminyStoryTraverseTownLine4Spanish, gJiminyStoryTraverseTownLine5Spanish, gJiminyStoryTraverseTownLine6Spanish, gJiminyStoryTraverseTownLine7Spanish,
    gJiminyStoryTraverseTownLine8Spanish, gJiminyStoryTraverseTownLine9Spanish, gJiminyStoryTraverseTownLine10Spanish, gJiminyStoryTraverseTownLine11Spanish,
    gJiminyStoryTraverseTownLine12Spanish, gJiminyStoryTraverseTownLine13Spanish, gJiminyStoryTraverseTownLine14Spanish, gJiminyStoryTraverseTownLine15Spanish,
    gJiminyStoryTraverseTownLine16Spanish, gJiminyStoryTraverseTownLine17Spanish, gJiminyStoryTraverseTownLine18Spanish, gJiminyStoryTraverseTownLine19Spanish,
    gJiminyStoryTraverseTownLine20Spanish, gJiminyStoryTraverseTownLine21Spanish, gJiminyStoryTraverseTownLine22Spanish,
};

const JiminyTextChar* gJiminyStoryWonderlandLines[26] = {
    gJiminyStoryWonderlandLine0, gJiminyStoryWonderlandLine1, gJiminyStoryWonderlandLine2, gJiminyStoryWonderlandLine3,
    gJiminyStoryWonderlandLine4, gJiminyStoryWonderlandLine5, gJiminyStoryWonderlandLine6, gJiminyStoryWonderlandLine7,
    gJiminyStoryWonderlandLine8, gJiminyStoryWonderlandLine9, gJiminyStoryWonderlandLine10, gJiminyStoryWonderlandLine11,
    gJiminyStoryWonderlandLine12, gJiminyStoryWonderlandLine13, gJiminyStoryWonderlandLine14, gJiminyStoryWonderlandLine15,
    gJiminyStoryWonderlandLine16, gJiminyStoryWonderlandLine17, gJiminyStoryWonderlandLine18, gJiminyStoryWonderlandLine19,
    gJiminyStoryWonderlandLine20, gJiminyStoryWonderlandLine21, gJiminyStoryWonderlandLine22, gJiminyStoryWonderlandLine23,
    gJiminyStoryWonderlandLine24, gJiminyStoryWonderlandLine25,
};

const JiminyTextChar* gJiminyStoryWonderlandLinesFrench[29] = {
    gJiminyStoryWonderlandLine0French, gJiminyStoryWonderlandLine1French, gJiminyStoryWonderlandLine2French, gJiminyStoryWonderlandLine3French,
    gJiminyStoryWonderlandLine4French, gJiminyStoryWonderlandLine5French, gJiminyStoryWonderlandLine6French, gJiminyStoryWonderlandLine7French,
    gJiminyStoryWonderlandLine8French, gJiminyStoryWonderlandLine9French, gJiminyStoryWonderlandLine10French, gJiminyStoryWonderlandLine11French,
    gJiminyStoryWonderlandLine12French, gJiminyStoryWonderlandLine13French, gJiminyStoryWonderlandLine14French, gJiminyStoryWonderlandLine15French,
    gJiminyStoryWonderlandLine16French, gJiminyStoryWonderlandLine17French, gJiminyStoryWonderlandLine18French, gJiminyStoryWonderlandLine19French,
    gJiminyStoryWonderlandLine20French, gJiminyStoryWonderlandLine21French, gJiminyStoryWonderlandLine22French, gJiminyStoryWonderlandLine23French,
    gJiminyStoryWonderlandLine24French, gJiminyStoryWonderlandLine25French, gJiminyStoryWonderlandLine26French, gJiminyStoryWonderlandLine27French,
    gJiminyStoryWonderlandLine28French,
};

const JiminyTextChar* gJiminyStoryWonderlandLinesGerman[32] = {
    gJiminyStoryWonderlandLine0German, gJiminyStoryWonderlandLine1German, gJiminyStoryWonderlandLine2German, gJiminyStoryWonderlandLine3German,
    gJiminyStoryWonderlandLine4German, gJiminyStoryWonderlandLine5German, gJiminyStoryWonderlandLine6German, gJiminyStoryWonderlandLine7German,
    gJiminyStoryWonderlandLine8German, gJiminyStoryWonderlandLine9German, gJiminyStoryWonderlandLine10German, gJiminyStoryWonderlandLine11German,
    gJiminyStoryWonderlandLine12German, gJiminyStoryWonderlandLine13German, gJiminyStoryWonderlandLine14German, gJiminyStoryWonderlandLine15German,
    gJiminyStoryWonderlandLine16German, gJiminyStoryWonderlandLine17German, gJiminyStoryWonderlandLine18German, gJiminyStoryWonderlandLine19German,
    gJiminyStoryWonderlandLine20German, gJiminyStoryWonderlandLine21German, gJiminyStoryWonderlandLine22German, gJiminyStoryWonderlandLine23German,
    gJiminyStoryWonderlandLine24German, gJiminyStoryWonderlandLine25German, gJiminyStoryWonderlandLine26German, gJiminyStoryWonderlandLine27German,
    gJiminyStoryWonderlandLine28German, gJiminyStoryWonderlandLine29German, gJiminyStoryWonderlandLine30German, gJiminyStoryWonderlandLine31German,
};

const JiminyTextChar* gJiminyStoryWonderlandLinesItalian[31] = {
    gJiminyStoryWonderlandLine0Italian, gJiminyStoryWonderlandLine1Italian, gJiminyStoryWonderlandLine2Italian, gJiminyStoryWonderlandLine3Italian,
    gJiminyStoryWonderlandLine4Italian, gJiminyStoryWonderlandLine5Italian, gJiminyStoryWonderlandLine6Italian, gJiminyStoryWonderlandLine7Italian,
    gJiminyStoryWonderlandLine8Italian, gJiminyStoryWonderlandLine9Italian, gJiminyStoryWonderlandLine10Italian, gJiminyStoryWonderlandLine11Italian,
    gJiminyStoryWonderlandLine12Italian, gJiminyStoryWonderlandLine13Italian, gJiminyStoryWonderlandLine14Italian, gJiminyStoryWonderlandLine15Italian,
    gJiminyStoryWonderlandLine16Italian, gJiminyStoryWonderlandLine17Italian, gJiminyStoryWonderlandLine18Italian, gJiminyStoryWonderlandLine19Italian,
    gJiminyStoryWonderlandLine20Italian, gJiminyStoryWonderlandLine21Italian, gJiminyStoryWonderlandLine22Italian, gJiminyStoryWonderlandLine23Italian,
    gJiminyStoryWonderlandLine24Italian, gJiminyStoryWonderlandLine25Italian, gJiminyStoryWonderlandLine26Italian, gJiminyStoryWonderlandLine27Italian,
    gJiminyStoryWonderlandLine28Italian, gJiminyStoryWonderlandLine29Italian, gJiminyStoryWonderlandLine30Italian,
};

const JiminyTextChar* gJiminyStoryWonderlandLinesSpanish[26] = {
    gJiminyStoryWonderlandLine0Spanish, gJiminyStoryWonderlandLine1Spanish, gJiminyStoryWonderlandLine2Spanish, gJiminyStoryWonderlandLine3Spanish,
    gJiminyStoryWonderlandLine4Spanish, gJiminyStoryWonderlandLine5Spanish, gJiminyStoryWonderlandLine6Spanish, gJiminyStoryWonderlandLine7Spanish,
    gJiminyStoryWonderlandLine8Spanish, gJiminyStoryWonderlandLine9Spanish, gJiminyStoryWonderlandLine10Spanish, gJiminyStoryWonderlandLine11Spanish,
    gJiminyStoryWonderlandLine12Spanish, gJiminyStoryWonderlandLine13Spanish, gJiminyStoryWonderlandLine14Spanish, gJiminyStoryWonderlandLine15Spanish,
    gJiminyStoryWonderlandLine16Spanish, gJiminyStoryWonderlandLine17Spanish, gJiminyStoryWonderlandLine18Spanish, gJiminyStoryWonderlandLine19Spanish,
    gJiminyStoryWonderlandLine20Spanish, gJiminyStoryWonderlandLine21Spanish, gJiminyStoryWonderlandLine22Spanish, gJiminyStoryWonderlandLine23Spanish,
    gJiminyStoryWonderlandLine24Spanish, gJiminyStoryWonderlandLine25Spanish,
};

const JiminyTextChar* gJiminyStoryOlympusColiseumLines[17] = {
    gJiminyStoryOlympusColiseumLine0, gJiminyStoryOlympusColiseumLine1, gJiminyStoryOlympusColiseumLine2, gJiminyStoryOlympusColiseumLine3,
    gJiminyStoryOlympusColiseumLine4, gJiminyStoryOlympusColiseumLine5, gJiminyStoryOlympusColiseumLine6, gJiminyStoryOlympusColiseumLine7,
    gJiminyStoryOlympusColiseumLine8, gJiminyStoryOlympusColiseumLine9, gJiminyStoryOlympusColiseumLine10, gJiminyStoryOlympusColiseumLine11,
    gJiminyStoryOlympusColiseumLine12, gJiminyStoryOlympusColiseumLine13, gJiminyStoryOlympusColiseumLine14, gJiminyStoryOlympusColiseumLine15,
    gJiminyStoryOlympusColiseumLine16,
};

const JiminyTextChar* gJiminyStoryOlympusColiseumLinesFrench[18] = {
    gJiminyStoryOlympusColiseumLine0French, gJiminyStoryOlympusColiseumLine1French, gJiminyStoryOlympusColiseumLine2French, gJiminyStoryOlympusColiseumLine3French,
    gJiminyStoryOlympusColiseumLine4French, gJiminyStoryOlympusColiseumLine5French, gJiminyStoryOlympusColiseumLine6French, gJiminyStoryOlympusColiseumLine7French,
    gJiminyStoryOlympusColiseumLine8French, gJiminyStoryOlympusColiseumLine9French, gJiminyStoryOlympusColiseumLine10French, gJiminyStoryOlympusColiseumLine11French,
    gJiminyStoryOlympusColiseumLine12French, gJiminyStoryOlympusColiseumLine13French, gJiminyStoryOlympusColiseumLine14French, gJiminyStoryOlympusColiseumLine15French,
    gJiminyStoryOlympusColiseumLine16French, gJiminyStoryOlympusColiseumLine17French,
};

const JiminyTextChar* gJiminyStoryOlympusColiseumLinesGerman[24] = {
    gJiminyStoryOlympusColiseumLine0German, gJiminyStoryOlympusColiseumLine1German, gJiminyStoryOlympusColiseumLine2German, gJiminyStoryOlympusColiseumLine3German,
    gJiminyStoryOlympusColiseumLine4German, gJiminyStoryOlympusColiseumLine5German, gJiminyStoryOlympusColiseumLine6German, gJiminyStoryOlympusColiseumLine7German,
    gJiminyStoryOlympusColiseumLine8German, gJiminyStoryOlympusColiseumLine9German, gJiminyStoryOlympusColiseumLine10German, gJiminyStoryOlympusColiseumLine11German,
    gJiminyStoryOlympusColiseumLine12German, gJiminyStoryOlympusColiseumLine13German, gJiminyStoryOlympusColiseumLine14German, gJiminyStoryOlympusColiseumLine15German,
    gJiminyStoryOlympusColiseumLine16German, gJiminyStoryOlympusColiseumLine17German, gJiminyStoryOlympusColiseumLine18German, gJiminyStoryOlympusColiseumLine19German,
    gJiminyStoryOlympusColiseumLine20German, gJiminyStoryOlympusColiseumLine21German, gJiminyStoryOlympusColiseumLine22German, gJiminyStoryOlympusColiseumLine23German,
};

const JiminyTextChar* gJiminyStoryOlympusColiseumLinesItalian[20] = {
    gJiminyStoryOlympusColiseumLine0Italian, gJiminyStoryOlympusColiseumLine1Italian, gJiminyStoryOlympusColiseumLine2Italian, gJiminyStoryOlympusColiseumLine3Italian,
    gJiminyStoryOlympusColiseumLine4Italian, gJiminyStoryOlympusColiseumLine5Italian, gJiminyStoryOlympusColiseumLine6Italian, gJiminyStoryOlympusColiseumLine7Italian,
    gJiminyStoryOlympusColiseumLine8Italian, gJiminyStoryOlympusColiseumLine9Italian, gJiminyStoryOlympusColiseumLine10Italian, gJiminyStoryOlympusColiseumLine11Italian,
    gJiminyStoryOlympusColiseumLine12Italian, gJiminyStoryOlympusColiseumLine13Italian, gJiminyStoryOlympusColiseumLine14Italian, gJiminyStoryOlympusColiseumLine15Italian,
    gJiminyStoryOlympusColiseumLine16Italian, gJiminyStoryOlympusColiseumLine17Italian, gJiminyStoryOlympusColiseumLine18Italian, gJiminyStoryOlympusColiseumLine19Italian,
};

const JiminyTextChar* gJiminyStoryOlympusColiseumLinesSpanish[19] = {
    gJiminyStoryOlympusColiseumLine0Spanish, gJiminyStoryOlympusColiseumLine1Spanish, gJiminyStoryOlympusColiseumLine2Spanish, gJiminyStoryOlympusColiseumLine3Spanish,
    gJiminyStoryOlympusColiseumLine4Spanish, gJiminyStoryOlympusColiseumLine5Spanish, gJiminyStoryOlympusColiseumLine6Spanish, gJiminyStoryOlympusColiseumLine7Spanish,
    gJiminyStoryOlympusColiseumLine8Spanish, gJiminyStoryOlympusColiseumLine9Spanish, gJiminyStoryOlympusColiseumLine10Spanish, gJiminyStoryOlympusColiseumLine11Spanish,
    gJiminyStoryOlympusColiseumLine12Spanish, gJiminyStoryOlympusColiseumLine13Spanish, gJiminyStoryOlympusColiseumLine14Spanish, gJiminyStoryOlympusColiseumLine15Spanish,
    gJiminyStoryOlympusColiseumLine16Spanish, gJiminyStoryOlympusColiseumLine17Spanish, gJiminyStoryOlympusColiseumLine18Spanish,
};

const JiminyTextChar* gJiminyStoryAgrabahLines[32] = {
    gJiminyStoryAgrabahLine0, gJiminyStoryAgrabahLine1, gJiminyStoryAgrabahLine2, gJiminyStoryAgrabahLine3,
    gJiminyStoryAgrabahLine4, gJiminyStoryAgrabahLine5, gJiminyStoryAgrabahLine6, gJiminyStoryAgrabahLine7,
    gJiminyStoryAgrabahLine8, gJiminyStoryAgrabahLine9, gJiminyStoryAgrabahLine10, gJiminyStoryAgrabahLine11,
    gJiminyStoryAgrabahLine12, gJiminyStoryAgrabahLine13, gJiminyStoryAgrabahLine14, gJiminyStoryAgrabahLine15,
    gJiminyStoryAgrabahLine16, gJiminyStoryAgrabahLine17, gJiminyStoryAgrabahLine18, gJiminyStoryAgrabahLine19,
    gJiminyStoryAgrabahLine20, gJiminyStoryAgrabahLine21, gJiminyStoryAgrabahLine22, gJiminyStoryAgrabahLine23,
    gJiminyStoryAgrabahLine24, gJiminyStoryAgrabahLine25, gJiminyStoryAgrabahLine26, gJiminyStoryAgrabahLine27,
    gJiminyStoryAgrabahLine28, gJiminyStoryAgrabahLine29, gJiminyStoryAgrabahLine30, gJiminyStoryAgrabahLine31,
};

const JiminyTextChar* gJiminyStoryAgrabahLinesFrench[32] = {
    gJiminyStoryAgrabahLine0French, gJiminyStoryAgrabahLine1French, gJiminyStoryAgrabahLine2French, gJiminyStoryAgrabahLine3French,
    gJiminyStoryAgrabahLine4French, gJiminyStoryAgrabahLine5French, gJiminyStoryAgrabahLine6French, gJiminyStoryAgrabahLine7French,
    gJiminyStoryAgrabahLine8French, gJiminyStoryAgrabahLine9French, gJiminyStoryAgrabahLine10French, gJiminyStoryAgrabahLine11French,
    gJiminyStoryAgrabahLine12French, gJiminyStoryAgrabahLine13French, gJiminyStoryAgrabahLine14French, gJiminyStoryAgrabahLine15French,
    gJiminyStoryAgrabahLine16French, gJiminyStoryAgrabahLine17French, gJiminyStoryAgrabahLine18French, gJiminyStoryAgrabahLine19French,
    gJiminyStoryAgrabahLine20French, gJiminyStoryAgrabahLine21French, gJiminyStoryAgrabahLine22French, gJiminyStoryAgrabahLine23French,
    gJiminyStoryAgrabahLine24French, gJiminyStoryAgrabahLine25French, gJiminyStoryAgrabahLine26French, gJiminyStoryAgrabahLine27French,
    gJiminyStoryAgrabahLine28French, gJiminyStoryAgrabahLine29French, gJiminyStoryAgrabahLine30French, gJiminyStoryAgrabahLine31French,
};

const JiminyTextChar* gJiminyStoryAgrabahLinesGerman[43] = {
    gJiminyStoryAgrabahLine0German, gJiminyStoryAgrabahLine1German, gJiminyStoryAgrabahLine2German, gJiminyStoryAgrabahLine3German,
    gJiminyStoryAgrabahLine4German, gJiminyStoryAgrabahLine5German, gJiminyStoryAgrabahLine6German, gJiminyStoryAgrabahLine7German,
    gJiminyStoryAgrabahLine8German, gJiminyStoryAgrabahLine9German, gJiminyStoryAgrabahLine10German, gJiminyStoryAgrabahLine11German,
    gJiminyStoryAgrabahLine12German, gJiminyStoryAgrabahLine13German, gJiminyStoryAgrabahLine14German, gJiminyStoryAgrabahLine15German,
    gJiminyStoryAgrabahLine16German, gJiminyStoryAgrabahLine17German, gJiminyStoryAgrabahLine18German, gJiminyStoryAgrabahLine19German,
    gJiminyStoryAgrabahLine20German, gJiminyStoryAgrabahLine21German, gJiminyStoryAgrabahLine22German, gJiminyStoryAgrabahLine23German,
    gJiminyStoryAgrabahLine24German, gJiminyStoryAgrabahLine25German, gJiminyStoryAgrabahLine26German, gJiminyStoryAgrabahLine27German,
    gJiminyStoryAgrabahLine28German, gJiminyStoryAgrabahLine29German, gJiminyStoryAgrabahLine30German, gJiminyStoryAgrabahLine31German,
    gJiminyStoryAgrabahLine32German, gJiminyStoryAgrabahLine33German, gJiminyStoryAgrabahLine34German, gJiminyStoryAgrabahLine35German,
    gJiminyStoryAgrabahLine36German, gJiminyStoryAgrabahLine37German, gJiminyStoryAgrabahLine38German, gJiminyStoryAgrabahLine39German,
    gJiminyStoryAgrabahLine40German, gJiminyStoryAgrabahLine41German, gJiminyStoryAgrabahLine42German,
};

const JiminyTextChar* gJiminyStoryAgrabahLinesItalian[43] = {
    gJiminyStoryAgrabahLine0Italian, gJiminyStoryAgrabahLine1Italian, gJiminyStoryAgrabahLine2Italian, gJiminyStoryAgrabahLine3Italian,
    gJiminyStoryAgrabahLine4Italian, gJiminyStoryAgrabahLine5Italian, gJiminyStoryAgrabahLine6Italian, gJiminyStoryAgrabahLine7Italian,
    gJiminyStoryAgrabahLine8Italian, gJiminyStoryAgrabahLine9Italian, gJiminyStoryAgrabahLine10Italian, gJiminyStoryAgrabahLine11Italian,
    gJiminyStoryAgrabahLine12Italian, gJiminyStoryAgrabahLine13Italian, gJiminyStoryAgrabahLine14Italian, gJiminyStoryAgrabahLine15Italian,
    gJiminyStoryAgrabahLine16Italian, gJiminyStoryAgrabahLine17Italian, gJiminyStoryAgrabahLine18Italian, gJiminyStoryAgrabahLine19Italian,
    gJiminyStoryAgrabahLine20Italian, gJiminyStoryAgrabahLine21Italian, gJiminyStoryAgrabahLine22Italian, gJiminyStoryAgrabahLine23Italian,
    gJiminyStoryAgrabahLine24Italian, gJiminyStoryAgrabahLine25Italian, gJiminyStoryAgrabahLine26Italian, gJiminyStoryAgrabahLine27Italian,
    gJiminyStoryAgrabahLine28Italian, gJiminyStoryAgrabahLine29Italian, gJiminyStoryAgrabahLine30Italian, gJiminyStoryAgrabahLine31Italian,
    gJiminyStoryAgrabahLine32Italian, gJiminyStoryAgrabahLine33Italian, gJiminyStoryAgrabahLine34Italian, gJiminyStoryAgrabahLine35Italian,
    gJiminyStoryAgrabahLine36Italian, gJiminyStoryAgrabahLine37Italian, gJiminyStoryAgrabahLine38Italian, gJiminyStoryAgrabahLine39Italian,
    gJiminyStoryAgrabahLine40Italian, gJiminyStoryAgrabahLine41Italian, gJiminyStoryAgrabahLine42Italian,
};

const JiminyTextChar* gJiminyStoryAgrabahLinesSpanish[34] = {
    gJiminyStoryAgrabahLine0Spanish, gJiminyStoryAgrabahLine1Spanish, gJiminyStoryAgrabahLine2Spanish, gJiminyStoryAgrabahLine3Spanish,
    gJiminyStoryAgrabahLine4Spanish, gJiminyStoryAgrabahLine5Spanish, gJiminyStoryAgrabahLine6Spanish, gJiminyStoryAgrabahLine7Spanish,
    gJiminyStoryAgrabahLine8Spanish, gJiminyStoryAgrabahLine9Spanish, gJiminyStoryAgrabahLine10Spanish, gJiminyStoryAgrabahLine11Spanish,
    gJiminyStoryAgrabahLine12Spanish, gJiminyStoryAgrabahLine13Spanish, gJiminyStoryAgrabahLine14Spanish, gJiminyStoryAgrabahLine15Spanish,
    gJiminyStoryAgrabahLine16Spanish, gJiminyStoryAgrabahLine17Spanish, gJiminyStoryAgrabahLine18Spanish, gJiminyStoryAgrabahLine19Spanish,
    gJiminyStoryAgrabahLine20Spanish, gJiminyStoryAgrabahLine21Spanish, gJiminyStoryAgrabahLine22Spanish, gJiminyStoryAgrabahLine23Spanish,
    gJiminyStoryAgrabahLine24Spanish, gJiminyStoryAgrabahLine25Spanish, gJiminyStoryAgrabahLine26Spanish, gJiminyStoryAgrabahLine27Spanish,
    gJiminyStoryAgrabahLine28Spanish, gJiminyStoryAgrabahLine29Spanish, gJiminyStoryAgrabahLine30Spanish, gJiminyStoryAgrabahLine31Spanish,
    gJiminyStoryAgrabahLine32Spanish, gJiminyStoryAgrabahLine33Spanish,
};

const JiminyTextChar* gJiminyStoryHalloweenTownLines[22] = {
    gJiminyStoryHalloweenTownLine0, gJiminyStoryHalloweenTownLine1, gJiminyStoryHalloweenTownLine2, gJiminyStoryHalloweenTownLine3,
    gJiminyStoryHalloweenTownLine4, gJiminyStoryHalloweenTownLine5, gJiminyStoryHalloweenTownLine6, gJiminyStoryHalloweenTownLine7,
    gJiminyStoryHalloweenTownLine8, gJiminyStoryHalloweenTownLine9, gJiminyStoryHalloweenTownLine10, gJiminyStoryHalloweenTownLine11,
    gJiminyStoryHalloweenTownLine12, gJiminyStoryHalloweenTownLine13, gJiminyStoryHalloweenTownLine14, gJiminyStoryHalloweenTownLine15,
    gJiminyStoryHalloweenTownLine16, gJiminyStoryHalloweenTownLine17, gJiminyStoryHalloweenTownLine18, gJiminyStoryHalloweenTownLine19,
    gJiminyStoryHalloweenTownLine20, gJiminyStoryHalloweenTownLine21,
};

const JiminyTextChar* gJiminyStoryHalloweenTownLinesFrench[27] = {
    gJiminyStoryHalloweenTownLine0French, gJiminyStoryHalloweenTownLine1French, gJiminyStoryHalloweenTownLine2French, gJiminyStoryHalloweenTownLine3French,
    gJiminyStoryHalloweenTownLine4French, gJiminyStoryHalloweenTownLine5French, gJiminyStoryHalloweenTownLine6French, gJiminyStoryHalloweenTownLine7French,
    gJiminyStoryHalloweenTownLine8French, gJiminyStoryHalloweenTownLine9French, gJiminyStoryHalloweenTownLine10French, gJiminyStoryHalloweenTownLine11French,
    gJiminyStoryHalloweenTownLine12French, gJiminyStoryHalloweenTownLine13French, gJiminyStoryHalloweenTownLine14French, gJiminyStoryHalloweenTownLine15French,
    gJiminyStoryHalloweenTownLine16French, gJiminyStoryHalloweenTownLine17French, gJiminyStoryHalloweenTownLine18French, gJiminyStoryHalloweenTownLine19French,
    gJiminyStoryHalloweenTownLine20French, gJiminyStoryHalloweenTownLine21French, gJiminyStoryHalloweenTownLine22French, gJiminyStoryHalloweenTownLine23French,
    gJiminyStoryHalloweenTownLine24French, gJiminyStoryHalloweenTownLine25French, gJiminyStoryHalloweenTownLine26French,
};

const JiminyTextChar* gJiminyStoryHalloweenTownLinesGerman[28] = {
    gJiminyStoryHalloweenTownLine0German, gJiminyStoryHalloweenTownLine1German, gJiminyStoryHalloweenTownLine2German, gJiminyStoryHalloweenTownLine3German,
    gJiminyStoryHalloweenTownLine4German, gJiminyStoryHalloweenTownLine5German, gJiminyStoryHalloweenTownLine6German, gJiminyStoryHalloweenTownLine7German,
    gJiminyStoryHalloweenTownLine8German, gJiminyStoryHalloweenTownLine9German, gJiminyStoryHalloweenTownLine10German, gJiminyStoryHalloweenTownLine11German,
    gJiminyStoryHalloweenTownLine12German, gJiminyStoryHalloweenTownLine13German, gJiminyStoryHalloweenTownLine14German, gJiminyStoryHalloweenTownLine15German,
    gJiminyStoryHalloweenTownLine16German, gJiminyStoryHalloweenTownLine17German, gJiminyStoryHalloweenTownLine18German, gJiminyStoryHalloweenTownLine19German,
    gJiminyStoryHalloweenTownLine20German, gJiminyStoryHalloweenTownLine21German, gJiminyStoryHalloweenTownLine22German, gJiminyStoryHalloweenTownLine23German,
    gJiminyStoryHalloweenTownLine24German, gJiminyStoryHalloweenTownLine25German, gJiminyStoryHalloweenTownLine26German, gJiminyStoryHalloweenTownLine27German,
};

const JiminyTextChar* gJiminyStoryHalloweenTownLinesItalian[27] = {
    gJiminyStoryHalloweenTownLine0Italian, gJiminyStoryHalloweenTownLine1Italian, gJiminyStoryHalloweenTownLine2Italian, gJiminyStoryHalloweenTownLine3Italian,
    gJiminyStoryHalloweenTownLine4Italian, gJiminyStoryHalloweenTownLine5Italian, gJiminyStoryHalloweenTownLine6Italian, gJiminyStoryHalloweenTownLine7Italian,
    gJiminyStoryHalloweenTownLine8Italian, gJiminyStoryHalloweenTownLine9Italian, gJiminyStoryHalloweenTownLine10Italian, gJiminyStoryHalloweenTownLine11Italian,
    gJiminyStoryHalloweenTownLine12Italian, gJiminyStoryHalloweenTownLine13Italian, gJiminyStoryHalloweenTownLine14Italian, gJiminyStoryHalloweenTownLine15Italian,
    gJiminyStoryHalloweenTownLine16Italian, gJiminyStoryHalloweenTownLine17Italian, gJiminyStoryHalloweenTownLine18Italian, gJiminyStoryHalloweenTownLine19Italian,
    gJiminyStoryHalloweenTownLine20Italian, gJiminyStoryHalloweenTownLine21Italian, gJiminyStoryHalloweenTownLine22Italian, gJiminyStoryHalloweenTownLine23Italian,
    gJiminyStoryHalloweenTownLine24Italian, gJiminyStoryHalloweenTownLine25Italian, gJiminyStoryHalloweenTownLine26Italian,
};

const JiminyTextChar* gJiminyStoryHalloweenTownLinesSpanish[24] = {
    gJiminyStoryHalloweenTownLine0Spanish, gJiminyStoryHalloweenTownLine1Spanish, gJiminyStoryHalloweenTownLine2Spanish, gJiminyStoryHalloweenTownLine3Spanish,
    gJiminyStoryHalloweenTownLine4Spanish, gJiminyStoryHalloweenTownLine5Spanish, gJiminyStoryHalloweenTownLine6Spanish, gJiminyStoryHalloweenTownLine7Spanish,
    gJiminyStoryHalloweenTownLine8Spanish, gJiminyStoryHalloweenTownLine9Spanish, gJiminyStoryHalloweenTownLine10Spanish, gJiminyStoryHalloweenTownLine11Spanish,
    gJiminyStoryHalloweenTownLine12Spanish, gJiminyStoryHalloweenTownLine13Spanish, gJiminyStoryHalloweenTownLine14Spanish, gJiminyStoryHalloweenTownLine15Spanish,
    gJiminyStoryHalloweenTownLine16Spanish, gJiminyStoryHalloweenTownLine17Spanish, gJiminyStoryHalloweenTownLine18Spanish, gJiminyStoryHalloweenTownLine19Spanish,
    gJiminyStoryHalloweenTownLine20Spanish, gJiminyStoryHalloweenTownLine21Spanish, gJiminyStoryHalloweenTownLine22Spanish, gJiminyStoryHalloweenTownLine23Spanish,
};

const JiminyTextChar* gJiminyStoryMonstroLines[25] = {
    gJiminyStoryMonstroLine0, gJiminyStoryMonstroLine1, gJiminyStoryMonstroLine2, gJiminyStoryMonstroLine3,
    gJiminyStoryMonstroLine4, gJiminyStoryMonstroLine5, gJiminyStoryMonstroLine6, gJiminyStoryMonstroLine7,
    gJiminyStoryMonstroLine8, gJiminyStoryMonstroLine9, gJiminyStoryMonstroLine10, gJiminyStoryMonstroLine11,
    gJiminyStoryMonstroLine12, gJiminyStoryMonstroLine13, gJiminyStoryMonstroLine14, gJiminyStoryMonstroLine15,
    gJiminyStoryMonstroLine16, gJiminyStoryMonstroLine17, gJiminyStoryMonstroLine18, gJiminyStoryMonstroLine19,
    gJiminyStoryMonstroLine20, gJiminyStoryMonstroLine21, gJiminyStoryMonstroLine22, gJiminyStoryMonstroLine23,
    gJiminyStoryMonstroLine24,
};

const JiminyTextChar* gJiminyStoryMonstroLinesFrench[27] = {
    gJiminyStoryMonstroLine0French, gJiminyStoryMonstroLine1French, gJiminyStoryMonstroLine2French, gJiminyStoryMonstroLine3French,
    gJiminyStoryMonstroLine4French, gJiminyStoryMonstroLine5French, gJiminyStoryMonstroLine6French, gJiminyStoryMonstroLine7French,
    gJiminyStoryMonstroLine8French, gJiminyStoryMonstroLine9French, gJiminyStoryMonstroLine10French, gJiminyStoryMonstroLine11French,
    gJiminyStoryMonstroLine12French, gJiminyStoryMonstroLine13French, gJiminyStoryMonstroLine14French, gJiminyStoryMonstroLine15French,
    gJiminyStoryMonstroLine16French, gJiminyStoryMonstroLine17French, gJiminyStoryMonstroLine18French, gJiminyStoryMonstroLine19French,
    gJiminyStoryMonstroLine20French, gJiminyStoryMonstroLine21French, gJiminyStoryMonstroLine22French, gJiminyStoryMonstroLine23French,
    gJiminyStoryMonstroLine24French, gJiminyStoryMonstroLine25French, gJiminyStoryMonstroLine26French,
};

const JiminyTextChar* gJiminyStoryMonstroLinesGerman[35] = {
    gJiminyStoryMonstroLine0German, gJiminyStoryMonstroLine1German, gJiminyStoryMonstroLine2German, gJiminyStoryMonstroLine3German,
    gJiminyStoryMonstroLine4German, gJiminyStoryMonstroLine5German, gJiminyStoryMonstroLine6German, gJiminyStoryMonstroLine7German,
    gJiminyStoryMonstroLine8German, gJiminyStoryMonstroLine9German, gJiminyStoryMonstroLine10German, gJiminyStoryMonstroLine11German,
    gJiminyStoryMonstroLine12German, gJiminyStoryMonstroLine13German, gJiminyStoryMonstroLine14German, gJiminyStoryMonstroLine15German,
    gJiminyStoryMonstroLine16German, gJiminyStoryMonstroLine17German, gJiminyStoryMonstroLine18German, gJiminyStoryMonstroLine19German,
    gJiminyStoryMonstroLine20German, gJiminyStoryMonstroLine21German, gJiminyStoryMonstroLine22German, gJiminyStoryMonstroLine23German,
    gJiminyStoryMonstroLine24German, gJiminyStoryMonstroLine25German, gJiminyStoryMonstroLine26German, gJiminyStoryMonstroLine27German,
    gJiminyStoryMonstroLine28German, gJiminyStoryMonstroLine29German, gJiminyStoryMonstroLine30German, gJiminyStoryMonstroLine31German,
    gJiminyStoryMonstroLine32German, gJiminyStoryMonstroLine33German, gJiminyStoryMonstroLine34German,
};

const JiminyTextChar* gJiminyStoryMonstroLinesItalian[31] = {
    gJiminyStoryMonstroLine0Italian, gJiminyStoryMonstroLine1Italian, gJiminyStoryMonstroLine2Italian, gJiminyStoryMonstroLine3Italian,
    gJiminyStoryMonstroLine4Italian, gJiminyStoryMonstroLine5Italian, gJiminyStoryMonstroLine6Italian, gJiminyStoryMonstroLine7Italian,
    gJiminyStoryMonstroLine8Italian, gJiminyStoryMonstroLine9Italian, gJiminyStoryMonstroLine10Italian, gJiminyStoryMonstroLine11Italian,
    gJiminyStoryMonstroLine12Italian, gJiminyStoryMonstroLine13Italian, gJiminyStoryMonstroLine14Italian, gJiminyStoryMonstroLine15Italian,
    gJiminyStoryMonstroLine16Italian, gJiminyStoryMonstroLine17Italian, gJiminyStoryMonstroLine18Italian, gJiminyStoryMonstroLine19Italian,
    gJiminyStoryMonstroLine20Italian, gJiminyStoryMonstroLine21Italian, gJiminyStoryMonstroLine22Italian, gJiminyStoryMonstroLine23Italian,
    gJiminyStoryMonstroLine24Italian, gJiminyStoryMonstroLine25Italian, gJiminyStoryMonstroLine26Italian, gJiminyStoryMonstroLine27Italian,
    gJiminyStoryMonstroLine28Italian, gJiminyStoryMonstroLine29Italian, gJiminyStoryMonstroLine30Italian,
};

const JiminyTextChar* gJiminyStoryMonstroLinesSpanish[25] = {
    gJiminyStoryMonstroLine0Spanish, gJiminyStoryMonstroLine1Spanish, gJiminyStoryMonstroLine2Spanish, gJiminyStoryMonstroLine3Spanish,
    gJiminyStoryMonstroLine4Spanish, gJiminyStoryMonstroLine5Spanish, gJiminyStoryMonstroLine6Spanish, gJiminyStoryMonstroLine7Spanish,
    gJiminyStoryMonstroLine8Spanish, gJiminyStoryMonstroLine9Spanish, gJiminyStoryMonstroLine10Spanish, gJiminyStoryMonstroLine11Spanish,
    gJiminyStoryMonstroLine12Spanish, gJiminyStoryMonstroLine13Spanish, gJiminyStoryMonstroLine14Spanish, gJiminyStoryMonstroLine15Spanish,
    gJiminyStoryMonstroLine16Spanish, gJiminyStoryMonstroLine17Spanish, gJiminyStoryMonstroLine18Spanish, gJiminyStoryMonstroLine19Spanish,
    gJiminyStoryMonstroLine20Spanish, gJiminyStoryMonstroLine21Spanish, gJiminyStoryMonstroLine22Spanish, gJiminyStoryMonstroLine23Spanish,
    gJiminyStoryMonstroLine24Spanish,
};

const JiminyTextChar* gJiminyStoryAtlanticaLines[25] = {
    gJiminyStoryAtlanticaLine0, gJiminyStoryAtlanticaLine1, gJiminyStoryAtlanticaLine2, gJiminyStoryAtlanticaLine3,
    gJiminyStoryAtlanticaLine4, gJiminyStoryAtlanticaLine5, gJiminyStoryAtlanticaLine6, gJiminyStoryAtlanticaLine7,
    gJiminyStoryAtlanticaLine8, gJiminyStoryAtlanticaLine9, gJiminyStoryAtlanticaLine10, gJiminyStoryAtlanticaLine11,
    gJiminyStoryAtlanticaLine12, gJiminyStoryAtlanticaLine13, gJiminyStoryAtlanticaLine14, gJiminyStoryAtlanticaLine15,
    gJiminyStoryAtlanticaLine16, gJiminyStoryAtlanticaLine17, gJiminyStoryAtlanticaLine18, gJiminyStoryAtlanticaLine19,
    gJiminyStoryAtlanticaLine20, gJiminyStoryAtlanticaLine21, gJiminyStoryAtlanticaLine22, gJiminyStoryAtlanticaLine23,
    gJiminyStoryAtlanticaLine24,
};

const JiminyTextChar* gJiminyStoryAtlanticaLinesFrench[30] = {
    gJiminyStoryAtlanticaLine0French, gJiminyStoryAtlanticaLine1French, gJiminyStoryAtlanticaLine2French, gJiminyStoryAtlanticaLine3French,
    gJiminyStoryAtlanticaLine4French, gJiminyStoryAtlanticaLine5French, gJiminyStoryAtlanticaLine6French, gJiminyStoryAtlanticaLine7French,
    gJiminyStoryAtlanticaLine8French, gJiminyStoryAtlanticaLine9French, gJiminyStoryAtlanticaLine10French, gJiminyStoryAtlanticaLine11French,
    gJiminyStoryAtlanticaLine12French, gJiminyStoryAtlanticaLine13French, gJiminyStoryAtlanticaLine14French, gJiminyStoryAtlanticaLine15French,
    gJiminyStoryAtlanticaLine16French, gJiminyStoryAtlanticaLine17French, gJiminyStoryAtlanticaLine18French, gJiminyStoryAtlanticaLine19French,
    gJiminyStoryAtlanticaLine20French, gJiminyStoryAtlanticaLine21French, gJiminyStoryAtlanticaLine22French, gJiminyStoryAtlanticaLine23French,
    gJiminyStoryAtlanticaLine24French, gJiminyStoryAtlanticaLine25French, gJiminyStoryAtlanticaLine26French, gJiminyStoryAtlanticaLine27French,
    gJiminyStoryAtlanticaLine28French, gJiminyStoryAtlanticaLine29French,
};

const JiminyTextChar* gJiminyStoryAtlanticaLinesGerman[33] = {
    gJiminyStoryAtlanticaLine0German, gJiminyStoryAtlanticaLine1German, gJiminyStoryAtlanticaLine2German, gJiminyStoryAtlanticaLine3German,
    gJiminyStoryAtlanticaLine4German, gJiminyStoryAtlanticaLine5German, gJiminyStoryAtlanticaLine6German, gJiminyStoryAtlanticaLine7German,
    gJiminyStoryAtlanticaLine8German, gJiminyStoryAtlanticaLine9German, gJiminyStoryAtlanticaLine10German, gJiminyStoryAtlanticaLine11German,
    gJiminyStoryAtlanticaLine12German, gJiminyStoryAtlanticaLine13German, gJiminyStoryAtlanticaLine14German, gJiminyStoryAtlanticaLine15German,
    gJiminyStoryAtlanticaLine16German, gJiminyStoryAtlanticaLine17German, gJiminyStoryAtlanticaLine18German, gJiminyStoryAtlanticaLine19German,
    gJiminyStoryAtlanticaLine20German, gJiminyStoryAtlanticaLine21German, gJiminyStoryAtlanticaLine22German, gJiminyStoryAtlanticaLine23German,
    gJiminyStoryAtlanticaLine24German, gJiminyStoryAtlanticaLine25German, gJiminyStoryAtlanticaLine26German, gJiminyStoryAtlanticaLine27German,
    gJiminyStoryAtlanticaLine28German, gJiminyStoryAtlanticaLine29German, gJiminyStoryAtlanticaLine30German, gJiminyStoryAtlanticaLine31German,
    gJiminyStoryAtlanticaLine32German,
};

const JiminyTextChar* gJiminyStoryAtlanticaLinesItalian[34] = {
    gJiminyStoryAtlanticaLine0Italian, gJiminyStoryAtlanticaLine1Italian, gJiminyStoryAtlanticaLine2Italian, gJiminyStoryAtlanticaLine3Italian,
    gJiminyStoryAtlanticaLine4Italian, gJiminyStoryAtlanticaLine5Italian, gJiminyStoryAtlanticaLine6Italian, gJiminyStoryAtlanticaLine7Italian,
    gJiminyStoryAtlanticaLine8Italian, gJiminyStoryAtlanticaLine9Italian, gJiminyStoryAtlanticaLine10Italian, gJiminyStoryAtlanticaLine11Italian,
    gJiminyStoryAtlanticaLine12Italian, gJiminyStoryAtlanticaLine13Italian, gJiminyStoryAtlanticaLine14Italian, gJiminyStoryAtlanticaLine15Italian,
    gJiminyStoryAtlanticaLine16Italian, gJiminyStoryAtlanticaLine17Italian, gJiminyStoryAtlanticaLine18Italian, gJiminyStoryAtlanticaLine19Italian,
    gJiminyStoryAtlanticaLine20Italian, gJiminyStoryAtlanticaLine21Italian, gJiminyStoryAtlanticaLine22Italian, gJiminyStoryAtlanticaLine23Italian,
    gJiminyStoryAtlanticaLine24Italian, gJiminyStoryAtlanticaLine25Italian, gJiminyStoryAtlanticaLine26Italian, gJiminyStoryAtlanticaLine27Italian,
    gJiminyStoryAtlanticaLine28Italian, gJiminyStoryAtlanticaLine29Italian, gJiminyStoryAtlanticaLine30Italian, gJiminyStoryAtlanticaLine31Italian,
    gJiminyStoryAtlanticaLine32Italian, gJiminyStoryAtlanticaLine33Italian,
};

const JiminyTextChar* gJiminyStoryAtlanticaLinesSpanish[27] = {
    gJiminyStoryAtlanticaLine0Spanish, gJiminyStoryAtlanticaLine1Spanish, gJiminyStoryAtlanticaLine2Spanish, gJiminyStoryAtlanticaLine3Spanish,
    gJiminyStoryAtlanticaLine4Spanish, gJiminyStoryAtlanticaLine5Spanish, gJiminyStoryAtlanticaLine6Spanish, gJiminyStoryAtlanticaLine7Spanish,
    gJiminyStoryAtlanticaLine8Spanish, gJiminyStoryAtlanticaLine9Spanish, gJiminyStoryAtlanticaLine10Spanish, gJiminyStoryAtlanticaLine11Spanish,
    gJiminyStoryAtlanticaLine12Spanish, gJiminyStoryAtlanticaLine13Spanish, gJiminyStoryAtlanticaLine14Spanish, gJiminyStoryAtlanticaLine15Spanish,
    gJiminyStoryAtlanticaLine16Spanish, gJiminyStoryAtlanticaLine17Spanish, gJiminyStoryAtlanticaLine18Spanish, gJiminyStoryAtlanticaLine19Spanish,
    gJiminyStoryAtlanticaLine20Spanish, gJiminyStoryAtlanticaLine21Spanish, gJiminyStoryAtlanticaLine22Spanish, gJiminyStoryAtlanticaLine23Spanish,
    gJiminyStoryAtlanticaLine24Spanish, gJiminyStoryAtlanticaLine25Spanish, gJiminyStoryAtlanticaLine26Spanish,
};

const JiminyTextChar* gJiminyStoryNeverLandLines[27] = {
    gJiminyStoryNeverLandLine0, gJiminyStoryNeverLandLine1, gJiminyStoryNeverLandLine2, gJiminyStoryNeverLandLine3,
    gJiminyStoryNeverLandLine4, gJiminyStoryNeverLandLine5, gJiminyStoryNeverLandLine6, gJiminyStoryNeverLandLine7,
    gJiminyStoryNeverLandLine8, gJiminyStoryNeverLandLine9, gJiminyStoryNeverLandLine10, gJiminyStoryNeverLandLine11,
    gJiminyStoryNeverLandLine12, gJiminyStoryNeverLandLine13, gJiminyStoryNeverLandLine14, gJiminyStoryNeverLandLine15,
    gJiminyStoryNeverLandLine16, gJiminyStoryNeverLandLine17, gJiminyStoryNeverLandLine18, gJiminyStoryNeverLandLine19,
    gJiminyStoryNeverLandLine20, gJiminyStoryNeverLandLine21, gJiminyStoryNeverLandLine22, gJiminyStoryNeverLandLine23,
    gJiminyStoryNeverLandLine24, gJiminyStoryNeverLandLine25, gJiminyStoryNeverLandLine26,
};

const JiminyTextChar* gJiminyStoryNeverLandLinesFrench[30] = {
    gJiminyStoryNeverLandLine0French, gJiminyStoryNeverLandLine1French, gJiminyStoryNeverLandLine2French, gJiminyStoryNeverLandLine3French,
    gJiminyStoryNeverLandLine4French, gJiminyStoryNeverLandLine5French, gJiminyStoryNeverLandLine6French, gJiminyStoryNeverLandLine7French,
    gJiminyStoryNeverLandLine8French, gJiminyStoryNeverLandLine9French, gJiminyStoryNeverLandLine10French, gJiminyStoryNeverLandLine11French,
    gJiminyStoryNeverLandLine12French, gJiminyStoryNeverLandLine13French, gJiminyStoryNeverLandLine14French, gJiminyStoryNeverLandLine15French,
    gJiminyStoryNeverLandLine16French, gJiminyStoryNeverLandLine17French, gJiminyStoryNeverLandLine18French, gJiminyStoryNeverLandLine19French,
    gJiminyStoryNeverLandLine20French, gJiminyStoryNeverLandLine21French, gJiminyStoryNeverLandLine22French, gJiminyStoryNeverLandLine23French,
    gJiminyStoryNeverLandLine24French, gJiminyStoryNeverLandLine25French, gJiminyStoryNeverLandLine26French, gJiminyStoryNeverLandLine27French,
    gJiminyStoryNeverLandLine28French, gJiminyStoryNeverLandLine29French,
};

const JiminyTextChar* gJiminyStoryNeverLandLinesGerman[35] = {
    gJiminyStoryNeverLandLine0German, gJiminyStoryNeverLandLine1German, gJiminyStoryNeverLandLine2German, gJiminyStoryNeverLandLine3German,
    gJiminyStoryNeverLandLine4German, gJiminyStoryNeverLandLine5German, gJiminyStoryNeverLandLine6German, gJiminyStoryNeverLandLine7German,
    gJiminyStoryNeverLandLine8German, gJiminyStoryNeverLandLine9German, gJiminyStoryNeverLandLine10German, gJiminyStoryNeverLandLine11German,
    gJiminyStoryNeverLandLine12German, gJiminyStoryNeverLandLine13German, gJiminyStoryNeverLandLine14German, gJiminyStoryNeverLandLine15German,
    gJiminyStoryNeverLandLine16German, gJiminyStoryNeverLandLine17German, gJiminyStoryNeverLandLine18German, gJiminyStoryNeverLandLine19German,
    gJiminyStoryNeverLandLine20German, gJiminyStoryNeverLandLine21German, gJiminyStoryNeverLandLine22German, gJiminyStoryNeverLandLine23German,
    gJiminyStoryNeverLandLine24German, gJiminyStoryNeverLandLine25German, gJiminyStoryNeverLandLine26German, gJiminyStoryNeverLandLine27German,
    gJiminyStoryNeverLandLine28German, gJiminyStoryNeverLandLine29German, gJiminyStoryNeverLandLine30German, gJiminyStoryNeverLandLine31German,
    gJiminyStoryNeverLandLine32German, gJiminyStoryNeverLandLine33German, gJiminyStoryNeverLandLine34German,
};

const JiminyTextChar* gJiminyStoryNeverLandLinesItalian[33] = {
    gJiminyStoryNeverLandLine0Italian, gJiminyStoryNeverLandLine1Italian, gJiminyStoryNeverLandLine2Italian, gJiminyStoryNeverLandLine3Italian,
    gJiminyStoryNeverLandLine4Italian, gJiminyStoryNeverLandLine5Italian, gJiminyStoryNeverLandLine6Italian, gJiminyStoryNeverLandLine7Italian,
    gJiminyStoryNeverLandLine8Italian, gJiminyStoryNeverLandLine9Italian, gJiminyStoryNeverLandLine10Italian, gJiminyStoryNeverLandLine11Italian,
    gJiminyStoryNeverLandLine12Italian, gJiminyStoryNeverLandLine13Italian, gJiminyStoryNeverLandLine14Italian, gJiminyStoryNeverLandLine15Italian,
    gJiminyStoryNeverLandLine16Italian, gJiminyStoryNeverLandLine17Italian, gJiminyStoryNeverLandLine18Italian, gJiminyStoryNeverLandLine19Italian,
    gJiminyStoryNeverLandLine20Italian, gJiminyStoryNeverLandLine21Italian, gJiminyStoryNeverLandLine22Italian, gJiminyStoryNeverLandLine23Italian,
    gJiminyStoryNeverLandLine24Italian, gJiminyStoryNeverLandLine25Italian, gJiminyStoryNeverLandLine26Italian, gJiminyStoryNeverLandLine27Italian,
    gJiminyStoryNeverLandLine28Italian, gJiminyStoryNeverLandLine29Italian, gJiminyStoryNeverLandLine30Italian, gJiminyStoryNeverLandLine31Italian,
    gJiminyStoryNeverLandLine32Italian,
};

const JiminyTextChar* gJiminyStoryNeverLandLinesSpanish[27] = {
    gJiminyStoryNeverLandLine0Spanish, gJiminyStoryNeverLandLine1Spanish, gJiminyStoryNeverLandLine2Spanish, gJiminyStoryNeverLandLine3Spanish,
    gJiminyStoryNeverLandLine4Spanish, gJiminyStoryNeverLandLine5Spanish, gJiminyStoryNeverLandLine6Spanish, gJiminyStoryNeverLandLine7Spanish,
    gJiminyStoryNeverLandLine8Spanish, gJiminyStoryNeverLandLine9Spanish, gJiminyStoryNeverLandLine10Spanish, gJiminyStoryNeverLandLine11Spanish,
    gJiminyStoryNeverLandLine12Spanish, gJiminyStoryNeverLandLine13Spanish, gJiminyStoryNeverLandLine14Spanish, gJiminyStoryNeverLandLine15Spanish,
    gJiminyStoryNeverLandLine16Spanish, gJiminyStoryNeverLandLine17Spanish, gJiminyStoryNeverLandLine18Spanish, gJiminyStoryNeverLandLine19Spanish,
    gJiminyStoryNeverLandLine20Spanish, gJiminyStoryNeverLandLine21Spanish, gJiminyStoryNeverLandLine22Spanish, gJiminyStoryNeverLandLine23Spanish,
    gJiminyStoryNeverLandLine24Spanish, gJiminyStoryNeverLandLine25Spanish, gJiminyStoryNeverLandLine26Spanish,
};

const JiminyTextChar* gJiminyStoryHollowBastionLines[25] = {
    gJiminyStoryHollowBastionLine0, gJiminyStoryHollowBastionLine1, gJiminyStoryHollowBastionLine2, gJiminyStoryHollowBastionLine3,
    gJiminyStoryHollowBastionLine4, gJiminyStoryHollowBastionLine5, gJiminyStoryHollowBastionLine6, gJiminyStoryHollowBastionLine7,
    gJiminyStoryHollowBastionLine8, gJiminyStoryHollowBastionLine9, gJiminyStoryHollowBastionLine10, gJiminyStoryHollowBastionLine11,
    gJiminyStoryHollowBastionLine12, gJiminyStoryHollowBastionLine13, gJiminyStoryHollowBastionLine14, gJiminyStoryHollowBastionLine15,
    gJiminyStoryHollowBastionLine16, gJiminyStoryHollowBastionLine17, gJiminyStoryHollowBastionLine18, gJiminyStoryHollowBastionLine19,
    gJiminyStoryHollowBastionLine20, gJiminyStoryHollowBastionLine21, gJiminyStoryHollowBastionLine22, gJiminyStoryHollowBastionLine23,
    gJiminyStoryHollowBastionLine24,
};

const JiminyTextChar* gJiminyStoryHollowBastionLinesFrench[27] = {
    gJiminyStoryHollowBastionLine0French, gJiminyStoryHollowBastionLine1French, gJiminyStoryHollowBastionLine2French, gJiminyStoryHollowBastionLine3French,
    gJiminyStoryHollowBastionLine4French, gJiminyStoryHollowBastionLine5French, gJiminyStoryHollowBastionLine6French, gJiminyStoryHollowBastionLine7French,
    gJiminyStoryHollowBastionLine8French, gJiminyStoryHollowBastionLine9French, gJiminyStoryHollowBastionLine10French, gJiminyStoryHollowBastionLine11French,
    gJiminyStoryHollowBastionLine12French, gJiminyStoryHollowBastionLine13French, gJiminyStoryHollowBastionLine14French, gJiminyStoryHollowBastionLine15French,
    gJiminyStoryHollowBastionLine16French, gJiminyStoryHollowBastionLine17French, gJiminyStoryHollowBastionLine18French, gJiminyStoryHollowBastionLine19French,
    gJiminyStoryHollowBastionLine20French, gJiminyStoryHollowBastionLine21French, gJiminyStoryHollowBastionLine22French, gJiminyStoryHollowBastionLine23French,
    gJiminyStoryHollowBastionLine24French, gJiminyStoryHollowBastionLine25French, gJiminyStoryHollowBastionLine26French,
};

const JiminyTextChar* gJiminyStoryHollowBastionLinesGerman[31] = {
    gJiminyStoryHollowBastionLine0German, gJiminyStoryHollowBastionLine1German, gJiminyStoryHollowBastionLine2German, gJiminyStoryHollowBastionLine3German,
    gJiminyStoryHollowBastionLine4German, gJiminyStoryHollowBastionLine5German, gJiminyStoryHollowBastionLine6German, gJiminyStoryHollowBastionLine7German,
    gJiminyStoryHollowBastionLine8German, gJiminyStoryHollowBastionLine9German, gJiminyStoryHollowBastionLine10German, gJiminyStoryHollowBastionLine11German,
    gJiminyStoryHollowBastionLine12German, gJiminyStoryHollowBastionLine13German, gJiminyStoryHollowBastionLine14German, gJiminyStoryHollowBastionLine15German,
    gJiminyStoryHollowBastionLine16German, gJiminyStoryHollowBastionLine17German, gJiminyStoryHollowBastionLine18German, gJiminyStoryHollowBastionLine19German,
    gJiminyStoryHollowBastionLine20German, gJiminyStoryHollowBastionLine21German, gJiminyStoryHollowBastionLine22German, gJiminyStoryHollowBastionLine23German,
    gJiminyStoryHollowBastionLine24German, gJiminyStoryHollowBastionLine25German, gJiminyStoryHollowBastionLine26German, gJiminyStoryHollowBastionLine27German,
    gJiminyStoryHollowBastionLine28German, gJiminyStoryHollowBastionLine29German, gJiminyStoryHollowBastionLine30German,
};

const JiminyTextChar* gJiminyStoryHollowBastionLinesItalian[29] = {
    gJiminyStoryHollowBastionLine0Italian, gJiminyStoryHollowBastionLine1Italian, gJiminyStoryHollowBastionLine2Italian, gJiminyStoryHollowBastionLine3Italian,
    gJiminyStoryHollowBastionLine4Italian, gJiminyStoryHollowBastionLine5Italian, gJiminyStoryHollowBastionLine6Italian, gJiminyStoryHollowBastionLine7Italian,
    gJiminyStoryHollowBastionLine8Italian, gJiminyStoryHollowBastionLine9Italian, gJiminyStoryHollowBastionLine10Italian, gJiminyStoryHollowBastionLine11Italian,
    gJiminyStoryHollowBastionLine12Italian, gJiminyStoryHollowBastionLine13Italian, gJiminyStoryHollowBastionLine14Italian, gJiminyStoryHollowBastionLine15Italian,
    gJiminyStoryHollowBastionLine16Italian, gJiminyStoryHollowBastionLine17Italian, gJiminyStoryHollowBastionLine18Italian, gJiminyStoryHollowBastionLine19Italian,
    gJiminyStoryHollowBastionLine20Italian, gJiminyStoryHollowBastionLine21Italian, gJiminyStoryHollowBastionLine22Italian, gJiminyStoryHollowBastionLine23Italian,
    gJiminyStoryHollowBastionLine24Italian, gJiminyStoryHollowBastionLine25Italian, gJiminyStoryHollowBastionLine26Italian, gJiminyStoryHollowBastionLine27Italian,
    gJiminyStoryHollowBastionLine28Italian,
};

const JiminyTextChar* gJiminyStoryHollowBastionLinesSpanish[26] = {
    gJiminyStoryHollowBastionLine0Spanish, gJiminyStoryHollowBastionLine1Spanish, gJiminyStoryHollowBastionLine2Spanish, gJiminyStoryHollowBastionLine3Spanish,
    gJiminyStoryHollowBastionLine4Spanish, gJiminyStoryHollowBastionLine5Spanish, gJiminyStoryHollowBastionLine6Spanish, gJiminyStoryHollowBastionLine7Spanish,
    gJiminyStoryHollowBastionLine8Spanish, gJiminyStoryHollowBastionLine9Spanish, gJiminyStoryHollowBastionLine10Spanish, gJiminyStoryHollowBastionLine11Spanish,
    gJiminyStoryHollowBastionLine12Spanish, gJiminyStoryHollowBastionLine13Spanish, gJiminyStoryHollowBastionLine14Spanish, gJiminyStoryHollowBastionLine15Spanish,
    gJiminyStoryHollowBastionLine16Spanish, gJiminyStoryHollowBastionLine17Spanish, gJiminyStoryHollowBastionLine18Spanish, gJiminyStoryHollowBastionLine19Spanish,
    gJiminyStoryHollowBastionLine20Spanish, gJiminyStoryHollowBastionLine21Spanish, gJiminyStoryHollowBastionLine22Spanish, gJiminyStoryHollowBastionLine23Spanish,
    gJiminyStoryHollowBastionLine24Spanish, gJiminyStoryHollowBastionLine25Spanish,
};

const JiminyTextChar* gJiminyStory100AcreWoodLines[9] = {
    gJiminyStory100AcreWoodLine0, gJiminyStory100AcreWoodLine1, gJiminyStory100AcreWoodLine2, gJiminyStory100AcreWoodLine3,
    gJiminyStory100AcreWoodLine4, gJiminyStory100AcreWoodLine5, gJiminyStory100AcreWoodLine6, gJiminyStory100AcreWoodLine7,
    gJiminyStory100AcreWoodLine8,
};

const JiminyTextChar* gJiminyStory100AcreWoodLinesFrench[10] = {
    gJiminyStory100AcreWoodLine0French, gJiminyStory100AcreWoodLine1French, gJiminyStory100AcreWoodLine2French, gJiminyStory100AcreWoodLine3French,
    gJiminyStory100AcreWoodLine4French, gJiminyStory100AcreWoodLine5French, gJiminyStory100AcreWoodLine6French, gJiminyStory100AcreWoodLine7French,
    gJiminyStory100AcreWoodLine8French, gJiminyStory100AcreWoodLine9French,
};

const JiminyTextChar* gJiminyStory100AcreWoodLinesGerman[12] = {
    gJiminyStory100AcreWoodLine0German, gJiminyStory100AcreWoodLine1German, gJiminyStory100AcreWoodLine2German, gJiminyStory100AcreWoodLine3German,
    gJiminyStory100AcreWoodLine4German, gJiminyStory100AcreWoodLine5German, gJiminyStory100AcreWoodLine6German, gJiminyStory100AcreWoodLine7German,
    gJiminyStory100AcreWoodLine8German, gJiminyStory100AcreWoodLine9German, gJiminyStory100AcreWoodLine10German, gJiminyStory100AcreWoodLine11German,
};

const JiminyTextChar* gJiminyStory100AcreWoodLinesItalian[9] = {
    gJiminyStory100AcreWoodLine0Italian, gJiminyStory100AcreWoodLine1Italian, gJiminyStory100AcreWoodLine2Italian, gJiminyStory100AcreWoodLine3Italian,
    gJiminyStory100AcreWoodLine4Italian, gJiminyStory100AcreWoodLine5Italian, gJiminyStory100AcreWoodLine6Italian, gJiminyStory100AcreWoodLine7Italian,
    gJiminyStory100AcreWoodLine8Italian,
};

const JiminyTextChar* gJiminyStory100AcreWoodLinesSpanish[11] = {
    gJiminyStory100AcreWoodLine0Spanish, gJiminyStory100AcreWoodLine1Spanish, gJiminyStory100AcreWoodLine2Spanish, gJiminyStory100AcreWoodLine3Spanish,
    gJiminyStory100AcreWoodLine4Spanish, gJiminyStory100AcreWoodLine5Spanish, gJiminyStory100AcreWoodLine6Spanish, gJiminyStory100AcreWoodLine7Spanish,
    gJiminyStory100AcreWoodLine8Spanish, gJiminyStory100AcreWoodLine9Spanish, gJiminyStory100AcreWoodLine10Spanish,
};

const JiminyTextChar* gJiminyStoryTwilightTownLines[15] = {
    gJiminyStoryTwilightTownLine0, gJiminyStoryTwilightTownLine1, gJiminyStoryTwilightTownLine2, gJiminyStoryTwilightTownLine3,
    gJiminyStoryTwilightTownLine4, gJiminyStoryTwilightTownLine5, gJiminyStoryTwilightTownLine6, gJiminyStoryTwilightTownLine7,
    gJiminyStoryTwilightTownLine8, gJiminyStoryTwilightTownLine9, gJiminyStoryTwilightTownLine10, gJiminyStoryTwilightTownLine11,
    gJiminyStoryTwilightTownLine12, gJiminyStoryTwilightTownLine13, gJiminyStoryTwilightTownLine14,
};

const JiminyTextChar* gJiminyStoryTwilightTownLinesFrench[16] = {
    gJiminyStoryTwilightTownLine0French, gJiminyStoryTwilightTownLine1French, gJiminyStoryTwilightTownLine2French, gJiminyStoryTwilightTownLine3French,
    gJiminyStoryTwilightTownLine4French, gJiminyStoryTwilightTownLine5French, gJiminyStoryTwilightTownLine6French, gJiminyStoryTwilightTownLine7French,
    gJiminyStoryTwilightTownLine8French, gJiminyStoryTwilightTownLine9French, gJiminyStoryTwilightTownLine10French, gJiminyStoryTwilightTownLine11French,
    gJiminyStoryTwilightTownLine12French, gJiminyStoryTwilightTownLine13French, gJiminyStoryTwilightTownLine14French, gJiminyStoryTwilightTownLine15French,
};

const JiminyTextChar* gJiminyStoryTwilightTownLinesGerman[21] = {
    gJiminyStoryTwilightTownLine0German, gJiminyStoryTwilightTownLine1German, gJiminyStoryTwilightTownLine2German, gJiminyStoryTwilightTownLine3German,
    gJiminyStoryTwilightTownLine4German, gJiminyStoryTwilightTownLine5German, gJiminyStoryTwilightTownLine6German, gJiminyStoryTwilightTownLine7German,
    gJiminyStoryTwilightTownLine8German, gJiminyStoryTwilightTownLine9German, gJiminyStoryTwilightTownLine10German, gJiminyStoryTwilightTownLine11German,
    gJiminyStoryTwilightTownLine12German, gJiminyStoryTwilightTownLine13German, gJiminyStoryTwilightTownLine14German, gJiminyStoryTwilightTownLine15German,
    gJiminyStoryTwilightTownLine16German, gJiminyStoryTwilightTownLine17German, gJiminyStoryTwilightTownLine18German, gJiminyStoryTwilightTownLine19German,
    gJiminyStoryTwilightTownLine20German,
};

const JiminyTextChar* gJiminyStoryTwilightTownLinesItalian[17] = {
    gJiminyStoryTwilightTownLine0Italian, gJiminyStoryTwilightTownLine1Italian, gJiminyStoryTwilightTownLine2Italian, gJiminyStoryTwilightTownLine3Italian,
    gJiminyStoryTwilightTownLine4Italian, gJiminyStoryTwilightTownLine5Italian, gJiminyStoryTwilightTownLine6Italian, gJiminyStoryTwilightTownLine7Italian,
    gJiminyStoryTwilightTownLine8Italian, gJiminyStoryTwilightTownLine9Italian, gJiminyStoryTwilightTownLine10Italian, gJiminyStoryTwilightTownLine11Italian,
    gJiminyStoryTwilightTownLine12Italian, gJiminyStoryTwilightTownLine13Italian, gJiminyStoryTwilightTownLine14Italian, gJiminyStoryTwilightTownLine15Italian,
    gJiminyStoryTwilightTownLine16Italian,
};

const JiminyTextChar* gJiminyStoryTwilightTownLinesSpanish[16] = {
    gJiminyStoryTwilightTownLine0Spanish, gJiminyStoryTwilightTownLine1Spanish, gJiminyStoryTwilightTownLine2Spanish, gJiminyStoryTwilightTownLine3Spanish,
    gJiminyStoryTwilightTownLine4Spanish, gJiminyStoryTwilightTownLine5Spanish, gJiminyStoryTwilightTownLine6Spanish, gJiminyStoryTwilightTownLine7Spanish,
    gJiminyStoryTwilightTownLine8Spanish, gJiminyStoryTwilightTownLine9Spanish, gJiminyStoryTwilightTownLine10Spanish, gJiminyStoryTwilightTownLine11Spanish,
    gJiminyStoryTwilightTownLine12Spanish, gJiminyStoryTwilightTownLine13Spanish, gJiminyStoryTwilightTownLine14Spanish, gJiminyStoryTwilightTownLine15Spanish,
};

const JiminyTextChar* gJiminyStoryDestinyIslandsLines[16] = {
    gJiminyStoryDestinyIslandsLine0, gJiminyStoryDestinyIslandsLine1, gJiminyStoryDestinyIslandsLine2, gJiminyStoryDestinyIslandsLine3,
    gJiminyStoryDestinyIslandsLine4, gJiminyStoryDestinyIslandsLine5, gJiminyStoryDestinyIslandsLine6, gJiminyStoryDestinyIslandsLine7,
    gJiminyStoryDestinyIslandsLine8, gJiminyStoryDestinyIslandsLine9, gJiminyStoryDestinyIslandsLine10, gJiminyStoryDestinyIslandsLine11,
    gJiminyStoryDestinyIslandsLine12, gJiminyStoryDestinyIslandsLine13, gJiminyStoryDestinyIslandsLine14, gJiminyStoryDestinyIslandsLine15,
};

const JiminyTextChar* gJiminyStoryDestinyIslandsLinesFrench[15] = {
    gJiminyStoryDestinyIslandsLine0French, gJiminyStoryDestinyIslandsLine1French, gJiminyStoryDestinyIslandsLine2French, gJiminyStoryDestinyIslandsLine3French,
    gJiminyStoryDestinyIslandsLine4French, gJiminyStoryDestinyIslandsLine5French, gJiminyStoryDestinyIslandsLine6French, gJiminyStoryDestinyIslandsLine7French,
    gJiminyStoryDestinyIslandsLine8French, gJiminyStoryDestinyIslandsLine9French, gJiminyStoryDestinyIslandsLine10French, gJiminyStoryDestinyIslandsLine11French,
    gJiminyStoryDestinyIslandsLine12French, gJiminyStoryDestinyIslandsLine13French, gJiminyStoryDestinyIslandsLine14French,
};

const JiminyTextChar* gJiminyStoryDestinyIslandsLinesGerman[17] = {
    gJiminyStoryDestinyIslandsLine0German, gJiminyStoryDestinyIslandsLine1German, gJiminyStoryDestinyIslandsLine2German, gJiminyStoryDestinyIslandsLine3German,
    gJiminyStoryDestinyIslandsLine4German, gJiminyStoryDestinyIslandsLine5German, gJiminyStoryDestinyIslandsLine6German, gJiminyStoryDestinyIslandsLine7German,
    gJiminyStoryDestinyIslandsLine8German, gJiminyStoryDestinyIslandsLine9German, gJiminyStoryDestinyIslandsLine10German, gJiminyStoryDestinyIslandsLine11German,
    gJiminyStoryDestinyIslandsLine12German, gJiminyStoryDestinyIslandsLine13German, gJiminyStoryDestinyIslandsLine14German, gJiminyStoryDestinyIslandsLine15German,
    gJiminyStoryDestinyIslandsLine16German,
};

const JiminyTextChar* gJiminyStoryDestinyIslandsLinesItalian[18] = {
    gJiminyStoryDestinyIslandsLine0Italian, gJiminyStoryDestinyIslandsLine1Italian, gJiminyStoryDestinyIslandsLine2Italian, gJiminyStoryDestinyIslandsLine3Italian,
    gJiminyStoryDestinyIslandsLine4Italian, gJiminyStoryDestinyIslandsLine5Italian, gJiminyStoryDestinyIslandsLine6Italian, gJiminyStoryDestinyIslandsLine7Italian,
    gJiminyStoryDestinyIslandsLine8Italian, gJiminyStoryDestinyIslandsLine9Italian, gJiminyStoryDestinyIslandsLine10Italian, gJiminyStoryDestinyIslandsLine11Italian,
    gJiminyStoryDestinyIslandsLine12Italian, gJiminyStoryDestinyIslandsLine13Italian, gJiminyStoryDestinyIslandsLine14Italian, gJiminyStoryDestinyIslandsLine15Italian,
    gJiminyStoryDestinyIslandsLine16Italian, gJiminyStoryDestinyIslandsLine17Italian,
};

const JiminyTextChar* gJiminyStoryDestinyIslandsLinesSpanish[15] = {
    gJiminyStoryDestinyIslandsLine0Spanish, gJiminyStoryDestinyIslandsLine1Spanish, gJiminyStoryDestinyIslandsLine2Spanish, gJiminyStoryDestinyIslandsLine3Spanish,
    gJiminyStoryDestinyIslandsLine4Spanish, gJiminyStoryDestinyIslandsLine5Spanish, gJiminyStoryDestinyIslandsLine6Spanish, gJiminyStoryDestinyIslandsLine7Spanish,
    gJiminyStoryDestinyIslandsLine8Spanish, gJiminyStoryDestinyIslandsLine9Spanish, gJiminyStoryDestinyIslandsLine10Spanish, gJiminyStoryDestinyIslandsLine11Spanish,
    gJiminyStoryDestinyIslandsLine12Spanish, gJiminyStoryDestinyIslandsLine13Spanish, gJiminyStoryDestinyIslandsLine14Spanish,
};

const JiminyTextChar* gJiminyStoryCastleOblivionLines[24] = {
    gJiminyStoryCastleOblivionLine0, gJiminyStoryCastleOblivionLine1, gJiminyStoryCastleOblivionLine2, gJiminyStoryCastleOblivionLine3,
    gJiminyStoryCastleOblivionLine4, gJiminyStoryCastleOblivionLine5, gJiminyStoryCastleOblivionLine6, gJiminyStoryCastleOblivionLine7,
    gJiminyStoryCastleOblivionLine8, gJiminyStoryCastleOblivionLine9, gJiminyStoryCastleOblivionLine10, gJiminyStoryCastleOblivionLine11,
    gJiminyStoryCastleOblivionLine12, gJiminyStoryCastleOblivionLine13, gJiminyStoryCastleOblivionLine14, gJiminyStoryCastleOblivionLine15,
    gJiminyStoryCastleOblivionLine16, gJiminyStoryCastleOblivionLine17, gJiminyStoryCastleOblivionLine18, gJiminyStoryCastleOblivionLine19,
    gJiminyStoryCastleOblivionLine20, gJiminyStoryCastleOblivionLine21, gJiminyStoryCastleOblivionLine22, gJiminyStoryCastleOblivionLine23,
};

const JiminyTextChar* gJiminyStoryCastleOblivionLinesFrench[28] = {
    gJiminyStoryCastleOblivionLine0French, gJiminyStoryCastleOblivionLine1French, gJiminyStoryCastleOblivionLine2French, gJiminyStoryCastleOblivionLine3French,
    gJiminyStoryCastleOblivionLine4French, gJiminyStoryCastleOblivionLine5French, gJiminyStoryCastleOblivionLine6French, gJiminyStoryCastleOblivionLine7French,
    gJiminyStoryCastleOblivionLine8French, gJiminyStoryCastleOblivionLine9French, gJiminyStoryCastleOblivionLine10French, gJiminyStoryCastleOblivionLine11French,
    gJiminyStoryCastleOblivionLine12French, gJiminyStoryCastleOblivionLine13French, gJiminyStoryCastleOblivionLine14French, gJiminyStoryCastleOblivionLine15French,
    gJiminyStoryCastleOblivionLine16French, gJiminyStoryCastleOblivionLine17French, gJiminyStoryCastleOblivionLine18French, gJiminyStoryCastleOblivionLine19French,
    gJiminyStoryCastleOblivionLine20French, gJiminyStoryCastleOblivionLine21French, gJiminyStoryCastleOblivionLine22French, gJiminyStoryCastleOblivionLine23French,
    gJiminyStoryCastleOblivionLine24French, gJiminyStoryCastleOblivionLine25French, gJiminyStoryCastleOblivionLine26French, gJiminyStoryCastleOblivionLine27French,
};

const JiminyTextChar* gJiminyStoryCastleOblivionLinesGerman[32] = {
    gJiminyStoryCastleOblivionLine0German, gJiminyStoryCastleOblivionLine1German, gJiminyStoryCastleOblivionLine2German, gJiminyStoryCastleOblivionLine3German,
    gJiminyStoryCastleOblivionLine4German, gJiminyStoryCastleOblivionLine5German, gJiminyStoryCastleOblivionLine6German, gJiminyStoryCastleOblivionLine7German,
    gJiminyStoryCastleOblivionLine8German, gJiminyStoryCastleOblivionLine9German, gJiminyStoryCastleOblivionLine10German, gJiminyStoryCastleOblivionLine11German,
    gJiminyStoryCastleOblivionLine12German, gJiminyStoryCastleOblivionLine13German, gJiminyStoryCastleOblivionLine14German, gJiminyStoryCastleOblivionLine15German,
    gJiminyStoryCastleOblivionLine16German, gJiminyStoryCastleOblivionLine17German, gJiminyStoryCastleOblivionLine18German, gJiminyStoryCastleOblivionLine19German,
    gJiminyStoryCastleOblivionLine20German, gJiminyStoryCastleOblivionLine21German, gJiminyStoryCastleOblivionLine22German, gJiminyStoryCastleOblivionLine23German,
    gJiminyStoryCastleOblivionLine24German, gJiminyStoryCastleOblivionLine25German, gJiminyStoryCastleOblivionLine26German, gJiminyStoryCastleOblivionLine27German,
    gJiminyStoryCastleOblivionLine28German, gJiminyStoryCastleOblivionLine29German, gJiminyStoryCastleOblivionLine30German, gJiminyStoryCastleOblivionLine31German,
};

const JiminyTextChar* gJiminyStoryCastleOblivionLinesItalian[29] = {
    gJiminyStoryCastleOblivionLine0Italian, gJiminyStoryCastleOblivionLine1Italian, gJiminyStoryCastleOblivionLine2Italian, gJiminyStoryCastleOblivionLine3Italian,
    gJiminyStoryCastleOblivionLine4Italian, gJiminyStoryCastleOblivionLine5Italian, gJiminyStoryCastleOblivionLine6Italian, gJiminyStoryCastleOblivionLine7Italian,
    gJiminyStoryCastleOblivionLine8Italian, gJiminyStoryCastleOblivionLine9Italian, gJiminyStoryCastleOblivionLine10Italian, gJiminyStoryCastleOblivionLine11Italian,
    gJiminyStoryCastleOblivionLine12Italian, gJiminyStoryCastleOblivionLine13Italian, gJiminyStoryCastleOblivionLine14Italian, gJiminyStoryCastleOblivionLine15Italian,
    gJiminyStoryCastleOblivionLine16Italian, gJiminyStoryCastleOblivionLine17Italian, gJiminyStoryCastleOblivionLine18Italian, gJiminyStoryCastleOblivionLine19Italian,
    gJiminyStoryCastleOblivionLine20Italian, gJiminyStoryCastleOblivionLine21Italian, gJiminyStoryCastleOblivionLine22Italian, gJiminyStoryCastleOblivionLine23Italian,
    gJiminyStoryCastleOblivionLine24Italian, gJiminyStoryCastleOblivionLine25Italian, gJiminyStoryCastleOblivionLine26Italian, gJiminyStoryCastleOblivionLine27Italian,
    gJiminyStoryCastleOblivionLine28Italian,
};

const JiminyTextChar* gJiminyStoryCastleOblivionLinesSpanish[29] = {
    gJiminyStoryCastleOblivionLine0Spanish, gJiminyStoryCastleOblivionLine1Spanish, gJiminyStoryCastleOblivionLine2Spanish, gJiminyStoryCastleOblivionLine3Spanish,
    gJiminyStoryCastleOblivionLine4Spanish, gJiminyStoryCastleOblivionLine5Spanish, gJiminyStoryCastleOblivionLine6Spanish, gJiminyStoryCastleOblivionLine7Spanish,
    gJiminyStoryCastleOblivionLine8Spanish, gJiminyStoryCastleOblivionLine9Spanish, gJiminyStoryCastleOblivionLine10Spanish, gJiminyStoryCastleOblivionLine11Spanish,
    gJiminyStoryCastleOblivionLine12Spanish, gJiminyStoryCastleOblivionLine13Spanish, gJiminyStoryCastleOblivionLine14Spanish, gJiminyStoryCastleOblivionLine15Spanish,
    gJiminyStoryCastleOblivionLine16Spanish, gJiminyStoryCastleOblivionLine17Spanish, gJiminyStoryCastleOblivionLine18Spanish, gJiminyStoryCastleOblivionLine19Spanish,
    gJiminyStoryCastleOblivionLine20Spanish, gJiminyStoryCastleOblivionLine21Spanish, gJiminyStoryCastleOblivionLine22Spanish, gJiminyStoryCastleOblivionLine23Spanish,
    gJiminyStoryCastleOblivionLine24Spanish, gJiminyStoryCastleOblivionLine25Spanish, gJiminyStoryCastleOblivionLine26Spanish, gJiminyStoryCastleOblivionLine27Spanish,
    gJiminyStoryCastleOblivionLine28Spanish,
};

const JiminyTextChar* gJiminyRikuStoryTale1Lines[41] = {
    gJiminyRikuStoryTale1Line0, gJiminyRikuStoryTale1Line1, gJiminyRikuStoryTale1Line2, gJiminyRikuStoryTale1Line3,
    gJiminyRikuStoryTale1Line4, gJiminyRikuStoryTale1Line5, gJiminyRikuStoryTale1Line6, gJiminyRikuStoryTale1Line7,
    gJiminyRikuStoryTale1Line8, gJiminyRikuStoryTale1Line9, gJiminyRikuStoryTale1Line10, gJiminyRikuStoryTale1Line11,
    gJiminyRikuStoryTale1Line12, gJiminyRikuStoryTale1Line13, gJiminyRikuStoryTale1Line14, gJiminyRikuStoryTale1Line15,
    gJiminyRikuStoryTale1Line16, gJiminyRikuStoryTale1Line17, gJiminyRikuStoryTale1Line18, gJiminyRikuStoryTale1Line19,
    gJiminyRikuStoryTale1Line20, gJiminyRikuStoryTale1Line21, gJiminyRikuStoryTale1Line22, gJiminyRikuStoryTale1Line23,
    gJiminyRikuStoryTale1Line24, gJiminyRikuStoryTale1Line25, gJiminyRikuStoryTale1Line26, gJiminyRikuStoryTale1Line27,
    gJiminyRikuStoryTale1Line28, gJiminyRikuStoryTale1Line29, gJiminyRikuStoryTale1Line30, gJiminyRikuStoryTale1Line31,
    gJiminyRikuStoryTale1Line32, gJiminyRikuStoryTale1Line33, gJiminyRikuStoryTale1Line34, gJiminyRikuStoryTale1Line35,
    gJiminyRikuStoryTale1Line36, gJiminyRikuStoryTale1Line37, gJiminyRikuStoryTale1Line38, gJiminyRikuStoryTale1Line39,
    gJiminyRikuStoryTale1Line40,
};

const JiminyTextChar* gJiminyRikuStoryTale1LinesFrench[42] = {
    gJiminyRikuStoryTale1Line0French, gJiminyRikuStoryTale1Line1French, gJiminyRikuStoryTale1Line2French, gJiminyRikuStoryTale1Line3French,
    gJiminyRikuStoryTale1Line4French, gJiminyRikuStoryTale1Line5French, gJiminyRikuStoryTale1Line6French, gJiminyRikuStoryTale1Line7French,
    gJiminyRikuStoryTale1Line8French, gJiminyRikuStoryTale1Line9French, gJiminyRikuStoryTale1Line10French, gJiminyRikuStoryTale1Line11French,
    gJiminyRikuStoryTale1Line12French, gJiminyRikuStoryTale1Line13French, gJiminyRikuStoryTale1Line14French, gJiminyRikuStoryTale1Line15French,
    gJiminyRikuStoryTale1Line16French, gJiminyRikuStoryTale1Line17French, gJiminyRikuStoryTale1Line18French, gJiminyRikuStoryTale1Line19French,
    gJiminyRikuStoryTale1Line20French, gJiminyRikuStoryTale1Line21French, gJiminyRikuStoryTale1Line22French, gJiminyRikuStoryTale1Line23French,
    gJiminyRikuStoryTale1Line24French, gJiminyRikuStoryTale1Line25French, gJiminyRikuStoryTale1Line26French, gJiminyRikuStoryTale1Line27French,
    gJiminyRikuStoryTale1Line28French, gJiminyRikuStoryTale1Line29French, gJiminyRikuStoryTale1Line30French, gJiminyRikuStoryTale1Line31French,
    gJiminyRikuStoryTale1Line32French, gJiminyRikuStoryTale1Line33French, gJiminyRikuStoryTale1Line34French, gJiminyRikuStoryTale1Line35French,
    gJiminyRikuStoryTale1Line36French, gJiminyRikuStoryTale1Line37French, gJiminyRikuStoryTale1Line38French, gJiminyRikuStoryTale1Line39French,
    gJiminyRikuStoryTale1Line40French, gJiminyRikuStoryTale1Line41French,
};

const JiminyTextChar* gJiminyRikuStoryTale1LinesGerman[54] = {
    gJiminyRikuStoryTale1Line0German, gJiminyRikuStoryTale1Line1German, gJiminyRikuStoryTale1Line2German, gJiminyRikuStoryTale1Line3German,
    gJiminyRikuStoryTale1Line4German, gJiminyRikuStoryTale1Line5German, gJiminyRikuStoryTale1Line6German, gJiminyRikuStoryTale1Line7German,
    gJiminyRikuStoryTale1Line8German, gJiminyRikuStoryTale1Line9German, gJiminyRikuStoryTale1Line10German, gJiminyRikuStoryTale1Line11German,
    gJiminyRikuStoryTale1Line12German, gJiminyRikuStoryTale1Line13German, gJiminyRikuStoryTale1Line14German, gJiminyRikuStoryTale1Line15German,
    gJiminyRikuStoryTale1Line16German, gJiminyRikuStoryTale1Line17German, gJiminyRikuStoryTale1Line18German, gJiminyRikuStoryTale1Line19German,
    gJiminyRikuStoryTale1Line20German, gJiminyRikuStoryTale1Line21German, gJiminyRikuStoryTale1Line22German, gJiminyRikuStoryTale1Line23German,
    gJiminyRikuStoryTale1Line24German, gJiminyRikuStoryTale1Line25German, gJiminyRikuStoryTale1Line26German, gJiminyRikuStoryTale1Line27German,
    gJiminyRikuStoryTale1Line28German, gJiminyRikuStoryTale1Line29German, gJiminyRikuStoryTale1Line30German, gJiminyRikuStoryTale1Line31German,
    gJiminyRikuStoryTale1Line32German, gJiminyRikuStoryTale1Line33German, gJiminyRikuStoryTale1Line34German, gJiminyRikuStoryTale1Line35German,
    gJiminyRikuStoryTale1Line36German, gJiminyRikuStoryTale1Line37German, gJiminyRikuStoryTale1Line38German, gJiminyRikuStoryTale1Line39German,
    gJiminyRikuStoryTale1Line40German, gJiminyRikuStoryTale1Line41German, gJiminyRikuStoryTale1Line42German, gJiminyRikuStoryTale1Line43German,
    gJiminyRikuStoryTale1Line44German, gJiminyRikuStoryTale1Line45German, gJiminyRikuStoryTale1Line46German, gJiminyRikuStoryTale1Line47German,
    gJiminyRikuStoryTale1Line48German, gJiminyRikuStoryTale1Line49German, gJiminyRikuStoryTale1Line50German, gJiminyRikuStoryTale1Line51German,
    gJiminyRikuStoryTale1Line52German, gJiminyRikuStoryTale1Line53German,
};

const JiminyTextChar* gJiminyRikuStoryTale1LinesItalian[47] = {
    gJiminyRikuStoryTale1Line0Italian, gJiminyRikuStoryTale1Line1Italian, gJiminyRikuStoryTale1Line2Italian, gJiminyRikuStoryTale1Line3Italian,
    gJiminyRikuStoryTale1Line4Italian, gJiminyRikuStoryTale1Line5Italian, gJiminyRikuStoryTale1Line6Italian, gJiminyRikuStoryTale1Line7Italian,
    gJiminyRikuStoryTale1Line8Italian, gJiminyRikuStoryTale1Line9Italian, gJiminyRikuStoryTale1Line10Italian, gJiminyRikuStoryTale1Line11Italian,
    gJiminyRikuStoryTale1Line12Italian, gJiminyRikuStoryTale1Line13Italian, gJiminyRikuStoryTale1Line14Italian, gJiminyRikuStoryTale1Line15Italian,
    gJiminyRikuStoryTale1Line16Italian, gJiminyRikuStoryTale1Line17Italian, gJiminyRikuStoryTale1Line18Italian, gJiminyRikuStoryTale1Line19Italian,
    gJiminyRikuStoryTale1Line20Italian, gJiminyRikuStoryTale1Line21Italian, gJiminyRikuStoryTale1Line22Italian, gJiminyRikuStoryTale1Line23Italian,
    gJiminyRikuStoryTale1Line24Italian, gJiminyRikuStoryTale1Line25Italian, gJiminyRikuStoryTale1Line26Italian, gJiminyRikuStoryTale1Line27Italian,
    gJiminyRikuStoryTale1Line28Italian, gJiminyRikuStoryTale1Line29Italian, gJiminyRikuStoryTale1Line30Italian, gJiminyRikuStoryTale1Line31Italian,
    gJiminyRikuStoryTale1Line32Italian, gJiminyRikuStoryTale1Line33Italian, gJiminyRikuStoryTale1Line34Italian, gJiminyRikuStoryTale1Line35Italian,
    gJiminyRikuStoryTale1Line36Italian, gJiminyRikuStoryTale1Line37Italian, gJiminyRikuStoryTale1Line38Italian, gJiminyRikuStoryTale1Line39Italian,
    gJiminyRikuStoryTale1Line40Italian, gJiminyRikuStoryTale1Line41Italian, gJiminyRikuStoryTale1Line42Italian, gJiminyRikuStoryTale1Line43Italian,
    gJiminyRikuStoryTale1Line44Italian, gJiminyRikuStoryTale1Line45Italian, gJiminyRikuStoryTale1Line46Italian,
};

const JiminyTextChar* gJiminyRikuStoryTale1LinesSpanish[43] = {
    gJiminyRikuStoryTale1Line0Spanish, gJiminyRikuStoryTale1Line1Spanish, gJiminyRikuStoryTale1Line2Spanish, gJiminyRikuStoryTale1Line3Spanish,
    gJiminyRikuStoryTale1Line4Spanish, gJiminyRikuStoryTale1Line5Spanish, gJiminyRikuStoryTale1Line6Spanish, gJiminyRikuStoryTale1Line7Spanish,
    gJiminyRikuStoryTale1Line8Spanish, gJiminyRikuStoryTale1Line9Spanish, gJiminyRikuStoryTale1Line10Spanish, gJiminyRikuStoryTale1Line11Spanish,
    gJiminyRikuStoryTale1Line12Spanish, gJiminyRikuStoryTale1Line13Spanish, gJiminyRikuStoryTale1Line14Spanish, gJiminyRikuStoryTale1Line15Spanish,
    gJiminyRikuStoryTale1Line16Spanish, gJiminyRikuStoryTale1Line17Spanish, gJiminyRikuStoryTale1Line18Spanish, gJiminyRikuStoryTale1Line19Spanish,
    gJiminyRikuStoryTale1Line20Spanish, gJiminyRikuStoryTale1Line21Spanish, gJiminyRikuStoryTale1Line22Spanish, gJiminyRikuStoryTale1Line23Spanish,
    gJiminyRikuStoryTale1Line24Spanish, gJiminyRikuStoryTale1Line25Spanish, gJiminyRikuStoryTale1Line26Spanish, gJiminyRikuStoryTale1Line27Spanish,
    gJiminyRikuStoryTale1Line28Spanish, gJiminyRikuStoryTale1Line29Spanish, gJiminyRikuStoryTale1Line30Spanish, gJiminyRikuStoryTale1Line31Spanish,
    gJiminyRikuStoryTale1Line32Spanish, gJiminyRikuStoryTale1Line33Spanish, gJiminyRikuStoryTale1Line34Spanish, gJiminyRikuStoryTale1Line35Spanish,
    gJiminyRikuStoryTale1Line36Spanish, gJiminyRikuStoryTale1Line37Spanish, gJiminyRikuStoryTale1Line38Spanish, gJiminyRikuStoryTale1Line39Spanish,
    gJiminyRikuStoryTale1Line40Spanish, gJiminyRikuStoryTale1Line41Spanish, gJiminyRikuStoryTale1Line42Spanish,
};

const JiminyTextChar* gJiminyRikuStoryTale2Lines[26] = {
    gJiminyRikuStoryTale2Line0, gJiminyRikuStoryTale2Line1, gJiminyRikuStoryTale2Line2, gJiminyRikuStoryTale2Line3,
    gJiminyRikuStoryTale2Line4, gJiminyRikuStoryTale2Line5, gJiminyRikuStoryTale2Line6, gJiminyRikuStoryTale2Line7,
    gJiminyRikuStoryTale2Line8, gJiminyRikuStoryTale2Line9, gJiminyRikuStoryTale2Line10, gJiminyRikuStoryTale2Line11,
    gJiminyRikuStoryTale2Line12, gJiminyRikuStoryTale2Line13, gJiminyRikuStoryTale2Line14, gJiminyRikuStoryTale2Line15,
    gJiminyRikuStoryTale2Line16, gJiminyRikuStoryTale2Line17, gJiminyRikuStoryTale2Line18, gJiminyRikuStoryTale2Line19,
    gJiminyRikuStoryTale2Line20, gJiminyRikuStoryTale2Line21, gJiminyRikuStoryTale2Line22, gJiminyRikuStoryTale2Line23,
    gJiminyRikuStoryTale2Line24, gJiminyRikuStoryTale2Line25,
};

const JiminyTextChar* gJiminyRikuStoryTale2LinesFrench[34] = {
    gJiminyRikuStoryTale2Line0French, gJiminyRikuStoryTale2Line1French, gJiminyRikuStoryTale2Line2French, gJiminyRikuStoryTale2Line3French,
    gJiminyRikuStoryTale2Line4French, gJiminyRikuStoryTale2Line5French, gJiminyRikuStoryTale2Line6French, gJiminyRikuStoryTale2Line7French,
    gJiminyRikuStoryTale2Line8French, gJiminyRikuStoryTale2Line9French, gJiminyRikuStoryTale2Line10French, gJiminyRikuStoryTale2Line11French,
    gJiminyRikuStoryTale2Line12French, gJiminyRikuStoryTale2Line13French, gJiminyRikuStoryTale2Line14French, gJiminyRikuStoryTale2Line15French,
    gJiminyRikuStoryTale2Line16French, gJiminyRikuStoryTale2Line17French, gJiminyRikuStoryTale2Line18French, gJiminyRikuStoryTale2Line19French,
    gJiminyRikuStoryTale2Line20French, gJiminyRikuStoryTale2Line21French, gJiminyRikuStoryTale2Line22French, gJiminyRikuStoryTale2Line23French,
    gJiminyRikuStoryTale2Line24French, gJiminyRikuStoryTale2Line25French, gJiminyRikuStoryTale2Line26French, gJiminyRikuStoryTale2Line27French,
    gJiminyRikuStoryTale2Line28French, gJiminyRikuStoryTale2Line29French, gJiminyRikuStoryTale2Line30French, gJiminyRikuStoryTale2Line31French,
    gJiminyRikuStoryTale2Line32French, gJiminyRikuStoryTale2Line33French,
};

const JiminyTextChar* gJiminyRikuStoryTale2LinesGerman[35] = {
    gJiminyRikuStoryTale2Line0German, gJiminyRikuStoryTale2Line1German, gJiminyRikuStoryTale2Line2German, gJiminyRikuStoryTale2Line3German,
    gJiminyRikuStoryTale2Line4German, gJiminyRikuStoryTale2Line5German, gJiminyRikuStoryTale2Line6German, gJiminyRikuStoryTale2Line7German,
    gJiminyRikuStoryTale2Line8German, gJiminyRikuStoryTale2Line9German, gJiminyRikuStoryTale2Line10German, gJiminyRikuStoryTale2Line11German,
    gJiminyRikuStoryTale2Line12German, gJiminyRikuStoryTale2Line13German, gJiminyRikuStoryTale2Line14German, gJiminyRikuStoryTale2Line15German,
    gJiminyRikuStoryTale2Line16German, gJiminyRikuStoryTale2Line17German, gJiminyRikuStoryTale2Line18German, gJiminyRikuStoryTale2Line19German,
    gJiminyRikuStoryTale2Line20German, gJiminyRikuStoryTale2Line21German, gJiminyRikuStoryTale2Line22German, gJiminyRikuStoryTale2Line23German,
    gJiminyRikuStoryTale2Line24German, gJiminyRikuStoryTale2Line25German, gJiminyRikuStoryTale2Line26German, gJiminyRikuStoryTale2Line27German,
    gJiminyRikuStoryTale2Line28German, gJiminyRikuStoryTale2Line29German, gJiminyRikuStoryTale2Line30German, gJiminyRikuStoryTale2Line31German,
    gJiminyRikuStoryTale2Line32German, gJiminyRikuStoryTale2Line33German, gJiminyRikuStoryTale2Line34German,
};

const JiminyTextChar* gJiminyRikuStoryTale2LinesItalian[32] = {
    gJiminyRikuStoryTale2Line0Italian, gJiminyRikuStoryTale2Line1Italian, gJiminyRikuStoryTale2Line2Italian, gJiminyRikuStoryTale2Line3Italian,
    gJiminyRikuStoryTale2Line4Italian, gJiminyRikuStoryTale2Line5Italian, gJiminyRikuStoryTale2Line6Italian, gJiminyRikuStoryTale2Line7Italian,
    gJiminyRikuStoryTale2Line8Italian, gJiminyRikuStoryTale2Line9Italian, gJiminyRikuStoryTale2Line10Italian, gJiminyRikuStoryTale2Line11Italian,
    gJiminyRikuStoryTale2Line12Italian, gJiminyRikuStoryTale2Line13Italian, gJiminyRikuStoryTale2Line14Italian, gJiminyRikuStoryTale2Line15Italian,
    gJiminyRikuStoryTale2Line16Italian, gJiminyRikuStoryTale2Line17Italian, gJiminyRikuStoryTale2Line18Italian, gJiminyRikuStoryTale2Line19Italian,
    gJiminyRikuStoryTale2Line20Italian, gJiminyRikuStoryTale2Line21Italian, gJiminyRikuStoryTale2Line22Italian, gJiminyRikuStoryTale2Line23Italian,
    gJiminyRikuStoryTale2Line24Italian, gJiminyRikuStoryTale2Line25Italian, gJiminyRikuStoryTale2Line26Italian, gJiminyRikuStoryTale2Line27Italian,
    gJiminyRikuStoryTale2Line28Italian, gJiminyRikuStoryTale2Line29Italian, gJiminyRikuStoryTale2Line30Italian, gJiminyRikuStoryTale2Line31Italian,
};

const JiminyTextChar* gJiminyRikuStoryTale2LinesSpanish[28] = {
    gJiminyRikuStoryTale2Line0Spanish, gJiminyRikuStoryTale2Line1Spanish, gJiminyRikuStoryTale2Line2Spanish, gJiminyRikuStoryTale2Line3Spanish,
    gJiminyRikuStoryTale2Line4Spanish, gJiminyRikuStoryTale2Line5Spanish, gJiminyRikuStoryTale2Line6Spanish, gJiminyRikuStoryTale2Line7Spanish,
    gJiminyRikuStoryTale2Line8Spanish, gJiminyRikuStoryTale2Line9Spanish, gJiminyRikuStoryTale2Line10Spanish, gJiminyRikuStoryTale2Line11Spanish,
    gJiminyRikuStoryTale2Line12Spanish, gJiminyRikuStoryTale2Line13Spanish, gJiminyRikuStoryTale2Line14Spanish, gJiminyRikuStoryTale2Line15Spanish,
    gJiminyRikuStoryTale2Line16Spanish, gJiminyRikuStoryTale2Line17Spanish, gJiminyRikuStoryTale2Line18Spanish, gJiminyRikuStoryTale2Line19Spanish,
    gJiminyRikuStoryTale2Line20Spanish, gJiminyRikuStoryTale2Line21Spanish, gJiminyRikuStoryTale2Line22Spanish, gJiminyRikuStoryTale2Line23Spanish,
    gJiminyRikuStoryTale2Line24Spanish, gJiminyRikuStoryTale2Line25Spanish, gJiminyRikuStoryTale2Line26Spanish, gJiminyRikuStoryTale2Line27Spanish,
};

const JiminyTextChar* gJiminyRikuStoryTale3Lines[20] = {
    gJiminyRikuStoryTale3Line0, gJiminyRikuStoryTale3Line1, gJiminyRikuStoryTale3Line2, gJiminyRikuStoryTale3Line3,
    gJiminyRikuStoryTale3Line4, gJiminyRikuStoryTale3Line5, gJiminyRikuStoryTale3Line6, gJiminyRikuStoryTale3Line7,
    gJiminyRikuStoryTale3Line8, gJiminyRikuStoryTale3Line9, gJiminyRikuStoryTale3Line10, gJiminyRikuStoryTale3Line11,
    gJiminyRikuStoryTale3Line12, gJiminyRikuStoryTale3Line13, gJiminyRikuStoryTale3Line14, gJiminyRikuStoryTale3Line15,
    gJiminyRikuStoryTale3Line16, gJiminyRikuStoryTale3Line17, gJiminyRikuStoryTale3Line18, gJiminyRikuStoryTale3Line19,
};

const JiminyTextChar* gJiminyRikuStoryTale3LinesFrench[22] = {
    gJiminyRikuStoryTale3Line0French, gJiminyRikuStoryTale3Line1French, gJiminyRikuStoryTale3Line2French, gJiminyRikuStoryTale3Line3French,
    gJiminyRikuStoryTale3Line4French, gJiminyRikuStoryTale3Line5French, gJiminyRikuStoryTale3Line6French, gJiminyRikuStoryTale3Line7French,
    gJiminyRikuStoryTale3Line8French, gJiminyRikuStoryTale3Line9French, gJiminyRikuStoryTale3Line10French, gJiminyRikuStoryTale3Line11French,
    gJiminyRikuStoryTale3Line12French, gJiminyRikuStoryTale3Line13French, gJiminyRikuStoryTale3Line14French, gJiminyRikuStoryTale3Line15French,
    gJiminyRikuStoryTale3Line16French, gJiminyRikuStoryTale3Line17French, gJiminyRikuStoryTale3Line18French, gJiminyRikuStoryTale3Line19French,
    gJiminyRikuStoryTale3Line20French, gJiminyRikuStoryTale3Line21French,
};

const JiminyTextChar* gJiminyRikuStoryTale3LinesGerman[29] = {
    gJiminyRikuStoryTale3Line0German, gJiminyRikuStoryTale3Line1German, gJiminyRikuStoryTale3Line2German, gJiminyRikuStoryTale3Line3German,
    gJiminyRikuStoryTale3Line4German, gJiminyRikuStoryTale3Line5German, gJiminyRikuStoryTale3Line6German, gJiminyRikuStoryTale3Line7German,
    gJiminyRikuStoryTale3Line8German, gJiminyRikuStoryTale3Line9German, gJiminyRikuStoryTale3Line10German, gJiminyRikuStoryTale3Line11German,
    gJiminyRikuStoryTale3Line12German, gJiminyRikuStoryTale3Line13German, gJiminyRikuStoryTale3Line14German, gJiminyRikuStoryTale3Line15German,
    gJiminyRikuStoryTale3Line16German, gJiminyRikuStoryTale3Line17German, gJiminyRikuStoryTale3Line18German, gJiminyRikuStoryTale3Line19German,
    gJiminyRikuStoryTale3Line20German, gJiminyRikuStoryTale3Line21German, gJiminyRikuStoryTale3Line22German, gJiminyRikuStoryTale3Line23German,
    gJiminyRikuStoryTale3Line24German, gJiminyRikuStoryTale3Line25German, gJiminyRikuStoryTale3Line26German, gJiminyRikuStoryTale3Line27German,
    gJiminyRikuStoryTale3Line28German,
};

const JiminyTextChar* gJiminyRikuStoryTale3LinesItalian[24] = {
    gJiminyRikuStoryTale3Line0Italian, gJiminyRikuStoryTale3Line1Italian, gJiminyRikuStoryTale3Line2Italian, gJiminyRikuStoryTale3Line3Italian,
    gJiminyRikuStoryTale3Line4Italian, gJiminyRikuStoryTale3Line5Italian, gJiminyRikuStoryTale3Line6Italian, gJiminyRikuStoryTale3Line7Italian,
    gJiminyRikuStoryTale3Line8Italian, gJiminyRikuStoryTale3Line9Italian, gJiminyRikuStoryTale3Line10Italian, gJiminyRikuStoryTale3Line11Italian,
    gJiminyRikuStoryTale3Line12Italian, gJiminyRikuStoryTale3Line13Italian, gJiminyRikuStoryTale3Line14Italian, gJiminyRikuStoryTale3Line15Italian,
    gJiminyRikuStoryTale3Line16Italian, gJiminyRikuStoryTale3Line17Italian, gJiminyRikuStoryTale3Line18Italian, gJiminyRikuStoryTale3Line19Italian,
    gJiminyRikuStoryTale3Line20Italian, gJiminyRikuStoryTale3Line21Italian, gJiminyRikuStoryTale3Line22Italian, gJiminyRikuStoryTale3Line23Italian,
};

const JiminyTextChar* gJiminyRikuStoryTale3LinesSpanish[21] = {
    gJiminyRikuStoryTale3Line0Spanish, gJiminyRikuStoryTale3Line1Spanish, gJiminyRikuStoryTale3Line2Spanish, gJiminyRikuStoryTale3Line3Spanish,
    gJiminyRikuStoryTale3Line4Spanish, gJiminyRikuStoryTale3Line5Spanish, gJiminyRikuStoryTale3Line6Spanish, gJiminyRikuStoryTale3Line7Spanish,
    gJiminyRikuStoryTale3Line8Spanish, gJiminyRikuStoryTale3Line9Spanish, gJiminyRikuStoryTale3Line10Spanish, gJiminyRikuStoryTale3Line11Spanish,
    gJiminyRikuStoryTale3Line12Spanish, gJiminyRikuStoryTale3Line13Spanish, gJiminyRikuStoryTale3Line14Spanish, gJiminyRikuStoryTale3Line15Spanish,
    gJiminyRikuStoryTale3Line16Spanish, gJiminyRikuStoryTale3Line17Spanish, gJiminyRikuStoryTale3Line18Spanish, gJiminyRikuStoryTale3Line19Spanish,
    gJiminyRikuStoryTale3Line20Spanish,
};

const JiminyTextChar* gJiminyRikuStoryTale4Lines[20] = {
    gJiminyRikuStoryTale4Line0, gJiminyRikuStoryTale4Line1, gJiminyRikuStoryTale4Line2, gJiminyRikuStoryTale4Line3,
    gJiminyRikuStoryTale4Line4, gJiminyRikuStoryTale4Line5, gJiminyRikuStoryTale4Line6, gJiminyRikuStoryTale4Line7,
    gJiminyRikuStoryTale4Line8, gJiminyRikuStoryTale4Line9, gJiminyRikuStoryTale4Line10, gJiminyRikuStoryTale4Line11,
    gJiminyRikuStoryTale4Line12, gJiminyRikuStoryTale4Line13, gJiminyRikuStoryTale4Line14, gJiminyRikuStoryTale4Line15,
    gJiminyRikuStoryTale4Line16, gJiminyRikuStoryTale4Line17, gJiminyRikuStoryTale4Line18, gJiminyRikuStoryTale4Line19,
};

const JiminyTextChar* gJiminyRikuStoryTale4LinesFrench[22] = {
    gJiminyRikuStoryTale4Line0French, gJiminyRikuStoryTale4Line1French, gJiminyRikuStoryTale4Line2French, gJiminyRikuStoryTale4Line3French,
    gJiminyRikuStoryTale4Line4French, gJiminyRikuStoryTale4Line5French, gJiminyRikuStoryTale4Line6French, gJiminyRikuStoryTale4Line7French,
    gJiminyRikuStoryTale4Line8French, gJiminyRikuStoryTale4Line9French, gJiminyRikuStoryTale4Line10French, gJiminyRikuStoryTale4Line11French,
    gJiminyRikuStoryTale4Line12French, gJiminyRikuStoryTale4Line13French, gJiminyRikuStoryTale4Line14French, gJiminyRikuStoryTale4Line15French,
    gJiminyRikuStoryTale4Line16French, gJiminyRikuStoryTale4Line17French, gJiminyRikuStoryTale4Line18French, gJiminyRikuStoryTale4Line19French,
    gJiminyRikuStoryTale4Line20French, gJiminyRikuStoryTale4Line21French,
};

const JiminyTextChar* gJiminyRikuStoryTale4LinesGerman[23] = {
    gJiminyRikuStoryTale4Line0German, gJiminyRikuStoryTale4Line1German, gJiminyRikuStoryTale4Line2German, gJiminyRikuStoryTale4Line3German,
    gJiminyRikuStoryTale4Line4German, gJiminyRikuStoryTale4Line5German, gJiminyRikuStoryTale4Line6German, gJiminyRikuStoryTale4Line7German,
    gJiminyRikuStoryTale4Line8German, gJiminyRikuStoryTale4Line9German, gJiminyRikuStoryTale4Line10German, gJiminyRikuStoryTale4Line11German,
    gJiminyRikuStoryTale4Line12German, gJiminyRikuStoryTale4Line13German, gJiminyRikuStoryTale4Line14German, gJiminyRikuStoryTale4Line15German,
    gJiminyRikuStoryTale4Line16German, gJiminyRikuStoryTale4Line17German, gJiminyRikuStoryTale4Line18German, gJiminyRikuStoryTale4Line19German,
    gJiminyRikuStoryTale4Line20German, gJiminyRikuStoryTale4Line21German, gJiminyRikuStoryTale4Line22German,
};

const JiminyTextChar* gJiminyRikuStoryTale4LinesItalian[20] = {
    gJiminyRikuStoryTale4Line0Italian, gJiminyRikuStoryTale4Line1Italian, gJiminyRikuStoryTale4Line2Italian, gJiminyRikuStoryTale4Line3Italian,
    gJiminyRikuStoryTale4Line4Italian, gJiminyRikuStoryTale4Line5Italian, gJiminyRikuStoryTale4Line6Italian, gJiminyRikuStoryTale4Line7Italian,
    gJiminyRikuStoryTale4Line8Italian, gJiminyRikuStoryTale4Line9Italian, gJiminyRikuStoryTale4Line10Italian, gJiminyRikuStoryTale4Line11Italian,
    gJiminyRikuStoryTale4Line12Italian, gJiminyRikuStoryTale4Line13Italian, gJiminyRikuStoryTale4Line14Italian, gJiminyRikuStoryTale4Line15Italian,
    gJiminyRikuStoryTale4Line16Italian, gJiminyRikuStoryTale4Line17Italian, gJiminyRikuStoryTale4Line18Italian, gJiminyRikuStoryTale4Line19Italian,
};

const JiminyTextChar* gJiminyRikuStoryTale4LinesSpanish[23] = {
    gJiminyRikuStoryTale4Line0Spanish, gJiminyRikuStoryTale4Line1Spanish, gJiminyRikuStoryTale4Line2Spanish, gJiminyRikuStoryTale4Line3Spanish,
    gJiminyRikuStoryTale4Line4Spanish, gJiminyRikuStoryTale4Line5Spanish, gJiminyRikuStoryTale4Line6Spanish, gJiminyRikuStoryTale4Line7Spanish,
    gJiminyRikuStoryTale4Line8Spanish, gJiminyRikuStoryTale4Line9Spanish, gJiminyRikuStoryTale4Line10Spanish, gJiminyRikuStoryTale4Line11Spanish,
    gJiminyRikuStoryTale4Line12Spanish, gJiminyRikuStoryTale4Line13Spanish, gJiminyRikuStoryTale4Line14Spanish, gJiminyRikuStoryTale4Line15Spanish,
    gJiminyRikuStoryTale4Line16Spanish, gJiminyRikuStoryTale4Line17Spanish, gJiminyRikuStoryTale4Line18Spanish, gJiminyRikuStoryTale4Line19Spanish,
    gJiminyRikuStoryTale4Line20Spanish, gJiminyRikuStoryTale4Line21Spanish, gJiminyRikuStoryTale4Line22Spanish,
};

const JiminyTextChar* gJiminyRikuStoryTale5Lines[23] = {
    gJiminyRikuStoryTale5Line0, gJiminyRikuStoryTale5Line1, gJiminyRikuStoryTale5Line2, gJiminyRikuStoryTale5Line3,
    gJiminyRikuStoryTale5Line4, gJiminyRikuStoryTale5Line5, gJiminyRikuStoryTale5Line6, gJiminyRikuStoryTale5Line7,
    gJiminyRikuStoryTale5Line8, gJiminyRikuStoryTale5Line9, gJiminyRikuStoryTale5Line10, gJiminyRikuStoryTale5Line11,
    gJiminyRikuStoryTale5Line12, gJiminyRikuStoryTale5Line13, gJiminyRikuStoryTale5Line14, gJiminyRikuStoryTale5Line15,
    gJiminyRikuStoryTale5Line16, gJiminyRikuStoryTale5Line17, gJiminyRikuStoryTale5Line18, gJiminyRikuStoryTale5Line19,
    gJiminyRikuStoryTale5Line20, gJiminyRikuStoryTale5Line21, gJiminyRikuStoryTale5Line22,
};

const JiminyTextChar* gJiminyRikuStoryTale5LinesFrench[26] = {
    gJiminyRikuStoryTale5Line0French, gJiminyRikuStoryTale5Line1French, gJiminyRikuStoryTale5Line2French, gJiminyRikuStoryTale5Line3French,
    gJiminyRikuStoryTale5Line4French, gJiminyRikuStoryTale5Line5French, gJiminyRikuStoryTale5Line6French, gJiminyRikuStoryTale5Line7French,
    gJiminyRikuStoryTale5Line8French, gJiminyRikuStoryTale5Line9French, gJiminyRikuStoryTale5Line10French, gJiminyRikuStoryTale5Line11French,
    gJiminyRikuStoryTale5Line12French, gJiminyRikuStoryTale5Line13French, gJiminyRikuStoryTale5Line14French, gJiminyRikuStoryTale5Line15French,
    gJiminyRikuStoryTale5Line16French, gJiminyRikuStoryTale5Line17French, gJiminyRikuStoryTale5Line18French, gJiminyRikuStoryTale5Line19French,
    gJiminyRikuStoryTale5Line20French, gJiminyRikuStoryTale5Line21French, gJiminyRikuStoryTale5Line22French, gJiminyRikuStoryTale5Line23French,
    gJiminyRikuStoryTale5Line24French, gJiminyRikuStoryTale5Line25French,
};

const JiminyTextChar* gJiminyRikuStoryTale5LinesGerman[31] = {
    gJiminyRikuStoryTale5Line0German, gJiminyRikuStoryTale5Line1German, gJiminyRikuStoryTale5Line2German, gJiminyRikuStoryTale5Line3German,
    gJiminyRikuStoryTale5Line4German, gJiminyRikuStoryTale5Line5German, gJiminyRikuStoryTale5Line6German, gJiminyRikuStoryTale5Line7German,
    gJiminyRikuStoryTale5Line8German, gJiminyRikuStoryTale5Line9German, gJiminyRikuStoryTale5Line10German, gJiminyRikuStoryTale5Line11German,
    gJiminyRikuStoryTale5Line12German, gJiminyRikuStoryTale5Line13German, gJiminyRikuStoryTale5Line14German, gJiminyRikuStoryTale5Line15German,
    gJiminyRikuStoryTale5Line16German, gJiminyRikuStoryTale5Line17German, gJiminyRikuStoryTale5Line18German, gJiminyRikuStoryTale5Line19German,
    gJiminyRikuStoryTale5Line20German, gJiminyRikuStoryTale5Line21German, gJiminyRikuStoryTale5Line22German, gJiminyRikuStoryTale5Line23German,
    gJiminyRikuStoryTale5Line24German, gJiminyRikuStoryTale5Line25German, gJiminyRikuStoryTale5Line26German, gJiminyRikuStoryTale5Line27German,
    gJiminyRikuStoryTale5Line28German, gJiminyRikuStoryTale5Line29German, gJiminyRikuStoryTale5Line30German,
};

const JiminyTextChar* gJiminyRikuStoryTale5LinesItalian[27] = {
    gJiminyRikuStoryTale5Line0Italian, gJiminyRikuStoryTale5Line1Italian, gJiminyRikuStoryTale5Line2Italian, gJiminyRikuStoryTale5Line3Italian,
    gJiminyRikuStoryTale5Line4Italian, gJiminyRikuStoryTale5Line5Italian, gJiminyRikuStoryTale5Line6Italian, gJiminyRikuStoryTale5Line7Italian,
    gJiminyRikuStoryTale5Line8Italian, gJiminyRikuStoryTale5Line9Italian, gJiminyRikuStoryTale5Line10Italian, gJiminyRikuStoryTale5Line11Italian,
    gJiminyRikuStoryTale5Line12Italian, gJiminyRikuStoryTale5Line13Italian, gJiminyRikuStoryTale5Line14Italian, gJiminyRikuStoryTale5Line15Italian,
    gJiminyRikuStoryTale5Line16Italian, gJiminyRikuStoryTale5Line17Italian, gJiminyRikuStoryTale5Line18Italian, gJiminyRikuStoryTale5Line19Italian,
    gJiminyRikuStoryTale5Line20Italian, gJiminyRikuStoryTale5Line21Italian, gJiminyRikuStoryTale5Line22Italian, gJiminyRikuStoryTale5Line23Italian,
    gJiminyRikuStoryTale5Line24Italian, gJiminyRikuStoryTale5Line25Italian, gJiminyRikuStoryTale5Line26Italian,
};

const JiminyTextChar* gJiminyRikuStoryTale5LinesSpanish[26] = {
    gJiminyRikuStoryTale5Line0Spanish, gJiminyRikuStoryTale5Line1Spanish, gJiminyRikuStoryTale5Line2Spanish, gJiminyRikuStoryTale5Line3Spanish,
    gJiminyRikuStoryTale5Line4Spanish, gJiminyRikuStoryTale5Line5Spanish, gJiminyRikuStoryTale5Line6Spanish, gJiminyRikuStoryTale5Line7Spanish,
    gJiminyRikuStoryTale5Line8Spanish, gJiminyRikuStoryTale5Line9Spanish, gJiminyRikuStoryTale5Line10Spanish, gJiminyRikuStoryTale5Line11Spanish,
    gJiminyRikuStoryTale5Line12Spanish, gJiminyRikuStoryTale5Line13Spanish, gJiminyRikuStoryTale5Line14Spanish, gJiminyRikuStoryTale5Line15Spanish,
    gJiminyRikuStoryTale5Line16Spanish, gJiminyRikuStoryTale5Line17Spanish, gJiminyRikuStoryTale5Line18Spanish, gJiminyRikuStoryTale5Line19Spanish,
    gJiminyRikuStoryTale5Line20Spanish, gJiminyRikuStoryTale5Line21Spanish, gJiminyRikuStoryTale5Line22Spanish, gJiminyRikuStoryTale5Line23Spanish,
    gJiminyRikuStoryTale5Line24Spanish, gJiminyRikuStoryTale5Line25Spanish,
};

const JiminyTextChar* gJiminyRikuStoryTale6Lines[31] = {
    gJiminyRikuStoryTale6Line0, gJiminyRikuStoryTale6Line1, gJiminyRikuStoryTale6Line2, gJiminyRikuStoryTale6Line3,
    gJiminyRikuStoryTale6Line4, gJiminyRikuStoryTale6Line5, gJiminyRikuStoryTale6Line6, gJiminyRikuStoryTale6Line7,
    gJiminyRikuStoryTale6Line8, gJiminyRikuStoryTale6Line9, gJiminyRikuStoryTale6Line10, gJiminyRikuStoryTale6Line11,
    gJiminyRikuStoryTale6Line12, gJiminyRikuStoryTale6Line13, gJiminyRikuStoryTale6Line14, gJiminyRikuStoryTale6Line15,
    gJiminyRikuStoryTale6Line16, gJiminyRikuStoryTale6Line17, gJiminyRikuStoryTale6Line18, gJiminyRikuStoryTale6Line19,
    gJiminyRikuStoryTale6Line20, gJiminyRikuStoryTale6Line21, gJiminyRikuStoryTale6Line22, gJiminyRikuStoryTale6Line23,
    gJiminyRikuStoryTale6Line24, gJiminyRikuStoryTale6Line25, gJiminyRikuStoryTale6Line26, gJiminyRikuStoryTale6Line27,
    gJiminyRikuStoryTale6Line28, gJiminyRikuStoryTale6Line29, gJiminyRikuStoryTale6Line30,
};

const JiminyTextChar* gJiminyRikuStoryTale6LinesFrench[35] = {
    gJiminyRikuStoryTale6Line0French, gJiminyRikuStoryTale6Line1French, gJiminyRikuStoryTale6Line2French, gJiminyRikuStoryTale6Line3French,
    gJiminyRikuStoryTale6Line4French, gJiminyRikuStoryTale6Line5French, gJiminyRikuStoryTale6Line6French, gJiminyRikuStoryTale6Line7French,
    gJiminyRikuStoryTale6Line8French, gJiminyRikuStoryTale6Line9French, gJiminyRikuStoryTale6Line10French, gJiminyRikuStoryTale6Line11French,
    gJiminyRikuStoryTale6Line12French, gJiminyRikuStoryTale6Line13French, gJiminyRikuStoryTale6Line14French, gJiminyRikuStoryTale6Line15French,
    gJiminyRikuStoryTale6Line16French, gJiminyRikuStoryTale6Line17French, gJiminyRikuStoryTale6Line18French, gJiminyRikuStoryTale6Line19French,
    gJiminyRikuStoryTale6Line20French, gJiminyRikuStoryTale6Line21French, gJiminyRikuStoryTale6Line22French, gJiminyRikuStoryTale6Line23French,
    gJiminyRikuStoryTale6Line24French, gJiminyRikuStoryTale6Line25French, gJiminyRikuStoryTale6Line26French, gJiminyRikuStoryTale6Line27French,
    gJiminyRikuStoryTale6Line28French, gJiminyRikuStoryTale6Line29French, gJiminyRikuStoryTale6Line30French, gJiminyRikuStoryTale6Line31French,
    gJiminyRikuStoryTale6Line32French, gJiminyRikuStoryTale6Line33French, gJiminyRikuStoryTale6Line34French,
};

const JiminyTextChar* gJiminyRikuStoryTale6LinesGerman[42] = {
    gJiminyRikuStoryTale6Line0German, gJiminyRikuStoryTale6Line1German, gJiminyRikuStoryTale6Line2German, gJiminyRikuStoryTale6Line3German,
    gJiminyRikuStoryTale6Line4German, gJiminyRikuStoryTale6Line5German, gJiminyRikuStoryTale6Line6German, gJiminyRikuStoryTale6Line7German,
    gJiminyRikuStoryTale6Line8German, gJiminyRikuStoryTale6Line9German, gJiminyRikuStoryTale6Line10German, gJiminyRikuStoryTale6Line11German,
    gJiminyRikuStoryTale6Line12German, gJiminyRikuStoryTale6Line13German, gJiminyRikuStoryTale6Line14German, gJiminyRikuStoryTale6Line15German,
    gJiminyRikuStoryTale6Line16German, gJiminyRikuStoryTale6Line17German, gJiminyRikuStoryTale6Line18German, gJiminyRikuStoryTale6Line19German,
    gJiminyRikuStoryTale6Line20German, gJiminyRikuStoryTale6Line21German, gJiminyRikuStoryTale6Line22German, gJiminyRikuStoryTale6Line23German,
    gJiminyRikuStoryTale6Line24German, gJiminyRikuStoryTale6Line25German, gJiminyRikuStoryTale6Line26German, gJiminyRikuStoryTale6Line27German,
    gJiminyRikuStoryTale6Line28German, gJiminyRikuStoryTale6Line29German, gJiminyRikuStoryTale6Line30German, gJiminyRikuStoryTale6Line31German,
    gJiminyRikuStoryTale6Line32German, gJiminyRikuStoryTale6Line33German, gJiminyRikuStoryTale6Line34German, gJiminyRikuStoryTale6Line35German,
    gJiminyRikuStoryTale6Line36German, gJiminyRikuStoryTale6Line37German, gJiminyRikuStoryTale6Line38German, gJiminyRikuStoryTale6Line39German,
    gJiminyRikuStoryTale6Line40German, gJiminyRikuStoryTale6Line41German,
};

const JiminyTextChar* gJiminyRikuStoryTale6LinesItalian[39] = {
    gJiminyRikuStoryTale6Line0Italian, gJiminyRikuStoryTale6Line1Italian, gJiminyRikuStoryTale6Line2Italian, gJiminyRikuStoryTale6Line3Italian,
    gJiminyRikuStoryTale6Line4Italian, gJiminyRikuStoryTale6Line5Italian, gJiminyRikuStoryTale6Line6Italian, gJiminyRikuStoryTale6Line7Italian,
    gJiminyRikuStoryTale6Line8Italian, gJiminyRikuStoryTale6Line9Italian, gJiminyRikuStoryTale6Line10Italian, gJiminyRikuStoryTale6Line11Italian,
    gJiminyRikuStoryTale6Line12Italian, gJiminyRikuStoryTale6Line13Italian, gJiminyRikuStoryTale6Line14Italian, gJiminyRikuStoryTale6Line15Italian,
    gJiminyRikuStoryTale6Line16Italian, gJiminyRikuStoryTale6Line17Italian, gJiminyRikuStoryTale6Line18Italian, gJiminyRikuStoryTale6Line19Italian,
    gJiminyRikuStoryTale6Line20Italian, gJiminyRikuStoryTale6Line21Italian, gJiminyRikuStoryTale6Line22Italian, gJiminyRikuStoryTale6Line23Italian,
    gJiminyRikuStoryTale6Line24Italian, gJiminyRikuStoryTale6Line25Italian, gJiminyRikuStoryTale6Line26Italian, gJiminyRikuStoryTale6Line27Italian,
    gJiminyRikuStoryTale6Line28Italian, gJiminyRikuStoryTale6Line29Italian, gJiminyRikuStoryTale6Line30Italian, gJiminyRikuStoryTale6Line31Italian,
    gJiminyRikuStoryTale6Line32Italian, gJiminyRikuStoryTale6Line33Italian, gJiminyRikuStoryTale6Line34Italian, gJiminyRikuStoryTale6Line35Italian,
    gJiminyRikuStoryTale6Line36Italian, gJiminyRikuStoryTale6Line37Italian, gJiminyRikuStoryTale6Line38Italian,
};

const JiminyTextChar* gJiminyRikuStoryTale6LinesSpanish[33] = {
    gJiminyRikuStoryTale6Line0Spanish, gJiminyRikuStoryTale6Line1Spanish, gJiminyRikuStoryTale6Line2Spanish, gJiminyRikuStoryTale6Line3Spanish,
    gJiminyRikuStoryTale6Line4Spanish, gJiminyRikuStoryTale6Line5Spanish, gJiminyRikuStoryTale6Line6Spanish, gJiminyRikuStoryTale6Line7Spanish,
    gJiminyRikuStoryTale6Line8Spanish, gJiminyRikuStoryTale6Line9Spanish, gJiminyRikuStoryTale6Line10Spanish, gJiminyRikuStoryTale6Line11Spanish,
    gJiminyRikuStoryTale6Line12Spanish, gJiminyRikuStoryTale6Line13Spanish, gJiminyRikuStoryTale6Line14Spanish, gJiminyRikuStoryTale6Line15Spanish,
    gJiminyRikuStoryTale6Line16Spanish, gJiminyRikuStoryTale6Line17Spanish, gJiminyRikuStoryTale6Line18Spanish, gJiminyRikuStoryTale6Line19Spanish,
    gJiminyRikuStoryTale6Line20Spanish, gJiminyRikuStoryTale6Line21Spanish, gJiminyRikuStoryTale6Line22Spanish, gJiminyRikuStoryTale6Line23Spanish,
    gJiminyRikuStoryTale6Line24Spanish, gJiminyRikuStoryTale6Line25Spanish, gJiminyRikuStoryTale6Line26Spanish, gJiminyRikuStoryTale6Line27Spanish,
    gJiminyRikuStoryTale6Line28Spanish, gJiminyRikuStoryTale6Line29Spanish, gJiminyRikuStoryTale6Line30Spanish, gJiminyRikuStoryTale6Line31Spanish,
    gJiminyRikuStoryTale6Line32Spanish,
};

const JiminyTextChar* gJiminyAttackCardKingdomKeyLines[12] = {
    gJiminyAttackCardKingdomKeyLine0, gJiminyAttackCardKingdomKeyLine1, gJiminyAttackCardKingdomKeyLine2, gJiminyAttackCardKingdomKeyLine3,
    gJiminyAttackCardKingdomKeyLine4, gJiminyAttackCardKingdomKeyLine5, gJiminyAttackCardKingdomKeyLine6, gJiminyAttackCardKingdomKeyLine7,
    gJiminyAttackCardKingdomKeyLine8, gJiminyAttackCardKingdomKeyLine9, gJiminyAttackCardKingdomKeyLine10, gJiminyAttackCardKingdomKeyLine11,
};

const JiminyTextChar* gJiminyAttackCardKingdomKeyLinesFrench[11] = {
    gJiminyAttackCardKingdomKeyLine0French, gJiminyAttackCardKingdomKeyLine1French, gJiminyAttackCardKingdomKeyLine2French, gJiminyAttackCardKingdomKeyLine3French,
    gJiminyAttackCardKingdomKeyLine4French, gJiminyAttackCardKingdomKeyLine5French, gJiminyAttackCardKingdomKeyLine6French, gJiminyAttackCardKingdomKeyLine7French,
    gJiminyAttackCardKingdomKeyLine8French, gJiminyAttackCardKingdomKeyLine9French, gJiminyAttackCardKingdomKeyLine10French,
};

const JiminyTextChar* gJiminyAttackCardKingdomKeyLinesGerman[13] = {
    gJiminyAttackCardKingdomKeyLine0German, gJiminyAttackCardKingdomKeyLine1German, gJiminyAttackCardKingdomKeyLine2German, gJiminyAttackCardKingdomKeyLine3German,
    gJiminyAttackCardKingdomKeyLine4German, gJiminyAttackCardKingdomKeyLine5German, gJiminyAttackCardKingdomKeyLine6German, gJiminyAttackCardKingdomKeyLine7German,
    gJiminyAttackCardKingdomKeyLine8German, gJiminyAttackCardKingdomKeyLine9German, gJiminyAttackCardKingdomKeyLine10German, gJiminyAttackCardKingdomKeyLine11German,
    gJiminyAttackCardKingdomKeyLine12German,
};

const JiminyTextChar* gJiminyAttackCardKingdomKeyLinesItalian[13] = {
    gJiminyAttackCardKingdomKeyLine0Italian, gJiminyAttackCardKingdomKeyLine1Italian, gJiminyAttackCardKingdomKeyLine2Italian, gJiminyAttackCardKingdomKeyLine3Italian,
    gJiminyAttackCardKingdomKeyLine4Italian, gJiminyAttackCardKingdomKeyLine5Italian, gJiminyAttackCardKingdomKeyLine6Italian, gJiminyAttackCardKingdomKeyLine7Italian,
    gJiminyAttackCardKingdomKeyLine8Italian, gJiminyAttackCardKingdomKeyLine9Italian, gJiminyAttackCardKingdomKeyLine10Italian, gJiminyAttackCardKingdomKeyLine11Italian,
    gJiminyAttackCardKingdomKeyLine12Italian,
};

const JiminyTextChar* gJiminyAttackCardKingdomKeyLinesSpanish[12] = {
    gJiminyAttackCardKingdomKeyLine0Spanish, gJiminyAttackCardKingdomKeyLine1Spanish, gJiminyAttackCardKingdomKeyLine2Spanish, gJiminyAttackCardKingdomKeyLine3Spanish,
    gJiminyAttackCardKingdomKeyLine4Spanish, gJiminyAttackCardKingdomKeyLine5Spanish, gJiminyAttackCardKingdomKeyLine6Spanish, gJiminyAttackCardKingdomKeyLine7Spanish,
    gJiminyAttackCardKingdomKeyLine8Spanish, gJiminyAttackCardKingdomKeyLine9Spanish, gJiminyAttackCardKingdomKeyLine10Spanish, gJiminyAttackCardKingdomKeyLine11Spanish,
};

const JiminyTextChar* gJiminyAttackCardThreeWishesLines[11] = {
    gJiminyAttackCardThreeWishesLine0, gJiminyAttackCardThreeWishesLine1, gJiminyAttackCardThreeWishesLine2, gJiminyAttackCardThreeWishesLine3,
    gJiminyAttackCardThreeWishesLine4, gJiminyAttackCardThreeWishesLine5, gJiminyAttackCardThreeWishesLine6, gJiminyAttackCardThreeWishesLine7,
    gJiminyAttackCardThreeWishesLine8, gJiminyAttackCardThreeWishesLine9, gJiminyAttackCardThreeWishesLine10,
};

const JiminyTextChar* gJiminyAttackCardThreeWishesLinesFrench[11] = {
    gJiminyAttackCardThreeWishesLine0French, gJiminyAttackCardThreeWishesLine1French, gJiminyAttackCardThreeWishesLine2French, gJiminyAttackCardThreeWishesLine3French,
    gJiminyAttackCardThreeWishesLine4French, gJiminyAttackCardThreeWishesLine5French, gJiminyAttackCardThreeWishesLine6French, gJiminyAttackCardThreeWishesLine7French,
    gJiminyAttackCardThreeWishesLine8French, gJiminyAttackCardThreeWishesLine9French, gJiminyAttackCardThreeWishesLine10French,
};

const JiminyTextChar* gJiminyAttackCardThreeWishesLinesGerman[11] = {
    gJiminyAttackCardThreeWishesLine0German, gJiminyAttackCardThreeWishesLine1German, gJiminyAttackCardThreeWishesLine2German, gJiminyAttackCardThreeWishesLine3German,
    gJiminyAttackCardThreeWishesLine4German, gJiminyAttackCardThreeWishesLine5German, gJiminyAttackCardThreeWishesLine6German, gJiminyAttackCardThreeWishesLine7German,
    gJiminyAttackCardThreeWishesLine8German, gJiminyAttackCardThreeWishesLine9German, gJiminyAttackCardThreeWishesLine10German,
};

const JiminyTextChar* gJiminyAttackCardThreeWishesLinesItalian[11] = {
    gJiminyAttackCardThreeWishesLine0Italian, gJiminyAttackCardThreeWishesLine1Italian, gJiminyAttackCardThreeWishesLine2Italian, gJiminyAttackCardThreeWishesLine3Italian,
    gJiminyAttackCardThreeWishesLine4Italian, gJiminyAttackCardThreeWishesLine5Italian, gJiminyAttackCardThreeWishesLine6Italian, gJiminyAttackCardThreeWishesLine7Italian,
    gJiminyAttackCardThreeWishesLine8Italian, gJiminyAttackCardThreeWishesLine9Italian, gJiminyAttackCardThreeWishesLine10Italian,
};

const JiminyTextChar* gJiminyAttackCardThreeWishesLinesSpanish[11] = {
    gJiminyAttackCardThreeWishesLine0Spanish, gJiminyAttackCardThreeWishesLine1Spanish, gJiminyAttackCardThreeWishesLine2Spanish, gJiminyAttackCardThreeWishesLine3Spanish,
    gJiminyAttackCardThreeWishesLine4Spanish, gJiminyAttackCardThreeWishesLine5Spanish, gJiminyAttackCardThreeWishesLine6Spanish, gJiminyAttackCardThreeWishesLine7Spanish,
    gJiminyAttackCardThreeWishesLine8Spanish, gJiminyAttackCardThreeWishesLine9Spanish, gJiminyAttackCardThreeWishesLine10Spanish,
};

const JiminyTextChar* gJiminyAttackCardCrabclawLines[12] = {
    gJiminyAttackCardCrabclawLine0, gJiminyAttackCardCrabclawLine1, gJiminyAttackCardCrabclawLine2, gJiminyAttackCardCrabclawLine3,
    gJiminyAttackCardCrabclawLine4, gJiminyAttackCardCrabclawLine5, gJiminyAttackCardCrabclawLine6, gJiminyAttackCardCrabclawLine7,
    gJiminyAttackCardCrabclawLine8, gJiminyAttackCardCrabclawLine9, gJiminyAttackCardCrabclawLine10, gJiminyAttackCardCrabclawLine11,
};

const JiminyTextChar* gJiminyAttackCardCrabclawLinesFrench[11] = {
    gJiminyAttackCardCrabclawLine0French, gJiminyAttackCardCrabclawLine1French, gJiminyAttackCardCrabclawLine2French, gJiminyAttackCardCrabclawLine3French,
    gJiminyAttackCardCrabclawLine4French, gJiminyAttackCardCrabclawLine5French, gJiminyAttackCardCrabclawLine6French, gJiminyAttackCardCrabclawLine7French,
    gJiminyAttackCardCrabclawLine8French, gJiminyAttackCardCrabclawLine9French, gJiminyAttackCardCrabclawLine10French,
};

const JiminyTextChar* gJiminyAttackCardCrabclawLinesGerman[13] = {
    gJiminyAttackCardCrabclawLine0German, gJiminyAttackCardCrabclawLine1German, gJiminyAttackCardCrabclawLine2German, gJiminyAttackCardCrabclawLine3German,
    gJiminyAttackCardCrabclawLine4German, gJiminyAttackCardCrabclawLine5German, gJiminyAttackCardCrabclawLine6German, gJiminyAttackCardCrabclawLine7German,
    gJiminyAttackCardCrabclawLine8German, gJiminyAttackCardCrabclawLine9German, gJiminyAttackCardCrabclawLine10German, gJiminyAttackCardCrabclawLine11German,
    gJiminyAttackCardCrabclawLine12German,
};

const JiminyTextChar* gJiminyAttackCardCrabclawLinesItalian[13] = {
    gJiminyAttackCardCrabclawLine0Italian, gJiminyAttackCardCrabclawLine1Italian, gJiminyAttackCardCrabclawLine2Italian, gJiminyAttackCardCrabclawLine3Italian,
    gJiminyAttackCardCrabclawLine4Italian, gJiminyAttackCardCrabclawLine5Italian, gJiminyAttackCardCrabclawLine6Italian, gJiminyAttackCardCrabclawLine7Italian,
    gJiminyAttackCardCrabclawLine8Italian, gJiminyAttackCardCrabclawLine9Italian, gJiminyAttackCardCrabclawLine10Italian, gJiminyAttackCardCrabclawLine11Italian,
    gJiminyAttackCardCrabclawLine12Italian,
};

const JiminyTextChar* gJiminyAttackCardCrabclawLinesSpanish[12] = {
    gJiminyAttackCardCrabclawLine0Spanish, gJiminyAttackCardCrabclawLine1Spanish, gJiminyAttackCardCrabclawLine2Spanish, gJiminyAttackCardCrabclawLine3Spanish,
    gJiminyAttackCardCrabclawLine4Spanish, gJiminyAttackCardCrabclawLine5Spanish, gJiminyAttackCardCrabclawLine6Spanish, gJiminyAttackCardCrabclawLine7Spanish,
    gJiminyAttackCardCrabclawLine8Spanish, gJiminyAttackCardCrabclawLine9Spanish, gJiminyAttackCardCrabclawLine10Spanish, gJiminyAttackCardCrabclawLine11Spanish,
};

const JiminyTextChar* gJiminyAttackCardPumpkinheadLines[12] = {
    gJiminyAttackCardPumpkinheadLine0, gJiminyAttackCardPumpkinheadLine1, gJiminyAttackCardPumpkinheadLine2, gJiminyAttackCardPumpkinheadLine3,
    gJiminyAttackCardPumpkinheadLine4, gJiminyAttackCardPumpkinheadLine5, gJiminyAttackCardPumpkinheadLine6, gJiminyAttackCardPumpkinheadLine7,
    gJiminyAttackCardPumpkinheadLine8, gJiminyAttackCardPumpkinheadLine9, gJiminyAttackCardPumpkinheadLine10, gJiminyAttackCardPumpkinheadLine11,
};

const JiminyTextChar* gJiminyAttackCardPumpkinheadLinesFrench[12] = {
    gJiminyAttackCardPumpkinheadLine0French, gJiminyAttackCardPumpkinheadLine1French, gJiminyAttackCardPumpkinheadLine2French, gJiminyAttackCardPumpkinheadLine3French,
    gJiminyAttackCardPumpkinheadLine4French, gJiminyAttackCardPumpkinheadLine5French, gJiminyAttackCardPumpkinheadLine6French, gJiminyAttackCardPumpkinheadLine7French,
    gJiminyAttackCardPumpkinheadLine8French, gJiminyAttackCardPumpkinheadLine9French, gJiminyAttackCardPumpkinheadLine10French, gJiminyAttackCardPumpkinheadLine11French,
};

const JiminyTextChar* gJiminyAttackCardPumpkinheadLinesGerman[14] = {
    gJiminyAttackCardPumpkinheadLine0German, gJiminyAttackCardPumpkinheadLine1German, gJiminyAttackCardPumpkinheadLine2German, gJiminyAttackCardPumpkinheadLine3German,
    gJiminyAttackCardPumpkinheadLine4German, gJiminyAttackCardPumpkinheadLine5German, gJiminyAttackCardPumpkinheadLine6German, gJiminyAttackCardPumpkinheadLine7German,
    gJiminyAttackCardPumpkinheadLine8German, gJiminyAttackCardPumpkinheadLine9German, gJiminyAttackCardPumpkinheadLine10German, gJiminyAttackCardPumpkinheadLine11German,
    gJiminyAttackCardPumpkinheadLine12German, gJiminyAttackCardPumpkinheadLine13German,
};

const JiminyTextChar* gJiminyAttackCardPumpkinheadLinesItalian[13] = {
    gJiminyAttackCardPumpkinheadLine0Italian, gJiminyAttackCardPumpkinheadLine1Italian, gJiminyAttackCardPumpkinheadLine2Italian, gJiminyAttackCardPumpkinheadLine3Italian,
    gJiminyAttackCardPumpkinheadLine4Italian, gJiminyAttackCardPumpkinheadLine5Italian, gJiminyAttackCardPumpkinheadLine6Italian, gJiminyAttackCardPumpkinheadLine7Italian,
    gJiminyAttackCardPumpkinheadLine8Italian, gJiminyAttackCardPumpkinheadLine9Italian, gJiminyAttackCardPumpkinheadLine10Italian, gJiminyAttackCardPumpkinheadLine11Italian,
    gJiminyAttackCardPumpkinheadLine12Italian,
};

const JiminyTextChar* gJiminyAttackCardPumpkinheadLinesSpanish[12] = {
    gJiminyAttackCardPumpkinheadLine0Spanish, gJiminyAttackCardPumpkinheadLine1Spanish, gJiminyAttackCardPumpkinheadLine2Spanish, gJiminyAttackCardPumpkinheadLine3Spanish,
    gJiminyAttackCardPumpkinheadLine4Spanish, gJiminyAttackCardPumpkinheadLine5Spanish, gJiminyAttackCardPumpkinheadLine6Spanish, gJiminyAttackCardPumpkinheadLine7Spanish,
    gJiminyAttackCardPumpkinheadLine8Spanish, gJiminyAttackCardPumpkinheadLine9Spanish, gJiminyAttackCardPumpkinheadLine10Spanish, gJiminyAttackCardPumpkinheadLine11Spanish,
};

const JiminyTextChar* gJiminyAttackCardFairyHarpLines[11] = {
    gJiminyAttackCardFairyHarpLine0, gJiminyAttackCardFairyHarpLine1, gJiminyAttackCardFairyHarpLine2, gJiminyAttackCardFairyHarpLine3,
    gJiminyAttackCardFairyHarpLine4, gJiminyAttackCardFairyHarpLine5, gJiminyAttackCardFairyHarpLine6, gJiminyAttackCardFairyHarpLine7,
    gJiminyAttackCardFairyHarpLine8, gJiminyAttackCardFairyHarpLine9, gJiminyAttackCardFairyHarpLine10,
};

const JiminyTextChar* gJiminyAttackCardFairyHarpLinesFrench[12] = {
    gJiminyAttackCardFairyHarpLine0French, gJiminyAttackCardFairyHarpLine1French, gJiminyAttackCardFairyHarpLine2French, gJiminyAttackCardFairyHarpLine3French,
    gJiminyAttackCardFairyHarpLine4French, gJiminyAttackCardFairyHarpLine5French, gJiminyAttackCardFairyHarpLine6French, gJiminyAttackCardFairyHarpLine7French,
    gJiminyAttackCardFairyHarpLine8French, gJiminyAttackCardFairyHarpLine9French, gJiminyAttackCardFairyHarpLine10French, gJiminyAttackCardFairyHarpLine11French,
};

const JiminyTextChar* gJiminyAttackCardFairyHarpLinesGerman[13] = {
    gJiminyAttackCardFairyHarpLine0German, gJiminyAttackCardFairyHarpLine1German, gJiminyAttackCardFairyHarpLine2German, gJiminyAttackCardFairyHarpLine3German,
    gJiminyAttackCardFairyHarpLine4German, gJiminyAttackCardFairyHarpLine5German, gJiminyAttackCardFairyHarpLine6German, gJiminyAttackCardFairyHarpLine7German,
    gJiminyAttackCardFairyHarpLine8German, gJiminyAttackCardFairyHarpLine9German, gJiminyAttackCardFairyHarpLine10German, gJiminyAttackCardFairyHarpLine11German,
    gJiminyAttackCardFairyHarpLine12German,
};

const JiminyTextChar* gJiminyAttackCardFairyHarpLinesItalian[11] = {
    gJiminyAttackCardFairyHarpLine0Italian, gJiminyAttackCardFairyHarpLine1Italian, gJiminyAttackCardFairyHarpLine2Italian, gJiminyAttackCardFairyHarpLine3Italian,
    gJiminyAttackCardFairyHarpLine4Italian, gJiminyAttackCardFairyHarpLine5Italian, gJiminyAttackCardFairyHarpLine6Italian, gJiminyAttackCardFairyHarpLine7Italian,
    gJiminyAttackCardFairyHarpLine8Italian, gJiminyAttackCardFairyHarpLine9Italian, gJiminyAttackCardFairyHarpLine10Italian,
};

const JiminyTextChar* gJiminyAttackCardFairyHarpLinesSpanish[12] = {
    gJiminyAttackCardFairyHarpLine0Spanish, gJiminyAttackCardFairyHarpLine1Spanish, gJiminyAttackCardFairyHarpLine2Spanish, gJiminyAttackCardFairyHarpLine3Spanish,
    gJiminyAttackCardFairyHarpLine4Spanish, gJiminyAttackCardFairyHarpLine5Spanish, gJiminyAttackCardFairyHarpLine6Spanish, gJiminyAttackCardFairyHarpLine7Spanish,
    gJiminyAttackCardFairyHarpLine8Spanish, gJiminyAttackCardFairyHarpLine9Spanish, gJiminyAttackCardFairyHarpLine10Spanish, gJiminyAttackCardFairyHarpLine11Spanish,
};

const JiminyTextChar* gJiminyAttackCardWishingStarLines[11] = {
    gJiminyAttackCardWishingStarLine0, gJiminyAttackCardWishingStarLine1, gJiminyAttackCardWishingStarLine2, gJiminyAttackCardWishingStarLine3,
    gJiminyAttackCardWishingStarLine4, gJiminyAttackCardWishingStarLine5, gJiminyAttackCardWishingStarLine6, gJiminyAttackCardWishingStarLine7,
    gJiminyAttackCardWishingStarLine8, gJiminyAttackCardWishingStarLine9, gJiminyAttackCardWishingStarLine10,
};

const JiminyTextChar* gJiminyAttackCardWishingStarLinesFrench[11] = {
    gJiminyAttackCardWishingStarLine0French, gJiminyAttackCardWishingStarLine1French, gJiminyAttackCardWishingStarLine2French, gJiminyAttackCardWishingStarLine3French,
    gJiminyAttackCardWishingStarLine4French, gJiminyAttackCardWishingStarLine5French, gJiminyAttackCardWishingStarLine6French, gJiminyAttackCardWishingStarLine7French,
    gJiminyAttackCardWishingStarLine8French, gJiminyAttackCardWishingStarLine9French, gJiminyAttackCardWishingStarLine10French,
};

const JiminyTextChar* gJiminyAttackCardWishingStarLinesGerman[12] = {
    gJiminyAttackCardWishingStarLine0German, gJiminyAttackCardWishingStarLine1German, gJiminyAttackCardWishingStarLine2German, gJiminyAttackCardWishingStarLine3German,
    gJiminyAttackCardWishingStarLine4German, gJiminyAttackCardWishingStarLine5German, gJiminyAttackCardWishingStarLine6German, gJiminyAttackCardWishingStarLine7German,
    gJiminyAttackCardWishingStarLine8German, gJiminyAttackCardWishingStarLine9German, gJiminyAttackCardWishingStarLine10German, gJiminyAttackCardWishingStarLine11German,
};

const JiminyTextChar* gJiminyAttackCardWishingStarLinesItalian[12] = {
    gJiminyAttackCardWishingStarLine0Italian, gJiminyAttackCardWishingStarLine1Italian, gJiminyAttackCardWishingStarLine2Italian, gJiminyAttackCardWishingStarLine3Italian,
    gJiminyAttackCardWishingStarLine4Italian, gJiminyAttackCardWishingStarLine5Italian, gJiminyAttackCardWishingStarLine6Italian, gJiminyAttackCardWishingStarLine7Italian,
    gJiminyAttackCardWishingStarLine8Italian, gJiminyAttackCardWishingStarLine9Italian, gJiminyAttackCardWishingStarLine10Italian, gJiminyAttackCardWishingStarLine11Italian,
};

const JiminyTextChar* gJiminyAttackCardWishingStarLinesSpanish[11] = {
    gJiminyAttackCardWishingStarLine0Spanish, gJiminyAttackCardWishingStarLine1Spanish, gJiminyAttackCardWishingStarLine2Spanish, gJiminyAttackCardWishingStarLine3Spanish,
    gJiminyAttackCardWishingStarLine4Spanish, gJiminyAttackCardWishingStarLine5Spanish, gJiminyAttackCardWishingStarLine6Spanish, gJiminyAttackCardWishingStarLine7Spanish,
    gJiminyAttackCardWishingStarLine8Spanish, gJiminyAttackCardWishingStarLine9Spanish, gJiminyAttackCardWishingStarLine10Spanish,
};

const JiminyTextChar* gJiminyAttackCardSpellbinderLines[11] = {
    gJiminyAttackCardSpellbinderLine0, gJiminyAttackCardSpellbinderLine1, gJiminyAttackCardSpellbinderLine2, gJiminyAttackCardSpellbinderLine3,
    gJiminyAttackCardSpellbinderLine4, gJiminyAttackCardSpellbinderLine5, gJiminyAttackCardSpellbinderLine6, gJiminyAttackCardSpellbinderLine7,
    gJiminyAttackCardSpellbinderLine8, gJiminyAttackCardSpellbinderLine9, gJiminyAttackCardSpellbinderLine10,
};

const JiminyTextChar* gJiminyAttackCardSpellbinderLinesFrench[11] = {
    gJiminyAttackCardSpellbinderLine0French, gJiminyAttackCardSpellbinderLine1French, gJiminyAttackCardSpellbinderLine2French, gJiminyAttackCardSpellbinderLine3French,
    gJiminyAttackCardSpellbinderLine4French, gJiminyAttackCardSpellbinderLine5French, gJiminyAttackCardSpellbinderLine6French, gJiminyAttackCardSpellbinderLine7French,
    gJiminyAttackCardSpellbinderLine8French, gJiminyAttackCardSpellbinderLine9French, gJiminyAttackCardSpellbinderLine10French,
};

const JiminyTextChar* gJiminyAttackCardSpellbinderLinesGerman[12] = {
    gJiminyAttackCardSpellbinderLine0German, gJiminyAttackCardSpellbinderLine1German, gJiminyAttackCardSpellbinderLine2German, gJiminyAttackCardSpellbinderLine3German,
    gJiminyAttackCardSpellbinderLine4German, gJiminyAttackCardSpellbinderLine5German, gJiminyAttackCardSpellbinderLine6German, gJiminyAttackCardSpellbinderLine7German,
    gJiminyAttackCardSpellbinderLine8German, gJiminyAttackCardSpellbinderLine9German, gJiminyAttackCardSpellbinderLine10German, gJiminyAttackCardSpellbinderLine11German,
};

const JiminyTextChar* gJiminyAttackCardSpellbinderLinesItalian[12] = {
    gJiminyAttackCardSpellbinderLine0Italian, gJiminyAttackCardSpellbinderLine1Italian, gJiminyAttackCardSpellbinderLine2Italian, gJiminyAttackCardSpellbinderLine3Italian,
    gJiminyAttackCardSpellbinderLine4Italian, gJiminyAttackCardSpellbinderLine5Italian, gJiminyAttackCardSpellbinderLine6Italian, gJiminyAttackCardSpellbinderLine7Italian,
    gJiminyAttackCardSpellbinderLine8Italian, gJiminyAttackCardSpellbinderLine9Italian, gJiminyAttackCardSpellbinderLine10Italian, gJiminyAttackCardSpellbinderLine11Italian,
};

const JiminyTextChar* gJiminyAttackCardSpellbinderLinesSpanish[11] = {
    gJiminyAttackCardSpellbinderLine0Spanish, gJiminyAttackCardSpellbinderLine1Spanish, gJiminyAttackCardSpellbinderLine2Spanish, gJiminyAttackCardSpellbinderLine3Spanish,
    gJiminyAttackCardSpellbinderLine4Spanish, gJiminyAttackCardSpellbinderLine5Spanish, gJiminyAttackCardSpellbinderLine6Spanish, gJiminyAttackCardSpellbinderLine7Spanish,
    gJiminyAttackCardSpellbinderLine8Spanish, gJiminyAttackCardSpellbinderLine9Spanish, gJiminyAttackCardSpellbinderLine10Spanish,
};

const JiminyTextChar* gJiminyAttackCardMetalChocoboLines[12] = {
    gJiminyAttackCardMetalChocoboLine0, gJiminyAttackCardMetalChocoboLine1, gJiminyAttackCardMetalChocoboLine2, gJiminyAttackCardMetalChocoboLine3,
    gJiminyAttackCardMetalChocoboLine4, gJiminyAttackCardMetalChocoboLine5, gJiminyAttackCardMetalChocoboLine6, gJiminyAttackCardMetalChocoboLine7,
    gJiminyAttackCardMetalChocoboLine8, gJiminyAttackCardMetalChocoboLine9, gJiminyAttackCardMetalChocoboLine10, gJiminyAttackCardMetalChocoboLine11,
};

const JiminyTextChar* gJiminyAttackCardMetalChocoboLinesFrench[12] = {
    gJiminyAttackCardMetalChocoboLine0French, gJiminyAttackCardMetalChocoboLine1French, gJiminyAttackCardMetalChocoboLine2French, gJiminyAttackCardMetalChocoboLine3French,
    gJiminyAttackCardMetalChocoboLine4French, gJiminyAttackCardMetalChocoboLine5French, gJiminyAttackCardMetalChocoboLine6French, gJiminyAttackCardMetalChocoboLine7French,
    gJiminyAttackCardMetalChocoboLine8French, gJiminyAttackCardMetalChocoboLine9French, gJiminyAttackCardMetalChocoboLine10French, gJiminyAttackCardMetalChocoboLine11French,
};

const JiminyTextChar* gJiminyAttackCardMetalChocoboLinesGerman[13] = {
    gJiminyAttackCardMetalChocoboLine0German, gJiminyAttackCardMetalChocoboLine1German, gJiminyAttackCardMetalChocoboLine2German, gJiminyAttackCardMetalChocoboLine3German,
    gJiminyAttackCardMetalChocoboLine4German, gJiminyAttackCardMetalChocoboLine5German, gJiminyAttackCardMetalChocoboLine6German, gJiminyAttackCardMetalChocoboLine7German,
    gJiminyAttackCardMetalChocoboLine8German, gJiminyAttackCardMetalChocoboLine9German, gJiminyAttackCardMetalChocoboLine10German, gJiminyAttackCardMetalChocoboLine11German,
    gJiminyAttackCardMetalChocoboLine12German,
};

const JiminyTextChar* gJiminyAttackCardMetalChocoboLinesItalian[13] = {
    gJiminyAttackCardMetalChocoboLine0Italian, gJiminyAttackCardMetalChocoboLine1Italian, gJiminyAttackCardMetalChocoboLine2Italian, gJiminyAttackCardMetalChocoboLine3Italian,
    gJiminyAttackCardMetalChocoboLine4Italian, gJiminyAttackCardMetalChocoboLine5Italian, gJiminyAttackCardMetalChocoboLine6Italian, gJiminyAttackCardMetalChocoboLine7Italian,
    gJiminyAttackCardMetalChocoboLine8Italian, gJiminyAttackCardMetalChocoboLine9Italian, gJiminyAttackCardMetalChocoboLine10Italian, gJiminyAttackCardMetalChocoboLine11Italian,
    gJiminyAttackCardMetalChocoboLine12Italian,
};

const JiminyTextChar* gJiminyAttackCardMetalChocoboLinesSpanish[12] = {
    gJiminyAttackCardMetalChocoboLine0Spanish, gJiminyAttackCardMetalChocoboLine1Spanish, gJiminyAttackCardMetalChocoboLine2Spanish, gJiminyAttackCardMetalChocoboLine3Spanish,
    gJiminyAttackCardMetalChocoboLine4Spanish, gJiminyAttackCardMetalChocoboLine5Spanish, gJiminyAttackCardMetalChocoboLine6Spanish, gJiminyAttackCardMetalChocoboLine7Spanish,
    gJiminyAttackCardMetalChocoboLine8Spanish, gJiminyAttackCardMetalChocoboLine9Spanish, gJiminyAttackCardMetalChocoboLine10Spanish, gJiminyAttackCardMetalChocoboLine11Spanish,
};

const JiminyTextChar* gJiminyAttackCardOlympiaLines[12] = {
    gJiminyAttackCardOlympiaLine0, gJiminyAttackCardOlympiaLine1, gJiminyAttackCardOlympiaLine2, gJiminyAttackCardOlympiaLine3,
    gJiminyAttackCardOlympiaLine4, gJiminyAttackCardOlympiaLine5, gJiminyAttackCardOlympiaLine6, gJiminyAttackCardOlympiaLine7,
    gJiminyAttackCardOlympiaLine8, gJiminyAttackCardOlympiaLine9, gJiminyAttackCardOlympiaLine10, gJiminyAttackCardOlympiaLine11,
};

const JiminyTextChar* gJiminyAttackCardOlympiaLinesFrench[12] = {
    gJiminyAttackCardOlympiaLine0French, gJiminyAttackCardOlympiaLine1French, gJiminyAttackCardOlympiaLine2French, gJiminyAttackCardOlympiaLine3French,
    gJiminyAttackCardOlympiaLine4French, gJiminyAttackCardOlympiaLine5French, gJiminyAttackCardOlympiaLine6French, gJiminyAttackCardOlympiaLine7French,
    gJiminyAttackCardOlympiaLine8French, gJiminyAttackCardOlympiaLine9French, gJiminyAttackCardOlympiaLine10French, gJiminyAttackCardOlympiaLine11French,
};

const JiminyTextChar* gJiminyAttackCardOlympiaLinesGerman[14] = {
    gJiminyAttackCardOlympiaLine0German, gJiminyAttackCardOlympiaLine1German, gJiminyAttackCardOlympiaLine2German, gJiminyAttackCardOlympiaLine3German,
    gJiminyAttackCardOlympiaLine4German, gJiminyAttackCardOlympiaLine5German, gJiminyAttackCardOlympiaLine6German, gJiminyAttackCardOlympiaLine7German,
    gJiminyAttackCardOlympiaLine8German, gJiminyAttackCardOlympiaLine9German, gJiminyAttackCardOlympiaLine10German, gJiminyAttackCardOlympiaLine11German,
    gJiminyAttackCardOlympiaLine12German, gJiminyAttackCardOlympiaLine13German,
};

const JiminyTextChar* gJiminyAttackCardOlympiaLinesItalian[12] = {
    gJiminyAttackCardOlympiaLine0Italian, gJiminyAttackCardOlympiaLine1Italian, gJiminyAttackCardOlympiaLine2Italian, gJiminyAttackCardOlympiaLine3Italian,
    gJiminyAttackCardOlympiaLine4Italian, gJiminyAttackCardOlympiaLine5Italian, gJiminyAttackCardOlympiaLine6Italian, gJiminyAttackCardOlympiaLine7Italian,
    gJiminyAttackCardOlympiaLine8Italian, gJiminyAttackCardOlympiaLine9Italian, gJiminyAttackCardOlympiaLine10Italian, gJiminyAttackCardOlympiaLine11Italian,
};

const JiminyTextChar* gJiminyAttackCardOlympiaLinesSpanish[12] = {
    gJiminyAttackCardOlympiaLine0Spanish, gJiminyAttackCardOlympiaLine1Spanish, gJiminyAttackCardOlympiaLine2Spanish, gJiminyAttackCardOlympiaLine3Spanish,
    gJiminyAttackCardOlympiaLine4Spanish, gJiminyAttackCardOlympiaLine5Spanish, gJiminyAttackCardOlympiaLine6Spanish, gJiminyAttackCardOlympiaLine7Spanish,
    gJiminyAttackCardOlympiaLine8Spanish, gJiminyAttackCardOlympiaLine9Spanish, gJiminyAttackCardOlympiaLine10Spanish, gJiminyAttackCardOlympiaLine11Spanish,
};

const JiminyTextChar* gJiminyAttackCardLionheartLines[11] = {
    gJiminyAttackCardLionheartLine0, gJiminyAttackCardLionheartLine1, gJiminyAttackCardLionheartLine2, gJiminyAttackCardLionheartLine3,
    gJiminyAttackCardLionheartLine4, gJiminyAttackCardLionheartLine5, gJiminyAttackCardLionheartLine6, gJiminyAttackCardLionheartLine7,
    gJiminyAttackCardLionheartLine8, gJiminyAttackCardLionheartLine9, gJiminyAttackCardLionheartLine10,
};

const JiminyTextChar* gJiminyAttackCardLionheartLinesFrench[11] = {
    gJiminyAttackCardLionheartLine0French, gJiminyAttackCardLionheartLine1French, gJiminyAttackCardLionheartLine2French, gJiminyAttackCardLionheartLine3French,
    gJiminyAttackCardLionheartLine4French, gJiminyAttackCardLionheartLine5French, gJiminyAttackCardLionheartLine6French, gJiminyAttackCardLionheartLine7French,
    gJiminyAttackCardLionheartLine8French, gJiminyAttackCardLionheartLine9French, gJiminyAttackCardLionheartLine10French,
};

const JiminyTextChar* gJiminyAttackCardLionheartLinesGerman[12] = {
    gJiminyAttackCardLionheartLine0German, gJiminyAttackCardLionheartLine1German, gJiminyAttackCardLionheartLine2German, gJiminyAttackCardLionheartLine3German,
    gJiminyAttackCardLionheartLine4German, gJiminyAttackCardLionheartLine5German, gJiminyAttackCardLionheartLine6German, gJiminyAttackCardLionheartLine7German,
    gJiminyAttackCardLionheartLine8German, gJiminyAttackCardLionheartLine9German, gJiminyAttackCardLionheartLine10German, gJiminyAttackCardLionheartLine11German,
};

const JiminyTextChar* gJiminyAttackCardLionheartLinesItalian[12] = {
    gJiminyAttackCardLionheartLine0Italian, gJiminyAttackCardLionheartLine1Italian, gJiminyAttackCardLionheartLine2Italian, gJiminyAttackCardLionheartLine3Italian,
    gJiminyAttackCardLionheartLine4Italian, gJiminyAttackCardLionheartLine5Italian, gJiminyAttackCardLionheartLine6Italian, gJiminyAttackCardLionheartLine7Italian,
    gJiminyAttackCardLionheartLine8Italian, gJiminyAttackCardLionheartLine9Italian, gJiminyAttackCardLionheartLine10Italian, gJiminyAttackCardLionheartLine11Italian,
};

const JiminyTextChar* gJiminyAttackCardLionheartLinesSpanish[11] = {
    gJiminyAttackCardLionheartLine0Spanish, gJiminyAttackCardLionheartLine1Spanish, gJiminyAttackCardLionheartLine2Spanish, gJiminyAttackCardLionheartLine3Spanish,
    gJiminyAttackCardLionheartLine4Spanish, gJiminyAttackCardLionheartLine5Spanish, gJiminyAttackCardLionheartLine6Spanish, gJiminyAttackCardLionheartLine7Spanish,
    gJiminyAttackCardLionheartLine8Spanish, gJiminyAttackCardLionheartLine9Spanish, gJiminyAttackCardLionheartLine10Spanish,
};

const JiminyTextChar* gJiminyAttackCardLadyLuckLines[11] = {
    gJiminyAttackCardLadyLuckLine0, gJiminyAttackCardLadyLuckLine1, gJiminyAttackCardLadyLuckLine2, gJiminyAttackCardLadyLuckLine3,
    gJiminyAttackCardLadyLuckLine4, gJiminyAttackCardLadyLuckLine5, gJiminyAttackCardLadyLuckLine6, gJiminyAttackCardLadyLuckLine7,
    gJiminyAttackCardLadyLuckLine8, gJiminyAttackCardLadyLuckLine9, gJiminyAttackCardLadyLuckLine10,
};

const JiminyTextChar* gJiminyAttackCardLadyLuckLinesFrench[11] = {
    gJiminyAttackCardLadyLuckLine0French, gJiminyAttackCardLadyLuckLine1French, gJiminyAttackCardLadyLuckLine2French, gJiminyAttackCardLadyLuckLine3French,
    gJiminyAttackCardLadyLuckLine4French, gJiminyAttackCardLadyLuckLine5French, gJiminyAttackCardLadyLuckLine6French, gJiminyAttackCardLadyLuckLine7French,
    gJiminyAttackCardLadyLuckLine8French, gJiminyAttackCardLadyLuckLine9French, gJiminyAttackCardLadyLuckLine10French,
};

const JiminyTextChar* gJiminyAttackCardLadyLuckLinesGerman[12] = {
    gJiminyAttackCardLadyLuckLine0German, gJiminyAttackCardLadyLuckLine1German, gJiminyAttackCardLadyLuckLine2German, gJiminyAttackCardLadyLuckLine3German,
    gJiminyAttackCardLadyLuckLine4German, gJiminyAttackCardLadyLuckLine5German, gJiminyAttackCardLadyLuckLine6German, gJiminyAttackCardLadyLuckLine7German,
    gJiminyAttackCardLadyLuckLine8German, gJiminyAttackCardLadyLuckLine9German, gJiminyAttackCardLadyLuckLine10German, gJiminyAttackCardLadyLuckLine11German,
};

const JiminyTextChar* gJiminyAttackCardLadyLuckLinesItalian[12] = {
    gJiminyAttackCardLadyLuckLine0Italian, gJiminyAttackCardLadyLuckLine1Italian, gJiminyAttackCardLadyLuckLine2Italian, gJiminyAttackCardLadyLuckLine3Italian,
    gJiminyAttackCardLadyLuckLine4Italian, gJiminyAttackCardLadyLuckLine5Italian, gJiminyAttackCardLadyLuckLine6Italian, gJiminyAttackCardLadyLuckLine7Italian,
    gJiminyAttackCardLadyLuckLine8Italian, gJiminyAttackCardLadyLuckLine9Italian, gJiminyAttackCardLadyLuckLine10Italian, gJiminyAttackCardLadyLuckLine11Italian,
};

const JiminyTextChar* gJiminyAttackCardLadyLuckLinesSpanish[12] = {
    gJiminyAttackCardLadyLuckLine0Spanish, gJiminyAttackCardLadyLuckLine1Spanish, gJiminyAttackCardLadyLuckLine2Spanish, gJiminyAttackCardLadyLuckLine3Spanish,
    gJiminyAttackCardLadyLuckLine4Spanish, gJiminyAttackCardLadyLuckLine5Spanish, gJiminyAttackCardLadyLuckLine6Spanish, gJiminyAttackCardLadyLuckLine7Spanish,
    gJiminyAttackCardLadyLuckLine8Spanish, gJiminyAttackCardLadyLuckLine9Spanish, gJiminyAttackCardLadyLuckLine10Spanish, gJiminyAttackCardLadyLuckLine11Spanish,
};

const JiminyTextChar* gJiminyAttackCardDivineRoseLines[12] = {
    gJiminyAttackCardDivineRoseLine0, gJiminyAttackCardDivineRoseLine1, gJiminyAttackCardDivineRoseLine2, gJiminyAttackCardDivineRoseLine3,
    gJiminyAttackCardDivineRoseLine4, gJiminyAttackCardDivineRoseLine5, gJiminyAttackCardDivineRoseLine6, gJiminyAttackCardDivineRoseLine7,
    gJiminyAttackCardDivineRoseLine8, gJiminyAttackCardDivineRoseLine9, gJiminyAttackCardDivineRoseLine10, gJiminyAttackCardDivineRoseLine11,
};

const JiminyTextChar* gJiminyAttackCardDivineRoseLinesFrench[12] = {
    gJiminyAttackCardDivineRoseLine0French, gJiminyAttackCardDivineRoseLine1French, gJiminyAttackCardDivineRoseLine2French, gJiminyAttackCardDivineRoseLine3French,
    gJiminyAttackCardDivineRoseLine4French, gJiminyAttackCardDivineRoseLine5French, gJiminyAttackCardDivineRoseLine6French, gJiminyAttackCardDivineRoseLine7French,
    gJiminyAttackCardDivineRoseLine8French, gJiminyAttackCardDivineRoseLine9French, gJiminyAttackCardDivineRoseLine10French, gJiminyAttackCardDivineRoseLine11French,
};

const JiminyTextChar* gJiminyAttackCardDivineRoseLinesGerman[12] = {
    gJiminyAttackCardDivineRoseLine0German, gJiminyAttackCardDivineRoseLine1German, gJiminyAttackCardDivineRoseLine2German, gJiminyAttackCardDivineRoseLine3German,
    gJiminyAttackCardDivineRoseLine4German, gJiminyAttackCardDivineRoseLine5German, gJiminyAttackCardDivineRoseLine6German, gJiminyAttackCardDivineRoseLine7German,
    gJiminyAttackCardDivineRoseLine8German, gJiminyAttackCardDivineRoseLine9German, gJiminyAttackCardDivineRoseLine10German, gJiminyAttackCardDivineRoseLine11German,
};

const JiminyTextChar* gJiminyAttackCardDivineRoseLinesItalian[11] = {
    gJiminyAttackCardDivineRoseLine0Italian, gJiminyAttackCardDivineRoseLine1Italian, gJiminyAttackCardDivineRoseLine2Italian, gJiminyAttackCardDivineRoseLine3Italian,
    gJiminyAttackCardDivineRoseLine4Italian, gJiminyAttackCardDivineRoseLine5Italian, gJiminyAttackCardDivineRoseLine6Italian, gJiminyAttackCardDivineRoseLine7Italian,
    gJiminyAttackCardDivineRoseLine8Italian, gJiminyAttackCardDivineRoseLine9Italian, gJiminyAttackCardDivineRoseLine10Italian,
};

const JiminyTextChar* gJiminyAttackCardDivineRoseLinesSpanish[12] = {
    gJiminyAttackCardDivineRoseLine0Spanish, gJiminyAttackCardDivineRoseLine1Spanish, gJiminyAttackCardDivineRoseLine2Spanish, gJiminyAttackCardDivineRoseLine3Spanish,
    gJiminyAttackCardDivineRoseLine4Spanish, gJiminyAttackCardDivineRoseLine5Spanish, gJiminyAttackCardDivineRoseLine6Spanish, gJiminyAttackCardDivineRoseLine7Spanish,
    gJiminyAttackCardDivineRoseLine8Spanish, gJiminyAttackCardDivineRoseLine9Spanish, gJiminyAttackCardDivineRoseLine10Spanish, gJiminyAttackCardDivineRoseLine11Spanish,
};

const JiminyTextChar* gJiminyAttackCardOathkeeperLines[11] = {
    gJiminyAttackCardOathkeeperLine0, gJiminyAttackCardOathkeeperLine1, gJiminyAttackCardOathkeeperLine2, gJiminyAttackCardOathkeeperLine3,
    gJiminyAttackCardOathkeeperLine4, gJiminyAttackCardOathkeeperLine5, gJiminyAttackCardOathkeeperLine6, gJiminyAttackCardOathkeeperLine7,
    gJiminyAttackCardOathkeeperLine8, gJiminyAttackCardOathkeeperLine9, gJiminyAttackCardOathkeeperLine10,
};

const JiminyTextChar* gJiminyAttackCardOathkeeperLinesFrench[11] = {
    gJiminyAttackCardOathkeeperLine0French, gJiminyAttackCardOathkeeperLine1French, gJiminyAttackCardOathkeeperLine2French, gJiminyAttackCardOathkeeperLine3French,
    gJiminyAttackCardOathkeeperLine4French, gJiminyAttackCardOathkeeperLine5French, gJiminyAttackCardOathkeeperLine6French, gJiminyAttackCardOathkeeperLine7French,
    gJiminyAttackCardOathkeeperLine8French, gJiminyAttackCardOathkeeperLine9French, gJiminyAttackCardOathkeeperLine10French,
};

const JiminyTextChar* gJiminyAttackCardOathkeeperLinesGerman[11] = {
    gJiminyAttackCardOathkeeperLine0German, gJiminyAttackCardOathkeeperLine1German, gJiminyAttackCardOathkeeperLine2German, gJiminyAttackCardOathkeeperLine3German,
    gJiminyAttackCardOathkeeperLine4German, gJiminyAttackCardOathkeeperLine5German, gJiminyAttackCardOathkeeperLine6German, gJiminyAttackCardOathkeeperLine7German,
    gJiminyAttackCardOathkeeperLine8German, gJiminyAttackCardOathkeeperLine9German, gJiminyAttackCardOathkeeperLine10German,
};

const JiminyTextChar* gJiminyAttackCardOathkeeperLinesItalian[11] = {
    gJiminyAttackCardOathkeeperLine0Italian, gJiminyAttackCardOathkeeperLine1Italian, gJiminyAttackCardOathkeeperLine2Italian, gJiminyAttackCardOathkeeperLine3Italian,
    gJiminyAttackCardOathkeeperLine4Italian, gJiminyAttackCardOathkeeperLine5Italian, gJiminyAttackCardOathkeeperLine6Italian, gJiminyAttackCardOathkeeperLine7Italian,
    gJiminyAttackCardOathkeeperLine8Italian, gJiminyAttackCardOathkeeperLine9Italian, gJiminyAttackCardOathkeeperLine10Italian,
};

const JiminyTextChar* gJiminyAttackCardOathkeeperLinesSpanish[10] = {
    gJiminyAttackCardOathkeeperLine0Spanish, gJiminyAttackCardOathkeeperLine1Spanish, gJiminyAttackCardOathkeeperLine2Spanish, gJiminyAttackCardOathkeeperLine3Spanish,
    gJiminyAttackCardOathkeeperLine4Spanish, gJiminyAttackCardOathkeeperLine5Spanish, gJiminyAttackCardOathkeeperLine6Spanish, gJiminyAttackCardOathkeeperLine7Spanish,
    gJiminyAttackCardOathkeeperLine8Spanish, gJiminyAttackCardOathkeeperLine9Spanish,
};

const JiminyTextChar* gJiminyAttackCardOblivionLines[12] = {
    gJiminyAttackCardOblivionLine0, gJiminyAttackCardOblivionLine1, gJiminyAttackCardOblivionLine2, gJiminyAttackCardOblivionLine3,
    gJiminyAttackCardOblivionLine4, gJiminyAttackCardOblivionLine5, gJiminyAttackCardOblivionLine6, gJiminyAttackCardOblivionLine7,
    gJiminyAttackCardOblivionLine8, gJiminyAttackCardOblivionLine9, gJiminyAttackCardOblivionLine10, gJiminyAttackCardOblivionLine11,
};

const JiminyTextChar* gJiminyAttackCardOblivionLinesFrench[12] = {
    gJiminyAttackCardOblivionLine0French, gJiminyAttackCardOblivionLine1French, gJiminyAttackCardOblivionLine2French, gJiminyAttackCardOblivionLine3French,
    gJiminyAttackCardOblivionLine4French, gJiminyAttackCardOblivionLine5French, gJiminyAttackCardOblivionLine6French, gJiminyAttackCardOblivionLine7French,
    gJiminyAttackCardOblivionLine8French, gJiminyAttackCardOblivionLine9French, gJiminyAttackCardOblivionLine10French, gJiminyAttackCardOblivionLine11French,
};

const JiminyTextChar* gJiminyAttackCardOblivionLinesGerman[14] = {
    gJiminyAttackCardOblivionLine0German, gJiminyAttackCardOblivionLine1German, gJiminyAttackCardOblivionLine2German, gJiminyAttackCardOblivionLine3German,
    gJiminyAttackCardOblivionLine4German, gJiminyAttackCardOblivionLine5German, gJiminyAttackCardOblivionLine6German, gJiminyAttackCardOblivionLine7German,
    gJiminyAttackCardOblivionLine8German, gJiminyAttackCardOblivionLine9German, gJiminyAttackCardOblivionLine10German, gJiminyAttackCardOblivionLine11German,
    gJiminyAttackCardOblivionLine12German, gJiminyAttackCardOblivionLine13German,
};

const JiminyTextChar* gJiminyAttackCardOblivionLinesItalian[13] = {
    gJiminyAttackCardOblivionLine0Italian, gJiminyAttackCardOblivionLine1Italian, gJiminyAttackCardOblivionLine2Italian, gJiminyAttackCardOblivionLine3Italian,
    gJiminyAttackCardOblivionLine4Italian, gJiminyAttackCardOblivionLine5Italian, gJiminyAttackCardOblivionLine6Italian, gJiminyAttackCardOblivionLine7Italian,
    gJiminyAttackCardOblivionLine8Italian, gJiminyAttackCardOblivionLine9Italian, gJiminyAttackCardOblivionLine10Italian, gJiminyAttackCardOblivionLine11Italian,
    gJiminyAttackCardOblivionLine12Italian,
};

const JiminyTextChar* gJiminyAttackCardOblivionLinesSpanish[12] = {
    gJiminyAttackCardOblivionLine0Spanish, gJiminyAttackCardOblivionLine1Spanish, gJiminyAttackCardOblivionLine2Spanish, gJiminyAttackCardOblivionLine3Spanish,
    gJiminyAttackCardOblivionLine4Spanish, gJiminyAttackCardOblivionLine5Spanish, gJiminyAttackCardOblivionLine6Spanish, gJiminyAttackCardOblivionLine7Spanish,
    gJiminyAttackCardOblivionLine8Spanish, gJiminyAttackCardOblivionLine9Spanish, gJiminyAttackCardOblivionLine10Spanish, gJiminyAttackCardOblivionLine11Spanish,
};

const JiminyTextChar* gJiminyAttackCardDiamondDustLines[12] = {
    gJiminyAttackCardDiamondDustLine0, gJiminyAttackCardDiamondDustLine1, gJiminyAttackCardDiamondDustLine2, gJiminyAttackCardDiamondDustLine3,
    gJiminyAttackCardDiamondDustLine4, gJiminyAttackCardDiamondDustLine5, gJiminyAttackCardDiamondDustLine6, gJiminyAttackCardDiamondDustLine7,
    gJiminyAttackCardDiamondDustLine8, gJiminyAttackCardDiamondDustLine9, gJiminyAttackCardDiamondDustLine10, gJiminyAttackCardDiamondDustLine11,
};

const JiminyTextChar* gJiminyAttackCardDiamondDustLinesFrench[12] = {
    gJiminyAttackCardDiamondDustLine0French, gJiminyAttackCardDiamondDustLine1French, gJiminyAttackCardDiamondDustLine2French, gJiminyAttackCardDiamondDustLine3French,
    gJiminyAttackCardDiamondDustLine4French, gJiminyAttackCardDiamondDustLine5French, gJiminyAttackCardDiamondDustLine6French, gJiminyAttackCardDiamondDustLine7French,
    gJiminyAttackCardDiamondDustLine8French, gJiminyAttackCardDiamondDustLine9French, gJiminyAttackCardDiamondDustLine10French, gJiminyAttackCardDiamondDustLine11French,
};

const JiminyTextChar* gJiminyAttackCardDiamondDustLinesGerman[14] = {
    gJiminyAttackCardDiamondDustLine0German, gJiminyAttackCardDiamondDustLine1German, gJiminyAttackCardDiamondDustLine2German, gJiminyAttackCardDiamondDustLine3German,
    gJiminyAttackCardDiamondDustLine4German, gJiminyAttackCardDiamondDustLine5German, gJiminyAttackCardDiamondDustLine6German, gJiminyAttackCardDiamondDustLine7German,
    gJiminyAttackCardDiamondDustLine8German, gJiminyAttackCardDiamondDustLine9German, gJiminyAttackCardDiamondDustLine10German, gJiminyAttackCardDiamondDustLine11German,
    gJiminyAttackCardDiamondDustLine12German, gJiminyAttackCardDiamondDustLine13German,
};

const JiminyTextChar* gJiminyAttackCardDiamondDustLinesItalian[14] = {
    gJiminyAttackCardDiamondDustLine0Italian, gJiminyAttackCardDiamondDustLine1Italian, gJiminyAttackCardDiamondDustLine2Italian, gJiminyAttackCardDiamondDustLine3Italian,
    gJiminyAttackCardDiamondDustLine4Italian, gJiminyAttackCardDiamondDustLine5Italian, gJiminyAttackCardDiamondDustLine6Italian, gJiminyAttackCardDiamondDustLine7Italian,
    gJiminyAttackCardDiamondDustLine8Italian, gJiminyAttackCardDiamondDustLine9Italian, gJiminyAttackCardDiamondDustLine10Italian, gJiminyAttackCardDiamondDustLine11Italian,
    gJiminyAttackCardDiamondDustLine12Italian, gJiminyAttackCardDiamondDustLine13Italian,
};

const JiminyTextChar* gJiminyAttackCardDiamondDustLinesSpanish[12] = {
    gJiminyAttackCardDiamondDustLine0Spanish, gJiminyAttackCardDiamondDustLine1Spanish, gJiminyAttackCardDiamondDustLine2Spanish, gJiminyAttackCardDiamondDustLine3Spanish,
    gJiminyAttackCardDiamondDustLine4Spanish, gJiminyAttackCardDiamondDustLine5Spanish, gJiminyAttackCardDiamondDustLine6Spanish, gJiminyAttackCardDiamondDustLine7Spanish,
    gJiminyAttackCardDiamondDustLine8Spanish, gJiminyAttackCardDiamondDustLine9Spanish, gJiminyAttackCardDiamondDustLine10Spanish, gJiminyAttackCardDiamondDustLine11Spanish,
};

const JiminyTextChar* gJiminyAttackCardOneWingedAngelLines[12] = {
    gJiminyAttackCardOneWingedAngelLine0, gJiminyAttackCardOneWingedAngelLine1, gJiminyAttackCardOneWingedAngelLine2, gJiminyAttackCardOneWingedAngelLine3,
    gJiminyAttackCardOneWingedAngelLine4, gJiminyAttackCardOneWingedAngelLine5, gJiminyAttackCardOneWingedAngelLine6, gJiminyAttackCardOneWingedAngelLine7,
    gJiminyAttackCardOneWingedAngelLine8, gJiminyAttackCardOneWingedAngelLine9, gJiminyAttackCardOneWingedAngelLine10, gJiminyAttackCardOneWingedAngelLine11,
};

const JiminyTextChar* gJiminyAttackCardOneWingedAngelLinesFrench[12] = {
    gJiminyAttackCardOneWingedAngelLine0French, gJiminyAttackCardOneWingedAngelLine1French, gJiminyAttackCardOneWingedAngelLine2French, gJiminyAttackCardOneWingedAngelLine3French,
    gJiminyAttackCardOneWingedAngelLine4French, gJiminyAttackCardOneWingedAngelLine5French, gJiminyAttackCardOneWingedAngelLine6French, gJiminyAttackCardOneWingedAngelLine7French,
    gJiminyAttackCardOneWingedAngelLine8French, gJiminyAttackCardOneWingedAngelLine9French, gJiminyAttackCardOneWingedAngelLine10French, gJiminyAttackCardOneWingedAngelLine11French,
};

const JiminyTextChar* gJiminyAttackCardOneWingedAngelLinesGerman[13] = {
    gJiminyAttackCardOneWingedAngelLine0German, gJiminyAttackCardOneWingedAngelLine1German, gJiminyAttackCardOneWingedAngelLine2German, gJiminyAttackCardOneWingedAngelLine3German,
    gJiminyAttackCardOneWingedAngelLine4German, gJiminyAttackCardOneWingedAngelLine5German, gJiminyAttackCardOneWingedAngelLine6German, gJiminyAttackCardOneWingedAngelLine7German,
    gJiminyAttackCardOneWingedAngelLine8German, gJiminyAttackCardOneWingedAngelLine9German, gJiminyAttackCardOneWingedAngelLine10German, gJiminyAttackCardOneWingedAngelLine11German,
    gJiminyAttackCardOneWingedAngelLine12German,
};

const JiminyTextChar* gJiminyAttackCardOneWingedAngelLinesItalian[13] = {
    gJiminyAttackCardOneWingedAngelLine0Italian, gJiminyAttackCardOneWingedAngelLine1Italian, gJiminyAttackCardOneWingedAngelLine2Italian, gJiminyAttackCardOneWingedAngelLine3Italian,
    gJiminyAttackCardOneWingedAngelLine4Italian, gJiminyAttackCardOneWingedAngelLine5Italian, gJiminyAttackCardOneWingedAngelLine6Italian, gJiminyAttackCardOneWingedAngelLine7Italian,
    gJiminyAttackCardOneWingedAngelLine8Italian, gJiminyAttackCardOneWingedAngelLine9Italian, gJiminyAttackCardOneWingedAngelLine10Italian, gJiminyAttackCardOneWingedAngelLine11Italian,
    gJiminyAttackCardOneWingedAngelLine12Italian,
};

const JiminyTextChar* gJiminyAttackCardOneWingedAngelLinesSpanish[14] = {
    gJiminyAttackCardOneWingedAngelLine0Spanish, gJiminyAttackCardOneWingedAngelLine1Spanish, gJiminyAttackCardOneWingedAngelLine2Spanish, gJiminyAttackCardOneWingedAngelLine3Spanish,
    gJiminyAttackCardOneWingedAngelLine4Spanish, gJiminyAttackCardOneWingedAngelLine5Spanish, gJiminyAttackCardOneWingedAngelLine6Spanish, gJiminyAttackCardOneWingedAngelLine7Spanish,
    gJiminyAttackCardOneWingedAngelLine8Spanish, gJiminyAttackCardOneWingedAngelLine9Spanish, gJiminyAttackCardOneWingedAngelLine10Spanish, gJiminyAttackCardOneWingedAngelLine11Spanish,
    gJiminyAttackCardOneWingedAngelLine12Spanish, gJiminyAttackCardOneWingedAngelLine13Spanish,
};

const JiminyTextChar* gJiminyAttackCardUltimaWeaponLines[10] = {
    gJiminyAttackCardUltimaWeaponLine0, gJiminyAttackCardUltimaWeaponLine1, gJiminyAttackCardUltimaWeaponLine2, gJiminyAttackCardUltimaWeaponLine3,
    gJiminyAttackCardUltimaWeaponLine4, gJiminyAttackCardUltimaWeaponLine5, gJiminyAttackCardUltimaWeaponLine6, gJiminyAttackCardUltimaWeaponLine7,
    gJiminyAttackCardUltimaWeaponLine8, gJiminyAttackCardUltimaWeaponLine9,
};

const JiminyTextChar* gJiminyAttackCardUltimaWeaponLinesFrench[10] = {
    gJiminyAttackCardUltimaWeaponLine0French, gJiminyAttackCardUltimaWeaponLine1French, gJiminyAttackCardUltimaWeaponLine2French, gJiminyAttackCardUltimaWeaponLine3French,
    gJiminyAttackCardUltimaWeaponLine4French, gJiminyAttackCardUltimaWeaponLine5French, gJiminyAttackCardUltimaWeaponLine6French, gJiminyAttackCardUltimaWeaponLine7French,
    gJiminyAttackCardUltimaWeaponLine8French, gJiminyAttackCardUltimaWeaponLine9French,
};

const JiminyTextChar* gJiminyAttackCardUltimaWeaponLinesGerman[11] = {
    gJiminyAttackCardUltimaWeaponLine0German, gJiminyAttackCardUltimaWeaponLine1German, gJiminyAttackCardUltimaWeaponLine2German, gJiminyAttackCardUltimaWeaponLine3German,
    gJiminyAttackCardUltimaWeaponLine4German, gJiminyAttackCardUltimaWeaponLine5German, gJiminyAttackCardUltimaWeaponLine6German, gJiminyAttackCardUltimaWeaponLine7German,
    gJiminyAttackCardUltimaWeaponLine8German, gJiminyAttackCardUltimaWeaponLine9German, gJiminyAttackCardUltimaWeaponLine10German,
};

const JiminyTextChar* gJiminyAttackCardUltimaWeaponLinesItalian[10] = {
    gJiminyAttackCardUltimaWeaponLine0Italian, gJiminyAttackCardUltimaWeaponLine1Italian, gJiminyAttackCardUltimaWeaponLine2Italian, gJiminyAttackCardUltimaWeaponLine3Italian,
    gJiminyAttackCardUltimaWeaponLine4Italian, gJiminyAttackCardUltimaWeaponLine5Italian, gJiminyAttackCardUltimaWeaponLine6Italian, gJiminyAttackCardUltimaWeaponLine7Italian,
    gJiminyAttackCardUltimaWeaponLine8Italian, gJiminyAttackCardUltimaWeaponLine9Italian,
};

const JiminyTextChar* gJiminyAttackCardUltimaWeaponLinesSpanish[11] = {
    gJiminyAttackCardUltimaWeaponLine0Spanish, gJiminyAttackCardUltimaWeaponLine1Spanish, gJiminyAttackCardUltimaWeaponLine2Spanish, gJiminyAttackCardUltimaWeaponLine3Spanish,
    gJiminyAttackCardUltimaWeaponLine4Spanish, gJiminyAttackCardUltimaWeaponLine5Spanish, gJiminyAttackCardUltimaWeaponLine6Spanish, gJiminyAttackCardUltimaWeaponLine7Spanish,
    gJiminyAttackCardUltimaWeaponLine8Spanish, gJiminyAttackCardUltimaWeaponLine9Spanish, gJiminyAttackCardUltimaWeaponLine10Spanish,
};

const JiminyTextChar* gJiminyMagicCardFireLines[4] = {
    gJiminyMagicCardFireLine0, gJiminyMagicCardFireLine1, gJiminyMagicCardFireLine2, gJiminyMagicCardFireLine3,
};

const JiminyTextChar* gJiminyMagicCardFireLinesFrench[4] = {
    gJiminyMagicCardFireLine0French, gJiminyMagicCardFireLine1French, gJiminyMagicCardFireLine2French, gJiminyMagicCardFireLine3French,
};

const JiminyTextChar* gJiminyMagicCardFireLinesGerman[5] = {
    gJiminyMagicCardFireLine0German, gJiminyMagicCardFireLine1German, gJiminyMagicCardFireLine2German, gJiminyMagicCardFireLine3German,
    gJiminyMagicCardFireLine4German,
};

const JiminyTextChar* gJiminyMagicCardFireLinesItalian[6] = {
    gJiminyMagicCardFireLine0Italian, gJiminyMagicCardFireLine1Italian, gJiminyMagicCardFireLine2Italian, gJiminyMagicCardFireLine3Italian,
    gJiminyMagicCardFireLine4Italian, gJiminyMagicCardFireLine5Italian,
};

const JiminyTextChar* gJiminyMagicCardFireLinesSpanish[5] = {
    gJiminyMagicCardFireLine0Spanish, gJiminyMagicCardFireLine1Spanish, gJiminyMagicCardFireLine2Spanish, gJiminyMagicCardFireLine3Spanish,
    gJiminyMagicCardFireLine4Spanish,
};

const JiminyTextChar* gJiminyMagicCardBlizzardLines[4] = {
    gJiminyMagicCardBlizzardLine0, gJiminyMagicCardBlizzardLine1, gJiminyMagicCardBlizzardLine2, gJiminyMagicCardBlizzardLine3,
};

const JiminyTextChar* gJiminyMagicCardBlizzardLinesFrench[4] = {
    gJiminyMagicCardBlizzardLine0French, gJiminyMagicCardBlizzardLine1French, gJiminyMagicCardBlizzardLine2French, gJiminyMagicCardBlizzardLine3French,
};

const JiminyTextChar* gJiminyMagicCardBlizzardLinesGerman[4] = {
    gJiminyMagicCardBlizzardLine0German, gJiminyMagicCardBlizzardLine1German, gJiminyMagicCardBlizzardLine2German, gJiminyMagicCardBlizzardLine3German,
};

const JiminyTextChar* gJiminyMagicCardBlizzardLinesItalian[6] = {
    gJiminyMagicCardBlizzardLine0Italian, gJiminyMagicCardBlizzardLine1Italian, gJiminyMagicCardBlizzardLine2Italian, gJiminyMagicCardBlizzardLine3Italian,
    gJiminyMagicCardBlizzardLine4Italian, gJiminyMagicCardBlizzardLine5Italian,
};

const JiminyTextChar* gJiminyMagicCardBlizzardLinesSpanish[5] = {
    gJiminyMagicCardBlizzardLine0Spanish, gJiminyMagicCardBlizzardLine1Spanish, gJiminyMagicCardBlizzardLine2Spanish, gJiminyMagicCardBlizzardLine3Spanish,
    gJiminyMagicCardBlizzardLine4Spanish,
};

const JiminyTextChar* gJiminyMagicCardThunderLines[5] = {
    gJiminyMagicCardThunderLine0, gJiminyMagicCardThunderLine1, gJiminyMagicCardThunderLine2, gJiminyMagicCardThunderLine3,
    gJiminyMagicCardThunderLine4,
};

const JiminyTextChar* gJiminyMagicCardThunderLinesFrench[4] = {
    gJiminyMagicCardThunderLine0French, gJiminyMagicCardThunderLine1French, gJiminyMagicCardThunderLine2French, gJiminyMagicCardThunderLine3French,
};

const JiminyTextChar* gJiminyMagicCardThunderLinesGerman[5] = {
    gJiminyMagicCardThunderLine0German, gJiminyMagicCardThunderLine1German, gJiminyMagicCardThunderLine2German, gJiminyMagicCardThunderLine3German,
    gJiminyMagicCardThunderLine4German,
};

const JiminyTextChar* gJiminyMagicCardThunderLinesItalian[6] = {
    gJiminyMagicCardThunderLine0Italian, gJiminyMagicCardThunderLine1Italian, gJiminyMagicCardThunderLine2Italian, gJiminyMagicCardThunderLine3Italian,
    gJiminyMagicCardThunderLine4Italian, gJiminyMagicCardThunderLine5Italian,
};

const JiminyTextChar* gJiminyMagicCardThunderLinesSpanish[5] = {
    gJiminyMagicCardThunderLine0Spanish, gJiminyMagicCardThunderLine1Spanish, gJiminyMagicCardThunderLine2Spanish, gJiminyMagicCardThunderLine3Spanish,
    gJiminyMagicCardThunderLine4Spanish,
};

const JiminyTextChar* gJiminyMagicCardCureLines[3] = {
    gJiminyMagicCardCureLine0, gJiminyMagicCardCureLine1, gJiminyMagicCardCureLine2,
};

const JiminyTextChar* gJiminyMagicCardCureLinesFrench[4] = {
    gJiminyMagicCardCureLine0French, gJiminyMagicCardCureLine1French, gJiminyMagicCardCureLine2French, gJiminyMagicCardCureLine3French,
};

const JiminyTextChar* gJiminyMagicCardCureLinesGerman[5] = {
    gJiminyMagicCardCureLine0German, gJiminyMagicCardCureLine1German, gJiminyMagicCardCureLine2German, gJiminyMagicCardCureLine3German,
    gJiminyMagicCardCureLine4German,
};

const JiminyTextChar* gJiminyMagicCardCureLinesItalian[4] = {
    gJiminyMagicCardCureLine0Italian, gJiminyMagicCardCureLine1Italian, gJiminyMagicCardCureLine2Italian, gJiminyMagicCardCureLine3Italian,
};

const JiminyTextChar* gJiminyMagicCardCureLinesSpanish[4] = {
    gJiminyMagicCardCureLine0Spanish, gJiminyMagicCardCureLine1Spanish, gJiminyMagicCardCureLine2Spanish, gJiminyMagicCardCureLine3Spanish,
};

const JiminyTextChar* gJiminyMagicCardGravityLines[5] = {
    gJiminyMagicCardGravityLine0, gJiminyMagicCardGravityLine1, gJiminyMagicCardGravityLine2, gJiminyMagicCardGravityLine3,
    gJiminyMagicCardGravityLine4,
};

const JiminyTextChar* gJiminyMagicCardGravityLinesFrench[5] = {
    gJiminyMagicCardGravityLine0French, gJiminyMagicCardGravityLine1French, gJiminyMagicCardGravityLine2French, gJiminyMagicCardGravityLine3French,
    gJiminyMagicCardGravityLine4French,
};

const JiminyTextChar* gJiminyMagicCardGravityLinesGerman[7] = {
    gJiminyMagicCardGravityLine0German, gJiminyMagicCardGravityLine1German, gJiminyMagicCardGravityLine2German, gJiminyMagicCardGravityLine3German,
    gJiminyMagicCardGravityLine4German, gJiminyMagicCardGravityLine5German, gJiminyMagicCardGravityLine6German,
};

const JiminyTextChar* gJiminyMagicCardGravityLinesItalian[7] = {
    gJiminyMagicCardGravityLine0Italian, gJiminyMagicCardGravityLine1Italian, gJiminyMagicCardGravityLine2Italian, gJiminyMagicCardGravityLine3Italian,
    gJiminyMagicCardGravityLine4Italian, gJiminyMagicCardGravityLine5Italian, gJiminyMagicCardGravityLine6Italian,
};

const JiminyTextChar* gJiminyMagicCardGravityLinesSpanish[6] = {
    gJiminyMagicCardGravityLine0Spanish, gJiminyMagicCardGravityLine1Spanish, gJiminyMagicCardGravityLine2Spanish, gJiminyMagicCardGravityLine3Spanish,
    gJiminyMagicCardGravityLine4Spanish, gJiminyMagicCardGravityLine5Spanish,
};

const JiminyTextChar* gJiminyMagicCardStopLines[5] = {
    gJiminyMagicCardStopLine0, gJiminyMagicCardStopLine1, gJiminyMagicCardStopLine2, gJiminyMagicCardStopLine3,
    gJiminyMagicCardStopLine4,
};

const JiminyTextChar* gJiminyMagicCardStopLinesFrench[5] = {
    gJiminyMagicCardStopLine0French, gJiminyMagicCardStopLine1French, gJiminyMagicCardStopLine2French, gJiminyMagicCardStopLine3French,
    gJiminyMagicCardStopLine4French,
};

const JiminyTextChar* gJiminyMagicCardStopLinesGerman[7] = {
    gJiminyMagicCardStopLine0German, gJiminyMagicCardStopLine1German, gJiminyMagicCardStopLine2German, gJiminyMagicCardStopLine3German,
    gJiminyMagicCardStopLine4German, gJiminyMagicCardStopLine5German, gJiminyMagicCardStopLine6German,
};

const JiminyTextChar* gJiminyMagicCardStopLinesItalian[6] = {
    gJiminyMagicCardStopLine0Italian, gJiminyMagicCardStopLine1Italian, gJiminyMagicCardStopLine2Italian, gJiminyMagicCardStopLine3Italian,
    gJiminyMagicCardStopLine4Italian, gJiminyMagicCardStopLine5Italian,
};

const JiminyTextChar* gJiminyMagicCardStopLinesSpanish[6] = {
    gJiminyMagicCardStopLine0Spanish, gJiminyMagicCardStopLine1Spanish, gJiminyMagicCardStopLine2Spanish, gJiminyMagicCardStopLine3Spanish,
    gJiminyMagicCardStopLine4Spanish, gJiminyMagicCardStopLine5Spanish,
};

const JiminyTextChar* gJiminyMagicCardAeroLines[5] = {
    gJiminyMagicCardAeroLine0, gJiminyMagicCardAeroLine1, gJiminyMagicCardAeroLine2, gJiminyMagicCardAeroLine3,
    gJiminyMagicCardAeroLine4,
};

const JiminyTextChar* gJiminyMagicCardAeroLinesFrench[5] = {
    gJiminyMagicCardAeroLine0French, gJiminyMagicCardAeroLine1French, gJiminyMagicCardAeroLine2French, gJiminyMagicCardAeroLine3French,
    gJiminyMagicCardAeroLine4French,
};

const JiminyTextChar* gJiminyMagicCardAeroLinesGerman[7] = {
    gJiminyMagicCardAeroLine0German, gJiminyMagicCardAeroLine1German, gJiminyMagicCardAeroLine2German, gJiminyMagicCardAeroLine3German,
    gJiminyMagicCardAeroLine4German, gJiminyMagicCardAeroLine5German, gJiminyMagicCardAeroLine6German,
};

const JiminyTextChar* gJiminyMagicCardAeroLinesItalian[6] = {
    gJiminyMagicCardAeroLine0Italian, gJiminyMagicCardAeroLine1Italian, gJiminyMagicCardAeroLine2Italian, gJiminyMagicCardAeroLine3Italian,
    gJiminyMagicCardAeroLine4Italian, gJiminyMagicCardAeroLine5Italian,
};

const JiminyTextChar* gJiminyMagicCardAeroLinesSpanish[6] = {
    gJiminyMagicCardAeroLine0Spanish, gJiminyMagicCardAeroLine1Spanish, gJiminyMagicCardAeroLine2Spanish, gJiminyMagicCardAeroLine3Spanish,
    gJiminyMagicCardAeroLine4Spanish, gJiminyMagicCardAeroLine5Spanish,
};

const JiminyTextChar* gJiminyMagicCardSimbaLines[6] = {
    gJiminyMagicCardSimbaLine0, gJiminyMagicCardSimbaLine1, gJiminyMagicCardSimbaLine2, gJiminyMagicCardSimbaLine3,
    gJiminyMagicCardSimbaLine4, gJiminyMagicCardSimbaLine5,
};

const JiminyTextChar* gJiminyMagicCardSimbaLinesFrench[6] = {
    gJiminyMagicCardSimbaLine0French, gJiminyMagicCardSimbaLine1French, gJiminyMagicCardSimbaLine2French, gJiminyMagicCardSimbaLine3French,
    gJiminyMagicCardSimbaLine4French, gJiminyMagicCardSimbaLine5French,
};

const JiminyTextChar* gJiminyMagicCardSimbaLinesGerman[8] = {
    gJiminyMagicCardSimbaLine0German, gJiminyMagicCardSimbaLine1German, gJiminyMagicCardSimbaLine2German, gJiminyMagicCardSimbaLine3German,
    gJiminyMagicCardSimbaLine4German, gJiminyMagicCardSimbaLine5German, gJiminyMagicCardSimbaLine6German, gJiminyMagicCardSimbaLine7German,
};

const JiminyTextChar* gJiminyMagicCardSimbaLinesItalian[6] = {
    gJiminyMagicCardSimbaLine0Italian, gJiminyMagicCardSimbaLine1Italian, gJiminyMagicCardSimbaLine2Italian, gJiminyMagicCardSimbaLine3Italian,
    gJiminyMagicCardSimbaLine4Italian, gJiminyMagicCardSimbaLine5Italian,
};

const JiminyTextChar* gJiminyMagicCardSimbaLinesSpanish[8] = {
    gJiminyMagicCardSimbaLine0Spanish, gJiminyMagicCardSimbaLine1Spanish, gJiminyMagicCardSimbaLine2Spanish, gJiminyMagicCardSimbaLine3Spanish,
    gJiminyMagicCardSimbaLine4Spanish, gJiminyMagicCardSimbaLine5Spanish, gJiminyMagicCardSimbaLine6Spanish, gJiminyMagicCardSimbaLine7Spanish,
};

const JiminyTextChar* gJiminyMagicCardGenieLines[5] = {
    gJiminyMagicCardGenieLine0, gJiminyMagicCardGenieLine1, gJiminyMagicCardGenieLine2, gJiminyMagicCardGenieLine3,
    gJiminyMagicCardGenieLine4,
};

const JiminyTextChar* gJiminyMagicCardGenieLinesFrench[5] = {
    gJiminyMagicCardGenieLine0French, gJiminyMagicCardGenieLine1French, gJiminyMagicCardGenieLine2French, gJiminyMagicCardGenieLine3French,
    gJiminyMagicCardGenieLine4French,
};

const JiminyTextChar* gJiminyMagicCardGenieLinesGerman[7] = {
    gJiminyMagicCardGenieLine0German, gJiminyMagicCardGenieLine1German, gJiminyMagicCardGenieLine2German, gJiminyMagicCardGenieLine3German,
    gJiminyMagicCardGenieLine4German, gJiminyMagicCardGenieLine5German, gJiminyMagicCardGenieLine6German,
};

const JiminyTextChar* gJiminyMagicCardGenieLinesItalian[5] = {
    gJiminyMagicCardGenieLine0Italian, gJiminyMagicCardGenieLine1Italian, gJiminyMagicCardGenieLine2Italian, gJiminyMagicCardGenieLine3Italian,
    gJiminyMagicCardGenieLine4Italian,
};

const JiminyTextChar* gJiminyMagicCardGenieLinesSpanish[6] = {
    gJiminyMagicCardGenieLine0Spanish, gJiminyMagicCardGenieLine1Spanish, gJiminyMagicCardGenieLine2Spanish, gJiminyMagicCardGenieLine3Spanish,
    gJiminyMagicCardGenieLine4Spanish, gJiminyMagicCardGenieLine5Spanish,
};

const JiminyTextChar* gJiminyMagicCardBambiLines[4] = {
    gJiminyMagicCardBambiLine0, gJiminyMagicCardBambiLine1, gJiminyMagicCardBambiLine2, gJiminyMagicCardBambiLine3,
};

const JiminyTextChar* gJiminyMagicCardBambiLinesFrench[4] = {
    gJiminyMagicCardBambiLine0French, gJiminyMagicCardBambiLine1French, gJiminyMagicCardBambiLine2French, gJiminyMagicCardBambiLine3French,
};

const JiminyTextChar* gJiminyMagicCardBambiLinesGerman[5] = {
    gJiminyMagicCardBambiLine0German, gJiminyMagicCardBambiLine1German, gJiminyMagicCardBambiLine2German, gJiminyMagicCardBambiLine3German,
    gJiminyMagicCardBambiLine4German,
};

const JiminyTextChar* gJiminyMagicCardBambiLinesItalian[5] = {
    gJiminyMagicCardBambiLine0Italian, gJiminyMagicCardBambiLine1Italian, gJiminyMagicCardBambiLine2Italian, gJiminyMagicCardBambiLine3Italian,
    gJiminyMagicCardBambiLine4Italian,
};

const JiminyTextChar* gJiminyMagicCardBambiLinesSpanish[5] = {
    gJiminyMagicCardBambiLine0Spanish, gJiminyMagicCardBambiLine1Spanish, gJiminyMagicCardBambiLine2Spanish, gJiminyMagicCardBambiLine3Spanish,
    gJiminyMagicCardBambiLine4Spanish,
};

const JiminyTextChar* gJiminyMagicCardDumboLines[6] = {
    gJiminyMagicCardDumboLine0, gJiminyMagicCardDumboLine1, gJiminyMagicCardDumboLine2, gJiminyMagicCardDumboLine3,
    gJiminyMagicCardDumboLine4, gJiminyMagicCardDumboLine5,
};

const JiminyTextChar* gJiminyMagicCardDumboLinesFrench[6] = {
    gJiminyMagicCardDumboLine0French, gJiminyMagicCardDumboLine1French, gJiminyMagicCardDumboLine2French, gJiminyMagicCardDumboLine3French,
    gJiminyMagicCardDumboLine4French, gJiminyMagicCardDumboLine5French,
};

const JiminyTextChar* gJiminyMagicCardDumboLinesGerman[7] = {
    gJiminyMagicCardDumboLine0German, gJiminyMagicCardDumboLine1German, gJiminyMagicCardDumboLine2German, gJiminyMagicCardDumboLine3German,
    gJiminyMagicCardDumboLine4German, gJiminyMagicCardDumboLine5German, gJiminyMagicCardDumboLine6German,
};

const JiminyTextChar* gJiminyMagicCardDumboLinesItalian[6] = {
    gJiminyMagicCardDumboLine0Italian, gJiminyMagicCardDumboLine1Italian, gJiminyMagicCardDumboLine2Italian, gJiminyMagicCardDumboLine3Italian,
    gJiminyMagicCardDumboLine4Italian, gJiminyMagicCardDumboLine5Italian,
};

const JiminyTextChar* gJiminyMagicCardDumboLinesSpanish[7] = {
    gJiminyMagicCardDumboLine0Spanish, gJiminyMagicCardDumboLine1Spanish, gJiminyMagicCardDumboLine2Spanish, gJiminyMagicCardDumboLine3Spanish,
    gJiminyMagicCardDumboLine4Spanish, gJiminyMagicCardDumboLine5Spanish, gJiminyMagicCardDumboLine6Spanish,
};

const JiminyTextChar* gJiminyMagicCardTinkerBellLines[4] = {
    gJiminyMagicCardTinkerBellLine0, gJiminyMagicCardTinkerBellLine1, gJiminyMagicCardTinkerBellLine2, gJiminyMagicCardTinkerBellLine3,
};

const JiminyTextChar* gJiminyMagicCardTinkerBellLinesFrench[4] = {
    gJiminyMagicCardTinkerBellLine0French, gJiminyMagicCardTinkerBellLine1French, gJiminyMagicCardTinkerBellLine2French, gJiminyMagicCardTinkerBellLine3French,
};

const JiminyTextChar* gJiminyMagicCardTinkerBellLinesGerman[5] = {
    gJiminyMagicCardTinkerBellLine0German, gJiminyMagicCardTinkerBellLine1German, gJiminyMagicCardTinkerBellLine2German, gJiminyMagicCardTinkerBellLine3German,
    gJiminyMagicCardTinkerBellLine4German,
};

const JiminyTextChar* gJiminyMagicCardTinkerBellLinesItalian[5] = {
    gJiminyMagicCardTinkerBellLine0Italian, gJiminyMagicCardTinkerBellLine1Italian, gJiminyMagicCardTinkerBellLine2Italian, gJiminyMagicCardTinkerBellLine3Italian,
    gJiminyMagicCardTinkerBellLine4Italian,
};

const JiminyTextChar* gJiminyMagicCardTinkerBellLinesSpanish[4] = {
    gJiminyMagicCardTinkerBellLine0Spanish, gJiminyMagicCardTinkerBellLine1Spanish, gJiminyMagicCardTinkerBellLine2Spanish, gJiminyMagicCardTinkerBellLine3Spanish,
};

const JiminyTextChar* gJiminyMagicCardMushuLines[5] = {
    gJiminyMagicCardMushuLine0, gJiminyMagicCardMushuLine1, gJiminyMagicCardMushuLine2, gJiminyMagicCardMushuLine3,
    gJiminyMagicCardMushuLine4,
};

const JiminyTextChar* gJiminyMagicCardMushuLinesFrench[4] = {
    gJiminyMagicCardMushuLine0French, gJiminyMagicCardMushuLine1French, gJiminyMagicCardMushuLine2French, gJiminyMagicCardMushuLine3French,
};

const JiminyTextChar* gJiminyMagicCardMushuLinesGerman[8] = {
    gJiminyMagicCardMushuLine0German, gJiminyMagicCardMushuLine1German, gJiminyMagicCardMushuLine2German, gJiminyMagicCardMushuLine3German,
    gJiminyMagicCardMushuLine4German, gJiminyMagicCardMushuLine5German, gJiminyMagicCardMushuLine6German, gJiminyMagicCardMushuLine7German,
};

const JiminyTextChar* gJiminyMagicCardMushuLinesItalian[6] = {
    gJiminyMagicCardMushuLine0Italian, gJiminyMagicCardMushuLine1Italian, gJiminyMagicCardMushuLine2Italian, gJiminyMagicCardMushuLine3Italian,
    gJiminyMagicCardMushuLine4Italian, gJiminyMagicCardMushuLine5Italian,
};

const JiminyTextChar* gJiminyMagicCardMushuLinesSpanish[6] = {
    gJiminyMagicCardMushuLine0Spanish, gJiminyMagicCardMushuLine1Spanish, gJiminyMagicCardMushuLine2Spanish, gJiminyMagicCardMushuLine3Spanish,
    gJiminyMagicCardMushuLine4Spanish, gJiminyMagicCardMushuLine5Spanish,
};

const JiminyTextChar* gJiminyMagicCardCloudLines[4] = {
    gJiminyMagicCardCloudLine0, gJiminyMagicCardCloudLine1, gJiminyMagicCardCloudLine2, gJiminyMagicCardCloudLine3,
};

const JiminyTextChar* gJiminyMagicCardCloudLinesFrench[4] = {
    gJiminyMagicCardCloudLine0French, gJiminyMagicCardCloudLine1French, gJiminyMagicCardCloudLine2French, gJiminyMagicCardCloudLine3French,
};

const JiminyTextChar* gJiminyMagicCardCloudLinesGerman[6] = {
    gJiminyMagicCardCloudLine0German, gJiminyMagicCardCloudLine1German, gJiminyMagicCardCloudLine2German, gJiminyMagicCardCloudLine3German,
    gJiminyMagicCardCloudLine4German, gJiminyMagicCardCloudLine5German,
};

const JiminyTextChar* gJiminyMagicCardCloudLinesItalian[4] = {
    gJiminyMagicCardCloudLine0Italian, gJiminyMagicCardCloudLine1Italian, gJiminyMagicCardCloudLine2Italian, gJiminyMagicCardCloudLine3Italian,
};

const JiminyTextChar* gJiminyMagicCardCloudLinesSpanish[5] = {
    gJiminyMagicCardCloudLine0Spanish, gJiminyMagicCardCloudLine1Spanish, gJiminyMagicCardCloudLine2Spanish, gJiminyMagicCardCloudLine3Spanish,
    gJiminyMagicCardCloudLine4Spanish,
};

const JiminyTextChar* gJiminyItemCardPotionLines[5] = {
    gJiminyItemCardPotionLine0, gJiminyItemCardPotionLine1, gJiminyItemCardPotionLine2, gJiminyItemCardPotionLine3,
    gJiminyItemCardPotionLine4,
};

const JiminyTextChar* gJiminyItemCardPotionLinesFrench[5] = {
    gJiminyItemCardPotionLine0French, gJiminyItemCardPotionLine1French, gJiminyItemCardPotionLine2French, gJiminyItemCardPotionLine3French,
    gJiminyItemCardPotionLine4French,
};

const JiminyTextChar* gJiminyItemCardPotionLinesGerman[7] = {
    gJiminyItemCardPotionLine0German, gJiminyItemCardPotionLine1German, gJiminyItemCardPotionLine2German, gJiminyItemCardPotionLine3German,
    gJiminyItemCardPotionLine4German, gJiminyItemCardPotionLine5German, gJiminyItemCardPotionLine6German,
};

const JiminyTextChar* gJiminyItemCardPotionLinesItalian[7] = {
    gJiminyItemCardPotionLine0Italian, gJiminyItemCardPotionLine1Italian, gJiminyItemCardPotionLine2Italian, gJiminyItemCardPotionLine3Italian,
    gJiminyItemCardPotionLine4Italian, gJiminyItemCardPotionLine5Italian, gJiminyItemCardPotionLine6Italian,
};

const JiminyTextChar* gJiminyItemCardPotionLinesSpanish[5] = {
    gJiminyItemCardPotionLine0Spanish, gJiminyItemCardPotionLine1Spanish, gJiminyItemCardPotionLine2Spanish, gJiminyItemCardPotionLine3Spanish,
    gJiminyItemCardPotionLine4Spanish,
};

const JiminyTextChar* gJiminyItemCardHiPotionLines[5] = {
    gJiminyItemCardHiPotionLine0, gJiminyItemCardHiPotionLine1, gJiminyItemCardHiPotionLine2, gJiminyItemCardHiPotionLine3,
    gJiminyItemCardHiPotionLine4,
};

const JiminyTextChar* gJiminyItemCardHiPotionLinesFrench[5] = {
    gJiminyItemCardHiPotionLine0French, gJiminyItemCardHiPotionLine1French, gJiminyItemCardHiPotionLine2French, gJiminyItemCardHiPotionLine3French,
    gJiminyItemCardHiPotionLine4French,
};

const JiminyTextChar* gJiminyItemCardHiPotionLinesGerman[7] = {
    gJiminyItemCardHiPotionLine0German, gJiminyItemCardHiPotionLine1German, gJiminyItemCardHiPotionLine2German, gJiminyItemCardHiPotionLine3German,
    gJiminyItemCardHiPotionLine4German, gJiminyItemCardHiPotionLine5German, gJiminyItemCardHiPotionLine6German,
};

const JiminyTextChar* gJiminyItemCardHiPotionLinesItalian[7] = {
    gJiminyItemCardHiPotionLine0Italian, gJiminyItemCardHiPotionLine1Italian, gJiminyItemCardHiPotionLine2Italian, gJiminyItemCardHiPotionLine3Italian,
    gJiminyItemCardHiPotionLine4Italian, gJiminyItemCardHiPotionLine5Italian, gJiminyItemCardHiPotionLine6Italian,
};

const JiminyTextChar* gJiminyItemCardHiPotionLinesSpanish[5] = {
    gJiminyItemCardHiPotionLine0Spanish, gJiminyItemCardHiPotionLine1Spanish, gJiminyItemCardHiPotionLine2Spanish, gJiminyItemCardHiPotionLine3Spanish,
    gJiminyItemCardHiPotionLine4Spanish,
};

const JiminyTextChar* gJiminyItemCardMegaPotionLines[6] = {
    gJiminyItemCardMegaPotionLine0, gJiminyItemCardMegaPotionLine1, gJiminyItemCardMegaPotionLine2, gJiminyItemCardMegaPotionLine3,
    gJiminyItemCardMegaPotionLine4, gJiminyItemCardMegaPotionLine5,
};

const JiminyTextChar* gJiminyItemCardMegaPotionLinesFrench[6] = {
    gJiminyItemCardMegaPotionLine0French, gJiminyItemCardMegaPotionLine1French, gJiminyItemCardMegaPotionLine2French, gJiminyItemCardMegaPotionLine3French,
    gJiminyItemCardMegaPotionLine4French, gJiminyItemCardMegaPotionLine5French,
};

const JiminyTextChar* gJiminyItemCardMegaPotionLinesGerman[8] = {
    gJiminyItemCardMegaPotionLine0German, gJiminyItemCardMegaPotionLine1German, gJiminyItemCardMegaPotionLine2German, gJiminyItemCardMegaPotionLine3German,
    gJiminyItemCardMegaPotionLine4German, gJiminyItemCardMegaPotionLine5German, gJiminyItemCardMegaPotionLine6German, gJiminyItemCardMegaPotionLine7German,
};

const JiminyTextChar* gJiminyItemCardMegaPotionLinesItalian[8] = {
    gJiminyItemCardMegaPotionLine0Italian, gJiminyItemCardMegaPotionLine1Italian, gJiminyItemCardMegaPotionLine2Italian, gJiminyItemCardMegaPotionLine3Italian,
    gJiminyItemCardMegaPotionLine4Italian, gJiminyItemCardMegaPotionLine5Italian, gJiminyItemCardMegaPotionLine6Italian, gJiminyItemCardMegaPotionLine7Italian,
};

const JiminyTextChar* gJiminyItemCardMegaPotionLinesSpanish[6] = {
    gJiminyItemCardMegaPotionLine0Spanish, gJiminyItemCardMegaPotionLine1Spanish, gJiminyItemCardMegaPotionLine2Spanish, gJiminyItemCardMegaPotionLine3Spanish,
    gJiminyItemCardMegaPotionLine4Spanish, gJiminyItemCardMegaPotionLine5Spanish,
};

const JiminyTextChar* gJiminyItemCardEtherLines[5] = {
    gJiminyItemCardEtherLine0, gJiminyItemCardEtherLine1, gJiminyItemCardEtherLine2, gJiminyItemCardEtherLine3,
    gJiminyItemCardEtherLine4,
};

const JiminyTextChar* gJiminyItemCardEtherLinesFrench[5] = {
    gJiminyItemCardEtherLine0French, gJiminyItemCardEtherLine1French, gJiminyItemCardEtherLine2French, gJiminyItemCardEtherLine3French,
    gJiminyItemCardEtherLine4French,
};

const JiminyTextChar* gJiminyItemCardEtherLinesGerman[7] = {
    gJiminyItemCardEtherLine0German, gJiminyItemCardEtherLine1German, gJiminyItemCardEtherLine2German, gJiminyItemCardEtherLine3German,
    gJiminyItemCardEtherLine4German, gJiminyItemCardEtherLine5German, gJiminyItemCardEtherLine6German,
};

const JiminyTextChar* gJiminyItemCardEtherLinesItalian[7] = {
    gJiminyItemCardEtherLine0Italian, gJiminyItemCardEtherLine1Italian, gJiminyItemCardEtherLine2Italian, gJiminyItemCardEtherLine3Italian,
    gJiminyItemCardEtherLine4Italian, gJiminyItemCardEtherLine5Italian, gJiminyItemCardEtherLine6Italian,
};

const JiminyTextChar* gJiminyItemCardEtherLinesSpanish[5] = {
    gJiminyItemCardEtherLine0Spanish, gJiminyItemCardEtherLine1Spanish, gJiminyItemCardEtherLine2Spanish, gJiminyItemCardEtherLine3Spanish,
    gJiminyItemCardEtherLine4Spanish,
};

const JiminyTextChar* gJiminyItemCardMegaEtherLines[6] = {
    gJiminyItemCardMegaEtherLine0, gJiminyItemCardMegaEtherLine1, gJiminyItemCardMegaEtherLine2, gJiminyItemCardMegaEtherLine3,
    gJiminyItemCardMegaEtherLine4, gJiminyItemCardMegaEtherLine5,
};

const JiminyTextChar* gJiminyItemCardMegaEtherLinesFrench[6] = {
    gJiminyItemCardMegaEtherLine0French, gJiminyItemCardMegaEtherLine1French, gJiminyItemCardMegaEtherLine2French, gJiminyItemCardMegaEtherLine3French,
    gJiminyItemCardMegaEtherLine4French, gJiminyItemCardMegaEtherLine5French,
};

const JiminyTextChar* gJiminyItemCardMegaEtherLinesGerman[8] = {
    gJiminyItemCardMegaEtherLine0German, gJiminyItemCardMegaEtherLine1German, gJiminyItemCardMegaEtherLine2German, gJiminyItemCardMegaEtherLine3German,
    gJiminyItemCardMegaEtherLine4German, gJiminyItemCardMegaEtherLine5German, gJiminyItemCardMegaEtherLine6German, gJiminyItemCardMegaEtherLine7German,
};

const JiminyTextChar* gJiminyItemCardMegaEtherLinesItalian[8] = {
    gJiminyItemCardMegaEtherLine0Italian, gJiminyItemCardMegaEtherLine1Italian, gJiminyItemCardMegaEtherLine2Italian, gJiminyItemCardMegaEtherLine3Italian,
    gJiminyItemCardMegaEtherLine4Italian, gJiminyItemCardMegaEtherLine5Italian, gJiminyItemCardMegaEtherLine6Italian, gJiminyItemCardMegaEtherLine7Italian,
};

const JiminyTextChar* gJiminyItemCardMegaEtherLinesSpanish[6] = {
    gJiminyItemCardMegaEtherLine0Spanish, gJiminyItemCardMegaEtherLine1Spanish, gJiminyItemCardMegaEtherLine2Spanish, gJiminyItemCardMegaEtherLine3Spanish,
    gJiminyItemCardMegaEtherLine4Spanish, gJiminyItemCardMegaEtherLine5Spanish,
};

const JiminyTextChar* gJiminyItemCardElixirLines[4] = {
    gJiminyItemCardElixirLine0, gJiminyItemCardElixirLine1, gJiminyItemCardElixirLine2, gJiminyItemCardElixirLine3,
};

const JiminyTextChar* gJiminyItemCardElixirLinesFrench[5] = {
    gJiminyItemCardElixirLine0French, gJiminyItemCardElixirLine1French, gJiminyItemCardElixirLine2French, gJiminyItemCardElixirLine3French,
    gJiminyItemCardElixirLine4French,
};

const JiminyTextChar* gJiminyItemCardElixirLinesGerman[5] = {
    gJiminyItemCardElixirLine0German, gJiminyItemCardElixirLine1German, gJiminyItemCardElixirLine2German, gJiminyItemCardElixirLine3German,
    gJiminyItemCardElixirLine4German,
};

const JiminyTextChar* gJiminyItemCardElixirLinesItalian[5] = {
    gJiminyItemCardElixirLine0Italian, gJiminyItemCardElixirLine1Italian, gJiminyItemCardElixirLine2Italian, gJiminyItemCardElixirLine3Italian,
    gJiminyItemCardElixirLine4Italian,
};

const JiminyTextChar* gJiminyItemCardElixirLinesSpanish[4] = {
    gJiminyItemCardElixirLine0Spanish, gJiminyItemCardElixirLine1Spanish, gJiminyItemCardElixirLine2Spanish, gJiminyItemCardElixirLine3Spanish,
};

const JiminyTextChar* gJiminyItemCardMegalixirLines[6] = {
    gJiminyItemCardMegalixirLine0, gJiminyItemCardMegalixirLine1, gJiminyItemCardMegalixirLine2, gJiminyItemCardMegalixirLine3,
    gJiminyItemCardMegalixirLine4, gJiminyItemCardMegalixirLine5,
};

const JiminyTextChar* gJiminyItemCardMegalixirLinesFrench[6] = {
    gJiminyItemCardMegalixirLine0French, gJiminyItemCardMegalixirLine1French, gJiminyItemCardMegalixirLine2French, gJiminyItemCardMegalixirLine3French,
    gJiminyItemCardMegalixirLine4French, gJiminyItemCardMegalixirLine5French,
};

const JiminyTextChar* gJiminyItemCardMegalixirLinesGerman[8] = {
    gJiminyItemCardMegalixirLine0German, gJiminyItemCardMegalixirLine1German, gJiminyItemCardMegalixirLine2German, gJiminyItemCardMegalixirLine3German,
    gJiminyItemCardMegalixirLine4German, gJiminyItemCardMegalixirLine5German, gJiminyItemCardMegalixirLine6German, gJiminyItemCardMegalixirLine7German,
};

const JiminyTextChar* gJiminyItemCardMegalixirLinesItalian[7] = {
    gJiminyItemCardMegalixirLine0Italian, gJiminyItemCardMegalixirLine1Italian, gJiminyItemCardMegalixirLine2Italian, gJiminyItemCardMegalixirLine3Italian,
    gJiminyItemCardMegalixirLine4Italian, gJiminyItemCardMegalixirLine5Italian, gJiminyItemCardMegalixirLine6Italian,
};

const JiminyTextChar* gJiminyItemCardMegalixirLinesSpanish[6] = {
    gJiminyItemCardMegalixirLine0Spanish, gJiminyItemCardMegalixirLine1Spanish, gJiminyItemCardMegalixirLine2Spanish, gJiminyItemCardMegalixirLine3Spanish,
    gJiminyItemCardMegalixirLine4Spanish, gJiminyItemCardMegalixirLine5Spanish,
};

const JiminyTextChar* gJiminyFriendCardDonaldDuckLines[5] = {
    gJiminyFriendCardDonaldDuckLine0, gJiminyFriendCardDonaldDuckLine1, gJiminyFriendCardDonaldDuckLine2, gJiminyFriendCardDonaldDuckLine3,
    gJiminyFriendCardDonaldDuckLine4,
};

const JiminyTextChar* gJiminyFriendCardDonaldDuckLinesFrench[4] = {
    gJiminyFriendCardDonaldDuckLine0French, gJiminyFriendCardDonaldDuckLine1French, gJiminyFriendCardDonaldDuckLine2French, gJiminyFriendCardDonaldDuckLine3French,
};

const JiminyTextChar* gJiminyFriendCardDonaldDuckLinesGerman[6] = {
    gJiminyFriendCardDonaldDuckLine0German, gJiminyFriendCardDonaldDuckLine1German, gJiminyFriendCardDonaldDuckLine2German, gJiminyFriendCardDonaldDuckLine3German,
    gJiminyFriendCardDonaldDuckLine4German, gJiminyFriendCardDonaldDuckLine5German,
};

const JiminyTextChar* gJiminyFriendCardDonaldDuckLinesItalian[5] = {
    gJiminyFriendCardDonaldDuckLine0Italian, gJiminyFriendCardDonaldDuckLine1Italian, gJiminyFriendCardDonaldDuckLine2Italian, gJiminyFriendCardDonaldDuckLine3Italian,
    gJiminyFriendCardDonaldDuckLine4Italian,
};

const JiminyTextChar* gJiminyFriendCardDonaldDuckLinesSpanish[5] = {
    gJiminyFriendCardDonaldDuckLine0Spanish, gJiminyFriendCardDonaldDuckLine1Spanish, gJiminyFriendCardDonaldDuckLine2Spanish, gJiminyFriendCardDonaldDuckLine3Spanish,
    gJiminyFriendCardDonaldDuckLine4Spanish,
};

const JiminyTextChar* gJiminyFriendCardGoofyLines[4] = {
    gJiminyFriendCardGoofyLine0, gJiminyFriendCardGoofyLine1, gJiminyFriendCardGoofyLine2, gJiminyFriendCardGoofyLine3,
};

const JiminyTextChar* gJiminyFriendCardGoofyLinesFrench[4] = {
    gJiminyFriendCardGoofyLine0French, gJiminyFriendCardGoofyLine1French, gJiminyFriendCardGoofyLine2French, gJiminyFriendCardGoofyLine3French,
};

const JiminyTextChar* gJiminyFriendCardGoofyLinesGerman[7] = {
    gJiminyFriendCardGoofyLine0German, gJiminyFriendCardGoofyLine1German, gJiminyFriendCardGoofyLine2German, gJiminyFriendCardGoofyLine3German,
    gJiminyFriendCardGoofyLine4German, gJiminyFriendCardGoofyLine5German, gJiminyFriendCardGoofyLine6German,
};

const JiminyTextChar* gJiminyFriendCardGoofyLinesItalian[5] = {
    gJiminyFriendCardGoofyLine0Italian, gJiminyFriendCardGoofyLine1Italian, gJiminyFriendCardGoofyLine2Italian, gJiminyFriendCardGoofyLine3Italian,
    gJiminyFriendCardGoofyLine4Italian,
};

const JiminyTextChar* gJiminyFriendCardGoofyLinesSpanish[6] = {
    gJiminyFriendCardGoofyLine0Spanish, gJiminyFriendCardGoofyLine1Spanish, gJiminyFriendCardGoofyLine2Spanish, gJiminyFriendCardGoofyLine3Spanish,
    gJiminyFriendCardGoofyLine4Spanish, gJiminyFriendCardGoofyLine5Spanish,
};

const JiminyTextChar* gJiminyFriendCardAladdinLines[5] = {
    gJiminyFriendCardAladdinLine0, gJiminyFriendCardAladdinLine1, gJiminyFriendCardAladdinLine2, gJiminyFriendCardAladdinLine3,
    gJiminyFriendCardAladdinLine4,
};

const JiminyTextChar* gJiminyFriendCardAladdinLinesFrench[4] = {
    gJiminyFriendCardAladdinLine0French, gJiminyFriendCardAladdinLine1French, gJiminyFriendCardAladdinLine2French, gJiminyFriendCardAladdinLine3French,
};

const JiminyTextChar* gJiminyFriendCardAladdinLinesGerman[7] = {
    gJiminyFriendCardAladdinLine0German, gJiminyFriendCardAladdinLine1German, gJiminyFriendCardAladdinLine2German, gJiminyFriendCardAladdinLine3German,
    gJiminyFriendCardAladdinLine4German, gJiminyFriendCardAladdinLine5German, gJiminyFriendCardAladdinLine6German,
};

const JiminyTextChar* gJiminyFriendCardAladdinLinesItalian[5] = {
    gJiminyFriendCardAladdinLine0Italian, gJiminyFriendCardAladdinLine1Italian, gJiminyFriendCardAladdinLine2Italian, gJiminyFriendCardAladdinLine3Italian,
    gJiminyFriendCardAladdinLine4Italian,
};

const JiminyTextChar* gJiminyFriendCardAladdinLinesSpanish[5] = {
    gJiminyFriendCardAladdinLine0Spanish, gJiminyFriendCardAladdinLine1Spanish, gJiminyFriendCardAladdinLine2Spanish, gJiminyFriendCardAladdinLine3Spanish,
    gJiminyFriendCardAladdinLine4Spanish,
};

const JiminyTextChar* gJiminyFriendCardArielLines[5] = {
    gJiminyFriendCardArielLine0, gJiminyFriendCardArielLine1, gJiminyFriendCardArielLine2, gJiminyFriendCardArielLine3,
    gJiminyFriendCardArielLine4,
};

const JiminyTextChar* gJiminyFriendCardArielLinesFrench[4] = {
    gJiminyFriendCardArielLine0French, gJiminyFriendCardArielLine1French, gJiminyFriendCardArielLine2French, gJiminyFriendCardArielLine3French,
};

const JiminyTextChar* gJiminyFriendCardArielLinesGerman[8] = {
    gJiminyFriendCardArielLine0German, gJiminyFriendCardArielLine1German, gJiminyFriendCardArielLine2German, gJiminyFriendCardArielLine3German,
    gJiminyFriendCardArielLine4German, gJiminyFriendCardArielLine5German, gJiminyFriendCardArielLine6German, gJiminyFriendCardArielLine7German,
};

const JiminyTextChar* gJiminyFriendCardArielLinesItalian[5] = {
    gJiminyFriendCardArielLine0Italian, gJiminyFriendCardArielLine1Italian, gJiminyFriendCardArielLine2Italian, gJiminyFriendCardArielLine3Italian,
    gJiminyFriendCardArielLine4Italian,
};

const JiminyTextChar* gJiminyFriendCardArielLinesSpanish[5] = {
    gJiminyFriendCardArielLine0Spanish, gJiminyFriendCardArielLine1Spanish, gJiminyFriendCardArielLine2Spanish, gJiminyFriendCardArielLine3Spanish,
    gJiminyFriendCardArielLine4Spanish,
};

const JiminyTextChar* gJiminyFriendCardJackLines[5] = {
    gJiminyFriendCardJackLine0, gJiminyFriendCardJackLine1, gJiminyFriendCardJackLine2, gJiminyFriendCardJackLine3,
    gJiminyFriendCardJackLine4,
};

const JiminyTextChar* gJiminyFriendCardJackLinesFrench[4] = {
    gJiminyFriendCardJackLine0French, gJiminyFriendCardJackLine1French, gJiminyFriendCardJackLine2French, gJiminyFriendCardJackLine3French,
};

const JiminyTextChar* gJiminyFriendCardJackLinesGerman[7] = {
    gJiminyFriendCardJackLine0German, gJiminyFriendCardJackLine1German, gJiminyFriendCardJackLine2German, gJiminyFriendCardJackLine3German,
    gJiminyFriendCardJackLine4German, gJiminyFriendCardJackLine5German, gJiminyFriendCardJackLine6German,
};

const JiminyTextChar* gJiminyFriendCardJackLinesItalian[5] = {
    gJiminyFriendCardJackLine0Italian, gJiminyFriendCardJackLine1Italian, gJiminyFriendCardJackLine2Italian, gJiminyFriendCardJackLine3Italian,
    gJiminyFriendCardJackLine4Italian,
};

const JiminyTextChar* gJiminyFriendCardJackLinesSpanish[5] = {
    gJiminyFriendCardJackLine0Spanish, gJiminyFriendCardJackLine1Spanish, gJiminyFriendCardJackLine2Spanish, gJiminyFriendCardJackLine3Spanish,
    gJiminyFriendCardJackLine4Spanish,
};

const JiminyTextChar* gJiminyFriendCardPeterPanLines[4] = {
    gJiminyFriendCardPeterPanLine0, gJiminyFriendCardPeterPanLine1, gJiminyFriendCardPeterPanLine2, gJiminyFriendCardPeterPanLine3,
};

const JiminyTextChar* gJiminyFriendCardPeterPanLinesFrench[4] = {
    gJiminyFriendCardPeterPanLine0French, gJiminyFriendCardPeterPanLine1French, gJiminyFriendCardPeterPanLine2French, gJiminyFriendCardPeterPanLine3French,
};

const JiminyTextChar* gJiminyFriendCardPeterPanLinesGerman[6] = {
    gJiminyFriendCardPeterPanLine0German, gJiminyFriendCardPeterPanLine1German, gJiminyFriendCardPeterPanLine2German, gJiminyFriendCardPeterPanLine3German,
    gJiminyFriendCardPeterPanLine4German, gJiminyFriendCardPeterPanLine5German,
};

const JiminyTextChar* gJiminyFriendCardPeterPanLinesItalian[5] = {
    gJiminyFriendCardPeterPanLine0Italian, gJiminyFriendCardPeterPanLine1Italian, gJiminyFriendCardPeterPanLine2Italian, gJiminyFriendCardPeterPanLine3Italian,
    gJiminyFriendCardPeterPanLine4Italian,
};

const JiminyTextChar* gJiminyFriendCardPeterPanLinesSpanish[4] = {
    gJiminyFriendCardPeterPanLine0Spanish, gJiminyFriendCardPeterPanLine1Spanish, gJiminyFriendCardPeterPanLine2Spanish, gJiminyFriendCardPeterPanLine3Spanish,
};

const JiminyTextChar* gJiminyFriendCardBeastLines[5] = {
    gJiminyFriendCardBeastLine0, gJiminyFriendCardBeastLine1, gJiminyFriendCardBeastLine2, gJiminyFriendCardBeastLine3,
    gJiminyFriendCardBeastLine4,
};

const JiminyTextChar* gJiminyFriendCardBeastLinesFrench[4] = {
    gJiminyFriendCardBeastLine0French, gJiminyFriendCardBeastLine1French, gJiminyFriendCardBeastLine2French, gJiminyFriendCardBeastLine3French,
};

const JiminyTextChar* gJiminyFriendCardBeastLinesGerman[5] = {
    gJiminyFriendCardBeastLine0German, gJiminyFriendCardBeastLine1German, gJiminyFriendCardBeastLine2German, gJiminyFriendCardBeastLine3German,
    gJiminyFriendCardBeastLine4German,
};

const JiminyTextChar* gJiminyFriendCardBeastLinesItalian[7] = {
    gJiminyFriendCardBeastLine0Italian, gJiminyFriendCardBeastLine1Italian, gJiminyFriendCardBeastLine2Italian, gJiminyFriendCardBeastLine3Italian,
    gJiminyFriendCardBeastLine4Italian, gJiminyFriendCardBeastLine5Italian, gJiminyFriendCardBeastLine6Italian,
};

const JiminyTextChar* gJiminyFriendCardBeastLinesSpanish[5] = {
    gJiminyFriendCardBeastLine0Spanish, gJiminyFriendCardBeastLine1Spanish, gJiminyFriendCardBeastLine2Spanish, gJiminyFriendCardBeastLine3Spanish,
    gJiminyFriendCardBeastLine4Spanish,
};

const JiminyTextChar* gJiminyEnemyCardShadowLines[5] = {
    gJiminyEnemyCardShadowLine0, gJiminyEnemyCardShadowLine1, gJiminyEnemyCardShadowLine2, gJiminyEnemyCardShadowLine3,
    gJiminyEnemyCardShadowLine4,
};

const JiminyTextChar* gJiminyEnemyCardShadowLinesFrench[5] = {
    gJiminyEnemyCardShadowLine0French, gJiminyEnemyCardShadowLine1French, gJiminyEnemyCardShadowLine2French, gJiminyEnemyCardShadowLine3French,
    gJiminyEnemyCardShadowLine4French,
};

const JiminyTextChar* gJiminyEnemyCardShadowLinesGerman[5] = {
    gJiminyEnemyCardShadowLine0German, gJiminyEnemyCardShadowLine1German, gJiminyEnemyCardShadowLine2German, gJiminyEnemyCardShadowLine3German,
    gJiminyEnemyCardShadowLine4German,
};

const JiminyTextChar* gJiminyEnemyCardShadowLinesItalian[6] = {
    gJiminyEnemyCardShadowLine0Italian, gJiminyEnemyCardShadowLine1Italian, gJiminyEnemyCardShadowLine2Italian, gJiminyEnemyCardShadowLine3Italian,
    gJiminyEnemyCardShadowLine4Italian, gJiminyEnemyCardShadowLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardShadowLinesSpanish[5] = {
    gJiminyEnemyCardShadowLine0Spanish, gJiminyEnemyCardShadowLine1Spanish, gJiminyEnemyCardShadowLine2Spanish, gJiminyEnemyCardShadowLine3Spanish,
    gJiminyEnemyCardShadowLine4Spanish,
};

const JiminyTextChar* gJiminyEnemyCardRedNocturneLines[5] = {
    gJiminyEnemyCardRedNocturneLine0, gJiminyEnemyCardRedNocturneLine1, gJiminyEnemyCardRedNocturneLine2, gJiminyEnemyCardRedNocturneLine3,
    gJiminyEnemyCardRedNocturneLine4,
};

const JiminyTextChar* gJiminyEnemyCardRedNocturneLinesFrench[5] = {
    gJiminyEnemyCardRedNocturneLine0French, gJiminyEnemyCardRedNocturneLine1French, gJiminyEnemyCardRedNocturneLine2French, gJiminyEnemyCardRedNocturneLine3French,
    gJiminyEnemyCardRedNocturneLine4French,
};

const JiminyTextChar* gJiminyEnemyCardRedNocturneLinesGerman[6] = {
    gJiminyEnemyCardRedNocturneLine0German, gJiminyEnemyCardRedNocturneLine1German, gJiminyEnemyCardRedNocturneLine2German, gJiminyEnemyCardRedNocturneLine3German,
    gJiminyEnemyCardRedNocturneLine4German, gJiminyEnemyCardRedNocturneLine5German,
};

const JiminyTextChar* gJiminyEnemyCardRedNocturneLinesItalian[5] = {
    gJiminyEnemyCardRedNocturneLine0Italian, gJiminyEnemyCardRedNocturneLine1Italian, gJiminyEnemyCardRedNocturneLine2Italian, gJiminyEnemyCardRedNocturneLine3Italian,
    gJiminyEnemyCardRedNocturneLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardRedNocturneLinesSpanish[6] = {
    gJiminyEnemyCardRedNocturneLine0Spanish, gJiminyEnemyCardRedNocturneLine1Spanish, gJiminyEnemyCardRedNocturneLine2Spanish, gJiminyEnemyCardRedNocturneLine3Spanish,
    gJiminyEnemyCardRedNocturneLine4Spanish, gJiminyEnemyCardRedNocturneLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardBlueRhapsodyLines[5] = {
    gJiminyEnemyCardBlueRhapsodyLine0, gJiminyEnemyCardBlueRhapsodyLine1, gJiminyEnemyCardBlueRhapsodyLine2, gJiminyEnemyCardBlueRhapsodyLine3,
    gJiminyEnemyCardBlueRhapsodyLine4,
};

const JiminyTextChar* gJiminyEnemyCardBlueRhapsodyLinesFrench[5] = {
    gJiminyEnemyCardBlueRhapsodyLine0French, gJiminyEnemyCardBlueRhapsodyLine1French, gJiminyEnemyCardBlueRhapsodyLine2French, gJiminyEnemyCardBlueRhapsodyLine3French,
    gJiminyEnemyCardBlueRhapsodyLine4French,
};

const JiminyTextChar* gJiminyEnemyCardBlueRhapsodyLinesGerman[5] = {
    gJiminyEnemyCardBlueRhapsodyLine0German, gJiminyEnemyCardBlueRhapsodyLine1German, gJiminyEnemyCardBlueRhapsodyLine2German, gJiminyEnemyCardBlueRhapsodyLine3German,
    gJiminyEnemyCardBlueRhapsodyLine4German,
};

const JiminyTextChar* gJiminyEnemyCardBlueRhapsodyLinesItalian[5] = {
    gJiminyEnemyCardBlueRhapsodyLine0Italian, gJiminyEnemyCardBlueRhapsodyLine1Italian, gJiminyEnemyCardBlueRhapsodyLine2Italian, gJiminyEnemyCardBlueRhapsodyLine3Italian,
    gJiminyEnemyCardBlueRhapsodyLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardBlueRhapsodyLinesSpanish[6] = {
    gJiminyEnemyCardBlueRhapsodyLine0Spanish, gJiminyEnemyCardBlueRhapsodyLine1Spanish, gJiminyEnemyCardBlueRhapsodyLine2Spanish, gJiminyEnemyCardBlueRhapsodyLine3Spanish,
    gJiminyEnemyCardBlueRhapsodyLine4Spanish, gJiminyEnemyCardBlueRhapsodyLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardYellowOperaLines[5] = {
    gJiminyEnemyCardYellowOperaLine0, gJiminyEnemyCardYellowOperaLine1, gJiminyEnemyCardYellowOperaLine2, gJiminyEnemyCardYellowOperaLine3,
    gJiminyEnemyCardYellowOperaLine4,
};

const JiminyTextChar* gJiminyEnemyCardYellowOperaLinesFrench[5] = {
    gJiminyEnemyCardYellowOperaLine0French, gJiminyEnemyCardYellowOperaLine1French, gJiminyEnemyCardYellowOperaLine2French, gJiminyEnemyCardYellowOperaLine3French,
    gJiminyEnemyCardYellowOperaLine4French,
};

const JiminyTextChar* gJiminyEnemyCardYellowOperaLinesGerman[6] = {
    gJiminyEnemyCardYellowOperaLine0German, gJiminyEnemyCardYellowOperaLine1German, gJiminyEnemyCardYellowOperaLine2German, gJiminyEnemyCardYellowOperaLine3German,
    gJiminyEnemyCardYellowOperaLine4German, gJiminyEnemyCardYellowOperaLine5German,
};

const JiminyTextChar* gJiminyEnemyCardYellowOperaLinesItalian[5] = {
    gJiminyEnemyCardYellowOperaLine0Italian, gJiminyEnemyCardYellowOperaLine1Italian, gJiminyEnemyCardYellowOperaLine2Italian, gJiminyEnemyCardYellowOperaLine3Italian,
    gJiminyEnemyCardYellowOperaLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardYellowOperaLinesSpanish[6] = {
    gJiminyEnemyCardYellowOperaLine0Spanish, gJiminyEnemyCardYellowOperaLine1Spanish, gJiminyEnemyCardYellowOperaLine2Spanish, gJiminyEnemyCardYellowOperaLine3Spanish,
    gJiminyEnemyCardYellowOperaLine4Spanish, gJiminyEnemyCardYellowOperaLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardGreenRequiemLines[5] = {
    gJiminyEnemyCardGreenRequiemLine0, gJiminyEnemyCardGreenRequiemLine1, gJiminyEnemyCardGreenRequiemLine2, gJiminyEnemyCardGreenRequiemLine3,
    gJiminyEnemyCardGreenRequiemLine4,
};

const JiminyTextChar* gJiminyEnemyCardGreenRequiemLinesFrench[5] = {
    gJiminyEnemyCardGreenRequiemLine0French, gJiminyEnemyCardGreenRequiemLine1French, gJiminyEnemyCardGreenRequiemLine2French, gJiminyEnemyCardGreenRequiemLine3French,
    gJiminyEnemyCardGreenRequiemLine4French,
};

const JiminyTextChar* gJiminyEnemyCardGreenRequiemLinesGerman[6] = {
    gJiminyEnemyCardGreenRequiemLine0German, gJiminyEnemyCardGreenRequiemLine1German, gJiminyEnemyCardGreenRequiemLine2German, gJiminyEnemyCardGreenRequiemLine3German,
    gJiminyEnemyCardGreenRequiemLine4German, gJiminyEnemyCardGreenRequiemLine5German,
};

const JiminyTextChar* gJiminyEnemyCardGreenRequiemLinesItalian[5] = {
    gJiminyEnemyCardGreenRequiemLine0Italian, gJiminyEnemyCardGreenRequiemLine1Italian, gJiminyEnemyCardGreenRequiemLine2Italian, gJiminyEnemyCardGreenRequiemLine3Italian,
    gJiminyEnemyCardGreenRequiemLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardGreenRequiemLinesSpanish[6] = {
    gJiminyEnemyCardGreenRequiemLine0Spanish, gJiminyEnemyCardGreenRequiemLine1Spanish, gJiminyEnemyCardGreenRequiemLine2Spanish, gJiminyEnemyCardGreenRequiemLine3Spanish,
    gJiminyEnemyCardGreenRequiemLine4Spanish, gJiminyEnemyCardGreenRequiemLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardSeaNeonLines[5] = {
    gJiminyEnemyCardSeaNeonLine0, gJiminyEnemyCardSeaNeonLine1, gJiminyEnemyCardSeaNeonLine2, gJiminyEnemyCardSeaNeonLine3,
    gJiminyEnemyCardSeaNeonLine4,
};

const JiminyTextChar* gJiminyEnemyCardSeaNeonLinesFrench[6] = {
    gJiminyEnemyCardSeaNeonLine0French, gJiminyEnemyCardSeaNeonLine1French, gJiminyEnemyCardSeaNeonLine2French, gJiminyEnemyCardSeaNeonLine3French,
    gJiminyEnemyCardSeaNeonLine4French, gJiminyEnemyCardSeaNeonLine5French,
};

const JiminyTextChar* gJiminyEnemyCardSeaNeonLinesGerman[6] = {
    gJiminyEnemyCardSeaNeonLine0German, gJiminyEnemyCardSeaNeonLine1German, gJiminyEnemyCardSeaNeonLine2German, gJiminyEnemyCardSeaNeonLine3German,
    gJiminyEnemyCardSeaNeonLine4German, gJiminyEnemyCardSeaNeonLine5German,
};

const JiminyTextChar* gJiminyEnemyCardSeaNeonLinesItalian[5] = {
    gJiminyEnemyCardSeaNeonLine0Italian, gJiminyEnemyCardSeaNeonLine1Italian, gJiminyEnemyCardSeaNeonLine2Italian, gJiminyEnemyCardSeaNeonLine3Italian,
    gJiminyEnemyCardSeaNeonLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardSeaNeonLinesSpanish[6] = {
    gJiminyEnemyCardSeaNeonLine0Spanish, gJiminyEnemyCardSeaNeonLine1Spanish, gJiminyEnemyCardSeaNeonLine2Spanish, gJiminyEnemyCardSeaNeonLine3Spanish,
    gJiminyEnemyCardSeaNeonLine4Spanish, gJiminyEnemyCardSeaNeonLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardWhiteMushroomLines[6] = {
    gJiminyEnemyCardWhiteMushroomLine0, gJiminyEnemyCardWhiteMushroomLine1, gJiminyEnemyCardWhiteMushroomLine2, gJiminyEnemyCardWhiteMushroomLine3,
    gJiminyEnemyCardWhiteMushroomLine4, gJiminyEnemyCardWhiteMushroomLine5,
};

const JiminyTextChar* gJiminyEnemyCardWhiteMushroomLinesFrench[6] = {
    gJiminyEnemyCardWhiteMushroomLine0French, gJiminyEnemyCardWhiteMushroomLine1French, gJiminyEnemyCardWhiteMushroomLine2French, gJiminyEnemyCardWhiteMushroomLine3French,
    gJiminyEnemyCardWhiteMushroomLine4French, gJiminyEnemyCardWhiteMushroomLine5French,
};

const JiminyTextChar* gJiminyEnemyCardWhiteMushroomLinesGerman[7] = {
    gJiminyEnemyCardWhiteMushroomLine0German, gJiminyEnemyCardWhiteMushroomLine1German, gJiminyEnemyCardWhiteMushroomLine2German, gJiminyEnemyCardWhiteMushroomLine3German,
    gJiminyEnemyCardWhiteMushroomLine4German, gJiminyEnemyCardWhiteMushroomLine5German, gJiminyEnemyCardWhiteMushroomLine6German,
};

const JiminyTextChar* gJiminyEnemyCardWhiteMushroomLinesItalian[6] = {
    gJiminyEnemyCardWhiteMushroomLine0Italian, gJiminyEnemyCardWhiteMushroomLine1Italian, gJiminyEnemyCardWhiteMushroomLine2Italian, gJiminyEnemyCardWhiteMushroomLine3Italian,
    gJiminyEnemyCardWhiteMushroomLine4Italian, gJiminyEnemyCardWhiteMushroomLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardWhiteMushroomLinesSpanish[6] = {
    gJiminyEnemyCardWhiteMushroomLine0Spanish, gJiminyEnemyCardWhiteMushroomLine1Spanish, gJiminyEnemyCardWhiteMushroomLine2Spanish, gJiminyEnemyCardWhiteMushroomLine3Spanish,
    gJiminyEnemyCardWhiteMushroomLine4Spanish, gJiminyEnemyCardWhiteMushroomLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardBlackFungusLines[5] = {
    gJiminyEnemyCardBlackFungusLine0, gJiminyEnemyCardBlackFungusLine1, gJiminyEnemyCardBlackFungusLine2, gJiminyEnemyCardBlackFungusLine3,
    gJiminyEnemyCardBlackFungusLine4,
};

const JiminyTextChar* gJiminyEnemyCardBlackFungusLinesFrench[5] = {
    gJiminyEnemyCardBlackFungusLine0French, gJiminyEnemyCardBlackFungusLine1French, gJiminyEnemyCardBlackFungusLine2French, gJiminyEnemyCardBlackFungusLine3French,
    gJiminyEnemyCardBlackFungusLine4French,
};

const JiminyTextChar* gJiminyEnemyCardBlackFungusLinesGerman[6] = {
    gJiminyEnemyCardBlackFungusLine0German, gJiminyEnemyCardBlackFungusLine1German, gJiminyEnemyCardBlackFungusLine2German, gJiminyEnemyCardBlackFungusLine3German,
    gJiminyEnemyCardBlackFungusLine4German, gJiminyEnemyCardBlackFungusLine5German,
};

const JiminyTextChar* gJiminyEnemyCardBlackFungusLinesItalian[5] = {
    gJiminyEnemyCardBlackFungusLine0Italian, gJiminyEnemyCardBlackFungusLine1Italian, gJiminyEnemyCardBlackFungusLine2Italian, gJiminyEnemyCardBlackFungusLine3Italian,
    gJiminyEnemyCardBlackFungusLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardBlackFungusLinesSpanish[5] = {
    gJiminyEnemyCardBlackFungusLine0Spanish, gJiminyEnemyCardBlackFungusLine1Spanish, gJiminyEnemyCardBlackFungusLine2Spanish, gJiminyEnemyCardBlackFungusLine3Spanish,
    gJiminyEnemyCardBlackFungusLine4Spanish,
};

const JiminyTextChar* gJiminyEnemyCardSoldierLines[5] = {
    gJiminyEnemyCardSoldierLine0, gJiminyEnemyCardSoldierLine1, gJiminyEnemyCardSoldierLine2, gJiminyEnemyCardSoldierLine3,
    gJiminyEnemyCardSoldierLine4,
};

const JiminyTextChar* gJiminyEnemyCardSoldierLinesFrench[5] = {
    gJiminyEnemyCardSoldierLine0French, gJiminyEnemyCardSoldierLine1French, gJiminyEnemyCardSoldierLine2French, gJiminyEnemyCardSoldierLine3French,
    gJiminyEnemyCardSoldierLine4French,
};

const JiminyTextChar* gJiminyEnemyCardSoldierLinesGerman[6] = {
    gJiminyEnemyCardSoldierLine0German, gJiminyEnemyCardSoldierLine1German, gJiminyEnemyCardSoldierLine2German, gJiminyEnemyCardSoldierLine3German,
    gJiminyEnemyCardSoldierLine4German, gJiminyEnemyCardSoldierLine5German,
};

const JiminyTextChar* gJiminyEnemyCardSoldierLinesItalian[5] = {
    gJiminyEnemyCardSoldierLine0Italian, gJiminyEnemyCardSoldierLine1Italian, gJiminyEnemyCardSoldierLine2Italian, gJiminyEnemyCardSoldierLine3Italian,
    gJiminyEnemyCardSoldierLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardSoldierLinesSpanish[5] = {
    gJiminyEnemyCardSoldierLine0Spanish, gJiminyEnemyCardSoldierLine1Spanish, gJiminyEnemyCardSoldierLine2Spanish, gJiminyEnemyCardSoldierLine3Spanish,
    gJiminyEnemyCardSoldierLine4Spanish,
};

const JiminyTextChar* gJiminyEnemyCardPowerwildLines[8] = {
    gJiminyEnemyCardPowerwildLine0, gJiminyEnemyCardPowerwildLine1, gJiminyEnemyCardPowerwildLine2, gJiminyEnemyCardPowerwildLine3,
    gJiminyEnemyCardPowerwildLine4, gJiminyEnemyCardPowerwildLine5, gJiminyEnemyCardPowerwildLine6, gJiminyEnemyCardPowerwildLine7,
};

const JiminyTextChar* gJiminyEnemyCardPowerwildLinesFrench[8] = {
    gJiminyEnemyCardPowerwildLine0French, gJiminyEnemyCardPowerwildLine1French, gJiminyEnemyCardPowerwildLine2French, gJiminyEnemyCardPowerwildLine3French,
    gJiminyEnemyCardPowerwildLine4French, gJiminyEnemyCardPowerwildLine5French, gJiminyEnemyCardPowerwildLine6French, gJiminyEnemyCardPowerwildLine7French,
};

const JiminyTextChar* gJiminyEnemyCardPowerwildLinesGerman[8] = {
    gJiminyEnemyCardPowerwildLine0German, gJiminyEnemyCardPowerwildLine1German, gJiminyEnemyCardPowerwildLine2German, gJiminyEnemyCardPowerwildLine3German,
    gJiminyEnemyCardPowerwildLine4German, gJiminyEnemyCardPowerwildLine5German, gJiminyEnemyCardPowerwildLine6German, gJiminyEnemyCardPowerwildLine7German,
};

const JiminyTextChar* gJiminyEnemyCardPowerwildLinesItalian[8] = {
    gJiminyEnemyCardPowerwildLine0Italian, gJiminyEnemyCardPowerwildLine1Italian, gJiminyEnemyCardPowerwildLine2Italian, gJiminyEnemyCardPowerwildLine3Italian,
    gJiminyEnemyCardPowerwildLine4Italian, gJiminyEnemyCardPowerwildLine5Italian, gJiminyEnemyCardPowerwildLine6Italian, gJiminyEnemyCardPowerwildLine7Italian,
};

const JiminyTextChar* gJiminyEnemyCardPowerwildLinesSpanish[8] = {
    gJiminyEnemyCardPowerwildLine0Spanish, gJiminyEnemyCardPowerwildLine1Spanish, gJiminyEnemyCardPowerwildLine2Spanish, gJiminyEnemyCardPowerwildLine3Spanish,
    gJiminyEnemyCardPowerwildLine4Spanish, gJiminyEnemyCardPowerwildLine5Spanish, gJiminyEnemyCardPowerwildLine6Spanish, gJiminyEnemyCardPowerwildLine7Spanish,
};

const JiminyTextChar* gJiminyEnemyCardBouncywildLines[6] = {
    gJiminyEnemyCardBouncywildLine0, gJiminyEnemyCardBouncywildLine1, gJiminyEnemyCardBouncywildLine2, gJiminyEnemyCardBouncywildLine3,
    gJiminyEnemyCardBouncywildLine4, gJiminyEnemyCardBouncywildLine5,
};

const JiminyTextChar* gJiminyEnemyCardBouncywildLinesFrench[5] = {
    gJiminyEnemyCardBouncywildLine0French, gJiminyEnemyCardBouncywildLine1French, gJiminyEnemyCardBouncywildLine2French, gJiminyEnemyCardBouncywildLine3French,
    gJiminyEnemyCardBouncywildLine4French,
};

const JiminyTextChar* gJiminyEnemyCardBouncywildLinesGerman[7] = {
    gJiminyEnemyCardBouncywildLine0German, gJiminyEnemyCardBouncywildLine1German, gJiminyEnemyCardBouncywildLine2German, gJiminyEnemyCardBouncywildLine3German,
    gJiminyEnemyCardBouncywildLine4German, gJiminyEnemyCardBouncywildLine5German, gJiminyEnemyCardBouncywildLine6German,
};

const JiminyTextChar* gJiminyEnemyCardBouncywildLinesItalian[6] = {
    gJiminyEnemyCardBouncywildLine0Italian, gJiminyEnemyCardBouncywildLine1Italian, gJiminyEnemyCardBouncywildLine2Italian, gJiminyEnemyCardBouncywildLine3Italian,
    gJiminyEnemyCardBouncywildLine4Italian, gJiminyEnemyCardBouncywildLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardBouncywildLinesSpanish[7] = {
    gJiminyEnemyCardBouncywildLine0Spanish, gJiminyEnemyCardBouncywildLine1Spanish, gJiminyEnemyCardBouncywildLine2Spanish, gJiminyEnemyCardBouncywildLine3Spanish,
    gJiminyEnemyCardBouncywildLine4Spanish, gJiminyEnemyCardBouncywildLine5Spanish, gJiminyEnemyCardBouncywildLine6Spanish,
};

const JiminyTextChar* gJiminyEnemyCardAirSoldierLines[4] = {
    gJiminyEnemyCardAirSoldierLine0, gJiminyEnemyCardAirSoldierLine1, gJiminyEnemyCardAirSoldierLine2, gJiminyEnemyCardAirSoldierLine3,
};

const JiminyTextChar* gJiminyEnemyCardAirSoldierLinesFrench[5] = {
    gJiminyEnemyCardAirSoldierLine0French, gJiminyEnemyCardAirSoldierLine1French, gJiminyEnemyCardAirSoldierLine2French, gJiminyEnemyCardAirSoldierLine3French,
    gJiminyEnemyCardAirSoldierLine4French,
};

const JiminyTextChar* gJiminyEnemyCardAirSoldierLinesGerman[6] = {
    gJiminyEnemyCardAirSoldierLine0German, gJiminyEnemyCardAirSoldierLine1German, gJiminyEnemyCardAirSoldierLine2German, gJiminyEnemyCardAirSoldierLine3German,
    gJiminyEnemyCardAirSoldierLine4German, gJiminyEnemyCardAirSoldierLine5German,
};

const JiminyTextChar* gJiminyEnemyCardAirSoldierLinesItalian[5] = {
    gJiminyEnemyCardAirSoldierLine0Italian, gJiminyEnemyCardAirSoldierLine1Italian, gJiminyEnemyCardAirSoldierLine2Italian, gJiminyEnemyCardAirSoldierLine3Italian,
    gJiminyEnemyCardAirSoldierLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardAirSoldierLinesSpanish[6] = {
    gJiminyEnemyCardAirSoldierLine0Spanish, gJiminyEnemyCardAirSoldierLine1Spanish, gJiminyEnemyCardAirSoldierLine2Spanish, gJiminyEnemyCardAirSoldierLine3Spanish,
    gJiminyEnemyCardAirSoldierLine4Spanish, gJiminyEnemyCardAirSoldierLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardBanditLines[6] = {
    gJiminyEnemyCardBanditLine0, gJiminyEnemyCardBanditLine1, gJiminyEnemyCardBanditLine2, gJiminyEnemyCardBanditLine3,
    gJiminyEnemyCardBanditLine4, gJiminyEnemyCardBanditLine5,
};

const JiminyTextChar* gJiminyEnemyCardBanditLinesFrench[6] = {
    gJiminyEnemyCardBanditLine0French, gJiminyEnemyCardBanditLine1French, gJiminyEnemyCardBanditLine2French, gJiminyEnemyCardBanditLine3French,
    gJiminyEnemyCardBanditLine4French, gJiminyEnemyCardBanditLine5French,
};

const JiminyTextChar* gJiminyEnemyCardBanditLinesGerman[7] = {
    gJiminyEnemyCardBanditLine0German, gJiminyEnemyCardBanditLine1German, gJiminyEnemyCardBanditLine2German, gJiminyEnemyCardBanditLine3German,
    gJiminyEnemyCardBanditLine4German, gJiminyEnemyCardBanditLine5German, gJiminyEnemyCardBanditLine6German,
};

const JiminyTextChar* gJiminyEnemyCardBanditLinesItalian[6] = {
    gJiminyEnemyCardBanditLine0Italian, gJiminyEnemyCardBanditLine1Italian, gJiminyEnemyCardBanditLine2Italian, gJiminyEnemyCardBanditLine3Italian,
    gJiminyEnemyCardBanditLine4Italian, gJiminyEnemyCardBanditLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardBanditLinesSpanish[6] = {
    gJiminyEnemyCardBanditLine0Spanish, gJiminyEnemyCardBanditLine1Spanish, gJiminyEnemyCardBanditLine2Spanish, gJiminyEnemyCardBanditLine3Spanish,
    gJiminyEnemyCardBanditLine4Spanish, gJiminyEnemyCardBanditLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardBarrelSpiderLines[4] = {
    gJiminyEnemyCardBarrelSpiderLine0, gJiminyEnemyCardBarrelSpiderLine1, gJiminyEnemyCardBarrelSpiderLine2, gJiminyEnemyCardBarrelSpiderLine3,
};

const JiminyTextChar* gJiminyEnemyCardBarrelSpiderLinesFrench[5] = {
    gJiminyEnemyCardBarrelSpiderLine0French, gJiminyEnemyCardBarrelSpiderLine1French, gJiminyEnemyCardBarrelSpiderLine2French, gJiminyEnemyCardBarrelSpiderLine3French,
    gJiminyEnemyCardBarrelSpiderLine4French,
};

const JiminyTextChar* gJiminyEnemyCardBarrelSpiderLinesGerman[5] = {
    gJiminyEnemyCardBarrelSpiderLine0German, gJiminyEnemyCardBarrelSpiderLine1German, gJiminyEnemyCardBarrelSpiderLine2German, gJiminyEnemyCardBarrelSpiderLine3German,
    gJiminyEnemyCardBarrelSpiderLine4German,
};

const JiminyTextChar* gJiminyEnemyCardBarrelSpiderLinesItalian[5] = {
    gJiminyEnemyCardBarrelSpiderLine0Italian, gJiminyEnemyCardBarrelSpiderLine1Italian, gJiminyEnemyCardBarrelSpiderLine2Italian, gJiminyEnemyCardBarrelSpiderLine3Italian,
    gJiminyEnemyCardBarrelSpiderLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardBarrelSpiderLinesSpanish[5] = {
    gJiminyEnemyCardBarrelSpiderLine0Spanish, gJiminyEnemyCardBarrelSpiderLine1Spanish, gJiminyEnemyCardBarrelSpiderLine2Spanish, gJiminyEnemyCardBarrelSpiderLine3Spanish,
    gJiminyEnemyCardBarrelSpiderLine4Spanish,
};

const JiminyTextChar* gJiminyEnemyCardSearchGhostLines[7] = {
    gJiminyEnemyCardSearchGhostLine0, gJiminyEnemyCardSearchGhostLine1, gJiminyEnemyCardSearchGhostLine2, gJiminyEnemyCardSearchGhostLine3,
    gJiminyEnemyCardSearchGhostLine4, gJiminyEnemyCardSearchGhostLine5, gJiminyEnemyCardSearchGhostLine6,
};

const JiminyTextChar* gJiminyEnemyCardSearchGhostLinesFrench[7] = {
    gJiminyEnemyCardSearchGhostLine0French, gJiminyEnemyCardSearchGhostLine1French, gJiminyEnemyCardSearchGhostLine2French, gJiminyEnemyCardSearchGhostLine3French,
    gJiminyEnemyCardSearchGhostLine4French, gJiminyEnemyCardSearchGhostLine5French, gJiminyEnemyCardSearchGhostLine6French,
};

const JiminyTextChar* gJiminyEnemyCardSearchGhostLinesGerman[8] = {
    gJiminyEnemyCardSearchGhostLine0German, gJiminyEnemyCardSearchGhostLine1German, gJiminyEnemyCardSearchGhostLine2German, gJiminyEnemyCardSearchGhostLine3German,
    gJiminyEnemyCardSearchGhostLine4German, gJiminyEnemyCardSearchGhostLine5German, gJiminyEnemyCardSearchGhostLine6German, gJiminyEnemyCardSearchGhostLine7German,
};

const JiminyTextChar* gJiminyEnemyCardSearchGhostLinesItalian[8] = {
    gJiminyEnemyCardSearchGhostLine0Italian, gJiminyEnemyCardSearchGhostLine1Italian, gJiminyEnemyCardSearchGhostLine2Italian, gJiminyEnemyCardSearchGhostLine3Italian,
    gJiminyEnemyCardSearchGhostLine4Italian, gJiminyEnemyCardSearchGhostLine5Italian, gJiminyEnemyCardSearchGhostLine6Italian, gJiminyEnemyCardSearchGhostLine7Italian,
};

const JiminyTextChar* gJiminyEnemyCardSearchGhostLinesSpanish[8] = {
    gJiminyEnemyCardSearchGhostLine0Spanish, gJiminyEnemyCardSearchGhostLine1Spanish, gJiminyEnemyCardSearchGhostLine2Spanish, gJiminyEnemyCardSearchGhostLine3Spanish,
    gJiminyEnemyCardSearchGhostLine4Spanish, gJiminyEnemyCardSearchGhostLine5Spanish, gJiminyEnemyCardSearchGhostLine6Spanish, gJiminyEnemyCardSearchGhostLine7Spanish,
};

const JiminyTextChar* gJiminyEnemyCardScrewdiverLines[5] = {
    gJiminyEnemyCardScrewdiverLine0, gJiminyEnemyCardScrewdiverLine1, gJiminyEnemyCardScrewdiverLine2, gJiminyEnemyCardScrewdiverLine3,
    gJiminyEnemyCardScrewdiverLine4,
};

const JiminyTextChar* gJiminyEnemyCardScrewdiverLinesFrench[5] = {
    gJiminyEnemyCardScrewdiverLine0French, gJiminyEnemyCardScrewdiverLine1French, gJiminyEnemyCardScrewdiverLine2French, gJiminyEnemyCardScrewdiverLine3French,
    gJiminyEnemyCardScrewdiverLine4French,
};

const JiminyTextChar* gJiminyEnemyCardScrewdiverLinesGerman[5] = {
    gJiminyEnemyCardScrewdiverLine0German, gJiminyEnemyCardScrewdiverLine1German, gJiminyEnemyCardScrewdiverLine2German, gJiminyEnemyCardScrewdiverLine3German,
    gJiminyEnemyCardScrewdiverLine4German,
};

const JiminyTextChar* gJiminyEnemyCardScrewdiverLinesItalian[5] = {
    gJiminyEnemyCardScrewdiverLine0Italian, gJiminyEnemyCardScrewdiverLine1Italian, gJiminyEnemyCardScrewdiverLine2Italian, gJiminyEnemyCardScrewdiverLine3Italian,
    gJiminyEnemyCardScrewdiverLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardScrewdiverLinesSpanish[5] = {
    gJiminyEnemyCardScrewdiverLine0Spanish, gJiminyEnemyCardScrewdiverLine1Spanish, gJiminyEnemyCardScrewdiverLine2Spanish, gJiminyEnemyCardScrewdiverLine3Spanish,
    gJiminyEnemyCardScrewdiverLine4Spanish,
};

const JiminyTextChar* gJiminyEnemyCardWightKnightLines[5] = {
    gJiminyEnemyCardWightKnightLine0, gJiminyEnemyCardWightKnightLine1, gJiminyEnemyCardWightKnightLine2, gJiminyEnemyCardWightKnightLine3,
    gJiminyEnemyCardWightKnightLine4,
};

const JiminyTextChar* gJiminyEnemyCardWightKnightLinesFrench[5] = {
    gJiminyEnemyCardWightKnightLine0French, gJiminyEnemyCardWightKnightLine1French, gJiminyEnemyCardWightKnightLine2French, gJiminyEnemyCardWightKnightLine3French,
    gJiminyEnemyCardWightKnightLine4French,
};

const JiminyTextChar* gJiminyEnemyCardWightKnightLinesGerman[8] = {
    gJiminyEnemyCardWightKnightLine0German, gJiminyEnemyCardWightKnightLine1German, gJiminyEnemyCardWightKnightLine2German, gJiminyEnemyCardWightKnightLine3German,
    gJiminyEnemyCardWightKnightLine4German, gJiminyEnemyCardWightKnightLine5German, gJiminyEnemyCardWightKnightLine6German, gJiminyEnemyCardWightKnightLine7German,
};

const JiminyTextChar* gJiminyEnemyCardWightKnightLinesItalian[6] = {
    gJiminyEnemyCardWightKnightLine0Italian, gJiminyEnemyCardWightKnightLine1Italian, gJiminyEnemyCardWightKnightLine2Italian, gJiminyEnemyCardWightKnightLine3Italian,
    gJiminyEnemyCardWightKnightLine4Italian, gJiminyEnemyCardWightKnightLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardWightKnightLinesSpanish[6] = {
    gJiminyEnemyCardWightKnightLine0Spanish, gJiminyEnemyCardWightKnightLine1Spanish, gJiminyEnemyCardWightKnightLine2Spanish, gJiminyEnemyCardWightKnightLine3Spanish,
    gJiminyEnemyCardWightKnightLine4Spanish, gJiminyEnemyCardWightKnightLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardGargoyleLines[6] = {
    gJiminyEnemyCardGargoyleLine0, gJiminyEnemyCardGargoyleLine1, gJiminyEnemyCardGargoyleLine2, gJiminyEnemyCardGargoyleLine3,
    gJiminyEnemyCardGargoyleLine4, gJiminyEnemyCardGargoyleLine5,
};

const JiminyTextChar* gJiminyEnemyCardGargoyleLinesFrench[6] = {
    gJiminyEnemyCardGargoyleLine0French, gJiminyEnemyCardGargoyleLine1French, gJiminyEnemyCardGargoyleLine2French, gJiminyEnemyCardGargoyleLine3French,
    gJiminyEnemyCardGargoyleLine4French, gJiminyEnemyCardGargoyleLine5French,
};

const JiminyTextChar* gJiminyEnemyCardGargoyleLinesGerman[6] = {
    gJiminyEnemyCardGargoyleLine0German, gJiminyEnemyCardGargoyleLine1German, gJiminyEnemyCardGargoyleLine2German, gJiminyEnemyCardGargoyleLine3German,
    gJiminyEnemyCardGargoyleLine4German, gJiminyEnemyCardGargoyleLine5German,
};

const JiminyTextChar* gJiminyEnemyCardGargoyleLinesItalian[6] = {
    gJiminyEnemyCardGargoyleLine0Italian, gJiminyEnemyCardGargoyleLine1Italian, gJiminyEnemyCardGargoyleLine2Italian, gJiminyEnemyCardGargoyleLine3Italian,
    gJiminyEnemyCardGargoyleLine4Italian, gJiminyEnemyCardGargoyleLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardGargoyleLinesSpanish[6] = {
    gJiminyEnemyCardGargoyleLine0Spanish, gJiminyEnemyCardGargoyleLine1Spanish, gJiminyEnemyCardGargoyleLine2Spanish, gJiminyEnemyCardGargoyleLine3Spanish,
    gJiminyEnemyCardGargoyleLine4Spanish, gJiminyEnemyCardGargoyleLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardPirateLines[5] = {
    gJiminyEnemyCardPirateLine0, gJiminyEnemyCardPirateLine1, gJiminyEnemyCardPirateLine2, gJiminyEnemyCardPirateLine3,
    gJiminyEnemyCardPirateLine4,
};

const JiminyTextChar* gJiminyEnemyCardPirateLinesFrench[5] = {
    gJiminyEnemyCardPirateLine0French, gJiminyEnemyCardPirateLine1French, gJiminyEnemyCardPirateLine2French, gJiminyEnemyCardPirateLine3French,
    gJiminyEnemyCardPirateLine4French,
};

const JiminyTextChar* gJiminyEnemyCardPirateLinesGerman[5] = {
    gJiminyEnemyCardPirateLine0German, gJiminyEnemyCardPirateLine1German, gJiminyEnemyCardPirateLine2German, gJiminyEnemyCardPirateLine3German,
    gJiminyEnemyCardPirateLine4German,
};

const JiminyTextChar* gJiminyEnemyCardPirateLinesItalian[5] = {
    gJiminyEnemyCardPirateLine0Italian, gJiminyEnemyCardPirateLine1Italian, gJiminyEnemyCardPirateLine2Italian, gJiminyEnemyCardPirateLine3Italian,
    gJiminyEnemyCardPirateLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardPirateLinesSpanish[5] = {
    gJiminyEnemyCardPirateLine0Spanish, gJiminyEnemyCardPirateLine1Spanish, gJiminyEnemyCardPirateLine2Spanish, gJiminyEnemyCardPirateLine3Spanish,
    gJiminyEnemyCardPirateLine4Spanish,
};

const JiminyTextChar* gJiminyEnemyCardAirPirateLines[6] = {
    gJiminyEnemyCardAirPirateLine0, gJiminyEnemyCardAirPirateLine1, gJiminyEnemyCardAirPirateLine2, gJiminyEnemyCardAirPirateLine3,
    gJiminyEnemyCardAirPirateLine4, gJiminyEnemyCardAirPirateLine5,
};

const JiminyTextChar* gJiminyEnemyCardAirPirateLinesFrench[6] = {
    gJiminyEnemyCardAirPirateLine0French, gJiminyEnemyCardAirPirateLine1French, gJiminyEnemyCardAirPirateLine2French, gJiminyEnemyCardAirPirateLine3French,
    gJiminyEnemyCardAirPirateLine4French, gJiminyEnemyCardAirPirateLine5French,
};

const JiminyTextChar* gJiminyEnemyCardAirPirateLinesGerman[6] = {
    gJiminyEnemyCardAirPirateLine0German, gJiminyEnemyCardAirPirateLine1German, gJiminyEnemyCardAirPirateLine2German, gJiminyEnemyCardAirPirateLine3German,
    gJiminyEnemyCardAirPirateLine4German, gJiminyEnemyCardAirPirateLine5German,
};

const JiminyTextChar* gJiminyEnemyCardAirPirateLinesItalian[6] = {
    gJiminyEnemyCardAirPirateLine0Italian, gJiminyEnemyCardAirPirateLine1Italian, gJiminyEnemyCardAirPirateLine2Italian, gJiminyEnemyCardAirPirateLine3Italian,
    gJiminyEnemyCardAirPirateLine4Italian, gJiminyEnemyCardAirPirateLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardAirPirateLinesSpanish[6] = {
    gJiminyEnemyCardAirPirateLine0Spanish, gJiminyEnemyCardAirPirateLine1Spanish, gJiminyEnemyCardAirPirateLine2Spanish, gJiminyEnemyCardAirPirateLine3Spanish,
    gJiminyEnemyCardAirPirateLine4Spanish, gJiminyEnemyCardAirPirateLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardDarkballLines[5] = {
    gJiminyEnemyCardDarkballLine0, gJiminyEnemyCardDarkballLine1, gJiminyEnemyCardDarkballLine2, gJiminyEnemyCardDarkballLine3,
    gJiminyEnemyCardDarkballLine4,
};

const JiminyTextChar* gJiminyEnemyCardDarkballLinesFrench[5] = {
    gJiminyEnemyCardDarkballLine0French, gJiminyEnemyCardDarkballLine1French, gJiminyEnemyCardDarkballLine2French, gJiminyEnemyCardDarkballLine3French,
    gJiminyEnemyCardDarkballLine4French,
};

const JiminyTextChar* gJiminyEnemyCardDarkballLinesGerman[5] = {
    gJiminyEnemyCardDarkballLine0German, gJiminyEnemyCardDarkballLine1German, gJiminyEnemyCardDarkballLine2German, gJiminyEnemyCardDarkballLine3German,
    gJiminyEnemyCardDarkballLine4German,
};

const JiminyTextChar* gJiminyEnemyCardDarkballLinesItalian[5] = {
    gJiminyEnemyCardDarkballLine0Italian, gJiminyEnemyCardDarkballLine1Italian, gJiminyEnemyCardDarkballLine2Italian, gJiminyEnemyCardDarkballLine3Italian,
    gJiminyEnemyCardDarkballLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardDarkballLinesSpanish[6] = {
    gJiminyEnemyCardDarkballLine0Spanish, gJiminyEnemyCardDarkballLine1Spanish, gJiminyEnemyCardDarkballLine2Spanish, gJiminyEnemyCardDarkballLine3Spanish,
    gJiminyEnemyCardDarkballLine4Spanish, gJiminyEnemyCardDarkballLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardWyvernLines[6] = {
    gJiminyEnemyCardWyvernLine0, gJiminyEnemyCardWyvernLine1, gJiminyEnemyCardWyvernLine2, gJiminyEnemyCardWyvernLine3,
    gJiminyEnemyCardWyvernLine4, gJiminyEnemyCardWyvernLine5,
};

const JiminyTextChar* gJiminyEnemyCardWyvernLinesFrench[5] = {
    gJiminyEnemyCardWyvernLine0French, gJiminyEnemyCardWyvernLine1French, gJiminyEnemyCardWyvernLine2French, gJiminyEnemyCardWyvernLine3French,
    gJiminyEnemyCardWyvernLine4French,
};

const JiminyTextChar* gJiminyEnemyCardWyvernLinesGerman[7] = {
    gJiminyEnemyCardWyvernLine0German, gJiminyEnemyCardWyvernLine1German, gJiminyEnemyCardWyvernLine2German, gJiminyEnemyCardWyvernLine3German,
    gJiminyEnemyCardWyvernLine4German, gJiminyEnemyCardWyvernLine5German, gJiminyEnemyCardWyvernLine6German,
};

const JiminyTextChar* gJiminyEnemyCardWyvernLinesItalian[6] = {
    gJiminyEnemyCardWyvernLine0Italian, gJiminyEnemyCardWyvernLine1Italian, gJiminyEnemyCardWyvernLine2Italian, gJiminyEnemyCardWyvernLine3Italian,
    gJiminyEnemyCardWyvernLine4Italian, gJiminyEnemyCardWyvernLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardWyvernLinesSpanish[6] = {
    gJiminyEnemyCardWyvernLine0Spanish, gJiminyEnemyCardWyvernLine1Spanish, gJiminyEnemyCardWyvernLine2Spanish, gJiminyEnemyCardWyvernLine3Spanish,
    gJiminyEnemyCardWyvernLine4Spanish, gJiminyEnemyCardWyvernLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardWizardLines[6] = {
    gJiminyEnemyCardWizardLine0, gJiminyEnemyCardWizardLine1, gJiminyEnemyCardWizardLine2, gJiminyEnemyCardWizardLine3,
    gJiminyEnemyCardWizardLine4, gJiminyEnemyCardWizardLine5,
};

const JiminyTextChar* gJiminyEnemyCardWizardLinesFrench[6] = {
    gJiminyEnemyCardWizardLine0French, gJiminyEnemyCardWizardLine1French, gJiminyEnemyCardWizardLine2French, gJiminyEnemyCardWizardLine3French,
    gJiminyEnemyCardWizardLine4French, gJiminyEnemyCardWizardLine5French,
};

const JiminyTextChar* gJiminyEnemyCardWizardLinesGerman[8] = {
    gJiminyEnemyCardWizardLine0German, gJiminyEnemyCardWizardLine1German, gJiminyEnemyCardWizardLine2German, gJiminyEnemyCardWizardLine3German,
    gJiminyEnemyCardWizardLine4German, gJiminyEnemyCardWizardLine5German, gJiminyEnemyCardWizardLine6German, gJiminyEnemyCardWizardLine7German,
};

const JiminyTextChar* gJiminyEnemyCardWizardLinesItalian[7] = {
    gJiminyEnemyCardWizardLine0Italian, gJiminyEnemyCardWizardLine1Italian, gJiminyEnemyCardWizardLine2Italian, gJiminyEnemyCardWizardLine3Italian,
    gJiminyEnemyCardWizardLine4Italian, gJiminyEnemyCardWizardLine5Italian, gJiminyEnemyCardWizardLine6Italian,
};

const JiminyTextChar* gJiminyEnemyCardWizardLinesSpanish[7] = {
    gJiminyEnemyCardWizardLine0Spanish, gJiminyEnemyCardWizardLine1Spanish, gJiminyEnemyCardWizardLine2Spanish, gJiminyEnemyCardWizardLine3Spanish,
    gJiminyEnemyCardWizardLine4Spanish, gJiminyEnemyCardWizardLine5Spanish, gJiminyEnemyCardWizardLine6Spanish,
};

const JiminyTextChar* gJiminyEnemyCardNeoshadowLines[5] = {
    gJiminyEnemyCardNeoshadowLine0, gJiminyEnemyCardNeoshadowLine1, gJiminyEnemyCardNeoshadowLine2, gJiminyEnemyCardNeoshadowLine3,
    gJiminyEnemyCardNeoshadowLine4,
};

const JiminyTextChar* gJiminyEnemyCardNeoshadowLinesFrench[5] = {
    gJiminyEnemyCardNeoshadowLine0French, gJiminyEnemyCardNeoshadowLine1French, gJiminyEnemyCardNeoshadowLine2French, gJiminyEnemyCardNeoshadowLine3French,
    gJiminyEnemyCardNeoshadowLine4French,
};

const JiminyTextChar* gJiminyEnemyCardNeoshadowLinesGerman[5] = {
    gJiminyEnemyCardNeoshadowLine0German, gJiminyEnemyCardNeoshadowLine1German, gJiminyEnemyCardNeoshadowLine2German, gJiminyEnemyCardNeoshadowLine3German,
    gJiminyEnemyCardNeoshadowLine4German,
};

const JiminyTextChar* gJiminyEnemyCardNeoshadowLinesItalian[5] = {
    gJiminyEnemyCardNeoshadowLine0Italian, gJiminyEnemyCardNeoshadowLine1Italian, gJiminyEnemyCardNeoshadowLine2Italian, gJiminyEnemyCardNeoshadowLine3Italian,
    gJiminyEnemyCardNeoshadowLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardNeoshadowLinesSpanish[6] = {
    gJiminyEnemyCardNeoshadowLine0Spanish, gJiminyEnemyCardNeoshadowLine1Spanish, gJiminyEnemyCardNeoshadowLine2Spanish, gJiminyEnemyCardNeoshadowLine3Spanish,
    gJiminyEnemyCardNeoshadowLine4Spanish, gJiminyEnemyCardNeoshadowLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardLargeBodyLines[6] = {
    gJiminyEnemyCardLargeBodyLine0, gJiminyEnemyCardLargeBodyLine1, gJiminyEnemyCardLargeBodyLine2, gJiminyEnemyCardLargeBodyLine3,
    gJiminyEnemyCardLargeBodyLine4, gJiminyEnemyCardLargeBodyLine5,
};

const JiminyTextChar* gJiminyEnemyCardLargeBodyLinesFrench[6] = {
    gJiminyEnemyCardLargeBodyLine0French, gJiminyEnemyCardLargeBodyLine1French, gJiminyEnemyCardLargeBodyLine2French, gJiminyEnemyCardLargeBodyLine3French,
    gJiminyEnemyCardLargeBodyLine4French, gJiminyEnemyCardLargeBodyLine5French,
};

const JiminyTextChar* gJiminyEnemyCardLargeBodyLinesGerman[6] = {
    gJiminyEnemyCardLargeBodyLine0German, gJiminyEnemyCardLargeBodyLine1German, gJiminyEnemyCardLargeBodyLine2German, gJiminyEnemyCardLargeBodyLine3German,
    gJiminyEnemyCardLargeBodyLine4German, gJiminyEnemyCardLargeBodyLine5German,
};

const JiminyTextChar* gJiminyEnemyCardLargeBodyLinesItalian[6] = {
    gJiminyEnemyCardLargeBodyLine0Italian, gJiminyEnemyCardLargeBodyLine1Italian, gJiminyEnemyCardLargeBodyLine2Italian, gJiminyEnemyCardLargeBodyLine3Italian,
    gJiminyEnemyCardLargeBodyLine4Italian, gJiminyEnemyCardLargeBodyLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardLargeBodyLinesSpanish[7] = {
    gJiminyEnemyCardLargeBodyLine0Spanish, gJiminyEnemyCardLargeBodyLine1Spanish, gJiminyEnemyCardLargeBodyLine2Spanish, gJiminyEnemyCardLargeBodyLine3Spanish,
    gJiminyEnemyCardLargeBodyLine4Spanish, gJiminyEnemyCardLargeBodyLine5Spanish, gJiminyEnemyCardLargeBodyLine6Spanish,
};

const JiminyTextChar* gJiminyEnemyCardFatBanditLines[6] = {
    gJiminyEnemyCardFatBanditLine0, gJiminyEnemyCardFatBanditLine1, gJiminyEnemyCardFatBanditLine2, gJiminyEnemyCardFatBanditLine3,
    gJiminyEnemyCardFatBanditLine4, gJiminyEnemyCardFatBanditLine5,
};

const JiminyTextChar* gJiminyEnemyCardFatBanditLinesFrench[6] = {
    gJiminyEnemyCardFatBanditLine0French, gJiminyEnemyCardFatBanditLine1French, gJiminyEnemyCardFatBanditLine2French, gJiminyEnemyCardFatBanditLine3French,
    gJiminyEnemyCardFatBanditLine4French, gJiminyEnemyCardFatBanditLine5French,
};

const JiminyTextChar* gJiminyEnemyCardFatBanditLinesGerman[6] = {
    gJiminyEnemyCardFatBanditLine0German, gJiminyEnemyCardFatBanditLine1German, gJiminyEnemyCardFatBanditLine2German, gJiminyEnemyCardFatBanditLine3German,
    gJiminyEnemyCardFatBanditLine4German, gJiminyEnemyCardFatBanditLine5German,
};

const JiminyTextChar* gJiminyEnemyCardFatBanditLinesItalian[6] = {
    gJiminyEnemyCardFatBanditLine0Italian, gJiminyEnemyCardFatBanditLine1Italian, gJiminyEnemyCardFatBanditLine2Italian, gJiminyEnemyCardFatBanditLine3Italian,
    gJiminyEnemyCardFatBanditLine4Italian, gJiminyEnemyCardFatBanditLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardFatBanditLinesSpanish[6] = {
    gJiminyEnemyCardFatBanditLine0Spanish, gJiminyEnemyCardFatBanditLine1Spanish, gJiminyEnemyCardFatBanditLine2Spanish, gJiminyEnemyCardFatBanditLine3Spanish,
    gJiminyEnemyCardFatBanditLine4Spanish, gJiminyEnemyCardFatBanditLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardAquatankLines[6] = {
    gJiminyEnemyCardAquatankLine0, gJiminyEnemyCardAquatankLine1, gJiminyEnemyCardAquatankLine2, gJiminyEnemyCardAquatankLine3,
    gJiminyEnemyCardAquatankLine4, gJiminyEnemyCardAquatankLine5,
};

const JiminyTextChar* gJiminyEnemyCardAquatankLinesFrench[6] = {
    gJiminyEnemyCardAquatankLine0French, gJiminyEnemyCardAquatankLine1French, gJiminyEnemyCardAquatankLine2French, gJiminyEnemyCardAquatankLine3French,
    gJiminyEnemyCardAquatankLine4French, gJiminyEnemyCardAquatankLine5French,
};

const JiminyTextChar* gJiminyEnemyCardAquatankLinesGerman[7] = {
    gJiminyEnemyCardAquatankLine0German, gJiminyEnemyCardAquatankLine1German, gJiminyEnemyCardAquatankLine2German, gJiminyEnemyCardAquatankLine3German,
    gJiminyEnemyCardAquatankLine4German, gJiminyEnemyCardAquatankLine5German, gJiminyEnemyCardAquatankLine6German,
};

const JiminyTextChar* gJiminyEnemyCardAquatankLinesItalian[6] = {
    gJiminyEnemyCardAquatankLine0Italian, gJiminyEnemyCardAquatankLine1Italian, gJiminyEnemyCardAquatankLine2Italian, gJiminyEnemyCardAquatankLine3Italian,
    gJiminyEnemyCardAquatankLine4Italian, gJiminyEnemyCardAquatankLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardAquatankLinesSpanish[6] = {
    gJiminyEnemyCardAquatankLine0Spanish, gJiminyEnemyCardAquatankLine1Spanish, gJiminyEnemyCardAquatankLine2Spanish, gJiminyEnemyCardAquatankLine3Spanish,
    gJiminyEnemyCardAquatankLine4Spanish, gJiminyEnemyCardAquatankLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardDefenderLines[7] = {
    gJiminyEnemyCardDefenderLine0, gJiminyEnemyCardDefenderLine1, gJiminyEnemyCardDefenderLine2, gJiminyEnemyCardDefenderLine3,
    gJiminyEnemyCardDefenderLine4, gJiminyEnemyCardDefenderLine5, gJiminyEnemyCardDefenderLine6,
};

const JiminyTextChar* gJiminyEnemyCardDefenderLinesFrench[8] = {
    gJiminyEnemyCardDefenderLine0French, gJiminyEnemyCardDefenderLine1French, gJiminyEnemyCardDefenderLine2French, gJiminyEnemyCardDefenderLine3French,
    gJiminyEnemyCardDefenderLine4French, gJiminyEnemyCardDefenderLine5French, gJiminyEnemyCardDefenderLine6French, gJiminyEnemyCardDefenderLine7French,
};

const JiminyTextChar* gJiminyEnemyCardDefenderLinesGerman[8] = {
    gJiminyEnemyCardDefenderLine0German, gJiminyEnemyCardDefenderLine1German, gJiminyEnemyCardDefenderLine2German, gJiminyEnemyCardDefenderLine3German,
    gJiminyEnemyCardDefenderLine4German, gJiminyEnemyCardDefenderLine5German, gJiminyEnemyCardDefenderLine6German, gJiminyEnemyCardDefenderLine7German,
};

const JiminyTextChar* gJiminyEnemyCardDefenderLinesItalian[7] = {
    gJiminyEnemyCardDefenderLine0Italian, gJiminyEnemyCardDefenderLine1Italian, gJiminyEnemyCardDefenderLine2Italian, gJiminyEnemyCardDefenderLine3Italian,
    gJiminyEnemyCardDefenderLine4Italian, gJiminyEnemyCardDefenderLine5Italian, gJiminyEnemyCardDefenderLine6Italian,
};

const JiminyTextChar* gJiminyEnemyCardDefenderLinesSpanish[7] = {
    gJiminyEnemyCardDefenderLine0Spanish, gJiminyEnemyCardDefenderLine1Spanish, gJiminyEnemyCardDefenderLine2Spanish, gJiminyEnemyCardDefenderLine3Spanish,
    gJiminyEnemyCardDefenderLine4Spanish, gJiminyEnemyCardDefenderLine5Spanish, gJiminyEnemyCardDefenderLine6Spanish,
};

const JiminyTextChar* gJiminyEnemyCardTornadoStepLines[5] = {
    gJiminyEnemyCardTornadoStepLine0, gJiminyEnemyCardTornadoStepLine1, gJiminyEnemyCardTornadoStepLine2, gJiminyEnemyCardTornadoStepLine3,
    gJiminyEnemyCardTornadoStepLine4,
};

const JiminyTextChar* gJiminyEnemyCardTornadoStepLinesFrench[5] = {
    gJiminyEnemyCardTornadoStepLine0French, gJiminyEnemyCardTornadoStepLine1French, gJiminyEnemyCardTornadoStepLine2French, gJiminyEnemyCardTornadoStepLine3French,
    gJiminyEnemyCardTornadoStepLine4French,
};

const JiminyTextChar* gJiminyEnemyCardTornadoStepLinesGerman[5] = {
    gJiminyEnemyCardTornadoStepLine0German, gJiminyEnemyCardTornadoStepLine1German, gJiminyEnemyCardTornadoStepLine2German, gJiminyEnemyCardTornadoStepLine3German,
    gJiminyEnemyCardTornadoStepLine4German,
};

const JiminyTextChar* gJiminyEnemyCardTornadoStepLinesItalian[5] = {
    gJiminyEnemyCardTornadoStepLine0Italian, gJiminyEnemyCardTornadoStepLine1Italian, gJiminyEnemyCardTornadoStepLine2Italian, gJiminyEnemyCardTornadoStepLine3Italian,
    gJiminyEnemyCardTornadoStepLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardTornadoStepLinesSpanish[5] = {
    gJiminyEnemyCardTornadoStepLine0Spanish, gJiminyEnemyCardTornadoStepLine1Spanish, gJiminyEnemyCardTornadoStepLine2Spanish, gJiminyEnemyCardTornadoStepLine3Spanish,
    gJiminyEnemyCardTornadoStepLine4Spanish,
};

const JiminyTextChar* gJiminyEnemyCardCrescendoLines[6] = {
    gJiminyEnemyCardCrescendoLine0, gJiminyEnemyCardCrescendoLine1, gJiminyEnemyCardCrescendoLine2, gJiminyEnemyCardCrescendoLine3,
    gJiminyEnemyCardCrescendoLine4, gJiminyEnemyCardCrescendoLine5,
};

const JiminyTextChar* gJiminyEnemyCardCrescendoLinesFrench[6] = {
    gJiminyEnemyCardCrescendoLine0French, gJiminyEnemyCardCrescendoLine1French, gJiminyEnemyCardCrescendoLine2French, gJiminyEnemyCardCrescendoLine3French,
    gJiminyEnemyCardCrescendoLine4French, gJiminyEnemyCardCrescendoLine5French,
};

const JiminyTextChar* gJiminyEnemyCardCrescendoLinesGerman[8] = {
    gJiminyEnemyCardCrescendoLine0German, gJiminyEnemyCardCrescendoLine1German, gJiminyEnemyCardCrescendoLine2German, gJiminyEnemyCardCrescendoLine3German,
    gJiminyEnemyCardCrescendoLine4German, gJiminyEnemyCardCrescendoLine5German, gJiminyEnemyCardCrescendoLine6German, gJiminyEnemyCardCrescendoLine7German,
};

const JiminyTextChar* gJiminyEnemyCardCrescendoLinesItalian[7] = {
    gJiminyEnemyCardCrescendoLine0Italian, gJiminyEnemyCardCrescendoLine1Italian, gJiminyEnemyCardCrescendoLine2Italian, gJiminyEnemyCardCrescendoLine3Italian,
    gJiminyEnemyCardCrescendoLine4Italian, gJiminyEnemyCardCrescendoLine5Italian, gJiminyEnemyCardCrescendoLine6Italian,
};

const JiminyTextChar* gJiminyEnemyCardCrescendoLinesSpanish[6] = {
    gJiminyEnemyCardCrescendoLine0Spanish, gJiminyEnemyCardCrescendoLine1Spanish, gJiminyEnemyCardCrescendoLine2Spanish, gJiminyEnemyCardCrescendoLine3Spanish,
    gJiminyEnemyCardCrescendoLine4Spanish, gJiminyEnemyCardCrescendoLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardCreeperPlantLines[6] = {
    gJiminyEnemyCardCreeperPlantLine0, gJiminyEnemyCardCreeperPlantLine1, gJiminyEnemyCardCreeperPlantLine2, gJiminyEnemyCardCreeperPlantLine3,
    gJiminyEnemyCardCreeperPlantLine4, gJiminyEnemyCardCreeperPlantLine5,
};

const JiminyTextChar* gJiminyEnemyCardCreeperPlantLinesFrench[6] = {
    gJiminyEnemyCardCreeperPlantLine0French, gJiminyEnemyCardCreeperPlantLine1French, gJiminyEnemyCardCreeperPlantLine2French, gJiminyEnemyCardCreeperPlantLine3French,
    gJiminyEnemyCardCreeperPlantLine4French, gJiminyEnemyCardCreeperPlantLine5French,
};

const JiminyTextChar* gJiminyEnemyCardCreeperPlantLinesGerman[6] = {
    gJiminyEnemyCardCreeperPlantLine0German, gJiminyEnemyCardCreeperPlantLine1German, gJiminyEnemyCardCreeperPlantLine2German, gJiminyEnemyCardCreeperPlantLine3German,
    gJiminyEnemyCardCreeperPlantLine4German, gJiminyEnemyCardCreeperPlantLine5German,
};

const JiminyTextChar* gJiminyEnemyCardCreeperPlantLinesItalian[6] = {
    gJiminyEnemyCardCreeperPlantLine0Italian, gJiminyEnemyCardCreeperPlantLine1Italian, gJiminyEnemyCardCreeperPlantLine2Italian, gJiminyEnemyCardCreeperPlantLine3Italian,
    gJiminyEnemyCardCreeperPlantLine4Italian, gJiminyEnemyCardCreeperPlantLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardCreeperPlantLinesSpanish[6] = {
    gJiminyEnemyCardCreeperPlantLine0Spanish, gJiminyEnemyCardCreeperPlantLine1Spanish, gJiminyEnemyCardCreeperPlantLine2Spanish, gJiminyEnemyCardCreeperPlantLine3Spanish,
    gJiminyEnemyCardCreeperPlantLine4Spanish, gJiminyEnemyCardCreeperPlantLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardGuardArmorLines[5] = {
    gJiminyEnemyCardGuardArmorLine0, gJiminyEnemyCardGuardArmorLine1, gJiminyEnemyCardGuardArmorLine2, gJiminyEnemyCardGuardArmorLine3,
    gJiminyEnemyCardGuardArmorLine4,
};

const JiminyTextChar* gJiminyEnemyCardGuardArmorLinesFrench[5] = {
    gJiminyEnemyCardGuardArmorLine0French, gJiminyEnemyCardGuardArmorLine1French, gJiminyEnemyCardGuardArmorLine2French, gJiminyEnemyCardGuardArmorLine3French,
    gJiminyEnemyCardGuardArmorLine4French,
};

const JiminyTextChar* gJiminyEnemyCardGuardArmorLinesGerman[6] = {
    gJiminyEnemyCardGuardArmorLine0German, gJiminyEnemyCardGuardArmorLine1German, gJiminyEnemyCardGuardArmorLine2German, gJiminyEnemyCardGuardArmorLine3German,
    gJiminyEnemyCardGuardArmorLine4German, gJiminyEnemyCardGuardArmorLine5German,
};

const JiminyTextChar* gJiminyEnemyCardGuardArmorLinesItalian[6] = {
    gJiminyEnemyCardGuardArmorLine0Italian, gJiminyEnemyCardGuardArmorLine1Italian, gJiminyEnemyCardGuardArmorLine2Italian, gJiminyEnemyCardGuardArmorLine3Italian,
    gJiminyEnemyCardGuardArmorLine4Italian, gJiminyEnemyCardGuardArmorLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardGuardArmorLinesSpanish[6] = {
    gJiminyEnemyCardGuardArmorLine0Spanish, gJiminyEnemyCardGuardArmorLine1Spanish, gJiminyEnemyCardGuardArmorLine2Spanish, gJiminyEnemyCardGuardArmorLine3Spanish,
    gJiminyEnemyCardGuardArmorLine4Spanish, gJiminyEnemyCardGuardArmorLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardCardSoldierLines[5] = {
    gJiminyEnemyCardCardSoldierLine0, gJiminyEnemyCardCardSoldierLine1, gJiminyEnemyCardCardSoldierLine2, gJiminyEnemyCardCardSoldierLine3,
    gJiminyEnemyCardCardSoldierLine4,
};

const JiminyTextChar* gJiminyEnemyCardCardSoldierLinesFrench[5] = {
    gJiminyEnemyCardCardSoldierLine0French, gJiminyEnemyCardCardSoldierLine1French, gJiminyEnemyCardCardSoldierLine2French, gJiminyEnemyCardCardSoldierLine3French,
    gJiminyEnemyCardCardSoldierLine4French,
};

const JiminyTextChar* gJiminyEnemyCardCardSoldierLinesGerman[5] = {
    gJiminyEnemyCardCardSoldierLine0German, gJiminyEnemyCardCardSoldierLine1German, gJiminyEnemyCardCardSoldierLine2German, gJiminyEnemyCardCardSoldierLine3German,
    gJiminyEnemyCardCardSoldierLine4German,
};

const JiminyTextChar* gJiminyEnemyCardCardSoldierLinesItalian[5] = {
    gJiminyEnemyCardCardSoldierLine0Italian, gJiminyEnemyCardCardSoldierLine1Italian, gJiminyEnemyCardCardSoldierLine2Italian, gJiminyEnemyCardCardSoldierLine3Italian,
    gJiminyEnemyCardCardSoldierLine4Italian,
};

const JiminyTextChar* gJiminyEnemyCardCardSoldierLinesSpanish[7] = {
    gJiminyEnemyCardCardSoldierLine0Spanish, gJiminyEnemyCardCardSoldierLine1Spanish, gJiminyEnemyCardCardSoldierLine2Spanish, gJiminyEnemyCardCardSoldierLine3Spanish,
    gJiminyEnemyCardCardSoldierLine4Spanish, gJiminyEnemyCardCardSoldierLine5Spanish, gJiminyEnemyCardCardSoldierLine6Spanish,
};

const JiminyTextChar* gJiminyEnemyCardHadesLines[9] = {
    gJiminyEnemyCardHadesLine0, gJiminyEnemyCardHadesLine1, gJiminyEnemyCardHadesLine2, gJiminyEnemyCardHadesLine3,
    gJiminyEnemyCardHadesLine4, gJiminyEnemyCardHadesLine5, gJiminyEnemyCardHadesLine6, gJiminyEnemyCardHadesLine7,
    gJiminyEnemyCardHadesLine8,
};

const JiminyTextChar* gJiminyEnemyCardHadesLinesFrench[8] = {
    gJiminyEnemyCardHadesLine0French, gJiminyEnemyCardHadesLine1French, gJiminyEnemyCardHadesLine2French, gJiminyEnemyCardHadesLine3French,
    gJiminyEnemyCardHadesLine4French, gJiminyEnemyCardHadesLine5French, gJiminyEnemyCardHadesLine6French, gJiminyEnemyCardHadesLine7French,
};

const JiminyTextChar* gJiminyEnemyCardHadesLinesGerman[12] = {
    gJiminyEnemyCardHadesLine0German, gJiminyEnemyCardHadesLine1German, gJiminyEnemyCardHadesLine2German, gJiminyEnemyCardHadesLine3German,
    gJiminyEnemyCardHadesLine4German, gJiminyEnemyCardHadesLine5German, gJiminyEnemyCardHadesLine6German, gJiminyEnemyCardHadesLine7German,
    gJiminyEnemyCardHadesLine8German, gJiminyEnemyCardHadesLine9German, gJiminyEnemyCardHadesLine10German, gJiminyEnemyCardHadesLine11German,
};

const JiminyTextChar* gJiminyEnemyCardHadesLinesItalian[11] = {
    gJiminyEnemyCardHadesLine0Italian, gJiminyEnemyCardHadesLine1Italian, gJiminyEnemyCardHadesLine2Italian, gJiminyEnemyCardHadesLine3Italian,
    gJiminyEnemyCardHadesLine4Italian, gJiminyEnemyCardHadesLine5Italian, gJiminyEnemyCardHadesLine6Italian, gJiminyEnemyCardHadesLine7Italian,
    gJiminyEnemyCardHadesLine8Italian, gJiminyEnemyCardHadesLine9Italian, gJiminyEnemyCardHadesLine10Italian,
};

const JiminyTextChar* gJiminyEnemyCardHadesLinesSpanish[10] = {
    gJiminyEnemyCardHadesLine0Spanish, gJiminyEnemyCardHadesLine1Spanish, gJiminyEnemyCardHadesLine2Spanish, gJiminyEnemyCardHadesLine3Spanish,
    gJiminyEnemyCardHadesLine4Spanish, gJiminyEnemyCardHadesLine5Spanish, gJiminyEnemyCardHadesLine6Spanish, gJiminyEnemyCardHadesLine7Spanish,
    gJiminyEnemyCardHadesLine8Spanish, gJiminyEnemyCardHadesLine9Spanish,
};

const JiminyTextChar* gJiminyEnemyCardTrickmasterLines[8] = {
    gJiminyEnemyCardTrickmasterLine0, gJiminyEnemyCardTrickmasterLine1, gJiminyEnemyCardTrickmasterLine2, gJiminyEnemyCardTrickmasterLine3,
    gJiminyEnemyCardTrickmasterLine4, gJiminyEnemyCardTrickmasterLine5, gJiminyEnemyCardTrickmasterLine6, gJiminyEnemyCardTrickmasterLine7,
};

const JiminyTextChar* gJiminyEnemyCardTrickmasterLinesFrench[8] = {
    gJiminyEnemyCardTrickmasterLine0French, gJiminyEnemyCardTrickmasterLine1French, gJiminyEnemyCardTrickmasterLine2French, gJiminyEnemyCardTrickmasterLine3French,
    gJiminyEnemyCardTrickmasterLine4French, gJiminyEnemyCardTrickmasterLine5French, gJiminyEnemyCardTrickmasterLine6French, gJiminyEnemyCardTrickmasterLine7French,
};

const JiminyTextChar* gJiminyEnemyCardTrickmasterLinesGerman[10] = {
    gJiminyEnemyCardTrickmasterLine0German, gJiminyEnemyCardTrickmasterLine1German, gJiminyEnemyCardTrickmasterLine2German, gJiminyEnemyCardTrickmasterLine3German,
    gJiminyEnemyCardTrickmasterLine4German, gJiminyEnemyCardTrickmasterLine5German, gJiminyEnemyCardTrickmasterLine6German, gJiminyEnemyCardTrickmasterLine7German,
    gJiminyEnemyCardTrickmasterLine8German, gJiminyEnemyCardTrickmasterLine9German,
};

const JiminyTextChar* gJiminyEnemyCardTrickmasterLinesItalian[8] = {
    gJiminyEnemyCardTrickmasterLine0Italian, gJiminyEnemyCardTrickmasterLine1Italian, gJiminyEnemyCardTrickmasterLine2Italian, gJiminyEnemyCardTrickmasterLine3Italian,
    gJiminyEnemyCardTrickmasterLine4Italian, gJiminyEnemyCardTrickmasterLine5Italian, gJiminyEnemyCardTrickmasterLine6Italian, gJiminyEnemyCardTrickmasterLine7Italian,
};

const JiminyTextChar* gJiminyEnemyCardTrickmasterLinesSpanish[8] = {
    gJiminyEnemyCardTrickmasterLine0Spanish, gJiminyEnemyCardTrickmasterLine1Spanish, gJiminyEnemyCardTrickmasterLine2Spanish, gJiminyEnemyCardTrickmasterLine3Spanish,
    gJiminyEnemyCardTrickmasterLine4Spanish, gJiminyEnemyCardTrickmasterLine5Spanish, gJiminyEnemyCardTrickmasterLine6Spanish, gJiminyEnemyCardTrickmasterLine7Spanish,
};

const JiminyTextChar* gJiminyEnemyCardJafarLines[6] = {
    gJiminyEnemyCardJafarLine0, gJiminyEnemyCardJafarLine1, gJiminyEnemyCardJafarLine2, gJiminyEnemyCardJafarLine3,
    gJiminyEnemyCardJafarLine4, gJiminyEnemyCardJafarLine5,
};

const JiminyTextChar* gJiminyEnemyCardJafarLinesFrench[6] = {
    gJiminyEnemyCardJafarLine0French, gJiminyEnemyCardJafarLine1French, gJiminyEnemyCardJafarLine2French, gJiminyEnemyCardJafarLine3French,
    gJiminyEnemyCardJafarLine4French, gJiminyEnemyCardJafarLine5French,
};

const JiminyTextChar* gJiminyEnemyCardJafarLinesGerman[7] = {
    gJiminyEnemyCardJafarLine0German, gJiminyEnemyCardJafarLine1German, gJiminyEnemyCardJafarLine2German, gJiminyEnemyCardJafarLine3German,
    gJiminyEnemyCardJafarLine4German, gJiminyEnemyCardJafarLine5German, gJiminyEnemyCardJafarLine6German,
};

const JiminyTextChar* gJiminyEnemyCardJafarLinesItalian[6] = {
    gJiminyEnemyCardJafarLine0Italian, gJiminyEnemyCardJafarLine1Italian, gJiminyEnemyCardJafarLine2Italian, gJiminyEnemyCardJafarLine3Italian,
    gJiminyEnemyCardJafarLine4Italian, gJiminyEnemyCardJafarLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardJafarLinesSpanish[6] = {
    gJiminyEnemyCardJafarLine0Spanish, gJiminyEnemyCardJafarLine1Spanish, gJiminyEnemyCardJafarLine2Spanish, gJiminyEnemyCardJafarLine3Spanish,
    gJiminyEnemyCardJafarLine4Spanish, gJiminyEnemyCardJafarLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardUrsulaLines[7] = {
    gJiminyEnemyCardUrsulaLine0, gJiminyEnemyCardUrsulaLine1, gJiminyEnemyCardUrsulaLine2, gJiminyEnemyCardUrsulaLine3,
    gJiminyEnemyCardUrsulaLine4, gJiminyEnemyCardUrsulaLine5, gJiminyEnemyCardUrsulaLine6,
};

const JiminyTextChar* gJiminyEnemyCardUrsulaLinesFrench[8] = {
    gJiminyEnemyCardUrsulaLine0French, gJiminyEnemyCardUrsulaLine1French, gJiminyEnemyCardUrsulaLine2French, gJiminyEnemyCardUrsulaLine3French,
    gJiminyEnemyCardUrsulaLine4French, gJiminyEnemyCardUrsulaLine5French, gJiminyEnemyCardUrsulaLine6French, gJiminyEnemyCardUrsulaLine7French,
};

const JiminyTextChar* gJiminyEnemyCardUrsulaLinesGerman[10] = {
    gJiminyEnemyCardUrsulaLine0German, gJiminyEnemyCardUrsulaLine1German, gJiminyEnemyCardUrsulaLine2German, gJiminyEnemyCardUrsulaLine3German,
    gJiminyEnemyCardUrsulaLine4German, gJiminyEnemyCardUrsulaLine5German, gJiminyEnemyCardUrsulaLine6German, gJiminyEnemyCardUrsulaLine7German,
    gJiminyEnemyCardUrsulaLine8German, gJiminyEnemyCardUrsulaLine9German,
};

const JiminyTextChar* gJiminyEnemyCardUrsulaLinesItalian[7] = {
    gJiminyEnemyCardUrsulaLine0Italian, gJiminyEnemyCardUrsulaLine1Italian, gJiminyEnemyCardUrsulaLine2Italian, gJiminyEnemyCardUrsulaLine3Italian,
    gJiminyEnemyCardUrsulaLine4Italian, gJiminyEnemyCardUrsulaLine5Italian, gJiminyEnemyCardUrsulaLine6Italian,
};

const JiminyTextChar* gJiminyEnemyCardUrsulaLinesSpanish[8] = {
    gJiminyEnemyCardUrsulaLine0Spanish, gJiminyEnemyCardUrsulaLine1Spanish, gJiminyEnemyCardUrsulaLine2Spanish, gJiminyEnemyCardUrsulaLine3Spanish,
    gJiminyEnemyCardUrsulaLine4Spanish, gJiminyEnemyCardUrsulaLine5Spanish, gJiminyEnemyCardUrsulaLine6Spanish, gJiminyEnemyCardUrsulaLine7Spanish,
};

const JiminyTextChar* gJiminyEnemyCardOogieBoogieLines[6] = {
    gJiminyEnemyCardOogieBoogieLine0, gJiminyEnemyCardOogieBoogieLine1, gJiminyEnemyCardOogieBoogieLine2, gJiminyEnemyCardOogieBoogieLine3,
    gJiminyEnemyCardOogieBoogieLine4, gJiminyEnemyCardOogieBoogieLine5,
};

const JiminyTextChar* gJiminyEnemyCardOogieBoogieLinesFrench[6] = {
    gJiminyEnemyCardOogieBoogieLine0French, gJiminyEnemyCardOogieBoogieLine1French, gJiminyEnemyCardOogieBoogieLine2French, gJiminyEnemyCardOogieBoogieLine3French,
    gJiminyEnemyCardOogieBoogieLine4French, gJiminyEnemyCardOogieBoogieLine5French,
};

const JiminyTextChar* gJiminyEnemyCardOogieBoogieLinesGerman[7] = {
    gJiminyEnemyCardOogieBoogieLine0German, gJiminyEnemyCardOogieBoogieLine1German, gJiminyEnemyCardOogieBoogieLine2German, gJiminyEnemyCardOogieBoogieLine3German,
    gJiminyEnemyCardOogieBoogieLine4German, gJiminyEnemyCardOogieBoogieLine5German, gJiminyEnemyCardOogieBoogieLine6German,
};

const JiminyTextChar* gJiminyEnemyCardOogieBoogieLinesItalian[8] = {
    gJiminyEnemyCardOogieBoogieLine0Italian, gJiminyEnemyCardOogieBoogieLine1Italian, gJiminyEnemyCardOogieBoogieLine2Italian, gJiminyEnemyCardOogieBoogieLine3Italian,
    gJiminyEnemyCardOogieBoogieLine4Italian, gJiminyEnemyCardOogieBoogieLine5Italian, gJiminyEnemyCardOogieBoogieLine6Italian, gJiminyEnemyCardOogieBoogieLine7Italian,
};

const JiminyTextChar* gJiminyEnemyCardOogieBoogieLinesSpanish[7] = {
    gJiminyEnemyCardOogieBoogieLine0Spanish, gJiminyEnemyCardOogieBoogieLine1Spanish, gJiminyEnemyCardOogieBoogieLine2Spanish, gJiminyEnemyCardOogieBoogieLine3Spanish,
    gJiminyEnemyCardOogieBoogieLine4Spanish, gJiminyEnemyCardOogieBoogieLine5Spanish, gJiminyEnemyCardOogieBoogieLine6Spanish,
};

const JiminyTextChar* gJiminyEnemyCardParasiteCageLines[6] = {
    gJiminyEnemyCardParasiteCageLine0, gJiminyEnemyCardParasiteCageLine1, gJiminyEnemyCardParasiteCageLine2, gJiminyEnemyCardParasiteCageLine3,
    gJiminyEnemyCardParasiteCageLine4, gJiminyEnemyCardParasiteCageLine5,
};

const JiminyTextChar* gJiminyEnemyCardParasiteCageLinesFrench[6] = {
    gJiminyEnemyCardParasiteCageLine0French, gJiminyEnemyCardParasiteCageLine1French, gJiminyEnemyCardParasiteCageLine2French, gJiminyEnemyCardParasiteCageLine3French,
    gJiminyEnemyCardParasiteCageLine4French, gJiminyEnemyCardParasiteCageLine5French,
};

const JiminyTextChar* gJiminyEnemyCardParasiteCageLinesGerman[9] = {
    gJiminyEnemyCardParasiteCageLine0German, gJiminyEnemyCardParasiteCageLine1German, gJiminyEnemyCardParasiteCageLine2German, gJiminyEnemyCardParasiteCageLine3German,
    gJiminyEnemyCardParasiteCageLine4German, gJiminyEnemyCardParasiteCageLine5German, gJiminyEnemyCardParasiteCageLine6German, gJiminyEnemyCardParasiteCageLine7German,
    gJiminyEnemyCardParasiteCageLine8German,
};

const JiminyTextChar* gJiminyEnemyCardParasiteCageLinesItalian[6] = {
    gJiminyEnemyCardParasiteCageLine0Italian, gJiminyEnemyCardParasiteCageLine1Italian, gJiminyEnemyCardParasiteCageLine2Italian, gJiminyEnemyCardParasiteCageLine3Italian,
    gJiminyEnemyCardParasiteCageLine4Italian, gJiminyEnemyCardParasiteCageLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardParasiteCageLinesSpanish[6] = {
    gJiminyEnemyCardParasiteCageLine0Spanish, gJiminyEnemyCardParasiteCageLine1Spanish, gJiminyEnemyCardParasiteCageLine2Spanish, gJiminyEnemyCardParasiteCageLine3Spanish,
    gJiminyEnemyCardParasiteCageLine4Spanish, gJiminyEnemyCardParasiteCageLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardHookLines[8] = {
    gJiminyEnemyCardHookLine0, gJiminyEnemyCardHookLine1, gJiminyEnemyCardHookLine2, gJiminyEnemyCardHookLine3,
    gJiminyEnemyCardHookLine4, gJiminyEnemyCardHookLine5, gJiminyEnemyCardHookLine6, gJiminyEnemyCardHookLine7,
};

const JiminyTextChar* gJiminyEnemyCardHookLinesFrench[9] = {
    gJiminyEnemyCardHookLine0French, gJiminyEnemyCardHookLine1French, gJiminyEnemyCardHookLine2French, gJiminyEnemyCardHookLine3French,
    gJiminyEnemyCardHookLine4French, gJiminyEnemyCardHookLine5French, gJiminyEnemyCardHookLine6French, gJiminyEnemyCardHookLine7French,
    gJiminyEnemyCardHookLine8French,
};

const JiminyTextChar* gJiminyEnemyCardHookLinesGerman[10] = {
    gJiminyEnemyCardHookLine0German, gJiminyEnemyCardHookLine1German, gJiminyEnemyCardHookLine2German, gJiminyEnemyCardHookLine3German,
    gJiminyEnemyCardHookLine4German, gJiminyEnemyCardHookLine5German, gJiminyEnemyCardHookLine6German, gJiminyEnemyCardHookLine7German,
    gJiminyEnemyCardHookLine8German, gJiminyEnemyCardHookLine9German,
};

const JiminyTextChar* gJiminyEnemyCardHookLinesItalian[10] = {
    gJiminyEnemyCardHookLine0Italian, gJiminyEnemyCardHookLine1Italian, gJiminyEnemyCardHookLine2Italian, gJiminyEnemyCardHookLine3Italian,
    gJiminyEnemyCardHookLine4Italian, gJiminyEnemyCardHookLine5Italian, gJiminyEnemyCardHookLine6Italian, gJiminyEnemyCardHookLine7Italian,
    gJiminyEnemyCardHookLine8Italian, gJiminyEnemyCardHookLine9Italian,
};

const JiminyTextChar* gJiminyEnemyCardHookLinesSpanish[8] = {
    gJiminyEnemyCardHookLine0Spanish, gJiminyEnemyCardHookLine1Spanish, gJiminyEnemyCardHookLine2Spanish, gJiminyEnemyCardHookLine3Spanish,
    gJiminyEnemyCardHookLine4Spanish, gJiminyEnemyCardHookLine5Spanish, gJiminyEnemyCardHookLine6Spanish, gJiminyEnemyCardHookLine7Spanish,
};

const JiminyTextChar* gJiminyEnemyCardDragonMaleficentLines[6] = {
    gJiminyEnemyCardDragonMaleficentLine0, gJiminyEnemyCardDragonMaleficentLine1, gJiminyEnemyCardDragonMaleficentLine2, gJiminyEnemyCardDragonMaleficentLine3,
    gJiminyEnemyCardDragonMaleficentLine4, gJiminyEnemyCardDragonMaleficentLine5,
};

const JiminyTextChar* gJiminyEnemyCardDragonMaleficentLinesFrench[6] = {
    gJiminyEnemyCardDragonMaleficentLine0French, gJiminyEnemyCardDragonMaleficentLine1French, gJiminyEnemyCardDragonMaleficentLine2French, gJiminyEnemyCardDragonMaleficentLine3French,
    gJiminyEnemyCardDragonMaleficentLine4French, gJiminyEnemyCardDragonMaleficentLine5French,
};

const JiminyTextChar* gJiminyEnemyCardDragonMaleficentLinesGerman[7] = {
    gJiminyEnemyCardDragonMaleficentLine0German, gJiminyEnemyCardDragonMaleficentLine1German, gJiminyEnemyCardDragonMaleficentLine2German, gJiminyEnemyCardDragonMaleficentLine3German,
    gJiminyEnemyCardDragonMaleficentLine4German, gJiminyEnemyCardDragonMaleficentLine5German, gJiminyEnemyCardDragonMaleficentLine6German,
};

const JiminyTextChar* gJiminyEnemyCardDragonMaleficentLinesItalian[7] = {
    gJiminyEnemyCardDragonMaleficentLine0Italian, gJiminyEnemyCardDragonMaleficentLine1Italian, gJiminyEnemyCardDragonMaleficentLine2Italian, gJiminyEnemyCardDragonMaleficentLine3Italian,
    gJiminyEnemyCardDragonMaleficentLine4Italian, gJiminyEnemyCardDragonMaleficentLine5Italian, gJiminyEnemyCardDragonMaleficentLine6Italian,
};

const JiminyTextChar* gJiminyEnemyCardDragonMaleficentLinesSpanish[6] = {
    gJiminyEnemyCardDragonMaleficentLine0Spanish, gJiminyEnemyCardDragonMaleficentLine1Spanish, gJiminyEnemyCardDragonMaleficentLine2Spanish, gJiminyEnemyCardDragonMaleficentLine3Spanish,
    gJiminyEnemyCardDragonMaleficentLine4Spanish, gJiminyEnemyCardDragonMaleficentLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardDarksideLines[6] = {
    gJiminyEnemyCardDarksideLine0, gJiminyEnemyCardDarksideLine1, gJiminyEnemyCardDarksideLine2, gJiminyEnemyCardDarksideLine3,
    gJiminyEnemyCardDarksideLine4, gJiminyEnemyCardDarksideLine5,
};

const JiminyTextChar* gJiminyEnemyCardDarksideLinesFrench[6] = {
    gJiminyEnemyCardDarksideLine0French, gJiminyEnemyCardDarksideLine1French, gJiminyEnemyCardDarksideLine2French, gJiminyEnemyCardDarksideLine3French,
    gJiminyEnemyCardDarksideLine4French, gJiminyEnemyCardDarksideLine5French,
};

const JiminyTextChar* gJiminyEnemyCardDarksideLinesGerman[9] = {
    gJiminyEnemyCardDarksideLine0German, gJiminyEnemyCardDarksideLine1German, gJiminyEnemyCardDarksideLine2German, gJiminyEnemyCardDarksideLine3German,
    gJiminyEnemyCardDarksideLine4German, gJiminyEnemyCardDarksideLine5German, gJiminyEnemyCardDarksideLine6German, gJiminyEnemyCardDarksideLine7German,
    gJiminyEnemyCardDarksideLine8German,
};

const JiminyTextChar* gJiminyEnemyCardDarksideLinesItalian[6] = {
    gJiminyEnemyCardDarksideLine0Italian, gJiminyEnemyCardDarksideLine1Italian, gJiminyEnemyCardDarksideLine2Italian, gJiminyEnemyCardDarksideLine3Italian,
    gJiminyEnemyCardDarksideLine4Italian, gJiminyEnemyCardDarksideLine5Italian,
};

const JiminyTextChar* gJiminyEnemyCardDarksideLinesSpanish[6] = {
    gJiminyEnemyCardDarksideLine0Spanish, gJiminyEnemyCardDarksideLine1Spanish, gJiminyEnemyCardDarksideLine2Spanish, gJiminyEnemyCardDarksideLine3Spanish,
    gJiminyEnemyCardDarksideLine4Spanish, gJiminyEnemyCardDarksideLine5Spanish,
};

const JiminyTextChar* gJiminyEnemyCardLarxeneLines[7] = {
    gJiminyEnemyCardLarxeneLine0, gJiminyEnemyCardLarxeneLine1, gJiminyEnemyCardLarxeneLine2, gJiminyEnemyCardLarxeneLine3,
    gJiminyEnemyCardLarxeneLine4, gJiminyEnemyCardLarxeneLine5, gJiminyEnemyCardLarxeneLine6,
};

const JiminyTextChar* gJiminyEnemyCardLarxeneLinesFrench[9] = {
    gJiminyEnemyCardLarxeneLine0French, gJiminyEnemyCardLarxeneLine1French, gJiminyEnemyCardLarxeneLine2French, gJiminyEnemyCardLarxeneLine3French,
    gJiminyEnemyCardLarxeneLine4French, gJiminyEnemyCardLarxeneLine5French, gJiminyEnemyCardLarxeneLine6French, gJiminyEnemyCardLarxeneLine7French,
    gJiminyEnemyCardLarxeneLine8French,
};

const JiminyTextChar* gJiminyEnemyCardLarxeneLinesGerman[8] = {
    gJiminyEnemyCardLarxeneLine0German, gJiminyEnemyCardLarxeneLine1German, gJiminyEnemyCardLarxeneLine2German, gJiminyEnemyCardLarxeneLine3German,
    gJiminyEnemyCardLarxeneLine4German, gJiminyEnemyCardLarxeneLine5German, gJiminyEnemyCardLarxeneLine6German, gJiminyEnemyCardLarxeneLine7German,
};

const JiminyTextChar* gJiminyEnemyCardLarxeneLinesItalian[7] = {
    gJiminyEnemyCardLarxeneLine0Italian, gJiminyEnemyCardLarxeneLine1Italian, gJiminyEnemyCardLarxeneLine2Italian, gJiminyEnemyCardLarxeneLine3Italian,
    gJiminyEnemyCardLarxeneLine4Italian, gJiminyEnemyCardLarxeneLine5Italian, gJiminyEnemyCardLarxeneLine6Italian,
};

const JiminyTextChar* gJiminyEnemyCardLarxeneLinesSpanish[8] = {
    gJiminyEnemyCardLarxeneLine0Spanish, gJiminyEnemyCardLarxeneLine1Spanish, gJiminyEnemyCardLarxeneLine2Spanish, gJiminyEnemyCardLarxeneLine3Spanish,
    gJiminyEnemyCardLarxeneLine4Spanish, gJiminyEnemyCardLarxeneLine5Spanish, gJiminyEnemyCardLarxeneLine6Spanish, gJiminyEnemyCardLarxeneLine7Spanish,
};

const JiminyTextChar* gJiminyEnemyCardRikuLines[8] = {
    gJiminyEnemyCardRikuLine0, gJiminyEnemyCardRikuLine1, gJiminyEnemyCardRikuLine2, gJiminyEnemyCardRikuLine3,
    gJiminyEnemyCardRikuLine4, gJiminyEnemyCardRikuLine5, gJiminyEnemyCardRikuLine6, gJiminyEnemyCardRikuLine7,
};

const JiminyTextChar* gJiminyEnemyCardRikuLinesFrench[8] = {
    gJiminyEnemyCardRikuLine0French, gJiminyEnemyCardRikuLine1French, gJiminyEnemyCardRikuLine2French, gJiminyEnemyCardRikuLine3French,
    gJiminyEnemyCardRikuLine4French, gJiminyEnemyCardRikuLine5French, gJiminyEnemyCardRikuLine6French, gJiminyEnemyCardRikuLine7French,
};

const JiminyTextChar* gJiminyEnemyCardRikuLinesGerman[9] = {
    gJiminyEnemyCardRikuLine0German, gJiminyEnemyCardRikuLine1German, gJiminyEnemyCardRikuLine2German, gJiminyEnemyCardRikuLine3German,
    gJiminyEnemyCardRikuLine4German, gJiminyEnemyCardRikuLine5German, gJiminyEnemyCardRikuLine6German, gJiminyEnemyCardRikuLine7German,
    gJiminyEnemyCardRikuLine8German,
};

const JiminyTextChar* gJiminyEnemyCardRikuLinesItalian[8] = {
    gJiminyEnemyCardRikuLine0Italian, gJiminyEnemyCardRikuLine1Italian, gJiminyEnemyCardRikuLine2Italian, gJiminyEnemyCardRikuLine3Italian,
    gJiminyEnemyCardRikuLine4Italian, gJiminyEnemyCardRikuLine5Italian, gJiminyEnemyCardRikuLine6Italian, gJiminyEnemyCardRikuLine7Italian,
};

const JiminyTextChar* gJiminyEnemyCardRikuLinesSpanish[9] = {
    gJiminyEnemyCardRikuLine0Spanish, gJiminyEnemyCardRikuLine1Spanish, gJiminyEnemyCardRikuLine2Spanish, gJiminyEnemyCardRikuLine3Spanish,
    gJiminyEnemyCardRikuLine4Spanish, gJiminyEnemyCardRikuLine5Spanish, gJiminyEnemyCardRikuLine6Spanish, gJiminyEnemyCardRikuLine7Spanish,
    gJiminyEnemyCardRikuLine8Spanish,
};

const JiminyTextChar* gJiminyEnemyCardAxelLines[7] = {
    gJiminyEnemyCardAxelLine0, gJiminyEnemyCardAxelLine1, gJiminyEnemyCardAxelLine2, gJiminyEnemyCardAxelLine3,
    gJiminyEnemyCardAxelLine4, gJiminyEnemyCardAxelLine5, gJiminyEnemyCardAxelLine6,
};

const JiminyTextChar* gJiminyEnemyCardAxelLinesFrench[9] = {
    gJiminyEnemyCardAxelLine0French, gJiminyEnemyCardAxelLine1French, gJiminyEnemyCardAxelLine2French, gJiminyEnemyCardAxelLine3French,
    gJiminyEnemyCardAxelLine4French, gJiminyEnemyCardAxelLine5French, gJiminyEnemyCardAxelLine6French, gJiminyEnemyCardAxelLine7French,
    gJiminyEnemyCardAxelLine8French,
};

const JiminyTextChar* gJiminyEnemyCardAxelLinesGerman[9] = {
    gJiminyEnemyCardAxelLine0German, gJiminyEnemyCardAxelLine1German, gJiminyEnemyCardAxelLine2German, gJiminyEnemyCardAxelLine3German,
    gJiminyEnemyCardAxelLine4German, gJiminyEnemyCardAxelLine5German, gJiminyEnemyCardAxelLine6German, gJiminyEnemyCardAxelLine7German,
    gJiminyEnemyCardAxelLine8German,
};

const JiminyTextChar* gJiminyEnemyCardAxelLinesItalian[9] = {
    gJiminyEnemyCardAxelLine0Italian, gJiminyEnemyCardAxelLine1Italian, gJiminyEnemyCardAxelLine2Italian, gJiminyEnemyCardAxelLine3Italian,
    gJiminyEnemyCardAxelLine4Italian, gJiminyEnemyCardAxelLine5Italian, gJiminyEnemyCardAxelLine6Italian, gJiminyEnemyCardAxelLine7Italian,
    gJiminyEnemyCardAxelLine8Italian,
};

const JiminyTextChar* gJiminyEnemyCardAxelLinesSpanish[8] = {
    gJiminyEnemyCardAxelLine0Spanish, gJiminyEnemyCardAxelLine1Spanish, gJiminyEnemyCardAxelLine2Spanish, gJiminyEnemyCardAxelLine3Spanish,
    gJiminyEnemyCardAxelLine4Spanish, gJiminyEnemyCardAxelLine5Spanish, gJiminyEnemyCardAxelLine6Spanish, gJiminyEnemyCardAxelLine7Spanish,
};

const JiminyTextChar* gJiminyEnemyCardVexenLines[9] = {
    gJiminyEnemyCardVexenLine0, gJiminyEnemyCardVexenLine1, gJiminyEnemyCardVexenLine2, gJiminyEnemyCardVexenLine3,
    gJiminyEnemyCardVexenLine4, gJiminyEnemyCardVexenLine5, gJiminyEnemyCardVexenLine6, gJiminyEnemyCardVexenLine7,
    gJiminyEnemyCardVexenLine8,
};

const JiminyTextChar* gJiminyEnemyCardVexenLinesFrench[9] = {
    gJiminyEnemyCardVexenLine0French, gJiminyEnemyCardVexenLine1French, gJiminyEnemyCardVexenLine2French, gJiminyEnemyCardVexenLine3French,
    gJiminyEnemyCardVexenLine4French, gJiminyEnemyCardVexenLine5French, gJiminyEnemyCardVexenLine6French, gJiminyEnemyCardVexenLine7French,
    gJiminyEnemyCardVexenLine8French,
};

const JiminyTextChar* gJiminyEnemyCardVexenLinesGerman[11] = {
    gJiminyEnemyCardVexenLine0German, gJiminyEnemyCardVexenLine1German, gJiminyEnemyCardVexenLine2German, gJiminyEnemyCardVexenLine3German,
    gJiminyEnemyCardVexenLine4German, gJiminyEnemyCardVexenLine5German, gJiminyEnemyCardVexenLine6German, gJiminyEnemyCardVexenLine7German,
    gJiminyEnemyCardVexenLine8German, gJiminyEnemyCardVexenLine9German, gJiminyEnemyCardVexenLine10German,
};

const JiminyTextChar* gJiminyEnemyCardVexenLinesItalian[10] = {
    gJiminyEnemyCardVexenLine0Italian, gJiminyEnemyCardVexenLine1Italian, gJiminyEnemyCardVexenLine2Italian, gJiminyEnemyCardVexenLine3Italian,
    gJiminyEnemyCardVexenLine4Italian, gJiminyEnemyCardVexenLine5Italian, gJiminyEnemyCardVexenLine6Italian, gJiminyEnemyCardVexenLine7Italian,
    gJiminyEnemyCardVexenLine8Italian, gJiminyEnemyCardVexenLine9Italian,
};

const JiminyTextChar* gJiminyEnemyCardVexenLinesSpanish[10] = {
    gJiminyEnemyCardVexenLine0Spanish, gJiminyEnemyCardVexenLine1Spanish, gJiminyEnemyCardVexenLine2Spanish, gJiminyEnemyCardVexenLine3Spanish,
    gJiminyEnemyCardVexenLine4Spanish, gJiminyEnemyCardVexenLine5Spanish, gJiminyEnemyCardVexenLine6Spanish, gJiminyEnemyCardVexenLine7Spanish,
    gJiminyEnemyCardVexenLine8Spanish, gJiminyEnemyCardVexenLine9Spanish,
};

const JiminyTextChar* gJiminyEnemyCardLexaeusLines[14] = {
    gJiminyEnemyCardLexaeusLine0, gJiminyEnemyCardLexaeusLine1, gJiminyEnemyCardLexaeusLine2, gJiminyEnemyCardLexaeusLine3,
    gJiminyEnemyCardLexaeusLine4, gJiminyEnemyCardLexaeusLine5, gJiminyEnemyCardLexaeusLine6, gJiminyEnemyCardLexaeusLine7,
    gJiminyEnemyCardLexaeusLine8, gJiminyEnemyCardLexaeusLine9, gJiminyEnemyCardLexaeusLine10, gJiminyEnemyCardLexaeusLine11,
    gJiminyEnemyCardLexaeusLine12, gJiminyEnemyCardLexaeusLine13,
};

const JiminyTextChar* gJiminyEnemyCardLexaeusLinesFrench[13] = {
    gJiminyEnemyCardLexaeusLine0French, gJiminyEnemyCardLexaeusLine1French, gJiminyEnemyCardLexaeusLine2French, gJiminyEnemyCardLexaeusLine3French,
    gJiminyEnemyCardLexaeusLine4French, gJiminyEnemyCardLexaeusLine5French, gJiminyEnemyCardLexaeusLine6French, gJiminyEnemyCardLexaeusLine7French,
    gJiminyEnemyCardLexaeusLine8French, gJiminyEnemyCardLexaeusLine9French, gJiminyEnemyCardLexaeusLine10French, gJiminyEnemyCardLexaeusLine11French,
    gJiminyEnemyCardLexaeusLine12French,
};

const JiminyTextChar* gJiminyEnemyCardLexaeusLinesGerman[16] = {
    gJiminyEnemyCardLexaeusLine0German, gJiminyEnemyCardLexaeusLine1German, gJiminyEnemyCardLexaeusLine2German, gJiminyEnemyCardLexaeusLine3German,
    gJiminyEnemyCardLexaeusLine4German, gJiminyEnemyCardLexaeusLine5German, gJiminyEnemyCardLexaeusLine6German, gJiminyEnemyCardLexaeusLine7German,
    gJiminyEnemyCardLexaeusLine8German, gJiminyEnemyCardLexaeusLine9German, gJiminyEnemyCardLexaeusLine10German, gJiminyEnemyCardLexaeusLine11German,
    gJiminyEnemyCardLexaeusLine12German, gJiminyEnemyCardLexaeusLine13German, gJiminyEnemyCardLexaeusLine14German, gJiminyEnemyCardLexaeusLine15German,
};

const JiminyTextChar* gJiminyEnemyCardLexaeusLinesItalian[14] = {
    gJiminyEnemyCardLexaeusLine0Italian, gJiminyEnemyCardLexaeusLine1Italian, gJiminyEnemyCardLexaeusLine2Italian, gJiminyEnemyCardLexaeusLine3Italian,
    gJiminyEnemyCardLexaeusLine4Italian, gJiminyEnemyCardLexaeusLine5Italian, gJiminyEnemyCardLexaeusLine6Italian, gJiminyEnemyCardLexaeusLine7Italian,
    gJiminyEnemyCardLexaeusLine8Italian, gJiminyEnemyCardLexaeusLine9Italian, gJiminyEnemyCardLexaeusLine10Italian, gJiminyEnemyCardLexaeusLine11Italian,
    gJiminyEnemyCardLexaeusLine12Italian, gJiminyEnemyCardLexaeusLine13Italian,
};

const JiminyTextChar* gJiminyEnemyCardLexaeusLinesSpanish[15] = {
    gJiminyEnemyCardLexaeusLine0Spanish, gJiminyEnemyCardLexaeusLine1Spanish, gJiminyEnemyCardLexaeusLine2Spanish, gJiminyEnemyCardLexaeusLine3Spanish,
    gJiminyEnemyCardLexaeusLine4Spanish, gJiminyEnemyCardLexaeusLine5Spanish, gJiminyEnemyCardLexaeusLine6Spanish, gJiminyEnemyCardLexaeusLine7Spanish,
    gJiminyEnemyCardLexaeusLine8Spanish, gJiminyEnemyCardLexaeusLine9Spanish, gJiminyEnemyCardLexaeusLine10Spanish, gJiminyEnemyCardLexaeusLine11Spanish,
    gJiminyEnemyCardLexaeusLine12Spanish, gJiminyEnemyCardLexaeusLine13Spanish, gJiminyEnemyCardLexaeusLine14Spanish,
};

const JiminyTextChar* gJiminyEnemyCardAnsemLines[7] = {
    gJiminyEnemyCardAnsemLine0, gJiminyEnemyCardAnsemLine1, gJiminyEnemyCardAnsemLine2, gJiminyEnemyCardAnsemLine3,
    gJiminyEnemyCardAnsemLine4, gJiminyEnemyCardAnsemLine5, gJiminyEnemyCardAnsemLine6,
};

const JiminyTextChar* gJiminyEnemyCardAnsemLinesFrench[7] = {
    gJiminyEnemyCardAnsemLine0French, gJiminyEnemyCardAnsemLine1French, gJiminyEnemyCardAnsemLine2French, gJiminyEnemyCardAnsemLine3French,
    gJiminyEnemyCardAnsemLine4French, gJiminyEnemyCardAnsemLine5French, gJiminyEnemyCardAnsemLine6French,
};

const JiminyTextChar* gJiminyEnemyCardAnsemLinesGerman[10] = {
    gJiminyEnemyCardAnsemLine0German, gJiminyEnemyCardAnsemLine1German, gJiminyEnemyCardAnsemLine2German, gJiminyEnemyCardAnsemLine3German,
    gJiminyEnemyCardAnsemLine4German, gJiminyEnemyCardAnsemLine5German, gJiminyEnemyCardAnsemLine6German, gJiminyEnemyCardAnsemLine7German,
    gJiminyEnemyCardAnsemLine8German, gJiminyEnemyCardAnsemLine9German,
};

const JiminyTextChar* gJiminyEnemyCardAnsemLinesItalian[8] = {
    gJiminyEnemyCardAnsemLine0Italian, gJiminyEnemyCardAnsemLine1Italian, gJiminyEnemyCardAnsemLine2Italian, gJiminyEnemyCardAnsemLine3Italian,
    gJiminyEnemyCardAnsemLine4Italian, gJiminyEnemyCardAnsemLine5Italian, gJiminyEnemyCardAnsemLine6Italian, gJiminyEnemyCardAnsemLine7Italian,
};

const JiminyTextChar* gJiminyEnemyCardAnsemLinesSpanish[8] = {
    gJiminyEnemyCardAnsemLine0Spanish, gJiminyEnemyCardAnsemLine1Spanish, gJiminyEnemyCardAnsemLine2Spanish, gJiminyEnemyCardAnsemLine3Spanish,
    gJiminyEnemyCardAnsemLine4Spanish, gJiminyEnemyCardAnsemLine5Spanish, gJiminyEnemyCardAnsemLine6Spanish, gJiminyEnemyCardAnsemLine7Spanish,
};

const JiminyTextChar* gJiminyEnemyCardMarluxiaLines[13] = {
    gJiminyEnemyCardMarluxiaLine0, gJiminyEnemyCardMarluxiaLine1, gJiminyEnemyCardMarluxiaLine2, gJiminyEnemyCardMarluxiaLine3,
    gJiminyEnemyCardMarluxiaLine4, gJiminyEnemyCardMarluxiaLine5, gJiminyEnemyCardMarluxiaLine6, gJiminyEnemyCardMarluxiaLine7,
    gJiminyEnemyCardMarluxiaLine8, gJiminyEnemyCardMarluxiaLine9, gJiminyEnemyCardMarluxiaLine10, gJiminyEnemyCardMarluxiaLine11,
    gJiminyEnemyCardMarluxiaLine12,
};

const JiminyTextChar* gJiminyEnemyCardMarluxiaLinesFrench[13] = {
    gJiminyEnemyCardMarluxiaLine0French, gJiminyEnemyCardMarluxiaLine1French, gJiminyEnemyCardMarluxiaLine2French, gJiminyEnemyCardMarluxiaLine3French,
    gJiminyEnemyCardMarluxiaLine4French, gJiminyEnemyCardMarluxiaLine5French, gJiminyEnemyCardMarluxiaLine6French, gJiminyEnemyCardMarluxiaLine7French,
    gJiminyEnemyCardMarluxiaLine8French, gJiminyEnemyCardMarluxiaLine9French, gJiminyEnemyCardMarluxiaLine10French, gJiminyEnemyCardMarluxiaLine11French,
    gJiminyEnemyCardMarluxiaLine12French,
};

const JiminyTextChar* gJiminyEnemyCardMarluxiaLinesGerman[17] = {
    gJiminyEnemyCardMarluxiaLine0German, gJiminyEnemyCardMarluxiaLine1German, gJiminyEnemyCardMarluxiaLine2German, gJiminyEnemyCardMarluxiaLine3German,
    gJiminyEnemyCardMarluxiaLine4German, gJiminyEnemyCardMarluxiaLine5German, gJiminyEnemyCardMarluxiaLine6German, gJiminyEnemyCardMarluxiaLine7German,
    gJiminyEnemyCardMarluxiaLine8German, gJiminyEnemyCardMarluxiaLine9German, gJiminyEnemyCardMarluxiaLine10German, gJiminyEnemyCardMarluxiaLine11German,
    gJiminyEnemyCardMarluxiaLine12German, gJiminyEnemyCardMarluxiaLine13German, gJiminyEnemyCardMarluxiaLine14German, gJiminyEnemyCardMarluxiaLine15German,
    gJiminyEnemyCardMarluxiaLine16German,
};

const JiminyTextChar* gJiminyEnemyCardMarluxiaLinesItalian[14] = {
    gJiminyEnemyCardMarluxiaLine0Italian, gJiminyEnemyCardMarluxiaLine1Italian, gJiminyEnemyCardMarluxiaLine2Italian, gJiminyEnemyCardMarluxiaLine3Italian,
    gJiminyEnemyCardMarluxiaLine4Italian, gJiminyEnemyCardMarluxiaLine5Italian, gJiminyEnemyCardMarluxiaLine6Italian, gJiminyEnemyCardMarluxiaLine7Italian,
    gJiminyEnemyCardMarluxiaLine8Italian, gJiminyEnemyCardMarluxiaLine9Italian, gJiminyEnemyCardMarluxiaLine10Italian, gJiminyEnemyCardMarluxiaLine11Italian,
    gJiminyEnemyCardMarluxiaLine12Italian, gJiminyEnemyCardMarluxiaLine13Italian,
};

const JiminyTextChar* gJiminyEnemyCardMarluxiaLinesSpanish[14] = {
    gJiminyEnemyCardMarluxiaLine0Spanish, gJiminyEnemyCardMarluxiaLine1Spanish, gJiminyEnemyCardMarluxiaLine2Spanish, gJiminyEnemyCardMarluxiaLine3Spanish,
    gJiminyEnemyCardMarluxiaLine4Spanish, gJiminyEnemyCardMarluxiaLine5Spanish, gJiminyEnemyCardMarluxiaLine6Spanish, gJiminyEnemyCardMarluxiaLine7Spanish,
    gJiminyEnemyCardMarluxiaLine8Spanish, gJiminyEnemyCardMarluxiaLine9Spanish, gJiminyEnemyCardMarluxiaLine10Spanish, gJiminyEnemyCardMarluxiaLine11Spanish,
    gJiminyEnemyCardMarluxiaLine12Spanish, gJiminyEnemyCardMarluxiaLine13Spanish,
};

const JiminyTextChar* gJiminyRikuCardSoulEaterLines[4] = {
    gJiminyRikuCardSoulEaterLine0, gJiminyRikuCardSoulEaterLine1, gJiminyRikuCardSoulEaterLine2, gJiminyRikuCardSoulEaterLine3,
};

const JiminyTextChar* gJiminyRikuCardSoulEaterLinesFrench[4] = {
    gJiminyRikuCardSoulEaterLine0French, gJiminyRikuCardSoulEaterLine1French, gJiminyRikuCardSoulEaterLine2French, gJiminyRikuCardSoulEaterLine3French,
};

const JiminyTextChar* gJiminyRikuCardSoulEaterLinesGerman[5] = {
    gJiminyRikuCardSoulEaterLine0German, gJiminyRikuCardSoulEaterLine1German, gJiminyRikuCardSoulEaterLine2German, gJiminyRikuCardSoulEaterLine3German,
    gJiminyRikuCardSoulEaterLine4German,
};

const JiminyTextChar* gJiminyRikuCardSoulEaterLinesItalian[5] = {
    gJiminyRikuCardSoulEaterLine0Italian, gJiminyRikuCardSoulEaterLine1Italian, gJiminyRikuCardSoulEaterLine2Italian, gJiminyRikuCardSoulEaterLine3Italian,
    gJiminyRikuCardSoulEaterLine4Italian,
};

const JiminyTextChar* gJiminyRikuCardSoulEaterLinesSpanish[5] = {
    gJiminyRikuCardSoulEaterLine0Spanish, gJiminyRikuCardSoulEaterLine1Spanish, gJiminyRikuCardSoulEaterLine2Spanish, gJiminyRikuCardSoulEaterLine3Spanish,
    gJiminyRikuCardSoulEaterLine4Spanish,
};

const JiminyTextChar* gJiminyRikuCardKingLines[4] = {
    gJiminyRikuCardKingLine0, gJiminyRikuCardKingLine1, gJiminyRikuCardKingLine2, gJiminyRikuCardKingLine3,
};

const JiminyTextChar* gJiminyRikuCardKingLinesFrench[4] = {
    gJiminyRikuCardKingLine0French, gJiminyRikuCardKingLine1French, gJiminyRikuCardKingLine2French, gJiminyRikuCardKingLine3French,
};

const JiminyTextChar* gJiminyRikuCardKingLinesGerman[5] = {
    gJiminyRikuCardKingLine0German, gJiminyRikuCardKingLine1German, gJiminyRikuCardKingLine2German, gJiminyRikuCardKingLine3German,
    gJiminyRikuCardKingLine4German,
};

const JiminyTextChar* gJiminyRikuCardKingLinesItalian[4] = {
    gJiminyRikuCardKingLine0Italian, gJiminyRikuCardKingLine1Italian, gJiminyRikuCardKingLine2Italian, gJiminyRikuCardKingLine3Italian,
};

const JiminyTextChar* gJiminyRikuCardKingLinesSpanish[4] = {
    gJiminyRikuCardKingLine0Spanish, gJiminyRikuCardKingLine1Spanish, gJiminyRikuCardKingLine2Spanish, gJiminyRikuCardKingLine3Spanish,
};

const JiminyTextChar* gJiminyMapCardTeemingDarknessLines[4] = {
    gJiminyMapCardTeemingDarknessLine0, gJiminyMapCardTeemingDarknessLine1, gJiminyMapCardTeemingDarknessLine2, gJiminyMapCardTeemingDarknessLine3,
};

const JiminyTextChar* gJiminyMapCardTeemingDarknessLinesFrench[4] = {
    gJiminyMapCardTeemingDarknessLine0French, gJiminyMapCardTeemingDarknessLine1French, gJiminyMapCardTeemingDarknessLine2French, gJiminyMapCardTeemingDarknessLine3French,
};

const JiminyTextChar* gJiminyMapCardTeemingDarknessLinesGerman[4] = {
    gJiminyMapCardTeemingDarknessLine0German, gJiminyMapCardTeemingDarknessLine1German, gJiminyMapCardTeemingDarknessLine2German, gJiminyMapCardTeemingDarknessLine3German,
};

const JiminyTextChar* gJiminyMapCardTeemingDarknessLinesItalian[6] = {
    gJiminyMapCardTeemingDarknessLine0Italian, gJiminyMapCardTeemingDarknessLine1Italian, gJiminyMapCardTeemingDarknessLine2Italian, gJiminyMapCardTeemingDarknessLine3Italian,
    gJiminyMapCardTeemingDarknessLine4Italian, gJiminyMapCardTeemingDarknessLine5Italian,
};

const JiminyTextChar* gJiminyMapCardTeemingDarknessLinesSpanish[5] = {
    gJiminyMapCardTeemingDarknessLine0Spanish, gJiminyMapCardTeemingDarknessLine1Spanish, gJiminyMapCardTeemingDarknessLine2Spanish, gJiminyMapCardTeemingDarknessLine3Spanish,
    gJiminyMapCardTeemingDarknessLine4Spanish,
};

const JiminyTextChar* gJiminyMapCardTranquilDarknessLines[2] = {
    gJiminyMapCardTranquilDarknessLine0, gJiminyMapCardTranquilDarknessLine1,
};

const JiminyTextChar* gJiminyMapCardTranquilDarknessLinesFrench[2] = {
    gJiminyMapCardTranquilDarknessLine0French, gJiminyMapCardTranquilDarknessLine1French,
};

const JiminyTextChar* gJiminyMapCardTranquilDarknessLinesGerman[3] = {
    gJiminyMapCardTranquilDarknessLine0German, gJiminyMapCardTranquilDarknessLine1German, gJiminyMapCardTranquilDarknessLine2German,
};

const JiminyTextChar* gJiminyMapCardTranquilDarknessLinesItalian[3] = {
    gJiminyMapCardTranquilDarknessLine0Italian, gJiminyMapCardTranquilDarknessLine1Italian, gJiminyMapCardTranquilDarknessLine2Italian,
};

const JiminyTextChar* gJiminyMapCardTranquilDarknessLinesSpanish[3] = {
    gJiminyMapCardTranquilDarknessLine0Spanish, gJiminyMapCardTranquilDarknessLine1Spanish, gJiminyMapCardTranquilDarknessLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardGuardedTroveLines[3] = {
    gJiminyMapCardGuardedTroveLine0, gJiminyMapCardGuardedTroveLine1, gJiminyMapCardGuardedTroveLine2,
};

const JiminyTextChar* gJiminyMapCardGuardedTroveLinesFrench[3] = {
    gJiminyMapCardGuardedTroveLine0French, gJiminyMapCardGuardedTroveLine1French, gJiminyMapCardGuardedTroveLine2French,
};

const JiminyTextChar* gJiminyMapCardGuardedTroveLinesGerman[3] = {
    gJiminyMapCardGuardedTroveLine0German, gJiminyMapCardGuardedTroveLine1German, gJiminyMapCardGuardedTroveLine2German,
};

const JiminyTextChar* gJiminyMapCardGuardedTroveLinesItalian[3] = {
    gJiminyMapCardGuardedTroveLine0Italian, gJiminyMapCardGuardedTroveLine1Italian, gJiminyMapCardGuardedTroveLine2Italian,
};

const JiminyTextChar* gJiminyMapCardGuardedTroveLinesSpanish[3] = {
    gJiminyMapCardGuardedTroveLine0Spanish, gJiminyMapCardGuardedTroveLine1Spanish, gJiminyMapCardGuardedTroveLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardLoomingDarknessLines[5] = {
    gJiminyMapCardLoomingDarknessLine0, gJiminyMapCardLoomingDarknessLine1, gJiminyMapCardLoomingDarknessLine2, gJiminyMapCardLoomingDarknessLine3,
    gJiminyMapCardLoomingDarknessLine4,
};

const JiminyTextChar* gJiminyMapCardLoomingDarknessLinesFrench[4] = {
    gJiminyMapCardLoomingDarknessLine0French, gJiminyMapCardLoomingDarknessLine1French, gJiminyMapCardLoomingDarknessLine2French, gJiminyMapCardLoomingDarknessLine3French,
};

const JiminyTextChar* gJiminyMapCardLoomingDarknessLinesGerman[5] = {
    gJiminyMapCardLoomingDarknessLine0German, gJiminyMapCardLoomingDarknessLine1German, gJiminyMapCardLoomingDarknessLine2German, gJiminyMapCardLoomingDarknessLine3German,
    gJiminyMapCardLoomingDarknessLine4German,
};

const JiminyTextChar* gJiminyMapCardLoomingDarknessLinesItalian[6] = {
    gJiminyMapCardLoomingDarknessLine0Italian, gJiminyMapCardLoomingDarknessLine1Italian, gJiminyMapCardLoomingDarknessLine2Italian, gJiminyMapCardLoomingDarknessLine3Italian,
    gJiminyMapCardLoomingDarknessLine4Italian, gJiminyMapCardLoomingDarknessLine5Italian,
};

const JiminyTextChar* gJiminyMapCardLoomingDarknessLinesSpanish[5] = {
    gJiminyMapCardLoomingDarknessLine0Spanish, gJiminyMapCardLoomingDarknessLine1Spanish, gJiminyMapCardLoomingDarknessLine2Spanish, gJiminyMapCardLoomingDarknessLine3Spanish,
    gJiminyMapCardLoomingDarknessLine4Spanish,
};

const JiminyTextChar* gJiminyMapCardSleepingDarknessLines[3] = {
    gJiminyMapCardSleepingDarknessLine0, gJiminyMapCardSleepingDarknessLine1, gJiminyMapCardSleepingDarknessLine2,
};

const JiminyTextChar* gJiminyMapCardSleepingDarknessLinesFrench[2] = {
    gJiminyMapCardSleepingDarknessLine0French, gJiminyMapCardSleepingDarknessLine1French,
};

const JiminyTextChar* gJiminyMapCardSleepingDarknessLinesGerman[4] = {
    gJiminyMapCardSleepingDarknessLine0German, gJiminyMapCardSleepingDarknessLine1German, gJiminyMapCardSleepingDarknessLine2German, gJiminyMapCardSleepingDarknessLine3German,
};

const JiminyTextChar* gJiminyMapCardSleepingDarknessLinesItalian[3] = {
    gJiminyMapCardSleepingDarknessLine0Italian, gJiminyMapCardSleepingDarknessLine1Italian, gJiminyMapCardSleepingDarknessLine2Italian,
};

const JiminyTextChar* gJiminyMapCardSleepingDarknessLinesSpanish[4] = {
    gJiminyMapCardSleepingDarknessLine0Spanish, gJiminyMapCardSleepingDarknessLine1Spanish, gJiminyMapCardSleepingDarknessLine2Spanish, gJiminyMapCardSleepingDarknessLine3Spanish,
};

const JiminyTextChar* gJiminyMapCardMomentsReprieveLines[2] = {
    gJiminyMapCardMomentsReprieveLine0, gJiminyMapCardMomentsReprieveLine1,
};

const JiminyTextChar* gJiminyMapCardMomentsReprieveLinesFrench[2] = {
    gJiminyMapCardMomentsReprieveLine0French, gJiminyMapCardMomentsReprieveLine1French,
};

const JiminyTextChar* gJiminyMapCardMomentsReprieveLinesGerman[5] = {
    gJiminyMapCardMomentsReprieveLine0German, gJiminyMapCardMomentsReprieveLine1German, gJiminyMapCardMomentsReprieveLine2German, gJiminyMapCardMomentsReprieveLine3German,
    gJiminyMapCardMomentsReprieveLine4German,
};

const JiminyTextChar* gJiminyMapCardMomentsReprieveLinesItalian[3] = {
    gJiminyMapCardMomentsReprieveLine0Italian, gJiminyMapCardMomentsReprieveLine1Italian, gJiminyMapCardMomentsReprieveLine2Italian,
};

const JiminyTextChar* gJiminyMapCardMomentsReprieveLinesSpanish[3] = {
    gJiminyMapCardMomentsReprieveLine0Spanish, gJiminyMapCardMomentsReprieveLine1Spanish, gJiminyMapCardMomentsReprieveLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardFeebleDarknessLines[3] = {
    gJiminyMapCardFeebleDarknessLine0, gJiminyMapCardFeebleDarknessLine1, gJiminyMapCardFeebleDarknessLine2,
};

const JiminyTextChar* gJiminyMapCardFeebleDarknessLinesFrench[2] = {
    gJiminyMapCardFeebleDarknessLine0French, gJiminyMapCardFeebleDarknessLine1French,
};

const JiminyTextChar* gJiminyMapCardFeebleDarknessLinesGerman[3] = {
    gJiminyMapCardFeebleDarknessLine0German, gJiminyMapCardFeebleDarknessLine1German, gJiminyMapCardFeebleDarknessLine2German,
};

const JiminyTextChar* gJiminyMapCardFeebleDarknessLinesItalian[3] = {
    gJiminyMapCardFeebleDarknessLine0Italian, gJiminyMapCardFeebleDarknessLine1Italian, gJiminyMapCardFeebleDarknessLine2Italian,
};

const JiminyTextChar* gJiminyMapCardFeebleDarknessLinesSpanish[3] = {
    gJiminyMapCardFeebleDarknessLine0Spanish, gJiminyMapCardFeebleDarknessLine1Spanish, gJiminyMapCardFeebleDarknessLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardAlmightyDarknessLines[5] = {
    gJiminyMapCardAlmightyDarknessLine0, gJiminyMapCardAlmightyDarknessLine1, gJiminyMapCardAlmightyDarknessLine2, gJiminyMapCardAlmightyDarknessLine3,
    gJiminyMapCardAlmightyDarknessLine4,
};

const JiminyTextChar* gJiminyMapCardAlmightyDarknessLinesFrench[5] = {
    gJiminyMapCardAlmightyDarknessLine0French, gJiminyMapCardAlmightyDarknessLine1French, gJiminyMapCardAlmightyDarknessLine2French, gJiminyMapCardAlmightyDarknessLine3French,
    gJiminyMapCardAlmightyDarknessLine4French,
};

const JiminyTextChar* gJiminyMapCardAlmightyDarknessLinesGerman[5] = {
    gJiminyMapCardAlmightyDarknessLine0German, gJiminyMapCardAlmightyDarknessLine1German, gJiminyMapCardAlmightyDarknessLine2German, gJiminyMapCardAlmightyDarknessLine3German,
    gJiminyMapCardAlmightyDarknessLine4German,
};

const JiminyTextChar* gJiminyMapCardAlmightyDarknessLinesItalian[6] = {
    gJiminyMapCardAlmightyDarknessLine0Italian, gJiminyMapCardAlmightyDarknessLine1Italian, gJiminyMapCardAlmightyDarknessLine2Italian, gJiminyMapCardAlmightyDarknessLine3Italian,
    gJiminyMapCardAlmightyDarknessLine4Italian, gJiminyMapCardAlmightyDarknessLine5Italian,
};

const JiminyTextChar* gJiminyMapCardAlmightyDarknessLinesSpanish[6] = {
    gJiminyMapCardAlmightyDarknessLine0Spanish, gJiminyMapCardAlmightyDarknessLine1Spanish, gJiminyMapCardAlmightyDarknessLine2Spanish, gJiminyMapCardAlmightyDarknessLine3Spanish,
    gJiminyMapCardAlmightyDarknessLine4Spanish, gJiminyMapCardAlmightyDarknessLine5Spanish,
};

const JiminyTextChar* gJiminyMapCardCalmBountyLines[2] = {
    gJiminyMapCardCalmBountyLine0, gJiminyMapCardCalmBountyLine1,
};

const JiminyTextChar* gJiminyMapCardCalmBountyLinesFrench[1] = {
    gJiminyMapCardCalmBountyLine0French,
};

const JiminyTextChar* gJiminyMapCardCalmBountyLinesGerman[2] = {
    gJiminyMapCardCalmBountyLine0German, gJiminyMapCardCalmBountyLine1German,
};

const JiminyTextChar* gJiminyMapCardCalmBountyLinesItalian[2] = {
    gJiminyMapCardCalmBountyLine0Italian, gJiminyMapCardCalmBountyLine1Italian,
};

const JiminyTextChar* gJiminyMapCardCalmBountyLinesSpanish[2] = {
    gJiminyMapCardCalmBountyLine0Spanish, gJiminyMapCardCalmBountyLine1Spanish,
};

const JiminyTextChar* gJiminyMapCardFalseBountyLines[4] = {
    gJiminyMapCardFalseBountyLine0, gJiminyMapCardFalseBountyLine1, gJiminyMapCardFalseBountyLine2, gJiminyMapCardFalseBountyLine3,
};

const JiminyTextChar* gJiminyMapCardFalseBountyLinesFrench[4] = {
    gJiminyMapCardFalseBountyLine0French, gJiminyMapCardFalseBountyLine1French, gJiminyMapCardFalseBountyLine2French, gJiminyMapCardFalseBountyLine3French,
};

const JiminyTextChar* gJiminyMapCardFalseBountyLinesGerman[4] = {
    gJiminyMapCardFalseBountyLine0German, gJiminyMapCardFalseBountyLine1German, gJiminyMapCardFalseBountyLine2German, gJiminyMapCardFalseBountyLine3German,
};

const JiminyTextChar* gJiminyMapCardFalseBountyLinesItalian[5] = {
    gJiminyMapCardFalseBountyLine0Italian, gJiminyMapCardFalseBountyLine1Italian, gJiminyMapCardFalseBountyLine2Italian, gJiminyMapCardFalseBountyLine3Italian,
    gJiminyMapCardFalseBountyLine4Italian,
};

const JiminyTextChar* gJiminyMapCardFalseBountyLinesSpanish[4] = {
    gJiminyMapCardFalseBountyLine0Spanish, gJiminyMapCardFalseBountyLine1Spanish, gJiminyMapCardFalseBountyLine2Spanish, gJiminyMapCardFalseBountyLine3Spanish,
};

const JiminyTextChar* gJiminyMapCardMoogleRoomLines[3] = {
    gJiminyMapCardMoogleRoomLine0, gJiminyMapCardMoogleRoomLine1, gJiminyMapCardMoogleRoomLine2,
};

const JiminyTextChar* gJiminyMapCardMoogleRoomLinesFrench[3] = {
    gJiminyMapCardMoogleRoomLine0French, gJiminyMapCardMoogleRoomLine1French, gJiminyMapCardMoogleRoomLine2French,
};

const JiminyTextChar* gJiminyMapCardMoogleRoomLinesGerman[3] = {
    gJiminyMapCardMoogleRoomLine0German, gJiminyMapCardMoogleRoomLine1German, gJiminyMapCardMoogleRoomLine2German,
};

const JiminyTextChar* gJiminyMapCardMoogleRoomLinesItalian[4] = {
    gJiminyMapCardMoogleRoomLine0Italian, gJiminyMapCardMoogleRoomLine1Italian, gJiminyMapCardMoogleRoomLine2Italian, gJiminyMapCardMoogleRoomLine3Italian,
};

const JiminyTextChar* gJiminyMapCardMoogleRoomLinesSpanish[4] = {
    gJiminyMapCardMoogleRoomLine0Spanish, gJiminyMapCardMoogleRoomLine1Spanish, gJiminyMapCardMoogleRoomLine2Spanish, gJiminyMapCardMoogleRoomLine3Spanish,
};

const JiminyTextChar* gJiminyMapCardSorcerousWakingLines[3] = {
    gJiminyMapCardSorcerousWakingLine0, gJiminyMapCardSorcerousWakingLine1, gJiminyMapCardSorcerousWakingLine2,
};

const JiminyTextChar* gJiminyMapCardSorcerousWakingLinesFrench[3] = {
    gJiminyMapCardSorcerousWakingLine0French, gJiminyMapCardSorcerousWakingLine1French, gJiminyMapCardSorcerousWakingLine2French,
};

const JiminyTextChar* gJiminyMapCardSorcerousWakingLinesGerman[3] = {
    gJiminyMapCardSorcerousWakingLine0German, gJiminyMapCardSorcerousWakingLine1German, gJiminyMapCardSorcerousWakingLine2German,
};

const JiminyTextChar* gJiminyMapCardSorcerousWakingLinesItalian[3] = {
    gJiminyMapCardSorcerousWakingLine0Italian, gJiminyMapCardSorcerousWakingLine1Italian, gJiminyMapCardSorcerousWakingLine2Italian,
};

const JiminyTextChar* gJiminyMapCardSorcerousWakingLinesSpanish[3] = {
    gJiminyMapCardSorcerousWakingLine0Spanish, gJiminyMapCardSorcerousWakingLine1Spanish, gJiminyMapCardSorcerousWakingLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardMartialWakingLines[3] = {
    gJiminyMapCardMartialWakingLine0, gJiminyMapCardMartialWakingLine1, gJiminyMapCardMartialWakingLine2,
};

const JiminyTextChar* gJiminyMapCardMartialWakingLinesFrench[3] = {
    gJiminyMapCardMartialWakingLine0French, gJiminyMapCardMartialWakingLine1French, gJiminyMapCardMartialWakingLine2French,
};

const JiminyTextChar* gJiminyMapCardMartialWakingLinesGerman[3] = {
    gJiminyMapCardMartialWakingLine0German, gJiminyMapCardMartialWakingLine1German, gJiminyMapCardMartialWakingLine2German,
};

const JiminyTextChar* gJiminyMapCardMartialWakingLinesItalian[3] = {
    gJiminyMapCardMartialWakingLine0Italian, gJiminyMapCardMartialWakingLine1Italian, gJiminyMapCardMartialWakingLine2Italian,
};

const JiminyTextChar* gJiminyMapCardMartialWakingLinesSpanish[3] = {
    gJiminyMapCardMartialWakingLine0Spanish, gJiminyMapCardMartialWakingLine1Spanish, gJiminyMapCardMartialWakingLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardAlchemicWakingLines[3] = {
    gJiminyMapCardAlchemicWakingLine0, gJiminyMapCardAlchemicWakingLine1, gJiminyMapCardAlchemicWakingLine2,
};

const JiminyTextChar* gJiminyMapCardAlchemicWakingLinesFrench[3] = {
    gJiminyMapCardAlchemicWakingLine0French, gJiminyMapCardAlchemicWakingLine1French, gJiminyMapCardAlchemicWakingLine2French,
};

const JiminyTextChar* gJiminyMapCardAlchemicWakingLinesGerman[3] = {
    gJiminyMapCardAlchemicWakingLine0German, gJiminyMapCardAlchemicWakingLine1German, gJiminyMapCardAlchemicWakingLine2German,
};

const JiminyTextChar* gJiminyMapCardAlchemicWakingLinesItalian[3] = {
    gJiminyMapCardAlchemicWakingLine0Italian, gJiminyMapCardAlchemicWakingLine1Italian, gJiminyMapCardAlchemicWakingLine2Italian,
};

const JiminyTextChar* gJiminyMapCardAlchemicWakingLinesSpanish[3] = {
    gJiminyMapCardAlchemicWakingLine0Spanish, gJiminyMapCardAlchemicWakingLine1Spanish, gJiminyMapCardAlchemicWakingLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardMeetingGroundLines[5] = {
    gJiminyMapCardMeetingGroundLine0, gJiminyMapCardMeetingGroundLine1, gJiminyMapCardMeetingGroundLine2, gJiminyMapCardMeetingGroundLine3,
    gJiminyMapCardMeetingGroundLine4,
};

const JiminyTextChar* gJiminyMapCardMeetingGroundLinesFrench[4] = {
    gJiminyMapCardMeetingGroundLine0French, gJiminyMapCardMeetingGroundLine1French, gJiminyMapCardMeetingGroundLine2French, gJiminyMapCardMeetingGroundLine3French,
};

const JiminyTextChar* gJiminyMapCardMeetingGroundLinesGerman[5] = {
    gJiminyMapCardMeetingGroundLine0German, gJiminyMapCardMeetingGroundLine1German, gJiminyMapCardMeetingGroundLine2German, gJiminyMapCardMeetingGroundLine3German,
    gJiminyMapCardMeetingGroundLine4German,
};

const JiminyTextChar* gJiminyMapCardMeetingGroundLinesItalian[5] = {
    gJiminyMapCardMeetingGroundLine0Italian, gJiminyMapCardMeetingGroundLine1Italian, gJiminyMapCardMeetingGroundLine2Italian, gJiminyMapCardMeetingGroundLine3Italian,
    gJiminyMapCardMeetingGroundLine4Italian,
};

const JiminyTextChar* gJiminyMapCardMeetingGroundLinesSpanish[6] = {
    gJiminyMapCardMeetingGroundLine0Spanish, gJiminyMapCardMeetingGroundLine1Spanish, gJiminyMapCardMeetingGroundLine2Spanish, gJiminyMapCardMeetingGroundLine3Spanish,
    gJiminyMapCardMeetingGroundLine4Spanish, gJiminyMapCardMeetingGroundLine5Spanish,
};

const JiminyTextChar* gJiminyMapCardMinglingWorldsLines[2] = {
    gJiminyMapCardMinglingWorldsLine0, gJiminyMapCardMinglingWorldsLine1,
};

const JiminyTextChar* gJiminyMapCardMinglingWorldsLinesFrench[1] = {
    gJiminyMapCardMinglingWorldsLine0French,
};

const JiminyTextChar* gJiminyMapCardMinglingWorldsLinesGerman[2] = {
    gJiminyMapCardMinglingWorldsLine0German, gJiminyMapCardMinglingWorldsLine1German,
};

const JiminyTextChar* gJiminyMapCardMinglingWorldsLinesItalian[2] = {
    gJiminyMapCardMinglingWorldsLine0Italian, gJiminyMapCardMinglingWorldsLine1Italian,
};

const JiminyTextChar* gJiminyMapCardMinglingWorldsLinesSpanish[3] = {
    gJiminyMapCardMinglingWorldsLine0Spanish, gJiminyMapCardMinglingWorldsLine1Spanish, gJiminyMapCardMinglingWorldsLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardStrongInitiativeLines[4] = {
    gJiminyMapCardStrongInitiativeLine0, gJiminyMapCardStrongInitiativeLine1, gJiminyMapCardStrongInitiativeLine2, gJiminyMapCardStrongInitiativeLine3,
};

const JiminyTextChar* gJiminyMapCardStrongInitiativeLinesFrench[3] = {
    gJiminyMapCardStrongInitiativeLine0French, gJiminyMapCardStrongInitiativeLine1French, gJiminyMapCardStrongInitiativeLine2French,
};

const JiminyTextChar* gJiminyMapCardStrongInitiativeLinesGerman[4] = {
    gJiminyMapCardStrongInitiativeLine0German, gJiminyMapCardStrongInitiativeLine1German, gJiminyMapCardStrongInitiativeLine2German, gJiminyMapCardStrongInitiativeLine3German,
};

const JiminyTextChar* gJiminyMapCardStrongInitiativeLinesItalian[4] = {
    gJiminyMapCardStrongInitiativeLine0Italian, gJiminyMapCardStrongInitiativeLine1Italian, gJiminyMapCardStrongInitiativeLine2Italian, gJiminyMapCardStrongInitiativeLine3Italian,
};

const JiminyTextChar* gJiminyMapCardStrongInitiativeLinesSpanish[5] = {
    gJiminyMapCardStrongInitiativeLine0Spanish, gJiminyMapCardStrongInitiativeLine1Spanish, gJiminyMapCardStrongInitiativeLine2Spanish, gJiminyMapCardStrongInitiativeLine3Spanish,
    gJiminyMapCardStrongInitiativeLine4Spanish,
};

const JiminyTextChar* gJiminyMapCardLastingDazeLines[4] = {
    gJiminyMapCardLastingDazeLine0, gJiminyMapCardLastingDazeLine1, gJiminyMapCardLastingDazeLine2, gJiminyMapCardLastingDazeLine3,
};

const JiminyTextChar* gJiminyMapCardLastingDazeLinesFrench[3] = {
    gJiminyMapCardLastingDazeLine0French, gJiminyMapCardLastingDazeLine1French, gJiminyMapCardLastingDazeLine2French,
};

const JiminyTextChar* gJiminyMapCardLastingDazeLinesGerman[5] = {
    gJiminyMapCardLastingDazeLine0German, gJiminyMapCardLastingDazeLine1German, gJiminyMapCardLastingDazeLine2German, gJiminyMapCardLastingDazeLine3German,
    gJiminyMapCardLastingDazeLine4German,
};

const JiminyTextChar* gJiminyMapCardLastingDazeLinesItalian[5] = {
    gJiminyMapCardLastingDazeLine0Italian, gJiminyMapCardLastingDazeLine1Italian, gJiminyMapCardLastingDazeLine2Italian, gJiminyMapCardLastingDazeLine3Italian,
    gJiminyMapCardLastingDazeLine4Italian,
};

const JiminyTextChar* gJiminyMapCardLastingDazeLinesSpanish[5] = {
    gJiminyMapCardLastingDazeLine0Spanish, gJiminyMapCardLastingDazeLine1Spanish, gJiminyMapCardLastingDazeLine2Spanish, gJiminyMapCardLastingDazeLine3Spanish,
    gJiminyMapCardLastingDazeLine4Spanish,
};

const JiminyTextChar* gJiminyMapCardStagnantSpaceLines[2] = {
    gJiminyMapCardStagnantSpaceLine0, gJiminyMapCardStagnantSpaceLine1,
};

const JiminyTextChar* gJiminyMapCardStagnantSpaceLinesFrench[2] = {
    gJiminyMapCardStagnantSpaceLine0French, gJiminyMapCardStagnantSpaceLine1French,
};

const JiminyTextChar* gJiminyMapCardStagnantSpaceLinesGerman[3] = {
    gJiminyMapCardStagnantSpaceLine0German, gJiminyMapCardStagnantSpaceLine1German, gJiminyMapCardStagnantSpaceLine2German,
};

const JiminyTextChar* gJiminyMapCardStagnantSpaceLinesItalian[3] = {
    gJiminyMapCardStagnantSpaceLine0Italian, gJiminyMapCardStagnantSpaceLine1Italian, gJiminyMapCardStagnantSpaceLine2Italian,
};

const JiminyTextChar* gJiminyMapCardStagnantSpaceLinesSpanish[3] = {
    gJiminyMapCardStagnantSpaceLine0Spanish, gJiminyMapCardStagnantSpaceLine1Spanish, gJiminyMapCardStagnantSpaceLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardPremiumRoomLines[3] = {
    gJiminyMapCardPremiumRoomLine0, gJiminyMapCardPremiumRoomLine1, gJiminyMapCardPremiumRoomLine2,
};

const JiminyTextChar* gJiminyMapCardPremiumRoomLinesFrench[3] = {
    gJiminyMapCardPremiumRoomLine0French, gJiminyMapCardPremiumRoomLine1French, gJiminyMapCardPremiumRoomLine2French,
};

const JiminyTextChar* gJiminyMapCardPremiumRoomLinesGerman[4] = {
    gJiminyMapCardPremiumRoomLine0German, gJiminyMapCardPremiumRoomLine1German, gJiminyMapCardPremiumRoomLine2German, gJiminyMapCardPremiumRoomLine3German,
};

const JiminyTextChar* gJiminyMapCardPremiumRoomLinesItalian[4] = {
    gJiminyMapCardPremiumRoomLine0Italian, gJiminyMapCardPremiumRoomLine1Italian, gJiminyMapCardPremiumRoomLine2Italian, gJiminyMapCardPremiumRoomLine3Italian,
};

const JiminyTextChar* gJiminyMapCardPremiumRoomLinesSpanish[3] = {
    gJiminyMapCardPremiumRoomLine0Spanish, gJiminyMapCardPremiumRoomLine1Spanish, gJiminyMapCardPremiumRoomLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardWhiteRoomLines[5] = {
    gJiminyMapCardWhiteRoomLine0, gJiminyMapCardWhiteRoomLine1, gJiminyMapCardWhiteRoomLine2, gJiminyMapCardWhiteRoomLine3,
    gJiminyMapCardWhiteRoomLine4,
};

const JiminyTextChar* gJiminyMapCardWhiteRoomLinesFrench[4] = {
    gJiminyMapCardWhiteRoomLine0French, gJiminyMapCardWhiteRoomLine1French, gJiminyMapCardWhiteRoomLine2French, gJiminyMapCardWhiteRoomLine3French,
};

const JiminyTextChar* gJiminyMapCardWhiteRoomLinesGerman[5] = {
    gJiminyMapCardWhiteRoomLine0German, gJiminyMapCardWhiteRoomLine1German, gJiminyMapCardWhiteRoomLine2German, gJiminyMapCardWhiteRoomLine3German,
    gJiminyMapCardWhiteRoomLine4German,
};

const JiminyTextChar* gJiminyMapCardWhiteRoomLinesItalian[4] = {
    gJiminyMapCardWhiteRoomLine0Italian, gJiminyMapCardWhiteRoomLine1Italian, gJiminyMapCardWhiteRoomLine2Italian, gJiminyMapCardWhiteRoomLine3Italian,
};

const JiminyTextChar* gJiminyMapCardWhiteRoomLinesSpanish[5] = {
    gJiminyMapCardWhiteRoomLine0Spanish, gJiminyMapCardWhiteRoomLine1Spanish, gJiminyMapCardWhiteRoomLine2Spanish, gJiminyMapCardWhiteRoomLine3Spanish,
    gJiminyMapCardWhiteRoomLine4Spanish,
};

const JiminyTextChar* gJiminyMapCardBlackRoomLines[4] = {
    gJiminyMapCardBlackRoomLine0, gJiminyMapCardBlackRoomLine1, gJiminyMapCardBlackRoomLine2, gJiminyMapCardBlackRoomLine3,
};

const JiminyTextChar* gJiminyMapCardBlackRoomLinesFrench[4] = {
    gJiminyMapCardBlackRoomLine0French, gJiminyMapCardBlackRoomLine1French, gJiminyMapCardBlackRoomLine2French, gJiminyMapCardBlackRoomLine3French,
};

const JiminyTextChar* gJiminyMapCardBlackRoomLinesGerman[4] = {
    gJiminyMapCardBlackRoomLine0German, gJiminyMapCardBlackRoomLine1German, gJiminyMapCardBlackRoomLine2German, gJiminyMapCardBlackRoomLine3German,
};

const JiminyTextChar* gJiminyMapCardBlackRoomLinesItalian[5] = {
    gJiminyMapCardBlackRoomLine0Italian, gJiminyMapCardBlackRoomLine1Italian, gJiminyMapCardBlackRoomLine2Italian, gJiminyMapCardBlackRoomLine3Italian,
    gJiminyMapCardBlackRoomLine4Italian,
};

const JiminyTextChar* gJiminyMapCardBlackRoomLinesSpanish[5] = {
    gJiminyMapCardBlackRoomLine0Spanish, gJiminyMapCardBlackRoomLine1Spanish, gJiminyMapCardBlackRoomLine2Spanish, gJiminyMapCardBlackRoomLine3Spanish,
    gJiminyMapCardBlackRoomLine4Spanish,
};

const JiminyTextChar* gJiminyMapCardKeyOfBeginningsLines[2] = {
    gJiminyMapCardKeyOfBeginningsLine0, gJiminyMapCardKeyOfBeginningsLine1,
};

const JiminyTextChar* gJiminyMapCardKeyOfBeginningsLinesFrench[1] = {
    gJiminyMapCardKeyOfBeginningsLine0French,
};

const JiminyTextChar* gJiminyMapCardKeyOfBeginningsLinesGerman[3] = {
    gJiminyMapCardKeyOfBeginningsLine0German, gJiminyMapCardKeyOfBeginningsLine1German, gJiminyMapCardKeyOfBeginningsLine2German,
};

const JiminyTextChar* gJiminyMapCardKeyOfBeginningsLinesItalian[3] = {
    gJiminyMapCardKeyOfBeginningsLine0Italian, gJiminyMapCardKeyOfBeginningsLine1Italian, gJiminyMapCardKeyOfBeginningsLine2Italian,
};

const JiminyTextChar* gJiminyMapCardKeyOfBeginningsLinesSpanish[3] = {
    gJiminyMapCardKeyOfBeginningsLine0Spanish, gJiminyMapCardKeyOfBeginningsLine1Spanish, gJiminyMapCardKeyOfBeginningsLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardKeyOfGuidanceLines[2] = {
    gJiminyMapCardKeyOfGuidanceLine0, gJiminyMapCardKeyOfGuidanceLine1,
};

const JiminyTextChar* gJiminyMapCardKeyOfGuidanceLinesFrench[2] = {
    gJiminyMapCardKeyOfGuidanceLine0French, gJiminyMapCardKeyOfGuidanceLine1French,
};

const JiminyTextChar* gJiminyMapCardKeyOfGuidanceLinesGerman[3] = {
    gJiminyMapCardKeyOfGuidanceLine0German, gJiminyMapCardKeyOfGuidanceLine1German, gJiminyMapCardKeyOfGuidanceLine2German,
};

const JiminyTextChar* gJiminyMapCardKeyOfGuidanceLinesItalian[3] = {
    gJiminyMapCardKeyOfGuidanceLine0Italian, gJiminyMapCardKeyOfGuidanceLine1Italian, gJiminyMapCardKeyOfGuidanceLine2Italian,
};

const JiminyTextChar* gJiminyMapCardKeyOfGuidanceLinesSpanish[3] = {
    gJiminyMapCardKeyOfGuidanceLine0Spanish, gJiminyMapCardKeyOfGuidanceLine1Spanish, gJiminyMapCardKeyOfGuidanceLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardKeyToTruthLines[2] = {
    gJiminyMapCardKeyToTruthLine0, gJiminyMapCardKeyToTruthLine1,
};

const JiminyTextChar* gJiminyMapCardKeyToTruthLinesFrench[2] = {
    gJiminyMapCardKeyToTruthLine0French, gJiminyMapCardKeyToTruthLine1French,
};

const JiminyTextChar* gJiminyMapCardKeyToTruthLinesGerman[3] = {
    gJiminyMapCardKeyToTruthLine0German, gJiminyMapCardKeyToTruthLine1German, gJiminyMapCardKeyToTruthLine2German,
};

const JiminyTextChar* gJiminyMapCardKeyToTruthLinesItalian[3] = {
    gJiminyMapCardKeyToTruthLine0Italian, gJiminyMapCardKeyToTruthLine1Italian, gJiminyMapCardKeyToTruthLine2Italian,
};

const JiminyTextChar* gJiminyMapCardKeyToTruthLinesSpanish[3] = {
    gJiminyMapCardKeyToTruthLine0Spanish, gJiminyMapCardKeyToTruthLine1Spanish, gJiminyMapCardKeyToTruthLine2Spanish,
};

const JiminyTextChar* gJiminyMapCardKeyToRewardsLines[2] = {
    gJiminyMapCardKeyToRewardsLine0, gJiminyMapCardKeyToRewardsLine1,
};

const JiminyTextChar* gJiminyMapCardKeyToRewardsLinesFrench[2] = {
    gJiminyMapCardKeyToRewardsLine0French, gJiminyMapCardKeyToRewardsLine1French,
};

const JiminyTextChar* gJiminyMapCardKeyToRewardsLinesGerman[3] = {
    gJiminyMapCardKeyToRewardsLine0German, gJiminyMapCardKeyToRewardsLine1German, gJiminyMapCardKeyToRewardsLine2German,
};

const JiminyTextChar* gJiminyMapCardKeyToRewardsLinesItalian[2] = {
    gJiminyMapCardKeyToRewardsLine0Italian, gJiminyMapCardKeyToRewardsLine1Italian,
};

const JiminyTextChar* gJiminyMapCardKeyToRewardsLinesSpanish[3] = {
    gJiminyMapCardKeyToRewardsLine0Spanish, gJiminyMapCardKeyToRewardsLine1Spanish, gJiminyMapCardKeyToRewardsLine2Spanish,
};

const JiminyTextChar* gJiminyPremiumCardsLines[17] = {
    gJiminyPremiumCardsLine0, gJiminyPremiumCardsLine1, gJiminyPremiumCardsLine2, gJiminyPremiumCardsLine3,
    gJiminyPremiumCardsLine4, gJiminyPremiumCardsLine5, gJiminyPremiumCardsLine6, gJiminyPremiumCardsLine7,
    gJiminyPremiumCardsLine8, gJiminyPremiumCardsLine9, gJiminyPremiumCardsLine10, gJiminyPremiumCardsLine11,
    gJiminyPremiumCardsLine12, gJiminyPremiumCardsLine13, gJiminyPremiumCardsLine14, gJiminyPremiumCardsLine15,
    gJiminyPremiumCardsLine16,
};

const JiminyTextChar* gJiminyPremiumCardsLinesFrench[17] = {
    gJiminyPremiumCardsLine0French, gJiminyPremiumCardsLine1French, gJiminyPremiumCardsLine2French, gJiminyPremiumCardsLine3French,
    gJiminyPremiumCardsLine4French, gJiminyPremiumCardsLine5French, gJiminyPremiumCardsLine6French, gJiminyPremiumCardsLine7French,
    gJiminyPremiumCardsLine8French, gJiminyPremiumCardsLine9French, gJiminyPremiumCardsLine10French, gJiminyPremiumCardsLine11French,
    gJiminyPremiumCardsLine12French, gJiminyPremiumCardsLine13French, gJiminyPremiumCardsLine14French, gJiminyPremiumCardsLine15French,
    gJiminyPremiumCardsLine16French,
};

const JiminyTextChar* gJiminyPremiumCardsLinesGerman[18] = {
    gJiminyPremiumCardsLine0German, gJiminyPremiumCardsLine1German, gJiminyPremiumCardsLine2German, gJiminyPremiumCardsLine3German,
    gJiminyPremiumCardsLine4German, gJiminyPremiumCardsLine5German, gJiminyPremiumCardsLine6German, gJiminyPremiumCardsLine7German,
    gJiminyPremiumCardsLine8German, gJiminyPremiumCardsLine9German, gJiminyPremiumCardsLine10German, gJiminyPremiumCardsLine11German,
    gJiminyPremiumCardsLine12German, gJiminyPremiumCardsLine13German, gJiminyPremiumCardsLine14German, gJiminyPremiumCardsLine15German,
    gJiminyPremiumCardsLine16German, gJiminyPremiumCardsLine17German,
};

const JiminyTextChar* gJiminyPremiumCardsLinesItalian[19] = {
    gJiminyPremiumCardsLine0Italian, gJiminyPremiumCardsLine1Italian, gJiminyPremiumCardsLine2Italian, gJiminyPremiumCardsLine3Italian,
    gJiminyPremiumCardsLine4Italian, gJiminyPremiumCardsLine5Italian, gJiminyPremiumCardsLine6Italian, gJiminyPremiumCardsLine7Italian,
    gJiminyPremiumCardsLine8Italian, gJiminyPremiumCardsLine9Italian, gJiminyPremiumCardsLine10Italian, gJiminyPremiumCardsLine11Italian,
    gJiminyPremiumCardsLine12Italian, gJiminyPremiumCardsLine13Italian, gJiminyPremiumCardsLine14Italian, gJiminyPremiumCardsLine15Italian,
    gJiminyPremiumCardsLine16Italian, gJiminyPremiumCardsLine17Italian, gJiminyPremiumCardsLine18Italian,
};

const JiminyTextChar* gJiminyPremiumCardsLinesSpanish[19] = {
    gJiminyPremiumCardsLine0Spanish, gJiminyPremiumCardsLine1Spanish, gJiminyPremiumCardsLine2Spanish, gJiminyPremiumCardsLine3Spanish,
    gJiminyPremiumCardsLine4Spanish, gJiminyPremiumCardsLine5Spanish, gJiminyPremiumCardsLine6Spanish, gJiminyPremiumCardsLine7Spanish,
    gJiminyPremiumCardsLine8Spanish, gJiminyPremiumCardsLine9Spanish, gJiminyPremiumCardsLine10Spanish, gJiminyPremiumCardsLine11Spanish,
    gJiminyPremiumCardsLine12Spanish, gJiminyPremiumCardsLine13Spanish, gJiminyPremiumCardsLine14Spanish, gJiminyPremiumCardsLine15Spanish,
    gJiminyPremiumCardsLine16Spanish, gJiminyPremiumCardsLine17Spanish, gJiminyPremiumCardsLine18Spanish,
};

const JiminyTextChar* gJiminyCharacterSoraLines[15] = {
    gJiminyCharacterSoraLine0, gJiminyCharacterSoraLine1, gJiminyCharacterSoraLine2, gJiminyCharacterSoraLine3,
    gJiminyCharacterSoraLine4, gJiminyCharacterSoraLine5, gJiminyCharacterSoraLine6, gJiminyCharacterSoraLine7,
    gJiminyCharacterSoraLine8, gJiminyCharacterSoraLine9, gJiminyCharacterSoraLine10, gJiminyCharacterSoraLine11,
    gJiminyCharacterSoraLine12, gJiminyCharacterSoraLine13, gJiminyCharacterSoraLine14,
};

const JiminyTextChar* gJiminyCharacterSoraLinesFrench[19] = {
    gJiminyCharacterSoraLine0French, gJiminyCharacterSoraLine1French, gJiminyCharacterSoraLine2French, gJiminyCharacterSoraLine3French,
    gJiminyCharacterSoraLine4French, gJiminyCharacterSoraLine5French, gJiminyCharacterSoraLine6French, gJiminyCharacterSoraLine7French,
    gJiminyCharacterSoraLine8French, gJiminyCharacterSoraLine9French, gJiminyCharacterSoraLine10French, gJiminyCharacterSoraLine11French,
    gJiminyCharacterSoraLine12French, gJiminyCharacterSoraLine13French, gJiminyCharacterSoraLine14French, gJiminyCharacterSoraLine15French,
    gJiminyCharacterSoraLine16French, gJiminyCharacterSoraLine17French, gJiminyCharacterSoraLine18French,
};

const JiminyTextChar* gJiminyCharacterSoraLinesGerman[19] = {
    gJiminyCharacterSoraLine0German, gJiminyCharacterSoraLine1German, gJiminyCharacterSoraLine2German, gJiminyCharacterSoraLine3German,
    gJiminyCharacterSoraLine4German, gJiminyCharacterSoraLine5German, gJiminyCharacterSoraLine6German, gJiminyCharacterSoraLine7German,
    gJiminyCharacterSoraLine8German, gJiminyCharacterSoraLine9German, gJiminyCharacterSoraLine10German, gJiminyCharacterSoraLine11German,
    gJiminyCharacterSoraLine12German, gJiminyCharacterSoraLine13German, gJiminyCharacterSoraLine14German, gJiminyCharacterSoraLine15German,
    gJiminyCharacterSoraLine16German, gJiminyCharacterSoraLine17German, gJiminyCharacterSoraLine18German,
};

const JiminyTextChar* gJiminyCharacterSoraLinesItalian[18] = {
    gJiminyCharacterSoraLine0Italian, gJiminyCharacterSoraLine1Italian, gJiminyCharacterSoraLine2Italian, gJiminyCharacterSoraLine3Italian,
    gJiminyCharacterSoraLine4Italian, gJiminyCharacterSoraLine5Italian, gJiminyCharacterSoraLine6Italian, gJiminyCharacterSoraLine7Italian,
    gJiminyCharacterSoraLine8Italian, gJiminyCharacterSoraLine9Italian, gJiminyCharacterSoraLine10Italian, gJiminyCharacterSoraLine11Italian,
    gJiminyCharacterSoraLine12Italian, gJiminyCharacterSoraLine13Italian, gJiminyCharacterSoraLine14Italian, gJiminyCharacterSoraLine15Italian,
    gJiminyCharacterSoraLine16Italian, gJiminyCharacterSoraLine17Italian,
};

const JiminyTextChar* gJiminyCharacterSoraLinesSpanish[15] = {
    gJiminyCharacterSoraLine0Spanish, gJiminyCharacterSoraLine1Spanish, gJiminyCharacterSoraLine2Spanish, gJiminyCharacterSoraLine3Spanish,
    gJiminyCharacterSoraLine4Spanish, gJiminyCharacterSoraLine5Spanish, gJiminyCharacterSoraLine6Spanish, gJiminyCharacterSoraLine7Spanish,
    gJiminyCharacterSoraLine8Spanish, gJiminyCharacterSoraLine9Spanish, gJiminyCharacterSoraLine10Spanish, gJiminyCharacterSoraLine11Spanish,
    gJiminyCharacterSoraLine12Spanish, gJiminyCharacterSoraLine13Spanish, gJiminyCharacterSoraLine14Spanish,
};

const JiminyTextChar* gJiminyCharacterDonaldDuckLines[16] = {
    gJiminyCharacterDonaldDuckLine0, gJiminyCharacterDonaldDuckLine1, gJiminyCharacterDonaldDuckLine2, gJiminyCharacterDonaldDuckLine3,
    gJiminyCharacterDonaldDuckLine4, gJiminyCharacterDonaldDuckLine5, gJiminyCharacterDonaldDuckLine6, gJiminyCharacterDonaldDuckLine7,
    gJiminyCharacterDonaldDuckLine8, gJiminyCharacterDonaldDuckLine9, gJiminyCharacterDonaldDuckLine10, gJiminyCharacterDonaldDuckLine11,
    gJiminyCharacterDonaldDuckLine12, gJiminyCharacterDonaldDuckLine13, gJiminyCharacterDonaldDuckLine14, gJiminyCharacterDonaldDuckLine15,
};

const JiminyTextChar* gJiminyCharacterDonaldDuckLinesFrench[16] = {
    gJiminyCharacterDonaldDuckLine0French, gJiminyCharacterDonaldDuckLine1French, gJiminyCharacterDonaldDuckLine2French, gJiminyCharacterDonaldDuckLine3French,
    gJiminyCharacterDonaldDuckLine4French, gJiminyCharacterDonaldDuckLine5French, gJiminyCharacterDonaldDuckLine6French, gJiminyCharacterDonaldDuckLine7French,
    gJiminyCharacterDonaldDuckLine8French, gJiminyCharacterDonaldDuckLine9French, gJiminyCharacterDonaldDuckLine10French, gJiminyCharacterDonaldDuckLine11French,
    gJiminyCharacterDonaldDuckLine12French, gJiminyCharacterDonaldDuckLine13French, gJiminyCharacterDonaldDuckLine14French, gJiminyCharacterDonaldDuckLine15French,
};

const JiminyTextChar* gJiminyCharacterDonaldDuckLinesGerman[16] = {
    gJiminyCharacterDonaldDuckLine0German, gJiminyCharacterDonaldDuckLine1German, gJiminyCharacterDonaldDuckLine2German, gJiminyCharacterDonaldDuckLine3German,
    gJiminyCharacterDonaldDuckLine4German, gJiminyCharacterDonaldDuckLine5German, gJiminyCharacterDonaldDuckLine6German, gJiminyCharacterDonaldDuckLine7German,
    gJiminyCharacterDonaldDuckLine8German, gJiminyCharacterDonaldDuckLine9German, gJiminyCharacterDonaldDuckLine10German, gJiminyCharacterDonaldDuckLine11German,
    gJiminyCharacterDonaldDuckLine12German, gJiminyCharacterDonaldDuckLine13German, gJiminyCharacterDonaldDuckLine14German, gJiminyCharacterDonaldDuckLine15German,
};

const JiminyTextChar* gJiminyCharacterDonaldDuckLinesItalian[18] = {
    gJiminyCharacterDonaldDuckLine0Italian, gJiminyCharacterDonaldDuckLine1Italian, gJiminyCharacterDonaldDuckLine2Italian, gJiminyCharacterDonaldDuckLine3Italian,
    gJiminyCharacterDonaldDuckLine4Italian, gJiminyCharacterDonaldDuckLine5Italian, gJiminyCharacterDonaldDuckLine6Italian, gJiminyCharacterDonaldDuckLine7Italian,
    gJiminyCharacterDonaldDuckLine8Italian, gJiminyCharacterDonaldDuckLine9Italian, gJiminyCharacterDonaldDuckLine10Italian, gJiminyCharacterDonaldDuckLine11Italian,
    gJiminyCharacterDonaldDuckLine12Italian, gJiminyCharacterDonaldDuckLine13Italian, gJiminyCharacterDonaldDuckLine14Italian, gJiminyCharacterDonaldDuckLine15Italian,
    gJiminyCharacterDonaldDuckLine16Italian, gJiminyCharacterDonaldDuckLine17Italian,
};

const JiminyTextChar* gJiminyCharacterDonaldDuckLinesSpanish[15] = {
    gJiminyCharacterDonaldDuckLine0Spanish, gJiminyCharacterDonaldDuckLine1Spanish, gJiminyCharacterDonaldDuckLine2Spanish, gJiminyCharacterDonaldDuckLine3Spanish,
    gJiminyCharacterDonaldDuckLine4Spanish, gJiminyCharacterDonaldDuckLine5Spanish, gJiminyCharacterDonaldDuckLine6Spanish, gJiminyCharacterDonaldDuckLine7Spanish,
    gJiminyCharacterDonaldDuckLine8Spanish, gJiminyCharacterDonaldDuckLine9Spanish, gJiminyCharacterDonaldDuckLine10Spanish, gJiminyCharacterDonaldDuckLine11Spanish,
    gJiminyCharacterDonaldDuckLine12Spanish, gJiminyCharacterDonaldDuckLine13Spanish, gJiminyCharacterDonaldDuckLine14Spanish,
};

const JiminyTextChar* gJiminyCharacterGoofyLines[12] = {
    gJiminyCharacterGoofyLine0, gJiminyCharacterGoofyLine1, gJiminyCharacterGoofyLine2, gJiminyCharacterGoofyLine3,
    gJiminyCharacterGoofyLine4, gJiminyCharacterGoofyLine5, gJiminyCharacterGoofyLine6, gJiminyCharacterGoofyLine7,
    gJiminyCharacterGoofyLine8, gJiminyCharacterGoofyLine9, gJiminyCharacterGoofyLine10, gJiminyCharacterGoofyLine11,
};

const JiminyTextChar* gJiminyCharacterGoofyLinesFrench[13] = {
    gJiminyCharacterGoofyLine0French, gJiminyCharacterGoofyLine1French, gJiminyCharacterGoofyLine2French, gJiminyCharacterGoofyLine3French,
    gJiminyCharacterGoofyLine4French, gJiminyCharacterGoofyLine5French, gJiminyCharacterGoofyLine6French, gJiminyCharacterGoofyLine7French,
    gJiminyCharacterGoofyLine8French, gJiminyCharacterGoofyLine9French, gJiminyCharacterGoofyLine10French, gJiminyCharacterGoofyLine11French,
    gJiminyCharacterGoofyLine12French,
};

const JiminyTextChar* gJiminyCharacterGoofyLinesGerman[16] = {
    gJiminyCharacterGoofyLine0German, gJiminyCharacterGoofyLine1German, gJiminyCharacterGoofyLine2German, gJiminyCharacterGoofyLine3German,
    gJiminyCharacterGoofyLine4German, gJiminyCharacterGoofyLine5German, gJiminyCharacterGoofyLine6German, gJiminyCharacterGoofyLine7German,
    gJiminyCharacterGoofyLine8German, gJiminyCharacterGoofyLine9German, gJiminyCharacterGoofyLine10German, gJiminyCharacterGoofyLine11German,
    gJiminyCharacterGoofyLine12German, gJiminyCharacterGoofyLine13German, gJiminyCharacterGoofyLine14German, gJiminyCharacterGoofyLine15German,
};

const JiminyTextChar* gJiminyCharacterGoofyLinesItalian[13] = {
    gJiminyCharacterGoofyLine0Italian, gJiminyCharacterGoofyLine1Italian, gJiminyCharacterGoofyLine2Italian, gJiminyCharacterGoofyLine3Italian,
    gJiminyCharacterGoofyLine4Italian, gJiminyCharacterGoofyLine5Italian, gJiminyCharacterGoofyLine6Italian, gJiminyCharacterGoofyLine7Italian,
    gJiminyCharacterGoofyLine8Italian, gJiminyCharacterGoofyLine9Italian, gJiminyCharacterGoofyLine10Italian, gJiminyCharacterGoofyLine11Italian,
    gJiminyCharacterGoofyLine12Italian,
};

const JiminyTextChar* gJiminyCharacterGoofyLinesSpanish[12] = {
    gJiminyCharacterGoofyLine0Spanish, gJiminyCharacterGoofyLine1Spanish, gJiminyCharacterGoofyLine2Spanish, gJiminyCharacterGoofyLine3Spanish,
    gJiminyCharacterGoofyLine4Spanish, gJiminyCharacterGoofyLine5Spanish, gJiminyCharacterGoofyLine6Spanish, gJiminyCharacterGoofyLine7Spanish,
    gJiminyCharacterGoofyLine8Spanish, gJiminyCharacterGoofyLine9Spanish, gJiminyCharacterGoofyLine10Spanish, gJiminyCharacterGoofyLine11Spanish,
};

const JiminyTextChar* gJiminyCharacterJiminyCricketLines[7] = {
    gJiminyCharacterJiminyCricketLine0, gJiminyCharacterJiminyCricketLine1, gJiminyCharacterJiminyCricketLine2, gJiminyCharacterJiminyCricketLine3,
    gJiminyCharacterJiminyCricketLine4, gJiminyCharacterJiminyCricketLine5, gJiminyCharacterJiminyCricketLine6,
};

const JiminyTextChar* gJiminyCharacterJiminyCricketLinesFrench[10] = {
    gJiminyCharacterJiminyCricketLine0French, gJiminyCharacterJiminyCricketLine1French, gJiminyCharacterJiminyCricketLine2French, gJiminyCharacterJiminyCricketLine3French,
    gJiminyCharacterJiminyCricketLine4French, gJiminyCharacterJiminyCricketLine5French, gJiminyCharacterJiminyCricketLine6French, gJiminyCharacterJiminyCricketLine7French,
    gJiminyCharacterJiminyCricketLine8French, gJiminyCharacterJiminyCricketLine9French,
};

const JiminyTextChar* gJiminyCharacterJiminyCricketLinesGerman[10] = {
    gJiminyCharacterJiminyCricketLine0German, gJiminyCharacterJiminyCricketLine1German, gJiminyCharacterJiminyCricketLine2German, gJiminyCharacterJiminyCricketLine3German,
    gJiminyCharacterJiminyCricketLine4German, gJiminyCharacterJiminyCricketLine5German, gJiminyCharacterJiminyCricketLine6German, gJiminyCharacterJiminyCricketLine7German,
    gJiminyCharacterJiminyCricketLine8German, gJiminyCharacterJiminyCricketLine9German,
};

const JiminyTextChar* gJiminyCharacterJiminyCricketLinesItalian[12] = {
    gJiminyCharacterJiminyCricketLine0Italian, gJiminyCharacterJiminyCricketLine1Italian, gJiminyCharacterJiminyCricketLine2Italian, gJiminyCharacterJiminyCricketLine3Italian,
    gJiminyCharacterJiminyCricketLine4Italian, gJiminyCharacterJiminyCricketLine5Italian, gJiminyCharacterJiminyCricketLine6Italian, gJiminyCharacterJiminyCricketLine7Italian,
    gJiminyCharacterJiminyCricketLine8Italian, gJiminyCharacterJiminyCricketLine9Italian, gJiminyCharacterJiminyCricketLine10Italian, gJiminyCharacterJiminyCricketLine11Italian,
};

const JiminyTextChar* gJiminyCharacterJiminyCricketLinesSpanish[8] = {
    gJiminyCharacterJiminyCricketLine0Spanish, gJiminyCharacterJiminyCricketLine1Spanish, gJiminyCharacterJiminyCricketLine2Spanish, gJiminyCharacterJiminyCricketLine3Spanish,
    gJiminyCharacterJiminyCricketLine4Spanish, gJiminyCharacterJiminyCricketLine5Spanish, gJiminyCharacterJiminyCricketLine6Spanish, gJiminyCharacterJiminyCricketLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterRikuLines[16] = {
    gJiminyCharacterRikuLine0, gJiminyCharacterRikuLine1, gJiminyCharacterRikuLine2, gJiminyCharacterRikuLine3,
    gJiminyCharacterRikuLine4, gJiminyCharacterRikuLine5, gJiminyCharacterRikuLine6, gJiminyCharacterRikuLine7,
    gJiminyCharacterRikuLine8, gJiminyCharacterRikuLine9, gJiminyCharacterRikuLine10, gJiminyCharacterRikuLine11,
    gJiminyCharacterRikuLine12, gJiminyCharacterRikuLine13, gJiminyCharacterRikuLine14, gJiminyCharacterRikuLine15,
};

const JiminyTextChar* gJiminyCharacterRikuLinesFrench[22] = {
    gJiminyCharacterRikuLine0French, gJiminyCharacterRikuLine1French, gJiminyCharacterRikuLine2French, gJiminyCharacterRikuLine3French,
    gJiminyCharacterRikuLine4French, gJiminyCharacterRikuLine5French, gJiminyCharacterRikuLine6French, gJiminyCharacterRikuLine7French,
    gJiminyCharacterRikuLine8French, gJiminyCharacterRikuLine9French, gJiminyCharacterRikuLine10French, gJiminyCharacterRikuLine11French,
    gJiminyCharacterRikuLine12French, gJiminyCharacterRikuLine13French, gJiminyCharacterRikuLine14French, gJiminyCharacterRikuLine15French,
    gJiminyCharacterRikuLine16French, gJiminyCharacterRikuLine17French, gJiminyCharacterRikuLine18French, gJiminyCharacterRikuLine19French,
    gJiminyCharacterRikuLine20French, gJiminyCharacterRikuLine21French,
};

const JiminyTextChar* gJiminyCharacterRikuLinesGerman[21] = {
    gJiminyCharacterRikuLine0German, gJiminyCharacterRikuLine1German, gJiminyCharacterRikuLine2German, gJiminyCharacterRikuLine3German,
    gJiminyCharacterRikuLine4German, gJiminyCharacterRikuLine5German, gJiminyCharacterRikuLine6German, gJiminyCharacterRikuLine7German,
    gJiminyCharacterRikuLine8German, gJiminyCharacterRikuLine9German, gJiminyCharacterRikuLine10German, gJiminyCharacterRikuLine11German,
    gJiminyCharacterRikuLine12German, gJiminyCharacterRikuLine13German, gJiminyCharacterRikuLine14German, gJiminyCharacterRikuLine15German,
    gJiminyCharacterRikuLine16German, gJiminyCharacterRikuLine17German, gJiminyCharacterRikuLine18German, gJiminyCharacterRikuLine19German,
    gJiminyCharacterRikuLine20German,
};

const JiminyTextChar* gJiminyCharacterRikuLinesItalian[17] = {
    gJiminyCharacterRikuLine0Italian, gJiminyCharacterRikuLine1Italian, gJiminyCharacterRikuLine2Italian, gJiminyCharacterRikuLine3Italian,
    gJiminyCharacterRikuLine4Italian, gJiminyCharacterRikuLine5Italian, gJiminyCharacterRikuLine6Italian, gJiminyCharacterRikuLine7Italian,
    gJiminyCharacterRikuLine8Italian, gJiminyCharacterRikuLine9Italian, gJiminyCharacterRikuLine10Italian, gJiminyCharacterRikuLine11Italian,
    gJiminyCharacterRikuLine12Italian, gJiminyCharacterRikuLine13Italian, gJiminyCharacterRikuLine14Italian, gJiminyCharacterRikuLine15Italian,
    gJiminyCharacterRikuLine16Italian,
};

const JiminyTextChar* gJiminyCharacterRikuLinesSpanish[16] = {
    gJiminyCharacterRikuLine0Spanish, gJiminyCharacterRikuLine1Spanish, gJiminyCharacterRikuLine2Spanish, gJiminyCharacterRikuLine3Spanish,
    gJiminyCharacterRikuLine4Spanish, gJiminyCharacterRikuLine5Spanish, gJiminyCharacterRikuLine6Spanish, gJiminyCharacterRikuLine7Spanish,
    gJiminyCharacterRikuLine8Spanish, gJiminyCharacterRikuLine9Spanish, gJiminyCharacterRikuLine10Spanish, gJiminyCharacterRikuLine11Spanish,
    gJiminyCharacterRikuLine12Spanish, gJiminyCharacterRikuLine13Spanish, gJiminyCharacterRikuLine14Spanish, gJiminyCharacterRikuLine15Spanish,
};

const JiminyTextChar* gJiminyCharacterKairiLines[15] = {
    gJiminyCharacterKairiLine0, gJiminyCharacterKairiLine1, gJiminyCharacterKairiLine2, gJiminyCharacterKairiLine3,
    gJiminyCharacterKairiLine4, gJiminyCharacterKairiLine5, gJiminyCharacterKairiLine6, gJiminyCharacterKairiLine7,
    gJiminyCharacterKairiLine8, gJiminyCharacterKairiLine9, gJiminyCharacterKairiLine10, gJiminyCharacterKairiLine11,
    gJiminyCharacterKairiLine12, gJiminyCharacterKairiLine13, gJiminyCharacterKairiLine14,
};

const JiminyTextChar* gJiminyCharacterKairiLinesFrench[19] = {
    gJiminyCharacterKairiLine0French, gJiminyCharacterKairiLine1French, gJiminyCharacterKairiLine2French, gJiminyCharacterKairiLine3French,
    gJiminyCharacterKairiLine4French, gJiminyCharacterKairiLine5French, gJiminyCharacterKairiLine6French, gJiminyCharacterKairiLine7French,
    gJiminyCharacterKairiLine8French, gJiminyCharacterKairiLine9French, gJiminyCharacterKairiLine10French, gJiminyCharacterKairiLine11French,
    gJiminyCharacterKairiLine12French, gJiminyCharacterKairiLine13French, gJiminyCharacterKairiLine14French, gJiminyCharacterKairiLine15French,
    gJiminyCharacterKairiLine16French, gJiminyCharacterKairiLine17French, gJiminyCharacterKairiLine18French,
};

const JiminyTextChar* gJiminyCharacterKairiLinesGerman[23] = {
    gJiminyCharacterKairiLine0German, gJiminyCharacterKairiLine1German, gJiminyCharacterKairiLine2German, gJiminyCharacterKairiLine3German,
    gJiminyCharacterKairiLine4German, gJiminyCharacterKairiLine5German, gJiminyCharacterKairiLine6German, gJiminyCharacterKairiLine7German,
    gJiminyCharacterKairiLine8German, gJiminyCharacterKairiLine9German, gJiminyCharacterKairiLine10German, gJiminyCharacterKairiLine11German,
    gJiminyCharacterKairiLine12German, gJiminyCharacterKairiLine13German, gJiminyCharacterKairiLine14German, gJiminyCharacterKairiLine15German,
    gJiminyCharacterKairiLine16German, gJiminyCharacterKairiLine17German, gJiminyCharacterKairiLine18German, gJiminyCharacterKairiLine19German,
    gJiminyCharacterKairiLine20German, gJiminyCharacterKairiLine21German, gJiminyCharacterKairiLine22German,
};

const JiminyTextChar* gJiminyCharacterKairiLinesItalian[17] = {
    gJiminyCharacterKairiLine0Italian, gJiminyCharacterKairiLine1Italian, gJiminyCharacterKairiLine2Italian, gJiminyCharacterKairiLine3Italian,
    gJiminyCharacterKairiLine4Italian, gJiminyCharacterKairiLine5Italian, gJiminyCharacterKairiLine6Italian, gJiminyCharacterKairiLine7Italian,
    gJiminyCharacterKairiLine8Italian, gJiminyCharacterKairiLine9Italian, gJiminyCharacterKairiLine10Italian, gJiminyCharacterKairiLine11Italian,
    gJiminyCharacterKairiLine12Italian, gJiminyCharacterKairiLine13Italian, gJiminyCharacterKairiLine14Italian, gJiminyCharacterKairiLine15Italian,
    gJiminyCharacterKairiLine16Italian,
};

const JiminyTextChar* gJiminyCharacterKairiLinesSpanish[16] = {
    gJiminyCharacterKairiLine0Spanish, gJiminyCharacterKairiLine1Spanish, gJiminyCharacterKairiLine2Spanish, gJiminyCharacterKairiLine3Spanish,
    gJiminyCharacterKairiLine4Spanish, gJiminyCharacterKairiLine5Spanish, gJiminyCharacterKairiLine6Spanish, gJiminyCharacterKairiLine7Spanish,
    gJiminyCharacterKairiLine8Spanish, gJiminyCharacterKairiLine9Spanish, gJiminyCharacterKairiLine10Spanish, gJiminyCharacterKairiLine11Spanish,
    gJiminyCharacterKairiLine12Spanish, gJiminyCharacterKairiLine13Spanish, gJiminyCharacterKairiLine14Spanish, gJiminyCharacterKairiLine15Spanish,
};

const JiminyTextChar* gJiminyCharacterSimbaLines[7] = {
    gJiminyCharacterSimbaLine0, gJiminyCharacterSimbaLine1, gJiminyCharacterSimbaLine2, gJiminyCharacterSimbaLine3,
    gJiminyCharacterSimbaLine4, gJiminyCharacterSimbaLine5, gJiminyCharacterSimbaLine6,
};

const JiminyTextChar* gJiminyCharacterSimbaLinesFrench[8] = {
    gJiminyCharacterSimbaLine0French, gJiminyCharacterSimbaLine1French, gJiminyCharacterSimbaLine2French, gJiminyCharacterSimbaLine3French,
    gJiminyCharacterSimbaLine4French, gJiminyCharacterSimbaLine5French, gJiminyCharacterSimbaLine6French, gJiminyCharacterSimbaLine7French,
};

const JiminyTextChar* gJiminyCharacterSimbaLinesGerman[9] = {
    gJiminyCharacterSimbaLine0German, gJiminyCharacterSimbaLine1German, gJiminyCharacterSimbaLine2German, gJiminyCharacterSimbaLine3German,
    gJiminyCharacterSimbaLine4German, gJiminyCharacterSimbaLine5German, gJiminyCharacterSimbaLine6German, gJiminyCharacterSimbaLine7German,
    gJiminyCharacterSimbaLine8German,
};

const JiminyTextChar* gJiminyCharacterSimbaLinesItalian[7] = {
    gJiminyCharacterSimbaLine0Italian, gJiminyCharacterSimbaLine1Italian, gJiminyCharacterSimbaLine2Italian, gJiminyCharacterSimbaLine3Italian,
    gJiminyCharacterSimbaLine4Italian, gJiminyCharacterSimbaLine5Italian, gJiminyCharacterSimbaLine6Italian,
};

const JiminyTextChar* gJiminyCharacterSimbaLinesSpanish[7] = {
    gJiminyCharacterSimbaLine0Spanish, gJiminyCharacterSimbaLine1Spanish, gJiminyCharacterSimbaLine2Spanish, gJiminyCharacterSimbaLine3Spanish,
    gJiminyCharacterSimbaLine4Spanish, gJiminyCharacterSimbaLine5Spanish, gJiminyCharacterSimbaLine6Spanish,
};

const JiminyTextChar* gJiminyCharacterDumboLines[11] = {
    gJiminyCharacterDumboLine0, gJiminyCharacterDumboLine1, gJiminyCharacterDumboLine2, gJiminyCharacterDumboLine3,
    gJiminyCharacterDumboLine4, gJiminyCharacterDumboLine5, gJiminyCharacterDumboLine6, gJiminyCharacterDumboLine7,
    gJiminyCharacterDumboLine8, gJiminyCharacterDumboLine9, gJiminyCharacterDumboLine10,
};

const JiminyTextChar* gJiminyCharacterDumboLinesFrench[13] = {
    gJiminyCharacterDumboLine0French, gJiminyCharacterDumboLine1French, gJiminyCharacterDumboLine2French, gJiminyCharacterDumboLine3French,
    gJiminyCharacterDumboLine4French, gJiminyCharacterDumboLine5French, gJiminyCharacterDumboLine6French, gJiminyCharacterDumboLine7French,
    gJiminyCharacterDumboLine8French, gJiminyCharacterDumboLine9French, gJiminyCharacterDumboLine10French, gJiminyCharacterDumboLine11French,
    gJiminyCharacterDumboLine12French,
};

const JiminyTextChar* gJiminyCharacterDumboLinesGerman[15] = {
    gJiminyCharacterDumboLine0German, gJiminyCharacterDumboLine1German, gJiminyCharacterDumboLine2German, gJiminyCharacterDumboLine3German,
    gJiminyCharacterDumboLine4German, gJiminyCharacterDumboLine5German, gJiminyCharacterDumboLine6German, gJiminyCharacterDumboLine7German,
    gJiminyCharacterDumboLine8German, gJiminyCharacterDumboLine9German, gJiminyCharacterDumboLine10German, gJiminyCharacterDumboLine11German,
    gJiminyCharacterDumboLine12German, gJiminyCharacterDumboLine13German, gJiminyCharacterDumboLine14German,
};

const JiminyTextChar* gJiminyCharacterDumboLinesItalian[12] = {
    gJiminyCharacterDumboLine0Italian, gJiminyCharacterDumboLine1Italian, gJiminyCharacterDumboLine2Italian, gJiminyCharacterDumboLine3Italian,
    gJiminyCharacterDumboLine4Italian, gJiminyCharacterDumboLine5Italian, gJiminyCharacterDumboLine6Italian, gJiminyCharacterDumboLine7Italian,
    gJiminyCharacterDumboLine8Italian, gJiminyCharacterDumboLine9Italian, gJiminyCharacterDumboLine10Italian, gJiminyCharacterDumboLine11Italian,
};

const JiminyTextChar* gJiminyCharacterDumboLinesSpanish[12] = {
    gJiminyCharacterDumboLine0Spanish, gJiminyCharacterDumboLine1Spanish, gJiminyCharacterDumboLine2Spanish, gJiminyCharacterDumboLine3Spanish,
    gJiminyCharacterDumboLine4Spanish, gJiminyCharacterDumboLine5Spanish, gJiminyCharacterDumboLine6Spanish, gJiminyCharacterDumboLine7Spanish,
    gJiminyCharacterDumboLine8Spanish, gJiminyCharacterDumboLine9Spanish, gJiminyCharacterDumboLine10Spanish, gJiminyCharacterDumboLine11Spanish,
};

const JiminyTextChar* gJiminyCharacterBambiLines[6] = {
    gJiminyCharacterBambiLine0, gJiminyCharacterBambiLine1, gJiminyCharacterBambiLine2, gJiminyCharacterBambiLine3,
    gJiminyCharacterBambiLine4, gJiminyCharacterBambiLine5,
};

const JiminyTextChar* gJiminyCharacterBambiLinesFrench[7] = {
    gJiminyCharacterBambiLine0French, gJiminyCharacterBambiLine1French, gJiminyCharacterBambiLine2French, gJiminyCharacterBambiLine3French,
    gJiminyCharacterBambiLine4French, gJiminyCharacterBambiLine5French, gJiminyCharacterBambiLine6French,
};

const JiminyTextChar* gJiminyCharacterBambiLinesGerman[7] = {
    gJiminyCharacterBambiLine0German, gJiminyCharacterBambiLine1German, gJiminyCharacterBambiLine2German, gJiminyCharacterBambiLine3German,
    gJiminyCharacterBambiLine4German, gJiminyCharacterBambiLine5German, gJiminyCharacterBambiLine6German,
};

const JiminyTextChar* gJiminyCharacterBambiLinesItalian[7] = {
    gJiminyCharacterBambiLine0Italian, gJiminyCharacterBambiLine1Italian, gJiminyCharacterBambiLine2Italian, gJiminyCharacterBambiLine3Italian,
    gJiminyCharacterBambiLine4Italian, gJiminyCharacterBambiLine5Italian, gJiminyCharacterBambiLine6Italian,
};

const JiminyTextChar* gJiminyCharacterBambiLinesSpanish[6] = {
    gJiminyCharacterBambiLine0Spanish, gJiminyCharacterBambiLine1Spanish, gJiminyCharacterBambiLine2Spanish, gJiminyCharacterBambiLine3Spanish,
    gJiminyCharacterBambiLine4Spanish, gJiminyCharacterBambiLine5Spanish,
};

const JiminyTextChar* gJiminyCharacterMushuLines[8] = {
    gJiminyCharacterMushuLine0, gJiminyCharacterMushuLine1, gJiminyCharacterMushuLine2, gJiminyCharacterMushuLine3,
    gJiminyCharacterMushuLine4, gJiminyCharacterMushuLine5, gJiminyCharacterMushuLine6, gJiminyCharacterMushuLine7,
};

const JiminyTextChar* gJiminyCharacterMushuLinesFrench[9] = {
    gJiminyCharacterMushuLine0French, gJiminyCharacterMushuLine1French, gJiminyCharacterMushuLine2French, gJiminyCharacterMushuLine3French,
    gJiminyCharacterMushuLine4French, gJiminyCharacterMushuLine5French, gJiminyCharacterMushuLine6French, gJiminyCharacterMushuLine7French,
    gJiminyCharacterMushuLine8French,
};

const JiminyTextChar* gJiminyCharacterMushuLinesGerman[10] = {
    gJiminyCharacterMushuLine0German, gJiminyCharacterMushuLine1German, gJiminyCharacterMushuLine2German, gJiminyCharacterMushuLine3German,
    gJiminyCharacterMushuLine4German, gJiminyCharacterMushuLine5German, gJiminyCharacterMushuLine6German, gJiminyCharacterMushuLine7German,
    gJiminyCharacterMushuLine8German, gJiminyCharacterMushuLine9German,
};

const JiminyTextChar* gJiminyCharacterMushuLinesItalian[11] = {
    gJiminyCharacterMushuLine0Italian, gJiminyCharacterMushuLine1Italian, gJiminyCharacterMushuLine2Italian, gJiminyCharacterMushuLine3Italian,
    gJiminyCharacterMushuLine4Italian, gJiminyCharacterMushuLine5Italian, gJiminyCharacterMushuLine6Italian, gJiminyCharacterMushuLine7Italian,
    gJiminyCharacterMushuLine8Italian, gJiminyCharacterMushuLine9Italian, gJiminyCharacterMushuLine10Italian,
};

const JiminyTextChar* gJiminyCharacterMushuLinesSpanish[8] = {
    gJiminyCharacterMushuLine0Spanish, gJiminyCharacterMushuLine1Spanish, gJiminyCharacterMushuLine2Spanish, gJiminyCharacterMushuLine3Spanish,
    gJiminyCharacterMushuLine4Spanish, gJiminyCharacterMushuLine5Spanish, gJiminyCharacterMushuLine6Spanish, gJiminyCharacterMushuLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterMooglesLines[8] = {
    gJiminyCharacterMooglesLine0, gJiminyCharacterMooglesLine1, gJiminyCharacterMooglesLine2, gJiminyCharacterMooglesLine3,
    gJiminyCharacterMooglesLine4, gJiminyCharacterMooglesLine5, gJiminyCharacterMooglesLine6, gJiminyCharacterMooglesLine7,
};

const JiminyTextChar* gJiminyCharacterMooglesLinesFrench[11] = {
    gJiminyCharacterMooglesLine0French, gJiminyCharacterMooglesLine1French, gJiminyCharacterMooglesLine2French, gJiminyCharacterMooglesLine3French,
    gJiminyCharacterMooglesLine4French, gJiminyCharacterMooglesLine5French, gJiminyCharacterMooglesLine6French, gJiminyCharacterMooglesLine7French,
    gJiminyCharacterMooglesLine8French, gJiminyCharacterMooglesLine9French, gJiminyCharacterMooglesLine10French,
};

const JiminyTextChar* gJiminyCharacterMooglesLinesGerman[9] = {
    gJiminyCharacterMooglesLine0German, gJiminyCharacterMooglesLine1German, gJiminyCharacterMooglesLine2German, gJiminyCharacterMooglesLine3German,
    gJiminyCharacterMooglesLine4German, gJiminyCharacterMooglesLine5German, gJiminyCharacterMooglesLine6German, gJiminyCharacterMooglesLine7German,
    gJiminyCharacterMooglesLine8German,
};

const JiminyTextChar* gJiminyCharacterMooglesLinesItalian[8] = {
    gJiminyCharacterMooglesLine0Italian, gJiminyCharacterMooglesLine1Italian, gJiminyCharacterMooglesLine2Italian, gJiminyCharacterMooglesLine3Italian,
    gJiminyCharacterMooglesLine4Italian, gJiminyCharacterMooglesLine5Italian, gJiminyCharacterMooglesLine6Italian, gJiminyCharacterMooglesLine7Italian,
};

const JiminyTextChar* gJiminyCharacterMooglesLinesSpanish[10] = {
    gJiminyCharacterMooglesLine0Spanish, gJiminyCharacterMooglesLine1Spanish, gJiminyCharacterMooglesLine2Spanish, gJiminyCharacterMooglesLine3Spanish,
    gJiminyCharacterMooglesLine4Spanish, gJiminyCharacterMooglesLine5Spanish, gJiminyCharacterMooglesLine6Spanish, gJiminyCharacterMooglesLine7Spanish,
    gJiminyCharacterMooglesLine8Spanish, gJiminyCharacterMooglesLine9Spanish,
};

const JiminyTextChar* gJiminyCharacterLeonLines[13] = {
    gJiminyCharacterLeonLine0, gJiminyCharacterLeonLine1, gJiminyCharacterLeonLine2, gJiminyCharacterLeonLine3,
    gJiminyCharacterLeonLine4, gJiminyCharacterLeonLine5, gJiminyCharacterLeonLine6, gJiminyCharacterLeonLine7,
    gJiminyCharacterLeonLine8, gJiminyCharacterLeonLine9, gJiminyCharacterLeonLine10, gJiminyCharacterLeonLine11,
    gJiminyCharacterLeonLine12,
};

const JiminyTextChar* gJiminyCharacterLeonLinesFrench[12] = {
    gJiminyCharacterLeonLine0French, gJiminyCharacterLeonLine1French, gJiminyCharacterLeonLine2French, gJiminyCharacterLeonLine3French,
    gJiminyCharacterLeonLine4French, gJiminyCharacterLeonLine5French, gJiminyCharacterLeonLine6French, gJiminyCharacterLeonLine7French,
    gJiminyCharacterLeonLine8French, gJiminyCharacterLeonLine9French, gJiminyCharacterLeonLine10French, gJiminyCharacterLeonLine11French,
};

const JiminyTextChar* gJiminyCharacterLeonLinesGerman[17] = {
    gJiminyCharacterLeonLine0German, gJiminyCharacterLeonLine1German, gJiminyCharacterLeonLine2German, gJiminyCharacterLeonLine3German,
    gJiminyCharacterLeonLine4German, gJiminyCharacterLeonLine5German, gJiminyCharacterLeonLine6German, gJiminyCharacterLeonLine7German,
    gJiminyCharacterLeonLine8German, gJiminyCharacterLeonLine9German, gJiminyCharacterLeonLine10German, gJiminyCharacterLeonLine11German,
    gJiminyCharacterLeonLine12German, gJiminyCharacterLeonLine13German, gJiminyCharacterLeonLine14German, gJiminyCharacterLeonLine15German,
    gJiminyCharacterLeonLine16German,
};

const JiminyTextChar* gJiminyCharacterLeonLinesItalian[16] = {
    gJiminyCharacterLeonLine0Italian, gJiminyCharacterLeonLine1Italian, gJiminyCharacterLeonLine2Italian, gJiminyCharacterLeonLine3Italian,
    gJiminyCharacterLeonLine4Italian, gJiminyCharacterLeonLine5Italian, gJiminyCharacterLeonLine6Italian, gJiminyCharacterLeonLine7Italian,
    gJiminyCharacterLeonLine8Italian, gJiminyCharacterLeonLine9Italian, gJiminyCharacterLeonLine10Italian, gJiminyCharacterLeonLine11Italian,
    gJiminyCharacterLeonLine12Italian, gJiminyCharacterLeonLine13Italian, gJiminyCharacterLeonLine14Italian, gJiminyCharacterLeonLine15Italian,
};

const JiminyTextChar* gJiminyCharacterLeonLinesSpanish[14] = {
    gJiminyCharacterLeonLine0Spanish, gJiminyCharacterLeonLine1Spanish, gJiminyCharacterLeonLine2Spanish, gJiminyCharacterLeonLine3Spanish,
    gJiminyCharacterLeonLine4Spanish, gJiminyCharacterLeonLine5Spanish, gJiminyCharacterLeonLine6Spanish, gJiminyCharacterLeonLine7Spanish,
    gJiminyCharacterLeonLine8Spanish, gJiminyCharacterLeonLine9Spanish, gJiminyCharacterLeonLine10Spanish, gJiminyCharacterLeonLine11Spanish,
    gJiminyCharacterLeonLine12Spanish, gJiminyCharacterLeonLine13Spanish,
};

const JiminyTextChar* gJiminyCharacterYuffieLines[11] = {
    gJiminyCharacterYuffieLine0, gJiminyCharacterYuffieLine1, gJiminyCharacterYuffieLine2, gJiminyCharacterYuffieLine3,
    gJiminyCharacterYuffieLine4, gJiminyCharacterYuffieLine5, gJiminyCharacterYuffieLine6, gJiminyCharacterYuffieLine7,
    gJiminyCharacterYuffieLine8, gJiminyCharacterYuffieLine9, gJiminyCharacterYuffieLine10,
};

const JiminyTextChar* gJiminyCharacterYuffieLinesFrench[13] = {
    gJiminyCharacterYuffieLine0French, gJiminyCharacterYuffieLine1French, gJiminyCharacterYuffieLine2French, gJiminyCharacterYuffieLine3French,
    gJiminyCharacterYuffieLine4French, gJiminyCharacterYuffieLine5French, gJiminyCharacterYuffieLine6French, gJiminyCharacterYuffieLine7French,
    gJiminyCharacterYuffieLine8French, gJiminyCharacterYuffieLine9French, gJiminyCharacterYuffieLine10French, gJiminyCharacterYuffieLine11French,
    gJiminyCharacterYuffieLine12French,
};

const JiminyTextChar* gJiminyCharacterYuffieLinesGerman[13] = {
    gJiminyCharacterYuffieLine0German, gJiminyCharacterYuffieLine1German, gJiminyCharacterYuffieLine2German, gJiminyCharacterYuffieLine3German,
    gJiminyCharacterYuffieLine4German, gJiminyCharacterYuffieLine5German, gJiminyCharacterYuffieLine6German, gJiminyCharacterYuffieLine7German,
    gJiminyCharacterYuffieLine8German, gJiminyCharacterYuffieLine9German, gJiminyCharacterYuffieLine10German, gJiminyCharacterYuffieLine11German,
    gJiminyCharacterYuffieLine12German,
};

const JiminyTextChar* gJiminyCharacterYuffieLinesItalian[11] = {
    gJiminyCharacterYuffieLine0Italian, gJiminyCharacterYuffieLine1Italian, gJiminyCharacterYuffieLine2Italian, gJiminyCharacterYuffieLine3Italian,
    gJiminyCharacterYuffieLine4Italian, gJiminyCharacterYuffieLine5Italian, gJiminyCharacterYuffieLine6Italian, gJiminyCharacterYuffieLine7Italian,
    gJiminyCharacterYuffieLine8Italian, gJiminyCharacterYuffieLine9Italian, gJiminyCharacterYuffieLine10Italian,
};

const JiminyTextChar* gJiminyCharacterYuffieLinesSpanish[11] = {
    gJiminyCharacterYuffieLine0Spanish, gJiminyCharacterYuffieLine1Spanish, gJiminyCharacterYuffieLine2Spanish, gJiminyCharacterYuffieLine3Spanish,
    gJiminyCharacterYuffieLine4Spanish, gJiminyCharacterYuffieLine5Spanish, gJiminyCharacterYuffieLine6Spanish, gJiminyCharacterYuffieLine7Spanish,
    gJiminyCharacterYuffieLine8Spanish, gJiminyCharacterYuffieLine9Spanish, gJiminyCharacterYuffieLine10Spanish,
};

const JiminyTextChar* gJiminyCharacterAerithLines[12] = {
    gJiminyCharacterAerithLine0, gJiminyCharacterAerithLine1, gJiminyCharacterAerithLine2, gJiminyCharacterAerithLine3,
    gJiminyCharacterAerithLine4, gJiminyCharacterAerithLine5, gJiminyCharacterAerithLine6, gJiminyCharacterAerithLine7,
    gJiminyCharacterAerithLine8, gJiminyCharacterAerithLine9, gJiminyCharacterAerithLine10, gJiminyCharacterAerithLine11,
};

const JiminyTextChar* gJiminyCharacterAerithLinesFrench[12] = {
    gJiminyCharacterAerithLine0French, gJiminyCharacterAerithLine1French, gJiminyCharacterAerithLine2French, gJiminyCharacterAerithLine3French,
    gJiminyCharacterAerithLine4French, gJiminyCharacterAerithLine5French, gJiminyCharacterAerithLine6French, gJiminyCharacterAerithLine7French,
    gJiminyCharacterAerithLine8French, gJiminyCharacterAerithLine9French, gJiminyCharacterAerithLine10French, gJiminyCharacterAerithLine11French,
};

const JiminyTextChar* gJiminyCharacterAerithLinesGerman[16] = {
    gJiminyCharacterAerithLine0German, gJiminyCharacterAerithLine1German, gJiminyCharacterAerithLine2German, gJiminyCharacterAerithLine3German,
    gJiminyCharacterAerithLine4German, gJiminyCharacterAerithLine5German, gJiminyCharacterAerithLine6German, gJiminyCharacterAerithLine7German,
    gJiminyCharacterAerithLine8German, gJiminyCharacterAerithLine9German, gJiminyCharacterAerithLine10German, gJiminyCharacterAerithLine11German,
    gJiminyCharacterAerithLine12German, gJiminyCharacterAerithLine13German, gJiminyCharacterAerithLine14German, gJiminyCharacterAerithLine15German,
};

const JiminyTextChar* gJiminyCharacterAerithLinesItalian[14] = {
    gJiminyCharacterAerithLine0Italian, gJiminyCharacterAerithLine1Italian, gJiminyCharacterAerithLine2Italian, gJiminyCharacterAerithLine3Italian,
    gJiminyCharacterAerithLine4Italian, gJiminyCharacterAerithLine5Italian, gJiminyCharacterAerithLine6Italian, gJiminyCharacterAerithLine7Italian,
    gJiminyCharacterAerithLine8Italian, gJiminyCharacterAerithLine9Italian, gJiminyCharacterAerithLine10Italian, gJiminyCharacterAerithLine11Italian,
    gJiminyCharacterAerithLine12Italian, gJiminyCharacterAerithLine13Italian,
};

const JiminyTextChar* gJiminyCharacterAerithLinesSpanish[12] = {
    gJiminyCharacterAerithLine0Spanish, gJiminyCharacterAerithLine1Spanish, gJiminyCharacterAerithLine2Spanish, gJiminyCharacterAerithLine3Spanish,
    gJiminyCharacterAerithLine4Spanish, gJiminyCharacterAerithLine5Spanish, gJiminyCharacterAerithLine6Spanish, gJiminyCharacterAerithLine7Spanish,
    gJiminyCharacterAerithLine8Spanish, gJiminyCharacterAerithLine9Spanish, gJiminyCharacterAerithLine10Spanish, gJiminyCharacterAerithLine11Spanish,
};

const JiminyTextChar* gJiminyCharacterCidLines[8] = {
    gJiminyCharacterCidLine0, gJiminyCharacterCidLine1, gJiminyCharacterCidLine2, gJiminyCharacterCidLine3,
    gJiminyCharacterCidLine4, gJiminyCharacterCidLine5, gJiminyCharacterCidLine6, gJiminyCharacterCidLine7,
};

const JiminyTextChar* gJiminyCharacterCidLinesFrench[8] = {
    gJiminyCharacterCidLine0French, gJiminyCharacterCidLine1French, gJiminyCharacterCidLine2French, gJiminyCharacterCidLine3French,
    gJiminyCharacterCidLine4French, gJiminyCharacterCidLine5French, gJiminyCharacterCidLine6French, gJiminyCharacterCidLine7French,
};

const JiminyTextChar* gJiminyCharacterCidLinesGerman[9] = {
    gJiminyCharacterCidLine0German, gJiminyCharacterCidLine1German, gJiminyCharacterCidLine2German, gJiminyCharacterCidLine3German,
    gJiminyCharacterCidLine4German, gJiminyCharacterCidLine5German, gJiminyCharacterCidLine6German, gJiminyCharacterCidLine7German,
    gJiminyCharacterCidLine8German,
};

const JiminyTextChar* gJiminyCharacterCidLinesItalian[7] = {
    gJiminyCharacterCidLine0Italian, gJiminyCharacterCidLine1Italian, gJiminyCharacterCidLine2Italian, gJiminyCharacterCidLine3Italian,
    gJiminyCharacterCidLine4Italian, gJiminyCharacterCidLine5Italian, gJiminyCharacterCidLine6Italian,
};

const JiminyTextChar* gJiminyCharacterCidLinesSpanish[8] = {
    gJiminyCharacterCidLine0Spanish, gJiminyCharacterCidLine1Spanish, gJiminyCharacterCidLine2Spanish, gJiminyCharacterCidLine3Spanish,
    gJiminyCharacterCidLine4Spanish, gJiminyCharacterCidLine5Spanish, gJiminyCharacterCidLine6Spanish, gJiminyCharacterCidLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterCloudLines[10] = {
    gJiminyCharacterCloudLine0, gJiminyCharacterCloudLine1, gJiminyCharacterCloudLine2, gJiminyCharacterCloudLine3,
    gJiminyCharacterCloudLine4, gJiminyCharacterCloudLine5, gJiminyCharacterCloudLine6, gJiminyCharacterCloudLine7,
    gJiminyCharacterCloudLine8, gJiminyCharacterCloudLine9,
};

const JiminyTextChar* gJiminyCharacterCloudLinesFrench[12] = {
    gJiminyCharacterCloudLine0French, gJiminyCharacterCloudLine1French, gJiminyCharacterCloudLine2French, gJiminyCharacterCloudLine3French,
    gJiminyCharacterCloudLine4French, gJiminyCharacterCloudLine5French, gJiminyCharacterCloudLine6French, gJiminyCharacterCloudLine7French,
    gJiminyCharacterCloudLine8French, gJiminyCharacterCloudLine9French, gJiminyCharacterCloudLine10French, gJiminyCharacterCloudLine11French,
};

const JiminyTextChar* gJiminyCharacterCloudLinesGerman[15] = {
    gJiminyCharacterCloudLine0German, gJiminyCharacterCloudLine1German, gJiminyCharacterCloudLine2German, gJiminyCharacterCloudLine3German,
    gJiminyCharacterCloudLine4German, gJiminyCharacterCloudLine5German, gJiminyCharacterCloudLine6German, gJiminyCharacterCloudLine7German,
    gJiminyCharacterCloudLine8German, gJiminyCharacterCloudLine9German, gJiminyCharacterCloudLine10German, gJiminyCharacterCloudLine11German,
    gJiminyCharacterCloudLine12German, gJiminyCharacterCloudLine13German, gJiminyCharacterCloudLine14German,
};

const JiminyTextChar* gJiminyCharacterCloudLinesItalian[11] = {
    gJiminyCharacterCloudLine0Italian, gJiminyCharacterCloudLine1Italian, gJiminyCharacterCloudLine2Italian, gJiminyCharacterCloudLine3Italian,
    gJiminyCharacterCloudLine4Italian, gJiminyCharacterCloudLine5Italian, gJiminyCharacterCloudLine6Italian, gJiminyCharacterCloudLine7Italian,
    gJiminyCharacterCloudLine8Italian, gJiminyCharacterCloudLine9Italian, gJiminyCharacterCloudLine10Italian,
};

const JiminyTextChar* gJiminyCharacterCloudLinesSpanish[10] = {
    gJiminyCharacterCloudLine0Spanish, gJiminyCharacterCloudLine1Spanish, gJiminyCharacterCloudLine2Spanish, gJiminyCharacterCloudLine3Spanish,
    gJiminyCharacterCloudLine4Spanish, gJiminyCharacterCloudLine5Spanish, gJiminyCharacterCloudLine6Spanish, gJiminyCharacterCloudLine7Spanish,
    gJiminyCharacterCloudLine8Spanish, gJiminyCharacterCloudLine9Spanish,
};

const JiminyTextChar* gJiminyCharacterTidusLines[9] = {
    gJiminyCharacterTidusLine0, gJiminyCharacterTidusLine1, gJiminyCharacterTidusLine2, gJiminyCharacterTidusLine3,
    gJiminyCharacterTidusLine4, gJiminyCharacterTidusLine5, gJiminyCharacterTidusLine6, gJiminyCharacterTidusLine7,
    gJiminyCharacterTidusLine8,
};

const JiminyTextChar* gJiminyCharacterTidusLinesFrench[9] = {
    gJiminyCharacterTidusLine0French, gJiminyCharacterTidusLine1French, gJiminyCharacterTidusLine2French, gJiminyCharacterTidusLine3French,
    gJiminyCharacterTidusLine4French, gJiminyCharacterTidusLine5French, gJiminyCharacterTidusLine6French, gJiminyCharacterTidusLine7French,
    gJiminyCharacterTidusLine8French,
};

const JiminyTextChar* gJiminyCharacterTidusLinesGerman[10] = {
    gJiminyCharacterTidusLine0German, gJiminyCharacterTidusLine1German, gJiminyCharacterTidusLine2German, gJiminyCharacterTidusLine3German,
    gJiminyCharacterTidusLine4German, gJiminyCharacterTidusLine5German, gJiminyCharacterTidusLine6German, gJiminyCharacterTidusLine7German,
    gJiminyCharacterTidusLine8German, gJiminyCharacterTidusLine9German,
};

const JiminyTextChar* gJiminyCharacterTidusLinesItalian[8] = {
    gJiminyCharacterTidusLine0Italian, gJiminyCharacterTidusLine1Italian, gJiminyCharacterTidusLine2Italian, gJiminyCharacterTidusLine3Italian,
    gJiminyCharacterTidusLine4Italian, gJiminyCharacterTidusLine5Italian, gJiminyCharacterTidusLine6Italian, gJiminyCharacterTidusLine7Italian,
};

const JiminyTextChar* gJiminyCharacterTidusLinesSpanish[9] = {
    gJiminyCharacterTidusLine0Spanish, gJiminyCharacterTidusLine1Spanish, gJiminyCharacterTidusLine2Spanish, gJiminyCharacterTidusLine3Spanish,
    gJiminyCharacterTidusLine4Spanish, gJiminyCharacterTidusLine5Spanish, gJiminyCharacterTidusLine6Spanish, gJiminyCharacterTidusLine7Spanish,
    gJiminyCharacterTidusLine8Spanish,
};

const JiminyTextChar* gJiminyCharacterWakkaLines[7] = {
    gJiminyCharacterWakkaLine0, gJiminyCharacterWakkaLine1, gJiminyCharacterWakkaLine2, gJiminyCharacterWakkaLine3,
    gJiminyCharacterWakkaLine4, gJiminyCharacterWakkaLine5, gJiminyCharacterWakkaLine6,
};

const JiminyTextChar* gJiminyCharacterWakkaLinesFrench[8] = {
    gJiminyCharacterWakkaLine0French, gJiminyCharacterWakkaLine1French, gJiminyCharacterWakkaLine2French, gJiminyCharacterWakkaLine3French,
    gJiminyCharacterWakkaLine4French, gJiminyCharacterWakkaLine5French, gJiminyCharacterWakkaLine6French, gJiminyCharacterWakkaLine7French,
};

const JiminyTextChar* gJiminyCharacterWakkaLinesGerman[8] = {
    gJiminyCharacterWakkaLine0German, gJiminyCharacterWakkaLine1German, gJiminyCharacterWakkaLine2German, gJiminyCharacterWakkaLine3German,
    gJiminyCharacterWakkaLine4German, gJiminyCharacterWakkaLine5German, gJiminyCharacterWakkaLine6German, gJiminyCharacterWakkaLine7German,
};

const JiminyTextChar* gJiminyCharacterWakkaLinesItalian[7] = {
    gJiminyCharacterWakkaLine0Italian, gJiminyCharacterWakkaLine1Italian, gJiminyCharacterWakkaLine2Italian, gJiminyCharacterWakkaLine3Italian,
    gJiminyCharacterWakkaLine4Italian, gJiminyCharacterWakkaLine5Italian, gJiminyCharacterWakkaLine6Italian,
};

const JiminyTextChar* gJiminyCharacterWakkaLinesSpanish[7] = {
    gJiminyCharacterWakkaLine0Spanish, gJiminyCharacterWakkaLine1Spanish, gJiminyCharacterWakkaLine2Spanish, gJiminyCharacterWakkaLine3Spanish,
    gJiminyCharacterWakkaLine4Spanish, gJiminyCharacterWakkaLine5Spanish, gJiminyCharacterWakkaLine6Spanish,
};

const JiminyTextChar* gJiminyCharacterSelphieLines[8] = {
    gJiminyCharacterSelphieLine0, gJiminyCharacterSelphieLine1, gJiminyCharacterSelphieLine2, gJiminyCharacterSelphieLine3,
    gJiminyCharacterSelphieLine4, gJiminyCharacterSelphieLine5, gJiminyCharacterSelphieLine6, gJiminyCharacterSelphieLine7,
};

const JiminyTextChar* gJiminyCharacterSelphieLinesFrench[7] = {
    gJiminyCharacterSelphieLine0French, gJiminyCharacterSelphieLine1French, gJiminyCharacterSelphieLine2French, gJiminyCharacterSelphieLine3French,
    gJiminyCharacterSelphieLine4French, gJiminyCharacterSelphieLine5French, gJiminyCharacterSelphieLine6French,
};

const JiminyTextChar* gJiminyCharacterSelphieLinesGerman[8] = {
    gJiminyCharacterSelphieLine0German, gJiminyCharacterSelphieLine1German, gJiminyCharacterSelphieLine2German, gJiminyCharacterSelphieLine3German,
    gJiminyCharacterSelphieLine4German, gJiminyCharacterSelphieLine5German, gJiminyCharacterSelphieLine6German, gJiminyCharacterSelphieLine7German,
};

const JiminyTextChar* gJiminyCharacterSelphieLinesItalian[8] = {
    gJiminyCharacterSelphieLine0Italian, gJiminyCharacterSelphieLine1Italian, gJiminyCharacterSelphieLine2Italian, gJiminyCharacterSelphieLine3Italian,
    gJiminyCharacterSelphieLine4Italian, gJiminyCharacterSelphieLine5Italian, gJiminyCharacterSelphieLine6Italian, gJiminyCharacterSelphieLine7Italian,
};

const JiminyTextChar* gJiminyCharacterSelphieLinesSpanish[8] = {
    gJiminyCharacterSelphieLine0Spanish, gJiminyCharacterSelphieLine1Spanish, gJiminyCharacterSelphieLine2Spanish, gJiminyCharacterSelphieLine3Spanish,
    gJiminyCharacterSelphieLine4Spanish, gJiminyCharacterSelphieLine5Spanish, gJiminyCharacterSelphieLine6Spanish, gJiminyCharacterSelphieLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterNamineLines[15] = {
    gJiminyCharacterNamineLine0, gJiminyCharacterNamineLine1, gJiminyCharacterNamineLine2, gJiminyCharacterNamineLine3,
    gJiminyCharacterNamineLine4, gJiminyCharacterNamineLine5, gJiminyCharacterNamineLine6, gJiminyCharacterNamineLine7,
    gJiminyCharacterNamineLine8, gJiminyCharacterNamineLine9, gJiminyCharacterNamineLine10, gJiminyCharacterNamineLine11,
    gJiminyCharacterNamineLine12, gJiminyCharacterNamineLine13, gJiminyCharacterNamineLine14,
};

const JiminyTextChar* gJiminyCharacterNamineLinesFrench[16] = {
    gJiminyCharacterNamineLine0French, gJiminyCharacterNamineLine1French, gJiminyCharacterNamineLine2French, gJiminyCharacterNamineLine3French,
    gJiminyCharacterNamineLine4French, gJiminyCharacterNamineLine5French, gJiminyCharacterNamineLine6French, gJiminyCharacterNamineLine7French,
    gJiminyCharacterNamineLine8French, gJiminyCharacterNamineLine9French, gJiminyCharacterNamineLine10French, gJiminyCharacterNamineLine11French,
    gJiminyCharacterNamineLine12French, gJiminyCharacterNamineLine13French, gJiminyCharacterNamineLine14French, gJiminyCharacterNamineLine15French,
};

const JiminyTextChar* gJiminyCharacterNamineLinesGerman[19] = {
    gJiminyCharacterNamineLine0German, gJiminyCharacterNamineLine1German, gJiminyCharacterNamineLine2German, gJiminyCharacterNamineLine3German,
    gJiminyCharacterNamineLine4German, gJiminyCharacterNamineLine5German, gJiminyCharacterNamineLine6German, gJiminyCharacterNamineLine7German,
    gJiminyCharacterNamineLine8German, gJiminyCharacterNamineLine9German, gJiminyCharacterNamineLine10German, gJiminyCharacterNamineLine11German,
    gJiminyCharacterNamineLine12German, gJiminyCharacterNamineLine13German, gJiminyCharacterNamineLine14German, gJiminyCharacterNamineLine15German,
    gJiminyCharacterNamineLine16German, gJiminyCharacterNamineLine17German, gJiminyCharacterNamineLine18German,
};

const JiminyTextChar* gJiminyCharacterNamineLinesItalian[13] = {
    gJiminyCharacterNamineLine0Italian, gJiminyCharacterNamineLine1Italian, gJiminyCharacterNamineLine2Italian, gJiminyCharacterNamineLine3Italian,
    gJiminyCharacterNamineLine4Italian, gJiminyCharacterNamineLine5Italian, gJiminyCharacterNamineLine6Italian, gJiminyCharacterNamineLine7Italian,
    gJiminyCharacterNamineLine8Italian, gJiminyCharacterNamineLine9Italian, gJiminyCharacterNamineLine10Italian, gJiminyCharacterNamineLine11Italian,
    gJiminyCharacterNamineLine12Italian,
};

const JiminyTextChar* gJiminyCharacterNamineLinesSpanish[15] = {
    gJiminyCharacterNamineLine0Spanish, gJiminyCharacterNamineLine1Spanish, gJiminyCharacterNamineLine2Spanish, gJiminyCharacterNamineLine3Spanish,
    gJiminyCharacterNamineLine4Spanish, gJiminyCharacterNamineLine5Spanish, gJiminyCharacterNamineLine6Spanish, gJiminyCharacterNamineLine7Spanish,
    gJiminyCharacterNamineLine8Spanish, gJiminyCharacterNamineLine9Spanish, gJiminyCharacterNamineLine10Spanish, gJiminyCharacterNamineLine11Spanish,
    gJiminyCharacterNamineLine12Spanish, gJiminyCharacterNamineLine13Spanish, gJiminyCharacterNamineLine14Spanish,
};

const JiminyTextChar* gJiminyCharacterRikuReplicaLines[12] = {
    gJiminyCharacterRikuReplicaLine0, gJiminyCharacterRikuReplicaLine1, gJiminyCharacterRikuReplicaLine2, gJiminyCharacterRikuReplicaLine3,
    gJiminyCharacterRikuReplicaLine4, gJiminyCharacterRikuReplicaLine5, gJiminyCharacterRikuReplicaLine6, gJiminyCharacterRikuReplicaLine7,
    gJiminyCharacterRikuReplicaLine8, gJiminyCharacterRikuReplicaLine9, gJiminyCharacterRikuReplicaLine10, gJiminyCharacterRikuReplicaLine11,
};

const JiminyTextChar* gJiminyCharacterRikuReplicaLinesFrench[14] = {
    gJiminyCharacterRikuReplicaLine0French, gJiminyCharacterRikuReplicaLine1French, gJiminyCharacterRikuReplicaLine2French, gJiminyCharacterRikuReplicaLine3French,
    gJiminyCharacterRikuReplicaLine4French, gJiminyCharacterRikuReplicaLine5French, gJiminyCharacterRikuReplicaLine6French, gJiminyCharacterRikuReplicaLine7French,
    gJiminyCharacterRikuReplicaLine8French, gJiminyCharacterRikuReplicaLine9French, gJiminyCharacterRikuReplicaLine10French, gJiminyCharacterRikuReplicaLine11French,
    gJiminyCharacterRikuReplicaLine12French, gJiminyCharacterRikuReplicaLine13French,
};

const JiminyTextChar* gJiminyCharacterRikuReplicaLinesGerman[13] = {
    gJiminyCharacterRikuReplicaLine0German, gJiminyCharacterRikuReplicaLine1German, gJiminyCharacterRikuReplicaLine2German, gJiminyCharacterRikuReplicaLine3German,
    gJiminyCharacterRikuReplicaLine4German, gJiminyCharacterRikuReplicaLine5German, gJiminyCharacterRikuReplicaLine6German, gJiminyCharacterRikuReplicaLine7German,
    gJiminyCharacterRikuReplicaLine8German, gJiminyCharacterRikuReplicaLine9German, gJiminyCharacterRikuReplicaLine10German, gJiminyCharacterRikuReplicaLine11German,
    gJiminyCharacterRikuReplicaLine12German,
};

const JiminyTextChar* gJiminyCharacterRikuReplicaLinesItalian[12] = {
    gJiminyCharacterRikuReplicaLine0Italian, gJiminyCharacterRikuReplicaLine1Italian, gJiminyCharacterRikuReplicaLine2Italian, gJiminyCharacterRikuReplicaLine3Italian,
    gJiminyCharacterRikuReplicaLine4Italian, gJiminyCharacterRikuReplicaLine5Italian, gJiminyCharacterRikuReplicaLine6Italian, gJiminyCharacterRikuReplicaLine7Italian,
    gJiminyCharacterRikuReplicaLine8Italian, gJiminyCharacterRikuReplicaLine9Italian, gJiminyCharacterRikuReplicaLine10Italian, gJiminyCharacterRikuReplicaLine11Italian,
};

const JiminyTextChar* gJiminyCharacterRikuReplicaLinesSpanish[13] = {
    gJiminyCharacterRikuReplicaLine0Spanish, gJiminyCharacterRikuReplicaLine1Spanish, gJiminyCharacterRikuReplicaLine2Spanish, gJiminyCharacterRikuReplicaLine3Spanish,
    gJiminyCharacterRikuReplicaLine4Spanish, gJiminyCharacterRikuReplicaLine5Spanish, gJiminyCharacterRikuReplicaLine6Spanish, gJiminyCharacterRikuReplicaLine7Spanish,
    gJiminyCharacterRikuReplicaLine8Spanish, gJiminyCharacterRikuReplicaLine9Spanish, gJiminyCharacterRikuReplicaLine10Spanish, gJiminyCharacterRikuReplicaLine11Spanish,
    gJiminyCharacterRikuReplicaLine12Spanish,
};

const JiminyTextChar* gJiminyCharacterAxelLines[11] = {
    gJiminyCharacterAxelLine0, gJiminyCharacterAxelLine1, gJiminyCharacterAxelLine2, gJiminyCharacterAxelLine3,
    gJiminyCharacterAxelLine4, gJiminyCharacterAxelLine5, gJiminyCharacterAxelLine6, gJiminyCharacterAxelLine7,
    gJiminyCharacterAxelLine8, gJiminyCharacterAxelLine9, gJiminyCharacterAxelLine10,
};

const JiminyTextChar* gJiminyCharacterAxelLinesFrench[12] = {
    gJiminyCharacterAxelLine0French, gJiminyCharacterAxelLine1French, gJiminyCharacterAxelLine2French, gJiminyCharacterAxelLine3French,
    gJiminyCharacterAxelLine4French, gJiminyCharacterAxelLine5French, gJiminyCharacterAxelLine6French, gJiminyCharacterAxelLine7French,
    gJiminyCharacterAxelLine8French, gJiminyCharacterAxelLine9French, gJiminyCharacterAxelLine10French, gJiminyCharacterAxelLine11French,
};

const JiminyTextChar* gJiminyCharacterAxelLinesGerman[12] = {
    gJiminyCharacterAxelLine0German, gJiminyCharacterAxelLine1German, gJiminyCharacterAxelLine2German, gJiminyCharacterAxelLine3German,
    gJiminyCharacterAxelLine4German, gJiminyCharacterAxelLine5German, gJiminyCharacterAxelLine6German, gJiminyCharacterAxelLine7German,
    gJiminyCharacterAxelLine8German, gJiminyCharacterAxelLine9German, gJiminyCharacterAxelLine10German, gJiminyCharacterAxelLine11German,
};

const JiminyTextChar* gJiminyCharacterAxelLinesItalian[12] = {
    gJiminyCharacterAxelLine0Italian, gJiminyCharacterAxelLine1Italian, gJiminyCharacterAxelLine2Italian, gJiminyCharacterAxelLine3Italian,
    gJiminyCharacterAxelLine4Italian, gJiminyCharacterAxelLine5Italian, gJiminyCharacterAxelLine6Italian, gJiminyCharacterAxelLine7Italian,
    gJiminyCharacterAxelLine8Italian, gJiminyCharacterAxelLine9Italian, gJiminyCharacterAxelLine10Italian, gJiminyCharacterAxelLine11Italian,
};

const JiminyTextChar* gJiminyCharacterAxelLinesSpanish[11] = {
    gJiminyCharacterAxelLine0Spanish, gJiminyCharacterAxelLine1Spanish, gJiminyCharacterAxelLine2Spanish, gJiminyCharacterAxelLine3Spanish,
    gJiminyCharacterAxelLine4Spanish, gJiminyCharacterAxelLine5Spanish, gJiminyCharacterAxelLine6Spanish, gJiminyCharacterAxelLine7Spanish,
    gJiminyCharacterAxelLine8Spanish, gJiminyCharacterAxelLine9Spanish, gJiminyCharacterAxelLine10Spanish,
};

const JiminyTextChar* gJiminyCharacterLarxeneLines[13] = {
    gJiminyCharacterLarxeneLine0, gJiminyCharacterLarxeneLine1, gJiminyCharacterLarxeneLine2, gJiminyCharacterLarxeneLine3,
    gJiminyCharacterLarxeneLine4, gJiminyCharacterLarxeneLine5, gJiminyCharacterLarxeneLine6, gJiminyCharacterLarxeneLine7,
    gJiminyCharacterLarxeneLine8, gJiminyCharacterLarxeneLine9, gJiminyCharacterLarxeneLine10, gJiminyCharacterLarxeneLine11,
    gJiminyCharacterLarxeneLine12,
};

const JiminyTextChar* gJiminyCharacterLarxeneLinesFrench[12] = {
    gJiminyCharacterLarxeneLine0French, gJiminyCharacterLarxeneLine1French, gJiminyCharacterLarxeneLine2French, gJiminyCharacterLarxeneLine3French,
    gJiminyCharacterLarxeneLine4French, gJiminyCharacterLarxeneLine5French, gJiminyCharacterLarxeneLine6French, gJiminyCharacterLarxeneLine7French,
    gJiminyCharacterLarxeneLine8French, gJiminyCharacterLarxeneLine9French, gJiminyCharacterLarxeneLine10French, gJiminyCharacterLarxeneLine11French,
};

const JiminyTextChar* gJiminyCharacterLarxeneLinesGerman[14] = {
    gJiminyCharacterLarxeneLine0German, gJiminyCharacterLarxeneLine1German, gJiminyCharacterLarxeneLine2German, gJiminyCharacterLarxeneLine3German,
    gJiminyCharacterLarxeneLine4German, gJiminyCharacterLarxeneLine5German, gJiminyCharacterLarxeneLine6German, gJiminyCharacterLarxeneLine7German,
    gJiminyCharacterLarxeneLine8German, gJiminyCharacterLarxeneLine9German, gJiminyCharacterLarxeneLine10German, gJiminyCharacterLarxeneLine11German,
    gJiminyCharacterLarxeneLine12German, gJiminyCharacterLarxeneLine13German,
};

const JiminyTextChar* gJiminyCharacterLarxeneLinesItalian[13] = {
    gJiminyCharacterLarxeneLine0Italian, gJiminyCharacterLarxeneLine1Italian, gJiminyCharacterLarxeneLine2Italian, gJiminyCharacterLarxeneLine3Italian,
    gJiminyCharacterLarxeneLine4Italian, gJiminyCharacterLarxeneLine5Italian, gJiminyCharacterLarxeneLine6Italian, gJiminyCharacterLarxeneLine7Italian,
    gJiminyCharacterLarxeneLine8Italian, gJiminyCharacterLarxeneLine9Italian, gJiminyCharacterLarxeneLine10Italian, gJiminyCharacterLarxeneLine11Italian,
    gJiminyCharacterLarxeneLine12Italian,
};

const JiminyTextChar* gJiminyCharacterLarxeneLinesSpanish[13] = {
    gJiminyCharacterLarxeneLine0Spanish, gJiminyCharacterLarxeneLine1Spanish, gJiminyCharacterLarxeneLine2Spanish, gJiminyCharacterLarxeneLine3Spanish,
    gJiminyCharacterLarxeneLine4Spanish, gJiminyCharacterLarxeneLine5Spanish, gJiminyCharacterLarxeneLine6Spanish, gJiminyCharacterLarxeneLine7Spanish,
    gJiminyCharacterLarxeneLine8Spanish, gJiminyCharacterLarxeneLine9Spanish, gJiminyCharacterLarxeneLine10Spanish, gJiminyCharacterLarxeneLine11Spanish,
    gJiminyCharacterLarxeneLine12Spanish,
};

const JiminyTextChar* gJiminyCharacterVexenLines[11] = {
    gJiminyCharacterVexenLine0, gJiminyCharacterVexenLine1, gJiminyCharacterVexenLine2, gJiminyCharacterVexenLine3,
    gJiminyCharacterVexenLine4, gJiminyCharacterVexenLine5, gJiminyCharacterVexenLine6, gJiminyCharacterVexenLine7,
    gJiminyCharacterVexenLine8, gJiminyCharacterVexenLine9, gJiminyCharacterVexenLine10,
};

const JiminyTextChar* gJiminyCharacterVexenLinesFrench[12] = {
    gJiminyCharacterVexenLine0French, gJiminyCharacterVexenLine1French, gJiminyCharacterVexenLine2French, gJiminyCharacterVexenLine3French,
    gJiminyCharacterVexenLine4French, gJiminyCharacterVexenLine5French, gJiminyCharacterVexenLine6French, gJiminyCharacterVexenLine7French,
    gJiminyCharacterVexenLine8French, gJiminyCharacterVexenLine9French, gJiminyCharacterVexenLine10French, gJiminyCharacterVexenLine11French,
};

const JiminyTextChar* gJiminyCharacterVexenLinesGerman[14] = {
    gJiminyCharacterVexenLine0German, gJiminyCharacterVexenLine1German, gJiminyCharacterVexenLine2German, gJiminyCharacterVexenLine3German,
    gJiminyCharacterVexenLine4German, gJiminyCharacterVexenLine5German, gJiminyCharacterVexenLine6German, gJiminyCharacterVexenLine7German,
    gJiminyCharacterVexenLine8German, gJiminyCharacterVexenLine9German, gJiminyCharacterVexenLine10German, gJiminyCharacterVexenLine11German,
    gJiminyCharacterVexenLine12German, gJiminyCharacterVexenLine13German,
};

const JiminyTextChar* gJiminyCharacterVexenLinesItalian[14] = {
    gJiminyCharacterVexenLine0Italian, gJiminyCharacterVexenLine1Italian, gJiminyCharacterVexenLine2Italian, gJiminyCharacterVexenLine3Italian,
    gJiminyCharacterVexenLine4Italian, gJiminyCharacterVexenLine5Italian, gJiminyCharacterVexenLine6Italian, gJiminyCharacterVexenLine7Italian,
    gJiminyCharacterVexenLine8Italian, gJiminyCharacterVexenLine9Italian, gJiminyCharacterVexenLine10Italian, gJiminyCharacterVexenLine11Italian,
    gJiminyCharacterVexenLine12Italian, gJiminyCharacterVexenLine13Italian,
};

const JiminyTextChar* gJiminyCharacterVexenLinesSpanish[10] = {
    gJiminyCharacterVexenLine0Spanish, gJiminyCharacterVexenLine1Spanish, gJiminyCharacterVexenLine2Spanish, gJiminyCharacterVexenLine3Spanish,
    gJiminyCharacterVexenLine4Spanish, gJiminyCharacterVexenLine5Spanish, gJiminyCharacterVexenLine6Spanish, gJiminyCharacterVexenLine7Spanish,
    gJiminyCharacterVexenLine8Spanish, gJiminyCharacterVexenLine9Spanish,
};

const JiminyTextChar* gJiminyCharacterMarluxiaLines[10] = {
    gJiminyCharacterMarluxiaLine0, gJiminyCharacterMarluxiaLine1, gJiminyCharacterMarluxiaLine2, gJiminyCharacterMarluxiaLine3,
    gJiminyCharacterMarluxiaLine4, gJiminyCharacterMarluxiaLine5, gJiminyCharacterMarluxiaLine6, gJiminyCharacterMarluxiaLine7,
    gJiminyCharacterMarluxiaLine8, gJiminyCharacterMarluxiaLine9,
};

const JiminyTextChar* gJiminyCharacterMarluxiaLinesFrench[11] = {
    gJiminyCharacterMarluxiaLine0French, gJiminyCharacterMarluxiaLine1French, gJiminyCharacterMarluxiaLine2French, gJiminyCharacterMarluxiaLine3French,
    gJiminyCharacterMarluxiaLine4French, gJiminyCharacterMarluxiaLine5French, gJiminyCharacterMarluxiaLine6French, gJiminyCharacterMarluxiaLine7French,
    gJiminyCharacterMarluxiaLine8French, gJiminyCharacterMarluxiaLine9French, gJiminyCharacterMarluxiaLine10French,
};

const JiminyTextChar* gJiminyCharacterMarluxiaLinesGerman[14] = {
    gJiminyCharacterMarluxiaLine0German, gJiminyCharacterMarluxiaLine1German, gJiminyCharacterMarluxiaLine2German, gJiminyCharacterMarluxiaLine3German,
    gJiminyCharacterMarluxiaLine4German, gJiminyCharacterMarluxiaLine5German, gJiminyCharacterMarluxiaLine6German, gJiminyCharacterMarluxiaLine7German,
    gJiminyCharacterMarluxiaLine8German, gJiminyCharacterMarluxiaLine9German, gJiminyCharacterMarluxiaLine10German, gJiminyCharacterMarluxiaLine11German,
    gJiminyCharacterMarluxiaLine12German, gJiminyCharacterMarluxiaLine13German,
};

const JiminyTextChar* gJiminyCharacterMarluxiaLinesItalian[11] = {
    gJiminyCharacterMarluxiaLine0Italian, gJiminyCharacterMarluxiaLine1Italian, gJiminyCharacterMarluxiaLine2Italian, gJiminyCharacterMarluxiaLine3Italian,
    gJiminyCharacterMarluxiaLine4Italian, gJiminyCharacterMarluxiaLine5Italian, gJiminyCharacterMarluxiaLine6Italian, gJiminyCharacterMarluxiaLine7Italian,
    gJiminyCharacterMarluxiaLine8Italian, gJiminyCharacterMarluxiaLine9Italian, gJiminyCharacterMarluxiaLine10Italian,
};

const JiminyTextChar* gJiminyCharacterMarluxiaLinesSpanish[11] = {
    gJiminyCharacterMarluxiaLine0Spanish, gJiminyCharacterMarluxiaLine1Spanish, gJiminyCharacterMarluxiaLine2Spanish, gJiminyCharacterMarluxiaLine3Spanish,
    gJiminyCharacterMarluxiaLine4Spanish, gJiminyCharacterMarluxiaLine5Spanish, gJiminyCharacterMarluxiaLine6Spanish, gJiminyCharacterMarluxiaLine7Spanish,
    gJiminyCharacterMarluxiaLine8Spanish, gJiminyCharacterMarluxiaLine9Spanish, gJiminyCharacterMarluxiaLine10Spanish,
};

const JiminyTextChar* gJiminyCharacterAladdinLines[16] = {
    gJiminyCharacterAladdinLine0, gJiminyCharacterAladdinLine1, gJiminyCharacterAladdinLine2, gJiminyCharacterAladdinLine3,
    gJiminyCharacterAladdinLine4, gJiminyCharacterAladdinLine5, gJiminyCharacterAladdinLine6, gJiminyCharacterAladdinLine7,
    gJiminyCharacterAladdinLine8, gJiminyCharacterAladdinLine9, gJiminyCharacterAladdinLine10, gJiminyCharacterAladdinLine11,
    gJiminyCharacterAladdinLine12, gJiminyCharacterAladdinLine13, gJiminyCharacterAladdinLine14, gJiminyCharacterAladdinLine15,
};

const JiminyTextChar* gJiminyCharacterAladdinLinesFrench[19] = {
    gJiminyCharacterAladdinLine0French, gJiminyCharacterAladdinLine1French, gJiminyCharacterAladdinLine2French, gJiminyCharacterAladdinLine3French,
    gJiminyCharacterAladdinLine4French, gJiminyCharacterAladdinLine5French, gJiminyCharacterAladdinLine6French, gJiminyCharacterAladdinLine7French,
    gJiminyCharacterAladdinLine8French, gJiminyCharacterAladdinLine9French, gJiminyCharacterAladdinLine10French, gJiminyCharacterAladdinLine11French,
    gJiminyCharacterAladdinLine12French, gJiminyCharacterAladdinLine13French, gJiminyCharacterAladdinLine14French, gJiminyCharacterAladdinLine15French,
    gJiminyCharacterAladdinLine16French, gJiminyCharacterAladdinLine17French, gJiminyCharacterAladdinLine18French,
};

const JiminyTextChar* gJiminyCharacterAladdinLinesGerman[19] = {
    gJiminyCharacterAladdinLine0German, gJiminyCharacterAladdinLine1German, gJiminyCharacterAladdinLine2German, gJiminyCharacterAladdinLine3German,
    gJiminyCharacterAladdinLine4German, gJiminyCharacterAladdinLine5German, gJiminyCharacterAladdinLine6German, gJiminyCharacterAladdinLine7German,
    gJiminyCharacterAladdinLine8German, gJiminyCharacterAladdinLine9German, gJiminyCharacterAladdinLine10German, gJiminyCharacterAladdinLine11German,
    gJiminyCharacterAladdinLine12German, gJiminyCharacterAladdinLine13German, gJiminyCharacterAladdinLine14German, gJiminyCharacterAladdinLine15German,
    gJiminyCharacterAladdinLine16German, gJiminyCharacterAladdinLine17German, gJiminyCharacterAladdinLine18German,
};

const JiminyTextChar* gJiminyCharacterAladdinLinesItalian[19] = {
    gJiminyCharacterAladdinLine0Italian, gJiminyCharacterAladdinLine1Italian, gJiminyCharacterAladdinLine2Italian, gJiminyCharacterAladdinLine3Italian,
    gJiminyCharacterAladdinLine4Italian, gJiminyCharacterAladdinLine5Italian, gJiminyCharacterAladdinLine6Italian, gJiminyCharacterAladdinLine7Italian,
    gJiminyCharacterAladdinLine8Italian, gJiminyCharacterAladdinLine9Italian, gJiminyCharacterAladdinLine10Italian, gJiminyCharacterAladdinLine11Italian,
    gJiminyCharacterAladdinLine12Italian, gJiminyCharacterAladdinLine13Italian, gJiminyCharacterAladdinLine14Italian, gJiminyCharacterAladdinLine15Italian,
    gJiminyCharacterAladdinLine16Italian, gJiminyCharacterAladdinLine17Italian, gJiminyCharacterAladdinLine18Italian,
};

const JiminyTextChar* gJiminyCharacterAladdinLinesSpanish[16] = {
    gJiminyCharacterAladdinLine0Spanish, gJiminyCharacterAladdinLine1Spanish, gJiminyCharacterAladdinLine2Spanish, gJiminyCharacterAladdinLine3Spanish,
    gJiminyCharacterAladdinLine4Spanish, gJiminyCharacterAladdinLine5Spanish, gJiminyCharacterAladdinLine6Spanish, gJiminyCharacterAladdinLine7Spanish,
    gJiminyCharacterAladdinLine8Spanish, gJiminyCharacterAladdinLine9Spanish, gJiminyCharacterAladdinLine10Spanish, gJiminyCharacterAladdinLine11Spanish,
    gJiminyCharacterAladdinLine12Spanish, gJiminyCharacterAladdinLine13Spanish, gJiminyCharacterAladdinLine14Spanish, gJiminyCharacterAladdinLine15Spanish,
};

const JiminyTextChar* gJiminyCharacterGenieLines[11] = {
    gJiminyCharacterGenieLine0, gJiminyCharacterGenieLine1, gJiminyCharacterGenieLine2, gJiminyCharacterGenieLine3,
    gJiminyCharacterGenieLine4, gJiminyCharacterGenieLine5, gJiminyCharacterGenieLine6, gJiminyCharacterGenieLine7,
    gJiminyCharacterGenieLine8, gJiminyCharacterGenieLine9, gJiminyCharacterGenieLine10,
};

const JiminyTextChar* gJiminyCharacterGenieLinesFrench[13] = {
    gJiminyCharacterGenieLine0French, gJiminyCharacterGenieLine1French, gJiminyCharacterGenieLine2French, gJiminyCharacterGenieLine3French,
    gJiminyCharacterGenieLine4French, gJiminyCharacterGenieLine5French, gJiminyCharacterGenieLine6French, gJiminyCharacterGenieLine7French,
    gJiminyCharacterGenieLine8French, gJiminyCharacterGenieLine9French, gJiminyCharacterGenieLine10French, gJiminyCharacterGenieLine11French,
    gJiminyCharacterGenieLine12French,
};

const JiminyTextChar* gJiminyCharacterGenieLinesGerman[14] = {
    gJiminyCharacterGenieLine0German, gJiminyCharacterGenieLine1German, gJiminyCharacterGenieLine2German, gJiminyCharacterGenieLine3German,
    gJiminyCharacterGenieLine4German, gJiminyCharacterGenieLine5German, gJiminyCharacterGenieLine6German, gJiminyCharacterGenieLine7German,
    gJiminyCharacterGenieLine8German, gJiminyCharacterGenieLine9German, gJiminyCharacterGenieLine10German, gJiminyCharacterGenieLine11German,
    gJiminyCharacterGenieLine12German, gJiminyCharacterGenieLine13German,
};

const JiminyTextChar* gJiminyCharacterGenieLinesItalian[14] = {
    gJiminyCharacterGenieLine0Italian, gJiminyCharacterGenieLine1Italian, gJiminyCharacterGenieLine2Italian, gJiminyCharacterGenieLine3Italian,
    gJiminyCharacterGenieLine4Italian, gJiminyCharacterGenieLine5Italian, gJiminyCharacterGenieLine6Italian, gJiminyCharacterGenieLine7Italian,
    gJiminyCharacterGenieLine8Italian, gJiminyCharacterGenieLine9Italian, gJiminyCharacterGenieLine10Italian, gJiminyCharacterGenieLine11Italian,
    gJiminyCharacterGenieLine12Italian, gJiminyCharacterGenieLine13Italian,
};

const JiminyTextChar* gJiminyCharacterGenieLinesSpanish[13] = {
    gJiminyCharacterGenieLine0Spanish, gJiminyCharacterGenieLine1Spanish, gJiminyCharacterGenieLine2Spanish, gJiminyCharacterGenieLine3Spanish,
    gJiminyCharacterGenieLine4Spanish, gJiminyCharacterGenieLine5Spanish, gJiminyCharacterGenieLine6Spanish, gJiminyCharacterGenieLine7Spanish,
    gJiminyCharacterGenieLine8Spanish, gJiminyCharacterGenieLine9Spanish, gJiminyCharacterGenieLine10Spanish, gJiminyCharacterGenieLine11Spanish,
    gJiminyCharacterGenieLine12Spanish,
};

const JiminyTextChar* gJiminyCharacterJasmineLines[6] = {
    gJiminyCharacterJasmineLine0, gJiminyCharacterJasmineLine1, gJiminyCharacterJasmineLine2, gJiminyCharacterJasmineLine3,
    gJiminyCharacterJasmineLine4, gJiminyCharacterJasmineLine5,
};

const JiminyTextChar* gJiminyCharacterJasmineLinesFrench[6] = {
    gJiminyCharacterJasmineLine0French, gJiminyCharacterJasmineLine1French, gJiminyCharacterJasmineLine2French, gJiminyCharacterJasmineLine3French,
    gJiminyCharacterJasmineLine4French, gJiminyCharacterJasmineLine5French,
};

const JiminyTextChar* gJiminyCharacterJasmineLinesGerman[7] = {
    gJiminyCharacterJasmineLine0German, gJiminyCharacterJasmineLine1German, gJiminyCharacterJasmineLine2German, gJiminyCharacterJasmineLine3German,
    gJiminyCharacterJasmineLine4German, gJiminyCharacterJasmineLine5German, gJiminyCharacterJasmineLine6German,
};

const JiminyTextChar* gJiminyCharacterJasmineLinesItalian[7] = {
    gJiminyCharacterJasmineLine0Italian, gJiminyCharacterJasmineLine1Italian, gJiminyCharacterJasmineLine2Italian, gJiminyCharacterJasmineLine3Italian,
    gJiminyCharacterJasmineLine4Italian, gJiminyCharacterJasmineLine5Italian, gJiminyCharacterJasmineLine6Italian,
};

const JiminyTextChar* gJiminyCharacterJasmineLinesSpanish[6] = {
    gJiminyCharacterJasmineLine0Spanish, gJiminyCharacterJasmineLine1Spanish, gJiminyCharacterJasmineLine2Spanish, gJiminyCharacterJasmineLine3Spanish,
    gJiminyCharacterJasmineLine4Spanish, gJiminyCharacterJasmineLine5Spanish,
};

const JiminyTextChar* gJiminyCharacterIagoLines[7] = {
    gJiminyCharacterIagoLine0, gJiminyCharacterIagoLine1, gJiminyCharacterIagoLine2, gJiminyCharacterIagoLine3,
    gJiminyCharacterIagoLine4, gJiminyCharacterIagoLine5, gJiminyCharacterIagoLine6,
};

const JiminyTextChar* gJiminyCharacterIagoLinesFrench[6] = {
    gJiminyCharacterIagoLine0French, gJiminyCharacterIagoLine1French, gJiminyCharacterIagoLine2French, gJiminyCharacterIagoLine3French,
    gJiminyCharacterIagoLine4French, gJiminyCharacterIagoLine5French,
};

const JiminyTextChar* gJiminyCharacterIagoLinesGerman[7] = {
    gJiminyCharacterIagoLine0German, gJiminyCharacterIagoLine1German, gJiminyCharacterIagoLine2German, gJiminyCharacterIagoLine3German,
    gJiminyCharacterIagoLine4German, gJiminyCharacterIagoLine5German, gJiminyCharacterIagoLine6German,
};

const JiminyTextChar* gJiminyCharacterIagoLinesItalian[7] = {
    gJiminyCharacterIagoLine0Italian, gJiminyCharacterIagoLine1Italian, gJiminyCharacterIagoLine2Italian, gJiminyCharacterIagoLine3Italian,
    gJiminyCharacterIagoLine4Italian, gJiminyCharacterIagoLine5Italian, gJiminyCharacterIagoLine6Italian,
};

const JiminyTextChar* gJiminyCharacterIagoLinesSpanish[7] = {
    gJiminyCharacterIagoLine0Spanish, gJiminyCharacterIagoLine1Spanish, gJiminyCharacterIagoLine2Spanish, gJiminyCharacterIagoLine3Spanish,
    gJiminyCharacterIagoLine4Spanish, gJiminyCharacterIagoLine5Spanish, gJiminyCharacterIagoLine6Spanish,
};

const JiminyTextChar* gJiminyCharacterJafarLines[8] = {
    gJiminyCharacterJafarLine0, gJiminyCharacterJafarLine1, gJiminyCharacterJafarLine2, gJiminyCharacterJafarLine3,
    gJiminyCharacterJafarLine4, gJiminyCharacterJafarLine5, gJiminyCharacterJafarLine6, gJiminyCharacterJafarLine7,
};

const JiminyTextChar* gJiminyCharacterJafarLinesFrench[9] = {
    gJiminyCharacterJafarLine0French, gJiminyCharacterJafarLine1French, gJiminyCharacterJafarLine2French, gJiminyCharacterJafarLine3French,
    gJiminyCharacterJafarLine4French, gJiminyCharacterJafarLine5French, gJiminyCharacterJafarLine6French, gJiminyCharacterJafarLine7French,
    gJiminyCharacterJafarLine8French,
};

const JiminyTextChar* gJiminyCharacterJafarLinesGerman[10] = {
    gJiminyCharacterJafarLine0German, gJiminyCharacterJafarLine1German, gJiminyCharacterJafarLine2German, gJiminyCharacterJafarLine3German,
    gJiminyCharacterJafarLine4German, gJiminyCharacterJafarLine5German, gJiminyCharacterJafarLine6German, gJiminyCharacterJafarLine7German,
    gJiminyCharacterJafarLine8German, gJiminyCharacterJafarLine9German,
};

const JiminyTextChar* gJiminyCharacterJafarLinesItalian[7] = {
    gJiminyCharacterJafarLine0Italian, gJiminyCharacterJafarLine1Italian, gJiminyCharacterJafarLine2Italian, gJiminyCharacterJafarLine3Italian,
    gJiminyCharacterJafarLine4Italian, gJiminyCharacterJafarLine5Italian, gJiminyCharacterJafarLine6Italian,
};

const JiminyTextChar* gJiminyCharacterJafarLinesSpanish[9] = {
    gJiminyCharacterJafarLine0Spanish, gJiminyCharacterJafarLine1Spanish, gJiminyCharacterJafarLine2Spanish, gJiminyCharacterJafarLine3Spanish,
    gJiminyCharacterJafarLine4Spanish, gJiminyCharacterJafarLine5Spanish, gJiminyCharacterJafarLine6Spanish, gJiminyCharacterJafarLine7Spanish,
    gJiminyCharacterJafarLine8Spanish,
};

const JiminyTextChar* gJiminyCharacterJafarGenieLines[7] = {
    gJiminyCharacterJafarGenieLine0, gJiminyCharacterJafarGenieLine1, gJiminyCharacterJafarGenieLine2, gJiminyCharacterJafarGenieLine3,
    gJiminyCharacterJafarGenieLine4, gJiminyCharacterJafarGenieLine5, gJiminyCharacterJafarGenieLine6,
};

const JiminyTextChar* gJiminyCharacterJafarGenieLinesFrench[9] = {
    gJiminyCharacterJafarGenieLine0French, gJiminyCharacterJafarGenieLine1French, gJiminyCharacterJafarGenieLine2French, gJiminyCharacterJafarGenieLine3French,
    gJiminyCharacterJafarGenieLine4French, gJiminyCharacterJafarGenieLine5French, gJiminyCharacterJafarGenieLine6French, gJiminyCharacterJafarGenieLine7French,
    gJiminyCharacterJafarGenieLine8French,
};

const JiminyTextChar* gJiminyCharacterJafarGenieLinesGerman[11] = {
    gJiminyCharacterJafarGenieLine0German, gJiminyCharacterJafarGenieLine1German, gJiminyCharacterJafarGenieLine2German, gJiminyCharacterJafarGenieLine3German,
    gJiminyCharacterJafarGenieLine4German, gJiminyCharacterJafarGenieLine5German, gJiminyCharacterJafarGenieLine6German, gJiminyCharacterJafarGenieLine7German,
    gJiminyCharacterJafarGenieLine8German, gJiminyCharacterJafarGenieLine9German, gJiminyCharacterJafarGenieLine10German,
};

const JiminyTextChar* gJiminyCharacterJafarGenieLinesItalian[9] = {
    gJiminyCharacterJafarGenieLine0Italian, gJiminyCharacterJafarGenieLine1Italian, gJiminyCharacterJafarGenieLine2Italian, gJiminyCharacterJafarGenieLine3Italian,
    gJiminyCharacterJafarGenieLine4Italian, gJiminyCharacterJafarGenieLine5Italian, gJiminyCharacterJafarGenieLine6Italian, gJiminyCharacterJafarGenieLine7Italian,
    gJiminyCharacterJafarGenieLine8Italian,
};

const JiminyTextChar* gJiminyCharacterJafarGenieLinesSpanish[8] = {
    gJiminyCharacterJafarGenieLine0Spanish, gJiminyCharacterJafarGenieLine1Spanish, gJiminyCharacterJafarGenieLine2Spanish, gJiminyCharacterJafarGenieLine3Spanish,
    gJiminyCharacterJafarGenieLine4Spanish, gJiminyCharacterJafarGenieLine5Spanish, gJiminyCharacterJafarGenieLine6Spanish, gJiminyCharacterJafarGenieLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterJackLines[7] = {
    gJiminyCharacterJackLine0, gJiminyCharacterJackLine1, gJiminyCharacterJackLine2, gJiminyCharacterJackLine3,
    gJiminyCharacterJackLine4, gJiminyCharacterJackLine5, gJiminyCharacterJackLine6,
};

const JiminyTextChar* gJiminyCharacterJackLinesFrench[9] = {
    gJiminyCharacterJackLine0French, gJiminyCharacterJackLine1French, gJiminyCharacterJackLine2French, gJiminyCharacterJackLine3French,
    gJiminyCharacterJackLine4French, gJiminyCharacterJackLine5French, gJiminyCharacterJackLine6French, gJiminyCharacterJackLine7French,
    gJiminyCharacterJackLine8French,
};

const JiminyTextChar* gJiminyCharacterJackLinesGerman[8] = {
    gJiminyCharacterJackLine0German, gJiminyCharacterJackLine1German, gJiminyCharacterJackLine2German, gJiminyCharacterJackLine3German,
    gJiminyCharacterJackLine4German, gJiminyCharacterJackLine5German, gJiminyCharacterJackLine6German, gJiminyCharacterJackLine7German,
};

const JiminyTextChar* gJiminyCharacterJackLinesItalian[7] = {
    gJiminyCharacterJackLine0Italian, gJiminyCharacterJackLine1Italian, gJiminyCharacterJackLine2Italian, gJiminyCharacterJackLine3Italian,
    gJiminyCharacterJackLine4Italian, gJiminyCharacterJackLine5Italian, gJiminyCharacterJackLine6Italian,
};

const JiminyTextChar* gJiminyCharacterJackLinesSpanish[7] = {
    gJiminyCharacterJackLine0Spanish, gJiminyCharacterJackLine1Spanish, gJiminyCharacterJackLine2Spanish, gJiminyCharacterJackLine3Spanish,
    gJiminyCharacterJackLine4Spanish, gJiminyCharacterJackLine5Spanish, gJiminyCharacterJackLine6Spanish,
};

const JiminyTextChar* gJiminyCharacterSallyLines[7] = {
    gJiminyCharacterSallyLine0, gJiminyCharacterSallyLine1, gJiminyCharacterSallyLine2, gJiminyCharacterSallyLine3,
    gJiminyCharacterSallyLine4, gJiminyCharacterSallyLine5, gJiminyCharacterSallyLine6,
};

const JiminyTextChar* gJiminyCharacterSallyLinesFrench[7] = {
    gJiminyCharacterSallyLine0French, gJiminyCharacterSallyLine1French, gJiminyCharacterSallyLine2French, gJiminyCharacterSallyLine3French,
    gJiminyCharacterSallyLine4French, gJiminyCharacterSallyLine5French, gJiminyCharacterSallyLine6French,
};

const JiminyTextChar* gJiminyCharacterSallyLinesGerman[8] = {
    gJiminyCharacterSallyLine0German, gJiminyCharacterSallyLine1German, gJiminyCharacterSallyLine2German, gJiminyCharacterSallyLine3German,
    gJiminyCharacterSallyLine4German, gJiminyCharacterSallyLine5German, gJiminyCharacterSallyLine6German, gJiminyCharacterSallyLine7German,
};

const JiminyTextChar* gJiminyCharacterSallyLinesItalian[8] = {
    gJiminyCharacterSallyLine0Italian, gJiminyCharacterSallyLine1Italian, gJiminyCharacterSallyLine2Italian, gJiminyCharacterSallyLine3Italian,
    gJiminyCharacterSallyLine4Italian, gJiminyCharacterSallyLine5Italian, gJiminyCharacterSallyLine6Italian, gJiminyCharacterSallyLine7Italian,
};

const JiminyTextChar* gJiminyCharacterSallyLinesSpanish[7] = {
    gJiminyCharacterSallyLine0Spanish, gJiminyCharacterSallyLine1Spanish, gJiminyCharacterSallyLine2Spanish, gJiminyCharacterSallyLine3Spanish,
    gJiminyCharacterSallyLine4Spanish, gJiminyCharacterSallyLine5Spanish, gJiminyCharacterSallyLine6Spanish,
};

const JiminyTextChar* gJiminyCharacterDrFinkelsteinLines[10] = {
    gJiminyCharacterDrFinkelsteinLine0, gJiminyCharacterDrFinkelsteinLine1, gJiminyCharacterDrFinkelsteinLine2, gJiminyCharacterDrFinkelsteinLine3,
    gJiminyCharacterDrFinkelsteinLine4, gJiminyCharacterDrFinkelsteinLine5, gJiminyCharacterDrFinkelsteinLine6, gJiminyCharacterDrFinkelsteinLine7,
    gJiminyCharacterDrFinkelsteinLine8, gJiminyCharacterDrFinkelsteinLine9,
};

const JiminyTextChar* gJiminyCharacterDrFinkelsteinLinesFrench[12] = {
    gJiminyCharacterDrFinkelsteinLine0French, gJiminyCharacterDrFinkelsteinLine1French, gJiminyCharacterDrFinkelsteinLine2French, gJiminyCharacterDrFinkelsteinLine3French,
    gJiminyCharacterDrFinkelsteinLine4French, gJiminyCharacterDrFinkelsteinLine5French, gJiminyCharacterDrFinkelsteinLine6French, gJiminyCharacterDrFinkelsteinLine7French,
    gJiminyCharacterDrFinkelsteinLine8French, gJiminyCharacterDrFinkelsteinLine9French, gJiminyCharacterDrFinkelsteinLine10French, gJiminyCharacterDrFinkelsteinLine11French,
};

const JiminyTextChar* gJiminyCharacterDrFinkelsteinLinesGerman[16] = {
    gJiminyCharacterDrFinkelsteinLine0German, gJiminyCharacterDrFinkelsteinLine1German, gJiminyCharacterDrFinkelsteinLine2German, gJiminyCharacterDrFinkelsteinLine3German,
    gJiminyCharacterDrFinkelsteinLine4German, gJiminyCharacterDrFinkelsteinLine5German, gJiminyCharacterDrFinkelsteinLine6German, gJiminyCharacterDrFinkelsteinLine7German,
    gJiminyCharacterDrFinkelsteinLine8German, gJiminyCharacterDrFinkelsteinLine9German, gJiminyCharacterDrFinkelsteinLine10German, gJiminyCharacterDrFinkelsteinLine11German,
    gJiminyCharacterDrFinkelsteinLine12German, gJiminyCharacterDrFinkelsteinLine13German, gJiminyCharacterDrFinkelsteinLine14German, gJiminyCharacterDrFinkelsteinLine15German,
};

const JiminyTextChar* gJiminyCharacterDrFinkelsteinLinesItalian[12] = {
    gJiminyCharacterDrFinkelsteinLine0Italian, gJiminyCharacterDrFinkelsteinLine1Italian, gJiminyCharacterDrFinkelsteinLine2Italian, gJiminyCharacterDrFinkelsteinLine3Italian,
    gJiminyCharacterDrFinkelsteinLine4Italian, gJiminyCharacterDrFinkelsteinLine5Italian, gJiminyCharacterDrFinkelsteinLine6Italian, gJiminyCharacterDrFinkelsteinLine7Italian,
    gJiminyCharacterDrFinkelsteinLine8Italian, gJiminyCharacterDrFinkelsteinLine9Italian, gJiminyCharacterDrFinkelsteinLine10Italian, gJiminyCharacterDrFinkelsteinLine11Italian,
};

const JiminyTextChar* gJiminyCharacterDrFinkelsteinLinesSpanish[11] = {
    gJiminyCharacterDrFinkelsteinLine0Spanish, gJiminyCharacterDrFinkelsteinLine1Spanish, gJiminyCharacterDrFinkelsteinLine2Spanish, gJiminyCharacterDrFinkelsteinLine3Spanish,
    gJiminyCharacterDrFinkelsteinLine4Spanish, gJiminyCharacterDrFinkelsteinLine5Spanish, gJiminyCharacterDrFinkelsteinLine6Spanish, gJiminyCharacterDrFinkelsteinLine7Spanish,
    gJiminyCharacterDrFinkelsteinLine8Spanish, gJiminyCharacterDrFinkelsteinLine9Spanish, gJiminyCharacterDrFinkelsteinLine10Spanish,
};

const JiminyTextChar* gJiminyCharacterOogieBoogieLines[9] = {
    gJiminyCharacterOogieBoogieLine0, gJiminyCharacterOogieBoogieLine1, gJiminyCharacterOogieBoogieLine2, gJiminyCharacterOogieBoogieLine3,
    gJiminyCharacterOogieBoogieLine4, gJiminyCharacterOogieBoogieLine5, gJiminyCharacterOogieBoogieLine6, gJiminyCharacterOogieBoogieLine7,
    gJiminyCharacterOogieBoogieLine8,
};

const JiminyTextChar* gJiminyCharacterOogieBoogieLinesFrench[10] = {
    gJiminyCharacterOogieBoogieLine0French, gJiminyCharacterOogieBoogieLine1French, gJiminyCharacterOogieBoogieLine2French, gJiminyCharacterOogieBoogieLine3French,
    gJiminyCharacterOogieBoogieLine4French, gJiminyCharacterOogieBoogieLine5French, gJiminyCharacterOogieBoogieLine6French, gJiminyCharacterOogieBoogieLine7French,
    gJiminyCharacterOogieBoogieLine8French, gJiminyCharacterOogieBoogieLine9French,
};

const JiminyTextChar* gJiminyCharacterOogieBoogieLinesGerman[13] = {
    gJiminyCharacterOogieBoogieLine0German, gJiminyCharacterOogieBoogieLine1German, gJiminyCharacterOogieBoogieLine2German, gJiminyCharacterOogieBoogieLine3German,
    gJiminyCharacterOogieBoogieLine4German, gJiminyCharacterOogieBoogieLine5German, gJiminyCharacterOogieBoogieLine6German, gJiminyCharacterOogieBoogieLine7German,
    gJiminyCharacterOogieBoogieLine8German, gJiminyCharacterOogieBoogieLine9German, gJiminyCharacterOogieBoogieLine10German, gJiminyCharacterOogieBoogieLine11German,
    gJiminyCharacterOogieBoogieLine12German,
};

const JiminyTextChar* gJiminyCharacterOogieBoogieLinesItalian[10] = {
    gJiminyCharacterOogieBoogieLine0Italian, gJiminyCharacterOogieBoogieLine1Italian, gJiminyCharacterOogieBoogieLine2Italian, gJiminyCharacterOogieBoogieLine3Italian,
    gJiminyCharacterOogieBoogieLine4Italian, gJiminyCharacterOogieBoogieLine5Italian, gJiminyCharacterOogieBoogieLine6Italian, gJiminyCharacterOogieBoogieLine7Italian,
    gJiminyCharacterOogieBoogieLine8Italian, gJiminyCharacterOogieBoogieLine9Italian,
};

const JiminyTextChar* gJiminyCharacterOogieBoogieLinesSpanish[8] = {
    gJiminyCharacterOogieBoogieLine0Spanish, gJiminyCharacterOogieBoogieLine1Spanish, gJiminyCharacterOogieBoogieLine2Spanish, gJiminyCharacterOogieBoogieLine3Spanish,
    gJiminyCharacterOogieBoogieLine4Spanish, gJiminyCharacterOogieBoogieLine5Spanish, gJiminyCharacterOogieBoogieLine6Spanish, gJiminyCharacterOogieBoogieLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterPinocchioLines[13] = {
    gJiminyCharacterPinocchioLine0, gJiminyCharacterPinocchioLine1, gJiminyCharacterPinocchioLine2, gJiminyCharacterPinocchioLine3,
    gJiminyCharacterPinocchioLine4, gJiminyCharacterPinocchioLine5, gJiminyCharacterPinocchioLine6, gJiminyCharacterPinocchioLine7,
    gJiminyCharacterPinocchioLine8, gJiminyCharacterPinocchioLine9, gJiminyCharacterPinocchioLine10, gJiminyCharacterPinocchioLine11,
    gJiminyCharacterPinocchioLine12,
};

const JiminyTextChar* gJiminyCharacterPinocchioLinesFrench[16] = {
    gJiminyCharacterPinocchioLine0French, gJiminyCharacterPinocchioLine1French, gJiminyCharacterPinocchioLine2French, gJiminyCharacterPinocchioLine3French,
    gJiminyCharacterPinocchioLine4French, gJiminyCharacterPinocchioLine5French, gJiminyCharacterPinocchioLine6French, gJiminyCharacterPinocchioLine7French,
    gJiminyCharacterPinocchioLine8French, gJiminyCharacterPinocchioLine9French, gJiminyCharacterPinocchioLine10French, gJiminyCharacterPinocchioLine11French,
    gJiminyCharacterPinocchioLine12French, gJiminyCharacterPinocchioLine13French, gJiminyCharacterPinocchioLine14French, gJiminyCharacterPinocchioLine15French,
};

const JiminyTextChar* gJiminyCharacterPinocchioLinesGerman[17] = {
    gJiminyCharacterPinocchioLine0German, gJiminyCharacterPinocchioLine1German, gJiminyCharacterPinocchioLine2German, gJiminyCharacterPinocchioLine3German,
    gJiminyCharacterPinocchioLine4German, gJiminyCharacterPinocchioLine5German, gJiminyCharacterPinocchioLine6German, gJiminyCharacterPinocchioLine7German,
    gJiminyCharacterPinocchioLine8German, gJiminyCharacterPinocchioLine9German, gJiminyCharacterPinocchioLine10German, gJiminyCharacterPinocchioLine11German,
    gJiminyCharacterPinocchioLine12German, gJiminyCharacterPinocchioLine13German, gJiminyCharacterPinocchioLine14German, gJiminyCharacterPinocchioLine15German,
    gJiminyCharacterPinocchioLine16German,
};

const JiminyTextChar* gJiminyCharacterPinocchioLinesItalian[15] = {
    gJiminyCharacterPinocchioLine0Italian, gJiminyCharacterPinocchioLine1Italian, gJiminyCharacterPinocchioLine2Italian, gJiminyCharacterPinocchioLine3Italian,
    gJiminyCharacterPinocchioLine4Italian, gJiminyCharacterPinocchioLine5Italian, gJiminyCharacterPinocchioLine6Italian, gJiminyCharacterPinocchioLine7Italian,
    gJiminyCharacterPinocchioLine8Italian, gJiminyCharacterPinocchioLine9Italian, gJiminyCharacterPinocchioLine10Italian, gJiminyCharacterPinocchioLine11Italian,
    gJiminyCharacterPinocchioLine12Italian, gJiminyCharacterPinocchioLine13Italian, gJiminyCharacterPinocchioLine14Italian,
};

const JiminyTextChar* gJiminyCharacterPinocchioLinesSpanish[13] = {
    gJiminyCharacterPinocchioLine0Spanish, gJiminyCharacterPinocchioLine1Spanish, gJiminyCharacterPinocchioLine2Spanish, gJiminyCharacterPinocchioLine3Spanish,
    gJiminyCharacterPinocchioLine4Spanish, gJiminyCharacterPinocchioLine5Spanish, gJiminyCharacterPinocchioLine6Spanish, gJiminyCharacterPinocchioLine7Spanish,
    gJiminyCharacterPinocchioLine8Spanish, gJiminyCharacterPinocchioLine9Spanish, gJiminyCharacterPinocchioLine10Spanish, gJiminyCharacterPinocchioLine11Spanish,
    gJiminyCharacterPinocchioLine12Spanish,
};

const JiminyTextChar* gJiminyCharacterGeppettoLines[14] = {
    gJiminyCharacterGeppettoLine0, gJiminyCharacterGeppettoLine1, gJiminyCharacterGeppettoLine2, gJiminyCharacterGeppettoLine3,
    gJiminyCharacterGeppettoLine4, gJiminyCharacterGeppettoLine5, gJiminyCharacterGeppettoLine6, gJiminyCharacterGeppettoLine7,
    gJiminyCharacterGeppettoLine8, gJiminyCharacterGeppettoLine9, gJiminyCharacterGeppettoLine10, gJiminyCharacterGeppettoLine11,
    gJiminyCharacterGeppettoLine12, gJiminyCharacterGeppettoLine13,
};

const JiminyTextChar* gJiminyCharacterGeppettoLinesFrench[15] = {
    gJiminyCharacterGeppettoLine0French, gJiminyCharacterGeppettoLine1French, gJiminyCharacterGeppettoLine2French, gJiminyCharacterGeppettoLine3French,
    gJiminyCharacterGeppettoLine4French, gJiminyCharacterGeppettoLine5French, gJiminyCharacterGeppettoLine6French, gJiminyCharacterGeppettoLine7French,
    gJiminyCharacterGeppettoLine8French, gJiminyCharacterGeppettoLine9French, gJiminyCharacterGeppettoLine10French, gJiminyCharacterGeppettoLine11French,
    gJiminyCharacterGeppettoLine12French, gJiminyCharacterGeppettoLine13French, gJiminyCharacterGeppettoLine14French,
};

const JiminyTextChar* gJiminyCharacterGeppettoLinesGerman[17] = {
    gJiminyCharacterGeppettoLine0German, gJiminyCharacterGeppettoLine1German, gJiminyCharacterGeppettoLine2German, gJiminyCharacterGeppettoLine3German,
    gJiminyCharacterGeppettoLine4German, gJiminyCharacterGeppettoLine5German, gJiminyCharacterGeppettoLine6German, gJiminyCharacterGeppettoLine7German,
    gJiminyCharacterGeppettoLine8German, gJiminyCharacterGeppettoLine9German, gJiminyCharacterGeppettoLine10German, gJiminyCharacterGeppettoLine11German,
    gJiminyCharacterGeppettoLine12German, gJiminyCharacterGeppettoLine13German, gJiminyCharacterGeppettoLine14German, gJiminyCharacterGeppettoLine15German,
    gJiminyCharacterGeppettoLine16German,
};

const JiminyTextChar* gJiminyCharacterGeppettoLinesItalian[15] = {
    gJiminyCharacterGeppettoLine0Italian, gJiminyCharacterGeppettoLine1Italian, gJiminyCharacterGeppettoLine2Italian, gJiminyCharacterGeppettoLine3Italian,
    gJiminyCharacterGeppettoLine4Italian, gJiminyCharacterGeppettoLine5Italian, gJiminyCharacterGeppettoLine6Italian, gJiminyCharacterGeppettoLine7Italian,
    gJiminyCharacterGeppettoLine8Italian, gJiminyCharacterGeppettoLine9Italian, gJiminyCharacterGeppettoLine10Italian, gJiminyCharacterGeppettoLine11Italian,
    gJiminyCharacterGeppettoLine12Italian, gJiminyCharacterGeppettoLine13Italian, gJiminyCharacterGeppettoLine14Italian,
};

const JiminyTextChar* gJiminyCharacterGeppettoLinesSpanish[14] = {
    gJiminyCharacterGeppettoLine0Spanish, gJiminyCharacterGeppettoLine1Spanish, gJiminyCharacterGeppettoLine2Spanish, gJiminyCharacterGeppettoLine3Spanish,
    gJiminyCharacterGeppettoLine4Spanish, gJiminyCharacterGeppettoLine5Spanish, gJiminyCharacterGeppettoLine6Spanish, gJiminyCharacterGeppettoLine7Spanish,
    gJiminyCharacterGeppettoLine8Spanish, gJiminyCharacterGeppettoLine9Spanish, gJiminyCharacterGeppettoLine10Spanish, gJiminyCharacterGeppettoLine11Spanish,
    gJiminyCharacterGeppettoLine12Spanish, gJiminyCharacterGeppettoLine13Spanish,
};

const JiminyTextChar* gJiminyCharacterHerculesLines[10] = {
    gJiminyCharacterHerculesLine0, gJiminyCharacterHerculesLine1, gJiminyCharacterHerculesLine2, gJiminyCharacterHerculesLine3,
    gJiminyCharacterHerculesLine4, gJiminyCharacterHerculesLine5, gJiminyCharacterHerculesLine6, gJiminyCharacterHerculesLine7,
    gJiminyCharacterHerculesLine8, gJiminyCharacterHerculesLine9,
};

const JiminyTextChar* gJiminyCharacterHerculesLinesFrench[12] = {
    gJiminyCharacterHerculesLine0French, gJiminyCharacterHerculesLine1French, gJiminyCharacterHerculesLine2French, gJiminyCharacterHerculesLine3French,
    gJiminyCharacterHerculesLine4French, gJiminyCharacterHerculesLine5French, gJiminyCharacterHerculesLine6French, gJiminyCharacterHerculesLine7French,
    gJiminyCharacterHerculesLine8French, gJiminyCharacterHerculesLine9French, gJiminyCharacterHerculesLine10French, gJiminyCharacterHerculesLine11French,
};

const JiminyTextChar* gJiminyCharacterHerculesLinesGerman[12] = {
    gJiminyCharacterHerculesLine0German, gJiminyCharacterHerculesLine1German, gJiminyCharacterHerculesLine2German, gJiminyCharacterHerculesLine3German,
    gJiminyCharacterHerculesLine4German, gJiminyCharacterHerculesLine5German, gJiminyCharacterHerculesLine6German, gJiminyCharacterHerculesLine7German,
    gJiminyCharacterHerculesLine8German, gJiminyCharacterHerculesLine9German, gJiminyCharacterHerculesLine10German, gJiminyCharacterHerculesLine11German,
};

const JiminyTextChar* gJiminyCharacterHerculesLinesItalian[10] = {
    gJiminyCharacterHerculesLine0Italian, gJiminyCharacterHerculesLine1Italian, gJiminyCharacterHerculesLine2Italian, gJiminyCharacterHerculesLine3Italian,
    gJiminyCharacterHerculesLine4Italian, gJiminyCharacterHerculesLine5Italian, gJiminyCharacterHerculesLine6Italian, gJiminyCharacterHerculesLine7Italian,
    gJiminyCharacterHerculesLine8Italian, gJiminyCharacterHerculesLine9Italian,
};

const JiminyTextChar* gJiminyCharacterHerculesLinesSpanish[10] = {
    gJiminyCharacterHerculesLine0Spanish, gJiminyCharacterHerculesLine1Spanish, gJiminyCharacterHerculesLine2Spanish, gJiminyCharacterHerculesLine3Spanish,
    gJiminyCharacterHerculesLine4Spanish, gJiminyCharacterHerculesLine5Spanish, gJiminyCharacterHerculesLine6Spanish, gJiminyCharacterHerculesLine7Spanish,
    gJiminyCharacterHerculesLine8Spanish, gJiminyCharacterHerculesLine9Spanish,
};

const JiminyTextChar* gJiminyCharacterPhiloctetesLines[7] = {
    gJiminyCharacterPhiloctetesLine0, gJiminyCharacterPhiloctetesLine1, gJiminyCharacterPhiloctetesLine2, gJiminyCharacterPhiloctetesLine3,
    gJiminyCharacterPhiloctetesLine4, gJiminyCharacterPhiloctetesLine5, gJiminyCharacterPhiloctetesLine6,
};

const JiminyTextChar* gJiminyCharacterPhiloctetesLinesFrench[7] = {
    gJiminyCharacterPhiloctetesLine0French, gJiminyCharacterPhiloctetesLine1French, gJiminyCharacterPhiloctetesLine2French, gJiminyCharacterPhiloctetesLine3French,
    gJiminyCharacterPhiloctetesLine4French, gJiminyCharacterPhiloctetesLine5French, gJiminyCharacterPhiloctetesLine6French,
};

const JiminyTextChar* gJiminyCharacterPhiloctetesLinesGerman[7] = {
    gJiminyCharacterPhiloctetesLine0German, gJiminyCharacterPhiloctetesLine1German, gJiminyCharacterPhiloctetesLine2German, gJiminyCharacterPhiloctetesLine3German,
    gJiminyCharacterPhiloctetesLine4German, gJiminyCharacterPhiloctetesLine5German, gJiminyCharacterPhiloctetesLine6German,
};

const JiminyTextChar* gJiminyCharacterPhiloctetesLinesItalian[7] = {
    gJiminyCharacterPhiloctetesLine0Italian, gJiminyCharacterPhiloctetesLine1Italian, gJiminyCharacterPhiloctetesLine2Italian, gJiminyCharacterPhiloctetesLine3Italian,
    gJiminyCharacterPhiloctetesLine4Italian, gJiminyCharacterPhiloctetesLine5Italian, gJiminyCharacterPhiloctetesLine6Italian,
};

const JiminyTextChar* gJiminyCharacterPhiloctetesLinesSpanish[7] = {
    gJiminyCharacterPhiloctetesLine0Spanish, gJiminyCharacterPhiloctetesLine1Spanish, gJiminyCharacterPhiloctetesLine2Spanish, gJiminyCharacterPhiloctetesLine3Spanish,
    gJiminyCharacterPhiloctetesLine4Spanish, gJiminyCharacterPhiloctetesLine5Spanish, gJiminyCharacterPhiloctetesLine6Spanish,
};

const JiminyTextChar* gJiminyCharacterHadesLines[9] = {
    gJiminyCharacterHadesLine0, gJiminyCharacterHadesLine1, gJiminyCharacterHadesLine2, gJiminyCharacterHadesLine3,
    gJiminyCharacterHadesLine4, gJiminyCharacterHadesLine5, gJiminyCharacterHadesLine6, gJiminyCharacterHadesLine7,
    gJiminyCharacterHadesLine8,
};

const JiminyTextChar* gJiminyCharacterHadesLinesFrench[8] = {
    gJiminyCharacterHadesLine0French, gJiminyCharacterHadesLine1French, gJiminyCharacterHadesLine2French, gJiminyCharacterHadesLine3French,
    gJiminyCharacterHadesLine4French, gJiminyCharacterHadesLine5French, gJiminyCharacterHadesLine6French, gJiminyCharacterHadesLine7French,
};

const JiminyTextChar* gJiminyCharacterHadesLinesGerman[12] = {
    gJiminyCharacterHadesLine0German, gJiminyCharacterHadesLine1German, gJiminyCharacterHadesLine2German, gJiminyCharacterHadesLine3German,
    gJiminyCharacterHadesLine4German, gJiminyCharacterHadesLine5German, gJiminyCharacterHadesLine6German, gJiminyCharacterHadesLine7German,
    gJiminyCharacterHadesLine8German, gJiminyCharacterHadesLine9German, gJiminyCharacterHadesLine10German, gJiminyCharacterHadesLine11German,
};

const JiminyTextChar* gJiminyCharacterHadesLinesItalian[8] = {
    gJiminyCharacterHadesLine0Italian, gJiminyCharacterHadesLine1Italian, gJiminyCharacterHadesLine2Italian, gJiminyCharacterHadesLine3Italian,
    gJiminyCharacterHadesLine4Italian, gJiminyCharacterHadesLine5Italian, gJiminyCharacterHadesLine6Italian, gJiminyCharacterHadesLine7Italian,
};

const JiminyTextChar* gJiminyCharacterHadesLinesSpanish[9] = {
    gJiminyCharacterHadesLine0Spanish, gJiminyCharacterHadesLine1Spanish, gJiminyCharacterHadesLine2Spanish, gJiminyCharacterHadesLine3Spanish,
    gJiminyCharacterHadesLine4Spanish, gJiminyCharacterHadesLine5Spanish, gJiminyCharacterHadesLine6Spanish, gJiminyCharacterHadesLine7Spanish,
    gJiminyCharacterHadesLine8Spanish,
};

const JiminyTextChar* gJiminyCharacterAliceLines[11] = {
    gJiminyCharacterAliceLine0, gJiminyCharacterAliceLine1, gJiminyCharacterAliceLine2, gJiminyCharacterAliceLine3,
    gJiminyCharacterAliceLine4, gJiminyCharacterAliceLine5, gJiminyCharacterAliceLine6, gJiminyCharacterAliceLine7,
    gJiminyCharacterAliceLine8, gJiminyCharacterAliceLine9, gJiminyCharacterAliceLine10,
};

const JiminyTextChar* gJiminyCharacterAliceLinesFrench[13] = {
    gJiminyCharacterAliceLine0French, gJiminyCharacterAliceLine1French, gJiminyCharacterAliceLine2French, gJiminyCharacterAliceLine3French,
    gJiminyCharacterAliceLine4French, gJiminyCharacterAliceLine5French, gJiminyCharacterAliceLine6French, gJiminyCharacterAliceLine7French,
    gJiminyCharacterAliceLine8French, gJiminyCharacterAliceLine9French, gJiminyCharacterAliceLine10French, gJiminyCharacterAliceLine11French,
    gJiminyCharacterAliceLine12French,
};

const JiminyTextChar* gJiminyCharacterAliceLinesGerman[13] = {
    gJiminyCharacterAliceLine0German, gJiminyCharacterAliceLine1German, gJiminyCharacterAliceLine2German, gJiminyCharacterAliceLine3German,
    gJiminyCharacterAliceLine4German, gJiminyCharacterAliceLine5German, gJiminyCharacterAliceLine6German, gJiminyCharacterAliceLine7German,
    gJiminyCharacterAliceLine8German, gJiminyCharacterAliceLine9German, gJiminyCharacterAliceLine10German, gJiminyCharacterAliceLine11German,
    gJiminyCharacterAliceLine12German,
};

const JiminyTextChar* gJiminyCharacterAliceLinesItalian[13] = {
    gJiminyCharacterAliceLine0Italian, gJiminyCharacterAliceLine1Italian, gJiminyCharacterAliceLine2Italian, gJiminyCharacterAliceLine3Italian,
    gJiminyCharacterAliceLine4Italian, gJiminyCharacterAliceLine5Italian, gJiminyCharacterAliceLine6Italian, gJiminyCharacterAliceLine7Italian,
    gJiminyCharacterAliceLine8Italian, gJiminyCharacterAliceLine9Italian, gJiminyCharacterAliceLine10Italian, gJiminyCharacterAliceLine11Italian,
    gJiminyCharacterAliceLine12Italian,
};

const JiminyTextChar* gJiminyCharacterAliceLinesSpanish[10] = {
    gJiminyCharacterAliceLine0Spanish, gJiminyCharacterAliceLine1Spanish, gJiminyCharacterAliceLine2Spanish, gJiminyCharacterAliceLine3Spanish,
    gJiminyCharacterAliceLine4Spanish, gJiminyCharacterAliceLine5Spanish, gJiminyCharacterAliceLine6Spanish, gJiminyCharacterAliceLine7Spanish,
    gJiminyCharacterAliceLine8Spanish, gJiminyCharacterAliceLine9Spanish,
};

const JiminyTextChar* gJiminyCharacterQueenOfHeartsLines[8] = {
    gJiminyCharacterQueenOfHeartsLine0, gJiminyCharacterQueenOfHeartsLine1, gJiminyCharacterQueenOfHeartsLine2, gJiminyCharacterQueenOfHeartsLine3,
    gJiminyCharacterQueenOfHeartsLine4, gJiminyCharacterQueenOfHeartsLine5, gJiminyCharacterQueenOfHeartsLine6, gJiminyCharacterQueenOfHeartsLine7,
};

const JiminyTextChar* gJiminyCharacterQueenOfHeartsLinesFrench[10] = {
    gJiminyCharacterQueenOfHeartsLine0French, gJiminyCharacterQueenOfHeartsLine1French, gJiminyCharacterQueenOfHeartsLine2French, gJiminyCharacterQueenOfHeartsLine3French,
    gJiminyCharacterQueenOfHeartsLine4French, gJiminyCharacterQueenOfHeartsLine5French, gJiminyCharacterQueenOfHeartsLine6French, gJiminyCharacterQueenOfHeartsLine7French,
    gJiminyCharacterQueenOfHeartsLine8French, gJiminyCharacterQueenOfHeartsLine9French,
};

const JiminyTextChar* gJiminyCharacterQueenOfHeartsLinesGerman[10] = {
    gJiminyCharacterQueenOfHeartsLine0German, gJiminyCharacterQueenOfHeartsLine1German, gJiminyCharacterQueenOfHeartsLine2German, gJiminyCharacterQueenOfHeartsLine3German,
    gJiminyCharacterQueenOfHeartsLine4German, gJiminyCharacterQueenOfHeartsLine5German, gJiminyCharacterQueenOfHeartsLine6German, gJiminyCharacterQueenOfHeartsLine7German,
    gJiminyCharacterQueenOfHeartsLine8German, gJiminyCharacterQueenOfHeartsLine9German,
};

const JiminyTextChar* gJiminyCharacterQueenOfHeartsLinesItalian[9] = {
    gJiminyCharacterQueenOfHeartsLine0Italian, gJiminyCharacterQueenOfHeartsLine1Italian, gJiminyCharacterQueenOfHeartsLine2Italian, gJiminyCharacterQueenOfHeartsLine3Italian,
    gJiminyCharacterQueenOfHeartsLine4Italian, gJiminyCharacterQueenOfHeartsLine5Italian, gJiminyCharacterQueenOfHeartsLine6Italian, gJiminyCharacterQueenOfHeartsLine7Italian,
    gJiminyCharacterQueenOfHeartsLine8Italian,
};

const JiminyTextChar* gJiminyCharacterQueenOfHeartsLinesSpanish[8] = {
    gJiminyCharacterQueenOfHeartsLine0Spanish, gJiminyCharacterQueenOfHeartsLine1Spanish, gJiminyCharacterQueenOfHeartsLine2Spanish, gJiminyCharacterQueenOfHeartsLine3Spanish,
    gJiminyCharacterQueenOfHeartsLine4Spanish, gJiminyCharacterQueenOfHeartsLine5Spanish, gJiminyCharacterQueenOfHeartsLine6Spanish, gJiminyCharacterQueenOfHeartsLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterWhiteRabbitLines[7] = {
    gJiminyCharacterWhiteRabbitLine0, gJiminyCharacterWhiteRabbitLine1, gJiminyCharacterWhiteRabbitLine2, gJiminyCharacterWhiteRabbitLine3,
    gJiminyCharacterWhiteRabbitLine4, gJiminyCharacterWhiteRabbitLine5, gJiminyCharacterWhiteRabbitLine6,
};

const JiminyTextChar* gJiminyCharacterWhiteRabbitLinesFrench[6] = {
    gJiminyCharacterWhiteRabbitLine0French, gJiminyCharacterWhiteRabbitLine1French, gJiminyCharacterWhiteRabbitLine2French, gJiminyCharacterWhiteRabbitLine3French,
    gJiminyCharacterWhiteRabbitLine4French, gJiminyCharacterWhiteRabbitLine5French,
};

const JiminyTextChar* gJiminyCharacterWhiteRabbitLinesGerman[6] = {
    gJiminyCharacterWhiteRabbitLine0German, gJiminyCharacterWhiteRabbitLine1German, gJiminyCharacterWhiteRabbitLine2German, gJiminyCharacterWhiteRabbitLine3German,
    gJiminyCharacterWhiteRabbitLine4German, gJiminyCharacterWhiteRabbitLine5German,
};

const JiminyTextChar* gJiminyCharacterWhiteRabbitLinesItalian[6] = {
    gJiminyCharacterWhiteRabbitLine0Italian, gJiminyCharacterWhiteRabbitLine1Italian, gJiminyCharacterWhiteRabbitLine2Italian, gJiminyCharacterWhiteRabbitLine3Italian,
    gJiminyCharacterWhiteRabbitLine4Italian, gJiminyCharacterWhiteRabbitLine5Italian,
};

const JiminyTextChar* gJiminyCharacterWhiteRabbitLinesSpanish[6] = {
    gJiminyCharacterWhiteRabbitLine0Spanish, gJiminyCharacterWhiteRabbitLine1Spanish, gJiminyCharacterWhiteRabbitLine2Spanish, gJiminyCharacterWhiteRabbitLine3Spanish,
    gJiminyCharacterWhiteRabbitLine4Spanish, gJiminyCharacterWhiteRabbitLine5Spanish,
};

const JiminyTextChar* gJiminyCharacterCardOfHeartsLines[6] = {
    gJiminyCharacterCardOfHeartsLine0, gJiminyCharacterCardOfHeartsLine1, gJiminyCharacterCardOfHeartsLine2, gJiminyCharacterCardOfHeartsLine3,
    gJiminyCharacterCardOfHeartsLine4, gJiminyCharacterCardOfHeartsLine5,
};

const JiminyTextChar* gJiminyCharacterCardOfHeartsLinesFrench[7] = {
    gJiminyCharacterCardOfHeartsLine0French, gJiminyCharacterCardOfHeartsLine1French, gJiminyCharacterCardOfHeartsLine2French, gJiminyCharacterCardOfHeartsLine3French,
    gJiminyCharacterCardOfHeartsLine4French, gJiminyCharacterCardOfHeartsLine5French, gJiminyCharacterCardOfHeartsLine6French,
};

const JiminyTextChar* gJiminyCharacterCardOfHeartsLinesGerman[6] = {
    gJiminyCharacterCardOfHeartsLine0German, gJiminyCharacterCardOfHeartsLine1German, gJiminyCharacterCardOfHeartsLine2German, gJiminyCharacterCardOfHeartsLine3German,
    gJiminyCharacterCardOfHeartsLine4German, gJiminyCharacterCardOfHeartsLine5German,
};

const JiminyTextChar* gJiminyCharacterCardOfHeartsLinesItalian[6] = {
    gJiminyCharacterCardOfHeartsLine0Italian, gJiminyCharacterCardOfHeartsLine1Italian, gJiminyCharacterCardOfHeartsLine2Italian, gJiminyCharacterCardOfHeartsLine3Italian,
    gJiminyCharacterCardOfHeartsLine4Italian, gJiminyCharacterCardOfHeartsLine5Italian,
};

const JiminyTextChar* gJiminyCharacterCardOfHeartsLinesSpanish[6] = {
    gJiminyCharacterCardOfHeartsLine0Spanish, gJiminyCharacterCardOfHeartsLine1Spanish, gJiminyCharacterCardOfHeartsLine2Spanish, gJiminyCharacterCardOfHeartsLine3Spanish,
    gJiminyCharacterCardOfHeartsLine4Spanish, gJiminyCharacterCardOfHeartsLine5Spanish,
};

const JiminyTextChar* gJiminyCharacterCardOfSpadesLines[6] = {
    gJiminyCharacterCardOfSpadesLine0, gJiminyCharacterCardOfSpadesLine1, gJiminyCharacterCardOfSpadesLine2, gJiminyCharacterCardOfSpadesLine3,
    gJiminyCharacterCardOfSpadesLine4, gJiminyCharacterCardOfSpadesLine5,
};

const JiminyTextChar* gJiminyCharacterCardOfSpadesLinesFrench[7] = {
    gJiminyCharacterCardOfSpadesLine0French, gJiminyCharacterCardOfSpadesLine1French, gJiminyCharacterCardOfSpadesLine2French, gJiminyCharacterCardOfSpadesLine3French,
    gJiminyCharacterCardOfSpadesLine4French, gJiminyCharacterCardOfSpadesLine5French, gJiminyCharacterCardOfSpadesLine6French,
};

const JiminyTextChar* gJiminyCharacterCardOfSpadesLinesGerman[6] = {
    gJiminyCharacterCardOfSpadesLine0German, gJiminyCharacterCardOfSpadesLine1German, gJiminyCharacterCardOfSpadesLine2German, gJiminyCharacterCardOfSpadesLine3German,
    gJiminyCharacterCardOfSpadesLine4German, gJiminyCharacterCardOfSpadesLine5German,
};

const JiminyTextChar* gJiminyCharacterCardOfSpadesLinesItalian[6] = {
    gJiminyCharacterCardOfSpadesLine0Italian, gJiminyCharacterCardOfSpadesLine1Italian, gJiminyCharacterCardOfSpadesLine2Italian, gJiminyCharacterCardOfSpadesLine3Italian,
    gJiminyCharacterCardOfSpadesLine4Italian, gJiminyCharacterCardOfSpadesLine5Italian,
};

const JiminyTextChar* gJiminyCharacterCardOfSpadesLinesSpanish[6] = {
    gJiminyCharacterCardOfSpadesLine0Spanish, gJiminyCharacterCardOfSpadesLine1Spanish, gJiminyCharacterCardOfSpadesLine2Spanish, gJiminyCharacterCardOfSpadesLine3Spanish,
    gJiminyCharacterCardOfSpadesLine4Spanish, gJiminyCharacterCardOfSpadesLine5Spanish,
};

const JiminyTextChar* gJiminyCharacterCheshireCatLines[8] = {
    gJiminyCharacterCheshireCatLine0, gJiminyCharacterCheshireCatLine1, gJiminyCharacterCheshireCatLine2, gJiminyCharacterCheshireCatLine3,
    gJiminyCharacterCheshireCatLine4, gJiminyCharacterCheshireCatLine5, gJiminyCharacterCheshireCatLine6, gJiminyCharacterCheshireCatLine7,
};

const JiminyTextChar* gJiminyCharacterCheshireCatLinesFrench[9] = {
    gJiminyCharacterCheshireCatLine0French, gJiminyCharacterCheshireCatLine1French, gJiminyCharacterCheshireCatLine2French, gJiminyCharacterCheshireCatLine3French,
    gJiminyCharacterCheshireCatLine4French, gJiminyCharacterCheshireCatLine5French, gJiminyCharacterCheshireCatLine6French, gJiminyCharacterCheshireCatLine7French,
    gJiminyCharacterCheshireCatLine8French,
};

const JiminyTextChar* gJiminyCharacterCheshireCatLinesGerman[8] = {
    gJiminyCharacterCheshireCatLine0German, gJiminyCharacterCheshireCatLine1German, gJiminyCharacterCheshireCatLine2German, gJiminyCharacterCheshireCatLine3German,
    gJiminyCharacterCheshireCatLine4German, gJiminyCharacterCheshireCatLine5German, gJiminyCharacterCheshireCatLine6German, gJiminyCharacterCheshireCatLine7German,
};

const JiminyTextChar* gJiminyCharacterCheshireCatLinesItalian[7] = {
    gJiminyCharacterCheshireCatLine0Italian, gJiminyCharacterCheshireCatLine1Italian, gJiminyCharacterCheshireCatLine2Italian, gJiminyCharacterCheshireCatLine3Italian,
    gJiminyCharacterCheshireCatLine4Italian, gJiminyCharacterCheshireCatLine5Italian, gJiminyCharacterCheshireCatLine6Italian,
};

const JiminyTextChar* gJiminyCharacterCheshireCatLinesSpanish[8] = {
    gJiminyCharacterCheshireCatLine0Spanish, gJiminyCharacterCheshireCatLine1Spanish, gJiminyCharacterCheshireCatLine2Spanish, gJiminyCharacterCheshireCatLine3Spanish,
    gJiminyCharacterCheshireCatLine4Spanish, gJiminyCharacterCheshireCatLine5Spanish, gJiminyCharacterCheshireCatLine6Spanish, gJiminyCharacterCheshireCatLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterArielLines[15] = {
    gJiminyCharacterArielLine0, gJiminyCharacterArielLine1, gJiminyCharacterArielLine2, gJiminyCharacterArielLine3,
    gJiminyCharacterArielLine4, gJiminyCharacterArielLine5, gJiminyCharacterArielLine6, gJiminyCharacterArielLine7,
    gJiminyCharacterArielLine8, gJiminyCharacterArielLine9, gJiminyCharacterArielLine10, gJiminyCharacterArielLine11,
    gJiminyCharacterArielLine12, gJiminyCharacterArielLine13, gJiminyCharacterArielLine14,
};

const JiminyTextChar* gJiminyCharacterArielLinesFrench[16] = {
    gJiminyCharacterArielLine0French, gJiminyCharacterArielLine1French, gJiminyCharacterArielLine2French, gJiminyCharacterArielLine3French,
    gJiminyCharacterArielLine4French, gJiminyCharacterArielLine5French, gJiminyCharacterArielLine6French, gJiminyCharacterArielLine7French,
    gJiminyCharacterArielLine8French, gJiminyCharacterArielLine9French, gJiminyCharacterArielLine10French, gJiminyCharacterArielLine11French,
    gJiminyCharacterArielLine12French, gJiminyCharacterArielLine13French, gJiminyCharacterArielLine14French, gJiminyCharacterArielLine15French,
};

const JiminyTextChar* gJiminyCharacterArielLinesGerman[18] = {
    gJiminyCharacterArielLine0German, gJiminyCharacterArielLine1German, gJiminyCharacterArielLine2German, gJiminyCharacterArielLine3German,
    gJiminyCharacterArielLine4German, gJiminyCharacterArielLine5German, gJiminyCharacterArielLine6German, gJiminyCharacterArielLine7German,
    gJiminyCharacterArielLine8German, gJiminyCharacterArielLine9German, gJiminyCharacterArielLine10German, gJiminyCharacterArielLine11German,
    gJiminyCharacterArielLine12German, gJiminyCharacterArielLine13German, gJiminyCharacterArielLine14German, gJiminyCharacterArielLine15German,
    gJiminyCharacterArielLine16German, gJiminyCharacterArielLine17German,
};

const JiminyTextChar* gJiminyCharacterArielLinesItalian[18] = {
    gJiminyCharacterArielLine0Italian, gJiminyCharacterArielLine1Italian, gJiminyCharacterArielLine2Italian, gJiminyCharacterArielLine3Italian,
    gJiminyCharacterArielLine4Italian, gJiminyCharacterArielLine5Italian, gJiminyCharacterArielLine6Italian, gJiminyCharacterArielLine7Italian,
    gJiminyCharacterArielLine8Italian, gJiminyCharacterArielLine9Italian, gJiminyCharacterArielLine10Italian, gJiminyCharacterArielLine11Italian,
    gJiminyCharacterArielLine12Italian, gJiminyCharacterArielLine13Italian, gJiminyCharacterArielLine14Italian, gJiminyCharacterArielLine15Italian,
    gJiminyCharacterArielLine16Italian, gJiminyCharacterArielLine17Italian,
};

const JiminyTextChar* gJiminyCharacterArielLinesSpanish[15] = {
    gJiminyCharacterArielLine0Spanish, gJiminyCharacterArielLine1Spanish, gJiminyCharacterArielLine2Spanish, gJiminyCharacterArielLine3Spanish,
    gJiminyCharacterArielLine4Spanish, gJiminyCharacterArielLine5Spanish, gJiminyCharacterArielLine6Spanish, gJiminyCharacterArielLine7Spanish,
    gJiminyCharacterArielLine8Spanish, gJiminyCharacterArielLine9Spanish, gJiminyCharacterArielLine10Spanish, gJiminyCharacterArielLine11Spanish,
    gJiminyCharacterArielLine12Spanish, gJiminyCharacterArielLine13Spanish, gJiminyCharacterArielLine14Spanish,
};

const JiminyTextChar* gJiminyCharacterSebastianLines[8] = {
    gJiminyCharacterSebastianLine0, gJiminyCharacterSebastianLine1, gJiminyCharacterSebastianLine2, gJiminyCharacterSebastianLine3,
    gJiminyCharacterSebastianLine4, gJiminyCharacterSebastianLine5, gJiminyCharacterSebastianLine6, gJiminyCharacterSebastianLine7,
};

const JiminyTextChar* gJiminyCharacterSebastianLinesFrench[9] = {
    gJiminyCharacterSebastianLine0French, gJiminyCharacterSebastianLine1French, gJiminyCharacterSebastianLine2French, gJiminyCharacterSebastianLine3French,
    gJiminyCharacterSebastianLine4French, gJiminyCharacterSebastianLine5French, gJiminyCharacterSebastianLine6French, gJiminyCharacterSebastianLine7French,
    gJiminyCharacterSebastianLine8French,
};

const JiminyTextChar* gJiminyCharacterSebastianLinesGerman[8] = {
    gJiminyCharacterSebastianLine0German, gJiminyCharacterSebastianLine1German, gJiminyCharacterSebastianLine2German, gJiminyCharacterSebastianLine3German,
    gJiminyCharacterSebastianLine4German, gJiminyCharacterSebastianLine5German, gJiminyCharacterSebastianLine6German, gJiminyCharacterSebastianLine7German,
};

const JiminyTextChar* gJiminyCharacterSebastianLinesItalian[11] = {
    gJiminyCharacterSebastianLine0Italian, gJiminyCharacterSebastianLine1Italian, gJiminyCharacterSebastianLine2Italian, gJiminyCharacterSebastianLine3Italian,
    gJiminyCharacterSebastianLine4Italian, gJiminyCharacterSebastianLine5Italian, gJiminyCharacterSebastianLine6Italian, gJiminyCharacterSebastianLine7Italian,
    gJiminyCharacterSebastianLine8Italian, gJiminyCharacterSebastianLine9Italian, gJiminyCharacterSebastianLine10Italian,
};

const JiminyTextChar* gJiminyCharacterSebastianLinesSpanish[8] = {
    gJiminyCharacterSebastianLine0Spanish, gJiminyCharacterSebastianLine1Spanish, gJiminyCharacterSebastianLine2Spanish, gJiminyCharacterSebastianLine3Spanish,
    gJiminyCharacterSebastianLine4Spanish, gJiminyCharacterSebastianLine5Spanish, gJiminyCharacterSebastianLine6Spanish, gJiminyCharacterSebastianLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterFlounderLines[10] = {
    gJiminyCharacterFlounderLine0, gJiminyCharacterFlounderLine1, gJiminyCharacterFlounderLine2, gJiminyCharacterFlounderLine3,
    gJiminyCharacterFlounderLine4, gJiminyCharacterFlounderLine5, gJiminyCharacterFlounderLine6, gJiminyCharacterFlounderLine7,
    gJiminyCharacterFlounderLine8, gJiminyCharacterFlounderLine9,
};

const JiminyTextChar* gJiminyCharacterFlounderLinesFrench[12] = {
    gJiminyCharacterFlounderLine0French, gJiminyCharacterFlounderLine1French, gJiminyCharacterFlounderLine2French, gJiminyCharacterFlounderLine3French,
    gJiminyCharacterFlounderLine4French, gJiminyCharacterFlounderLine5French, gJiminyCharacterFlounderLine6French, gJiminyCharacterFlounderLine7French,
    gJiminyCharacterFlounderLine8French, gJiminyCharacterFlounderLine9French, gJiminyCharacterFlounderLine10French, gJiminyCharacterFlounderLine11French,
};

const JiminyTextChar* gJiminyCharacterFlounderLinesGerman[11] = {
    gJiminyCharacterFlounderLine0German, gJiminyCharacterFlounderLine1German, gJiminyCharacterFlounderLine2German, gJiminyCharacterFlounderLine3German,
    gJiminyCharacterFlounderLine4German, gJiminyCharacterFlounderLine5German, gJiminyCharacterFlounderLine6German, gJiminyCharacterFlounderLine7German,
    gJiminyCharacterFlounderLine8German, gJiminyCharacterFlounderLine9German, gJiminyCharacterFlounderLine10German,
};

const JiminyTextChar* gJiminyCharacterFlounderLinesItalian[9] = {
    gJiminyCharacterFlounderLine0Italian, gJiminyCharacterFlounderLine1Italian, gJiminyCharacterFlounderLine2Italian, gJiminyCharacterFlounderLine3Italian,
    gJiminyCharacterFlounderLine4Italian, gJiminyCharacterFlounderLine5Italian, gJiminyCharacterFlounderLine6Italian, gJiminyCharacterFlounderLine7Italian,
    gJiminyCharacterFlounderLine8Italian,
};

const JiminyTextChar* gJiminyCharacterFlounderLinesSpanish[10] = {
    gJiminyCharacterFlounderLine0Spanish, gJiminyCharacterFlounderLine1Spanish, gJiminyCharacterFlounderLine2Spanish, gJiminyCharacterFlounderLine3Spanish,
    gJiminyCharacterFlounderLine4Spanish, gJiminyCharacterFlounderLine5Spanish, gJiminyCharacterFlounderLine6Spanish, gJiminyCharacterFlounderLine7Spanish,
    gJiminyCharacterFlounderLine8Spanish, gJiminyCharacterFlounderLine9Spanish,
};

const JiminyTextChar* gJiminyCharacterUrsulaLines[9] = {
    gJiminyCharacterUrsulaLine0, gJiminyCharacterUrsulaLine1, gJiminyCharacterUrsulaLine2, gJiminyCharacterUrsulaLine3,
    gJiminyCharacterUrsulaLine4, gJiminyCharacterUrsulaLine5, gJiminyCharacterUrsulaLine6, gJiminyCharacterUrsulaLine7,
    gJiminyCharacterUrsulaLine8,
};

const JiminyTextChar* gJiminyCharacterUrsulaLinesFrench[10] = {
    gJiminyCharacterUrsulaLine0French, gJiminyCharacterUrsulaLine1French, gJiminyCharacterUrsulaLine2French, gJiminyCharacterUrsulaLine3French,
    gJiminyCharacterUrsulaLine4French, gJiminyCharacterUrsulaLine5French, gJiminyCharacterUrsulaLine6French, gJiminyCharacterUrsulaLine7French,
    gJiminyCharacterUrsulaLine8French, gJiminyCharacterUrsulaLine9French,
};

const JiminyTextChar* gJiminyCharacterUrsulaLinesGerman[9] = {
    gJiminyCharacterUrsulaLine0German, gJiminyCharacterUrsulaLine1German, gJiminyCharacterUrsulaLine2German, gJiminyCharacterUrsulaLine3German,
    gJiminyCharacterUrsulaLine4German, gJiminyCharacterUrsulaLine5German, gJiminyCharacterUrsulaLine6German, gJiminyCharacterUrsulaLine7German,
    gJiminyCharacterUrsulaLine8German,
};

const JiminyTextChar* gJiminyCharacterUrsulaLinesItalian[8] = {
    gJiminyCharacterUrsulaLine0Italian, gJiminyCharacterUrsulaLine1Italian, gJiminyCharacterUrsulaLine2Italian, gJiminyCharacterUrsulaLine3Italian,
    gJiminyCharacterUrsulaLine4Italian, gJiminyCharacterUrsulaLine5Italian, gJiminyCharacterUrsulaLine6Italian, gJiminyCharacterUrsulaLine7Italian,
};

const JiminyTextChar* gJiminyCharacterUrsulaLinesSpanish[9] = {
    gJiminyCharacterUrsulaLine0Spanish, gJiminyCharacterUrsulaLine1Spanish, gJiminyCharacterUrsulaLine2Spanish, gJiminyCharacterUrsulaLine3Spanish,
    gJiminyCharacterUrsulaLine4Spanish, gJiminyCharacterUrsulaLine5Spanish, gJiminyCharacterUrsulaLine6Spanish, gJiminyCharacterUrsulaLine7Spanish,
    gJiminyCharacterUrsulaLine8Spanish,
};

const JiminyTextChar* gJiminyCharacterPeterPanLines[13] = {
    gJiminyCharacterPeterPanLine0, gJiminyCharacterPeterPanLine1, gJiminyCharacterPeterPanLine2, gJiminyCharacterPeterPanLine3,
    gJiminyCharacterPeterPanLine4, gJiminyCharacterPeterPanLine5, gJiminyCharacterPeterPanLine6, gJiminyCharacterPeterPanLine7,
    gJiminyCharacterPeterPanLine8, gJiminyCharacterPeterPanLine9, gJiminyCharacterPeterPanLine10, gJiminyCharacterPeterPanLine11,
    gJiminyCharacterPeterPanLine12,
};

const JiminyTextChar* gJiminyCharacterPeterPanLinesFrench[13] = {
    gJiminyCharacterPeterPanLine0French, gJiminyCharacterPeterPanLine1French, gJiminyCharacterPeterPanLine2French, gJiminyCharacterPeterPanLine3French,
    gJiminyCharacterPeterPanLine4French, gJiminyCharacterPeterPanLine5French, gJiminyCharacterPeterPanLine6French, gJiminyCharacterPeterPanLine7French,
    gJiminyCharacterPeterPanLine8French, gJiminyCharacterPeterPanLine9French, gJiminyCharacterPeterPanLine10French, gJiminyCharacterPeterPanLine11French,
    gJiminyCharacterPeterPanLine12French,
};

const JiminyTextChar* gJiminyCharacterPeterPanLinesGerman[15] = {
    gJiminyCharacterPeterPanLine0German, gJiminyCharacterPeterPanLine1German, gJiminyCharacterPeterPanLine2German, gJiminyCharacterPeterPanLine3German,
    gJiminyCharacterPeterPanLine4German, gJiminyCharacterPeterPanLine5German, gJiminyCharacterPeterPanLine6German, gJiminyCharacterPeterPanLine7German,
    gJiminyCharacterPeterPanLine8German, gJiminyCharacterPeterPanLine9German, gJiminyCharacterPeterPanLine10German, gJiminyCharacterPeterPanLine11German,
    gJiminyCharacterPeterPanLine12German, gJiminyCharacterPeterPanLine13German, gJiminyCharacterPeterPanLine14German,
};

const JiminyTextChar* gJiminyCharacterPeterPanLinesItalian[13] = {
    gJiminyCharacterPeterPanLine0Italian, gJiminyCharacterPeterPanLine1Italian, gJiminyCharacterPeterPanLine2Italian, gJiminyCharacterPeterPanLine3Italian,
    gJiminyCharacterPeterPanLine4Italian, gJiminyCharacterPeterPanLine5Italian, gJiminyCharacterPeterPanLine6Italian, gJiminyCharacterPeterPanLine7Italian,
    gJiminyCharacterPeterPanLine8Italian, gJiminyCharacterPeterPanLine9Italian, gJiminyCharacterPeterPanLine10Italian, gJiminyCharacterPeterPanLine11Italian,
    gJiminyCharacterPeterPanLine12Italian,
};

const JiminyTextChar* gJiminyCharacterPeterPanLinesSpanish[12] = {
    gJiminyCharacterPeterPanLine0Spanish, gJiminyCharacterPeterPanLine1Spanish, gJiminyCharacterPeterPanLine2Spanish, gJiminyCharacterPeterPanLine3Spanish,
    gJiminyCharacterPeterPanLine4Spanish, gJiminyCharacterPeterPanLine5Spanish, gJiminyCharacterPeterPanLine6Spanish, gJiminyCharacterPeterPanLine7Spanish,
    gJiminyCharacterPeterPanLine8Spanish, gJiminyCharacterPeterPanLine9Spanish, gJiminyCharacterPeterPanLine10Spanish, gJiminyCharacterPeterPanLine11Spanish,
};

const JiminyTextChar* gJiminyCharacterTinkerBellLines[4] = {
    gJiminyCharacterTinkerBellLine0, gJiminyCharacterTinkerBellLine1, gJiminyCharacterTinkerBellLine2, gJiminyCharacterTinkerBellLine3,
};

const JiminyTextChar* gJiminyCharacterTinkerBellLinesFrench[4] = {
    gJiminyCharacterTinkerBellLine0French, gJiminyCharacterTinkerBellLine1French, gJiminyCharacterTinkerBellLine2French, gJiminyCharacterTinkerBellLine3French,
};

const JiminyTextChar* gJiminyCharacterTinkerBellLinesGerman[5] = {
    gJiminyCharacterTinkerBellLine0German, gJiminyCharacterTinkerBellLine1German, gJiminyCharacterTinkerBellLine2German, gJiminyCharacterTinkerBellLine3German,
    gJiminyCharacterTinkerBellLine4German,
};

const JiminyTextChar* gJiminyCharacterTinkerBellLinesItalian[4] = {
    gJiminyCharacterTinkerBellLine0Italian, gJiminyCharacterTinkerBellLine1Italian, gJiminyCharacterTinkerBellLine2Italian, gJiminyCharacterTinkerBellLine3Italian,
};

const JiminyTextChar* gJiminyCharacterTinkerBellLinesSpanish[4] = {
    gJiminyCharacterTinkerBellLine0Spanish, gJiminyCharacterTinkerBellLine1Spanish, gJiminyCharacterTinkerBellLine2Spanish, gJiminyCharacterTinkerBellLine3Spanish,
};

const JiminyTextChar* gJiminyCharacterWendyLines[7] = {
    gJiminyCharacterWendyLine0, gJiminyCharacterWendyLine1, gJiminyCharacterWendyLine2, gJiminyCharacterWendyLine3,
    gJiminyCharacterWendyLine4, gJiminyCharacterWendyLine5, gJiminyCharacterWendyLine6,
};

const JiminyTextChar* gJiminyCharacterWendyLinesFrench[8] = {
    gJiminyCharacterWendyLine0French, gJiminyCharacterWendyLine1French, gJiminyCharacterWendyLine2French, gJiminyCharacterWendyLine3French,
    gJiminyCharacterWendyLine4French, gJiminyCharacterWendyLine5French, gJiminyCharacterWendyLine6French, gJiminyCharacterWendyLine7French,
};

const JiminyTextChar* gJiminyCharacterWendyLinesGerman[8] = {
    gJiminyCharacterWendyLine0German, gJiminyCharacterWendyLine1German, gJiminyCharacterWendyLine2German, gJiminyCharacterWendyLine3German,
    gJiminyCharacterWendyLine4German, gJiminyCharacterWendyLine5German, gJiminyCharacterWendyLine6German, gJiminyCharacterWendyLine7German,
};

const JiminyTextChar* gJiminyCharacterWendyLinesItalian[9] = {
    gJiminyCharacterWendyLine0Italian, gJiminyCharacterWendyLine1Italian, gJiminyCharacterWendyLine2Italian, gJiminyCharacterWendyLine3Italian,
    gJiminyCharacterWendyLine4Italian, gJiminyCharacterWendyLine5Italian, gJiminyCharacterWendyLine6Italian, gJiminyCharacterWendyLine7Italian,
    gJiminyCharacterWendyLine8Italian,
};

const JiminyTextChar* gJiminyCharacterWendyLinesSpanish[7] = {
    gJiminyCharacterWendyLine0Spanish, gJiminyCharacterWendyLine1Spanish, gJiminyCharacterWendyLine2Spanish, gJiminyCharacterWendyLine3Spanish,
    gJiminyCharacterWendyLine4Spanish, gJiminyCharacterWendyLine5Spanish, gJiminyCharacterWendyLine6Spanish,
};

const JiminyTextChar* gJiminyCharacterHookLines[12] = {
    gJiminyCharacterHookLine0, gJiminyCharacterHookLine1, gJiminyCharacterHookLine2, gJiminyCharacterHookLine3,
    gJiminyCharacterHookLine4, gJiminyCharacterHookLine5, gJiminyCharacterHookLine6, gJiminyCharacterHookLine7,
    gJiminyCharacterHookLine8, gJiminyCharacterHookLine9, gJiminyCharacterHookLine10, gJiminyCharacterHookLine11,
};

const JiminyTextChar* gJiminyCharacterHookLinesFrench[12] = {
    gJiminyCharacterHookLine0French, gJiminyCharacterHookLine1French, gJiminyCharacterHookLine2French, gJiminyCharacterHookLine3French,
    gJiminyCharacterHookLine4French, gJiminyCharacterHookLine5French, gJiminyCharacterHookLine6French, gJiminyCharacterHookLine7French,
    gJiminyCharacterHookLine8French, gJiminyCharacterHookLine9French, gJiminyCharacterHookLine10French, gJiminyCharacterHookLine11French,
};

const JiminyTextChar* gJiminyCharacterHookLinesGerman[13] = {
    gJiminyCharacterHookLine0German, gJiminyCharacterHookLine1German, gJiminyCharacterHookLine2German, gJiminyCharacterHookLine3German,
    gJiminyCharacterHookLine4German, gJiminyCharacterHookLine5German, gJiminyCharacterHookLine6German, gJiminyCharacterHookLine7German,
    gJiminyCharacterHookLine8German, gJiminyCharacterHookLine9German, gJiminyCharacterHookLine10German, gJiminyCharacterHookLine11German,
    gJiminyCharacterHookLine12German,
};

const JiminyTextChar* gJiminyCharacterHookLinesItalian[12] = {
    gJiminyCharacterHookLine0Italian, gJiminyCharacterHookLine1Italian, gJiminyCharacterHookLine2Italian, gJiminyCharacterHookLine3Italian,
    gJiminyCharacterHookLine4Italian, gJiminyCharacterHookLine5Italian, gJiminyCharacterHookLine6Italian, gJiminyCharacterHookLine7Italian,
    gJiminyCharacterHookLine8Italian, gJiminyCharacterHookLine9Italian, gJiminyCharacterHookLine10Italian, gJiminyCharacterHookLine11Italian,
};

const JiminyTextChar* gJiminyCharacterHookLinesSpanish[12] = {
    gJiminyCharacterHookLine0Spanish, gJiminyCharacterHookLine1Spanish, gJiminyCharacterHookLine2Spanish, gJiminyCharacterHookLine3Spanish,
    gJiminyCharacterHookLine4Spanish, gJiminyCharacterHookLine5Spanish, gJiminyCharacterHookLine6Spanish, gJiminyCharacterHookLine7Spanish,
    gJiminyCharacterHookLine8Spanish, gJiminyCharacterHookLine9Spanish, gJiminyCharacterHookLine10Spanish, gJiminyCharacterHookLine11Spanish,
};

const JiminyTextChar* gJiminyCharacterBeastLines[10] = {
    gJiminyCharacterBeastLine0, gJiminyCharacterBeastLine1, gJiminyCharacterBeastLine2, gJiminyCharacterBeastLine3,
    gJiminyCharacterBeastLine4, gJiminyCharacterBeastLine5, gJiminyCharacterBeastLine6, gJiminyCharacterBeastLine7,
    gJiminyCharacterBeastLine8, gJiminyCharacterBeastLine9,
};

const JiminyTextChar* gJiminyCharacterBeastLinesFrench[11] = {
    gJiminyCharacterBeastLine0French, gJiminyCharacterBeastLine1French, gJiminyCharacterBeastLine2French, gJiminyCharacterBeastLine3French,
    gJiminyCharacterBeastLine4French, gJiminyCharacterBeastLine5French, gJiminyCharacterBeastLine6French, gJiminyCharacterBeastLine7French,
    gJiminyCharacterBeastLine8French, gJiminyCharacterBeastLine9French, gJiminyCharacterBeastLine10French,
};

const JiminyTextChar* gJiminyCharacterBeastLinesGerman[13] = {
    gJiminyCharacterBeastLine0German, gJiminyCharacterBeastLine1German, gJiminyCharacterBeastLine2German, gJiminyCharacterBeastLine3German,
    gJiminyCharacterBeastLine4German, gJiminyCharacterBeastLine5German, gJiminyCharacterBeastLine6German, gJiminyCharacterBeastLine7German,
    gJiminyCharacterBeastLine8German, gJiminyCharacterBeastLine9German, gJiminyCharacterBeastLine10German, gJiminyCharacterBeastLine11German,
    gJiminyCharacterBeastLine12German,
};

const JiminyTextChar* gJiminyCharacterBeastLinesItalian[11] = {
    gJiminyCharacterBeastLine0Italian, gJiminyCharacterBeastLine1Italian, gJiminyCharacterBeastLine2Italian, gJiminyCharacterBeastLine3Italian,
    gJiminyCharacterBeastLine4Italian, gJiminyCharacterBeastLine5Italian, gJiminyCharacterBeastLine6Italian, gJiminyCharacterBeastLine7Italian,
    gJiminyCharacterBeastLine8Italian, gJiminyCharacterBeastLine9Italian, gJiminyCharacterBeastLine10Italian,
};

const JiminyTextChar* gJiminyCharacterBeastLinesSpanish[10] = {
    gJiminyCharacterBeastLine0Spanish, gJiminyCharacterBeastLine1Spanish, gJiminyCharacterBeastLine2Spanish, gJiminyCharacterBeastLine3Spanish,
    gJiminyCharacterBeastLine4Spanish, gJiminyCharacterBeastLine5Spanish, gJiminyCharacterBeastLine6Spanish, gJiminyCharacterBeastLine7Spanish,
    gJiminyCharacterBeastLine8Spanish, gJiminyCharacterBeastLine9Spanish,
};

const JiminyTextChar* gJiminyCharacterBelleLines[11] = {
    gJiminyCharacterBelleLine0, gJiminyCharacterBelleLine1, gJiminyCharacterBelleLine2, gJiminyCharacterBelleLine3,
    gJiminyCharacterBelleLine4, gJiminyCharacterBelleLine5, gJiminyCharacterBelleLine6, gJiminyCharacterBelleLine7,
    gJiminyCharacterBelleLine8, gJiminyCharacterBelleLine9, gJiminyCharacterBelleLine10,
};

const JiminyTextChar* gJiminyCharacterBelleLinesFrench[11] = {
    gJiminyCharacterBelleLine0French, gJiminyCharacterBelleLine1French, gJiminyCharacterBelleLine2French, gJiminyCharacterBelleLine3French,
    gJiminyCharacterBelleLine4French, gJiminyCharacterBelleLine5French, gJiminyCharacterBelleLine6French, gJiminyCharacterBelleLine7French,
    gJiminyCharacterBelleLine8French, gJiminyCharacterBelleLine9French, gJiminyCharacterBelleLine10French,
};

const JiminyTextChar* gJiminyCharacterBelleLinesGerman[12] = {
    gJiminyCharacterBelleLine0German, gJiminyCharacterBelleLine1German, gJiminyCharacterBelleLine2German, gJiminyCharacterBelleLine3German,
    gJiminyCharacterBelleLine4German, gJiminyCharacterBelleLine5German, gJiminyCharacterBelleLine6German, gJiminyCharacterBelleLine7German,
    gJiminyCharacterBelleLine8German, gJiminyCharacterBelleLine9German, gJiminyCharacterBelleLine10German, gJiminyCharacterBelleLine11German,
};

const JiminyTextChar* gJiminyCharacterBelleLinesItalian[12] = {
    gJiminyCharacterBelleLine0Italian, gJiminyCharacterBelleLine1Italian, gJiminyCharacterBelleLine2Italian, gJiminyCharacterBelleLine3Italian,
    gJiminyCharacterBelleLine4Italian, gJiminyCharacterBelleLine5Italian, gJiminyCharacterBelleLine6Italian, gJiminyCharacterBelleLine7Italian,
    gJiminyCharacterBelleLine8Italian, gJiminyCharacterBelleLine9Italian, gJiminyCharacterBelleLine10Italian, gJiminyCharacterBelleLine11Italian,
};

const JiminyTextChar* gJiminyCharacterBelleLinesSpanish[11] = {
    gJiminyCharacterBelleLine0Spanish, gJiminyCharacterBelleLine1Spanish, gJiminyCharacterBelleLine2Spanish, gJiminyCharacterBelleLine3Spanish,
    gJiminyCharacterBelleLine4Spanish, gJiminyCharacterBelleLine5Spanish, gJiminyCharacterBelleLine6Spanish, gJiminyCharacterBelleLine7Spanish,
    gJiminyCharacterBelleLine8Spanish, gJiminyCharacterBelleLine9Spanish, gJiminyCharacterBelleLine10Spanish,
};

const JiminyTextChar* gJiminyCharacterMaleficentLines[11] = {
    gJiminyCharacterMaleficentLine0, gJiminyCharacterMaleficentLine1, gJiminyCharacterMaleficentLine2, gJiminyCharacterMaleficentLine3,
    gJiminyCharacterMaleficentLine4, gJiminyCharacterMaleficentLine5, gJiminyCharacterMaleficentLine6, gJiminyCharacterMaleficentLine7,
    gJiminyCharacterMaleficentLine8, gJiminyCharacterMaleficentLine9, gJiminyCharacterMaleficentLine10,
};

const JiminyTextChar* gJiminyCharacterMaleficentLinesFrench[10] = {
    gJiminyCharacterMaleficentLine0French, gJiminyCharacterMaleficentLine1French, gJiminyCharacterMaleficentLine2French, gJiminyCharacterMaleficentLine3French,
    gJiminyCharacterMaleficentLine4French, gJiminyCharacterMaleficentLine5French, gJiminyCharacterMaleficentLine6French, gJiminyCharacterMaleficentLine7French,
    gJiminyCharacterMaleficentLine8French, gJiminyCharacterMaleficentLine9French,
};

const JiminyTextChar* gJiminyCharacterMaleficentLinesGerman[11] = {
    gJiminyCharacterMaleficentLine0German, gJiminyCharacterMaleficentLine1German, gJiminyCharacterMaleficentLine2German, gJiminyCharacterMaleficentLine3German,
    gJiminyCharacterMaleficentLine4German, gJiminyCharacterMaleficentLine5German, gJiminyCharacterMaleficentLine6German, gJiminyCharacterMaleficentLine7German,
    gJiminyCharacterMaleficentLine8German, gJiminyCharacterMaleficentLine9German, gJiminyCharacterMaleficentLine10German,
};

const JiminyTextChar* gJiminyCharacterMaleficentLinesItalian[12] = {
    gJiminyCharacterMaleficentLine0Italian, gJiminyCharacterMaleficentLine1Italian, gJiminyCharacterMaleficentLine2Italian, gJiminyCharacterMaleficentLine3Italian,
    gJiminyCharacterMaleficentLine4Italian, gJiminyCharacterMaleficentLine5Italian, gJiminyCharacterMaleficentLine6Italian, gJiminyCharacterMaleficentLine7Italian,
    gJiminyCharacterMaleficentLine8Italian, gJiminyCharacterMaleficentLine9Italian, gJiminyCharacterMaleficentLine10Italian, gJiminyCharacterMaleficentLine11Italian,
};

const JiminyTextChar* gJiminyCharacterMaleficentLinesSpanish[11] = {
    gJiminyCharacterMaleficentLine0Spanish, gJiminyCharacterMaleficentLine1Spanish, gJiminyCharacterMaleficentLine2Spanish, gJiminyCharacterMaleficentLine3Spanish,
    gJiminyCharacterMaleficentLine4Spanish, gJiminyCharacterMaleficentLine5Spanish, gJiminyCharacterMaleficentLine6Spanish, gJiminyCharacterMaleficentLine7Spanish,
    gJiminyCharacterMaleficentLine8Spanish, gJiminyCharacterMaleficentLine9Spanish, gJiminyCharacterMaleficentLine10Spanish,
};

const JiminyTextChar* gJiminyCharacterDragonMaleficentLines[8] = {
    gJiminyCharacterDragonMaleficentLine0, gJiminyCharacterDragonMaleficentLine1, gJiminyCharacterDragonMaleficentLine2, gJiminyCharacterDragonMaleficentLine3,
    gJiminyCharacterDragonMaleficentLine4, gJiminyCharacterDragonMaleficentLine5, gJiminyCharacterDragonMaleficentLine6, gJiminyCharacterDragonMaleficentLine7,
};

const JiminyTextChar* gJiminyCharacterDragonMaleficentLinesFrench[8] = {
    gJiminyCharacterDragonMaleficentLine0French, gJiminyCharacterDragonMaleficentLine1French, gJiminyCharacterDragonMaleficentLine2French, gJiminyCharacterDragonMaleficentLine3French,
    gJiminyCharacterDragonMaleficentLine4French, gJiminyCharacterDragonMaleficentLine5French, gJiminyCharacterDragonMaleficentLine6French, gJiminyCharacterDragonMaleficentLine7French,
};

const JiminyTextChar* gJiminyCharacterDragonMaleficentLinesGerman[10] = {
    gJiminyCharacterDragonMaleficentLine0German, gJiminyCharacterDragonMaleficentLine1German, gJiminyCharacterDragonMaleficentLine2German, gJiminyCharacterDragonMaleficentLine3German,
    gJiminyCharacterDragonMaleficentLine4German, gJiminyCharacterDragonMaleficentLine5German, gJiminyCharacterDragonMaleficentLine6German, gJiminyCharacterDragonMaleficentLine7German,
    gJiminyCharacterDragonMaleficentLine8German, gJiminyCharacterDragonMaleficentLine9German,
};

const JiminyTextChar* gJiminyCharacterDragonMaleficentLinesItalian[7] = {
    gJiminyCharacterDragonMaleficentLine0Italian, gJiminyCharacterDragonMaleficentLine1Italian, gJiminyCharacterDragonMaleficentLine2Italian, gJiminyCharacterDragonMaleficentLine3Italian,
    gJiminyCharacterDragonMaleficentLine4Italian, gJiminyCharacterDragonMaleficentLine5Italian, gJiminyCharacterDragonMaleficentLine6Italian,
};

const JiminyTextChar* gJiminyCharacterDragonMaleficentLinesSpanish[8] = {
    gJiminyCharacterDragonMaleficentLine0Spanish, gJiminyCharacterDragonMaleficentLine1Spanish, gJiminyCharacterDragonMaleficentLine2Spanish, gJiminyCharacterDragonMaleficentLine3Spanish,
    gJiminyCharacterDragonMaleficentLine4Spanish, gJiminyCharacterDragonMaleficentLine5Spanish, gJiminyCharacterDragonMaleficentLine6Spanish, gJiminyCharacterDragonMaleficentLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterWinnieThePoohLines[9] = {
    gJiminyCharacterWinnieThePoohLine0, gJiminyCharacterWinnieThePoohLine1, gJiminyCharacterWinnieThePoohLine2, gJiminyCharacterWinnieThePoohLine3,
    gJiminyCharacterWinnieThePoohLine4, gJiminyCharacterWinnieThePoohLine5, gJiminyCharacterWinnieThePoohLine6, gJiminyCharacterWinnieThePoohLine7,
    gJiminyCharacterWinnieThePoohLine8,
};

const JiminyTextChar* gJiminyCharacterWinnieThePoohLinesFrench[9] = {
    gJiminyCharacterWinnieThePoohLine0French, gJiminyCharacterWinnieThePoohLine1French, gJiminyCharacterWinnieThePoohLine2French, gJiminyCharacterWinnieThePoohLine3French,
    gJiminyCharacterWinnieThePoohLine4French, gJiminyCharacterWinnieThePoohLine5French, gJiminyCharacterWinnieThePoohLine6French, gJiminyCharacterWinnieThePoohLine7French,
    gJiminyCharacterWinnieThePoohLine8French,
};

const JiminyTextChar* gJiminyCharacterWinnieThePoohLinesGerman[9] = {
    gJiminyCharacterWinnieThePoohLine0German, gJiminyCharacterWinnieThePoohLine1German, gJiminyCharacterWinnieThePoohLine2German, gJiminyCharacterWinnieThePoohLine3German,
    gJiminyCharacterWinnieThePoohLine4German, gJiminyCharacterWinnieThePoohLine5German, gJiminyCharacterWinnieThePoohLine6German, gJiminyCharacterWinnieThePoohLine7German,
    gJiminyCharacterWinnieThePoohLine8German,
};

const JiminyTextChar* gJiminyCharacterWinnieThePoohLinesItalian[8] = {
    gJiminyCharacterWinnieThePoohLine0Italian, gJiminyCharacterWinnieThePoohLine1Italian, gJiminyCharacterWinnieThePoohLine2Italian, gJiminyCharacterWinnieThePoohLine3Italian,
    gJiminyCharacterWinnieThePoohLine4Italian, gJiminyCharacterWinnieThePoohLine5Italian, gJiminyCharacterWinnieThePoohLine6Italian, gJiminyCharacterWinnieThePoohLine7Italian,
};

const JiminyTextChar* gJiminyCharacterWinnieThePoohLinesSpanish[8] = {
    gJiminyCharacterWinnieThePoohLine0Spanish, gJiminyCharacterWinnieThePoohLine1Spanish, gJiminyCharacterWinnieThePoohLine2Spanish, gJiminyCharacterWinnieThePoohLine3Spanish,
    gJiminyCharacterWinnieThePoohLine4Spanish, gJiminyCharacterWinnieThePoohLine5Spanish, gJiminyCharacterWinnieThePoohLine6Spanish, gJiminyCharacterWinnieThePoohLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterPigletLines[6] = {
    gJiminyCharacterPigletLine0, gJiminyCharacterPigletLine1, gJiminyCharacterPigletLine2, gJiminyCharacterPigletLine3,
    gJiminyCharacterPigletLine4, gJiminyCharacterPigletLine5,
};

const JiminyTextChar* gJiminyCharacterPigletLinesFrench[6] = {
    gJiminyCharacterPigletLine0French, gJiminyCharacterPigletLine1French, gJiminyCharacterPigletLine2French, gJiminyCharacterPigletLine3French,
    gJiminyCharacterPigletLine4French, gJiminyCharacterPigletLine5French,
};

const JiminyTextChar* gJiminyCharacterPigletLinesGerman[7] = {
    gJiminyCharacterPigletLine0German, gJiminyCharacterPigletLine1German, gJiminyCharacterPigletLine2German, gJiminyCharacterPigletLine3German,
    gJiminyCharacterPigletLine4German, gJiminyCharacterPigletLine5German, gJiminyCharacterPigletLine6German,
};

const JiminyTextChar* gJiminyCharacterPigletLinesItalian[6] = {
    gJiminyCharacterPigletLine0Italian, gJiminyCharacterPigletLine1Italian, gJiminyCharacterPigletLine2Italian, gJiminyCharacterPigletLine3Italian,
    gJiminyCharacterPigletLine4Italian, gJiminyCharacterPigletLine5Italian,
};

const JiminyTextChar* gJiminyCharacterPigletLinesSpanish[6] = {
    gJiminyCharacterPigletLine0Spanish, gJiminyCharacterPigletLine1Spanish, gJiminyCharacterPigletLine2Spanish, gJiminyCharacterPigletLine3Spanish,
    gJiminyCharacterPigletLine4Spanish, gJiminyCharacterPigletLine5Spanish,
};

const JiminyTextChar* gJiminyCharacterOwlLines[6] = {
    gJiminyCharacterOwlLine0, gJiminyCharacterOwlLine1, gJiminyCharacterOwlLine2, gJiminyCharacterOwlLine3,
    gJiminyCharacterOwlLine4, gJiminyCharacterOwlLine5,
};

const JiminyTextChar* gJiminyCharacterOwlLinesFrench[7] = {
    gJiminyCharacterOwlLine0French, gJiminyCharacterOwlLine1French, gJiminyCharacterOwlLine2French, gJiminyCharacterOwlLine3French,
    gJiminyCharacterOwlLine4French, gJiminyCharacterOwlLine5French, gJiminyCharacterOwlLine6French,
};

const JiminyTextChar* gJiminyCharacterOwlLinesGerman[6] = {
    gJiminyCharacterOwlLine0German, gJiminyCharacterOwlLine1German, gJiminyCharacterOwlLine2German, gJiminyCharacterOwlLine3German,
    gJiminyCharacterOwlLine4German, gJiminyCharacterOwlLine5German,
};

const JiminyTextChar* gJiminyCharacterOwlLinesItalian[6] = {
    gJiminyCharacterOwlLine0Italian, gJiminyCharacterOwlLine1Italian, gJiminyCharacterOwlLine2Italian, gJiminyCharacterOwlLine3Italian,
    gJiminyCharacterOwlLine4Italian, gJiminyCharacterOwlLine5Italian,
};

const JiminyTextChar* gJiminyCharacterOwlLinesSpanish[5] = {
    gJiminyCharacterOwlLine0Spanish, gJiminyCharacterOwlLine1Spanish, gJiminyCharacterOwlLine2Spanish, gJiminyCharacterOwlLine3Spanish,
    gJiminyCharacterOwlLine4Spanish,
};

const JiminyTextChar* gJiminyCharacterRooLines[6] = {
    gJiminyCharacterRooLine0, gJiminyCharacterRooLine1, gJiminyCharacterRooLine2, gJiminyCharacterRooLine3,
    gJiminyCharacterRooLine4, gJiminyCharacterRooLine5,
};

const JiminyTextChar* gJiminyCharacterRooLinesFrench[6] = {
    gJiminyCharacterRooLine0French, gJiminyCharacterRooLine1French, gJiminyCharacterRooLine2French, gJiminyCharacterRooLine3French,
    gJiminyCharacterRooLine4French, gJiminyCharacterRooLine5French,
};

const JiminyTextChar* gJiminyCharacterRooLinesGerman[6] = {
    gJiminyCharacterRooLine0German, gJiminyCharacterRooLine1German, gJiminyCharacterRooLine2German, gJiminyCharacterRooLine3German,
    gJiminyCharacterRooLine4German, gJiminyCharacterRooLine5German,
};

const JiminyTextChar* gJiminyCharacterRooLinesItalian[6] = {
    gJiminyCharacterRooLine0Italian, gJiminyCharacterRooLine1Italian, gJiminyCharacterRooLine2Italian, gJiminyCharacterRooLine3Italian,
    gJiminyCharacterRooLine4Italian, gJiminyCharacterRooLine5Italian,
};

const JiminyTextChar* gJiminyCharacterRooLinesSpanish[6] = {
    gJiminyCharacterRooLine0Spanish, gJiminyCharacterRooLine1Spanish, gJiminyCharacterRooLine2Spanish, gJiminyCharacterRooLine3Spanish,
    gJiminyCharacterRooLine4Spanish, gJiminyCharacterRooLine5Spanish,
};

const JiminyTextChar* gJiminyCharacterEeyoreLines[8] = {
    gJiminyCharacterEeyoreLine0, gJiminyCharacterEeyoreLine1, gJiminyCharacterEeyoreLine2, gJiminyCharacterEeyoreLine3,
    gJiminyCharacterEeyoreLine4, gJiminyCharacterEeyoreLine5, gJiminyCharacterEeyoreLine6, gJiminyCharacterEeyoreLine7,
};

const JiminyTextChar* gJiminyCharacterEeyoreLinesFrench[9] = {
    gJiminyCharacterEeyoreLine0French, gJiminyCharacterEeyoreLine1French, gJiminyCharacterEeyoreLine2French, gJiminyCharacterEeyoreLine3French,
    gJiminyCharacterEeyoreLine4French, gJiminyCharacterEeyoreLine5French, gJiminyCharacterEeyoreLine6French, gJiminyCharacterEeyoreLine7French,
    gJiminyCharacterEeyoreLine8French,
};

const JiminyTextChar* gJiminyCharacterEeyoreLinesGerman[9] = {
    gJiminyCharacterEeyoreLine0German, gJiminyCharacterEeyoreLine1German, gJiminyCharacterEeyoreLine2German, gJiminyCharacterEeyoreLine3German,
    gJiminyCharacterEeyoreLine4German, gJiminyCharacterEeyoreLine5German, gJiminyCharacterEeyoreLine6German, gJiminyCharacterEeyoreLine7German,
    gJiminyCharacterEeyoreLine8German,
};

const JiminyTextChar* gJiminyCharacterEeyoreLinesItalian[7] = {
    gJiminyCharacterEeyoreLine0Italian, gJiminyCharacterEeyoreLine1Italian, gJiminyCharacterEeyoreLine2Italian, gJiminyCharacterEeyoreLine3Italian,
    gJiminyCharacterEeyoreLine4Italian, gJiminyCharacterEeyoreLine5Italian, gJiminyCharacterEeyoreLine6Italian,
};

const JiminyTextChar* gJiminyCharacterEeyoreLinesSpanish[8] = {
    gJiminyCharacterEeyoreLine0Spanish, gJiminyCharacterEeyoreLine1Spanish, gJiminyCharacterEeyoreLine2Spanish, gJiminyCharacterEeyoreLine3Spanish,
    gJiminyCharacterEeyoreLine4Spanish, gJiminyCharacterEeyoreLine5Spanish, gJiminyCharacterEeyoreLine6Spanish, gJiminyCharacterEeyoreLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterTiggerLines[8] = {
    gJiminyCharacterTiggerLine0, gJiminyCharacterTiggerLine1, gJiminyCharacterTiggerLine2, gJiminyCharacterTiggerLine3,
    gJiminyCharacterTiggerLine4, gJiminyCharacterTiggerLine5, gJiminyCharacterTiggerLine6, gJiminyCharacterTiggerLine7,
};

const JiminyTextChar* gJiminyCharacterTiggerLinesFrench[10] = {
    gJiminyCharacterTiggerLine0French, gJiminyCharacterTiggerLine1French, gJiminyCharacterTiggerLine2French, gJiminyCharacterTiggerLine3French,
    gJiminyCharacterTiggerLine4French, gJiminyCharacterTiggerLine5French, gJiminyCharacterTiggerLine6French, gJiminyCharacterTiggerLine7French,
    gJiminyCharacterTiggerLine8French, gJiminyCharacterTiggerLine9French,
};

const JiminyTextChar* gJiminyCharacterTiggerLinesGerman[9] = {
    gJiminyCharacterTiggerLine0German, gJiminyCharacterTiggerLine1German, gJiminyCharacterTiggerLine2German, gJiminyCharacterTiggerLine3German,
    gJiminyCharacterTiggerLine4German, gJiminyCharacterTiggerLine5German, gJiminyCharacterTiggerLine6German, gJiminyCharacterTiggerLine7German,
    gJiminyCharacterTiggerLine8German,
};

const JiminyTextChar* gJiminyCharacterTiggerLinesItalian[9] = {
    gJiminyCharacterTiggerLine0Italian, gJiminyCharacterTiggerLine1Italian, gJiminyCharacterTiggerLine2Italian, gJiminyCharacterTiggerLine3Italian,
    gJiminyCharacterTiggerLine4Italian, gJiminyCharacterTiggerLine5Italian, gJiminyCharacterTiggerLine6Italian, gJiminyCharacterTiggerLine7Italian,
    gJiminyCharacterTiggerLine8Italian,
};

const JiminyTextChar* gJiminyCharacterTiggerLinesSpanish[8] = {
    gJiminyCharacterTiggerLine0Spanish, gJiminyCharacterTiggerLine1Spanish, gJiminyCharacterTiggerLine2Spanish, gJiminyCharacterTiggerLine3Spanish,
    gJiminyCharacterTiggerLine4Spanish, gJiminyCharacterTiggerLine5Spanish, gJiminyCharacterTiggerLine6Spanish, gJiminyCharacterTiggerLine7Spanish,
};

const JiminyTextChar* gJiminyCharacterRabbitLines[9] = {
    gJiminyCharacterRabbitLine0, gJiminyCharacterRabbitLine1, gJiminyCharacterRabbitLine2, gJiminyCharacterRabbitLine3,
    gJiminyCharacterRabbitLine4, gJiminyCharacterRabbitLine5, gJiminyCharacterRabbitLine6, gJiminyCharacterRabbitLine7,
    gJiminyCharacterRabbitLine8,
};

const JiminyTextChar* gJiminyCharacterRabbitLinesFrench[9] = {
    gJiminyCharacterRabbitLine0French, gJiminyCharacterRabbitLine1French, gJiminyCharacterRabbitLine2French, gJiminyCharacterRabbitLine3French,
    gJiminyCharacterRabbitLine4French, gJiminyCharacterRabbitLine5French, gJiminyCharacterRabbitLine6French, gJiminyCharacterRabbitLine7French,
    gJiminyCharacterRabbitLine8French,
};

const JiminyTextChar* gJiminyCharacterRabbitLinesGerman[9] = {
    gJiminyCharacterRabbitLine0German, gJiminyCharacterRabbitLine1German, gJiminyCharacterRabbitLine2German, gJiminyCharacterRabbitLine3German,
    gJiminyCharacterRabbitLine4German, gJiminyCharacterRabbitLine5German, gJiminyCharacterRabbitLine6German, gJiminyCharacterRabbitLine7German,
    gJiminyCharacterRabbitLine8German,
};

const JiminyTextChar* gJiminyCharacterRabbitLinesItalian[9] = {
    gJiminyCharacterRabbitLine0Italian, gJiminyCharacterRabbitLine1Italian, gJiminyCharacterRabbitLine2Italian, gJiminyCharacterRabbitLine3Italian,
    gJiminyCharacterRabbitLine4Italian, gJiminyCharacterRabbitLine5Italian, gJiminyCharacterRabbitLine6Italian, gJiminyCharacterRabbitLine7Italian,
    gJiminyCharacterRabbitLine8Italian,
};

const JiminyTextChar* gJiminyCharacterRabbitLinesSpanish[9] = {
    gJiminyCharacterRabbitLine0Spanish, gJiminyCharacterRabbitLine1Spanish, gJiminyCharacterRabbitLine2Spanish, gJiminyCharacterRabbitLine3Spanish,
    gJiminyCharacterRabbitLine4Spanish, gJiminyCharacterRabbitLine5Spanish, gJiminyCharacterRabbitLine6Spanish, gJiminyCharacterRabbitLine7Spanish,
    gJiminyCharacterRabbitLine8Spanish,
};

const JiminyTextChar* gJiminyHeartlessGuardArmorLines[6] = {
    gJiminyHeartlessGuardArmorLine0, gJiminyHeartlessGuardArmorLine1, gJiminyHeartlessGuardArmorLine2, gJiminyHeartlessGuardArmorLine3,
    gJiminyHeartlessGuardArmorLine4, gJiminyHeartlessGuardArmorLine5,
};

const JiminyTextChar* gJiminyHeartlessGuardArmorLinesFrench[9] = {
    gJiminyHeartlessGuardArmorLine0French, gJiminyHeartlessGuardArmorLine1French, gJiminyHeartlessGuardArmorLine2French, gJiminyHeartlessGuardArmorLine3French,
    gJiminyHeartlessGuardArmorLine4French, gJiminyHeartlessGuardArmorLine5French, gJiminyHeartlessGuardArmorLine6French, gJiminyHeartlessGuardArmorLine7French,
    gJiminyHeartlessGuardArmorLine8French,
};

const JiminyTextChar* gJiminyHeartlessGuardArmorLinesGerman[8] = {
    gJiminyHeartlessGuardArmorLine0German, gJiminyHeartlessGuardArmorLine1German, gJiminyHeartlessGuardArmorLine2German, gJiminyHeartlessGuardArmorLine3German,
    gJiminyHeartlessGuardArmorLine4German, gJiminyHeartlessGuardArmorLine5German, gJiminyHeartlessGuardArmorLine6German, gJiminyHeartlessGuardArmorLine7German,
};

const JiminyTextChar* gJiminyHeartlessGuardArmorLinesItalian[7] = {
    gJiminyHeartlessGuardArmorLine0Italian, gJiminyHeartlessGuardArmorLine1Italian, gJiminyHeartlessGuardArmorLine2Italian, gJiminyHeartlessGuardArmorLine3Italian,
    gJiminyHeartlessGuardArmorLine4Italian, gJiminyHeartlessGuardArmorLine5Italian, gJiminyHeartlessGuardArmorLine6Italian,
};

const JiminyTextChar* gJiminyHeartlessGuardArmorLinesSpanish[8] = {
    gJiminyHeartlessGuardArmorLine0Spanish, gJiminyHeartlessGuardArmorLine1Spanish, gJiminyHeartlessGuardArmorLine2Spanish, gJiminyHeartlessGuardArmorLine3Spanish,
    gJiminyHeartlessGuardArmorLine4Spanish, gJiminyHeartlessGuardArmorLine5Spanish, gJiminyHeartlessGuardArmorLine6Spanish, gJiminyHeartlessGuardArmorLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessParasiteCageLines[10] = {
    gJiminyHeartlessParasiteCageLine0, gJiminyHeartlessParasiteCageLine1, gJiminyHeartlessParasiteCageLine2, gJiminyHeartlessParasiteCageLine3,
    gJiminyHeartlessParasiteCageLine4, gJiminyHeartlessParasiteCageLine5, gJiminyHeartlessParasiteCageLine6, gJiminyHeartlessParasiteCageLine7,
    gJiminyHeartlessParasiteCageLine8, gJiminyHeartlessParasiteCageLine9,
};

const JiminyTextChar* gJiminyHeartlessParasiteCageLinesFrench[12] = {
    gJiminyHeartlessParasiteCageLine0French, gJiminyHeartlessParasiteCageLine1French, gJiminyHeartlessParasiteCageLine2French, gJiminyHeartlessParasiteCageLine3French,
    gJiminyHeartlessParasiteCageLine4French, gJiminyHeartlessParasiteCageLine5French, gJiminyHeartlessParasiteCageLine6French, gJiminyHeartlessParasiteCageLine7French,
    gJiminyHeartlessParasiteCageLine8French, gJiminyHeartlessParasiteCageLine9French, gJiminyHeartlessParasiteCageLine10French, gJiminyHeartlessParasiteCageLine11French,
};

const JiminyTextChar* gJiminyHeartlessParasiteCageLinesGerman[12] = {
    gJiminyHeartlessParasiteCageLine0German, gJiminyHeartlessParasiteCageLine1German, gJiminyHeartlessParasiteCageLine2German, gJiminyHeartlessParasiteCageLine3German,
    gJiminyHeartlessParasiteCageLine4German, gJiminyHeartlessParasiteCageLine5German, gJiminyHeartlessParasiteCageLine6German, gJiminyHeartlessParasiteCageLine7German,
    gJiminyHeartlessParasiteCageLine8German, gJiminyHeartlessParasiteCageLine9German, gJiminyHeartlessParasiteCageLine10German, gJiminyHeartlessParasiteCageLine11German,
};

const JiminyTextChar* gJiminyHeartlessParasiteCageLinesItalian[10] = {
    gJiminyHeartlessParasiteCageLine0Italian, gJiminyHeartlessParasiteCageLine1Italian, gJiminyHeartlessParasiteCageLine2Italian, gJiminyHeartlessParasiteCageLine3Italian,
    gJiminyHeartlessParasiteCageLine4Italian, gJiminyHeartlessParasiteCageLine5Italian, gJiminyHeartlessParasiteCageLine6Italian, gJiminyHeartlessParasiteCageLine7Italian,
    gJiminyHeartlessParasiteCageLine8Italian, gJiminyHeartlessParasiteCageLine9Italian,
};

const JiminyTextChar* gJiminyHeartlessParasiteCageLinesSpanish[9] = {
    gJiminyHeartlessParasiteCageLine0Spanish, gJiminyHeartlessParasiteCageLine1Spanish, gJiminyHeartlessParasiteCageLine2Spanish, gJiminyHeartlessParasiteCageLine3Spanish,
    gJiminyHeartlessParasiteCageLine4Spanish, gJiminyHeartlessParasiteCageLine5Spanish, gJiminyHeartlessParasiteCageLine6Spanish, gJiminyHeartlessParasiteCageLine7Spanish,
    gJiminyHeartlessParasiteCageLine8Spanish,
};

const JiminyTextChar* gJiminyHeartlessTrickmasterLines[8] = {
    gJiminyHeartlessTrickmasterLine0, gJiminyHeartlessTrickmasterLine1, gJiminyHeartlessTrickmasterLine2, gJiminyHeartlessTrickmasterLine3,
    gJiminyHeartlessTrickmasterLine4, gJiminyHeartlessTrickmasterLine5, gJiminyHeartlessTrickmasterLine6, gJiminyHeartlessTrickmasterLine7,
};

const JiminyTextChar* gJiminyHeartlessTrickmasterLinesFrench[10] = {
    gJiminyHeartlessTrickmasterLine0French, gJiminyHeartlessTrickmasterLine1French, gJiminyHeartlessTrickmasterLine2French, gJiminyHeartlessTrickmasterLine3French,
    gJiminyHeartlessTrickmasterLine4French, gJiminyHeartlessTrickmasterLine5French, gJiminyHeartlessTrickmasterLine6French, gJiminyHeartlessTrickmasterLine7French,
    gJiminyHeartlessTrickmasterLine8French, gJiminyHeartlessTrickmasterLine9French,
};

const JiminyTextChar* gJiminyHeartlessTrickmasterLinesGerman[11] = {
    gJiminyHeartlessTrickmasterLine0German, gJiminyHeartlessTrickmasterLine1German, gJiminyHeartlessTrickmasterLine2German, gJiminyHeartlessTrickmasterLine3German,
    gJiminyHeartlessTrickmasterLine4German, gJiminyHeartlessTrickmasterLine5German, gJiminyHeartlessTrickmasterLine6German, gJiminyHeartlessTrickmasterLine7German,
    gJiminyHeartlessTrickmasterLine8German, gJiminyHeartlessTrickmasterLine9German, gJiminyHeartlessTrickmasterLine10German,
};

const JiminyTextChar* gJiminyHeartlessTrickmasterLinesItalian[10] = {
    gJiminyHeartlessTrickmasterLine0Italian, gJiminyHeartlessTrickmasterLine1Italian, gJiminyHeartlessTrickmasterLine2Italian, gJiminyHeartlessTrickmasterLine3Italian,
    gJiminyHeartlessTrickmasterLine4Italian, gJiminyHeartlessTrickmasterLine5Italian, gJiminyHeartlessTrickmasterLine6Italian, gJiminyHeartlessTrickmasterLine7Italian,
    gJiminyHeartlessTrickmasterLine8Italian, gJiminyHeartlessTrickmasterLine9Italian,
};

const JiminyTextChar* gJiminyHeartlessTrickmasterLinesSpanish[11] = {
    gJiminyHeartlessTrickmasterLine0Spanish, gJiminyHeartlessTrickmasterLine1Spanish, gJiminyHeartlessTrickmasterLine2Spanish, gJiminyHeartlessTrickmasterLine3Spanish,
    gJiminyHeartlessTrickmasterLine4Spanish, gJiminyHeartlessTrickmasterLine5Spanish, gJiminyHeartlessTrickmasterLine6Spanish, gJiminyHeartlessTrickmasterLine7Spanish,
    gJiminyHeartlessTrickmasterLine8Spanish, gJiminyHeartlessTrickmasterLine9Spanish, gJiminyHeartlessTrickmasterLine10Spanish,
};

const JiminyTextChar* gJiminyHeartlessDarksideLines[7] = {
    gJiminyHeartlessDarksideLine0, gJiminyHeartlessDarksideLine1, gJiminyHeartlessDarksideLine2, gJiminyHeartlessDarksideLine3,
    gJiminyHeartlessDarksideLine4, gJiminyHeartlessDarksideLine5, gJiminyHeartlessDarksideLine6,
};

const JiminyTextChar* gJiminyHeartlessDarksideLinesFrench[9] = {
    gJiminyHeartlessDarksideLine0French, gJiminyHeartlessDarksideLine1French, gJiminyHeartlessDarksideLine2French, gJiminyHeartlessDarksideLine3French,
    gJiminyHeartlessDarksideLine4French, gJiminyHeartlessDarksideLine5French, gJiminyHeartlessDarksideLine6French, gJiminyHeartlessDarksideLine7French,
    gJiminyHeartlessDarksideLine8French,
};

const JiminyTextChar* gJiminyHeartlessDarksideLinesGerman[10] = {
    gJiminyHeartlessDarksideLine0German, gJiminyHeartlessDarksideLine1German, gJiminyHeartlessDarksideLine2German, gJiminyHeartlessDarksideLine3German,
    gJiminyHeartlessDarksideLine4German, gJiminyHeartlessDarksideLine5German, gJiminyHeartlessDarksideLine6German, gJiminyHeartlessDarksideLine7German,
    gJiminyHeartlessDarksideLine8German, gJiminyHeartlessDarksideLine9German,
};

const JiminyTextChar* gJiminyHeartlessDarksideLinesItalian[7] = {
    gJiminyHeartlessDarksideLine0Italian, gJiminyHeartlessDarksideLine1Italian, gJiminyHeartlessDarksideLine2Italian, gJiminyHeartlessDarksideLine3Italian,
    gJiminyHeartlessDarksideLine4Italian, gJiminyHeartlessDarksideLine5Italian, gJiminyHeartlessDarksideLine6Italian,
};

const JiminyTextChar* gJiminyHeartlessDarksideLinesSpanish[7] = {
    gJiminyHeartlessDarksideLine0Spanish, gJiminyHeartlessDarksideLine1Spanish, gJiminyHeartlessDarksideLine2Spanish, gJiminyHeartlessDarksideLine3Spanish,
    gJiminyHeartlessDarksideLine4Spanish, gJiminyHeartlessDarksideLine5Spanish, gJiminyHeartlessDarksideLine6Spanish,
};

const JiminyTextChar* gJiminyHeartlessShadowLines[9] = {
    gJiminyHeartlessShadowLine0, gJiminyHeartlessShadowLine1, gJiminyHeartlessShadowLine2, gJiminyHeartlessShadowLine3,
    gJiminyHeartlessShadowLine4, gJiminyHeartlessShadowLine5, gJiminyHeartlessShadowLine6, gJiminyHeartlessShadowLine7,
    gJiminyHeartlessShadowLine8,
};

const JiminyTextChar* gJiminyHeartlessShadowLinesFrench[9] = {
    gJiminyHeartlessShadowLine0French, gJiminyHeartlessShadowLine1French, gJiminyHeartlessShadowLine2French, gJiminyHeartlessShadowLine3French,
    gJiminyHeartlessShadowLine4French, gJiminyHeartlessShadowLine5French, gJiminyHeartlessShadowLine6French, gJiminyHeartlessShadowLine7French,
    gJiminyHeartlessShadowLine8French,
};

const JiminyTextChar* gJiminyHeartlessShadowLinesGerman[11] = {
    gJiminyHeartlessShadowLine0German, gJiminyHeartlessShadowLine1German, gJiminyHeartlessShadowLine2German, gJiminyHeartlessShadowLine3German,
    gJiminyHeartlessShadowLine4German, gJiminyHeartlessShadowLine5German, gJiminyHeartlessShadowLine6German, gJiminyHeartlessShadowLine7German,
    gJiminyHeartlessShadowLine8German, gJiminyHeartlessShadowLine9German, gJiminyHeartlessShadowLine10German,
};

const JiminyTextChar* gJiminyHeartlessShadowLinesItalian[9] = {
    gJiminyHeartlessShadowLine0Italian, gJiminyHeartlessShadowLine1Italian, gJiminyHeartlessShadowLine2Italian, gJiminyHeartlessShadowLine3Italian,
    gJiminyHeartlessShadowLine4Italian, gJiminyHeartlessShadowLine5Italian, gJiminyHeartlessShadowLine6Italian, gJiminyHeartlessShadowLine7Italian,
    gJiminyHeartlessShadowLine8Italian,
};

const JiminyTextChar* gJiminyHeartlessShadowLinesSpanish[10] = {
    gJiminyHeartlessShadowLine0Spanish, gJiminyHeartlessShadowLine1Spanish, gJiminyHeartlessShadowLine2Spanish, gJiminyHeartlessShadowLine3Spanish,
    gJiminyHeartlessShadowLine4Spanish, gJiminyHeartlessShadowLine5Spanish, gJiminyHeartlessShadowLine6Spanish, gJiminyHeartlessShadowLine7Spanish,
    gJiminyHeartlessShadowLine8Spanish, gJiminyHeartlessShadowLine9Spanish,
};

const JiminyTextChar* gJiminyHeartlessSoldierLines[7] = {
    gJiminyHeartlessSoldierLine0, gJiminyHeartlessSoldierLine1, gJiminyHeartlessSoldierLine2, gJiminyHeartlessSoldierLine3,
    gJiminyHeartlessSoldierLine4, gJiminyHeartlessSoldierLine5, gJiminyHeartlessSoldierLine6,
};

const JiminyTextChar* gJiminyHeartlessSoldierLinesFrench[9] = {
    gJiminyHeartlessSoldierLine0French, gJiminyHeartlessSoldierLine1French, gJiminyHeartlessSoldierLine2French, gJiminyHeartlessSoldierLine3French,
    gJiminyHeartlessSoldierLine4French, gJiminyHeartlessSoldierLine5French, gJiminyHeartlessSoldierLine6French, gJiminyHeartlessSoldierLine7French,
    gJiminyHeartlessSoldierLine8French,
};

const JiminyTextChar* gJiminyHeartlessSoldierLinesGerman[9] = {
    gJiminyHeartlessSoldierLine0German, gJiminyHeartlessSoldierLine1German, gJiminyHeartlessSoldierLine2German, gJiminyHeartlessSoldierLine3German,
    gJiminyHeartlessSoldierLine4German, gJiminyHeartlessSoldierLine5German, gJiminyHeartlessSoldierLine6German, gJiminyHeartlessSoldierLine7German,
    gJiminyHeartlessSoldierLine8German,
};

const JiminyTextChar* gJiminyHeartlessSoldierLinesItalian[7] = {
    gJiminyHeartlessSoldierLine0Italian, gJiminyHeartlessSoldierLine1Italian, gJiminyHeartlessSoldierLine2Italian, gJiminyHeartlessSoldierLine3Italian,
    gJiminyHeartlessSoldierLine4Italian, gJiminyHeartlessSoldierLine5Italian, gJiminyHeartlessSoldierLine6Italian,
};

const JiminyTextChar* gJiminyHeartlessSoldierLinesSpanish[7] = {
    gJiminyHeartlessSoldierLine0Spanish, gJiminyHeartlessSoldierLine1Spanish, gJiminyHeartlessSoldierLine2Spanish, gJiminyHeartlessSoldierLine3Spanish,
    gJiminyHeartlessSoldierLine4Spanish, gJiminyHeartlessSoldierLine5Spanish, gJiminyHeartlessSoldierLine6Spanish,
};

const JiminyTextChar* gJiminyHeartlessLargeBodyLines[10] = {
    gJiminyHeartlessLargeBodyLine0, gJiminyHeartlessLargeBodyLine1, gJiminyHeartlessLargeBodyLine2, gJiminyHeartlessLargeBodyLine3,
    gJiminyHeartlessLargeBodyLine4, gJiminyHeartlessLargeBodyLine5, gJiminyHeartlessLargeBodyLine6, gJiminyHeartlessLargeBodyLine7,
    gJiminyHeartlessLargeBodyLine8, gJiminyHeartlessLargeBodyLine9,
};

const JiminyTextChar* gJiminyHeartlessLargeBodyLinesFrench[12] = {
    gJiminyHeartlessLargeBodyLine0French, gJiminyHeartlessLargeBodyLine1French, gJiminyHeartlessLargeBodyLine2French, gJiminyHeartlessLargeBodyLine3French,
    gJiminyHeartlessLargeBodyLine4French, gJiminyHeartlessLargeBodyLine5French, gJiminyHeartlessLargeBodyLine6French, gJiminyHeartlessLargeBodyLine7French,
    gJiminyHeartlessLargeBodyLine8French, gJiminyHeartlessLargeBodyLine9French, gJiminyHeartlessLargeBodyLine10French, gJiminyHeartlessLargeBodyLine11French,
};

const JiminyTextChar* gJiminyHeartlessLargeBodyLinesGerman[14] = {
    gJiminyHeartlessLargeBodyLine0German, gJiminyHeartlessLargeBodyLine1German, gJiminyHeartlessLargeBodyLine2German, gJiminyHeartlessLargeBodyLine3German,
    gJiminyHeartlessLargeBodyLine4German, gJiminyHeartlessLargeBodyLine5German, gJiminyHeartlessLargeBodyLine6German, gJiminyHeartlessLargeBodyLine7German,
    gJiminyHeartlessLargeBodyLine8German, gJiminyHeartlessLargeBodyLine9German, gJiminyHeartlessLargeBodyLine10German, gJiminyHeartlessLargeBodyLine11German,
    gJiminyHeartlessLargeBodyLine12German, gJiminyHeartlessLargeBodyLine13German,
};

const JiminyTextChar* gJiminyHeartlessLargeBodyLinesItalian[11] = {
    gJiminyHeartlessLargeBodyLine0Italian, gJiminyHeartlessLargeBodyLine1Italian, gJiminyHeartlessLargeBodyLine2Italian, gJiminyHeartlessLargeBodyLine3Italian,
    gJiminyHeartlessLargeBodyLine4Italian, gJiminyHeartlessLargeBodyLine5Italian, gJiminyHeartlessLargeBodyLine6Italian, gJiminyHeartlessLargeBodyLine7Italian,
    gJiminyHeartlessLargeBodyLine8Italian, gJiminyHeartlessLargeBodyLine9Italian, gJiminyHeartlessLargeBodyLine10Italian,
};

const JiminyTextChar* gJiminyHeartlessLargeBodyLinesSpanish[13] = {
    gJiminyHeartlessLargeBodyLine0Spanish, gJiminyHeartlessLargeBodyLine1Spanish, gJiminyHeartlessLargeBodyLine2Spanish, gJiminyHeartlessLargeBodyLine3Spanish,
    gJiminyHeartlessLargeBodyLine4Spanish, gJiminyHeartlessLargeBodyLine5Spanish, gJiminyHeartlessLargeBodyLine6Spanish, gJiminyHeartlessLargeBodyLine7Spanish,
    gJiminyHeartlessLargeBodyLine8Spanish, gJiminyHeartlessLargeBodyLine9Spanish, gJiminyHeartlessLargeBodyLine10Spanish, gJiminyHeartlessLargeBodyLine11Spanish,
    gJiminyHeartlessLargeBodyLine12Spanish,
};

const JiminyTextChar* gJiminyHeartlessRedNocturneLines[9] = {
    gJiminyHeartlessRedNocturneLine0, gJiminyHeartlessRedNocturneLine1, gJiminyHeartlessRedNocturneLine2, gJiminyHeartlessRedNocturneLine3,
    gJiminyHeartlessRedNocturneLine4, gJiminyHeartlessRedNocturneLine5, gJiminyHeartlessRedNocturneLine6, gJiminyHeartlessRedNocturneLine7,
    gJiminyHeartlessRedNocturneLine8,
};

const JiminyTextChar* gJiminyHeartlessRedNocturneLinesFrench[9] = {
    gJiminyHeartlessRedNocturneLine0French, gJiminyHeartlessRedNocturneLine1French, gJiminyHeartlessRedNocturneLine2French, gJiminyHeartlessRedNocturneLine3French,
    gJiminyHeartlessRedNocturneLine4French, gJiminyHeartlessRedNocturneLine5French, gJiminyHeartlessRedNocturneLine6French, gJiminyHeartlessRedNocturneLine7French,
    gJiminyHeartlessRedNocturneLine8French,
};

const JiminyTextChar* gJiminyHeartlessRedNocturneLinesGerman[12] = {
    gJiminyHeartlessRedNocturneLine0German, gJiminyHeartlessRedNocturneLine1German, gJiminyHeartlessRedNocturneLine2German, gJiminyHeartlessRedNocturneLine3German,
    gJiminyHeartlessRedNocturneLine4German, gJiminyHeartlessRedNocturneLine5German, gJiminyHeartlessRedNocturneLine6German, gJiminyHeartlessRedNocturneLine7German,
    gJiminyHeartlessRedNocturneLine8German, gJiminyHeartlessRedNocturneLine9German, gJiminyHeartlessRedNocturneLine10German, gJiminyHeartlessRedNocturneLine11German,
};

const JiminyTextChar* gJiminyHeartlessRedNocturneLinesItalian[11] = {
    gJiminyHeartlessRedNocturneLine0Italian, gJiminyHeartlessRedNocturneLine1Italian, gJiminyHeartlessRedNocturneLine2Italian, gJiminyHeartlessRedNocturneLine3Italian,
    gJiminyHeartlessRedNocturneLine4Italian, gJiminyHeartlessRedNocturneLine5Italian, gJiminyHeartlessRedNocturneLine6Italian, gJiminyHeartlessRedNocturneLine7Italian,
    gJiminyHeartlessRedNocturneLine8Italian, gJiminyHeartlessRedNocturneLine9Italian, gJiminyHeartlessRedNocturneLine10Italian,
};

const JiminyTextChar* gJiminyHeartlessRedNocturneLinesSpanish[9] = {
    gJiminyHeartlessRedNocturneLine0Spanish, gJiminyHeartlessRedNocturneLine1Spanish, gJiminyHeartlessRedNocturneLine2Spanish, gJiminyHeartlessRedNocturneLine3Spanish,
    gJiminyHeartlessRedNocturneLine4Spanish, gJiminyHeartlessRedNocturneLine5Spanish, gJiminyHeartlessRedNocturneLine6Spanish, gJiminyHeartlessRedNocturneLine7Spanish,
    gJiminyHeartlessRedNocturneLine8Spanish,
};

const JiminyTextChar* gJiminyHeartlessBlueRhapsodyLines[9] = {
    gJiminyHeartlessBlueRhapsodyLine0, gJiminyHeartlessBlueRhapsodyLine1, gJiminyHeartlessBlueRhapsodyLine2, gJiminyHeartlessBlueRhapsodyLine3,
    gJiminyHeartlessBlueRhapsodyLine4, gJiminyHeartlessBlueRhapsodyLine5, gJiminyHeartlessBlueRhapsodyLine6, gJiminyHeartlessBlueRhapsodyLine7,
    gJiminyHeartlessBlueRhapsodyLine8,
};

const JiminyTextChar* gJiminyHeartlessBlueRhapsodyLinesFrench[10] = {
    gJiminyHeartlessBlueRhapsodyLine0French, gJiminyHeartlessBlueRhapsodyLine1French, gJiminyHeartlessBlueRhapsodyLine2French, gJiminyHeartlessBlueRhapsodyLine3French,
    gJiminyHeartlessBlueRhapsodyLine4French, gJiminyHeartlessBlueRhapsodyLine5French, gJiminyHeartlessBlueRhapsodyLine6French, gJiminyHeartlessBlueRhapsodyLine7French,
    gJiminyHeartlessBlueRhapsodyLine8French, gJiminyHeartlessBlueRhapsodyLine9French,
};

const JiminyTextChar* gJiminyHeartlessBlueRhapsodyLinesGerman[9] = {
    gJiminyHeartlessBlueRhapsodyLine0German, gJiminyHeartlessBlueRhapsodyLine1German, gJiminyHeartlessBlueRhapsodyLine2German, gJiminyHeartlessBlueRhapsodyLine3German,
    gJiminyHeartlessBlueRhapsodyLine4German, gJiminyHeartlessBlueRhapsodyLine5German, gJiminyHeartlessBlueRhapsodyLine6German, gJiminyHeartlessBlueRhapsodyLine7German,
    gJiminyHeartlessBlueRhapsodyLine8German,
};

const JiminyTextChar* gJiminyHeartlessBlueRhapsodyLinesItalian[8] = {
    gJiminyHeartlessBlueRhapsodyLine0Italian, gJiminyHeartlessBlueRhapsodyLine1Italian, gJiminyHeartlessBlueRhapsodyLine2Italian, gJiminyHeartlessBlueRhapsodyLine3Italian,
    gJiminyHeartlessBlueRhapsodyLine4Italian, gJiminyHeartlessBlueRhapsodyLine5Italian, gJiminyHeartlessBlueRhapsodyLine6Italian, gJiminyHeartlessBlueRhapsodyLine7Italian,
};

const JiminyTextChar* gJiminyHeartlessBlueRhapsodyLinesSpanish[8] = {
    gJiminyHeartlessBlueRhapsodyLine0Spanish, gJiminyHeartlessBlueRhapsodyLine1Spanish, gJiminyHeartlessBlueRhapsodyLine2Spanish, gJiminyHeartlessBlueRhapsodyLine3Spanish,
    gJiminyHeartlessBlueRhapsodyLine4Spanish, gJiminyHeartlessBlueRhapsodyLine5Spanish, gJiminyHeartlessBlueRhapsodyLine6Spanish, gJiminyHeartlessBlueRhapsodyLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessYellowOperaLines[9] = {
    gJiminyHeartlessYellowOperaLine0, gJiminyHeartlessYellowOperaLine1, gJiminyHeartlessYellowOperaLine2, gJiminyHeartlessYellowOperaLine3,
    gJiminyHeartlessYellowOperaLine4, gJiminyHeartlessYellowOperaLine5, gJiminyHeartlessYellowOperaLine6, gJiminyHeartlessYellowOperaLine7,
    gJiminyHeartlessYellowOperaLine8,
};

const JiminyTextChar* gJiminyHeartlessYellowOperaLinesFrench[8] = {
    gJiminyHeartlessYellowOperaLine0French, gJiminyHeartlessYellowOperaLine1French, gJiminyHeartlessYellowOperaLine2French, gJiminyHeartlessYellowOperaLine3French,
    gJiminyHeartlessYellowOperaLine4French, gJiminyHeartlessYellowOperaLine5French, gJiminyHeartlessYellowOperaLine6French, gJiminyHeartlessYellowOperaLine7French,
};

const JiminyTextChar* gJiminyHeartlessYellowOperaLinesGerman[9] = {
    gJiminyHeartlessYellowOperaLine0German, gJiminyHeartlessYellowOperaLine1German, gJiminyHeartlessYellowOperaLine2German, gJiminyHeartlessYellowOperaLine3German,
    gJiminyHeartlessYellowOperaLine4German, gJiminyHeartlessYellowOperaLine5German, gJiminyHeartlessYellowOperaLine6German, gJiminyHeartlessYellowOperaLine7German,
    gJiminyHeartlessYellowOperaLine8German,
};

const JiminyTextChar* gJiminyHeartlessYellowOperaLinesItalian[8] = {
    gJiminyHeartlessYellowOperaLine0Italian, gJiminyHeartlessYellowOperaLine1Italian, gJiminyHeartlessYellowOperaLine2Italian, gJiminyHeartlessYellowOperaLine3Italian,
    gJiminyHeartlessYellowOperaLine4Italian, gJiminyHeartlessYellowOperaLine5Italian, gJiminyHeartlessYellowOperaLine6Italian, gJiminyHeartlessYellowOperaLine7Italian,
};

const JiminyTextChar* gJiminyHeartlessYellowOperaLinesSpanish[8] = {
    gJiminyHeartlessYellowOperaLine0Spanish, gJiminyHeartlessYellowOperaLine1Spanish, gJiminyHeartlessYellowOperaLine2Spanish, gJiminyHeartlessYellowOperaLine3Spanish,
    gJiminyHeartlessYellowOperaLine4Spanish, gJiminyHeartlessYellowOperaLine5Spanish, gJiminyHeartlessYellowOperaLine6Spanish, gJiminyHeartlessYellowOperaLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessGreenRequiemLines[11] = {
    gJiminyHeartlessGreenRequiemLine0, gJiminyHeartlessGreenRequiemLine1, gJiminyHeartlessGreenRequiemLine2, gJiminyHeartlessGreenRequiemLine3,
    gJiminyHeartlessGreenRequiemLine4, gJiminyHeartlessGreenRequiemLine5, gJiminyHeartlessGreenRequiemLine6, gJiminyHeartlessGreenRequiemLine7,
    gJiminyHeartlessGreenRequiemLine8, gJiminyHeartlessGreenRequiemLine9, gJiminyHeartlessGreenRequiemLine10,
};

const JiminyTextChar* gJiminyHeartlessGreenRequiemLinesFrench[12] = {
    gJiminyHeartlessGreenRequiemLine0French, gJiminyHeartlessGreenRequiemLine1French, gJiminyHeartlessGreenRequiemLine2French, gJiminyHeartlessGreenRequiemLine3French,
    gJiminyHeartlessGreenRequiemLine4French, gJiminyHeartlessGreenRequiemLine5French, gJiminyHeartlessGreenRequiemLine6French, gJiminyHeartlessGreenRequiemLine7French,
    gJiminyHeartlessGreenRequiemLine8French, gJiminyHeartlessGreenRequiemLine9French, gJiminyHeartlessGreenRequiemLine10French, gJiminyHeartlessGreenRequiemLine11French,
};

const JiminyTextChar* gJiminyHeartlessGreenRequiemLinesGerman[13] = {
    gJiminyHeartlessGreenRequiemLine0German, gJiminyHeartlessGreenRequiemLine1German, gJiminyHeartlessGreenRequiemLine2German, gJiminyHeartlessGreenRequiemLine3German,
    gJiminyHeartlessGreenRequiemLine4German, gJiminyHeartlessGreenRequiemLine5German, gJiminyHeartlessGreenRequiemLine6German, gJiminyHeartlessGreenRequiemLine7German,
    gJiminyHeartlessGreenRequiemLine8German, gJiminyHeartlessGreenRequiemLine9German, gJiminyHeartlessGreenRequiemLine10German, gJiminyHeartlessGreenRequiemLine11German,
    gJiminyHeartlessGreenRequiemLine12German,
};

const JiminyTextChar* gJiminyHeartlessGreenRequiemLinesItalian[11] = {
    gJiminyHeartlessGreenRequiemLine0Italian, gJiminyHeartlessGreenRequiemLine1Italian, gJiminyHeartlessGreenRequiemLine2Italian, gJiminyHeartlessGreenRequiemLine3Italian,
    gJiminyHeartlessGreenRequiemLine4Italian, gJiminyHeartlessGreenRequiemLine5Italian, gJiminyHeartlessGreenRequiemLine6Italian, gJiminyHeartlessGreenRequiemLine7Italian,
    gJiminyHeartlessGreenRequiemLine8Italian, gJiminyHeartlessGreenRequiemLine9Italian, gJiminyHeartlessGreenRequiemLine10Italian,
};

const JiminyTextChar* gJiminyHeartlessGreenRequiemLinesSpanish[10] = {
    gJiminyHeartlessGreenRequiemLine0Spanish, gJiminyHeartlessGreenRequiemLine1Spanish, gJiminyHeartlessGreenRequiemLine2Spanish, gJiminyHeartlessGreenRequiemLine3Spanish,
    gJiminyHeartlessGreenRequiemLine4Spanish, gJiminyHeartlessGreenRequiemLine5Spanish, gJiminyHeartlessGreenRequiemLine6Spanish, gJiminyHeartlessGreenRequiemLine7Spanish,
    gJiminyHeartlessGreenRequiemLine8Spanish, gJiminyHeartlessGreenRequiemLine9Spanish,
};

const JiminyTextChar* gJiminyHeartlessPowerwildLines[7] = {
    gJiminyHeartlessPowerwildLine0, gJiminyHeartlessPowerwildLine1, gJiminyHeartlessPowerwildLine2, gJiminyHeartlessPowerwildLine3,
    gJiminyHeartlessPowerwildLine4, gJiminyHeartlessPowerwildLine5, gJiminyHeartlessPowerwildLine6,
};

const JiminyTextChar* gJiminyHeartlessPowerwildLinesFrench[6] = {
    gJiminyHeartlessPowerwildLine0French, gJiminyHeartlessPowerwildLine1French, gJiminyHeartlessPowerwildLine2French, gJiminyHeartlessPowerwildLine3French,
    gJiminyHeartlessPowerwildLine4French, gJiminyHeartlessPowerwildLine5French,
};

const JiminyTextChar* gJiminyHeartlessPowerwildLinesGerman[9] = {
    gJiminyHeartlessPowerwildLine0German, gJiminyHeartlessPowerwildLine1German, gJiminyHeartlessPowerwildLine2German, gJiminyHeartlessPowerwildLine3German,
    gJiminyHeartlessPowerwildLine4German, gJiminyHeartlessPowerwildLine5German, gJiminyHeartlessPowerwildLine6German, gJiminyHeartlessPowerwildLine7German,
    gJiminyHeartlessPowerwildLine8German,
};

const JiminyTextChar* gJiminyHeartlessPowerwildLinesItalian[8] = {
    gJiminyHeartlessPowerwildLine0Italian, gJiminyHeartlessPowerwildLine1Italian, gJiminyHeartlessPowerwildLine2Italian, gJiminyHeartlessPowerwildLine3Italian,
    gJiminyHeartlessPowerwildLine4Italian, gJiminyHeartlessPowerwildLine5Italian, gJiminyHeartlessPowerwildLine6Italian, gJiminyHeartlessPowerwildLine7Italian,
};

const JiminyTextChar* gJiminyHeartlessPowerwildLinesSpanish[8] = {
    gJiminyHeartlessPowerwildLine0Spanish, gJiminyHeartlessPowerwildLine1Spanish, gJiminyHeartlessPowerwildLine2Spanish, gJiminyHeartlessPowerwildLine3Spanish,
    gJiminyHeartlessPowerwildLine4Spanish, gJiminyHeartlessPowerwildLine5Spanish, gJiminyHeartlessPowerwildLine6Spanish, gJiminyHeartlessPowerwildLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessBouncywildLines[6] = {
    gJiminyHeartlessBouncywildLine0, gJiminyHeartlessBouncywildLine1, gJiminyHeartlessBouncywildLine2, gJiminyHeartlessBouncywildLine3,
    gJiminyHeartlessBouncywildLine4, gJiminyHeartlessBouncywildLine5,
};

const JiminyTextChar* gJiminyHeartlessBouncywildLinesFrench[8] = {
    gJiminyHeartlessBouncywildLine0French, gJiminyHeartlessBouncywildLine1French, gJiminyHeartlessBouncywildLine2French, gJiminyHeartlessBouncywildLine3French,
    gJiminyHeartlessBouncywildLine4French, gJiminyHeartlessBouncywildLine5French, gJiminyHeartlessBouncywildLine6French, gJiminyHeartlessBouncywildLine7French,
};

const JiminyTextChar* gJiminyHeartlessBouncywildLinesGerman[10] = {
    gJiminyHeartlessBouncywildLine0German, gJiminyHeartlessBouncywildLine1German, gJiminyHeartlessBouncywildLine2German, gJiminyHeartlessBouncywildLine3German,
    gJiminyHeartlessBouncywildLine4German, gJiminyHeartlessBouncywildLine5German, gJiminyHeartlessBouncywildLine6German, gJiminyHeartlessBouncywildLine7German,
    gJiminyHeartlessBouncywildLine8German, gJiminyHeartlessBouncywildLine9German,
};

const JiminyTextChar* gJiminyHeartlessBouncywildLinesItalian[7] = {
    gJiminyHeartlessBouncywildLine0Italian, gJiminyHeartlessBouncywildLine1Italian, gJiminyHeartlessBouncywildLine2Italian, gJiminyHeartlessBouncywildLine3Italian,
    gJiminyHeartlessBouncywildLine4Italian, gJiminyHeartlessBouncywildLine5Italian, gJiminyHeartlessBouncywildLine6Italian,
};

const JiminyTextChar* gJiminyHeartlessBouncywildLinesSpanish[8] = {
    gJiminyHeartlessBouncywildLine0Spanish, gJiminyHeartlessBouncywildLine1Spanish, gJiminyHeartlessBouncywildLine2Spanish, gJiminyHeartlessBouncywildLine3Spanish,
    gJiminyHeartlessBouncywildLine4Spanish, gJiminyHeartlessBouncywildLine5Spanish, gJiminyHeartlessBouncywildLine6Spanish, gJiminyHeartlessBouncywildLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessAirSoldierLines[10] = {
    gJiminyHeartlessAirSoldierLine0, gJiminyHeartlessAirSoldierLine1, gJiminyHeartlessAirSoldierLine2, gJiminyHeartlessAirSoldierLine3,
    gJiminyHeartlessAirSoldierLine4, gJiminyHeartlessAirSoldierLine5, gJiminyHeartlessAirSoldierLine6, gJiminyHeartlessAirSoldierLine7,
    gJiminyHeartlessAirSoldierLine8, gJiminyHeartlessAirSoldierLine9,
};

const JiminyTextChar* gJiminyHeartlessAirSoldierLinesFrench[10] = {
    gJiminyHeartlessAirSoldierLine0French, gJiminyHeartlessAirSoldierLine1French, gJiminyHeartlessAirSoldierLine2French, gJiminyHeartlessAirSoldierLine3French,
    gJiminyHeartlessAirSoldierLine4French, gJiminyHeartlessAirSoldierLine5French, gJiminyHeartlessAirSoldierLine6French, gJiminyHeartlessAirSoldierLine7French,
    gJiminyHeartlessAirSoldierLine8French, gJiminyHeartlessAirSoldierLine9French,
};

const JiminyTextChar* gJiminyHeartlessAirSoldierLinesGerman[14] = {
    gJiminyHeartlessAirSoldierLine0German, gJiminyHeartlessAirSoldierLine1German, gJiminyHeartlessAirSoldierLine2German, gJiminyHeartlessAirSoldierLine3German,
    gJiminyHeartlessAirSoldierLine4German, gJiminyHeartlessAirSoldierLine5German, gJiminyHeartlessAirSoldierLine6German, gJiminyHeartlessAirSoldierLine7German,
    gJiminyHeartlessAirSoldierLine8German, gJiminyHeartlessAirSoldierLine9German, gJiminyHeartlessAirSoldierLine10German, gJiminyHeartlessAirSoldierLine11German,
    gJiminyHeartlessAirSoldierLine12German, gJiminyHeartlessAirSoldierLine13German,
};

const JiminyTextChar* gJiminyHeartlessAirSoldierLinesItalian[9] = {
    gJiminyHeartlessAirSoldierLine0Italian, gJiminyHeartlessAirSoldierLine1Italian, gJiminyHeartlessAirSoldierLine2Italian, gJiminyHeartlessAirSoldierLine3Italian,
    gJiminyHeartlessAirSoldierLine4Italian, gJiminyHeartlessAirSoldierLine5Italian, gJiminyHeartlessAirSoldierLine6Italian, gJiminyHeartlessAirSoldierLine7Italian,
    gJiminyHeartlessAirSoldierLine8Italian,
};

const JiminyTextChar* gJiminyHeartlessAirSoldierLinesSpanish[8] = {
    gJiminyHeartlessAirSoldierLine0Spanish, gJiminyHeartlessAirSoldierLine1Spanish, gJiminyHeartlessAirSoldierLine2Spanish, gJiminyHeartlessAirSoldierLine3Spanish,
    gJiminyHeartlessAirSoldierLine4Spanish, gJiminyHeartlessAirSoldierLine5Spanish, gJiminyHeartlessAirSoldierLine6Spanish, gJiminyHeartlessAirSoldierLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessBanditLines[7] = {
    gJiminyHeartlessBanditLine0, gJiminyHeartlessBanditLine1, gJiminyHeartlessBanditLine2, gJiminyHeartlessBanditLine3,
    gJiminyHeartlessBanditLine4, gJiminyHeartlessBanditLine5, gJiminyHeartlessBanditLine6,
};

const JiminyTextChar* gJiminyHeartlessBanditLinesFrench[10] = {
    gJiminyHeartlessBanditLine0French, gJiminyHeartlessBanditLine1French, gJiminyHeartlessBanditLine2French, gJiminyHeartlessBanditLine3French,
    gJiminyHeartlessBanditLine4French, gJiminyHeartlessBanditLine5French, gJiminyHeartlessBanditLine6French, gJiminyHeartlessBanditLine7French,
    gJiminyHeartlessBanditLine8French, gJiminyHeartlessBanditLine9French,
};

const JiminyTextChar* gJiminyHeartlessBanditLinesGerman[10] = {
    gJiminyHeartlessBanditLine0German, gJiminyHeartlessBanditLine1German, gJiminyHeartlessBanditLine2German, gJiminyHeartlessBanditLine3German,
    gJiminyHeartlessBanditLine4German, gJiminyHeartlessBanditLine5German, gJiminyHeartlessBanditLine6German, gJiminyHeartlessBanditLine7German,
    gJiminyHeartlessBanditLine8German, gJiminyHeartlessBanditLine9German,
};

const JiminyTextChar* gJiminyHeartlessBanditLinesItalian[7] = {
    gJiminyHeartlessBanditLine0Italian, gJiminyHeartlessBanditLine1Italian, gJiminyHeartlessBanditLine2Italian, gJiminyHeartlessBanditLine3Italian,
    gJiminyHeartlessBanditLine4Italian, gJiminyHeartlessBanditLine5Italian, gJiminyHeartlessBanditLine6Italian,
};

const JiminyTextChar* gJiminyHeartlessBanditLinesSpanish[9] = {
    gJiminyHeartlessBanditLine0Spanish, gJiminyHeartlessBanditLine1Spanish, gJiminyHeartlessBanditLine2Spanish, gJiminyHeartlessBanditLine3Spanish,
    gJiminyHeartlessBanditLine4Spanish, gJiminyHeartlessBanditLine5Spanish, gJiminyHeartlessBanditLine6Spanish, gJiminyHeartlessBanditLine7Spanish,
    gJiminyHeartlessBanditLine8Spanish,
};

const JiminyTextChar* gJiminyHeartlessFatBanditLines[7] = {
    gJiminyHeartlessFatBanditLine0, gJiminyHeartlessFatBanditLine1, gJiminyHeartlessFatBanditLine2, gJiminyHeartlessFatBanditLine3,
    gJiminyHeartlessFatBanditLine4, gJiminyHeartlessFatBanditLine5, gJiminyHeartlessFatBanditLine6,
};

const JiminyTextChar* gJiminyHeartlessFatBanditLinesFrench[9] = {
    gJiminyHeartlessFatBanditLine0French, gJiminyHeartlessFatBanditLine1French, gJiminyHeartlessFatBanditLine2French, gJiminyHeartlessFatBanditLine3French,
    gJiminyHeartlessFatBanditLine4French, gJiminyHeartlessFatBanditLine5French, gJiminyHeartlessFatBanditLine6French, gJiminyHeartlessFatBanditLine7French,
    gJiminyHeartlessFatBanditLine8French,
};

const JiminyTextChar* gJiminyHeartlessFatBanditLinesGerman[8] = {
    gJiminyHeartlessFatBanditLine0German, gJiminyHeartlessFatBanditLine1German, gJiminyHeartlessFatBanditLine2German, gJiminyHeartlessFatBanditLine3German,
    gJiminyHeartlessFatBanditLine4German, gJiminyHeartlessFatBanditLine5German, gJiminyHeartlessFatBanditLine6German, gJiminyHeartlessFatBanditLine7German,
};

const JiminyTextChar* gJiminyHeartlessFatBanditLinesItalian[8] = {
    gJiminyHeartlessFatBanditLine0Italian, gJiminyHeartlessFatBanditLine1Italian, gJiminyHeartlessFatBanditLine2Italian, gJiminyHeartlessFatBanditLine3Italian,
    gJiminyHeartlessFatBanditLine4Italian, gJiminyHeartlessFatBanditLine5Italian, gJiminyHeartlessFatBanditLine6Italian, gJiminyHeartlessFatBanditLine7Italian,
};

const JiminyTextChar* gJiminyHeartlessFatBanditLinesSpanish[8] = {
    gJiminyHeartlessFatBanditLine0Spanish, gJiminyHeartlessFatBanditLine1Spanish, gJiminyHeartlessFatBanditLine2Spanish, gJiminyHeartlessFatBanditLine3Spanish,
    gJiminyHeartlessFatBanditLine4Spanish, gJiminyHeartlessFatBanditLine5Spanish, gJiminyHeartlessFatBanditLine6Spanish, gJiminyHeartlessFatBanditLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessBarrelSpiderLines[9] = {
    gJiminyHeartlessBarrelSpiderLine0, gJiminyHeartlessBarrelSpiderLine1, gJiminyHeartlessBarrelSpiderLine2, gJiminyHeartlessBarrelSpiderLine3,
    gJiminyHeartlessBarrelSpiderLine4, gJiminyHeartlessBarrelSpiderLine5, gJiminyHeartlessBarrelSpiderLine6, gJiminyHeartlessBarrelSpiderLine7,
    gJiminyHeartlessBarrelSpiderLine8,
};

const JiminyTextChar* gJiminyHeartlessBarrelSpiderLinesFrench[8] = {
    gJiminyHeartlessBarrelSpiderLine0French, gJiminyHeartlessBarrelSpiderLine1French, gJiminyHeartlessBarrelSpiderLine2French, gJiminyHeartlessBarrelSpiderLine3French,
    gJiminyHeartlessBarrelSpiderLine4French, gJiminyHeartlessBarrelSpiderLine5French, gJiminyHeartlessBarrelSpiderLine6French, gJiminyHeartlessBarrelSpiderLine7French,
};

const JiminyTextChar* gJiminyHeartlessBarrelSpiderLinesGerman[12] = {
    gJiminyHeartlessBarrelSpiderLine0German, gJiminyHeartlessBarrelSpiderLine1German, gJiminyHeartlessBarrelSpiderLine2German, gJiminyHeartlessBarrelSpiderLine3German,
    gJiminyHeartlessBarrelSpiderLine4German, gJiminyHeartlessBarrelSpiderLine5German, gJiminyHeartlessBarrelSpiderLine6German, gJiminyHeartlessBarrelSpiderLine7German,
    gJiminyHeartlessBarrelSpiderLine8German, gJiminyHeartlessBarrelSpiderLine9German, gJiminyHeartlessBarrelSpiderLine10German, gJiminyHeartlessBarrelSpiderLine11German,
};

const JiminyTextChar* gJiminyHeartlessBarrelSpiderLinesItalian[9] = {
    gJiminyHeartlessBarrelSpiderLine0Italian, gJiminyHeartlessBarrelSpiderLine1Italian, gJiminyHeartlessBarrelSpiderLine2Italian, gJiminyHeartlessBarrelSpiderLine3Italian,
    gJiminyHeartlessBarrelSpiderLine4Italian, gJiminyHeartlessBarrelSpiderLine5Italian, gJiminyHeartlessBarrelSpiderLine6Italian, gJiminyHeartlessBarrelSpiderLine7Italian,
    gJiminyHeartlessBarrelSpiderLine8Italian,
};

const JiminyTextChar* gJiminyHeartlessBarrelSpiderLinesSpanish[9] = {
    gJiminyHeartlessBarrelSpiderLine0Spanish, gJiminyHeartlessBarrelSpiderLine1Spanish, gJiminyHeartlessBarrelSpiderLine2Spanish, gJiminyHeartlessBarrelSpiderLine3Spanish,
    gJiminyHeartlessBarrelSpiderLine4Spanish, gJiminyHeartlessBarrelSpiderLine5Spanish, gJiminyHeartlessBarrelSpiderLine6Spanish, gJiminyHeartlessBarrelSpiderLine7Spanish,
    gJiminyHeartlessBarrelSpiderLine8Spanish,
};

const JiminyTextChar* gJiminyHeartlessSearchGhostLines[7] = {
    gJiminyHeartlessSearchGhostLine0, gJiminyHeartlessSearchGhostLine1, gJiminyHeartlessSearchGhostLine2, gJiminyHeartlessSearchGhostLine3,
    gJiminyHeartlessSearchGhostLine4, gJiminyHeartlessSearchGhostLine5, gJiminyHeartlessSearchGhostLine6,
};

const JiminyTextChar* gJiminyHeartlessSearchGhostLinesFrench[8] = {
    gJiminyHeartlessSearchGhostLine0French, gJiminyHeartlessSearchGhostLine1French, gJiminyHeartlessSearchGhostLine2French, gJiminyHeartlessSearchGhostLine3French,
    gJiminyHeartlessSearchGhostLine4French, gJiminyHeartlessSearchGhostLine5French, gJiminyHeartlessSearchGhostLine6French, gJiminyHeartlessSearchGhostLine7French,
};

const JiminyTextChar* gJiminyHeartlessSearchGhostLinesGerman[10] = {
    gJiminyHeartlessSearchGhostLine0German, gJiminyHeartlessSearchGhostLine1German, gJiminyHeartlessSearchGhostLine2German, gJiminyHeartlessSearchGhostLine3German,
    gJiminyHeartlessSearchGhostLine4German, gJiminyHeartlessSearchGhostLine5German, gJiminyHeartlessSearchGhostLine6German, gJiminyHeartlessSearchGhostLine7German,
    gJiminyHeartlessSearchGhostLine8German, gJiminyHeartlessSearchGhostLine9German,
};

const JiminyTextChar* gJiminyHeartlessSearchGhostLinesItalian[8] = {
    gJiminyHeartlessSearchGhostLine0Italian, gJiminyHeartlessSearchGhostLine1Italian, gJiminyHeartlessSearchGhostLine2Italian, gJiminyHeartlessSearchGhostLine3Italian,
    gJiminyHeartlessSearchGhostLine4Italian, gJiminyHeartlessSearchGhostLine5Italian, gJiminyHeartlessSearchGhostLine6Italian, gJiminyHeartlessSearchGhostLine7Italian,
};

const JiminyTextChar* gJiminyHeartlessSearchGhostLinesSpanish[8] = {
    gJiminyHeartlessSearchGhostLine0Spanish, gJiminyHeartlessSearchGhostLine1Spanish, gJiminyHeartlessSearchGhostLine2Spanish, gJiminyHeartlessSearchGhostLine3Spanish,
    gJiminyHeartlessSearchGhostLine4Spanish, gJiminyHeartlessSearchGhostLine5Spanish, gJiminyHeartlessSearchGhostLine6Spanish, gJiminyHeartlessSearchGhostLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessSeaNeonLines[8] = {
    gJiminyHeartlessSeaNeonLine0, gJiminyHeartlessSeaNeonLine1, gJiminyHeartlessSeaNeonLine2, gJiminyHeartlessSeaNeonLine3,
    gJiminyHeartlessSeaNeonLine4, gJiminyHeartlessSeaNeonLine5, gJiminyHeartlessSeaNeonLine6, gJiminyHeartlessSeaNeonLine7,
};

const JiminyTextChar* gJiminyHeartlessSeaNeonLinesFrench[9] = {
    gJiminyHeartlessSeaNeonLine0French, gJiminyHeartlessSeaNeonLine1French, gJiminyHeartlessSeaNeonLine2French, gJiminyHeartlessSeaNeonLine3French,
    gJiminyHeartlessSeaNeonLine4French, gJiminyHeartlessSeaNeonLine5French, gJiminyHeartlessSeaNeonLine6French, gJiminyHeartlessSeaNeonLine7French,
    gJiminyHeartlessSeaNeonLine8French,
};

const JiminyTextChar* gJiminyHeartlessSeaNeonLinesGerman[11] = {
    gJiminyHeartlessSeaNeonLine0German, gJiminyHeartlessSeaNeonLine1German, gJiminyHeartlessSeaNeonLine2German, gJiminyHeartlessSeaNeonLine3German,
    gJiminyHeartlessSeaNeonLine4German, gJiminyHeartlessSeaNeonLine5German, gJiminyHeartlessSeaNeonLine6German, gJiminyHeartlessSeaNeonLine7German,
    gJiminyHeartlessSeaNeonLine8German, gJiminyHeartlessSeaNeonLine9German, gJiminyHeartlessSeaNeonLine10German,
};

const JiminyTextChar* gJiminyHeartlessSeaNeonLinesItalian[8] = {
    gJiminyHeartlessSeaNeonLine0Italian, gJiminyHeartlessSeaNeonLine1Italian, gJiminyHeartlessSeaNeonLine2Italian, gJiminyHeartlessSeaNeonLine3Italian,
    gJiminyHeartlessSeaNeonLine4Italian, gJiminyHeartlessSeaNeonLine5Italian, gJiminyHeartlessSeaNeonLine6Italian, gJiminyHeartlessSeaNeonLine7Italian,
};

const JiminyTextChar* gJiminyHeartlessSeaNeonLinesSpanish[8] = {
    gJiminyHeartlessSeaNeonLine0Spanish, gJiminyHeartlessSeaNeonLine1Spanish, gJiminyHeartlessSeaNeonLine2Spanish, gJiminyHeartlessSeaNeonLine3Spanish,
    gJiminyHeartlessSeaNeonLine4Spanish, gJiminyHeartlessSeaNeonLine5Spanish, gJiminyHeartlessSeaNeonLine6Spanish, gJiminyHeartlessSeaNeonLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessScrewdiverLines[6] = {
    gJiminyHeartlessScrewdiverLine0, gJiminyHeartlessScrewdiverLine1, gJiminyHeartlessScrewdiverLine2, gJiminyHeartlessScrewdiverLine3,
    gJiminyHeartlessScrewdiverLine4, gJiminyHeartlessScrewdiverLine5,
};

const JiminyTextChar* gJiminyHeartlessScrewdiverLinesFrench[7] = {
    gJiminyHeartlessScrewdiverLine0French, gJiminyHeartlessScrewdiverLine1French, gJiminyHeartlessScrewdiverLine2French, gJiminyHeartlessScrewdiverLine3French,
    gJiminyHeartlessScrewdiverLine4French, gJiminyHeartlessScrewdiverLine5French, gJiminyHeartlessScrewdiverLine6French,
};

const JiminyTextChar* gJiminyHeartlessScrewdiverLinesGerman[8] = {
    gJiminyHeartlessScrewdiverLine0German, gJiminyHeartlessScrewdiverLine1German, gJiminyHeartlessScrewdiverLine2German, gJiminyHeartlessScrewdiverLine3German,
    gJiminyHeartlessScrewdiverLine4German, gJiminyHeartlessScrewdiverLine5German, gJiminyHeartlessScrewdiverLine6German, gJiminyHeartlessScrewdiverLine7German,
};

const JiminyTextChar* gJiminyHeartlessScrewdiverLinesItalian[7] = {
    gJiminyHeartlessScrewdiverLine0Italian, gJiminyHeartlessScrewdiverLine1Italian, gJiminyHeartlessScrewdiverLine2Italian, gJiminyHeartlessScrewdiverLine3Italian,
    gJiminyHeartlessScrewdiverLine4Italian, gJiminyHeartlessScrewdiverLine5Italian, gJiminyHeartlessScrewdiverLine6Italian,
};

const JiminyTextChar* gJiminyHeartlessScrewdiverLinesSpanish[7] = {
    gJiminyHeartlessScrewdiverLine0Spanish, gJiminyHeartlessScrewdiverLine1Spanish, gJiminyHeartlessScrewdiverLine2Spanish, gJiminyHeartlessScrewdiverLine3Spanish,
    gJiminyHeartlessScrewdiverLine4Spanish, gJiminyHeartlessScrewdiverLine5Spanish, gJiminyHeartlessScrewdiverLine6Spanish,
};

const JiminyTextChar* gJiminyHeartlessAquatankLines[8] = {
    gJiminyHeartlessAquatankLine0, gJiminyHeartlessAquatankLine1, gJiminyHeartlessAquatankLine2, gJiminyHeartlessAquatankLine3,
    gJiminyHeartlessAquatankLine4, gJiminyHeartlessAquatankLine5, gJiminyHeartlessAquatankLine6, gJiminyHeartlessAquatankLine7,
};

const JiminyTextChar* gJiminyHeartlessAquatankLinesFrench[8] = {
    gJiminyHeartlessAquatankLine0French, gJiminyHeartlessAquatankLine1French, gJiminyHeartlessAquatankLine2French, gJiminyHeartlessAquatankLine3French,
    gJiminyHeartlessAquatankLine4French, gJiminyHeartlessAquatankLine5French, gJiminyHeartlessAquatankLine6French, gJiminyHeartlessAquatankLine7French,
};

const JiminyTextChar* gJiminyHeartlessAquatankLinesGerman[9] = {
    gJiminyHeartlessAquatankLine0German, gJiminyHeartlessAquatankLine1German, gJiminyHeartlessAquatankLine2German, gJiminyHeartlessAquatankLine3German,
    gJiminyHeartlessAquatankLine4German, gJiminyHeartlessAquatankLine5German, gJiminyHeartlessAquatankLine6German, gJiminyHeartlessAquatankLine7German,
    gJiminyHeartlessAquatankLine8German,
};

const JiminyTextChar* gJiminyHeartlessAquatankLinesItalian[7] = {
    gJiminyHeartlessAquatankLine0Italian, gJiminyHeartlessAquatankLine1Italian, gJiminyHeartlessAquatankLine2Italian, gJiminyHeartlessAquatankLine3Italian,
    gJiminyHeartlessAquatankLine4Italian, gJiminyHeartlessAquatankLine5Italian, gJiminyHeartlessAquatankLine6Italian,
};

const JiminyTextChar* gJiminyHeartlessAquatankLinesSpanish[7] = {
    gJiminyHeartlessAquatankLine0Spanish, gJiminyHeartlessAquatankLine1Spanish, gJiminyHeartlessAquatankLine2Spanish, gJiminyHeartlessAquatankLine3Spanish,
    gJiminyHeartlessAquatankLine4Spanish, gJiminyHeartlessAquatankLine5Spanish, gJiminyHeartlessAquatankLine6Spanish,
};

const JiminyTextChar* gJiminyHeartlessWightKnightLines[7] = {
    gJiminyHeartlessWightKnightLine0, gJiminyHeartlessWightKnightLine1, gJiminyHeartlessWightKnightLine2, gJiminyHeartlessWightKnightLine3,
    gJiminyHeartlessWightKnightLine4, gJiminyHeartlessWightKnightLine5, gJiminyHeartlessWightKnightLine6,
};

const JiminyTextChar* gJiminyHeartlessWightKnightLinesFrench[6] = {
    gJiminyHeartlessWightKnightLine0French, gJiminyHeartlessWightKnightLine1French, gJiminyHeartlessWightKnightLine2French, gJiminyHeartlessWightKnightLine3French,
    gJiminyHeartlessWightKnightLine4French, gJiminyHeartlessWightKnightLine5French,
};

const JiminyTextChar* gJiminyHeartlessWightKnightLinesGerman[11] = {
    gJiminyHeartlessWightKnightLine0German, gJiminyHeartlessWightKnightLine1German, gJiminyHeartlessWightKnightLine2German, gJiminyHeartlessWightKnightLine3German,
    gJiminyHeartlessWightKnightLine4German, gJiminyHeartlessWightKnightLine5German, gJiminyHeartlessWightKnightLine6German, gJiminyHeartlessWightKnightLine7German,
    gJiminyHeartlessWightKnightLine8German, gJiminyHeartlessWightKnightLine9German, gJiminyHeartlessWightKnightLine10German,
};

const JiminyTextChar* gJiminyHeartlessWightKnightLinesItalian[10] = {
    gJiminyHeartlessWightKnightLine0Italian, gJiminyHeartlessWightKnightLine1Italian, gJiminyHeartlessWightKnightLine2Italian, gJiminyHeartlessWightKnightLine3Italian,
    gJiminyHeartlessWightKnightLine4Italian, gJiminyHeartlessWightKnightLine5Italian, gJiminyHeartlessWightKnightLine6Italian, gJiminyHeartlessWightKnightLine7Italian,
    gJiminyHeartlessWightKnightLine8Italian, gJiminyHeartlessWightKnightLine9Italian,
};

const JiminyTextChar* gJiminyHeartlessWightKnightLinesSpanish[8] = {
    gJiminyHeartlessWightKnightLine0Spanish, gJiminyHeartlessWightKnightLine1Spanish, gJiminyHeartlessWightKnightLine2Spanish, gJiminyHeartlessWightKnightLine3Spanish,
    gJiminyHeartlessWightKnightLine4Spanish, gJiminyHeartlessWightKnightLine5Spanish, gJiminyHeartlessWightKnightLine6Spanish, gJiminyHeartlessWightKnightLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessGargoyleLines[7] = {
    gJiminyHeartlessGargoyleLine0, gJiminyHeartlessGargoyleLine1, gJiminyHeartlessGargoyleLine2, gJiminyHeartlessGargoyleLine3,
    gJiminyHeartlessGargoyleLine4, gJiminyHeartlessGargoyleLine5, gJiminyHeartlessGargoyleLine6,
};

const JiminyTextChar* gJiminyHeartlessGargoyleLinesFrench[8] = {
    gJiminyHeartlessGargoyleLine0French, gJiminyHeartlessGargoyleLine1French, gJiminyHeartlessGargoyleLine2French, gJiminyHeartlessGargoyleLine3French,
    gJiminyHeartlessGargoyleLine4French, gJiminyHeartlessGargoyleLine5French, gJiminyHeartlessGargoyleLine6French, gJiminyHeartlessGargoyleLine7French,
};

const JiminyTextChar* gJiminyHeartlessGargoyleLinesGerman[8] = {
    gJiminyHeartlessGargoyleLine0German, gJiminyHeartlessGargoyleLine1German, gJiminyHeartlessGargoyleLine2German, gJiminyHeartlessGargoyleLine3German,
    gJiminyHeartlessGargoyleLine4German, gJiminyHeartlessGargoyleLine5German, gJiminyHeartlessGargoyleLine6German, gJiminyHeartlessGargoyleLine7German,
};

const JiminyTextChar* gJiminyHeartlessGargoyleLinesItalian[7] = {
    gJiminyHeartlessGargoyleLine0Italian, gJiminyHeartlessGargoyleLine1Italian, gJiminyHeartlessGargoyleLine2Italian, gJiminyHeartlessGargoyleLine3Italian,
    gJiminyHeartlessGargoyleLine4Italian, gJiminyHeartlessGargoyleLine5Italian, gJiminyHeartlessGargoyleLine6Italian,
};

const JiminyTextChar* gJiminyHeartlessGargoyleLinesSpanish[8] = {
    gJiminyHeartlessGargoyleLine0Spanish, gJiminyHeartlessGargoyleLine1Spanish, gJiminyHeartlessGargoyleLine2Spanish, gJiminyHeartlessGargoyleLine3Spanish,
    gJiminyHeartlessGargoyleLine4Spanish, gJiminyHeartlessGargoyleLine5Spanish, gJiminyHeartlessGargoyleLine6Spanish, gJiminyHeartlessGargoyleLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessPirateLines[10] = {
    gJiminyHeartlessPirateLine0, gJiminyHeartlessPirateLine1, gJiminyHeartlessPirateLine2, gJiminyHeartlessPirateLine3,
    gJiminyHeartlessPirateLine4, gJiminyHeartlessPirateLine5, gJiminyHeartlessPirateLine6, gJiminyHeartlessPirateLine7,
    gJiminyHeartlessPirateLine8, gJiminyHeartlessPirateLine9,
};

const JiminyTextChar* gJiminyHeartlessPirateLinesFrench[12] = {
    gJiminyHeartlessPirateLine0French, gJiminyHeartlessPirateLine1French, gJiminyHeartlessPirateLine2French, gJiminyHeartlessPirateLine3French,
    gJiminyHeartlessPirateLine4French, gJiminyHeartlessPirateLine5French, gJiminyHeartlessPirateLine6French, gJiminyHeartlessPirateLine7French,
    gJiminyHeartlessPirateLine8French, gJiminyHeartlessPirateLine9French, gJiminyHeartlessPirateLine10French, gJiminyHeartlessPirateLine11French,
};

const JiminyTextChar* gJiminyHeartlessPirateLinesGerman[14] = {
    gJiminyHeartlessPirateLine0German, gJiminyHeartlessPirateLine1German, gJiminyHeartlessPirateLine2German, gJiminyHeartlessPirateLine3German,
    gJiminyHeartlessPirateLine4German, gJiminyHeartlessPirateLine5German, gJiminyHeartlessPirateLine6German, gJiminyHeartlessPirateLine7German,
    gJiminyHeartlessPirateLine8German, gJiminyHeartlessPirateLine9German, gJiminyHeartlessPirateLine10German, gJiminyHeartlessPirateLine11German,
    gJiminyHeartlessPirateLine12German, gJiminyHeartlessPirateLine13German,
};

const JiminyTextChar* gJiminyHeartlessPirateLinesItalian[12] = {
    gJiminyHeartlessPirateLine0Italian, gJiminyHeartlessPirateLine1Italian, gJiminyHeartlessPirateLine2Italian, gJiminyHeartlessPirateLine3Italian,
    gJiminyHeartlessPirateLine4Italian, gJiminyHeartlessPirateLine5Italian, gJiminyHeartlessPirateLine6Italian, gJiminyHeartlessPirateLine7Italian,
    gJiminyHeartlessPirateLine8Italian, gJiminyHeartlessPirateLine9Italian, gJiminyHeartlessPirateLine10Italian, gJiminyHeartlessPirateLine11Italian,
};

const JiminyTextChar* gJiminyHeartlessPirateLinesSpanish[11] = {
    gJiminyHeartlessPirateLine0Spanish, gJiminyHeartlessPirateLine1Spanish, gJiminyHeartlessPirateLine2Spanish, gJiminyHeartlessPirateLine3Spanish,
    gJiminyHeartlessPirateLine4Spanish, gJiminyHeartlessPirateLine5Spanish, gJiminyHeartlessPirateLine6Spanish, gJiminyHeartlessPirateLine7Spanish,
    gJiminyHeartlessPirateLine8Spanish, gJiminyHeartlessPirateLine9Spanish, gJiminyHeartlessPirateLine10Spanish,
};

const JiminyTextChar* gJiminyHeartlessAirPirateLines[9] = {
    gJiminyHeartlessAirPirateLine0, gJiminyHeartlessAirPirateLine1, gJiminyHeartlessAirPirateLine2, gJiminyHeartlessAirPirateLine3,
    gJiminyHeartlessAirPirateLine4, gJiminyHeartlessAirPirateLine5, gJiminyHeartlessAirPirateLine6, gJiminyHeartlessAirPirateLine7,
    gJiminyHeartlessAirPirateLine8,
};

const JiminyTextChar* gJiminyHeartlessAirPirateLinesFrench[10] = {
    gJiminyHeartlessAirPirateLine0French, gJiminyHeartlessAirPirateLine1French, gJiminyHeartlessAirPirateLine2French, gJiminyHeartlessAirPirateLine3French,
    gJiminyHeartlessAirPirateLine4French, gJiminyHeartlessAirPirateLine5French, gJiminyHeartlessAirPirateLine6French, gJiminyHeartlessAirPirateLine7French,
    gJiminyHeartlessAirPirateLine8French, gJiminyHeartlessAirPirateLine9French,
};

const JiminyTextChar* gJiminyHeartlessAirPirateLinesGerman[11] = {
    gJiminyHeartlessAirPirateLine0German, gJiminyHeartlessAirPirateLine1German, gJiminyHeartlessAirPirateLine2German, gJiminyHeartlessAirPirateLine3German,
    gJiminyHeartlessAirPirateLine4German, gJiminyHeartlessAirPirateLine5German, gJiminyHeartlessAirPirateLine6German, gJiminyHeartlessAirPirateLine7German,
    gJiminyHeartlessAirPirateLine8German, gJiminyHeartlessAirPirateLine9German, gJiminyHeartlessAirPirateLine10German,
};

const JiminyTextChar* gJiminyHeartlessAirPirateLinesItalian[10] = {
    gJiminyHeartlessAirPirateLine0Italian, gJiminyHeartlessAirPirateLine1Italian, gJiminyHeartlessAirPirateLine2Italian, gJiminyHeartlessAirPirateLine3Italian,
    gJiminyHeartlessAirPirateLine4Italian, gJiminyHeartlessAirPirateLine5Italian, gJiminyHeartlessAirPirateLine6Italian, gJiminyHeartlessAirPirateLine7Italian,
    gJiminyHeartlessAirPirateLine8Italian, gJiminyHeartlessAirPirateLine9Italian,
};

const JiminyTextChar* gJiminyHeartlessAirPirateLinesSpanish[9] = {
    gJiminyHeartlessAirPirateLine0Spanish, gJiminyHeartlessAirPirateLine1Spanish, gJiminyHeartlessAirPirateLine2Spanish, gJiminyHeartlessAirPirateLine3Spanish,
    gJiminyHeartlessAirPirateLine4Spanish, gJiminyHeartlessAirPirateLine5Spanish, gJiminyHeartlessAirPirateLine6Spanish, gJiminyHeartlessAirPirateLine7Spanish,
    gJiminyHeartlessAirPirateLine8Spanish,
};

const JiminyTextChar* gJiminyHeartlessDarkballLines[9] = {
    gJiminyHeartlessDarkballLine0, gJiminyHeartlessDarkballLine1, gJiminyHeartlessDarkballLine2, gJiminyHeartlessDarkballLine3,
    gJiminyHeartlessDarkballLine4, gJiminyHeartlessDarkballLine5, gJiminyHeartlessDarkballLine6, gJiminyHeartlessDarkballLine7,
    gJiminyHeartlessDarkballLine8,
};

const JiminyTextChar* gJiminyHeartlessDarkballLinesFrench[8] = {
    gJiminyHeartlessDarkballLine0French, gJiminyHeartlessDarkballLine1French, gJiminyHeartlessDarkballLine2French, gJiminyHeartlessDarkballLine3French,
    gJiminyHeartlessDarkballLine4French, gJiminyHeartlessDarkballLine5French, gJiminyHeartlessDarkballLine6French, gJiminyHeartlessDarkballLine7French,
};

const JiminyTextChar* gJiminyHeartlessDarkballLinesGerman[12] = {
    gJiminyHeartlessDarkballLine0German, gJiminyHeartlessDarkballLine1German, gJiminyHeartlessDarkballLine2German, gJiminyHeartlessDarkballLine3German,
    gJiminyHeartlessDarkballLine4German, gJiminyHeartlessDarkballLine5German, gJiminyHeartlessDarkballLine6German, gJiminyHeartlessDarkballLine7German,
    gJiminyHeartlessDarkballLine8German, gJiminyHeartlessDarkballLine9German, gJiminyHeartlessDarkballLine10German, gJiminyHeartlessDarkballLine11German,
};

const JiminyTextChar* gJiminyHeartlessDarkballLinesItalian[9] = {
    gJiminyHeartlessDarkballLine0Italian, gJiminyHeartlessDarkballLine1Italian, gJiminyHeartlessDarkballLine2Italian, gJiminyHeartlessDarkballLine3Italian,
    gJiminyHeartlessDarkballLine4Italian, gJiminyHeartlessDarkballLine5Italian, gJiminyHeartlessDarkballLine6Italian, gJiminyHeartlessDarkballLine7Italian,
    gJiminyHeartlessDarkballLine8Italian,
};

const JiminyTextChar* gJiminyHeartlessDarkballLinesSpanish[9] = {
    gJiminyHeartlessDarkballLine0Spanish, gJiminyHeartlessDarkballLine1Spanish, gJiminyHeartlessDarkballLine2Spanish, gJiminyHeartlessDarkballLine3Spanish,
    gJiminyHeartlessDarkballLine4Spanish, gJiminyHeartlessDarkballLine5Spanish, gJiminyHeartlessDarkballLine6Spanish, gJiminyHeartlessDarkballLine7Spanish,
    gJiminyHeartlessDarkballLine8Spanish,
};

const JiminyTextChar* gJiminyHeartlessDefenderLines[13] = {
    gJiminyHeartlessDefenderLine0, gJiminyHeartlessDefenderLine1, gJiminyHeartlessDefenderLine2, gJiminyHeartlessDefenderLine3,
    gJiminyHeartlessDefenderLine4, gJiminyHeartlessDefenderLine5, gJiminyHeartlessDefenderLine6, gJiminyHeartlessDefenderLine7,
    gJiminyHeartlessDefenderLine8, gJiminyHeartlessDefenderLine9, gJiminyHeartlessDefenderLine10, gJiminyHeartlessDefenderLine11,
    gJiminyHeartlessDefenderLine12,
};

const JiminyTextChar* gJiminyHeartlessDefenderLinesFrench[14] = {
    gJiminyHeartlessDefenderLine0French, gJiminyHeartlessDefenderLine1French, gJiminyHeartlessDefenderLine2French, gJiminyHeartlessDefenderLine3French,
    gJiminyHeartlessDefenderLine4French, gJiminyHeartlessDefenderLine5French, gJiminyHeartlessDefenderLine6French, gJiminyHeartlessDefenderLine7French,
    gJiminyHeartlessDefenderLine8French, gJiminyHeartlessDefenderLine9French, gJiminyHeartlessDefenderLine10French, gJiminyHeartlessDefenderLine11French,
    gJiminyHeartlessDefenderLine12French, gJiminyHeartlessDefenderLine13French,
};

const JiminyTextChar* gJiminyHeartlessDefenderLinesGerman[17] = {
    gJiminyHeartlessDefenderLine0German, gJiminyHeartlessDefenderLine1German, gJiminyHeartlessDefenderLine2German, gJiminyHeartlessDefenderLine3German,
    gJiminyHeartlessDefenderLine4German, gJiminyHeartlessDefenderLine5German, gJiminyHeartlessDefenderLine6German, gJiminyHeartlessDefenderLine7German,
    gJiminyHeartlessDefenderLine8German, gJiminyHeartlessDefenderLine9German, gJiminyHeartlessDefenderLine10German, gJiminyHeartlessDefenderLine11German,
    gJiminyHeartlessDefenderLine12German, gJiminyHeartlessDefenderLine13German, gJiminyHeartlessDefenderLine14German, gJiminyHeartlessDefenderLine15German,
    gJiminyHeartlessDefenderLine16German,
};

const JiminyTextChar* gJiminyHeartlessDefenderLinesItalian[15] = {
    gJiminyHeartlessDefenderLine0Italian, gJiminyHeartlessDefenderLine1Italian, gJiminyHeartlessDefenderLine2Italian, gJiminyHeartlessDefenderLine3Italian,
    gJiminyHeartlessDefenderLine4Italian, gJiminyHeartlessDefenderLine5Italian, gJiminyHeartlessDefenderLine6Italian, gJiminyHeartlessDefenderLine7Italian,
    gJiminyHeartlessDefenderLine8Italian, gJiminyHeartlessDefenderLine9Italian, gJiminyHeartlessDefenderLine10Italian, gJiminyHeartlessDefenderLine11Italian,
    gJiminyHeartlessDefenderLine12Italian, gJiminyHeartlessDefenderLine13Italian, gJiminyHeartlessDefenderLine14Italian,
};

const JiminyTextChar* gJiminyHeartlessDefenderLinesSpanish[13] = {
    gJiminyHeartlessDefenderLine0Spanish, gJiminyHeartlessDefenderLine1Spanish, gJiminyHeartlessDefenderLine2Spanish, gJiminyHeartlessDefenderLine3Spanish,
    gJiminyHeartlessDefenderLine4Spanish, gJiminyHeartlessDefenderLine5Spanish, gJiminyHeartlessDefenderLine6Spanish, gJiminyHeartlessDefenderLine7Spanish,
    gJiminyHeartlessDefenderLine8Spanish, gJiminyHeartlessDefenderLine9Spanish, gJiminyHeartlessDefenderLine10Spanish, gJiminyHeartlessDefenderLine11Spanish,
    gJiminyHeartlessDefenderLine12Spanish,
};

const JiminyTextChar* gJiminyHeartlessWyvernLines[10] = {
    gJiminyHeartlessWyvernLine0, gJiminyHeartlessWyvernLine1, gJiminyHeartlessWyvernLine2, gJiminyHeartlessWyvernLine3,
    gJiminyHeartlessWyvernLine4, gJiminyHeartlessWyvernLine5, gJiminyHeartlessWyvernLine6, gJiminyHeartlessWyvernLine7,
    gJiminyHeartlessWyvernLine8, gJiminyHeartlessWyvernLine9,
};

const JiminyTextChar* gJiminyHeartlessWyvernLinesFrench[8] = {
    gJiminyHeartlessWyvernLine0French, gJiminyHeartlessWyvernLine1French, gJiminyHeartlessWyvernLine2French, gJiminyHeartlessWyvernLine3French,
    gJiminyHeartlessWyvernLine4French, gJiminyHeartlessWyvernLine5French, gJiminyHeartlessWyvernLine6French, gJiminyHeartlessWyvernLine7French,
};

const JiminyTextChar* gJiminyHeartlessWyvernLinesGerman[10] = {
    gJiminyHeartlessWyvernLine0German, gJiminyHeartlessWyvernLine1German, gJiminyHeartlessWyvernLine2German, gJiminyHeartlessWyvernLine3German,
    gJiminyHeartlessWyvernLine4German, gJiminyHeartlessWyvernLine5German, gJiminyHeartlessWyvernLine6German, gJiminyHeartlessWyvernLine7German,
    gJiminyHeartlessWyvernLine8German, gJiminyHeartlessWyvernLine9German,
};

const JiminyTextChar* gJiminyHeartlessWyvernLinesItalian[9] = {
    gJiminyHeartlessWyvernLine0Italian, gJiminyHeartlessWyvernLine1Italian, gJiminyHeartlessWyvernLine2Italian, gJiminyHeartlessWyvernLine3Italian,
    gJiminyHeartlessWyvernLine4Italian, gJiminyHeartlessWyvernLine5Italian, gJiminyHeartlessWyvernLine6Italian, gJiminyHeartlessWyvernLine7Italian,
    gJiminyHeartlessWyvernLine8Italian,
};

const JiminyTextChar* gJiminyHeartlessWyvernLinesSpanish[11] = {
    gJiminyHeartlessWyvernLine0Spanish, gJiminyHeartlessWyvernLine1Spanish, gJiminyHeartlessWyvernLine2Spanish, gJiminyHeartlessWyvernLine3Spanish,
    gJiminyHeartlessWyvernLine4Spanish, gJiminyHeartlessWyvernLine5Spanish, gJiminyHeartlessWyvernLine6Spanish, gJiminyHeartlessWyvernLine7Spanish,
    gJiminyHeartlessWyvernLine8Spanish, gJiminyHeartlessWyvernLine9Spanish, gJiminyHeartlessWyvernLine10Spanish,
};

const JiminyTextChar* gJiminyHeartlessWizardLines[8] = {
    gJiminyHeartlessWizardLine0, gJiminyHeartlessWizardLine1, gJiminyHeartlessWizardLine2, gJiminyHeartlessWizardLine3,
    gJiminyHeartlessWizardLine4, gJiminyHeartlessWizardLine5, gJiminyHeartlessWizardLine6, gJiminyHeartlessWizardLine7,
};

const JiminyTextChar* gJiminyHeartlessWizardLinesFrench[7] = {
    gJiminyHeartlessWizardLine0French, gJiminyHeartlessWizardLine1French, gJiminyHeartlessWizardLine2French, gJiminyHeartlessWizardLine3French,
    gJiminyHeartlessWizardLine4French, gJiminyHeartlessWizardLine5French, gJiminyHeartlessWizardLine6French,
};

const JiminyTextChar* gJiminyHeartlessWizardLinesGerman[7] = {
    gJiminyHeartlessWizardLine0German, gJiminyHeartlessWizardLine1German, gJiminyHeartlessWizardLine2German, gJiminyHeartlessWizardLine3German,
    gJiminyHeartlessWizardLine4German, gJiminyHeartlessWizardLine5German, gJiminyHeartlessWizardLine6German,
};

const JiminyTextChar* gJiminyHeartlessWizardLinesItalian[8] = {
    gJiminyHeartlessWizardLine0Italian, gJiminyHeartlessWizardLine1Italian, gJiminyHeartlessWizardLine2Italian, gJiminyHeartlessWizardLine3Italian,
    gJiminyHeartlessWizardLine4Italian, gJiminyHeartlessWizardLine5Italian, gJiminyHeartlessWizardLine6Italian, gJiminyHeartlessWizardLine7Italian,
};

const JiminyTextChar* gJiminyHeartlessWizardLinesSpanish[7] = {
    gJiminyHeartlessWizardLine0Spanish, gJiminyHeartlessWizardLine1Spanish, gJiminyHeartlessWizardLine2Spanish, gJiminyHeartlessWizardLine3Spanish,
    gJiminyHeartlessWizardLine4Spanish, gJiminyHeartlessWizardLine5Spanish, gJiminyHeartlessWizardLine6Spanish,
};

const JiminyTextChar* gJiminyHeartlessNeoshadowLines[3] = {
    gJiminyHeartlessNeoshadowLine0, gJiminyHeartlessNeoshadowLine1, gJiminyHeartlessNeoshadowLine2,
};

const JiminyTextChar* gJiminyHeartlessNeoshadowLinesFrench[5] = {
    gJiminyHeartlessNeoshadowLine0French, gJiminyHeartlessNeoshadowLine1French, gJiminyHeartlessNeoshadowLine2French, gJiminyHeartlessNeoshadowLine3French,
    gJiminyHeartlessNeoshadowLine4French,
};

const JiminyTextChar* gJiminyHeartlessNeoshadowLinesGerman[4] = {
    gJiminyHeartlessNeoshadowLine0German, gJiminyHeartlessNeoshadowLine1German, gJiminyHeartlessNeoshadowLine2German, gJiminyHeartlessNeoshadowLine3German,
};

const JiminyTextChar* gJiminyHeartlessNeoshadowLinesItalian[2] = {
    gJiminyHeartlessNeoshadowLine0Italian, gJiminyHeartlessNeoshadowLine1Italian,
};

const JiminyTextChar* gJiminyHeartlessNeoshadowLinesSpanish[3] = {
    gJiminyHeartlessNeoshadowLine0Spanish, gJiminyHeartlessNeoshadowLine1Spanish, gJiminyHeartlessNeoshadowLine2Spanish,
};

const JiminyTextChar* gJiminyHeartlessWhiteMushroomLines[8] = {
    gJiminyHeartlessWhiteMushroomLine0, gJiminyHeartlessWhiteMushroomLine1, gJiminyHeartlessWhiteMushroomLine2, gJiminyHeartlessWhiteMushroomLine3,
    gJiminyHeartlessWhiteMushroomLine4, gJiminyHeartlessWhiteMushroomLine5, gJiminyHeartlessWhiteMushroomLine6, gJiminyHeartlessWhiteMushroomLine7,
};

const JiminyTextChar* gJiminyHeartlessWhiteMushroomLinesFrench[9] = {
    gJiminyHeartlessWhiteMushroomLine0French, gJiminyHeartlessWhiteMushroomLine1French, gJiminyHeartlessWhiteMushroomLine2French, gJiminyHeartlessWhiteMushroomLine3French,
    gJiminyHeartlessWhiteMushroomLine4French, gJiminyHeartlessWhiteMushroomLine5French, gJiminyHeartlessWhiteMushroomLine6French, gJiminyHeartlessWhiteMushroomLine7French,
    gJiminyHeartlessWhiteMushroomLine8French,
};

const JiminyTextChar* gJiminyHeartlessWhiteMushroomLinesGerman[9] = {
    gJiminyHeartlessWhiteMushroomLine0German, gJiminyHeartlessWhiteMushroomLine1German, gJiminyHeartlessWhiteMushroomLine2German, gJiminyHeartlessWhiteMushroomLine3German,
    gJiminyHeartlessWhiteMushroomLine4German, gJiminyHeartlessWhiteMushroomLine5German, gJiminyHeartlessWhiteMushroomLine6German, gJiminyHeartlessWhiteMushroomLine7German,
    gJiminyHeartlessWhiteMushroomLine8German,
};

const JiminyTextChar* gJiminyHeartlessWhiteMushroomLinesItalian[9] = {
    gJiminyHeartlessWhiteMushroomLine0Italian, gJiminyHeartlessWhiteMushroomLine1Italian, gJiminyHeartlessWhiteMushroomLine2Italian, gJiminyHeartlessWhiteMushroomLine3Italian,
    gJiminyHeartlessWhiteMushroomLine4Italian, gJiminyHeartlessWhiteMushroomLine5Italian, gJiminyHeartlessWhiteMushroomLine6Italian, gJiminyHeartlessWhiteMushroomLine7Italian,
    gJiminyHeartlessWhiteMushroomLine8Italian,
};

const JiminyTextChar* gJiminyHeartlessWhiteMushroomLinesSpanish[8] = {
    gJiminyHeartlessWhiteMushroomLine0Spanish, gJiminyHeartlessWhiteMushroomLine1Spanish, gJiminyHeartlessWhiteMushroomLine2Spanish, gJiminyHeartlessWhiteMushroomLine3Spanish,
    gJiminyHeartlessWhiteMushroomLine4Spanish, gJiminyHeartlessWhiteMushroomLine5Spanish, gJiminyHeartlessWhiteMushroomLine6Spanish, gJiminyHeartlessWhiteMushroomLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessBlackFungusLines[12] = {
    gJiminyHeartlessBlackFungusLine0, gJiminyHeartlessBlackFungusLine1, gJiminyHeartlessBlackFungusLine2, gJiminyHeartlessBlackFungusLine3,
    gJiminyHeartlessBlackFungusLine4, gJiminyHeartlessBlackFungusLine5, gJiminyHeartlessBlackFungusLine6, gJiminyHeartlessBlackFungusLine7,
    gJiminyHeartlessBlackFungusLine8, gJiminyHeartlessBlackFungusLine9, gJiminyHeartlessBlackFungusLine10, gJiminyHeartlessBlackFungusLine11,
};

const JiminyTextChar* gJiminyHeartlessBlackFungusLinesFrench[13] = {
    gJiminyHeartlessBlackFungusLine0French, gJiminyHeartlessBlackFungusLine1French, gJiminyHeartlessBlackFungusLine2French, gJiminyHeartlessBlackFungusLine3French,
    gJiminyHeartlessBlackFungusLine4French, gJiminyHeartlessBlackFungusLine5French, gJiminyHeartlessBlackFungusLine6French, gJiminyHeartlessBlackFungusLine7French,
    gJiminyHeartlessBlackFungusLine8French, gJiminyHeartlessBlackFungusLine9French, gJiminyHeartlessBlackFungusLine10French, gJiminyHeartlessBlackFungusLine11French,
    gJiminyHeartlessBlackFungusLine12French,
};

const JiminyTextChar* gJiminyHeartlessBlackFungusLinesGerman[13] = {
    gJiminyHeartlessBlackFungusLine0German, gJiminyHeartlessBlackFungusLine1German, gJiminyHeartlessBlackFungusLine2German, gJiminyHeartlessBlackFungusLine3German,
    gJiminyHeartlessBlackFungusLine4German, gJiminyHeartlessBlackFungusLine5German, gJiminyHeartlessBlackFungusLine6German, gJiminyHeartlessBlackFungusLine7German,
    gJiminyHeartlessBlackFungusLine8German, gJiminyHeartlessBlackFungusLine9German, gJiminyHeartlessBlackFungusLine10German, gJiminyHeartlessBlackFungusLine11German,
    gJiminyHeartlessBlackFungusLine12German,
};

const JiminyTextChar* gJiminyHeartlessBlackFungusLinesItalian[13] = {
    gJiminyHeartlessBlackFungusLine0Italian, gJiminyHeartlessBlackFungusLine1Italian, gJiminyHeartlessBlackFungusLine2Italian, gJiminyHeartlessBlackFungusLine3Italian,
    gJiminyHeartlessBlackFungusLine4Italian, gJiminyHeartlessBlackFungusLine5Italian, gJiminyHeartlessBlackFungusLine6Italian, gJiminyHeartlessBlackFungusLine7Italian,
    gJiminyHeartlessBlackFungusLine8Italian, gJiminyHeartlessBlackFungusLine9Italian, gJiminyHeartlessBlackFungusLine10Italian, gJiminyHeartlessBlackFungusLine11Italian,
    gJiminyHeartlessBlackFungusLine12Italian,
};

const JiminyTextChar* gJiminyHeartlessBlackFungusLinesSpanish[12] = {
    gJiminyHeartlessBlackFungusLine0Spanish, gJiminyHeartlessBlackFungusLine1Spanish, gJiminyHeartlessBlackFungusLine2Spanish, gJiminyHeartlessBlackFungusLine3Spanish,
    gJiminyHeartlessBlackFungusLine4Spanish, gJiminyHeartlessBlackFungusLine5Spanish, gJiminyHeartlessBlackFungusLine6Spanish, gJiminyHeartlessBlackFungusLine7Spanish,
    gJiminyHeartlessBlackFungusLine8Spanish, gJiminyHeartlessBlackFungusLine9Spanish, gJiminyHeartlessBlackFungusLine10Spanish, gJiminyHeartlessBlackFungusLine11Spanish,
};

const JiminyTextChar* gJiminyHeartlessCreeperPlantLines[8] = {
    gJiminyHeartlessCreeperPlantLine0, gJiminyHeartlessCreeperPlantLine1, gJiminyHeartlessCreeperPlantLine2, gJiminyHeartlessCreeperPlantLine3,
    gJiminyHeartlessCreeperPlantLine4, gJiminyHeartlessCreeperPlantLine5, gJiminyHeartlessCreeperPlantLine6, gJiminyHeartlessCreeperPlantLine7,
};

const JiminyTextChar* gJiminyHeartlessCreeperPlantLinesFrench[8] = {
    gJiminyHeartlessCreeperPlantLine0French, gJiminyHeartlessCreeperPlantLine1French, gJiminyHeartlessCreeperPlantLine2French, gJiminyHeartlessCreeperPlantLine3French,
    gJiminyHeartlessCreeperPlantLine4French, gJiminyHeartlessCreeperPlantLine5French, gJiminyHeartlessCreeperPlantLine6French, gJiminyHeartlessCreeperPlantLine7French,
};

const JiminyTextChar* gJiminyHeartlessCreeperPlantLinesGerman[12] = {
    gJiminyHeartlessCreeperPlantLine0German, gJiminyHeartlessCreeperPlantLine1German, gJiminyHeartlessCreeperPlantLine2German, gJiminyHeartlessCreeperPlantLine3German,
    gJiminyHeartlessCreeperPlantLine4German, gJiminyHeartlessCreeperPlantLine5German, gJiminyHeartlessCreeperPlantLine6German, gJiminyHeartlessCreeperPlantLine7German,
    gJiminyHeartlessCreeperPlantLine8German, gJiminyHeartlessCreeperPlantLine9German, gJiminyHeartlessCreeperPlantLine10German, gJiminyHeartlessCreeperPlantLine11German,
};

const JiminyTextChar* gJiminyHeartlessCreeperPlantLinesItalian[9] = {
    gJiminyHeartlessCreeperPlantLine0Italian, gJiminyHeartlessCreeperPlantLine1Italian, gJiminyHeartlessCreeperPlantLine2Italian, gJiminyHeartlessCreeperPlantLine3Italian,
    gJiminyHeartlessCreeperPlantLine4Italian, gJiminyHeartlessCreeperPlantLine5Italian, gJiminyHeartlessCreeperPlantLine6Italian, gJiminyHeartlessCreeperPlantLine7Italian,
    gJiminyHeartlessCreeperPlantLine8Italian,
};

const JiminyTextChar* gJiminyHeartlessCreeperPlantLinesSpanish[8] = {
    gJiminyHeartlessCreeperPlantLine0Spanish, gJiminyHeartlessCreeperPlantLine1Spanish, gJiminyHeartlessCreeperPlantLine2Spanish, gJiminyHeartlessCreeperPlantLine3Spanish,
    gJiminyHeartlessCreeperPlantLine4Spanish, gJiminyHeartlessCreeperPlantLine5Spanish, gJiminyHeartlessCreeperPlantLine6Spanish, gJiminyHeartlessCreeperPlantLine7Spanish,
};

const JiminyTextChar* gJiminyHeartlessTornadoStepLines[9] = {
    gJiminyHeartlessTornadoStepLine0, gJiminyHeartlessTornadoStepLine1, gJiminyHeartlessTornadoStepLine2, gJiminyHeartlessTornadoStepLine3,
    gJiminyHeartlessTornadoStepLine4, gJiminyHeartlessTornadoStepLine5, gJiminyHeartlessTornadoStepLine6, gJiminyHeartlessTornadoStepLine7,
    gJiminyHeartlessTornadoStepLine8,
};

const JiminyTextChar* gJiminyHeartlessTornadoStepLinesFrench[9] = {
    gJiminyHeartlessTornadoStepLine0French, gJiminyHeartlessTornadoStepLine1French, gJiminyHeartlessTornadoStepLine2French, gJiminyHeartlessTornadoStepLine3French,
    gJiminyHeartlessTornadoStepLine4French, gJiminyHeartlessTornadoStepLine5French, gJiminyHeartlessTornadoStepLine6French, gJiminyHeartlessTornadoStepLine7French,
    gJiminyHeartlessTornadoStepLine8French,
};

const JiminyTextChar* gJiminyHeartlessTornadoStepLinesGerman[11] = {
    gJiminyHeartlessTornadoStepLine0German, gJiminyHeartlessTornadoStepLine1German, gJiminyHeartlessTornadoStepLine2German, gJiminyHeartlessTornadoStepLine3German,
    gJiminyHeartlessTornadoStepLine4German, gJiminyHeartlessTornadoStepLine5German, gJiminyHeartlessTornadoStepLine6German, gJiminyHeartlessTornadoStepLine7German,
    gJiminyHeartlessTornadoStepLine8German, gJiminyHeartlessTornadoStepLine9German, gJiminyHeartlessTornadoStepLine10German,
};

const JiminyTextChar* gJiminyHeartlessTornadoStepLinesItalian[9] = {
    gJiminyHeartlessTornadoStepLine0Italian, gJiminyHeartlessTornadoStepLine1Italian, gJiminyHeartlessTornadoStepLine2Italian, gJiminyHeartlessTornadoStepLine3Italian,
    gJiminyHeartlessTornadoStepLine4Italian, gJiminyHeartlessTornadoStepLine5Italian, gJiminyHeartlessTornadoStepLine6Italian, gJiminyHeartlessTornadoStepLine7Italian,
    gJiminyHeartlessTornadoStepLine8Italian,
};

const JiminyTextChar* gJiminyHeartlessTornadoStepLinesSpanish[10] = {
    gJiminyHeartlessTornadoStepLine0Spanish, gJiminyHeartlessTornadoStepLine1Spanish, gJiminyHeartlessTornadoStepLine2Spanish, gJiminyHeartlessTornadoStepLine3Spanish,
    gJiminyHeartlessTornadoStepLine4Spanish, gJiminyHeartlessTornadoStepLine5Spanish, gJiminyHeartlessTornadoStepLine6Spanish, gJiminyHeartlessTornadoStepLine7Spanish,
    gJiminyHeartlessTornadoStepLine8Spanish, gJiminyHeartlessTornadoStepLine9Spanish,
};

const JiminyTextChar* gJiminyHeartlessCrescendoLines[6] = {
    gJiminyHeartlessCrescendoLine0, gJiminyHeartlessCrescendoLine1, gJiminyHeartlessCrescendoLine2, gJiminyHeartlessCrescendoLine3,
    gJiminyHeartlessCrescendoLine4, gJiminyHeartlessCrescendoLine5,
};

const JiminyTextChar* gJiminyHeartlessCrescendoLinesFrench[7] = {
    gJiminyHeartlessCrescendoLine0French, gJiminyHeartlessCrescendoLine1French, gJiminyHeartlessCrescendoLine2French, gJiminyHeartlessCrescendoLine3French,
    gJiminyHeartlessCrescendoLine4French, gJiminyHeartlessCrescendoLine5French, gJiminyHeartlessCrescendoLine6French,
};

const JiminyTextChar* gJiminyHeartlessCrescendoLinesGerman[6] = {
    gJiminyHeartlessCrescendoLine0German, gJiminyHeartlessCrescendoLine1German, gJiminyHeartlessCrescendoLine2German, gJiminyHeartlessCrescendoLine3German,
    gJiminyHeartlessCrescendoLine4German, gJiminyHeartlessCrescendoLine5German,
};

const JiminyTextChar* gJiminyHeartlessCrescendoLinesItalian[6] = {
    gJiminyHeartlessCrescendoLine0Italian, gJiminyHeartlessCrescendoLine1Italian, gJiminyHeartlessCrescendoLine2Italian, gJiminyHeartlessCrescendoLine3Italian,
    gJiminyHeartlessCrescendoLine4Italian, gJiminyHeartlessCrescendoLine5Italian,
};

const JiminyTextChar* gJiminyHeartlessCrescendoLinesSpanish[6] = {
    gJiminyHeartlessCrescendoLine0Spanish, gJiminyHeartlessCrescendoLine1Spanish, gJiminyHeartlessCrescendoLine2Spanish, gJiminyHeartlessCrescendoLine3Spanish,
    gJiminyHeartlessCrescendoLine4Spanish, gJiminyHeartlessCrescendoLine5Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterRikuLines[24] = {
    gJiminyRikuCharacterRikuLine0, gJiminyRikuCharacterRikuLine1, gJiminyRikuCharacterRikuLine2, gJiminyRikuCharacterRikuLine3,
    gJiminyRikuCharacterRikuLine4, gJiminyRikuCharacterRikuLine5, gJiminyRikuCharacterRikuLine6, gJiminyRikuCharacterRikuLine7,
    gJiminyRikuCharacterRikuLine8, gJiminyRikuCharacterRikuLine9, gJiminyRikuCharacterRikuLine10, gJiminyRikuCharacterRikuLine11,
    gJiminyRikuCharacterRikuLine12, gJiminyRikuCharacterRikuLine13, gJiminyRikuCharacterRikuLine14, gJiminyRikuCharacterRikuLine15,
    gJiminyRikuCharacterRikuLine16, gJiminyRikuCharacterRikuLine17, gJiminyRikuCharacterRikuLine18, gJiminyRikuCharacterRikuLine19,
    gJiminyRikuCharacterRikuLine20, gJiminyRikuCharacterRikuLine21, gJiminyRikuCharacterRikuLine22, gJiminyRikuCharacterRikuLine23,
};

const JiminyTextChar* gJiminyRikuCharacterRikuLinesFrench[25] = {
    gJiminyRikuCharacterRikuLine0French, gJiminyRikuCharacterRikuLine1French, gJiminyRikuCharacterRikuLine2French, gJiminyRikuCharacterRikuLine3French,
    gJiminyRikuCharacterRikuLine4French, gJiminyRikuCharacterRikuLine5French, gJiminyRikuCharacterRikuLine6French, gJiminyRikuCharacterRikuLine7French,
    gJiminyRikuCharacterRikuLine8French, gJiminyRikuCharacterRikuLine9French, gJiminyRikuCharacterRikuLine10French, gJiminyRikuCharacterRikuLine11French,
    gJiminyRikuCharacterRikuLine12French, gJiminyRikuCharacterRikuLine13French, gJiminyRikuCharacterRikuLine14French, gJiminyRikuCharacterRikuLine15French,
    gJiminyRikuCharacterRikuLine16French, gJiminyRikuCharacterRikuLine17French, gJiminyRikuCharacterRikuLine18French, gJiminyRikuCharacterRikuLine19French,
    gJiminyRikuCharacterRikuLine20French, gJiminyRikuCharacterRikuLine21French, gJiminyRikuCharacterRikuLine22French, gJiminyRikuCharacterRikuLine23French,
    gJiminyRikuCharacterRikuLine24French,
};

const JiminyTextChar* gJiminyRikuCharacterRikuLinesGerman[28] = {
    gJiminyRikuCharacterRikuLine0German, gJiminyRikuCharacterRikuLine1German, gJiminyRikuCharacterRikuLine2German, gJiminyRikuCharacterRikuLine3German,
    gJiminyRikuCharacterRikuLine4German, gJiminyRikuCharacterRikuLine5German, gJiminyRikuCharacterRikuLine6German, gJiminyRikuCharacterRikuLine7German,
    gJiminyRikuCharacterRikuLine8German, gJiminyRikuCharacterRikuLine9German, gJiminyRikuCharacterRikuLine10German, gJiminyRikuCharacterRikuLine11German,
    gJiminyRikuCharacterRikuLine12German, gJiminyRikuCharacterRikuLine13German, gJiminyRikuCharacterRikuLine14German, gJiminyRikuCharacterRikuLine15German,
    gJiminyRikuCharacterRikuLine16German, gJiminyRikuCharacterRikuLine17German, gJiminyRikuCharacterRikuLine18German, gJiminyRikuCharacterRikuLine19German,
    gJiminyRikuCharacterRikuLine20German, gJiminyRikuCharacterRikuLine21German, gJiminyRikuCharacterRikuLine22German, gJiminyRikuCharacterRikuLine23German,
    gJiminyRikuCharacterRikuLine24German, gJiminyRikuCharacterRikuLine25German, gJiminyRikuCharacterRikuLine26German, gJiminyRikuCharacterRikuLine27German,
};

const JiminyTextChar* gJiminyRikuCharacterRikuLinesItalian[25] = {
    gJiminyRikuCharacterRikuLine0Italian, gJiminyRikuCharacterRikuLine1Italian, gJiminyRikuCharacterRikuLine2Italian, gJiminyRikuCharacterRikuLine3Italian,
    gJiminyRikuCharacterRikuLine4Italian, gJiminyRikuCharacterRikuLine5Italian, gJiminyRikuCharacterRikuLine6Italian, gJiminyRikuCharacterRikuLine7Italian,
    gJiminyRikuCharacterRikuLine8Italian, gJiminyRikuCharacterRikuLine9Italian, gJiminyRikuCharacterRikuLine10Italian, gJiminyRikuCharacterRikuLine11Italian,
    gJiminyRikuCharacterRikuLine12Italian, gJiminyRikuCharacterRikuLine13Italian, gJiminyRikuCharacterRikuLine14Italian, gJiminyRikuCharacterRikuLine15Italian,
    gJiminyRikuCharacterRikuLine16Italian, gJiminyRikuCharacterRikuLine17Italian, gJiminyRikuCharacterRikuLine18Italian, gJiminyRikuCharacterRikuLine19Italian,
    gJiminyRikuCharacterRikuLine20Italian, gJiminyRikuCharacterRikuLine21Italian, gJiminyRikuCharacterRikuLine22Italian, gJiminyRikuCharacterRikuLine23Italian,
    gJiminyRikuCharacterRikuLine24Italian,
};

const JiminyTextChar* gJiminyRikuCharacterRikuLinesSpanish[25] = {
    gJiminyRikuCharacterRikuLine0Spanish, gJiminyRikuCharacterRikuLine1Spanish, gJiminyRikuCharacterRikuLine2Spanish, gJiminyRikuCharacterRikuLine3Spanish,
    gJiminyRikuCharacterRikuLine4Spanish, gJiminyRikuCharacterRikuLine5Spanish, gJiminyRikuCharacterRikuLine6Spanish, gJiminyRikuCharacterRikuLine7Spanish,
    gJiminyRikuCharacterRikuLine8Spanish, gJiminyRikuCharacterRikuLine9Spanish, gJiminyRikuCharacterRikuLine10Spanish, gJiminyRikuCharacterRikuLine11Spanish,
    gJiminyRikuCharacterRikuLine12Spanish, gJiminyRikuCharacterRikuLine13Spanish, gJiminyRikuCharacterRikuLine14Spanish, gJiminyRikuCharacterRikuLine15Spanish,
    gJiminyRikuCharacterRikuLine16Spanish, gJiminyRikuCharacterRikuLine17Spanish, gJiminyRikuCharacterRikuLine18Spanish, gJiminyRikuCharacterRikuLine19Spanish,
    gJiminyRikuCharacterRikuLine20Spanish, gJiminyRikuCharacterRikuLine21Spanish, gJiminyRikuCharacterRikuLine22Spanish, gJiminyRikuCharacterRikuLine23Spanish,
    gJiminyRikuCharacterRikuLine24Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterKingLines[15] = {
    gJiminyRikuCharacterKingLine0, gJiminyRikuCharacterKingLine1, gJiminyRikuCharacterKingLine2, gJiminyRikuCharacterKingLine3,
    gJiminyRikuCharacterKingLine4, gJiminyRikuCharacterKingLine5, gJiminyRikuCharacterKingLine6, gJiminyRikuCharacterKingLine7,
    gJiminyRikuCharacterKingLine8, gJiminyRikuCharacterKingLine9, gJiminyRikuCharacterKingLine10, gJiminyRikuCharacterKingLine11,
    gJiminyRikuCharacterKingLine12, gJiminyRikuCharacterKingLine13, gJiminyRikuCharacterKingLine14,
};

const JiminyTextChar* gJiminyRikuCharacterKingLinesFrench[16] = {
    gJiminyRikuCharacterKingLine0French, gJiminyRikuCharacterKingLine1French, gJiminyRikuCharacterKingLine2French, gJiminyRikuCharacterKingLine3French,
    gJiminyRikuCharacterKingLine4French, gJiminyRikuCharacterKingLine5French, gJiminyRikuCharacterKingLine6French, gJiminyRikuCharacterKingLine7French,
    gJiminyRikuCharacterKingLine8French, gJiminyRikuCharacterKingLine9French, gJiminyRikuCharacterKingLine10French, gJiminyRikuCharacterKingLine11French,
    gJiminyRikuCharacterKingLine12French, gJiminyRikuCharacterKingLine13French, gJiminyRikuCharacterKingLine14French, gJiminyRikuCharacterKingLine15French,
};

const JiminyTextChar* gJiminyRikuCharacterKingLinesGerman[19] = {
    gJiminyRikuCharacterKingLine0German, gJiminyRikuCharacterKingLine1German, gJiminyRikuCharacterKingLine2German, gJiminyRikuCharacterKingLine3German,
    gJiminyRikuCharacterKingLine4German, gJiminyRikuCharacterKingLine5German, gJiminyRikuCharacterKingLine6German, gJiminyRikuCharacterKingLine7German,
    gJiminyRikuCharacterKingLine8German, gJiminyRikuCharacterKingLine9German, gJiminyRikuCharacterKingLine10German, gJiminyRikuCharacterKingLine11German,
    gJiminyRikuCharacterKingLine12German, gJiminyRikuCharacterKingLine13German, gJiminyRikuCharacterKingLine14German, gJiminyRikuCharacterKingLine15German,
    gJiminyRikuCharacterKingLine16German, gJiminyRikuCharacterKingLine17German, gJiminyRikuCharacterKingLine18German,
};

const JiminyTextChar* gJiminyRikuCharacterKingLinesItalian[14] = {
    gJiminyRikuCharacterKingLine0Italian, gJiminyRikuCharacterKingLine1Italian, gJiminyRikuCharacterKingLine2Italian, gJiminyRikuCharacterKingLine3Italian,
    gJiminyRikuCharacterKingLine4Italian, gJiminyRikuCharacterKingLine5Italian, gJiminyRikuCharacterKingLine6Italian, gJiminyRikuCharacterKingLine7Italian,
    gJiminyRikuCharacterKingLine8Italian, gJiminyRikuCharacterKingLine9Italian, gJiminyRikuCharacterKingLine10Italian, gJiminyRikuCharacterKingLine11Italian,
    gJiminyRikuCharacterKingLine12Italian, gJiminyRikuCharacterKingLine13Italian,
};

const JiminyTextChar* gJiminyRikuCharacterKingLinesSpanish[16] = {
    gJiminyRikuCharacterKingLine0Spanish, gJiminyRikuCharacterKingLine1Spanish, gJiminyRikuCharacterKingLine2Spanish, gJiminyRikuCharacterKingLine3Spanish,
    gJiminyRikuCharacterKingLine4Spanish, gJiminyRikuCharacterKingLine5Spanish, gJiminyRikuCharacterKingLine6Spanish, gJiminyRikuCharacterKingLine7Spanish,
    gJiminyRikuCharacterKingLine8Spanish, gJiminyRikuCharacterKingLine9Spanish, gJiminyRikuCharacterKingLine10Spanish, gJiminyRikuCharacterKingLine11Spanish,
    gJiminyRikuCharacterKingLine12Spanish, gJiminyRikuCharacterKingLine13Spanish, gJiminyRikuCharacterKingLine14Spanish, gJiminyRikuCharacterKingLine15Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterSoraLines[13] = {
    gJiminyRikuCharacterSoraLine0, gJiminyRikuCharacterSoraLine1, gJiminyRikuCharacterSoraLine2, gJiminyRikuCharacterSoraLine3,
    gJiminyRikuCharacterSoraLine4, gJiminyRikuCharacterSoraLine5, gJiminyRikuCharacterSoraLine6, gJiminyRikuCharacterSoraLine7,
    gJiminyRikuCharacterSoraLine8, gJiminyRikuCharacterSoraLine9, gJiminyRikuCharacterSoraLine10, gJiminyRikuCharacterSoraLine11,
    gJiminyRikuCharacterSoraLine12,
};

const JiminyTextChar* gJiminyRikuCharacterSoraLinesFrench[13] = {
    gJiminyRikuCharacterSoraLine0French, gJiminyRikuCharacterSoraLine1French, gJiminyRikuCharacterSoraLine2French, gJiminyRikuCharacterSoraLine3French,
    gJiminyRikuCharacterSoraLine4French, gJiminyRikuCharacterSoraLine5French, gJiminyRikuCharacterSoraLine6French, gJiminyRikuCharacterSoraLine7French,
    gJiminyRikuCharacterSoraLine8French, gJiminyRikuCharacterSoraLine9French, gJiminyRikuCharacterSoraLine10French, gJiminyRikuCharacterSoraLine11French,
    gJiminyRikuCharacterSoraLine12French,
};

const JiminyTextChar* gJiminyRikuCharacterSoraLinesGerman[14] = {
    gJiminyRikuCharacterSoraLine0German, gJiminyRikuCharacterSoraLine1German, gJiminyRikuCharacterSoraLine2German, gJiminyRikuCharacterSoraLine3German,
    gJiminyRikuCharacterSoraLine4German, gJiminyRikuCharacterSoraLine5German, gJiminyRikuCharacterSoraLine6German, gJiminyRikuCharacterSoraLine7German,
    gJiminyRikuCharacterSoraLine8German, gJiminyRikuCharacterSoraLine9German, gJiminyRikuCharacterSoraLine10German, gJiminyRikuCharacterSoraLine11German,
    gJiminyRikuCharacterSoraLine12German, gJiminyRikuCharacterSoraLine13German,
};

const JiminyTextChar* gJiminyRikuCharacterSoraLinesItalian[11] = {
    gJiminyRikuCharacterSoraLine0Italian, gJiminyRikuCharacterSoraLine1Italian, gJiminyRikuCharacterSoraLine2Italian, gJiminyRikuCharacterSoraLine3Italian,
    gJiminyRikuCharacterSoraLine4Italian, gJiminyRikuCharacterSoraLine5Italian, gJiminyRikuCharacterSoraLine6Italian, gJiminyRikuCharacterSoraLine7Italian,
    gJiminyRikuCharacterSoraLine8Italian, gJiminyRikuCharacterSoraLine9Italian, gJiminyRikuCharacterSoraLine10Italian,
};

const JiminyTextChar* gJiminyRikuCharacterSoraLinesSpanish[13] = {
    gJiminyRikuCharacterSoraLine0Spanish, gJiminyRikuCharacterSoraLine1Spanish, gJiminyRikuCharacterSoraLine2Spanish, gJiminyRikuCharacterSoraLine3Spanish,
    gJiminyRikuCharacterSoraLine4Spanish, gJiminyRikuCharacterSoraLine5Spanish, gJiminyRikuCharacterSoraLine6Spanish, gJiminyRikuCharacterSoraLine7Spanish,
    gJiminyRikuCharacterSoraLine8Spanish, gJiminyRikuCharacterSoraLine9Spanish, gJiminyRikuCharacterSoraLine10Spanish, gJiminyRikuCharacterSoraLine11Spanish,
    gJiminyRikuCharacterSoraLine12Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterKairiLines[16] = {
    gJiminyRikuCharacterKairiLine0, gJiminyRikuCharacterKairiLine1, gJiminyRikuCharacterKairiLine2, gJiminyRikuCharacterKairiLine3,
    gJiminyRikuCharacterKairiLine4, gJiminyRikuCharacterKairiLine5, gJiminyRikuCharacterKairiLine6, gJiminyRikuCharacterKairiLine7,
    gJiminyRikuCharacterKairiLine8, gJiminyRikuCharacterKairiLine9, gJiminyRikuCharacterKairiLine10, gJiminyRikuCharacterKairiLine11,
    gJiminyRikuCharacterKairiLine12, gJiminyRikuCharacterKairiLine13, gJiminyRikuCharacterKairiLine14, gJiminyRikuCharacterKairiLine15,
};

const JiminyTextChar* gJiminyRikuCharacterKairiLinesFrench[19] = {
    gJiminyRikuCharacterKairiLine0French, gJiminyRikuCharacterKairiLine1French, gJiminyRikuCharacterKairiLine2French, gJiminyRikuCharacterKairiLine3French,
    gJiminyRikuCharacterKairiLine4French, gJiminyRikuCharacterKairiLine5French, gJiminyRikuCharacterKairiLine6French, gJiminyRikuCharacterKairiLine7French,
    gJiminyRikuCharacterKairiLine8French, gJiminyRikuCharacterKairiLine9French, gJiminyRikuCharacterKairiLine10French, gJiminyRikuCharacterKairiLine11French,
    gJiminyRikuCharacterKairiLine12French, gJiminyRikuCharacterKairiLine13French, gJiminyRikuCharacterKairiLine14French, gJiminyRikuCharacterKairiLine15French,
    gJiminyRikuCharacterKairiLine16French, gJiminyRikuCharacterKairiLine17French, gJiminyRikuCharacterKairiLine18French,
};

const JiminyTextChar* gJiminyRikuCharacterKairiLinesGerman[21] = {
    gJiminyRikuCharacterKairiLine0German, gJiminyRikuCharacterKairiLine1German, gJiminyRikuCharacterKairiLine2German, gJiminyRikuCharacterKairiLine3German,
    gJiminyRikuCharacterKairiLine4German, gJiminyRikuCharacterKairiLine5German, gJiminyRikuCharacterKairiLine6German, gJiminyRikuCharacterKairiLine7German,
    gJiminyRikuCharacterKairiLine8German, gJiminyRikuCharacterKairiLine9German, gJiminyRikuCharacterKairiLine10German, gJiminyRikuCharacterKairiLine11German,
    gJiminyRikuCharacterKairiLine12German, gJiminyRikuCharacterKairiLine13German, gJiminyRikuCharacterKairiLine14German, gJiminyRikuCharacterKairiLine15German,
    gJiminyRikuCharacterKairiLine16German, gJiminyRikuCharacterKairiLine17German, gJiminyRikuCharacterKairiLine18German, gJiminyRikuCharacterKairiLine19German,
    gJiminyRikuCharacterKairiLine20German,
};

const JiminyTextChar* gJiminyRikuCharacterKairiLinesItalian[18] = {
    gJiminyRikuCharacterKairiLine0Italian, gJiminyRikuCharacterKairiLine1Italian, gJiminyRikuCharacterKairiLine2Italian, gJiminyRikuCharacterKairiLine3Italian,
    gJiminyRikuCharacterKairiLine4Italian, gJiminyRikuCharacterKairiLine5Italian, gJiminyRikuCharacterKairiLine6Italian, gJiminyRikuCharacterKairiLine7Italian,
    gJiminyRikuCharacterKairiLine8Italian, gJiminyRikuCharacterKairiLine9Italian, gJiminyRikuCharacterKairiLine10Italian, gJiminyRikuCharacterKairiLine11Italian,
    gJiminyRikuCharacterKairiLine12Italian, gJiminyRikuCharacterKairiLine13Italian, gJiminyRikuCharacterKairiLine14Italian, gJiminyRikuCharacterKairiLine15Italian,
    gJiminyRikuCharacterKairiLine16Italian, gJiminyRikuCharacterKairiLine17Italian,
};

const JiminyTextChar* gJiminyRikuCharacterKairiLinesSpanish[18] = {
    gJiminyRikuCharacterKairiLine0Spanish, gJiminyRikuCharacterKairiLine1Spanish, gJiminyRikuCharacterKairiLine2Spanish, gJiminyRikuCharacterKairiLine3Spanish,
    gJiminyRikuCharacterKairiLine4Spanish, gJiminyRikuCharacterKairiLine5Spanish, gJiminyRikuCharacterKairiLine6Spanish, gJiminyRikuCharacterKairiLine7Spanish,
    gJiminyRikuCharacterKairiLine8Spanish, gJiminyRikuCharacterKairiLine9Spanish, gJiminyRikuCharacterKairiLine10Spanish, gJiminyRikuCharacterKairiLine11Spanish,
    gJiminyRikuCharacterKairiLine12Spanish, gJiminyRikuCharacterKairiLine13Spanish, gJiminyRikuCharacterKairiLine14Spanish, gJiminyRikuCharacterKairiLine15Spanish,
    gJiminyRikuCharacterKairiLine16Spanish, gJiminyRikuCharacterKairiLine17Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterNamineLines[16] = {
    gJiminyRikuCharacterNamineLine0, gJiminyRikuCharacterNamineLine1, gJiminyRikuCharacterNamineLine2, gJiminyRikuCharacterNamineLine3,
    gJiminyRikuCharacterNamineLine4, gJiminyRikuCharacterNamineLine5, gJiminyRikuCharacterNamineLine6, gJiminyRikuCharacterNamineLine7,
    gJiminyRikuCharacterNamineLine8, gJiminyRikuCharacterNamineLine9, gJiminyRikuCharacterNamineLine10, gJiminyRikuCharacterNamineLine11,
    gJiminyRikuCharacterNamineLine12, gJiminyRikuCharacterNamineLine13, gJiminyRikuCharacterNamineLine14, gJiminyRikuCharacterNamineLine15,
};

const JiminyTextChar* gJiminyRikuCharacterNamineLinesFrench[20] = {
    gJiminyRikuCharacterNamineLine0French, gJiminyRikuCharacterNamineLine1French, gJiminyRikuCharacterNamineLine2French, gJiminyRikuCharacterNamineLine3French,
    gJiminyRikuCharacterNamineLine4French, gJiminyRikuCharacterNamineLine5French, gJiminyRikuCharacterNamineLine6French, gJiminyRikuCharacterNamineLine7French,
    gJiminyRikuCharacterNamineLine8French, gJiminyRikuCharacterNamineLine9French, gJiminyRikuCharacterNamineLine10French, gJiminyRikuCharacterNamineLine11French,
    gJiminyRikuCharacterNamineLine12French, gJiminyRikuCharacterNamineLine13French, gJiminyRikuCharacterNamineLine14French, gJiminyRikuCharacterNamineLine15French,
    gJiminyRikuCharacterNamineLine16French, gJiminyRikuCharacterNamineLine17French, gJiminyRikuCharacterNamineLine18French, gJiminyRikuCharacterNamineLine19French,
};

const JiminyTextChar* gJiminyRikuCharacterNamineLinesGerman[23] = {
    gJiminyRikuCharacterNamineLine0German, gJiminyRikuCharacterNamineLine1German, gJiminyRikuCharacterNamineLine2German, gJiminyRikuCharacterNamineLine3German,
    gJiminyRikuCharacterNamineLine4German, gJiminyRikuCharacterNamineLine5German, gJiminyRikuCharacterNamineLine6German, gJiminyRikuCharacterNamineLine7German,
    gJiminyRikuCharacterNamineLine8German, gJiminyRikuCharacterNamineLine9German, gJiminyRikuCharacterNamineLine10German, gJiminyRikuCharacterNamineLine11German,
    gJiminyRikuCharacterNamineLine12German, gJiminyRikuCharacterNamineLine13German, gJiminyRikuCharacterNamineLine14German, gJiminyRikuCharacterNamineLine15German,
    gJiminyRikuCharacterNamineLine16German, gJiminyRikuCharacterNamineLine17German, gJiminyRikuCharacterNamineLine18German, gJiminyRikuCharacterNamineLine19German,
    gJiminyRikuCharacterNamineLine20German, gJiminyRikuCharacterNamineLine21German, gJiminyRikuCharacterNamineLine22German,
};

const JiminyTextChar* gJiminyRikuCharacterNamineLinesItalian[20] = {
    gJiminyRikuCharacterNamineLine0Italian, gJiminyRikuCharacterNamineLine1Italian, gJiminyRikuCharacterNamineLine2Italian, gJiminyRikuCharacterNamineLine3Italian,
    gJiminyRikuCharacterNamineLine4Italian, gJiminyRikuCharacterNamineLine5Italian, gJiminyRikuCharacterNamineLine6Italian, gJiminyRikuCharacterNamineLine7Italian,
    gJiminyRikuCharacterNamineLine8Italian, gJiminyRikuCharacterNamineLine9Italian, gJiminyRikuCharacterNamineLine10Italian, gJiminyRikuCharacterNamineLine11Italian,
    gJiminyRikuCharacterNamineLine12Italian, gJiminyRikuCharacterNamineLine13Italian, gJiminyRikuCharacterNamineLine14Italian, gJiminyRikuCharacterNamineLine15Italian,
    gJiminyRikuCharacterNamineLine16Italian, gJiminyRikuCharacterNamineLine17Italian, gJiminyRikuCharacterNamineLine18Italian, gJiminyRikuCharacterNamineLine19Italian,
};

const JiminyTextChar* gJiminyRikuCharacterNamineLinesSpanish[18] = {
    gJiminyRikuCharacterNamineLine0Spanish, gJiminyRikuCharacterNamineLine1Spanish, gJiminyRikuCharacterNamineLine2Spanish, gJiminyRikuCharacterNamineLine3Spanish,
    gJiminyRikuCharacterNamineLine4Spanish, gJiminyRikuCharacterNamineLine5Spanish, gJiminyRikuCharacterNamineLine6Spanish, gJiminyRikuCharacterNamineLine7Spanish,
    gJiminyRikuCharacterNamineLine8Spanish, gJiminyRikuCharacterNamineLine9Spanish, gJiminyRikuCharacterNamineLine10Spanish, gJiminyRikuCharacterNamineLine11Spanish,
    gJiminyRikuCharacterNamineLine12Spanish, gJiminyRikuCharacterNamineLine13Spanish, gJiminyRikuCharacterNamineLine14Spanish, gJiminyRikuCharacterNamineLine15Spanish,
    gJiminyRikuCharacterNamineLine16Spanish, gJiminyRikuCharacterNamineLine17Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterRikuReplicaLines[8] = {
    gJiminyRikuCharacterRikuReplicaLine0, gJiminyRikuCharacterRikuReplicaLine1, gJiminyRikuCharacterRikuReplicaLine2, gJiminyRikuCharacterRikuReplicaLine3,
    gJiminyRikuCharacterRikuReplicaLine4, gJiminyRikuCharacterRikuReplicaLine5, gJiminyRikuCharacterRikuReplicaLine6, gJiminyRikuCharacterRikuReplicaLine7,
};

const JiminyTextChar* gJiminyRikuCharacterRikuReplicaLinesFrench[9] = {
    gJiminyRikuCharacterRikuReplicaLine0French, gJiminyRikuCharacterRikuReplicaLine1French, gJiminyRikuCharacterRikuReplicaLine2French, gJiminyRikuCharacterRikuReplicaLine3French,
    gJiminyRikuCharacterRikuReplicaLine4French, gJiminyRikuCharacterRikuReplicaLine5French, gJiminyRikuCharacterRikuReplicaLine6French, gJiminyRikuCharacterRikuReplicaLine7French,
    gJiminyRikuCharacterRikuReplicaLine8French,
};

const JiminyTextChar* gJiminyRikuCharacterRikuReplicaLinesGerman[12] = {
    gJiminyRikuCharacterRikuReplicaLine0German, gJiminyRikuCharacterRikuReplicaLine1German, gJiminyRikuCharacterRikuReplicaLine2German, gJiminyRikuCharacterRikuReplicaLine3German,
    gJiminyRikuCharacterRikuReplicaLine4German, gJiminyRikuCharacterRikuReplicaLine5German, gJiminyRikuCharacterRikuReplicaLine6German, gJiminyRikuCharacterRikuReplicaLine7German,
    gJiminyRikuCharacterRikuReplicaLine8German, gJiminyRikuCharacterRikuReplicaLine9German, gJiminyRikuCharacterRikuReplicaLine10German, gJiminyRikuCharacterRikuReplicaLine11German,
};

const JiminyTextChar* gJiminyRikuCharacterRikuReplicaLinesItalian[10] = {
    gJiminyRikuCharacterRikuReplicaLine0Italian, gJiminyRikuCharacterRikuReplicaLine1Italian, gJiminyRikuCharacterRikuReplicaLine2Italian, gJiminyRikuCharacterRikuReplicaLine3Italian,
    gJiminyRikuCharacterRikuReplicaLine4Italian, gJiminyRikuCharacterRikuReplicaLine5Italian, gJiminyRikuCharacterRikuReplicaLine6Italian, gJiminyRikuCharacterRikuReplicaLine7Italian,
    gJiminyRikuCharacterRikuReplicaLine8Italian, gJiminyRikuCharacterRikuReplicaLine9Italian,
};

const JiminyTextChar* gJiminyRikuCharacterRikuReplicaLinesSpanish[11] = {
    gJiminyRikuCharacterRikuReplicaLine0Spanish, gJiminyRikuCharacterRikuReplicaLine1Spanish, gJiminyRikuCharacterRikuReplicaLine2Spanish, gJiminyRikuCharacterRikuReplicaLine3Spanish,
    gJiminyRikuCharacterRikuReplicaLine4Spanish, gJiminyRikuCharacterRikuReplicaLine5Spanish, gJiminyRikuCharacterRikuReplicaLine6Spanish, gJiminyRikuCharacterRikuReplicaLine7Spanish,
    gJiminyRikuCharacterRikuReplicaLine8Spanish, gJiminyRikuCharacterRikuReplicaLine9Spanish, gJiminyRikuCharacterRikuReplicaLine10Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterAnsemLines[14] = {
    gJiminyRikuCharacterAnsemLine0, gJiminyRikuCharacterAnsemLine1, gJiminyRikuCharacterAnsemLine2, gJiminyRikuCharacterAnsemLine3,
    gJiminyRikuCharacterAnsemLine4, gJiminyRikuCharacterAnsemLine5, gJiminyRikuCharacterAnsemLine6, gJiminyRikuCharacterAnsemLine7,
    gJiminyRikuCharacterAnsemLine8, gJiminyRikuCharacterAnsemLine9, gJiminyRikuCharacterAnsemLine10, gJiminyRikuCharacterAnsemLine11,
    gJiminyRikuCharacterAnsemLine12, gJiminyRikuCharacterAnsemLine13,
};

const JiminyTextChar* gJiminyRikuCharacterAnsemLinesFrench[14] = {
    gJiminyRikuCharacterAnsemLine0French, gJiminyRikuCharacterAnsemLine1French, gJiminyRikuCharacterAnsemLine2French, gJiminyRikuCharacterAnsemLine3French,
    gJiminyRikuCharacterAnsemLine4French, gJiminyRikuCharacterAnsemLine5French, gJiminyRikuCharacterAnsemLine6French, gJiminyRikuCharacterAnsemLine7French,
    gJiminyRikuCharacterAnsemLine8French, gJiminyRikuCharacterAnsemLine9French, gJiminyRikuCharacterAnsemLine10French, gJiminyRikuCharacterAnsemLine11French,
    gJiminyRikuCharacterAnsemLine12French, gJiminyRikuCharacterAnsemLine13French,
};

const JiminyTextChar* gJiminyRikuCharacterAnsemLinesGerman[16] = {
    gJiminyRikuCharacterAnsemLine0German, gJiminyRikuCharacterAnsemLine1German, gJiminyRikuCharacterAnsemLine2German, gJiminyRikuCharacterAnsemLine3German,
    gJiminyRikuCharacterAnsemLine4German, gJiminyRikuCharacterAnsemLine5German, gJiminyRikuCharacterAnsemLine6German, gJiminyRikuCharacterAnsemLine7German,
    gJiminyRikuCharacterAnsemLine8German, gJiminyRikuCharacterAnsemLine9German, gJiminyRikuCharacterAnsemLine10German, gJiminyRikuCharacterAnsemLine11German,
    gJiminyRikuCharacterAnsemLine12German, gJiminyRikuCharacterAnsemLine13German, gJiminyRikuCharacterAnsemLine14German, gJiminyRikuCharacterAnsemLine15German,
};

const JiminyTextChar* gJiminyRikuCharacterAnsemLinesItalian[16] = {
    gJiminyRikuCharacterAnsemLine0Italian, gJiminyRikuCharacterAnsemLine1Italian, gJiminyRikuCharacterAnsemLine2Italian, gJiminyRikuCharacterAnsemLine3Italian,
    gJiminyRikuCharacterAnsemLine4Italian, gJiminyRikuCharacterAnsemLine5Italian, gJiminyRikuCharacterAnsemLine6Italian, gJiminyRikuCharacterAnsemLine7Italian,
    gJiminyRikuCharacterAnsemLine8Italian, gJiminyRikuCharacterAnsemLine9Italian, gJiminyRikuCharacterAnsemLine10Italian, gJiminyRikuCharacterAnsemLine11Italian,
    gJiminyRikuCharacterAnsemLine12Italian, gJiminyRikuCharacterAnsemLine13Italian, gJiminyRikuCharacterAnsemLine14Italian, gJiminyRikuCharacterAnsemLine15Italian,
};

const JiminyTextChar* gJiminyRikuCharacterAnsemLinesSpanish[17] = {
    gJiminyRikuCharacterAnsemLine0Spanish, gJiminyRikuCharacterAnsemLine1Spanish, gJiminyRikuCharacterAnsemLine2Spanish, gJiminyRikuCharacterAnsemLine3Spanish,
    gJiminyRikuCharacterAnsemLine4Spanish, gJiminyRikuCharacterAnsemLine5Spanish, gJiminyRikuCharacterAnsemLine6Spanish, gJiminyRikuCharacterAnsemLine7Spanish,
    gJiminyRikuCharacterAnsemLine8Spanish, gJiminyRikuCharacterAnsemLine9Spanish, gJiminyRikuCharacterAnsemLine10Spanish, gJiminyRikuCharacterAnsemLine11Spanish,
    gJiminyRikuCharacterAnsemLine12Spanish, gJiminyRikuCharacterAnsemLine13Spanish, gJiminyRikuCharacterAnsemLine14Spanish, gJiminyRikuCharacterAnsemLine15Spanish,
    gJiminyRikuCharacterAnsemLine16Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterVexenLines[16] = {
    gJiminyRikuCharacterVexenLine0, gJiminyRikuCharacterVexenLine1, gJiminyRikuCharacterVexenLine2, gJiminyRikuCharacterVexenLine3,
    gJiminyRikuCharacterVexenLine4, gJiminyRikuCharacterVexenLine5, gJiminyRikuCharacterVexenLine6, gJiminyRikuCharacterVexenLine7,
    gJiminyRikuCharacterVexenLine8, gJiminyRikuCharacterVexenLine9, gJiminyRikuCharacterVexenLine10, gJiminyRikuCharacterVexenLine11,
    gJiminyRikuCharacterVexenLine12, gJiminyRikuCharacterVexenLine13, gJiminyRikuCharacterVexenLine14, gJiminyRikuCharacterVexenLine15,
};

const JiminyTextChar* gJiminyRikuCharacterVexenLinesFrench[18] = {
    gJiminyRikuCharacterVexenLine0French, gJiminyRikuCharacterVexenLine1French, gJiminyRikuCharacterVexenLine2French, gJiminyRikuCharacterVexenLine3French,
    gJiminyRikuCharacterVexenLine4French, gJiminyRikuCharacterVexenLine5French, gJiminyRikuCharacterVexenLine6French, gJiminyRikuCharacterVexenLine7French,
    gJiminyRikuCharacterVexenLine8French, gJiminyRikuCharacterVexenLine9French, gJiminyRikuCharacterVexenLine10French, gJiminyRikuCharacterVexenLine11French,
    gJiminyRikuCharacterVexenLine12French, gJiminyRikuCharacterVexenLine13French, gJiminyRikuCharacterVexenLine14French, gJiminyRikuCharacterVexenLine15French,
    gJiminyRikuCharacterVexenLine16French, gJiminyRikuCharacterVexenLine17French,
};

const JiminyTextChar* gJiminyRikuCharacterVexenLinesGerman[16] = {
    gJiminyRikuCharacterVexenLine0German, gJiminyRikuCharacterVexenLine1German, gJiminyRikuCharacterVexenLine2German, gJiminyRikuCharacterVexenLine3German,
    gJiminyRikuCharacterVexenLine4German, gJiminyRikuCharacterVexenLine5German, gJiminyRikuCharacterVexenLine6German, gJiminyRikuCharacterVexenLine7German,
    gJiminyRikuCharacterVexenLine8German, gJiminyRikuCharacterVexenLine9German, gJiminyRikuCharacterVexenLine10German, gJiminyRikuCharacterVexenLine11German,
    gJiminyRikuCharacterVexenLine12German, gJiminyRikuCharacterVexenLine13German, gJiminyRikuCharacterVexenLine14German, gJiminyRikuCharacterVexenLine15German,
};

const JiminyTextChar* gJiminyRikuCharacterVexenLinesItalian[18] = {
    gJiminyRikuCharacterVexenLine0Italian, gJiminyRikuCharacterVexenLine1Italian, gJiminyRikuCharacterVexenLine2Italian, gJiminyRikuCharacterVexenLine3Italian,
    gJiminyRikuCharacterVexenLine4Italian, gJiminyRikuCharacterVexenLine5Italian, gJiminyRikuCharacterVexenLine6Italian, gJiminyRikuCharacterVexenLine7Italian,
    gJiminyRikuCharacterVexenLine8Italian, gJiminyRikuCharacterVexenLine9Italian, gJiminyRikuCharacterVexenLine10Italian, gJiminyRikuCharacterVexenLine11Italian,
    gJiminyRikuCharacterVexenLine12Italian, gJiminyRikuCharacterVexenLine13Italian, gJiminyRikuCharacterVexenLine14Italian, gJiminyRikuCharacterVexenLine15Italian,
    gJiminyRikuCharacterVexenLine16Italian, gJiminyRikuCharacterVexenLine17Italian,
};

const JiminyTextChar* gJiminyRikuCharacterVexenLinesSpanish[16] = {
    gJiminyRikuCharacterVexenLine0Spanish, gJiminyRikuCharacterVexenLine1Spanish, gJiminyRikuCharacterVexenLine2Spanish, gJiminyRikuCharacterVexenLine3Spanish,
    gJiminyRikuCharacterVexenLine4Spanish, gJiminyRikuCharacterVexenLine5Spanish, gJiminyRikuCharacterVexenLine6Spanish, gJiminyRikuCharacterVexenLine7Spanish,
    gJiminyRikuCharacterVexenLine8Spanish, gJiminyRikuCharacterVexenLine9Spanish, gJiminyRikuCharacterVexenLine10Spanish, gJiminyRikuCharacterVexenLine11Spanish,
    gJiminyRikuCharacterVexenLine12Spanish, gJiminyRikuCharacterVexenLine13Spanish, gJiminyRikuCharacterVexenLine14Spanish, gJiminyRikuCharacterVexenLine15Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterLexaeusLines[17] = {
    gJiminyRikuCharacterLexaeusLine0, gJiminyRikuCharacterLexaeusLine1, gJiminyRikuCharacterLexaeusLine2, gJiminyRikuCharacterLexaeusLine3,
    gJiminyRikuCharacterLexaeusLine4, gJiminyRikuCharacterLexaeusLine5, gJiminyRikuCharacterLexaeusLine6, gJiminyRikuCharacterLexaeusLine7,
    gJiminyRikuCharacterLexaeusLine8, gJiminyRikuCharacterLexaeusLine9, gJiminyRikuCharacterLexaeusLine10, gJiminyRikuCharacterLexaeusLine11,
    gJiminyRikuCharacterLexaeusLine12, gJiminyRikuCharacterLexaeusLine13, gJiminyRikuCharacterLexaeusLine14, gJiminyRikuCharacterLexaeusLine15,
    gJiminyRikuCharacterLexaeusLine16,
};

const JiminyTextChar* gJiminyRikuCharacterLexaeusLinesFrench[18] = {
    gJiminyRikuCharacterLexaeusLine0French, gJiminyRikuCharacterLexaeusLine1French, gJiminyRikuCharacterLexaeusLine2French, gJiminyRikuCharacterLexaeusLine3French,
    gJiminyRikuCharacterLexaeusLine4French, gJiminyRikuCharacterLexaeusLine5French, gJiminyRikuCharacterLexaeusLine6French, gJiminyRikuCharacterLexaeusLine7French,
    gJiminyRikuCharacterLexaeusLine8French, gJiminyRikuCharacterLexaeusLine9French, gJiminyRikuCharacterLexaeusLine10French, gJiminyRikuCharacterLexaeusLine11French,
    gJiminyRikuCharacterLexaeusLine12French, gJiminyRikuCharacterLexaeusLine13French, gJiminyRikuCharacterLexaeusLine14French, gJiminyRikuCharacterLexaeusLine15French,
    gJiminyRikuCharacterLexaeusLine16French, gJiminyRikuCharacterLexaeusLine17French,
};

const JiminyTextChar* gJiminyRikuCharacterLexaeusLinesGerman[19] = {
    gJiminyRikuCharacterLexaeusLine0German, gJiminyRikuCharacterLexaeusLine1German, gJiminyRikuCharacterLexaeusLine2German, gJiminyRikuCharacterLexaeusLine3German,
    gJiminyRikuCharacterLexaeusLine4German, gJiminyRikuCharacterLexaeusLine5German, gJiminyRikuCharacterLexaeusLine6German, gJiminyRikuCharacterLexaeusLine7German,
    gJiminyRikuCharacterLexaeusLine8German, gJiminyRikuCharacterLexaeusLine9German, gJiminyRikuCharacterLexaeusLine10German, gJiminyRikuCharacterLexaeusLine11German,
    gJiminyRikuCharacterLexaeusLine12German, gJiminyRikuCharacterLexaeusLine13German, gJiminyRikuCharacterLexaeusLine14German, gJiminyRikuCharacterLexaeusLine15German,
    gJiminyRikuCharacterLexaeusLine16German, gJiminyRikuCharacterLexaeusLine17German, gJiminyRikuCharacterLexaeusLine18German,
};

const JiminyTextChar* gJiminyRikuCharacterLexaeusLinesItalian[18] = {
    gJiminyRikuCharacterLexaeusLine0Italian, gJiminyRikuCharacterLexaeusLine1Italian, gJiminyRikuCharacterLexaeusLine2Italian, gJiminyRikuCharacterLexaeusLine3Italian,
    gJiminyRikuCharacterLexaeusLine4Italian, gJiminyRikuCharacterLexaeusLine5Italian, gJiminyRikuCharacterLexaeusLine6Italian, gJiminyRikuCharacterLexaeusLine7Italian,
    gJiminyRikuCharacterLexaeusLine8Italian, gJiminyRikuCharacterLexaeusLine9Italian, gJiminyRikuCharacterLexaeusLine10Italian, gJiminyRikuCharacterLexaeusLine11Italian,
    gJiminyRikuCharacterLexaeusLine12Italian, gJiminyRikuCharacterLexaeusLine13Italian, gJiminyRikuCharacterLexaeusLine14Italian, gJiminyRikuCharacterLexaeusLine15Italian,
    gJiminyRikuCharacterLexaeusLine16Italian, gJiminyRikuCharacterLexaeusLine17Italian,
};

const JiminyTextChar* gJiminyRikuCharacterLexaeusLinesSpanish[19] = {
    gJiminyRikuCharacterLexaeusLine0Spanish, gJiminyRikuCharacterLexaeusLine1Spanish, gJiminyRikuCharacterLexaeusLine2Spanish, gJiminyRikuCharacterLexaeusLine3Spanish,
    gJiminyRikuCharacterLexaeusLine4Spanish, gJiminyRikuCharacterLexaeusLine5Spanish, gJiminyRikuCharacterLexaeusLine6Spanish, gJiminyRikuCharacterLexaeusLine7Spanish,
    gJiminyRikuCharacterLexaeusLine8Spanish, gJiminyRikuCharacterLexaeusLine9Spanish, gJiminyRikuCharacterLexaeusLine10Spanish, gJiminyRikuCharacterLexaeusLine11Spanish,
    gJiminyRikuCharacterLexaeusLine12Spanish, gJiminyRikuCharacterLexaeusLine13Spanish, gJiminyRikuCharacterLexaeusLine14Spanish, gJiminyRikuCharacterLexaeusLine15Spanish,
    gJiminyRikuCharacterLexaeusLine16Spanish, gJiminyRikuCharacterLexaeusLine17Spanish, gJiminyRikuCharacterLexaeusLine18Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterZexionLines[17] = {
    gJiminyRikuCharacterZexionLine0, gJiminyRikuCharacterZexionLine1, gJiminyRikuCharacterZexionLine2, gJiminyRikuCharacterZexionLine3,
    gJiminyRikuCharacterZexionLine4, gJiminyRikuCharacterZexionLine5, gJiminyRikuCharacterZexionLine6, gJiminyRikuCharacterZexionLine7,
    gJiminyRikuCharacterZexionLine8, gJiminyRikuCharacterZexionLine9, gJiminyRikuCharacterZexionLine10, gJiminyRikuCharacterZexionLine11,
    gJiminyRikuCharacterZexionLine12, gJiminyRikuCharacterZexionLine13, gJiminyRikuCharacterZexionLine14, gJiminyRikuCharacterZexionLine15,
    gJiminyRikuCharacterZexionLine16,
};

const JiminyTextChar* gJiminyRikuCharacterZexionLinesFrench[18] = {
    gJiminyRikuCharacterZexionLine0French, gJiminyRikuCharacterZexionLine1French, gJiminyRikuCharacterZexionLine2French, gJiminyRikuCharacterZexionLine3French,
    gJiminyRikuCharacterZexionLine4French, gJiminyRikuCharacterZexionLine5French, gJiminyRikuCharacterZexionLine6French, gJiminyRikuCharacterZexionLine7French,
    gJiminyRikuCharacterZexionLine8French, gJiminyRikuCharacterZexionLine9French, gJiminyRikuCharacterZexionLine10French, gJiminyRikuCharacterZexionLine11French,
    gJiminyRikuCharacterZexionLine12French, gJiminyRikuCharacterZexionLine13French, gJiminyRikuCharacterZexionLine14French, gJiminyRikuCharacterZexionLine15French,
    gJiminyRikuCharacterZexionLine16French, gJiminyRikuCharacterZexionLine17French,
};

const JiminyTextChar* gJiminyRikuCharacterZexionLinesGerman[19] = {
    gJiminyRikuCharacterZexionLine0German, gJiminyRikuCharacterZexionLine1German, gJiminyRikuCharacterZexionLine2German, gJiminyRikuCharacterZexionLine3German,
    gJiminyRikuCharacterZexionLine4German, gJiminyRikuCharacterZexionLine5German, gJiminyRikuCharacterZexionLine6German, gJiminyRikuCharacterZexionLine7German,
    gJiminyRikuCharacterZexionLine8German, gJiminyRikuCharacterZexionLine9German, gJiminyRikuCharacterZexionLine10German, gJiminyRikuCharacterZexionLine11German,
    gJiminyRikuCharacterZexionLine12German, gJiminyRikuCharacterZexionLine13German, gJiminyRikuCharacterZexionLine14German, gJiminyRikuCharacterZexionLine15German,
    gJiminyRikuCharacterZexionLine16German, gJiminyRikuCharacterZexionLine17German, gJiminyRikuCharacterZexionLine18German,
};

const JiminyTextChar* gJiminyRikuCharacterZexionLinesItalian[17] = {
    gJiminyRikuCharacterZexionLine0Italian, gJiminyRikuCharacterZexionLine1Italian, gJiminyRikuCharacterZexionLine2Italian, gJiminyRikuCharacterZexionLine3Italian,
    gJiminyRikuCharacterZexionLine4Italian, gJiminyRikuCharacterZexionLine5Italian, gJiminyRikuCharacterZexionLine6Italian, gJiminyRikuCharacterZexionLine7Italian,
    gJiminyRikuCharacterZexionLine8Italian, gJiminyRikuCharacterZexionLine9Italian, gJiminyRikuCharacterZexionLine10Italian, gJiminyRikuCharacterZexionLine11Italian,
    gJiminyRikuCharacterZexionLine12Italian, gJiminyRikuCharacterZexionLine13Italian, gJiminyRikuCharacterZexionLine14Italian, gJiminyRikuCharacterZexionLine15Italian,
    gJiminyRikuCharacterZexionLine16Italian,
};

const JiminyTextChar* gJiminyRikuCharacterZexionLinesSpanish[20] = {
    gJiminyRikuCharacterZexionLine0Spanish, gJiminyRikuCharacterZexionLine1Spanish, gJiminyRikuCharacterZexionLine2Spanish, gJiminyRikuCharacterZexionLine3Spanish,
    gJiminyRikuCharacterZexionLine4Spanish, gJiminyRikuCharacterZexionLine5Spanish, gJiminyRikuCharacterZexionLine6Spanish, gJiminyRikuCharacterZexionLine7Spanish,
    gJiminyRikuCharacterZexionLine8Spanish, gJiminyRikuCharacterZexionLine9Spanish, gJiminyRikuCharacterZexionLine10Spanish, gJiminyRikuCharacterZexionLine11Spanish,
    gJiminyRikuCharacterZexionLine12Spanish, gJiminyRikuCharacterZexionLine13Spanish, gJiminyRikuCharacterZexionLine14Spanish, gJiminyRikuCharacterZexionLine15Spanish,
    gJiminyRikuCharacterZexionLine16Spanish, gJiminyRikuCharacterZexionLine17Spanish, gJiminyRikuCharacterZexionLine18Spanish, gJiminyRikuCharacterZexionLine19Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterAxelLines[19] = {
    gJiminyRikuCharacterAxelLine0, gJiminyRikuCharacterAxelLine1, gJiminyRikuCharacterAxelLine2, gJiminyRikuCharacterAxelLine3,
    gJiminyRikuCharacterAxelLine4, gJiminyRikuCharacterAxelLine5, gJiminyRikuCharacterAxelLine6, gJiminyRikuCharacterAxelLine7,
    gJiminyRikuCharacterAxelLine8, gJiminyRikuCharacterAxelLine9, gJiminyRikuCharacterAxelLine10, gJiminyRikuCharacterAxelLine11,
    gJiminyRikuCharacterAxelLine12, gJiminyRikuCharacterAxelLine13, gJiminyRikuCharacterAxelLine14, gJiminyRikuCharacterAxelLine15,
    gJiminyRikuCharacterAxelLine16, gJiminyRikuCharacterAxelLine17, gJiminyRikuCharacterAxelLine18,
};

const JiminyTextChar* gJiminyRikuCharacterAxelLinesFrench[17] = {
    gJiminyRikuCharacterAxelLine0French, gJiminyRikuCharacterAxelLine1French, gJiminyRikuCharacterAxelLine2French, gJiminyRikuCharacterAxelLine3French,
    gJiminyRikuCharacterAxelLine4French, gJiminyRikuCharacterAxelLine5French, gJiminyRikuCharacterAxelLine6French, gJiminyRikuCharacterAxelLine7French,
    gJiminyRikuCharacterAxelLine8French, gJiminyRikuCharacterAxelLine9French, gJiminyRikuCharacterAxelLine10French, gJiminyRikuCharacterAxelLine11French,
    gJiminyRikuCharacterAxelLine12French, gJiminyRikuCharacterAxelLine13French, gJiminyRikuCharacterAxelLine14French, gJiminyRikuCharacterAxelLine15French,
    gJiminyRikuCharacterAxelLine16French,
};

const JiminyTextChar* gJiminyRikuCharacterAxelLinesGerman[20] = {
    gJiminyRikuCharacterAxelLine0German, gJiminyRikuCharacterAxelLine1German, gJiminyRikuCharacterAxelLine2German, gJiminyRikuCharacterAxelLine3German,
    gJiminyRikuCharacterAxelLine4German, gJiminyRikuCharacterAxelLine5German, gJiminyRikuCharacterAxelLine6German, gJiminyRikuCharacterAxelLine7German,
    gJiminyRikuCharacterAxelLine8German, gJiminyRikuCharacterAxelLine9German, gJiminyRikuCharacterAxelLine10German, gJiminyRikuCharacterAxelLine11German,
    gJiminyRikuCharacterAxelLine12German, gJiminyRikuCharacterAxelLine13German, gJiminyRikuCharacterAxelLine14German, gJiminyRikuCharacterAxelLine15German,
    gJiminyRikuCharacterAxelLine16German, gJiminyRikuCharacterAxelLine17German, gJiminyRikuCharacterAxelLine18German, gJiminyRikuCharacterAxelLine19German,
};

const JiminyTextChar* gJiminyRikuCharacterAxelLinesItalian[19] = {
    gJiminyRikuCharacterAxelLine0Italian, gJiminyRikuCharacterAxelLine1Italian, gJiminyRikuCharacterAxelLine2Italian, gJiminyRikuCharacterAxelLine3Italian,
    gJiminyRikuCharacterAxelLine4Italian, gJiminyRikuCharacterAxelLine5Italian, gJiminyRikuCharacterAxelLine6Italian, gJiminyRikuCharacterAxelLine7Italian,
    gJiminyRikuCharacterAxelLine8Italian, gJiminyRikuCharacterAxelLine9Italian, gJiminyRikuCharacterAxelLine10Italian, gJiminyRikuCharacterAxelLine11Italian,
    gJiminyRikuCharacterAxelLine12Italian, gJiminyRikuCharacterAxelLine13Italian, gJiminyRikuCharacterAxelLine14Italian, gJiminyRikuCharacterAxelLine15Italian,
    gJiminyRikuCharacterAxelLine16Italian, gJiminyRikuCharacterAxelLine17Italian, gJiminyRikuCharacterAxelLine18Italian,
};

const JiminyTextChar* gJiminyRikuCharacterAxelLinesSpanish[20] = {
    gJiminyRikuCharacterAxelLine0Spanish, gJiminyRikuCharacterAxelLine1Spanish, gJiminyRikuCharacterAxelLine2Spanish, gJiminyRikuCharacterAxelLine3Spanish,
    gJiminyRikuCharacterAxelLine4Spanish, gJiminyRikuCharacterAxelLine5Spanish, gJiminyRikuCharacterAxelLine6Spanish, gJiminyRikuCharacterAxelLine7Spanish,
    gJiminyRikuCharacterAxelLine8Spanish, gJiminyRikuCharacterAxelLine9Spanish, gJiminyRikuCharacterAxelLine10Spanish, gJiminyRikuCharacterAxelLine11Spanish,
    gJiminyRikuCharacterAxelLine12Spanish, gJiminyRikuCharacterAxelLine13Spanish, gJiminyRikuCharacterAxelLine14Spanish, gJiminyRikuCharacterAxelLine15Spanish,
    gJiminyRikuCharacterAxelLine16Spanish, gJiminyRikuCharacterAxelLine17Spanish, gJiminyRikuCharacterAxelLine18Spanish, gJiminyRikuCharacterAxelLine19Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterMarluxiaLines[19] = {
    gJiminyRikuCharacterMarluxiaLine0, gJiminyRikuCharacterMarluxiaLine1, gJiminyRikuCharacterMarluxiaLine2, gJiminyRikuCharacterMarluxiaLine3,
    gJiminyRikuCharacterMarluxiaLine4, gJiminyRikuCharacterMarluxiaLine5, gJiminyRikuCharacterMarluxiaLine6, gJiminyRikuCharacterMarluxiaLine7,
    gJiminyRikuCharacterMarluxiaLine8, gJiminyRikuCharacterMarluxiaLine9, gJiminyRikuCharacterMarluxiaLine10, gJiminyRikuCharacterMarluxiaLine11,
    gJiminyRikuCharacterMarluxiaLine12, gJiminyRikuCharacterMarluxiaLine13, gJiminyRikuCharacterMarluxiaLine14, gJiminyRikuCharacterMarluxiaLine15,
    gJiminyRikuCharacterMarluxiaLine16, gJiminyRikuCharacterMarluxiaLine17, gJiminyRikuCharacterMarluxiaLine18,
};

const JiminyTextChar* gJiminyRikuCharacterMarluxiaLinesFrench[21] = {
    gJiminyRikuCharacterMarluxiaLine0French, gJiminyRikuCharacterMarluxiaLine1French, gJiminyRikuCharacterMarluxiaLine2French, gJiminyRikuCharacterMarluxiaLine3French,
    gJiminyRikuCharacterMarluxiaLine4French, gJiminyRikuCharacterMarluxiaLine5French, gJiminyRikuCharacterMarluxiaLine6French, gJiminyRikuCharacterMarluxiaLine7French,
    gJiminyRikuCharacterMarluxiaLine8French, gJiminyRikuCharacterMarluxiaLine9French, gJiminyRikuCharacterMarluxiaLine10French, gJiminyRikuCharacterMarluxiaLine11French,
    gJiminyRikuCharacterMarluxiaLine12French, gJiminyRikuCharacterMarluxiaLine13French, gJiminyRikuCharacterMarluxiaLine14French, gJiminyRikuCharacterMarluxiaLine15French,
    gJiminyRikuCharacterMarluxiaLine16French, gJiminyRikuCharacterMarluxiaLine17French, gJiminyRikuCharacterMarluxiaLine18French, gJiminyRikuCharacterMarluxiaLine19French,
    gJiminyRikuCharacterMarluxiaLine20French,
};

const JiminyTextChar* gJiminyRikuCharacterMarluxiaLinesGerman[26] = {
    gJiminyRikuCharacterMarluxiaLine0German, gJiminyRikuCharacterMarluxiaLine1German, gJiminyRikuCharacterMarluxiaLine2German, gJiminyRikuCharacterMarluxiaLine3German,
    gJiminyRikuCharacterMarluxiaLine4German, gJiminyRikuCharacterMarluxiaLine5German, gJiminyRikuCharacterMarluxiaLine6German, gJiminyRikuCharacterMarluxiaLine7German,
    gJiminyRikuCharacterMarluxiaLine8German, gJiminyRikuCharacterMarluxiaLine9German, gJiminyRikuCharacterMarluxiaLine10German, gJiminyRikuCharacterMarluxiaLine11German,
    gJiminyRikuCharacterMarluxiaLine12German, gJiminyRikuCharacterMarluxiaLine13German, gJiminyRikuCharacterMarluxiaLine14German, gJiminyRikuCharacterMarluxiaLine15German,
    gJiminyRikuCharacterMarluxiaLine16German, gJiminyRikuCharacterMarluxiaLine17German, gJiminyRikuCharacterMarluxiaLine18German, gJiminyRikuCharacterMarluxiaLine19German,
    gJiminyRikuCharacterMarluxiaLine20German, gJiminyRikuCharacterMarluxiaLine21German, gJiminyRikuCharacterMarluxiaLine22German, gJiminyRikuCharacterMarluxiaLine23German,
    gJiminyRikuCharacterMarluxiaLine24German, gJiminyRikuCharacterMarluxiaLine25German,
};

const JiminyTextChar* gJiminyRikuCharacterMarluxiaLinesItalian[22] = {
    gJiminyRikuCharacterMarluxiaLine0Italian, gJiminyRikuCharacterMarluxiaLine1Italian, gJiminyRikuCharacterMarluxiaLine2Italian, gJiminyRikuCharacterMarluxiaLine3Italian,
    gJiminyRikuCharacterMarluxiaLine4Italian, gJiminyRikuCharacterMarluxiaLine5Italian, gJiminyRikuCharacterMarluxiaLine6Italian, gJiminyRikuCharacterMarluxiaLine7Italian,
    gJiminyRikuCharacterMarluxiaLine8Italian, gJiminyRikuCharacterMarluxiaLine9Italian, gJiminyRikuCharacterMarluxiaLine10Italian, gJiminyRikuCharacterMarluxiaLine11Italian,
    gJiminyRikuCharacterMarluxiaLine12Italian, gJiminyRikuCharacterMarluxiaLine13Italian, gJiminyRikuCharacterMarluxiaLine14Italian, gJiminyRikuCharacterMarluxiaLine15Italian,
    gJiminyRikuCharacterMarluxiaLine16Italian, gJiminyRikuCharacterMarluxiaLine17Italian, gJiminyRikuCharacterMarluxiaLine18Italian, gJiminyRikuCharacterMarluxiaLine19Italian,
    gJiminyRikuCharacterMarluxiaLine20Italian, gJiminyRikuCharacterMarluxiaLine21Italian,
};

const JiminyTextChar* gJiminyRikuCharacterMarluxiaLinesSpanish[20] = {
    gJiminyRikuCharacterMarluxiaLine0Spanish, gJiminyRikuCharacterMarluxiaLine1Spanish, gJiminyRikuCharacterMarluxiaLine2Spanish, gJiminyRikuCharacterMarluxiaLine3Spanish,
    gJiminyRikuCharacterMarluxiaLine4Spanish, gJiminyRikuCharacterMarluxiaLine5Spanish, gJiminyRikuCharacterMarluxiaLine6Spanish, gJiminyRikuCharacterMarluxiaLine7Spanish,
    gJiminyRikuCharacterMarluxiaLine8Spanish, gJiminyRikuCharacterMarluxiaLine9Spanish, gJiminyRikuCharacterMarluxiaLine10Spanish, gJiminyRikuCharacterMarluxiaLine11Spanish,
    gJiminyRikuCharacterMarluxiaLine12Spanish, gJiminyRikuCharacterMarluxiaLine13Spanish, gJiminyRikuCharacterMarluxiaLine14Spanish, gJiminyRikuCharacterMarluxiaLine15Spanish,
    gJiminyRikuCharacterMarluxiaLine16Spanish, gJiminyRikuCharacterMarluxiaLine17Spanish, gJiminyRikuCharacterMarluxiaLine18Spanish, gJiminyRikuCharacterMarluxiaLine19Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterLarxeneLines[13] = {
    gJiminyRikuCharacterLarxeneLine0, gJiminyRikuCharacterLarxeneLine1, gJiminyRikuCharacterLarxeneLine2, gJiminyRikuCharacterLarxeneLine3,
    gJiminyRikuCharacterLarxeneLine4, gJiminyRikuCharacterLarxeneLine5, gJiminyRikuCharacterLarxeneLine6, gJiminyRikuCharacterLarxeneLine7,
    gJiminyRikuCharacterLarxeneLine8, gJiminyRikuCharacterLarxeneLine9, gJiminyRikuCharacterLarxeneLine10, gJiminyRikuCharacterLarxeneLine11,
    gJiminyRikuCharacterLarxeneLine12,
};

const JiminyTextChar* gJiminyRikuCharacterLarxeneLinesFrench[15] = {
    gJiminyRikuCharacterLarxeneLine0French, gJiminyRikuCharacterLarxeneLine1French, gJiminyRikuCharacterLarxeneLine2French, gJiminyRikuCharacterLarxeneLine3French,
    gJiminyRikuCharacterLarxeneLine4French, gJiminyRikuCharacterLarxeneLine5French, gJiminyRikuCharacterLarxeneLine6French, gJiminyRikuCharacterLarxeneLine7French,
    gJiminyRikuCharacterLarxeneLine8French, gJiminyRikuCharacterLarxeneLine9French, gJiminyRikuCharacterLarxeneLine10French, gJiminyRikuCharacterLarxeneLine11French,
    gJiminyRikuCharacterLarxeneLine12French, gJiminyRikuCharacterLarxeneLine13French, gJiminyRikuCharacterLarxeneLine14French,
};

const JiminyTextChar* gJiminyRikuCharacterLarxeneLinesGerman[17] = {
    gJiminyRikuCharacterLarxeneLine0German, gJiminyRikuCharacterLarxeneLine1German, gJiminyRikuCharacterLarxeneLine2German, gJiminyRikuCharacterLarxeneLine3German,
    gJiminyRikuCharacterLarxeneLine4German, gJiminyRikuCharacterLarxeneLine5German, gJiminyRikuCharacterLarxeneLine6German, gJiminyRikuCharacterLarxeneLine7German,
    gJiminyRikuCharacterLarxeneLine8German, gJiminyRikuCharacterLarxeneLine9German, gJiminyRikuCharacterLarxeneLine10German, gJiminyRikuCharacterLarxeneLine11German,
    gJiminyRikuCharacterLarxeneLine12German, gJiminyRikuCharacterLarxeneLine13German, gJiminyRikuCharacterLarxeneLine14German, gJiminyRikuCharacterLarxeneLine15German,
    gJiminyRikuCharacterLarxeneLine16German,
};

const JiminyTextChar* gJiminyRikuCharacterLarxeneLinesItalian[18] = {
    gJiminyRikuCharacterLarxeneLine0Italian, gJiminyRikuCharacterLarxeneLine1Italian, gJiminyRikuCharacterLarxeneLine2Italian, gJiminyRikuCharacterLarxeneLine3Italian,
    gJiminyRikuCharacterLarxeneLine4Italian, gJiminyRikuCharacterLarxeneLine5Italian, gJiminyRikuCharacterLarxeneLine6Italian, gJiminyRikuCharacterLarxeneLine7Italian,
    gJiminyRikuCharacterLarxeneLine8Italian, gJiminyRikuCharacterLarxeneLine9Italian, gJiminyRikuCharacterLarxeneLine10Italian, gJiminyRikuCharacterLarxeneLine11Italian,
    gJiminyRikuCharacterLarxeneLine12Italian, gJiminyRikuCharacterLarxeneLine13Italian, gJiminyRikuCharacterLarxeneLine14Italian, gJiminyRikuCharacterLarxeneLine15Italian,
    gJiminyRikuCharacterLarxeneLine16Italian, gJiminyRikuCharacterLarxeneLine17Italian,
};

const JiminyTextChar* gJiminyRikuCharacterLarxeneLinesSpanish[15] = {
    gJiminyRikuCharacterLarxeneLine0Spanish, gJiminyRikuCharacterLarxeneLine1Spanish, gJiminyRikuCharacterLarxeneLine2Spanish, gJiminyRikuCharacterLarxeneLine3Spanish,
    gJiminyRikuCharacterLarxeneLine4Spanish, gJiminyRikuCharacterLarxeneLine5Spanish, gJiminyRikuCharacterLarxeneLine6Spanish, gJiminyRikuCharacterLarxeneLine7Spanish,
    gJiminyRikuCharacterLarxeneLine8Spanish, gJiminyRikuCharacterLarxeneLine9Spanish, gJiminyRikuCharacterLarxeneLine10Spanish, gJiminyRikuCharacterLarxeneLine11Spanish,
    gJiminyRikuCharacterLarxeneLine12Spanish, gJiminyRikuCharacterLarxeneLine13Spanish, gJiminyRikuCharacterLarxeneLine14Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterDiZLines[11] = {
    gJiminyRikuCharacterDiZLine0, gJiminyRikuCharacterDiZLine1, gJiminyRikuCharacterDiZLine2, gJiminyRikuCharacterDiZLine3,
    gJiminyRikuCharacterDiZLine4, gJiminyRikuCharacterDiZLine5, gJiminyRikuCharacterDiZLine6, gJiminyRikuCharacterDiZLine7,
    gJiminyRikuCharacterDiZLine8, gJiminyRikuCharacterDiZLine9, gJiminyRikuCharacterDiZLine10,
};

const JiminyTextChar* gJiminyRikuCharacterDiZLinesFrench[13] = {
    gJiminyRikuCharacterDiZLine0French, gJiminyRikuCharacterDiZLine1French, gJiminyRikuCharacterDiZLine2French, gJiminyRikuCharacterDiZLine3French,
    gJiminyRikuCharacterDiZLine4French, gJiminyRikuCharacterDiZLine5French, gJiminyRikuCharacterDiZLine6French, gJiminyRikuCharacterDiZLine7French,
    gJiminyRikuCharacterDiZLine8French, gJiminyRikuCharacterDiZLine9French, gJiminyRikuCharacterDiZLine10French, gJiminyRikuCharacterDiZLine11French,
    gJiminyRikuCharacterDiZLine12French,
};

const JiminyTextChar* gJiminyRikuCharacterDiZLinesGerman[13] = {
    gJiminyRikuCharacterDiZLine0German, gJiminyRikuCharacterDiZLine1German, gJiminyRikuCharacterDiZLine2German, gJiminyRikuCharacterDiZLine3German,
    gJiminyRikuCharacterDiZLine4German, gJiminyRikuCharacterDiZLine5German, gJiminyRikuCharacterDiZLine6German, gJiminyRikuCharacterDiZLine7German,
    gJiminyRikuCharacterDiZLine8German, gJiminyRikuCharacterDiZLine9German, gJiminyRikuCharacterDiZLine10German, gJiminyRikuCharacterDiZLine11German,
    gJiminyRikuCharacterDiZLine12German,
};

const JiminyTextChar* gJiminyRikuCharacterDiZLinesItalian[11] = {
    gJiminyRikuCharacterDiZLine0Italian, gJiminyRikuCharacterDiZLine1Italian, gJiminyRikuCharacterDiZLine2Italian, gJiminyRikuCharacterDiZLine3Italian,
    gJiminyRikuCharacterDiZLine4Italian, gJiminyRikuCharacterDiZLine5Italian, gJiminyRikuCharacterDiZLine6Italian, gJiminyRikuCharacterDiZLine7Italian,
    gJiminyRikuCharacterDiZLine8Italian, gJiminyRikuCharacterDiZLine9Italian, gJiminyRikuCharacterDiZLine10Italian,
};

const JiminyTextChar* gJiminyRikuCharacterDiZLinesSpanish[11] = {
    gJiminyRikuCharacterDiZLine0Spanish, gJiminyRikuCharacterDiZLine1Spanish, gJiminyRikuCharacterDiZLine2Spanish, gJiminyRikuCharacterDiZLine3Spanish,
    gJiminyRikuCharacterDiZLine4Spanish, gJiminyRikuCharacterDiZLine5Spanish, gJiminyRikuCharacterDiZLine6Spanish, gJiminyRikuCharacterDiZLine7Spanish,
    gJiminyRikuCharacterDiZLine8Spanish, gJiminyRikuCharacterDiZLine9Spanish, gJiminyRikuCharacterDiZLine10Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterMaleficentLines[13] = {
    gJiminyRikuCharacterMaleficentLine0, gJiminyRikuCharacterMaleficentLine1, gJiminyRikuCharacterMaleficentLine2, gJiminyRikuCharacterMaleficentLine3,
    gJiminyRikuCharacterMaleficentLine4, gJiminyRikuCharacterMaleficentLine5, gJiminyRikuCharacterMaleficentLine6, gJiminyRikuCharacterMaleficentLine7,
    gJiminyRikuCharacterMaleficentLine8, gJiminyRikuCharacterMaleficentLine9, gJiminyRikuCharacterMaleficentLine10, gJiminyRikuCharacterMaleficentLine11,
    gJiminyRikuCharacterMaleficentLine12,
};

const JiminyTextChar* gJiminyRikuCharacterMaleficentLinesFrench[13] = {
    gJiminyRikuCharacterMaleficentLine0French, gJiminyRikuCharacterMaleficentLine1French, gJiminyRikuCharacterMaleficentLine2French, gJiminyRikuCharacterMaleficentLine3French,
    gJiminyRikuCharacterMaleficentLine4French, gJiminyRikuCharacterMaleficentLine5French, gJiminyRikuCharacterMaleficentLine6French, gJiminyRikuCharacterMaleficentLine7French,
    gJiminyRikuCharacterMaleficentLine8French, gJiminyRikuCharacterMaleficentLine9French, gJiminyRikuCharacterMaleficentLine10French, gJiminyRikuCharacterMaleficentLine11French,
    gJiminyRikuCharacterMaleficentLine12French,
};

const JiminyTextChar* gJiminyRikuCharacterMaleficentLinesGerman[14] = {
    gJiminyRikuCharacterMaleficentLine0German, gJiminyRikuCharacterMaleficentLine1German, gJiminyRikuCharacterMaleficentLine2German, gJiminyRikuCharacterMaleficentLine3German,
    gJiminyRikuCharacterMaleficentLine4German, gJiminyRikuCharacterMaleficentLine5German, gJiminyRikuCharacterMaleficentLine6German, gJiminyRikuCharacterMaleficentLine7German,
    gJiminyRikuCharacterMaleficentLine8German, gJiminyRikuCharacterMaleficentLine9German, gJiminyRikuCharacterMaleficentLine10German, gJiminyRikuCharacterMaleficentLine11German,
    gJiminyRikuCharacterMaleficentLine12German, gJiminyRikuCharacterMaleficentLine13German,
};

const JiminyTextChar* gJiminyRikuCharacterMaleficentLinesItalian[13] = {
    gJiminyRikuCharacterMaleficentLine0Italian, gJiminyRikuCharacterMaleficentLine1Italian, gJiminyRikuCharacterMaleficentLine2Italian, gJiminyRikuCharacterMaleficentLine3Italian,
    gJiminyRikuCharacterMaleficentLine4Italian, gJiminyRikuCharacterMaleficentLine5Italian, gJiminyRikuCharacterMaleficentLine6Italian, gJiminyRikuCharacterMaleficentLine7Italian,
    gJiminyRikuCharacterMaleficentLine8Italian, gJiminyRikuCharacterMaleficentLine9Italian, gJiminyRikuCharacterMaleficentLine10Italian, gJiminyRikuCharacterMaleficentLine11Italian,
    gJiminyRikuCharacterMaleficentLine12Italian,
};

const JiminyTextChar* gJiminyRikuCharacterMaleficentLinesSpanish[15] = {
    gJiminyRikuCharacterMaleficentLine0Spanish, gJiminyRikuCharacterMaleficentLine1Spanish, gJiminyRikuCharacterMaleficentLine2Spanish, gJiminyRikuCharacterMaleficentLine3Spanish,
    gJiminyRikuCharacterMaleficentLine4Spanish, gJiminyRikuCharacterMaleficentLine5Spanish, gJiminyRikuCharacterMaleficentLine6Spanish, gJiminyRikuCharacterMaleficentLine7Spanish,
    gJiminyRikuCharacterMaleficentLine8Spanish, gJiminyRikuCharacterMaleficentLine9Spanish, gJiminyRikuCharacterMaleficentLine10Spanish, gJiminyRikuCharacterMaleficentLine11Spanish,
    gJiminyRikuCharacterMaleficentLine12Spanish, gJiminyRikuCharacterMaleficentLine13Spanish, gJiminyRikuCharacterMaleficentLine14Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterJafarGenieLines[8] = {
    gJiminyRikuCharacterJafarGenieLine0, gJiminyRikuCharacterJafarGenieLine1, gJiminyRikuCharacterJafarGenieLine2, gJiminyRikuCharacterJafarGenieLine3,
    gJiminyRikuCharacterJafarGenieLine4, gJiminyRikuCharacterJafarGenieLine5, gJiminyRikuCharacterJafarGenieLine6, gJiminyRikuCharacterJafarGenieLine7,
};

const JiminyTextChar* gJiminyRikuCharacterJafarGenieLinesFrench[8] = {
    gJiminyRikuCharacterJafarGenieLine0French, gJiminyRikuCharacterJafarGenieLine1French, gJiminyRikuCharacterJafarGenieLine2French, gJiminyRikuCharacterJafarGenieLine3French,
    gJiminyRikuCharacterJafarGenieLine4French, gJiminyRikuCharacterJafarGenieLine5French, gJiminyRikuCharacterJafarGenieLine6French, gJiminyRikuCharacterJafarGenieLine7French,
};

const JiminyTextChar* gJiminyRikuCharacterJafarGenieLinesGerman[9] = {
    gJiminyRikuCharacterJafarGenieLine0German, gJiminyRikuCharacterJafarGenieLine1German, gJiminyRikuCharacterJafarGenieLine2German, gJiminyRikuCharacterJafarGenieLine3German,
    gJiminyRikuCharacterJafarGenieLine4German, gJiminyRikuCharacterJafarGenieLine5German, gJiminyRikuCharacterJafarGenieLine6German, gJiminyRikuCharacterJafarGenieLine7German,
    gJiminyRikuCharacterJafarGenieLine8German,
};

const JiminyTextChar* gJiminyRikuCharacterJafarGenieLinesItalian[7] = {
    gJiminyRikuCharacterJafarGenieLine0Italian, gJiminyRikuCharacterJafarGenieLine1Italian, gJiminyRikuCharacterJafarGenieLine2Italian, gJiminyRikuCharacterJafarGenieLine3Italian,
    gJiminyRikuCharacterJafarGenieLine4Italian, gJiminyRikuCharacterJafarGenieLine5Italian, gJiminyRikuCharacterJafarGenieLine6Italian,
};

const JiminyTextChar* gJiminyRikuCharacterJafarGenieLinesSpanish[8] = {
    gJiminyRikuCharacterJafarGenieLine0Spanish, gJiminyRikuCharacterJafarGenieLine1Spanish, gJiminyRikuCharacterJafarGenieLine2Spanish, gJiminyRikuCharacterJafarGenieLine3Spanish,
    gJiminyRikuCharacterJafarGenieLine4Spanish, gJiminyRikuCharacterJafarGenieLine5Spanish, gJiminyRikuCharacterJafarGenieLine6Spanish, gJiminyRikuCharacterJafarGenieLine7Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterUrsulaLines[9] = {
    gJiminyRikuCharacterUrsulaLine0, gJiminyRikuCharacterUrsulaLine1, gJiminyRikuCharacterUrsulaLine2, gJiminyRikuCharacterUrsulaLine3,
    gJiminyRikuCharacterUrsulaLine4, gJiminyRikuCharacterUrsulaLine5, gJiminyRikuCharacterUrsulaLine6, gJiminyRikuCharacterUrsulaLine7,
    gJiminyRikuCharacterUrsulaLine8,
};

const JiminyTextChar* gJiminyRikuCharacterUrsulaLinesFrench[10] = {
    gJiminyRikuCharacterUrsulaLine0French, gJiminyRikuCharacterUrsulaLine1French, gJiminyRikuCharacterUrsulaLine2French, gJiminyRikuCharacterUrsulaLine3French,
    gJiminyRikuCharacterUrsulaLine4French, gJiminyRikuCharacterUrsulaLine5French, gJiminyRikuCharacterUrsulaLine6French, gJiminyRikuCharacterUrsulaLine7French,
    gJiminyRikuCharacterUrsulaLine8French, gJiminyRikuCharacterUrsulaLine9French,
};

const JiminyTextChar* gJiminyRikuCharacterUrsulaLinesGerman[10] = {
    gJiminyRikuCharacterUrsulaLine0German, gJiminyRikuCharacterUrsulaLine1German, gJiminyRikuCharacterUrsulaLine2German, gJiminyRikuCharacterUrsulaLine3German,
    gJiminyRikuCharacterUrsulaLine4German, gJiminyRikuCharacterUrsulaLine5German, gJiminyRikuCharacterUrsulaLine6German, gJiminyRikuCharacterUrsulaLine7German,
    gJiminyRikuCharacterUrsulaLine8German, gJiminyRikuCharacterUrsulaLine9German,
};

const JiminyTextChar* gJiminyRikuCharacterUrsulaLinesItalian[9] = {
    gJiminyRikuCharacterUrsulaLine0Italian, gJiminyRikuCharacterUrsulaLine1Italian, gJiminyRikuCharacterUrsulaLine2Italian, gJiminyRikuCharacterUrsulaLine3Italian,
    gJiminyRikuCharacterUrsulaLine4Italian, gJiminyRikuCharacterUrsulaLine5Italian, gJiminyRikuCharacterUrsulaLine6Italian, gJiminyRikuCharacterUrsulaLine7Italian,
    gJiminyRikuCharacterUrsulaLine8Italian,
};

const JiminyTextChar* gJiminyRikuCharacterUrsulaLinesSpanish[9] = {
    gJiminyRikuCharacterUrsulaLine0Spanish, gJiminyRikuCharacterUrsulaLine1Spanish, gJiminyRikuCharacterUrsulaLine2Spanish, gJiminyRikuCharacterUrsulaLine3Spanish,
    gJiminyRikuCharacterUrsulaLine4Spanish, gJiminyRikuCharacterUrsulaLine5Spanish, gJiminyRikuCharacterUrsulaLine6Spanish, gJiminyRikuCharacterUrsulaLine7Spanish,
    gJiminyRikuCharacterUrsulaLine8Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterHadesLines[8] = {
    gJiminyRikuCharacterHadesLine0, gJiminyRikuCharacterHadesLine1, gJiminyRikuCharacterHadesLine2, gJiminyRikuCharacterHadesLine3,
    gJiminyRikuCharacterHadesLine4, gJiminyRikuCharacterHadesLine5, gJiminyRikuCharacterHadesLine6, gJiminyRikuCharacterHadesLine7,
};

const JiminyTextChar* gJiminyRikuCharacterHadesLinesFrench[8] = {
    gJiminyRikuCharacterHadesLine0French, gJiminyRikuCharacterHadesLine1French, gJiminyRikuCharacterHadesLine2French, gJiminyRikuCharacterHadesLine3French,
    gJiminyRikuCharacterHadesLine4French, gJiminyRikuCharacterHadesLine5French, gJiminyRikuCharacterHadesLine6French, gJiminyRikuCharacterHadesLine7French,
};

const JiminyTextChar* gJiminyRikuCharacterHadesLinesGerman[8] = {
    gJiminyRikuCharacterHadesLine0German, gJiminyRikuCharacterHadesLine1German, gJiminyRikuCharacterHadesLine2German, gJiminyRikuCharacterHadesLine3German,
    gJiminyRikuCharacterHadesLine4German, gJiminyRikuCharacterHadesLine5German, gJiminyRikuCharacterHadesLine6German, gJiminyRikuCharacterHadesLine7German,
};

const JiminyTextChar* gJiminyRikuCharacterHadesLinesItalian[8] = {
    gJiminyRikuCharacterHadesLine0Italian, gJiminyRikuCharacterHadesLine1Italian, gJiminyRikuCharacterHadesLine2Italian, gJiminyRikuCharacterHadesLine3Italian,
    gJiminyRikuCharacterHadesLine4Italian, gJiminyRikuCharacterHadesLine5Italian, gJiminyRikuCharacterHadesLine6Italian, gJiminyRikuCharacterHadesLine7Italian,
};

const JiminyTextChar* gJiminyRikuCharacterHadesLinesSpanish[8] = {
    gJiminyRikuCharacterHadesLine0Spanish, gJiminyRikuCharacterHadesLine1Spanish, gJiminyRikuCharacterHadesLine2Spanish, gJiminyRikuCharacterHadesLine3Spanish,
    gJiminyRikuCharacterHadesLine4Spanish, gJiminyRikuCharacterHadesLine5Spanish, gJiminyRikuCharacterHadesLine6Spanish, gJiminyRikuCharacterHadesLine7Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterOogieBoogieLines[8] = {
    gJiminyRikuCharacterOogieBoogieLine0, gJiminyRikuCharacterOogieBoogieLine1, gJiminyRikuCharacterOogieBoogieLine2, gJiminyRikuCharacterOogieBoogieLine3,
    gJiminyRikuCharacterOogieBoogieLine4, gJiminyRikuCharacterOogieBoogieLine5, gJiminyRikuCharacterOogieBoogieLine6, gJiminyRikuCharacterOogieBoogieLine7,
};

const JiminyTextChar* gJiminyRikuCharacterOogieBoogieLinesFrench[9] = {
    gJiminyRikuCharacterOogieBoogieLine0French, gJiminyRikuCharacterOogieBoogieLine1French, gJiminyRikuCharacterOogieBoogieLine2French, gJiminyRikuCharacterOogieBoogieLine3French,
    gJiminyRikuCharacterOogieBoogieLine4French, gJiminyRikuCharacterOogieBoogieLine5French, gJiminyRikuCharacterOogieBoogieLine6French, gJiminyRikuCharacterOogieBoogieLine7French,
    gJiminyRikuCharacterOogieBoogieLine8French,
};

const JiminyTextChar* gJiminyRikuCharacterOogieBoogieLinesGerman[8] = {
    gJiminyRikuCharacterOogieBoogieLine0German, gJiminyRikuCharacterOogieBoogieLine1German, gJiminyRikuCharacterOogieBoogieLine2German, gJiminyRikuCharacterOogieBoogieLine3German,
    gJiminyRikuCharacterOogieBoogieLine4German, gJiminyRikuCharacterOogieBoogieLine5German, gJiminyRikuCharacterOogieBoogieLine6German, gJiminyRikuCharacterOogieBoogieLine7German,
};

const JiminyTextChar* gJiminyRikuCharacterOogieBoogieLinesItalian[8] = {
    gJiminyRikuCharacterOogieBoogieLine0Italian, gJiminyRikuCharacterOogieBoogieLine1Italian, gJiminyRikuCharacterOogieBoogieLine2Italian, gJiminyRikuCharacterOogieBoogieLine3Italian,
    gJiminyRikuCharacterOogieBoogieLine4Italian, gJiminyRikuCharacterOogieBoogieLine5Italian, gJiminyRikuCharacterOogieBoogieLine6Italian, gJiminyRikuCharacterOogieBoogieLine7Italian,
};

const JiminyTextChar* gJiminyRikuCharacterOogieBoogieLinesSpanish[8] = {
    gJiminyRikuCharacterOogieBoogieLine0Spanish, gJiminyRikuCharacterOogieBoogieLine1Spanish, gJiminyRikuCharacterOogieBoogieLine2Spanish, gJiminyRikuCharacterOogieBoogieLine3Spanish,
    gJiminyRikuCharacterOogieBoogieLine4Spanish, gJiminyRikuCharacterOogieBoogieLine5Spanish, gJiminyRikuCharacterOogieBoogieLine6Spanish, gJiminyRikuCharacterOogieBoogieLine7Spanish,
};

const JiminyTextChar* gJiminyRikuCharacterHookLines[6] = {
    gJiminyRikuCharacterHookLine0, gJiminyRikuCharacterHookLine1, gJiminyRikuCharacterHookLine2, gJiminyRikuCharacterHookLine3,
    gJiminyRikuCharacterHookLine4, gJiminyRikuCharacterHookLine5,
};

const JiminyTextChar* gJiminyRikuCharacterHookLinesFrench[7] = {
    gJiminyRikuCharacterHookLine0French, gJiminyRikuCharacterHookLine1French, gJiminyRikuCharacterHookLine2French, gJiminyRikuCharacterHookLine3French,
    gJiminyRikuCharacterHookLine4French, gJiminyRikuCharacterHookLine5French, gJiminyRikuCharacterHookLine6French,
};

const JiminyTextChar* gJiminyRikuCharacterHookLinesGerman[6] = {
    gJiminyRikuCharacterHookLine0German, gJiminyRikuCharacterHookLine1German, gJiminyRikuCharacterHookLine2German, gJiminyRikuCharacterHookLine3German,
    gJiminyRikuCharacterHookLine4German, gJiminyRikuCharacterHookLine5German,
};

const JiminyTextChar* gJiminyRikuCharacterHookLinesItalian[7] = {
    gJiminyRikuCharacterHookLine0Italian, gJiminyRikuCharacterHookLine1Italian, gJiminyRikuCharacterHookLine2Italian, gJiminyRikuCharacterHookLine3Italian,
    gJiminyRikuCharacterHookLine4Italian, gJiminyRikuCharacterHookLine5Italian, gJiminyRikuCharacterHookLine6Italian,
};

const JiminyTextChar* gJiminyRikuCharacterHookLinesSpanish[7] = {
    gJiminyRikuCharacterHookLine0Spanish, gJiminyRikuCharacterHookLine1Spanish, gJiminyRikuCharacterHookLine2Spanish, gJiminyRikuCharacterHookLine3Spanish,
    gJiminyRikuCharacterHookLine4Spanish, gJiminyRikuCharacterHookLine5Spanish, gJiminyRikuCharacterHookLine6Spanish,
};

const JiminyTextChar* gJiminyRikuHeartlessGuardArmorLines[7] = {
    gJiminyRikuHeartlessGuardArmorLine0, gJiminyRikuHeartlessGuardArmorLine1, gJiminyRikuHeartlessGuardArmorLine2, gJiminyRikuHeartlessGuardArmorLine3,
    gJiminyRikuHeartlessGuardArmorLine4, gJiminyRikuHeartlessGuardArmorLine5, gJiminyRikuHeartlessGuardArmorLine6,
};

const JiminyTextChar* gJiminyRikuHeartlessGuardArmorLinesFrench[7] = {
    gJiminyRikuHeartlessGuardArmorLine0French, gJiminyRikuHeartlessGuardArmorLine1French, gJiminyRikuHeartlessGuardArmorLine2French, gJiminyRikuHeartlessGuardArmorLine3French,
    gJiminyRikuHeartlessGuardArmorLine4French, gJiminyRikuHeartlessGuardArmorLine5French, gJiminyRikuHeartlessGuardArmorLine6French,
};

const JiminyTextChar* gJiminyRikuHeartlessGuardArmorLinesGerman[8] = {
    gJiminyRikuHeartlessGuardArmorLine0German, gJiminyRikuHeartlessGuardArmorLine1German, gJiminyRikuHeartlessGuardArmorLine2German, gJiminyRikuHeartlessGuardArmorLine3German,
    gJiminyRikuHeartlessGuardArmorLine4German, gJiminyRikuHeartlessGuardArmorLine5German, gJiminyRikuHeartlessGuardArmorLine6German, gJiminyRikuHeartlessGuardArmorLine7German,
};

const JiminyTextChar* gJiminyRikuHeartlessGuardArmorLinesItalian[7] = {
    gJiminyRikuHeartlessGuardArmorLine0Italian, gJiminyRikuHeartlessGuardArmorLine1Italian, gJiminyRikuHeartlessGuardArmorLine2Italian, gJiminyRikuHeartlessGuardArmorLine3Italian,
    gJiminyRikuHeartlessGuardArmorLine4Italian, gJiminyRikuHeartlessGuardArmorLine5Italian, gJiminyRikuHeartlessGuardArmorLine6Italian,
};

const JiminyTextChar* gJiminyRikuHeartlessGuardArmorLinesSpanish[7] = {
    gJiminyRikuHeartlessGuardArmorLine0Spanish, gJiminyRikuHeartlessGuardArmorLine1Spanish, gJiminyRikuHeartlessGuardArmorLine2Spanish, gJiminyRikuHeartlessGuardArmorLine3Spanish,
    gJiminyRikuHeartlessGuardArmorLine4Spanish, gJiminyRikuHeartlessGuardArmorLine5Spanish, gJiminyRikuHeartlessGuardArmorLine6Spanish,
};

const JiminyTextChar* gJiminyRikuHeartlessParasiteCageLines[7] = {
    gJiminyRikuHeartlessParasiteCageLine0, gJiminyRikuHeartlessParasiteCageLine1, gJiminyRikuHeartlessParasiteCageLine2, gJiminyRikuHeartlessParasiteCageLine3,
    gJiminyRikuHeartlessParasiteCageLine4, gJiminyRikuHeartlessParasiteCageLine5, gJiminyRikuHeartlessParasiteCageLine6,
};

const JiminyTextChar* gJiminyRikuHeartlessParasiteCageLinesFrench[7] = {
    gJiminyRikuHeartlessParasiteCageLine0French, gJiminyRikuHeartlessParasiteCageLine1French, gJiminyRikuHeartlessParasiteCageLine2French, gJiminyRikuHeartlessParasiteCageLine3French,
    gJiminyRikuHeartlessParasiteCageLine4French, gJiminyRikuHeartlessParasiteCageLine5French, gJiminyRikuHeartlessParasiteCageLine6French,
};

const JiminyTextChar* gJiminyRikuHeartlessParasiteCageLinesGerman[7] = {
    gJiminyRikuHeartlessParasiteCageLine0German, gJiminyRikuHeartlessParasiteCageLine1German, gJiminyRikuHeartlessParasiteCageLine2German, gJiminyRikuHeartlessParasiteCageLine3German,
    gJiminyRikuHeartlessParasiteCageLine4German, gJiminyRikuHeartlessParasiteCageLine5German, gJiminyRikuHeartlessParasiteCageLine6German,
};

const JiminyTextChar* gJiminyRikuHeartlessParasiteCageLinesItalian[7] = {
    gJiminyRikuHeartlessParasiteCageLine0Italian, gJiminyRikuHeartlessParasiteCageLine1Italian, gJiminyRikuHeartlessParasiteCageLine2Italian, gJiminyRikuHeartlessParasiteCageLine3Italian,
    gJiminyRikuHeartlessParasiteCageLine4Italian, gJiminyRikuHeartlessParasiteCageLine5Italian, gJiminyRikuHeartlessParasiteCageLine6Italian,
};

const JiminyTextChar* gJiminyRikuHeartlessParasiteCageLinesSpanish[8] = {
    gJiminyRikuHeartlessParasiteCageLine0Spanish, gJiminyRikuHeartlessParasiteCageLine1Spanish, gJiminyRikuHeartlessParasiteCageLine2Spanish, gJiminyRikuHeartlessParasiteCageLine3Spanish,
    gJiminyRikuHeartlessParasiteCageLine4Spanish, gJiminyRikuHeartlessParasiteCageLine5Spanish, gJiminyRikuHeartlessParasiteCageLine6Spanish, gJiminyRikuHeartlessParasiteCageLine7Spanish,
};

const JiminyTextChar* gJiminyRikuHeartlessTrickmasterLines[8] = {
    gJiminyRikuHeartlessTrickmasterLine0, gJiminyRikuHeartlessTrickmasterLine1, gJiminyRikuHeartlessTrickmasterLine2, gJiminyRikuHeartlessTrickmasterLine3,
    gJiminyRikuHeartlessTrickmasterLine4, gJiminyRikuHeartlessTrickmasterLine5, gJiminyRikuHeartlessTrickmasterLine6, gJiminyRikuHeartlessTrickmasterLine7,
};

const JiminyTextChar* gJiminyRikuHeartlessTrickmasterLinesFrench[9] = {
    gJiminyRikuHeartlessTrickmasterLine0French, gJiminyRikuHeartlessTrickmasterLine1French, gJiminyRikuHeartlessTrickmasterLine2French, gJiminyRikuHeartlessTrickmasterLine3French,
    gJiminyRikuHeartlessTrickmasterLine4French, gJiminyRikuHeartlessTrickmasterLine5French, gJiminyRikuHeartlessTrickmasterLine6French, gJiminyRikuHeartlessTrickmasterLine7French,
    gJiminyRikuHeartlessTrickmasterLine8French,
};

const JiminyTextChar* gJiminyRikuHeartlessTrickmasterLinesGerman[8] = {
    gJiminyRikuHeartlessTrickmasterLine0German, gJiminyRikuHeartlessTrickmasterLine1German, gJiminyRikuHeartlessTrickmasterLine2German, gJiminyRikuHeartlessTrickmasterLine3German,
    gJiminyRikuHeartlessTrickmasterLine4German, gJiminyRikuHeartlessTrickmasterLine5German, gJiminyRikuHeartlessTrickmasterLine6German, gJiminyRikuHeartlessTrickmasterLine7German,
};

const JiminyTextChar* gJiminyRikuHeartlessTrickmasterLinesItalian[8] = {
    gJiminyRikuHeartlessTrickmasterLine0Italian, gJiminyRikuHeartlessTrickmasterLine1Italian, gJiminyRikuHeartlessTrickmasterLine2Italian, gJiminyRikuHeartlessTrickmasterLine3Italian,
    gJiminyRikuHeartlessTrickmasterLine4Italian, gJiminyRikuHeartlessTrickmasterLine5Italian, gJiminyRikuHeartlessTrickmasterLine6Italian, gJiminyRikuHeartlessTrickmasterLine7Italian,
};

const JiminyTextChar* gJiminyRikuHeartlessTrickmasterLinesSpanish[8] = {
    gJiminyRikuHeartlessTrickmasterLine0Spanish, gJiminyRikuHeartlessTrickmasterLine1Spanish, gJiminyRikuHeartlessTrickmasterLine2Spanish, gJiminyRikuHeartlessTrickmasterLine3Spanish,
    gJiminyRikuHeartlessTrickmasterLine4Spanish, gJiminyRikuHeartlessTrickmasterLine5Spanish, gJiminyRikuHeartlessTrickmasterLine6Spanish, gJiminyRikuHeartlessTrickmasterLine7Spanish,
};

const JiminyTextChar* gJiminyRikuHeartlessDarksideLines[8] = {
    gJiminyRikuHeartlessDarksideLine0, gJiminyRikuHeartlessDarksideLine1, gJiminyRikuHeartlessDarksideLine2, gJiminyRikuHeartlessDarksideLine3,
    gJiminyRikuHeartlessDarksideLine4, gJiminyRikuHeartlessDarksideLine5, gJiminyRikuHeartlessDarksideLine6, gJiminyRikuHeartlessDarksideLine7,
};

const JiminyTextChar* gJiminyRikuHeartlessDarksideLinesFrench[10] = {
    gJiminyRikuHeartlessDarksideLine0French, gJiminyRikuHeartlessDarksideLine1French, gJiminyRikuHeartlessDarksideLine2French, gJiminyRikuHeartlessDarksideLine3French,
    gJiminyRikuHeartlessDarksideLine4French, gJiminyRikuHeartlessDarksideLine5French, gJiminyRikuHeartlessDarksideLine6French, gJiminyRikuHeartlessDarksideLine7French,
    gJiminyRikuHeartlessDarksideLine8French, gJiminyRikuHeartlessDarksideLine9French,
};

const JiminyTextChar* gJiminyRikuHeartlessDarksideLinesGerman[9] = {
    gJiminyRikuHeartlessDarksideLine0German, gJiminyRikuHeartlessDarksideLine1German, gJiminyRikuHeartlessDarksideLine2German, gJiminyRikuHeartlessDarksideLine3German,
    gJiminyRikuHeartlessDarksideLine4German, gJiminyRikuHeartlessDarksideLine5German, gJiminyRikuHeartlessDarksideLine6German, gJiminyRikuHeartlessDarksideLine7German,
    gJiminyRikuHeartlessDarksideLine8German,
};

const JiminyTextChar* gJiminyRikuHeartlessDarksideLinesItalian[8] = {
    gJiminyRikuHeartlessDarksideLine0Italian, gJiminyRikuHeartlessDarksideLine1Italian, gJiminyRikuHeartlessDarksideLine2Italian, gJiminyRikuHeartlessDarksideLine3Italian,
    gJiminyRikuHeartlessDarksideLine4Italian, gJiminyRikuHeartlessDarksideLine5Italian, gJiminyRikuHeartlessDarksideLine6Italian, gJiminyRikuHeartlessDarksideLine7Italian,
};

const JiminyTextChar* gJiminyRikuHeartlessDarksideLinesSpanish[10] = {
    gJiminyRikuHeartlessDarksideLine0Spanish, gJiminyRikuHeartlessDarksideLine1Spanish, gJiminyRikuHeartlessDarksideLine2Spanish, gJiminyRikuHeartlessDarksideLine3Spanish,
    gJiminyRikuHeartlessDarksideLine4Spanish, gJiminyRikuHeartlessDarksideLine5Spanish, gJiminyRikuHeartlessDarksideLine6Spanish, gJiminyRikuHeartlessDarksideLine7Spanish,
    gJiminyRikuHeartlessDarksideLine8Spanish, gJiminyRikuHeartlessDarksideLine9Spanish,
};

const JiminyLocalizedName* gJiminyRootNames[3] = {
    &gJiminyMenuStoryNameByLanguage, &gJiminyMenuCardIndexNameByLanguage, &gJiminyMenuCharactersNameByLanguage,
};

const JiminyLocalizedName* gJiminyEntry01Names[17] = {
    &gJiminyStoryTale1NameByLanguage, &gJiminyStoryTale2NameByLanguage, &gJiminyStoryTale3NameByLanguage, &gJiminyStoryTale4NameByLanguage,
    &gWorldNameTraverseTownByLanguage, &gJiminyStoryWonderlandNameByLanguage, &gWorldNameOlympusColiseumByLanguage, &gWorldNameAgrabahByLanguage,
    &gWorldNameHalloweenTownByLanguage, &gWorldNameMonstroByLanguage, &gWorldNameAtlanticaByLanguage, &gWorldNameNeverLandByLanguage,
    &gWorldNameHollowBastionByLanguage, &gJiminyStory100AcreWoodNameByLanguage, &gWorldNameTwilightTownByLanguage, &gWorldNameDestinyIslandsByLanguage,
    &gJiminyStoryCastleOblivionNameByLanguage,
};

const JiminyLocalizedName* gJiminyEntry02Names[7] = {
    &gJiminyMenuAttackCardsNameByLanguage, &gJiminyMenuMagicCardsNameByLanguage, &gJiminyMenuItemCardsNameByLanguage, &gJiminyMenuFriendCardsNameByLanguage,
    &gJiminyMenuEnemyCardsNameByLanguage, &gJiminyMenuMapCardsNameByLanguage, &gJiminyMenuPremiumCardsNameByLanguage,
};

const JiminyLocalizedName* gJiminyEntry03Names[3] = {
    &gJiminyMenuCharacters1NameByLanguage, &gJiminyMenuCharacters2NameByLanguage, &gJiminyMenuHeartlessNameByLanguage,
};

const JiminyLocalizedName* gJiminyEntry04Names[17] = {
    &gCardNameKingdomKeyByLanguage, &gCardNameThreeWishesByLanguage, &gCardNameCrabclawByLanguage, &gCardNamePumpkinheadByLanguage,
    &gCardNameFairyHarpByLanguage, &gCardNameWishingStarByLanguage, &gCardNameSpellbinderByLanguage, &gCardNameMetalChocoboByLanguage,
    &gCardNameOlympiaByLanguage, &gCardNameLionheartByLanguage, &gCardNameLadyLuckByLanguage, &gCardNameDivineRoseByLanguage,
    &gCardNameOathkeeperByLanguage, &gCardNameOblivionByLanguage, &gCardNameDiamondDustByLanguage, &gCardNameOneWingedAngelByLanguage,
    &gCardNameUltimaWeaponByLanguage,
};

const JiminyLocalizedName* gJiminyEntry05Names[14] = {
    &gCardNameFireByLanguage, &gCardNameBlizzardByLanguage, &gCardNameThunderByLanguage, &gCardNameCureByLanguage,
    &gCardNameGravityByLanguage, &gCardNameStopByLanguage, &gCardNameAeroByLanguage, &gCardNameSimbaByLanguage,
    &gCardNameDumboByLanguage, &gCardNameBambiByLanguage, &gCardNameMushuByLanguage, &gCardNameGenieByLanguage,
    &gCardNameTinkerBellByLanguage, &gCardNameCloudByLanguage,
};

const JiminyLocalizedName* gJiminyEntry06Names[7] = {
    &gCardNamePotionByLanguage, &gCardNameHiPotionByLanguage, &gCardNameMegaPotionByLanguage, &gCardNameEtherByLanguage,
    &gCardNameMegaEtherByLanguage, &gCardNameElixirByLanguage, &gCardNameMegalixirByLanguage,
};

const JiminyLocalizedName* gJiminyEntry07Names[7] = {
    &gCardNameDonaldDuckByLanguage, &gCardNameGoofyByLanguage, &gCardNameAladdinByLanguage, &gCardNameJackByLanguage,
    &gCardNameArielByLanguage, &gCardNamePeterPanByLanguage, &gCardNameBeastByLanguage,
};

const JiminyLocalizedName* gJiminyEntry08Names[49] = {
    &gEnemyNameShadowByLanguage, &gEnemyNameSoldierByLanguage, &gEnemyNameLargeBodyByLanguage, &gEnemyNameRedNocturneByLanguage,
    &gEnemyNameBlueRhapsodyByLanguage, &gEnemyNameYellowOperaByLanguage, &gEnemyNameGreenRequiemByLanguage, &gEnemyNamePowerwildByLanguage,
    &gEnemyNameBouncywildByLanguage, &gEnemyNameAirSoldierByLanguage, &gEnemyNameBanditByLanguage, &gEnemyNameFatBanditByLanguage,
    &gEnemyNameBarrelSpiderByLanguage, &gEnemyNameSearchGhostByLanguage, &gEnemyNameSeaNeonByLanguage, &gEnemyNameScrewdiverByLanguage,
    &gEnemyNameAquatankByLanguage, &gEnemyNameWightKnightByLanguage, &gEnemyNameGargoyleByLanguage, &gEnemyNamePirateByLanguage,
    &gEnemyNameAirPirateByLanguage, &gEnemyNameDarkballByLanguage, &gEnemyNameDefenderByLanguage, &gEnemyNameWyvernByLanguage,
    &gEnemyNameWizardByLanguage, &gEnemyNameNeoshadowByLanguage, &gEnemyNameWhiteMushroomByLanguage, &gEnemyNameBlackFungusByLanguage,
    &gEnemyNameCreeperPlantByLanguage, &gEnemyNameTornadoStepByLanguage, &gEnemyNameCrescendoByLanguage, &gEnemyNameGuardArmorByLanguage,
    &gEnemyNameParasiteCageByLanguage, &gEnemyNameTrickmasterByLanguage, &gEnemyNameDarksideByLanguage, &gEnemyNameCardSoldierByLanguage,
    &gEnemyNameHadesByLanguage, &gEnemyNameJafarByLanguage, &gEnemyNameOogieBoogieByLanguage, &gEnemyNameUrsulaByLanguage,
    &gEnemyNameHookByLanguage, &gEnemyNameDragonMaleficentByLanguage, &gEnemyNameRikuByLanguage, &gEnemyNameAxelByLanguage,
    &gEnemyNameLarxeneByLanguage, &gEnemyNameVexenByLanguage, &gEnemyNameMarluxiaByLanguage, &gEnemyNameLexaeusByLanguage,
    &gEnemyNameAnsemByLanguage,
};

const JiminyLocalizedName* gJiminyEntry09Names[26] = {
    &gRoomNameTranquilDarknessByLanguage, &gJiminyMapCardTeemingDarknessNameByLanguage, &gRoomNameFeebleDarknessByLanguage, &gJiminyMapCardAlmightyDarknessNameByLanguage,
    &gRoomNameSleepingDarknessByLanguage, &gJiminyMapCardLoomingDarknessNameByLanguage, &gRoomNamePremiumRoomByLanguage, &gRoomNameWhiteRoomByLanguage,
    &gRoomNameBlackRoomByLanguage, &gRoomNameMartialWakingByLanguage, &gRoomNameSorcerousWakingByLanguage, &gJiminyMapCardAlchemicWakingNameByLanguage,
    &gJiminyMapCardMeetingGroundNameByLanguage, &gJiminyMapCardStagnantSpaceNameByLanguage, &gRoomNameStrongInitiativeByLanguage, &gJiminyMapCardLastingDazeNameByLanguage,
    &gRoomNameCalmBountyByLanguage, &gRoomNameGuardedTroveByLanguage, &gRoomNameFalseBountyByLanguage, &gRoomNameMomentsReprieveByLanguage,
    &gRoomNameMinglingWorldsByLanguage, &gRoomNameMoogleRoomByLanguage, &gJiminyMapCardKeyOfBeginningsNameByLanguage, &gJiminyMapCardKeyOfGuidanceNameByLanguage,
    &gJiminyMapCardKeyToTruthNameByLanguage, &gJiminyMapCardKeyToRewardsNameByLanguage,
};

const JiminyLocalizedName* gJiminyEntry10Names[1] = {
    &gJiminyPremiumCardsNameByLanguage,
};

const JiminyLocalizedName* gJiminyEntry11Names[25] = {
    &gCharacterNameSoraByLanguage, &gCardNameDonaldDuckByLanguage, &gCardNameGoofyByLanguage, &gCharacterNameJiminyCricketByLanguage,
    &gEnemyNameRikuByLanguage, &gCharacterNameKairiByLanguage, &gCardNameSimbaByLanguage, &gCardNameDumboByLanguage,
    &gCardNameBambiByLanguage, &gCardNameMushuByLanguage, &gCharacterNameMooglesByLanguage, &gCharacterNameLeonByLanguage,
    &gCharacterNameYuffieByLanguage, &gCharacterNameAerithByLanguage, &gCharacterNameCidByLanguage, &gCardNameCloudByLanguage,
    &gCharacterNameTidusByLanguage, &gCharacterNameWakkaByLanguage, &gCharacterNameSelphieByLanguage, &gCharacterNameNamineByLanguage,
    &gCharacterNameRikuReplicaByLanguage, &gEnemyNameAxelByLanguage, &gEnemyNameLarxeneByLanguage, &gEnemyNameVexenByLanguage,
    &gEnemyNameMarluxiaByLanguage,
};

const JiminyLocalizedName* gJiminyEntry12Names[40] = {
    &gCharacterNameAliceByLanguage, &gCharacterNameQueenOfHeartsByLanguage, &gCharacterNameWhiteRabbitByLanguage, &gCharacterNameCardOfHeartsByLanguage,
    &gCharacterNameCardOfSpadesByLanguage, &gCharacterNameCheshireCatByLanguage, &gCharacterNameHerculesByLanguage, &gCharacterNamePhiloctetesByLanguage,
    &gEnemyNameHadesByLanguage, &gCardNameAladdinByLanguage, &gCardNameGenieByLanguage, &gCharacterNameJasmineByLanguage,
    &gCharacterNameIagoByLanguage, &gEnemyNameJafarByLanguage, &gCharacterNameJafarGenieByLanguage, &gCardNameJackByLanguage,
    &gCharacterNameSallyByLanguage, &gCharacterNameDrFinkelsteinByLanguage, &gEnemyNameOogieBoogieByLanguage, &gCharacterNamePinocchioByLanguage,
    &gCharacterNameGeppettoByLanguage, &gCardNameArielByLanguage, &gCharacterNameSebastianByLanguage, &gCharacterNameFlounderByLanguage,
    &gEnemyNameUrsulaByLanguage, &gCardNamePeterPanByLanguage, &gCardNameTinkerBellByLanguage, &gCharacterNameWendyByLanguage,
    &gCharacterNameHookByLanguage, &gCardNameBeastByLanguage, &gCharacterNameBelleByLanguage, &gCharacterNameMaleficentByLanguage,
    &gEnemyNameDragonMaleficentByLanguage, &gCharacterNameWinnieThePoohByLanguage, &gCharacterNamePigletByLanguage, &gCharacterNameOwlByLanguage,
    &gCharacterNameRooByLanguage, &gCharacterNameEeyoreByLanguage, &gCharacterNameTiggerByLanguage, &gCharacterNameRabbitByLanguage,
};

const JiminyLocalizedName* gJiminyEntry13Names[35] = {
    &gEnemyNameShadowByLanguage, &gEnemyNameSoldierByLanguage, &gEnemyNameLargeBodyByLanguage, &gEnemyNameRedNocturneByLanguage,
    &gEnemyNameBlueRhapsodyByLanguage, &gEnemyNameYellowOperaByLanguage, &gEnemyNameGreenRequiemByLanguage, &gEnemyNamePowerwildByLanguage,
    &gEnemyNameBouncywildByLanguage, &gEnemyNameAirSoldierByLanguage, &gEnemyNameBanditByLanguage, &gEnemyNameFatBanditByLanguage,
    &gEnemyNameBarrelSpiderByLanguage, &gEnemyNameSearchGhostByLanguage, &gEnemyNameSeaNeonByLanguage, &gEnemyNameScrewdiverByLanguage,
    &gEnemyNameAquatankByLanguage, &gEnemyNameWightKnightByLanguage, &gEnemyNameGargoyleByLanguage, &gEnemyNamePirateByLanguage,
    &gEnemyNameAirPirateByLanguage, &gEnemyNameDarkballByLanguage, &gEnemyNameDefenderByLanguage, &gEnemyNameWyvernByLanguage,
    &gEnemyNameWizardByLanguage, &gEnemyNameNeoshadowByLanguage, &gEnemyNameWhiteMushroomByLanguage, &gEnemyNameBlackFungusByLanguage,
    &gEnemyNameCreeperPlantByLanguage, &gEnemyNameTornadoStepByLanguage, &gEnemyNameCrescendoByLanguage, &gEnemyNameGuardArmorByLanguage,
    &gEnemyNameParasiteCageByLanguage, &gEnemyNameTrickmasterByLanguage, &gEnemyNameDarksideByLanguage,
};

const JiminyLocalizedName* gJiminyEntry15Names[6] = {
    &gJiminyRikuStoryTale1NameByLanguage, &gJiminyRikuStoryTale2NameByLanguage, &gJiminyRikuStoryTale3NameByLanguage, &gJiminyRikuStoryTale4NameByLanguage,
    &gJiminyRikuStoryTale5NameByLanguage, &gJiminyRikuStoryTale6NameByLanguage,
};

const JiminyLocalizedName* gJiminyEntry18Names[14] = {
    &gEnemyNameRikuByLanguage, &gCardNameKingByLanguage, &gCharacterNameSoraByLanguage, &gCharacterNameKairiByLanguage,
    &gCharacterNameNamineByLanguage, &gCharacterNameRikuReplicaByLanguage, &gEnemyNameAnsemByLanguage, &gEnemyNameVexenByLanguage,
    &gEnemyNameLexaeusByLanguage, &gCharacterNameZexionByLanguage, &gEnemyNameAxelByLanguage, &gEnemyNameMarluxiaByLanguage,
    &gEnemyNameLarxeneByLanguage, &gCharacterNameDiZByLanguage,
};

const JiminyLocalizedName* gJiminyEntry19Names[6] = {
    &gCharacterNameMaleficentByLanguage, &gCharacterNameJafarGenieByLanguage, &gEnemyNameUrsulaByLanguage, &gEnemyNameHadesByLanguage,
    &gEnemyNameOogieBoogieByLanguage, &gCharacterNameHookByLanguage,
};

const JiminyLocalizedName* gJiminyEntry20Names[33] = {
    &gEnemyNameShadowByLanguage, &gEnemyNameSoldierByLanguage, &gEnemyNameLargeBodyByLanguage, &gEnemyNameRedNocturneByLanguage,
    &gEnemyNameBlueRhapsodyByLanguage, &gEnemyNameYellowOperaByLanguage, &gEnemyNameGreenRequiemByLanguage, &gEnemyNamePowerwildByLanguage,
    &gEnemyNameBouncywildByLanguage, &gEnemyNameAirSoldierByLanguage, &gEnemyNameBanditByLanguage, &gEnemyNameFatBanditByLanguage,
    &gEnemyNameBarrelSpiderByLanguage, &gEnemyNameSearchGhostByLanguage, &gEnemyNameSeaNeonByLanguage, &gEnemyNameScrewdiverByLanguage,
    &gEnemyNameAquatankByLanguage, &gEnemyNameWightKnightByLanguage, &gEnemyNameGargoyleByLanguage, &gEnemyNamePirateByLanguage,
    &gEnemyNameAirPirateByLanguage, &gEnemyNameDarkballByLanguage, &gEnemyNameDefenderByLanguage, &gEnemyNameWyvernByLanguage,
    &gEnemyNameWizardByLanguage, &gEnemyNameNeoshadowByLanguage, &gEnemyNameCreeperPlantByLanguage, &gEnemyNameTornadoStepByLanguage,
    &gEnemyNameCrescendoByLanguage, &gEnemyNameGuardArmorByLanguage, &gEnemyNameParasiteCageByLanguage, &gEnemyNameTrickmasterByLanguage,
    &gEnemyNameDarksideByLanguage,
};

const JiminyLocalizedName* gJiminyEntry16Names[22] = {
    &gCardNameSoulEaterByLanguage, &gCardNameKingByLanguage, &gEnemyNameShadowByLanguage, &gEnemyNameLargeBodyByLanguage,
    &gEnemyNamePowerwildByLanguage, &gEnemyNameFatBanditByLanguage, &gEnemyNameSearchGhostByLanguage, &gEnemyNameSeaNeonByLanguage,
    &gEnemyNameWightKnightByLanguage, &gEnemyNamePirateByLanguage, &gEnemyNameDefenderByLanguage, &gEnemyNameGuardArmorByLanguage,
    &gEnemyNameParasiteCageByLanguage, &gEnemyNameTrickmasterByLanguage, &gEnemyNameDarksideByLanguage, &gEnemyNameHadesByLanguage,
    &gEnemyNameJafarByLanguage, &gEnemyNameOogieBoogieByLanguage, &gEnemyNameUrsulaByLanguage, &gEnemyNameHookByLanguage,
    &gEnemyNameDragonMaleficentByLanguage, &gEnemyNameLexaeusByLanguage,
};

const JiminyTextChar* gJiminyHiddenTexts[13] = {
    gJiminyHiddenText0, gJiminyHiddenText1, gJiminyHiddenText2, gJiminyHiddenText3,
    gJiminyHiddenText4, gJiminyHiddenText5, gJiminyHiddenText6, gJiminyHiddenText7,
    gJiminyHiddenText8, gJiminyHiddenText9, gJiminyHiddenText10, gJiminyHiddenText11,
    gJiminyHiddenText12,
};

#endif
