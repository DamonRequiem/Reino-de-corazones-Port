#ifdef VERSION_US
#include "event_041_text.inc"
#endif

static const MessageScriptEntry sEvent041Script[9] = {
    { PORTRAIT_VEXEN, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent041Text00), 0, 100 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent041Text01), 0, 130 },
    { PORTRAIT_VEXEN, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent041Text02), 0, 160 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent041Text03), 0, 162 },
    { PORTRAIT_VEXEN, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent041Text04), 0, 260 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent041Text05), 0, 310 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent041Text06), 0, 312 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent041Text07), 0, 395 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent041Text08), MSG_SCRIPT_FLAG_END, 690 },
};

#ifdef VERSION_JP
#include "event_041_text.inc"
#endif

static const EventCameraKeyframe sEvent041Camera[2] = {
    { -65091, 187904, 61440, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -60536, 182272, 66560, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 50, NULL },
};

static const EvSoundCue sEvent041SoundCues[3] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_EV_CARDTHR, 355, 0, 0 },
    { SONG_EV_WARPIN, 370, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent041Track0[14] = {
    { 21, 180, 182272, 70400, 0, 0, 66, NULL, NULL },
    { 21, 230, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 21, 320, 0, 0, 0, 0, 69, NULL, NULL },
    { 22, 333, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 72, 390, 0, 0, 0, 0, 69, NULL, NULL },
    { 76, 410, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 415, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 445, 194304, 63488, 0, 4, 67, NULL, NULL },
    { 4, 485, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 615, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 4, 640, 0, 0, 0, 0, 69, NULL, NULL },
    { 75, 3000, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent041Track1[3] = {
    { 158, 400, 167936, 71168, 0, 0, 66, NULL, NULL },
    { 159, 413, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent041Track2[3] = {
    { 123, 405, 180992, 78336, 0, 0, 66, NULL, NULL },
    { 124, 418, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent041Track3[6] = {
    { 721, 280, 201472, 61440, 0, 0, 2, NULL, NULL },
    { 722, 318, 0, 0, 0, 0, 5, NULL, NULL },
    { 724, 370, 0, 0, 0, 0, 5, NULL, NULL },
    { 725, 400, 0, 0, 0, 0, 0, EventCharaFadeOut, NULL },
    { 721, 500, 0, 0, 0, 0, 2, NULL, NULL },
    { 721, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent041Track4[9] = {
    { 591, 271, 0, 0, 0, 0, 322, NULL, NULL },
    { 609, 318, 201472, 61440, 0, 0, 274, NULL, NULL },
    { 591, 354, 0, 0, 0, 0, 322, NULL, NULL },
    { 591, 355, 193280, 55296, 0, 0, 338, NULL, NULL },
    { 591, 366, 187904, 59136, 0, 591, 339, NULL, NULL },
    { 599, 390, 182272, 70400, 0, 0, 338, NULL, NULL },
    { 591, 640, 0, 0, 0, 0, 322, NULL, NULL },
    { 601, 1500, 194304, 63488, 0, 0, 338, NULL, NULL },
    { 591, 5000, 0, 0, 0, 0, 33093, NULL, NULL },
};

static const EventCharaTrack sEvent041Tracks[5] = {
    { sEvent041Track0, EVENT_CHARA_SORA },
    { sEvent041Track1, EVENT_CHARA_GOOFY },
    { sEvent041Track2, EVENT_CHARA_DONALD },
    { sEvent041Track3, EVENT_CHARA_VEXEN },
    { sEvent041Track4, EVENT_CHARA_B_STATES_1 },
};

const EventSequenceDef gEvent041 = {
    ARRAY_COUNT(sEvent041Tracks),
    sEvent041Tracks,
    sEvent041Camera,
    sEvent041Script,
    sEvent041SoundCues,
    NULL,
    750,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_042_10F_DEMO,
    0,
    { 0, 8 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
