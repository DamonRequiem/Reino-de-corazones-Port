#ifdef VERSION_US
#include "event_129_text.inc"
#endif

static const MessageScriptEntry sEvent129Script[12] = {
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text00), 0, 200 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text01), 0, 330 },
    { PORTRAIT_BEAST, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text02), 0, 400 },
    { PORTRAIT_BELLE, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text03), 0, 610 },
    { PORTRAIT_BELLE, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text04), 0, 730 },
    { PORTRAIT_BEAST, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text05), 0, 760 },
    { PORTRAIT_BELLE, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text06), 0, 790 },
    { PORTRAIT_BEAST, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text07), 0, 990 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text08), 0, 1160 },
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text09), 0, 1230 },
    { PORTRAIT_BEAST, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text10), 0, 1470 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent129Text11), MSG_SCRIPT_FLAG_END, 1720 },
};

#ifdef VERSION_JP
#include "event_129_text.inc"
#endif

static const EvSoundCue sEvent129SoundCues[6] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_EV_WOMAN2_DIRTL, 376, 0, 0 },
    { SONG_BGM_EVENT_SILENCE, 400, EV_SOUND_FLAG_FADE_IN, 0 },
    { SONG_SND_351, 639, 0, 0 },
    { SONG_EV_WOMAN2_DIRTR, 946, 0, 0 },
    { SONG_BGM_EVENT_SILENCE, 1775, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent129Camera[5] = {
    { -65536, 31488, 63744, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -65306, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 80, NULL },
    { -64536, 81152, 67072, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 100, NULL },
    { -64036, 49408, 76800, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 100, NULL },
    { -55537, 43264, 77568, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 80, NULL },
};

static const EventCharaKeyframe sEvent129Track0[7] = {
    { 2, 1, 11008, 62464, 0, 0, 66, NULL, NULL },
    { 7, 130, 32000, 74240, 0, 2, 67, NULL, NULL },
    { 2, 1020, 0, 0, 0, 0, 69, NULL, NULL },
    { 12, 1080, 43008, 82176, 0, 2, 99, NULL, NULL },
    { 2, 1530, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 1550, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent129Track1[9] = {
    { 112, 1, 4096, 64000, 0, 0, 66, NULL, NULL },
    { 117, 140, 21504, 74240, 0, 112, 67, NULL, NULL },
    { 112, 1020, 0, 0, 0, 0, 69, NULL, NULL },
    { 121, 1090, 34560, 83456, 0, 112, 99, NULL, NULL },
    { 112, 1225, 0, 0, 0, 0, 69, NULL, NULL },
    { 125, 1232, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 1535, 0, 0, 0, 0, 69, NULL, NULL },
    { 111, 1550, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent129Track2[13] = {
    { 144, 1, 11264, 55296, 0, 0, 66, NULL, NULL },
    { 149, 100, 26624, 65280, 0, 144, 67, NULL, NULL },
    { 144, 120, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 170, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 144, 195, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 202, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 1020, 0, 0, 0, 0, 69, NULL, NULL },
    { 152, 1100, 43520, 73728, 0, 144, 99, NULL, NULL },
    { 144, 1540, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 1560, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1715, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 1722, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent129Track3[6] = {
    { 229, 1080, 0, 0, 0, 0, 2, NULL, NULL },
    { 229, 1082, 45056, 82688, 0, 0, 2, NULL, NULL },
    { 233, 1112, 0, 0, 0, 173, 4, EventCharaHop, NULL },
    { 229, 1120, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 1550, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent129Track4[22] = {
    { 328, 305, 91904, 70400, 0, 0, 2, NULL, NULL },
    { 328, 360, 0, 0, 0, 0, 5, NULL, NULL },
    { 330, 380, 0, 0, 0, 173, 4, NULL, NULL },
    { 328, 395, 0, 0, 0, 0, 5, NULL, NULL },
    { 332, 402, 0, 0, 0, 0, 5, NULL, NULL },
    { 328, 620, 0, 0, 0, 0, 5, NULL, NULL },
    { 328, 635, 0, 0, 0, 0, 5, NULL, NULL },
    { 335, 685, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 328, 722, 0, 0, 0, 0, 5, NULL, NULL },
    { 328, 755, 0, 0, 0, 0, 5, NULL, NULL },
    { 332, 762, 0, 0, 0, 0, 5, NULL, NULL },
    { 328, 930, 0, 0, 0, 0, 5, NULL, NULL },
    { 330, 960, 0, 0, 0, 173, 4, NULL, NULL },
    { 328, 1050, 0, 0, 0, 0, 5, NULL, NULL },
    { 330, 1130, 56576, 88064, 0, 328, 3, NULL, NULL },
    { 328, 1190, 0, 0, 0, 0, 5, NULL, NULL },
    { 329, 1260, 0, 0, 0, 0, 5, NULL, NULL },
    { 329, 1410, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 329, 1440, 0, 0, 0, 0, 5, NULL, NULL },
    { 328, 1500, 0, 0, 0, 0, 5, NULL, NULL },
    { 330, 2000, 0, 0, 0, 173, 4, NULL, NULL },
    { 328, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent129Track5[13] = {
    { 375, 300, 69888, 81408, 0, 0, 66, NULL, NULL },
    { 374, 310, 0, 0, 0, 0, 69, NULL, NULL },
    { 374, 430, 0, 0, 0, 0, 5, NULL, NULL },
    { 380, 450, 0, 0, 0, 0, 5, NULL, NULL },
    { 380, 580, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 380, 670, 0, 0, 0, 0, 5, NULL, NULL },
    { 374, 690, 0, 0, 0, 0, 5, NULL, NULL },
    { 374, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 375, 830, 0, 0, 0, 0, 69, NULL, NULL },
    { 374, 840, 0, 0, 0, 0, 69, NULL, NULL },
    { 374, 860, 0, 0, 0, 0, 5, NULL, NULL },
    { 376, 1500, 0, 0, 0, 173, 4, NULL, NULL },
    { 374, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent129Tracks[6] = {
    { sEvent129Track0, EVENT_CHARA_SORA },
    { sEvent129Track1, EVENT_CHARA_DONALD },
    { sEvent129Track2, EVENT_CHARA_GOOFY },
    { sEvent129Track3, EVENT_CHARA_JIMINY_CRICKET },
    { sEvent129Track4, EVENT_CHARA_BEAST },
    { sEvent129Track5, EVENT_CHARA_BELLE },
};

const EventSequenceDef gEvent129 = {
    ARRAY_COUNT(sEvent129Tracks),
    sEvent129Tracks,
    sEvent129Camera,
    sEvent129Script,
    sEvent129SoundCues,
    NULL,
    1780,
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
