#ifndef GUARD_BOS_BOOGIE_H
#define GUARD_BOS_BOOGIE_H

#include "anim.h"
#include "obj.h"
#include "taskpool.h"
#include "battle_actor_types.h"
#include "types.h"

enum BosBoogieState {
    BOS_BOOGIE_STATE_IDLE,
    BOS_BOOGIE_STATE_CARD_ACTION,
    BOS_BOOGIE_STATE_CARD_BROKEN,
    BOS_BOOGIE_STATE_HURT,
    BOS_BOOGIE_STATE_DEFEATED,
    BOS_BOOGIE_STATE_DICE_FACE,
    BOS_BOOGIE_STATE_SUMMON,
    BOS_BOOGIE_STATE_DICE_FACE_END,
    BOS_BOOGIE_STATE_WAIT_TASK,
    BOS_BOOGIE_STATE_DICE_THROW,
    BOS_BOOGIE_STATE_ATTACK_HIT,
    BOS_BOOGIE_STATE_WALK
};

typedef struct BoogieWork {
    s32 state;
    s16 timer;
    ObjTiles* tiles;
    ObjPalette* palette;
    ObjPalette* palette2;
    AnimState anim;
    TaskPool tasks;
    BtlObj actor;
    s32 vx;
    s32 vy;
    s32 vz;
    s32 animationIndex;
    Task* dice;
    Task* task;
    Task* dice2;
    Task* dice3;
    u32 defeatStep;
    u8 cardRequested;
    u8 diceFollower;
} BoogieWork;

enum BosBoogieDiceState {
    BOS_BOOGIE_DICE_STATE_BROKEN,
    BOS_BOOGIE_DICE_STATE_TUMBLE,
    BOS_BOOGIE_DICE_STATE_DESTROYED,
    BOS_BOOGIE_DICE_STATE_THROWN,
    BOS_BOOGIE_DICE_STATE_SHOW_FACE,
    BOS_BOOGIE_DICE_STATE_FACE_WAIT,
    BOS_BOOGIE_DICE_STATE_SQUASH,
    BOS_BOOGIE_DICE_STATE_SQUASH_WAIT,
    BOS_BOOGIE_DICE_STATE_JUMP,
    BOS_BOOGIE_DICE_STATE_VANISH,
    BOS_BOOGIE_DICE_STATE_WAIT_CARD,
    BOS_BOOGIE_DICE_STATE_NONE
};

typedef struct BoogieDiceWork {
    u32 state;
    s16 timer;
    ObjTiles* tiles;
    ObjPalette* palette;
    ObjPalette* palette2;
    AnimState anim;
    TaskPool tasks;
    BtlObj obj;
    s32 vz;
    s32 speed;
    u8 angle;
    s32 scaleX;
    s32 scaleY;
    s32 y;
    u8 counted;
    BoogieWork* parent;
    u8 follower;
} BoogieDiceWork;

typedef struct StatusObjDef {
    void* sprites;
    u16 spriteCount;
} StatusObjDef;

typedef struct StatusAnimDef {
    AnimHeader** anims;
    void** gfxTable;
    void* tiles;
    u16 animId;
} StatusAnimDef;

void BosBoogieApplyDiceFace(BoogieWork* work);
void SetBoogieAnimation(BoogieWork* work, s32 index, u16 flags);
u8 ClampBoogiePosition(s32* x, s32* y);
void task_bos_boogie_0(BoogieWork* work);
u8 task_bos_boogie_1(BoogieWork* work);
void task_bos_boogie_2(BoogieWork* work);
void task_bos_boogie_3(BoogieWork* work);
void BosBoogieRemoveOtherEnemies();
void BosBoogieApplyGimmick();
u32 GetBoogieDiceState();

#endif
