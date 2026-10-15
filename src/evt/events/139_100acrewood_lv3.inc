#ifdef VERSION_US
#include "event_139_text.inc"
#endif

static const MessageScriptEntry sEvent139Script[12] = {
    { PORTRAIT_WINNIE_THE_POOH, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text00), 0, 100 },
    { PORTRAIT_ROO, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text01), 0, 130 },
    { PORTRAIT_WINNIE_THE_POOH, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text02), 0, 160 },
    { PORTRAIT_ROO, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text03), 0, 190 },
    { PORTRAIT_ROO, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text04), 0, 192 },
    { PORTRAIT_ROO, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text05), 0, 194 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text06), 0, 225 },
    { PORTRAIT_WINNIE_THE_POOH, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text07), 0, 255 },
    { PORTRAIT_ROO, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text08), 0, 430 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text09), 0, 460 },
    { PORTRAIT_ROO, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text10), 0, 490 },
    { PORTRAIT_ROO, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent139Text11), MSG_SCRIPT_FLAG_END, 760 },
};

#ifdef VERSION_JP
#include "event_139_text.inc"
#endif

static const EvSoundCue sEvent139SoundCues[11] = {
    { SONG_BGM_WINNIETHEPOOH, 0, 0, 0 },
    { SONG_BG_POO, 2, 0, 0 },
    { SONG_SYS_LU_JP, 521, 0, 0 },
    { SONG_SYS_LU_JP, 559, 0, 0 },
    { SONG_SYS_LU_JP, 640, 0, 0 },
    { SONG_SYS_LU_JP, 679, 0, 0 },
    { SONG_SYS_LU_JP, 820, 0, 0 },
    { SONG_SYS_LU_JP, 855, 0, 0 },
    { SONG_SYS_LU_JP, 890, 0, 0 },
    { SONG_BG_POO, 914, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_WINNIETHEPOOH, 915, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent139Camera[1] = {
    { -65336, 323328, 177152, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent139Track0[11] = {
    { 4, 220, 316928, 179456, 0, 0, 66, NULL, NULL },
    { 36, 440, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 450, 0, 0, 0, 0, 69, NULL, NULL },
    { 34, 510, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 530, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 535, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 690, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 695, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 830, 0, 0, 0, 0, 69, NULL, NULL },
    { 3, 835, 0, 0, 0, 0, 69, NULL, NULL },
    { 2, 2000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent139Track1[8] = {
    { 758, 520, 322560, 182784, 0, 0, 2, NULL, NULL },
    { 774, 530, 0, 0, 0, 0, 5, NULL, NULL },
    { 775, 710, 0, 0, 0, 0, 5, NULL, NULL },
    { 774, 720, 0, 0, 0, 0, 5, NULL, NULL },
    { 758, 840, 0, 0, 0, 0, 5, NULL, NULL },
    { 772, 850, 0, 0, 0, 0, 5, NULL, NULL },
    { 757, 860, 0, 0, 0, 0, 5, NULL, NULL },
    { 756, 2000, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaKeyframe sEvent139Track2[14] = {
    { 816, 270, 327680, 179456, 0, 0, 2, NULL, NULL },
    { 816, 400, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 816, 500, 0, 0, 0, 0, 5, NULL, NULL },
    { 816, 520, 0, 0, 0, 0, 69, NULL, NULL },
    { 818, 580, 0, 0, 0, 83, 100, NULL, NULL },
    { 816, 600, 0, 0, 0, 0, 69, NULL, NULL },
    { 816, 610, 0, 0, 0, 0, 5, NULL, NULL },
    { 817, 640, 0, 0, 0, 0, 5, NULL, NULL },
    { 819, 700, 0, 0, 0, 211, 36, NULL, NULL },
    { 817, 720, 0, 0, 0, 0, 5, NULL, NULL },
    { 816, 800, 0, 0, 0, 0, 5, NULL, NULL },
    { 816, 820, 0, 0, 0, 0, 69, NULL, NULL },
    { 818, 1000, 0, 0, 0, 83, 100, NULL, NULL },
    { 816, 2000, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaTrack sEvent139Tracks[3] = {
    { sEvent139Track0, EVENT_CHARA_SORA },
    { sEvent139Track1, EVENT_CHARA_WINNIE_THE_POOH },
    { sEvent139Track2, EVENT_CHARA_ROO },
};

const EventSequenceDef gEvent139 = {
    ARRAY_COUNT(sEvent139Tracks),
    sEvent139Tracks,
    sEvent139Camera,
    sEvent139Script,
    sEvent139SoundCues,
    NULL,
    920,
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
    3,
};
