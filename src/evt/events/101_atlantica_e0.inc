#ifdef VERSION_US
#include "event_101_text.inc"
#endif

static const MessageScriptEntry sEvent101Script[12] = {
    { PORTRAIT_GOOFY, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text00), 0, 300 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text01), 0, 340 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text02), 0, 360 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text03), 0, 380 },
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text04), 0, 400 },
    { PORTRAIT_ARIEL, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text05), 0, 630 },
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text06), 0, 650 },
    { PORTRAIT_ARIEL, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text07), 0, 670 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text08), 0, 850 },
    { PORTRAIT_ARIEL, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text09), 0, 870 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text10), 0, 1130 },
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent101Text11), MSG_SCRIPT_FLAG_END, 1150 },
};

#ifdef VERSION_JP
#include "event_101_text.inc"
#endif

static const EventCameraKeyframe sEvent101Camera[8] = {
    { -65536, 73472, 58624, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -65134, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 80, NULL },
    { -64976, 56320, 44800, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 50, NULL },
    { -64936, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -64906, 65792, 54016, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 30, NULL },
    { -64591, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -60536, 73472, 58624, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 50, NULL },
    { -55537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent101SoundCues[3] = {
    { SONG_BGM_EVENT1, 0, 0, 0 },
    { SONG_SND_350, 680, 0, 0 },
    { SONG_BGM_EVENT1, 1245, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent101Track0[16] = {
    { 4, 310, 73472, 61184, 0, 0, 2, NULL, NULL },
    { 3, 315, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 320, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 325, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 330, 0, 0, 0, 0, 69, NULL, NULL },
    { 32, 401, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 410, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 415, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 420, 0, 0, 0, 0, 69, NULL, NULL },
    { 0, 425, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 430, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 950, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 960, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1110, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 1115, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent101Track1[11] = {
    { 114, 1, 81920, 61184, 0, 0, 2, NULL, NULL },
    { 114, 399, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 401, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 649, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 651, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 849, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 970, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 1110, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1149, 0, 0, 0, 0, 5, NULL, NULL },
    { 127, 1151, 0, 0, 0, 0, 5, NULL, NULL },
    { 128, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent101Track2[17] = {
    { 146, 150, 69376, 67328, 0, 0, 2, NULL, NULL },
    { 144, 180, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 220, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 250, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 299, 0, 0, 0, 0, 69, NULL, NULL },
    { 165, 301, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 359, 0, 0, 0, 0, 69, NULL, NULL },
    { 170, 401, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 415, 0, 0, 0, 0, 69, NULL, NULL },
    { 142, 420, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 425, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 849, 0, 0, 0, 0, 5, NULL, NULL },
    { 165, 851, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 930, 0, 0, 0, 0, 5, NULL, NULL },
    { 142, 950, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 1100, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent101Track3[18] = {
    { 314, 410, 4096, 27136, 0, 0, 66, NULL, NULL },
    { 319, 520, 0, 0, 0, 83, 100, NULL, NULL },
    { 315, 523, 0, 0, 0, 83, 100, NULL, NULL },
    { 314, 590, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 315, 594, 0, 0, 0, 0, 69, NULL, NULL },
    { 319, 620, 0, 0, 0, 83, 100, NULL, NULL },
    { 315, 623, 0, 0, 0, 83, 100, NULL, NULL },
    { 314, 629, 0, 0, 0, 0, 69, NULL, NULL },
    { 324, 631, 0, 0, 0, 0, 69, NULL, NULL },
    { 314, 720, 0, 0, 0, 0, 69, NULL, NULL },
    { 322, 770, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 315, 790, 0, 0, 0, 211, 100, NULL, NULL },
    { 316, 795, 0, 0, 0, 0, 69, NULL, NULL },
    { 316, 880, 0, 0, 0, 0, 5, NULL, NULL },
    { 316, 890, 0, 0, 0, 0, 69, NULL, NULL },
    { 317, 895, 0, 0, 0, 0, 69, NULL, NULL },
    { 321, 999, 0, 0, 0, 45, 100, NULL, NULL },
    { 316, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent101Track4[3] = {
    { 590, 680, 0, 0, 0, 0, 258, NULL, NULL },
    { 590, 720, 62208, 48128, 0, 0, 274, NULL, NULL },
    { 590, 999, 0, 0, 0, 0, 33026, NULL, NULL },
};

static const EventCharaTrack sEvent101Tracks[5] = {
    { sEvent101Track0, EVENT_CHARA_SORA },
    { sEvent101Track1, EVENT_CHARA_DONALD },
    { sEvent101Track2, EVENT_CHARA_GOOFY },
    { sEvent101Track3, EVENT_CHARA_ARIEL },
    { sEvent101Track4, EVENT_CHARA_B_STATES_0 },
};

const EventSequenceDef gEvent101 = {
    ARRAY_COUNT(sEvent101Tracks),
    sEvent101Tracks,
    sEvent101Camera,
    sEvent101Script,
    sEvent101SoundCues,
    NULL,
    1250,
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
