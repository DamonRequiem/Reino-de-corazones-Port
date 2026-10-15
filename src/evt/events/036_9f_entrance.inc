#ifdef VERSION_US
#include "event_036_text.inc"
#endif

static const MessageScriptEntry sEvent036Script[14] = {
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text00), 0, 200 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text01), 0, 260 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text02), 0, 310 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text03), 0, 330 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text04), 0, 350 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text05), 0, 370 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text06), 0, 412 },
    { PORTRAIT_DONALD, 3, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text07), 0, 430 },
    { PORTRAIT_DONALD, 3, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text08), 0, 432 },
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text09), 0, 570 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text10), 0, 650 },
    { PORTRAIT_JIMINY_CRICKET, 4, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text11), 0, 652 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text12), 0, 680 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent036Text13), MSG_SCRIPT_FLAG_END, 682 },
};

#ifdef VERSION_JP
#include "event_036_text.inc"
#endif

static const EventCameraKeyframe sEvent036Camera[1] = {
    { -65485, 178944, 70912, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent036SoundCues[1] = {
    { SONG_BGM_T13THFLOOR, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent036Track0[17] = {
    { 4, 1, 139776, 92928, 0, 0, 66, NULL, NULL },
    { 9, 170, 182528, 72192, 0, 4, 67, NULL, NULL },
    { 4, 190, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 270, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 280, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 285, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 290, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 295, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 300, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 320, 0, 0, 0, 0, 5, NULL, NULL },
    { 15, 380, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 390, 0, 0, 0, 0, 5, NULL, NULL },
    { 15, 410, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 420, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 660, 0, 0, 0, 0, 5, NULL, NULL },
    { 15, 670, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent036Track1[12] = {
    { 114, 1, 141056, 101376, 0, 0, 66, NULL, NULL },
    { 119, 173, 176896, 82176, 0, 114, 67, NULL, NULL },
    { 114, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 260, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 114, 349, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 351, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 429, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 433, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 560, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 114, 569, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 571, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent036Track2[7] = {
    { 146, 1, 131328, 91904, 0, 0, 66, NULL, NULL },
    { 151, 175, 166144, 74240, 0, 146, 67, NULL, NULL },
    { 146, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 260, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 146, 369, 0, 0, 0, 0, 69, NULL, NULL },
    { 165, 371, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent036Track3[8] = {
    { 229, 580, 0, 0, 0, 0, 2, NULL, NULL },
    { 229, 581, 182528, 72192, 0, 0, 2, NULL, NULL },
    { 233, 610, 0, 0, 0, 173, 4, EventCharaHop, NULL },
    { 229, 620, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 630, 0, 0, 0, 0, 69, NULL, NULL },
    { 231, 651, 0, 0, 0, 0, 69, NULL, NULL },
    { 234, 653, 0, 0, 0, 0, 64, EventCharaHop, NULL },
    { 231, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent036Tracks[4] = {
    { sEvent036Track0, EVENT_CHARA_SORA },
    { sEvent036Track1, EVENT_CHARA_DONALD },
    { sEvent036Track2, EVENT_CHARA_GOOFY },
    { sEvent036Track3, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent036 = {
    ARRAY_COUNT(sEvent036Tracks),
    sEvent036Tracks,
    sEvent036Camera,
    sEvent036Script,
    sEvent036SoundCues,
    NULL,
    720,
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
