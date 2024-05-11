#include "serpent.h"
#include<stdlib.h>
#include<stdio.h>




struct Serpent *nouveau_serpent(int x, int y) {
    struct Serpent *serpent = malloc(sizeof(struct Serpent));
    if (serpent == NULL) {
        return NULL; // Memory allocation failed
    }
    serpent->x_tete = x;
    serpent->y_tete = y;
    serpent->corps = *nouvelle_liste_section(); // Dereference the pointer
    return serpent;
}

// In serpent.c
/*
void detruire_serpent(struct Serpent **serpent) {
    if (*serpent != NULL) {
        detruire_liste_section(&(*serpent)->corps);
        free(*serpent);
        *serpent = NULL;
    }
}
*/

