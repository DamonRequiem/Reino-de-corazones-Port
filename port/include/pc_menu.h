/*
 * pc_menu.h
 * The in-game menu opened with Esc (port/pc_menu.c).
 */
#ifndef PC_MENU_H
#define PC_MENU_H

#include <SDL.h>
#include "pc_video.h"

enum {
    PC_MENU_NONE,
    PC_MENU_CHANGED,     /* a setting in gPcConfig changed: apply it */
    PC_MENU_CLOSED,
    PC_MENU_SAVE_STATE,
    PC_MENU_LOAD_STATE,
    PC_MENU_QUIT,
};

int PcMenuInit(SDL_Renderer* r, int launched);
void PcMenuSetMonitorHz(int hz);
int PcMenuIsOpen(void);
void PcMenuOpen(void);
void PcMenuClose(void);
int PcMenuHandleEvent(SDL_Renderer* r, const SDL_Event* e);
void PcMenuDraw(SDL_Renderer* r);
int PcMenuPreviewing(void);

#endif
