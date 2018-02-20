#ifndef _PROJET_JOUEUR_H
#define _PROJET_JOUEUR_H
#include <stdio.h>
#include <stdlib.h>
#include "feuilleScore.h"


/* Definition du type erreur */
typedef int err_t ; 

typedef struct joueur_s{												/* structure joueur contenant le nom et le score de celui-ci*/
	char *nom;
	int score;
	feuille_score_t * feuil;
}joueur_t;

/*fonction qui verifie l'existence du joueur*/


/*fonction creation du joueur*/
extern joueur_t * joueur_creer( char * const prenom  , int const nom  );
extern void afficher_nom(joueur_t * const player);
extern void afficher_score(joueur_t * const player);
extern void setFeuilleScore(joueur_t *, feuille_score_t *);
#endif