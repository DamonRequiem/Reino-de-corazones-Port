#ifdef VERSION_US
#include "event_081_text.inc"
#endif

static const MessageScriptEntry sEvent081Script[4] = {
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent081Text00), 0, 300 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent081Text01), 0, 310 },
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent081Text02), 0, 320 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent081Text03), MSG_SCRIPT_FLAG_END, 330 },
};

#ifdef VERSION_JP
#include "event_081_text.inc"
#endif

static const EventCameraKeyframe sEvent081Camera[1] = {
    { -64537, 33792, 32768, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent081SoundCues[1] = {
    { SONG_BGM_EVENT1, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent081Track0[16] = {
    { 12, 0, 71168, 23040, 0, 0, 2, NULL, NULL },
    { 12, 120, 0, 0, 0, 173, 36, NULL, NULL },
    { 2, 124, 0, 0, 0, 173, 4, NULL, NULL },
    { 2, 135, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 140, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 145, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 150, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 155, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 205, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 230, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 240, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 260, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 280, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 230, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 335, 0, 0, 0, 0, 69, NULL, NULL },
    { 19, 400, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent081Track1[18] = {
    { 152, 0, 72192, 15872, 0, 0, 2, NULL, NULL },
    { 152, 190, 0, 0, 0, 173, 36, NULL, NULL },
    { 144, 194, 0, 0, 0, 173, 4, NULL, NULL },
    { 144, 188, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 195, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 199, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 220, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 240, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 260, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 280, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 299, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 301, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 311, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 331, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 380, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 157, 395, 0, 0, 0, 0, 69, NULL, NULL },
    { 158, 500, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent081Track2[18] = {
    { 121, 0, 90880, 21504, 0, 0, 2, NULL, NULL },
    { 121, 160, 0, 0, 0, 173, 36, NULL, NULL },
    { 121, 164, 0, 0, 0, 173, 4, NULL, NULL },
    { 112, 170, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 175, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 195, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 215, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 245, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 265, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 280, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 319, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 321, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 341, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 350, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 380, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 122, 395, 0, 0, 0, 0, 69, NULL, NULL },
    { 123, 490, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent081Track3[3] = {
    { 472, 348, 78848, 20480, 0, 0, 258, NULL, NULL },
    { 474, 505, 0, 0, 0, 173, 260, NULL, NULL },
    { 472, 999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent081Track4[3] = {
    { 472, 340, 79872, 13312, 0, 0, 258, NULL, NULL },
    { 474, 500, 0, 0, 0, 173, 260, NULL, NULL },
    { 472, 999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent081Track5[3] = {
    { 472, 346, 89600, 21504, 0, 0, 258, NULL, NULL },
    { 474, 508, 0, 0, 0, 173, 260, NULL, NULL },
    { 472, 999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent081Track6[3] = {
    { 472, 388, 78848, 20480, 0, 0, 258, NULL, NULL },
    { 474, 505, 0, 0, 0, 173, 260, NULL, NULL },
    { 472, 999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent081Track7[3] = {
    { 472, 380, 79872, 13312, 0, 0, 258, NULL, NULL },
    { 474, 500, 0, 0, 0, 173, 260, NULL, NULL },
    { 472, 999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent081Track8[3] = {
    { 472, 386, 89600, 21504, 0, 0, 258, NULL, NULL },
    { 474, 508, 0, 0, 0, 173, 260, NULL, NULL },
    { 472, 999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaTrack sEvent081Tracks[9] = {
    { sEvent081Track0, EVENT_CHARA_SORA },
    { sEvent081Track1, EVENT_CHARA_GOOFY },
    { sEvent081Track2, EVENT_CHARA_DONALD },
    { sEvent081Track3, EVENT_CHARA_SHADOW },
    { sEvent081Track4, EVENT_CHARA_SHADOW },
    { sEvent081Track5, EVENT_CHARA_SHADOW },
    { sEvent081Track6, EVENT_CHARA_SHADOW },
    { sEvent081Track7, EVENT_CHARA_SHADOW },
    { sEvent081Track8, EVENT_CHARA_SHADOW },
};

const EventSequenceDef gEvent081 = {
    ARRAY_COUNT(sEvent081Tracks),
    sEvent081Tracks,
    sEvent081Camera,
    sEvent081Script,
    sEvent081SoundCues,
    NULL,
    560,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_SHADOW_100,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
