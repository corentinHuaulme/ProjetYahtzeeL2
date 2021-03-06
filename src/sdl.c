/**
* \file sdl.c
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Contient la fenêtre principale du jeu
* \date Vendredi 23 mars 2018
*/

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "de.h"
#include "sdl.h"
#include "combinaison.h"
#include "joueur.h"
#include "feuilleScore.h"

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
int tourJoueur = 0;
feuille_score_t * feuilles[4];
de_t * tabDe[5];
de_t * deGarde[5];
de_t * deCombinaison[5];
combinaison_t * combi = NULL;

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
	


	
	TTF_Font* Sans = TTF_OpenFont("../ressources/fonts/Montserrat-Regular.ttf", 30);
	SDL_Color White = {255, 255, 255};

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


void initTab(){
	int i=0;
	for(i=0;i<5;i++){
		tabDe[i] = creerDe();
		deGarde[i] = creerDe();
		deCombinaison[i] = creerDe();
	}
}

void showCombi(SDL_Window* win, SDL_Renderer* ren){
	int i=0;
	char * strAjout = malloc(20*sizeof(char));
	for(i=0;i<5;i++){
		if(deGarde[i]->nombreFace == 0){
			deCombinaison[i]->nombreFace = tabDe[i]->nombreFace;
			deCombinaison[i]->nomImage = tabDe[i]->nomImage;
		}else{
			deCombinaison[i]->nombreFace = deGarde[i]->nombreFace;
			deCombinaison[i]->nomImage = deGarde[i]->nomImage;
		}
	}
	combi = creerCombinaison(deCombinaison);

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

	TTF_Font* Sans = TTF_OpenFont("../ressources/fonts/Montserrat-Regular.ttf", 30);
	SDL_Color White = {255, 255, 255};
	SDL_Color gris = {130, 130, 130};
	sprintf(strAjout,"Brelan : %i", brelan(combi));
	sBrelan = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalBrelan>0){
		sBrelan = TTF_RenderText_Solid(Sans, strAjout, gris);
	}
	SDL_Texture* mBrelan = SDL_CreateTextureFromSurface(ren, sBrelan);
	
	rBrelan = malloc(sizeof(SDL_Rect));
	rBrelan->x = 100; 
	rBrelan->y = 250;
	SDL_QueryTexture(mBrelan, NULL, NULL, &(rBrelan->w), &(rBrelan->h));
	SDL_RenderCopy(ren, mBrelan, NULL, rBrelan);
	
	sprintf(strAjout,"Petite Suite : %i", petite_suite(combi));
	
	sPetiteS = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalPetiteSuite>0){
		sPetiteS = TTF_RenderText_Solid(Sans, strAjout, gris);
	}
	SDL_Texture* mPetiteS = SDL_CreateTextureFromSurface(ren, sPetiteS);
	
	rPetiteS = malloc(sizeof(SDL_Rect));
	rPetiteS->x = 100; 
	rPetiteS->y = 300;
	SDL_QueryTexture(mPetiteS, NULL, NULL, &(rPetiteS->w), &(rPetiteS->h));
	SDL_RenderCopy(ren, mPetiteS, NULL, rPetiteS);



	sprintf(strAjout,"Grande Suite : %i", grande_suite(combi));
	sGrandeS = TTF_RenderText_Solid(Sans,strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalGrandeSuite>0){
		sGrandeS = TTF_RenderText_Solid(Sans,strAjout, gris);
	}

	SDL_Texture* mGrandeS = SDL_CreateTextureFromSurface(ren, sGrandeS);
	
	rGrandeS = malloc(sizeof(SDL_Rect));
	rGrandeS->x = 100; 
	rGrandeS->y = 350;
	SDL_QueryTexture(mGrandeS, NULL, NULL, &(rGrandeS->w), &(rGrandeS->h));
	SDL_RenderCopy(ren, mGrandeS, NULL, rGrandeS);


	sprintf(strAjout,"Full : %i", full(combi));
	sFull = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalFull>0){
		sFull = TTF_RenderText_Solid(Sans, strAjout, gris);
	}

	SDL_Texture* mFull = SDL_CreateTextureFromSurface(ren, sFull);
	
	rFull = malloc(sizeof(SDL_Rect));
	rFull->x = 100; 
	rFull->y = 400;
	SDL_QueryTexture(mFull, NULL, NULL, &(rFull->w), &(rFull->h));
	SDL_RenderCopy(ren, mFull, NULL, rFull);
	

	sprintf(strAjout,"Carre : %i", carre(combi));
	sCarre = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalCarre>0){
		sCarre = TTF_RenderText_Solid(Sans, strAjout, gris);
	}

	SDL_Texture* mCarre = SDL_CreateTextureFromSurface(ren, sCarre);
	
	rCarre = malloc(sizeof(SDL_Rect));
	rCarre->x = 100; 
	rCarre->y = 450;
	SDL_QueryTexture(mCarre, NULL, NULL, &(rCarre->w), &(rCarre->h));
	SDL_RenderCopy(ren, mCarre, NULL, rCarre);


	sprintf(strAjout,"Chance : %i", chance(combi));
	sChance = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalChance>0){
		sChance = TTF_RenderText_Solid(Sans, strAjout, gris);
	}

	SDL_Texture* mChance = SDL_CreateTextureFromSurface(ren, sChance);
	
	rChance = malloc(sizeof(SDL_Rect));
	rChance->x = 100; 
	rChance->y = 500;
	SDL_QueryTexture(mChance, NULL, NULL, &(rChance->w), &(rChance->h));
	SDL_RenderCopy(ren, mChance, NULL, rChance);


	sprintf(strAjout,"Somme 1 : %i", cpt1(combi));
	sCpt1 = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalUn>0){
		sCpt1 = TTF_RenderText_Solid(Sans, strAjout, gris);
	}

	SDL_Texture* mCpt1 = SDL_CreateTextureFromSurface(ren, sCpt1);
	
	rCpt1 = malloc(sizeof(SDL_Rect));
	rCpt1->x = 550; 
	rCpt1->y = 250;
	SDL_QueryTexture(mCpt1, NULL, NULL, &(rCpt1->w), &(rCpt1->h));
	SDL_RenderCopy(ren, mCpt1, NULL, rCpt1);


	sprintf(strAjout,"Somme 2 : %i", cpt2(combi)*2);
	sCpt2 = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalDeux>0){
		sCpt2 = TTF_RenderText_Solid(Sans, strAjout, gris);
	}

	SDL_Texture* mCpt2 = SDL_CreateTextureFromSurface(ren, sCpt2);
	
	rCpt2 = malloc(sizeof(SDL_Rect));
	rCpt2->x = 550; 
	rCpt2->y = 300;
	SDL_QueryTexture(mCpt2, NULL, NULL, &(rCpt2->w), &(rCpt2->h));
	SDL_RenderCopy(ren, mCpt2, NULL, rCpt2);


	sprintf(strAjout,"Somme 3 : %i", cpt3(combi)*3);
	sCpt3 = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalTrois>0){
		sCpt3 = TTF_RenderText_Solid(Sans, strAjout, gris);
	}

	SDL_Texture* mCpt3 = SDL_CreateTextureFromSurface(ren, sCpt3);
	
	rCpt3 = malloc(sizeof(SDL_Rect));
	rCpt3->x = 550; 
	rCpt3->y = 350;
	SDL_QueryTexture(mCpt3, NULL, NULL, &(rCpt3->w), &(rCpt3->h));
	SDL_RenderCopy(ren, mCpt3, NULL, rCpt3);


	sprintf(strAjout,"Somme 4 : %i", cpt4(combi)*4);
	sCpt4 = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalQuatre>0){
		sCpt4 = TTF_RenderText_Solid(Sans, strAjout, gris);
	}

	SDL_Texture* mCpt4 = SDL_CreateTextureFromSurface(ren, sCpt4);
	
	rCpt4 = malloc(sizeof(SDL_Rect));
	rCpt4->x = 550; 
	rCpt4->y = 400;
	SDL_QueryTexture(mCpt4, NULL, NULL, &(rCpt4->w), &(rCpt4->h));
	SDL_RenderCopy(ren, mCpt4, NULL, rCpt4);


	sprintf(strAjout,"Somme 5 : %i", cpt5(combi)*5);
	sCpt5 = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalCinq>0){
		sCpt5 = TTF_RenderText_Solid(Sans, strAjout, gris);
	}
	SDL_Texture* mCpt5 = SDL_CreateTextureFromSurface(ren, sCpt5);
	
	rCpt5 = malloc(sizeof(SDL_Rect));
	rCpt5->x = 550; 
	rCpt5->y = 450;
	SDL_QueryTexture(mCpt5, NULL, NULL, &(rCpt5->w), &(rCpt5->h));
	SDL_RenderCopy(ren, mCpt5, NULL, rCpt5);


	sprintf(strAjout,"Somme 6 : %i", cpt6(combi)*6);
	sCpt6 = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalSix>0){
		sCpt6 = TTF_RenderText_Solid(Sans, strAjout, gris);
	}

	SDL_Texture* mCpt6 = SDL_CreateTextureFromSurface(ren, sCpt6);
	
	rCpt6 = malloc(sizeof(SDL_Rect));
	rCpt6->x = 550; 
	rCpt6->y = 500;
	SDL_QueryTexture(mCpt6, NULL, NULL, &(rCpt6->w), &(rCpt6->h));
	SDL_RenderCopy(ren, mCpt6, NULL, rCpt6);


	sprintf(strAjout,"Yahtzee : %i", yahtzee(combi));
	sYahtzee = TTF_RenderText_Solid(Sans, strAjout, White);
	if(feuilles[tourJoueur%nbJoueur]->totalYahtzee>0){
		sYahtzee = TTF_RenderText_Solid(Sans, strAjout, gris);
	}

	SDL_Texture* mYahtzee = SDL_CreateTextureFromSurface(ren, sYahtzee);
	
	rYahtzee = malloc(sizeof(SDL_Rect));
	rYahtzee->x = 375; 
	rYahtzee->y = 550;
	SDL_QueryTexture(mYahtzee, NULL, NULL, &(rYahtzee->w), &(rYahtzee->h));
	SDL_RenderCopy(ren, mYahtzee, NULL, rYahtzee);

	//SDL_RenderPresent( ren );
	if(tourJoueur >= nbJoueur * 10){
		afficheFinPartie(win,ren);
	}
}

void deLancer(){
	int i = 0;
	for(i=0;i<5;i++){
		tabDe[i] = creerDe();
		if(deGarde[i]->nombreFace == 0){
			deGarde[i] = creerDe();
		}
		printf("%i\n",deGarde[i]->nombreFace);
	}
	lancerDe(tabDe,5);
}

void afficheFenetre(SDL_Window* win, SDL_Renderer* ren){	

	int i = 0;

	TTF_Font* Sans = TTF_OpenFont("../ressources/fonts/Montserrat-Regular.ttf", 30);
	SDL_Color White = {255, 255, 255};

	SDL_Surface* sLancer = NULL;
	SDL_Surface* sPoint = NULL;
	SDL_Surface* sTour = NULL;
	SDL_Surface* sDe1 = NULL;
	SDL_Surface* sDe2 = NULL;
	SDL_Surface* sDe3 = NULL;
	SDL_Surface* sDe4 = NULL;
	SDL_Surface* sDe5 = NULL;
	SDL_Surface* sDe1Select = NULL;
	SDL_Surface* sDe2Select = NULL;
	SDL_Surface* sDe3Select = NULL;
	SDL_Surface* sDe4Select = NULL;
	SDL_Surface* sDe5Select = NULL;
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
	SDL_QueryTexture(mLancer, NULL, NULL, &(rLancer->w), &(rLancer->h));

	SDL_RenderCopy(ren, mLancer, NULL, rLancer);

	//SDL_RenderPresent( ren );
	/* fin ajout bouton lancer */

	char * strAjout = malloc(20*sizeof(char));
	sprintf(strAjout,"Points : %i", totalPoint(feuilles[tourJoueur%nbJoueur]));
	sPoint = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mPoint = SDL_CreateTextureFromSurface(ren, sPoint);
	
	SDL_Rect rPoint;
	rPoint.x = 200; 
	rPoint.y = 50;
	SDL_QueryTexture(mPoint, NULL, NULL, &(rPoint.w), &(rPoint.h));

	SDL_RenderCopy(ren, mPoint, NULL, &rPoint);

	/* Ajout texte "tour de XX" */
	strAjout = malloc(20*sizeof(char));
	sprintf(strAjout,"Au tour de %s", joueurs[tourJoueur%nbJoueur]->nom);
	sTour = TTF_RenderText_Solid(Sans, strAjout, White);

	SDL_Texture* mTour = SDL_CreateTextureFromSurface(ren, sTour);
	
	SDL_Rect rTour;
	rTour.x = 600; 
	rTour.y = 50;
	SDL_QueryTexture(mTour, NULL, NULL, &(rTour.w), &(rTour.h));

	SDL_RenderCopy(ren, mTour, NULL, &rTour);

	/* fin ajout texte "tour de XX" */
	/* Debut déclaration images dé */

	if(deGarde[0]->nombreFace != 0){
		sDe1 = IMG_Load(deGarde[0]->nomImage);
		SDL_Rect rDe1Select;
		rDe1Select.x = 340;
		rDe1Select.y = 190;
		rDe1Select.w = 65;
		rDe1Select.h = 65;
		SDL_SetRenderDrawColor( ren, 0, 255, 255, 255 );
		SDL_RenderFillRect( ren, &rDe1Select );		

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
		SDL_Rect rDe2Select;
		rDe2Select.x = 410;
		rDe2Select.y = 190;
		rDe2Select.w = 65;
		rDe2Select.h = 65;
		SDL_SetRenderDrawColor( ren, 0, 255, 255, 255 );
		SDL_RenderFillRect( ren, &rDe2Select );	
	}else{
		sDe2 = IMG_Load(tabDe[1]->nomImage);
	}

	SDL_Texture* mDe2 = SDL_CreateTextureFromSurface(ren, sDe2);
	
	rDe2 = malloc(sizeof(SDL_Rect));
	rDe2->x = 420; 
	rDe2->y = 200;
	rDe2->w = 50;
	rDe2->h = 50;

	SDL_RenderCopy(ren, mDe2, NULL, rDe2);

	if(deGarde[2]->nombreFace != 0){
		sDe3 = IMG_Load(deGarde[2]->nomImage);
		SDL_Rect rDe3Select;
		rDe3Select.x = 480;
		rDe3Select.y = 190;
		rDe3Select.w = 65;
		rDe3Select.h = 65;
		SDL_SetRenderDrawColor( ren, 0, 255, 255, 255 );
		SDL_RenderFillRect( ren, &rDe3Select );	
	}else{
		sDe3 = IMG_Load(tabDe[2]->nomImage);
	}

	SDL_Texture* mDe3 = SDL_CreateTextureFromSurface(ren, sDe3);
	
	rDe3 = malloc(sizeof(SDL_Rect));
	rDe3->x = 490; 
	rDe3->y = 200;
	rDe3->w = 50;
	rDe3->h = 50;

	SDL_RenderCopy(ren, mDe3, NULL, rDe3);

	if(deGarde[3]->nombreFace != 0){
		sDe4 = IMG_Load(deGarde[3]->nomImage);
		SDL_Rect rDe4Select;
		rDe4Select.x = 550;
		rDe4Select.y = 190;
		rDe4Select.w = 65;
		rDe4Select.h = 65;
		SDL_SetRenderDrawColor( ren, 0, 255, 255, 255 );
		SDL_RenderFillRect( ren, &rDe4Select );	
	}else{
		sDe4 = IMG_Load(tabDe[3]->nomImage);
	}

	SDL_Texture* mDe4 = SDL_CreateTextureFromSurface(ren, sDe4);
	
	rDe4 = malloc(sizeof(SDL_Rect));
	rDe4->x = 560; 
	rDe4->y = 200;
	rDe4->w = 50;
	rDe4->h = 50;

	SDL_RenderCopy(ren, mDe4, NULL, rDe4);

	if(deGarde[4]->nombreFace != 0){
		sDe5 = IMG_Load(deGarde[4]->nomImage);
		SDL_Rect rDe5Select;
		rDe5Select.x = 620;
		rDe5Select.y = 190;
		rDe5Select.w = 65;
		rDe5Select.h = 65;
		SDL_SetRenderDrawColor( ren, 0, 255, 255, 255 );
		SDL_RenderFillRect( ren, &rDe5Select );	
	}else{
		sDe5 = IMG_Load(tabDe[4]->nomImage);
	}

	SDL_Texture* mDe5 = SDL_CreateTextureFromSurface(ren, sDe5);
	
	rDe5 = malloc(sizeof(SDL_Rect));
	rDe5->x = 630; 
	rDe5->y = 200;
	rDe5->w = 50;
	rDe5->h = 50;

	SDL_RenderCopy(ren, mDe5, NULL, rDe5);

	showCombi(win, ren);

	SDL_RenderPresent( ren );

}

int afficheFinPartie(SDL_Window * win, SDL_Renderer * ren){

	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);
        /* Select the color for drawing. It is set to red here. */
        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);

        /* Clear the entire screen to our selected color. */
        SDL_RenderClear(ren);

	SDL_Surface * sFinPartie = NULL;
	SDL_Surface * sJoueur1 = NULL;
	SDL_Surface * sJoueur2 = NULL;
	SDL_Surface * sJoueur3 = NULL;
	SDL_Surface * sJoueur4 = NULL;
	SDL_Surface * sRetourMenu = NULL;
	
	TTF_Font* mont = TTF_OpenFont("../ressources/fonts/Montserrat-Regular.ttf", 50);
	SDL_Color blanc = {255, 255, 255};

	sFinPartie = TTF_RenderText_Solid(mont, "Fin de la partie !", blanc);
	SDL_Texture* mFinPartie = SDL_CreateTextureFromSurface(ren, sFinPartie);

	SDL_Rect * rFinPartie;
	rFinPartie = malloc(sizeof(SDL_Rect));
	rFinPartie->x = 450; 
	rFinPartie->y = 100;
	SDL_QueryTexture(mFinPartie, NULL, NULL, &(rFinPartie->w), &(rFinPartie->h));

	SDL_RenderCopy(ren, mFinPartie, NULL, rFinPartie);

	char * strAjout = malloc(20*sizeof(char));
	sprintf(strAjout,"%s : %i",joueurs[0]->nom, totalPoint(feuilles[0]));
	sJoueur1 = TTF_RenderText_Solid(mont, strAjout, blanc);
	SDL_Texture* mJoueur1 = SDL_CreateTextureFromSurface(ren, sJoueur1);

	SDL_Rect * rJoueur1;
	rJoueur1 = malloc(sizeof(SDL_Rect));
	rJoueur1->x = 150; 
	rJoueur1->y = 250;
	SDL_QueryTexture(mJoueur1, NULL, NULL, &(rJoueur1->w), &(rJoueur1->h));

	SDL_RenderCopy(ren, mJoueur1, NULL, rJoueur1);

	
	sprintf(strAjout,"%s : %i",joueurs[1]->nom, totalPoint(feuilles[1]));
	sJoueur2 = TTF_RenderText_Solid(mont, strAjout, blanc);
	SDL_Texture* mJoueur2 = SDL_CreateTextureFromSurface(ren, sJoueur2);

	SDL_Rect * rJoueur2;
	rJoueur2 = malloc(sizeof(SDL_Rect));
	rJoueur2->x = 150; 
	rJoueur2->y = 350;
	SDL_QueryTexture(mJoueur2, NULL, NULL, &(rJoueur2->w), &(rJoueur2->h));

	SDL_RenderCopy(ren, mJoueur2, NULL, rJoueur2);
	
	if(nbJoueur > 2){
		sprintf(strAjout,"%s : %i",joueurs[2]->nom, totalPoint(feuilles[2]));
		sJoueur3 = TTF_RenderText_Solid(mont, strAjout, blanc);
		SDL_Texture* mJoueur3 = SDL_CreateTextureFromSurface(ren, sJoueur3);

		SDL_Rect * rJoueur3;
		rJoueur3 = malloc(sizeof(SDL_Rect));
		rJoueur3->x = 150; 
		rJoueur3->y = 450;
		SDL_QueryTexture(mJoueur3, NULL, NULL, &(rJoueur3->w), &(rJoueur3->h));

		SDL_RenderCopy(ren, mJoueur3, NULL, rJoueur3);
	}
	if(nbJoueur > 3){
		sprintf(strAjout,"%s : %i",joueurs[3]->nom, totalPoint(feuilles[3]));
		sJoueur4 = TTF_RenderText_Solid(mont, strAjout, blanc);
		SDL_Texture* mJoueur4 = SDL_CreateTextureFromSurface(ren, sJoueur4);

		SDL_Rect * rJoueur4;
		rJoueur4 = malloc(sizeof(SDL_Rect));
		rJoueur4->x = 150; 
		rJoueur4->y = 550;
		SDL_QueryTexture(mJoueur4, NULL, NULL, &(rJoueur4->w), &(rJoueur4->h));

		SDL_RenderCopy(ren, mJoueur4, NULL, rJoueur4);
	}
	sRetourMenu = TTF_RenderText_Solid(mont, "Menu principal", blanc);
	SDL_Texture* mRetourMenu = SDL_CreateTextureFromSurface(ren, sRetourMenu);

	SDL_Rect * rRetourMenu;
	rRetourMenu = malloc(sizeof(SDL_Rect));
	rRetourMenu->x = 450; 
	rRetourMenu->y = 700;
	SDL_QueryTexture(mRetourMenu, NULL, NULL, &(rRetourMenu->w), &(rRetourMenu->h));

	SDL_RenderCopy(ren, mRetourMenu, NULL, rRetourMenu);
	SDL_RenderPresent(ren);

}

int fermerFenetre(SDL_Window* win, SDL_Renderer* ren){
	//SDL_DestroyWindow(win);
	IMG_Quit();
}

int fenetreJeu(SDL_Window* win, SDL_Renderer* ren, joueur_t ** joueurs, int nbJ){
	int i=0;
	nbJoueur = nbJ;
	for(i=0;i<nbJoueur;i++){
		joueurs[i] = joueurs[i];
		feuilles[i] = creerFeuilleScore();
	}	
	initTab();
	deLancer();
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
								fprintf(stdout,"Click x=%i , y=%i",e.motion.x, e.motion.y);
								if(check_click_in_rect(e.motion.x, e.motion.y, rLancer)){
									if(nbLancer == 0){
										tourJoueur++;
										initTab();
										nbLancer = 3;
									}else{
										nbLancer--;
									}
									deLancer();
									afficheFenetre(win,ren);
									showCombi(win,ren);
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rDe1)){
									fprintf(stdout,"Click De1");
									if(deGarde[0]->nombreFace == 0){
										deGarde[0]->nombreFace = tabDe[0]->nombreFace;
										deGarde[0]->nomImage = tabDe[0]->nomImage;
									}else{
										deGarde[0]->nombreFace = 0;
										deGarde[0]->nomImage = "deUn.png";
									}
									afficheFenetre(win,ren);
									showCombi(win,ren);
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rDe2)){
									fprintf(stdout,"Click De2");
									if(deGarde[1]->nombreFace == 0){
										deGarde[1]->nombreFace = tabDe[1]->nombreFace;
										deGarde[1]->nomImage = tabDe[1]->nomImage;
									}else{
										deGarde[1]->nombreFace = 0;
										deGarde[1]->nomImage = "deUn.png";
									}
									afficheFenetre(win,ren);
									showCombi(win,ren);
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rDe3)){
									fprintf(stdout,"Click De3");
									if(deGarde[2]->nombreFace == 0){
										deGarde[2]->nombreFace = tabDe[2]->nombreFace;
										deGarde[2]->nomImage = tabDe[2]->nomImage;
									}else{
										deGarde[2]->nombreFace = 0;
										deGarde[2]->nomImage = "deUn.png";
									}
									afficheFenetre(win,ren);
									showCombi(win,ren);
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rDe4)){
									fprintf(stdout,"Click De4");
									if(deGarde[3]->nombreFace == 0){
										deGarde[3]->nombreFace = tabDe[3]->nombreFace;
										deGarde[3]->nomImage = tabDe[3]->nomImage;
									}else{
										deGarde[3]->nombreFace = 0;
										deGarde[3]->nomImage = "deUn.png";
									}
									afficheFenetre(win,ren);
									showCombi(win,ren);
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rDe5)){
									fprintf(stdout,"Click De5");
									if(deGarde[4]->nombreFace == 0){
										deGarde[4]->nombreFace = tabDe[4]->nombreFace;
										deGarde[4]->nomImage = tabDe[4]->nomImage;
									}else{
										deGarde[4]->nombreFace = 0;
										deGarde[4]->nomImage = "deUn.png";
									}
									afficheFenetre(win,ren);
									showCombi(win,ren);
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rBrelan)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_brelan;
									if(feuilles[tourJoueur%nbJoueur]->totalBrelan == 0){
										afficherMessageBox("Brelan",ptr,win,ren);
									}else{
										afficherErreurBox("Brelan");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rPetiteS)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_petite_suite;
									if(feuilles[tourJoueur%nbJoueur]->totalPetiteSuite == 0){
										afficherMessageBox("Petite Suite",ptr,win,ren);
									}else{
										afficherErreurBox("Petite Suite");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rGrandeS)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_grande_suite;
									if(feuilles[tourJoueur%nbJoueur]->totalGrandeSuite == 0){
										afficherMessageBox("Grande Suite",ptr,win,ren);
									}else{
										afficherErreurBox("Grande Suite");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rFull)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_full;
									if(feuilles[tourJoueur%nbJoueur]->totalFull == 0){
										afficherMessageBox("Full",ptr,win,ren);
									}else{
										afficherErreurBox("Full");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rCarre)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_carre;
									if(feuilles[tourJoueur%nbJoueur]->totalCarre == 0){
										afficherMessageBox("Carre",ptr,win,ren);
									}else{
										afficherErreurBox("Carre");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rYahtzee)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_yahtzee;
									if(feuilles[tourJoueur%nbJoueur]->totalYahtzee == 0){
										afficherMessageBox("Yahtzee",ptr,win,ren);
									}else{
										afficherErreurBox("Yahtzee");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rChance)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_chance;
									if(feuilles[tourJoueur%nbJoueur]->totalChance == 0){
										afficherMessageBox("Chance",ptr,win,ren);
									}else{
										afficherErreurBox("Chance");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rCpt1)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_un;
									if(feuilles[tourJoueur%nbJoueur]->totalUn == 0){
										afficherMessageBox("Somme des 1",ptr,win,ren);
									}else{
										afficherErreurBox("Somme des 1");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rCpt2)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_deux;
									if(feuilles[tourJoueur%nbJoueur]->totalDeux == 0){
										afficherMessageBox("Somme des 2",ptr,win,ren);
									}else{
										afficherErreurBox("Somme des 2");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rCpt3)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_trois;
									if(feuilles[tourJoueur%nbJoueur]->totalTrois == 0){
										afficherMessageBox("Somme des 3",ptr,win,ren);
									}else{
										afficherErreurBox("Somme des 3");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rCpt4)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_quatre;
									if(feuilles[tourJoueur%nbJoueur]->totalQuatre == 0){
										afficherMessageBox("Somme des 4",ptr,win,ren);
									}else{
										afficherErreurBox("Somme des 4");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rCpt5)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_cinq;
									if(feuilles[tourJoueur%nbJoueur]->totalCinq == 0){
										afficherMessageBox("Somme des 5",ptr,win,ren);
									}else{
										afficherErreurBox("Somme des 5");
									}
								}
								if(check_click_in_rect(e.motion.x, e.motion.y, rCpt6)){
									void (*ptr)(feuille_score_t *, combinaison_t) = ajout_six;
									if(feuilles[tourJoueur%nbJoueur]->totalSix == 0){
										afficherMessageBox("Somme des 6",ptr,win,ren);
									}else{
										afficherErreurBox("Somme des 6");
									}
								}
								break;
						    }
						    break;
					} 
				}
				//SDL_Event e; 
				while(SDL_PollEvent(&e)) {
					switch(e.type) { 
						case SDL_QUIT: running = 0; break; 
						case SDL_MOUSEBUTTONDOWN:
						    switch (e.button.button)
						    {
							case SDL_BUTTON_LEFT:
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
int afficherMessageBox(char * figure, void (*p)(feuille_score_t *, combinaison_t), SDL_Window *win, SDL_Renderer *ren){
	const SDL_MessageBoxButtonData buttons[] = {
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "Oui" },
		{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "Non" },
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
		if(strcmp(buttons[buttonid].text,"Oui") == 0){
			printf("TEST");
			p(feuilles[tourJoueur%nbJoueur],*(creerCombinaison(deCombinaison)));
			afficheScore(feuilles[tourJoueur%nbJoueur]);
			tourJoueur++;
			initTab();
			nbLancer = 3;
			deLancer();
			afficheFenetre(win,ren);
			showCombi(win,ren);
			return 0;
		}
		SDL_Log("selection was %s", buttons[buttonid].text);
		return 0;
	}
	return 0;
}

int afficherErreurBox(char * figure){
	const SDL_MessageBoxButtonData buttons[] = {
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "OK" },
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
	strcpy(mess,"Voulez avez déjà le ");
	strcat(mess,figure);
	strcat(mess, " !");
	const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION, /* .flags */
		NULL, /* .window */
		"Choix impossible !", /* .title */
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
		return 0;
	}
	return 0;
}


int afficheFenetreJoueur(SDL_Window* win, SDL_Renderer* ren)
{
	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);
	TTF_Font* Sans = TTF_OpenFont("../ressources/fonts/Montserrat-Regular.ttf", 50);
	SDL_Color White = {255, 255, 255};
	SDL_SetRenderDrawColor( ren, 255, 0, 0, 255 );
	SDL_RenderClear(ren);	

	SDL_Surface* sSuivant = NULL;
	SDL_Surface* sJouer = NULL;
	SDL_Surface* sLettreUp1 = NULL;
	SDL_Surface* sLettreDown1 = NULL;
	SDL_Surface* sLettreUp2 = NULL;
	SDL_Surface* sLettreDown2 = NULL;
	SDL_Surface* sLettreUp3 = NULL;
	SDL_Surface* sLettreDown3 = NULL;
	if(nbJoueur<4){
		sSuivant = TTF_RenderText_Solid(Sans, "Ajout joueur", White);
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


	sLettreUp2 = IMG_Load("../ressources/flecheHaut.png");

	SDL_Texture* mLettreUp2 = SDL_CreateTextureFromSurface(ren, sLettreUp2);
	
	rLettreUp2 = malloc(sizeof(SDL_Rect));
	rLettreUp2->x = 443; 
	rLettreUp2->y = 200;
	rLettreUp2->w = 50;
	rLettreUp2->h = 50;

	SDL_RenderCopy(ren, mLettreUp2, NULL, rLettreUp2);


	sLettreUp3 = IMG_Load("../ressources/flecheHaut.png");

	SDL_Texture* mLettreUp3 = SDL_CreateTextureFromSurface(ren, sLettreUp3);
	
	rLettreUp3 = malloc(sizeof(SDL_Rect));
	rLettreUp3->x = 493; 
	rLettreUp3->y = 200;
	rLettreUp3->w = 50;
	rLettreUp3->h = 50;

	SDL_RenderCopy(ren, mLettreUp3, NULL, rLettreUp3);


	sLettreDown1 = IMG_Load("../ressources/flecheBas.png");

	SDL_Texture* mLettreDown1 = SDL_CreateTextureFromSurface(ren, sLettreDown1);	
	rLettreDown1 = malloc(sizeof(SDL_Rect));
	rLettreDown1->x = 393; 
	rLettreDown1->y = 315;
	rLettreDown1->w = 50;
	rLettreDown1->h = 50;

	SDL_RenderCopy(ren, mLettreDown1, NULL, rLettreDown1);


	sLettreDown2 = IMG_Load("../ressources/flecheBas.png");

	SDL_Texture* mLettreDown2 = SDL_CreateTextureFromSurface(ren, sLettreDown2);
	
	rLettreDown2 = malloc(sizeof(SDL_Rect));
	rLettreDown2->x = 443; 
	rLettreDown2->y = 315;
	rLettreDown2->w = 50;
	rLettreDown2->h = 50;

	SDL_RenderCopy(ren, mLettreDown2, NULL, rLettreDown2);


	sLettreDown3 = IMG_Load("../ressources/flecheBas.png");

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
										printf("nbJoueur : %i\n", nbJoueur);
										nom[0]='A';nom[2]='A';nom[4]='A';
										afficheFenetreJoueur(win,ren);											
									}else if(nbJoueur >1 && check_click_in_rect(e.motion.x, e.motion.y, rJouer)){
										printf(" nbJoueur : %i\n", nbJoueur);
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
	
	TTF_Font* Sans = TTF_OpenFont("../ressources/fonts/Montserrat-Regular.ttf", 60);
	SDL_Color White = {255, 255, 255};

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
	TTF_Font* Sans = TTF_OpenFont("../ressources/fonts/Montserrat-Regular.ttf", 75); 

	if(Sans == NULL){
		printf("\nERROR\n");
	}

	SDL_Color White = {255, 255, 255};
	

	sImage = IMG_Load("../ressources/tapis.jpg");

	SDL_Texture* mImage = SDL_CreateTextureFromSurface(renderer, sImage);
	
	rImage = malloc(sizeof(SDL_Rect));
	rImage->x = 0; 
	rImage->y = 0;
	rImage->w = 1280;
	rImage->h = 720;

	SDL_RenderCopy(renderer, mImage, NULL, rImage);
	
	sImage_de = IMG_Load("../ressources/de_deco.png");

	SDL_Texture* mImage_de = SDL_CreateTextureFromSurface(renderer, sImage_de);
	
	rImage_de = malloc(sizeof(SDL_Rect));
	rImage_de->x = 100; 
	rImage_de->y = 360;
	rImage_de->w = 130;
	rImage_de->h = 90;

	SDL_RenderCopy(renderer, mImage_de, NULL, rImage_de);
	
	sImage_de2 = IMG_Load("../ressources/de_deco.png");

	SDL_Texture* mImage_de2 = SDL_CreateTextureFromSurface(renderer, sImage_de2);
	
	rImage_de2 = malloc(sizeof(SDL_Rect));
	rImage_de2->x = 1010; 
	rImage_de2->y = 360;
	rImage_de2->w = 130;
	rImage_de2->h = 90;

	SDL_RenderCopy(renderer, mImage_de2, NULL, rImage_de2);
	//SDL_Color White = {255, 255, 255};
	
	sImage2 = IMG_Load("../ressources/small.png");

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
	SDL_RenderCopy(renderer, mTitre, NULL, &rTitre);
*/
    
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
	rQuitter.y = 500;
	SDL_QueryTexture(mQuitter, NULL, NULL, &(rQuitter.w), &(rQuitter.h));
	SDL_RenderCopy(renderer, mQuitter, NULL, &rQuitter);


	sCredit = TTF_RenderText_Solid(Sans, "Credits", White);
	SDL_Texture* mCredit = SDL_CreateTextureFromSurface(renderer, sCredit);
	
	SDL_Rect rCredit;
	rCredit.x = 350; 
	rCredit.y = 400;
	SDL_QueryTexture(mCredit, NULL, NULL, &(rCredit.w), &(rCredit.h));
	SDL_RenderCopy(renderer, mCredit, NULL, &rCredit);

	SDL_RenderPresent( renderer );

	
	if( pWindow )
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
