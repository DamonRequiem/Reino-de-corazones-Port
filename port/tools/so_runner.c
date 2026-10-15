/*
 * so_runner.c
 * Test helper: runs a game built as a shared library (python3 port/build.py
 * --target linuxarmso --app headless) the way the Android app does: loaded
 * with dlopen at an address chosen at run time, then its main().
 *     so_runner path/to/khcom_headless.so [game arguments...]
 */
#include <dlfcn.h>
#include <stdio.h>

int main(int argc, char** argv) {
    void* h;
    int (*gameMain)(int, char**);
    if (argc < 2) {
        fprintf(stderr, "usage: so_runner game.so [args...]\n");
        return 1;
    }
    h = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    if (!h) {
        fprintf(stderr, "so_runner: %s\n", dlerror());
        return 1;
    }
    gameMain = (int (*)(int, char**))dlsym(h, "main");
    if (!gameMain) {
        fprintf(stderr, "so_runner: no main in %s\n", argv[1]);
        return 1;
    }
    return gameMain(argc - 1, argv + 1);
}
