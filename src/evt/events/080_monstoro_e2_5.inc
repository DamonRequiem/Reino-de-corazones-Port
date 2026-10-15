#ifdef VERSION_US
#include "event_080_text.inc"
#endif

static const MessageScriptEntry sEvent080Script[14] = {
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text00), 0, 230 },
    { PORTRAIT_PINOCCHIO, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text01), 0, 240 },
    { PORTRAIT_PINOCCHIO, 5, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text02), 0, 242 },
    { PORTRAIT_PINOCCHIO, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text03), 0, 244 },
    { PORTRAIT_PINOCCHIO, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text04), 0, 246 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text05), 0, 250 },
    { PORTRAIT_DONALD, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text06), 0, 260 },
    { PORTRAIT_PINOCCHIO, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text07), 0, 270 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text08), 0, 280 },
    { PORTRAIT_PINOCCHIO, 11, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text09), 0, 290 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text10), 0, 300 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text11), 0, 302 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text12), 0, 310 },
    { PORTRAIT_PINOCCHIO, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent080Text13), MSG_SCRIPT_FLAG_END, 320 },
};

#ifdef VERSION_JP
#include "event_080_text.inc"
#endif

static const EventCameraKeyframe sEvent080Camera[2] = {
    { -65436, 45568, 95488, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64986, 40704, 98048, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 50, NULL },
};

static const EvSoundCue sEvent080SoundCues[3] = {
    { SONG_BGM_PINOCCHIO_FIELD, 0, 0, 0 },
    { SONG_EV_DL_JUMP, 259, 0, 0 },
    { SONG_BGM_PINOCCHIO_FIELD, 545, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent080Track0[12] = {
    { 21, 130, 46080, 95488, 0, 0, 66, NULL, NULL },
    { 22, 145, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 150, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 155, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 160, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 249, 0, 0, 0, 0, 5, NULL, NULL },
    { 31, 251, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 351, 0, 0, 0, 0, 5, NULL, NULL },
    { 12, 360, 0, 0, 0, 173, 36, NULL, NULL },
    { 13, 370, 0, 0, 0, 192, 36, NULL, NULL },
    { 12, 999, 0, 0, 0, 173, 36, NULL, NULL },
    { 2, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent080Track1[9] = {
    { 123, 135, 49920, 100608, 0, 0, 66, NULL, NULL },
    { 124, 150, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 155, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 160, 0, 0, 0, 0, 5, NULL, NULL },
    { 113, 259, 0, 0, 0, 0, 5, NULL, NULL },
    { 130, 261, 0, 0, 0, 0, 5, NULL, NULL },
    { 113, 380, 0, 0, 0, 0, 5, NULL, NULL },
    { 121, 999, 0, 0, 0, 173, 36, NULL, NULL },
    { 113, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent080Track2[7] = {
    { 158, 140, 36864, 94208, 0, 0, 66, NULL, NULL },
    { 159, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 165, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 170, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 380, 0, 0, 0, 0, 5, NULL, NULL },
    { 152, 999, 0, 0, 0, 173, 36, NULL, NULL },
    { 143, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent080Track3[10] = {
    { 238, 0, 81408, 81920, 0, 0, 2, NULL, NULL },
    { 247, 125, 0, 0, 0, 173, 36, NULL, NULL },
    { 238, 128, 0, 0, 0, 173, 4, NULL, NULL },
    { 238, 145, 0, 0, 0, 0, 5, NULL, NULL },
    { 250, 160, 0, 0, 0, 211, 4, NULL, NULL },
    { 241, 289, 0, 0, 0, 0, 69, NULL, NULL },
    { 259, 291, 0, 0, 0, 0, 69, NULL, NULL },
    { 241, 380, 0, 0, 0, 0, 69, NULL, NULL },
    { 241, 390, 0, 0, 0, 0, 5, NULL, NULL },
    { 238, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent080Track4[8] = {
    { 229, 160, 0, 0, 0, 0, 2, NULL, NULL },
    { 229, 161, 46080, 95488, 0, 0, 2, NULL, NULL },
    { 233, 180, 0, 0, 0, 173, 4, EventCharaHop, NULL },
    { 230, 188, 0, 0, 0, 173, 4, NULL, NULL },
    { 229, 321, 0, 0, 0, 0, 5, NULL, NULL },
    { 232, 330, 0, 0, 0, 45, 68, NULL, NULL },
    { 234, 350, 0, 0, 0, 45, 68, EventCharaHop, NULL },
    { 229, 999, 0, 0, 0, 0, 32770, NULL, NULL },
};

static const EventCharaTrack sEvent080Tracks[5] = {
    { sEvent080Track0, EVENT_CHARA_SORA },
    { sEvent080Track1, EVENT_CHARA_DONALD },
    { sEvent080Track2, EVENT_CHARA_GOOFY },
    { sEvent080Track3, EVENT_CHARA_PINOCCHIO },
    { sEvent080Track4, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent080 = {
    ARRAY_COUNT(sEvent080Tracks),
    sEvent080Tracks,
    sEvent080Camera,
    sEvent080Script,
    sEvent080SoundCues,
    NULL,
    550,
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
