#ifdef VERSION_US
#include "event_188_text.inc"
#endif

static const MessageScriptEntry sEvent188Script[9] = {
    { PORTRAIT_RIKU_REPLICA, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent188Text00), 0, 260 },
    { PORTRAIT_RIKU_REPLICA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent188Text01), 0, 470 },
    { PORTRAIT_RIKU_REPLICA, 5, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent188Text02), 0, 472 },
    { PORTRAIT_RIKU, 5, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent188Text03), 0, 500 },
    { PORTRAIT_RIKU_REPLICA, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent188Text04), 0, 690 },
    { PORTRAIT_RIKU_REPLICA, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent188Text05), 0, 800 },
    { PORTRAIT_RIKU, 5, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent188Text06), 0, 850 },
    { PORTRAIT_RIKU_REPLICA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent188Text07), 0, 880 },
    { PORTRAIT_RIKU_REPLICA, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent188Text08), MSG_SCRIPT_FLAG_END, 1000 },
};

#ifdef VERSION_JP
#include "event_188_text.inc"
#endif

static const EvSoundCue sEvent188SoundCues[4] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_BGM_EVENT_SILENCE, 465, EV_SOUND_FLAG_FADE_IN, 0 },
    { SONG_SND_379, 1080, 0, 0 },
    { SONG_BGM_EVENT_SILENCE, 1195, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent188Camera[1] = {
    { -64537, 65024, 88576, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent188Track0[5] = {
    { 561, 150, 73728, 99328, 0, 0, 2, NULL, NULL },
    { 562, 165, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 290, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 420, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 515, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent188Track1[5] = {
    { 705, 100, 56064, 93952, 0, 0, 66, NULL, NULL },
    { 705, 530, 0, 0, 0, 0, 1048901, NULL, NULL },
    { 705, 1080, 0, 0, 0, 0, 1048901, NULL, NULL },
    { 705, 1200, 0, 0, 0, 0, 1048896, EventCharaFadeOut, NULL },
    { 705, 2000, 0, 0, 0, 0, 98370, NULL, NULL },
};

static const EventCharaKeyframe sEvent188Track2[3] = {
    { 928, 529, 0, 0, 0, 0, 8194, NULL, NULL },
    { 928, 660, 54528, 86784, 0, 0, 16642, NULL, NULL },
    { 928, 2000, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaTrack sEvent188Tracks[3] = {
    { sEvent188Track0, EVENT_CHARA_RIKU },
    { sEvent188Track1, EVENT_CHARA_RIKU_REPLICA },
    { sEvent188Track2, EVENT_CHARA_B_STATES_4 },
};

const EventSequenceDef gEvent188 = {
    ARRAY_COUNT(sEvent188Tracks),
    sEvent188Tracks,
    sEvent188Camera,
    sEvent188Script,
    sEvent188SoundCues,
    NULL,
    1200,
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
