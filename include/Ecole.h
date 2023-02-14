/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour les Ecoles
*/

#ifndef ECOLE_H
#define ECOLE_H

#include "Service.h"

class Ecole : public Service
{
private:
    /* data */
public:
    Ecole() {
        ressources.energie = -2;
        ressources.eau = -1;
        ressources.bonheur = 10;
        ressources.materiaux = 0;
        ressources.argent = -250;
        ressources.habitant = -5;
    }
    ~Ecole() {}

    void afficher() {

    }
    char get_char() {
        return ' ';
    }
};

#endif