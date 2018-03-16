#include <stdio.h>
#include "sdlJeu.h"
#include "sdlDeclaJoueur.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"


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


int main(int argc, char** argv)
{
    	//Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL;
	//Le pointeur vers la surface incluse dans la fenetre
	SDL_Surface* sTitre = NULL;
	SDL_Surface* sJouer = NULL;
	SDL_Surface* sRegles = NULL;
	SDL_Surface* sQuit = NULL;

    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	/* Création de la fenêtre */
	pWindow = SDL_CreateWindow("YAHTZEEEEEEEEEEEE",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 1000,800,SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = NULL;
	renderer =  SDL_CreateRenderer( pWindow, -1, SDL_RENDERER_ACCELERATED);
	
    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

    // Clear winow
    SDL_RenderClear( renderer );

	TTF_Font* Sans = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 24); //this opens a font style and sets a size

	if(Sans == NULL){
		printf("ERROR");
	}

	SDL_Color White = {255, 255, 255};

	sTitre = TTF_RenderText_Solid(Sans, "Yahtzee", White);

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, sTitre);
	
	SDL_Rect Message_rect;
	Message_rect.x = 0; 
	Message_rect.y = 0;
	Message_rect.w = 1000;
	Message_rect.h = 100;

	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

	//SDL_RenderPresent( renderer );

    
	sJouer = TTF_RenderText_Solid(Sans, "Jouer", White);

	SDL_Texture* mJouer = SDL_CreateTextureFromSurface(renderer, sJouer);
	
	SDL_Rect rJouer;
	rJouer.x = 350; 
	rJouer.y = 200;
	rJouer.w = 300;
	rJouer.h = 100;

	SDL_RenderCopy(renderer, mJouer, NULL, &rJouer);


	sRegles = TTF_RenderText_Solid(Sans, "Regles", White);

	SDL_Texture* mRegles = SDL_CreateTextureFromSurface(renderer, sRegles);
	
	SDL_Rect rRegles;
	rRegles.x = 350; 
	rRegles.y = 350;
	rRegles.w = 300;
	rRegles.h = 100;

	SDL_SetTextInputRect(&rRegles);
	SDL_RenderCopy(renderer, mRegles, NULL, &rRegles);

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
								fenetreJeu(pWindow, renderer);
								running = 0;
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

	//Destruction de la fenetre
	SDL_DestroyWindow(pWindow);
	TTF_Quit();
   	SDL_Quit();

    return 0;
}
