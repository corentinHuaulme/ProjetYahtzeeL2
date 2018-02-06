#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "de.h"

void lancerDe(de_t * de, int seed){
	srand(seed * time(NULL));
	de->nombreFace = rand() % 6 + 1;
}

de_t * creerDe(){
	de_t* de = malloc(sizeof(de_t));
	de->nombreFace = 0;
	return de;
}
