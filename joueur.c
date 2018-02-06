#include <stdlib.h>
#include <stdio.h>

const int VRAI  1
const int FAUX  0

typedef struct joueur_s{ 												/* structure joueur contenant le nom et le score de celui-ci*/
	char *nom;
	int score;
}joueur_t;


void individu_detruire( joueur_t ** player ) {
	  if(joueur_existe(*player)) {
    free((*player)->nom);												/*liberation mémoire* de l'attribut nom*/
    free((*player)->score);												/*liberation mémoire de l'attribut score*/
    free(*player);														/*liberation mémoire*/
  }
  
  return(OK) ;
}

int joueur_existe( joueur_t * const player ) {
  if( player == NULL ) 
    return(FAUX) ;
  else
    return(VRAI) ; 
}

int afficher_nom(joueur_t * player) {	
	 printf( "%s" ,  individu->nom );
}

int afficher_score(joueur_t * player) {
	 printf( "%i" ,  individu->score );
}
 
void joueur_t * player_creer( char * const prenom , int const nom ) {  	/*fonction de creation de joueur*/
  joueur_t * player = malloc(sizeof(joueur_t));
  
  player->nom = malloc(sizeof(char));               					/*allocation memoire pour nom*/
  player->score = malloc(sizeof(int));			  						/*allocation memoire pour score*/ 
  
  
  return( player ) ;
}

