/*
 * launcher.c - "Reino de Corazones"
 *
 * The program the player opens. On the first run it asks for the player's
 * own copy of the game (a .gba file: file dialog or drag and drop), checks it
 * by SHA-1 (USA B8CE or Europe B8CP), and keeps a copy in rom/. Then it shows
 * the main menu and starts the native engine for that version:
 *
 *   ReinoDeCorazones.exe        this launcher
 *   motor/rdc-usa.exe + .map    engine for the USA version (no game data inside)
 *   motor/rdc-eur.exe + .map    engine for the European version
 *   rom/                        the player's verified copies
 *   partidas/ config/ capturas/ registros/
 *
 * The engines carry none of the game's data: they rebuild it at start-up
 * from the ROM (port/pc_romdata.c). All artwork here is original.
 *
 * Testing options: --capture FILE.bmp [--frames N] [--select FILE.gba]
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include "../pc_sha1.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#define STBI_NO_STDIO
#include "stb_image.h"
#include "assets/atlas.h"

#ifdef _WIN32
#include <windows.h>
#include <commdlg.h>
#include <SDL_syswm.h>
#include <shellapi.h>
#endif

#define W 960
#define H 600

enum { REGION_EUR, REGION_USA, REGION_COUNT };
static const char* const kRegionId[REGION_COUNT] = {"eur", "usa"};
static const char* const kRegionSha[REGION_COUNT] = {
    "8db73586cdb11b3795907edebf43228dbcd3e6b2", /* Europe (B8CP) */
    "10729bd884f8fdca7a310b6d606c52e46657aa48", /* USA (B8CE) */
};
static const char* const kJapanSha = "59ec0a0a4ccd1e6acb3bbd7bfb21d63988958cfa";

static SDL_Window* sWin;
static SDL_Renderer* sRen;
static SDL_Texture* sBg;
static SDL_Texture* sAtlas;
static char sProgDir[1024];  /* where the launcher lives (motor/ is here) */
static char sDataDir[1024];  /* rom/, partidas/... (AppData if read-only) */
static int sInstalled[REGION_COUNT];
static int sLastRegion = REGION_EUR;

/* Toast message */
static int sToast = -1;
static Uint32 sToastUntil;
static int sToastGood;

/* Menu */
typedef struct { int label, sub, action, region; } Button;
enum { ACT_FIND, ACT_PLAY, ACT_FOLDER, ACT_EXIT };
static Button sButtons[6];
static int sNumButtons, sSel;
static SDL_Rect sButtonRects[6];

static Uint32 sStartTicks;
static const char* sExtraArgs = ""; /* testing: appended to the engine's command line */
static float sFade = 0;

/* ------------------------------------------------------------------ */
/* Files and folders                                                    */
/* ------------------------------------------------------------------ */

static void JoinPath(char* out, size_t n, const char* a, const char* b) {
    snprintf(out, n, "%s%s", a, b);
}

static void MakeDir(const char* path) {
#ifdef _WIN32
    wchar_t w[1024];
    MultiByteToWideChar(CP_UTF8, 0, path, -1, w, 1024);
    CreateDirectoryW(w, NULL);
#else
    char cmd[1200];
    snprintf(cmd, sizeof(cmd), "mkdir -p '%s'", path);
    if (system(cmd)) {
    }
#endif
}

static int FileExists(const char* path) {
    SDL_RWops* rw = SDL_RWFromFile(path, "rb");
    if (!rw)
        return 0;
    SDL_RWclose(rw);
    return 1;
}

static int DirWritable(const char* dir) {
    char p[1100];
    SDL_RWops* rw;
    JoinPath(p, sizeof(p), dir, ".rdc_write_test");
    rw = SDL_RWFromFile(p, "wb");
    if (!rw)
        return 0;
    SDL_RWclose(rw);
    remove(p);
    return 1;
}

static void RomPath(char* out, size_t n, int region) {
    snprintf(out, n, "%srom%c%s.gba", sDataDir, '/', kRegionId[region]);
}

static int RegionOfData(const unsigned char* data, size_t size, int* japanese);

/* Copies dropped straight into rom/ under any name are recognised and renamed. */
static void AdoptLooseRoms(void) {
#ifdef _WIN32
    char pattern[1100];
    wchar_t wpat[1100];
    WIN32_FIND_DATAW fd;
    HANDLE h;
    snprintf(pattern, sizeof(pattern), "%srom\\*.gba", sDataDir);
    MultiByteToWideChar(CP_UTF8, 0, pattern, -1, wpat, 1100);
    h = FindFirstFileW(wpat, &fd);
    if (h == INVALID_HANDLE_VALUE)
        return;
    do {
        char name[600], full[1800], dst[1100];
        size_t sz;
        void* data;
        int region, jp;
        WideCharToMultiByte(CP_UTF8, 0, fd.cFileName, -1, name, sizeof(name), NULL, NULL);
        if (!SDL_strcasecmp(name, "usa.gba") || !SDL_strcasecmp(name, "eur.gba"))
            continue;
        snprintf(full, sizeof(full), "%srom/%s", sDataDir, name);
        data = SDL_LoadFile(full, &sz);
        if (!data)
            continue;
        region = RegionOfData((const unsigned char*)data, sz, &jp);
        SDL_free(data);
        if (region < 0)
            continue;
        RomPath(dst, sizeof(dst), region);
        if (!FileExists(dst)) {
            wchar_t wsrc[1800], wdst[1100];
            MultiByteToWideChar(CP_UTF8, 0, full, -1, wsrc, 1800);
            MultiByteToWideChar(CP_UTF8, 0, dst, -1, wdst, 1100);
            MoveFileW(wsrc, wdst);
        }
    } while (FindNextFileW(h, &fd));
    FindClose(h);
#endif
}

static void ScanInstalled(void) {
    int r;
    for (r = 0; r < REGION_COUNT; r++) {
        char p[1100];
        RomPath(p, sizeof(p), r);
        sInstalled[r] = FileExists(p);
    }
}

static void LoadSettings(void) {
    char p[1100];
    SDL_RWops* rw;
    snprintf(p, sizeof(p), "%sconfig/lanzador.ini", sDataDir);
    rw = SDL_RWFromFile(p, "rb");
    if (rw) {
        char buf[256] = {0};
        SDL_RWread(rw, buf, 1, sizeof(buf) - 1);
        SDL_RWclose(rw);
        if (strstr(buf, "ultima=usa"))
            sLastRegion = REGION_USA;
    }
}

static void SaveSettings(void) {
    char p[1100];
    SDL_RWops* rw;
    snprintf(p, sizeof(p), "%sconfig/lanzador.ini", sDataDir);
    rw = SDL_RWFromFile(p, "wb");
    if (rw) {
        const char* s = sLastRegion == REGION_USA ? "[lanzador]\r\nultima=usa\r\n" : "[lanzador]\r\nultima=eur\r\n";
        SDL_RWwrite(rw, s, 1, strlen(s));
        SDL_RWclose(rw);
    }
}

/* A save from the earlier single-version build (khcom.sav next to the
 * program) becomes the USA save. */
static void MigrateOldSave(void) {
    char oldp[1100], newp[1100];
    SDL_RWops *in, *out;
    snprintf(oldp, sizeof(oldp), "%skhcom.sav", sProgDir);
    snprintf(newp, sizeof(newp), "%spartidas/usa.sav", sDataDir);
    if (!FileExists(oldp) || FileExists(newp))
        return;
    in = SDL_RWFromFile(oldp, "rb");
    out = SDL_RWFromFile(newp, "wb");
    if (in && out) {
        char buf[4096];
        size_t n;
        while ((n = SDL_RWread(in, buf, 1, sizeof(buf))) > 0)
            SDL_RWwrite(out, buf, 1, n);
    }
    if (in) SDL_RWclose(in);
    if (out) SDL_RWclose(out);
}

/* ------------------------------------------------------------------ */
/* Checking the player's ROM                                            */
/* ------------------------------------------------------------------ */

static void ShowToast(int msg, int good) {
    sToast = msg;
    sToastGood = good;
    sToastUntil = SDL_GetTicks() + 4500;
}

static void BuildMenu(void);
static void Render(void);

static void AcceptRom(const char* path) {
    SDL_RWops* rw = SDL_RWFromFile(path, "rb");
    Sint64 size;
    unsigned char* data;
    int region = -1;

    if (!rw) {
        ShowToast(M_READ_ERR, 0);
        return;
    }
    size = SDL_RWsize(rw);
    if (size < 0x200 || size > 64 * 1024 * 1024) {
        SDL_RWclose(rw);
        ShowToast(M_NOT_GBA, 0);
        return;
    }
    data = (unsigned char*)malloc((size_t)size);
    if (!data || SDL_RWread(rw, data, 1, (size_t)size) != (size_t)size) {
        SDL_RWclose(rw);
        free(data);
        ShowToast(M_READ_ERR, 0);
        return;
    }
    SDL_RWclose(rw);
    if (!memcmp(data, "PK\3\4", 4) || !memcmp(data, "7z\xBC\xAF", 4) || !memcmp(data, "Rar!", 4)) {
        free(data);
        ShowToast(M_ZIP, 0);
        return;
    }
    if (data[0xB2] != 0x96) { /* fixed byte of every GBA cartridge header */
        free(data);
        ShowToast(M_NOT_GBA, 0);
        return;
    }
    sToast = M_CHECKING; /* one frame of feedback while hashing */
    sToastGood = 1;
    sToastUntil = SDL_GetTicks() + 1000;
    Render();
    {
        int jp = 0;
        region = RegionOfData(data, (size_t)size, &jp);
        if (region < 0) {
            free(data);
            ShowToast(jp ? M_BAD_JP : M_BAD, 0);
            return;
        }
    }
    if (sInstalled[region]) {
        free(data);
        ShowToast(M_ALREADY, 1);
    } else {
        char dst[1100];
        SDL_RWops* out;
        RomPath(dst, sizeof(dst), region);
        out = SDL_RWFromFile(dst, "wb");
        if (!out || SDL_RWwrite(out, data, 1, (size_t)size) != (size_t)size) {
            if (out)
                SDL_RWclose(out);
            free(data);
            ShowToast(M_COPY_ERR, 0);
            return;
        }
        SDL_RWclose(out);
        free(data);
        ShowToast(region == REGION_EUR ? M_OK_EUR : M_OK_USA, 1);
    }
    sLastRegion = region;
    SaveSettings();
    ScanInstalled();
    BuildMenu();
}

static int RegionOfData(const unsigned char* data, size_t size, int* japanese) {
    uint8_t sha[20];
    char hex[41];
    int r, i;
    PcSha1(data, size, sha);
    for (i = 0; i < 20; i++)
        snprintf(hex + i * 2, 3, "%02x", sha[i]);
    *japanese = !strcmp(hex, kJapanSha);
    for (r = 0; r < REGION_COUNT; r++)
        if (!strcmp(hex, kRegionSha[r]))
            return r;
    return -1;
}

static void FindRom(void) {
#ifdef _WIN32
    wchar_t file[1024] = L"";
    OPENFILENAMEW ofn;
    SDL_SysWMinfo wm;
    memset(&ofn, 0, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    SDL_VERSION(&wm.version);
    if (SDL_GetWindowWMInfo(sWin, &wm))
        ofn.hwndOwner = wm.info.win.window;
    ofn.lpstrFilter = L"Juego de Game Boy Advance (*.gba)\0*.gba\0Todos los archivos\0*.*\0";
    ofn.lpstrFile = file;
    ofn.nMaxFile = 1024;
    ofn.lpstrTitle = L"Elige tu copia de Kingdom Hearts: Chain of Memories";
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
    if (GetOpenFileNameW(&ofn)) {
        char utf8[3072];
        WideCharToMultiByte(CP_UTF8, 0, file, -1, utf8, sizeof(utf8), NULL, NULL);
        AcceptRom(utf8);
    }
#endif
}

/* ------------------------------------------------------------------ */
/* Starting the engine                                                  */
/* ------------------------------------------------------------------ */

static void Play(int region) {
    char exe[1100], map[1100], rom[1100], cmd[4400];
    sLastRegion = region;
    SaveSettings();
    snprintf(exe, sizeof(exe), "%smotor/rdc-%s.exe", sProgDir, kRegionId[region]);
    snprintf(map, sizeof(map), "%smotor/rdc-%s.map", sProgDir, kRegionId[region]);
    RomPath(rom, sizeof(rom), region);
    if (!FileExists(exe) || !FileExists(map)) {
        ShowToast(M_NO_ENGINE, 0);
        return;
    }
    {
        /* No trailing backslash before a closing quote: Windows would read \" as a quote. */
        char root[1100];
        size_t n;
        snprintf(root, sizeof(root), "%s", sDataDir);
        n = strlen(root);
        while (n > 3 && (root[n - 1] == '\\' || root[n - 1] == '/'))
            root[--n] = 0;
        snprintf(cmd, sizeof(cmd), "\"%s\" --root \"%s\" --rom \"%s\" --map \"%s\" --region %s %s", exe, root, rom,
             map, kRegionId[region], sExtraArgs);
    }
#ifdef _WIN32
    {
        static wchar_t wcmd[4400];
        STARTUPINFOW si;
        PROCESS_INFORMATION pi;
        DWORD code = 0;
        MultiByteToWideChar(CP_UTF8, 0, cmd, -1, wcmd, 4400);
        memset(&si, 0, sizeof(si));
        si.cb = sizeof(si);
        sToast = M_LAUNCH;
        sToastUntil = SDL_GetTicks() + 1500;
        Render();
        if (!CreateProcessW(NULL, wcmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            ShowToast(M_NO_ENGINE, 0);
            return;
        }
        SDL_HideWindow(sWin);
        WaitForSingleObject(pi.hProcess, INFINITE);
        GetExitCodeProcess(pi.hProcess, &code);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        SDL_ShowWindow(sWin);
        SDL_RaiseWindow(sWin);
        SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
        sToast = -1;
        if (code != 0)
            ShowToast(M_ENGINE_FAIL, 0);
    }
#else
    if (system(cmd) != 0)
        ShowToast(M_ENGINE_FAIL, 0);
#endif
}

static void OpenSavesFolder(void) {
    char p[1100];
    snprintf(p, sizeof(p), "%spartidas", sDataDir);
#ifdef _WIN32
    {
        wchar_t w[1100];
        MultiByteToWideChar(CP_UTF8, 0, p, -1, w, 1100);
        ShellExecuteW(NULL, L"open", w, NULL, NULL, SW_SHOWNORMAL);
    }
#endif
}

/* ------------------------------------------------------------------ */
/* Drawing                                                              */
/* ------------------------------------------------------------------ */

static SDL_Texture* LoadPng(int resId, const char* fallback) {
    const unsigned char* bytes = NULL;
    int len = 0, w, h, n;
    unsigned char* px;
    SDL_Surface* s;
    SDL_Texture* t;
    void* fileData = NULL;
#ifdef _WIN32
    HRSRC r = FindResourceA(NULL, MAKEINTRESOURCEA(resId), MAKEINTRESOURCEA(10) /* RT_RCDATA */);
    if (r) {
        HGLOBAL g = LoadResource(NULL, r);
        bytes = (const unsigned char*)LockResource(g);
        len = (int)SizeofResource(NULL, r);
    }
#else
    (void)resId;
#endif
    if (!bytes) {
        size_t sz;
        fileData = SDL_LoadFile(fallback, &sz);
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
    t = SDL_CreateTextureFromSurface(sRen, s);
    SDL_FreeSurface(s);
    stbi_image_free(px);
    if (t)
        SDL_SetTextureBlendMode(t, SDL_BLENDMODE_BLEND);
    return t;
}

static void Sprite(int id, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Rect src = kSprites[id], dst = {x, y, src.w, src.h};
    SDL_SetTextureColorMod(sAtlas, r, g, b);
    SDL_SetTextureAlphaMod(sAtlas, a);
    SDL_RenderCopy(sRen, sAtlas, &src, &dst);
}

static void SpriteCentered(int id, int cx, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    Sprite(id, cx - kSprites[id].w / 2, y, r, g, b, a);
}

/* Floating cards and twinkling stars. */
typedef struct { float x, y, speed, sway, phase, scale, rot, spin; int kind; } Card;
static Card sCards[9];
typedef struct { int x, y; float phase, speed; } Star;
static Star sStars[44];

static float Frand(void) { return (float)rand() / (float)RAND_MAX; }

static void InitDecor(void) {
    int i;
    for (i = 0; i < 9; i++) {
        Card* c = &sCards[i];
        c->x = 40 + Frand() * (W - 80);
        c->y = Frand() * (H + 200);
        c->speed = 9 + Frand() * 12;
        c->sway = 10 + Frand() * 20;
        c->phase = Frand() * 6.28f;
        c->scale = 0.35f + Frand() * 0.45f;
        c->rot = Frand() * 40 - 20;
        c->spin = Frand() * 10 - 5;
        c->kind = i % 3;
    }
    for (i = 0; i < 44; i++) {
        sStars[i].x = rand() % W;
        sStars[i].y = (int)(powf(Frand(), 1.5f) * H * 0.7f);
        sStars[i].phase = Frand() * 6.28f;
        sStars[i].speed = 0.6f + Frand() * 1.8f;
    }
}

static void DrawDecor(float t, float dt) {
    int i;
    for (i = 0; i < 44; i++) {
        Star* s = &sStars[i];
        float a = 0.5f + 0.5f * sinf(t * s->speed + s->phase);
        SDL_Rect src = kSprites[G_TWINKLE];
        int sz = 10 + (int)(a * 10);
        SDL_Rect dst = {s->x - sz / 2, s->y - sz / 2, sz, sz};
        SDL_SetTextureColorMod(sAtlas, 255, 250, 230);
        SDL_SetTextureAlphaMod(sAtlas, (Uint8)(40 + a * 200));
        SDL_RenderCopy(sRen, sAtlas, &src, &dst);
    }
    for (i = 0; i < 9; i++) {
        Card* c = &sCards[i];
        SDL_Rect src = kSprites[G_CARD0 + c->kind];
        SDL_Rect dst;
        c->y -= c->speed * dt;
        c->rot += c->spin * dt;
        if (c->y < -120) {
            c->y = H + 40 + Frand() * 80;
            c->x = 40 + Frand() * (W - 80);
        }
        dst.w = (int)(src.w * c->scale);
        dst.h = (int)(src.h * c->scale);
        dst.x = (int)(c->x + sinf(t * 0.6f + c->phase) * c->sway) - dst.w / 2;
        dst.y = (int)c->y;
        SDL_SetTextureColorMod(sAtlas, 255, 255, 255);
        SDL_SetTextureAlphaMod(sAtlas, (Uint8)(70 + 50 * c->scale));
        SDL_RenderCopyEx(sRen, sAtlas, &src, &dst, c->rot, NULL, SDL_FLIP_NONE);
    }
}

static void BuildMenu(void) {
    int r, y;
    sNumButtons = 0;
    if (!sInstalled[REGION_EUR] && !sInstalled[REGION_USA]) {
        sButtons[sNumButtons++] = (Button){B_FIND, -1, ACT_FIND, 0};
        sButtons[sNumButtons++] = (Button){B_EXIT, -1, ACT_EXIT, 0};
        sButtonRects[0] = (SDL_Rect){(W - 470) / 2, 330, 470, 66};
        sButtonRects[1] = (SDL_Rect){(W - 470) / 2, 432, 470, 66};
        sSel = 0;
        return;
    }
    for (r = 0; r < REGION_COUNT; r++) {
        int rr = r == 0 ? sLastRegion : 1 - sLastRegion; /* last played first */
        if (sInstalled[rr])
            sButtons[sNumButtons++] = (Button){rr == REGION_EUR ? B_PLAY_EUR : B_PLAY_USA,
                                               rr == REGION_EUR ? S_PLAY_EUR : S_PLAY_USA, ACT_PLAY, rr};
    }
    if (!sInstalled[REGION_EUR] || !sInstalled[REGION_USA])
        sButtons[sNumButtons++] = (Button){B_ADD, sInstalled[REGION_EUR] ? S_ADD_USA : S_ADD_EUR, ACT_FIND, 0};
    sButtons[sNumButtons++] = (Button){B_FOLDER, S_FOLDER, ACT_FOLDER, 0};
    sButtons[sNumButtons++] = (Button){B_EXIT, -1, ACT_EXIT, 0};
    for (r = 0, y = 222; r < sNumButtons; r++, y += 74)
        sButtonRects[r] = (SDL_Rect){(W - 470) / 2, y, 470, 66};
    sSel = 0;
}

static void DrawButton(int i, float t) {
    SDL_Rect rc = sButtonRects[i];
    Button* b = &sButtons[i];
    int sel = i == sSel;
    if (sel) {
        Uint8 pulse = (Uint8)(215 + 40 * sinf(t * 3.0f));
        Sprite(G_BUTTON_SEL, rc.x - 16, rc.y - 16, 255, 255, 255, pulse);
    } else {
        Sprite(G_BUTTON, rc.x - 16, rc.y - 16, 255, 255, 255, 235);
    }
    if (b->sub >= 0) {
        SpriteCentered(b->label, rc.x + rc.w / 2, rc.y + 2, sel ? 255 : 226, sel ? 238 : 228, sel ? 196 : 255, 255);
        SpriteCentered(b->sub, rc.x + rc.w / 2, rc.y + 34, sel ? 240 : 186, sel ? 226 : 188, sel ? 200 : 228, 255);
    } else {
        SpriteCentered(b->label, rc.x + rc.w / 2, rc.y + (rc.h - kSprites[b->label].h) / 2,
                       sel ? 255 : 226, sel ? 238 : 228, sel ? 196 : 255, 255);
    }
}

static void RenderFrame(int present);
static void Render(void) { RenderFrame(1); }

static void RenderFrame(int present) {
    static Uint32 last;
    Uint32 now = SDL_GetTicks();
    float t = (now - sStartTicks) / 1000.0f;
    float dt = last ? (now - last) / 1000.0f : 0;
    int welcome = !sInstalled[REGION_EUR] && !sInstalled[REGION_USA];
    Uint8 fadeA;
    int i;
    last = now;
    if (dt > 0.1f)
        dt = 0.1f;
    sFade = t < 1.2f ? t / 1.2f : 1.0f;
    fadeA = (Uint8)(255 * sFade);

    SDL_RenderCopy(sRen, sBg, NULL, NULL);
    DrawDecor(t, dt);

    /* Title, with a slow breathing glow. */
    SpriteCentered(T_TITLE, W / 2, 26, 255, 255, 255, (Uint8)(fadeA * (0.9f + 0.1f * sinf(t * 1.3f))));
    SpriteCentered(T_SUBTITLE, W / 2, 126, 205, 200, 245, fadeA);
    SpriteCentered(G_ORNAMENT, W / 2, 168, 255, 255, 255, fadeA);

    if (welcome) {
        SpriteCentered(G_PANEL, W / 2, 196, 255, 255, 255, (Uint8)(fadeA * 0.95f));
        SpriteCentered(T_WELCOME1, W / 2, 232, 236, 232, 255, fadeA);
        SpriteCentered(T_WELCOME2, W / 2, 272, 210, 206, 240, fadeA);
    }
    for (i = 0; i < sNumButtons; i++)
        DrawButton(i, t);

    if (sToast >= 0 && SDL_TICKS_PASSED(now, sToastUntil))
        sToast = -1;
    if (sToast >= 0) {
        int tw = kSprites[sToast].w + 40, th = 50;
        SDL_Rect box = {(W - tw) / 2, 530, tw, th};
        SDL_SetRenderDrawBlendMode(sRen, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(sRen, 8, 10, 32, 215);
        SDL_RenderFillRect(sRen, &box);
        if (sToastGood)
            SDL_SetRenderDrawColor(sRen, 236, 200, 120, 255);
        else
            SDL_SetRenderDrawColor(sRen, 230, 110, 120, 255);
        SDL_RenderDrawRect(sRen, &box);
        SpriteCentered(sToast, W / 2, 530 + (th - kSprites[sToast].h) / 2,
                       sToastGood ? 255 : 255, sToastGood ? 240 : 205, sToastGood ? 205 : 210, 255);
    } else if (welcome) {
        SpriteCentered(F_SUPPORTED, W / 2, 528, 200, 190, 150, fadeA);
        SpriteCentered(F_PRIVACY, W / 2, 556, 170, 168, 210, fadeA);
    } else {
        SpriteCentered(F_KEYS, W / 2, 556, 170, 168, 210, fadeA);
    }
    Sprite(F_VERSION, W - kSprites[F_VERSION].w - 12, H - kSprites[F_VERSION].h - 6, 150, 146, 190, fadeA);
    if (present)
        SDL_RenderPresent(sRen);
}

/* ------------------------------------------------------------------ */

static void Activate(int i) {
    switch (sButtons[i].action) {
        case ACT_FIND: FindRom(); break;
        case ACT_PLAY: Play(sButtons[i].region); break;
        case ACT_FOLDER: OpenSavesFolder(); break;
        case ACT_EXIT: SDL_Quit(); exit(0);
    }
}

static int HitButton(int x, int y) {
    int i;
    for (i = 0; i < sNumButtons; i++) {
        SDL_Rect r = sButtonRects[i];
        if (x >= r.x && x < r.x + r.w && y >= r.y && y < r.y + r.h)
            return i;
    }
    return -1;
}

int main(int argc, char** argv) {
    const char* capture = NULL;
    const char* select = NULL;
    int playRegion = -1;
    int captureFrames = 90, frame = 0, i;
    char* base;

    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--capture") && i + 1 < argc)
            capture = argv[++i];
        else if (!strcmp(argv[i], "--frames") && i + 1 < argc)
            captureFrames = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--select") && i + 1 < argc)
            select = argv[++i];
        else if (!strcmp(argv[i], "--play") && i + 1 < argc)
            playRegion = !strcmp(argv[++i], "usa") ? REGION_USA : REGION_EUR;
        else if (!strcmp(argv[i], "--engine-args") && i + 1 < argc)
            sExtraArgs = argv[++i];
    }

    SDL_SetHint(SDL_HINT_WINDOWS_DPI_AWARENESS, "permonitorv2");
    SDL_SetHint(SDL_HINT_WINDOWS_INTRESOURCE_ICON, "1");
    SDL_SetHint(SDL_HINT_WINDOWS_INTRESOURCE_ICON_SMALL, "1");
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0)
        return 1;

    base = SDL_GetBasePath();
    snprintf(sProgDir, sizeof(sProgDir), "%s", base ? base : "./");
    SDL_free(base);
    snprintf(sDataDir, sizeof(sDataDir), "%s", sProgDir);
    if (!DirWritable(sDataDir)) {
        char* pref = SDL_GetPrefPath(NULL, "ReinoDeCorazones");
        if (pref) {
            snprintf(sDataDir, sizeof(sDataDir), "%s", pref);
            SDL_free(pref);
        }
    }
    {
        static const char* const dirs[] = {"rom", "partidas", "config", "capturas", "registros"};
        for (i = 0; i < 5; i++) {
            char p[1100];
            snprintf(p, sizeof(p), "%s%s", sDataDir, dirs[i]);
            MakeDir(p);
        }
    }
    MigrateOldSave();
    LoadSettings();
    AdoptLooseRoms();
    ScanInstalled();

    sWin = SDL_CreateWindow("Reino de Corazones", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H,
                            SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
    sRen = SDL_CreateRenderer(sWin, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!sRen)
        sRen = SDL_CreateRenderer(sWin, -1, SDL_RENDERER_SOFTWARE);
    SDL_RenderSetLogicalSize(sRen, W, H);
    sBg = LoadPng(101, "assets/fondo.png");
    sAtlas = LoadPng(102, "assets/atlas.png");
    if (!sBg || !sAtlas) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Reino de Corazones", "No se pudieron cargar los gráficos del menú.", sWin);
        return 1;
    }
    for (i = 0; i < SDL_NumJoysticks(); i++)
        if (SDL_IsGameController(i))
            SDL_GameControllerOpen(i);
    srand(7);
    InitDecor();
    BuildMenu();
    sStartTicks = SDL_GetTicks();
    if (select)
        AcceptRom(select);
    if (playRegion >= 0 && sInstalled[playRegion])
        Play(playRegion);

    for (;;) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    SDL_Quit();
                    return 0;
                case SDL_DROPFILE:
                    AcceptRom(e.drop.file);
                    SDL_free(e.drop.file);
                    break;
                case SDL_MOUSEMOTION: {
                    int h = HitButton(e.motion.x, e.motion.y);
                    if (h >= 0)
                        sSel = h;
                    break;
                }
                case SDL_MOUSEBUTTONDOWN:
                    if (e.button.button == SDL_BUTTON_LEFT) {
                        int h = HitButton(e.button.x, e.button.y);
                        if (h >= 0) {
                            sSel = h;
                            Activate(h);
                        }
                    }
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_UP: sSel = (sSel + sNumButtons - 1) % sNumButtons; break;
                        case SDLK_DOWN: case SDLK_TAB: sSel = (sSel + 1) % sNumButtons; break;
                        case SDLK_RETURN: case SDLK_KP_ENTER: case SDLK_SPACE: Activate(sSel); break;
                        case SDLK_ESCAPE: SDL_Quit(); return 0;
                    }
                    break;
                case SDL_CONTROLLERDEVICEADDED:
                    SDL_GameControllerOpen(e.cdevice.which);
                    break;
                case SDL_CONTROLLERBUTTONDOWN:
                    if (e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP)
                        sSel = (sSel + sNumButtons - 1) % sNumButtons;
                    else if (e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN)
                        sSel = (sSel + 1) % sNumButtons;
                    else if (e.cbutton.button == SDL_CONTROLLER_BUTTON_A || e.cbutton.button == SDL_CONTROLLER_BUTTON_START)
                        Activate(sSel);
                    break;
            }
        }
        if (capture && ++frame >= captureFrames) {
            SDL_Surface* s = SDL_CreateRGBSurfaceWithFormat(0, W, H, 32, SDL_PIXELFORMAT_ARGB8888);
            RenderFrame(0);
            SDL_RenderReadPixels(sRen, NULL, SDL_PIXELFORMAT_ARGB8888, s->pixels, s->pitch);
            SDL_SaveBMP(s, capture);
            SDL_FreeSurface(s);
            SDL_Quit();
            return 0;
        }
        Render();
        if (!SDL_GetWindowFlags(sWin) || capture)
            SDL_Delay(1);
    }
}
