#ifdef VERSION_US
#include "event_035_text.inc"
#endif

static const MessageScriptEntry sEvent035Script[3] = {
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent035Text00), 0, 340 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent035Text01), 0, 450 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent035Text02), MSG_SCRIPT_FLAG_END, 520 },
};

#ifdef VERSION_JP
#include "event_035_text.inc"
#endif

static const EventCameraKeyframe sEvent035Camera[1] = {
    { -65485, 55296, 51456, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent035SoundCues[2] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_BGM_EVENT_XIII, 735, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent035Track0[3] = {
    { 486, 50, 33792, 68864, 0, 0, 82, NULL, NULL },
    { 502, 130, 50176, 61952, 0, 486, 83, NULL, NULL },
    { 486, 5000, 0, 0, 0, 0, 32853, NULL, NULL },
};

static const EventCharaKeyframe sEvent035Track1[8] = {
    { 445, 160, 60928, 53760, 0, 0, 18, NULL, NULL },
    { 445, 290, 0, 0, 0, 0, 16, NULL, CreateBalloonTask },
    { 445, 360, 0, 0, 0, 0, 21, NULL, NULL },
    { 445, 410, 0, 0, 0, 0, 16, NULL, CreateExclamationTask },
    { 447, 480, 0, 0, 0, 0, 21, NULL, NULL },
    { 444, 550, 0, 0, 0, 0, 21, NULL, NULL },
    { 445, 680, 0, 0, 0, 0, 16, NULL, CreateBalloonTask },
    { 445, 5000, 0, 0, 0, 0, 32789, NULL, NULL },
};

static const EventCharaKeyframe sEvent035Track2[1] = {
    { 919, 5000, 62464, 52992, 0, 0, 33106, NULL, NULL },
};

static const EventCharaTrack sEvent035Tracks[3] = {
    { sEvent035Track0, EVENT_CHARA_AXEL },
    { sEvent035Track1, EVENT_CHARA_NAMINE },
    { sEvent035Track2, EVENT_CHARA_MAP_GIMMICK_44 },
};

const EventSequenceDef gEvent035 = {
    ARRAY_COUNT(sEvent035Tracks),
    sEvent035Tracks,
    sEvent035Camera,
    sEvent035Script,
    sEvent035SoundCues,
    NULL,
    740,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_036_9F_ENTRANCE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
