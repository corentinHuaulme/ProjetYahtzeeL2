/**
* \file joueur.c
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Contient toutes les fonctions permettant de manipuler un joueur_t.
* \date Mardi 20 Février 2018
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "joueur.h"

/**
 \fn void afficher_nom(joueur_t * const player)
 \brief Permet d'écrire dans le terminal le nom du joueur passé en paramètre.
 \param joueur_t * const player pour le joueur_t..
**/
void afficher_nom(joueur_t * const player) {	
      printf( "%s" , player->nom ) ;
}
/**
 \fn void afficher_score(joueur_t * const player)
 \brief Permet d'écrire dans le terminal le nom du joueur passé en paramètre.
 \param joueur_t * const player pour le joueur_t.
**/
void afficher_score(joueur_t * const player) {
      printf( "%i" , player->score) ;
}

/**
 \fn extern joueur_t joueur_creer(char * const nom, int const score)
 \brief Permet de créer un joueur_t avec les valeurs passées en paramètre.
 \param char * const nom pour le nom du joueur_t.
 \param int const score pour le score du joueur_t.
**/
extern joueur_t * joueur_creer( char * const nom , int const score) {
  
  joueur_t * player = malloc(sizeof(joueur_t));
  player->nom = malloc((sizeof(char) * strlen(nom))+1);
  player->feuil = malloc(sizeof(feuille_score_t));
  strcpy(player->nom, nom);
  player->score = score;											
  return( player ) ;
}
/**
 \fn extern void setFeuilleScore(joueur_t * j, feuille_score_t * f);
 \brief Assigne la feuille_score_t f au joueur_t j
 \param joueur_t * j pour le joueur_t à modifier.
 \param feuille_score_t * f pour la feuille_score_t à assigner au joueur_t.
**/
extern void setFeuilleScore(joueur_t * j, feuille_score_t * f){
		j->feuil = f;
}
