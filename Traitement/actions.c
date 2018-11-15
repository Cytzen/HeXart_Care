#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "actions.h"


void ordreFichier(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le poul est de %f.\n", ptr_Tableau[i].poul);
    }
    return;
}

void ordreCroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le poul est de %f.\n", ptr_Tableau[i].poul);
    }
    return;
}

void ordreDecroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for (int j = *ptr_nbrLine-1; j >= 0; j--)
    {
        printf("A %f ms ", ptr_Tableau[j].temps);
        printf("le poul est de %f.\n", ptr_Tableau[j].poul);
    }
    return;
}

void ordreCroissantPoul(ligne* ptr_Tableau, int* ptr_nbrLine)
{

    int min;
    ligne tempo;

    for (int i = 0 ; i < *ptr_nbrLine; i++)
    {
        /* recherche du numero du minimum */
        min = i;
        for (int k = i+1; k< *ptr_nbrLine ; k++)
        {
            if (ptr_Tableau[k].poul < ptr_Tableau[min].poul)
            {
                min =k;
            }
        }
        /* echange des valeurs entre la case courante et le minimum */
        tempo = ptr_Tableau[i];
        ptr_Tableau[i] = ptr_Tableau[min];
        ptr_Tableau[min] = tempo;
    }

    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le poul est de %f.\n", ptr_Tableau[i].poul);
    }
    return;
}

void ordreDecroissantPoul(ligne* ptr_Tableau, int* ptr_nbrLine)
{

    int min;
    ligne tempo;

    for (int i = 0 ; i < *ptr_nbrLine; i++)
    {
        /* recherche du numero du minimum */
        min = i;
        for (int k = i+1; k< *ptr_nbrLine ; k++)
        {
            if (ptr_Tableau[k].poul > ptr_Tableau[min].poul)
            {
                min =k;
            }
        }
        /* echange des valeurs entre la case courante et le minimum */
        tempo = ptr_Tableau[i];
        ptr_Tableau[i] = ptr_Tableau[min];
        ptr_Tableau[min] = tempo;
    }

    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le poul est de %f.\n", ptr_Tableau[i].poul);
    }
    return;
}

void tempsChoisi(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    float choix;
    printf("Pour quel temps en ms voulez vous afficher les donnees ?\n");
    scanf("%f", &choix);
    printf("\n");

    if (0 < choix && choix <= ptr_Tableau[*ptr_nbrLine-1].temps)
    {
        for (int i = 0; i < *ptr_nbrLine; i++)
        {
            if (ptr_Tableau[i].temps == choix)
            {
                printf("A %f ms ", ptr_Tableau[i].temps);
                printf("le poul est de %f.\n", ptr_Tableau[i].poul);
            }
        }
    }
    else
    {
        printf("Il n'y a pas de donnees pour le temps que vous avez choisi.\n");
    }

    return;
}












void nbrLigneDonnees(int* ptr_nbrLine)
{
    printf ("Le nombre de lignes de donnees actuellement en memoire est %d.\n", *ptr_nbrLine);

}
