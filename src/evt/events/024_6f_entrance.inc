#ifdef VERSION_US
#include "event_024_text.inc"
#endif

static const MessageScriptEntry sEvent024Script[4] = {
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent024Text00), 0, 220 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent024Text01), 0, 230 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent024Text02), 0, 250 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent024Text03), MSG_SCRIPT_FLAG_END, 270 },
};

#ifdef VERSION_JP
#include "event_024_text.inc"
#endif

static const EventCameraKeyframe sEvent024Camera[1] = {
    { -65485, 186880, 65024, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent024SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent024Track0[5] = {
    { 4, 1, 144896, 91392, 0, 0, 66, NULL, NULL },
    { 9, 180, 182272, 71168, 0, 4, 67, NULL, NULL },
    { 4, 230, 0, 0, 0, 0, 69, NULL, NULL },
    { 34, 270, 0, 0, 0, 0, 69, NULL, NULL },
    { 36, 290, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent024Track1[7] = {
    { 114, 1, 152576, 91136, 0, 0, 66, NULL, NULL },
    { 119, 180, 192000, 73472, 0, 114, 67, NULL, NULL },
    { 114, 190, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 195, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 249, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 251, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 290, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent024Track2[9] = {
    { 146, 1, 143104, 86272, 0, 0, 66, NULL, NULL },
    { 151, 180, 189952, 62720, 0, 146, 67, NULL, NULL },
    { 146, 190, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 195, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 200, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 205, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 219, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 221, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 290, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent024Tracks[3] = {
    { sEvent024Track0, EVENT_CHARA_SORA },
    { sEvent024Track1, EVENT_CHARA_DONALD },
    { sEvent024Track2, EVENT_CHARA_GOOFY },
};

const EventSequenceDef gEvent024 = {
    ARRAY_COUNT(sEvent024Tracks),
    sEvent024Tracks,
    sEvent024Camera,
    sEvent024Script,
    sEvent024SoundCues,
    NULL,
    320,
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
