#ifndef GUARD_MODE_SIO_H
#define GUARD_MODE_SIO_H

#include "types.h"
#include "text_types.h"
#include "anim.h"
#include "mode.h"
#include "taskpool.h"
#include "obj.h"

typedef struct SioBattleWork {
    s8 cursor;
    u8 state;
    u16 slideTimer;
    u16 stateFrames;
    s32 x;
    s32 topBarY;
    s32 bottomBarY;
    void* tiles;
    void* palette;
    void* gfx2[3];
    void* tiles2;
    void* palette2;
    void* gfx3;
    void* tiles3;
    void* palette3;
    void* gfx4;
    void* tiles4;
    void* palette4;
    void* gfx;
    AnimState anim;
    s32 cursorY;
    u16 modeArg;
} SioBattleWork;

typedef struct SioWorldEntry {
    void* tiles;
    u16 tilesSize;
    void* map;
    u16 mapSize;
    void* palette;
    u16 paletteSize;
    const void* text;
    u8 world;
    u16 textX;
} SioWorldEntry;

typedef struct SioChgCardPos {
    s16 x;
    s16 y;
    s8 owner;
    s8 up;
    s8 down;
    s8 left;
    s8 right;
    u8 unk_09[3];
} SioChgCardPos;

typedef struct SioAnimDef {
    void* gfxTable;
    void* anims;
    void* tiles;
    u8 animId;
} SioAnimDef;

#ifdef VERSION_JP
#define SIO_ERROR_TEXT_SLOTS 98
#else
#ifdef VERSION_EU
#define SIO_ERROR_TEXT_SLOTS 216
#else
#define SIO_ERROR_TEXT_SLOTS 108
#endif
#endif

#ifdef VERSION_EU
#define SIO_CONNECT_TEXT_SLOTS 180
#else
#define SIO_CONNECT_TEXT_SLOTS 0x5A
#endif

typedef struct SioBtlConnectWork {
    u16 unk_00;
    s16 timer;
    s8 state;
    u8 textSlotCount;
    TextSlot textSlots[SIO_CONNECT_TEXT_SLOTS];
    void* palette;
} SioBtlConnectWork;

typedef struct SioErrorWork {
    u8 unk_00;
    u16 unk_02;
    u16 unk_04;
    u8 textSlotCount;
    TextSlot textSlots[SIO_ERROR_TEXT_SLOTS];
    void* palette;
} SioErrorWork;

typedef struct SioCardTaskArg {
    s32* x;
    s32* y;
    s32* scaleX;
    s32* scaleY;
    u8* angle;
    s8* visible;
    s32 targetX;
    s32 targetY;
    u16 delay;
} SioCardTaskArg;

typedef struct SioChgCardWork {
    u8 unk_000;
    s8 state;
    s16 blinkPhase;
    s16 timer;
    void* playerTilesPalettes[4];
    void* gfx[2];
    AnimState anim[2];
    void* tiles;
    ObjPalette* palette;
    void* gfx2;
    AnimState anim2;
    s8 cursorVisible;
    s16 cursor;
    s16 nextCursor;
    s16 x;
    s16 y;
    void* tiles2;
    void* palette2;
    void* gfx3;
    AnimState anim3;
    s8 ready;
    s8 cardVisible[10];
    s32 cardX[10];
    s32 cardY[10];
    void* tiles3[10];
    void* palette3[10];
    void* gfx4[10];
    void* tiles4;
    void* palette4;
    void* gfx5[10];
    s32 scaleX[10];
    s32 scaleY[10];
    u8 angle[10];
    u16 offeredCard;
    void* tiles5;
    void* gfx6;
    s8 messageVisible;
    u8 textSlotCount;
    TextSlot textSlots[42];
    s8 cardInfoVisible;
    u8 textSlotCount2;
    TextSlot textSlots2[20];
    s16 receiveOk;
    u16 collectionBackup[0x3E7];
    u64 obtainedCardKindsBackup;
    s16 messageX;
    s16 messageY;
    s8 leaveDelay;
    TaskPool tasks;
} SioChgCardWork;

typedef struct SioBtlCardgetWork {
    s8 state;
    u16 unk_02;
    s16 timer;
    s8 lost;
    void* tiles;
    void* tiles2;
    void* palette;
    void* palette2;
    void* gfx;
    void* gfx2;
    s32 unk_20;
    s32 unk_24;
    void* tiles3;
    void* tiles4;
    void* palette3;
    void* palette4;
    void* gfx3;
    void* gfx4;
    u8 unk_40[4];
} SioBtlCardgetWork;

typedef struct SioBtlOptionWork {
    s8 cursor;
    u8 returnState;
    s8 state;
    s16 fadeLevel;
    s16 timer;
    void* playerTilesPalettes[4];
    void* gfx6[2];
    AnimState anim2[2];
    u8 textSlotCount;
    TextSlot textSlots[20];
#ifdef VERSION_EU
    TextSlot unkEu_0F4[20];
#endif
    void* palette7;
    u8 textSlotCount2;
    TextSlot textSlots2[10];
#ifdef VERSION_EU
    TextSlot unkEu_1EC[10];
#endif
    void* palette8;
    u8 textSlotCount3;
    TextSlot textSlots3[10];
#ifdef VERSION_EU
    TextSlot unkEu_294[10];
#endif
    void* palette9;
    void* tiles;
    void* palette;
    void* gfx;
    s8 menuOpen;
    void* tiles2;
    void* palette2;
    void* gfx2;
    AnimState anim;
    s32 cursorY;
    s8 cursorVisible;
    void* tiles4;
    void* palette4;
    void* gfx4;
    void* gfx7;
    void* gfx8;
    s8 handicapMarkerVisible;
    u16 frameCount;
    void* tiles5[2];
    void* gfx5[2];
    ObjPalette* palette5[2];
    s8 handicaps[2];
    s8 handicap;
    s8 player1Ready;
    s8 player2Ready;
    u16 modeArg;
    void* tiles3;
    void* palette3;
    void* gfx3;
    s8 messageVisible;
    u8 textSlotCount4;
    TextSlot textSlots4[60];
#ifdef VERSION_EU
    TextSlot unkEu_54C[60];
#endif
    void* palette6;
    s8 worldChangeState;
    s16 messageX;
    s16 messageY;
    s8 leaveDelay;
    s8 worldEntry;
    u16 unk_418;
} SioBtlOptionWork;

extern u8 gSioErrorText[];
extern u8 gSioBtlConnectText[];
extern u8 gSioChgConnectText[];
extern u8 gSioBtlWaitingText[];
extern u8 gSioChgSwapConfirmText[];
extern u8 gSioChgSwappingText[];
extern u8 gSioChgSwapCompleteText[];
extern u8 gSioChgSaveCompleteText[];
extern u8 gSioBtlReadyText[];
extern u8 gSioBtlSendingDeckText[];
extern u8 gSioChgWaitingText[];
extern Mode gModeDeckExchange;

void mode_sio_btl_connect_0(s32 arg);
void mode_sio_btl_connect_1();
void mode_sio_btl_connect_2();
void SioBtlConnectOnConnect();
void SioBtlConnectOnCancel();
void SioInitWorldList();
void SetSioBtlOptionAnimation(u16 player, u16 index, u16 flags);

enum SioBtlOptionEntry {
    SIO_BTL_OPTION_ENTRY_NEW,
    SIO_BTL_OPTION_ENTRY_FROM_DECK_MENU
};

void mode_sio_btl_option_0(s32 arg);
void SioBtlOptionLoadBg();
void SioBtlOptionInitObjs();
void SioBtlOptionLoadWorld();
void SioBtlOptionFadeIn();
void SioBtlOptionWaitStart();
void SioBtlOptionHandleIdle();
void SioBtlOptionHandleMenu();
void SioBtlOptionSetHandicap();
void SioBtlOptionChangeWorld();
void SioBtlOptionWaitReady();
void SioBtlOptionConfirm();
void SioBtlOptionStartDeckExchange();
void SioBtlOptionWaitDeckExchange();
void SioBtlOptionResumeCommands();
void SioBtlOptionWaitBeforeSync();
void SioBtlOptionSyncStart();
void SioBtlOptionStartBattle();
void SioBtlOptionDraw();
void SioBtlOptionCheckReady();
void SioBtlOptionRecvWorld();
void SioBtlOptionRecvSettings();
void SioBtlOptionSyncDeckNames();
void SioBtlOptionDrawStats();
void SioApplyBattleSettings();
void SioBtlOptionSyncHandicaps();
void SioBtlOptionUpdateHandicapGauges(u16 handicap1, u16 handicap2);
void SioBtlOptionCancelReady();
void mode_sio_btl_cardget_0(s32 arg);
void SioBtlCardgetLoadBgTiles();
void SioBtlCardgetLoadBg();
void SioBtlCardgetShowResult();
void mode_sio_btl_cardget_1();
void mode_sio_chg_connect_0(s32 arg);
void mode_sio_chg_connect_1();
void mode_sio_chg_connect_2();
void SioChgConnectOnConnect();
void SioChgConnectOnCancel();
void SioChgConnectStartTrade();
void mode_sio_chg_card_0(s32 arg);
void SioChgCardLoadBg();
void SioChgCardInitObjs();
void mode_sio_chg_card_1();
void SioChgCardWaitStart();
void SioChgCardSelect();
void SioChgCardConfirm();
void SioChgCardTryTrade();
void SioChgCardWaitTradeResult();
void SioChgCardTradeFailed();
void SioChgCardStartMove();
void SioChgCardSave();
void SioChgCardWaitMove();
void SioChgCardShowSecondMessage();
void SioChgCardHideMessage();
void SioChgCardRestart();
void SioChgCardDraw();
void SioChgCardRecvSlots();
void SioChgCardSetSlot(u16 command);
void SioChgCardSetSlotId(u16 command);
void SioChgCardReturnCard();
s8 SioChgCardHasOwnCards();
s8 SioChgCardSlotsEmpty();
void SioChgCardShowInfo();
void SioChgCardHideInfo();
void SioChgCardDrawPointTotals();
void SioChgCardHandleInput();
void SioChgCardCancelReady();
void SioChgCardCreateMoveTasks();
void SioChgCardBackupCollection();
void SioChgCardRestoreCollection();
s16 SioChgCardReceiveCards();
void SioChgCardReturnOwnCards();
void func_080B3DF8();
void mode_sioError_0(s32 arg);
void mode_sioError_1();
void SioErrorDraw();
void mode_sioError_2();
void SetSioChgCardAnimation(u16 player, u16 index, u16 flags);
void SioBtlCardgetDraw();
void SioBtlCardgetLoad1PWin();
void SioBtlCardgetLoad2PWin();
void SioBtlOptionPlayWorldBgm();

#endif /* GUARD_MODE_SIO_H */
