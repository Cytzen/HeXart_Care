#include <stdlib.h>
#include <stdio.h>

#include "donnees.h"


void chargeDonnees (ligne* ptr_Tableau, int* ptr_nbrLine)
{
    int verif;
    *ptr_nbrLine = 0;

    ligne ligneEnCour;
    int checkFermeture = 1;

    FILE* fichier = NULL;

    //Recupère le nombre de lignes du fichier.
    fichier = fopen("battements.csv", "r");
    while ((verif = getc(fichier)) != EOF) ///(End Of Fichier).
    {
        if (verif == '\n')
            ++*ptr_nbrLine;                //Incrémente le nombre de ligne.

    }

    //Remplis le tableau de structure avec les données du csv.
    fichier = fopen("battements.csv", "r");
    if (fichier != NULL)
    {
        printf("Succes ouverture du fichier\n");

        // Boucle pour parcourir le tableau du début vers la fin.
        for (int i = 0; i < *ptr_nbrLine; i++)
        {
            fscanf(fichier, "%f;%f", &ligneEnCour.temps, &ligneEnCour.pouls); //Récupère les données dans "ligneEnCour".
            ptr_Tableau[i] = ligneEnCour; //Copie "ligneEnCour" dans la case "i" du tableau.
        }

        checkFermeture = fclose(fichier);
        if(checkFermeture == 0)
        {
            printf("Succes fermeture du fichier\n\n");
        }

    }
    else
    {
        printf("Echec l'ouverture du fichier\n\n");
    }

    return;
}
