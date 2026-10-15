#ifndef GUARD_SIO_API_H
#define GUARD_SIO_API_H

#include "types.h"
#include "sio_types.h"

#define SIO_STAT_LOCAL_ID 0x3
#define SIO_STAT_PLAYER_COUNT 0x1C
#define SIO_STAT_PLAYER_COUNT_SHIFT 2
#define SIO_STAT_PARENT 0x20
#define SIO_STAT_CONNECTED 0x40
#define SIO_STAT_RECV_EMPTY 0x100
#define SIO_STAT_RECV_EMPTY_SHIFT 8
#define SIO_STAT_HANDSHAKE 0xE00
#define SIO_STAT_HANDSHAKE_SHIFT 9
#define SIO_STAT_ERRORS 0x7F0000

#define SIO_STAT_ERROR_HARDWARE 0x10000
#define SIO_STAT_ERROR_HARDWARE_SHIFT 16
#define SIO_STAT_ERROR_CHECKSUM 0x20000
#define SIO_STAT_ERROR_CHECKSUM_SHIFT 17
#define SIO_STAT_ERROR_QUEUE_FULL_SEND 0x40000
#define SIO_STAT_ERROR_QUEUE_FULL_RECV 0x80000
#define SIO_STAT_ERROR_QUEUE_FULL_SHIFT 18
#define SIO_STAT_ERROR_TIMEOUT_PARENT 0x100000
#define SIO_STAT_ERROR_TIMEOUT_CHILD 0x200000
#define SIO_STAT_ERROR_TIMEOUT_SHIFT 20
#define SIO_STAT_ERROR_INVALID_ID 0x400000

enum SioLinkResult {
    SIO_LINK_RESULT_NONE,
    SIO_LINK_RESULT_ERROR,
    SIO_LINK_RESULT_EXCHANGE_DONE
};

enum SioPlayerId {
    SIO_PLAYER_PARENT,
    SIO_PLAYER_CHILD
};

void SioReset();
u32 SioRunStateMachine(u8* request, u16* sendFrame, u16 (*recvFrame)[2]);
u32 SioTransferFrames(u8* request, u16* sendFrame, u16 (*recvFrame)[2]);
void SioShutdown();
u8 SioIsConnected();

extern u8 gSioLastSendCount;
extern s16 gSioErrorFrameCount;
extern u16 gSioRecvFrame[4][2];
extern u32 gSioErrorStatus;
extern s32 (*gSioLinkRecvCallback)();
extern u8 gSioPlayerCount;
extern u8 gSioLastRecvCount;
extern s32 (*gSioLinkSendCallback)();
extern u16 gSioCommandRecv[4][2];
extern u32 gSioStatus;
extern u8 gSioHandshake;
extern u32 gSioPlayerId;
extern u8 gSioHandshakeRequest;
extern SioWork gSioWork;
extern u16 gSioCommandSend[4];
extern u8 gSioLinkResult;
extern u16 gSioSendFrame[4];

#endif
