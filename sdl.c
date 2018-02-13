#include "SDL2/SDL.h"

#include <stdio.h>

const int WIDTH  = 640;
const int HEIGHT = 480;
 
Uint32 couleur(int r, int g, int b)
{ return (((r<<8)+ g)<<8 )+ b; }
 
void dessin(SDL_Renderer * ren, SDL_Texture * tex, Uint32 * pixels, float alpha) 
{
  Uint32  *p;
  Uint8 r,g,b;
  int x,y;
  float beta = 1-alpha;
  pixels = (Uint32*) malloc(WIDTH*HEIGHT*sizeof(Uint32));
  if (!pixels) {fprintf(stderr,"Erreur allocation\n"); return;}
 
  tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888,
								  SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
 
  p = pixels;
  for(y=0;y<HEIGHT;y++)
	 {
		for(x=0;x<WIDTH;x++)
		  {
			 r = 255 * y / HEIGHT;
			 g = 255 * x / WIDTH;
			 b = 255 * (x+y) / (WIDTH+HEIGHT);
 
			 *p=couleur(alpha*r+beta*g,alpha*g+beta*b,alpha*b+beta*r);
			 p++;
		  }
	 }
  SDL_UpdateTexture(tex, NULL, pixels, WIDTH * sizeof (Uint32));
  SDL_RenderCopy(ren,tex, NULL, NULL);
  SDL_RenderPresent(ren);
  SDL_DestroyTexture(tex);
  free(pixels);
}

SDL_Texture* loadTexture(char * filename, SDL_Renderer *ren){
        SDL_Texture *texture = 0;
        SDL_Surface *loadedImage = 0;
        loadedImage = SDL_LoadBMP(filename);
        if (!loadedImage)
          {
          fprintf(stderr,"Erreur chargement image : %s\n",SDL_GetError());
          return 0;
          }
 
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        if (texture == 0)
          {
          fprintf(stderr,"Erreur creation texture : %s\n",SDL_GetError());
          return 0;
          }
        return texture;
}

int main(int argc, char** argv)
{
  SDL_Window *win = 0;
  SDL_Renderer *ren = 0;
  Uint32 * pixels = 0;
  SDL_Texture * tex = 0;
  float alpha = 0.0;
  float pas = 0.03;
  int n;
  /* Initialisation de la SDL. Si ça se passe mal, on quitte */
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
      fprintf(stderr,"Erreur initialisation\n");
      return -1;
  }
  /* Création de la fenêtre et du renderer */
  SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &ren);
 
  if (!win || !ren) 
	 {
		fprintf(stderr,"Erreur à la création des fenêtres\n");
		SDL_Quit();
		return -1;
	 }
  /* Affichage du fond noir */
  SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
  SDL_RenderClear(ren);
  SDL_RenderPresent(ren);
 
  pixels = (Uint32*) malloc(WIDTH*HEIGHT*sizeof(Uint32));
  if (!pixels) {fprintf(stderr,"Erreur allocation\n"); return;}
 
  tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888,
				 SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
 
  for (n=0;n<1000L;n++) {
	 dessin(ren,tex,pixels,alpha);
	 alpha += pas;
	 if (alpha > 1.0) { alpha = 1.0; pas = -pas;}
	 if (alpha < 0.0) { alpha = 0.0; pas = -pas;}
  }
 
  SDL_Delay(1000);
 
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}