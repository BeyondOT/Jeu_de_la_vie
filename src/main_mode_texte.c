/**
 * @file main_mode_texte.c
 * @brief fichier principal lors du lancement en mode texte.
 * 
 * @author Achraf 
 */
#include <stdio.h>

#include "../include/grille.h"
#include "../include/io_mode_texte.h"
#include "../include/jeu.h"

int main (int argc, char ** argv) {
	
	if (argc != 2 )
	{
		printf("usage : main <fichier grille>");
		return 1;
	}

	grille g, gc;
	init_grille_from_file(argv[1],&g);
	alloue_grille (g.nbl, g.nbc, &gc);
	affiche_grille(g);
	debut_jeu(&g, &gc);

	libere_grille(&g);
	libere_grille(&gc);
	return 0;
}