/*
    Date : 26 janvier 2023
    Description : Classe pour l'energie
*/

#ifndef ENERGIE_H
#define ENERGIE_H

#include "Service.h"

class Energie : public Service
{
private:
    /* data */
public:
    Energie();
    Energie(Coordonnee CoordonneeDp);
    Energie(Ressources RessourcesDp, Coordonnee CoordonneeDp);
    ~Energie();
};

Energie::Energie(){}

Energie::Energie(Coordonnee CoordonneeDp) {
    coordonnee = CoordonneeDp;
}

Energie::Energie(Ressources RessourcesDp, Coordonnee CoordonneeDp) {
    ressources = RessourcesDp;
    coordonnee = CoordonneeDp;
}

Energie::~Energie(){}


#endif