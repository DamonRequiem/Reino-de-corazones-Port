#ifdef VERSION_US
#include "event_077_text.inc"
#endif

static const MessageScriptEntry sEvent077Script[3] = {
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent077Text00), 0, 100 },
    { PORTRAIT_PINOCCHIO, 11, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent077Text01), 0, 150 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent077Text02), MSG_SCRIPT_FLAG_END, 170 },
};

#ifdef VERSION_JP
#include "event_077_text.inc"
#endif

static const EventCameraKeyframe sEvent077Camera[1] = {
    { -65485, 104448, 98304, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent077SoundCues[1] = {
    { SONG_BGM_EVENT2, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent077Track1[6] = {
    { 20, 1, 96000, 112640, 0, 0, 66, NULL, NULL },
    { 4, 78, 0, 0, 0, 0, 85, NULL, NULL },
    { 2, 90, 0, 0, 0, 0, 85, NULL, NULL },
    { 3, 169, 0, 0, 0, 0, 85, NULL, NULL },
    { 3, 171, 0, 0, 0, 0, 80, NULL, CreateExclamationTask },
    { 18, 230, 0, 0, 0, 0, 32853, NULL, NULL },
};

static const EventCharaKeyframe sEvent077Track0[1] = {
    { 934, 999, 0, 12800, 0, 0, 32770, NULL, NULL },
};

static const EventCharaTrack sEvent077Tracks[2] = {
    { sEvent077Track0, EVENT_CHARA_BOSS_PARASITE_CAGE },
    { sEvent077Track1, EVENT_CHARA_SORA },
};

const EventSequenceDef gEvent077 = {
    ARRAY_COUNT(sEvent077Tracks),
    sEvent077Tracks,
    sEvent077Camera,
    sEvent077Script,
    sEvent077SoundCues,
    NULL,
    280,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_PARASITE_CAGE,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
