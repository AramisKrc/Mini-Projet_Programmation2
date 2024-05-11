#include "Liste_section.h"
#include <stdlib.h>
#include<stdio.h>

struct maillon_section *nouveau_maillon_section(int nb_case, int color) {
    struct maillon_section *m = malloc(sizeof(struct maillon_section));
    if (m == NULL) {
        return NULL; // Allocation failed
    }
    m->nb_case = nb_case;
    m->color = color;
    m->suivant = NULL;
    return m;
}

void detruire_maillon_section(struct maillon_section **m) {
    if (*m != NULL) {
        free(*m);
        *m = NULL;
    }
}

struct liste_section *nouvelle_liste_section() {
    struct liste_section *l = malloc(sizeof(struct liste_section));
    if (l == NULL) {
        return NULL; // Allocation failed
    }
    l->premier = NULL;
    l->dernier = NULL;
    l->longueur = 0;
    return l;
}

int est_vide_liste_section(const struct liste_section *l) {
    return (l->premier == NULL);
}

int longueur_liste_section(const struct liste_section *l) {
    return l->longueur;
}

void afficher_liste_section(const struct liste_section *l) {
    struct maillon_section *m;
    for (m = l->premier; m != NULL; m = m->suivant) {
        printf("Size: %d, Color: %d\n", m->nb_case, m->color);
    }
}

void ajouter_maillon_debut_liste_section(struct liste_section *l, struct maillon_section *m) {
    if (est_vide_liste_section(l)) {
        l->dernier = m;
    }
    m->suivant = l->premier;
    l->premier = m;
    ++l->longueur;
}

void ajouter_maillon_fin_liste_section(struct liste_section *l, struct maillon_section *m) {
    m->suivant = NULL;
    if (est_vide_liste_section(l)) {
        l->premier = m;
    } else {
        l->dernier->suivant = m;
    }
    l->dernier = m;
    ++l->longueur;
}

struct maillon_section *extraire_maillon_debut_liste_section(struct liste_section *l) {
    struct maillon_section *m = l->premier;
    if (m != NULL) {
        l->premier = m->suivant;
        --l->longueur;
        if (est_vide_liste_section(l)) {
            l->dernier = NULL;
        }
        m->suivant = NULL;
    }
    return m;
}

struct maillon_section *extraire_maillon_fin_liste_section(struct liste_section *l) {
    struct maillon_section *m = l->premier, *res;
    if (m == NULL) {
        return m;
    }
    --l->longueur;
    if (m->suivant == NULL) {
        l->premier = NULL;
        l->dernier = NULL;
        return m;
    }
    while (m->suivant->suivant != NULL) {
        m = m->suivant;
    }
    l->dernier = m;
    res = m->suivant;
    m->suivant = NULL;
    return res;
}

/*void detruire_liste_section(struct liste_section **l) {
    if (*l != NULL) {
        while (!est_vide_liste_section(*l)) {
            struct maillon_section *m = extraire_maillon_debut_liste_section(*l);
            detruire_maillon_section(&m);
        }
        free(*l);
        *l = NULL;
        
    }
}
*/
