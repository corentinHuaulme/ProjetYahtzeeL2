#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "de.h"

void lancerDe(de_t * de[], int nbLancer){
	
	srand(time(0));
	int  i = 0;
	for(i=0;i<nbLancer;i++){
		de[i]->nombreFace = rand() % 6 + 1;
	}
}

de_t * creerDe(){
	de_t* de = malloc(sizeof(de_t));
	de->nombreFace = 0;
	return de;
}
