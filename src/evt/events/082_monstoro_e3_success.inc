#ifdef VERSION_US
#include "event_082_text.inc"
#endif

static const MessageScriptEntry sEvent082Script[3] = {
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent082Text00), 0, 100 },
    { PORTRAIT_GOOFY, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent082Text01), 0, 180 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent082Text02), MSG_SCRIPT_FLAG_END, 200 },
};

#ifdef VERSION_JP
#include "event_082_text.inc"
#endif

static const EventCameraKeyframe sEvent082Camera[6] = {
    { -65416, 30720, 32768, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65316, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_MEDIUM | CAMERA_MODE_KEEP, 0, NULL },
    { -65206, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_MEDIUM | CAMERA_MODE_KEEP, 0, NULL },
    { -65206, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_LARGE | CAMERA_MODE_KEEP, 0, NULL },
    { -65186, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_WHITE | CAMERA_KEYFRAME_FLAG_SHAKE_LARGE | CAMERA_MODE_KEEP, 20, NULL },
    { -64537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent082SoundCues[5] = {
    { SONG_BGM_EVENT1, 0, 0, 0 },
    { SONG_EV_RUMBLE, 120, 0, 0 },
    { SONG_EV_RUMBLE, 300, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_EV_FLASH02, 330, 0, 0 },
    { SONG_BGM_EVENT1, 331, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent082Track0[6] = {
    { 21, 80, 34816, 40960, 0, 0, 66, NULL, NULL },
    { 22, 90, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 120, 0, 0, 0, 0, 69, NULL, NULL },
    { 29, 220, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 29, 330, 0, 0, 0, 0, 69, NULL, NULL },
    { 29, 350, 69120, 28160, -10240, 4, 32867, NULL, NULL },
};

static const EventCharaKeyframe sEvent082Track1[6] = {
    { 123, 84, 37376, 47360, 0, 0, 66, NULL, NULL },
    { 124, 94, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 120, 0, 0, 0, 0, 69, NULL, NULL },
    { 134, 220, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 134, 330, 0, 0, 0, 0, 69, NULL, NULL },
    { 134, 350, 66560, 33280, -12800, 114, 32867, NULL, NULL },
};

static const EventCharaKeyframe sEvent082Track2[6] = {
    { 158, 88, 22016, 38400, 0, 0, 66, NULL, NULL },
    { 159, 98, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 120, 0, 0, 0, 0, 69, NULL, NULL },
    { 162, 220, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 162, 330, 0, 0, 0, 0, 69, NULL, NULL },
    { 162, 350, 69120, 25600, -7680, 146, 32867, NULL, NULL },
};

static const EventCharaTrack sEvent082Tracks[3] = {
    { sEvent082Track0, EVENT_CHARA_SORA },
    { sEvent082Track1, EVENT_CHARA_DONALD },
    { sEvent082Track2, EVENT_CHARA_GOOFY },
};

const EventSequenceDef gEvent082 = {
    ARRAY_COUNT(sEvent082Tracks),
    sEvent082Tracks,
    sEvent082Camera,
    sEvent082Script,
    sEvent082SoundCues,
    NULL,
    530,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_086_MONSTORO_E3_END,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
