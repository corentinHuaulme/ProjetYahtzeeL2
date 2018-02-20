#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "de.h"
#include "combinaison.h"
#include "joueur.h"
#include "menu.c"
#include "feuilleScore.h"


int main(){
	if(jouer()==1){
		int nbJoueur=0,i=0;
		printf("Combien de joueurs ?\n");
		scanf("%i",&nbJoueur);
		joueur_t * tabJoueur[nbJoueur];
		char * blaze = malloc(sizeof(char) * 50);
		for(i=1;i<=nbJoueur;i++){
			printf("Quel est le matricule du joueur %i ?\n",i);
			scanf("%s",blaze);
			tabJoueur[i-1] = joueur_creer(blaze , 0);
			setFeuilleScore(tabJoueur[i-1],creerFeuilleScore());
		}
		int nbTourRestant=nbJoueur*10;
		free(blaze);
		while(nbTourRestant>0){
			printf("Au tour de %s\n",tabJoueur[nbTourRestant%nbJoueur]->nom);
			int nbLancer=3;
			while(nbLancer>0){
				de_t * tabDe[5];
				int i = 0, ind = 0, numDe=0;
				char rep='O';
				de_t * deGarder[5];
				for(i=0;i<5;i++){
					tabDe[i] = creerDe();
					deGarder[i] = creerDe();
				}
				while((rep =='O' || rep == 'o') && nbLancer > 0){
					nbLancer--;
					lancerDe(tabDe,5);
					for(i=0;i<5;i++){
						if(deGarder[i]->nombreFace == 0){
							printf("%d-", tabDe[i]->nombreFace);
						}else{
							printf("%d-", deGarder[i]->nombreFace);
						}
					}
					
					if(nbLancer >0){
						for(i=1;i<=5;i++){
							do{	
								if(deGarder[i-1]->nombreFace == 0){
									printf("\nVoulez-vous garder le De N°%i ?", i);
									scanf(" %c",&rep);
								}else{
									rep='N';
								}
							}while(rep != 'O' && rep != 'N' && rep != 'n' && rep != 'o');
							if(rep == 'O' || rep == 'o'){
								deGarder[i-1]->nombreFace = tabDe[i-1]->nombreFace;
							}
						}
						printf("Voulez vous relancer les dés ? (nombre de lancer restant = %i)[O/N/A (aide)]",nbLancer);
						scanf(" %c",&rep);
					}
				}
				for(i=0;i<5;i++){
					if(deGarder[i]->nombreFace == 0){
						deGarder[i]->nombreFace = tabDe[i]->nombreFace;
					}
				}
				rep = 'n';
				combinaison_t * combi;
				combi = creerCombinaison(deGarder);
				combinaisonPossible(combi);
				if(combi->brelan >=1 && (rep=='N' || rep=='n')){
					printf("Voulez-vous garder le brelan ? [O/N] ");
					scanf(" %c",&rep);
					if(rep=='O' || rep=='o'){
						ajout_brelan(tabJoueur[nbTourRestant%nbJoueur]->feuil, *combi);	
					}
				}if(combi->petite_suite>=1 && (rep=='N' || rep=='n')){
					printf("Voulez-vous garder la petite suite ? [O/N] ");
					scanf(" %c",&rep);
					if(rep=='O' || rep=='o'){
						ajout_petite_suite(tabJoueur[nbTourRestant%nbJoueur]->feuil);	
					}
				}if(combi->grande_suite>=1 && (rep=='N' || rep=='n')){
					printf("Voulez-vous garder la grande suite ? [O/N] ");
					scanf(" %c",&rep);
					if(rep=='O' || rep=='o'){
						ajout_grande_suite(tabJoueur[nbTourRestant%nbJoueur]->feuil);
					}
				}if(combi->full>=1 && (rep=='N' || rep=='n')){
					printf("Voulez-vous garder le full ? [O/N] ");
					scanf(" %c",&rep);
					if(rep=='O' || rep=='o'){
						ajout_full(tabJoueur[nbTourRestant%nbJoueur]->feuil);	
					}
				}if(combi->carre>=1 && (rep=='N' || rep=='n')){
					printf("Voulez-vous garder le carré ? [O/N] ");
					scanf(" %c",&rep);
					if(rep=='O' || rep=='o'){
						ajout_carre(tabJoueur[nbTourRestant%nbJoueur]->feuil, *combi);
					}
				}if(combi->yahtzee>=1 && (rep=='N' || rep=='n')){
					printf("Voulez-vous garder le yahtzee ? [O/N] ");
					scanf(" %c",&rep);
					if(rep=='O' || rep=='o'){
						ajout_yahtzee(tabJoueur[nbTourRestant%nbJoueur]->feuil);	
					}
				}
				printf("SCORE TOTAL : %i",totalPoint(tabJoueur[nbTourRestant%nbJoueur]->feuil));
				tabJoueur[nbTourRestant%nbJoueur]->score = totalPoint(tabJoueur[nbTourRestant%nbJoueur]->feuil);
				printf("%s-%i pts\n",tabJoueur[nbTourRestant%nbJoueur]->nom, tabJoueur[nbTourRestant%nbJoueur]->score);
			}
			nbTourRestant--;
		}
	}
	return 0;


}
