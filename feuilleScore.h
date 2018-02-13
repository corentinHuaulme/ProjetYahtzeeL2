#ifndef FEUILLESCORE_H_
#define FEUILLESCORE_H_

#include <stdio.h>
#include <stdlib.h>
#include "combinaison.h"


typedef struct feuille_score_s{
	
	int totalUn;
	int totalDeux;
	int totalTrois;
	int totalQuatre;
	int totalCinq;
	int totalSix;
	int totalFull;
	int totalBrelan;
	int totalCarre;
	int totalPetiteSuite;
	int totalGrandeSuite;
	int totalChance;
	int totalYahtzee;

}feuille_score_t;

feuille_score_t * creerFeuilleScore();

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

#endif