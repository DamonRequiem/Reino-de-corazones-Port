#ifdef VERSION_US
#include "event_170_text.inc"
#endif

static const MessageScriptEntry sEvent170Script[2] = {
    { PORTRAIT_RIKU, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent170Text00), 0, 250 },
    { PORTRAIT_RIKU, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent170Text01), MSG_SCRIPT_FLAG_END, 350 },
};

#ifdef VERSION_JP
#include "event_170_text.inc"
#endif

static const EvSoundCue sEvent170SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent170Camera[1] = {
    { -64537, 190976, 59648, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent170Track0[5] = {
    { 515, 1, 156416, 83968, 0, 0, 66, NULL, NULL },
    { 518, 140, 187136, 67840, 0, 515, 67, NULL, NULL },
    { 515, 170, 0, 0, 0, 0, 69, NULL, NULL },
    { 557, 1000, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 3000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent170Track1[3] = {
    { 603, 203, 0, 0, 0, 0, 66, NULL, NULL },
    { 603, 1000, 187136, 67840, 0, 0, 338, NULL, NULL },
    { 603, 3000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent170Tracks[2] = {
    { sEvent170Track0, EVENT_CHARA_RIKU },
    { sEvent170Track1, EVENT_CHARA_B_STATES_1 },
};

const EventSequenceDef gEvent170 = {
    ARRAY_COUNT(sEvent170Tracks),
    sEvent170Tracks,
    sEvent170Camera,
    sEvent170Script,
    sEvent170SoundCues,
    NULL,
    410,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
