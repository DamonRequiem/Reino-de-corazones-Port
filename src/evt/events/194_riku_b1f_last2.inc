#ifdef VERSION_US
#include "event_194_text.inc"
#endif

static const MessageScriptEntry sEvent194Script[7] = {
    { PORTRAIT_ANSEM, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent194Text00), 0, 100 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent194Text01), 0, 250 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent194Text02), 0, 350 },
    { PORTRAIT_ANSEM, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent194Text03), 0, 380 },
    { PORTRAIT_ANSEM, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent194Text04), 0, 445 },
    { PORTRAIT_MICKEY, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent194Text05), 0, 1180 },
    { PORTRAIT_MICKEY, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent194Text06), MSG_SCRIPT_FLAG_END, 1400 },
};

#ifdef VERSION_JP
#include "event_194_text.inc"
#endif

static const EvSoundCue sEvent194SoundCues[12] = {
    { SONG_BGM_EVENT2, 0, 0, 0 },
    { SONG_SND_380, 105, 0, 0 },
    { SONG_EV_RUMBLE, 120, 0, 0 },
    { SONG_EV_RUMBLE, 190, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_SND_376, 260, 0, 0 },
    { SONG_EV_FLASH00, 270, 0, 0 },
    { SONG_SND_380, 440, 0, 0 },
    { SONG_EV_RUMBLE, 441, 0, 0 },
    { SONG_SND_379, 450, 0, 0 },
    { SONG_EV_RUMBLE, 620, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_EVENT2, 660, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_EV_WHITEOUT, 1530, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent194Camera[12] = {
    { -65416, 175616, 66560, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65336, 170752, 71168, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_SMALL | CAMERA_MODE_APPROACH, 80, NULL },
    { -65266, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -65246, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FLASH | CAMERA_KEYFRAME_FLAG_NO_FLASH_SOUND | CAMERA_MODE_KEEP, 20, NULL },
    { -65136, 188928, 62208, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 50, NULL },
    { -65106, 183552, 65536, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 30, NULL },
    { -64676, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_SMALL | CAMERA_MODE_KEEP, 0, NULL },
    { -64131, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -64088, 69376, 29440, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64006, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -63536, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_OUT_WHITE | CAMERA_MODE_KEEP, 100, NULL },
    { -60536, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EventBgEffectEntry sEvent194BgEffects[5] = {
    { 450, 0, 0, 0, 0 },
    { 530, 0, 80, 0, EVENT_BG_EFFECT_FLAG_FADE_OUT | EVENT_BG_EFFECT_FLAG_FULL_FADE },
    { 3310, 0, 0, 0, 0 },
    { 4000, 0, 0, 0, EVENT_BG_EFFECT_FLAG_CLEAR },
    { 5000, 0, 0, 0, EVENT_BG_EFFECT_FLAG_FADE_IN | EVENT_BG_EFFECT_FLAG_END },
};

static const EventCharaKeyframe sEvent194Track0[15] = {
    { 561, 120, 158208, 83712, 0, 0, 66, NULL, NULL },
    { 542, 170, 149504, 88064, 0, 515, 67, NULL, NULL },
    { 560, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 548, 290, 194816, 65792, 0, 515, 67, NULL, NULL },
    { 553, 345, 0, 0, 0, 0, 69, NULL, NULL },
    { 563, 450, 0, 0, 0, 0, 69, NULL, NULL },
    { 514, 460, 0, 0, 0, 0, 69, NULL, NULL },
    { 514, 470, 0, 0, 0, 0, 5, NULL, NULL },
    { 526, 620, 0, 0, 0, 0, 5, NULL, NULL },
    { 526, 650, 0, 0, 0, 0, 0, EventCharaFadeOut, NULL },
    { 515, 1450, 0, 0, 0, 0, 66, NULL, NULL },
    { 514, 1520, 53248, 34816, 0, 0, 322, EventCharaFadeIn, NULL },
    { 515, 1580, 0, 0, 0, 0, 325, NULL, NULL },
    { 518, 1690, 68096, 31232, 0, 515, 67, NULL, NULL },
    { 514, 5000, 0, 0, 0, 0, 33093, NULL, NULL },
};

static const EventCharaKeyframe sEvent194Track1[7] = {
    { 688, 10, 182528, 73216, 0, 0, 2, NULL, NULL },
    { 693, 272, 0, 0, 0, 0, 5, NULL, NULL },
    { 688, 278, 0, 0, 0, 0, 5, NULL, NULL },
    { 693, 425, 0, 0, 0, 0, 5, NULL, NULL },
    { 694, 450, 0, 0, 0, 0, 5, NULL, NULL },
    { 694, 480, 0, 0, 0, 0, 0, EventCharaFadeOut, NULL },
    { 693, 1000, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaKeyframe sEvent194Track2[6] = {
    { 920, 950, 0, 0, 0, 0, 8450, NULL, NULL },
    { 920, 951, 225792, 47104, 0, 0, 16770, NULL, NULL },
    { 920, 1150, 183040, 63744, 0, 920, 259, NULL, NULL },
    { 920, 1280, 0, 0, 0, 0, 389, NULL, NULL },
    { 920, 1310, 0, 0, 0, 0, 256, EventCharaFadeOut, NULL },
    { 920, 2000, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaKeyframe sEvent194Track3[5] = {
    { 746, 1450, 0, 0, 0, 0, 2, NULL, NULL },
    { 745, 1520, 85248, 35584, 0, 0, 258, EventCharaFadeIn, NULL },
    { 746, 1580, 0, 0, 0, 0, 261, NULL, NULL },
    { 754, 1690, 72704, 30208, 0, 746, 3, NULL, NULL },
    { 746, 5000, 0, 0, 0, 0, 33029, NULL, NULL },
};

static const EventCharaKeyframe sEvent194Track4[5] = {
    { 926, 105, 0, 0, 0, 0, 8194, NULL, NULL },
    { 926, 300, 182016, 66560, 0, 0, 16658, NULL, NULL },
    { 103, 440, 0, 0, 0, 0, 66, NULL, NULL },
    { 926, 480, 183552, 65536, 0, 0, 274, NULL, NULL },
    { 926, 5000, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaTrack sEvent194Tracks[5] = {
    { sEvent194Track0, EVENT_CHARA_RIKU },
    { sEvent194Track1, EVENT_CHARA_ANSEM },
    { sEvent194Track2, EVENT_CHARA_KOUKYU },
    { sEvent194Track3, EVENT_CHARA_MICKEY },
    { sEvent194Track4, EVENT_CHARA_SHOUGEKIHA_PURPLE },
};

const EventSequenceDef gEvent194 = {
    ARRAY_COUNT(sEvent194Tracks),
    sEvent194Tracks,
    sEvent194Camera,
    sEvent194Script,
    sEvent194SoundCues,
    sEvent194BgEffects,
    1680,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_195_RIKU_ENDING,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
