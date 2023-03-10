/* pomme.h */
#ifndef __POMME__
#define __POMME__

/* Représente les coordonnées d'une case du quadrillage */
typedef struct {
    int y; /* Ordonnée */
    int x; /* Abscisse */
} Case;

typedef struct _liste_{
    Case position;
    struct _liste_ * suivant;
} Liste_Cases, *Tete;

/* Liste simplement chainée représentant les coordonnées de pommes */
typedef struct _pomme_{
    Case position; /* Coordonnée d'une case contenant une pomme */
    struct _pomme_ * suivant; /* Pointeur vers une autre pomme */
} Pomme;

/* Renvoie une pomme créée aléatoirement de qu'elle tienne
 * dans un quadrillage de dimension nb_lignes * nb_colonnes
*/
Pomme * pomme_aleatoire(int nb_lignes, int nb_colonnes);

/* Creer une pomme */
Pomme * alloue_pomme(int y, int x);

#endif