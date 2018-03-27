/**
* \file feuilleScore.h
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Header du fichier "feuilleScore.c" contenant la definition de la structure "feuille_score_t"
* \date Mardi 20 Février 2018
*/

#ifndef FEUILLESCORE_H_
#define FEUILLESCORE_H_

#include <stdio.h>
#include <stdlib.h>
#include "combinaison.h"

/**
 \struct feuille_score_t
 \brief Représente un feuille de score de yahtzee
**/
typedef struct{
	
	int totalUn; ///< Somme des de_t ayant pour face "1"
	int totalDeux;///< Somme des de_t ayant pour face "2"
	int totalTrois;///< Somme des de_t ayant pour face "3"
	int totalQuatre;///< Somme des de_t ayant pour face "4"
	int totalCinq;///< Somme des de_t ayant pour face "5"
	int totalSix;///< Somme des de_t ayant pour face "6"
	int totalFull;///< Valeur du full (0 pour aucun full / 25 pour un full)
	int totalBrelan;///< Valeur du brelan (0 pour aucun brelan / la somme des de_t pour un brelan)
	int totalCarre;///< Valeur du carre (0 pour aucun carre / la somme des de_t pour un carre)
	int totalPetiteSuite; ///< Valeur de la petite suite (0 pour aucune petite suite / 30 pour une petite suite)
	int totalGrandeSuite;///< Valeur de la grande suite (0 pour aucune grande suite / 40 pour une grande suite)
	int totalChance; ///< Somme des de_t
	int totalYahtzee;///< Valeur du yahtzee (0 pour aucun yahtzee / 50 pour un yahtzee)

}feuille_score_t;

feuille_score_t * creerFeuilleScore();

void afficheScore(feuille_score_t *);

void ajout_un(feuille_score_t *, combinaison_t);
void ajout_deux(feuille_score_t *, combinaison_t);
void ajout_trois(feuille_score_t *, combinaison_t);
void ajout_quatre(feuille_score_t *, combinaison_t);
void ajout_cinq(feuille_score_t *, combinaison_t);
void ajout_six(feuille_score_t *, combinaison_t);

void ajout_brelan(feuille_score_t *, combinaison_t);
void ajout_full(feuille_score_t *);
void ajout_petite_suite(feuille_score_t *);
void ajout_grande_suite(feuille_score_t *);
void ajout_carre(feuille_score_t *, combinaison_t);
void ajout_chance(feuille_score_t *, combinaison_t);
void ajout_yahtzee(feuille_score_t *);
int totalPoint();
#endif
