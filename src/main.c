/* Auteur : OUMAKHLOUF Selym | LUSTGARTEN Leo
 * Creation : 08/03/2023
*/

#define _DEFAULT_SOURCE
#include "jeu.h"
#include "graphique.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#define DELAI 2500

int main(void){
    initscr();
    curs_set(false);
    keypad(stdscr, TRUE);
    Monde world;
    world = monde_initialiser(LINES - 1, COLS - 1, TAILLE_SERPENT, NB_POMMES);
    interface_afficher_monde(world);
    int touche;
    srand(time(NULL));
    while(monde_est_mort_serpent(world) == 0){
        touche = getch();
        switch (touche) {
        case 'z' :
            world.snake.dir = NORD;
            break;
        case KEY_UP :
            world.snake.dir = NORD;
            break;
        case 's' :
            world.snake.dir = SUD;
            break;
        case KEY_DOWN :
            world.snake.dir = SUD;
            break;
        case 'q' :
            world.snake.dir = OUEST;
            break;
        case KEY_LEFT :
            world.snake.dir = OUEST;
            break;
        case 'd' :
            world.snake.dir = EST;
            break;
        case KEY_RIGHT :
            world.snake.dir = EST;
            break;
        default:
            break;
        }
        monde_evoluer_serpent(&world);
        clear();
        interface_afficher_monde(world);
        refresh();
        usleep(DELAI);
    }
    clear();
    mvprintw((LINES - 1) / 2, (COLS - 1) / 2, "Nombre de pommes mangées %d", world.pom_mangees);
    refresh();
    getch();
    endwin();
}