#ifndef GUARD_ALLMAP_H
#define GUARD_ALLMAP_H

#include "obj.h"
#include "allmap_types.h"
#include "types.h"
#include "text_types.h"
#include "taskpool.h"
#include "anim.h"
#include "card_ui_types.h"

#ifdef VERSION_EU
#define ALLMAP_ROOMNAME_TEXT_SLOTS 36
#else
#define ALLMAP_ROOMNAME_TEXT_SLOTS 24
#endif

typedef struct AllmapRoomnameWork {
    TextSlot textSlots[ALLMAP_ROOMNAME_TEXT_SLOTS + 1];
    void* palette;
    u8 textSlotCount;
    u16 x;
} AllmapRoomnameWork;

typedef struct AllmapRoomArg {
    u32 x : 16;
    u32 y : 16;
    u32 room : 8;
    u32 unk_05 : 8;
    u32 asSprite : 16;
} AllmapRoomArg;

typedef struct AllmapBarWork {
    void* tiles;
    void* tiles2;
    void* palette;
    u16 steps;
    s32 y;
    s32 targetY;
    s32 y2;
    s32 targetY2;
    s32 x;
    s32 targetX;
    u32 state;
    u8 closing;
    u8 fadeStarted;
    u8 unk_2E[0x802];
} AllmapBarWork;

typedef struct AllmapCursorPos {
    u16 x;
    u16 y;
} AllmapCursorPos;

typedef struct AllmapCursorWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s16 screenX;
    s16 screenY;
    s32 dropY;
    s32 dropTargetY;
    AllmapCursorPos pos;
    s32 x;
    s32 y;
    s32 drawX;
    s32 drawY;
    u16 moveSteps;
} AllmapCursorWork;

typedef struct AllmapState {
    TaskPool tasks;
    Task* roomTasks[32];
    Task* cursorTask;
    Task* roomnameTask;
    Task* pushaTask;
    s16 scrollX;
    s16 scrollY;
    s32 introScrollY;
    s32 introTargetY;
    s16 originX;
    s16 originY;
    s16 width;
    s16 height;
    u16 minX;
    u16 maxX;
    u16 minY;
    u16 maxY;
    s32 moveSpeed;
    u8 lastRoom;
} AllmapState;

typedef struct AllmapDoorinfoWork {
    AllmapCursorPos pos;
    u8 room;
    void* gfx2[4];
    void* tiles;
    EventKeyCard doors[4];
    ObjPalette* palette;
    void* tiles2;
    ObjPalette* palette2;
    void* gfx;
    s16 roomX;
    s16 roomY;
    u16 steps;
    s32 x;
    s32 y;
    s32 targetX;
    s32 targetY;
    u16 count;
    u8 closing;
} AllmapDoorinfoWork;

typedef struct AllmapPushaWork {
    void* tiles;
    void* palette;
    void* gfx;
    AllmapCursorWork* cursor;
    u16 angle;
    s16 y2;
    TaskPool tasks;
    Task* task;
    s16 x;
    s16 y;
} AllmapPushaWork;

s32 GetAllmapRoomPaletteOffset(u8 room);
void InitAllmap();
void AllmapUpdateCamera(AllmapState* state);
void UpdateAllmap();
void DestroyAllmap();
void AllmapHandleInput();
void AllmapInitDropOffsets();
void AllmapSetBounds(u16 minX, u16 maxX, u16 minY, u16 maxY);
u8 AllmapDoorHasCardInfo(u8 room, u8 side);
u8 AllmapDoorHasKeyInfo(u8 room, u8 side);
s16 AllmapDrawRoomnameFrame(u16 width);
s32 GetAllmapRoomnamePaletteOffset(u8 nameId);
void AllmapClearRoomnameFrame();
void AllmapBarStartClose(AllmapBarWork* work);
void AllmapBarFadeOut(AllmapBarWork* work);
u8 AllmapHasDoorInfo(AllmapCursorPos pos);
void AllmapDoorinfoLoadDoors(AllmapDoorinfoWork* work);
void AllmapDoorinfoLoadKeys(AllmapDoorinfoWork* work);
void AllmapDoorinfoDrawDoors(AllmapDoorinfoWork* work);
void AllmapDoorinfoDrawKeys(AllmapDoorinfoWork* work);
u8 IsStockMesDispActive();
s32 GetAllmapRoomAt(AllmapCursorPos pos);
void AllmapAddRoom(u8 id, u16 x, u16 y);

extern u8 gAllmapCursorRoom;
extern s16 gAllmapCameraY;
extern s16 gAllmapCameraX;

void task_allmap_room_0(AllmapRoomWork* work, AllmapRoomArg* arg);
s32 task_allmap_room_1();
void task_allmap_room_2(AllmapRoomWork* work);
void task_allmap_room_3(AllmapRoomWork* work);
void task_allmap_cursor_0(AllmapCursorWork* work, AllmapCursorPos* arg);
s32 task_allmap_cursor_1(AllmapCursorWork* work);
void task_allmap_cursor_2(AllmapCursorWork* work);
void task_allmap_cursor_3(AllmapCursorWork* work);
void task_allmap_roomname_0(AllmapRoomnameWork* work, u8* nameId);
s32 task_allmap_roomname_1();
void task_allmap_roomname_2(AllmapRoomnameWork* work);
void task_allmap_roomname_3(AllmapRoomnameWork* work);
void task_allmap_bar_0(AllmapBarWork* work);
s32 task_allmap_bar_1(AllmapBarWork* work);
void task_allmap_bar_2(AllmapBarWork* work);
void task_allmap_bar_3(AllmapBarWork* work);

#endif /* GUARD_ALLMAP_H */
