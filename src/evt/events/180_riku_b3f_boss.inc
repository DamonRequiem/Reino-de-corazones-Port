#ifdef VERSION_US
#include "event_180_text.inc"
#endif

static const MessageScriptEntry sEvent180Script[1] = {
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent180Text00), MSG_SCRIPT_FLAG_END, 100 },
};

#ifdef VERSION_JP
#include "event_180_text.inc"
#endif

static const EvSoundCue sEvent180SoundCues[1] = {
    { SONG_BGM_BOSSWORLD, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent180Camera[1] = {
    { -64537, 61440, 92160, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent180Track0[2] = {
    { 514, 40, 51200, 99840, 0, 0, 66, NULL, NULL },
    { 526, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent180Track1[1] = {
    { 944, 999, 18432, 36864, 0, 0, 32834, NULL, NULL },
};

static const EventCharaTrack sEvent180Tracks[2] = {
    { sEvent180Track0, EVENT_CHARA_RIKU },
    { sEvent180Track1, EVENT_CHARA_BOSS_DARKSIDE },
};

const EventSequenceDef gEvent180 = {
    ARRAY_COUNT(sEvent180Tracks),
    sEvent180Tracks,
    sEvent180Camera,
    sEvent180Script,
    sEvent180SoundCues,
    NULL,
    160,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_DARKSIDE,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
