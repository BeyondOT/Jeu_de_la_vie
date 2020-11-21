/**
 * @file io.h
 * @author Achraf 
 */

#include <X11/Xlib.h>

#include <X11/Xutil.h>
#include <cairo.h>
#include <cairo-xlib.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "grille.h"
#include "jeu.h"

/** 
 * @brief affiche une case sur l'interface cairo
 * 
 * @param c Valeur de la cellule
 * @param x Position x de la cellule
 * @param y Position y de la cellule
 * @param w Largeur de la cellule
 * @param h Hauteur de la cellule
 * @param cr Pointeur vers interface cairo
 */
void affiche_block (int c, int x, int y, int w, int h, cairo_t *cr);


/**
 * @brief affiche le contenu de la grille dans l'interface cairo
 * 
 * @param g grille à afficher
 * @param cr Pointeur vers interface cairo
 * 
 */
void affiche_grille (grille g, cairo_t *cr);


/**
 * @brief affiche les parametres dans l'interface cairo
 * 
 * @param cr Pointeur vers interface cairo
 * @param g Pointeur vers la grille g
 */
void affiche_param (cairo_t *cr, grille *g);


/**
 * @brief Affiche l'introduction du jeu
 * 
 * @param cr Pointeur vers l'interface cairo
 */
void affiche_intro (cairo_t *cr);


/**
 * @brief Ouvre une fenêtre et crée une surface cairo dedans
 * 
 * @param x : Pointeur vers la largeur de la fenêtre
 * @param y : Pointeur vers la hauteur de la fenêtre
 */
cairo_surface_t *cairo_surface_create (int *x, int *y);


/**
 * @brief Fermeture de la surface cairo
 * 
 * @param sfc : Surface cairo à fermer
 */
void cairo_surface_close (cairo_surface_t *sfc);


/**
 * @brief Teste la presence d'un evenement utilisateur
 * 
 * @param sfc Pointeur vers surface cairo
 * @param block Marqueur de blocage
 */
int cairo_event_listener (cairo_surface_t *sfc, int block);


/**
 * @brief Lance la partie
 * 
 * @param g Grille a utiliser
 * @param gc Copie de grille à utiliser pour evolution
 * @param go Copie de grille à utiliser pour oscillation
 */
void debut_jeu (grille *g, grille *gc, grille *go);
