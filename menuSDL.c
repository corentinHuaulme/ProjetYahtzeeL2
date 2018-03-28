/**

 *\file menuSDL.c
 *\brief Programme qui affiche le menu fait avec la SDL 
 *\author Corentin Hualme Dinga Andy
 *\version 0.9.6
 *\date vendredi 23 mars 2018
 *
 */

#include <stdio.h>
#include "sdlJeu.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "de.h"
#include "sdl.h"
#include "combinaison.h"
#include "joueur.h"
#include "feuilleScore.h"

/**
 \fn menuPrincipale(SDL_Window* pWindow, SDL_Renderer* renderer)
 \brief Affiche les différentes option du menu.
**/

void menuPrincipale(SDL_Window* pWindow, SDL_Renderer* renderer){
	SDL_Window* pWindow = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Surface* sTitre = NULL;
	SDL_Surface* sJouer = NULL;
	SDL_Surface* sRegles = NULL;
	SDL_Surface* sQuitter = NULL;
	SDL_Surface* sCredit = NULL;
	SDL_Rect rJouer;
	SDL_Rect rRegles;
	SDL_Rect rQuitter;
	SDL_Rect rCredit;    	
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
	
	pWindow = SDL_CreateWindow("YAHTZEE",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 1280,720,SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = NULL;
	renderer =  SDL_CreateRenderer( pWindow, -1, SDL_RENDERER_ACCELERATED);
	
    
    SDL_SetRenderDrawColor( renderer, 0, 140, 90, 0);

    
    SDL_RenderClear( renderer );
	TTF_Init();
	TTF_Font* Sans = TTF_OpenFont("fonts/Cabin/Cabin-Regular.ttf", 30); 

	if(Sans == NULL){
		printf("\nERROR\n");
	}

	SDL_Color White = {255, 255, 255};
	
	sTitre = TTF_RenderText_Solid(Sans, "Yahtzee", White);
	SDL_Texture* mTitre = SDL_CreateTextureFromSurface(renderer, sTitre);
	
	SDL_Rect rTitre;
	rTitre.x = 250; 
	rTitre.y = 50;
	SDL_QueryTexture(mTitre, NULL, NULL, &(rTitre.w), &(rTitre.h));
	SDL_RenderCopy(renderer, mTitre, NULL, &rTitre);

    
	sJouer = TTF_RenderText_Solid(Sans, "Jouer", White);

	SDL_Texture* mJouer = SDL_CreateTextureFromSurface(renderer, sJouer);
	
	SDL_Rect rJouer;
	rJouer.x = 350; 
	rJouer.y = 200;
	SDL_QueryTexture(mJouer, NULL, NULL, &(rJouer.w), &(rJouer.h));
	SDL_RenderCopy(renderer, mJouer, NULL, &rJouer);


	sRegles = TTF_RenderText_Solid(Sans, "Regles du jeu", White);
	SDL_Texture* mRegles = SDL_CreateTextureFromSurface(renderer, sRegles);
	
	SDL_Rect rRegles;
	rRegles.x = 350; 
	rRegles.y = 300;
	SDL_QueryTexture(mRegles, NULL, NULL, &(rRegles.w), &(rRegles.h));
	SDL_RenderCopy(renderer, mRegles, NULL, &rRegles);

	
	sQuitter = TTF_RenderText_Solid(Sans, "Quitter", White);
	SDL_Texture* mQuitter = SDL_CreateTextureFromSurface(renderer, sQuitter);
	
	SDL_Rect rQuitter;
	rQuitter.x = 350; 
	rQuitter.y = 400;
	SDL_QueryTexture(mQuitter, NULL, NULL, &(rQuitter.w), &(rQuitter.h));
	SDL_RenderCopy(renderer, mQuitter, NULL, &rQuitter);


	sCredit = TTF_RenderText_Solid(Sans, "Credits", White);
	SDL_Texture* mCredit = SDL_CreateTextureFromSurface(renderer, sCredit);
	
	SDL_Rect rCredit;
	rCredit.x = 350; 
	rCredit.y = 500;
	SDL_QueryTexture(mCredit, NULL, NULL, &(rCredit.w), &(rCredit.h));
	SDL_RenderCopy(renderer, mCredit, NULL, &rCredit);

	SDL_RenderPresent( renderer );
}