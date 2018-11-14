#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "donnees.h"


void chargeDonnees (ligne* ptr_Tableau, int* ptr_nbrLine)
{
    //int nbrLine = 0;
    // int* ptr_nbrLine = &nbrLine;

    int compteur;

    ligne ligneEnCour;
    int checkFermeture = 1;

    FILE* fichier = NULL;

    //Recupère le nombre de lignes du fichier.
    fichier = fopen("Tableau.csv", "r"); ///----------------------------///

    while ((compteur = getc(fichier)) != EOF) ////End Of Fichier
    {
        if (compteur == '\n')
            ++*ptr_nbrLine;
    }
    printf ("Nbr de lignes = %d\n\n", *ptr_nbrLine); ///----------------------------//////----------------------------///


    //Remplis le tableau de structure avec les données du csv.
    fichier = fopen("Tableau.csv", "r"); ///----------------------------///
    if (fichier != NULL)
    {
        printf("Succes ouverture du fichier\n");
        for(int i = 0; i < *ptr_nbrLine; i++)
        {
            fscanf(fichier, "%f;%f", &ligneEnCour.temps, &ligneEnCour.poul);
            ptr_Tableau[i] = ligneEnCour;
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
