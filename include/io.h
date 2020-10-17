/**
 * @file io.h
 * @author Achraf 
 */
#ifndef __IO_H
#define __IO_H

#include <stdio.h>

#include "grille.h"
#include "jeu.h"

/**
 * @brief affiche un trait horizontale c foiss
 * 
 * @param c nombre de traits à afficher
 */
void affiche_trait (int c);

/**
 * @brief affiche une ligne de la grille c fois
 * 
 * @param c nombre de lignes à afficher
 * @param ligne ligne à afficher
 */
void affiche_ligne (int c, int* ligne);

/**
 * @brief affiche la grille g
 * 
 * @param g la grille à afficher
 */
void affiche_grille (grille g);

/**
 * @brief efface la grille
 * 
 */
void efface_grille ();

/**
 * @brief debute le jeu
 * 
 * @param g la grille
 * @param gc la copie de la grille
 */
void debut_jeu(grille *g, grille *gc);

#endif
