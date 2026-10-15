#ifdef VERSION_US
#include "event_052_text.inc"
#endif

static const MessageScriptEntry sEvent052Script[2] = {
    { PORTRAIT_JIMINY_CRICKET, 4, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent052Text00), 0, 200 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent052Text01), MSG_SCRIPT_FLAG_END, 265 },
};

#ifdef VERSION_JP
#include "event_052_text.inc"
#endif

static const EventCameraKeyframe sEvent052Camera[1] = {
    { -64536, 192512, 60672, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent052SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent052Track0[14] = {
    { 4, 1, 156160, 83968, 0, 0, 66, NULL, NULL },
    { 14, 110, 195072, 65536, 0, 4, 67, NULL, NULL },
    { 4, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 215, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 220, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 225, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 260, 0, 0, 0, 0, 5, NULL, NULL },
    { 31, 267, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 300, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 305, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 310, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 315, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 350, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 3000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent052Track1[9] = {
    { 229, 75, 0, 0, 0, 0, 8194, NULL, NULL },
    { 229, 76, 185856, 68096, 0, 0, 16402, NULL, NULL },
    { 233, 103, 0, 0, 0, 173, 4, EventCharaHop, NULL },
    { 229, 106, 0, 0, 0, 173, 4, NULL, NULL },
    { 229, 120, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 130, 0, 0, 0, 0, 69, NULL, NULL },
    { 231, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 234, 190, 0, 0, 0, 0, 64, EventCharaHop, NULL },
    { 231, 3000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent052Tracks[2] = {
    { sEvent052Track0, EVENT_CHARA_SORA },
    { sEvent052Track1, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent052 = {
    ARRAY_COUNT(sEvent052Tracks),
    sEvent052Tracks,
    sEvent052Camera,
    sEvent052Script,
    sEvent052SoundCues,
    NULL,
    320,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_053_12F_DESTINY_ISLAND_E0,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
