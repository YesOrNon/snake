/* jeu.h */
#ifndef __JEU__
#define __JEU__
#include <serpent.h>
#include <pomme.h>
#define TAILLE_SERPENT 2
#define NB_POMMES 4

/* Permet de représenter une situation de jeu */
typedef struct {
    int lignes;     /* Dimension du */
    int colonnes;   /*    monde     */
    Serpent snake;
    Pomme apple; /* Positions des pommes présentes */
    int pom_mangees;
} Monde;

/* Ajoute une nouvelle pomme dans le monde si celle ci est sur une case vide */
void monde_ajouter_pomme(Monde *mon);

/* Renvoie 1 si la pomme que l'on souhaite ajouter est sur le corps du serpent
 * 0 sinon
*/
int pomme_sur_serpent(Tete serp, Case apple);

/* Renvoie 1 si la pomme que l'on souhaite ajouter est une pomme déjà exitante
 * 0 sinon
*/
int pomme_sur_pomme(Pomme list_pomme, Case apple);

/* Renvoie un monde dans une configuration initiale pour le jeu
 * Le quadrillage du monde est de taille nb_lignes * nb_colonnes
 * Le serpent est de taille initiale taille_serpent
 * Le monde contient à chaque instant nb_pommes
 * Les pommes y sont disposés aléatoirement
 * Le serpent se trouve dans sa configuration initiale (serpent_initialiser)
*/
Monde monde_initialiser(int nb_lignes, int nb_colonnes, int taille_serpent, int nb_pommes); 

/* Teste si le serpent du monde va mourir c'est-à-dire
 *  s'il vise une case en dehors du cadrillage
 * ou bien une case de son corps
 * Renvoie 1 s'il va mourir, 0 sinon
*/ 
int monde_est_mort_serpent(Monde mon);

/* Modifie le serpent du monde mob de sorte à le faire avancer suivant sa
 * direction vers la prochaine case
 * Si la tête du serpent arrive sur une case vide du quadrillage, le serpent s'y déplace
 * S'il arrive sur une case occupé par une pomme :
 *      celle -ci est mangée, le serpent grandit en conséquence
 *      et une nouvelle pomme créée aléatoirement est ajouté à mon
*/ 
void monde_evoluer_serpent(Monde *mon);

#endif