#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED

typedef struct ligne ligne;
struct ligne
{
    float temps;
    float pouls;
};

void chargeDonnees(ligne* ptr_Tableau, int* ptr_nbrLine);

#endif // DONNEES_H_INCLUDED
