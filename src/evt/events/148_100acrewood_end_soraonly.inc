#ifdef VERSION_US
#include "event_148_text.inc"
#endif

static const MessageScriptEntry sEvent148Script[1] = {
    { PORTRAIT_SORA, 7, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent148Text00), MSG_SCRIPT_FLAG_END, 150 },
};

#ifdef VERSION_JP
#include "event_148_text.inc"
#endif

static const EvSoundCue sEvent148SoundCues[1] = {
    { SONG_NONE, 0, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent148Camera[1] = {
    { -64537, 790528, 416512, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent148Track0[6] = {
    { 2, 80, 790528, 419840, 0, 0, 66, NULL, NULL },
    { 1, 90, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 100, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 110, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 120, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 1000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent148Tracks[1] = {
    { sEvent148Track0, EVENT_CHARA_SORA },
};

const EventSequenceDef gEvent148 = {
    ARRAY_COUNT(sEvent148Tracks),
    sEvent148Tracks,
    sEvent148Camera,
    sEvent148Script,
    sEvent148SoundCues,
    NULL,
    210,
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
    7,
};
