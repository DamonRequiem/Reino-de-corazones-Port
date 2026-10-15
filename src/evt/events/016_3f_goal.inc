#ifdef VERSION_US
#include "event_016_text.inc"
#endif

static const MessageScriptEntry sEvent016Script[10] = {
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent016Text00), 0, 260 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent016Text01), 0, 300 },
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent016Text02), 0, 320 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent016Text03), 0, 340 },
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent016Text04), 0, 360 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent016Text05), 0, 380 },
    { PORTRAIT_DONALD, 3, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent016Text06), 0, 400 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent016Text07), 0, 420 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent016Text08), 0, 432 },
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent016Text09), MSG_SCRIPT_FLAG_END, 460 },
};

#ifdef VERSION_JP
#include "event_016_text.inc"
#endif

static const EventCameraKeyframe sEvent016Camera[1] = {
    { -65485, 193536, 60672, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent016SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent016Track0[10] = {
    { 4, 1, 156928, 84224, 0, 0, 66, NULL, NULL },
    { 9, 250, 206080, 60672, 0, 4, 67, NULL, NULL },
    { 4, 270, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 275, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 280, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 285, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 419, 0, 0, 0, 0, 5, NULL, NULL },
    { 32, 421, 0, 0, 0, 0, 5, NULL, NULL },
    { 15, 431, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent016Track1[13] = {
    { 114, 1, 147968, 87552, 0, 0, 66, NULL, NULL },
    { 119, 180, 181760, 71168, 0, 114, 67, NULL, NULL },
    { 114, 259, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 261, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 319, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 321, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 359, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 361, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 399, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 401, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 459, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 461, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent016Track2[11] = {
    { 146, 1, 152064, 80384, 0, 0, 66, NULL, NULL },
    { 151, 220, 192512, 60160, 0, 146, 67, NULL, NULL },
    { 146, 275, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 280, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 285, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 290, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 339, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 341, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 379, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 381, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent016Tracks[3] = {
    { sEvent016Track0, EVENT_CHARA_SORA },
    { sEvent016Track1, EVENT_CHARA_DONALD },
    { sEvent016Track2, EVENT_CHARA_GOOFY },
};

const EventSequenceDef gEvent016 = {
    ARRAY_COUNT(sEvent016Tracks),
    sEvent016Tracks,
    sEvent016Camera,
    sEvent016Script,
    sEvent016SoundCues,
    NULL,
    510,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_017_3F_DEMO,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
