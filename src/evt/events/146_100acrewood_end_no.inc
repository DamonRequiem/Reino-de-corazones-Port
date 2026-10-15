static const MessageScriptEntry sEvent146Script[2] = {
    { PORTRAIT_WINNIE_THE_POOH, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent145Text00), 0, 400 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent145Text01), MSG_SCRIPT_FLAG_END, 430 },
};

static const EvSoundCue sEvent146SoundCues[4] = {
    { SONG_BGM_WINNIETHEPOOH, 1, 0, 0 },
    { SONG_BG_POO, 2, 0, 0 },
    { SONG_BG_POO, 484, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_WINNIETHEPOOH, 485, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent146Camera[1] = {
    { -64537, 790528, 416512, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent146Track0[8] = {
    { 2, 1, 772096, 412160, 0, 0, 66, NULL, NULL },
    { 7, 100, 0, 0, 0, 83, 68, NULL, NULL },
    { 2, 150, 0, 0, 0, 0, 69, NULL, NULL },
    { 1, 160, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 170, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 180, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 190, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 2000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent146Track1[5] = {
    { 756, 1, 757248, 404224, 0, 0, 2, NULL, NULL },
    { 781, 230, 0, 0, 0, 83, 4, NULL, NULL },
    { 756, 240, 0, 0, 0, 0, 5, NULL, NULL },
    { 795, 1000, 0, 0, 0, 0, 325, NULL, NULL },
    { 796, 2000, 0, 0, 0, 0, 33093, NULL, NULL },
};

static const EventCharaTrack sEvent146Tracks[2] = {
    { sEvent146Track0, EVENT_CHARA_SORA },
    { sEvent146Track1, EVENT_CHARA_WINNIE_THE_POOH },
};

const EventSequenceDef gEvent146 = {
    ARRAY_COUNT(sEvent146Tracks),
    sEvent146Tracks,
    sEvent146Camera,
    sEvent146Script,
    sEvent146SoundCues,
    NULL,
    490,
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
