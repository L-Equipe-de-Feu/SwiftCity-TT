/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour le magasin
*/

#ifndef MAGASIN_H
#define MAGASIN_H

#include "Commercial.h"

class Magasin : public Commercial {
private:
    /* data */
public:
    Magasin();
    Magasin(Coordonnee CoordonneeDp);
    Magasin(Ressources RessourcesDp, Coordonnee CoordonneeDp);
    ~Magasin();
};

Magasin::Magasin(){}

Magasin::Magasin(Coordonnee CoordonneeDp){
    coordonnee = CoordonneeDp;
}

Magasin::Magasin(Ressources RessourcesDp, Coordonnee CoordonneeDp){
    ressources = RessourcesDp;
    coordonnee = CoordonneeDp;
}

Magasin::~Magasin(){}

#endif