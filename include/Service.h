/*
    Date : 26 janvier 2023 (creation)
    Description : Classe Service pour les service de la ville
*/

#ifndef SERVICE_H
#define SERVICE_H

#include "Batiment.h"

class Service : public Batiment
{
private:
    /* data */
public:
    Service();
    Service(Coordonnee CoordonneeDp);
    Service(Ressources RessourcesDp, Coordonnee CoordonneeDp);
    ~Service();
};

Service::Service(){}

Service::Service(Coordonnee CoordonneeDp){
    coordonnee = CoordonneeDp;
}

Service::Service(Ressources RessourcesDp, Coordonnee CoordonneeDp) {
    ressources = RessourcesDp;
    coordonnee = CoordonneeDp;
}

Service::~Service(){}


#endif