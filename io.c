/**
 * @file io.c
 * @author Achraf
 */
#include "io.h"

void affiche_trait (int c){
	int i;
	for (i=0; i<c; ++i) printf ("|---");
	printf("|\n");
	return;
}

void affiche_ligne (int c, int* ligne){
	int i;
	for (i=0; i<c; ++i) 
		if (ligne[i] == 0 ) printf ("|   "); else printf ("| O ");
	printf("|\n");
	return;
}

void affiche_grille (grille g){
	int i, l=g.nbl, c=g.nbc, t=g.temps, cycle=g.cycle, v=g.vieille;
	printf("\nVoisinage cyclique : ");

    if (cycle == 0){
        printf("désactivé\n"); 
    }
    else {
        printf("activé\n");
    }

    printf("\nVieillissement : ");  

    if (v == 0){
        printf("désactivé\n"); 
    }
    else {
        printf("activé\n"); 
    }
    printf("\nTemps d'évolution de la grille : %d \n", t);
	printf("\n");
	affiche_trait(c);
	for (i=0; i<l; ++i) {
		affiche_ligne(c, g.cellules[i]);
		affiche_trait(c);
	}	
	printf("\n"); 
	return;
}

void efface_grille (){
	printf("\e[H\e[2J");
}

void debut_jeu(grille *g, grille *gc){
	char c = getchar(); 
	while (c != 'q') // touche 'q' pour quitter
	{ 
		switch (c) {
			case '\n' : 
			{ // touche "entree" pour évoluer
				evolue(g,gc);
				system("clear");
				affiche_grille(*g);
				g->temps += 1;
				break;
			}
			case 'n' : 
			{
				char filename[FILENAME_MAX];
				scanf(" %s", filename);
				libere_grille(g);
				libere_grille(gc);
				init_grille_from_file(filename, g);
				alloue_grille(g->nbl, g->nbc, gc);

				break;
			}
			default : 
			{ // touche non traitée
				printf("\n\e[1A");
				break;
			}
		}
		c = getchar(); 
	}
	return;	
}
