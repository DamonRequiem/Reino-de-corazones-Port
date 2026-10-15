#ifdef VERSION_US
#include "event_027_text.inc"
#endif

static const MessageScriptEntry sEvent027Script[10] = {
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent027Text00), 0, 150 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent027Text01), 0, 170 },
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent027Text02), 0, 190 },
    { PORTRAIT_LARXENE, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent027Text03), 0, 250 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent027Text04), 0, 310 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent027Text05), 0, 440 },
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent027Text06), 0, 540 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent027Text07), 0, 560 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent027Text08), 0, 600 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent027Text09), MSG_SCRIPT_FLAG_END, 650 },
};

#ifdef VERSION_JP
#include "event_027_text.inc"
#endif

static const EventCameraKeyframe sEvent027Camera[3] = {
    { -65223, 196352, 58880, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65066, 206080, 53248, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 40, NULL },
    { -64537, 199936, 60928, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 30, NULL },
};

static const EvSoundCue sEvent027SoundCues[4] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_EV_CARDTHR, 241, 0, 0 },
    { SONG_EV_WARPIN, 260, 0, 0 },
    { SONG_BGM_EVENT_XIII, 315, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent027Track0[20] = {
    { 21, 210, 186624, 69888, 0, 0, 66, NULL, NULL },
    { 22, 220, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 245, 0, 0, 0, 0, 69, NULL, NULL },
    { 72, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 310, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 30, 312, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 350, 204800, 62208, 0, 4, 67, NULL, NULL },
    { 4, 353, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 0, 365, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 385, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 390, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 395, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 400, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 420, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 425, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 440, 0, 0, 0, 0, 5, NULL, NULL },
    { 31, 570, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 590, 0, 0, 0, 0, 5, NULL, NULL },
    { 15, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent027Track2[7] = {
    { 114, 450, 0, 0, 0, 0, 8258, NULL, NULL },
    { 114, 451, 175360, 84224, 0, 0, 16450, NULL, NULL },
    { 120, 525, 204544, 69120, 0, 114, 67, NULL, NULL },
    { 114, 527, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 535, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 540, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent027Track4[9] = {
    { 146, 450, 0, 0, 0, 0, 8258, NULL, NULL },
    { 146, 451, 169216, 72960, 0, 0, 16450, NULL, NULL },
    { 153, 520, 191488, 61440, 0, 146, 67, NULL, NULL },
    { 146, 522, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 530, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 535, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 559, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 561, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent027Track3[8] = {
    { 229, 470, 0, 0, 0, 0, 8194, NULL, NULL },
    { 229, 471, 204800, 62208, 0, 0, 16386, NULL, NULL },
    { 233, 500, 0, 0, 0, 173, 4, EventCharaHop, NULL },
    { 229, 510, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 520, 0, 0, 0, 0, 69, NULL, NULL },
    { 231, 540, 0, 0, 0, 0, 69, NULL, NULL },
    { 234, 542, 0, 0, 0, 0, 64, EventCharaHop, NULL },
    { 231, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent027Track1[4] = {
    { 856, 192, 204800, 62208, 0, 0, 2, NULL, NULL },
    { 865, 260, 0, 0, 0, 0, 5, NULL, NULL },
    { 856, 280, 0, 0, 0, 0, 0, EventCharaFadeOut, NULL },
    { 856, 300, 0, 0, 0, 0, 32770, NULL, NULL },
};

static const EventCharaKeyframe sEvent027Track5[5] = {
    { 591, 240, 0, 0, 0, 0, 2, NULL, NULL },
    { 591, 241, 201472, 62208, -5120, 0, 258, NULL, NULL },
    { 591, 250, 189952, 67328, -5120, 591, 259, NULL, NULL },
    { 599, 260, 186624, 69888, 0, 0, 338, NULL, NULL },
    { 591, 290, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaTrack sEvent027Tracks[6] = {
    { sEvent027Track0, EVENT_CHARA_SORA },
    { sEvent027Track1, EVENT_CHARA_LARXENE },
    { sEvent027Track2, EVENT_CHARA_DONALD },
    { sEvent027Track3, EVENT_CHARA_JIMINY_CRICKET },
    { sEvent027Track4, EVENT_CHARA_GOOFY },
    { sEvent027Track5, EVENT_CHARA_B_STATES_1 },
};

const EventSequenceDef gEvent027 = {
    ARRAY_COUNT(sEvent027Tracks),
    sEvent027Tracks,
    sEvent027Camera,
    sEvent027Script,
    sEvent027SoundCues,
    NULL,
    720,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_NONE,
    0,
    { 194, 4 },
    EVENT_EXIT_MAP_6F,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
