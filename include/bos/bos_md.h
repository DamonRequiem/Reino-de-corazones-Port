#ifndef GUARD_BOS_MD_H
#define GUARD_BOS_MD_H

#include "battle_actor_types.h"
#include "obj.h"
#include "types.h"
#include "taskpool.h"
#include "anim.h"

typedef struct MdFrameSprite {
    u16 x;
    u16 y;
    u16 z;
    void* src;
    u32 srcSize;
    void* sprite;
} MdFrameSprite;

typedef struct MdFramePos {
    s16 x;
    s16 y;
    s16 z;
    u16 unk_06;
} MdFramePos;

typedef struct MdFrameDef {
    u16 bgOffsetX;
    u16 bgOffsetY;
    void* tiles;
    u16 tilesSize;
    const void* blocks[4];
    MdFrameSprite desc[2];
    MdFramePos pos[1];
} MdFrameDef;

typedef struct MdAnimFrame {
    s16 gfxIndex;
    u16 duration;
} MdAnimFrame;

typedef struct MdAnimDef {
    const MdAnimFrame* frames;
    u16 frameCount;
} MdAnimDef;

typedef struct MdAnim {
    u16 animId;
    const MdAnimFrame* frames;
    s16 frameCount;
    s16 frame;
    s16 timer;
} MdAnim;

typedef struct MdHahenWork {
    s32 x;
    s32 y;
    s32 z;
    s32 vx;
    s32 vy;
    s32 vz;
    ObjPalette* palette;
    ObjTiles* tiles;
    void* gfx;
    u16 timer;
} MdHahenWork;

typedef struct MdDaiWork {
    s32 x;
    s32 y;
    s32 z;
    s32 dropZ;
    s16 dropSteps;
    ObjPalette* palette;
    ObjTiles* tiles;
    Collider collider;
    u16* flags;
    s16 level;
    u16 state;
    TaskPool* pool;
} MdDaiWork;

typedef struct MdFireWork {
    u32 state;
    s16 timer;
    s16 flashTimer;
    s16 contactCooldown;
    ObjPalette* palette;
    ObjPalette* palette2;
    ObjTiles* tiles;
    AnimState anim;
    u32 scale;
    s16 scaleSteps;
    BtlObj sub;
    s32 x;
    s32 y;
    s32 z;
    s32 vx;
    s32 vy;
    s16 motion;
    s16 pattern;
    s16 index;
    u8 angle;
    u32 centerX;
    u32 centerY;
    u16* flags;
} MdFireWork;

typedef struct MdFireArg {
    TaskPool* pool;
    s16 pattern;
    u16 index;
    u16* flags;
} MdFireArg;

typedef struct MdFirePoint {
    s16 x;
    s16 y;
    u16 delay;
    u16 unk_06;
} MdFirePoint;

typedef struct MdFireDef {
    const MdFirePoint* points;
    s16 count;
} MdFireDef;

typedef struct MdGfx {
    void* tiles;
    void* src;
    void* sprite;
    s16 x;
    s16 y;
    s16 z;
} MdGfx;

enum MdFlag {
    MD_FLAG_STATE_REQUESTED = 0x1
};

enum MdSignal {
    MD_SIGNAL_QUAKE_SLAM = 0x1,
    MD_SIGNAL_CLEAR_FIRES = 0x2
};

typedef struct MdWork {
    u32 state;
    u32 nextState;
    u32 statePhase;
    u16 step;
    u32 hurtState[1];
    u16 flags;
    s16 timer;
    u16 stepsLeft;
    s16 hurtTimer;
    u8 bgVisible;
    ObjPalette* palette;
    ObjPalette* palette2;
    void* bgPalette;
    TaskPool tasks;
    TaskPool tasks2;
    TaskPool tasks3;
    BtlObj sub[1];
    u16 bgOffsetX;
    u16 bgOffsetY;
    MdGfx gfx[2];
    MdAnim anim;
    u16 signals;
} MdWork;

void BosMdFireHandleReaction(MdFireWork* work);
u8 BosMdFireUpdateMotion(MdFireWork* work);

s32 task_bos_md_hahen_1(MdHahenWork* work);
void task_bos_md_hahen_2(MdHahenWork* work);
void task_bos_md_dai_0(MdDaiWork* work, void** args);
void task_bos_md_hahen_0(MdHahenWork* work, s32* src);
u8 task_bos_md_fire_1(MdFireWork* work);
void task_bos_md_fire_2(MdFireWork* work);
void task_bos_md_3(MdWork* work);
void task_bos_md_hahen_3(MdHahenWork* work);
void task_bos_md_fire_3(MdFireWork* work);
void task_bos_md_dai_3(MdDaiWork* work);
void BosMdSetBgMap(MdWork* work, u16 index);
void BosMdLoadBgTiles(MdWork* work, u16 index);

typedef struct MdMapData {
    void* tiles;
    u16 tilesSize;
    void* palette;
    u16 paletteSize;
    void* map[4];
} MdMapData;

typedef struct MdMapWork {
    u32 unk_00;
} MdMapWork;

s32 task_bos_md_dai_1(MdDaiWork* work);
void task_bos_md_fire_0(MdFireWork* work, MdFireArg* arg);
void BosMdFirePlace(MdFireWork* work);
void task_bos_md_dai_2(MdDaiWork* work);
void BosMdSetFrame(MdWork* work, u16 id);
void BosMdRequestState(MdWork* work, s32 state);
void MdAnimStart(MdWork* work, s16 id);
u8 BosMdAnimIsLastFrame(MdWork* work);
u8 BosMdUpdateIdle(MdWork* work);
u8 BosMdUpdateBite(MdWork* work);
u8 BosMdUpdateQuake(MdWork* work);
u8 BosMdUpdateFireBreath(MdWork* work);
s32 task_bos_md_1(MdWork* work);
void task_bos_md_0(MdWork* work, void* arg);
void MdAnimUpdate(MdWork* work);
void task_bos_md_2(MdWork* work);
void BosMdEndHurt(MdWork* work);
void BosMdHandleReaction(MdWork* work);
u8 BosMdUpdateDefeat(MdWork* work);
void BosMdChooseAttack(MdWork* work);
void task_bos_md_map_0(MdMapWork* work, MdMapData* arg);
s32 task_bos_md_map_1(MdMapWork* work);

#endif /* GUARD_BOS_MD_H */
