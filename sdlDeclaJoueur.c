#include <stdio.h>
#include "sdlDeclaJoueur.h"
#include "sdl.h"
#include "sdlJeu.h"
#include "joueur.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"


SDL_Rect * rSuivant = NULL;
SDL_Rect * rJouer = NULL;
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

char nom[5]="A\0A\0A";
joueur_t * joueurs[4];
int nbJoueur=0;

int afficheFenetreJoueur(SDL_Window* win, SDL_Renderer* ren)
{
	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);
	TTF_Font* Sans = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 50);
	SDL_Color White = {255, 255, 255};
	//SDL_SetRenderDrawColor( ren, 0, 160, 50, 0);
	SDL_RenderClear(ren);	
	SDL_Surface* sImage = NULL;
	SDL_Surface* sSuivant = NULL;
	SDL_Surface* sJouer = NULL;
	SDL_Surface* sLettreUp1 = NULL;
	SDL_Surface* sLettreDown1 = NULL;
	SDL_Surface* sLettreUp2 = NULL;
	SDL_Surface* sLettreDown2 = NULL;
	SDL_Surface* sLettreUp3 = NULL;
	SDL_Surface* sLettreDown3 = NULL;
	SDL_Rect * rImage = NULL;
	
	sImage = IMG_Load("tapis.jpg");

	SDL_Texture* mImage = SDL_CreateTextureFromSurface(ren, sImage);
	
	rImage = malloc(sizeof(SDL_Rect));
	rImage->x = 0; 
	rImage->y = 0;
	rImage->w = 1280;
	rImage->h = 720;

	SDL_RenderCopy(ren, mImage, NULL, rImage);
	
	if(nbJoueur<4){
		sSuivant = TTF_RenderText_Solid(Sans, "Ajout   joueur", White);
		SDL_Texture* mSuivant = SDL_CreateTextureFromSurface(ren, sSuivant);
	
		rSuivant = malloc(sizeof(SDL_Rect));
		rSuivant->x = 300; 
		rSuivant->y = 550;
		SDL_QueryTexture(mSuivant, NULL, NULL, &(rSuivant->w), &(rSuivant->h));
		SDL_RenderCopy(ren, mSuivant, NULL, rSuivant);
	}
	if(nbJoueur>1){
		sJouer = TTF_RenderText_Solid(Sans, "Jouer !", White);
		SDL_Texture* mJouer = SDL_CreateTextureFromSurface(ren, sJouer);
	
		rJouer = malloc(sizeof(SDL_Rect));
		if(nbJoueur>3){	
			rJouer->x = 500;
		}else{
			rJouer->x = 650;
		}
		rJouer->y = 550;
		SDL_QueryTexture(mJouer, NULL, NULL, &(rJouer->w), &(rJouer->h));
		SDL_RenderCopy(ren, mJouer, NULL, rJouer);
	}

	sLettre1 = TTF_RenderText_Solid(Sans,&(nom[0]), White);
	SDL_Texture* mLettre1 = SDL_CreateTextureFromSurface(ren, sLettre1);
	
	rLettre1 = malloc(sizeof(SDL_Rect));
	rLettre1->x = 400; 
	rLettre1->y = 250;
	SDL_QueryTexture(mLettre1, NULL, NULL, &(rLettre1->w), &(rLettre1->h));
	SDL_RenderCopy(ren, mLettre1, NULL, rLettre1);
	

	sLettre2 = TTF_RenderText_Solid(Sans, &(nom[2]), White);
	SDL_Texture* mLettre2 = SDL_CreateTextureFromSurface(ren, sLettre2);
	
	rLettre2 = malloc(sizeof(SDL_Rect));
	rLettre2->x = 450; 
	rLettre2->y = 250;
	SDL_QueryTexture(mLettre2, NULL, NULL, &(rLettre2->w), &(rLettre2->h));
	SDL_RenderCopy(ren, mLettre2, NULL, rLettre2);


	sLettre3 = TTF_RenderText_Solid(Sans, &(nom[4]), White);
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
	printf("nbJoueur : %i\n", nbJoueur);
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
										nom[0] = nom[0]-1;
										afficheFenetreJoueur(win,ren);											
									}else if(check_click_in_rect(e.motion.x, e.motion.y, rLettreDown1)){
										nom[0]=nom[0]+1;
										afficheFenetreJoueur(win,ren);											
									}else if(check_click_in_rect(e.motion.x, e.motion.y, rLettreUp2)){
										nom[2]=nom[2]-1;
										afficheFenetreJoueur(win,ren);											
									}else if(check_click_in_rect(e.motion.x, e.motion.y, rLettreDown2)){
										nom[2]=nom[2]+1;
										afficheFenetreJoueur(win,ren);											
									}else if(check_click_in_rect(e.motion.x, e.motion.y, rLettreUp3)){
										nom[4]=nom[4]-1;
										afficheFenetreJoueur(win,ren);											
									}else if(check_click_in_rect(e.motion.x, e.motion.y, rLettreDown3)){
										nom[4]=nom[4]+1;
										afficheFenetreJoueur(win,ren);											
									}else if(nbJoueur < 4 && check_click_in_rect(e.motion.x, e.motion.y, rSuivant)){
										char temp[4];temp[0]=nom[0];temp[1]=nom[2];temp[2]=nom[4];temp[3]='\0';
										joueurs[nbJoueur] = joueur_creer(temp,0);
										nbJoueur++;
										printf("nbJoueurs : %i\n", nbJoueur);
										nom[0]='A';nom[2]='A';nom[4]='A';
										afficheFenetreJoueur(win,ren);											
									}else if(nbJoueur >1 && check_click_in_rect(e.motion.x, e.motion.y, rJouer)){
										printf(" nbJoueurs : %i\n", nbJoueur);
										printf("nom joueur %s\n", joueurs[0]->nom);
										fenetreJeu(win,ren,joueurs, nbJoueur);
										running = 0;											
									}
									break;
							}
							break;
					}

				}
			}
		}
	}
	return 0;
}
