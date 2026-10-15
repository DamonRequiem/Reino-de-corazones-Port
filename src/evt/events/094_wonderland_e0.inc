#ifdef VERSION_US
#include "event_094_text.inc"
#endif

static const MessageScriptEntry sEvent094Script[7] = {
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent094Text00), 0, 190 },
    { PORTRAIT_WHITE_RABBIT, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent094Text01), 0, 400 },
    { PORTRAIT_WHITE_RABBIT, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent094Text02), 0, 450 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent094Text03), 0, 500 },
    { PORTRAIT_WHITE_RABBIT, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent094Text04), 0, 540 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent094Text05), 0, 750 },
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent094Text06), MSG_SCRIPT_FLAG_END, 770 },
};

#ifdef VERSION_JP
#include "event_094_text.inc"
#endif

static const EventCameraKeyframe sEvent094Camera[2] = {
    { -65536, 69120, 81408, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -64537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 80, NULL },
};

static const EvSoundCue sEvent094SoundCues[2] = {
    { SONG_BGM_ALICE_FIELD, 0, 0, 0 },
    { SONG_BGM_ALICE_FIELD, 925, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent094Track0[17] = {
    { 4, 0, 34048, 100096, 0, 0, 66, NULL, NULL },
    { 9, 150, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 401, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 451, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 4, 453, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 499, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 30, 541, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 620, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 720, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 730, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 800, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 805, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 810, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 815, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 840, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent094Track1[12] = {
    { 114, 0, 31488, 106496, 0, 0, 66, NULL, NULL },
    { 119, 150, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 401, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 451, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 114, 610, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 630, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 730, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 740, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 769, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 771, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 850, 0, 0, 0, 0, 69, NULL, NULL },
    { 119, 999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent094Track2[14] = {
    { 146, 0, 23808, 100096, 0, 0, 66, NULL, NULL },
    { 151, 150, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 189, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 165, 191, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 401, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 451, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 146, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 630, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 720, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 770, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 840, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 850, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 860, 0, 0, 0, 0, 69, NULL, NULL },
    { 151, 999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent094Track3[20] = {
    { 264, 200, 106240, 63232, 0, 0, 2, NULL, NULL },
    { 266, 290, 0, 0, 0, 173, 36, NULL, NULL },
    { 264, 293, 0, 0, 0, 173, 4, NULL, NULL },
    { 264, 320, 0, 0, 0, 0, 5, NULL, NULL },
    { 269, 340, 0, 0, 0, 0, 5, NULL, NULL },
    { 264, 360, 0, 0, 0, 0, 0, EventCharaHopLow, NULL },
    { 268, 365, 0, 0, 0, 0, 5, NULL, NULL },
    { 268, 375, 0, 0, 0, 0, 69, NULL, NULL },
    { 268, 385, 0, 0, 0, 0, 5, NULL, NULL },
    { 268, 395, 0, 0, 0, 0, 69, NULL, NULL },
    { 268, 405, 0, 0, 0, 0, 5, NULL, NULL },
    { 268, 415, 0, 0, 0, 0, 5, NULL, NULL },
    { 268, 425, 0, 0, 0, 0, 69, NULL, NULL },
    { 268, 435, 0, 0, 0, 0, 5, NULL, NULL },
    { 268, 445, 0, 0, 0, 0, 5, NULL, NULL },
    { 268, 455, 0, 0, 0, 0, 5, NULL, NULL },
    { 268, 550, 0, 0, 0, 0, 5, NULL, NULL },
    { 268, 580, 0, 0, 0, 0, 69, NULL, NULL },
    { 266, 740, 0, 0, 0, 83, 100, NULL, NULL },
    { 264, 999, 0, 0, 0, 0, 98373, NULL, NULL },
};

static const EventCharaTrack sEvent094Tracks[4] = {
    { sEvent094Track0, EVENT_CHARA_SORA },
    { sEvent094Track1, EVENT_CHARA_DONALD },
    { sEvent094Track2, EVENT_CHARA_GOOFY },
    { sEvent094Track3, EVENT_CHARA_WHITE_RABBIT },
};

const EventSequenceDef gEvent094 = {
    ARRAY_COUNT(sEvent094Tracks),
    sEvent094Tracks,
    sEvent094Camera,
    sEvent094Script,
    sEvent094SoundCues,
    NULL,
    930,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    1,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
