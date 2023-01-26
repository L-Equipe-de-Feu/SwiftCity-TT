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
    Batiment(Coordonnee CoordonneeDp);
    Batiment(Ressources RessourcesDp, Coordonnee CoordonneeDp);
    ~Batiment();

    void SetCoordonnee(Coordonnee NCoordonnee);
    Coordonnee GetCoordonne();
    void SetRessources(Ressources NRessources);
    Ressources GetREssources();
};

Batiment::Batiment() {}

Batiment::Batiment(Coordonnee CoordonneeDp){
    coordonnee = CoordonneeDp;
}

Batiment::Batiment(Ressources RessourcesDp, Coordonnee CoordonneeDp) {
    ressources = RessourcesDp;
    coordonnee = CoordonneeDp;
}

void Batiment::SetCoordonnee(Coordonnee NCoordonnee){
    coordonnee = NCoordonnee;
}

Coordonnee Batiment::GetCoordonne(){
    return coordonnee;
}

void Batiment::SetRessources(Ressources NRessources){
    ressources = NRessources;
}

Ressources Batiment::GetREssources(){
    return ressources;
}


#endif