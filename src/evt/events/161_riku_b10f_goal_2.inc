#ifdef VERSION_US
#include "event_161_text.inc"
#endif

static const MessageScriptEntry sEvent161Script[5] = {
    { PORTRAIT_VEXEN, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent161Text00), 0, 100 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent161Text01), 0, 102 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent161Text02), 0, 200 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent161Text03), 0, 230 },
    { PORTRAIT_VEXEN, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent161Text04), MSG_SCRIPT_FLAG_END, 232 },
};

#ifdef VERSION_JP
#include "event_161_text.inc"
#endif

static const EvSoundCue sEvent161SoundCues[2] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_EV_WARPIN, 260, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent161Camera[1] = {
    { -64537, 188160, 61184, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent161Track0[4] = {
    { 561, 120, 179200, 72448, 0, 0, 66, NULL, NULL },
    { 561, 170, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 562, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 563, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent161Track1[4] = {
    { 721, 260, 198144, 64000, 0, 0, 2, NULL, NULL },
    { 721, 300, 198144, 64000, 0, 0, 2, EventCharaFadeOut, NULL },
    { 721, 500, 0, 0, 0, 0, 2, NULL, NULL },
    { 721, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent161Tracks[2] = {
    { sEvent161Track0, EVENT_CHARA_RIKU },
    { sEvent161Track1, EVENT_CHARA_VEXEN },
};

const EventSequenceDef gEvent161 = {
    ARRAY_COUNT(sEvent161Tracks),
    sEvent161Tracks,
    sEvent161Camera,
    sEvent161Script,
    sEvent161SoundCues,
    NULL,
    340,
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
