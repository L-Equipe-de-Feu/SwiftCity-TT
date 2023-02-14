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
    Bureau() {
        ressources.energie = -2;
        ressources.eau = -1;
        ressources.bonheur = 0;
        ressources.materiaux = -10;
        ressources.argent = -10;
        ressources.habitant = -5;
    }
    ~Bureau() {}

    void afficher() {

    }
    char get_char() {
        return ' ';
    }
};
#endif