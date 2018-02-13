#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "joueur.h"


static void afficher_nom(joueur_t * const player) {	
      printf( "%s" , player->nom ) ;
}

static void afficher_score(joueur_t * const player) {
      printf( "%i" , player->score) ;
}

 
extern joueur_t * joueur_creer( char * const nom , int const score ) {  	/*fonction de creation de joueur*/
  
  joueur_t * player = malloc(sizeof(joueur_t));
  player->nom = malloc(sizeof(char));
  player->afficher_nom = afficher_nom;
  player->afficher_score = afficher_score;
  strcpy(player->nom, nom);							           
  player->score = score;  													
  return( player ) ;
}

int main(){
	joueur_t * joueur = NULL;
	printf( "Test creation du joueur\n" ) ;
  	joueur = joueur_creer( "Andy" , 250 ) ;

  	printf( "Test affichage nom joueur\n" ) ;  
  	joueur->afficher_nom(joueur);				/*affichage du nom du joueur */
  	printf( "\n");
  	
  	printf( "Test affichage score joueur\n" ) ;  
  	joueur->afficher_score(joueur);				/*affichage du score du joueur */
  	printf( "\n");
	
}
