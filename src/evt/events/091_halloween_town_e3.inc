#ifdef VERSION_US
#include "event_091_text.inc"
#endif

static const MessageScriptEntry sEvent091Script[11] = {
    { PORTRAIT_JACK, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent091Text00), 0, 240 },
    { PORTRAIT_OOGIE_BOOGIE, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent091Text01), 0, 280 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent091Text02), 0, 300 },
    { PORTRAIT_OOGIE_BOOGIE, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent091Text03), 0, 310 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent091Text04), 0, 406 },
    { PORTRAIT_OOGIE_BOOGIE, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent091Text05), 0, 420 },
    { PORTRAIT_OOGIE_BOOGIE, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent091Text06), 0, 422 },
    { PORTRAIT_OOGIE_BOOGIE, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent091Text07), 0, 600 },
    { PORTRAIT_OOGIE_BOOGIE, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent091Text08), 0, 604 },
    { PORTRAIT_JACK, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent091Text09), 0, 640 },
    { PORTRAIT_OOGIE_BOOGIE, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent091Text10), MSG_SCRIPT_FLAG_END, 660 },
};

#ifdef VERSION_JP
#include "event_091_text.inc"
#endif

static const EventCameraKeyframe sEvent091Camera[2] = {
    { -65485, 89600, 79872, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65236, 49664, 51200, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 150, NULL },
};

static const EvSoundCue sEvent091SoundCues[6] = {
    { SONG_BGM_EVENT_UNREST, 0, 0, 0 },
    { SONG_SND_348, 335, 0, 0 },
    { SONG_SND_348, 359, 0, 0 },
    { SONG_SND_348, 383, 0, 0 },
    { SONG_BGM_EVENT_UNREST, 440, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_EVENT2, 604, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent091Track0[7] = {
    { 4, 0, 125184, 102656, 0, 0, 2, NULL, NULL },
    { 14, 170, 0, 0, 0, 211, 36, NULL, NULL },
    { 4, 173, 0, 0, 0, 211, 4, NULL, NULL },
    { 4, 299, 0, 0, 0, 0, 5, NULL, NULL },
    { 30, 399, 0, 0, 0, 0, 5, NULL, NULL },
    { 27, 655, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent091Track1[10] = {
    { 289, 0, 109312, 82944, 0, 0, 2, NULL, NULL },
    { 297, 140, 0, 0, 0, 211, 36, NULL, NULL },
    { 289, 144, 0, 0, 0, 211, 4, NULL, NULL },
    { 289, 150, 0, 0, 0, 0, 5, NULL, NULL },
    { 288, 239, 0, 0, 0, 0, 5, NULL, NULL },
    { 298, 242, 0, 0, 0, 0, 5, NULL, NULL },
    { 288, 619, 0, 0, 0, 0, 5, NULL, NULL },
    { 290, 640, 0, 0, 0, 173, 4, NULL, NULL },
    { 298, 641, 0, 0, 0, 0, 5, NULL, NULL },
    { 288, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent091Track2[4] = {
    { 114, 0, 132608, 103424, 0, 0, 2, NULL, NULL },
    { 120, 188, 0, 0, 0, 211, 36, NULL, NULL },
    { 114, 192, 0, 0, 0, 211, 4, NULL, NULL },
    { 114, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent091Track3[4] = {
    { 146, 0, 123136, 109312, 0, 0, 2, NULL, NULL },
    { 153, 228, 0, 0, 0, 211, 36, NULL, NULL },
    { 146, 234, 0, 0, 0, 211, 4, NULL, NULL },
    { 146, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent091Track4[7] = {
    { 362, 242, 29440, 53760, 0, 0, 2, NULL, NULL },
    { 370, 250, 0, 0, 0, 0, 5, NULL, NULL },
    { 370, 311, 0, 0, 0, 0, 69, NULL, NULL },
    { 371, 419, 0, 0, 0, 0, 69, NULL, NULL },
    { 365, 560, 0, 0, 0, 0, 69, NULL, NULL },
    { 361, 601, 0, 0, 0, 0, 69, NULL, NULL },
    { 372, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent091Tracks[5] = {
    { sEvent091Track0, EVENT_CHARA_SORA },
    { sEvent091Track1, EVENT_CHARA_JACK },
    { sEvent091Track2, EVENT_CHARA_DONALD },
    { sEvent091Track3, EVENT_CHARA_GOOFY },
    { sEvent091Track4, EVENT_CHARA_OOGIE_BOOGIE },
};

const EventSequenceDef gEvent091 = {
    ARRAY_COUNT(sEvent091Tracks),
    sEvent091Tracks,
    sEvent091Camera,
    sEvent091Script,
    sEvent091SoundCues,
    NULL,
    730,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_092_HALLOWEEN_TOWN_E3,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
