#ifdef VERSION_US
#include "event_115_text.inc"
#endif

static const MessageScriptEntry sEvent115Script[8] = {
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent115Text00), 0, 150 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent115Text01), 0, 170 },
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent115Text02), 0, 190 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent115Text03), 0, 220 },
    { PORTRAIT_DONALD, 5, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent115Text04), 0, 300 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent115Text05), 0, 320 },
    { PORTRAIT_JIMINY_CRICKET, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent115Text06), 0, 560 },
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent115Text07), MSG_SCRIPT_FLAG_END, 630 },
};

#ifdef VERSION_JP
#include "event_115_text.inc"
#endif

static const EventCameraKeyframe sEvent115Camera[2] = {
    { -65536, 32768, 32768, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_KEYFRAME_FLAG_SWAY, 0, NULL },
    { -55537, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_KEYFRAME_FLAG_SWAY | CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 80, NULL },
};

static const EvSoundCue sEvent115SoundCues[4] = {
    { SONG_BGM_PETERPAN_FIELD, 0, 0, 0 },
    { SONG_SND_387, 251, 0, 0 },
    { SONG_SND_387, 780, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_PETERPAN_FIELD, 1015, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent115Track0[8] = {
    { 1, 80, 24064, 40960, 0, 0, 2, NULL, NULL },
    { 2, 100, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 130, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 135, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 290, 0, 0, 0, 0, 69, NULL, NULL },
    { 27, 302, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 780, 0, 0, 0, 0, 69, NULL, NULL },
    { 9, 9999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent115Track2[11] = {
    { 114, 80, 36608, 42496, 0, 0, 66, NULL, NULL },
    { 114, 105, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 130, 0, 0, 0, 0, 69, NULL, NULL },
    { 114, 189, 0, 0, 0, 0, 5, NULL, NULL },
    { 126, 191, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 280, 0, 0, 0, 0, 5, NULL, NULL },
    { 133, 330, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 114, 720, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 740, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 780, 0, 0, 0, 0, 69, NULL, NULL },
    { 119, 9999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent115Track1[15] = {
    { 144, 80, 32256, 33024, 0, 0, 66, NULL, NULL },
    { 144, 100, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 130, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 169, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 171, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 310, 0, 0, 0, 0, 5, NULL, NULL },
    { 163, 330, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 629, 0, 0, 0, 0, 5, NULL, NULL },
    { 164, 631, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 700, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 720, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 740, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 750, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 780, 0, 0, 0, 0, 69, NULL, NULL },
    { 151, 9999, 0, 0, 0, 45, 32836, NULL, NULL },
};

static const EventCharaKeyframe sEvent115Track3[16] = {
    { 455, 250, 0, 0, 0, 0, 2, NULL, NULL },
    { 455, 251, 69888, 14336, -10240, 0, 2, NULL, NULL },
    { 456, 290, 28928, 39168, -5632, 455, 131, NULL, NULL },
    { 456, 330, 0, 0, 0, 0, 133, NULL, NULL },
    { 456, 340, 24832, 32512, -5632, 455, 131, NULL, NULL },
    { 456, 570, 0, 0, 0, 0, 128, EventCharaCircleSlow, NULL },
    { 456, 580, 0, 0, 0, 0, 133, NULL, NULL },
    { 456, 590, 28928, 39168, -5632, 455, 131, NULL, NULL },
    { 456, 600, 0, 0, 0, 0, 133, NULL, NULL },
    { 456, 630, 0, 0, 0, 0, 0, EventCharaJitter, NULL },
    { 456, 650, 0, 0, 0, 0, 133, NULL, NULL },
    { 456, 670, 0, 0, 0, 1, 132, NULL, NULL },
    { 456, 710, 0, 0, 0, 0, 197, NULL, NULL },
    { 458, 720, 0, 0, 0, 0, 197, NULL, NULL },
    { 458, 800, 69888, 14336, -10240, 459, 195, NULL, NULL },
    { 458, 9999, 0, 0, 0, 0, 32965, NULL, NULL },
};

static const EventCharaKeyframe sEvent115Track4[9] = {
    { 229, 500, 0, 0, 0, 0, 8194, NULL, NULL },
    { 231, 501, 24064, 40960, 0, 0, 16450, NULL, NULL },
    { 234, 530, 0, 0, 0, 45, 68, EventCharaHop, NULL },
    { 231, 540, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 550, 0, 0, 0, 0, 69, NULL, NULL },
    { 229, 680, 0, 0, 0, 0, 5, NULL, NULL },
    { 233, 700, 0, 0, 0, 173, 4, EventCharaHop, NULL },
    { 229, 701, 0, 0, 0, 0, 2, NULL, NULL },
    { 229, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent115Tracks[5] = {
    { sEvent115Track0, EVENT_CHARA_SORA },
    { sEvent115Track1, EVENT_CHARA_GOOFY },
    { sEvent115Track2, EVENT_CHARA_DONALD },
    { sEvent115Track3, EVENT_CHARA_TINKER_BELL },
    { sEvent115Track4, EVENT_CHARA_JIMINY_CRICKET },
};

const EventSequenceDef gEvent115 = {
    ARRAY_COUNT(sEvent115Tracks),
    sEvent115Tracks,
    sEvent115Camera,
    sEvent115Script,
    sEvent115SoundCues,
    NULL,
    1020,
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
