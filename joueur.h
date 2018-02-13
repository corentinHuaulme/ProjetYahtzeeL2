#ifndef _PROJET_DE_H
#define _PROJET_DE_H
#include <stdio.h>
#include <stdlib.h>


/* Definition du type erreur */
typedef int err_t ; 

typedef struct joueur_s{ 
	void (*afficher_nom)( struct joueur_s * const );
	void (*afficher_score)(struct joueur_s * const );												/* structure joueur contenant le nom et le score de celui-ci*/
	char *nom;
	int score;
}joueur_t;

/*fonction qui verifie l'existence du joueur*/


/*fonction creation du joueur*/
extern joueur_t * joueur_creer( char * const prenom  , int const nom  );

#endif