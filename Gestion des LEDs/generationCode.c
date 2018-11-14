#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"
#include <stdbool.h>

bool ecriture(int mode, int x){
    char *modeLeds = NULL;
    modeLeds = fopen("coeur/param.h","w+");

    if(modeLeds == NULL){
        printf("/nEchec d'ouverture du fichier. Fermeture./n");
        return false;
    }
    fprintf(modeLeds,"int mode = %d;\nint x = %d;", mode, x);
    fclose(modeLeds);
    return true;
}
