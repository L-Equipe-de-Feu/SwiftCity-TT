/*
    Date : 26 janvier 2023
    Description : construction de la classe batiment
        qui est virtuel
*/

#ifndef BATIMENT_H
#define BATIMENT_H

#include "StructRessources.h"

class Batiment {
protected:
    Ressources ressources;
public:
    Batiment();
    ~Batiment();

    void SetRessources(Ressources NRessources);
    Ressources GetRessources();
};

Batiment::Batiment() {}


void Batiment::SetRessources(Ressources NRessources){
    ressources = NRessources;
}

Ressources Batiment::GetRessources(){
    return ressources;
}


#endif