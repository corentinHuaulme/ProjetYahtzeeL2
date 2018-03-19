#ifndef RESSCORE_H
#define RES_SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include"feuilleScore.h"

int sauvegarder_feuilleScore(feuille_score_t*);
feuille_score_t* charger_feuilleScore();
int afficher_feuilleScore(feuille_score_t*);

#endif