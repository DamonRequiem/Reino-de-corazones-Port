/**
 * mode_mapchk.c
 * Debug Map Check
 */

#include "mode_mapchk.h"
#include "registration_data.h"
#include "map_runtime.h"
#include "map_api.h"
#include "card_api.h"
#include "save_api.h"
#include "bos4_api.h"
#include "game_state.h"
#include "m4a_song.h"
#include "display.h"
#include "fade.h"
#include "key.h"
#include "malloc.h"
#include "world_types.h"
#include "gba/keys.h"
#include "map_types.h"
#include "mode.h"
#include "player_progression_types.h"
#include "save_types.h"
#include "types.h"
#include "debug_text.h"
#include "map_check_worlds.h"

static const char sDebugMenuTextUs_0984B5F8[] = "\202s\202t\202s\202n\202q\202h\202`\202k";

static const char sDebugMenuTextUs_0984B60C[] = "\202f\202n\202`\202k\201@\201@\201@\201@";

static const char sDebugMenuTextUs_0984B620[] = "\202r\202s\202`\202q\202s\201@\201@\201@";

static const char sDebugMenuTextUs_0984B634[] = "\202e\202h\202d\202k\202c\201@\201@\201@";

static const char sDebugMenuTextUs_0984B648[] = "\202c\202d\202a\202t\202f\201@\201@\201@";

static const char sDebugMenuTextUs_0984B65C[] = "\202e\202t\202m\202m\202d\202k\201@";

static const char sDebugMenuTextUs_0984B66C[] = "\202r\202s\202`\202f\202d\201@\201@";

static const char sDebugMenuTextUs_0984B67C[] = "\202g\202d\202w\202`\202f\202n\202m";

static const char sDebugMenuTextUs_0984B68C[] = "\202b\202k\202h\202e\202e\201@\201@";

static const char sDebugMenuTextUs_0984B69C[] = "\202o\202`\202r\202r\201@\201@\201@";

static const char sDebugMenuTextUs_0984B6AC[] = "\202s\202n\202v\202d\202q\201@\201@";

static const char sDebugMenuTextUs_0984B6BC[] = "\202r\202l\202`\202k\202k\201@\201@";

static const char sDebugMenuTextUs_0984B6CC[] = "\202e\202k\202`\202s\201@\201@\201@";

static const char sDebugMenuTextUs_0984B6DC[] = "\202v\202h\202c\202d\201@\201@\201@";

static const char sDebugMenuTextUs_0984B6EC[] = "\202g\202h\202f\202g\201@\201@\201@";

static const char sDebugMenuTextUs_0984B6FC[] = "\202k\202n\202v\201@\201@\201@\201@";

static const char sDebugMenuTextUs_0984B70C[] = "\202q\202`\202m\202c\202n\202l\201@";

static const char sDebugMenuTextUs_0984B71C[] = "\202c\202d\202e\202`\202t\202k\202s";

static const char sMapChkWhitePalette[32] = "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377";

static const char sMapChkOnText[] = "\202n\202m\201@";

static const char sMapChkOffText[] = "\202n\202e\202e";

static const char sMapChkBasementText[] = "\201i\202a\201@\201@\201@\201j";

static const char sMapChkBasementNoneText[] = "\201i\202a\201|\201|\201|\201j";

static const char sMapChkHelpText[] = "\202t\202c\201F\202r\202d\202k\202d\202b\202s\201@\202k\202q\201F\202r\202d\202s\201@\202`\201F\202r\202s\202`\202q\202s";

static const char sMapChkModeLabel[] = "\202l\202n\202c\202d\201@\201F";

static const char sMapChkWorldLabel[] = "\202v\202n\202q\202k\202c\201F";

static const char sMapChkFloorLabel[] = "\202e\202k\202n\202n\202q\201F";

static const char sMapChkParamLabel[] = "\202o\202`\202q\202`\202l\201F";

static const char sMapChkFormLabel[] = "\202e\202n\202q\202l\201@\201F";

static const char sMapChkWideLabel[] = "\202v\202h\202c\202d\201@\201F";

static const char sMapChkHighLabel[] = "\202g\202h\202f\202g\201@\201F";

static const char sMapChkDeepLabel[] = "\202c\202d\202d\202o\201@\201F";

static const char sMapChkCursorBlankText[] = "\201@";

static const char sMapChkCursorText[] = "\201\204";

static MapChkWork* sMapChkWork;
static MapFormDef* sMapChkForm;

static const char* sMapChkModeNames[] = {
    sDebugMenuTextUs_0984B648,
    sDebugMenuTextUs_0984B634,
    sDebugMenuTextUs_0984B620,
    sDebugMenuTextUs_0984B60C,
    sDebugMenuTextUs_0984B5F8,
};

static const char* sMapChkFormNames[] = {
    sDebugMenuTextUs_0984B71C,
    sDebugMenuTextUs_0984B70C,
    sDebugMenuTextUs_0984B6FC,
    sDebugMenuTextUs_0984B6EC,
    sDebugMenuTextUs_0984B6DC,
    sDebugMenuTextUs_0984B6CC,
    sDebugMenuTextUs_0984B6BC,
    sDebugMenuTextUs_0984B6AC,
    sDebugMenuTextUs_0984B69C,
    sDebugMenuTextUs_0984B68C,
    sDebugMenuTextUs_0984B67C,
    sDebugMenuTextUs_0984B66C,
    sDebugMenuTextUs_0984B65C,
};

static void (*sMapChkRowHandlers[10])(MapChkWork*) = {
    MapChkEditMode,
    MapChkEditWorld,
    MapChkEditFloor,
    MapChkFlipParamToggle,
    MapChkEditForm,
    MapChkEditWidth,
    MapChkEditMinHeight,
    MapChkEditMaxHeight,
    MapChkEditMinDepth,
    MapChkEditMaxDepth,
};

Mode gModeMapChk = {
    "Mode_MapChk",
    (ModeInitFunc)Mode_MapChk_0,
    Mode_MapChk_1,
    Mode_MapChk_2,
};

void MapChkSetParamToggle(u8* work, u8 on) {
    if (work[5] != on) {
        work[5] = on;

        if (on) {
            DebugTextPrint(80, 68, 2, sMapChkOnText);
        } else {
            DebugTextPrint(80, 68, 2, sMapChkOffText);
        }
    }
}

void MapChkSetFloorProgress(u8 floor, u8 cleared) {
    if ((gGameState.flags & GAME_FLAG_RIKU) != 0) {
        if (cleared) {
            switch (floor) {
            case 0:
                gMapFloorState.progress = 1;
                break;
            case 1:
                gMapFloorState.progress = 3;
                break;
            case 2:
                gMapFloorState.progress = 5;
                break;
            case 3:
                gMapFloorState.progress = 7;
                break;
            case 4:
                gMapFloorState.progress = 9;
                break;
            case 5:
                gMapFloorState.progress = 11;
                break;
            case 6:
                gMapFloorState.progress = 13;
                break;
            case 7:
                gMapFloorState.progress = 15;
                break;
            case 8:
                gMapFloorState.progress = 17;
                break;
            case 9:
                gMapFloorState.progress = 19;
                break;
            case 10:
                gMapFloorState.progress = 22;
                break;
            case 11:
                gMapFloorState.progress = 24;
                break;
            }
        } else {
            switch (floor) {
            case 0:
                gMapFloorState.progress = 0;
                break;
            case 1:
                gMapFloorState.progress = 2;
                break;
            case 2:
                gMapFloorState.progress = 4;
                break;
            case 3:
                gMapFloorState.progress = 6;
                break;
            case 4:
                gMapFloorState.progress = 8;
                break;
            case 5:
                gMapFloorState.progress = 10;
                break;
            case 6:
                gMapFloorState.progress = 12;
                break;
            case 7:
                gMapFloorState.progress = 14;
                break;
            case 8:
                gMapFloorState.progress = 16;
                break;
            case 9:
                gMapFloorState.progress = 18;
                break;
            case 10:
                gMapFloorState.progress = 20;
                break;
            case 11:
                gMapFloorState.progress = 23;
                break;
            }
        }
    } else {
        if (cleared) {
            switch (floor) {
            case 0:
                gMapFloorState.progress = 1;
                break;
            case 1:
                gMapFloorState.progress = 3;
                break;
            case 2:
                gMapFloorState.progress = 5;
                break;
            case 3:
                gMapFloorState.progress = 7;
                break;
            case 4:
                gMapFloorState.progress = 9;
                break;
            case 5:
                gMapFloorState.progress = 11;
                break;
            case 6:
                gMapFloorState.progress = 13;
                break;
            case 7:
                gMapFloorState.progress = 15;
                break;
            case 8:
                gMapFloorState.progress = 17;
                break;
            case 9:
                gMapFloorState.progress = 19;
                break;
            case 10:
                gMapFloorState.progress = 21;
                break;
            case 11:
                gMapFloorState.progress = 23;
                break;
            case 12:
                gMapFloorState.progress = 27;
                break;
            }
        } else {
            switch (floor) {
            case 0:
                gMapFloorState.progress = 0;
                break;
            case 1:
                gMapFloorState.progress = 2;
                break;
            case 2:
                gMapFloorState.progress = 4;
                break;
            case 3:
                gMapFloorState.progress = 6;
                break;
            case 4:
                gMapFloorState.progress = 8;
                break;
            case 5:
                gMapFloorState.progress = 10;
                break;
            case 6:
                gMapFloorState.progress = 12;
                break;
            case 7:
                gMapFloorState.progress = 14;
                break;
            case 8:
                gMapFloorState.progress = 16;
                break;
            case 9:
                gMapFloorState.progress = 18;
                break;
            case 10:
                gMapFloorState.progress = 20;
                break;
            case 11:
                gMapFloorState.progress = 22;
                break;
            case 12:
                gMapFloorState.progress = 25;
                break;
            }
        }
    }
}

void MapChkEditMode(MapChkWork* work) {
    if ((GetKeysRepeat() & DPAD_LEFT) != 0) {
        work->mode = work->mode == 0 ? 4 : work->mode - 1;
    }

    if ((GetKeysRepeat() & DPAD_RIGHT) != 0) {
        work->mode = work->mode > 3 ? 0 : work->mode + 1;
    }

    DebugTextPrint(80, 32, 2, sMapChkModeNames[work->mode]);
}

void MapChkEditWorld(MapChkWork* work) {
    u8 prevWorld = work->world;
    const u8* names;
    s32 offset;

    if ((GetKeysRepeat() & DPAD_LEFT) != 0) {
        work->world = work->world == 0 ? WORLD_CASTLE_OBLIVION : work->world - 1;
    }

    if ((GetKeysRepeat() & DPAD_RIGHT) != 0) {
        work->world = work->world > 11 ? 0 : work->world + 1;
    }

    if (prevWorld != work->world) {
        names = gMapChkWorldNames[0];
        offset = work->world * 8;
        names += 4;
        DebugTextPrint(80, 44, 2, *(const char**)(names + offset));
    }
}

void MapChkEditFloor(MapChkWork* work) {
    if ((GetKeysRepeat() & DPAD_LEFT) != 0) {
        work->floor = work->floor == 0 ? 13 : work->floor - 1;
    }

    if ((GetKeysRepeat() & DPAD_RIGHT) != 0) {
        work->floor = work->floor > 12 ? 0 : work->floor + 1;
    }

    DebugTextPrintNumber(80, 56, 2, work->floor + 1);
    DebugTextPrint(112, 56, 2, sMapChkBasementText);

    if (12 - work->floor > 0) {
        DebugTextPrintNumber(128, 56, 2, 12 - work->floor);
    } else {
        DebugTextPrint(112, 56, 2, sMapChkBasementNoneText);
    }
}

void MapChkEditForm(MapChkWork* work) {
    u8 prevForm = work->form;

    if ((GetKeysRepeat() & DPAD_LEFT) != 0) {
        work->form = work->form == 0 ? 12 : work->form - 1;
    }

    if ((GetKeysRepeat() & DPAD_RIGHT) != 0) {
        work->form = work->form > 11 ? 0 : work->form + 1;
    }

    if (prevForm != work->form) {
        LoadMapForm(work->form + 15);
        DebugTextPrint(80, 80, 2, sMapChkFormNames[work->form]);
        DebugTextPrintNumber(80, 92, 2, sMapChkForm->maxWidth);
        DebugTextPrintNumber(80, 104, 2, sMapChkForm->minHeight);
        DebugTextPrintNumber(80, 116, 2, sMapChkForm->maxHeight);
        DebugTextPrintNumber(80, 128, 2, sMapChkForm->minDepth);
        DebugTextPrintNumber(80, 140, 2, sMapChkForm->maxDepth);
        MapChkSetParamToggle((u8*)work, TRUE);
    }
}

void MapChkEditWidth(MapChkWork* work) {
    u8 width = sMapChkForm->maxWidth;

    if ((GetKeysRepeat() & DPAD_LEFT) != 0 && width > 8) {
        width--;
    }

    if ((GetKeysRepeat() & DPAD_RIGHT) != 0 && width <= 47) {
        width++;
    }

    if (sMapChkForm->maxWidth != width) {
        sMapChkForm->maxWidth = width;
        sMapChkForm->minWidth = width;
        DebugTextPrintNumber(80, 92, 2, sMapChkForm->maxWidth);
        MapChkSetParamToggle((u8*)work, TRUE);
    }
}

void MapChkFlipParamToggle(MapChkWork* work) {
    if ((GetKeysRepeat() & (DPAD_RIGHT | DPAD_LEFT)) != 0) {
        MapChkSetParamToggle((u8*)work, !work->useParams ? TRUE : FALSE);
    }
}

void MapChkEditMinHeight(MapChkWork* work) {
    u8 minHeight = sMapChkForm->minHeight;

    if ((GetKeysRepeat() & DPAD_LEFT) != 0 && minHeight > 2) {
        minHeight--;
    }

    if ((GetKeysRepeat() & DPAD_RIGHT) != 0 && minHeight <= 9) {
        minHeight++;
    }

    if (sMapChkForm->minHeight != minHeight) {
        sMapChkForm->minHeight = minHeight;
        DebugTextPrintNumber(80, 104, 2, sMapChkForm->minHeight);

        if (sMapChkForm->maxHeight < minHeight) {
            sMapChkForm->maxHeight = minHeight;
            DebugTextPrintNumber(80, 116, 2, sMapChkForm->maxHeight);
        }

        MapChkSetParamToggle((u8*)work, TRUE);
    }
}

void MapChkEditMaxHeight(MapChkWork* work) {
    u8 maxHeight = sMapChkForm->maxHeight;

    if ((GetKeysRepeat() & DPAD_LEFT) != 0 && maxHeight > 2) {
        maxHeight--;
    }

    if ((GetKeysRepeat() & DPAD_RIGHT) != 0 && maxHeight <= 9) {
        maxHeight++;
    }

    if (sMapChkForm->maxHeight != maxHeight) {
        sMapChkForm->maxHeight = maxHeight;
        DebugTextPrintNumber(80, 116, 2, sMapChkForm->maxHeight);

        if (sMapChkForm->minHeight > maxHeight) {
            sMapChkForm->minHeight = maxHeight;
            DebugTextPrintNumber(80, 104, 2, sMapChkForm->minHeight);
        }

        MapChkSetParamToggle((u8*)work, TRUE);
    }
}

void MapChkEditMinDepth(MapChkWork* work) {
    u8 minDepth = sMapChkForm->minDepth;

    if ((GetKeysRepeat() & DPAD_LEFT) != 0 && minDepth > 3) {
        minDepth--;
    }

    if ((GetKeysRepeat() & DPAD_RIGHT) != 0 && minDepth <= 47) {
        minDepth++;
    }

    if (sMapChkForm->minDepth != minDepth) {
        sMapChkForm->minDepth = minDepth;
        DebugTextPrintNumber(80, 128, 2, sMapChkForm->minDepth);

        if (sMapChkForm->maxDepth < minDepth) {
            sMapChkForm->maxDepth = minDepth;
            DebugTextPrintNumber(80, 140, 2, sMapChkForm->maxDepth);
        }

        MapChkSetParamToggle((u8*)work, TRUE);
    }
}

void MapChkEditMaxDepth(MapChkWork* work) {
    u8 maxDepth = sMapChkForm->maxDepth;

    if ((GetKeysRepeat() & DPAD_LEFT) != 0 && maxDepth > 3) {
        maxDepth--;
    }

    if ((GetKeysRepeat() & DPAD_RIGHT) != 0 && maxDepth <= 47) {
        maxDepth++;
    }

    if (sMapChkForm->maxDepth != maxDepth) {
        sMapChkForm->maxDepth = maxDepth;
        DebugTextPrintNumber(80, 140, 2, sMapChkForm->maxDepth);

        if (sMapChkForm->minDepth > maxDepth) {
            sMapChkForm->minDepth = maxDepth;
            DebugTextPrintNumber(80, 128, 2, sMapChkForm->minDepth);
        }

        MapChkSetParamToggle((u8*)work, TRUE);
    }
}

void Mode_MapChk_0() {
    const u8* names;
    s32 offset;

    sMapChkWork = EwramAlloc(sizeof(MapChkWork));
    SaveLoadHeader();
    gMapChkUseParams = FALSE;
    sMapChkWork->cursor = 0;
    sMapChkWork->mode = 0;
    sMapChkWork->world = 0;
    sMapChkWork->floor = 1;
    sMapChkWork->form = 0;
    sMapChkWork->useParams = FALSE;
    gGameState.roomEffect = ROOM_EFFECT_NONE;
    LoadMapForm(sMapChkWork->form);
    sMapChkForm = &gMapForm;
    SetBgMode0();
    SetupBg(0, 0, 15, 0);
    EnableBg(0);
    DebugTextInit(0, 0x5400, 0x500);
    DebugTextLoadPalette(0, sMapChkWhitePalette, sizeof(sMapChkWhitePalette), 15);
    DebugTextPrint(0, 0, 2, sMapChkHelpText);
    DebugTextPrint(24, 32, 2, sMapChkModeLabel);
    DebugTextPrint(24, 44, 2, sMapChkWorldLabel);
    DebugTextPrint(24, 56, 2, sMapChkFloorLabel);
    DebugTextPrint(24, 68, 2, sMapChkParamLabel);
    DebugTextPrint(24, 80, 2, sMapChkFormLabel);
    DebugTextPrint(24, 92, 2, sMapChkWideLabel);
    DebugTextPrint(24, 104, 2, sMapChkHighLabel);
    DebugTextPrint(24, 128, 2, sMapChkDeepLabel);
    DebugTextPrint(80, 68, 2, sMapChkOffText);
    DebugTextPrint(80, 32, 2, sMapChkModeNames[sMapChkWork->mode]);
    names = gMapChkWorldNames[0];
    offset = sMapChkWork->world * 8;
    names += 4;
    DebugTextPrint(80, 44, 2, *(const char**)(names + offset));
    DebugTextPrintNumber(80, 56, 2, sMapChkWork->floor + 1);
    DebugTextPrint(80, 80, 2, sMapChkFormNames[sMapChkWork->form]);
    DebugTextPrintNumber(80, 92, 2, sMapChkForm->maxWidth);
    DebugTextPrintNumber(80, 104, 2, sMapChkForm->minHeight);
    DebugTextPrintNumber(80, 116, 2, sMapChkForm->maxHeight);
    DebugTextPrintNumber(80, 128, 2, sMapChkForm->minDepth);
    DebugTextPrintNumber(80, 140, 2, sMapChkForm->maxDepth);
    FadeStartIn(FADE_MODE_BLACK, 8);
    m4aMPlayAllStop();
}

void Mode_MapChk_1() {
    MapChkWork* work;

    DebugTextPrint(12, sMapChkWork->cursor * 12 + 32, 2, sMapChkCursorBlankText);

    if ((GetKeysRepeat() & DPAD_UP) != 0) {
        sMapChkWork->cursor = sMapChkWork->cursor == 0 ? 9 : sMapChkWork->cursor - 1;
    }

    if ((GetKeysRepeat() & DPAD_DOWN) != 0) {
        sMapChkWork->cursor = sMapChkWork->cursor > 8 ? 0 : sMapChkWork->cursor + 1;
    }

    DebugTextPrint(12, sMapChkWork->cursor * 12 + 32, 2, sMapChkCursorText);
    sMapChkRowHandlers[sMapChkWork->cursor](sMapChkWork);

    if ((GetKeysPressed() & (A_BUTTON | START_BUTTON)) != 0) {
        func_08085FB0();

        if ((gGameState.flags & GAME_FLAG_RIKU) == 0) {
            InitSoraDecks();
        }

        InitMapCardInventory();
        gMapChkUseParams = sMapChkWork->useParams;
        gGameState.progression.friendFlags |= FRIEND_FLAG_DONALD_DUCK;
        gGameState.progression.friendFlags |= FRIEND_FLAG_GOOFY;
        gGameState.progression.tutorialFlags |= TUTORIAL_FLAG_MAP_SELECT | TUTORIAL_FLAG_SAVE_POINT | TUTORIAL_FLAG_MAP |
            TUTORIAL_FLAG_MAP_SELECT_EVENT_DOOR | TUTORIAL_FLAG_WARP_POINT | TUTORIAL_FLAG_ROOM_CREATE |
            TUTORIAL_FLAG_MAP_STAIR;
        work = sMapChkWork;

        switch (work->mode) {
        case 1:
            gGameState.floors[work->floor].world = gMapChkWorldNames[work->world][0];
            MapChkSetFloorProgress(sMapChkWork->floor, FALSE);
            GoToFloor(sMapChkWork->floor);
            SetFloorWorld(gMapChkWorldNames[sMapChkWork->world][0]);
            gMapFloorState.flags |= FLOOR_FLAG_LOGO_SHOWN;
            EnterFloorWorld();
            RequestMapMode();
            break;
        case 2:
            gGameState.floors[work->floor].world = 0;
            MapChkSetFloorProgress(sMapChkWork->floor, FALSE);
            GoToFloor(sMapChkWork->floor);
            gMapFloorState.room = MAP_ROOM_ENTRANCE_HALL;
            gMapFloorState.entrySide = MAP_DOOR_SIDE_NONE;
            RequestMapMode();
            break;
        case 3:
            gGameState.floors[sMapChkWork->floor].world = gMapChkWorldNames[sMapChkWork->world][0];
            MapChkSetFloorProgress(sMapChkWork->floor, TRUE);
            GoToFloor(sMapChkWork->floor);
            gMapFloorState.room = MAP_ROOM_EXIT_HALL;
            gMapFloorState.entrySide = MAP_DOOR_SIDE_NONE;
            RequestMapMode();
            break;
        case 4:
            gGameState.floors[0].world = WORLD_TRAVERSE_TOWN;
            GoToFloor(0);
            SetFloorWorld(WORLD_TRAVERSE_TOWN);
            gMapFloorState.room = MAP_ROOM_TUTORIAL;
            gMapFloorState.entrySide = MAP_DOOR_SIDE_NONE;
            RequestMapMode();
            break;
        default:
            gGameState.floors[sMapChkWork->floor].world =
                gMapChkWorldNames[sMapChkWork->world][0];
            MapChkSetFloorProgress(sMapChkWork->floor, FALSE);
            GoToFloor(sMapChkWork->floor);
            SetFloorWorld(gMapChkWorldNames[sMapChkWork->world][0]);
            EnterFloorWorld();
            ModeRequest(&gModeMapDbg, 0);
            break;
        }
    } else if ((GetKeysPressed() & (B_BUTTON | SELECT_BUTTON)) != 0) {
        ModeRequest(&gModeDebug, 0);
    } else {
        DebugTextDraw(0);
        DebugTextClear();
    }
}

void Mode_MapChk_2() {
    DebugTextDestroy();
    EwramFree(sMapChkWork);
}
