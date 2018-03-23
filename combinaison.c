#include<stdio.h>
#include<stdlib.h>
#include "de.h"
#include "combinaison.h"

combinaison_t * creerCombinaison(de_t ** tab){
	combinaison_t * combi = malloc(sizeof(combinaison_t));
	int i=0;

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
	for(i=0;i<5;i++){
		printf("tab %i %i\n",i, tab[i]->nombreFace);
		combi->tabDe[i] = creerDe();
		combi->tabDe[i]->nombreFace = tab[i]->nombreFace;
		combi->tabDe[i]->nomImage = tab[i]->nomImage;
		switch (tab[i]->nombreFace){
			case 1 :
				combi->cpt1++;
				break;
			case 2 :
				combi->cpt2++;
				break;
			case 3 :
				combi->cpt3++;
				break;
			case 4 :
				combi->cpt4++;
				break;
			case 5 :
				combi->cpt5++;
				break;
			case 6 :
				combi->cpt6++;
				break;
		}
	}
	return combi;
}

int brelan(combinaison_t * com){
	com->brelan = 0;
	if(com->cpt1 >= 3 || com->cpt2 >= 3 || com->cpt3 >= 3 || com->cpt4 >= 3 || com->cpt5 >= 3 || com->cpt6 >= 3){
		int i=0;
		for(i=0;i<5;i++){
			com->brelan+=com->tabDe[i]->nombreFace;
		}
	}
	printf("Brelan : %i\n",com->brelan);
	return com->brelan;
}

int petite_suite(combinaison_t * com){
	com->petite_suite = 0;
	if((com->cpt1>0 && com->cpt2>0 && com->cpt3>0 && com->cpt4>0) || (com->cpt2>0 && com->cpt3>0 && com->cpt4>0 && com->cpt5>0) || (com->cpt3>0 && com->cpt4>0 && com->cpt5>0 && com->cpt6>0)){
		com->petite_suite = 30;
	}
	return com->petite_suite;
}

int grande_suite(combinaison_t * com){
	com->grande_suite = 0;
	if((com->cpt1>0 && com->cpt2>0 && com->cpt3>0 && com->cpt4>0 && com->cpt5>0) || (com->cpt2>0 && com->cpt3>0 && com->cpt4>0 && com->cpt5>0 && com->cpt6>0)){
		com->grande_suite = 40;
	}
	return com->grande_suite;
}
int chance(combinaison_t * com){
	int i=0;
	com->chance=0;
	for(i=0;i<5;i++){
		com->chance+=com->tabDe[i]->nombreFace;
	}
	return com->chance;
}
int full(combinaison_t * com){
	com->full=0;
	if((com->cpt1==2 && com->cpt2==3) || (com->cpt1==2 && com->cpt3==3) || (com->cpt1==2 && com->cpt4==3) || (com->cpt1==2 && com->cpt5==3) || (com->cpt1==2 && com->cpt6==3)){
		com->full = 25;
	}
	if((com->cpt2==2 && com->cpt1==3) || (com->cpt2==2 && com->cpt3==3) || (com->cpt2==2 && com->cpt4==3) || (com->cpt2==2 && com->cpt5==3) || (com->cpt2==2 && com->cpt6==3)){
		com->full = 25;
	}
	if((com->cpt3==2 && com->cpt1==3) || (com->cpt3==2 && com->cpt2==3) || (com->cpt3==2 && com->cpt4==3) || (com->cpt3==2 && com->cpt5==3) || (com->cpt3==2 && com->cpt6==3)){
		com->full = 25;
	}
	if((com->cpt4==2 && com->cpt1==3) || (com->cpt4==2 && com->cpt2==3) || (com->cpt4==2 && com->cpt3==3) || (com->cpt4==2 && com->cpt5==3) || (com->cpt4==2 && com->cpt6==3)){
		com->full = 25;
	}
	if((com->cpt5==2 && com->cpt1==3) || (com->cpt5==2 && com->cpt2==3) || (com->cpt5==2 && com->cpt3==3) || (com->cpt5==2 && com->cpt4==3) || (com->cpt5==2 && com->cpt5==3)){
		com->full = 25;
	}
	if((com->cpt6==2 && com->cpt1==3) || (com->cpt6==2 && com->cpt2==3) || (com->cpt6==2 && com->cpt3==3) || (com->cpt6==2 && com->cpt4==3) || (com->cpt6==2 && com->cpt5==3)){
		com->full = 25;
	}
	return com->full;
}

int carre(combinaison_t * com){
	com->carre = 0;
	if(com->cpt1 == 4 || com->cpt2 == 4 || com->cpt3 == 4 || com->cpt4 == 4 || com->cpt5 == 4 || com->cpt6 == 4){
		int i=0;
		for(i=0;i<5;i++){
			com->carre+=com->tabDe[i]->nombreFace;
		}
	}
	return com->carre;
}

int yahtzee(combinaison_t * com){
	com->yahtzee = 0;
	if(com->cpt1 == 5 || com->cpt2 == 5 || com->cpt3 == 5 || com->cpt4 == 5 || com->cpt5 == 5 || com->cpt6 == 5){
		com->yahtzee = 50;
	}
	return com->yahtzee;
}

int cpt1(combinaison_t * com){
	return com->cpt1;
}

int cpt2(combinaison_t * com){
	return com->cpt2;
}

int cpt3(combinaison_t * com){
	return com->cpt3;
}

int cpt4(combinaison_t * com){
	return com->cpt4;
}

int cpt5(combinaison_t * com){
	return com->cpt5;
}

int cpt6(combinaison_t * com){
	return com->cpt6;
}
