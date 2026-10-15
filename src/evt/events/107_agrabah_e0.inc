#ifdef VERSION_US
#include "event_107_text.inc"
#endif

static const MessageScriptEntry sEvent107Script[4] = {
    { PORTRAIT_GOOFY, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent107Text00), 0, 190 },
    { PORTRAIT_DONALD, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent107Text01), 0, 350 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent107Text02), 0, 550 },
    { PORTRAIT_ALADDIN, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent107Text03), MSG_SCRIPT_FLAG_END, 570 },
};

#ifdef VERSION_JP
#include "event_107_text.inc"
#endif

static const EventCameraKeyframe sEvent107Camera[4] = {
    { -65536, 33024, 87296, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -65455, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 80, NULL },
    { -65286, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -55537, 87040, 60160, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 80, NULL },
};

static const EvSoundCue sEvent107SoundCues[1] = {
    { SONG_BGM_ALADDIN_FIELD, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent107Track0[1] = {
    { 278, 9999, 89600, 61696, 0, 0, 32834, NULL, NULL },
};

static const EventCharaKeyframe sEvent107Track1[20] = {
    { 146, 1, 15360, 98816, 0, 0, 66, NULL, NULL },
    { 151, 90, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 150, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 146, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 165, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 170, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 175, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 189, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 191, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 200, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 205, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 215, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 220, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 153, 520, 0, 0, 0, 45, 100, NULL, NULL },
    { 146, 523, 0, 0, 0, 45, 100, NULL, NULL },
    { 146, 530, 0, 0, 0, 0, 69, NULL, NULL },
    { 157, 540, 0, 0, 0, 0, 69, NULL, NULL },
    { 158, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent107Track2[9] = {
    { 4, 1, 8192, 107520, 0, 0, 66, NULL, NULL },
    { 9, 90, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 200, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 260, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 14, 510, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 513, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 520, 0, 0, 0, 0, 69, NULL, NULL },
    { 19, 1000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent107Track3[10] = {
    { 114, 1, 0, 102400, 0, 0, 66, NULL, NULL },
    { 119, 90, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 200, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 260, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 114, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 120, 510, 0, 0, 0, 45, 100, NULL, NULL },
    { 114, 513, 0, 0, 0, 45, 100, NULL, NULL },
    { 114, 520, 0, 0, 0, 0, 69, NULL, NULL },
    { 122, 530, 0, 0, 0, 0, 69, NULL, NULL },
    { 123, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent107Track4[2] = {
    { 475, 10, 77824, 55296, 0, 0, 66, NULL, NULL },
    { 472, 9999, 0, 0, 0, 0, 33093, NULL, NULL },
};

static const EventCharaKeyframe sEvent107Track5[2] = {
    { 475, 30, 90112, 52992, 0, 0, 2, NULL, NULL },
    { 472, 9999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent107Track6[2] = {
    { 475, 60, 98304, 54016, 0, 0, 2, NULL, NULL },
    { 472, 9999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent107Track7[2] = {
    { 475, 90, 106752, 58368, 0, 0, 2, NULL, NULL },
    { 472, 9999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent107Track8[2] = {
    { 475, 120, 100608, 65024, 0, 0, 66, NULL, NULL },
    { 473, 9999, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaTrack sEvent107Tracks[9] = {
    { sEvent107Track0, EVENT_CHARA_ALADDIN },
    { sEvent107Track1, EVENT_CHARA_GOOFY },
    { sEvent107Track2, EVENT_CHARA_SORA },
    { sEvent107Track3, EVENT_CHARA_DONALD },
    { sEvent107Track4, EVENT_CHARA_SHADOW },
    { sEvent107Track5, EVENT_CHARA_SHADOW },
    { sEvent107Track6, EVENT_CHARA_SHADOW },
    { sEvent107Track7, EVENT_CHARA_SHADOW },
    { sEvent107Track8, EVENT_CHARA_SHADOW },
};

const EventSequenceDef gEvent107 = {
    ARRAY_COUNT(sEvent107Tracks),
    sEvent107Tracks,
    sEvent107Camera,
    sEvent107Script,
    sEvent107SoundCues,
    NULL,
    620,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_EVENT_AGRABAH_1,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
