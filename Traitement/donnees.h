#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED


typedef struct ligne ligne;
struct ligne
{
    float temps;
    float poul;
};

void chargeDonnees(ligne *ptr_Tableau);

#endif // DONNEES_H_INCLUDED
