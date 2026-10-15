#ifdef VERSION_US
#include "event_013_text.inc"
#endif

static const MessageScriptEntry sEvent013Script[17] = {
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text00), 0, 395 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text01), 0, 495 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text02), 0, 705 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text03), 0, 707 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text04), 0, 795 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text05), 0, 905 },
    { PORTRAIT_DONALD, 3, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text06), 0, 965 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text07), 0, 990 },
    { PORTRAIT_DONALD, 3, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text08), 0, 1020 },
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text09), 0, 1295 },
    { PORTRAIT_JIMINY_CRICKET, 3, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text10), 0, 1400 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text11), 0, 1402 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text12), 0, 1705 },
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text13), 0, 1785 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text14), 0, 1820 },
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text15), 0, 1822 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent013Text16), MSG_SCRIPT_FLAG_END, 1880 },
};

#ifdef VERSION_JP
#include "event_013_text.inc"
#endif

static const EventCameraKeyframe sEvent013Camera[1] = {
    { -65485, 197632, 58368, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent013SoundCues[2] = {
    { SONG_BGM_T13THFLOOR, 0, 0, 0 },
    { SONG_EV_DL_JUMP, 1730, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent013Track0[20] = {
    { 4, 1, 170496, 76800, 0, 0, 66, NULL, NULL },
    { 9, 171, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 230, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 235, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 240, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 245, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 310, 0, 0, 0, 0, 5, NULL, NULL },
    { 7, 340, 0, 0, 0, 173, 4, NULL, NULL },
    { 2, 520, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 650, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 2, 720, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 770, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 2, 790, 0, 0, 0, 0, 5, NULL, NULL },
    { 31, 880, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 900, 0, 0, 0, 0, 5, NULL, NULL },
    { 32, 1560, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1580, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1630, 0, 0, 0, 0, 0, NULL, CreateQuestionTask },
    { 2, 1850, 0, 0, 0, 0, 5, NULL, NULL },
    { 32, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent013Track1[27] = {
    { 114, 51, 158720, 89856, 0, 0, 66, NULL, NULL },
    { 119, 231, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 270, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 310, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 360, 0, 0, 0, 0, 0, NULL, CreateQuestionTask },
    { 114, 390, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 397, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 520, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 650, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 114, 930, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 935, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 960, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 967, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1015, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 1022, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1037, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1167, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 114, 1290, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 1297, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1360, 0, 0, 0, 0, 69, NULL, NULL },
    { 110, 1365, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1580, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 1630, 0, 0, 0, 0, 0, NULL, CreateQuestionTask },
    { 114, 1730, 0, 0, 0, 0, 5, NULL, NULL },
    { 130, 1760, 0, 0, 0, 0, 0, EventCharaHop, NULL },
    { 114, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent013Track2[14] = {
    { 146, 1, 156672, 77056, 0, 0, 66, NULL, NULL },
    { 151, 131, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 170, 290, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 170, 405, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 440, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 450, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 490, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 497, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 164, 709, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 1580, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 1630, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 144, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent013Track3[9] = {
    { 229, 1320, 0, 0, 0, 0, 2, NULL, NULL },
    { 229, 1321, 199168, 62976, 0, 0, 2, NULL, NULL },
    { 233, 1350, 0, 0, 0, 173, 4, EventCharaHop, NULL },
    { 229, 1370, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 1500, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 1550, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 229, 1700, 0, 0, 0, 0, 69, NULL, NULL },
    { 233, 1710, 0, 0, 0, 0, 64, EventCharaHop, NULL },
    { 229, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent013Tracks[4] = {
    { sEvent013Track0, EVENT_CHARA_SORA },
    { sEvent013Track1, EVENT_CHARA_DONALD },
    { sEvent013Track2, EVENT_CHARA_GOOFY },
    { sEvent013Track3, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent013 = {
    ARRAY_COUNT(sEvent013Tracks),
    sEvent013Tracks,
    sEvent013Camera,
    sEvent013Script,
    sEvent013SoundCues,
    NULL,
    1940,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_014_2F_DEMO,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
