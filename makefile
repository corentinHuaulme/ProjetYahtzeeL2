prog : de.o combinaison.o mainDe.o
	gcc mainDe.o de.o combinaison.o -o prog

mainDe.o : mainDe.c
	gcc -c mainDe.c -o mainDe.o -I./

de.o : de.c
	gcc -c de.c -o de.o -I./

combinaison.o : combinaison.c
	gcc -c combinaison.c -o combinaison.o -I./

