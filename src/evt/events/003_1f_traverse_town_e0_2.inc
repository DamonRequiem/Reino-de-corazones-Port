#ifdef VERSION_US
#include "event_003_text.inc"
#endif

static const MessageScriptEntry sEvent003Script[24] = {
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text00), 0, 90 },
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text01), 0, 120 },
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text02), 0, 122 },
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text03), 0, 150 },
    { PORTRAIT_GOOFY, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text04), 0, 255 },
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text05), 0, 355 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text06), 0, 450 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text07), 0, 500 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text08), 0, 530 },
    { PORTRAIT_GOOFY, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text09), 0, 600 },
    { PORTRAIT_DONALD, 4, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text10), 0, 690 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text11), 0, 805 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text12), 0, 835 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text13), 0, 935 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text14), 0, 1060 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text15), 0, 1090 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text16), 0, 1092 },
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text17), 0, 1420 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text18), 0, 1480 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text19), 0, 1482 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text20), 0, 1630 },
    { PORTRAIT_NONE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text21), 0, 1640 },
    { PORTRAIT_NONE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text22), 0, 1642 },
    { PORTRAIT_NONE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent003Text23), MSG_SCRIPT_FLAG_END, 1644 },
};

#ifdef VERSION_JP
#include "event_003_text.inc"
#endif

static const EventCameraKeyframe sEvent003Camera[4] = {
    { -65126, 62976, 58880, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64516, 66048, 57600, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 20, NULL },
    { -63975, 75008, 54528, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 80, NULL },
    { -60536, 81152, 49664, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 80, NULL },
};

static const EvSoundCue sEvent003SoundCues[2] = {
    { SONG_BGM_EVENT_UNREST, 0, 0, 0 },
    { SONG_BGM_EVENT_UNREST, 1685, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent003Track0[41] = {
    { 2, 30, 60928, 65792, 0, 0, 2, NULL, NULL },
    { 1, 45, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 60, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 375, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 380, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 385, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 390, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 610, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 660, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 0, 670, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 700, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 750, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 4, 760, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 765, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 770, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 775, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 800, 0, 0, 0, 0, 69, NULL, NULL },
    { 31, 850, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 870, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 875, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 880, 0, 0, 0, 0, 69, NULL, NULL },
    { 0, 885, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 910, 0, 0, 0, 0, 5, NULL, NULL },
    { 16, 920, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 970, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 975, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1010, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 1040, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 1200, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1330, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 4, 1430, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 1435, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 1440, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 1445, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1510, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 1515, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1520, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 1525, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1560, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 1600, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent003Track1[19] = {
    { 114, 30, 61952, 72704, 0, 0, 2, NULL, NULL },
    { 114, 115, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 124, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 280, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 330, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 114, 350, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 357, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 460, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 470, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 630, 0, 0, 0, 0, 69, NULL, NULL },
    { 119, 660, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 685, 0, 0, 0, 0, 69, NULL, NULL },
    { 131, 692, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 820, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 825, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1015, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 1020, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1025, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent003Track2[19] = {
    { 144, 30, 48896, 62464, 0, 0, 66, NULL, NULL },
    { 144, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 230, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 144, 250, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 257, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 470, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 480, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 550, 0, 0, 0, 0, 69, NULL, NULL },
    { 151, 580, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 595, 0, 0, 0, 0, 69, NULL, NULL },
    { 165, 602, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 810, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 815, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 830, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 837, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 1020, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 1025, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 1030, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent003Track3[4] = {
    { 231, 30, 52992, 70656, 0, 0, 66, NULL, NULL },
    { 231, 1350, 0, 0, 0, 0, 69, NULL, NULL },
    { 232, 1380, 0, 0, 0, 45, 68, NULL, NULL },
    { 231, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent003Track4[5] = {
    { 181, 1115, 82688, 55552, 0, 0, 2, NULL, NULL },
    { 178, 1150, 0, 0, 0, 0, 5, NULL, NULL },
    { 178, 1160, 0, 0, 0, 45, 4, NULL, NULL },
    { 178, 1190, 0, 0, 0, 45, 4, EventCharaFadeOut, NULL },
    { 178, 9999, 0, 0, 0, 0, 32770, NULL, NULL },
};

static const EventCharaTrack sEvent003Tracks[5] = {
    { sEvent003Track0, EVENT_CHARA_SORA },
    { sEvent003Track1, EVENT_CHARA_DONALD },
    { sEvent003Track2, EVENT_CHARA_GOOFY },
    { sEvent003Track3, EVENT_CHARA_JIMINY_CRICKET },
    { sEvent003Track4, EVENT_CHARA_ROBED_FIGURE },
};

const EventSequenceDef gEvent003 = {
    ARRAY_COUNT(sEvent003Tracks),
    sEvent003Tracks,
    sEvent003Camera,
    sEvent003Script,
    sEvent003SoundCues,
    NULL,
    1690,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_MAP_1F,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
