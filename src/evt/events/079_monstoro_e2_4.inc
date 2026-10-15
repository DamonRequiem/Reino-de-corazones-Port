#ifdef VERSION_US
static const MessageScriptEntry sEvent079Script[6] = {
    { PORTRAIT_PINOCCHIO, 8, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent078Text00, 0, 250 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, 1, gEvent078Text01, 0, 320 },
    { PORTRAIT_PINOCCHIO, 11, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, gEvent078Text02, 0, 340 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, 1, gEvent078Text03, 0, 420 },
    { PORTRAIT_PINOCCHIO, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, gEvent078Text04, 0, 630 },
    { PORTRAIT_PINOCCHIO, 14, MSG_WIN_POSITION_KEEP, 1, gEvent078Text05, MSG_SCRIPT_FLAG_END, 635 },
};
#endif

#ifdef VERSION_JP
static const MessageScriptEntry sEvent079Script[6] = {
    { PORTRAIT_PINOCCHIO, 8, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent078Text00, 0, 250 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, 3, gEvent078Text01, 0, 320 },
    { PORTRAIT_PINOCCHIO, 11, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 3, gEvent078Text02, 0, 340 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, 3, gEvent079Text03, 0, 420 },
    { PORTRAIT_PINOCCHIO, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 3, gEvent078Text04, 0, 630 },
    { PORTRAIT_PINOCCHIO, 14, MSG_WIN_POSITION_KEEP, 3, gEvent078Text05, MSG_SCRIPT_FLAG_END, 635 },
};

#include "event_079_text.inc"
#endif
#ifdef VERSION_EU
static const MessageScriptEntry sEvent079Script[6] = {
    { PORTRAIT_PINOCCHIO, 8, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, &gEvent078Text00ByLanguage, 0, 250 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, 1, &gEvent078Text01ByLanguage, 0, 320 },
    { PORTRAIT_PINOCCHIO, 11, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, &gEvent078Text02ByLanguage, 0, 340 },
    { PORTRAIT_SORA, 2, MSG_WIN_POSITION_TOP_FACE_LEFT, 1, &gEvent078Text03ByLanguage, 0, 420 },
    { PORTRAIT_PINOCCHIO, 2, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, 1, &gEvent078Text04ByLanguage, 0, 630 },
    { PORTRAIT_PINOCCHIO, 14, MSG_WIN_POSITION_KEEP, 1, &gEvent078Text05ByLanguage, MSG_SCRIPT_FLAG_END, 635 },
};
#endif

static const EventCameraKeyframe sEvent079Camera[2] = {
    { -65535, 34304, 30720, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -63536, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent079SoundCues[1] = {
    { SONG_NONE, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent079Track0[21] = {
    { 241, 50, 37376, 36864, 0, 0, 322, NULL, NULL },
    { 241, 80, 0, 0, 0, 0, 261, NULL, NULL },
    { 238, 110, 0, 0, 0, 0, 261, NULL, NULL },
    { 244, 140, 31232, 38144, 0, 236, 259, NULL, NULL },
    { 238, 190, 0, 0, 0, 0, 261, NULL, NULL },
    { 238, 200, 0, 0, 0, 0, 325, NULL, NULL },
    { 241, 210, 0, 0, 0, 0, 325, NULL, NULL },
    { 250, 220, 34304, 37632, 0, 239, 323, NULL, NULL },
    { 241, 335, 0, 0, 0, 0, 325, NULL, NULL },
    { 259, 342, 0, 0, 0, 0, 325, NULL, NULL },
    { 241, 352, 0, 0, 0, 0, 325, NULL, NULL },
    { 238, 362, 0, 0, 0, 0, 325, NULL, NULL },
    { 238, 470, 0, 0, 0, 0, 261, NULL, NULL },
    { 238, 600, 0, 0, 0, 0, 256, NULL, CreateBalloonTask },
    { 238, 680, 0, 0, 0, 0, 261, NULL, NULL },
    { 247, 710, 0, 0, 0, 173, 260, NULL, NULL },
    { 253, 770, 0, 0, 0, 45, 324, NULL, NULL },
    { 247, 820, 0, 0, 0, 83, 324, NULL, NULL },
    { 253, 890, 0, 0, 0, 211, 260, NULL, NULL },
    { 247, 920, 0, 0, 0, 83, 324, NULL, NULL },
    { 247, 2000, 0, 0, 0, 173, 33028, NULL, NULL },
};

static const EventCharaTrack sEvent079Tracks[1] = {
    { sEvent079Track0, EVENT_CHARA_PINOCCHIO },
};

const EventSequenceDef gEvent079 = {
    ARRAY_COUNT(sEvent079Tracks),
    sEvent079Tracks,
    sEvent079Camera,
    sEvent079Script,
    sEvent079SoundCues,
    NULL,
    920,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_080_MONSTORO_E2_5,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
