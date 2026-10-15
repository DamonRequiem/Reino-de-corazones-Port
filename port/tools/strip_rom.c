/*
 * strip_rom.c - takes the ROM's contents out of a linked port executable.
 *
 * All data the build extracted from the ROM (graphics, music, maps, text,
 * movies) sits in the executable's "romdat" section (convert_data.py).
 * This tool finds where every byte of that section comes from in the ROM and
 * writes:
 *   - a map: (section offset, ROM offset, length) copies, plus the few bytes
 *     that are not ROM content (pointers the linker filled in, padding), and
 *     SHA-1 checksums of the ROM and of the finished section;
 *   - the executable with that section emptied: no ROM data at all.
 * At start-up port/pc_romdata.c rebuilds the section from the player's ROM.
 *
 * usage: strip_rom exe rom region out_exe out_map
 * Host tool (built and run by port/build.py), not part of the game.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../pc_sha1.h"

#define KEY 8
#define MAX_CAND 48
#define HBITS 25

static uint8_t* ReadFile(const char* path, size_t* size) {
    FILE* f = fopen(path, "rb");
    uint8_t* d;
    if (!f) { fprintf(stderr, "strip_rom: cannot open %s\n", path); exit(1); }
    fseek(f, 0, SEEK_END);
    *size = (size_t)ftell(f);
    fseek(f, 0, SEEK_SET);
    d = malloc(*size + 16);
    if (fread(d, 1, *size, f) != *size) { fprintf(stderr, "strip_rom: read error\n"); exit(1); }
    fclose(f);
    return d;
}

static size_t sRawSize;

static uint32_t U32(const uint8_t* p) { return p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24; }
static uint16_t U16(const uint8_t* p) { return (uint16_t)(p[0] | p[1] << 8); }

static int FindSection(const uint8_t* d, const char* name, uint32_t* off, uint32_t* size) {
    if (!memcmp(d, "\x7f" "ELF", 4)) {
        uint32_t shoff = U32(d + 0x20);
        uint16_t shentsize = U16(d + 0x2E), shnum = U16(d + 0x30), shstrndx = U16(d + 0x32);
        uint32_t stroff = U32(d + shoff + shstrndx * shentsize + 16);
        int i;
        for (i = 0; i < shnum; i++) {
            const uint8_t* s = d + shoff + i * shentsize;
            if (!strcmp((const char*)d + stroff + U32(s), name)) {
                *off = U32(s + 16);
                *size = U32(s + 20);
                return 1;
            }
        }
    } else if (d[0] != 'M' || d[1] != 'Z') {
        /* Raw image (the 32-bit core's memory, port/wasm/build_core.py). */
        if (strcmp(name, "wasmdata"))
            return 0;
        *off = 0;
        *size = (uint32_t)sRawSize;
        return 1;
    } else if (d[0] == 'M' && d[1] == 'Z') {
        uint32_t pe = U32(d + 0x3C);
        uint16_t nsec = U16(d + pe + 6), opt = U16(d + pe + 20);
        int i;
        for (i = 0; i < nsec; i++) {
            const uint8_t* s = d + pe + 24 + opt + i * 40;
            char nm[9] = {0};
            memcpy(nm, s, 8);
            if (nm[0] == '.' && !strcmp(nm + 1, name)) {
                uint32_t vsize = U32(s + 8), rawsize = U32(s + 16);
                *off = U32(s + 20);
                *size = vsize < rawsize ? vsize : rawsize;
                return 1;
            }
        }
    }
    return 0;
}

static void Put32(uint8_t* p, uint32_t v) { p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24); }

/* PE: turn the emptied section into uninitialised data (the loader fills it
 * with zeros) and remove its 30 MB of zeros from the file. */
static size_t DropPeSection(uint8_t* d, size_t size, const char* name) {
    uint32_t pe = U32(d + 0x3C);
    uint16_t nsec = U16(d + pe + 6), opt = U16(d + pe + 20);
    uint8_t* sec = d + pe + 24 + opt;
    uint32_t ptr = 0, raw = 0;
    int i, k = -1;
    for (i = 0; i < nsec; i++)
        if (!strncmp((const char*)sec + i * 40, name, 8))
            k = i;
    if (k < 0)
        return size;
    raw = U32(sec + k * 40 + 16);
    ptr = U32(sec + k * 40 + 20);
    if (!raw || (size_t)ptr + raw > size)
        return size;
    memmove(d + ptr, d + ptr + raw, size - ptr - raw);
    for (i = 0; i < nsec; i++) {
        uint8_t* s = sec + i * 40;
        if (i != k && U32(s + 20) > ptr)
            Put32(s + 20, U32(s + 20) - raw);
    }
    Put32(sec + k * 40 + 16, 0);                      /* SizeOfRawData */
    Put32(sec + k * 40 + 20, 0);                      /* PointerToRawData */
    Put32(sec + k * 40 + 36, 0xC0000080);             /* uninitialised, read, write */
    if (U32(d + pe + 12) > ptr)                       /* PointerToSymbolTable */
        Put32(d + pe + 12, U32(d + pe + 12) - raw);
    Put32(d + pe + 24 + 8, U32(d + pe + 24 + 8) - raw);   /* SizeOfInitializedData */
    Put32(d + pe + 24 + 12, U32(d + pe + 24 + 12) + raw); /* SizeOfUninitializedData */
    return size - raw;
}

/* ELF (32-bit, Android's libgame.so): when romdat and romdatw end the file
 * part of their writable segment, make them NOBITS (the loader zero-fills
 * them like .bss) and cut their bytes out of the file. */
static size_t DropElfSections(uint8_t* d, size_t size) {
    uint32_t shoff = U32(d + 0x20), phoff = U32(d + 0x1C);
    uint16_t phentsize = U16(d + 0x2A), phnum = U16(d + 0x2C);
    uint16_t shentsize = U16(d + 0x2E), shnum = U16(d + 0x30);
    uint32_t a0, s0, a1, s1, start, end, cut;
    int i, done = 0;
    if (d[4] != 1 || !FindSection(d, "romdat", &a0, &s0) || !FindSection(d, "romdatw", &a1, &s1) || a1 < a0)
        return size;
    start = a0;
    end = a1 + s1;
    for (i = 0; i < phnum; i++) {
        uint8_t* ph = d + phoff + i * phentsize;
        if (U32(ph) == 1 /* PT_LOAD */ && U32(ph + 4) <= start && U32(ph + 4) + U32(ph + 16) == end) {
            Put32(ph + 16, start - U32(ph + 4)); /* p_filesz: the rest is zero-filled */
            done = 1;
        }
    }
    if (!done) {
        fprintf(stderr, "strip_rom: romdat is not at the end of its segment; ELF left full size\n");
        return size;
    }
    cut = (end - start) & ~15u; /* keep later sections' alignment */
    for (i = 0; i < shnum; i++) {
        uint8_t* sh = d + shoff + i * shentsize;
        const char* nm = (const char*)d + U32(d + shoff + U16(d + 0x32) * shentsize + 16) + U32(sh);
        if (!strcmp(nm, "romdat") || !strcmp(nm, "romdatw")) {
            Put32(sh + 4, 8); /* SHT_NOBITS */
            Put32(sh + 16, start);
        } else if (U32(sh + 16) >= end) {
            Put32(sh + 16, U32(sh + 16) - cut);
        }
    }
    memmove(d + end - cut, d + end, size - end);
    if (shoff >= end)
        Put32(d + 0x20, shoff - cut);
    return size - cut;
}

static const uint8_t* sRom;
static size_t sRomSize;
static int32_t* sHead;
static int32_t* sNext;

static uint32_t Hash(const uint8_t* p) {
    uint64_t k;
    memcpy(&k, p, 8);
    k *= 0x9E3779B97F4A7C15ull;
    return (uint32_t)(k >> (64 - HBITS));
}

static size_t Run(const uint8_t* d, size_t dn, size_t a, size_t b, size_t limit) {
    size_t n = 0;
    while (n < limit && a + n < dn && b + n < sRomSize && d[a + n] == sRom[b + n])
        n++;
    return n;
}

typedef struct { uint32_t so, ro, n; } Copy;
typedef struct { uint32_t so, n; } Lit;

typedef struct {
    const char* name;
    uint32_t off, size;
    Copy* copies;
    Lit* lits;
    size_t nc, nl, litBytes, longest;
    uint8_t sha[20];
} Section;

/* Finds where each byte of D[0..size) comes from in the ROM. */
static void MapSection(const uint8_t* D, Section* S) {
    size_t size = S->size, pos = 0, n;
    int64_t cur = -1, litStart = -1;
    S->copies = malloc(sizeof(Copy) * (size / 4 + 16));
    S->lits = malloc(sizeof(Lit) * (size / 4 + 16));
    S->nc = S->nl = S->litBytes = S->longest = 0;
#define FLUSH_LIT()                                                    \
    if (litStart >= 0) {                                               \
        Lit* L = &S->lits[S->nl++];                                    \
        L->so = (uint32_t)litStart;                                    \
        L->n = (uint32_t)(pos - litStart);                             \
        S->litBytes += L->n;                                           \
        if (L->n > S->longest) S->longest = L->n;                      \
        litStart = -1;                                                 \
    }
    while (pos < size) {
        if (cur >= 0 && (size_t)cur < sRomSize && D[pos] == sRom[cur]) {
            n = Run(D, size, pos, (size_t)cur, (size_t)-1);
            FLUSH_LIT();
            if (S->nc && S->copies[S->nc - 1].so + S->copies[S->nc - 1].n == pos &&
                S->copies[S->nc - 1].ro + S->copies[S->nc - 1].n == cur)
                S->copies[S->nc - 1].n += (uint32_t)n;
            else {
                Copy* C = &S->copies[S->nc++];
                C->so = (uint32_t)pos;
                C->ro = (uint32_t)cur;
                C->n = (uint32_t)n;
            }
            pos += n;
            cur += (int64_t)n;
            continue;
        }
        {
            int64_t best = -1;
            size_t bestLen = 0;
            if (pos + KEY <= size) {
                int32_t c = sHead[Hash(D + pos)];
                int tried = 0;
                while (c >= 0 && tried < MAX_CAND) {
                    if (!memcmp(sRom + c, D + pos, KEY)) {
                        size_t len = Run(D, size, pos, (size_t)c, 1 << 16);
                        tried++;
                        if (len > bestLen) {
                            bestLen = len;
                            best = c;
                        }
                    }
                    c = sNext[c];
                }
            }
            if (best >= 0) {
                cur = best;
                continue;
            }
        }
        /* Not ROM content (a pointer the linker filled in, padding...). */
        if (litStart < 0)
            litStart = (int64_t)pos;
        pos++;
        if (cur >= 0)
            cur++;
    }
    FLUSH_LIT();
#undef FLUSH_LIT
}

/* Map file (all little-endian):
 *   "RDCMAP2\0", region[4], ROM SHA-1[20], u32 section count, then per
 *   section: name[8], u32 size, SHA-1[20] of the finished contents,
 *   u32 copies, u32 literal runs, copies {u32 offset, u32 ROM offset,
 *   u32 length}..., literal runs {u32 offset, u32 length, bytes}... */
int main(int argc, char** argv) {
    static const char* const names[3] = {"romdat", "romdatw", "wasmdata"};
    Section secs[3];
    int ns = 0, k;
    size_t exeSize, i;
    uint8_t* exe;
    uint8_t romSha[20];
    FILE* f;

    if (argc != 6) {
        fprintf(stderr, "usage: strip_rom exe rom region out_exe out_map\n");
        return 1;
    }
    exe = ReadFile(argv[1], &exeSize);
    sRawSize = exeSize;
    sRom = ReadFile(argv[2], &sRomSize);

    /* Index every 8-byte window of the ROM. */
    sHead = malloc(sizeof(int32_t) << HBITS);
    sNext = malloc(sizeof(int32_t) * sRomSize);
    memset(sHead, 0xFF, sizeof(int32_t) << HBITS);
    for (i = sRomSize - KEY + 1; i-- > 0;) {
        uint32_t h = Hash(sRom + i);
        sNext[i] = sHead[h];
        sHead[h] = (int32_t)i;
    }

    for (k = 0; k < 3; k++) {
        Section* S = &secs[ns];
        uint8_t* rebuilt;
        const uint8_t* D;
        if (!FindSection(exe, names[k], &S->off, &S->size))
            continue;
        S->name = names[k];
        D = exe + S->off;
        MapSection(D, S);
        /* Check: rebuild the section from the table alone. */
        rebuilt = calloc(S->size + 1, 1);
        for (i = 0; i < S->nc; i++)
            memcpy(rebuilt + S->copies[i].so, sRom + S->copies[i].ro, S->copies[i].n);
        for (i = 0; i < S->nl; i++)
            memcpy(rebuilt + S->lits[i].so, D + S->lits[i].so, S->lits[i].n);
        if (memcmp(rebuilt, D, S->size)) {
            fprintf(stderr, "strip_rom: rebuilt %s differs (bug)\n", S->name);
            return 1;
        }
        free(rebuilt);
        PcSha1(D, S->size, S->sha);
        printf("%s: %u bytes = %zu from the ROM in %zu copies + %zu other bytes in %zu runs (longest %zu)\n",
               S->name, S->size, S->size - S->litBytes, S->nc, S->litBytes, S->nl, S->longest);
        ns++;
    }
    if (!ns) {
        fprintf(stderr, "strip_rom: no romdat section\n");
        return 1;
    }

    PcSha1(sRom, sRomSize, romSha);
    f = fopen(argv[5], "wb");
    {
        char region[4] = {0};
        uint32_t v;
        memcpy(region, argv[3], strlen(argv[3]) < 4 ? strlen(argv[3]) : 4);
        fwrite("RDCMAP2", 1, 8, f);
        fwrite(region, 1, 4, f);
        fwrite(romSha, 1, 20, f);
        v = (uint32_t)ns; fwrite(&v, 4, 1, f);
        for (k = 0; k < ns; k++) {
            Section* S = &secs[k];
            char nm[8] = {0};
            memcpy(nm, S->name, strlen(S->name));
            fwrite(nm, 1, 8, f);
            fwrite(&S->size, 4, 1, f);
            fwrite(S->sha, 1, 20, f);
            v = (uint32_t)S->nc; fwrite(&v, 4, 1, f);
            v = (uint32_t)S->nl; fwrite(&v, 4, 1, f);
            for (i = 0; i < S->nc; i++)
                fwrite(&S->copies[i], 12, 1, f);
            for (i = 0; i < S->nl; i++) {
                fwrite(&S->lits[i], 8, 1, f);
                fwrite(exe + S->off + S->lits[i].so, 1, S->lits[i].n, f);
            }
        }
    }
    fclose(f);

    for (k = 0; k < ns; k++)
        memset(exe + secs[k].off, 0, secs[k].size);
    if (exe[0] == 'M' && exe[1] == 'Z') {
        exeSize = DropPeSection(exe, exeSize, ".romdat");
        exeSize = DropPeSection(exe, exeSize, ".romdatw");
    } else if (!memcmp(exe, "\x7f" "ELF", 4) && U16(exe + 0x10) == 3 /* ET_DYN */) {
        exeSize = DropElfSections(exe, exeSize);
    }
    f = fopen(argv[4], "wb");
    fwrite(exe, 1, exeSize, f);
    fclose(f);
    return 0;
}
