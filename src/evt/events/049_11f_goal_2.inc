#ifdef VERSION_US
#include "event_049_text.inc"
#endif

static const MessageScriptEntry sEvent049Script[4] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent049Text00), 0, 430 },
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent049Text01), 0, 690 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent049Text02), 0, 750 },
    { PORTRAIT_GOOFY, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent049Text03), MSG_SCRIPT_FLAG_END, 1090 },
};

#ifdef VERSION_JP
#include "event_049_text.inc"
#endif

static const EventCameraKeyframe sEvent049Camera[5] = {
    { -65066, 179712, 68864, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64606, 203776, 56832, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 60, NULL },
    { -64596, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_WHITE | CAMERA_MODE_KEEP, 10, NULL },
    { -64586, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 10, NULL },
    { -64537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent049SoundCues[3] = {
    { SONG_BGM_EVENT_UNREST, 0, 0, 0 },
    { SONG_SND_360, 410, 0, 0 },
    { SONG_EV_FLASH01, 935, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent049Track0[11] = {
    { 21, 430, 173824, 76544, 0, 0, 66, NULL, NULL },
    { 25, 450, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 530, 202752, 63232, 0, 4, 67, NULL, NULL },
    { 4, 533, 203520, 62976, 0, 4, 67, NULL, NULL },
    { 4, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 710, 0, 0, 0, 0, 69, NULL, NULL },
    { 101, 870, 0, 0, 0, 0, 69, NULL, NULL },
    { 76, 940, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 990, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 1080, 0, 0, 0, 0, 69, NULL, NULL },
    { 75, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent049Track1[12] = {
    { 123, 520, 168960, 84992, 0, 0, 66, NULL, NULL },
    { 120, 605, 201216, 70400, 0, 114, 67, NULL, NULL },
    { 114, 607, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 620, 0, 0, 0, 0, 69, NULL, NULL },
    { 119, 660, 213504, 64768, 0, 114, 67, NULL, NULL },
    { 114, 665, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 670, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 689, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 691, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 940, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 990, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 114, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent049Track2[8] = {
    { 158, 525, 160768, 79616, 0, 0, 66, NULL, NULL },
    { 153, 610, 193024, 65024, 0, 146, 67, NULL, NULL },
    { 146, 612, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 940, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 990, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 146, 1089, 0, 0, 0, 0, 69, NULL, NULL },
    { 165, 1091, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent049Track3[7] = {
    { 699, 300, 193792, 67328, 0, 0, 2, NULL, NULL },
    { 700, 310, 0, 0, 0, 0, 5, NULL, NULL },
    { 695, 320, 0, 0, 0, 0, 5, NULL, NULL },
    { 695, 330, 0, 0, 0, 0, 69, NULL, NULL },
    { 696, 340, 0, 0, 0, 0, 69, NULL, NULL },
    { 710, 400, 0, 0, 0, 45, 116, NULL, NULL },
    { 696, 401, 0, 0, 0, 0, 98370, NULL, NULL },
};

static const EventCharaKeyframe sEvent049Track4[9] = {
    { 909, 375, 0, 0, 0, 0, 8194, NULL, NULL },
    { 909, 395, 215552, 56576, -2560, 0, 16642, NULL, NULL },
    { 909, 410, 206336, 60416, 0, 909, 259, NULL, NULL },
    { 909, 728, 0, 0, 0, 0, 261, NULL, NULL },
    { 917, 744, 206336, 55296, -512, 909, 4355, NULL, NULL },
    { 917, 800, 0, 0, 0, 0, 261, NULL, NULL },
    { 917, 880, 206336, 55296, -11520, 909, 4355, NULL, NULL },
    { 917, 940, 0, 0, 0, 0, 261, NULL, NULL },
    { 917, 9000, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaKeyframe sEvent049Track5[4] = {
    { 591, 940, 0, 0, 0, 0, 8194, NULL, NULL },
    { 592, 1000, 206336, 55296, -11520, 591, 16643, NULL, NULL },
    { 592, 1080, 206336, 55296, -512, 591, 259, NULL, NULL },
    { 601, 9000, 203520, 62976, 0, 0, 33106, NULL, NULL },
};

static const EventCharaTrack sEvent049Tracks[6] = {
    { sEvent049Track0, EVENT_CHARA_SORA },
    { sEvent049Track1, EVENT_CHARA_DONALD },
    { sEvent049Track2, EVENT_CHARA_GOOFY },
    { sEvent049Track3, EVENT_CHARA_RIKU_REPLICA },
    { sEvent049Track4, EVENT_CHARA_OMAMORI },
    { sEvent049Track5, EVENT_CHARA_B_STATES_1 },
};

const EventSequenceDef gEvent049 = {
    ARRAY_COUNT(sEvent049Tracks),
    sEvent049Tracks,
    sEvent049Camera,
    sEvent049Script,
    sEvent049SoundCues,
    NULL,
    1200,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_050_11F_GOAL_3,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
