/**
* \file res_score.h
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Header du fichier "res_score.c"
* \date Mardi 20 Février 2018
*/

#ifndef RESSCORE_H
#define RES_SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include"feuilleScore.h"

int sauvegarder_feuilleScore(feuille_score_t*);
feuille_score_t* charger_feuilleScore();
int afficher_feuilleScore(feuille_score_t*);

#endif

