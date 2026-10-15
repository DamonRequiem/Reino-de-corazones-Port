#ifdef VERSION_US
#include "event_085_text.inc"
#endif

static const MessageScriptEntry sEvent085Script[1] = {
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent085Text00), MSG_SCRIPT_FLAG_END, 230 },
};

#ifdef VERSION_JP
#include "event_085_text.inc"
#endif

static const EventCameraKeyframe sEvent085Camera[1] = {
    { -64537, 33792, 32768, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent085SoundCues[1] = {
    { SONG_BGM_EVENT1, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent085Track0[9] = {
    { 12, 0, 71168, 23040, 0, 0, 2, NULL, NULL },
    { 12, 90, 0, 0, 0, 173, 36, NULL, NULL },
    { 2, 93, 0, 0, 0, 173, 4, NULL, NULL },
    { 2, 135, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 140, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 145, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 150, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 19, 400, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent085Track2[10] = {
    { 152, 0, 72192, 14592, 0, 0, 2, NULL, NULL },
    { 152, 150, 0, 0, 0, 173, 36, NULL, NULL },
    { 144, 153, 0, 0, 0, 173, 4, NULL, NULL },
    { 144, 200, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 205, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 215, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 245, 0, 0, 0, 0, 69, NULL, NULL },
    { 157, 255, 0, 0, 0, 0, 69, NULL, NULL },
    { 158, 500, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent085Track1[10] = {
    { 121, 0, 89600, 20480, 0, 0, 2, NULL, NULL },
    { 121, 128, 0, 0, 0, 173, 36, NULL, NULL },
    { 121, 131, 0, 0, 0, 173, 4, NULL, NULL },
    { 112, 170, 0, 0, 0, 0, 5, NULL, NULL },
    { 111, 175, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 185, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 240, 0, 0, 0, 0, 69, NULL, NULL },
    { 122, 250, 0, 0, 0, 0, 69, NULL, NULL },
    { 123, 490, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent085Tracks[3] = {
    { sEvent085Track0, EVENT_CHARA_SORA },
    { sEvent085Track1, EVENT_CHARA_DONALD },
    { sEvent085Track2, EVENT_CHARA_GOOFY },
};

const EventSequenceDef gEvent085 = {
    ARRAY_COUNT(sEvent085Tracks),
    sEvent085Tracks,
    sEvent085Camera,
    sEvent085Script,
    sEvent085SoundCues,
    NULL,
    300,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_SHADOW_100,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
