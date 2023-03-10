/* Auteur : OUMAKHLOUF Selym | LUSTGARTEN Leo
 * Creation : 08/03/2023
*/

#include <ncurses.h>
#include "graphique.h"

void interface_afficher_quadrillage(Monde mon){
    for (int i = 0; i < mon.lignes; i += YCASE - 1){
        for (int j = 0; j < mon.colonnes; j += XCASE - 1) {
            attron(COLOR_PAIR(1));
            box(subwin(stdscr, YCASE, XCASE, i, j),
                ACS_VLINE, ACS_HLINE);
            attroff(COLOR_PAIR(1));
        } 
    }
}

void interface_afficher_pomme(Pomme pom){
    int y = pom.position.y;
    int x = pom.position.x;
    attron(COLOR_PAIR(2));
    box(subwin(stdscr, YCASE - 2, XCASE - 2,
               (YCASE - 1) * y + 1, (XCASE - 1) * x + 1),
        ACS_VLINE, ACS_HLINE);
    attroff(COLOR_PAIR(2));
}

void interface_afficher_serpent(Serpent ser){
    int y = ser.head->position.y;
    int x = ser.head->position.x;
    attron(COLOR_PAIR(3));
    box(subwin(stdscr, YCASE - 2, XCASE - 2,
               (YCASE- 1 ) * y + 1,(XCASE - 1) * x + 1),
        ACS_VLINE, ACS_HLINE);
    attroff(COLOR_PAIR(3));
    ser.head = ser.head->suivant;
    while (ser.head){
        y = ser.head->position.y;
        x = ser.head->position.x;
        attron(COLOR_PAIR(4));
        box(subwin(stdscr, YCASE - 2, XCASE - 2,
                   (YCASE - 1) * y + 1, (XCASE - 1) * x + 1),
            ACS_VLINE, ACS_HLINE);
        attroff(COLOR_PAIR(4));
    } 
}

void interface_afficher_monde(Monde mon){
    interface_afficher_quadrillage(mon);
    interface_afficher_pomme(mon.apple);
    interface_afficher_serpent(mon.snake);
    attron(COLOR_PAIR(2));
    mvprintw(LINES - 1, 1, "Nombre de pommes mangées %d", mon.pom_mangees);
    attroff(COLOR_PAIR(2));
}