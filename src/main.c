/**
 * @file main.c
 * @brief fichier principal lors du lancement en mode graphique. 
 * 
 * @author Achraf 
 */

#include <stdio.h>

#include "../include/grille.h"
#include "../include/io.h"
#include "../include/jeu.h"


int main (int argc, char ** argv) {

	if (argc != 2 )
	{
		printf("usage : main <fichier grille>\n");
		return 1;
	}

	// declaration, initialisation et affichage des grilles requises
	grille g, gc, go;
	init_grille_from_file(argv[1],&g);
	alloue_grille (g.nbl, g.nbc, &gc);
	alloue_grille (g.nbl, g.nbc, &go);

	// Lancement du jeu
	debut_jeu(&g, &gc, &go);

	// libere la memoire apres la fin du jeu
	libere_grille(&g);
	libere_grille(&gc);
	libere_grille(&go);

	return 0;
}

