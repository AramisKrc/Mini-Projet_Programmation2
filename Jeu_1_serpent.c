#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "Jeu.h"
#include<unistd.h>

void jouer_jeu_serpent_limite(Grille *grille, int delai) {
    int ch;
    unsigned int snake_x = grille->n / 2;
    unsigned int snake_y = grille->m / 2;
    srand(time(NULL));

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    halfdelay(delai);

    do {
        Grille_vider(grille);
        grille->tableau[snake_x][snake_y] = 'S';
        grille->tableau[grille->fruit_x][grille->fruit_y] = 'F';

        int rand_x = rand() % grille->n;
        int rand_y = rand() % grille->m;

        Grille_redessiner(grille);

        ch = getch();

        switch (ch) {
            case KEY_UP:
                if (snake_x > 0) snake_x--;
                break;
            case KEY_DOWN:
                if (snake_x < grille->n - 1) snake_x++;
                break;
            case KEY_LEFT:
                if (snake_y > 0) snake_y--;
                break;
            case KEY_RIGHT:
                if (snake_y < grille->m - 1) snake_y++;
                break;
        }

        if (grille->tableau[snake_x][snake_y] == 'F') {
            // If the snake eats the fruit, increase its length and respawn the fruit
            grille->fruit_x = rand() % grille->n;
            grille->fruit_y = rand() % grille->m;
            grille->tableau[grille->fruit_x][grille->fruit_y] = 'F';
            //increase the length of the snake
            grille->tableau[snake_x][snake_y] = 'S';

        } else if (grille->tableau[snake_x][snake_y] == 'S') {  // If the snake hits itself, end the game
            
             printf("\33[1E");
            printf("Game over!");
            sleep(2);
            break;
          
    
        }


    } while (ch != 'q');

    endwin();
}
