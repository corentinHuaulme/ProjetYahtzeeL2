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
combinaison_t * combi = NULL;

void initTab(){
	int i=0;
	for(i=0;i<5;i++){
		tabDe[i] = creerDe();
		deGarde[i] = creerDe();
	}
}

void showCombi(SDL_Window* win, SDL_Renderer* ren){
	int i=0;
	char * strAjout = malloc(20*sizeof(char));
	for(i=0;i<5;i++){
		if(deGarde[i]->nombreFace == 0){
			deGarde[i]->nombreFace = tabDe[i]->nombreFace;
			deGarde[i]->nomImage = tabDe[i]->nomImage;
		}
		printf("DE%i : %i",i,deGarde[i]->nombreFace);
	}
	combi = creerCombinaison(deGarde);

	SDL_Surface* sBrelan = NULL;
	SDL_Surface* sPetiteS = NULL;
	SDL_Surface* sGrandeS = NULL;
	SDL_Surface* sFull = NULL;
	SDL_Surface* sCarre = NULL;
	SDL_Surface* sYahtzee = NULL;
	SDL_Surface* sChance = NULL;
	SDL_Surface* sCpt1 = NULL;
	SDL_Surface* sCpt2 = NULL;
	SDL_Surface* sCpt3 = NULL;
	SDL_Surface* sCpt4 = NULL;
	SDL_Surface* sCpt5 = NULL;
	SDL_Surface* sCpt6 = NULL;

	TTF_Font* Sans = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 50);
	SDL_Color White = {255, 255, 255};
	sprintf(strAjout,"Brelan : %i", brelan(combi));

	sBrelan = TTF_RenderText_Solid(Sans, strAjout, White);
	SDL_Texture* mBrelan = SDL_CreateTextureFromSurface(ren, sBrelan);
	
	rBrelan = malloc(sizeof(SDL_Rect));
	rBrelan->x = 100; 
	rBrelan->y = 250;
	SDL_QueryTexture(mBrelan, NULL, NULL, &(rBrelan->w), &(rBrelan->h));
	SDL_RenderCopy(ren, mBrelan, NULL, rBrelan);
	
	sprintf(strAjout,"Petite Suite : %i", petite_suite(combi));
	sPetiteS = TTF_RenderText_Solid(Sans, strAjout, White);
	SDL_Texture* mPetiteS = SDL_CreateTextureFromSurface(ren, sPetiteS);
	
	rPetiteS = malloc(sizeof(SDL_Rect));
	rPetiteS->x = 100; 
	rPetiteS->y = 300;
	SDL_QueryTexture(mPetiteS, NULL, NULL, &(rPetiteS->w), &(rPetiteS->h));
	SDL_RenderCopy(ren, mPetiteS, NULL, rPetiteS);



	sprintf(strAjout,"Grande Suite : %i", grande_suite(combi));
	sGrandeS = TTF_RenderText_Solid(Sans,strAjout, White);

	SDL_Texture* mGrandeS = SDL_CreateTextureFromSurface(ren, sGrandeS);
	
	rGrandeS = malloc(sizeof(SDL_Rect));
	rGrandeS->x = 100; 
	rGrandeS->y = 350;
	SDL_QueryTexture(mGrandeS, NULL, NULL, &(rGrandeS->w), &(rGrandeS->h));
	SDL_RenderCopy(ren, mGrandeS, NULL, rGrandeS);


	sprintf(strAjout,"Full : %i", full(combi));
	sFull = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mFull = SDL_CreateTextureFromSurface(ren, sFull);
	
	rFull = malloc(sizeof(SDL_Rect));
	rFull->x = 100; 
	rFull->y = 400;
	SDL_QueryTexture(mFull, NULL, NULL, &(rFull->w), &(rFull->h));
	SDL_RenderCopy(ren, mFull, NULL, rFull);
	

	sprintf(strAjout,"Carre : %i", carre(combi));
	sCarre = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mCarre = SDL_CreateTextureFromSurface(ren, sCarre);
	
	rCarre = malloc(sizeof(SDL_Rect));
	rCarre->x = 100; 
	rCarre->y = 450;
	SDL_QueryTexture(mCarre, NULL, NULL, &(rCarre->w), &(rCarre->h));
	SDL_RenderCopy(ren, mCarre, NULL, rCarre);


	sprintf(strAjout,"Chance : %i", chance(combi));
	sChance = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mChance = SDL_CreateTextureFromSurface(ren, sChance);
	
	rChance = malloc(sizeof(SDL_Rect));
	rChance->x = 100; 
	rChance->y = 500;
	SDL_QueryTexture(mChance, NULL, NULL, &(rChance->w), &(rChance->h));
	SDL_RenderCopy(ren, mChance, NULL, rChance);


	sprintf(strAjout,"Somme 1 : %i", cpt1(combi));
	sCpt1 = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mCpt1 = SDL_CreateTextureFromSurface(ren, sCpt1);
	
	rCpt1 = malloc(sizeof(SDL_Rect));
	rCpt1->x = 550; 
	rCpt1->y = 250;
	SDL_QueryTexture(mCpt1, NULL, NULL, &(rCpt1->w), &(rCpt1->h));
	SDL_RenderCopy(ren, mCpt1, NULL, rCpt1);


	sprintf(strAjout,"Somme 2 : %i", cpt2(combi)*2);
	sCpt2 = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mCpt2 = SDL_CreateTextureFromSurface(ren, sCpt2);
	
	rCpt2 = malloc(sizeof(SDL_Rect));
	rCpt2->x = 550; 
	rCpt2->y = 300;
	SDL_QueryTexture(mCpt2, NULL, NULL, &(rCpt2->w), &(rCpt2->h));
	SDL_RenderCopy(ren, mCpt2, NULL, rCpt2);


	sprintf(strAjout,"Somme 3 : %i", cpt3(combi)*3);
	sCpt3 = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mCpt3 = SDL_CreateTextureFromSurface(ren, sCpt3);
	
	rCpt3 = malloc(sizeof(SDL_Rect));
	rCpt3->x = 550; 
	rCpt3->y = 350;
	SDL_QueryTexture(mCpt3, NULL, NULL, &(rCpt3->w), &(rCpt3->h));
	SDL_RenderCopy(ren, mCpt3, NULL, rCpt3);


	sprintf(strAjout,"Somme 4 : %i", cpt4(combi)*4);
	sCpt4 = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mCpt4 = SDL_CreateTextureFromSurface(ren, sCpt4);
	
	rCpt4 = malloc(sizeof(SDL_Rect));
	rCpt4->x = 550; 
	rCpt4->y = 400;
	SDL_QueryTexture(mCpt4, NULL, NULL, &(rCpt4->w), &(rCpt4->h));
	SDL_RenderCopy(ren, mCpt4, NULL, rCpt4);


	sprintf(strAjout,"Somme 5 : %i", cpt5(combi)*5);
	sCpt5 = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mCpt5 = SDL_CreateTextureFromSurface(ren, sCpt5);
	
	rCpt5 = malloc(sizeof(SDL_Rect));
	rCpt5->x = 550; 
	rCpt5->y = 450;
	SDL_QueryTexture(mCpt5, NULL, NULL, &(rCpt5->w), &(rCpt5->h));
	SDL_RenderCopy(ren, mCpt5, NULL, rCpt5);


	sprintf(strAjout,"Somme 6 : %i", cpt6(combi)*6);
	sCpt6 = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mCpt6 = SDL_CreateTextureFromSurface(ren, sCpt6);
	
	rCpt6 = malloc(sizeof(SDL_Rect));
	rCpt6->x = 550; 
	rCpt6->y = 500;
	SDL_QueryTexture(mCpt6, NULL, NULL, &(rCpt6->w), &(rCpt6->h));
	SDL_RenderCopy(ren, mCpt6, NULL, rCpt6);


	sprintf(strAjout,"Yahtzee : %i", yahtzee(combi));
	sYahtzee = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mYahtzee = SDL_CreateTextureFromSurface(ren, sYahtzee);
	
	rYahtzee = malloc(sizeof(SDL_Rect));
	rYahtzee->x = 375; 
	rYahtzee->y = 550;
	SDL_QueryTexture(mYahtzee, NULL, NULL, &(rYahtzee->w), &(rYahtzee->h));
	SDL_RenderCopy(ren, mYahtzee, NULL, rYahtzee);

	//SDL_RenderPresent( ren );
}


void afficheFenetre(SDL_Window* win, SDL_Renderer* ren){	

	int i = 0;
	for(i=0;i<5;i++){
		tabDe[i] = creerDe();
		if(deGarde[i]->nombreFace == 0){
			deGarde[i] = creerDe();
		}
		printf("%i\n",deGarde[i]->nombreFace);
	}
	lancerDe(tabDe,5);

	TTF_Font* Sans = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 50);
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

	showCombi(win, ren);

	SDL_RenderPresent( ren );

}

int fermerFenetre(SDL_Window* win, SDL_Renderer* ren){
	//SDL_DestroyWindow(win);
	IMG_Quit();
}

int fenetreJeu(SDL_Window* win, SDL_Renderer* ren, joueur_t ** joueurs){
	initTab();	
	afficheFenetre(win, ren);
	showCombi(win,ren);
	if( win )
	{
        	int running = 1; 
		while(running) {
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
								showCombi(win,ren);
							}
							if(check_click_in_rect(e.motion.x, e.motion.y, rDe1)){
								if(deGarde[0]->nombreFace == 0){
									deGarde[0]->nombreFace = tabDe[0]->nombreFace;
									deGarde[0]->nomImage = tabDe[0]->nomImage;
								}
							}
							if(check_click_in_rect(e.motion.x, e.motion.y, rDe2)){
								if(deGarde[1]->nombreFace == 0){
									deGarde[1]->nombreFace = tabDe[1]->nombreFace;
									deGarde[1]->nomImage = tabDe[1]->nomImage;
								}
							}
							if(check_click_in_rect(e.motion.x, e.motion.y, rDe3)){
								if(deGarde[2]->nombreFace == 0){
									deGarde[2]->nombreFace = tabDe[2]->nombreFace;
									deGarde[2]->nomImage = tabDe[2]->nomImage;
								}
							}
							if(check_click_in_rect(e.motion.x, e.motion.y, rDe4)){
								if(deGarde[3]->nombreFace == 0){
									deGarde[3]->nombreFace = tabDe[3]->nombreFace;
									deGarde[3]->nomImage = tabDe[3]->nomImage;
								}
							}
							if(check_click_in_rect(e.motion.x, e.motion.y, rDe5)){
								if(deGarde[4]->nombreFace == 0){
									deGarde[4]->nombreFace = tabDe[4]->nombreFace;
									deGarde[4]->nomImage = tabDe[4]->nomImage;
								}
							}
							if(check_click_in_rect(e.motion.x, e.motion.y, rBrelan)){
								afficherMessageBox("Brelan");
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
int afficherMessageBox(char * figure){
	const SDL_MessageBoxButtonData buttons[] = {
		{ /* .flags, .buttonid, .text */        0, 0, "no" },
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "oui" },
		{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "non" },
	};
	const SDL_MessageBoxColorScheme colorScheme = {
	{ /* .colors (.r, .g, .b) */
	    /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
	    { 255,   0,   0 },
	    /* [SDL_MESSAGEBOX_COLOR_TEXT] */
	    {   0, 255,   0 },
	    /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
	    { 255, 255,   0 },
	    /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
	    {   0,   0, 255 },
	    /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
	    { 255,   0, 255 }
	}
	};
	char mess[80];
	strcpy(mess,"Voulez vous gardez le ");
	strcat(mess,figure);
	strcat(mess, " ?");
	const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION, /* .flags */
		NULL, /* .window */
		"Quel est votre choix ?", /* .title */
		mess, /* .message */
		SDL_arraysize(buttons), /* .numbuttons */
		buttons, /* .buttons */
		&colorScheme /* .colorScheme */
	};
	int buttonid;
	if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
		SDL_Log("error displaying message box");
		return 1;
	}
	if (buttonid == -1) {
		SDL_Log("no selection");
	} else {
		SDL_Log("selection was %s", buttons[buttonid].text);
		return 0;
	}
	return 0;
}

