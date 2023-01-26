/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour les batiments de culture
*/

#ifndef CULTURE_H
#define CULTURE_H

#include "Service.h"

class Culture : public Service
{
private:
    /* data */
public:
    Culture();
    Culture(Coordonnee CoordonneeDp);
    Culture(Ressources RessourcesDp, Coordonnee CoordonneeDp);
    ~Culture();
};

Culture::Culture(){}

Culture::Culture(Coordonnee CoordonneeDp) {
    coordonnee = CoordonneeDp;
}

Culture::Culture(Ressources RessourcesDp, Coordonnee CoordonneeDp) {
    coordonnee = CoordonneeDp;
    ressources = RessourcesDp;
}

Culture::~Culture(){}


#endif