#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jouer(){ 															/*lancement de la partie*/

	srand(time(NULL));
	int choix;

// Affichage du menu et saisie du choix //
do
	{
	
		printf("\n\n\n\n\n\n\n\n\n");
		printf("	   #   #   ###     #   #   #####  #####  #####  #####  \n");
		printf("	   #   #  #   #    #   #     #        #  #      #      \n");
		printf("	     #    #   #    #   #     #       #   #      #      \n");
		printf("	     #    #####    #####     #      #    ####   ####   \n");
		printf("	     #    #   #    #   #     #     #     #      #      \n");
		printf("	     #    #   #    #   #     #    #      #      #      \n");
		printf("	     #    #   #    #   #     #   ######  #####  #####  \n");
		printf("\n		+---------------------------------------+\n");
		printf("		|					|");
		printf("\n		|		Menu :			|\n");
		printf("		|					|\n");
		printf("		|	1 - Lancer une partie		|\n");
		printf("		|	2 - Regles du jeu     		|\n");
		printf("		|	3 - Quitter           		|\n");
		printf("		|					|");
        printf("\n		+---------------------------------------+\n");
        printf("Votre choix : ");
		scanf("%i",&choix);

	switch(choix){	
			case 1: return 1;	break;
			case 2: printf("\n	Regles du jeu de mots meles: \n");
					printf("\n	Le Yams se joue avec 5 dés et se finit une fois toutes les cases de \n	la fiche de score remplies.");
					printf("\n	Chaque joueur joue tout à tour et dispose de 3 lancers à chaque coup.");
					printf("\n	L’objectif étant de réaliser des combinaisons qui rapportent des points.");
					printf("\n	Le joueur a le choix de reprendre tous ou une partie des dés à chaque \n	lancé, selon son gré, pour tenter d’obtenir la combinaison voulue. ");
                    printf("\n	A chaque tour, le joueur doit obligatoirement inscrire son score dans\n 	une des cases de la feuille de marque que ce soit par un X ou par les points qu’il a obtenu. \n"); break;
			case 3: return 3;   break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}
	while(choix!=3);
	printf("Au revoir, et merci d'avoir joue !\n");
	printf("\n");
	return EXIT_SUCCESS;
}


	