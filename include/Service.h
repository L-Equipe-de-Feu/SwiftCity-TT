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
    Service() {
        ressources.energie = -1;
        ressources.eau = -1;
        ressources.bonheur = 1;
        ressources.materiaux = 0;
        ressources.argent = -1;
        ressources.habitant = -1;
    }
    ~Service() {}

    virtual void afficher()=0;
    virtual char get_char()=0;
};

#endif