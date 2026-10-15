#ifdef VERSION_US
#include "event_125_text.inc"
#endif

static const MessageScriptEntry sEvent125Script[1] = {
    { PORTRAIT_HADES, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent125Text00), MSG_SCRIPT_FLAG_END, 200 },
};

#ifdef VERSION_JP
#include "event_125_text.inc"
#endif

static const EvSoundCue sEvent125SoundCues[1] = {
    { SONG_BGM_EVENT2, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent125Camera[1] = {
    { -55537, 65536, 103168, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent125Track0[2] = {
    { 21, 1, 55040, 116992, 0, 0, 66, NULL, NULL },
    { 21, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent125Track1[2] = {
    { 395, 1, 76032, 110848, 0, 0, 2, NULL, NULL },
    { 395, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent125Tracks[2] = {
    { sEvent125Track0, EVENT_CHARA_SORA },
    { sEvent125Track1, EVENT_CHARA_HADES },
};

const EventSequenceDef gEvent125 = {
    ARRAY_COUNT(sEvent125Tracks),
    sEvent125Tracks,
    sEvent125Camera,
    sEvent125Script,
    sEvent125SoundCues,
    NULL,
    300,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_HADES,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
