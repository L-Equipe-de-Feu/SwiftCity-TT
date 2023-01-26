/*
    Date : 26 janvier 2023
    Description : Structure pour les batiments Commercial
*/

#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Batiment.h"

class Commercial : public Batiment {
private:
    /* data */
public:
    Commercial();
    Commercial(Coordonnee CoordonneeDp);
    Commercial(Ressources RessourcesDp, Coordonnee CoordonneeDp);
    ~Commercial();
};

Commercial::Commercial(){}

Commercial::Commercial(Coordonnee CoordonneeDp) {
    coordonnee = CoordonneeDp;
}

Commercial::Commercial(Ressources RessourcesDp, Coordonnee CoordonneeDp){
    coordonnee = CoordonneeDp;
    ressources = RessourcesDp;
}

Commercial::~Commercial()
{
}

#endif