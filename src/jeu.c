/**
 * @file jeu.c
 * @author Achraf 
 */
#include "../include/jeu.h"

int compte_voisins_vivants_c (int i, int j, grille g){
	int v = 0, l=g.nbl, c = g.nbc;

	v += (est_vivante(modulo(i-1,l),modulo(j-1,c),g) && 
			est_viable(modulo(i-1,l), modulo(j-1, c),g));
	v += (est_vivante(modulo(i-1,l),modulo(j,c),g) && 
			est_viable(modulo(i-1,l),modulo(j,c),g)); 
	v += (est_vivante(modulo(i-1,l),modulo(j+1,c),g) && 
			est_viable(modulo(i-1,l),modulo(j+1,c),g)); 
	v += (est_vivante(modulo(i,l),modulo(j-1,c),g) && 
			est_viable(modulo(i,l),modulo(j-1,c),g));
	v += (est_vivante(modulo(i,l),modulo(j+1,c),g) && 
			est_viable(modulo(i,l),modulo(j+1,c),g));
	v += (est_vivante(modulo(i+1,l),modulo(j-1,c),g) 
			&& est_viable(modulo(i+1,l),modulo(j-1,c),g));
	v += (est_vivante(modulo(i+1,l),modulo(j,c),g) 
			&& est_viable(modulo(i+1,l),modulo(j,c),g));
	v += (est_vivante(modulo(i+1,l),modulo(j+1,c),g) 
			&& est_viable(modulo(i+1,l),modulo(j+1,c),g));

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
			(jj >= 0) && (jj < c) &&
			est_viable((ii),(jj),g)
			){
				v+= est_vivante((ii),(jj),g);
			}
		}
	}	
	return v;
}

void evolue (grille *g, grille *gc){
	copie_grille (*g,*gc); // copie temporaire de la grille
	int l=g->nbl, c = g->nbc,v;
	int (*compte_voisins_vivants)(int, int, grille);
	if(g->cycle)compte_voisins_vivants = compte_voisins_vivants_c;
	else compte_voisins_vivants = compte_voisins_vivants_nc;
	
	for (int i=0; i<l; i++){
		for (int j=0; j<c; ++j){
			v = compte_voisins_vivants(i, j, *gc);
			if(est_viable(i,j,*g)){
				if(g->vielliessement){   // Si le vieillissement est activé
					if (est_vivante(i,j,*g)){ 
						if ((v!=2 && v!= 3) || est_vieille(i,j,*g)){ // Si la cellule n'a pas 2 ou 3 voisins ou est vielle
							set_morte(i,j,*g); // elle meurt 
						}else{
							vieillir(i,j,*g); // elle vieillit
						}
					}else{
						if (v==3 && !est_vieille(i,j,*g)){
							set_vivante(i,j,*g);
						}else{
							set_morte(i,j,*g);
						}
					}
				}else{
					if (est_vivante(i,j,*g)){
						if ( v!=2 && v!= 3 ){
							set_morte(i,j,*g);
						}    
					}else{
						if( v==3 ){
							set_vivante(i,j,*g);
						}
					}
				}
			}
		}
	}
	return;
}
