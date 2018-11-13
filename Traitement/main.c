/*
    Traitement des données

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
    chargeDonnees ();
    menu();
    return 0;
}
