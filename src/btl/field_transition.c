/**
 * field_transition.c
 * Field Entry Transition
 */

#include "mode.h"
#include "obj_api.h"
#include "battle.h"
#include "sprites_evt.h"
#include "sprites_fld.h"
#include "sprites_riku.h"
#include "sprites_sora.h"
#include "gba/io_reg.h"
#include "malloc.h"
#include "anim.h"
#include "game_state.h"
#include "obj.h"
#include <stddef.h>
#include "system_state.h"
#include "types.h"
#include "sprite_palettes.h"
#include "fld_types.h"

static FieldTransitionWork* sFieldTransitionWork;

void FieldTransitionInit() {
    FieldTransitionWork* work;
    FieldTransitionWork** slot = &sFieldTransitionWork;
    work = EwramAlloc(sizeof(FieldTransitionWork));
    *slot = work;
    work->initialized = 0;
    work->tiles = NULL;
    work->palette = NULL;
    work->flipped = FALSE;
}

void FieldTransitionUpdate() {
    void* gfx;

    if (IsModeStarted()) {
        ReleaseObjTiles(sFieldTransitionWork->tiles);
        ReleaseObjPalette(sFieldTransitionWork->palette);
        EwramFree(sFieldTransitionWork);
        ModeClearTransitionCallback();
        return;
    }

    REG_DISPCNT |= DISPCNT_OBJ_ON;
    gSystemFlags |= SYSTEM_FLAG_DMA3_IMMEDIATE;

    if (sFieldTransitionWork->initialized == 0) {
        sFieldTransitionWork->tiles = AllocObjTiles(0xA00, NULL);

        if (gGameState.flags & GAME_FLAG_RIKU) {
            sFieldTransitionWork->palette = LoadObjPalette(gRikuPalette, sizeof(gRikuPalette));
            AnimInit(&sFieldTransitionWork->anim, NULL, NULL);

            switch (gGameState.fieldAngle) {
            case FLD_ANGLE_UP:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gRik1bb01Anims, gRik1bb01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gRik1bb01Tiles);
                break;
            case FLD_ANGLE_UP_RIGHT:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gRik1bl01Anims, gRik1bl01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gRik1bl01Tiles);
                sFieldTransitionWork->flipped = TRUE;
                break;
            case FLD_ANGLE_RIGHT:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gRik1ll01Anims, gRik1ll01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gRik1ll01Tiles);
                sFieldTransitionWork->flipped = TRUE;
                break;
            case FLD_ANGLE_DOWN_RIGHT:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gRik1fl01Anims, gRik1fl01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gRik1fl01Tiles);
                sFieldTransitionWork->flipped = TRUE;
                break;
            case FLD_ANGLE_DOWN:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gRik1ff01Anims, gRik1ff01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gRik1ff01Tiles);
                break;
            case FLD_ANGLE_DOWN_LEFT:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gRik1fl01Anims, gRik1fl01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gRik1fl01Tiles);
                break;
            case FLD_ANGLE_LEFT:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gRik1ll01Anims, gRik1ll01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gRik1ll01Tiles);
                break;
            default:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gRik1bl01Anims, gRik1bl01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gRik1bl01Tiles);
                break;
            }
        } else {
            sFieldTransitionWork->palette = LoadObjPalette(gSoraPalette, sizeof(gSoraPalette));
            AnimInit(&sFieldTransitionWork->anim, NULL, NULL);

            switch (gGameState.fieldAngle) {
            case FLD_ANGLE_UP:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gSor1bb01Anims, gSor1bb01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gSor1bb01Tiles);
                break;
            case FLD_ANGLE_UP_RIGHT:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gSor1bl01Anims, gSor1bl01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gSor1bl01Tiles);
                sFieldTransitionWork->flipped = TRUE;
                break;
            case FLD_ANGLE_RIGHT:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gSor1ll01Anims, gSor1ll01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gSor1ll01Tiles);
                sFieldTransitionWork->flipped = TRUE;
                break;
            case FLD_ANGLE_DOWN_RIGHT:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gSor1fl01Anims, gSor1fl01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gSor1fl01Tiles);
                sFieldTransitionWork->flipped = TRUE;
                break;
            case FLD_ANGLE_DOWN:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gSor1ff01Anims, gSor1ff01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gSor1ff01Tiles);
                break;
            case FLD_ANGLE_DOWN_LEFT:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gSor1fl01Anims, gSor1fl01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gSor1fl01Tiles);
                break;
            case FLD_ANGLE_LEFT:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gSor1ll01Anims, gSor1ll01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gSor1ll01Tiles);
                break;
            default:
                AnimChangeWithTables(&sFieldTransitionWork->anim, 0, ANIM_FLAG_LOOP, gSor1bl01Anims, gSor1bl01Frames);
                SetObjTileSource(sFieldTransitionWork->tiles, gSor1bl01Tiles);
                break;
            }
        }

        sFieldTransitionWork->initialized++;
    }

    gfx = AnimUpdate(&sFieldTransitionWork->anim);

    if (sFieldTransitionWork->flipped) {
        DrawSprite(120, 96, gfx, sFieldTransitionWork->tiles, sFieldTransitionWork->palette, NULL, SPRITE_FLAG_HFLIP, 0);
    } else {
        DrawSprite(120, 96, gfx, sFieldTransitionWork->tiles, sFieldTransitionWork->palette, NULL, 0, 0);
    }

    gSystemFlags &= ~SYSTEM_FLAG_DMA3_IMMEDIATE;
    UpdateSpriteOam();
}

void StartFieldTransition() {
    ModeSetTransitionCallback(FieldTransitionInit, FieldTransitionUpdate);
}

u8 ClampBosBoogieBounds(s32* x, s32* y, s32* z, s32* floor) {
    if (*y < 0x24000) {
        if (*z > -0x2000) {
            *floor = 0;
            *y = 0x24000;
            return 1;
        }

        *floor = -0x2000;
    } else {
        *floor = 0;
    }

    return 0;
}
