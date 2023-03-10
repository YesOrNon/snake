/* Auteur : OUMAKHLOUF Selym | LUSTGARTEN Leo
 * Creation : 08/03/2023
*/

#include <pomme.h>
#include <time.h>
#include <stdlib.h>

Pomme * alloue_pomme(int y, int x){
    Pomme * apple = (Pomme *)malloc(sizeof(Pomme));
    if (!apple) {return NULL;}
    apple->position.y = y;
    apple->position.x = x;
    apple->suivant = NULL;
    return apple;
}

Pomme * pomme_aleatoire(int nb_lignes, int nb_colonnes){
    int y = rand() % nb_lignes;
    int x = rand() % nb_colonnes;
    Pomme * apple = alloue_pomme(y, x);
    return apple;
}