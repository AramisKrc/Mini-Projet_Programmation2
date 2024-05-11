#ifndef LISTE_SECTION_H
#define LISTE_SECTION_H

struct maillon_section {
    int nb_case;
    int color;
    struct maillon_section *suivant;
};

struct liste_section {
    struct maillon_section *premier;
    struct maillon_section *dernier;
    int longueur;
};

struct maillon_section *nouveau_maillon_section(int nb_case, int color);
void detruire_maillon_section(struct maillon_section **m);
struct liste_section *nouvelle_liste_section();
int est_vide_liste_section(const struct liste_section *l);
int longueur_liste_section(const struct liste_section *l);
void afficher_liste_section(const struct liste_section *l);
void ajouter_maillon_debut_liste_section(struct liste_section *l, struct maillon_section *m);
void ajouter_maillon_fin_liste_section(struct liste_section *l, struct maillon_section *m);
struct maillon_section *extraire_maillon_debut_liste_section(struct liste_section *l);
struct maillon_section *extraire_maillon_fin_liste_section(struct liste_section *l);
void detruire_liste_section(struct liste_section **l);

#endif /* LISTE_SECTION_H */
