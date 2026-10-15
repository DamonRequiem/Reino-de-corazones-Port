#ifdef VERSION_US
#include "event_001_text.inc"
#endif

static const MessageScriptEntry sEvent001Script[3] = {
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent001Text00), 0, 190 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent001Text01), 0, 230 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent001Text02), MSG_SCRIPT_FLAG_END, 650 },
};

#ifdef VERSION_JP
#include "event_001_text.inc"
#endif

static const EvSoundCue sEvent001SoundCues[3] = {
    { SONG_BGM_T13THFLOOR, 0, 0, 0 },
    { SONG_BGM_T13THFLOOR, 718, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_EV_WHITEOUT, 720, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent001Camera[4] = {
    { -65536, 208896, 46592, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -65386, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 100, NULL },
    { -64816, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -64766, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_WHITE | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 50, NULL },
};

static const EventCharaKeyframe sEvent001Track0[19] = {
    { 4, 150, 216320, 45056, 0, 0, 66, NULL, NULL },
    { 3, 155, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 165, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 300, 0, 0, 0, 0, 5, NULL, NULL },
    { 105, 310, 0, 0, 0, 0, 5, NULL, NULL },
    { 105, 360, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 105, 380, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 430, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 560, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 2, 600, 0, 0, 0, 0, 5, NULL, NULL },
    { 15, 610, 0, 0, 0, 0, 5, NULL, NULL },
    { 17, 620, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 680, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 685, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 690, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 695, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent001Track1[7] = {
    { 612, 160, 226816, 47104, 0, 0, 2, NULL, NULL },
    { 611, 303, 0, 0, 0, 0, 5, NULL, NULL },
    { 622, 313, 0, 0, 0, 0, 5, NULL, NULL },
    { 622, 363, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 622, 383, 0, 0, 0, 0, 5, NULL, NULL },
    { 611, 500, 0, 0, 0, 0, 5, NULL, NULL },
    { 612, 350, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent001Track2[7] = {
    { 647, 160, 211456, 40704, 0, 0, 66, NULL, NULL },
    { 647, 305, 0, 0, 0, 0, 5, NULL, NULL },
    { 663, 315, 0, 0, 0, 0, 5, NULL, NULL },
    { 663, 365, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 663, 385, 0, 0, 0, 0, 5, NULL, NULL },
    { 647, 490, 0, 0, 0, 0, 5, NULL, NULL },
    { 647, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent001Track3[3] = {
    { 180, 270, 197376, 65024, 0, 0, 66, NULL, NULL },
    { 180, 300, 0, 0, 0, 0, 64, EventCharaFadeOut, NULL },
    { 180, 301, 0, 0, 0, 0, 98370, NULL, NULL },
};

static const EventCharaTrack sEvent001Tracks[4] = {
    { sEvent001Track0, EVENT_CHARA_SORA },
    { sEvent001Track1, EVENT_CHARA_GOOFY_2 },
    { sEvent001Track2, EVENT_CHARA_DONALD_2 },
    { sEvent001Track3, EVENT_CHARA_ROBED_FIGURE },
};

const EventSequenceDef gEvent001 = {
    ARRAY_COUNT(sEvent001Tracks),
    sEvent001Tracks,
    sEvent001Camera,
    sEvent001Script,
    sEvent001SoundCues,
    NULL,
    840,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_002_1F_TRAVERSE_TOWN_E0_1,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
