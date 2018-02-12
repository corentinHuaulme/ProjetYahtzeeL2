#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "de.h"
#include "combinaison.h"

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
			printf("Voulez vous relancer les dés ? (nombre de lancer restant = %i)[O/N]",nbLancer);
			scanf(" %c",&rep);
		}
	}

	combinaison_t * combi;
	combi = creerCombinaison(deGarder);
	combinaisonPossible(combi);
	printf("brelan : %i",combi->brelan);
	printf("petite_suite : %i",combi->petite_suite);
	printf("grande_suite : %i",combi->grande_suite);
	printf("full : %i",combi->full);
	printf("carre : %i",combi->carre);
	printf("yahtzee : %i",combi->yahtzee);
	return 0;


}
