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
        ressources.eau = -1;
        ressources.bonheur = 5;
        ressources.materiaux = 0;
        ressources.argent = -50;
        ressources.habitant = 0;
        couts = 50;
    }
    ~Culture() {}

    void afficher() {}

    char get_char() 
    {
        return 'C';
    }
};
#endif