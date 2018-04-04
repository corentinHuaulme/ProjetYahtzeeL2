/**
* \file sdlCredit.c
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Contient les noms des auteurs du projet.
* \date Mardi 20 Février 2018
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
 \fn afficheCredit(SDL_Window* win, SDL_Renderer* ren)
 \brief Affiche les credits dans la fenêtre win.
**/
void afficheCredit(SDL_Window* win, SDL_Renderer* ren){	
	

	SDL_RenderClear(ren);
	SDL_RenderPresent( ren );
	SDL_Surface* sNom1 = NULL;
	SDL_Surface* sNom2 = NULL;
	SDL_Surface* sNom3 = NULL;
	SDL_Surface* sRetour = NULL;
	SDL_Surface* sImage = NULL;
	SDL_Rect * rImage = NULL;
	
	TTF_Font* Sans = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 60);
	SDL_Color White = {255, 255, 255};
	
	sImage = IMG_Load("tapis.jpg");

	SDL_Texture* mImage = SDL_CreateTextureFromSurface(ren, sImage);
	
	rImage = malloc(sizeof(SDL_Rect));
	rImage->x = 0; 
	rImage->y = 0;
	rImage->w = 1280;
	rImage->h = 720;

	SDL_RenderCopy(ren, mImage, NULL, rImage);

	sNom1 = TTF_RenderUTF8_Solid(Sans, "HUAULME Corentin", White);
	SDL_Texture* mNom1 = SDL_CreateTextureFromSurface(ren, sNom1);
	
	SDL_Rect rNom1;
	rNom1.x = 350; 
	rNom1.y = 110;
	SDL_QueryTexture(mNom1, NULL, NULL, &(rNom1.w), &(rNom1.h));
	SDL_RenderCopy(ren, mNom1, NULL, &rNom1);
	

	sNom2 = TTF_RenderUTF8_Solid(Sans,"DINGA Andy", White);
	SDL_Texture* mNom2 = SDL_CreateTextureFromSurface(ren, sNom2);
	
	SDL_Rect rNom2;
	rNom2.x = 350; 
	rNom2.y = 200;
	SDL_QueryTexture(mNom2, NULL, NULL, &(rNom2.w), &(rNom2.h));
	SDL_RenderCopy(ren, mNom2, NULL, &rNom2);
	
	sNom3 = TTF_RenderUTF8_Solid(Sans,"JIANG Lijuan", White);
	SDL_Texture* mNom3 = SDL_CreateTextureFromSurface(ren, sNom3);
	
	SDL_Rect rNom3;
	rNom3.x = 350; 
	rNom3.y = 290;
	SDL_QueryTexture(mNom3, NULL, NULL, &(rNom3.w), &(rNom3.h));
	SDL_RenderCopy(ren, mNom3, NULL, &rNom3);
	
	sRetour = TTF_RenderUTF8_Solid(Sans,"Retour", White);
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
