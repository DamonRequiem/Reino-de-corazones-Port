/**
 * ev_bg_effect.c
 * Event Background Effects
 */

#include "registration_data.h"
#include "fade.h"
#include "display.h"
#include "taskpool.h"
#include "card.h"
#include "sprites_msg.h"
#include "evt_obj.h"
#include "evt_types.h"
#include "msg_types.h"
#include "sprite_palettes.h"
#include "types.h"
#include <stddef.h>
#include "ev_bg_effect.h"
#include "default_bg_map.h"
#include "macros.h"

static const EventBgEffectDef sEventBgEffect0Def = {
    &gEventBgEffectMaps[0], gEventBgEffect0Tiles, gEventBgEffect0Palette, sizeof(gEventBgEffect0Tiles), sizeof(gEventBgEffect0Palette), { 1, 1, 0, 0 }, NULL, 0, EVENT_BG_EFFECT_LOOP_NONE,
};

static const EventBgEffectFrame sEventBgEffect1Frames[8] = {
    { 6, 0 },
    { 6, 0x800 },
    { 6, 0x1000 },
    { 6, 0x1800 },
    { 6, 0x2000 },
    { 6, 0x2800 },
    { 6, 0x3000 },
    { 6, 0x3800 },
};

static const EventBgEffectDef sEventBgEffect1Def = {
    &gEventBgEffectMaps[1], gEventBgEffect1Tiles, gEventBgEffect1Palette, 0x800, sizeof(gEventBgEffect1Palette), { 1, 1, 0, 0 }, sEventBgEffect1Frames, ARRAY_COUNT(sEventBgEffect1Frames), EVENT_BG_EFFECT_LOOP_NONE,
};

static const EventBgEffectFrame sEventBgEffect2Frames[8] = {
    { 6, 0 },
    { 6, 0xC00 },
    { 6, 0x1800 },
    { 6, 0x2400 },
    { 6, 0x3000 },
    { 6, 0x3C00 },
    { 6, 0x4800 },
    { 6, 0x5400 },
};

static const EventBgEffectDef sEventBgEffect2Def = {
    &gEventBgEffectMaps[2], gEventBgEffect2Tiles, gEventBgEffect2Palette, 0xC00, sizeof(gEventBgEffect2Palette), { 1, 1, 0, 0 }, sEventBgEffect2Frames, ARRAY_COUNT(sEventBgEffect2Frames), EVENT_BG_EFFECT_LOOP_NONE,
};

static const EventBgEffectFrame sEventBgEffect3Frames[10] = {
    { 6, 0 },
    { 6, 0x800 },
    { 6, 0x1000 },
    { 6, 0x1800 },
    { 6, 0x2000 },
    { 6, 0x2800 },
    { 6, 0x3000 },
    { 6, 0x3800 },
    { 6, 0x4000 },
    { 6, 0x4800 },
};

static const EventBgEffectDef sEventBgEffect3Def = {
    &gEventBgEffectMaps[3], gEventBgEffect3Tiles, gEventBgEffect3Palette, 0x800, sizeof(gEventBgEffect3Palette), { 1, 1, 0, 0 }, sEventBgEffect3Frames, ARRAY_COUNT(sEventBgEffect3Frames), EVENT_BG_EFFECT_LOOP_NONE,
};

static const EventBgEffectFrame sEventBgEffect4Frames[10] = {
    { 6, 0 },
    { 6, 0x800 },
    { 6, 0x1000 },
    { 6, 0x1800 },
    { 6, 0x2000 },
    { 6, 0x2800 },
    { 6, 0x3000 },
    { 6, 0x3800 },
    { 6, 0x4000 },
    { 6, 0x4800 },
};

static const EventBgEffectDef sEventBgEffect4Def = {
    &gEventBgEffectMaps[4], gEventBgEffect4Tiles, gEventBgEffect4Palette, 0x800, sizeof(gEventBgEffect4Palette), { 1, 1, 0, 0 }, sEventBgEffect4Frames, ARRAY_COUNT(sEventBgEffect4Frames), EVENT_BG_EFFECT_LOOP_NONE,
};

static const EventBgEffectFrame sEventBgEffect5Frames[16] = {
    { 6, 0 },
    { 6, 0xC00 },
    { 6, 0x1800 },
    { 6, 0x2400 },
    { 6, 0x3000 },
    { 6, 0x3C00 },
    { 6, 0x4800 },
    { 6, 0x3000 },
    { 6, 0x3C00 },
    { 6, 0x4800 },
    { 6, 0x3000 },
    { 6, 0x3C00 },
    { 6, 0x4800 },
    { 6, 0x3000 },
    { 6, 0x3C00 },
    { 6, 0x4800 },
};

static const EventBgEffectDef sEventBgEffect5Def = {
    &gEventBgEffectMaps[5], gEventBgEffect5Tiles, gEventBgEffect5Palette, 0xC00, sizeof(gEventBgEffect5Palette), { 1, 1, 0, 0 }, sEventBgEffect5Frames, ARRAY_COUNT(sEventBgEffect5Frames), EVENT_BG_EFFECT_LOOP_NONE,
};

static const EventBgEffectFrame sEventBgEffect6Frames[6] = {
    { 6, 0 },
    { 6, 0x1000 },
    { 6, 0x2000 },
    { 6, 0x3000 },
    { 6, 0x4000 },
    { 6, 0x5000 },
};

static const EventBgEffectDef sEventBgEffect6Def = {
    &gEventBgEffectMaps[6], gEventBgEffect6Tiles, gEventBgEffect6Palette, 0x1000, sizeof(gEventBgEffect6Palette), { 1, 1, 0, 0 }, sEventBgEffect6Frames, ARRAY_COUNT(sEventBgEffect6Frames), 2,
};

void LoadEventBgEffect(EventBgEffectWork* work) {
    const EventBgEffectEntry* entry;
    const EventBgEffectDef* def;

    entry = &work->entries[work->entry];
    def = gEventBgEffectDefs[entry->effect];
    work->effect = entry->effect;
    LoadBgTiles(0, def->tiles, def->tilesSize);
    LoadBgPalette(0, def->palette, def->paletteSize);
    LoadBgMap(0, def->maps[0], 0x800);
    SetBgScroll(0, (u16)((gEventState->x >> 8) - (entry->x >> 8)), (u16)((gEventState->y >> 8) - (entry->y >> 8)));

    if (def->frames != NULL) {
        work->animating = TRUE;
    }

    SetBgBlend(0, 16, 16);
    gEventState->bgEffectActive = TRUE;
    work->frame = work->frameTimer = work->fadingIn = 0;
}

void ClearEventBgEffect(EventBgEffectWork* work) {
    LoadBgTiles(0, gMsgwinTiles, sizeof(gMsgwinTiles));
    LoadBgPalette(0, gMsgwinPalette, sizeof(gMsgwinPalette));
    LoadBgMap(0, gDefaultBgMap, sizeof(gDefaultBgMap));
}

void StartEventBgEffectFadeOut(EventBgEffectWork* work) {
    const EventBgEffectEntry* entry;
    u16 frames;
    u8 i;

    frames = 16;
    entry = &work->entries[work->entry];

    for (i = 16; i <= 31; i++) {
        FadeSetPaletteExcluded(i, TRUE);
    }

    FadeSetPaletteExcluded(14, TRUE);

    if (entry->x > 0) {
        frames = entry->x;
    }

    if (entry->flags & EVENT_BG_EFFECT_FLAG_FULL_FADE) {
        FadeStartOut(FADE_MODE_BLACK, frames);
    } else {
        FadeToAmount(FADE_MODE_BLACK, 16, frames);
    }
}

void StartEventBgEffectFadeIn(EventBgEffectWork* work) {
    const EventBgEffectEntry* entry;
    u16 frames;

    frames = 16;
    entry = &work->entries[work->entry];
    FadeSetPaletteExcluded(14, TRUE);

    if (entry->x > 0) {
        frames = entry->x;
    }

    if (entry->flags & EVENT_BG_EFFECT_FLAG_FULL_FADE) {
        FadeStartIn(FADE_MODE_BLACK, frames);
    } else {
        FadeToOriginal(FADE_MODE_BLACK, frames);
    }
}

void EV_BG_EFFECT_0(EventBgEffectWork* work, u8* arg) {
    u8 eventId;
    u8 z;

    eventId = arg[0];
    z = 0;
    work->eventId = eventId;
    work->entry = z;
    work->animating = z;
    work->entries = gEventSequenceDefs[work->eventId]->bgEffects;
}

u8 EV_BG_EFFECT_1(EventBgEffectWork* work, void* task) {
    const EventBgEffectEntry* entries;
    const EventBgEffectEntry* entry;
    u8 i;

    entries = work->entries;

    if (entries == NULL) {
        return 0;
    }

    if (entries[work->entry].frame <= gEventState->frame && !(entries[work->entry].flags & EVENT_BG_EFFECT_FLAG_END)) {
        work->entry++;
        entry = &entries[work->entry];

        if (entry->flags & EVENT_BG_EFFECT_FLAG_LOAD) {
            LoadEventBgEffect(work);

            if (work->animating) {
                SetTaskUpdate(task, (TaskUpdateFunc)UpdateEventBgEffectAnim);
            }
        }

        if (entry->flags & EVENT_BG_EFFECT_FLAG_FADE_OUT) {
            StartEventBgEffectFadeOut(work);
        }

        if (entry->flags & EVENT_BG_EFFECT_FLAG_FADE_IN) {
            StartEventBgEffectFadeIn(work);
            work->fadingIn = TRUE;
        }

        if (entry->flags & EVENT_BG_EFFECT_FLAG_CLEAR) {
            ClearEventBgEffect(work);
            gEventState->bgEffectActive = FALSE;
            gBldCnt = gEventState->bldCnt;
            gBldAlpha = gEventState->bldAlpha;
        }
    }

    if (work->fadingIn == TRUE) {
        if (!FadeIsActive()) {
            work->fadingIn = FALSE;

            for (i = 16; i < 32; i++) {
                FadeSetPaletteExcluded(i, FALSE);
            }
        }
    }

    return 1;
}

u8 UpdateEventBgEffectAnim(EventBgEffectWork* work, void* task) {
    const EventBgEffectEntry* entry;

    entry = &work->entries[work->entry];
    SetBgScroll(0, (u16)((gEventState->x >> 8) - (entry->x >> 8)),
                (u16)((gEventState->y >> 8) - (entry->y >> 8)));

    if (!StepEventBgEffectAnim(work)) {
        SetTaskUpdate(task, (TaskUpdateFunc)EV_BG_EFFECT_1);
    }

    return 1;
}

u8 StepEventBgEffectAnim(EventBgEffectWork* work) {
    const EventBgEffectDef* def;
    const EventBgEffectFrame* frames;

    if (!work->animating) {
        return FALSE;
    }

    def = gEventBgEffectDefs[work->effect];
    frames = def->frames;

    if (work->frameTimer < frames[work->frame].duration) {
        work->frameTimer++;
    } else {
        work->frameTimer = 0;

        if (work->frame < def->frameCount - 1) {
            work->frame++;
            RequestDma3Copy(def->tiles + frames[work->frame].tilesOffset, GetBgCharBase(0), def->tilesSize);
        } else {
            if (def->loopFrame == EVENT_BG_EFFECT_LOOP_NONE) {
                work->animating = FALSE;
                return FALSE;
            }

            work->frame = def->loopFrame;
            RequestDma3Copy(def->tiles + frames[work->frame].tilesOffset, GetBgCharBase(0), def->tilesSize);
        }
    }

    return TRUE;
}

void EV_BG_EFFECT_2() {
}

void EV_BG_EFFECT_3() {
}

void CreateEVBGEFFECTTask(u8* work) {
    TaskCreate((TaskPool*)&work[0x10], &gTaskDescEVBGEFFECT, work);
}

const EventBgEffectDef* gEventBgEffectDefs[8] = {
    &sEventBgEffect0Def,
    &sEventBgEffect1Def,
    &sEventBgEffect2Def,
    &sEventBgEffect3Def,
    &sEventBgEffect4Def,
    &sEventBgEffect5Def,
    &sEventBgEffect6Def,
    NULL,
};

TaskDesc gTaskDescEVBGEFFECT = {
    "EV_BG_EFFECT",
    (TaskInitFunc)EV_BG_EFFECT_0,
    (TaskUpdateFunc)EV_BG_EFFECT_1,
    (TaskDrawFunc)EV_BG_EFFECT_2,
    (TaskDestroyFunc)EV_BG_EFFECT_3,
    sizeof(EventBgEffectWork),
};
