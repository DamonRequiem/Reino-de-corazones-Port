#ifdef VERSION_US
#include "event_120_text.inc"
#endif

static const MessageScriptEntry sEvent120Script[24] = {
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text00), 0, 240 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text01), 0, 425 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text02), 0, 485 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text03), 0, 487 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text04), 0, 489 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text05), 0, 540 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text06), 0, 560 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text07), 0, 580 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text08), 0, 610 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text09), 0, 790 },
    { PORTRAIT_DONALD, 3, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text10), 0, 810 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text11), 0, 875 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text12), 0, 930 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text13), 0, 990 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text14), 0, 1020 },
    { PORTRAIT_HADES, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text15), 0, 1730 },
    { PORTRAIT_HADES, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text16), 0, 1976 },
    { PORTRAIT_HADES, 3, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text17), 0, 1978 },
    { PORTRAIT_CLOUD, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text18), MSG_SCRIPT_FLAG_SILHOUETTE, 1985 },
    { PORTRAIT_HADES, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text19), 0, 2025 },
    { PORTRAIT_HADES, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text20), 0, 2175 },
    { PORTRAIT_HADES, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text21), 0, 2177 },
    { PORTRAIT_CLOUD, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text22), 0, 2207 },
    { PORTRAIT_HADES, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent120Text23), MSG_SCRIPT_FLAG_END, 2237 },
};

#ifdef VERSION_JP
#include "event_120_text.inc"
#endif

static const EvSoundCue sEvent120SoundCues[5] = {
    { SONG_BGM_HERCULES_FIELD, 0, 0, 0 },
    { SONG_BGM_HERCULES_FIELD, 1300, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_EVENT_UNREST, 1500, EV_SOUND_FLAG_FADE_IN, 0 },
    { SONG_BTL_HA_IKARI, 1945, 0, 0 },
    { SONG_BGM_EVENT_UNREST, 2450, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent120Camera[3] = {
    { -65536, 31232, 30976, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -65276, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 80, NULL },
    { -55537, 31232, 21760, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 80, NULL },
};

static const EventCharaKeyframe sEvent120Track0[24] = {
    { 4, 1, 12288, 50176, 0, 0, 66, NULL, NULL },
    { 9, 160, 57088, 25600, 0, 4, 67, NULL, NULL },
    { 4, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 0, 185, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 190, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 195, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 260, 0, 0, 0, 0, 5, NULL, NULL },
    { 12, 320, 34304, 32512, 0, 2, 35, NULL, NULL },
    { 3, 325, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 510, 0, 0, 0, 0, 5, NULL, NULL },
    { 34, 590, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 612, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 615, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 640, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 770, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 2, 880, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 885, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1015, 0, 0, 0, 0, 5, NULL, NULL },
    { 30, 1022, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1090, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 1095, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1100, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 1400, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 9999, 77056, 11264, 0, 0, 98370, NULL, NULL },
};

static const EventCharaKeyframe sEvent120Track1[26] = {
    { 114, 1, 21504, 51200, 0, 0, 66, NULL, NULL },
    { 119, 80, 38400, 41728, 0, 114, 67, NULL, NULL },
    { 114, 100, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 105, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 110, 0, 0, 0, 0, 5, NULL, NULL },
    { 119, 150, 31232, 37632, 0, 114, 3, NULL, NULL },
    { 114, 170, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 210, 0, 0, 0, 0, 0, NULL, CreateQuestionTask },
    { 114, 235, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 242, 0, 0, 0, 0, 5, NULL, NULL },
    { 119, 280, 0, 0, 0, 211, 4, NULL, NULL },
    { 114, 550, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 555, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 590, 0, 0, 0, 0, 69, NULL, NULL },
    { 127, 605, 0, 0, 0, 0, 69, NULL, NULL },
    { 128, 792, 0, 0, 0, 0, 69, NULL, NULL },
    { 129, 803, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 808, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 812, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 890, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 895, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1035, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 1040, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1150, 0, 0, 0, 0, 69, NULL, NULL },
    { 120, 1405, 0, 0, 0, 45, 100, NULL, NULL },
    { 114, 9999, 77824, 12800, 0, 0, 98370, NULL, NULL },
};

static const EventCharaKeyframe sEvent120Track2[21] = {
    { 146, 1, 3840, 49408, 0, 0, 66, NULL, NULL },
    { 151, 160, 48640, 24832, 0, 146, 67, NULL, NULL },
    { 146, 185, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 190, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 195, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 200, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 270, 0, 0, 0, 0, 5, NULL, NULL },
    { 152, 330, 36608, 26368, 0, 144, 35, NULL, NULL },
    { 144, 340, 0, 0, 0, 0, 5, NULL, NULL },
    { 145, 550, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 572, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 582, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 885, 0, 0, 0, 0, 5, NULL, NULL },
    { 145, 1050, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1060, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 1070, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1080, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 1090, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 1135, 0, 0, 0, 0, 69, NULL, NULL },
    { 153, 1410, 0, 0, 0, 45, 100, NULL, NULL },
    { 146, 9999, 79360, 10240, 0, 0, 98370, NULL, NULL },
};

static const EventCharaKeyframe sEvent120Track3[20] = {
    { 231, 360, 0, 0, 0, 0, 2, NULL, NULL },
    { 231, 362, 33792, 31232, 0, 0, 2, NULL, NULL },
    { 234, 390, 0, 0, 0, 211, 4, EventCharaHop, NULL },
    { 232, 410, 0, 0, 0, 211, 4, NULL, NULL },
    { 231, 420, 0, 0, 0, 0, 5, NULL, NULL },
    { 234, 460, 0, 0, 0, 0, 0, EventCharaHop, NULL },
    { 231, 500, 0, 0, 0, 0, 5, NULL, NULL },
    { 231, 510, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 820, 0, 0, 0, 0, 69, NULL, NULL },
    { 231, 830, 0, 0, 0, 0, 69, NULL, NULL },
    { 231, 840, 0, 0, 0, 0, 5, NULL, NULL },
    { 234, 870, 0, 0, 0, 0, 0, EventCharaHop, NULL },
    { 231, 890, 0, 0, 0, 0, 5, NULL, NULL },
    { 231, 900, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 950, 0, 0, 0, 0, 69, NULL, NULL },
    { 231, 1025, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 1030, 0, 0, 0, 0, 69, NULL, NULL },
    { 230, 1050, 0, 0, 0, 83, 68, NULL, NULL },
    { 233, 1080, 0, 0, 0, 83, 68, EventCharaHop, NULL },
    { 229, 9999, 0, 0, 0, 0, 98370, NULL, NULL },
};

static const EventCharaKeyframe sEvent120Track4[6] = {
    { 348, 2044, 66560, 43264, 0, 0, 8194, NULL, NULL },
    { 348, 2045, 66560, 43264, 0, 0, 16386, NULL, NULL },
    { 349, 2145, 0, 0, 0, 211, 4, NULL, NULL },
    { 348, 2295, 0, 0, 0, 0, 5, NULL, NULL },
    { 348, 2315, 0, 0, 0, 0, 69, NULL, NULL },
    { 349, 9999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent120Track5[13] = {
    { 396, 1499, 68096, 49408, 0, 0, 8194, NULL, NULL },
    { 396, 1500, 68096, 49408, 0, 0, 16386, NULL, NULL },
    { 398, 1700, 24832, 26112, 0, 396, 3, NULL, NULL },
    { 396, 1725, 0, 0, 0, 0, 5, NULL, NULL },
    { 395, 1760, 0, 0, 0, 0, 5, NULL, NULL },
    { 395, 1890, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 395, 1910, 0, 0, 0, 0, 5, NULL, NULL },
    { 401, 1945, 0, 0, 0, 0, 5, NULL, NULL },
    { 401, 1990, 256000, 0, 0, 0, 2, NULL, NULL },
    { 403, 1995, 24832, 26112, 0, 0, 2, NULL, NULL },
    { 395, 2005, 0, 0, 0, 0, 5, NULL, NULL },
    { 395, 2425, 0, 0, 0, 0, 69, NULL, NULL },
    { 396, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent120Track6[4] = {
    { 395, 1910, 256000, 0, 0, 0, 8194, NULL, NULL },
    { 401, 1945, 24832, 26112, 0, 0, 16386, NULL, NULL },
    { 402, 1990, 0, 0, 0, 0, 5, NULL, NULL },
    { 395, 9999, 256000, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaKeyframe sEvent120Track7[3] = {
    { 404, 1910, 256000, 0, 0, 0, 8194, NULL, NULL },
    { 404, 1974, 24832, 26112, 0, 0, 16386, NULL, NULL },
    { 404, 9999, 256000, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaTrack sEvent120Tracks[8] = {
    { sEvent120Track0, EVENT_CHARA_SORA },
    { sEvent120Track1, EVENT_CHARA_DONALD },
    { sEvent120Track2, EVENT_CHARA_GOOFY },
    { sEvent120Track3, EVENT_CHARA_JIMINY_CRICKET },
    { sEvent120Track4, EVENT_CHARA_CLOUD },
    { sEvent120Track5, EVENT_CHARA_HADES },
    { sEvent120Track6, EVENT_CHARA_HADES_ANGRY },
    { sEvent120Track7, EVENT_CHARA_HADES_ANGRY_2 },
};

const EventSequenceDef gEvent120 = {
    ARRAY_COUNT(sEvent120Tracks),
    sEvent120Tracks,
    sEvent120Camera,
    sEvent120Script,
    sEvent120SoundCues,
    NULL,
    2455,
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
