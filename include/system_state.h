#ifndef GUARD_SYSTEM_STATE_H
#define GUARD_SYSTEM_STATE_H

#include "types.h"
#include "intr.h"

enum DebugFlagBit {
    DEBUG_FLAG_CHKBTL = 0x1,
    DEBUG_FLAG_INVINCIBLE = 0x2,
    DEBUG_FLAG_DISP_DMG = 0x4,
    DEBUG_FLAG_ALL_MAP_CARD = 0x8,
    DEBUG_FLAG_ALL_BTL_CARD = 0x10,
    DEBUG_FLAG_ALL_ABILITY = 0x20,
    DEBUG_FLAG_ENEMY_INVINCIBLE = 0x40,
    DEBUG_FLAG_PREMIUM = 0x80,
    DEBUG_FLAG_LEVEL_MAX = 0x100,
    DEBUG_FLAG_GENTLE_ENEMY = 0x200,
    DEBUG_FLAG_NO_ENCOUNT = 0x400,
    DEBUG_FLAG_RIKU = 0x800,
    DEBUG_FLAG_YAMI_RIKU = 0x1000,
    DEBUG_FLAG_COMP_MEMO = 0x2000,
    DEBUG_FLAG_ENEMY_CARD = 0x4000,
    DEBUG_FLAG_DEBUG_MENU = 0x8000
};

enum SystemFlag {
    SYSTEM_FLAG_LINK_ACTIVE = 0x1,
    SYSTEM_FLAG_DMA3_IMMEDIATE = 0x8,
    SYSTEM_FLAG_DMA3_FLUSH_CPU = 0x10,
    SYSTEM_FLAG_NO_SOFT_RESET = 0x20
};

enum FrameSyncFlag {
    FRAME_SYNC_SOUND_BUSY = 0x1,
    FRAME_SYNC_IN_VBLANK = 0x2,
    FRAME_SYNC_FRAME_READY = 0x4,
    FRAME_SYNC_VBLANK_OVERRUN = 0x8
};

#define SOFT_RESET_MAGIC 0xFEDCBA98

extern vu16 gFrameSyncFlags;
extern u16 gVBlankEndVCount;
extern u32 gUnk_03006C04[3];
extern u32 gDebugFlags;
extern IntrFunc* gIntrTableSerial;
extern u32 gSoftResetMarker[2];
extern IntrFunc gIntrTable[INTR_COUNT];
extern IntrFunc* gIntrTableVCount;
extern IntrFunc* gIntrTableVBlank;
extern IntrFunc* gIntrTableTimer3;
extern IntrFunc gHBlankCallback;
extern vu32 gVBlankCounter;
extern IntrFunc gVCountCallback;
extern IntrFunc gVBlankCallback;
extern IntrFunc* gIntrTableHBlank;
extern vu16 gSystemFlags;
extern u8 gUnk_03006C7A[6];
extern u8 gIntrHandler[0x800];
extern vu32 gFrameCounter;

#ifdef VERSION_EU
enum Language {
    LANGUAGE_ENGLISH,
    LANGUAGE_FRENCH,
    LANGUAGE_GERMAN,
    LANGUAGE_ITALIAN,
    LANGUAGE_SPANISH
};

extern u32 gLanguage;

#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) ((void*)(x))
#endif
extern IntrFunc gVBlankHandlerOverride;

extern u8 IrqHandler[];

#endif
