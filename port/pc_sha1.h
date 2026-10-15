/*
 * pc_sha1.h
 * SHA-1 (FIPS 180-4), header-only. Used to recognise the player's ROM and to
 * check the data rebuilt from it (pc_romdata.c, tools/strip_rom.c).
 */
#ifndef PC_SHA1_H
#define PC_SHA1_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint32_t h[5];
    uint64_t length;
    uint8_t block[64];
    size_t used;
} PcSha1Ctx;

static inline uint32_t PcSha1Rol(uint32_t x, int n) { return (x << n) | (x >> (32 - n)); }

static inline void PcSha1Block(PcSha1Ctx* c, const uint8_t* p) {
    uint32_t w[80], a, b, d, e, f, k, t, cc;
    int i;
    for (i = 0; i < 16; i++)
        w[i] = (uint32_t)p[i * 4] << 24 | (uint32_t)p[i * 4 + 1] << 16 | (uint32_t)p[i * 4 + 2] << 8 | p[i * 4 + 3];
    for (i = 16; i < 80; i++)
        w[i] = PcSha1Rol(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
    a = c->h[0]; b = c->h[1]; cc = c->h[2]; d = c->h[3]; e = c->h[4];
    for (i = 0; i < 80; i++) {
        if (i < 20) { f = (b & cc) | (~b & d); k = 0x5A827999; }
        else if (i < 40) { f = b ^ cc ^ d; k = 0x6ED9EBA1; }
        else if (i < 60) { f = (b & cc) | (b & d) | (cc & d); k = 0x8F1BBCDC; }
        else { f = b ^ cc ^ d; k = 0xCA62C1D6; }
        t = PcSha1Rol(a, 5) + f + e + k + w[i];
        e = d; d = cc; cc = PcSha1Rol(b, 30); b = a; a = t;
    }
    c->h[0] += a; c->h[1] += b; c->h[2] += cc; c->h[3] += d; c->h[4] += e;
}

static inline void PcSha1Init(PcSha1Ctx* c) {
    c->h[0] = 0x67452301; c->h[1] = 0xEFCDAB89; c->h[2] = 0x98BADCFE; c->h[3] = 0x10325476; c->h[4] = 0xC3D2E1F0;
    c->length = 0;
    c->used = 0;
}

static inline void PcSha1Update(PcSha1Ctx* c, const void* data, size_t n) {
    const uint8_t* p = (const uint8_t*)data;
    c->length += n;
    if (c->used) {
        size_t take = 64 - c->used < n ? 64 - c->used : n;
        memcpy(c->block + c->used, p, take);
        c->used += take; p += take; n -= take;
        if (c->used == 64) { PcSha1Block(c, c->block); c->used = 0; }
    }
    while (n >= 64) { PcSha1Block(c, p); p += 64; n -= 64; }
    if (n) { memcpy(c->block, p, n); c->used = n; }
}

static inline void PcSha1Final(PcSha1Ctx* c, uint8_t out[20]) {
    uint64_t bits = c->length * 8;
    uint8_t pad = 0x80, zero = 0, len[8];
    int i;
    PcSha1Update(c, &pad, 1);
    while (c->used != 56)
        PcSha1Update(c, &zero, 1);
    for (i = 0; i < 8; i++)
        len[i] = (uint8_t)(bits >> (56 - i * 8));
    PcSha1Update(c, len, 8);
    for (i = 0; i < 20; i++)
        out[i] = (uint8_t)(c->h[i / 4] >> (24 - (i % 4) * 8));
}

static inline void PcSha1(const void* data, size_t n, uint8_t out[20]) {
    PcSha1Ctx c;
    PcSha1Init(&c);
    PcSha1Update(&c, data, n);
    PcSha1Final(&c, out);
}

#endif /* PC_SHA1_H */
