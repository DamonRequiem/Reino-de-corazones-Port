#ifdef VERSION_US
static const MessageScriptEntry sEvent069Script[1] = {
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent069Text00, MSG_SCRIPT_FLAG_END, 9999 },
};

#include "event_069_text.inc"
#endif
#ifdef VERSION_JP
static const MessageScriptEntry sEvent069Script[1] = {
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent069Text00, MSG_SCRIPT_FLAG_END, 9999 },
};

#include "event_069_text.inc"
#endif
#ifdef VERSION_EU
static const MessageScriptEntry sEvent069Script[1] = {
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, NULL, MSG_SCRIPT_FLAG_END, 9999 },
};
#endif

static const EventCameraKeyframe sEvent069Camera[3] = {
    { -65536, 216576, 51968, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -65286, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 150, NULL },
    { -55537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent069SoundCues[2] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_BGM_TOWN_FIELD, 2000, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent069Track0[3] = {
    { 4, 250, 214016, 59392, 0, 0, 66, NULL, NULL },
    { 9, 350, 224512, 50432, 0, 4, 67, NULL, NULL },
    { 4, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent069Track1[3] = {
    { 114, 30, 205568, 58880, 0, 0, 66, NULL, NULL },
    { 114, 3000, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent069Track2[3] = {
    { 146, 30, 217088, 68096, 0, 0, 66, NULL, NULL },
    { 146, 3000, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent069Track3[3] = {
    { 428, 30, 199936, 54528, 0, 0, 66, NULL, NULL },
    { 428, 3000, 0, 0, 0, 0, 69, NULL, NULL },
    { 428, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent069Track4[3] = {
    { 696, 30, 228352, 67328, 0, 0, 66, NULL, NULL },
    { 696, 3000, 0, 0, 0, 0, 69, NULL, NULL },
    { 696, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent069Tracks[5] = {
    { sEvent069Track0, EVENT_CHARA_SORA },
    { sEvent069Track1, EVENT_CHARA_DONALD },
    { sEvent069Track2, EVENT_CHARA_GOOFY },
    { sEvent069Track3, EVENT_CHARA_NAMINE },
    { sEvent069Track4, EVENT_CHARA_RIKU_REPLICA },
};

const EventSequenceDef gEvent069 = {
    ARRAY_COUNT(sEvent069Tracks),
    sEvent069Tracks,
    sEvent069Camera,
    sEvent069Script,
    sEvent069SoundCues,
    NULL,
    250,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_070_13F_CASTLE_OBLIVION_LAST5,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
