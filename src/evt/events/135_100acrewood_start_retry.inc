#ifdef VERSION_US
#include "event_135_text.inc"
static const MessageScriptEntry sEvent135Script[1] = {
    { PORTRAIT_WINNIE_THE_POOH, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, gEventTextUs_0900868C, MSG_SCRIPT_FLAG_END, 300 },
};
#endif

#ifdef VERSION_JP
static const MessageScriptEntry sEvent135Script[1] = {
    { PORTRAIT_WINNIE_THE_POOH, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 3, gEvent135Text00, MSG_SCRIPT_FLAG_END, 300 },
};

#include "event_135_text.inc"
#endif
#ifdef VERSION_EU
static const MessageScriptEntry sEvent135Script[1] = {
    { PORTRAIT_WINNIE_THE_POOH, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, &gPoohTalkTextByLanguage, MSG_SCRIPT_FLAG_END, 300 },
};
#endif

static const EventCameraKeyframe sEvent135Camera[2] = {
    { -65536, 105216, 67328, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -64636, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 80, NULL },
};

static const EvSoundCue sEvent135SoundCues[2] = {
    { SONG_BGM_WINNIETHEPOOH, 1, 0, 0 },
    { SONG_BG_POO, 2, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent135Track0[5] = {
    { 2, 1, 73472, 59648, 0, 0, 66, NULL, NULL },
    { 7, 121, 100096, 71424, 0, 2, 67, NULL, NULL },
    { 2, 140, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 145, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 2000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent135Track1[3] = {
    { 796, 160, 110080, 67840, 0, 0, 258, NULL, NULL },
    { 797, 1830, 0, 0, 0, 0, 261, NULL, NULL },
    { 756, 1880, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent135Track2[2] = {
    { 806, 20, 146176, 59904, -5120, 0, 2, NULL, NULL },
    { 806, 9999, 0, 0, 0, 173, 33028, NULL, NULL },
};

static const EventCharaTrack sEvent135Tracks[3] = {
    { sEvent135Track0, EVENT_CHARA_SORA },
    { sEvent135Track1, EVENT_CHARA_WINNIE_THE_POOH },
    { sEvent135Track2, EVENT_CHARA_TRAP },
};

const EventSequenceDef gEvent135 = {
    ARRAY_COUNT(sEvent135Tracks),
    sEvent135Tracks,
    sEvent135Camera,
    sEvent135Script,
    sEvent135SoundCues,
    NULL,
    360,
    FALSE,
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
    0,
};
