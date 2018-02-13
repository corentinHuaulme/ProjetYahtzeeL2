#ifndef COMBINAISON_H_
#define COMBINAISON_H_

#include <stdio.h>
#include <stdlib.h>
#include "de.h"


typedef struct combinaison_s{
	de_t * tabDe[5];

	int cpt1;
	int cpt2;
	int cpt3;
	int cpt4;
	int cpt5;
	int cpt6;

	int brelan;
	int petite_suite;
	int grande_suite;
	int full;
	int carre;
	int yahtzee;
	int chance;
	int simple;
}combinaison_t;

combinaison_t * creerCombinaison(de_t **);
void combinaisonPossible(combinaison_t *);

#endif