#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "menu.h"
#include "actions.h"


void menu (ligne* ptr_Tableau, int* ptr_nbrLine)
{
    int choice = 1;

    printf("**** Traitement des donnees ****\n\n");

    while ((choice > 0) && (choice < 11))
    {
        printf("Que souhaitez-vous faire?\n\n");
        printf("(1)     Afficher dans l'ordre du fichier\n");
        printf("(2)     Afficher dans l'ordre croissant des dates\n");
        printf("(3)     Afficher dans l'ordre decrissant des date\n");
        printf("(4)     Afficher dans l'ordre croissant des pouls\n");
        printf("(5)     Afficher dans l'ordre decroissant des pouls\n");
        printf("(6)     Afficher les donnees pour un temps choisi\n");
        printf("(7)     Afficher la moyenne pour une plage de donnees choisi\n");
        printf("(8)     Afficher le nombre de ligne de donnees actuellement en memoire\n");
        printf("(9)     Afficher le poul minimum\n");
        printf("(10)    Afficher le poul maximum\n\n");
        printf("(autre) Quitter?\n\n");

        scanf("%d", &choice);

        switch(choice)
        {
        case 1 :
        {
            chargeDonnees (ptr_Tableau, ptr_nbrLine);
            ordreFichier(ptr_Tableau, ptr_nbrLine);
            printf("\n");
            break;
        }

        case 2  :
        {
            chargeDonnees (ptr_Tableau, ptr_nbrLine);
            ordreCroissantTemps(ptr_Tableau, ptr_nbrLine);
            printf("\n");
            break;
        }

        case 3  :
        {
            chargeDonnees (ptr_Tableau, ptr_nbrLine);
            ordreDecroissantTemps(ptr_Tableau, ptr_nbrLine);
            printf("\n");
            break;
        }

        case 4  :
        {
            chargeDonnees (ptr_Tableau, ptr_nbrLine);
            ordreCroissantPoul(ptr_Tableau, ptr_nbrLine);
            printf("\n");
            break;
        }

        case 5  :
        {
            chargeDonnees (ptr_Tableau, ptr_nbrLine);
            ordreDecroissantPoul(ptr_Tableau, ptr_nbrLine);
            printf("\n");
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
