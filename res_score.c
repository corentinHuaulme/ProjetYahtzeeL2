#include<stdio.h>
#include<stdlib.h>
#include"feuilleScore.h"
#include"res_score.h"

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
	feuille_score_t * feuille = creerFeuilleScore();
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
	fic=fopen("res","r");
	fscanf(fic,"%i\n",feuille->totalUn);
	fscanf(fic,"%i\n",feuille->totalDeux);
	fscanf(fic,"%i\n",feuille->totalTrois);
	fscanf(fic,"%i\n",feuille-> totalQuatre);
	fscanf(fic,"%i\n",feuille->totalCinq);
	fscanf(fic,"%i\n",feuille->totalSix);
	fscanf(fic,"%i\n",feuille->totalFull);
	fscanf(fic,"%i\n",feuille->totalBrelan);
	fscanf(fic,"%i\n",feuille->totalCarre);
	fscanf(fic,"%i\n",feuille->totalPetiteSuite);
	fscanf(fic,"%i\n",feuille->totalGrandeSuite);
	fscanf(fic,"%i\n",feuille->totalChance);
	fscanf(fic,"%i\n",feuille->totalYahtzee);

	
	return 0;
}


int main()
{
	feuille_score_t * f = creerFeuilleScore();
	sauvegarder_feuilleScore(f);
	charger_feuilleScore(f);
	afficher_feuilleScore(f);
	return 0;
}
