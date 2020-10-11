output : main.o jeu.o io.o grille.o
	gcc -o output main.o jeu.o io.o grille.o -lm

main.o : main.c jeu.h io.h grille.h
	gcc -c main.c

jeu.o : jeu.c jeu.h
	gcc -c jeu.c

io.o : io.c io.h
	gcc -c io.c

grille.o : grille.c grille.h
	gcc -c grille.c

clean : 
	rm *.o

dist :
	tar -jcvf prog.tar.xz main.c jeu.c io.c grille.c Makefile Doxyfile
