/*
 * pc_config.h
 * Settings read from khcom.ini (port/pc_config.c).
 */
#ifndef PC_CONFIG_H
#define PC_CONFIG_H

/* GBA buttons, in KEYINPUT bit order. */
enum {
    PC_BTN_A, PC_BTN_B, PC_BTN_SELECT, PC_BTN_START,
    PC_BTN_RIGHT, PC_BTN_LEFT, PC_BTN_UP, PC_BTN_DOWN,
    PC_BTN_R, PC_BTN_L,
    PC_NUM_BUTTONS
};

#define PC_MAX_BINDINGS 4
/* Gamepad bindings: an SDL_GameControllerButton, or this flag | an axis
 * (the analog triggers). */
#define PC_PAD_AXIS_FLAG 0x100

typedef struct {
    int codes[PC_MAX_BINDINGS]; /* SDL_Scancode or gamepad code */
    int count;
} PcBinding;

typedef struct {
    int fullscreen;
    int scale;
    int integerScale;
    int vsync;
    int fps;        /* 30, 60 or 120 */
    char renderer[24]; /* "auto" or an SDL render driver name */
    int filter;     /* PC_FILTER_* (pc_video.h) */
    int gbaColors;
    int ghosting;
    int skipMovies;
    int pauseInBackground;
    int audioEnabled;
    int volume; /* 0..100 */
    int aspect;         /* picture shape: 0 original 3:2, 1 4:3, 2 16:9, 3 whole screen (phones) */
    int touchOpacity;   /* Android on-screen buttons: 0..100 % */
    int touchSize;      /* 0 small, 1 normal, 2 large */
    int vibration;      /* short vibration on each button press */
    int stickMode;      /* Android movement control: 0 floating joystick, 1 fixed joystick, 2 D-pad */
    int fastSpeed;      /* fast forward: 2, 3 or 4 times the normal speed */
    PcBinding keys[PC_NUM_BUTTONS];
    PcBinding pad[PC_NUM_BUTTONS];
} PcConfig;

extern PcConfig gPcConfig;

/* Loads the file, creating it with the defaults if it does not exist. */
void PcConfigLoad(const char* path);
/* Writes one setting back to the file loaded by PcConfigLoad. */
void PcConfigSet(const char* section, const char* key, const char* value);
extern const char* const kFilterNames[6];
extern const char* const kAspectNames[4];
extern const char* const kStickNames[3]; /* gPcConfig.stickMode */

#endif /* PC_CONFIG_H */
