#ifndef GUARD_BOS4_H
#define GUARD_BOS4_H

#include "battle_actor_types.h"
#include "bos_boogie.h"
#include "battle_bg_types.h"
#include "map_types.h"
#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "bos4_api.h"
#include "obj.h"

typedef struct BoogieExplosiondiceWork {
    u32 state;
    u16 timer;
    ObjTiles* tiles;
    ObjPalette* palette;
    ObjPalette* palette2;
    AnimState anim;
    TaskPool tasks;
    BtlObj obj;
    u32 vz;
    u32 speed;
    u8 angle;
    BoogieWork* boogie;
} BoogieExplosiondiceWork;

typedef struct BoogieDiskWork {
    u32 state;
    u16 timer;
    ObjTiles* tiles;
    ObjPalette* palette;
    ObjPalette* palette2;
    AnimState anim;
    TaskPool tasks;
    BtlObj obj;
    s32 vz;
    s32 vx;
    s32 vy;
    u8 angle;
} BoogieDiskWork;

typedef struct BoogieMapanimeWork {
    BosMapanimeState anims[3];
} BoogieMapanimeWork;

typedef struct UrsulaThunderWork {
    u16 strikeStarted;
    s32 x;
    s32 y;
    s32 z;
} UrsulaThunderWork;

u8 BosBoogieExplosiondiceIsHeld(BoogieExplosiondiceWork* work);
u8 BosMapanimeIsAtEnd(BosMapanimeState* anim);
void task_bos_boogie_explosiondice_3(BoogieExplosiondiceWork* work);
void task_bos_boogie_disk_3(BoogieDiskWork* work);
void task_bos_boogie_mapanime_0(BoogieMapanimeWork* work);
void task_bos_ursula_thunder_0(UrsulaThunderWork* work);
u8 task_bos_ursula_thunder_1(UrsulaThunderWork* work);

extern MapRoomState* gMapRoomState;

typedef struct UrsulaBubbleSingleWork {
    void* tiles;
    void* palette;
    void* palette2;
#ifndef VERSION_EU
    AnimState anim;
#endif
    BtlObj obj;
    u16 timer;
    u32 state;
    u16 angle;
    u16 targetAngle;
    s32 speed;
    u8 unk_144[0x4];
} UrsulaBubbleSingleWork;

void task_bos_ursula_bubble_single_3(UrsulaBubbleSingleWork* work);

typedef struct BoogieKnifereaderWork {
    u32 state;
    u16 timer;
    TaskPool tasks;
    BtlObj obj;
    Task* knives[5];
} BoogieKnifereaderWork;

typedef struct UrsulaBubbleWork {
    u32 unk_000;
    TaskPool tasks;
    Task* bubbles[10];
    u16 bubbleCount;
#ifdef VERSION_EU
    AnimState anim;
#endif
} UrsulaBubbleWork;

typedef struct BoogieMapWork {
    u32 unk_00;
} BoogieMapWork;

void task_bos_boogie_map_0(BoogieMapWork* work, BattleBackgroundDef* arg);

u8 ClampBoogieDiskPosition(s32* x, s32* y, s16 marginX, s16 offsetY, s32 z);
void task_bos_boogie_dice_3(BoogieDiceWork* work);

u16 BosUrsulaSpawnThreeBubbles(UrsulaBubbleWork* work);
u16 BosUrsulaSpawnSixBubbles(UrsulaBubbleWork* work);
void task_bos_ursula_bubble_0(UrsulaBubbleWork* work);
u16 BosUrsulaSpawnTenBubbles(UrsulaBubbleWork* work);
u8 task_bos_boogie_mapanime_1(BoogieMapanimeWork* work);

void BosUrsulaPopBubbles(UrsulaBubbleWork* work);

typedef struct BoogieSakuWork {
    ObjTiles* tiles;
    ObjPalette* palette;
    AnimState anim;
    u16 openTimer;
    BoogieWork* boogie;
    TaskPool tasks;
    Task* task;
    u8 closePending;
} BoogieSakuWork;

typedef struct BoogieKnifeWork {
    u32 state;
    u16 timer;
    ObjTiles* tiles;
    ObjPalette* palette;
    ObjPalette* palette2;
    AnimState anim;
    BtlObj obj;
    s32 vz;
    s32 vx;
    u8 unk_144[0x4];
    u32 scaleX;
    u32 drawOffsetX;
    s32 gravity;
    s32 bounceVz;
} BoogieKnifeWork;

typedef struct BoogieKaihukuWork {
    u32 state;
    u16 timer;
    ObjTiles* tiles;
    ObjPalette* palette;
    ObjPalette* palette2;
    AnimState anim;
    u8 unk_02C[0x14];
    BtlObj obj;
    u32 vz;
    BoogieWork* boogie;
} BoogieKaihukuWork;

u16 BosMapanimeGetFrameIndex(BosMapanimeState* anim);
u8 BosBoogieIsActorPastSaku();
u8 BosBoogieKnifeIsLanded(BoogieKnifeWork* work);
void BosBoogieSakuDrawAt(BoogieSakuWork* work, s32 px, u16 flags);
void task_bos_boogie_saku_0(BoogieSakuWork* work, BoogieWork* arg);
void task_bos_boogie_saku_3(BoogieSakuWork* work);
void task_bos_boogie_knife_3(BoogieKnifeWork* work);
u8 BosBoogieAnyKnifeActive(BoogieKnifereaderWork* work);
void task_bos_boogie_kaihuku_3(BoogieKaihukuWork* work);

void task_bos_boogie_knifereader_0(BoogieKnifereaderWork* work);
void task_bos_boogie_knifereader_2(BoogieKnifereaderWork* work);
void task_bos_boogie_knifereader_3(BoogieKnifereaderWork* work);
void task_bos_boogie_mapanime_2();
void task_bos_boogie_mapanime_3();
void task_bos_ursula_thunder_2();
void task_bos_ursula_thunder_3();
void BosUrsulaBubblePop(UrsulaBubbleSingleWork* work);
u8 task_bos_ursula_bubble_1(UrsulaBubbleWork* work);
void task_bos_ursula_bubble_2(UrsulaBubbleWork* work);
void task_bos_ursula_bubble_3(UrsulaBubbleWork* work);

u8 task_bos_boogie_explosiondice_1(BoogieExplosiondiceWork* work);
void task_bos_boogie_kaihuku_2(BoogieKaihukuWork* work);

void BosBoogieKnifeAttack(BoogieKnifeWork* work);

u8 task_bos_ursula_bubble_single_1(UrsulaBubbleSingleWork* work);
u8 task_bos_boogie_saku_1(BoogieSakuWork* work);

void task_bos_boogie_dice_0(BoogieDiceWork* work, BoogieWork* arg);
u8 task_bos_boogie_dice_1(BoogieDiceWork* work);
u8 ClampBoogieDicePosition(s32* x, s32* y, s16 marginX, u16 marginY);
void BosBoogieDiceGrow(BoogieDiceWork* work);

u8 task_bos_boogie_kaihuku_1(BoogieKaihukuWork* work);

void task_bos_boogie_knife_0(BoogieKnifeWork* work, s32* arg);

void task_bos_boogie_disk_0(BoogieDiskWork* work, BtlObj* arg);
u8 task_bos_boogie_disk_1(BoogieDiskWork* work);
u8 task_bos_boogie_knifereader_1(BoogieKnifereaderWork* work);
u8 task_bos_boogie_knife_1(BoogieKnifeWork* work);
void task_bos_boogie_knife_2(BoogieKnifeWork* work);
void task_bos_boogie_explosiondice_0(BoogieExplosiondiceWork* work, BoogieWork* arg);

u8 task_bos_boogie_map_1();

void task_bos_boogie_dice_2(BoogieDiceWork* work);
u8 BosBoogieDiceIsHeld(BoogieDiceWork* work);
void task_bos_ursula_bubble_single_0(UrsulaBubbleSingleWork* work, u8* arg);
s32 strcmp(const char* a, const char* b);
void RollBoogieDice(BoogieDiceWork* work);

void task_bos_boogie_kaihuku_0(BoogieKaihukuWork* work, BoogieWork* arg);
void BosBoogieSpawnKnives(BoogieKnifereaderWork* work);
void task_bos_boogie_explosiondice_2(BoogieExplosiondiceWork* work);
void task_bos_boogie_disk_2(BoogieDiskWork* work);
void task_bos_ursula_bubble_single_2(UrsulaBubbleSingleWork* work);

#endif /* GUARD_BOS4_H */
