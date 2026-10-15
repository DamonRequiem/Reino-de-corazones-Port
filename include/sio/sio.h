#ifndef GUARD_SIO_H
#define GUARD_SIO_H

#include "types.h"

u16 IsVBlankIntrLive();
void SioInit();
void func_08006E70();
void SioStop();
void SioCheckParent();
void SioInitTimer();
void SioQueueSendFrame(u16* frame);
void SioReadRecvFrame(u16 (*frame)[2]);
void SioVBlankUpdate();
void SioTimer3Intr();
void SioSerialIntr();
void SioStartTransfer();
u8 SioHandshake();
void SioRecvWord();
void SioSendWord();
void SioStopTimer();
void SioFinishTransfer();
void SioResetSendQueue();
void SioResetRecvQueue();
void SioClearRegs();

#endif /* GUARD_SIO_H */
