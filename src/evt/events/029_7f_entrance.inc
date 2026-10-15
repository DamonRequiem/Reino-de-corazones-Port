#ifdef VERSION_US
#include "event_029_text.inc"
#endif

static const MessageScriptEntry sEvent029Script[6] = {
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent029Text00), 0, 130 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent029Text01), 0, 180 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent029Text02), 0, 510 },
    { PORTRAIT_DONALD, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent029Text03), 0, 540 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent029Text04), 0, 542 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent029Text05), MSG_SCRIPT_FLAG_END, 570 },
};

#ifdef VERSION_JP
#include "event_029_text.inc"
#endif

static const EventCameraKeyframe sEvent029Camera[2] = {
    { -65176, 165120, 78336, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64537, 152320, 83712, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 40, NULL },
};

static const EvSoundCue sEvent029SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent029Track0[15] = {
    { 4, 1, 118784, 104448, 0, 0, 66, NULL, NULL },
    { 14, 140, 164608, 82176, 0, 4, 67, NULL, NULL },
    { 4, 150, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 155, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 165, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 179, 0, 0, 0, 0, 5, NULL, NULL },
    { 31, 181, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 190, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 195, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 200, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 205, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 220, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 400, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 1000, 0, 0, 0, 0, 98373, NULL, NULL },
};

static const EventCharaKeyframe sEvent029Track1[11] = {
    { 114, 280, 120064, 108544, 0, 0, 66, NULL, NULL },
    { 120, 380, 154624, 89600, 0, 114, 67, NULL, NULL },
    { 114, 382, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 520, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 525, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 539, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 543, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 580, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 585, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 119, 700, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent029Track2[13] = {
    { 146, 280, 114944, 103936, 0, 0, 66, NULL, NULL },
    { 153, 390, 145152, 87296, 0, 146, 67, NULL, NULL },
    { 146, 392, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 509, 0, 0, 0, 0, 69, NULL, NULL },
    { 165, 511, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 550, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 555, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 569, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 571, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 580, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 585, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 151, 700, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaTrack sEvent029Tracks[3] = {
    { sEvent029Track0, EVENT_CHARA_SORA },
    { sEvent029Track1, EVENT_CHARA_DONALD },
    { sEvent029Track2, EVENT_CHARA_GOOFY },
};

const EventSequenceDef gEvent029 = {
    ARRAY_COUNT(sEvent029Tracks),
    sEvent029Tracks,
    sEvent029Camera,
    sEvent029Script,
    sEvent029SoundCues,
    NULL,
    650,
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
