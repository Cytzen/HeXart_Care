#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED

#include "donnees.h"

void ordreFichier(ligne* ptr_Tableau, int* ptr_nbrLine);

void ordreCroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine);

void ordreDecroissantTemps(ligne* ptr_Tableau, int* ptr_nbrLine);

void ordreCroissantPouls(ligne* ptr_Tableau, int* ptr_nbrLine);

void ordredecroissantPouls(ligne* ptr_Tableau, int* ptr_nbrLine);

void tempsChoisi(ligne* ptr_Tableau, int* ptr_nbrLine);

void moyenne(ligne* ptr_Tableau, int* ptr_nbrLine);

void nbrLigneDonnees(int* ptr_nbrLine);

void poulsMin(ligne* ptr_Tableau, int* ptr_nbrLine);

void poulsMax(ligne* ptr_Tableau, int* ptr_nbrLine);

#endif // ACTIONS_H_INCLUDED
