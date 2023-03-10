/* Auteur : OUMAKHLOUF Selym | LUSTGARTEN Leo
 * Creation : 08/03/2023
*/

#include "jeu.h"

void deplace_serpent(Tete serp, Case position_serp){
    if(serp->suivant){
        deplace_serpent(serp->suivant, serp->position);
    }
    serp->position = position_serp;
}

int pomme_sur_serpent(Tete serp, Case apple){
    while(serp){
        if (serp->position.y == apple.y &&
            serp->position.x == apple.x) {return 1;}
        serp = serp->suivant;
    }
    return 0;
}

int pomme_sur_pomme(Pomme list_pomme, Case apple){
    while(&list_pomme){
        if (list_pomme.position.y == apple.y &&
            list_pomme.position.x == apple.x) {return 1;}
        list_pomme = *list_pomme.suivant;
    }
    return 0;
}

void monde_ajouter_pomme(Monde *mon){
    int boucle = 1;
    Pomme * apple = pomme_aleatoire(mon->lignes, mon->colonnes);
    while(boucle){
        Pomme * apple = pomme_aleatoire(mon->lignes, mon->colonnes);
        Tete corps = mon->snake.head;
        while(pomme_sur_serpent(corps, apple->position) == 1){
            Pomme * apple = pomme_aleatoire(mon->lignes, mon->colonnes);
        }
        Pomme * list_pomme = &(mon->apple);
        if(pomme_sur_pomme(*list_pomme, apple->position) == 0){
            boucle = 0;
        }
    }
    *apple = mon->apple;
    mon->apple = *apple;
}

Monde monde_initialiser(int nb_lignes, int nb_colonnes, int taille_serpent, int nb_pommes){
    Monde mon;
    mon.pom_mangees = 0;
    mon.lignes = nb_lignes;
    mon.colonnes = nb_colonnes;
    mon.snake = serpent_initialiser(nb_lignes, nb_colonnes, taille_serpent);
    for (int i = 0; i < nb_pommes; i++){
        monde_ajouter_pomme(&mon);
    }
    return mon;
}

int monde_est_mort_serpent(Monde mon){
    Case vise = serpent_case_visee(mon.snake);
    if (vise.y > mon.lignes || vise.y < 0 || vise.x > mon.colonnes || vise.x < 0) {return 1;}
    while(mon.snake.head->suivant){
        if (mon.snake.head->position.y == vise.y 
                        && mon.snake.head->position.x == vise.x) {return 1;}
        else {mon.snake.head = mon.snake.head->suivant;}
    }
    return 0;
}

void monde_evoluer_serpent(Monde * mon){
    Case vise = serpent_case_visee(mon->snake);
    Tete tmp = alloue_Tete(vise.y, vise.x);
    tmp->suivant = mon->snake.head->suivant;
    mon->snake.head = tmp;
    int ajout = 1;
    while(&(mon)->apple.suivant){
        if (mon->apple.position.x == vise.x && mon->apple.position.y == vise.y){
            ajout = 0;
            Pomme *p = pomme_aleatoire(mon->lignes, mon->colonnes);
            while(pomme_sur_serpent(mon->snake.head, p->position) == 1 
                    && pomme_sur_pomme(mon->apple, p->position) == 1){
                        p = pomme_aleatoire(mon->lignes, mon->colonnes);
                    }
            p->suivant = mon->apple.suivant;
            *(mon)->apple.suivant = *p;
        }
    }
    if (ajout == 1) {deplace_serpent(mon->snake.head, mon->snake.head->position);}
}