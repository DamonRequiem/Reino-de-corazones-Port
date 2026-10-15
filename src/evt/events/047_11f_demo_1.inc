#ifdef VERSION_US
#include "event_047_text.inc"
#endif

static const MessageScriptEntry sEvent047Script[15] = {
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text00), 0, 130 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text01), 0, 160 },
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text02), 0, 180 },
    { PORTRAIT_LARXENE, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text03), 0, 182 },
    { PORTRAIT_LARXENE, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text04), 0, 332 },
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text05), 0, 334 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text06), 0, 360 },
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text07), 0, 380 },
    { PORTRAIT_MARLUXIA, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text08), 0, 420 },
    { PORTRAIT_NAMINE, 4, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text09), 0, 570 },
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text10), 0, 590 },
    { PORTRAIT_NAMINE, 4, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text11), 0, 630 },
    { PORTRAIT_MARLUXIA, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text12), 0, 650 },
    { PORTRAIT_NAMINE, 4, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text13), 0, 940 },
    { PORTRAIT_NAMINE, 5, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent047Text14), MSG_SCRIPT_FLAG_END, 1200 },
};

#ifdef VERSION_JP
#include "event_047_text.inc"
#endif

static const EventCameraKeyframe sEvent047Camera[2] = {
    { -64596, 76288, 54272, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -60536, 92416, 63232, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 100, NULL },
};

static const EvSoundCue sEvent047SoundCues[4] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_EV_WARPIN, 660, 0, 0 },
    { SONG_EV_WARPIN, 730, 0, 0 },
    { SONG_BGM_EVENT_XIII, 735, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent047Track0[6] = {
    { 856, 420, 82176, 57600, 0, 0, 18, NULL, NULL },
    { 856, 580, 0, 0, 0, 0, 85, NULL, NULL },
    { 857, 680, 0, 0, 0, 0, 85, NULL, NULL },
    { 856, 730, 0, 0, 0, 0, 85, NULL, NULL },
    { 856, 760, 0, 0, 0, 0, 80, EventCharaFadeOut, NULL },
    { 856, 1000, 0, 0, 0, 0, 98373, NULL, NULL },
};

static const EventCharaKeyframe sEvent047Track1[8] = {
    { 486, 1, 36096, 65280, 0, 0, 82, NULL, NULL },
    { 502, 90, 57088, 57088, 0, 486, 83, NULL, NULL },
    { 486, 110, 0, 0, 0, 0, 85, NULL, NULL },
    { 485, 190, 0, 0, 0, 0, 85, NULL, NULL },
    { 509, 320, 0, 0, 0, 0, 80, NULL, CreateBalloonTask },
    { 509, 810, 0, 0, 0, 0, 85, NULL, NULL },
    { 509, 940, 0, 0, 0, 0, 80, NULL, CreateBalloonTask },
    { 509, 999, 0, 0, 0, 0, 32853, NULL, NULL },
};

static const EventCharaKeyframe sEvent047Track2[5] = {
    { 842, 390, 77312, 70144, 0, 0, 18, NULL, NULL },
    { 842, 400, 0, 0, 0, 0, 85, NULL, NULL },
    { 841, 660, 0, 0, 0, 0, 69, NULL, NULL },
    { 841, 690, 0, 0, 0, 0, 80, EventCharaFadeOut, NULL },
    { 841, 1000, 0, 0, 0, 0, 98370, NULL, NULL },
};

static const EventCharaKeyframe sEvent047Track3[7] = {
    { 445, 430, 99840, 70400, 0, 0, 2, NULL, NULL },
    { 445, 560, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 445, 790, 0, 0, 0, 0, 5, NULL, NULL },
    { 445, 920, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 445, 1020, 0, 0, 0, 0, 5, NULL, NULL },
    { 447, 1150, 0, 0, 0, 0, 5, NULL, NULL },
    { 444, 2000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent047Track4[1] = {
    { 919, 30, 100352, 70144, 0, 0, 33090, NULL, NULL },
};

static const EventCharaTrack sEvent047Tracks[5] = {
    { sEvent047Track0, EVENT_CHARA_LARXENE },
    { sEvent047Track1, EVENT_CHARA_AXEL },
    { sEvent047Track2, EVENT_CHARA_MARLUXIA },
    { sEvent047Track3, EVENT_CHARA_NAMINE },
    { sEvent047Track4, EVENT_CHARA_MAP_GIMMICK_44 },
};

const EventSequenceDef gEvent047 = {
    ARRAY_COUNT(sEvent047Tracks),
    sEvent047Tracks,
    sEvent047Camera,
    sEvent047Script,
    sEvent047SoundCues,
    NULL,
    1260,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_048_11F_GOAL_1,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
