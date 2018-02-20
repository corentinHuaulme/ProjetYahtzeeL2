#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "de.h"
#include "combinaison.h"
#include "joueur.h"
#include "feuilleScore.h"


int main(){
	de_t * tabDe[5];
	int i = 0, ind = 0, numDe=0, nbLancer=3;
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

	rep = 'o';
	combinaison_t * combi;
	combi = creerCombinaison(deGarder);
	combinaisonPossible(combi);/*
	feuille_score_t * feuil;
	feuil = creerFeuilleScore();*/
	printf("\nbrelan : %i\n",combi->brelan);
	printf("petite_suite : %i\n",combi->petite_suite);
	printf("grande_suite : %i\n",combi->grande_suite);
	printf("full : %i\n",combi->full);
	printf("carre : %i\n",combi->carre);
	printf("yahtzee : %i\n",combi->yahtzee);
	if(combi->brelan ==1){
		printf("Voulez-vous garder le brelan ?");
		scanf("%c",&rep);
	}
	joueur_t * joueur = NULL;
	printf( "Test creation du joueur\n" ) ;
  	joueur = joueur_creer( "Andy" , 250 ) ;

  	printf( "Test affichage nom joueur\n" ) ;  
  	joueur->afficher_nom(joueur);				/*affichage du nom du joueur */
  	printf( "\n");
  	
  	printf( "Test affichage score joueur\n" ) ;  
  	joueur->afficher_score(joueur);				/*affichage du score du joueur */
  	printf( "\n");
	return 0;


}
