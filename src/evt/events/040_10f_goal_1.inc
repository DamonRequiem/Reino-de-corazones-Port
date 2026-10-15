#ifdef VERSION_US
#include "event_040_text.inc"
#endif

static const MessageScriptEntry sEvent040Script[12] = {
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text00), 0, 335 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text01), 0, 365 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text02), 0, 367 },
    { PORTRAIT_GOOFY, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text03), 0, 405 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text04), 0, 460 },
    { PORTRAIT_VEXEN, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text05), 0, 490 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text06), 0, 650 },
    { PORTRAIT_VEXEN, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text07), 0, 680 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text08), 0, 720 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text09), 0, 820 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text10), 0, 850 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent040Text11), MSG_SCRIPT_FLAG_END, 852 },
};

#ifdef VERSION_JP
#include "event_040_text.inc"
#endif

static const EventCameraKeyframe sEvent040Camera[2] = {
    { -65296, 165376, 73728, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -62536, 190208, 60672, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 50, NULL },
};

static const EvSoundCue sEvent040SoundCues[4] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_BGM_EVENT_XIII, 360, EV_SOUND_FLAG_FADE_IN, 0 },
    { SONG_BGM_EVENT_XIII, 700, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_EVENT2, 825, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent040Track0[26] = {
    { 4, 1, 137216, 95488, 0, 0, 66, NULL, NULL },
    { 9, 150, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 210, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 270, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 305, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 308, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 330, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 340, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 420, 0, 0, 0, 0, 69, NULL, NULL },
    { 0, 425, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 430, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 435, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 510, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 560, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 2, 580, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 585, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 590, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 600, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 650, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 660, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 710, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 800, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 815, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 830, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent040Track1[8] = {
    { 114, 5, 133632, 103168, 0, 0, 66, NULL, NULL },
    { 119, 155, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 210, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 114, 270, 0, 0, 0, 0, 69, NULL, NULL },
    { 120, 318, 0, 0, 0, 45, 100, NULL, NULL },
    { 114, 321, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent040Track2[12] = {
    { 146, 8, 123136, 96256, 0, 0, 66, NULL, NULL },
    { 151, 158, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 210, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 146, 270, 0, 0, 0, 0, 69, NULL, NULL },
    { 153, 325, 0, 0, 0, 45, 100, NULL, NULL },
    { 146, 328, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 380, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 400, 0, 0, 0, 0, 69, NULL, NULL },
    { 167, 407, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 590, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent040Track3[2] = {
    { 721, 30, 202496, 61184, 0, 0, 2, NULL, NULL },
    { 721, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent040Tracks[4] = {
    { sEvent040Track0, EVENT_CHARA_SORA },
    { sEvent040Track1, EVENT_CHARA_DONALD },
    { sEvent040Track2, EVENT_CHARA_GOOFY },
    { sEvent040Track3, EVENT_CHARA_VEXEN },
};

const EventSequenceDef gEvent040 = {
    ARRAY_COUNT(sEvent040Tracks),
    sEvent040Tracks,
    sEvent040Camera,
    sEvent040Script,
    sEvent040SoundCues,
    NULL,
    910,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_VEXEN_1,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
