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

    //Recup�re le nombre de lignes du fichier.
    fichier = fopen("HeartbeatData.csv", "r");
    while ((verif = getc(fichier)) != EOF) ///(End Of Fichier).
    {
        if (verif == '\n')
            ++*ptr_nbrLine;                //Incr�mente le nombre de ligne.

    }

    //Remplis le tableau de structure avec les donn�es du csv.
    fichier = fopen("HeartbeatData.csv", "r");
    if (fichier != NULL)
    {
        printf("Succes ouverture du fichier\n");

        // Boucle pour parcourir le tableau du d�but vers la fin.
        for (int i = 0; i < *ptr_nbrLine; i++)
        {
            fscanf(fichier, "%f;%f", &ligneEnCour.temps, &ligneEnCour.pouls); //R�cup�re les donn�es dans "ligneEnCour".
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
