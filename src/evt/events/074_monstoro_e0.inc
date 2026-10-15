#ifdef VERSION_US
#include "event_074_text.inc"
#endif

static const MessageScriptEntry sEvent074Script[20] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text00), 0, 300 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text01), 0, 310 },
    { PORTRAIT_PINOCCHIO, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text02), MSG_SCRIPT_FLAG_SILHOUETTE, 340 },
    { PORTRAIT_DONALD, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text03), 0, 380 },
    { PORTRAIT_PINOCCHIO, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text04), MSG_SCRIPT_FLAG_SILHOUETTE, 420 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text05), 0, 430 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text06), 0, 460 },
    { PORTRAIT_PINOCCHIO, 3, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text07), 0, 600 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text08), 0, 610 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text09), 0, 620 },
    { PORTRAIT_PINOCCHIO, 3, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text10), 0, 630 },
    { PORTRAIT_PINOCCHIO, 3, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text11), 0, 640 },
    { PORTRAIT_PINOCCHIO, 10, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text12), 0, 690 },
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text13), 0, 700 },
    { PORTRAIT_PINOCCHIO, 1, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text14), 0, 710 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text15), 0, 720 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text16), 0, 730 },
    { PORTRAIT_PINOCCHIO, 7, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text17), 0, 740 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text18), 0, 750 },
    { PORTRAIT_PINOCCHIO, 4, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent074Text19), MSG_SCRIPT_FLAG_END, 760 },
};

#ifdef VERSION_JP
#include "event_074_text.inc"
#endif

static const EventCameraKeyframe sEvent074Camera[3] = {
    { -65536, 30720, 20480, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -65436, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 80, NULL },
    { -65286, 30720, 20480, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 150, NULL },
};

static const EvSoundCue sEvent074SoundCues[3] = {
    { SONG_BGM_PINOCCHIO_FIELD, 0, 0, 0 },
    { SONG_SND_349, 641, 0, 0 },
    { SONG_BGM_PINOCCHIO_FIELD, 994, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent074Track0[20] = {
    { 4, 130, 20480, 35840, 0, 0, 66, NULL, NULL },
    { 3, 145, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 175, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 190, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 205, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 342, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 380, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 2, 390, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 400, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 405, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 490, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 560, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 570, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 720, 0, 0, 0, 0, 69, NULL, NULL },
    { 36, 751, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 825, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 830, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 855, 0, 0, 0, 0, 69, NULL, NULL },
    { 12, 999, 0, 0, 0, 83, 32868, NULL, NULL },
};

static const EventCharaKeyframe sEvent074Track1[22] = {
    { 146, 0, 40960, 28160, 0, 0, 66, NULL, NULL },
    { 142, 135, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 150, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 175, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 190, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 220, 0, 0, 0, 0, 69, NULL, NULL },
    { 142, 235, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 309, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 311, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 342, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 380, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 144, 390, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 400, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 490, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 550, 0, 0, 0, 0, 69, NULL, NULL },
    { 143, 570, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 729, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 731, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 800, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 870, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 880, 0, 0, 0, 0, 69, NULL, NULL },
    { 152, 999, 0, 0, 0, 83, 32868, NULL, NULL },
};

static const EventCharaKeyframe sEvent074Track2[16] = {
    { 114, 0, 25600, 23040, 0, 0, 66, NULL, NULL },
    { 114, 125, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 135, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 155, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 165, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 175, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 195, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 342, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 379, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 136, 381, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 390, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 400, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 405, 0, 0, 0, 0, 69, NULL, NULL },
    { 113, 410, 0, 0, 0, 0, 69, NULL, NULL },
    { 112, 900, 0, 0, 0, 0, 69, NULL, NULL },
    { 121, 999, 0, 0, 0, 83, 32868, NULL, NULL },
};

static const EventCharaKeyframe sEvent074Track3[10] = {
    { 229, 431, 256000, 256000, 0, 0, 2, NULL, NULL },
    { 232, 432, 20480, 35840, 0, 0, 66, NULL, NULL },
    { 234, 460, 0, 0, 0, 45, 68, EventCharaHop, NULL },
    { 233, 470, 0, 0, 0, 0, 64, EventCharaHop, NULL },
    { 229, 741, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 751, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 229, 800, 0, 0, 0, 0, 69, NULL, NULL },
    { 230, 810, 0, 0, 0, 173, 4, NULL, NULL },
    { 233, 825, 0, 0, 0, 173, 4, EventCharaHop, NULL },
    { 229, 1000, 256000, 256000, 0, 0, 32770, NULL, NULL },
};

static const EventCharaKeyframe sEvent074Track4[11] = {
    { 236, 465, 256000, 256000, 0, 0, 2, NULL, NULL },
    { 236, 456, 69120, 53760, 0, 0, 2, NULL, NULL },
    { 251, 570, 0, 0, 0, 211, 36, NULL, NULL },
    { 239, 573, 0, 0, 0, 211, 4, NULL, NULL },
    { 239, 641, 0, 0, 0, 0, 5, NULL, NULL },
    { 239, 690, 0, 0, 0, 0, 0, NULL, CreateGlowNoseTask },
    { 258, 691, 0, 0, 0, 0, 5, NULL, NULL },
    { 240, 761, 0, 0, 0, 0, 5, NULL, NULL },
    { 240, 766, 0, 0, 0, 0, 69, NULL, NULL },
    { 237, 770, 0, 0, 0, 0, 69, NULL, NULL },
    { 243, 890, 0, 0, 0, 83, 32836, NULL, NULL },
};

static const EventCharaTrack sEvent074Tracks[5] = {
    { sEvent074Track0, EVENT_CHARA_SORA },
    { sEvent074Track1, EVENT_CHARA_GOOFY },
    { sEvent074Track2, EVENT_CHARA_DONALD },
    { sEvent074Track3, EVENT_CHARA_JIMINY_CRICKET },
    { sEvent074Track4, EVENT_CHARA_PINOCCHIO },
};

const EventSequenceDef gEvent074 = {
    ARRAY_COUNT(sEvent074Tracks),
    sEvent074Tracks,
    sEvent074Camera,
    sEvent074Script,
    sEvent074SoundCues,
    NULL,
    999,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    1,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
