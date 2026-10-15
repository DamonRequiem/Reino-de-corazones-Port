/**
 * key.c
 * Key Input
 */

#include "gba/keys.h"
#include "gba/io_reg.h"
#include "types.h"

static u16 sKeysHeld;
static u16 sKeysPressed;
static u16 sKeysRepeat;
static u16 sKeyChordLatch;
static u8 sKeyHoldLeft;
static u8 sKeyHoldRight;
static u8 sKeyHoldUp;
static u8 sKeyHoldDown;
static u8 sKeyHoldA;
static u8 sKeyHoldB;
static u8 sKeyHoldL;
static u8 sKeyHoldR;
static u8 sKeyHoldStart;
static u8 sKeyHoldSelect;
static u8 sKeyReleaseLeft;
static u8 sKeyReleaseRight;
static u8 sKeyReleaseUp;
static u8 sKeyReleaseDown;
static u8 sKeyReleaseA;
static u8 sKeyReleaseB;
static u8 sKeyReleaseL;
static u8 sKeyReleaseR;
static u8 sKeyReleaseStart;
static u8 sKeyReleaseSelect;

u16 GetKeysHeld() {
    return sKeysHeld;
}

u16 GetKeysPressed() {
    return sKeysPressed;
}

u16 GetKeysRepeat() {
    return sKeysRepeat;
}

void ResetKeyState() {
    sKeysHeld = 0;
    sKeysPressed = 0;
    sKeysRepeat = 0;
    sKeyChordLatch = 0;
    sKeyHoldLeft = 0;
    sKeyHoldRight = 0;
    sKeyHoldUp = 0;
    sKeyHoldDown = 0;
    sKeyHoldL = 0;
    sKeyHoldR = 0;
    sKeyHoldA = 0;
    sKeyHoldB = 0;
    sKeyHoldStart = 0;
    sKeyHoldSelect = 0;
    sKeyReleaseLeft = 0xFF;
    sKeyReleaseRight = 0xFF;
    sKeyReleaseUp = 0xFF;
    sKeyReleaseDown = 0xFF;
    sKeyReleaseL = 0xFF;
    sKeyReleaseR = 0xFF;
    sKeyReleaseA = 0xFF;
    sKeyReleaseB = 0xFF;
    sKeyReleaseStart = 0xFF;
    sKeyReleaseSelect = 0xFF;
}

u8 GetKeyHoldTime(u16 key) {
    switch (key) {
    case DPAD_LEFT:
        return sKeyHoldLeft;
    case DPAD_RIGHT:
        return sKeyHoldRight;
    case DPAD_UP:
        return sKeyHoldUp;
    case DPAD_DOWN:
        return sKeyHoldDown;
    case L_BUTTON:
        return sKeyHoldL;
    case R_BUTTON:
        return sKeyHoldR;
    case A_BUTTON:
        return sKeyHoldA;
    case B_BUTTON:
        return sKeyHoldB;
    case START_BUTTON:
        return sKeyHoldStart;
    case SELECT_BUTTON:
        return sKeyHoldSelect;
    }
}

u8 GetKeyReleaseTime(u16 key) {
    switch (key) {
    case DPAD_LEFT:
        return sKeyReleaseLeft;
    case DPAD_RIGHT:
        return sKeyReleaseRight;
    case DPAD_UP:
        return sKeyReleaseUp;
    case DPAD_DOWN:
        return sKeyReleaseDown;
    case L_BUTTON:
        return sKeyReleaseL;
    case R_BUTTON:
        return sKeyReleaseR;
    case A_BUTTON:
        return sKeyReleaseA;
    case B_BUTTON:
        return sKeyReleaseB;
    case START_BUTTON:
        return sKeyReleaseStart;
    case SELECT_BUTTON:
        return sKeyReleaseSelect;
    }
}

u16 ReadKeyChord(u16 key1, u16 key2) {
    u16 keys = 0;
    u8 release1 = GetKeyReleaseTime(key1);
    u8 release2 = GetKeyReleaseTime(key2);

    if (release1 == 2) {
        sKeyChordLatch &= ~key1;
    }

    if (release2 == 2) {
        sKeyChordLatch &= ~key2;
    }

    if (((GetKeysPressed() & key1) && (GetKeysHeld() & key2)) || ((GetKeysPressed() & key2) && (GetKeysHeld() & key1))) {
        sKeyChordLatch |= key1 | key2;
        keys = key1 | key2;
    }

    if ((sKeyChordLatch & key1) == 0) {
        if (GetKeyHoldTime(key1) == 5 || release1 == 1) {
            sKeyChordLatch |= key1;
            keys = key1;
        }
    }

    if ((sKeyChordLatch & key2) == 0) {
        if (GetKeyHoldTime(key2) == 5 || release2 == 1) {
            sKeyChordLatch |= key2;
            keys = key2;
        }
    }

    return keys;
}

u16 ReadDpadChord() {
    u16 keys = 0;
    u8 up = GetKeyReleaseTime(DPAD_UP);
    u8 down = GetKeyReleaseTime(DPAD_DOWN);
    u8 left = GetKeyReleaseTime(DPAD_LEFT);
    u8 right = GetKeyReleaseTime(DPAD_RIGHT);

    if (up == 2) {
        sKeyChordLatch &= ~DPAD_UP;
    }

    if (down == 2) {
        sKeyChordLatch &= ~DPAD_DOWN;
    }

    if (left == 2) {
        sKeyChordLatch &= ~DPAD_LEFT;
    }

    if (right == 2) {
        sKeyChordLatch &= ~DPAD_RIGHT;
    }

    if (((GetKeysPressed() & DPAD_UP) && (GetKeysHeld() & DPAD_LEFT)) || ((GetKeysPressed() & DPAD_LEFT) && (GetKeysHeld() & DPAD_UP))) {
        sKeyChordLatch |= (DPAD_UP | DPAD_LEFT);
        keys = (DPAD_UP | DPAD_LEFT);
    }

    if (((GetKeysPressed() & DPAD_UP) && (GetKeysHeld() & DPAD_RIGHT)) || ((GetKeysPressed() & DPAD_RIGHT) && (GetKeysHeld() & DPAD_UP))) {
        sKeyChordLatch |= (DPAD_UP | DPAD_RIGHT);
        keys = (DPAD_UP | DPAD_RIGHT);
    }

    if (((GetKeysPressed() & DPAD_DOWN) && (GetKeysHeld() & DPAD_LEFT)) || ((GetKeysPressed() & DPAD_LEFT) && (GetKeysHeld() & DPAD_DOWN))) {
        sKeyChordLatch |= (DPAD_DOWN | DPAD_LEFT);
        keys = (DPAD_DOWN | DPAD_LEFT);
    }

    if (((GetKeysPressed() & DPAD_DOWN) && (GetKeysHeld() & DPAD_RIGHT)) || ((GetKeysPressed() & DPAD_RIGHT) && (GetKeysHeld() & DPAD_DOWN))) {
        sKeyChordLatch |= (DPAD_DOWN | DPAD_RIGHT);
        keys = (DPAD_DOWN | DPAD_RIGHT);
    }

    if ((sKeyChordLatch & DPAD_UP) == 0) {
        if (GetKeyHoldTime(DPAD_UP) == 10 || up == 1) {
            sKeyChordLatch |= DPAD_UP;
            keys = DPAD_UP;
        }
    }

    if ((sKeyChordLatch & DPAD_DOWN) == 0) {
        if (GetKeyHoldTime(DPAD_DOWN) == 10 || down == 1) {
            sKeyChordLatch |= DPAD_DOWN;
            keys = DPAD_DOWN;
        }
    }

    if ((sKeyChordLatch & DPAD_LEFT) == 0) {
        if (GetKeyHoldTime(DPAD_LEFT) == 10 || left == 1) {
            sKeyChordLatch |= DPAD_LEFT;
            keys = DPAD_LEFT;
        }
    }

    if ((sKeyChordLatch & DPAD_RIGHT) == 0) {
        if (GetKeyHoldTime(DPAD_RIGHT) == 10 || right == 1) {
            sKeyChordLatch |= DPAD_RIGHT;
            keys = DPAD_RIGHT;
        }
    }

    return keys;
}

void UpdateKeyState() {
    u16 keys;

    keys = REG_KEYINPUT ^ KEYS_MASK;
    sKeysPressed = keys & ~sKeysHeld;
    sKeysHeld = keys;

    if (sKeysHeld & DPAD_LEFT) {
        sKeyHoldLeft++;
        sKeyReleaseLeft = 0;

        if (sKeyHoldLeft > 32) {
            sKeyHoldLeft = 29;
        }
    } else {
        sKeyHoldLeft = 0;

        if (sKeyReleaseLeft < 255) {
            sKeyReleaseLeft++;
        }
    }

    if (sKeysHeld & DPAD_RIGHT) {
        sKeyHoldRight++;
        sKeyReleaseRight = 0;

        if (sKeyHoldRight > 32) {
            sKeyHoldRight = 29;
        }
    } else {
        sKeyHoldRight = 0;

        if (sKeyReleaseRight < 255) {
            sKeyReleaseRight++;
        }
    }

    if (sKeysHeld & DPAD_UP) {
        sKeyHoldUp++;
        sKeyReleaseUp = 0;

        if (sKeyHoldUp > 32) {
            sKeyHoldUp = 29;
        }
    } else {
        sKeyHoldUp = 0;

        if (sKeyReleaseUp < 255) {
            sKeyReleaseUp++;
        }
    }

    if (sKeysHeld & DPAD_DOWN) {
        sKeyHoldDown++;
        sKeyReleaseDown = 0;

        if (sKeyHoldDown > 32) {
            sKeyHoldDown = 29;
        }
    } else {
        sKeyHoldDown = 0;

        if (sKeyReleaseDown < 255) {
            sKeyReleaseDown++;
        }
    }

    if (sKeysHeld & L_BUTTON) {
        sKeyHoldL++;
        sKeyReleaseL = 0;

        if (sKeyHoldL > 32) {
            sKeyHoldL = 29;
        }
    } else {
        sKeyHoldL = 0;

        if (sKeyReleaseL < 255) {
            sKeyReleaseL++;
        }
    }

    if (sKeysHeld & R_BUTTON) {
        sKeyHoldR++;
        sKeyReleaseR = 0;

        if (sKeyHoldR > 32) {
            sKeyHoldR = 29;
        }
    } else {
        sKeyHoldR = 0;

        if (sKeyReleaseR < 255) {
            sKeyReleaseR++;
        }
    }

    if (sKeysHeld & A_BUTTON) {
        sKeyHoldA++;
        sKeyReleaseA = 0;

        if (sKeyHoldA > 32) {
            sKeyHoldA = 29;
        }
    } else {
        sKeyHoldA = 0;

        if (sKeyReleaseA < 255) {
            sKeyReleaseA++;
        }
    }

    if (sKeysHeld & B_BUTTON) {
        sKeyHoldB++;
        sKeyReleaseB = 0;

        if (sKeyHoldB > 32) {
            sKeyHoldB = 29;
        }
    } else {
        sKeyHoldB = 0;

        if (sKeyReleaseB < 255) {
            sKeyReleaseB++;
        }
    }

    if (sKeysHeld & START_BUTTON) {
        sKeyHoldStart++;
        sKeyReleaseStart = 0;

        if (sKeyHoldStart > 32) {
            sKeyHoldStart = 29;
        }
    } else {
        sKeyHoldStart = 0;

        if (sKeyReleaseStart < 255) {
            sKeyReleaseStart++;
        }
    }

    if (sKeysHeld & SELECT_BUTTON) {
        sKeyHoldSelect++;
        sKeyReleaseSelect = 0;

        if (sKeyHoldSelect > 32) {
            sKeyHoldSelect = 29;
        }
    } else {
        sKeyHoldSelect = 0;

        if (sKeyReleaseSelect < 255) {
            sKeyReleaseSelect++;
        }
    }

    sKeysRepeat = 0;

    if (sKeyHoldLeft == 1 || sKeyHoldLeft == 32) {
        sKeysRepeat |= DPAD_LEFT;
    }

    if (sKeyHoldRight == 1 || sKeyHoldRight == 32) {
        sKeysRepeat |= DPAD_RIGHT;
    }

    if (sKeyHoldUp == 1 || sKeyHoldUp == 32) {
        sKeysRepeat |= DPAD_UP;
    }

    if (sKeyHoldDown == 1 || sKeyHoldDown == 32) {
        sKeysRepeat |= DPAD_DOWN;
    }

    if (sKeyHoldL == 1 || sKeyHoldL == 32) {
        sKeysRepeat |= L_BUTTON;
    }

    if (sKeyHoldR == 1 || sKeyHoldR == 32) {
        sKeysRepeat |= R_BUTTON;
    }

    if (sKeyHoldA == 1 || sKeyHoldA == 32) {
        sKeysRepeat |= A_BUTTON;
    }

    if (sKeyHoldB == 1 || sKeyHoldB == 32) {
        sKeysRepeat |= B_BUTTON;
    }

    if (sKeyHoldStart == 1 || sKeyHoldStart == 32) {
        sKeysRepeat |= START_BUTTON;
    }

    if (sKeyHoldSelect == 1 || sKeyHoldSelect == 32) {
        sKeysRepeat |= SELECT_BUTTON;
    }
}
