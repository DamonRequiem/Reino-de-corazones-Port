/**
 * mode_test.c
 * Debug HP Gauge Sprite Test
 */

#include "mode_test.h"
#include "gba/keys.h"
#include "sprites_mode_test.h"
#include "engine_math.h"
#include "key.h"
#include "mode.h"
#include "obj.h"
#include "obj_api.h"
#include <stddef.h>
#include "types.h"
#include "sprite_palettes.h"

#ifndef VERSION_EU
static struct ObjTiles* sTestTiles;
static struct ObjPalette* sTestPalette;
static s32 sTestFrame;
#endif

#ifndef VERSION_EU
void mode_test_0() {
    sTestFrame = 0;
    sTestTiles = LoadObjTiles(gBHpgagETiles, sizeof(gBHpgagETiles));
    sTestPalette = LoadObjPalette(gBStatesPalette, sizeof(gBStatesPalette));
}
#endif

#ifndef VERSION_EU
void mode_test_1() {
    if (GetKeysRepeat() & DPAD_LEFT) {
        sTestFrame--;
    } else if (GetKeysRepeat() & DPAD_RIGHT) {
        sTestFrame++;
    }

    if (sTestFrame < 0) {
        sTestFrame = 0;
    }

    if (sTestFrame > 13) {
        sTestFrame = 13;
    }

    DrawSprite(120, 80, gBHpgagEFrames[sTestFrame], sTestTiles, sTestPalette, NULL, 0, 0);
}
#endif

#ifndef VERSION_EU
void mode_test_2() {
    ReleaseObjTiles(sTestTiles);
    ReleaseObjPalette(sTestPalette);
}
#endif

void ApproachValueHalf(s32* value, s32 target) {
    *value += (target - *value) >> 1;
}

#ifndef VERSION_EU
Mode gModeTest = { "mode_test", (ModeInitFunc)mode_test_0, mode_test_1, mode_test_2 };
#endif
