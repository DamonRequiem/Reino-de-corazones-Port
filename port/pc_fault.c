/*
 * pc_fault.c
 * Safety net for original-game NULL/garbage pointer accesses.
 *
 * On the GBA, a read or write through a NULL pointer (or through a garbage
 * pointer read from the BIOS area) never crashes: reads return the BIOS latch
 * value and writes are ignored. The known cases are fixed in the source with
 * PC_NULL_FIX; this catches the ones nobody has documented yet.
 *
 * When code inside khcom.exe faults on such an address, the handler decodes
 * the faulting instruction's memory operand, finds the base register holding
 * the bad pointer and moves it onto gPcNullPage (same low 12 bits), then lets
 * the instruction run again. The access then reads the BIOS-like page or is
 * absorbed by it, as on hardware. Each recovered site is logged once
 * ("khcom.exe+0x...") so it can be fixed properly in the source.
 *
 * Only addresses that cannot be valid on PC are handled: below 64 KiB, and
 * the top of the address space where the BIOS latch value (0xE3A02004)
 * points. Everything else is a real bug and goes to the crash report.
 */
#ifndef _WIN32
#define _GNU_SOURCE 1
#endif
#include <stdint.h>
#include <string.h>
#include "pc_platform.h"

#define MAX_LOGGED_SITES 64

static uintptr_t sLoggedSites[MAX_LOGGED_SITES];
static int sNumLoggedSites;
static unsigned long sRecoveries;
static uintptr_t sImageBase, sImageEnd;

/* Register numbers in ModRM order: eax ecx edx ebx esp ebp esi edi. */
enum { R_AX, R_CX, R_DX, R_BX, R_SP, R_BP, R_SI, R_DI };

static int AddressIsGbaOnly(uintptr_t addr) {
    if (addr < 0x10000)
        return 1;
#if UINTPTR_MAX == 0xFFFFFFFFu
    /* 32-bit: the BIOS latch 0xE3A02004 and anything near it is kernel space
     * (Windows) or above the 32-bit process's mappings (Linux). */
    return addr >= 0xE0000000u;
#else
    return addr >= 0xFFFF800000000000ull || (addr >> 32) == 0xE3A02004ull >> 32;
#endif
}

#if defined(__arm__)
/* 32-bit ARM (Android): the game is built in ARM state (-marm), where every
 * load/store class (LDR/STR, LDRH/LDRD/..., LDM/STM, VLDR/VLDM) names its base
 * register in bits 16-19. regs[] holds r0-r15. */
static int FindBaseRegister(const uint8_t* ip, uintptr_t fault, const uintptr_t* regs) {
    uint32_t w;
    int rn;
    (void)fault;
    (void)regs;
    memcpy(&w, ip, 4);
    if ((w >> 28) == 0xF)
        return -1; /* unconditional space: no plain loads/stores here */
    rn = (w >> 16) & 15;
    if (rn == 13 || rn == 15)
        return -1; /* stack or PC-relative: never a GBA pointer */
    if (((w >> 26) & 3) == 1)
        return rn; /* LDR/STR/LDRB/STRB */
    if (((w >> 25) & 7) == 0 && (w & 0x90) == 0x90)
        return rn; /* LDRH/STRH/LDRSB/LDRSH/LDRD/STRD/LDREX */
    if (((w >> 25) & 7) == 4 || ((w >> 25) & 7) == 6)
        return rn; /* LDM/STM, VLDR/VSTR/VLDM/VSTM */
    return -1;
}
#else
/* Finds which register forms the base of the faulting memory operand.
 * Returns the register number, or -1 if the operand has no usable base. */
static int FindBaseRegister(const uint8_t* ip, uintptr_t fault, const uintptr_t* regs) {
    const uint8_t* p = ip;
    uint8_t op, modrm, mod, rm;

    for (;;) {
        uint8_t b = *p;
        if (b == 0x67)
            return -1; /* 16-bit addressing: never generated here */
        if (b == 0x66 || b == 0xF0 || b == 0xF2 || b == 0xF3 || b == 0x2E || b == 0x36 || b == 0x3E ||
            b == 0x26 || b == 0x64 || b == 0x65) {
            p++;
            continue;
        }
        break;
    }
#if UINTPTR_MAX != 0xFFFFFFFFu
    if ((*p & 0xF0) == 0x40)
        p++; /* REX: extended registers are not handled, but plain ones are */
#endif
    op = *p++;

    /* String instructions use ESI (source) / EDI (destination) implicitly. */
    if ((op >= 0xA4 && op <= 0xA7) || (op >= 0xAA && op <= 0xAF)) {
        uintptr_t si = regs[R_SI], di = regs[R_DI];
        uintptr_t dsi = fault > si ? fault - si : si - fault;
        uintptr_t ddi = fault > di ? fault - di : di - fault;
        return dsi <= ddi ? R_SI : R_DI;
    }
    if (op == 0x0F) {
        op = *p++;
        if (op == 0x38 || op == 0x3A)
            p++;
        if ((op >= 0x80 && op <= 0x8F) || op == 0x0B || op == 0x31 || op == 0xA2)
            return -1; /* no memory operand */
    } else if (op >= 0xA0 && op <= 0xA3) {
        return -1; /* absolute moffs address */
    }

    modrm = *p++;
    mod = modrm >> 6;
    rm = modrm & 7;
    if (mod == 3)
        return -1;
    if (rm == 4) {
        uint8_t sib = *p;
        uint8_t base = sib & 7;
        if (mod == 0 && base == 5)
            return -1; /* [index*scale + disp32]: no base */
        return base == R_SP ? -1 : base;
    }
    if (mod == 0 && rm == 5)
        return -1; /* disp32 (absolute, or RIP-relative on x86-64) */
    return rm == R_SP ? -1 : rm;
}
#endif

static void LogSite(uintptr_t ip, uintptr_t fault) {
    int i;
    for (i = 0; i < sNumLoggedSites; i++)
        if (sLoggedSites[i] == ip)
            return;
    if (sNumLoggedSites < MAX_LOGGED_SITES)
        sLoggedSites[sNumLoggedSites++] = ip;
    if (ip >= sImageBase && ip < sImageEnd && sImageBase != 0)
        PcLog("[pc] recovered GBA-style access to 0x%lX at game+0x%06lX (frame %u)\n", (unsigned long)fault,
              (unsigned long)(ip - sImageBase), gPcFrameCount);
    else
        PcLog("[pc] recovered GBA-style access to 0x%lX at 0x%lX (frame %u)\n", (unsigned long)fault,
              (unsigned long)ip, gPcFrameCount);
}

/* Shared logic. regs[] holds the 8 general registers in ModRM order and is
 * updated in place. Returns 1 if the access was redirected. */
static int Recover(uintptr_t ip, uintptr_t fault, uintptr_t* regs) {
    int reg;
    uintptr_t target;

    if (!AddressIsGbaOnly(fault))
        return 0;
    if (sImageBase != 0 && (ip < sImageBase || ip >= sImageEnd))
        return 0; /* not our code (a system library): a genuine crash */
    reg = FindBaseRegister((const uint8_t*)ip, fault, regs);
    if (reg < 0)
        return 0;
    target = (uintptr_t)gPcNullPage + (fault & 0xFFF);
    regs[reg] += target - fault;
    sRecoveries++;
    LogSite(ip, fault);
    return 1;
}

unsigned long PcFaultRecoveries(void) {
    return sRecoveries;
}

#ifdef _WIN32
#include <windows.h>

static LONG CALLBACK FaultHandler(EXCEPTION_POINTERS* info) {
    EXCEPTION_RECORD* er = info->ExceptionRecord;
    CONTEXT* c = info->ContextRecord;
    uintptr_t regs[8];

    if (er->ExceptionCode != EXCEPTION_ACCESS_VIOLATION || er->NumberParameters < 2)
        return EXCEPTION_CONTINUE_SEARCH;
#if defined(__x86_64__) || defined(_M_X64)
    regs[0] = c->Rax; regs[1] = c->Rcx; regs[2] = c->Rdx; regs[3] = c->Rbx;
    regs[4] = c->Rsp; regs[5] = c->Rbp; regs[6] = c->Rsi; regs[7] = c->Rdi;
    if (!Recover(c->Rip, (uintptr_t)er->ExceptionInformation[1], regs))
        return EXCEPTION_CONTINUE_SEARCH;
    c->Rax = regs[0]; c->Rcx = regs[1]; c->Rdx = regs[2]; c->Rbx = regs[3];
    c->Rbp = regs[5]; c->Rsi = regs[6]; c->Rdi = regs[7];
#else
    regs[0] = c->Eax; regs[1] = c->Ecx; regs[2] = c->Edx; regs[3] = c->Ebx;
    regs[4] = c->Esp; regs[5] = c->Ebp; regs[6] = c->Esi; regs[7] = c->Edi;
    if (!Recover(c->Eip, (uintptr_t)er->ExceptionInformation[1], regs))
        return EXCEPTION_CONTINUE_SEARCH;
    c->Eax = regs[0]; c->Ecx = regs[1]; c->Edx = regs[2]; c->Ebx = regs[3];
    c->Ebp = regs[5]; c->Esi = regs[6]; c->Edi = regs[7];
#endif
    return EXCEPTION_CONTINUE_EXECUTION;
}

void PcInstallFaultRecovery(void) {
    HMODULE mod = GetModuleHandleA(NULL);
    IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)((uint8_t*)mod + ((IMAGE_DOS_HEADER*)mod)->e_lfanew);
    sImageBase = (uintptr_t)mod;
    sImageEnd = sImageBase + nt->OptionalHeader.SizeOfImage;
    AddVectoredExceptionHandler(1, FaultHandler);
}

#else /* POSIX: Linux test builds and Android */
#include <signal.h>
#include <stdlib.h>
#include <ucontext.h>
#if defined(__arm__)
#include <dlfcn.h>
#include <link.h>
#endif

static void (*sNextHandler)(int);
static struct sigaction sNextAction;

static void FaultHandler(int sig, siginfo_t* si, void* ctx) {
    ucontext_t* uc = (ucontext_t*)ctx;
    int i;
#if defined(__arm__)
    /* r0-r10, fp, ip, sp, lr, pc are consecutive in struct sigcontext. */
    unsigned long* g = &uc->uc_mcontext.arm_r0;
    uintptr_t regs[16];
    for (i = 0; i < 16; i++)
        regs[i] = (uintptr_t)g[i];
    if (!(uc->uc_mcontext.arm_cpsr & 0x20) /* ARM state, not Thumb */ &&
        Recover((uintptr_t)uc->uc_mcontext.arm_pc, (uintptr_t)si->si_addr, regs)) {
        for (i = 0; i < 15; i++)
            g[i] = (unsigned long)regs[i];
        return;
    }
#else
    greg_t* g = uc->uc_mcontext.gregs;
    uintptr_t regs[8];
#if defined(__x86_64__)
    static const int idx[8] = {REG_RAX, REG_RCX, REG_RDX, REG_RBX, REG_RSP, REG_RBP, REG_RSI, REG_RDI};
    const int ipIdx = REG_RIP;
#else
    static const int idx[8] = {REG_EAX, REG_ECX, REG_EDX, REG_EBX, REG_ESP, REG_EBP, REG_ESI, REG_EDI};
    const int ipIdx = REG_EIP;
#endif

    for (i = 0; i < 8; i++)
        regs[i] = (uintptr_t)g[idx[i]];
    if (Recover((uintptr_t)g[ipIdx], (uintptr_t)si->si_addr, regs)) {
        for (i = 0; i < 8; i++)
            if (i != 4)
                g[idx[i]] = (greg_t)regs[i];
        return;
    }
#endif
    /* Not recoverable: hand over to the previous handler (the crash report,
     * or Android's debuggerd), else the default action. */
    if (sNextAction.sa_flags & SA_SIGINFO) {
        if (sNextAction.sa_sigaction) {
            sigaction(SIGSEGV, &sNextAction, NULL);
            sNextAction.sa_sigaction(sig, si, ctx);
            return;
        }
    } else if (sNextHandler && sNextHandler != SIG_DFL && sNextHandler != SIG_IGN) {
        sNextHandler(sig);
    }
    signal(SIGSEGV, SIG_DFL);
    raise(SIGSEGV);
}

#if defined(__arm__)
/* Address range of the module holding the game code (the executable, or
 * libmain.so on Android), so faults in system libraries are left alone. */
static int FindImage(struct dl_phdr_info* info, size_t size, void* data) {
    int i;
    uintptr_t self = (uintptr_t)data;
    (void)size;
    for (i = 0; i < info->dlpi_phnum; i++) {
        const ElfW(Phdr)* ph = &info->dlpi_phdr[i];
        uintptr_t start = info->dlpi_addr + ph->p_vaddr;
        if (ph->p_type == PT_LOAD && (ph->p_flags & PF_X) && self >= start && self < start + ph->p_memsz) {
            sImageBase = start;
            sImageEnd = start + ph->p_memsz;
            return 1;
        }
    }
    return 0;
}
#endif

void PcInstallFaultRecovery(void) {
    struct sigaction sa;
    if (getenv("KHCOM_NO_RECOVERY"))
        return; /* tests can ask for plain crashes */
#if defined(__arm__)
    dl_iterate_phdr(FindImage, (void*)(uintptr_t)&PcInstallFaultRecovery);
    if (sImageBase == 0)
        return; /* cannot tell our code apart: better a plain crash than a wrong fix */
#endif
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = FaultHandler;
    sa.sa_flags = SA_SIGINFO | SA_NODEFER;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGSEGV, &sa, &sNextAction);
    sNextHandler = (sNextAction.sa_flags & SA_SIGINFO) ? NULL : sNextAction.sa_handler;
}
#endif
