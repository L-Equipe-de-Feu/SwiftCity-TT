/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour les bureaux
*/

#ifndef BUREAU_H
#define BUREAU_H

#include "Commercial.h"

class Bureau : public Commercial {
private:
    /* data */
public:
    Bureau();
    Bureau(Coordonnee CoordonneeDp);
    Bureau(Ressources RessourcesDp, Coordonnee CoordonneeDp);
    ~Bureau();
};

Bureau::Bureau(){}

Bureau::Bureau(Coordonnee CoordonneeDp) {
    coordonnee = CoordonneeDp;
}

Bureau::Bureau(Ressources RessourcesDp, Coordonnee CoordonneeDp) {
    ressources = RessourcesDp;
    coordonnee = CoordonneeDp;
}

Bureau::~Bureau(){}



#endif