#ifdef VERSION_US
#include "event_123_text.inc"
#endif

static const MessageScriptEntry sEvent123Script[3] = {
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent123Text00), 0, 300 },
    { PORTRAIT_JIMINY_CRICKET, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent123Text01), 0, 380 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent123Text02), MSG_SCRIPT_FLAG_END, 420 },
};

#ifdef VERSION_JP
#include "event_123_text.inc"
#endif

static const EvSoundCue sEvent123SoundCues[2] = {
    { SONG_BGM_EVENT1, 0, 0, 0 },
    { SONG_BGM_EVENT1, 515, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent123Camera[1] = {
    { -60536, 68096, 38656, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent123Track0[17] = {
    { 21, 150, 61440, 40192, 0, 0, 2, NULL, NULL },
    { 22, 165, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 220, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 225, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 235, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 245, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 255, 0, 0, 0, 0, 69, NULL, NULL },
    { 0, 265, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 299, 0, 0, 0, 0, 5, NULL, NULL },
    { 30, 302, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 405, 0, 0, 0, 0, 5, NULL, NULL },
    { 16, 415, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 495, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 500, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 505, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 510, 0, 0, 0, 0, 5, NULL, NULL },
    { 12, 999, 0, 0, 0, 83, 32868, NULL, NULL },
};

static const EventCharaKeyframe sEvent123Track1[11] = {
    { 123, 150, 65792, 50176, 0, 0, 2, NULL, NULL },
    { 124, 165, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 223, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 233, 0, 0, 0, 0, 69, NULL, NULL },
    { 111, 243, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 253, 0, 0, 0, 0, 5, NULL, NULL },
    { 111, 263, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 273, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 390, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 520, 0, 0, 0, 0, 69, NULL, NULL },
    { 121, 999, 0, 0, 0, 83, 32868, NULL, NULL },
};

static const EventCharaKeyframe sEvent123Track2[12] = {
    { 158, 150, 75776, 43776, 0, 0, 2, NULL, NULL },
    { 159, 165, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 220, 0, 0, 0, 0, 5, NULL, NULL },
    { 142, 230, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 240, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 250, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 270, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 280, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 390, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 510, 0, 0, 0, 0, 69, NULL, NULL },
    { 152, 999, 0, 0, 0, 83, 32868, NULL, NULL },
};

static const EventCharaKeyframe sEvent123Track3[8] = {
    { 229, 334, 0, 0, 0, 0, 66, NULL, NULL },
    { 231, 335, 60672, 39936, 0, 0, 2, NULL, NULL },
    { 234, 370, 0, 0, 0, 211, 36, EventCharaHop, NULL },
    { 231, 372, 0, 0, 0, 0, 5, NULL, NULL },
    { 233, 385, 0, 0, 0, 0, 64, EventCharaHop, NULL },
    { 229, 450, 0, 0, 0, 0, 69, NULL, NULL },
    { 233, 480, 0, 0, 0, 83, 100, EventCharaHop, NULL },
    { 229, 999, 0, 0, 0, 0, 32834, NULL, NULL },
};

static const EventCharaTrack sEvent123Tracks[4] = {
    { sEvent123Track0, EVENT_CHARA_SORA },
    { sEvent123Track1, EVENT_CHARA_DONALD },
    { sEvent123Track2, EVENT_CHARA_GOOFY },
    { sEvent123Track3, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent123 = {
    ARRAY_COUNT(sEvent123Tracks),
    sEvent123Tracks,
    sEvent123Camera,
    sEvent123Script,
    sEvent123SoundCues,
    NULL,
    520,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
