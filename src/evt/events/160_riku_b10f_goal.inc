#ifdef VERSION_US
#include "event_160_text.inc"
#endif

static const MessageScriptEntry sEvent160Script[13] = {
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text00), 0, 250 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text01), 0, 280 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text02), 0, 460 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text03), 0, 462 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text04), 0, 490 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text05), 0, 520 },
    { PORTRAIT_VEXEN, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text06), 0, 660 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text07), 0, 662 },
    { PORTRAIT_RIKU, 5, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text08), 0, 710 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text09), 0, 790 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text10), 0, 792 },
    { PORTRAIT_RIKU, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text11), 0, 794 },
    { PORTRAIT_VEXEN, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent160Text12), MSG_SCRIPT_FLAG_END, 822 },
};

#ifdef VERSION_JP
#include "event_160_text.inc"
#endif

static const EvSoundCue sEvent160SoundCues[7] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_EV_WARPOUT, 130, 0, 0 },
    { SONG_BGM_EVENT_XIII, 160, EV_SOUND_FLAG_FADE_IN, 0 },
    { SONG_SND_359, 260, 0, 0 },
    { SONG_SND_359, 750, 0, 0 },
    { SONG_BGM_EVENT_XIII, 705, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_EVENT2, 755, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent160Camera[1] = {
    { -64537, 188160, 61184, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent160Track0[13] = {
    { 515, 1, 151552, 86784, 0, 0, 66, NULL, NULL },
    { 518, 130, 0, 0, 0, 45, 68, NULL, NULL },
    { 515, 140, 0, 0, 0, 0, 69, NULL, NULL },
    { 532, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 532, 210, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 532, 220, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 260, 0, 0, 0, 0, 69, NULL, NULL },
    { 560, 570, 0, 0, 0, 0, 69, NULL, NULL },
    { 534, 590, 0, 0, 0, 0, 69, NULL, NULL },
    { 534, 640, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 534, 650, 0, 0, 0, 0, 69, NULL, NULL },
    { 563, 750, 0, 0, 0, 0, 69, NULL, NULL },
    { 560, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent160Track1[4] = {
    { 721, 130, 0, 0, 0, 0, 2, NULL, NULL },
    { 721, 300, 198144, 64000, 0, 0, 2, EventCharaFadeIn, NULL },
    { 721, 430, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 721, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent160Tracks[2] = {
    { sEvent160Track0, EVENT_CHARA_RIKU },
    { sEvent160Track1, EVENT_CHARA_VEXEN },
};

const EventSequenceDef gEvent160 = {
    ARRAY_COUNT(sEvent160Tracks),
    sEvent160Tracks,
    sEvent160Camera,
    sEvent160Script,
    sEvent160SoundCues,
    NULL,
    880,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_VEXEN_3,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
