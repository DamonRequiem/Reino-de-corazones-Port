#ifndef GUARD_BOS4_API_H
#define GUARD_BOS4_API_H

#include "types.h"

typedef struct BosMapanimeFrame {
    u16 duration;
    u16 frame;
} BosMapanimeFrame;

typedef struct BosMapanimeDef {
    const BosMapanimeFrame* frames;
    u16 frameCount;
    void* tiles;
    u16 destOffset;
    u16 copySize;
    u16 frameSize;
    s32 bg;
} BosMapanimeDef;

typedef struct BosMapanimeState {
    u16 timer;
    u16 frameIndex;
    u8 uploadPending;
    const BosMapanimeDef* def;
} BosMapanimeState;

void BosMapanimeInit(struct BosMapanimeState* anim, const struct BosMapanimeDef* def);
u8 BosMapanimeUpdate(struct BosMapanimeState* anim, const struct BosMapanimeDef* def, u8 defer);
void ResetPooState();
void SavePooState(void* state);
void LoadPooState(const void* state);

struct BtlObj;

extern u16 gBosBoogieSakuOpenTime;
enum BosBoogieDiceFace {
    BOS_BOOGIE_DICE_FACE_DISK,
    BOS_BOOGIE_DICE_FACE_GARGOYLES,
    BOS_BOOGIE_DICE_FACE_WIGHT_KNIGHTS,
    BOS_BOOGIE_DICE_FACE_KNIVES,
    BOS_BOOGIE_DICE_FACE_SEARCH_GHOSTS,
    BOS_BOOGIE_DICE_FACE_HEAL
};

extern u8 gBosBoogieDiceFace;
extern struct BtlObj* gBosBoogieActor;
extern u16 gBosBoogieDiceBreakCount;
extern u8 gBosBoogieDiceFaceReady;
extern u8 gBosBoogieGimmickCardDropped;
extern u8 gBosBoogieAttackHit;
extern u8 gBosBoogieTaskKnockedDown;
extern u8 gBosBoogieKnivesRetract;
extern u8 gBosBoogieKnivesMoveRight;
extern u8 gBosUrsulaActive;
extern s32 gBosUrsulaBaseZ;
extern u8 gMapChkUseParams;

#endif
