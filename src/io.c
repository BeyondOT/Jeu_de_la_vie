/**
 * @file io.c
 * @author Achraf
 */
#include "../include/io.h"

void affiche_trait (int c){
	int i;
	for (i=0; i<c; ++i) printf ("|---");
	printf("|\n");
	return;
}

void affiche_ligne (int c, int* ligne){
	for (int j=0; j<c; j++){
		if (ligne[j] == 0 ){
			printf ("|   ");
		}else if(ligne[j] == -1){
			printf ("| X ");
		}else{
			printf ("| %d ", ligne[j]);
		}
	}
	printf("|\n");
	return;
}

void affiche_grille (grille g){
	int i, l=g.nbl, c=g.nbc;

	printf("\nVoisinage g->cycle : ");
    if (!g.cycle){
        printf("désactivé\n"); 
    }
    else {
        printf("activé\n");
    }

    printf("\nVieillissement : ");  

    if (!g.vielliessement){
        printf("désactivé\n"); 
    }
    else {
        printf("activé\n"); 
    }
    printf("\nTemps d'évolution de la grille : %d \n", g.tpsEvolution);
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
				g->tpsEvolution ++;
				evolue(g,gc);
				system("clear");
				affiche_grille(*g);
				
				break;
			}
			case 'v':{
				if(!g->vielliessement) g->vielliessement = 1;
				else g->vielliessement = 0;
				break;
			}
			case 'c' :
			{
				if(!g->cycle) g->cycle = 1;
				else g->cycle = 0;
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
				g->tpsEvolution = 1;

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
