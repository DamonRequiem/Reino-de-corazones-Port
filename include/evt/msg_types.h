#ifndef GUARD_MSG_TYPES_H
#define GUARD_MSG_TYPES_H

#include "types.h"

#ifdef VERSION_EU
typedef u8 MsgLatinChar;
#else
typedef u16 MsgLatinChar;
#endif

enum EventCameraMode {
    CAMERA_MODE_FOLLOW,
    CAMERA_MODE_APPROACH,
    CAMERA_MODE_KEEP
};

enum EventCameraKeyframeFlag {
    CAMERA_KEYFRAME_FLAG_FLASH = 0x10,
    CAMERA_KEYFRAME_FLAG_FADE_OUT_WHITE = 0x20,
    CAMERA_KEYFRAME_FLAG_FADE_OUT_BLACK = 0x40,
    CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE = 0x80,
    CAMERA_KEYFRAME_FLAG_FADE_IN_BLACK = 0x100,
    CAMERA_KEYFRAME_FLAG_HALF_FLASH = 0x200,
    CAMERA_KEYFRAME_FLAG_SHAKE_MEDIUM = 0x400,
    CAMERA_KEYFRAME_FLAG_SHAKE_LARGE = 0x800,
    CAMERA_KEYFRAME_FLAG_SWAY = 0x1000,
    CAMERA_KEYFRAME_FLAG_SHAKE_SMALL = 0x2000,
    CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE_LINEAR = 0x4000,
    CAMERA_KEYFRAME_FLAG_END = 0x8000,
    CAMERA_KEYFRAME_FLAG_NO_FLASH_SOUND = 0x10000,
    CAMERA_KEYFRAME_FLAG_WAVE_START = 0x20000,
    CAMERA_KEYFRAME_FLAG_WAVE_STOP = 0x40000
};

#define CAMERA_KEYFRAME_MODE_MASK 0xF
typedef struct EventCameraKeyframe {
    s32 frame;
    s32 x;
    s32 y;
    s32 yOffset;
    u8 target;
    u32 flags;
    u16 duration;
    void* callback;
} EventCameraKeyframe;

enum MessageScriptFlag {
    MSG_SCRIPT_FLAG_FOCUS_SPEAKER = 0x10,
    MSG_SCRIPT_FLAG_SILHOUETTE = 0x20,
    MSG_SCRIPT_FLAG_YES_NO = 0x40,
    MSG_SCRIPT_FLAG_NO_FADE = 0x80,
    MSG_SCRIPT_FLAG_END = 0x8000
};

enum MsgWinPosition {
    MSG_WIN_POSITION_TOP_FACE_RIGHT,
    MSG_WIN_POSITION_BOTTOM_FACE_RIGHT,
    MSG_WIN_POSITION_TOP_FACE_LEFT,
    MSG_WIN_POSITION_BOTTOM_FACE_LEFT,
    MSG_WIN_POSITION_KEEP
};

typedef struct MessageScriptEntry {
    u32 portraitId;
    u32 expressionId;
    u32 positionIndex;
    u8 charDelay;
    const void* text;
    u16 flags;
    u16 frame;
} MessageScriptEntry;

#ifdef VERSION_JP
#define EVENT_TEXT_DELAY 3
#else
#define EVENT_TEXT_DELAY 1
#endif

#ifdef VERSION_EU
#define EVENT_TEXT(name) (&name##ByLanguage)
#else
#define EVENT_TEXT(name) (name)
#endif

struct EventCharaWork;

typedef void (*EventCharaKeyframeFunc)(struct EventCharaWork*);

enum EventCharaMotion {
    CHARA_MOTION_SET_POSITION = 2,
    CHARA_MOTION_MOVE_TO = 3,
    CHARA_MOTION_WALK = 4
};

enum EventCharaKeyframeFlag {
    CHARA_KEYFRAME_FLAG_PRIORITY_1 = 0x10,
    CHARA_KEYFRAME_FLAG_FAST = 0x20,
    CHARA_KEYFRAME_FLAG_HFLIP = 0x40,
    CHARA_KEYFRAME_FLAG_BOB = 0x80,
    CHARA_KEYFRAME_FLAG_NO_SHADOW = 0x100,
    CHARA_KEYFRAME_FLAG_PLAYER_CONTROL = 0x200,
    CHARA_KEYFRAME_FLAG_PRIORITY_0 = 0x400,
    CHARA_KEYFRAME_FLAG_SILHOUETTE = 0x800,
    CHARA_KEYFRAME_FLAG_KEEP_ANIM = 0x1000,
    CHARA_KEYFRAME_FLAG_DEFER_SPAWN = 0x2000,
    CHARA_KEYFRAME_FLAG_SPAWN = 0x4000,
    CHARA_KEYFRAME_FLAG_END = 0x8000,
    CHARA_KEYFRAME_FLAG_DESPAWN = 0x10000,
    CHARA_KEYFRAME_FLAG_BOB_LARGE = 0x40000,
    CHARA_KEYFRAME_FLAG_BLINK = 0x80000,
    CHARA_KEYFRAME_FLAG_TRANSLUCENT = 0x100000
};

#define CHARA_KEYFRAME_MOTION_MASK 0xF
typedef struct EventCharaKeyframe {
    u32 anim;
    u16 frame;
    s32 x;
    s32 y;
    s32 z;
    u16 motionArg;
    u32 flags;
    void* update;
    EventCharaKeyframeFunc callback;
} EventCharaKeyframe;

typedef struct EventCharaTrack {
    const EventCharaKeyframe* keyframes;
    u8 chara;
} EventCharaTrack;

enum EvSoundFlag {
    EV_SOUND_FLAG_FADE_OUT = 0x1,
    EV_SOUND_FLAG_FADE_IN = 0x2,
    EV_SOUND_FLAG_STOP = 0x4,
    EV_SOUND_FLAG_END = 0x8000
};

typedef struct EvSoundCue {
    u16 song;
    u16 frame;
    u16 flags;
    u16 unk_06;
} EvSoundCue;

enum EventBgEffectFlag {
    EVENT_BG_EFFECT_FLAG_LOAD = 0x1,
    EVENT_BG_EFFECT_FLAG_CLEAR = 0x2,
    EVENT_BG_EFFECT_FLAG_FADE_OUT = 0x4,
    EVENT_BG_EFFECT_FLAG_FADE_IN = 0x8,
    EVENT_BG_EFFECT_FLAG_FULL_FADE = 0x10,
    EVENT_BG_EFFECT_FLAG_END = 0x8000
};

typedef struct EventBgEffectEntry {
    u16 frame;
    u16 effect;
    s32 x;
    s32 y;
    u16 flags;
} EventBgEffectEntry;

enum EventExitCode {
    EVENT_EXIT_WORLD_SELECT = 1,
    EVENT_EXIT_BATTLE_TUTORIAL_0,
    EVENT_EXIT_MAP_1F,
    EVENT_EXIT_BATTLE_TUTORIAL_1,
    EVENT_EXIT_MAP_4F,
    EVENT_EXIT_MAP_6F,
    EVENT_EXIT_MOVIE_6F_GOAL = 10,
    EVENT_EXIT_MOVIE_12F_E2,
    EVENT_EXIT_MOVIE_ENDING,
    EVENT_EXIT_MOVIE_RIKU_ENDING,
    EVENT_EXIT_NONE = 0xFFFF
};

#define POOH_LEVEL_NONE 0xFF

typedef struct EventSequenceDef {
    u8 charaCount;
    const EventCharaTrack* charaTracks;
    const EventCameraKeyframe* keyframes;
    const MessageScriptEntry* script;
    const EvSoundCue* soundCues;
    const EventBgEffectEntry* bgEffects;
    u16 endFrame;
    u8 toMap;
    u8 startsBattle;
    u8 toTitle;
    u8 toCopyright;
    u8 toMapFld;
    u16 battleId;
    u16 nextEvent;
    u16 startDelay;
    u8 unk_26[2];
    u16 exitCode;
    u8 unk_2A;
    u8 world;
    u8 poohLevel;
} EventSequenceDef;

extern const EventSequenceDef* gEventSequenceDefs[];

typedef struct MsgFaceControl {
    u8 portraitId;
    u8 expressionId;
    u8 command;
    u8 silhouette;
    u32 positionIndex;
    u8 shown;
} MsgFaceControl;

typedef struct GlyphWidthTable {
    u16 widths[256];
} GlyphWidthTable;

#endif
