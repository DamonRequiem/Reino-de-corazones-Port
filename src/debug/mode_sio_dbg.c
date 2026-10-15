/**
 * mode_sio_dbg.c
 * Debug Link Battle Config
 */

#include "macros.h"
#include "registration_data.h"
#include "mode_sio_dbg.h"
#include "mode_chkbtl.h"
#include "mode_sio_api.h"
#include "game_state.h"
#include "display.h"
#include "key.h"
#include "gba/keys.h"
#include "mode.h"
#include "card_api.h"
#include "chara_types.h"
#include "player_progression_types.h"
#include "types.h"
#include "debug_text.h"

#ifdef VERSION_EU
u16 gUnk_0203C3C4 EWRAM_COMMON(4);
#else
s8 gUnk_0203C3C4 EWRAM_COMMON(4);
#endif
u16 gUnk_0203C3C8 EWRAM_COMMON(4);
u16 gUnk_0203C3CC EWRAM_COMMON(4);
u16 gSioDbgCp EWRAM_COMMON(4);
#ifdef VERSION_EU
u16 gUnk_0203C3D4 EWRAM_COMMON(4);
u16 gSioDbgLevel1P EWRAM_COMMON(4);
u16 gSioDbgLoseCount1P EWRAM_COMMON(4);
u16 gSioDbgWinCount2P EWRAM_COMMON(4);
u16 gSioDbgHp2P EWRAM_COMMON(4);
u16 gSioDbgLevel2P EWRAM_COMMON(4);
#else
s8 gUnk_0203C3D4 EWRAM_COMMON(4);
#endif

static const char* sSioDbgRowNames[] = {
#ifdef VERSION_EU
    "\x82\x50\x82\x6f\x81\x40\x82\x6b\x82\x64\x82\x75\x82\x64\x82\x6b\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x50\x82\x6f\x81\x40\x82\x67\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x50\x82\x6f\x81\x40\x82\x62\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x50\x82\x6f\x81\x40\x82\x76\x82\x68\x82\x6d\x81\x40\x81\x40\x82\x6d\x82\x74\x82\x6c\x81\x46",
    "\x82\x50\x82\x6f\x81\x40\x82\x6b\x82\x6e\x82\x72\x82\x64\x81\x40\x82\x6d\x82\x74\x82\x6c\x81\x46",
    "\x82\x51\x82\x6f\x81\x40\x82\x6b\x82\x64\x82\x75\x82\x64\x82\x6b\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x51\x82\x6f\x81\x40\x82\x67\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x51\x82\x6f\x81\x40\x82\x62\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x51\x82\x6f\x81\x40\x82\x76\x82\x68\x82\x6d\x81\x40\x81\x40\x82\x6d\x82\x74\x82\x6c\x81\x46",
    "\x82\x51\x82\x6f\x81\x40\x82\x6b\x82\x6e\x82\x72\x82\x64\x81\x40\x82\x6d\x82\x74\x82\x6c\x81\x46",
    "\x82\x62\x82\x60\x82\x71\x82\x63\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x60\x82\x61\x82\x68\x82\x6b\x82\x68\x82\x73\x82\x78\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
#else
    "\x82\x6b\x82\x64\x82\x75\x82\x64\x82\x6b\x81\x40\x81\x40\x81\x46",
    "\x82\x67\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x62\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x62\x82\x60\x82\x71\x82\x63\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x60\x82\x61\x82\x68\x82\x6b\x82\x68\x82\x73\x82\x78\x81\x46",
#endif
};

#ifndef VERSION_EU
static const char* sSioDbgModeNames[] = {
    "\x82\x60\x82\x6b\x82\x6b\x81\x40\x81\x40\x81\x40",
    "\x82\x6d\x82\x6e\x82\x71\x82\x6c\x82\x60\x82\x6b",
};
#endif

static const char sSioDbgCursorText[] = "\x81\x84";

static const char sSioDbgTitleText[] = "\x82\x61\x82\x60\x82\x73\x82\x73\x82\x6b\x82\x64\x81\x40\x82\x62\x82\x6e\x82\x6d\x82\x65\x82\x68\x82\x66";

static const char sSioDbgCursorBlankText[] = "\x81\x40";

Mode gModeSioDbgFlg = {
    "mode_sio_dbg_flg",
    mode_sio_dbg_flg_0,
    mode_sio_dbg_flg_1,
    mode_sio_dbg_flg_2,
};

static s8 sSioDbgCursor;
static s8 sSioDbgRowCount;

void mode_sio_dbg_flg_0(s32 arg) {
#ifdef VERSION_EU
    s32 zero;
#else
    s32 i;
#endif

    SetBgMode0();
    SetupBg(0, 0, 0x0F, 0);
    EnableBg(0);
    DebugTextInit(0, 0x5400, 0x500);
    DebugTextLoadPalette(0, gWhitePalette, sizeof(gWhitePalette), 0x0F);
    sSioDbgCursor = 0;
#ifdef VERSION_EU
    zero = 0;
#endif
    DebugTextPrint(8, 0x24, 2, sSioDbgCursorText);
#ifdef VERSION_EU
    sSioDbgRowCount = 10;
#else
    sSioDbgRowCount = 5;
#endif
    DebugTextPrint(0x0C, 0x12, 2, sSioDbgTitleText);

#ifdef VERSION_EU
    DebugTextPrint(0x14, 0x24, 2, sSioDbgRowNames[0]);
    DebugTextPrint(0x14, 0x2D, 2, sSioDbgRowNames[1]);
    DebugTextPrint(0x14, 0x36, 2, sSioDbgRowNames[2]);
    DebugTextPrint(0x14, 0x3F, 2, sSioDbgRowNames[3]);
    DebugTextPrint(0x14, 0x48, 2, sSioDbgRowNames[4]);
    DebugTextPrint(0x14, 0x5A, 2, sSioDbgRowNames[5]);
    DebugTextPrint(0x14, 0x63, 2, sSioDbgRowNames[6]);
    DebugTextPrint(0x14, 0x6C, 2, sSioDbgRowNames[7]);
    DebugTextPrint(0x14, 0x75, 2, sSioDbgRowNames[8]);
    DebugTextPrint(0x14, 0x7E, 2, sSioDbgRowNames[9]);
    gSioDbgLevel1P = 1;
    gUnk_0203C3C4 = 80;
    gSioDbgCp = 275;
    gUnk_0203C3CC = zero;
    gSioDbgLoseCount1P = zero;
    gSioDbgLevel2P = 1;
    gSioDbgHp2P = 80;
    gUnk_0203C3C8 = 275;
    gSioDbgWinCount2P = zero;
    gUnk_0203C3D4 = zero;
    DebugTextPrintNumber(0x78, 0x24, 2, gSioDbgLevel1P);
    DebugTextPrintNumber(0x78, 0x2D, 2, gUnk_0203C3C4);
    DebugTextPrintNumber(0x78, 0x36, 2, gSioDbgCp);
    DebugTextPrintNumber(0x78, 0x3F, 2, gUnk_0203C3CC);
    DebugTextPrintNumber(0x78, 0x48, 2, gSioDbgLoseCount1P);
    DebugTextPrintNumber(0x78, 0x5A, 2, gSioDbgLevel2P);
    DebugTextPrintNumber(0x78, 0x63, 2, gSioDbgHp2P);
    DebugTextPrintNumber(0x78, 0x6C, 2, gUnk_0203C3C8);
    DebugTextPrintNumber(0x78, 0x75, 2, gSioDbgWinCount2P);
    DebugTextPrintNumber(0x78, 0x7E, 2, gUnk_0203C3D4);
#else
    for (i = 0; i < sSioDbgRowCount; i++) {
        DebugTextPrint(0x14, i * 9 + 0x24, 2, sSioDbgRowNames[i]);
    }

    gUnk_0203C3C8 = 50;
    gUnk_0203C3CC = 500;
    gSioDbgCp = 500;
    gUnk_0203C3C4 = 0;
    gUnk_0203C3D4 = 0;
    DebugTextPrintNumber(0x64, 0x24, 2, gUnk_0203C3C8);
    DebugTextPrintNumber(0x64, 0x2D, 2, gUnk_0203C3CC);
    DebugTextPrintNumber(0x64, 0x36, 2, gSioDbgCp);
    DebugTextPrint(0x64, 0x3F, 2, sSioDbgModeNames[gUnk_0203C3C4]);
    DebugTextPrint(0x64, 0x48, 2, sSioDbgModeNames[gUnk_0203C3D4]);
#endif
}

void mode_sio_dbg_flg_1() {
    u8 prev;

    prev = sSioDbgCursor;

#ifdef VERSION_EU
    if (GetKeysRepeat() & DPAD_UP) {
        if (sSioDbgCursor == 0) {
            sSioDbgCursor = 10;
        } else if (sSioDbgCursor == 6) {
            sSioDbgCursor = 4;
        } else {
            sSioDbgCursor--;
        }
    }

    if (GetKeysRepeat() & DPAD_DOWN) {
        if (sSioDbgCursor == 10) {
            sSioDbgCursor = 0;
        } else if (sSioDbgCursor == 4) {
            sSioDbgCursor = 6;
        } else {
            sSioDbgCursor++;
        }
    }
#else
    if (GetKeysRepeat() & DPAD_UP) {
        sSioDbgCursor--;
    }

    if (GetKeysRepeat() & DPAD_DOWN) {
        sSioDbgCursor++;
    }
#endif

    if (prev != sSioDbgCursor) {
#ifndef VERSION_EU
        if (sSioDbgCursor < 0) {
            sSioDbgCursor = sSioDbgRowCount - 1;
        } else if (sSioDbgCursor >= sSioDbgRowCount) {
            sSioDbgCursor = 0;
        }
#endif

        DebugTextPrint(8, (prev + 4) * 9, 2, sSioDbgCursorBlankText);
        DebugTextPrint(8, (sSioDbgCursor + 4) * 9, 2, sSioDbgCursorText);
    }

    switch (sSioDbgCursor) {
#ifdef VERSION_EU
    case 0:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gSioDbgLevel1P > 1) {
                gSioDbgLevel1P--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gSioDbgLevel1P <= 98) {
                gSioDbgLevel1P++;
            }
        }

        DebugTextPrintNumber(0x78, 0x24, 2, gSioDbgLevel1P);
        break;
    case 1:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnk_0203C3C4 > 80) {
                gUnk_0203C3C4 -= 15;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnk_0203C3C4 <= 559) {
                gUnk_0203C3C4 += 15;
            }
        }

        DebugTextPrintNumber(0x78, 0x2D, 2, gUnk_0203C3C4);
        break;
    case 2:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gSioDbgCp > 275) {
                gSioDbgCp -= 25;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gSioDbgCp <= 974) {
                gSioDbgCp += 25;
            }
        }

        DebugTextPrintNumber(0x78, 0x36, 2, gSioDbgCp);
        break;
    case 3:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnk_0203C3CC > 1) {
                gUnk_0203C3CC--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnk_0203C3CC <= 998) {
                gUnk_0203C3CC++;
            }
        }

        DebugTextPrintNumber(0x78, 0x3F, 2, gUnk_0203C3CC);
        break;
    case 4:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gSioDbgLoseCount1P > 1) {
                gSioDbgLoseCount1P--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gSioDbgLoseCount1P <= 998) {
                gSioDbgLoseCount1P++;
            }
        }

        DebugTextPrintNumber(0x78, 0x48, 2, gSioDbgLoseCount1P);
        break;
    case 6:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gSioDbgLevel2P > 1) {
                gSioDbgLevel2P--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gSioDbgLevel2P <= 98) {
                gSioDbgLevel2P++;
            }
        }

        DebugTextPrintNumber(0x78, 0x5A, 2, gSioDbgLevel2P);
        break;
    case 7:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gSioDbgHp2P > 80) {
                gSioDbgHp2P -= 15;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gSioDbgHp2P <= 559) {
                gSioDbgHp2P += 15;
            }
        }

        DebugTextPrintNumber(0x78, 0x63, 2, gSioDbgHp2P);
        break;
    case 8:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnk_0203C3C8 > 275) {
                gUnk_0203C3C8 -= 25;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnk_0203C3C8 <= 974) {
                gUnk_0203C3C8 += 25;
            }
        }

        DebugTextPrintNumber(0x78, 0x6C, 2, gUnk_0203C3C8);
        break;
    case 9:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gSioDbgWinCount2P > 1) {
                gSioDbgWinCount2P--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gSioDbgWinCount2P <= 998) {
                gSioDbgWinCount2P++;
            }
        }

        DebugTextPrintNumber(0x78, 0x75, 2, gSioDbgWinCount2P);
        break;
    case 10:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnk_0203C3D4 > 1) {
                gUnk_0203C3D4--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnk_0203C3D4 <= 998) {
                gUnk_0203C3D4++;
            }
        }

        DebugTextPrintNumber(0x78, 0x7E, 2, gUnk_0203C3D4);
        break;
#else
    case 0:
        if (GetKeysHeld() & DPAD_LEFT) {
            if (gUnk_0203C3C8 > 1) {
                gUnk_0203C3C8--;
            }
        }

        if (GetKeysHeld() & DPAD_RIGHT) {
            if (gUnk_0203C3C8 <= 98) {
                gUnk_0203C3C8++;
            }
        }

        DebugTextPrintNumber(0x64, 0x24, 2, gUnk_0203C3C8);
        break;
    case 1:
        if (GetKeysHeld() & DPAD_LEFT) {
            if (gUnk_0203C3CC > 5) {
                gUnk_0203C3CC -= 5;
            }
        }

        if (GetKeysHeld() & DPAD_RIGHT) {
            if (gUnk_0203C3CC <= 994) {
                gUnk_0203C3CC += 5;
            }
        }

        DebugTextPrintNumber(0x64, 0x2D, 2, gUnk_0203C3CC);
        break;
    case 2:
        if (GetKeysHeld() & DPAD_LEFT) {
            if (gSioDbgCp > 5) {
                gSioDbgCp -= 5;
            }
        }

        if (GetKeysHeld() & DPAD_RIGHT) {
            if (gSioDbgCp <= 994) {
                gSioDbgCp += 5;
            }
        }

        DebugTextPrintNumber(0x64, 0x36, 2, gSioDbgCp);
        break;
    case 3:
        break;
    case 4:
        break;
#endif
    }

    if (GetKeysPressed() & (A_BUTTON | B_BUTTON | START_BUTTON)) {
        gSioDebugMode = TRUE;
        InitDebugDecks();
        ModeRequest(&gModeSioBtlConnect, 0);
    } else {
        DebugTextDraw(0);
        DebugTextClear();
    }
}

void mode_sio_dbg_flg_2() {
    DebugTextDestroy();
}

#ifdef VERSION_EU
void SioDbgApplySettings() {
    gCharaLinkSend.level = gSioDbgLevel1P;
    gCharaLinkSend.maxHp = gCharaLinkSend.hp = gUnk_0203C3C4;
    gGameState.progression.cp = gSioDbgCp;
    gCharaLinkSend.winCount = gUnk_0203C3CC;
    gCharaLinkSend.loseCount = gSioDbgLoseCount1P;
    gCharaLinkSend.learnedStocks = -1;
    gCharaLinkSend.learnedStocks2 = -1;
    gCharaLinkSend.ap = 4;
    gCharaLinkSend.seed = 0x1234;
    gCharaLinkSend.worldFlags = 0x1FFE;
    gCharaLinkRecv.level = gSioDbgLevel2P;
    gCharaLinkRecv.maxHp = gCharaLinkRecv.hp = gSioDbgHp2P;
    gCharaLinkRecv.winCount = gSioDbgWinCount2P;
    gCharaLinkRecv.loseCount = gUnk_0203C3D4;
    gCharaLinkRecv.learnedStocks = -1;
    gCharaLinkRecv.learnedStocks2 = -1;
    gCharaLinkRecv.ap = 4;
    gCharaLinkRecv.seed = 0x1234;
    gCharaLinkRecv.worldFlags = 0x1FFE;
}
#else
void SioDbgApplySettings() {
    gCharaLinkSend.level = gUnk_0203C3C8;
    gCharaLinkSend.maxHp = gUnk_0203C3CC;
}
#endif
