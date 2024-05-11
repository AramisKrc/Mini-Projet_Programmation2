#include "Grille.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "serpent.h"

Grille* Grille_allouer(unsigned int n, unsigned int m) {
    Grille *grille = malloc(sizeof(Grille));
    if (grille == NULL) {
        return NULL; // Memory allocation failed
    }

    grille->n = n;
    grille->m = m;
    grille->tableau = malloc(n * sizeof(char *));
    if (grille->tableau == NULL) {
        free(grille);
        return NULL; // Memory allocation failed
    }

    // Allocate memory for each row
    for (unsigned int i = 0; i < n; i++) {
        grille->tableau[i] = malloc(m * sizeof(char));
        if (grille->tableau[i] == NULL) {
            // Free previously allocated memory
            for (unsigned int j = 0; j < i; j++) {
                free(grille->tableau[j]);
            }
            free(grille->tableau);
            free(grille);
            return NULL; // Memory allocation failed
        }
    }

    Grille_vider(grille);
    Grille_tirage_fruit(grille);
    return grille;
}

void Grille_vider(Grille *grille) {
    for (unsigned int i = 0; i < grille->n; i++) {
        for (unsigned int j = 0; j < grille->m; j++) {
            grille->tableau[i][j] = ' ';
        }
    }
}

void Grille_tirage_fruit(Grille *grille) {
    srand(time(NULL));
    grille->fruit_x = rand() % grille->n;
    grille->fruit_y = rand() % grille->m;
}






void Grille_desallouer(Grille *grille) {
    for (unsigned int i = 0; i < grille->n; i++) {
        free(grille->tableau[i]);
    }
    free(grille->tableau);
    free(grille);
}

void Grille_redessiner(Grille *grille) {
    printf("\033[H");  // Move cursor to top-left corner

    // Print top border
    printf("\033[47m "); // White background color
    for (unsigned int j = 0; j < grille->m * 2 +1 ; j++) {
        printf(" ");
    }
    printf("\33[1E");

    // Print the grid with the fruit marked
    for (unsigned int i = 0; i < grille->n; i++) {
        // Print left border

        printf("\033[47m "); // White background color for left border
        // Print grid contents
        for (unsigned int j = 0; j < grille->m; j++) {
            if (i == grille->fruit_x && j == grille->fruit_y) {
                printf("\033[0m\U0001F34E"); // Emoji for fruit with default color
            } else if (grille->tableau[i][j] == 'S') {
                printf("\033[32m\u25A0 "); // Green color for the snake
            } else {
                printf("\033[40m  "); // Black background color for the interior
            }
            
            
        }
        // Print right border
        printf("\033[47m "); // White background color for right border
        printf("\33[1E");
    }

    // Print bottom border
    printf("\033[47m"); // White background color
    for (unsigned int j = 0; j < grille->m * 2 + 2; j++) {
        printf(" ");
    }
    printf("\033[0m\n"); // Reset colors
    printf("\n");
}
