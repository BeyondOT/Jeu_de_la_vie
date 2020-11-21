/**
 * @file jeu.h
 * @author Achraf 
 */
#ifndef __JEU_H
#define __JEU_H

#include "grille.h"

/**
 * @brief modulo modifié pour traiter correctement les bords i=0 et j=0
 * dans le calcul des voisins avec bords cycliques
 * @param i nombre i
 * @param m nombre m
 * @return int 
 */
static inline int modulo(int i, int m) {return (i+m)%m;}

/**
 * @brief compte le nombre de voisins vivants de la cellule (i,j)
 * les bords sont non-cycliques.
 * 
 * @param i numéro de la ligne de la cellule 
 * @param j numéro de la collone de la cellulle
 * @param g la grille
 * @return int 
 */
int compte_voisins_vivants_nc (int i, int j, grille g);

/**
 * @brief compte le nombre de voisins vivants de la cellule (i,j)
 * les bords sont cycliques.
 * 
 * @param i numéro de la ligne de la cellule 
 * @param j numéro de la collone de la cellulle
 * @param g la grille
 * @return int 
 */
int compte_voisins_vivants_c (int i, int j, grille g);

/**
 * @brief fait évoluer la grille g d'un pas dans le temps
 * 
 * @param g la grille
 * @param gc la copie de la grille
 */
void evolue (grille *g, grille *gc);

int meme_grille (grille *g, grille *go);

#endif
