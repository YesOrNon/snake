/* graphique.h */
#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

#include "jeu.h"
#include <ncurses.h>
#define YCASE 4
#define XCASE 6

/* Permet d'afficher une case */
void dessiner_case(int y, int x, int couleur);

/* Affiche le quadrillage du monde */
void interface_afficher_quadrillage(Monde mon);

/* Affiche la pomme donnée en paramètre */
void interface_afficher_pomme(Pomme pom);

/* Affiche le serpent */
void interface_afficher_serpent(Serpent ser);

/* Affiche le monde et le nombre de pommes mangées */
void interface_afficher_monde(Monde mon);

#endif