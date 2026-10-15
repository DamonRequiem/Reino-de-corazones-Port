#ifdef VERSION_US
#include "event_190_text.inc"
#endif

static const MessageScriptEntry sEvent190Script[15] = {
    { PORTRAIT_MICKEY, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text00), 0, 210 },
    { PORTRAIT_RIKU, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text01), 0, 240 },
    { PORTRAIT_MICKEY, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text02), 0, 270 },
    { PORTRAIT_RIKU, 3, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text03), 0, 780 },
    { PORTRAIT_MICKEY, 4, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text04), 0, 825 },
    { PORTRAIT_RIKU, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text05), 0, 880 },
    { PORTRAIT_DIZ, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text06), 0, 940 },
    { PORTRAIT_RIKU, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text07), 0, 970 },
    { PORTRAIT_DIZ, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text08), 0, 1000 },
    { PORTRAIT_RIKU, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text09), 0, 1050 },
    { PORTRAIT_DIZ, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text10), 0, 1080 },
    { PORTRAIT_RIKU, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text11), 0, 1110 },
    { PORTRAIT_DIZ, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text12), 0, 1140 },
    { PORTRAIT_DIZ, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text13), 0, 1220 },
    { PORTRAIT_RIKU, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent190Text14), MSG_SCRIPT_FLAG_END, 1460 },
};

#ifdef VERSION_JP
#include "event_190_text.inc"
#endif

static const EvSoundCue sEvent190SoundCues[6] = {
    { SONG_BGM_T13THFLOOR, 0, 0, 0 },
    { SONG_SND_958, 640, 0, 0 },
    { SONG_EV_SR_STONEL, 645, 0, 0 },
    { SONG_SND_959, 660, 0, 0 },
    { SONG_EV_SR_STONER, 665, 0, 0 },
    { SONG_EV_CARDTHR, 1191, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent190Camera[4] = {
    { -65116, 159488, 77056, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64916, 201728, 55296, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 80, NULL },
    { -64537, 192000, 61952, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 50, NULL },
    { -60536, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EventCharaKeyframe sEvent190Track0[17] = {
    { 515, 1, 125696, 101888, 0, 0, 66, NULL, NULL },
    { 518, 110, 0, 0, 0, 45, 68, NULL, NULL },
    { 515, 350, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 400, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 515, 510, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 620, 167424, 84736, 0, 0, 66, NULL, NULL },
    { 518, 690, 185088, 75520, 0, 515, 67, NULL, NULL },
    { 515, 730, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 850, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 1190, 0, 0, 0, 0, 69, NULL, NULL },
    { 559, 1250, 0, 0, 0, 0, 69, NULL, NULL },
    { 558, 1280, 0, 0, 0, 0, 69, NULL, NULL },
    { 558, 1410, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 558, 1440, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 1480, 0, 0, 0, 0, 69, NULL, NULL },
    { 518, 1700, 230400, 52992, 0, 515, 67, NULL, NULL },
    { 515, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent190Track1[18] = {
    { 745, 50, 198400, 64256, 0, 0, 2, NULL, NULL },
    { 747, 180, 0, 0, 0, 173, 4, NULL, NULL },
    { 745, 300, 0, 0, 0, 0, 5, NULL, NULL },
    { 745, 310, 0, 0, 0, 0, 69, NULL, NULL },
    { 746, 510, 0, 0, 0, 0, 69, NULL, NULL },
    { 746, 620, 161792, 76544, 0, 0, 66, NULL, NULL },
    { 754, 690, 176384, 70400, 0, 746, 67, NULL, NULL },
    { 746, 800, 0, 0, 0, 0, 69, NULL, NULL },
    { 745, 820, 0, 0, 0, 0, 69, NULL, NULL },
    { 752, 900, 0, 0, 0, 0, 69, NULL, NULL },
    { 745, 920, 0, 0, 0, 0, 69, NULL, NULL },
    { 746, 1470, 0, 0, 0, 0, 69, NULL, NULL },
    { 745, 1500, 0, 0, 0, 0, 69, NULL, NULL },
    { 747, 1540, 0, 0, 0, 83, 68, NULL, NULL },
    { 745, 1550, 0, 0, 0, 0, 69, NULL, NULL },
    { 746, 1560, 0, 0, 0, 0, 69, NULL, NULL },
    { 754, 2020, 0, 0, 0, 45, 68, NULL, NULL },
    { 746, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent190Track2[4] = {
    { 907, 1160, 201984, 61952, 0, 0, 2, NULL, NULL },
    { 908, 1205, 0, 0, 0, 0, 5, NULL, NULL },
    { 907, 1600, 0, 0, 0, 0, 5, NULL, NULL },
    { 907, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent190Track3[8] = {
    { 591, 1190, 0, 0, 0, 0, 8194, NULL, NULL },
    { 591, 1191, 197376, 58624, 0, 0, 16658, NULL, NULL },
    { 591, 1200, 189440, 65792, 0, 591, 275, NULL, NULL },
    { 591, 1203, 0, 0, 0, 0, 2, NULL, NULL },
    { 604, 1250, 185088, 75520, 0, 0, 66, NULL, NULL },
    { 591, 1264, 0, 0, 0, 0, 2, NULL, NULL },
    { 603, 1440, 185088, 75520, 0, 0, 66, NULL, NULL },
    { 591, 5000, 0, 0, 0, 0, 98309, NULL, NULL },
};

static const EventCharaTrack sEvent190Tracks[4] = {
    { sEvent190Track0, EVENT_CHARA_RIKU },
    { sEvent190Track1, EVENT_CHARA_MICKEY },
    { sEvent190Track2, EVENT_CHARA_DIZ },
    { sEvent190Track3, EVENT_CHARA_B_STATES_1 },
};

const EventSequenceDef gEvent190 = {
    ARRAY_COUNT(sEvent190Tracks),
    sEvent190Tracks,
    sEvent190Camera,
    sEvent190Script,
    sEvent190SoundCues,
    NULL,
    1640,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_191_RIKU_B1F_ENTRANCE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
