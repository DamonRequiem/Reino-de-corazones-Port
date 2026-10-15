#ifdef VERSION_US
#include "event_039_text.inc"
#endif

static const MessageScriptEntry sEvent039Script[10] = {
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent039Text00), 0, 305 },
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent039Text01), 0, 330 },
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent039Text02), 0, 360 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent039Text03), 0, 410 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent039Text04), 0, 440 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent039Text05), 0, 670 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent039Text06), 0, 672 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent039Text07), 0, 674 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent039Text08), 0, 750 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent039Text09), MSG_SCRIPT_FLAG_END, 780 },
};

#ifdef VERSION_JP
#include "event_039_text.inc"
#endif

static const EventCameraKeyframe sEvent039Camera[1] = {
    { -65485, 182016, 67328, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent039SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent039Track0[16] = {
    { 4, 5, 140800, 92928, 0, 0, 66, NULL, NULL },
    { 9, 220, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 230, 0, 0, 0, 0, 69, NULL, NULL },
    { 0, 235, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 240, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 245, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 380, 0, 0, 0, 0, 5, NULL, NULL },
    { 32, 490, 0, 0, 0, 0, 5, NULL, NULL },
    { 32, 620, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 32, 650, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 690, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 695, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 700, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 705, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 710, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent039Track1[5] = {
    { 114, 1, 151296, 94464, 0, 0, 66, NULL, NULL },
    { 119, 120, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 300, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 307, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent039Track2[6] = {
    { 146, 15, 130816, 91136, 0, 0, 66, NULL, NULL },
    { 151, 200, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 230, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 240, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 390, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent039Track3[7] = {
    { 231, 250, 0, 0, 0, 0, 66, NULL, NULL },
    { 229, 250, 189440, 68864, 0, 0, 2, NULL, NULL },
    { 233, 280, 0, 0, 0, 173, 4, EventCharaHop, NULL },
    { 229, 283, 0, 0, 0, 173, 4, NULL, NULL },
    { 229, 335, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 345, 0, 0, 0, 0, 69, NULL, NULL },
    { 231, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent039Tracks[4] = {
    { sEvent039Track0, EVENT_CHARA_SORA },
    { sEvent039Track1, EVENT_CHARA_DONALD },
    { sEvent039Track2, EVENT_CHARA_GOOFY },
    { sEvent039Track3, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent039 = {
    ARRAY_COUNT(sEvent039Tracks),
    sEvent039Tracks,
    sEvent039Camera,
    sEvent039Script,
    sEvent039SoundCues,
    NULL,
    810,
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
