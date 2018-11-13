#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "donnees.h"


void chargeDonnees (ligne *ptr_Tableau)
{

    ligne ligne1;
    int checkFermeture = 1;

    FILE* fichier = NULL;
    fichier = fopen("Tableau.csv", "r"); ///----------------------------///

    if (fichier != NULL)
    {
        printf("Succes ouverture du fichier\n");
        for(int i = 0; i < 12; i++) ///----------------------------///
        {
            fscanf(fichier, "%f;%f", &ligne1.temps, &ligne1.poul);
            ptr_Tableau[i] = ligne1;
        }

        checkFermeture = fclose(fichier);
        if(checkFermeture == 0)
        {
            printf("Succes fermeture du fichier\n");
        }

    }
    else
    {
        printf("Echec l'ouverture du fichier\n");
    }

    printf("Chargement du fichier termine.\n\n");
    return;

}
