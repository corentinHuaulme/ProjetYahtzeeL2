#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "de.h"

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

de_t * creerDe(){
	de_t* de = malloc(sizeof(de_t));
	de->nombreFace = 0;
	de->nomImage = "deUn.png";
	return de;
}
