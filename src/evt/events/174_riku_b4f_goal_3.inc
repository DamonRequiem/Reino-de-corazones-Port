#ifdef VERSION_US
#include "event_174_text.inc"
#endif

static const MessageScriptEntry sEvent174Script[4] = {
    { PORTRAIT_RIKU, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent174Text00), 0, 100 },
    { PORTRAIT_RIKU, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent174Text01), 0, 250 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent174Text02), 0, 485 },
    { PORTRAIT_RIKU, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent174Text03), MSG_SCRIPT_FLAG_END, 750 },
};

#ifdef VERSION_JP
#include "event_174_text.inc"
#endif

static const EvSoundCue sEvent174SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent174Camera[1] = {
    { -64537, 194816, 62720, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent174Track0[15] = {
    { 547, 150, 195840, 64512, 0, 0, 2, NULL, NULL },
    { 545, 300, 0, 0, 0, 0, 5, NULL, NULL },
    { 546, 350, 0, 0, 0, 0, 5, NULL, NULL },
    { 514, 380, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 420, 0, 0, 0, 0, 5, NULL, NULL },
    { 514, 430, 0, 0, 0, 0, 5, NULL, NULL },
    { 514, 440, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 480, 0, 0, 0, 0, 69, NULL, NULL },
    { 538, 490, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 520, 0, 0, 0, 0, 69, NULL, NULL },
    { 514, 550, 0, 0, 0, 0, 69, NULL, NULL },
    { 514, 680, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 514, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 564, 2000, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent174Tracks[1] = {
    { sEvent174Track0, EVENT_CHARA_RIKU },
};

const EventSequenceDef gEvent174 = {
    ARRAY_COUNT(sEvent174Tracks),
    sEvent174Tracks,
    sEvent174Camera,
    sEvent174Script,
    sEvent174SoundCues,
    NULL,
    810,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_175_RIKU_B4F_DEMO,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
