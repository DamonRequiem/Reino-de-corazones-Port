#ifdef VERSION_US
#include "event_054_text.inc"
#endif

static const MessageScriptEntry sEvent054Script[18] = {
    { PORTRAIT_RIKU, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text00), 0, 250 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text01), 0, 280 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text02), 0, 380 },
    { PORTRAIT_RIKU, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text03), 0, 420 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text04), 0, 525 },
    { PORTRAIT_RIKU, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text05), 0, 555 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text06), 0, 820 },
    { PORTRAIT_RIKU, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text07), 0, 910 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text08), 0, 940 },
    { PORTRAIT_RIKU, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text09), 0, 970 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text10), 0, 1060 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text11), 0, 1200 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text12), 0, 1230 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text13), 0, 1232 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text14), 0, 1260 },
    { PORTRAIT_RIKU, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text15), 0, 1290 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text16), 0, 1292 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent054Text17), MSG_SCRIPT_FLAG_END, 1322 },
};

#ifdef VERSION_JP
#include "event_054_text.inc"
#endif

static const EventCameraKeyframe sEvent054Camera[3] = {
    { -65535, 46592, 79872, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64456, 78848, 57600, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 120, NULL },
    { -60536, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_MEDIUM | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent054SoundCues[6] = {
    { SONG_BGM_DESTINY_FIELD, 0, 0, 0 },
    { SONG_BGM_DESTINY_FIELD, 1055, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_EV_RUMBLE, 1080, 0, 0 },
    { SONG_BGM_EVENT2, 1081, 0, 0 },
    { SONG_EV_RUMBLE, 1535, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_EVENT2, 1536, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent054Track0[38] = {
    { 4, 1, 24832, 92160, 0, 0, 66, NULL, NULL },
    { 14, 110, 71168, 68864, 0, 4, 67, NULL, NULL },
    { 4, 113, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 130, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 140, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 190, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 27, 220, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 375, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 382, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 440, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 450, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 490, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 27, 500, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 520, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 527, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 570, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 620, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 650, 0, 0, 0, 0, 69, NULL, NULL },
    { 34, 670, 0, 0, 0, 0, 69, NULL, NULL },
    { 34, 800, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 34, 920, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 930, 0, 0, 0, 0, 69, NULL, NULL },
    { 36, 990, 0, 0, 0, 0, 69, NULL, NULL },
    { 36, 1040, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 1050, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 1090, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1100, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 1110, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 1160, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 27, 1185, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1330, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 1350, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1380, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 1410, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 1430, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 1450, 0, 0, 0, 0, 69, NULL, NULL },
    { 13, 2000, 0, 0, 0, 64, 100, NULL, NULL },
    { 2, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent054Track1[12] = {
    { 515, 200, 86016, 60416, 0, 0, 66, NULL, NULL },
    { 515, 210, 0, 0, 0, 0, 5, NULL, NULL },
    { 514, 550, 0, 0, 0, 0, 5, NULL, NULL },
    { 526, 557, 0, 0, 0, 0, 5, NULL, NULL },
    { 514, 840, 0, 0, 0, 0, 5, NULL, NULL },
    { 514, 890, 0, 0, 0, 0, 0, NULL, CreateQuestionTask },
    { 514, 1100, 0, 0, 0, 0, 5, NULL, NULL },
    { 526, 1110, 0, 0, 0, 0, 5, NULL, NULL },
    { 526, 1160, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 526, 1195, 0, 0, 0, 0, 5, NULL, NULL },
    { 514, 1500, 0, 0, 0, 0, 5, NULL, NULL },
    { 520, 5000, 0, 0, 0, 173, 32772, NULL, NULL },
};

static const EventCharaTrack sEvent054Tracks[2] = {
    { sEvent054Track0, EVENT_CHARA_SORA },
    { sEvent054Track1, EVENT_CHARA_RIKU },
};

const EventSequenceDef gEvent054 = {
    ARRAY_COUNT(sEvent054Tracks),
    sEvent054Tracks,
    sEvent054Camera,
    sEvent054Script,
    sEvent054SoundCues,
    NULL,
    1540,
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
