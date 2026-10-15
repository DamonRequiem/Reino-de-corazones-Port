#ifdef VERSION_US
#include "event_132_text.inc"
#endif

static const MessageScriptEntry sEvent132Script[14] = {
    { PORTRAIT_MALEFICENT, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text00), 0, 180 },
    { PORTRAIT_MALEFICENT, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text01), 0, 350 },
    { PORTRAIT_MALEFICENT, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text02), 0, 352 },
    { PORTRAIT_MALEFICENT, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text03), 0, 420 },
    { PORTRAIT_BEAST, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text04), 0, 450 },
    { PORTRAIT_SORA, 5, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text05), 0, 480 },
    { PORTRAIT_BEAST, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text06), 0, 530 },
    { PORTRAIT_MALEFICENT, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text07), 0, 560 },
    { PORTRAIT_BEAST, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text08), 0, 580 },
    { PORTRAIT_MALEFICENT, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text09), 0, 620 },
    { PORTRAIT_MALEFICENT, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text10), 0, 622 },
    { PORTRAIT_MALEFICENT, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text11), 0, 670 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text12), 0, 720 },
    { PORTRAIT_MALEFICENT, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent132Text13), MSG_SCRIPT_FLAG_END, 750 },
};

#ifdef VERSION_JP
#include "event_132_text.inc"
#endif

static const EvSoundCue sEvent132SoundCues[5] = {
    { SONG_BGM_EVENT_UNREST, 0, 0, 0 },
    { SONG_EV_WOMAN2_DIRTR, 515, 0, 0 },
    { SONG_SND_351, 529, 0, 0 },
    { SONG_SND_375, 860, 0, 0 },
    { SONG_EV_FLASH02, 980, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent132Camera[5] = {
    { -65535, 32256, 71680, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65256, 56064, 65536, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 120, NULL },
    { -64686, 66816, 58624, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 50, NULL },
    { -64556, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -64526, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_WHITE | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 30, NULL },
};

static const EventBgEffectEntry sEvent132BgEffects[4] = {
    { 850, 0, 0, 0, 0 },
    { 860, 0, 0, 0, EVENT_BG_EFFECT_FLAG_FADE_OUT },
    { 870, 6, 66560, 38144, EVENT_BG_EFFECT_FLAG_LOAD },
    { 1009, 0, 0, 0, EVENT_BG_EFFECT_FLAG_CLEAR | EVENT_BG_EFFECT_FLAG_END },
};

static const EventCharaKeyframe sEvent132Track0[7] = {
    { 4, 1, 28672, 93184, 0, 0, 66, NULL, NULL },
    { 14, 80, 0, 0, 0, 45, 100, NULL, NULL },
    { 4, 83, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 475, 0, 0, 0, 0, 69, NULL, NULL },
    { 16, 532, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 680, 0, 0, 0, 0, 69, NULL, NULL },
    { 19, 2000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent132Track1[6] = {
    { 114, 1, 15104, 99328, 0, 0, 66, NULL, NULL },
    { 120, 110, 0, 0, 0, 45, 100, NULL, NULL },
    { 114, 113, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 690, 0, 0, 0, 0, 69, NULL, NULL },
    { 122, 705, 0, 0, 0, 0, 69, NULL, NULL },
    { 123, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent132Track2[6] = {
    { 146, 1, 3840, 97792, 0, 0, 66, NULL, NULL },
    { 153, 130, 0, 0, 0, 45, 100, NULL, NULL },
    { 146, 133, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 690, 0, 0, 0, 0, 69, NULL, NULL },
    { 157, 705, 0, 0, 0, 0, 69, NULL, NULL },
    { 158, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent132Track3[8] = {
    { 329, 1, 18432, 91648, 0, 0, 66, NULL, NULL },
    { 333, 100, 0, 0, 0, 45, 100, NULL, NULL },
    { 329, 500, 0, 0, 0, 0, 69, NULL, NULL },
    { 331, 520, 0, 0, 0, 45, 68, NULL, NULL },
    { 329, 525, 0, 0, 0, 0, 69, NULL, NULL },
    { 334, 565, 0, 0, 0, 0, 69, NULL, NULL },
    { 329, 680, 0, 0, 0, 0, 69, NULL, NULL },
    { 334, 9999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent132Track4[12] = {
    { 410, 230, 70400, 66048, 0, 0, 2, NULL, NULL },
    { 410, 240, 0, 0, 0, 0, 69, NULL, NULL },
    { 411, 280, 0, 0, 0, 0, 69, NULL, NULL },
    { 413, 320, 0, 0, 0, 45, 68, NULL, NULL },
    { 411, 380, 0, 0, 0, 0, 69, NULL, NULL },
    { 410, 390, 0, 0, 0, 0, 69, NULL, NULL },
    { 410, 615, 0, 0, 0, 0, 5, NULL, NULL },
    { 415, 621, 0, 0, 0, 0, 5, NULL, NULL },
    { 416, 630, 0, 0, 0, 0, 5, NULL, NULL },
    { 412, 650, 0, 0, 0, 173, 4, NULL, NULL },
    { 410, 770, 0, 0, 0, 0, 5, NULL, NULL },
    { 414, 9999, 0, 0, 0, 0, 33797, NULL, NULL },
};

static const EventCharaTrack sEvent132Tracks[5] = {
    { sEvent132Track0, EVENT_CHARA_SORA },
    { sEvent132Track1, EVENT_CHARA_DONALD },
    { sEvent132Track2, EVENT_CHARA_GOOFY },
    { sEvent132Track3, EVENT_CHARA_BEAST },
    { sEvent132Track4, EVENT_CHARA_MALEFICENT },
};

const EventSequenceDef gEvent132 = {
    ARRAY_COUNT(sEvent132Tracks),
    sEvent132Tracks,
    sEvent132Camera,
    sEvent132Script,
    sEvent132SoundCues,
    sEvent132BgEffects,
    1010,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_DRAGON_MALEFICENT,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
