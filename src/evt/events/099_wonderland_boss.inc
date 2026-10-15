#ifdef VERSION_US
#include "event_099_text.inc"
#endif

static const MessageScriptEntry sEvent099Script[1] = {
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent099Text00), MSG_SCRIPT_FLAG_END, 130 },
};

#ifdef VERSION_JP
#include "event_099_text.inc"
#endif

static const EventCameraKeyframe sEvent099Camera[2] = {
    { -65536, 30720, 43008, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -64536, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 60, NULL },
};

static const EvSoundCue sEvent099SoundCues[3] = {
    { SONG_BGM_EVENT2, 1, 0, 0 },
    { SONG_EV_EV10_05, 131, 0, 0 },
    { SONG_BGM_BOSS1_WORLD, 180, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent099Track0[2] = {
    { 18, 131, 15360, 55296, 0, 0, 66, NULL, NULL },
    { 13, 160, 0, 0, 0, 64, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent099Track1[3] = {
    { 932, 131, 21248, 32768, -9728, 0, 2, NULL, NULL },
    { 933, 180, 0, 0, 0, 0, 5, NULL, NULL },
    { 932, 2200, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent099Tracks[2] = {
    { sEvent099Track0, EVENT_CHARA_SORA },
    { sEvent099Track1, EVENT_CHARA_BOSS_TRICKMASTER },
};

const EventSequenceDef gEvent099 = {
    ARRAY_COUNT(sEvent099Tracks),
    sEvent099Tracks,
    sEvent099Camera,
    sEvent099Script,
    sEvent099SoundCues,
    NULL,
    160,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_TRICKMASTER,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
