/*
 * pc_video.c
 * Image filters for the window: turns the game's 240x160 picture into the
 * image that is shown, at 1x to 5x.
 *
 *   original   sharp pixels (nearest neighbour)
 *   suave      smooth (bilinear, done by the graphics card)
 *   limpio     clean pixels: enlarged sharply to Nx, then smoothed only
 *              between screen pixels (crisp at any window size)
 *   bordes     Scale2x / Scale3x (EPX): rounds the staircase edges of
 *              pixel art without blurring
 *   lcd        the GBA's screen: a fine grid between pixels
 *   crt        a television: dark scanlines and a soft glow
 *
 * Optional extras: GBA colours (the original screen's softer, darker
 * colours) and LCD ghosting (each frame mixed with the previous one, like
 * the real screen; a few effects in GBA games rely on it).
 *
 * All filters run on the CPU: at most 1200x800 pixels per frame.
 */
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "pc_platform.h"
#include "pc_video.h"

#define GW PC_SCREEN_W
#define GH PC_SCREEN_H

static uint32_t sIn[GW * GH];       /* after colours / ghosting */
static uint32_t sPrev[GW * GH];     /* previous frame, for ghosting */
static int sHavePrev;
static uint32_t* sOut;              /* filtered image */
static uint32_t* sTmp;              /* intermediate for 4x (2x twice) */
static int sOutCap;
/* The GBA's screen has no backlight: colours look darker and less
 * saturated. Each channel is taken to linear light, mixed a little with the
 * others and darkened, then taken back. */
static uint32_t GbaColor(uint32_t p) {
    static const float mix[3][3] = {
        {0.84f, 0.18f, -0.02f}, /* red out   <- r, g, b */
        {0.09f, 0.76f, 0.15f},  /* green out */
        {0.15f, 0.12f, 0.73f},  /* blue out  */
    };
    float lin[3];
    uint32_t out = 0xFF000000u;
    int o;
    lin[0] = powf(((p >> 16) & 255) / 255.0f, 2.2f);
    lin[1] = powf(((p >> 8) & 255) / 255.0f, 2.2f);
    lin[2] = powf((p & 255) / 255.0f, 2.2f);
    for (o = 0; o < 3; o++) {
        float x = (mix[o][0] * lin[0] + mix[o][1] * lin[1] + mix[o][2] * lin[2]) * 0.92f;
        x = x < 0 ? 0 : x > 1 ? 1 : x;
        out |= (uint32_t)(powf(x, 1.0f / 2.2f) * 255.0f + 0.5f) << (16 - o * 8);
    }
    return out;
}

/* GBA colours per frame through a cache: the game shows few distinct colours. */
#define CACHE_BITS 12
static uint32_t sCacheKey[1 << CACHE_BITS], sCacheVal[1 << CACHE_BITS];

static uint32_t GbaColorCached(uint32_t p) {
    uint32_t h = ((p & 0xFFFFFF) * 2654435761u) >> (32 - CACHE_BITS);
    if (sCacheKey[h] != (p | 0xFF000000u)) {
        sCacheKey[h] = p | 0xFF000000u;
        sCacheVal[h] = GbaColor(p);
    }
    return sCacheVal[h];
}

static inline uint32_t Avg(uint32_t a, uint32_t b) {
    return (((a ^ b) & 0xFEFEFEFEu) >> 1) + (a & b);
}

static inline uint32_t Scale(uint32_t p, int num) { /* p * num / 256 per channel */
    uint32_t rb = ((p & 0x00FF00FFu) * (uint32_t)num >> 8) & 0x00FF00FFu;
    uint32_t g = ((p & 0x0000FF00u) * (uint32_t)num >> 8) & 0x0000FF00u;
    return 0xFF000000u | rb | g;
}

static void Nearest(const uint32_t* in, int w, int h, uint32_t* out, int n) {
    int x, y, i, j;
    for (y = 0; y < h; y++) {
        uint32_t* row = out + (size_t)y * n * w * n;
        for (x = 0; x < w; x++) {
            uint32_t p = in[y * w + x];
            for (i = 0; i < n; i++)
                row[x * n + i] = p;
        }
        for (j = 1; j < n; j++)
            memcpy(row + (size_t)j * w * n, row, (size_t)w * n * 4);
    }
}

/* Scale2x / EPX: each pixel becomes 2x2, taking a neighbour's colour where
 * two neighbours agree, which rounds diagonal edges. */
static void Scale2x(const uint32_t* in, int w, int h, uint32_t* out) {
    int x, y;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            uint32_t E = in[y * w + x];
            uint32_t B = in[(y > 0 ? y - 1 : y) * w + x];
            uint32_t H = in[(y < h - 1 ? y + 1 : y) * w + x];
            uint32_t D = in[y * w + (x > 0 ? x - 1 : x)];
            uint32_t F = in[y * w + (x < w - 1 ? x + 1 : x)];
            uint32_t* o = out + (size_t)(y * 2) * w * 2 + x * 2;
            if (B != H && D != F) {
                o[0] = D == B ? D : E;
                o[1] = B == F ? F : E;
                o[w * 2] = D == H ? D : E;
                o[w * 2 + 1] = H == F ? F : E;
            } else {
                o[0] = o[1] = o[w * 2] = o[w * 2 + 1] = E;
            }
        }
    }
}

/* Scale3x: the 3x3 version of the same rules. */
static void Scale3x(const uint32_t* in, int w, int h, uint32_t* out) {
    int x, y;
    for (y = 0; y < h; y++) {
        int ym = y > 0 ? y - 1 : y, yp = y < h - 1 ? y + 1 : y;
        for (x = 0; x < w; x++) {
            int xm = x > 0 ? x - 1 : x, xp = x < w - 1 ? x + 1 : x;
            uint32_t A = in[ym * w + xm], B = in[ym * w + x], C = in[ym * w + xp];
            uint32_t D = in[y * w + xm], E = in[y * w + x], F = in[y * w + xp];
            uint32_t G = in[yp * w + xm], H = in[yp * w + x], I = in[yp * w + xp];
            uint32_t* o = out + (size_t)(y * 3) * w * 3 + x * 3;
            size_t r = (size_t)w * 3;
            if (B != H && D != F) {
                o[0] = D == B ? D : E;
                o[1] = (D == B && E != C) || (B == F && E != A) ? B : E;
                o[2] = B == F ? F : E;
                o[r] = (D == B && E != G) || (D == H && E != A) ? D : E;
                o[r + 1] = E;
                o[r + 2] = (B == F && E != I) || (H == F && E != C) ? F : E;
                o[2 * r] = D == H ? D : E;
                o[2 * r + 1] = (D == H && E != I) || (H == F && E != G) ? H : E;
                o[2 * r + 2] = H == F ? F : E;
            } else {
                o[0] = o[1] = o[2] = o[r] = o[r + 1] = o[r + 2] = o[2 * r] = o[2 * r + 1] = o[2 * r + 2] = E;
            }
        }
    }
}

/* The GBA's LCD: a darker line between pixels, slightly brighter centres. */
static void Lcd(const uint32_t* in, int w, int h, uint32_t* out, int n) {
    int x, y, i, j;
    int edge = n >= 5 ? 214 : n == 4 ? 204 : n == 3 ? 192 : 205; /* darkening of the grid */
    int centre = n >= 3 ? 268 : 262;                /* compensating boost */
    for (y = 0; y < h; y++)
        for (x = 0; x < w; x++) {
            uint32_t p = in[y * w + x];
            uint32_t bright, dark = Scale(p, edge), corner = Scale(p, edge * edge / 256);
            {
                /* boost without overflow */
                uint32_t r = (p >> 16) & 255, g = (p >> 8) & 255, b = p & 255;
                r = r * centre >> 8; g = g * centre >> 8; b = b * centre >> 8;
                bright = 0xFF000000u | (r > 255 ? 255 : r) << 16 | (g > 255 ? 255 : g) << 8 | (b > 255 ? 255 : b);
            }
            for (j = 0; j < n; j++)
                for (i = 0; i < n; i++) {
                    int lastX = i == n - 1, lastY = j == n - 1;
                    out[(size_t)(y * n + j) * w * n + x * n + i] =
                        (lastX && lastY) ? corner : (lastX || lastY) ? dark : bright;
                }
        }
}

/* A television: each line of pixels drawn brighter in the middle and dark
 * at the bottom, with a little horizontal glow. */
static void Crt(const uint32_t* in, int w, int h, uint32_t* out, int n) {
    int x, y, i, j;
    for (y = 0; y < h; y++)
        for (x = 0; x < w; x++) {
            uint32_t p = in[y * w + x];
            uint32_t l = in[y * w + (x > 0 ? x - 1 : x)], r = in[y * w + (x < w - 1 ? x + 1 : x)];
            uint32_t glow = Avg(p, Avg(Avg(l, r), p)); /* 75% self, 25% neighbours */
            for (j = 0; j < n; j++) {
                int k;
                if (n == 2)
                    k = j == 0 ? 268 : 140;
                else if (j == n - 1)
                    k = 110;
                else if (j == 0)
                    k = 236;
                else
                    k = 276;
                for (i = 0; i < n; i++) {
                    uint32_t src = (i == 0 || i == n - 1) ? glow : p;
                    uint32_t rr = (src >> 16) & 255, gg = (src >> 8) & 255, bb = src & 255;
                    rr = rr * k >> 8; gg = gg * k >> 8; bb = bb * k >> 8;
                    out[(size_t)(y * n + j) * w * n + x * n + i] =
                        0xFF000000u | (rr > 255 ? 255 : rr) << 16 | (gg > 255 ? 255 : gg) << 8 | (bb > 255 ? 255 : bb);
                }
            }
        }
}

static void Reserve(int pixels) {
    if (pixels > sOutCap) {
        free(sOut);
        free(sTmp);
        sOut = (uint32_t*)malloc((size_t)pixels * 4);
        sTmp = (uint32_t*)malloc((size_t)pixels * 4);
        sOutCap = pixels;
    }
}

const uint32_t* PcVideoFilter(const PcVideoSettings* s, int* outW, int* outH, int* smooth) {
    int n = s->scale < 1 ? 1 : s->scale > 5 ? 5 : s->scale;
    int i;
    const uint32_t* src = gPcFramebuffer;

    /* Colours and ghosting work on the 240x160 picture. */
    if (s->gbaColors || s->ghosting) {
        for (i = 0; i < GW * GH; i++) {
            uint32_t p = gPcFramebuffer[i] | 0xFF000000u;
            if (s->gbaColors)
                p = GbaColorCached(p);
            if (s->ghosting) {
                uint32_t cur = p;
                if (sHavePrev)
                    p = Avg(p, sPrev[i]);
                sPrev[i] = cur;
            }
            sIn[i] = p;
        }
        sHavePrev = s->ghosting;
        src = sIn;
    } else {
        sHavePrev = 0;
    }

    *smooth = 1;
    switch (s->filter) {
        case PC_FILTER_SMOOTH:
            /* The graphics card smooths the 240x160 picture. */
            *outW = GW;
            *outH = GH;
            return src;
        case PC_FILTER_ORIGINAL:
            *smooth = 0;
            /* fallthrough */
        case PC_FILTER_CLEAN:
            if (n == 1) {
                *outW = GW;
                *outH = GH;
                return src;
            }
            Reserve(GW * GH * n * n);
            Nearest(src, GW, GH, sOut, n);
            break;
        case PC_FILTER_EDGES:
            if (n == 1) {
                *outW = GW;
                *outH = GH;
                *smooth = 0;
                return src;
            }
            Reserve(GW * GH * 25);
            if (n == 2) {
                Scale2x(src, GW, GH, sOut);
            } else if (n == 3) {
                Scale3x(src, GW, GH, sOut);
            } else {
                /* 4x = 2x twice; 5x is drawn at 4x and smoothed up by the card. */
                Scale2x(src, GW, GH, sTmp);
                Scale2x(sTmp, GW * 2, GH * 2, sOut);
                n = 4;
            }
            break;
        case PC_FILTER_LCD:
            if (n == 1)
                n = 3; /* the grid needs room: always drawn at least at 3x */
            Reserve(GW * GH * n * n);
            Lcd(src, GW, GH, sOut, n);
            break;
        case PC_FILTER_CRT:
        default:
            if (n == 1)
                n = 3;
            Reserve(GW * GH * n * n);
            Crt(src, GW, GH, sOut, n);
            break;
    }
    *outW = GW * n;
    *outH = GH * n;
    return sOut;
}

/* For 120 fps: the picture halfway between the previous frame and this one. */
void PcVideoBlend(const uint32_t* a, const uint32_t* b, uint32_t* out, int pixels) {
    int i;
    for (i = 0; i < pixels; i++)
        out[i] = Avg(a[i], b[i]);
}

void PcVideoResetHistory(void) {
    sHavePrev = 0;
}
