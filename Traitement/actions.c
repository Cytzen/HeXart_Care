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
    for(int i = *ptr_nbrLine-1; i > -1; i--)
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le poul est de %f.\n", ptr_Tableau[i].poul);
    }
    return;
}



