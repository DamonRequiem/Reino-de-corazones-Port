/**
 * mode_deck.c
 * Deck Menu Screen
 */

#include "mode_deck.h"
#include "registration_data.h"
#include "map_api.h"
#include "mode.h"
#include "m4a_song.h"
#include "mode_test.h"
#include "gba/keys.h"
#include "sprites_msg.h"
#include "fade.h"
#include "songs.h"
#include "field_state.h"
#include "game_state.h"
#include "key.h"
#include "obj_api.h"
#include <stddef.h>
#include "system_state.h"
#include "taskpool.h"
#include "types.h"
#include "mode_sio.h"
#include "sprite_palettes.h"
#include "card.h"

static TaskPool sModeDeckTasks;
static u8 sModeDeckResult;

void Mode_Deck_0() {
    sModeDeckResult = DECK_MENU_RESULT_NONE;
    TaskPoolInit(&sModeDeckTasks, 1);

    if ((gGameState.flags & GAME_FLAG_RIKU) == 0) {
        TaskCreate(&sModeDeckTasks, &gTaskDescDeckmenu2, &sModeDeckResult);
    } else {
        TaskCreate(&sModeDeckTasks, &gTaskDescDeckmenu2Riku, &sModeDeckResult);
    }

    if (gSystemFlags & SYSTEM_FLAG_LINK_ACTIVE) {
        m4aMPlayAllStop();
    }
}

void Mode_Deck_1() {
    if (gSystemFlags & SYSTEM_FLAG_LINK_ACTIVE) {
        SioBtlOptionRecvSettings();
    } else {
        UpdatePlayTime();
    }

    TaskPoolUpdate(&sModeDeckTasks);
    TaskPoolDraw(&sModeDeckTasks);

    if (sModeDeckResult == DECK_MENU_RESULT_RETURN_TO_MAP) {
        if (gDebugFlags & DEBUG_FLAG_CHKBTL) {
            ModeRequest(&gModeChkbtl, 0);
        } else if (gSystemFlags & SYSTEM_FLAG_LINK_ACTIVE) {
            ModeRequest(&gModeSioBtlOption, SIO_BTL_OPTION_ENTRY_FROM_DECK_MENU);
        } else {
            ReturnToMap(FALSE);
        }
    }

    if (sModeDeckResult == DECK_MENU_RESULT_RETURN_TO_MENU) {
        if (gDebugFlags & DEBUG_FLAG_CHKBTL) {
            ModeRequest(&gModeChkbtl, 0);
        } else if (gSystemFlags & SYSTEM_FLAG_LINK_ACTIVE) {
            ModeRequest(&gModeSioBtlOption, SIO_BTL_OPTION_ENTRY_FROM_DECK_MENU);
        } else {
            ReturnToMap(TRUE);
        }
    }
}

void Mode_Deck_2() {
    TaskPoolDestroy(&sModeDeckTasks);
}

enum MenuState {
    MENU_STATE_SLIDE_IN,
    MENU_STATE_MAIN,
    MENU_STATE_SUBMENU,
    MENU_STATE_UNUSED,
    MENU_STATE_EXIT,
    MENU_STATE_CLOSE
};

enum MenuItem {
    MENU_ITEM_DECK,
    MENU_ITEM_CARD,
    MENU_ITEM_MAP,
    MENU_ITEM_SAVE,
    MENU_ITEM_MEMO,
    MENU_ITEM_OPTION,
    MENU_ITEM_DECK_1,
    MENU_ITEM_DECK_2,
    MENU_ITEM_DECK_3,
    MENU_ITEM_EDIT
};

void menu_0(MenuWork* work) {
    gFieldState->flags |= FIELD_FLAG_FREEZE_PLAYER;
    gFieldState->flags |= FIELD_FLAG_FREEZE_ENEMIES;
    gFieldState->flags |= FIELD_FLAG_MENU_OPEN;
    work->x = 0xF000;
    work->y = 0x4800;
    work->cursor = MENU_ITEM_DECK;
    work->state = MENU_STATE_SLIDE_IN;
    work->tiles = LoadObjTiles(gMenuTiles, sizeof(gMenuTiles));
    work->palette = LoadObjPalette(gMenuPalette, sizeof(gMenuPalette));
    m4aSongNumStart(SONG_SYS_CANSEL);
}

u8 menu_1(MenuWork* work) {
    switch (work->state) {
    case MENU_STATE_SLIDE_IN:
        work->x += (0xBC00 - work->x) >> 1;

        if ((work->x >> 8) == 0xBC) {
            work->state = MENU_STATE_MAIN;
        }

        if (GetKeysPressed() & B_BUTTON) {
            work->state = MENU_STATE_EXIT;
        }

        break;
    case MENU_STATE_MAIN:
        if (GetKeysRepeat() & DPAD_UP) {
            if (work->cursor != MENU_ITEM_DECK) {
                work->cursor--;
            } else {
                work->cursor = MENU_ITEM_OPTION;
            }

            m4aSongNumStart(SONG_SYS_CLICK);
        }

        if (GetKeysRepeat() & DPAD_DOWN) {
            if (work->cursor <= MENU_ITEM_MEMO) {
                work->cursor++;
            } else {
                work->cursor = MENU_ITEM_DECK;
            }

            m4aSongNumStart(SONG_SYS_CLICK);
        }

        if (GetKeysPressed() & A_BUTTON) {
            switch (work->cursor) {
            case MENU_ITEM_DECK:
                work->state = MENU_STATE_SUBMENU;
                work->cursor = MENU_ITEM_DECK_1;
                m4aSongNumStart(SONG_SYS_CANSEL);
                break;
            case MENU_ITEM_MAP:
                RequestFieldResume();
                FadeStartOut(FADE_MODE_BLACK, 32);
                work->state = MENU_STATE_EXIT;
                m4aSongNumStart(SONG_SYS_KETTEI);
                break;
            case MENU_ITEM_CARD:
            case MENU_ITEM_SAVE:
            case MENU_ITEM_MEMO:
                m4aSongNumStart(SONG_SYS_BEEP);
                break;
            case MENU_ITEM_OPTION:
                m4aSongNumStart(SONG_SYS_BEEP);
                break;
            }
        }

        if (GetKeysPressed() & B_BUTTON) {
            work->state = MENU_STATE_CLOSE;
            m4aSongNumStart(SONG_SYS_CLOSE);
        }

        break;
    case MENU_STATE_SUBMENU:
        if (GetKeysRepeat() & DPAD_UP) {
            if (work->cursor > MENU_ITEM_DECK_1) {
                work->cursor--;
            } else {
                work->cursor = MENU_ITEM_EDIT;
            }

            m4aSongNumStart(SONG_SYS_CLICK);
        }

        if (GetKeysRepeat() & DPAD_DOWN) {
            if (work->cursor <= MENU_ITEM_DECK_3) {
                work->cursor++;
            } else {
                work->cursor = MENU_ITEM_DECK_1;
            }

            m4aSongNumStart(SONG_SYS_CLICK);
        }

        if (GetKeysPressed() & B_BUTTON) {
            work->state = MENU_STATE_MAIN;
            work->cursor = MENU_ITEM_DECK;
            m4aSongNumStart(SONG_SYS_CLOSE);
        }

        if (GetKeysPressed() & A_BUTTON) {
            switch (work->cursor) {
            case MENU_ITEM_DECK_1:
                work->cursor = MENU_ITEM_DECK;
                work->state = MENU_STATE_MAIN;
                m4aSongNumStart(SONG_SYS_KETTEI);
                break;
            case MENU_ITEM_DECK_2:
                work->cursor = MENU_ITEM_DECK;
                work->state = MENU_STATE_MAIN;
                m4aSongNumStart(SONG_SYS_KETTEI);
                break;
            case MENU_ITEM_DECK_3:
                work->cursor = MENU_ITEM_DECK;
                work->state = MENU_STATE_MAIN;
                m4aSongNumStart(SONG_SYS_KETTEI);
                break;
            case MENU_ITEM_EDIT:
                RequestFieldResume();
                FadeStartOut(FADE_MODE_BLACK, 32);
                work->state = MENU_STATE_EXIT;
                m4aSongNumStart(SONG_SYS_KETTEI);
                break;
            }
        }

        break;
    case MENU_STATE_EXIT:
        work->x += (0x11800 - work->x) >> 1;

        if ((work->x >> 8) > 274) {
            if (!FadeIsActive()) {
                if (work->cursor != MENU_ITEM_MAP) {
                    if (work->cursor == MENU_ITEM_EDIT) {
                        ModeRequest(&gModeDeck, 0);
                    }
                } else {
                    ModeRequest(&gModeAllmap, 0);
                }

                work->state = MENU_STATE_CLOSE;
            }
        }

        break;
    case MENU_STATE_CLOSE:
        work->x += (0x11800 - work->x) >> 1;

        if ((work->x >> 8) > 274) {
            return 0;
        }

        break;
    case MENU_STATE_UNUSED:
    default:
        break;
    }

    return 1;
}

void menu_2(MenuWork* work) {
    DrawSprite(work->x >> 8, work->y >> 8, gMenuFrames[work->cursor], work->tiles, work->palette, NULL, 0, 80);
}

void menu_3(MenuWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    gFieldState->flags &= ~FIELD_FLAG_FREEZE_PLAYER;
    gFieldState->flags &= ~FIELD_FLAG_FREEZE_ENEMIES;
    gFieldState->flags &= ~FIELD_FLAG_MENU_OPEN;
}

Mode gModeDeck = { "Mode_Deck", (ModeInitFunc)Mode_Deck_0, Mode_Deck_1, Mode_Deck_2 };

TaskDesc gTaskDescMenu = {
    "menu",
    (TaskInitFunc)menu_0,
    (TaskUpdateFunc)menu_1,
    (TaskDrawFunc)menu_2,
    (TaskDestroyFunc)menu_3,
    sizeof(MenuWork),
};
