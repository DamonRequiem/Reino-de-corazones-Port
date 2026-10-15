#ifndef GUARD_FADE_H
#define GUARD_FADE_H

#include "types.h"

enum FadeMode {
    FADE_MODE_BLACK,
    FADE_MODE_WHITE,
    FADE_MODE_ADD_WHITE,
    FADE_MODE_RED,
    FADE_MODE_BLUE,
    FADE_MODE_GREEN,
    FADE_MODE_GRAY,
    FADE_MODE_WHITE_BLEND,
    FADE_MODE_CONTRAST,
    FADE_MODE_DARK_MAGENTA,
    FADE_MODE_DARK_RED
};

void FadeReset();
void FadeUpdate();
void FadeStartIn(s32 mode, u16 frames);
void FadeStartOut(s32 mode, u16 frames);
void FadeToOriginal(s32 mode, u16 frames);
void FadeToAmount(s32 mode, u16 amount, u16 frames);
void FadeFromAmount(s32 mode, u16 amount, u16 frames);
void FadeSetPaletteExcluded(u16 slot, u8 excluded);
u8 FadeIsActive();
void FadeLock();
void FadeSetPaused(u8 on);

void FadeClearPaletteSlot(u16 slot);
u16 FadeGetAmount();
u16 FadeGetColor();

#endif
