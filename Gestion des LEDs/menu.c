#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"
#include "menu.h"

int menu(){
    int mode, x=0;
    printf("\nQuel mode d'affichage souhaitez-vous ?\n\n");
    printf("(1) Toutes les leds\n");
    printf("(2) Toutes les leds avec clignotement\n");
    printf("(3) Une LED sur X d'allumee\n");
    printf("(4) Chenille\n");
    printf("(5) Chenille avec clignotement\n");
    printf("(6) Une seule LED au choix\n\n");
    scanf("%d", &mode);
    while(mode>6 || mode<1){
        printf("\nVeuillez entrez une valeur comprise entre 1 et 6.");
        scanf("%d", &mode);
    }
    if(mode == 3){
        printf("\nCombien vaut X ? (entre 1 et 10)\n");
        scanf("%d",&x);
        while(x>10 || x<1){
            printf("\nVeuillez entrez une valeur comprise entre 1 et 10.\n");
            scanf("%d", &x);
        }
    }
    else if(mode == 6){
        printf("\nQuelle LED doit s'eclairer ?(entre 1 et 10)\n");
        scanf("%d",&x);
        while(x>10 || x<1){
            printf("\nVeuillez entrez une valeur comprise entre 1 et 10.\n");
            scanf("%d", &x);
        }
    }
    if (ecriture(mode, x)){
        printf("\nSucces de la generation du code. Voulez-vous modifier votre choix ? (1- oui, autre - non)\n\n");
        scanf("%d", &x);
        if (x == 1){
            menu();
        }
    }
    return 1;
}
