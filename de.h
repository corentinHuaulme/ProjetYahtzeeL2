#ifndef _PROJET_DE_H
#define _PROJET_DE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct de_s{
	int nombreFace;
}de_t;

void lancerDe(de_t * de, int seed);
de_t * creerDe();

#endif
