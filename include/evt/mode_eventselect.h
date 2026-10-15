#ifndef GUARD_MODE_EVENTSELECT_H
#define GUARD_MODE_EVENTSELECT_H

#include "types.h"
#include "taskpool.h"
#include "evt_types.h"
#include "event_chara_types.h"
#include "anim.h"
#include "msg_types.h"

typedef struct EventSoundMix {
    s16 pan;
    u16 volume;
} EventSoundMix;

typedef struct DownWork {
    s32 x[8];
    s32 y[8];
    u8 wobble[8];
    u16 angle[8];
} DownWork;

typedef struct EvSoundWork {
    const EvSoundCue* soundCues;
    u8 eventId;
    u8 cue;
    u8 unk_06;
    u8 fadeMode;
    s32 volume;
} EvSoundWork;

typedef struct EventDebugWork {
    void* tiles;
    void* palette;
    u16 digits[16];
    u8 digitCount;
} EventDebugWork;

typedef struct EffectWork {
    EventCharaWork* actor;
    void* tiles;
    void* palette;
    void* gfx;
    DownWork* down;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 z2;
    s32 vx;
    s32 vz;
    u16 timer;
    u16 age;
    u8 followFlip;
    u8 state;
    TaskPool tasks;
} EffectWork;

extern EventState* gEventState;
extern const EventCharaParams gEventCharaParams[];

void mode_eventselect_0();
void mode_eventselect_1();
void mode_eventselect_2();
void Hanabira_0(EffectWork* work, EventCharaWork* chara);
s32 Hanabira_1(EffectWork* work);
void Hanabira_2(EffectWork* work);
void Hanabira_3(EffectWork* work);
void Hanabira_c_0(EffectWork* work, EventCharaWork* chara);
s32 Hanabira_c_1(EffectWork* work);
void Hanabira_c_2(EffectWork* work);
void Hanabira_c_3(EffectWork* work);
void smoke_0(EffectWork* work, EventCharaWork* chara);
void Exclamation_0(EffectWork* work, EventCharaWork* chara);
void balloon_0(EffectWork* work, EventCharaWork* chara);
s32 EffectUpdateObj(EffectWork* work);
s32 Exclamation_1(EffectWork* work);
void EffectDrawObj(EffectWork* work);
void EffectReleaseObj(EffectWork* work);
void Question_0(EffectWork* work, EventCharaWork* chara);
void TinkerbellParticleInit(EffectWork* work, EventCharaWork* chara);
s32 Question_1(EffectWork* work);
s32 TinkerbellParticleUpdate(EffectWork* work);
void TinkerbellParticleDraw(EffectWork* work);
void TinkerbellParticleDestroy(EffectWork* work);
void GlowNose_0(EffectWork* work, EventCharaWork* chara);
s32 GlowNose_1(EffectWork* work);
void GlowNose2_0(EffectWork* work, EventCharaWork* chara);
s32 GlowNose2_1(EffectWork* work);
void down_0(EffectWork* work, EventCharaWork* chara);
s32 down_1(EffectWork* work);
s32 down_2(EffectWork* work);
void down_3(EffectWork* work);
void Tinkerbell_0(EffectWork* work, EventCharaWork* chara);
s32 Tinkerbell_1(EffectWork* work);
void Tinkerbell_2(EffectWork* work);
void Tinkerbell_3(EffectWork* work);
void CreateGlowNose2Task(EventCharaWork* work);
void EV_SOUND_0(EvSoundWork* work, u8* arg);
s32 EV_SOUND_1(EvSoundWork* work);
void EV_SOUND_2();
void EV_SOUND_3();
void EvSoundUpdateFadeIn(EvSoundWork* work);
void Event_Debug_0(EventDebugWork* work);
s32 Event_Debug_1(EventDebugWork* work);
void Event_Debug_2(EventDebugWork* work);
void Event_Debug_3(EventDebugWork* work);

s16 GetEventListLength(u8 list);

#endif
