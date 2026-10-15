#ifndef GUARD_MSG_H
#define GUARD_MSG_H

#include "obj.h"
#include "msg_types.h"
#include "evt_types.h"
#include "event_chara_types.h"
#include "types.h"
#include "anim.h"
#include "text_types.h"
#include "taskpool.h"

#define MSG_CODE_END 0
#ifdef VERSION_EU
#define MSG_CODE_NL 0x1F
#define MSG_CODE_HIGHLIGHT 0x1D
#define MSG_CODE_PLAIN 0x1E
#else
#define MSG_CODE_NL 0x0A
#define MSG_CODE_HIGHLIGHT 0x4079
#define MSG_CODE_PLAIN 0x4000
#endif
#define MSG_CODE_JP_NL 0x6E6E

typedef struct SpriteTextLine {
    s32 x;
    s32 y;
    ObjTiles* glyphTiles[16];
    ObjPalette* palette;
    ObjPalette* alternatePalette;
    u8 length;
    u8 font;
    u8 visible;
    u8 unk_53;
    u8 useAlternatePalette;
} SpriteTextLine;

#define BG_TEXT_GLYPH_SPACE 0xFFFF

typedef struct BgTextLine {
    u8 x;
    u8 y;
    u16 glyphs[16];
    u8 length;
    u8 glyphHeight;
    u8 bg;
    u8 dirty;
    u8 paletteIndex;
} BgTextLine;

typedef struct MsgFaceWork {
    void* tiles;
    ObjPalette* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 scaleX;
    u8 steps;
    u8 arrived;
    u8 talking;
    u8 flipX;
    u8 visible;
    MsgFaceControl* face;
} MsgFaceWork;

typedef struct MsgWinWork {
    TaskPool tasks;
    ObjPalette* palette;
    s32 scrollX;
    u16 glyphPaletteIndex;
    u8 steps;
    u32 position;
    u8 shownChars;
    u8 charTimer;
    u8 charCount;
    u8 scriptIndex;
    u8 eventId;
    u8 textLoaded;
    u8 started;
    u8 waitCreated;
    MsgFaceControl face;
    u8 bg;
    const MessageScriptEntry* script;
    MsgLatinChar* nextText;
} MsgWinWork;

typedef struct EventSeqWork {
    TaskPool tasks;
    TaskPool tasks2;
    Task* task;
    u16 eventId;
    u8 fromGame;
    u8 ending;
    u8 unk_30;
    u8 unk_31;
    u8 hasBoss;
    const struct EventSequenceDef* seqDef;
    u16 timer;
#ifdef VERSION_EU
    u8 bg3MapUnpacked;
    u8 bg2MapUnpacked;
    u8 bg1MapUnpacked;
    u8 hasMapAnim;
#endif
} EventSeqWork;

typedef struct EventScanlineScroll {
    u8 unk_00[2];
    u8 enabled;
    u16 scrollX[160];
} EventScanlineScroll;

typedef struct EventCameraWork {
    s32 targetX;
    s32 targetY;
    u8 eventId;
    u8 keyframe;
    const EventCameraKeyframe* keyframes;
    u16 steps;
    u16 angle;
    u8 approachMode;
    u8 effectStarted;
    u16 wavePhase;
    EventScanlineScroll scanline;
} EventCameraWork;

typedef struct MsgWaitWork {
    void* tiles;
    void* tiles2;
    ObjPalette* palette2;
    void* tiles3;
    ObjPalette* palette3;
    ObjPalette* palette;
    void* palette4;
    TextSlot textSlots[10];
    TextSlot textSlots2[10];
    void* gfx;
    void* gfx2;
    AnimState anim2;
    AnimState anim;
    u8 textSlotCount;
    u8 textSlotCount2;
    s32 x;
    s32 y;
    u8 cursor;
    u8 unk_101;
    u8 timer;
    u8 nextPosition;
    u8 choiceShown;
} MsgWaitWork;

typedef struct TextGlyphSprite {
    s32 x;
    s32 y;
    void* tiles;
    ObjPalette* palette;
    ObjPalette* alternatePalette;
    u8 useAlternatePalette;
    u8 visible;
} TextGlyphSprite;

extern EventState* gEventState;

extern const EventCharaParams gEventCharaParams[];

void HideMsgGlyphs();
u16 LoadTwoDigitTextTileArray(u8 value, void** out);
void InitTextTileArray(void** tiles, u8 n);
void FreeTextTileArray(void** tiles, u8 n);
u16 LoadTwoDigitTextSlots(u8 value, TextSlot* out);
void RequestMsgfaceSlideIn(MsgFaceControl* ctl);
void RequestMsgfaceSlideOut(MsgFaceControl* ctl);
void view_2();
void view_3();
s32 LoadLatinTextSlots(const u16* text, TextSlot* slots);
s32 LoadJapaneseTextSlots(const u16* text, TextSlot* slots);
void SetBgTextLine(u8 x, u8 y, u8 glyphHeight, u8* text, u8 slot, u8 paletteIndex);
void SetSpriteTextSlotAscii(s32 x, s32 y, u8* str, u8 slot, u8 useAlternatePalette);
void DrawBgTextLines();
u8 GetStringLength(const u8* text);
u8 EventCharaHop(EventCharaWork* work, void* task);
void CreateMsgfaceTask(void* pool, MsgFaceControl* ctl, u8 portraitId, u8 expressionId, u8 positionIndex);
u8 LayoutMsgGlyphsPage(s32 x, s32 y, MsgLatinChar* text, MsgLatinChar** nextText);
void HBlankIntrEventScanlineScroll();
u8 MsgfaceFlipInUpdate(MsgFaceWork* work, void* task);
u8 MsgwinOpenUpdate(MsgWinWork* work, void* task);
u8 MsgwinTypeUpdate(MsgWinWork* work, void* task);
u8 MsgwinCloseUpdate(MsgWinWork* work, void* task);
void MsgwinTypeStep(MsgWinWork* work);
void MsgwinLoadEntry(MsgWinWork* work);
void MsgwinCheckStart(MsgWinWork* work);
u8 UpdateMsgwaitClosing(MsgWaitWork* work);
u8 msgface_1(MsgFaceWork* work, void* task);
u8 MsgfaceSlideInUpdate(MsgFaceWork* work, void* task);
u8 MsgfaceSlideOutUpdate(MsgFaceWork* work, void* task);
u8 MsgfaceChangeUpdate(MsgFaceWork* work, void* task);
u8 MsgfaceFlipOutUpdate(MsgFaceWork* work, void* task);
u8 UpdateMsgwaitYesnoChoice(MsgWaitWork* work, void* task);
void DrawMsgGlyphsWithPalette(u8 n, void* palette);
void ClearSpriteTextLines();

void GetSjisGlyph(u16 code, u16* glyph, u8* bank);

u8 event_chara_1(EventCharaWork* work, void* task);
u8 EventCharaToggleAnim(EventCharaWork* work, void* task);
u8 EventCharaFadeToBlack(void* work, void* task);
u8 EventCharaBlendDown2Update(EventCharaWork* work, void* task);
u8 EventCharaFadeToBlackUpdate(EventCharaWork* work, void* task);
u8 EventCharaToggleAnimUpdate(EventCharaWork* work, void* task);
u8 AdvanceEventCharaKeyframe(EventCharaWork* work);
void UpdateEventCharaMotion(EventCharaWork* work);
s32 PlayEventCharaAnimSounds(EventCharaWork* work);
u8 EventCharaHopUpdate(EventCharaWork* work, void* task);
u8 EventCharaHopHigh(EventCharaWork* work, void* task);
u8 EventCharaHopHighUpdate(EventCharaWork* work, void* task);
u8 EventCharaHopLow(EventCharaWork* work, void* task);
u8 EventCharaHopLowUpdate(EventCharaWork* work, void* task);
u8 EventCharaDrop(EventCharaWork* work, void* task);
u8 EventCharaDropUpdate(EventCharaWork* work, void* task);
u8 EventCharaFadeOut(void* work, void* task);
u8 EventCharaFadeOutUpdate(EventCharaWork* work, void* task);
u8 EventCharaFadeIn(void* work, void* task);
u8 EventCharaFadeInUpdate(EventCharaWork* work, void* task);
u8 EventCharaBlendUp(void* work, void* task);
u8 EventCharaBlendUpUpdate(EventCharaWork* work, void* task);
u8 EventCharaBlendDown(void* work, void* task);
u8 EventCharaBlendDownUpdate(EventCharaWork* work, void* task);
u8 EventCharaCircleSlow(EventCharaWork* work, void* task);
u8 EventCharaCircleSlowUpdate(EventCharaWork* work, void* task);
u8 EventCharaCircleFast(EventCharaWork* work, void* task);
u8 EventCharaCircleFastUpdate(EventCharaWork* work, void* task);
u8 EventCharaJitter(EventCharaWork* work, void* task);
u8 EventCharaJitterUpdate(EventCharaWork* work, void* task);
void SetEventCharaEndAnim(EventCharaWork* work);
void ApplyEventCharaDrawFlags(EventCharaWork* work);
void SetMsgfacePortrait(MsgFaceControl* ctl, u8 portraitId, u8 expressionId, u8 positionIndex);
void ClearEventObjPaletteExclusions();
void PlaySoraFootstep(EventCharaWork* work, u8 kind, u8 flag);
void PlayDonaldFootstep(EventCharaWork* work, u8 kind, u8 flag);
void PlayGoofyFootstep(EventCharaWork* work, u8 kind, u8 flag);
void SetEventCameraCenter(EventCameraWork* work);
void EventCameraFollow(EventCameraWork* work);
u8 FindEventCameraTarget(EventCameraWork* work);
void EventCameraSnap(EventCameraWork* work);
u8 FindEventCharaTrack(EventCameraWork* work, u8 chara);
u8 UpdateEventCameraFollowPlayer(EventCameraWork* work);
void UpdateEventScanlineWave(EventCameraWork* work);
void EventCameraApproach(EventCameraWork* work);

void ReadEventCharaDpadAngle(EventCharaWork* work);
u8 UpdateEventCharaJump(EventCharaWork* work, void* task);
void SetupEventCharaShadow(EventCharaWork* work);
#ifdef VERSION_EU
u8 LoadEventBg3(EventSeqWork* work);
u8 LoadEventBg2Map(EventSeqWork* work);
u8 LoadEventBg1(EventSeqWork* work);
u8 InitEventState(EventSeqWork* work);
#endif

void msgwait_yesno_0(MsgWaitWork* work, u8* arg);
u8 UpdateEventSeq(EventSeqWork* work, void* task);
void UpdateEventCharaAngle(EventCharaWork* work);
u8 UpdateEventCharaControl(EventCharaWork* work, void* task);

void event_seq_0(EventSeqWork* work, u8* arg);
u8 event_seq_1(EventSeqWork* work, void* task);
void event_seq_2(EventSeqWork* work);
void event_seq_3(EventSeqWork* work);
void event_chara_0(EventCharaWork* work, EventSeqArg* arg);
void event_chara_2(EventCharaWork* work);
void event_chara_3(EventCharaWork* work);
void msgface_0(MsgFaceWork* work, MsgFaceControl* ctl);
void msgface_2(MsgFaceWork* work);
void msgface_3(MsgFaceWork* work);
void msgwait_0(MsgWaitWork* work, u8* arg);
u8 msgwait_1(MsgWaitWork* work, void* task);
void msgwait_2(MsgWaitWork* work);
void msgwait_3(MsgWaitWork* work);

#endif /* GUARD_MSG_H */
