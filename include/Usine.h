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
        ressources.bonheur = -20;
        ressources.materiaux = 60;
        ressources.argent = -100;
        ressources.habitant = -10;
    }
    ~Usine() {}

    void afficher() {}

    char get_char() {
        return 'U';
    }

};

#endif