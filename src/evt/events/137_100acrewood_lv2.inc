#ifdef VERSION_US
#include "event_137_text.inc"
#endif

static const MessageScriptEntry sEvent137Script[16] = {
    { PORTRAIT_OWL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text00), 0, 100 },
    { PORTRAIT_WINNIE_THE_POOH, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text01), 0, 120 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text02), 0, 140 },
    { PORTRAIT_OWL, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text03), 0, 160 },
    { PORTRAIT_OWL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text04), 0, 260 },
    { PORTRAIT_OWL, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text05), 0, 262 },
    { PORTRAIT_OWL, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text06), 0, 264 },
    { PORTRAIT_OWL, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text07), 0, 266 },
    { PORTRAIT_SORA, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text08), 0, 280 },
    { PORTRAIT_OWL, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text09), 0, 300 },
    { PORTRAIT_OWL, 1, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text10), 0, 302 },
    { PORTRAIT_WINNIE_THE_POOH, 2, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text11), 0, 400 },
    { PORTRAIT_OWL, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text12), 0, 420 },
    { PORTRAIT_WINNIE_THE_POOH, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text13), 0, 440 },
    { PORTRAIT_SORA, 4, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text14), 0, 600 },
    { PORTRAIT_OWL, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent137Text15), MSG_SCRIPT_FLAG_END, 620 },
};

#ifdef VERSION_JP
#include "event_137_text.inc"
#endif

static const EvSoundCue sEvent137SoundCues[4] = {
    { SONG_BGM_WINNIETHEPOOH, 0, 0, 0 },
    { SONG_BG_POO, 2, 0, 0 },
    { SONG_BG_POO, 824, EV_SOUND_FLAG_FADE_OUT, 0 },
    { SONG_BGM_WINNIETHEPOOH, 825, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCameraKeyframe sEvent137Camera[1] = {
    { -65226, 237824, 121344, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EventCharaKeyframe sEvent137Track0[10] = {
    { 4, 130, 235008, 129536, 0, 0, 66, NULL, NULL },
    { 0, 135, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 170, 0, 0, 0, 0, 5, NULL, NULL },
    { 0, 175, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 180, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 250, 0, 0, 0, 0, 64, NULL, CreateQuestionTask },
    { 4, 280, 0, 0, 0, 0, 69, NULL, NULL },
    { 34, 290, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 670, 0, 0, 0, 0, 69, NULL, NULL },
    { 4, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent137Track1[6] = {
    { 756, 180, 229120, 126464, 0, 0, 2, NULL, NULL },
    { 765, 250, 0, 0, 0, 0, 0, NULL, CreateQuestionTask },
    { 765, 310, 0, 0, 0, 0, 5, NULL, NULL },
    { 798, 399, 0, 0, 0, 0, 69, NULL, NULL },
    { 799, 421, 0, 0, 0, 0, 69, NULL, NULL },
    { 800, 999, 0, 0, 0, 0, 32837, NULL, NULL },
};

static const EventCharaKeyframe sEvent137Track2[6] = {
    { 814, 155, 244736, 121344, 0, 0, 2, NULL, NULL },
    { 815, 415, 0, 0, 0, 0, 5, NULL, NULL },
    { 815, 450, 0, 0, 0, 0, 5, NULL, NULL },
    { 814, 590, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 814, 630, 0, 0, 0, 0, 5, NULL, NULL },
    { 815, 999, 0, 0, 0, 0, 32773, NULL, NULL },
};

static const EventCharaTrack sEvent137Tracks[3] = {
    { sEvent137Track0, EVENT_CHARA_SORA },
    { sEvent137Track1, EVENT_CHARA_WINNIE_THE_POOH },
    { sEvent137Track2, EVENT_CHARA_OWL },
};

const EventSequenceDef gEvent137 = {
    ARRAY_COUNT(sEvent137Tracks),
    sEvent137Tracks,
    sEvent137Camera,
    sEvent137Script,
    sEvent137SoundCues,
    NULL,
    830,
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
    2,
};
