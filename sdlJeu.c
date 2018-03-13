#include <stdio.h>
#include "sdlJeu.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "de.h"
#include "combinaison.h"
#include "joueur.h"
#include "feuilleScore.h"


void afficheFenetre(SDL_Window* win, SDL_Renderer* ren){	

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
	sLancer = TTF_RenderText_Solid(Sans, "Lancer", White);

	SDL_Texture* mLancer = SDL_CreateTextureFromSurface(ren, sLancer);
	
	SDL_Rect rLancer;
	rLancer.x = 350; 
	rLancer.y = 600;
	rLancer.w = 300;
	rLancer.h = 100;

	SDL_RenderCopy(ren, mLancer, NULL, &rLancer);

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

	sDe1 = IMG_Load("deUn.png");

	SDL_Texture* mDe1 = SDL_CreateTextureFromSurface(ren, sDe1);
	
	SDL_Rect rDe1;
	rDe1.x = 350; 
	rDe1.y = 300;
	rDe1.w = 50;
	rDe1.h = 50;

	SDL_RenderCopy(ren, mDe1, NULL, &rDe1);
	
	sDe2 = IMG_Load("DeDeux.png");

	SDL_Texture* mDe2 = SDL_CreateTextureFromSurface(ren, sDe2);
	
	SDL_Rect rDe2;
	rDe2.x = 400; 
	rDe2.y = 300;
	rDe2.w = 50;
	rDe2.h = 50;

	SDL_RenderCopy(ren, mDe2, NULL, &rDe2);

	sDe3 = IMG_Load("DeTrois.png");

	SDL_Texture* mDe3 = SDL_CreateTextureFromSurface(ren, sDe3);
	
	SDL_Rect rDe3;
	rDe3.x = 450; 
	rDe3.y = 300;
	rDe3.w = 50;
	rDe3.h = 50;

	SDL_RenderCopy(ren, mDe3, NULL, &rDe3);

	sDe4 = IMG_Load("DeQuatre.png");

	SDL_Texture* mDe4 = SDL_CreateTextureFromSurface(ren, sDe4);
	
	SDL_Rect rDe4;
	rDe4.x = 500; 
	rDe4.y = 300;
	rDe4.w = 50;
	rDe4.h = 50;

	SDL_RenderCopy(ren, mDe4, NULL, &rDe4);

	sDe5 = IMG_Load("DeCinq.png");

	SDL_Texture* mDe5 = SDL_CreateTextureFromSurface(ren, sDe5);
	
	SDL_Rect rDe5;
	rDe5.x = 550; 
	rDe5.y = 300;
	rDe5.w = 50;
	rDe5.h = 50;

	SDL_RenderCopy(ren, mDe5, NULL, &rDe5);

	SDL_RenderPresent( ren );

}

int fermerFenetre(SDL_Window* win, SDL_Renderer* ren){
	SDL_DestroyWindow(win);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

int fenetreJeu(SDL_Window* win, SDL_Renderer* ren){
	afficheFenetre(win, ren);
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
						    SDL_ShowSimpleMessageBox(0, "Mouse", "Left button was pressed!", win);
						    break;
						case SDL_BUTTON_RIGHT:
						    SDL_ShowSimpleMessageBox(0, "Mouse", "Right button was pressed!", win);
						    break;
						default:
						    SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", win);
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
