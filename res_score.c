#include<stdio.h>
#include<stdlib.h>
#include"feuilleScore.h"


feuille_score_t * creer_feuilleScore(){
	
	feuille_score_t * feuille = malloc(sizeof(feuille_score_t));
	feuille->totalUn = 0;
	feuille->totalDeux = 0;
	feuille->totalTrois = 0;
	feuille->totalQuatre = 0;
	feuille->totalCinq = 0;
	feuille->totalSix = 0;
	feuille->totalBrelan = 0;
	feuille->totalFull = 0;
	feuille->totalPetiteSuite = 0;
	feuille->totalGrandeSuite = 0;
	feuille->totalCarre = 0;
	feuille->totalChance = 0;
	feuille->totalYahtzee = 0;
	
	return feuille;
}

int sauvegarder_feuilleScore(feuille_score_t * feuille){
	FILE*fic;
	char nom_fic[20];
	printf("donnez le nom du fichier  ");
	scanf("%s",nom_fic);
	
	fic=fopen("res","w");

	fprintf(fic,"%i\n",feuille->totalUn);
	fprintf(fic,"%i\n",feuille->totalDeux);
	fprintf(fic,"%i\n",feuille->totalTrois);
	fprintf(fic,"%i\n",feuille-> totalQuatre);
	fprintf(fic,"%i\n",feuille->totalCinq);
	fprintf(fic,"%i\n",feuille->totalSix);
	fprintf(fic,"%i\n",feuille->totalFull);
	fprintf(fic,"%i\n",feuille->totalBrelan);
	fprintf(fic,"%i\n",feuille->totalCarre);
	fprintf(fic,"%i\n",feuille->totalPetiteSuite);
	fprintf(fic,"%i\n",feuille->totalGrandeSuite);
	fprintf(fic,"%i\n",feuille->totalChance);
	fprintf(fic,"%i\n",feuille->totalYahtzee);

	
	fclose(fic);
	return 0;
}


feuille_score_t* charger_feuilleScore(){
	feuille_score_t * feuille = malloc(sizeof(feuille_score_t));
	feuille->totalUn = 0;
	feuille->totalDeux = 0;
	feuille->totalTrois = 0;
	feuille->totalQuatre = 0;
	feuille->totalCinq = 0;
	feuille->totalSix = 0;
	feuille->totalBrelan = 0;
	feuille->totalFull = 0;
	feuille->totalPetiteSuite = 0;
	feuille->totalGrandeSuite = 0;
	feuille->totalCarre = 0;
	feuille->totalChance = 0;
	feuille->totalYahtzee = 0;
	FILE*fic;
	char nom_fic[20];
	printf("donnez le nom du fichier ");
	scanf("%s", nom_fic);
	fic=fopen("res","r");
	if(fic==NULL){
		printf("fichier absent");	
	}
	else{
		fscanf(fic,"%i",&feuille->totalUn);
		fscanf(fic,"%i",&feuille->totalDeux);
		fscanf(fic,"%i",&feuille->totalTrois);
		fscanf(fic,"%i",&feuille->totalQuatre);
		fscanf(fic,"%i",&feuille->totalCinq);
		fscanf(fic,"%i",&feuille->totalSix);
		fscanf(fic,"%i",&feuille->totalFull);
		fscanf(fic,"%i",&feuille->totalBrelan);
		fscanf(fic,"%i",&feuille->totalCarre);
		fscanf(fic,"%i",&feuille->totalPetiteSuite);
		fscanf(fic,"%i",&feuille->totalGrandeSuite);
		fscanf(fic,"%i",&feuille->totalChance);
		fscanf(fic,"%i",&feuille->totalYahtzee);
		
		fclose(fic);	
	}
	return feuille;
}

int afficher_feuilleScore(feuille_score_t * feuille){
	FILE*fic;

	fprintf(fic,"%i\n",feuille->totalUn);
	fprintf(fic,"%i\n",feuille->totalDeux);
	fprintf(fic,"%i\n",feuille->totalTrois);
	fprintf(fic,"%i\n",feuille-> totalQuatre);
	fprintf(fic,"%i\n",feuille->totalCinq);
	fprintf(fic,"%i\n",feuille->totalSix);
	fprintf(fic,"%i\n",feuille->totalFull);
	fprintf(fic,"%i\n",feuille->totalBrelan);
	fprintf(fic,"%i\n",feuille->totalCarre);
	fprintf(fic,"%i\n",feuille->totalPetiteSuite);
	fprintf(fic,"%i\n",feuille->totalGrandeSuite);
	fprintf(fic,"%i\n",feuille->totalChance);
	fprintf(fic,"%i\n",feuille->totalYahtzee);

	
	return 0;
}


int main()
{
	creer_feuilleScore();
	sauvegarder_feuilleScore();
	charger_feuilleScore();
	afficher_feuilleScore();
	return 0;
}
