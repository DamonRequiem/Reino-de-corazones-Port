#ifndef GUARD_MODE_SIO_DBG_H
#define GUARD_MODE_SIO_DBG_H

#include "types.h"

void mode_sio_dbg_flg_0(s32 arg);
void mode_sio_dbg_flg_1();
void mode_sio_dbg_flg_2();
void SioDbgApplySettings();

#ifdef VERSION_EU
extern u16 gUnk_0203C3C4;
#else
extern s8 gUnk_0203C3C4;
#endif
extern u16 gUnk_0203C3C8;
extern u16 gUnk_0203C3CC;
extern u16 gSioDbgCp;
#ifdef VERSION_EU
extern u16 gUnk_0203C3D4;
extern u16 gSioDbgLevel1P;
extern u16 gSioDbgLoseCount1P;
extern u16 gSioDbgWinCount2P;
extern u16 gSioDbgHp2P;
extern u16 gSioDbgLevel2P;
#else
extern s8 gUnk_0203C3D4;
#endif

#endif
