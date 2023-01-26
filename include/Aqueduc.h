/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour l'aqueduc
*/

#ifndef AQUEDUC_H
#define AQUEDUC_H

#include "Service.h"

class Aqueduc : public Service
{
private:
    /* data */
public:
    Aqueduc();
    Aqueduc(Coordonnee CoordonneeDp);
    Aqueduc(Ressources Ressources, Coordonnee CoordonneeDp);
    ~Aqueduc();
};

Aqueduc::Aqueduc(){}

Aqueduc::Aqueduc(Coordonnee CoordonneeDp){
    coordonnee = CoordonneeDp;
}

Aqueduc::Aqueduc(Ressources RessourcesDp, Coordonnee CoordonneeDp){
    coordonnee = CoordonneeDp;
    ressources = RessourcesDp;
}

Aqueduc::~Aqueduc(){}


#endif