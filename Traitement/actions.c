#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> // Ajout Bibliothèque poue utiliser les booléens

#include "actions.h"
#include "tris.h"


//-------------------------------------------------------------------------------------------------------------------//
void ordreFichier(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    // Boucle pour parcourir le tableau du début vers la fin.
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %.0f ms ", ptr_Tableau[i].temps);                   //Affiche le temps pour la case "i" du tableau.
        printf("le pouls est de %.2f.\n", ptr_Tableau[i].pouls);      //Affiche le pouls pour la case "i" du tableau.
    }
    return;
}



//-------------------------------------------------------------------------------------------------------------------//
void ordreCroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    // Boucle pour parcourir le tableau du début vers la fin.
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %.0f ms ", ptr_Tableau[i].temps);                   //Affiche le temps pour la case "i" du tableau.
        printf("le pouls est de %.2f.\n", ptr_Tableau[i].pouls);      //Affiche le pouls pour la case "i" du tableau.
    }
    return;
}



//-------------------------------------------------------------------------------------------------------------------//
void ordreDecroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    // Boucle pour parcourir le tableau de la fin vers le début.
    for (int j = *ptr_nbrLine-1; j >= 0; j--)
    {
        printf("A %.0f ms ", ptr_Tableau[j].temps);                   //Affiche le temps pour la case "i" du tableau.
        printf("le pouls est de %.2f.\n", ptr_Tableau[j].pouls);      //Affiche le pouls pour la case "i" du tableau.
    }
    return;
}



//-------------------------------------------------------------------------------------------------------------------//
void ordreCroissantPouls(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisCroissantTemps(ptr_Tableau, ptr_nbrLine);

    // Boucle pour parcourir le tableau du début vers la fin.
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %.0f ms ", ptr_Tableau[i].temps);                   //Affiche le temps pour la case "i" du tableau.
        printf("le pouls est de %.2f.\n", ptr_Tableau[i].pouls);      //Affiche le pouls pour la case "i" du tableau.
    }
    return;
}



//-------------------------------------------------------------------------------------------------------------------//
void ordreDecroissantPouls(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisDecroissantTemps(ptr_Tableau, ptr_nbrLine);

    // Boucle pour parcourir le tableau du début vers la fin.
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        printf("A %.0f ms ", ptr_Tableau[i].temps);                   //Affiche le temps pour la case "i" du tableau.
        printf("le pouls est de %.2f.\n", ptr_Tableau[i].pouls);      //Affiche le pouls pour la case "i" du tableau.
    }
    return;
}



//-------------------------------------------------------------------------------------------------------------------//
void tempsChoisi(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    float choix;
    printf("Pour quel temps (en ms) voulez vous afficher les donnees ?\n");
    scanf("%f", &choix);
    printf("\n");

    // Vérifie si il existe des données pour le temps choisi.
    if (0 < choix && choix <= ptr_Tableau[*ptr_nbrLine-1].temps)
    {
        // Boucle pour parcourir le tableau du début vers la fin.
        for (int i = 0; i < *ptr_nbrLine; i++)
        {
            //Si le temps de la case du tableau est égal au temps recherché, affiche les valeurs de la case.
            if (ptr_Tableau[i].temps == choix)
            {
                printf("A %.0f ms ", ptr_Tableau[i].temps);                   //Affiche le temps pour la case "i" du tableau.
                printf("le pouls est de %.2f.\n", ptr_Tableau[i].pouls);      //Affiche le pouls pour la case "i" du tableau.
            }
        }
    }
    else
    {
        printf("Il n'y a pas de donnees pour le temps que vous avez choisi.\n");
    }

    return;
}



//-------------------------------------------------------------------------------------------------------------------//
void moyenne(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    float debut, fin;
    float moyenne = 0;
    int nbrTotal = 0;
    bool msgErreur = false;

    do
    {
        //Affiche un message d'erreur si la première valeur de la plage est superieure a la dernière.
        if(msgErreur)
        {
            printf("/!\ Attention /!\ La premiere valeur de la plage ne peut pas etre superieure a la derniere.\n\n");
        }

        //Demande la valeur pour "debut".
        printf("Entrez le temps (en ms) a partir duquel la plage de donnee commence.\n");
        scanf("%f", &debut);
        printf("\n");

        //Demande à rentrer une nouvelle valeur pour "debut" car le temps choisi n'existe pas.
        while (debut < 0 || debut > ptr_Tableau[*ptr_nbrLine-1].temps)
        {
            printf("Il n'existe pas de valeur pour %fms.\n", debut);
            printf("Entrez le temps (en ms) a partir duquel la plage de donnee commence.\n");
            scanf("%f", &debut);
            printf("\n");
        }

        //Demande la valeur pour "fin".
        printf("Entrez le temps (en ms) a partir duquel la plage de donnee se termine.\n");
        scanf("%f", &fin);
        printf("\n");

        //Demande à rentrer une nouvelle valeur pour "fin" car le temps choisi n'existe pas.
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


    // Boucle pour parcourir le tableau du début vers la fin.
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        //Vérifie si le temps de la case du tableau se trouve dans la plage de données.
        if (debut <= ptr_Tableau[i].temps && ptr_Tableau[i].temps <= fin)
        {
            moyenne = moyenne + ptr_Tableau[i].pouls;               //Additions les pouls de la palge de données.
            ++nbrTotal;                                             //Incrémentation de l'effectif total.
        }
    }
    moyenne = moyenne / nbrTotal;                                   //Calcul de la moyenne.
    printf("La moyenne du pouls sur la plage %.0fms - %.0fms est de %.2f.\n", debut, fin, moyenne);
}



//-------------------------------------------------------------------------------------------------------------------//
void nbrLigneDonnees(int* ptr_nbrLine)
{
    printf ("Le nombre de lignes de donnees actuellement en memoire est %d.\n", *ptr_nbrLine);
}



//-------------------------------------------------------------------------------------------------------------------//
void poulsMin(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisCroissantTemps(ptr_Tableau, ptr_nbrLine);

    printf("Le pouls minimum est de %f.\n",ptr_Tableau[0].pouls);

    // Boucle pour parcourir le tableau du début vers la fin.
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        //Si le pouls de la case du tableau est égal au pouls min, affiche les valeurs de la case.
        if (ptr_Tableau[i].pouls == ptr_Tableau[0].pouls)
        {
            printf("A %.0f ms ", ptr_Tableau[i].temps);                   //Affiche le temps pour la case "i" du tableau.
            printf("le pouls est de %.2f.\n", ptr_Tableau[i].pouls);      //Affiche le pouls pour la case "i" du tableau.
        }
    }
}



//-------------------------------------------------------------------------------------------------------------------//
void poulsMax(ligne* ptr_Tableau, int* ptr_nbrLine)
{
    trisCroissantTemps(ptr_Tableau, ptr_nbrLine);

    printf("Le pouls maximum est de %f.\n",ptr_Tableau[*ptr_nbrLine-1].pouls);

    // Boucle pour parcourir le tableau du début vers la fin.
    for (int i = 0; i < *ptr_nbrLine; i++)
    {
        //Si le pouls de la case du tableau est égal au pouls max, affiche les valeurs de la case.
        if (ptr_Tableau[i].pouls == ptr_Tableau[*ptr_nbrLine-1].pouls)
        {
            printf("A %.0f ms ", ptr_Tableau[i].temps);                   //Affiche le temps pour la case "i" du tableau.
            printf("le pouls est de %.2f.\n", ptr_Tableau[i].pouls);      //Affiche le pouls pour la case "i" du tableau.
        }
    }
}
