#ifdef VERSION_US
#include "event_067_text.inc"
#endif

static const MessageScriptEntry sEvent067Script[14] = {
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text00), 0, 130 },
    { PORTRAIT_MARLUXIA, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text01), 0, 250 },
    { PORTRAIT_MARLUXIA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text02), 0, 460 },
    { PORTRAIT_RIKU_REPLICA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text03), 0, 480 },
    { PORTRAIT_RIKU_REPLICA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text04), 0, 635 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text05), 0, 940 },
    { PORTRAIT_NAMINE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text06), 0, 990 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text07), 0, 1050 },
    { PORTRAIT_GOOFY, 4, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text08), 0, 1105 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text09), 0, 1155 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text10), 0, 1215 },
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text11), 0, 1260 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text12), 0, 1290 },
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent067Text13), MSG_SCRIPT_FLAG_END, 1470 },
};

#ifdef VERSION_JP
#include "event_067_text.inc"
#endif

static const EventCameraKeyframe sEvent067Camera[7] = {
    { -65196, 172544, 70912, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65006, 223488, 50176, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 70, NULL },
    { -64996, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_WHITE | CAMERA_MODE_KEEP, 10, NULL },
    { -64986, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 10, NULL },
    { -64886, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -64506, 215808, 50688, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 70, NULL },
    { -56536, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent067SoundCues[5] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_BGM_EVENT_XIII, 345, EV_SOUND_FLAG_FADE_IN, 0 },
    { SONG_SND_367, 517, 0, 0 },
    { SONG_BGM_EVENT_XIII, 630, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_EVENT_UNREST, 945, EV_SOUND_FLAG_FADE_IN | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent067Track0[18] = {
    { 21, 180, 169984, 71168, 0, 0, 66, NULL, NULL },
    { 22, 192, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 310, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 27, 430, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 640, 188928, 72192, 0, 0, 66, NULL, NULL },
    { 14, 700, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 703, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 730, 0, 0, 0, 0, 69, NULL, NULL },
    { 34, 860, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 34, 880, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 900, 0, 0, 0, 0, 69, NULL, NULL },
    { 0, 905, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1010, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 1015, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1180, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 1210, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 3000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent067Track1[13] = {
    { 123, 175, 159744, 71168, 0, 0, 66, NULL, NULL },
    { 124, 187, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 133, 320, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 133, 430, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 640, 175872, 70912, 0, 0, 66, NULL, NULL },
    { 120, 720, 0, 0, 0, 45, 100, NULL, NULL },
    { 114, 723, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 1120, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 1125, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 1150, 0, 0, 0, 0, 69, NULL, NULL },
    { 136, 1160, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 3000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent067Track2[13] = {
    { 158, 185, 171776, 79616, 0, 0, 66, NULL, NULL },
    { 159, 197, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 161, 310, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 161, 430, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 640, 191744, 84224, 0, 0, 66, NULL, NULL },
    { 153, 740, 0, 0, 0, 45, 100, NULL, NULL },
    { 146, 743, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 1070, 0, 0, 0, 0, 69, NULL, NULL },
    { 142, 1075, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 1100, 0, 0, 0, 0, 5, NULL, NULL },
    { 165, 1107, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 3000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent067Track3[4] = {
    { 841, 560, 224000, 55808, 0, 0, 2, NULL, NULL },
    { 841, 630, 0, 0, 0, 0, 0, EventCharaFadeOut, CreateHanabiraTask },
    { 841, 560, 0, 0, 0, 0, 2, NULL, NULL },
    { 841, 3000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent067Track4[18] = {
    { 696, 1, 148224, 104704, 0, 0, 66, NULL, NULL },
    { 710, 125, 189440, 79616, 0, 696, 4195, NULL, NULL },
    { 696, 128, 0, 0, 0, 45, 68, NULL, NULL },
    { 696, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 716, 310, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 716, 481, 0, 0, 0, 0, 69, NULL, NULL },
    { 696, 492, 188928, 72960, 0, 0, 66, NULL, NULL },
    { 702, 520, 214784, 58624, 0, 696, 4163, NULL, NULL },
    { 702, 640, 0, 0, 0, 0, 69, NULL, NULL },
    { 696, 650, 0, 0, 0, 0, 69, NULL, NULL },
    { 695, 660, 0, 0, 0, 0, 69, NULL, NULL },
    { 711, 700, 230912, 60416, 0, 695, 67, NULL, NULL },
    { 695, 750, 0, 0, 0, 0, 69, NULL, NULL },
    { 696, 760, 0, 0, 0, 0, 69, NULL, NULL },
    { 696, 1240, 0, 0, 0, 0, 5, NULL, NULL },
    { 695, 1310, 0, 0, 0, 0, 5, NULL, NULL },
    { 695, 1440, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 695, 3000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent067Track5[13] = {
    { 428, 33, 136448, 93440, 0, 0, 66, NULL, NULL },
    { 449, 93, 0, 0, 0, 45, 100, NULL, NULL },
    { 428, 96, 0, 0, 0, 45, 68, NULL, NULL },
    { 428, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 428, 310, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 428, 730, 0, 0, 0, 0, 69, NULL, NULL },
    { 428, 731, 183040, 61696, 0, 0, 66, NULL, NULL },
    { 449, 800, 0, 0, 0, 45, 100, NULL, NULL },
    { 428, 803, 0, 0, 0, 45, 68, NULL, NULL },
    { 428, 820, 0, 0, 0, 0, 69, NULL, NULL },
    { 422, 960, 0, 0, 0, 0, 69, NULL, NULL },
    { 423, 980, 0, 0, 0, 0, 69, NULL, NULL },
    { 422, 3000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent067Tracks[6] = {
    { sEvent067Track0, EVENT_CHARA_SORA },
    { sEvent067Track1, EVENT_CHARA_DONALD },
    { sEvent067Track2, EVENT_CHARA_GOOFY },
    { sEvent067Track3, EVENT_CHARA_MARLUXIA },
    { sEvent067Track4, EVENT_CHARA_RIKU_REPLICA },
    { sEvent067Track5, EVENT_CHARA_NAMINE },
};

const EventSequenceDef gEvent067 = {
    ARRAY_COUNT(sEvent067Tracks),
    sEvent067Tracks,
    sEvent067Camera,
    sEvent067Script,
    sEvent067SoundCues,
    NULL,
    1530,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_068_13F_CASTLE_OBLIVION_LAST3,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
