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
    virtual ~Batiment();

    void SetRessources(Ressources NRessources);
    Ressources GetRessources();
    virtual void afficher();
    virtual char get_char();
};

Batiment::Batiment() {
    ressources.energie = 0;
    ressources.eau = 0;
    ressources.bonheur = 0;
    ressources.materiaux = 0;
    ressources.argent = 0;
    ressources.habitant = 0;
}

Batiment::~Batiment(){}

void Batiment::afficher(){

}

char Batiment::get_char(){
    return ' ';
}

void Batiment::SetRessources(Ressources NRessources){
    ressources = NRessources;
}

Ressources Batiment::GetRessources(){
    return ressources;
}


#endif