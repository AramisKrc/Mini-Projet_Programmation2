#include <stdio.h>
#include <stdlib.h>
#include "Grille.h"
#include "Jeu.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <n> <m> <delai>\n", argv[0]);
        return 1;
    }

    unsigned int n = atoi(argv[1]);
    unsigned int m = atoi(argv[2]);
    int delai = atoi(argv[3]);

    Grille *grille = Grille_allouer(n, m);
    if (grille == NULL) {
        printf("Failed to allocate memory for the grid.\n");
        return 1;
    }

    jouer_jeu_serpent_limite(grille, delai);

    Grille_desallouer(grille);

    return 0;
}

