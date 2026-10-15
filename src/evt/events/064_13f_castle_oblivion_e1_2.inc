#ifdef VERSION_US
#include "event_064_text.inc"
#endif

static const MessageScriptEntry sEvent064Script[16] = {
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text00), 0, 150 },
    { PORTRAIT_AXEL, 3, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text01), 0, 152 },
    { PORTRAIT_MARLUXIA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text02), 0, 180 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text03), 0, 230 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text04), 0, 232 },
    { PORTRAIT_AXEL, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text05), 0, 280 },
    { PORTRAIT_MARLUXIA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text06), 0, 300 },
    { PORTRAIT_MARLUXIA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text07), 0, 400 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text08), 0, 550 },
    { PORTRAIT_MARLUXIA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text09), 0, 580 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text10), 0, 650 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text11), 0, 670 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text12), 0, 690 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text13), 0, 770 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text14), 0, 772 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent064Text15), MSG_SCRIPT_FLAG_END, 830 },
};

#ifdef VERSION_JP
#include "event_064_text.inc"
#endif

static const EventCameraKeyframe sEvent064Camera[3] = {
    { -65046, 182016, 66304, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64881, 170752, 66560, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 30, NULL },
    { -64537, 164352, 66560, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 50, NULL },
};

static const EvSoundCue sEvent064SoundCues[6] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_EV_EV34_03, 270, 0, 0 },
    { SONG_BGM_EVENT_XIII, 450, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_EV_WARPIN, 635, 0, 0 },
    { SONG_BGM_EVENT2, 780, 0, 0 },
    { SONG_EV_EV34_03, 790, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent064Track0[6] = {
    { 510, 240, 175872, 67584, 0, 0, 66, NULL, NULL },
    { 503, 270, 0, 0, 0, 0, 69, NULL, NULL },
    { 493, 410, 0, 0, 0, 0, 69, NULL, NULL },
    { 510, 460, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 510, 790, 0, 0, 0, 0, 5, NULL, NULL },
    { 511, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent064Track1[4] = {
    { 842, 615, 190720, 80128, 0, 0, 2, NULL, NULL },
    { 844, 635, 185600, 76544, 0, 842, 3, NULL, NULL },
    { 842, 655, 0, 0, 0, 0, 0, EventCharaFadeOut, NULL },
    { 842, 1000, 0, 0, 0, 0, 32770, NULL, NULL },
};

static const EventCharaKeyframe sEvent064Track2[7] = {
    { 428, 190, 0, 0, 0, 0, 8194, NULL, NULL },
    { 428, 210, 184320, 75008, 0, 0, 16386, EventCharaFadeIn, NULL },
    { 428, 240, 0, 0, 0, 0, 5, NULL, NULL },
    { 428, 290, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 428, 635, 0, 0, 0, 0, 5, NULL, NULL },
    { 428, 655, 0, 0, 0, 0, 0, EventCharaFadeOut, NULL },
    { 428, 9999, 0, 0, 0, 0, 32770, NULL, NULL },
};

static const EventCharaKeyframe sEvent064Track3[6] = {
    { 4, 450, 139520, 86272, 0, 0, 66, NULL, NULL },
    { 14, 520, 164096, 74240, 0, 4, 67, NULL, NULL },
    { 4, 522, 0, 0, 0, 45, 68, NULL, NULL },
    { 4, 590, 0, 0, 0, 0, 69, NULL, NULL },
    { 19, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 21, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent064Track4[6] = {
    { 114, 450, 132352, 89088, 0, 0, 66, NULL, NULL },
    { 120, 530, 154112, 76288, 0, 114, 67, NULL, NULL },
    { 114, 532, 0, 0, 0, 45, 68, NULL, NULL },
    { 114, 595, 0, 0, 0, 0, 69, NULL, NULL },
    { 122, 605, 0, 0, 0, 0, 69, NULL, NULL },
    { 123, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent064Track5[6] = {
    { 146, 450, 142848, 94720, 0, 0, 66, NULL, NULL },
    { 153, 530, 160512, 82944, 0, 146, 67, NULL, NULL },
    { 146, 532, 0, 0, 0, 45, 68, NULL, NULL },
    { 146, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 157, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 158, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent064Tracks[6] = {
    { sEvent064Track0, EVENT_CHARA_AXEL },
    { sEvent064Track1, EVENT_CHARA_MARLUXIA },
    { sEvent064Track2, EVENT_CHARA_NAMINE },
    { sEvent064Track3, EVENT_CHARA_SORA },
    { sEvent064Track4, EVENT_CHARA_DONALD },
    { sEvent064Track5, EVENT_CHARA_GOOFY },
};

const EventSequenceDef gEvent064 = {
    ARRAY_COUNT(sEvent064Tracks),
    sEvent064Tracks,
    sEvent064Camera,
    sEvent064Script,
    sEvent064SoundCues,
    NULL,
    880,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_AXEL_2,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
