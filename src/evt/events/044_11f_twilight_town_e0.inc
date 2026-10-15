#ifdef VERSION_US
#include "event_044_text.inc"
#endif

static const MessageScriptEntry sEvent044Script[22] = {
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text00), 0, 620 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text01), 0, 650 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text02), 0, 790 },
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text03), 0, 820 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text04), 0, 860 },
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text05), 0, 900 },
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text06), 0, 1110 },
    { PORTRAIT_JIMINY_CRICKET, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text07), 0, 1140 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text08), 0, 1320 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text09), 0, 1370 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text10), 0, 1440 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text11), 0, 1610 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text12), 0, 1612 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text13), 0, 1614 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text14), 0, 1720 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text15), 0, 1816 },
    { PORTRAIT_NAMINE, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text16), 0, 2060 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text17), 0, 2280 },
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text18), 0, 2310 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text19), 0, 2340 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text20), 0, 2342 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent044Text21), MSG_SCRIPT_FLAG_END, 2570 },
};

#ifdef VERSION_JP
#include "event_044_text.inc"
#endif

static const EvSoundCue sEvent044SoundCues[2] = {
    { SONG_BGM_TWILIGHTTOWN, 0, 0, 0 },
    { SONG_BGM_TWILIGHTTOWN, 2615, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent044Camera[7] = {
    { -65536, 65280, 32768, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -65386, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 80, NULL },
    { -64026, 65280, 104704, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 230, NULL },
    { -63656, 68608, 103168, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 70, NULL },
    { -63306, 89344, 97792, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 100, NULL },
    { -62316, 68608, 103168, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 100, NULL },
    { -60536, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EventBgEffectEntry sEvent044BgEffects[4] = {
    { 1860, 0, 0, 0, 0 },
    { 1790, 0, 0, 0, EVENT_BG_EFFECT_FLAG_FADE_OUT | EVENT_BG_EFFECT_FLAG_FULL_FADE },
    { 2230, 0, 0, 0, EVENT_BG_EFFECT_FLAG_CLEAR },
    { 2550, 0, 0, 0, EVENT_BG_EFFECT_FLAG_FADE_IN | EVENT_BG_EFFECT_FLAG_FULL_FADE | EVENT_BG_EFFECT_FLAG_END },
};

static const EventCharaKeyframe sEvent044Track0[40] = {
    { 4, 350, 32768, 130304, 0, 0, 82, NULL, NULL },
    { 9, 530, 73216, 109312, 0, 4, 83, NULL, NULL },
    { 4, 550, 0, 0, 0, 0, 85, NULL, NULL },
    { 0, 555, 0, 0, 0, 0, 21, NULL, NULL },
    { 4, 560, 0, 0, 0, 0, 21, NULL, NULL },
    { 3, 565, 0, 0, 0, 0, 21, NULL, NULL },
    { 2, 670, 0, 0, 0, 0, 21, NULL, NULL },
    { 3, 675, 0, 0, 0, 0, 21, NULL, NULL },
    { 4, 700, 0, 0, 0, 0, 21, NULL, NULL },
    { 3, 705, 0, 0, 0, 0, 21, NULL, NULL },
    { 2, 710, 0, 0, 0, 0, 21, NULL, NULL },
    { 1, 715, 0, 0, 0, 0, 21, NULL, NULL },
    { 2, 720, 0, 0, 0, 0, 85, NULL, NULL },
    { 3, 755, 0, 0, 0, 0, 85, NULL, NULL },
    { 2, 760, 0, 0, 0, 0, 85, NULL, NULL },
    { 1, 765, 0, 0, 0, 0, 21, NULL, NULL },
    { 2, 785, 0, 0, 0, 0, 21, NULL, NULL },
    { 32, 1130, 0, 0, 0, 0, 21, NULL, NULL },
    { 2, 1330, 0, 0, 0, 0, 21, NULL, NULL },
    { 89, 1380, 0, 0, 0, 0, 5, NULL, NULL },
    { 88, 1400, 0, 0, 0, 0, 21, NULL, NULL },
    { 15, 1420, 0, 0, 0, 0, 21, NULL, NULL },
    { 2, 1470, 0, 0, 0, 0, 21, NULL, NULL },
    { 1, 1475, 0, 0, 0, 0, 21, NULL, NULL },
    { 2, 1480, 0, 0, 0, 0, 85, NULL, NULL },
    { 3, 1485, 0, 0, 0, 0, 85, NULL, NULL },
    { 4, 1510, 0, 0, 0, 0, 85, NULL, NULL },
    { 9, 1560, 82688, 104960, 0, 4, 83, NULL, NULL },
    { 4, 1580, 0, 0, 0, 0, 85, NULL, NULL },
    { 36, 1630, 0, 0, 0, 0, 85, NULL, NULL },
    { 4, 1640, 0, 0, 0, 0, 85, NULL, NULL },
    { 3, 1645, 0, 0, 0, 0, 85, NULL, NULL },
    { 2, 1650, 0, 0, 0, 0, 85, NULL, NULL },
    { 1, 1655, 0, 0, 0, 0, 21, NULL, NULL },
    { 2, 1685, 0, 0, 0, 0, 21, NULL, NULL },
    { 95, 1780, 0, 0, 0, 0, 21, NULL, NULL },
    { 2, 1790, 0, 0, 0, 0, 21, NULL, NULL },
    { 86, 2390, 0, 0, 0, 0, 5, NULL, NULL },
    { 86, 2520, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 86, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent044Track1[23] = {
    { 114, 350, 29952, 137728, 0, 0, 82, NULL, NULL },
    { 119, 510, 0, 0, 0, 45, 84, NULL, NULL },
    { 114, 530, 0, 0, 0, 0, 85, NULL, NULL },
    { 110, 535, 0, 0, 0, 0, 21, NULL, NULL },
    { 114, 680, 0, 0, 0, 0, 21, NULL, NULL },
    { 110, 690, 0, 0, 0, 0, 21, NULL, NULL },
    { 114, 815, 0, 0, 0, 0, 85, NULL, NULL },
    { 126, 822, 0, 0, 0, 0, 85, NULL, NULL },
    { 114, 920, 0, 0, 0, 0, 85, NULL, NULL },
    { 127, 1020, 0, 0, 0, 0, 85, NULL, NULL },
    { 127, 1070, 0, 0, 0, 0, 80, NULL, CreateExclamationTask },
    { 129, 1085, 0, 0, 0, 0, 85, NULL, NULL },
    { 114, 1105, 0, 0, 0, 0, 85, NULL, NULL },
    { 126, 1112, 0, 0, 0, 0, 85, NULL, NULL },
    { 114, 1160, 0, 0, 0, 0, 85, NULL, NULL },
    { 114, 1290, 0, 0, 0, 0, 80, NULL, CreateBalloonTask },
    { 114, 1892, 0, 0, 0, 0, 85, NULL, NULL },
    { 114, 1912, 0, 0, 0, 0, 80, EventCharaFadeOut, NULL },
    { 114, 2230, 0, 0, 0, 0, 82, NULL, NULL },
    { 114, 2310, 66560, 119552, 0, 0, 82, EventCharaFadeIn, NULL },
    { 126, 2317, 0, 0, 0, 0, 85, NULL, NULL },
    { 114, 3220, 0, 0, 0, 0, 85, NULL, NULL },
    { 114, 5000, 0, 0, 0, 0, 32853, NULL, NULL },
};

static const EventCharaKeyframe sEvent044Track2[23] = {
    { 146, 300, 19200, 130048, 0, 0, 82, NULL, NULL },
    { 151, 458, 0, 0, 0, 45, 84, NULL, NULL },
    { 146, 470, 0, 0, 0, 0, 85, NULL, NULL },
    { 142, 480, 0, 0, 0, 0, 21, NULL, NULL },
    { 146, 510, 0, 0, 0, 0, 21, NULL, NULL },
    { 142, 520, 0, 0, 0, 0, 21, NULL, NULL },
    { 146, 530, 0, 0, 0, 0, 85, NULL, NULL },
    { 145, 540, 0, 0, 0, 0, 85, NULL, NULL },
    { 144, 580, 0, 0, 0, 0, 85, NULL, NULL },
    { 145, 620, 0, 0, 0, 0, 85, NULL, NULL },
    { 167, 627, 0, 0, 0, 0, 85, NULL, NULL },
    { 145, 815, 0, 0, 0, 0, 85, NULL, NULL },
    { 145, 1160, 0, 0, 0, 0, 85, NULL, NULL },
    { 145, 1290, 0, 0, 0, 0, 80, NULL, CreateBalloonTask },
    { 145, 1365, 0, 0, 0, 0, 85, NULL, NULL },
    { 167, 1372, 0, 0, 0, 0, 85, NULL, NULL },
    { 145, 1520, 0, 0, 0, 0, 85, NULL, NULL },
    { 146, 1892, 0, 0, 0, 0, 85, NULL, NULL },
    { 146, 1912, 0, 0, 0, 0, 80, EventCharaFadeOut, NULL },
    { 146, 2230, 0, 0, 0, 0, 82, NULL, NULL },
    { 146, 2720, 55040, 111616, 0, 0, 82, EventCharaFadeIn, NULL },
    { 146, 3220, 0, 0, 0, 0, 85, NULL, NULL },
    { 146, 5000, 0, 0, 0, 0, 32853, NULL, NULL },
};

static const EventCharaKeyframe sEvent044Track3[13] = {
    { 229, 550, 0, 0, 0, 0, 18, NULL, NULL },
    { 231, 551, 72704, 108544, 0, 0, 18, NULL, NULL },
    { 234, 580, 0, 0, 0, 211, 20, EventCharaHop, NULL },
    { 232, 590, 0, 0, 0, 211, 20, NULL, NULL },
    { 231, 610, 0, 0, 0, 0, 21, NULL, NULL },
    { 229, 840, 0, 0, 0, 0, 21, NULL, NULL },
    { 229, 970, 0, 0, 0, 0, 85, NULL, NULL },
    { 229, 1892, 0, 0, 0, 0, 85, NULL, NULL },
    { 229, 1912, 0, 0, 0, 0, 80, EventCharaFadeOut, NULL },
    { 229, 2230, 0, 0, 0, 0, 82, NULL, NULL },
    { 229, 2720, 63232, 105216, 0, 0, 82, EventCharaFadeIn, NULL },
    { 229, 3220, 0, 0, 0, 0, 85, NULL, NULL },
    { 229, 5000, 0, 0, 0, 0, 32853, NULL, NULL },
};

static const EventCharaKeyframe sEvent044Track4[4] = {
    { 422, 1990, 0, 0, 0, 0, 8194, NULL, NULL },
    { 424, 2120, 93696, 100352, 0, 0, 16658, EventCharaFadeIn, NULL },
    { 424, 2150, 0, 0, 0, 0, 272, EventCharaFadeOut, NULL },
    { 422, 2220, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaKeyframe sEvent044Track5[4] = {
    { 912, 1365, 0, 0, 0, 0, 8194, NULL, NULL },
    { 912, 1380, 73216, 109312, 0, 0, 16658, NULL, NULL },
    { 912, 1815, 0, 0, 0, 0, 2, NULL, NULL },
    { 910, 5000, 82688, 104960, 0, 0, 33042, NULL, NULL },
};

static const EventCharaTrack sEvent044Tracks[6] = {
    { sEvent044Track0, EVENT_CHARA_SORA },
    { sEvent044Track1, EVENT_CHARA_DONALD },
    { sEvent044Track2, EVENT_CHARA_GOOFY },
    { sEvent044Track3, EVENT_CHARA_JIMINY_CRICKET },
    { sEvent044Track4, EVENT_CHARA_NAMINE },
    { sEvent044Track5, EVENT_CHARA_OMAMORI },
};

const EventSequenceDef gEvent044 = {
    ARRAY_COUNT(sEvent044Tracks),
    sEvent044Tracks,
    sEvent044Camera,
    sEvent044Script,
    sEvent044SoundCues,
    sEvent044BgEffects,
    2620,
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
    WORLD_TWILIGHT_TOWN,
    POOH_LEVEL_NONE,
};
