#ifndef _PROJET_DE_H
#define _PROJET_DE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct de_s{
	int nombreFace;
	char * nomImage;
}de_t;

void lancerDe(de_t * de[], int nbLancer);
de_t * creerDe();

#endif
