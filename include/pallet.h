#ifndef GUARD_PALLET_H
#define GUARD_PALLET_H

#include "types.h"

typedef struct PaletteBuffer {
    u16 colors[512];
    u16 banks[32];
} PaletteBuffer;

typedef struct PaletteWave {
    u8 amplitude;
    u8 frequency;
    u8 enabled;
} PaletteWave;

extern PaletteWave gBgWaves[];

u16* FadePaletteToGray(const u16* src, u16* dst, u16 size, u16 amount);
u16* FadePaletteToWhite(u16* src, u16* dst, u16 size, u16 amount);
u16* BrightenPalette(const u16* src, u16* dst, u16 size, u16 amount);
u16* LoadPaletteBuffered(const void* src, u16* dst, u16 size);
u16* GetPaletteBufferBank(u8 bank);
void ResetPaletteEffect();
void PalletFree();
void PalletClear();
void SetPaletteBankFadeEnabled(u16 bank, u8 enabled);
u16* FadeAllPalettesToBlack(u16* src, u16 amount);
u16* FadeAllPalettesToWhite(u16* src, u16 amount);
void DisableBgWave(s32 bg);
void HBlankIntrBgWave();
void StopAllBgWaves();

void PalletInit();
s16 GetPaletteEffect();
void SetPaletteEffect(s16 effect);
u16* FadePaletteToBlack(u16* src, u16* dst, u16 size, u16 amount);
u16* LoadPaletteWithEffect(const void* src, u16* dst, u16 size);
void StartBgWave(void (*callback)());
void SetBgWaveParams(s32 bg, u8 amplitude, u8 frequency);
void EnableBgWave(s32 bg);
void HBlankIntrBgWave1(s32 bg);
void StopBgWave(s32 bg);
void PushPaletteEffect(s32 effect);
void PopPaletteEffect();

#endif /* GUARD_PALLET_H */
