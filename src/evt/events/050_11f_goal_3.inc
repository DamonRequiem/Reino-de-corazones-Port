#ifdef VERSION_US
#include "event_050_text.inc"
#endif

static const MessageScriptEntry sEvent050Script[19] = {
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text00), 0, 200 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text01), 0, 320 },
    { PORTRAIT_DONALD, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text02), 0, 390 },
    { PORTRAIT_DONALD, 4, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text03), 0, 392 },
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text04), 0, 394 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text05), 0, 530 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text06), 0, 550 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text07), 0, 570 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text08), 0, 572 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text09), 0, 720 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text10), 0, 740 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text11), 0, 760 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text12), 0, 780 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text13), 0, 880 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text14), 0, 900 },
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text15), 0, 920 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text16), 0, 940 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text17), 0, 1070 },
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent050Text18), MSG_SCRIPT_FLAG_END, 1150 },
};

#ifdef VERSION_JP
#include "event_050_text.inc"
#endif

static const EventCameraKeyframe sEvent050Camera[6] = {
    { -65416, 219904, 47616, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65306, 151040, 83456, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 40, NULL },
    { -65206, 220416, 48384, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 40, NULL },
    { -64556, 151040, 83456, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 40, NULL },
    { -64426, 163584, 79360, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 40, NULL },
    { -64386, 193536, 60672, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 40, NULL },
};

static const EvSoundCue sEvent050SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent050Track0[37] = {
    { 4, 80, 220416, 53248, 0, 0, 66, NULL, NULL },
    { 3, 85, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 90, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 95, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 320, 0, 0, 0, 0, 5, NULL, NULL },
    { 31, 400, 0, 0, 0, 0, 5, NULL, NULL },
    { 12, 520, 157952, 83968, 0, 2, 3, NULL, NULL },
    { 2, 523, 0, 0, 0, 173, 4, NULL, NULL },
    { 2, 530, 0, 0, 0, 0, 5, NULL, NULL },
    { 31, 560, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 570, 0, 0, 0, 0, 5, NULL, NULL },
    { 32, 572, 0, 0, 0, 0, 5, NULL, NULL },
    { 31, 720, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 740, 0, 0, 0, 0, 5, NULL, NULL },
    { 31, 760, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 790, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 900, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 31, 901, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 950, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 955, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 960, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 965, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 980, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 1020, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 1023, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 1030, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 1035, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 1040, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 1045, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1070, 0, 0, 0, 0, 5, NULL, NULL },
    { 31, 1071, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1080, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 1085, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1090, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 1095, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1110, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 1500, 0, 0, 0, 45, 32868, NULL, NULL },
};

static const EventCharaKeyframe sEvent050Track1[16] = {
    { 128, 370, 153088, 92416, 0, 0, 2, NULL, NULL },
    { 129, 380, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 385, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 388, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 391, 0, 0, 0, 0, 69, NULL, NULL },
    { 127, 580, 0, 0, 0, 0, 69, NULL, NULL },
    { 127, 710, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 127, 761, 0, 0, 0, 0, 69, NULL, NULL },
    { 129, 770, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 780, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 781, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 920, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 921, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1120, 0, 0, 0, 0, 69, NULL, NULL },
    { 119, 1150, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 9920, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent050Track2[11] = {
    { 146, 550, 142336, 86272, 0, 0, 66, NULL, NULL },
    { 165, 551, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 580, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 710, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 146, 720, 0, 0, 0, 0, 69, NULL, NULL },
    { 165, 721, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 760, 0, 0, 0, 0, 69, NULL, NULL },
    { 165, 761, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 880, 0, 0, 0, 0, 69, NULL, NULL },
    { 165, 881, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 580, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent050Tracks[3] = {
    { sEvent050Track0, EVENT_CHARA_SORA },
    { sEvent050Track1, EVENT_CHARA_DONALD },
    { sEvent050Track2, EVENT_CHARA_GOOFY },
};

const EventSequenceDef gEvent050 = {
    ARRAY_COUNT(sEvent050Tracks),
    sEvent050Tracks,
    sEvent050Camera,
    sEvent050Script,
    sEvent050SoundCues,
    NULL,
    1180,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_051_11F_DEMO_2,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
