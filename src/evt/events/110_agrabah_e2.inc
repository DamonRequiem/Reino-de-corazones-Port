#ifdef VERSION_US
#include "event_110_text.inc"
#endif

static const MessageScriptEntry sEvent110Script[13] = {
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text00), 0, 100 },
    { PORTRAIT_ALADDIN, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text01), 0, 110 },
    { PORTRAIT_ALADDIN, 4, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text02), 0, 190 },
    { PORTRAIT_GOOFY, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text03), 0, 350 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text04), 0, 370 },
    { PORTRAIT_ALADDIN, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text05), 0, 380 },
    { PORTRAIT_GENIE, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text06), 0, 390 },
    { PORTRAIT_ALADDIN, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text07), 0, 900 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text08), 0, 920 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text09), 0, 940 },
    { PORTRAIT_ALADDIN, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text10), 0, 1120 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text11), 0, 1140 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent110Text12), MSG_SCRIPT_FLAG_END, 1200 },
};

#ifdef VERSION_JP
#include "event_110_text.inc"
#endif

static const EventCameraKeyframe sEvent110Camera[6] = {
    { -65406, 32256, 29696, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65276, 77824, 90368, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 40, NULL },
    { -65056, 32256, 29696, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 40, NULL },
    { -64816, 70912, 89600, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 40, NULL },
    { -64536, 69632, 92672, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 60, NULL },
    { -62536, 77312, 90112, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 30, NULL },
};

static const EvSoundCue sEvent110SoundCues[5] = {
    { SONG_BGM_ALADDIN_FIELD, 0, 0, 0 },
    { SONG_EV_DL_JUMP, 70, 0, 0 },
    { SONG_BGM_EVENT2, 190, 0, 0 },
    { SONG_BGM_EVENT2, 680, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_EVENT2, 1000, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent110Track0[16] = {
    { 2, 1, 28672, 30720, 0, 0, 66, NULL, NULL },
    { 7, 40, 0, 0, 0, 83, 68, NULL, NULL },
    { 2, 365, 0, 0, 0, 0, 69, NULL, NULL },
    { 31, 375, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 701, 45824, 124416, 0, 0, 66, NULL, NULL },
    { 14, 800, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 803, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 810, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 939, 0, 0, 0, 0, 5, NULL, NULL },
    { 34, 950, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1020, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1080, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 0, 1085, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1150, 0, 0, 0, 0, 69, NULL, NULL },
    { 19, 3000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent110Track1[12] = {
    { 112, 1, 12032, 39168, 0, 0, 66, NULL, NULL },
    { 117, 40, 0, 0, 0, 83, 68, NULL, NULL },
    { 112, 70, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 90, 0, 0, 0, 0, 64, EventCharaHopLow, CreateExclamationTask },
    { 112, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 701, 33024, 122112, 0, 0, 66, NULL, NULL },
    { 120, 790, 0, 0, 0, 45, 100, NULL, NULL },
    { 114, 793, 0, 0, 0, 45, 100, NULL, NULL },
    { 114, 1020, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1080, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 122, 1175, 0, 0, 0, 0, 69, NULL, NULL },
    { 123, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent110Track2[22] = {
    { 144, 1, 36864, 26624, 0, 0, 66, NULL, NULL },
    { 149, 40, 0, 0, 0, 83, 68, NULL, NULL },
    { 144, 330, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 335, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 349, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 351, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 400, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 405, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 701, 31488, 114176, 0, 0, 66, NULL, NULL },
    { 153, 845, 0, 0, 0, 45, 100, NULL, NULL },
    { 146, 848, 0, 0, 0, 45, 100, NULL, NULL },
    { 146, 860, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 865, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 919, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 921, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 1020, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 1080, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 145, 1085, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 1160, 0, 0, 0, 0, 69, NULL, NULL },
    { 157, 1180, 0, 0, 0, 0, 69, NULL, NULL },
    { 158, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent110Track3[14] = {
    { 270, 1, 20736, 34560, 0, 0, 66, NULL, NULL },
    { 271, 40, 0, 0, 0, 83, 68, NULL, NULL },
    { 270, 105, 0, 0, 0, 0, 69, NULL, NULL },
    { 274, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 270, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 282, 701, 40448, 116992, 0, 0, 66, NULL, NULL },
    { 284, 785, 0, 0, 0, 45, 100, NULL, NULL },
    { 284, 788, 0, 0, 0, 45, 100, NULL, NULL },
    { 282, 900, 0, 0, 0, 0, 69, NULL, NULL },
    { 285, 1020, 0, 0, 0, 0, 69, NULL, NULL },
    { 285, 1080, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 282, 1090, 0, 0, 0, 0, 69, NULL, NULL },
    { 282, 1100, 0, 0, 0, 0, 69, NULL, NULL },
    { 282, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent110Track4[10] = {
    { 664, 1, 13056, 26624, -2560, 0, 66, NULL, NULL },
    { 666, 40, 0, 0, 0, 83, 262212, NULL, NULL },
    { 664, 391, 0, 0, 0, 0, 262213, NULL, NULL },
    { 666, 400, 22272, 30720, -10240, 664, 266307, NULL, NULL },
    { 666, 450, 60928, 54784, -7680, 664, 266307, NULL, NULL },
    { 666, 480, 54016, 97280, -2560, 664, 262211, NULL, NULL },
    { 670, 720, 0, 0, 0, 0, 262213, NULL, NULL },
    { 664, 1020, 0, 0, 0, 0, 262213, NULL, NULL },
    { 664, 1075, 0, 0, 0, 0, 262213, NULL, NULL },
    { 665, 9999, 0, 0, 0, 0, 294981, NULL, NULL },
};

static const EventCharaKeyframe sEvent110Track5[2] = {
    { 587, 480, 77056, 97792, 0, 0, 66, NULL, NULL },
    { 588, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent110Track6[7] = {
    { 475, 15, 85504, 89344, 0, 0, 258, NULL, NULL },
    { 472, 600, 0, 0, 0, 0, 261, NULL, NULL },
    { 478, 620, 0, 0, 0, 0, 261, NULL, NULL },
    { 472, 621, 0, 0, 0, 0, 258, NULL, NULL },
    { 472, 1000, 0, 0, 0, 0, 261, NULL, NULL },
    { 475, 1020, 89600, 94208, 0, 0, 258, NULL, NULL },
    { 472, 9999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent110Track7[7] = {
    { 475, 21, 84736, 106752, 0, 0, 258, NULL, NULL },
    { 473, 620, 0, 0, 0, 0, 261, NULL, NULL },
    { 478, 640, 0, 0, 0, 0, 261, NULL, NULL },
    { 473, 641, 0, 0, 0, 0, 258, NULL, NULL },
    { 473, 1010, 0, 0, 0, 0, 261, NULL, NULL },
    { 475, 1030, 100352, 94976, 0, 0, 258, NULL, NULL },
    { 472, 9999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent110Track8[7] = {
    { 475, 28, 67840, 103168, 0, 0, 258, NULL, NULL },
    { 473, 640, 0, 0, 0, 0, 325, NULL, NULL },
    { 478, 660, 0, 0, 0, 0, 325, NULL, NULL },
    { 473, 661, 0, 0, 0, 0, 322, NULL, NULL },
    { 472, 1020, 0, 0, 0, 0, 325, NULL, NULL },
    { 475, 1040, 85760, 87040, 0, 0, 258, NULL, NULL },
    { 472, 9999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent110Track9[7] = {
    { 475, 34, 68864, 93184, 0, 0, 258, NULL, NULL },
    { 472, 660, 0, 0, 0, 0, 325, NULL, NULL },
    { 478, 680, 0, 0, 0, 0, 325, NULL, NULL },
    { 472, 681, 0, 0, 0, 0, 322, NULL, NULL },
    { 472, 1030, 0, 0, 0, 0, 325, NULL, NULL },
    { 475, 1050, 74496, 86272, 0, 0, 258, NULL, NULL },
    { 472, 9999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent110Track10[7] = {
    { 475, 41, 89600, 97024, 0, 0, 258, NULL, NULL },
    { 472, 680, 0, 0, 0, 0, 261, NULL, NULL },
    { 478, 700, 0, 0, 0, 0, 261, NULL, NULL },
    { 472, 701, 0, 0, 0, 0, 258, NULL, NULL },
    { 472, 1040, 0, 0, 0, 0, 261, NULL, NULL },
    { 475, 1060, 96000, 85760, 0, 0, 258, NULL, NULL },
    { 472, 9999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent110Track11[3] = {
    { 928, 1020, 0, 0, 0, 0, 8258, NULL, NULL },
    { 927, 1070, 51200, 76288, 0, 0, 16722, NULL, NULL },
    { 928, 2000, 0, 0, 0, 0, 98370, NULL, NULL },
};

static const EventCharaTrack sEvent110Tracks[12] = {
    { sEvent110Track0, EVENT_CHARA_SORA },
    { sEvent110Track1, EVENT_CHARA_DONALD },
    { sEvent110Track2, EVENT_CHARA_GOOFY },
    { sEvent110Track3, EVENT_CHARA_ALADDIN },
    { sEvent110Track4, EVENT_CHARA_GENIE },
    { sEvent110Track5, EVENT_CHARA_JASMINE },
    { sEvent110Track6, EVENT_CHARA_SHADOW },
    { sEvent110Track7, EVENT_CHARA_SHADOW },
    { sEvent110Track8, EVENT_CHARA_SHADOW },
    { sEvent110Track9, EVENT_CHARA_SHADOW },
    { sEvent110Track10, EVENT_CHARA_SHADOW },
    { sEvent110Track11, EVENT_CHARA_B_STATES_4 },
};

const EventSequenceDef gEvent110 = {
    ARRAY_COUNT(sEvent110Tracks),
    sEvent110Tracks,
    sEvent110Camera,
    sEvent110Script,
    sEvent110SoundCues,
    NULL,
    1280,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_EVENT_AGRABAH_2,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
