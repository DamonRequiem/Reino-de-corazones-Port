#ifdef VERSION_US
#include "event_092_text.inc"
#endif

static const MessageScriptEntry sEvent092Script[1] = {
    { PORTRAIT_OOGIE_BOOGIE, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent092Text00), MSG_SCRIPT_FLAG_END, 100 },
};

#ifdef VERSION_JP
#include "event_092_text.inc"
#endif

static const EventCameraKeyframe sEvent092Camera[1] = {
    { -65485, 94208, 153600, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent092SoundCues[1] = {
    { SONG_BGM_EVENT2, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent092Track0[1] = {
    { 20, 30, 92160, 172032, 0, 0, 32834, NULL, NULL },
};

static const EventCharaKeyframe sEvent092Track1[1] = {
    { 936, 30, 78336, 58880, 0, 0, 32770, NULL, NULL },
};

static const EventCharaTrack sEvent092Tracks[2] = {
    { sEvent092Track0, EVENT_CHARA_SORA },
    { sEvent092Track1, EVENT_CHARA_BOSS_OOGIE_BOOGIE },
};

const EventSequenceDef gEvent092 = {
    ARRAY_COUNT(sEvent092Tracks),
    sEvent092Tracks,
    sEvent092Camera,
    sEvent092Script,
    sEvent092SoundCues,
    NULL,
    200,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_OOGIE_BOOGIE,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
