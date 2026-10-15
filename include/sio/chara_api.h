#ifndef GUARD_CHARA_API_H
#define GUARD_CHARA_API_H

#include "types.h"
#include "card_types.h"

struct CharaObjParam;
struct CharaObjParam2;

#define SIO_CMD_DATA 0xACD

enum SioConnectMode {
    SIO_CONNECT_MODE_BATTLE,
    SIO_CONNECT_MODE_TRADE
};

u8 SioConnectUpdate();
u8 SioLinkUpdate();
void FreeLinkDecks();
void SioLinkClose();
u8 SioHasError();
void SioConnectInit(void (*onConnect)(), void (*onCancel)(), u8 mode);
void SioCommandReset();
s32 SioCommandSend();
s32 SioCommandRecv();
void SioSetLinkCallbacks(s32 (*send)(), s32 (*recv)());
s32 SioKeySyncSend();
s32 SioKeySyncRecv();
void SioPrepareDeckExchange();
s32 SioExchangeSend();
s32 SioExchangeRecv();
void SioPrepareCharaLinkExchange();
void CharaObjInitDefeat2(struct CharaObjParam2* param);
u8 CharaObjUpdateDefeat2();
void CharaObjInitDefeat(struct CharaObjParam* param);
u8 CharaObjUpdateDefeat();
void RequestMapRowsCopy(u8* src, u8* dst, u16 size, s16 count);

extern u32 gDebugLogC[100];
extern u32 gVBlankTimerElapsed;
extern s16 gSioCancelTimer;
extern s16 gSioAutoConnectTimer;
extern void (*gSioCancelCallback)();
extern u32 gVBlankTimerBase;
extern s16 gSioAutoConnectState;
extern u32 gDebugLogSeq;
extern u32 gDebugLogB[100];
extern u32 gDebugLogA[100];
extern u32 gDebugLogD[100];
extern u16 gDebugLogIndex;
extern s8 gLinkDecksAllocated;
extern u16 gSioExchangeSeqEnd;
extern Deck* gSioSendDeck;
extern s8 gSioHandshakeDone;
extern s8 gSioHandshakeConfirm;
extern u16 gSioRelayKeysB;
extern s8 gSioConnectRetries;
extern u16* gSioExchangeSendData;
#ifdef VERSION_EU
extern u16 gRandomPartnerATimer;
#endif
extern u16 gSioExchangeSeq;
extern Deck* gSioRecvDeck;
#ifdef VERSION_EU
extern u16 gRandomPartnerDpadTimer;
#endif
extern u16* gSioExchangeRecvData;
extern s8 gSioConnectAccepted;
#ifdef VERSION_EU
extern u16 gRandomPartnerDpad;
#endif
extern s8 gSioHandshakeAck;
extern s8 gSioConnected;
extern void (*gSioConnectCallback)();
extern u16 gSioConnectId;
extern u16 gSioRelayKeysA;
extern u16 gUnk_0203C3B8;

#ifdef VERSION_EU
void SioExchangeLoopback();
s32 SioRandomPartnerSend();
s32 SioRandomPartnerRecv();
#endif

#endif
