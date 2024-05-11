#ifndef SERPENT_H
#define SERPENT_H

#include "Liste_section.h"

struct Serpent {
    int x_tete;
    int y_tete;
    struct liste_section corps;
};

struct Serpent *nouveau_serpent(int x, int y);
void detruire_serpent(struct Serpent **serpent);

#endif /* SERPENT_H */
