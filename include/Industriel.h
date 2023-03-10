/*
    Date : 26 janvier 2023
    Description : Classe pour les batiments industriels
*/

#ifndef INDUSTRIEL_H
#define INDUSTRIEL_H

#include "Batiment.h"

class Industriel : public Batiment {
private:
    /* data */
public:
    Industriel() {
        ressources.energie = -1;
        ressources.eau = -1;
        ressources.bonheur = -1;
        ressources.materiaux = 1;
        ressources.argent = -1;
        ressources.habitant = -1;
    }
    ~Industriel() {}

    virtual void afficher()=0;
    virtual char get_char()=0;
};

#endif