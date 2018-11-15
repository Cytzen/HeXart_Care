/*
    Module 3.4 : Traitement des données

    Projet : HeXartCare
    Corentin, Gabriel, Julien, Arthur
    EXIA A1
*/

#include <stdlib.h>
#include <stdio.h>

#include "menu.h"


int main()
{
    //Déclaration du pointeur qui contiendra le nombre lignes.
    int nbrLine = 0;
    int* ptr_nbrLine = &nbrLine;


    //Création du tableau (de structure ligne) qui va stocker les données en mémoire.
    ligne *ptr_Tableau;
    ptr_Tableau = malloc(255*sizeof(float)); //-------------------------------//

    if (ptr_Tableau == NULL)
    {
        printf("Erreur creation du tableau");
        return 0;
    }


    //Appel du menu.
    menu (ptr_Tableau, ptr_nbrLine);


    //Libération de la mémoire et sortie du programme.
    free (ptr_Tableau);
    return 0;
}
