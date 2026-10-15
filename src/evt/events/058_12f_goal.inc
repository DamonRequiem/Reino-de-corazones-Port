#ifdef VERSION_US
#include "event_058_text.inc"
#endif

static const MessageScriptEntry sEvent058Script[12] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text00), 0, 160 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text01), 0, 450 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text02), 0, 452 },
    { PORTRAIT_NAMINE, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text03), 0, 500 },
    { PORTRAIT_NAMINE, 4, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text04), 0, 502 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text05), 0, 535 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text06), 0, 539 },
    { PORTRAIT_NAMINE, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text07), 0, 560 },
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text08), 0, 580 },
    { PORTRAIT_RIKU_REPLICA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text09), 0, 810 },
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text10), 0, 812 },
    { PORTRAIT_RIKU_REPLICA, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent058Text11), MSG_SCRIPT_FLAG_END, 814 },
};

#ifdef VERSION_JP
#include "event_058_text.inc"
#endif

static const EventCameraKeyframe sEvent058Camera[3] = {
    { -65336, 171264, 71424, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64836, 178432, 68864, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 50, NULL },
    { -60536, 183296, 70144, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 50, NULL },
};

static const EvSoundCue sEvent058SoundCues[3] = {
    { SONG_BGM_T13THFLOOR, 0, 0, 0 },
    { SONG_BGM_T13THFLOOR, 575, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_SND_359, 830, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent058Track0[17] = {
    { 4, 1, 140800, 92160, 0, 0, 66, NULL, NULL },
    { 9, 80, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 100, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 150, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 170, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 200, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 203, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 280, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 410, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 16, 440, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 537, 0, 0, 0, 0, 69, NULL, NULL },
    { 34, 590, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 650, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 780, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 840, 0, 0, 0, 0, 69, NULL, NULL },
    { 18, 2000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent058Track1[14] = {
    { 423, 160, 182528, 71168, 0, 0, 66, NULL, NULL },
    { 425, 170, 0, 0, 0, 0, 69, NULL, NULL },
    { 422, 190, 0, 0, 0, 0, 69, NULL, NULL },
    { 422, 470, 0, 0, 0, 0, 5, NULL, NULL },
    { 423, 488, 0, 0, 0, 0, 5, NULL, NULL },
    { 425, 498, 0, 0, 0, 0, 5, NULL, NULL },
    { 422, 501, 0, 0, 0, 0, 5, NULL, NULL },
    { 423, 600, 0, 0, 0, 0, 5, NULL, NULL },
    { 423, 650, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 425, 670, 0, 0, 0, 0, 5, NULL, NULL },
    { 422, 680, 0, 0, 0, 0, 69, NULL, NULL },
    { 428, 760, 0, 0, 0, 0, 69, NULL, NULL },
    { 422, 880, 0, 0, 0, 0, 69, NULL, NULL },
    { 422, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent058Track2[5] = {
    { 695, 700, 0, 0, 0, 0, 2, NULL, NULL },
    { 695, 701, 212480, 64000, 0, 0, 2, NULL, NULL },
    { 711, 800, 0, 0, 0, 173, 4, NULL, NULL },
    { 695, 830, 0, 0, 0, 0, 5, NULL, NULL },
    { 698, 1845, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent058Tracks[3] = {
    { sEvent058Track0, EVENT_CHARA_SORA },
    { sEvent058Track1, EVENT_CHARA_NAMINE },
    { sEvent058Track2, EVENT_CHARA_RIKU_REPLICA },
};

const EventSequenceDef gEvent058 = {
    ARRAY_COUNT(sEvent058Tracks),
    sEvent058Tracks,
    sEvent058Camera,
    sEvent058Script,
    sEvent058SoundCues,
    NULL,
    920,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_RIKU_4,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
