#ifndef GUARD_MACROS_H
#define GUARD_MACROS_H

#define INCLUDE_ASM(path) asm(".include \"" path "\"")

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#define STATIC_ASSERT(expr, id) typedef char id[(expr) ? 1 : -1];

#ifdef PLATFORM_PC
/* PC port: no separate EWRAM/IWRAM regions; keep alignment only. */
#define EWRAM_COMMON(align) __attribute__((aligned(align))) = {0}
#define IWRAM_DATA(align) __attribute__((aligned(align))) = {0}
#define IWRAM_COMMON(align) __attribute__((aligned(align))) = {0}
#define ASM_SYMBOL(name) STRINGIFY(__USER_LABEL_PREFIX__) name
/* Original-game bugs (marked @bug in the source) that access memory through a
 * NULL pointer hit the GBA BIOS region: reads return the last BIOS opcode
 * fetched and writes are ignored. PC_NULL_FIX redirects such a pointer to a
 * page that holds that value and is restored every frame (port/pc_memory.c).
 * Only use it where the access reads or writes plain values; a pointer read
 * through NULL needs a site-specific fix. */
extern unsigned char gPcNullPage[];
#define PC_NULL_FIX(p) ((p) != 0 ? (p) : (__typeof__(p))(void*)gPcNullPage)
/* Code that only exists in the PC build, written inline so the GBA sources
 * keep their line numbers (some section names are built from __LINE__). */
#define PC_ONLY(...) __VA_ARGS__
#define GBA_ONLY(...)
#else
#define PC_ONLY(...)
#define GBA_ONLY(...) __VA_ARGS__
#define PC_NULL_FIX(p) (p)
#define ASM_SYMBOL(name) name
#define EWRAM_COMMON(align) __attribute__((section(".ewram_common." STRINGIFY(__LINE__)), aligned(align))) = {0}
#define IWRAM_DATA(align) __attribute__((section(".iwram." STRINGIFY(__LINE__)), aligned(align))) = {0}
#define IWRAM_COMMON(align) __attribute__((section(".iwram_common." STRINGIFY(__LINE__)), aligned(align))) = {0}
#endif

#endif /* GUARD_MACROS_H */
