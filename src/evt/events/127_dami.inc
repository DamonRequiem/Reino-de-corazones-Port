#ifndef VERSION_EU
#ifdef VERSION_US
static const MessageScriptEntry sEvent127Script[7] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent127Text00, 0, 150 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, gEvent127Text01, 0, 180 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_KEEP, 1, gEvent127Text02, 0, 185 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, gEvent127Text03, 0, 300 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent127Text04, 0, 330 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, gEvent127Text05, 0, 360 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_KEEP, 1, gEvent127Text06, MSG_SCRIPT_FLAG_END, 360 },
};

#include "event_127_text.inc"
#endif
#ifdef VERSION_JP
static const MessageScriptEntry sEvent127Script[7] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent127Text00, 0, 150 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 3, gEvent127Text01, 0, 180 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_KEEP, 3, gEvent127Text02, 0, 185 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 3, gEvent127Text03, 0, 300 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent127Text04, 0, 330 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 3, gEvent127Text05, 0, 360 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_KEEP, 3, gEvent127Text06, MSG_SCRIPT_FLAG_END, 360 },
};

#include "event_127_text.inc"
#endif
static const EventCameraKeyframe sEvent127Camera[1] = {
    { -55537, 66304, 66560, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent127SoundCues[1] = {
    { SONG_BGM_TOWN_FIELD, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent127Track0[7] = {
    { 4, 100, 57344, 75008, 0, 0, 66, NULL, NULL },
    { 27, 182, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 235, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 285, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 325, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 450, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent127Track1[1] = {
    { 114, 9999, 63744, 78592, 0, 0, 32834, NULL, NULL },
};

static const EventCharaKeyframe sEvent127Track2[1] = {
    { 146, 9999, 46848, 79616, 0, 0, 32834, NULL, NULL },
};

static const EventCharaKeyframe sEvent127Track3[1] = {
    { 638, 9999, 70144, 67328, 0, 0, 32770, NULL, NULL },
};

static const EventCharaTrack sEvent127Tracks[4] = {
    { sEvent127Track0, EVENT_CHARA_SORA },
    { sEvent127Track1, EVENT_CHARA_DONALD },
    { sEvent127Track2, EVENT_CHARA_GOOFY },
    { sEvent127Track3, EVENT_CHARA_LEON },
};

const EventSequenceDef gEvent127 = {
    ARRAY_COUNT(sEvent127Tracks),
    sEvent127Tracks,
    sEvent127Camera,
    sEvent127Script,
    sEvent127SoundCues,
    NULL,
    600,
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
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
#endif
