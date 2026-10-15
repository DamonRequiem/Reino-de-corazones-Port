#ifndef GUARD_TYPES_H
#define GUARD_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#ifdef PLATFORM_PC
/* The GBA aligns 64-bit integers to 4 bytes inside structs; Windows aligns them
 * to 8. Pin the GBA layout so save data and struct sizes match on every PC. */
typedef unsigned long long u64 __attribute__((aligned(4)));
typedef signed long long s64 __attribute__((aligned(4)));
#else
typedef unsigned long long u64;
typedef signed long long s64;
#endif

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

#define TRUE 1
#define FALSE 0

#endif /* GUARD_TYPES_H */
