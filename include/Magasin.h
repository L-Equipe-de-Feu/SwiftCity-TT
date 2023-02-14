/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour le magasin
*/

#ifndef MAGASIN_H
#define MAGASIN_H

#include "Commercial.h"

class Magasin : public Commercial {
private:
    /* data */
public:
    Magasin() {
        ressources.energie = -1;
        ressources.eau = -1;
        ressources.bonheur = 0;
        ressources.materiaux = -5;
        ressources.argent = -100;
        ressources.habitant = -2;
    }
    ~Magasin(){}

    void afficher() {

    }
    char get_char() {
        return 'C';
    }
};

#endif