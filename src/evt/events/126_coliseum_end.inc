#ifdef VERSION_US
#include "event_126_text.inc"
#endif

static const MessageScriptEntry sEvent126Script[21] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text00), 0, 150 },
    { PORTRAIT_PHILOCTETES, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text01), 0, 180 },
    { PORTRAIT_PHILOCTETES, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text02), 0, 182 },
    { PORTRAIT_GOOFY, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text03), 0, 210 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text04), 0, 240 },
    { PORTRAIT_HERCULES, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text05), 0, 300 },
    { PORTRAIT_HERCULES, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text06), 0, 302 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text07), 0, 490 },
    { PORTRAIT_HERCULES, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text08), 0, 520 },
    { PORTRAIT_JIMINY_CRICKET, 3, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text09), 0, 600 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text10), 0, 730 },
    { PORTRAIT_CLOUD, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text11), 0, 750 },
    { PORTRAIT_CLOUD, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text12), 0, 810 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text13), 0, 881 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text14), 0, 920 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text15), 0, 922 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text16), 0, 1030 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text17), 0, 1032 },
    { PORTRAIT_CLOUD, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text18), 0, 1360 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text19), 0, 1401 },
    { PORTRAIT_CLOUD, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent126Text20), MSG_SCRIPT_FLAG_END, 1480 },
};

#ifdef VERSION_JP
#include "event_126_text.inc"
#endif

static const EvSoundCue sEvent126SoundCues[3] = {
    { SONG_BGM_HERCULES_FIELD, 0, 0, 0 },
    { SONG_BGM_HERCULES_FIELD, 881, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_EV_CARDTHR, 1274, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent126Camera[3] = {
    { -64916, 43264, 67072, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64686, 72192, 48384, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 100, NULL },
    { -55537, 81152, 43520, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 50, NULL },
};

static const EventCharaKeyframe sEvent126Track0[18] = {
    { 4, 145, 44800, 77568, 0, 0, 2, NULL, NULL },
    { 27, 181, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 235, 0, 0, 0, 0, 5, NULL, NULL },
    { 30, 301, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 315, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 445, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 4, 465, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 470, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 640, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 700, 69632, 60928, 0, 4, 99, NULL, NULL },
    { 4, 876, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 921, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 950, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 1031, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1285, 0, 0, 0, 0, 69, NULL, NULL },
    { 72, 1340, 0, 0, 0, 0, 69, NULL, NULL },
    { 76, 1397, 0, 0, 0, 0, 69, NULL, NULL },
    { 36, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent126Track1[3] = {
    { 114, 650, 30464, 76288, 0, 0, 66, NULL, NULL },
    { 120, 720, 67072, 66560, 0, 114, 99, NULL, NULL },
    { 114, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent126Track2[9] = {
    { 144, 205, 46336, 65536, 0, 0, 2, NULL, NULL },
    { 164, 212, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 650, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 655, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 660, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 665, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 685, 0, 0, 0, 0, 69, NULL, NULL },
    { 153, 715, 56832, 65792, 0, 146, 99, NULL, NULL },
    { 146, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent126Track3[6] = {
    { 381, 175, 37376, 70912, 0, 0, 66, NULL, NULL },
    { 385, 185, 0, 0, 0, 0, 69, NULL, NULL },
    { 381, 680, 0, 0, 0, 0, 69, NULL, NULL },
    { 382, 685, 0, 0, 0, 0, 69, NULL, NULL },
    { 384, 725, 56320, 55040, 0, 382, 67, NULL, NULL },
    { 381, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent126Track4[5] = {
    { 229, 605, 76288, 54528, 0, 0, 2, NULL, NULL },
    { 233, 725, 0, 0, 0, 0, 0, EventCharaHop, NULL },
    { 229, 770, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 780, 0, 0, 0, 0, 69, NULL, NULL },
    { 231, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent126Track5[16] = {
    { 346, 780, 83968, 54016, 0, 0, 2, NULL, NULL },
    { 347, 800, 0, 0, 0, 0, 5, NULL, NULL },
    { 344, 830, 0, 0, 0, 0, 5, NULL, NULL },
    { 348, 840, 0, 0, 0, 0, 5, NULL, NULL },
    { 348, 850, 0, 0, 0, 0, 69, NULL, NULL },
    { 349, 880, 0, 0, 0, 45, 68, NULL, NULL },
    { 348, 1060, 0, 0, 0, 0, 69, NULL, NULL },
    { 348, 1190, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 348, 1260, 0, 0, 0, 0, 69, NULL, NULL },
    { 350, 1310, 0, 0, 0, 0, 69, NULL, NULL },
    { 348, 1370, 0, 0, 0, 0, 69, NULL, NULL },
    { 349, 1400, 0, 0, 0, 45, 68, NULL, NULL },
    { 348, 1425, 0, 0, 0, 0, 69, NULL, NULL },
    { 351, 1460, 0, 0, 0, 0, 69, NULL, NULL },
    { 348, 1500, 0, 0, 0, 0, 69, NULL, NULL },
    { 349, 5000, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent126Track6[6] = {
    { 388, 260, 52480, 70912, 0, 0, 2, NULL, NULL },
    { 387, 630, 0, 0, 0, 0, 5, NULL, NULL },
    { 387, 635, 0, 0, 0, 0, 69, NULL, NULL },
    { 388, 640, 0, 0, 0, 0, 69, NULL, NULL },
    { 391, 710, 67584, 49408, 0, 388, 99, NULL, NULL },
    { 387, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent126Track7[6] = {
    { 593, 1273, 0, 0, 0, 0, 8194, NULL, NULL },
    { 593, 1274, 83712, 44800, 0, 0, 16658, NULL, NULL },
    { 593, 1288, 74496, 51712, 0, 593, 275, NULL, NULL },
    { 593, 1291, 0, 0, 0, 0, 274, NULL, NULL },
    { 600, 1340, 69632, 60928, 0, 0, 338, NULL, NULL },
    { 593, 5000, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaTrack sEvent126Tracks[8] = {
    { sEvent126Track0, EVENT_CHARA_SORA },
    { sEvent126Track1, EVENT_CHARA_DONALD },
    { sEvent126Track2, EVENT_CHARA_GOOFY },
    { sEvent126Track3, EVENT_CHARA_PHILOCTETES },
    { sEvent126Track4, EVENT_CHARA_JIMINY_CRICKET },
    { sEvent126Track5, EVENT_CHARA_CLOUD },
    { sEvent126Track6, EVENT_CHARA_HERCULES },
    { sEvent126Track7, EVENT_CHARA_B_STATES_2 },
};

const EventSequenceDef gEvent126 = {
    ARRAY_COUNT(sEvent126Tracks),
    sEvent126Tracks,
    sEvent126Camera,
    sEvent126Script,
    sEvent126SoundCues,
    NULL,
    1500,
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
