
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

void afficheCredit(SDL_Window* win, SDL_Renderer* ren){	
	

	SDL_RenderClear(ren);
	SDL_RenderPresent( ren );
	SDL_Surface* sNom1 = NULL;
	SDL_Surface* sNom2 = NULL;
	SDL_Surface* sNom3 = NULL;
	SDL_Surface* sRetour = NULL;
	
	TTF_Font* Sans = TTF_OpenFont("fonts/Montserrat-Regular.ttf", 60);
	SDL_Color White = {255, 255, 255};

	sNom1 = TTF_RenderUTF8_Solid(Sans, "HUAULME Corentin", White);
	SDL_Texture* mNom1 = SDL_CreateTextureFromSurface(ren, sNom1);
	
	SDL_Rect rNom1;
	rNom1.x = 70; 
	rNom1.y = 110;
	SDL_QueryTexture(mNom1, NULL, NULL, &(rNom1.w), &(rNom1.h));
	SDL_RenderCopy(ren, mNom1, NULL, &rNom1);
	

	sNom2 = TTF_RenderUTF8_Solid(Sans,"DINGA Andy", White);
	SDL_Texture* mNom2 = SDL_CreateTextureFromSurface(ren, sNom2);
	
	SDL_Rect rNom2;
	rNom2.x = 70; 
	rNom2.y = 200;
	SDL_QueryTexture(mNom2, NULL, NULL, &(rNom2.w), &(rNom2.h));
	SDL_RenderCopy(ren, mNom2, NULL, &rNom2);
	
	sNom3 = TTF_RenderUTF8_Solid(Sans,"JIANG Lijuan", White);
	SDL_Texture* mNom3 = SDL_CreateTextureFromSurface(ren, sNom3);
	
	SDL_Rect rNom3;
	rNom3.x = 70; 
	rNom3.y = 290;
	SDL_QueryTexture(mNom3, NULL, NULL, &(rNom3.w), &(rNom3.h));
	SDL_RenderCopy(ren, mNom3, NULL, &rNom3);
	
	sRetour = TTF_RenderUTF8_Solid(Sans,"Retour", White);
	SDL_Texture* mRetour = SDL_CreateTextureFromSurface(ren, sRetour);
	
	SDL_Rect rRetour;
	rRetour.x = 1000; 
	rRetour.y = 10;
	SDL_QueryTexture(mRetour, NULL, NULL, &(rRetour.w), &(rRetour.h));
	SDL_RenderCopy(ren, mRetour, NULL, &rRetour);
	
	SDL_RenderPresent( ren );
}
