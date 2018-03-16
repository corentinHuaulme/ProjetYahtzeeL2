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

SDL_Rect * rLancer = NULL;
SDL_Rect * rDe1 = NULL;
SDL_Rect * rDe2 = NULL;
SDL_Rect * rDe3 = NULL;
SDL_Rect * rDe4 = NULL;
SDL_Rect * rDe5 = NULL;

SDL_Rect * rBrelan = NULL;
SDL_Rect * rPetiteS = NULL;
SDL_Rect * rGrandeS = NULL;
SDL_Rect * rFull = NULL;
SDL_Rect * rCarre = NULL;
SDL_Rect * rYahtzee = NULL;
SDL_Rect * rChance = NULL;
SDL_Rect * rCpt1 = NULL;
SDL_Rect * rCpt2 = NULL;
SDL_Rect * rCpt3 = NULL;
SDL_Rect * rCpt4 = NULL;
SDL_Rect * rCpt5 = NULL;
SDL_Rect * rCpt6 = NULL;

int nbLancer=2;
de_t * tabDe[5];
de_t * deGarde[5];

void initTab(){
	int i=0;
	for(i=0;i<5;i++){
		tabDe[i] = creerDe();
		deGarde[i] = creerDe();
	}
}

void afficheFenetre(SDL_Window* win, SDL_Renderer* ren){	

	int i = 0;
	for(i=0;i<5;i++){
		tabDe[i] = creerDe();
		if(deGarde[i]->nombreFace == 0){
			deGarde[i] = creerDe();
		}
	}
	lancerDe(tabDe,5);

	TTF_Font* Sans = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 24);
	SDL_Color White = {255, 255, 255};

	SDL_Surface* sLancer = NULL;
	SDL_Surface* sTour = NULL;
	SDL_Surface* sDe1 = NULL;
	SDL_Surface* sDe2 = NULL;
	SDL_Surface* sDe3 = NULL;
	SDL_Surface* sDe4 = NULL;
	SDL_Surface* sDe5 = NULL;
	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);
        /* Select the color for drawing. It is set to red here. */
        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);

        /* Clear the entire screen to our selected color. */
        SDL_RenderClear(ren);
	
	/* Ajout bouton lancer */
	if(nbLancer > 0){
		sLancer = TTF_RenderText_Solid(Sans, "Lancer", White);
	}else{
		sLancer = TTF_RenderText_Solid(Sans, "Tour suivant", White);
	}
	SDL_Texture* mLancer = SDL_CreateTextureFromSurface(ren, sLancer);

	rLancer = malloc(sizeof(SDL_Rect));
	rLancer->x = 350; 
	rLancer->y = 600;
	rLancer->w = 300;
	rLancer->h = 100;

	SDL_RenderCopy(ren, mLancer, NULL, rLancer);

	//SDL_RenderPresent( ren );
	/* fin ajout bouton lancer */


	/* Ajout texte "tour de XX" */
	sTour = TTF_RenderText_Solid(Sans, "Au tour de ", White);

	SDL_Texture* mTour = SDL_CreateTextureFromSurface(ren, sTour);
	
	SDL_Rect rTour;
	rTour.x = 650; 
	rTour.y = 50;
	rTour.w = 300;
	rTour.h = 100;

	SDL_RenderCopy(ren, mTour, NULL, &rTour);

	/* fin ajout texte "tour de XX" */
	/* Debut déclaration images dé */

	if(deGarde[0]->nombreFace != 0){
		sDe1 = IMG_Load(deGarde[0]->nomImage);
	}else{
		sDe1 = IMG_Load(tabDe[0]->nomImage);
	}

	SDL_Texture* mDe1 = SDL_CreateTextureFromSurface(ren, sDe1);
	
	rDe1 = malloc(sizeof(SDL_Rect));
	rDe1->x = 350; 
	rDe1->y = 200;
	rDe1->w = 50;
	rDe1->h = 50;

	SDL_RenderCopy(ren, mDe1, NULL, rDe1);
	
	if(deGarde[1]->nombreFace != 0){
		sDe2 = IMG_Load(deGarde[1]->nomImage);
	}else{
		sDe2 = IMG_Load(tabDe[1]->nomImage);
	}

	SDL_Texture* mDe2 = SDL_CreateTextureFromSurface(ren, sDe2);
	
	rDe2 = malloc(sizeof(SDL_Rect));
	rDe2->x = 400; 
	rDe2->y = 200;
	rDe2->w = 50;
	rDe2->h = 50;

	SDL_RenderCopy(ren, mDe2, NULL, rDe2);

	if(deGarde[2]->nombreFace != 0){
		sDe3 = IMG_Load(deGarde[2]->nomImage);
	}else{
		sDe3 = IMG_Load(tabDe[2]->nomImage);
	}

	SDL_Texture* mDe3 = SDL_CreateTextureFromSurface(ren, sDe3);
	
	rDe3 = malloc(sizeof(SDL_Rect));
	rDe3->x = 450; 
	rDe3->y = 200;
	rDe3->w = 50;
	rDe3->h = 50;

	SDL_RenderCopy(ren, mDe3, NULL, rDe3);

	if(deGarde[3]->nombreFace != 0){
		sDe4 = IMG_Load(deGarde[3]->nomImage);
	}else{
		sDe4 = IMG_Load(tabDe[3]->nomImage);
	}

	SDL_Texture* mDe4 = SDL_CreateTextureFromSurface(ren, sDe4);
	
	rDe4 = malloc(sizeof(SDL_Rect));
	rDe4->x = 500; 
	rDe4->y = 200;
	rDe4->w = 50;
	rDe4->h = 50;

	SDL_RenderCopy(ren, mDe4, NULL, rDe4);

	if(deGarde[4]->nombreFace != 0){
		sDe5 = IMG_Load(deGarde[4]->nomImage);
	}else{
		sDe5 = IMG_Load(tabDe[4]->nomImage);
	}

	SDL_Texture* mDe5 = SDL_CreateTextureFromSurface(ren, sDe5);
	
	rDe5 = malloc(sizeof(SDL_Rect));
	rDe5->x = 550; 
	rDe5->y = 200;
	rDe5->w = 50;
	rDe5->h = 50;

	SDL_RenderCopy(ren, mDe5, NULL, rDe5);

	SDL_RenderPresent( ren );

}

void showCombi(SDL_Window* win, SDL_Renderer* ren){
	sBrelan = TTF_RenderText_Solid(Sans, "Brelan : ", White);

	SDL_Texture* mBrelan = SDL_CreateTextureFromSurface(ren, sBrelan);
	
	rBrelan = malloc(sizeof(SDL_Rect));
	rBrelan->x = 250; 
	rBrelan->y = 200;
	rBrelan->w = 300;
	rBrelan->h = 100;

	/*rPetiteS;
	rGrandeSL;
	rFull;
	rCarre;
	rYahtzee;
	rChance;
	rCpt1;
	rCpt2;
	rCpt3;
	rCpt4;
	rCpt5;
	rCpt6;*/
}

int fermerFenetre(SDL_Window* win, SDL_Renderer* ren){
	SDL_DestroyWindow(win);
	IMG_Quit();
}

int fenetreJeu(SDL_Window* win, SDL_Renderer* ren){
	initTab();	
	afficheFenetre(win, ren);
	if( win )
	{
        	int running = 1; 
		while(running) {
			if(nbLancer == 0){
				showCombi(win, ren);
			}
			SDL_Event e; 
			while(SDL_PollEvent(&e)) { 
				switch(e.type) { 
					case SDL_QUIT: running = 0; break; 
					case SDL_MOUSEBUTTONDOWN:
					    switch (e.button.button)
					    {
						case SDL_BUTTON_LEFT:
							if(check_click_in_rect(e.motion.x, e.motion.y, rLancer)){
								nbLancer--;
								afficheFenetre(win,ren);
							}
							if(check_click_in_rect(e.motion.x, e.motion.y, rDe1)){
								if(deGarde[0]->nombreFace == 0)
									deGarde[0] = tabDe[0];
							}
							if(check_click_in_rect(e.motion.x, e.motion.y, rDe2)){
								if(deGarde[1]->nombreFace == 0)
									deGarde[1] = tabDe[1];
							}
							if(check_click_in_rect(e.motion.x, e.motion.y, rDe3)){
								if(deGarde[2]->nombreFace == 0)
									deGarde[2] = tabDe[2];
							}
							if(check_click_in_rect(e.motion.x, e.motion.y, rDe4)){
								if(deGarde[3]->nombreFace == 0)
									deGarde[3] = tabDe[3];
							}
							if(check_click_in_rect(e.motion.x, e.motion.y, rDe5)){
								if(deGarde[4]->nombreFace == 0)
									deGarde[4] = tabDe[4];
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
	fermerFenetre(win, ren);
	return 0;
}
