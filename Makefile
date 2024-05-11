# Compiler
CC=gcc
# Flags de compilation
CFLAGS=-Wall -Wextra -Werror -std=c99

# Noms des fichiers sources
SRC=main.c Grille.c
# Nom de l'exécutable final
EXEC=my_program

# Commande pour construire l'exécutable
my_program: main.c Grille.c
	gcc -Wall -Wextra -Werror -std=c99 -o my_program main.c Grille.c

clean:
    rm -f my_program

.PHONY: clean

