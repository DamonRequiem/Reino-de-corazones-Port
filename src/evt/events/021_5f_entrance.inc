#ifdef VERSION_US
#include "event_021_text.inc"
#endif

static const MessageScriptEntry sEvent021Script[17] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text00), 0, 380 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text01), 0, 520 },
    { PORTRAIT_GOOFY, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text02), 0, 660 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text03), 0, 680 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text04), 0, 682 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text05), 0, 760 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text06), 0, 780 },
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text07), 0, 800 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text08), 0, 820 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text09), 0, 840 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text10), 0, 990 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text11), 0, 1090 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text12), 0, 1092 },
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text13), 0, 1110 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text14), 0, 1130 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text15), 0, 1132 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent021Text16), MSG_SCRIPT_FLAG_END, 1160 },
};

#ifdef VERSION_JP
#include "event_021_text.inc"
#endif

static const EventCameraKeyframe sEvent021Camera[2] = {
    { -65236, 176640, 70144, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64537, 194560, 60672, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 80, NULL },
};

static const EvSoundCue sEvent021SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent021Track0[27] = {
    { 4, 1, 150272, 89088, 0, 0, 66, NULL, NULL },
    { 9, 170, 182784, 72704, 0, 4, 67, NULL, NULL },
    { 4, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 185, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 190, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 195, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 230, 0, 0, 0, 0, 5, NULL, NULL },
    { 15, 245, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 260, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 265, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 270, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 275, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 310, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 360, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 380, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 390, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 519, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 521, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 679, 0, 0, 0, 0, 69, NULL, NULL },
    { 36, 690, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 739, 0, 0, 0, 0, 69, NULL, NULL },
    { 34, 850, 0, 0, 0, 0, 69, NULL, NULL },
    { 34, 980, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 34, 1100, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1140, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 1155, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent021Track2[26] = {
    { 146, 1, 137216, 91392, 0, 0, 66, NULL, NULL },
    { 151, 170, 169216, 74496, 0, 146, 67, NULL, NULL },
    { 146, 190, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 230, 0, 0, 0, 0, 69, NULL, NULL },
    { 168, 245, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 250, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 151, 380, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 390, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 490, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 146, 495, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 500, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 505, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 510, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 530, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 580, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 144, 600, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 620, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 640, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 659, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 661, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 839, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 841, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 1129, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 1133, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent021Track1[19] = {
    { 114, 1, 146432, 95232, 0, 0, 66, NULL, NULL },
    { 119, 170, 176896, 80896, 0, 114, 67, NULL, NULL },
    { 114, 190, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 223, 0, 0, 0, 0, 69, NULL, NULL },
    { 139, 245, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 250, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 119, 380, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 390, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 490, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 114, 495, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 500, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 505, 0, 0, 0, 0, 5, NULL, NULL },
    { 113, 510, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 799, 0, 0, 0, 0, 5, NULL, NULL },
    { 125, 801, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 1109, 0, 0, 0, 0, 5, NULL, NULL },
    { 125, 1111, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent021Track3[7] = {
    { 231, 690, 0, 0, 0, 0, 66, NULL, NULL },
    { 231, 691, 186112, 71680, 0, 0, 66, NULL, NULL },
    { 234, 720, 0, 0, 0, 45, 68, EventCharaHop, NULL },
    { 231, 730, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 740, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 750, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent021Tracks[4] = {
    { sEvent021Track0, EVENT_CHARA_SORA },
    { sEvent021Track1, EVENT_CHARA_DONALD },
    { sEvent021Track2, EVENT_CHARA_GOOFY },
    { sEvent021Track3, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent021 = {
    ARRAY_COUNT(sEvent021Tracks),
    sEvent021Tracks,
    sEvent021Camera,
    sEvent021Script,
    sEvent021SoundCues,
    NULL,
    1220,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
