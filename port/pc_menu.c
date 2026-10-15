/*
 * pc_menu.c
 * The in-game menu (Esc): pauses the game and changes the picture and sound
 * settings with a live preview. Same look as the launcher; the text is
 * pre-rendered (port/launcher/make_menu_assets.py -> port/res/menu_atlas.*).
 *
 * Controls: arrows / D-pad to choose and change, Enter / A to accept,
 * Esc / B to go back to the game. The mouse works too.
 */
#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include "pc_config.h"
#include "pc_menu.h"
#include "pc_platform.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#define STBI_ONLY_JPEG
#define STBI_NO_STDIO
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#include "../launcher/stb_image.h"
#pragma GCC diagnostic pop
#include "../res/menu_atlas.h"

#ifdef _WIN32
#include <windows.h>
#endif

#define MW 960 /* menu coordinates: 3:2 like the game */
#define MH 640

enum { ROW_CONTINUE, ROW_FPS, ROW_SCALE, ROW_FILTER, ROW_COLORS, ROW_GHOST, ROW_FULL, ROW_VSYNC, ROW_VOLUME,
       ROW_SAVE, ROW_LOAD, ROW_QUIT, ROW_TOPACITY, ROW_TSIZE, ROW_VIBRATION, ROW_ASPECT, ROW_FFSPEED, ROW_STICK };

/* The rows shown, top to bottom. A phone has no window to size and its
 * screen always syncs, so those rows give way to the touch controls. */
#if defined(__ANDROID__) || defined(PC_FORCE_TOUCH)
#define ROW_COUNT 15
static const int kRows[ROW_COUNT] = {ROW_CONTINUE, ROW_ASPECT, ROW_FPS, ROW_FILTER, ROW_COLORS, ROW_GHOST,
                                     ROW_STICK, ROW_TOPACITY, ROW_TSIZE, ROW_VIBRATION, ROW_FFSPEED, ROW_VOLUME,
                                     ROW_SAVE, ROW_LOAD, ROW_QUIT};
#define TOUCH_UI 1
#else
#define ROW_COUNT 12
static const int kRows[ROW_COUNT] = {ROW_CONTINUE, ROW_FPS, ROW_SCALE, ROW_FILTER, ROW_COLORS, ROW_GHOST,
                                     ROW_FULL, ROW_VSYNC, ROW_VOLUME, ROW_SAVE, ROW_LOAD, ROW_QUIT};
#define TOUCH_UI 0
#endif

static SDL_Texture* sAtlas;
static int sOpen, sSel;
static int sMonitorHz = 60;
static int sLaunched; /* started from the launcher: "Salir al menú principal" */
static const int kRowY0 = 128;
#if defined(__ANDROID__) || defined(PC_FORCE_TOUCH)
static const int kRowH = 28; /* more rows on phones */
#else
static const int kRowH = 34;
#endif

static SDL_Texture* LoadAtlas(SDL_Renderer* r) {
    const unsigned char* bytes = NULL;
    int len = 0, w, h, n;
    unsigned char* px;
    SDL_Surface* s;
    SDL_Texture* t;
    void* fileData = NULL;
#ifdef _WIN32
    HRSRC res = FindResourceA(NULL, MAKEINTRESOURCEA(201), MAKEINTRESOURCEA(10) /* RT_RCDATA */);
    if (res) {
        HGLOBAL g = LoadResource(NULL, res);
        bytes = (const unsigned char*)LockResource(g);
        len = (int)SizeofResource(NULL, res);
    }
#endif
#ifdef __ANDROID__
    {
        size_t sz;
        fileData = SDL_LoadFile("menu_atlas.png", &sz); /* the APK's assets */
        bytes = (const unsigned char*)fileData;
        len = (int)sz;
    }
#endif
    if (!bytes) {
        size_t sz;
        fileData = SDL_LoadFile("port/res/menu_atlas.png", &sz);
        bytes = (const unsigned char*)fileData;
        len = (int)sz;
    }
    if (!bytes)
        return NULL;
    px = stbi_load_from_memory(bytes, len, &w, &h, &n, 4);
    SDL_free(fileData);
    if (!px)
        return NULL;
    s = SDL_CreateRGBSurfaceWithFormatFrom(px, w, h, 32, w * 4, SDL_PIXELFORMAT_RGBA32);
    t = SDL_CreateTextureFromSurface(r, s);
    SDL_FreeSurface(s);
    stbi_image_free(px);
    if (t) {
        SDL_SetTextureBlendMode(t, SDL_BLENDMODE_BLEND);
        SDL_SetTextureScaleMode(t, SDL_ScaleModeLinear);
    }
    return t;
}

int PcMenuInit(SDL_Renderer* r, int launched) {
    sLaunched = launched;
    sAtlas = LoadAtlas(r);
    if (!sAtlas)
        PcLog("[pc] menu: artwork not found, the Esc menu is unavailable\n");
    return sAtlas != NULL;
}

void PcMenuSetMonitorHz(int hz) { sMonitorHz = hz; }
int PcMenuIsOpen(void) { return sOpen; }

void PcMenuOpen(void) {
    if (!sAtlas)
        return;
    sOpen = 1;
    sSel = ROW_CONTINUE;
}

void PcMenuClose(void) { sOpen = 0; }

/* A picture or touch-control setting is selected: the panel turns see-through
 * so the change can be judged on the game behind it. */
int PcMenuPreviewing(void) {
    int row = kRows[sSel];
    return sOpen && ((row >= ROW_FPS && row <= ROW_GHOST) || row == ROW_TOPACITY || row == ROW_TSIZE || row == ROW_STICK ||
                     row == ROW_ASPECT);
}

/* ------------------------------------------------------------------ */

static void SaveSetting(int row) {
    char v[16];
    switch (row) {
        case ROW_FPS: snprintf(v, sizeof(v), "%d", gPcConfig.fps); PcConfigSet("video", "fps", v); break;
        case ROW_SCALE: snprintf(v, sizeof(v), "%d", gPcConfig.scale); PcConfigSet("video", "scale", v); break;
        case ROW_FILTER: PcConfigSet("video", "filter", kFilterNames[gPcConfig.filter]); break;
        case ROW_COLORS: PcConfigSet("video", "gba_colors", gPcConfig.gbaColors ? "1" : "0"); break;
        case ROW_GHOST: PcConfigSet("video", "lcd_ghosting", gPcConfig.ghosting ? "1" : "0"); break;
        case ROW_FULL: PcConfigSet("video", "fullscreen", gPcConfig.fullscreen ? "1" : "0"); break;
        case ROW_VSYNC: PcConfigSet("video", "vsync", gPcConfig.vsync ? "1" : "0"); break;
        case ROW_VOLUME: snprintf(v, sizeof(v), "%d", gPcConfig.volume); PcConfigSet("audio", "volume", v); break;
        case ROW_TOPACITY: snprintf(v, sizeof(v), "%d", gPcConfig.touchOpacity); PcConfigSet("touch", "opacity", v); break;
        case ROW_TSIZE: snprintf(v, sizeof(v), "%d", gPcConfig.touchSize); PcConfigSet("touch", "size", v); break;
        case ROW_VIBRATION: PcConfigSet("touch", "vibration", gPcConfig.vibration ? "1" : "0"); break;
        case ROW_ASPECT: PcConfigSet("screen", "aspect", kAspectNames[gPcConfig.aspect]); break;
        case ROW_FFSPEED: snprintf(v, sizeof(v), "%d", gPcConfig.fastSpeed); PcConfigSet("game", "fast_speed", v); break;
        case ROW_STICK: PcConfigSet("touch", "stick", kStickNames[gPcConfig.stickMode]); break;
    }
}

/* Changes the value of a row by one step; returns what the game must redo. */
static int Change(int row, int dir) {
    switch (row) {
        case ROW_FPS: {
            static const int fps[3] = {30, 60, 120};
            int i = gPcConfig.fps == 30 ? 0 : gPcConfig.fps == 120 ? 2 : 1;
            i = (i + dir + 3) % 3;
            gPcConfig.fps = fps[i];
            break;
        }
        case ROW_SCALE: gPcConfig.scale = (gPcConfig.scale - 1 + dir + 5) % 5 + 1; break;
        case ROW_FILTER: gPcConfig.filter = (gPcConfig.filter + dir + PC_FILTER_COUNT) % PC_FILTER_COUNT; break;
        case ROW_COLORS: gPcConfig.gbaColors = !gPcConfig.gbaColors; break;
        case ROW_GHOST: gPcConfig.ghosting = !gPcConfig.ghosting; break;
        case ROW_FULL: gPcConfig.fullscreen = !gPcConfig.fullscreen; break;
        case ROW_VSYNC: gPcConfig.vsync = !gPcConfig.vsync; break;
        case ROW_VOLUME: {
            int v = gPcConfig.volume / 10 * 10 + dir * 10;
            gPcConfig.volume = v < 0 ? 0 : v > 100 ? 100 : v;
            break;
        }
        case ROW_TOPACITY: {
            int v = (gPcConfig.touchOpacity + 5) / 10 * 10 + dir * 10;
            gPcConfig.touchOpacity = v < 0 ? 0 : v > 100 ? 100 : v;
            break;
        }
        case ROW_TSIZE: gPcConfig.touchSize = (gPcConfig.touchSize + dir + 3) % 3; break;
        case ROW_VIBRATION: gPcConfig.vibration = !gPcConfig.vibration; break;
        case ROW_ASPECT: gPcConfig.aspect = (gPcConfig.aspect + dir + 4) % 4; break;
        case ROW_FFSPEED: gPcConfig.fastSpeed = (gPcConfig.fastSpeed - 2 + dir + 3) % 3 + 2; break;
        case ROW_STICK: gPcConfig.stickMode = (gPcConfig.stickMode + dir + 3) % 3; break;
        default: return PC_MENU_NONE;
    }
    SaveSetting(row);
    return PC_MENU_CHANGED;
}

static int Accept(int row) {
    switch (row) {
        case ROW_CONTINUE: sOpen = 0; return PC_MENU_CLOSED;
        case ROW_SAVE: sOpen = 0; return PC_MENU_SAVE_STATE;
        case ROW_LOAD: sOpen = 0; return PC_MENU_LOAD_STATE;
        case ROW_QUIT: return PC_MENU_QUIT;
        default: return Change(row, 1);
    }
}

static int ValueSprite(int row);

static void ToMenuCoords(SDL_Renderer* r, int wx, int wy, int* mx, int* my) {
    /* Window pixels -> menu coordinates (the menu fills the window keeping 3:2). */
    int ow, oh;
    float sc, ox, oy;
    SDL_GetRendererOutputSize(r, &ow, &oh);
    sc = (float)ow / MW < (float)oh / MH ? (float)ow / MW : (float)oh / MH;
    ox = (ow - MW * sc) / 2;
    oy = (oh - MH * sc) / 2;
    {
        /* Mouse events come in window coordinates; scale for high-DPI. */
        SDL_Window* w = SDL_RenderGetWindow(r);
        int ww, wh;
        SDL_GetWindowSize(w, &ww, &wh);
        if (ww > 0 && wh > 0) {
            wx = wx * ow / ww;
            wy = wy * oh / wh;
        }
    }
    *mx = (int)((wx - ox) / sc);
    *my = (int)((wy - oy) / sc);
}

static int RowAt(int mx, int my) {
    int row = (my - kRowY0) / kRowH;
    if (my < kRowY0 || row < 0 || row >= ROW_COUNT || mx < 140 || mx > 820)
        return -1;
    return row;
}

int PcMenuHandleEvent(SDL_Renderer* r, const SDL_Event* e) {
    switch (e->type) {
        case SDL_KEYDOWN:
            switch (e->key.keysym.sym) {
                case SDLK_UP: sSel = (sSel + ROW_COUNT - 1) % ROW_COUNT; break;
                case SDLK_DOWN: case SDLK_TAB: sSel = (sSel + 1) % ROW_COUNT; break;
                case SDLK_LEFT: return Change(kRows[sSel], -1);
                case SDLK_RIGHT: return Change(kRows[sSel], 1);
                case SDLK_RETURN: case SDLK_KP_ENTER: case SDLK_SPACE: return Accept(kRows[sSel]);
                case SDLK_ESCAPE: case SDLK_BACKSPACE: case SDLK_AC_BACK: sOpen = 0; return PC_MENU_CLOSED;
            }
            break;
        case SDL_CONTROLLERBUTTONDOWN:
            switch (e->cbutton.button) {
                case SDL_CONTROLLER_BUTTON_DPAD_UP: sSel = (sSel + ROW_COUNT - 1) % ROW_COUNT; break;
                case SDL_CONTROLLER_BUTTON_DPAD_DOWN: sSel = (sSel + 1) % ROW_COUNT; break;
                case SDL_CONTROLLER_BUTTON_DPAD_LEFT: return Change(kRows[sSel], -1);
                case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: return Change(kRows[sSel], 1);
                case SDL_CONTROLLER_BUTTON_A: return Accept(kRows[sSel]);
                case SDL_CONTROLLER_BUTTON_B: case SDL_CONTROLLER_BUTTON_GUIDE: case SDL_CONTROLLER_BUTTON_BACK:
                    sOpen = 0;
                    return PC_MENU_CLOSED;
            }
            break;
        case SDL_MOUSEMOTION: {
            int mx, my, row;
            ToMenuCoords(r, e->motion.x, e->motion.y, &mx, &my);
            row = RowAt(mx, my);
            if (row >= 0)
                sSel = row;
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            int mx, my, row;
            if (e->button.button != SDL_BUTTON_LEFT)
                break;
            ToMenuCoords(r, e->button.x, e->button.y, &mx, &my);
            row = RowAt(mx, my);
            if (row < 0)
                break;
            sSel = row;
            if (ValueSprite(kRows[row]) >= 0)
                return Change(kRows[row], mx < 560 ? -1 : 1); /* left / right half of the value */
            return Accept(kRows[row]);
        }
    }
    return PC_MENU_NONE;
}

/* ------------------------------------------------------------------ */

static void Sprite(SDL_Renderer* r, int id, int x, int y, Uint8 cr, Uint8 cg, Uint8 cb, Uint8 a) {
    SDL_Rect src = kMenuSprites[id], dst = {x, y, src.w, src.h};
    SDL_SetTextureColorMod(sAtlas, cr, cg, cb);
    SDL_SetTextureAlphaMod(sAtlas, a);
    SDL_RenderCopy(r, sAtlas, &src, &dst);
}

static void Centered(SDL_Renderer* r, int id, int cx, int y, Uint8 cr, Uint8 cg, Uint8 cb, Uint8 a) {
    Sprite(r, id, cx - kMenuSprites[id].w / 2, y, cr, cg, cb, a);
}

static int ValueSprite(int row) {
    switch (row) {
        case ROW_FPS: return gPcConfig.fps == 30 ? V_30 : gPcConfig.fps == 120 ? V_120 : V_60;
        case ROW_SCALE: return V_S1 + gPcConfig.scale - 1;
        case ROW_FILTER: return V_F0 + gPcConfig.filter;
        case ROW_COLORS: return gPcConfig.gbaColors ? V_YES : V_NO;
        case ROW_GHOST: return gPcConfig.ghosting ? V_YES : V_NO;
        case ROW_FULL: return gPcConfig.fullscreen ? V_YES : V_NO;
        case ROW_VSYNC: return gPcConfig.vsync ? V_YES : V_NO;
        case ROW_VOLUME: return V_VOL0 + gPcConfig.volume / 10;
        case ROW_TOPACITY: return V_VOL0 + (gPcConfig.touchOpacity + 5) / 10;
        case ROW_TSIZE: return V_TSMALL + gPcConfig.touchSize;
        case ROW_VIBRATION: return gPcConfig.vibration ? V_YES : V_NO;
        case ROW_ASPECT: return V_ASPECT0 + gPcConfig.aspect;
        case ROW_FFSPEED: return V_FF2 + gPcConfig.fastSpeed - 2;
        case ROW_STICK: return V_STICK0 + gPcConfig.stickMode;
    }
    return -1;
}

static int HelpSprite(int row) {
#if TOUCH_UI
    switch (row) {
        case ROW_FPS: return gPcConfig.fps == 120 && sMonitorHz < 100 ? H_FPS_60HZ_T : H_FPS_T;
        case ROW_VOLUME: return H_VOLUME_T;
        case ROW_SAVE: return H_SAVE_T;
        case ROW_LOAD: return H_LOAD_T;
        case ROW_QUIT: return H_QUIT_T;
        case ROW_TOPACITY: return H_TOPACITY;
        case ROW_TSIZE: return H_TSIZE;
        case ROW_VIBRATION: return H_VIBRATION;
        case ROW_ASPECT: return H_ASPECT0 + gPcConfig.aspect;
        case ROW_FFSPEED: return H_FFSPEED;
        case ROW_STICK: return H_STICK0 + gPcConfig.stickMode;
    }
#endif
    switch (row) {
        case ROW_CONTINUE: return H_CONTINUE;
        case ROW_FPS: return gPcConfig.fps == 120 && sMonitorHz < 100 ? H_FPS_60HZ : H_FPS;
        case ROW_SCALE: return H_SCALE;
        case ROW_FILTER: return H_F0 + gPcConfig.filter;
        case ROW_COLORS: return H_COLORS;
        case ROW_GHOST: return H_GHOST;
        case ROW_FULL: return H_FULL;
        case ROW_VSYNC: return H_VSYNC;
        case ROW_VOLUME: return H_VOLUME;
        case ROW_SAVE: return H_SAVE;
        case ROW_LOAD: return H_LOAD;
        default: return sLaunched ? H_QUIT : H_QUIT_ALONE;
    }
}

void PcMenuDraw(SDL_Renderer* r) {
    static const int labels[] = {L_CONTINUE, L_FPS, L_SCALE, L_FILTER, L_COLORS, L_GHOST, L_FULL, L_VSYNC,
                                 L_VOLUME, L_SAVE, L_LOAD, L_QUIT, L_TOPACITY, L_TSIZE, L_VIBRATION, L_ASPECT, L_FFSPEED, L_STICK};
    float t = (SDL_GetTicks() % 600000u) / 1000.0f; /* small: float keeps its precision */
    int ow, oh, i;
    SDL_Rect all;

    if (!sOpen || !sAtlas)
        return;
    /* Dim the game, then draw in menu coordinates. */
    SDL_RenderSetLogicalSize(r, 0, 0);
    SDL_RenderSetIntegerScale(r, SDL_FALSE);
    SDL_GetRendererOutputSize(r, &ow, &oh);
    all.x = 0; all.y = 0; all.w = ow; all.h = oh;
    SDL_SetRenderDrawBlendMode(r, SDL_BLENDMODE_BLEND);
    {
        /* While a picture setting is selected the panel turns see-through,
         * so the change can be judged on the game behind it. */
        int preview = PcMenuPreviewing();
        SDL_SetRenderDrawColor(r, 4, 4, 16, preview ? 60 : 120);
        SDL_RenderFillRect(r, &all);
        SDL_RenderSetLogicalSize(r, MW, MH);
        Centered(r, G_MPANEL, MW / 2, 22, 255, 255, 255, preview ? 196 : 255);
    }
    Centered(r, M_TITLE, MW / 2, 30, 255, 255, 255, 255);
    Centered(r, G_MORNAMENT, MW / 2, 100, 255, 255, 255, 230);
    for (i = 0; i < ROW_COUNT; i++) {
        int y = kRowY0 + i * kRowH;
        int sel = i == sSel;
        int row = kRows[i];
        int v = ValueSprite(row);
        int ly = y + (kRowH - kMenuSprites[labels[row]].h) / 2;
        if (sel) {
            Uint8 a = (Uint8)(200 + 55 * SDL_sinf(t * 3.0f));
            Centered(r, G_ROW, MW / 2, y, 255, 255, 255, a);
        }
        if (row == ROW_QUIT)
            Sprite(r, sLaunched ? L_QUIT : L_QUIT_ALONE, 150, ly, sel ? 255 : 226, sel ? 238 : 228, sel ? 196 : 255, 255);
        else if (v < 0)
            Sprite(r, labels[row], 150, ly, sel ? 255 : 226, sel ? 238 : 228, sel ? 196 : 255, 255);
        else {
            int vy = y + (kRowH - kMenuSprites[v].h) / 2;
            Sprite(r, labels[row], 150, ly, sel ? 255 : 200, sel ? 238 : 202, sel ? 196 : 235, 255);
            Centered(r, v, 650, vy, sel ? 255 : 236, sel ? 244 : 232, sel ? 214 : 255, 255);
            if (sel || TOUCH_UI) {
                Sprite(r, G_LEFT, 520, y + (kRowH - 22) / 2, 236, 200, 120, 255);
                Sprite(r, G_RIGHT, 758, y + (kRowH - 22) / 2, 236, 200, 120, 255);
            }
        }
    }
    {
        int help = HelpSprite(kRows[sSel]);
        Centered(r, help, MW / 2, kRowY0 + ROW_COUNT * kRowH + 12, 205, 200, 240, 255);
    }
    Centered(r, TOUCH_UI ? M_TOUCH : M_KEYS, MW / 2, MH - 42, 160, 156, 200, 255);
    /* Back to window pixels: SDL converts mouse and touch positions with the
     * logical size in force, and ToMenuCoords expects window pixels. */
    SDL_RenderSetLogicalSize(r, 0, 0);
}
