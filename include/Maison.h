/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour les maison
*/

#ifndef MAISON_H
#define MAISON_H

#include "Residentiel.h"

class Maison : public Residentiel {
private:
    /* data */
public:
    Maison();
    ~Maison();
};

Maison::Maison(){
    ressources.energie = -2;
    ressources.eau = -1;
    ressources.bonheur = 0;
    ressources.materiaux = 0;
    ressources.argent = -100;
    ressources.habitant = 3;
}

Maison::~Maison(){}


#endif