#ifdef VERSION_US
#include "event_002_text.inc"
static const MessageScriptEntry sEvent002Script[8] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent002Text00, 0, 250 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent002Text01, 0, 370 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_KEEP, 1, gEvent002Text02, 0, 372 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, gEvent002Text03, 0, 400 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent002Text04, 0, 430 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent002Text05, 0, 980 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent002Text06, 0, 1045 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, gEvent002Text07, MSG_SCRIPT_FLAG_END, 1080 },
};
#endif

#ifdef VERSION_JP
static const MessageScriptEntry sEvent002Script[7] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent002Text00, 0, 250 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent002Text01, 0, 370 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 3, gEvent002Text02, 0, 400 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent002Text03, 0, 430 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent002Text04, 0, 980 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent002Text05, 0, 1045 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 3, gEvent002Text06, MSG_SCRIPT_FLAG_END, 1080 },
};

#include "event_002_text.inc"
#endif
#ifdef VERSION_EU
static const MessageScriptEntry sEvent002Script[8] = {
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, &gEvent002Text00ByLanguage, 0, 250 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, &gEvent002Text01ByLanguage, 0, 370 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_KEEP, 1, &gEvent002Text02ByLanguage, 0, 372 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, &gEvent002Text03ByLanguage, 0, 400 },
    { PORTRAIT_JIMINY_CRICKET, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, &gEvent002Text04ByLanguage, 0, 430 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, &gEvent002Text05ByLanguage, 0, 980 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, &gEvent002Text06ByLanguage, 0, 1045 },
    { PORTRAIT_ROBED_FIGURE, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, &gEvent002Text07ByLanguage, MSG_SCRIPT_FLAG_END, 1080 },
};
#endif

static const EventCameraKeyframe sEvent002Camera[9] = {
    { -65536, 40448, 67840, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -65455, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 80, NULL },
    { -64926, 66048, 56576, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 85, NULL },
    { -64866, 82176, 68096, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 40, NULL },
    { -64736, 54016, 82944, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 70, NULL },
    { -64616, 30720, 70144, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 65, NULL },
    { -64536, 37632, 75520, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 65, NULL },
    { -64036, 49408, 66304, 0, EVENT_CHARA_NONE, CAMERA_MODE_APPROACH, 50, NULL },
    { -55537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent002SoundCues[2] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_BGM_EVENT_UNREST, 285, EV_SOUND_FLAG_FADE_IN | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent002Track0[43] = {
    { 4, 1, 17408, 90112, 0, 0, 66, NULL, NULL },
    { 14, 150, 66560, 60416, 0, 4, 99, NULL, NULL },
    { 4, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 230, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 27, 252, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 320, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 325, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 330, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 335, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 432, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 437, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 462, 0, 0, 0, 0, 5, NULL, NULL },
    { 27, 512, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 4, 520, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 525, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 550, 0, 0, 0, 0, 69, NULL, NULL },
    { 0, 555, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 580, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 585, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 590, 0, 0, 0, 0, 5, NULL, NULL },
    { 1, 595, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 610, 0, 0, 0, 0, 69, NULL, NULL },
    { 12, 650, 0, 0, 0, 83, 100, NULL, NULL },
    { 2, 670, 0, 0, 0, 0, 69, NULL, NULL },
    { 12, 740, 0, 0, 0, 173, 36, NULL, NULL },
    { 2, 760, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 770, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 780, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 785, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 800, 0, 0, 0, 0, 5, NULL, NULL },
    { 14, 865, 0, 0, 0, 211, 36, NULL, NULL },
    { 4, 885, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 895, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 915, 0, 0, 0, 0, 69, NULL, NULL },
    { 12, 950, 38144, 75520, 0, 2, 99, NULL, NULL },
    { 2, 970, 0, 0, 0, 0, 69, NULL, NULL },
    { 31, 985, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 1000, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 1005, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 1025, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 1040, 0, 0, 0, 45, 68, NULL, NULL },
    { 30, 1130, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent002Track1[19] = {
    { 231, 200, 0, 0, 0, 0, 2, NULL, NULL },
    { 231, 201, 66816, 58880, 0, 0, 2, NULL, NULL },
    { 234, 230, 0, 0, 0, 211, 4, EventCharaHop, NULL },
    { 231, 251, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 260, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 415, 0, 0, 0, 0, 69, NULL, NULL },
    { 233, 435, 0, 0, 0, 0, 64, EventCharaHop, NULL },
    { 229, 460, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 480, 0, 0, 0, 0, 5, NULL, NULL },
    { 230, 600, 0, 0, 0, 173, 4, NULL, NULL },
    { 229, 770, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 785, 0, 0, 0, 0, 69, NULL, NULL },
    { 231, 795, 0, 0, 0, 0, 5, NULL, NULL },
    { 229, 1028, 0, 0, 0, 0, 69, NULL, NULL },
    { 231, 1120, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 1130, 0, 0, 0, 0, 69, NULL, NULL },
    { 230, 1150, 0, 0, 0, 83, 68, NULL, NULL },
    { 233, 1165, 0, 0, 0, 83, 68, EventCharaHop, NULL },
    { 229, 9999, 0, 0, 0, 0, 32834, NULL, NULL },
};

static const EventCharaKeyframe sEvent002Track2[8] = {
    { 180, 260, 0, 0, 0, 0, 8258, NULL, NULL },
    { 180, 290, 41472, 74240, 0, 0, 16450, EventCharaFadeIn, NULL },
    { 186, 360, 0, 0, 0, 45, 68, NULL, NULL },
    { 180, 640, 0, 0, 0, 0, 69, NULL, NULL },
    { 178, 700, 0, 0, 0, 0, 69, NULL, NULL },
    { 178, 1090, 0, 0, 0, 0, 5, NULL, NULL },
    { 187, 2000, 0, 0, 0, 0, 5, NULL, NULL },
    { 178, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent002Tracks[3] = {
    { sEvent002Track0, EVENT_CHARA_SORA },
    { sEvent002Track1, EVENT_CHARA_JIMINY_CRICKET },
    { sEvent002Track2, EVENT_CHARA_ROBED_FIGURE },
};

const EventSequenceDef gEvent002 = {
    ARRAY_COUNT(sEvent002Tracks),
    sEvent002Tracks,
    sEvent002Camera,
    sEvent002Script,
    sEvent002SoundCues,
    NULL,
    1200,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_BATTLE_TUTORIAL_0,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
