/**
 * romcri.c
 * Room Creation Effects
 */

#include "pallet.h"
#include "romcri.h"
#include "romcri_backgrounds.h"
#include "display.h"
#include "game_state.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "fld_types.h"

void task_romcri_eff_0(RomcriEffWork* work, s32 angle) {
    SetupBg(1, 0, 23, 12);
    work->angle = angle;
    work->timer = 0;
    DisableBg(1);
    PushPaletteEffect(0);
    LoadBgPalette(1, gRomcriEffPalette, sizeof(gRomcriEffPalette));
    PopPaletteEffect();
    SetBgPriority(1, 0);
    SetBgBlend(1, 16, 16);

    switch (work->angle) {
    case FLD_ANGLE_DOWN_LEFT:
        LoadBgTiles(1, gRomcriEffDownTiles, sizeof(gRomcriEffDownTiles));
        SetBgScroll(1, (u16)-35, (u16)-23);
        break;
    case FLD_ANGLE_DOWN_RIGHT:
        LoadBgTiles(1, gRomcriEffDownTiles, sizeof(gRomcriEffDownTiles));
        SetBgScroll(1, (u16)-77, (u16)-23);
        break;
    case FLD_ANGLE_UP_LEFT:
        LoadBgTiles(1, gRomcriEffUpTiles, sizeof(gRomcriEffUpTiles));
        SetBgScroll(1, (u16)-39, 2);
        break;
    case FLD_ANGLE_UP_RIGHT:
        LoadBgTiles(1, gRomcriEffUpTiles, sizeof(gRomcriEffUpTiles));
#ifdef VERSION_EU
        SetBgScroll(1, (u16)-73, 5);
#else
        SetBgScroll(1, (u16)-71, 3);
#endif
        break;
    }
}

u8 task_romcri_eff_1(RomcriEffWork* work) {
    switch (work->angle) {
    case FLD_ANGLE_DOWN_LEFT:
        switch (work->timer) {
        case 0:
            LoadBgMap(1, gRomcriEffDownLeftMap0, sizeof(gRomcriEffDownLeftMap0));
            break;
        case 4:
            LoadBgMap(1, gRomcriEffDownLeftMap1, sizeof(gRomcriEffDownLeftMap1));
            break;
        case 8:
            LoadBgMap(1, gRomcriEffDownLeftMap2, sizeof(gRomcriEffDownLeftMap2));
            break;
        case 12:
            LoadBgMap(1, gRomcriEffDownLeftMap3, sizeof(gRomcriEffDownLeftMap3));
            break;
        case 16:
            LoadBgTiles(1, gRomcriEffDown2Tiles, sizeof(gRomcriEffDown2Tiles));
            LoadBgMap(1, gRomcriEffDownLeftMap4, sizeof(gRomcriEffDownLeftMap4));
            break;
        case 20:
            LoadBgMap(1, gRomcriEffDownLeftMap5, sizeof(gRomcriEffDownLeftMap5));
            break;
        case 24:
            LoadBgMap(1, gRomcriEffDownLeftMap6, sizeof(gRomcriEffDownLeftMap6));
            break;
        case 28:
            LoadBgMap(1, gRomcriEffDownLeftMap7, sizeof(gRomcriEffDownLeftMap7));
            break;
        case 32:
            return 0;
        }

        break;
    case FLD_ANGLE_DOWN_RIGHT:
        switch (work->timer) {
        case 0:
            LoadBgMap(1, gRomcriEffDownRightMap0, sizeof(gRomcriEffDownRightMap0));
            break;
        case 4:
            LoadBgMap(1, gRomcriEffDownRightMap1, sizeof(gRomcriEffDownRightMap1));
            break;
        case 8:
            LoadBgMap(1, gRomcriEffDownRightMap2, sizeof(gRomcriEffDownRightMap2));
            break;
        case 12:
            LoadBgMap(1, gRomcriEffDownRightMap3, sizeof(gRomcriEffDownRightMap3));
            break;
        case 16:
            LoadBgTiles(1, gRomcriEffDown2Tiles, sizeof(gRomcriEffDown2Tiles));
            LoadBgMap(1, gRomcriEffDownRightMap4, sizeof(gRomcriEffDownRightMap4));
            break;
        case 20:
            LoadBgMap(1, gRomcriEffDownRightMap5, sizeof(gRomcriEffDownRightMap5));
            break;
        case 24:
            LoadBgMap(1, gRomcriEffDownRightMap6, sizeof(gRomcriEffDownRightMap6));
            break;
        case 28:
            LoadBgMap(1, gRomcriEffDownRightMap7, sizeof(gRomcriEffDownRightMap7));
            break;
        case 32:
            return 0;
        }

        break;
    case FLD_ANGLE_UP_RIGHT:
        switch (work->timer) {
        case 0:
            LoadBgMap(1, gRomcriEffUpRightMap0, sizeof(gRomcriEffUpRightMap0));
            break;
        case 4:
            LoadBgMap(1, gRomcriEffUpRightMap1, sizeof(gRomcriEffUpRightMap1));
            break;
        case 8:
            LoadBgMap(1, gRomcriEffUpRightMap2, sizeof(gRomcriEffUpRightMap2));
            break;
        case 12:
            LoadBgMap(1, gRomcriEffUpRightMap3, sizeof(gRomcriEffUpRightMap3));
            break;
        case 16:
            LoadBgMap(1, gRomcriEffUpRightMap4, sizeof(gRomcriEffUpRightMap4));
            break;
        case 20:
            LoadBgMap(1, gRomcriEffUpRightMap5, sizeof(gRomcriEffUpRightMap5));
            break;
        case 24:
            LoadBgMap(1, gRomcriEffUpRightMap6, sizeof(gRomcriEffUpRightMap6));
            break;
        case 28:
            LoadBgMap(1, gRomcriEffUpRightMap7, sizeof(gRomcriEffUpRightMap7));
            break;
        case 32:
            return 0;
        }

        break;
    case FLD_ANGLE_UP_LEFT:
        switch (work->timer) {
        case 0:
            LoadBgMap(1, gRomcriEffUpLeftMap0, sizeof(gRomcriEffUpLeftMap0));
            break;
        case 4:
            LoadBgMap(1, gRomcriEffUpLeftMap1, sizeof(gRomcriEffUpLeftMap1));
            break;
        case 8:
            LoadBgMap(1, gRomcriEffUpLeftMap2, sizeof(gRomcriEffUpLeftMap2));
            break;
        case 12:
            LoadBgMap(1, gRomcriEffUpLeftMap3, sizeof(gRomcriEffUpLeftMap3));
            break;
        case 16:
            LoadBgMap(1, gRomcriEffUpLeftMap4, sizeof(gRomcriEffUpLeftMap4));
            break;
        case 20:
            LoadBgMap(1, gRomcriEffUpLeftMap5, sizeof(gRomcriEffUpLeftMap5));
            break;
        case 24:
            LoadBgMap(1, gRomcriEffUpLeftMap6, sizeof(gRomcriEffUpLeftMap6));
            break;
        case 28:
            LoadBgMap(1, gRomcriEffUpLeftMap7, sizeof(gRomcriEffUpLeftMap7));
            break;
        case 32:
            return 0;
        }

        break;
    }

    work->timer++;
    return 1;
}

void task_romcri_eff_3() {
    DisableBg(1);
}

void task_romcri_eff2_0(RomcriEff2Work* work, s32 angle) {
    SetupBg(1, 0, 23, 12);
    work->timer = 0;
    work->frame = 0;
    work->angle = angle;
    DisableBg(1);
    PushPaletteEffect(0);
    LoadBgPalette(1, gRomcriEff2Palette, sizeof(gRomcriEff2Palette));
    PopPaletteEffect();
    SetBgPriority(1, 0);
    SetBgBlend(1, 16, 16);
    LoadBgTiles(1, gRomcriEff2Tiles, sizeof(gRomcriEff2Tiles));

    if (gGameState.flags & GAME_FLAG_RIKU) {
        switch (work->angle) {
        case FLD_ANGLE_UP_RIGHT:
            SetBgScroll(1, (u16)-100, 4);
            break;
        case FLD_ANGLE_UP_LEFT:
            SetBgScroll(1, (u16)-73, 5);
            break;
        case FLD_ANGLE_DOWN_RIGHT:
            SetBgScroll(1, (u16)-101, (u16)-18);
            break;
        case FLD_ANGLE_DOWN_LEFT:
            SetBgScroll(1, (u16)-75, (u16)-19);
            break;
        }
    } else {
        switch (work->angle) {
        case FLD_ANGLE_UP_RIGHT:
            SetBgScroll(1, (u16)-100, (u16)-6);
            break;
        case FLD_ANGLE_UP_LEFT:
            SetBgScroll(1, (u16)-73, (u16)-5);
            break;
        case FLD_ANGLE_DOWN_RIGHT:
            SetBgScroll(1, (u16)-101, (u16)-28);
            break;
        case FLD_ANGLE_DOWN_LEFT:
            SetBgScroll(1, (u16)-75, (u16)-29);
            break;
        }
    }
}

u8 task_romcri_eff2_1(RomcriEff2Work* work) {
    if (work->timer % 4 == 0) {
        switch (work->frame) {
        case 0:
            LoadBgMap(1, gRomcriEff2Map0, sizeof(gRomcriEff2Map0));
            break;
        case 1:
            EnableBg(1);
            LoadBgMap(1, gRomcriEff2Map1, sizeof(gRomcriEff2Map1));
            break;
        case 2:
            LoadBgMap(1, gRomcriEff2Map2, sizeof(gRomcriEff2Map2));
            break;
        case 3:
            LoadBgMap(1, gRomcriEff2Map3, sizeof(gRomcriEff2Map3));
            break;
        case 4:
            LoadBgMap(1, gRomcriEff2Map2, sizeof(gRomcriEff2Map2));
            break;
        case 5:
            LoadBgMap(1, gRomcriEff2Map1, sizeof(gRomcriEff2Map1));
            break;
        }

        work->frame++;

        if (work->frame > 5) {
            work->frame = 0;
        }
    }

    if (work->timer > 30 && work->frame == 0) {
        return 0;
    }

    work->timer++;
    return 1;
}

void task_romcri_eff2_3() {
    DisableBg(1);
}

TaskDesc gTaskDescRomcriEff = {
    "task_romcri_eff",
    (TaskInitFunc)task_romcri_eff_0,
    (TaskUpdateFunc)task_romcri_eff_1,
    NULL,
    (TaskDestroyFunc)task_romcri_eff_3,
    sizeof(RomcriEffWork),
};

TaskDesc gTaskDescRomcriEff2 = {
    "task_romcri_eff2",
    (TaskInitFunc)task_romcri_eff2_0,
    (TaskUpdateFunc)task_romcri_eff2_1,
    NULL,
    (TaskDestroyFunc)task_romcri_eff2_3,
    sizeof(RomcriEff2Work),
};
