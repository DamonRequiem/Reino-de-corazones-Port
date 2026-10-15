/*
 * pc_transform.c
 * C version of asm/transform.s: the 8-point integer transform and the
 * square-root quantizer of the block audio codec (src/lib/audio_block_codec.c,
 * used by the staff roll / credits audio). Reached through the veneers
 * func_081213C4 / CC / D4 exactly as on the GBA.
 *
 * Arithmetic is 32-bit two's complement like the ARM code: products and
 * sums wrap (done in u32), right shifts are arithmetic.
 */
#include "types.h"
#include "lib/audio_block_codec.h"

extern const u8 gUnk_09C43708[4096]; /* square-root table */

static const int sBandShift[8] = { 8, 8, 9, 9, 10, 11, 12, 13 };

#define ADD(a, b) ((s32)((u32)(a) + (u32)(b)))
#define SUB(a, b) ((s32)((u32)(a) - (u32)(b)))
#define MUL(a, k) ((s32)((u32)(a) * (u32)(k)))

static s32 Quantize(s32 x, int sh) {
    s32 m = x <= 0 ? SUB(0, x) : x;
    s32 q = gUnk_09C43708[m >> sh];
    return x <= 0 ? -q : q;
}

static s32 Dequantize(s32 x, int sh) {
    u32 v = ((u32)x * (u32)x) << sh;
    return x <= 0 ? (s32)(0u - v) : (s32)v;
}

static void ForwardTransform(const s32* in, s32* out) {
    s32 x0 = in[0], x1 = in[1], x2 = in[2], x3 = in[3], x4 = in[4], x5 = in[5], x6 = in[6], x7 = in[7];
    s32 sl = ADD(x0, x7), lr = ADD(x3, x4), fp = ADD(x1, x6), ip = ADD(x2, x5);
    s32 r2 = ADD(sl, lr), r5 = SUB(sl, lr), r3 = ADD(fp, ip), r4 = SUB(fp, ip);

    r2 = ADD(r2, r3);
    r3 = SUB(r2 >> 1, r3);
    r4 = SUB(r4, MUL(r5, 3) >> 3);
    r5 = ADD(r5, MUL(r4, 3) >> 3);
    out[0] = r2;
    out[4] = r3;
    out[2] = r5;
    out[6] = r4;

    /* The ARM code reloads the input here (it may alias the output). */
    x0 = in[0], x1 = in[1], x2 = in[2], x3 = in[3], x4 = in[4], x5 = in[5], x6 = in[6], x7 = in[7];
    sl = SUB(x3, x4);
    fp = SUB(x2, x5);
    ip = SUB(x1, x6);
    lr = SUB(x0, x7);
    ip = ADD(ip, MUL(fp, 3) >> 3);
    fp = SUB(MUL(ip, 5) >> 3, fp);
    r2 = ADD(sl, fp);
    r3 = SUB(sl, fp);
    r4 = SUB(lr, ip);
    r5 = ADD(lr, ip);
    r2 = SUB(r2, r5 >> 3);
    r3 = ADD(r3, MUL(r4, 7) >> 3);
    r4 = SUB(r4, r3 >> 1);
    out[1] = r5;
    out[3] = r4;
    out[5] = r3;
    out[7] = r2;
}

static void InverseTransform(const s32* in, s32* out) {
    s32 r2 = in[0], r3 = in[1], r4 = in[2], r5 = in[3], r6 = in[4], r7 = in[5], r8 = in[6], r9 = in[7];
    s32 sl, fp, ip, lr;

    r5 = ADD(r5, r7 >> 1);
    r7 = SUB(r7, MUL(r5, 7) >> 3);
    r9 = ADD(r9, r3 >> 3);
    sl = ADD(r9, r7);
    fp = SUB(r9, r7);
    ip = SUB(r3, r5);
    lr = ADD(r3, r5);
    fp = SUB(MUL(ip, 5) >> 3, fp);
    ip = SUB(ip, MUL(fp, 3) >> 3);
    r4 = SUB(r4, MUL(r8, 3) >> 3);
    r8 = ADD(r8, MUL(r4, 3) >> 3);
    r6 = SUB(r2 >> 1, r6);
    r2 = SUB(r2, r6);
    r3 = ADD(r2, r4);
    r5 = ADD(r6, r8);
    r7 = SUB(r6, r8);
    r9 = SUB(r2, r4);
    out[0] = ADD(r3, lr);
    out[1] = ADD(r5, ip);
    out[2] = ADD(r7, fp);
    out[3] = ADD(r9, sl);
    out[4] = SUB(r9, sl);
    out[5] = SUB(r7, fp);
    out[6] = SUB(r5, ip);
    out[7] = SUB(r3, lr);
}

/* Divides by 4, rounding toward zero. */
static void DivideBy4(s32* v) {
    int i;
    for (i = 0; i < 8; i++)
        v[i] = v[i] > 0 ? v[i] >> 2 : -(SUB(0, v[i]) >> 2);
}

static s32 ShiftLeft(s32 v, s32 sh) {
    u32 n = (u32)sh & 0xFF; /* ARM LSL by register */
    return n >= 32 ? 0 : (s32)((u32)v << n);
}

/* func_08109AAC: forward transform of 8 samples, then quantized twice
 * (the second pass codes the doubled residual of the first). */
void func_081213CC(s32* in, s32* out) {
    s32 v[8];
    int i;

    ForwardTransform(in, out);
    for (i = 0; i < 8; i++) {
        s32 x = out[i];
        v[i] = SUB(MUL(x, 2), Dequantize(Quantize(x, sBandShift[i]), sBandShift[i]));
    }
    for (i = 0; i < 8; i++)
        out[i] = Quantize(v[i], sBandShift[i]);
}

/* func_08109BE0: scales each coefficient by its shift, inverse transform. */
void func_081213C4(s32* in, s32* out, const s32* shifts) {
    s32 v[8];
    int i;

    for (i = 0; i < 8; i++)
        v[i] = ShiftLeft(in[i], shifts[i]);
    for (i = 0; i < 8; i++)
        out[i] = v[i];
    InverseTransform(out, out);
    DivideBy4(out);
}

/* func_08109C68: dequantizes 8 coefficients, inverse transform. */
void func_081213D4(s32* in, s32* out) {
    s32 v[8];
    int i;

    for (i = 0; i < 8; i++)
        v[i] = Dequantize(in[i], sBandShift[i]);
    for (i = 0; i < 8; i++)
        out[i] = v[i];
    InverseTransform(out, out);
    DivideBy4(out);
}
