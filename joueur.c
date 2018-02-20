#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "joueur.h"


void afficher_nom(joueur_t * const player) {	
      printf( "%s" , player->nom ) ;
}

void afficher_score(joueur_t * const player) {
      printf( "%i" , player->score) ;
}

 
extern joueur_t * joueur_creer( char * const nom , int const score) {  	/*fonction de creation de joueur*/
  
  joueur_t * player = malloc(sizeof(joueur_t));
  player->nom = malloc((sizeof(char) * strlen(nom))+1);
  player->feuil = malloc(sizeof(feuille_score_t));
  strcpy(player->nom, nom);
  player->score = score;											
  return( player ) ;
}
extern void setFeuilleScore(joueur_t * j, feuille_score_t * f){
		j->feuil = f;
}
