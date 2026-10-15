#ifdef VERSION_US
#include "event_096_text.inc"
#endif

static const MessageScriptEntry sEvent096Script[6] = {
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent096Text00), 0, 300 },
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent096Text01), 0, 340 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent096Text02), 0, 380 },
    { PORTRAIT_QUEEN_OF_HEARTS, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent096Text03), 0, 400 },
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent096Text04), 0, 670 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent096Text05), MSG_SCRIPT_FLAG_END, 710 },
};

#ifdef VERSION_JP
#include "event_096_text.inc"
#endif

static const EventCameraKeyframe sEvent096Camera[3] = {
    { -65126, 55040, 76800, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65056, 89600, 58880, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 30, NULL },
    { -64936, 55040, 76800, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 70, NULL },
};

static const EvSoundCue sEvent096SoundCues[3] = {
    { SONG_BGM_EVENT1, 0, 0, 0 },
    { SONG_EV_EV10_01, 650, 0, 0 },
    { SONG_BGM_EVENT1, 915, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent096Track0[22] = {
    { 21, 150, 50432, 79360, 0, 0, 66, NULL, NULL },
    { 22, 170, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 350, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 355, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 365, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 370, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 405, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 410, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 415, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 420, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 435, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 620, 0, 0, 0, 173, 68, NULL, NULL },
    { 4, 650, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 680, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 685, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 690, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 695, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 709, 0, 0, 0, 0, 5, NULL, NULL },
    { 31, 711, 0, 0, 0, 0, 5, NULL, NULL },
    { 12, 999, 0, 0, 0, 173, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent096Track1[22] = {
    { 158, 155, 37376, 78848, 0, 0, 66, NULL, NULL },
    { 159, 175, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 355, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 365, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 370, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 379, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 381, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 405, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 410, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 415, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 420, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 425, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 602, 0, 0, 0, 0, 69, NULL, NULL },
    { 151, 620, 0, 0, 0, 173, 68, NULL, NULL },
    { 146, 650, 0, 0, 0, 0, 69, NULL, NULL },
    { 161, 711, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 715, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 720, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 725, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 730, 0, 0, 0, 0, 5, NULL, NULL },
    { 152, 810, 16384, 94720, 0, 144, 32771, NULL, NULL },
};

static const EventCharaKeyframe sEvent096Track2[22] = {
    { 123, 158, 52736, 84480, 0, 0, 66, NULL, NULL },
    { 124, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 310, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 315, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 325, 0, 0, 0, 0, 69, NULL, NULL },
    { 111, 330, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 339, 0, 0, 0, 0, 5, NULL, NULL },
    { 125, 341, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 405, 0, 0, 0, 0, 5, NULL, NULL },
    { 111, 410, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 415, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 420, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 425, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 603, 0, 0, 0, 0, 69, NULL, NULL },
    { 119, 620, 0, 0, 0, 173, 68, NULL, NULL },
    { 114, 650, 0, 0, 0, 0, 69, NULL, NULL },
    { 133, 711, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 715, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 720, 0, 0, 0, 0, 69, NULL, NULL },
    { 111, 725, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 730, 0, 0, 0, 0, 5, NULL, NULL },
    { 121, 820, 20480, 97024, 0, 112, 32771, NULL, NULL },
};

static const EventCharaKeyframe sEvent096Track3[1] = {
    { 219, 999, 89600, 59136, 0, 0, 32770, NULL, NULL },
};

static const EventCharaKeyframe sEvent096Track4[8] = {
    { 206, 450, 82944, 50944, 0, 0, 2, NULL, NULL },
    { 212, 620, 0, 0, 0, 173, 4, NULL, NULL },
    { 206, 650, 0, 0, 0, 0, 5, NULL, NULL },
    { 209, 830, 0, 0, 0, 0, 5, NULL, NULL },
    { 206, 840, 0, 0, 0, 0, 5, NULL, NULL },
    { 206, 850, 0, 0, 0, 0, 69, NULL, NULL },
    { 212, 883, 0, 0, 0, 83, 68, NULL, NULL },
    { 212, 999, 0, 0, 0, 173, 32772, NULL, NULL },
};

static const EventCharaKeyframe sEvent096Track5[9] = {
    { 206, 450, 80128, 52736, 0, 0, 2, NULL, NULL },
    { 212, 605, 0, 0, 0, 173, 4, NULL, NULL },
    { 211, 635, 0, 0, 0, 211, 4, NULL, NULL },
    { 206, 650, 0, 0, 0, 0, 5, NULL, NULL },
    { 209, 830, 0, 0, 0, 0, 5, NULL, NULL },
    { 206, 840, 0, 0, 0, 0, 5, NULL, NULL },
    { 206, 850, 0, 0, 0, 0, 69, NULL, NULL },
    { 212, 910, 0, 0, 0, 83, 68, NULL, NULL },
    { 212, 999, 0, 0, 0, 173, 32772, NULL, NULL },
};

static const EventCharaKeyframe sEvent096Track6[7] = {
    { 206, 450, 76800, 54528, 0, 0, 2, NULL, NULL },
    { 212, 590, 0, 0, 0, 173, 4, NULL, NULL },
    { 212, 620, 0, 0, 0, 83, 68, NULL, NULL },
    { 206, 650, 0, 0, 0, 0, 5, NULL, NULL },
    { 209, 830, 0, 0, 0, 0, 5, NULL, NULL },
    { 206, 850, 0, 0, 0, 0, 5, NULL, NULL },
    { 212, 999, 0, 0, 0, 173, 32772, NULL, NULL },
};

static const EventCharaKeyframe sEvent096Track7[9] = {
    { 197, 450, 103680, 63232, 0, 0, 18, NULL, NULL },
    { 203, 620, 0, 0, 0, 173, 20, NULL, NULL },
    { 197, 650, 0, 0, 0, 0, 21, NULL, NULL },
    { 200, 830, 0, 0, 0, 0, 21, NULL, NULL },
    { 197, 840, 0, 0, 0, 0, 21, NULL, NULL },
    { 199, 850, 0, 0, 0, 0, 21, NULL, NULL },
    { 202, 878, 0, 0, 0, 211, 20, NULL, NULL },
    { 203, 920, 0, 0, 0, 173, 20, NULL, NULL },
    { 203, 999, 0, 0, 0, 173, 32772, NULL, NULL },
};

static const EventCharaKeyframe sEvent096Track8[10] = {
    { 197, 450, 100864, 65024, 0, 0, 18, NULL, NULL },
    { 203, 605, 0, 0, 0, 173, 20, NULL, NULL },
    { 203, 635, 0, 0, 0, 83, 84, NULL, NULL },
    { 197, 650, 0, 0, 0, 0, 21, NULL, NULL },
    { 200, 830, 0, 0, 0, 0, 21, NULL, NULL },
    { 197, 840, 0, 0, 0, 0, 21, NULL, NULL },
    { 199, 850, 0, 0, 0, 0, 21, NULL, NULL },
    { 202, 910, 0, 0, 0, 211, 20, NULL, NULL },
    { 203, 940, 0, 0, 0, 173, 20, NULL, NULL },
    { 203, 999, 0, 0, 0, 173, 32772, NULL, NULL },
};

static const EventCharaKeyframe sEvent096Track9[9] = {
    { 197, 450, 97536, 66560, 0, 0, 18, NULL, NULL },
    { 203, 520, 0, 0, 0, 173, 20, NULL, NULL },
    { 203, 590, 0, 0, 0, 173, 20, NULL, NULL },
    { 202, 620, 0, 0, 0, 211, 20, NULL, NULL },
    { 197, 650, 0, 0, 0, 0, 21, NULL, NULL },
    { 200, 830, 0, 0, 0, 0, 21, NULL, NULL },
    { 197, 850, 0, 0, 0, 0, 21, NULL, NULL },
    { 203, 900, 0, 0, 0, 173, 20, NULL, NULL },
    { 203, 999, 0, 0, 0, 173, 32772, NULL, NULL },
};

static const EventCharaTrack sEvent096Tracks[10] = {
    { sEvent096Track0, EVENT_CHARA_SORA },
    { sEvent096Track1, EVENT_CHARA_GOOFY },
    { sEvent096Track2, EVENT_CHARA_DONALD },
    { sEvent096Track3, EVENT_CHARA_QUEEN_OF_HEARTS },
    { sEvent096Track4, EVENT_CHARA_CARD_SOLDIER_SPADE },
    { sEvent096Track5, EVENT_CHARA_CARD_SOLDIER_SPADE },
    { sEvent096Track6, EVENT_CHARA_CARD_SOLDIER_SPADE },
    { sEvent096Track7, EVENT_CHARA_CARD_SOLDIER_HEART },
    { sEvent096Track8, EVENT_CHARA_CARD_SOLDIER_HEART },
    { sEvent096Track9, EVENT_CHARA_CARD_SOLDIER_HEART },
};

const EventSequenceDef gEvent096 = {
    ARRAY_COUNT(sEvent096Tracks),
    sEvent096Tracks,
    sEvent096Camera,
    sEvent096Script,
    sEvent096SoundCues,
    NULL,
    920,
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
