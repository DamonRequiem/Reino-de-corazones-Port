/**
 * mode_backupstat.c
 * Debug Save Backup Status
 */

#include "mode_chkbtl.h"
#include "mode_backupstat.h"
#include "gba/keys.h"
#include "display.h"
#include "key.h"
#include "mode.h"
#include "save_api.h"
#include "types.h"
#include "debug_text.h"

static const char* sBackupStatStateNames[3] = {
    "\x82\xC8\x82\xB5\x81\x40",
    "\x82\xB1\x82\xED\x82\xEA",
    "\x82\xA0\x82\xE8\x81\x40",
};

static const BackupStatEntry sBackupStatEntryTable[6] = {
    {"\x82\x72\x82\x78\x82\x72\x82\x73\x82\x64\x82\x6C\x81\x40", 2},
    {"\x82\x72\x82\x6E\x82\x71\x82\x60\x81\x40\x81\x40\x82\x50", 64},
    {"\x82\x72\x82\x6E\x82\x71\x82\x60\x81\x40\x81\x40\x82\x51", 64},
    {"\x82\x71\x82\x68\x82\x6A\x82\x74\x81\x40\x81\x40\x82\x50", 512},
    {"\x82\x71\x82\x68\x82\x6A\x82\x74\x81\x40\x81\x40\x82\x51", 512},
    {"\x82\x72\x82\x74\x82\x72\x82\x6F\x82\x64\x82\x6D\x82\x63", 4},
};

static s8 sBackupStatCursor;
static s8 sBackupStatCount;
static const BackupStatEntry* sBackupStatEntries;
static s16 sBackupStatStates[12];

void mode_backupstat_0() {
    s32 i;
    s32 j;

    SetBgMode0();
    SetupBg(0, 0, 15, 0);
    EnableBg(0);
    DebugTextInit(0, 0x5400, 0x500);
    DebugTextLoadPalette(0, gWhitePalette, sizeof(gWhitePalette), 15);
    sBackupStatCursor = 0;
    DebugTextPrint(0, 0, 2, "\x81\x84");
    sBackupStatCount = 6;
    sBackupStatEntries = sBackupStatEntryTable;

    for (i = 0; i < sBackupStatCount; i++) {
        for (j = 0; j <= 1; j++) {
            switch (i) {
            case 0:
                sBackupStatStates[i * 2 + j] = SaveCheckHeaderSlot(j);
                break;
            case 1:
                sBackupStatStates[i * 2 + j] = SaveCheckFileLargeSlot(0, j);
                break;
            case 2:
                sBackupStatStates[i * 2 + j] = SaveCheckFileLargeSlot(1, j);
                break;
            case 3:
                sBackupStatStates[i * 2 + j] = SaveCheckFileSmallSlot(0, j);
                break;
            case 4:
                sBackupStatStates[i * 2 + j] = SaveCheckFileSmallSlot(1, j);
                break;
            case 5:
                sBackupStatStates[i * 2 + j] = SaveCheckSystemSlot(j);
                break;
            }
        }
    }

    for (i = 0; i < sBackupStatCount * 2; i++) {
        DebugTextPrint(12, i * 9, 2, sBackupStatEntries[i / 2].name);

        switch (i % 2) {
        case 0:
            DebugTextPrint(75, i * 9, 2, "\x81\x7C\x82\x50");
            break;
        case 1:
            DebugTextPrint(75, i * 9, 2, "\x81\x7C\x82\x51");
            break;
        }

        DebugTextPrint(120, i * 9, 2, sBackupStatStateNames[sBackupStatStates[i]]);
    }
}

void BackupStatApplyState() {
    u16 slot;

    slot = sBackupStatCursor % 2;

    switch (sBackupStatCursor / 2) {
    case 0:
        SaveSetHeaderState(slot, sBackupStatStates[sBackupStatCursor]);
        break;
    case 1:
        SaveSetFileLargeState(0, slot, sBackupStatStates[sBackupStatCursor]);
        break;
    case 2:
        SaveSetFileLargeState(1, slot, sBackupStatStates[sBackupStatCursor]);
        break;
    case 3:
        SaveSetFileSmallState(0, slot, sBackupStatStates[sBackupStatCursor]);
        break;
    case 4:
        SaveSetFileSmallState(1, slot, sBackupStatStates[sBackupStatCursor]);
        break;
    case 5:
        SaveSetSystemState(slot, sBackupStatStates[sBackupStatCursor]);
        break;
    }

    DebugTextPrint(120, sBackupStatCursor * 9, 2, sBackupStatStateNames[sBackupStatStates[sBackupStatCursor]]);
}

void mode_backupstat_1() {
    u8 prev;

    prev = sBackupStatCursor;

    if (GetKeysRepeat() & DPAD_UP) {
        sBackupStatCursor--;
    } else if (GetKeysRepeat() & DPAD_DOWN) {
        sBackupStatCursor++;
    }

    if (prev != sBackupStatCursor) {
        if (sBackupStatCursor < 0) {
            sBackupStatCursor = sBackupStatCount * 2 - 1;
        } else if (sBackupStatCursor >= sBackupStatCount * 2) {
            sBackupStatCursor = 0;
        }

        DebugTextPrint(0, prev * 9, 2, "\x81\x40");
        DebugTextPrint(0, sBackupStatCursor * 9, 2, "\x81\x84");
    }

    if ((GetKeysPressed() & DPAD_LEFT) != 0) {
        if (--sBackupStatStates[sBackupStatCursor] < 0) {
            sBackupStatStates[sBackupStatCursor] = 2;
        }

        BackupStatApplyState();
    } else if (GetKeysPressed() & DPAD_RIGHT) {
        if (++sBackupStatStates[sBackupStatCursor] > 2) {
            sBackupStatStates[sBackupStatCursor] = 0;
        }

        BackupStatApplyState();
    }

    if (GetKeysPressed() & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)) {
        ModeRequest(&gModeDebug, 0);
    } else {
        DebugTextDraw(0);
        DebugTextClear();
    }
}

void mode_backupstat_2() {
    DebugTextDestroy();
}

Mode gModeBackupstat = {
    "mode_backupstat",
    (ModeInitFunc)mode_backupstat_0,
    mode_backupstat_1,
    mode_backupstat_2,
};
