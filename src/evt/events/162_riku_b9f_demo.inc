#ifdef VERSION_US
#include "event_162_text.inc"
#endif

static const MessageScriptEntry sEvent162Script[10] = {
    { PORTRAIT_LEXAEUS, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent162Text00), 0, 130 },
    { PORTRAIT_ZEXION, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent162Text01), 0, 220 },
    { PORTRAIT_LEXAEUS, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent162Text02), 0, 250 },
    { PORTRAIT_ZEXION, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent162Text03), 0, 280 },
    { PORTRAIT_ZEXION, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent162Text04), 0, 282 },
    { PORTRAIT_ZEXION, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent162Text05), 0, 284 },
    { PORTRAIT_LEXAEUS, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent162Text06), 0, 315 },
    { PORTRAIT_ZEXION, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent162Text07), 0, 345 },
    { PORTRAIT_LEXAEUS, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent162Text08), 0, 375 },
    { PORTRAIT_ZEXION, 1, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent162Text09), MSG_SCRIPT_FLAG_END, 410 },
};

#ifdef VERSION_JP
#include "event_162_text.inc"
#endif

static const EvSoundCue sEvent162SoundCues[2] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_BGM_EVENT_XIII, 455, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent162Camera[1] = {
    { -65116, 83456, 64256, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent162Track0[6] = {
    { 883, 3, 46848, 58624, 0, 0, 66, NULL, NULL },
    { 885, 100, 0, 0, 0, 83, 68, NULL, NULL },
    { 883, 310, 0, 0, 0, 0, 69, NULL, NULL },
    { 887, 1000, 0, 0, 0, 0, 69, NULL, NULL },
    { 883, 1000, 0, 0, 0, 0, 69, NULL, NULL },
    { 883, 3000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent162Track1[6] = {
    { 889, 160, 97024, 77056, 0, 0, 66, NULL, NULL },
    { 889, 170, 0, 0, 0, 0, 5, NULL, NULL },
    { 889, 180, 0, 0, 0, 0, 5, NULL, NULL },
    { 902, 190, 0, 0, 0, 0, 5, NULL, NULL },
    { 902, 420, 0, 0, 0, 0, 5, NULL, NULL },
    { 902, 3000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent162Tracks[2] = {
    { sEvent162Track0, EVENT_CHARA_LEXAEUS },
    { sEvent162Track1, EVENT_CHARA_ZEXION },
};

const EventSequenceDef gEvent162 = {
    ARRAY_COUNT(sEvent162Tracks),
    sEvent162Tracks,
    sEvent162Camera,
    sEvent162Script,
    sEvent162SoundCues,
    NULL,
    460,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
