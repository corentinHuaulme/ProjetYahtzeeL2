#include <stdio.h>
#include "sdlJeu.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

int afficheFenetreJoueur(SDL_Window* win, SDL_Renderer* ren)
{
	//Le pointeur vers les surfaces incluse dans la fenetre
	SDL_Surface* sTitre = NULL;
	SDL_Surface* sJoueur = NULL;
	SDL_Surface* sRetour = NULL;

    // Set render color to red ( background will be rendered in this color )
	SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

    // Clear winow
	SDL_RenderClear( renderer );

	TTF_Font* Sans = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 24); //this opens a font style and sets a size

	if(Sans == NULL){
		printf("ERROR");
	}

	SDL_Color White = {255, 255, 255};

	sTitre = TTF_RenderText_Solid(Sans, "Yahtzee du pauvre", White);

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
							}
						    break;
						case SDL_BUTTON_RIGHT:
						    SDL_ShowSimpleMessageBox(0, "Mouse", "Right button was pressed!", pWindow);
						    break;
						default:
						    SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", pWindow);
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
