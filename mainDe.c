#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "de.h"

int main(){
	de_t * tabDe[5];
	int i = 0, ind = 0;
	char strDeGarder[9];
	int deGarder[5];
	for(i=0;i<5;i++){
		tabDe[i] = creerDe();
	}
	lancerDe(tabDe,5);
	for(i=0;i<5;i++){
		printf("%d-", tabDe[i]->nombreFace);
	}
	printf("\nQuels dés voulez vous garder ?");
	scanf("%s",strDeGarder);
	printf("%i\n", strlen(strDeGarder));
	for(i=0;i<strlen(strDeGarder);i++){
		if(strDeGarder[i] == ' '){
			printf("ALLO ?");
			deGarder[ind] = strDeGarder[i+1] - '0';
			ind = ind + 1;
		}
	}
	printf("%d",ind);
	for(i=0;i<ind;i++){
		printf("%c\t", deGarder[i]);
	}
	return 0;
}
