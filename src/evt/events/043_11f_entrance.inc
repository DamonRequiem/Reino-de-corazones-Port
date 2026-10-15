#ifdef VERSION_US
#include "event_043_text.inc"
#endif

static const MessageScriptEntry sEvent043Script[2] = {
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent043Text00), 0, 210 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent043Text01), MSG_SCRIPT_FLAG_END, 250 },
};

#ifdef VERSION_JP
#include "event_043_text.inc"
#endif

static const EventCameraKeyframe sEvent043Camera[1] = {
    { -65485, 165120, 75776, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent043SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent043Track0[7] = {
    { 4, 1, 136704, 95488, 0, 0, 66, NULL, NULL },
    { 9, 110, 163584, 82176, 0, 4, 67, NULL, NULL },
    { 4, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 74, 252, 0, 0, 0, 0, 69, NULL, NULL },
    { 76, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 310, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent043Track1[4] = {
    { 114, 1, 137984, 103680, 0, 0, 66, NULL, NULL },
    { 119, 110, 160512, 90624, 0, 114, 67, NULL, NULL },
    { 114, 315, 0, 0, 0, 0, 69, NULL, NULL },
    { 119, 999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent043Track2[4] = {
    { 146, 1, 125440, 95744, 0, 0, 66, NULL, NULL },
    { 151, 110, 150784, 80384, 0, 146, 67, NULL, NULL },
    { 146, 320, 0, 0, 0, 0, 69, NULL, NULL },
    { 151, 999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent043Track3[8] = {
    { 231, 120, 0, 0, 0, 0, 66, NULL, NULL },
    { 231, 121, 163584, 82176, 0, 0, 66, NULL, NULL },
    { 234, 150, 0, 0, 0, 45, 68, EventCharaHop, NULL },
    { 231, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 170, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 270, 0, 0, 0, 0, 5, NULL, NULL },
    { 233, 300, 0, 0, 0, 173, 4, EventCharaHop, NULL },
    { 229, 310, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaKeyframe sEvent043Track4[3] = {
    { 591, 206, 0, 0, 0, 0, 8258, NULL, NULL },
    { 601, 252, 163584, 82176, 0, 0, 16722, NULL, NULL },
    { 591, 500, 0, 0, 0, 0, 98370, NULL, NULL },
};

static const EventCharaTrack sEvent043Tracks[5] = {
    { sEvent043Track0, EVENT_CHARA_SORA },
    { sEvent043Track1, EVENT_CHARA_DONALD },
    { sEvent043Track2, EVENT_CHARA_GOOFY },
    { sEvent043Track3, EVENT_CHARA_JIMINY_CRICKET },
    { sEvent043Track4, EVENT_CHARA_B_STATES_1 },
};

const EventSequenceDef gEvent043 = {
    ARRAY_COUNT(sEvent043Tracks),
    sEvent043Tracks,
    sEvent043Camera,
    sEvent043Script,
    sEvent043SoundCues,
    NULL,
    400,
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
