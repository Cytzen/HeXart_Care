/*
    Module 3.4 : Traitement des données

    Projet : HeXartCare
    Corentin, Gabriel, Julien, Arthur
    EXIA A1
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "menu.h"
#include "donnees.h"



int main()
{
    ///----------------------------///
    int nbrLine = 0;
    int* ptr_nbrLine = &nbrLine;
    ///----------------------------///



    ligne *ptr_TableauDonnees;
    ptr_TableauDonnees = malloc(255*sizeof(float));
    if (ptr_TableauDonnees == NULL)
    {
        printf("Erreur creation du tableau");
        return 0;
    }
    else
    {
        chargeDonnees (ptr_TableauDonnees, ptr_nbrLine);
    }


    menu(ptr_TableauDonnees, ptr_nbrLine);

    free (ptr_TableauDonnees);
    return 0;
}
