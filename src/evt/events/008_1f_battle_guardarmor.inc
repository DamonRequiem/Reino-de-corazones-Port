static const MessageScriptEntry sEvent008Script[1] = {
    { PORTRAIT_CID, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent007Text00), MSG_SCRIPT_FLAG_END, 9999 },
};

static const EventCameraKeyframe sEvent008Camera[9] = {
    { -65436, 69120, 94720, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -65366, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_SMALL | CAMERA_MODE_KEEP, 0, NULL },
    { -65311, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -65271, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_MEDIUM | CAMERA_MODE_KEEP, 0, NULL },
    { -65251, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_SMALL | CAMERA_MODE_KEEP, 0, NULL },
    { -65196, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_MODE_KEEP, 0, NULL },
    { -65176, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_MEDIUM | CAMERA_MODE_KEEP, 0, NULL },
    { -65156, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_SHAKE_SMALL | CAMERA_MODE_KEEP, 0, NULL },
    { -63536, 0, 0, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_KEEP, 0, NULL },
};

static const EvSoundCue sEvent008SoundCues[7] = {
    { SONG_BGM_EVENT2, 0, 0, 0 },
    { SONG_SND_389, 220, 0, 0 },
    { SONG_EV_RUMBLE, 225, 0, 0 },
    { SONG_EV_RUMBLE, 245, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_SND_389, 335, 0, 0 },
    { SONG_EV_RUMBLE, 345, 0, 0 },
    { SONG_EV_RUMBLE, 355, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent008Track0[5] = {
    { 3, 100, 48640, 110080, 0, 0, 66, NULL, NULL },
    { 105, 150, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 105, 320, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 360, 0, 0, 0, 0, 69, NULL, NULL },
    { 18, 2000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent008Track1[1] = {
    { 945, 1, 36864, 104704, 0, 0, 32770, NULL, NULL },
};

static const EventCharaTrack sEvent008Tracks[2] = {
    { sEvent008Track0, EVENT_CHARA_SORA },
    { sEvent008Track1, EVENT_CHARA_BOSS_GUARD_ARMOR },
};

const EventSequenceDef gEvent008 = {
    ARRAY_COUNT(sEvent008Tracks),
    sEvent008Tracks,
    sEvent008Camera,
    sEvent008Script,
    sEvent008SoundCues,
    NULL,
    500,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    BATTLE_GUARD_ARMOR,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
