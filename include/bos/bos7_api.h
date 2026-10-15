#ifndef GUARD_BOS7_API_H
#define GUARD_BOS7_API_H

#include "types.h"

struct Task;

enum BosLstBitKind {
    BOS_LST_BIT_KIND_BITS,
    BOS_LST_BIT_KIND_PLATFORM
};

typedef struct LstBitArg {
    s32 kind;
    s32 index;
    s16* facing;
    u16* falCount;
    s16* unk_10;
    s32 x;
    s32 y;
    s32 z;
    s32 x2;
    s32 y2;
    s32 z2;
} LstBitArg;

typedef struct LstCtrArg {
    s16* unk_00;
    u16 count;
    u16 index;
    s32 delay;
    s32 x;
    s32 y;
    s32 z;
} LstCtrArg;

enum BosLstFalKind {
    BOS_LST_FAL_DRIFT,
    BOS_LST_FAL_DASH,
    BOS_LST_FAL_HIGH,
    BOS_LST_FAL_PLATFORM,
    BOS_LST_FAL_DEFEAT_SPIRAL,
    BOS_LST_FAL_DEFEAT_BURST
};

typedef struct LstFalArg {
    s32 kind;
    s32 x;
    s32 y;
    s32 z;
    u8 angle;
    s16 facing;
    u16* falCount;
} LstFalArg;

typedef struct LstSnpArg {
    s32 x;
    s32 y;
    s32 z;
    s16 facing;
} LstSnpArg;

void BosLstFldSetBgMode(struct Task* task, s32 mode, s32 scrollDir);
void BosLstFldSetCameraMode(struct Task* task, s32 mode);
void BosLstFldSetScrollSpeed(struct Task* task, s32 speed);
u8 BosLstBitIsAlive(struct Task* task);
u8 BosLstBitHasShots(struct Task* task);
s16 BosLstBitMarkFirstAlive(struct Task* task, s16 found);
void BosLstBitStartHover(struct Task* task);
void BosLstBitStartFiring(struct Task* task, s16 shots);
void BosLstBitStartReturn(struct Task* task);
u8 BosLstBitInterrupt(struct Task* task, u8 destroy);
u8 BosLstCtrIsActive(struct Task* task);

#endif
