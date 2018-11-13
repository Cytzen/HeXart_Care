#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "actions.h"


void ordre (ligne *ptr_Tableau)
{
    for(int i = 0; i < 12; i++) ///----------------------------///
    {
        printf("A %f ms ", ptr_Tableau[i].temps);
        printf("le poul est de %f\n", ptr_Tableau[i].poul);
    }
    return;
}
