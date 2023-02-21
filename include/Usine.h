/*
    Date : 26 janvier 2023
    Description : Classe pour les usines
*/

#ifndef USINE_H
#define USINE_H

#include "Industriel.h"

class Usine : public Industriel {
private:
    /* data */
public:
    Usine() {
        ressources.energie = -10;
        ressources.eau = -4;
        ressources.bonheur = -10;
        ressources.materiaux = 120;
        ressources.argent = -100;
        ressources.habitant = -10;
        couts = 500;
    }
    ~Usine() {}

    void afficher() {}

    char get_char() {
        return 'U';
    }

};

#endif