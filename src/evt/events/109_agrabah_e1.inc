#ifdef VERSION_US
#include "event_109_text.inc"
#endif

static const MessageScriptEntry sEvent109Script[22] = {
    { PORTRAIT_GOOFY, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text00), 0, 250 },
    { PORTRAIT_ALADDIN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text01), 0, 280 },
    { PORTRAIT_ALADDIN, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text02), 0, 282 },
    { PORTRAIT_SORA, 3, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text03), 0, 300 },
    { PORTRAIT_GENIE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text04), 0, 320 },
    { PORTRAIT_GENIE, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text05), 0, 322 },
    { PORTRAIT_GENIE, 4, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text06), 0, 324 },
    { PORTRAIT_ALADDIN, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text07), 0, 360 },
    { PORTRAIT_GENIE, 0, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text08), 0, 430 },
    { PORTRAIT_ALADDIN, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text09), 0, 450 },
    { PORTRAIT_ALADDIN, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text10), 0, 452 },
    { PORTRAIT_GENIE, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text11), 0, 480 },
    { PORTRAIT_GENIE, 3, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text12), 0, 482 },
    { PORTRAIT_ALADDIN, 0, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text13), 0, 630 },
    { PORTRAIT_ALADDIN, 3, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text14), 0, 632 },
    { PORTRAIT_ALADDIN, 0, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text15), 0, 634 },
    { PORTRAIT_SORA, 1, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text16), 0, 650 },
    { PORTRAIT_GENIE, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text17), 0, 670 },
    { PORTRAIT_GENIE, 3, MSG_WIN_POSITION_KEEP, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text18), 0, 672 },
    { PORTRAIT_ALADDIN, 4, MSG_WIN_POSITION_BOTTOM_FACE_RIGHT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text19), 0, 690 },
    { PORTRAIT_GENIE, 3, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text20), 0, 710 },
    { PORTRAIT_ALADDIN, 1, MSG_WIN_POSITION_BOTTOM_FACE_LEFT, EVENT_TEXT_DELAY, EVENT_TEXT(gEvent109Text21), MSG_SCRIPT_FLAG_END, 740 },
};

#ifdef VERSION_JP
#include "event_109_text.inc"
#endif

static const EventCameraKeyframe sEvent109Camera[1] = {
    { -55537, 32768, 26624, 0, EVENT_CHARA_NONE, CAMERA_KEYFRAME_FLAG_END, 0, NULL },
};

static const EvSoundCue sEvent109SoundCues[2] = {
    { SONG_BGM_ALADDIN_FIELD, 0, 0, 0 },
    { SONG_BGM_ALADDIN_FIELD, 885, EV_SOUND_FLAG_FADE_OUT | EV_SOUND_FLAG_END, 0 },
};

static const EventCharaKeyframe sEvent109Track3[12] = {
    { 2, 10, 86528, 16640, 0, 0, 2, NULL, NULL },
    { 7, 200, 0, 0, 0, 173, 4, NULL, NULL },
    { 2, 260, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 265, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 299, 0, 0, 0, 0, 5, NULL, NULL },
    { 30, 301, 0, 0, 0, 0, 5, NULL, NULL },
    { 4, 370, 0, 0, 0, 0, 5, NULL, NULL },
    { 27, 420, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 4, 750, 0, 0, 0, 0, 5, NULL, NULL },
    { 3, 755, 0, 0, 0, 0, 5, NULL, NULL },
    { 2, 760, 0, 0, 0, 0, 5, NULL, NULL },
    { 12, 9999, 0, 0, 0, 173, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent109Track4[13] = {
    { 112, 1, 76032, 21248, 0, 0, 2, NULL, NULL },
    { 117, 198, 0, 0, 0, 173, 4, NULL, NULL },
    { 112, 210, 0, 0, 0, 0, 5, NULL, NULL },
    { 113, 215, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 260, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 265, 0, 0, 0, 0, 5, NULL, NULL },
    { 110, 370, 0, 0, 0, 0, 5, NULL, NULL },
    { 133, 420, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 110, 750, 0, 0, 0, 0, 5, NULL, NULL },
    { 114, 755, 0, 0, 0, 0, 5, NULL, NULL },
    { 113, 760, 0, 0, 0, 0, 5, NULL, NULL },
    { 112, 765, 0, 0, 0, 0, 5, NULL, NULL },
    { 121, 9999, 0, 0, 0, 173, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent109Track2[17] = {
    { 144, 1, 68352, 18176, 0, 0, 2, NULL, NULL },
    { 149, 190, 0, 0, 0, 173, 4, NULL, NULL },
    { 144, 210, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 215, 0, 0, 0, 0, 5, NULL, NULL },
    { 143, 220, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 225, 0, 0, 0, 0, 69, NULL, NULL },
    { 145, 230, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 249, 0, 0, 0, 0, 69, NULL, NULL },
    { 165, 251, 0, 0, 0, 0, 69, NULL, NULL },
    { 146, 370, 0, 0, 0, 0, 69, NULL, NULL },
    { 161, 420, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 146, 750, 0, 0, 0, 0, 69, NULL, NULL },
    { 142, 755, 0, 0, 0, 0, 5, NULL, NULL },
    { 146, 760, 0, 0, 0, 0, 5, NULL, NULL },
    { 145, 765, 0, 0, 0, 0, 5, NULL, NULL },
    { 144, 770, 0, 0, 0, 0, 5, NULL, NULL },
    { 152, 9999, 0, 0, 0, 173, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent109Track1[17] = {
    { 270, 10, 77824, 12800, 0, 0, 2, NULL, NULL },
    { 271, 200, 0, 0, 0, 173, 4, NULL, NULL },
    { 270, 270, 0, 0, 0, 0, 5, NULL, NULL },
    { 276, 290, 0, 0, 0, 0, 5, NULL, NULL },
    { 270, 340, 0, 0, 0, 0, 5, NULL, NULL },
    { 282, 370, 0, 0, 0, 0, 5, NULL, NULL },
    { 287, 440, 0, 0, 0, 0, 5, NULL, NULL },
    { 282, 490, 0, 0, 0, 0, 5, NULL, NULL },
    { 287, 620, 0, 0, 0, 0, 0, NULL, CreateBalloonTask },
    { 282, 631, 0, 0, 0, 0, 5, NULL, NULL },
    { 287, 633, 0, 0, 0, 0, 5, NULL, NULL },
    { 282, 680, 0, 0, 0, 0, 5, NULL, NULL },
    { 286, 720, 0, 0, 0, 0, 0, NULL, CreateExclamationTask },
    { 270, 730, 0, 0, 0, 0, 5, NULL, NULL },
    { 270, 750, 0, 0, 0, 0, 69, NULL, NULL },
    { 270, 780, 0, 0, 0, 0, 5, NULL, NULL },
    { 272, 790, 0, 0, 0, 173, 32804, NULL, NULL },
};

static const EventCharaKeyframe sEvent109Track0[14] = {
    { 664, 10, 69376, 8704, -2560, 0, 262146, NULL, NULL },
    { 666, 200, 0, 0, 0, 173, 262148, NULL, NULL },
    { 664, 240, 0, 0, 0, 0, 262149, NULL, NULL },
    { 664, 319, 0, 0, 0, 0, 262213, NULL, NULL },
    { 669, 323, 0, 0, 0, 0, 262213, NULL, NULL },
    { 666, 326, 0, 0, 0, 0, 69, NULL, NULL },
    { 664, 370, 0, 0, 0, 0, 262213, NULL, NULL },
    { 673, 420, 0, 0, 0, 0, 64, NULL, CreateExclamationTask },
    { 673, 455, 0, 0, 0, 0, 69, NULL, NULL },
    { 664, 481, 0, 0, 0, 0, 262213, NULL, NULL },
    { 666, 510, 0, 0, 0, 0, 69, NULL, NULL },
    { 664, 770, 0, 0, 0, 0, 262213, NULL, NULL },
    { 664, 780, 0, 0, 0, 0, 262149, NULL, NULL },
    { 666, 9999, 0, 0, 0, 173, 294948, NULL, NULL },
};

static const EventCharaTrack sEvent109Tracks[5] = {
    { sEvent109Track0, EVENT_CHARA_GENIE },
    { sEvent109Track1, EVENT_CHARA_ALADDIN },
    { sEvent109Track2, EVENT_CHARA_GOOFY },
    { sEvent109Track3, EVENT_CHARA_SORA },
    { sEvent109Track4, EVENT_CHARA_DONALD },
};

const EventSequenceDef gEvent109 = {
    ARRAY_COUNT(sEvent109Tracks),
    sEvent109Tracks,
    sEvent109Camera,
    sEvent109Script,
    sEvent109SoundCues,
    NULL,
    890,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    0,
    EVENT_NONE,
    0,
    { 0, 0 },
    EVENT_EXIT_NONE,
    0,
    WORLD_NONE,
    POOH_LEVEL_NONE,
};
