#ifndef GUARD_CHARA_H
#define GUARD_CHARA_H

#include "chara_types.h"
#include "types.h"

typedef struct MaskFadeWork {
    u8* tiles;
    u16 tileCount;
    u16 stepDelay;
    s16 step;
    s16 timer;
    u8 tileBuffer[0x20];
    u8 maskedTile[0x20];
    s8 patterns[0x1F4];
} MaskFadeWork;

typedef struct ChgCardObjWork {
    s16 timer;
    s16 unk_02;
    s8 state;
    s32* x;
    s32* y;
    s32* scaleX;
    s32* scaleY;
    u8* angle;
    u8* visible;
    s32 targetX;
    s32 targetY;
    s16 delay;
    u8 flipAngleY;
    u8 flipAngleX;
    s16 scale;
    s32 decel;
    s32 speed;
    s32 dirX;
    s32 dirY;
    s32 distance;
} ChgCardObjWork;

typedef struct ChgCardObjParam {
    s32* x;
    s32* y;
    s32* scaleX;
    s32* scaleY;
    u8* angle;
    u8* visible;
    s32 targetX;
    s32 targetY;
    u16 delay;
} ChgCardObjParam;

typedef struct CharaObj {
    u32 x;
    u32 y;
    u32 z;
    u32 tilesAddr;
    u16 tileCount;
    u32 tilesAddr2;
    u16 tileCount2;
    u32 tilesAddr3;
    u16 tileCount3;
    u32 paletteAddr;
    u16 paletteSize;
    u32 tilesAddr4;
    u16 tileCount4;
    u32 paletteAddr2;
    u16 paletteSize2;
    s16 fadeLevel;
    s32 bgFxVz;
    s16 fadeTick;
    s16 timer;
    u8 state;
    u16 savedPalette[0x400];
    u16 fadedPalette[0x400];
    void (*callback)();
    struct BtlObj* prizeObj;
    u16 bankFadeEnabled[32];
    u16 flags;
} CharaObj;

typedef struct CharaPrizeArgs {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x14];
} CharaPrizeArgs;

typedef struct MaskFadeArgs {
    u8* tiles;
    u32 tileCount : 16;
    u32 stepDelay : 16;
} MaskFadeArgs;

void task_chara_mask_fade_0(MaskFadeWork* work, MaskFadeArgs* args);
u8 task_chara_mask_fade_1(MaskFadeWork* work);
void task_chara_mask_fade_2();
void task_chara_mask_fade_3();
void task_chgCardObj_0(ChgCardObjWork* work, ChgCardObjParam* arg);
u8 task_chgCardObj_1(ChgCardObjWork* work);
void task_chgCardObj_2();
void task_chgCardObj_3();
u8 SioConnectUpdateAuto();
void DebugLogClear();
void DebugLogAdd(u16 a, u16 b, u16 c, u16 d);
void DebugLogResetSeq();
void DebugLogNextSeq();
void VBlankTimerStart();
void VBlankTimerUpdate();
void SioAutoConnectStart();
u8 SioAutoConnectUpdate();
void SioAutoConnectOnConnect();
s32 SioConnectSend();
s32 SioConnectRecv();
s32 SioConnectSendAuto();
s32 SioConnectRecvAuto();
void SioCommandClearSend();
void SioCommandClearRecv();
void SioSyncInit(void (*onConnect)());
s32 SioSyncSend();
s32 SioSyncRecv();
void CharaObjFree();
void CharaObjSetBankFadeEnabled(u16 bank, u8 enabled);
void RequestTileRowsCopy(u8* src, u8* dst, u16 size, s16 count);

#endif /* GUARD_CHARA_H */
