#ifndef GUARD_SROLL_API_H
#define GUARD_SROLL_API_H

#include "types.h"

struct SrollInit;
struct Task;
struct SrollWork;

void SrollBCharSetMotion(struct Task* task, s32 motion);
s32 SrollTextMeasureWidth(struct SrollWork* work, const u8* str);
void SrollTextSelectFont(struct SrollWork* work, u32 font);
void SrollTextInit(struct SrollWork* work, const struct SrollInit* init);
void SrollTextSetColors(struct SrollWork* work, u16 fgColor, u16 shadowColor, u16 bgColor, u16 edgeColor);
void SrollTextClearRect(struct SrollWork* work, u16 x, u16 y, u16 width, u16 height, u8 flush);
void SrollTextDrawStringAtPixelX(struct SrollWork* work, u16 x, u16 y, u8* str, u8 flush);
void ScanlineDmaReset();
void ScanlineDmaInit(vu16* dst, void* src, u32 cnt);
void ScanlineDmaQueueBuffer(void* src);
void ScanlineDmaEnable();
void ScanlineDmaDisable();
void BlockAudioStart();
void BlockAudioUpdate();
void BlockAudioStop();

s32* GetDecodedAudioBuffer();
s32 GetDecodedAudioReadPosition();
void SetDecodedAudioReadPosition(s32 pos);

#endif
