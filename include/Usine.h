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
        ressources.energie = -8;
        ressources.eau = -4;
        ressources.bonheur = -4;
        ressources.materiaux = 100;
        ressources.argent = -200;
        ressources.habitant = -7;
        couts = 200;
    }
    ~Usine() {}

    void afficher() {}

    char get_char() {
        return 'U';
    }

};

#endif