/*
    Date : 26 janvier 2023
    Description : construction de la classe batiment
        qui est virtuel
*/

#ifndef BATIMENT_H
#define BATIMENT_H

#include "Coordonnee.h"
#include "StructRessources.h"

class Batiment {
protected:
    Coordonnee coordonnee;
    Ressources ressources;
public:
    Batiment();
    ~Batiment();
};

#endif