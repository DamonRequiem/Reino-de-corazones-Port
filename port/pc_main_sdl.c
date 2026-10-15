/*
 * pc_main_sdl.c
 * Desktop frontend: window, input and timing, built on SDL2.
 *
 * The game runs exactly as in the headless build; this file only:
 *   - shows gPcFramebuffer in a resizable window (nearest-neighbour scaling,
 *     correct 3:2 aspect, optional pixel-perfect integer scaling),
 *   - feeds keyboard / gamepad state into KEYINPUT once per frame,
 *   - paces the game at the GBA's native 59.7275 frames per second, or,
 *     on a ~60 Hz monitor with vsync on, at exactly one frame per refresh
 *     (60 fps, 0.46% faster than the GBA) so motion never stutters,
 *   - pauses while the window is in the background (optional).
 *
 * Controls and display options come from khcom.ini (port/pc_config.c);
 * defaults: arrows = D-pad, X = A, Z = B, Enter = Start,
 *   Backspace / Right Shift = Select, A = L, S = R
 * The save (khcom.sav), settings, log and screenshots live next to the
 * executable, or in the user's AppData folder if that one is read-only.
 * Hotkeys: F11 or Alt+Enter = fullscreen, F10 = integer scaling,
 *   hold Tab = fast forward, F12 = screenshot, F5/F8 = quick save/load
 *   state, Esc = quit
 *
 * Testing options: --frames N --dump-every N --out DIR --press F:KEYS
 * (same meaning as in the headless build).
 */
#include <setjmp.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL.h>
#ifndef _WIN32
#include <sys/stat.h>
#endif
#include "pc_config.h"
#include "pc_menu.h"
#include "pc_touch.h"
#include "pc_video.h"
#include "pc_platform.h"

#ifdef _WIN32
#include <windows.h>
#include <SDL_syswm.h>
void PcWinDiagInit(void* hwnd);
extern volatile uint32_t gPcAlive;
extern const char* gPcLogHint;
#define PC_ALIVE() (gPcAlive++)
#else
#define PC_ALIVE() ((void)0)
#endif
int PcTakeRecoveredNotice(void);

#ifdef __ANDROID__
/* Phones and tablets: on-screen controls, always full screen, the app
 * lifecycle (another app in front, the screen turned off). */
#include <android/log.h>
#define PC_TOUCH 1
#elif defined(PC_FORCE_TOUCH)
#define PC_TOUCH 1 /* testing the phone layout on a PC (build.py --touch-test) */
#else
#define PC_TOUCH 0
#endif
static volatile int sInBackground; /* Android: the app is not visible; draw nothing */
#if PC_TOUCH
/* Leaving the app: the game is snapshotted to partidas/<region>.suspend, so
 * if Android closes it while in the background, the next start continues
 * from there. The file is removed as soon as the app comes back alive. */
static int sSuspendWait;    /* frames left to wait for the snapshot */
static int sSuspending;     /* a snapshot for the background was requested */
static int sResuming;       /* starting from such a snapshot */
#endif

#define GBA_FPS (16777216.0 / 280896.0) /* 59.7275 Hz */

/* KEYINPUT bits (active low on hardware). */
enum {
    KEY_A = 1 << 0, KEY_B = 1 << 1, KEY_SELECT = 1 << 2, KEY_START = 1 << 3,
    KEY_RIGHT = 1 << 4, KEY_LEFT = 1 << 5, KEY_UP = 1 << 6, KEY_DOWN = 1 << 7,
    KEY_R = 1 << 8, KEY_L = 1 << 9,
};

static SDL_Window* sWindow;
static SDL_Renderer* sRenderer;
static SDL_Texture* sTexture;
static FILE* sLogFile;
static jmp_buf sResetJump;
static char sBasePath[1024]; /* folder for the save, settings, log, screenshots */
/* Started by the launcher (ReinoDeCorazones.exe): --root --rom --map --region */
static const char* sRoot;
static const char* sRomPath;
static const char* sMapPath;
static const char* sRegion = "usa";

/* Where each kind of file goes. Launched from the menu, they live in the
 * program's folders (partidas/, config/, capturas/, registros/); a bare
 * development build keeps the old flat names next to the executable. */
static void FilePath(char* out, size_t n, const char* kind) {
    if (!sRoot) {
        if (!strcmp(kind, "sav")) snprintf(out, n, "%skhcom.sav", sBasePath);
        else if (!strcmp(kind, "state")) snprintf(out, n, "%skhcom.state", sBasePath);
        else if (!strcmp(kind, "ini")) snprintf(out, n, "%skhcom.ini", sBasePath);
        else if (!strcmp(kind, "log")) snprintf(out, n, "%skhcom_log.txt", sBasePath);
        else snprintf(out, n, "%s", sBasePath); /* screenshots */
        return;
    }
    if (!strcmp(kind, "sav")) snprintf(out, n, "%spartidas/%s.sav", sBasePath, sRegion);
    else if (!strcmp(kind, "state")) snprintf(out, n, "%spartidas/%s.state", sBasePath, sRegion);
    else if (!strcmp(kind, "suspend")) snprintf(out, n, "%spartidas/%s.suspend", sBasePath, sRegion);
    else if (!strcmp(kind, "ini")) snprintf(out, n, "%sconfig/reino.ini", sBasePath);
    else if (!strcmp(kind, "log")) snprintf(out, n, "%sregistros/%s.txt", sBasePath, sRegion);
    else snprintf(out, n, "%scapturas/%s_", sBasePath, sRegion);
}

static void MakeDirs(void) {
    static const char* const dirs[] = {"partidas", "config", "capturas", "registros"};
    int i;
    for (i = 0; i < 4; i++) {
        char p[1200];
        snprintf(p, sizeof(p), "%s%s", sBasePath, dirs[i]);
#ifdef _WIN32
        {
            wchar_t w[1200];
            MultiByteToWideChar(CP_UTF8, 0, p, -1, w, 1200);
            CreateDirectoryW(w, NULL);
        }
#else
        mkdir(p, 0755);
#endif
    }
}

static uint64_t sPerfFreq;
static uint64_t sNextFrameTime;
static int sFastForward;
static int sAudioMuted;
static int sTestFast;
static uint32_t sTestPadAt, sTestPadOff; /* testing: a virtual controller comes / goes at these frames */
static double sAudioBaseSpeed = 1.0; /* sound speed at normal pace (UpdatePacing) */
static double sAudioSpeedSet = -1;
static int sIntegerScale;
static int sPaused;         /* window in the background */

/* Automated test options. */
static uint32_t sMaxFrames;
static double sRunSeconds;   /* --seconds: real-time run, then report the frame rate */
static uint64_t sStartTime;
static int sCrashTest; /* 1 = crash, 2 = hang (checks the diagnostics) */
#if PC_TOUCH
static uint32_t sBgTestFrame, sBgTestBack; /* --bgtest F: send to background at frame F */
static int sBgTestKill;                     /* --bgkill: ...and "kill" the process there */
#endif
static uint32_t sDumpEvery;
static const char* sOutDir = ".";
#define MAX_PRESSES 8192
static struct { uint32_t frame; uint16_t keys; } sPresses[MAX_PRESSES];
static int sNumPresses;

/* The log stops growing past this (a long session must not fill the phone). */
#define LOG_LIMIT (2u << 20)
static int sLogFull;
static unsigned sLogcatLines;

void PcLog(const char* fmt, ...) {
    va_list ap;
    if (sLogFile && !sLogFull && ftell(sLogFile) > (long)LOG_LIMIT) {
        fputs("[pc] log: size limit reached, further messages are not written\n", sLogFile);
        fflush(sLogFile);
        sLogFull = 1;
    }
    if (sLogFull)
        return;
    va_start(ap, fmt);
#ifdef __ANDROID__
    if (sLogcatLines < 20000) { /* logcat: same idea */
        va_list ap2;
        sLogcatLines++;
        va_copy(ap2, ap);
        __android_log_vprint(ANDROID_LOG_INFO, "ReinoDeCorazones", fmt, ap2);
        va_end(ap2);
    }
#endif
    if (sLogFile) {
        vfprintf(sLogFile, fmt, ap);
        fflush(sLogFile);
    } else {
        vfprintf(stderr, fmt, ap);
    }
    va_end(ap);
}

void PcLongjmpToMain(int code) {
    longjmp(sResetJump, code);
}

void PcRequestSoftReset(void) {
    PcLog("[pc] soft reset at frame %u\n", gPcFrameCount);
    PcLongjmpToMain(1);
}

/* Short message in the window title (recovery, quick save/load). */
static uint32_t sNoticeUntil;
static void ShowNotice(const char* text) {
    char title[200];
#ifdef __ANDROID__
    SDL_AndroidShowToast(text, 0, -1, 0, 0); /* no title bar on a phone */
#endif
    snprintf(title, sizeof(title), "Reino de Corazones  -  %s", text);
    SDL_SetWindowTitle(sWindow, title);
    sNoticeUntil = gPcFrameCount + 180;
}

static void UpdateNotice(void) {
    if (sNoticeUntil && gPcFrameCount >= sNoticeUntil) {
        SDL_SetWindowTitle(sWindow, "Reino de Corazones");
        sNoticeUntil = 0;
    }
}

#ifdef __ANDROID__
/* On Android the game returns from SDL_main instead of exiting, so the
 * activity closes normally (GameActivity then ends its process). */
static jmp_buf sQuitJump;
static int sQuitReady, sQuitCode;
#endif

static void Quit(int code) {
    PcSaveFlush();
    PcAudioClose();
    PcLog("[pc] exiting after %u frames\n", gPcFrameCount);
    if (sLogFile)
        fclose(sLogFile);
    sLogFile = NULL;
    SDL_Quit();
#ifdef __ANDROID__
    if (sQuitReady) {
        sQuitCode = code;
        longjmp(sQuitJump, 1);
    }
#endif
    exit(code);
}

static void Fatal(const char* msg) {
    PcLog("[pc] fatal: %s\n", msg);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Reino de Corazones", msg, sWindow);
    Quit(1);
}

/* ------------------------------------------------------------------ */
/* Input                                                                */
/* ------------------------------------------------------------------ */

static uint16_t ReadKeyboard(void) {
    const Uint8* k = SDL_GetKeyboardState(NULL);
    uint16_t held = 0;
    int btn, i;

    /* Alt+Enter toggles fullscreen; don't let it press Start too. */
    if (SDL_GetModState() & KMOD_ALT)
        return 0;
    for (btn = 0; btn < PC_NUM_BUTTONS; btn++)
        for (i = 0; i < gPcConfig.keys[btn].count; i++)
            if (k[gPcConfig.keys[btn].codes[i]])
                held |= (uint16_t)(1 << btn);
    return held;
}

/* ---- Game controllers: a notice when one comes or goes; on phones the
 * on-screen buttons hide while one is connected. ---- */
static int CountControllers(void) {
    int i, n = 0;
    for (i = 0; i < SDL_NumJoysticks(); i++)
        if (SDL_IsGameController(i) && SDL_GameControllerFromInstanceID(SDL_JoystickGetDeviceInstanceID(i)))
            n++;
    return n;
}

static void ControllerAdded(int which) {
    SDL_GameController* c;
    const char* name;
    char text[160];
    if (!SDL_IsGameController(which) || SDL_GameControllerFromInstanceID(SDL_JoystickGetDeviceInstanceID(which)))
        return; /* not a controller, or already open */
    c = SDL_GameControllerOpen(which);
    if (!c)
        return;
    name = SDL_GameControllerName(c);
    if (name && (SDL_strcasestr(name, "uinput") || SDL_strcasestr(name, "virtual") || SDL_strcasestr(name, "fpc") ||
                 SDL_strcasestr(name, "gpio") || SDL_strcasestr(name, "goodix")))
    {
        SDL_GameControllerClose(c); /* a phone's own sensor or button chip, not a controller */
        return;
    }
    PcLog("[pc] controller connected: %s\n", name ? name : "?");
    snprintf(text, sizeof(text), "Mando conectado: %s", name && *name ? name : "mando");
    ShowNotice(text);
#if PC_TOUCH
    PcTouchSetGamepad(1);
#endif
}

static void ControllerRemoved(SDL_JoystickID id) {
    SDL_GameController* c = SDL_GameControllerFromInstanceID(id);
    if (!c)
        return;
    SDL_GameControllerClose(c);
    PcLog("[pc] controller disconnected\n");
    if (CountControllers() == 0) {
        ShowNotice("Mando desconectado");
#if PC_TOUCH
        PcTouchSetGamepad(0);
#endif
    }
}

static void ControllerUsed(const SDL_Event* e) {
#if PC_TOUCH
    if (e->type == SDL_CONTROLLERBUTTONDOWN ||
        (e->type == SDL_CONTROLLERAXISMOTION && (e->caxis.value > 16000 || e->caxis.value < -16000)))
        PcTouchGamepadUsed();
#else
    (void)e;
#endif
}

static int PadPressed(SDL_GameController* c, int code) {
    if (code & PC_PAD_AXIS_FLAG)
        return SDL_GameControllerGetAxis(c, (SDL_GameControllerAxis)(code & 0xFF)) > 16000;
    return SDL_GameControllerGetButton(c, (SDL_GameControllerButton)code);
}

static uint16_t ReadGamepads(void) {
    uint16_t held = 0;
    int i, btn, j;

    for (i = 0; i < SDL_NumJoysticks(); i++) {
        SDL_GameController* c;
        int lx, ly;

        if (!SDL_IsGameController(i))
            continue;
        c = SDL_GameControllerFromInstanceID(SDL_JoystickGetDeviceInstanceID(i));
        if (c == NULL)
            continue;
        for (btn = 0; btn < PC_NUM_BUTTONS; btn++)
            for (j = 0; j < gPcConfig.pad[btn].count; j++)
                if (PadPressed(c, gPcConfig.pad[btn].codes[j]))
                    held |= (uint16_t)(1 << btn);
        /* The left stick always works as a D-pad. */
        lx = SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTX);
        ly = SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTY);
        if (lx < -16000) held |= KEY_LEFT;
        if (lx > 16000) held |= KEY_RIGHT;
        if (ly < -16000) held |= KEY_UP;
        if (ly > 16000) held |= KEY_DOWN;
    }
    return held;
}

static uint16_t FilterDpad(uint16_t held) {
    /* Opposite directions cannot be held on a real D-pad; some games misbehave. */
    if ((held & (KEY_LEFT | KEY_RIGHT)) == (KEY_LEFT | KEY_RIGHT)) held &= ~(KEY_LEFT | KEY_RIGHT);
    if ((held & (KEY_UP | KEY_DOWN)) == (KEY_UP | KEY_DOWN)) held &= ~(KEY_UP | KEY_DOWN);
    return held;
}

static uint16_t ParseKeys(const char* s) {
    uint16_t k = 0;
    for (; *s; s++) {
        switch (*s) {
            case 'A': k |= KEY_A; break;
            case 'B': k |= KEY_B; break;
            case 'S': k |= KEY_SELECT; break;
            case 'T': k |= KEY_START; break;
            case 'R': k |= KEY_RIGHT; break;
            case 'L': k |= KEY_LEFT; break;
            case 'U': k |= KEY_UP; break;
            case 'D': k |= KEY_DOWN; break;
            case 'r': k |= KEY_R; break;
            case 'l': k |= KEY_L; break;
        }
    }
    return k;
}

/* ------------------------------------------------------------------ */
/* Video                                                                */
/* ------------------------------------------------------------------ */

static void ApplySettings(void);
static void ToggleFullscreen(void) {
    gPcConfig.fullscreen = !gPcConfig.fullscreen;
    PcConfigSet("video", "fullscreen", gPcConfig.fullscreen ? "1" : "0");
    ApplySettings();
}

static void SaveScreenshotNow(void) {
    char path[1200];
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    char prefix[1100];
    FilePath(prefix, sizeof(prefix), "shot");
    snprintf(path, sizeof(path), "%s%s%04d%02d%02d_%02d%02d%02d.bmp", prefix, sRoot ? "" : "khcom_",
             tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
    if (PcSaveScreenshot(path))
        PcLog("[pc] screenshot saved: %s\n", path);
}

/* ------------------------------------------------------------------ */
/* Picture: filters, frame rate                                         */
/* ------------------------------------------------------------------ */

static int sMonitorHz = 60;
static int sLockDiv;            /* vsync lock: monitor refreshes per game frame (0 = timer pacing) */
static int sFramesSincePresent;
static uint64_t sLastPresentTime;
static int sMidPresentPending;  /* 120 fps without lock: show the real frame halfway */
static int sTexW, sTexH;
static uint32_t* sPrevImg;      /* last frame's filtered picture (120 fps in-between frames) */
static uint32_t* sBlendImg;
static int sPrevW, sPrevH, sPrevCap;
static const uint32_t* sCurImg;
static int sCurW, sCurH, sCurSmooth;
static int sSuppressInput;      /* after the menu: ignore keys until released */
static int sMenuRequested;
static int sMenuAvailable;
static int sAppliedScale;

static unsigned sPresentCount;
static const char* sCaptureFile; /* testing: --capture-at FRAME:FILE.bmp [--menu] */
static uint32_t sCaptureFrame;
static int sCaptureMenu;

static void DrawEx(const uint32_t* img, int w, int h, int smooth, int present);
static void FilterFrame(int keepPrevious);
static void Draw(const uint32_t* img, int w, int h, int smooth) {
    DrawEx(img, w, h, smooth, 1);
}

static void DrawEx(const uint32_t* img, int w, int h, int smooth, int present) {
    if (sInBackground)
        return; /* no surface to draw on (Android, app in the background) */
    if (!sTexture || w != sTexW || h != sTexH) {
        if (sTexture)
            SDL_DestroyTexture(sTexture);
        sTexture = SDL_CreateTexture(sRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
        sTexW = w;
        sTexH = h;
        if (!sTexture)
            return;
    }
    {
        /* Shown at exactly its own size, smoothing would only blur it. */
        int ow, oh, dw;
        float k;
        SDL_GetRendererOutputSize(sRenderer, &ow, &oh);
        k = (float)ow / PC_SCREEN_W < (float)oh / PC_SCREEN_H ? (float)ow / PC_SCREEN_W : (float)oh / PC_SCREEN_H;
        if (sIntegerScale && k >= 1)
            k = (float)(int)k;
        dw = (int)(PC_SCREEN_W * k + 0.5f);
        if (dw == w)
            smooth = 0;
    }
    SDL_SetTextureScaleMode(sTexture, smooth ? SDL_ScaleModeLinear : SDL_ScaleModeNearest);
    SDL_UpdateTexture(sTexture, NULL, img, w * 4);
#if PC_TOUCH
    {
        /* The picture as large as the screen allows (3:2), the controls
         * around and over it, in screen pixels. */
        int ow, oh;
        SDL_Rect dst;
        float k;
        static const float kAspect[4] = {3.0f / 2.0f, 4.0f / 3.0f, 16.0f / 9.0f, 0};
        float aspect;
        SDL_RenderSetLogicalSize(sRenderer, 0, 0);
        SDL_GetRendererOutputSize(sRenderer, &ow, &oh);
        aspect = kAspect[gPcConfig.aspect & 3];
        if (aspect == 0)
            aspect = (float)ow / oh; /* the whole screen */
        k = (float)ow / (oh * aspect) < 1 ? (float)ow / (oh * aspect) : 1; /* never wider than the screen */
        dst.h = (int)(oh * k);
        dst.w = (int)(oh * k * aspect);
        if (dst.w > ow)
            dst.w = ow;
        dst.x = (ow - dst.w) / 2;
        dst.y = (oh - dst.h) / 2;
        /* A whole-number enlargement first (the filter's), then the graphics
         * card smooths only the last fraction: even pixels, no blur. */
        SDL_SetTextureScaleMode(sTexture, dst.w == w && dst.h == h ? SDL_ScaleModeNearest : SDL_ScaleModeLinear);
        PcTouchLayout(ow, oh, &dst);
        SDL_SetRenderDrawColor(sRenderer, 0, 0, 0, 255);
        SDL_RenderClear(sRenderer);
        PcTouchDrawBackdrop(sRenderer, ow, oh, &dst);
        SDL_RenderCopy(sRenderer, sTexture, NULL, &dst);
        if (!PcMenuIsOpen() || PcMenuPreviewing())
            PcTouchDraw(sRenderer);
        PcMenuDraw(sRenderer);
        if (present) {
            SDL_RenderPresent(sRenderer);
            sPresentCount++;
        }
        return;
    }
#endif
    SDL_RenderSetLogicalSize(sRenderer, PC_SCREEN_W, PC_SCREEN_H);
    SDL_RenderSetIntegerScale(sRenderer, sIntegerScale ? SDL_TRUE : SDL_FALSE);
    SDL_SetRenderDrawColor(sRenderer, 0, 0, 0, 255);
    SDL_RenderClear(sRenderer);
    SDL_RenderCopy(sRenderer, sTexture, NULL, NULL);
    PcMenuDraw(sRenderer);
    if (present) {
        SDL_RenderPresent(sRenderer);
        sPresentCount++;
    }
}

/* Testing: saves exactly what the window shows. */
static void CaptureWindow(const char* file) {
    int ow, oh;
    SDL_Surface* s;
    if (sCaptureMenu)
        PcMenuOpen();
    FilterFrame(0);
    DrawEx(sCurImg, sCurW, sCurH, sCurSmooth, 0);
    SDL_RenderSetLogicalSize(sRenderer, 0, 0);
    SDL_GetRendererOutputSize(sRenderer, &ow, &oh);
    s = SDL_CreateRGBSurfaceWithFormat(0, ow, oh, 32, SDL_PIXELFORMAT_ARGB8888);
    if (s) {
        SDL_RenderReadPixels(sRenderer, NULL, SDL_PIXELFORMAT_ARGB8888, s->pixels, s->pitch);
        SDL_SaveBMP(s, file);
        SDL_FreeSurface(s);
    }
    PcMenuClose();
}

/* Runs the chosen filter on the game's current frame. */
static void FilterFrame(int keepPrevious) {
    PcVideoSettings vs;
    if (keepPrevious && sCurImg && gPcConfig.fps == 120) {
        int n = sCurW * sCurH;
        if (n > sPrevCap) {
            free(sPrevImg);
            free(sBlendImg);
            sPrevImg = (uint32_t*)malloc((size_t)n * 4);
            sBlendImg = (uint32_t*)malloc((size_t)n * 4);
            sPrevCap = sPrevImg && sBlendImg ? n : 0;
        }
        if (sPrevCap >= n) {
            memcpy(sPrevImg, sCurImg, (size_t)n * 4);
            sPrevW = sCurW;
            sPrevH = sCurH;
        }
    }
    vs.filter = gPcConfig.filter;
    vs.scale = gPcConfig.scale;
#if PC_TOUCH
    {
        /* Phones: as large a whole-number step as the screen needs (max 5). */
        int ow = 0, oh = 0;
        if (sRenderer)
            SDL_GetRendererOutputSize(sRenderer, &ow, &oh);
        vs.scale = oh / PC_SCREEN_H;
        vs.scale = vs.scale < 2 ? 2 : vs.scale > 5 ? 5 : vs.scale;
    }
#endif
    vs.gbaColors = gPcConfig.gbaColors;
    vs.ghosting = gPcConfig.ghosting;
    sCurImg = PcVideoFilter(&vs, &sCurW, &sCurH, &sCurSmooth);
}

/* Shows the current picture again (menu, background pause). */
static void Redraw(void) {
    if (!sCurImg)
        FilterFrame(0);
    Draw(sCurImg, sCurW, sCurH, sCurSmooth);
}

static void DrawBlended(void) {
    if (sPrevImg && sPrevW == sCurW && sPrevH == sCurH) {
        PcVideoBlend(sPrevImg, sCurImg, sBlendImg, sCurW * sCurH);
        Draw(sBlendImg, sCurW, sCurH, sCurSmooth);
    } else {
        Draw(sCurImg, sCurW, sCurH, sCurSmooth);
    }
}

/* Makes the renderer and the artwork textures. */
static void CreateRenderer(void) {
    sRenderer = SDL_CreateRenderer(sWindow, -1, SDL_RENDERER_ACCELERATED |
                                                    (gPcConfig.vsync && !sMaxFrames ? SDL_RENDERER_PRESENTVSYNC : 0));
    if (!sRenderer) {
        PcLog("[pc] video: renderer unavailable (%s), using the default one\n", SDL_GetError());
        SDL_SetHint(SDL_HINT_RENDER_DRIVER, "");
        sRenderer = SDL_CreateRenderer(sWindow, -1, SDL_RENDERER_ACCELERATED |
                                                    (gPcConfig.vsync && !sMaxFrames ? SDL_RENDERER_PRESENTVSYNC : 0));
    }
    if (!sRenderer)
        sRenderer = SDL_CreateRenderer(sWindow, -1, SDL_RENDERER_SOFTWARE);
    if (!sRenderer)
        Fatal(SDL_GetError());
    SDL_RenderSetLogicalSize(sRenderer, PC_SCREEN_W, PC_SCREEN_H);
    SDL_RenderSetIntegerScale(sRenderer, sIntegerScale ? SDL_TRUE : SDL_FALSE);
    sMenuAvailable = PcMenuInit(sRenderer, sRoot != NULL);
#if PC_TOUCH
    PcTouchReload(sRenderer);
#endif
}

/* The phone lost the graphics context (seen on some devices after a long
 * time in the background): the renderer and every texture are made again,
 * and the old ones freed, so nothing piles up however often it happens. */
static void ResetRenderer(void) {
    PcLog("[pc] video: graphics context lost, renderer recreated\n");
    sTexture = NULL; /* freed with the renderer */
    SDL_DestroyRenderer(sRenderer);
    sRenderer = NULL;
    CreateRenderer();
}

/* Called once per game frame: shows it according to the frame-rate setting.
 *   60  one picture per game frame (the GBA's rate)
 *   30  every other game frame (the game itself still runs at full speed)
 *   120 on a 120 Hz+ monitor, an in-between picture (the two frames mixed)
 *       before each real one: the GBA game animates at 60, this smooths it. */
static void ShowFrame(void) {
    int presents, blended = 0, i;
    sFramesSincePresent++;
    if (sFastForward) {
        /* Fast forward: one picture per refresh, the game runs N frames. */
        if (gPcFrameCount % (unsigned)gPcConfig.fastSpeed == 0) {
            FilterFrame(0);
            Draw(sCurImg, sCurW, sCurH, sCurSmooth);
        }
        sFramesSincePresent = 0;
        return;
    }
    if (gPcConfig.fps == 30 && (gPcFrameCount & 1))
        return; /* shown together with the next frame */
    FilterFrame(1);
    if (sLockDiv) {
        presents = sLockDiv * sFramesSincePresent; /* one per monitor refresh */
        if (gPcConfig.fps == 120 && sLockDiv >= 2)
            blended = sLockDiv / 2;
    } else {
        presents = 1;
        if (gPcConfig.fps == 120 && sMonitorHz >= 100) {
            blended = 1;
            sMidPresentPending = 1;
        }
    }
    for (i = 0; i < presents; i++) {
        if (i < blended)
            DrawBlended();
        else
            Draw(sCurImg, sCurW, sCurH, sCurSmooth);
    }
    sFramesSincePresent = 0;
}

/* Decides how frames are paced on this monitor. A monitor at 60, 120, 180
 * or 240 Hz with vsync on gets a fixed number of refreshes per game frame:
 * perfectly even motion, 0.46% faster than the GBA. Other rates (144 Hz,
 * vsync off) are paced by the clock at the GBA's own 59.73 frames/second. */
static void UpdatePacing(void) {
    SDL_DisplayMode mode;
    int k;
    sMonitorHz = 60;
    if (SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(sWindow), &mode) == 0 && mode.refresh_rate > 0)
        sMonitorHz = mode.refresh_rate;
    if (SDL_getenv("RDC_TEST_HZ")) /* testing: pretend the monitor runs at this rate */
        sMonitorHz = SDL_atoi(SDL_getenv("RDC_TEST_HZ"));
    sLockDiv = 0;
    if (gPcConfig.vsync && !sMaxFrames)
        for (k = 1; k <= 4; k++)
            if (sMonitorHz >= 60 * k - 1 && sMonitorHz <= 60 * k + 1)
                sLockDiv = k;
    sAudioBaseSpeed = sLockDiv ? (double)sMonitorHz / sLockDiv / GBA_FPS : 1.0;
    sAudioSpeedSet = -1; /* applied by FrameHook */
    PcMenuSetMonitorHz(sMonitorHz);
    PcLog("[pc] display: %d Hz, %d fps, %s\n", sMonitorHz, gPcConfig.fps,
          sLockDiv ? "locked to the monitor" : gPcConfig.vsync ? "timer pacing, vsync present" : "timer pacing");
    sNextFrameTime = 0;
    sLastPresentTime = 0;
}

/* Window size for a resolution setting, shrunk (keeping 3:2) if the screen
 * is too small; the picture is still drawn at the chosen resolution. */
static void WindowSizeFor(int scale, int* w, int* h) {
    SDL_Rect usable;
    int idx = sWindow ? SDL_GetWindowDisplayIndex(sWindow) : 0;
    *w = PC_SCREEN_W * scale;
    *h = PC_SCREEN_H * scale;
    if (SDL_GetDisplayUsableBounds(idx < 0 ? 0 : idx, &usable) == 0) {
        int maxW = usable.w * 95 / 100, maxH = (usable.h - 40) * 95 / 100; /* room for the title bar */
        if (*w > maxW || *h > maxH) {
            float k = (float)maxW / *w < (float)maxH / *h ? (float)maxW / *w : (float)maxH / *h;
            *w = (int)(*w * k) / 3 * 3;
            *h = *w * 2 / 3;
        }
    }
}

/* Applies the settings in gPcConfig (from the menu or a hotkey). */
static void ApplySettings(void) {
    int fs = (SDL_GetWindowFlags(sWindow) & SDL_WINDOW_FULLSCREEN_DESKTOP) != 0;
    if (fs != gPcConfig.fullscreen)
        SDL_SetWindowFullscreen(sWindow, gPcConfig.fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    if (!gPcConfig.fullscreen && sAppliedScale != gPcConfig.scale) {
        int w, h;
        WindowSizeFor(gPcConfig.scale, &w, &h);
        SDL_SetWindowSize(sWindow, w, h);
        SDL_SetWindowPosition(sWindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }
    sAppliedScale = gPcConfig.scale;
    {
        /* Only when it changes: on some drivers this resets the device. */
        static int lastVsync = -1;
        int want = gPcConfig.vsync && !sMaxFrames;
        if (want != lastVsync) {
            if (lastVsync >= 0)
                SDL_RenderSetVSync(sRenderer, want);
            lastVsync = want;
        }
    }
    PcAudioSetVolume(gPcConfig.volume);
    UpdatePacing();
}

static void HandleEvent(SDL_Event* ev) {
    SDL_Event e = *ev;
    {
#if PC_TOUCH
        if (PcTouchHandleEvent(&e))
            return;
#endif
        switch (e.type) {
            case SDL_QUIT:
                Quit(0);
                break;
            case SDL_APP_WILLENTERBACKGROUND:
                /* Android may close the app while it is in the background:
                 * write the save now, snapshot the game, then stop until it
                 * comes back. Nothing is drawn from here on. */
                PcSaveFlush();
                sInBackground = 1;
                PcAudioPause(1);
#if PC_TOUCH
                if (!sSuspending && !PcMenuIsOpen()) {
                    /* A few more frames, unseen and silent, so the game reaches
                     * the point where it can be snapshotted. */
                    char path[1200];
                    FilePath(path, sizeof(path), "suspend");
                    PcStateRequestQuickSave(path);
                    sSuspending = 1;
                    sSuspendWait = 6;
                    sPaused = 0;
                    break;
                }
#endif
                sPaused = 1;
                break;
            case SDL_APP_DIDENTERFOREGROUND:
                sInBackground = 0;
#if PC_TOUCH
                {
                    /* Still alive: the background snapshot is not needed. */
                    char path[1200];
                    FilePath(path, sizeof(path), "suspend");
                    remove(path);
                    sSuspendWait = 0;
                }
#endif
                if (sPaused) {
                    sPaused = 0;
                    PcAudioPause(0);
                    sNextFrameTime = 0;
#if PC_TOUCH
                    PcTouchReset();
#endif
                }
                break;
            case SDL_RENDER_DEVICE_RESET:
            case SDL_RENDER_TARGETS_RESET:
                /* The phone dropped the graphics memory (app switch): the
                 * textures must be made again. */
                if (e.type == SDL_RENDER_DEVICE_RESET)
                    ResetRenderer();
                break;
            case SDL_WINDOWEVENT:
                if (gPcConfig.pauseInBackground && !sMaxFrames) {
                    if (e.window.event == SDL_WINDOWEVENT_FOCUS_LOST && !sPaused) {
                        sPaused = 1;
                        PcAudioPause(1);
                        SDL_SetWindowTitle(sWindow, "Reino de Corazones  -  en pausa");
                    } else if (e.window.event == SDL_WINDOWEVENT_FOCUS_GAINED && sPaused) {
                        sPaused = 0;
                        PcAudioPause(0);
                        SDL_SetWindowTitle(sWindow, "Reino de Corazones");
                        sNextFrameTime = 0; /* restart the frame schedule */
                    }
                }
                break;
            case SDL_CONTROLLERDEVICEADDED:
                ControllerAdded(e.cdevice.which);
                break;
            case SDL_CONTROLLERDEVICEREMOVED:
                ControllerRemoved(e.cdevice.which);
                break;
            case SDL_CONTROLLERAXISMOTION:
                ControllerUsed(&e);
                break;
            case SDL_CONTROLLERBUTTONDOWN:
                ControllerUsed(&e);
                if (sMenuAvailable && (e.cbutton.button == SDL_CONTROLLER_BUTTON_GUIDE ||
                                       e.cbutton.button == SDL_CONTROLLER_BUTTON_RIGHTSTICK))
                    sMenuRequested = 1;
                break;
            case SDL_KEYDOWN:
                if (e.key.repeat)
                    break;
                if (e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_AC_BACK) {
                    if (sMenuAvailable && !sMaxFrames)
                        sMenuRequested = 1;
                    else
                        Quit(0);
                }
                else if (e.key.keysym.sym == SDLK_F11 ||
                         (e.key.keysym.sym == SDLK_RETURN && (e.key.keysym.mod & KMOD_ALT)))
                    ToggleFullscreen();
                else if (e.key.keysym.sym == SDLK_F10)
                    sIntegerScale = !sIntegerScale; else if (e.key.keysym.sym == SDLK_F9) {
                    sAudioMuted = !sAudioMuted;
                    ShowNotice(sAudioMuted ? "sonido silenciado (F9)" : "sonido activado");
                } else if (e.key.keysym.sym == SDLK_F12)
                    SaveScreenshotNow();
                else if (e.key.keysym.sym == SDLK_F5 || e.key.keysym.sym == SDLK_F8) {
                    char path[1200];
                    FilePath(path, sizeof(path), "state");
                    if (e.key.keysym.sym == SDLK_F5)
                        PcStateRequestQuickSave(path);
                    else
                        PcStateRequestQuickLoad(path);
                }
                break;
        }
    }
}

static void PollEvents(void) {
    SDL_Event e;
    while (SDL_PollEvent(&e))
        HandleEvent(&e);
    sFastForward = SDL_GetKeyboardState(NULL)[SDL_SCANCODE_TAB];
    if (sTestFast) /* testing: --fast */
        sFastForward = 1;
#if PC_TOUCH
    sFastForward |= PcTouchFastForward();
    if (PcTouchTakeMenu() && sMenuAvailable)
        sMenuRequested = 1;
#endif
}

static void WaitUntil(uint64_t until) {
    for (;;) {
        int64_t remaining = (int64_t)(until - SDL_GetPerformanceCounter());
        if (remaining <= 0)
            break;
        /* Sleep for most of the wait, then spin for precision. */
        if (remaining > (int64_t)(sPerfFreq / 500))
            SDL_Delay((Uint32)((remaining * 1000) / sPerfFreq) - 1);
    }
}

/* Waits until the next frame is due. */
static void Pace(void) {
    uint64_t frameTicks = (uint64_t)(sPerfFreq / GBA_FPS);
    uint64_t now = SDL_GetPerformanceCounter();

    if (sFastForward && !sMaxFrames) {
        /* Fast forward: paced by the clock at N times the GBA's rate, so the
         * sound can keep up (sped up, like a tape played fast). */
        uint64_t ft = frameTicks / (uint64_t)gPcConfig.fastSpeed;
        if (sNextFrameTime == 0 || now > sNextFrameTime + ft * 8)
            sNextFrameTime = now;
        sNextFrameTime += ft;
        WaitUntil(sNextFrameTime);
        sLastPresentTime = SDL_GetPerformanceCounter();
        sMidPresentPending = 0;
        return;
    }
    if (sMaxFrames) {
        sNextFrameTime = now;
        sLastPresentTime = now;
        sMidPresentPending = 0;
        return;
    }
    if (sLockDiv) {
        /* ShowFrame() already waited for the monitor. If that returned much
         * too early (vsync ignored by the driver, window minimised...), wait
         * out the rest so the game never runs fast. */
        uint64_t want;
        if (sFramesSincePresent)
            return; /* 30 fps: this frame is shown with the next one */
        want = sPerfFreq * (gPcConfig.fps == 30 ? 2 : 1) / 60;
        if (sLastPresentTime && now - sLastPresentTime < want * 85 / 100) {
            uint64_t until = sLastPresentTime + want;
            WaitUntil(until);
            now = until; /* keep an exact schedule, no drift */
        }
        sLastPresentTime = now;
        return;
    }
    if (sNextFrameTime == 0 || now > sNextFrameTime + frameTicks * 4)
        sNextFrameTime = now; /* first frame, or we fell far behind (e.g. window dragged) */
    sNextFrameTime += frameTicks;
    if (sMidPresentPending) {
        /* 120 fps on a fast monitor without lock: in-between picture shown
         * at the start of the frame, the real one halfway. */
        WaitUntil(sNextFrameTime - frameTicks / 2);
        Draw(sCurImg, sCurW, sCurH, sCurSmooth);
        sMidPresentPending = 0;
    }
    WaitUntil(sNextFrameTime);
}

/* The Esc menu: the game waits while it is open. */
static void RunMenu(void) {
    char path[1200];
    PcAudioPause(1);
    PcMenuOpen();
#if PC_TOUCH
    PcTouchReset();
#endif
    while (PcMenuIsOpen()) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                Quit(0);
#if PC_TOUCH
            if (PcTouchHandleEvent(&e)) {
                if (PcTouchTakeMenu())
                    PcMenuClose(); /* the heart again: back to the game */
                continue;
            }
            if (e.type == SDL_APP_WILLENTERBACKGROUND) {
                PcSaveFlush();
                sInBackground = 1;
                continue;
            }
            if (e.type == SDL_APP_DIDENTERFOREGROUND) {
                sInBackground = 0;
                continue;
            }
            if (e.type == SDL_RENDER_DEVICE_RESET) {
                ResetRenderer();
                continue;
            }
#endif
            if (e.type == SDL_CONTROLLERDEVICEADDED) {
                ControllerAdded(e.cdevice.which);
                continue;
            }
            if (e.type == SDL_CONTROLLERDEVICEREMOVED) {
                ControllerRemoved(e.cdevice.which);
                continue;
            }
            if (e.type == SDL_KEYDOWN && !e.key.repeat &&
                (e.key.keysym.sym == SDLK_F11 || (e.key.keysym.sym == SDLK_RETURN && (e.key.keysym.mod & KMOD_ALT)))) {
                ToggleFullscreen();
                continue;
            }
            if (e.type == SDL_KEYDOWN && e.key.repeat && e.key.keysym.sym == SDLK_ESCAPE)
                continue;
            switch (PcMenuHandleEvent(sRenderer, &e)) {
                case PC_MENU_CHANGED:
                    ApplySettings();
                    break;
                case PC_MENU_SAVE_STATE:
                    FilePath(path, sizeof(path), "state");
                    PcStateRequestQuickSave(path);
                    break;
                case PC_MENU_LOAD_STATE:
                    FilePath(path, sizeof(path), "state");
                    PcStateRequestQuickLoad(path);
                    break;
                case PC_MENU_QUIT:
                    Quit(0);
                    break;
            }
            if (!PcMenuIsOpen())
                break;
        }
        PC_ALIVE(); /* the game waits on purpose while the menu is open */
        if (sInBackground) {
            SDL_Delay(50);
            continue;
        }
        FilterFrame(0); /* live preview of the settings */
        Draw(sCurImg, sCurW, sCurH, sCurSmooth);
        if (!gPcConfig.vsync)
            SDL_Delay(15);
    }
#if PC_TOUCH
    PcTouchReset();
#endif
    if (!sInBackground)
        Redraw();
    PcAudioPause(sPaused);
    sSuppressInput = 1;
    sNextFrameTime = 0;
    sLastPresentTime = 0;
}

#if PC_TOUCH
/* Testing (--bgtest): the app comes back, or (--bgkill) Android closes it. */
static void BgTestTick(void) {
    SDL_Event ev;
    if (!sBgTestBack || !sPaused || SDL_GetTicks() < sBgTestBack)
        return;
    if (sBgTestKill) {
        PcLog("[pc] test: process killed in the background\n");
        _Exit(0);
    }
    memset(&ev, 0, sizeof(ev));
    ev.type = SDL_APP_DIDENTERFOREGROUND;
    PcLog("[pc] test: app back in front (%d %s)\n", SDL_PushEvent(&ev), SDL_GetError());
    sBgTestBack = 0;
}

/* Runs on Android's thread the moment the app starts leaving the screen,
 * before the drawing surface goes away: stop drawing right now. */
static int BackgroundWatch(void* data, SDL_Event* e) {
    (void)data;
    if (e->type == SDL_APP_WILLENTERBACKGROUND || e->type == SDL_APP_DIDENTERBACKGROUND)
        sInBackground = 1;
    return 0;
}
#endif

static void FrameHook(void) {
    uint16_t held;
    int i;

    PC_ALIVE();
    PollEvents();
#if PC_TOUCH
    if (sSuspendWait > 0 && --sSuspendWait == 0 && sInBackground)
        sPaused = 1; /* the snapshot did not come (a cutscene...): stop anyway */
#endif
    while (sPaused) {
        /* In the background: keep the window alive, run nothing. */
        SDL_Event e;
        if (SDL_WaitEventTimeout(&e, 100)) {
            HandleEvent(&e);
            PollEvents();
        }
        if (!sInBackground)
            Redraw();
#if PC_TOUCH
        BgTestTick();
#endif
        PC_ALIVE(); /* paused on purpose, not stuck */
    }
    if (sMenuRequested) {
        sMenuRequested = 0;
        RunMenu();
    }

    held = ReadKeyboard() | ReadGamepads();
#if PC_TOUCH
    held |= PcTouchHeld();
#endif
    held = FilterDpad(held);
    if (sSuppressInput) {
        /* Keys used to leave the menu must not reach the game. */
        if (held)
            held = 0;
        else
            sSuppressInput = 0;
    }
    for (i = 0; i < sNumPresses; i++)
        if (gPcFrameCount >= sPresses[i].frame && gPcFrameCount < sPresses[i].frame + 4)
            held |= sPresses[i].keys;
    PC_IO16(PC_REG_KEYINPUT) = (uint16_t)(0x03FF & ~held);

    /* New sound for this frame; while fast-forwarding it plays sped up. */
    {
        double speed = sFastForward ? (double)gPcConfig.fastSpeed : sAudioBaseSpeed;
        if (speed != sAudioSpeedSet) {
            sAudioSpeedSet = speed;
            PcAudioSetSpeed(speed);
        }
    }
    PcAudioUpdate(sAudioMuted);

    /* While fast-forwarding, only every Nth frame is shown. */
    ShowFrame();
    if (sCaptureFile && gPcFrameCount == sCaptureFrame)
        CaptureWindow(sCaptureFile);

    if (sDumpEvery && gPcFrameCount % sDumpEvery == 0) {
        char path[1200];
        snprintf(path, sizeof(path), "%s/frame_%05u.bmp", sOutDir, gPcFrameCount);
        PcSaveScreenshot(path);
    }
    PcSaveTick();
    {
        int result = PcStateTakeQuickResult();
#if PC_TOUCH
        if (sSuspending && (result == 1 || result == -1)) {
            sSuspending = 0;
            sSuspendWait = 0;
            if (sInBackground)
                sPaused = 1;
            result = 0; /* silent */
        } else if (sResuming && (result == 2 || result == -2)) {
            char path[1200];
            sResuming = 0;
            FilePath(path, sizeof(path), "suspend");
            remove(path);
            if (result == 2)
                ShowNotice("Continúas donde lo dejaste");
            result = 0;
        }
#endif
    switch (result) {
        case 1: ShowNotice(PC_TOUCH ? "Estado guardado" : "estado guardado (F8 para cargar)"); break;
        case 2: ShowNotice(PC_TOUCH ? "Estado cargado" : "estado cargado"); break;
        case -1: ShowNotice(PC_TOUCH ? "No se pudo guardar el estado" : "no se pudo guardar el estado"); break;
        case -2: ShowNotice(PC_TOUCH ? "No hay un estado guardado que se pueda cargar" : "no hay estado guardado para esta version"); break;
    }
    }
    if (PcTakeRecoveredNotice())
        ShowNotice(sRoot ? "se recuperó de un error (detalles en la carpeta registros)" : "se recupero de un error (detalles en khcom_log.txt)");
    UpdateNotice();
#if PC_TOUCH
    if (sBgTestFrame && gPcFrameCount == sBgTestFrame) {
        /* Testing: what Android sends when the player switches apps. */
        SDL_Event ev;
        memset(&ev, 0, sizeof(ev));
        ev.type = SDL_APP_WILLENTERBACKGROUND;
        SDL_PushEvent(&ev);
        PcLog("[pc] test: app sent to the background at frame %u\n", gPcFrameCount);
        sBgTestFrame = 0;
        sBgTestBack = SDL_GetTicks() + 1500;
    }
#endif
    if (sTestPadAt && gPcFrameCount == sTestPadAt) {
        SDL_VirtualJoystickDesc desc;
        int dev;
        SDL_zero(desc);
        desc.version = SDL_VIRTUAL_JOYSTICK_DESC_VERSION;
        desc.type = SDL_JOYSTICK_TYPE_GAMECONTROLLER;
        desc.naxes = 6;
        desc.nbuttons = 15;
        desc.name = "Mando de prueba";
        dev = SDL_JoystickAttachVirtualEx(&desc);
        PcLog("[pc] test: virtual controller attached (%d)\n", dev);
    }
    if (sTestPadOff && gPcFrameCount == sTestPadOff) {
        SDL_JoystickDetachVirtual(0);
        PcLog("[pc] test: virtual controller detached\n");
    }
    if (sCrashTest && gPcFrameCount == 600) {
        int kind = sCrashTest;
        sCrashTest = 0; /* once: recovery must not crash again */
        if (kind == 1) {
            volatile int* volatile bad = (int*)(uintptr_t)0x12345678; /* not a GBA-style address */
            *bad = 1;
        } else if (kind == 3) {
            SDL_Delay(20000);
        }
        else
            for (;;) {}
    }
    if (sRunSeconds > 0) {
        uint64_t now = SDL_GetPerformanceCounter();
        if (!sStartTime)
            sStartTime = now, sPresentCount = 0;
        else if ((double)(now - sStartTime) / sPerfFreq >= sRunSeconds) {
            PcLog("[pc] %u frames in %.1f s = %.3f fps (game), %.2f pictures shown per second\n", gPcFrameCount,
                  sRunSeconds, gPcFrameCount / ((double)(now - sStartTime) / sPerfFreq),
                  sPresentCount / ((double)(now - sStartTime) / sPerfFreq));
            Quit(0);
        }
    }
    if (sMaxFrames && gPcFrameCount >= sMaxFrames) {
        PcLog("[pc] reached %u frames without crashing\n", gPcFrameCount);
        Quit(0);
    }
    Pace();
}

/* ------------------------------------------------------------------ */

static int DirIsWritable(const char* dir) {
    char path[1200];
    SDL_RWops* rw;
    snprintf(path, sizeof(path), "%s.khcom_write_test", dir);
    rw = SDL_RWFromFile(path, "wb");
    if (!rw)
        return 0;
    SDL_RWclose(rw);
    remove(path);
    return 1;
}

int main(int argc, char** argv) {
    int i;
    char* base;
    char logPath[1200];

#ifdef __ANDROID__
    if (setjmp(sQuitJump))
        return sQuitCode;
    sQuitReady = 1;
#endif
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--frames") && i + 1 < argc)
            sMaxFrames = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--capture-at") && i + 1 < argc) {
            char* colon = strchr(argv[++i], ':');
            if (colon) {
                sCaptureFrame = (uint32_t)strtoul(argv[i], NULL, 0);
                sCaptureFile = colon + 1;
            }
        } else if (!strcmp(argv[i], "--menu"))
            sCaptureMenu = 1;
        else if (!strcmp(argv[i], "--root") && i + 1 < argc)
            sRoot = argv[++i];
        else if (!strcmp(argv[i], "--rom") && i + 1 < argc)
            sRomPath = argv[++i];
        else if (!strcmp(argv[i], "--map") && i + 1 < argc)
            sMapPath = argv[++i];
        else if (!strcmp(argv[i], "--region") && i + 1 < argc)
            sRegion = argv[++i];
        else if (!strcmp(argv[i], "--fast"))
            sTestFast = 1;
        else if (!strcmp(argv[i], "--test-pad") && i + 2 < argc) {
            sTestPadAt = (uint32_t)strtoul(argv[++i], NULL, 0);
            sTestPadOff = (uint32_t)strtoul(argv[++i], NULL, 0);
        }
        else if (!strcmp(argv[i], "--seconds") && i + 1 < argc)
            sRunSeconds = atof(argv[++i]);
        else if (!strcmp(argv[i], "--dump-every") && i + 1 < argc)
            sDumpEvery = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--selftest")) {
            volatile int a = 1234, z = 0, m = -1, mn = (int)0x80000000;
            char msg[128];
            PcInstallDivZeroHandler();
            snprintf(msg, sizeof(msg), "1234/0=%d 1234%%0=%d INT_MIN/-1=%d\n", a / z, a % z, mn / m);
            fputs(msg, stdout);
            return 0;
        } else if (!strcmp(argv[i], "--crashtest"))
            sCrashTest = 1;
#if PC_TOUCH
        else if (!strcmp(argv[i], "--bgtest") && i + 1 < argc)
            sBgTestFrame = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--bgkill"))
            sBgTestKill = 1;
#endif
        else if (!strcmp(argv[i], "--hangtest"))
            sCrashTest = 2;
        else if (!strcmp(argv[i], "--systemwaittest"))
            sCrashTest = 3; /* 20 s inside Windows: must not be reported as a hang */
        else if (!strcmp(argv[i], "--out") && i + 1 < argc)
            sOutDir = argv[++i];
        else if (!strcmp(argv[i], "--press") && i + 1 < argc && sNumPresses < MAX_PRESSES) {
            char* colon = strchr(argv[++i], ':');
            if (colon) {
                sPresses[sNumPresses].frame = (uint32_t)strtoul(argv[i], NULL, 0);
                sPresses[sNumPresses].keys = ParseKeys(colon + 1);
                sNumPresses++;
            }
        }
    }

    PcInstallDivZeroHandler();
    PcInstallFaultRecovery();
    SDL_SetHint(SDL_HINT_WINDOWS_DPI_AWARENESS, "permonitorv2");
    SDL_SetHint(SDL_HINT_WINDOWS_INTRESOURCE_ICON, "1");       /* port/res/khcom.rc */
    SDL_SetHint(SDL_HINT_WINDOWS_INTRESOURCE_ICON_SMALL, "1");
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
#ifdef __ANDROID__
    SDL_SetHint(SDL_HINT_ANDROID_BLOCK_ON_PAUSE, "0");     /* the pause is handled in PollEvents */
    SDL_SetHint(SDL_HINT_ANDROID_TRAP_BACK_BUTTON, "1");   /* Back opens the menu */
    SDL_SetHint(SDL_HINT_ORIENTATIONS, "LandscapeLeft LandscapeRight");
    SDL_SetHint(SDL_HINT_MOUSE_TOUCH_EVENTS, "0");
    SDL_SetHint(SDL_HINT_TOUCH_MOUSE_EVENTS, "1");         /* taps work the menu like clicks */
#elif defined(PC_FORCE_TOUCH)
    SDL_SetHint(SDL_HINT_MOUSE_TOUCH_EVENTS, "1");         /* the mouse plays the finger */
#endif
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) != 0) {
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }
#if PC_TOUCH
    SDL_AddEventWatch(BackgroundWatch, NULL);
#endif

    base = sRoot ? SDL_strdup(sRoot) : SDL_GetBasePath();
    if (base) {
        snprintf(sBasePath, sizeof(sBasePath), "%s", base);
        SDL_free(base);
    }
    if (!DirIsWritable(sBasePath)) {
        /* e.g. installed under Program Files: use %APPDATA%\KHCoM\ instead. */
        char* pref = SDL_GetPrefPath(NULL, sRoot ? "ReinoDeCorazones" : "KHCoM");
        if (pref) {
            snprintf(sBasePath, sizeof(sBasePath), "%s", pref);
            SDL_free(pref);
        }
    }
    {
        size_t n = strlen(sBasePath);
        if (n && sBasePath[n - 1] != '/' && sBasePath[n - 1] != '\\' && n + 1 < sizeof(sBasePath))
            strcat(sBasePath, "/");
    }
    if (sRoot)
        MakeDirs();
    FilePath(logPath, sizeof(logPath), "log");
    sLogFile = fopen(logPath, "w");
    PcLog("[pc] Reino de Corazones - native PC port of Kingdom Hearts: Chain of Memories (%s)\n", sRegion);
    PcLog("[pc] data folder: %s\n", sBasePath);
#ifdef _WIN32
    if (sRoot) {
        static char hint[96];
        snprintf(hint, sizeof(hint), "la carpeta «registros» (%s.txt)", sRegion);
        gPcLogHint = hint;
    }
#endif
    if (sRomPath || PcRomDataNeeded()) {
        const char* err;
        if (!sRomPath || !sMapPath) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Reino de Corazones",
                                     "Para jugar, abre ReinoDeCorazones.exe (en la carpeta de arriba).\n"
                                     "Ahí eliges tu copia del juego y desde ahí se inicia.", NULL);
            return 2;
        }
#ifdef PC_SPLIT_CORE
        err = RdcHostLoad(sRomPath, sMapPath); /* the 32-bit core, rebuilt from the ROM */
#else
        err = PcRomDataLoad(sRomPath, sMapPath);
#endif
        if (err) {
            PcLog("[pc] %s\n", err);
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Reino de Corazones", err, NULL);
            return 3;
        }
    }
    {
        char path[1200];
        FilePath(path, sizeof(path), "ini");
        PcConfigLoad(path);
        FilePath(path, sizeof(path), "sav");
        PcSaveLoad(path);
    }
    sIntegerScale = gPcConfig.integerScale;
#ifdef __ANDROID__
    gPcConfig.fullscreen = 1; /* a phone app always fills the screen */
    gPcConfig.vsync = 1;
#endif
    gPcSkipMovies = gPcConfig.skipMovies;

    {
        int ww, wh;
        WindowSizeFor(gPcConfig.scale, &ww, &wh);
        if (SDL_getenv("RDC_TEST_WINDOW")) /* testing: a phone-sized window */
            sscanf(SDL_getenv("RDC_TEST_WINDOW"), "%dx%d", &ww, &wh);
        sWindow = SDL_CreateWindow("Reino de Corazones", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ww, wh,
                                   SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI |
                                       (gPcConfig.fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0));
    }
    if (!sWindow)
        Fatal(SDL_GetError());
#ifdef _WIN32
    {
        SDL_SysWMinfo wm;
        SDL_VERSION(&wm.version);
        PcWinDiagInit(SDL_GetWindowWMInfo(sWindow, &wm) ? (void*)wm.info.win.window : NULL);
    }
#endif
    /* Direct3D 11 first: it changes window size and vsync without resetting
     * the device (Direct3D 9 resets it, which some drivers handle badly). */
#ifdef __ANDROID__
    SDL_SetHint(SDL_HINT_RENDER_DRIVER,
                gPcConfig.renderer[0] && SDL_strcasecmp(gPcConfig.renderer, "auto") ? gPcConfig.renderer : "opengles2");
#else
    SDL_SetHint(SDL_HINT_RENDER_DRIVER,
                gPcConfig.renderer[0] && SDL_strcasecmp(gPcConfig.renderer, "auto") ? gPcConfig.renderer : "direct3d11");
#endif
    CreateRenderer();
    sAppliedScale = gPcConfig.scale;
    {
        SDL_RendererInfo ri;
        if (SDL_GetRendererInfo(sRenderer, &ri) == 0)
            PcLog("[pc] video: %s renderer\n", ri.name);
    }
    sPerfFreq = SDL_GetPerformanceFrequency();

    PcApuReset();
    UpdatePacing();
    if (gPcConfig.audioEnabled && !sMaxFrames)
        PcAudioOpen(gPcConfig.volume);
    else
        PcLog("[pc] audio: disabled\n");

#if PC_TOUCH
    {
        /* The app was closed by Android while in the background: continue. */
        char path[1200];
        FILE* f;
        FilePath(path, sizeof(path), "suspend");
        f = fopen(path, "rb");
        if (f) {
            fclose(f);
            PcLog("[pc] continuing from the background snapshot %s\n", path);
            PcStateRequestQuickLoad(path);
            sResuming = 1;
        }
    }
#endif
#ifdef PC_SPLIT_CORE
    RdcHostRun(FrameHook); /* sets the hooks, snapshots and runs AgbMain inside the core */
    Fatal("El juego se detuvo por un error (detalles en la carpeta registros).");
    return 1;
#else
    PC_IO16(PC_REG_KEYINPUT) = 0x03FF;
    PcResetNullPage();
    gPcFrameHook = FrameHook;
    gPcScanlineHook = PcRenderScanline;

    PcSaveGameState();
    PcStateInit();
    if (setjmp(sResetJump) == 1)
        PcRestoreGameState();
    AgbMain();
    Fatal("AgbMain returned unexpectedly");
    return 1;
#endif
}
