#include <stdio.h>
#include <stdlib.h>
#include "de.h"

typedef struct combinaison{
	de_t * tabDe[5];

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
