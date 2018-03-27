/**
* \file de.c
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Contient toutes les fonctions permettant de manipuler un de_t
* \date Mardi 20 Février 2018
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "de.h"


/**
 \fn void lancerDe(de_t * de[], int nbLancer)
 \brief Permet de lancer nbLancer de_t du tableau de.
 \param de_t * de[] pour le tableau de pointeur de de_t à lancer.
 \param int nbLancer pour le nombre de de_t à lancer.
**/
void lancerDe(de_t * de[], int nbLancer){
	
	srand(time(0));
	int  i = 0;
	for(i=0;i<nbLancer;i++){
		de[i]->nombreFace = rand() % 6 + 1;
		switch(de[i]->nombreFace){
			case 1 :
				de[i]->nomImage="deUn.png";
				break;
			case 2 :
				de[i]->nomImage="DeDeux.png";
				break;
			case 3 :
				de[i]->nomImage="DeTrois.png";
				break;
			case 4 :
				de[i]->nomImage="DeQuatre.png";
				break;
			case 5 :
				de[i]->nomImage="DeCinq.png";
				break;
			case 6 :
				de[i]->nomImage="DeSix.png";
				break;
		}
	}
}
/**
 \fn de_t * creerDe()
 \brief Créer un de_t vierge.
 \return Le de_t vierge créer.
**/
de_t * creerDe(){
	de_t* de = malloc(sizeof(de_t));
	de->nombreFace = 0;
	de->nomImage = "deUn.png";
	return de;
}
