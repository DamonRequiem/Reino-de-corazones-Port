#ifdef VERSION_US
#include "event_141_text.inc"
#endif

static const MessageScriptEntry sEvent141Script[15] = {
    { PORTRAIT_TIGGER, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text00), 0, 210 },
    { PORTRAIT_WINNIE_THE_POOH, 1, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text01), 0, 240 },
    { PORTRAIT_TIGGER, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text02), 0, 270 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text03), 0, 370 },
    { PORTRAIT_TIGGER, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text04), 0, 410 },
    { PORTRAIT_TIGGER, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text05), 0, 414 },
    { PORTRAIT_TIGGER, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text06), 0, 418 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_TOP_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text07), 0, 450 },
    { PORTRAIT_TIGGER, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text08), 0, 480 },
    { PORTRAIT_TIGGER, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text09), 0, 484 },
    { PORTRAIT_TIGGER, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text10), 0, 870 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text11), 0, 900 },
    { PORTRAIT_TIGGER, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text12), 0, 930 },
    { PORTRAIT_TIGGER, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text13), 0, 934 },
    { PORTRAIT_WINNIE_THE_POOH, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent141Text14), MSG_SCRIPT_FLAG_END, 1270 },
};

#ifdef VERSION_JP
#include "event_141_text.inc"
#endif

static const EvSoundCue sEvent141SoundCues[14] = {
    { SONG_BGM_WINNIETHEPOOH, 1, 0, 0 },
    { SONG_BG_POO, 2, 0, 0 },
    { SONG_SYS_TIGGER_JP, 524, 0, 0 },
    { SONG_SYS_TIGGER_JP, 573, 0, 0 },
    { SONG_SYS_TIGGER_JP, 609, 0, 0 },
    { SONG_SYS_TIGGER_JP, 645, 0, 0 },
    { SONG_SYS_TIGGER_JP, 681, 0, 0 },
    { SONG_SYS_TIGGER_JP, 717, 0, 0 },
    { SONG_SYS_TIGGER_JP, 753, 0, 0 },
    { SONG_SYS_TIGGER_JP, 788, 0, 0 },
    { SONG_SND_961, 1015, 0, 0 },
    { SONG_SND_961, 1050, 0, 0 },
    { SONG_BG_POO, 1294, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_WINNIETHEPOOH, 1295, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent141Camera[7] = {
    { -65486, 588288, 323840, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65036, 582144, 319232, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 50, NULL },
    { -64986, 582144, 307200, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 80, NULL },
    { -64914, 588288, 312320, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 36, NULL },
    { -64842, 590592, 307200, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 72, NULL },
    { -64516, 588288, 318720, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 72, NULL },
    { -63536, 592896, 327424, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 70, NULL },
};

static const EventCharaKeyframe sEvent141Track0[13] = {
    { 4, 160, 580864, 329984, 0, 0, 66, NULL, NULL },
    { 0, 165, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 290, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 340, 0, 0, 0, 0, 0, NULL, CreateQuestionTask },
    { 4, 445, 0, 0, 0, 0, 5, NULL, NULL },
    { 30, 452, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 550, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 580, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 895, 0, 0, 0, 0, 69, NULL, NULL },
    { 36, 925, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 970, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 980, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 2000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent141Track1[32] = {
    { 822, 10, 551680, 306688, 0, 0, 66, NULL, NULL },
    { 833, 180, 574720, 322048, 0, 822, 67, NULL, NULL },
    { 822, 400, 0, 0, 0, 0, 69, NULL, NULL },
    { 826, 490, 0, 0, 0, 0, 69, NULL, NULL },
    { 823, 500, 0, 0, 0, 0, 69, NULL, NULL },
    { 830, 546, 0, 0, 0, 0, 85, NULL, NULL },
    { 831, 549, 0, 0, 0, 0, 85, NULL, NULL },
    { 831, 579, 583680, 315648, 0, 0, 4435, EventCharaHop, NULL },
    { 831, 582, 0, 0, 0, 0, 341, NULL, NULL },
    { 827, 585, 0, 0, 0, 0, 341, NULL, NULL },
    { 827, 615, 593152, 321024, 0, 0, 4435, EventCharaHop, NULL },
    { 827, 618, 0, 0, 0, 0, 341, NULL, NULL },
    { 831, 621, 0, 0, 0, 0, 341, NULL, NULL },
    { 831, 651, 602368, 316160, 0, 0, 4435, EventCharaHop, NULL },
    { 831, 654, 0, 0, 0, 0, 341, NULL, NULL },
    { 831, 657, 0, 0, 0, 0, 277, NULL, NULL },
    { 831, 687, 592896, 311040, 0, 0, 4371, EventCharaHop, NULL },
    { 831, 690, 0, 0, 0, 0, 277, NULL, NULL },
    { 827, 693, 0, 0, 0, 0, 277, NULL, NULL },
    { 827, 723, 583680, 315648, 0, 0, 4371, EventCharaHop, NULL },
    { 827, 726, 0, 0, 0, 0, 277, NULL, NULL },
    { 827, 729, 0, 0, 0, 0, 341, NULL, NULL },
    { 827, 759, 593152, 321024, 0, 0, 4435, EventCharaHop, NULL },
    { 827, 762, 0, 0, 0, 0, 341, NULL, NULL },
    { 828, 853, 0, 0, 0, 0, 277, NULL, NULL },
    { 832, 872, 0, 0, 0, 0, 277, NULL, NULL },
    { 834, 900, 0, 0, 0, 0, 277, NULL, NULL },
    { 822, 950, 0, 0, 0, 0, 277, NULL, NULL },
    { 822, 980, 0, 0, 0, 0, 341, NULL, NULL },
    { 824, 990, 0, 0, 0, 83, 372, NULL, NULL },
    { 824, 1150, 0, 0, 0, 83, 116, NULL, NULL },
    { 822, 2000, 0, 0, 0, 0, 98309, NULL, NULL },
};

static const EventCharaKeyframe sEvent141Track2[13] = {
    { 756, 155, 590080, 328960, 0, 0, 66, NULL, NULL },
    { 765, 165, 0, 0, 0, 0, 69, NULL, NULL },
    { 758, 580, 0, 0, 0, 0, 69, NULL, NULL },
    { 773, 620, 0, 0, 0, 0, 69, NULL, NULL },
    { 758, 650, 0, 0, 0, 0, 5, NULL, NULL },
    { 772, 730, 0, 0, 0, 0, 5, NULL, NULL },
    { 758, 980, 0, 0, 0, 0, 5, NULL, NULL },
    { 757, 1090, 0, 0, 0, 0, 5, NULL, NULL },
    { 757, 1110, 0, 0, 0, 0, 5, NULL, NULL },
    { 782, 1190, 0, 0, 0, 64, 4, NULL, NULL },
    { 757, 1200, 0, 0, 0, 0, 5, NULL, NULL },
    { 756, 1230, 0, 0, 0, 0, 5, NULL, NULL },
    { 795, 2000, 0, 0, 0, 0, 33093, NULL, NULL },
};

static const EventCharaTrack sEvent141Tracks[3] = {
    { sEvent141Track0, EVENT_CHARA_SORA },
    { sEvent141Track1, EVENT_CHARA_TIGGER },
    { sEvent141Track2, EVENT_CHARA_WINNIE_THE_POOH },
};

const EventSequenceDef gEvent141 = {
    ARRAY_COUNT(sEvent141Tracks),
    sEvent141Tracks,
    sEvent141Camera,
    sEvent141Script,
    sEvent141SoundCues,
    NULL,
    1300,
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
    0,
    WORLD_NONE,
    5,
};
