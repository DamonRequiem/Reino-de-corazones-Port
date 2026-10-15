/**
 * mode_debflag.c
 * Debug Flag Settings
 */

#include "macros.h"
#include "map_api.h"
#include "mode_chkbtl.h"
#include "mode_debflag.h"
#include "gba/keys.h"
#include "display.h"
#include "key.h"
#include "mode.h"
#include "system_state.h"
#include "types.h"
#include "debug_text.h"

static s8 sDebflagCursor;
static s8 sDebflagCount;
static const DebugFlag* sDebflagList;
#ifdef VERSION_EU
static u32 sUnkEu_020348D4;
#endif

u8 gDebflagReturnToMap EWRAM_COMMON(4);

static const DebugFlag sDebugFlagList[14] = {
    { "\x82\x6c\x82\x74\x82\x73\x82\x64\x82\x6a\x82\x68\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_INVINCIBLE },
    { "\x82\x64\x82\x6d\x82\x64\x82\x6c\x82\x78\x82\x6c\x82\x74\x82\x73\x82\x64\x82\x6a\x82\x68\x81\x46", DEBUG_FLAG_ENEMY_INVINCIBLE },
    { "\x82\x66\x82\x64\x82\x6d\x82\x73\x82\x6b\x82\x64\x82\x64\x82\x6d\x82\x64\x82\x6c\x82\x78\x81\x46", DEBUG_FLAG_GENTLE_ENEMY },
    { "\x82\x63\x82\x68\x82\x72\x82\x6f\x82\x63\x82\x6c\x82\x66\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_DISP_DMG },
    { "\x82\x60\x82\x6b\x82\x6b\x82\x60\x82\x61\x82\x68\x82\x6b\x82\x68\x82\x73\x82\x78\x81\x40\x81\x46", DEBUG_FLAG_ALL_ABILITY },
    { "\x82\x6b\x82\x64\x82\x75\x82\x64\x82\x6b\x82\x6c\x82\x60\x82\x77\x81\x40\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_LEVEL_MAX },
    { "\x82\x6d\x82\x6e\x82\x64\x82\x6d\x82\x62\x82\x6e\x82\x6d\x82\x73\x81\x40\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_NO_ENCOUNT },
    { "\x82\x60\x82\x6b\x82\x6b\x82\x61\x82\x73\x82\x6b\x82\x62\x82\x60\x82\x71\x82\x63\x81\x40\x81\x46", DEBUG_FLAG_ALL_BTL_CARD },
    { "\x82\x60\x82\x6b\x82\x6b\x82\x6c\x82\x60\x82\x6f\x82\x62\x82\x60\x82\x71\x82\x63\x81\x40\x81\x46", DEBUG_FLAG_ALL_MAP_CARD },
    { "\x82\x6f\x82\x71\x82\x64\x82\x6c\x82\x68\x82\x74\x82\x6c\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_PREMIUM },
    { "\x82\x62\x82\x6e\x82\x6c\x82\x6f\x82\x6c\x82\x64\x82\x6c\x82\x6e\x81\x40\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_COMP_MEMO },
    { "\x82\x71\x82\x68\x82\x6a\x82\x74\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_RIKU },
    { "\x82\x78\x82\x60\x82\x6c\x82\x68\x82\x71\x82\x68\x82\x6a\x82\x74\x81\x40\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_YAMI_RIKU },
    { "\x82\x64\x82\x6d\x82\x64\x82\x6c\x82\x78\x82\x62\x82\x60\x82\x71\x82\x63\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_ENEMY_CARD },
};

static const DebugFlag sDebugFlagListMap[7] = {
    { "\x82\x6c\x82\x74\x82\x73\x82\x64\x82\x6a\x82\x68\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_INVINCIBLE },
    { "\x82\x64\x82\x6d\x82\x64\x82\x6c\x82\x78\x82\x6c\x82\x74\x82\x73\x82\x64\x82\x6a\x82\x68\x81\x46", DEBUG_FLAG_ENEMY_INVINCIBLE },
    { "\x82\x66\x82\x64\x82\x6d\x82\x73\x82\x6b\x82\x64\x82\x64\x82\x6d\x82\x64\x82\x6c\x82\x78\x81\x46", DEBUG_FLAG_GENTLE_ENEMY },
    { "\x82\x63\x82\x68\x82\x72\x82\x6f\x82\x63\x82\x6c\x82\x66\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_DISP_DMG },
    { "\x82\x6d\x82\x6e\x82\x64\x82\x6d\x82\x62\x82\x6e\x82\x74\x82\x6d\x82\x73\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_NO_ENCOUNT },
    { "\x82\x6f\x82\x71\x82\x64\x82\x6c\x82\x68\x82\x74\x82\x6c\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_PREMIUM },
    { "\x82\x64\x82\x6d\x82\x64\x82\x6c\x82\x78\x82\x62\x82\x60\x82\x71\x82\x63\x81\x40\x81\x40\x81\x46", DEBUG_FLAG_ENEMY_CARD },
};

void mode_debflag_0(s32 arg) {
    s32 i;

    SetBgMode0();
    SetupBg(0, 0, 0x0F, 0);
    EnableBg(0);
    DebugTextInit(0, 0x5400, 0x500);
    DebugTextLoadPalette(0, gWhitePalette, sizeof(gWhitePalette), 0x0F);
    sDebflagCursor = 0;
    DebugTextPrint(0, 0, 2, "\x81\x84");

    if (arg != 0) {
        sDebflagCount = 7;
        sDebflagList = sDebugFlagListMap;
        gDebflagReturnToMap = TRUE;
    } else {
        sDebflagCount = 14;
        sDebflagList = sDebugFlagList;
        gDebflagReturnToMap = FALSE;
    }

    for (i = 0; i < sDebflagCount; i++) {
        DebugTextPrint(0x0C, i * 9, 2, sDebflagList[i].name);

        if (gDebugFlags & sDebflagList[i].mask) {
            DebugTextPrint(0x78, i * 9, 2, "\x82\x6e\x82\x6d\x81\x40");
        } else {
            DebugTextPrint(0x78, i * 9, 2, "\x82\x6e\x82\x65\x82\x65");
        }
    }
}

void mode_debflag_1() {
    u8 prev;
    const DebugFlag* entry;

    prev = sDebflagCursor;

    if (GetKeysRepeat() & DPAD_UP) {
        sDebflagCursor--;
    }

    if (GetKeysRepeat() & DPAD_DOWN) {
        sDebflagCursor++;
    }

    if (prev != sDebflagCursor) {
        if (sDebflagCursor < 0) {
            sDebflagCursor = sDebflagCount - 1;
        } else if (sDebflagCursor >= sDebflagCount) {
            sDebflagCursor = 0;
        }

        DebugTextPrint(0, prev * 9, 2, "\x81\x40");
        DebugTextPrint(0, sDebflagCursor * 9, 2, "\x81\x84");
    }

    if (GetKeysPressed() & (DPAD_RIGHT | DPAD_LEFT)) {
        entry = &sDebflagList[sDebflagCursor];
        gDebugFlags ^= entry->mask;

        if (gDebugFlags & entry->mask) {
            DebugTextPrint(0x78, sDebflagCursor * 9, 2, "\x82\x6e\x82\x6d\x81\x40");
        } else {
            DebugTextPrint(0x78, sDebflagCursor * 9, 2, "\x82\x6e\x82\x65\x82\x65");
        }
    }

    if (GetKeysPressed() & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)) {
        if (gDebflagReturnToMap) {
            RequestMapMode();
        } else {
            ModeRequest(&gModeDebug, 0);
        }
    } else {
        DebugTextDraw(0);
        DebugTextClear();
    }
}

void mode_debflag_2() {
    DebugTextDestroy();
}

Mode gModeDebflag = { "mode_debflag", mode_debflag_0, mode_debflag_1, mode_debflag_2 };
