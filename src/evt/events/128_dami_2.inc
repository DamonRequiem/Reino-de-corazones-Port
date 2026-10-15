#ifndef VERSION_EU
#ifdef VERSION_US
static const MessageScriptEntry sEvent128Script[4] = {
    { PORTRAIT_AERITH, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, gEvent128Text00, 0, 150 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent128Text01, 0, 180 },
    { PORTRAIT_AERITH, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, gEvent128Text02, 0, 210 },
    { PORTRAIT_AERITH, 0, MSG_WIN_POSITION_KEEP, 1, gEvent128Text03, MSG_SCRIPT_FLAG_END, 240 },
};

#include "event_128_text.inc"
#endif
#ifdef VERSION_JP
static const MessageScriptEntry sEvent128Script[4] = {
    { PORTRAIT_AERITH, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 3, gEvent128Text00, 0, 150 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent128Text01, 0, 180 },
    { PORTRAIT_AERITH, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 3, gEvent128Text02, 0, 210 },
    { PORTRAIT_AERITH, 0, MSG_WIN_POSITION_KEEP, 3, gEvent128Text03, MSG_SCRIPT_FLAG_END, 240 },
};

#include "event_128_text.inc"
#endif
static const EventCameraKeyframe sEvent128Camera[1] = {
    { -55537, 80384, 58368, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent128SoundCues[1] = {
    { SONG_BGM_TOWN_FIELD, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent128Track0[1] = {
    { 4, 9999, 72960, 68096, 0, 0, 32834, NULL, NULL },
};

static const EventCharaKeyframe sEvent128Track1[1] = {
    { 451, 9999, 82432, 63232, 0, 0, 32770, NULL, NULL },
};

static const EventCharaKeyframe sEvent128Track2[1] = {
    { 638, 9999, 98304, 67840, 0, 0, 32770, NULL, NULL },
};

static const EventCharaKeyframe sEvent128Track3[1] = {
    { 684, 9999, 64512, 62464, 0, 0, 32834, NULL, NULL },
};

static const EventCharaKeyframe sEvent128Track4[1] = {
    { 114, 9999, 68352, 75264, 0, 0, 32834, NULL, NULL },
};

static const EventCharaKeyframe sEvent128Track5[1] = {
    { 146, 9999, 57088, 72448, 0, 0, 32834, NULL, NULL },
};

static const EventCharaTrack sEvent128Tracks[6] = {
    { sEvent128Track0, EVENT_CHARA_SORA },
    { sEvent128Track1, EVENT_CHARA_AERITH },
    { sEvent128Track2, EVENT_CHARA_LEON },
    { sEvent128Track3, EVENT_CHARA_YUFFIE },
    { sEvent128Track4, EVENT_CHARA_DONALD },
    { sEvent128Track5, EVENT_CHARA_GOOFY },
};

const EventSequenceDef gEvent128 = {
    ARRAY_COUNT(sEvent128Tracks),
    sEvent128Tracks,
    sEvent128Camera,
    sEvent128Script,
    sEvent128SoundCues,
    NULL,
    350,
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
