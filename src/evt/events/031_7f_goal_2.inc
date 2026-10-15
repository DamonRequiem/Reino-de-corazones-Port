#ifdef VERSION_US
#include "event_031_text.inc"
#endif

static const MessageScriptEntry sEvent031Script[1] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent031Text00), MSG_SCRIPT_FLAG_END, 415 },
};

#ifdef VERSION_JP
#include "event_031_text.inc"
#endif

static const EventCameraKeyframe sEvent031Camera[1] = {
    { -65485, 191744, 62208, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent031SoundCues[2] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_BGM_EVENT_XIII, 470, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent031Track0[8] = {
    { 21, 300, 188160, 69632, 0, 0, 66, NULL, NULL },
    { 21, 350, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 22, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 370, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 388, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 391, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 410, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent031Track1[3] = {
    { 123, 365, 185088, 77312, 0, 0, 66, NULL, NULL },
    { 124, 370, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent031Track2[3] = {
    { 158, 367, 176640, 71936, 0, 0, 66, NULL, NULL },
    { 159, 372, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent031Track3[6] = {
    { 699, 150, 205056, 59648, 0, 0, 2, NULL, NULL },
    { 699, 280, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 700, 290, 0, 0, 0, 0, 5, NULL, NULL },
    { 695, 300, 0, 0, 0, 0, 69, NULL, NULL },
    { 696, 320, 0, 0, 0, 0, 69, NULL, NULL },
    { 710, 380, 228096, 47104, 0, 696, 32835, NULL, NULL },
};

static const EventCharaTrack sEvent031Tracks[4] = {
    { sEvent031Track0, EVENT_CHARA_SORA },
    { sEvent031Track1, EVENT_CHARA_DONALD },
    { sEvent031Track2, EVENT_CHARA_GOOFY },
    { sEvent031Track3, EVENT_CHARA_RIKU_REPLICA },
};

const EventSequenceDef gEvent031 = {
    ARRAY_COUNT(sEvent031Tracks),
    sEvent031Tracks,
    sEvent031Camera,
    sEvent031Script,
    sEvent031SoundCues,
    NULL,
    475,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_032_8F_ENTRANCE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
