#ifdef VERSION_US
#include "event_166_text.inc"
#endif

static const MessageScriptEntry sEvent166Script[14] = {
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text00), 0, 115 },
    { PORTRAIT_ANSEM, 1, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text01), 0, 330 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text02), 0, 500 },
    { PORTRAIT_ANSEM, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text03), 0, 530 },
    { PORTRAIT_ANSEM, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text04), 0, 532 },
    { PORTRAIT_ANSEM, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text05), 0, 534 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text06), 0, 565 },
    { PORTRAIT_ANSEM, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text07), 0, 595 },
    { PORTRAIT_ANSEM, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text08), 0, 597 },
    { PORTRAIT_RIKU, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text09), 0, 770 },
    { PORTRAIT_RIKU, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text10), 0, 772 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text11), 0, 785 },
    { PORTRAIT_ANSEM, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text12), 0, 950 },
    { PORTRAIT_ANSEM, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent166Text13), MSG_SCRIPT_FLAG_END, 1100 },
};

#ifdef VERSION_JP
#include "event_166_text.inc"
#endif

static const EvSoundCue sEvent166SoundCues[5] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_SND_379, 410, 0, 0 },
    { SONG_BGM_EVENT_UNREST, 411, 0, 0 },
    { SONG_EV_CARDTHR, 989, 0, 0 },
    { SONG_SND_379, 1150, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent166Camera[2] = {
    { -65146, 175872, 68352, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -62536, 188416, 61696, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 80, NULL },
};

static const EventCharaKeyframe sEvent166Track0[24] = {
    { 515, 1, 141568, 92672, 0, 0, 66, NULL, NULL },
    { 522, 100, 0, 0, 0, 45, 100, NULL, NULL },
    { 515, 103, 175872, 75264, 0, 515, 67, NULL, NULL },
    { 515, 110, 0, 0, 0, 0, 69, NULL, NULL },
    { 538, 120, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 170, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 200, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 514, 220, 0, 0, 0, 0, 69, NULL, NULL },
    { 514, 340, 0, 0, 0, 0, 5, NULL, NULL },
    { 514, 390, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 514, 450, 0, 0, 0, 0, 5, NULL, NULL },
    { 514, 460, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 560, 0, 0, 0, 0, 69, NULL, NULL },
    { 538, 570, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 610, 0, 0, 0, 0, 69, NULL, NULL },
    { 530, 620, 0, 0, 0, 0, 69, NULL, NULL },
    { 530, 750, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 530, 773, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 780, 0, 0, 0, 0, 69, NULL, NULL },
    { 538, 788, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 995, 0, 0, 0, 0, 69, NULL, NULL },
    { 559, 1180, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 4000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent166Track1[10] = {
    { 688, 410, 0, 0, 0, 0, 2, NULL, NULL },
    { 688, 450, 201728, 63232, 0, 0, 2, EventCharaFadeIn, NULL },
    { 688, 795, 0, 0, 0, 0, 5, NULL, NULL },
    { 688, 925, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 688, 970, 0, 0, 0, 0, 5, NULL, NULL },
    { 692, 1050, 0, 0, 0, 0, 5, NULL, NULL },
    { 688, 1150, 0, 0, 0, 0, 5, NULL, NULL },
    { 688, 1200, 0, 0, 0, 0, 0, EventCharaFadeOut, NULL },
    { 688, 1500, 0, 0, 0, 0, 2, NULL, NULL },
    { 688, 4000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent166Track2[7] = {
    { 591, 988, 0, 0, 0, 0, 8258, NULL, NULL },
    { 591, 989, 194816, 58624, 0, 0, 16706, NULL, NULL },
    { 591, 1000, 181504, 65536, 0, 591, 323, NULL, NULL },
    { 591, 1008, 0, 0, 0, 0, 66, NULL, NULL },
    { 604, 1180, 175872, 75264, 0, 0, 338, NULL, NULL },
    { 591, 1200, 0, 0, 0, 0, 66, NULL, NULL },
    { 591, 4000, 0, 0, 0, 0, 98373, NULL, NULL },
};

static const EventCharaTrack sEvent166Tracks[3] = {
    { sEvent166Track0, EVENT_CHARA_RIKU },
    { sEvent166Track1, EVENT_CHARA_ANSEM },
    { sEvent166Track2, EVENT_CHARA_B_STATES_1 },
};

const EventSequenceDef gEvent166 = {
    ARRAY_COUNT(sEvent166Tracks),
    sEvent166Tracks,
    sEvent166Camera,
    sEvent166Script,
    sEvent166SoundCues,
    NULL,
    1240,
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
