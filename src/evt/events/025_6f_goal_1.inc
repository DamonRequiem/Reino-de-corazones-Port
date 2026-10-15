#ifdef VERSION_US
#include "event_025_text.inc"
#endif

static const MessageScriptEntry sEvent025Script[11] = {
    { PORTRAIT_DONALD, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent025Text00), 0, 350 },
    { PORTRAIT_LARXENE, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent025Text01), 0, 370 },
    { PORTRAIT_LARXENE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent025Text02), 0, 470 },
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent025Text03), 0, 472 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent025Text04), 0, 490 },
    { PORTRAIT_LARXENE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent025Text05), 0, 510 },
    { PORTRAIT_LARXENE, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent025Text06), 0, 540 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent025Text07), 0, 610 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent025Text08), 0, 630 },
    { PORTRAIT_LARXENE, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent025Text09), 0, 660 },
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent025Text10), MSG_SCRIPT_FLAG_END, 662 },
};

#ifdef VERSION_JP
#include "event_025_text.inc"
#endif

static const EventCameraKeyframe sEvent025Camera[6] = {
    { -65536, 140032, 86784, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65281, 171264, 70912, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 180, NULL },
    { -65116, 211456, 52736, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 40, NULL },
    { -64846, 182528, 65536, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 40, NULL },
    { -64826, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_WHITE | CAMERA_MODE_KEEP, 10, NULL },
    { -64036, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent025SoundCues[2] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_BGM_EVENT_XIII, 375, EV_SOUND_FLAG_FADE_IN | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent025Track0[26] = {
    { 856, 380, 213504, 57344, 0, 0, 2, NULL, NULL },
    { 881, 450, 0, 0, 0, 173, 4, NULL, NULL },
    { 856, 520, 0, 0, 0, 0, 5, NULL, NULL },
    { 856, 530, 0, 0, 0, 0, 69, NULL, NULL },
    { 878, 611, 0, 0, 0, 0, 69, NULL, NULL },
    { 879, 631, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 879, 632, 0, 0, 0, 0, 69, NULL, NULL },
    { 880, 640, 0, 0, 0, 0, 69, NULL, NULL },
    { 856, 650, 0, 0, 0, 0, 69, NULL, NULL },
    { 857, 670, 0, 0, 0, 0, 5, NULL, NULL },
    { 862, 675, 0, 0, 0, 173, 4, NULL, NULL },
    { 863, 685, 0, 0, 0, 173, 36, NULL, NULL },
    { 863, 720, 146176, 91392, 0, 856, 3, NULL, NULL },
    { 864, 750, 0, 0, 0, 0, 5, NULL, NULL },
    { 856, 760, 0, 0, 0, 0, 69, NULL, NULL },
    { 876, 955, 0, 0, 0, 0, 69, NULL, NULL },
    { 876, 1050, 0, 0, 0, 0, 69, NULL, NULL },
    { 882, 1090, 0, 0, 0, 45, 68, NULL, NULL },
    { 876, 1420, 0, 0, 0, 0, 69, NULL, NULL },
    { 882, 1450, 0, 0, 0, 45, 68, EventCharaFadeOut, NULL },
    { 876, 1481, 0, 0, 0, 0, 66, NULL, NULL },
    { 856, 1520, 184576, 67840, 0, 0, 2, EventCharaFadeIn, NULL },
    { 856, 1550, 0, 0, 0, 0, 5, NULL, NULL },
    { 868, 1595, 0, 0, 0, 0, 5, NULL, NULL },
    { 870, 1619, 195328, 65280, 0, 856, 4099, NULL, NULL },
    { 870, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent025Track1[21] = {
    { 4, 0, 129536, 98304, 0, 0, 66, NULL, NULL },
    { 9, 200, 174592, 74752, 0, 4, 67, NULL, NULL },
    { 4, 205, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 260, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 550, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 600, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 30, 640, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 690, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 710, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 68, 815, 0, 0, 0, 0, 69, NULL, NULL },
    { 80, 900, 0, 0, 0, 0, 69, NULL, NULL },
    { 81, 960, 0, 0, 0, 0, 69, NULL, NULL },
    { 81, 1090, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 81, 1110, 0, 0, 0, 0, 69, NULL, NULL },
    { 80, 1250, 0, 0, 0, 0, 69, NULL, NULL },
    { 68, 1380, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 80, 1520, 0, 0, 0, 0, 69, NULL, NULL },
    { 82, 1595, 0, 0, 0, 0, 69, NULL, NULL },
    { 19, 1605, 179968, 69888, 0, 4, 67, NULL, NULL },
    { 21, 1620, 0, 0, 0, 0, 69, NULL, NULL },
    { 21, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent025Track2[15] = {
    { 114, 0, 128768, 105728, 0, 0, 66, NULL, NULL },
    { 119, 200, 174080, 82944, 0, 114, 67, NULL, NULL },
    { 114, 205, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 260, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 114, 690, 0, 0, 0, 0, 69, NULL, NULL },
    { 133, 820, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 120, 840, 0, 0, 0, 45, 100, NULL, NULL },
    { 114, 842, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 850, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 855, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1550, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 1555, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1560, 0, 0, 0, 0, 69, NULL, NULL },
    { 122, 1570, 0, 0, 0, 0, 69, NULL, NULL },
    { 123, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent025Track3[14] = {
    { 146, 0, 116992, 98560, 0, 0, 66, NULL, NULL },
    { 151, 200, 162304, 75520, 0, 146, 67, NULL, NULL },
    { 146, 205, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 260, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 146, 690, 0, 0, 0, 0, 69, NULL, NULL },
    { 161, 820, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 153, 847, 167168, 69120, 0, 146, 67, NULL, NULL },
    { 146, 855, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 860, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 1550, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 1555, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 1560, 0, 0, 0, 0, 69, NULL, NULL },
    { 157, 1570, 0, 0, 0, 0, 69, NULL, NULL },
    { 158, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent025Tracks[4] = {
    { sEvent025Track0, EVENT_CHARA_LARXENE },
    { sEvent025Track1, EVENT_CHARA_SORA },
    { sEvent025Track2, EVENT_CHARA_DONALD },
    { sEvent025Track3, EVENT_CHARA_GOOFY },
};

const EventSequenceDef gEvent025 = {
    ARRAY_COUNT(sEvent025Tracks),
    sEvent025Tracks,
    sEvent025Camera,
    sEvent025Script,
    sEvent025SoundCues,
    NULL,
    770,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_MOVIE_6F_GOAL,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
