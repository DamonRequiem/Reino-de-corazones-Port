#ifdef VERSION_US
#include "event_023_text.inc"
#endif

static const MessageScriptEntry sEvent023Script[14] = {
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text00), 0, 100 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text01), 0, 140 },
    { PORTRAIT_LARXENE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text02), 0, 190 },
    { PORTRAIT_LARXENE, 2, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text03), 0, 192 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text04), 0, 400 },
    { PORTRAIT_LARXENE, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text05), 0, 420 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text06), 0, 460 },
    { PORTRAIT_LARXENE, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text07), 0, 480 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text08), 0, 520 },
    { PORTRAIT_LARXENE, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text09), 0, 540 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text10), 0, 560 },
    { PORTRAIT_AXEL, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text11), 0, 562 },
    { PORTRAIT_LARXENE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text12), 0, 710 },
    { PORTRAIT_AXEL, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent023Text13), MSG_SCRIPT_FLAG_END, 1020 },
};

#ifdef VERSION_JP
#include "event_023_text.inc"
#endif

static const EventCameraKeyframe sEvent023Camera[2] = {
    { -64676, 68608, 60672, 0, EVENT_CHARA_NONE, 0, 0, NULL },
    { -64537, 76544, 66816, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END | CAMERA_MODE_APPROACH, 130, NULL },
};

static const EvSoundCue sEvent023SoundCues[4] = {
    { SONG_BGM_EVENT_XIII, 0, 0, 0 },
    { SONG_EV_CARDTHR, 382, 0, 0 },
    { SONG_EV_WARPIN, 720, 0, 0 },
    { SONG_BGM_EVENT_XIII, 1075, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent023Track0[8] = {
    { 856, 385, 62720, 62208, 0, 0, 66, NULL, NULL },
    { 866, 415, 0, 0, 0, 0, 69, NULL, NULL },
    { 856, 530, 0, 0, 0, 0, 69, NULL, NULL },
    { 857, 570, 0, 0, 0, 0, 69, NULL, NULL },
    { 856, 700, 0, 0, 0, 0, 64, NULL, CreateBalloonTask },
    { 856, 720, 0, 0, 0, 0, 69, NULL, NULL },
    { 856, 850, 0, 0, 0, 0, 64, EventCharaFadeOut, NULL },
    { 856, 999, 0, 0, 0, 0, 98370, NULL, NULL },
};

static const EventCharaKeyframe sEvent023Track1[17] = {
    { 486, 135, 72960, 72704, 0, 0, 18, NULL, NULL },
    { 506, 143, 0, 0, 0, 0, 21, NULL, NULL },
    { 486, 150, 0, 0, 0, 0, 21, NULL, NULL },
    { 486, 160, 0, 0, 0, 0, 85, NULL, NULL },
    { 485, 170, 0, 0, 0, 0, 85, NULL, NULL },
    { 494, 190, 0, 0, 0, 83, 84, NULL, NULL },
    { 485, 200, 0, 0, 0, 0, 85, NULL, NULL },
    { 485, 330, 0, 0, 0, 0, 80, NULL, CreateBalloonTask },
    { 485, 340, 0, 0, 0, 0, 85, NULL, NULL },
    { 486, 350, 0, 0, 0, 0, 85, NULL, NULL },
    { 486, 358, 0, 0, 0, 0, 21, NULL, NULL },
    { 501, 410, 0, 0, 0, 0, 21, NULL, NULL },
    { 486, 490, 0, 0, 0, 0, 21, NULL, NULL },
    { 486, 500, 0, 0, 0, 0, 85, NULL, NULL },
    { 485, 860, 0, 0, 0, 0, 85, NULL, NULL },
    { 485, 990, 0, 0, 0, 0, 80, NULL, CreateBalloonTask },
    { 485, 999, 0, 0, 0, 0, 32853, NULL, NULL },
};

static const EventCharaKeyframe sEvent023Track2[6] = {
    { 591, 381, 0, 0, 0, 0, 2, NULL, NULL },
    { 591, 382, 73216, 60672, 0, 0, 274, NULL, NULL },
    { 591, 390, 66816, 55808, 0, 591, 275, NULL, NULL },
    { 591, 400, 0, 0, 0, 0, 2, NULL, NULL },
    { 608, 427, 62720, 62208, 0, 0, 338, NULL, NULL },
    { 591, 500, 0, 0, 0, 0, 98306, NULL, NULL },
};

static const EventCharaTrack sEvent023Tracks[3] = {
    { sEvent023Track0, EVENT_CHARA_LARXENE },
    { sEvent023Track1, EVENT_CHARA_AXEL },
    { sEvent023Track2, EVENT_CHARA_B_STATES_1 },
};

const EventSequenceDef gEvent023 = {
    ARRAY_COUNT(sEvent023Tracks),
    sEvent023Tracks,
    sEvent023Camera,
    sEvent023Script,
    sEvent023SoundCues,
    NULL,
    1080,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    0,
    EVENT_024_6F_ENTRANCE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
