/**
 * mode_wlogo.c
 * World Logo Screen
 */

#include "mode_wlogo.h"
#include "registration_data.h"
#include "monsgage.h"
#include "jiminy_data.h"
#include "gba/keys.h"
#include "battle_backgrounds.h"
#include "link_menus.h"
#include "fade.h"
#include "common_text.h"
#include "display.h"
#include "jiminy_inline_text_data.h"
#include "key.h"
#include "map_api.h"
#include "mode.h"
#include "obj_api.h"
#include "poo_api.h"
#include <stddef.h>
#include "taskpool.h"
#include "text.h"
#include "text_types.h"
#include "types.h"
#include "obj.h"
#include "sprite_palettes.h"
#include "world_types.h"
#include "engine_math.h"
#include "gba/io_reg.h"

static u8* sWorldNames[13] = {
#if defined(VERSION_US)
    (u8*)gWorldNameWonderland,
    (u8*)gWorldNameMonstro,
    (u8*)gWorldNameHalloweenTown,
    (u8*)gWorldNameAtlantica,
    (u8*)gWorldNameNeverLand,
    (u8*)gWorldNameOlympusColiseum,
    (u8*)gWorldNameHollowBastion,
    (u8*)gWorldNameDestinyIslands,
    (u8*)gWorldNameAgrabah,
    (u8*)gWorldNameTraverseTown,
    (u8*)gWorldName100AcreWood,
    (u8*)gWorldNameTwilightTown,
    (u8*)gWorldNameCastleOblivion,
#elif defined(VERSION_JP)
    gWorldNameWonderland,
    gWorldNameMonstro,
    gWorldNameHalloweenTown,
    gWorldNameAtlantica,
    gWorldNameNeverLand,
    gWorldNameOlympusColiseum,
    gWorldNameHollowBastion,
    gWorldNameDestinyIslands,
    gWorldNameAgrabah,
    gWorldNameTraverseTown,
    gWorldName100AcreWood,
    gWorldNameTwilightTown,
    gWorldNameCastleOblivion,
#elif defined(VERSION_EU)
    (u8*)&gWorldNameWonderlandByLanguage,
    (u8*)&gWorldNameMonstroByLanguage,
    (u8*)&gWorldNameHalloweenTownByLanguage,
    (u8*)&gWorldNameAtlanticaByLanguage,
    (u8*)&gWorldNameNeverLandByLanguage,
    (u8*)&gWorldNameOlympusColiseumByLanguage,
    (u8*)&gWorldNameHollowBastionByLanguage,
    (u8*)&gWorldNameDestinyIslandsByLanguage,
    (u8*)&gWorldNameAgrabahByLanguage,
    (u8*)&gWorldNameTraverseTownByLanguage,
    (u8*)&gWorldName100AcreWoodByLanguage,
    (u8*)&gWorldNameTwilightTownByLanguage,
    (u8*)&gWorldNameCastleOblivionByLanguage,
#endif
};

static u8 sWLogoWorldIds[13] = {
    WORLD_WONDERLAND,
    WORLD_MONSTRO,
    WORLD_HALLOWEEN_TOWN,
    WORLD_ATLANTICA,
    WORLD_NEVER_LAND,
    WORLD_OLYMPUS_COLISEUM,
    WORLD_HOLLOW_BASTION,
    WORLD_DESTINY_ISLANDS,
    WORLD_AGRABAH,
    WORLD_TRAVERSE_TOWN,
    0,
    WORLD_TWILIGHT_TOWN,
    WORLD_CASTLE_OBLIVION,
};

enum WLogoModeState {
    WLOGO_MODE_STATE_SELECT,
    WLOGO_MODE_STATE_START,
    WLOGO_MODE_STATE_PLAY,
    WLOGO_MODE_STATE_RESTART
};

static u8 sWLogoState;
static s8 sWLogoWorld;
static u8 sWLogoTimer;
static u8 sWLogoNameLength;
#ifdef VERSION_EU
static TextSlot sWLogoNameSlots[80];
#else
static TextSlot sWLogoNameSlots[20];
#endif
static struct ObjPalette* sWLogoNamePalette;
static TaskPool sModeWLogoTasks;
static Task* sModeWLogoTask;
static TaskPool sTaskWLogoTasks;
static Task* sTaskWLogoTask;

void mode_wLogo_0(s32 arg) {
    sWLogoWorld = arg;
    WLogoInitWorldSelect();
}

void mode_wLogo_1() {
    u8* lengthPtr;

    switch (sWLogoState) {
    case WLOGO_MODE_STATE_SELECT:
        DrawTextSlots(35, 75, sWLogoNameSlots, sWLogoNamePalette, 20, sWLogoNameLength);

        if (GetKeysPressed() & DPAD_LEFT) {
            sWLogoWorld--;

            if (sWLogoWorld < 0) {
                sWLogoWorld = WORLD_CASTLE_OBLIVION;
            }

#ifdef VERSION_EU
            sWLogoNameLength = LoadTextSlots(GetLocalizedString(sWorldNames[sWLogoWorld]), sWLogoNameSlots);
#else
            sWLogoNameLength = LoadTextSlots(sWorldNames[sWLogoWorld], sWLogoNameSlots);
#endif
        }

        if (GetKeysPressed() & DPAD_RIGHT) {
            sWLogoWorld++;

            if (sWLogoWorld > WORLD_CASTLE_OBLIVION) {
                sWLogoWorld = 0;
            }

            lengthPtr = &sWLogoNameLength;
#ifdef VERSION_EU
            *lengthPtr = LoadTextSlots(GetLocalizedString(sWorldNames[sWLogoWorld]), sWLogoNameSlots);
#else
            *lengthPtr = LoadTextSlots(sWorldNames[sWLogoWorld], sWLogoNameSlots);
#endif
        }

        if (GetKeysPressed() & A_BUTTON) {
            FadeStartOut(FADE_MODE_BLACK, 16);
            DisableBg(0);
            DisableBg(1);
            sWLogoState++;
        }

        if (GetKeysPressed() & B_BUTTON) {
            ModeRequest(&gModeDebug, 0);
        }

        break;
    case WLOGO_MODE_STATE_START:
        WLogoStartLogo(sWLogoWorldIds[sWLogoWorld]);
        sWLogoState++;
        break;
    case WLOGO_MODE_STATE_PLAY:
        if (IsTaskActive(sModeWLogoTask)) {
            TaskPoolUpdate(&sModeWLogoTasks);
            TaskPoolDraw(&sModeWLogoTasks);
        } else {
            sWLogoState++;
        }

        break;
    case WLOGO_MODE_STATE_RESTART:
        sWLogoTimer++;

        if (sWLogoTimer > 10) {
            ModeRequest(&gModeWLogo, sWLogoWorld);
        }

        break;
    }
}

void mode_wLogo_2() {
    FreeTextSlots(sWLogoNameSlots, 20);
    ReleaseObjPalette(sWLogoNamePalette);

    if (sWLogoState != WLOGO_MODE_STATE_SELECT) {
        if (sWLogoState == WLOGO_MODE_STATE_RESTART) {
            TaskPoolDestroy(&sModeWLogoTasks);
        }
    }
}

void WLogoInitWorldSelect() {
    u8* lengthPtr;
    FadeStartIn(FADE_MODE_BLACK, 16);
    SetBgMode0();
    SetupBg(1, 2, 31, 0);
    SetBgSize(1, BGCNT_TXT256x256);
    LoadBgTiles(1, gSioBgTiles, sizeof(gSioBgTiles));
    LoadBgPalette(1, gSioBgPalettes, sizeof(gSioBgPalettes));
    LoadBgMap(1, gSioBattleBgMap, sizeof(gSioBattleBgMap));
    DisableBg(0);
    EnableBg(1);
    sWLogoState = WLOGO_MODE_STATE_SELECT;
    sWLogoTimer = 0;
    InitTextSlots(sWLogoNameSlots, 20);
    lengthPtr = &sWLogoNameLength;
#ifdef VERSION_EU
    *lengthPtr = LoadTextSlots(GetLocalizedString(sWorldNames[sWLogoWorld]), sWLogoNameSlots);
#else
    *lengthPtr = LoadTextSlots(sWorldNames[sWLogoWorld], sWLogoNameSlots);
#endif
    sWLogoNamePalette = LoadObjPalette(gNameTextPalettes[0], sizeof(gNameTextPalettes[0]));
}

void WLogoStartLogo(u8 world) {
    FadeStartIn(FADE_MODE_BLACK, 16);
    SetBgMode1();
    SetupBg(0, 0, 7, 14);
    SetBgPriority(0, 0);
    SetBgOverflow(0, TRUE);
    SetBgSize(0, BGCNT_TXT256x256);
    SetupBg(2, 2, 24, 0);
    SetBgPriority(2, 2);
    SetBgOverflow(2, TRUE);
    SetBgSize(2, BGCNT_AFF512x512);
    TaskPoolInit(&sModeWLogoTasks, 2);

    switch (world) {
    case WORLD_WONDERLAND:
        LoadBgTiles(2, gBtlBgWonderlandTiles, sizeof(gBtlBgWonderlandTiles));
        LoadBgPalette(2, gBtlBgWonderlandPalette, sizeof(gBtlBgWonderlandPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgWonderlandMap);
#else
        LoadBgMap(2, gBtlBgWonderlandMap, sizeof(gBtlBgWonderlandMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoWon, NULL);
        break;
    case WORLD_MONSTRO:
        LoadBgTiles(2, gBtlBgMonstroTiles, sizeof(gBtlBgMonstroTiles));
        LoadBgPalette(2, gBtlBgMonstroPalette, sizeof(gBtlBgMonstroPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgMonstroMap);
#else
        LoadBgMap(2, gBtlBgMonstroMap, sizeof(gBtlBgMonstroMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoMons, NULL);
        break;
    case WORLD_HALLOWEEN_TOWN:
        LoadBgTiles(2, gBtlBgHalloweenTownTiles, sizeof(gBtlBgHalloweenTownTiles));
        LoadBgPalette(2, gBtlBgHalloweenTownPalette, sizeof(gBtlBgHalloweenTownPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgHalloweenTownMap);
#else
        LoadBgMap(2, gBtlBgHalloweenTownMap, sizeof(gBtlBgHalloweenTownMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoHwt, NULL);
        break;
    case WORLD_ATLANTICA:
        LoadBgTiles(2, gBtlBgAtlanticaTiles, sizeof(gBtlBgAtlanticaTiles));
        LoadBgPalette(2, gBtlBgAtlanticaPalette, sizeof(gBtlBgAtlanticaPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgAtlanticaMap);
#else
        LoadBgMap(2, gBtlBgAtlanticaMap, sizeof(gBtlBgAtlanticaMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoAtl, NULL);
        break;
    case WORLD_NEVER_LAND:
        LoadBgTiles(2, gBtlBgNeverLandTiles, sizeof(gBtlBgNeverLandTiles));
        LoadBgPalette(2, gBtlBgNeverLandPalette, sizeof(gBtlBgNeverLandPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgNeverLandMap);
#else
        LoadBgMap(2, gBtlBgNeverLandMap, sizeof(gBtlBgNeverLandMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoNvl, NULL);
        break;
    case WORLD_OLYMPUS_COLISEUM:
        LoadBgTiles(2, gBtlBgOlympusColiseumTiles, sizeof(gBtlBgOlympusColiseumTiles));
        LoadBgPalette(2, gBtlBgOlympusColiseumPalette, sizeof(gBtlBgOlympusColiseumPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgOlympusColiseumMap);
#else
        LoadBgMap(2, gBtlBgOlympusColiseumMap, sizeof(gBtlBgOlympusColiseumMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoCol, NULL);
        break;
    case WORLD_HOLLOW_BASTION:
        LoadBgTiles(2, gBtlBgHollowBastionTiles, sizeof(gBtlBgHollowBastionTiles));
        LoadBgPalette(2, gBtlBgHollowBastionPalette, sizeof(gBtlBgHollowBastionPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgHollowBastionMap);
#else
        LoadBgMap(2, gBtlBgHollowBastionMap, sizeof(gBtlBgHollowBastionMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoHlw, NULL);
        break;
    case WORLD_DESTINY_ISLANDS:
        LoadBgTiles(2, gBtlBgDestinyIslandsTiles, sizeof(gBtlBgDestinyIslandsTiles));
        LoadBgPalette(2, gBtlBgDestinyIslandsPalette, sizeof(gBtlBgDestinyIslandsPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgDestinyIslandsMap);
#else
        LoadBgMap(2, gBtlBgDestinyIslandsMap, sizeof(gBtlBgDestinyIslandsMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoDil, NULL);
        break;
    case WORLD_AGRABAH:
        LoadBgTiles(2, gBtlBgAgrabahTiles, sizeof(gBtlBgAgrabahTiles));
        LoadBgPalette(2, gBtlBgAgrabahPalette, sizeof(gBtlBgAgrabahPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgAgrabahMap);
#else
        LoadBgMap(2, gBtlBgAgrabahMap, sizeof(gBtlBgAgrabahMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoAgr, NULL);
        break;
    case WORLD_TRAVERSE_TOWN:
        LoadBgTiles(2, gBtlBgTraverseTownTiles, sizeof(gBtlBgTraverseTownTiles));
        LoadBgPalette(2, gBtlBgTraverseTownPalette, sizeof(gBtlBgTraverseTownPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgTraverseTownMap);
#else
        LoadBgMap(2, gBtlBgTraverseTownMap, sizeof(gBtlBgTraverseTownMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoTvt, NULL);
        break;
    case 0:
        LoadBgTiles(2, gBtlBgWonderlandTiles, sizeof(gBtlBgWonderlandTiles));
        LoadBgPalette(2, gBtlBgWonderlandPalette, sizeof(gBtlBgWonderlandPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgWonderlandMap);
#else
        LoadBgMap(2, gBtlBgWonderlandMap, sizeof(gBtlBgWonderlandMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoPoo, NULL);
        break;
    case WORLD_TWILIGHT_TOWN:
        LoadBgTiles(2, gBtlBgTwilightTownTiles, sizeof(gBtlBgTwilightTownTiles));
        LoadBgPalette(2, gBtlBgTwilightTownPalette, sizeof(gBtlBgTwilightTownPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgTwilightTownMap);
#else
        LoadBgMap(2, gBtlBgTwilightTownMap, sizeof(gBtlBgTwilightTownMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoTt, NULL);
        break;
    case WORLD_CASTLE_OBLIVION:
        LoadBgTiles(2, gBtlBgCastleOblivionTiles, sizeof(gBtlBgCastleOblivionTiles));
        LoadBgPalette(2, gBtlBgCastleOblivionPalette, sizeof(gBtlBgCastleOblivionPalette));
#ifdef VERSION_EU
        LoadBgMapLz77(2, gBtlBgCastleOblivionMap);
#else
        LoadBgMap(2, gBtlBgCastleOblivionMap, sizeof(gBtlBgCastleOblivionMap));
#endif
        sModeWLogoTask = TaskCreate(&sModeWLogoTasks, &gTaskDescWlogoBks, NULL);
        break;
    }

    SetBgAffine(2, 0, Q_8_8(1), Q_8_8(1), 0x10000, 0x16800);
}

void task_wLogo_0(WLogoTaskWork* work, u8 world) {
    work->worldId = world;
    work->cameraOffsetY = -0x5A00;
    work->timer = 0;
    TaskPoolInit(&sTaskWLogoTasks, 2);

    switch (work->worldId) {
    case WORLD_WONDERLAND:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoWon, NULL);
        break;
    case WORLD_MONSTRO:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoMons, NULL);
        break;
    case WORLD_HALLOWEEN_TOWN:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoHwt, NULL);
        break;
    case WORLD_ATLANTICA:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoAtl, NULL);
        break;
    case WORLD_NEVER_LAND:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoNvl, NULL);
        break;
    case WORLD_OLYMPUS_COLISEUM:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoCol, NULL);
        break;
    case WORLD_HOLLOW_BASTION:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoHlw, NULL);
        break;
    case WORLD_AGRABAH:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoAgr, NULL);
        break;
    case WORLD_DESTINY_ISLANDS:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoDil, NULL);
        break;
    case WORLD_TRAVERSE_TOWN:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoTvt, NULL);
        break;
    case 0:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoPoo, NULL);
        break;
    case WORLD_TWILIGHT_TOWN:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoTt, NULL);
        break;
    case WORLD_CASTLE_OBLIVION:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoBks, NULL);
        break;
    default:
        sTaskWLogoTask = TaskCreate(&sTaskWLogoTasks, &gTaskDescWlogoWon, NULL);
        break;
    }

    if (work->worldId == 0) {
        MovePooCamera(0, work->cameraOffsetY);
    } else {
        MapMoveCameraTarget(0, work->cameraOffsetY);
    }
}

u8 task_wLogo_1(WLogoTaskWork* work) {
    if (work->worldId == 0) {
        work->timer++;

        if (work->timer <= 314) {
            MovePooCamera(0, 76);
        }
    } else {
        work->timer++;

        if (work->timer <= 314) {
            MapMoveCameraTarget(0, 76);
        }
    }

    if (IsTaskActive(sTaskWLogoTask)) {
        TaskPoolUpdate(&sTaskWLogoTasks);
        TaskPoolDraw(&sTaskWLogoTasks);
        return 1;
    }

    return 0;
}

void task_wLogo_2(WLogoTaskWork* work) {
}

void task_wLogo_3(WLogoTaskWork* work) {
    TaskPoolDestroy(&sTaskWLogoTasks);
    SetBgBlend(0, 0, 16);
}

Mode gModeWLogo = {
    "mode_wLogo",
    mode_wLogo_0,
    mode_wLogo_1,
    mode_wLogo_2,
};

TaskDesc gTaskDescWLogo = {
    "task_wLogo",
    (TaskInitFunc)task_wLogo_0,
    (TaskUpdateFunc)task_wLogo_1,
    (TaskDrawFunc)task_wLogo_2,
    (TaskDestroyFunc)task_wLogo_3,
    sizeof(WLogoTaskWork),
};
