/*
 * pc_touch.c
 * On-screen controls for phones and tablets (Android).
 *
 * Landscape layout around the game picture: a floating joystick on the left,
 * A (key-sword: attack) and B (jump) on the right, the L/R card arrows and
 * the L+R button (stacked cards) just above the game's card deck, Select and
 * Start at the bottom, the menu (heart) and fast-forward at the top.
 * Artwork: port/res/touch_atlas.png (port/launcher/make_touch_assets.py).
 *
 * The joystick answers anywhere in a circle well beyond its drawing: where
 * the finger lands, the stick is centred there, and if the finger runs past
 * its edge the stick follows it. 8 directions. Every finger is tracked on
 * its own; a finger between A and B presses both.
 */
#include <math.h>
#include <string.h>
#include <SDL.h>
#include "pc_config.h"
#include "pc_platform.h"
#include "pc_touch.h"

#define STBI_ONLY_PNG
#define STBI_ONLY_JPEG
#define STBI_NO_STDIO
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#include "../launcher/stb_image.h"
#pragma GCC diagnostic pop
#include "../res/touch_atlas.h"

enum { KEY_A = 1 << 0, KEY_B = 1 << 1, KEY_SELECT = 1 << 2, KEY_START = 1 << 3, KEY_RIGHT = 1 << 4,
       KEY_LEFT = 1 << 5, KEY_UP = 1 << 6, KEY_DOWN = 1 << 7, KEY_R = 1 << 8, KEY_L = 1 << 9 };

/* Pseudo-buttons above the GBA's ten. */
#define TOUCH_MENU (1 << 12)
#define TOUCH_FAST (1 << 13)

enum { STICK_FLOATING, STICK_FIXED, STICK_DPAD };

enum { C_STICK, C_A, C_B, C_L, C_R, C_LR, C_START, C_SELECT, C_MENU, C_FAST, C_COUNT };

typedef struct {
    float x, y, w, h; /* drawn rectangle, output pixels */
    float cx, cy, r;  /* hit circle (round controls) */
    float angle;      /* degrees, clockwise (the L / R plates) */
    float sag;        /* the plate's arch: its ends drop this much (output pixels) */
} Control;

#define MAX_FINGERS 10
typedef struct {
    SDL_FingerID id;
    int used;
    float x, y;
    int onStick; /* this finger steers the joystick */
    uint32_t bits;
} Finger;

static SDL_Texture* sAtlas;
static SDL_Texture* sBackdrop; /* the castle of hearts around the picture */
static int sBackdropW, sBackdropH;
static Control sCtl[C_COUNT];
static Finger sFingers[MAX_FINGERS];
static int sOw, sOh;
/* Joystick: resting centre (layout), current centre and knob (while held). */
static float sStickRestX, sStickRestY, sStickX, sStickY, sKnobX, sKnobY;
static float sStickZoneX, sStickZoneY; /* left side: a touch there grabs the stick */
static float sStickReach;   /* knob travel = radius of the base */
static float sStickGrab;    /* how far from the resting centre a touch takes it */
static int sStickHeld;
static int sGamepad;    /* a game controller is connected: the controls hide */
static int sShowAnyway; /* ...unless the screen was touched since its last use */
static uint32_t sHeld;
static int sMenuTaps;
static int sFastOn;
static uint32_t sLastTouchMs;
static SDL_Haptic* sHaptic;
static int sHapticTried;

static SDL_Texture* LoadImage(SDL_Renderer* r, const char* asset, const char* devPath, int* outW, int* outH) {
    size_t sz;
    void* data = SDL_LoadFile(asset, &sz); /* Android: from the APK's assets */
    int w, h, n;
    unsigned char* px;
    SDL_Surface* s;
    SDL_Texture* t;
    if (!data)
        data = SDL_LoadFile(devPath, &sz);
    if (!data)
        return NULL;
    px = stbi_load_from_memory((const unsigned char*)data, (int)sz, &w, &h, &n, 4);
    SDL_free(data);
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
    if (outW) *outW = w;
    if (outH) *outH = h;
    return t;
}

static SDL_Texture* LoadAtlas(SDL_Renderer* r) {
    return LoadImage(r, "touch_atlas.png", "port/res/touch_atlas.png", NULL, NULL);
}

int PcTouchInit(SDL_Renderer* r) {
    if (sAtlas)
        SDL_DestroyTexture(sAtlas);
    sAtlas = LoadAtlas(r);
    if (sBackdrop)
        SDL_DestroyTexture(sBackdrop);
    sBackdrop = LoadImage(r, "art/borde.jpg", "port/android/art/borde.jpg", &sBackdropW, &sBackdropH);
    if (!sAtlas)
        PcLog("[pc] touch: artwork not found (%s)\n", SDL_GetError());
    return sAtlas != NULL;
}

/* The renderer lost its textures (the phone switched apps): load them again. */
void PcTouchReload(SDL_Renderer* r) {
    sAtlas = NULL; /* the old ones are gone with the device */
    sBackdrop = NULL;
    PcTouchInit(r);
}

static void Place(int c, float cx, float cy, float w, float h, float hitR) {
    sCtl[c].w = w;
    sCtl[c].h = h;
    sCtl[c].x = cx - w / 2;
    sCtl[c].y = cy - h / 2;
    sCtl[c].cx = cx;
    sCtl[c].cy = cy;
    sCtl[c].r = hitR;
    sCtl[c].angle = 0;
    sCtl[c].sag = 0;
}

/* Lays the controls out for an ow x oh screen, the game drawn in `game`. */
void PcTouchLayout(int ow, int oh, const SDL_Rect* game) {
    /* Everything is sized from the screen's short side (never stretched) and
     * placed from the screen's edges, so the controls sit in the same spots
     * under the thumbs whatever the picture's shape (3:2, 4:3, 16:9, whole
     * screen). Only the card arrows follow the picture: they belong above the
     * game's card deck, and step aside if that is where the joystick is. */
    static const float kSize[3] = {0.84f, 1.0f, 1.16f};
    float k = kSize[gPcConfig.touchSize < 0 || gPcConfig.touchSize > 2 ? 1 : gPcConfig.touchSize];
    float u = (float)(oh < ow ? oh : ow); /* the short side */
    float m = u * 0.035f;
    float d = u * 0.34f * k;              /* joystick size */
    float ab = u * 0.19f * k;             /* A/B size */
    float pw2 = u * 0.24f * k, ph2 = pw2 * 130 / 220; /* L / R plates */
    float tw = u * 0.17f * k, th = tw * 110 / 130;  /* L+R button */
    float gsx = game->w / (float)PC_SCREEN_W;       /* screen pixels per GBA pixel */
    float gsy = game->h / (float)PC_SCREEN_H;       /* (differ when the picture is stretched) */
    float pw = u * 0.18f * k, ph = pw * 64 / 200;
    float ic = u * 0.105f * k;
    float dcx, dcy, acx, acy, ax, ay;
    float bl = (float)game->x, br = (float)(ow - game->x - game->w); /* side borders */
    int inLeft = 0, inRight = 0;

    sOw = ow;
    sOh = oh;

    /* With a narrower picture (original, 4:3, 16:9) the borders beside it
     * hold the controls, shrunk a little if needed, so they cover none of
     * the game. With the whole screen they float over the picture. */
    if (bl > 0 && br > 0) {
        float sL = (bl - m) / d, sR = (br - m) / (ab * 2.08f);
        if (sL >= 0.7f) {
            inLeft = 1;
            if (sL < 1) d *= sL;
        }
        if (sR >= 0.7f) {
            inRight = 1;
            if (sR < 1) { ab *= sR; tw *= sR; th *= sR; }
        }
    }

    /* Joystick: left thumb, high on the left so the game's card deck
     * (bottom left) stays in view. It is floating: a touch anywhere on the
     * left side brings it under the finger. */
    dcx = inLeft ? bl / 2 : m + d * 0.5f;
    dcy = oh * 0.34f;
    if (dcy - d / 2 < oh * 0.13f)
        dcy = oh * 0.13f + d / 2;
    if (dcy + d / 2 > oh - m - ph * 1.3f)
        dcy = oh - m - ph * 1.3f - d / 2;
    Place(C_STICK, dcx, dcy, d, d, d * 0.5f);
    sStickRestX = dcx;
    sStickRestY = dcy;
    sStickReach = d * 0.36f;
    sStickGrab = d * 1.0f;
    sStickZoneX = inLeft ? (bl > dcx + d * 0.75f ? bl : dcx + d * 0.75f) : dcx + d * 0.75f;
    sStickZoneY = oh * 0.12f;
    if (!sStickHeld) {
        sStickX = sKnobX = dcx;
        sStickY = sKnobY = dcy;
    }

    /* A up and to the right of B, like the console: right thumb. */
    acx = inRight ? ow - br / 2 + ab * 0.54f : ow - m - ab * 0.62f;
    acy = oh * 0.50f;
    Place(C_A, acx, acy, ab, ab, ab * 0.62f);
    Place(C_B, acx - ab * 1.08f, acy + ab * 0.55f, ab, ab, ab * 0.62f);
    /* L+R (stacked cards): with them, under A and right of B. */
    {
        float lry = acy + ab * 1.2f;
        if (lry + th / 2 > oh - m - ph * 1.4f)
            lry = oh - m - ph * 1.4f - th / 2;
        Place(C_LR, acx, lry, tw, th, 0);
    }

    Place(C_SELECT, dcx, oh - m - ph / 2, pw, ph, 0);
    Place(C_START, acx - ab * 0.54f, oh - m - ph / 2, pw, ph, 0);
    Place(C_MENU, ow / 2.0f - ic * 0.65f, m * 0.6f + ic / 2, ic, ic, ic * 0.65f);
    Place(C_FAST, ow / 2.0f + ic * 0.65f, m * 0.6f + ic / 2, ic, ic, ic * 0.65f);

    /* L / R: two arrow plates in a fan around the game's card deck (bottom
     * left of the picture): L above it, R tilted down along its right side,
     * the L+R button between them. Anchored to the deck's top right corner;
     * sized from the screen like the rest, so they never stretch. */
    ax = game->x + 44 * gsx;
    ay = game->y + 102 * gsy;
    {
        /* Both plates lie on one circle around the deck, at the same distance
         * from its centre and with the circle's own curve, so they read as
         * one arc: L above the cards, R down their right side. */
        const float kPi = 3.14159265f;
        float rho = u * 0.40f * k;                       /* the circle's radius */
        float sag = pw2 * 17 / 220;                      /* as drawn (make_touch_assets.py) */
        float aL = -80 * kPi / 180, aR = -30 * kPi / 180; /* where each sits on it */
        float rc = rho - sag * 0.5f;                     /* to the sprite's centre */
        float cx = ax - u * 0.30f * k, cy = ay + u * 0.43f * k; /* the circle's centre */
        float lx, ly, rx, ry, hw = pw2 * 0.5f;
        /* Keep both on screen: move the whole arc, never bend it. */
        lx = cx + rc * cosf(aL);
        if (lx - hw * 1.05f < m)
            cx += m - (lx - hw * 1.05f);
        ry = cy + rc * sinf(aR);
        if (ry + hw * sinf(60 * kPi / 180) + ph2 * 0.6f > oh - m)
            cy -= ry + hw * sinf(60 * kPi / 180) + ph2 * 0.6f - (oh - m);
        lx = cx + rc * cosf(aL);
        ly = cy + rc * sinf(aL);
        rx = cx + rc * cosf(aR);
        ry = cy + rc * sinf(aR);
        Place(C_L, lx, ly, pw2, ph2 + sag, 0);
        sCtl[C_L].angle = aL * 180 / kPi + 90;
        sCtl[C_L].sag = sag;
        Place(C_R, rx, ry, pw2, ph2 + sag, 0);
        sCtl[C_R].angle = aR * 180 / kPi + 90;
        sCtl[C_R].sag = sag;
    }
}

/* Inside a control's (possibly turned) rectangle, grown by `grow`. */
static int InPlate(int c, float x, float y, float grow) {
    const Control* k = &sCtl[c];
    float a = -k->angle * (float)M_PI / 180.0f;
    float dx = x - k->cx, dy = y - k->cy;
    float lx = dx * cosf(a) - dy * sinf(a), ly = dx * sinf(a) + dy * cosf(a);
    float band = k->h - k->sag;                       /* the plate's own thickness */
    float t = lx / (k->w * 0.5f);
    float mid = k->sag * t * t - k->sag * 0.5f;       /* centre line of the arch */
    return fabsf(lx) < k->w * (0.5f + grow) && fabsf(ly - mid) < band * (0.5f + grow);
}

static int InRect(int c, float x, float y, float grow) {
    const Control* k = &sCtl[c];
    float gx = k->w * grow, gy = k->h * grow;
    return x >= k->x - gx && x < k->x + k->w + gx && y >= k->y - gy && y < k->y + k->h + gy;
}

static float Dist(int c, float x, float y) {
    float dx = x - sCtl[c].cx, dy = y - sCtl[c].cy;
    return sqrtf(dx * dx + dy * dy);
}

/* Direction of the knob from the stick's centre (8 ways). */
static uint32_t StickBits(void) {
    float dx = sKnobX - sStickX, dy = sKnobY - sStickY;
    float r = sqrtf(dx * dx + dy * dy);
    int sector;
    static const uint32_t kDirs[8] = {KEY_RIGHT, KEY_RIGHT | KEY_DOWN, KEY_DOWN, KEY_DOWN | KEY_LEFT,
                                      KEY_LEFT, KEY_LEFT | KEY_UP, KEY_UP, KEY_UP | KEY_RIGHT};
    if (r < sStickReach * 0.28f)
        return 0; /* dead centre */
    sector = (int)floorf((atan2f(dy, dx) + (float)M_PI / 8) / ((float)M_PI / 4));
    sector = ((sector % 8) + 8) % 8;
    return kDirs[sector];
}

/* The stick finger moved: the knob follows it, and the stick itself is
 * dragged along when the finger goes past its edge. */
static void StickTo(float x, float y) {
    float dx = x - sStickX, dy = y - sStickY;
    float r = sqrtf(dx * dx + dy * dy);
    if (r > sStickReach && gPcConfig.stickMode == STICK_FLOATING) {
        float pull = (r - sStickReach) / r;
        sStickX += dx * pull;
        sStickY += dy * pull;
    } else if (r > sStickReach) {
        /* Fixed: the knob stops at the rim, the direction still follows. */
        x = sStickX + dx * sStickReach / r;
        y = sStickY + dy * sStickReach / r;
    }
    sKnobX = x;
    sKnobY = y;
}

static void StickRelease(void) {
    sStickHeld = 0;
    sStickX = sKnobX = sStickRestX;
    sStickY = sKnobY = sStickRestY;
}

/* Buttons under a finger at (x, y) (not the joystick). */
static uint32_t ButtonsAt(float x, float y) {
    uint32_t bits = 0;
    if (InRect(C_LR, x, y, 0.08f))
        return KEY_L | KEY_R; /* right next to A and B: it wins its own square */
    {
        float da = Dist(C_A, x, y), db = Dist(C_B, x, y), r = sCtl[C_A].r;
        if (da < r * 1.15f && db < r * 1.15f)
            bits |= KEY_A | KEY_B; /* between the two: both */
        else if (da < r * 1.25f && da <= db)
            bits |= KEY_A;
        else if (db < r * 1.25f)
            bits |= KEY_B;
    }
    if (InPlate(C_L, x, y, 0.06f)) bits |= KEY_L;
    if (InPlate(C_R, x, y, 0.06f)) bits |= KEY_R;
    if (InRect(C_START, x, y, 0.15f)) bits |= KEY_START;
    if (InRect(C_SELECT, x, y, 0.15f)) bits |= KEY_SELECT;
    if (Dist(C_MENU, x, y) < sCtl[C_MENU].r) bits |= TOUCH_MENU;
    if (Dist(C_FAST, x, y) < sCtl[C_FAST].r) bits |= TOUCH_FAST;
    return bits;
}

/* What a finger presses; `down` on the touch that starts it. */
static uint32_t Hit(Finger* f, int down) {
    if (f->onStick) {
        StickTo(f->x, f->y);
        return StickBits();
    }
    if (down) {
        uint32_t bits = ButtonsAt(f->x, f->y);
        float dx = f->x - sStickRestX, dy = f->y - sStickRestY;
        float dist = sqrtf(dx * dx + dy * dy);
        if (!bits && !sStickHeld && gPcConfig.stickMode != STICK_FLOATING &&
            dist < sCtl[C_STICK].w * 0.62f) {
            /* Fixed joystick or D-pad: pressed where it is. */
            f->onStick = 1;
            sStickHeld = 1;
            sStickX = sStickRestX;
            sStickY = sStickRestY;
            StickTo(f->x, f->y);
            return StickBits();
        }
        if (!bits && !sStickHeld && gPcConfig.stickMode == STICK_FLOATING &&
            ((f->x < sStickZoneX && f->y > sStickZoneY) || dist < sStickGrab)) {
            /* The stick comes to the finger. */
            float half = sCtl[C_STICK].w / 2;
            f->onStick = 1;
            sStickHeld = 1;
            sStickX = f->x < half ? half : f->x > sOw - half ? sOw - half : f->x;
            sStickY = f->y < half ? half : f->y > sOh - half ? sOh - half : f->y;
            sKnobX = f->x;
            sKnobY = f->y;
            return StickBits();
        }
        return bits;
    }
    return ButtonsAt(f->x, f->y);
}

static void Buzz(void) {
    if (!gPcConfig.vibration)
        return;
    if (!sHapticTried) {
        int i;
        sHapticTried = 1;
        SDL_InitSubSystem(SDL_INIT_HAPTIC);
        /* The phone's own vibrator is the last haptic device on Android. */
        for (i = SDL_NumHaptics() - 1; i >= 0 && !sHaptic; i--) {
            sHaptic = SDL_HapticOpen(i);
            if (sHaptic && SDL_HapticRumbleInit(sHaptic) != 0) {
                SDL_HapticClose(sHaptic);
                sHaptic = NULL;
            }
        }
    }
    if (sHaptic)
        SDL_HapticRumblePlay(sHaptic, 0.5f, 12);
}

static void Recompute(void) {
    int i;
    uint32_t held = 0, pressedNow;
    for (i = 0; i < MAX_FINGERS; i++)
        if (sFingers[i].used)
            held |= sFingers[i].bits;
    pressedNow = held & ~sHeld;
    if (pressedNow & TOUCH_MENU)
        sMenuTaps++;
    if (pressedNow & TOUCH_FAST)
        sFastOn = !sFastOn;
    if (pressedNow & ~(uint32_t)(KEY_UP | KEY_DOWN | KEY_LEFT | KEY_RIGHT))
        Buzz(); /* not for every change of direction */
    sHeld = held;
}

static Finger* FindFinger(SDL_FingerID id, int create) {
    int i;
    for (i = 0; i < MAX_FINGERS; i++)
        if (sFingers[i].used && sFingers[i].id == id)
            return &sFingers[i];
    if (!create)
        return NULL;
    for (i = 0; i < MAX_FINGERS; i++)
        if (!sFingers[i].used) {
            memset(&sFingers[i], 0, sizeof(sFingers[i]));
            sFingers[i].used = 1;
            sFingers[i].id = id;
            return &sFingers[i];
        }
    return NULL;
}

int PcTouchHandleEvent(const SDL_Event* e) {
    Finger* f;
    switch (e->type) {
        case SDL_FINGERDOWN:
        case SDL_FINGERMOTION:
            if (sGamepad && !sShowAnyway) {
                /* Controller in use: a touch only brings the buttons back. */
                if (e->type == SDL_FINGERDOWN)
                    sShowAnyway = 1;
                return 1;
            }
            f = FindFinger(e->tfinger.fingerId, e->type == SDL_FINGERDOWN);
            if (!f)
                return 1;
            f->x = e->tfinger.x * sOw;
            f->y = e->tfinger.y * sOh;
            f->bits = Hit(f, e->type == SDL_FINGERDOWN);
            sLastTouchMs = SDL_GetTicks();
            Recompute();
            return 1;
        case SDL_FINGERUP:
            f = FindFinger(e->tfinger.fingerId, 0);
            if (f) {
                if (f->onStick)
                    StickRelease();
                f->used = 0;
            }
            Recompute();
            return 1;
    }
    return 0;
}

void PcTouchReset(void) {
    memset(sFingers, 0, sizeof(sFingers));
    sHeld = 0;
    StickRelease();
}

uint16_t PcTouchHeld(void) {
    return (uint16_t)(sHeld & 0x3FF);
}

int PcTouchTakeMenu(void) {
    int n = sMenuTaps;
    sMenuTaps = 0;
    return n > 0;
}

int PcTouchFastForward(void) {
    return sFastOn;
}

static void DrawSprite(SDL_Renderer* r, int id, const Control* c, Uint8 alpha, double angle) {
    SDL_Rect src = kTouchSprites[id];
    SDL_FRect dst = {c->x, c->y, c->w, c->h};
    SDL_SetTextureAlphaMod(sAtlas, alpha);
    if (angle != 0)
        SDL_RenderCopyExF(r, sAtlas, &src, &dst, angle, NULL, SDL_FLIP_NONE);
    else
        SDL_RenderCopyF(r, sAtlas, &src, &dst);
}

/* Draws the controls in output pixels (the caller resets the logical size). */
void PcTouchDraw(SDL_Renderer* r) {
    Uint8 a = (Uint8)(gPcConfig.touchOpacity * 255 / 100);
    Uint8 aOn = (Uint8)(a + (255 - a) / 2);
    uint32_t h = sHeld;
    if (!sAtlas || gPcConfig.touchOpacity <= 0 || PcTouchHidden())
        return;
    if (gPcConfig.stickMode == STICK_DPAD) {
        Control pad = sCtl[C_STICK];
        static const struct { uint32_t key; double angle; } kArms[4] = {
            {KEY_UP, 0}, {KEY_RIGHT, 90}, {KEY_DOWN, 180}, {KEY_LEFT, 270}};
        int i;
        float w = pad.w * 0.95f;
        pad.x = sStickRestX - w / 2;
        pad.y = sStickRestY - w / 2;
        pad.w = pad.h = w;
        DrawSprite(r, T_DPAD, &pad, sStickHeld ? aOn : a, 0);
        for (i = 0; i < 4; i++)
            if (h & kArms[i].key)
                DrawSprite(r, T_DPAD_HL, &pad, 255, kArms[i].angle);
    } else {
        Control base = sCtl[C_STICK], knob;
        float kw = base.w * 0.54f;
        base.x = sStickX - base.w / 2;
        base.y = sStickY - base.h / 2;
        knob.w = knob.h = kw;
        knob.x = sKnobX - kw / 2;
        knob.y = sKnobY - kw / 2;
        DrawSprite(r, T_STICK, &base, sStickHeld ? aOn : a, 0);
        DrawSprite(r, sStickHeld ? T_KNOB_ON : T_KNOB, &knob, sStickHeld ? aOn : a, 0);
    }
    DrawSprite(r, h & KEY_A ? T_A_ON : T_A, &sCtl[C_A], h & KEY_A ? aOn : a, 0);
    DrawSprite(r, h & KEY_B ? T_B_ON : T_B, &sCtl[C_B], h & KEY_B ? aOn : a, 0);
    {
        int both = (h & (KEY_L | KEY_R)) == (KEY_L | KEY_R);
        DrawSprite(r, h & KEY_L ? T_L_ON : T_L, &sCtl[C_L], h & KEY_L ? aOn : a, sCtl[C_L].angle);
        DrawSprite(r, h & KEY_R ? T_R_ON : T_R, &sCtl[C_R], h & KEY_R ? aOn : a, sCtl[C_R].angle);
        DrawSprite(r, both ? T_LR_ON : T_LR, &sCtl[C_LR], both ? aOn : a, 0);
    }
    DrawSprite(r, h & KEY_START ? T_START_ON : T_START, &sCtl[C_START], h & KEY_START ? aOn : a, 0);
    DrawSprite(r, h & KEY_SELECT ? T_SELECT_ON : T_SELECT, &sCtl[C_SELECT], h & KEY_SELECT ? aOn : a, 0);
    DrawSprite(r, h & TOUCH_MENU ? T_MENU_ON : T_MENU, &sCtl[C_MENU], h & TOUCH_MENU ? aOn : a, 0);
    DrawSprite(r, sFastOn || (h & TOUCH_FAST) ? T_FAST_ON : T_FAST, &sCtl[C_FAST], sFastOn ? aOn : a, 0);
}

/* The surroundings of the picture: the castle of hearts at night (its left
 * half against the left edge, its right half against the right edge, both
 * at screen height), and a gold frame around the game. */
void PcTouchDrawBackdrop(SDL_Renderer* r, int ow, int oh, const SDL_Rect* game) {
    if (sBackdrop && (game->x > 0 || game->y > 0)) {
        int half = sBackdropW / 2;
        int dw = (int)((float)half * oh / sBackdropH + 0.5f);
        SDL_Rect srcL = {0, 0, half, sBackdropH}, srcR = {half, 0, sBackdropW - half, sBackdropH};
        SDL_Rect dstL = {0, 0, dw, oh}, dstR = {ow - dw, 0, dw, oh};
        SDL_SetTextureAlphaMod(sBackdrop, 255);
        SDL_RenderCopy(r, sBackdrop, &srcL, &dstL);
        SDL_RenderCopy(r, sBackdrop, &srcR, &dstR);
    }
    if (game->x > 2 || game->y > 2) {
        SDL_Rect f;
        int i;
        SDL_SetRenderDrawBlendMode(r, SDL_BLENDMODE_BLEND);
        for (i = 0; i < 6; i++) { /* soft shadow */
            f.x = game->x - 2 - i; f.y = game->y - 2 - i; f.w = game->w + 4 + 2 * i; f.h = game->h + 4 + 2 * i;
            SDL_SetRenderDrawColor(r, 0, 0, 8, (Uint8)(90 - i * 14));
            SDL_RenderDrawRect(r, &f);
        }
        f.x = game->x - 2; f.y = game->y - 2; f.w = game->w + 4; f.h = game->h + 4;
        SDL_SetRenderDrawColor(r, 236, 200, 120, 230); /* gold */
        SDL_RenderDrawRect(r, &f);
        f.x++; f.y++; f.w -= 2; f.h -= 2;
        SDL_SetRenderDrawColor(r, 120, 96, 60, 200);
        SDL_RenderDrawRect(r, &f);
    }
}

uint32_t PcTouchLastUse(void) {
    return sLastTouchMs;
}

/* A game controller was connected (1) or the last one removed (0). */
void PcTouchSetGamepad(int connected) {
    sGamepad = connected;
    sShowAnyway = 0;
    PcTouchReset();
}

/* The controller was used again: the on-screen buttons step aside. */
void PcTouchGamepadUsed(void) {
    if (sShowAnyway) {
        sShowAnyway = 0;
        PcTouchReset();
    }
}

int PcTouchHidden(void) {
    return sGamepad && !sShowAnyway;
}
