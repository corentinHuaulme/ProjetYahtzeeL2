#include<stdio.h>
#include<stdlib.h>
#include"feuilleScore.h"


int creer_feuilleScore(){
	int somme_chance;
	int somme_brelan;
	int somme_petite_suite;
	int somme_grande_suite;
	int somme_carre;
	int somme_full;
	int somme_yahtzee;
	feuille_score_t feuille;
	
	FILE*fichier;
	char nom_fic[20];
	printf("donnez le nom du fichier  ");
	scanf("%s",nom_fic);
	
	fichier=fopen("nom_fic","w");
	
	printf("rentrez la somme de chance ");
	somme_chance=somme_chance+feuille.totalUn+feuille.totalDeux+feuille.totalTrois+feuille.totalQuatre+feuille.totalCinq+feuille.totalSix
	scanf("%i",&somme_chance);
	
	printf("rentrez la somme de somme_brelan ");
	somme_brelan=ajout_brelan();
	somme_brelan ++;
	scanf("%i",&somme_brelan);
	
	printf("rentrez la somme de somme_petite_suite ");
	somme_petite_suite = ajout_petit_suite();
	somme_petite_suite++;
	scanf("%i",&somme_petite_suite);
	
	printf("rentrez la somme de somme_grande_suite ");
	somme_grande_suite = ajout_grande_suite();
	somme_grande_suite++;
	scanf("%i",&somme_grande_suite);
	
	printf("rentrez la somme de somme_full ");
	somme_full = ajout_full();
	somme_full++;
	scanf("%i",&somme_full);
	
	printf("rentrez la somme de yahtzee");
	somme_yahtzee=50;
	scanf("%i",&somme_yahtzee);
	
	
	while(somme_chance !=-1 && somme_brelan!=-1 && somme_petite_suite!=-1 && somme_grande_suite!=-1&&somme_carre!=-1&& somme_full!=-1&&somme_yahtzee!=-1){
		fprintf(fichier,"%i%i%i%i%i%i%i",somme_chance,somme_brelan,somme_petite_suite,somme_grande_suite,somme_carre, somme_full,somme_yahtzee);
		scanf("%i%i%i%i%i%i%i",&somme_chance,&somme_brelan,&somme_petite_suite,&somme_grande_suite,&somme_carre,&somme_full,&somme_yahtzee);
	}
	fclose(fichier);
}


int affichier_somme_feuilleScore(){
	int somme_chance;
	int somme_brelan;
	int somme_petite_suite;
	int somme_grande_suite;
	int somme_carre;
	int somme_full;
	int somme_yahtzee;
	FILE*fichier;
	char nom_fic[20];
	printf("donnez le nom du fichier ");
	scanf("%s", nom_fic);
	fichier=fopen("nom_fic","r");
	if(fichier==NULL){
		printf("fichier absent");	
	}
	else{
		fscanf(fichier,"%i%i%i%i%i%i%i",somme_chance,somme_brelan,somme_petite_suite,somme_grande_suite,somme_carre, somme_full,somme_yahtzee);
		while(!feof(fichier)){
			printf("%i%i%i%i%i%i%i",somme_chance,somme_brelan,somme_petite_suite,somme_grande_suite,somme_carre, somme_full,somme_yahtzee);
			fscanf(fichier,"%i%i%i%i%i%i%i",somme_chance,somme_brelan,somme_petite_suite,somme_grande_suite,somme_carre, somme_full,somme_yahtzee);
		}
		fclose(fichier);	
	}
}


int main()
{
	creer_feuilleScore();
	return 0;
}

