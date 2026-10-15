#ifdef VERSION_US
#include "event_019_text.inc"
#endif

static const MessageScriptEntry sEvent019Script[8] = {
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent019Text00), 0, 250 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent019Text01), 0, 350 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent019Text02), 0, 450 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent019Text03), 0, 600 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent019Text04), 0, 660 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent019Text05), 0, 680 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent019Text06), 0, 710 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent019Text07), MSG_SCRIPT_FLAG_END, 900 },
};

#ifdef VERSION_JP
#include "event_019_text.inc"
#endif

static const EventCameraKeyframe sEvent019Camera[3] = {
    { -64966, 180736, 68608, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64656, 186368, 67072, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 20, NULL },
    { -64536, 180736, 68608, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 30, NULL },
};

static const EvSoundCue sEvent019SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent019Track0[11] = {
    { 4, 0, 133632, 98048, 0, 0, 66, NULL, NULL },
    { 9, 200, 179712, 73728, 0, 4, 67, NULL, NULL },
    { 4, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 34, 602, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 34, 610, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 660, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 30, 663, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 690, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 705, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 910, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 9999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent019Track1[15] = {
    { 114, 0, 145664, 94464, 0, 0, 66, NULL, NULL },
    { 119, 450, 0, 0, 0, 45, 68, NULL, NULL },
    { 112, 451, 221696, 60928, 0, 0, 2, NULL, NULL },
    { 117, 590, 191232, 68864, 0, 112, 3, NULL, NULL },
    { 112, 600, 0, 0, 0, 0, 5, NULL, NULL },
    { 136, 601, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 679, 0, 0, 0, 0, 5, NULL, NULL },
    { 125, 681, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 720, 0, 0, 0, 0, 5, NULL, NULL },
    { 111, 725, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 730, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 735, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 745, 0, 0, 0, 0, 69, NULL, NULL },
    { 119, 1200, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 1210, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent019Track2[2] = {
    { 146, 0, 145408, 88832, 0, 0, 66, NULL, NULL },
    { 151, 450, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaTrack sEvent019Tracks[3] = {
    { sEvent019Track0, EVENT_CHARA_SORA },
    { sEvent019Track1, EVENT_CHARA_DONALD },
    { sEvent019Track2, EVENT_CHARA_GOOFY },
};

const EventSequenceDef gEvent019 = {
    ARRAY_COUNT(sEvent019Tracks),
    sEvent019Tracks,
    sEvent019Camera,
    sEvent019Script,
    sEvent019SoundCues,
    NULL,
    950,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_MAP_4F,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
