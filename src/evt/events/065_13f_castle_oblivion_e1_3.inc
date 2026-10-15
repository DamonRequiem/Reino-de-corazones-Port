#ifdef VERSION_US
#include "event_065_text.inc"
#endif

static const MessageScriptEntry sEvent065Script[4] = {
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent065Text00), 0, 140 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent065Text01), 0, 160 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent065Text02), 0, 350 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent065Text03), MSG_SCRIPT_FLAG_END, 440 },
};

#ifdef VERSION_JP
#include "event_065_text.inc"
#endif

static const EventCameraKeyframe sEvent065Camera[2] = {
    { -65146, 161792, 69888, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent065SoundCues[3] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_EV_WARPIN, 400, 0, 0 },
    { SONG_BGM_EVENT_XIII, 865, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent065Track0[20] = {
    { 21, 141, 156672, 76800, 0, 0, 66, NULL, NULL },
    { 22, 145, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 161, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 440, 0, 0, 0, 0, 69, NULL, NULL },
    { 30, 441, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 550, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 680, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 4, 690, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 695, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 705, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 730, 0, 0, 0, 0, 5, NULL, NULL },
    { 15, 740, 0, 0, 0, 0, 5, NULL, NULL },
    { 17, 750, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 760, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 765, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 770, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 775, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 790, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 999, 0, 0, 0, 45, 32868, NULL, NULL },
};

static const EventCharaKeyframe sEvent065Track1[4] = {
    { 123, 155, 146688, 77824, 0, 0, 66, NULL, NULL },
    { 124, 165, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 795, 0, 0, 0, 0, 69, NULL, NULL },
    { 120, 999, 0, 0, 0, 45, 32868, NULL, NULL },
};

static const EventCharaKeyframe sEvent065Track2[4] = {
    { 158, 160, 155136, 86528, 0, 0, 66, NULL, NULL },
    { 159, 170, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 796, 0, 0, 0, 0, 69, NULL, NULL },
    { 153, 999, 0, 0, 0, 45, 32868, NULL, NULL },
};

static const EventCharaKeyframe sEvent065Track3[4] = {
    { 508, 170, 172800, 69632, 0, 0, 2, NULL, NULL },
    { 508, 400, 0, 0, 0, 0, 5, NULL, NULL },
    { 508, 420, 0, 0, 0, 0, 0, EventCharaFadeOut, NULL },
    { 508, 430, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaKeyframe sEvent065Track4[3] = {
    { 928, 170, 0, 0, 0, 0, 8194, NULL, NULL },
    { 928, 300, 173824, 59136, 0, 0, 16658, NULL, NULL },
    { 928, 2000, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaTrack sEvent065Tracks[5] = {
    { sEvent065Track0, EVENT_CHARA_SORA },
    { sEvent065Track1, EVENT_CHARA_DONALD },
    { sEvent065Track2, EVENT_CHARA_GOOFY },
    { sEvent065Track3, EVENT_CHARA_AXEL },
    { sEvent065Track4, EVENT_CHARA_B_STATES_4 },
};

const EventSequenceDef gEvent065 = {
    ARRAY_COUNT(sEvent065Tracks),
    sEvent065Tracks,
    sEvent065Camera,
    sEvent065Script,
    sEvent065SoundCues,
    NULL,
    870,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
