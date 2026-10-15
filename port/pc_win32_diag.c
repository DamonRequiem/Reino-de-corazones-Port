/*
 * pc_win32_diag.c
 * Crash and hang reports for the Windows build.
 *
 * When the game crashes or stops producing frames, this:
 *   1. gets the window out of the way (a message box behind a fullscreen
 *      window makes the whole PC look frozen),
 *   2. writes the faulting address and the code addresses found on the stack
 *      to khcom_log.txt, as "khcom.exe+OFFSET" so they can be matched to the
 *      source with the unstripped build (addr2line),
 *   3. tells the player and closes the game.
 */
#ifdef _WIN32
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "pc_platform.h"

#define HANG_SECONDS 10
/* Stuck inside Windows or the graphics driver (resizing, mode changes,
 * driver resets): give it much longer before calling it a hang. */
#define HANG_SECONDS_SYSTEM 45

static HWND sWindow;
static HANDLE sMainThread;
static DWORD sMainThreadId;
static uintptr_t sImageBase, sImageEnd;
static volatile LONG sReporting;

static void HideWindow(void) {
    /* Async: a synchronous call would wait on the (possibly hung) game thread. */
    if (sWindow != NULL)
        ShowWindowAsync(sWindow, SW_MINIMIZE);
}

static uintptr_t sTextBase, sTextEnd; /* our code (.text) */

/* "khcom.exe+0x1234", or the Windows / driver module an address is in
 * ("d3d9.dll+0x5678"), so a report says where the program was waiting. */
static void LogAddress(const char* label, uintptr_t addr) {
    HMODULE mod = NULL;
    char path[MAX_PATH];
    if (addr >= sImageBase && addr < sImageEnd) {
        PcLog("[pc]   %s khcom.exe+0x%06lX\n", label, (unsigned long)(addr - sImageBase));
        return;
    }
    if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                           (LPCSTR)addr, &mod) &&
        GetModuleFileNameA(mod, path, sizeof(path))) {
        const char* name = strrchr(path, '\\');
        PcLog("[pc]   %s %s+0x%lX\n", label, name ? name + 1 : path, (unsigned long)(addr - (uintptr_t)mod));
        return;
    }
    PcLog("[pc]   %s 0x%08lX\n", label, (unsigned long)addr);
}

/* Is the address code of some module (ours or a DLL)? */
static int IsCode(uintptr_t v) {
    MEMORY_BASIC_INFORMATION mbi;
    if (v >= sTextBase && v < sTextEnd)
        return 1;
    if (v >= sImageBase && v < sImageEnd)
        return 0; /* our data (game graphics...): not a return address */
    if (!VirtualQuery((void*)v, &mbi, sizeof(mbi)) || mbi.Type != MEM_IMAGE)
        return 0;
    return (mbi.Protect & (PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)) != 0;
}

/* Logs every value on the stack that points into our code: a rough backtrace
 * that works without frame pointers. */
static void LogStack(uintptr_t esp) {
    MEMORY_BASIC_INFORMATION mbi;
    uintptr_t p, end;
    int found = 0;

    if (!VirtualQuery((void*)esp, &mbi, sizeof(mbi)))
        return;
    end = (uintptr_t)mbi.BaseAddress + mbi.RegionSize;
    if (end > esp + 0x2000)
        end = esp + 0x2000;
    for (p = esp & ~(uintptr_t)3; p + 4 <= end && found < 24; p += 4) {
        uintptr_t v = *(uintptr_t*)p;
        if (IsCode(v)) {
            LogAddress("stack", v);
            found++;
        }
    }
}

static void Report(const char* title, const char* text) {
    wchar_t wtitle[128], wtext[512];

    HideWindow();
    /* Messages are UTF-8 (accents); MessageBoxA would use the ANSI code page. */
    MultiByteToWideChar(CP_UTF8, 0, title, -1, wtitle, 128);
    MultiByteToWideChar(CP_UTF8, 0, text, -1, wtext, 512);
    if (!MessageBoxW(NULL, wtext, wtitle, MB_OK | MB_ICONERROR | MB_TOPMOST | MB_SETFOREGROUND))
        PcLog("[pc] message box failed: %lu\n", (unsigned long)GetLastError());
}

/* Runs on the game thread in place of the crashed code. */
static void ResumeTrampoline(void) {
    PcStateResumeAfterCrash(); /* does not return */
}

/* Points a thread's context at ResumeTrampoline, on a fresh aligned stack
 * area below the current one. */
static void RedirectToResume(CONTEXT* c) {
#if defined(__i386__) || defined(_M_IX86)
    uintptr_t sp = (c->Esp - 256) & ~(uintptr_t)15;
    sp -= 4;
    *(uintptr_t*)sp = 0; /* fake return address: the trampoline never returns */
    c->Esp = sp;
    c->Eip = (uintptr_t)ResumeTrampoline;
#else
    uintptr_t sp = (c->Rsp - 256) & ~(uintptr_t)15;
    sp -= 8;
    *(uintptr_t*)sp = 0;
    c->Rsp = sp;
    c->Rip = (uintptr_t)ResumeTrampoline;
#endif
}

static int InOurCode(uintptr_t ip) {
    return ip >= sImageBase && ip < sImageEnd;
}

/* Last line of defence: go back a couple of seconds instead of closing. Runs
 * as a vectored handler (after pc_fault.c's), and only for faults in the
 * game's own code on the game thread; anything else reaches CrashFilter. */
static LONG CALLBACK ResumeHandler(EXCEPTION_POINTERS* info) {
    DWORD code = info->ExceptionRecord->ExceptionCode;
#if defined(__i386__) || defined(_M_IX86)
    uintptr_t ip = info->ContextRecord->Eip;
#else
    uintptr_t ip = info->ContextRecord->Rip;
#endif
    if (code != EXCEPTION_ACCESS_VIOLATION && code != EXCEPTION_ILLEGAL_INSTRUCTION &&
        code != EXCEPTION_PRIV_INSTRUCTION && code != EXCEPTION_ARRAY_BOUNDS_EXCEEDED)
        return EXCEPTION_CONTINUE_SEARCH;
    if (GetCurrentThreadId() != sMainThreadId || !InOurCode(ip) || !PcStateCanResume())
        return EXCEPTION_CONTINUE_SEARCH;
    PcLog("[pc] CRASH: exception 0x%08lX at frame %u - recovering\n", (unsigned long)code, gPcFrameCount);
    LogAddress("at", ip);
    RedirectToResume(info->ContextRecord);
    return EXCEPTION_CONTINUE_EXECUTION;
}

extern const char* gPcLogHint;

static LONG WINAPI CrashFilter(EXCEPTION_POINTERS* info) {
    char msg[320];

    if (InterlockedExchange(&sReporting, 1))
        return EXCEPTION_EXECUTE_HANDLER;
    PcLog("[pc] CRASH: exception 0x%08lX at frame %u\n", (unsigned long)info->ExceptionRecord->ExceptionCode,
          gPcFrameCount);
    LogAddress("at", (uintptr_t)info->ExceptionRecord->ExceptionAddress);
#ifdef _M_IX86
    LogStack(info->ContextRecord->Esp);
#elif defined(__i386__)
    LogStack(info->ContextRecord->Esp);
#endif
    snprintf(msg, sizeof(msg),
             "El juego se cerró inesperadamente (cuadro %u).\n\n"
             "Se guardaron los detalles en %s.\n"
             "Envía ese archivo y cuenta qué estabas haciendo.",
             gPcFrameCount, gPcLogHint);
    Report("Reino de Corazones", msg);
    return EXCEPTION_EXECUTE_HANDLER;
}

/* Ticks of the main loop: every game frame, and also every pass of the
 * pause menu and of the background pause, which stop the game on purpose. */
volatile uint32_t gPcAlive;
/* Where the log is, for the error messages ("registros\\usa.txt"...). */
const char* gPcLogHint = "khcom_log.txt, junto al juego";

static DWORD WINAPI Watchdog(LPVOID arg) {
    uint32_t lastFrame = gPcAlive;
    int stuck = 0;
    (void)arg;

    for (;;) {
        Sleep(1000);
        /* Graphics driver setup can take a while on some PCs: only start
         * watching once the game has drawn its first frame. */
        if (gPcFrameCount == 0)
            continue;
        if (gPcAlive != lastFrame) {
            lastFrame = gPcAlive;
            stuck = 0;
            continue;
        }
        /* Minimised windows, window drags/resizes and system menus
         * legitimately pause the loop. */
        {
            GUITHREADINFO gti;
            gti.cbSize = sizeof(gti);
            if ((sWindow != NULL && IsIconic(sWindow)) ||
                (GetGUIThreadInfo(sMainThreadId, &gti) &&
                 (gti.flags & (GUI_INMOVESIZE | GUI_INMENUMODE | GUI_SYSTEMMENUMODE | GUI_POPUPMENUMODE)))) {
                stuck = 0;
                continue;
            }
        }
        if (++stuck < HANG_SECONDS)
            continue;
        if (stuck < HANG_SECONDS_SYSTEM) {
            /* Where is the game thread? Inside Windows or the driver, wait more. */
            uintptr_t where = 0;
            if (SuspendThread(sMainThread) != (DWORD)-1) {
                CONTEXT c;
                memset(&c, 0, sizeof(c));
                c.ContextFlags = CONTEXT_CONTROL;
                if (GetThreadContext(sMainThread, &c)) {
#if defined(__i386__) || defined(_M_IX86)
                    where = c.Eip;
#else
                    where = c.Rip;
#endif
                }
                ResumeThread(sMainThread);
            }
            if (where && !InOurCode(where)) {
                if (stuck == HANG_SECONDS) {
                    PcLog("[pc] no new frame for %d seconds, waiting on Windows / the graphics driver:\n", stuck);
                    LogAddress("in", where);
                }
                continue;
            }
        }

        /* A game-code infinite loop: move the game thread back to the last
         * snapshot instead of closing. */
        if (PcStateCanResume() && SuspendThread(sMainThread) != (DWORD)-1) {
            CONTEXT ctx;
            uintptr_t ip;
            int redirected = 0;
            memset(&ctx, 0, sizeof(ctx));
            ctx.ContextFlags = CONTEXT_FULL;
            if (GetThreadContext(sMainThread, &ctx)) {
#if defined(__i386__) || defined(_M_IX86)
                ip = ctx.Eip;
#else
                ip = ctx.Rip;
#endif
                if (InOurCode(ip)) {
                    RedirectToResume(&ctx);
                    redirected = SetThreadContext(sMainThread, &ctx) != 0;
                }
            }
            ResumeThread(sMainThread);
            if (redirected) {
                PcLog("[pc] HANG at frame %u - recovering\n", gPcFrameCount);
                LogAddress("at", ip);
                stuck = 0;
                lastFrame = gPcAlive;
                continue;
            }
        }

        if (InterlockedExchange(&sReporting, 1))
            return 0;
        {
            /* Capture where the main thread is, then let it run again right away:
             * a suspended thread may hold a lock (heap, stdio, graphics driver)
             * that logging or the message box below would wait on forever. */
            uintptr_t ip = 0, sp = 0;
            if (SuspendThread(sMainThread) != (DWORD)-1) {
                CONTEXT ctx;
                memset(&ctx, 0, sizeof(ctx));
                ctx.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
                if (GetThreadContext(sMainThread, &ctx)) {
#if defined(__i386__) || defined(_M_IX86)
                    ip = ctx.Eip;
                    sp = ctx.Esp;
#else
                    ip = ctx.Rip;
                    sp = ctx.Rsp;
#endif
                }
                ResumeThread(sMainThread);
            }
            PcLog("[pc] HANG: no new frame for %d seconds (frame %u)\n", HANG_SECONDS, gPcFrameCount);
            if (ip != 0) {
                LogAddress("at", ip);
                LogStack(sp);
            }
        }
        /* The game window belongs to the stuck thread; the message box would
         * wait on it (activation messages), so stop that thread first. */
        TerminateThread(sMainThread, 2);
        {
            char msg[320];
            snprintf(msg, sizeof(msg),
                     "El juego dejó de responder (cuadro %u).\n\n"
                     "Se guardaron los detalles en %s.\n"
                     "Envía ese archivo y cuenta qué estabas haciendo.",
                     gPcFrameCount, gPcLogHint);
            Report("Reino de Corazones", msg);
        }
        ExitProcess(2);
    }
}

void PcWinDiagInit(void* hwnd) {
    HMODULE mod = GetModuleHandleA(NULL);
    IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)mod;
    IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)((uint8_t*)mod + dos->e_lfanew);

    sWindow = (HWND)hwnd;
    sImageBase = (uintptr_t)mod;
    sImageEnd = sImageBase + nt->OptionalHeader.SizeOfImage;
    {
        IMAGE_SECTION_HEADER* s = IMAGE_FIRST_SECTION(nt);
        int i;
        for (i = 0; i < nt->FileHeader.NumberOfSections; i++, s++)
            if (!memcmp(s->Name, ".text", 6)) {
                sTextBase = sImageBase + s->VirtualAddress;
                sTextEnd = sTextBase + s->Misc.VirtualSize;
            }
    }
    sMainThreadId = GetCurrentThreadId();
    DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &sMainThread, 0, FALSE,
                    DUPLICATE_SAME_ACCESS);
    SetUnhandledExceptionFilter(CrashFilter);
    AddVectoredExceptionHandler(0, ResumeHandler); /* 0 = after the fault recovery */
    CreateThread(NULL, 0, Watchdog, NULL, 0, NULL);
}
#endif /* _WIN32 */
