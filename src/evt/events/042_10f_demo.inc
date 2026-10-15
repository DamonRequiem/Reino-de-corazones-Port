#ifdef VERSION_US
#include "event_042_text.inc"
#endif

static const MessageScriptEntry sEvent042Script[7] = {
    { PORTRAIT_LARXENE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent042Text00), 0, 100 },
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent042Text01), 0, 130 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent042Text02), 0, 330 },
    { PORTRAIT_MARLUXIA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent042Text03), 0, 360 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent042Text04), 0, 430 },
    { PORTRAIT_MARLUXIA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent042Text05), 0, 510 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent042Text06), MSG_SCRIPT_FLAG_END, 540 },
};

#ifdef VERSION_JP
#include "event_042_text.inc"
#endif

static const EventCameraKeyframe sEvent042Camera[1] = {
    { -65485, 68864, 59904, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent042SoundCues[2] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_BGM_EVENT_XIII, 625, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent042Track0[8] = {
    { 509, 150, 79360, 62976, 0, 0, 2, NULL, NULL },
    { 509, 170, 0, 0, 0, 0, 5, NULL, NULL },
    { 509, 300, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 509, 370, 0, 0, 0, 0, 5, NULL, NULL },
    { 485, 390, 0, 0, 0, 0, 5, NULL, NULL },
    { 485, 570, 0, 0, 0, 0, 69, NULL, NULL },
    { 494, 700, 0, 0, 0, 83, 68, NULL, NULL },
    { 485, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent042Track1[3] = {
    { 876, 120, 69632, 74752, 0, 0, 2, NULL, NULL },
    { 876, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 856, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent042Track2[3] = {
    { 841, 505, 56320, 61952, 0, 0, 66, NULL, NULL },
    { 845, 3000, 0, 0, 0, 0, 69, NULL, NULL },
    { 841, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent042Tracks[3] = {
    { sEvent042Track0, EVENT_CHARA_AXEL },
    { sEvent042Track1, EVENT_CHARA_LARXENE },
    { sEvent042Track2, EVENT_CHARA_MARLUXIA },
};

const EventSequenceDef gEvent042 = {
    ARRAY_COUNT(sEvent042Tracks),
    sEvent042Tracks,
    sEvent042Camera,
    sEvent042Script,
    sEvent042SoundCues,
    NULL,
    630,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_043_11F_ENTRANCE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
