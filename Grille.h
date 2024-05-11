#ifndef GRILLE_H
#define GRILLE_H

typedef struct {
    unsigned int n; // Number of rows
    unsigned int m; // Number of columns
    char **tableau; // 2D array of characters
    unsigned int fruit_x; // X-coordinate of the fruit
    unsigned int fruit_y; // Y-coordinate of the fruit
} Grille;

Grille* Grille_allouer(unsigned int n, unsigned int m);
void Grille_vider(Grille *grille);
void Grille_tirage_fruit(Grille *grille);
void Grille_remplir(Grille *grille, unsigned int snake_x, unsigned int snake_y, unsigned int snake_size);
void Grille_desallouer(Grille *grille);
void Grille_redessiner(Grille *grille);

#endif /* GRILLE_H */
