/*
 * pc_movie_codec.c
 * C version of asm/movie_codec.s, the cutscene decoders.
 *
 * On the GBA these are hand-written ARM routines copied to IWRAM; the
 * delta decoder even has its instructions patched for the frame width
 * (src/lib/movie_player.c). Here the frame size is plain state.
 *
 * Video is RGB555, 16-bit pixels:
 *  - Key frames: one 16x16 block per 8 bytes (two colours, two blends and
 *    a 2-bit index for each of 4x4 sample points), then the samples are
 *    interpolated horizontally and vertically.
 *  - Delta frames: 8x8 blocks coded as a binary tree down to 2x1 / 1x2,
 *    each node copying the previous frame (in place or moved), adding a
 *    brightness offset, filling one colour or splitting in two.
 *  - Post-process: a light filter across the 8x8 block edges.
 * Audio is 8-bit PCM made from 16-bit PCM or from 2-bit ADPCM.
 *
 * Every operation keeps the ARM code's exact integer behaviour, including
 * the carries between the two pixels of a 32-bit word, so the frames are
 * bit-identical to the console's (verified against the original ARM code
 * on every frame of every movie).
 */
#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

static inline u16 Rd16(const u8* p) { u16 v; memcpy(&v, p, 2); return v; }
static inline u32 Rd32(const u8* p) { u32 v; memcpy(&v, p, 4); return v; }
static inline void Wr16(u8* p, u32 v) { u16 h = (u16)v; memcpy(p, &h, 2); }
static inline void Wr32(u8* p, u32 v) { memcpy(p, &v, 4); }

#define MASK_HI 0x7BDF7BDFu  /* each channel without its lowest bit (G, B) */
#define MASK_LO 0x04200420u  /* the bits MASK_HI removes */

static s32 sWidth, sHeight;

/* (2a + b) / 3 for 5-bit channels, as in movie_player.c's constant table. */
static const u8 sThirds[96] = {
    0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5,
    5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10,
    11, 11, 11, 12, 12, 12, 13, 13, 13, 14, 14, 14, 15, 15, 15, 16,
    16, 16, 17, 17, 17, 18, 18, 18, 19, 19, 19, 20, 20, 20, 21, 21,
    21, 22, 22, 22, 23, 23, 23, 24, 24, 24, 25, 25, 25, 26, 26, 26,
    27, 27, 27, 28, 28, 28, 29, 29, 29, 30, 30, 30, 31, 31, 0, 0,
};

void PcMovieVideoCodecSetup(s32 w, s32 h) {
    sWidth = w;
    sHeight = h;
}

/* ------------------------------------------------------------------ */
/* Key frames                                                           */
/* ------------------------------------------------------------------ */

static void KeyBlocks(u8* dst, s32 w, s32 h, u8* src) {
    s32 bx, by, k, s;
    for (by = 0; by < h; by += 16) {
        for (bx = 0; bx < w; bx += 16) {
            u32 c0 = Rd16(src), c1 = Rd16(src + 2);
            u32 m0 = 0, m1 = 0, idx;
            for (s = 10; s >= 0; s -= 5) {
                u32 a = (c0 >> s) & 31, b = (c1 >> s) & 31;
                m0 = (m0 << 5) + sThirds[b + (a << 1)];
                m1 = (m1 << 5) + sThirds[a + (b << 1)];
            }
            idx = Rd32(src + 4);
            /* The blends overwrite the index word: palette = c0 c1 m0 m1. */
            Wr16(src + 4, m0);
            Wr16(src + 6, m1);
            for (k = 0; k < 16; k++) {
                u32 sel = (idx >> (k * 2)) & 3;
                u8* p = dst + ((by + (k >> 2) * 4) * w + bx + (k & 3) * 4) * 2;
                Wr16(p, Rd16(src + sel * 2));
            }
            src += 8;
        }
    }
}

/* Fills the 3 pixels between horizontal samples on every 4th row. */
static void KeyHorizontal(u8* dst, s32 w, s32 h) {
    s32 y, s;
    for (y = 0; y < h; y += 4) {
        u8* p = dst + y * w * 2;
        u32 prev = Rd16(p), prevLo = prev & MASK_LO;
        prev &= MASK_HI;
        for (s = 0; s < w / 4 - 1; s++) {
            u8* q = p + s * 8;
            u32 next = Rd16(q + 8), nextLo = next & MASK_LO, mid;
            next &= MASK_HI;
            mid = ((prev + next) >> 1) | prevLo;
            Wr16(q + 4, mid);
            mid &= MASK_HI;
            Wr16(q + 2, ((prev + mid) >> 1) | prevLo);
            Wr16(q + 6, ((mid + next) >> 1) | nextLo);
            prev = next;
            prevLo = nextLo;
        }
        {
            u8* q = p + (w - 4) * 2;
            u32 last = Rd16(q);
            Wr16(q + 2, last);
            Wr16(q + 4, last);
            Wr16(q + 6, last);
        }
    }
}

/* Fills the 3 rows between sampled rows, two pixels (one word) at a time. */
static void KeyVertical(u8* dst, s32 w, s32 h) {
    s32 x, s, row = w * 2;
    for (x = 0; x < w; x += 2) {
        u8* p = dst + x * 2;
        u32 prev = Rd32(p), prevLo = prev & MASK_LO;
        prev &= MASK_HI;
        for (s = 0; s < h / 4 - 1; s++) {
            u8* q = p + s * 4 * row;
            u32 next = Rd32(q + 4 * row), nextLo = next & MASK_LO, mid;
            next &= MASK_HI;
            mid = ((prev + next) >> 1) | prevLo;
            Wr32(q + 2 * row, mid);
            mid &= MASK_HI;
            Wr32(q + row, ((prev + mid) >> 1) | prevLo);
            Wr32(q + 3 * row, ((mid + next) >> 1) | nextLo);
            prev = next;
            prevLo = nextLo;
        }
        {
            u8* q = p + (h - 4) * row;
            u32 last = Rd32(q);
            Wr32(q + row, last);
            Wr32(q + 2 * row, last);
            Wr32(q + 3 * row, last);
        }
    }
}

void PcMovieDecodeKeyFrame(void* dst, u32 w, u32 h, void* src) {
    KeyBlocks((u8*)dst, (s32)w, (s32)h, (u8*)src);
    KeyHorizontal((u8*)dst, (s32)w, (s32)h);
    KeyVertical((u8*)dst, (s32)w, (s32)h);
}

/* Softens the 8x8 block edges: first the vertical edges of every row
 * (pixel by pixel), then the horizontal edges (word by word). */
void PcMoviePostProcessFrame(void* buf, u32 w, u32 h) {
    u8* base = (u8*)buf;
    s32 W = (s32)w, H = (s32)h, x, y;

    for (y = 0; y < H; y++) {
        u8* p = base + y * W * 2;
        for (x = 0; x < W - 8; x += 8) {
            u32 a = Rd16(p + (x + 7) * 2), b = Rd16(p + (x + 8) * 2);
            Wr16(p + (x + 8) * 2, (((a & MASK_HI) + (b & MASK_HI)) >> 1) | (b & MASK_LO));
        }
    }
    for (y = 8; y < H; y += 8) {
        u8* above = base + (y - 1) * W * 2;
        u8* p = base + y * W * 2;
        for (x = 0; x < W; x += 2) {
            u32 a = Rd32(above + x * 2), b = Rd32(p + x * 2);
            Wr32(p + x * 2, (((a & MASK_HI) + (b & MASK_HI)) >> 1) | (b & MASK_LO));
        }
    }
}

/* ------------------------------------------------------------------ */
/* Delta frames                                                         */
/* ------------------------------------------------------------------ */

typedef struct {
    const u8* bits;  /* control bits, MSB first in 32-bit words */
    u32 bitBuf;
    int bitCount;
    const u8* values; /* 16-bit colours / brightness offsets */
    const u8* moves;  /* 8-bit motion vectors */
    const u8* prev;   /* previous frame */
    u8* out;          /* frame being built */
    s32 row;          /* bytes per row */
} DeltaState;

static inline int Bit(DeltaState* d) {
    int b;
    if (d->bitCount == 0) {
        d->bitBuf = Rd32(d->bits);
        d->bits += 4;
        d->bitCount = 32;
    }
    b = (int)(d->bitBuf >> 31);
    d->bitBuf <<= 1;
    d->bitCount--;
    return b;
}

static inline u32 Value(DeltaState* d) {
    u32 v = Rd16(d->values);
    d->values += 2;
    return v;
}

/* Source of a moved copy: the previous frame displaced by -8..7 pixels. */
static inline const u8* MoveSource(DeltaState* d, s32 off) {
    u32 m = *d->moves++;
    s32 dy = (s32)(m >> 4) - 8, dx = (s32)(m & 15) - 8;
    return d->prev + off + (dy * sWidth + dx) * 2;
}

static void Copy(DeltaState* d, const u8* src, s32 off, int bw, int bh) {
    u8* dst = d->out + off;
    int y;
    for (y = 0; y < bh; y++)
        memcpy(dst + y * d->row, src + y * d->row, (size_t)bw * 2);
}

/* Copy plus a brightness offset. Two pixels wide or more, the ARM code adds
 * to whole words, so a carry out of the left pixel spills into the right. */
static void CopyAdd(DeltaState* d, const u8* src, s32 off, int bw, int bh, u32 add) {
    u8* dst = d->out + off;
    int x, y;
    for (y = 0; y < bh; y++) {
        if (bw == 1) {
            Wr16(dst + y * d->row, Rd16(src + y * d->row) + add);
            continue;
        }
        for (x = 0; x < bw; x += 2) {
            u32 v = (u32)Rd16(src + y * d->row + x * 2) | ((u32)Rd16(src + y * d->row + x * 2 + 2) << 16);
            Wr32(dst + y * d->row + x * 2, v + (add | (add << 16)));
        }
    }
}

static void Fill(DeltaState* d, s32 off, int bw, int bh, u32 colour) {
    u8* dst = d->out + off;
    int x, y;
    for (y = 0; y < bh; y++)
        for (x = 0; x < bw; x++)
            Wr16(dst + y * d->row + x * 2, colour);
}

static void Node(DeltaState* d, s32 off, int bw, int bh) {
    if (!Bit(d)) {
        if (!Bit(d))
            Copy(d, d->prev + off, off, bw, bh);
        else
            Copy(d, MoveSource(d, off), off, bw, bh);
        return;
    }
    if (bw * bh == 2) {
        /* 2x1 / 1x2: moved + offset, one colour, or two raw pixels. */
        if (!Bit(d)) {
            const u8* src = MoveSource(d, off);
            CopyAdd(d, src, off, bw, bh, Value(d));
        } else if (!Bit(d)) {
            Fill(d, off, bw, bh, Value(d));
        } else {
            u32 a = Value(d), b = Value(d);
            Wr16(d->out + off, a);
            Wr16(d->out + off + (bw == 2 ? 2 : d->row), b);
        }
        return;
    }
    if (!Bit(d)) {
        int topBottom;
        if (bh == 1)
            topBottom = 0;
        else if (bw == 1)
            topBottom = 1;
        else
            topBottom = !Bit(d);
        if (topBottom) {
            Node(d, off, bw, bh / 2);
            Node(d, off + (bh / 2) * d->row, bw, bh / 2);
        } else {
            Node(d, off, bw / 2, bh);
            Node(d, off + bw, bw / 2, bh); /* bw/2 pixels = bw bytes */
        }
        return;
    }
    if (!Bit(d)) {
        const u8* src = MoveSource(d, off);
        CopyAdd(d, src, off, bw, bh, Value(d));
    } else {
        Fill(d, off, bw, bh, Value(d));
    }
}

void PcMovieDecodeDeltaFrame(void* prev, void* out, void* data) {
    const u8* p = (const u8*)data;
    DeltaState d;
    s32 bx, by;

    d.bits = p + 4;
    d.bitCount = 0;
    d.bitBuf = 0;
    d.values = d.bits + Rd16(p);
    d.moves = d.values + Rd16(p + 2);
    d.prev = (const u8*)prev;
    d.out = (u8*)out;
    d.row = sWidth * 2;
    for (by = 0; by < sHeight / 8; by++)
        for (bx = 0; bx < sWidth / 8; bx++)
            Node(&d, by * 8 * d.row + bx * 16, 8, 8);
}

/* ------------------------------------------------------------------ */
/* Audio                                                                */
/* ------------------------------------------------------------------ */

/* 16-bit PCM -> 8-bit PCM; `bytes` counts the 16-bit input. */
void PcMovieDecodeAudioPcm16(void* src, void* dst, s32 bytes) {
    const u8* s = (const u8*)src;
    s8* o = (s8*)dst;
    do {
        *o++ = (s8)((s16)Rd16(s) >> 8);
        s += 2;
        bytes -= 2;
    } while (bytes != 0);
}

void PcMovieDecodeAudioNull(void* src, void* dst, s32 bytes) {
    (void)src;
    (void)dst;
    (void)bytes;
}

/* Step table built like MovieSetupAudioCodec: for each of 89 step sizes v,
 * the deltas for codes 0..3 are v/2, v+v/2, -v/2, -(v+v/2). */
static s16 sAdpcmSteps[89 * 4];
static int sAdpcmReady;

extern const u16 gUnk_09D6D1E4[89];

static void AdpcmInit(void) {
    int i, j;
    for (i = 0; i <= 0x58; i++) {
        s32 v = gUnk_09D6D1E4[i];
        for (j = 0; j <= 3; j++) {
            if (j <= 1)
                sAdpcmSteps[(i << 2) + j] = (s16)(j * v + v / 2);
            else
                sAdpcmSteps[(i << 2) + j] = (s16)(-((j & 1) * v + v / 2));
        }
    }
    sAdpcmReady = 1;
}

/* 2-bit ADPCM: 16-bit start value, 16-bit start step, then words of 16
 * codes (low bits first). `bytes` is twice the samples produced. */
void PcMovieDecodeAudioAdpcm(void* src, void* dst, s32 bytes) {
    const u8* s = (const u8*)src;
    s8* o = (s8*)dst;
    s32 value, step;
    u32 codes;
    int left = 16;

    if (!sAdpcmReady)
        AdpcmInit();
    value = (s16)Rd16(s);
    step = (s32)Rd16(s + 2) << 2;
    codes = Rd32(s + 4);
    s += 8;
    do {
        u32 c = codes & 3;
        value += sAdpcmSteps[c + step];
        *o++ = (s8)(value >> 8);
        step += (c & 1) ? 4 : -4;
        if (step < 0)
            step = 0;
        if (step > 352)
            step = 352;
        if (--left != 0) {
            codes >>= 2;
        } else {
            left = 16;
            codes = Rd32(s);
            s += 4;
            bytes -= 32;
        }
    } while (bytes != 0);
}
