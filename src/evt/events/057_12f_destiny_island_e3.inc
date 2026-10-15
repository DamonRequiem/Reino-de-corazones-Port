#ifdef VERSION_US
#include "event_057_text.inc"
#endif

static const MessageScriptEntry sEvent057Script[3] = {
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent057Text00), 0, 150 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent057Text01), 0, 335 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent057Text02), MSG_SCRIPT_FLAG_END, 635 },
};

#ifdef VERSION_JP
#include "event_057_text.inc"
#endif

static const EventCameraKeyframe sEvent057Camera[1] = {
    { -60536, 32512, 31488, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent057SoundCues[1] = {
    { SONG_NONE, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent057Track0[21] = {
    { 15, 180, 33024, 35840, 0, 0, 66, NULL, NULL },
    { 15, 310, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 15, 430, 0, 0, 0, 0, 69, NULL, NULL },
    { 15, 480, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 15, 490, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 510, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 515, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 520, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 545, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 550, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 555, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 560, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 565, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 590, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 595, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 630, 0, 0, 0, 0, 69, NULL, NULL },
    { 31, 655, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 675, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 680, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 695, 0, 0, 0, 0, 5, NULL, NULL },
    { 12, 1120, 0, 0, 0, 173, 32804, NULL, NULL },
};

static const EventCharaTrack sEvent057Tracks[1] = {
    { sEvent057Track0, EVENT_CHARA_SORA },
};

const EventSequenceDef gEvent057 = {
    ARRAY_COUNT(sEvent057Tracks),
    sEvent057Tracks,
    sEvent057Camera,
    sEvent057Script,
    sEvent057SoundCues,
    NULL,
    740,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_058_12F_GOAL,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
