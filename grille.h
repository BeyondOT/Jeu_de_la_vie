/**
 * @file grille.h
 * @author Achraf
 */
#ifndef __GRILLE_H
#define __GRILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// structure grille : nombre de lignes, nombre de colonnes, tableau de tableau de cellules
/**
 * @brief Structure de la grille qui contiernt
 * nbc qui est le nombre de lignes
 * nbl qui est le nombre de colonnes
 * cellules qui est un tableau de tableau
 */
typedef struct {int nbl; int nbc; int** cellules;} grille;

/**
 * @brief Alloue et initialise les cellules de la structure grille
 * @param l nombre de lignes de la grille 
 * @param c nombre de colonnes de la grille
 * @param g la grille que l'on initialise
 */
void alloue_grille (int l, int c, grille* g);

/**
 * @brief Libère une grille
 * 
 * @param g la grille à libèrer 
 */
void libere_grille (grille* g);

/**
 * @brief Alloue et initialise la grille g à partir d'un fichier
 * 
 * @param filename nom du fichier à partir duquel on initialise la grille
 * @param g la grille que l'on initialise
 */
void init_grille_from_file (char * filename, grille* g);

/**
 * @brief Rend vivante la cellule (i,j) de la grille g
 * 
 * @param i numéro de la ligne de la cellule
 * @param j numéro de la colonne de la cellule
 * @param g la grille 
 */
static inline void set_vivante(int i, int j, grille g){g.cellules[i][j] = 1;}

/**
 * @brief Rend morte la cellule (i,j) de la grille g
 * 
 * @param i numéro de la ligne de la cellule
 * @param j numéro de la colonne de la cellule
 * @param g la grille 
 */
static inline void set_morte(int i, int j, grille g){g.cellules[i][j] = 0;}

/**
 * @brief teste si la cellule (i,j) de la grille est vivante
 * 
 * @param i numéro de la ligne de la cellule
 * @param j numéro de la colonne de la cellule
 * @param g la grille 
 */
static inline int est_vivante(int i, int j, grille g){return g.cellules[i][j] == 1;}

// recopie gs dans gd (sans allocation)

/**
 * @brief Recopie la grille gs dans la grille gd (sans allocation)
 * 
 * @param gs grille à copier
 * @param gd grille dans laquelle on copie 
 */
void copie_grille (grille gs, grille gd);

#endif
