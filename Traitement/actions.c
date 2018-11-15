#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "actions.h"


void ordreFichier(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for(int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le poul est de %f.\n", ptr_Tableau[i].poul);
    }
    return;
}

void ordreCroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for(int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le poul est de %f.\n", ptr_Tableau[i].poul);
    }
    return;
}

void ordreDecroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    for(int j = *ptr_nbrLine-1; j >= 0; j--)
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


    /*for (int i = 0; i < 5; i++)
    {
        printf ("%d",ptr_Tableau[i]);
    }*/


}


