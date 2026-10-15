#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include "map_types.h"
#include "map_room_types.h"
#include "types.h"
#include "game_state.h"
#include "anim.h"
#include "mode.h"
#include "taskpool.h"
#include "fld_types.h"
#include "text_types.h"
#include "battle_actor_types.h"
#include "obj.h"
#include "card_types.h"

typedef struct MapPlatform {
    u16 left;
    u16 right;
    s32 z;
    u8 hasStairs;
    u16 x;
    u16 y;
    u8 spotType;
    s32 spotUpperZ;
    s32 spotLowerZ;
} MapPlatform;

enum MapEnmDefFlag {
    MAP_ENM_DEF_FLAG_NO_SHADOW = 0x1,
    MAP_ENM_DEF_FLAG_AIRBORNE = 0x2,
    MAP_ENM_DEF_FLAG_SPAWN_ANYWHERE = 0x4,
    MAP_ENM_DEF_FLAG_GUARD = 0x8
};

typedef struct MapEnmDef {
    const AnimDef* animDef;
    void* palette;
    u16 tileCount;
    u16 height;
    u16 radius;
    TaskDesc* desc;
    u16 flags;
} MapEnmDef;

typedef struct MapGmkDef {
    void* palette;
    const void* tiles;
    u16 tilesSize;
    void* gfxTable;
    void* anims;
    u8 ownTiles;
    u8 spotFinder;
    s16 offsetX;
    s16 offsetY;
    s16 offsetZ;
    u16 radius;
    u16 height;
    u16 hitSong;
    void* desc;
} MapGmkDef;

typedef struct MapAnmSlot {
    const void* tiles;
    u16 frameSize;
    u8* dest;
    u8* pending;
    s16 timer;
    void* script;
    s16* scriptPos;
} MapAnmSlot;

enum GmkFlag {
    GMK_FLAG_DESTROYED = 0x1,
    GMK_FLAG_USED = 0x2,
    GMK_FLAG_TOGGLED = 0x4,
    GMK_FLAG_HAS_ENEMY = 0x8
};

typedef struct MapGmkPlacement {
    u16 flags;
    FldPos pos;
    const MapGmkDef* def;
} MapGmkPlacement;

#define MAP_PATTERN_END 0xFF

typedef struct MapCellPattern {
    s16 dx;
    s16 dy;
    u8 bg3Piece;
    u8 bg2Piece;
    u16 edgeFlags;
    u16 edgeIgnoreMask;
    u8 unk_0A[0x02];
} MapCellPattern;

typedef struct MapCardAttributes {
    u16 kind;
    u16 value;
    u16 color;
} MapCardAttributes;

typedef struct PrizeEntry {
    u8 unk_00[0x02];
    u16 unk_02;
} PrizeEntry;

typedef struct PrzCardChance {
    u8 cardIndex;
    u16 weight;
    u16 weight2;
    u8 unk_06[0x02];
} PrzCardChance;

typedef struct MapPrizeArgs {
    u8 worldPrize;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_10[0x04];
    u16 id;
} MapPrizeArgs;

typedef struct MapEnmArgs {
    const MapEnmDef* def;
    void (*update)(struct MapEnmWork*);
    FldPos pos;
    u8 angle;
    s32 speed;
} MapEnmArgs;

enum MapEnmFlag {
    MAP_ENM_FLAG_HFLIP = 0x1,
    MAP_ENM_FLAG_PERSISTENT = 0x2,
    MAP_ENM_FLAG_REMOVED = 0x4,
    MAP_ENM_FLAG_AGGRESSIVE = 0x8,
    MAP_ENM_FLAG_SLOW = 0x10,
    MAP_ENM_FLAG_ASLEEP = 0x20,
    MAP_ENM_FLAG_FIRST_STRIKE = 0x40,
    MAP_ENM_FLAG_WHITE_MUSHROOM = 0x100,
    MAP_ENM_FLAG_BLACK_FUNGUS = 0x200
};

typedef struct MapEnmWork {
    const MapEnmDef* def;
    u16 flags;
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    s16 radius;
    s16 height;
    void (*update)(struct MapEnmWork*);
    u16 timer;
    u16 unk_D2;
    s32 targetX;
    s32 targetY;
    s32 targetZ;
    s16 colliderDelay;
    TaskPool tasks;
} MapEnmWork;

typedef struct MapEnm01Work {
    MapEnmWork enm;
    u8 wasOnScreen;
} MapEnm01Work;

typedef struct MapEnm03Work {
    MapEnmWork enm;
    FldPos home;
} MapEnm03Work;

typedef struct LoadGameMenuWork {
    ObjPalette* palette2;
    void* tiles2;
    s32 y;
    s32 y2;
    s32 x;
    AnimState anim;
    ObjPalette* palette;
    void* tiles;
    s32 y3;
    ObjPalette* palette7;
    TextSlot textSlots[0x24];
    u8 textSlotCount;
    u16 slotBaseY;
    ObjPalette* palette3;
    void* tiles3;
    ObjPalette* palette4;
    void* tiles4;
    ObjPalette* palette5;
    void* tiles5;
    ObjPalette* palette6;
    void* tiles6;
    u8 showRikuSlots;
    u8 forSioBattle;
    u8 loaded;
    u8 selectedSlot;
    u8 lastSlot;
    u16 timer;
    void (*update)(struct LoadGameMenuWork*);
} LoadGameMenuWork;

typedef struct MenuMsgWork {
    u8 toTitle;
    void (*update)(struct MenuMsgWork*);
    TaskPool tasks;
} MenuMsgWork;

typedef struct NewGameSlotMenuWork {
    ObjPalette* palette2;
    void* tiles2;
    s32 y;
    s32 y2;
    ObjPalette* palette3;
    void* tiles3;
    AnimState anim;
    ObjPalette* palette;
    void* tiles;
    s32 y3;
    ObjPalette* palette8;
    TextSlot textSlots[0x24];
    u8 textSlotCount;
    u16 slotBaseY;
    ObjPalette* palette9;
    TextSlot textSlots2[0x36];
    u8 textSlotCount2;
    ObjPalette* palette4;
    void* tiles4;
    ObjPalette* palette5;
    void* tiles5;
    ObjPalette* palette6;
    void* tiles6;
    ObjPalette* palette7;
    void* tiles7;
    u8 confirmed;
    u8 isRiku;
    u8 selectedSlot;
    u16 timer;
    void (*update)(struct NewGameSlotMenuWork*);
} NewGameSlotMenuWork;

typedef struct MapRndWork {
    TaskPool tasks;
} MapRndWork;

typedef struct MapMenuWork {
    ObjPalette* palette2;
    void* tiles2;
    s32 y;
    s32 y2;
    void* tiles3;
    s32 x;
    void* tiles4;
    s32 x2;
    ObjPalette* palette3;
    void* tiles5;
    s32 x3;
    s32 x4;
    s32 x5;
    u8 cursorVisible;
    ObjPalette* palette4;
    ObjPalette* palette5;
    void* tiles6;
    s32 x6;
    AnimState anim;
    ObjPalette* palette;
    void* tiles;
    s32 x7;
    s32 y3;
    ObjPalette* palette8;
    TextSlot textSlots[0x18];
    u8 textSlotCount;
    ObjPalette* palette6;
    void* tiles8;
    ObjPalette* palette7;
    void* tiles7;
    s32 x8;
    s32 y4;
    s32 playerStartX;
    s32 playerStartY;
    ObjPalette* palette9[0x03];
    void* tiles9[0x03];
    void* gfx[0x03];
    ObjPalette* confirmPalette;
#ifdef VERSION_EU
    TextSlot textSlots2[0x42];
#else
    TextSlot textSlots2[0x21];
#endif
    u8 textSlotCount2;
    TextSlot textSlots3[0x06];
    u8 textSlotCount3;
    TextSlot textSlots4[0x09];
    u8 textSlotCount4;
    u8 cursor;
    u8 confirmCursor;
    u16 steps;
    u8 panelsVisible;
    u8 reopened;
    s32 (*update)(struct MapMenuWork*);
} MapMenuWork;

typedef struct MapSaveWork {
    FldRes* palette2;
    void* tiles2;
    s32 y;
    s32 y2;
    s32 x;
    FldRes* palette3;
    void* tiles3;
    AnimState anim;
    FldRes* palette;
    void* tiles;
    s32 x2;
    FldRes* palette4;
    TextSlot textSlots[0x24];
    u8 textSlotCount;
    FldRes* palette5;
    void* tiles4;
    s32 x3;
    s32 y3;
    s32 playerStartX;
    s32 playerStartY;
    FldRes* palette6;
    void* tiles5;
    FldRes* palette7;
    void* tiles6;
    FldRes* palette8;
#ifdef VERSION_EU
    TextSlot textSlots2[0x36];
#else
    TextSlot textSlots2[0x1B];
#endif
    u8 textSlotCount2;
    TextSlot textSlots3[0x06];
    u8 textSlotCount3;
    TextSlot textSlots4[0x09];
    u8 textSlotCount4;
    s32 (*update)(struct MapSaveWork*);
    u8 confirmCursor;
    u16 steps;
    u8 dialogVisible;
    TaskPool tasks;
} MapSaveWork;

typedef struct MapAnmEntry {
    void* script;
    void* tiles;
    u16 frameSize;
    u8 tileOffset;
} MapAnmEntry;

typedef struct MapAnmWork {
    MapAnmSlot slots[8];
} MapAnmWork;

typedef struct MapDbgWork {
    u8 visible;
    u8* editing;
    void (*update)(struct MapDbgWork*);
    u8 seedCursor;
    u8 codeCursor;
    void* tiles;
    void* palette;
    u16 seedText[0x0A];
    u8 seedTextLength;
    u16 codeText[0x0A];
    u8 codeTextLength;
    u16 cursorText;
    u8 cursorTextLength;
} MapDbgWork;

typedef struct MapGmkEnmWork {
    FldObj obj;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    u8 (*update)(struct MapGmkEnmWork*);
    u8 flipX;
    s32 targetZ;
    u16 timer;
} MapGmkEnmWork;

typedef struct MapGmkDmyWork {
    void* tiles;
} MapGmkDmyWork;

typedef struct MapGmkJumpWork {
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    u8 unk_0BC[0x04];
    u8 state;
    s32 jumpHeight;
    void (*update)(struct MapGmkJumpWork*);
} MapGmkJumpWork;

typedef struct MapGmkTutorialWork {
    FldObj obj;
    Collider collider;
    void* tiles;
    ObjPalette* palette;
    u8 unk_0A4[0x04];
    u8 opened;
    u8 (*update)(struct MapGmkTutorialWork*);
    TaskPool tasks;
} MapGmkTutorialWork;

typedef struct MapGmk01Work {
    MapGmkPlacement* placement;
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    u16 timer;
    u8 (*update)(struct MapGmk01Work*);
} MapGmk01Work;

typedef struct MapGmkSpiderWork {
    FldObj obj;
    u8 unk_040[0x5C];
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    u8 (*update)(struct MapGmkSpiderWork*);
    u8 flipX;
} MapGmkSpiderWork;

typedef struct MapGmkGpWork {
    MapGmkPlacement* placement;
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    u16 hitSong;
    u16 timer;
    u8 (*update)(struct MapGmkGpWork*);
} MapGmkGpWork;

typedef struct MapGmkGp1Work {
    MapGmkPlacement* placement;
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    u16 hitSong;
    u8 visible;
    u8 (*update)(struct MapGmkGp1Work*);
} MapGmkGp1Work;

typedef struct MapGmk00Work {
    MapGmkPlacement* placement;
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    u16 radius;
    u16 unk_0C6;
    u8 visible;
    u8 stoodOn;
} MapGmk00Work;

typedef struct MapGmkBarrelWork {
    MapGmkPlacement* placement;
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    u8 visible;
    u8 (*update)(struct MapGmkBarrelWork*);
} MapGmkBarrelWork;

typedef struct MapPrizeWork {
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    Collider collider;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    void* gfx2;
    void (*update)(struct MapPrizeWork*);
    u16 kind;
    u16 timer;
    s32 vz;
    s32 speed;
    u8 angle;
    u8 angleStep;
    s32 scale;
    u16 amount;
    u8 visible;
    u8 collected;
} MapPrizeWork;

typedef struct MapGmkGp07Work {
    MapGmkPlacement* placement;
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    s32 (*update)(struct MapGmkGp07Work*);
} MapGmkGp07Work;

typedef struct MapGmkGp08Work {
    MapGmkPlacement* placement;
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    void* gfx2;
    u16 hitSong;
    u8 overlayVisible;
    s32 (*update)(struct MapGmkGp08Work*);
} MapGmkGp08Work;

typedef struct MapGmkGp09Work {
    MapGmkPlacement* placement;
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    void* gfx2;
    u8 overlayVisible;
    s32 (*update)(struct MapGmkGp09Work*);
} MapGmkGp09Work;

typedef struct MapGmk04Work {
    MapGmkPlacement* placement;
    FldObj obj;
    Collider collider;
    ObjPalette* palette;
    void* tiles;
    AnimState anim;
    void* gfx;
    void (*update)(struct MapGmk04Work*);
    TaskPool tasks;
} MapGmk04Work;

typedef struct MapGmk05Work {
    u8 unk_000[0x04];
    FldObj obj;
    Collider collider;
    ObjPalette* palette;
    void* tiles;
    AnimState anim;
    void* gfx;
    void (*update)(struct MapGmk05Work*);
    u8 targeted;
    TaskPool tasks;
    TaskPool tasks2;
} MapGmk05Work;

typedef struct MapGmk06Work {
    u8 unk_000[0x04];
    FldObj obj;
    Collider collider;
    AnimState anim;
    ObjPalette* palette;
    void* tiles;
    void* gfx;
    void (*update)(struct MapGmk06Work*);
    TaskPool tasks;
} MapGmk06Work;

typedef struct MapPrzCardWork {
    s32 posX;
    s32 posY;
    s32 posZ;
    s32 ground;
    Collider collider;
    FldRes* palette;
    void* tiles;
    FldRes* palette2;
    void* tiles2;
    void* tiles3;
    void* tiles4;
    ObjPalette* palette3;
    u16 spriteFlags;
    u16 timer;
    void (*update)(struct MapPrzCardWork*);
    CardStat stat;
    u16 cardId;
    s32 vz;
    s32 speed;
    s16 scaleX;
    s16 scaleY;
    u8 angle;
    s16 x;
    s16 y;
    u16 priority;
    s32 dirX;
    s32 dirY;
    s32 distance;
    s16 scale;
    u8 rotation;
    u8 phaseY;
    u8 phaseX;
    u8 worldPrize;
    u8 collected;
    TaskPool tasks;
} MapPrzCardWork;

typedef struct MapPrzStockWork {
    u16* stock;
    void (*update)(struct MapPrzStockWork*);
    TaskPool tasks;
} MapPrzStockWork;

typedef struct MapSparkWork {
    FldObj* obj;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    u8 unk_24[0x04];
} MapSparkWork;

typedef struct MapFaintWork {
    FldObj* obj;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    u8 unk_24[0x04];
} MapFaintWork;

typedef struct MapDmgWork {
    ObjPalette* palette;
    void* tiles;
    u8 visible;
    u8 enabled;
    u16 timer;
} MapDmgWork;

typedef struct MapTalkWork {
    FldObj* obj;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    u8 unk_24[0x04];
    u8 playerOnRight;
} MapTalkWork;

typedef struct MapDonaldWork {
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void (*update)(struct MapDonaldWork*);
    u8 targeted;
    u8 visible;
    TaskPool tasks;
    TaskPool tasks2;
} MapDonaldWork;

typedef struct MapGoofyWork {
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void (*update)(struct MapGoofyWork*);
    u8 targeted;
    u8 visible;
    TaskPool tasks;
    TaskPool tasks2;
} MapGoofyWork;

typedef struct MapNamineWork {
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void (*update)(struct MapNamineWork*);
    u8 registered;
    u8 targeted;
    u8 visible;
    u16 spriteFlags;
    TaskPool tasks;
    TaskPool tasks2;
} MapNamineWork;

typedef struct MapMickeyWork {
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void (*update)(struct MapMickeyWork*);
    u8 targeted;
    u8 visible;
    u16 spriteFlags;
    TaskPool tasks;
    TaskPool tasks2;
} MapMickeyWork;

typedef struct MapTutorialWork {
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    u8 visible;
    u8 shadowVisible;
    u8 flip;
    void (*update)(struct MapTutorialWork*);
    TaskPool tasks;
    TaskPool tasks2;
} MapTutorialWork;

typedef struct MapNiserikuWork {
    FldObj obj;
    Collider collider;
    AnimState anim;
    void* tiles;
    ObjPalette* palette;
    void (*update)(struct MapNiserikuWork*);
    u8 registered;
    u8 targeted;
    u8 visible;
    TaskPool tasks;
    TaskPool tasks2;
} MapNiserikuWork;

typedef struct MapFloorWork {
    void* tiles;
    void* palette;
    void* gfx;
    s16 textX;
    u16 timer;
    u8 textSlotCount;
    void* palette2;
#ifdef VERSION_EU
    TextSlot textSlots[0x3C];
#else
    TextSlot textSlots[0x28];
#endif
} MapFloorWork;

typedef struct MapMsgWork {
    FldRes* palette;
    TextSlot textSlots[0x30];
    u8 textSlotCount;
    s16 textX;
    u16 timer;
} MapMsgWork;

typedef struct MapStairWork {
    FldObj obj;
    ObjPalette* palette;
    void* tiles;
    u8 visible;
    void (*update)(struct MapStairWork*);
    TaskPool tasks;
} MapStairWork;

typedef struct MapFixWork {
    u8 colliderCount;
    Collider colliders[5];
    TaskPool tasks;
#ifdef VERSION_EU
    u8 bg3MapLoaded;
    u8 bg2MapLoaded;
    u8 bg1MapLoaded;
#endif
} MapFixWork;

typedef struct MapDoorGfx {
    void* palette;
    void* side0Closed;
    void* side0Open;
    void* side3Closed;
    void* side3Open;
    void* side2Closed;
    void* side2Open;
    void* side1Closed;
    void* side1Open;
} MapDoorGfx;

typedef struct MapDoorWork {
    MapDoor* door;
    FldObj obj;
    void* tiles;
    ObjPalette* palette;
    void* sprite;
    void* closedSrc;
    void* openSrc;
    void* tiles2;
    ObjPalette* palette2;
    void* sprite2;
    void* openSrc2;
    void* closedSrc2;
    u8 (*update)(struct MapDoorWork*);
    u8 visible;
    u8 triggered;
    TaskPool tasks;
} MapDoorWork;

extern MapRoomState* gMapRoomState;

extern const MapGmkDef gWorldMapGmkDefs[];
extern const MapGmkDef gMapGmkBarrelDef;
extern const MapGmkDef gMapGmk01Def;
extern const MapGmkDef gMapGmk04Def;
extern const MapGmkDef gMapGmkDefs[];
extern const MapGmkDef gMapGmk05Def;
extern const MapGmkDef gMapGmk06Def;
extern const u8 gDonaldTalkMessages[28];
extern const u8 gGoofyTalkMessages[28];
extern const u8 gSoraFloorEvents[13];
extern const u8 gRikuFloorEvents[13];
extern const u8 gCellMasks[][8];
extern u8 gMapQuickSaveConfirmText[];
extern u8 gMapSaveCompleteText[];
extern u8 gNewGameSlotMenuText[];
extern u8 gMapSaveConfirmText[];
extern const MapDoorGfx gWorldMapDoorGfx[14];

void MapMenuInitConfirm(MapMenuWork* work);
void LoadGameMenuSlideInX(LoadGameMenuWork* work);
void LoadGameMenuMoveCursor(LoadGameMenuWork* work);
void LoadGameMenuInput(LoadGameMenuWork* work);
void LoadGameMenuSlideOutX(LoadGameMenuWork* work);
void LoadGameMenuExit(LoadGameMenuWork* work);
void LoadGameMenuSlideOutY(LoadGameMenuWork* work);
void MapRestoreBg1();
void MapDrawBg1(s32 x, s32 y);
void MapFindLowestEdgeRightward(s32 type, s16* px, s16* py, s16* pz, s16 lo, s16 hi);
void MapEnmInit(MapEnmWork* work, MapEnmArgs* arg);

s32 LoadGameMenuLoadFile(u8 slot);
s32 MapSaveSlideInX(MapSaveWork* work);
s32 MapMenuSlideInX(MapMenuWork* work);
s32 MapMenuSoraInput(MapMenuWork* work);
s32 MapMenuSlideInY(MapMenuWork* work);
s32 MapMenuRikuInput(MapMenuWork* work);
s32 MapMenuOpenSubMode(MapMenuWork* work);
s32 MapMenuSlideOutX(MapMenuWork* work);
s32 MapMenuConfirmInput(MapMenuWork* work);
s32 MapMenuSlideOutY(MapMenuWork* work);
s32 MapMenuResume(MapMenuWork* work);
s32 Task_MapMenu_1(MapMenuWork* work);
s32 MapMenuOpen(MapMenuWork* work);
s32 MapSaveSlideInY(MapSaveWork* work);
s32 MapSaveInput(MapSaveWork* work);
s32 MapSaveWaitClose(MapSaveWork* work);
s32 MapSaveSlideOutX(MapSaveWork* work);
s32 MapSaveSlideOutY(MapSaveWork* work);
void MapPlaceDoorsOnLastPlatform();
void NewGameSlotMenuSlideIn(NewGameSlotMenuWork* work);
void NewGameSlotMenuInput(NewGameSlotMenuWork* work);
void NewGameSlotMenuSlideOut(NewGameSlotMenuWork* work);
void NewGameSlotMenuExit(NewGameSlotMenuWork* work);
void MapMenuFreeConfirm(MapMenuWork* work);
s32 Task_MapSave_1(MapSaveWork* work);
void MapFreeRoom();
void MapDrawBgs(s16 x, s16 y);
u8 RequestTilemapStripCopy(void* src, void* dst, u8 x, u8 y, u8 vertical);
void* GetSelectedMapCard();
u8 MapDoorWaitHit(MapDoorWork* work);
u8 MapDoorWaitCard(MapDoorWork* work);
u8 MapDoorWaitOpen(MapDoorWork* work);
void CreateWorldPrize(s32 x, s32 y, s32 z);
MapCell* MapGetCell(s16 x, s16 y);
void MapComputeRowBounds();
void MapCellSetBg3Piece(MapCell* cell, s32 piece);
void MapCellSetBg2CornerPiece(MapCell* cell, s32 piece);
void MapPlaceDoorOnPlatform(MapPlatform* platform, s32 side);
void MapBuildBgColumn(u16* bg3Map, u16* bg2Map, u16* bg1Map, s16 x, s16 y);
void MapBuildBgRow(u16* bg3Map, u16* bg2Map, u16* bg1Map, s16 x, s16 y);
u8 MapPickFreeFloorPos(FldPos* pos, s32* py);
u8 MapPickFreeFloorPosInView(FldPos* pos, s32* py);
void MapFixCreateGimmicks(void* gimmicks);
MapCell* MapFixGetCell(s16 x, s16 y);
void MapEnmSetupArgs(MapEnmArgs* arg, const MapEnmDef* def);
u8 MapEnmPlaceAtStairs(MapEnmArgs* arg);
u8 MapEnmPlaceAboveGmk01(MapEnmArgs* arg);
void MapEnmSpawnFixed(MapEnmArgs* arg, u8 kind, u8 place);
void MapEnmStartBattle(MapEnmWork* work);
const u8* GetCellMaskBlock(void* maskTable, u16 x, u16 y);
void* GetCellMaskTable(u8 type);
u8 FldObjIsOutOfView(FldObj* obj);
u16 MapGmkGetFreeTiles();
void CreateRandomMapPrizes(s32 x, s32 y, s32 z);
void MapFixLoadCellTypes(const u8* src);
void MapFixSnapCamera();
void MapFixInitCells(MapFixedDef* def);
void MapApplyLayer1DecorRule(MapDecorRule* rule);
u8 MapPatternFits(s16 x, s16 y, const MapCellPattern* pattern);
void MapPlaceLayer1DecorPiece(s16 x, s16 y, const u8* pieces, u16* base);
void MapPlaceLayer2DecorPiece(s16 x, s16 y, const u8* pieces, u16* base);
void MapApplyLayer2DecorRule(MapDecorRule* rule);
const PrizeEntry* PickRandomPrzCard(u8 worldPrize);
void NewGameSlotMenuLoadFloorTiles(u8 slot, u8 selected, u8 floor);
void NewGameSlotMenuLoadLevelTiles(u8 slot, u16 level);
void NewGameSlotMenuLoadTimeTiles(u8 slot, u32 playTime);

s32 FieldGroundAt(s32 x, s32 y, s32 z);
s32 GetFldPosFloor(FldPos* pos);
void FldPosPlaceAtCell(FldPos* pos, s16 x, s16 y, u8 w, u8 h);
void FldPosPlaceOnFreeFloor(FldPos* pos);
s32 MapClampCameraX(s32 x);
s32 MapClampCameraY(s32 y);
void MapSnapCamera();
void InitFieldState();
void SpawnMapPlayer();
u8 IsHitByMapAttack(FldPos* pos, s16 radius, s16 height);
u8 GetCurrentRoomCardValue();
s32 IsMapInterrupted();
s32 IsFldObjTalkTarget(FldObj* obj);
void CreateMapRndTask();
void UpdateMapField();
void DrawMapField();
void MenuMsgWaitMessage(MenuMsgWork* work);
void MenuMsgWaitFade(MenuMsgWork* work);
void Mode_MenuMsg_0(s32 arg);
void StartFieldTransition();
void DestroyMapField();
void MapCellSetType(MapCell* cell, s32 type, s32 upperZ);
u8 FldPosHeightExceeds(FldPos* pos, u16 limit);
u8 GetRandomPieceVariant(u8 piece);
void MapCellSetBg2Piece(MapCell* cell, u8 piece, u8 variant);
void MapCellSetFloorBg3Piece(MapCell* cell);
void MapCellSetBg2EdgePiece(MapCell* cell, s32 piece);
void MapCellSetBg2PieceVariant(MapCell* cell, s32 piece, u8 variant);
void MapSetCornerCellPieces(s16 x, s16 y, s32 bg3Piece, s32 bg2Piece);
s16 MapOutlineNextRowRightToLeft(u8 prevType, u8 type, s16 y);
u8 MapCellHasType(s16 x, s16 y, u8 type);
s16 MapOutlineNextRowLeftToRight(u8 prevType, u8 type, s16 y);
void MapCellSetBg1Piece(s16 x, s16 y, u8 piece);
u8 MapCellIsUnbounded(s16 x, s16 y);
void MapAssignWallTopPieces(s16 x, s16 y);
void MapAssignLedgePieces(s16 x, s16 y);
void MapAssignLeftBorderPiece(s16 y);
void MapAssignRightBorderPiece(s16 y);
void MapAssignBg1Pieces();
u8 MapPlaceFirstPlatformDoor(u8 side);
s32 MapPlaceLastPlatformDoor();
void MapPlaceRightPlatformDoor(u8 side);
void MapPlaceLeftPlatformDoor(u8 side);
s32 PickRandomTopEdgeType(s16 left, s16 right, s16 x);
s32 PickRandomBottomEdgeType(s16 left, s16 right, s16 x);
s32 GetMatchingBottomEdgeType(s16 x, s16 y);
s32 PickEdgeTypeByHalf(s16 left, s16 right, s16 x, u8 top);
s32 PickEdgeTypeByThird(s16 left, s16 right, s16 x, u8 top);
s32 GetTopEdgeTypeBelowLedge(u8 index, s16 x, s16 y);
u8 MapFindSpanBelowPlatforms(s16* left, s16* right, s16* row, s16* z);
void MapSetPlatform(u8 index, u16 left, u16 right, s16 z);
void MapTracePlatformLeftToRight(u8 index, s16 left, s16 right, s16 startY, u8 edgeMode);
void MapTracePlatformOutward(u8 index, s16 left, s16 right, s16 startX, s16 startY, u8 edgeMode);
void MapTracePlatformRightToLeft(u8 index, s16 left, s16 right, s16 startY, u8 edgeMode);
void MapGenerateLayout1();
void MapDrawBgColumn(void* buf, s16 x, s16 y);
void MapDrawBgRow(void* buf, s16 x, s16 y);
MapPlatform* GetMapPlatform(u8 index);
void* GetMapBgBuffer();
u16 GetRandomMapWidth();
void MapGenerateRoom(u16 cols, u16 rows);
void MapEnmPlaceInView(MapEnmArgs* arg);
void MapEnmPlaceInViewAbove(MapEnmArgs* arg);
s32 MapEnmPlaceInRoom(MapEnmArgs* arg);
void MapEnmApplyRoomFlags(MapEnmWork* work);
void MapEnmSetAnim(MapEnmWork* work, u8 index, u16 flags);
void MapEnmUpdateAnim(MapEnmWork* work);
u8 GetRandomBattleId();
void MapEnmCheckContact(MapEnmWork* work);
s32 MapEnmCheckAttacked(MapEnmWork* work);
void MapEnmSaveToCache(MapEnmWork* work);
void MapEnmRestoreFromCache();
void MapEnmSpawnRoomSet();
void MapEnmInitRoom();
void MapEnmUpdateSpawner();
MapCell* MapCellAtPos(s32 x, s32 y);
u8 MapCellIsFreeOfType(s16 x, s16 y, u8 type);
s32 MapAreaIsFreeOfType(s16 x, s16 y, u8 w, u8 h, u8 type);
s32 MapCellHeightExceeds(s16 x, s16 y, u8 limit);
s32 MapWallFaceIsUnreserved(s16 x, s16 y, u16 width);
void MapEnmDestroy(MapEnmWork* work);
s32 MapGmkIsAreaSparse(s16 x, s16 y);
void MapReserveArea(s16 x, s16 y, u8 w, u8 h);
s16 MapRowsToWallBase(s16 x, s16 y);
void MapAnmSetupSlot(MapAnmSlot* slot, const MapAnmEntry* entry);
void MapAnmStepScript(MapAnmSlot* slot);
void MapAnmFlushSlot(MapAnmSlot* slot);
void MapAnmUpdateSlot(MapAnmSlot* slot);
s32 Task_MapAnm_1(MapAnmWork* work);
void MapAnmResetSlot(MapAnmSlot* slot);
u8 MapAnmCmdFrame(MapAnmSlot* slot);
void MapFixFreeCells();
void NewGameSlotMenuSelectSlot(u8 slot);
u8 GetRandomMapGmkIndex(u8 slot);
u8 MapGmkFindSpot(FldPos* pos, u8 spotFinder);
s32 MapGmkIsPaletteUnused(void* palette);
s32 MapGmkNeedsTiles(u8 ownTiles, const void* tiles);
void MapGmkReserveJump();
void MapGmkPlaceGmk01();
void MapGmkPlaceGmk04();
void MapGmkPlaceMoogle();
void MapGmkPlaceWorldGimmicks();
void MapGmkPlaceRandomGimmicks();
void MapGmkInitRoom();
void MapGmkCreateTasks();
void DropMapGmkPrize(FldPos* pos);
void MapGmkFree();
void MapApplyLayer1DecorRules(MapDecorRule* rules);
u8 MapDecorCheckFits(s16 x, s16 y, const u8* pattern);
void MapApplyLayer2DecorRules(MapDecorRule* rules);
void MapApplyRoomDecor();
u8 IsEventDoor(u8 room, u8 side);
u8 RollCardValue();
s32 CreateMapPrzCardTask(const PrizeEntry* prize, u8 worldPrize, s32 x, s32 y, s32 z);
u8 TryCreateRandomPrzCard(u8 worldPrize, s32 x, s32 y, s32 z);
void MapDbgSetUpdate(ModeFunc update);
void MapDbgSetUpdateAndRun(ModeFunc update);
void CreateMapPrizeTasks(u8 id, u8 count, s32 x, s32 y, s32 z);
void MapDbgFreeCameraInput();
void MapDbgMain();
void MapDbgExitRoom();
void MapDbgFreeCameraMode();
void MapDbgWaitEdit();
void MapDbgWaitMenu();
void MapDbgWaitRoomCreate();
void Mode_MapDbg_0();
void Mode_MapDbg_1();
void Mode_MapDbg_2();
void MapFldCreateWorldLogo();
void MapFldDestroyAllmapRoom();
void StartWorldBossBattle();
void MapFldShowWorldLogo();
void MapFldMain();
void MapFldExitRoom();
void MapFldOpenAllmap();
void MapFldWaitMenu();
void MapFldWaitRoomCreate();
void MapFldRestart();
void Mode_MapFld_0();
void Mode_MapFld_1();
void Mode_MapFld_2();
MapFixedDef* GetMapFixedDef();
void MapFixCreateCharaTasks();
u8 GetWorldEntryEventId();
u8 GetFloorEventId();
void MapFixMain();
void MapFixEnterMapFld();
void MapFixLeaveEntranceHall();
void MapFixLeaveExitHall();
void MapFixWaitMenu();
void MapFixWaitWalkOut();
void MapFixWaitRoomCreate();
void Mode_MapFix_0();
void MapFixWaitWorldEvent();
void Mode_MapFix_1();
void Mode_MapFix_2();
void MapFldStartBattle();
void MapFldSetUpdate(ModeFunc update);
void MapFldSetUpdateAndRun(ModeFunc update);
void MapFixSetUpdate(ModeFunc update);
void MapFixSetUpdateAndRun(ModeFunc update);
s32 NewGameSlotMenuShowSummary(u8 slot);
void LoadGameMenuLoadFloorTiles(u8 slot, u8 selected, u8 floor);
void LoadGameMenuLoadLevelTiles(u8 slot, u16 level);
void LoadGameMenuLoadTimeTiles(u8 slot, u32 playTime);
void MapMenuWriteDigits3(ObjTiles* tiles, u8 offset, u16 value);
void MapMenuWriteDigits5(ObjTiles* tiles, u8 offset, u32 value);
s32 Task_MapFix_1(MapFixWork* work);
void MapDoorShowOpen(MapDoorWork* work);
u8 MapDoorIdle(MapDoorWork* work);
void MapMenuSetPanelPalettesExcluded(MapMenuWork* work, u8 excluded);
void MapMenuSetCharaPalettesExcluded(MapMenuWork* work, u8 excluded);
void MapSaveSetPanelPalettesExcluded(MapSaveWork* work, u8 excluded);
void MapSaveSetCharaPalettesExcluded(MapSaveWork* work, u8 excluded);
void MapSaveLoadFloorTiles(u8 floor);

void MapFindLowestEdgeLeftward(s32 type, s16* px, s16* py, s16* pz, s16 lo, s16 hi);
void MapEnmDraw(MapEnmWork* work);
void LoadGameMenuSelectSlot(u8 slot);
void MapSaveShowSummary(MapSaveWork* work, u8 slot);
void MapUpdateCamera(s32 targetX, s32 targetY);
void NewGameSlotMenuDraw();
void LoadGameMenuDraw();
void NewGameSlotMenuMoveCursor(NewGameSlotMenuWork* work);
void Mode_MenuNew_1();
void Mode_MenuLoad_1();
s32 Task_MapRnd_1(MapRndWork* work);
void MapDoorShowClosed(MapDoorWork* work);
void MapSaveLoadLevelTiles(u16 level);
void MapSaveLoadTimeTiles(u32 playTime);
void MapBuildStairs(u16 x, u16 y);
void MapMarkJumpSpot(MapPlatform* platform);
void MapFindPlatformStairs(MapPlatform* platform);
void MapPlacePlatformStairs();

#endif /* GUARD_MAP_H */
