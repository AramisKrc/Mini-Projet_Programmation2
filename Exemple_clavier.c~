#include<ncurses.h>

int main() {
  int ch, ch_dern;
  int i=0,o;

  /* Initialisation de ncurses et du clavier(4 lignes)*/
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();


  halfdelay(1);  /* Temps d'exécution max de getch à 1/10eme de seconde */

  do{
  
    ch = getch();
    
    i++;  /* Compteur pour se rendre compte que "le temps passe" */

    if (ch==-1){  /* Si aucune touche utilisee, getch renvoie -1 */
       /* Comme aucune touche n'a ete utilisee
          le programme peut faire autre chose */
       printf("%d\33[1E",i);  /* Par exemple : afficher un compteur */
    } 
    else{
       /* Ici une touche a ete utilisee, getch a renvoyee son code
          le programme peut repondre a l'utilisateur du clavier*/
      ch_dern=ch; /* Par exemple ic, on sauvegarde la dernière touche utilisee pour l'afficher*/     
    
    }
    
    /* A partir d'ici, les actions sont effectuees que l'utilisateur ait appuye ou non sur une touche) */
    
    printf("\33[2J"); /* Efface tout l'ecran */
    printf("\33[H");  /* Place le curseur en haut à gauche */
    printf("Test: appuyez une touche (ou appuyez sur # pour Sortir)\n\33[1E");

    switch(ch_dern) {  
        case KEY_UP:   /* Ces constantes sont dans ncurses pour correspondre aux codes de touches */
           printf("La derniere touche utilisee est: Up Arrow\33[1E");
           i=0;
           break;
        case KEY_DOWN: 
           printf("La derniere touche utilisee est: Down Arrow\33[1E");
           break;
        case KEY_LEFT: 
           printf("La derniere touche utilisee est: Left Arrow\33[1E");
           break; 
        case KEY_RIGHT: 
           printf("La derniere touche utilisee est: Right Arrow\33[1E");
           break;
        default:
           printf("La derniere touche utilisee est: %c\33[1E",ch_dern);
           break;
      }
      
   fflush(stdout);  /* Force l'affichage compler des commandes precedentes */
   
  } while (ch!= '#');

    
  endwin(); /* Doit obligatoirement etre mis en fin de programme pour remettre le terminal en etat */
  
  printf("\n\nAu revoir !\n");


  return 0;
}

