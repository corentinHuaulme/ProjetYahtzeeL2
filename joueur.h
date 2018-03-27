/**
* \file joueur.h
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Header du fichier "joueur.c" contenant la definition de la structure "joueur_t"
* \date Mardi 20 Février 2018
*/

#ifndef _PROJET_JOUEUR_H
#define _PROJET_JOUEUR_H
#include <stdio.h>
#include <stdlib.h>
#include "feuilleScore.h"


/**
 \var typedef int err_t
 \brief Une définition du type d'erreur
*/
typedef int err_t ; 

/**
 \struct joueur_t
 \brief Représente un joueur
*/
typedef struct{
	char *nom; ///< Nom du joueur
	int score; ///< Score du joueur
	feuille_score_t * feuil; ///< feuille_score_t du joueur
}joueur_t;

extern joueur_t * joueur_creer( char * const prenom  , int const nom  );
extern void afficher_nom(joueur_t * const player);
extern void afficher_score(joueur_t * const player);
extern void setFeuilleScore(joueur_t *, feuille_score_t *);
#endif
