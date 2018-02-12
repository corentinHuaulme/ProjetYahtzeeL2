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

	return combi;
}

void combinaisonPossible(combinaison_t * com){
	int i=0, cpt1=0,cpt2=0,cpt3=0,cpt4=0,cpt5=0,cpt6=0;
	for(i=0;i<5;i++){
		switch(com->tabDe[i]->nombreFace){
			case 1 :
				cpt1++;
				break;
			case 2 :
				cpt2++;
				break;
			case 3 :
				cpt3++;
				break;
			case 4 :
				cpt4++;
				break;
			case 5 :
				cpt5++;
				break;
			case 6 :
				cpt6++;
				break;
		}
	}
	if((cpt1>0 && cpt2>0 && cpt3>0 && cpt4>0) || (cpt2>0 && cpt3>0 && cpt4>0 && cpt5>0) || (cpt3>0 && cpt4>0 && cpt5>0 && cpt6>0)){
		com->petite_suite = 1;
	}
	if((cpt1>0 && cpt2>0 && cpt3>0 && cpt4>0 && cpt5>0) || (cpt2>0 && cpt3>0 && cpt4>0 && cpt5>0 && cpt6>0)){
		com->grande_suite = 1;
	}
	if((cpt1>=2 && cpt2>=2) || (cpt2>=2 && cpt3>=2) || (cpt3>=2 && cpt4>=2) || (cpt4>=2 && cpt5>=2) || (cpt5>=2 && cpt6>=2)){
		com->full = 1;
	}
	if(cpt1 == 3 || cpt2 == 3 || cpt3 == 3 || cpt4 == 3 || cpt5 == 3 || cpt6 == 3){
		com->brelan = 1;
	}
	if(cpt1 == 4 || cpt2 == 4 || cpt3 == 4 || cpt4 == 4 || cpt5 == 4 || cpt6 == 4){
		com->carre = 1;
	}
	if(cpt1 == 5 || cpt2 == 5 || cpt3 == 5 || cpt4 == 5 || cpt5 == 5 || cpt6 == 5){
		com->yahtzee = 1;
	}
	
}
