/**
 * mode_dummy.c
 * Debug Placeholder Screen
 */

#include "map_api.h"
#include "mode_chkbtl.h"
#include "msg_api.h"
#include "display.h"
#include "mode_dummy.h"
#include "sprites_mode_debug.h"
#include "gba/keys.h"
#include "fade.h"
#include "game_state.h"
#include "key.h"
#include "map_runtime.h"
#include "mode.h"
#include "registration_data.h"
#include "system_state.h"
#include "types.h"
#include "debug_text.h"
#include "event_ids.h"
#include "mode_movie.h"
#include "macros.h"

static u16 sDummyEntryIndex;

static const DummyEntry sDummyEntries[10] = {
    { "\x83\x49\x81\x5b\x83\x76\x83\x6a\x83\x93\x83\x4f", "\x83\x80\x81\x5b\x83\x72\x81\x5b\x81\x40\x91\x90\x8c\xb4\x81\x60\x8f\xe9\x8a\x4f\x8a\xcf", 0 },
    { "\x82\x50\x8a\x4b", "\x83\x8f\x81\x5b\x83\x8b\x83\x68\x91\x49\x91\xf0\x83\x60\x83\x85\x81\x5b\x83\x67\x83\x8a\x83\x41\x83\x8b", 1 },
    { "\x83\x67\x83\x89\x83\x94\x83\x40\x81\x5b\x83\x58\x83\x5e\x83\x45\x83\x93", "\x83\x8b\x81\x5b\x83\x80\x83\x4e\x83\x8a\x83\x47\x83\x43\x83\x67\x83\x60\x83\x85\x81\x5b\x83\x67\x83\x8a\x83\x41\x83\x8b", 2 },
    { "\x83\x67\x83\x89\x83\x94\x83\x40\x81\x5b\x83\x58\x83\x5e\x83\x45\x83\x93", "\x83\x6f\x83\x67\x83\x8b\x83\x60\x83\x85\x81\x5b\x83\x67\x83\x8a\x83\x41\x83\x8b", 3 },
    { "\x82\x53\x8a\x4b", "\x83\x80\x81\x5b\x83\x72\x81\x5b\x82\xc8\x82\xa2\x82\xb5\x82\x50\x96\x87\x8a\x47", 4 },
    { "\x82\x55\x8a\x4b", "\x83\x80\x81\x5b\x83\x72\x81\x5b", 5 },
    { "\x82\x50\x82\x50\x8a\x4b", "\x83\x80\x81\x5b\x83\x72\x81\x5b\x82\xc8\x82\xa2\x82\xb5\x82\x50\x96\x87\x8a\x47", 6 },
    { "\x82\x50\x82\x51\x8a\x4b", "\x83\x80\x81\x5b\x83\x72\x81\x5b", 7 },
    { "\x82\x50\x82\x52\x8a\x4b", "\x83\x80\x81\x5b\x83\x72\x81\x5b", 8 },
    { "\x83\x58\x83\x5e\x83\x62\x83\x74\x83\x8d\x81\x5b\x83\x8b", "\x82\x73\x82\x67\x82\x64\x81\x40\x82\x64\x82\x6d\x82\x63", 9 },
};

void mode_dummy_0(u32 arg) {
    const DummyEntry* entry;

    FadeStartIn(FADE_MODE_BLACK, 0x10);
    SetBgMode0();
    SetupBg(0, 0, 0x0F, 0);
    EnableBg(0);
    DebugTextInit(0, 0x5400, 0x500);
    DebugTextLoadPalette(0, gWhitePalette, sizeof(gWhitePalette), 0x0F);
    SetupBg(1, 1, 0x0C, 8);
#ifdef VERSION_EU
    LoadBgTilesLz77(1, gDebugCheckerBgTiles);
    LoadBgMapLz77(1, gDebugCheckerBgMap);
    LoadBgPalette(1, gDebugCheckerBgPalette, sizeof(gDebugCheckerBgPalette));
#else
    LoadBgTiles(1, gDebugCheckerBgTiles, sizeof(gDebugCheckerBgTiles));
    LoadBgPalette(1, gDebugCheckerBgPalette, sizeof(gDebugCheckerBgPalette));
    LoadBgMap(1, gDebugCheckerBgMap, sizeof(gDebugCheckerBgMap));
#endif
    EnableBg(1);
    sDummyEntryIndex = arg;

    if (arg >= ARRAY_COUNT(sDummyEntries)) {
        sDummyEntryIndex = 0;
        DebugTextPrint(0, 0, 2, "\x83\x47\x83\x89\x81\x5b\x81\x46\x96\xb3\x8c\xf8\x82\xc8\x88\xf8\x90\x94");
    } else {
        sDummyEntryIndex = arg;
        entry = &sDummyEntries[arg];
        DebugTextPrint(0, 0, 2, entry->name);
        DebugTextPrint(0x10, 0x18, 2, entry->desc);
    }
}

void DummyUpdateExit() {
    const DummyEntry* entry;

    if (!FadeIsActive()) {
        entry = &sDummyEntries[sDummyEntryIndex];

        switch (entry->action) {
        case 0:
            ModeRequestHeapReset(&gModeMovie, MOVIE_OPENING);
            break;
        case 1:
            gGameState.availableWorlds = 0x200;
            ModeRequest(&gModeWorldselect, 0);
            break;
        case 2:
            AdvanceFloorStory();
            RequestMapMode();
            break;
        case 3:
            RequestEventMode(EVENT_006_1F_TRAVERSE_TOWN_E2);
            break;
        case 4:
            RequestEventMode(EVENT_020_4F_DEMO);
            break;
        case 5:
            RequestEventMode(EVENT_028_6F_DEMO);
            break;
        case 6:
            RequestEventMode(EVENT_044_11F_TWILIGHT_TOWN_E0);
            break;
        case 7:
            RequestEventMode(EVENT_061_13F_ENTRANCE);
            break;
        case 8:
            RequestEventMode(EVENT_073_13F_CAPSULE_ROOM_ENDING);
            break;
        case 9:
        default:
#ifdef VERSION_EU
            ModeRequest(&gModeLang, 0);
#else
            ModeRequest(&gModeCopyright1, 0);
#endif
            break;
        }
    } else {
        DebugTextDraw(0);
        DebugTextClear();
        SetBgScroll(1, (gFrameCounter << 14) >> 16, 0);
        UpdatePlayTime();
    }
}

void mode_dummy_1() {
    if (!FadeIsActive() && (GetKeysPressed() & (A_BUTTON | START_BUTTON))) {
        FadeStartOut(FADE_MODE_BLACK, 0x10);
        SetModeUpdate(DummyUpdateExit);
    }

    DebugTextDraw(0);
    DebugTextClear();
    SetBgScroll(1, (gFrameCounter << 14) >> 16, 0);
    UpdatePlayTime();
}

void mode_dummy_2() {
    DebugTextDestroy();
}

Mode gModeDummy = { "mode_dummy", (ModeInitFunc)mode_dummy_0, mode_dummy_1, mode_dummy_2 };
