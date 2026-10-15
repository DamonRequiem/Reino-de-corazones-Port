#ifdef VERSION_US
#include "event_037_text.inc"
#endif

static const MessageScriptEntry sEvent037Script[3] = {
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent037Text00), 0, 260 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent037Text01), 0, 280 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent037Text02), MSG_SCRIPT_FLAG_END, 330 },
};

#ifdef VERSION_JP
#include "event_037_text.inc"
#endif

static const EventCameraKeyframe sEvent037Camera[1] = {
    { -65485, 189184, 63488, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent037SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent037Track0[16] = {
    { 4, 1, 151808, 87808, 0, 0, 66, NULL, NULL },
    { 9, 170, 192768, 67328, 0, 4, 67, NULL, NULL },
    { 4, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 0, 185, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 200, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 205, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 215, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 230, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 235, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 285, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 290, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 295, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 300, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 320, 0, 0, 0, 0, 69, NULL, NULL },
    { 36, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent037Track1[13] = {
    { 114, 1, 148736, 95232, 0, 0, 66, NULL, NULL },
    { 119, 170, 189696, 75264, 0, 114, 67, NULL, NULL },
    { 114, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 185, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 190, 0, 0, 0, 0, 69, NULL, NULL },
    { 111, 200, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 205, 0, 0, 0, 0, 5, NULL, NULL },
    { 113, 210, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 230, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 235, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 259, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 261, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent037Track2[13] = {
    { 146, 1, 140288, 90112, 0, 0, 66, NULL, NULL },
    { 151, 170, 181248, 69632, 0, 146, 67, NULL, NULL },
    { 146, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 142, 185, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 200, 0, 0, 0, 0, 5, NULL, NULL },
    { 145, 205, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 210, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 230, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 235, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 240, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 279, 0, 0, 0, 0, 69, NULL, NULL },
    { 165, 281, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent037Tracks[3] = {
    { sEvent037Track0, EVENT_CHARA_SORA },
    { sEvent037Track1, EVENT_CHARA_DONALD },
    { sEvent037Track2, EVENT_CHARA_GOOFY },
};

const EventSequenceDef gEvent037 = {
    ARRAY_COUNT(sEvent037Tracks),
    sEvent037Tracks,
    sEvent037Camera,
    sEvent037Script,
    sEvent037SoundCues,
    NULL,
    380,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_038_9F_DEMO,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
