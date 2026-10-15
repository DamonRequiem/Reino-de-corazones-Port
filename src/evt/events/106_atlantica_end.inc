#ifdef VERSION_US
#include "event_106_text.inc"
#endif

static const MessageScriptEntry sEvent106Script[20] = {
    { PORTRAIT_FLOUNDER, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text00), 0, 150 },
    { PORTRAIT_ARIEL, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text01), 0, 170 },
    { PORTRAIT_ARIEL, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text02), 0, 172 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text03), 0, 200 },
    { PORTRAIT_ARIEL, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text04), 0, 240 },
    { PORTRAIT_SEBASTIAN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text05), 0, 270 },
    { PORTRAIT_SEBASTIAN, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text06), 0, 272 },
    { PORTRAIT_ARIEL, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text07), 0, 370 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text08), 0, 390 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text09), 0, 460 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text10), 0, 462 },
    { PORTRAIT_ARIEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text11), 0, 490 },
    { PORTRAIT_ARIEL, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text12), 0, 492 },
    { PORTRAIT_ARIEL, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text13), 0, 590 },
    { PORTRAIT_ARIEL, 5, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text14), 0, 592 },
    { PORTRAIT_ARIEL, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text15), 0, 640 },
    { PORTRAIT_ARIEL, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text16), 0, 642 },
    { PORTRAIT_ARIEL, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text17), 0, 680 },
    { PORTRAIT_JIMINY_CRICKET, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text18), 0, 870 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent106Text19), MSG_SCRIPT_FLAG_END, 910 },
};

#ifdef VERSION_JP
#include "event_106_text.inc"
#endif

static const EventCameraKeyframe sEvent106Camera[1] = {
    { -64626, 45056, 38144, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent106SoundCues[2] = {
    { SONG_BGM_EVENT4, 0, 0, 0 },
    { SONG_BGM_EVENT4, 965, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent106Track0[6] = {
    { 464, 210, 44288, 40192, -2560, 0, 66, NULL, NULL },
    { 464, 280, 0, 0, 0, 0, 5, NULL, NULL },
    { 464, 350, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 464, 360, 0, 0, 0, 0, 5, NULL, NULL },
    { 464, 470, 0, 0, 0, 0, 69, NULL, NULL },
    { 464, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent106Track1[10] = {
    { 316, 210, 48896, 43008, 0, 0, 2, NULL, NULL },
    { 314, 280, 0, 0, 0, 0, 5, NULL, NULL },
    { 314, 350, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 314, 360, 0, 0, 0, 0, 5, NULL, NULL },
    { 314, 369, 0, 0, 0, 0, 69, NULL, NULL },
    { 322, 371, 0, 0, 0, 0, 69, NULL, NULL },
    { 314, 470, 0, 0, 0, 0, 69, NULL, NULL },
    { 314, 610, 0, 0, 0, 0, 5, NULL, NULL },
    { 316, 660, 0, 0, 0, 0, 5, NULL, NULL },
    { 314, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent106Track2[8] = {
    { 4, 459, 36608, 45312, 0, 0, 66, NULL, NULL },
    { 30, 463, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 500, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 580, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 4, 710, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 840, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 4, 905, 0, 0, 0, 0, 69, NULL, NULL },
    { 36, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent106Track3[1] = {
    { 112, 999, 54784, 34560, 0, 0, 32770, NULL, NULL },
};

static const EventCharaKeyframe sEvent106Track4[3] = {
    { 144, 389, 36096, 35072, 0, 0, 66, NULL, NULL },
    { 164, 391, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent106Track5[4] = {
    { 231, 620, 32256, 41984, 0, 0, 66, NULL, NULL },
    { 229, 860, 0, 0, 0, 0, 69, NULL, NULL },
    { 233, 872, 0, 0, 0, 0, 64, EventCharaHop, NULL },
    { 229, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent106Tracks[6] = {
    { sEvent106Track0, EVENT_CHARA_FLOUNDER },
    { sEvent106Track1, EVENT_CHARA_ARIEL },
    { sEvent106Track2, EVENT_CHARA_SORA },
    { sEvent106Track3, EVENT_CHARA_DONALD },
    { sEvent106Track4, EVENT_CHARA_GOOFY },
    { sEvent106Track5, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent106 = {
    ARRAY_COUNT(sEvent106Tracks),
    sEvent106Tracks,
    sEvent106Camera,
    sEvent106Script,
    sEvent106SoundCues,
    NULL,
    970,
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
