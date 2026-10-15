#ifdef VERSION_US
static const MessageScriptEntry sEvent062Script[1] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent062Text00, MSG_SCRIPT_FLAG_END, 9999 },
};

#include "event_062_text.inc"
#endif
#ifdef VERSION_JP
static const MessageScriptEntry sEvent062Script[1] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent062Text00, MSG_SCRIPT_FLAG_END, 9999 },
};

#include "event_062_text.inc"
#endif
#ifdef VERSION_EU
static const MessageScriptEntry sEvent062Script[1] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, NULL, MSG_SCRIPT_FLAG_END, 9999 },
};
#endif

static const EventCameraKeyframe sEvent062Camera[1] = {
    { -65485, 159744, 66048, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent062SoundCues[3] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_EV_WARPOUT, 290, 0, 0 },
    { SONG_BGM_EVENT_XIII, 365, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent062Track0[1] = {
    { 714, 1000, 153088, 68864, 0, 0, 33026, NULL, NULL },
};

static const EventCharaKeyframe sEvent062Track1[1] = {
    { 440, 30, 157952, 71680, 0, 0, 32770, NULL, NULL },
};

static const EventCharaKeyframe sEvent062Track2[4] = {
    { 842, 290, 0, 0, 0, 0, 2, NULL, NULL },
    { 842, 350, 184064, 84480, 0, 0, 2, EventCharaFadeIn, NULL },
    { 844, 450, 167936, 76800, 0, 842, 3, NULL, NULL },
    { 842, 330, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent062Tracks[3] = {
    { sEvent062Track0, EVENT_CHARA_RIKU_REPLICA },
    { sEvent062Track1, EVENT_CHARA_NAMINE },
    { sEvent062Track2, EVENT_CHARA_MARLUXIA },
};

const EventSequenceDef gEvent062 = {
    ARRAY_COUNT(sEvent062Tracks),
    sEvent062Tracks,
    sEvent062Camera,
    sEvent062Script,
    sEvent062SoundCues,
    NULL,
    370,
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
