/*
    Date : 26 janvier 2023
    Description : Classe pour les residence
*/

#ifndef RESIDENTIEL_H
#define RESIDENTIEL_H

#include "Batiment.h"

class Residentiel : public Batiment
{
private:
    /* data */
public:
    Residentiel();
    ~Residentiel();
};

Residentiel::Residentiel(){
    ressources.energie = -1;
    ressources.eau = -1;
    ressources.bonheur = 0;
    ressources.materiaux = 0;
    ressources.argent = -1;
    ressources.habitant = 1;
}

Residentiel::~Residentiel(){}

#endif