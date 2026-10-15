#ifdef VERSION_US
#include "event_090_text.inc"
#endif

static const MessageScriptEntry sEvent090Script[22] = {
    { PORTRAIT_JACK, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text00), 0, 440 },
    { PORTRAIT_SALLY, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text01), 0, 560 },
    { PORTRAIT_JACK, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text02), 0, 570 },
    { PORTRAIT_SALLY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text03), 0, 580 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text04), 0, 650 },
    { PORTRAIT_SALLY, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text05), 0, 690 },
    { PORTRAIT_SALLY, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text06), 0, 692 },
    { PORTRAIT_JACK, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text07), 0, 710 },
    { PORTRAIT_SALLY, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text08), 0, 730 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text09), 0, 745 },
    { PORTRAIT_JACK, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text10), 0, 760 },
    { PORTRAIT_OOGIE_BOOGIE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text11), MSG_SCRIPT_FLAG_SILHOUETTE, 780 },
    { PORTRAIT_SALLY, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text12), 0, 920 },
    { PORTRAIT_JACK, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text13), 0, 1030 },
    { PORTRAIT_OOGIE_BOOGIE, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text14), 0, 1040 },
    { PORTRAIT_OOGIE_BOOGIE, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text15), 0, 1130 },
    { PORTRAIT_OOGIE_BOOGIE, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text16), 0, 1160 },
    { PORTRAIT_OOGIE_BOOGIE, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text17), 0, 1162 },
    { PORTRAIT_OOGIE_BOOGIE, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text18), 0, 1190 },
    { PORTRAIT_OOGIE_BOOGIE, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text19), 0, 1200 },
    { PORTRAIT_JACK, 2, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text20), 0, 1340 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent090Text21), MSG_SCRIPT_FLAG_END, 1390 },
};

#ifdef VERSION_JP
#include "event_090_text.inc"
#endif

static const EvSoundCue sEvent090SoundCues[5] = {
    { SONG_BGM_HALLOWEEN_FIELD, 0, 0, 0 },
    { SONG_BGM_HALLOWEEN_FIELD, 770, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_EVENT_UNREST, 781, EV_SOUND_FLAG_FADE_IN, 0 },
    { SONG_BTL_MON_HIT03, 790, 0, 0 },
    { SONG_BGM_EVENT_UNREST, 1635, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent090Camera[12] = {
    { -65386, 96000, 24576, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64887, 96000, 61952, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 160, NULL },
    { -64746, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -64736, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_MEDIUM | CAMERA_MODE_KEEP, 0, NULL },
    { -64716, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -64706, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FLASH | CAMERA_MODE_KEEP, 10, NULL },
    { -64615, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -64286, 90368, 100352, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 30, NULL },
    { -64197, 93696, 90880, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 80, NULL },
    { -64126, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -63907, 97792, 77312, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 80, NULL },
    { -63906, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_BLACK | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 30, NULL },
};

static const EventCharaKeyframe sEvent090Track0[21] = {
    { 4, 220, 87296, 84224, 0, 0, 66, NULL, NULL },
    { 9, 339, 102656, 70912, 0, 4, 67, NULL, NULL },
    { 4, 590, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 744, 0, 0, 0, 0, 69, NULL, NULL },
    { 34, 778, 0, 0, 0, 0, 69, NULL, NULL },
    { 35, 780, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 820, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 880, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 930, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 936, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 940, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 945, 0, 0, 0, 0, 5, NULL, NULL },
    { 12, 1000, 92928, 98816, 0, 2, 3, NULL, NULL },
    { 2, 1343, 0, 0, 0, 0, 5, NULL, NULL },
    { 12, 1375, 81408, 103168, 0, 2, 3, NULL, NULL },
    { 2, 1379, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1389, 0, 0, 0, 0, 69, NULL, NULL },
    { 31, 1391, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 1405, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1415, 0, 0, 0, 0, 5, NULL, NULL },
    { 12, 1999, 0, 0, 0, 173, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent090Track1[21] = {
    { 570, 220, 107264, 64000, 0, 0, 2, NULL, NULL },
    { 570, 270, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 573, 320, 0, 0, 0, 0, 5, NULL, NULL },
    { 573, 441, 0, 0, 0, 0, 69, NULL, NULL },
    { 573, 500, 0, 0, 0, 0, 5, NULL, NULL },
    { 573, 581, 0, 0, 0, 0, 69, NULL, NULL },
    { 571, 651, 0, 0, 0, 0, 69, NULL, NULL },
    { 572, 685, 0, 0, 0, 0, 69, NULL, NULL },
    { 573, 691, 0, 0, 0, 0, 5, NULL, NULL },
    { 573, 755, 0, 0, 0, 0, 69, NULL, NULL },
    { 573, 820, 0, 0, 0, 0, 5, NULL, NULL },
    { 568, 880, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 568, 890, 0, 0, 0, 0, 69, NULL, NULL },
    { 568, 900, 0, 0, 0, 0, 5, NULL, NULL },
    { 568, 909, 0, 0, 0, 0, 69, NULL, NULL },
    { 568, 921, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 568, 1130, 0, 0, 0, 0, 69, NULL, NULL },
    { 573, 1139, 105728, 78080, 0, 0, 2, NULL, NULL },
    { 573, 1460, 0, 0, 0, 0, 5, NULL, NULL },
    { 574, 1530, 0, 0, 0, 173, 4, NULL, NULL },
    { 573, 1139, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent090Track2[20] = {
    { 289, 220, 95744, 84480, 0, 0, 66, NULL, NULL },
    { 296, 326, 115456, 69632, 0, 289, 67, NULL, NULL },
    { 289, 340, 0, 0, 0, 0, 69, NULL, NULL },
    { 289, 709, 0, 0, 0, 0, 5, NULL, NULL },
    { 292, 735, 0, 0, 0, 0, 5, NULL, NULL },
    { 288, 745, 0, 0, 0, 0, 5, NULL, NULL },
    { 289, 755, 0, 0, 0, 0, 5, NULL, NULL },
    { 288, 820, 0, 0, 0, 0, 5, NULL, NULL },
    { 288, 880, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 288, 890, 0, 0, 0, 0, 5, NULL, NULL },
    { 289, 925, 0, 0, 0, 0, 5, NULL, NULL },
    { 288, 935, 0, 0, 0, 0, 5, NULL, NULL },
    { 291, 990, 98304, 102400, 0, 288, 3, NULL, NULL },
    { 288, 1000, 0, 0, 0, 0, 5, NULL, NULL },
    { 290, 1029, 0, 0, 0, 173, 36, NULL, NULL },
    { 298, 1045, 0, 0, 0, 0, 5, NULL, NULL },
    { 288, 1339, 0, 0, 0, 0, 5, NULL, NULL },
    { 298, 1341, 0, 0, 0, 0, 5, NULL, NULL },
    { 288, 1410, 0, 0, 0, 0, 5, NULL, NULL },
    { 291, 1999, 0, 0, 0, 173, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent090Track3[12] = {
    { 114, 220, 92928, 91648, 0, 0, 66, NULL, NULL },
    { 119, 360, 107008, 77568, 0, 114, 67, NULL, NULL },
    { 114, 370, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 820, 0, 0, 0, 0, 5, NULL, NULL },
    { 133, 880, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 110, 940, 0, 0, 0, 0, 5, NULL, NULL },
    { 113, 950, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 955, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 970, 0, 0, 0, 0, 5, NULL, NULL },
    { 121, 1030, 104192, 93952, 0, 112, 3, NULL, NULL },
    { 112, 1415, 0, 0, 0, 0, 5, NULL, NULL },
    { 121, 1999, 0, 0, 0, 173, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent090Track4[14] = {
    { 146, 220, 79360, 86272, 0, 0, 66, NULL, NULL },
    { 151, 350, 91648, 74752, 0, 146, 67, NULL, NULL },
    { 146, 650, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 820, 0, 0, 0, 0, 69, NULL, NULL },
    { 161, 880, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 146, 935, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 940, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 945, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 960, 0, 0, 0, 0, 5, NULL, NULL },
    { 152, 990, 89600, 92672, 0, 144, 3, NULL, NULL },
    { 144, 1340, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 1390, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1420, 0, 0, 0, 0, 5, NULL, NULL },
    { 152, 1999, 0, 0, 0, 173, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent090Track5[15] = {
    { 361, 799, 256000, 256000, 0, 0, 8258, NULL, NULL },
    { 361, 800, 75264, 63232, 0, 0, 16450, NULL, NULL },
    { 366, 820, 104960, 66048, 0, 361, 67, NULL, NULL },
    { 366, 825, 0, 0, 0, 0, 69, NULL, NULL },
    { 366, 830, 0, 0, 0, 0, 5, NULL, NULL },
    { 366, 870, 67072, 117248, 0, 361, 3, NULL, NULL },
    { 362, 1041, 0, 0, 0, 0, 69, NULL, NULL },
    { 367, 1131, 0, 0, 0, 0, 69, NULL, NULL },
    { 369, 1159, 0, 0, 0, 0, 69, NULL, NULL },
    { 362, 1189, 0, 0, 0, 0, 69, NULL, NULL },
    { 363, 1191, 0, 0, 0, 0, 69, NULL, NULL },
    { 361, 1195, 0, 0, 0, 0, 69, NULL, NULL },
    { 361, 1199, 0, 0, 0, 0, 5, NULL, NULL },
    { 365, 1201, 0, 0, 0, 0, 5, NULL, NULL },
    { 366, 1999, 0, 0, 0, 173, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent090Track6[3] = {
    { 479, 790, 75776, 65536, 0, 0, 274, NULL, NULL },
    { 480, 800, 0, 0, 0, 0, 277, NULL, NULL },
    { 481, 999, 0, 0, 0, 0, 33045, NULL, NULL },
};

static const EventCharaKeyframe sEvent090Track7[3] = {
    { 482, 790, 75776, 65536, 0, 0, 274, NULL, NULL },
    { 483, 798, 75776, 65536, 0, 0, 274, NULL, NULL },
    { 484, 999, 75776, 57344, 0, 0, 33026, NULL, NULL },
};

static const EventCharaTrack sEvent090Tracks[8] = {
    { sEvent090Track0, EVENT_CHARA_SORA },
    { sEvent090Track1, EVENT_CHARA_SALLY },
    { sEvent090Track2, EVENT_CHARA_JACK },
    { sEvent090Track3, EVENT_CHARA_DONALD },
    { sEvent090Track4, EVENT_CHARA_GOOFY },
    { sEvent090Track5, EVENT_CHARA_OOGIE_BOOGIE },
    { sEvent090Track6, EVENT_CHARA_HALLOWEEN_TOWN_GATE_DOOR },
    { sEvent090Track7, EVENT_CHARA_HALLOWEEN_TOWN_GATE_DOOR_2 },
};

const EventSequenceDef gEvent090 = {
    ARRAY_COUNT(sEvent090Tracks),
    sEvent090Tracks,
    sEvent090Camera,
    sEvent090Script,
    sEvent090SoundCues,
    NULL,
    1640,
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
