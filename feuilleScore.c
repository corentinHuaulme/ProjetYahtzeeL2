#include <stdio.h>
#include <stdlib.h>
#include "feuilleScore.h"
#include "combinaison.h"

feuille_score_t * creerFeuilleScore(){
	feuille_score_t * feuil;
	feuil->totalUn = 0;
	feuil->totalDeux = 0;
	feuil->totalTrois = 0;
	feuil->totalQuatre = 0;
	feuil->totalCinq = 0;
	feuil->totalSix = 0;
	feuil->totalBrelan = 0;
	feuil->totalPetiteSuite = 0;
	feuil->totalGrandeSuite = 0;
	feuil->totalCarre = 0;
	feuil->totalYahtzee = 0;
	
	return feuil;
}

void ajout_un(feuille_score_t * f, combinaison_t com){
	f->totalUn = com.cpt1;
}
void ajout_deux(feuille_score_t * f, combinaison_t com){
	f->totalDeux = com.cpt2;
}
void ajout_trois(feuille_score_t * f, combinaison_t com){
	f->totalTrois = com.cpt3;
}
void ajout_quatre(feuille_score_t * f, combinaison_t com){
	f->totalQuatre = com.cpt4;
}
void ajout_cinq(feuille_score_t * f, combinaison_t com){
	f->totalCinq = com.cpt5;
}
void ajouts_six(feuille_score_t * f, combinaison_t com){
	f->totalSix = com.cpt6;
}

void ajout_brelan(feuille_score_t * f, combinaison_t com){
	if(com.cpt1==3){
		f->totalBrelan = com.cpt1;
	}else if(com.cpt2==3){
		f->totalBrelan = com.cpt2 * 2;
	}else if(com.cpt3==3){
		f->totalBrelan = com.cpt3 * 3;
	}else if(com.cpt4==3){
		f->totalBrelan = com.cpt4 * 4;
	}else if(com.cpt5==3){
		f->totalBrelan = com.cpt5 * 5;
	}else if(com.cpt6==3){
		f->totalBrelan = com.cpt6 * 6;
	}
}
void ajout_carre(feuille_score_t * f, combinaison_t com){
	if(com.cpt1==4){
		f->totalBrelan = com.cpt1 * 1;
	}else if(com.cpt2==4){
		f->totalBrelan = com.cpt2 * 2;
	}else if(com.cpt3==4){
		f->totalBrelan = com.cpt3 * 3;
	}else if(com.cpt4==4){
		f->totalBrelan = com.cpt4 * 4;
	}else if(com.cpt5==4){
		f->totalBrelan = com.cpt5 * 5;
	}else if(com.cpt6==4){
		f->totalBrelan = com.cpt6 * 6;
	}
}
void ajout_chance(feuille_score_t * f, combinaison_t com){
	f->totalChance+=com.cpt1;
	f->totalChance+=com.cpt2*2;
	f->totalChance+=com.cpt3*3;
	f->totalChance+=com.cpt4*4;
	f->totalChance+=com.cpt5*5;
	f->totalChance+=com.cpt6*6;
}
void ajout_petite_suite(feuille_score_t * f){
	f->totalPetiteSuite = 30;
}
void ajout_full(feuille_score_t * f){
	f->totalFull = 25;
}
void ajout_grande_suite(feuille_score_t * f){
	f->totalGrandeSuite = 40;
}
void ajout_yahtzee(feuille_score_t * f){
	f->totalYahtzee = 50;
}