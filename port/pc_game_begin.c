/*
 * pc_game_begin.c / pc_game_end.c
 * Markers around the game's global variables.
 *
 * port/build.py links pc_game_begin.o first and pc_game_end.o right after the
 * game and data objects. The linker keeps .data and .bss input sections in
 * command-line order, so everything the game owns sits between these markers.
 * A soft reset restores that range to its boot-time contents, like the GBA
 * clearing its RAM (see PcSaveGameState / PcRestoreGameState).
 */
char gPcGameDataBegin[4] __attribute__((aligned(16))) = {1, 2, 3, 4};
char gPcGameBssBegin[4] __attribute__((aligned(16)));
