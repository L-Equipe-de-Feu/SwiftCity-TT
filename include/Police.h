/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour les policiers
*/

#ifndef POLICE_H
#define POLICE_H

#include "Service.h"

class Police : public Service {
private:
    /* data */
public:
    Police() {
        ressources.energie = -5;
        ressources.eau = -2;
        ressources.bonheur = 10;
        ressources.materiaux = 0;
        ressources.argent = -100;
        ressources.habitant = -4;
    }
    ~Police() {}

    void afficher() {}
    char get_char() {
        return ' ';
    }
};

#endif