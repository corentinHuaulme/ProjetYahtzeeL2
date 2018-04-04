/**
* \file de.h
* \author Andy Dinga Corentin Huaulmé Lijuan Jiang
* \brief Header du fichier "de.c" contenant la definition de la structure "de_t"
* \date Mardi 20 Février 2018
*/

#ifndef _PROJET_DE_H
#define _PROJET_DE_H
#include <stdio.h>
#include <stdlib.h>

/**
 \struct de_t
 \brief Représente un dé avec sa face et son image.
**/
typedef struct{
	int nombreFace; ///< Valeur de la face du dé
	char * nomImage;///< Image de dé
}de_t;

void lancerDe(de_t * de[], int nbLancer);
de_t * creerDe();

#endif
