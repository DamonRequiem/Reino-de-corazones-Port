#ifdef VERSION_US
#include "event_034_text.inc"
#endif

static const MessageScriptEntry sEvent034Script[10] = {
    { PORTRAIT_RIKU_REPLICA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent034Text00), 0, 100 },
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent034Text01), 0, 160 },
    { PORTRAIT_RIKU_REPLICA, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent034Text02), 0, 162 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent034Text03), 0, 250 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent034Text04), 0, 310 },
    { PORTRAIT_RIKU_REPLICA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent034Text05), 0, 340 },
    { PORTRAIT_RIKU_REPLICA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent034Text06), 0, 420 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent034Text07), 0, 450 },
    { PORTRAIT_RIKU_REPLICA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent034Text08), 0, 480 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent034Text09), MSG_SCRIPT_FLAG_END, 830 },
};

#ifdef VERSION_JP
#include "event_034_text.inc"
#endif

static const EventCameraKeyframe sEvent034Camera[2] = {
    { -64966, 193792, 61696, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -62536, 188416, 64768, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 80, NULL },
};

static const EvSoundCue sEvent034SoundCues[1] = {
    { SONG_BGM_EVENT_UNREST, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent034Track0[9] = {
    { 21, 190, 190464, 68352, 0, 0, 66, NULL, NULL },
    { 22, 205, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 270, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 290, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 445, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 510, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 650, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 780, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 4, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent034Track1[3] = {
    { 123, 195, 186624, 75776, 0, 0, 66, NULL, NULL },
    { 124, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent034Track2[3] = {
    { 158, 198, 178432, 70144, 0, 0, 66, NULL, NULL },
    { 159, 213, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent034Track3[7] = {
    { 699, 120, 208128, 60160, 0, 0, 2, NULL, NULL },
    { 700, 135, 0, 0, 0, 0, 5, NULL, NULL },
    { 695, 490, 0, 0, 0, 0, 5, NULL, NULL },
    { 696, 500, 0, 0, 0, 0, 5, NULL, NULL },
    { 696, 510, 0, 0, 0, 0, 69, NULL, NULL },
    { 710, 600, 0, 0, 0, 45, 100, NULL, NULL },
    { 696, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent034Tracks[4] = {
    { sEvent034Track0, EVENT_CHARA_SORA },
    { sEvent034Track1, EVENT_CHARA_DONALD },
    { sEvent034Track2, EVENT_CHARA_GOOFY },
    { sEvent034Track3, EVENT_CHARA_RIKU_REPLICA },
};

const EventSequenceDef gEvent034 = {
    ARRAY_COUNT(sEvent034Tracks),
    sEvent034Tracks,
    sEvent034Camera,
    sEvent034Script,
    sEvent034SoundCues,
    NULL,
    890,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_035_8F_DEMO,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
