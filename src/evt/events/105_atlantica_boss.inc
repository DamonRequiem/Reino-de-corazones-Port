#ifdef VERSION_US
#include "event_105_text.inc"
#endif

static const MessageScriptEntry sEvent105Script[1] = {
    { PORTRAIT_URSULA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent105Text00), MSG_SCRIPT_FLAG_END, 100 },
};

#ifdef VERSION_JP
#include "event_105_text.inc"
#endif

static const EvSoundCue sEvent105SoundCues[1] = {
    { SONG_BGM_EVENT2, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent105Camera[1] = {
    { -64626, 81920, 102400, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent105Track0[1] = {
    { 21, 459, 81920, 122880, 0, 0, 32834, NULL, NULL },
};

static const EventCharaKeyframe sEvent105Track1[1] = {
    { 937, 459, 45312, 60928, 0, 0, 32770, NULL, NULL },
};

static const EventCharaTrack sEvent105Tracks[2] = {
    { sEvent105Track0, EVENT_CHARA_SORA },
    { sEvent105Track1, EVENT_CHARA_BOSS_URSULA },
};

const EventSequenceDef gEvent105 = {
    ARRAY_COUNT(sEvent105Tracks),
    sEvent105Tracks,
    sEvent105Camera,
    sEvent105Script,
    sEvent105SoundCues,
    NULL,
    150,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_URSULA,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
