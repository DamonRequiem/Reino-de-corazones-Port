#ifdef VERSION_US
#include "event_018_text.inc"
#endif

static const MessageScriptEntry sEvent018Script[16] = {
    { PORTRAIT_DONALD, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text00), 0, 210 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text01), 0, 230 },
    { PORTRAIT_GOOFY, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text02), 0, 380 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text03), 0, 382 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text04), 0, 410 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text05), 0, 500 },
    { PORTRAIT_DONALD, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text06), 0, 520 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text07), 0, 540 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text08), 0, 542 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text09), 0, 760 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text10), 0, 1170 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text11), 0, 1340 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text12), 0, 1500 },
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text13), 0, 1540 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text14), 0, 1640 },
    { PORTRAIT_GOOFY, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent018Text15), MSG_SCRIPT_FLAG_END, 1660 },
};

#ifdef VERSION_JP
#include "event_018_text.inc"
#endif

static const EventCameraKeyframe sEvent018Camera[3] = {
    { -64656, 182528, 66304, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64236, 200448, 56832, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 100, NULL },
    { -64036, 182528, 66304, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 60, NULL },
};

static const EvSoundCue sEvent018SoundCues[4] = {
    { SONG_BGM_T13THFLOOR, 0, 0, 0 },
    { SONG_BGM_T13THFLOOR, 415, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_SND_369, 820, 0, 0 },
    { SONG_SND_370, 1260, EV_SOUND_FLAG_END, 0 },
};

static const EventBgEffectEntry sEvent018BgEffects[3] = {
    { 820, 0, 0, 0, 0 },
    { 1300, 0, 0, 0, EVENT_BG_EFFECT_FLAG_FADE_OUT | EVENT_BG_EFFECT_FLAG_FULL_FADE },
    { 1900, 0, 0, 0, EVENT_BG_EFFECT_FLAG_FADE_IN | EVENT_BG_EFFECT_FLAG_FULL_FADE | EVENT_BG_EFFECT_FLAG_END },
};

static const EventCharaKeyframe sEvent018Track0[31] = {
    { 4, 0, 152832, 85504, 0, 0, 66, NULL, NULL },
    { 9, 170, 190208, 68352, 0, 4, 67, NULL, NULL },
    { 4, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 185, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 190, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 195, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 240, 0, 0, 0, 0, 5, NULL, NULL },
    { 32, 370, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 32, 390, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 415, 0, 0, 0, 0, 5, NULL, NULL },
    { 89, 550, 0, 0, 0, 0, 5, NULL, NULL },
    { 89, 680, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 88, 690, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 695, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 705, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 720, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1120, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1170, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 1350, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1480, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 4, 1550, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 1600, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 4, 1610, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 1615, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 1620, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 1625, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 1670, 0, 0, 0, 0, 5, NULL, NULL },
    { 15, 1680, 0, 0, 0, 0, 5, NULL, NULL },
    { 17, 1690, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 9999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent018Track1[20] = {
    { 114, 0, 150272, 91904, 0, 0, 66, NULL, NULL },
    { 119, 160, 179712, 77312, 0, 114, 67, NULL, NULL },
    { 114, 209, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 211, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 235, 0, 0, 0, 0, 69, NULL, NULL },
    { 127, 240, 0, 0, 0, 0, 69, NULL, NULL },
    { 128, 370, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 128, 420, 0, 0, 0, 0, 69, NULL, NULL },
    { 129, 430, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 519, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 521, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 820, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 840, 0, 0, 0, 0, 64, EventCharaFadeOut, NULL },
    { 114, 1300, 0, 0, 0, 0, 66, NULL, NULL },
    { 114, 1320, 179712, 77312, 0, 0, 66, EventCharaFadeIn, NULL },
    { 114, 1350, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 1480, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 114, 1539, 0, 0, 0, 0, 69, NULL, NULL },
    { 126, 1541, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent018Track2[21] = {
    { 146, 0, 141568, 91648, 0, 0, 66, NULL, NULL },
    { 151, 160, 173056, 71680, 0, 146, 67, NULL, NULL },
    { 146, 170, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 175, 0, 0, 0, 0, 69, NULL, NULL },
    { 144, 220, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 225, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 230, 0, 0, 0, 0, 69, NULL, NULL },
    { 170, 240, 0, 0, 0, 0, 69, NULL, NULL },
    { 170, 370, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 146, 375, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 379, 0, 0, 0, 0, 69, NULL, NULL },
    { 167, 383, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 820, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 840, 0, 0, 0, 0, 64, EventCharaFadeOut, NULL },
    { 145, 1300, 0, 0, 0, 0, 66, NULL, NULL },
    { 145, 1320, 173056, 71680, 0, 0, 66, EventCharaFadeIn, NULL },
    { 145, 1350, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 1480, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 145, 1659, 0, 0, 0, 0, 69, NULL, NULL },
    { 167, 1661, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent018Track3[5] = {
    { 420, 970, 0, 0, 0, 0, 8194, NULL, NULL },
    { 420, 1000, 205568, 58112, 0, 0, 16642, EventCharaFadeIn, NULL },
    { 420, 1220, 0, 0, 0, 0, 261, NULL, NULL },
    { 420, 1250, 0, 0, 0, 0, 256, EventCharaFadeOut, NULL },
    { 420, 9999, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaKeyframe sEvent018Track4[5] = {
    { 422, 1080, 0, 0, 0, 0, 8194, NULL, NULL },
    { 422, 1110, 205568, 58368, 0, 0, 540930, EventCharaFadeIn, NULL },
    { 422, 1260, 0, 0, 0, 0, 524549, NULL, NULL },
    { 422, 1290, 0, 0, 0, 0, 524544, EventCharaFadeOut, NULL },
    { 422, 1300, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaKeyframe sEvent018Track5[3] = {
    { 911, 450, 0, 0, 0, 0, 8194, NULL, NULL },
    { 911, 680, 190208, 68352, 0, 0, 16658, NULL, NULL },
    { 911, 1000, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaTrack sEvent018Tracks[6] = {
    { sEvent018Track0, EVENT_CHARA_SORA },
    { sEvent018Track1, EVENT_CHARA_DONALD },
    { sEvent018Track2, EVENT_CHARA_GOOFY },
    { sEvent018Track3, EVENT_CHARA_KAIRI },
    { sEvent018Track4, EVENT_CHARA_NAMINE },
    { sEvent018Track5, EVENT_CHARA_OMAMORI },
};

const EventSequenceDef gEvent018 = {
    ARRAY_COUNT(sEvent018Tracks),
    sEvent018Tracks,
    sEvent018Camera,
    sEvent018Script,
    sEvent018SoundCues,
    sEvent018BgEffects,
    1740,
    TRUE,
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
    POOH_LEVEL_NONE,
};
