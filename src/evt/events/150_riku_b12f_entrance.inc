#ifdef VERSION_US
#include "event_150_text.inc"
#endif

static const MessageScriptEntry sEvent150Script[1] = {
    { PORTRAIT_RIKU, 0, MSG_WIN_POSITION_TOP_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent150Text00), MSG_SCRIPT_FLAG_END, 350 },
};

#ifdef VERSION_JP
#include "event_150_text.inc"
#endif

static const EvSoundCue sEvent150SoundCues[2] = {
    { SONG_NONE, 0, 0, 0 },
    { SONG_BGM_TOWN_FIELD, 5000, EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent150Camera[4] = {
    { -65536, 196352, 58112, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE, 0, NULL },
    { -65416, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_FADE_IN_WHITE | CAMERA_MODE_KEEP, 110, NULL },
    { -65306, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -64537, 205056, 51200, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 80, NULL },
};

static const EventCharaKeyframe sEvent150Track0[8] = {
    { 515, 100, 196864, 64768, 0, 0, 66, NULL, NULL },
    { 515, 110, 0, 0, 0, 0, 5, NULL, NULL },
    { 514, 140, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 150, 0, 0, 0, 0, 5, NULL, NULL },
    { 515, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 514, 200, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 210, 0, 0, 0, 0, 69, NULL, NULL },
    { 515, 5000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent150Tracks[1] = {
    { sEvent150Track0, EVENT_CHARA_RIKU },
};

const EventSequenceDef gEvent150 = {
    ARRAY_COUNT(sEvent150Tracks),
    sEvent150Tracks,
    sEvent150Camera,
    sEvent150Script,
    sEvent150SoundCues,
    NULL,
    400,
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
