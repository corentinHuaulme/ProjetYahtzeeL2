/**
* \file combinaison.h
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Header du fichier "combinaison.c" contenant la definition de la structure "combinaison_t"
* \date Mardi 20 Février 2018
*/


#ifndef COMBINAISON_H_
#define COMBINAISON_H_

#include <stdio.h>
#include <stdlib.h>
#include "de.h"

/**
 \struct combinaison_t
 \brief Contient les valeurs des différentes figures possibles avec tabDe.
**/
typedef struct{
	de_t * tabDe[5]; ///< Tableau de pointeurs de de_t

	int cpt1; ///< Nombre de de_t ayant pour face "1"
	int cpt2; ///< Nombre de de_t ayant pour face "2"
	int cpt3; ///< Nombre de de_t ayant pour face "3"
	int cpt4; ///< Nombre de de_t ayant pour face "4"
	int cpt5; ///< Nombre de de_t ayant pour face "5"
	int cpt6; ///< Nombre de de_t ayant pour face "6"

	int brelan; ///< Valeur du brelan contenu dans tabDe
	int petite_suite; ///< Valeur de la petite suite contenu dans tabDe
	int grande_suite; ///< Valeur de la grande suite contenu dans tabDe
	int full; ///< Valeur du full contenu dans tabDe
	int carre; ///< Valeur du carre contenu dans tabDe
	int yahtzee; ///< Valeur du yahtzee contenu dans tabDe
	int chance; ///< Somme des de_t contenu dans tabDe
}combinaison_t;

combinaison_t * creerCombinaison(de_t **);
int brelan(combinaison_t*);
int petite_suite(combinaison_t*);
int grande_suite(combinaison_t*);
int full(combinaison_t*);
int carre(combinaison_t*);
int yahtzee(combinaison_t*);
int chance(combinaison_t*);
int cpt1(combinaison_t*);
int cpt2(combinaison_t*);
int cpt3(combinaison_t*);
int cpt4(combinaison_t*);
int cpt5(combinaison_t*);
int cpt6(combinaison_t*);

#endif
