#ifdef VERSION_US
#include "event_192_text.inc"
#endif

static const MessageScriptEntry sEvent192Script[3] = {
    { PORTRAIT_RIKU, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent192Text00), 0, 150 },
    { PORTRAIT_ANSEM, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent192Text01), 0, 250 },
    { PORTRAIT_ANSEM, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent192Text02), MSG_SCRIPT_FLAG_END, 300 },
};

#ifdef VERSION_JP
#include "event_192_text.inc"
#endif

static const EvSoundCue sEvent192SoundCues[3] = {
    { SONG_BGM_F13F_FORGET, 0, 0, 0 },
    { SONG_SND_359, 110, 0, 0 },
    { SONG_BGM_F13F_FORGET, 475, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent192Camera[2] = {
    { -65536, 35072, 32512, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -64537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 80, NULL },
};

static const EventCharaKeyframe sEvent192Track0[9] = {
    { 515, 1, 67328, 56576, 0, 0, 2, NULL, NULL },
    { 522, 100, 0, 0, 0, 211, 36, NULL, NULL },
    { 515, 103, 0, 0, 0, 211, 4, NULL, NULL },
    { 515, 110, 0, 0, 0, 0, 5, NULL, NULL },
    { 560, 350, 0, 0, 0, 0, 5, NULL, NULL },
    { 562, 360, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 390, 0, 0, 0, 0, 5, NULL, NULL },
    { 522, 1000, 0, 0, 0, 211, 36, NULL, NULL },
    { 515, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent192Tracks[1] = {
    { sEvent192Track0, EVENT_CHARA_RIKU },
};

const EventSequenceDef gEvent192 = {
    ARRAY_COUNT(sEvent192Tracks),
    sEvent192Tracks,
    sEvent192Camera,
    sEvent192Script,
    sEvent192SoundCues,
    NULL,
    480,
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
