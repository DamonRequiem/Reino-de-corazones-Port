#ifndef GUARD_AUDIO_BLOCK_CODEC_H
#define GUARD_AUDIO_BLOCK_CODEC_H

#include "types.h"

extern u8* gAudioCodecSrc;
extern s32 gAudioCodecBitBuffer;
extern s32 gAudioCodecBitCount;
extern s32* gAudioCodecSamples;
extern s32 gAudioCodecResiduals[8];
extern s32 gAudioCodecTransformBuf[16];

void _08117284(s32 offset);
void _08117674(s32 offset);
void _08117A4C(s32 offset);
void DecodeAudioSubblock(s32 offset);
void DecodeAudioBlock(u8* src, s32* samples, s32 offset);
s32 PeekAudioBits8();

void func_081213C4(s32* a, s32* b, const s32* c);
void func_081213CC(s32* a, s32* b);
void func_081213D4(s32* a, s32* b);

#endif
