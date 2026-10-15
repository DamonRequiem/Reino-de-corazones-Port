#ifdef VERSION_US
#include "event_084_text.inc"
#endif

static const MessageScriptEntry sEvent084Script[3] = {
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent084Text00), 0, 100 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent084Text01), 0, 180 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent084Text02), MSG_SCRIPT_FLAG_YES_NO | MSG_SCRIPT_FLAG_END, 200 },
};

#ifdef VERSION_JP
#include "event_084_text.inc"
#endif

static const EventCameraKeyframe sEvent084Camera[2] = {
    { -65416, 33792, 35840, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent084SoundCues[2] = {
    { SONG_BGM_EVENT1, 0, 0, 0 },
    { SONG_BGM_EVENT1, 219, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent084Track0[2] = {
    { 2, 200, 35072, 36864, 0, 0, 2, NULL, NULL },
    { 2, 550, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent084Track1[2] = {
    { 114, 101, 40448, 42752, 0, 0, 2, NULL, NULL },
    { 114, 200, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent084Track2[2] = {
    { 144, 200, 26112, 39168, 0, 0, 66, NULL, NULL },
    { 164, 201, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent084Track3[2] = {
    { 231, 510, 24832, 45056, 0, 0, 66, NULL, NULL },
    { 231, 550, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent084Tracks[4] = {
    { sEvent084Track0, EVENT_CHARA_SORA },
    { sEvent084Track1, EVENT_CHARA_DONALD },
    { sEvent084Track2, EVENT_CHARA_GOOFY },
    { sEvent084Track3, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent084 = {
    ARRAY_COUNT(sEvent084Tracks),
    sEvent084Tracks,
    sEvent084Camera,
    sEvent084Script,
    sEvent084SoundCues,
    NULL,
    220,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_SHADOW_100,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
