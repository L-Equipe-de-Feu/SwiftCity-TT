/*
    Date : 26 janvier 2023
    Description : Classe pour les pompiers
*/

#ifndef POMPIER_H
#define POMPIER_H

#include "Service.h"

class Pompier : public Service
{
private:
    /* data */
public:
    Pompier();
    Pompier(Coordonnee CoordonneeDp);
    Pompier(Ressources RessourcesDp, Coordonnee Coordonnee);
    ~Pompier();
};

Pompier::Pompier(){}

Pompier::Pompier(Coordonnee CoordonneeDp) {
    coordonnee = CoordonneeDp;
}

Pompier::Pompier(Ressources RessourcesDp, Coordonnee CoordonneeDp) {
    coordonnee = CoordonneeDp;
    ressources = RessourcesDp;
}

Pompier::~Pompier(){}


#endif