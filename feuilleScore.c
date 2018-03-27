/**
* \file feuilleScore.c
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Contient toutes les fonctions pour manipuler une feuille de score feuille_score_t
* \date Mardi 20 Février 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include "feuilleScore.h"
#include "combinaison.h"

/**
 \fn feuille_score_t * creerFeuilleScore()
 \brief Créer une structure feuille_score_t vierge.
 \return Une feuille_score vierge
**/
feuille_score_t * creerFeuilleScore(){
	feuille_score_t * feuil = malloc(sizeof(feuille_score_t));
	feuil->totalUn = 0;
	feuil->totalDeux = 0;
	feuil->totalTrois = 0;
	feuil->totalQuatre = 0;
	feuil->totalCinq = 0;
	feuil->totalSix = 0;
	feuil->totalBrelan = 0;
	feuil->totalFull = 0;
	feuil->totalPetiteSuite = 0;
	feuil->totalGrandeSuite = 0;
	feuil->totalCarre = 0;
	feuil->totalChance = 0;
	feuil->totalYahtzee = 0;
	
	return feuil;
}
/**
 \fn void afficheScore(feuille_score_t * feuil)
 \brief Fonction de debug affichant les valeurs de la feuille de score dans le terminal
 \param feuile feuille_score_t*
**/
void afficheScore(feuille_score_t * feuil){
	printf("Total un : %d\n", feuil->totalUn);
	printf("Total deux : %d\n", feuil->totalDeux);
	printf("Total trois : %d\n", feuil->totalTrois);
	printf("Total quatre : %d\n", feuil->totalQuatre);
	printf("Total cinq : %d\n", feuil->totalCinq);
	printf("Total six : %d\n", feuil->totalSix);
	printf("Total brelan : %d\n", feuil->totalBrelan);
	printf("Total carre : %d\n", feuil->totalCarre);
	printf("Total full : %d\n", feuil->totalFull);
	printf("Total petite suite : %d\n", feuil->totalPetiteSuite);
	printf("Total grande suite : %d\n", feuil->totalGrandeSuite);
	printf("Total chance : %d\n", feuil->totalChance);
	printf("Total yahtzee : %d\n", feuil->totalYahtzee);
}
/**
 \fn void ajout_un(feuille_score_t * f, combinaison_t com)
 \brief Ajoute la somme des dés ayant pour face "1" dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_un(feuille_score_t * f, combinaison_t com){
	f->totalUn = com.cpt1;
}
/**
 \fn void ajout_deux(feuille_score_t * f, combinaison_t com)
 \brief Ajoute la somme des dés ayant pour face "2" dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_deux(feuille_score_t * f, combinaison_t com){
	f->totalDeux = com.cpt2 * 2;
}
/**
 \fn void ajout_trois(feuille_score_t * f, combinaison_t com)
 \brief Ajoute la somme des dés ayant pour face "3" dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_trois(feuille_score_t * f, combinaison_t com){
	f->totalTrois = com.cpt3 * 3;
}
/**
 \fn void ajout_quatre(feuille_score_t * f, combinaison_t com)
 \brief Ajoute la somme des dés ayant pour face "4" dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_quatre(feuille_score_t * f, combinaison_t com){
	f->totalQuatre = com.cpt4 * 4;
}
/**
 \fn void ajout_cinq(feuille_score_t * f, combinaison_t com)
 \brief Ajoute la somme des dés ayant pour face "5" dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_cinq(feuille_score_t * f, combinaison_t com){
	f->totalCinq = com.cpt5 * 5;
}
/**
 \fn void ajout_six(feuille_score_t * f, combinaison_t com)
 \brief Ajoute la somme des dés ayant pour face "6" dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_six(feuille_score_t * f, combinaison_t com){
	f->totalSix = com.cpt6 * 6;
}
/**
 \fn void ajout_brelan(feuille_score_t * f, combinaison_t com)
 \brief Ajoute la somme des dés calculée dans le fichier "combinaison.c" (si il n'y a pas de brelan, la valeur de brelan dans la combinaison est de 0) dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_brelan(feuille_score_t * f, combinaison_t com){
	int i=0;
	f->totalBrelan = 0;
	for(i=0;i<5;i++){
		f->totalBrelan+= com.tabDe[i]->nombreFace;
	}
}
/**
 \fn void ajout_carre(feuille_score_t * f, combinaison_t com)
 \brief Ajoute la somme des dés calculée dans le fichier "combinaison.c" (si il n'y a pas de carré, la valeur de carré dans la combinaison est de 0) dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_carre(feuille_score_t * f, combinaison_t com){
	if(com.cpt1==4){
		f->totalCarre = com.cpt1 * 1;
	}else if(com.cpt2==4){
		f->totalCarre = com.cpt2 * 2;
	}else if(com.cpt3==4){
		f->totalCarre = com.cpt3 * 3;
	}else if(com.cpt4==4){
		f->totalCarre = com.cpt4 * 4;
	}else if(com.cpt5==4){
		f->totalCarre = com.cpt5 * 5;
	}else if(com.cpt6==4){
		f->totalCarre = com.cpt6 * 6;
	}
}
/**
 \fn void ajout_chance(feuille_score_t * f, combinaison_t com)
 \brief Ajoute la somme des dés calculée dans le fichier "combinaison.c" dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_chance(feuille_score_t * f, combinaison_t com){
	f->totalChance+=com.cpt1;
	f->totalChance+=com.cpt2*2;
	f->totalChance+=com.cpt3*3;
	f->totalChance+=com.cpt4*4;
	f->totalChance+=com.cpt5*5;
	f->totalChance+=com.cpt6*6;
}
/**
 \fn void ajout_petite_suite(feuille_score_t * f, combinaison_t com)
 \brief Ajoute 30 (si il n'y a pas de petite suite, la valeur de petite suit dans la combinaison est de 0) dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_petite_suite(feuille_score_t * f){
	f->totalPetiteSuite = 30;
}
/**
 \fn void ajout_full(feuille_score_t * f, combinaison_t com)
 \brief Ajoute 25 (si il n'y a pas de full, la valeur de full dans la combinaison est de 0) dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_full(feuille_score_t * f){
	f->totalFull = 25;
}
/**
 \fn void grande_suite(feuille_score_t * f, combinaison_t com)
 \brief Ajoute 40 (si il n'y a pas de grande suite, la valeur de grande suite dans la combinaison est de 0) dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_grande_suite(feuille_score_t * f){
	f->totalGrandeSuite = 40;
}
/**
 \fn void ajou_yahtzee(feuille_score_t * f, combinaison_t com)
 \brief Ajoute 50 (si il n'y a pas de yahtzee, la valeur de yahtzee dans la combinaison est de 0) dans la feuille de score passée en paramètre
 \param feuille_score_t * f pour la feuille de score
 \param combinaison_t com pour la combinaison de dés correspondantes
**/
void ajout_yahtzee(feuille_score_t * f){
	f->totalYahtzee = 50;
}
/**
 \fn int totalPoint(feuille_score_t * f)
 \brief Calcule la somme de toutes les lignes de la feuille de score
 \param feuille_score_t * f pour la feuille de score à calculer
 \return La somme de la feuille de score
**/
int totalPoint(feuille_score_t * f){
	int somme=0;
	somme+=f->totalUn;
	somme+=f->totalDeux;
	somme+=f->totalTrois;
	somme+=f->totalQuatre;
	somme+=f->totalCinq;
	somme+=f->totalSix;
	somme+=f->totalBrelan;
	somme+=f->totalFull;
	somme+=f->totalCarre;
	somme+=f->totalPetiteSuite;
	somme+=f->totalGrandeSuite;
	somme+=f->totalChance;
	somme+=f->totalYahtzee;
	return somme;
}
