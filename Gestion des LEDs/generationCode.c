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
    fprintf(modeLeds,"#ifndef PARAM_H_\n#define PARAM_H_\n\nint mode = %d;\nint x = %d;\n\n#endif /* PARAM_H */", mode, x);
    fclose(modeLeds);
    return true;
}
