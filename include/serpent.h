/* serpent.h */
#ifndef __SNAKE__
#define __SNAKE__
#include "pomme.h"

/* Représente les quatres directions cardinales */
typedef enum {
    NORD,
    SUD,
    EST,
    OUEST
} Direction;

/* Permet de représenter un serpent */
typedef struct {
    Direction dir; /* Direction actuelle du serpent */
    Tete head; /* Tête du serpent */
} Serpent;

/* Alloue un espace mémoire pour une case du serpent */
Tete alloue_Tete(int y, int x);

/* Renvoie un serpent dont la tête est située au centre d'un cadrillage
 * de dimensions nb_lignes * nb_colonnes
 * Le serpent doit tenir sur taille cases en comptant sa tête et son corps
*/
Serpent serpent_initialiser(int nb_lignes, int nb_colonnes, int taille);

/* Renvoie la case visée par le serpent serp
 * Il s'agit de la case que la tête de serp va occuper au prochain deplacement
*/
Case serpent_case_visee(Serpent serp);

/* Fcontion récursive permettant de deplacer le serpent */
void deplace_serpent(Tete serp, Case position_serp);

#endif