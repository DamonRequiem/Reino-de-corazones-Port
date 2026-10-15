#ifdef VERSION_US
static const MessageScriptEntry sEvent196Script[1] = {
    { PORTRAIT_RIKU, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, gEvent196Text00, MSG_SCRIPT_FLAG_END, 100 },
};

#include "event_196_text.inc"
#endif
#ifdef VERSION_JP
static const MessageScriptEntry sEvent196Script[1] = {
    { PORTRAIT_RIKU, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 3, gEvent196Text00, MSG_SCRIPT_FLAG_END, 100 },
};

#include "event_196_text.inc"
#endif
#ifdef VERSION_EU
static const MessageScriptEntry sEvent196Script[1] = {
    { PORTRAIT_RIKU, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, 1, NULL, MSG_SCRIPT_FLAG_END, 100 },
};
#endif

const u8 gUnk_0902FC64[8] = {
    13, 0, 0, 0, 0, 128, 0, 0,
};

static const EventCameraKeyframe sEvent196Camera[1] = {
    { -64537, 65280, 71680, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent196Track0[1] = {
    { 515, 999, 89088, 89088, 0, 0, 32770, NULL, NULL },
};

static const EventCharaTrack sEvent196Tracks[1] = {
    { sEvent196Track0, EVENT_CHARA_RIKU },
};

const EventSequenceDef gEvent196 = {
    ARRAY_COUNT(sEvent196Tracks),
    sEvent196Tracks,
    sEvent196Camera,
    sEvent196Script,
    NULL,
    NULL,
    1000,
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
    POOH_LEVEL_NONE,
};
