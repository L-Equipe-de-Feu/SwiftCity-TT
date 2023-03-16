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
    Culture() {
        ressources.energie = -1;
        ressources.eau = -2;
        ressources.bonheur = 16;
        ressources.materiaux = 0;
        ressources.argent = -200;
        ressources.habitant = 0;
        couts = 2000;
    }
    ~Culture() {}

    void afficher() {}

    char get_char() 
    {
        return '^';
    }
};
#endif