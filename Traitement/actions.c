#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "actions.h"
#include "tris.h"



void ordreFichier(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le pouls est de %f.\n", ptr_Tableau[i].poul);
    }
    return;
}

void ordreCroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le pouls est de %f.\n", ptr_Tableau[i].poul);
    }
    return;
}

void ordreDecroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for (int j = *ptr_nbrLine-1; j >= 0; j--)
    {
        printf("A %f ms ", ptr_Tableau[j].temps);
        printf("le pouls est de %f.\n", ptr_Tableau[j].poul);
    }
    return;
}

void ordreCroissantPouls(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisCroissantTemps(ptr_Tableau, ptr_nbrLine);

    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le pouls est de %f.\n", ptr_Tableau[i].poul);
    }
    return;
}

void ordreDecroissantPouls(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisDecroissantTemps(ptr_Tableau, ptr_nbrLine);

    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le pouls est de %f.\n", ptr_Tableau[i].poul);
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
                printf("le pouls est de %f.\n", ptr_Tableau[i].poul);
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


void poulsMin(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisCroissantTemps(ptr_Tableau, ptr_nbrLine);

    printf("Le pouls minimum est de %f.\n",ptr_Tableau[0].poul);
}


void poulsMax(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisCroissantTemps(ptr_Tableau, ptr_nbrLine);

    printf("Le pouls maximum est de %f.\n",ptr_Tableau[*ptr_nbrLine-1].poul);
}
