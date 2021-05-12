#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "generationCode.h"


bool ecriture(int mode, int x)
{
    char *modeLeds = NULL;
    modeLeds = fopen("LED_Config/param.h","w+");     // On ouvre le fichier param.h pour �crire dessus en le vidant d'abord

    if(modeLeds == NULL)        // Si le fichier n'est pas trouv�
    {
        printf("/nEchec d'ouverture du fichier. Fermeture./n");
        return false;
    }
    fprintf(modeLeds,"#ifndef PARAM_H_\n#define PARAM_H_\n\nint mode = %d;\nint x = %d;\n\n#endif /* PARAM_H */", mode, x);     // On �crit dans param.h
    fclose(modeLeds);       // On ferme le fichier
    return true;
}
