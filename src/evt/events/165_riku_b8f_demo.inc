#ifdef VERSION_US
#include "event_165_text.inc"
#endif

static const MessageScriptEntry sEvent165Script[6] = {
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent165Text00), 0, 160 },
    { PORTRAIT_RIKU_REPLICA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent165Text01), 0, 190 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent165Text02), 0, 360 },
    { PORTRAIT_RIKU_REPLICA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent165Text03), 0, 390 },
    { PORTRAIT_VEXEN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent165Text04), 0, 420 },
    { PORTRAIT_RIKU_REPLICA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent165Text05), MSG_SCRIPT_FLAG_END, 450 },
};

#ifdef VERSION_JP
#include "event_165_text.inc"
#endif

static const EvSoundCue sEvent165SoundCues[2] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_BGM_EVENT_XIII, 505, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent165Camera[1] = {
    { -64537, 68608, 51712, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent165Track0[3] = {
    { 696, 1, 31744, 77312, 0, 0, 66, NULL, NULL },
    { 712, 130, 0, 0, 0, 45, 68, NULL, NULL },
    { 696, 3000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent165Track1[5] = {
    { 721, 110, 78080, 56576, 0, 0, 66, NULL, NULL },
    { 721, 200, 0, 0, 0, 0, 5, NULL, NULL },
    { 721, 330, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 721, 1000, 0, 0, 0, 0, 5, NULL, NULL },
    { 721, 3000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent165Tracks[2] = {
    { sEvent165Track0, EVENT_CHARA_RIKU_REPLICA },
    { sEvent165Track1, EVENT_CHARA_VEXEN },
};

const EventSequenceDef gEvent165 = {
    ARRAY_COUNT(sEvent165Tracks),
    sEvent165Tracks,
    sEvent165Camera,
    sEvent165Script,
    sEvent165SoundCues,
    NULL,
    510,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_166_RIKU_B7F_ENTRANCE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
