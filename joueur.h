#ifndef _PROJET_DE_H
#define _PROJET_DE_H
#include <stdio.h>
#include <stdlib.h>


typedef struct joueur_s{ 												/* structure joueur contenant le nom et le score de celui-ci*/
	char *nom;
	int score;
}joueur_t;

/*fonction destruction du joueur*/
void individu_detruire( joueur_t ** player );

/*fonction qui verifie l'existence du joueur*/
int joueur_existe( joueur_t * const player );

/*fonction afficher le nom du joueur*/
void afficher_nom(joueur_t * player);

/*fonction affichage du score*/
void afficher_score(joueur_t * player);

/*fonction creation du joueur*/
void joueur_t * player_creer( char * const prenom , int const nom );

#endif