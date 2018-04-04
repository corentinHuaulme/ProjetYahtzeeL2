/**
* \file sdlRegle.c
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Contient les règle du jeu.
* \date Vendredi 23 mars 2018
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
 \fn afficheRegle(SDL_Window* win, SDL_Renderer* ren)
 \brief Affiche les règles du jeu dans la fenêtre win.
**/
void afficheRegle(SDL_Window* win, SDL_Renderer* ren){	
	
	SDL_RenderClear(ren);
	SDL_RenderPresent( ren );
	SDL_Surface* sRegle1 = NULL;
	SDL_Surface* sRegle2 = NULL;
	SDL_Surface* sRegle3 = NULL;
	SDL_Surface* sRegle4 = NULL;
	SDL_Surface* sRegle5 = NULL;
	SDL_Surface* sRegle6 = NULL;
	SDL_Surface* sRegle8 = NULL;
	SDL_Surface* sRegle9 = NULL;
	SDL_Surface* sRegle7 = NULL;
	SDL_Surface* sRetour = NULL;
	SDL_Surface* sImage = NULL;
	SDL_Rect * rImage = NULL;


	
	TTF_Font* Sans = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 30);
	SDL_Color White = {255, 255, 255};
	
	sImage = IMG_Load("tapis.jpg");

	SDL_Texture* mImage = SDL_CreateTextureFromSurface(ren, sImage);
	
	rImage = malloc(sizeof(SDL_Rect));
	rImage->x = 0; 
	rImage->y = 0;
	rImage->w = 1280;
	rImage->h = 720;

	SDL_RenderCopy(ren, mImage, NULL, rImage);

	sRegle1 = TTF_RenderUTF8_Solid(Sans, "Regles du jeu : Le Yahtzee se joue avec 5 des et se finit une fois toutes les cases de", White);
	SDL_Texture* mRegle1 = SDL_CreateTextureFromSurface(ren, sRegle1);
	
	SDL_Rect rRegle1;
	rRegle1.x = 40; 
	rRegle1.y = 140;
	SDL_QueryTexture(mRegle1, NULL, NULL, &(rRegle1.w), &(rRegle1.h));
	SDL_RenderCopy(ren, mRegle1, NULL, &rRegle1);
	

	sRegle2 = TTF_RenderUTF8_Solid(Sans,"la fiche de score remplies. Chaque joueur joue tout à tour et dispose de 3 lancers à chaque coup.", White);
	SDL_Texture* mRegle2 = SDL_CreateTextureFromSurface(ren, sRegle2);
	
	SDL_Rect rRegle2;
	rRegle2.x = 40; 
	rRegle2.y = 170;
	SDL_QueryTexture(mRegle2, NULL, NULL, &(rRegle2.w), &(rRegle2.h));
	SDL_RenderCopy(ren, mRegle2, NULL, &rRegle2);
	
	sRegle3 = TTF_RenderUTF8_Solid(Sans,"L’objectif etant de realiser des combinaisons qui rapportent des points.", White);
	SDL_Texture* mRegle3 = SDL_CreateTextureFromSurface(ren, sRegle3);
	
	SDL_Rect rRegle3;
	rRegle3.x = 40; 
	rRegle3.y = 200;
	SDL_QueryTexture(mRegle3, NULL, NULL, &(rRegle3.w), &(rRegle3.h));
	SDL_RenderCopy(ren, mRegle3, NULL, &rRegle3);
	
	sRegle4 = TTF_RenderUTF8_Solid(Sans,"Le joueur a le choix de reprendre tous ou une partie des des à chaque lance,", White);
	SDL_Texture* mRegle4 = SDL_CreateTextureFromSurface(ren, sRegle4);
	
	SDL_Rect rRegle4;
	rRegle4.x = 40; 
	rRegle4.y = 230;
	SDL_QueryTexture(mRegle4, NULL, NULL, &(rRegle4.w), &(rRegle4.h));
	SDL_RenderCopy(ren, mRegle4, NULL, &rRegle4);
	
	sRegle5 = TTF_RenderUTF8_Solid(Sans,"selon son gre, pour tenter d’obtenir la combinaison voulue.", White);
	SDL_Texture* mRegle5 = SDL_CreateTextureFromSurface(ren, sRegle5);
	
	SDL_Rect rRegle5;
	rRegle5.x = 40; 
	rRegle5.y = 260;
	SDL_QueryTexture(mRegle5, NULL, NULL, &(rRegle5.w), &(rRegle5.h));
	SDL_RenderCopy(ren, mRegle5, NULL, &rRegle5);
	
	sRegle6 = TTF_RenderUTF8_Solid(Sans,"A chaque tour, le joueur doit obligatoirement inscrire son score dans une des", White);
	SDL_Texture* mRegle6 = SDL_CreateTextureFromSurface(ren, sRegle6);
	
	SDL_Rect rRegle6;
	rRegle6.x = 40; 
	rRegle6.y = 290;
	SDL_QueryTexture(mRegle6, NULL, NULL, &(rRegle6.w), &(rRegle6.h));
	SDL_RenderCopy(ren, mRegle6, NULL, &rRegle6);
	
	sRegle7 = TTF_RenderUTF8_Solid(Sans,"cases de la feuille de marque que ce soit par un X ", White);
	SDL_Texture* mRegle7 = SDL_CreateTextureFromSurface(ren, sRegle7);
	
	SDL_Rect rRegle7;
	rRegle7.x = 40; 
	rRegle7.y = 320;
	SDL_QueryTexture(mRegle7, NULL, NULL, &(rRegle7.w), &(rRegle7.h));
	SDL_RenderCopy(ren, mRegle7, NULL, &rRegle7);
	
	sRegle8 = TTF_RenderUTF8_Solid(Sans,"ou par les points qu’il a obtenu.", White);
	SDL_Texture* mRegle8 = SDL_CreateTextureFromSurface(ren, sRegle8);
	
	TTF_Font* Police = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 60);
	sRetour = TTF_RenderUTF8_Solid(Police,"Retour", White);
	SDL_Texture* mRetour = SDL_CreateTextureFromSurface(ren, sRetour);
	
	SDL_Rect rRetour;
	rRetour.x = 10; 
	rRetour.y = 10;
	SDL_QueryTexture(mRetour, NULL, NULL, &(rRetour.w), &(rRetour.h));
	SDL_RenderCopy(ren, mRetour, NULL, &rRetour);
	
	SDL_RenderPresent( ren );
	if( win)
	{
        	int running = 1; 
		while(running) { 
			SDL_Event e; 
			while(SDL_PollEvent(&e)) { 
				switch(e.type) { 
					case SDL_QUIT: running = 0; 
					break; 
					case SDL_MOUSEBUTTONDOWN:
					    switch (e.button.button)
					    {
						case SDL_BUTTON_LEFT:
							if(check_click_in_rect(e.motion.x, e.motion.y, &rRetour)){
								menuPrincipal(win, ren);
								running = 0;
							}
						    break;
					    }
					    break;
				} 
			} 
		}
	 }
	SDL_DestroyWindow(win);
	
}