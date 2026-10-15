#ifdef VERSION_US
#include "event_083_text.inc"
#endif

static const MessageScriptEntry sEvent083Script[5] = {
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent083Text00), 0, 100 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent083Text01), 0, 481 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent083Text02), 0, 500 },
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent083Text03), 0, 540 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent083Text04), MSG_SCRIPT_FLAG_YES_NO | MSG_SCRIPT_FLAG_END, 580 },
};

#ifdef VERSION_JP
#include "event_083_text.inc"
#endif

static const EventCameraKeyframe sEvent083Camera[2] = {
    { -65416, 33792, 35840, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent083SoundCues[2] = {
    { SONG_BGM_EVENT1, 0, 0, 0 },
    { SONG_BGM_EVENT1, 599, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent083Track0[4] = {
    { 2, 200, 35072, 36864, 0, 0, 2, NULL, NULL },
    { 2, 450, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 2, 500, 0, 0, 0, 0, 5, NULL, NULL },
    { 32, 550, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent083Track1[4] = {
    { 136, 101, 40448, 42752, 0, 0, 2, NULL, NULL },
    { 112, 200, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 450, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 112, 900, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent083Track2[9] = {
    { 144, 200, 26112, 39168, 0, 0, 2, NULL, NULL },
    { 144, 450, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 144, 460, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 465, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 480, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 482, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 580, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 581, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent083Track3[3] = {
    { 229, 510, 24832, 45056, 0, 0, 2, NULL, NULL },
    { 229, 520, 0, 0, 0, 0, 69, NULL, NULL },
    { 231, 550, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent083Tracks[4] = {
    { sEvent083Track0, EVENT_CHARA_SORA },
    { sEvent083Track1, EVENT_CHARA_DONALD },
    { sEvent083Track2, EVENT_CHARA_GOOFY },
    { sEvent083Track3, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent083 = {
    ARRAY_COUNT(sEvent083Tracks),
    sEvent083Tracks,
    sEvent083Camera,
    sEvent083Script,
    sEvent083SoundCues,
    NULL,
    600,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_SHADOW_100,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
