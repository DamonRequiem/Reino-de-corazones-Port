#ifdef VERSION_US
#include "event_117_text.inc"
#endif

static const MessageScriptEntry sEvent117Script[24] = {
    { PORTRAIT_PETER_PAN, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text00), 0, 130 },
    { PORTRAIT_WENDY, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text01), 0, 320 },
    { PORTRAIT_PETER_PAN, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text02), 0, 340 },
    { PORTRAIT_PETER_PAN, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text03), 0, 490 },
    { PORTRAIT_WENDY, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text04), 0, 650 },
    { PORTRAIT_WENDY, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text05), 0, 652 },
    { PORTRAIT_PETER_PAN, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text06), 0, 720 },
    { PORTRAIT_PETER_PAN, 4, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text07), 0, 722 },
    { PORTRAIT_PETER_PAN, 4, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text08), 0, 724 },
    { PORTRAIT_PETER_PAN, 4, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text09), 0, 726 },
    { PORTRAIT_WENDY, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text10), 0, 750 },
    { PORTRAIT_PETER_PAN, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text11), 0, 900 },
    { PORTRAIT_WENDY, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text12), 0, 920 },
    { PORTRAIT_PETER_PAN, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text13), 0, 940 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text14), 0, 1040 },
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text15), 0, 1080 },
    { PORTRAIT_WENDY, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text16), 0, 1140 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text17), 0, 1180 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text18), 0, 1210 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text19), 0, 1240 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text20), 0, 1250 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text21), 0, 1400 },
    { PORTRAIT_WENDY, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text22), 0, 1420 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent117Text23), MSG_SCRIPT_FLAG_END, 1440 },
};

#ifdef VERSION_JP
#include "event_117_text.inc"
#endif

static const EventCameraKeyframe sEvent117Camera[2] = {
    { -65396, 30720, 27136, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SWAY, 0, NULL },
    { -65366, 35072, 27136, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SWAY | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 30, NULL },
};

static const EvSoundCue sEvent117SoundCues[8] = {
    { SONG_BGM_PETERPAN_FIELD, 0, 0, 0 },
    { SONG_SND_387, 1, 0, 0 },
    { SONG_BGM_PETERPAN_FIELD, 650, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_EVENT_SILENCE, 900, EV_SOUND_FLAG_FADE_IN, 0 },
    { SONG_BGM_EVENT_SILENCE, 1139, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_PETERPAN_FIELD, 1180, EV_SOUND_FLAG_FADE_IN, 0 },
    { SONG_SND_387, 1520, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_PETERPAN_FIELD, 1545, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent117Track0[23] = {
    { 2, 150, -7168, 11520, 0, 0, 66, NULL, NULL },
    { 7, 310, 0, 0, 0, 83, 68, NULL, NULL },
    { 2, 350, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 480, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 2, 1010, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 1015, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1020, 0, 0, 0, 0, 69, NULL, NULL },
    { 0, 1025, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1039, 0, 0, 0, 0, 5, NULL, NULL },
    { 30, 1041, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1150, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 1155, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1160, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 1165, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1179, 0, 0, 0, 0, 69, NULL, NULL },
    { 32, 1260, 0, 0, 0, 0, 69, NULL, NULL },
    { 32, 1390, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 2, 1450, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 1455, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1460, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 1465, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1480, 0, 0, 0, 0, 5, NULL, NULL },
    { 14, 9999, 0, 0, 0, 211, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent117Track1[26] = {
    { 112, 150, -15360, 12288, 0, 0, 66, NULL, NULL },
    { 117, 310, 0, 0, 0, 83, 68, NULL, NULL },
    { 112, 350, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 480, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 112, 1010, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 1015, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1020, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 1025, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1079, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 1081, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1150, 0, 0, 0, 0, 5, NULL, NULL },
    { 113, 1155, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 1160, 0, 0, 0, 0, 5, NULL, NULL },
    { 111, 1165, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 1220, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 1225, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1239, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 1241, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1405, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 1410, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 1450, 0, 0, 0, 0, 69, NULL, NULL },
    { 111, 1455, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 1460, 0, 0, 0, 0, 5, NULL, NULL },
    { 113, 1465, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1480, 0, 0, 0, 0, 5, NULL, NULL },
    { 120, 9999, 0, 0, 0, 211, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent117Track2[26] = {
    { 144, 150, -3328, 5888, 0, 0, 66, NULL, NULL },
    { 149, 310, 0, 0, 0, 83, 68, NULL, NULL },
    { 144, 350, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 480, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 144, 1010, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 1015, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1020, 0, 0, 0, 0, 5, NULL, NULL },
    { 145, 1025, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 1150, 0, 0, 0, 0, 5, NULL, NULL },
    { 145, 1155, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1160, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 1165, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1190, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 1195, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1209, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 1211, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1405, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 1410, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1439, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 1441, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 1450, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 1455, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1460, 0, 0, 0, 0, 5, NULL, NULL },
    { 145, 1465, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 1480, 0, 0, 0, 0, 5, NULL, NULL },
    { 153, 9999, 0, 0, 0, 211, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent117Track3[18] = {
    { 309, 1, 256, 16640, -2560, 0, 194, NULL, NULL },
    { 309, 100, 0, 0, 0, 83, 196, NULL, NULL },
    { 310, 110, 0, 0, 0, 83, 196, NULL, NULL },
    { 301, 140, 0, 0, 0, 0, 197, NULL, NULL },
    { 308, 163, 0, 0, 0, 83, 228, NULL, NULL },
    { 309, 173, 0, 0, 0, 83, 228, NULL, NULL },
    { 301, 183, 39424, 36096, 0, 299, 67, NULL, NULL },
    { 299, 660, 0, 0, 0, 0, 69, NULL, NULL },
    { 305, 720, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 306, 750, 0, 0, 0, 0, 69, NULL, NULL },
    { 299, 760, 0, 0, 0, 0, 69, NULL, NULL },
    { 299, 890, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 299, 950, 0, 0, 0, 0, 69, NULL, NULL },
    { 301, 980, 0, 0, 0, 1, 68, NULL, NULL },
    { 301, 985, 0, 0, 0, 0, 5, NULL, NULL },
    { 302, 990, 0, 0, 0, 0, 5, NULL, NULL },
    { 311, 1060, -3328, 14336, -23040, 300, 3, NULL, NULL },
    { 300, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent117Track4[4] = {
    { 682, 1, 45312, 39168, 0, 0, 2, NULL, NULL },
    { 682, 500, 0, 0, 0, 0, 5, NULL, NULL },
    { 682, 630, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 682, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent117Track5[6] = {
    { 455, 0, 3840, 14336, -5632, 0, 66, NULL, NULL },
    { 456, 110, 0, 0, 0, 83, 196, NULL, NULL },
    { 456, 140, 0, 0, 0, 0, 197, NULL, NULL },
    { 456, 185, 49664, 37888, -5632, 455, 195, NULL, NULL },
    { 456, 1020, 0, 0, 0, 0, 133, NULL, NULL },
    { 458, 9999, 0, 0, 0, 0, 32901, NULL, NULL },
};

static const EventCharaTrack sEvent117Tracks[6] = {
    { sEvent117Track0, EVENT_CHARA_SORA },
    { sEvent117Track1, EVENT_CHARA_DONALD },
    { sEvent117Track2, EVENT_CHARA_GOOFY },
    { sEvent117Track3, EVENT_CHARA_PETER_PAN },
    { sEvent117Track4, EVENT_CHARA_WENDY },
    { sEvent117Track5, EVENT_CHARA_TINKER_BELL },
};

const EventSequenceDef gEvent117 = {
    ARRAY_COUNT(sEvent117Tracks),
    sEvent117Tracks,
    sEvent117Camera,
    sEvent117Script,
    sEvent117SoundCues,
    NULL,
    1550,
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
