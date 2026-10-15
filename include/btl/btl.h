#ifndef GUARD_BTL_H
#define GUARD_BTL_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "obj.h"
#include "battle_actor_types.h"

typedef struct BtlSpawnArgs {
    u32 variant : 16;
    u32 mainSide : 8;
    u32 unk_03 : 8;
} BtlSpawnArgs;

enum SummonLevel {
    SUMMON_LEVEL_SINGLE,
    SUMMON_LEVEL_PAIR,
    SUMMON_LEVEL_TRIPLE,
    SUMMON_LEVEL_SLEIGHT
};

typedef struct BtlTaskArgs {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x6];
    s16 facingLeft;
    u16 mainSide;
    void* unk_18;
    u16 variant;
} BtlTaskArgs;

enum BtlDrawInfoFlag {
    BTL_DRAW_INFO_FLAG_FACING_LEFT = 0x1
};

typedef struct BtlDrawInfo {
    s32 x;
    s32 y;
    s32 z;
    u16 flags;
    AnimState anim;
    const void* tileSrc;
    s32 scale;
} BtlDrawInfo;

typedef struct BtlLockonWork {
    void* tiles;
    void* palette;
    AnimState anim;
    void* gfx;
    s16 timer;
} BtlLockonWork;

typedef struct BtlAreaWork {
    void* palette;
    void* tiles;
    u8 visible;
    u8 enabled;
    s16 timer;
} BtlAreaWork;

enum ComboFlag {
    COMBO_FLAG_AERIAL_SWING = 0x1,
    COMBO_FLAG_ZOOM_ON_HIT = 0x2
};

enum ComboType {
    COMBO_TYPE_NORMAL,
    COMBO_TYPE_TARGET_FAR_X,
    COMBO_TYPE_TARGET_ABOVE,
    COMBO_TYPE_AIRBORNE,
    COMBO_TYPE_TARGET_FAR_Y
};

typedef struct SoraAttackDef {
    s32 animId;
    const s32* attackIds;
    u16 swingSound;
    u16 hitSound;
    s32 vz;
    u16 flags;
    const struct SoraAttackDef* next;
} SoraAttackDef;

typedef struct RikuAttackDef {
    s32 animId;
    s16 hitFrame;
    const s32* attackIds;
    u16 swingSound;
    u16 song;
    s32 vz;
    u16 flags;
    const struct RikuAttackDef* next;
} RikuAttackDef;

enum BtlItem {
    BTL_ITEM_POTION,
    BTL_ITEM_HI_POTION,
    BTL_ITEM_MEGA_POTION,
    BTL_ITEM_ETHER,
    BTL_ITEM_MEGA_ETHER,
    BTL_ITEM_ELIXIR,
    BTL_ITEM_MEGALIXIR
};

enum BtlSoraFlag {
    BTL_SORA_FLAG_SWING_HIT = 0x2,
    BTL_SORA_FLAG_HIDDEN = 0x4,
    BTL_SORA_FLAG_OVER_PLATFORM = 0x10,
    BTL_SORA_FLAG_ON_PLATFORM = 0x20,
    BTL_SORA_FLAG_COMBO_EXTENDED = 0x40,
    BTL_SORA_FLAG_PASS_THROUGH = 0x80,
    BTL_SORA_FLAG_HIT_FLASH = 0x100,
    BTL_SORA_FLAG_AT_SIDE_EDGE = 0x200,
    BTL_SORA_FLAG_HC_STATUS = 0x400
};

typedef struct BtlSoraWork {
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    AnimState anim;
    TaskPool tasks;
    u32 state;
    u32 nextState;
    BtlObj actor;
    s32 vz;
    u16 stateTimer;
    s16 steps;
    u16 timer;
    u16 flags;
    s32 speed;
    u8 angle;
    u8 comboCount;
    u8 variant[0x2];
    const SoraAttackDef* attacks[3];
    u8 tapTimers[0x2];
    u8 mainSide;
    u8 sioKeysA;
    u16 platformPriority;
    s32 platformX;
    s32 platformY;
    s32 platformZ;
    const u16* groundSongs;
    Task* task;
    TaskDesc* summonDesc;
    u8 swingSpeed;
    u8 breakAnim;
    u8 keyblade;
    s32 unk_194;
    s32 targetY;
    s32 scaleX;
    s32 scaleY;
    BtlObj* target;
    u16 frameCount;
} BtlSoraWork;

enum BtlRikuFlag {
    BTL_RIKU_FLAG_SWING_HIT = 0x2,
    BTL_RIKU_FLAG_HIDDEN = 0x4,
    BTL_RIKU_FLAG_OVER_PLATFORM = 0x10,
    BTL_RIKU_FLAG_ON_PLATFORM = 0x20,
    BTL_RIKU_FLAG_COMBO_EXTENDED = 0x40,
    BTL_RIKU_FLAG_PASS_THROUGH = 0x80,
    BTL_RIKU_FLAG_HIT_FLASH = 0x100,
    BTL_RIKU_FLAG_AT_SIDE_EDGE = 0x200,
    BTL_RIKU_FLAG_FIRE_LAUNCHED = 0x400,
    BTL_RIKU_FLAG_AFTERIMAGE = 0x800,
    BTL_RIKU_FLAG_HC_STATUS = 0x1000,
    BTL_RIKU_FLAG_DASH_UP = 0x2000
};

typedef struct BtlRikuWork {
    ObjTiles* tiles2;
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    AnimState anim;
    TaskPool tasks;
    u32 state;
    u32 nextState;
    BtlObj actor;
    s32 vz;
    s16 stateTimer;
    s16 steps;
    u16 unk_15C;
    u16 flags;
    s32 speed;
    u8 angle;
    u8 comboCount;
    u8 variant[0x2];
    const RikuAttackDef* attacks[3];
    u8 tapTimers[0x4];
    u8 mainSide;
    u8 sioKeysA;
    u16 platformPriority;
    s32 platformX;
    s32 platformY;
    s32 platformZ;
    const u16* groundSongs;
    u32 task;
    TaskDesc* summonDesc;
    s32 unk_194;
    u8 unk_198[0x4];
    s32 scaleX;
    s32 scaleY;
    BtlObj* target;
    u16 frameCount;
    void* paletteData;
    u16 limitDashCount;
    s32 targetX;
    s32 targetY;
    s16 drawCount;
    BtlDrawInfo drawInfo[9];
    BtlObj* actor2;
} BtlRikuWork;

void LoadBtlSoraPalette(BtlSoraWork* work);
void DisableBtlSoraPassThrough(BtlSoraWork* work);
void BgFxStartDashRing(s32 x, s32 y, s32 z, u8 flip);
void BgFxStartRagnarokShot(s32 x, s32 y, s32 z, u8 flip);
s32 ResolveLinkActiveCardsMove(s32* out, s32 side);

typedef struct BtlMapWork {
    s32 xMin;
    s32 xMax;
    s32 yMin;
    s32 yMax;
} BtlMapWork;

typedef struct BtlTaskArg {
    s32 side;
    u8 mainSide;
} BtlTaskArg;

#endif /* GUARD_BTL_H */
