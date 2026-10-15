#ifdef VERSION_US
#include "event_177_text.inc"
#endif

static const MessageScriptEntry sEvent177Script[8] = {
    { PORTRAIT_RIKU, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent177Text00), 0, 380 },
    { PORTRAIT_RIKU, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent177Text01), 0, 460 },
    { PORTRAIT_RIKU, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent177Text02), 0, 462 },
    { PORTRAIT_RIKU, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent177Text03), 0, 660 },
    { PORTRAIT_RIKU, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent177Text04), 0, 800 },
    { PORTRAIT_RIKU, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent177Text05), 0, 980 },
    { PORTRAIT_RIKU, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent177Text06), 0, 1080 },
    { PORTRAIT_RIKU, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent177Text07), MSG_SCRIPT_FLAG_END, 1405 },
};

#ifdef VERSION_JP
#include "event_177_text.inc"
#endif

static const EvSoundCue sEvent177SoundCues[5] = {
    { SONG_BGM_DESTINY_FIELD, 0, 0, 0 },
    { SONG_SND_356, 1, 0, 0 },
    { SONG_SND_370, 1280, 0, 0 },
    { SONG_SND_356, 1585, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_DESTINY_FIELD, 1586, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent177Camera[7] = {
    { -65536, 96768, 77312, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -65385, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 80, NULL },
    { -64846, 0, 0, -6912, EVENT_CHARA_RIKU, 0, 0, NULL },
    { -64666, 31744, 42752, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 100, NULL },
    { -63986, 34560, 45312, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 30, NULL },
    { -62536, 47104, 51968, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 100, NULL },
    { -60536, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EventCharaKeyframe sEvent177Track0[24] = {
    { 515, 1, 130816, 102656, 0, 0, 2, NULL, NULL },
    { 518, 150, 96768, 84224, 0, 515, 3, NULL, NULL },
    { 515, 200, 0, 0, 0, 0, 5, NULL, NULL },
    { 540, 330, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 540, 382, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 400, 0, 0, 0, 0, 5, NULL, NULL },
    { 518, 430, 0, 0, 0, 211, 4, NULL, NULL },
    { 515, 500, 0, 0, 0, 0, 5, NULL, NULL },
    { 518, 580, 0, 0, 0, 211, 4, NULL, NULL },
    { 532, 600, 0, 0, 0, 0, 5, NULL, NULL },
    { 532, 650, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 532, 665, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 810, 0, 0, 0, 0, 5, NULL, NULL },
    { 522, 880, 0, 0, 0, 211, 36, NULL, NULL },
    { 515, 883, 0, 0, 0, 211, 4, NULL, NULL },
    { 515, 900, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 950, 0, 0, 0, 0, 0, NULL, CreateQuestionTask },
    { 515, 1320, 0, 0, 0, 0, 5, NULL, NULL },
    { 532, 1330, 0, 0, 0, 0, 5, NULL, NULL },
    { 532, 1380, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 515, 1400, 0, 0, 0, 0, 5, NULL, NULL },
    { 538, 1407, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 1500, 0, 0, 0, 0, 5, NULL, NULL },
    { 540, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent177Track1[6] = {
    { 676, 1100, 25600, 45312, 0, 0, 66, NULL, NULL },
    { 676, 1230, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 676, 1280, 0, 0, 0, 0, 69, NULL, NULL },
    { 676, 1350, 0, 0, 0, 0, 64, EventCharaFadeOut, NULL },
    { 676, 2000, 120320, 146176, 0, 0, 66, NULL, NULL },
    { 676, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent177Track2[6] = {
    { 627, 1100, 35584, 50432, 0, 0, 66, NULL, NULL },
    { 627, 1230, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 627, 1280, 0, 0, 0, 0, 69, NULL, NULL },
    { 627, 1350, 0, 0, 0, 0, 64, EventCharaFadeOut, NULL },
    { 627, 2000, 120320, 146176, 0, 0, 66, NULL, NULL },
    { 627, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent177Track3[6] = {
    { 678, 1100, 27392, 53248, 0, 0, 66, NULL, NULL },
    { 678, 1230, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 678, 1280, 0, 0, 0, 0, 69, NULL, NULL },
    { 678, 1350, 0, 0, 0, 0, 64, EventCharaFadeOut, NULL },
    { 678, 2000, 120320, 146176, 0, 0, 66, NULL, NULL },
    { 678, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent177Tracks[4] = {
    { sEvent177Track0, EVENT_CHARA_RIKU },
    { sEvent177Track1, EVENT_CHARA_WAKKA },
    { sEvent177Track2, EVENT_CHARA_SELPHIE },
    { sEvent177Track3, EVENT_CHARA_TIDUS },
};

const EventSequenceDef gEvent177 = {
    ARRAY_COUNT(sEvent177Tracks),
    sEvent177Tracks,
    sEvent177Camera,
    sEvent177Script,
    sEvent177SoundCues,
    NULL,
    1590,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    1,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
