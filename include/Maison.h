/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour les maison
*/

#ifndef MAISON_H
#define MAISON_H

#include "Residentiel.h"

class Maison : public Residentiel {
private:
    /* data */
public:
    Maison() {
        ressources.energie = -2;
        ressources.eau = -2;
        ressources.bonheur = 0;
        ressources.materiaux = 0;
        ressources.argent = 0;
        ressources.habitant = 10;
        couts = 200;
    }
    ~Maison() {}

    void afficher() {}

    char get_char() {
        return 'M';
    }
};
#endif