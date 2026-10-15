#ifdef VERSION_US
#include "event_033_text.inc"
#endif

static const MessageScriptEntry sEvent033Script[19] = {
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text00), 0, 295 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text01), 0, 450 },
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text02), 0, 520 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text03), 0, 550 },
    { PORTRAIT_RIKU_REPLICA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text04), 0, 620 },
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text05), 0, 622 },
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text06), 0, 810 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text07), 0, 840 },
    { PORTRAIT_RIKU_REPLICA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text08), 0, 870 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text09), 0, 900 },
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text10), 0, 930 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text11), 0, 1025 },
    { PORTRAIT_RIKU_REPLICA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text12), 0, 1280 },
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text13), 0, 1450 },
    { PORTRAIT_RIKU_REPLICA, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text14), 0, 1452 },
    { PORTRAIT_RIKU_REPLICA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text15), 0, 1550 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text16), 0, 1880 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text17), 0, 1985 },
    { PORTRAIT_RIKU_REPLICA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent033Text18), MSG_SCRIPT_FLAG_END, 2045 },
};

#ifdef VERSION_JP
#include "event_033_text.inc"
#endif

static const EventCameraKeyframe sEvent033Camera[4] = {
    { -65326, 157184, 78336, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64186, 194560, 61440, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 80, NULL },
    { -63456, 200704, 58368, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 80, NULL },
    { -55537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_WHITE | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 20, NULL },
};

static const EvSoundCue sEvent033SoundCues[5] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_BGM_EVENT_UNREST, 210, EV_SOUND_FLAG_FADE_IN, 0 },
    { SONG_BGM_EVENT_UNREST, 1870, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_EVENT2, 1955, 0, 0 },
    { SONG_SND_359, 2015, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent033Track0[32] = {
    { 4, 1, 140544, 92416, 0, 0, 66, NULL, NULL },
    { 9, 90, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 120, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 170, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 300, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 371, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 374, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 445, 0, 0, 0, 0, 69, NULL, NULL },
    { 36, 530, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 650, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 780, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 4, 835, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 845, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 890, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 905, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 950, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1000, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 1020, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 1050, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 1180, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 30, 1200, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1250, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 1470, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1570, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 1620, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 27, 1650, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1680, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 1720, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 1850, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 16, 1910, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1940, 0, 0, 0, 0, 69, NULL, NULL },
    { 19, 3000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent033Track1[10] = {
    { 114, 1, 136960, 100352, 0, 0, 66, NULL, NULL },
    { 119, 90, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 125, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 175, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 114, 300, 0, 0, 0, 0, 69, NULL, NULL },
    { 120, 385, 0, 0, 0, 45, 100, NULL, NULL },
    { 114, 388, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 2060, 0, 0, 0, 0, 69, NULL, NULL },
    { 122, 2075, 0, 0, 0, 0, 69, NULL, NULL },
    { 123, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent033Track2[10] = {
    { 146, 1, 129024, 94720, 0, 0, 66, NULL, NULL },
    { 151, 90, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 130, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 180, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 146, 300, 0, 0, 0, 0, 69, NULL, NULL },
    { 153, 408, 0, 0, 0, 45, 100, NULL, NULL },
    { 146, 411, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 2063, 0, 0, 0, 0, 69, NULL, NULL },
    { 157, 2078, 0, 0, 0, 0, 69, NULL, NULL },
    { 158, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent033Track3[16] = {
    { 695, 470, 206080, 60928, 0, 0, 2, NULL, NULL },
    { 696, 480, 0, 0, 0, 0, 5, NULL, NULL },
    { 696, 570, 0, 0, 0, 0, 69, NULL, NULL },
    { 696, 580, 0, 0, 0, 0, 5, NULL, NULL },
    { 695, 1230, 0, 0, 0, 0, 5, NULL, NULL },
    { 707, 1290, 0, 0, 0, 0, 5, NULL, NULL },
    { 695, 1300, 0, 0, 0, 0, 5, NULL, NULL },
    { 696, 1310, 0, 0, 0, 0, 5, NULL, NULL },
    { 696, 1350, 0, 0, 0, 0, 69, NULL, NULL },
    { 712, 1400, 0, 0, 0, 45, 68, NULL, NULL },
    { 696, 1430, 0, 0, 0, 0, 69, NULL, NULL },
    { 708, 1451, 0, 0, 0, 0, 69, NULL, NULL },
    { 696, 1500, 0, 0, 0, 0, 69, NULL, NULL },
    { 696, 1510, 0, 0, 0, 0, 5, NULL, NULL },
    { 695, 2015, 0, 0, 0, 0, 5, NULL, NULL },
    { 698, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent033Tracks[4] = {
    { sEvent033Track0, EVENT_CHARA_SORA },
    { sEvent033Track1, EVENT_CHARA_DONALD },
    { sEvent033Track2, EVENT_CHARA_GOOFY },
    { sEvent033Track3, EVENT_CHARA_RIKU_REPLICA },
};

const EventSequenceDef gEvent033 = {
    ARRAY_COUNT(sEvent033Tracks),
    sEvent033Tracks,
    sEvent033Camera,
    sEvent033Script,
    sEvent033SoundCues,
    NULL,
    2125,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_RIKU_2,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
