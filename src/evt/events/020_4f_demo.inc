#ifdef VERSION_US
static const MessageScriptEntry sEvent020Script[1] = {
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent020Text00, MSG_SCRIPT_FLAG_END, 1000 },
};

#include "event_020_text.inc"
#endif
#ifdef VERSION_JP
static const MessageScriptEntry sEvent020Script[1] = {
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent020Text00, MSG_SCRIPT_FLAG_END, 1000 },
};

#include "event_020_text.inc"
#endif
#ifdef VERSION_EU
static const MessageScriptEntry sEvent020Script[1] = {
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, NULL, MSG_SCRIPT_FLAG_END, 1000 },
};
#endif

static const EventCameraKeyframe sEvent020Camera[1] = {
    { -60536, 60672, 48384, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent020SoundCues[2] = {
    { SONG_BGM_EVENT_NAMINE, 0, 0, 0 },
    { SONG_BGM_EVENT_NAMINE, 395, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent020Track0[7] = {
    { 442, 80, 59904, 54016, 0, 0, 18, NULL, NULL },
    { 443, 180, 0, 0, 0, 0, 21, NULL, NULL },
    { 442, 200, 0, 0, 0, 0, 21, NULL, NULL },
    { 443, 250, 0, 0, 0, 0, 21, NULL, NULL },
    { 442, 280, 0, 0, 0, 0, 21, NULL, NULL },
    { 443, 300, 0, 0, 0, 0, 21, NULL, NULL },
    { 442, 5000, 0, 0, 0, 0, 32789, NULL, NULL },
};

static const EventCharaKeyframe sEvent020Track1[1] = {
    { 919, 5000, 60416, 53760, 0, 0, 33106, NULL, NULL },
};

static const EventCharaTrack sEvent020Tracks[2] = {
    { sEvent020Track0, EVENT_CHARA_NAMINE },
    { sEvent020Track1, EVENT_CHARA_MAP_GIMMICK_44 },
};

const EventSequenceDef gEvent020 = {
    ARRAY_COUNT(sEvent020Tracks),
    sEvent020Tracks,
    sEvent020Camera,
    sEvent020Script,
    sEvent020SoundCues,
    NULL,
    400,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_021_5F_ENTRANCE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
