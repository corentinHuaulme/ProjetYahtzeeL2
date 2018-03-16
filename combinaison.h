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
