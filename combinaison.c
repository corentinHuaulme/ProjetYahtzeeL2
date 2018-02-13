#include<stdio.h>
#include<stdlib.h>
#include "de.h"
#include "combinaison.h"

combinaison_t * creerCombinaison(de_t ** tab){
	combinaison_t * combi = malloc(sizeof(combinaison_t));
	int i=0;
	for(i=0;i<5;i++){
		combi->tabDe[i] = tab[i];
	}
	combi->brelan = 0;
	combi->full = 0;
	combi->carre = 0;
	combi->petite_suite = 0;
	combi->grande_suite = 0;
	combi->yahtzee = 0;

	combi->cpt1 = 0;
	combi->cpt2 = 0;
	combi->cpt3 = 0;
	combi->cpt4 = 0;
	combi->cpt5 = 0;
	combi->cpt6 = 0;
	return combi;
}

void combinaisonPossible(combinaison_t * com){
	int i=0;
	for(i=0;i<5;i++){
		switch(com->tabDe[i]->nombreFace){
			case 1 :
				com->cpt1++;
				break;
			case 2 :
				com->cpt2++;
				break;
			case 3 :
				com->cpt3++;
				break;
			case 4 :
				com->cpt4++;
				break;
			case 5 :
				com->cpt5++;
				break;
			case 6 :
				com->cpt6++;
				break;
		}
	}
	if((com->cpt1>0 && com->cpt2>0 && com->cpt3>0 && com->cpt4>0) || (com->cpt2>0 && com->cpt3>0 && com->cpt4>0 && com->cpt5>0) || (com->cpt3>0 && com->cpt4>0 && com->cpt5>0 && com->cpt6>0)){
		com->petite_suite = 1;
	}
	if((com->cpt1>0 && com->cpt2>0 && com->cpt3>0 && com->cpt4>0 && com->cpt5>0) || (com->cpt2>0 && com->cpt3>0 && com->cpt4>0 && com->cpt5>0 && com->cpt6>0)){
		com->grande_suite = 1;
	}
	if((com->cpt1>=2 && com->cpt2>=2) || (com->cpt2>=2 && com->cpt3>=2) || (com->cpt3>=2 && com->cpt4>=2) || (com->cpt4>=2 && com->cpt5>=2) || (com->cpt5>=2 && com->cpt6>=2)){
		com->full = 1;
	}
	if(com->cpt1 == 3 || com->cpt2 == 3 || com->cpt3 == 3 || com->cpt4 == 3 || com->cpt5 == 3 || com->cpt6 == 3){
		com->brelan = 1;
	}
	if(com->cpt1 == 4 || com->cpt2 == 4 || com->cpt3 == 4 || com->cpt4 == 4 || com->cpt5 == 4 || com->cpt6 == 4){
		com->carre = 1;
	}
	if(com->cpt1 == 5 || com->cpt2 == 5 || com->cpt3 == 5 || com->cpt4 == 5 || com->cpt5 == 5 || com->cpt6 == 5){
		com->yahtzee = 1;
	}
	
}

combinaison_t * aideCombinaison(de_t * tab[5]){
	combinaison_t * comb = creerCombinaison(tab);
	combinaisonPossible(comb);
	return comb;
}
