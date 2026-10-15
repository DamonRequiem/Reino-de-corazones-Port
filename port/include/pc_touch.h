/*
 * pc_touch.h
 * On-screen controls for touch screens (port/pc_touch.c).
 */
#ifndef PC_TOUCH_H
#define PC_TOUCH_H

#include <stdint.h>
#include <SDL.h>

int PcTouchInit(SDL_Renderer* r);
void PcTouchReload(SDL_Renderer* r);
void PcTouchLayout(int ow, int oh, const SDL_Rect* game);
int PcTouchHandleEvent(const SDL_Event* e); /* 1 if it was a touch event */
void PcTouchReset(void);
uint16_t PcTouchHeld(void);                 /* GBA buttons held (KEYINPUT bits) */
int PcTouchTakeMenu(void);                  /* the menu button was tapped */
int PcTouchFastForward(void);
void PcTouchDraw(SDL_Renderer* r);
void PcTouchDrawBackdrop(SDL_Renderer* r, int ow, int oh, const SDL_Rect* game);
uint32_t PcTouchLastUse(void);
void PcTouchSetGamepad(int connected); /* hides the controls while a controller is connected */
void PcTouchGamepadUsed(void);
int PcTouchHidden(void);

#endif
