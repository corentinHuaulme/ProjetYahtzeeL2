#include <stdio.h>
#include "sdlDeclaJoueur.h"
#include "sdl.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

SDL_Rect * rLettre1 = NULL;
SDL_Rect * rLettre2 = NULL;
SDL_Rect * rLettre3 = NULL;
SDL_Rect * rLettreUp1 = NULL;
SDL_Rect * rLettreDown1 = NULL;
SDL_Rect * rLettreUp2 = NULL;
SDL_Rect * rLettreDown2 = NULL;
SDL_Rect * rLettreUp3 = NULL;
SDL_Rect * rLettreDown3 = NULL;

SDL_Surface* sLettre1 = NULL;
SDL_Surface* sLettre2 = NULL;
SDL_Surface* sLettre3 = NULL;

char ltr1='A';
char ltr2='A';
char ltr3='A';

int afficheFenetreJoueur(SDL_Window* win, SDL_Renderer* ren)
{
	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);
	TTF_Font* Sans = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 50);
	SDL_Color White = {255, 255, 255};

	SDL_Surface* sSuivant = NULL;
	SDL_Surface* sLettreUp1 = NULL;
	SDL_Surface* sLettreDown1 = NULL;
	SDL_Surface* sLettreUp2 = NULL;
	SDL_Surface* sLettreDown2 = NULL;
	SDL_Surface* sLettreUp3 = NULL;
	SDL_Surface* sLettreDown3 = NULL;

	sSuivant = TTF_RenderText_Solid(Sans, "Suivant", White);
	SDL_Texture* mSuivant = SDL_CreateTextureFromSurface(ren, sSuivant);
	
	SDL_Rect* rSuivant = NULL;
	rSuivant = malloc(sizeof(SDL_Rect));
	rSuivant->x = 400; 
	rSuivant->y = 450;
	SDL_QueryTexture(mSuivant, NULL, NULL, &(rSuivant->w), &(rSuivant->h));
	SDL_RenderCopy(ren, mSuivant, NULL, rSuivant);
	
	char * l = &(ltr1);
	l = &(l[0]);

	sLettre1 = TTF_RenderText_Solid(Sans,&(l[0]), White);
	SDL_Texture* mLettre1 = SDL_CreateTextureFromSurface(ren, sLettre1);
	
	rLettre1 = malloc(sizeof(SDL_Rect));
	rLettre1->x = 400; 
	rLettre1->y = 250;
	SDL_QueryTexture(mLettre1, NULL, NULL, &(rLettre1->w), &(rLettre1->h));
	SDL_RenderCopy(ren, mLettre1, NULL, rLettre1);
	

	sLettre2 = TTF_RenderText_Solid(Sans, &(ltr2), White);
	SDL_Texture* mLettre2 = SDL_CreateTextureFromSurface(ren, sLettre2);
	
	rLettre2 = malloc(sizeof(SDL_Rect));
	rLettre2->x = 450; 
	rLettre2->y = 250;
	SDL_QueryTexture(mLettre2, NULL, NULL, &(rLettre2->w), &(rLettre2->h));
	SDL_RenderCopy(ren, mLettre2, NULL, rLettre2);


	sLettre3 = TTF_RenderText_Solid(Sans, &(ltr3), White);
	SDL_Texture* mLettre3 = SDL_CreateTextureFromSurface(ren, sLettre3);
	
	rLettre3 = malloc(sizeof(SDL_Rect));
	rLettre3->x = 500; 
	rLettre3->y = 250;
	SDL_QueryTexture(mLettre3, NULL, NULL, &(rLettre3->w), &(rLettre3->h));
	SDL_RenderCopy(ren, mLettre3, NULL, rLettre3);

	sLettreUp1 = IMG_Load("flecheHaut.png");

	SDL_Texture* mLettreUp1 = SDL_CreateTextureFromSurface(ren, sLettreUp1);
	
	rLettreUp1 = malloc(sizeof(SDL_Rect));
	rLettreUp1->x = 393; 
	rLettreUp1->y = 200;
	rLettreUp1->w = 50;
	rLettreUp1->h = 50;

	SDL_RenderCopy(ren, mLettreUp1, NULL, rLettreUp1);


	sLettreUp2 = IMG_Load("flecheHaut.png");

	SDL_Texture* mLettreUp2 = SDL_CreateTextureFromSurface(ren, sLettreUp2);
	
	rLettreUp2 = malloc(sizeof(SDL_Rect));
	rLettreUp2->x = 443; 
	rLettreUp2->y = 200;
	rLettreUp2->w = 50;
	rLettreUp2->h = 50;

	SDL_RenderCopy(ren, mLettreUp2, NULL, rLettreUp2);


	sLettreUp3 = IMG_Load("flecheHaut.png");

	SDL_Texture* mLettreUp3 = SDL_CreateTextureFromSurface(ren, sLettreUp3);
	
	rLettreUp3 = malloc(sizeof(SDL_Rect));
	rLettreUp3->x = 493; 
	rLettreUp3->y = 200;
	rLettreUp3->w = 50;
	rLettreUp3->h = 50;

	SDL_RenderCopy(ren, mLettreUp3, NULL, rLettreUp3);


	sLettreDown1 = IMG_Load("flecheBas.png");

	SDL_Texture* mLettreDown1 = SDL_CreateTextureFromSurface(ren, sLettreDown1);	
	rLettreDown1 = malloc(sizeof(SDL_Rect));
	rLettreDown1->x = 393; 
	rLettreDown1->y = 315;
	rLettreDown1->w = 50;
	rLettreDown1->h = 50;

	SDL_RenderCopy(ren, mLettreDown1, NULL, rLettreDown1);


	sLettreDown2 = IMG_Load("flecheBas.png");

	SDL_Texture* mLettreDown2 = SDL_CreateTextureFromSurface(ren, sLettreDown2);
	
	rLettreDown2 = malloc(sizeof(SDL_Rect));
	rLettreDown2->x = 443; 
	rLettreDown2->y = 315;
	rLettreDown2->w = 50;
	rLettreDown2->h = 50;

	SDL_RenderCopy(ren, mLettreDown2, NULL, rLettreDown2);


	sLettreDown3 = IMG_Load("flecheBas.png");

	SDL_Texture* mLettreDown3 = SDL_CreateTextureFromSurface(ren, sLettreDown3);
	
	rLettreDown3 = malloc(sizeof(SDL_Rect));
	rLettreDown3->x = 493; 
	rLettreDown3->y = 315;
	rLettreDown3->w = 50;
	rLettreDown3->h = 50;

	SDL_RenderCopy(ren, mLettreDown3, NULL, rLettreDown3);

	SDL_RenderPresent(ren);
}


int fenetreJoueur(SDL_Window* win, SDL_Renderer* ren)
{
	afficheFenetreJoueur(win,ren);
	if(win){
		int running = 1;
		while(running){
			while(running) {
				SDL_Event e; 
				while(SDL_PollEvent(&e)) { 
					switch(e.type) { 
						case SDL_QUIT: running = 0; break;
						case SDL_MOUSEBUTTONDOWN:
							switch (e.button.button)
							{
								case SDL_BUTTON_LEFT:
									if(check_click_in_rect(e.motion.x, e.motion.y, rLettreUp1)){
											ltr1 = ltr1-1;
											afficheFenetreJoueur(win,ren);											
									}if(check_click_in_rect(e.motion.x, e.motion.y, rLettreDown1)){
											ltr1=ltr1+1;
											afficheFenetreJoueur(win,ren);											
									}if(check_click_in_rect(e.motion.x, e.motion.y, rLettreUp2)){
											ltr2=ltr2-1;
											//afficheFenetreJoueur(win,ren);											
									}if(check_click_in_rect(e.motion.x, e.motion.y, rLettreDown2)){
											ltr2=ltr2+1;
											//afficheFenetreJoueur(win,ren);											
									}if(check_click_in_rect(e.motion.x, e.motion.y, rLettreUp3)){
											ltr3=ltr3-1;
											//afficheFenetreJoueur(win,ren);											
									}if(check_click_in_rect(e.motion.x, e.motion.y, rLettreDown3)){
											ltr3=ltr3+1;
											//afficheFenetreJoueur(win,ren);											
									}
									break;
							}
							break;
					}

				}
			}
		}
	}
}