#ifndef GUARD_SIO_TYPES_H
#define GUARD_SIO_TYPES_H

#include "types.h"
#include "macros.h"

typedef struct SioWork {
    u8 isParent;
    u8 state;
    u8 playerId;
    u8 playerCount;
    u16 recv[4];
    u8 recvEmpty;
    u8 transferCount;
    u8 paused;
    u8 unk_0F;
    u8 startPending;
    u8 handshake;
    u8 hardwareError;
    u8 checksumError;
    u8 queueFull;
    u8 timeout;
    u16 checksum;
    u8 sendWordIdx;
    u8 recvWordIdx;
    u8 unk_1A;
    u16 sendBuf[4][32];
    u8 sendReadIdx;
    u8 sendCount;
    u8 unk_11E;
    u16 recvBuf[2][4][32];
    u8 recvReadIdx;
    u8 recvCount;
    u8 unk_322[0x02];
} SioWork;

STATIC_ASSERT(sizeof(SioWork) == 0x324, SioWorkSize);

#endif
