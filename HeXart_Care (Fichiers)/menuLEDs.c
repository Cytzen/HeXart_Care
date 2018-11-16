#include <stdio.h>
#include <stdlib.h>

#include "menuLEDs.h"
#include "generationCode.h"

int menuLEDs()
{
    int mode = 1;
    int x = 0 ;

    printf("<---- Menu : Gestion des LEDs ---->\n");
    printf("Quel mode d'affichage souhaitez-vous ?\n\n");
    printf("(1) Toutes les leds\n");
    printf("(2) Toutes les leds avec clignotement\n");
    printf("(3) Une LED sur X d'allumee\n");
    printf("(4) Chenille\n");
    printf("(5) Chenille avec clignotement\n");
    printf("(6) Une seule LED au choix\n\n");
    printf("(autre) Retour\n\n");

    scanf("%d", &mode);     // On fait choisir le mode à l'utilisateur
    printf("\n");

    if(mode == 3)      // On fait choisir x à l'utilisateur
    {
        printf("\nCombien vaut X ? (entre 1 et 10)\n");
        scanf("%d",&x);
        while(x>10 || x<1)         // Si l'utilisateur n'a pas rentré un bon numéro...
        {
            printf("\nVeuillez entrez une valeur comprise entre 1 et 10.\n");
            scanf("%d", &x);
        }
    }
    else if(mode == 6)      // On fait choisir la led à l'utilisateur
    {
        printf("\nQuelle LED doit s'eclairer ?(entre 1 et 10)\n");
        scanf("%d",&x);
        while(x>10 || x<1)         // Si l'utilisateur n'a pas rentré un bon numéro...
        {
            printf("\nVeuillez entrez une valeur comprise entre 1 et 10.\n");
            scanf("%d", &x);
        }
    }
    else if(mode < 1 || mode > 6)
    {
        printf("RETOUR !");
        printf("\n");
        return 1;
    }
    if (ecriture(mode, x))          // On lance la fonction ecriture()
    {
        printf("\nSucces de la generation du code. Voulez-vous modifier votre choix ? (1- oui, autre - non)\n\n");
        scanf("%d", &x);
        if (x == 1)         // Si l'utilisateur veut il peut recommencer
        {
            menuLEDs();
        }
    }
    return 1;
}
