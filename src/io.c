/*!
 * @file io.c
 *
 * @brief Fonctions de l'interface en mode graphique 
 * 
 * @author Achraf 
 */

#include "../include/io.h"

void affiche_block (int c, int x, int y, int w, int h, cairo_t *cr){
		
		if (c == 0 ) {
			cairo_set_source_rgb (cr, 0.80, 0.80, 0.80);
		} else if (c == -1) {
			cairo_set_source_rgb (cr, 0.2, 0.2, 0.2);	
		} else {
			cairo_set_source_rgb(cr, 0.41, 0.35, 0.80);	
		}

		cairo_rectangle (cr, x+1, y+1, w-2, h-2);
		cairo_fill (cr);
	
		if (c > 0) {
			
			char buff[10];
		
			cairo_set_source_rgb (cr, 0.2, 0.2, 0.2);
			cairo_text_extents_t extents;
			cairo_set_font_size (cr, 14.0);

			cairo_select_font_face (cr, "Serif",
					CAIRO_FONT_SLANT_NORMAL,
					CAIRO_FONT_WEIGHT_BOLD);

			sprintf (buff, "%d", c );
			cairo_text_extents (cr, buff, &extents);
			int xx = (x+(w/2))-(extents.width/2 + extents.x_bearing);
			int yy = (y+(h/2))-(extents.height/2 + extents.y_bearing);
		
			cairo_move_to (cr, xx, yy);
			cairo_show_text (cr, buff);

		}

		cairo_set_line_width (cr, 2);
		cairo_set_source_rgb (cr, 0.2, 0.2, 0.2);
		
		cairo_move_to (cr, x, y);
                cairo_move_to (cr, (x+w), y);
		cairo_line_to (cr, (x+w), (y+h));
		cairo_line_to (cr, x, (y+h));
		cairo_move_to (cr, x, y);
		cairo_stroke (cr);

	return;
}

void affiche_grille (grille g, cairo_t *cr){
	int i, j, l=g.nbl, c=g.nbc;

	int x = 260,
	    y = 110;
	
	int block_w = (500 - 20)/c;
	int block_h = (500 - 20)/l;

	cairo_move_to (cr, x, y);

	for (i=0; i<c; i++) {
		for(j=0; j<l; j++){
			affiche_block(g.cellules[j][i],x+(i * block_w),y+(j * block_h),block_w,block_h,cr);
		}
	}
	
	cairo_set_line_width (cr, 2);
	cairo_set_source_rgb (cr, 0.2, 0.2, 0.2);
        cairo_move_to (cr, x, y);
	cairo_line_to (cr, x+(c*block_w), y);
	cairo_move_to (cr, x, y);
	cairo_line_to (cr, x, y+(l*block_h));
	
	cairo_stroke (cr);

	return;
}


void affiche_param (cairo_t *cr, grille *g){

	const char *utf8;
	char buff[10];
    double x,y;

	cairo_set_line_width (cr, 2);
	cairo_set_source_rgb (cr, 0.67, 0.84, 0.90);
	cairo_rectangle (cr, 0, 0, 250, 600);
	cairo_fill (cr);

	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_text_extents_t extents;
    cairo_set_font_size (cr, 20);
        cairo_select_font_face (cr, "Serif",
		CAIRO_FONT_SLANT_NORMAL,
		CAIRO_FONT_WEIGHT_BOLD);


	utf8 = "Paramètres";
	
	cairo_text_extents (cr, utf8, &extents);
	x = 125.0-(extents.width/2 + extents.x_bearing);
	y = 50.0-(extents.height/2 + extents.y_bearing);
	cairo_move_to (cr, x, y);
	cairo_show_text (cr, utf8);
	

	cairo_set_font_size (cr, 15.0);
	cairo_select_font_face (cr, "Serif",
		CAIRO_FONT_SLANT_NORMAL,
		CAIRO_FONT_WEIGHT_NORMAL);

	utf8 = "Temps d'évolution : ";
	cairo_move_to (cr, 10, 100);
	cairo_show_text (cr, utf8);

	cairo_move_to (cr, 160, 100);
	sprintf (buff, "%d", g->tpsEvolution);
	cairo_show_text (cr, buff);

	cairo_move_to(cr, 10, 125);
  	cairo_show_text(cr, "- - - - - - - - - - - - - - - - - - - - - - - -");

	utf8 = "Mode Cyclique :";
	cairo_move_to (cr, 10, 150);
	cairo_show_text (cr, utf8);

	cairo_move_to (cr, 160, 150);
	sprintf(buff, "%s", (g->cycle) ? "Actif":"Inactif");
	cairo_show_text (cr, buff);

	utf8 = "(Appuyer sur 'c' pour changer)";
	cairo_move_to (cr, 10, 175);
	cairo_show_text (cr, utf8);

	utf8 = "Vielliessement :";
	cairo_move_to (cr, 10, 225);
	cairo_show_text (cr, utf8);

	cairo_move_to (cr, 160, 225);
	sprintf(buff, "%s", (g->vielliessement) ? "Actif":"Inactif");
	cairo_show_text (cr, buff);

	utf8 = "(Appuyer sur 'v' pour changer)";
	cairo_move_to (cr, 10, 250);
	cairo_show_text (cr, utf8);

	utf8 = "Oscillation :";
	cairo_move_to (cr, 10, 300);
	cairo_show_text (cr, utf8);

	cairo_move_to (cr, 160, 300);
	sprintf(buff, "%s", (g->oscillation) ? "Oui":"Non");
	cairo_show_text (cr, buff);

	utf8 = "(Appuyer sur 'o' pour changer)";
	cairo_move_to (cr, 10, 325);
	cairo_show_text (cr, utf8);

    if (g->oscillation){

        utf8 = "Période :";
		cairo_move_to (cr, 10, 375);
		cairo_show_text (cr, utf8);
	
		cairo_move_to (cr, 160, 375);
		sprintf(buff, "%d", (g->oscillation-1));
		cairo_show_text (cr, buff);
		

		utf8 = "Correspondance :";
		cairo_move_to (cr, 10, 425);
		cairo_show_text (cr, utf8);
	
		cairo_move_to (cr, 160, 425);
		sprintf(buff, "%s", ((g->oscillation-1) ? "Non":"Oui"));
		cairo_show_text (cr, buff);	
	}

	cairo_move_to(cr, 10, 450);
  	cairo_show_text(cr, "- - - - - - - - - - - - - - - - - - - - - - - - ");

	utf8 = "Pour faire évoluer vite 'b'.";
			cairo_move_to (cr, 10, 475);
			cairo_show_text (cr, utf8);

	utf8 = "Pour changer la grille 'n'.";
		cairo_move_to (cr, 10, 525);
		cairo_show_text (cr, utf8);
	
	utf8 = "Pour quitter : 'clic droit'";
		cairo_move_to (cr, 10, 575);
		cairo_show_text (cr, utf8);
	
	return; 
}


void affiche_intro (cairo_t *cr){

    cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_text_extents_t extents;

	const char *utf8 = "JEU DE LA VIE";
	double x,y;

	cairo_select_font_face (cr, "Courier",
		CAIRO_FONT_SLANT_NORMAL,
		CAIRO_FONT_WEIGHT_NORMAL);

	cairo_set_font_size (cr, 50);
	cairo_text_extents (cr, utf8, &extents);
	x = 500.0-(extents.width/2 + extents.x_bearing);
	y = 50.0-(extents.height/2 + extents.y_bearing);

	cairo_move_to (cr, x, y);
	cairo_show_text (cr, utf8);

	return;
}


int cairo_event_listener(cairo_surface_t *sfc, int block){
   	char keybuf[8];
      	KeySym key;
      	XEvent e;
    	for (;;){
		if (block || XPending(cairo_xlib_surface_get_display(sfc))){
			XNextEvent(cairo_xlib_surface_get_display(sfc), &e);
		} else {
			return 0;
		}

		switch (e.type){
			case ButtonPress:
		       		return -e.xbutton.button;
			case KeyPress:
		      		XLookupString(&e.xkey, keybuf, sizeof(keybuf), &key, NULL);
		      		return key;
			default:
				break;
		}
	}
}


cairo_surface_t *cairo_surface_create(int *x, int *y){

   	Display *dsp;
   	Drawable da;
   	
	int screen;
   	cairo_surface_t *sfc;
	       
   	if ((dsp = XOpenDisplay(NULL)) == NULL){
		exit(1);
	}
	
	screen = DefaultScreen(dsp);

      	da = XCreateSimpleWindow(dsp, DefaultRootWindow(dsp), 0, 0, *x, *y, 0, 0, 0xffffff);
        XSelectInput(dsp, da, ButtonPressMask | KeyPressMask);
	XMapWindow(dsp, da);

	sfc = cairo_xlib_surface_create(dsp, da, DefaultVisual(dsp, screen), *x, *y);
	cairo_xlib_surface_set_size(sfc, *x, *y);


   	return sfc;
}



void cairo_suface_close(cairo_surface_t *sfc){

	Display *dsp = cairo_xlib_surface_get_display(sfc);

	cairo_surface_destroy(sfc);
	XCloseDisplay(dsp);

	return;
}


void debut_jeu (grille *g, grille *gc,  grille *go){

	cairo_surface_t *sfc; 	// surface cairo
	cairo_t *ctx; // contexte 
	
	int x = 750, 
	    y = 600;				
	struct timespec ts = {0, 5000000};
	
	int c;

	sfc = cairo_surface_create(&x, &y);
  	ctx = cairo_create(sfc);

	
	do {
		c = cairo_event_listener(sfc, 0);

     	switch (c){	  
			// La lettre c
			case 0x0063 : {  
				if(g->cycle){
					g->cycle = 0;
				}else{
				    g->cycle = 1;
				}                
				affiche_param(ctx, g);
				break;
			}

			// La lettre n
			case 0x006E : {  
				cairo_destroy(ctx);
				cairo_suface_close(sfc);
				char fg[23] = "./grilles/grille";
				char nb[2];
 				g->tpsEvolution = 0;
				g->cycle = 0;
				g->oscillation = 0;
				g->vielliessement = 0;

				printf("Entrez le numéro de la nouvelle grille à charger:\n");
				scanf(" %s", nb);
				while( getchar() != '\n' );
				strcat (fg, nb);
				strcat (fg, ".txt");
				libere_grille(g);
				libere_grille(gc);
				libere_grille(go);
				init_grille_from_file(fg,g);
				alloue_grille (g->nbl, g->nbc, gc);
				alloue_grille (g->nbl, g->nbc, go);
				debut_jeu(g,gc,go);
				break;
			}

			// La lettre o
			case 0x006f :{
				if (g->oscillation) {
					g->oscillation = 0;
					libere_grille(go);
					alloue_grille(g->nbl,g->nbc,go);
				}else{
					g->oscillation = 1;
					copie_grille(*g, *go);
				}          
				affiche_param(ctx, g);
				break;
			}

			// La lettre v
			case 0x0076 :{
				if(!g->vielliessement){
					g->vielliessement=1;
				}else { 
					g->vielliessement=0;
                }
				affiche_param(ctx, g);

		        	break;
			}

			// La lettre b
			case 0x0062 :{
				g->tpsEvolution++;
				evolue(g,gc);
				if (g->oscillation){
					if(meme_grille(g,go)){
						affiche_param(ctx, g);
						affiche_grille(*g, ctx);
						g->oscillation=0;
					}
					affiche_param(ctx, g);
                    affiche_grille(*g, ctx);
				    g->oscillation++;
				}
				break;
			}

			// Clic gauche
 			case -1 : {
				g->tpsEvolution++;
				evolue(g,gc);
				if (g->oscillation){
			        	if(meme_grille(g,go)){
						affiche_param(ctx, g);
                                		affiche_grille(*g, ctx);
			                	g->oscillation=0;
			        	}
					affiche_param(ctx, g);
                                	affiche_grille(*g, ctx);
				        g->oscillation++;
				}
				break;
			}

			// Clic droit
			case +1: {
				libere_grille(g);
				libere_grille(gc);
				libere_grille(go);
				break;
			}

			default: {
				break;
			}
			
    }
	affiche_intro(ctx);
       
	affiche_param(ctx, g);

	affiche_grille(*g, ctx);
	cairo_surface_flush(sfc);
    	nanosleep(&ts, NULL);
	
	} while ( c != -3 );

	cairo_destroy(ctx);

	cairo_suface_close(sfc);

	return;	
}