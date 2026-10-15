/*
 * pc_render.c
 * Scanline renderer for the emulated GBA display (PPU).
 *
 * Called once per visible line by the frame scheduler (pc_frame.c), it reads
 * the registers, VRAM, palette and OAM exactly as they are at that moment, so
 * raster effects driven by HBlank/VCount interrupts and HBlank DMA show up as
 * on the console. Supported:
 *
 *   - display modes 0-5 (tiled text BGs, affine BGs, 16bpp/8bpp bitmaps)
 *   - affine reference point latching (reload at frame start or when the game
 *     writes BGxX/BGxY, then +PB/+PD per line)
 *   - regular and affine sprites (incl. double size), 1D/2D tile mapping,
 *     4bpp/8bpp, priorities, semi-transparent sprites, OBJ window
 *   - windows 0/1/OBJ/outside with per-layer and effect masks
 *   - colour effects: alpha blending, brighten, darken
 *   - BG and OBJ mosaic, forced blank
 *
 * Output is a 240x160 XRGB8888 framebuffer (gPcFramebuffer).
 */
#include <string.h>
#include "pc_platform.h"

#define W 240
#define H 160

/* Register offsets. */
#define DISPCNT  0x00
#define BG0CNT   0x08
#define BG0HOFS  0x10
#define BG2PA    0x20
#define BG2X     0x28
#define BG2Y     0x2C
#define WIN0H    0x40
#define WIN1H    0x42
#define WIN0V    0x44
#define WIN1V    0x46
#define WININ    0x48
#define WINOUT   0x4A
#define MOSAIC   0x4C
#define BLDCNT   0x50
#define BLDALPHA 0x52
#define BLDY     0x54

/* Layer ids used for priority/effect resolution. */
enum { L_BG0, L_BG1, L_BG2, L_BG3, L_OBJ, L_BD };

/* A pixel slot is a 15-bit colour, or TRANSPARENT. */
#define TRANSPARENT 0x8000

uint32_t gPcFramebuffer[W * H];
static uint32_t sColorLut[0x8000];
static int sLutReady;

/* Per-line buffers. */
static uint16_t sBg[4][W];
static uint16_t sObj[W];
static uint8_t sObjPrio[W];
static uint8_t sObjSemi[W];
static uint8_t sObjWin[W];
static uint8_t sWinMask[W];

/* Internal affine reference points for BG2/BG3. */
static struct {
    int32_t refX[2], refY[2];
    uint32_t seenX[2], seenY[2];
} sAffine;
#define sRefX sAffine.refX
#define sRefY sAffine.refY
#define sSeenX sAffine.seenX
#define sSeenY sAffine.seenY

/* For snapshots (pc_state.c). */
void* PcRenderState(size_t* size) {
    *size = sizeof(sAffine);
    return &sAffine;
}

static inline uint16_t Io16(int off) { return PC_IO16(off); }
static inline uint32_t Io32(int off) { return PC_IO32(off); }

static inline uint16_t Pal16(int index) {
    uint16_t c;
    memcpy(&c, gPcPltt + (index & 0x1FF) * 2, 2);
    return c & 0x7FFF;
}

static inline uint16_t Vram16(uint32_t addr) {
    uint16_t v;
    memcpy(&v, gPcVram + (addr % PC_VRAM_SIZE), 2);
    return v;
}

static int32_t SignExtend28(uint32_t v) {
    return (int32_t)(v << 4) >> 4;
}

static void InitLut(void) {
    uint32_t c;
    for (c = 0; c < 0x8000; c++) {
        uint32_t r = c & 31, g = (c >> 5) & 31, b = (c >> 10) & 31;
        r = (r << 3) | (r >> 2);
        g = (g << 3) | (g >> 2);
        b = (b << 3) | (b >> 2);
        sColorLut[c] = 0xFF000000u | (r << 16) | (g << 8) | b;
    }
    sLutReady = 1;
}

/* ------------------------------------------------------------------ */
/* Backgrounds                                                          */
/* ------------------------------------------------------------------ */

static void MosaicLine(uint16_t* line, int size) {
    int x;
    if (size <= 1)
        return;
    for (x = 0; x < W; x++)
        line[x] = line[x - x % size];
}

static void RenderTextBg(int bg, int line) {
    uint16_t cnt = Io16(BG0CNT + bg * 2);
    uint32_t hofs = Io16(BG0HOFS + bg * 4) & 0x1FF;
    uint32_t vofs = Io16(BG0HOFS + 2 + bg * 4) & 0x1FF;
    uint32_t charBase = ((cnt >> 2) & 3) * 0x4000;
    uint32_t screenBase = ((cnt >> 8) & 31) * 0x800;
    int is8bpp = (cnt >> 7) & 1;
    int size = (cnt >> 14) & 3;
    uint32_t mapW = (size & 1) ? 512 : 256;
    uint32_t mapH = (size & 2) ? 512 : 256;
    uint16_t mosaic = Io16(MOSAIC);
    int mosH = (mosaic & 15) + 1, mosV = ((mosaic >> 4) & 15) + 1;
    int y = line;
    uint32_t py, ty;
    uint16_t* out = sBg[bg];
    int x;

    if (cnt & 0x40)
        y -= y % mosV;
    py = (y + vofs) & (mapH - 1);
    ty = py >> 3;

    for (x = 0; x < W; x++) {
        uint32_t px = (x + hofs) & (mapW - 1);
        uint32_t tx = px >> 3;
        uint32_t block = (tx >> 5) + (ty >> 5) * (mapW >> 8);
        uint16_t entry = Vram16(screenBase + block * 0x800 + ((ty & 31) * 32 + (tx & 31)) * 2);
        uint32_t tile = entry & 0x3FF;
        uint32_t fx = px & 7, fy = py & 7;
        uint32_t addr;

        if (entry & 0x400) fx = 7 - fx;
        if (entry & 0x800) fy = 7 - fy;

        if (is8bpp) {
            addr = charBase + tile * 64 + fy * 8 + fx;
            /* BG tiles cannot come from OBJ VRAM. */
            if (addr >= 0x10000) { out[x] = TRANSPARENT; continue; }
            out[x] = gPcVram[addr] ? Pal16(gPcVram[addr]) : TRANSPARENT;
        } else {
            uint8_t b, idx;
            addr = charBase + tile * 32 + fy * 4 + (fx >> 1);
            if (addr >= 0x10000) { out[x] = TRANSPARENT; continue; }
            b = gPcVram[addr];
            idx = (fx & 1) ? (b >> 4) : (b & 15);
            out[x] = idx ? Pal16((entry >> 12) * 16 + idx) : TRANSPARENT;
        }
    }
    if (cnt & 0x40)
        MosaicLine(out, mosH);
}

/* Reloads the affine reference point when the game wrote a new one. */
static void LatchAffine(int i, int line) {
    uint32_t rx = Io32(BG2X + i * 0x10), ry = Io32(BG2Y + i * 0x10);

    if (line == 0 || rx != sSeenX[i]) {
        sRefX[i] = SignExtend28(rx);
        sSeenX[i] = rx;
    }
    if (line == 0 || ry != sSeenY[i]) {
        sRefY[i] = SignExtend28(ry);
        sSeenY[i] = ry;
    }
}

static void StepAffine(int i) {
    sRefX[i] += (int16_t)Io16(BG2PA + i * 0x10 + 2); /* PB */
    sRefY[i] += (int16_t)Io16(BG2PA + i * 0x10 + 6); /* PD */
}

static void RenderAffineBg(int bg) {
    int i = bg - 2;
    uint16_t cnt = Io16(BG0CNT + bg * 2);
    int16_t pa = (int16_t)Io16(BG2PA + i * 0x10);
    int16_t pc = (int16_t)Io16(BG2PA + i * 0x10 + 4);
    uint32_t charBase = ((cnt >> 2) & 3) * 0x4000;
    uint32_t screenBase = ((cnt >> 8) & 31) * 0x800;
    int32_t size = 128 << ((cnt >> 14) & 3);
    int wrap = (cnt >> 13) & 1;
    int32_t x0 = sRefX[i], y0 = sRefY[i];
    uint16_t* out = sBg[bg];
    int x;

    for (x = 0; x < W; x++, x0 += pa, y0 += pc) {
        int32_t tx = x0 >> 8, ty = y0 >> 8;
        uint8_t tile, idx;

        if (wrap) {
            tx &= size - 1;
            ty &= size - 1;
        } else if (tx < 0 || ty < 0 || tx >= size || ty >= size) {
            out[x] = TRANSPARENT;
            continue;
        }
        tile = gPcVram[(screenBase + (ty >> 3) * (size >> 3) + (tx >> 3)) & 0xFFFF];
        idx = gPcVram[(charBase + tile * 64 + (ty & 7) * 8 + (tx & 7)) & 0xFFFF];
        out[x] = idx ? Pal16(idx) : TRANSPARENT;
    }
    if (cnt & 0x40)
        MosaicLine(out, (Io16(MOSAIC) & 15) + 1);
}

/* Modes 3-5 draw BG2 as a bitmap, still through the BG2 affine transform. */
static void RenderBitmapBg(int mode) {
    int16_t pa = (int16_t)Io16(BG2PA);
    int16_t pc = (int16_t)Io16(BG2PA + 4);
    uint16_t dispcnt = Io16(DISPCNT);
    uint32_t page = (mode != 3 && (dispcnt & 0x10)) ? 0xA000 : 0;
    int32_t bw = mode == 5 ? 160 : 240, bh = mode == 5 ? 128 : 160;
    int32_t x0 = sRefX[0], y0 = sRefY[0];
    uint16_t* out = sBg[2];
    int x;

    for (x = 0; x < W; x++, x0 += pa, y0 += pc) {
        int32_t tx = x0 >> 8, ty = y0 >> 8;

        if (tx < 0 || ty < 0 || tx >= bw || ty >= bh) {
            out[x] = TRANSPARENT;
            continue;
        }
        if (mode == 4) {
            uint8_t idx = gPcVram[page + ty * 240 + tx];
            out[x] = idx ? Pal16(idx) : TRANSPARENT;
        } else {
            out[x] = Vram16(page + (ty * bw + tx) * 2) & 0x7FFF;
        }
    }
    if (Io16(BG0CNT + 4) & 0x40)
        MosaicLine(out, (Io16(MOSAIC) & 15) + 1);
}

/* ------------------------------------------------------------------ */
/* Sprites                                                              */
/* ------------------------------------------------------------------ */

static const uint8_t sObjDims[3][4][2] = {
    {{8, 8}, {16, 16}, {32, 32}, {64, 64}},
    {{16, 8}, {32, 8}, {32, 16}, {64, 32}},
    {{8, 16}, {8, 32}, {16, 32}, {32, 64}},
};

static void RenderObjs(int line, int bitmapMode) {
    uint16_t dispcnt = Io16(DISPCNT);
    int map1d = (dispcnt >> 6) & 1;
    uint16_t mosaic = Io16(MOSAIC);
    int mosH = ((mosaic >> 8) & 15) + 1, mosV = ((mosaic >> 12) & 15) + 1;
    int i;

    for (i = 0; i < W; i++) {
        sObj[i] = TRANSPARENT;
        sObjPrio[i] = 4;
        sObjSemi[i] = 0;
        sObjWin[i] = 0;
    }
    if (!(dispcnt & 0x1000))
        return;

    for (i = 0; i < 128; i++) {
        const uint8_t* e = gPcOam + i * 8;
        uint16_t a0 = (uint16_t)(e[0] | (e[1] << 8));
        uint16_t a1 = (uint16_t)(e[2] | (e[3] << 8));
        uint16_t a2 = (uint16_t)(e[4] | (e[5] << 8));
        int affine = (a0 >> 8) & 1;
        int dbl = affine && ((a0 >> 9) & 1);
        int mode = (a0 >> 10) & 3;
        int mos = (a0 >> 12) & 1;
        int is8bpp = (a0 >> 13) & 1;
        int shape = (a0 >> 14) & 3;
        int w, h, boxW, boxH, y, x, dy, prio, pal, sx;
        uint32_t tile;
        int16_t pa = 0x100, pb = 0, pc = 0, pd = 0x100;

        if (!affine && (a0 & 0x200))
            continue; /* hidden */
        if (shape == 3 || mode == 3)
            continue;
        w = sObjDims[shape][(a1 >> 14) & 3][0];
        h = sObjDims[shape][(a1 >> 14) & 3][1];
        boxW = dbl ? w * 2 : w;
        boxH = dbl ? h * 2 : h;

        y = a0 & 0xFF;
        dy = (line - y) & 0xFF;
        if (dy >= boxH)
            continue;
        if (mos) {
            dy -= line % mosV;
            if (dy < 0)
                dy = 0;
        }

        x = a1 & 0x1FF;
        if (x >= W)
            x -= 512;
        tile = a2 & 0x3FF;
        prio = (a2 >> 10) & 3;
        pal = a2 >> 12;
        if (bitmapMode && tile < 512)
            continue; /* bitmap modes use the lower OBJ tiles as frame buffer */

        if (affine) {
            int g = (a1 >> 9) & 31;
            const uint8_t* p = gPcOam + g * 32;
            pa = (int16_t)(p[6] | (p[7] << 8));
            pb = (int16_t)(p[14] | (p[15] << 8));
            pc = (int16_t)(p[22] | (p[23] << 8));
            pd = (int16_t)(p[30] | (p[31] << 8));
        }

        for (sx = 0; sx < boxW; sx++) {
            int px = x + sx;
            int tx, ty, msx;
            uint32_t addr;
            uint8_t idx;
            uint16_t color;

            if (px < 0 || px >= W)
                continue;
            msx = sx;
            if (mos) {
                msx -= px % mosH;
                if (msx < 0)
                    msx = 0;
            }

            if (affine) {
                int rx = msx - boxW / 2, ry = dy - boxH / 2;
                tx = ((pa * rx + pb * ry) >> 8) + w / 2;
                ty = ((pc * rx + pd * ry) >> 8) + h / 2;
                if (tx < 0 || ty < 0 || tx >= w || ty >= h)
                    continue;
            } else {
                tx = (a1 & 0x1000) ? w - 1 - msx : msx;
                ty = (a1 & 0x2000) ? h - 1 - dy : dy;
            }

            if (is8bpp) {
                uint32_t t = map1d ? tile + ((ty >> 3) * (w >> 3) + (tx >> 3)) * 2
                                   : (tile & ~1u) + (ty >> 3) * 32 + (tx >> 3) * 2;
                addr = 0x10000 + (t & 0x3FF) * 32 + (ty & 7) * 8 + (tx & 7);
                idx = gPcVram[addr % PC_VRAM_SIZE];
                if (!idx)
                    continue;
                color = Pal16(256 + idx);
            } else {
                uint32_t t = map1d ? tile + (ty >> 3) * (w >> 3) + (tx >> 3)
                                   : tile + (ty >> 3) * 32 + (tx >> 3);
                uint8_t b;
                addr = 0x10000 + (t & 0x3FF) * 32 + (ty & 7) * 4 + ((tx & 7) >> 1);
                b = gPcVram[addr % PC_VRAM_SIZE];
                idx = (tx & 1) ? (b >> 4) : (b & 15);
                if (!idx)
                    continue;
                color = Pal16(256 + pal * 16 + idx);
            }

            if (mode == 2) {
                sObjWin[px] = 1;
                continue;
            }
            /* Lower priority value wins; on a tie the lower OAM index (drawn first) stays. */
            if (prio < sObjPrio[px]) {
                sObj[px] = color;
                sObjPrio[px] = (uint8_t)prio;
                sObjSemi[px] = mode == 1;
            }
        }
    }
}

/* ------------------------------------------------------------------ */
/* Windows and composition                                              */
/* ------------------------------------------------------------------ */

static int InRange(int v, int a, int b) {
    /* a = start (inclusive), b = end (exclusive); a > b wraps around. */
    if (a <= b)
        return v >= a && v < b;
    return v >= a || v < b;
}

static void BuildWindowMask(int line) {
    uint16_t dispcnt = Io16(DISPCNT);
    int x;

    if (!(dispcnt & 0xE000)) {
        memset(sWinMask, 0x3F, sizeof(sWinMask));
        return;
    }
    {
        uint16_t winin = Io16(WININ), winout = Io16(WINOUT);
        int w0 = (dispcnt & 0x2000) && InRange(line, Io16(WIN0V) >> 8, Io16(WIN0V) & 0xFF);
        int w1 = (dispcnt & 0x4000) && InRange(line, Io16(WIN1V) >> 8, Io16(WIN1V) & 0xFF);
        int w0l = Io16(WIN0H) >> 8, w0r = Io16(WIN0H) & 0xFF;
        int w1l = Io16(WIN1H) >> 8, w1r = Io16(WIN1H) & 0xFF;

        for (x = 0; x < W; x++) {
            if (w0 && InRange(x, w0l, w0r))
                sWinMask[x] = winin & 0x3F;
            else if (w1 && InRange(x, w1l, w1r))
                sWinMask[x] = (winin >> 8) & 0x3F;
            else if ((dispcnt & 0x8000) && sObjWin[x])
                sWinMask[x] = (winout >> 8) & 0x3F;
            else
                sWinMask[x] = winout & 0x3F;
        }
    }
}

static inline uint16_t Blend(uint16_t a, uint16_t b, int eva, int evb) {
    int r = ((a & 31) * eva + (b & 31) * evb) >> 4;
    int g = (((a >> 5) & 31) * eva + ((b >> 5) & 31) * evb) >> 4;
    int bl = (((a >> 10) & 31) * eva + ((b >> 10) & 31) * evb) >> 4;
    if (r > 31) r = 31;
    if (g > 31) g = 31;
    if (bl > 31) bl = 31;
    return (uint16_t)(r | (g << 5) | (bl << 10));
}

static inline uint16_t Brighten(uint16_t c, int evy) {
    int r = c & 31, g = (c >> 5) & 31, b = (c >> 10) & 31;
    r += ((31 - r) * evy) >> 4;
    g += ((31 - g) * evy) >> 4;
    b += ((31 - b) * evy) >> 4;
    return (uint16_t)(r | (g << 5) | (b << 10));
}

static inline uint16_t Darken(uint16_t c, int evy) {
    int r = c & 31, g = (c >> 5) & 31, b = (c >> 10) & 31;
    r -= (r * evy) >> 4;
    g -= (g * evy) >> 4;
    b -= (b * evy) >> 4;
    return (uint16_t)(r | (g << 5) | (b << 10));
}

static void Compose(int line, int enabledBgs) {
    uint16_t bldcnt = Io16(BLDCNT);
    int effect = (bldcnt >> 6) & 3;
    int eva = Io16(BLDALPHA) & 31, evb = (Io16(BLDALPHA) >> 8) & 31;
    int evy = Io16(BLDY) & 31;
    uint16_t backdrop = Pal16(0);
    uint32_t* dst = gPcFramebuffer + line * W;
    int order[4], count = 0, prio, bg, x;

    if (eva > 16) eva = 16;
    if (evb > 16) evb = 16;
    if (evy > 16) evy = 16;

    /* BGs sorted by priority, then by index. */
    for (prio = 0; prio < 4; prio++)
        for (bg = 0; bg < 4; bg++)
            if ((enabledBgs & (1 << bg)) && (Io16(BG0CNT + bg * 2) & 3) == prio)
                order[count++] = bg;

    for (x = 0; x < W; x++) {
        uint8_t mask = sWinMask[x];
        int topLayer = L_BD, secondLayer = L_BD;
        uint16_t top = backdrop, second = backdrop;
        int found = 0, i;
        uint16_t out;

        /* Walk layers front to back (by priority; OBJ before BGs of equal
         * priority; lower BG index first) and keep the first two opaque ones. */
        for (prio = 0; prio < 4 && found < 2; prio++) {
            if (sObj[x] != TRANSPARENT && (mask & 0x10) && sObjPrio[x] == prio) {
                if (found == 0) { top = sObj[x]; topLayer = L_OBJ; }
                else { second = sObj[x]; secondLayer = L_OBJ; }
                found++;
            }
            for (i = 0; i < count && found < 2; i++) {
                bg = order[i];
                if ((Io16(BG0CNT + bg * 2) & 3) != prio)
                    continue;
                if ((mask & (1 << bg)) && sBg[bg][x] != TRANSPARENT) {
                    if (found == 0) { top = sBg[bg][x]; topLayer = bg; }
                    else { second = sBg[bg][x]; secondLayer = bg; }
                    found++;
                }
            }
        }

        out = top;
        if (mask & 0x20) {
            int topIs1st = (bldcnt >> topLayer) & 1;
            int secondIs2nd = (bldcnt >> (8 + secondLayer)) & 1;

            if (topLayer == L_OBJ && sObjSemi[x] && secondIs2nd) {
                out = Blend(top, second, eva, evb);
            } else if (topIs1st) {
                if (effect == 1 && secondIs2nd)
                    out = Blend(top, second, eva, evb);
                else if (effect == 2)
                    out = Brighten(top, evy);
                else if (effect == 3)
                    out = Darken(top, evy);
            }
        }
        dst[x] = sColorLut[out];
    }
}

/* ------------------------------------------------------------------ */

void PcRenderScanline(int line) {
    uint16_t dispcnt = Io16(DISPCNT);
    int mode = dispcnt & 7;
    int enabled = (dispcnt >> 8) & 15;
    int bg;

    if (!sLutReady)
        InitLut();

    LatchAffine(0, line);
    LatchAffine(1, line);

    if (dispcnt & 0x80) { /* forced blank shows white */
        uint32_t* dst = gPcFramebuffer + line * W;
        for (bg = 0; bg < W; bg++)
            dst[bg] = 0xFFFFFFFFu;
        StepAffine(0);
        StepAffine(1);
        return;
    }

    switch (mode) {
        case 0:
            break;
        case 1:
            enabled &= 0x7;
            break;
        case 2:
            enabled &= 0xC;
            break;
        case 3:
        case 4:
        case 5:
            enabled &= 0x4;
            break;
        default:
            enabled = 0;
            break;
    }

    for (bg = 0; bg < 4; bg++) {
        if (!(enabled & (1 << bg)))
            continue;
        if (mode >= 3)
            RenderBitmapBg(mode);
        else if (mode == 0 || (mode == 1 && bg < 2))
            RenderTextBg(bg, line);
        else
            RenderAffineBg(bg);
    }

    RenderObjs(line, mode >= 3);
    BuildWindowMask(line);
    Compose(line, enabled);

    StepAffine(0);
    StepAffine(1);
}
