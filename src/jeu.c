/**
 * @file jeu.c
 * @author Achraf 
 */
#include "jeu.h"

int compte_voisins_vivants_c (int i, int j, grille g){
	int v = 0, l=g.nbl, c = g.nbc;
	v+= est_vivante(modulo(i-1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j+1,c),g);

	return v; 
}

int compte_voisins_vivants_nc(int i, int j, grille g){
	int v = 0, l=g.nbl, c=g.nbc;
    int k, h;
	for(k=-1; k<=1; k++){
		for(h=-1; h<=1; h++) {
			int ii=i+k;
			int jj=j+h;
			if ( (!((k == 0) && (h == 0))) &&
			(ii >= 0) && (ii < l) &&
			(jj >= 0) && (jj < c)
			){
				v+= est_vivante((ii),(jj),g);
			}
		}
	}	
	return v;
}

void evolue (grille *g, grille *gc){
	copie_grille (*g,*gc); // copie temporaire de la grille
	int i,j,l=g->nbl, c = g->nbc,v;
	int (*compte_voisins_vivants)(int, int, grille);
	if(cyclique)compte_voisins_vivants = compte_voisins_vivants_c;
	else compte_voisins_vivants = compte_voisins_vivants_nc;
	
	for (i=0; i<l; i++)
	{
		for (j=0; j<c; ++j)
		{
			v = compte_voisins_vivants(i, j, *gc);
			if (est_vivante(i,j,*g)) 
			{ // evolution d'une cellule vivante
				if ( v!=2 && v!= 3 ) set_morte(i,j,*g);
			}
			else 
			{ // evolution d'une cellule morte
				if ( v==3 ) set_vivante(i,j,*g);
			}
		}
	}
	return;
}
