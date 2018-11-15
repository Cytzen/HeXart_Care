#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "actions.h"
#include "tris.h"


//-----------------------------------------------------------------------//
void ordreFichier(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le pouls est de %f.\n", ptr_Tableau[i].pouls);
    }
    return;
}



//-----------------------------------------------------------------------//
void ordreCroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le pouls est de %f.\n", ptr_Tableau[i].pouls);
    }
    return;
}



//-----------------------------------------------------------------------//
void ordreDecroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for (int j = *ptr_nbrLine-1; j >= 0; j--)
    {
        printf("A %f ms ", ptr_Tableau[j].temps);
        printf("le pouls est de %f.\n", ptr_Tableau[j].pouls);
    }
    return;
}



//-----------------------------------------------------------------------//
void ordreCroissantPouls(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisCroissantTemps(ptr_Tableau, ptr_nbrLine);

    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le pouls est de %f.\n", ptr_Tableau[i].pouls);
    }
    return;
}



//-----------------------------------------------------------------------//
void ordreDecroissantPouls(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisDecroissantTemps(ptr_Tableau, ptr_nbrLine);

    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le pouls est de %f.\n", ptr_Tableau[i].pouls);
    }
    return;
}



//-----------------------------------------------------------------------//
void tempsChoisi(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    float choix;
    printf("Pour quel temps (en ms) voulez vous afficher les donnees ?\n");
    scanf("%f", &choix);
    printf("\n");

    if (0 < choix && choix <= ptr_Tableau[*ptr_nbrLine-1].temps)
    {
        for (int i = 0; i < *ptr_nbrLine; i++)
        {
            if (ptr_Tableau[i].temps == choix)
            {
                printf("A %f ms ", ptr_Tableau[i].temps);
                printf("le pouls est de %f.\n", ptr_Tableau[i].pouls);
            }
        }
    }
    else
    {
        printf("Il n'y a pas de donnees pour le temps que vous avez choisi.\n");
    }

    return;
}



//-----------------------------------------------------------------------//
void moyenne(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    float debut, fin;
    float moyenne = 0;
    int nbrTotal = 0;
    bool msgErreur = false;

    do
    {
        if(msgErreur)
        {
            printf("/!\ Attention /!\ La premiere valeur de la plage ne peut pas etre superieure a la derniere.\n\n");
        }

        printf("Entrez le temps (en ms) a partir duquel la plage de donnee commence.\n");
        scanf("%f", &debut);
        printf("\n");
        while (debut < 0 || debut > ptr_Tableau[*ptr_nbrLine-1].temps)
        {
            printf("Il n'existe pas de valeur pour %fms.\n", debut);
            printf("Entrez le temps (en ms) a partir duquel la plage de donnee commence.\n");
            scanf("%f", &debut);
            printf("\n");
        }

        printf("Entrez le temps (en ms) a partir duquel la plage de donnee se termine.\n");
        scanf("%f", &fin);
        printf("\n");
        while (fin < 0 || fin > ptr_Tableau[*ptr_nbrLine-1].temps)
        {
            printf("Il n'existe pas de valeur pour %fms.\n", fin);
            printf("Entrez le temps (en ms) a partir duquel la plage de donnee termine.\n");
            scanf("%f", &fin);
            printf("\n");
        }

        msgErreur = true;
    }
    while (debut > fin);


    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        if (debut <= ptr_Tableau[i].temps && ptr_Tableau[i].temps <= fin)
        {
            moyenne = moyenne + ptr_Tableau[i].pouls;
            ++nbrTotal;
        }
    }
    moyenne = moyenne / nbrTotal;
    printf("La moyenne du pouls sur la plage %fms - %fms est de %f.\n", debut, fin, moyenne);
}



//-----------------------------------------------------------------------//
void nbrLigneDonnees(int* ptr_nbrLine)
{
    printf ("Le nombre de lignes de donnees actuellement en memoire est %d.\n", *ptr_nbrLine);
}



//-----------------------------------------------------------------------//
void poulsMin(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisCroissantTemps(ptr_Tableau, ptr_nbrLine);

    printf("Le pouls minimum est de %f.\n",ptr_Tableau[0].pouls);

    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        if (ptr_Tableau[i].pouls == ptr_Tableau[0].pouls)
        {
            printf("A %f ms ", ptr_Tableau[i].temps);
            printf("le pouls est de %f.\n", ptr_Tableau[i].pouls);
        }
    }
}



//-----------------------------------------------------------------------//
void poulsMax(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisCroissantTemps(ptr_Tableau, ptr_nbrLine);

    printf("Le pouls maximum est de %f.\n",ptr_Tableau[*ptr_nbrLine-1].pouls);

    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        if (ptr_Tableau[i].pouls == ptr_Tableau[*ptr_nbrLine-1].pouls)
        {
            printf("A %f ms ", ptr_Tableau[i].temps);
            printf("le pouls est de %f.\n", ptr_Tableau[i].pouls);
        }
    }
}
