#ifdef VERSION_US
static const MessageScriptEntry sEvent014Script[1] = {
    { PORTRAIT_SELPHIE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, gEvent014Text00, MSG_SCRIPT_FLAG_END, 9000 },
};

#include "event_014_text.inc"
#endif
#ifdef VERSION_JP
static const MessageScriptEntry sEvent014Script[1] = {
    { PORTRAIT_SELPHIE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 3, gEvent014Text00, MSG_SCRIPT_FLAG_END, 9000 },
};

#include "event_014_text.inc"
#endif
#ifdef VERSION_EU
static const MessageScriptEntry sEvent014Script[1] = {
    { PORTRAIT_SELPHIE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, NULL, MSG_SCRIPT_FLAG_END, 9000 },
};
#endif

static const EventCameraKeyframe sEvent014Camera[1] = {
    { -60536, 60672, 48384, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent014SoundCues[2] = {
    { SONG_BGM_EVENT_NAMINE, 0, 0, 0 },
    { SONG_BGM_EVENT_NAMINE, 395, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent014Track0[7] = {
    { 442, 100, 59904, 54016, 0, 0, 18, NULL, NULL },
    { 443, 130, 0, 0, 0, 0, 21, NULL, NULL },
    { 442, 150, 0, 0, 0, 0, 21, NULL, NULL },
    { 443, 170, 0, 0, 0, 0, 21, NULL, NULL },
    { 442, 220, 0, 0, 0, 0, 21, NULL, NULL },
    { 443, 350, 0, 0, 0, 0, 21, NULL, NULL },
    { 442, 5000, 0, 0, 0, 0, 32789, NULL, NULL },
};

static const EventCharaKeyframe sEvent014Track1[1] = {
    { 919, 5000, 60416, 53760, 0, 0, 33106, NULL, NULL },
};

static const EventCharaTrack sEvent014Tracks[2] = {
    { sEvent014Track0, EVENT_CHARA_NAMINE },
    { sEvent014Track1, EVENT_CHARA_MAP_GIMMICK_44 },
};

const EventSequenceDef gEvent014 = {
    ARRAY_COUNT(sEvent014Tracks),
    sEvent014Tracks,
    sEvent014Camera,
    sEvent014Script,
    sEvent014SoundCues,
    NULL,
    400,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_015_3F_ENTRANCE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
