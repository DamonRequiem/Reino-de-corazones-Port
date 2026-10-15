#ifndef GUARD_POO_H
#define GUARD_POO_H

#include "poo_data.h"
#include "pooh_actor_types.h"
#include "prize_types.h"
#include "types.h"
#include "listpool.h"
#include "anim.h"
#include "taskpool.h"
#include "obj.h"
#include "bos4_api.h"
#include "battle_actor_types.h"
#include "macros.h"
typedef struct PooHit {
    Collider* collider;
    u16 message;
    u8 enabled;
} PooHit;

typedef struct PoohInteractionRegistry {
    PooHit entries[6];
    u16 count;
    u8 rabbitTalkBlocked;
} PoohInteractionRegistry;

typedef struct PooMapWork {
    u8 mapWidth;
    u8 mapHeight;
    TaskPool tasks;
} PooMapWork;

typedef struct PooShadowWork {
    s32 x;
    s32 y;
    void* tiles;
    void* palette;
    void* gfx;
    PooPos* pos;
    PooShadowInfo* shadowInfo;
    AnimState anim;
} PooShadowWork;

typedef struct PooShadowArgs {
    PooPos* pos;
    PooShadowInfo* shadowInfo;
    s32 scale;
} PooShadowArgs;

typedef struct PooTileDesc {
    s32 x;
    s32 y;
    u32 kind;
} PooTileDesc;

typedef struct PooGaugeWork {
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    void* paletteSrc;
    u8 warning;
    u16 blinkTimer;
} PooGaugeWork;

typedef struct PooMapBornWork {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x04];
    PooPos pos;
    Collider collider;
    u8 unk_7C;
    TaskPool tasks;
    Task* task;
    u8 colliderActive;
    u8 armed;
} PooMapBornWork;

typedef struct PooScaleWork {
    s32 x;
    s32 y;
    void* tiles;
    void* palette;
    PooPos* pos;
    AnimState anim;
    s32 scale;
    void* gfx;
} PooScaleWork;

typedef struct PooBalloonObjWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    PooPos* pos;
} PooBalloonObjWork;

typedef struct PooNode {
    u16 weight;
    u16 baseWeight;
    u16 unk_04;
    void* pos;
    ListNode node;
} PooNode;

STATIC_ASSERT(sizeof(PooNode) == 0x20, PooNodeSize);

typedef struct PooFrame {
    u16 duration;
    u16 nextGfxIndex;
} PooFrame;

typedef struct PooAnimData {
    u8 unk_00[0x04];
    u16 frameCount;
    u16 firstGfxIndex;
    PooFrame frames[1];
} PooAnimData;

typedef struct PooAnimDesc {
    void* unk_00;
    void* unk_04;
    void* tiles;
    u16 animId;
} PooAnimDesc;

typedef struct PooHoneyWork {
    void* tiles;
    void* palette;
    AnimState anim;
    u16 tileBytes;
    PooPos pos;
    PooPos pos2;
    PooPos pos3;
    PooPos minPos;
    PooPos maxPos;
    Collider collider;
    PooNode node;
    u32 state;
    TaskPool tasks;
    u16 timer;
} PooHoneyWork;

typedef struct PooPileArgs {
    s32 x;
    s32 y;
    u8 unk_08[0x08];
    s32 stage;
} PooPileArgs;

typedef struct PooPileWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    PooPos pos;
    Collider collider;
    PooNode node;
    u16 stage;
    TaskPool tasks;
    Task* task;
    u8 colliderActive;
} PooPileWork;

typedef struct PooPigletWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    u8 flipped;
    u16 animIndex;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    Collider collider;
    TaskPool tasks;
    u32 state;
    u16 timer;
    s32 speed;
    u16 interactionId;
} PooPigletWork;

typedef struct PooEeyoreWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    Collider collider;
    TaskPool tasks;
    s32 animId;
    u16 tileBytes;
    u16 moveTimer;
    u8 colliderActive;
    u16 interactionId;
} PooEeyoreWork;

typedef struct PooRabbitWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    u8 flipped;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    TaskPool tasks;
    Collider collider;
    s32 animIndex;
    u16 timer;
    u16 interactionId;
    u16 waitTimer;
} PooRabbitWork;

typedef struct PooGfxDesc {
    void* gfxTable;
    u16 gfxCount;
} PooGfxDesc;

typedef struct PooTiggerWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    u8 flipped;
    u16 animIndex;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    Collider collider;
    TaskPool tasks;
    s32 targetX;
    s32 targetY;
    s32 targetZ;
    u8 unk_B4[0x04];
    u8 heading;
    s16 hopTimer;
    u16 stepTimer;
    u16 step;
    s32 mode;
    u8 unk_C4[0x04];
    PooShadowInfo shadowInfo;
    u8 onCollider;
    u8 isTigger;
    u16 tileBytes;
} PooTiggerWork;

typedef struct PooBalloonWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    PooPos pos;
    Collider collider;
    PooNode node;
    TaskPool tasks;
    Task* task;
    Task* freeBalloonTask;
    u16 tileBytes;
    u16 angle;
} PooBalloonWork;

typedef struct PooOwlBalloonWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    PooPos pos;
    Collider collider;
    PooNode node;
    TaskPool tasks;
    Task* task;
    u16 tileBytes;
} PooOwlBalloonWork;

typedef struct PooPrizeWork {
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    Collider collider;
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    void (*update)(struct PooPrizeWork* w);
    u16 kind;
    u16 timer;
    s32 vz;
    s32 speed;
    u8 angle;
    u8 spin;
    s32 scale;
    u16 amount;
    u8 visible;
    u8 collected;
} PooPrizeWork;

typedef struct PooEeyoreTailWork {
    void* tiles;
    void* palette;
    void* gfx;
    u32 x;
    u32 y;
    s32 z;
    s32 ground;
    u16 tileBytes;
    u32 height;
    TaskPool tasks;
} PooEeyoreTailWork;

typedef struct PooFreeBalloonWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    PooPos pos2;
    PooPos pos3;
    s16 x;
    s16 y;
    void* tiles2;
    void* palette2;
    void* gfx2;
    AnimState anim2;
    PooPos pos4;
    PooPos pos5;
    s16 x2;
    s16 y2;
    u16 timer;
    PooPos* pos;
} PooFreeBalloonWork;

typedef struct PooMapObjHitDesc {
    void* tiles;
    u16 gfxCount;
    void* anims;
    void* gfxTable;
    void* palette;
} PooMapObjHitDesc;

typedef struct PooSpawn {
    s32 x;
    s32 y;
    TaskDesc* desc;
} PooSpawn;

typedef struct PooSpawnArgs {
    PooPos pos;
    u16 prizeId;
} PooSpawnArgs;

typedef struct PooMapObjHitArgs {
    s32 x;
    s32 y;
    u8 unk_08[0x08];
    const PooMapObjHitDesc* desc;
    s32 kind;
    u16 prizeId;
} PooMapObjHitArgs;

typedef struct PooMapObjHitWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_30[0x04];
    const PooMapObjHitDesc* desc;
    u8 playing;
    u16 tileBytes;
    Collider collider;
    s32 kind;
    u16 prizeId;
} PooMapObjHitWork;

typedef struct PooLeafWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_30[0x04];
    Collider collider;
    u8 playing;
    u16 tileBytes;
    u16 prizeId;
} PooLeafWork;

typedef struct PooOwlWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    PooPos pos;
    TaskPool tasks;
    u8 flying;
    u8 descending;
    u16 flyTimer;
    u16 tileBytes;
} PooOwlWork;

typedef struct PooStumpWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_30[0x04];
    Collider collider;
} PooStumpWork;

typedef struct PooFootmarkWork {
    void* tiles;
    void* palette;
    void* gfx;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    PooNode node;
} PooFootmarkWork;

typedef struct PooBoardWork {
    void* tiles;
    void* palette;
    void* gfx;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_18[0x04];
    Collider collider;
} PooBoardWork;

typedef struct PooVegetableWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    u16 tileBytes;
    Collider collider;
} PooVegetableWork;

typedef struct PooTanpopoWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    void* tiles2;
    void* gfx2;
    AnimState anim2;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_50[0x04];
    Collider collider;
    u8 playing;
    u16 tileBytes;
    u16 tileBytes2;
    u16 prizeId;
} PooTanpopoWork;

typedef struct PooHoneycombWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    u16 tileBytes;
    Collider collider;
    u16 shakeTimer;
    u16 angle;
    s32 shakeX;
    u8 colliderActive;
} PooHoneycombWork;

typedef struct PooBeeSub {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x04];
    s32 targetX;
    s32 targetY;
    u8 unk_18[0x08];
} PooBeeSub;

typedef struct PooBeeWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    PooBeeSub sub[4];
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    s32 dx;
    s32 dy;
    u8 unk_BC[0x0A];
    u16 releaseTimer;
    u8 setupPending;
} PooBeeWork;

typedef struct PooWagonWork {
    void* tiles;
    void* palette;
    void* gfx;
    void* tiles2;
    void* gfx2;
    void* tiles3;
    void* gfx3;
    PooPos pos;
    PooPos pos2;
    u8 poohAboard;
    u16 timer;
    u16 angle;
} PooWagonWork;

typedef struct PooWheelWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    u16 tileBytes;
    u16 animId;
    s32 speed;
    s32 startX;
    u8 removeWhenOffscreen;
} PooWheelWork;

typedef struct PooCabbageWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    s32 targetX;
    s32 targetY;
    s32 targetZ;
    s32 unk_40;
    Collider collider;
    s32 hopHeight;
    u16 state;
    TaskPool tasks;
    Task* task;
    s32 speed;
    s32 vz;
    u8 angle;
    u16 moveTimer;
    u16 zTimer;
    u16 age;
    u8 colliderActive;
    u8 wasOnScreen;
    u8 animating;
    u16 stackIndex;
} PooCabbageWork;

typedef struct PooCabbageBornWork {
    TaskPool tasks;
    u16 unk_14;
    u16 timer;
} PooCabbageBornWork;

typedef struct PooMapButterflyWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_30[0x04];
    u8 onScreen;
} PooMapButterflyWork;

typedef struct PooBflyPart {
    void* tiles;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_2C;
    s32 pointAX;
    s32 pointAY;
    s32 pointBX;
    s32 pointBY;
    s32 targetX;
    s32 targetY;
    u8 angle;
    s32 dirIndex;
    u8 flipped;
    u16 timer;
    u8 unk_54[0x14];
} PooBflyPart;

typedef struct PooMapBeeWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_30[0x04];
    u8 onScreen;
    u16 state;
} PooMapBeeWork;

typedef struct PooZzzWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    void* pos;
} PooZzzWork;

typedef struct PooPileDesc {
    s32 x;
    s32 y;
    u16 kind;
} PooPileDesc;

typedef struct PooCabbageAfterEventWork {
    void* tiles;
    void* palette;
    void* gfx;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    u16 tileBytes;
} PooCabbageAfterEventWork;

typedef struct PooRabbitAfterEventWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    TaskPool tasks;
    Collider collider;
    u16 tileBytes;
    u16 interactionId;
} PooRabbitAfterEventWork;

typedef struct PooBeeAfterEventWork {
    void* tiles;
    void* tiles2;
    void* palette;
    void* gfx;
    void* gfx2;
    AnimState anim;
    AnimState anim2;
    s32 x;
    s32 y;
    s32 z;
    u32 ground;
} PooBeeAfterEventWork;

typedef struct PooMapAnimeWork {
    BosMapanimeState anims[2];
} PooMapAnimeWork;

typedef struct PooSparkWork {
    PooPos pos;
    AnimState anim;
    void* tiles;
    void* palette;
    u8 unk_30[0x04];
} PooSparkWork;

typedef struct PooButterflyWork {
    PooBflyPart parts[2];
    void* palette;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_E0;
} PooButterflyWork;

enum PooSoraFlag {
    POO_SORA_FLAG_FLIP_X = 0x2
};

typedef struct PooSoraWork {
    void* tiles;
    void* palette;
    AnimState anim;
    void* gfx;
    TaskPool tasks;
    Collider collider;
    u32 state;
    s16 timer;
    s32 vz;
    u16 flags;
    s32 animAction;
    const u16* sounds;
    u8 onCollider;
    PooNode node;
} PooSoraWork;

typedef struct PooTrapWork {
    void* tiles;
    void* palette;
    void* gfx;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    Collider collider;
    TaskPool tasks;
    u8 colliderActive;
    PooNode node;
} PooTrapWork;

typedef struct PooRooWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    u8 flipped;
    PooPos pos;
    PooPos* srcPos;
    Collider collider;
    TaskPool tasks;
    s32 vz;
    s32 lastZ;
    u32 state;
    u16 interactionId;
} PooRooWork;

typedef struct PooBgSet {
    void* map;
    void* tiles;
    void* palette;
} PooBgSet;

#define POO_PAL_STEP_END 0xFF

typedef struct PooPalStep {
    u16 palette;
    u16 duration;
} PooPalStep;

extern const s32 gPooMainEventIds[];

extern const BosMapanimeDef gPooMapanimeDef0;
extern const s32 gPooPileKindStages[];
extern const PooAnimDesc gPooPigletAnimDescs[];
extern const PooAnimDesc gPooSoraAnimDescs[11][5];
extern const u16 gPooSoraSounds[8];
extern const PooAnimDesc gPooTiggerAnimDescs[];
extern const u16 gPooCabbageRemoveCounts[];
extern const PooMapObjHitDesc gPooMapObjHitDescs[];
extern const PooPileDesc gPooPileDescs[];
extern const PooAnimDesc gPooRabbitAnimDescs[];
extern const PooTileDesc gPooTileDescs[];
extern const PooSpawn gPooSpawns[85];
extern const s32 gPooTiggerHopHeights[];
extern const s32 gPooTiggerHopCorners[8];
extern const PooGfxDesc gPooTiggerGfxDescs[];
extern const PooGfxDesc gPooRabbitGfxDescs[];
extern const PooGfxDesc gPooPigletGfxDescs[];

extern const PooPoint gPooBeePoints[];
extern const BosMapanimeDef gPooMapanimeDef1;

s32 GetPooManhattanDistance(PooPos* from, PooPos* to);
void SetPoohPalette(PoohWork* work, u32 action);
void task_poo_mapbee_0(PooMapBeeWork* work, PooPos* pos);
void task_poo_zzz_2(PooZzzWork* work);
s32 GetPooWagonSide(s32 posX, s32 posY);
u8 task_poo_wagonwheel_1(PooWheelWork* work);
u8 task_poo_gauge_1(PooGaugeWork* work);
void task_poo_roo_0(PooRooWork* work, PooPos* pos);
u8 task_poo_roo_1(PooRooWork* work);
void task_poo_roo_2(PooRooWork* work);
void task_poo_shadowdodai_2(PooShadowWork* work);
void task_poo_pooh_2(PoohWork* work);
void task_poo_pooh_3(PoohWork* work);
u8 task_poo_butterflyRight_1(PooButterflyWork* work);
void task_poo_butterflyRight_2(PooButterflyWork* work);
u8 task_poo_butterflyLeft_1(PooButterflyWork* work);
void task_poo_butterflyLeft_2(PooButterflyWork* work);
u8 task_poo_mapbeeborn_1(PooMapBornWork* work);
u8 task_poo_mapbutterflyborn_1(PooMapBornWork* work);
u8 task_poo_leaf_1(PooLeafWork* work);
u8 GetPooScreenOverflow(s16 x, s16 y, s16 h, s16 vy, s16 w, s16 vx, s32* ox, s32* oy);
void SetPooTiggerrooAnimation(PooTiggerWork* work, u16 flags);
u8 task_poo_tiggerroo_1(PooTiggerWork* work);
void task_poo_tiggerroo_2(PooTiggerWork* work);
s32 IsInPooWagonAreaForPooh(PooPos* pos);
u8 task_poo_eeyoretail_1(PooEeyoreTailWork* work);
void MovePooh(PoohWork* work, s32 maxSpeed, u8 faceTarget);
void task_poo_shadowscale_2(PooScaleWork* work);
void task_poo_wagon_0(PooWagonWork* work);
u8 task_poo_wagon_1(PooWagonWork* work);
void task_poo_zzz_0(PooZzzWork* work, u8* arg);
u8 IsPoohBeeChaseOver();
void PooBflyPartUpdate(PooBflyPart* part);
u8 task_poo_owlballoon_1(PooOwlBalloonWork* work);
s32 GetPoohStumpIndex(PoohWork* work);
PooNode* FindPoohTargetNode();
void StartPooTiggerHopStep(PooTiggerWork* work);
void SnapToPooWagonLine(u32* px, u32* py, u16 steps);
void GetPooCabbageStackSpot(PooSpot* spot);
void task_poo_eeyoretail_0(PooEeyoreTailWork* work);
void task_poo_honeycomb_0(PooHoneycombWork* work);
void task_poo_spark_2(PooSparkWork* work);
s32 GetPooNodeScore(PooNode* node);
u16 CreatePooMapobjhitTasks(void* pool, u16 prizeId);
u8 IsPooPosBlocked(PooPos* pos);
u8 GetPooWallSlide(PooActor* actor, s32 x, s32 y, s32* ox, s32* oy);
void task_poo_gauge_0(PooGaugeWork* work);
void task_poo_mapbeeborn_0(PooMapBornWork* work, PooPos* pos);
void task_poo_mapbutterflyborn_0(PooMapBornWork* work, PooPos* pos);
void task_poo_butterfly_0(PooButterflyWork* work, PooPos* pos);
void task_poo_freeballoon_0(PooFreeBalloonWork* work, PooPos* pos);
void task_poo_butterfly_3(PooButterflyWork* work);
void task_poo_mapbutterfly_0(PooMapButterflyWork* work, PooPos* pos);
void task_poo_shadowdodai_0(PooShadowWork* work, PooShadowArgs* args);
void task_poo_shadowscale_0(PooScaleWork* work, PooShadowArgs* args);
void CreatePooMapobjhitTask(void* pool, u32 kind, s32 x, s32 y, u16 prizeId);
void task_poo_zzz_3(PooZzzWork* work);
void SetPooRabbitAnimation(PooRabbitWork* work, s32 animIndex, u16 flags);
void PooBflyPartInit(PooBflyPart* part);
void task_poo_roo_footmark_0(PooFootmarkWork* work);
void task_poo_spark_0(PooSparkWork* work, PooPos* pos);
void task_poo_trap_0(PooTrapWork* work, PooPos* pos);
u8 CanSpawnPooCabbage();
void UpdatePoohGauge(PoohWork* work);
void UpdatePoohAction(PoohWork* work, PooNode* node);
u8 task_poo_pooh_1(PoohWork* work);
u8 task_poo_mapbee_1(PooMapBeeWork* work);
void task_poo_roo_3(PooRooWork* work);
u8 IsPooRooAnimFrameEnding();
u8 IsPooRooAnimFinished();
u8 IsPoohOffScreen();
void task_poo_tanpopo_3(PooTanpopoWork* work);
void task_poo_ti_board_0(PooBoardWork* work, PooPos* pos);
u8 task_poo_ti_board_1(PooBoardWork* work);
void task_poo_honeycomb_3(PooHoneycombWork* work);
void task_poo_bee_0(PooBeeWork* work);
u8 task_poo_bee_1(PooBeeWork* work);
void task_poo_vegetable_0(PooVegetableWork* work);
u8 task_poo_vegetable_1(PooVegetableWork* work);
u8 IsPooSoraOverWagon();
void ProjectToPooWagonEdgeUL(s32* px, s32* py);
void ProjectToPooWagonEdgeLR(s32* px, s32* py);
void ProjectToPooWagonEdgeUR(s32* px, s32* py);
void task_poo_wagon_2(PooWagonWork* work);
void task_poo_wagon_3(PooWagonWork* work);
void task_poo_wagonwheel_3(PooWheelWork* work);
void task_poo_spark_3(PooSparkWork* work);
u8 IsPooBeeAfterEventVisible();
void task_poo_cabbage_3(PooCabbageWork* work);
void task_poo_cabbageborn_0(PooCabbageBornWork* work);
u8 task_poo_cabbageborn_1(PooCabbageBornWork* work);
void PooBflyPartSetAnimation(PooBflyPart* part);
u8 task_poo_butterfly_1(PooButterflyWork* work);
void task_poo_mapbee_3(PooMapBeeWork* work);
u8 task_poo_mapbutterfly_1(PooMapButterflyWork* work);
void CreatePooPileTasks(void* pool);
void PooBflyPartSetDir(PooBflyPart* part);

void AddPooNode(PooNode* node, u16 weight, void* pos);
void task_poo_honey_3(PooHoneyWork* work);
u8 task_poo_mapanime_1(PooMapAnimeWork* work);
s32 GetRandomPooPileStage();
void task_poo_pile_3(PooPileWork* work);
void CreatePooPileTask(void* pool, u16 kind, s32 x, s32 y);
void task_poo_tigerstump_0(PooStumpWork* work, PooPos* pos);
u8 task_poo_tigerstump_1(PooStumpWork* work);
void task_poo_poohstump_0(PooStumpWork* work, PooPos* pos);
u8 task_poo_poohstump_1(PooStumpWork* work);
void SetPooPigletAnimation(PooPigletWork* work, s32 animIndex, u16 flags);
u8 task_poo_piglet_1(PooPigletWork* work);
void task_poo_piglet_3(PooPigletWork* work);
void task_poo_eeyore_3(PooEeyoreWork* work);
u8 task_poo_rabbit_1(PooRabbitWork* work);
void task_poo_rabbit_3(PooRabbitWork* work);
u16 GetPooTiggerAnimDuration(PooTiggerWork* work);
void task_poo_tiggerroo_3(PooTiggerWork* work);
void task_poo_trapballoon_3(PooBalloonWork* work);
void task_poo_owlballoon_3(PooOwlBalloonWork* work);
s32 GetPooGroundZ(Collider* collider, PooPos* pos, u8* onCollider);
u8 task_poo_map_1(PooMapWork* work);
u16 GetPooMapTile(u16 x, u16 y);
u8 IsPooExitTile(PooPos* pos);
void UpdatePooActorAngle(PooActor* actor);
void SetPooSoraAnimation(PooSoraWork* work, s32 animAction, u16 flags);
void SetPooSoraAttackPoint(PooActor* actor);
s32 GetPooSoraGroundZ(PooSoraWork* work);
void task_poo_sora_3(PooSoraWork* work);
u8 task_poo_sora_1(PooSoraWork* work, Task* task);
u8 PooSoraUpdateCall(PooSoraWork* work, Task* task);
u8 PooSoraUpdateJump(PooSoraWork* work, Task* task);
u8 PooSoraUpdateAttack(PooSoraWork* work, Task* task);
void task_poo_trapballoon_2(PooBalloonWork* work);
u8 ConstrainPooActorMove(PooActor* actor, s32 x, s32 y);
u8 IsPooSoraCallStarting();
u8 IsPooSoraCalling();
u8 task_poo_trap_1(PooTrapWork* work);
void task_poo_shadow_0(TaskPool* pool, void* arg);
u8 IsPooNearScreen(s16 x, s16 y);
s32 GetPooGaugeFrame(u16 timer);
void task_poo_gauge_2(PooGaugeWork* work);
void UpdatePooCameraCenter();
void ScrollPooCamera(PooMapWork* work);
void SetPooActorAngleFromDpad(PooActor* actor);
void task_poo_butterfly_2(PooButterflyWork* work);
u8 task_poo_prize_1(PooPrizeWork* work);
void task_poo_prize_3(PooPrizeWork* work);
u8 AreAllPooEventsDone();
u8 IsPooSoraOnWagon();
void task_poo_eeyoretail_3(PooEeyoreTailWork* work);
void task_poo_freeballoon_3(PooFreeBalloonWork* work);
void task_poo_leaf_3(PooLeafWork* work);
void task_poo_mapanime_0(PooMapAnimeWork* work);
void task_poo_mapbeeborn_3(PooMapBornWork* work);
void task_poo_owl_3(PooOwlWork* work);
void task_poo_poohstump_3(PooStumpWork* work);
void task_poo_roo_footmark_3(PooFootmarkWork* work);
u8 task_poo_spark_1(PooSparkWork* work);
void task_poo_ti_board_3(PooBoardWork* work);
void task_poo_tigerstump_3(PooStumpWork* work);
void task_poo_vegetable_3(PooVegetableWork* work);
u8 PooBflyPartDraw(PooBflyPart* part, void* pal);
void task_poo_mapobjhit_3(PooMapObjHitWork* work);
void PooPrizeUpdateCollect(PooPrizeWork* work);
u16 CreatePooSpawnTasks(void* pool, u16 prizeId);
u8 task_poo_honeycomb_1(PooHoneycombWork* work);
u8 task_poo_eeyore_1(PooEeyoreWork* work);
void task_poo_mapobjhit_2(PooMapObjHitWork* work);
void task_poo_ti_board_2(PooBoardWork* work);
void task_poo_cabbageAfterEvent_2(PooCabbageAfterEventWork* work);
void StartPooTiggerHop(PooTiggerWork* work);
void task_poo_tigger_0(PooTiggerWork* work);
void task_poo_tiggerroo_0(PooTiggerWork* work);
void task_poo_trap_2(PooTrapWork* work);
void SetPooTiggerAnimation(PooTiggerWork* work, u16 flags);
void task_poo_wagonwheel_0(PooWheelWork* work);
void task_poo_trapballoon_0(PooBalloonWork* work, PooPos* pos);
void task_poo_owlballoon_0(PooOwlBalloonWork* work, PooPos* pos);
u8 ApplyPooSoraPushOut(PooSoraWork* work, PooPos* pos);
u8 GetPooAngleToPooh(PooPos* pos);
void task_poo_owl_0(PooOwlWork* work);
u8 task_poo_owl_1(PooOwlWork* work);
void task_poo_rabbitAfterEvent_0(PooRabbitAfterEventWork* work);
void task_poo_balloon_2(PooBalloonObjWork* work);
void task_poo_mapbeeborn_2(PooMapBornWork* work);
void task_poo_mapbutterflyborn_2(PooMapBornWork* work);
void task_poo_mapbutterfly_2(PooMapButterflyWork* work);
void task_poo_freeballoon_2(PooFreeBalloonWork* work);
void task_poo_mapobjhit_0(PooMapObjHitWork* work, PooMapObjHitArgs* args);
void task_poo_mapbee_2(PooMapBeeWork* work);
void task_poo_leaf_0(PooLeafWork* work, PooSpawnArgs* args);
void task_poo_beeAfterEvent_0(PooBeeAfterEventWork* work);
u8 task_poo_tanpopo_1(PooTanpopoWork* work);
void task_poo_pile_0(PooPileWork* work, PooPileArgs* args);
u8 task_poo_cabbageAfterEvent_1(PooCabbageAfterEventWork* work);
void PlayPooTiggerHopSound(s32 x, s32 y, s32 z, u8 isTigger);
u8 IsPoohNearScreenEdge();
void ResetPoohStumpCount(PoohWork* work);
void task_poo_pitAndButterfly_0(PooTrapWork* work, PooPos* pos);
u8 CheckPoohInterrupts(PoohWork* work, PooNode* node);
void ChoosePoohTarget(PoohWork* work, PooNode* node);
void task_poo_sora_0(PooSoraWork* work);
u8 task_poo_pile_1(PooPileWork* work);
u8 task_poo_freeballoon_1(PooFreeBalloonWork* work);
void task_poo_prize_0(PooPrizeWork* work, PoohPrizeArgs* args);
void PooPrizeUpdateBounce(PooPrizeWork* work);
void ClampToPooWagonArea(u32* px, u32* py, u16 steps);
void task_poo_bee_2(PooBeeWork* work);
void task_poo_map_0(PooMapWork* work);
u8 task_poo_trapballoon_1(PooBalloonWork* work);
u8 task_poo_cabbage_1(PooCabbageWork* work);
void task_poo_cabbage_2(PooCabbageWork* work);
void task_poo_pooh_0(PoohWork* work);
extern const u16 gPooCabbageStackPriorities[];
void UpdatePoohStumpCircle(PoohWork* work);
s32 GetPooWagonNearestSide(s32 x, s32 y);
u8 HandlePoohRequest(PoohWork* work);

void task_poo_mapbutterflyborn_3(PooMapBornWork* work);
void task_poo_trap_3(PooTrapWork* work);
u8 task_poo_pitAndButterfly_1(PooTrapWork* work);
void task_poo_pitAndButterfly_2(PooTrapWork* work);
void task_poo_pitAndButterfly_3(PooTrapWork* work);
u8 task_poo_rabbitAfterEvent_1(PooRabbitAfterEventWork* work);
void task_poo_rabbitAfterEvent_3(PooRabbitAfterEventWork* work);
void ProjectToPooWagonEdgeLL(s32* px, s32* py);
u8 IsPooCabbageGameActive();
void task_poo_cabbageAfterEvent_0(PooCabbageAfterEventWork* work);
u16 GetPooCabbageLandedCount();
u32 NextPoohStumpIndex(u32 index);
void task_poo_bee_3(PooBeeWork* work);
void task_poo_cabbageAfterEvent_3(PooCabbageAfterEventWork* work);
u8 AreAllPooBeesOut();
void ApplyPooh04FrameOffset(PoohWork* work);
u8 task_poo_beeAfterEvent_1(PooBeeAfterEventWork* work);
void task_poo_beeAfterEvent_3(PooBeeAfterEventWork* work);

s32 IsInPooWagonArea(PooPos* pos);
void task_poo_map_2(PooMapWork* work);
void task_poo_map_3(PooMapWork* work);
void UnfreezePooCamera();
void StartPooCameraFollowPooh();
u16 GetPooSoraPriority();
void IncPooCabbageLandedCount();
u8 task_poo_shadowdodai_1(PooShadowWork* work);
u8 task_poo_shadowscale_1(PooScaleWork* work);
void ApplyPooh04aFrameOffset(PoohWork* work);
void SetPooCameraFocus(s32 x, s32 y);
void RemovePooNode(PooNode* node);
u8 IsPooEeyoreTailLanded();
u8 IsPooHoneycombShaken();
void IncPooCabbageCount();
void task_poo_balloon_3(PooBalloonObjWork* work);
void task_poo_gauge_3(PooGaugeWork* work);
void task_poo_mapbutterfly_3(PooMapButterflyWork* work);
void task_poo_shadowdodai_3(PooShadowWork* work);
void task_poo_shadowscale_3(PooScaleWork* work);
void CreatePooShadowscaleTask(void* pool, void* pos, s32 scale);
s32 NextPooPileStage(u32 stage);
s32 GetPooPileHeight(u32 stage);
void ApplyPoohFrameOffset(PoohWork* work, const PooSpot* offsets, u16 frameCount);
u16 GetPooNodeWeight(PooNode* node);
void SetPooNodeWeight(PooNode* node, u16 weight);
u16 GetPooNodeBaseWeight(PooNode* node);
void SetPooNodeBaseWeight(PooNode* node, u16 weight);
u8 task_poo_balloon_1(void* work);
void task_poo_mapanime_2(void* work);
void task_poo_mapanime_3(void* work);
u8 task_poo_roo_footmark_1(void* work);
u8 task_poo_zzz_1(void* work);
void FreezePooCamera();
void StopPooCameraFollowPooh();
u16 GetPooWagonPriority2();
u16 GetPooWagonPriority();
u16 GetPooCabbageCount();
void task_poo_cabbageborn_2(PooCabbageBornWork* work);
void task_poo_cabbageborn_3(PooCabbageBornWork* work);
u8 task_poo_shadow_1(TaskPool* pool);
void task_poo_shadow_2(TaskPool* pool);
void task_poo_shadow_3(TaskPool* pool);
u8 IsPoohDescendingWithOwl();
u8 IsPoohOnOwlBalloon();
u8 IsPoohWalkingToTarget();
u8 IsPoohWaitingOnWagon();
u8 IsPoohAtLowerExit();
u16 GetPoohHoneyAnim();
u8 task_poo_honey_1(PooHoneyWork* work);
u8 IsPoohLookingAtHoneycomb();
void SetPooPrizeDropped(u16 prizeId);
u8 IsPooPrizeDropped(u16 prizeId);
void ResetPooProgress();
void GetPooStatePooh(PooPos* pos, s32* action);
void SetPooStateGauge(u16 gauge, u16 gaugeTimer);
void GetPooStateGauge(u16* gauge, u16* gaugeTimer);
void SetPooStateWheelPos(s16 x, s16 y);
void GetPooStateWheelPos(u16* x, u16* y);
void GetPooStatePos2(PooPos* pos);
void SetPooEventDone(s32 event);
void ClearPooFlag(s32 flag);
u16 AddPoohInteraction(Collider* collider, u16 message);
void SetPoohInteractionEnabled(u16 id, u8 enabled);
u16 FindPoohInteractionMessage();
void SetPooRabbitTalkBlocked(u8 blocked);

u16 GetPooExitAt(PooPos* pos);
u16 CheckPooSoraExit(PooPos* pos);

u8 IsPoohOnWagon();

#endif /* GUARD_POO_H */
