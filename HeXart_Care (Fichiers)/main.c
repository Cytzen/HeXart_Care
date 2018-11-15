/*
    Programme qui permet :
    - de changer l'affichage LED du coeur.
    - d'avoir des informations sur les pouls enregistrés et de traiter ces données.

    Projet : HeXartCare
    Corentin, Gabriel, Julien, Arthur
    EXIA A1
*/

#include <stdlib.h>
#include <stdio.h>

#include "menuTraitement.h"
#include "menuLEDs.h"


int main()
{
    int choice = 1;


    //Déclaration du pointeur qui contiendra le nombre lignes.
    int nbrLine = 0;
    int* ptr_nbrLine = &nbrLine;

    //Création du tableau (de structure "ligne") qui va stocker les données en mémoire.
    ligne *ptr_Tableau;
    ptr_Tableau = malloc(255*sizeof(float)); //Allocation de mémoire pour le tableau.

    if (ptr_Tableau == NULL)
    {
        printf("Erreur creation du tableau");
        return 0;
    }


    while ((choice > 0) && (choice < 3))
    {
        printf("<---- Menu : Principal ---->\n");
        printf("Que souhaitez-vous faire?\n\n");
        printf("(1)     Menu : Traitement de donnees.\n");
        printf("(2)     Menu : Gestion des LEDs.\n\n");
        printf("(autre) Quitter\n\n");
        scanf("%d", &choice);
        printf("\n");

        switch(choice)
        {
        case 1 :
        {
            //Appel du menu Traitement de données.
            menuTraitement(ptr_Tableau, ptr_nbrLine);
            printf("\n");
            break;
        }

        case 2  :
        {
            menuLEDs();
            printf("\n");
            break;
        }


        default :
        {
            printf("CIAO !");
            return 0;
        }
        }

    }

    //Libération de la mémoire et sortie du programme.
    free (ptr_Tableau);
    return 0;
}
