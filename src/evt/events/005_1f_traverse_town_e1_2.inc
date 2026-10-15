#ifdef VERSION_US
#include "event_005_text.inc"
#endif

static const MessageScriptEntry sEvent005Script[4] = {
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent005Text00), 0, 100 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent005Text01), 0, 130 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent005Text02), 0, 160 },
    { PORTRAIT_LEON, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent005Text03), MSG_SCRIPT_FLAG_END, 280 },
};

#ifdef VERSION_JP
#include "event_005_text.inc"
#endif

static const EventCameraKeyframe sEvent005Camera[2] = {
    { -65156, 57856, 76288, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -62536, 73984, 64256, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 110, NULL },
};

static const EvSoundCue sEvent005SoundCues[3] = {
    { SONG_BGM_EVENT1, 0, 0, 0 },
    { SONG_EV_CARDTHR, 203, 0, 0 },
    { SONG_BGM_EVENT1, 520, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent005Track0[8] = {
    { 4, 125, 51200, 83456, 0, 0, 66, NULL, NULL },
    { 36, 140, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 203, 0, 0, 0, 0, 69, NULL, NULL },
    { 72, 250, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 255, 0, 0, 0, 0, 69, NULL, NULL },
    { 75, 290, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 378, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 9999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent005Track1[2] = {
    { 114, 382, 40192, 82688, 0, 0, 66, NULL, NULL },
    { 119, 9999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent005Track2[2] = {
    { 146, 380, 44800, 91904, 0, 0, 66, NULL, NULL },
    { 151, 9999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent005Track3[6] = {
    { 642, 170, 71936, 76032, 0, 0, 2, NULL, NULL },
    { 638, 180, 0, 0, 0, 0, 5, NULL, NULL },
    { 646, 300, 0, 0, 0, 0, 5, NULL, NULL },
    { 639, 310, 0, 0, 0, 0, 5, NULL, NULL },
    { 639, 340, 0, 0, 0, 0, 69, NULL, NULL },
    { 641, 9999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent005Track4[7] = {
    { 593, 202, 0, 0, 0, 0, 8194, NULL, NULL },
    { 593, 203, 62976, 69120, 0, 0, 16642, NULL, NULL },
    { 593, 210, 56064, 73728, 0, 593, 275, NULL, NULL },
    { 600, 250, 51200, 83456, 0, 0, 338, NULL, NULL },
    { 593, 255, 0, 0, 0, 0, 2, NULL, NULL },
    { 602, 290, 51200, 83456, 0, 0, 338, NULL, NULL },
    { 593, 465, 0, 0, 0, 0, 32770, NULL, NULL },
};

static const EventCharaTrack sEvent005Tracks[5] = {
    { sEvent005Track0, EVENT_CHARA_SORA },
    { sEvent005Track1, EVENT_CHARA_DONALD },
    { sEvent005Track2, EVENT_CHARA_GOOFY },
    { sEvent005Track3, EVENT_CHARA_LEON },
    { sEvent005Track4, EVENT_CHARA_B_STATES_2 },
};

const EventSequenceDef gEvent005 = {
    ARRAY_COUNT(sEvent005Tracks),
    sEvent005Tracks,
    sEvent005Camera,
    sEvent005Script,
    sEvent005SoundCues,
    NULL,
    530,
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
