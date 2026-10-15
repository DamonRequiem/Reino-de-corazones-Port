#ifdef VERSION_US
#include "event_068_text.inc"
#endif

static const MessageScriptEntry sEvent068Script[2] = {
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent068Text00), 0, 100 },
    { PORTRAIT_GOOFY, 4, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent068Text01), MSG_SCRIPT_FLAG_YES_NO | MSG_SCRIPT_FLAG_END, 130 },
};

#ifdef VERSION_JP
#include "event_068_text.inc"
#endif

static const EventCameraKeyframe sEvent068Camera[3] = {
    { -65206, 216576, 51968, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65166, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_WHITE | CAMERA_MODE_KEEP, 60, NULL },
    { -55537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent068SoundCues[2] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_EV_WHITEOUT, 330, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent068Track0[3] = {
    { 4, 240, 214016, 59392, 0, 0, 66, NULL, NULL },
    { 16, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent068Track1[3] = {
    { 114, 95, 205568, 58880, 0, 0, 66, NULL, NULL },
    { 126, 105, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent068Track2[3] = {
    { 146, 125, 217088, 68096, 0, 0, 66, NULL, NULL },
    { 165, 135, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent068Track3[2] = {
    { 428, 30, 199936, 54528, 0, 0, 66, NULL, NULL },
    { 428, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent068Track4[2] = {
    { 696, 30, 228352, 67328, 0, 0, 66, NULL, NULL },
    { 696, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent068Tracks[5] = {
    { sEvent068Track0, EVENT_CHARA_SORA },
    { sEvent068Track1, EVENT_CHARA_DONALD },
    { sEvent068Track2, EVENT_CHARA_GOOFY },
    { sEvent068Track3, EVENT_CHARA_NAMINE },
    { sEvent068Track4, EVENT_CHARA_RIKU_REPLICA },
};

const EventSequenceDef gEvent068 = {
    ARRAY_COUNT(sEvent068Tracks),
    sEvent068Tracks,
    sEvent068Camera,
    sEvent068Script,
    sEvent068SoundCues,
    NULL,
    490,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_MARLUXIA_2,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
