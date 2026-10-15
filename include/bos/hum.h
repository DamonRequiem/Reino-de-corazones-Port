#ifndef GUARD_HUM_H
#define GUARD_HUM_H

#include "hum_types.h"
#include "types.h"
#include "jiminy_types.h"
#include "anim.h"
#include "taskpool.h"
#include "obj.h"
#include "battle_actor_types.h"

typedef struct VixenSub {
    u8 pending;
    u8 active;
    s32 x;
    s32 y;
} VixenSub;

typedef struct CloudWork {
    HumWork base;
    u32 speed;
    u16 state;
    u16 attackPhase;
    u16 nextState;
} CloudWork;

enum HookFlag {
    HOOK_FLAG_BOMB_THROWN = 0x1,
    HOOK_FLAG_POST_THROW_ANIM = 0x2
};

typedef struct HookWork {
    HumWork base;
    u32 speed;
    s32 playerSlide;
    s32 slide;
    u16 angle;
    u16 rollLevel;
    u16 flags;
    TaskPool tasks;
    void* bombTask;
    void* bombTask2;
    void* bombTask3;
} HookWork;

typedef struct HookMoonWork {
    void* tiles;
    ObjPalette* palette;
    u16 angle;
    u8 backdropSet;
} HookMoonWork;

typedef struct VixenNdlArgs {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 facingLeft;
    u16 variant;
    void* tiles;
    u8 unk_1C[0x04];
} VixenNdlArgs;

typedef struct VixenNdlWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 hitPhase;
    u8 hitDone;
    u8 flipped;
} VixenNdlWork;

typedef struct VixenFrzWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u32 state;
    s16 timer;
    u16 variant;
    u16 flipped;
} VixenFrzWork;

typedef struct VixenIceWork {
    u32 state;
    void* tiles;
    ObjPalette* palette;
    AnimState anim;
    VixenSub* sub;
    Collider collider;
    s16 stateTimer;
    u16 steps;
    u16 lifetime;
    s32 scale;
    s32 targetScale;
} VixenIceWork;

typedef struct LexTmh0Work {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 facingLeft;
    s32 scale;
    s16 steps;
} LexTmh0Work;

typedef struct LexTmhWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 facingLeft;
    u8 done;
    s32 state;
    s32 targetX;
    s32 targetY;
    s32 vz;
    void* tiles2;
    void* palette2;
    u8 flyLeft;
    s16 timer;
} LexTmhWork;

enum RikuSpawnFlag {
    RIKU_SPAWN_FLAG_FACING_LEFT = 0x1
};

typedef struct RikuSpawn {
    s32 x;
    s32 y;
    s32 z;
    u16 flags;
    AnimState anim;
    const void* tileSrc;
    s32 scale;
} RikuSpawn;

typedef struct MahluxiaFlwWork {
    s32 state;
    void* tiles;
    void* palette;
    AnimState anim;
    u8 unk_24[0x04];
    s32 vz;
    s32 vx;
    s32 x;
    s32 y;
    s32 z;
} MahluxiaFlwWork;

enum MahluxiaFlag {
    MAHLUXIA_FLAG_SWING_DOWN = 0x1,
    MAHLUXIA_FLAG_AFTERIMAGE = 0x2,
    MAHLUXIA_FLAG_EFFECT_LAUNCHED = 0x4
};

typedef struct MahluxiaWork {
    HumWork base;
    HumSub sub;
    s32 hoverZ;
    s16 swingAmplitude;
    u16 steps;
    s32 angle;
    u16 flags;
    s32 swingBaseY;
    s16 afterimageTimer;
    RikuSpawn spawns[9];
    s32 subSpeed;
    TaskPool tasks;
} MahluxiaWork;

typedef struct LaxeneKnfWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 facingLeft;
    u8 onScreen;
    u16 timer;
    s32 playerPrevX;
    s32 playerPrevY;
    s32 playerPrevZ;
    s32 state;
    s32 vx;
} LaxeneKnfWork;

enum LaxeneFlag {
    LAXENE_FLAG_ATTACK_HIT = 0x1
};

typedef struct LaxeneWork {
    HumWork base;
    s32 hoverZ;
    u16 unk_18C;
    u16 flags;
    u16 scaleSteps;
    TaskPool tasks;
} LaxeneWork;

enum VixenFlag {
    VIXEN_FLAG_SLIDE_DOWN = 0x1
};

typedef struct VixenWork {
    HumWork base;
    s32 hoverZ;
    u8 unk_18C[0x0C];
    s32 needleX;
    s32 needleY;
    u16 angle;
    u16 flags;
    TaskPool tasks;
    void* task;
    u8 needleCount;
    s32 slideSpeed;
    VixenSub sub[3];
    ObjTiles needleTiles;
} VixenWork;

enum LexceusFlag {
    LEXCEUS_FLAG_ATTACK_HIT = 0x1,
    LEXCEUS_FLAG_COMBO_FOLLOWUP = 0x2,
    LEXCEUS_FLAG_WEAPON_THROWN = 0x4
};

typedef struct LexceusWork {
    HumWork base;
    u8 unk_188[0x38];
    s32 unk_1C0;
    s32 hoverZ;
    u8 unk_1C8[0x02];
    u16 flags;
    s16 scaleSteps;
    s32 targetScaleX;
    s32 targetScaleY;
    TaskPool tasks;
    void* task;
    s32 tilt;
    s32 targetTilt;
    u16 tiltSteps;
    s32 tiltSlide;
    s32 cameraBaseY;
} LexceusWork;

typedef struct HadesSub {
    s32 groundY;
    s32 x;
    s32 y;
    s32 z;
    s32 x2;
    s32 y2;
    s32 z2;
    s32 x3;
    s32 y3;
    s32 z3;
} HadesSub;

enum HadesFlag {
    HADES_FLAG_ANGRY = 0x1,
    HADES_FLAG_FLAMES_ACTIVE = 0x2,
    HADES_FLAG_FLAMES_ENDING = 0x4
};

typedef struct HadesWork {
    HumWork base;
    HumSub sub;
    s32 hoverZ;
    u16 unk_1C8;
    u16 flags;
    s16 angryAttacks;
    s32 subVz;
    void* tiles;
    void* tiles2;
    void* tiles3;
    AnimState anim;
    AnimState anim2;
    AnimState anim3;
    void* palette;
    HadesSub sub2[2];
    s32 scale;
} HadesWork;

typedef struct LeonWork {
    HumWork base;
    u16 flashTimer;
    u8 gunbladeRaised;
    u64 savedLearnedStocks;
    u64 savedLearnedStocks2;
} LeonWork;

typedef struct AnsemWork {
    HumWork base;
    HumSub sub;
    s32 hoverZ;
    s32 subOffsetX;
    s32 subOffsetZ;
    s32 subRiseSpeed;
    u8 unk_1D4[0x02];
    s16 steps;
    s16 repeatCount;
} AnsemWork;

typedef struct VixenFrgDef {
    s16 x;
    s16 z;
    u16 frame;
    u16 spriteFlags;
} VixenFrgDef;

typedef struct VixenFrgSub {
    void* gfx;
    s32 x;
    s32 y;
    s32 z;
    s32 vz;
    s32 vx;
    s32 vy;
    u16 spriteFlags;
} VixenFrgSub;

typedef struct VixenFrgWork {
    ObjTiles tilesSlot;
    void* tiles;
    void* palette;
    s16 timer;
    VixenFrgSub sub[15];
    u8 blinking;
} VixenFrgWork;

enum RikuFlag {
    RIKU_FLAG_DIVE_HIT = 0x1,
    RIKU_FLAG_FIRE_LAUNCHED = 0x2,
    RIKU_FLAG_AFTERIMAGE = 0x4
};

typedef struct RikuWork {
    HumWork base;
    HumSub sub;
    s32 unk_1C4;
    u16 state;
    u16 flags;
    s16 afterimageTimer;
    RikuSpawn spawns[9];
    u16 dashCount;
} RikuWork;

typedef struct HookBombWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 facingLeft;
    s32 vz;
    u8 angle;
    s32 state;
    s16 timer;
    void* tiles2;
    void* palette2;
    u8 visible;
    s16 bounceCount;
    s16 maxBounces;
    u16 variant;
    s32 speed;
} HookBombWork;

typedef struct LexRockSub {
    u8 hasHit;
    s32 x;
    s32 y;
    s32 z;
    s32 vz;
    s32 vx;
    s32 vy;
} LexRockSub;

typedef struct LexRockWork {
    void* tiles2[12];
    void* palette2;
    AnimState anim[12];
    s32 x;
    s32 y;
    s32 z;
    u8 facingLeft;
    u16 state;
    u16 rockCount;
    s16 timer;
    LexRockSub sub[12];
    void* tiles;
    void* palette;
    u8 blinking;
} LexRockWork;

enum AxcelFlag {
    AXCEL_FLAG_ATTACK_HIT = 0x1
};

typedef struct AxcelWork {
    HumWork base;
    HumSub sub;
    HumSub sub2;
    s32 hoverZ;
    s16 steps;
    u16 flags;
    u16 scaleSteps;
    s32 targetScaleX;
    s32 targetScaleY;
    s32 orbitRadius;
    void* tiles;
    void* palette;
    TaskPool tasks;
    u16 subAngle;
    u16 sub2Angle;
} AxcelWork;

typedef struct AxcelPtcWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
} AxcelPtcWork;

typedef struct RobeWork {
    HumWork base;
    u16 idleAnim;
} RobeWork;

extern TaskDesc gTaskDescHumMahluxiaFlw;

void CloudJumpOffset(CloudWork* work, s16 distance, s32 speed);
void CloudJumpTo(CloudWork* work, s32 x, s32 y);
void CloudLeapTo(CloudWork* work, s32 x, s32 y);
s32 CloudTryJumpAway(CloudWork* work);
void AxcelDrawSubShadow(AxcelWork* work, HumSub* sub);
void RikuDrawAfterimage(RikuWork* work, RikuSpawn* spawn);
void RikuSaveAfterimage(RikuWork* work, RikuSpawn* dst);
void BgFxStartAnsemWave(s32 x, s32 y, s32 z, u8 facingLeft, s32 attack);
void LexceusHover(HumWork* work, s32 hoverZ);
s32 __modsi3(s32 a, s32 b);
u16 GetJiminyTextLength(const u16* text);
void JiminyLoadHiddenRow(s32 row, const u16* const* itemTexts);
void JiminyInitCursor(s16 x, s16 y, s16 rowHeight);
void JiminyReloadRows();
void JiminyUpdateCursor(s16 x, s16 y, s16 rowHeight);
void JiminyLoadRows(s16 visibleRows, s16 itemCount, const u16* const* itemTexts, const u16* itemFlags, const u16* itemChildren, s16 listX, s16 listY, s16 rowHeight);

s32 GetJiminyEntryState(s32 idx);

#endif /* GUARD_HUM_H */
