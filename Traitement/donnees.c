#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "donnees.h"


void chargeDonnees ()
{

    ligne ligne1;
    int i =0;
    int checkCloture = 1;
    float tableau[12]= {0}; ///----------------------------///

    FILE* fichier = NULL;
    fichier = fopen("Tableau.csv", "r");

    if (fichier != NULL)
    {
        printf("Succes ouverture du fichier\n");
        for(i = 0; i < 12; i++) ///----------------------------///
        {
            fscanf(fichier, "%f;%f", &ligne1.temps, &ligne1.poul);
        }

        checkCloture = fclose(fichier);
        if(checkCloture == 0)
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
