/**
* \file sdl.c
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Contient la fenêtre principale du jeu
* \date Vendredi 23 mars 2018
*/

#include <stdio.h>
#include "sdlJeu.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "de.h"
#include "sdl.h"
#include "sdlDeclaJoueur.h"
#include "combinaison.h"
#include "joueur.h"
#include "feuilleScore.h"

/**
 \fn check_click_in_rect(int x, int y, struct SDL_Rect *rect)
 \brief Verifie le rectangle où le curseur de la souris pointe.
**/
int check_click_in_rect(int x, int y, struct SDL_Rect *rect)
{
    /* Check X coordinate is within rectangle range */
    if (x >= rect->x && x < (rect->x + rect->w))
    {
        /* Check Y coordinate is within rectangle range */
        if (y >= rect->y && y < (rect->y + rect->h))
        {
            /* X and Y is inside the rectangle */
            return 1;
        }
    }

    /* X or Y is outside the rectangle */
    return 0;
}

/**
 \fn menuPrincipal(SDL_Window* pWindow, SDL_Renderer* renderer)
 \brief Affiche la fenêtre win qui est la fenêtre principale du jeu Cette fenêtre contient les différents onglets du menu.
**/
void menuPrincipal(SDL_Window* pWindow, SDL_Renderer* renderer){
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Surface* sImage = NULL;
	SDL_Surface* sImage2 = NULL;
	SDL_Surface* sImage_de = NULL;
	SDL_Surface* sImage_de2 = NULL;
	SDL_Surface* sTitre = NULL;
	SDL_Surface* sJouer = NULL;
	SDL_Surface* sRegles = NULL;
	SDL_Surface* sQuitter = NULL;
	SDL_Surface* sCredit = NULL;
	SDL_Rect * rImage = NULL;
	SDL_Rect * rImage2 = NULL;
	SDL_Rect * rImage_de = NULL;
	SDL_Rect * rImage_de2 = NULL;
	  	
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
	if(!pWindow){
		pWindow = SDL_CreateWindow("YAHTZEE",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 1280,720,SDL_WINDOW_SHOWN);
		renderer =  SDL_CreateRenderer( pWindow, -1, SDL_RENDERER_ACCELERATED);
	}

    
    SDL_RenderClear( renderer );
    SDL_RenderPresent( renderer );
	TTF_Init();
	TTF_Font* Sans = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 45); 

	if(Sans == NULL){
		printf("\nERROR\n");
	}
	sImage = IMG_Load("tapis.jpg");

	SDL_Texture* mImage = SDL_CreateTextureFromSurface(renderer, sImage);
	
	rImage = malloc(sizeof(SDL_Rect));
	rImage->x = 0; 
	rImage->y = 0;
	rImage->w = 1280;
	rImage->h = 720;

	SDL_RenderCopy(renderer, mImage, NULL, rImage);
	
	sImage_de = IMG_Load("des_rouge.png");

	SDL_Texture* mImage_de = SDL_CreateTextureFromSurface(renderer, sImage_de);
	
	rImage_de = malloc(sizeof(SDL_Rect));
	rImage_de->x = 100; 
	rImage_de->y = 360;
	rImage_de->w = 130;
	rImage_de->h = 90;

	SDL_RenderCopy(renderer, mImage_de, NULL, rImage_de);
	
	sImage_de2 = IMG_Load("des_rouge.png");

	SDL_Texture* mImage_de2 = SDL_CreateTextureFromSurface(renderer, sImage_de2);
	
	rImage_de2 = malloc(sizeof(SDL_Rect));
	rImage_de2->x = 1010; 
	rImage_de2->y = 360;
	rImage_de2->w = 130;
	rImage_de2->h = 90;

	SDL_RenderCopy(renderer, mImage_de2, NULL, rImage_de2);
	SDL_Color White = {255, 255, 255};
	
	sImage2 = IMG_Load("small.png");

	SDL_Texture* mImage2 = SDL_CreateTextureFromSurface(renderer, sImage2);
	
	rImage2 = malloc(sizeof(SDL_Rect));
	rImage2->x = 450; 
	rImage2->y = 30;
	rImage2->w = 350;
	rImage2->h = 100;

	SDL_RenderCopy(renderer, mImage2, NULL, rImage2);
	
	/*sTitre = TTF_RenderText_Solid(Sans, "Yahtzee", White);
	SDL_Texture* mTitre = SDL_CreateTextureFromSurface(renderer, sTitre);
	
	SDL_Rect rTitre;
	rTitre.x = 250; 
	rTitre.y = 50;
	SDL_QueryTexture(mTitre, NULL, NULL, &(rTitre.w), &(rTitre.h));
	SDL_RenderCopy(renderer, mTitre, NULL, &rTitre);*/

    
	sJouer = TTF_RenderText_Solid(Sans, "Jouer", White);

	SDL_Texture* mJouer = SDL_CreateTextureFromSurface(renderer, sJouer);
	
	SDL_Rect rJouer;
	rJouer.x = 500; 
	rJouer.y = 200;
	SDL_QueryTexture(mJouer, NULL, NULL, &(rJouer.w), &(rJouer.h));
	SDL_RenderCopy(renderer, mJouer, NULL, &rJouer);


	sRegles = TTF_RenderText_Solid(Sans, "Regles du jeu", White);
	SDL_Texture* mRegles = SDL_CreateTextureFromSurface(renderer, sRegles);
	
	SDL_Rect rRegles;
	rRegles.x = 500; 
	rRegles.y = 300;
	SDL_QueryTexture(mRegles, NULL, NULL, &(rRegles.w), &(rRegles.h));
	SDL_RenderCopy(renderer, mRegles, NULL, &rRegles);

	
	sQuitter = TTF_RenderText_Solid(Sans, "Quitter", White);
	SDL_Texture* mQuitter = SDL_CreateTextureFromSurface(renderer, sQuitter);
	
	SDL_Rect rQuitter;
	rQuitter.x = 500; 
	rQuitter.y = 500;
	SDL_QueryTexture(mQuitter, NULL, NULL, &(rQuitter.w), &(rQuitter.h));
	SDL_RenderCopy(renderer, mQuitter, NULL, &rQuitter);


	sCredit = TTF_RenderText_Solid(Sans, "Credits", White);
	SDL_Texture* mCredit = SDL_CreateTextureFromSurface(renderer, sCredit);
	
	SDL_Rect rCredit;
	rCredit.x = 500; 
	rCredit.y = 400;
	SDL_QueryTexture(mCredit, NULL, NULL, &(rCredit.w), &(rCredit.h));
	SDL_RenderCopy(renderer, mCredit, NULL, &rCredit);

	SDL_RenderPresent( renderer );

	
	if( pWindow )
	{
        	int running = 1; 
		while(running) { 
			SDL_Event e; 
			while(running && SDL_PollEvent(&e)) { 
				switch(e.type) { 
					case SDL_QUIT: running = 0; 
					break; 
					case SDL_MOUSEBUTTONDOWN:
					    switch (e.button.button)
					    {
						case SDL_BUTTON_LEFT:
							if(check_click_in_rect(e.motion.x, e.motion.y, &rJouer)){
								fenetreJoueur(pWindow, renderer);
								running = 0;
							}else if(check_click_in_rect(e.motion.x, e.motion.y, &rRegles)){
								afficheRegle(pWindow, renderer);
								running = 1;
							}else if(check_click_in_rect(e.motion.x, e.motion.y, &rQuitter)){
								running = 0;
							}else if(check_click_in_rect(e.motion.x, e.motion.y, &rCredit)){
								afficheCredit(pWindow, renderer);
								running = 1;
							}
						    break;
					    }
					    break;
				} 
			} 
		}
	} else {
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

	
	SDL_DestroyWindow(pWindow);
	TTF_Quit();
   	SDL_Quit();

}

int main(){
	SDL_Window* pWindow = NULL;
	SDL_Renderer* renderer = NULL;
	menuPrincipal(pWindow, renderer);
}