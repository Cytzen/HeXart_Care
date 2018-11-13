#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "menu.h"


void menu ()
{
    int choice = 1;

    printf("**** Traitement des donnees ****\n\n");

    while ((choice > 0) && (choice < 11))
    {
        printf("Que souhaitez-vous faire?\n\n");
        printf("(1)     Afficher dans l'odre du fichier\n");
        printf("(2)     Afficher dans l'odre croissant des dates\n");
        printf("(3)     Afficher dans l'odre decrissant des date\n");
        printf("(4)     Afficher dans l'odre croissantt des pouls\n");
        printf("(5)     Afficher dans l'odre décrissant des pouls\n");
        printf("(6)     Afficher les données pour un temps choisis\n");
        printf("(7)     Afficher la moyenne pour une plage de donnees choisie\n");
        printf("(8)     Afficher le nombre de ligne de donnees actuellement en memoire\n");
        printf("(9)     Afficher le poul minimum\n");
        printf("(10)    Afficher le poul maximum\n\n");
        printf("(autre) Quitter?\n\n");

        scanf("%d", &choice);

        switch(choice)
        {
        case 1 :
        {


            break;
        }
        case 2  :
        {



            break;
        }
        case 3  :
        {



            break;
        }
        case 4  :
        {



            break;
        }
        case 5  :
        {



            break;
        }
        case 6  :
        {



            break;
        }
        case 7  :
        {



            break;
        }
        case 8  :
        {



            break;
        }
        case 9  :
        {



            break;
        }
        case 10  :
        {



            break;
        }
        default :
        {

            printf("CIAO !");
            return;
        }
        }
    }

}
