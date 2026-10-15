/*
 * pc_divzero.c
 * GBA-compatible integer division by zero.
 *
 * The GBA has no divide instruction: the game calls libgcc's __divsi3 and
 * friends, which return 0 when dividing by zero (quotient and remainder).
 * Several original-game bugs rely on that (see the "division by zero" @bug
 * notes). On x86 the same division traps and would close the game.
 *
 * This installs a trap handler that, for a faulting DIV/IDIV instruction,
 * sets the result registers to what the GBA would produce and resumes after
 * the instruction:
 *   x / 0  -> quotient 0, remainder 0
 *   INT_MIN / -1 (also traps on x86) -> quotient INT_MIN, remainder 0
 */
#ifndef _WIN32
#define _GNU_SOURCE 1 /* REG_EIP / REG_RIP in <ucontext.h> */
#endif
#include <stdint.h>
#include <string.h>
#include "pc_platform.h"

#if defined(__arm__)
/*
 * 32-bit ARM (Android armeabi-v7a): like the GBA, ARMv7-A has no guaranteed
 * divide instruction, so the compiler calls the run-time helpers below. They
 * replace the toolchain's versions and give the GBA results directly:
 *   x / 0 -> 0 (remainder 0), INT_MIN / -1 -> INT_MIN (remainder 0).
 * No trap handler is needed. They must not use '/' themselves.
 */
static uint32_t UDiv(uint32_t n, uint32_t d, uint32_t* rem) {
    uint32_t q = 0;
    int shift;
    if (d == 0) {
        *rem = 0;
        return 0;
    }
    if (n < d) {
        *rem = n;
        return 0;
    }
    shift = __builtin_clz(d) - __builtin_clz(n);
    d <<= shift;
    for (; shift >= 0; shift--, d >>= 1) {
        q <<= 1;
        if (n >= d) {
            n -= d;
            q |= 1;
        }
    }
    *rem = n;
    return q;
}

static int32_t SDiv(int32_t n, int32_t d, int32_t* rem) {
    uint32_t un = n < 0 ? 0u - (uint32_t)n : (uint32_t)n;
    uint32_t ud = d < 0 ? 0u - (uint32_t)d : (uint32_t)d;
    uint32_t q, r;
    if (d == 0 || (n == INT32_MIN && d == -1)) {
        *rem = 0;
        return d == 0 ? 0 : INT32_MIN;
    }
    q = UDiv(un, ud, &r);
    *rem = n < 0 ? -(int32_t)r : (int32_t)r;
    return (n < 0) != (d < 0) ? -(int32_t)q : (int32_t)q;
}

/* Quotient in r0, remainder in r1: a 64-bit return value under the AAPCS. */
uint32_t __aeabi_uidiv(uint32_t n, uint32_t d);
int32_t __aeabi_idiv(int32_t n, int32_t d);
uint64_t __aeabi_uidivmod(uint32_t n, uint32_t d);
uint64_t __aeabi_idivmod(int32_t n, int32_t d);
uint32_t __udivsi3(uint32_t n, uint32_t d);
int32_t __divsi3(int32_t n, int32_t d);
uint32_t __umodsi3(uint32_t n, uint32_t d);
int32_t __modsi3(int32_t n, int32_t d);

uint32_t __aeabi_uidiv(uint32_t n, uint32_t d) {
    uint32_t r;
    return UDiv(n, d, &r);
}
int32_t __aeabi_idiv(int32_t n, int32_t d) {
    int32_t r;
    return SDiv(n, d, &r);
}
uint64_t __aeabi_uidivmod(uint32_t n, uint32_t d) {
    uint32_t r, q = UDiv(n, d, &r);
    return q | (uint64_t)r << 32;
}
uint64_t __aeabi_idivmod(int32_t n, int32_t d) {
    int32_t r, q = SDiv(n, d, &r);
    return (uint32_t)q | (uint64_t)(uint32_t)r << 32;
}
uint32_t __udivsi3(uint32_t n, uint32_t d) {
    return __aeabi_uidiv(n, d);
}
int32_t __divsi3(int32_t n, int32_t d) {
    return __aeabi_idiv(n, d);
}
uint32_t __umodsi3(uint32_t n, uint32_t d) {
    uint32_t r;
    UDiv(n, d, &r);
    return r;
}
int32_t __modsi3(int32_t n, int32_t d) {
    int32_t r;
    SDiv(n, d, &r);
    return r;
}

void PcInstallDivZeroHandler(void) {
}

#else /* x86: the hardware traps, the handler fixes the result */

/* Returns the length of a DIV/IDIV instruction at `ip`, or 0 if it is not one.
 * Sets *width to the operand size in bytes and *isSigned for IDIV. */
static int DecodeDiv(const uint8_t* ip, int* width, int* isSigned) {
    const uint8_t* p = ip;
    int opsize16 = 0, rexW = 0;
    uint8_t op, modrm, mod, reg, rm;

    for (;;) {
        uint8_t b = *p;
        if (b == 0x66) { opsize16 = 1; p++; continue; }
        if (b == 0x67 || b == 0x2E || b == 0x36 || b == 0x3E || b == 0x26 || b == 0x64 || b == 0x65 ||
            b == 0xF0 || b == 0xF2 || b == 0xF3) { p++; continue; }
        break;
    }
#if defined(__x86_64__) || defined(_M_X64)
    if ((*p & 0xF0) == 0x40) {
        rexW = (*p >> 3) & 1;
        p++;
    }
#endif
    op = *p++;
    if (op != 0xF6 && op != 0xF7)
        return 0;
    modrm = *p++;
    mod = modrm >> 6;
    reg = (modrm >> 3) & 7;
    rm = modrm & 7;
    if (reg != 6 && reg != 7)
        return 0;
    if (mod != 3 && rm == 4) {
        uint8_t sib = *p++;
        if (mod == 0 && (sib & 7) == 5)
            p += 4;
    }
    if (mod == 1)
        p += 1;
    else if (mod == 2)
        p += 4;
    else if (mod == 0 && rm == 5)
        p += 4;

    *isSigned = reg == 7;
    *width = op == 0xF6 ? 1 : rexW ? 8 : opsize16 ? 2 : 4;
    return (int)(p - ip);
}

/* Applies the GBA result to the accumulator pair. `overflow` is the
 * INT_MIN / -1 case, where the quotient stays the (negative) dividend. */
static void SetResult(uintptr_t* ax, uintptr_t* dx, int width, int overflow) {
    switch (width) {
        case 1: /* AL = quotient, AH = remainder */
            *ax = (*ax & ~(uintptr_t)0xFFFF) | (overflow ? 0x80 : 0);
            break;
        case 2:
            *ax = (*ax & ~(uintptr_t)0xFFFF) | (overflow ? 0x8000 : 0);
            *dx &= ~(uintptr_t)0xFFFF;
            break;
        case 4:
            *ax = overflow ? 0x80000000u : 0;
            *dx = 0;
            break;
        default:
            *ax = overflow ? (uintptr_t)1 << (sizeof(uintptr_t) * 8 - 1) : 0;
            *dx = 0;
            break;
    }
}

#ifdef _WIN32
#include <windows.h>

static LONG CALLBACK DivHandler(EXCEPTION_POINTERS* info) {
    DWORD code = info->ExceptionRecord->ExceptionCode;
    CONTEXT* c = info->ContextRecord;
    int width, isSigned, len;

    if (code != EXCEPTION_INT_DIVIDE_BY_ZERO && code != EXCEPTION_INT_OVERFLOW)
        return EXCEPTION_CONTINUE_SEARCH;
#if defined(__x86_64__) || defined(_M_X64)
    len = DecodeDiv((const uint8_t*)c->Rip, &width, &isSigned);
    if (len == 0)
        return EXCEPTION_CONTINUE_SEARCH;
    {
        uintptr_t ax = c->Rax, dx = c->Rdx;
        SetResult(&ax, &dx, width, code == EXCEPTION_INT_OVERFLOW && isSigned);
        c->Rax = ax;
        c->Rdx = dx;
    }
    c->Rip += len;
#else
    len = DecodeDiv((const uint8_t*)c->Eip, &width, &isSigned);
    if (len == 0)
        return EXCEPTION_CONTINUE_SEARCH;
    {
        uintptr_t ax = c->Eax, dx = c->Edx;
        SetResult(&ax, &dx, width, code == EXCEPTION_INT_OVERFLOW && isSigned);
        c->Eax = ax;
        c->Edx = dx;
    }
    c->Eip += len;
#endif
    return EXCEPTION_CONTINUE_EXECUTION;
}

void PcInstallDivZeroHandler(void) {
    AddVectoredExceptionHandler(1, DivHandler);
}

#else /* POSIX (Linux test builds) */
#include <signal.h>
#include <ucontext.h>

static void DivHandler(int sig, siginfo_t* si, void* ctx) {
    ucontext_t* uc = (ucontext_t*)ctx;
    greg_t* g = uc->uc_mcontext.gregs;
    int width, isSigned, len;
    uintptr_t ax, dx;
#if defined(__x86_64__)
    len = DecodeDiv((const uint8_t*)g[REG_RIP], &width, &isSigned);
#else
    len = DecodeDiv((const uint8_t*)g[REG_EIP], &width, &isSigned);
#endif
    (void)sig;
    if (len == 0) {
        /* Not a division we understand: report it like any other crash. */
        signal(SIGFPE, SIG_DFL);
        return;
    }
    /* Linux reports INT_MIN / -1 as FPE_INTDIV as well, so that rare case
     * yields 0 here (Windows tells the two apart and handles both exactly). */
#if defined(__x86_64__)
    ax = (uintptr_t)g[REG_RAX];
    dx = (uintptr_t)g[REG_RDX];
#else
    ax = (uintptr_t)g[REG_EAX];
    dx = (uintptr_t)g[REG_EDX];
#endif
    SetResult(&ax, &dx, width, isSigned && si->si_code == FPE_INTOVF);
#if defined(__x86_64__)
    g[REG_RAX] = (greg_t)ax;
    g[REG_RDX] = (greg_t)dx;
    g[REG_RIP] += len;
#else
    g[REG_EAX] = (greg_t)ax;
    g[REG_EDX] = (greg_t)dx;
    g[REG_EIP] += len;
#endif
}

void PcInstallDivZeroHandler(void) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = DivHandler;
    sa.sa_flags = SA_SIGINFO | SA_NODEFER;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGFPE, &sa, NULL);
}
#endif
#endif /* __arm__ */
