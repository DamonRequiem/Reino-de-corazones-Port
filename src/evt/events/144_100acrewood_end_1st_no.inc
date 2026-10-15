static const MessageScriptEntry sEvent144Script[8] = {
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent143Text00), 0, 250 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent143Text01), 0, 300 },
    { PORTRAIT_WINNIE_THE_POOH, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent143Text02), 0, 330 },
    { PORTRAIT_WINNIE_THE_POOH, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent143Text03), 0, 350 },
    { PORTRAIT_WINNIE_THE_POOH, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent143Text04), 0, 500 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent143Text05), 0, 670 },
    { PORTRAIT_WINNIE_THE_POOH, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent143Text06), 0, 700 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent143Text07), MSG_SCRIPT_FLAG_END, 730 },
};

static const EvSoundCue sEvent144SoundCues[4] = {
    { SONG_BGM_WINNIETHEPOOH, 0, 0, 0 },
    { SONG_BG_POO, 2, 0, 0 },
    { SONG_BG_POO, 784, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_WINNIETHEPOOH, 785, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent144Camera[1] = {
    { -64537, 790528, 416512, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent144Track0[13] = {
    { 2, 1, 772096, 412160, 0, 0, 66, NULL, NULL },
    { 7, 100, 0, 0, 0, 83, 68, NULL, NULL },
    { 2, 110, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 120, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 150, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 160, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 170, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 180, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 260, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 265, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 510, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 640, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 4, 5000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent144Track1[6] = {
    { 756, 1, 757248, 404224, 0, 0, 2, NULL, NULL },
    { 781, 230, 0, 0, 0, 83, 4, NULL, NULL },
    { 756, 360, 0, 0, 0, 0, 5, NULL, NULL },
    { 795, 690, 0, 0, 0, 0, 325, NULL, NULL },
    { 804, 1000, 0, 0, 0, 0, 325, NULL, NULL },
    { 804, 5000, 0, 0, 0, 0, 33093, NULL, NULL },
};

static const EventCharaTrack sEvent144Tracks[2] = {
    { sEvent144Track0, EVENT_CHARA_SORA },
    { sEvent144Track1, EVENT_CHARA_WINNIE_THE_POOH },
};

const EventSequenceDef gEvent144 = {
    ARRAY_COUNT(sEvent144Tracks),
    sEvent144Tracks,
    sEvent144Camera,
    sEvent144Script,
    sEvent144SoundCues,
    NULL,
    790,
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
