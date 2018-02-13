prog : de.o combinaison.o feuilleScore.o mainDe.o
	gcc mainDe.o de.o combinaison.o feuilleScore.o -o prog

mainDe.o : mainDe.c
	gcc -c mainDe.c -o mainDe.o

de.o : de.c
	gcc -c de.c -o de.o

combinaison.o : combinaison.c
	gcc -c combinaison.c -o combinaison.o

feuilleScore.o : feuilleScore.c
	gcc -c feuilleScore.c -o feuilleScore.o

