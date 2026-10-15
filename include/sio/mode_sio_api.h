#ifndef GUARD_MODE_SIO_API_H
#define GUARD_MODE_SIO_API_H

#include "types.h"
#include "chara_types.h"

#define SIO_TRADE_CARD_NONE 0x800

enum SioBattleEntry {
    SIO_BATTLE_ENTRY_OPEN,
    SIO_BATTLE_ENTRY_FILE_LOADED,
    SIO_BATTLE_ENTRY_BATTLE_CANCELLED,
    SIO_BATTLE_ENTRY_TRADE_CANCELLED
};

void mode_sio_battle_0(s32 arg);
void mode_sio_battle_1();
void mode_sio_battle_2();
void ClearSioBattleFileLoaded();
void SioChgCardRecvSlotIds();

extern s8 gSioDebugMode;
extern u8 gSioBattleFileLoaded;
extern u16 gSioWinCount;
extern u16 gSioLoseCount;
extern s8 gSioWorldCursor;
extern CharaLinkData gCharaLinkRecv;
extern u8 gSioDeckNames[2][20];
extern u8 gSioHandicaps[2];
extern u8 gSioDeckNameRecv[2][20];
extern u8 gSioWorldCount;
extern s8 gSioDeckNameChunk;
extern s8 gSioPrevWorldCursor;
extern s8 gSioWorldList[14];
extern u8 gSioSavedWorld;
extern CharaLinkData gCharaLinkSend;
extern u8 gSioDeckNameRecvBuf[2][20];
#ifdef VERSION_EU
extern s8 gSioDebugReady[2];
#endif
#ifndef VERSION_EU
extern s8 gSioChgCardCursor;
extern u16 gSioChgCardSlots[10];
extern s8 gSioChgCardReady[2];
#endif

#endif
