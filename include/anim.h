#ifndef GUARD_ANIM_H
#define GUARD_ANIM_H

#include "types.h"
#include "macros.h"

typedef struct AnimDef {
    void* gfxTable;
    void* anims;
    void* tiles;
    u8 animId;
} AnimDef;

typedef struct AnimFrame {
    u16 gfxIndex;
    u16 duration;
} AnimFrame;

typedef struct AnimHeader {
    u16 originX;
    u16 originY;
    u16 frameCount;
    AnimFrame frames[0];
} __attribute__((packed, aligned(2))) AnimHeader;

STATIC_ASSERT(sizeof(AnimHeader) == 6, AnimHeaderSize);
STATIC_ASSERT(sizeof(AnimFrame) == 4, AnimFrameSize);

enum AnimFlag {
    ANIM_FLAG_LOOP = 0x1,
    ANIM_FLAG_RANDOM_START = 0x2,
    ANIM_FLAG_KEEP_FRAME = 0x4,
    ANIM_FLAG_FINISHED = 0x1000
};

typedef struct AnimState {
    AnimHeader** anims;
    void** gfxTable;
    u16 flags;
    u16 timer;
    u16 frameCount;
    u16 frame;
    u16 animId;
    AnimFrame* frames;
} AnimState;

void AnimInit(AnimState* anim, void* anims, void* gfxTable);
void AnimChangeWithTables(AnimState* anim, u16 animId, u16 flags, void* anims, void* gfxTable);
u8 AnimIsFrameEnding(AnimState* anim);

void AnimStart(AnimState* anim, u16 animId, u16 flags);
void AnimChange(AnimState* anim, u16 animId, u16 flags);
void* AnimUpdate(AnimState* anim);
void* AnimGetGfx(AnimState* anim);
u8 AnimIsFinished(AnimState* anim);
u16 AnimGetId(AnimState* anim);
u16 AnimGetFrame(AnimState* anim);
u16 AnimGetGfxIndex(AnimState* anim);
void AnimSetFrame(AnimState* anim, u16 frame);
void AnimReset(AnimState* anim);

#endif
