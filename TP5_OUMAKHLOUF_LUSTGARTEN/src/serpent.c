/* Auteur : OUMAKHLOUF Selym | LUSTGARTEN Leo
 * Creation : 08/03/2023
*/
#include <serpent.h>
#include <stdlib.h>

Tete alloue_Tete(int y, int x){
    Tete head = (Tete)malloc(sizeof(Tete));
    if (!head) {return NULL;}
    head->position.y = y;
    head->position.x = x;
    head->suivant = NULL;
    return head;
}

Serpent serpent_initialiser(int nb_lignes, int nb_colonnes, int taille){
    Serpent snake;
    int y = nb_lignes / 2;
    int x = nb_colonnes / 2;
    snake.dir = EST;
    snake.head = NULL;
    Tete tmp;
    for (int i = taille; i >= 0; i--){
        tmp = alloue_Tete(y, x - i);
        tmp->suivant = snake.head;
        snake.head = tmp;
    }
    return snake;
}

Case serpent_case_visee(Serpent serp){
    switch (serp.dir) {
        case NORD :
            serp.head->position.y--;
            break;
        case SUD :
            serp.head->position.y++;
            break;
        case EST :
            serp.head->position.x++;
            break;
        case OUEST :
            serp.head->position.x--;
    }
    return serp.head->position;
}

