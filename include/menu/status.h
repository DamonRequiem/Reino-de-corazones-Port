#ifndef GUARD_STATUS_H
#define GUARD_STATUS_H

#include "anim.h"
#include "types.h"
#include "text_types.h"
#include "taskpool.h"

typedef struct StatusEntry {
    s32 items[72];
    u16 count;
} StatusEntry;

typedef struct StatusBarWork {
    void* tiles;
    void* palette;
    u16 steps;
    s32 y;
    s32 targetY;
    s32 y2;
    s32 targetY2;
    s32 x;
    s32 targetX;
    u8 closing;
    u8 fadeStarted;
    u8 unk_26[0x6];
} StatusBarWork;

typedef struct StatusTabWork {
    void* tiles;
    void* tiles2;
    void* palette;
    void* palette2;
    void* gfx;
    void* gfx2;
    s32* tab;
} StatusTabWork;

typedef struct StatusSoraWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
} StatusSoraWork;

typedef struct StatusDecknameWork {
    TextSlot textSlots[10];
    void* palette;
    u8 textSlotCount;
    u8* mesWindowOpen;
} StatusDecknameWork;

typedef struct StatusCursorWork {
    void* tiles;
    void* tiles2;
    void* palette;
    void* palette2;
    void* gfx[2];
    AnimState anim[2];
    s16* cursor;
    s16 lastCursor;
    u16 moveSteps;
    s32 y;
    s32 targetY;
    s32 x;
    s32 targetX;
} StatusCursorWork;

typedef struct StatusScrollcursorWork {
    void* tiles;
    void* palette;
    void* gfx;
    u16* scroll;
    u16 unk_10;
    s16 y;
} StatusScrollcursorWork;

typedef struct StatusMeswindowWork {
    TaskPool pool;
    void* task;
    s32 item;
    u8* open;
    u8 textIndex;
} StatusMeswindowWork;

typedef struct StatusMessageParam {
    void* text;
    s16 x;
    s16 y;
} StatusMessageParam;

typedef struct StatusMessageWork {
    TextSlot textSlots[100];
    u8 textSlotCount;
    void* palette;
    StatusMessageParam param;
} StatusMessageWork;

typedef struct StatusFriendWork {
    void* tiles[3];
    void* palette[3];
    void* gfx[3];
    u16 count;
} StatusFriendWork;

typedef struct StatusMesParam {
    u32 x : 16;
    u32 y : 16;
    u32 textIndex : 8;
    u32 unk_04_08 : 8;
    u32 helpIndex : 16;
} StatusMesParam;

typedef struct StatusFriendEntry {
    u16 flag;
    u16 cardId;
} StatusFriendEntry;

typedef struct StatusFriendTable {
    StatusFriendEntry entries[8];
} StatusFriendTable;

typedef struct StockMesDispWork {
    void* tiles;
    void* palette;
    void* tiles2;
    void* tiles3;
    void* palette2;
    void* palette3;
    void* gfx;
    void* gfx2;
    u16 frame;
    TaskPool tasks;
    void* task;
    u16 x;
    u16 y;
    u8 textIndex;
    u16 helpIndex;
    u8 textCount;
} StockMesDispWork;

typedef struct StatusWork {
    TaskPool pool;
    u32 tab;
    u16 unk_18;
    s16 cursor;
    s16 scroll;
} StatusWork;

typedef struct StatusStocklistWork {
    StatusEntry entries[4];
    void* tiles2[8];
    void* palette;
    void* tiles;
    void* palette2;
    void* gfx;
    s32* tab;
    u16 scroll;
    u16 timer;
    u8 blink;
} StatusStocklistWork;

extern s32 gStatusBarState;

u8 IsStatusBarIdle();
void StatusHandleInput(StatusWork* work);
s16 GetStatusScroll();
u16 GetStatusVisibleRowCount();
u16 GetStatusMaxScroll();
u8 StatusTabHasItems();
void StatusStocklistLoadRows(u16 scroll);
s32 GetStatusListItem(s16 index);
void StatusEntryClear(StatusEntry* entry);
void StatusEntryAppend(StatusEntry* entry, s32 item);
s32 GetStatusItemTab(u32 item);
void* LoadStockNameTiles(u16 stock);
s32 GetStatusItemStockIndex(s32 item);
s16 GetStatusScrollcursorY(StatusScrollcursorWork* work);
void StatusStocklistScrollDown();
void* CreateStockMesDispTask(void* pool, u16 helpIndex, u8 textIndex, u16 x, s32 y);
u8 GetStockMesDispTextIndex(void* task);

void StatusBarStartClose(StatusBarWork* work);
u8 IsStatusMesWindowOpen();
void StatusStocklistScrollUp();

void task_status_0(StatusWork* work);
u8 task_status_1(StatusWork* work);
void task_status_2(StatusWork* work);
void task_status_3(StatusWork* work);
void task_status_bar_0(StatusBarWork* work);
u8 task_status_bar_1(StatusBarWork* work);
void task_status_bar_2(StatusBarWork* work);
void task_status_bar_3(StatusBarWork* work);
void task_status_tab_0(StatusTabWork* work, s32* tab);
u8 task_status_tab_1(StatusTabWork* work);
void task_status_tab_2(StatusTabWork* work);
void task_status_tab_3(StatusTabWork* work);
void task_status_sora_0(StatusSoraWork* work);
u8 task_status_sora_1(StatusSoraWork* work);
void task_status_sora_2(StatusSoraWork* work);
void task_status_sora_3(StatusSoraWork* work);
void task_status_deckname_0(StatusDecknameWork* work, u8* mesWindowOpen);
u8 task_status_deckname_1(StatusDecknameWork* work);
void task_status_deckname_2(StatusDecknameWork* work);
void task_status_deckname_3(StatusDecknameWork* work);
void task_status_cursor_0(StatusCursorWork* work, s16* cursor);
u8 task_status_cursor_1(StatusCursorWork* work);
void task_status_cursor_2(StatusCursorWork* work);
void task_status_cursor_3(StatusCursorWork* work);
void task_status_stocklist_0(StatusStocklistWork* work, s32* tab);
u8 task_status_stocklist_1(StatusStocklistWork* work);
void task_status_stocklist_2(StatusStocklistWork* work);
void task_status_stocklist_3(StatusStocklistWork* work);
void task_status_scrollcursor_0(StatusScrollcursorWork* work, u16* scroll);
u8 task_status_scrollcursor_1(StatusScrollcursorWork* work);
void task_status_scrollcursor_2(StatusScrollcursorWork* work);
void task_status_scrollcursor_3(StatusScrollcursorWork* work);
void task_status_meswindow_0(StatusMeswindowWork* work, u8* open);
u8 task_status_meswindow_1(StatusMeswindowWork* work);
void task_status_meswindow_2(StatusMeswindowWork* work);
void task_status_meswindow_3(StatusMeswindowWork* work);
void task_status_message_0(StatusMessageWork* work, StatusMessageParam* arg);
u8 task_status_message_1(StatusMessageWork* work);
void task_status_message_2(StatusMessageWork* work);
void task_status_message_3(StatusMessageWork* work);
void task_status_friend_0(StatusFriendWork* work);
u8 task_status_friend_1(StatusFriendWork* work);
void task_status_friend_2(StatusFriendWork* work);
void task_status_friend_3(StatusFriendWork* work);

#endif /* GUARD_STATUS_H */
