#ifndef _PROJET_SDLJEU_H
#define _PROJET_SDLJEU_H
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "joueur.h"
#include "SDL2/SDL_image.h"

int fenetreJeu(SDL_Window* win, SDL_Renderer* ren, joueur_t **, int nbJoueur);
int afficherMessageBox(char*,void (*p)(feuille_score_t *, combinaison_t), SDL_Window * win, SDL_Renderer *ren);
int afficheFinPartie(SDL_Window * win, SDL_Renderer * ren);

#endif
