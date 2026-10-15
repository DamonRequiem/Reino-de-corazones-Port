#ifdef VERSION_US
#include "event_012_text.inc"
#endif

static const MessageScriptEntry sEvent012Script[18] = {
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text00), 0, 290 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text01), 0, 320 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text02), 0, 400 },
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text03), 0, 402 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text04), 0, 440 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text05), 0, 470 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text06), 0, 500 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text07), 0, 575 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text08), 0, 635 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text09), 0, 750 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text10), 0, 810 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text11), 0, 1040 },
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text12), 0, 1070 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text13), 0, 1135 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text14), 0, 1325 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text15), 0, 1360 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text16), 0, 1410 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent012Text17), MSG_SCRIPT_FLAG_END, 1450 },
};

#ifdef VERSION_JP
#include "event_012_text.inc"
#endif

static const EventCameraKeyframe sEvent012Camera[1] = {
    { -65485, 189696, 62208, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent012SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent012Track0[13] = {
    { 4, 1, 164352, 80640, 0, 0, 66, NULL, NULL },
    { 9, 121, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 435, 0, 0, 0, 0, 69, NULL, NULL },
    { 36, 472, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 705, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 710, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 715, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 820, 0, 0, 0, 0, 5, NULL, NULL },
    { 32, 930, 0, 0, 0, 0, 5, NULL, NULL },
    { 32, 1010, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 32, 1380, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 5050, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent012Track1[13] = {
    { 114, 5, 160256, 87040, 0, 0, 66, NULL, NULL },
    { 119, 126, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 540, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 545, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 570, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 577, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 820, 0, 0, 0, 0, 5, NULL, NULL },
    { 127, 880, 0, 0, 0, 0, 5, NULL, NULL },
    { 127, 1010, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 127, 1160, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1355, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 1362, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 5050, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent012Track2[19] = {
    { 146, 7, 149248, 83712, 0, 0, 66, NULL, NULL },
    { 151, 128, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 495, 0, 0, 0, 0, 69, NULL, NULL },
    { 165, 502, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 605, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 630, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 637, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 780, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 805, 0, 0, 0, 0, 69, NULL, NULL },
    { 167, 812, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 1100, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 1130, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 1137, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 1160, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 1290, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 144, 1320, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 1327, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent012Track3[8] = {
    { 231, 121, 0, 0, 0, 0, 66, NULL, NULL },
    { 231, 122, 192000, 66816, 0, 0, 66, NULL, NULL },
    { 234, 150, 0, 0, 0, 45, 68, EventCharaHop, NULL },
    { 231, 155, 0, 0, 0, 0, 69, NULL, NULL },
    { 232, 190, 201216, 62976, 0, 231, 67, NULL, NULL },
    { 231, 350, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent012Tracks[4] = {
    { sEvent012Track0, EVENT_CHARA_SORA },
    { sEvent012Track1, EVENT_CHARA_DONALD },
    { sEvent012Track2, EVENT_CHARA_GOOFY },
    { sEvent012Track3, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent012 = {
    ARRAY_COUNT(sEvent012Tracks),
    sEvent012Tracks,
    sEvent012Camera,
    sEvent012Script,
    sEvent012SoundCues,
    NULL,
    1510,
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
