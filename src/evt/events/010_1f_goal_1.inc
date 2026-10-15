#ifdef VERSION_US
#include "event_010_text.inc"
#endif

static const MessageScriptEntry sEvent010Script[14] = {
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text00), 0, 230 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text01), 0, 260 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text02), 0, 290 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text03), 0, 590 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text04), 0, 620 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text05), 0, 650 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text06), 0, 900 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text07), 0, 930 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text08), 0, 1130 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text09), 0, 1132 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text10), 0, 1136 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text11), 0, 1170 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text12), 0, 1200 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent010Text13), MSG_SCRIPT_FLAG_END, 1500 },
};

#ifdef VERSION_JP
#include "event_010_text.inc"
#endif

static const EvSoundCue sEvent010SoundCues[7] = {
    { SONG_BGM_T13THFLOOR, 0, 0, 0 },
    { SONG_EV_WARPOUT, 560, 0, 0 },
    { SONG_BGM_EVENT_XIII, 580, 0, 0 },
    { SONG_EV_CARDTHR, 846, 0, 0 },
    { SONG_EV_EV34_02, 1220, 0, 0 },
    { SONG_EV_EV34_03, 1309, 0, 0 },
    { SONG_BGM_EVENT2, 1340, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent010Camera[7] = {
    { -65016, 183808, 65536, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64546, 183296, 61184, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 30, NULL },
    { -64236, 179456, 65792, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 60, NULL },
    { -64226, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_WHITE | CAMERA_MODE_KEEP, 10, NULL },
    { -64196, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 20, NULL },
    { -63856, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -63796, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_BLACK | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 30, NULL },
};

static const EventCharaKeyframe sEvent010Track0[17] = {
    { 4, 1, 149504, 87552, 0, 0, 66, NULL, NULL },
    { 9, 120, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 130, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 180, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 27, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 310, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 360, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 380, 0, 0, 0, 0, 69, NULL, NULL },
    { 19, 395, 0, 0, 0, 0, 69, NULL, NULL },
    { 21, 621, 0, 0, 0, 0, 69, NULL, NULL },
    { 22, 636, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1140, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 1210, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1330, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1380, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 1400, 0, 0, 0, 0, 69, NULL, NULL },
    { 19, 2000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent010Track1[14] = {
    { 114, 1, 146688, 94976, 0, 0, 66, NULL, NULL },
    { 119, 120, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 140, 0, 0, 0, 0, 69, NULL, NULL },
    { 133, 190, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 133, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 405, 0, 0, 0, 0, 69, NULL, NULL },
    { 122, 420, 0, 0, 0, 0, 69, NULL, NULL },
    { 123, 621, 0, 0, 0, 0, 69, NULL, NULL },
    { 124, 636, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1330, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1380, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 114, 1405, 0, 0, 0, 0, 69, NULL, NULL },
    { 122, 1420, 0, 0, 0, 0, 69, NULL, NULL },
    { 123, 1999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent010Track2[14] = {
    { 146, 1, 136704, 90624, 0, 0, 66, NULL, NULL },
    { 151, 120, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 150, 0, 0, 0, 0, 69, NULL, NULL },
    { 161, 200, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 161, 220, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 415, 0, 0, 0, 0, 69, NULL, NULL },
    { 157, 430, 0, 0, 0, 0, 69, NULL, NULL },
    { 158, 621, 0, 0, 0, 0, 69, NULL, NULL },
    { 159, 636, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 1330, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 1380, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 146, 1405, 0, 0, 0, 0, 69, NULL, NULL },
    { 157, 1420, 0, 0, 0, 0, 69, NULL, NULL },
    { 158, 1999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent010Track3[15] = {
    { 485, 550, 0, 0, 0, 0, 8258, NULL, NULL },
    { 485, 845, 171776, 60160, 0, 0, 16450, EventCharaFadeIn, NULL },
    { 487, 850, 0, 0, 0, 0, 69, NULL, NULL },
    { 488, 910, 0, 0, 0, 0, 69, NULL, NULL },
    { 489, 920, 0, 0, 0, 0, 69, NULL, NULL },
    { 485, 1000, 0, 0, 0, 0, 69, NULL, NULL },
    { 494, 1080, 192768, 67584, 0, 485, 67, NULL, NULL },
    { 485, 1100, 0, 0, 0, 0, 69, NULL, NULL },
    { 485, 1133, 0, 0, 0, 0, 5, NULL, NULL },
    { 499, 1195, 0, 0, 0, 0, 5, NULL, NULL },
    { 485, 1210, 0, 0, 0, 0, 5, NULL, NULL },
    { 490, 1261, 0, 0, 0, 0, 5, NULL, NULL },
    { 491, 1309, 0, 0, 0, 0, 5, NULL, NULL },
    { 492, 1360, 0, 0, 0, 0, 5, NULL, NULL },
    { 493, 1999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent010Track4[3] = {
    { 485, 1296, 0, 0, 0, 0, 2, NULL, NULL },
    { 512, 1309, 192768, 67584, 0, 0, 2, NULL, NULL },
    { 485, 1999, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaKeyframe sEvent010Track5[15] = {
    { 181, 100, 221440, 54016, 0, 0, 2, NULL, NULL },
    { 184, 180, 0, 0, 0, 173, 4, NULL, NULL },
    { 181, 310, 0, 0, 0, 0, 5, NULL, NULL },
    { 184, 330, 198144, 65792, 0, 178, 3, NULL, NULL },
    { 178, 470, 0, 0, 0, 0, 5, NULL, NULL },
    { 178, 520, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 178, 680, 0, 0, 0, 0, 5, NULL, NULL },
    { 178, 810, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 178, 830, 0, 0, 0, 0, 5, NULL, NULL },
    { 190, 841, 0, 0, 0, 0, 5, NULL, NULL },
    { 191, 863, 0, 0, 0, 0, 5, NULL, NULL },
    { 189, 868, 0, 0, 0, 0, 5, NULL, NULL },
    { 178, 960, 0, 0, 0, 0, 5, NULL, NULL },
    { 178, 1200, 0, 0, 0, 45, 4, EventCharaFadeOut, NULL },
    { 178, 1820, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaKeyframe sEvent010Track6[6] = {
    { 591, 837, 0, 0, 0, 0, 8194, NULL, NULL },
    { 605, 841, 198144, 65792, 0, 0, 16658, NULL, NULL },
    { 591, 846, 186880, 51968, 0, 0, 274, NULL, NULL },
    { 591, 850, 176384, 49408, 0, 591, 275, NULL, NULL },
    { 606, 910, 171776, 60160, 0, 0, 338, NULL, NULL },
    { 591, 1999, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaTrack sEvent010Tracks[7] = {
    { sEvent010Track0, EVENT_CHARA_SORA },
    { sEvent010Track1, EVENT_CHARA_DONALD },
    { sEvent010Track2, EVENT_CHARA_GOOFY },
    { sEvent010Track3, EVENT_CHARA_AXEL },
    { sEvent010Track4, EVENT_CHARA_AXEL },
    { sEvent010Track5, EVENT_CHARA_ROBED_FIGURE },
    { sEvent010Track6, EVENT_CHARA_B_STATES_1 },
};

const EventSequenceDef gEvent010 = {
    ARRAY_COUNT(sEvent010Tracks),
    sEvent010Tracks,
    sEvent010Camera,
    sEvent010Script,
    sEvent010SoundCues,
    NULL,
    1560,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_AXEL_1,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
