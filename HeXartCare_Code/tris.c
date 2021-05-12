#include <stdlib.h>
#include <stdio.h>

#include "tris.h"


void trisCroissantPouls(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    int min;
    ligne tempo;

    for (int i = 0 ; i < *ptr_nbrLine; i++)
    {
        // Recherche du pouls du minimum.
        min = i;
        for (int k = i+1; k < *ptr_nbrLine ; k++)
        {
            if (ptr_Tableau[k].pouls < ptr_Tableau[min].pouls)
            {
                min =k;
            }
        }
        // Echange les valeurs entre la case "i" et le minimum.
        tempo = ptr_Tableau[i];
        ptr_Tableau[i] = ptr_Tableau[min];
        ptr_Tableau[min] = tempo;
    }
}


void trisDecroissantPouls(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    int max;
    ligne tempo;

    for (int i = 0 ; i < *ptr_nbrLine; i++)
    {
        // Recherche du pouls du maximum.
        max = i;
        for (int k = i+1; k < *ptr_nbrLine ; k++)
        {
            if (ptr_Tableau[k].pouls > ptr_Tableau[max].pouls)
            {
                max =k;
            }
        }
        // Echange les valeurs entre la case "i" et le maximum.
        tempo = ptr_Tableau[i];
        ptr_Tableau[i] = ptr_Tableau[max];
        ptr_Tableau[max] = tempo;
    }
}
