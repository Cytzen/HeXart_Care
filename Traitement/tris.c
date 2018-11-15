#include <stdlib.h>
#include <stdio.h>

#include "tris.h"


void trisCroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    int min;
    ligne tempo;

    for (int i = 0 ; i < *ptr_nbrLine; i++)
    {
        /* recherche du numero du minimum */
        min = i;
        for (int k = i+1; k < *ptr_nbrLine ; k++)
        {
            if (ptr_Tableau[k].pouls < ptr_Tableau[min].pouls)
            {
                min =k;
            }
        }
        /* echange des valeurs entre la case courante et le minimum */
        tempo = ptr_Tableau[i];
        ptr_Tableau[i] = ptr_Tableau[min];
        ptr_Tableau[min] = tempo;
    }
}


void trisDecroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    int min;
    ligne tempo;

    for (int i = 0 ; i < *ptr_nbrLine; i++)
    {
        /* recherche du numero du minimum */
        min = i;
        for (int k = i+1; k < *ptr_nbrLine ; k++)
        {
            if (ptr_Tableau[k].pouls > ptr_Tableau[min].pouls)
            {
                min =k;
            }
        }
        /* echange des valeurs entre la case courante et le minimum */
        tempo = ptr_Tableau[i];
        ptr_Tableau[i] = ptr_Tableau[min];
        ptr_Tableau[min] = tempo;
    }
}
