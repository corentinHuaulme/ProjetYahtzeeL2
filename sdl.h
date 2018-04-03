
#ifndef _PROJET_SDL_H
#define _PROJET_SDL_H
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

int check_click_in_rect(int x, int y, struct SDL_Rect *rect);
void menuPrincipal(SDL_Window* pWindow, SDL_Renderer* renderer);

#endif