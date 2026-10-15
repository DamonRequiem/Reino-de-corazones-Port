/*
 * pc_romdata.c
 * Fills the game's data from the player's own ROM.
 *
 * The shipped engine carries the "romdat" section (every graphic, song, map,
 * text and movie) empty. port/tools/strip_rom.c recorded where each byte of
 * it lives in the ROM; this file reads that table (motor/<region>.map),
 * checks the ROM's SHA-1, copies the pieces into place and checks the SHA-1
 * of the result. Takes about a tenth of a second.
 */
#ifndef _WIN32
#define _GNU_SOURCE 1 /* dl_iterate_phdr */
#endif
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pc_platform.h"
#include "pc_sha1.h"

#ifdef _WIN32
#include <windows.h>
#endif

#ifndef _WIN32
extern char __start_romdat[] __attribute__((weak));
extern char __stop_romdat[] __attribute__((weak));
#endif

#ifndef _WIN32
extern char __start_romdatw[] __attribute__((weak));
extern char __stop_romdatw[] __attribute__((weak));
#endif

/* Not for the 64-bit build: there the data lives in the 32-bit core, whose
 * addresses are fixed (PC_SPLIT_CORE, port/wasm/). */
#if (defined(__ANDROID__) || defined(PC_ROMDATA_RELOC)) && !defined(PC_SPLIT_CORE)
#define PC_RELOCATE_ROMDATA 1
#endif

#if PC_RELOCATE_ROMDATA
/*
 * Android: the game is a shared library (libgame.so) loaded at an address
 * chosen at run time, so pointers stored in the game's data need the load
 * address added (R_ARM_RELATIVE relocations). The system loader did that to
 * the emptied sections already, on zeros. Here the sections are cleared,
 * rebuilt with the link-time values the map records (and checked against
 * the map's SHA-1), and only then are the pointers relocated again.
 */
#include <elf.h>
#include <link.h>

typedef struct {
    uint32_t* sites; /* sorted addresses of the 32-bit words to relocate */
    size_t count;
    uintptr_t base;
    int bad;         /* a relocation this code does not handle lies in the data */
} Relocs;

static Relocs sRelocs;
static int sRelocsLoaded;

static int FindSelf(struct dl_phdr_info* info, size_t size, void* data) {
    uintptr_t self = (uintptr_t)&PcRomDataSection;
    int i;
    (void)size;
    for (i = 0; i < info->dlpi_phnum; i++) {
        const ElfW(Phdr)* ph = &info->dlpi_phdr[i];
        if (ph->p_type == PT_LOAD && self >= info->dlpi_addr + ph->p_vaddr &&
            self < info->dlpi_addr + ph->p_vaddr + ph->p_memsz) {
            *(struct dl_phdr_info*)data = *info;
            return 1;
        }
    }
    return 0;
}

static int CmpU32(const void* a, const void* b) {
    uint32_t x = *(const uint32_t*)a, y = *(const uint32_t*)b;
    return x < y ? -1 : x > y;
}

/* Collects the relocations that fall inside romdat / romdatw. */
static void LoadRelocs(void) {
    struct dl_phdr_info self;
    const ElfW(Dyn)* dyn = NULL;
    const ElfW(Rel)* rel = NULL;
    size_t relsz = 0, i, cap = 0;
    uint8_t *d0, *d1;
    size_t n0, n1;
    int k;

    sRelocsLoaded = 1;
    memset(&self, 0, sizeof(self));
    if (!dl_iterate_phdr(FindSelf, &self))
        return;
    sRelocs.base = self.dlpi_addr;
    for (k = 0; k < self.dlpi_phnum; k++)
        if (self.dlpi_phdr[k].p_type == PT_DYNAMIC)
            dyn = (const ElfW(Dyn)*)(self.dlpi_addr + self.dlpi_phdr[k].p_vaddr);
    if (!dyn)
        return;
    for (; dyn->d_tag != DT_NULL; dyn++) {
        if (dyn->d_tag == DT_REL) {
            /* Android's loader leaves addresses here relative to the load
             * address; glibc's turns them into absolute ones. */
            uintptr_t v = dyn->d_un.d_ptr;
            rel = (const ElfW(Rel)*)(v < self.dlpi_addr ? self.dlpi_addr + v : v);
        }
        else if (dyn->d_tag == DT_RELSZ)
            relsz = dyn->d_un.d_val;
        else if (dyn->d_tag == DT_RELA || dyn->d_tag == 36 /* DT_RELR */)
            sRelocs.bad = 1; /* never produced for 32-bit ARM by our link */
    }
    if (!PcRomDataSection("romdat", &d0, &n0))
        n0 = 0, d0 = NULL;
    if (!PcRomDataSection("romdatw", &d1, &n1))
        n1 = 0, d1 = NULL;
    for (i = 0; rel && i < relsz / sizeof(*rel); i++) {
        uintptr_t at = self.dlpi_addr + rel[i].r_offset;
        int inside = (d0 && at >= (uintptr_t)d0 && at < (uintptr_t)d0 + n0) ||
                     (d1 && at >= (uintptr_t)d1 && at < (uintptr_t)d1 + n1);
        if (!inside)
            continue;
        if (ELF32_R_TYPE(rel[i].r_info) != R_ARM_RELATIVE) {
            sRelocs.bad = 1;
            continue;
        }
        if (sRelocs.count == cap) {
            uint32_t* grown;
            cap = cap ? cap * 2 : 4096;
            grown = (uint32_t*)realloc(sRelocs.sites, cap * sizeof(uint32_t));
            if (!grown) {
                sRelocs.bad = 1;
                return;
            }
            sRelocs.sites = grown;
        }
        sRelocs.sites[sRelocs.count++] = (uint32_t)at;
    }
    qsort(sRelocs.sites, sRelocs.count, sizeof(uint32_t), CmpU32);
}

/* Is byte `p` part of a word the loader relocated? */
static int IsRelocated(const uint8_t* p) {
    size_t lo = 0, hi;
    uint32_t a = (uint32_t)(uintptr_t)p;
    if (!sRelocsLoaded)
        LoadRelocs();
    hi = sRelocs.count;
    while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        if (sRelocs.sites[mid] + 4 <= a)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo < sRelocs.count && sRelocs.sites[lo] <= a;
}

static void Relocate(uint8_t* sec, size_t size) {
    size_t i;
    for (i = 0; i < sRelocs.count; i++) {
        uint32_t at = sRelocs.sites[i];
        if (at >= (uint32_t)(uintptr_t)sec && at + 4 <= (uint32_t)(uintptr_t)sec + size) {
            uint32_t v;
            memcpy(&v, (void*)(uintptr_t)at, 4);
            v += (uint32_t)sRelocs.base;
            memcpy((void*)(uintptr_t)at, &v, 4);
        }
    }
}
#endif

#ifndef PC_SPLIT_CORE /* the 64-bit phone build: port/wasm/pc_core_host.c */
/* Where a section of the running executable is ("romdat": constant game
 * data, "romdatw": the game's initialised variables). */
int PcRomDataSection(const char* name, uint8_t** start, size_t* size) {
#ifdef _WIN32
    uint8_t* base = (uint8_t*)GetModuleHandleA(NULL);
    IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)base;
    IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)(base + dos->e_lfanew);
    IMAGE_SECTION_HEADER* s = IMAGE_FIRST_SECTION(nt);
    char want[9] = {0};
    int i;
    snprintf(want, sizeof(want), ".%s", name);
    for (i = 0; i < nt->FileHeader.NumberOfSections; i++, s++) {
        if (!strncmp((const char*)s->Name, want, 8)) {
            *start = base + s->VirtualAddress;
            *size = s->Misc.VirtualSize;
            return 1;
        }
    }
    return 0;
#else
    char *b, *e;
    if (!strcmp(name, "romdat")) {
        b = __start_romdat;
        e = __stop_romdat;
    } else {
        b = __start_romdatw;
        e = __stop_romdatw;
    }
    if (!b || !e)
        return 0;
    *start = (uint8_t*)b;
    *size = (size_t)(e - b);
    return 1;
#endif
}

static int SectionBounds(uint8_t** start, size_t* size) {
    return PcRomDataSection("romdat", start, size);
}

int PcRomDataNeeded(void) {
    uint8_t* s;
    size_t n, i, check;
    if (!SectionBounds(&s, &n))
        return 0;
    /* A development build has the data linked in; a shipped one is empty. */
    check = n < (1u << 20) ? n : (1u << 20);
    for (i = 0; i < check; i++)
        if (s[i]) {
#if PC_RELOCATE_ROMDATA
            if (IsRelocated(s + i))
                continue; /* a pointer the loader filled in */
#endif
            return 0;
        }
    return 1;
}

#endif /* PC_SPLIT_CORE */

static uint8_t* ReadAll(const char* path, size_t* size) {
    FILE* f = fopen(path, "rb");
    uint8_t* d;
    long n;
    if (!f)
        return NULL;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    d = (uint8_t*)malloc(n > 0 ? (size_t)n : 1);
    if (d && fread(d, 1, (size_t)n, f) != (size_t)n) {
        free(d);
        d = NULL;
    }
    fclose(f);
    *size = (size_t)n;
    return d;
}

static uint32_t Le32(const uint8_t* p) {
    return p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24;
}

/* Returns NULL on success, or a message for the player (Spanish). */
const char* PcRomDataLoad(const char* romPath, const char* mapPath) {
    static char err[512];
    uint8_t *map, *rom, *p, *end;
    size_t mapSize, romSize;
    uint32_t nsec, k;
    uint8_t sha[20];

    map = ReadAll(mapPath, &mapSize);
    if (!map || mapSize < 36 || memcmp(map, "RDCMAP2", 8)) {
        snprintf(err, sizeof(err), "Falta o está dañado el archivo del motor:\n%s", mapPath);
        free(map);
        return err;
    }
    rom = ReadAll(romPath, &romSize);
    if (!rom) {
        snprintf(err, sizeof(err), "No se pudo abrir tu ROM:\n%s", romPath);
        free(map);
        return err;
    }
    PcSha1(rom, romSize, sha);
    if (memcmp(sha, map + 12, 20)) {
        free(map);
        free(rom);
        return "La ROM no es la versión que este motor necesita (su huella SHA-1 no coincide).";
    }
#if PC_RELOCATE_ROMDATA
    if (!sRelocsLoaded)
        LoadRelocs();
    if (sRelocs.bad) {
        free(map);
        free(rom);
        return "Este motor no se puede preparar en este teléfono (reubicación no admitida).";
    }
#endif
    nsec = Le32(map + 32);
    p = map + 36;
    end = map + mapSize;
    for (k = 0; k < nsec; k++) {
        char name[9] = {0};
        uint8_t* sec;
        size_t secSize;
        uint32_t size, nCopies, nLits, i;
        const uint8_t* wantSha;
        if (p + 40 > end)
            goto bad;
        memcpy(name, p, 8);
        size = Le32(p + 8);
        wantSha = p + 12;
        nCopies = Le32(p + 32);
        nLits = Le32(p + 36);
        p += 40;
        if (!PcRomDataSection(name, &sec, &secSize) || secSize < size ||
            (secSize != size && strcmp(name, "wasmdata"))) {
            free(map);
            free(rom);
            return "El archivo .map no corresponde a este motor. Vuelve a descomprimir el programa.";
        }
#if PC_RELOCATE_ROMDATA
        memset(sec, 0, secSize); /* undo the loader's work on the emptied data */
#endif
        secSize = size; /* the core's image: its zeroed variables follow it */
        for (i = 0; i < nCopies; i++, p += 12) {
            uint32_t so, ro, n;
            if (p + 12 > end)
                goto bad;
            so = Le32(p);
            ro = Le32(p + 4);
            n = Le32(p + 8);
            if ((size_t)so + n > secSize || (size_t)ro + n > romSize)
                goto bad;
            memcpy(sec + so, rom + ro, n);
        }
        for (i = 0; i < nLits; i++) {
            uint32_t so, n;
            if (p + 8 > end)
                goto bad;
            so = Le32(p);
            n = Le32(p + 4);
            p += 8;
            if (p + n > end || (size_t)so + n > secSize)
                goto bad;
            memcpy(sec + so, p, n);
            p += n;
        }
        PcSha1(sec, secSize, sha);
        if (memcmp(sha, wantSha, 20)) {
            free(map);
            free(rom);
            return "Los datos reconstruidos no coinciden (archivo .map de otra versión del motor).";
        }
#if PC_RELOCATE_ROMDATA
        Relocate(sec, secSize);
#endif
    }
    free(map);
    free(rom);
    PcLog("[pc] game data rebuilt from %s\n", romPath);
    return NULL;

bad:
    free(map);
    free(rom);
    return "El archivo .map está dañado. Vuelve a descomprimir el programa.";
}
